#include "types.h"
extern u32 lbl_8055D6E8;
extern s32 lbl_8055D6AC;
extern s32 lbl_8055D6DC;
extern void *lbl_8055D6E0;
extern void TRKInitializeEventQueue(void);
extern u32 lbl_80558DD8;
extern u32 lbl_8035BF20[];
extern void TRKReleaseBuffer(void *);
extern void TRKAppendBuffer1_ui64(void);
extern void TRKAppendBuffer_ui32(void);
extern void OSRegisterVersion(s32);
extern void fn_80033404(void);
extern void fn_80032778(void);
extern void usr_puts_serial(void);
extern void fn_800331A0(void);
extern void __AXSPBInit(void);
extern void TRKGetInput(void);
extern void fn_800320E8(s32);
extern void fn_80031C68(void);
extern void fn_800322E4(void);
extern void CircleBufferWriteBytes(void);
extern void *lbl_8055D740;
extern u8 lbl_8035E820[];
extern u16 lbl_8055D730;
extern u16 lbl_8055D732;
extern s32 lbl_8055D738;
extern void *lbl_8055D744;
extern s32 lbl_8055D748;
extern s32 lbl_8055D750;
extern s32 lbl_8055D754;
extern s32 lbl_8055D758;
extern s32 lbl_8055D774;
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void OSSleepThread(void *);
extern void AIStopDMA(void);
extern void __DSPHandler(void *);
extern volatile u32 lbl_8055D778;
extern volatile u32 lbl_8055D77C;
extern volatile u32 lbl_8055D784;
extern u32 lbl_8055D780;
extern u32 lbl_8055D75C;
extern u8 lbl_8035F700[];
extern u8 lbl_8035FB80[];
extern u64 OSGetTime(void);
extern void CircleBufferInitialize(u32);
extern void DSPAssertTask(void *);
extern void AIInitDMA(void *, u32);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned short lbl_8055D734;
extern void *lbl_8055D728;
extern void *lbl_8055D71C;
extern void *lbl_8055D724;
extern void *lbl_8055D718;
extern void *lbl_8055D720;
extern void *lbl_8055D714;
extern u8 lbl_8035BFA0[];
extern s32 lbl_8055D6F0;
extern s32 lbl_8055D6F4;
extern s32 lbl_8055D6F8;
extern void *lbl_8055D6FC;
extern void *lbl_8055D700;
extern void *lbl_8055D704;
extern void *lbl_8055D708;
extern void *lbl_8055D70C;
extern void *lbl_8055D710;
extern void DCInvalidateRange(void *, u32);
extern void DCFlushRangeNoSync(void *, u32);
typedef void (*TRKCommFn)(void **, void *);

extern void *lbl_8055D73C;
extern void *lbl_8055D6A8;
void TRKPostEvent(s32 arg0) {
    extern u32 lbl_80558DD0;
    extern s32 lbl_8055D6B0, lbl_8055D6B4, lbl_8055D6B8, lbl_8055D6BC;
    extern s32 lbl_8055D6C0, lbl_8055D6C4, lbl_8055D6C8, lbl_8055D6CC;
    extern s32 lbl_8055D6D0, lbl_8055D6D4, lbl_8055D6DC;
    extern void TRKInitializeNub(void);
    extern void __OSSetInterruptHandler(int, void (*)(void *, void *));
    extern void __OSUnmaskInterrupts(u32);
    extern void TRKGetNextEvent(void *, void *);
    s32 irq;
    u32 ticks;
    if ((s32)lbl_8055D6A8 != 1) {
        u32 zero = 0;
        OSRegisterVersion(lbl_80558DD0);
        ticks = (*(volatile u32 *)0x800000F8 >> 2) / 125000;
        lbl_8055D6D0 = zero;
        lbl_8055D6C8 = zero;
        lbl_8055D6C0 = zero;
        lbl_8055D6B8 = zero;
        lbl_8055D6B0 = zero;
        lbl_8055D6D4 = (ticks * 0x7B24) / 8000;
        lbl_8055D6CC = (ticks * 0xA428) / 8000;
        lbl_8055D6C4 = (ticks * 0xA410) / 8000;
        lbl_8055D6BC = (ticks * 0xF618) / 8000;
        lbl_8055D6B4 = (ticks * 0xBB8) / 8000;
        *(volatile u32 *)0xCD006C00 &= ~0x15;
        *(volatile u32 *)0xCD006C04 = zero;
        *(volatile u32 *)0xCD006C0C = zero;
        *(volatile u32 *)0xCD006C00 = (*(volatile u32 *)0xCD006C00 & 0xFFFFFFDF) | 0x20;
        if ((((*(volatile u32 *)0xCD006C00 >> 6) & 1) ^ 1) != 0) {
            *(volatile u32 *)0xCD006C00 &= 0xFFFFFFBF;
            irq = OSDisableInterrupts();
            TRKInitializeNub();
            *(volatile u32 *)0xCD006C00 |= 0x40;
            OSRestoreInterrupts(irq);
        }
        lbl_8055D6E0 = 0;
        lbl_8055D6DC = arg0;
        __OSSetInterruptHandler(5, TRKGetNextEvent);
        __OSUnmaskInterrupts(0x04000000);
        lbl_8055D6A8 = (void *)1;
    }
}

void TRKConstructEvent(void) {
    /* Reset the TRK event flag so the next TRKPostEvent reinitializes the debug nub. */
#define sTrkEventFlag lbl_8055D6A8
    sTrkEventFlag = 0;
#undef sTrkEventFlag
}

void TRKGetNextEvent(void *arg0, void *restoreContext) {
    u8 context[0x2D0];
    s32 value;
    u32 addr;
    void (*fn)(void);
    *(volatile u16 *)0xCC00500A = (*(volatile u16 *)0xCC00500A & ~0xA0) | 8;
    OSClearContext(context);
    OSSetCurrentContext(context);
    addr = (u32)lbl_8055D6E0;
    if (addr != 0 && lbl_8055D6AC == 0) {
        value = lbl_8055D6DC;
        lbl_8055D6AC = 1;
        if (value != 0) TRKInitializeEventQueue();
        else {
            fn = (void (*)(void))addr;
            fn();
        }
        lbl_8055D6AC = 0;
    }
    OSClearContext(context);
    OSSetCurrentContext(restoreContext);
}

extern s32 lbl_8055D6D8;
void TRKInitializeEventQueue(void) {
    u32 saved;
    void (*callback)(void);
    *(volatile u32 *)0x8055D6D8 = (u32)&saved - 8;
    callback = (void (*)(void))*(volatile u32 *)0x8055D6DC;
    callback();
    saved = *(volatile u32 *)0x8055D6D8;
}

