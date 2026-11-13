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
    u32 zero = 0;
    if ((s32)lbl_8055D6A8 != 1) {
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
    lbl_8055D6A8 = 0;
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
    u32 tmp;
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
        tmp = *(volatile u32 *)0xCD006C08;
        status = tmp & 0x7FFFFFFFU;
        tmp = *(volatile u32 *)0xCD006C08;
        control = tmp & 0x7FFFFFFFU;
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
    OSRegisterVersion(lbl_80558DD8);
    TRKAppendBuffer_ui32();
    fn_800331A0();
    __AXSPBInit();
    TRKGetInput();
    CircleBufferWriteBytes();
    fn_800320E8(0);
}

void TRKReadBuffer_ui32(void) {
    TRKAppendBuffer1_ui64();
    fn_80033404();
    fn_80032778();
    usr_puts_serial();
    fn_80031C68();
    fn_800322E4();
}

extern int lbl_8035BEA0[4];
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
    u32 *a;
    u32 *b;
    s32 count;
    lbl_8055D6E8 = 0;
    a = lbl_8035BF20;
    b = (u32 *)lbl_8035BEA0;
    count = 2;
    do {
        *(u32 *)((u8 *)a + 0x00) = 0;
        *(u32 *)((u8 *)b + 0x00) = 0;
        *(u32 *)((u8 *)a + 0x04) = 0;
        *(u32 *)((u8 *)b + 0x04) = 0;
        *(u32 *)((u8 *)a + 0x08) = 0;
        *(u32 *)((u8 *)b + 0x08) = 0;
        *(u32 *)((u8 *)a + 0x0C) = 0;
        *(u32 *)((u8 *)b + 0x0C) = 0;
        *(u32 *)((u8 *)a + 0x10) = 0;
        *(u32 *)((u8 *)b + 0x10) = 0;
        *(u32 *)((u8 *)a + 0x14) = 0;
        *(u32 *)((u8 *)b + 0x14) = 0;
        *(u32 *)((u8 *)a + 0x18) = 0;
        *(u32 *)((u8 *)b + 0x18) = 0;
        *(u32 *)((u8 *)a + 0x1C) = 0;
        *(u32 *)((u8 *)b + 0x1C) = 0;
        *(u32 *)((u8 *)a + 0x20) = 0;
        *(u32 *)((u8 *)b + 0x20) = 0;
        *(u32 *)((u8 *)a + 0x24) = 0;
        *(u32 *)((u8 *)b + 0x24) = 0;
        *(u32 *)((u8 *)a + 0x28) = 0;
        *(u32 *)((u8 *)b + 0x28) = 0;
        *(u32 *)((u8 *)a + 0x2C) = 0;
        *(u32 *)((u8 *)b + 0x2C) = 0;
        *(u32 *)((u8 *)a + 0x30) = 0;
        *(u32 *)((u8 *)b + 0x30) = 0;
        *(u32 *)((u8 *)a + 0x34) = 0;
        *(u32 *)((u8 *)b + 0x34) = 0;
        *(u32 *)((u8 *)a + 0x38) = 0;
        *(u32 *)((u8 *)b + 0x38) = 0;
        *(u32 *)((u8 *)a + 0x3C) = 0;
        a += 16;
        *(u32 *)((u8 *)b + 0x3C) = 0;
        b += 16;
    } while (--count);
}

#pragma pop
void TRKReadBuffer(void *arg0) {
    u32 old = lbl_8035BEA0[0];
    *(u32 *)arg0 = old;
    lbl_8035BEA0[0] = (u32)arg0;
    *(u32 *)((u8 *)arg0 + 0xC) = 0;
}

