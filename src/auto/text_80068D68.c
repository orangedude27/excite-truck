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
extern void *l2cu_find_lcb_by_bd_addr(u8 *addr);
extern void l2cu_create_conn_after_switch(void *p_lcb);
extern u8 lbl_80392960[];
extern u8 lbl_803C0D48[];
extern u8 lbl_803C0B98[];
extern u32 lbl_8055DCA4;
extern void fn_80070F90(void *ptr);
extern u8 lbl_803C4C40[];
#include "revolution/BTE/stack/sdp/sdpint.h"
extern void AXFXReverbHiExpShutdown(void*);
extern s32 AXFXReverbHiExpInit(void*);
extern void __FreeDelayLine(void*);
extern s32 __CtrlMsgInt(s32,s32,s32,s32,s32,u32,void*,void*,void*,s32);
extern f32 lbl_80560D50;
extern f32 lbl_80560D54;

extern u8 lbl_803C0F78[];
extern u8 lbl_80316570[];
extern u8 lbl_803C0AD8[];
extern u8 lbl_8055DC80;
extern u8 *lbl_80559038;
extern void fn_8006E6E4(void *);
extern void fn_80071450(void *);
extern void fn_80070954(u32 code, void *msg, u16 param);
extern void fn_8007096C(u32 code, void *msg, u16 param1, u16 param2);
extern void fn_800709CC(u32 code, void *msg, s32 param1, s32 param2, u16 param3, u16 param4, u8 param5, u16 param6);
extern u8 lbl_803C4828[];
extern void rfc_send_fcon(void *, s32, void *);
extern void rfc_send_fcon_80093FDC(void *, s32);
extern void PORT_FlowInd(void *, s32, s32);
extern void PORT_LineStatusInd(void *, u8, u8);
extern void *port_find_mcb_dlci_port(void *, u8);
extern void rfc_port_timer_stop(void *);
extern void rfc_send_rls(void *, u8, s32, u8);
extern void rfc_check_send_cmd(void *, void *);
extern void fn_800916F4(void *, s32, s16 *);
extern char lbl_803140D0[];
extern char lbl_80315048[];
extern u8 lbl_803C0C14[];
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
extern void BTA_EnableBluetooth(void *);
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
    u8 *p0 = arg0 + 2;
    u8 *p1 = arg1 + 2;
    if (arg0[0] != arg1[0]) return -1;
    if (arg0[1] != arg1[1]) return -1;
    if (p0[0] != p1[0]) return -1;
    if (p0[1] != p1[1]) return -1;
    if (p0[2] != p1[2]) return -1;
    if (p0[3] == p1[3]) return 0;
    return -1;
}

void fn_80071078(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x80) = arg0; }

void fn_80071088(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x88) = arg0; }

void fn_80071098(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x84) = arg0; }

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

s32 fn_80072EF4(void) { return 0xB; }