extern s32 lbl_8055D6B0, lbl_8055D6B4, lbl_8055D6B8, lbl_8055D6BC;
extern s32 lbl_8055D6C0, lbl_8055D6C4, lbl_8055D6C8, lbl_8055D6CC;
extern s32 lbl_8055D6D0, lbl_8055D6D4;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void TRKInitializeNub(void) {
    s64 now = 0;
    s32 state = 0;
    s64 duration = 0;
    s64 start = 0;
    s64 elapsed = 0;
    s64 deadline = 0;
    u32 status = 0;
    u32 control = 0;
    u32 tmp = 0;
    goto continuation;
measure:
    control = *(volatile u32 *)0xCD006C00;
    control = (control & ~0x20) | 0x20;
    *(volatile u32 *)0xCD006C00 = control;
    control = *(volatile u32 *)0xCD006C00;
    *(volatile u32 *)0xCD006C00 = control & ~2U;
    control = *(volatile u32 *)0xCD006C00;
    *(volatile u32 *)0xCD006C00 = (control & ~1U) | 1U;
    do {
        tmp = *(volatile u32 *)0xCD006C08;
        status = tmp & 0x7FFFFFFFU;
        tmp = *(volatile u32 *)0xCD006C08;
        control = tmp & 0x7FFFFFFFU;
    } while (status == control);
    start = (s64)OSGetTime();
    control = *(volatile u32 *)0xCD006C00;
    *(volatile u32 *)0xCD006C00 = (control & ~2U) | 2U;
    control = *(volatile u32 *)0xCD006C00;
    *(volatile u32 *)0xCD006C00 = (control & ~1U) | 1U;
    do {
        status = *(volatile u32 *)0xCD006C08;
        status &= 0x7FFFFFFFU;
        control = *(volatile u32 *)0xCD006C08;
        control &= 0x7FFFFFFFU;
    } while (status == control);
    now = (s64)OSGetTime();
    control = *(volatile u32 *)0xCD006C00;
    elapsed = now - start;
    *(volatile u32 *)0xCD006C00 = control & ~2U;
    control = *(volatile u32 *)0xCD006C00;
    *(volatile u32 *)0xCD006C00 = control & ~1U;
    if (elapsed > (s64)((((u64)(u32)lbl_8055D6D0 << 32) | (u32)lbl_8055D6D4) -
                       (((u64)(u32)lbl_8055D6B0 << 32) | (u32)lbl_8055D6B4))) {
        duration = (s64)(((u64)(u32)lbl_8055D6C0 << 32) | (u32)lbl_8055D6C4);
        state = 1;
        goto continuation;
    }
    if (elapsed <= (s64)((((u64)(u32)lbl_8055D6D0 << 32) | (u32)lbl_8055D6D4) +
                         (((u64)(u32)lbl_8055D6B0 << 32) | (u32)lbl_8055D6B4)) &&
        elapsed > (s64)((((u64)(u32)lbl_8055D6C8 << 32) | (u32)lbl_8055D6CC) -
                       (((u64)(u32)lbl_8055D6B0 << 32) | (u32)lbl_8055D6B4))) {
        duration = (s64)(((u64)(u32)lbl_8055D6B8 << 32) | (u32)lbl_8055D6BC);
        state = 1;
        goto continuation;
    }
    state = 0;
continuation:
    if (state == 0) {
        goto measure;
    }
    deadline = now + duration;
    do {
        now = (s64)OSGetTime();
    } while (now < deadline);
}
#pragma pop
void TRKMessageSend(void) {
/* The game bundles an older RVL_SDK AX library (build 0x4200_60422); this is
 * that library's AXInitEx(0). It registers the version string, then brings up
 * each AX subsystem in order: allocator, voice pool (VPB), SPB, aux, CL and
 * output/DMA (TRKAppendBuffer_ui32=__AXAllocInit, fn_800331A0=__AXVPBInit,
 * TRKGetInput=__AXAuxInit, CircleBufferWriteBytes=__AXClInit,
 * fn_800320E8=__AXOutInit). */
#define __AXVersion_4200 lbl_80558DD8
    OSRegisterVersion(__AXVersion_4200);
    TRKAppendBuffer_ui32();
    fn_800331A0();
    __AXSPBInit();
    TRKGetInput();
    CircleBufferWriteBytes();
    fn_800320E8(0);
#undef __AXVersion_4200
}

void TRKReadBuffer_ui32(void) {
    /* Leftover diagnostic sequence: append a ui64 to a TRK buffer, run assorted TRK/AX helpers, clear the serial output flags and shut down audio DMA. */
    TRKAppendBuffer1_ui64();
    fn_80033404();
    fn_80032778();
    usr_puts_serial();
    fn_80031C68();
    fn_800322E4();
}

extern int lbl_8035BEA0[4];
/* Return the head pointer of TRK message-buffer free-list pool index (lbl_8035BEA0). */
int TRKReadBuffer_ui8(int index) { return lbl_8035BEA0[index]; }

/* Drains the pending TRK message-buffer queue (lbl_8055D6E8): for each active buffer, invokes its callback, releases it, returns it to free-list pool 0 (lbl_8035BEA0[0]), and clears active. */
void TRKReadBuffer1_ui64(void) {
    typedef struct TRKBuf {
        struct TRKBuf *next;
        u32 unk4;
        struct TRKBuf *queue_next;
        u32 active;
        void (*callback)(struct TRKBuf *);
    } TRKBuf;
    TRKBuf *buf = (TRKBuf *)lbl_8055D6E8;
    if (buf != 0) lbl_8055D6E8 = (u32)buf->queue_next;
    while (buf != 0) {
        if (buf->active != 0) {
            if (buf->callback != 0) buf->callback(buf);
            TRKReleaseBuffer(buf);
            buf->next = (TRKBuf *)lbl_8035BEA0[0];
            lbl_8035BEA0[0] = (s32)buf;
            buf->active = 0;
        }
        buf = (TRKBuf *)lbl_8055D6E8;
        if (buf != 0) lbl_8055D6E8 = (u32)buf->queue_next;
    }
}

#pragma push
#pragma scheduling invalid_target
void TRKAppendBuffer_ui32(void) {
    u32 *a = lbl_8035BF20;
    u32 *b = (u32 *)lbl_8035BEA0;
    s32 i = 2;
    lbl_8055D6E8 = 0;
    do {
        a[0] = 0; b[0] = 0; a[1] = 0; b[1] = 0;
        a[2] = 0; b[2] = 0; a[3] = 0; b[3] = 0;
        a[4] = 0; b[4] = 0; a[5] = 0; b[5] = 0;
        a[6] = 0; b[6] = 0; a[7] = 0; b[7] = 0;
        a[8] = 0; b[8] = 0; a[9] = 0; b[9] = 0;
        a[10] = 0; b[10] = 0; a[11] = 0; b[11] = 0;
        a[12] = 0; b[12] = 0; a[13] = 0; b[13] = 0;
        a[14] = 0; a[15] = 0; b[14] = 0; b[15] = 0;
        a += 16; b += 16;
    } while (--i);
}

void TRKAppendBuffer1_ui64(void) {
    u32 *a = lbl_8035BF20;
    u32 *b = (u32 *)lbl_8035BEA0;
    s32 i = 2;
    lbl_8055D6E8 = 0;
    do {
        a[0] = 0; b[0] = 0; a[1] = 0; b[1] = 0;
        a[2] = 0; b[2] = 0; a[3] = 0; b[3] = 0;
        a[4] = 0; b[4] = 0; a[5] = 0; b[5] = 0;
        a[6] = 0; b[6] = 0; a[7] = 0; b[7] = 0;
        a[8] = 0; b[8] = 0; a[9] = 0; b[9] = 0;
        a[10] = 0; b[10] = 0; a[11] = 0; b[11] = 0;
        a[12] = 0; b[12] = 0; a[13] = 0; b[13] = 0;
        a[14] = 0; b[14] = 0; a[15] = 0; b[15] = 0;
        a += 16; b += 16;
    } while (--i);
}

#pragma pop
void TRKReadBuffer(void *buffer) {
    /* Return a TRK message buffer to free-list pool 0: link it ahead of the current head and clear its pool index. */
    u32 oldHead = lbl_8035BEA0[0];
    *(u32 *)buffer = oldHead;
    lbl_8035BEA0[0] = (u32)buffer;
    *(u32 *)((u8 *)buffer + 0xC) = 0;
}

void TRKAppendBuffer(void *buf) {
    /* Push a TRK message buffer onto the front of the pending queue (linked via +0x08). */
#define sPendingQueue lbl_8055D6E8
    *(u32 *)((u8 *)buf + 8) = sPendingQueue;
    sPendingQueue = (u32)buf;
#undef sPendingQueue
}

