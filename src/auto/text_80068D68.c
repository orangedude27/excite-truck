// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <stdarg.h>
#include <printf.h>
#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/bta/include/ptim.h"
#include "revolution/BTE/gki/platform/gki_int.h"
#include "revolution/BTE/gki/common/gki.h"
#include <revolution/OS.h>
extern u8 lbl_803C4040[];
extern u8 lbl_803151D8[];
extern char lbl_8031801C[];
extern char lbl_80318040[];
extern char lbl_8031806C[];
extern char lbl_80318090[];
extern void *l2cu_find_lcb_by_bd_addr(u8 *addr);
extern void l2cu_create_conn_after_switch(void *p_lcb);
extern u8 lbl_80392960[];
extern u8 lbl_803C0D48[];
extern u8 lbl_803C0B98[];
extern u32 lbl_8055DCA4;
extern void fn_80070F90(void *ptr);
extern u8 lbl_803C4C40[];
#include "revolution/BTE/stack/sdp/sdpint.h"
#include "revolution/BTE/stack/include/wbt_api.h"
extern void AXFXReverbHiExpShutdown(void*);
extern s32 AXFXReverbHiExpInit(void*);
extern void __FreeDelayLine(void*);
extern s32 __CtrlMsgInt(s32,s32,s32,s32,s32,u32,void*,void*,void*,s32);
extern f32 lbl_80560D50;
extern f32 lbl_80560D54;
extern u32 lbl_80560D28;

extern u8 lbl_803C0F78[];
extern u8 lbl_80316570[];
extern u8 lbl_80315CA0[];
extern u8 lbl_80559060[];
extern s32 btsnd_hcic_reset_800857CC(void);
extern u8 lbl_803C0AD8[];
extern u8 lbl_8055DC80;
extern u8 *lbl_80559038;
extern void fn_8006E6E4(void *);
extern void fn_80071450(void *);
  extern void fn_80070954(u32 code, void *msg, u16 param);
  extern char lbl_80319D48[];
extern char lbl_80319EC0[];
extern void fn_8007096C(u32 code, void *msg, u16 param1, u16 param2);
extern void fn_800709CC(u32 code, void *msg, s32 param1, s32 param2, u16 param3, u16 param4, u8 param5, u16 param6);
extern u8 lbl_803C4828[];
extern void rfc_send_fcon(void *, s32, void *);
extern void rfc_send_fcon_80093FDC(void *, s32);
extern void PORT_FlowInd(void *, s32, s32);
extern void PORT_LineStatusInd(void *, u8, u8);
extern void *port_find_mcb_dlci_port(void *mcb, u8 dlci);
extern void rfc_port_timer_stop(void *);
extern void rfc_send_rls(void *, u8, s32, u8);
extern void rfc_check_send_cmd(void *, void *);
extern void fn_800916F4(void *, s32, s16 *);
extern char lbl_803140D0[];
extern char lbl_80315048[];
extern u8 lbl_803C0C14[];
extern void bta_dm_signal_strength_timer_cback(void *);
extern s32 fn_8008128C(void *);
extern char lbl_803140E8[];
extern char lbl_803BF240[2000];
extern char lbl_803BFA20[0x5000];
extern char lbl_80559040[4]; /* "%s\n" */
extern u8 lbl_8055DC70;
extern u32 fn_8009B0E0(void);
extern void btu_task_msg_handler(void);
extern int vsprintf(char *s, const char *format, va_list arg);
extern int sprintf(char *s, const char *format, ...);
extern void OSReport(const char *msg, ...);

extern void OSReport(const char *msg, ...);

extern const char lbl_80313BB0[];
extern const char lbl_80313BCC[];
extern const char lbl_805590A4[];
extern char lbl_8031A620[];
extern u8 lbl_8055DC90;
#include "revolution/BTE/stack/include/sdp_api.h"
typedef struct hcisu_if {
    void (*init)(u32, u32, u32);
    void (*open)(void *);
    void (*close)(s32, void *);
} hcisu_if;

typedef struct tUUSB {
    u8 pad0[4];
    u16 at_0x04; // at 0x4
    u16 at_0x06; // at 0x6
    u16 at_0x08; // at 0x8
    u8 padA;     // at 0xA
    u8 at_0x0B;  // at 0xB
    u8 padC[2];
} tUUSB;

typedef struct hcisu_h2_cb_t {
    u8 pad[0x1E];
    u8 at_0x1E; // at 0x1E
    u8 at_0x1F; // at 0x1F
} hcisu_h2_cb_t;

typedef struct tHCI_CFG {
    u16 at_0x00; // at 0x0
    u16 at_0x02; // at 0x2
} tHCI_CFG;

extern hcisu_h2_cb_t lbl_803BD1A0;
#define hcisu_h2_cb lbl_803BD1A0
extern void UUSB_Register(tUUSB *uusb);
extern void UUSB_Open(tUUSB *uusb, void *cback);
extern void UUSB_Close(void *uusb);
void fn_80070758(void);

extern hcisu_if *lbl_8055DC68;
extern void *lbl_8055DC6C;
extern s32 lbl_8055DC74;
extern void GKI_freebuf(void *);
extern void GKI_shutdown(void);
extern u8 lbl_80559050;
extern s32 lbl_80559054;
extern s32 lbl_8055DC78;
extern s32 lbl_8055DC7C;
extern void fn_80070854(void);
extern void fn_8008251C(void);
extern void OSCancelAlarm(OSAlarm *alarm);

void DBPrintf_80068D68(const char *fmt, ...) {
#pragma unused(fmt)
}

void DeleteFlushCallback(s32 arg0) {
    extern void DBPrintf_8006CFA8(const char *, ...);
    extern u8 lbl_803131E8[];
    extern u8 lbl_80392960[];
    DBPrintf_8006CFA8((const char *)lbl_803131E8, arg0, lbl_80392960[0xD]);
    if (lbl_80392960[0xD] != 0) lbl_80392960[0xD] = 8;
}

void fn_80068F28(s32 arg0) {
    extern void DBPrintf_8006CFA8(const char *, ...);
    extern char lbl_80313210[];
    extern u8 lbl_80392960[];
    extern void OSCancelAlarm(OSAlarm *);
    extern void fn_80073AF8(void);
    DBPrintf_8006CFA8(lbl_80313210, arg0, lbl_80392960[0x11]);
    OSCancelAlarm((OSAlarm *)(lbl_80392960 + 0x690));
    lbl_80392960[0x11] = 3;
    fn_80073AF8();
}

void fn_80068F80(void) {
    lbl_80392960[0xC] = 1;
}

extern u8 lbl_80393680[];
extern void fn_80069408(void);
extern void fn_80069D80(void);
void fn_80069C14(u32 r3, u32 r4) {
    OSSwitchFiberEx(r3, r4, 0, 0, fn_80069408, (u8*)&lbl_80393680 + 0x1000);
}

s32 WUDiTerminateDevice(void) {
    s32 i;
    u8 *entry;
    u8 *base = lbl_80392960;
    for (i = 0, entry = base + 0x64; i < 10; i++, entry += 0x60) {
        if (entry[0x59] > 1) btm_remove_acl(entry + 0x40);
    }
    for (i = 0, entry = base + 0x424; i < 6; i++, entry += 0x60) {
        if (entry[0x59] > 1) btm_remove_acl(entry + 0x40);
    }
    return 3;
}

void fn_80069D80(void) {
    extern s32 WUDiDeleteDevice(void);
    extern s32 SCCheckStatus(void);
    extern s32 SCSetBtDeviceInfoArray(void *);
    extern void SCFlushAsync(void *);
    extern void OSCancelAlarm(OSAlarm *);
    extern u8 lbl_80393058[];
    u8 *base = lbl_80392960;
    u8 state = base[0xD];
    base[0xC] = 0;
    switch (state) {
    case 1:
        BTA_DmSetVisibility(0, 0);
        base[0xD] = 2;
        break;
    case 2:
        base[0xD] = WUDiTerminateDevice();
        break;
    case 3:
        base[0xD] = WUDiDeleteDevice();
        break;
    case 5:
        if (SCCheckStatus() != 0) break;
        memset(lbl_80393058, 0, 0x461);
        if (SCSetBtDeviceInfoArray(lbl_80393058) != 0) {
            base[0xD] = 6;
            SCFlushAsync(DeleteFlushCallback);
        }
        break;
    case 8: {
        BOOL enabled = OSDisableInterrupts();
        u8 connectable = base[0x66A];
        OSRestoreInterrupts(enabled);
        enabled = OSDisableInterrupts();
        base[0x66B] = 0;
        base[0x66A] = connectable;
        OSRestoreInterrupts(enabled);
        BTA_DmSetVisibility(0, connectable);
        OSCancelAlarm((OSAlarm *)(base + 0x690));
        base[0xD] = 0;
        if (base[8] != 0) {
            ((void (*)(u32))base[8])(1);
        }
        base[0xD] = 0;
        break;
    }
    }
}

void fn_80069EB4(u32 r3, u32 r4) {
    OSSwitchFiberEx(r3, r4, 0, 0, fn_80069D80, (u8*)&lbl_80393680 + 0x1000);
}

extern u8 lbl_80392960[];
extern u8 lbl_80393058[];
extern void fn_80069FE8(void);
extern void fn_8006A300(void);
extern u8 fn_8006A1DC(void);
extern void fn_8006BAD8(void);
extern s32 SCCheckStatus(void);
extern s32 BTA_EnableBluetooth(void *);
extern s32 SCSetBtDeviceInfoArray(void *);
extern void SCFlushAsync(void *);
void fn_8006A1BC(u32 r3, u32 r4)
{
    OSSwitchFiberEx(r3, r4, 0, 0, fn_80069FE8, (u8*)&lbl_80393680 + 0x1000);
}

void fn_8006A300(void)
{
    u8 state = lbl_80392960[0x10];

    switch (state) {
    case 1:
        lbl_80392960[0x10] = (SCCheckStatus() == 0) ? 2 : 1;
        break;
    case 2:
        lbl_80392960[0x10] = fn_8006A1DC();
        break;
    case 3:
        OSCancelAlarm((OSAlarm *)(lbl_80392960 + 0x690));
        lbl_80392960[0x688] = 1;
        BTA_EnableBluetooth(fn_8006BAD8);
        lbl_80392960[0x10] = 4;
        break;
    }
}

void fn_8006A39C(u32 r3, u32 r4)
{
    OSSwitchFiberEx(r3, r4, 0, 0, fn_8006A300, (u8*)&lbl_80393680 + 0x1000);
}

void fn_8006A3BC(void)
{
    volatile u8 *base = lbl_80392960;
    u8 state = base[0x11];
    switch (state) {
    case 1:
        if (SCCheckStatus() == 0) {
            if (SCSetBtDeviceInfoArray(lbl_80393058) != 0) {
                SCFlushAsync(fn_80068F28);
                state = 2;
            } else {
                state = 1;
            }
            base[0x11] = state;
            break;
        }
        break;
    case 2:
        break;
    }
}

void fn_8006A3BC(void);
void fn_8006A440(u32 r3, u32 r4)
{
	OSSwitchFiberEx(r3, r4, 0, 0, fn_8006A3BC, (u8*)&lbl_80393680 + 0x1000);
}

extern void fn_8006B598(void *);
void fn_8006A7D0(s32 arg0, s32 arg1) {
    s32 saved = OSDisableInterrupts();
    *(s32 *)(lbl_80392960 + 0x674) = arg0;
    *(s32 *)(lbl_80392960 + 0x678) = arg1;
    OSRestoreInterrupts(saved);
}

s8 fn_8006A940(void)
{
    u32 enabled;
    volatile s8 value;
    enabled = OSDisableInterrupts();
    value = (s8)lbl_80392960[0x688];
    OSRestoreInterrupts(enabled);
    return value;
}

extern u8 lbl_80392960[];
u8 fn_8006A97C(void)
{
    u32 enabled;
    u8 value;
    enabled = OSDisableInterrupts();
    value = (u8)(*(u16 *)(lbl_80392960 + 0x6C6) - *(u16 *)(lbl_80392960 + 0x6C4));
    OSRestoreInterrupts(enabled);
    return value;
}

void WUDSetSniffMode(BD_ADDR addr, s32 interval)
{
    tBTM_PM_PWR_MD block;
    if (interval > 0) {
        block.mode = BTM_PM_MD_SNIFF;
    } else {
        block.mode = BTM_PM_MD_ACTIVE;
    }
    block.max = interval;
    block.min = interval;
    block.attempt = 1;
    block.timeout = 0;
    BTM_SetPowerMode(lbl_80392960[0x68A], addr, &block);
}

s32 WUDSetDisableChannel(s8 arg0) {
    extern void DBPrintf_8006CFA8(const char *, ...);
    extern u8 BTM_SetAfhChannels(u8, u8);
    extern char lbl_80313550[];
    extern char lbl_80313568[];
    extern u8 lbl_80392960[];
    register s32 result = 0;
    register volatile u8 *base = lbl_80392960;
    s32 min;
    s32 max;
    s32 channel;
    s32 state;
    u8 status;
    DBPrintf_8006CFA8(lbl_80313550);
    if (arg0 < 0 || arg0 > 0xD) return 0;
    state = OSDisableInterrupts();
    channel = (s8)base[0x688];
    OSRestoreInterrupts(state);
    if ((u32)channel == 3) {
        if (arg0 == 0) {
            min = 0xFF;
            max = 0xFF;
        } else {
            channel = arg0 + 1;
            channel = channel * 5;
            min = channel - 0xE;
            max = channel + 0xE;
            if (min < 0) min = 0;
            if (max > 0x4E) max = 0x4E;
        }
        status = BTM_SetAfhChannels((u8)min, (u8)max);
        DBPrintf_8006CFA8(lbl_80313568, status);
        result = 1;
    }
    return result;
}

s32 fn_8006ADC4(s32 arg0)
{
    extern void DBPrintf_8006CFA8(const char *, ...);
    extern const char lbl_80313584[];
    s32 prev;
    s32 enabled;
    DBPrintf_8006CFA8(lbl_80313584, arg0);
    enabled = OSDisableInterrupts();
    prev = *(s32 *)(lbl_80392960 + 0x66C);
    *(s32 *)(lbl_80392960 + 0x66C) = arg0;
    OSRestoreInterrupts(enabled);
    return prev;
}

s32 fn_8006AE20(s32 arg0)
{
    extern void DBPrintf_8006CFA8(const char *, ...);
    extern const char lbl_803135A0[];
    s32 prev;
    s32 enabled;
    DBPrintf_8006CFA8(lbl_803135A0, arg0);
    enabled = OSDisableInterrupts();
    prev = *(s32 *)(lbl_80392960 + 0x670);
    *(s32 *)(lbl_80392960 + 0x670) = arg0;
    OSRestoreInterrupts(enabled);
    return prev;
}

void WUDSetVisibility(u8 arg0, u8 arg1)
{
    s32 enabled;
    enabled = OSDisableInterrupts();
    lbl_80392960[0x66B] = arg0;
    lbl_80392960[0x66A] = arg1;
    OSRestoreInterrupts(enabled);
    BTA_DmSetVisibility(arg0, arg1);
}

void fn_8006B26C(tBTM_VSC_CMPL *arg0) {
    extern u8 lbl_8055DC39;
    extern u8 lbl_8055DC3A;
    extern u8 lbl_80313600[];
    extern void fn_8006B330(void);
    s32 count;
    s32 size;
    u8 packet[0x100];

    if (arg0 != 0) {
        if (lbl_8055DC3A == lbl_8055DC39) {
            fn_8006B330();
            return;
        }
        count = lbl_8055DC3A - lbl_8055DC39;
        if (count >= 0x13) count = 0x13;
        packet[0] = count;
        size = count * 0xD;
        memcpy(packet + 1, lbl_80313600 + lbl_8055DC39 * 0xD + 1, size);
        lbl_8055DC39 += count;
        BTM_VendorSpecificCommand(0xFC4F, size + 1, packet, fn_8006B26C);
        return;
    }
    fn_8006B330();
}

extern void *lbl_80319994;
extern u16 lbl_80394680[];
extern u32 lbl_80393628[];
s32 _WUDGetDevAddr(u32 arg0) {
    s32 r31;
    s32 saved = OSDisableInterrupts();
    if (arg0 < 0x10) {
        r31 = ((u32 *)&lbl_80393628)[(u8)arg0];
    } else {
        r31 = 0;
    }
    OSRestoreInterrupts(saved);
    return r31;
}

u16 _WUDGetQueuedSize(s8 arg0) {
    u16 r31;
    s32 saved = OSDisableInterrupts();
    if (arg0 >= 0 && arg0 < 0x10) {
        r31 = lbl_80394680[arg0];
    } else {
        r31 = 0;
    }
    OSRestoreInterrupts(saved);
    return r31;
}

extern u16 lbl_803946A0[];
u16 _WUDGetQueuedSize_8006CA10(s8 arg0) {
    u16 r31;
    s32 saved = OSDisableInterrupts();
    if (arg0 >= 0 && arg0 < 0x10) {
        r31 = lbl_803946A0[arg0];
    } else {
        r31 = 0;
    }
    OSRestoreInterrupts(saved);
    return r31;
}

s32 fn_8006CFA0(void) {
    return 0;
}

void DBPrintf_8006CFA8(const char *fmt, ...) {
#pragma unused(fmt)
}

void fn_8006D4C4(void *arg) {
    ((s32 *)arg)[1] = 0;
    ((s32 *)arg)[0] = 0;
    ((u16 *)arg)[4] = 0;
}

void *GKI_read_mbox(UINT8 mbox) {
    UINT8 task_id = GKI_get_taskid();
    void *p_buf = NULL;
    BUFFER_HDR_T *p_hdr;

    if (task_id >= GKI_MAX_TASKS || mbox >= NUM_TASK_MBOX) {
        return NULL;
    }

    GKI_disable();

    if (gki_cb.com.OSTaskQFirst[task_id][mbox]) {
        p_hdr = gki_cb.com.OSTaskQFirst[task_id][mbox];
        gki_cb.com.OSTaskQFirst[task_id][mbox] = p_hdr->p_next;
        p_hdr->p_next = NULL;
        p_hdr->status = BUF_STATUS_UNLINKED;
        p_buf = (UINT8 *)p_hdr + BUFFER_HDR_SIZE;
    }

    GKI_enable();

    return p_buf;
}

void *GKI_dequeue(BUFFER_Q *p_q) {
    BUFFER_HDR_T *p_hdr;

    GKI_disable();

    if (!p_q || !p_q->count) {
        GKI_enable();
        return NULL;
    }

    p_hdr = (BUFFER_HDR_T *)((UINT8 *)p_q->p_first - BUFFER_HDR_SIZE);

    if (p_hdr->p_next) {
        p_q->p_first = (void *)((UINT8 *)p_hdr->p_next + BUFFER_HDR_SIZE);
    } else {
        p_q->p_first = NULL;
        p_q->p_last = NULL;
    }

    p_q->count--;

    p_hdr->p_next = NULL;
    p_hdr->status = BUF_STATUS_UNLINKED;

    GKI_enable();

    return (void *)((UINT8 *)p_hdr + BUFFER_HDR_SIZE);
}

s32 fn_8006DF60(s32 *arg0) {
    return *arg0;
}

extern void fn_8006EBAC(void);
extern void fn_8006EB88(void);
extern u8 fn_8006EB80(void);
extern u32 lbl_803946C0[];
extern u8 lbl_80392960[0x1000];
extern u16 lbl_80394680[];
extern u32 lbl_80393628[];
s32 fn_8006DF68(s32 *arg0) {
    s32 val = arg0[-2];
    return val ? val + 8 : 0;
}

u8 fn_8006DF84(void *arg0) {
    u16 val = *(u16 *)((u8 *)arg0 + 8);
    u32 tmp = __cntlzw(val);
    return tmp >> 19;
}

void gki_timers_init(void) {
    u8 *base = (u8 *)&lbl_803946C0 + 0x30000;
    *(u32 *)(base - 0x77C8) = 0;
    *(u32 *)(base - 0x77C4) = 0;
    *(u32 *)(base - 0x77C0) = 0;
    *(u32 *)(base - 0x77A0) = 0;
    *(u32 *)(base - 0x7780) = 0;
    *(u32 *)(base - 0x7760) = 0;
    *(u32 *)(base - 0x7740) = 0;
    *(u32 *)(base - 0x77BC) = 0;
    *(u32 *)(base - 0x779C) = 0;
    *(u32 *)(base - 0x777C) = 0;
    *(u32 *)(base - 0x775C) = 0;
    *(u32 *)(base - 0x773C) = 0;
    *(u32 *)(base - 0x77B8) = 0;
    *(u32 *)(base - 0x7798) = 0;
    *(u32 *)(base - 0x7778) = 0;
    *(u32 *)(base - 0x7758) = 0;
    *(u32 *)(base - 0x7738) = 0;
    *(u32 *)(base - 0x77B4) = 0;
    *(u32 *)(base - 0x7794) = 0;
    *(u32 *)(base - 0x7774) = 0;
    *(u32 *)(base - 0x7754) = 0;
    *(u32 *)(base - 0x7734) = 0;
    *(u32 *)(base - 0x77B0) = 0;
    *(u32 *)(base - 0x7790) = 0;
    *(u32 *)(base - 0x7770) = 0;
    *(u32 *)(base - 0x7750) = 0;
    *(u32 *)(base - 0x7730) = 0;
    *(u32 *)(base - 0x77AC) = 0;
    *(u32 *)(base - 0x778C) = 0;
    *(u32 *)(base - 0x776C) = 0;
    *(u32 *)(base - 0x774C) = 0;
    *(u32 *)(base - 0x772C) = 0;
    *(u32 *)(base - 0x77A8) = 0;
    *(u32 *)(base - 0x7788) = 0;
    *(u32 *)(base - 0x7768) = 0;
    *(u32 *)(base - 0x7748) = 0;
    *(u32 *)(base - 0x7728) = 0;
    *(u32 *)(base - 0x77A4) = 0;
    *(u32 *)(base - 0x7784) = 0;
    *(u32 *)(base - 0x7764) = 0;
    *(u32 *)(base - 0x7744) = 0;
    *(u32 *)(base - 0x7724) = 0;
}

s32 fn_8006E4F8(void) {
    u8 *base = (u8 *)&lbl_803946C0 + 0x30000;
    return *(s32 *)(base - 0x77D8);
}

void GKI_stop_timer(UINT8 tnum) {
    UINT8 task_id = GKI_get_taskid();

    switch (tnum) {
#if (GKI_NUM_TIMERS > 0)
        case TIMER_0:
            gki_cb.com.OSTaskTmr0R[task_id] = 0;
            gki_cb.com.OSTaskTmr0[task_id] = 0;
            break;
#endif

#if (GKI_NUM_TIMERS > 1)
        case TIMER_1:
            gki_cb.com.OSTaskTmr1R[task_id] = 0;
            gki_cb.com.OSTaskTmr1[task_id] = 0;
            break;
#endif
    }
}

