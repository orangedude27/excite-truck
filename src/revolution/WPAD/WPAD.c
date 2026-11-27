/*
 * WPAD source-coverage TU.
 *
 * Much of the public WPAD SDK shape is represented here, but this file also
 * contains REXE01-only anonymous helper coverage. Several helper functions are
 * intentionally FUZZY because the remaining gaps are MWCC struct-copy/inlining
 * shape rather than unknown behavior. Do not use this file as a promotion target
 * without first checking the auto-unit ownership notes in PROJECT_STATUS.md.
 */

#include <revolution/version.h>

#include <revolution/BTE.h>
#include <revolution/IPC.h>
#include <revolution/OS.h>
#include <revolution/SC.h>
#include <revolution/WPAD.h>
#include <revolution/WUD.h>
#include <revolution/WPAD/WPADHIDParser.h>

#include <string.h>
#include "revolution/WPAD/WPAD.h"
#include "revolution/WPAD/WPADInternal.h"


extern void DBPrintf_80068D68(const char* pFmt, ...);
extern const char lbl_80312164[], lbl_8031219C[], lbl_80558FE4[];
extern volatile u16 lbl_80560CC8, lbl_80560CCA, lbl_80560CCC, lbl_80560CCE;
extern volatile u16 lbl_80560CD0, lbl_80560CD2, lbl_80560CD4, lbl_80560CD6;
extern u8 lbl_803928E8[];
extern const u8 lbl_803123B8[];
extern const char lbl_803122A0[];
extern const char lbl_803122BC[];
extern const char lbl_803122D8[];
extern const char lbl_80312648[];
extern const char lbl_80312654[];
extern WPADCB* lbl_8038F4F0[WPAD_MAX_CONTROLLERS];
extern const u8 lbl_803127C8[];
extern const u8 lbl_80312798[];
extern u8 lbl_8055DC28;
extern u8 lbl_8055DC29;
extern u8 lbl_8055DC2A;
extern u8 lbl_8055DC2B;
extern void* lbl_8055DC14;
extern u8 lbl_8055DC08[WPAD_MAX_CONTROLLERS];
extern u8 lbl_8055DC11;
extern u8 lbl_8055DC1A;
extern u8 lbl_80392900[];
extern u8 lbl_8055DBF8;
extern OSShutdownFunctionInfo lbl_80312130;
extern u16 lbl_8055DBFA;
extern u8 lbl_8055DBFC;
extern u8 lbl_8055DBFD;
extern u16 lbl_8055DBFE;
extern u8 lbl_8055DC00[WPAD_MAX_CONTROLLERS];
extern s8 lbl_8055DC04;
extern u8 lbl_8055DC06;
extern const char* lbl_8055DC0C;
extern u8 lbl_8055DC10;
extern u8 lbl_8055DC18;
extern const char* lbl_80558FD8;
extern u8 lbl_8055DC12;
extern u8 lbl_8055DC19;
extern const char lbl_80312140[];
extern const char lbl_80312158[];

// BTA_HhClose from BTE
extern void BTA_HhClose(u8 devHandle);

// fn_8005B00C
extern s32 fn_8005B00C(void);
extern s32 fn_8006A940(void);
extern void fn_800684D0(s32 chan);

// Helper function declarations for fn_8005E09C
static BOOL IsControllerDataChanged(WPADCB* p, void* pLhs, void* pRhs);
BOOL fn_80063564(WPADCommandQueue* pQueue, s32 format, WPADCallback pCallback);
extern void (*lbl_80312338[])(u8 port, u8* p_rpt);
void fn_80060AFC(s32 chan);
#define WPAD_DECODE_LEN_T u16
void WPADiDecode(s32 chan, u8* data, WPAD_DECODE_LEN_T len, s32 seed);
typedef struct { f64 d[6]; } Cmd64;
typedef struct {
    Cmd64 rmb;
    Cmd64 rmbCopy;
    Cmd64 std;
    Cmd64 stdCopy;
    Cmd64 ext;
    Cmd64 extCopy;
} WPADManageFrame;
void WPADiSendOutputReport(s32 chan, WPADGameInfo *info);
s32 WPADiSendGameInfoReport(s32 chan, WPADGameInfo* pInfo);

typedef struct WPADCB_8011_View {
    u8 _unk0[0x7F8];
    u32 dataFormat;
    u8 _unk7FC[6];
    u8 devMode;
    u8 _unk803[0x35];
    u16 filterDiffDpd;
    u16 filterSameDpd;
    u16 filterDiffAcc;
    u16 filterSameAcc;
    u16 filterDiffExt;
    u16 filterSameExt;
} WPADCB_8011_View;

// debug_msg.c is NonMatching, provide stub here
void DEBUGPrint(const char* pFmt, ...) {
#pragma unused(pFmt)
}

#define DPD_CONFIG1_SIZE 9
#define DPD_CONFIG2_SIZE 2
#define SPK_CONFIG_SIZE 7

RVL_LIB_VERSION(WPAD, "May 17 2007", "01:52:03", "0x4199_60831");

OSAlarm _managerAlarm = {0};
WPADCB* _wpdcb[WPAD_MAX_CONTROLLERS] = {0};
u8 __WPADiManageHandlerStack[0x1000] ALIGN(32) = {0};
s8 _dev_handle_index[WUD_MAX_DEV_ENTRY] = {0};
u8 FAKE_ALIGNMENT[0x10] = {0};
WPADCB _wpd[WPAD_MAX_CONTROLLERS] = {0};

u8 _sleepTime;
u8 _dpdSensitivity;
u8 _sensorBarPos;
u32 _rumble;
u8 _speakerVolume;
u8 _scFlush;
u8 _gametype;
const char* _gamecode;
u8 _chan_active_state[WPAD_MAX_CONTROLLERS];

static u8 _scSetting;
static u8 _shutdown;
static s8 _afhChannel;
static BOOL _initialized;
static u8 _rumbleCnt[WPAD_MAX_CONTROLLERS];
static u8 _extCnt[WPAD_MAX_CONTROLLERS];
static u16 _afhCnt;
static u8 _checkCnt;
static u16 _senseCnt;
static u8 _regShutdown;

static u16 __WPAD_acc_diff_count_threshold = 6;
static u16 __WPAD_dpd_diff_count_threshold = 4;
static u16 __WPAD_acc_hyst_count_threshold = 30;
static u16 __WPAD_dpd_hyst_count_threshold = 30;

static void WPADiConnCallback(UINT8 devHandle, u8 open);
static void WPADiRecvCallback(UINT8 devHandle, UINT8* pReport, UINT16 len);

static DECOMP_INLINE void WPADiDisconnect(s32 chan, BOOL sleep);
static void __SendData(s32 chan, WPADCommand command);

BOOL __CanPushCmdQueue(const WPADCommandQueue* pQueue, s8 num);
s8 __GetCmdNumber(const WPADCommandQueue* pQueue);

static void __SetScreenSaverFlag(BOOL disable);
static u8 __GetDpdSensitivity(void);
static u8 __GetSensorBarPosition(void);
static u32 __GetMotorMode(void);
static u8 __ClampSpeakerVolume(u8 volume);
static u8 __GetSpeakerVolume(void);

u16 _WPADGetStackBufferStatus(s32 chan);
u16 _WPADGetModuleBufferStatus(s32 chan);

static void* noAlloc(u32 size) {
#pragma unused(size)

    DEBUGPrint("No Alloc: Nothing to do!!!\n");
    return NULL;
}

static BOOL noFree(void* pBlock) {
#pragma unused(pBlock)

    DEBUGPrint("No Free: Nothing to do!!!\n");
    return FALSE;
}

static BOOL OnShutdown(BOOL final, u32 event) {
    BOOL result = FALSE;
    WUDLibStatus status = WUDGetStatus();

    if (!final) {
        if (status == WUD_LIB_STATUS_3) {
            switch (event) {
            case OS_SD_EVENT_FATAL: {
                DEBUGPrint("Deregister allocators because of fatal error.\n");
                WPADRegisterAllocator(&noAlloc, &noFree);

                // FALLTHROUGH
            }

            case OS_SD_EVENT_SHUTDOWN:
            case OS_SD_EVENT_3: {
                __WPADShutdown();
                result = FALSE;
                break;
            }

            case OS_SD_EVENT_1:
            case OS_SD_EVENT_RESTART:
            case OS_SD_EVENT_RETURN_TO_MENU:
            case OS_SD_EVENT_LAUNCH_APP: {
                __WPADReconnect();
                result = FALSE;
                break;
            }
            }

        } else if (status == WUD_LIB_STATUS_5) {
            WPADStopSimpleSync();
            result = FALSE;

        } else if (status == WUD_LIB_STATUS_4 || status == WUD_LIB_STATUS_1 ||
                   status == WUD_LIB_STATUS_2) {
            result = FALSE;

        } else if (status == WUD_LIB_STATUS_0) {
            result = TRUE;
        }
    } else {
        result = TRUE;
    }

_end:
    return result;
}

static OSShutdownFunctionInfo ShutdownFunctionInfo = {OnShutdown, 127};

static s32 WPADiSendData(s32 chan, WPADCommand command) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled;
    s32 status;
    u8 statusReqBusy;

    enabled = OSDisableInterrupts();
    status = p->status;
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_OK) {
        enabled = OSDisableInterrupts();
        statusReqBusy = p->statusReqBusy;
        OSRestoreInterrupts(enabled);

        if (statusReqBusy) {
            status = WPAD_ERR_COMMUNICATION_ERROR;
        } else {
            __SendData(chan, command);
        }
    } else if (status != WPAD_ERR_COMMUNICATION_ERROR &&
               status == WPAD_ERR_TRANSFER) {

        enabled = OSDisableInterrupts();
        p->status = WPAD_ERR_OK;
        OSRestoreInterrupts(enabled);
    }

    if (status == WPAD_ERR_COMMUNICATION_ERROR) {
        // clang-format off
        if ((s32)OS_TICKS_TO_SEC(__OSGetSystemTime() - p->lastReportSendTime) > 1 &&
            _sleepTime != 0)
        // clang-format on
        {
            if (!p->UNK_0x910) {
                p->lastReportSendTime = __OSGetSystemTime();
                WPADiDisconnect(chan, FALSE);
            } else {
                enabled = OSDisableInterrupts();
                p->status = WPAD_ERR_TRANSFER;
                OSRestoreInterrupts(enabled);
            }
        }
    }

    return status;
}

static void WPADiRadioSensitivity(s32 chan) {
    WPADCB *p = lbl_8038F4F0[chan];
    u8 *q = (u8 *)p;
    u32 two = 2;
    u16 a;

    // Calculate radio sensitivity value
    a = *(u8 *)(q + 0x8c3) * 9;
    a += (u16)(*(u16 *)(q + 0x8c4) * 100 / two);
    a /= 10;
    a = MIN(100, a);

    *(u8 *)(q + 0x8c3) = a;
    *(u16 *)(q + 0x8c4) = 0;

    if (*(u8 *)(q + 0x80c) != 0) {
        if (a > 85) {
            *(u8 *)(q + 0x80c) = 0;
            *(u8 *)(q + 0x80d) = 0;
        } else if (a > 80) {
            (*(u8 *)(q + 0x80d))++;

            if (*(u8 *)(q + 0x80d) >= 20) {
                *(u8 *)(q + 0x80c) = 0;
                *(u8 *)(q + 0x80d) = 0;
            }
        }
    } else if (a < 75) {
        *(u8 *)(q + 0x80c) = 1;
        *(u8 *)(q + 0x80d) = 0;
    } else if (a < 80) {
        (*(u8 *)(q + 0x80d))++;

        if (*(u8 *)(q + 0x80d) >= 1) {
            *(u8 *)(q + 0x80c) = 1;
            *(u8 *)(q + 0x80d) = 0;
        }
    }
}

static u8 IsButtonChanged(u16 lhs, u16 rhs) {
    return lhs != rhs ? TRUE : FALSE;
}

static u8 IsAnalogChanged(s32 lhs, s32 rhs, s32 threshold) {
    s32 diff = lhs - rhs < 0 ? rhs - lhs : lhs - rhs;
    return diff > threshold ? TRUE : FALSE;
}

#pragma push
#pragma use_lmw_stmw on
static BOOL IsControllerDataChanged(WPADCB* p, void* pLhs, void* pRhs) {
#define WPAD_BUTTON_CHANGED(lhs, rhs) ((lhs) != (rhs))
#define WPAD_ANALOG_CHANGED(lhs, rhs, threshold) \
    ((analogDiff = ((lhs) - (rhs) < 0 ? (rhs) - (lhs) : (lhs) - (rhs))), \
     (analogMask = analogDiff ^ (threshold)), \
     (analogResult = analogMask >> 1), \
     (analogMask &= analogDiff), \
     (analogMask = analogResult - analogMask), \
     ((u32)analogMask >> 31))
    WPADCB_8011_View* q = (WPADCB_8011_View*)p;
    WPADStatus* pLhsCR = (WPADStatus*)pLhs;
    WPADStatus* pRhsCR = (WPADStatus*)pRhs;
    u8 devMode = q->devMode;
    u8 changed;
    BOOL analogChanged;
    int i;
    register s32 analogDiff;
    register s32 analogMask;
    register s32 analogResult;

#define CALC_ANALOG_NOISE_ACC(CHANGED)                                         \
    if (CHANGED) {                                                             \
        q->filterDiffAcc++;                                                    \
                                                                               \
        if (q->filterDiffAcc > __WPAD_acc_diff_count_threshold) {              \
            q->filterDiffAcc = 0;                                              \
            q->filterSameAcc = 0;                                              \
            changed |= TRUE;                                                   \
        }                                                                      \
                                                                               \
    } else {                                                                   \
        q->filterSameAcc =                                                     \
            (q->filterSameAcc + 1) % __WPAD_acc_hyst_count_threshold;          \
                                                                               \
        if (q->filterSameAcc == __WPAD_acc_hyst_count_threshold - 1 &&         \
            q->filterDiffAcc > 0) {                                            \
                                                                               \
            q->filterDiffAcc--;                                                \
        }                                                                      \
    }

#define CALC_ANALOG_NOISE_DPD(CHANGED)                                         \
    if (CHANGED) {                                                             \
        q->filterDiffDpd++;                                                    \
                                                                               \
        if (q->filterDiffDpd > __WPAD_dpd_diff_count_threshold) {              \
            q->filterDiffDpd = 0;                                              \
            changed |= TRUE;                                                   \
        }                                                                      \
                                                                               \
    } else {                                                                   \
        q->filterSameDpd =                                                     \
            (q->filterSameDpd + 1) % __WPAD_dpd_hyst_count_threshold;          \
                                                                               \
        if (q->filterSameDpd == __WPAD_dpd_hyst_count_threshold - 1 &&         \
            q->filterDiffDpd > 0) {                                            \
                                                                               \
            q->filterDiffDpd--;                                                \
        }                                                                      \
    }

#define CALC_ANALOG_NOISE_EXT(CHANGED)                                         \
    if (CHANGED) {                                                             \
        q->filterDiffExt++;                                                    \
                                                                               \
        if (q->filterDiffExt > __WPAD_acc_diff_count_threshold) {              \
            q->filterDiffExt = 0;                                              \
            q->filterSameExt = 0;                                              \
            changed |= TRUE;                                                   \
        }                                                                      \
                                                                               \
    } else {                                                                   \
        q->filterSameExt =                                                     \
            (q->filterSameExt + 1) % __WPAD_acc_hyst_count_threshold;          \
                                                                               \
        if (q->filterSameExt == __WPAD_acc_hyst_count_threshold - 1 &&         \
            q->filterDiffExt > 0) {                                            \
                                                                               \
            q->filterDiffExt--;                                                \
        }                                                                      \
    }

    if (q->dataFormat == WPAD_FMT_CORE_BTN ||
        q->dataFormat == WPAD_FMT_CORE_BTN_ACC ||
        q->dataFormat == WPAD_FMT_CORE_BTN_ACC_DPD) {

        changed = WPAD_BUTTON_CHANGED(pLhsCR->button, pRhsCR->button);

        if (pLhsCR->err == WPAD_ERR_OK && pRhsCR->err == WPAD_ERR_OK) {
                        analogChanged = WPAD_ANALOG_CHANGED(pLhsCR->accY, pRhsCR->accY, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCR->accX, pRhsCR->accX, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCR->accZ, pRhsCR->accZ, 12);
            CALC_ANALOG_NOISE_ACC(analogChanged);;

            for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                            analogChanged = WPAD_ANALOG_CHANGED(pLhsCR->obj[i].y, pRhsCR->obj[i].y, 2);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCR->obj[i].x, pRhsCR->obj[i].x, 2);
            CALC_ANALOG_NOISE_DPD(analogChanged);;
            }
        }
    } else if (q->dataFormat == WPAD_FMT_FS_BTN ||
               q->dataFormat == WPAD_FMT_FS_BTN_ACC ||
               q->dataFormat == WPAD_FMT_FS_BTN_ACC_DPD) {

        WPADFSStatus* pLhsFS = (WPADFSStatus*)pLhs;
        WPADFSStatus* pRhsFS = (WPADFSStatus*)pRhs;

        changed = WPAD_BUTTON_CHANGED(pLhsFS->button, pRhsFS->button);

        if (pLhsFS->err == WPAD_ERR_OK && pRhsFS->err == WPAD_ERR_OK) {
                        analogChanged = WPAD_ANALOG_CHANGED(pLhsFS->accY, pRhsFS->accY, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsFS->accX, pRhsFS->accX, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsFS->accZ, pRhsFS->accZ, 12);
            CALC_ANALOG_NOISE_ACC(analogChanged);;

            for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                            analogChanged = WPAD_ANALOG_CHANGED(pLhsFS->obj[i].y, pRhsFS->obj[i].y, 2);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsFS->obj[i].x, pRhsFS->obj[i].x, 2);
            CALC_ANALOG_NOISE_DPD(analogChanged);;
            }

                        analogChanged = WPAD_ANALOG_CHANGED(pLhsFS->fsAccY, pRhsFS->fsAccY, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsFS->fsAccX, pRhsFS->fsAccX, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsFS->fsAccZ, pRhsFS->fsAccZ, 12);
            CALC_ANALOG_NOISE_EXT(analogChanged);;

            changed |= WPAD_ANALOG_CHANGED(pLhsFS->fsStickX, pRhsFS->fsStickX, 1);
            changed |= WPAD_ANALOG_CHANGED(pLhsFS->fsStickY, pRhsFS->fsStickY, 1);
        }
    } else {
        if (q->dataFormat == WPAD_FMT_CLASSIC_BTN ||
            q->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC ||
            q->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {

            WPADCLStatus* pLhsCL = (WPADCLStatus*)pLhs;
            WPADCLStatus* pRhsCL = (WPADCLStatus*)pRhs;

            s32 leftStickDiv;
            s32 rightStickDiv;
            s32 triggerDiv;
            switch (devMode) {
            case WPAD_DEV_MODE_CLASSIC_REDUCED: {
                leftStickDiv = 16;
                rightStickDiv = 32;
                triggerDiv = 8;
                break;
            }

            case WPAD_DEV_MODE_CLASSIC_STANDARD: {
                leftStickDiv = 4;
                rightStickDiv = 4;
                triggerDiv = 1;
                break;
            }

            default: {
                leftStickDiv = 1;
                rightStickDiv = 1;
                triggerDiv = 1;
                break;
            }
            }

            changed = WPAD_BUTTON_CHANGED(pLhsCL->button, pRhsCL->button);

            if (pLhsCL->err == WPAD_ERR_OK && pRhsCL->err == WPAD_ERR_OK) {
                            analogChanged = WPAD_ANALOG_CHANGED(pLhsCL->accY, pRhsCL->accY, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCL->accX, pRhsCL->accX, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCL->accZ, pRhsCL->accZ, 12);
            CALC_ANALOG_NOISE_ACC(analogChanged);;

                for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                                analogChanged = WPAD_ANALOG_CHANGED(pLhsCL->obj[i].y, pRhsCL->obj[i].y, 2);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCL->obj[i].x, pRhsCL->obj[i].x, 2);
            CALC_ANALOG_NOISE_DPD(analogChanged);;
                }

                changed |= WPAD_BUTTON_CHANGED(pLhsCL->clButton, pRhsCL->clButton);

                changed |= WPAD_ANALOG_CHANGED(pLhsCL->clLStickX / leftStickDiv,
                                           pRhsCL->clLStickX / leftStickDiv, 1);
                changed |= WPAD_ANALOG_CHANGED(pLhsCL->clLStickY / leftStickDiv,
                                           pRhsCL->clLStickY / leftStickDiv, 1);

                changed |=
                    WPAD_ANALOG_CHANGED(pLhsCL->clRStickX / rightStickDiv,
                                    pRhsCL->clRStickX / rightStickDiv, 1);
                changed |=
                    WPAD_ANALOG_CHANGED(pLhsCL->clRStickY / rightStickDiv,
                                    pRhsCL->clRStickY / rightStickDiv, 1);

                changed |= WPAD_ANALOG_CHANGED(pLhsCL->clTriggerL / triggerDiv,
                                           pRhsCL->clTriggerL / triggerDiv, 1);
                changed |= WPAD_ANALOG_CHANGED(pLhsCL->clTriggerR / triggerDiv,
                                           pRhsCL->clTriggerR / triggerDiv, 1);
            }

        } else {
            changed = WPAD_BUTTON_CHANGED(pLhsCR->button, pRhsCR->button);

            if (pLhsCR->err == WPAD_ERR_OK && pRhsCR->err == WPAD_ERR_OK) {
                            analogChanged = WPAD_ANALOG_CHANGED(pLhsCR->accY, pRhsCR->accY, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCR->accX, pRhsCR->accX, 12);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCR->accZ, pRhsCR->accZ, 12);
            CALC_ANALOG_NOISE_ACC(analogChanged);;

                for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                                analogChanged = WPAD_ANALOG_CHANGED(pLhsCR->obj[i].y, pRhsCR->obj[i].y, 2);
            analogChanged |= WPAD_ANALOG_CHANGED(pLhsCR->obj[i].x, pRhsCR->obj[i].x, 2);
            CALC_ANALOG_NOISE_DPD(analogChanged);;
                }
            }
        }
    }

    return changed;

#undef CALC_ANALOG_NOISE_EXT
#undef CALC_ANALOG_NOISE_ACC
#undef CALC_ANALOG_NOISE_DPD
#undef WPAD_BUTTON_CHANGED
#undef WPAD_ANALOG_CHANGED
}
#pragma pop
void fn_8005E09C(s32 port)
{
  u8 *new_var;
  s32 enabled;
  s32 flag;
  WPADCB *p;
  s32 idx;
  WPADCB *p2;
  WPADCB **cbs;
  s32 changed;
  s32 offset;
  s32 devHandle;
  s64 currentTime;
  s64 lastTime;
  s32 timeDiff;
  s32 timeout;
  s32 irq;
  u8 *rx;
  cbs = lbl_8038F4F0;
  idx = port * 4;
  flag = 0;
  p = lbl_8038F4F0[port];
  if (p->readStatus == (-1))
  {
    goto _end;
  }
  enabled = OSDisableInterrupts();
  offset = ((u8) (p->rxBufSel == 0)) * 0x60;
  changed = IsControllerDataChanged(p, (void *) ((((u8 *) p) + 0xA0) + offset), (void *) p->rxBufMain);
  if (changed != 0)
  {
    memcpy(p->rxBufMain, (void *) ((((u8 *) p) + 0xA0) + offset), 0x60);
  }
  if ((*((s8 *) (((u8 *) p) + 0x69))) != 0)
  {
    memset(p->rxBufMain, 0, 0x60);
  }
  OSRestoreInterrupts(enabled);
  p2 = lbl_8038F4F0[port];
  enabled = 0;
  irq = OSDisableInterrupts();
  offset = ((u8) (p2->rxBufSel == 0)) * 0x60;
  new_var = (u8 *) p2;
  rx = new_var + offset;
  if ((*((u16 *) (rx + 0xA0))) == 0x1C10)
  {
    enabled = 1;
  }
  if (((p2->readFormat - 6) <= 2) && ((*((u16 *) (rx + 0xCA))) == 0x1450))
  {
    enabled = 1;
  }
  *((u16 *) (new_var + 0x852)) = enabled ? (*((u16 *) (new_var + 0x852)) + 1) : 0;
  OSRestoreInterrupts(irq);
  if ((*((u16 *) (new_var + 0x852))) > 600)
  {
    p2 = lbl_8038F4F0[port];
    irq = OSDisableInterrupts();
    *((u8 *) (((u8 *) p2) + 0x851)) = 0;
    OSRestoreInterrupts(irq);
  }
  if (changed != 0)
  {
    flag = 1;
    currentTime = __OSGetSystemTime();
    *((s64 *) (((u8 *) p) + 0x830)) = currentTime;
  }
  else
    if (lbl_8055DC1A != 0)
  {
    currentTime = __OSGetSystemTime();
    lastTime = *((s64 *) (((u8 *) p) + 0x830));
    timeDiff = OS_TICKS_TO_SEC(currentTime - lastTime);
    timeout = lbl_8055DC1A * 60;
    if (timeDiff > timeout)
    {
      p = lbl_8038F4F0[port];
      irq = OSDisableInterrupts();
      devHandle = p->readStatus;
      OSRestoreInterrupts(irq);
      if (devHandle != (-1))
      {
        irq = OSDisableInterrupts();
        if ((*((u8 *) (((u8 *) p) + 0x8C6))) != 0)
        {
          OSRestoreInterrupts(irq);
        }
        else
        {
          *((u8 *) (((u8 *) p) + 0x8C6)) = 1;
          OSRestoreInterrupts(irq);
          BTA_HhClose(*((u8 *) (((u8 *) p) + 0x803)));
        }
      }
    }
  }
  if (flag != 0)
  {
    fn_8005B00C();
  }
  _end:
  ;

  ;
}

void fn_8005E298(void) {
    WPADManageFrame frame;
    register WPADCB **var_r28 asm("r28");
    register u8 *var_r27 asm("r27");
    register s32 var_r26 asm("r26");
    register s32 var_r25 asm("r25");
    register s8 var_r29 asm("r29");
    register s8 var_r22 asm("r22");
    register WPADCB *temp_r30 asm("r30");
    register s32 zero asm("r31") = 0;
    register s32 sixteen asm("r23") = 0x10;
    register s32 one asm("r24") = 1;
    s32 temp_r25;
    s32 temp_r25_2;
    s32 temp_r30_2;
    s32 temp_r30_3;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_state2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s8 var_r22_2;
    s8 var_r22_3;
    s8 var_r29_2;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 var_r0_5;
    u8 var_r3;
    WPADCB *temp_r29;
    WPADCB *temp_r29_2;
    WPADCB *temp_r5_3;

    if (fn_8006A940() == 3) {
        var_r26 = 0;
        var_r28 = lbl_8038F4F0;
        var_r27 = lbl_8055DC00;
        do {
            var_r25 = 0;
            if ((u8) lbl_8055DBFD == 5) {
                temp_r30 = *var_r28;
                if ((*(s32*)((u8*)temp_r30 + 0x818) != 0) && (*(s32*)((u8*)temp_r30 + 0x780) != 0)) {
                    temp_r25 = OSDisableInterrupts();
                    temp_state2 = OSDisableInterrupts();
                    var_r29 = *(u8*)((u8*)temp_r30 + 0x5ED) - *(u8*)((u8*)temp_r30 + 0x5EC);
                    if (var_r29 < 0) {
                        var_r29 += *(s32*)((u8*)temp_r30 + 0x5F4);
                    }
                    OSRestoreInterrupts(temp_state2);
                    if (var_r29 == 0) {
                        OSRestoreInterrupts(temp_r25);
                        var_r0 = 0;
                    } else {
                        memcpy(&frame.ext, (void *)(*(s32*)((u8*)temp_r30 + 0x5F0) + ((s8)*(u8*)((u8*)temp_r30 + 0x5EC) * 0x30)), 0x30);
                        OSRestoreInterrupts(temp_r25);
                        var_r0 = 1;
                    }
                    if (var_r0 != 0) {
                        frame.extCopy.d[0] = frame.ext.d[0];
                        frame.extCopy.d[1] = frame.ext.d[1];
                        frame.extCopy.d[2] = frame.ext.d[2];
                        frame.extCopy.d[3] = frame.ext.d[3];
                        frame.extCopy.d[4] = frame.ext.d[4];
                        frame.extCopy.d[5] = frame.ext.d[5];
                        if (WPADiSendGameInfoReport(var_r26, (WPADGameInfo*)&frame.extCopy) == 0) {
                            temp_r25_2 = OSDisableInterrupts();
                            temp_state2 = OSDisableInterrupts();
                            var_r29_2 = *(u8*)((u8*)temp_r30 + 0x5ED) - *(u8*)((u8*)temp_r30 + 0x5EC);
                            if (var_r29_2 < 0) {
                                var_r29_2 += *(s32*)((u8*)temp_r30 + 0x5F4);
                            }
                            OSRestoreInterrupts(temp_state2);
                            if (var_r29_2 == 0) {
                                OSRestoreInterrupts(temp_r25_2);
                            } else {
                                memset((void *)(*(s32*)((u8*)temp_r30 + 0x5F0) + ((s8)*(u8*)((u8*)temp_r30 + 0x5EC) * 0x30)), 0, 0x30);
                                temp_r0 = *(u8*)((u8*)temp_r30 + 0x5EC);
                                temp_r4 = *(s32*)((u8*)temp_r30 + 0x5F4) - 1;
                                temp_r5 = (s8) temp_r0 - temp_r4;
                                temp_r4_2 = (s32) ~(temp_r5 | (temp_r4 - (s8) temp_r0)) >> 0x1F;
                                *(u8*)((u8*)temp_r30 + 0x5EC) = (u8) (((s8) temp_r0 + 1) & ~temp_r4_2);
                                OSRestoreInterrupts(temp_r25_2);
                            }
                            var_r25 = 1;
                        } else {
                            goto block_18;
                        }
                    } else {
                        goto block_18;
                    }
                } else {
block_18:
                    var_r25 = 0;
                }
            }
            temp_r29 = *var_r28;
            if (*(s32*)((u8*)temp_r29 + 0x818) != 0) {
                temp_r30_2 = OSDisableInterrupts();
                temp_state2 = OSDisableInterrupts();
                var_r22 = *(u8*)((u8*)temp_r29 + 0x161) - *(u8*)((u8*)temp_r29 + 0x160);
                if (var_r22 < 0) {
                    var_r22 += *(s32*)((u8*)temp_r29 + 0x168);
                }
                OSRestoreInterrupts(temp_state2);
                if (var_r22 == 0) {
                    OSRestoreInterrupts(temp_r30_2);
                    var_r0_2 = 0;
                } else {
                    memcpy(&frame.std, (void *)(*(s32*)((u8*)temp_r29 + 0x164) + ((s8)*(u8*)((u8*)temp_r29 + 0x160) * 0x30)), 0x30);
                    OSRestoreInterrupts(temp_r30_2);
                    var_r0_2 = 1;
                }
                if (var_r0_2 != 0) {
                    frame.stdCopy.d[0] = frame.std.d[0];
                    frame.stdCopy.d[1] = frame.std.d[1];
                    frame.stdCopy.d[2] = frame.std.d[2];
                    frame.stdCopy.d[3] = frame.std.d[3];
                    frame.stdCopy.d[4] = frame.std.d[4];
                    frame.stdCopy.d[5] = frame.std.d[5];
                    if (WPADiSendGameInfoReport(var_r26, (WPADGameInfo*)&frame.stdCopy) == 0) {
                        temp_r30_3 = OSDisableInterrupts();
                        temp_state2 = OSDisableInterrupts();
                        var_r22_2 = *(u8*)((u8*)temp_r29 + 0x161) - *(u8*)((u8*)temp_r29 + 0x160);
                        if (var_r22_2 < 0) {
                            var_r22_2 += *(s32*)((u8*)temp_r29 + 0x168);
                        }
                        OSRestoreInterrupts(temp_state2);
                        if (var_r22_2 == 0) {
                            OSRestoreInterrupts(temp_r30_3);
                        } else {
                            memset((void *)(*(s32*)((u8*)temp_r29 + 0x164) + ((s8)*(u8*)((u8*)temp_r29 + 0x160) * 0x30)), 0, 0x30);
                            temp_r0_2 = *(u8*)((u8*)temp_r29 + 0x160);
                            temp_r4_3 = *(s32*)((u8*)temp_r29 + 0x168) - 1;
                            temp_r5_2 = (s8) temp_r0_2 - temp_r4_3;
                            temp_r4_4 = (s32) ~(temp_r5_2 | (temp_r4_3 - (s8) temp_r0_2)) >> 0x1F;
                            *(u8*)((u8*)temp_r29 + 0x160) = (u8) (((s8) temp_r0_2 + 1) & ~temp_r4_4);
                            OSRestoreInterrupts(temp_r30_3);
                        }
                        var_r0_3 = 1;
                    } else {
                        goto block_33;
                    }
                } else {
                    goto block_33;
                }
            } else {
block_33:
                var_r0_3 = 0;
            }
            var_r25 |= var_r0_3;
            temp_r29_2 = *var_r28;
            if (*(s32*)((u8*)temp_r29_2 + 0x7FC) != -1) {
                if (var_r25 != 1) {
                    temp_state2 = OSDisableInterrupts();
                    var_r22_3 = *(u8*)((u8*)temp_r29_2 + 0x161) - *(u8*)((u8*)temp_r29_2 + 0x160);
                    if (var_r22_3 < 0) {
                        var_r22_3 += *(s32*)((u8*)temp_r29_2 + 0x168);
                    }
                    OSRestoreInterrupts(temp_state2);
                    if (var_r22_3 > 0) {
                        *(s32*)((u8*)*var_r28 + 0x810) = zero;
                        goto block_done;
                    }
                }
                if (*var_r27 == 5) {
                    *(u16*)((u8*)&frame.rmb + 0x1A) = one;
                    temp_r5_3 = *var_r28;
                    *(void**)((u8*)&frame.rmb + 0x2C) = (void *)zero;
                    *(s32*)((u8*)temp_r5_3 + 0x810) = zero;
                    *(u32*)&frame.rmb = sixteen;
                    *(u8*)((u8*)&frame.rmb + 4) = zero;
                    frame.rmbCopy.d[0] = frame.rmb.d[0];
                    frame.rmbCopy.d[1] = frame.rmb.d[1];
                    frame.rmbCopy.d[2] = frame.rmb.d[2];
                    frame.rmbCopy.d[3] = frame.rmb.d[3];
                    frame.rmbCopy.d[4] = frame.rmb.d[4];
                    frame.rmbCopy.d[5] = frame.rmb.d[5];
                    WPADiSendOutputReport(var_r26, (WPADGameInfo*)&frame.rmbCopy);
                }
block_done:
                if (*(s32*)((u8*)*var_r28 + 0x810) != 0) {
                    var_r0_4 = *var_r27 + 1;
                } else {
                    var_r0_4 = 0;
                }
                *var_r27 = var_r0_4;
            }
            if ((u8) lbl_8055DBFC == 5) {
                fn_8005E09C(var_r26);
            }
            if ((u16) lbl_8055DBFA == 0xA) {
                WPADiRadioSensitivity(var_r26);
            }
            var_r26 += 1;
            var_r27 += 1;
            var_r28 += 1;
        } while (var_r26 < 4);
        if (lbl_8055DBFE == 60000) {
            DCInvalidateRange((void *)0x800031A2, 1);
            DBPrintf_80068D68(lbl_80312140, *(u8 *)0x800031A2);
            if ((s8) lbl_8055DC04 != (s32) *(u8 *)0x800031A2) {
                temp_state2 = OSDisableInterrupts();
                lbl_8055DC04 = *(u8 *)0x800031A2;
                OSRestoreInterrupts(temp_state2);
                WUDSetDisableChannel((s8) lbl_8055DC04);
            }
        }
        lbl_8055DBFA = (lbl_8055DBFA + 1) & ~((s32) ~((lbl_8055DBFA - 0xA) | (0xA - lbl_8055DBFA)) >> 0x1F);
        lbl_8055DBFC = (lbl_8055DBFC + 1) & ~((s32) ~((lbl_8055DBFC - 5) | (5 - lbl_8055DBFC)) >> 0x1F);
        lbl_8055DBFD = (lbl_8055DBFD + 1) & ~((s32) ~((lbl_8055DBFD - 5) | (5 - lbl_8055DBFD)) >> 0x1F);
        lbl_8055DBFE = (lbl_8055DBFE + 1) & ~((s32) ~((lbl_8055DBFE - 0xEA60) | (0xEA60 - lbl_8055DBFE)) >> 0x1F);
        if (((s32) lbl_8055DC11 != 0) && (SCCheckStatus() == 0) && (SCSetBtDeviceInfoArray(&_scArray) == 1)) {
            SCFlushAsync(0);
            lbl_8055DC11 = 0;
        }
        if (((s32) lbl_8055DC06 != 0) && (SCCheckStatus() == 0)) {
            var_r0_5 = SCGetBtDpdSensibility();
            if (var_r0_5 < 1U) {
                var_r0_5 = 1;
            }
            if (var_r0_5 > 5U) {
                var_r0_5 = 5;
            }
            lbl_8055DC19 = var_r0_5;
            temp_r3 = SCGetWpadSensorBarPosition();
            lbl_8055DC18 = (temp_r3 - 1) == 0;
            temp_r3_2 = SCGetWpadMotorMode();
            lbl_8055DC14 = (void*)((temp_r3_2 - 1) == 0);
            var_r3 = SCGetWpadSpeakerVolume();
            if (var_r3 > 0x7FU) {
                var_r3 = 0x7F;
            }
            lbl_8055DC12 = var_r3;
            lbl_8055DC06 = 0;
        }
        BTA_HhGetAclQueueInfo();
    }
}

static void CheckButtonCombination(s32 chan) {
    WPADCB* p = _wpdcb[chan];

    s8 pressed = -1;
    BOOL enabled = OSDisableInterrupts();

    u8 rxBufIndex = p->rxBufIndex != 0 ? 0 : 1;
    WPADStatus* pStatus = (WPADStatus*)p->rxBufs[rxBufIndex];

    if ((p->dataFormat == WPAD_FMT_FS_BTN ||
         p->dataFormat == WPAD_FMT_FS_BTN_ACC ||
         p->dataFormat == WPAD_FMT_FS_BTN_ACC_DPD) &&

        (pStatus->button == (WPAD_BUTTON_A | WPAD_BUTTON_B | WPAD_BUTTON_PLUS |
                             WPAD_BUTTON_MINUS))) {

        pressed = 1;
    }

    if ((p->dataFormat == WPAD_FMT_CLASSIC_BTN ||
         p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC ||
         p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC_DPD)) {

        WPADCLStatus* pStatusCL = (WPADCLStatus*)pStatus;

        if (pStatus->button == (WPAD_BUTTON_A | WPAD_BUTTON_B |
                                WPAD_BUTTON_PLUS | WPAD_BUTTON_MINUS)) {
            pressed = 1;
        }

        if (pStatus->err != WPAD_ERR_OK) {
            pressed = 0;
        } else if (pStatusCL->clButton ==
                   (WPAD_BUTTON_CL_A | WPAD_BUTTON_CL_B | WPAD_BUTTON_CL_PLUS |
                    WPAD_BUTTON_CL_MINUS)) {

            pressed = 1;
        }
    }

    if (pressed < 0) {
        p->comboHeld = 0;
    } else {
        p->comboHeld += pressed;
    }

    OSRestoreInterrupts(enabled);

    if (p->comboHeld > 600) {
        WPADRecalibrate(chan);
    }
}

