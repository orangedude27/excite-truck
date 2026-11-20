#include <revolution/OS.h>
#include <revolution/PAD.h>
#include <revolution/SI.h>
#include <string.h>

#define PAD_MAX_CONTROLLER 4

#define PAD_BUTTON_A 0x0100
#define PAD_BUTTON_B 0x0200
#define PAD_BUTTON_X 0x0400
#define PAD_BUTTON_Y 0x0800
#define PAD_BUTTON_START 0x1000
#define PAD_TRIGGER_L 0x0040
#define PAD_TRIGGER_R 0x0020

#define PAD_CHAN0_BIT 0x80000000
#define PAD_CHAN1_BIT 0x40000000
#define PAD_CHAN2_BIT 0x20000000
#define PAD_CHAN3_BIT 0x10000000

/* Forward declarations */
void UpdateOrigin(s32 chan);
void fn_80056308(s32 chan, u32 status);
void fn_800563C8(s32 chan, u32 status);
void fn_8005649C(s32 chan, u32 type);
BOOL fn_800567BC(u32 mask);
BOOL fn_800568C4(u32 chanMask);
BOOL fn_800569D0(void);
void SPEC0_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
void SPEC1_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
void fn_80056D5C(s32 chan, PADStatus* status, u32 data[2]);
BOOL fn_800572DC(BOOL final, u32 event);
void SamplingHandler(s16 intr, OSContext* ctx);
BOOL __PADDisableRecalibration(BOOL disable);
BOOL fn_80057460(void);

extern void SIRefreshSamplingRate(void);
extern void fn_80057F2C(s32 chan, u32 command);
extern void fn_8005B01C(void);
extern int __cntlzw(unsigned int);
extern BOOL lbl_8055DB2C;

/* .data */
char lbl_80311590[] =
    "<< RVL_SDK - PAD \trelease build: Sep  7 2006 07:20:50 (0x4200_60422) >>";

OSShutdownFunctionInfo lbl_803115D8 = {
    fn_800572DC,
    127,
    NULL,
    NULL
};

/* .bss */
u8 lbl_8038F080[64];
u32 lbl_8038F0C0[16];

/* .sdata */
const char* lbl_80558F70 = lbl_80311590;
s32 lbl_80558F74 = 32;
u32 lbl_80558F78 = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
static u32 lbl_80558F7C = 0x00000300;
u32 lbl_80558F80 = 5;
void (*lbl_80558F84)(s32 chan, PADStatus* status, u32 data[2]) = fn_80056D5C;
char lbl_80558F88[4] = "A";
char lbl_80558F8C[4] = "B";

/* .sbss */
BOOL lbl_8055DAF0;
BOOL lbl_8055DAF4;
u32 __PADSpec;
u32 lbl_8055DAFC;
u32 lbl_8055DB00;
u32 lbl_8055DB04;
u32 lbl_8055DB08;
u32 lbl_8055DB0C;
u32 lbl_8055DB10;
u32 lbl_8055DB14;
u32 lbl_8055DB18[2];

#define PAD_ORIGIN(chan) ((PADStatus*)(lbl_8038F080 + (chan) * sizeof(PADStatus)))

void UpdateOrigin(s32 chan) {
    u32 mask = PAD_CHAN0_BIT >> chan;
    PADStatus* origin = PAD_ORIGIN(chan);

    switch (lbl_80558F7C & 0x00000700u) {
    case 0x00000000u:
    case 0x00000500u:
    case 0x00000600u:
    case 0x00000700u:
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000100u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000200u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        break;
    case 0x00000300u:
    case 0x00000400u:
        break;
    }

    origin->stickX -= 128;
    origin->stickY -= 128;
    origin->substickX -= 128;
    origin->substickY -= 128;

    if (lbl_80558F78 & mask) {
        if (origin->stickX > 64 && (SIGetType(chan) & 0xFFFF0000) == 0x09000000) {
            origin->stickX = 0;
        }
    }
}

void fn_80056308(s32 chan, u32 status) {
    /* SI transfer callback: on success, refresh PAD origin/response and enable polling, then advance probing to the next pending channel. */
    u32 response[2];
    s32 enabledChan;

    if ((status & 0xF) == 0) {
        UpdateOrigin(lbl_80558F74);
        enabledChan = lbl_80558F74;
        lbl_8055DB14 |= PAD_CHAN0_BIT >> enabledChan;
        SIGetResponse(enabledChan, response);
        fn_80057F2C(enabledChan, lbl_80558F7C | 0x00400000);
        SIEnablePolling(lbl_8055DB14);
    }
    lbl_80558F74 = __cntlzw(lbl_8055DB10);
    if (lbl_80558F74 != 32) {
        lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
        memset(&lbl_8038F080[lbl_80558F74 * 12], 0, 12);
        SIGetTypeAsync(lbl_80558F74, fn_8005649C);
    }
}