void fn_8006E6E4(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

UINT16 GKI_update_timer_list(TIMER_LIST_Q *p_timer_listq, INT32 num_units_since_last_update) {
    TIMER_LIST_ENT *p_tle;
    UINT16 num_time_out = 0;
    INT32 rem_ticks;
    INT32 temp_ticks;

    p_tle = p_timer_listq->p_first;

    while (p_tle && p_tle->ticks <= 0) {
        num_time_out++;
        p_tle = p_tle->p_next;
    }

    rem_ticks = num_units_since_last_update;

    while (p_tle != NULL && rem_ticks > 0) {
        temp_ticks = p_tle->ticks;
        p_tle->ticks -= rem_ticks;

        if (p_tle->ticks <= 0) {
            p_tle->ticks = 0;
            num_time_out++;
        }

        rem_ticks -= temp_ticks;
        p_tle = p_tle->p_next;
    }

    if (p_timer_listq->last_ticks > 0) {
        p_timer_listq->last_ticks -= num_units_since_last_update;

        if (p_timer_listq->last_ticks < 0)
            p_timer_listq->last_ticks = 0;
    }

    return num_time_out;
}

void GKI_init(void) {
    memset(&gki_cb, 0, sizeof(gki_cb));

    gki_buffer_init();
    gki_timers_init();
    gki_cb.com.OSRdyTbl[GKI_PPC_TASK] = TASK_READY;
    gki_cb.com.OSTName[GKI_PPC_TASK] = NULL;
    gki_cb.com.OSWaitTmr[GKI_PPC_TASK] = 0;
    gki_cb.com.OSWaitEvt[GKI_PPC_TASK] = 0;

    gki_cb.os.int_index = 0;
    gki_cb.os.int_state[gki_cb.os.int_index] = OSEnableInterrupts();
    gki_cb.os.int_index++;
}

void GKI_shutdown(void) {
    gki_cb.os.int_state[gki_cb.os.int_index] = OSDisableInterrupts();
    gki_cb.os.int_index++;
    gki_cb.com.OSRdyTbl[GKI_PPC_TASK] = TASK_DEAD;
    gki_cb.os.int_index--;
    OSRestoreInterrupts(gki_cb.os.int_state[gki_cb.os.int_index]);

    while (gki_cb.os.int_index > 0) {
        gki_cb.os.int_index--;
        OSRestoreInterrupts(gki_cb.os.int_state[gki_cb.os.int_index]);
    }
}

void fn_8006EACC(void) {

}

void fn_8006EAD0(void) {

}

void fn_8006EAD4(void) {

}

void fn_8006EAD8(void) {

}

UINT8 GKI_send_event(UINT8 task_id, UINT16 event) {
    if (task_id >= GKI_MAX_TASKS) {
        return GKI_FAILURE;
    }

    gki_cb.os.int_state[gki_cb.os.int_index] = OSDisableInterrupts();
    gki_cb.os.int_index++;
    gki_cb.com.OSWaitEvt[task_id] |= event;
    gki_cb.os.int_index--;
    OSRestoreInterrupts(gki_cb.os.int_state[gki_cb.os.int_index]);

    return GKI_SUCCESS;
}

u8 fn_8006EB80(void) {
    return 2;
}

#pragma dont_inline on
void fn_8006EB88(void) {
    gki_cb.os.int_index--;
    OSRestoreInterrupts(gki_cb.os.int_state[gki_cb.os.int_index]);
}

void fn_8006EBAC(void) {
    gki_cb.os.int_state[gki_cb.os.int_index] = OSDisableInterrupts();
    gki_cb.os.int_index++;
}

void fn_8006EBF0(void) {

}

extern s32 fn_80068DB8(void);
s32 fn_8006EBF4(void) {
    s32 r = fn_80068DB8();
    if (r == 0) {
        r = 0;
    }
    return r;
}

void fn_8006EC20(void) {
    fn_80068E08();
}

void fn_8006EC24(s32 arg0, s32 arg1) {
    if (arg0 != 4) {
        if (arg0 >= 4) {
            return;
        }
        if (arg0 == 0) {
            return;
        }
    }
    fn_80070B24((s8)arg1);
}

void fn_8006F18C(u8 arg0, u8 arg1, u16 arg2) {
    hcisu_h2_cb_t *cb = &hcisu_h2_cb;
    cb->pad[0x1E] = 0;
    cb->pad[0x1A] = 0;
    cb->pad[0x1B] = 0;
    cb->pad[0x1C] = 0;
    cb->at_0x1F = arg0;
    cb->pad[0x20] = arg1;
    *(u16 *)&cb->pad[0x12] = arg2;
}

BOOL hcisu_h2_open(tHCI_CFG *p_cfg) {
    tUUSB uusb;
    BOOL result = TRUE;

    uusb.at_0x0B = 0;
    uusb.at_0x04 = p_cfg->at_0x00;
    uusb.at_0x06 = p_cfg->at_0x02;
    uusb.at_0x08 = hcisu_h2_cb.at_0x1F;

    hcisu_h2_cb.at_0x1E = 2;

    UUSB_Register(&uusb);
    UUSB_Open(&uusb, fn_8006EC24);

    return result;
}

void fn_8006F220(void) {
    hcisu_h2_cb.at_0x1E = 0;
    UUSB_Close(&hcisu_h2_cb);
    fn_80070758();
}

int fn_8006F254(s32 arg0) {
    hcisu_h2_send_msg_now((u8 *)&lbl_803BD1A0, arg0);
    return 1;
}

int fn_8006F284(s32 arg0) {
    hcisu_h2_receive_msg((u16)(arg0 - 8 - *(u16 *)((u8 *)&lbl_803BD1A0 + 0x12)), (u8 *)&lbl_803BD1A0);
    return 0;
}

s32 fn_8007011C(void) { return 0; }

/* uusb control block at lbl_803BD1E0 (96 bytes): fd @0, state u8 @0x29,
 * BUFFER_Q acl_q @0x2C, BUFFER_Q sco_q @0x3C. */
typedef struct uusb_cb_t {
    s32 fd;              /* 0x0 */
    u8 pad4[0x24];
    u8 at_0x28;
    u8 state;            /* 0x29 */
    u8 pad2A[2];
    BUFFER_Q acl_q;      /* 0x2C */
    u8 pad38[4];
    BUFFER_Q sco_q;      /* 0x3C */
} uusb_cb_t;

extern uusb_cb_t lbl_803BD1E0;
extern OSAlarm lbl_803C0A20;
extern void uusb_CloseDeviceCB(void);
extern u8 lbl_8055DC51;
extern s32 IUSB_CloseDeviceAsync(s32 fd, void (*callback)(void), void *arg);
typedef enum {
    USB_IOCTLV_CTRLMSG,
    USB_IOCTLV_BLKMSG,
    USB_IOCTLV_INTRMSG
} USBIoctl;
#pragma use_lmw_stmw off
extern void DCInvalidateRange(const void* buf, u32 len);
extern s32 __IntrBlkMsgInt(s32 fd, u32 endpoint, u32 length, void* buffer, s32 ioctl, void (*callback)(void), void* callbackArg, s32 async);
void fn_80070758(void) {
    fn_8009B0E0();
    fn_8006EBAC();
    lbl_803BD1E0.state = 5;
    lbl_803BD1E0.at_0x28 = 0;
    lbl_8055DC51 = 0;
    fn_8006EB88();
}

extern void fn_80070820(void);
void fn_8007079C(u16 *arg0, u16 arg1) {
    *arg0 = arg1;
    if (lbl_8055DC68 != NULL) {
        ((void (*)(void *))(*(u32 *)((u8 *)lbl_8055DC68 + 0xC)))(arg0);
    } else {
        GKI_freebuf(arg0);
    }
}

void bte_hcisu_task(void) {
    if (lbl_8055DC68 != NULL) {
        if (lbl_8055DC68->init != NULL) {
            lbl_8055DC68->init(2, 1, 0x800);
        }

        if (lbl_8055DC68->open != NULL) {
            lbl_8055DC68->open(lbl_8055DC6C);
        }
    }
}

extern u32 fn_8009B0E0(void);
void fn_80070820(void) {
    if (lbl_8055DC68 != NULL && lbl_8055DC68->close != NULL) {
        ((void (*)(void))lbl_8055DC68->close)();
    }
}

void fn_80070844(void *p_msg) {
    GKI_send_msg(2, 0, p_msg);
}

void fn_80070854(void) {
    RFCOMM_Init();
    GAP_Init();
    HID_DevInit();
    fn_800869CC();
}

void LogMsg(UINT32 trace_set_mask, const char *fmt_str, ...) {
    va_list list;
    va_start(list, fmt_str);
    vsprintf(lbl_803BF240, fmt_str, list);
    va_end(list);

    sprintf(lbl_803BF240, lbl_80559040, lbl_803BF240);
    OSReport(lbl_803BF240);
}

void fn_8007093C(u32 code, void *msg) {
    if (lbl_8055DC70 == 0) {
        LogMsg(code, msg);
    }
}

void fn_80070954(u32 code, void *msg, u16 param) {
    if (lbl_8055DC70 == 0) {
        LogMsg(code, msg);
    }
}

void fn_8007096C(u32 code, void *msg, u16 param1, u16 param2) {
    if (lbl_8055DC70 == 0) {
        LogMsg(code, msg);
    }
}

void fn_80070984(u32 code, void *msg) {
    if (lbl_8055DC70 == 0) {
        LogMsg(code, msg);
    }
}

void fn_8007099C(u32 code, void *msg) {
    if (lbl_8055DC70 == 0) {
        LogMsg(code, msg);
    }
}

void fn_800709B4(u32 code, void *msg) {
    if (lbl_8055DC70 == 0) {
        LogMsg(code, msg);
    }
}

void fn_800709CC(u32 code, void *msg, s32 param1, s32 param2, u16 param3, u16 param4, u8 param5, u16 param6) {
    if (lbl_8055DC70 == 0) {
        LogMsg(code, msg);
    }
}

void fn_800709E4(void) {
    OSSwitchFiber(btu_task_msg_handler, (u8 *)&lbl_803BFA20 + 0x1000);
}

void fn_80070AF0(s32 arg0) {
    lbl_8055DC74 = arg0;
    OSCancelAlarm(&lbl_803C0A20);
    fn_80070820();
    GKI_shutdown();
}

void fn_80070B54(void) {
    lbl_80559050 = 1;
    lbl_80559054 = 1;
    lbl_8055DC78 = 0;
    lbl_8055DC7C = 0;
    fn_8008251C();
    fn_80070854();
    bta_sys_init();
}

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
void btu_task_msg_handler(void) {
    extern unsigned char lbl_803C0A50[];
    UINT32 event;
    TIMER_LIST_ENT *timer;
    BT_HDR *msg;
    UINT16 events;
    UINT8 j;
    UINT8 i;
    int done = 0;
    int handled;
    void (*timer_callback)(TIMER_LIST_ENT *);
    unsigned char *timer_reg;
    int timer_handled;
    extern void l2c_rcv_acl_data(BT_HDR *);
    extern void l2c_link_segments_xmitted(BT_HDR *);
    extern void btu_hcif_process_event(BT_HDR *);
    extern int btu_hcif_send_cmd();
    extern void l2c_process_timeout(void *);
    extern void btu_hcif_cmd_timeout(void);
    extern void hidh_proc_repage_timeout(TIMER_LIST_ENT *);
    extern void bta_sys_event(BT_HDR *);
    extern void fn_8007DEF4(void *);
    extern void fn_8007C794(void);
    extern void fn_8007AD38(void);
    extern void fn_80095518(void *);
    extern void fn_8007141C(void);
    extern void sdp_conn_timeout(tCONN_CB *);
    OSGetTime();
    lbl_8055DC78++;
    fn_8006EBAC();
    if (lbl_80559054) {
        lbl_80559054 = 0;
        lbl_80559050 = 1;
    } else {
        lbl_80559050++;
        fn_8006EB88();
        return;
    }
    fn_8006EB88();
    events = 5;
    if ((UINT32)lbl_8055DC78 > (UINT32)(lbl_8055DC7C + 500)) {
        lbl_8055DC7C = lbl_8055DC78;
        events |= 0x30;
    }
    while (!done) {
        done = 1;
        if (events & 1) {
            while ((msg = GKI_read_mbox(0)) != 0) {
                done = 0;
                event = msg->event & 0xFF00;
                switch (event) {
                case 0x1100: l2c_rcv_acl_data(msg); break;
                case 0x1900: l2c_link_segments_xmitted(msg); break;
                case 0x1200: fn_8007DEF4(msg); break;
                case 0x1000: btu_hcif_process_event(msg); GKI_freebuf(msg); break;
                case 0x1600: btu_hcif_send_cmd(msg); break;
                default:
                    for (i = 0, handled = 0; !handled && i < 6; i++) {
                        unsigned char *reg = lbl_803C0A50 + 0x10 + i * 8;
                        void (*callback)(BT_HDR *) = *(void (**)(BT_HDR *))(reg + 4);
                        if (callback && event == *(UINT16 *)reg) {
                            if (callback) {
                                callback(msg);
                                handled = 1;
                            }
                        }
                    }
                    if (!handled) GKI_freebuf(msg);
                    break;
                }
            }
        }
        if (events & 0x10) {
            GKI_update_timer_list((TIMER_LIST_Q *)(lbl_803C0A50 + 0x40), 1);
            events &= ~0x10;
            while ((timer = *(TIMER_LIST_ENT **)(lbl_803C0A50 + 0x40)) != 0 && timer->ticks == 0) {
                done = 0;
                GKI_remove_from_timer_list((TIMER_LIST_Q *)(lbl_803C0A50 + 0x40), timer);
                switch (timer->event) {
                case 1: btm_dev_timeout(timer); break;
                case 9: btm_acl_timeout(timer); break;
                case 2: case 3: case 4: l2c_process_timeout(timer); break;
                case 5: sdp_conn_timeout((tCONN_CB *)timer->param); break;
                case 10: fn_8007C794(); break;
                case 8: fn_8007AD38(); break;
                case 11: case 12: fn_80095518(timer); break;
                case 60: btu_hcif_cmd_timeout(); break;
                case 66: hidh_proc_repage_timeout(timer); break;
                case 22: ((void (*)(TIMER_LIST_ENT *))timer->param)(timer); break;
                default:
                    for (j = 0, timer_handled = 0; !timer_handled && j < 2; j++) {
                        timer_reg = lbl_803C0A50 + j * 8;
                        timer_callback = *(void (**)(TIMER_LIST_ENT *))(timer_reg + 4);
                        if (timer_callback && *(TIMER_LIST_ENT **)timer_reg == timer) {
                            timer_callback(timer);
                            timer_handled = 1;
                        }
                    }
                    break;
                }
            }
        }
        if (events & 4) {
            while ((msg = GKI_read_mbox(2)) != 0) {
                done = 0;
                bta_sys_event(msg);
            }
        }
        if (events & 0x20) {
            events &= ~0x20;
            fn_8007141C();
        }
        if (events & 0x8000) break;
    }
    lbl_80559054 = 1;
}
#pragma pop

extern unsigned char lbl_803C0A50[];
extern unsigned char lbl_803C0AD8[];
void fn_80070F90(void *arg0) {
    GKI_remove_from_timer_list((void *)(lbl_803C0A50 + 0x40), arg0);
}

extern void (*lbl_803C0AD8_callback)(void);
void fn_80070FA4(void *arg0, const void *arg1) {
    const unsigned char *src = (const unsigned char *)arg1;
    unsigned char *dst = (unsigned char *)arg0;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
}

s32 bdcmp(u8 *arg0, u8 *arg1) {
    u8 *p0;
    u8 *p1;
    if (arg0[0] != arg1[0]) return -1;
    if (arg0[1] != arg1[1]) return -1;
    p0 = arg0;
    p1 = arg1;
    p0 += 2;
    p1 += 2;
    if (p0[0] != p1[0]) return -1;
    if (p0[1] != p1[1]) return -1;
    if (p0[2] != p1[2]) return -1;
    if (p0[3] == p1[3]) {
        return 0;
    } else {
        return -1;
    }
}

void fn_80071078(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x80) = arg0; }

void fn_80071088(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x88) = arg0; }

void fn_80071098(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x84) = arg0; }

typedef void (*tConnOpenCb)(u8, u8, u16);
void bta_sys_conn_open(s32 arg0, s32 arg1, s32 arg2) {
    typedef void (*tConnOpenCb2)(s32, s32, s32, s32);
    tConnOpenCb2 *callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x80 / 4] != 0) callbacks[0x80 / 4](0, arg0, arg1, arg2);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x84 / 4] != 0) callbacks[0x84 / 4](0, arg0, arg1, arg2);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x88 / 4] != 0) callbacks[0x88 / 4](0, arg0, arg1, arg2);
}

void bta_sys_conn_open_8007116C(s32 arg0, s32 arg1, s32 arg2) {
    typedef void (*tConnOpenCb2)(s32, s32, s32, s32);
    tConnOpenCb2 *callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x80 / 4] != 0) callbacks[0x80 / 4](1, arg0, arg1, arg2);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x84 / 4] != 0) callbacks[0x84 / 4](1, arg0, arg1, arg2);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x88 / 4] != 0) callbacks[0x88 / 4](1, arg0, arg1, arg2);
}

void fn_80071230(void *arg0, void *arg1, void *arg2) {
    void (*callback)(int, void *, void *, void *) =
        *(void (**)(int, void *, void *, void *))(lbl_803C0AD8 + 0x84);
    if (callback != 0)
        callback(5, arg0, arg1, arg2);
}

void fn_80071264(void *a, void *b, void *c) {
    extern u8 lbl_803C0AD8[];
    void (*callback)(s32, void *, void *, void *) = *(void (**)(s32, void *, void *, void *))(lbl_803C0AD8 + 0x84);
    if (callback != 0) callback(6, a, b, c);
}

void fn_80071298(void *a, void *b, void *c) {
    extern u8 lbl_803C0AD8[];
    void (*callback)(s32, void *, void *, void *) = *(void (**)(s32, void *, void *, void *))(lbl_803C0AD8 + 0x84);
    if (callback != 0) callback(7, a, b, c);
}

void fn_8007141C(void) {
    if (lbl_803C0AD8[0x7C] == 0) {
        ptim_timer_update((tPTIM_CB *)(lbl_803C0AD8 + 0x68));
    }
}

void fn_8007143C(u32 index, u32 value) {
    ((u32 *)lbl_803C0AD8)[index & 0xFF] = value;
}

void fn_80071450(void *arg0) {
    GKI_send_msg(lbl_803C0AD8[0x7D], lbl_80559038[2], arg0);
}

void fn_8007148C(s32 arg0) {
    fn_800716B0((void **)((u8 *)&lbl_803C0AD8 + 0x68), arg0, &lbl_803C0AD8);
}

void fn_8007146C(s32 arg0, u16 arg1, s32 arg2) {
    ptim_start_timer((tPTIM_CB *)((u8 *)&lbl_803C0AD8 + 0x68), (TIMER_LIST_ENT *)arg0, arg1, arg2);
}

void fn_80072C38(void) {
    BTM_CancelRemoteDeviceName();
}

extern int strncpy(char *, const char *, unsigned int);
extern u32 lbl_802EE9C0[];
u8 bta_dm_authorize_cback(const void *bd_addr, const void *dev_class, const char *bd_name,
                         u8 *service_name, u8 service_id, int is_originator) {
    u8 sec_event[0x110];
    u8 index = 1;
    u32 (*callback)(u32, void *);

    fn_80070FA4(sec_event + 8, bd_addr);
    strncpy((char *)sec_event + 0x0E, bd_name, 0x20);
    while (index < 0x18) {
        if (lbl_802EE9C0[index] == service_id) {
            sec_event[0xFE] = index;
            break;
        }
        index++;
    }
    callback = *(u32 (**)(u32, void *))(lbl_803C0C14 + 0x50);
    if (callback != 0 && index <= 0x17) {
        callback(4, sec_event + 8);
        return 1;
    }
    return 0xB;
}

void bta_dm_pinname_cback(u8 *arg0) {
    u8 local[0x108];
    u16 len;
    u32 copy_len;
    u8 *dst;
    const u8 *src;
    void (*callback)(int, void *, void *);

    fn_80070FA4(local, lbl_803C0C14 + 0xF8);
    local[0xFE] = lbl_803C0C14[0xFE];
    local[0xFF] = lbl_803C0C14[0xFF];
    local[0x100] = lbl_803C0C14[0x100];
    if (arg0 != 0 && *(u16 *)arg0 == 0) {
        len = *(u16 *)(arg0 + 2);
        dst = local + 6;
        src = arg0 + 4;
        copy_len = 0x20;
        if (len < 0x20) copy_len = len;
        memcpy(dst, src, copy_len);
        local[0x26] = 0;
    } else {
        local[6] = 0;
    }
    callback = *(void (**)(int, void *, void *))(lbl_803C0C14 + 0x50);
    callback(2, local, lbl_803C0C14);
}

s32 fn_80072EF4(void) { return 0xB; }

void fn_8007301C(void *arg0) {
    void (**callback)(s32, void *);
    callback = (void (**)(s32, void *))(lbl_803C0C14 + 0x50);
    if (*callback != 0) (*callback)(0, arg0);
}

void fn_80073044(u8 *arg0) {
    if (arg0[0xC] != 0) {
        lbl_803C0C14[0x6C] = arg0[8];
        *(u16 *)(lbl_803C0C14 + 0x70) = *(u16 *)(arg0 + 0xA);
        bta_dm_signal_strength_timer_cback(0);
    } else {
        fn_8007148C((s32)(lbl_803C0C14 + 0x54));
    }
}

extern void fn_80070FA4(void *, const void *);
extern void *GKI_getbuf(unsigned short);
void fn_80073464(void) {
    ((void (**)(int, int)) (lbl_803C0C14 + 0x50))[0](1, 0);
}

void bta_dm_rssi_cback(unsigned char *arg) {
    unsigned char sp[8];
    if (arg[0] == 0) {
        fn_80070FA4(sp, arg + 3);
        sp[6] = 1;
        sp[7] = arg[2];
        ((void (**)(int, void *)) (lbl_803C0C14 + 0x50))[0](7, sp);
    }
}

void bta_dm_link_quality_cback(unsigned char *arg) {
    unsigned char sp[9];
    if (arg[0] == 0) {
        fn_80070FA4(sp, arg + 3);
        sp[6] = 2;
        sp[8] = arg[2];
        ((void (**)(int, void *)) (lbl_803C0C14 + 0x50))[0](7, sp);
    }
}

void bta_dm_keep_acl(void *arg0) {
    extern u8 lbl_80560D48[];
    u16 timeout = *(u16 *)((u8 *)arg0 + 6);
    lbl_803C0C14[0x101] = timeout;
    if ((u8)timeout != 0) {
        L2CA_SetIdleTimeoutByBdAddr(lbl_80560D48, 0xFFFF);
        L2CA_SetIdleTimeout(0, 0xFFFF, TRUE);
    } else {
        L2CA_SetIdleTimeoutByBdAddr(lbl_80560D48, 2);
        L2CA_SetIdleTimeout(0, 2, TRUE);
    }
}

void fn_80073A00(void) {
    ((void (**)(int, int)) (lbl_803C0C14 + 0x50))[0](1, 0);
}

void fn_80073A1C(void) {

}

s32 BTA_EnableBluetooth(void *arg0) {
    void *buf;
    extern u32 lbl_80560D18;
    extern u32 lbl_80560D20;
    memset(lbl_803C0C14, 0, 0x104);
    fn_8006EAD0();
    fn_8007143C(1, (u32)&lbl_80560D18);
    fn_8007143C(2, (u32)&lbl_80560D20);
    fn_8006EAD4();
    buf = GKI_getbuf(0xC);
    if (buf != 0) {
        *(u16 *)buf = 0x100;
        *(void **)((char *)buf + 8) = arg0;
        fn_80071450(buf);
        return 0;
    }
    return 1;
}

void fn_80073AF8(void) {
    void *buf = GKI_getbuf(8);
    if (buf != 0) {
        *(u16 *)buf = 0x101;
        fn_80071450(buf);
    }
}

u8 fn_80079514(void);
u8 fn_80073B30(void) {
    u8 result;
    fn_8006EAD0();
    result = fn_80079514();
    fn_8006EAD4();
    return result;
}

void BTA_DmSetDeviceName(char *name) {
    void *buf = GKI_getbuf(0x28);
    if (buf != 0) {
        *(u16 *)buf = 0x102;
        strncpy((char *)buf + 8, name, 0x20);
        fn_80071450(buf);
    }
}

void BTA_DmSearch(u8 *services, u32 duration, u32 mode) {
    u8 *buf = GKI_getbuf(0x1C);
    if (buf != 0) {
        *(u16 *)buf = 0x200;
        memcpy(buf + 8, services, 0xA);
        *(u32 *)(buf + 0x14) = duration;
        *(u32 *)(buf + 0x18) = mode;
        fn_80071450(buf);
    }
}

void fn_80073CA8(void) {
    u16 *buf = GKI_getbuf(8);
    if (buf != 0) {
        *buf = 0x201;
        fn_80071450(buf);
    }
}

void BTA_DmPinReply(u8 *bd_addr, u8 accept, u8 pin_len, u8 *pin_code) {
    u8 *buf = GKI_getbuf(0x20);
    if (buf != 0) {
        *(u16 *)buf = 0x107;
        fn_80070FA4(buf + 8, bd_addr);
        buf[0xE] = accept;
        if (accept != 0) {
            buf[0xF] = pin_len;
            memcpy(buf + 0x10, pin_code, pin_len);
        }
        fn_80071450(buf);
    }
}

u8 fn_80073E5C(u8 *arg0) {
    u8 result;
    fn_8006EAD0();
    result = BTM_SecDeleteDevice(arg0);
    fn_8006EAD4();
    return result == 0;
}

void fn_80073EA4(void) {
    s16 *buf;

    buf = (s16 *)GKI_getbuf(8);
    if (buf != 0) {
        *buf = 0x10C;
        fn_80071450(buf);
    }
}

s32 bta_dm_sm_execute(BT_HDR *p_msg) {
    extern u8 lbl_802EEA38[];
    extern u8 lbl_802EEA6C[];
    typedef void (*tAction)(BT_HDR *);
    u8 *table = lbl_802EEA6C;
    s32 i = 0;
    u16 event;
    u8 action;

loop:
    event = p_msg->event;
    action = table[i + (((event & 0xFF) * 4) - (event & 0xFF))];
    if (action != 0xD) {
        ((tAction *)lbl_802EEA38)[action](p_msg);
        i++;
        if (i < 2)
            goto loop;
    }
    return 1;
}

BOOLEAN bta_dm_search_sm_execute(BT_HDR *p_msg) {
    extern u8 lbl_802EEB50[];
    extern u8 lbl_802EEA98[];
    extern u8 lbl_803C0B98[];
    u8 (*state_table)[3];
    u8 action;
    int i;

    state_table = (u8 (*)[3])*(u32 *)(lbl_802EEB50 + *(u16 *)(lbl_803C0B98 + 0x18) * 4);
    *(u16 *)(lbl_803C0B98 + 0x18) = state_table[p_msg->event & 0xFF][2];
    for (i = 0; i < 2; i++) {
        action = state_table[p_msg->event & 0xFF][i];
        if (action != 0x12) {
            ((void (*)(BT_HDR *))*(u32 *)(lbl_802EEA98 + action * 4))(p_msg);
        } else {
            break;
        }
    }
    return TRUE;
}

void fn_800740A4(void) {
    BTM_PmRegister(4, lbl_803C0C14 + 0x95, 0);
}

void bta_dm_pm_btm_cback(void *arg0, s8 arg1, s16 arg2, s8 arg3) {
    u8 *buf = GKI_getbuf(0x14);
    if (buf != 0) {
        *(u16 *)(buf + 0) = 0x109;
        buf[0xE] = arg1;
        *(u16 *)(buf + 0x10) = arg2;
        buf[0x12] = arg3;
        fn_80070FA4(buf + 8, arg0);
        fn_80071450(buf);
    }
}

void fn_80074A4C(s32 arg0) {
    bta_dm_pm_set_mode((u8 *)arg0 + 8, 1);
}

void bta_hh_api_disc_act(void *arg0, void *arg1) {
    u8 handle;
    u8 size;
    if (arg1 != 0) handle = (u8)*(u16 *)((u8 *)arg1 + 6);
    else handle = *((u8 *)arg0 + 0x16);
    size = 6;
    if ((u8)HID_HostCloseDev(handle)) {
        (*(void (**)(int, u8 *))(lbl_803C0D48 + 0x224))(3, &size);
    }
}

void fn_80075AA4(void *arg0) {
    (*(void (**)(int, void *))(lbl_803C0D48 + 0x224))(10, arg0);
}

void BTA_HhEnable(u8 arg0, void *arg1) {
    u8 *buf;
    fn_8006EAD0();
    fn_8007143C(0x17, (u32)&lbl_80560D28);
    fn_8006EAD4();
    buf = GKI_getbuf(0x34);
    if (buf != 0) {
        memset(buf, 0, 0x34);
        *(u16 *)buf = 0x170C;
        *(void **)(buf + 0x30) = arg1;
        buf[8] = arg0;
        fn_80071450(buf);
    }
}

void fn_80076228(void) {
    s16 *ptr = GKI_getbuf(8);
    if (ptr != 0) {
        *ptr = 0x170D;
        fn_80071450(ptr);
    }
}

void BTA_HhClose(s16 arg0) {
    s16 *ptr = GKI_getbuf(8);
    if (ptr != 0) {
        memset(ptr, 0, 8);
        *ptr = 0x1701;
        *(s16 *)((u8 *)ptr + 6) = arg0;
        fn_80071450(ptr);
    }
}

extern char lbl_803156D0[];
void BTA_HhOpen(const u8 *arg0, s8 arg1, s8 arg2) {
    u8 *buf = GKI_getbuf(0x10);
    if (buf != 0) {
        memset(buf, 0, 0x10);
        *(u16 *)buf = 0x1700;
        *(u16 *)(buf + 6) = 0xFF;
        buf[0xE] = arg2;
        buf[0xF] = arg1;
        fn_80070FA4(buf + 8, arg0);
        fn_80071450(buf);
    } else if (lbl_8055DC80 >= 1) {
        fn_8007093C(0x500, lbl_803156D0);
    }
}

void BTA_HhSendData(u8 arg0, void *arg1) {
    u8 *buf = GKI_getbuf(0x14);
    if (buf != 0) {
        memset(buf, 0, 0x14);
        *(u16 *)buf = 0x1708;
        *(u16 *)(buf + 6) = arg0;
        buf[8] = 0xA;
        *(u16 *)(buf + 0xC) = 0;
        buf[9] = 2;
        *(void **)(buf + 0x10) = arg1;
        buf[0xA] = 0;
        fn_80071450(buf);
    }
}

void BTA_HhAddDev(const u8 *arg0, u16 arg1, u8 arg2, u8 arg3, const void *arg4) {
    u8 *buf = GKI_getbuf(0x1C);
    if (buf != 0) {
        memset(buf, 0, 0x1C);
        *(u16 *)buf = 0x170A;
        *(u16 *)(buf + 0x10) = 0xB;
        *(u16 *)(buf + 6) = 0xFF;
        *(u16 *)(buf + 0xE) = arg1;
        buf[0x12] = arg2;
        buf[0x13] = arg3;
        memcpy(buf + 0x14, arg4, 8);
        fn_80070FA4(buf + 8, arg0);
        fn_80071450(buf);
    }
}

void BTA_HhRemoveDev(u8 arg0) {
    void *buf = GKI_getbuf(0x1C);
    if (buf != 0) {
        memset(buf, 0, 0x1C);
        *(u16 *)buf = 0x170A;
        *(u16 *)((u8 *)buf + 0x10) = 0xC;
        *(u16 *)((u8 *)buf + 6) = arg0;
        fn_80071450(buf);
    }
}

void BTA_HhGetAclQueueInfo(void) {
    void *buf = GKI_getbuf(8);
    if (buf != 0) {
        memset(buf, 0, 8);
        *(u16 *)buf = 0x170E;
        fn_80071450(buf);
    }
}

extern char lbl_80315700[];
extern void *jumptable_803159A0[];
char *bta_hh_evt_code(u32 event) {
    u32 index = event - 0x1700;
    char *base = lbl_80315700;
    switch (index) {
    case 0: return base + 0x108;
    case 1: return base + 0x120;
    case 2: return base + 0x138;
    case 3: return base + 0x14C;
    case 4: return base + 0x164;
    case 5: return base + 0x178;
    case 6: return base + 0x190;
    case 7: return base + 0x1A8;
    case 8: return base + 0x1BC;
    case 9: return base + 0x1D4;
    case 10: return base + 0x1F0;
    case 11: return base + 0x204;
    case 12: return base + 0x21C;
    case 13: return base + 0x238;
    case 14: return base + 0x250;
    case 15: return base + 0x268;
    default: return base + 0x284;
    }
}

extern u8 lbl_803C0F78[];
extern u8 lbl_80317008[];
extern u8 *lbl_80559030;
extern u8 lbl_8055DC80;
extern u8 lbl_803C0D48[];
extern u8 lbl_80315A64[];
extern void *GKI_getbuf(u16);
extern void fn_800716F0(void *);
void bta_hh_add_device_to_list(void *arg0, s8 arg1, s16 arg2, void *arg3, s32 arg4, s32 arg5) {
    if (lbl_8055DC80 >= 5) {
        fn_80070954(0x504, lbl_80315A64, arg4);
    }
    *((u8 *)arg0 + 0x16) = arg1;
    *((u8 *)arg0 + 0x18) = 1;
    *(u16 *)((u8 *)arg0 + 0xE) = arg2;
    *((u8 *)arg0 + 0x13) = arg4;
    *((u8 *)arg0 + 0x15) = arg5;
    if (arg3 != 0) {
        fn_800716F0((u8 *)arg0 + 4);
        if (*(u16 *)arg3 != 0) {
            void *p = GKI_getbuf(*(u16 *)arg3);
            *(void **)((u8 *)arg0 + 4) = p;
            if (p != 0) {
                *(u16 *)arg0 = *(u16 *)arg3;
                memcpy(p, *(void **)((u8 *)arg3 + 4), *(u16 *)arg3);
            }
        }
    }
}