static void WPADiCheckContInputs(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL changed = FALSE;
    BOOL screenSaver = FALSE;
    BOOL enabled;
    u8 rxBufIndex;
    WPADStatus* pStatus;
    WPADStatus* pStatusMain;

    if (p->status == WPAD_ERR_NO_CONTROLLER) {
        return;
    }

    enabled = OSDisableInterrupts();

    rxBufIndex = p->rxBufIndex != 0 ? 0 : 1;
    pStatus = (WPADStatus*)p->rxBufs[rxBufIndex];

    changed = IsControllerDataChanged(p, pStatus, p->rxBufMain);
    if (changed) {
        memcpy(p->rxBufMain, pStatus, RX_BUFFER_SIZE);
    }

    pStatusMain = (WPADStatus*)p->rxBufMain;
    if (pStatusMain->err != WPAD_ERR_OK) {
        memset(p->rxBufMain, 0, RX_BUFFER_SIZE);
    }

    OSRestoreInterrupts(enabled);

    CheckButtonCombination(chan);

    if (changed) {
        screenSaver = TRUE;
        p->lastControllerDataUpdate = __OSGetSystemTime();
    } else if (_sleepTime != 0) {
        s32 time =
            OS_TICKS_TO_SEC(__OSGetSystemTime() - p->lastControllerDataUpdate);

        if (time > _sleepTime * 60) {
            WPADiDisconnect(chan, TRUE);
        }
    }

    __SetScreenSaverFlag(screenSaver);
}

static BOOL WPADiProcessExtCommand(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    WPADCommand command;

    if (p->used) {
        if (WPADiGetCommand(&p->extCmdQueue, &command)) {

            if (command.reportID == RPTID_SET_DATA_REPORT_MODE ||
                p->wpInfo.attach) {

                if (WPADiSendData(chan, command) == WPAD_ERR_OK) {
                    WPADiPopCommand(&p->extCmdQueue);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

static BOOL WPADiProcessCommand(s32 chan, BOOL prevSuccess) {
    WPADCB* p = _wpdcb[chan];
    WPADCommand command;

    if (p->used) {
        if (WPADiGetCommand(&p->stdCmdQueue, &command) &&
            WPADiSendData(chan, command) == WPAD_ERR_OK) {

            WPADiPopCommand(&p->stdCmdQueue);
            return TRUE;
        }
    }

    return FALSE;
}

static void WPADiContMapTableUpdate(void) {
    if (!_scFlush || SCCheckStatus() != SC_STATUS_OK) {
        return;
    }

    if (SCSetBtDeviceInfoArray(&_scArray) != TRUE) {
        return;
    }

    SCFlushAsync(NULL);

    _scFlush = FALSE;
}

static void WPADiGetScSettings(void) {
    if (!_scSetting || SCCheckStatus() != SC_STATUS_OK) {
        return;
    }

    _dpdSensitivity = __GetDpdSensitivity();
    _sensorBarPos = __GetSensorBarPosition();
    _rumble = __GetMotorMode();
    _speakerVolume = __GetSpeakerVolume();

    _scSetting = FALSE;
}

static void WPADiAfh(void) {
    BOOL enabled;
    u8* pWifiChannel;

    if (_afhCnt != 60000) {
        return;
    }

    pWifiChannel = OSPhysicalToCached(OS_PHYS_WIFI_AFH_CHANNEL);
    DCInvalidateRange(pWifiChannel, sizeof *pWifiChannel);

    DEBUGPrint("Check the update of WiFi using channel\n");

    if (_afhChannel != *pWifiChannel) {
        enabled = OSDisableInterrupts();
        _afhChannel = *pWifiChannel;
        OSRestoreInterrupts(enabled);

        DEBUGPrint("WiFi uses channel = %d\n", *pWifiChannel);
        WUDSetDisableChannel(_afhChannel);
    }
}

static void WPADiRumbleMotor(s32 chan, BOOL prevSuccess) {
    WPADCommand command;

    if (prevSuccess == TRUE || __GetCmdNumber(&_wpdcb[chan]->stdCmdQueue) > 0) {
        _wpdcb[chan]->motorBusy = FALSE;

    } else if (_rumbleCnt[chan] == 5) {
        _wpdcb[chan]->motorBusy = FALSE;

        command.reportID = RPTID_SET_RUMBLE;
        command.dataLength = RPT10_SIZE;
        command.dataBuf[RPT10_RUMBLE] = FALSE;
        command.cmdCB = NULL;

        __SendData(chan, command);
    }

    _rumbleCnt[chan] = _wpdcb[chan]->motorBusy ? _rumbleCnt[chan] + 1 : 0;
}

static void WPADiManageHandler(OSAlarm* pAlarm, OSContext* pContext) {
    WPADLibStatus status = WPADGetStatus();
    s32 chan;
    BOOL success;

    if (status != WPAD_LIB_STATUS_3) {
        if (status == WPAD_LIB_STATUS_2 && !_initialized) {
            _initialized = TRUE;

            WUDSetHidConnCallback(WPADiConnCallback);
            WUDSetHidRecvCallback(WPADiRecvCallback);
        }

        return;
    }

    for (chan = WPAD_CHAN0; chan < WPAD_MAX_CONTROLLERS; chan++) {
        success = FALSE;

        if (_extCnt[chan] == 5) {
            success |= WPADiProcessExtCommand(chan);

            if (success) {
                _extCnt[chan] = 0;
            }
        }

        if (!success) {
            success |= WPADiProcessCommand(chan, success);
        }

        if (_wpdcb[chan]->status != WPAD_ERR_NO_CONTROLLER) {
            WPADiRumbleMotor(chan, success);
        }

        if (_checkCnt == 5) {
            WPADiCheckContInputs(chan);
        }

        if (_senseCnt == 10) {
            WPADiRadioSensitivity(chan);
        }

        _extCnt[chan] = _extCnt[chan] == 5 ? _extCnt[chan] : _extCnt[chan] + 1;
    }

    WPADiAfh();

    _senseCnt = _senseCnt == 10 ? 0 : _senseCnt + 1;
    _checkCnt = _checkCnt == 5 ? 0 : _checkCnt + 1;
    _afhCnt = _afhCnt == 60000 ? 0 : _afhCnt + 1;

    WPADiContMapTableUpdate();
    WPADiGetScSettings();

    BTA_HhGetAclQueueInfo();
}

static void WPADiManageHandler0(OSAlarm* pAlarm, OSContext* pContext) {
    OSSwitchFiberEx((u32)pAlarm, (u32)pContext, 0, 0, WPADiManageHandler,
                    __WPADiManageHandlerStack +
                        sizeof(__WPADiManageHandlerStack));
}

static void __ClearControlBlock(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    WPADStatus* pStatus;

    p->rxBufIndex = 0;
    p->wpInfoOut = NULL;

    p->motorRunning = FALSE;

    p->cmdBlkCB = NULL;
    p->extensionCB = NULL;
    p->samplingCB = NULL;

    p->samplingBuf = NULL;
    p->samplingBufIndex = 0;
    p->samplingBufSize = 0;

    p->dataFormat = WPAD_FMT_CORE_BTN;
    p->status = WPAD_ERR_NO_CONTROLLER;
    p->devType = WPAD_DEV_NOT_FOUND;
    p->devMode = WPAD_DEV_MODE_NORMAL;

    p->calibrated = FALSE;
    p->comboHeld = 0;

    p->statusReqBusy = FALSE;

    p->defaultDpdSize = 12;
    p->currentDpdCommand = WPAD_DPD_DISABLE;
    p->pendingDpdCommand = 0;

    p->filterDiffDpd = 0;
    p->filterSameDpd = 0;
    p->filterDiffAcc = 0;
    p->filterSameAcc = 0;
    p->filterDiffExt = 0;
    p->filterSameExt = 0;

    p->lastControllerDataUpdate = __OSGetSystemTime();
    p->lastReportSendTime = __OSGetSystemTime();
    p->UNK_0x910 = 0;
    p->UNK_0x8C9 = 0;
    p->UNK_0x8C4 = 0;
    p->wmReadDataPtr = NULL;
    p->wmReadAddress = 0;
    p->wmReadLength = 0;
    p->wmReadHadError = 0;
    p->devHandle = WUD_DEV_HANDLE_INVALID;
    p->used = FALSE;
    p->handshakeFinished = FALSE;
    p->configIndex = 0;
    p->radioQuality = WPAD_RADIO_QUALITY_BAD;
    p->radioQualityOkMs = 0;
    p->audioFrames = 0;
    p->UNK_0x982 = 0;
    p->radioSensitivity = 0;
    p->copyOutCount = 0;
    p->sleeping = TRUE;
    p->getInfoBusy = FALSE;
    p->getInfoCB = NULL;

    memset(&p->wpInfo, 0, sizeof(p->wpInfo));
    memset(&p->wmReadDataBuf, 0, sizeof(p->wmReadDataBuf));

    memset(p->rxBufs, 0, sizeof(p->rxBufs));
    memset(p->rxBufMain, 0, RX_BUFFER_SIZE);

    memset(&p->devConfig, 0, sizeof(WPADDevConfig));
    memset(&p->extConfig, 0, sizeof(WPADExtConfig));
    memset(&p->encryptionKey, 0, sizeof(p->encryptionKey));
    memset(&p->decryptAddTable, 0, sizeof(p->decryptAddTable));
    memset(&p->decryptXorTable, 0, sizeof(p->decryptXorTable));
    memset(&p->gameInfo, 0, sizeof(WPADGameInfo));

    p->UNK_0x38[0] = -1;
    p->UNK_0x38[1] = -1;

    p->stdCmdQueue.buffer = p->stdCmdQueueList;
    p->stdCmdQueue.capacity = ARRAY_SIZE(p->stdCmdQueueList);
    p->extCmdQueue.buffer = p->extCmdQueueList;
    p->extCmdQueue.capacity = ARRAY_SIZE(p->extCmdQueueList);

    WPADiClearQueue(&p->stdCmdQueue);
    WPADiClearQueue(&p->extCmdQueue);

    _extCnt[chan] = 0;

    _wmb[chan].at_0x00 = 0;
    _wmb[chan].at_0x04 = 0;
    _wmb[chan].at_0x08 = 0;
    _wmb[chan].at_0x0c = 0;
    _wmb[chan].at_0x10 = NULL;

    _rumbleCnt[chan] = 0;
}

// DECOMP_FORCEACTIVE
extern void WPADiClearQueue(WPADCommandQueue* pQueue);

void WPADiInitSub(void) {
    BOOL enabled;
    s32 chan;
    int i;

    WPADSetSensorBarPower(TRUE);

    for (i = 0; i < WUD_MAX_DEV_ENTRY; i++) {
        _dev_handle_index[i] = WUD_DEV_HANDLE_INVALID;
    }

    DEBUGPrint("WPADInit()\n");

    for (chan = 0; chan < WPAD_MAX_CONTROLLERS; chan++) {
        _wpdcb[chan] = &_wpd[chan];
        _chan_active_state[chan] = FALSE;

        _wpdcb[chan]->connectCB = NULL;
        __ClearControlBlock(chan);
        OSInitThreadQueue(&_wpd[chan].threadQueue);

        _extCnt[chan] = 0;
        _rumbleCnt[chan] = 0;
    }

    _sleepTime = 5;
    _gamecode = OSGetAppGamename();
    _gametype = OSGetAppType();
    _dpdSensitivity = __GetDpdSensitivity();
    _sensorBarPos = __GetSensorBarPosition();
    _rumble = __GetMotorMode();
    _speakerVolume = __GetSpeakerVolume();
    _senseCnt = 0;
    _checkCnt = 0;
    _afhCnt = 0;
    _shutdown = FALSE;
    _scFlush = FALSE;
    _scSetting = TRUE;
    _afhChannel = -1;

    OSCreateAlarm(&_managerAlarm);
    OSSetPeriodicAlarm(&_managerAlarm, OSGetTime(), OS_MSEC_TO_TICKS(1),
                       WPADiManageHandler0);

    OSRegisterVersion(__WPADVersion);
}

void WPADInit(void) {
    if (!_regShutdown) {
        OSRegisterShutdownFunction(&ShutdownFunctionInfo);
        _regShutdown = TRUE;
    }

    if (WUDInit()) {
        _initialized = FALSE;
        WPADiInitSub();
    }
}

DECOMP_INLINE void __WPADShutdown(void) {
    BOOL enabled = OSDisableInterrupts();
    int i;

    if (_shutdown) {
        OSRestoreInterrupts(enabled);
        return;
    }

    _shutdown = TRUE;

    WUDSetVisibility(FALSE, FALSE);

    for (i = WUD_MAX_DEV_ENTRY_FOR_STD + WPAD_CHAN0;
         i < WUD_MAX_DEV_ENTRY_FOR_STD + WPAD_MAX_CONTROLLERS; i++) {
        memset(&_scArray.devices[i], 0, sizeof(SCBtDeviceInfo));
    }

    OSCancelAlarm(&_managerAlarm);

    WUDSetHidRecvCallback(NULL);
    WUDShutdown();

    OSRestoreInterrupts(enabled);
}

void __WPADReconnect(void) {
    BOOL enabled = OSDisableInterrupts();
    int i;

    if (_shutdown) {
        OSRestoreInterrupts(enabled);
        return;
    }

    _shutdown = TRUE;

    BTA_DmSendHciReset();

    OSCancelAlarm(&_managerAlarm);

    WUDSetHidRecvCallback(NULL);
    WUDShutdown();

    OSRestoreInterrupts(enabled);
}

BOOL WPADStartSimpleSync(void) {
    return WUDStartSyncSimple();
}

BOOL WPADStartFastSimpleSync(void) {
    return WUDStartFastSyncSimple();
}

BOOL WPADStopSimpleSync(void) {
    return WUDStopSyncSimple();
}

BOOL WPADStartClearDevice(void) {
    return WUDStartClearDevice();
}

WPADSyncDeviceCallback
WPADSetSimpleSyncCallback(WPADSyncDeviceCallback pCallback) {
    return WUDSetSyncSimpleCallback(pCallback);
}

WPADClearDeviceCallback
WPADSetClearDeviceCallback(WPADClearDeviceCallback pCallback) {
    return WUDSetClearDeviceCallback(pCallback);
}

void WPADRegisterAllocator(WPADAllocFunc pAllocFunc, WPADFreeFunc pFreeFunc) {
    WUDRegisterAllocator(pAllocFunc, pFreeFunc);
}

u32 WPADGetWorkMemorySize(void) {
    return WUDGetAllocatedMemSize();
}

WPADLibStatus WPADGetStatus(void) {
    return (WPADLibStatus)WUDGetStatus();
}

void WPADGetAddress(s32 chan, BD_ADDR_PTR pAddr) {
    WPADCB* p = _wpdcb[chan];
    BD_ADDR_PTR pDevAddr;
    BOOL enabled;
    s8 devHandle;

    enabled = OSDisableInterrupts();
    devHandle = p->devHandle;
    OSRestoreInterrupts(enabled);

    pDevAddr = _WUDGetDevAddr(devHandle);

    if (pDevAddr != NULL)
        WUD_BDCPY(pAddr, pDevAddr);
    else {
        memset(pAddr, 0, BD_ADDR_LEN);
    }
}

u8 WPADGetSensorBarPosition(void) {
    BOOL enabled = OSDisableInterrupts();
    u8 pos = _sensorBarPos;
    OSRestoreInterrupts(enabled);
    return pos;
}

static void setupCallback(s32 chan, s32 status) {
    WPADCB* p = _wpdcb[chan];

    if (status == WPAD_ERR_NO_CONTROLLER) {
        return;
    }

    if (status == WPAD_ERR_OK) {
        p->handshakeFinished = TRUE;

        if (p->connectCB != NULL) {
            p->connectCB(chan, status);
        }
    } else {
        WPADiDisconnect(chan, FALSE);
    }
}

static void abortConnCallback(s32 chan, s32 status) {
    WPADCB* p = _wpdcb[chan];

    if (status != WPAD_ERR_OK) {
        WPADiClearQueue(&p->stdCmdQueue);

        if (status != WPAD_ERR_NO_CONTROLLER) {
            WPADiDisconnect(chan, FALSE);
        }
    }
}

static void firmwareCheckCallback(s32 chan, s32 status) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled;
    u32 address;
    u16 size;
    u8 port;

    if (status == WPAD_ERR_NO_CONTROLLER) {
        return;
    }

    enabled = OSDisableInterrupts();

    p->configIndex = status == WPAD_ERR_OK ? 1 : 0;
    p->status = WPAD_ERR_OK;

    OSRestoreInterrupts(enabled);

    size = status == WPAD_ERR_OK ? 20 : 42;
    address =
        status == WPAD_ERR_OK ? WM_ADDR_MEM_176C : WM_ADDR_MEM_DEV_CONFIG_0;

    DEBUGPrint(" ==>this error means that the firmware is for NDEV %s\n",
               p->configIndex != 0 ? "2.0" : "2.1 or later");

    WPADiSendSetReportType(&p->stdCmdQueue, WPAD_FMT_CORE_BTN,
                           &abortConnCallback);

    WPADiSendDPDCSB(&p->stdCmdQueue, FALSE, &abortConnCallback);
    WPADiSendSetPort(&p->stdCmdQueue, 1 << chan, &abortConnCallback);

    WPADiSendReadData(&p->stdCmdQueue, p->wmReadDataBuf, sizeof(WPADGameInfo),
                      WM_ADDR_MEM_GAME_INFO_0, &abortConnCallback);
    WPADiSendReadData(&p->stdCmdQueue, p->wmReadDataBuf, sizeof(WPADGameInfo),
                      WM_ADDR_MEM_GAME_INFO_1, &abortConnCallback);

    WPADiSendReadData(&p->stdCmdQueue, p->wmReadDataBuf, size, address,
                      &setupCallback);

    WPADiSendGetContStat(&p->stdCmdQueue, NULL, NULL);
}

static s32 WPADiRetrieveChannel(u8 devHandle) {
    BD_ADDR_PTR pAddr;
    int i;

    pAddr = _WUDGetDevAddr(devHandle);

    for (i = 0; (s16)i < WPAD_MAX_CONTROLLERS; i++) {
        if (WUD_BDCMP(_scArray.active[(u32)i].addr, pAddr) != 0) {
            continue;
        }

        if (_chan_active_state[i]) {
            continue;
        }

        _chan_active_state[i] = TRUE;
        return i;
    }

    for (i = 0; i < WPAD_MAX_CONTROLLERS; i++) {
        if (_chan_active_state[i]) {
            continue;
        }

        _chan_active_state[i] = TRUE;
        WUD_BDCPY(&_scArray.regist[WUD_MAX_DEV_ENTRY_FOR_STD + i].addr, pAddr);
        _scFlush = TRUE;

        return i;
    }

    return WPAD_CHAN_INVALID;
}

static void WPADiConnCallback(UINT8 devHandle, u8 open) {
    s32 chan;
    WPADCB* p;
    WPADCommand command;
    BOOL remain;

    if (open) {
        DEBUGPrint("connection is opened\n");

        chan = WPADiRetrieveChannel(devHandle);

        p = _wpdcb[chan];
        _dev_handle_index[devHandle] = chan;

        __ClearControlBlock(chan);
        p->devHandle = devHandle;

        p->devType = WPAD_DEV_CORE;
        p->dataFormat = WPAD_FMT_CORE_BTN;
        p->used = TRUE;
        p->status = WPAD_ERR_OK;
        p->radioSensitivity = 100;
        p->sleeping = FALSE;

        WPADiSendReadData(&p->stdCmdQueue, p->wmReadDataBuf, 1,
                          WM_ADDR_MEM_1770, firmwareCheckCallback);

        __SetScreenSaverFlag(TRUE);
    } else {
        DEBUGPrint("connection is closed\n");

        chan = _dev_handle_index[devHandle];
        _dev_handle_index[devHandle] = WUD_DEV_HANDLE_INVALID;

        if (chan != WUD_DEV_HANDLE_INVALID) {
            p = _wpdcb[chan];
            p->status = WPAD_ERR_NO_CONTROLLER;

            if (p->cmdBlkCB != NULL) {
                p->cmdBlkCB(chan, WPAD_ERR_NO_CONTROLLER);
            } else if (_wmb[chan].at_0x10 != NULL) {
                _wmb[chan].at_0x10(chan, WPAD_ERR_NO_CONTROLLER);
            }

            do {
                remain = WPADiGetCommand(&p->stdCmdQueue, &command);

                if (remain) {
                    if (command.cmdCB != NULL) {
                        command.cmdCB(chan, WPAD_ERR_NO_CONTROLLER);
                    }

                    WPADiPopCommand(&p->stdCmdQueue);
                }
            } while (remain);

            DEBUGPrint("clean up command queue\n");

            if (p->samplingBuf != NULL) {
                WPADSetAutoSamplingBuf(chan, p->samplingBuf,
                                       p->samplingBufSize);
            }

            __ClearControlBlock(chan);
            _chan_active_state[chan] = FALSE;

            if (p->connectCB != NULL) {
                p->connectCB(chan, WPAD_ERR_NO_CONTROLLER);
            }
        } else {
            DEBUGPrint("WARNING: disconnection for device handle not assigned "
                       "to channel.\n");
        }
    }
}

/* HID receive callback: resolve device handle to port and dispatch report parsing. */
static void WPADiRecvCallback(UINT8 devHandle, UINT8* pReport, UINT16 len) {
    s32 result;
    u8 port = _dev_handle_index[devHandle];

    // @bug Accepts WPAD_MAX_CONTROLLERS
    if (port <= WPAD_MAX_CONTROLLERS) {
        result = WPADiHIDParser(port, pReport);

        if (result != 0) {
            DEBUGPrint("HID Parser reports: %d\n", result);
        }
    } else {
        DEBUGPrint("WPADiRecvCallback(): Unknown channel %d\n", port);
    }
}

static s32 WPADiGetStatus(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled = OSDisableInterrupts();

    s32 status = p->status;

    OSRestoreInterrupts(enabled);
    return status;
}

void WPADGetAccGravityUnit(s32 chan, u32 type, WPADAccGravityUnit* pAcc) {
    /* Copy the 1g accelerometer calibration delta (1g - 0g) for the requested device into pAcc, with interrupts disabled. */
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();

    if (pAcc != NULL) {
        switch (type) {
        case WPAD_ACC_GRAVITY_UNIT_CORE: {
            WPADDevConfig* config = (WPADDevConfig*)((u8*)p + 0x794);
            pAcc->x = config->accX1g - config->accX0g;
            pAcc->y = config->accY1g - config->accY0g;
            pAcc->z = config->accZ1g - config->accZ0g;
            break;
        }

        case WPAD_ACC_GRAVITY_UNIT_FS: {
            WPADExtConfig* config = (WPADExtConfig*)((u8*)p + 0x7C2);
            pAcc->x = config->fs.accX1g - config->fs.accX0g;
            pAcc->y = config->fs.accY1g - config->fs.accY0g;
            pAcc->z = config->fs.accZ1g - config->fs.accZ0g;
            break;
        }
        }
    }

    OSRestoreInterrupts(enabled);
}

static void DisconnectCallback(s32 chan, s32 status) {
    WPADCB* p = _wpdcb[chan];

    if (status != WPAD_ERR_NO_CONTROLLER) {
        BTA_HhClose(p->devHandle);
    }
}

static void WPADiDisconnect(s32 chan, BOOL sleep) {
    WPADCB* p = _wpdcb[chan];
    s32 status;
    BOOL enabled;

    status = WPADiGetStatus(chan);
    if (status == WPAD_ERR_NO_CONTROLLER) {
        return;
    }

    if (sleep) {
        enabled = OSDisableInterrupts();

        if (p->sleeping) {
            OSRestoreInterrupts(enabled);
            return;
        }

        p->sleeping = TRUE;

        OSRestoreInterrupts(enabled);
        WPADControlLed(chan, 0, DisconnectCallback);
    } else {
        BD_ADDR addr;
        WPADGetAddress(chan, addr);

        btm_remove_acl(addr);
    }
}

void WPADDisconnect(s32 chan) {
    s32 status;

    memset(&_scArray.devices[WUD_MAX_DEV_ENTRY_FOR_STD + chan], 0,
           sizeof(SCBtDeviceInfo));

    _scFlush = TRUE;

    WPADiDisconnect(chan, TRUE);
}

/* Returns the current controller status and, if requested, its device type. */
s32 WPADProbe(s32 chan, s32* outDevType) {
    WPADCB* cb = lbl_8038F4F0[chan];
    BOOL enabled;
    s32 status;

    enabled = OSDisableInterrupts();

    if (outDevType != NULL) {
        *outDevType = ((u8*)cb)[0x801];
    }

    status = ((s32*)((u8*)cb + 0x7FC))[0];

    if (status != WPAD_ERR_NO_CONTROLLER) {
        if (((u8*)cb)[0x801] == WPAD_DEV_NOT_FOUND) {
            status = WPAD_ERR_NO_CONTROLLER;
        } else if (!((BOOL*)((u8*)cb + 0x81C))[0]) {
            status = WPAD_ERR_COMMUNICATION_ERROR;
        }
    }

    OSRestoreInterrupts(enabled);
    return status;
}

/* Set the sampling callback for a WPAD channel and return the previous one.
 * Interrupts are disabled while the callback slot is swapped. */
WPADSamplingCallback WPADSetSamplingCallback(s32 chan,
                                             WPADSamplingCallback pCallback) {

    WPADCB* p;
    BOOL enabled;
    WPADSamplingCallback pOldCallback;

    DBPrintf_80068D68(lbl_803122A0);

    enabled = OSDisableInterrupts();
    p = lbl_8038F4F0[chan];

    pOldCallback = *(WPADSamplingCallback*)((u8*)p + 0x7E4);
    *(WPADSamplingCallback*)((u8*)p + 0x7E4) = pCallback;

    OSRestoreInterrupts(enabled);
    return pOldCallback;
}

WPADSamplingCallback WPADSetSamplingCallback_800603D0(s32 chan,
                                                     WPADSamplingCallback pCallback) {
    /* Set the WPAD sampling callback at offset 0x7E0 for the given channel and
       return the previous callback. Interrupts are disabled during the swap. */
    WPADCB* p;
    BOOL enabled;
    WPADSamplingCallback pOldCallback;

    DBPrintf_80068D68(lbl_803122BC);
    enabled = OSDisableInterrupts();
    p = lbl_8038F4F0[chan];
    pOldCallback = *(WPADSamplingCallback*)((u8*)p + 0x7E0);
    *(WPADSamplingCallback*)((u8*)p + 0x7E0) = pCallback;
    OSRestoreInterrupts(enabled);
    return pOldCallback;
}

WPADConnectCallback WPADSetConnectCallback(s32 chan,
                                           WPADConnectCallback pCallback) {

    WPADCB* p;
    BOOL enabled;
    WPADConnectCallback pOldCallback;

    DEBUGPrint("WPADSetConnectCallback()\n");

    enabled = OSDisableInterrupts();
    p = _wpdcb[chan];

    pOldCallback = p->connectCB;
    p->connectCB = pCallback;

    OSRestoreInterrupts(enabled);
    return pOldCallback;
}

WPADExtensionCallback
WPADSetExtensionCallback(s32 chan, WPADExtensionCallback pCallback) {

    WPADCB* p;
    BOOL enabled;
    WPADExtensionCallback pOldCallback;

    DEBUGPrint("WPADSetExtensionCallback()\n");

    enabled = OSDisableInterrupts();
    p = _wpdcb[chan];

    pOldCallback = p->extensionCB;
    p->extensionCB = pCallback;

    OSRestoreInterrupts(enabled);
    return pOldCallback;
}

u32 WPADGetDataFormat(s32 chan) {
    BOOL enabled = OSDisableInterrupts();
    WPADCB* p = _wpdcb[chan];

    u32 format = p->dataFormat;

    OSRestoreInterrupts(enabled);
    return format;
}

/* Sets the WPAD data report format for a channel; queues a format change when needed and returns WPAD status. */
s32 WPADSetDataFormat(s32 chan, u32 format) {
    WPADCB* cb = lbl_8038F4F0[chan];
    s32 status;
    BOOL enabled;
    BOOL handshakeFinished;
    u32 currentFormat;

    enabled = OSDisableInterrupts();
    handshakeFinished = *(BOOL*)((u8*)cb + 0x81C);
    status = *(s32*)((u8*)cb + 0x7FC);
    currentFormat = *(u32*)((u8*)cb + 0x7F8);
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        goto _end;
    }
    if (!handshakeFinished) {
        status = WPAD_ERR_COMMUNICATION_ERROR;
        goto _end;
    }
    if (currentFormat != format) {
        if (!fn_80063564(&cb->stdCmdQueue, format, NULL)) {
            status = WPAD_ERR_COMMUNICATION_ERROR;
        } else {
            enabled = OSDisableInterrupts();
            *(u32*)((u8*)cb + 0x7F8) = format;
            OSRestoreInterrupts(enabled);
            status = WPAD_ERR_OK;
        }
    } else {
        status = WPAD_ERR_OK;
    }
_end:
    return status;
}

static void __infoCallback(s32 chan, s32 result) {
    WPADCB* p = _wpdcb[chan];

    if (p->getInfoCB != NULL) {
        p->getInfoCB(chan, result);
    }

    p->getInfoCB = NULL;
    p->getInfoBusy = FALSE;
}

s32 WPADGetInfoAsync(s32 chan, WPADInfo* pInfo, WPADCallback pCallback) {
    BOOL handshake;
    s32 status;
    WPADCB* p = _wpdcb[chan];
    BOOL enabled;
    u8 getInfoBusy;

    enabled = OSDisableInterrupts();

    handshake = p->handshakeFinished;
    status = p->status;
    getInfoBusy = p->getInfoBusy;

    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        goto _end;
    }

    if (!handshake || getInfoBusy) {
        status = WPAD_ERR_COMMUNICATION_ERROR;
        goto _end;
    }

    enabled = OSDisableInterrupts();

    p->getInfoBusy = TRUE;
    p->getInfoCB = pCallback;

    OSRestoreInterrupts(enabled);

    if (WPADiSendGetContStat(&p->stdCmdQueue, pInfo, __infoCallback)) {
        status = WPAD_ERR_OK;
        goto _end;
    }

    status = WPAD_ERR_COMMUNICATION_ERROR;

    enabled = OSDisableInterrupts();

    p->getInfoBusy = FALSE;
    p->getInfoCB = NULL;

    OSRestoreInterrupts(enabled);

_end:
    if (status != WPAD_ERR_OK && pCallback != NULL) {
        pCallback(chan, status);
    }

    return status;
}

/* Start or stop rumble for a WPAD channel, respecting link/config state. */
void WPADControlMotor(s32 chan, u32 command) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();
    s32 status = *(s32*)((u8*)p + 0x7FC);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        OSRestoreInterrupts(enabled);
        return;
    }

    if (!lbl_8055DC14 && (command != WPAD_MOTOR_STOP ||
                         *(BOOL*)((u8*)p + 0x814) != TRUE)) {
        OSRestoreInterrupts(enabled);
        return;
    }

    if (command == WPAD_MOTOR_STOP && *(BOOL*)((u8*)p + 0x814) == FALSE ||
        command == WPAD_MOTOR_RUMBLE && *(BOOL*)((u8*)p + 0x814) == TRUE) {
        OSRestoreInterrupts(enabled);
        return;
    }

    *(BOOL*)((u8*)p + 0x814) = command == WPAD_MOTOR_STOP ? FALSE : TRUE;
    *(u32*)((u8*)p + 0x810) = TRUE;

    OSRestoreInterrupts(enabled);
}

void WPADEnableMotor(BOOL enable) {
    BOOL enabled = OSDisableInterrupts();
    _rumble = enable;
    OSRestoreInterrupts(enabled);
}

BOOL WPADIsMotorEnabled(void) {
    BOOL enabled = OSDisableInterrupts();
    BOOL motorEnabled = _rumble;
    OSRestoreInterrupts(enabled);

    return motorEnabled;
}

s32 WPADControlLed(s32 chan, u8 flags, WPADCallback pCallback) {
    WPADCB* p = _wpdcb[chan];
    BOOL success;
    BOOL enabled;
    BOOL handshake;
    s32 status;

    status = WPAD_ERR_OK;

    enabled = OSDisableInterrupts();
    status = p->status;
    handshake = p->handshakeFinished;
    OSRestoreInterrupts(enabled);

    if (status != WPAD_ERR_NO_CONTROLLER) {
        if (!handshake) {
            status = WPAD_ERR_COMMUNICATION_ERROR;
        } else {
            success = WPADiSendSetPort(&p->stdCmdQueue, flags, pCallback);
            status = success ? 0 : WPAD_ERR_COMMUNICATION_ERROR;
        }
    }

    if (status != WPAD_ERR_OK && pCallback != NULL) {
        pCallback(chan, status);
    }

    return status;
}

/* Save WPAD settings (speaker volume and rumble/motor mode) to system config and flush asynchronously. */
BOOL WPADSaveConfig(WPADSaveCallback pCallback) {
    BOOL success = TRUE;
    BOOL enabled;
    u8 volume;
    u8 mode;

    if (SCCheckStatus() != SC_STATUS_OK) {
        return FALSE;
    }

    enabled = OSDisableInterrupts();
    volume = _speakerVolume;
    mode = _rumble ? SC_MOTOR_ON : SC_MOTOR_OFF;
    OSRestoreInterrupts(enabled);

    success &= SCSetWpadSpeakerVolume(volume);
    success &= SCSetWpadMotorMode(mode);

    if (success) {
        SCFlushAsync(pCallback);
    } else if (pCallback != NULL) {
        pCallback(SC_STATUS_FATAL);
    }

    return success;
}