/* Remove a message buffer from the per-pool doubly-linked list indicated by buffer->poolIndex (+0xC). */
void TRKReleaseBuffer(void *buffer) {
    s32 poolIndex = *(s32 *)((u8 *)buffer + 0xC);
    u32 head = ((u32 *)lbl_8035BEA0)[poolIndex];
    u32 tail = lbl_8035BF20[poolIndex];
    if (head == tail) {
        lbl_8035BF20[poolIndex] = 0;
        ((u32 *)lbl_8035BEA0)[poolIndex] = 0;
        return;
    }
    if ((u32)buffer == head) {
        void *next = *(void **)buffer;
        ((u32 *)lbl_8035BEA0)[poolIndex] = (u32)next;
        *(u32 *)((u8 *)next + 4) = 0;
        return;
    }
    if ((u32)buffer == tail) {
        void *prev = *(void **)((u8 *)buffer + 4);
        lbl_8035BF20[poolIndex] = (u32)prev;
        *(u32 *)prev = 0;
        return;
    }
    {
        void *prev = *(void **)((u8 *)buffer + 4);
        void *next = *(void **)buffer;
        *(void **)prev = next;
        *(void **)((u8 *)next + 4) = prev;
    }
}

extern void fn_80033148(void *);
#pragma push
#pragma scheduling on
/* Really AX's AXFreeVoice (AXAlloc.c): takes a voice off its priority stack,
 * asks for a depop if it was still playing, resets its parameter block and
 * pushes it onto the free stack (priority 0). */
void TRKGetFreeBuffer(void *voice) {
#define __AXRemoveFromStack TRKReleaseBuffer
#define __AXSetPBDefault    fn_80033148
#define __AXStackHead       lbl_8035BEA0 /* AXVPB *[32], one list per priority */
    struct AXVPB {
        struct AXVPB *next;  /* 0x00 */
        struct AXVPB *prev;  /* 0x04 */
        struct AXVPB *next1; /* 0x08 */
        u32 priority;        /* 0x0C */
        u8 pad10[0x10];
        u32 depop;           /* 0x20 */
        u8 pad24[0x124];
        u16 state;           /* 0x148: pb.state, 1 = running */
    } *vpb = voice;
    s32 level = OSDisableInterrupts();
    __AXRemoveFromStack(voice);
    if (vpb->state == 1) {
        vpb->depop = 1;
    }
    __AXSetPBDefault(voice);
    {
        void *head = (void *)__AXStackHead[0];
        vpb->next = head;
        __AXStackHead[0] = (s32)voice;
    }
    vpb->priority = 0;
    OSRestoreInterrupts(level);
#undef __AXStackHead
#undef __AXSetPBDefault
#undef __AXRemoveFromStack
}
#pragma push
#pragma use_lmw_stmw off
void *TRKInitializeMessageBuffers(u32 priority, s32 callback, s32 callbackArg, s32 arg3) {
    /* AX voice-stack recycle: take a voice off the top of its priority stack (scanning the
       other per-priority stacks when empty), reset it, then push it onto `priority`'s stack
       with the supplied callback fields. */
#define __AXSetPBDefault fn_80033148
#define __AXStackHead    lbl_8035BEA0
#define __AXStackTail    lbl_8035BF20
    extern s32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(s32);
    extern void fn_80033148(void *);
    s32 level = OSDisableInterrupts();
    u32 index;
    void *voice = (void *)__AXStackHead[0];
    if (voice != 0)
        __AXStackHead[0] = *(u32 *)voice;
    if (voice == 0) {
        u32 *firstp = (u32 *)__AXStackHead + 1;
        u32 *lastp = __AXStackTail + 1;
        for (index = 1; index < priority; ++index, ++firstp, ++lastp) {
            u32 first = *firstp;
            voice = 0;
            if (first != 0) {
                u32 last = *lastp;
                if (first == last) {
                    *lastp = 0;
                    voice = (void *)first;
                    *firstp = 0;
                } else if (last != 0) {
                    voice = (void *)last;
                    last = *(u32 *)((u8 *)last + 4);
                    *lastp = last;
                    *(u32 *)last = 0;
                }
            }
            if (voice != 0) {
                if (*(u16 *)((u8 *)voice + 0x148) == 1)
                    *(u32 *)((u8 *)voice + 0x20) = 1;
                if (*(void (**)(void *))((u8 *)voice + 0x10) != 0)
                    (*(void (**)(void *))((u8 *)voice + 0x10))(voice);
                break;
            }
        }
    }
    if (voice != 0) {
        void *stackHead = (void *)__AXStackHead[priority];
        *(void **)voice = stackHead;
        *(u32 *)((u8 *)voice + 4) = 0;
        if (stackHead != 0) {
            stackHead = (void *)__AXStackHead[priority];
            *(void **)((u8 *)stackHead + 4) = voice;
            __AXStackHead[priority] = (u32)voice;
        } else {
            __AXStackHead[priority] = (u32)voice;
            __AXStackTail[priority] = (u32)voice;
        }
        *(u32 *)((u8 *)voice + 0xC) = priority;
        *(s32 *)((u8 *)voice + 0x10) = callback;
        *(s32 *)((u8 *)voice + 0x14) = callbackArg;
        __AXSetPBDefault(voice);
    }
    OSRestoreInterrupts(level);
    return voice;
#undef __AXSetPBDefault
#undef __AXStackHead
#undef __AXStackTail
}
#pragma pop

#pragma pop
/* Enqueue a TRK message buffer onto the specified input queue, updating the
 * queue head/tail lists (lbl_8035BEA0/lbl_8035BF20) with interrupts disabled. */
void TRKProcessInput(void *buffer, s32 queueId) {
    s32 interrupts;
    s32 index;
    void *head;
    interrupts = OSDisableInterrupts();
    TRKReleaseBuffer(buffer);
    index = queueId * 4;
    head = *(void **)((u8 *)&lbl_8035BEA0 + index);
    *(void **)buffer = head;
    *(void **)((u8 *)buffer + 4) = 0;
    if (head != 0) {
        *(void **)((u8 *)*(void **)((u8 *)&lbl_8035BEA0 + index) + 4) = buffer;
        *(void **)((u8 *)&lbl_8035BEA0 + index) = buffer;
    } else {
        *(void **)((u8 *)&lbl_8035BEA0 + index) = buffer;
        *(void **)((u8 *)&lbl_8035BF20 + index) = buffer;
    }
    *(s32 *)((u8 *)buffer + 0xC) = queueId;
    OSRestoreInterrupts(interrupts);
}

void TRKGetInput(void) {
    extern u8 lbl_8035BFA0[];
    extern s32 lbl_8055D6F8;
    extern s32 lbl_8055D6F4;
    extern s32 lbl_8055D6F0;
    u32 *first;
    u32 *second;
    u32 *third;
    int i;

    lbl_8055D728 = 0;
    first = (u32 *)lbl_8035BFA0;
    second = (u32 *)(lbl_8035BFA0 + 0xD80);
    third = (u32 *)(lbl_8035BFA0 + 0x1B00);
    lbl_8055D724 = 0;
    lbl_8055D720 = 0;
    lbl_8055D71C = 0;
    lbl_8055D718 = 0;
    lbl_8055D714 = 0;
    lbl_8055D6F8 = 0;
    lbl_8055D6F4 = 1;
    lbl_8055D6F0 = 2;
    i = 0x20;
    do {
        first[0] = 0;
        second[0] = 0;
        third[0] = 0;
        first[1] = 0;
        second[1] = 0;
        third[1] = 0;
        first[2] = 0;
        second[2] = 0;
        third[2] = 0;
        first[3] = 0;
        second[3] = 0;
        third[3] = 0;
        first[4] = 0;
        second[4] = 0;
        third[4] = 0;
        first[5] = 0;
        second[5] = 0;
        third[5] = 0;
        first[6] = 0;
        second[6] = 0;
        third[6] = 0;
        first[7] = 0;
        second[7] = 0;
        third[7] = 0;
        first[8] = 0;
        first += 9;
        second[8] = 0;
        second += 9;
        third[8] = 0;
        third += 9;
        i--;
    } while (i != 0);
}