extern u8 *lbl_80559030;
extern u8 lbl_80315A64[];
extern void fn_800716F0(void *);
void fn_80076E70(void) {
    *(u16 *)(lbl_803C0F78 + 0x4C6) = 0x7D00;
    lbl_803C0F78[0x27BF] = 0xFF;
}

void btm_acl_removed(u8 *addr) {
    s32 i;
    u8 *entry;
    void (*callback)(u8 *, u32, u32, u32, u32);

    entry = lbl_803C0F78 + 0x34;
    for (i = 0; i < 4; i++, entry += 0x11C) {
        if (entry[0x119] != 0 && memcmp(entry + 8, addr, 6) == 0)
            break;
    }
    if (i < 4) {
        entry[0x119] = 0;
        callback = *(void (**)(u8 *, u32, u32, u32, u32))(lbl_803C0F78 + 0x4C8);
        if (callback != 0)
            callback(addr, 0, 0, 0, 0);
    }
}

extern void l2c_link_hci_disc_comp(u16, u8);
void btm_acl_device_down(void)
{
    u8 *entry;
    u32 i;
    for (i = 0, entry = lbl_803C0F78 + 0x34; i < 4; i++, entry += 0x11C) {
        if (entry[0x119]) l2c_link_hci_disc_comp(*(u16 *)entry, 3);
    }
}

void fn_800778C8(s16 arg0) {
    *(s16 *)(lbl_803C0F78 + 0x4C4) = arg0;
}

void btm_read_remote_version_complete(u8 *arg0) {
    u8 status;
    u8 *var_r6;
    u16 var_r4;
    s32 var_i;

    status = arg0[0];
    var_r6 = lbl_803C0F78 + 0x34;
    if (status != 0) {
        return;
    }
    var_r4 = arg0[1];
    var_r4 = (var_r4 + (arg0[2] << 8)) & 0xFFFF;
    for (var_i = 0; var_i < 4; var_i++, var_r6 += 0x11C) {
        if (var_r6[0x119] != 0 && *(u16 *)var_r6 == var_r4) {
            var_r6[0x118] = arg0[3];
            *(u16 *)(var_r6 + 0x10A) = arg0[4] + (arg0[5] << 8);
            *(u16 *)(var_r6 + 0x10C) = arg0[6] + (arg0[7] << 8);
            return;
        }
    }
}

void fn_80077C94(s16 arg0) {
    *(s16 *)(lbl_803C0F78 + 0x4C6) = arg0;
}

u16 BTM_GetNumAclLinks(void)
{
    u8 *p = lbl_803C0F78;
    u16 count = 0;
    if (p[0x14D]) count = 1;
    if (p[0x269]) count++;
    if (p[0x385]) count++;
    if (p[0x4A1]) count++;
    return count;
}

u8 fn_80077DD8(void) {
    return lbl_803C0F78[0x27BF];
}

u16 BTM_GetHCIConnHandle(u8 *arg0) {
    u32 var_r31;
    u8 *var_r30;

    var_r31 = 0;
    var_r30 = lbl_803C0F78 + 0x34;
loop:
    if (var_r30[0x119] == 0) {
        goto next;
    }
    switch (memcmp(var_r30 + 8, arg0, 6)) {
    case 0:
        goto found;
    default:
        goto next;
    }
next:
    var_r31++;
    var_r30 += 0x11C;
    if (var_r31 < 4) {
        goto loop;
    }
    var_r30 = 0;
found:
    if (var_r30 != 0) {
        return *(u16 *)var_r30;
    }
    return 0xFFFF;
}

void btm_process_clk_off_comp_evt(u16 arg0, u16 arg1) {
    u8 *base;
    u32 i;

    base = lbl_803C0F78;
    i = 0;
    if (base[0x14D] != 0 && *(u16 *)(base + 0x34) == arg0) goto update;
    i = 1;
    if (base[0x269] != 0 && *(u16 *)(base + 0x150) == arg0) goto update;
    i = 2;
    if (base[0x385] != 0 && *(u16 *)(base + 0x26C) == arg0) goto update;
    i = 3;
    if (base[0x4A1] != 0 && *(u16 *)(base + 0x388) == arg0) goto update;
    i = 4;
update:
    if (i >= 4) return;
    *(u16 *)(lbl_803C0F78 + i * 0x11C + 0x3A) = arg1;
}

s32 fn_80078310(s32 arg0)
{
    if (arg0 == 0) {
        *(s32 *)(lbl_803C0F78 + 0x4C8) = 0;
    } else {
        if (*(s32 *)(lbl_803C0F78 + 0x4C8) != 0)
            return 2;
        *(s32 *)(lbl_803C0F78 + 0x4C8) = arg0;
    }
    return 0;
}

void btm_chg_all_acl_pkt_types(BOOLEAN start) {
    u8 *cb = lbl_803C0F78;
    u8 *p = cb + 0x34;
    s32 i;
    u16 mask, pkt;
    u8 mode, sp8;
    s8 sp14;
    u8 spC[4];
    if (start) {
        for (i = 0; i < 4; i++, p += 0x11C) {
            if (!p[0x119]) continue;
            if (cb[0x27C0] >= 5) fn_80070954(0xD0004, lbl_80315CA0 + 0x38C, *(u16 *)p);
            *(u16 *)(p + 4) = *(u16 *)(p + 2);
            pkt = 0x18;
            mode = cb[0x636];
            if (mode >= 3) pkt |= 0x3300;
            mask = *(u16 *)(cb + 0x654);
            pkt &= mask;
            pkt &= 0xCC18;
            if (mode >= 3) pkt |= (u16)((0x18 | 0x3300 | mask) & 0x3306);
            if (cb[0x27C0] >= 4) fn_80070954(0xD0003, lbl_80315CA0 + 0x40, pkt);
            if (btsnd_hcic_change_conn_type(*(u16 *)p, pkt)) *(u16 *)(p + 2) = pkt;
        }
    } else {
        for (i = 0; i < 4; i++, p += 0x11C) {
            if (!p[0x119] || !*(u16 *)(p + 4) || BTM_ReadPowerMode(p + 8, &sp8)) continue;
            if (sp8 == 2) {
                if (cb[0x27C0] >= 5) fn_80070954(0xD0004, lbl_80315CA0 + 0x3BC, *(u16 *)p);
                sp14 = 0;
                BTM_SetPowerMode(0x80, p + 8, (void *)spC);
            } else {
                if (cb[0x27C0] >= 5) fn_8007096C(0xD0004, lbl_80315CA0 + 0x3EC, *(u16 *)p, *(u16 *)(p + 2));
                pkt = *(u16 *)(p + 4);
                mask = *(u16 *)(cb + 0x654);
                mode = cb[0x636];
                pkt &= mask;
                pkt &= 0xCC18;
                if (mode >= 3) pkt |= (u16)((*(u16 *)(p + 4) | mask) & 0x3306);
                if (cb[0x27C0] >= 4) fn_80070954(0xD0003, lbl_80315CA0 + 0x40, pkt);
                if (btsnd_hcic_change_conn_type(*(u16 *)p, pkt)) *(u16 *)(p + 2) = pkt;
                *(u16 *)(p + 4) = 0;
            }
        }
    }
}

BOOLEAN BTM_SecDeleteDevice(BD_ADDR bd_addr) {
    s32 i = 0;
    u8 *entry = lbl_803C0F78 + 0x1F30;
    while (i < 16) {
        if ((entry[0x76] & 0x80) && memcmp(entry + 0x1C, bd_addr, 6) == 0)
            break;
        i++;
        entry += 0x88;
    }
    if (i == 16) return FALSE;
    entry[0x76] = 0;
    BTM_DeleteStoredLinkKey(bd_addr, 0);
    return TRUE;
}

char *BTM_SecReadDevName(BD_ADDR bd_addr) {
    u8 *entry;
    s32 i;
    char *name;
    i = 0;
    name = 0;
    entry = lbl_803C0F78 + 0x1F30;
    do {
        if ((entry[0x76] & 0x80) && memcmp(entry + 0x1C, bd_addr, 6) == 0) {
            name = (char *)entry + 0x35;
            break;
        }
        i++;
        entry += 0x88;
    } while (i < 16);
    return name;
}

tBTM_SEC_DEV_REC *btm_find_dev_by_handle(UINT16 handle) {
    u8 *entry = lbl_803C0F78 + 0x1F30;
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++, entry += 0x88) {
            if ((entry[0x76] & 0x80) && *(u16 *)(entry + 0x18) == handle) return (tBTM_SEC_DEV_REC *)entry;
        }
    }
    return 0;
}

tBTM_SEC_DEV_REC *btm_find_dev(BD_ADDR bd_addr) {
    u8 *entry;
    s32 i;
    entry = lbl_803C0F78 + 0x1F30;
    i = 0;
    do {
        if ((entry[0x76] & 0x80) && memcmp(entry + 0x1C, bd_addr, 6) == 0) {
            return (tBTM_SEC_DEV_REC *)entry;
        }
        i++;
        entry += 0x88;
    } while (i < 16);
    return 0;
}

void btm_db_reset(void) {
    u8 param = 12;
    btm_inq_db_reset();
    btm_discovery_db_reset();
    if (*(void (**)(void *))(lbl_803C0F78 + 0x5A8)) {
        void (*callback)(void *) = *(void (**)(void *))(lbl_803C0F78 + 0x5A8);
        *(void (**)(void *))(lbl_803C0F78 + 0x5A8) = NULL;
        if (callback) callback(NULL);
    }
    if (*(void (**)(void *))(lbl_803C0F78 + 0x5C4)) {
        void (*callback)(void *) = *(void (**)(void *))(lbl_803C0F78 + 0x5C4);
        *(void (**)(void *))(lbl_803C0F78 + 0x5C4) = NULL;
        if (callback) callback(&param);
    }
    if (*(void (**)(void *))(lbl_803C0F78 + 0x5E0)) {
        void (*callback)(void *) = *(void (**)(void *))(lbl_803C0F78 + 0x5E0);
        *(void (**)(void *))(lbl_803C0F78 + 0x5E0) = NULL;
        if (callback) callback(&param);
    }
}

void BTM_DeviceReset(void (*arg0)(void *)) {
    register u8 zero = 0;
    if (*(u32 *)(lbl_803C0F78 + 0x58C) != 0 &&
        *(u32 *)(lbl_803C0F78 + 0x58C) != (u32)arg0)
        return;
    btm_acl_device_down();
    btm_db_reset();
    *(volatile u32 *)(lbl_803C0F78 + 0x58C) = (u32)arg0;
    *(volatile u8 *)(lbl_803C0F78 + 0x64E) = zero;
    *(volatile u8 *)(lbl_803C0F78 + 0x64F) = 5;
    btu_start_timer(lbl_803C0F78 + 0x574, 1, 4, 0);
    ((void (*)(void))btsnd_hcic_reset)();
    if (*(void (**)(void *))(lbl_803C0F78 + 0x568) != NULL)
        (*(void (**)(void *))(lbl_803C0F78 + 0x568))((void *)1);
}

void BTM_SendHciReset(void (*arg0)(void)) {
    u32 zero = 0;
    if (*(u32 *)(lbl_803C0F78 + 0x58C) != 0 &&
        *(u32 *)(lbl_803C0F78 + 0x58C) != (u32)arg0 &&
        *(u32 *)(lbl_803C0F78 + 0x620) != (u32)arg0)
        return;
    btm_acl_device_down();
    btm_db_reset();
    *(volatile u32 *)(lbl_803C0F78 + 0x620) = (u32)arg0;
    *(volatile u8 *)(lbl_803C0F78 + 0x64E) = zero;
    *(volatile u8 *)(lbl_803C0F78 + 0x64F) = 5;
    btu_start_timer(lbl_803C0F78 + 0x574, 1, 4, zero);
    ((void (*)(void))btsnd_hcic_reset)();
    if (*(void (**)(void *))(lbl_803C0F78 + 0x568) != NULL)
        (*(void (**)(void *))(lbl_803C0F78 + 0x568))((void *)1);
}

u8 fn_80079514(void) {
    return (u8)((lbl_803C0F78[0x64E] - 5) == 0);
}

void btm_read_local_version_complete(UINT8 *p, UINT16 evt_len) {
    if (p[0] == 0) {
        lbl_803C0F78[0x636] = p[1];
        *(u16 *)(lbl_803C0F78 + 0x638) = p[2] + (p[3] << 8);
        lbl_803C0F78[0x63A] = p[4];
        *(u16 *)(lbl_803C0F78 + 0x63C) = p[5] + (p[6] << 8);
        *(u16 *)(lbl_803C0F78 + 0x63E) = p[7] + (p[8] << 8);
    }
    lbl_803C0F78[0x64E] = 4;
    lbl_803C0F78[0x64F] = 4;
    btu_start_timer(lbl_803C0F78 + 0x574, 1, 1);
    btsnd_hcic_reset_800857CC();
}

tBTM_STATUS BTM_SetLocalDeviceName(char *p_name) {
    void *buf;
    u8 *name;

    if (p_name == NULL) return 5;
    name = lbl_803C0F78;
    if (name[0x64E] <= 1) return 0xC;
    buf = GKI_getpoolbuf(2);
    if (buf != NULL) {
        if ((void *)name != (void *)p_name) {
            memset(name, 0, 0x20);
            strncpy((char *)name, p_name, 0x1F);
        }
        ((BOOLEAN (*)(void *, BD_NAME))btsnd_hcic_change_name)(buf, name);
        return 1;
    }
    return 3;
}

void btm_read_local_name_complete(UINT8 *p, UINT16 evt_len) {
    tBTM_CMPL_CB *callback = *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5A8);
    fn_80070F90(lbl_803C0F78 + 0x590);
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5A8) = NULL;
    if (callback != NULL) {
        if (p[0] == 0) callback(p + 1);
        else callback(NULL);
    }
}

tBTM_STATUS fn_8007A240(void (*arg0)(void *, void *)) {
    if (arg0 != 0) arg0(lbl_803C0F78 + 0x630, lbl_803C0F78);
    return 0;
}

void fn_8007A280(u8 *arg0) {
    u8 *base;
    if (arg0[0] != 0) return;
    base = lbl_803C0F78;
    base[0x635] = arg0[1];
    base[0x634] = arg0[2];
    base[0x633] = arg0[3];
    base[0x632] = arg0[4];
    base[0x631] = arg0[5];
    base[0x630] = arg0[6];
}

tBTM_STATUS fn_8007A2C8(u16 *arg0) {
    register u16 *base = (u16 *)lbl_803C0F78;
    if (((u8 *)base)[0x64e] < 4) return 0xc;
    arg0[0] = base[0x31b];
    arg0[1] = base[0x31c];
    arg0[2] = base[0x31d];
    arg0[3] = base[0x31e];
    arg0[4] = base[0x31f];
    return 0;
}

tBTM_STATUS BTM_SetDeviceClass(DEV_CLASS dev_class) {
    void *buf;
    memcpy(lbl_803C0F78 + 0x648, dev_class, 3);
    if (lbl_803C0F78[0x64e] <= 1) return 0xc;
    buf = GKI_getpoolbuf(2);
    if (buf != 0) {
        fn_80085524(buf, dev_class);
        return 0;
    }
    return 3;
}

void *fn_8007A394(void) { return lbl_803C0F78 + 0x648; }

void *fn_8007A3A4(void) { return lbl_803C0F78 + 0x640; }

s32 fn_8007A3B4(s32 value) { s32 old = *(s32 *)(lbl_803C0F78 + 0x568); *(s32 *)(lbl_803C0F78 + 0x568) = value; return old; }

void btm_vsc_complete(UINT8 *p, UINT16 cc_opcode, UINT16 evt_len, tBTM_CMPL_CB *p_vsc_cplt_cback) {
    u8 packet[0x108];
    u8 *src = p;
    u8 *out = packet + 4;
    tBTM_CMPL_CB *callback = *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x61C);
    lbl_803C0F78[0x650] = 0;
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x61C) = NULL;
    if (callback != NULL) {
        *(u16 *)(packet + 0) = cc_opcode;
        *(u16 *)(packet + 2) = evt_len;
        memcpy(out, src, evt_len);
        callback(packet);
    }
}

extern char lbl_803161E0[];
extern char lbl_80316464[];
s32 fn_8007A534(s32 arg0) {
    if (*(s32 *)(lbl_803C0F78 + 0x56C) != 0 && arg0 != 0)
        return 2;
    *(s32 *)(lbl_803C0F78 + 0x56C) = arg0;
    return 0;
}

extern char lbl_80316220[];
extern void fn_8008534C(void *, u16);
tBTM_STATUS BTM_WritePageTimeout(UINT16 timeout) {
    void *buf;
    if (lbl_803C0F78[0x27c0] >= 4) {
        fn_80070954(0xD0003, lbl_80316220, timeout);
    }
    *(u16 *)(lbl_803C0F78 + 0x64c) = (timeout * 0x271) / 1000;
    buf = GKI_getpoolbuf(2);
    if (buf != NULL) {
        fn_8008534C(buf, timeout);
        return 0;
    }
    return 3;
}

void btm_read_stored_link_key_complete(u8 *p) {
    void (*callback)(u8 *);
    u8 param[6];
    callback = *(void (**)(u8 *))(lbl_803C0F78 + 0x570);
    *(void (**)(u8 *))(lbl_803C0F78 + 0x570) = NULL;
    if (callback != NULL) {
        param[0] = 2;
        param[1] = p[0];
        *(u16 *)(param + 2) = p[1] + (p[2] << 8);
        *(u16 *)(param + 4) = p[3] + (p[4] << 8);
        callback(param);
    }
}

void btm_write_stored_link_key_complete(u8 *p) {
    void (*callback)(u8 *);
    u8 param[3];
    callback = *(void (**)(u8 *))(lbl_803C0F78 + 0x570);
    *(void (**)(u8 *))(lbl_803C0F78 + 0x570) = NULL;
    if (callback != NULL) {
        param[0] = 3;
        param[1] = p[0];
        param[2] = p[1];
        callback(param);
    }
}

void btm_delete_stored_link_key_complete(u8 *p) {
    void (*callback)(u8 *);
    u8 param[4];
    callback = *(void (**)(u8 *))(lbl_803C0F78 + 0x570);
    *(void (**)(u8 *))(lbl_803C0F78 + 0x570) = NULL;
    if (callback != NULL) {
        param[0] = 4;
        param[1] = p[0];
        *(u16 *)(param + 2) = p[1] + (p[2] << 8);
        callback(param);
    }
}

void fn_8007ABE8(void *arg0) {
    void (*callback)(void) = *(void (**)(void))(lbl_803C0F78 + 0x568);
    if (callback != NULL) callback();
}

void fn_8007AD38(void) {

}

tBTM_STATUS BTM_SetInquiryScanType(UINT16 arg0) {
    void *p_buf;
    tBTM_STATUS status;
    if (arg0 != 0 && arg0 != 1) return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x10)) return BTM_MODE_UNSUPPORTED;
    if (arg0 != *(u16 *)(lbl_803C0F78 + 0x16A4)) {
        if ((u8)fn_80079514() != 0) {
            p_buf = GKI_getpoolbuf(2);
            if (p_buf != 0) {
                fn_80085DC4(p_buf, (u8)arg0);
                *(u16 *)(lbl_803C0F78 + 0x16A4) = arg0;
                goto done;
            }
            status = BTM_NO_RESOURCES;
            goto result;
        }
        status = BTM_WRONG_MODE;
        goto result;
    }
done:
    status = BTM_SUCCESS;
result:
    return status;
}

tBTM_STATUS BTM_SetPageScanType(UINT16 arg0) {
    void *p_buf;
    tBTM_STATUS status;
    if (arg0 != 0 && arg0 != 1) return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x20)) return BTM_MODE_UNSUPPORTED;
    if (arg0 != *(u16 *)(lbl_803C0F78 + 0x16A6)) {
        if ((u8)fn_80079514() != 0) {
            p_buf = GKI_getpoolbuf(2);
            if (p_buf != 0) {
                fn_80085E24(p_buf, (u8)arg0);
                *(u16 *)(lbl_803C0F78 + 0x16A6) = arg0;
                goto done;
            }
            status = BTM_NO_RESOURCES;
            goto result;
        }
        status = BTM_WRONG_MODE;
        goto result;
    }
done:
    status = BTM_SUCCESS;
result:
    return status;
}

extern void fn_80085DF4(void *, UINT8);
extern u8 fn_80079514(void);
tBTM_STATUS BTM_SetInquiryMode(UINT8 arg0) {
    void *buf;
    if (arg0 != 0 && arg0 != 1) return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x40)) return BTM_MODE_UNSUPPORTED;
    if (!fn_80079514()) return BTM_WRONG_MODE;
    buf = GKI_getpoolbuf(2);
    if (buf == 0) goto fail;
    fn_80085DF4(buf, arg0);
    goto done;
fail:
    return BTM_NO_RESOURCES;
done:
    return BTM_SUCCESS;
}

u8 fn_8007B340(void) {
    return lbl_803C0F78[0x1848];
}

tBTM_INQ_INFO *BTM_InqDbFirst(void) {
    u8 *entry = lbl_803C0F78 + 0x16E4;
    s32 i;
    for (i = 0; i < 2; i++, entry += 0xA8) {
        if (entry[0x1A]) return (tBTM_INQ_INFO *)(entry + 8);
        if (entry[0x36]) return (tBTM_INQ_INFO *)(entry + 0x24);
        if (entry[0x52]) return (tBTM_INQ_INFO *)(entry + 0x40);
        if (entry[0x6E]) return (tBTM_INQ_INFO *)(entry + 0x5C);
        if (entry[0x8A]) return (tBTM_INQ_INFO *)(entry + 0x78);
        if (entry[0xA6]) return (tBTM_INQ_INFO *)(entry + 0x94);
    }
    return 0;
}

void fn_8007BC88(void) {

}

#pragma push
#pragma use_lmw_stmw off
tBTM_STATUS btm_initiate_rem_name(BD_ADDR remote_bda, tBTM_INQ_INFO *p_cur, UINT8 origin, UINT32 timeout, tBTM_CMPL_CB *p_cb) {
    u8 *base = lbl_803C0F78;
    u8 active;
    u8 start = 1;
    u8 result = 1;
    u8 status = 1;
    if (!fn_80079514()) return 6;
    active = base[0x16AE];
    if (active & origin) return 2;
    if (origin == 1) {
        if (active != 0) {
            if (memcmp(remote_bda, base + 0x16A8, 6) != 0) return 2;
            start = 0;
        }
        *(tBTM_CMPL_CB **)(base + 0x167C) = p_cb;
    } else if (active != 0) {
        return 2;
    }
    if (start) {
        memcpy(base + 0x16A8, remote_bda, 6);
        btu_start_timer(base + 0x1680, 0xA, timeout);
        if (p_cur != 0) {
            result = btsnd_hcic_rmt_name_req(remote_bda, ((u8 *)p_cur)[0xB], ((u8 *)p_cur)[0xD], *(u16 *)p_cur | 0x8000);
        } else {
            result = btsnd_hcic_rmt_name_req(remote_bda, 1, 0, 0);
        }
    }
    if (result) base[0x16AE] |= origin;
    else status = 3;
    return status;
}
#pragma pop

void fn_8007C794(void) {
    btm_process_remote_name(0, 0, 0, 0x1F);
    btm_sec_rmt_name_request_complete(0, 0, 0x1F);
}

tBTM_STATUS BTM_ReadPowerMode(BD_ADDR remote_bda, tBTM_PM_MODE *p_mode) {
    u8 i;
    u8 *p = lbl_803C0F78 + 0x34;
    for (i = 0; i < 4; i++, p += (u32)0x11C) {
        if (p[0x119] && memcmp(p + 8, remote_bda, 6) == 0) break;
    }
    if ((s32)i == 4) return BTM_UNKNOWN_ADDR;
    *p_mode = lbl_803C0F78[0x4EC + i * (s32)0x22];
    return BTM_SUCCESS;
}

void btm_pm_sm_alloc(u8 index) {
    u8 *entry;
    entry = lbl_803C0F78 + 0x4cc + index * 0x22;
    memset(entry, 0, 0x22);
    entry[0x20] = 0;
}

void btm_pm_proc_cmd_status(UINT8 status) {
    u8 *base = lbl_803C0F78;
    u8 state = base[0x564];
    u8 index;
    u8 result;
    u8 *entry;
    if (state >= 4) return;
    if (status == 0) {
        result = 4;
        base[state * 0x22 + 0x4EC] = result;
    } else {
        result = 5;
    }
    index = base[0x565];
    if (index != 0x80) {
        entry = base + (index << 3);
        if (entry[0x558] & 2) {
            void (*callback)(void *, s32, s32) = *(void (**)(void *, s32, s32))(entry + 0x554);
            callback(base + state * 0x11C + 0x3C, 0, status);
        }
    }
    base[0x564] = 4;
    (void)result;
}

void fn_8007D4C4(void) {
    extern u32 lbl_802EEBF8[];
    u32 *src = lbl_802EEBF8;
    u8 *dst = lbl_803C0F78;
    *(u16 *)(dst + 0x18F6) = 0xFFFF;
    *(u32 *)(dst + 0x18F8) = src[0];
    *(u32 *)(dst + 0x18FC) = src[1];
    *(u32 *)(dst + 0x1900) = src[2];
    *(u32 *)(dst + 0x1904) = src[3];
    dst[0x1909] = 2;
}

tBTM_STATUS BTM_RemoveSco(UINT16 sco_inx) {
    u8 *entry = lbl_803C0F78 + sco_inx * 0x34;
    u16 state;
    if (sco_inx >= 3 || (state = *(u16 *)(entry + 0x185C)) == 0) return 7;
    if (*(u16 *)(entry + 0x185E) == 0xFFFF || state == 6) {
        *(u16 *)(entry + 0x185E) = 0xFFFF;
        *(u16 *)(entry + 0x185C) = 0;
        *(u32 *)(entry + 0x1864) = 0;
        return 0;
    }
    *(u16 *)(entry + 0x185C) = 5;
    if (!btsnd_hcic_disconnect(*(u16 *)(entry + 0x185E), 0x13)) {
        *(u16 *)(entry + 0x185C) = state;
        return 3;
    }
    return 1;
}

void btm_remove_sco_links(BD_ADDR addr) {
    u8 *entry = lbl_803C0F78 + 0x1854;
    u16 i;
    for (i = 0; i < 3; i++, entry += 0x34) {
        if (entry[0xD] && memcmp(entry + 0x28, addr, 6) == 0) {
            BTM_RemoveSco(i);
        }
    }
}

extern u8 lbl_8031A3B0[];
void btm_sco_acl_removed(BD_ADDR addr) {
    u8 *entry;
    u16 i;
    entry = lbl_803C0F78 + 0x1854;
    i = 0;
    for (; i < 3; i++, entry += 0x34) {
        if (*(u16 *)(entry + 8) != 0 &&
            (addr == 0 || (memcmp(entry + 0x28, addr, 6) == 0 && entry[0xD] != 0))) {
            *(u16 *)(entry + 8) = 0;
            *(u32 *)(entry + 0x10) = 0;
            ((void (*)(u16))*(u32 *)(entry + 4))(i);
        }
    }
}

void fn_8007DEF4(void *arg0) {
    GKI_freebuf(arg0);
}

void fn_80071508(u8 arg0) {
    lbl_8055DC80 = arg0;
}

void fn_80071510(void *arg0, s32 arg1, u8 arg2) {
    fn_8006E6E4(arg0);
    ((s32 *)arg0)[3] = arg1;
    ((u8 *)arg0)[0x10] = arg2;
}

void ptim_timer_update(tPTIM_CB *p_cb) {
    TIMER_LIST_ENT *p_entry;
    TIMER_CBACK *p_cback;
    void *p_buf;
    UINT16 event;

    GKI_update_timer_list(&p_cb->timer_queue, p_cb->timer_id);

    p_entry = p_cb->timer_queue.p_first;
    while (p_entry != NULL) {
        if (p_entry->ticks <= 0) {
            GKI_remove_from_timer_list(&p_cb->timer_queue, p_entry);
            p_cback = p_entry->p_cback;
            if (p_cback != NULL) {
                p_cback(p_entry);
            } else {
                event = p_entry->event;
                if (event != 0) {
                    p_buf = GKI_getbuf(8);
                    if (p_buf != NULL) {
                        ((UINT16 *)p_buf)[0] = event;
                        fn_80071450(p_buf);
                    }
                }
            }
            p_entry = p_cb->timer_queue.p_first;
        } else {
            p_entry = p_entry->p_next;
        }
    }

    if (p_cb->timer_queue.p_first == NULL) {
        GKI_stop_timer(p_cb->timer_id);
    }
}