void TRKAppendBuffer(void *arg0) {
    *(u32 *)((u8 *)arg0 + 8) = lbl_8055D6E8;
    lbl_8055D6E8 = (u32)arg0;
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
void TRKGetFreeBuffer(void *arg0) {
    s32 level = OSDisableInterrupts();
    TRKReleaseBuffer(arg0);
    if (*(u16 *)((u8 *)arg0 + 0x148) == 1) {
        *(u32 *)((u8 *)arg0 + 0x20) = 1;
    }
    fn_80033148(arg0);
    {
        void *head = (void *)lbl_8035BEA0[0];
        *(void **)arg0 = head;
        lbl_8035BEA0[0] = (s32)arg0;
    }
    *(u32 *)((u8 *)arg0 + 0xC) = 0;
    OSRestoreInterrupts(level);
}

#pragma use_lmw_stmw off
void *TRKInitializeMessageBuffers(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(s32);
    extern void fn_80033148(void *);
    s32 irq = OSDisableInterrupts();
    u32 index;
    void *buf = (void *)lbl_8035BEA0[0];
    if (buf != 0)
        lbl_8035BEA0[0] = *(u32 *)buf;
    if (buf == 0) {
        u32 *firstp = (u32 *)lbl_8035BEA0 + 1;
        u32 *lastp = lbl_8035BF20 + 1;
        for (index = 1; index < arg0; ++index, ++firstp, ++lastp) {
            u32 first = *firstp;
            if (first != 0) {
                u32 last = *lastp;
                if (first == last) {
                    *lastp = 0;
                    buf = (void *)first;
                    *firstp = 0;
                } else if (last != 0) {
                    buf = (void *)last;
                    *lastp = *(u32 *)((u8 *)last + 4);
                    *(u32 *)((u8 *)buf + 4) = 0;
                }
            }
            if (buf != 0) {
                if (*(u16 *)((u8 *)buf + 0x148) == 1)
                    *(u32 *)((u8 *)buf + 0x20) = 1;
                if (*(void (**)(void *))((u8 *)buf + 0x10) != 0)
                    (*(void (**)(void *))((u8 *)buf + 0x10))(buf);
                break;
            }
        }
    }
    if (buf != 0) {
        void *head = (void *)lbl_8035BEA0[arg0];
        *(void **)buf = head;
        *(u32 *)((u8 *)buf + 4) = 0;
        if (head != 0) {
            *(void **)((u8 *)head + 4) = buf;
            lbl_8035BEA0[arg0] = (u32)buf;
        } else {
            lbl_8035BEA0[arg0] = (u32)buf;
            lbl_8035BF20[arg0] = (u32)buf;
        }
        *(u32 *)((u8 *)buf + 0xC) = arg0;
        *(s32 *)((u8 *)buf + 0x10) = arg1;
        *(s32 *)((u8 *)buf + 0x14) = arg2;
        fn_80033148(buf);
    }
    OSRestoreInterrupts(irq);
    return buf;
}
#pragma use_lmw_stmw reset

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

void usr_puts_serial(void) {
    lbl_8055D728 = 0;
    lbl_8055D724 = 0;
    lbl_8055D720 = 0;
}

void TRKDispatchMessage(void **arg0) {
    extern u8 lbl_8035BFA0[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D728 != 0) {
        *arg0 = lbl_8035BFA0 + lbl_8055D6F8 * 0x480;
        return;
    }
    *arg0 = 0;
}

void __AXGetAuxAOutput(void **arg0) {
    extern u8 lbl_8035BFA0[];
    extern s32 lbl_8055D6F4;
    *arg0 = lbl_8035BFA0 + lbl_8055D6F4 * 0x480;
}

extern u8 lbl_8035DAA0[];
extern u8 lbl_8035BFA0[];
extern s32 lbl_8055D6F8;
extern s32 lbl_8055D6F4;
void __AXGetAuxAInputDpl2(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F8 * 0x480 + 0x180;
}

void __AXGetAuxAOutputDpl2R(void **arg0) {
    *arg0 = lbl_8035BFA0 + lbl_8055D6F4 * 0x480 + 0x180;
}

void __AXGetAuxAOutputDpl2Ls(void **arg0) {
    *arg0 = lbl_8035BFA0 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxAOutputDpl2Rs(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F4 * 0x480 + 0x180;
}

void __AXGetAuxAInput(void **arg0) {
    extern u8 lbl_8035CD20[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D724 != 0) {
        *arg0 = lbl_8035CD20 + lbl_8055D6F8 * 0x480;
        return;
    }
    *arg0 = 0;
}

void __AXGetAuxBOutput(void **arg0) {
    extern u8 lbl_8035CD20[];
    extern s32 lbl_8055D6F4;
    *arg0 = lbl_8035CD20 + lbl_8055D6F4 * 0x480;
}

void __AXGetAuxBInputDpl2(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F8 * 0x480 + 0x300;
}

extern u8 lbl_8035CD20[];
void __AXGetAuxBOutputDpl2R(void **arg0) {
    *arg0 = lbl_8035CD20 + lbl_8055D6F4 * 0x480 + 0x180;
}

void __AXGetAuxBOutputDpl2Ls(void **arg0) {
    *arg0 = lbl_8035CD20 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxBOutputDpl2Rs(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxBInput(void **arg0) {
    extern u8 lbl_8035DAA0[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D720 != 0) {
        *arg0 = lbl_8035DAA0 + lbl_8055D6F8 * 0x480;
        return;
    }
    *arg0 = 0;
}

void __AXGetAuxCOutput(void **arg0) {
    extern u8 lbl_8035DAA0[];
    extern s32 lbl_8055D6F4;
    *arg0 = lbl_8035DAA0 + lbl_8055D6F4 * 0x480;
}

void InitMetroTRKCommTable(void) {
    void *a[4];
    void *c[3];
    void *b[4];
    void *d[3];
    void *e[3];
    u8 *base0 = lbl_8035BFA0;
    u8 *base1 = lbl_8035BFA0 + 0xD80;
    u8 *base2 = lbl_8035BFA0 + 0x1B00;
    s32 i8 = lbl_8055D6F8 * 0x480;
    s32 i4 = lbl_8055D6F4 * 0x480;
    lbl_8055D710 = base0 + i8;
    lbl_8055D70C = base0 + i4;
    lbl_8055D708 = base1 + i8;
    lbl_8055D704 = base1 + i4;
    lbl_8055D700 = base2 + i8;
    lbl_8055D6FC = base2 + i4;
    if (lbl_8055D728 != 0) {
        if ((u32)lbl_8055D740 == 2) {
            s32 o = lbl_8055D6F0 * 0x480;
            u8 *p = base0 + o;
            u8 *q = base2 + o;
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
            u8 *p = base0 + lbl_8055D6F0 * 0x480;
            c[0] = p;
            c[1] = p + 0x180;
            c[2] = p + 0x300;
            DCInvalidateRange(c[0], 0x480);
            ((TRKCommFn)lbl_8055D728)(c, lbl_8055D71C);
            DCFlushRangeNoSync(c[0], 0x480);
        }
    }
    if (lbl_8055D724 != 0) {
        if ((u32)lbl_8055D740 == 2) {
            s32 o = lbl_8055D6F0 * 0x480;
            u8 *p = base1 + o;
            u8 *q = base2 + o;
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
            u8 *p = base1 + lbl_8055D6F0 * 0x480;
            d[0] = p;
            d[1] = p + 0x180;
            d[2] = p + 0x300;
            DCInvalidateRange(d[0], 0x480);
            ((TRKCommFn)lbl_8055D724)(d, lbl_8055D718);
            DCFlushRangeNoSync(d[0], 0x480);
        }
    }
    if (lbl_8055D720 != 0 && (u32)lbl_8055D740 != 2) {
        u8 *p = base2 + lbl_8055D6F0 * 0x480;
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

void AXRegisterAuxACallback(void *arg0, void *arg1) {
    lbl_8055D728 = arg0;
    lbl_8055D71C = arg1;
}

void AXRegisterAuxBCallback(void *arg0, void *arg1) {
    lbl_8055D724 = arg0;
    lbl_8055D718 = arg1;
}

void AXRegisterAuxCCallback(void *arg0, void *arg1) {
    lbl_8055D720 = arg0;
    lbl_8055D714 = arg1;
}

void AXGetAuxACallback(void **arg0, void **arg1) {
    *arg0 = lbl_8055D728;
    *arg1 = lbl_8055D71C;
}

void AXGetAuxBCallback(void **arg0, void **arg1) {
    *arg0 = lbl_8055D724;
    *arg1 = lbl_8055D718;
}

void AXGetAuxCCallback(void **arg0, void **arg1) {
    *arg0 = lbl_8055D720;
    *arg1 = lbl_8055D714;
}

void* fn_80031248(void) {
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
#pragma dont_inline on
void CircleBufferReadBytes(u32 arg0, u32 arg1, void *arg2) {
    void *sp8;
    void *temp_r31;

    temp_r31 = lbl_8055D744;
    lbl_8055D73C = (void *)0x1E83;
    sp8 = __AXGetStudio_800324C4();
    *(u16 *)lbl_8055D744 = 0;
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x1096);

    switch ((s32)lbl_8055D740) {
    case 0:
        *(u16 *)lbl_8055D744 = 1;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(arg0 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)arg0;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x2DD);
        break;
    case 1:
        *(u16 *)lbl_8055D744 = 2;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(arg0 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)arg0;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x33D);
        break;
    case 2:
        *(u16 *)lbl_8055D744 = 3;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(arg0 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)arg0;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x39D);
        break;
    }

    sp8 = __AXFXGetLfoSinTable_8003313C();
    *(u16 *)lbl_8055D744 = 4;
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = 5;
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;

    if ((u32)lbl_8055D740 == 2) {
        TRKDispatchMessage(&sp8);
        if (sp8 != 0) {
            *(u16 *)lbl_8055D744 = 9;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = lbl_8055D734;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxAInputDpl2(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxAOutput(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxAOutputDpl2R(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxAOutputDpl2Ls(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxAOutputDpl2Rs(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x6D3);
        }
        __AXGetAuxAInput(&sp8);
        if (sp8 != 0) {
            *(u16 *)lbl_8055D744 = 10;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = lbl_8055D732;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxBInputDpl2(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxBOutput(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxBOutputDpl2R(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxBOutputDpl2Ls(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxBOutputDpl2Rs(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x6D3);
        }
    } else {
        TRKDispatchMessage(&sp8);
        if (sp8 != 0) {
            *(u16 *)lbl_8055D744 = 6;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = lbl_8055D734;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxAOutput(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x4E1);
        }
        __AXGetAuxAInput(&sp8);
        if (sp8 != 0) {
            *(u16 *)lbl_8055D744 = 7;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = lbl_8055D732;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxBOutput(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x4E1);
        }
        __AXGetAuxBInput(&sp8);
        if (sp8 != 0) {
            *(u16 *)lbl_8055D744 = 8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = lbl_8055D730;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            __AXGetAuxCOutput(&sp8);
            *(u16 *)lbl_8055D744 = (u16)((u32)sp8 >> 16);
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            *(u16 *)lbl_8055D744 = (u16)(u32)sp8;
            lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
            lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x4E1);
        }
    }

    if (lbl_8055D738 != 0) {
        *(u16 *)lbl_8055D744 = 0xB;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = 0x8000;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = 0xA;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)((u32)lbl_802FEDA0 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(u32)lbl_802FEDA0;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x73A);
    }

    *(u16 *)lbl_8055D744 = 0xE;
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)(((u32 *)arg2)[0] >> 16);
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)((u32 *)arg2)[0];
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)(((u32 *)arg2)[1] >> 16);
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)((u32 *)arg2)[1];
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)(((u32 *)arg2)[2] >> 16);
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)((u32 *)arg2)[2];
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)(((u32 *)arg2)[3] >> 16);
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    *(u16 *)lbl_8055D744 = (u16)((u32 *)arg2)[3];
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x199);

    if ((u32)lbl_8055D740 == 2) {
        *(u16 *)lbl_8055D744 = 0xD;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(arg0 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)arg0;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(arg1 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)arg1;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x2AF);
    } else {
        *(u16 *)lbl_8055D744 = 0xC;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(arg0 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)arg0;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)(arg1 >> 16);
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        *(u16 *)lbl_8055D744 = (u16)arg1;
        lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
        lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x299);
    }

    *(u16 *)lbl_8055D744 = 0xF;
    lbl_8055D744 = (u8 *)lbl_8055D744 + 2;
    lbl_8055D73C = (void *)((u32)lbl_8055D73C + 0x1E);
    DCFlushRange(temp_r31, 0x300);
}
#pragma dont_inline reset
void CircleBufferWriteBytes(void) {
    lbl_8055D740 = 0;
    lbl_8055D748 = 0;
    lbl_8055D744 = lbl_8035E820;
    lbl_8055D738 = 1;
    lbl_8055D734 = 0x8000;
    lbl_8055D732 = 0x8000;
    lbl_8055D730 = 0x8000;
}