void fn_8007301C(void *arg0) {
    void (**callback)(s32, void *);
    callback = (void (**)(s32, void *))(lbl_803C0C14 + 0x50);
    if (*callback != 0) (*callback)(0, arg0);
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

void fn_80073A00(void) {
    ((void (**)(int, int)) (lbl_803C0C14 + 0x50))[0](1, 0);
}

void fn_80073A1C(void) {

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
    action = table[((event & 0xFF) * 4) - (event & 0xFF) + i];
    if (action != 0xD) {
        ((tAction *)lbl_802EEA38)[action](p_msg);
        i++;
        if (i < 2)
            goto loop;
    }
    return 1;
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
    u8 status;
    if (arg1 != 0)
        status = (u8)*(u16 *)((u8 *)arg1 + 6);
    else
        status = *((u8 *)arg0 + 0x16);
    if (HID_HostCloseDev() != 0)
        (*(void (**)(int, u8 *))(lbl_803C0D48 + 0x224))(3, &status);
}

void fn_80075AA4(void *arg0) {
    (*(void (**)(int, void *))(lbl_803C0D48 + 0x224))(10, arg0);
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
    if (var_r30[0x119] != 0 && memcmp(var_r30 + 8, arg0, 6) == 0) {
        goto found;
    }
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
    if (base[0x14D] != 0 && *(u16 *)(base + 0x34) == arg0) {
        goto update;
    }
    i = 1;
    if (base[0x269] != 0 && *(u16 *)(base + 0x150) == arg0) {
        goto update;
    }
    i = 2;
    if (base[0x385] != 0 && *(u16 *)(base + 0x26C) == arg0) {
        goto update;
    }
    i = 3;
    if (base[0x4A1] != 0 && *(u16 *)(base + 0x388) == arg0) {
        goto update;
    }
    i = 4;
update:
    if (i >= 4) {
        return;
    }
    *(u16 *)(base + i * 0x11C + 0x3A) = arg1;
}

s32 fn_80078310(s32 arg0)
{
    s32 result;
    if (arg0 == 0) {
        *(s32 *)(lbl_803C0F78 + 0x4C8) = 0;
        result = 0;
    } else if (*(s32 *)(lbl_803C0F78 + 0x4C8) != 0) {
        result = 2;
    } else {
        *(s32 *)(lbl_803C0F78 + 0x4C8) = arg0;
        result = 0;
    }
    return result;
}

BOOLEAN BTM_SecDeleteDevice(BD_ADDR bd_addr) {
    u8 *entry;
    s32 i;
    entry = lbl_803C0F78 + 0x1F30;
    for (i = 0; i < 16; i++, entry += 0x88) {
        if ((entry[0x76] & 0x80) && memcmp(entry + 0x1C, bd_addr, 6) == 0) break;
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

void fn_8007AD38(void) {

}

tBTM_STATUS BTM_SetInquiryScanType(UINT16 arg0) {
    void *p_buf;
    if (arg0 != 0 && arg0 != 1) return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x10)) return BTM_MODE_UNSUPPORTED;
    if (arg0 != *(u16 *)(lbl_803C0F78 + 0x16A4)) {
        if ((u8)fn_80079514() == 0) return BTM_WRONG_MODE;
        p_buf = GKI_getpoolbuf(2);
        if (p_buf == 0) return BTM_NO_RESOURCES;
        fn_80085DC4(p_buf, (u8)arg0);
        *(u16 *)(lbl_803C0F78 + 0x16A4) = arg0;
    }
    return BTM_SUCCESS;
}

tBTM_STATUS BTM_SetPageScanType(UINT16 arg0) {
    void *p_buf;
    if (arg0 != 0 && arg0 != 1) return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x20)) return BTM_MODE_UNSUPPORTED;
    if (arg0 != *(u16 *)(lbl_803C0F78 + 0x16A6)) {
        if ((u8)fn_80079514() == 0) return BTM_WRONG_MODE;
        p_buf = GKI_getpoolbuf(2);
        if (p_buf == 0) return BTM_NO_RESOURCES;
        fn_80085E24(p_buf, (u8)arg0);
        *(u16 *)(lbl_803C0F78 + 0x16A6) = arg0;
    }
    return BTM_SUCCESS;
}

tBTM_STATUS BTM_SetInquiryMode(UINT8 arg0) {
    if (arg0 != 0 && arg0 != 1) return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x40)) return BTM_MODE_UNSUPPORTED;
    if (!fn_80079514()) return BTM_WRONG_MODE;
    if (GKI_getpoolbuf(2) != 0) {
        fn_80085DF4(arg0);
        return BTM_SUCCESS;
    }
    return BTM_NO_RESOURCES;
}

u8 fn_8007B340(void) {
    return lbl_803C0F78[0x1848];
}