void ptim_start_timer(tPTIM_CB *p_cb, TIMER_LIST_ENT *p_tle, UINT16 type, INT32 timeout) {
    if (p_cb->timer_queue.p_first == NULL) {
        GKI_start_timer(p_cb->timer_id, p_cb->period / 10, TRUE);
    }
    GKI_remove_from_timer_list(&p_cb->timer_queue, p_tle);
    p_tle->event = type;
    p_tle->ticks = timeout;
    GKI_add_to_timer_list(&p_cb->timer_queue, p_tle);
}

void fn_800716F0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        GKI_freebuf(buf);
        *(void **)arg0 = NULL;
    }
}

void bta_dm_disable_timer_cback(void) {
 u8 i;
 if (lbl_8055DC80 >= 4) fn_8007093C(0x503, lbl_80315048);
 if (BTM_GetNumAclLinks() && lbl_803C0C14[0x101] == 0) {
  for (i=0; i<lbl_803C0C14[0x4D]; i++) btm_remove_acl((u8 *)lbl_803C0C14+i*0xB);
 } else {
  lbl_803C0C14[0x72]=0;
  ((void (**)(int,int,void *))(lbl_803C0C14+0x50))[0](1,0,lbl_803C0C14);
 }
}

void fn_800719B0(void *arg0) { BTM_SetLocalDeviceName((char *)arg0 + 8); }

void fn_800719B8(void *arg0) {
    BTM_SetDiscoverability(((u8 *)arg0)[8], 0, 0);
    BTM_SetConnectability(((u8 *)arg0)[9], 0, 0);
}

void bta_dm_bond(void *arg0) {
 u32 sp8[2];
 s32 ptr = fn_8008128C((u8 *)arg0 + 8);
 if (ptr) memcpy(sp8, (void *)ptr, 8); else memset(sp8, 0, 8);
 BTM_SecBond((u8 *)arg0 + 8, ((u8 *)arg0)[0xE], (u8 *)arg0 + 0xF, sp8);
}

void bta_dm_pin_reply(void *arg0) {
 u32 sp8[2];
 s32 ptr = fn_8008128C((u8 *)arg0 + 8);
 if (ptr) memcpy(sp8, (void *)ptr, 8); else memset(sp8, 0, 8);
 if (((u8 *)arg0)[0xE]) {
  BTM_PINCodeReply((u8 *)arg0 + 8, 0, ((u8 *)arg0)[0xF], (u8 *)arg0 + 0x10, sp8);
 } else {
  BTM_PINCodeReply((u8 *)arg0 + 8, 0xB, 0, 0, sp8);
 }
}

void bta_dm_search_cancel(void) {
    BTM_ClearInqDb(0);
    if (((u16 (*)(void))fn_8007B340)() != 0) {
        BTM_CancelInquiry();
        ((void (*)(s32, s32))*(u32 *)lbl_803C0B98)(4, 0);
        {
            void *buf = GKI_getbuf(0x110);
            if (buf != 0) {
                *(u16 *)buf = 0x207;
                fn_80071450(buf);
            }
        }
    } else if (*(s32 *)(lbl_803C0B98 + 8) == 0) {
        BTM_CancelRemoteDeviceName();
    }
}

void bta_dm_disc_rmt_name(void *arg0) {
    void *buf = GKI_getbuf(0x110);
    if (buf != 0) {
        *(u16 *)buf = 0x207;
        fn_80071450(buf);
    }
    *(s32 *)((u8 *)arg0 + 0x108) = 0;
    ((void (*)(s32, void *))*(u32 *)lbl_803C0B98)(2, (u8 *)arg0 + 8);
}

void fn_80072434(void) {
    ((void (*)(u32, u32))*(u32 *)lbl_803C0B98)(3, 0);
}

void bta_dm_disc_result(void *arg0) {
    ((void (*)(u32, void *))*(u32 *)lbl_803C0B98)(2, (u8 *)arg0 + 8);
    {
        void *buf = GKI_getbuf(0x110);
        if (buf != 0) {
            *(u16 *)buf = 0x207;
            fn_80071450(buf);
        }
    }
}

extern void fn_80072524(void);
void bta_dm_search_result(void *arg0) {
    if (*(u32 *)((u8 *)arg0 + 0x108) != 0)
        ((void (*)(u32, void *))*(u32 *)lbl_803C0B98)(2, (u8 *)arg0 + 8);
    if (lbl_803C0B98[0x78] == 0) {
        lbl_803C0B98[0x78] = 0;
        bta_dm_discover_next_device();
    } else {
        lbl_803C0B98[0x79] = 1;
        *(void (**)(void))(lbl_803C0B98 + 0x48) = fn_80072524;
        fn_8007146C((s32)(lbl_803C0B98 + 0x40), 0, 0xBB8);
    }
}

void fn_80072524(void) {
    if (lbl_8055DC80 >= 4)
        fn_8007093C(0x503, lbl_80315048);
    lbl_803C0B98[0x78] = 0;
    bta_dm_discover_next_device();
}

void fn_80072570(void) {
    if (*(void **)(lbl_803C0B98 + 0x14) != 0) {
        GKI_freebuf(*(void **)(lbl_803C0B98 + 0x14));
        *(void **)(lbl_803C0B98 + 0x14) = 0;
    }
}

void fn_800725B4(void *arg0) {
    *(void **)(lbl_803C0B98 + 0x74) = GKI_getbuf(0x1C);
    memcpy(*(void **)(lbl_803C0B98 + 0x74), arg0, 0x1C);
}

void fn_800725FC(void *arg0) {
    *(void **)(lbl_803C0B98 + 0x74) = GKI_getbuf(0x18);
    memcpy(*(void **)(lbl_803C0B98 + 0x74), arg0, 0x18);
}

extern u8 lbl_803C0B98[];
extern void *GKI_getbuf(u16);
void fn_80072644(void) {
    if (*(void **)(lbl_803C0B98 + 0x74) != 0) {
        GKI_freebuf(*(void **)(lbl_803C0B98 + 0x74));
        *(void **)(lbl_803C0B98 + 0x74) = 0;
    }
}

void fn_80072688(void) {
    if (*(void **)(lbl_803C0B98 + 0x74) != 0) {
        fn_80071450(*(void **)(lbl_803C0B98 + 0x74));
        *(void **)(lbl_803C0B98 + 0x74) = 0;
    }
}

void bta_dm_search_cancel_transac_cmpl(void) {
    if (*(void **)(lbl_803C0B98 + 0x14) != 0) {
        GKI_freebuf(*(void **)(lbl_803C0B98 + 0x14));
        *(void **)(lbl_803C0B98 + 0x14) = 0;
    }
    ((void (*)(u32, u32))*(u32 *)lbl_803C0B98)(4, 0);
}

void fn_80072728(void) {
    ((void (*)(u32, u32))*(u32 *)lbl_803C0B98)(4, 0);
}

void fn_800729C0(s16 arg0) {
    void *buf = GKI_getbuf(0xA);
    if (buf != 0) {
        *(u16 *)buf = 0x206;
        *(u16 *)((u8 *)buf + 8) = arg0;
        fn_80071450(buf);
    }
}

void bta_dm_inq_results_cb(u8 *arg0) {
    volatile u8 local[0x108];
    void *info;

    fn_80070FA4((void *)local, arg0 + 2);
    memcpy((void *)(local + 6), arg0 + 8, 3);
    local[9] = arg0[0xE];
    info = BTM_InqDbRead(arg0 + 2);
    if (info != 0) {
        local[10] = 0;
    }
    ((void (*)(u32, void *))*(u32 *)lbl_803C0B98)(0, (void *)local);
    if (info != 0) {
        *((u8 *)info + 0x10) = local[10];
    }
}

void fn_80072A98(void *arg0) {
    void *buf = GKI_getbuf(0x110);
    if (buf != 0) {
        *(u16 *)buf = 0x203;
        *((u8 *)buf + 8) = *((u8 *)arg0 + 1);
        fn_80071450(buf);
    }
}

void fn_80072AE4(u8 *arg0, u8 *arg1, u8 *arg2) {
    strncpy((char *)lbl_803C0B98 + 0x20, (char *)arg2, 0x1F);
    BTM_SecDeleteRmtNameNotifyCallback(fn_80072AE4);
}

void bta_dm_remname_cback(u8 *arg0) {
    void *buf;
    u8 *addr;
    fn_8007148C((s32)(lbl_803C0B98 + 0x58));
    buf = GKI_getbuf(0x110);
    if (buf != 0) {
        addr = *(u8 **)(lbl_803C0B98 + 4) + 2;
        fn_80070FA4((u8 *)buf + 8, addr);
        strncpy((char *)buf + 0xE, (char *)arg0 + 4, 0x20);
        *(u16 *)buf = 0x204;
        fn_80071450(buf);
    }
}

void bta_dm_disc_remname_cback(u8 *arg0) {
    void *buf;
    fn_8007148C((s32)(lbl_803C0B98 + 0x58));
    buf = GKI_getbuf(0x110);
    if (buf != 0) {
        fn_80070FA4((u8 *)buf + 8, lbl_803C0B98 + 0x1A);
        strncpy((char *)buf + 0xE, (char *)arg0 + 4, 0x20);
        *(u16 *)buf = 0x204;
        fn_80071450(buf);
    }
}

void bta_sys_disable(void) {
    void **pp_module;
    void *p_module;
    void *p_fn;
    s32 i;

    pp_module = (void **)&lbl_803C0AD8;
    for (i = 0; i < 0x1A; i++) {
        p_module = *pp_module;
        if (p_module != NULL) {
            p_fn = *(void **)((u8 *)p_module + 4);
            if (p_fn != NULL) {
                ((void (*)(void))p_fn)();
            }
        }
        pp_module++;
    }
}

tBTM_STATUS BTM_ChangeEScoLinkParms(u16 sco_inx, tBTM_CHG_ESCO_PARAMS *p_parms) {
    u16 *var_r28 = (u16 *)p_parms;
    u16 *var_r30 = (u16 *)&lbl_80316570;
    u16 *var_r31;
    u16 *var_r29;
    u16 var_r27;
    u16 temp;
    u8 *btm_cb;
    
    if (sco_inx >= 3) {
        return BTM_WRONG_MODE;
    }
    
    btm_cb = lbl_803C0F78;
    var_r31 = (u16 *)&btm_cb[sco_inx * 0x34];
    
    if (var_r31[0x185C / 2] == 4) {
        return BTM_WRONG_MODE;
    }
    
    temp = btm_cb[0x1882 + sco_inx * 0x34];
    var_r29 = (u16 *)&var_r31[0x1868 / 2];
    
    if (temp != 0 && btm_cb[0x1908] != 0) {
        if (btm_cb[0x636] >= 3) {
            u16 pkt_mask = btm_cb[0x656];
            var_r27 = (((u16 *)var_r28)[0] | pkt_mask) & 0x3C0;
        } else {
            var_r27 = (((u16 *)var_r28)[0] & btm_cb[0x656]) & 0x3F;
        }
        
        if (btm_cb[0x27C0] >= 3) {
            fn_80070954(0xD0002, &var_r30[0x28C], var_r31[1]);
        }
        
        if (btsnd_hcic_setup_esco_conn(var_r31[1], var_r29[0], var_r29[1], ((u16 *)var_r28)[0], 0, ((u16 *)var_r28)[2], var_r27)) {
            ((u16 *)var_r28)[0] = var_r27;
            return BTM_CMD_STARTED;
        }
        return BTM_NO_RESOURCES;
    }
    
    var_r27 = (((u16 *)var_r28)[0] & btm_cb[0x656]) & 7;
    var_r29[3] = var_r27;
    
    if (btsnd_hcic_change_conn_type(var_r31[1], (var_r27 << 5) & 0xE0)) {
        if (btm_cb[0x27C0] >= 3) {
            fn_8007096C(0xD0002, &var_r30[0x248], var_r31[1], var_r27);
        }
        return BTM_CMD_STARTED;
    }
    return BTM_NO_RESOURCES;
}

BOOLEAN btm_is_sco_active(UINT16 handle) {
    u8 *base;
    base = lbl_803C0F78;
    if (handle == *(UINT16 *)(base + 0x185e) &&
        *(UINT16 *)(base + 0x185c) == 4)
        return TRUE;
    if (handle == *(UINT16 *)(base + 0x1892) &&
        *(UINT16 *)(base + 0x1890) == 4)
        return TRUE;
    if (handle == *(UINT16 *)(base + 0x18c6) &&
        *(UINT16 *)(base + 0x18c4) == 4)
        return TRUE;
    return FALSE;
}

extern unsigned char lbl_803C0F78[];
extern int memcmp(const void *, const void *, unsigned long);
int btm_num_sco_links_active(void) {
    int count;
    unsigned char *base;
    unsigned short state;
    base = lbl_803C0F78;
    count = 0;
    state = *(unsigned short *)(base + 0x185c);
    if (state >= 2 && state < 7)
        count = 1;
    state = *(unsigned short *)(base + 0x1890);
    if (state >= 2 && state < 7)
        count++;
    state = *(unsigned short *)(base + 0x18c4);
    if (state >= 2 && state < 7)
        count++;
    return count;
}

BOOLEAN btm_is_sco_active_by_bdaddr(BD_ADDR addr) {
    int i;
    u8 *link;
    i = 0;
    link = lbl_803C0F78 + 0x1854;
    do {
        if (memcmp(link + 0x28, addr, 6) == 0 && *(UINT16 *)(link + 8) == 4)
            return TRUE;
        i++;
        link += 0x34;
    } while ((unsigned)i < 3);
    return FALSE;
}

void BTM_PINCodeReply(BD_ADDR bd_addr, UINT8 res, UINT8 pin_len, UINT8 *p_pin, UINT32 trusted_mask[]) {
    void *p_dev;

    if (*(u32 *)(lbl_803C0F78 + 0x194C)) {
        fn_80070F90(lbl_803C0F78 + 0x193C);
        *(u32 *)(lbl_803C0F78 + 0x194C) = 0;
        memset(lbl_803C0F78 + 0x1954, 0xFF, 6);
        if (res != 0) {
            lbl_803C0F78[0x27BF] = 0xE;
            btsnd_hcic_link_key_neg_reply_800840C8(bd_addr);
        } else {
            lbl_803C0F78[0x27BF] = 0;
            btsnd_hcic_pin_code_req_reply(bd_addr, pin_len, p_pin);
            p_dev = btm_find_dev(bd_addr);
            if (p_dev != 0) {
                *(u32 *)((u8 *)p_dev + 0x10) = trusted_mask[0];
                *(u32 *)((u8 *)p_dev + 0x14) = trusted_mask[1];
            }
        }
    }
}

extern u8 btm_sec_execute_procedure(void *);
extern u8 lbl_80316A10[];
extern u8 lbl_80316A70[];
void BTM_DeviceAuthorized(u8 *bd_addr, u8 res, u32 *trusted_mask) {
    tBTM_SEC_DEV_REC *record = btm_find_dev(bd_addr);
    u8 *dev = (u8 *)record;
    if (record == 0) {
        if (lbl_803C0F78[0x27c0] >= 2) {
            fn_800709CC(0xD0001, lbl_80316A10, bd_addr[0], bd_addr[1], bd_addr[2],
                        bd_addr[3], bd_addr[4], bd_addr[5]);
        }
    } else {
        if (lbl_803C0F78[0x27c0] >= 4)
            fn_8007096C(0xD0003, lbl_80316A70, res, dev[0x7f] * (res != 0));
        if (res == 0) {
            dev[0x76] |= 1;
            *(u32 *)(dev + 0x10) = trusted_mask[0];
            *(u32 *)(dev + 0x14) = trusted_mask[1];
        }
        if (dev[0x7f] == 4) {
            dev[0x7f] = 0;
            if (res != 0) {
                if (*(void **)(dev + 4) != 0) {
                    if (dev[0x80] != 0) {
                        void *p = *(void **)dev;
                        if (p != 0 && *(u32 *)p == 3) *(u32 *)((u8 *)p + 4) = 0;
                    }
                    ((void (*)(u8 *, u32, u8))*(void **)(dev + 4))(bd_addr, *(u32 *)(dev + 8), res);
                    *(u32 *)(dev + 4) = 0;
                }
            } else {
                res = btm_sec_execute_procedure(dev);
                if (res != 1 && *(void **)(dev + 4) != 0) {
                    if (dev[0x80] != 0) {
                        void *p = *(void **)dev;
                        if (p != 0 && *(u32 *)p == 3) *(u32 *)((u8 *)p + 4) = 0;
                    }
                    ((void (*)(u8 *, u32, u8))*(void **)(dev + 4))(bd_addr, *(u32 *)(dev + 8), res);
                    *(u32 *)(dev + 4) = 0;
                }
            }
        }
    }
}

void fn_8007F588(s8 arg0) {
    lbl_803C0F78[0x1978] = arg0;
    memset(&lbl_803C0F78[0x1954], 0xFF, 6);
}

void fn_8007F5A4(void) {
    if (lbl_803C0F78[0x1978] == 3) {
        btsnd_hcic_write_pin_type_8008543C(1);
        btsnd_hcic_write_pin_type_800854B0(1);
    }
}

void btm_sec_abort_access_req(BD_ADDR arg0) {
    tBTM_SEC_DEV_REC *dev;
    void (*cb)(BD_ADDR, void *, void *);
    u8 state;
    u32 *p;
    u32 zero;
    dev = btm_find_dev(arg0);
    if (dev != 0) {
        cb = *(void (**)(BD_ADDR, void *, void *))((u8 *)lbl_803C0F78 + 0x1920);
        if (cb != 0) cb(arg0, (u8 *)dev + 0x22, (u8 *)dev + 0x35);
        state = *((u8 *)dev + 0x7f);
        if (state == 4) goto done;
        if (state != 1) goto done;
        zero = 0;
        *((u8 *)dev + 0x7f) = zero;
        if (*((u8 *)dev + 0x80) != 0) {
            p = *(u32 **)dev;
            if (p != 0 && *p == 3) {
                p[1] = zero;
                *(u32 *)((u8 *)dev + 4) = zero;
            }
        }
    }
done:
    return;
}

s32 fn_8007FEFC(u16 handle) {
    tBTM_SEC_DEV_REC *dev = btm_find_dev_by_handle(handle);
    if (dev == NULL) {
        return 0;
    }
    if ((((u8 *)dev)[0x81] & 0x40) != 0) {
        return 1;
    }
    return 0;
}

tBTM_STATUS btm_sec_disconnect(UINT16 handle, UINT8 reason) {
    tBTM_SEC_DEV_REC *p_dev_rec;
    UINT8 old_state;

    p_dev_rec = btm_find_dev_by_handle(handle);
    if (p_dev_rec == NULL) {
        return (tBTM_STATUS)5;
    }
    if (*((UINT8 *)p_dev_rec + 0x81) & 0x40) {
        lbl_803C0F78[0x197E] = reason;
        return (tBTM_STATUS)0;
    }
    old_state = *((UINT8 *)p_dev_rec + 0x7F);
    if (old_state == 5) {
        return (tBTM_STATUS)1;
    }
    *((UINT8 *)p_dev_rec + 0x7F) = 5;
    if (btsnd_hcic_disconnect(handle, reason)) {
        return (tBTM_STATUS)1;
    }
    *((UINT8 *)p_dev_rec + 0x7F) = old_state;
    return (tBTM_STATUS)3;
}

extern u8 lbl_80317008[];
void btm_sec_pin_code_request_timeout(void) {
    u8 *base = lbl_803C0F78;

    if (base[0x27C0] >= 4) {
        fn_8007093C(0xD0003, lbl_80317008);
    }
    *(u32 *)(base + 0x194C) = 0;
    memset(lbl_803C0F78 + 0x1954, 0xFF, 6);
    btsnd_hcic_link_key_neg_reply_800840C8(base + 0x27B4);
}

void btm_sec_update_clock_offset(UINT16 handle, UINT16 clock_offset) {
    tBTM_SEC_DEV_REC *dev;
    tBTM_INQ_INFO *inq;

    dev = btm_find_dev_by_handle(handle);
    if (dev != NULL) {
        clock_offset |= 0x8000;
        *(UINT16 *)((u8 *)dev + 0x1A) = clock_offset;
        inq = BTM_InqDbRead((u8 *)dev + 0x1C);
        if (inq != NULL) {
            *(UINT16 *)inq = clock_offset;
        }
    }
}

s32 fn_8008128C(void *arg0) {
    void *dev = btm_find_dev(arg0);
    if (dev != NULL) {
        return (s32)dev + 0x10;
    }
    return 0;
}

void btu_hcif_connection_request_evt(u8 *event) {
    u8 bda[6];
    u8 dev_class[3];
    u8 link_type;

    bda[5] = event[0];
    bda[4] = event[1];
    bda[3] = event[2];
    bda[2] = event[3];
    bda[1] = event[4];
    bda[0] = event[5];
    dev_class[2] = event[6];
    dev_class[1] = event[7];
    dev_class[0] = event[8];
    link_type = event[9];
    if (link_type == 1) {
        btm_sec_conn_req(bda, dev_class);
    } else {
        btm_sco_conn_req(bda, dev_class, link_type);
    }
}

void btu_hcif_hdl_command_complete(UINT16 opcode, UINT8 *param2, UINT16 param3) {
    if (opcode == 0xC14) { btm_read_local_name_complete(param2, param3); return; }
    if (opcode < 0xC14) {
        if (opcode == 0xC05) { btm_event_filter_complete(param2); return; }
        if (opcode < 0xC05) {
            if (opcode == 0x80C) { btm_read_link_policy_complete(param2); return; }
            if (opcode < 0x80C) {
                if (opcode == 0x402) { btm_process_inq_complete(0, (UINT8)param2); return; }
            } else if (opcode == 0xC03) { btm_reset_complete(); return; }
        } else {
            if (opcode == 0xC11) { btm_write_stored_link_key_complete(param2); return; }
            if (opcode < 0xC11) {
                if (opcode == 0xC0D) { btm_read_stored_link_key_complete(param2); return; }
            } else if (opcode < 0xC13) { btm_delete_stored_link_key_complete(param2); return; }
        }
    } else {
        if (opcode == 0x1009) { fn_8007A280(param2); return; }
        if (opcode < 0x1009) {
            if (opcode == 0x1003) { btm_read_local_features_complete(param2, param3); return; }
            if (opcode < 0x1003) {
                if (opcode == 0x1001) { btm_read_local_version_complete(param2, param3); return; }
            } else if (opcode == 0x1005) { btm_read_hci_buf_size_complete(param2, param3); return; }
        } else if (opcode != 0x1404) {
            if (opcode < 0x1404) {
                if (opcode > 0x1402) { btm_read_link_quality_complete(param2); return; }
            } else if (opcode < 0x1406) { btm_read_rssi_complete(param2); return; }
        }
    }
    if ((opcode & 0xFC00) == 0xFC00) btm_vsc_complete(param2, opcode, param3, (tBTM_CMPL_CB *)opcode);
}

extern void l2c_link_role_change_failed(void);
void btu_hcif_hdl_command_status(s32 arg0, s32 arg1, UINT8 *arg2) {
    tBTM_ESCO_DATA sp10;
    UINT8 spD, spC, spB, spA, sp9, sp8;
    UINT16 temp_r0;
    if (arg0 != 0x802) {
        if (arg0 < 0x802) {
            if (arg0 < 0x801) goto block_6;
            goto block_5;
        }
        if (arg0 < 0x807) {
block_5:
            btm_pm_proc_cmd_status(arg1);
            return;
        }
        goto block_6;
    }
block_6:
    if (arg1 != 0) {
        switch (arg0) {
        case 0x401: btm_process_inq_complete(arg1, 0); return;
        case 0x419: btm_process_remote_name(0, 0, 0, arg1); btm_sec_rmt_name_request_complete(0, 0, arg1); return;
        case 0xD: btm_qos_setup_complete(arg1, 0, 0); return;
        case 0x80B: btm_acl_role_changed(arg1, 0, 0xFF); l2c_link_role_change_failed(); return;
        case 0x405:
            if (arg2 != 0) {
                spD=arg2[1]; spC=arg2[2]; spB=arg2[3]; spA=arg2[4]; sp9=arg2[5]; sp8=arg2[6];
                btm_sec_connected(&sp8,0xFFFF,arg1,0); l2c_link_hci_conn_comp(arg1,0xFFFF,&sp8); return;
            }
            break;
        case 0x428:
            if (arg2 != 0) {
                temp_r0=arg2[1]+(arg2[2]<<8);
                if (btm_is_sco_active(temp_r0)!=0) { btm_esco_proc_conn_chg(arg1,temp_r0,0,0,0,0); return; }
                btm_sco_connected(arg1,0,temp_r0,&sp10); return;
            }
            break;
        default:
            if ((u32)(arg0 & 0xFC00)==0xFFFFFC00U) btm_vsc_complete(arg2,arg0,1,0);
            break;
        }
    }
}

void fn_8008251C(void) {
    btm_init();
    l2c_init();
    sdp_init();
    btm_discovery_db_init();
}

void fn_80082548(void) {
 memset(&lbl_803C0A50, 0, 0x84);
 *(u16 *)((u8 *)&lbl_803C0A50 + 0x7e)=0x2a4;
 *(u16 *)((u8 *)&lbl_803C0A50 + 0x80)=1;
}

extern u8 lbl_803C3740[];
extern void gap_connect_ind(void), gap_connect_cfm(void), gap_config_ind(void), gap_config_cfm(void), gap_disconnect_ind(void), gap_data_ind(void), gap_congestion_ind(void);
void fn_800826D4(void) {
 *(void **)(lbl_803C3740+0x84)=gap_connect_ind;
 *(void **)(lbl_803C3740+0x88)=gap_connect_cfm;
 *(void **)(lbl_803C3740+0x8c)=0;
 *(void **)(lbl_803C3740+0x90)=gap_config_ind;
 *(void **)(lbl_803C3740+0x94)=gap_config_cfm;
 *(void **)(lbl_803C3740+0x98)=gap_disconnect_ind;
 *(void **)(lbl_803C3740+0x9c)=0;
 *(void **)(lbl_803C3740+0xa0)=0;
 *(void **)(lbl_803C3740+0xa4)=gap_data_ind;
 *(void **)(lbl_803C3740+0xa8)=gap_congestion_ind;
}

void fn_800833E8(s32 arg0) { btm_cback(0, arg0); }

void fn_800833F4(s32 arg0) { btm_cback(1, arg0); }

extern u16 lbl_80317620;
extern void gap_find_addr_name_cb(void *);
void gap_find_addr_inq_cb(u8 *param) {
    u16 result;
    u8 event;
    void *info;

    if (lbl_803C3740[0x7E] == 0) return;
    if (lbl_803C3740[0x28] >= 5)
        fn_8007096C(0xE0003, &lbl_80317620, param[0], param[1]);
    event = param[0];
    if (event == 0) {
        result = 0x111;
        info = BTM_InqDbFirst();
        *(void **)(lbl_803C3740 + 0x30) = info;
        if (info == 0) result = 0x102;
        else if (BTM_ReadRemoteDeviceName((u8 *)info + 2, gap_find_addr_name_cb) == 1) return;
    }
    if (event <= 8) {
        switch (event) {
        case 0: result = 0; break;
        case 1: result = 0x10B; break;
        case 2: result = 0x103; break;
        case 3: result = 0x109; break;
        case 4: result = 0x10C; break;
        case 5: result = 0x10D; break;
        case 6: result = 0x115; break;
        case 7: result = 0x114; break;
        default: break;
        }
    } else result = 0x114;
    *(u16 *)(lbl_803C3740 + 0x34) = result;
    if (*(void **)(lbl_803C3740 + 0x2C) != 0)
        ((void (*)(u32, u16 *))*(void **)(lbl_803C3740 + 0x2C))(5, &result);
    lbl_803C3740[0x7E] = 0;
    *(void **)(lbl_803C3740 + 0x2C) = 0;
}

u16 gap_convert_btm_status(u16 status) {
    switch (status) {
    case 0: return 0;
    case 1: return 0x10B;
    case 2: return 0x103;
    case 3: return 0x109;
    case 4: return 0x10C;
    case 5: return 0x10D;
    case 6: return 0x115;
    case 7:
    case 8:
    default: return 0x114;
    }
}