void fn_800563C8(s32 chan, u32 status) {
    u32 data[2];
    s32 runningChan;

    if ((status & 0xF) == 0) {
        runningChan = lbl_80558F74;
        lbl_8055DB14 |= PAD_CHAN0_BIT >> runningChan;
        SIGetResponse(runningChan, data);
        fn_80057F2C(runningChan, lbl_80558F7C | 0x00400000);
        SIEnablePolling(lbl_8055DB14);
        lbl_8055DB08 |= PAD_CHAN0_BIT >> lbl_80558F74;
    }
    lbl_80558F74 = __cntlzw(lbl_8055DB10);
    if (lbl_80558F74 != 32) {
        lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
        memset(PAD_ORIGIN(lbl_80558F74), 0, sizeof(PADStatus));
        SIGetTypeAsync(lbl_80558F74, fn_8005649C);
    }
}

void fn_8005649C(s32 chan, u32 type) {
    u8* origin = lbl_8038F080;
    u32 chanBit;
    u32 resetChan;
    u32 recalibrate;
    BOOL rc;
    u32 response[2];
    (void)chan;
    resetChan = lbl_80558F74;
    chanBit = PAD_CHAN0_BIT >> resetChan;
    recalibrate = lbl_8055DB0C & chanBit;
    lbl_8055DB0C &= ~chanBit;
    rc = TRUE;
    if (type & 0x0F) {
        lbl_80558F74 = __cntlzw(lbl_8055DB10);
        if (lbl_80558F74 != 32) {
            lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
            memset(origin + lbl_80558F74 * 12, 0, 12);
            SIGetTypeAsync(lbl_80558F74, fn_8005649C);
        }
        return;
    }
    type &= ~0xFF;
    ((u32*)(origin + 0x30))[resetChan] = type;
    if (((type & 0x18000000) != 0x08000000) || !(type & 0x01000000)) {
        lbl_80558F74 = __cntlzw(lbl_8055DB10);
        if (lbl_80558F74 != 32) {
            lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
            memset(origin + lbl_80558F74 * 12, 0, 12);
            SIGetTypeAsync(lbl_80558F74, fn_8005649C);
        }
        return;
    }
    if (lbl_80558F80 < 2) {
        lbl_8055DB14 |= chanBit;
        SIGetResponse(resetChan, response);
        fn_80057F2C(resetChan, lbl_80558F7C | 0x00400000);
        SIEnablePolling(lbl_8055DB14);
        lbl_80558F74 = __cntlzw(lbl_8055DB10);
        if (lbl_80558F74 != 32) {
            lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
            memset(origin + lbl_80558F74 * 12, 0, 12);
            SIGetTypeAsync(lbl_80558F74, fn_8005649C);
        }
        return;
    }
    if (!(type & 0x80000000) || (type & 0x04000000)) {
        if (recalibrate) {
            rc = SITransfer(lbl_80558F74, &lbl_80558F8C, 3, origin + lbl_80558F74 * 12, 10, fn_80056308, 0);
        } else {
            rc = SITransfer(lbl_80558F74, &lbl_80558F88, 1, origin + lbl_80558F74 * 12, 10, fn_80056308, 0);
        }
    } else if ((type & 0x00100000) && !(type & 0x00080000) && !(type & 0x00040000)) {
        if (type & 0x40000000) {
            rc = SITransfer(resetChan, &lbl_80558F88, 1, origin + resetChan * 12, 10, fn_80056308, 0);
        } else {
            rc = SITransfer(resetChan, (void*)(origin + 0x40 + resetChan * 4), 3, origin + resetChan * 12, 8, fn_800563C8, 0);
        }
    }
    if (!rc) {
        lbl_8055DB00 |= chanBit;
        lbl_80558F74 = __cntlzw(lbl_8055DB10);
        if (lbl_80558F74 != 32) {
            lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
            memset(origin + lbl_80558F74 * 12, 0, 12);
            SIGetTypeAsync(lbl_80558F74, fn_8005649C);
        }
    }
}

