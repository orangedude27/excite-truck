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
    PADStatus* origin;
    u32 mask = PAD_CHAN0_BIT >> chan;

    origin = PAD_ORIGIN(chan);
    switch (lbl_80558F7C & 0x00000700u) {
    case 0x00000100u:
    case 0x00000200u:
    case 0x00000400u:
    case 0x00000700u:
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000500u:
    case 0x00000600u:
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000000u:
    case 0x00000300u:
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
    u32 data[2];
    s32 enabledChan;
    if ((status & 0xF) == 0) {
        UpdateOrigin(lbl_80558F74);
        enabledChan = lbl_80558F74;
        lbl_8055DB14 |= PAD_CHAN0_BIT >> enabledChan;
        SIGetResponse(enabledChan, data);
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
    u8* origin = (u8*)lbl_8038F080;
    u32 chanMask;
    u32 bit;
    s32 currentChan;
    u32 resetMask;
    s32 nextChan;
    BOOL ret;

    bit = 0x80000000;
    chanMask = bit >> chan;
    currentChan = lbl_80558F74;
    resetMask = lbl_8055DB0C;
    lbl_8055DB0C = resetMask & ~chanMask;
    if ((type & 8) || (type & 0xFFFF0000) != 0x09000000) {
        lbl_8055DB04 |= chanMask;
        nextChan = __cntlzw(lbl_8055DB10);
        lbl_80558F74 = nextChan;
        if (nextChan != 32) {
            lbl_8055DB10 &= ~(bit >> nextChan);
            memset(origin + nextChan * sizeof(PADStatus), 0, sizeof(PADStatus));
            SIGetTypeAsync(lbl_80558F74, fn_8005649C);
        }
    } else {
        lbl_8055DB08 |= chanMask;
        if (resetMask & chanMask) {
            nextChan = __cntlzw(lbl_8055DB10);
            lbl_80558F74 = nextChan;
            if (nextChan != 32) {
                lbl_8055DB10 &= ~(0x80000000 >> nextChan);
                memset(origin + nextChan * sizeof(PADStatus), 0, sizeof(PADStatus));
                SIGetTypeAsync(lbl_80558F74, fn_8005649C);
            }
        } else if (lbl_80558F80 < 2) {
            lbl_8055DB14 |= chanMask;
            fn_80057F2C(currentChan, lbl_80558F7C | 0x00400000);
            SIEnablePolling(lbl_8055DB14);
            nextChan = __cntlzw(lbl_8055DB10);
            lbl_80558F74 = nextChan;
            if (nextChan != 32) {
                lbl_8055DB10 &= ~(bit >> nextChan);
                memset(origin + nextChan * sizeof(PADStatus), 0, sizeof(PADStatus));
                SIGetTypeAsync(lbl_80558F74, fn_8005649C);
            }
        } else {
            switch (lbl_80558F80) {
            case 4:
                ret = SITransfer(lbl_80558F74, &lbl_80558F8C, 3, origin + lbl_80558F74 * 12, 10, (SICallback)fn_80056308, 0);
                break;
            case 3:
                ret = SITransfer(lbl_80558F74, &lbl_80558F88, 1, origin + lbl_80558F74 * 12, 10, (SICallback)fn_80056308, 0);
                break;
            case 2:
                ret = SITransfer(currentChan, &lbl_80558F88, 1, origin + currentChan * 12, 10, (SICallback)fn_80056308, 0);
                break;
            case 5:
                ret = SITransfer(currentChan, (void*)(origin + 0x40 + currentChan * 4), 3, origin + currentChan * 12, 8, (SICallback)fn_800563C8, 0);
                break;
            }
            if (!ret) {
                nextChan = __cntlzw(lbl_8055DB10);
                lbl_80558F74 = nextChan;
                lbl_8055DB00 |= chanMask;
                if (nextChan != 32) {
                    lbl_8055DB10 &= ~(0x80000000 >> nextChan);
                    memset(origin + nextChan * sizeof(PADStatus), 0, sizeof(PADStatus));
                    SIGetTypeAsync(lbl_80558F74, fn_8005649C);
                }
            }
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
    if (lbl_80558F80 == 4) {
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

BOOL fn_800569D0(void) {
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
    {
        BOOL flag = lbl_8055DB2C;
        lbl_8055DB18[0] = TRUE;
        if (flag) {
            s64 time = OSGetTime();
            *(u16*)0x800030E0 = ((time & 0xFFFF) + ((time >> 16) & 0xFFFF) + ((time >> 32) & 0xFFFF) + ((time >> 48) & 0xFFFF)) & 0x3FFF;
            lbl_8055DB0C = 0xF0000000;
        }
    }
    {
        u32 id = (*(u16*)0x800030E0 & 0x3FFF) << 8;
        lbl_8038F0C0[0] = id | 0x4D000000;
        lbl_8038F0C0[1] = id | 0x4D400000;
        lbl_8038F0C0[2] = id | 0x4D800000;
        lbl_8038F0C0[3] = id | 0x4DC00000;
    }
    SIRefreshSamplingRate();
    OSRegisterShutdownFunction(&lbl_803115D8);
    return fn_800567BC(0xF0000000);
}

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
    status->button |= ((data[0] >> 31) & 1) ? PAD_BUTTON_A : 0;
    status->button |= ((data[0] >> 30) & 1) ? PAD_BUTTON_B : 0;
    status->button |= ((data[0] >> 29) & 1) ? PAD_BUTTON_X : 0;
    status->button |= ((data[0] >> 28) & 1) ? PAD_BUTTON_Y : 0;
    status->button |= ((data[0] >> 27) & 1) ? PAD_BUTTON_START : 0;

    status->stickX = (s8)(data[0] >> 16);
    status->stickY = (s8)(data[0] >> 8);
    status->substickX = (s8)data[0];
    status->substickY = (s8)(data[1] >> 24);
    status->triggerLeft = (u8)(data[1] >> 16);
    status->triggerRight = (u8)(data[1] >> 8);
    status->analogA = (u8)data[1];
    status->analogB = (u8)(data[1] >> 4);

    if (170 <= status->triggerLeft) {
        status->button |= PAD_TRIGGER_L;
    }
    if (170 <= status->triggerRight) {
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

void fn_80056D5C(s32 chan, PADStatus* status, u32 data[2]) {
    u8* origin = (u8*)lbl_8038F080;
    u8 temp;

    status->button = (u16)(data[0] >> 16);
    status->stickX = (s8)(data[0] >> 8);
    status->stickY = (s8)data[0];

    switch (lbl_80558F7C & 0x700) {
    case 0:
    case 0x300:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)data[1];
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x100:
    case 0x200:
    case 0x400:
    case 0x700:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)data[1];
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x500:
    case 0x600:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)data[1];
        status->analogA = 0;
        status->analogB = 0;
        break;
    }

    status->stickX = ClampS8(status->stickX, *(s8*)(origin + chan * 12 + 2));
    status->stickY = ClampS8(status->stickY, *(s8*)(origin + chan * 12 + 3));
    status->substickX = ClampS8(status->substickX, *(s8*)(origin + chan * 12 + 4));
    status->substickY = ClampS8(status->substickY, *(s8*)(origin + chan * 12 + 5));
    status->triggerLeft = ClampU8(status->triggerLeft, *(origin + chan * 12 + 6));
    status->triggerRight = ClampU8(status->triggerRight, *(origin + chan * 12 + 7));
    status->analogA = ClampU8(status->analogA, *(origin + chan * 12 + 8));
    status->analogB = ClampU8(status->analogB, *(origin + chan * 12 + 9));

    temp = (u8)(data[0] >> 16);
    status->err = (s8)temp;
    if (status->err == 0) {
        s32 diff_x;
        s32 diff_y;
        if (lbl_80558F78 & (0x80000000 >> chan)) {
            diff_x = abs_diff_sqr(status->stickX, -60);
            diff_y = abs_diff_sqr(status->stickY, 0x40);
            if (diff_x + diff_y < 25) {
                status->err = -1;
                return;
            }
            diff_x = abs_diff_sqr(status->stickX, 0x40);
            diff_y = abs_diff_sqr(status->stickY, 0x40);
            if (diff_x + diff_y < 25) {
                status->err = -1;
                return;
            }
        }
    }
}

static BOOL PADSync(void) {
    return lbl_8055DB10 == 0 && lbl_80558F74 == 32;
}

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

void SamplingHandler(s16 intr, OSContext* ctx) {
    unsigned char local[0x2D8];
    (void)intr;
    if (lbl_8055DAF4 != 0) {
        OSClearContext((OSContext*)local);
        OSSetCurrentContext((OSContext*)local);
        ((void (*)(void))lbl_8055DAF4)();
        OSClearContext((OSContext*)local);
        OSSetCurrentContext(ctx);
    }
}

BOOL __PADDisableRecalibration(BOOL disable) {
    BOOL enabled = OSDisableInterrupts();
    BOOL old = (OS_PAD_FLAGS & 0x40) ? TRUE : FALSE;
    OS_PAD_FLAGS &= ~0x40;
    if (disable) {
        OS_PAD_FLAGS |= 0x40;
    }
    OSRestoreInterrupts(enabled);
    return old;
}

#pragma dont_inline on
BOOL fn_80057460(void) {
    extern long Si_80311630;
    return (unsigned long)((-1 - Si_80311630) | (Si_80311630 + 1)) >> 31;
}
#pragma dont_inline off