BOOLEAN btsnd_hcic_inquiry(const LAP inq_lap, UINT8 duration, UINT8 response_cnt) {
    u8 *p_buf;
    u8 lap2;
    u8 lap1;
    if ((p_buf = GKI_getpoolbuf(2)) == NULL) return FALSE;
    *(u16*)&p_buf[2] = 8;
    *(u16*)&p_buf[4] = 0;
    p_buf[8] = 1;
    p_buf[9] = 4;
    p_buf[10] = 5;
    lap2 = inq_lap[2];
    p_buf[11] = lap2;
    lap1 = inq_lap[1];
    p_buf[12] = lap1;
    p_buf[13] = inq_lap[0];
    p_buf[14] = duration;
    p_buf[15] = response_cnt;
    btu_hcif_send_cmd(p_buf);
    return TRUE;
}

u8 btsnd_hcic_inq_cancel(void) {
    u8 *p;
    u16 zero = 0;
    p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = zero;
    p[8] = 2;
    p[9] = 4;
    p[10] = zero;
    btu_hcif_send_cmd(p, 2);
    return TRUE;
}

BOOLEAN btsnd_hcic_per_inq_mode(UINT16 max_period, UINT16 min_period, const LAP inq_lap, UINT8 duration, UINT8 response_cnt) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 0xC;
    *(u16 *)(p + 4) = 0;
    p[8] = 3; p[9] = 4; p[10] = 9;
    p[11] = max_period; p[12] = max_period >> 8;
    p[13] = min_period; p[14] = min_period >> 8;
    p[15] = inq_lap[2]; p[16] = inq_lap[1]; p[17] = inq_lap[0];
    p[18] = duration; p[19] = response_cnt;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_disconnect(UINT16 handle, UINT8 reason) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 6;
    *(u16 *)(p + 4) = 0;
    p[8] = 6; p[9] = 4; p[10] = 3;
    p[11] = handle; p[12] = handle >> 8; p[13] = reason;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_add_SCO_conn(UINT16 handle, UINT16 packet_types) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 7;
    *(u16 *)(p + 4) = 0;
    p[8] = 7; p[9] = 4; p[10] = 4;
    p[11] = handle; p[12] = handle >> 8;
    p[13] = packet_types; p[14] = packet_types >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_link_key_neg_reply(BD_ADDR bd_addr) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 9;
    *(u16 *)(p + 4) = 0;
    p[8] = 0xC; p[9] = 4; p[10] = 6;
    p[11] = bd_addr[5]; p[12] = bd_addr[4]; p[13] = bd_addr[3];
    p[14] = bd_addr[2]; p[15] = bd_addr[1]; p[16] = bd_addr[0];
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_pin_code_req_reply(BD_ADDR bd_addr, UINT8 pin_code_len, PIN_CODE pin_code) {
    BT_HDR *p_buf;
    UINT8 *p;
    UINT8 *src;
    UINT8 *dst;
    UINT8 i;

    p_buf = (BT_HDR *)GKI_getpoolbuf(2);
    if (p_buf == NULL) return FALSE;
    p = (UINT8 *)p_buf;
    *(UINT16 *)(p + 2) = 0x1A;
    *(UINT16 *)(p + 4) = 0;
    p[8] = 0x0D;
    p[9] = 4;
    p[10] = 0x17;
    p[11] = bd_addr[5];
    p[12] = bd_addr[4];
    p[13] = bd_addr[3];
    p[14] = bd_addr[2];
    p[15] = bd_addr[1];
    p[16] = bd_addr[0];
    p[17] = pin_code_len;
    src = pin_code;
    dst = p + 0x12;
    for (i = 0; i < pin_code_len; i++) *dst++ = *src++;
    while (i < 16) { *dst++ = 0; i++; }
    btu_hcif_send_cmd(p_buf);
    return TRUE;
}

BOOL btsnd_hcic_link_key_neg_reply_800840C8(void *link_key) {
    u8 *p;
    p = GKI_getpoolbuf(2);
    if (p == 0) {
        return FALSE;
    }
    *(u16 *)(p + 2) = 9;
    *(u16 *)(p + 4) = 0;
    p[8] = 0xE;
    p[9] = 4;
    p[10] = 6;
    p[11] = ((u8 *)link_key)[5];
    p[12] = ((u8 *)link_key)[4];
    p[13] = ((u8 *)link_key)[3];
    p[14] = ((u8 *)link_key)[2];
    p[15] = ((u8 *)link_key)[1];
    p[16] = ((u8 *)link_key)[0];
    btu_hcif_send_cmd(4, (BT_HDR *)p);
    return TRUE;
}

BOOLEAN btsnd_hcic_change_conn_type(UINT16 handle, UINT16 packet_types) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 7;
    *(u16 *)(p + 4) = 0;
    p[8] = 0xF; p[9] = 4; p[10] = 4;
    p[11] = handle; p[12] = handle >> 8;
    p[13] = packet_types; p[14] = packet_types >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_auth_request(UINT16 handle) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 5;
    *(u16 *)(p + 4) = 0;
    p[8] = 0x11; p[9] = 4; p[10] = 2;
    p[11] = handle; p[12] = handle >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_set_conn_encrypt(UINT16 handle, BOOLEAN enable) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 6;
    *(u16 *)(p + 4) = 0;
    p[8] = 0x13; p[9] = 4; p[10] = 3;
    p[11] = handle; p[12] = handle >> 8; p[13] = enable;
    btu_hcif_send_cmd(p);
    return TRUE;
}

u8 btsnd_hcic_rmt_name_req(u8 *bd_addr, u8 page_scan_rep_mode, u8 page_scan_mode, u16 clock_offset) {
    BT_HDR *p;
    u8 *pp;
    p = (BT_HDR *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    p->len = 0xD;
    p->offset = 0;
    pp = (u8 *)(p + 1);
    pp[0] = 0x19;
    pp[1] = 4;
    pp[2] = 0xA;
    pp[3] = bd_addr[5];
    pp[4] = bd_addr[4];
    pp[5] = bd_addr[3];
    pp[6] = bd_addr[2];
    pp[7] = bd_addr[1];
    pp[8] = bd_addr[0];
    pp[9] = page_scan_rep_mode;
    pp[10] = page_scan_mode;
    pp[11] = clock_offset;
    pp[12] = clock_offset >> 8;
    btu_hcif_send_cmd(0, p);
    return TRUE;
}

s32 btsnd_hcic_link_key_neg_reply_800843D8(u8 *arg0) {
    u8 *buf = (u8 *)GKI_getpoolbuf(2);
    if (buf == 0) return 0;
    *(u16 *)(buf + 2)=9; *(u16 *)(buf + 4)=0;
    buf[8]=0x1A; buf[9]=4; buf[10]=6;
    buf[11]=arg0[5]; buf[12]=arg0[4]; buf[13]=arg0[3]; buf[14]=arg0[2]; buf[15]=arg0[1]; buf[16]=arg0[0];
    btu_hcif_send_cmd(buf); return 1;
}

s32 btsnd_hcic_auth_request_80084478(u16 arg0) {
    u8 *buf = (u8 *)GKI_getpoolbuf(2);
    if (buf == 0) return 0;
    *(u16 *)(buf + 2) = 5; *(u16 *)(buf + 4) = 0;
    buf[8]=0x1B; buf[9]=4; buf[10]=2; buf[11]=(u8)arg0; buf[12]=(u8)(arg0>>8);
    btu_hcif_send_cmd(buf); return 1;
}

s32 btsnd_hcic_auth_request_800844F4(u16 arg0) {
    u8 *buf = (u8 *)GKI_getpoolbuf(2);
    if (buf == 0) return 0;
    *(u16 *)(buf + 2) = 5; *(u16 *)(buf + 4) = 0;
    buf[8]=0x1D; buf[9]=4; buf[10]=2; buf[11]=(u8)arg0; buf[12]=(u8)(arg0>>8);
    btu_hcif_send_cmd(buf); return 1;
}

s32 btsnd_hcic_auth_request_80084570(u16 handle) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return 0;
    *(u16 *)(p + 2) = 5;
    *(u16 *)(p + 4) = 0;
    p[8] = 0x1F;
    p[9] = 4;
    p[10] = 2;
    p[11] = handle;
    p[12] = handle >> 8;
    btu_hcif_send_cmd(p);
    return 1;
}

s32 btsnd_hcic_hold_mode_80084A34(u8 *p, u16 handle, u16 max_interval, u16 min_interval) {
    if (p == NULL) {
        p = GKI_getpoolbuf(2);
        if (p == NULL) return 0;
    }
    *(u16 *)(p + 2) = 9;
    *(u16 *)(p + 4) = 0;
    p[8] = 5;
    p[9] = 8;
    p[10] = 6;
    p[11] = handle;
    p[12] = handle >> 8;
    p[13] = max_interval;
    p[14] = max_interval >> 8;
    p[15] = min_interval;
    p[16] = min_interval >> 8;
    btu_hcif_send_cmd(p);
    return 1;
}

s32 btsnd_hcic_exit_sniff_mode_80084AE8(u8 *p, u16 handle) {
    if (p == NULL) {
        p = GKI_getpoolbuf(2);
        if (p == NULL) return 0;
    }
    *(u16 *)(p + 2) = 5;
    *(u16 *)(p + 4) = 0;
    p[8] = 6;
    p[9] = 8;
    p[10] = 2;
    p[11] = handle;
    p[12] = handle >> 8;
    btu_hcif_send_cmd(p);
    return 1;
}

BOOLEAN btsnd_hcic_switch_role(BD_ADDR bd_addr, UINT8 role) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 10;
    *(u16 *)(p + 4) = 0;
    p[8] = 0xB;
    p[9] = 8;
    p[10] = 7;
    p[11] = bd_addr[5];
    p[12] = bd_addr[4];
    p[13] = bd_addr[3];
    p[14] = bd_addr[2];
    p[15] = bd_addr[1];
    p[16] = bd_addr[0];
    p[17] = role;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_write_policy_set(UINT16 handle, UINT16 settings) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 7;
    *(u16 *)(p + 4) = 0;
    p[8] = 0xD;
    p[9] = 8;
    p[10] = 4;
    p[11] = handle;
    p[12] = handle >> 8;
    p[13] = settings;
    p[14] = settings >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_reset(UINT8 local_controller_id) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = 0;
    p[8] = 3;
    p[9] = 0xC;
    p[10] = 0;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_write_pin_type(UINT8 type) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 4;
    *(u16 *)(p + 4) = 0;
    p[8] = 0xA; p[9] = 0xC; p[10] = 1; p[11] = type;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_read_stored_key(BD_ADDR bd_addr, BOOLEAN read_all_flag) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 10;
    *(u16 *)(p + 4) = 0;
    p[8] = 0xD; p[9] = 0xC; p[10] = 7;
    p[11] = bd_addr[5]; p[12] = bd_addr[4]; p[13] = bd_addr[3];
    p[14] = bd_addr[2]; p[15] = bd_addr[1]; p[16] = bd_addr[0];
    p[17] = read_all_flag;
    btu_hcif_send_cmd(p);
    return TRUE;
}

s32 btsnd_hcic_switch_role_8008515C(BD_ADDR bd_addr, UINT8 role) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return 0;
    *(u16 *)(p + 2) = 10;
    *(u16 *)(p + 4) = 0;
    p[8] = 0x12; p[9] = 0xC; p[10] = 7;
    p[11] = bd_addr[5]; p[12] = bd_addr[4]; p[13] = bd_addr[3];
    p[14] = bd_addr[2]; p[15] = bd_addr[1]; p[16] = bd_addr[0];
    p[17] = role;
    btu_hcif_send_cmd(p);
    return 1;
}

BOOLEAN btsnd_hcic_change_name(BD_NAME name) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    u32 len = strlen((char *)name) + 1;
    u8 *dst = p + 0xB;
    u8 *src = (u8 *)name;
    u32 i = 0;
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 0xFB;
    *(u16 *)(p + 4) = 0;
    p[8] = 0x13; p[9] = 0xC; p[10] = 0xF8;
    if (len > 0) {
        if (len >= 8) {
            u32 r = len - 8;
            if (r > 0) {
                u32 k = (r + 7) >> 3;
                if (k > 0) {
                    do {
                        dst[0] = src[i];
                        dst[1] = src[i + 1];
                        dst[2] = src[i + 2];
                        dst[3] = src[i + 3];
                        dst[4] = src[i + 4];
                        dst[5] = src[i + 5];
                        dst[6] = src[i + 6];
                        dst[7] = src[i + 7];
                        dst += 8;
                        i += 8;
                    } while (--k > 0);
                }
            }
        }
        while (i < len) {
            *dst++ = src[i++];
        }
    }
    btu_hcif_send_cmd(p);
    return TRUE;
}

void fn_80085384(u8 *arg0, u8 arg1) {
    *(u16 *)(arg0 + 2) = 4; *(u16 *)(arg0 + 4) = 0;
    arg0[8] = 0x1A; arg0[9] = 0xC; arg0[10] = 1; arg0[11] = arg1;
    btu_hcif_send_cmd(0xC, 0x1A, 0, 4);
}

void fn_800853B4(u8 *arg0, u16 arg1, u16 arg2) {
    *(u16 *)(arg0 + 2) = 7; *(u16 *)(arg0 + 4) = 0;
    arg0[8] = 0x1C; arg0[9] = 0xC; arg0[10] = 4;
    arg0[11] = arg1; arg0[12] = arg1 >> 8; arg0[13] = arg2; arg0[14] = arg2 >> 8;
    btu_hcif_send_cmd(arg1 >> 8, 4, 0xC, 0x1C, 0);
}

void fn_800853F8(u8 *arg0, u16 arg1, u16 arg2) {
    *(u16 *)(arg0 + 2) = 7; *(u16 *)(arg0 + 4) = 0;
    arg0[8] = 0x1E; arg0[9] = 0xC; arg0[10] = 4;
    arg0[11] = arg1; arg0[12] = arg1 >> 8; arg0[13] = arg2; arg0[14] = arg2 >> 8;
    btu_hcif_send_cmd(arg1 >> 8, 4, 0xC, 0x1E, 0);
}

BOOL btsnd_hcic_write_pin_type_8008543C(u32 pin_type) {
    u8 *buf = GKI_getpoolbuf(2);
    if (buf == NULL) return FALSE;
    *(u16 *)(buf + 2) = 4;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 0x20;
    buf[9] = 0xC;
    buf[10] = 1;
    buf[11] = pin_type;
    btu_hcif_send_cmd(buf);
    return TRUE;
}

BOOL btsnd_hcic_write_pin_type_800854B0(u32 pin_type) {
    u8 *buf = GKI_getpoolbuf(2);
    if (buf == NULL) return FALSE;
    *(u16 *)(buf + 2) = 4;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 0x22;
    buf[9] = 0xC;
    buf[10] = 1;
    buf[11] = pin_type;
    btu_hcif_send_cmd(buf);
    return TRUE;
}

void fn_80085568(void *arg0, u16 arg1, u16 arg2) {
    ((u16 *)((u8 *)arg0 + 2))[0] = 7;
    ((u16 *)((u8 *)arg0 + 4))[0] = 0;
    ((u8 *)arg0)[8] = 0x28;
    ((u8 *)arg0)[9] = 0xC;
    ((u8 *)arg0)[10] = 4;
    ((u8 *)arg0)[11] = arg1;
    ((u8 *)arg0)[12] = arg1 >> 8;
    ((u8 *)arg0)[13] = arg2;
    ((u8 *)arg0)[14] = arg2 >> 8;
    btu_hcif_send_cmd(arg0);
}

BOOLEAN btsnd_hcic_set_host_buf_size(UINT16 acl_len, UINT8 sco_len, UINT16 acl_num, UINT16 sco_num) {
    BT_HDR *buf = GKI_getpoolbuf(2);
    u8 *p;
    if (buf == NULL) return FALSE;
    buf->len = 10;
    buf->offset = 0;
    p = (u8 *)(buf + 1);
    p[0] = 0x33; p[1] = 0xC; p[2] = 7;
    p[3] = acl_len; p[4] = acl_len >> 8;
    p[5] = sco_len;
    p[6] = acl_num; p[7] = acl_num >> 8;
    p[8] = sco_num; p[9] = sco_num >> 8;
    btu_hcif_send_cmd(buf);
    return TRUE;
}

s32 btsnd_hcic_write_policy_set_80085668(u16 arg0, u16 arg1) {
    u8 *buf = GKI_getpoolbuf(2);
    register u16 first = arg0;
    register u16 second = arg1;
    if (buf == NULL) return 0;
    *(u16 *)(buf + 2) = 7;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 0x37;
    buf[9] = 0xC;
    buf[10] = 4;
    buf[11] = first;
    buf[12] = first >> 8;
    buf[13] = second;
    buf[14] = second >> 8;
    btu_hcif_send_cmd(first >> 8, 4, 0xC, 0x37);
    return 1;
}

BOOLEAN btsnd_hcic_write_cur_iac_lap(UINT8 num_cur_iac, LAP cur_iac_lap[]) {
    UINT8 *p_buf = GKI_getpoolbuf(2);
    UINT8 *p;
    UINT8 i;
    if (p_buf == NULL) return FALSE;
    *(u16 *)(p_buf + 2) = (num_cur_iac * 3) + 4;
    *(u16 *)(p_buf + 4) = 0;
    p_buf[8] = 0x3A;
    p_buf[9] = 0xC;
    p_buf[10] = (num_cur_iac * 3) + 1;
    p_buf[11] = num_cur_iac;
    p = p_buf + 0xC;
    for (i = 0; i < num_cur_iac; i++) {
        p[0] = cur_iac_lap[i][2];
        p[1] = cur_iac_lap[i][1];
        p[2] = cur_iac_lap[i][0];
        p += 3;
    }
    btu_hcif_send_cmd(p_buf);
    return TRUE;
}

s32 btsnd_hcic_inq_cancel_8008576C(void) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == 0) return 0;
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = 0;
    p[8] = 1; p[9] = 0x10; p[10] = 0;
    btu_hcif_send_cmd(p);
    return 1;
}

s32 btsnd_hcic_reset_800857CC(void) {
    u8 *p = GKI_getpoolbuf(2);
    u16 three = 3;
    u16 zero = 0;
    if (p == NULL) return 0;
    *(u16 *)(p + 2) = three;
    *(u16 *)(p + 4) = zero;
    p[8] = (u8)three;
    p[9] = 0x10;
    p[10] = (u8)zero;
    btu_hcif_send_cmd(0, 3);
    return 1;
}

void fn_80085828(void *arg0) {
    u8 *p = (u8 *)arg0;
    p[2] = 3; p[3] = 0;
    p[4] = 0; p[5] = 0;
    p[8] = 5; p[9] = 0x10; p[10] = 0;
    btu_hcif_send_cmd(5, 0, 3);
}

s32 btsnd_hcic_inq_cancel_80085850(void) {
    u8 *p = GKI_getpoolbuf(2);
    u16 zero = 0;
    u8 opcode = 9;
    if (p == 0) {
        return 0;
    }
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = zero;
    p[8] = opcode;
    p[9] = 0x10;
    p[10] = zero;
    btu_hcif_send_cmd(p, opcode);
    return 1;
}

s32 btsnd_hcic_auth_request_800858B0(u16 arg0) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == 0) return 0;
    *(s16 *)(p + 2) = 5;
    *(s16 *)(p + 4) = 0;
    p[8] = 3;
    p[9] = 0x14;
    p[10] = 2;
    p[11] = (u8)arg0;
    p[12] = (u8)(arg0 >> 8);
    btu_hcif_send_cmd();
    return 1;
}

BOOLEAN btsnd_hcic_read_rssi(UINT16 handle) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 5;
    *(u16 *)(p + 4) = 0;
    p[8] = 5;
    p[9] = 0x14;
    p[10] = 2;
    p[11] = handle;
    p[12] = handle >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

extern u8 lbl_802EEC08[];
BOOLEAN btsnd_hcic_set_afh_channels(u8 first, u8 last) {
    u8 map[10];
    u8 *buf;
    s32 i;

    for (i = 0; i < 10; i++) map[i] = lbl_802EEC08[i];
    buf = (u8 *)GKI_getpoolbuf(2);
    if (buf == 0) return 0;

    *(u16 *)(buf + 2) = 0xD;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 0x3F;
    buf[9] = 0xC;
    buf[10] = 0xA;

    if (first <= last && last <= 0x4E) {
        for (i = first; i <= last; i++) map[i >> 3] &= ~(1 << (i & 7));
    }
    for (i = 0; i < 10; i++) buf[11 + i] = map[i];
    btu_hcif_send_cmd(buf);
    return 1;
}

void btsnd_hcic_vendor_spec_cmd(void *buffer, u16 opcode, u8 len, u8 *p_data, void *p_cmd_cplt_cback) {
    u8 *p = (u8 *)buffer;
    u8 *pp = p + 8;
    u16 cmd = 0xFC00 | opcode;
    *(u16 *)(p + 2) = 3 + len;
    *(u16 *)(p + 4) = 0;
    *(void **)pp = p_cmd_cplt_cback;
    pp += 4;
    *pp = (u8)cmd;
    pp[1] = (u8)(cmd >> 8);
    pp[2] = len;
    pp += 3;
    if (len > 0) {
        if (len > 8) {
            if (len < 8 || len > 0x7FFFFFFE) {
                ;
            } else {
                u8 blocks = (len - 8 + 7) >> 3;
                u8 *src = p_data;
                u8 i;
                u8 j;
                for (i = 0; i < blocks; i++) {
                    *pp = *src;
                    src++;
                    for (j = 1; j < 8; j++) pp[j] = *src++;
                    pp += 8;
                }
                for (i = 0; i * 8 < len - 8; i++) *pp++ = *src++;
            }
        } else {
            u8 i;
            u8 *src = p_data;
            for (i = 0; i < len; i++) *pp++ = *src++;
        }
    }
    btu_hcif_send_cmd(p);
}

s32 HID_HostGetSDPRecord(void *addr, void *p_db, u32 db_len, void *sdp_cback) {
    extern u8 lbl_803C3C38[];
    extern void hidh_search_callback(u16);
    tSDP_UUID uuid_list;

    if (lbl_803C3C38[0x380] != 0) return 0x10;
    *(void **)(lbl_803C3C38 + 0x388) = p_db;
    uuid_list.len = 2;
    uuid_list.uu.uuid16 = 0x1124;
    SDP_InitDiscoveryDb(p_db, db_len, 1, &uuid_list, 0, NULL);
    if (SDP_ServiceSearchRequest(addr, p_db, hidh_search_callback)) {
        *(void **)(lbl_803C3C38 + 0x384) = sdp_cback;
        lbl_803C3C38[0x380] = 1;
        return 0;
    }
    return 3;
}

extern u8 lbl_803C3C38[];
extern u8 lbl_803C3AF0[];
extern u8 hidh_conn_reg(void);
extern u8 hidh_conn_initiate(void);
extern void hidd_pm_set_now(void *);
u8 HID_HostRegister(void *arg0) {
    u8 result;
    if (lbl_803C3C38[0x400] != 0)
        return 2;
    if (arg0 == 0)
        return 5;
    result = hidh_conn_reg();
    if (result != 0)
        return result;
    *(void **)(lbl_803C3C38 + 0x340) = arg0;
    lbl_803C3C38[0x400] = 1;
    return 0;
}

#pragma push
#pragma use_lmw_stmw off
u8 HID_HostDeregister(void) {
    extern u8 lbl_803C3C38[];
    extern u8 hidh_conn_disconnect(u32);
    extern void fn_80070F90(void*);
    extern void fn_80089248(void);
    u8 *entry;
    u32 offset;
    u32 i;
    if (lbl_803C3C38[0x400] == 0)
        return 1;
    for (i = 0; i <= 0x10; i++) {
        offset = i * 0x34;
        entry = lbl_803C3C38 + offset;
        if (entry[0] == 0)
            continue;
        if (entry[0xA] == 1) {
            entry[0xC] = 1;
            fn_80070F90(entry + 0x1C);
            if (entry[0xA] == 1) {
                entry[0xC] = 1;
                hidh_conn_disconnect(i);
            }
        }
        entry[0] = 0;
        entry[0x10] = 0;
        *(u16 *)(entry + 0x16) = 0;
        *(u16 *)(entry + 0x14) = 0;
    }
    fn_80089248();
    lbl_803C3C38[0x400] = 0;
    return 0;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
u8 HID_HostRemoveDev(u32 dev_handle) {
    extern u8 lbl_803C3C38[];
    extern u8 hidh_conn_disconnect(u32);
    u8 *entry;
    u32 offset;
    if (lbl_803C3C38[0x400] == 0)
        return 1;
    if (dev_handle > 0x10)
        return 5;
    offset = dev_handle * 0x34;
    entry = lbl_803C3C38 + offset;
    if (entry[0] == 0)
        return 5;
    if (entry[0xA] == 1) {
        entry[0xC] = 1;
        fn_80070F90(entry + 0x1C);
        if (entry[0xA] == 1) {
            entry[0xC] = 1;
            hidh_conn_disconnect(dev_handle);
        }
    }
    entry[0] = 0;
    entry[0x10] = 0;
    entry[0x14] = 0;
    entry[0x16] = 0;
    return 0;
}
#pragma pop
u8 HID_HostOpenDev(u32 arg0) {
    u8 *entry;
    u32 offset;
    if (lbl_803C3C38[0x400] == 0)
        return 1;
    if (arg0 > 0x10) return 5;
    offset = arg0 * 0x34;
    entry = lbl_803C3C38 + offset;
    if (entry[0] == 0)
        return 5;
    if (entry[0xA] != 0)
        return 10;
    entry[0xC] = 1;
    return hidh_conn_initiate();
}

extern char lbl_80317CC8[];
extern char lbl_80317CFC[];
extern char lbl_80318C8C[];
void fn_80089248(void)
{
    L2CA_Deregister(0x11);
    L2CA_Deregister(0x13);
}

extern u8 lbl_80560D48[];
BOOLEAN L2CA_SetIdleTimeoutByBdAddr(BD_ADDR addr, UINT16 timeout) {
    void *p;
    u8 *entry;
    if (memcmp(lbl_80560D48, addr, 6) != 0) {
        p = l2cu_find_lcb_by_bd_addr(addr);
        if (p != 0 && *(u8 *)p != 0 && *(s32 *)((u8 *)p + 4) == 4) {
            *(u16 *)((u8 *)p + 0x58) = timeout;
            goto done;
        }
        return FALSE;
    }
    entry = lbl_803C4040;
    if (entry[8] != 0 && *(s32 *)(entry + 0xC) == 4) *(u16 *)(entry + 0x60) = timeout;
    if ((entry += 0x64)[0] != 0 && *(s32 *)(entry + 4) == 4) *(u16 *)(entry + 0x58) = timeout;
    if (entry[0x5C] != 0 && *(s32 *)(entry + 0x60) == 4) *(u16 *)(entry + 0xB4) = timeout;
    if (entry[0xB8] != 0 && *(s32 *)(entry + 0xBC) == 4) *(u16 *)(entry + 0x110) = timeout;
done:
    return TRUE;
}

extern void fn_80070954(u32, void *, u16);
extern void *l2cu_find_ccb_by_cid(void *, u16);
extern void fn_80089E40(void *, u8, void *);
extern char lbl_8031801C[];
extern char lbl_80318040[];
extern char lbl_8031806C[];
extern char lbl_80318090[];
u8 fn_80089E20(u8 value) {
    if (value != 0xFF) lbl_803C4040[0] = value;
    return lbl_803C4040[0];
}

void fn_80089E3C(void) {

}

extern char lbl_80318580[];
extern char lbl_803185A8[];
extern void l2cu_release_ccb(void *);
extern void l2cu_send_peer_connect_rsp(void *, u8, u16);
void l2c_csm_term_w4_sec_comp(void *p_ccb, u16 event, BT_HDR *p_msg)
{
    u16 offset = event - 3;
    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, lbl_80318580, event);
    if (offset > 0x1A)
        return;
    switch (event) {
    case 3:
        btm_sec_abort_access_req(*(BD_ADDR *)((u8 *)p_ccb + 0x10));
        l2cu_release_ccb(p_ccb);
        break;
    case 7:
        *(u32 *)((u8 *)p_ccb + 4) = 4;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x3C);
        if (lbl_803C4040[0] >= 3) {
            fn_80070954(0x80002, lbl_803185A8, *(u16 *)((u8 *)p_ccb + 0x14));
            {
                u8 *p = *(u8 **)((u8 *)p_ccb + 0x30);
                void (*fn)(void *, u16, u16, u8) = *(void (**)(void *, u16, u16, u8))(p + 4);
                fn((u8 *)*(void **)((u8 *)p_ccb + 0x10) + 0x2A,
                   *(u16 *)((u8 *)p_ccb + 0x14), *(u16 *)(p + 2),
                   *((u8 *)p_ccb + 0x36));
            }
        }
        break;
    case 8:
        l2cu_send_peer_connect_rsp(p_ccb, 3, 0);
        l2cu_release_ccb(p_ccb);
        break;
    case 17:
        GKI_freebuf(p_msg);
        break;
    case 19:
        l2cu_release_ccb(p_ccb);
        break;
    case 26:
        l2cu_send_peer_disc_rsp(*(void **)((u8 *)p_ccb + 0x10),
            *((u8 *)p_ccb + 0x36), *(u16 *)((u8 *)p_ccb + 0x14),
            *(u16 *)((u8 *)p_ccb + 0x16));
        btm_sec_abort_access_req(*(BD_ADDR *)((u8 *)p_ccb + 0x10));
        l2cu_release_ccb(p_ccb);
        break;
    }
}