void WPADRead(s32 chan, WPADStatus* pStatus) {
    BOOL enabled = OSDisableInterrupts();
    WPADCB* p = _wpdcb[chan];

    u8 rxBufIndex = p->rxBufIndex != 0 ? 0 : 1;
    WPADStatus* pRxStatus = (WPADStatus*)p->rxBufs[rxBufIndex];

    switch (pRxStatus->err) {
    case WPAD_ERR_OK: {
        if (p->dataFormat == WPAD_FMT_CORE_BTN ||
            p->dataFormat == WPAD_FMT_CORE_BTN_ACC ||
            p->dataFormat == WPAD_FMT_CORE_BTN_ACC_DPD) {

            memcpy(pStatus, pRxStatus, sizeof(WPADStatus));

        } else if (p->dataFormat == WPAD_FMT_FS_BTN ||
                   p->dataFormat == WPAD_FMT_FS_BTN_ACC ||
                   p->dataFormat == WPAD_FMT_FS_BTN_ACC_DPD) {

            memcpy(pStatus, pRxStatus, sizeof(WPADFSStatus));

        } else if (p->dataFormat == WPAD_FMT_CLASSIC_BTN ||
                   p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC ||
                   p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {

            memcpy(pStatus, pRxStatus, sizeof(WPADCLStatus));

        } else {
            memcpy(pStatus, pRxStatus, sizeof(WPADStatusEx));
        }

        break;
    }

    case WPAD_ERR_COMMUNICATION_ERROR:
    case WPAD_ERR_CORRUPTED: {
        memcpy(pStatus, pRxStatus, sizeof(WPADStatus));
        break;
    }

    default: {
        if (p->dataFormat == WPAD_FMT_CORE_BTN ||
            p->dataFormat == WPAD_FMT_CORE_BTN_ACC ||
            p->dataFormat == WPAD_FMT_CORE_BTN_ACC_DPD) {

            memset(pStatus, 0, sizeof(WPADStatus));

        } else if (p->dataFormat == WPAD_FMT_FS_BTN ||
                   p->dataFormat == WPAD_FMT_FS_BTN_ACC ||
                   p->dataFormat == WPAD_FMT_FS_BTN_ACC_DPD) {

            memset(pStatus, 0, sizeof(WPADFSStatus));

        } else if (p->dataFormat == WPAD_FMT_CLASSIC_BTN ||
                   p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC ||
                   p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {

            memset(pStatus, 0, sizeof(WPADCLStatus));

        } else {
            memset(pStatus, 0, sizeof(WPADStatusEx));
        }

        pStatus->err = pRxStatus->err;
        break;
    }
    }

    OSRestoreInterrupts(enabled);
}

void WPADSetAutoSamplingBuf(s32 chan, void* pBuffer, u32 len) {
    /* Configure the auto-sampling ring buffer for a channel: select entry size by format, clear/init entries (err set by controller state), and install buffer/length. */
    WPADCB* p;
    BOOL enabled;
    s8 defaultErr;
    s32 fmtSize;
    int i;

    DBPrintf_80068D68(lbl_803122D8);

    enabled = OSDisableInterrupts();
    p = lbl_8038F4F0[chan];

    defaultErr = (*(s32*)((u8*)p + 0x7FC)) == WPAD_ERR_NO_CONTROLLER ? WPAD_ERR_NO_CONTROLLER
                                                     : WPAD_ERR_INVALID;

    if ((*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_CORE_BTN ||
        (*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_CORE_BTN_ACC ||
        (*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_CORE_BTN_ACC_DPD) {

        fmtSize = sizeof(WPADStatus);

    } else if ((*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_FS_BTN ||
               (*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_FS_BTN_ACC ||
               (*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_FS_BTN_ACC_DPD) {

        fmtSize = sizeof(WPADFSStatus);

    } else if ((*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_CLASSIC_BTN ||
               (*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_CLASSIC_BTN_ACC ||
               (*(u32*)((u8*)p + 0x7F8)) == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {

        fmtSize = sizeof(WPADCLStatus);

    } else {
        fmtSize = sizeof(WPADStatusEx);
    }

    if (pBuffer != NULL) {
        memset(pBuffer, 0, fmtSize * len);

        for (i = 0; i < len; i++) {
            ((WPADStatus*)((u8*)pBuffer + i * fmtSize))->err = defaultErr;
        }

        (*(u32*)((u8*)p + 0x7F0)) = -1;
        (*(u32*)((u8*)p + 0x7F4)) = len;
    }

    (*(WPADStatus**)((u8*)p + 0x7EC)) = pBuffer;

    OSRestoreInterrupts(enabled);
}

/* Exclude conflicting simultaneous D-pad inputs from the current status (core and classic). */
void WPADiExcludeButton(s32 chan) {
    WPADCB* wcb = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();

    u8 bufIndex = *(u8*)((u8*)wcb + 0x806) != 0 ? 0 : 1;
    void* rxBuf = wcb->rxBufs[bufIndex];

    WPADStatus* coreStatus;
    WPADCLStatus* clStatus;

    coreStatus = (WPADStatus*)rxBuf;

    if ((coreStatus->button & (WPAD_BUTTON_LEFT | WPAD_BUTTON_RIGHT)) ==
        (WPAD_BUTTON_LEFT | WPAD_BUTTON_RIGHT)) {
        coreStatus->button &= ~WPAD_BUTTON_RIGHT;
    }

    if ((coreStatus->button & (WPAD_BUTTON_UP | WPAD_BUTTON_DOWN)) ==
        (WPAD_BUTTON_UP | WPAD_BUTTON_DOWN)) {
        coreStatus->button &= ~WPAD_BUTTON_DOWN;
    }

    if (*(u32*)((u8*)wcb + 0x7F8) == WPAD_FMT_CLASSIC_BTN ||
        *(u32*)((u8*)wcb + 0x7F8) == WPAD_FMT_CLASSIC_BTN_ACC ||
        *(u32*)((u8*)wcb + 0x7F8) == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {
        clStatus = (WPADCLStatus*)rxBuf;

        if ((clStatus->clButton &
             (WPAD_BUTTON_CL_LEFT | WPAD_BUTTON_CL_RIGHT)) ==
            (WPAD_BUTTON_CL_LEFT | WPAD_BUTTON_CL_RIGHT)) {
            clStatus->clButton &= ~WPAD_BUTTON_CL_RIGHT;
        }

        if ((clStatus->clButton & (WPAD_BUTTON_CL_UP | WPAD_BUTTON_CL_DOWN)) ==
            (WPAD_BUTTON_CL_UP | WPAD_BUTTON_CL_DOWN)) {
            clStatus->clButton &= ~WPAD_BUTTON_CL_DOWN;
        }
    }

    OSRestoreInterrupts(enabled);
}

void fn_80060AFC(s32 chan) {
    /* Copy the latest received WPAD status into the optional ring buffer for chan (size/format at +0x7EC..+0x7F8), invoke sampling callback if set, and bump sample count. */
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();
    u8 rxBufIndex = *(u8*)((u8*)p + 0x806) != 0 ? 0 : 1;
    WPADStatus* pStatus = (WPADStatus*)p->rxBufs[rxBufIndex];

    if (*(void**)((u8*)p + 0x7EC) != NULL) {
        if (++*(u32*)((u8*)p + 0x7F0) >= *(u32*)((u8*)p + 0x7F4)) {
            *(u32*)((u8*)p + 0x7F0) = 0;
        }
        if (*(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CORE_BTN ||
            *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CORE_BTN_ACC ||
            *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CORE_BTN_ACC_DPD) {
            memcpy(&(*(WPADStatus**)((u8*)p + 0x7EC))[*(u32*)((u8*)p + 0x7F0)],
                   pStatus, sizeof(WPADStatus));
        } else if (*(u32*)((u8*)p + 0x7F8) == WPAD_FMT_FS_BTN ||
                   *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_FS_BTN_ACC ||
                   *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_FS_BTN_ACC_DPD) {
            WPADFSStatus* pDst = &(*(WPADFSStatus**)((u8*)p + 0x7EC))[*(u32*)((u8*)p + 0x7F0)];
            memcpy(pDst, pStatus, !pDst->err ? sizeof(WPADFSStatus) : sizeof(WPADStatus));
        } else if (*(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CLASSIC_BTN ||
                   *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CLASSIC_BTN_ACC ||
                   *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {
            WPADCLStatus* pDst = &(*(WPADCLStatus**)((u8*)p + 0x7EC))[*(u32*)((u8*)p + 0x7F0)];
            memcpy(pDst, pStatus, !pDst->err ? sizeof(WPADCLStatus) : sizeof(WPADStatus));
        } else {
            WPADStatusEx* pDst = &(*(WPADStatusEx**)((u8*)p + 0x7EC))[*(u32*)((u8*)p + 0x7F0)];
            memcpy(pDst, pStatus, !pDst->err ? sizeof(WPADStatusEx) : sizeof(WPADStatus));
        }
    }
    if (*(WPADSamplingCallback*)((u8*)p + 0x7E8) != NULL) {
        (*(WPADSamplingCallback*)((u8*)p + 0x7E8))(chan);
    }
    ++*(u16*)((u8*)p + 0x8C4);
    OSRestoreInterrupts(enabled);
}

void WPADiCopyOut(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled = OSDisableInterrupts();

    u8 rxBufIndex = p->rxBufIndex != 0 ? 0 : 1;
    WPADStatus* pStatus = (WPADStatus*)p->rxBufs[rxBufIndex];

    if (p->samplingBuf != NULL) {
        if (++p->samplingBufIndex >= p->samplingBufSize) {
            p->samplingBufIndex = 0;
        }

        if (p->dataFormat == WPAD_FMT_CORE_BTN ||
            p->dataFormat == WPAD_FMT_CORE_BTN_ACC ||
            p->dataFormat == WPAD_FMT_CORE_BTN_ACC_DPD) {

            memcpy(&p->samplingBuf[p->samplingBufIndex], pStatus,
                   sizeof(WPADStatus));

        } else if (p->dataFormat == WPAD_FMT_FS_BTN ||
                   p->dataFormat == WPAD_FMT_FS_BTN_ACC ||
                   p->dataFormat == WPAD_FMT_FS_BTN_ACC_DPD) {

            memcpy(&p->samplingBufFS[p->samplingBufIndex], pStatus,
                   !pStatus->err ? sizeof(WPADFSStatus) : sizeof(WPADStatus));

        } else if (p->dataFormat == WPAD_FMT_CLASSIC_BTN ||
                   p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC ||
                   p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {

            memcpy(&p->samplingBufCL[p->samplingBufIndex], pStatus,
                   !pStatus->err ? sizeof(WPADCLStatus) : sizeof(WPADStatus));

        } else {
            memcpy(&p->samplingBufEx[p->samplingBufIndex], pStatus,
                   !pStatus->err ? sizeof(WPADStatusEx) : sizeof(WPADStatus));
        }
    }

    if (p->samplingCB != NULL) {
        p->samplingCB(chan);
    }

    p->copyOutCount++;
    OSRestoreInterrupts(enabled);
}

BOOL WPADIsSpeakerEnabled(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled = OSDisableInterrupts();

    BOOL spkEnabled = p->wpInfo.speaker;

    OSRestoreInterrupts(enabled);
    return spkEnabled;
}

s32 WPADControlSpeaker(s32 chan, u32 command, WPADCallback pCallback) {
    WPADCB* p;
    BOOL enabled;
    BOOL spkEnable;
    BOOL handshake;
    s32 status;

    // clang-format off
    u8 config[SPK_CONFIG_SIZE] = {0x00,
                                  0x00,                            // 4-bit ADPCM
                                  0xD0, 0x07,                      // 3000Hz (little-endian)
                                  WPAD_MAX_SPEAKER_VOLUME / 2 + 1, // Default volume
                                  0x0C, 0x0E                       // ???
    };
    // clang-format on

    p = _wpdcb[chan];

    enabled = OSDisableInterrupts();

    spkEnable = p->wpInfo.speaker;
    status = p->status;
    handshake = p->handshakeFinished;

    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        goto _end;
    }

    if (!handshake) {
        status = WPAD_ERR_COMMUNICATION_ERROR;
        goto _end;
    }

    if (command == WPAD_SPEAKER_OFF) {
        if (!spkEnable) {
            status = WPAD_ERR_OK;
        } else {
            enabled = OSDisableInterrupts();

            if (__CanPushCmdQueue(&p->stdCmdQueue, 5)) {
                WPADiSendMuteSpeaker(&p->stdCmdQueue, TRUE, NULL);

                WPADiSendWriteDataCmd(&p->stdCmdQueue, 0x01, WM_REG_SPEAKER_01,
                                      NULL);
                WPADiSendWriteDataCmd(&p->stdCmdQueue, 0x00, WM_REG_SPEAKER_09,
                                      NULL);

                WPADiSendEnableSpeaker(&p->stdCmdQueue, FALSE, NULL);

                WPADiSendGetContStat(&p->stdCmdQueue, NULL, pCallback);

                OSRestoreInterrupts(enabled);
                return WPAD_ERR_OK;
            }

            status = WPAD_ERR_COMMUNICATION_ERROR;
            OSRestoreInterrupts(enabled);
        }
    } else {
        switch (command) {
        case WPAD_SPEAKER_ON:
        case WPAD_SPEAKER_5: {
            enabled = OSDisableInterrupts();

            if (__CanPushCmdQueue(&p->stdCmdQueue, 7)) {
                WPADiSendEnableSpeaker(&p->stdCmdQueue, TRUE, NULL);
                WPADiSendMuteSpeaker(&p->stdCmdQueue, TRUE, NULL);

                WPADiSendWriteDataCmd(&p->stdCmdQueue, 0x01, WM_REG_SPEAKER_09,
                                      NULL);
                // Sends 0x80 instead of 0x08?
                WPADiSendWriteDataCmd(&p->stdCmdQueue, 0x80, WM_REG_SPEAKER_01,
                                      NULL);

                config[4] = _speakerVolume;

                WPADiSendWriteData(&p->stdCmdQueue, &config, SPK_CONFIG_SIZE,
                                   WM_REG_SPEAKER_01, NULL);

                WPADiSendMuteSpeaker(&p->stdCmdQueue, FALSE, NULL);

                WPADiSendGetContStat(&p->stdCmdQueue, NULL, pCallback);

                OSRestoreInterrupts(enabled);
                return WPAD_ERR_OK;
            }

            status = WPAD_ERR_COMMUNICATION_ERROR;

            OSRestoreInterrupts(enabled);
            break;
        }

        case WPAD_SPEAKER_MUTE: {
            if (!WPADiSendMuteSpeaker(&p->stdCmdQueue, TRUE, pCallback)) {
                status = WPAD_ERR_COMMUNICATION_ERROR;
                break;
            }

            return WPAD_ERR_OK;
        }

        case WPAD_SPEAKER_UNMUTE: {
            if (!WPADiSendMuteSpeaker(&p->stdCmdQueue, FALSE, pCallback)) {
                status = WPAD_ERR_COMMUNICATION_ERROR;
                break;
            }

            return WPAD_ERR_OK;
        }

        case WPAD_SPEAKER_PLAY: {
            if (!WPADiSendWriteDataCmd(&p->stdCmdQueue, 0x01, WM_REG_SPEAKER_08,
                                       pCallback)) {

                status = WPAD_ERR_COMMUNICATION_ERROR;
                break;
            }

            return WPAD_ERR_OK;
        }
        }
    }

_end:
    if (pCallback != NULL) {
        pCallback(chan, status);
    }

    return status;
}

u8 WPADGetSpeakerVolume(void) {
    BOOL enabled = OSDisableInterrupts();
    u8 volume = _speakerVolume;
    OSRestoreInterrupts(enabled);
    return volume;
}

void WPADSetSpeakerVolume(u8 volume) {
    BOOL enabled = OSDisableInterrupts();
    _speakerVolume = __ClampSpeakerVolume(volume);
    OSRestoreInterrupts(enabled);
}

#pragma opt_propagation off
static BOOL IsBusyStream(s32 chan) {
    BOOL enabled;
    union { u32 u; WPADCB* p; } pc;
    WPADCB* p;
    WPADCB** table;
    u8 radioQuality;
    u32 devType;
    u8 bufferStatus;
    u16 bteBufferStatus;
    u16 btmBufferStatus;
    u8 audioFrames;
    s8 queueSize;
    u8 linkNumber;

    table = lbl_8038F4F0;
    pc.u = (u32)table[chan];
    p = pc.p;
    enabled = OSDisableInterrupts();
    radioQuality = ((u8*)p)[0x80C];
    devType = p->UNK_0x801;
    bufferStatus = WUDGetBufferStatus();
    {
        BOOL enabled2 = OSDisableInterrupts();
        queueSize = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (queueSize < 0) {
            queueSize += p->stdCmdQueue.capacity;
        }
        OSRestoreInterrupts(enabled2);
    }
    {
        WPADCB* p2 = table[chan];
        BOOL enabled2;
        s32 status;
        s8 handle;
        enabled2 = OSDisableInterrupts();
        status = *(s32*)((u8*)p2 + 0x7FC);
        handle = *(s8*)((u8*)p2 + 0x803);
        OSRestoreInterrupts(enabled2);
        if (status == WPAD_ERR_NO_CONTROLLER) {
            bteBufferStatus = 0;
        } else {
            bteBufferStatus = _WUDGetQueuedSize(handle);
        }
    }
    {
        WPADCB* p2 = table[chan];
        BOOL enabled2;
        s32 status;
        s8 handle;
        enabled2 = OSDisableInterrupts();
        status = *(s32*)((u8*)p2 + 0x7FC);
        handle = *(s8*)((u8*)p2 + 0x803);
        OSRestoreInterrupts(enabled2);
        if (status == WPAD_ERR_NO_CONTROLLER) {
            btmBufferStatus = 0;
        } else {
            btmBufferStatus = _WUDGetNotAckedSize(handle);
        }
    }
    audioFrames = ((u8*)p)[0x80E];
    linkNumber = _WUDGetLinkNumber();
    OSRestoreInterrupts(enabled);
    if (radioQuality != WPAD_RADIO_QUALITY_GOOD || btmBufferStatus > 3 ||
        bufferStatus == 10 || bufferStatus >= linkNumber * 2 + 2 ||
        devType == WPAD_DEV_UNKNOWN || queueSize >= 21 || audioFrames >= 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}
#pragma opt_propagation reset
/* Return whether stream data can be sent to the controller on `chan` (connected, handshake complete, and stream not busy). */
BOOL WPADCanSendStreamData(s32 chan) {
    WPADCB* cb = lbl_8038F4F0[chan];
    BOOL enabled;
    BOOL handshakeFinished;
    s32 status;

    enabled = OSDisableInterrupts();
    status = *(s32*)((u8*)cb + 0x7FC);
    handshakeFinished = *(BOOL*)((u8*)cb + 0x81C);
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER || !handshakeFinished || IsBusyStream(chan)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

s32 WPADSendStreamData(s32 chan, void* pData, u16 len) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled;
    BOOL handshake;
    s32 status;

    enabled = OSDisableInterrupts();
    status = p->status;
    handshake = p->handshakeFinished;
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        return WPAD_ERR_NO_CONTROLLER;
    }

    if (!handshake) {
        return WPAD_ERR_COMMUNICATION_ERROR;
    }

    if (IsBusyStream(chan)) {
        return WPAD_ERR_COMMUNICATION_ERROR;
    }

    if (!WPADiSendStreamData(&p->stdCmdQueue, pData, len)) {
        return WPAD_ERR_COMMUNICATION_ERROR;
    }

    enabled = OSDisableInterrupts();
    p->audioFrames++;
    OSRestoreInterrupts(enabled);

    return WPAD_ERR_OK;
}

u8 WPADGetDpdSensitivity(void) {
    return _dpdSensitivity;
}

BOOL WPADSetSensorBarPower(BOOL enable) {
    u32 oldReg;
    u32 newReg;
    BOOL enabled;
    BOOL old;

    enabled = OSDisableInterrupts();
    oldReg = ACRReadReg(ACR_GPIO1BOUT);

    if (enable) {
        newReg = oldReg | GPIO_SENSORBAR;
    } else {
        newReg = oldReg & ~GPIO_SENSORBAR;
    }

    ACRWriteReg(ACR_GPIO1BOUT, newReg);
    old = oldReg & GPIO_SENSORBAR ? TRUE : FALSE;

    OSRestoreInterrupts(enabled);
    return old;
}

BOOL WPADIsDpdEnabled(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled = OSDisableInterrupts();

    BOOL dpdEnabled = p->wpInfo.dpd;

    OSRestoreInterrupts(enabled);
    return dpdEnabled;
}

static void __dpdCb(s32 chan, s32 result) {
    WPADCB* p = _wpdcb[chan];

    p->currentDpdCommand = p->pendingDpdCommand;
    p->wpInfo.dpd = p->pendingDpdCommand == WPAD_DPD_DISABLE ? 0 : 1;
}

s32 WPADControlDpd(s32 chan, u32 command, WPADCallback pCallback) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled;
    BOOL dpdEnabled;
    BOOL handshake;
    u8 currCmd;
    u8 pendingCmd;
    s32 status;

    // clang-format off
    static const u8 cfg1[WPAD_MAX_DPD_SENS][DPD_CONFIG1_SIZE] = {
        {0x02, 0x00, 0x00, 0x71, 0x01, 0x00, 0x64, 0x00, 254},
        {0x02, 0x00, 0x00, 0x71, 0x01, 0x00, 0x96, 0x00, 180},
        {0x02, 0x00, 0x00, 0x71, 0x01, 0x00, 0xAA, 0x00, 100},
        {0x02, 0x00, 0x00, 0x71, 0x01, 0x00, 0xC8, 0x00,  54},
        {0x07, 0x00, 0x00, 0x71, 0x01, 0x00, 0x72, 0x00,  32}
    };
    // clang-format on

    // clang-format off
    static const u8 cfg2[WPAD_MAX_DPD_SENS][DPD_CONFIG2_SIZE] = {
        {0xFD, 0x05},
        {0xB3, 0x04},
        {0x63, 0x03},
        {0x35, 0x03},
        {0x1F, 0x03}
    };
    // clang-format on

    enabled = OSDisableInterrupts();

    dpdEnabled = p->wpInfo.dpd;
    currCmd = p->currentDpdCommand;
    pendingCmd = p->pendingDpdCommand;
    status = p->status;
    handshake = p->handshakeFinished;

    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        goto _end;
    }

    if (!handshake) {
        status = WPAD_ERR_COMMUNICATION_ERROR;
        goto _end;
    }

    if (command == WPAD_DPD_DISABLE) {
        if (!dpdEnabled) {
            status = WPAD_ERR_OK;
        } else {
            enabled = OSDisableInterrupts();

            if (__CanPushCmdQueue(&p->stdCmdQueue, 3)) {
                p->pendingDpdCommand = command;

                WPADiSendEnableDPD(&p->stdCmdQueue, FALSE, NULL);
                WPADiSendDPDCSB(&p->stdCmdQueue, FALSE, &__dpdCb);

                WPADiSendGetContStat(&p->stdCmdQueue, NULL, pCallback);

                OSRestoreInterrupts(enabled);
                return WPAD_ERR_OK;
            }

            status = WPAD_ERR_COMMUNICATION_ERROR;

            OSRestoreInterrupts(enabled);
        }
    } else if (command != pendingCmd) {
        enabled = OSDisableInterrupts();

        if (__CanPushCmdQueue(&p->stdCmdQueue, 8)) {
            p->pendingDpdCommand = command;

            WPADiSendEnableDPD(&p->stdCmdQueue, TRUE, NULL);
            WPADiSendDPDCSB(&p->stdCmdQueue, TRUE, NULL);

            WPADiSendWriteDataCmd(&p->stdCmdQueue, 0x01, WM_REG_DPD_30, NULL);

            WPADiSendWriteData(&p->stdCmdQueue, cfg1[_dpdSensitivity - 1],
                               DPD_CONFIG1_SIZE, WM_REG_DPD_CONFIG_BLOCK_1,
                               NULL);

            WPADiSendWriteData(&p->stdCmdQueue, cfg2[_dpdSensitivity - 1],
                               DPD_CONFIG2_SIZE, WM_REG_DPD_CONFIG_BLOCK_2,
                               NULL);

            WPADiSendWriteDataCmd(&p->stdCmdQueue, command,
                                  WM_REG_DPD_DATA_FORMAT, NULL);
            WPADiSendWriteDataCmd(&p->stdCmdQueue, 0x08, WM_REG_DPD_30,
                                  &__dpdCb);

            WPADiSendGetContStat(&p->stdCmdQueue, NULL, pCallback);

            OSRestoreInterrupts(enabled);
            return WPAD_ERR_OK;
        }

        status = WPAD_ERR_COMMUNICATION_ERROR;

        OSRestoreInterrupts(enabled);
    }

_end:
    if (pCallback != NULL) {
        pCallback(chan, status);
    }

    return status;
}

static void __SendData(s32 chan, WPADCommand command) {
    BOOL enabled;
    BOOL rumble;
    s8 devHandle;
    WPADCB* p;
    UINT8 reportID;
    BT_HDR* pBuffer;
    u8* pRptData;
    s32 status;
    u8* pCmdData;
    UINT16 len;

    pBuffer = NULL;

    reportID = command.reportID;
    pCmdData = command.dataBuf;
    len = command.dataLength;

    enabled = OSDisableInterrupts();

    p = _wpdcb[chan];
    status = p->status;
    devHandle = p->devHandle;

    if (devHandle < 0) {
        OSRestoreInterrupts(enabled);
        return;
    }

    p->status = WPAD_ERR_COMMUNICATION_ERROR;
    rumble = p->motorRunning & _rumble;

    OSRestoreInterrupts(enabled);

    if (reportID == RPTID_SET_RUMBLE) {
        BOOL enabled = OSDisableInterrupts();

        p->status = status;

        OSRestoreInterrupts(enabled);
    } else if (reportID == RPTID_SEND_SPEAKER_DATA) {
        BOOL enabled = OSDisableInterrupts();

        p->status = status;
        p->audioFrames--;

        OSRestoreInterrupts(enabled);
    } else {
        enabled = OSDisableInterrupts();

        switch (reportID) {
        case RPTID_WRITE_DATA: {
            break;
        }

        case RPTID_READ_DATA: {
            p->wmReadHadError = 0;
            p->wmReadAddress = command.readAddress;
            p->wmReadLength = command.readLength;
            p->wmReadDataPtr = command.dstBuf;
            break;
        }

        case RPTID_REQUEST_STATUS: {
            p->status = status;
            p->wpInfoOut = command.statusReportOut;
            p->statusReqBusy = TRUE;
            break;
        }

        case 0xFF: { // wat
            u32 time;
            memcpy(&time, command.dataBuf, sizeof(u32));
            p->lastReportSendTime = __OSGetSystemTime() + time;
            p->UNK_0x910 = 1;
            return;
        }

        default: {
            pCmdData[0] |= (1 << RPT_OUT_FLAG_REQUEST_ACK_RPT);
            break;
        }
        }

        p->cmdBlkCB = command.cmdCB;
        p->lastReportID = reportID;
        p->lastReportSendTime = __OSGetSystemTime() + OS_SEC_TO_TICKS(2);
        p->UNK_0x910 = 0;

        OSRestoreInterrupts(enabled);
    }

    DEBUGPrint("handle = %d, repid = %02x\n", devHandle, reportID);

    pBuffer = GKI_getbuf((u8)(len + 18));
    pBuffer->len = (u8)(len + 1);
    pBuffer->offset = 10;

    pRptData = (u8*)(pBuffer) + sizeof(BT_HDR) + pBuffer->offset;
    pRptData[0] = reportID;
    memcpy(&pRptData[1], pCmdData, len);

    if (rumble) {
        pRptData[RPT_OUT_FLAGS] |= (1 << RPT_OUT_FLAG_RUMBLE);
    } else {
        pRptData[RPT_OUT_FLAGS] &= ~(1 << RPT_OUT_FLAG_RUMBLE);
    }

    BTA_HhSendData((UINT8)devHandle, pBuffer);
}

BOOL WPADiSendSetPort(WPADCommandQueue* pQueue, u8 port,
                      WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_SET_PORT;
    command.dataLength = RPT11_SIZE;
    command.dataBuf[RPT11_LED] = port << 4;
    command.cmdCB = pCallback;

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendSetReportType(WPADCommandQueue* pQueue, s32 format,
                            WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_SET_DATA_REPORT_MODE;
    command.dataLength = RPT12_SIZE;
    command.dataBuf[RPT12_CONT_REPORT] = 4; // Always continuous reporting
    command.cmdCB = pCallback;

    switch (format) {
    case WPAD_FMT_CORE_BTN: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN;
        break;
    }
    case WPAD_FMT_CORE_BTN_ACC: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC;
        break;
    }

    case WPAD_FMT_CORE_BTN_ACC_DPD: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD12;
        break;
    }

    case WPAD_FMT_FS_BTN: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_EXT8;
        break;
    }

    case WPAD_FMT_FS_BTN_ACC: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_EXT16;
        break;
    }

    case WPAD_FMT_FS_BTN_ACC_DPD: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD10_EXT9;
        break;
    }

    case WPAD_FMT_CLASSIC_BTN: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_EXT8;
        break;
    }

    case WPAD_FMT_CLASSIC_BTN_ACC: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_EXT16;
        break;
    }

    case WPAD_FMT_CLASSIC_BTN_ACC_DPD: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD10_EXT9;
        break;
    }

    case WPAD_FMT_BTN_ACC_DPD_EXTENDED: {
        command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD18_1;
        break;
    }
    }

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendEnableDPD(WPADCommandQueue* pQueue, BOOL enable,
                        WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_ENABLE_DPD;
    command.dataLength = RPT13_SIZE;
    command.dataBuf[RPT13_DPD_ENABLE] = enable ? 4 : 0;
    command.cmdCB = pCallback;

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendEnableSpeaker(WPADCommandQueue* pQueue, BOOL enable,
                            WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_ENABLE_SPEAKER;
    command.dataLength = RPT14_SIZE;
    command.dataBuf[RPT14_SPEAKER_ENABLE] = enable ? 4 : 0;
    command.cmdCB = pCallback;

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendGetContStat(WPADCommandQueue* pQueue, WPADInfo* pInfo,
                          WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_REQUEST_STATUS;
    command.dataLength = RPT15_SIZE;
    command.dataBuf[0] = 0;
    command.cmdCB = pCallback;
    command.statusReportOut = pInfo;

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendWriteDataCmd(WPADCommandQueue* pQueue, u8 cmd, u32 addr,
                           WPADCallback pCallback) {

    return WPADiSendWriteData(pQueue, &cmd, sizeof(u8), addr, pCallback);
}

BOOL WPADiSendWriteData(WPADCommandQueue* pQueue, const void* pSrc, u16 len,
                        u32 addr, WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;
    u8 packedLen = len & 31;

    command.reportID = RPTID_WRITE_DATA;
    command.dataLength = RPT16_SIZE;
    command.cmdCB = pCallback;
    memcpy(&command.dataBuf[RPT16_DATA_DST_ADDRESS], &addr, sizeof(u32));
    memcpy(&command.dataBuf[RPT16_DATA_LENGTH], &packedLen, sizeof(u8));
    memcpy(&command.dataBuf[RPT16_DATA], pSrc, len);

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendReadData(WPADCommandQueue* pQueue, void* pDst, u16 len, u32 addr,
                       WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_READ_DATA;
    command.dataLength = RPT17_SIZE;
    command.cmdCB = pCallback;
    memcpy(&command.dataBuf[RPT17_DATA_SRC_ADDRESS], &addr, sizeof(u32));
    memcpy(&command.dataBuf[RPT17_DATA_LENGTH], &len, sizeof(u16));
    command.dstBuf = pDst;
    command.readLength = len;
    command.readAddress = addr;

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendStreamData(WPADCommandQueue* pQueue, const void* pData, u16 len) {
    BOOL success;
    WPADCommand command;
    u8 packedLen = len << 3;

    command.reportID = RPTID_SEND_SPEAKER_DATA;
    command.dataLength = sizeof(command.dataBuf);
    command.dataBuf[RPT18_DATA_LENGTH] = packedLen;
    command.cmdCB = NULL;
    memcpy(&command.dataBuf[RPT18_DATA], pData, len);

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendMuteSpeaker(WPADCommandQueue* pQueue, BOOL mute,
                          WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_MUTE_SPEAKER;
    command.dataLength = RPT19_SIZE;
    command.dataBuf[RPT19_SPEAKER_MUTE] = mute ? 4 : 0;
    command.cmdCB = pCallback;

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL WPADiSendDPDCSB(WPADCommandQueue* pQueue, BOOL enable,
                     WPADCallback pCallback) {
    BOOL success;
    WPADCommand command;

    command.reportID = RPTID_SEND_DPD_CSB;
    command.dataLength = RPT1A_SIZE;
    command.dataBuf[RPT1A_DPD_CSB] = enable ? 4 : 0;
    command.cmdCB = pCallback;

    success = WPADiPushCommand(pQueue, command);
    return success;
}

BOOL __CanPushCmdQueue(const WPADCommandQueue* pQueue, s8 num) {
    s8 queueSize = __GetCmdNumber(pQueue);

    if ((u32)(queueSize + num) <= pQueue->capacity - 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}



s8 __GetCmdNumber(const WPADCommandQueue* pQueue) {
    BOOL enabled;
    s8 remain;

    enabled = OSDisableInterrupts();

    remain = pQueue->back - pQueue->front;
    if (remain < 0) {
        remain += pQueue->capacity;
    }

    OSRestoreInterrupts(enabled);

    return remain;
}

#pragma section ".text"
// WPADiClearQueue is defined in the GX auto-block
DECOMP_FORCEACTIVE(WPAD_c, "WPADiClearQueue");
extern void WPADiClearQueue(WPADCommandQueue* pQueue);
//void WPADiClearQueue(WPADCommandQueue* pQueue) {
//    BOOL enabled = OSDisableInterrupts();
//
//    pQueue->front = 0;
//    pQueue->back = 0;
//    memset(pQueue->buffer, 0, pQueue->capacity * sizeof(WPADCommand));
//
//    OSRestoreInterrupts(enabled);
//}

BOOL WPADiPushCommand(WPADCommandQueue* pQueue, WPADCommand command) {
    BOOL enabled = OSDisableInterrupts();

    if (pQueue->capacity - 1 == __GetCmdNumber(pQueue)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    // @bug Useless memset
    memset(&pQueue->buffer[pQueue->back], 0, sizeof(WPADCommand));
    memcpy(&pQueue->buffer[pQueue->back], &command, sizeof(WPADCommand));

    pQueue->back = pQueue->back == pQueue->capacity - 1 ? 0 : pQueue->back + 1;

    OSRestoreInterrupts(enabled);

    return TRUE;
}

BOOL WPADiGetCommand(const WPADCommandQueue* pQueue, WPADCommand* pCommand) {
    BOOL enabled = OSDisableInterrupts();

    if (__GetCmdNumber(pQueue) == 0) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    memcpy(pCommand, &pQueue->buffer[pQueue->front], sizeof(WPADCommand));

    OSRestoreInterrupts(enabled);
    return TRUE;
}

BOOL WPADiPopCommand(WPADCommandQueue* pQueue) {
    BOOL enabled = OSDisableInterrupts();

    if (__GetCmdNumber(pQueue) == 0) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    memset(&pQueue->buffer[pQueue->front], 0, sizeof(WPADCommand));

    pQueue->front =
        pQueue->front == pQueue->capacity - 1 ? 0 : pQueue->front + 1;

    OSRestoreInterrupts(enabled);

    return TRUE;
}

static void __SetScreenSaverFlag(BOOL disable) {
    if (disable) {
        __VIResetRFIdle();
    }
}

static u8 __GetDpdSensitivity(void) {
    u8 result = SCGetBtDpdSensibility();

    if (result < WPAD_MIN_DPD_SENS) {
        result = WPAD_MIN_DPD_SENS;
    }

    if (result > WPAD_MAX_DPD_SENS) {
        result = WPAD_MAX_DPD_SENS;
    }

    return result;
}

static u8 __GetSensorBarPosition(void) {
    // SC_SENSOR_BAR_TOP ? WPAD_SENSOR_BAR_TOP : WPAD_SENSOR_BAR_BOTTOM
    return !!(SCGetWpadSensorBarPosition() == 1);
}

static u32 __GetMotorMode(void) {
    // SC_MOTOR_ON ? WPAD_MOTOR_ON : WPAD_MOTOR_OFF
    return !!(SCGetWpadMotorMode() == 1);
}

static u8 __ClampSpeakerVolume(u8 volume) {
    u8 result = volume;

    if (volume <= 0) {
        result = 0;
    }

    if (volume >= WPAD_MAX_SPEAKER_VOLUME) {
        result = WPAD_MAX_SPEAKER_VOLUME;
    }

    return result;
}

static u8 __GetSpeakerVolume(void) {
    u8 volume = SCGetWpadSpeakerVolume();
    return __ClampSpeakerVolume(volume);
}





u16 _WPADGetStackBufferStatus(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled;
    s32 status;
    s8 handle;

    enabled = OSDisableInterrupts();
    status = p->status;
    handle = p->devHandle;
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        return 0;
    }

    return _WUDGetQueuedSize(handle);
}

u16 _WPADGetModuleBufferStatus(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL enabled;
    s32 status;
    s8 handle;

    enabled = OSDisableInterrupts();
    status = p->status;
    handle = p->devHandle;
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        return 0;
    }

    return _WUDGetNotAckedSize(handle);
}

void WPADRecalibrate(s32 chan) {
    WPADCB* p = _wpdcb[chan];
    BOOL enable = OSDisableInterrupts();

    p->calibrated = FALSE;

    OSRestoreInterrupts(enable);
}

// These functions are in the carved WPAD auto-block but not in the source.
// The pre-built auto-block .o is not resolving them, so we implement them.

// WUD internal functions referenced by WPAD
extern void fn_8006A7D0(void);
extern s32 fn_8006A940(void);
extern void fn_8006AC4C(void);
extern void fn_8006ADC4(void*);
extern void fn_8006A81C(void);

// WPADCB pointer table
extern WPADCB* lbl_8038F4F0[WPAD_MAX_CONTROLLERS];
extern WPADCB* _wpdcb[WPAD_MAX_CONTROLLERS];

// Global flags
extern u8 lbl_8055DC05;
#define _reset lbl_8055DC05 /* WPADReset guard: set once the subsystem is torn down */
extern void* lbl_8055DC14;
extern u8 lbl_80393058[0x468];
extern OSAlarm lbl_8038F4C0;
extern u8 lbl_8055DC19;
extern u8 lbl_8055DC12;

/* WPAD-internal callback installer: tail-calls fn_8006A7D0, which stores the
   two callbacks the caller passes into the WUD control block during input
   initialization (the caller's argument registers flow through the tail call). */
void fn_8005EE78(void) { fn_8006A7D0(); }

/* WPAD-internal WUD library-status getter: tail-calls fn_8006A940 so its
   status byte reaches the caller in r3; input initialization polls this until
   the library reports ready (status 3). */
void fn_8005EE7C(void) { fn_8006A940(); }

/* Return the cached DPD (pointer) sensitivity (1-5), loaded from System Config.
   Callers add this to 1.0 to scale the maximum cursor error distance. */
u8 fn_80062458(void) {
    return lbl_8055DC19;
}

// fn_8005D0DC: WUD initialization helper
#pragma push
#pragma opt_propagation off
/* WPAD's registered shutdown handler (the OSShutdownFunctionInfo at
 * lbl_80312130, priority 0x7f).  OS calls every registered handler once with
 * final == FALSE and then again with final == TRUE; returning TRUE means
 * "nothing of mine is left to wait for", so the final pass always returns it.
 * On the first pass, once the WUD library is up (status 2 or 3), a fatal
 * error, shutdown or reset (events 0, 2, 3) runs the full WPAD reset: hide
 * the devices, wipe the four controller slots out of the System Config
 * Bluetooth array, cancel the manager alarm, clear the HID receive callback
 * and shut WUD down.  A restart, return-to-menu or app launch (events 1, 4,
 * 5, 6) only asks the Bluetooth device manager to stop before the same alarm,
 * callback and WUD shutdown.  Both paths run at most once (_reset). */
BOOL fn_8005D0DC(BOOL final, s32 event) {
    #define WUDGetStatus          fn_8006A940 /* library status, WUD block +0x688 */
    #define WUDSetHidRecvCallback fn_8006ADC4 /* debug-prints its own name */
    #define WUDShutdown           fn_8006A81C /* idem; re-arms the WUD alarm */
    #define BtaDmStop             fn_80073EA4 /* post the BTA DM request event */
    s32 i;
    void *pDev;
    WUDLibStatus status;
    BOOL ret = FALSE;

    status = WUDGetStatus();
    if (final == 0) {
        if (status == WUD_LIB_STATUS_2 || status == WUD_LIB_STATUS_3) {
            switch (event) {
            case OS_SD_EVENT_FATAL:
            case OS_SD_EVENT_SHUTDOWN:
            case OS_SD_EVENT_3:
                if (_reset == 0) {
                    _reset = 1;
                    WUDSetVisibility(FALSE, FALSE);
                    for (i = WUD_MAX_DEV_ENTRY_FOR_STD, pDev = &_scArray.devices[WUD_MAX_DEV_ENTRY_FOR_STD];
                         i < WUD_MAX_DEV_ENTRY_FOR_STD + WPAD_MAX_CONTROLLERS;
                         i++, pDev = (void *)((u8 *)pDev + sizeof(SCBtDeviceInfo))) {
                        memset(pDev, 0, sizeof(SCBtDeviceInfo));
                    }
                    OSCancelAlarm(&_managerAlarm);
                    WUDSetHidRecvCallback(NULL);
                    WUDShutdown();
                }
                ret = FALSE;
                break;
            case OS_SD_EVENT_1:
            case OS_SD_EVENT_RESTART:
            case OS_SD_EVENT_RETURN_TO_MENU:
            case OS_SD_EVENT_LAUNCH_APP:
                if (_reset == 0) {
                    _reset = 1;
                    BtaDmStop();
                    OSCancelAlarm(&_managerAlarm);
                    WUDSetHidRecvCallback(NULL);
                    WUDShutdown();
                }
                ret = FALSE;
                break;
            }
        } else if (status == WUD_LIB_STATUS_4 || status == WUD_LIB_STATUS_1) {
            ret = FALSE;
        } else if (status == WUD_LIB_STATUS_0) {
            ret = TRUE;
        }
    } else {
        ret = TRUE;
    }
    return ret;
    #undef WUDGetStatus
    #undef WUDSetHidRecvCallback
    #undef WUDShutdown
    #undef BtaDmStop
}
#pragma pop

/* WPADiSendGameInfoReport: hand one output report to the Wiimote on this channel.
 * pInfo is really a WPADCommand* (the manager pops one off the channel's
 * command queue and passes it here).
 *
 * Ready channel (readStatus WPAD_ERR_OK and no report request outstanding):
 * copy the command word by word into a local and pass that to __SendData
 * (WPADiSendOutputReport), which builds the HID report and sends it - the copy keeps
 * __SendData from touching the queue entry the caller still owns.
 * A leftover WPAD_ERR_TRANSFER is cleared back to WPAD_ERR_OK so the next read
 * can start.  While the channel is busy, a command whose deadline (+0x848,
 * armed by __SendData from the WPAD timeout) passed more than a second ago is
 * given up on: the deadline is restarted and, unless the link is already being
 * torn down (+0x8C6), the HID connection is dropped with BTA_HhClose.  A
 * deadline that belongs to a 0xFF delay request (+0x850) only reports
 * WPAD_ERR_TRANSFER instead.  The status for the caller is returned. */
#pragma opt_propagation off
s32 WPADiSendGameInfoReport(s32 chan, WPADGameInfo *pCommand)
{
#define s_wpadControlBlocks lbl_8038F4F0
#define s_wpadTimeout lbl_8055DC1A
  s32 status;
  s32 controlOffset = chan * 4;
  WPADCB *controlBlock;
  WPADCB **controlBlocks = s_wpadControlBlocks;
  WPADCB *deadlineBlock;
  BOOL irqState;
  u8 statusRequestPending;
  u32 commandWords[12];
  controlBlock = *(WPADCB **)((u8 *)controlBlocks + controlOffset);
  irqState = OSDisableInterrupts();
  status = controlBlock->readStatus;
  OSRestoreInterrupts(irqState);
  if (status == WPAD_ERR_OK)
  {
    irqState = OSDisableInterrupts();
    statusRequestPending = controlBlock->statusReqPending;
    OSRestoreInterrupts(irqState);
    if (statusRequestPending != 0)
    {
      status = WPAD_ERR_BUSY;
    }
    else
    {
      u32 *source = (u32 *) pCommand;
      u32 w11;
      u32 w10;
      u32 w9;
      u32 w8;
      u32 w7;
      u32 w6;
      u32 w5;
      u32 w4;
      u32 w3;
      u32 w0;
      u32 w1;
      u32 w2;
      w0 = source[0];
      w1 = source[1];
      w2 = source[2];
      w3 = source[3];
      w4 = source[4];
      w5 = source[5];
      w6 = source[6];
      w7 = source[7];
      w8 = source[8];
      w9 = source[9];
      w10 = source[10];
      w11 = source[11];
      commandWords[0] = w0;
      commandWords[1] = w1;
      commandWords[2] = w2;
      commandWords[3] = w3;
      commandWords[4] = w4;
      commandWords[5] = w5;
      commandWords[6] = w6;
      commandWords[7] = w7;
      commandWords[8] = w8;
      commandWords[9] = w9;
      commandWords[10] = w10;
      commandWords[11] = w11;
      WPADiSendOutputReport(chan, (WPADGameInfo *) commandWords);
    }
  }
  else
    if (status != WPAD_ERR_BUSY)
  {
    if (status == WPAD_ERR_TRANSFER)
  {
    irqState = OSDisableInterrupts();
    controlBlock->readStatus = WPAD_ERR_OK;
    OSRestoreInterrupts(irqState);
  }
  }
  else
    if ((((s32) ((__OSGetSystemTime() - (*((s64 *) (((u8 *) controlBlock) + 0x848)))) / ((*((u32 *) 0x800000F8)) / 4))) > 1) && (s_wpadTimeout != 0))
  {
    if ((*((u8 *) (((u8 *) controlBlock) + 0x850))) == 0)
    {
      s32 controlStatus;
      WPADCB *controlAgain;
      deadlineBlock = controlBlock;
      *((s64 *) (((u8 *) deadlineBlock) + 0x848)) = __OSGetSystemTime();
      controlAgain = *(WPADCB **)((u8 *)controlBlocks + controlOffset);
      irqState = OSDisableInterrupts();
      controlStatus = controlAgain->readStatus;
      OSRestoreInterrupts(irqState);
      if (controlStatus != WPAD_ERR_NO_CONTROLLER)
      {
        irqState = OSDisableInterrupts();
        if (((u8 *) controlAgain)[0x8C6])
        {
          OSRestoreInterrupts(irqState);
        }
        else
        {
          ((u8 *) controlAgain)[0x8C6] = TRUE;
          OSRestoreInterrupts(irqState);
          BTA_HhClose(((u8 *) controlAgain)[0x803]);
        }
      }
    }
    else
    {
      irqState = OSDisableInterrupts();
      controlBlock->readStatus = WPAD_ERR_TRANSFER;
      OSRestoreInterrupts(irqState);
    }
  }
  return status;
}
#pragma opt_propagation reset

/*
 * WPAD library state that the game's symbol table leaves unnamed (.sbss
 * 0x8055DBFD and 0x8055DC00, .data 0x80312130 and 0x80312158). The named WPAD
 * statics next to them (_regShutdown, _senseCnt, _sleepTime, ...) are declared
 * at the top of this file.
 */
#define wpd_ext_count       lbl_8055DBFD /* u8: 5-tick gate for the extension command queue */
#define wpd_game_code_count lbl_8055DC00 /* u8[4]: per-channel 5-tick gate to resend the game code */
#define wpd_shutdown_info   lbl_80312130 /* OSShutdownFunctionInfo: fn_8005D0DC, priority 0x7f */
#define wpd_init_msg        lbl_80312158 /* "WPADInit()\n" */

// WPADInit(): bring up the WPAD library. Registers the library's shutdown
// function, starts the Bluetooth stack (WUDInit), powers on the sensor bar,
// clears the four control blocks, copies the DPD sensitivity / sensor bar
// position / motor mode / speaker volume out of the System Configuration and
// starts the 1 ms management alarm.
void fn_8005EB44(void) {
    register u8* p_wpd asm("r29");    // &(_wpd[chan])
    register u8* p_wpdcb asm("r28");  // &(_wpdcb[chan])
    register u8* p_active asm("r27"); // &(_chan_active_state[chan])
    register s32 chan asm("r26");
    register s32 zero asm("r30") = 0;
    s32 i;
    u8 sens;
    u8 vol;
    BOOL enabled;

    if (!_regShutdown) {
        OSRegisterShutdownFunction(&wpd_shutdown_info);
        _regShutdown = TRUE;
    }

    if (!WUDInit()) {
        return;
    }

    enabled = OSDisableInterrupts();
    IPC_HW_REGS_PPC[IPC_GPIO1BOUT] |= GPIO_SENSORBAR; // sensor bar power on
    OSRestoreInterrupts(enabled);

    for (i = 0; i < WUD_MAX_DEV_ENTRY; i++) {
        _dev_handle_index[i] = WUD_DEV_HANDLE_INVALID;
    }

    DBPrintf_80068D68(wpd_init_msg);

    p_wpd = (u8*)&_wpd[0];
    p_wpdcb = (u8*)&_wpdcb[0];
    chan = WPAD_CHAN0;
    p_active = _chan_active_state;
    do {
        *(void**)p_wpdcb = p_wpd;
        *p_active = zero;
        *(void**)(*(u8**)p_wpdcb + 0x7E4) = (void*)zero; // samplingCB
        __ClearControlBlock(chan);
        OSInitThreadQueue((OSThreadQueue*)(p_wpd + 0x824)); // threadQueue
        chan++;
        p_wpd += 0x8E0; // sizeof(WPADCB) of this WPAD build
        p_wpdcb += 4;
        p_active++;
    } while (chan < WPAD_MAX_CONTROLLERS);

    _sleepTime = 5;
    _gamecode = OSGetAppGamename();
    _gametype = OSGetAppType();

    sens = SCGetBtDpdSensibility();
    if (sens < WPAD_MIN_DPD_SENS) {
        sens = WPAD_MIN_DPD_SENS;
    }
    if (sens > WPAD_MAX_DPD_SENS) {
        sens = WPAD_MAX_DPD_SENS;
    }
    _dpdSensitivity = sens;

    _sensorBarPos = (SCGetWpadSensorBarPosition() == SC_SENSOR_BAR_TOP);
    _rumble = (SCGetWpadMotorMode() == 1);

    vol = SCGetWpadSpeakerVolume();
    if (vol > WPAD_MAX_SPEAKER_VOLUME) {
        vol = WPAD_MAX_SPEAKER_VOLUME;
    }
    _speakerVolume = vol;

    WUDSetHidConnCallback(WPADiConnCallback);
    WUDSetHidRecvCallback(WPADiRecvCallback);

    _senseCnt = zero;
    _checkCnt = zero;
    wpd_ext_count = zero;
    _afhCnt = zero;
    wpd_game_code_count[3] = zero;
    wpd_game_code_count[2] = zero;
    wpd_game_code_count[1] = zero;
    wpd_game_code_count[0] = zero;

    OSCreateAlarm(&_managerAlarm);
    OSSetPeriodicAlarm(&_managerAlarm, OSGetTime(), OS_MSEC_TO_TICKS(1), WPADiManageHandler0);

    _shutdown = zero;
    _scFlush = zero;
    _scSetting = TRUE;
    _afhChannel = WPAD_CHAN_INVALID;

    OSRegisterVersion(__WPADVersion);
}

// WPADReset: tear the Wii controller subsystem down once - hide the devices,
// wipe the four paired-controller slots from the SC Bluetooth device array,
// cancel the manager alarm, then drop the HID receive callback and shut the
// WUD library down so it can be brought back up.
void fn_8005ED8C(void) {
    if (_reset == 0) {
        void* pDev;
        s32 i;

        _reset = 1;
        WUDSetVisibility(0, 0);

        for (i = WUD_MAX_DEV_ENTRY_FOR_STD, pDev = &_scArray.devices[WUD_MAX_DEV_ENTRY_FOR_STD];
             i < WUD_MAX_DEV_ENTRY_FOR_STD + WPAD_MAX_CONTROLLERS;
             i++, pDev = (void*)((u8*)pDev + sizeof(SCBtDeviceInfo))) {
            memset(pDev, 0, sizeof(SCBtDeviceInfo));
        }

        OSCancelAlarm(&_managerAlarm);
        fn_8006ADC4(NULL);
        fn_8006A81C();
    }
}

// Tear down the active WPAD manager state once (alarm and HID callbacks)
// without the device-list clear performed by the full WPAD reset path.
void fn_8005EE20(void) {
    if (lbl_8055DC05 == 0) {
        lbl_8055DC05 = 1;
        fn_80073EA4();
        OSCancelAlarm(&lbl_8038F4C0);
        fn_8006ADC4(0);
        fn_8006A81C();
    }
}

/* WPAD-internal fast-simple-sync starter: tail-calls WUDStartFastSyncSimple so
   its result reaches callers such as the home-button sync-check alarm callback
   (which casts this to an s32-returning function). */
/* Tail-call thunk forwarding to WUDStartFastSyncSimple to start a simple fast wireless sync. */ /* Tail-call thunk forwarding to WUDStartFastSyncSimple to start a simple fast wireless sync. */ /* Tail-call thunk forwarding to WUDStartFastSyncSimple to start a simple fast wireless sync. */ void fn_8005EE6C(void) { WUDStartFastSyncSimple(); }

/* WPAD-internal fast-simple-sync stopper: tail-calls fn_8006AC4C, which stops
   the simple-sync loop when the WUD library is running and reports whether it
   was active (the home-button sync-check alarm callback reads that result). */
void fn_8005EE70(void) { fn_8006AC4C(); }

/* WPAD-internal wrapper: tail-calls WUDSetSyncSimpleCallback to install the simple-sync
 * callback (the previous callback, returned in r3, still reaches the caller). */
void fn_8005EE74(WUDSyncDeviceCallback pCallback) { WUDSetSyncSimpleCallback(pCallback); }

/* Get the HID device handle for the specified channel (interrupt-protected). */
u8 fn_8005EE80(s32 chan)
{
    WPADCB* controlBlock = lbl_8038F4F0[chan];
    BOOL interruptsDisabled = OSDisableInterrupts();
    u8 deviceHandle = controlBlock->devHandle;
    OSRestoreInterrupts(interruptsDisabled);
    return deviceHandle;
}

void fn_8005EEC4(s32 chan, s32 result) {
    u16 val16;
    u32 val32;
    u32 word;
    u32 w;
    u16 ch;
    u32 v;
    WPADCB *cb = lbl_8038F4F0[chan];
    u8 *queue = (u8 *)cb + 0x160;
    u8 buf[0x68] ALIGN(8);
    s8 diff;
    BOOL enabled;
    BOOL innerEnabled;
    s8 index;
    s32 lastIndex;
    s32 wrapMask;
    if (result == -1) return;
    if (result == 0) {
        *(u32 *)((u8 *)cb + 0x81c) = 1;
        if (*(void **)((u8 *)cb + 0x7e4) != 0) (*(void (**)(void))((u8 *)cb + 0x7e4))();
        return;
    }
    val32 = *(u32 *)((u8 *)cb + 0x820);
    val16 = 0x2a;
    if (val32 != 0) val16 = 0x14;
    word = val32;
    word = (u32)(((s32)(-(s32)word | (s32)word) >> 31) & 0x176c);
    *(u16 *)&buf[0] = val16;
    *(u32 *)&buf[4] = word;
    *(u32 *)&buf[8] = 0x17;
    *(u16 *)&buf[0x22] = 6;
    *(u32 *)&buf[0x34] = (u32)fn_8005EEC4;
    memcpy(&buf[0x0c], &buf[4], 4);
    memcpy(&buf[0x10], &buf[0], 2);
    ch = *(u16 *)&buf[0];
    v = (u32)((u8 *)cb + 0x874);
    w = *(u32 *)&buf[4];
    *(u32 *)&buf[0x24] = v;
    *(double *)&buf[0x38] = *(double *)&buf[8];
    *(double *)&buf[0x40] = *(double *)&buf[0x10];
    *(double *)&buf[0x48] = *(double *)&buf[0x18];
    *(double *)&buf[0x50] = *(double *)&buf[0x20];
    *(u16 *)&buf[0x28] = ch;
    *(u32 *)&buf[0x2c] = w;
    *(double *)&buf[0x58] = *(double *)&buf[0x28];
    *(double *)&buf[0x60] = *(double *)&buf[0x30];
    enabled = OSDisableInterrupts();
    innerEnabled = OSDisableInterrupts();
    diff = (s8)(queue[1] - queue[0]);
    if (diff < 0) diff = (s8)(diff + *(u32 *)(queue + 8));
    OSRestoreInterrupts(innerEnabled);
    if (*(u32 *)(queue + 8) - 1 == (u32)diff) { OSRestoreInterrupts(enabled); return; }
    memset(*(u8 **)(queue + 4) + (s8)queue[1] * 0x30, 0, 0x30);
    memcpy(*(u8 **)(queue + 4) + (s8)queue[1] * 0x30, buf + 0x38, 0x30);
    index = (s8)queue[1];
    lastIndex = *(u32 *)(queue + 8) - 1;
    wrapMask = ~(((s32)index - lastIndex) | (lastIndex - (s32)index)) >> 31;
    queue[1] = (index + 1) & ~wrapMask;
    OSRestoreInterrupts(enabled);
}

/* WPAD's retry callback for the first game-info block: when that read ends in a
 * transfer error, queue the very same read of WM_ADDR_MEM_GAME_INFO_0 again,
 * with this same callback on it, so WPAD keeps trying until the Wii Remote
 * answers.  Every other result is ignored. */
/* On a transfer error, requeue the first game-info block read with this same callback so WPAD retries until the Remote answers. */ void WPADiGameInfoReadRetry(s32 chan, s32 result) {
    WPADCB *cb = lbl_8038F4F0[chan];
    WPADCommandQueue *queue = &cb->stdCmdQueue;
    /* the WPADCommand built here (at buf + 8) and the copy of it that the
     * inlined WPADiPushCommand inserts (at buf + 0x38); the ring's front and
     * back indices are the queue's first two bytes */
    u8 buf[0x68] ALIGN(8);
    s8 diff;
    BOOL enabled;
    BOOL innerEnabled;
    u32 addr;
    u16 len;
    u32 dst;
    s8 index;
    s32 lastIndex;
    s32 wrapMask;
    if (result != WPAD_ERR_TRANSFER) return;
    /* WPADiSendReadData(queue, read buffer, sizeof(WPADGameInfo),
     * WM_ADDR_MEM_GAME_INFO_0, WPADiGameInfoReadRetry) inlined: the command's report ID,
     * payload length and callback, then its read address and length staged
     * where the two memcpys below can take their addresses. */
    *(u32 *)&buf[4] = WM_ADDR_MEM_GAME_INFO_0;
    *(u16 *)&buf[0] = sizeof(WPADGameInfo);
    *(u32 *)&buf[8] = RPTID_READ_DATA;                  /* command.reportID */
    *(u16 *)&buf[0x22] = RPT17_SIZE;                    /* command.dataLength */
    *(u32 *)&buf[0x34] = (u32)WPADiGameInfoReadRetry;              /* command.cmdCB: retry here */
    memcpy(&buf[0x0c], &buf[4], sizeof(u32));  /* command.dataBuf's read address */
    memcpy(&buf[0x10], &buf[0], sizeof(u16));  /* command.dataBuf's read length */
    len = *(u16 *)&buf[0];
    dst = (u32)((u8 *)cb + 0x874); /* command.dstBuf: cb's 0x40-byte Wii-memory read buffer */
    addr = *(u32 *)&buf[4];
    *(u32 *)&buf[0x24] = dst;                           /* command.dstBuf */
    *(double *)&buf[0x38] = *(double *)&buf[8];
    *(double *)&buf[0x40] = *(double *)&buf[0x10];
    *(double *)&buf[0x48] = *(double *)&buf[0x18];
    *(double *)&buf[0x50] = *(double *)&buf[0x20];
    *(u16 *)&buf[0x28] = len;                        /* command.readLength */
    *(u32 *)&buf[0x2c] = addr;                       /* command.readAddress */
    *(double *)&buf[0x58] = *(double *)&buf[0x28];
    *(double *)&buf[0x60] = *(double *)&buf[0x30];
    enabled = OSDisableInterrupts();
    /* WPADiPushCommand's "is the ring full?" test: back - front, wrapped by the
     * capacity; one slot short of the capacity means full.  The queue's first
     * two bytes are its front and back indices. */
    innerEnabled = OSDisableInterrupts();
    diff = (s8)(((u8 *)queue)[1] - ((u8 *)queue)[0]);
    if (diff < 0)
        diff = (s8)(diff + queue->capacity);
    OSRestoreInterrupts(innerEnabled);
    if (queue->capacity - 1 == (u32)diff) { /* the command ring is full */
        OSRestoreInterrupts(enabled);
        return;
    }
    memset(&queue->buffer[(s8)((u8 *)queue)[1]], 0, sizeof(WPADCommand));
    memcpy(&queue->buffer[(s8)((u8 *)queue)[1]], &buf[0x38], sizeof(WPADCommand));
    index = (s8)((u8 *)queue)[1];
    lastIndex = queue->capacity - 1;
    wrapMask = ~(((s32)index - lastIndex) | (lastIndex - (s32)index)) >> 31;
    ((u8 *)queue)[1] = (index + 1) & ~wrapMask; /* back, wrapped at the capacity */
    OSRestoreInterrupts(enabled);
}

/* WPAD's retry callback for the game-info read: when that read ends in a
 * transfer error, queue the very same read of the second game-info block
 * again, with this same callback on it.  Every other result is ignored. */
/* WPAD game-info read completion callback: on a transfer error, re-queues the same game-info block read (with itself as callback) on the controller's standard command ring; all other results are ignored. */ void WPADiRetryGameInfoRead(s32 chan, s32 result) {
    WPADCB *cb = lbl_8038F4F0[chan];
    WPADCommandQueue *queue = &cb->stdCmdQueue;
    /* the WPADCommand built here (at buf + 8) and the copy of it that the
     * inlined WPADiPushCommand inserts (at buf + 0x38); the ring's front and
     * back indices are the queue's first two bytes */
    u8 buf[0x68] ALIGN(8);
    s8 diff;
    BOOL enabled;
    BOOL innerEnabled;
    u32 addr;
    u16 len;
    u32 dst;
    s8 index;
    s32 lastIndex;
    s32 wrapMask;
    if (result != WPAD_ERR_TRANSFER) return;
    /* WPADiSendReadData(queue, cb's read buffer, sizeof(WPADGameInfo),
     * WM_ADDR_MEM_GAME_INFO_1, WPADiRetryGameInfoRead) inlined: the command's report ID,
     * payload length and callback, then its read address and length staged
     * where the two memcpys below can take their addresses. */
    *(u32 *)&buf[4] = WM_ADDR_MEM_GAME_INFO_1;
    *(u16 *)&buf[0] = sizeof(WPADGameInfo);
    *(u32 *)&buf[8] = RPTID_READ_DATA;                  /* command.reportID */
    *(u16 *)&buf[0x22] = RPT17_SIZE;                    /* command.dataLength */
    *(u32 *)&buf[0x34] = (u32)WPADiRetryGameInfoRead;              /* command.cmdCB */
    memcpy(&buf[0x0c], &buf[4], sizeof(u32));  /* command.dataBuf's read address */
    memcpy(&buf[0x10], &buf[0], sizeof(u16));  /* command.dataBuf's read length */
    len = *(u16 *)&buf[0];
    dst = (u32)((u8 *)cb + 0x874); /* command.dstBuf: cb's controller-read buffer */
    addr = *(u32 *)&buf[4];
    *(u32 *)&buf[0x24] = dst;                           /* command.dstBuf */
    *(double *)&buf[0x38] = *(double *)&buf[8];
    *(double *)&buf[0x40] = *(double *)&buf[0x10];
    *(double *)&buf[0x48] = *(double *)&buf[0x18];
    *(double *)&buf[0x50] = *(double *)&buf[0x20];
    *(u16 *)&buf[0x28] = len;                        /* command.readLength */
    *(u32 *)&buf[0x2c] = addr;                       /* command.readAddress */
    *(double *)&buf[0x58] = *(double *)&buf[0x28];
    *(double *)&buf[0x60] = *(double *)&buf[0x30];
    enabled = OSDisableInterrupts();
    innerEnabled = OSDisableInterrupts();
    diff = (s8)(((u8 *)queue)[1] - ((u8 *)queue)[0]);
    if (diff < 0)
        diff = (s8)(diff + queue->capacity);
    OSRestoreInterrupts(innerEnabled);
    if (queue->capacity - 1 == (u32)diff) { /* the command ring is full */
        OSRestoreInterrupts(enabled);
        return;
    }
    memset(&queue->buffer[(s8)((u8 *)queue)[1]], 0, sizeof(WPADCommand));
    memcpy(&queue->buffer[(s8)((u8 *)queue)[1]], &buf[0x38], sizeof(WPADCommand));
    index = (s8)((u8 *)queue)[1];
    lastIndex = queue->capacity - 1;
    wrapMask = ~(((s32)index - lastIndex) | (lastIndex - (s32)index)) >> 31;
    ((u8 *)queue)[1] = (index + 1) & ~wrapMask; /* back, wrapped at the capacity */
    OSRestoreInterrupts(enabled);
}

static inline void fn_8005F3E8_enqueue(WPADCB *cb, WPADCommand *cmd) {
    BOOL intr, intr2;
    s8 count;
    u8 back;
    s32 t4;
    intr = OSDisableInterrupts();
    intr2 = OSDisableInterrupts();
    count = (s8)(cb->stdCmdQueue.back - cb->stdCmdQueue.front);
    if (count < 0) count += cb->stdCmdQueue.capacity;
    OSRestoreInterrupts(intr2);
    if ((u32)(cb->stdCmdQueue.capacity - 1) == (u32)count) {
        OSRestoreInterrupts(intr);
        return;
    }
    memset((u8 *)cb->stdCmdQueue.buffer + (s8)cb->stdCmdQueue.back * 0x30, 0, 0x30);
    memcpy((u8 *)cb->stdCmdQueue.buffer + (s8)cb->stdCmdQueue.back * 0x30, cmd, 0x30);
    back = cb->stdCmdQueue.back;
    t4 = cb->stdCmdQueue.capacity - 1;
    count = (s8)back - t4;
    count = (s32)~(count | (t4 - (s8)back)) >> 0x1F;
    cb->stdCmdQueue.back = (u8)(((s8)back + 1) & ~count);
    OSRestoreInterrupts(intr);
}

void fn_8005F3E8(s32 chan, s32 arg1) {
    WPADCB *cb;
    BOOL intr;
    WPADCommand cmd;
    s32 v;
    s32 r31;

    cb = _wpdcb[chan];
    if (arg1 == -1) return;
    intr = OSDisableInterrupts();
    cb->UNK_0x820 = (arg1 == 0) ? 1 : 0;
    cb->readStatus = 0;
    OSRestoreInterrupts(intr);
    r31 = (arg1 == 0) ? 0x14 : 0x2a;
    v = (arg1 == 0) ? 0x176c : 0;
    DBPrintf_80068D68(lbl_80312164, (cb->UNK_0x820 != 0) ? lbl_80558FE4 : lbl_8031219C);
    fn_80063564(&cb->stdCmdQueue, 0, 0);

    memset(&cmd, 0, 0x30);
    cmd.reportID = 0x1a;
    cmd.dataLength = 1;
    fn_8005F3E8_enqueue(cb, &cmd);

    memset(&cmd, 0, 0x30);
    cmd.reportID = 0x11;
    cmd.dataBuf[0] = (u8)(((1 << chan) * 0x10) & 0xf0);
    cmd.dataLength = 1;
    fn_8005F3E8_enqueue(cb, &cmd);

    memset(&cmd, 0, 0x30);
    cmd.dataBuf[0] = 0x2a; cmd.dataBuf[1] = 0x38; cmd.dataBuf[2] = 0x17; cmd.dataBuf[3] = 6;
    cmd.reportID = 0x2a;
    cmd.dataLength = 0x38;
    cmd.dstBuf = (void *)((u8 *)cb + 0x874);
    cmd.readLength = 6;
    cmd.cmdCB = (WPADCallback)WPADiGameInfoReadRetry;
    fn_8005F3E8_enqueue(cb, &cmd);

    memset(&cmd, 0, 0x30);
    cmd.dataBuf[0] = 0x62; cmd.dataBuf[1] = 0x38; cmd.dataBuf[2] = 0x17; cmd.dataBuf[3] = 6;
    cmd.reportID = 0x62;
    cmd.dataLength = 0x38;
    cmd.dstBuf = (void *)((u8 *)cb + 0x874);
    cmd.readLength = 6;
    cmd.cmdCB = (WPADCallback)WPADiRetryGameInfoRead;
    fn_8005F3E8_enqueue(cb, &cmd);

    memset(&cmd, 0, 0x30);
    cmd.dataBuf[0] = (u8)r31; cmd.dataBuf[1] = 0x38; cmd.dataBuf[2] = 0x17; cmd.dataBuf[3] = 6;
    cmd.reportID = r31;
    cmd.dataLength = 0x38;
    cmd.dstBuf = (void *)((u8 *)cb + 0x874);
    cmd.readLength = 6;
    cmd.cmdCB = (WPADCallback)fn_8005EEC4;
    fn_8005F3E8_enqueue(cb, &cmd);

    memset(&cmd, 0, 0x30);
    cmd.reportID = 0x15;
    cmd.dataLength = 1;
    fn_8005F3E8_enqueue(cb, &cmd);
}

/* Assign a WPAD channel to a newly connected controller. Reuse the channel whose saved
   Bluetooth address matches this device if it is still free; otherwise claim the first
   free channel, record the address there and flag the BT info for saving. */
s32 fn_8005FBCC(u8 devHandle) {
#define chanInUse    lbl_8055DC08
#define btInfoArray  lbl_80393058
#define btInfoDirty  lbl_8055DC11
    BD_ADDR_PTR devAddr;
    int chan;
    devAddr = _WUDGetDevAddr(devHandle);
    for (chan = 0; chan < WPAD_MAX_CONTROLLERS; chan++) {
        if (memcmp(btInfoArray + (chan + 10) * 0x46 + 1, devAddr, 6) != 0) {
            continue;
        }
        if (chanInUse[chan]) {
            continue;
        }
        chanInUse[chan] = TRUE;
        return chan;
    }
    for (chan = 0; chan < WPAD_MAX_CONTROLLERS; chan++) {
        if (chanInUse[chan]) {
            continue;
        }
        chanInUse[chan] = TRUE;
        memcpy(btInfoArray + (chan + 10) * 0x46 + 1, devAddr, 6);
        btInfoDirty = TRUE;
        return chan;
    }
    return WPAD_CHAN_INVALID;
#undef chanInUse
#undef btInfoArray
#undef btInfoDirty
}
/* HID connect/disconnect callback: on connect, claim a channel for the Wii
 * Remote, reset its control block and queue the extension/firmware probe
 * read; on disconnect, drain the channel's command queue (answering every
 * callback with WPAD_ERR_NO_CONTROLLER), tear the channel down and release it. */
/* WPAD HID connect/disconnect callback: on connect, claim and reset a channel and queue the extension/firmware probe read; on disconnect, answer every queued command with WPAD_ERR_NO_CONTROLLER, tear down the channel and release it. */ void wpadConnectionCallback(u8 devHandle, u8 open) {
    extern void WPADiResetChannel_8005E8E0(s32 chan);
    extern const char lbl_803120E0[];
    extern s8 lbl_80390500[];
    extern void fn_8005F3E8(s32, s32);
    extern s32 fn_8005B00C(void);
    /* WPAD debug string block; the branch messages are at fixed offsets. */
    const char* msgBase = lbl_803120E0;
    BOOL hasCommand;
    s32 chan;
    WPADCommand command;
    WPADCommand queuedCommand ALIGN(8);
    WPADCommand readCommand ALIGN(8);
    WPADCB* cb;
    s8 indexByte;
    s32 index;
    s32 lastIndex;
    s32 wrapMask;

    if (open) {
        DBPrintf_80068D68(msgBase + 0xCC);
        chan = fn_8005FBCC(devHandle);
        cb = lbl_8038F4F0[chan];
        lbl_80390500[devHandle] = chan;
        WPADiResetChannel_8005E8E0(chan);
        cb->extDevHandle = devHandle;
        cb->UNK_0x801 = 0;
        cb->readFormat = WPAD_FMT_CORE_BTN;
        cb->connected = TRUE;
        cb->readStatus = WPAD_ERR_OK;
        cb->devHandle = 100;
        /* 0x8C6 is an unnamed byte inside the control block. */
        ((u8*)cb)[0x8C6] = FALSE;
        {
            u32 readAddress = WM_ADDR_MEM_1770;
            u16 readLength = 1;
            BOOL intrEnabled;
            readCommand.reportID = 0x17;
            readCommand.dataLength = 6;
            readCommand.cmdCB = fn_8005F3E8;
            memcpy(readCommand.dataBuf, &readAddress, 4);
            memcpy(readCommand.dataBuf + 4, &readLength, 2);
            /* Where the identifier byte read back from the extension lands. */
            readCommand.dstBuf = (u8*)cb + 0x874;
            readCommand.readLength = readLength;
            readCommand.readAddress = readAddress;
            *(f64*)((u8*)&queuedCommand + 0) = *(f64*)((u8*)&readCommand + 0);
            *(f64*)((u8*)&queuedCommand + 8) = *(f64*)((u8*)&readCommand + 8);
            *(f64*)((u8*)&queuedCommand + 16) = *(f64*)((u8*)&readCommand + 16);
            *(f64*)((u8*)&queuedCommand + 24) = *(f64*)((u8*)&readCommand + 24);
            *(f64*)((u8*)&queuedCommand + 32) = *(f64*)((u8*)&readCommand + 32);
            *(f64*)((u8*)&queuedCommand + 40) = *(f64*)((u8*)&readCommand + 40);
            intrEnabled = OSDisableInterrupts();
            {
            s8 count;
            BOOL savedIntr = OSDisableInterrupts();
            count = cb->stdCmdQueue.back - cb->stdCmdQueue.front;
            if (count < 0) count += cb->stdCmdQueue.capacity;
            OSRestoreInterrupts(savedIntr);
            if (cb->stdCmdQueue.capacity - 1 == count) {
                OSRestoreInterrupts(intrEnabled);
            } else {
                memset(&cb->stdCmdQueue.buffer[cb->stdCmdQueue.back], 0, sizeof(WPADCommand));
                memcpy(&cb->stdCmdQueue.buffer[cb->stdCmdQueue.back], &queuedCommand, sizeof(WPADCommand));
                indexByte = cb->stdCmdQueue.back;
                index = indexByte;
                lastIndex = cb->stdCmdQueue.capacity - 1;
                wrapMask = ~(((s32)index - lastIndex) | (lastIndex - (s32)index)) >> 31;
                cb->stdCmdQueue.back = (index + 1) & ~wrapMask;
                OSRestoreInterrupts(intrEnabled);
            }
            }
        }
        fn_8005B00C();
    } else {
        DBPrintf_80068D68(msgBase + 0xE4);
        chan = lbl_80390500[devHandle];
        lbl_80390500[devHandle] = WUD_DEV_HANDLE_INVALID;
        if (chan != WUD_DEV_HANDLE_INVALID) {
            cb = lbl_8038F4F0[chan];
            cb->readStatus = WPAD_ERR_NO_CONTROLLER;
            if (cb->readCB != NULL) {
                cb->readCB(chan, WPAD_ERR_NO_CONTROLLER);
            } else if (*(WPADCallback*)(lbl_80392900 + chan * 0x14 + 0x10) != NULL) {
                (*(WPADCallback*)(lbl_80392900 + chan * 0x14 + 0x10))(chan, WPAD_ERR_NO_CONTROLLER);
            }
            do {
                {
                    s8 count;
                    BOOL intrEnabled = OSDisableInterrupts();
                    BOOL savedIntr = OSDisableInterrupts();
                    count = cb->stdCmdQueue.back - cb->stdCmdQueue.front;
                    if (count < 0) count += cb->stdCmdQueue.capacity;
                    OSRestoreInterrupts(savedIntr);
                    if (count == 0) {
                        OSRestoreInterrupts(intrEnabled);
                        hasCommand = FALSE;
                    } else {
                        memcpy(&command, &cb->stdCmdQueue.buffer[cb->stdCmdQueue.front], sizeof(WPADCommand));
                        OSRestoreInterrupts(intrEnabled);
                        hasCommand = TRUE;
                    }
                }
                if (hasCommand) {
                    if (command.cmdCB != NULL) {
                        command.cmdCB(chan, WPAD_ERR_NO_CONTROLLER);
                    }
                    {
                        s8 count;
                        BOOL intrEnabled = OSDisableInterrupts();
                    BOOL savedIntr = OSDisableInterrupts();
                    count = cb->stdCmdQueue.back - cb->stdCmdQueue.front;
                    if (count < 0) count += cb->stdCmdQueue.capacity;
                    OSRestoreInterrupts(savedIntr);
                    if (count == 0) {
                            OSRestoreInterrupts(intrEnabled);
                        } else {
                            memset(&cb->stdCmdQueue.buffer[cb->stdCmdQueue.front], 0, sizeof(WPADCommand));
                            indexByte = cb->stdCmdQueue.front;
                            index = indexByte;
                            lastIndex = cb->stdCmdQueue.capacity - 1;
                            wrapMask = ~(((s32)index - lastIndex) | (lastIndex - (s32)index)) >> 31;
                            cb->stdCmdQueue.front = (index + 1) & ~wrapMask;
                            OSRestoreInterrupts(intrEnabled);
                        }
                    }
                }
            } while (hasCommand);
            DBPrintf_80068D68(msgBase + 0x100);
            if (cb->autoSamplingBuf != NULL) {
                WPADSetAutoSamplingBuf(chan, cb->autoSamplingBuf, cb->autoSamplingSize);
            }
            WPADiResetChannel_8005E8E0(chan);
            lbl_8055DC08[chan] = FALSE;
            if (*(WPADCallback*)((u8*)cb + 0x7E4) != NULL) {
                (*(WPADCallback*)((u8*)cb + 0x7E4))(chan, WPAD_ERR_NO_CONTROLLER);
            }
        } else {
            DBPrintf_80068D68(msgBase + 0x118);
        }
    }
}

// Disconnect a WPAD channel and clear its saved Bluetooth device information.
void fn_8006022C(s32 chan)
{
    s32 status;
    WPADCB* cb;
    BOOL intrEnabled;

    memset(lbl_80393058 + (chan + 10) * 0x46 + 1, 0, 0x46);
    lbl_8055DC11 = TRUE;
    cb = lbl_8038F4F0[chan];
    intrEnabled = OSDisableInterrupts();
    status = *(s32*)((u8*)cb + 0x7FC);
    OSRestoreInterrupts(intrEnabled);
    if (status == WPAD_ERR_NO_CONTROLLER) {
        return;
    }
    intrEnabled = OSDisableInterrupts();
    if (((u8*)cb)[0x8C6]) {
        OSRestoreInterrupts(intrEnabled);
        return;
    }
    ((u8*)cb)[0x8C6] = TRUE;
    OSRestoreInterrupts(intrEnabled);
    BTA_HhClose(((u8*)cb)[0x803]);
}

/* Requests a controller status report on a ready channel: builds a RPTID_REQUEST_STATUS command with statusOut as its WPADInfo output and callback as its completion callback, then queues it on the channel's standard command queue. */
#define WPADiRequestStatus fn_800604E8
#pragma push
#pragma opt_propagation off
s32 fn_800604E8(s32 chan, s32 statusOut, void* callback) {
    /* Queue a RPTID_REQUEST_STATUS report on a ready channel: check status and handshake, copy the command into a free standard-queue slot and advance its tail. Returns WPAD_ERR_OK, WPAD_ERR_COMMUNICATION_ERROR if unready or full, or the channel's prior error. */
    WPADCB* cb = _wpdcb[chan];
    s32 intrState, nestedIntrState, result, handshakeDone;
    s32 enqueueOk;
    s32 negTwo;
    s32 resultMask;
    u8 command[0x60] ALIGN(8);
    u8* cmdQueue; /* &cb->stdCmdQueue as bytes: [0]=front, [1]=back, [4]=buffer, [8]=capacity */
    s8 usedCount, tailIndex;
    s32 lastSlot, wrapMask;
    intrState = OSDisableInterrupts();
    handshakeDone = cb->handshakeDone;
    result = cb->readStatus;
    OSRestoreInterrupts(intrState);
    if (result != WPAD_ERR_NO_CONTROLLER) {
        if (handshakeDone == 0) result = WPAD_ERR_COMMUNICATION_ERROR;
        else {
            *(u32*)&command[0] = RPTID_REQUEST_STATUS;
            *(u16*)&command[0x1A] = 1;
            command[4] = 0;
            *(void**)&command[0x2C] = callback;
            *(u32*)&command[0x28] = statusOut;
            *(double*)&command[0x30] = *(double*)&command[0];
            *(double*)&command[0x38] = *(double*)&command[8];
            *(double*)&command[0x40] = *(double*)&command[0x10];
            *(double*)&command[0x48] = *(double*)&command[0x18];
            *(double*)&command[0x50] = *(double*)&command[0x20];
            *(double*)&command[0x58] = *(double*)&command[0x28];
            cmdQueue = (u8*)&cb->stdCmdQueue;
            intrState = OSDisableInterrupts();
            nestedIntrState = OSDisableInterrupts();
            enqueueOk = cmdQueue[0];
            usedCount = (s8)(cmdQueue[1] - enqueueOk);
            if (usedCount < 0) {
                usedCount = (s8)(usedCount + *(u32*)(cmdQueue + 8));
            }
            OSRestoreInterrupts(nestedIntrState);
            if (*(u32*)(cmdQueue + 8) - 1 == (u32)usedCount) {
                OSRestoreInterrupts(intrState);
                enqueueOk = 0;
            } else {
                memset(*(u8**)(cmdQueue + 4) + (s8)cmdQueue[1] * 0x30, 0, 0x30);
                memcpy(*(u8**)(cmdQueue + 4) + (s8)cmdQueue[1] * 0x30, command + 0x30, 0x30);
                tailIndex = (s8)cmdQueue[1];
                lastSlot = *(s32*)(cmdQueue + 8) - 1;
                wrapMask = ~(((s32)tailIndex - lastSlot) | (lastSlot - (s32)tailIndex)) >> 31;
                cmdQueue[1] = (tailIndex + 1) & ~wrapMask;
                OSRestoreInterrupts(intrState);
                enqueueOk = 1;
            }
            resultMask = enqueueOk;
            resultMask = -resultMask;
            resultMask |= enqueueOk;
            resultMask >>= 31;
            negTwo = WPAD_ERR_COMMUNICATION_ERROR;
            result = negTwo & ~resultMask;
        }
    }
    return result;
}
#pragma pop
// Caches the WPAD motor-enabled setting (from SCGetWpadMotorMode) with interrupts disabled.
void fn_80060750(void* enable) {
    BOOL interrupts = OSDisableInterrupts();
    lbl_8055DC14 = enable;
    OSRestoreInterrupts(interrupts);
}

/* Returns the WPAD motor/rumble-enabled setting (lbl_8055DC14) atomically. */
void* fn_80060784(void) {
    BOOL interruptsEnabled = OSDisableInterrupts();
    void* motorMode = lbl_8055DC14;
    OSRestoreInterrupts(interruptsEnabled);
    return motorMode;
}

/* Returns the data format for the given WPAD channel (field at +0x7F0), clamping -1 to 0. */
u32 fn_800609E0(s32 chan) {
    BOOL enabled = OSDisableInterrupts();
    u32 val = *(u32*)((u8*)lbl_8038F4F0[chan] + 0x7F0);
    OSRestoreInterrupts(enabled);
    return (val == (u32)-1) ? 0 : val;
}

/* Returns the connection state for the given WPAD channel (field at +0x77C). */
u32 fn_80060C7C(s32 chan) {
#define s_wpadControlBlocks lbl_8038F4F0
    WPADCB* controlBlock = s_wpadControlBlocks[chan];
    BOOL interrupts = OSDisableInterrupts();
    u32 connected = *(u32*)((u8*)controlBlock + 0x77C);
    OSRestoreInterrupts(interrupts);
    return connected;
#undef s_wpadControlBlocks
}

static inline BOOL fn_80060CC0_CanQueue(WPADCommandQueue* pQueue, s8 num) {
    BOOL enabled = OSDisableInterrupts();
    s8 queueSize = pQueue->back - pQueue->front;

    if (queueSize < 0) {
        queueSize += pQueue->capacity;
    }

    OSRestoreInterrupts(enabled);
    return (u32)(queueSize + num) <= pQueue->capacity - 1;
}

#define WPADiSendMuteSpeakerInline(q, muteValue, callbackValue) \
    { \
        WPADCommand command; \
        command.reportID = RPTID_MUTE_SPEAKER; \
        command.dataLength = RPT19_SIZE; \
        command.dataBuf[RPT19_SPEAKER_MUTE] = (muteValue) ? 4 : 0; \
        command.cmdCB = (callbackValue); \
        WPADiPushCommandInline((q), command); \
    }

#define WPADiPushCommandInline(pQueue, localCommand) \
    { \
        WPADCommand cmdCopy; \
        f64* cmdSrc; \
        f64* cmdDst; \
        BOOL queueEnabled; \
        BOOL innerEnabled; \
        s8 queueSize; \
        cmdSrc = (f64*)&(localCommand); \
        cmdDst = (f64*)&cmdCopy; \
        cmdDst[0] = cmdSrc[0]; \
        cmdDst[1] = cmdSrc[1]; \
        cmdDst[2] = cmdSrc[2]; \
        cmdDst[3] = cmdSrc[3]; \
        cmdDst[4] = cmdSrc[4]; \
        cmdDst[5] = cmdSrc[5]; \
        queueEnabled = OSDisableInterrupts(); \
        innerEnabled = OSDisableInterrupts(); \
        queueSize = (pQueue)->back - (pQueue)->front; \
        if (queueSize < 0) queueSize += (pQueue)->capacity; \
        OSRestoreInterrupts(innerEnabled); \
        if ((pQueue)->capacity - 1 == queueSize) { \
            OSRestoreInterrupts(queueEnabled); \
        } else { \
            memset(&(pQueue)->buffer[(pQueue)->back], 0, sizeof(WPADCommand)); \
            memcpy(&(pQueue)->buffer[(pQueue)->back], &cmdCopy, sizeof(WPADCommand)); \
            (pQueue)->back = (pQueue)->back == (pQueue)->capacity - 1 ? 0 : (pQueue)->back + 1; \
            OSRestoreInterrupts(queueEnabled); \
        } \
    }

#define WPADiSendEnableSpeakerInline(pQueue, enableValue, callbackValue) \
    { \
        WPADCommand command; \
        command.reportID = RPTID_ENABLE_SPEAKER; \
        command.dataLength = RPT14_SIZE; \
        command.dataBuf[RPT14_SPEAKER_ENABLE] = (enableValue) ? 4 : 0; \
        command.cmdCB = (callbackValue); \
        WPADiPushCommandInline((pQueue), command); \
    }

#define WPADiSendWriteDataCmdInline(pQueue, commandValue, addressValue, callbackValue) \
    { \
        WPADCommand command; \
        u8 byteValue; \
        u32 address; \
        byteValue = (commandValue); \
        address = (addressValue); \
        command.reportID = RPTID_WRITE_DATA; \
        command.dataLength = RPT16_SIZE; \
        command.cmdCB = (callbackValue); \
        memcpy(&command.dataBuf[RPT16_DATA_DST_ADDRESS], &address, sizeof(u32)); \
        memcpy(&command.dataBuf[RPT16_DATA_LENGTH], &byteValue, sizeof(u8)); \
        memcpy(&command.dataBuf[RPT16_DATA], &byteValue, sizeof(u8)); \
        WPADiPushCommandInline((pQueue), command); \
    }

#define WPADiSendWriteDataInline(pQueue, sourceData, argLength, addressValue, callbackValue) \
    { \
        WPADCommand command; \
        u8 packedLength; \
        u32 address; \
        packedLength = (argLength) & 31; \
        address = (addressValue); \
        command.reportID = RPTID_WRITE_DATA; \
        command.dataLength = RPT16_SIZE; \
        command.cmdCB = (callbackValue); \
        memcpy(&command.dataBuf[RPT16_DATA_DST_ADDRESS], &address, sizeof(u32)); \
        memcpy(&command.dataBuf[RPT16_DATA_LENGTH], &packedLength, sizeof(u8)); \
        memcpy(&command.dataBuf[RPT16_DATA], (sourceData), (argLength)); \
        WPADiPushCommandInline((pQueue), command); \
    }

#define WPADiSendGetContStatInline(pQueue, infoValue, callbackValue) \
    { \
        WPADCommand command; \
        command.reportID = RPTID_REQUEST_STATUS; \
        command.dataLength = RPT15_SIZE; \
        command.dataBuf[0] = 0; \
        command.cmdCB = (callbackValue); \
        command.statusReportOut = (infoValue); \
        WPADiPushCommandInline((pQueue), command); \
    }

#define WPADiPushCommandInlineResult(pQueue, localCommand, resultValue) \
    { \
        WPADCommand cmdCopy; \
        f64* cmdSrc; \
        f64* cmdDst; \
        BOOL queueEnabled; \
        BOOL innerEnabled; \
        s8 queueSize; \
        cmdSrc = (f64*)&(localCommand); \
        cmdDst = (f64*)&cmdCopy; \
        cmdDst[0] = cmdSrc[0]; \
        cmdDst[1] = cmdSrc[1]; \
        cmdDst[2] = cmdSrc[2]; \
        cmdDst[3] = cmdSrc[3]; \
        cmdDst[4] = cmdSrc[4]; \
        cmdDst[5] = cmdSrc[5]; \
        queueEnabled = OSDisableInterrupts(); \
        innerEnabled = OSDisableInterrupts(); \
        queueSize = (pQueue)->back - (pQueue)->front; \
        if (queueSize < 0) queueSize += (pQueue)->capacity; \
        OSRestoreInterrupts(innerEnabled); \
        if ((pQueue)->capacity - 1 == queueSize) { \
            OSRestoreInterrupts(queueEnabled); \
            (resultValue) = FALSE; \
        } else { \
            memset(&(pQueue)->buffer[(pQueue)->back], 0, sizeof(WPADCommand)); \
            memcpy(&(pQueue)->buffer[(pQueue)->back], &cmdCopy, sizeof(WPADCommand)); \
            (pQueue)->back = (pQueue)->back == (pQueue)->capacity - 1 ? 0 : (pQueue)->back + 1; \
            OSRestoreInterrupts(queueEnabled); \
            (resultValue) = TRUE; \
        } \
    }

#define WPADiSendMuteSpeakerResultInline(pQueue, muteValue, callbackValue, resultValue) \
    { \
        WPADCommand command; \
        command.reportID = RPTID_MUTE_SPEAKER; \
        command.dataLength = RPT19_SIZE; \
        command.dataBuf[RPT19_SPEAKER_MUTE] = (muteValue) ? 4 : 0; \
        command.cmdCB = (callbackValue); \
        WPADiPushCommandInlineResult((pQueue), command, resultValue); \
    }

#define WPADiSendWriteDataCmdResultInline(pQueue, commandValue, addressValue, callbackValue, resultValue) \
    { \
        WPADCommand command; \
        u8 byteValue; \
        u32 address; \
        byteValue = (commandValue); \
        address = (addressValue); \
        command.reportID = RPTID_WRITE_DATA; \
        command.dataLength = RPT16_SIZE; \
        command.cmdCB = (callbackValue); \
        memcpy(&command.dataBuf[RPT16_DATA_DST_ADDRESS], &address, sizeof(u32)); \
        memcpy(&command.dataBuf[RPT16_DATA_LENGTH], &byteValue, sizeof(u8)); \
        memcpy(&command.dataBuf[RPT16_DATA], &byteValue, sizeof(u8)); \
        WPADiPushCommandInlineResult((pQueue), command, resultValue); \
    }

#define WPADiSendMuteSpeakerStorage(pQueue, muteValue, callbackValue, commandStorage) \
    { \
        (commandStorage).reportID = RPTID_MUTE_SPEAKER; \
        (commandStorage).dataLength = RPT19_SIZE; \
        (commandStorage).dataBuf[RPT19_SPEAKER_MUTE] = (muteValue) ? 4 : 0; \
        (commandStorage).cmdCB = (callbackValue); \
        WPADiPushCommandInline((pQueue), commandStorage); \
    }

#define WPADiSendEnableSpeakerStorage(pQueue, enableValue, callbackValue, commandStorage) \
    { \
        (commandStorage).reportID = RPTID_ENABLE_SPEAKER; \
        (commandStorage).dataLength = RPT14_SIZE; \
        (commandStorage).dataBuf[RPT14_SPEAKER_ENABLE] = (enableValue) ? 4 : 0; \
        (commandStorage).cmdCB = (callbackValue); \
        WPADiPushCommandInline((pQueue), commandStorage); \
    }

#define WPADiSendWriteDataCmdStorage(pQueue, commandValue, addressValue, callbackValue, commandStorage) \
    { \
        u8 byteValue; \
        u32 address; \
        byteValue = (commandValue); \
        address = (addressValue); \
        (commandStorage).reportID = RPTID_WRITE_DATA; \
        (commandStorage).dataLength = RPT16_SIZE; \
        (commandStorage).cmdCB = (callbackValue); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA_DST_ADDRESS], &address, sizeof(u32)); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA_LENGTH], &byteValue, sizeof(u8)); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA], &byteValue, sizeof(u8)); \
        WPADiPushCommandInline((pQueue), commandStorage); \
    }

#define WPADiSendWriteDataStorage(pQueue, sourceData, argLength, addressValue, callbackValue, commandStorage) \
    { \
        u8 packedLength; \
        u32 address; \
        packedLength = (argLength) & 31; \
        address = (addressValue); \
        (commandStorage).reportID = RPTID_WRITE_DATA; \
        (commandStorage).dataLength = RPT16_SIZE; \
        (commandStorage).cmdCB = (callbackValue); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA_DST_ADDRESS], &address, sizeof(u32)); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA_LENGTH], &packedLength, sizeof(u8)); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA], (sourceData), (argLength)); \
        WPADiPushCommandInline((pQueue), commandStorage); \
    }

#define WPADiSendGetContStatStorage(pQueue, infoValue, callbackValue, commandStorage) \
    { \
        (commandStorage).reportID = RPTID_REQUEST_STATUS; \
        (commandStorage).dataLength = RPT15_SIZE; \
        (commandStorage).dataBuf[0] = 0; \
        (commandStorage).cmdCB = (callbackValue); \
        (commandStorage).statusReportOut = (infoValue); \
        WPADiPushCommandInline((pQueue), commandStorage); \
    }

#define WPADiSendMuteSpeakerResultStorage(pQueue, muteValue, callbackValue, resultValue, commandStorage) \
    { \
        (commandStorage).reportID = RPTID_MUTE_SPEAKER; \
        (commandStorage).dataLength = RPT19_SIZE; \
        (commandStorage).dataBuf[RPT19_SPEAKER_MUTE] = (muteValue) ? 4 : 0; \
        (commandStorage).cmdCB = (callbackValue); \
        WPADiPushCommandInlineResult((pQueue), commandStorage, resultValue); \
    }

#define WPADiSendWriteDataCmdResultStorage(pQueue, commandValue, addressValue, callbackValue, resultValue, commandStorage) \
    { \
        u8 byteValue; \
        u32 address; \
        byteValue = (commandValue); \
        address = (addressValue); \
        (commandStorage).reportID = RPTID_WRITE_DATA; \
        (commandStorage).dataLength = RPT16_SIZE; \
        (commandStorage).cmdCB = (callbackValue); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA_DST_ADDRESS], &address, sizeof(u32)); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA_LENGTH], &byteValue, sizeof(u8)); \
        memcpy(&(commandStorage).dataBuf[RPT16_DATA], &byteValue, sizeof(u8)); \
        WPADiPushCommandInlineResult((pQueue), commandStorage, resultValue); \
    }