BOOL fn_800567BC(u32 mask) {
    u32 disable;
    BOOL enabled = OSDisableInterrupts();
    mask |= lbl_8055DB00;
    mask &= ~(lbl_8055DB08 | lbl_8055DB04);
    lbl_8055DB00 = 0;
    lbl_8055DB10 |= mask;
    disable = lbl_8055DB10 & lbl_8055DB14;
    lbl_8055DB14 &= ~mask;
    lbl_8055DAFC &= ~mask;
    if (lbl_80558F80 == 4) {
        lbl_8055DB0C |= mask;
    }
    SIDisablePolling(disable);
    if (lbl_80558F74 == 32) {
        lbl_80558F74 = __cntlzw(lbl_8055DB10);
        if (lbl_80558F74 != 32) {
            lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
            memset(PAD_ORIGIN(lbl_80558F74), 0, sizeof(PADStatus));
            SIGetTypeAsync(lbl_80558F74, fn_8005649C);
        }
    }
    OSRestoreInterrupts(enabled);
    return TRUE;
}

BOOL fn_800568C4(u32 chanMask) {
    BOOL enabled = OSDisableInterrupts();
    u32 pollingMask;

    chanMask |= lbl_8055DB00;
    lbl_8055DB00 = 0;
    chanMask &= ~(lbl_8055DB08 | lbl_8055DB04);
    lbl_8055DB10 |= chanMask;
    pollingMask = lbl_8055DB10 & lbl_8055DB14;
    lbl_8055DB14 &= ~chanMask;
    lbl_8055DAFC &= ~chanMask;
    if (((*(volatile u8*)0x800030E3) & 0x40) == 0) {
        lbl_8055DB0C |= chanMask;
    }
    SIDisablePolling(pollingMask);
    if (lbl_80558F74 == 32) {
        lbl_80558F74 = __cntlzw(lbl_8055DB10);
        if (lbl_80558F74 != 32) {
            lbl_8055DB10 &= ~(PAD_CHAN0_BIT >> lbl_80558F74);
            memset(PAD_ORIGIN(lbl_80558F74), 0, sizeof(PADStatus));
            SIGetTypeAsync(lbl_80558F74, fn_8005649C);
        }
    }
    OSRestoreInterrupts(enabled);
    return TRUE;
}

#pragma opt_propagation off
BOOL fn_800569D0(void) {
    u32 id;
    s64 time;
    if (lbl_8055DB18[0]) {
        return TRUE;
    }
    OSRegisterVersion(lbl_80558F70);
    if (__PADSpec != 0) {
        u32 spec = __PADSpec;
        __PADSpec = 0;
        switch (spec) {
        case 0:
            lbl_80558F84 = SPEC0_MakeStatus;
            break;
        case 1:
            lbl_80558F84 = SPEC1_MakeStatus;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            lbl_80558F84 = fn_80056D5C;
            break;
        }
        lbl_80558F80 = spec;
    }
    lbl_8055DB18[0] = TRUE;
    if (lbl_8055DB2C) {
        time = OSGetTime();
        *(u16*)0x800030E0 = ((time & 0xFFFF) + ((time >> 16) & 0xFFFF) + ((time >> 32) & 0xFFFF) + ((time >> 48) & 0xFFFF)) & 0x3FFF;
        lbl_8055DB0C = 0xF0000000;
    }
    id = (*(u16*)0x800030E0 & 0x3FFF) << 8;
    lbl_8038F0C0[0] = id | 0x4D000000;
    lbl_8038F0C0[1] = id | 0x4D400000;
    lbl_8038F0C0[2] = id | 0x4D800000;
    lbl_8038F0C0[3] = id | 0x4DC00000;
    SIRefreshSamplingRate();
    OSRegisterShutdownFunction(&lbl_803115D8);
    return fn_800567BC(0xF0000000);
}
#pragma opt_propagation reset
void SPEC0_MakeStatus(s32 chan, PADStatus *status, u32 data[2])
{
  (void) chan;
  status->button = 0;
  status->button |= (data[0] & 0x00080000) ? (PAD_BUTTON_A) : (0);
  status->button |= (data[0] & 0x00200000) ? (PAD_BUTTON_B) : (0);
  status->button |= (data[0] & 0x01000000) ? (PAD_BUTTON_X) : (0);
  status->button |= (data[0] & 0x00010000) ? (PAD_BUTTON_Y) : (0);
  status->button |= (data[0] & 0x00100000) ? (PAD_BUTTON_START) : (0);
  status->stickX = (s8) (data[1] >> 16);
  status->stickY = (s8) (data[1] >> 24);
  status->substickX = (s8) data[1];
  status->substickY = (s8) (data[1] >> 8);
  status->triggerLeft = (u8) (data[0] >> 8);
  status->triggerRight = (u8) data[0];
  status->analogA = 0;
  status->analogB = 0;
  if (0xAA <= status->triggerLeft)
  {
    status->button |= PAD_TRIGGER_L;
  }
  if (0xAA <= status->triggerRight)
  {
    status->button |= PAD_TRIGGER_R;
  }
  status->stickX -= 128;
  if (data)
  {
  }
  status->stickY -= 128;
  status->substickX -= 128;
  status->substickY -= 128;
}