extern char lbl_803183B0[];
void l2c_csm_w4_l2cap_connect_rsp(void *p_ccb, u16 event, BT_HDR *p_msg)
{
    void *p_lcb = *(void **)((u8 *)p_ccb + 0x30);
    void (*cb1)(u16, u16) = *(void (**)(u16, u16))((u8 *)p_lcb + 0x18);
    void (*cb2)(u16, u16) = *(void (**)(u16, u16))((u8 *)p_lcb + 8);
    u16 local_cid = *(u16 *)((u8 *)p_ccb + 0x14);
    if (lbl_803C4040[0] >= 4) fn_80070954(0x80003, lbl_803183B0 + 0x294, event);
    if ((u16)(event - 3) > 0x1A) return;
    switch (event) {
    case 3:
        *(u32 *)((u8 *)p_ccb + 4) = 0;
        if (lbl_803C4040[0] >= 3) fn_80070954(0x80002, lbl_803183B0 + 0x40, local_cid);
        l2cu_release_ccb(p_ccb); cb1(local_cid, 0); break;
    case 7:
        *(u16 *)((u8 *)p_ccb + 0x16) = *(u16 *)((u8 *)p_msg + 0xE);
        *(u32 *)((u8 *)p_ccb + 4) = 5;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        if (lbl_803C4040[0] >= 3) fn_80070954(0x80002, lbl_803183B0 + 0x2BC, local_cid);
        cb2(local_cid, 0); break;
    case 8:
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x78);
        if (*(u32 *)((u8 *)p_lcb + 0xC)) {
            if (lbl_803C4040[0] >= 3) fn_8007093C(0x80002, lbl_803183B0 + 0x2F4);
            ((void (*)(u16,u16))*(void **)((u8 *)p_lcb+0xC))(0,0);
        } break;
    case 9:
        if (lbl_803C4040[0] >= 3) fn_8007096C(0x80002, lbl_803183B0 + 0x318, local_cid, *(u16 *)((u8 *)p_msg+0xA));
        l2cu_release_ccb(p_ccb); cb1(local_cid, *(u16 *)((u8 *)p_msg+0xA)); break;
    case 10:
        if (lbl_803C4040[0] >= 3) fn_80070954(0x80002, lbl_803183B0 + 0x358, local_cid);
        l2cu_release_ccb(p_ccb); cb2(local_cid, 0xEEEF); break;
    case 17: GKI_freebuf(p_msg); break;
    default: l2cu_release_ccb(p_ccb);
    }
}

extern char lbl_80318B28[];
extern char lbl_803183F0[];
void l2c_csm_w4_l2ca_disconnect_rsp(void *p_ccb, u16 event, void *p_data)
{
    void *r31;
    u16 local_cid;
    u16 offset;
    r31 = *(void **)((u8 *)(*(void **)((u8 *)p_ccb + 0x30)) + 0x18);
    local_cid = *(u16 *)((u8 *)p_ccb + 0x14);
    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, lbl_80318B28, event);
    offset = event - 3;
    if (offset > 0x1A)
        return;
    switch (event)
    {
    case 3:
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, lbl_803183F0, local_cid);
        l2cu_release_ccb(p_ccb);
        ((void (*)(u16, u8))r31)(local_cid, 0);
        break;
    case 7:
        l2cu_send_peer_disc_rsp(*(void **)((u8 *)p_ccb + 0x10),
            *((u8 *)p_ccb + 0x36), local_cid, *(u16 *)((u8 *)p_ccb + 0x16));
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, lbl_803183F0, local_cid);
        l2cu_release_ccb(p_ccb);
        ((void (*)(u16, u8))r31)(local_cid, 0);
        break;
    case 8:
    case 9:
        l2cu_send_peer_disc_rsp(*(void **)((u8 *)p_ccb + 0x10),
            *((u8 *)p_ccb + 0x36), local_cid, *(u16 *)((u8 *)p_ccb + 0x16));
        l2cu_release_ccb(p_ccb);
        break;
    case 17:
    case 19:
        GKI_freebuf(p_data);
        break;
    }
}

void l2c_link_sec_comp(BD_ADDR bd_addr, void *ref_data, UINT8 status)
{
    u8 addr[6];
    void *lcb;
    void *ccb;
    u8 state;
    u8 status_copy = status;
    memcpy(addr, bd_addr, 6);
    lcb = l2cu_find_lcb_by_bd_addr(bd_addr);
    if (lcb == 0) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80318C8C);
    } else {
        state = status ? 8 : 7;
        ccb = *(void **)((u8 *)lcb + 8);
        while (ccb != 0) {
            void *next = *(void **)((u8 *)ccb + 8);
            fn_80089E40(ccb, state, addr);
            ccb = next;
        }
    }
}

extern void *l2cu_find_lcb_by_handle(u16 handle);
s32 l2c_link_hci_qos_violation(u16 handle) {
    void *lcb = l2cu_find_lcb_by_handle(handle);
    void *ccb;
    if (lcb == 0) return 0;
    ccb = *(void **)((u8 *)lcb + 8);
    while (ccb != 0) {
        if (*(void **)((u8 *)*(void **)((u8 *)ccb + 0x30) + 0x20) != 0)
            fn_80089E40(ccb, 6, 0);
        ccb = *(void **)((u8 *)ccb + 8);
    }
    return 1;
}

extern char lbl_80318D98[];
void l2c_link_adjust_allocation(void) {
    u8 *base = lbl_803C4040;
    u8 *entry;
    s32 active = 0;
    s32 i;
    u16 allocation, value;
    if (*(u16 *)(base + 0x7B8) == 0) return;
    if (base[8] != 0 && base[0x62] == 1) active = 1;
    if (base[0x64] != 0 && base[0xBE] == 1) active++;
    if (base[0xC0] != 0 && base[0x11A] == 1) active++;
    if (base[0x11C] != 0 && base[0x176] == 1) active++;
    allocation = *(u16 *)(base + 2) / *(u16 *)(base + 0x7B8) + 1;
    entry = base + 8;
    for (i = 0; i < 4; i++, entry += 0x5C) {
        if (entry[0] != 0) {
            if (active == 0 || entry[0x5A] == 1) {
                *(u16 *)(entry + 0x34) = allocation;
                *(u16 *)(entry + 0x36) = allocation;
            } else {
                *(u16 *)(entry + 0x34) = 3;
                *(u16 *)(entry + 0x36) = 3;
            }
            value = *(u16 *)(entry + 0x34) * 120 / 100;
            *(u16 *)(entry + 0x3A) = value;
            *(u16 *)(entry + 0x3C) = value < 3 ? 3 - value : 0;
            *(u16 *)(entry + 0x3E) = value + 2;
            if (base[0] >= 5)
                fn_800709CC(0x80004, lbl_80318D98, i, entry[0x5A],
                            *(u16 *)(entry + 0x36), value,
                            *(u16 *)(entry + 0x3C), *(u16 *)(entry + 0x3E));
        }
    }
}

void fn_8008C04C(s16 arg0) {
    *(s16 *)(lbl_803C4040 + 2) = arg0;
    *(s16 *)(lbl_803C4040 + 4) = arg0;
}

BOOL l2cap_link_chk_pkt_end(void) {
    u8 *p_lcb;
    u8 *p_buf;
    u8 *p_data;
    u16 offset, len;
    u8 hi, lo;
    u16 l2cap_len;
    p_lcb = *(u8 **)(lbl_803C4040 + 0x7BC);
    if (p_lcb != 0) {
        p_buf = *(u8 **)(p_lcb + 0x50);
        if (p_buf != 0) {
            offset = *(u16 *)(p_buf + 4);
            len = *(u16 *)(p_buf + 2);
            p_data = p_buf + offset;
            hi = p_data[0x0D];
            lo = p_data[0x0C];
            l2cap_len = (u16)(lo + (hi << 8));
            if (l2cap_len > len - 8) return FALSE;
            *(u8 **)(p_lcb + 0x50) = 0;
        }
    }
    return TRUE;
}

void l2c_link_role_changed(u8 *bd_addr, u8 new_role) {
    u8 *p_lcb, *entry;
    s32 i;
    p_lcb = l2cu_find_lcb_by_bd_addr(bd_addr);
    if (p_lcb != 0) p_lcb[0x30] = new_role;
    for (i = 0, entry = lbl_803C4040 + 8; i < 4; i++, entry += 0x5C)
        if (entry[0] != 0 && *(s32 *)(entry + 4) == 2) l2cu_create_conn_after_switch(entry);
}

void l2c_link_role_change_failed(void) {
    u8 *entry;
    s32 i;
    for (i = 0, entry = lbl_803C4040 + 8; i < 4; i++, entry += 0x5C)
        if (entry[0] != 0 && *(s32 *)(entry + 4) == 2) l2cu_create_conn_after_switch(entry);
}

void fn_8008C464(u8 *bd_addr) {
    void *lcb = l2cu_find_lcb_by_bd_addr(bd_addr);
    if (lcb != 0 && *(u32 *)((u8 *)lcb + 8) == 0)
        btu_start_timer((u8 *)lcb + 0x10, 2, 0x78);
}

void l2c_process_timeout(void *arg) {
    u16 event = *(u16 *)((u8 *)arg + 0x14);
    if (event == 4) l2c_process_held_packets(1);
    else if (event == 2) l2c_link_timeout(*(void **)((u8 *)arg + 0x10));
    else if (event > 2 && event < 4) fn_80089E40(*(void **)((u8 *)arg + 0x10), 0x1E, 0);
    else if (event == 0x49) return;
}

extern u8 lbl_803C4040[];
extern void *l2cu_find_lcb_by_bd_addr(u8 *addr);
extern void l2cu_create_conn_after_switch(void *p_lcb);
void *l2cu_find_lcb_by_bd_addr(u8 *addr) {
    int i = 0;
    u8 *lcb = lbl_803C4040 + 8;
    while (i < 4) {
        if (lcb[0] && memcmp(lcb + 0x2A, addr, 6) == 0) return lcb;
        lcb += 0x5C;
        i++;
    }
    return 0;
}

void *l2cu_find_lcb_by_handle(u16 handle) {
    u8 *p = lbl_803C4040;
    if (*(p += 8) != 0 && *(u16 *)(p + 0x28) == handle) return p;
    if (*(p += 0x5C) != 0 && *(u16 *)(p + 0x28) == handle) return p;
    if (*(p += 0x5C) != 0 && *(u16 *)(p + 0x28) == handle) return p;
    if (*(p += 0x5C) != 0 && *(u16 *)(p + 0x28) == handle) return p;
    return 0;
}

u8 fn_8008D7C4(void) { return lbl_803C4040[1]; }

void *l2cu_build_header(u16 arg0, u8 arg1, u8 arg2, s32 arg3) {
    BT_HDR *buf = GKI_getpoolbuf(2);
    u8 *p;
    if (buf == NULL) return NULL;
    buf->len = arg1 + 0xC;
    buf->offset = 0;
    p = (u8 *)(buf + 1);
    p[0] = arg0 | 0x2000;
    p[1] = (arg0 | 0x2000) >> 8;
    p[2] = arg1 + 8;
    p[3] = (arg1 + 8) >> 8;
    p[4] = arg1 + 4;
    p[5] = (arg1 + 4) >> 8;
    p[6] = 1;
    p[7] = 0;
    p[8] = arg2;
    p[9] = arg3;
    p[10] = arg1;
    p[11] = arg3 >> 8;
    return buf;
}

void l2cu_send_peer_connect_req(void *arg0) {
    void *p;
    extern void *l2cu_build_header(u16, u8, u8, s32);
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    extern void fn_8007093C(u32, void *);
    extern char lbl_80319174[];
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x10) + 0x31) += 1;
    *(u8 *)((u8 *)arg0 + 0x35) = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x10) + 0x31);
    p = l2cu_build_header(*(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x10) + 0x28), 4, 2, *(u8 *)((u8 *)arg0 + 0x35));
    if (p == 0) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80319174);
    } else {
        *(u8 *)((u8 *)p + 0x14) = *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 2);
        *(u8 *)((u8 *)p + 0x15) = *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 2) >> 8;
        *(u8 *)((u8 *)p + 0x16) = *(u16 *)((u8 *)arg0 + 0x14);
        *(u8 *)((u8 *)p + 0x17) = *(u16 *)((u8 *)arg0 + 0x14) >> 8;
        l2c_link_check_send_pkts(*(void **)((u8 *)arg0 + 0x10), 0, p, 0);
    }
}

void l2cu_send_peer_echo_rsp(void *arg0, s32 arg1, u8 *arg2, u32 arg3) {
    extern void *l2cu_build_header(u16, u8, u8, s32);
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    extern void fn_8007093C(u32, void *);
    extern char lbl_80319174[];
    u32 length = arg3;
    u16 limit;
    void *packet;
    u8 *dst;
    u32 i;
    if (*(u16 *)(lbl_803C0A50 + 0x7E) < 0x294)
        limit = *(u16 *)(lbl_803C0A50 + 0x7C);
    else
        limit = 0x294;
    if (length > (u16)(limit - 0xC))
        length = 0;
    packet = l2cu_build_header(*(u16 *)((char *)arg0 + 0x28), (u8)length, 9, arg1);
    if (packet == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_80319174);
    } else {
        dst = (u8 *)packet + 0x14;
        for (i = 0; i < length; i++) dst[i] = arg2[i];
        l2c_link_check_send_pkts(arg0, 0, packet, 0);
    }
}

extern void *l2cu_build_header(u16, u8, u8, s32);
extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
extern void fn_8007093C(u32, void *);
extern char lbl_80319174[];
void l2cu_send_peer_info_rsp(void *arg0, s32 arg1, u16 arg2) {
    void *p;
    u8 flag = 1;
    p = l2cu_build_header(*(u16 *)((u8 *)arg0 + 0x28), 4, 0xb, arg1);
    if (p == 0) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80319174);
    } else {
        *(u8 *)((u8 *)p + 0x14) = arg2;
        *((u8 *)p + 0x15) = arg2 >> 8;
        *((u8 *)p + 0x16) = flag;
        *((u8 *)p + 0x17) = 0;
        l2c_link_check_send_pkts(arg0, 0, p, flag);
    }
}

void *l2cu_find_ccb_by_cid(void *p_lcb, u16 cid) {
    u8 *p_ccb = 0;
    if (cid >= 0x40) {
        p_ccb = lbl_803C4040 + 0x178 + (((u16)(cid - 0x40)) * 0x7c);
        if (p_ccb[0] == 0)
            p_ccb = 0;
        else if (p_lcb != 0 && p_lcb != *(void **)(p_ccb + 0x10))
            p_ccb = 0;
    }
    return p_ccb;
}

void *fn_8008EBE4(s16 psm) {
    u8 *p_rcb = lbl_803C4040 + 0x650;
    int i;
    for (i = 0; i < 8; i++) {
        if (p_rcb[0] == 0) {
            p_rcb[0] = 1;
            *(s16 *)(p_rcb + 2) = psm;
            return p_rcb;
        }
        p_rcb += 0x2c;
    }
    return 0;
}

void fn_8008EC30(void *arg0) {
    *(u8 *)arg0 = 0;
    *(u16 *)((u8 *)arg0 + 2) = 0;
}

void *l2cu_find_rcb_by_psm(u16 psm) {
    u8 *p_rcb = lbl_803C4040 + 0x650;
    int i;
    for (i = 0; i < 8; i++) {
        if (p_rcb[0] != 0 && *(u16 *)(p_rcb + 2) == psm)
            return p_rcb;
        p_rcb += 0x2c;
    }
    return 0;
}

void l2cu_process_peer_cfg_req(void *arg0, void *arg1) {
    int var_r0, var_r3, var_r6 = 1, var_r7 = 1, var_r8 = 1;
    unsigned short temp_r0;
    unsigned char *a = (unsigned char *)arg0;
    unsigned char *b = (unsigned char *)arg1;
    if (b[2]) {
        temp_r0 = *(unsigned short *)(b + 4);
        if (temp_r0 >= 0x30) {
            *(unsigned short *)(a + 0x3A) = temp_r0;
            if (temp_r0 > 0x69B) {
                *(unsigned short *)(b + 4) = 0x69B;
                *(unsigned short *)(a + 0x3A) = 0x69B;
            }
        } else { var_r6 = 0; *(unsigned short *)(b + 4) = 0x30; }
    }
    if (b[0x20] && !*(unsigned short *)(b + 0x22)) {
        var_r8 = 0; *(unsigned short *)(b + 0x22) = 0xFFFF;
    }
    if (b[6]) {
        if (b[9] <= 2) {
            struct Copy { unsigned int w[6]; };
            *(struct Copy *)(a + 0x40) = *(struct Copy *)(b + 8);
        } else { var_r7 = 0; b[9] = 1; }
    }
    var_r3 = 0; var_r0 = 0;
    if (var_r6 && var_r8 && var_r7) var_r0 = 1;
    if (var_r0) var_r3 = 1;
    if (!var_r3) {
        *(short *)b = 1;
        if (var_r6) b[2] = 0;
        if (var_r8) b[0x20] = 0;
        if (var_r7) b[6] = 0;
        *(signed char *)(b + 0x24) = 0;
    }
}

void fn_8008EE40(void *arg0, void *arg1) {
    struct Pair { u32 x; u32 y; };
    u8 *dst = (u8 *)arg0; u8 *src = (u8 *)arg1;
    if (src[6] != 0) {
        *(struct Pair *)(dst + 0x58) = *(struct Pair *)(src + 8);
        *(struct Pair *)(dst + 0x60) = *(struct Pair *)(src + 0x10);
        *(struct Pair *)(dst + 0x68) = *(struct Pair *)(src + 0x18);
    }
}

void fn_8008EF90(void *arg0, void *arg1) {
    struct Pair { u32 first; u32 second; };
    u8 *dst = (u8 *)arg0;
    u8 *src = (u8 *)arg1;
    if (src[6] != 0) {
        *(struct Pair *)(dst + 0x40) = *(struct Pair *)(src + 8);
        *(struct Pair *)(dst + 0x48) = *(struct Pair *)(src + 0x10);
        *(struct Pair *)(dst + 0x50) = *(struct Pair *)(src + 0x18);
    }
}

void l2cu_device_reset(void) {
    s32 i;
    u8 *entry;
    for (i = 0, entry = lbl_803C4040 + 8; i < 4; i++, entry += 0x5C) {
        if (entry[0] && *(u16 *)(entry + 0x28) != 0xFFFF)
            l2c_link_hci_disc_comp(*(u16 *)(entry + 0x28), 0xFF);
    }
}

void *l2cu_find_lcb_by_state(s32 state) {
    u8 *entry = lbl_803C4040;
    entry += 7;
    if (*++entry && *(s32 *)(entry + 4) == state) return entry;
    entry += 0x5B;
    if (*++entry && *(s32 *)(entry + 4) == state) return entry;
    entry += 0x5B;
    if (*++entry && *(s32 *)(entry + 4) == state) return entry;
    entry += 0x5B;
    if (*++entry && *(s32 *)(entry + 4) == state) return entry;
    return 0;
}

extern void RFCOMM_DlcEstablishReq(void *, u8);
extern char lbl_80319300[];
void PORT_ParNegCnf(void *arg0, u8 arg1, u16 arg2, u8 arg3, u8 arg4) {
    void *port;
    u8 *mcb;
    port = port_find_mcb_dlci_port(arg0, arg1);
    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, u8, u16, u8, u8))fn_8007099C)(0x90003, lbl_80319300, arg1, arg2, arg3, arg4);
    if (port == 0) return;
    mcb = (u8 *)port;
    if (*((u8 *)arg0 + 0x72) == 0) {
        if (arg3 == 0xE0) *((u8 *)arg0 + 0x72) = 2;
        else *((u8 *)arg0 + 0x72) = 1;
    }
    if (*(u16 *)(mcb + 0x12) < arg2) arg2 = *(u16 *)(mcb + 0x12);
    *(u16 *)(mcb + 0x12) = arg2;
    *(u16 *)(mcb + 0x14) = arg2;
    if (*((u8 *)arg0 + 0x72) == 2) {
        *(s16 *)(mcb + 0x98) = arg4;
        if (arg4 == 0) mcb[0x24] = 1;
    }
    if (mcb[2] == 1) ((void (*)(void *, u8, u16))RFCOMM_DlcEstablishReq)(arg0, mcb[0xD], *(u16 *)(mcb + 0x12));
}

void PORT_DlcEstablishInd(s32 arg0, s32 arg1, s32 arg2) {
    extern char lbl_8031932C[];
    extern void *port_find_dlci_port(unsigned int);
    extern void rfc_timer_stop(void *);
    extern void RFCOMM_DlcEstablishRsp(void *, u8, s32, u16);
    void (*rsp)(s32, s32, s32, s32) = (void (*)(s32, s32, s32, s32))RFCOMM_DlcEstablishRsp;
    void (*logfn)(s32, void *, s32, s32) = (void (*)(s32, void *, s32, s32))fn_8007096C;
    u8 *port;
    void *(*find_mcb)(void) = (void *(*)(void))port_find_mcb_dlci_port;
    port = (u8 *)find_mcb();
    if (lbl_803C4828[0x414] >= 4) logfn(0x90003, lbl_8031932C, arg1, arg2);
    if (port == 0) {
        port = (u8 *)port_find_dlci_port(arg1);
        if (port == 0) {
            rsp(arg0, arg1, 0, 1);
            return;
        }
        *(u8 *)(arg0 + arg1 + 0x24) = port[0];
    }
    if (arg2 != 0 && (u32)arg2 < *(u16 *)(port + 0x14)) *(u16 *)(port + 0x14) = (u16)arg2;
    rfc_timer_stop((void *)arg0);
    rsp(arg0, arg1, *(u16 *)(port + 0x12), 0);
    if (*(void (**)(s32,u8))(port + 0x8c) != 0 && (*(u32 *)(port + 0x88) & 0x200))
        (*(void (**)(s32,u8))(port + 0x8c))(0x200, port[0]);
    if (*(void (**)(s32,u8))(port + 0x90) != 0) (*(void (**)(s32,u8))(port + 0x90))(0, port[0]);
    port[2] = 2;
}

void PORT_ControlCnf(void *mcb, u8 dlci, void *pars) {
    extern char lbl_80319430[];
    extern u32 port_rfc_send_tx_data(void *);
    u8 *port = port_find_mcb_dlci_port(mcb, dlci);
    s32 event = 0;
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, lbl_80319430);
    if (port == 0)
        return;
    if (!(port[0x64] & 2)) {
        port[0x64] |= 2;
        if (port[0x64] & 4)
            event = *(u32 *)(port + 0x88) & 0x200;
    }
    if (port[0x64] & 4)
        event |= port_rfc_send_tx_data(port);
    if (event != 0 && *(void (**)(s32, u8))(port + 0x8c) != 0)
        (*(void (**)(s32, u8))(port + 0x8c))(event, port[0]);
}

void PORT_LineStatusInd(void *mcb, u8 dlci, u8 line_status) {
    extern char lbl_80319440[];
    u8 *port;
    s32 event;
    u32 mask;
    u8 value;

    port = (u8 *)port_find_mcb_dlci_port(mcb, dlci);
    event = 0;
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, lbl_80319440);
    if (port != 0) {
        value = port[0xF];
        port[0xF] = value | line_status;
        if (line_status & 2)
            event |= 0x2000;
        if (line_status & 1)
            event |= 0x40;
        if (line_status & 0xFC)
            event |= 0x80;
        if (*(void (**)(s32, u8))(port + 0x8C) != 0) {
            mask = *(u32 *)(port + 0x88);
            if (mask & event)
                (*(void (**)(s32, u8))(port + 0x8C))(mask & event, port[0]);
        }
    }
}

void PORT_CloseInd(void *arg0) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319468[];
    extern void fn_8007093C(u32, void *);
    extern void port_rfc_closed(void *, s32);
    extern void rfc_release_multiplexer_channel(void *);
    u8 *entry;
    s32 i;

    if (lbl_803C4828[0x414] >= 4) fn_8007093C(0x90003, lbl_80319468);
    for (i = 0, entry = lbl_803C4828 + 0x68; i < 5; i++, entry += 0xA4)
        if (*(void **)(entry + 0x6C) == arg0) port_rfc_closed(entry, 0x10);
    rfc_release_multiplexer_channel(arg0);
}

void Port_TimeOutCloseMux(void *arg0) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319478[];
    extern void fn_8007093C(u32, void *);
    extern void port_rfc_closed(void *, s32);
    u8 *entry;
    s32 i;

    if (lbl_803C4828[0x414] >= 4) fn_8007093C(0x90003, lbl_80319478);
    for (i = 0, entry = lbl_803C4828 + 0x68; i < 5; i++, entry += 0xA4)
        if (*(void **)(entry + 0x6C) == arg0) port_rfc_closed(entry, 0x12);
}

void *port_find_mcb_dlci_port(void *mcb, u8 dlci) {
    u8 index;
    if (mcb == 0) {
        return 0;
    }
    if (dlci > 0x3D) {
        return 0;
    }
    index = *((u8 *)mcb + dlci + 0x24);
    if (index == 0) {
        return 0;
    }
    return lbl_803C4828 + (index - 1) * 0xA4 + 0x68;
}

void *port_find_dlci_port(unsigned int arg0) {
    unsigned short i;
    unsigned int odd = arg0 & 1;
    unsigned int prev = arg0 - 1;
    char *base = (char *)&lbl_803C4828;
    for (i = 0; i < 5; i++) {
        char *entry = base + (i * 0xA4);
        char *port = entry + 0x68;
        unsigned char dlci;
        if (*(unsigned char *)(entry + 0x69) == 0) continue;
        if (*(unsigned int *)(port + 0x6C) != 0) continue;
        dlci = *(unsigned char *)(port + 0xD);
        if ((unsigned int)dlci == arg0) return port;
        if (odd != 0 && (int)dlci == (int)prev) {
            *(unsigned char *)(port + 0xD) = dlci + 1;
            return port;
        }
    }
    return 0;
}

int port_flow_control_user(void *arg0) {
    void *temp_r4;
    unsigned char var_r5 = 0;
    if (*((unsigned char *)arg0 + 0x24) == 0) {
        temp_r4 = *(void **)((char *)arg0 + 0x6c);
        if (temp_r4 != 0 && *((unsigned char *)temp_r4 + 0x71) != 0 &&
            *(unsigned int *)((char *)arg0 + 0x28) <= 0x1f40 &&
            *(unsigned short *)((char *)arg0 + 0x20) > 0x10) {
            var_r5 = 1;
        }
    }
    if (*((unsigned char *)arg0 + 0x25) == var_r5) return 0;
    *((unsigned char *)arg0 + 0x25) = var_r5;
    if (var_r5 != 0) return 0x10000;
    return 0x30000;
}

int port_get_signal_changes(void *arg0, int arg1, int arg2) {
    int changed = arg2 ^ arg1;
    int signals = 0;
    if (changed & 1) {
        signals |= 0x10;
        if (arg2 & 1) signals |= 0x800;
    }
    if (changed & 2) {
        signals |= 8;
        if (arg2 & 2) signals |= 0x400;
    }
    if (changed & 4) signals |= 0x100;
    if (changed & 8) {
        signals |= 0x20;
        if (arg2 & 8) signals |= 0x1000;
    }
    return *((int *)((char *)arg0 + 0x88)) & signals;
}

void fn_800911DC(void) {

}

