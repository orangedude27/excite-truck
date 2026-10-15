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

#include <string.h>

extern void DBPrintf_80068D68(const char* pFmt, ...);
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
extern void* lbl_8055DC14;
extern u8 lbl_8055DC08[WPAD_MAX_CONTROLLERS];
extern u8 lbl_8055DC11;
extern u8 lbl_80392900[];
BOOL fn_80063564(WPADCommandQueue* pQueue, s32 format, WPADCallback pCallback);
extern void (*lbl_80312338[])(u8 port, u8* p_rpt);
void fn_80060AFC(s32 chan);
void WPADiDecode(s32 chan, u8* data, s32 len, s32 seed);

// debug_msg.c is NonMatching, provide stub here
void DEBUGPrint(const char* pFmt, ...) {
#pragma unused(pFmt)
}

#define DPD_CONFIG1_SIZE 9
#define DPD_CONFIG2_SIZE 2
#define SPK_CONFIG_SIZE 7

RVL_LIB_VERSION(WPAD, "May 17 2007", "01:52:03", "0x4199_60831");

WPADCB _wpd[WPAD_MAX_CONTROLLERS];
WPADCB* _wpdcb[WPAD_MAX_CONTROLLERS];

u8 __WPADiManageHandlerStack[0x1000] ALIGN(32);

s8 _dev_handle_index[WUD_MAX_DEV_ENTRY];
OSAlarm _managerAlarm;

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
    WPADCB* p = _wpdcb[chan];
    u32 two = 2; // some define?
    u16 a;

    a = p->radioSensitivity * 9;
    a += (u16)(p->copyOutCount * 100 / two);
    a /= 10;
    a = MIN(100, a);

    p->radioSensitivity = a;
    p->copyOutCount = 0;

    if (p->radioQuality != WPAD_RADIO_QUALITY_GOOD) {
        if (a > 85) {
            p->radioQuality = WPAD_RADIO_QUALITY_GOOD;
            p->radioQualityOkMs = 0;
        } else if (a > 80) {
            p->radioQualityOkMs++;

            if (p->radioQualityOkMs >= 20) {
                p->radioQuality = WPAD_RADIO_QUALITY_GOOD;
                p->radioQualityOkMs = 0;
            }
        }
    } else if (a < 75) {
        p->radioQuality = WPAD_RADIO_QUALITY_BAD;
        p->radioQualityOkMs = 0;
    } else if (a < 80) {
        p->radioQualityOkMs++;

        if (p->radioQualityOkMs >= 1) {
            p->radioQuality = WPAD_RADIO_QUALITY_BAD;
            p->radioQualityOkMs = 0;
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

static BOOL IsControllerDataChanged(WPADCB* p, void* pLhs, void* pRhs) {
    WPADStatus* pLhsCR = (WPADStatus*)pLhs;
    WPADStatus* pRhsCR = (WPADStatus*)pRhs;
    u8 devMode = p->devMode;
    BOOL analogChanged;
    u8 changed;
    int i;

#define CALC_ANALOG_NOISE_ACC(CHANGED)                                         \
    if (CHANGED) {                                                             \
        p->filterDiffAcc++;                                                    \
                                                                               \
        if (p->filterDiffAcc > __WPAD_acc_diff_count_threshold) {              \
            p->filterDiffAcc = 0;                                              \
            p->filterSameAcc = 0;                                              \
            changed |= TRUE;                                                   \
        }                                                                      \
                                                                               \
    } else {                                                                   \
        p->filterSameAcc =                                                     \
            (p->filterSameAcc + 1) % __WPAD_acc_hyst_count_threshold;          \
                                                                               \
        if (p->filterSameAcc == __WPAD_acc_hyst_count_threshold - 1 &&         \
            p->filterDiffAcc > 0) {                                            \
                                                                               \
            p->filterDiffAcc--;                                                \
        }                                                                      \
    }

#define CALC_ANALOG_NOISE_DPD(CHANGED)                                         \
    if (CHANGED) {                                                             \
        p->filterDiffDpd++;                                                    \
                                                                               \
        if (p->filterDiffDpd > __WPAD_dpd_diff_count_threshold) {              \
            p->filterDiffDpd = 0;                                              \
            changed |= TRUE;                                                   \
        }                                                                      \
                                                                               \
    } else {                                                                   \
        p->filterSameDpd =                                                     \
            (p->filterSameDpd + 1) % __WPAD_dpd_hyst_count_threshold;          \
                                                                               \
        if (p->filterSameDpd == __WPAD_dpd_hyst_count_threshold - 1 &&         \
            p->filterDiffDpd > 0) {                                            \
                                                                               \
            p->filterDiffDpd--;                                                \
        }                                                                      \
    }

#define CALC_ANALOG_NOISE_EXT(CHANGED)                                         \
    if (CHANGED) {                                                             \
        p->filterDiffExt++;                                                    \
                                                                               \
        if (p->filterDiffExt > __WPAD_acc_diff_count_threshold) {              \
            p->filterDiffExt = 0;                                              \
            p->filterSameExt = 0;                                              \
            changed |= TRUE;                                                   \
        }                                                                      \
                                                                               \
    } else {                                                                   \
        p->filterSameExt =                                                     \
            (p->filterSameExt + 1) % __WPAD_acc_hyst_count_threshold;          \
                                                                               \
        if (p->filterSameExt == __WPAD_acc_hyst_count_threshold - 1 &&         \
            p->filterDiffExt > 0) {                                            \
                                                                               \
            p->filterDiffExt--;                                                \
        }                                                                      \
    }

    if (p->dataFormat == WPAD_FMT_CORE_BTN ||
        p->dataFormat == WPAD_FMT_CORE_BTN_ACC ||
        p->dataFormat == WPAD_FMT_CORE_BTN_ACC_DPD) {

        changed = IsButtonChanged(pLhsCR->button, pRhsCR->button);

        if (pLhsCR->err == WPAD_ERR_OK && pRhsCR->err == WPAD_ERR_OK) {
            CALC_ANALOG_NOISE_ACC(
                IsAnalogChanged(pLhsCR->accX, pRhsCR->accX, 12) |
                IsAnalogChanged(pLhsCR->accY, pRhsCR->accY, 12) |
                IsAnalogChanged(pLhsCR->accZ, pRhsCR->accZ, 12));

            for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                CALC_ANALOG_NOISE_DPD(
                    IsAnalogChanged(pLhsCR->obj[i].x, pRhsCR->obj[i].x, 2) |
                    IsAnalogChanged(pLhsCR->obj[i].y, pRhsCR->obj[i].y, 2));
            }
        }
    } else if (p->dataFormat == WPAD_FMT_FS_BTN ||
               p->dataFormat == WPAD_FMT_FS_BTN_ACC ||
               p->dataFormat == WPAD_FMT_FS_BTN_ACC_DPD) {

        WPADFSStatus* pLhsFS = (WPADFSStatus*)pLhs;
        WPADFSStatus* pRhsFS = (WPADFSStatus*)pRhs;

        changed = IsButtonChanged(pLhsFS->button, pRhsFS->button);

        if (pLhsFS->err == WPAD_ERR_OK && pRhsFS->err == WPAD_ERR_OK) {
            CALC_ANALOG_NOISE_ACC(
                IsAnalogChanged(pLhsFS->accX, pRhsFS->accX, 12) |
                IsAnalogChanged(pLhsFS->accY, pRhsFS->accY, 12) |
                IsAnalogChanged(pLhsFS->accZ, pRhsFS->accZ, 12));

            for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                CALC_ANALOG_NOISE_DPD(
                    IsAnalogChanged(pLhsFS->obj[i].x, pRhsFS->obj[i].x, 2) |
                    IsAnalogChanged(pLhsFS->obj[i].y, pRhsFS->obj[i].y, 2));
            }

            CALC_ANALOG_NOISE_EXT(
                IsAnalogChanged(pLhsFS->fsAccX, pRhsFS->fsAccX, 12) |
                IsAnalogChanged(pLhsFS->fsAccY, pRhsFS->fsAccY, 12) |
                IsAnalogChanged(pLhsFS->fsAccZ, pRhsFS->fsAccZ, 12));

            changed |= IsAnalogChanged(pLhsFS->fsStickX, pRhsFS->fsStickX, 1);
            changed |= IsAnalogChanged(pLhsFS->fsStickY, pRhsFS->fsStickY, 1);
        }
    } else {
        if (p->dataFormat == WPAD_FMT_CLASSIC_BTN ||
            p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC ||
            p->dataFormat == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {

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

            changed = IsButtonChanged(pLhsCL->button, pRhsCL->button);

            if (pLhsCL->err == WPAD_ERR_OK && pRhsCL->err == WPAD_ERR_OK) {
                CALC_ANALOG_NOISE_ACC(
                    IsAnalogChanged(pLhsCL->accX, pRhsCL->accX, 12) |
                    IsAnalogChanged(pLhsCL->accY, pRhsCL->accY, 12) |
                    IsAnalogChanged(pLhsCL->accZ, pRhsCL->accZ, 12));

                for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                    CALC_ANALOG_NOISE_DPD(
                        IsAnalogChanged(pLhsCL->obj[i].x, pRhsCL->obj[i].x, 2) |
                        IsAnalogChanged(pLhsCL->obj[i].y, pRhsCL->obj[i].y, 2));
                }

                changed |= IsButtonChanged(pLhsCL->clButton, pRhsCL->clButton);

                changed |= IsAnalogChanged(pLhsCL->clLStickX / leftStickDiv,
                                           pRhsCL->clLStickX / leftStickDiv, 1);
                changed |= IsAnalogChanged(pLhsCL->clLStickY / leftStickDiv,
                                           pRhsCL->clLStickY / leftStickDiv, 1);

                changed |=
                    IsAnalogChanged(pLhsCL->clRStickX / rightStickDiv,
                                    pRhsCL->clRStickX / rightStickDiv, 1);
                changed |=
                    IsAnalogChanged(pLhsCL->clRStickY / rightStickDiv,
                                    pRhsCL->clRStickY / rightStickDiv, 1);

                changed |= IsAnalogChanged(pLhsCL->clTriggerL / triggerDiv,
                                           pRhsCL->clTriggerL / triggerDiv, 1);
                changed |= IsAnalogChanged(pLhsCL->clTriggerR / triggerDiv,
                                           pRhsCL->clTriggerR / triggerDiv, 1);
            }

        } else {
            changed = IsButtonChanged(pLhsCR->button, pRhsCR->button);

            if (pLhsCR->err == WPAD_ERR_OK && pRhsCR->err == WPAD_ERR_OK) {
                CALC_ANALOG_NOISE_ACC(
                    IsAnalogChanged(pLhsCR->accX, pRhsCR->accX, 12) |
                    IsAnalogChanged(pLhsCR->accY, pRhsCR->accY, 12) |
                    IsAnalogChanged(pLhsCR->accZ, pRhsCR->accZ, 12));

                for (i = 0; i < WPAD_MAX_DPD_OBJECTS; i++) {
                    CALC_ANALOG_NOISE_DPD(
                        IsAnalogChanged(pLhsCR->obj[i].x, pRhsCR->obj[i].x, 2) |
                        IsAnalogChanged(pLhsCR->obj[i].y, pRhsCR->obj[i].y, 2));
                }
            }
        }
    }

    return changed;

#undef CALC_ANALOG_NOISE_EXT
#undef CALC_ANALOG_NOISE_ACC
#undef CALC_ANALOG_NOISE_DPD
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

// TODO: _wpd should be 32-byte aligned, but doing so breaks this function
static u8 FAKE_ALIGNMENT[0x10];
// WPADiClearQueue is defined in the GX auto-block
DECOMP_FORCEACTIVE(WPAD_c, _dev_handle_index, FAKE_ALIGNMENT);
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

s32 WPADProbe(s32 chan, s32* pDevType) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled;
    s32 status;

    enabled = OSDisableInterrupts();

    if (pDevType != NULL) {
        *pDevType = ((u8*)p)[0x801];
    }

    status = ((s32*)((u8*)p + 0x7FC))[0];

    if (status != WPAD_ERR_NO_CONTROLLER) {
        if (((u8*)p)[0x801] == WPAD_DEV_NOT_FOUND) {
            status = WPAD_ERR_NO_CONTROLLER;
        } else if (!((BOOL*)((u8*)p + 0x81C))[0]) {
            status = WPAD_ERR_COMMUNICATION_ERROR;
        }
    }

    OSRestoreInterrupts(enabled);
    return status;
}

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