// fn_80060CC0: WPAD processing (large - stub)
#pragma inline_max_size(1000)
#pragma inline_max_total_size(10000)
extern u8 lbl_80560CC0, lbl_80560CC1, lbl_80560CC2, lbl_80560CC3;
extern u8 lbl_80560CC4, lbl_80560CC5, lbl_80560CC6;
#pragma inline_depth(3)
s32 fn_80060CC0(s32 chan, u32 command, WPADCallback pCallback) {
    struct {
        u8* p;
        BOOL handshake;
        BOOL spkEnable;
        u8 pad[16];
    } cb;
    BOOL enabled;
    s32 status;
    BOOL sendResult;
    BOOL innerEnabled0, innerEnabled1;
    s8 queueSize0, queueSize1;
    u8 config[SPK_CONFIG_SIZE];
    cb.pad[0] = 0;
    config[0] = lbl_80560CC0;
    config[1] = lbl_80560CC1;
    config[2] = lbl_80560CC2;
    config[3] = lbl_80560CC3;
    config[4] = lbl_80560CC4;
    config[5] = lbl_80560CC5;
    config[6] = lbl_80560CC6;
    cb.p = (u8*)lbl_8038F4F0[chan];
    enabled = OSDisableInterrupts();
    cb.spkEnable = *(s32*)(cb.p + 0x77C);
    status = *(s32*)(cb.p + 0x7FC);
    cb.handshake = *(s32*)(cb.p + 0x81C);
    OSRestoreInterrupts(enabled);
    if (status == WPAD_ERR_NO_CONTROLLER) goto _end;
    if (!cb.handshake) { status = WPAD_ERR_COMMUNICATION_ERROR; goto _end; }
    if (command == WPAD_SPEAKER_OFF) {
        if (!cb.spkEnable) {
            status = WPAD_ERR_OK;
        } else {
            enabled = OSDisableInterrupts();
            innerEnabled0 = OSDisableInterrupts();
            queueSize0 = ((WPADCommandQueue*)(cb.p + 0x160))->back - ((WPADCommandQueue*)(cb.p + 0x160))->front;
            if (queueSize0 < 0) queueSize0 += ((WPADCommandQueue*)(cb.p + 0x160))->capacity;
            OSRestoreInterrupts(innerEnabled0);
            if ((u32)(queueSize0 + 5) <= ((WPADCommandQueue*)(cb.p + 0x160))->capacity - 1) {
                WPADiSendMuteSpeakerInline((WPADCommandQueue*)(cb.p + 0x160), TRUE, NULL);
                WPADiSendWriteDataCmdInline((WPADCommandQueue*)(cb.p + 0x160), 0x01, WM_REG_SPEAKER_01, NULL);
                WPADiSendWriteDataCmdInline((WPADCommandQueue*)(cb.p + 0x160), 0x00, WM_REG_SPEAKER_09, NULL);
                WPADiSendEnableSpeakerInline((WPADCommandQueue*)(cb.p + 0x160), FALSE, NULL);
                WPADiSendGetContStatInline((WPADCommandQueue*)(cb.p + 0x160), NULL, pCallback);
                OSRestoreInterrupts(enabled);
                return WPAD_ERR_OK;
            }
            status = WPAD_ERR_COMMUNICATION_ERROR;
            OSRestoreInterrupts(enabled);
        }
    } else {
        switch (command) {
        case WPAD_SPEAKER_ON:
        case WPAD_SPEAKER_5: {
            enabled = OSDisableInterrupts();
            innerEnabled1 = OSDisableInterrupts();
            queueSize1 = ((WPADCommandQueue*)(cb.p + 0x160))->back - ((WPADCommandQueue*)(cb.p + 0x160))->front;
            if (queueSize1 < 0) queueSize1 += ((WPADCommandQueue*)(cb.p + 0x160))->capacity;
            OSRestoreInterrupts(innerEnabled1);
            if ((u32)(queueSize1 + 7) <= ((WPADCommandQueue*)(cb.p + 0x160))->capacity - 1) {
                WPADiSendEnableSpeakerInline((WPADCommandQueue*)(cb.p + 0x160), TRUE, NULL);
                WPADiSendMuteSpeakerInline((WPADCommandQueue*)(cb.p + 0x160), TRUE, NULL);
                WPADiSendWriteDataCmdInline((WPADCommandQueue*)(cb.p + 0x160), 0x01, WM_REG_SPEAKER_09, NULL);
                WPADiSendWriteDataCmdInline((WPADCommandQueue*)(cb.p + 0x160), 0x80, WM_REG_SPEAKER_01, NULL);
                config[4] = _speakerVolume;
                WPADiSendWriteDataInline((WPADCommandQueue*)(cb.p + 0x160), &config, SPK_CONFIG_SIZE, WM_REG_SPEAKER_01, NULL);
                WPADiSendMuteSpeakerInline((WPADCommandQueue*)(cb.p + 0x160), FALSE, NULL);
                WPADiSendGetContStatInline((WPADCommandQueue*)(cb.p + 0x160), NULL, pCallback);
                OSRestoreInterrupts(enabled);
                return WPAD_ERR_OK;
            }
            status = WPAD_ERR_COMMUNICATION_ERROR;
            OSRestoreInterrupts(enabled);
            break;
        }
        case WPAD_SPEAKER_MUTE: {
            WPADiSendMuteSpeakerResultInline((WPADCommandQueue*)(cb.p + 0x160), TRUE, pCallback, sendResult);
            if (!sendResult) { status = WPAD_ERR_COMMUNICATION_ERROR; break; }
            return WPAD_ERR_OK;
        }
        case WPAD_SPEAKER_UNMUTE: {
            WPADiSendMuteSpeakerResultInline((WPADCommandQueue*)(cb.p + 0x160), FALSE, pCallback, sendResult);
            if (!sendResult) { status = WPAD_ERR_COMMUNICATION_ERROR; break; }
            return WPAD_ERR_OK;
        }
        case WPAD_SPEAKER_PLAY: {
            WPADiSendWriteDataCmdResultInline((WPADCommandQueue*)(cb.p + 0x160), 0x01, WM_REG_SPEAKER_08, pCallback, sendResult);
            if (!sendResult) { status = WPAD_ERR_COMMUNICATION_ERROR; break; }
            return WPAD_ERR_OK;
        }
        }
    }
_end:
    if (pCallback != NULL) pCallback(chan, status);
    return status;
}
#pragma inline_depth(1)
#undef WPADiSendMuteSpeakerInline
#undef WPADiSendMuteSpeakerStorage
#undef WPADiSendEnableSpeakerStorage
#undef WPADiSendWriteDataCmdStorage
#undef WPADiSendWriteDataStorage
#undef WPADiSendGetContStatStorage
#undef WPADiSendMuteSpeakerResultStorage
#undef WPADiSendWriteDataCmdResultStorage
#undef WPADiPushCommandInlineResult
#undef WPADiSendMuteSpeakerResultInline
#undef WPADiSendWriteDataCmdResultInline
#undef WPADiPushCommandInline
#undef WPADiSendEnableSpeakerInline
#undef WPADiSendWriteDataCmdInline
#undef WPADiSendWriteDataInline
#undef WPADiSendGetContStatInline
/* Return the REXE01 global WPAD data-report format, read atomically with
 * interrupts disabled. `chan` is unused: this build keeps one format for all
 * controllers instead of a per-channel value. */