void fn_800916D8(void *callback, u32 cid) {
    u32 index = cid - 0x40;
    u8 *base = lbl_803C4828;
    *(void **)(base + 0x3C + index * 4) = callback;
}

void rfc_mx_sm_state_connected(void *arg0, s32 arg1, void *arg2) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319868[];
    extern char lbl_803199B8[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void rfc_timer_start(void *, u16);
    extern void rfc_send_disc(void *, s32, void *);
    extern void rfc_send_ua(void *, s32, void *);
    extern void PORT_CloseInd(void *);

    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, lbl_803199B8, arg1);
    switch (arg1) {
    case 5:
    case 8:
        rfc_timer_start(arg0, 3);
        *(u8 *)((u8 *)arg0 + 0x6C) = 6;
        ((void (*)(void *, s32))rfc_send_disc)(arg0, 0);
        return;
    case 14:
        *(u8 *)((u8 *)arg0 + 0x6C) = 0;
        PORT_CloseInd(arg0);
        return;
    case 3:
        ((void (*)(void *, s32))rfc_send_ua)(arg0, 0);
        if (*(u8 *)((u8 *)arg0 + 0x6D)) L2CA_DisconnectReq(*(u16 *)((u8 *)arg0 + 0x68));
        PORT_CloseInd(arg0);
        return;
    default:
        if (lbl_803C4828[0x414] >= 4)
            ((void (*)(u32, void *, s32, u16))fn_8007096C)(0x90003, lbl_80319868, arg1, *(u8 *)((u8 *)arg0 + 0x6C));
        return;
    }
}

void rfc_mx_conf_cnf(void *arg0, u16 *arg1) {
    extern void PORT_StartCnf(void *, u16);
    extern void rfc_release_multiplexer_channel(void *);
    extern void rfc_send_sabme(void *, s32, void *);
    extern char lbl_80319A70[];
    void (*start)(void *, u16) = PORT_StartCnf;
    void (*disconnect)(u16) = (void (*)(u16))L2CA_DisconnectReq;
    void (*release)(void *) = rfc_release_multiplexer_channel;
    void (*sabme)(void *, u8) = (void (*)(void *, u8))rfc_send_sabme;
    u8 *p = (u8 *)arg0;
    if (lbl_803C4828[0x414] >= 4) {
        void (*logfn)(u32, void *, void *, u16) = (void (*)(u32, void *, void *, u16))fn_8007096C;
        logfn(0x90003, lbl_80319A70, arg1, arg1 ? *arg1 : 0);
    }
    if (*arg1 != 0) {
        if (p[0x6D] != 0) {
            start(arg0, 0);
            disconnect(*(u16 *)(p + 0x68));
        }
        release(arg0);
        return;
    }
    p[0x6E] = 1;
    if (p[0x6C] == 2 && p[0x6F] != 0) {
        if (p[0x6D] != 0) {
            p[0x6C] = 3;
            sabme(arg0, 0);
        } else {
            p[0x6C] = 4;
        }
    }
}

void rfc_port_sm_state_closed(void *p_port, u16 event, void *p_data) {
    extern char lbl_80319AC4[];
    extern char lbl_80319AE4[];
    extern void rfc_sec_check_complete(void *, void *, s8);
    extern void rfc_port_closed(void *);
    extern void rfc_send_dm(void *, u8, u8);
    extern void Port_TimeOutCloseMux(void *);
    u8 *port = (u8 *)p_port;
    switch (event) {
    case 9:
        port[0x68] = 2;
        btm_sec_mx_access_request(*(u8 **)(port + 0x6C) + 0x62, 3, 1, 3, (u32)(port[0xD] / 2),
                                  (tBTM_SEC_CALLBACK *)rfc_sec_check_complete, p_port);
        return;
    case 12:
        break;
    case 13:
        return;
    case 14:
        GKI_freebuf(p_data);
        break;
    case 0:
        port[0x68] = 3;
        btm_sec_mx_access_request(*(u8 **)(port + 0x6C) + 0x62, 3, 0, 3, (u32)(port[0xD] / 2),
                                  (tBTM_SEC_CALLBACK *)rfc_sec_check_complete, p_port);
        return;
    case 1:
        return;
    case 2:
        rfc_port_closed(p_port);
        return;
    case 4:
        GKI_freebuf(p_data);
        rfc_send_dm(*(void **)(port + 0x6C), port[0xD], 0);
        return;
    case 3:
        rfc_send_dm(*(void **)(port + 0x6C), port[0xD], 0);
        return;
    case 5:
        Port_TimeOutCloseMux(*(void **)(port + 0x6C));
        if (lbl_803C4828[0x414] >= 1)
            fn_8007096C(0x90000, lbl_80319AC4, port[0x68], event);
        return;
    }
    if (lbl_803C4828[0x414] >= 2)
        fn_80070954(0x90001, lbl_80319AE4, event);
}

void rfc_port_sm_orig_wait_sec_check(void *port, u16 event, void *data) {
    extern char lbl_80319AB0[];
    extern void rfc_send_sabme(void *, s32, void *);
    extern void rfc_port_closed(void *);
    u8 *p = port;
    char *messages = lbl_80319AB0;
    switch (event) {
    case 15:
        if (*(u8 *)data != 0) {
            PORT_DlcEstablishCnf(*(void **)(p + 0x6C), p[0xD], 0, 0x70);
            rfc_port_closed(port);
            return;
        }
        ((void (*)(void *, u8))rfc_send_sabme)(*(void **)(p + 0x6C), p[0xD]);
        rfc_port_timer_start(port, 0x3C);
        p[0x68] = 1;
        return;
    case 9:
    case 0:
        if (lbl_803C4828[0x414] >= 1) fn_8007096C(0x90000, messages + 0x14, p[0x68], event);
        return;
    case 12:
        btm_sec_abort_access_req((u8 *)*(void **)(p + 0x6C) + 0x62);
        rfc_port_closed(port);
        return;
    case 14:
        if (lbl_803C4828[0x414] >= 1) fn_8007093C(0x90000, messages + 0x198);
        GKI_freebuf(data);
        return;
    case 4:
        GKI_freebuf(data);
        return;
    }
    if (lbl_803C4828[0x414] >= 2) fn_80070954(0x90001, messages + 0x1C8, event);
}

void rfc_port_sm_disc_wait_ua(void *p_port, s32 event, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319AC4[];
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void rfc_port_closed(void *);
    extern void GKI_freebuf(void *);
    extern void rfc_send_dm(void *, u8, u8);

    u8 *port = (u8 *)p_port;
    u8 dlci = port[0xD];

    if (event < 0xF) {
        switch (event) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        }
    }
    if (lbl_803C4828[0x414] > 1)
        fn_8007096C(0x9, lbl_80319AC4, port[0x68], event);
}

void PORT_ParNegInd(void *, u8, u16, u8, u8);
void PORT_ParNegCnf(void *, u8, u16, u8, u8);
  void rfc_send_dm(void *, u8, BOOLEAN);
void rfc_port_timer_stop(void *);
void *port_find_mcb_dlci_port(void *, u8);
extern u8 lbl_80319DB0[];
void rfc_process_pn(void *arg0, s32 arg1, void *arg2) {
    u8 dlci = *(u8 *)arg2;
    void *mcb;
    u8 flag;
    if (arg1 != 0) {
        if (*(u8 *)((u8 *)arg0 + 0x6C) != 6) {
            PORT_ParNegInd(arg0, dlci, *(u16 *)((u8 *)arg2 + 0xE), *(u8 *)((u8 *)arg2 + 0xA), *(u8 *)((u8 *)arg2 + 0x11));
        } else {
            rfc_send_dm(arg0, dlci, 0);
            if (lbl_803C4828[0x414] >= 2) fn_8007093C(0x90001, lbl_80319DB0);
        }
    } else {
        mcb = port_find_mcb_dlci_port(arg0, dlci);
        if (mcb != 0) {
            flag = *(u8 *)((u8 *)mcb + 0x69);
            if ((flag & 1) != 0) {
                *(u8 *)((u8 *)mcb + 0x69) = flag & 0xFE;
                rfc_port_timer_stop(mcb);
                PORT_ParNegCnf(arg0, dlci, *(u16 *)((u8 *)arg2 + 0xE), *(u8 *)((u8 *)arg2 + 0xA), *(u8 *)((u8 *)arg2 + 0x11));
            }
        }
    }
}

void rfc_process_rls(void *arg0, s32 arg1, void *arg2) {
    void *mcb;

    if (arg1 != 0) {
        PORT_LineStatusInd(arg0, *(u8 *)arg2, *(u8 *)((u8 *)arg2 + 9));
        rfc_send_rls(arg0, *(u8 *)arg2, 0, *(u8 *)((u8 *)arg2 + 9));
        return;
    }
    mcb = port_find_mcb_dlci_port(arg0, *(u8 *)arg2);
    if (mcb == NULL || (*(u8 *)((u8 *)mcb + 0x69) & 0x10) == 0) {
        return;
    }
    *(u8 *)((u8 *)mcb + 0x69) &= 0xFFFFFFEF;
    rfc_port_timer_stop(mcb);
}

void fn_800932D8(void) {

}

void fn_800932DC(void *arg0, s32 arg1) {
    GKI_freebuf((void *)arg1);
}

void rfc_process_fcon(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        *(u8 *)(lbl_803C4828 + 0x64) = 0;
        rfc_send_fcon(arg0, 0, lbl_803C4828);
        if (*(u8 *)((u8 *)arg0 + 0x73) == 0) {
            PORT_FlowInd(arg0, 0, 1);
        }
    }
}

void rfc_process_fcoff(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        *(u8 *)(lbl_803C4828 + 0x64) = 1;
        if (*(u8 *)((u8 *)arg0 + 0x73) == 0) {
            PORT_FlowInd(arg0, 0, 0);
        }
        rfc_send_fcon_80093FDC(arg0, 0);
    }
}

void rfc_process_l2cap_congestion(void *arg0, s32 arg1) {
    *(u8 *)((u8 *)arg0 + 0x73) = (u8)arg1;
    if (arg1 == 0) {
        rfc_check_send_cmd(arg0, NULL);
    }
    if (*(u8 *)(lbl_803C4828 + 0x64) == 0) {
        if (arg1 == 0) {
            PORT_FlowInd(arg0, 0, 1);
        } else {
            PORT_FlowInd(arg0, 0, 0);
        }
    }
}

void rfc_set_port_state(void *arg0, void *arg1) {
    if (*(u16 *)((u8 *)arg1 + 0x12) & 1) {
        *(u8 *)arg0 = *(u8 *)((u8 *)arg1 + 0xA);
    }
    if (*(u16 *)((u8 *)arg1 + 0x12) & 2) {
        *(u8 *)((u8 *)arg0 + 1) = *(u8 *)((u8 *)arg1 + 0xB);
    }
    if (*(u16 *)((u8 *)arg1 + 0x12) & 4) {
        *(u8 *)((u8 *)arg0 + 2) = *(u8 *)((u8 *)arg1 + 0xC);
    }
    if (*(u16 *)((u8 *)arg1 + 0x12) & 8) {
        *(u8 *)((u8 *)arg0 + 3) = *(u8 *)((u8 *)arg1 + 0xD);
    }
    if (*(u16 *)((u8 *)arg1 + 0x12) & 0x10) {
        *(u8 *)((u8 *)arg0 + 4) = *(u8 *)((u8 *)arg1 + 0xE);
    }
    if (*(u16 *)((u8 *)arg1 + 0x12) & 0x3F00) {
        *(u8 *)((u8 *)arg0 + 5) = *(u8 *)((u8 *)arg1 + 0xF);
    }
    if (*(u16 *)((u8 *)arg1 + 0x12) & 0x20) {
        *(u8 *)((u8 *)arg0 + 7) = *(u8 *)((u8 *)arg1 + 0x10);
    }
    if (*(u16 *)((u8 *)arg1 + 0x12) & 0x40) {
        *(u8 *)((u8 *)arg0 + 8) = *(u8 *)((u8 *)arg1 + 0x11);
    }
}

void fn_800934D8(void *arg0, s16 arg1) {
    s16 sp8;

    sp8 = arg1;
    fn_800916F4(arg0, 7, &sp8);
}

void RFCOMM_DlcEstablishReq(void *arg0, u8 arg1) {
    void *port = port_find_mcb_dlci_port(arg0, arg1);
    if (*((u8 *)arg0 + 0x6C) != 5) {
        PORT_DlcEstablishCnf(arg0, arg1, 0, 1);
    } else {
        rfc_port_sm_execute(port, 9, 0);
    }
}

void RFCOMM_DlcEstablishRsp(void *arg0, u8 arg1, s32 arg2, u16 arg3) {
    u16 sp8 = arg3;
    void *port = port_find_mcb_dlci_port(arg0, arg1);
    if (*((u8 *)arg0 + 0x6C) != 5 && sp8 == 0) {
        PORT_DlcReleaseInd(arg0, arg1);
        return;
    }
    rfc_port_sm_execute(port, 0xB, &sp8);
}

void RFCOMM_ParNegReq(void *arg0, s32 arg1, s32 arg2) {
    u8 *port;
    u32 max_frame;
    u16 mtu;
    u16 frame;
    u8 value;
    u8 credits;

    port = ((u8 * (*)())port_find_mcb_dlci_port)();
    if (((u8 *)arg0)[0x6C] != 5) {
        port[0xE] = 0xD;
        return;
    }
    value = ((u8 *)arg0)[0x72];
    frame = 2;
    if ((s32)value != 0)
        frame = value;
    if ((u8)frame == 2) {
        mtu = *(u16 *)(port + 0x9C);
        max_frame = 0xF0;
        frame = 7;
        if (mtu < 7)
            frame = mtu;
        credits = (u8)frame;
        *(u16 *)(port + 0x9A) = credits;
    } else {
        max_frame = 0;
        credits = 0;
    }
    port[0x69] |= 1;
    rfc_send_pn(arg0, arg1, 1, arg2, max_frame, credits);
    rfc_port_timer_start(port, 0x3C);
}

void fn_800936BC(void *p, u16 a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6) {
    if (*((u8 *)p + 0x6C) == 5)
        rfc_send_pn(p, a1, a2, a3, a4, a5, a6);
}

void RFCOMM_PortNegReq(void *mcb, u8 dlci, void *pars) {
    void *port = port_find_mcb_dlci_port(mcb, dlci);
    if (*(u8 *)((u8 *)mcb + 0x6c) != 5) {
        PORT_PortNegCnf(mcb, dlci, 0, 1);
        return;
    }
    if (pars == NULL)
        *(u8 *)((u8 *)port + 0x69) |= 2;
    else
        *(u8 *)((u8 *)port + 0x69) |= 4;
    rfc_send_rpn(mcb, dlci, 1, pars, 0x3f7f);
    rfc_port_timer_start(port, 0x3c);
}

void fn_800937A0(void *p, u16 a1, u16 a2, u16 a3) {
    if (*(u8 *)((u8 *)p + 0x6c) == 5)
        rfc_send_rpn(p, a1, 0, a2, a3);
}

void RFCOMM_ControlReq(void *mcb, u8 dlci, void *ctrl) {
    void *port = port_find_mcb_dlci_port(mcb, dlci);
    if (*(u8 *)((u8 *)port + 2) == 2) {
        switch (*(u8 *)((u8 *)port + 0x68)) {
        case 4:
            *(u8 *)((u8 *)port + 0x64) |= 1;
            *(u8 *)((u8 *)port + 0x69) |= 8;
            rfc_send_msc(mcb, dlci, 1, ctrl);
            rfc_port_timer_start(port, 0x3c);
            break;
        default:
            break;
        }
    }
}

void RFCOMM_FlowReq(void *mcb, u8 dlci, u8 state) {
    u8 *port = port_find_mcb_dlci_port(mcb, dlci);
    if (port[2] != 2)
        goto done;
    if (port[0x68] == 4) {
        port[0x5e] = state == 0;
        port[0x69] |= 8;
        rfc_send_msc(mcb, dlci, 1, port + 0x5a);
        rfc_port_timer_start(port, 0x3c);
    } else {
        goto done;
    }
done:
    return;
}

void RFCOMM_LineStatusReq(void *arg0, u8 arg1, u8 arg2) {
    void *mcb = port_find_mcb_dlci_port(arg0, arg1);
    if (*((u8 *)mcb + 2) != 2) return;
    if (*((u8 *)mcb + 0x68) == 4) {
        *((u8 *)mcb + 0x69) |= 0x10;
        rfc_send_rls(arg0, arg1, 1, arg2);
        rfc_port_timer_start(mcb, 0x3C);
    } else {
        return;
    }
}

void fn_800939A0(void *arg0, u8 arg1) { rfc_port_sm_execute(port_find_mcb_dlci_port(arg0, arg1), 0xC, 0); }

void fn_800939CC(void *arg0, u8 arg1, void *arg2) { rfc_port_sm_execute(port_find_mcb_dlci_port(arg0, arg1), 0xE, arg2); }

void rfc_send_sabme(void *arg0, s32 arg1, void *arg2) { u8 *buf; u8 *frame; s32 flag; flag=1; if (*(u8 *)((u8 *)arg0+0x6D)==0) flag=0; buf=GKI_getpoolbuf(2); if(buf) { frame=buf+0x11; *(u16 *)(buf+4)=9; frame[0]=(flag<<1)|1|(arg1<<2); frame[1]=0x3F; frame[2]=1; frame[3]=fn_8009504C(3,frame,0x3F); *(u16 *)(buf+2)=4; rfc_check_send_cmd(arg0,buf); } }

void rfc_send_ua(void *arg0, s32 arg1, void *arg2) { u8 *buf; u8 *frame; s32 flag; flag=1; if (*(u8 *)((u8 *)arg0+0x6D)!=0) flag=0; buf=GKI_getpoolbuf(2); if(buf) { frame=buf+0x11; *(u16 *)(buf+4)=9; frame[0]=(flag<<1)|1|(arg1<<2); frame[1]=0x73; frame[2]=1; frame[3]=fn_8009504C(3,frame,0x73); *(u16 *)(buf+2)=4; rfc_check_send_cmd(arg0,buf); } }

void rfc_send_dm(void *arg0, u8 arg1, u8 arg2) {
    u8 *buf;
    u8 *data;
    s32 flag;

    flag = 1;
    if (((u8 *)arg0)[0x6D] != 0) {
        flag = 0;
    }
    buf = (u8 *)GKI_getpoolbuf(2);
    if (buf != 0) {
        *(u16 *)(buf + 4) = 9;
        data = buf + 0x11;
        data[0] = (u8)(((arg1 << 2) & 0x3FC) | ((flag << 1) & 0xFE) | 1);
        data[1] = (u8)((((-(s32)arg2 | arg2) >> 31) & 0x10) | 0xF);
        data[2] = 1;
        data[3] = fn_8009504C(3, data, data[0]);
        *(u16 *)(buf + 2) = 4;
        rfc_check_send_cmd(arg0, buf);
    }
}

void rfc_send_disc(void *arg0, s32 arg1, void *arg2) {
    u8 *buf;
    u8 *frame;
    s32 flag;
    flag = 1;
    if (*((u8 *)arg0 + 0x6D) == 0) flag = 0;
    buf = GKI_getpoolbuf(2);
    if (buf != 0) {
        frame = buf + 0x11;
        *(u16 *)(buf + 4) = 9;
        frame[0] = ((flag << 1) | 1) | (arg1 << 2);
        frame[1] = 0x53;
        frame[2] = 1;
        frame[3] = fn_8009504C(3, frame, 0x53);
        *(u16 *)(buf + 2) = 4;
        rfc_check_send_cmd(arg0, buf);
    }
}

void rfc_send_fcon(void *arg0, s32 arg1, void *arg2) {
    u8 *buf = GKI_getpoolbuf(2);
    if (buf != 0) {
        s32 sign = (-arg1 | arg1) >> 31;
        u16 field = 2;
        u8 enabled = 1;
        *(u16 *)(buf + 4) = 0xC;
        buf[0x14] = (u8)((sign & 2) | 0xA1);
        buf[0x15] = enabled;
        *(u16 *)(buf + 2) = field;
        rfc_send_buf_uih(arg0, 0, buf, 2);
    }
}

void rfc_send_fcon_80093FDC(void *arg0, s32 arg1) {
    u8 *buf;
    s32 temp;
    buf = GKI_getpoolbuf(2);
    if (buf != 0) {
        temp = -arg1;
        temp |= arg1;
        *(u16 *)(buf + 4) = 0xC;
        temp >>= 31;
        *(u16 *)(buf + 2) = 2;
        buf[0x14] = (u8)((temp & 2) | 0x61);
        buf[0x15] = 1;
        rfc_send_buf_uih(arg0, 0, buf, 2);
    }
}

void rfc_send_rls(void *arg0, u8 arg1, s32 arg2, u8 arg3) {
    u8 *buf = GKI_getpoolbuf(2);
    if (buf != 0) {
        s32 iVar;
        s32 iVar2;
        *(u16 *)(buf + 4) = 0xC;
        iVar = ((-arg2 | arg2) >> 31) & 2;
        iVar2 = (arg1 << 2) | 3;
        buf[0x14] = iVar | 0x51;
        buf[0x15] = 5;
        buf[0x16] = iVar2;
        buf[0x17] = arg3 | 1;
        *(u16 *)(buf + 2) = 4;
        rfc_send_buf_uih(arg0, 0, buf, buf[0x17], buf[0x16]);
    }
}

void rfc_send_test(s32 arg0, s32 arg1, void *p_buf) {
    u8 *p = p_buf;
    u16 len = *(u16 *)(p + 4);
    u16 count;
    u8 *src;
    u8 *dst;
    if (len < 0x10) {
        count = *(u16 *)(p + 2);
        src = p + len + count + 7;
        dst = p + count + 0x17;
        do {
            *dst-- = *src--;
        } while (++len < count);
        *(u16 *)(p + 4) = 0x10;
    }
    len = *(u16 *)(p + 4) - 2;
    *(u16 *)(p + 4) = len;
    p[len + 8] = (((-arg1 | arg1) >> 31) & 2) | 0x21;
    p[len + 9] = (*(u16 *)(p + 2) << 1) | 1;
    count = *(u16 *)(p + 2);
    *(u16 *)(p + 2) = count + 2;
    rfc_send_buf_uih(0, count);
}

void rfc_send_credit(void *p_mcb, UINT8 credits, UINT8 arg2, u32 arg3) {
    u8 state = *(u8 *)((u8 *)p_mcb + 0x6D);
    void *p_buf;
    u8 *p;
    if (state == 0) state = 0;
    else state = 1;
    p_buf = GKI_getpoolbuf(2);
    if (p_buf == NULL) return;
    p = p_buf;
    *(u16 *)(p + 4) = 9;
    p[0x11] = (state << 1) | 1 | (credits << 2);
    p[0x12] = 0xFF;
    p[0x13] = 1;
    p[0x14] = arg2;
    p[0x15] = fn_8009504C(2, p + *(u16 *)(p + 4) + 8, 9);
    *(u16 *)(p + 2) = 5;
    rfc_check_send_cmd(p_mcb, p_buf);
}

extern u8 fn_80095084(s32, void *);
extern char lbl_80319DD8[];
extern char lbl_80559090[];
extern char lbl_80559098[];
s32 rfc_parse_data(void *arg0, void *arg1, u8 *arg2) {
    char *messages = lbl_80319DD8;
    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r8_3;
    s32 temp_r9;
    s32 var_r8;
    u16 temp_r8;
    u8 *var_r7_2;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r3_4;
    u8 temp_r3_5;
    u8 temp_r3_6;
    u8 temp_r6_2;
    u8 temp_r6_3;
    u8 temp_r6_4;
    u8 temp_r6_5;
    u8 temp_r6_6;
    u8 temp_r8_2;
    u8 temp_r9_2;
    u8 *temp_r6;
    u8 *temp_r7;
    u8 *var_r7;

    temp_r6 = arg2 + (*(u16 *)((u8 *)(arg2) + 4));
    temp_r8 = (*(u16 *)((u8 *)(arg2) + 2));
    temp_r7 = temp_r6 + 8;
    if (temp_r8 < 3U) {
        if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
            fn_80070954(0x90000, messages, temp_r8);
        }
        return 0x32;
    }
    temp_r8_2 = (*(u8 *)((u8 *)(temp_r6) + 8));
    temp_r9 = temp_r8_2 & 1;
    (*(u8 *)((u8 *)(arg1) + 2)) = (u8) ((s32) (temp_r8_2 & 2) >> 1);
    var_r7 = temp_r7 + 1;
    temp_r8_3 = (s32) (*(u8 *)((u8 *)(temp_r6) + 8)) >> 2;
    (*(u8 *)((u8 *)(arg1) + 0)) = (u8) temp_r8_3;
    if (temp_r9 == 0) {
        var_r7 += 1;
        (*(u8 *)((u8 *)(arg1) + 0)) = (u8) ((u8) temp_r8_3 + ((*(u8 *)((u8 *)(temp_r7) + 1)) << 6));
    }
    (*(u8 *)((u8 *)(arg1) + 1)) = (u8) ((*(u8 *)((u8 *)(var_r7) + 0)) & 0xFFFFFFEF);
    (*(u8 *)((u8 *)(arg1) + 4)) = (u8) ((s32) ((*(u8 *)((u8 *)(var_r7) + 0)) & 0x10) >> 4);
    temp_r6_2 = (*(u8 *)((u8 *)(var_r7) + 1));
    var_r7_2 = var_r7 + 2;
    temp_r10 = temp_r6_2 & 1;
    var_r8 = (s32) temp_r6_2 >> 1;
    if (temp_r10 == 0) {
        var_r7_2 += 1;
        var_r8 = (s32) (u16) (var_r8 + ((*(u8 *)((u8 *)(var_r7) + 2)) << 7));
    }
    temp_r11 = (temp_r9 == 0) + (temp_r10 == 0);
    (*(u16 *)((u8 *)(arg2) + 2)) = (u16) ((*(u16 *)((u8 *)(arg2) + 2)) - (temp_r11 + 4));
    (*(u16 *)((u8 *)(arg2) + 4)) = (u16) (temp_r11 + (*(u16 *)((u8 *)(arg2) + 4)) + 3);
    if (((u8) (*(u8 *)((u8 *)(arg0) + 0x72)) == 2) && ((u8) (*(u8 *)((u8 *)(arg1) + 1)) == 0xEF) && ((s32) (*(u8 *)((u8 *)(arg1) + 0)) != 0) && ((u8) (*(u8 *)((u8 *)(arg1) + 4)) == 1)) {
        (*(u8 *)((u8 *)(arg1) + 5)) = (u8) *var_r7_2;
        (*(u16 *)((u8 *)(arg2) + 2)) = (u16) ((*(u16 *)((u8 *)(arg2) + 2)) - 1);
        (*(u16 *)((u8 *)(arg2) + 4)) = (u16) ((*(u16 *)((u8 *)(arg2) + 4)) + 1);
    } else {
        (*(u8 *)((u8 *)(arg1) + 5)) = 0U;
    }
    if ((u16) (*(u16 *)((u8 *)(arg2) + 2)) != (u16) var_r8) {
        if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
            ((void (*)(u32, void *))fn_8007096C)(0x90000, messages + 0x10);
        }
        return 0x32;
    }
    temp_r9_2 = (*(u8 *)((u8 *)(arg1) + 1));
    switch ((s32) temp_r9_2) {                      case 0x2F:
        temp_r6_3 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r6_3 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || (((s32) temp_r6_3 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || ((s32) (*(u8 *)((u8 *)(arg1) + 4)) == 0) || ((u16) var_r8 != 0) || ((temp_r3 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3 == 0) == 0)) && ((temp_r3 < 2U) || (temp_r3 > 0x3DU))) || (fn_80095084(3, temp_r7) == 0)) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, lbl_80319DD8 + 0x24);
            }
            return 0x32;
        }
        return 0;
    case 0x63:
        temp_r6_4 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r6_4 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || (((s32) temp_r6_4 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || ((s32) (*(u8 *)((u8 *)(arg1) + 4)) == 0) || ((u16) var_r8 != 0) || ((temp_r3_2 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3_2 == 0) == 0)) && ((temp_r3_2 < 2U) || (temp_r3_2 > 0x3DU))) || (fn_80095084(3, temp_r7) == 0)) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, messages + 0x10);
            }
            return 0x32;
        }
        return 1;
    case 0xF:
        temp_r6_5 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r6_5 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || (((s32) temp_r6_5 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || ((u16) var_r8 != 0) || ((temp_r3_3 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3_3 == 0) == 0)) && ((temp_r3_3 < 2U) || (temp_r3_3 > 0x3DU))) || (fn_80095084(3, temp_r7) == 0)) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, messages + 0x20);
            }
            return 0x32;
        }
        return 2;
    case 0x43:
        temp_r6_6 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r6_6 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || (((s32) temp_r6_6 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || ((s32) (*(u8 *)((u8 *)(arg1) + 4)) == 0) || ((u16) var_r8 != 0) || ((temp_r3_4 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3_4 == 0) == 0)) && ((temp_r3_4 < 2U) || (temp_r3_4 > 0x3DU))) || (fn_80095084(3, temp_r7) == 0)) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, lbl_80319DD8 + 0x30);
            }
            return 0x32;
        }
        return 3;
    case 0xEF:
        temp_r3_5 = (*(u8 *)((u8 *)(arg1) + 0));
        if (((s32) temp_r3_5 != 0) && ((temp_r3_5 < 2U) || (temp_r3_5 > 0x3DU))) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, lbl_80319DD8 + 0x3C);
            }
            return 0x32;
        }
        if (fn_80095084(2, temp_r7) == 0) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, lbl_80319DD8 + 0x54);
            }
            return 0x32;
        }
        temp_r3_6 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r3_6 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || (((s32) temp_r3_6 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0))) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, lbl_80319DD8 + 0x64);
            }
            return 4;
        }
        return 4;
    default:
        return 0x32;
    }
}