void fn_8007BC88(void) {

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

void fn_8008251C(void) {
    btm_init();
    l2c_init();
    sdp_init();
    btm_discovery_db_init();
}

void fn_800833E8(s32 arg0) { btm_cback(0, arg0); }

void fn_800833F4(s32 arg0) { btm_cback(1, arg0); }

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

void fn_80089E3C(void) {

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
    u8 *lcb = lbl_803C4040 + 8;
    if (lcb[0] && *(u16 *)(lcb + 0x28) == handle) return lcb;
    lcb += 0x5C;
    if (lcb[0] && *(u16 *)(lcb + 0x28) == handle) return lcb;
    lcb += 0x5C;
    if (lcb[0] && *(u16 *)(lcb + 0x28) == handle) return lcb;
    lcb += 0x5C;
    if (lcb[0] && *(u16 *)(lcb + 0x28) == handle) return lcb;
    return 0;
}

u8 fn_8008D7C4(void) { return lbl_803C4040[1]; }

extern void *l2cu_build_header(u16, u8, u8, s32);
extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
extern void fn_8007093C(u32, void *);
extern char lbl_80319174[];
void l2cu_send_peer_info_rsp(void *arg0, s32 arg1, u8 arg2) {
    void *p;
    p = l2cu_build_header(*(u16 *)((u8 *)arg0 + 0x28), 4, 0xb, arg1);
    if (p == 0) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80319174);
    } else {
        *(u8 *)((u8 *)p + 0x14) = arg2;
        *((u8 *)p + 0x15) = arg2 >> 8;
        *((u8 *)p + 0x16) = 1;
        *((u8 *)p + 0x17) = 0;
        l2c_link_check_send_pkts(arg0, 0, p, 1);
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

void fn_8008EE40(void *arg0, void *arg1) {
    u8 *dst = (u8 *)arg0; u8 *src = (u8 *)arg1; u32 a, b;
    if (src[6] != 0) {
        b = *(u32 *)(src + 0xc); a = *(u32 *)(src + 8);
        *(u32 *)(dst + 0x58) = a; *(u32 *)(dst + 0x5c) = b;
        b = *(u32 *)(src + 0x14); a = *(u32 *)(src + 0x10);
        *(u32 *)(dst + 0x60) = a; *(u32 *)(dst + 0x64) = b;
        b = *(u32 *)(src + 0x1c); a = *(u32 *)(src + 0x18);
        *(u32 *)(dst + 0x68) = a; *(u32 *)(dst + 0x6c) = b;
    }
}

void fn_8008EF90(void *arg0, void *arg1) {
    u8 *dst = (u8 *)arg0; u8 *src = (u8 *)arg1; u32 a, b;
    if (src[6] != 0) {
        b = *(u32 *)(src + 0xc); a = *(u32 *)(src + 8);
        *(u32 *)(dst + 0x40) = a; *(u32 *)(dst + 0x44) = b;
        b = *(u32 *)(src + 0x14); a = *(u32 *)(src + 0x10);
        *(u32 *)(dst + 0x48) = a; *(u32 *)(dst + 0x4c) = b;
        b = *(u32 *)(src + 0x1c); a = *(u32 *)(src + 0x18);
        *(u32 *)(dst + 0x50) = a; *(u32 *)(dst + 0x54) = b;
    }
}

void fn_800911DC(void) {

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

tCONN_CB *sdpu_allocate_ccb(void) {
    UINT16 xx;
    tCONN_CB *p_ccb;

    for (xx = 0, p_ccb = &sdp_cb.ccb[0]; xx < SDP_MAX_CONNECTIONS; xx++, p_ccb++) {
        if (p_ccb->con_state == SDP_STATE_IDLE) {
            memset(p_ccb, 0, sizeof(tCONN_CB));
            p_ccb->timer_entry.param = (UINT32)p_ccb;
            return (p_ccb);
        }
    }

    return (NULL);
}

void fn_80099F58(void *arg0) {
    fn_80070F90((u8 *)arg0 + 8);
    *(u8 *)arg0 = 0;
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

    if (num_attr <= 1) {
        return;
    } else if (num_attr > SDP_MAX_ATTR_FILTERS) {
        num_attr = SDP_MAX_ATTR_FILTERS;
    }

    num_attr--;
    for (i = 0; i < num_attr;) {
        if (p_db->attr_filters[i] > p_db->attr_filters[i + 1]) {
            x = p_db->attr_filters[i];
            p_db->attr_filters[i] = p_db->attr_filters[i + 1];
            p_db->attr_filters[i + 1] = x;
            i = 0;
        } else {
            i++;
        }
    }
}

static void USB_LOG(const char *fmt, ...) {
    va_list list;

    if (lbl_8055DC90) {
        OSReport((char *)0x803C469C);
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
    s32 zero;
    f32 h;
    f32 g;
    f32 f;
    f32 e;
    f32 d;
    f32 c;
    f32 b;
    f32 a;
    zero = 0;
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

s32 fn_8009D000(void) {
    if (!(OSGetConsoleType() & 0x10000000)) {
        lbl_8055DCA4 = 0;
        return 2;
    }
    lbl_8055DCA4 = 0xA5FF005A;
    return 0;
}

u16 fn_8006D8D0(u32 arg0) {
    s32 diff = (s32)arg0 - 8;
    if (diff < 0) {
        return 0;
    }
    {
        u8 val = *(u8 *)((u8 *)diff + 4);
        if (val < 9) {
            return *(u16 *)((u8 *)&lbl_803946C0 + 0x289E8 + (val << 4));
        }
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
    u32 *ptr = (u32 *)&lbl_80392960;
    void (*func)(void);
    if (arg8 == 3) {
        func = (void (*)(void))ptr[0x66C / 4];
        if (func) {
            func();
        }
        return;
    }
    DBPrintf_8006CFA8(lbl_803140D0, arg8);
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