void fn_80031C68(void) {

}

extern void *lbl_8055D740;
void fn_80031C6C(void* hi) {
    lbl_8055D740 = hi;
}

u16 fn_80031C74(void) {
    return lbl_8055D734;
}

u16 fn_80031C7C(void) {
    return lbl_8055D732;
}

u16 fn_80031C84(void) {
    return lbl_8055D730;
}

void fn_80031C8C(unsigned short arg0) {
    lbl_8055D734 = arg0;
}

void fn_80031C94(unsigned short arg0) {
    lbl_8055D732 = arg0;
}

void fn_80031C9C(unsigned short arg0) {
    lbl_8055D730 = arg0;
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
void __AXDSPInitCallback_80031F90(void) {
    lbl_8055D770 = 1;
}

void fn_80031F9C(void) {
    if (lbl_8055D780 == 2U) {
        lbl_8055D780 = 0;
        CircleBufferInitialize((u32)(OSGetTime() - (((u64)lbl_8055D778 << 32) | lbl_8055D77C)) >> 2);
    } else {
        lbl_8055D780 = 1;
    }
}

void __AXDSPDoneCallback(void) {
    lbl_8055D76C = 1;
    OSWakeupThread(&lbl_8055D760);
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
void fn_800322E4(void) {
    s32 enabled = OSDisableInterrupts();
    lbl_8055D774 = 0;
    __DSPHandler(lbl_8035FB80);
    OSSleepThread(&lbl_8055D760);
    AIStopDMA();
    OSRestoreInterrupts(enabled);
}

u32 AIRegisterDMACallback(u32 value) {
    u32 old = lbl_8055D774;
    BOOL enabled = OSDisableInterrupts();
    lbl_8055D774 = value;
    OSRestoreInterrupts(enabled);
    return old;
}

s32 AXRmtGetSamplesLeft(void) {
    s32 result;
    s32 samples = lbl_8055D754 - 0x24;
    if (samples < 0) {
        samples += lbl_8055D758;
    }
    result = samples - lbl_8055D750;
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

void AXRmtAdvancePtr(s32 arg0) {
    s32 end;
    end = lbl_8055D754 - 0x24;
    if (end < 0) end += lbl_8055D758;
    end -= lbl_8055D750;
    if (end < 0) end += lbl_8055D758;
    if (arg0 > end) arg0 = end;
    lbl_8055D750 += arg0;
    if (lbl_8055D750 >= lbl_8055D758) {
        lbl_8055D750 -= lbl_8055D758;
    }
}

extern u8 lbl_80363BE0[];
void *__AXGetStudio_800324C4(void) {
    return lbl_80363BE0;
}