u32 fn_80062054(s32 chan) {
#pragma unused(chan)
    BOOL enabled = OSDisableInterrupts();
    u32 format = lbl_8055DC12;
    OSRestoreInterrupts(enabled);
    return format;
}

// Caches the WPAD speaker volume (clamped to 0..0x7F) with interrupts disabled.
void fn_80062088(s32 volume) {
    BOOL interrupts = OSDisableInterrupts();
    lbl_8055DC12 = volume;
    OSRestoreInterrupts(interrupts);
}

/* Out-of-line copy of WPADSendStreamData with WPADiSendStreamData and the
 * command-queue push inlined: validate the channel and stream state, build the
 * 0x18 speaker stream report and enqueue it on the channel's standard queue. */
#pragma push
#pragma opt_propagation off
#define WPADSendStreamDataInline fn_80062278
s32 WPADSendStreamDataInline(s32 chan, void* pData, u16 len) {
    /* REXE01 inline expansion of WPADSendStreamData: build the 0x18 stream report and queue it on the channel's standard command queue when the controller is connected, handshaken and the stream is idle. Returns WPAD_ERR_OK, WPAD_ERR_NO_CONTROLLER, or WPAD_ERR_COMMUNICATION_ERROR when busy/unready. */
    WPADCB* cb = lbl_8038F4F0[chan];
    s32 intrState, nestedIntrState, status, handshakeDone;
    s32 enqueueOk;
    s32 head;
    u8 command[0x60] ALIGN(8);
    WPADCommandQueue* queue;
    s8 usedCount, tailIndex;
    s32 lastSlot, wrapMask;
    intrState = OSDisableInterrupts();
    status = cb->readStatus;
    handshakeDone = cb->handshakeDone;
    OSRestoreInterrupts(intrState);
    if (status == WPAD_ERR_NO_CONTROLLER) return WPAD_ERR_NO_CONTROLLER;
    if (handshakeDone == 0) return WPAD_ERR_COMMUNICATION_ERROR;
    if (IsBusyStream(chan)) return WPAD_ERR_COMMUNICATION_ERROR;
    *(u32*)&command[0] = 0x18;
    *(u16*)&command[0x1A] = 0x15;
    command[4] = (u8)(len << 3);
    *(void**)&command[0x2C] = NULL;
    memcpy(&command[5], pData, len);
    *(double*)&command[0x30] = *(double*)&command[0];
    *(double*)&command[0x38] = *(double*)&command[8];
    *(double*)&command[0x40] = *(double*)&command[0x10];
    *(double*)&command[0x48] = *(double*)&command[0x18];
    *(double*)&command[0x50] = *(double*)&command[0x20];
    *(double*)&command[0x58] = *(double*)&command[0x28];
    queue = &cb->stdCmdQueue;
    intrState = OSDisableInterrupts();
    nestedIntrState = OSDisableInterrupts();
    head = (u8)queue->front;
    usedCount = (s8)((u8)queue->back - head);
    if (usedCount < 0) {
        usedCount = (s8)(usedCount + queue->capacity);
    }
    OSRestoreInterrupts(nestedIntrState);
    if (queue->capacity - 1 == (u32)usedCount) {
        OSRestoreInterrupts(intrState);
        enqueueOk = 0;
    } else {
        memset((u8*)queue->buffer + (s8)queue->back * 0x30, 0, 0x30);
        memcpy((u8*)queue->buffer + (s8)queue->back * 0x30, command + 0x30, 0x30);
        tailIndex = (s8)queue->back;
        lastSlot = (s32)queue->capacity - 1;
        wrapMask = ~(((s32)tailIndex - lastSlot) | (lastSlot - (s32)tailIndex)) >> 31;
        queue->back = (tailIndex + 1) & ~wrapMask;
        OSRestoreInterrupts(intrState);
        enqueueOk = 1;
    }
    if (enqueueOk == 0) return WPAD_ERR_COMMUNICATION_ERROR;
    intrState = OSDisableInterrupts();
    cb->pendingCmdCount++;
    OSRestoreInterrupts(intrState);
    return WPAD_ERR_OK;
}
#pragma pop
/* Return the DPD-enabled state for the given WPAD channel. */
u32 fn_80062460(s32 chan) {
    WPADCB *cb = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();
    u32 dpdEnabled = *(u32 *)((u8 *)cb + 0x778);
    OSRestoreInterrupts(enabled);
    return dpdEnabled;
}

// fn_800624A4: WPAD callback handler (large - stub)
extern u8 lbl_802EE898[];
extern u8 lbl_802EE8C8[];
s32 fn_800624A4(s32 chan, s32 arg1, WPADCallback arg2) {
    u8 frame[0x420] ALIGN(8);
    register s32 channel asm("r31") = chan;
    register u32 value81C asm("r26");
    register WPADCallback callback asm("r28") = arg2;
    register u32 value778 asm("r27");
    register s32 status asm("r25");
    register WPADCB* p asm("r29") = lbl_8038F4F0[channel];
    register u32 arg asm("r30") = arg1;
    BOOL outerEnabled;
    BOOL enabled;
    BOOL nestedEnabled;
    s8 used;
    s8 index;
    s32 lastIndex;
    s32 wrapMask;
    u32 capacity;

    enabled = OSDisableInterrupts();
    value778 = *(u32*)((u8*)p + 0x778);
    status = *(s32*)((u8*)p + 0x7FC);
    value81C = *(u32*)((u8*)p + 0x81C);
    OSRestoreInterrupts(enabled);
    if (status == WPAD_ERR_NO_CONTROLLER) goto finish;
    if (value81C == 0) {
        status = -2;
        goto finish;
    }
    if (arg != 0) goto extended;
    if (value778 == 0) {
        status = 0;
        goto finish;
    }

    outerEnabled = OSDisableInterrupts();
    nestedEnabled = OSDisableInterrupts();
    used = p->stdCmdQueue.back - p->stdCmdQueue.front;
    if (used < 0) used += p->stdCmdQueue.capacity;
    OSRestoreInterrupts(nestedEnabled);
    capacity = p->stdCmdQueue.capacity;
    if (used + 3 > p->stdCmdQueue.capacity - 1) goto queue_three_fail;

    {
        WPADCommand* cmd = (WPADCommand*)(frame + 0x3C0);
        WPADCommand* copy = (WPADCommand*)(frame + 0x3F0);
        *(u32*)cmd = 0x13;
        *((u8*)cmd + 4) = 0;
        cmd->dataLength = 1;
        cmd->cmdCB = NULL;
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x3F0), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        WPADCommand* cmd = (WPADCommand*)(frame + 0x360);
        WPADCommand* copy = (WPADCommand*)(frame + 0x390);
        *(u32*)cmd = 0x1A;
        *((u8*)cmd + 4) = 0;
        cmd->dataLength = 1;
        cmd->cmdCB = NULL;
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x390), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        WPADCommand* cmd = (WPADCommand*)(frame + 0x300);
        WPADCommand* copy = (WPADCommand*)(frame + 0x330);
        *(u32*)cmd = 0x15;
        *((u8*)cmd + 4) = 0;
        cmd->dataLength = 1;
        cmd->cmdCB = (WPADCallback)callback;
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x330), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }

    OSRestoreInterrupts(outerEnabled);
    return 0;

queue_three_fail:
    status = -2;
    OSRestoreInterrupts(outerEnabled);
    goto finish;

extended:
    outerEnabled = OSDisableInterrupts();
    nestedEnabled = OSDisableInterrupts();
    used = p->stdCmdQueue.back - p->stdCmdQueue.front;
    if (used < 0) used += p->stdCmdQueue.capacity;
    OSRestoreInterrupts(nestedEnabled);
    capacity = p->stdCmdQueue.capacity;
    if (used + 8 > p->stdCmdQueue.capacity - 1) goto queue_eight_fail;
queue_eight:

    {
        WPADCommand* cmd = (WPADCommand*)(frame + 0x2A0);
        WPADCommand* copy = (WPADCommand*)(frame + 0x2D0);
        *(u32*)cmd = 0x13;
        *((u8*)cmd + 4) = 4;
        cmd->dataLength = 1;
        cmd->cmdCB = NULL;
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x2D0), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        WPADCommand* cmd = (WPADCommand*)(frame + 0x240);
        WPADCommand* copy = (WPADCommand*)(frame + 0x270);
        *(u32*)cmd = 0x1A;
        *((u8*)cmd + 4) = 4;
        cmd->dataLength = 1;
        cmd->cmdCB = NULL;
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x270), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        WPADCommand* cmd = (WPADCommand*)(frame + 0x1E0);
        WPADCommand* copy = (WPADCommand*)(frame + 0x210);
        *(u32*)cmd = 0x15;
        *((u8*)cmd + 4) = 0;
        cmd->dataLength = 1;
        cmd->cmdCB = NULL;
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x210), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        u32 addr = 0x04B00030;
        u8 firstByte = 1;
        u8 secondByte = 1;
        WPADCommand* cmd = (WPADCommand*)(frame + 0x1B0);
        WPADCommand* copy = (WPADCommand*)(frame + 0x180);
        *(u32*)cmd = 0x16;
        cmd->dataLength = 0x15;
        cmd->cmdCB = NULL;
        memcpy((u8*)cmd + 4, &addr, 4);
        memcpy((u8*)cmd + 8, &firstByte, 1);
        memcpy((u8*)cmd + 9, &secondByte, 1);
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x180), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        s32 ix = lbl_8055DC19 - 1;
        u8* tableData = (u8*)lbl_802EE898 + ((ix << 3) + ix);
        u32 addr = 0x04B00000;
        u8 firstByte = 9;
        
        WPADCommand* cmd = (WPADCommand*)(frame + 0x120);
        WPADCommand* copy = (WPADCommand*)(frame + 0x150);
        *(u32*)cmd = 0x16;
        cmd->dataLength = 0x15;
        cmd->cmdCB = NULL;
        memcpy((u8*)cmd + 4, &addr, 4);
        memcpy((u8*)cmd + 8, &firstByte, 1);
        
        memcpy((u8*)cmd + 9, tableData, 9);
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x150), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        s32 ix = lbl_8055DC19 - 1;
        u8* tableData = (u8*)lbl_802EE8C8 + (ix << 1);
        u32 addr = 0x04B0001A;
        u8 firstByte = 2;
        
        WPADCommand* cmd = (WPADCommand*)(frame + 0xC0);
        WPADCommand* copy = (WPADCommand*)(frame + 0xF0);
        *(u32*)cmd = 0x16;
        cmd->dataLength = 0x15;
        cmd->cmdCB = NULL;
        memcpy((u8*)cmd + 4, &addr, 4);
        memcpy((u8*)cmd + 8, &firstByte, 1);
        
        memcpy((u8*)cmd + 9, tableData, 2);
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0xF0), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        u32 addr = 0x04B00033;
        u8 firstByte = 1;
        u8 secondByte = (u8)arg;
        WPADCommand* cmd = (WPADCommand*)(frame + 0x90);
        WPADCommand* copy = (WPADCommand*)(frame + 0x60);
        *(u32*)cmd = 0x16;
        cmd->dataLength = 0x15;
        cmd->cmdCB = NULL;
        memcpy((u8*)cmd + 4, &addr, 4);
        memcpy((u8*)cmd + 8, &firstByte, 1);
        memcpy((u8*)cmd + 9, &secondByte, 1);
        
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x60), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }


    {
        u32 addr = 0x04B00030;
        u8 firstByte = 1;
        u8 secondByte = 8;
        WPADCommand* cmd = (WPADCommand*)(frame + 0x30);
        WPADCommand* copy = (WPADCommand*)(frame + 0x00);
        *(u32*)cmd = 0x16;
        cmd->dataLength = 0x15;
        cmd->cmdCB = (WPADCallback)callback;
        memcpy((u8*)cmd + 4, &addr, 4);
        memcpy((u8*)cmd + 8, &firstByte, 1);
        memcpy((u8*)cmd + 9, &secondByte, 1);
        
        ((double*)copy)[0] = ((double*)cmd)[0];
        ((double*)copy)[1] = ((double*)cmd)[1];
        ((double*)copy)[2] = ((double*)cmd)[2];
        ((double*)copy)[3] = ((double*)cmd)[3];
        ((double*)copy)[4] = ((double*)cmd)[4];
        ((double*)copy)[5] = ((double*)cmd)[5];
    }

        enabled = OSDisableInterrupts();
        nestedEnabled = OSDisableInterrupts();
        used = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (used < 0) used += p->stdCmdQueue.capacity;
        OSRestoreInterrupts(nestedEnabled);
        capacity = p->stdCmdQueue.capacity;
        if (capacity - 1 == used) {
            OSRestoreInterrupts(enabled);
        } else {
            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
            memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], (WPADCommand*)(frame + 0x00), sizeof(WPADCommand));
            {
                register s32 ringIndex asm("r6") = p->stdCmdQueue.back;
                register s32 ringLimit asm("r4") = p->stdCmdQueue.capacity - 1;
                register s32 ringMask;
                ringMask = ~((ringIndex - ringLimit) | (ringLimit - ringIndex)) >> 31;
                p->stdCmdQueue.back = (ringIndex + 1) & ~ringMask;
            }
            OSRestoreInterrupts(enabled);
        }

    OSRestoreInterrupts(outerEnabled);
    return 0;

queue_eight_fail:
    status = -2;
    OSRestoreInterrupts(outerEnabled);
    goto finish;

finish:
    if (callback != NULL) ((void (*)(s32, s32))callback)(channel, status);
    return status;
}
extern const char lbl_803122F4[];
/* Send one Wiimote output HID report: set up the control block, apply rumble/ack state, build the report buffer and send it */ void WPADiSendOutputReport(s32 chan, WPADGameInfo *pCommand) {
    /* Send one Wiimote output report on channel: set up the controller block,
     * handle rumble/ack timing, build a HID report buffer and send it over HID. */
    WPADCommand* command = (WPADCommand*)pCommand;
    s32 enabled;
    s32 rumble;
    s8 devHandle;
    u8* controlBlock;
    u8 reportID;
    BT_HDR* pBuffer;
    u8* pRptData;
    s32 commStatus;
    u8* pCmdData;
    u16 len;
    u32 time;

    reportID = (u8)command->reportID;
    len = command->dataLength;
    pCmdData = command->dataBuf;
    enabled = OSDisableInterrupts();
    controlBlock = (u8*)lbl_8038F4F0[chan];
    devHandle = *(s8*)(controlBlock + 0x803);
    commStatus = *(s32*)(controlBlock + 0x7fc);
    if (devHandle < 0) {
        OSRestoreInterrupts(enabled);
        return;
    }
    *(s32*)(controlBlock + 0x7fc) = WPAD_ERR_COMMUNICATION_ERROR;
    rumble = *(u32*)(controlBlock + 0x814) & (u32)lbl_8055DC14;
    OSRestoreInterrupts(enabled);

    if (reportID == RPTID_SET_RUMBLE) {
        enabled = OSDisableInterrupts();
        *(s32*)(controlBlock + 0x7fc) = commStatus;
        OSRestoreInterrupts(enabled);
        goto send;
    }
    if (reportID == RPTID_SEND_SPEAKER_DATA) {
        enabled = OSDisableInterrupts();
        *(s32*)(controlBlock + 0x7fc) = commStatus;
        controlBlock[0x80e]--;
        OSRestoreInterrupts(enabled);
        goto send;
    }

    enabled = OSDisableInterrupts();
    switch (reportID) {
    case RPTID_WRITE_DATA:
        break;
    case RPTID_READ_DATA:
        *(s32*)(controlBlock + 0x8bc) = 0;
        *(s32*)(controlBlock + 0x8b8) = (s32)command->readAddress;
        *(u16*)(controlBlock + 0x8c0) = command->readLength;
        *(s32*)(controlBlock + 0x8b4) = (s32)command->dstBuf;
        break;
    case RPTID_REQUEST_STATUS:
        *(s32*)(controlBlock + 0x7fc) = commStatus;
        *(void**)(controlBlock + 0x790) = command->statusReportOut;
        controlBlock[0x800] = 1;
        break;
    case 0xFF:
        memcpy(&time, command->dataBuf, sizeof(u32));
        *(s64*)(controlBlock + 0x848) = __OSGetSystemTime() + time;
        controlBlock[0x850] = 1;
        return;
    default:
        pCmdData[0] |= (1 << RPT_OUT_FLAG_REQUEST_ACK_RPT);
        break;
    }
    *(void**)(controlBlock + 0x7dc) = command->cmdCB;
    controlBlock[0x8c7] = reportID;
    *(s64*)(controlBlock + 0x848) = __OSGetSystemTime() + OS_SEC_TO_TICKS(lbl_8055DC1A * 60);
    controlBlock[0x850] = 0;
    OSRestoreInterrupts(enabled);

send:
    DBPrintf_80068D68(lbl_803122F4, devHandle, reportID);
    pBuffer = GKI_getbuf((u8)(len + 18));
    pBuffer->len = (u8)(len + 1);
    pBuffer->offset = 10;
    pRptData = (u8*)pBuffer + sizeof(BT_HDR) + pBuffer->offset;
    pRptData[0] = reportID;
    memcpy(&pRptData[1], pCmdData, len);
    if (rumble) {
        pRptData[RPT_OUT_FLAGS] |= (1 << RPT_OUT_FLAG_RUMBLE);
    } else {
        pRptData[RPT_OUT_FLAGS] &= ~(1 << RPT_OUT_FLAG_RUMBLE);
    }
    BTA_HhSendData((UINT8)devHandle, pBuffer);
}