/* Disable serial input by clearing the three AX aux input callbacks (A/B/C). */
void usr_puts_serial(void) {
    lbl_8055D728 = 0;
    lbl_8055D724 = 0;
    lbl_8055D720 = 0;
}

void TRKDispatchMessage(void **out) {
    /* Return the current AUX-A DSP input buffer through *out, or NULL when no
     * AUX-A callback is registered. lbl_8055D728 = AUX-A callback,
     * lbl_8055D6F8 = DSP write ring index, lbl_8035BFA0 = AUX-A buffer array
     * (0x480 bytes per ring slot). */
    extern u8 lbl_8035BFA0[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D728 != 0) {
        *out = lbl_8035BFA0 + lbl_8055D6F8 * 0x480;
        return;
    }
    *out = 0;
}

void __AXGetAuxAOutput(void **out) {
    /* Return the current read-ring slot of the AUX-A output buffer lbl_8035BFA0
     * (0x480 bytes per slot, read ring index lbl_8055D6F4) through *out. */
    extern u8 lbl_8035BFA0[];
    extern s32 lbl_8055D6F4;
    *out = lbl_8035BFA0 + lbl_8055D6F4 * 0x480;
}

extern u8 lbl_8035DAA0[];
extern u8 lbl_8035BFA0[];
extern s32 lbl_8055D6F8;
extern s32 lbl_8055D6F4;
void __AXGetAuxAInputDpl2(void **out) {
    /* Return a pointer into the current write-ring slot of the AUX-A Dolby Pro
     * Logic 2 input buffer lbl_8035DAA0 (0x480 bytes/slot), at byte offset 0x180. */
    *out = lbl_8035DAA0 + lbl_8055D6F8 * 0x480 + 0x180;
}

void __AXGetAuxAOutputDpl2R(void **out) {
    /* Return a pointer into the current read-ring slot of the AUX-A Dolby Pro
     * Logic 2 output buffer lbl_8035BFA0 (0x480 bytes/slot), at byte offset 0x180. */
    *out = lbl_8035BFA0 + lbl_8055D6F4 * 0x480 + 0x180;
}