void rfc_check_mcb_active(void *arg0) {
    u8 *mcb = (u8 *)arg0;
    u16 i;
    for (i = 0; i < 0x3D; i++) {
        if (mcb[i + 0x24] != 0) {
            mcb[0x74] = 0;
            return;
        }
    }
    if (mcb[0x74] != 0) {
        mcb[0x74] = 0;
        fn_800916F4(arg0, 8, 0);
        return;
    }
    if (lbl_803C4828[0x414] >= 4) {
        fn_80070954(0x90003, lbl_80319EC0, 2);
    }
    *(void **)(mcb + 0x10) = arg0;
    btu_start_timer(arg0, 0xB, 2);
}

void fn_80095518(void *arg0) {
    u16 state = *(u16 *)((u8 *)arg0 + 0x14);
    if (state == 12) rfc_port_sm_execute(*(void **)((u8 *)arg0 + 0x10), 5, 0);
    else if (state == 11) fn_800916F4(*(void **)((u8 *)arg0 + 0x10), 5, 0);
}

void rfc_sec_check_complete(void *unused, void *arg0, s8 arg1) {
    if (*((u8 *)arg0 + 1) == 0) return;
    if (*((u8 *)arg0 + 0x68) != 2 && *((u8 *)arg0 + 0x68) != 3) return;
    rfc_port_sm_execute(arg0, 15, &arg1);
}

void fn_8009578C(void *arg0) {
    void *port = *(void **)((u8 *)arg0 + 0x6c);
    u16 credit;
    if (*((u8 *)port + 0x72) == 2) {
        credit = *(u16 *)((u8 *)arg0 + 0x98);
        if (credit) *(u16 *)((u8 *)arg0 + 0x98) = credit - 1;
        if (*(u16 *)((u8 *)arg0 + 0x98) == 0) *((u8 *)arg0 + 0x24) = 1;
    }
}

void rfc_check_send_cmd(void *arg0, void *arg1) {
    register u8 *p = (u8 *)arg0;
    if (arg1 != 0) {
        GKI_enqueue((BUFFER_Q *)(p + 0x18), arg1);
    }
    for (;;) {
        arg1 = GKI_dequeue((BUFFER_Q *)(p + 0x18));
        if (arg1 == 0) return;
        L2CA_DataWrite(*(u16 *)(p + 0x68), (BT_HDR *)arg1);
        if (p[0x73] != 0) return;
    }
}

BOOLEAN SDP_ServiceSearchRequest(UINT8 *p_bd_addr, tSDP_DISCOVERY_DB *p_db, tSDP_DISC_CMPL_CB *p_cb) {
    tCONN_CB *p_ccb = sdp_conn_originate(p_bd_addr);
    if (p_ccb == NULL) return FALSE;
    *(u8 *)((u8 *)p_ccb + 0x474) = 0;
    *(u32 *)((u8 *)p_ccb + 0x410) = (u32)p_db;
    *(u32 *)((u8 *)p_ccb + 0x414) = (u32)p_cb;
    return TRUE;
}

BOOLEAN SDP_ServiceSearchAttributeRequest(UINT8 *p_bd_addr, tSDP_DISCOVERY_DB *p_db, tSDP_DISC_CMPL_CB *p_cb) {
    tCONN_CB *p_ccb = sdp_conn_originate(p_bd_addr);
    if (p_ccb == NULL) return FALSE;
    *(u8 *)((u8 *)p_ccb + 0x474) = 0;
    *(u32 *)((u8 *)p_ccb + 0x410) = (u32)p_db;
    *(u32 *)((u8 *)p_ccb + 0x414) = (u32)p_cb;
    *(u8 *)((u8 *)p_ccb + 0x475) = 1;
    return TRUE;
}

void *fn_80095C64(void **head, u32 attr) {
    void *p = *head;
    while (p != NULL) {
        if (*(u16 *)((u8 *)p + 4) == attr) return p;
        p = *(void **)p;
    }
    return NULL;
}

extern void *fn_80096904(void *, u32, u32);
UINT16 SDP_GetLocalDiRecord(tSDP_DI_GET_RECORD *p_device_info, UINT32 *p_handle) {
    tSDP_RECORD *record;
    void *attr;
    u16 len;
    UINT16 result = 9;
    if (*p_handle == 0) *p_handle = *(UINT32 *)(lbl_803C4C40 + 0x121C);
    record = sdp_db_find_record(*p_handle);
    if (record != NULL) {
        memset(p_device_info, 0, 0xFA);
        result = 0;
        attr = fn_80096904(record, 0x200, 0x200);
        if (attr != NULL) p_device_info->spec_id = (*(u8 *)*(u8 **)((u8 *)attr + 4) << 8) + *(*(u8 **)((u8 *)attr + 4) + 1);
        attr = fn_80096904(record, 0x201, 0x201);
        if (attr != NULL) p_device_info->rec.vendor = (*(u8 *)*(u8 **)((u8 *)attr + 4) << 8) + *(*(u8 **)((u8 *)attr + 4) + 1);
        attr = fn_80096904(record, 0x202, 0x202);
        if (attr != NULL) p_device_info->rec.product = (*(u8 *)*(u8 **)((u8 *)attr + 4) << 8) + *(*(u8 **)((u8 *)attr + 4) + 1);
        attr = fn_80096904(record, 0x203, 0x203);
        if (attr != NULL) p_device_info->rec.version = (*(u8 *)*(u8 **)((u8 *)attr + 4) << 8) + *(*(u8 **)((u8 *)attr + 4) + 1);
        attr = fn_80096904(record, 0x205, 0x205);
        if (attr != NULL) p_device_info->rec.vendor_id_source = (*(u8 *)*(u8 **)((u8 *)attr + 4) << 8) + *(*(u8 **)((u8 *)attr + 4) + 1);
        attr = fn_80096904(record, 0x204, 0x204);
        if (attr != NULL) p_device_info->rec.primary_record = **(u8 **)((u8 *)attr + 4);
        attr = fn_80096904(record, 0xB, 0xB);
        if (attr != NULL) { len = *(u32 *)attr; if (len > 0x50) len = 0x50; memcpy(p_device_info->rec.client_executable_url, *(void **)((u8 *)attr + 4), len); }
        attr = fn_80096904(record, 0x101, 0x101);
        if (attr != NULL) { len = *(u32 *)attr; if (len > 0x50) len = 0x50; memcpy(p_device_info->rec.service_description, *(void **)((u8 *)attr + 4), len); }
        attr = fn_80096904(record, 0xA, 0xA);
        if (attr != NULL) { len = *(u32 *)attr; if (len > 0x50) len = 0x50; memcpy(p_device_info->rec.documentation_url, *(void **)((u8 *)attr + 4), len); }
    } else *p_handle = 0;
    return result;
}

u8 fn_80096670(u8 value) {
    if (value != 0xFF) lbl_803C4C40[0x4630] = value;
    return lbl_803C4C40[0x4630];
}

tSDP_RECORD *sdp_db_find_record(UINT32 handle) {
    u8 *start = &lbl_803C4C40[0x1224];
    u8 *end = start + (u32)(*(u16 *)&lbl_803C4C40[0x1222]) * 0x298;
    u8 *p;
    for (p = start; p < end; p += 0x298) {
        if (*(u32 *)p == handle) return (tSDP_RECORD *)p;
    }
    return NULL;
}

void *fn_80096904(void *arg0, u32 arg1, u32 arg2) {
    u16 count = *(u16 *)((u8 *)arg0 + 8);
    u8 *p = (u8 *)arg0 + 0xC;
    u16 i = 0;
    while (i < count) {
        u16 value = *(u16 *)(p + 8);
        if (value >= arg1 && value <= arg2) return p;
        i++;
        p += 0xC;
    }
    return NULL;
}

extern void process_service_search_attr_rsp(tCONN_CB *, u8 *, u16);
extern void sdp_snd_service_search_req(tCONN_CB *, u8, u8 *);
void fn_8009757C(u8 *p_ccb) {
    if (p_ccb[0x475]) {
        p_ccb[0x474] = 3;
        process_service_search_attr_rsp((tCONN_CB *)p_ccb, NULL, 0);
    } else {
        *(u16 *)(p_ccb + 0x46c) = 0;
        sdp_snd_service_search_req((tCONN_CB *)p_ccb, 0, NULL);
    }
}

void *add_record(void *ctx, void *data) {
    u32 size = *(u32 *)((u8 *)ctx + 4);
    void *record;
    void *node;
    if (size < 0x14) return NULL;
    record = *(void **)((u8 *)ctx + 0x68);
    *(u32 *)((u8 *)ctx + 4) = size - 0x14;
    *(void **)((u8 *)ctx + 0x68) = (u8 *)record + 0x14;
    *(u32 *)record = 0;
    *(u32 *)((u8 *)record + 4) = 0;
    memcpy((u8 *)record + 0xC, data, 6);
    node = *(void **)((u8 *)ctx + 8);
    if (node == NULL) {
        *(void **)((u8 *)ctx + 8) = record;
    } else {
        while (*(void **)((u8 *)node + 4) != NULL)
            node = *(void **)((u8 *)node + 4);
        *(void **)((u8 *)node + 4) = record;
    }
    return record;
}

void sdp_connect_ind(u8 *addr, u16 cid, u16 psm, u8 status) {
    extern void fn_80070954(u32, void *, u16);
    extern u8 lbl_8031A200[];
    void *ccb = sdpu_allocate_ccb();
    if (ccb != 0) {
        *(u8 *)ccb = 2;
        memcpy((u8 *)ccb + 2, addr, 6);
        *(u16 *)((u8 *)ccb + 0x22) = cid;
        L2CA_ConnectRsp(addr, status, cid, 0, 0);
        L2CA_ConfigReq(cid, (tL2CAP_CFG_INFO *)lbl_803C4C40);
        if (lbl_803C4C40[0x4630] >= 4) {
            fn_80070954(0xA0003, lbl_8031A200, *(u16 *)((u8 *)ccb + 0x22));
        }
    }
}

void sdp_conn_timeout(tCONN_CB *p_ccb) {
    extern char lbl_8031A4B8[];
    extern u8 lbl_803C4C40[];
    extern void fn_80099F58(void *);
    if (lbl_803C4C40[0x4630] >= 4) {
        fn_8007096C(0xA0003, lbl_8031A4B8, p_ccb->con_state, p_ccb->connection_id);
    }
    L2CA_DisconnectReq(p_ccb->connection_id);
    if (*(void (**)(UINT16))((u8 *)p_ccb + 0x414) != NULL)
        (*(void (**)(UINT16))((u8 *)p_ccb + 0x414))(0xFFF1);
    fn_80099F58(p_ccb);
}

tCONN_CB *l2cu_find_lcb_by_handle_80099E54(UINT16 handle) {
    u8 *p = lbl_803C4C40 + 0x3C;
    int i;
    for (i = 0; i < 4; i++, p += 0x478) {
        if (p[0] != 0 && *(UINT16 *)(p + 0x22) == handle) return (tCONN_CB *)p;
    }
    return NULL;
}

tCONN_CB *sdpu_allocate_ccb(void) {
    UINT16 xx;
    u8 *p_ccb;

    for (xx = 0, p_ccb = lbl_803C4C40 + 0x3C; xx < SDP_MAX_CONNECTIONS; xx++, p_ccb += 0x478) {
        if (p_ccb[0] == SDP_STATE_IDLE) {
            memset(p_ccb, 0, 0x478);
            *(u32 *)(p_ccb + 0x18) = (u32)p_ccb;
            return (tCONN_CB *)p_ccb;
        }
    }
    return NULL;
}

void fn_80099F58(void *arg0) {
    fn_80070F90((u8 *)arg0 + 8);
    *(u8 *)arg0 = 0;
}

UINT8 *sdpu_build_attrib_entry(UINT8 *p_out, tSDP_ATTRIBUTE *p_attr)
{
    UINT8_TO_BE_STREAM(p_out, (UINT_DESC_TYPE << 3) | SIZE_TWO_BYTES);
    UINT16_TO_BE_STREAM(p_out, p_attr->id);
    switch (p_attr->type) {
    case TEXT_STR_DESC_TYPE:
    case DATA_ELE_SEQ_DESC_TYPE:
    case DATA_ELE_ALT_DESC_TYPE:
    case URL_DESC_TYPE:
        UINT8_TO_BE_STREAM(p_out, (p_attr->type << 3) | SIZE_IN_NEXT_BYTE);
        UINT8_TO_BE_STREAM(p_out, p_attr->len);
        ARRAY_TO_BE_STREAM(p_out, p_attr->value_ptr, (int)p_attr->len);
        return p_out;
    }
    switch (p_attr->len) {
    case 1: UINT8_TO_BE_STREAM(p_out, (p_attr->type << 3) | SIZE_ONE_BYTE); break;
    case 2: UINT8_TO_BE_STREAM(p_out, (p_attr->type << 3) | SIZE_TWO_BYTES); break;
    case 4: UINT8_TO_BE_STREAM(p_out, (p_attr->type << 3) | SIZE_FOUR_BYTES); break;
    case 8: UINT8_TO_BE_STREAM(p_out, (p_attr->type << 3) | SIZE_EIGHT_BYTES); break;
    case 16: UINT8_TO_BE_STREAM(p_out, (p_attr->type << 3) | SIZE_SIXTEEN_BYTES); break;
    default:
        UINT8_TO_BE_STREAM(p_out, (p_attr->type << 3) | SIZE_IN_NEXT_BYTE);
        UINT8_TO_BE_STREAM(p_out, p_attr->len);
        break;
    }
    ARRAY_TO_BE_STREAM(p_out, p_attr->value_ptr, (int)p_attr->len);
    return p_out;
}

UINT8 *sdpu_extract_uid_seq (UINT8 *p, UINT16 param_len, tSDP_UUID_SEQ *p_seq)
{
    UINT8   *p_seq_end;
    UINT8   descr, type, size;
    UINT32  seq_len, uuid_len;

    /* Assume none found */
    p_seq->num_uids = 0;

    /* A UID sequence is composed of a bunch of UIDs. */

    BE_STREAM_TO_UINT8 (descr, p);
    type = descr >> 3;
    size = descr & 7;

    if (type != DATA_ELE_SEQ_DESC_TYPE)
        return (NULL);

    switch (size)
    {
    case SIZE_TWO_BYTES:
        seq_len = 2;
        break;
    case SIZE_FOUR_BYTES:
        seq_len = 4;
        break;
    case SIZE_SIXTEEN_BYTES:
        seq_len = 16;
        break;
    case SIZE_IN_NEXT_BYTE:
        BE_STREAM_TO_UINT8 (seq_len, p);
        break;
    case SIZE_IN_NEXT_WORD:
        BE_STREAM_TO_UINT16 (seq_len, p);
        break;
    case SIZE_IN_NEXT_LONG:
        BE_STREAM_TO_UINT32 (seq_len, p);
        break;
    default:
        return (NULL);
    }

    if (seq_len >= param_len)
        return (NULL);

    p_seq_end = p + seq_len;

    /* Loop through, extracting the UIDs */
    for ( ; p < p_seq_end ; )
    {
        BE_STREAM_TO_UINT8 (descr, p);
        type = descr >> 3;
        size = descr & 7;

        if (type != UUID_DESC_TYPE)
            return (NULL);

        switch (size)
        {
        case SIZE_TWO_BYTES:
            uuid_len = 2;
            break;
        case SIZE_FOUR_BYTES:
            uuid_len = 4;
            break;
        case SIZE_SIXTEEN_BYTES:
            uuid_len = 16;
            break;
        case SIZE_IN_NEXT_BYTE:
            BE_STREAM_TO_UINT8 (uuid_len, p);
            break;
        case SIZE_IN_NEXT_WORD:
            BE_STREAM_TO_UINT16 (uuid_len, p);
            break;
        case SIZE_IN_NEXT_LONG:
            BE_STREAM_TO_UINT32 (uuid_len, p);
            break;
        default:
            return (NULL);
        }

        /* If UUID length is valid, copy it across */
        if ((uuid_len == 2) || (uuid_len == 4) || (uuid_len == 16))
        {
            p_seq->uuid_entry[p_seq->num_uids].len = (UINT16) uuid_len;
            BE_STREAM_TO_ARRAY (p, p_seq->uuid_entry[p_seq->num_uids].value, (int)uuid_len);
            p_seq->num_uids++;
        }
        else
            return (NULL);

        /* We can only do so many */
        if (p_seq->num_uids >= MAX_UUIDS_PER_SEQ)
            return (NULL);
    }

    if (p != p_seq_end)
        return (NULL);

    return (p);
}

UINT8 *sdpu_get_len_from_type (UINT8 *p, UINT8 type, UINT32 *p_len)
{
    UINT8   u8;
    UINT16  u16;
    UINT32  u32;

    switch (type & 7)
    {
    case SIZE_ONE_BYTE:
        *p_len = 1;
        break;
    case SIZE_TWO_BYTES:
        *p_len = 2;
        break;
    case SIZE_FOUR_BYTES:
        *p_len = 4;
        break;
    case SIZE_EIGHT_BYTES:
        *p_len = 8;
        break;
    case SIZE_SIXTEEN_BYTES:
        *p_len = 16;
        break;
    case SIZE_IN_NEXT_BYTE:
        BE_STREAM_TO_UINT8 (u8, p);
        *p_len = u8;
        break;
    case SIZE_IN_NEXT_WORD:
        BE_STREAM_TO_UINT16 (u16, p);
        *p_len = u16;
        break;
    case SIZE_IN_NEXT_LONG:
        BE_STREAM_TO_UINT32 (u32, p);
        *p_len = (UINT16) u32;
        break;
    }

    return (p);
}

BOOLEAN sdpu_compare_uuid_with_attr(tBT_UUID *p_btuuid, tSDP_DISC_ATTR *p_attr) {
    UINT16 attr_len = SDP_DISC_ATTR_LEN(p_attr->attr_len_type);

    /* Since both UUIDs are compressed, lengths must match  */
    if (p_btuuid->len != attr_len) {
        return (FALSE);
    }

    if (p_btuuid->len == 2) {
        return (BOOLEAN)(p_btuuid->uu.uuid16 == p_attr->attr_value.v.u16);
    } else if (p_btuuid->len == 4) {
        return (BOOLEAN)(p_btuuid->uu.uuid32 == p_attr->attr_value.v.u32);
    }

    return (BOOLEAN)(memcmp(p_btuuid->uu.uuid128, p_attr->attr_value.v.array, MAX_UUID_SIZE) == 0);
}

void sdpu_sort_attr_list(UINT16 num_attr, tSDP_DISCOVERY_DB *p_db) {
    UINT16 i;
    UINT16 x;

    if (num_attr <= 1) return;
    num_attr--;
    for (i = 0; i < num_attr;) {
        if (p_db->attr_filters[i] > p_db->attr_filters[i + 1]) {
            x = p_db->attr_filters[i];
            p_db->attr_filters[i] = p_db->attr_filters[i + 1];
            p_db->attr_filters[i + 1] = x;
            i = (UINT16)-1;
        }
        i++;
    }
}

static void USB_LOG(const char *fmt, ...) {
    va_list list;
    if (lbl_8055DC90) {
        OSReport((const char *)&lbl_805590A4);
        va_start(list, fmt);
        vprintf(fmt, list);
        va_end(list);
    }
}

static void USB_ERR(const char *fmt, ...) {
    va_list list;

    if (lbl_8055DC90) {
        OSReport(lbl_8031A620);
        va_start(list, fmt);
        vprintf(fmt, list);
        va_end(list);
    }
}

u32 fn_8009B0E0(void) {
    return 0;
}

s32 IUSB_ReadIntrMsgAsync(s32 fd, u32 endpoint, u32 length, void* buffer,
                           void (*callback)(void), void* callbackArg) {
    DCInvalidateRange(buffer, length);
    return __IntrBlkMsgInt(fd, endpoint, length, buffer, USB_IOCTLV_INTRMSG,
                           callback, callbackArg, TRUE);
}

s32 IUSB_ReadBlkMsgAsync(s32 fd, u32 endpoint, u32 length, void* buffer,
                         void (*callback)(void), void* callbackArg) {
    DCInvalidateRange(buffer, length);
    return __IntrBlkMsgInt(fd, endpoint, length, buffer, USB_IOCTLV_BLKMSG,
                           callback, callbackArg, TRUE);
}

s32 IUSB_WriteBlkMsgAsync(s32 fd, u32 endpoint, u32 length, void* buffer,
                         void (*callback)(void), void* callbackArg) {
    DCFlushRange(buffer, length);
    return __IntrBlkMsgInt(fd, endpoint, length, buffer, USB_IOCTLV_BLKMSG,
                           callback, callbackArg, TRUE);
}

#pragma use_lmw_stmw off
s32 IUSB_WriteCtrlMsgAsync(s32 a,s32 b,s32 c,s32 d,s32 e,u32 length,void* data,void* callback,void* context) {
    DCFlushRange(data,length);
    return __CtrlMsgInt(a,b,c,d,e,length,data,callback,context,1);
}
#pragma use_lmw_stmw reset
s32 AXFXReverbHiInit(void* arg0) {
    s32 zero = 0;
    f32 h, g, f, e, d, c, b, a;
    a = *(f32*)((u8*)arg0 + 0x158);
    f = lbl_80560D50;
    b = *(f32*)((u8*)arg0 + 0x150);
    c = *(f32*)((u8*)arg0 + 0x148);
    d = *(f32*)((u8*)arg0 + 0x154);
    e = *(f32*)((u8*)arg0 + 0x15C);
    g = lbl_80560D54;
    h = *(f32*)((u8*)arg0 + 0x14C);
    *(s32*)((u8*)arg0 + 0x110) = 5;
    *(f32*)((u8*)arg0 + 0x114) = a;
    *(f32*)((u8*)arg0 + 0x118) = a;
    *(s32*)((u8*)arg0 + 0x11C) = zero;
    *(f32*)((u8*)arg0 + 0x120) = b;
    *(f32*)((u8*)arg0 + 0x124) = c;
    *(f32*)((u8*)arg0 + 0x128) = d;
    *(f32*)((u8*)arg0 + 0x12C) = e;
    *(f32*)((u8*)arg0 + 0x130) = f;
    *(f32*)((u8*)arg0 + 0x134) = g;
    *(s32*)((u8*)arg0 + 0x138) = zero;
    *(s32*)((u8*)arg0 + 0x13C) = zero;
    *(f32*)((u8*)arg0 + 0x140) = h;
    *(f32*)((u8*)arg0 + 0x144) = f;
    return AXFXReverbHiExpInit(arg0);
}

s32 fn_8009BF98(void* arg0) {
    AXFXReverbHiExpShutdown(arg0);
    return 1;
}

void fn_8009BFBC(void) {
    AXFXReverbHiExpCallback();
}

void AXFXReverbHiExpShutdown(void* arg0) {
    s32 enabled = OSDisableInterrupts();
    *(u32*)((u8*)arg0 + 0x10C) |= 1;
    __FreeDelayLine(arg0);
    OSRestoreInterrupts(enabled);
}

void* __AXFXAllocFunction(u32 size) {
    return OSAllocFromHeap(__OSCurrHeap, size);
}

void __AXFXFreeFunction(void* ptr) {
    OSFreeToHeap(__OSCurrHeap, ptr);
}

extern void *lbl_805590B0;
extern void *lbl_805590B4;
void AXFXSetHooks_8009CDB0(void *arg0, void *arg1) {
    lbl_805590B0 = arg0;
    lbl_805590B4 = arg1;
}

void AXGetAuxACallback_8009CDBC(void **arg0, void **arg1) {
    *arg0 = lbl_805590B0;
    *arg1 = lbl_805590B4;
}

void* TPLGet(void* tpl, u32 index) {
    u32 count = *(u32*)((u8*)tpl + 4);
    u8* entries = *(u8**)((u8*)tpl + 8);
    return entries + (index % count) * 8;
}

s32 EUARTInit(void) {
    u8 sp8;
    s32 temp_r31;
    extern u32 lbl_8055DC98, lbl_8055DC9C, lbl_8055DCA0;
    if (lbl_8055DC98 != 0) return 1;
    if (!(OSGetConsoleType() & 0x10000000)) {
        lbl_8055DC9C = 2;
        return 0;
    }
    temp_r31 = OSDisableInterrupts();
    sp8 = 0xF2;
    if (EXIWriteReg(0, 1, 0xB0000000, &sp8, 1) == 0) {
        lbl_8055DC9C = 5;
        OSRestoreInterrupts(temp_r31);
        return 0;
    }
    sp8 = 0xF3;
    if (EXIWriteReg(0, 1, 0xB0000000, &sp8, 1) == 0) {
        lbl_8055DC9C = 5;
        OSRestoreInterrupts(temp_r31);
        return 0;
    }
    OSRestoreInterrupts(temp_r31);
    lbl_8055DC98 = 1;
    lbl_8055DC9C = 0;
    lbl_8055DCA0 = 0;
    return 1;
}

s32 fn_8009D000(void) {
    if (!(OSGetConsoleType() & 0x10000000)) {
        lbl_8055DCA4 = 0;
        return 2;
    }
    lbl_8055DCA4 = 0xA5FF005A;
    return 0;
}

u16 fn_8006D8D0(u32 arg0) {
    u32 diff;
    u8 val;
    diff = arg0 - 8;
    if ((diff & 1) != 0) {
        return 0;
    }
    val = *(u8 *)((u8 *)diff + 4);
    if (val < 9) {
        return *(u16 *)((u8 *)&lbl_803946C0 + 0x289E8 + (val << 4));
    }
    return 0;
}
u8 fn_8006CA6C(void) {
    u32 saved = OSDisableInterrupts();
    u8 val = lbl_80392960[0x665];
    OSRestoreInterrupts(saved);
    return val;
}

void fn_8006CF44(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u32 arg8) {
    register u32 *ptr = (u32 *)&lbl_80392960;
    void (*func)(void);
    if (arg8 == 3) {
        func = (void (*)(void))ptr[0x66C / 4];
        if (func) func();
    } else {
        DBPrintf_8006CFA8(lbl_803140D0, arg8);
    }
}

void fn_8006CF80(void) {
    DBPrintf_8006CFA8(lbl_803140E8);
}

extern char lbl_803140FC[];
extern char lbl_80313794[];
extern u32 lbl_8055DC30;
void fn_8006CF90(void) {
    DBPrintf_8006CFA8(lbl_803140FC);
}

void WUDDeviceStatusCallback(u32 arg0) {
    DBPrintf_8006CFA8(lbl_80313BB0);
    if (arg0 == 2) {
        OSReport(lbl_80313BCC);
    }
}

void fn_8006BAA4(u32 arg0) {
    u32 *base = (u32 *)&lbl_80392960;
    if (arg0 == 0) {
        lbl_8055DC30 = 0;
        *(u8 *)((u8 *)base + 0x688) = 0;
        return;
    }
    DBPrintf_8006CFA8(lbl_80313794);
}
extern u32 lbl_8055DCA4;
extern char lbl_80315700[];
extern void *jumptable_803159A0[];
extern u8 lbl_80559060[];
extern u8 lbl_803151D8[];
extern char lbl_80319EC0[];