/* WPADiSendSetReportType with WPADiPushCommand inlined (the REXE01 build keeps
 * both copies): fill a SetDataReportMode command for the requested data format
 * - always continuous reporting - and append it to the command queue, copying
 * it through the 8-byte aligned half of the frame.  Returns FALSE, leaving the
 * queue untouched, when the queue holds capacity - 1 commands already. */
BOOL fn_80063564(WPADCommandQueue* pQueue, s32 format, WPADCallback pCallback) {
    u8 frame[0x60] ALIGN(8);
    WPADCommand* command = (WPADCommand*)(frame + 0x30);
    s8 diff;
    s8 index;
    BOOL innerEnabled;
    BOOL enabled;
    register s32 wrapMask;
    s32 lastIndex;

    command->reportID = RPTID_SET_DATA_REPORT_MODE;
    command->dataLength = RPT12_SIZE;
    command->dataBuf[RPT12_CONT_REPORT] = 4; // Always continuous reporting
    command->cmdCB = pCallback;

    switch (format) {
    case WPAD_FMT_CORE_BTN: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN;
        break;
    }
    case WPAD_FMT_CORE_BTN_ACC: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC;
        break;
    }
    case WPAD_FMT_CORE_BTN_ACC_DPD: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD12;
        break;
    }
    case WPAD_FMT_FS_BTN: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_EXT8;
        break;
    }
    case WPAD_FMT_FS_BTN_ACC: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_EXT16;
        break;
    }
    case WPAD_FMT_FS_BTN_ACC_DPD: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD10_EXT9;
        break;
    }
    case WPAD_FMT_CLASSIC_BTN: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_EXT8;
        break;
    }
    case WPAD_FMT_CLASSIC_BTN_ACC: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_EXT16;
        break;
    }
    case WPAD_FMT_CLASSIC_BTN_ACC_DPD: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD10_EXT9;
        break;
    }
    case WPAD_FMT_BTN_ACC_DPD_EXTENDED: {
        command->dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD18_1;
        break;
    }
    default:
        break;
    }

    ((double*)frame)[0] = ((double*)command)[0];
    ((double*)frame)[1] = ((double*)command)[1];
    ((double*)frame)[2] = ((double*)command)[2];
    ((double*)frame)[3] = ((double*)command)[3];
    ((double*)frame)[4] = ((double*)command)[4];
    ((double*)frame)[5] = ((double*)command)[5];

    enabled = OSDisableInterrupts();
    innerEnabled = OSDisableInterrupts();
    diff = pQueue->back - pQueue->front;
    if (diff < 0) {
        diff = (s8)(diff + pQueue->capacity);
    }
    OSRestoreInterrupts(innerEnabled);
    if (pQueue->capacity - 1 == diff) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    memset(&pQueue->buffer[pQueue->back], 0, sizeof(WPADCommand));
    memcpy(&pQueue->buffer[pQueue->back], frame, sizeof(WPADCommand));
    /* the ring indices are bytes: read back as a byte and wrap it round */
    index = (s8)(u8)pQueue->back;
    lastIndex = pQueue->capacity - 1;
    wrapMask = ~((index - lastIndex) | (lastIndex - index)) >> 31;
    pQueue->back = (index + 1) & ~wrapMask;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

#pragma opt_propagation off
/* Appends a WriteData command writing one byte to a Wiimote register to a command queue, returning FALSE when the ring is full (inlined WPADiSendWriteData/WPADiPushCommand copy). */ BOOL WPADiSendWriteDataCmd_80063744(WPADCommandQueue *pQueue, u8 value, u32 address, WPADCallback pCallback) {
    /* WPADiSendWriteDataCmd with WPADiSendWriteData and WPADiPushCommand both
     * inlined (the REXE01 build keeps this second copy): build a WriteData
     * command writing the single byte `value` to the wiimote register
     * `address`, and append it to the command queue, copying the command into
     * the 8-byte aligned half of the frame on the way.  Returns FALSE, leaving
     * the queue untouched, when it already holds capacity - 1 commands. */
    WPADCommand frame[2] ALIGN(8); /* command in frame[0]; frame[1] is what gets pushed */
    WPADCommand* command = frame;
    BOOL enabled;
    BOOL innerEnabled;
    s8 diff;
    s32 index;
    s32 lastIndex;
    s32 wrapMask;
    s8 rawBack;

    /* WPADiSendWriteData's "u8 packedLen = len & 31" for len 1 shares the word
     * the byte argument came in, just above it */
    *(u8 *)((u8 *)&value + 1) = 1;
    command->reportID = RPTID_WRITE_DATA;
    command->dataLength = RPT16_SIZE;
    command->cmdCB = pCallback;
    memcpy(&command->dataBuf[RPT16_DATA_DST_ADDRESS], &address, sizeof(u32));
    memcpy(&command->dataBuf[RPT16_DATA_LENGTH], (u8 *)&value + 1, sizeof(u8));
    memcpy(&command->dataBuf[RPT16_DATA], &value, sizeof(u8));
    *(double *)((u8 *)frame + 0x30) = *(double *)frame;
    *(double *)((u8 *)frame + 0x38) = *(double *)((u8 *)frame + 8);
    *(double *)((u8 *)frame + 0x40) = *(double *)((u8 *)frame + 0x10);
    *(double *)((u8 *)frame + 0x48) = *(double *)((u8 *)frame + 0x18);
    *(double *)((u8 *)frame + 0x50) = *(double *)((u8 *)frame + 0x20);
    *(double *)((u8 *)frame + 0x58) = *(double *)((u8 *)frame + 0x28);

    enabled = OSDisableInterrupts();
    innerEnabled = OSDisableInterrupts();
    diff = (s8)(pQueue->back - pQueue->front);
    if (diff < 0) {
        diff = (s8)(diff + pQueue->capacity);
    }
    OSRestoreInterrupts(innerEnabled);
    if (pQueue->capacity - 1 == (u32)diff) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    memset(pQueue->buffer + (s8)pQueue->back, 0, sizeof(WPADCommand));
    memcpy(pQueue->buffer + (s8)pQueue->back, (u8 *)frame + 0x30, sizeof(WPADCommand));
    /* the ring indices are bytes: back + 1, or 0 when that was the last slot */
    rawBack = pQueue->back;
    index = rawBack;
    lastIndex = pQueue->capacity - 1;
    wrapMask = ~((index - lastIndex) | (lastIndex - index)) >> 31;
    pQueue->back = (index + 1) & ~wrapMask;
    OSRestoreInterrupts(enabled);
    return TRUE;
}
#pragma opt_propagation reset
BOOL WPADiEnqueueCommand(u8* queue, const void* src, u32 len, u32 val1, u32 val2) {
    /* Enqueues a 0x30-byte WPAD command packet into a ring buffer (fields at +0/+1
       indices, +4 buffer base, +8 capacity). Returns FALSE if the queue is full. */
    u8 packet[0x60] ALIGN(8);
    u8 lenMask;
    s8 usedSlots;
    BOOL irqState;
    BOOL innerIrqState;
    s8 writeIndex;
    s32 maxIndex;
    s32 wrapAdjust;

    lenMask = len & 0x1F;
    *(u32*)&packet[0x30] = 0x16;
    *(u16*)&packet[0x4A] = 0x15;
    *(u32*)&packet[0x5C] = val2;
    memcpy(&packet[0x34], &val1, 4);
    memcpy(&packet[0x38], &lenMask, 1);
    memcpy(&packet[0x39], src, len);
    *(double*)&packet[0] = *(double*)&packet[0x30];
    *(double*)&packet[8] = *(double*)&packet[0x38];
    *(double*)&packet[0x10] = *(double*)&packet[0x40];
    *(double*)&packet[0x18] = *(double*)&packet[0x48];
    *(double*)&packet[0x20] = *(double*)&packet[0x50];
    *(double*)&packet[0x28] = *(double*)&packet[0x58];

    irqState = OSDisableInterrupts();
    innerIrqState = OSDisableInterrupts();
    usedSlots = (s8)(queue[1] - queue[0]);
    if (usedSlots < 0)
        usedSlots = (s8)(usedSlots + *(u32*)(queue + 8));
    OSRestoreInterrupts(innerIrqState);

    if (*(u32*)(queue + 8) - 1 == (u32)usedSlots) {
        OSRestoreInterrupts(irqState);
        return FALSE;
    }
    memset(*(u8**)(queue + 4) + (s8)queue[1] * 0x30, 0, 0x30);
    memcpy(*(u8**)(queue + 4) + (s8)queue[1] * 0x30, packet, 0x30);
    writeIndex = (s8)queue[1];
    maxIndex = *(u32*)(queue + 8) - 1;
    wrapAdjust = ~(((s32)writeIndex - maxIndex) | (maxIndex - (s32)writeIndex)) >> 31;
    queue[1] = (writeIndex + 1) & ~wrapAdjust;
    OSRestoreInterrupts(irqState);
    return TRUE;
}