// Returns the AUX-A Dolby Pro Logic II left-surround output buffer through *out:
// the current ring slot (lbl_8055D6F4) of the 0x480-byte-per-slot AUX-A output
// array (lbl_8035BFA0), plus the 0x300-byte Ls block offset.
void __AXGetAuxAOutputDpl2Ls(void **out) {
    *out = lbl_8035BFA0 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxAOutputDpl2Rs(void **out) {
    /* Write the AUX-A DPL2 rear-surround (Rs) output buffer for the current DSP
     * read position into *out; REXE01 keeps AX state as raw labels. */
    *out = lbl_8035DAA0 + lbl_8055D6F4 * 0x480 + 0x180;
}

/* Return the DSP's current auxiliary-A input buffer through *out, or NULL when
 * no AUX-A callback is registered. REXE01 keeps the AX state as raw labels:
 * lbl_8055D724 = AUX-A callback, lbl_8055D6F8 = DSP write ring index and
 * lbl_8035CD20 = AUX-A buffer array (0x480 bytes per ring slot). */
void __AXGetAuxAInput(void **out) {
    extern u8 lbl_8035CD20[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D724 != 0) {
        *out = lbl_8035CD20 + lbl_8055D6F8 * 0x480;
        return;
    }
    *out = 0;
}

void __AXGetAuxBOutput(void **out) {
    extern u8 lbl_8035CD20[];
    extern s32 lbl_8055D6F4;
    /* Return the current read-ring slot of the AUX-B output buffer lbl_8035CD20
     * (0x480 bytes per slot) through *out. */
    *out = lbl_8035CD20 + lbl_8055D6F4 * 0x480;
}

void __AXGetAuxBInputDpl2(void **out) {
    /* Return a pointer into the current write-ring slot of the AUX-B Dolby Pro
     * Logic 2 input buffer lbl_8035DAA0 (0x480 bytes/slot), at byte offset 0x300. */
    *out = lbl_8035DAA0 + lbl_8055D6F8 * 0x480 + 0x300;
}

extern u8 lbl_8035CD20[];
void __AXGetAuxBOutputDpl2R(void **out) {
    /* Return a pointer into the current read-ring slot of the AUX-B Dolby Pro
     * Logic 2 output buffer lbl_8035CD20 (0x480 bytes/slot), at byte offset 0x180. */
    *out = lbl_8035CD20 + lbl_8055D6F4 * 0x480 + 0x180;
}

// Returns the AUX-B Dolby Pro Logic II left-surround output buffer through *out:
// the current ring slot (lbl_8055D6F4) of the 0x480-byte-per-slot AUX-B output
// array (lbl_8035CD20), plus the 0x300-byte Ls block offset.
void __AXGetAuxBOutputDpl2Ls(void **out) {
    *out = lbl_8035CD20 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxBOutputDpl2Rs(void **out) {
    /* Write the AUX-B DPL2 rear-surround (Rs) output buffer for the current DSP
     * read position into *out; REXE01 keeps AX state as raw labels. */
    *out = lbl_8035DAA0 + lbl_8055D6F4 * 0x480 + 0x300;
}

// Returns the current AuxB DSP input buffer in *out, or NULL when no AuxB callback is registered.
void __AXGetAuxBInput(void **out) {
    extern u8 lbl_8035DAA0[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D720 != 0) {
        *out = lbl_8035DAA0 + lbl_8055D6F8 * 0x480;
        return;
    }
    *out = 0;
}

/* Return the DSP's current AUX-C output buffer (0x480 bytes per ring slot) through *out. */
void __AXGetAuxCOutput(void **out) {
    extern u8 lbl_8035DAA0[];
    extern s32 lbl_8055D6F4;
    *out = lbl_8035DAA0 + lbl_8055D6F4 * 0x480;
}

#pragma opt_common_subs off
void InitMetroTRKCommTable(void) {
    void *a[4];
    void *c[3];
    void *b[4];
    void *d[3];
    void *e[3];
    u8 *base = lbl_8035BFA0;
    s32 i8 = lbl_8055D6F8 * 0x480;
    s32 i4 = lbl_8055D6F4 * 0x480;
    {
        u8 *b2 = base + 0x1B00;
        u8 *b1 = base + 0xD80;
        lbl_8055D710 = base + i8;
        lbl_8055D70C = base + i4;
        lbl_8055D708 = b1 + i8;
        lbl_8055D704 = b1 + i4;
        lbl_8055D700 = b2 + i8;
        lbl_8055D6FC = b2 + i4;
    }
    if (lbl_8055D728 != 0) {
        u8 *b2 = base + 0x1B00;
        if ((u32)lbl_8055D740 == 2) {
            s32 o = lbl_8055D6F0 * 0x480;
            u8 *p = base + o;
            u8 *q = b2 + o;
            a[0] = p;
            a[1] = p + 0x180;
            a[2] = p + 0x300;
            a[3] = q + 0x180;
            DCInvalidateRange(a[0], 0x480);
            DCInvalidateRange(a[3], 0x180);
            ((TRKCommFn)lbl_8055D728)(a, lbl_8055D71C);
            DCFlushRangeNoSync(a[0], 0x480);
            DCFlushRangeNoSync(a[3], 0x180);
        } else {
            u8 *p = base + lbl_8055D6F0 * 0x480;
            c[0] = p;
            c[1] = p + 0x180;
            c[2] = p + 0x300;
            DCInvalidateRange(c[0], 0x480);
            ((TRKCommFn)lbl_8055D728)(c, lbl_8055D71C);
            DCFlushRangeNoSync(c[0], 0x480);
        }
    }
    if (lbl_8055D724 != 0) {
        u8 *b2 = base + 0x1B00;
        u8 *b1 = base + 0xD80;
        if ((u32)lbl_8055D740 == 2) {
            s32 o = lbl_8055D6F0 * 0x480;
            u8 *p = b1 + o;
            u8 *q = b2 + o;
            b[0] = p;
            b[1] = p + 0x180;
            b[2] = p + 0x300;
            b[3] = q + 0x300;
            DCInvalidateRange(b[0], 0x480);
            DCInvalidateRange(b[3], 0x180);
            ((TRKCommFn)lbl_8055D724)(b, lbl_8055D718);
            DCFlushRangeNoSync(b[0], 0x480);
            DCFlushRangeNoSync(b[3], 0x180);
        } else {
            u8 *p = b1 + lbl_8055D6F0 * 0x480;
            d[0] = p;
            d[1] = p + 0x180;
            d[2] = p + 0x300;
            DCInvalidateRange(d[0], 0x480);
            ((TRKCommFn)lbl_8055D724)(d, lbl_8055D718);
            DCFlushRangeNoSync(d[0], 0x480);
        }
    }
    if (lbl_8055D720 != 0 && (u32)lbl_8055D740 != 2) {
        u8 *b2 = base + 0x1B00;
        u8 *p = b2 + lbl_8055D6F0 * 0x480;
        e[0] = p;
        e[1] = p + 0x180;
        e[2] = p + 0x300;
        DCInvalidateRange(e[0], 0x480);
        ((TRKCommFn)lbl_8055D720)(e, lbl_8055D714);
        DCFlushRangeNoSync(e[0], 0x480);
    }
    lbl_8055D6F8 = ((u32)lbl_8055D6F8 + 1) % 3;
    lbl_8055D6F4 = ((u32)lbl_8055D6F4 + 1) % 3;
    lbl_8055D6F0 = ((u32)lbl_8055D6F0 + 1) % 3;
}
#pragma opt_common_subs reset
void AXRegisterAuxACallback(void *callback, void *context) {
    /* Register the AX auxiliary-A bus DSP callback and the user context passed to it. */
    lbl_8055D728 = callback;
    lbl_8055D71C = context;
}

void AXRegisterAuxBCallback(void *callback, void *context) {
    /* Register the AX auxiliary-B bus DSP callback and the user context passed to it. */
    lbl_8055D724 = callback;
    lbl_8055D718 = context;
}

void AXRegisterAuxCCallback(void *callback, void *context) {
    /* Register the AX auxiliary-C bus DSP callback and the user context passed to it. */
    lbl_8055D720 = callback;
    lbl_8055D714 = context;
}

/* Retrieve the registered AUX A DSP callback and its user context. */
void AXGetAuxACallback(void **callback, void **context) {
    *callback = lbl_8055D728;
    *context = lbl_8055D71C;
}

/* Retrieve the registered AUX B DSP callback and its user context. */
void AXGetAuxBCallback(void **callback, void **context) {
    *callback = lbl_8055D724;
    *context = lbl_8055D718;
}

/* Retrieve the AX auxiliary-C bus callbacks registered via AXRegisterAuxCCallback:
   lbl_8055D720 is the callback and lbl_8055D714 the argument passed to it. */
void AXGetAuxCCallback(void **outCallback, void **outArg) {
    *outCallback = lbl_8055D720;
    *outArg = lbl_8055D714;
}

void* fn_80031248(void) {
    /* Return the running total of items written into the current gdev CC
     * audio-state message (global lbl_8055D73C / ccMessageId). */
    return lbl_8055D73C;
}

#pragma dont_inline on
void *gdev_cc_initialize(void) {
    s32 old;
    s32 next;
    s32 newOff;
    s32 oldOff;
    void *newPtr;
    void *oldPtr;
    old = lbl_8055D748;
    next = (old + 1) & 1;
    newOff = next * 0x300;
    lbl_8055D748 = next;
    oldOff = old * 0x300;
    newPtr = (u8 *)&lbl_8035E820 + newOff;
    lbl_8055D744 = newPtr;
    oldPtr = (u8 *)&lbl_8035E820 + oldOff;
    return oldPtr;
}

extern void DCFlushRange(void *, u32);
extern void *__AXFXGetLfoSinTable_8003313C(void);
extern void *__AXGetStudio_800324C4(void);
extern u8 lbl_802FEDA0[];
/* Item tags of the MetroTRK gdev CC audio-state message written by
 * CircleBufferReadBytes: a list of 16-bit words, every item a tag followed by
 * its value as a high and a low half word. */
enum {
    CC_TAG_STUDIO = 0,           /* the AX studio, __AXGetStudio() */
    CC_TAG_BLOCK_0 = 1,          /* voice block address; one tag per audio mode */
    CC_TAG_BLOCK_1 = 2,
    CC_TAG_BLOCK_2 = 3,
    CC_TAG_LFO_SIN = 4,          /* __AXFXGetLfoSinTable() */
    CC_TAG_AUX_BEGIN = 5,        /* no value: the AUX buffers below follow */
    CC_TAG_AUX_A = 6,            /* stereo: AUX-A input + output */
    CC_TAG_AUX_B = 7,            /* stereo: AUX-B input + output */
    CC_TAG_AUX_C = 8,            /* stereo: AUX-C input + output */
    CC_TAG_AUX_A_DPL2 = 9,       /* Dolby Pro Logic II: AUX-A input + 5 outputs */
    CC_TAG_AUX_B_DPL2 = 10,      /* Dolby Pro Logic II: AUX-B input + 5 outputs */
    CC_TAG_WAVE_TABLE = 0xA,     /* address of the 4032-byte sine table lbl_802FEDA0 */
    CC_TAG_MASK = 0xB,           /* the 0x8000 "all channels" mask */
    CC_TAG_BUFFERS_STEREO = 0xC, /* voice block + AI DMA buffer, stereo mode */
    CC_TAG_BUFFERS_DPL2 = 0xD,   /* voice block + AI DMA buffer, DPL2 mode */
    CC_TAG_RING_LISTS = 0xE,     /* the four sound ring lists */
    CC_TAG_END = 0xF             /* no value: closes the message */
};
#pragma dont_inline on
/* Builds the MetroTRK gdev "CC" audio-state message in the current 0x300-byte CC
 * ring buffer: a list of tagged 16-bit items (see the CC_TAG_ enum) describing
 * where the audio system's buffers are, so the host tool can go and read them -
 * the AX studio, the voice block, the LFO sine table, every AUX input and output
 * buffer actually in use (the set depends on the audio mode, 2 = Dolby Pro Logic
 * II), the four sound ring lists and the AI DMA buffer that is about to be
 * filled.  lbl_8055D73C keeps a running total of the items written, which
 * fn_80031248 hands back, and the buffer is flushed to memory at the end.
 * Called by CircleBufferInitialize and by the audio start-up fn_800320E8. */
void CircleBufferReadBytes(u32 voiceBlock, u32 dmaBuffer, void *ringLists) {
#define ccWritePtr  lbl_8055D744 /* write position in the current CC buffer */
#define ccMessageId lbl_8055D73C /* running total of the items written */
#define ccMode      lbl_8055D740 /* audio mode; 2 selects the DPL2 items */
#define ccReady     lbl_8055D738 /* send the wave table item when set */
#define ccMask1     lbl_8055D734 /* AUX-A/B/C channel masks, 0x8000 by default */
#define ccMask2     lbl_8055D732
#define ccMask3     lbl_8055D730
#define ccWaveTable lbl_802FEDA0 /* 4032-byte sine table the host reads */
    void *buffer;
    void *start;

    start = ccWritePtr;
    ccMessageId = (void *)0x1E83;
    buffer = __AXGetStudio_800324C4();
    *(u16 *)ccWritePtr = CC_TAG_STUDIO;
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)(u32)buffer;
    ccWritePtr = (u8 *)ccWritePtr + 2;
    ccMessageId = (void *)((u32)ccMessageId + 0x1096);

    switch ((s32)ccMode) {
    case 0:
        *(u16 *)ccWritePtr = CC_TAG_BLOCK_0;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(voiceBlock >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)voiceBlock;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        ccMessageId = (void *)((u32)ccMessageId + 0x2DD);
        break;
    case 1:
        *(u16 *)ccWritePtr = CC_TAG_BLOCK_1;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(voiceBlock >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)voiceBlock;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        ccMessageId = (void *)((u32)ccMessageId + 0x33D);
        break;
    case 2:
        *(u16 *)ccWritePtr = CC_TAG_BLOCK_2;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(voiceBlock >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)voiceBlock;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        ccMessageId = (void *)((u32)ccMessageId + 0x39D);
        break;
    }

    buffer = __AXFXGetLfoSinTable_8003313C();
    *(u16 *)ccWritePtr = CC_TAG_LFO_SIN;
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)(u32)buffer;
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = CC_TAG_AUX_BEGIN;
    ccWritePtr = (u8 *)ccWritePtr + 2;

    if ((u32)ccMode == 2) {
        TRKDispatchMessage(&buffer); /* AUX-A input */
        if (buffer != 0) {
            *(u16 *)ccWritePtr = CC_TAG_AUX_A_DPL2;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = ccMask1;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxAInputDpl2(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxAOutput(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxAOutputDpl2R(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxAOutputDpl2Ls(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxAOutputDpl2Rs(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            ccMessageId = (void *)((u32)ccMessageId + 0x6D3);
        }
        __AXGetAuxAInput(&buffer); /* AUX-B input */
        if (buffer != 0) {
            *(u16 *)ccWritePtr = CC_TAG_AUX_B_DPL2;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = ccMask2;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxBInputDpl2(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxBOutput(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxBOutputDpl2R(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxBOutputDpl2Ls(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxBOutputDpl2Rs(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            ccMessageId = (void *)((u32)ccMessageId + 0x6D3);
        }
    } else {
        TRKDispatchMessage(&buffer); /* AUX-A input */
        if (buffer != 0) {
            *(u16 *)ccWritePtr = CC_TAG_AUX_A;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = ccMask1;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxAOutput(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            ccMessageId = (void *)((u32)ccMessageId + 0x4E1);
        }
        __AXGetAuxAInput(&buffer); /* AUX-B input */
        if (buffer != 0) {
            *(u16 *)ccWritePtr = CC_TAG_AUX_B;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = ccMask2;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxBOutput(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            ccMessageId = (void *)((u32)ccMessageId + 0x4E1);
        }
        __AXGetAuxBInput(&buffer); /* AUX-C input */
        if (buffer != 0) {
            *(u16 *)ccWritePtr = CC_TAG_AUX_C;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = ccMask3;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            __AXGetAuxCOutput(&buffer);
            *(u16 *)ccWritePtr = (u16)((u32)buffer >> 16);
            ccWritePtr = (u8 *)ccWritePtr + 2;
            *(u16 *)ccWritePtr = (u16)(u32)buffer;
            ccWritePtr = (u8 *)ccWritePtr + 2;
            ccMessageId = (void *)((u32)ccMessageId + 0x4E1);
        }
    }

    if (ccReady != 0) {
        *(u16 *)ccWritePtr = CC_TAG_MASK;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = 0x8000;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = CC_TAG_WAVE_TABLE;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)((u32)ccWaveTable >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(u32)ccWaveTable;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        ccMessageId = (void *)((u32)ccMessageId + 0x73A);
    }

    *(u16 *)ccWritePtr = CC_TAG_RING_LISTS;
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)(((u32 *)ringLists)[0] >> 16);
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)((u32 *)ringLists)[0];
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)(((u32 *)ringLists)[1] >> 16);
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)((u32 *)ringLists)[1];
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)(((u32 *)ringLists)[2] >> 16);
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)((u32 *)ringLists)[2];
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)(((u32 *)ringLists)[3] >> 16);
    ccWritePtr = (u8 *)ccWritePtr + 2;
    *(u16 *)ccWritePtr = (u16)((u32 *)ringLists)[3];
    ccWritePtr = (u8 *)ccWritePtr + 2;
    ccMessageId = (void *)((u32)ccMessageId + 0x199);

    if ((u32)ccMode == 2) {
        *(u16 *)ccWritePtr = CC_TAG_BUFFERS_DPL2;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(voiceBlock >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)voiceBlock;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(dmaBuffer >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)dmaBuffer;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        ccMessageId = (void *)((u32)ccMessageId + 0x2AF);
    } else {
        *(u16 *)ccWritePtr = CC_TAG_BUFFERS_STEREO;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(voiceBlock >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)voiceBlock;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)(dmaBuffer >> 16);
        ccWritePtr = (u8 *)ccWritePtr + 2;
        *(u16 *)ccWritePtr = (u16)dmaBuffer;
        ccWritePtr = (u8 *)ccWritePtr + 2;
        ccMessageId = (void *)((u32)ccMessageId + 0x299);
    }

    *(u16 *)ccWritePtr = CC_TAG_END;
    ccWritePtr = (u8 *)ccWritePtr + 2;
    ccMessageId = (void *)((u32)ccMessageId + 0x1E);
    DCFlushRange(start, 0x300);
#undef ccWaveTable
#undef ccMask3
#undef ccMask2
#undef ccMask1
#undef ccReady
#undef ccMode
#undef ccMessageId
#undef ccWritePtr
}
#pragma dont_inline reset
void CircleBufferWriteBytes(void) {
    /* Initialize the MetroTRK gdev CC ring-buffer state: reset the mode and
       buffer index, point the trace writer at the static 0x300-byte buffer,
       flag it ready, and load the three 16-bit CC mask values (0x8000). */
#define ccMode        lbl_8055D740
#define ccBufferIndex lbl_8055D748
#define ccWritePtr    lbl_8055D744
#define ccReady       lbl_8055D738
#define ccMask1       lbl_8055D734
#define ccMask2       lbl_8055D732
#define ccMask3       lbl_8055D730
    ccMode = 0;
    ccBufferIndex = 0;
    ccWritePtr = lbl_8035E820;
    ccReady = 1;
    ccMask1 = 0x8000;
    ccMask2 = 0x8000;
    ccMask3 = 0x8000;
#undef ccMask3
#undef ccMask2
#undef ccMask1
#undef ccReady
#undef ccWritePtr
#undef ccBufferIndex
#undef ccMode
}

void fn_80031C68(void) {

}

extern void *lbl_8055D740;
void fn_80031C6C(void* mode) {
    /* Set the MetroTRK communication-channel mode global (ccMode). */
    lbl_8055D740 = mode;
}

u16 fn_80031C74(void) {
    /* Return ccMask1 (lbl_8055D734), the first MetroTRK CC AUX channel mask (0x8000 by default). */
    return lbl_8055D734;
}

u16 fn_80031C7C(void) {
    /* Return the second debug CC channel mask (ccMask2, lbl_8055D732). */
    return lbl_8055D732;
}

u16 fn_80031C84(void) {
    /* Return the third debug CC channel mask (ccMask3, lbl_8055D730). */
    return lbl_8055D730;
}

void fn_80031C8C(unsigned short mask) {
    /* Set ccMask1 (lbl_8055D734), the first MetroTRK debug CC AUX channel mask. */
    lbl_8055D734 = mask;
}

void fn_80031C94(unsigned short mask) {
    /* Set ccMask2 (lbl_8055D732), the second MetroTRK debug CC channel mask. */
    #define ccMask2 lbl_8055D732
    ccMask2 = mask;
    #undef ccMask2
}

void fn_80031C9C(unsigned short mask) {
    /* Set ccMask3 (lbl_8055D730), the third MetroTRK debug CC channel mask. */
    lbl_8055D730 = mask;
}

extern u64 lbl_8035EE20[];
extern s32 lbl_8055D788;
extern s32 lbl_8055D754, lbl_8055D758, lbl_8055D750;
extern void fn_80032EAC(u32, void *);
extern void __AXPrintStudio(void);
extern void *gdev_cc_initialize(void);
extern void DSPSendMailToDSP(u32);
extern s32 DSPCheckMailToDSP(void);
extern void TRKReadBuffer1_ui64(void);
extern void InitMetroTRKCommTable(void);
extern s32 fn_800328E8(void);
extern void CircleBufferReadBytes(u32, u32, void *);
extern void *__AXGetCurrentProfile(void);
void CircleBufferInitialize(u32 arg0) {
    u8 *base = (u8 *)lbl_8035EE20;
    s32 start;
    s32 ring;
    s32 i;
    u8 *profile;
    void *ptrs[4];
    *(u64 *)base = OSGetTime();
    fn_80032EAC(arg0, base);
    __AXPrintStudio();
    arg0 = (u32)gdev_cc_initialize();
    DSPSendMailToDSP(0xBABE0080);
    while (DSPCheckMailToDSP() != 0) { }
    DSPSendMailToDSP(arg0);
    while (DSPCheckMailToDSP() != 0) { }
    TRKReadBuffer1_ui64();
    *(u64 *)(base + 8) = OSGetTime();
    InitMetroTRKCommTable();
    *(u64 *)(base + 0x10) = OSGetTime();
    *(u64 *)(base + 0x18) = OSGetTime();
    if (lbl_8055D774 != 0) ((void (*)(void))lbl_8055D774)();
    *(u64 *)(base + 0x20) = OSGetTime();
    start = lbl_8055D754;
    ptrs[0] = base + 0x40 + start * 2;
    ptrs[1] = base + 0x40 + start * 2 + 0x168;
    ptrs[2] = base + 0x40 + start * 2 + 0x2D0;
    ptrs[3] = base + 0x40 + start * 2 + 0x438;
    ring = start + 0x12;
    if (ring >= lbl_8055D758) ring = 0;
    if (lbl_8055D750 >= start && lbl_8055D750 < start + 0x12) lbl_8055D750 = ring;
    lbl_8055D754 = ring;
    CircleBufferReadBytes((u32)(base + 0x5E0), (u32)(base + 0x8E0 + lbl_8055D788 * 0x180), ptrs);
    ++lbl_8055D788;
    if (lbl_8055D75C == 1) lbl_8055D788 %= 3;
    else {
        lbl_8055D788 &= 1;
        AIInitDMA(base + 0x8E0 + lbl_8055D788 * 0x180, 0x180);
    }
    *(u64 *)(base + 0x28) = OSGetTime();
    *(s32 *)(base + 0x30) = fn_800328E8();
    profile = __AXGetCurrentProfile();
    if (profile != 0) {
        for (i = 0; i < 7; ++i) {
            profile[0] = base[i * 8];
            profile[1] = base[i * 8 + 1];
            profile[2] = base[i * 8 + 2];
            profile[3] = base[i * 8 + 3];
            profile[4] = base[i * 8 + 4];
            profile[5] = base[i * 8 + 5];
            profile[6] = base[i * 8 + 6];
            profile[7] = base[i * 8 + 7];
            profile += 8;
        }
    }
}

/* Initialize/tick the audio/DSP path: capture start time on first entry,
 * transition state (reset + CircleBufferInitialize or assert DSP task), and
 * advance the AI DMA buffer ring when enabled. */
void fn_80031ED4(void) {
    u64 time;
    if ((s32)lbl_8055D780 == 0) {
        time = OSGetTime();
        lbl_8055D77C = (u32)time;
        lbl_8055D778 = (u32)(time >> 32);
    }
    if (lbl_8055D780 == 1U) {
        lbl_8055D780 = 0;
        CircleBufferInitialize(0);
    } else {
        lbl_8055D780 = 2;
        DSPAssertTask(lbl_8035FB80);
    }
    if (lbl_8055D75C == 1U) {
        AIInitDMA(lbl_8035F700 + lbl_8055D784 * 0x180, 0x180);
        lbl_8055D784 += 1;
        lbl_8055D784 %= 3;
    }
}

extern s32 lbl_8055D770;
extern s32 lbl_8055D76C;
extern s32 lbl_8055D760;
extern volatile u32 lbl_8055D778;
extern volatile u32 lbl_8055D77C;
extern volatile u32 lbl_8055D784;
extern u32 lbl_8055D780;
extern u32 lbl_8055D75C;
extern u8 lbl_8035F700[];
extern u8 lbl_8035FB80[];
extern u64 OSGetTime(void);
extern void CircleBufferInitialize(u32);
extern void OSWakeupThread(void *);
extern void DSPAssertTask(void *);
extern void AIInitDMA(void *, u32);
/* DSP-init callback for the audio task: signal that the DSP has run its init
 * routine, releasing fn_80032004 which spins on this flag until it is set. */
void __AXDSPInitCallback_80031F90(void) {
#define s_dspInitDone lbl_8055D770
    s_dspInitDone = 1;
#undef s_dspInitDone
}

void fn_80031F9C(void) {
    /* AXOut.c's DSP-task resume callback: fn_80032004 stores it at
     * __AXDSPTask + 0x2C, between __AXDSPInitCallback_80031F90 and
     * __AXDSPDoneCallback, and the DSP interrupt runs it when the audio task
     * resumes on the DSP.  Names this build lost: lbl_8055D780 is
     * __AXOutDspReady, lbl_8055D778/7C the time stamp fn_80031ED4
     * (__AXOutAiCallback) takes when it asserts the task, and
     * CircleBufferInitialize() is __AXOutNewFrame(). */
#define __AXOutDspReady       lbl_8055D780
#define __AXDSPAssertTimeHi   lbl_8055D778
#define __AXDSPAssertTimeLo   lbl_8055D77C
#define AX_OUT_DSP_IDLE       0U  /* nothing pending */
#define AX_OUT_DSP_UP         1U  /* DSP task is up: the AI callback runs the frame */
#define AX_OUT_DSP_W4_TASK    2U  /* task asserted: waiting for the DSP to take it */

    /* Waiting on the assert: run the audio frame here, giving __AXOutNewFrame()
     * the time the DSP took to take the task over.  Otherwise just mark the task
     * up and leave the next frame to the AI callback. */
    if (__AXOutDspReady == AX_OUT_DSP_W4_TASK) {
        __AXOutDspReady = AX_OUT_DSP_IDLE;
        CircleBufferInitialize((u32)(OSGetTime() - (((u64)__AXDSPAssertTimeHi << 32) | __AXDSPAssertTimeLo)) >> 2);
    } else {
        __AXOutDspReady = AX_OUT_DSP_UP;
    }
#undef __AXOutDspReady
#undef __AXDSPAssertTimeHi
#undef __AXDSPAssertTimeLo
#undef AX_OUT_DSP_IDLE
#undef AX_OUT_DSP_UP
#undef AX_OUT_DSP_W4_TASK
}

/* DSP-task done callback: mark the audio task finished and wake the thread
 * sleeping on the DSP sleep queue. */
void __AXDSPDoneCallback(void) {
#define s_dspDoneFlag lbl_8055D76C
#define s_dspSleepQueue lbl_8055D760 /* queue __AXDSPDoneCallback wakes */
    s_dspDoneFlag = 1;
    OSWakeupThread(&s_dspSleepQueue);
#undef s_dspDoneFlag
#undef s_dspSleepQueue
}

void fn_80032000(void) {

}

extern u8 lbl_8035FBD0[];
extern u8 lbl_802FFD60[];
extern u16 lbl_80558DE0;
extern u16 lbl_80558DE2;
extern u16 lbl_80558DE4;
extern void OSInitThreadQueue(void *);
extern s32 DSPReset(void);
extern void DSPInit(void);
extern void DSPAssertInt(void *);
#pragma scheduling on
void fn_80032004(void) {
    struct {
        u8 pad[4];
        u32 unk4;
        u8 pad8[4];
        void *unkC;
        u32 unk10;
        u32 unk14;
        void *unk18;
        u32 unk1C;
        u32 unk20;
        u16 unk24;
        u16 unk26;
        void (*unk28)(void);
        void (*unk2C)(void);
        void (*unk30)(void);
        void (*unk34)(void);
    } *task = (void *)lbl_8035FB80;
    u32 zero = 0;
    task->unk4 = zero;
    lbl_8055D770 = zero;
    task->unkC = lbl_802FFD60;
    task->unk10 = lbl_80558DE4;
    task->unk14 = zero;
    task->unk18 = lbl_8035FBD0;
    task->unk1C = 0x2000;
    task->unk20 = zero;
    task->unk24 = lbl_80558DE0;
    task->unk26 = lbl_80558DE2;
    task->unk28 = __AXDSPInitCallback_80031F90;
    task->unk2C = fn_80031F9C;
    task->unk30 = __AXDSPDoneCallback;
    task->unk34 = fn_80032000;
    lbl_8055D76C = zero;
    OSInitThreadQueue(&lbl_8055D760);
    if (DSPReset() == 0) DSPInit();
    DSPAssertInt(lbl_8035FB80);
    while (lbl_8055D770 == 0) {}
}

extern u32 fn_8003010C(u32);
extern void AIStartDMA(void);
extern s32 lbl_8055D768;
void fn_800320E8(s32 arg0) {
    u32 zero = 0;
    u8 *base;
    u8 *ring;
    u8 *dma;
    s32 *p;
    u32 i;
    void *buffers[4];

    lbl_8055D788 = zero;
    lbl_8055D784 = zero;
    lbl_8055D75C = arg0;
    lbl_8055D768 = zero;

    base = (u8 *)lbl_8035EE20;
    p = (s32 *)(base + 0x8E0);
    i = 0x20;
    do {
        p[0] = zero;
        p[1] = zero;
        p[2] = zero;
        p[3] = zero;
        p[4] = zero;
        p[5] = zero;
        p[6] = zero;
        p[7] = zero;
        p[8] = zero;
        p += 9;
    } while (--i != 0);
    DCFlushRange(base + 0x8E0, 0x480);

    p = (s32 *)(base + 0x5E0);
    i = 0x18;
    do {
        p[0] = zero;
        p[1] = zero;
        p[2] = zero;
        p[3] = zero;
        p[4] = zero;
        p[5] = zero;
        p[6] = zero;
        p[7] = zero;
        p += 8;
    } while (--i != 0);
    DCFlushRange(base + 0x5E0, 0x300);

    p = (s32 *)(base + 0x40);
    i = 0x24;
    do {
        p[0] = zero;
        p[1] = zero;
        p[2] = zero;
        p[3] = zero;
        p[4] = zero;
        p[5] = zero;
        p[6] = zero;
        p[7] = zero;
        p[8] = zero;
        p[9] = zero;
        p += 10;
    } while (--i != 0);
    DCFlushRange(base + 0x40, 0x5A0);

    fn_80032004();
    fn_8003010C((u32)fn_80031ED4);

    ring = base + 0x40;
    buffers[0] = ring;
    buffers[1] = ring + 0x168;
    buffers[2] = ring + 0x2D0;
    buffers[3] = ring + 0x438;
    lbl_8055D750 = 0x12;
    lbl_8055D754 = 0x12;
    lbl_8055D758 = 0xB4;

    if (lbl_8055D75C == 1) {
        dma = base + 0x8E0;
        CircleBufferReadBytes((u32)(base + 0x5E0), (u32)(dma + 0x300), buffers);
    } else {
        dma = base + 0x8E0;
        CircleBufferReadBytes((u32)(base + 0x5E0), (u32)(dma + 0x180), buffers);
    }

    lbl_8055D780 = 1;
    lbl_8055D774 = zero;
    if (lbl_8055D75C == 1) {
        dma = base + 0x8E0;
        AIInitDMA(dma + lbl_8055D784 * 0x180, 0x180);
        lbl_8055D784++;
        lbl_8055D784 &= 1;
    } else {
        dma = base + 0x8E0;
        AIInitDMA(dma + lbl_8055D788 * 0x180, 0x180);
    }
    AIStartDMA();
}

#pragma scheduling reset
/* Stops the audio output path, with interrupts kept off throughout: drops the AI
 * DMA callback so no more samples are asked for, flags the AX DSP task (its 0x8
 * flags word, the SDK's DSP_TASK_CANCELED bit) so the DSP finishes it, sleeps
 * until that task's done callback __AXDSPDoneCallback wakes this thread, and then
 * stops the AI DMA. */
void fn_800322E4(void) {
#define s_aiDmaCallback lbl_8055D774 /* callback AIRegisterDMACallback registers */
#define s_dspTask lbl_8035FB80       /* the AX DSP task fn_80032004 set up */
#define s_dspSleepQueue lbl_8055D760 /* queue __AXDSPDoneCallback wakes */
    s32 enabled = OSDisableInterrupts();
    s_aiDmaCallback = 0;
    __DSPHandler(s_dspTask);
    OSSleepThread(&s_dspSleepQueue);
    AIStopDMA();
    OSRestoreInterrupts(enabled);
#undef s_aiDmaCallback
#undef s_dspTask
#undef s_dspSleepQueue
}

/* Registers the AI DMA completion callback, returning the previously registered callback. */
u32 AIRegisterDMACallback(u32 callback) {
    u32 oldCallback = lbl_8055D774;
    BOOL enabled = OSDisableInterrupts();
    lbl_8055D774 = callback;
    OSRestoreInterrupts(enabled);
    return oldCallback;
}

/* Returns the unread sample count in the remote audio ring buffer: the write pointer (less a 0x24 margin)
 * minus the read pointer, wrapping around the buffer size on underflow. */
s32 AXRmtGetSamplesLeft(void) {
    s32 result;
    s32 available = lbl_8055D754 - 0x24;
    if (available < 0) {
        available += lbl_8055D758;
    }
    result = available - lbl_8055D750;
    if (result < 0) {
        return result + lbl_8055D758;
    }
    return result;
}

extern u8 lbl_8035EE60[];
extern void DCInvalidateRange(void *, u32);
s32 AXRmtGetSamples(s32 arg0, s16 *arg1, s32 arg2) {
    s32 count;
    s32 index;
    s32 i;
    count = lbl_8055D754 - 0x24;
    if (count < 0) count += lbl_8055D758;
    count = count - lbl_8055D750;
    if (count < 0) count += lbl_8055D758;
    if (arg2 <= count) {
    } else {
        count = arg2;
    }
    index = lbl_8055D750;
    for (i = count; i > 0; i--) {
        *arg1++ = *(s16 *)(lbl_8035EE60 + arg0 * 0x168 + index * 2);
        index++;
        if (index >= lbl_8055D758) index = 0;
    }
    DCInvalidateRange(lbl_8035EE60 + arg0 * 0x168, lbl_8055D758 << 1);
    return count;
}

void AXRmtAdvancePtr(s32 samples) {
    /* Advance the remote audio read pointer, clamping to the available sample space in the ring buffer. */
    s32 available;
    available = lbl_8055D754 - 0x24;
    if (available < 0) available += lbl_8055D758;
    available -= lbl_8055D750;
    if (available < 0) available += lbl_8055D758;
    if (samples > available) samples = available;
    lbl_8055D750 += samples;
    if (lbl_8055D750 >= lbl_8055D758) {
        lbl_8055D750 -= lbl_8055D758;
    }
}

extern u8 lbl_80363BE0[];
void *__AXGetStudio_800324C4(void) {
    /* Return the pointer to the AX studio parameter block (AXSPB). */
    #define s_axStudio lbl_80363BE0
    return s_axStudio;
    #undef s_axStudio
}