void SPEC1_MakeStatus(s32 chan, PADStatus* status, u32 data[2]) {
    (void)chan;
    status->button = 0;
    status->button |= (data[0] & 0x00800000) ? PAD_BUTTON_A : 0;
    status->button |= (data[0] & 0x01000000) ? PAD_BUTTON_B : 0;
    status->button |= (data[0] & 0x00200000) ? PAD_BUTTON_X : 0;
    status->button |= (data[0] & 0x00100000) ? PAD_BUTTON_Y : 0;
    status->button |= (data[0] & 0x02000000) ? PAD_BUTTON_START : 0;
    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);
    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];
    status->analogA = 0;
    status->analogB = 0;
    if (0xAA <= status->triggerLeft) {
        status->button |= PAD_TRIGGER_L;
    }
    if (0xAA <= status->triggerRight) {
        status->button |= PAD_TRIGGER_R;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

static inline s8 ClampS8(s8 var, s8 org) {
    if (0 < org) {
        s8 min = (s8)(-128 + org);
        if (var < min) {
            var = min;
        }
    } else if (org < 0) {
        s8 max = (s8)(127 + org);
        if (max < var) {
            var = max;
        }
    }
    return (s8)(var - org);
}

static inline u8 ClampU8(u8 var, u8 org) {
    if (var < org) {
        return 0;
    }
    return (u8)(var - org);
}

static inline s32 abs_diff_sqr(s32 a, s32 b) {
    s32 diff = a - b;
    if (diff < 0) {
        diff = -diff;
    }
    return diff * diff;
}

static inline s32 sqabs(s32 d) {
    s32 sign = d >> 31;
    return (sign ^ d) - sign;
}

void fn_80056D5C(s32 chan, PADStatus* status, u32 data[2]) {
    u8* origin = lbl_8038F080;

    status->button = (data[0] >> 16) & 0x3fff;
    status->stickX = data[0] >> 8;
    status->stickY = data[0];

    switch (lbl_80558F7C & 0x700) {
    case 0x000:
    case 0x500:
    case 0x600:
    case 0x700:
        status->substickX = data[1] >> 24;
        status->substickY = data[1] >> 16;
        status->triggerLeft = (data[1] >> 8) & 0xf0;
        status->triggerRight = (data[1] >> 4) & 0xf0;
        status->analogA = data[1] & 0xf0;
        status->analogB = data[1] * 0x10;
        break;
    case 0x100:
        status->substickX = (data[1] >> 24) & 0xf0;
        status->substickY = (data[1] >> 20) & 0xf0;
        status->triggerLeft = data[1] >> 16;
        status->triggerRight = data[1] >> 8;
        status->analogA = data[1] & 0xf0;
        status->analogB = data[1] * 0x10;
        break;
    case 0x200:
        status->substickX = (data[1] >> 24) & 0xf0;
        status->substickY = (data[1] >> 20) & 0xf0;
        status->triggerLeft = (data[1] >> 16) & 0xf0;
        status->triggerRight = (data[1] >> 12) & 0xf0;
        status->analogA = data[1] >> 8;
        status->analogB = data[1];
        break;
    case 0x300:
        status->substickX = data[1] >> 24;
        status->substickY = data[1] >> 16;
        status->triggerLeft = data[1] >> 8;
        status->triggerRight = data[1];
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x400:
        status->substickX = data[1] >> 24;
        status->triggerLeft = 0;
        status->substickY = data[1] >> 16;
        status->triggerRight = 0;
        status->analogA = data[1] >> 8;
        status->analogB = data[1];
        break;
    }

    status->stickX -= 0x80;
    status->stickY -= 0x80;
    status->substickX -= 0x80;
    status->substickY -= 0x80;

    if ((((u32*)(origin + 0x30))[chan] & 0xffff0000) + 0xF7000000 == 0 &&
        ((status->button & 0x80) ^ 0x80) != 0) {
        lbl_8055DAFC |= 0x80000000 >> chan;
        status->stickX = 0;
        status->stickY = 0;
        status->substickX = 0;
        status->substickY = 0;
        return;
    }

    lbl_8055DAFC &= ~(0x80000000 >> chan);

    {
        s32 off = chan * 12;
        u8* base = origin + off;
        u8* prev = origin + 0x50;
        PADStatus* old = (PADStatus*)(prev + off);
        u8 org;
        u8 v;

        status->stickX = ClampS8(status->stickX, base[2]);
        status->stickY = ClampS8(status->stickY, base[3]);
        status->substickX = ClampS8(status->substickX, base[4]);
        status->substickY = ClampS8(status->substickY, base[5]);

        org = base[6];
        v = status->triggerLeft;
        if (v < org) v = org;
        status->triggerLeft = v - org;

        org = base[7];
        v = status->triggerRight;
        if (v < org) v = org;
        status->triggerRight = v - org;

        if (sqabs((s32)status->stickX * status->stickX - (s32)old->stickX * old->stickX) >= 9 ||
            sqabs((s32)status->stickY * status->stickY - (s32)old->stickY * old->stickY) >= 9 ||
            sqabs((s32)status->substickX * status->substickX - (s32)old->substickX * old->substickX) >= 9 ||
            sqabs((s32)status->substickY * status->substickY - (s32)old->substickY * old->substickY) >= 9 ||
            sqabs((s32)status->triggerLeft * status->triggerLeft - (s32)old->triggerLeft * old->triggerLeft) >= 9 ||
            sqabs((s32)status->triggerRight * status->triggerRight - (s32)old->triggerRight * old->triggerRight) >= 9 ||
            status->button != old->button) {
            fn_8005B01C();
        }
        memcpy(prev + off, status, 0xc);
    }
}

static BOOL PADSync(void) {
    return lbl_8055DB10 == 0 && lbl_80558F74 == 32;
}

/* PAD shutdown/reset handler: finalize on shutdown or report sync/reset readiness. */
BOOL fn_800572DC(BOOL final, u32 event) {
    BOOL ready;

    if (lbl_8055DAF4) {
        lbl_8055DAF4 = FALSE;
        SIUnregisterPollingHandler(SamplingHandler);
    }
    if (!final) {
        ready = FALSE;
        if (PADSync() && !fn_80057460()) {
            ready = TRUE;
        }
        if (!lbl_8055DAF0 && ready) {
            lbl_8055DAF0 = fn_800568C4(0xF0000000);
            return FALSE;
        }
        return ready;
    }
    lbl_8055DAF0 = FALSE;
    return TRUE;
}

void SamplingHandler(s16 intr, OSContext* context) {
    /* Run the registered PAD sampling callback on a temporary OS context
       during an SI polling interrupt, then restore the interrupted context. */
    unsigned char tempContext[0x2D0];
    (void)intr;
    if (lbl_8055DAF4 != 0) {
        OSClearContext((OSContext*)tempContext);
        OSSetCurrentContext((OSContext*)tempContext);
        ((void (*)(void))lbl_8055DAF4)();
        OSClearContext((OSContext*)tempContext);
        OSSetCurrentContext(context);
    }
}

/* Enables or disables PAD origin recalibration. Returns TRUE if recalibration was previously disabled. */
BOOL __PADDisableRecalibration(BOOL disable) {
    BOOL interrupts = OSDisableInterrupts();
    BOOL wasDisabled = (OS_PAD_FLAGS & 0x40) ? TRUE : FALSE;
    OS_PAD_FLAGS &= ~0x40;
    if (disable) {
        OS_PAD_FLAGS |= 0x40;
    }
    OSRestoreInterrupts(interrupts);
    return wasDisabled;
}

#pragma dont_inline on
extern SIMain Si_80311630;
/* TRUE while the SI driver has a transfer in flight: the SI context (SIBios.c's
 * Si) holds the active channel in .chan, or SI_CHAN_NONE when idle. The PAD
 * shutdown handler waits for this to be FALSE before re-polling. */
BOOL fn_80057460(void) {
    return Si_80311630.chan != SI_CHAN_NONE;
}
#pragma dont_inline off