BOOL fn_80063A50(u8* queue, u32 value, u16 halfword, u32 word, u32 last) {
    /* Build and enqueue a 0x30-byte WPAD command packet into the ring buffer at queue (indices at +0/+1, buffer base at +4, capacity at +8). Returns FALSE if full. */
    u8 buf[0x68] ALIGN(8);
    s8 diff;
    BOOL enabled;
    BOOL innerEnabled;
    u32 copiedWord;
    u16 copiedHalfword;
    s8 index;
    s32 lastIndex;
    s32 wrapMask;

    *(u16*)&buf[0] = halfword;
    *(u32*)&buf[4] = word;
    *(u32*)&buf[0x38] = 0x17;
    *(u16*)&buf[0x52] = 6;
    *(u32*)&buf[0x64] = last;
    memcpy(&buf[0x3c], &buf[4], 4);
    memcpy(&buf[0x40], &buf[0], 2);

    copiedHalfword = *(u16*)&buf[0];
    copiedWord = *(u32*)&buf[4];
    *(u32*)&buf[0x54] = value;
    *(double*)&buf[8] = *(double*)&buf[0x38];
    *(double*)&buf[0x10] = *(double*)&buf[0x40];
    *(double*)&buf[0x18] = *(double*)&buf[0x48];
    *(double*)&buf[0x20] = *(double*)&buf[0x50];
    *(u16*)&buf[0x58] = copiedHalfword;
    *(u32*)&buf[0x5c] = copiedWord;
    *(double*)&buf[0x28] = *(double*)&buf[0x58];
    *(double*)&buf[0x30] = *(double*)&buf[0x60];

    enabled = OSDisableInterrupts();
    innerEnabled = OSDisableInterrupts();
    diff = (s8)(queue[1] - queue[0]);
    if (diff < 0)
        diff = (s8)(diff + *(u32*)(queue + 8));
    OSRestoreInterrupts(innerEnabled);

    if (*(u32*)(queue + 8) - 1 == (u32)diff) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    memset(*(u8**)(queue + 4) + (s8)queue[1] * 0x30, 0, 0x30);
    memcpy(*(u8**)(queue + 4) + (s8)queue[1] * 0x30, buf + 8, 0x30);

    index = (s8)queue[1];
    lastIndex = *(u32*)(queue + 8) - 1;
    wrapMask = ~(((s32)index - lastIndex) | (lastIndex - (s32)index)) >> 31;
    queue[1] = (index + 1) & ~wrapMask;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* Reset a WPAD command queue by clearing its front/back indices and zeroing all
 * queued command slots, while holding interrupts disabled. */
void WPADiClearQueue_80063BD4(WPADCommandQueue* pQueue) {
	s32 enabled = OSDisableInterrupts();

	pQueue->front = 0;
	pQueue->back = 0;
	memset(pQueue->buffer, 0, pQueue->capacity * sizeof(WPADCommand));

	OSRestoreInterrupts(enabled);
}

void getDevConfig(s32 chan, s32 result, WPADStatus* status, u8* data)
{
    const char* messages = (const char*)lbl_80312338;
    u8* p = (u8*)lbl_8038F4F0[chan];
    u16 valueCC8 = lbl_80560CC8;
    u16 valueCCA = lbl_80560CCA;
    u16 valueCCC = lbl_80560CCC;
    u16 valueCCE = lbl_80560CCE;
    u16 valueCD0 = lbl_80560CD0;
    u16 valueCD2 = lbl_80560CD2;
    u16 valueCD4 = lbl_80560CD4;
    u16 valueCD6 = lbl_80560CD6;
    u8* config = *(u8**)(p + 0x8B4);
    u32 sum;
    s32 i;
    s32 offset;
    u8 attempt;

    *(u16*)&status->obj[0].x = valueCC8;
    *(u16*)&status->obj[0].y = valueCD0;
    status->obj[0].size = *(u16*)(p + 0x804);
    status->obj[0].traceId = 0;
    *(u16*)&status->obj[1].x = valueCCA;
    *(u16*)&status->obj[1].y = valueCD2;
    status->obj[1].size = *(u16*)(p + 0x804);
    status->obj[1].traceId = 1;
    *(u16*)&status->obj[2].x = valueCCC;
    *(u16*)&status->obj[2].y = valueCD4;
    status->obj[2].size = *(u16*)(p + 0x804);
    status->obj[2].traceId = 2;
    *(u16*)&status->obj[3].x = valueCCE;
    *(u16*)&status->obj[3].y = valueCD6;
    status->obj[3].size = *(u16*)(p + 0x804);
    status->obj[3].traceId = 3;
    *(s16*)(p + 0x7b4) = 0x212;
    *(s16*)(p + 0x7b6) = 0x212;
    *(s16*)(p + 0x7b8) = 0x212;
    *(s16*)(p + 0x7ba) = 0x27C;
    *(s16*)(p + 0x7bc) = 0x27C;
    *(s16*)(p + 0x7be) = 0x27C;
    p[0x7C1] = 0;
    p[0x7C0] = 0;
    if (result == 0) {
        if (*(s32*)(p + 0x820) == 0) {
            for (attempt = 0; attempt < 2; attempt++) {
                offset = attempt * 11;
                sum = 0;
                for (i = offset; i < offset + 10; i++) {
                    sum += config[i];
                }
                if ((u8)(sum + 0x55) == config[offset + 10]) {
                    DBPrintf_80068D68(messages + 0x98);
                    status->obj[0].x = (s16)(u16)data[offset + 0] | ((data[offset + 2] & 48) << 4);
                    status->obj[0].y = 0x2FF - (s16)((s16)(u16)data[offset + 1] | ((data[offset + 2] & 192) << 2));
                    status->obj[0].size = *(u16*)(p + 0x804);
                    status->obj[0].traceId = 0;
                    status->obj[1].x = (s16)(u16)data[offset + 3] | ((data[offset + 2] & 3) << 8);
                    status->obj[1].y = 0x2FF - (s16)((s16)(u16)data[offset + 4] | ((data[offset + 2] & 12) << 6));
                    status->obj[1].size = *(u16*)(p + 0x804);
                    status->obj[1].traceId = 1;
                    status->obj[2].x = (s16)(u16)data[offset + 5] | ((data[offset + 7] & 48) << 4);
                    status->obj[2].y = 0x2FF - (s16)((s16)(u16)data[offset + 6] | ((data[offset + 7] & 192) << 2));
                    status->obj[2].size = *(u16*)(p + 0x804);
                    status->obj[2].traceId = 2;
                    status->obj[3].x = (s16)(u16)data[offset + 8] | ((data[offset + 7] & 12) << 8);
                    status->obj[3].y = 0x2FF - (s16)((s16)(u16)data[offset + 9] | ((data[offset + 7] & 12) << 6));
                    status->obj[3].size = *(u16*)(p + 0x804);
                    status->obj[3].traceId = 3;
                    break;
                }
                DBPrintf_80068D68(messages + 0xB0);
            }
        } else {
            DBPrintf_80068D68(messages + 0xC8);
        }
        for (attempt = 0; attempt < 2; attempt++) {
            offset = attempt * 10;
            sum = 0;
            if (*(s32*)(p + 0x820) == 0) {
                offset += 22;
            }
            for (i = offset; i < offset + 9; i++) {
                sum += config[i];
            }
            if ((u8)(sum + 0x55) == config[offset + 9]) {
                DBPrintf_80068D68(messages + 0x10C);
                *(s16*)(p + 0x7b4) = (config[offset + 0] << 2) | ((config[offset + 3] >> 4) & 3);
                *(s16*)(p + 0x7b6) = (config[offset + 1] << 2) | ((config[offset + 3] >> 2) & 3);
                *(s16*)(p + 0x7b8) = (config[offset + 2] << 2) | ((config[offset + 3] >> 0) & 3);
                *(s16*)(p + 0x7ba) = (config[offset + 4] << 2) | ((config[offset + 7] >> 4) & 3);
                *(s16*)(p + 0x7bc) = (config[offset + 5] << 2) | ((config[offset + 7] >> 2) & 3);
                *(s16*)(p + 0x7be) = (config[offset + 6] << 2) | ((config[offset + 7] >> 0) & 3);
                p[0x7C1] = config[offset + 8] & 0x7F;
                p[0x7C0] = config[offset + 8] & 0x80;
                break;
            }
            DBPrintf_80068D68(messages + 0x118);
        }
        DBPrintf_80068D68(messages + 0x128, *(s16*)(p + 0x7B4), *(s16*)(p + 0x7B6), *(s16*)(p + 0x7B8));
        DBPrintf_80068D68(messages + 0x150, *(s16*)(p + 0x7BA), *(s16*)(p + 0x7BC), *(s16*)(p + 0x7BE));
        DBPrintf_80068D68(messages + 0x178, p[0x7C1], p[0x7C0]);
    }
}

/* Parse the 0x20-byte extension-controller config block read back from the
   extension register: check the two 16-byte blocksums and store the stick and
   accelerometer calibration in the channel's extension config. On failure the
   channel is marked as an unsupported extension. */
void parseExtConfig(s32 chan, s32 result) {
    const char* debugStrings = (const char*)lbl_80312338;
    WPADCB* cb = lbl_8038F4F0[chan];
    WPADExtConfig* ext = (WPADExtConfig*)((u8*)cb + 0x7C2);
    u8* configData = (u8*)cb->samplingBufSize;
    s32 validOffset = -1;
    s32 blockIdx;
    s32 offset;
    s32 byteIdx;
    s32 blockSum;
    if (result != 0) {
        cb->UNK_0x801 = WPAD_DEV_NOT_SUPPORTED;
    } else if ((u8)(cb->UNK_0x801 + 0xFF) <= 1) {
        WPADiDecode(chan, configData, 0x20, 0x20);
        for (blockIdx = 0; blockIdx < 2; blockIdx++) {
            offset = blockIdx * 16;
            blockSum = 0;
            for (byteIdx = offset; byteIdx < offset + 14; byteIdx++) {
                blockSum += configData[byteIdx];
            }
            if ((u8)(blockSum + WPAD_CONFIG_BLOCK_CHECKSUM_BIAS) == configData[offset + 14] && (u8)(blockSum + 0xAA) == configData[offset + 15]) {
                validOffset = offset;
            }
        }
        switch (cb->UNK_0x801) {
        case WPAD_DEV_FREESTYLE:
            if (validOffset < 0) {
                DBPrintf_80068D68(debugStrings + 0x194);
                ext->fs.accX0g = 0x200;
                ext->fs.accY0g = 0x200;
                ext->fs.accZ0g = 0x200;
                ext->fs.accX1g = 0x2CC;
                ext->fs.accY1g = 0x2CC;
                ext->fs.accZ1g = 0x2CC;
            } else {
                u8* p = (u8*)(validOffset + (s32)configData);
                u8 b0 = configData[validOffset];
                ext->fs.accX0g = (u16)((b0 << 2) | ((p[3] >> 4) & 3));
                ext->fs.accY0g = (u16)((p[1] << 2) | ((p[3] >> 2) & 3));
                ext->fs.accZ0g = (u16)((p[2] << 2) | (p[3] & 3));
                ext->fs.accX1g = (u16)((p[4] << 2) | ((p[7] >> 4) & 3));
                ext->fs.accY1g = (u16)((p[5] << 2) | ((p[7] >> 2) & 3));
                ext->fs.accZ1g = (u16)((p[6] << 2) | (p[7] & 3));
                ext->fs.stickXMax = (s8)p[8];
                ext->fs.stickXMin = (s8)p[9];
                ext->fs.stickXCenter = (s8)p[10];
                ext->fs.stickYMax = (s8)p[11];
                ext->fs.stickYMin = (s8)p[12];
                ext->fs.stickYCenter = (s8)p[13];
                DBPrintf_80068D68(debugStrings + 0x1a8, ext->fs.accX0g, ext->fs.accY0g, ext->fs.accZ0g);
                DBPrintf_80068D68(debugStrings + 0x1d8, ext->fs.accX1g, ext->fs.accY1g, ext->fs.accZ1g);
                DBPrintf_80068D68(debugStrings + 0x208, ext->fs.stickXCenter, ext->fs.stickXMax, ext->fs.stickXMin);
                DBPrintf_80068D68(debugStrings + 0x230, ext->fs.stickYCenter, ext->fs.stickYMax, ext->fs.stickYMin);
            }
            break;
        case WPAD_DEV_CLASSIC: {
            u8* p = (u8*)(validOffset + (s32)configData);
            ext->cl.lStickXMax = (s8)configData[validOffset];
            ext->cl.lStickXMin = (s8)p[1];
            ext->cl.lStickXCenter = (s8)p[2];
            ext->cl.lStickYMax = (s8)p[3];
            ext->cl.lStickYMin = (s8)p[4];
            ext->cl.lStickYCenter = (s8)p[5];
            ext->cl.rStickXMax = (s8)p[6];
            ext->cl.rStickXMin = (s8)p[7];
            ext->cl.rStickXCenter = (s8)p[8];
            ext->cl.rStickYMax = (s8)p[9];
            ext->cl.rStickYMin = (s8)p[10];
            ext->cl.rStickYCenter = (s8)p[11];
            ext->cl.triggerLZero = p[12];
            ext->cl.triggerRZero = p[13];
            DBPrintf_80068D68(debugStrings + 0x258, ext->cl.lStickXCenter, ext->cl.lStickXMax, ext->cl.lStickXMin);
            DBPrintf_80068D68(debugStrings + 0x280, ext->cl.lStickYCenter, ext->cl.lStickYMax, ext->cl.lStickYMin);
            DBPrintf_80068D68(debugStrings + 0x2a8, ext->cl.rStickXCenter, ext->cl.rStickXMax, ext->cl.rStickXMin);
            DBPrintf_80068D68(debugStrings + 0x2d0, ext->cl.rStickYCenter, ext->cl.rStickYMax, ext->cl.rStickYMin);
            DBPrintf_80068D68(debugStrings + 0x2f8, ext->cl.triggerLZero, ext->cl.triggerRZero);
            break;
        }
        default:
            break;
        }
        *((u8*)cb + 0x851) = 0;
    }
    if (*(WPADCallback*)((u8*)cb + 0x7dc) != NULL) {
        (*(WPADCallback*)((u8*)cb + 0x7dc))(chan, cb->UNK_0x801);
        *(WPADCallback*)((u8*)cb + 0x7dc) = NULL;
    }
}

/* Decode the 2-byte extension-type report read back from the controller: byte 0 is
 * stored as the extension mode, byte 1 selects the extension type (0 -> 1,
 * 1 -> 2, other -> 0xFB), and a type of 2 is rejected unless the mode is 1..3.
 * On read failure the type is marked invalid and the mode cleared. */
void fn_80064740(s32 chan, s32 result) {
    WPADCB* cb = lbl_8038F4F0[chan];
    u8* data = (u8*)cb->samplingBufSize;
    if (result == 0) {
        WPADiDecode(chan, data, 2, 0xfe);
        cb->UNK_0x802 = data[0];
        switch (data[1]) {
        case 0:
            cb->UNK_0x801 = 1;
            break;
        case 1:
            cb->UNK_0x801 = 2;
            break;
        default:
            cb->UNK_0x801 = 0xfb;
            break;
        }
        if (cb->UNK_0x801 == 2) {
            if (cb->UNK_0x802 < 1 || cb->UNK_0x802 > 3) {
                cb->UNK_0x801 = 0xfc;
            }
        }
        DBPrintf_80068D68(lbl_80312648, cb->UNK_0x801);
        DBPrintf_80068D68(lbl_80312654, cb->UNK_0x802);
    } else {
        cb->UNK_0x801 = 0xfc;
        cb->UNK_0x802 = 0;
    }
}

#pragma push
/* Handle a Wii Remote game-info report (report ID 0x2A/0x62): checksum the 47 raw
 * bytes against (sum + 0x55) and, if valid, copy the 0x38-byte payload into the
 * control block and mark the result slot at (u8)resultSlot*4 + 0x38 with 0 on
 * success or -4 (checksum failure).  No-op when sd is nonzero. */
void getGameInfo(s32 chan, s32 sd, s32 resultSlot) {
    WPADCB* cb = lbl_8038F4F0[chan];
    u8* src = (u8*)cb->samplingBufSize;
    s32 i;
    u8 sum = 0;

    if (sd == 0) {
        for (i = 0; i < 0x2F; i++) {
            sum += src[i];
        }
        if (src[0x2F] == (u8)(sum + 0x55)) {
            memcpy(cb, src, 0x38);
            *(s32*)((u8*)cb + (u8)resultSlot * 4 + 0x38) = 0;
        } else {
            *(s32*)((u8*)cb + (u8)resultSlot * 4 + 0x38) = -4;
        }
    }
}
#pragma pop
/* Dispatches an incoming WPAD HID report to the handler for its report ID and performs per-port post-processing. */
s32 WPADiHIDParser(u8 port, u8* p_rpt) {
#pragma dont_inline on
    BOOL enabled;
    s32 result = 0;

    if (p_rpt[0] >= 0x20 && p_rpt[0] <= 0x3F) {
        enabled = OSDisableInterrupts();
        lbl_80312338[p_rpt[0] - 0x20](port, p_rpt);
        OSRestoreInterrupts(enabled);
        WPADiExcludeButton(port);
        fn_80060AFC(port);
    } else {
        result = -1;
    }

    return result;
}

#pragma opt_propagation off
/* Extension-command reply callback: clears the extension command queue and updates the
 * controller's extension-kind byte (0xfd = detached, 0xfc = attached) before notifying
 * the callback held at +0x7E0.  A reply value of zero is ignored. */
void fn_80064A80(s32 chan, s32 extResult) {
    WPADCB* cb = lbl_8038F4F0[chan];
    if (extResult != 0) {
        u8 extKind;
        WPADiClearQueue_80063BD4(&cb->extCmdQueue);
        if (extResult == -1) {
            extKind = 0xfd;
        } else {
            s32 attached = cb->info.attach;
            s32 sign = (-attached | attached) >> 31;
            extKind = (u8)sign & 0xfc;
        }
        cb->UNK_0x801 = extKind;
        if (*(s32*)((u8*)cb + 0x7e0) != 0) {
            ((WPADCallback)*(void**)((u8*)cb + 0x7e0))(chan, extKind);
        }
    }
}
#pragma opt_propagation reset
// fn_80064B1C: WPAD data processing
void fn_80064B1C(s32 chan, void* data) {
    register const char* strBase asm("r31") = (const char*)lbl_80312338;
    register s32 channel asm("r26") = chan;
    register void* report asm("r27") = data;
    register u8* p asm("r29");
    register s32 enabled asm("r30");
    register u8* buf asm("r28");
    register s32 i asm("r5");
    register WPADCallback cbk asm("r24");
    register WPADCommandQueue* q asm("r25");
    s32 old;
    s32 oldReport;
    u32 v;
    s32 signBit;
    DBPrintf_80068D68(strBase + 0x328);
    enabled = OSDisableInterrupts();
    p = (u8*)lbl_8038F4F0[(u8)channel];
    old = *(s32*)(p + 0x81C);
    if (old == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }
    buf = p + 0xA0 + p[0x806] * 0x60;
    for (i = 0; i < 96; i++) buf[i] = 0;
    oldReport = *(s32*)(p + 0x780);
    i = ((u8*)report)[2];
    *(u16*)buf = (u16)((((u8*)report)[1] | (i << 8)) & 0x9f1f);
    signBit = ((u32)((u8*)report)[1] & 0x80) << 17;
    *(s32*)(p + 0x788) = signBit >> 7;
    *(s32*)(p + 0x778) = (((u8*)report)[3] >> 3) & 1;
    *(s32*)(p + 0x77C) = (((u8*)report)[3] >> 2) & 1;
    *(s32*)(p + 0x780) = (((u8*)report)[3] >> 1) & 1;
    *(s32*)(p + 0x784) = ((u8*)report)[3] & 1;
    p[0x78D] = (u8)(((u32)((u8*)report)[3] >> 4) & 0xF);
    p[0x78E] = 0;
    p[0x78F] = ((u8*)report)[5] & 0xf0;
    v = ((u8*)report)[6];
    if (v >= 0x55) p[0x78C] = 4;
    else if (v >= 0x44) p[0x78C] = 3;
    else if (v >= 0x33) p[0x78C] = 2;
    else if (v >= 3) p[0x78C] = 1;
    else p[0x78C] = 0;
    if (*(s32*)(p + 0x780) != 0) {
        if (oldReport == 0) {
            DBPrintf_80068D68(strBase + 0x33c);
            q = (WPADCommandQueue*)(p + 0x5ec);
            cbk = *(WPADCallback*)(p + 0x7e0);
            fn_80063564(q, *(s32*)(p + 0x7f8), (void*)0);
            WPADiSendWriteDataCmd_80063744(q, 0xaa, 0x4A400F0, fn_80064A80);
            fn_800684D0(channel);
            WPADiEnqueueCommand((u8*)q, p + 0x854, 6, 0x4A40040, (u32)fn_80064A80);
            WPADiEnqueueCommand((u8*)q, p + 0x85a, 6, 0x4A40046, (u32)fn_80064A80);
            WPADiEnqueueCommand((u8*)q, p + 0x860, 4, 0x4A4004C, (u32)fn_80064A80);
            fn_80063A50((u8*)q, (u32)(p + 0x874), 2, 0x4A400FE, (u32)fn_80064A80);
            fn_80063A50((u8*)q, (u32)(p + 0x874), 0x20, 0x4A40020, (u32)cbk);
            p[0x851] = 0;
            p[0x801] = 0xff;
            p[0x802] = 0;
            if (cbk != ((void*)0)) cbk(channel, 0xff);
        } else {
            DBPrintf_80068D68(strBase + 0x354);
        }
    } else {
        p[0x801] = 0;
        p[0x802] = 0;
        if (oldReport != 0) {
            WPADiClearQueue_80063BD4((WPADCommandQueue*)(p + 0x5ec));
            fn_80063564((WPADCommandQueue*)(p + 0x160), *(s32*)(p + 0x7f8), (void*)0);
            cbk = *(WPADCallback*)(p + 0x7e0);
            if (cbk != ((void*)0)) cbk(channel, 0);
        } else {
            DBPrintf_80068D68(strBase + 0x36c);
            if (*(void**)(p + 0x790) != ((void*)0)) {
                memcpy(*(void**)(p + 0x790), p + 0x778, 0x18);
                *(void**)(p + 0x790) = ((void*)0);
            }
            if (*(void**)(p + 0x7dc) != ((void*)0) && p[0x800]) {
                ((WPADCallback)*(void**)(p + 0x7dc))(channel, 0);
                *(void**)(p + 0x7dc) = ((void*)0);
            }
        }
    }
    *(s8*)(buf + 0x29) = -2;
    buf[0x28] = p[0x801];
    p[0x800] = 0;
    p[0x806] = (u8)((u32)__cntlzw(p[0x806]) >> 5);
    OSRestoreInterrupts(enabled);
}

// fn_80064F64: WPAD data processing
void fn_80064F64(s32 chan, void* data) {
    const char* strBase = (const char*)lbl_80312338;
    WPADCB* pCB;
    volatile u8* pBuf;
    u32 offset;
    u8 type;
    u8 ext;
    s32 enabled;
    u16 rptLen;
    s32 sd;
    s32 cb_8B8;
    WPADCallback callback;
    u8* p;
    u8 dataLen;
    s16 pos;

    enabled = OSDisableInterrupts();
    pCB = lbl_8038F4F0[(u8)chan];
    pBuf = (volatile u8*)pCB + *(u8*)((u8*)pCB + 0x806) * 0x60 + 0xA0;
    for (offset = 0; offset < 96; offset++) {
        pBuf[offset] = 0;
    }
    p = (u8*)data;
    *(u16*)pBuf = ((u16)p[1] | ((u16)p[2] << 8)) & 0x9F1F;
    type = p[3];
    ext = p[4];
    dataLen = (u8)((p[3] >> 4) + 1);
    rptLen = (u16)p[5] | ((u16)p[4] << 8);
    if (((p[3] & 0x0F) != 0)) {
        DBPrintf_80068D68(strBase + 0x384, type, ext);
        *(s32*)((u8*)pCB + 0x8BC) = -1;
        callback = *(WPADCallback*)((u8*)pCB + 0x7DC);
        if (callback) {
            callback(chan, -3);
            *(WPADCallback*)((u8*)pCB + 0x7DC) = 0;
            *(s32*)((u8*)pCB + 0x7FC) = 0;
        }
    }
    p = (u8*)data;
    cb_8B8 = *(s32*)((u8*)pCB + 0x8B8);
    cb_8B8 = (u16)cb_8B8;
    pos = (s16)(rptLen - cb_8B8);
    if ((u32)(u16)rptLen >= (u32)cb_8B8 && (u16)rptLen <= cb_8B8 + *(u16*)((u8*)pCB + 0x8C0)) {
        memcpy(*(u8**)((u8*)pCB + 0x8B4) + pos, p + 6, dataLen);
        if (cb_8B8 + *(u16*)((u8*)pCB + 0x8C0) == (u16)rptLen + dataLen) {
            DBPrintf_80068D68(strBase + 0x39C, *(s32*)((u8*)pCB + 0x8B8));
            DBPrintf_80068D68(strBase + 0x3B0, *(u16*)((u8*)pCB + 0x8C0));
        }
        cb_8B8 = *(s32*)((u8*)pCB + 0x8B8);
        sd = *(s32*)((u8*)pCB + 0x8BC) < 0 ? -3 : 0;
        if (cb_8B8 == 0) {
            if (*(s32*)((u8*)pCB + 0x820) != 0) {
                if ((u32)cb_8B8 == 0x176C && *(volatile s32*)((u8*)pCB + 0x820) == 1) {
                    getDevConfig(chan, sd, (WPADStatus*)pBuf, data);
                }
            }
            if (*(s32*)((u8*)pCB + 0x8B8) == 0x04A40020) {
                parseExtConfig(chan, sd);
            }
            if (*(s32*)((u8*)pCB + 0x8B8) == 0x04A400FE) {
                fn_80064740(chan, sd);
            }
            if (*(u32*)((u8*)pCB + 0x8B8) == 0x2A) {
                getGameInfo(chan, sd, 0);
            }
            if (*(u32*)((u8*)pCB + 0x8B8) == 0x62) {
                getGameInfo(chan, sd, 1);
            }
        }
        callback = *(WPADCallback*)((u8*)pCB + 0x7DC);
        if (callback) {
            callback(chan, sd);
            *(WPADCallback*)((u8*)pCB + 0x7DC) = 0;
            *(s32*)((u8*)pCB + 0x7FC) = 0;
        }
    } else {
        DBPrintf_80068D68(strBase + 0x3C0);
    }
    *(s8*)(pBuf + 0x29) = -2;
    pBuf[0x28] = *((u8*)pCB + 0x801);
    *((u8*)pCB + 0x806) = (u8)((u32)__cntlzw(*((u8*)pCB + 0x806)) >> 5);
    OSRestoreInterrupts(enabled);
}

// Decode a core-button (no accelerometer) input report from the remote on
// `chan` into the WPADStatus the application reads. The report's buttons are
// narrowed to the core set and written, with the last read's result and the
// attached extension's kind, into the control block's inactive receive buffer;
// flipping rxBufSel with interrupts off publishes it. WPADiDecodeAccStatus does
// the same with the accelerometer and fn_80065934 with an extension's data.
#define WPADiDecodeStatus fn_80065524
void WPADiDecodeStatus(s32 chan, WPADStatus* pReport)
{
    WPADCB* controlBlock;
    volatile u8* outBuf;
    WPADStatus* status;
    u32 i;
    BOOL irqState;
    u8* report = (u8*)pReport;

    irqState = OSDisableInterrupts();
    controlBlock = lbl_8038F4F0[(u8)chan];
    outBuf = (volatile u8*)controlBlock->rxBufs[controlBlock->rxBufSel];
    for (i = 0; i < RX_BUFFER_SIZE; i++) {
        outBuf[i] = 0;
    }
    status = (WPADStatus*)outBuf;
    status->button = ((u16)report[2] << 8) | report[1];
    status->button &= WPAD_BUTTON_CORE_ALL;
    if (controlBlock->readFormat == WPAD_FMT_CORE_BTN) {
        status->err = controlBlock->readStatus;
    } else if (controlBlock->readStatus == WPAD_ERR_OK) {
        status->err = WPAD_ERR_INVALID;
    }
    status->dev = controlBlock->UNK_0x801;
    controlBlock->info.nearempty = (report[1] >> 7) & 1;
    controlBlock->rxBufSel = !controlBlock->rxBufSel;
    OSRestoreInterrupts(irqState);
}

#define WPADiDecodeAccStatus fn_800656E8
void WPADiDecodeAccStatus(s32 chan, WPADStatusEx* pReport)
{
    /* Decode one core-button + accelerometer input report from the remote on
     * `chan` into the WPADStatusEx the application reads.
     *
     * pReport is the report as it came in, read as bytes: +1 is the status
     * byte (bit 7 says whether an extension is plugged in, bits 5-6 carry the
     * two low bits of the X accelerometer), +2 the high button byte, and +3
     * to +5 the eight high bits of the X, Y and Z accelerometer readings.
     * The decoded status goes into the control block's other receive buffer
     * - the one the application is not reading - which is cleared first;
     * flipping rxBufIndex at the end, with interrupts off, publishes it.
     * The readings are widened back to 10 bits and brought down to the
     * remote's zero-g calibration, and the buttons narrowed to the core set.
     * WPADiDecodeStatus does the same without the accelerometer and fn_80065934
     * with an extension's data. */
    typedef struct {
        u8 _head[0x788];
        u32 extDisconnected; /* 0x788 bit 7 of the last report's status byte */
        u8 _gap78C[0x7B4 - 0x78C];
        s16 accX0g;          /* 0x7B4 the remote's accelerometer zero-g ... */
        s16 accY0g;          /* 0x7B6 ... calibration (0x212 until read out ... */
        s16 accZ0g;          /* 0x7B8 ... of its memory; 0x7BA.. holds 1-g) */
        u8 _gap7BA[0x7F8 - 0x7BA];
        u32 dataFormat;      /* 0x7F8 WPADDataFormat the remote is set to */
        s32 status;          /* 0x7FC WPADResult of the last read */
        u8 _gap800;
        u8 extType;          /* 0x801 WPADDeviceType of the attached extension */
        u8 _gap802[0x806 - 0x802];
        u8 rxBufIndex;       /* 0x806 which rxBufs[] holds the last report */
    } CBView;

    WPADCB* pCB;
    volatile u8* pBuf;
    u32 i;
    BOOL enabled;
    u8* p = (u8*)pReport;
    CBView* cb;
    WPADStatusEx* pOut;

    pCB = lbl_8038F4F0[(u8)chan];
    cb = (CBView*)pCB;
    pBuf = (volatile u8*)pCB->rxBufs[cb->rxBufIndex];
    for (i = 0; i < RX_BUFFER_SIZE; i++) {
        pBuf[i] = 0;
    }
    pOut = (WPADStatusEx*)pBuf;
    pOut->button = ((u16)p[2] << 8) | p[1];
    pOut->button &= WPAD_BUTTON_CORE_ALL;
    if (cb->dataFormat <= (u32)WPAD_FMT_CORE_BTN_ACC) {
        pOut->err = cb->status;
    } else if (cb->status == WPAD_ERR_OK) {
        pOut->err = WPAD_ERR_INVALID;
    }
    pOut->dev = cb->extType;
    cb->extDisconnected = (p[1] >> 7) & 1;
    {
        s16 accX = p[3] << 2; /* the reading's high 8 bits ... */
        accX &= ~3;
        pOut->accX = (s16)(accX | ((p[1] >> 5) & 3)) - cb->accX0g; /* ... and its low 2 */
    }
    {
        s16 accY = p[4] << 2;
        accY &= ~3;
        pOut->accY = (s16)(accY | (s16)((p[2] >> 4) & 2)) - cb->accY0g;
    }
    {
        s16 accZ = p[5] << 2;
        accZ &= ~3;
        pOut->accZ = (s16)(accZ | (s16)((p[2] >> 5) & 2)) - cb->accZ0g;
    }
    enabled = OSDisableInterrupts();
    cb->rxBufIndex = !cb->rxBufIndex;
    OSRestoreInterrupts(enabled);
}

/* Decode one incoming WPAD report for `chan`: zero the active RX buffer, copy the raw
 * payload, and (when extension reporting is on) unpack/calibrate Classic or Freestyle
 * stick, trigger and button data for the connected controller. Interrupts are disabled
 * for the whole update. */
void fn_80065934(s32 chan, u8* data)
{
    typedef struct {
        u8 _head[0xA0];
        u8 rxBufs[2][RX_BUFFER_SIZE]; /* 0xA0 */
        u8 _gap160[0x780 - 0x160];
        u32 UNK_0x780;                /* 0x780 */
        u8 _gap784[0x788 - 0x784];
        u32 extDisconnected;          /* 0x788 */
        u8 _gap78C[0x7C2 - 0x78C];
        WPADExtConfig extCalib;       /* 0x7C2 */
        u8 _gap7DC[0x7F8 - 0x7DC];
        u32 dataFormat;               /* 0x7F8 */
        s32 status;                   /* 0x7FC */
        u8 _gap800;
        u8 extType;                   /* 0x801 */
        u8 UNK_0x802;                 /* 0x802 */
        u8 _gap803[0x806 - 0x803];
        u8 rxBufIndex;                /* 0x806 */
        u8 _gap807[0x851 - 0x807];
        u8 UNK_0x851;                 /* 0x851 */
    } CBView;

    CBView* cb;
    volatile s8* buf;
    WPADFSStatus* fs;
    WPADCLStatus* cl;
    u32 offset;
    u32 format;
    s16 x, y, v;
    s32 irqState;

    irqState = OSDisableInterrupts();
    cb = (CBView*)lbl_8038F4F0[(u8)chan];
    buf = (volatile s8*)cb->rxBufs[cb->rxBufIndex];
    for (offset = 0; offset < 96; offset++) {
        buf[offset] = 0;
    }
    *(u16*)buf = ((u16)data[2] << 8 | data[1]) & 0x9F1F;
    format = cb->dataFormat;
    if (format == 0 || format == 3 || format == 6) {
        buf[0x29] = cb->status;
    } else if (cb->status == 0) {
        buf[0x29] = -4;
    }
    buf[0x28] = cb->extType;
    cb->extDisconnected = (data[1] >> 7) & 1;
    memcpy(lbl_803928E8, data + 3, 8);
    WPADiDecode(chan, data + 3, 8, 0);
    if (cb->UNK_0x780 != 0) {
        if (cb->extType == 1) {
            fs = (WPADFSStatus*)cb->rxBufs[cb->rxBufIndex];
            fs->fsStickX = data[3];
            fs->fsStickY = data[4];
            fs->fsAccX = (s16)((s16)((s16)((s16)(data[5] << 2) & ~3) | ((s16)(data[8] >> 2) & 3)) - *(s16*)((u8*)cb + 0x7ce));
            fs->fsAccY = (s16)((s16)((s16)((s16)(data[6] << 2) & ~3) | ((s16)(data[8] >> 4) & 3)) - *(s16*)((u8*)cb + 0x7d0));
            fs->fsAccZ = (s16)((s16)((s16)((s16)(data[7] << 2) & ~3) | (data[8] >> 6)) - *(s16*)((u8*)cb + 0x7d2));
            fs->button |= ((~data[8]) & 3) << 13;
            if (cb->UNK_0x851 == 0) {
                cb->UNK_0x851 = 1;
                cb->extCalib.fs.stickXCenter = fs->fsStickX;
                cb->extCalib.fs.stickYCenter = fs->fsStickY;
            }
            x = (u8)fs->fsStickX - (u8)cb->extCalib.fs.stickXCenter;
            y = (u8)fs->fsStickY - (u8)cb->extCalib.fs.stickYCenter;
            if (x < -128) fs->fsStickX = -128;
            else if (x > 127) fs->fsStickX = 127;
            else fs->fsStickX = x;
            if (y < -128) fs->fsStickY = -128;
            else if (y > 127) fs->fsStickY = 127;
            else fs->fsStickY = y;
        } else if (cb->extType == 2) {
            switch (cb->UNK_0x802) {
            case 1:
                cl = (WPADCLStatus*)cb->rxBufs[cb->rxBufIndex];
                cl->clLStickX = (data[3] & 63) << 4;
                cl->clLStickY = (data[4] & 63) << 4;
                v = (s16)(data[5] >> 7) | ((s16)((s16)(data[3] >> 3) & 24) | (s16)((s16)(data[4] >> 5) & 6));
                v <<= 5;
                cl->clRStickX = v - 512;
                v = (data[5] & 31) << 5;
                cl->clRStickY = v - 512;
                cl->clTriggerL = (((s16)(data[5] >> 2) & 24) | (data[6] >> 5)) << 3;
                cl->clTriggerR = (data[6] & 31) << 3;
                cl->clButton = ((data[7] << 8) | data[8]) ^ 0xFFFF;
                break;
            case 2:
                cl = (WPADCLStatus*)cb->rxBufs[cb->rxBufIndex];
                cl->clLStickX = (s16)((s16)((s16)(data[3] << 2) & ~3) | ((data[7] >> 0) & 3)) - 512;
                v = data[4] << 2;
                v &= ~3;
                v |= (s16)(data[7] >> 2) & 3;
                cl->clRStickX = v - 512;
                v = data[5] << 2;
                v &= ~3;
                v |= (s16)(data[7] >> 4) & 3;
                cl->clLStickY = v - 512;
                v = data[6] << 2;
                v &= ~3;
                v |= data[7] >> 6;
                cl->clRStickY = v - 512;
                cl->clTriggerL = data[8];
                cl->clTriggerR = data[9];
                cl->clButton = ((data[10] << 8) | data[11]) ^ 0xFFFF;
                break;
            case 3:
                cl = (WPADCLStatus*)cb->rxBufs[cb->rxBufIndex];
                cl->clLStickX = (s16)((s16)(u16)data[3] << 2) - 512;
                cl->clRStickX = (s16)((s16)(u16)data[4] << 2) - 512;
                cl->clLStickY = (s16)((s16)(u16)data[5] << 2) - 512;
                cl->clRStickY = (s16)((s16)(u16)data[6] << 2) - 512;
                cl->clTriggerL = data[7];
                cl->clTriggerR = data[8];
                cl->clButton = ((data[9] << 8) | data[10]) ^ 0xFFFF;
                break;
            }
            if (cb->UNK_0x851 == 0) {
                cb->UNK_0x851 = 1;
                cb->extCalib.cl.lStickXCenter = cl->clLStickX;
                cb->extCalib.cl.lStickYCenter = cl->clLStickY;
                cb->extCalib.cl.rStickXCenter = cl->clRStickX;
                cb->extCalib.cl.rStickYCenter = cl->clRStickY;
                cb->extCalib.cl.triggerLZero = cl->clTriggerL;
                cb->extCalib.cl.triggerRZero = cl->clTriggerR;
            }
            x = cl->clLStickX - cb->extCalib.cl.lStickXCenter;
            y = cl->clLStickY - cb->extCalib.cl.lStickYCenter;
            if (x < -1024) cl->clLStickX = -1024;
            else if (x > 1023) cl->clLStickX = 1023;
            else cl->clLStickX = x;
            if (y < -1024) cl->clLStickY = -1024;
            else if (y > 1023) cl->clLStickY = 1023;
            else cl->clLStickY = y;
            x = cl->clRStickX - cb->extCalib.cl.rStickXCenter;
            y = cl->clRStickY - cb->extCalib.cl.rStickYCenter;
            if (x < -1024) cl->clRStickX = -1024;
            else if (x > 1023) cl->clRStickX = 1023;
            else cl->clRStickX = x;
            if (y < -1024) cl->clRStickY = -1024;
            else if (y > 1023) cl->clRStickY = 1023;
            else cl->clRStickY = y;
            x = cl->clTriggerL - cb->extCalib.cl.triggerLZero;
            y = cl->clTriggerR - cb->extCalib.cl.triggerRZero;
            if (x < 0) cl->clTriggerL = 0;
            else cl->clTriggerL = x;
            if (y < 0) cl->clTriggerR = 0;
            else cl->clTriggerR = y;
        }
        if (memcmp(lbl_803928E8, lbl_803123B8, 7) == 0 && (s8)buf[0x29] == 0) {
            buf[0x29] = -7;
        }
    }
    cb->rxBufIndex = (u8)((u32)__cntlzw(cb->rxBufIndex) >> 5);
    OSRestoreInterrupts(irqState);
}

// Decode one core button + accelerometer + IR (DPD) input report into the
// control block's other receive buffer; the WPADiDecodeStatus/WPADiDecodeAccStatus
// family, without extension data.
extern f32 lbl_80560CD8;
#define decodeCoreAccDpdReport fn_800660E8
void decodeCoreAccDpdReport(s32 chan, u8* data)
{
    /* View of the control-block fields this decoder touches. */
    typedef struct {
        u8 _head[0xA0];
        u8 rxBufs[2][RX_BUFFER_SIZE]; /* 0xA0 decoded reports, double buffered */
        u8 _gap160[0x788 - 0x160];
        u32 extDisconnected; /* 0x788 bit 7 of the last report's status byte */
        u8 _gap78C[0x7B4 - 0x78C];
        s16 accX0g; /* 0x7B4 accelerometer zero-g point, subtracted below */
        s16 accY0g; /* 0x7B6 */
        s16 accZ0g; /* 0x7B8 */
        u8 _gap7BA[0x7F8 - 0x7BA];
        u32 dataFormat; /* 0x7F8 WPADDataFormat the remote is set to */
        s32 status;     /* 0x7FC WPADResult of the last read */
        u8 _gap800;
        u8 extType;     /* 0x801 WPADDeviceType of the attached extension */
        u8 _gap802[0x806 - 0x802];
        u8 rxBufIndex;  /* 0x806 which rxBufs[] holds the last report */
    } CBView;

    WPADCB* pCB;
    volatile u8* pBuf;
    CBView* cb;
    WPADStatus* pStatus;
    u32 i;
    BOOL irqState;
    /* Raw report bytes: +1 status (bit 7: extension unplugged, bits 5-6: the two
     * low bits of acc X), +2 buttons (bits 4 and 5: the low bit of acc Y and of
     * acc Z), +3..5 the accelerometer high bytes, then four IR (DPD) objects of
     * three bytes each: x, y, and the byte holding both low x/y bit pairs and
     * the object size. */
    u8* report = data;

    pCB = lbl_8038F4F0[(u8)chan];
    cb = (CBView*)pCB;
    /* Decode into the buffer the application is not reading, then publish it. */
    pBuf = (volatile u8*)pCB->rxBufs[cb->rxBufIndex];
    for (i = 0; i < RX_BUFFER_SIZE; i++) {
        pBuf[i] = 0;
    }
    pStatus = (WPADStatus*)pBuf;
    pStatus->button = ((u16)report[1] | ((u16)report[2] << 8)) & WPAD_BUTTON_CORE_ALL;
    if (cb->dataFormat <= (u32)WPAD_FMT_CORE_BTN_ACC_DPD) {
        pStatus->err = cb->status;
    } else if (cb->status == WPAD_ERR_OK) {
        pStatus->err = WPAD_ERR_INVALID;
    }
    pStatus->dev = cb->extType;
    cb->extDisconnected = (s32)(report[1] & 0x80) >> 7;
    pStatus->accX = (s16)((s16)((s16)(report[3] << 2) & ~3) | ((s16)(report[1] >> 5) & 3)) - cb->accX0g;
    pStatus->accY = (s16)((s16)((s16)(report[4] << 2) & ~3) | (s16)((s16)(report[2] >> 4) & 2)) - cb->accY0g;
    pStatus->accZ = (s16)((s16)((s16)(report[5] << 2) & ~3) | (s16)((s16)(report[2] >> 5) & 2)) - cb->accZ0g;

    /* A size of 0, or a position on the edge of the sensor's 1024x768 field,
     * means the camera saw nothing there.  The size byte is a radius; the
     * 3.14159 factor turns it into the object's area. */
    pStatus->obj[0].x = (s16)(u16)report[6] | ((report[8] << 4) & 0x300);
    pStatus->obj[0].y = WPAD_MAX_DPD_Y - (s16)((s16)(u16)report[7] | ((report[8] << 2) & 0x300));
    pStatus->obj[0].size = report[8] & 0xF;
    pStatus->obj[0].size = (u8)(3.14159f * ((f32)(u32)pStatus->obj[0].size * (f32)(u32)pStatus->obj[0].size));
    if (pStatus->obj[0].size == 0 || pStatus->obj[0].x == WPAD_MAX_DPD_X || pStatus->obj[0].y == WPAD_MAX_DPD_Y) {
        pStatus->obj[0].x = 0;
        pStatus->obj[0].y = WPAD_MAX_DPD_Y;
        pStatus->obj[0].size = 0;
    }
    pStatus->obj[0].traceId = 0;

    pStatus->obj[1].x = (s16)(u16)report[9] | ((report[11] << 4) & 0x300);
    pStatus->obj[1].y = WPAD_MAX_DPD_Y - (s16)((s16)(u16)report[10] | ((report[11] << 2) & 0x300));
    pStatus->obj[1].size = report[11] & 0xF;
    pStatus->obj[1].size = (u8)(3.14159f * ((f32)(u32)pStatus->obj[1].size * (f32)(u32)pStatus->obj[1].size));
    if (pStatus->obj[1].size == 0 || pStatus->obj[1].x == WPAD_MAX_DPD_X || pStatus->obj[1].y == WPAD_MAX_DPD_Y) {
        pStatus->obj[1].x = 0;
        pStatus->obj[1].y = WPAD_MAX_DPD_Y;
        pStatus->obj[1].size = 0;
    }
    pStatus->obj[1].traceId = 1;

    pStatus->obj[2].x = (s16)(u16)report[12] | ((report[14] << 4) & 0x300);
    pStatus->obj[2].y = WPAD_MAX_DPD_Y - (s16)((s16)(u16)report[13] | ((report[14] << 2) & 0x300));
    pStatus->obj[2].size = report[14] & 0xF;
    pStatus->obj[2].size = (u8)(3.14159f * ((f32)(u32)pStatus->obj[2].size * (f32)(u32)pStatus->obj[2].size));
    if (pStatus->obj[2].size == 0 || pStatus->obj[2].x == WPAD_MAX_DPD_X || pStatus->obj[2].y == WPAD_MAX_DPD_Y) {
        pStatus->obj[2].x = 0;
        pStatus->obj[2].y = WPAD_MAX_DPD_Y;
        pStatus->obj[2].size = 0;
    }
    pStatus->obj[2].traceId = 2;

    pStatus->obj[3].x = (s16)(u16)report[15] | ((report[17] << 4) & 0x300);
    pStatus->obj[3].y = WPAD_MAX_DPD_Y - (s16)((s16)(u16)report[16] | ((report[17] << 2) & 0x300));
    pStatus->obj[3].size = report[17] & 0xF;
    pStatus->obj[3].size = (u8)(3.14159f * ((f32)(u32)pStatus->obj[3].size * (f32)(u32)pStatus->obj[3].size));
    if (pStatus->obj[3].size == 0 || pStatus->obj[3].x == WPAD_MAX_DPD_X || pStatus->obj[3].y == WPAD_MAX_DPD_Y) {
        pStatus->obj[3].x = 0;
        pStatus->obj[3].y = WPAD_MAX_DPD_Y;
        pStatus->obj[3].size = 0;
    }
    pStatus->obj[3].traceId = 3;

    /* Swapping the buffer index with interrupts off publishes the new report. */
    irqState = OSDisableInterrupts();
    cb->rxBufIndex = (u8)((u32)__cntlzw(cb->rxBufIndex) >> 5);
    OSRestoreInterrupts(irqState);
}

/*
 * No-op stub - the compiled body is a single `blr`.  The SDK leaves it here
 * among the HID report parsers (fn_80066634 below decodes the frequency
 * sensor / classic-controller extension data into the channel's control
 * block); nothing is ever done in this one.
 */
void fn_80066630(void) {
    //
}

// fn_80066634: WPAD data processing
void fn_80066634(s32 chan, u8* data)
{
    typedef struct {
        u8 _head[0xA0];
        u8 rxBufs[2][RX_BUFFER_SIZE]; /* 0xA0 */
        u8 _gap160[0x780 - 0x160];
        u32 UNK_0x780;                /* 0x780 */
        u8 _gap784[0x788 - 0x784];
        u32 extDisconnected;          /* 0x788 */
        u8 _gap78C[0x7B4 - 0x78C];
        s16 accX0g;                   /* 0x7B4 */
        s16 accY0g;                   /* 0x7B6 */
        s16 accZ0g;                   /* 0x7B8 */
        u8 _gap7BA[0x7C2 - 0x7BA];
        WPADExtConfig extCalib;       /* 0x7C2 */
        u8 _gap7DC[0x7F8 - 0x7DC];
        u32 dataFormat;               /* 0x7F8 */
        s32 status;                   /* 0x7FC */
        u8 _gap800;
        u8 extType;                   /* 0x801 */
        u8 UNK_0x802;                 /* 0x802 */
        u8 _gap803[0x806 - 0x803];
        u8 rxBufIndex;                /* 0x806 */
        u8 _gap807[0x851 - 0x807];
        u8 UNK_0x851;                 /* 0x851 */
    } CBView;

    CBView* cb;
    volatile s8* buf;
    WPADFSStatus* fs;
    WPADCLStatus* cl;
    u32 offset;
    u32 format;
    s16 x, y, v;
    s32 bits;
    s32 enabled;
    cb = (CBView*)lbl_8038F4F0[(u8)chan];
    buf = (volatile s8*)cb->rxBufs[cb->rxBufIndex];
    for (offset = 0; offset < 96; offset++) {
        buf[offset] = 0;
    }
    *(u16*)buf = ((u16)data[2] << 8 | data[1]) & 0x9F1F;
    format = cb->dataFormat;
    if (format == 0 || format == 1 || format == 3 || format == 4 || format == 6 || format == 7) {
        buf[0x29] = cb->status;
    } else if (cb->status != 0) {
        buf[0x29] = -4;
    }
    buf[0x28] = cb->extType;
    cb->extDisconnected = (data[1] >> 7) & 1;
    {
        s16 a = data[3] << 2;
        a &= ~3;
        *(s16*)(buf + 2) = (s16)(a | ((data[1] >> 5) & 3)) - cb->accX0g;
    }
    {
        s16 b = data[4] << 2;
        b &= ~3;
        *(s16*)(buf + 4) = (s16)(b | (s16)((data[2] >> 4) & 2)) - cb->accY0g;
    }
    {
        s16 c = data[5] << 2;
        c &= ~3;
        *(s16*)(buf + 6) = (s16)(c | (s16)((data[2] >> 5) & 2)) - cb->accZ0g;
    }
    memcpy(lbl_803928E8, data + 6, 0x10);
    WPADiDecode(chan, data + 6, 0x10, 0);
    if (cb->UNK_0x780 != 0) {
        if (cb->extType == 1) {
            fs = (WPADFSStatus*)cb->rxBufs[cb->rxBufIndex];
            fs->fsStickX = data[6];
            fs->fsStickY = data[7];
            fs->fsAccX = (s16)((s16)((s16)((s16)(data[8] << 2) & ~3) | ((s16)(data[11] >> 2) & 3)) - cb->extCalib.fs.accX0g);
            fs->fsAccY = (s16)((s16)((s16)((s16)(data[9] << 2) & ~3) | ((s16)(data[11] >> 4) & 3)) - cb->extCalib.fs.accY0g);
            fs->fsAccZ = (s16)((s16)((s16)((s16)(data[10] << 2) & ~3) | (data[11] >> 6)) - cb->extCalib.fs.accZ0g);
            fs->button |= ((~data[11]) & 3) << 13;
            if (cb->UNK_0x851 == 0) {
                cb->UNK_0x851 = 1;
                cb->extCalib.fs.stickXCenter = fs->fsStickX;
                cb->extCalib.fs.stickYCenter = fs->fsStickY;
            }
            x = (u8)fs->fsStickX - (u8)cb->extCalib.fs.stickXCenter;
            y = (u8)fs->fsStickY - (u8)cb->extCalib.fs.stickYCenter;
            if (x < -128) fs->fsStickX = -128;
            else if (x > 127) fs->fsStickX = 127;
            else fs->fsStickX = x;
            if (y < -128) fs->fsStickY = -128;
            else if (y > 127) fs->fsStickY = 127;
            else fs->fsStickY = y;
        } else if (cb->extType == 2) {
            switch (cb->UNK_0x802) {
            case 1:
                cl = (WPADCLStatus*)cb->rxBufs[cb->rxBufIndex];
                cl->clLStickX = (s16)((data[6] & 63) << 4) - 512;
                cl->clLStickY = (s16)((data[7] & 63) << 4) - 512;
                v = (data[8] >> 7) | (((s16)(data[6] >> 3) & 24) | ((s16)(data[7] >> 5) & 6));
                v <<= 5;
                cl->clRStickX = v - 512;
                v = (data[8] & 31) << 5;
                cl->clRStickY = v - 512;
                cl->clTriggerL = (((s16)(data[8] >> 2) & 24) | (data[9] >> 5)) << 3;
                cl->clTriggerR = (data[9] & 31) << 3;
                cl->clButton = ((data[10] << 8) | data[11]) ^ 0xFFFF;
                break;
            case 2:
                cl = (WPADCLStatus*)cb->rxBufs[cb->rxBufIndex];
                cl->clLStickX = (s16)((s16)((s16)(data[6] << 2) & ~3) | ((data[10] >> 0) & 3)) - 512;
                v = data[7] << 2;
                v &= ~3;
                v |= (s16)(data[10] >> 2) & 3;
                cl->clRStickX = v - 512;
                v = data[8] << 2;
                v &= ~3;
                v |= (s16)(data[10] >> 4) & 3;
                cl->clLStickY = v - 512;
                v = data[9] << 2;
                v &= ~3;
                v |= data[10] >> 6;
                cl->clRStickY = v - 512;
                cl->clTriggerL = data[11];
                cl->clTriggerR = data[12];
                cl->clButton = ((data[13] << 8) | data[14]) ^ 0xFFFF;
                break;
            case 3:
                cl = (WPADCLStatus*)cb->rxBufs[cb->rxBufIndex];
                v = (s16)data[6];
                v <<= 2;
                cl->clLStickX = v - 512;
                v = (s16)data[7];
                v <<= 2;
                cl->clRStickX = v - 512;
                v = (s16)data[8];
                v <<= 2;
                cl->clLStickY = v - 512;
                v = (s16)data[9];
                v <<= 2;
                cl->clRStickY = v - 512;
                cl->clTriggerL = data[10];
                cl->clTriggerR = data[11];
                cl->clButton = ((data[12] << 8) | data[13]) ^ 0xFFFF;
                break;
            }
            if (cb->UNK_0x851 == 0) {
                cb->UNK_0x851 = 1;
                cb->extCalib.cl.lStickXCenter = cl->clLStickX;
                cb->extCalib.cl.lStickYCenter = cl->clLStickY;
                cb->extCalib.cl.rStickXCenter = cl->clRStickX;
                cb->extCalib.cl.rStickYCenter = cl->clRStickY;
                cb->extCalib.cl.triggerLZero = cl->clTriggerL;
                cb->extCalib.cl.triggerRZero = cl->clTriggerR;
            }
            x = cl->clLStickX - cb->extCalib.cl.lStickXCenter;
            y = cl->clLStickY - cb->extCalib.cl.lStickYCenter;
            if (x < -1024) cl->clLStickX = -1024;
            else if (x > 1023) cl->clLStickX = 1023;
            else cl->clLStickX = x;
            if (y < -1024) cl->clLStickY = -1024;
            else if (y > 1023) cl->clLStickY = 1023;
            else cl->clLStickY = y;
            x = cl->clRStickX - cb->extCalib.cl.rStickXCenter;
            y = cl->clRStickY - cb->extCalib.cl.rStickYCenter;
            if (x < -1024) cl->clRStickX = -1024;
            else if (x > 1023) cl->clRStickX = 1023;
            else cl->clRStickX = x;
            if (y < -1024) cl->clRStickY = -1024;
            else if (y > 1023) cl->clRStickY = 1023;
            else cl->clRStickY = y;
            x = cl->clTriggerL - cb->extCalib.cl.triggerLZero;
            y = cl->clTriggerR - cb->extCalib.cl.triggerRZero;
            if (x < 0) cl->clTriggerL = 0;
            else cl->clTriggerL = x;
            if (y < 0) cl->clTriggerR = 0;
            else cl->clTriggerR = y;
        }
        if (memcmp(lbl_803928E8, lbl_803123B8, 0x10) == 0 && (s8)buf[0x29] == 0) {
            buf[0x29] = -7;
        }
    }
    enabled = OSDisableInterrupts();
    cb->rxBufIndex = !cb->rxBufIndex;
    OSRestoreInterrupts(enabled);
}

// Empty placeholder: this WPAD function has no body in the original.
void fn_80066EAC(void) {
}

// fn_80066EB0: WPAD data processing
void fn_80066EB0(s32 arg0, u8 *arg1) {
    s32 enabled;
    s16 temp_r0;
    s16 temp_r0_10;
    s16 temp_r0_11;
    s16 temp_r0_2;
    s16 temp_r0_3;
    s16 temp_r0_4;
    s16 temp_r0_7;
    s16 temp_r0_9;
    s16 temp_r4_4;
    s16 temp_r4_5;
    s16 temp_r4_6;
    s16 temp_r5_8;
    WPADCB *temp_r31;
    volatile s8 *temp_r30;
    u8 *temp_r5;
    s32 var_r29;
    register s32 offset asm("r6");
    register s32 channel asm("r29") = arg0;
    u8 temp_r0_5;
    u8 temp_r0_6;
    u8 temp_r0_8;
    u8 *temp_r3;
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    s16 sensorHi;

    temp_r31 = lbl_8038F4F0[(u8)channel];
    temp_r5 = (u8*)temp_r31 + ((*(u8 *)((s8*)(temp_r31) + (0x806))) * 0x60);
    temp_r30 = (volatile s8*)(temp_r5 + 0xA0);
    for (offset = 0; offset < 96; offset++) {
        temp_r30[offset] = 0;
    }
    *(s16*)temp_r30 = (s16) ((((*(u8 *)((s8*)(arg1) + (1))) & ~0xFF00) | (((*(u8 *)((s8*)(arg1) + (2))) << 8) & 0xFF00)) & 0x9F1F);
    if ((u32) (*(u32 *)((s8*)(temp_r31) + (0x7F8))) <= 8U) {
        (*(u8 *)((s8*)(temp_r30) + (0x29))) = (u8) (*(s32 *)((s8*)(temp_r31) + (0x7FC)));
    } else if ((s32) (*(s32 *)((s8*)(temp_r31) + (0x7FC))) == 0) {
        (*(s8 *)((s8*)(temp_r30) + (0x29))) = -4;
    }
    (*(u8 *)((s8*)(temp_r30) + (0x28))) = (u8) (*(u8 *)((s8*)(temp_r31) + (0x801)));
    (*(s32 *)((s8*)(temp_r31) + (0x788))) = (s32) ((s32) ((*(u8 *)((s8*)(arg1) + (1))) & 0x80) >> 7);
    (*(s16 *)((s8*)(temp_r30) + (2))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (3))) * 4) & 0xFFFFFFFC) | (((s8) (*(u8 *)((s8*)(arg1) + (1))) >> 5) & 3)) - (*(s16 *)((s8*)(temp_r31) + (0x7B4))));
    (*(s16 *)((s8*)(temp_r30) + (4))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (4))) * 4) & 0xFFFFFFFC) | (s16) (((s8) (*(u8 *)((s8*)(arg1) + (2))) >> 4) & 2)) - (*(s16 *)((s8*)(temp_r31) + (0x7B6))));
    (*(s16 *)((s8*)(temp_r30) + (6))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (5))) * 4) & 0xFFFFFFFC) | (s16) (((s8) (*(u8 *)((s8*)(arg1) + (2))) >> 5) & 2)) - (*(s16 *)((s8*)(temp_r31) + (0x7B8))));

    sensorHi = (s16)arg1[6];
    temp_r0 = sensorHi | (s16)((arg1[8] << 4) & 0x300);
    (*(s16 *)((s8*)(temp_r30) + (8))) = temp_r0;
    (*(s16 *)((s8*)(temp_r30) + (0xA))) = (s16) (0x2FF - (s16) ((s16)arg1[7] | (s16)((arg1[8] << 2) & 0x300)));
    if ((temp_r0 == 0x3FF) || ((s16) (*(s16 *)((s8*)(temp_r30) + (0xA))) == 0x2FF)) {
        (*(s16 *)((s8*)(temp_r30) + (8))) = 0;
        (*(s16 *)((s8*)(temp_r30) + (0xA))) = 0x2FF;
        (*(u16 *)((s8*)(temp_r30) + (0xC))) = 0U;
    } else {
        (*(u16 *)((s8*)(temp_r30) + (0xC))) = (u16) (*(u16 *)((s8*)(temp_r31) + (0x804)));
    }
    (*(s8 *)((s8*)(temp_r30) + (0xE))) = 0;

    temp_r0_2 = (s16)arg1[9] | (s16)((arg1[8] & 3) << 8);
    (*(s16 *)((s8*)(temp_r30) + (0x10))) = temp_r0_2;
    (*(s16 *)((s8*)(temp_r30) + (0x12))) = (s16) (0x2FF - (s16) ((s16)arg1[10] | (s16)((arg1[8] << 6) & 0x300)));
    if ((temp_r0_2 == 0x3FF) || ((s16) (*(s16 *)((s8*)(temp_r30) + (0x12))) == 0x2FF)) {
        (*(s16 *)((s8*)(temp_r30) + (0x10))) = 0;
        (*(s16 *)((s8*)(temp_r30) + (0x12))) = 0x2FF;
        (*(u16 *)((s8*)(temp_r30) + (0x14))) = 0U;
    } else {
        (*(u16 *)((s8*)(temp_r30) + (0x14))) = (u16) (*(u16 *)((s8*)(temp_r31) + (0x804)));
    }
    (*(s8 *)((s8*)(temp_r30) + (0x16))) = 1;

    temp_r0_3 = (s16)arg1[11] | (s16)((arg1[13] << 4) & 0x300);
    (*(s16 *)((s8*)(temp_r30) + (0x18))) = temp_r0_3;
    (*(s16 *)((s8*)(temp_r30) + (0x1A))) = (s16) (0x2FF - (s16) ((s16)arg1[12] | (s16)((arg1[13] << 2) & 0x300)));
    if ((temp_r0_3 == 0x3FF) || ((s16) (*(s16 *)((s8*)(temp_r30) + (0x1A))) == 0x2FF)) {
        (*(s16 *)((s8*)(temp_r30) + (0x18))) = 0;
        (*(s16 *)((s8*)(temp_r30) + (0x1A))) = 0x2FF;
        (*(u16 *)((s8*)(temp_r30) + (0x1C))) = 0U;
    } else {
        (*(u16 *)((s8*)(temp_r30) + (0x1C))) = (u16) (*(u16 *)((s8*)(temp_r31) + (0x804)));
    }
    (*(s8 *)((s8*)(temp_r30) + (0x1E))) = 2;

    temp_r0_4 = (s16)arg1[14] | (s16)((arg1[13] << 8) & 0xC00);
    (*(s16 *)((s8*)(temp_r30) + (0x20))) = temp_r0_4;
    (*(s16 *)((s8*)(temp_r30) + (0x22))) = (s16) (0x2FF - (s16) ((s16)arg1[15] | (s16)((arg1[13] << 6) & 0x300)));
    if ((temp_r0_4 == 0x3FF) || ((s16) (*(s16 *)((s8*)(temp_r30) + (0x22))) == 0x2FF)) {
        (*(s16 *)((s8*)(temp_r30) + (0x20))) = 0;
        (*(s16 *)((s8*)(temp_r30) + (0x22))) = 0x2FF;
        (*(u16 *)((s8*)(temp_r30) + (0x24))) = 0U;
    } else {
        (*(u16 *)((s8*)(temp_r30) + (0x24))) = (u16) (*(u16 *)((s8*)(temp_r31) + (0x804)));
    }
    (*(s8 *)((s8*)(temp_r30) + (0x26))) = 3;

    memcpy(&lbl_803928E8, arg1 + 0x10, 6);
    WPADiDecode(channel, arg1 + 0x10, 6, 0);
    if ((s32) (*(s32 *)((s8*)(temp_r31) + (0x780))) != 0) {
        temp_r0_5 = (*(u8 *)((s8*)(temp_r31) + (0x801)));
        if (temp_r0_5 == 1) {
            temp_r3 = (u8*)temp_r31 + ((*(u8 *)((s8*)(temp_r31) + (0x806))) * 0x60);
            (*(u8 *)((s8*)(temp_r3) + (0xD0))) = (u8) (*(u8 *)((s8*)(arg1) + (0x10)));
            (*(u8 *)((s8*)(temp_r3) + (0xD1))) = (u8) (*(u8 *)((s8*)(arg1) + (0x11)));
            (*(s16 *)((s8*)(temp_r3) + (0xCA))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (0x12))) * 4) & 0xFFFFFFFC) | (((u8) (*(u8 *)((s8*)(arg1) + (0x15))) >> 2U) & 3)) - (*(s16 *)((s8*)(temp_r31) + (0x7CE))));
            (*(s16 *)((s8*)(temp_r3) + (0xCC))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (0x13))) * 4) & 0xFFFFFFFC) | (((u8) (*(u8 *)((s8*)(arg1) + (0x15))) >> 4U) & 3)) - (*(s16 *)((s8*)(temp_r31) + (0x7D0))));
            (*(s16 *)((s8*)(temp_r3) + (0xCE))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (0x14))) * 4) & 0xFFFFFFFC) | ((s32) (*(u8 *)((s8*)(arg1) + (0x15))) >> 6)) - (*(s16 *)((s8*)(temp_r31) + (0x7D2))));
            temp_r0_6 = (*(u8 *)((s8*)(arg1) + (0x15)));
            (*(u16 *)((s8*)(temp_r3) + (0xA0))) = (u16) ((*(u16 *)((s8*)(temp_r3) + (0xA0))) | ((~(temp_r0_6 | temp_r0_6) << 0xD) & 0x6000));
            if ((s32) (*(u8 *)((s8*)(temp_r31) + (0x851))) == 0) {
                (*(u8 *)((s8*)(temp_r31) + (0x851))) = 1U;
                (*(s16 *)((s8*)(temp_r31) + (0x7C2))) = (s16) (s8) (*(u8 *)((s8*)(temp_r3) + (0xD0)));
                (*(s16 *)((s8*)(temp_r31) + (0x7C8))) = (s16) (s8) (*(u8 *)((s8*)(temp_r3) + (0xD1)));
            }
            temp_r5_8 = (*(u8 *)((s8*)(temp_r3) + (0xD0))) - (u8) (*(s16 *)((s8*)(temp_r31) + (0x7C2)));
            temp_r0_7 = (*(u8 *)((s8*)(temp_r3) + (0xD1))) - (u8) (*(s16 *)((s8*)(temp_r31) + (0x7C8)));
            if (temp_r5_8 < -0x80) {
                (*(s8 *)((s8*)(temp_r3) + (0xD0))) = -0x80;
            } else if (temp_r5_8 > 0x7F) {
                (*(u8 *)((s8*)(temp_r3) + (0xD0))) = 0x7FU;
            } else {
                (*(u8 *)((s8*)(temp_r3) + (0xD0))) = (u8) temp_r5_8;
            }
            if (temp_r0_7 < -0x80) {
                (*(s8 *)((s8*)(temp_r3) + (0xD1))) = -0x80;
            } else if (temp_r0_7 > 0x7F) {
                (*(u8 *)((s8*)(temp_r3) + (0xD1))) = 0x7FU;
            } else {
                (*(u8 *)((s8*)(temp_r3) + (0xD1))) = (u8) temp_r0_7;
            }
        } else if (temp_r0_5 == 2) {
            temp_r0_8 = (*(u8 *)((s8*)(temp_r31) + (0x802)));
            switch ((s32) temp_r0_8) {              /* irregular */
            case 1:
                temp_r4 = (u8*)temp_r31 + ((*(u8 *)((s8*)(temp_r31) + (0x806))) * 0x60);
                var_r29 = (s32) (temp_r4 + 0xA0);
                (*(s16 *)((s8*)(temp_r4) + (0xCC))) = (s16) ((s16) (((*(u8 *)((s8*)(arg1) + (0x10))) * 0x10) & 0x3F0) - 0x200);
                (*(s16 *)((s8*)(temp_r4) + (0xCE))) = (s16) ((s16) (((*(u8 *)((s8*)(arg1) + (0x11))) * 0x10) & 0x3F0) - 0x200);
                (*(s16 *)((s8*)(var_r29) + (0x30))) = (s16) ((s16) ((s16) (((s32) (*(u8 *)((s8*)(arg1) + (0x12))) >> 7) | ((((u8) (*(u8 *)((s8*)(arg1) + (0x11))) >> 5U) & 6 & ~0x18) | (((u8) (*(u8 *)((s8*)(arg1) + (0x10))) >> 3U) & 0x18))) << 5) - 0x200);
                (*(s16 *)((s8*)(var_r29) + (0x32))) = (s16) ((s16) (((*(u8 *)((s8*)(arg1) + (0x12))) << 5) & 0x3E0) - 0x200);
                (*(s8 *)((s8*)(var_r29) + (0x34))) = (s8) ((((((s32) (*(u8 *)((s8*)(arg1) + (0x13))) >> 5) & ~0x18) | (((s32) (*(u8 *)((s8*)(arg1) + (0x12))) >> 2) & 0x18)) * 8) & 0xF8);
                (*(s8 *)((s8*)(var_r29) + (0x35))) = (s8) (((*(u8 *)((s8*)(arg1) + (0x13))) * 8) & 0xF8);
                (*(s16 *)((s8*)(var_r29) + (0x2A))) = (s16) ((((*(u8 *)((s8*)(arg1) + (0x15))) & ~0xFF00) | (((*(u8 *)((s8*)(arg1) + (0x14))) << 8) & 0xFF00)) ^ 0xFFFF);
                break;
            case 2:
                temp_r4_2 = (u8*)temp_r31 + ((*(u8 *)((s8*)(temp_r31) + (0x806))) * 0x60);
                (*(s16 *)((s8*)(temp_r4_2) + (0xCC))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (0x10))) * 4) & 0xFFFFFFFC) | ((*(u8 *)((s8*)(arg1) + (0x14))) & 3)) - 0x200);
                var_r29 = (s32) (temp_r4_2 + 0xA0);
                (*(s16 *)((s8*)(var_r29) + (0x30))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (0x11))) * 4) & 0xFFFFFFFC) | (((u8) (*(u8 *)((s8*)(arg1) + (0x14))) >> 2U) & 3)) - 0x200);
                (*(s16 *)((s8*)(var_r29) + (0x2E))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (0x12))) * 4) & 0xFFFFFFFC) | (((u8) (*(u8 *)((s8*)(arg1) + (0x14))) >> 4U) & 3)) - 0x200);
                (*(s16 *)((s8*)(var_r29) + (0x32))) = (s16) ((s16) ((s16) ((s16) ((*(u8 *)((s8*)(arg1) + (0x13))) * 4) & 0xFFFFFFFC) | ((s32) (*(u8 *)((s8*)(arg1) + (0x14))) >> 6)) - 0x200);
                (*(u8 *)((s8*)(var_r29) + (0x34))) = (u8) (*(u8 *)((s8*)(arg1) + (0x15)));
                (*(s8 *)((s8*)(var_r29) + (0x35))) = 0;
                (*(s16 *)((s8*)(var_r29) + (0x2A))) = 0;
                break;
            case 3:
                temp_r4_3 = (u8*)temp_r31 + ((*(u8 *)((s8*)(temp_r31) + (0x806))) * 0x60);
                (*(s16 *)((s8*)(temp_r4_3) + (0xCC))) = (s16) ((s16) ((s16) (*(u8 *)((s8*)(arg1) + (0x10))) * 4) - 0x200);
                var_r29 = (s32) (temp_r4_3 + 0xA0);
                (*(s16 *)((s8*)(temp_r4_3) + (0xD0))) = (s16) ((s16) ((s16) (*(u8 *)((s8*)(arg1) + (0x11))) * 4) - 0x200);
                (*(s16 *)((s8*)(temp_r4_3) + (0xCE))) = (s16) ((s16) ((s16) (*(u8 *)((s8*)(arg1) + (0x12))) * 4) - 0x200);
                (*(s16 *)((s8*)(temp_r4_3) + (0xD2))) = (s16) ((s16) ((s16) (*(u8 *)((s8*)(arg1) + (0x13))) * 4) - 0x200);
                (*(u8 *)((s8*)(temp_r4_3) + (0xD4))) = (u8) (*(u8 *)((s8*)(arg1) + (0x14)));
                (*(u8 *)((s8*)(temp_r4_3) + (0xD5))) = (u8) (*(u8 *)((s8*)(arg1) + (0x15)));
                (*(s16 *)((s8*)(temp_r4_3) + (0xCA))) = 0;
                break;
            }
            if ((s32) (*(u8 *)((s8*)(temp_r31) + (0x851))) == 0) {
                (*(u8 *)((s8*)(temp_r31) + (0x851))) = 1U;
                (*(s16 *)((s8*)(temp_r31) + (0x7C2))) = (s16) (*(s16 *)((s8*)(var_r29) + (0x2C)));
                (*(s16 *)((s8*)(temp_r31) + (0x7C8))) = (s16) (*(s16 *)((s8*)(var_r29) + (0x2E)));
                (*(s16 *)((s8*)(temp_r31) + (0x7CE))) = (s16) (*(s16 *)((s8*)(var_r29) + (0x30)));
                (*(s16 *)((s8*)(temp_r31) + (0x7D4))) = (s16) (*(s16 *)((s8*)(var_r29) + (0x32)));
                (*(u8 *)((s8*)(temp_r31) + (0x7DA))) = (u8) (*(u8 *)((s8*)(var_r29) + (0x34)));
                (*(u8 *)((s8*)(temp_r31) + (0x7DB))) = (u8) (*(u8 *)((s8*)(var_r29) + (0x35)));
            }
            temp_r4_4 = (*(s16 *)((s8*)(var_r29) + (0x2C))) - (*(s16 *)((s8*)(temp_r31) + (0x7C2)));
            temp_r0_9 = (*(s16 *)((s8*)(var_r29) + (0x2E))) - (*(s16 *)((s8*)(temp_r31) + (0x7C8)));
            if (temp_r4_4 < -0x400) {
                (*(s16 *)((s8*)(var_r29) + (0x2C))) = -0x400;
            } else if (temp_r4_4 > 0x3FF) {
                (*(s16 *)((s8*)(var_r29) + (0x2C))) = 0x3FF;
            } else {
                (*(s16 *)((s8*)(var_r29) + (0x2C))) = temp_r4_4;
            }
            if (temp_r0_9 < -0x400) {
                (*(s16 *)((s8*)(var_r29) + (0x2E))) = -0x400;
            } else if (temp_r0_9 > 0x3FF) {
                (*(s16 *)((s8*)(var_r29) + (0x2E))) = 0x3FF;
            } else {
                (*(s16 *)((s8*)(var_r29) + (0x2E))) = temp_r0_9;
            }
            temp_r4_5 = (*(s16 *)((s8*)(var_r29) + (0x30))) - (*(s16 *)((s8*)(temp_r31) + (0x7CE)));
            temp_r0_10 = (*(s16 *)((s8*)(var_r29) + (0x32))) - (*(s16 *)((s8*)(temp_r31) + (0x7D4)));
            if (temp_r4_5 < -0x400) {
                (*(s16 *)((s8*)(var_r29) + (0x30))) = -0x400;
            } else if (temp_r4_5 > 0x3FF) {
                (*(s16 *)((s8*)(var_r29) + (0x30))) = 0x3FF;
            } else {
                (*(s16 *)((s8*)(var_r29) + (0x30))) = temp_r4_5;
            }
            if (temp_r0_10 < -0x400) {
                (*(s16 *)((s8*)(var_r29) + (0x32))) = -0x400;
            } else if (temp_r0_10 > 0x3FF) {
                (*(s16 *)((s8*)(var_r29) + (0x32))) = 0x3FF;
            } else {
                (*(s16 *)((s8*)(var_r29) + (0x32))) = temp_r0_10;
            }
            temp_r4_6 = (*(u8 *)((s8*)(var_r29) + (0x34))) - (*(u8 *)((s8*)(temp_r31) + (0x7DA)));
            temp_r0_11 = (*(u8 *)((s8*)(var_r29) + (0x35))) - (*(u8 *)((s8*)(temp_r31) + (0x7DB)));
            if (temp_r4_6 < 0) {
                (*(u8 *)((s8*)(var_r29) + (0x34))) = 0U;
            } else {
                (*(u8 *)((s8*)(var_r29) + (0x34))) = (u8) temp_r4_6;
            }
            if (temp_r0_11 < 0) {
                (*(u8 *)((s8*)(var_r29) + (0x35))) = 0U;
            } else {
                (*(u8 *)((s8*)(var_r29) + (0x35))) = (u8) temp_r0_11;
            }
        }
        if ((memcmp(&lbl_803928E8, &lbl_803123B8, 6) == 0) && ((s8) (*(u8 *)((s8*)(temp_r30) + (0x29))) == 0)) {
            (*(s8 *)((s8*)(temp_r30) + (0x29))) = -7;
        }
    }
    enabled = OSDisableInterrupts();
    (*(u8 *)((s8*)(temp_r31) + (0x806))) = (u8) ((*(u8 *)((s8*)(temp_r31) + (0x806))) == 0);
    OSRestoreInterrupts(enabled);
}

