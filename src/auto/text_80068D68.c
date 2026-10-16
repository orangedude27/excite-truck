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

extern const char lbl_80313BB0[];
extern const char lbl_80313BCC[];
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
        ((void (*)(s32, void *))lbl_8055DC68->close)(0, lbl_8055DC6C);
    } else {
        GKI_freebuf(lbl_8055DC6C);
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
    if (lbl_8055DC68 != NULL) {
        if (lbl_8055DC68->close != NULL) {
            ((void (*)(s32, void *))lbl_8055DC68->close)(0, lbl_8055DC6C);
        }
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

void fn_8007148C(s32 arg0) {
    fn_800716B0((void **)((u8 *)&lbl_803C0AD8 + 0x68), arg0, &lbl_803C0AD8);
}

void fn_8007146C(s32 arg0, u16 arg1, s32 arg2) {
    ptim_start_timer((tPTIM_CB *)((u8 *)&lbl_803C0AD8 + 0x68), (TIMER_LIST_ENT *)arg0, arg1, arg2);
}

void fn_80072C38(void) {
    BTM_CancelRemoteDeviceName();
}

void fn_80073A1C(void) {

}

void fn_8007AD38(void) {

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
        GKI_start_timer(p_cb->timer_id, (p_cb->period + 9) / 10, TRUE);
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

void fn_80089E3C(void) {

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