s32 WPADSetDataFormat(s32 chan, u32 format) {
    WPADCB* p = lbl_8038F4F0[chan];
    s32 status;
    BOOL enabled;
    BOOL handshake;
    u32 currFormat;

    enabled = OSDisableInterrupts();
    handshake = *(BOOL*)((u8*)p + 0x81C);
    status = *(s32*)((u8*)p + 0x7FC);
    currFormat = *(u32*)((u8*)p + 0x7F8);
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER) {
        goto _end;
    }
    if (!handshake) {
        status = WPAD_ERR_COMMUNICATION_ERROR;
        goto _end;
    }
    if (currFormat != format) {
        if (!fn_80063564(&p->stdCmdQueue, format, NULL)) {
            status = WPAD_ERR_COMMUNICATION_ERROR;
        } else {
            enabled = OSDisableInterrupts();
            *(u32*)((u8*)p + 0x7F8) = format;
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

void WPADiExcludeButton(s32 chan) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();

    u8 rxBufIndex = *(u8*)((u8*)p + 0x806) != 0 ? 0 : 1;
    void* pRxBuffer = p->rxBufs[rxBufIndex];

    WPADStatus* pStatus;
    WPADCLStatus* pStatusCL;

    pStatus = (WPADStatus*)pRxBuffer;

    if ((pStatus->button & (WPAD_BUTTON_LEFT | WPAD_BUTTON_RIGHT)) ==
        (WPAD_BUTTON_LEFT | WPAD_BUTTON_RIGHT)) {
        pStatus->button &= ~WPAD_BUTTON_RIGHT;
    }

    if ((pStatus->button & (WPAD_BUTTON_UP | WPAD_BUTTON_DOWN)) ==
        (WPAD_BUTTON_UP | WPAD_BUTTON_DOWN)) {
        pStatus->button &= ~WPAD_BUTTON_DOWN;
    }

    if (*(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CLASSIC_BTN ||
        *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CLASSIC_BTN_ACC ||
        *(u32*)((u8*)p + 0x7F8) == WPAD_FMT_CLASSIC_BTN_ACC_DPD) {
        pStatusCL = (WPADCLStatus*)pRxBuffer;

        if ((pStatusCL->clButton &
             (WPAD_BUTTON_CL_LEFT | WPAD_BUTTON_CL_RIGHT)) ==
            (WPAD_BUTTON_CL_LEFT | WPAD_BUTTON_CL_RIGHT)) {
            pStatusCL->clButton &= ~WPAD_BUTTON_CL_RIGHT;
        }

        if ((pStatusCL->clButton & (WPAD_BUTTON_CL_UP | WPAD_BUTTON_CL_DOWN)) ==
            (WPAD_BUTTON_CL_UP | WPAD_BUTTON_CL_DOWN)) {
            pStatusCL->clButton &= ~WPAD_BUTTON_CL_DOWN;
        }
    }

    OSRestoreInterrupts(enabled);
}

void fn_80060AFC(s32 chan) {
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

static BOOL IsBusyStream(s32 chan) {
    BOOL enabled;
    WPADCB* p = lbl_8038F4F0[chan];
    u8 radioQuality;
    u32 devType;
    u8 bufferStatus;
    u16 bteBufferStatus;
    u16 btmBufferStatus;
    u8 audioFrames;
    s8 queueSize;
    u8 linkNumber;

    enabled = OSDisableInterrupts();
    radioQuality = ((u8*)p)[0x80C];
    devType = p->UNK_0x801;
    bufferStatus = WUDGetBufferStatus();
    {
        BOOL enabled = OSDisableInterrupts();
        queueSize = p->stdCmdQueue.back - p->stdCmdQueue.front;
        if (queueSize < 0) {
            queueSize += p->stdCmdQueue.capacity;
        }
        OSRestoreInterrupts(enabled);
    }
    {
        WPADCB* p = lbl_8038F4F0[chan];
        BOOL enabled;
        s32 status;
        s8 handle;
        enabled = OSDisableInterrupts();
        status = *(s32*)((u8*)p + 0x7FC);
        handle = *(s8*)((u8*)p + 0x803);
        OSRestoreInterrupts(enabled);
        if (status == WPAD_ERR_NO_CONTROLLER) {
            bteBufferStatus = 0;
        } else {
            bteBufferStatus = _WUDGetQueuedSize(handle);
        }
    }
    {
        WPADCB* p = lbl_8038F4F0[chan];
        BOOL enabled;
        s32 status;
        s8 handle;
        enabled = OSDisableInterrupts();
        status = *(s32*)((u8*)p + 0x7FC);
        handle = *(s8*)((u8*)p + 0x803);
        OSRestoreInterrupts(enabled);
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

BOOL WPADCanSendStreamData(s32 chan) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled;
    BOOL handshake;
    s32 status;

    enabled = OSDisableInterrupts();
    status = *(s32*)((u8*)p + 0x7FC);
    handshake = *(BOOL*)((u8*)p + 0x81C);
    OSRestoreInterrupts(enabled);

    if (status == WPAD_ERR_NO_CONTROLLER || !handshake || IsBusyStream(chan)) {
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
extern void* lbl_8055DC14;
extern u8 lbl_80393058[0x468];
extern OSAlarm lbl_8038F4C0;
extern u8 lbl_8055DC19;
extern u8 lbl_8055DC12;

// fn_8005EE78: tail call wrapper
void fn_8005EE78(void) { fn_8006A7D0(); }

// fn_8005EE7C: tail call wrapper
void fn_8005EE7C(void) { fn_8006A940(); }

// fn_80062458: reads a global flag
u8 fn_80062458(void) {
    return lbl_8055DC19;
}

// fn_8005D0DC: WUD initialization helper
s32 fn_8005D0DC(s32 chan, s32 mode) {
    s32 result = fn_8006A940();
    s32 var_r30 = 0;
    u8 *ptr;
    s32 i;
    
    if (chan != 0) {
        return 0;
    }
    
    if (result < 2 || result > 3) {
        return 0;
    }
    
    if (mode == 1) {
        return 0;
    }
    
    if (mode > 1) {
        if (mode >= 4 && mode < 7) {
            if (lbl_8055DC05 == 0) {
                lbl_8055DC05 = 1;
                WUDSetVisibility(0, 0);
            }
            for (i = mode, ptr = lbl_80393058 + 0x2bd; i < 14; i++, ptr += 0x46) {
                memset(ptr, 0, 0x46);
            }
            goto skip_init;
        }
    }
    
    if (mode == 0) {
        if (lbl_8055DC05 == 0) {
            lbl_8055DC05 = 1;
            fn_80073EA4();
        }
    }

skip_init:
    OSCancelAlarm(&lbl_8038F4C0);
    fn_8006ADC4(NULL);
    fn_8006A81C();
    
    if (mode >= 4 && mode < 7) {
        return 0;
    }
    
    if (result == 0) {
        return 1;
    }
    
    return 0;
}

s32 fn_8005D234(s32 chan, WPADGameInfo* pInfo)
{
    WPADCB** table = lbl_8038F4F0;
    WPADCB* pCB;
    s32 offset;
    s32 status;
    s8 devHandle;
    BOOL enabled;
    s32 chanSave;
    WPADGameInfo* pInfoSave;
    s32 result;
    s64 currentTime;
    s32 elapsed;
    s32 status2;
    
    offset = chan * 4;
    pCB = table[chan];
    chanSave = chan;
    pInfoSave = pInfo;
    
    enabled = OSDisableInterrupts();
    status = ((s32*)pCB)[0x7FC / 4];
    OSRestoreInterrupts(enabled);
    
    if (status == 0) {
        enabled = OSDisableInterrupts();
        devHandle = ((s8*)pCB)[0x800];
        OSRestoreInterrupts(enabled);
        
        if (devHandle == 0) {
            u32 locals[12];
            s32 i;
            for (i = 0; i < 12; i++) {
                ((u32*)locals)[i] = ((u32*)pInfoSave)[i];
            }
            fn_80063324(chanSave, locals);
            return 0;
        }
        return -2;
    }
    
    if (status == -2) {
        currentTime = __OSGetSystemTime();
        elapsed = __div2i((s32)(currentTime >> 2), (s32)(pCB->lastControllerDataUpdate >> 2),
                         (s32)currentTime, (s32)pCB->lastControllerDataUpdate);
        
        if (elapsed > 1 && lbl_8055DC11 != 0) {
            if (pCB->wpInfoOut == NULL) {
                currentTime = __OSGetSystemTime();
                pCB->lastControllerDataUpdate = currentTime;
                pCB->samplingBufIndex = elapsed;
                
                enabled = OSDisableInterrupts();
                status2 = ((s32*)pCB)[0x7FC / 4];
                OSRestoreInterrupts(enabled);
                
                if (status2 == -1) {
                    enabled = OSDisableInterrupts();
                    devHandle = pCB->rxBufIndex;
                    if (devHandle == 0) {
                        pCB->rxBufIndex = 1;
                        OSRestoreInterrupts(enabled);
                        BTA_HhClose(pCB->devHandle);
                    } else {
                        OSRestoreInterrupts(enabled);
                    }
                }
            } else {
                enabled = OSDisableInterrupts();
                ((s32*)pCB)[0x7FC / 4] = -3;
                OSRestoreInterrupts(enabled);
            }
        }
        return -2;
    }
    
    if (status == -3) {
        enabled = OSDisableInterrupts();
        ((s32*)pCB)[0x7FC / 4] = 0;
        OSRestoreInterrupts(enabled);
        return -3;
    }
    
    return status;
}

// fn_8005EB44: WPAD initialization
void fn_8005EB44(void) {
    BOOL enabled = OSDisableInterrupts();
    if (lbl_8055DC05 == 0) {
        lbl_8055DC05 = 1;
        WUDSetVisibility(0, 0);
        memset(lbl_80393058 + 0x2bd, 0, 0x46 * 4);
        OSCancelAlarm(&lbl_8038F4C0);
        fn_8006ADC4(NULL);
        fn_8006A81C();
    }
    OSRestoreInterrupts(enabled);
}

// fn_8005ED8C: WPAD reset
void fn_8005ED8C(void) {
    if (lbl_8055DC05 == 0) {
        void* ptr;
        s32 i;

        lbl_8055DC05 = 1;
        WUDSetVisibility(0, 0);
        
        for (i = 10, ptr = lbl_80393058 + 0x2bd; i < 14; i++, ptr = (void*)((u8*)ptr + 0x46)) {
            memset(ptr, 0, 0x46);
        }
        
        OSCancelAlarm(&lbl_8038F4C0);
        fn_8006ADC4(NULL);
        fn_8006A81C();
    }
}

// fn_8005EE20: WPAD query
void fn_8005EE20(void) {
    if (lbl_8055DC05 == 0) {
        lbl_8055DC05 = 1;
        fn_80073EA4();
        OSCancelAlarm(&lbl_8038F4C0);
        fn_8006ADC4(0);
        fn_8006A81C();
    }
}

// fn_8005EE6C: tail call to WUDStartFastSyncSimple
void fn_8005EE6C(void) { WUDStartFastSyncSimple(); }

// fn_8005EE70: tail call to fn_8006AC4C
void fn_8005EE70(void) { fn_8006AC4C(); }

// fn_8005EE74: tail call to WUDSetSyncSimpleCallback
void fn_8005EE74(void) { WUDSetSyncSimpleCallback(NULL); }

// fn_8005EE80: get extFormat
u8 fn_8005EE80(s32 chan) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();
    u8 val = p->devHandle;
    OSRestoreInterrupts(enabled);
    return val;
}

void fn_8005EEC4(s32 chan, s32 result) {
    WPADCB* p = lbl_8038F4F0[chan];
    u8* raw = (u8*)p;
    BOOL enabled;
    s32 index;
    s32 capacity;
    s32 next;
    u8 command[0x30];
    if (result == -1) return;
    if (result == 0) {
        *(u32*)(raw + 0x81C) = 1;
        if (*(void (**)(void))(raw + 0x7E4) != NULL) (*(void (**)(void))(raw + 0x7E4))();
        return;
    }
    memset(command, 0, sizeof(command));
    *(u16*)command = (*(u32*)(raw + 0x820) != 0) ? 0x14 : 0x2A;
    *(u32*)(command + 4) = (*(u32*)(raw + 0x820) != 0) ? 0x176C : 0;
    *(u32*)(command + 8) = 0x17;
    *(u16*)(command + 0x22) = 6;
    *(void (**)(void))(command + 0x2C) = (void (*)())fn_8005EEC4;
    *(void**)(command + 0x24) = raw + 0x874;
    enabled = OSDisableInterrupts();
    OSDisableInterrupts();
    index = (s8)(*(u8*)(raw + 0x161) - *(u8*)(raw + 0x160));
    if (index < 0) index = (s8)(index + *(s32*)(raw + 0x168));
    OSRestoreInterrupts(enabled);
    capacity = *(s32*)(raw + 0x168);
    if ((u32)(capacity - 1) == (u32)index) {
        OSRestoreInterrupts(enabled);
        return;
    }
    next = (s8)*(u8*)(raw + 0x161);
    memset((void*)(*(u8**)(raw + 0x164) + next * 0x30), 0, 0x30);
    memcpy((void*)(*(u8**)(raw + 0x164) + next * 0x30), command, 0x30);
    next = (s8)*(u8*)(raw + 0x161);
    capacity = *(s32*)(raw + 0x168) - 1;
    next = next + 1;
    if (next > capacity) next = 0;
    *(u8*)(raw + 0x161) = next;
    OSRestoreInterrupts(enabled);
}

void fn_8005F248(s32 chan, s32 param_2) {
    WPADCB* cb = lbl_8038F4F0[chan];
    register s32 enabled asm("r30");
    register s32 status asm("r29");
    register WPADCB* p asm("r31") = cb;
    s8 front, back;
    u32 capacity;
    s32 diff;
    u8 buf[0x60];
    f64 d4, d3, d2, d1, d0, d5;
    
    if (param_2 != -3) {
        return;
    }
    
    *(u32*)(buf + 0x0C) = 0x62;
    *(u16*)(buf + 0x08) = 0x38;
    *(u32*)(buf + 0x10) = 0x17;
    *(u16*)(buf + 0x2A) = 0x6;
    *(void**)(buf + 0x3C) = fn_8005F248;
    
    memcpy(buf + 0x14, buf + 0x0C, 4);
    memcpy(buf + 0x18, buf + 0x08, 2);
    
    *(u16*)(buf + 0x30) = *(u16*)(buf + 0x08);
    *(u32*)(buf + 0x34) = *(u32*)(buf + 0x0C);
    *(u32*)(buf + 0x2C) = (u32)(p + 0x874);
    
    d4 = *(f64*)(buf + 0x10);
    d3 = *(f64*)(buf + 0x18);
    d2 = *(f64*)(buf + 0x20);
    d1 = *(f64*)(buf + 0x28);
    d5 = *(f64*)(buf + 0x38);
    d0 = *(f64*)(buf + 0x30);
    
    *(f64*)(buf + 0x00) = d4;
    *(f64*)(buf + 0x08) = d3;
    *(f64*)(buf + 0x10) = d2;
    *(f64*)(buf + 0x18) = d1;
    *(f64*)(buf + 0x20) = d0;
    *(f64*)(buf + 0x28) = d5;
    
    enabled = OSDisableInterrupts();
    OSDisableInterrupts();
    
    back = p->stdCmdQueue.back;
    front = p->stdCmdQueue.front;
    diff = front - back;
    
    if (diff >= 0) {
        OSRestoreInterrupts(enabled);
        return;
    }
    
    capacity = p->stdCmdQueue.capacity;
    diff = capacity + diff;
    status = diff;
    OSRestoreInterrupts(enabled);
    
    if (capacity - 1 != status) {
        OSRestoreInterrupts(enabled);
        return;
    }
    
    memset(p->stdCmdQueue.buffer + front * 0x30, 0, 0x30);
    memcpy(p->stdCmdQueue.buffer + front * 0x30, buf, 0x30);
    
    ((u8*)p)[0x161] = (u8)((u8)((s32)(capacity - 1 - status) >> 31) & ((u8)((s32)(status - capacity + 1 - 1) >> 31) ^ 0xFF));
    
    OSRestoreInterrupts(enabled);
}

s32 fn_8005FBCC(u8 devHandle) {
    BD_ADDR_PTR pAddr;
    int i;

    pAddr = _WUDGetDevAddr(devHandle);

    for (i = 0; i < WPAD_MAX_CONTROLLERS; i++) {
        if (memcmp(lbl_80393058 + i * 0x46 + 0x2BD, pAddr, 6) != 0) {
            continue;
        }
        if (lbl_8055DC08[i]) {
            continue;
        }
        lbl_8055DC08[i] = TRUE;
        return i;
    }

    for (i = 0; i < WPAD_MAX_CONTROLLERS; i++) {
        if (lbl_8055DC08[i]) {
            continue;
        }
        lbl_8055DC08[i] = TRUE;
        memcpy(lbl_80393058 + (i + 10) * 0x46 + 1, pAddr, 6);
        lbl_8055DC11 = TRUE;
        return i;
    }

    return WPAD_CHAN_INVALID;
}

void fn_8005FCCC(u8 devHandle, u8 open) {
    extern void fn_8005E8E0(s32 chan);
    extern const char lbl_803120E0[];
    extern s8 lbl_80390500[];
    extern void fn_8005F3E8(s32, s32);
    extern s32 fn_8005B00C(void);
    s32 chan;
    WPADCB* p;
    const char* messages = lbl_803120E0;
    WPADCommand command;
    WPADCommand queuedCommand ALIGN(8);
    WPADCommand readCommand ALIGN(8);
    BOOL remain;

    if (open) {
        DBPrintf_80068D68(messages + 0xCC);
        chan = fn_8005FBCC(devHandle);
        p = lbl_8038F4F0[chan];
        lbl_80390500[devHandle] = chan;
        fn_8005E8E0(chan);
        ((u8*)p)[0x803] = devHandle;
        ((u8*)p)[0x801] = 0;
        *(u32*)((u8*)p + 0x7F8) = 0;
        *(u32*)((u8*)p + 0x818) = TRUE;
        *(s32*)((u8*)p + 0x7FC) = 0;
        ((u8*)p)[0x8C3] = 100;
        ((u8*)p)[0x8C6] = FALSE;
        {
            u32 addr = 0x1770;
            u16 len = 1;
            BOOL enabled;
            readCommand.reportID = 0x17;
            readCommand.dataLength = 6;
            readCommand.cmdCB = fn_8005F3E8;
            memcpy(readCommand.dataBuf, &addr, 4);
            memcpy(readCommand.dataBuf + 4, &len, 2);
            readCommand.dstBuf = (u8*)p + 0x874;
            readCommand.readLength = len;
            readCommand.readAddress = addr;
            memcpy(&queuedCommand, &readCommand, sizeof(WPADCommand));
            enabled = OSDisableInterrupts();
            {
            s8 count;
            BOOL inner = OSDisableInterrupts();
            count = p->stdCmdQueue.back - p->stdCmdQueue.front;
            if (count < 0) count += p->stdCmdQueue.capacity;
            OSRestoreInterrupts(inner);
            if (p->stdCmdQueue.capacity - 1 == count) {
                OSRestoreInterrupts(enabled);
            } else {
                memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], 0, sizeof(WPADCommand));
                memcpy(&p->stdCmdQueue.buffer[p->stdCmdQueue.back], &queuedCommand, sizeof(WPADCommand));
                p->stdCmdQueue.back = p->stdCmdQueue.back == p->stdCmdQueue.capacity - 1 ? 0 : p->stdCmdQueue.back + 1;
                OSRestoreInterrupts(enabled);
            }
            }
        }
        fn_8005B00C();
    } else {
        DBPrintf_80068D68(messages + 0xE4);
        chan = lbl_80390500[devHandle];
        lbl_80390500[devHandle] = -1;
        if (chan != -1) {
            p = lbl_8038F4F0[chan];
            *(s32*)((u8*)p + 0x7FC) = -1;
            if (*(WPADCallback*)((u8*)p + 0x7DC) != NULL) {
                (*(WPADCallback*)((u8*)p + 0x7DC))(chan, -1);
            } else if (*(WPADCallback*)(lbl_80392900 + chan * 0x14 + 0x10) != NULL) {
                (*(WPADCallback*)(lbl_80392900 + chan * 0x14 + 0x10))(chan, -1);
            }
            do {
                {
                    BOOL enabled = OSDisableInterrupts();
                    s8 count;
                    BOOL inner = OSDisableInterrupts();
                    count = p->stdCmdQueue.back - p->stdCmdQueue.front;
                    if (count < 0) count += p->stdCmdQueue.capacity;
                    OSRestoreInterrupts(inner);
                    if (count == 0) {
                        OSRestoreInterrupts(enabled);
                        remain = FALSE;
                    } else {
                        memcpy(&command, &p->stdCmdQueue.buffer[p->stdCmdQueue.front], sizeof(WPADCommand));
                        OSRestoreInterrupts(enabled);
                        remain = TRUE;
                    }
                }
                if (remain) {
                    if (command.cmdCB != NULL) {
                        command.cmdCB(chan, -1);
                    }
                    {
                        BOOL enabled = OSDisableInterrupts();
                        s8 count;
                    BOOL inner = OSDisableInterrupts();
                    count = p->stdCmdQueue.back - p->stdCmdQueue.front;
                    if (count < 0) count += p->stdCmdQueue.capacity;
                    OSRestoreInterrupts(inner);
                    if (count == 0) {
                            OSRestoreInterrupts(enabled);
                        } else {
                            memset(&p->stdCmdQueue.buffer[p->stdCmdQueue.front], 0, sizeof(WPADCommand));
                            p->stdCmdQueue.front = p->stdCmdQueue.front == p->stdCmdQueue.capacity - 1 ? 0 : p->stdCmdQueue.front + 1;
                            OSRestoreInterrupts(enabled);
                        }
                    }
                }
            } while (remain);
            DBPrintf_80068D68(messages + 0x100);
            if (*(void**)((u8*)p + 0x7EC) != NULL) {
                WPADSetAutoSamplingBuf(chan, *(void**)((u8*)p + 0x7EC), *(u32*)((u8*)p + 0x7F4));
            }
            fn_8005E8E0(chan);
            lbl_8055DC08[chan] = FALSE;
            if (*(WPADCallback*)((u8*)p + 0x7E4) != NULL) {
                (*(WPADCallback*)((u8*)p + 0x7E4))(chan, -1);
            }
        } else {
            DBPrintf_80068D68(messages + 0x118);
        }
    }
}

// fn_8006022C: disconnect controller and clear saved device information
void fn_8006022C(s32 chan)
{
    s32 status;
    WPADCB* p;
    BOOL enabled;

    memset(lbl_80393058 + (chan + 10) * 0x46 + 1, 0, 0x46);
    lbl_8055DC11 = TRUE;
    p = lbl_8038F4F0[chan];
    enabled = OSDisableInterrupts();
    status = *(s32*)((u8*)p + 0x7FC);
    OSRestoreInterrupts(enabled);
    if (status == WPAD_ERR_NO_CONTROLLER) {
        return;
    }
    enabled = OSDisableInterrupts();
    if (((u8*)p)[0x8C6]) {
        OSRestoreInterrupts(enabled);
        return;
    }
    ((u8*)p)[0x8C6] = TRUE;
    OSRestoreInterrupts(enabled);
    BTA_HhClose(((u8*)p)[0x803]);
}

// fn_800604E8: set data format
void fn_800604E8(s32 chan, s32 format) {
    BOOL enabled = OSDisableInterrupts();
    (*(u32*)((u8*)_wpdcb[chan] + 0x8B8)) = format;
    OSRestoreInterrupts(enabled);
}

// fn_80060750: setter for lbl_8055DC14
void fn_80060750(void* param) {
    BOOL enabled = OSDisableInterrupts();
    lbl_8055DC14 = param;
    OSRestoreInterrupts(enabled);
}

// fn_80060784: getter for lbl_8055DC14
void* fn_80060784(void) {
    BOOL enabled = OSDisableInterrupts();
    void* val = lbl_8055DC14;
    OSRestoreInterrupts(enabled);
    return val;
}

// fn_800609E0: get data format (clamped)
u32 fn_800609E0(s32 chan) {
    BOOL enabled = OSDisableInterrupts();
    u32 val = *(u32*)((u8*)lbl_8038F4F0[chan] + 0x7F0);
    OSRestoreInterrupts(enabled);
    return (val == (u32)-1) ? 0 : val;
}

// fn_80060C7C: get connected flag
u32 fn_80060C7C(s32 chan) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();
    u32 val = *(u32*)((u8*)p + 0x77C);
    OSRestoreInterrupts(enabled);
    return val;
}

// fn_80060CC0: WPAD processing (large - stub)
void fn_80060CC0(void) { /* stub */ }

// fn_80062054: get data format
u32 fn_80062054(s32 chan) {
#pragma unused(chan)
    BOOL enabled = OSDisableInterrupts();
    u32 val = lbl_8055DC12;
    OSRestoreInterrupts(enabled);
    return val;
}

// fn_80062088: set data format
void fn_80062088(s32 val) {
    BOOL enabled = OSDisableInterrupts();
    lbl_8055DC12 = val;
    OSRestoreInterrupts(enabled);
}

// fn_80062278: check controller
s32 fn_80062278(s32 chan, void* pData, u16 len) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled;
    BOOL handshake;
    s32 status;
    WPADCommand command;
    s8 diff;
    s32 index;

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

    command.reportID = RPTID_SEND_SPEAKER_DATA;
    command.dataLength = sizeof(command.dataBuf);
    command.dataBuf[0] = len << 3;
    command.cmdCB = NULL;
    memcpy(&command.dataBuf[1], pData, len);

    enabled = OSDisableInterrupts();
    diff = p->stdCmdQueue.front - p->stdCmdQueue.back;
    if (diff < 0) {
        diff += p->stdCmdQueue.capacity;
    }
    OSRestoreInterrupts(enabled);

    if (p->stdCmdQueue.capacity - 1 == diff) {
        return WPAD_ERR_COMMUNICATION_ERROR;
    }

    index = p->stdCmdQueue.back;
    memset(&p->stdCmdQueue.buffer[index], 0, sizeof(WPADCommand));
    memcpy(&p->stdCmdQueue.buffer[index], &command, sizeof(WPADCommand));
    p->stdCmdQueue.back = p->stdCmdQueue.back == p->stdCmdQueue.capacity - 1 ? 0 : p->stdCmdQueue.back + 1;
    OSRestoreInterrupts(enabled);

    enabled = OSDisableInterrupts();
    p->audioFrames++;
    OSRestoreInterrupts(enabled);
    return WPAD_ERR_OK;
}

// fn_80062460: get controller status
u32 fn_80062460(s32 chan) {
    WPADCB* p = lbl_8038F4F0[chan];
    BOOL enabled = OSDisableInterrupts();
    u32 val = *(u32*)((u8*)p + 0x778);
    OSRestoreInterrupts(enabled);
    return val;
}

// fn_800624A4: WPAD callback handler (large - stub)
void fn_800624A4(void) { /* stub */ }

// fn_80063564: WPADSetReportType - queues a SetDataReportMode command.
// Functionally identical to WPADiSendSetReportType (line above) but placed at
// a separate anonymous address by the original REXE01 build. The reference asm
// (auto_03_8005D0DC_text.s, 0x80063564) expands the WPADCommand copy as inline
// lfd/stfd pairs and inlines the queue-full check; MWCC emits memcpy/memset
// library calls for this source shape. The 12-instruction delta (mine 132 vs
// ref 120) is a source-shape gap from memcpy/queue-check inlining, not a
// semantic difference. Marked FUZZY: same control flow, same behaviour, same
// register choices for the queue advance.
BOOL fn_80063564(WPADCommandQueue* pQueue, s32 format, WPADCallback pCallback) {
    WPADCommand command;
    BOOL enabled;
    s8 remain;
    s8 front;
    u32 capacity;

    command.reportID = RPTID_SET_DATA_REPORT_MODE;
    command.dataLength = RPT12_SIZE;
    command.dataBuf[RPT12_CONT_REPORT] = 4;
    command.cmdCB = pCallback;
    switch (format) {
    case WPAD_FMT_CORE_BTN: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN; break;
    case WPAD_FMT_CORE_BTN_ACC: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC; break;
    case WPAD_FMT_CORE_BTN_ACC_DPD: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD12; break;
    case WPAD_FMT_FS_BTN: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_EXT8; break;
    case WPAD_FMT_FS_BTN_ACC: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_EXT16; break;
    case WPAD_FMT_FS_BTN_ACC_DPD: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD10_EXT9; break;
    case WPAD_FMT_CLASSIC_BTN: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_EXT8; break;
    case WPAD_FMT_CLASSIC_BTN_ACC: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_EXT16; break;
    case WPAD_FMT_CLASSIC_BTN_ACC_DPD: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD10_EXT9; break;
    case WPAD_FMT_BTN_ACC_DPD_EXTENDED: command.dataBuf[RPT12_DATA_REPORT_MODE] = RPTID_DATA_BTN_ACC_DPD18_1; break;
    }
    enabled = OSDisableInterrupts();
    OSDisableInterrupts();
    remain = pQueue->front - pQueue->back;
    if (remain < 0) remain += pQueue->capacity;
    OSRestoreInterrupts(enabled);
    if (pQueue->capacity - 1 == remain) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    memset(&pQueue->buffer[pQueue->back], 0, sizeof(WPADCommand));
    memcpy(&pQueue->buffer[pQueue->back], &command, sizeof(WPADCommand));
    front = pQueue->back;
    capacity = pQueue->capacity;
    pQueue->back = front == capacity - 1 ? 0 : front + 1;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

static BOOL fn_80063744(u8* p, u8 idx, u32 val1, u32 val2) {
    u8 buf[0x40] ALIGN(8);
    s8 diff;
    BOOL enabled;
    u8 newIdx;
    u32 count;
    s8 delta;
    s8 delta2;
    u32 mask;
    
    buf[0] = 0;
    buf[1] = idx;
    buf[2] = 1;
    
    enabled = OSDisableInterrupts();
    enabled = OSDisableInterrupts();
    
    diff = p[1] - p[0];
    if (diff < 0) {
        diff += (s8)((s32)*(u32*)(p + 8));
    }
    
    OSRestoreInterrupts(enabled);
    
    if (*(u32*)(p + 8) - 1 != (u32)diff) {
        memset(p + 4 + p[1] * 0x30, 0, 0x30);
        memcpy(p + 4 + p[1] * 0x30, buf, 0x30);
        
        newIdx = p[1] + 1;
        count = *(u32*)(p + 8);
        delta = newIdx - count;
        delta2 = count - 1 - p[1];
        mask = ((s32)delta >> 31) | ((s32)delta2 >> 31);
        p[1] = newIdx & ~mask;
        
        OSRestoreInterrupts(enabled);
        return TRUE;
    }
    
    OSRestoreInterrupts(enabled);
    return FALSE;
}

static BOOL fn_800638C8(u8* p, const void* src, u32 len, u32 val1, u32 val2) {
    u8 buf[0x40] ALIGN(8);
    s8 diff;
    BOOL enabled;
    u8 newIdx;
    u32 count;
    s8 delta;
    s8 delta2;
    u32 mask;
    u32 lenMask;
    
    // Initialize buffer based on assembly
    // sp+8 = val1 (r6)
    // sp+c = len & 0x1F (r9)
    // sp+40 = 0x16
    // sp+5a = 0x15
    // sp+6c = val2 (r7)
    
    // memcpy(sp+44, sp+c, 4) -> copies val1 to sp+44
    // memcpy(sp+48, sp+c, 1) -> copies len&0x1F to sp+48
    // memcpy(sp+49, src, len) -> copies src to sp+49
    
    lenMask = len & 0x1F;
    *(u32*)&buf[0x44] = val1;
    buf[0x48] = lenMask;
    memcpy(&buf[0x49], src, len);
    
    enabled = OSDisableInterrupts();
    enabled = OSDisableInterrupts();
    
    diff = p[1] - p[0];
    if (diff < 0) {
        diff += (s8)((s32)*(u32*)(p + 8));
    }
    
    OSRestoreInterrupts(enabled);
    
    if (*(u32*)(p + 8) - 1 != (u32)diff) {
        memset(p + 4 + p[1] * 0x30, 0, 0x30);
        memcpy(p + 4 + p[1] * 0x30, buf, 0x30);
        
        newIdx = p[1] + 1;
        count = *(u32*)(p + 8);
        delta = newIdx - count;
        delta2 = count - 1 - p[1];
        mask = ((s32)delta >> 31) | ((s32)delta2 >> 31);
        p[1] = newIdx & ~mask;
        
        OSRestoreInterrupts(enabled);
        return TRUE;
    }
    
    OSRestoreInterrupts(enabled);
    return FALSE;
}

static BOOL fn_80063A50(u8* p, u32 val2, u16 halfword, u32 val4, u32 val5) {
    u8 buf[0x40] ALIGN(8);
    s8 diff;
    BOOL enabled;
    u8 newIdx;
    u32 count;
    s8 delta;
    s8 delta2;
    u32 mask;

    *(u16*)&buf[8] = halfword;
    *(u32*)&buf[0xc] = val4;
    *(u32*)&buf[0x40] = 0x17;
    *(u16*)&buf[0x5a] = 6;
    *(u32*)&buf[0x6c] = val5;

    memcpy(&buf[0x44], &buf[0xc], 4);
    memcpy(&buf[0x48], &buf[8], 2);

    *(double*)&buf[0x10] = *(double*)&buf[0x40];
    *(double*)&buf[0x18] = *(double*)&buf[0x48];
    *(double*)&buf[0x20] = *(double*)&buf[0x50];
    *(double*)&buf[0x28] = *(double*)&buf[0x58];
    *(double*)&buf[0x38] = *(double*)&buf[0x68];
    *(u16*)&buf[0x60] = halfword;
    *(u32*)&buf[0x64] = val4;
    *(double*)&buf[0x30] = *(double*)&buf[0x60];

    enabled = OSDisableInterrupts();
    enabled = OSDisableInterrupts();

    diff = p[1] - p[0];
    if (diff < 0) {
        diff += (s8)(s32)*(u32*)(p + 8);
    }

    OSRestoreInterrupts(enabled);

    if (*(u32*)(p + 8) - 1 != (u32)diff) {
        memset(p + 4 + p[1] * 0x30, 0, 0x30);
        memcpy(p + 4 + p[1] * 0x30, &buf[0x10], 0x30);

        newIdx = p[1] + 1;
        count = *(u32*)(p + 8);
        delta = newIdx - count;
        delta2 = count - 1 - p[1];
        mask = ((s32)delta >> 31) | ((s32)delta2 >> 31);
        p[1] = newIdx & ~mask;

        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}

void WPADiClearQueue_80063BD4(WPADCommandQueue* pQueue) {
	s32 enabled = OSDisableInterrupts();

	pQueue->front = 0;
	pQueue->back = 0;
	memset(pQueue->buffer, 0, pQueue->capacity * sizeof(WPADCommand));

	OSRestoreInterrupts(enabled);
}

void getDevConfig(s32 chan, s32 result, WPADStatus* status, u8* data)
{
    register const char* messages asm("r30") = (const char*)lbl_80312338;
    register u8* p asm("r27") = (u8*)lbl_8038F4F0[chan];
    register u16 valueCC8 asm("r7") = lbl_80560CC8;
    register u16 valueCCA asm("r22") = lbl_80560CCA;
    register u16 valueCCC asm("r23") = lbl_80560CCC;
    register u16 valueCCE asm("r31") = lbl_80560CCE;
    register u16 valueCD0 asm("r0") = lbl_80560CD0;
    register u16 valueCD2 asm("r29") = lbl_80560CD2;
    register u16 valueCD4 asm("r28") = lbl_80560CD4;
    register u16 valueCD6 asm("r12") = lbl_80560CD6;
    register u8* config asm("r26") = *(u8**)(p + 0x8B4);
    register u32 attempt asm("r28");
    register s32 offset asm("r29");
    s32 i;
    u32 sum;
    u8* src;

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
                offset = (u8)attempt * 11;
                sum = 0;
                for (i = offset; i < offset + 10; i++) {
                    sum += config[i];
                }
                if ((u8)(sum + 0x55) == config[offset + 10]) {
                    DBPrintf_80068D68(messages + 0x98);
                    src = data + offset;
                    status->obj[0].x = (s16)src[0] | ((src[2] & 48) << 4);
                    status->obj[0].y = 0x2FF - (s16)((s16)src[1] | ((src[2] & 192) << 2));
                    status->obj[0].size = *(u16*)(p + 0x804);
                    status->obj[0].traceId = 0;
                    status->obj[1].x = (s16)src[3] | ((src[2] & 3) << 8);
                    status->obj[1].y = 0x2FF - (s16)((s16)src[4] | ((src[2] & 12) << 6));
                    status->obj[1].size = *(u16*)(p + 0x804);
                    status->obj[1].traceId = 1;
                    status->obj[2].x = (s16)src[5] | ((src[7] & 48) << 4);
                    status->obj[2].y = 0x2FF - (s16)((s16)src[6] | ((src[7] & 192) << 2));
                    status->obj[2].size = *(u16*)(p + 0x804);
                    status->obj[2].traceId = 2;
                    status->obj[3].x = (s16)src[8] | ((src[7] & 12) << 8);
                    status->obj[3].y = 0x2FF - (s16)((s16)src[9] | ((src[7] & 12) << 6));
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
            offset = (u8)attempt * 10;
            sum = 0;
            if (*(s32*)(p + 0x820) == 0) {
                offset += 22;
            }
            for (i = offset; i < offset + 9; i++) {
                sum += config[i];
            }
            src = config + offset;
            if ((u8)(sum + 0x55) == src[9]) {
                DBPrintf_80068D68(messages + 0x10C);
                *(s16*)(p + 0x7b4) = (src[0] << 2) | ((src[3] >> 4) & 3);
                *(s16*)(p + 0x7b6) = (src[1] << 2) | ((src[3] >> 2) & 3);
                *(s16*)(p + 0x7b8) = (src[2] << 2) | ((src[3] >> 0) & 3);
                *(s16*)(p + 0x7ba) = (src[4] << 2) | ((src[7] >> 4) & 3);
                *(s16*)(p + 0x7bc) = (src[5] << 2) | ((src[7] >> 2) & 3);
                *(s16*)(p + 0x7be) = (src[6] << 2) | ((src[7] >> 0) & 3);
                p[0x7C1] = src[8] & 0x7F;
                p[0x7C0] = src[8] & 0x80;
                break;
            }
            DBPrintf_80068D68(messages + 0x118);
        }
        DBPrintf_80068D68(messages + 0x128, *(s16*)(p + 0x7B4), *(s16*)(p + 0x7B6), *(s16*)(p + 0x7B8));
        DBPrintf_80068D68(messages + 0x150, *(s16*)(p + 0x7BA), *(s16*)(p + 0x7BC), *(s16*)(p + 0x7BE));
        DBPrintf_80068D68(messages + 0x178, p[0x7C1], p[0x7C0]);
    }
}

void fn_80064740(s32 chan, s32 param_2) {
    WPADCB* cb = lbl_8038F4F0[chan];
    u8* data = (u8*)cb->samplingBufSize;
    if (param_2 == 0) {
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

WPADCB* getGameInfo(s32 chan, s32 param_2, s32 param_3) {
    WPADCB* cb = lbl_8038F4F0[chan];
    
    if (param_2 == 0 && cb->samplingBufSize != NULL) {
        u8* src = (u8*)cb->samplingBufSize;
        u8 checksum = 0;
        s32 i;
        
        for (i = 0; i < 2; i++) {
            s32 j;
            for (j = 0; j < 7; j++) {
                checksum += src[i * 0x15 + j];
            }
        }
        
        // After loop, process bytes at offsets 14-20
        for (i = 0; i < 7; i++) {
            checksum += src[14 + i];
        }
        
        // Compare with stored checksum
        if (src[0x2F] == (checksum + 0x55)) {
            memcpy(&cb->gameInfo, src, 0x38);
            ((s32*)&cb->gameInfo)[2] = 0; // store 0 at offset 0x38
        } else {
            ((s32*)&cb->gameInfo)[2] = -4;
        }
    }
    
    return cb;
}

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

void fn_80064A80(s32 chan, s32 param_2) {
	WPADCB* cb = lbl_8038F4F0[chan];
	if (param_2 != 0) {
		WPADiClearQueue_80063BD4(&cb->extCmdQueue);
		if (param_2 == -1) {
			((u8*)cb)[0x801] = 0xfd;
		} else {
			s32 val = *(s32*)((u8*)cb + 0x780);
			s32 t = -val | val;
			s32 sign = t >> 31;
			((u8*)cb)[0x801] = (sign >> 24) & 0x3f;
		}
		if (*(s32*)((u8*)cb + 0x7e0) != 0) {
			((void (*)(s32))*(void**)((u8*)cb + 0x7e0))(chan);
		}
	}
}

// fn_80064B1C: WPAD data processing
void fn_80064B1C(s32 chan, void* data) {
    WPADCB* cb;
    u8* p;
    u8* buf;
    s32 enabled;
    s32 old;
    s32 i;
    s32 v;

    DBPrintf_80068D68((const char*)lbl_80312338 + 0x328);
    enabled = OSDisableInterrupts();
    cb = lbl_8038F4F0[(u8)chan];
    old = *(s32*)((u8*)cb + 0x81C);
    if (old == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }
    p = (u8*)cb;
    buf = p + 0xA0 + p[0x806] * 0x60;
    for (i = 0; i < 2; i++) {
        s32 j;
        for (j = 0; j < 48; j++) buf[i * 48 + j] = 0;
    }
    buf[0] = 0;
    buf[1] = ((u8*)data)[1];
    *(u16*)buf = (((u8*)data)[1] << 8) | ((u8*)data)[2];
    *(u16*)buf &= 0x9f1f;
    *(s32*)(p + 0x788) = ((u8*)data)[1] >> 7;
    *(s32*)(p + 0x778) = (((u8*)data)[3] >> 3) & 1;
    *(s32*)(p + 0x77C) = (((u8*)data)[3] >> 2) & 1;
    *(s32*)(p + 0x780) = (((u8*)data)[3] >> 1) & 1;
    *(s32*)(p + 0x784) = ((u8*)data)[3] & 1;
    p[0x78D] = ((u8*)data)[3] >> 4;
    p[0x78E] = 0;
    p[0x78F] = ((u8*)data)[5] & 0xf0;
    v = ((u8*)data)[6];
    if (v >= 0x55) p[0x78C] = 4;
    else if (v >= 0x44) p[0x78C] = 3;
    else if (v >= 0x33) p[0x78C] = 2;
    else if (v >= 3) p[0x78C] = 1;
    else p[0x78C] = 0;
    if (*(s32*)(p + 0x780) != 0) {
        if (old == 0) DBPrintf_80068D68((const char*)lbl_80312338 + 0x33c);
    } else {
        p[0x801] = 0;
        p[0x802] = 0;
    }
    if (*(s32*)(p + 0x790) != 0) {
        memcpy(p + 0x778, p + 0x790, 0x18);
        *(s32*)(p + 0x790) = 0;
    }
    if (*(void**)(p + 0x7dc) && p[0x800]) {
        ((WPADCallback)*(void**)(p + 0x7dc))(chan, 0);
        *(s32*)(p + 0x7dc) = 0;
    }
    buf[0x29] = 0xfe;
    buf[0x28] = p[0x801];
    p[0x800] = 0;
    p[0x806] = __cntlzw(p[0x806]) >> 24;
    OSRestoreInterrupts(enabled);
}

// fn_80064F64: WPAD data processing
void fn_80064F64(s32 chan, void* data) { /* stub */ }

// fn_80065524: WPAD data processing
void fn_80065524(s32 chan, WPADStatusEx* pStatus)
{
    WPADCB* pCB;
    volatile u8* pBuf;
    u32 enabled;
    u32 i;

    enabled = OSDisableInterrupts();
    pCB = lbl_8038F4F0[(u8)chan];
    pBuf = (volatile u8*)pCB + *(u8*)((u8*)pCB + 0x806) * 0x60 + 0xA0;
    for (i = 0; i < 2; i++) {
        pBuf[0] = 0; pBuf[1] = 0; pBuf[2] = 0; pBuf[3] = 0;
        pBuf[4] = 0; pBuf[5] = 0; pBuf[6] = 0; pBuf[7] = 0;
        pBuf[8] = 0; pBuf[9] = 0; pBuf[10] = 0; pBuf[11] = 0;
        pBuf[12] = 0; pBuf[13] = 0; pBuf[14] = 0; pBuf[15] = 0;
        pBuf[16] = 0; pBuf[17] = 0; pBuf[18] = 0; pBuf[19] = 0;
        pBuf[20] = 0; pBuf[21] = 0; pBuf[22] = 0; pBuf[23] = 0;
        pBuf[24] = 0; pBuf[25] = 0; pBuf[26] = 0; pBuf[27] = 0;
        pBuf[28] = 0; pBuf[29] = 0; pBuf[30] = 0; pBuf[31] = 0;
        pBuf[32] = 0; pBuf[33] = 0; pBuf[34] = 0; pBuf[35] = 0;
        pBuf[36] = 0; pBuf[37] = 0; pBuf[38] = 0; pBuf[39] = 0;
        pBuf[40] = 0; pBuf[41] = 0; pBuf[42] = 0; pBuf[43] = 0;
        pBuf[44] = 0; pBuf[45] = 0; pBuf[46] = 0; pBuf[47] = 0;
        pBuf += 48;
    }
    *(u16*)pBuf = 0;
    *(u16*)pBuf = ((pStatus->button & 0xFF) << 8) | ((pStatus->button >> 8) & 0xFF);
    *(u16*)pBuf &= 0x9F1F;

    if (*(s32*)((u8*)pCB + 0x7F8) == 0) {
        if (*(s32*)((u8*)pCB + 0x7FC) != 0) {
            pBuf[0x29] = *(u8*)((u8*)pCB + 0x7FC);
        } else {
            pBuf[0x29] = -4;
            pBuf[0x28] = *(u8*)((u8*)pCB + 0x801);
            *(u32*)((u8*)pCB + 0x788) = (pStatus->dev >> 1) & 1;
            *(u8*)((u8*)pCB + 0x806) = __cntlzw(*(u8*)((u8*)pCB + 0x806)) >> 24;
        }
    }
    OSRestoreInterrupts(enabled);
}

// fn_800656E8: WPAD data processing
void fn_800656E8(s32 chan, WPADStatusEx* pStatus)
{
    WPADCB* pCB;
    volatile u8* pBuf;
    u32 i;
    u32 offset;
    u8* p = (u8*)pStatus;

    pCB = lbl_8038F4F0[(u8)chan];
    pBuf = (volatile u8*)pCB + *(u8*)((u8*)pCB + 0x806) * 0x60 + 0xA0;
    offset = 0;
    for (i = 0; i < 2; i++) {
        pBuf[offset] = 0;
        pBuf[offset + 1] = 0;
        pBuf[offset + 2] = 0;
        pBuf[offset + 3] = 0;
        pBuf[offset + 4] = 0;
        pBuf[offset + 5] = 0;
        pBuf[offset + 6] = 0;
        pBuf[offset + 7] = 0;
        offset += 8;
        pBuf[offset] = 0;
        pBuf[offset + 1] = 0;
        pBuf[offset + 2] = 0;
        pBuf[offset + 3] = 0;
        pBuf[offset + 4] = 0;
        pBuf[offset + 5] = 0;
        pBuf[offset + 6] = 0;
        pBuf[offset + 7] = 0;
        offset += 8;
        pBuf[offset] = 0;
        pBuf[offset + 1] = 0;
        pBuf[offset + 2] = 0;
        pBuf[offset + 3] = 0;
        pBuf[offset + 4] = 0;
        pBuf[offset + 5] = 0;
        pBuf[offset + 6] = 0;
        pBuf[offset + 7] = 0;
        offset += 8;
        pBuf[offset] = 0;
        pBuf[offset + 1] = 0;
        pBuf[offset + 2] = 0;
        pBuf[offset + 3] = 0;
        pBuf[offset + 4] = 0;
        pBuf[offset + 5] = 0;
        pBuf[offset + 6] = 0;
        pBuf[offset + 7] = 0;
        offset += 8;
        pBuf[offset] = 0;
        pBuf[offset + 1] = 0;
        pBuf[offset + 2] = 0;
        pBuf[offset + 3] = 0;
        pBuf[offset + 4] = 0;
        pBuf[offset + 5] = 0;
        pBuf[offset + 6] = 0;
        pBuf[offset + 7] = 0;
        offset += 8;
        pBuf[offset] = 0;
        pBuf[offset + 1] = 0;
        pBuf[offset + 2] = 0;
        pBuf[offset + 3] = 0;
        pBuf[offset + 4] = 0;
        pBuf[offset + 5] = 0;
        pBuf[offset + 6] = 0;
        pBuf[offset + 7] = 0;
        offset += 8;
    }
    *(u16*)pBuf = ((u16)p[2] << 8) | p[1];
    *(u16*)pBuf &= 0x9F1F;
    if (*(s32*)((u8*)pCB + 0x7F8) > 1) {
        if (*(s32*)((u8*)pCB + 0x7FC) == 0) *(u8*)(pBuf + 0x29) = -4;
    } else {
        *(u8*)(pBuf + 0x29) = *(u8*)((u8*)pCB + 0x7FC);
    }
    *(u8*)(pBuf + 0x28) = *(u8*)((u8*)pCB + 0x801);
    *(u32*)((u8*)pCB + 0x788) = p[1] & 1;
    *(s16*)(pBuf + 2) = (s16)((((u16)p[3] << 2) & 0xFFFC) | ((p[1] >> 6) & 3)) - *(s16*)((u8*)pCB + 0x7B4);
    *(s16*)(pBuf + 4) = (s16)((((u16)p[4] << 2) & 0xFFFC) | ((p[2] >> 6) & 3)) - *(s16*)((u8*)pCB + 0x7B6);
    *(s16*)(pBuf + 6) = (s16)((((u16)p[5] << 2) & 0xFFFC) | ((p[2] >> 5) & 3)) - *(s16*)((u8*)pCB + 0x7B8);
    OSDisableInterrupts();
    *(u8*)((u8*)pCB + 0x806) = __cntlzw(*(u8*)((u8*)pCB + 0x806)) >> 24;
    OSRestoreInterrupts(0);
}

// fn_80065934: WPAD data processing
void fn_80065934(void) { /* stub */ }

// fn_800660E8: WPAD data processing
void fn_800660E8(s32 chan, void* data) { /* stub */ }

// fn_80066630: WPAD data processing
void fn_80066630(void) { /* stub */ }

// fn_80066634: WPAD data processing
void fn_80066634(s32 chan, void* data) { /* stub */ }

// fn_80066EAC: WPAD data processing
void fn_80066EAC(void) { /* stub */ }

// fn_80066EB0: WPAD data processing
void fn_80066EB0(void) { /* stub */ }

// fn_800678D8: WPAD data processing
void fn_800678D8(void) { /* stub */ }

// fn_800678DC: WPAD data processing
BOOL fn_800678DC(void) { return FALSE; }

// fn_80067ECC: WPAD data processing
void fn_80067ECC(s32 chan, void* data) { /* stub */ }

// fn_800684CC: WPAD data processing
void fn_800684CC(void) { /* stub */ }

void WPADiDecode(s32 chan, u8* data, s32 len, s32 seed) {
    WPADCB* cb = lbl_8038F4F0[chan];
    u32 i;
    u8* base = (u8*)cb;

    for (i = 0; i < (u32)len; i++) {
        u32 index = (seed + i) & 7;
        u8 key = base[0x86C + index];
        u8 value = base[0x864 + index];
        data[i] = value + (data[i] ^ key);
    }
}

// WUD function stubs
u8 WUDGetBufferStatus(void) { return 0; }
void fn_8005E298(void);
extern u8 lbl_8038F500[];
u16 _WUDGetNotAckedSize(s8 handle) {
#pragma unused(handle)
    return 0;
}
u8 _WUDGetLinkNumber(void) { return 0; }
void __a1_22_ack(u8 chan, u8* pReport)
{
    WPADCB* pCB;
    volatile u8* pBuf;
    u32 offset;
    u8 type;
    u8 ext;
    BOOL intr;

    intr = OSDisableInterrupts();
    DBPrintf_80068D68((const char*)lbl_80312338 + 0x3E0);
    pCB = lbl_8038F4F0[(u8)chan];
    pBuf = (volatile u8*)pCB + *(u8*)((u8*)pCB + 0x806) * 0x60 + 0xA0;
    for (offset = 0; offset < 96; offset += 8) {
        pBuf[offset] = 0;
        pBuf[offset + 1] = 0; pBuf[offset + 2] = 0; pBuf[offset + 3] = 0;
        pBuf[offset + 4] = 0; pBuf[offset + 5] = 0; pBuf[offset + 6] = 0; pBuf[offset + 7] = 0;
    }
    *(u16*)(pBuf + 0x60) = ((u16)pReport[1] << 8 | pReport[2]) & 0x9F1F;
    type = pReport[3];
    ext = pReport[4];
    DBPrintf_80068D68((const char*)lbl_80312338 + 0x3F0, type, ext);
    pBuf[0x89] = -2;
    pBuf[0x88] = *((u8*)pCB + 0x801);
    if (ext) {
        DBPrintf_80068D68((const char*)lbl_80312338 + 0x41C, type, ext);
        if (*((u8*)pCB + 0x8C7) == type) {
            WPADCallback callback = *(WPADCallback*)((u8*)pCB + 0x7DC);
            if (callback) {
                callback(chan, -2);
                *(u32*)((u8*)pCB + 0x7DC) = 0;
                *(u32*)((u8*)pCB + 0x7FC) = 0;
            }
        } else {
            DBPrintf_80068D68((const char*)lbl_80312338 + 0x44C);
        }
    }
    *((u8*)pCB + 0x806) = __cntlzw(*((u8*)pCB + 0x806)) >> 24;
    OSRestoreInterrupts(intr);
}

void fn_8005E8C0(u32 r3, u32 r4)
{
	OSSwitchFiberEx(r3, r4, 0, 0, fn_8005E298, (u8*)&lbl_8038F500 + 0x1000);
}

void fn_8005E8E0(s32 chan)
{
    WPADCB* pCB = lbl_8038F4F0[chan];
    u8* p = (u8*)pCB;
    s32 enabled;
    u32 i = (u32)chan * 0x14;
    u8 value = 0xFD;

    *(u8*)(p + 0x806) = 0;
    *(u32*)(p + 0x790) = 0;
    *(u32*)(p + 0x814) = 0;
    *(u32*)(p + 0x7DC) = 0;
    *(u32*)(p + 0x7E0) = 0;
    *(u32*)(p + 0x7E8) = 0;
    *(u32*)(p + 0x7EC) = 0;
    *(u32*)(p + 0x7F0) = 0;
    *(u32*)(p + 0x7F4) = 0;
    *(u32*)(p + 0x7F8) = 0;
    *(u32*)(p + 0x7FC) = -1;
    p[0x801] = value;
    p[0x802] = 0;
    p[0x851] = 0;
    *(u16*)(p + 0x852) = 0;
    p[0x800] = 0;
    *(u16*)(p + 0x804) = 12;
    *(u16*)(p + 0x838) = 0;
    *(u16*)(p + 0x83A) = 0;
    *(u16*)(p + 0x83C) = 0;
    *(u16*)(p + 0x83E) = 0;
    *(u16*)(p + 0x840) = 0;
    *(u16*)(p + 0x842) = 0;
    *(u64*)(p + 0x830) = __OSGetSystemTime();
    *(u64*)(p + 0x848) = __OSGetSystemTime();
    p[0x850] = 0;
    p[0x807] = 0;
    *(u32*)(p + 0x808) = 0;
    *(u32*)(p + 0x8B4) = 0;
    *(u32*)(p + 0x8B8) = 0;
    *(u16*)(p + 0x8C0) = 0;
    *(u32*)(p + 0x8BC) = 0;
    p[0x803] = 0xFF;
    *(u32*)(p + 0x818) = 0;
    *(u32*)(p + 0x81C) = 0;
    *(u32*)(p + 0x820) = 0;
    p[0x80C] = 1;
    p[0x80D] = 0;
    p[0x80E] = 0;
    p[0x8C2] = 0;
    p[0x8C3] = 0;
    *(u16*)(p + 0x8C4) = 0;
    p[0x8C6] = 1;
    memset(p + 0x778, 0, 0x18);
    memset(p + 0x874, 0, 0x40);
    memset(p + 0xA0, 0, 0xC0);
    memset(p + 0x40, 0, 0x60);
    memset(p + 0x794, 0, 0x2E);
    memset(p + 0x7C2, 0, 0x1A);
    memset(p + 0x854, 0, 0x10);
    memset(p + 0x864, 0, 8);
    memset(p + 0x86C, 0, 8);
    memset(p, 0, 0x38);
    *(u32*)(p + 0x38) = -1;
    *(u32*)(p + 0x3C) = -1;
    *(void**)(p + 0x164) = p + 0x16C;
    *(u32*)(p + 0x168) = 0x18;
    *(void**)(p + 0x5F0) = p + 0x5F8;
    *(u32*)(p + 0x5F4) = 8;
    enabled = OSDisableInterrupts();
    p[0x160] = 0;
    p[0x161] = 0;
    memset(*(void**)(p + 0x164), 0, *(u32*)(p + 0x168) * 0x30);
    OSRestoreInterrupts(enabled);
    enabled = OSDisableInterrupts();
    p[0x5EC] = 0;
    p[0x5ED] = 0;
    memset(*(void**)(p + 0x5F0), 0, *(u32*)(p + 0x5F4) * 0x30);
    OSRestoreInterrupts(enabled);
    *(u32*)(lbl_80392900 + i) = 0;
    *(u32*)(lbl_80392900 + i + 4) = 0;
    *(u16*)(lbl_80392900 + i + 8) = 0;
    *(u32*)(lbl_80392900 + i + 12) = 0;
    *(u32*)(lbl_80392900 + i + 16) = 0;
}

extern WPADCB* getGameInfo(s32 param_1, s32 param_2, s32 param_3);
#include <types.h>