// Empty placeholder: this WPAD function has no body in the original.
void fn_800678D8(void) {
}

// fn_800678DC: WPAD data processing
__declspec(section ".sdata") extern f64 lbl_80560CE8;
__declspec(section ".sdata") extern f32 lbl_80560CD8;
__declspec(section ".sdata") extern unsigned char lbl_8055DC20[];
__declspec(section ".sdata") extern unsigned char lbl_8055DC24[];

void fn_800678DC(s32 chan, u8 *data) {
    WPADCB *cb = lbl_8038F4F0[(u8)chan];
    u8 *buf = (u8*)cb + ((u8*)cb)[0x806] * 0x60 + 0xA0;
    s32 i;
    s16 v;
    s16 t9;
    u8 nibble;
    BOOL enabled;
    f32 scale = lbl_80560CD8;

    if (lbl_8055DC20[chan] == 0 && lbl_8055DC24[chan] == 0) {
        for (i = 0; i < 0x60; i++) buf[i] = 0;
    }

    *(u16*)buf = ((u16)data[1] | ((u16)data[2] << 8)) & 0x9F1F;

    if (cb->readFormat == 0 || cb->readFormat == 1 || cb->readFormat == 9) {
        buf[0x29] = cb->readStatus;
    } else if (cb->readStatus == 0) {
        *(s8*)(buf + 0x29) = -4;
    }
    buf[0x28] = *(u8*)((u8*)cb + 0x801);
    *(u32*)((u8*)cb + 0x788) = 0;

    {
        s16 a = (s16)(data[3] << 2);
        s16 b = (s16)(((u8)data[1] >> 6) & 2);
        a = a & ~3;
        v = (s16)((s16)(a | b) - *(s16*)((u8*)cb + 0x7B4));
    }
    *(s16*)(buf + 2) = v;

    v = (s16)(((s16)((s16)(data[2] << 3) & ~0xFF)) | ((data[1] << 1) & 0xC0));
    *(s16*)(buf + 6) |= v;

    v = (s16)data[4];
    *(s16*)(buf + 8) = v | (s16)((data[6] << 4) & 0x300);
    v = (s16)data[5];
    *(s16*)(buf + 0xA) = 0x2FF - (s16)(v | (s16)((data[6] << 2) & 0x300));
    *(s16*)(buf + 0x32) = (s16)(((s16)((data[0xB] << 8) & 0xFF00) | data[0xC]) << 6) & 0xFFC0;
    buf[0x34] = data[6] & 0xF;
    {
        u8 b = data[7];
        *(s16*)(buf + 0x2A) = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
    }
    {
        u8 b = data[8];
        *(s16*)(buf + 0x2C) = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
    }
    {
        u8 b = data[9];
        t9 = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x2E) = t9;
    }
    {
        u8 b = data[0xA];
        s16 tA = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x2A) = *(s16*)(buf + 0x2A) * 8;
        *(s16*)(buf + 0x2C) = 0x2FF - (*(s16*)(buf + 0x2C) * 8);
        *(s16*)(buf + 0x2E) = t9 * 8;
        *(s16*)(buf + 0x30) = 0x2FF - ((s16)(tA * 8));
    }
    {
        s8 s = (s8)buf[0x34];
        *(s16*)(buf + 0xC) = (s16)(scale * ((f32)s * (f32)s));
    }
    if (*(u16*)(buf + 0xC) == 0 || *(s16*)(buf + 8) == 0x3FF || *(s16*)(buf + 0xA) == 0x2FF || (s32)buf[0x34] == 0xF) {
        *(s16*)(buf + 8) = 0;
        *(s16*)(buf + 0xA) = 0x2FF;
        *(u16*)(buf + 0xC) = 0;
        *(s16*)(buf + 0x32) = 0;
        *(u8*)(buf + 0x34) = 0;
        buf[0xE] = 0;
    }

    v = (s16)data[0xD];
    *(s16*)(buf + 0x10) = v | (s16)((data[0xF] << 4) & 0x300);
    v = (s16)data[0xE];
    *(s16*)(buf + 0x12) = 0x2FF - (s16)(v | (s16)((data[0xF] << 2) & 0x300));
    *(s16*)(buf + 0x3E) = (s16)(((s16)((data[0x14] << 8) & 0xFF00) | data[0x15]) << 6) & 0xFFC0;
    nibble = data[0xF] & 0xF;
    buf[0x40] = nibble;
    {
        u8 b = data[0x10];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x36) = t;
    }
    {
        u8 b = data[0x11];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x38) = t;
    }
    {
        u8 b = data[0x12];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x3A) = t;
    }
    {
        u8 b = data[0x13];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x36) = *(s16*)(buf + 0x36) * 8;
        *(s16*)(buf + 0x38) = 0x2FF - (*(s16*)(buf + 0x38) * 8);
        *(s16*)(buf + 0x3A) = *(s16*)(buf + 0x3A) * 8;
        *(s16*)(buf + 0x3C) = 0x2FF - ((s16)(t * 8));
    }
    {
        s8 s = (s8)nibble;
        *(s16*)(buf + 0x14) = (s16)(scale * ((f32)s * (f32)s));
    }
    if (*(u16*)(buf + 0x14) == 0 || *(s16*)(buf + 0x10) == 0x3FF || *(s16*)(buf + 0x12) == 0x2FF || (s32)(u8)buf[0x40] == 0xF) {
        *(s16*)(buf + 0x10) = 0;
        *(s16*)(buf + 0x12) = 0x2FF;
        *(u16*)(buf + 0x14) = 0;
        *(s16*)(buf + 0x3E) = 0;
        *(u8*)(buf + 0x40) = 0;
    }

    *(s8*)(buf + 0x16) = 1;
    enabled = OSDisableInterrupts();
    lbl_8055DC20[chan] = 1;
    if (lbl_8055DC20[chan] != 0 && lbl_8055DC24[chan] != 0) {
        *(s16*)(buf + 6) = *(s16*)(buf + 6) - *(s16*)((u8*)cb + 0x7B8);
        ((u8*)cb)[0x806] = (u8)(((u8*)cb)[0x806] == 0);
        lbl_8055DC24[chan] = 0;
        lbl_8055DC20[chan] = 0;
    }
    OSRestoreInterrupts(enabled);
}

// fn_80067ECC: WPAD data processing
void fn_80067ECC(s32 chan, u8 *data) {
    WPADCB *cb = lbl_8038F4F0[(u8)chan];
    u8 *base = (u8*)cb + ((u8*)cb)[0x806] * 0x60;
    u8 *buf = base + 0xA0;
    s32 i;
    s16 v;
    s16 t9;
    u8 nibble;
    BOOL enabled;
    f32 scale;

    if (lbl_8055DC20[chan] == 0 && lbl_8055DC24[chan] == 0) {
        for (i = 0; i < 0x60; i++) buf[i] = 0;
    }

    *(u16*)buf = ((u16)data[1] | ((u16)data[2] << 8)) & 0x9F1F;

    if (cb->readFormat == 0 || cb->readFormat == 1 || cb->readFormat == 9) {
        buf[0x29] = cb->readStatus;
    } else if (cb->readStatus == 0) {
        *(s8*)(buf + 0x29) = -4;
    }
    buf[0x28] = *(u8*)((u8*)cb + 0x801);
    *(u32*)((u8*)cb + 0x788) = 0;

    {
        s16 a = (s16)(data[3] << 2);
        s16 b = (s16)(((u8)data[1] >> 6) & 2);
        a = a & ~3;
        v = (s16)((s16)(a | b) - *(s16*)((u8*)cb + 0x7B6));
    }
    *(s16*)(buf + 4) = v;

    v = (s16)(((data[2] >> 1) & 0x30) | ((data[1] >> 3) & 0xC));
    *(s16*)(buf + 6) |= v;

    v = (s16)data[4];
    *(s16*)(buf + 0x18) = v | (s16)((data[6] << 4) & 0x300);
    v = (s16)data[5];
    *(s16*)(buf + 0x1A) = 0x2FF - (s16)(v | (s16)((data[6] << 2) & 0x300));
    *(s16*)(buf + 0x4A) = (s16)(((s16)((data[0xB] << 8) & 0xFF00) | data[0xC]) << 6) & 0xFFC0;
    buf[0x4C] = data[6] & 0xF;
    {
        u8 b = data[7];
        *(s16*)(buf + 0x42) = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
    }
    {
        u8 b = data[8];
        *(s16*)(buf + 0x44) = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
    }
    {
        u8 b = data[9];
        t9 = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x46) = t9;
    }
    {
        u8 b = data[0xA];
        s16 tA = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x42) = *(s16*)(buf + 0x42) * 8;
        *(s16*)(buf + 0x44) = 0x2FF - (*(s16*)(buf + 0x44) * 8);
        *(s16*)(buf + 0x46) = t9 * 8;
        *(s16*)(buf + 0x48) = 0x2FF - ((s16)(tA * 8));
    }
    {
        s8 s = (s8)buf[0x4C];
        scale = lbl_80560CD8;
        *(s16*)(buf + 0x1C) = (s16)(scale * ((f32)s * (f32)s));
    }
    if (*(u16*)(buf + 0x1C) == 0 || *(s16*)(buf + 0x18) == 0x3FF || *(s16*)(buf + 0x1A) == 0x2FF || (s32)buf[0x4C] == 0xF) {
        *(s16*)(buf + 0x18) = 0;
        *(s16*)(buf + 0x1A) = 0x2FF;
        *(u16*)(buf + 0x1C) = 0;
        *(s16*)(buf + 0x4A) = 0;
        *(u8*)(buf + 0x4C) = 0;
    }
    *(s8*)(buf + 0x1E) = 2;

    v = (s16)data[0xD];
    *(s16*)(buf + 0x20) = v | (s16)((data[0xF] << 4) & 0x300);
    v = (s16)data[0xE];
    *(s16*)(buf + 0x22) = 0x2FF - (s16)(v | (s16)((data[0xF] << 2) & 0x300));
    *(s16*)(buf + 0x56) = (s16)(((s16)((data[0x14] << 8) & 0xFF00) | data[0x15]) << 6) & 0xFFC0;
    nibble = data[0xF] & 0xF;
    *(s8*)(buf + 0x58) = nibble;
    {
        u8 b = data[0x10];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x4E) = t;
    }
    {
        u8 b = data[0x11];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x50) = t;
    }
    {
        u8 b = data[0x12];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x52) = t;
    }
    {
        u8 b = data[0x13];
        s16 t = b & (~((~(((s8)b + 1) | (-1 - (s8)b))) >> 31));
        *(s16*)(buf + 0x4E) = *(s16*)(buf + 0x4E) * 8;
        *(s16*)(buf + 0x50) = 0x2FF - (*(s16*)(buf + 0x50) * 8);
        *(s16*)(buf + 0x52) = *(s16*)(buf + 0x52) * 8;
        *(s16*)(buf + 0x54) = 0x2FF - ((s16)(t * 8));
    }
    {
        s8 s = (s8)nibble;
        *(s16*)(buf + 0x24) = (s16)(scale * ((f32)s * (f32)s));
    }
    if (*(u16*)(buf + 0x24) == 0 || *(s16*)(buf + 0x20) == 0x3FF || *(s16*)(buf + 0x22) == 0x2FF || (s32)(u8)buf[0x58] == 0xF) {
        *(s16*)(buf + 0x20) = 0;
        *(s16*)(buf + 0x22) = 0x2FF;
        *(u16*)(buf + 0x24) = 0;
        *(s16*)(buf + 0x56) = 0;
        *(u8*)(buf + 0x58) = 0;
    }
    *(s8*)(buf + 0x26) = 3;

    enabled = OSDisableInterrupts();
    lbl_8055DC24[chan] = 1;
    if (lbl_8055DC20[chan] != 0 && lbl_8055DC24[chan] != 0) {
        *(s16*)(buf + 6) = *(s16*)(buf + 6) - *(s16*)((u8*)cb + 0x7B8);
        ((u8*)cb)[0x806] = (u8)(((u8*)cb)[0x806] == 0);
        lbl_8055DC24[chan] = 0;
        lbl_8055DC20[chan] = 0;
    }
    OSRestoreInterrupts(enabled);
}

// Empty placeholder: this WPAD function has no body in the original.
void fn_800684CC(void) {
}

void fn_800684D0(s32 chan) {
    const u8 *cb = (const u8 *)lbl_8038F4F0[chan];
    u8 s[10];
    u8 o[8];
    u8 q[8];
    u8 tmp;
    u32 a, b;
    int i, ctr;
    u32 en;
    int off;
    u8 t15, t6v, t12, t11, t10, t11_2, t11_3;
    u8 t18_2, t15_2, t15_3, t14_3, t14_4, t15_4, t18_3, t25_2, t18_4;
    u8 t8_7, t9_2, t6_2, t16, t27, t19, t23, t29, t28, t25, t3_2, t14_2, t15_5, t11_4;
    u8 t9_3, t8_8, t14_5, t27_2, t0, t25_4, t17_2, t16_4, t14_6, t12_2, t26, t18_5, t25_5, t10_2, t25_6, t29_2;
    u32 sh23, sh25;

    lbl_8055DC2B = (u8)(OSGetTick() >> 8);
    lbl_8055DC2A = (u8)((OSGetTick() >> 16) & 0x3F);
    tmp = (u8)((OSGetTick() >> 24) & 0x4C);
    a = (u32)lbl_8055DC2B * (u32)lbl_8055DC2A;
    lbl_8055DC28 = 0xFF;
    lbl_8055DC29 = tmp;
    i = 0;
    b = (tmp + a) % 255;
    off = (int)(u8)((tmp + a) % 255) % 7;
    off = off * 6;
    for (ctr = 0; ctr < 2; ctr++) {
        int base = i;
        i += 5;
        b = (tmp + b * lbl_8055DC2A) % 255;
        s[base + 0] = lbl_803127C8[b];
        b = (tmp + b * lbl_8055DC2A) % 255;
        s[base + 1] = lbl_803127C8[b];
        b = (tmp + b * lbl_8055DC2A) % 255;
        s[base + 2] = lbl_803127C8[b];
        b = (tmp + b * lbl_8055DC2A) % 255;
        s[base + 3] = lbl_803127C8[b];
        b = (tmp + b * lbl_8055DC2A) % 255;
        s[base + 4] = lbl_803127C8[b];
    }
    lbl_8055DC2B = (u8)b;
    en = OSDisableInterrupts();
    t8_7 = lbl_803127C8[s[2]];
    t9_2 = lbl_803127C8[s[0]];
    t15 = (u32)t8_7 >> 31;
    t6v = ((u32)t8_7 << 29) - t15;
    t6_2 = lbl_803127C8[s[5]];
    t12 = ((t6v << 3) | (t6v >> 29)) + t15;
    t11 = (u32)t9_2 >> 31;
    t10 = ((u32)t9_2 << 29) - t11;
    t16 = lbl_80312798[off + 0] ^ t6_2;
    t27 = lbl_803127C8[s[1]];
    t11_2 = ((t10 << 3) | (t10 >> 29)) + t11;
    t19 = lbl_80312798[off + 1] ^ t27;
    t23 = lbl_803127C8[s[9]];
    t11_3 = lbl_803127C8[s[4]];
    t29 = lbl_803127C8[s[7]];
    t28 = s[8];
    t16 = (u8)((t16 >> t12) | (t16 << (8 - t12))) - t23;
    t25 = lbl_803127C8[s[6]];
    t14_2 = (u8)((t19 >> t11_2) | (t19 << (8 - t11_2))) - t6_2;
    t3_2 = lbl_80312798[off + 2] ^ t25;
    t18_2 = (u32)t29 >> 31;
    t15_2 = ((u32)t29 << 29) - t18_2;
    t15_5 = lbl_803127C8[s[8]];
    t15_3 = ((t15_2 << 3) | (t15_2 >> 29)) + t18_2;
    t15_4 = (u8)((t15_3 << 3) | (t15_3 >> 29));
    t14_3 = (u32)t15_5 >> 31;
    t14_4 = (((((u32)t15_5 << 29) - t14_3) << 3) | ((((u32)t15_5 << 29) - t14_3) >> 29)) + t14_3;
    t17_2 = lbl_80312798[off + 3] ^ t11_3;
    t18_3 = (u32)t25 >> 31;
    t25_2 = ((u32)t25 << 29) - t18_3;
    t18_4 = ((t25_2 << 3) | (t25_2 >> 29)) + t18_3;
    t14_5 = lbl_80312798[off + 4] ^ t27;
    t27_2 = lbl_80312798[off + 5] ^ t29;
    t15_5 = lbl_803127C8[s[3]];
    t9_3 = t9_2 ^ ((u8)(((u32)t3_2 >> t14_4) | (t3_2 << (8 - t14_4))) - t8_7);
    t8_8 = t8_7 ^ ((u8)(((u32)t17_2 >> t15_3) | (t17_2 << (8 - t15_3))) - t15_5);
    t9_3 = t11_3 ^ ((u8)(((u32)t14_5 >> t18_4) | (t14_5 << (8 - t18_4))) - t15_5);
    t11_4 = t23 ^ ((u8)(((u32)t27_2 >> t14_4) | (t27_2 << (8 - t14_4))) - t6_2);
    sh23 = (u32)(off + 2) << 8;
    sh25 = (u32)(off + 1) << 8;
    t0 = lbl_803127C8[t9_3 + sh25];
    t25_4 = lbl_803127C8[t28 + sh23];
    t17_2 = lbl_803127C8[s[7] + sh23];
    t16_4 = lbl_803127C8[t11_4 + sh25];
    t14_6 = lbl_803127C8[s[4] + sh23];
    t12_2 = lbl_803127C8[t14_2 + sh25];
    t26 = lbl_803127C8[s[5] + sh23];
    t18_5 = lbl_803127C8[t9_3 + sh25];
    t25_5 = lbl_803127C8[t8_8 + sh25];
    t10_2 = lbl_803127C8[s[9] + sh23];
    t25_6 = lbl_803127C8[t16 + sh25];
    t29_2 = lbl_803127C8[s[6] + sh25];
    o[0] = t0 ^ lbl_803127C8[s[3] + sh23];
    o[1] = t18_5 ^ t26;
    o[2] = t16_4 ^ t17_2;
    o[3] = t25_6 ^ lbl_803127C8[s[8] + sh23];
    o[4] = t12_2 ^ t14_6;
    o[5] = t25_5 ^ t10_2;
    o[6] = lbl_803127C8[s[0] + sh25] ^ t29_2;
    o[7] = lbl_803127C8[s[1] + sh25] ^ t25_4;
    q[0] = t25_6 ^ lbl_803127C8[s[1] + sh23];
    q[1] = t16_4 ^ t14_6;
    q[2] = t25_5 ^ lbl_803127C8[s[0] + sh23];
    q[3] = t18_5 ^ t10_2;
    q[4] = t0 ^ t17_2;
    q[5] = t12_2 ^ t25_4;
    q[6] = lbl_803127C8[s[3] + sh25] ^ t26;
    q[7] = lbl_803127C8[s[0] + sh25] ^ t29_2;
    ((u8 *)cb)[0x854] = s[9];
    ((u8 *)cb)[0x855] = s[8];
    ((u8 *)cb)[0x856] = s[7];
    ((u8 *)cb)[0x857] = s[6];
    ((u8 *)cb)[0x858] = s[5];
    ((u8 *)cb)[0x859] = s[4];
    ((u8 *)cb)[0x85A] = s[3];
    ((u8 *)cb)[0x85B] = s[2];
    ((u8 *)cb)[0x85C] = s[1];
    ((u8 *)cb)[0x85D] = s[0];
    ((u8 *)cb)[0x85E] = t11_4;
    ((u8 *)cb)[0x85F] = t9_3;
    ((u8 *)cb)[0x860] = t8_8;
    ((u8 *)cb)[0x861] = t15_4;
    ((u8 *)cb)[0x862] = t14_2;
    ((u8 *)cb)[0x863] = t16;
    memcpy((u8 *)cb + 0x864, o, 8);
    memcpy((u8 *)cb + 0x86C, q, 8);
    OSRestoreInterrupts(en);
}

void WPADiDecode(s32 chan, u8 *data, WPAD_DECODE_LEN_T len, s32 seed)
{
  WPADCB *cb = lbl_8038F4F0[chan];
  u8 *base = (u8 *) cb;
  u16 i;
  for (i = 0; i < len; i++)
  {
    u8 idx = (seed + i) % 8;
    u8 t1 = base[0x864 + idx], t2 = base[0x86C + idx];
    data[i] = t1 + (t2 ^ data[i]);
  }

}

// WUD function stubs
u8 WUDGetBufferStatus(void) { return 0; }
void fn_8005E298(void);  // WPAD management fiber body (runs on __WPADiManageHandlerStack)
u16 _WUDGetNotAckedSize(s8 handle) {
#pragma unused(handle)
    return 0;
}
u8 _WUDGetLinkNumber(void) { return 0; }
void __a1_22_ack(u8 chan, u8* pReport)
{
    const char* strBase = (const char*)lbl_80312338;
    WPADCB* pCB;
    BOOL intr;
    volatile u8* pBuf;
    u32 offset;
    u8 type;
    u8 ext;
    s32 status;

    intr = OSDisableInterrupts();
    DBPrintf_80068D68(strBase + 0x3E0);
    pCB = lbl_8038F4F0[(u8)chan];
    pBuf = (volatile u8*)pCB->rxBufs[*(u8*)((u8*)pCB + 0x806)];
    for (offset = 0; offset < 96; offset++) {
        pBuf[offset] = 0;
    }
    *(u16*)pBuf = ((u16)pReport[1] | ((u16)pReport[2] << 8)) & 0x9F1F;
    type = pReport[3];
    ext = pReport[4];
    DBPrintf_80068D68(strBase + 0x3F0, type, ext);
    status = (ext == 0) ? 0 : -3;
    ((volatile s8*)pBuf)[0x29] = -2;
    pBuf[0x28] = pCB->UNK_0x801;
    if (ext) {
        DBPrintf_80068D68(strBase + 0x41C, type, ext);
    }
    if (*(u8*)((u8*)pCB + 0x8C7) == type) {
        WPADCallback callback = pCB->readCB;
        if (callback) {
            register u32 z1 = 0;
            register u32 z2 = 0;
            callback(chan, status);
            pCB->readCB = (WPADCallback)z1;
            *(u32*)((u8*)pCB + 0x7FC) = z2;
        }
    } else {
        DBPrintf_80068D68(strBase + 0x44C);
    }
    *((u8*)pCB + 0x806) = !*((u8*)pCB + 0x806);
    OSRestoreInterrupts(intr);
}

/*
 * WPAD SDK "manageAlarm": the callback of the 1 ms management alarm
 * (_managerAlarm) that WPADInit (fn_8005EB44) arms.  Alarms run on the OS
 * alarm thread, so the callback does nothing but jump onto the WPAD
 * management fiber, fn_8005E298, which runs on the 4 KiB block
 * __WPADiManageHandlerStack (top-down, so the fiber starts at its top).  The
 * alarm and its argument are handed to the fiber, which ignores them.
 */
void fn_8005E8C0(OSAlarm* pAlarm, OSContext* pContext)
{
	OSSwitchFiberEx((u32)pAlarm, (u32)pContext, 0, 0, fn_8005E298,
	                __WPADiManageHandlerStack + sizeof(__WPADiManageHandlerStack));
}

/*
 * WPADiResetChannel: bring one channel's control block back to its
 * "just connected" state.  The connection handler (wpadConnectionCallback) calls it for
 * the channel handed to a Wii Remote that has just opened a link: it clears
 * the read/extension state, the status-report fields, the auto sampling
 * buffer and both command queues, marks the channel as not handshaked yet,
 * stamps the two activity timers with the current system time and zeroes the
 * channel's entry in the connection table.
 */
/* Reset one WPAD channel control block to its just-connected state: clear read/extension/status/auto-sampling fields and both command queues, mark the handshake pending, stamp the activity timers, and clear the channel's connection-table entry. */ void WPADiResetChannel_8005E8E0(s32 chan)
{
    WPADCB* pCB = lbl_8038F4F0[chan];
    u8* p = (u8*)pCB;
    BOOL enabled;
    u8 extKind = WPAD_DEV_NOT_FOUND;
    s32 invalid = WUD_DEV_HANDLE_INVALID;
    pCB->rxBufSel = 0;
    pCB->infoNext.dpd = 0;
    pCB->UNK_0x814 = 0;
    pCB->readCB = NULL;
    pCB->readSamplingCB = NULL;
    pCB->copyOutCB = NULL;
    pCB->autoSamplingBuf = NULL;
    pCB->autoSamplingIndex = 0;
    pCB->autoSamplingSize = 0;
    pCB->readFormat = WPAD_FMT_CORE_BTN;
    pCB->readStatus = WPAD_ERR_NO_CONTROLLER;
    pCB->UNK_0x801 = extKind;
    pCB->UNK_0x802 = 0;
    /* 0x838..0x873 has no established WPADCB names yet: 0x838 six halfwords,
     * 0x848 a timestamp, 0x850..0x853 two flags and a "same data" counter,
     * 0x854 the accelerometer calibration and 0x874 the 64-byte buffer a
     * memory read lands in. */
    p[0x851] = 0;
    *(u16*)(p + 0x852) = 0;
    pCB->UNK_0x800 = 0;
    pCB->dpdObjSize = 12;
    *(u16*)(p + 0x838) = 0;
    *(u16*)(p + 0x83A) = 0;
    *(u16*)(p + 0x83C) = 0;
    *(u16*)(p + 0x83E) = 0;
    *(u16*)(p + 0x840) = 0;
    *(u16*)(p + 0x842) = 0;
    pCB->lastRxTime = __OSGetSystemTime();
    *(u64*)(p + 0x848) = __OSGetSystemTime();
    p[0x850] = 0;
    pCB->UNK_0x807 = 0;
    pCB->UNK_0x808 = 0;
    *(u32*)(p + 0x8B4) = 0;
    *(u32*)(p + 0x8B8) = 0;
    *(u16*)(p + 0x8C0) = 0;
    *(u32*)(p + 0x8BC) = 0;
    pCB->extDevHandle = (s8)invalid;
    pCB->connected = 0;
    pCB->handshakeDone = 0;
    pCB->UNK_0x820 = 0;
    pCB->radioLow = 1;
    pCB->radioLowCount = 0;
    pCB->pendingCmdCount = 0;
    p[0x8C2] = 0;
    p[0x8C3] = 0;
    *(u16*)(p + 0x8C4) = 0;
    p[0x8C6] = 1;
    memset(&pCB->info, 0, sizeof(pCB->info));
    memset(p + 0x874, 0, 0x40);
    memset(pCB->rxBufs, 0, sizeof(pCB->rxBufs));
    memset(pCB->rxBufMain, 0, RX_BUFFER_SIZE);
    memset(p + 0x794, 0, 0x2E);
    memset(&pCB->extCalib, 0, 0x1A);
    memset(p + 0x854, 0, 0x10);
    memset(p + 0x864, 0, 8);
    memset(p + 0x86C, 0, 8);
    memset(&pCB->gameInfo, 0, sizeof(WPADGameInfo));
    pCB->UNK_0x38[0] = invalid;
    pCB->UNK_0x38[1] = invalid;
    pCB->stdCmdQueue.buffer = pCB->stdCmdQueueList;
    pCB->stdCmdQueue.capacity = ARRAY_SIZE(pCB->stdCmdQueueList);
    pCB->extCmdQueue.buffer = pCB->extCmdQueueList;
    pCB->extCmdQueue.capacity = 8;
    enabled = OSDisableInterrupts();
    pCB->stdCmdQueue.front = 0;
    pCB->stdCmdQueue.back = 0;
    memset(pCB->stdCmdQueue.buffer, 0,
           pCB->stdCmdQueue.capacity * sizeof(WPADCommand));
    OSRestoreInterrupts(enabled);
    enabled = OSDisableInterrupts();
    pCB->extCmdQueue.front = 0;
    pCB->extCmdQueue.back = 0;
    memset(pCB->extCmdQueue.buffer, 0,
           pCB->extCmdQueue.capacity * sizeof(WPADCommand));
    OSRestoreInterrupts(enabled);
    {
        u32 entryOff = (u32)chan * sizeof(WPADChanEntry);
        u8* entry = lbl_80392900;
        *(u32*)(entry + entryOff) = 0;
        entry += entryOff;
        *(u32*)(entry + 4) = 0;
        *(u16*)(entry + 8) = 0;
        *(u32*)(entry + 12) = 0;
        *(u32*)(entry + 16) = 0;
    }
}

#include <types.h>