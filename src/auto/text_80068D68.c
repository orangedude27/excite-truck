// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <stdarg.h>
#include <printf.h>
#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#define btsnd_hcic_reject_conn btsnd_hcic_reject_conn_public
#define btsnd_hcic_reject_esco_conn btsnd_hcic_reject_esco_conn_public
#define btsnd_hcic_accept_conn btsnd_hcic_accept_conn_public
#define btsnd_hcic_write_cur_iac_lap btsnd_hcic_write_cur_iac_lap_hcimsgs
#define btsnd_hcic_exit_sniff_mode btsnd_hcic_exit_sniff_mode_api
#define btsnd_hcic_sniff_mode btsnd_hcic_sniff_mode_api
#define btsnd_hcic_accept_esco_conn btsnd_hcic_accept_esco_conn_api
#include "revolution/BTE/stack/include/hcimsgs.h"
#undef btsnd_hcic_accept_esco_conn
#undef btsnd_hcic_sniff_mode
#undef btsnd_hcic_exit_sniff_mode
#undef btsnd_hcic_write_cur_iac_lap
#undef btsnd_hcic_accept_conn
#undef btsnd_hcic_reject_esco_conn
#undef btsnd_hcic_reject_conn
#include "revolution/BTE/bta/include/ptim.h"
extern int btsnd_hcic_reject_conn(void *, u8 *, u8);
extern int btsnd_hcic_reject_esco_conn(void *, u8 *, u8);
#include "revolution/BTE/gki/platform/gki_int.h"
#include "revolution/BTE/gki/common/gki.h"
#include <revolution/OS.h>
#include "revolution/BTE/stack/include/hiddefs.h"
extern u8 HID_HostCloseDev(u8);
static tBTM_STATUS btm_set_inq_event_filter(UINT8, UINT8 *);

typedef struct {
    u8 in_use;
    u8 pad_0x01[9];
    u8 state;
    u8 pad_0x0B;
    u8 conn_tries;
    u8 pad_0x0D[0x0F];
    u8 timer_entry[0x18];
} tHID_HOST_DEV_VIEW;

extern void rfc_port_sm_execute(void *, u16, void *);
extern char lbl_80319AB0[];
extern char lbl_803160C0[];
extern char lbl_80319174[];
typedef struct uusb_cb_t {
    s32 fd;
    u8 pad4[0x0D];
    u8 endpoint;
    u8 pad12[0x0B];
    u8 pool_id;
    u8 pad1E[0x0A];
    u8 at_0x28;
    u8 state;
    u8 pad2A[2];
    BUFFER_Q acl_q;
    u8 pad38[4];
    BUFFER_Q sco_q;
} uusb_cb_t;
#define UUSB_CB_DEFINED_EARLY 1
extern uusb_cb_t lbl_803BD1E0;
extern u8 lbl_8055DC50;
extern u8 lbl_8055DC51;
extern void uusb_CloseDeviceCB(s8);
extern void rfc_port_sm_state_closed(void *, u16, void *);
extern void rfc_port_sm_sabme_wait_ua(void *, u16, void *);
extern void rfc_port_sm_orig_wait_sec_check(void *, u16, void *);
extern void rfc_port_sm_term_wait_sec_check(void *, u16, void *);
extern void rfc_port_sm_opened(void *, u16, void *);
extern void rfc_port_sm_disc_wait_ua(void *, s32, void *);
extern void GAP_Init(void);
extern void bta_sys_init(void);
extern void fn_80071510(void *, s32, u8);
extern u8 *lbl_80559018;
extern u8 lbl_803C0D18[];
extern void bta_dm_pm_cback(u8, u8, u8, u8 *);
extern void bta_dm_pm_btm_cback(void *, s8, s16, s8);

extern void fn_800716F0(void *);
extern void bta_hh_clean_up_kdev(void *);
extern void fn_8006CF44(void *, void *, void *, void *, void *, u32);
extern void fn_8007BC88(void);
extern void fn_80076E70(void);
extern void fn_8007F588(s8);
extern void fn_8007D4C4(void);

extern void BTM_SendHciReset(void (*)(void));
extern void fn_80085384(u8 *, u8);
extern void RFCOMM_Init(void);
extern void rfcomm_l2cap_if_init(void);
extern int btu_hcif_send_cmd();
extern void fn_80085524(void *, void *);
extern void fn_800869CC(void);
extern void DBPrintf_8006CFA8(const char *, ...);
extern char lbl_80313464[];
extern char lbl_8031347C[];
extern u32 lbl_8055DC30;
extern u8 lbl_8055DC34;
extern void fn_800709FC(void);
extern void fn_8006EBAC(void);
extern void fn_8006EB88(void);
extern void fn_80071508(u8);
extern void fn_800716B0(void *, s32, void *);
extern u8 fn_80089E20(u8);
extern u8 fn_80096670(u8);
extern void SCInit(void);
extern char lbl_80315700[];
extern u8 lbl_802EEB60[];
extern u8 lbl_802EEC40[];
extern u8 lbl_802EEBD8[];
extern char *bta_hh_evt_code(u32);
extern char lbl_8031A188[];
extern char lbl_803192C0[];
extern char lbl_803192E0[];
extern void *port_find_dlci_port(unsigned int);
extern void rfc_port_timer_start(void *, u16);
extern void port_select_mtu(void *);
extern void fn_800936BC(void *, u16, u16, u16, u16, u16, u16);
extern void rfc_send_dm(void *, u8, u8);
extern unsigned char lbl_803C0A50[];
extern void UUSB_Write(u8, u8 *, u16, BT_HDR *);
extern void sdp_connect_ind(u8 *, u16, u16, u8);
extern void sdp_connect_cfm(u16, u16);
extern void sdp_config_ind(u16, void *);
extern void sdp_config_cfm(u16);
extern void sdp_disconnect_ind(u16, u8);
extern void sdp_disconnect_cfm(u16, u16);
extern void sdp_data_ind(u16, void *);
extern u8 lbl_80317C20[];
extern u8 HID_HostOpenDev(u32);
extern u8 HID_HostRemoveDev(u32);
extern u8 HID_HostAddDev(u8 *, u16, u8 *);
extern s32 HID_HostSetSecurityLevel(void *, u8);
extern char lbl_803152B0[];
extern char lbl_803152D0[];
extern u8 lbl_80559058[];
extern char lbl_80319278[];
extern char lbl_80319290[];
extern void RFCOMM_ParNegReq(void *, s32, s32);
extern void rfc_release_multiplexer_channel(void *);
extern void port_release_port(void *);
extern void rfc_check_mcb_active(void *);
extern u8 lbl_803C3AF0[];
extern char lbl_80317700[];
extern void hidd_pm_set_now(void *);
extern void fn_80086468(void *);
extern u8 lbl_803C4040[];
extern void l2c_init(void);
extern char lbl_803181F0[];
extern void fn_80089E40(void *, u8, void *);
extern u8 lbl_803151D8[];
extern char lbl_8031801C[];
extern char lbl_80318040[];
extern char lbl_8031806C[];
extern char lbl_80318090[];
extern void *l2cu_find_lcb_by_bd_addr(u8 *addr);
extern void l2cu_create_conn_after_switch(void *p_lcb);
extern u8 lbl_803130C8[];
extern u8 lbl_80392960[];
extern u8 lbl_80393058[];
extern char lbl_80313238[];
extern u8 lbl_803C0D48[];
extern u8 lbl_803C3C38[];
extern u8 lbl_8031787C[];
extern char lbl_80317838[];
extern void *l2cu_find_ccb_by_cid(void *, u16);
extern u8 lbl_803C0B98[];
extern char lbl_80316E08[];
extern u32 lbl_8055DCA4;
extern void fn_80070F90(void *ptr);
extern u8 lbl_803C4C40[];
extern char lbl_8031A50C[];
extern u8 lbl_80317298[];
extern UINT8 lbl_802EED40[];
extern void fn_80099F58(void *);
#include "revolution/BTE/stack/sdp/sdpint.h"
typedef struct {
    UINT32 record_handle;
    UINT32 free_pad_ptr;
    UINT16 num_attributes;
    tSDP_ATTRIBUTE attribute[0x36];
    UINT8 attr_pad[4];
} tSDP_RECORD_VIEW;
typedef struct { UINT8 pad[0x476]; UINT16 cont_offset; } tSDP_CCB_CONT_VIEW;
static void process_service_attr_rsp(tCONN_CB *, UINT8 *, UINT16);
typedef struct { UINT8 pad[0x418]; UINT32 handles[0x15]; } tSDP_CCB_HANDLE_VIEW;
typedef struct { UINT8 pad[0x24]; UINT16 list_len; UINT8 list_data[1]; } tSDP_CCB_RAW_LIST_VIEW;
extern char lbl_80317A54[];
extern char lbl_80317A80[];
#include "revolution/BTE/stack/include/wbt_api.h"
extern void AXFXReverbHiExpShutdown(void*);
extern s32 AXFXReverbHiExpInit(void*);
extern void __FreeDelayLine(void*);
extern s32 __CtrlMsgInt(s32,s32,s32,s32,s32,u32,void*,void*,void*,s32);
extern f32 lbl_80560D50;
extern f32 lbl_80560D54;
extern u32 lbl_80560D28;

typedef struct {
    void *earlyLine[3];
    u8 pad0C[0x20];
    void *preDelayLine[3];
    u8 pad38[0x0C];
    void *combLine[3][3];
    u8 pad68[0x30];
    void *allpassLine[3][2];
    u8 padB0[0x18];
    void *lastAllpassLine[3];
} AXFX_REVERBHI_EXP_FREE_VIEW;

extern u8 lbl_803C0F78[];
extern char lbl_80316870[];
extern char lbl_80315D00[];
extern char lbl_8031669C[];
extern char lbl_80317720[];
extern tBTM_SEC_DEV_REC *btm_find_oldest_dev(void);
extern u8 lbl_80316570[];
extern u8 lbl_80315FBC[];

typedef struct {
    UINT16 dl_len;
    UINT8 *dsc_list;
} tBTA_HH_DEV_DESCR;

typedef struct {
    UINT16 vendor_id;
    UINT16 product_id;
    UINT16 version;
    UINT16 ssr_max_latency;
    UINT16 ssr_min_tout;
    UINT8 ctry_code;
    tBTA_HH_DEV_DESCR descriptor;
} tBTA_HH_DEV_DSCP_INFO;

typedef struct {
    tBTA_HH_DEV_DSCP_INFO dscp_info;
    UINT8 addr[6];
    UINT16 attr_mask;
    UINT16 w4_evt;
    UINT8 index;
    UINT8 sub_class;
    UINT8 sec_mask;
    UINT8 app_id;
    UINT8 hid_handle;
    UINT8 vp;
    UINT8 in_use;
    UINT8 incoming_conn;
    UINT8 opened;
    UINT8 mode;
    UINT8 state;
} tBTA_HH_DEV_CB;

typedef struct {
    UINT8 kb_cb[0x100];
    tBTA_HH_DEV_CB kdev[0x10];
    tBTA_HH_DEV_CB *p_cur;
    UINT8 cb_index[0x10];
    void (*p_cback)(int, void *);
    void *p_disc_db;
    UINT8 trace_level;
    UINT8 cnt_num;
    UINT8 w4_disable;
} tBTA_HH_CB;

extern tBTA_HH_CB *bta_hh_cb_ptr;
#define bta_hh_cb (*bta_hh_cb_ptr)

enum { BTA_HH_OK = 0, BTA_HH_ERR = 1 };
#define HID_SUCCESS 0
#define BTA_HH_MAX_KNOWN 0x10
extern u8 HID_HostDeregister(void);

/* BTM (btm_int.h / btm_api.h / bt_types.h) types for btm_read_link_policy_complete */
typedef struct {
    UINT16 hci_handle;
    UINT16 pkt_types_mask;
    UINT16 restore_pkt_types;
    UINT16 clock_offset;
    UINT8 remote_addr[6];
    UINT8 remote_dc[3];
    char remote_name[24];
    UINT16 manufacturer;
    UINT16 lmp_subversion;
    UINT16 link_super_tout;
    UINT8 features[8];
    UINT8 lmp_version;
    UINT8 in_use;
    UINT8 link_role;
    UINT8 link_up_issued;
    UINT8 switch_role_state;
    UINT8 change_key_state;
    UINT8 encrypt_state;
    UINT8 mode;
} tACL_CONN_LKP;

typedef struct {
    UINT16 dummy;
    void *p_rlinkp_cmpl_cb;
    void *rlinkp_timer;
} tBTM_DEVCB_LKP;

typedef struct {
    tACL_CONN_LKP acl_db[7];
    tBTM_DEVCB_LKP devcb;
} tBTM_CB_LKP;

extern tBTM_CB_LKP *btm_cb_ptr_lkp;
#define btm_cb_lkp (*btm_cb_ptr_lkp)

typedef void (*tBTM_CMPL_CB_LKP)(void *p1);
typedef struct {
    UINT8 status;
    UINT8 hci_status;
    UINT8 rem_bda[6];
    UINT16 settings;
} tBTM_LNK_POLICY_RESULTS_LKP;
void btu_stop_timer(void *);
#define BTA_HH_DISABLE_EVT 1
#define BTA_HH_API_CLOSE_EVT 0x1701
extern void bta_hh_sm_execute(tBTA_HH_DEV_CB *p_cb, UINT16 event, void *p_data);
extern u8 lbl_80315CA0[];
extern u8 lbl_80559060[1];
extern s32 btsnd_hcic_reset_800857CC(void);
extern u8 lbl_803C0AD8[];
extern u8 lbl_8055DC80;
extern u8 *lbl_80559038;
extern void bta_hh_trace_dev_db(void);

static inline u8 hh_get_trans_status(u32 result) {
    switch (result) {
    case 0:
        return 0;
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        return (u8)result;
    default:
        return 5;
    }
}
extern void fn_8006E6E4(void *);
extern void fn_80071450(void *);
  extern void fn_80070954(u32 code, void *msg, u16 param);
  extern char lbl_803196B8[];
extern char lbl_803164F4[];
extern char lbl_80319D48[];
extern char lbl_80319EC0[];
extern void fn_8007096C(u32 code, void *msg, u16 param1, u16 param2);
extern void fn_800709CC(u32 code, void *msg, s32 param1, s32 param2, u16 param3, u16 param4, u8 param5, u16 param6);
extern u8 lbl_803C4828[];
struct t_port_info;
extern void rfc_inc_credit(struct t_port_info *, u8);
extern void rfc_send_fcon(void *, s32, void *);
extern void rfc_send_fcon_80093FDC(void *, s32);
extern void PORT_FlowInd(void *, s32, s32);
extern void PORT_LineStatusInd(void *, u8, u8);
extern u32 port_rfc_send_tx_data(void *);
extern void *port_find_mcb_dlci_port(void *mcb, u8 dlci);
extern void rfc_port_timer_stop(void *);
extern void rfc_send_rls(void *, u8, s32, u8);
extern void rfc_check_send_cmd(void *, void *);
extern void rfc_send_pn(void *, s32, s32, s32, s32, s32);
extern void fn_800916F4(void *, s32, s16 *);
extern char lbl_803140D0[];
extern char lbl_80315048[];
extern u8 lbl_803C0C14[];
extern void bta_dm_signal_strength_timer_cback(void *);
extern s32 fn_8008128C(void *);
extern char lbl_803140E8[];
extern char lbl_8031A2C0[];
extern char lbl_8031A2EC[];
extern char lbl_803157DC[];
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
extern const char lbl_805590A4;
extern char lbl_8031A620[];
extern u8 lbl_8055DC90;
#include "revolution/BTE/stack/include/sdp_api.h"
#include "revolution/BTE/stack/include/l2c_api.h"
#include "revolution/BTE/stack/include/hidd_api.h"
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

extern char lbl_803131A4[];
s32 fn_80068DB8(void *arg0) {
    DBPrintf_8006CFA8(lbl_803131A4);
    return (*(s32 (**)(void *))(lbl_80392960 + 0x674))(arg0);
}

extern char lbl_803131B4[];
void fn_80068E08(s32 arg0) {
    DBPrintf_8006CFA8(lbl_803131B4);
    ((void (*)(s32))(*(u32 *)(lbl_80392960 + 0x678)))(arg0);
}

extern char lbl_803131C4[];
void SyncFlushCallback(s32 arg0) {
    DBPrintf_8006CFA8(lbl_803131C4, arg0, lbl_80392960[0xC]);
    if (lbl_80392960[0xC] != 0) {
        if (arg0 == 0)
            lbl_80392960[0xC] = 0x17;
        else
            lbl_80392960[0xC] = 0xFF;
    }
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

s32 WUDiDeleteDevice(void)
{
    s32 i;
    u8 *entry;
    s32 j;
    u8 *entry2;
    u32 interrupt_state;
    u8 busy;
    register u8 *base = lbl_80392960;

    interrupt_state = OSDisableInterrupts();
    busy = base[0x665];
    OSRestoreInterrupts(interrupt_state);
    if (busy != 0)
        return 3;

    for (i = 0, entry = base + 0x64; i < 10; i++, entry += 0x60) {
        if (entry[0x59] == 1)
            fn_8006B598(entry + 0x40);
    }
    for (j = 0, entry2 = base + 0x424; j < 6; j++, entry2 += 0x60) {
        if (entry2[0x59] == 1)
            fn_8006B598(entry2 + 0x40);
    }
    return 5;
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

extern void WUDStoredLinkKeyCallback(void *);
extern void *WUDiGetDevInfo(u8 *);
u8 WUDiClearUnregisteredDevice(void) {
    s32 index;
    s32 offset;
    u8 *base;
    u8 *entry;

    if (lbl_80392960[0xE] != 0)
        return 2;
    base = lbl_80392960;
    index = 0;
    offset = 0;
    while (index < 0x10) {
        s32 interrupt = OSDisableInterrupts();
        if (index < 0 || index >= 10)
            entry = base + (index - 10) * 0x60 + 0x424;
        else
            entry = base + offset + 0x64;
        OSRestoreInterrupts(interrupt);
        if (entry[0x59] != 0) {
            if (entry[0x5C] == 1) {
                base[0xE] = 3;
                BTM_DeleteStoredLinkKey(entry + 0x40, WUDStoredLinkKeyCallback);
                entry[0x5C] = 0;
                return 2;
            }
            if (entry[0x5C] != 3) {
                void *info = WUDiGetDevInfo(entry + 0x40);
                if (info != 0) {
                    interrupt = OSDisableInterrupts();
                    memset(info, 0, 0x60);
                    OSRestoreInterrupts(interrupt);
                }
            }
        }
        index++;
        offset += 0x60;
    }
    return 3;
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
        if (SCCheckStatus() == 0 && SCSetBtDeviceInfoArray(lbl_80393058) != 0) {
            SCFlushAsync(fn_80068F28);
            state = 2;
        } else {
            state = 1;
        }
        base[0x11] = state;
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

s32 fn_8006A460(s32 arg0) {
    register u8 *var_r6;
    register u32 temp_r10;
    s32 temp_r26;
    s32 temp_r3;
    s32 var_ctr;
    register u32 var_r10;
    u64 temp_ret;
    void *temp_r7;
    void *temp_r8;
    void *temp_r9;
    void *var_r0;
    void *var_r0_2;
    void *var_r0_3;
    void *var_r0_4;
    u32 ready;
    u8 *base;
    u8 *setup;
    u32 *words;
    u16 *shorts1;
    u16 *shorts2;
    s32 init_zero = 0;
    register s32 old_state;
    register s32 lock_state;
    s32 i;
    register s32 n;
    register u32 zero = 0;
    register u32 one = 1;
    OSTime now;
    u32 scale;

    if ((ready = lbl_8055DC30, base = lbl_80392960, setup = base, ready != 0)) {
        return 0;
    }
    old_state = OSDisableInterrupts();
    words = (u32 *)(base + 0xCC8);
    shorts1 = (u16 *)(base + 0x1D20);
    shorts2 = (u16 *)(base + 0x1D40);
    for (i = 0; i < 16; i++) {
        words[i] = init_zero;
        shorts1[i] = init_zero;
        shorts2[i] = init_zero;
    }

    *(u8 **)(setup + 0x18) = setup + 0x58;
    *(u8 **)(setup + 0x14) = setup + 0x1C;
    var_r6 = setup;
    for (i = 0, var_r10 = 0; i < 3; i++) {
        *(u8 **)(var_r6 + 0x1C) = setup + (5 - var_r10) * 0x60 + 0x424;
        if (var_r10 == 0) {
            var_r0 = 0;
        } else {
            var_r0 = setup + (var_r10 - 1) * 0xC + 0x1C;
        }
        *(u8 **)(var_r6 + 0x20) = var_r0;
        if (var_r10 == 5) {
            var_r0_2 = 0;
        } else {
            var_r0_2 = setup + (var_r10 + 1) * 0xC + 0x1C;
        }
        temp_r10 = var_r10 + 1;
        *(u8 **)(var_r6 + 0x24) = var_r0_2;
        *(u8 **)(var_r6 + 0x28) = setup + (5 - temp_r10) * 0x60 + 0x424;
        if (temp_r10 == 0) {
            var_r0_3 = 0;
        } else {
            var_r0_3 = setup + (temp_r10 - 1) * 0xC + 0x1C;
        }
        *(u8 **)(var_r6 + 0x2C) = var_r0_3;
        if (temp_r10 == 5) {
            var_r0_4 = 0;
        } else {
            var_r0_4 = setup + (temp_r10 + 1) * 0xC + 0x1C;
        }
        *(u8 **)(var_r6 + 0x30) = var_r0_4;
        var_r6 += 0x18;
        var_r10 = temp_r10 + 1;
    }

    *(u32 *)(setup + 0) = zero;
    *(u32 *)(setup + 4) = zero;
    *(u32 *)(setup + 8) = zero;
    *(u32 *)(setup + 0x670) = zero;
    *(u32 *)(setup + 0x66C) = zero;
    *(u8 *)(setup + 0xC) = zero;
    *(u8 *)(setup + 0xE) = zero;
    *(u8 *)(setup + 0xD) = zero;
    *(u8 *)(setup + 0xF) = zero;
    *(u8 *)(setup + 0x10) = zero;
    *(u8 *)(setup + 0x11) = zero;
    *(u8 *)(setup + 0x667) = zero;
    *(u8 *)(setup + 0x669) = zero;
    *(u8 *)(setup + 0x668) = one;
    *(u8 *)(setup + 0x66A) = zero;
    *(u8 *)(setup + 0x66B) = zero;
    *(u8 *)(setup + 0x688) = zero;
    *(u8 *)(setup + 0x68A) = zero;
    *(s8 *)(setup + 0x68B) = -0x41;
    memset(setup + 0x682, 0, 6);
    memset(setup + 0x67C, 0, 6);
    *(u16 *)(setup + 0x6C4) = zero;
    *(u16 *)(setup + 0x6C6) = 0xA;

    lock_state = OSDisableInterrupts();
    memset(base + 0x64, 0, 0x3C0);
    memset(base + 0x424, 0, 0x240);
    *(u8 *)(base + 0x12) = 0;
    *(u8 *)(base + 0x13) = 0;
    *(u8 *)(base + 0x664) = 0;
    *(u8 *)(base + 0x665) = 0;
    *(u8 *)(base + 0x666) = 0;
    OSRestoreInterrupts(lock_state);
    *(u8 *)(setup + 0x10) = one;
    OSRestoreInterrupts(old_state);

    DBPrintf_8006CFA8(lbl_80313464);
    fn_800709FC();
    fn_80071508(lbl_8055DC34);
    fn_80089E20(lbl_8055DC34);
    fn_80096670(lbl_8055DC34);
    DBPrintf_8006CFA8(lbl_8031347C);
    SCInit();

    OSCreateAlarm((OSAlarm *)(setup + 0x690));
    now = __OSGetSystemTime();
    scale = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 10;
    ((void (*)(void *, u64, u32, u32, void (*)(u32, u32)))OSSetPeriodicAlarm)(
        setup + 0x690, now, 0, scale, (void (*)(u32, u32))fn_8006A39C);
    lbl_8055DC30 = 1;
    return 1;
}

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
    u8 *pm_ids = lbl_80392960;
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
    BTM_SetPowerMode(pm_ids[0x68A], addr, &block);
}

extern char lbl_803134A0[];
void (*WUDSetSyncSimpleCallback(void (*pCallback)(s32, s32)))(s32, s32) {
    void (*pOldCallback)(s32, s32);
    s32 enabled;
    DBPrintf_8006CFA8(lbl_803134A0);
    enabled = OSDisableInterrupts();
    pOldCallback = *(void (**)(s32, s32))(lbl_80392960 + 4);
    *(void (**)(s32, s32))(lbl_80392960 + 4) = pCallback;
    OSRestoreInterrupts(enabled);
    return pOldCallback;
}

extern char lbl_803134F0[];
extern s32 StartSyncDevice(u8, s8, BOOL);
s32 WUDStartFastSyncSimple(void) {
    s32 started;
    BOOL interrupts;
    void (*callback)(s32, s32);
    DBPrintf_8006CFA8(lbl_803134F0);
    started = StartSyncDevice(1, -1, 0);
    interrupts = OSDisableInterrupts();
    callback = *(void (**)(s32, s32))(lbl_80392960 + 4);
    OSRestoreInterrupts(interrupts);
    if (started == 0 && callback != 0)
        callback(-1, 0);
    return started;
}

extern char lbl_80313520[];
extern void fn_80073CA8(void);
s32 fn_8006AC4C(void) {
    s32 interrupts;
    s32 result;
    register u8 *state;
    DBPrintf_8006CFA8(lbl_80313520);
    state = lbl_80392960;
    result = 0;
    interrupts = OSDisableInterrupts();
    if ((s8)state[0x688] == 3) {
        if (state[0xC] == 3)
            fn_80073CA8();
        result = 1;
        state[0x668] = 0;
    }
    OSRestoreInterrupts(interrupts);
    return result;
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
    DBPrintf_8006CFA8(lbl_80313584);
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
    DBPrintf_8006CFA8(lbl_803135A0);
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
        count = count < 0x13 ? count : 0x13;
        packet[0] = count;
        count = (u8)count;
        size = count * 0xD;
        memcpy(packet + 1, lbl_80313600 + lbl_8055DC39 * 0xD + 1, size);
        lbl_8055DC39 += count;
        BTM_VendorSpecificCommand(0xFC4F, size + 1, packet, fn_8006B26C);
        return;
    }
    fn_8006B330();
}

extern u8 BTA_DmAddDevice(u8 *, u8 *, u32, u8);
extern void BTA_HhAddDev(const u8 *, u16, u8, u8, const void *);
void fn_8006B488(void) {
    u8 *base = lbl_803130C8;
    u8 *control = lbl_80392960;
    u8 *info = (u8 *)((void *(*)(void))WUDiGetDevInfo)();
    u8 status;
    BOOL interrupt;
    u8 state;
    f64 argData;
    u16 sp10;
    u32 sp14;
    status = BTA_DmAddDevice(info + 0x40, info + 0x46, 0, 0);
    DBPrintf_8006CFA8((const char *)(base + 0x5D8), status);
    if (memcmp(info, base + 0x1A0, 0x10) == 0) {
        sp14 = (u32)base;
        sp10 = 0xD9;
        DBPrintf_8006CFA8((const char *)(base + 0x5F0));
        argData = *(f64 *)&sp10;
        BTA_HhAddDev(info + 0x40, *(u16 *)(info + 0x5E), info[0x57], info[0x58], &argData);
    }
    interrupt = OSDisableInterrupts();
    state = info[0x5B];
    if (state == 0 || state == 4 || state == 2 || state == 5) {
        control[0x12]++;
    } else {
        control[0x13]++;
    }
    OSRestoreInterrupts(interrupt);
}

#pragma use_lmw_stmw off
void *WUDiGetDevInfo(u8 *addr) {
    struct WUDDevInfoView {
        u8 pad[0x40];
        u8 addr[6];
        u8 pad2[0x1A];
    };
    struct WUDControlView {
        u8 pad[0x64];
        struct WUDDevInfoView stdDevs[10];
        struct WUDDevInfoView smpDevs[6];
    };
    struct WUDControlView *control;
    void *result;
    s32 interrupt;
    s32 i;
    u8 *entry;

    control = (struct WUDControlView *)lbl_80392960;
    result = 0;
    interrupt = OSDisableInterrupts();
    entry = control->stdDevs[0].addr;
    for (i = 0; i < 10; i++, entry += 0x60) {
        if (memcmp(entry, addr, 6) == 0) {
            result = &control->stdDevs[i];
            break;
        }
    }
    if (result == 0) {
        entry = control->smpDevs[0].addr;
        for (i = 0; i < 6; i++, entry += 0x60) {
            if (memcmp(entry, addr, 6) == 0) {
                result = &control->smpDevs[i];
                break;
            }
        }
    }
    OSRestoreInterrupts(interrupt);
    return result;
}
#pragma use_lmw_stmw on
extern char lbl_8031377C[];
void *WUDiGetNewDevInfo(void) {
    struct DevInfo { u8 data[0x60]; };
    struct WUDView { u8 pad[0x64]; struct DevInfo stdDevs[1]; };
    u8 *base = lbl_80392960;
    u8 *entry;
    void *result = 0;
    BOOL enabled;
    u32 i;

    enabled = OSDisableInterrupts();
    if (base[0x669] == 0) {
        entry = base;
        for (i = 0; i < 10; i++) {
            if (entry[0xBD] == 0) {
                DBPrintf_8006CFA8(lbl_8031377C, i);
                result = &((struct WUDView *)base)->stdDevs[i];
                break;
            }
            entry += 0x60;
        }
    } else {
        result = *(void **)*(void ***)(base + 0x18);
    }
    OSRestoreInterrupts(enabled);
    return result;
}

void WUDiMoveTopSmpDevInfoPtr(void *arg0, void *arg1) {
    u8 *base = lbl_80392960;
    u8 *node;
    u8 *entry;
    s32 i;
    BOOL enabled = OSDisableInterrupts();

    for (i = 0, node = base; i < 6; i++, node += 0xC) {
        if (memcmp(*(u8 **)(node + 0x1C) + 0x40, (u8 *)arg0 + 0x40, 6) == 0) {
            entry = base + i * 0xC;
            if (memcmp(*(u8 **)(*(void **)(base + 0x14)) + 0x40,
                       *(u8 **)(entry + 0x1C) + 0x40, 6) != 0) {
                u8 *next = *(u8 **)(entry + 0x24);
                u8 *prev = *(u8 **)(entry + 0x20);
                *(u8 **)(prev + 8) = next;
                if (memcmp(*(u8 **)(*(void **)(base + 0x18)) + 0x40,
                           *(u8 **)(entry + 0x1C) + 0x40, 6) == 0) {
                    *(u8 **)(base + 0x18) = prev;
                } else {
                    *(u8 **)(next + 4) = prev;
                }
                *(u8 **)(entry + 0x24) = *(u8 **)(base + 0x14);
                *(u8 **)(*(u8 **)(base + 0x14) + 4) = entry + 0x1C;
                *(u8 **)(base + 0x14) = entry + 0x1C;
                *(u8 **)(entry + 0x20) = 0;
            }
            break;
        }
    }
    OSRestoreInterrupts(enabled);
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

extern void gki_init_free_queue(UINT8, UINT16, UINT16, void *);
void gki_buffer_init(void)
{
    UINT8 i, tt, mb;
    tGKI_COM_CB *p_cb = &gki_cb.com;

    for (tt = 0; tt < GKI_MAX_TASKS; tt++) {
        for (mb = 0; mb < NUM_TASK_MBOX; mb++) {
            p_cb->OSTaskQFirst[tt][mb] = NULL;
            p_cb->OSTaskQLast[tt][mb] = NULL;
        }
    }

    for (tt = 0; tt < GKI_NUM_TOTAL_BUF_POOLS; tt++) {
        p_cb->pool_start[tt] = NULL;
        p_cb->pool_end[tt] = NULL;
        p_cb->pool_size[tt] = 0;
        p_cb->freeq[tt].p_first = 0;
        p_cb->freeq[tt].p_last = 0;
        p_cb->freeq[tt].size = 0;
        p_cb->freeq[tt].total = 0;
        p_cb->freeq[tt].cur_cnt = 0;
        p_cb->freeq[tt].max_cnt = 0;
    }

    p_cb->pool_access_mask = GKI_DEF_BUFPOOL_PERM_MASK;

    gki_init_free_queue(0, GKI_BUF0_SIZE, GKI_BUF0_MAX, p_cb->bufpool0);
    gki_init_free_queue(1, GKI_BUF1_SIZE, GKI_BUF1_MAX, p_cb->bufpool1);
    gki_init_free_queue(2, GKI_BUF2_SIZE, GKI_BUF2_MAX, p_cb->bufpool2);
    gki_init_free_queue(3, GKI_BUF3_SIZE, GKI_BUF3_MAX, p_cb->bufpool3);
    gki_init_free_queue(4, GKI_BUF4_SIZE, GKI_BUF4_MAX, p_cb->bufpool4);

    for (i = 0; i < GKI_NUM_FIXED_BUF_POOLS; i++)
        p_cb->pool_list[i] = i;
    p_cb->curr_total_no_of_pools = GKI_NUM_FIXED_BUF_POOLS;
}

void fn_8006D4C4(void *arg) {
    ((s32 *)arg)[1] = 0;
    ((s32 *)arg)[0] = 0;
    ((u16 *)arg)[4] = 0;
}

void *GKI_getpoolbuf(UINT8 pool_id) {
    extern u32 lbl_803946C0[];
    extern void fn_8006EBAC(void);
    extern void fn_8006EB88(void);
    extern u8 fn_8006EB80(void);
    FREE_QUEUE_T *Q;
    BUFFER_HDR_T *p_hdr;
    tGKI_COM_CB *p_cb = (tGKI_COM_CB *)((UINT8 *)lbl_803946C0 + 0x54);

    if (pool_id >= GKI_NUM_TOTAL_BUF_POOLS)
        return NULL;

    fn_8006EBAC();

    Q = &p_cb->freeq[pool_id];
    if (Q->cur_cnt < Q->total) {
        p_hdr = Q->p_first;
        Q->p_first = p_hdr->p_next;

        if (!Q->p_first)
            Q->p_last = NULL;

        if (++Q->cur_cnt > Q->max_cnt)
            Q->max_cnt = Q->cur_cnt;

        fn_8006EB88();

        p_hdr->task_id = fn_8006EB80();
        p_hdr->status = BUF_STATUS_UNLINKED;
        p_hdr->p_next = NULL;
        p_hdr->Type = 0;

        return (void *)((UINT8 *)p_hdr + BUFFER_HDR_SIZE);
    }

    fn_8006EB88();
    return GKI_getbuf(p_cb->freeq[pool_id].size);
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

void GKI_enqueue_head(BUFFER_Q *p_q, void *p_buf) {
    BUFFER_HDR_T *p_hdr;
#if (GKI_ENABLE_BUF_CORRUPTION_CHECK == TRUE)
    if (gki_chk_buf_damage(p_buf)) {
        GKI_exception(GKI_ERROR_BUF_CORRUPTED, "Enqueue - Buffer corrupted");
        return;
    }
#endif
    p_hdr = (BUFFER_HDR_T *)((UINT8 *)p_buf - BUFFER_HDR_SIZE);
    if (p_hdr->status != BUF_STATUS_UNLINKED) {
        GKI_exception(GKI_ERROR_ENQUEUE_BUF_LINKED, "Eneueue head - buf already linked");
        return;
    }
    GKI_disable();
    if (p_q->p_first) {
        p_hdr->p_next = (BUFFER_HDR_T *)((UINT8 *)p_q->p_first - BUFFER_HDR_SIZE);
        p_q->p_first = p_buf;
    } else {
        p_q->p_first = p_buf;
        p_q->p_last = p_buf;
        p_hdr->p_next = NULL;
    }
    p_q->count++;
    p_hdr->status = BUF_STATUS_QUEUED;
    GKI_enable();
    return;
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

void *GKI_remove_from_queue(BUFFER_Q *p_q, void *p_buf)
{
    BUFFER_HDR_T *p_hdr;
    BUFFER_HDR_T *p_prev;

    fn_8006EBAC();
    if (p_buf == p_q->p_first) {
        fn_8006EB88();
        return GKI_dequeue(p_q);
    }

    p_hdr = (BUFFER_HDR_T *)((u8 *)p_buf - BUFFER_HDR_SIZE);
    p_prev = (BUFFER_HDR_T *)((u8 *)p_q->p_first - BUFFER_HDR_SIZE);
    while (p_prev != NULL) {
        if (p_prev->p_next == p_hdr) {
            p_prev->p_next = p_hdr->p_next;
            if (p_buf == p_q->p_last) {
                p_q->p_last = (u8 *)p_prev + BUFFER_HDR_SIZE;
            }
            p_q->count--;
            p_hdr->p_next = NULL;
            p_hdr->status = BUF_STATUS_UNLINKED;
            fn_8006EB88();
            return p_buf;
        }
        p_prev = (BUFFER_HDR_T *)p_prev->p_next;
    }

    fn_8006EB88();
    return NULL;
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

    switch (val) {
    default:
        return val + 8;
    case 0:
        return 0;
    }
}

u8 fn_8006DF84(void *arg0) {
    u16 val = *(u16 *)((u8 *)arg0 + 8);
    u32 tmp = __cntlzw(val);
    return tmp >> 5;
}

static UINT8 gki_set_pool_permission_local(UINT8 pool_id, UINT8 permission)
{
    tGKI_COM_CB *p_cb = &((tGKI_CB *)lbl_803946C0)->com;

    if (pool_id < GKI_NUM_TOTAL_BUF_POOLS) {
        if (permission == GKI_RESTRICTED_POOL)
            p_cb->pool_access_mask = (UINT16)(p_cb->pool_access_mask | (1 << pool_id));
        else
            p_cb->pool_access_mask = (UINT16)(p_cb->pool_access_mask & ~(1 << pool_id));
        return GKI_SUCCESS;
    }

    return GKI_INVALID_POOL;
}

static void gki_add_to_pool_list(UINT8 pool_id)
{
    INT32 i;
    INT32 j;
    tGKI_COM_CB *p_cb = (tGKI_COM_CB *)((u8 *)lbl_803946C0 + 0x54);

    for (i = 0; i < p_cb->curr_total_no_of_pools; i++) {
        if (p_cb->freeq[pool_id].size <= p_cb->freeq[p_cb->pool_list[i]].size)
            break;
    }

    for (j = p_cb->curr_total_no_of_pools; j > i; j--)
        p_cb->pool_list[j] = p_cb->pool_list[j - 1];

    p_cb->pool_list[i] = pool_id;
}

extern s32 fn_8006EBF4(void);
#pragma use_lmw_stmw off
UINT8 GKI_create_pool(UINT16 size, UINT16 count, UINT8 permission, void *p_mem_pool)
{
    UINT8 xx;
    UINT32 mem_needed;
    INT32 tempsize = size;
    tGKI_COM_CB *p_cb = &((tGKI_CB *)lbl_803946C0)->com;

    if (size > MAX_USER_BUF_SIZE)
        return GKI_INVALID_POOL;

    for (xx = 0; xx < GKI_NUM_TOTAL_BUF_POOLS; xx++) {
        if (!p_cb->pool_start[xx])
            break;
    }

    if (xx == GKI_NUM_TOTAL_BUF_POOLS)
        return GKI_INVALID_POOL;

    tempsize = (INT32)ALIGN_POOL(size);
    mem_needed = (tempsize + BUFFER_PADDING_SIZE) * count;

    if (!p_mem_pool)
        p_mem_pool = ((void *(*)(UINT32))fn_8006EBF4)(mem_needed);

    if (p_mem_pool) {
        gki_init_free_queue(xx, size, count, p_mem_pool);
        gki_add_to_pool_list(xx);

        if (xx < GKI_NUM_TOTAL_BUF_POOLS) {
            if (permission == 1)
                p_cb->pool_access_mask |= 1 << xx;
            else
                p_cb->pool_access_mask &= ~(1 << xx);
        }

        p_cb->curr_total_no_of_pools++;
        return xx;
    }

    return GKI_INVALID_POOL;
}
#pragma use_lmw_stmw reset
extern void fn_8006EBF0();
extern void fn_8006EC20();
extern char lbl_80314240[];
void GKI_delete_pool(u8 pool_id) {
    u8 *global = (u8 *)lbl_803946C0;
    u8 *pools = global + 0x30000;
    u8 *pool;
    s32 index;
    if (pool_id >= 9) return;
    if (*(u32 *)(pools + pool_id * 4 - 0x75E4) == 0) return;
    fn_8006EBAC();
    pool = pools + pool_id * 0x10 - 0x7668;
    if (*(u16 *)pool != 0) {
        ((void (*)(s32, const char *))fn_8006EBF0)(-8, lbl_80314240);
        fn_8006EB88();
        return;
    }
    *(u16 *)(pool - 4) = 0;
    *(u16 *)(pool - 2) = 0;
    *(u16 *)pool = 0;
    *(u16 *)(pool + 2) = 0;
    *(u32 *)(pool - 12) = 0;
    *(u32 *)(pool - 8) = 0;
    ((void (*)(s32))fn_8006EC20)(*(s32 *)(pools + pool_id * 4 - 0x75E4));
    *(u32 *)(pools + pool_id * 4 - 0x75E4) = 0;
    *(u32 *)(pools + pool_id * 4 - 0x75C0) = 0;
    *(u16 *)(pools + pool_id * 2 - 0x759C) = 0;
    index = 0;
    while (index < global[0x28A87] && global[0x28A7E + index] != pool_id) index++;
    for (; index < global[0x28A87] - 1; index++)
        global[0x28A7E + index] = global[0x28A7F + index];
    global[0x28A87]--;
    fn_8006EB88();
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

void GKI_start_timer(UINT8 tnum, INT32 ticks, BOOLEAN is_continuous) {
    UINT8 task_id;
    INT32 repeat;
    INT32 total;
    INT32 start;
    INT32 end;
    u8 *base;

    task_id = GKI_get_taskid();
    if (ticks <= 0)
        ticks = 1;
    repeat = ticks & ((-(INT32)is_continuous | (INT32)is_continuous) >> 31);
    GKI_disable();

    base = (u8 *)&lbl_803946C0 + 0x30000;
    start = *(INT32 *)(base - 0x77C8);
    end = *(INT32 *)(base - 0x77C4);
    total = end - start;
    if ((INT32)(0x7fffffff - total) > ticks)
        total += ticks;
    else
        total = 0x7fffffff;

    if (tnum == 0) {
        *(INT32 *)(base - 0x7780 + ((task_id & 0xff) << 2)) = repeat;
        *(INT32 *)(base - 0x77A0 + ((task_id & 0xff) << 2)) = total;
    } else if (tnum == 1) {
        *(INT32 *)(base - 0x7740 + ((task_id & 0xff) << 2)) = repeat;
        *(INT32 *)(base - 0x7760 + ((task_id & 0xff) << 2)) = total;
    }

    if (tnum > 1 && ticks > 0 && (end == 0 || (ticks < start && start > 0))) {
        *(INT32 *)(base - 0x77C4) = ticks + (end - start);
        *(INT32 *)(base - 0x77C8) = ticks;
    }
    GKI_enable();
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

void GKI_add_to_timer_list(TIMER_LIST_Q *p_timer_list, TIMER_LIST_ENT *p_tle) {
    TIMER_LIST_ENT *p_entry;
    INT32 ticks;

    if (p_tle->ticks < 0) return;
    if (p_tle->ticks >= p_timer_list->last_ticks) {
        if (p_timer_list->p_first == NULL) {
            p_timer_list->p_first = p_tle;
        } else {
            if (p_timer_list->p_last != NULL) p_timer_list->p_last->p_next = p_tle;
            p_tle->p_prev = p_timer_list->p_last;
        }
        p_tle->p_next = NULL;
        p_timer_list->p_last = p_tle;
        ticks = p_tle->ticks;
        p_tle->ticks = ticks - p_timer_list->last_ticks;
        p_timer_list->last_ticks = ticks;
    } else {
        p_entry = p_timer_list->p_first;
        while (p_tle->ticks > p_entry->ticks) {
            if (p_entry->ticks > 0) p_tle->ticks -= p_entry->ticks;
            p_entry = p_entry->p_next;
        }
        if (p_entry == p_timer_list->p_first) {
            p_tle->p_next = p_timer_list->p_first;
            p_timer_list->p_first->p_prev = p_tle;
            p_timer_list->p_first = p_tle;
        } else {
            p_entry->p_prev->p_next = p_tle;
            p_tle->p_prev = p_entry->p_prev;
            p_entry->p_prev = p_tle;
            p_tle->p_next = p_entry;
        }
        p_entry->ticks -= p_tle->ticks;
    }
    p_tle->in_use = 1;
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

extern s32 fn_80068DB8();
s32 fn_8006EBF4(void) {
    s32 r = fn_80068DB8();
    if (r == 0) {
        r = 0;
    }
    return r;
}

extern void fn_80068E08(s32);
void fn_8006EC20(void) {
    ((void (*)(void))fn_80068E08)();
}

void fn_8006EC24(s32 arg0, s32 arg1) {
    if (arg0 != 4) {
        if (arg0 >= 4) {
            return;
        }
        if (arg0 == 0) {
            return;
        }
        return;
    }
    fn_80070B24((s8)arg1);
}

__declspec(section ".sdata") extern u8 lbl_80560CF8[];
__declspec(section ".sdata") extern u8 lbl_80560D00[];
#pragma push
#pragma use_lmw_stmw off
s32 hcisu_h2_receive_msg(u16 arg0, u8 *arg1) {
    extern s32 fn_8007011C(void);
    extern void fn_8007093C(u32, void *);
    extern u16 fn_8006D8D0(u32);
    extern BT_HDR *l2cap_link_chk_pkt_start(BT_HDR *);
    extern BOOL l2cap_link_chk_pkt_end(void);
    extern char lbl_80314258[];
    extern char lbl_80314294[];
    u8 sp8;
    register u8 *var_r15 = arg1;
    register s32 var_r19 = 0;
    register u16 var_r16;
    register u8 *var_r22;
    register u32 var_r23;
    register u8 *var_r21;
    register u8 var_r17;
    register u8 var_r18;
    register u8 *buf;
    register u16 offset;
    register u16 remaining;
    register u16 len;
    register u16 got;

    if (var_r15[0x1E] != 2) return 0;
    var_r16 = (u16)(arg0 + 1);
    var_r22 = arg1 + arg0;
    var_r23 = ((u32)arg0 << 2) & 0x3FFFC;
    var_r21 = arg1 + (((u32)arg0 << 1) & 0x1FFFE);
for (;;) {
    if ((u16)((u16 (*)(u8, u8 *, u16))fn_8007011C)((u8)var_r16, &sp8, 1) == 0)
        break;
    var_r17 = 0;
    var_r19 += 1;
    switch (var_r22[0x1A]) {
    case 0:
        if (var_r16 == 1) {
            *(void **)(var_r15 + var_r23) = GKI_getpoolbuf(2);
            var_r22[0x14] = 4;
        } else if (var_r16 == 2) {
            *(void **)(var_r15 + var_r23) = GKI_getpoolbuf(3);
            var_r22[0x14] = 2;
        } else if (var_r16 == 3) {
            *(void **)(var_r15 + var_r23) = GKI_getpoolbuf(1);
            var_r22[0x14] = 3;
        }
        buf = *(u8 **)(var_r15 + var_r23);
        if (buf != 0) {
            *(u16 *)(buf + 2) = 0;
            *(u16 *)buf = *(u16 *)(lbl_80560D00 + (var_r22[0x14] * 2) - 2);
            *(u16 *)(buf + 4) = 0;
            var_r22[0x1A] = 1;
        } else {
            fn_8007093C(0x70000, lbl_80314258);
            var_r22[0x1A] = 2;
        }
        *(u16 *)(var_r21 + 0xC) = lbl_80560CF8[var_r22[0x14] - 1];
        /* fall through */
    case 1:
        buf = *(u8 **)(var_r15 + var_r23);
        offset = *(u16 *)(buf + 2);
        buf[offset + 8] = sp8;
        *(u16 *)(buf + 2) = offset + 1;
        remaining = *(u16 *)(var_r21 + 0xC) - 1;
        *(u16 *)(var_r21 + 0xC) = remaining;
        if (remaining == 0) {
            var_r18 = sp8;
            if (var_r22[0x14] == 2) {
                var_r18 = (u8)(((u16)sp8 << 8) + var_r22[0x17]);
                buf = (u8 *)l2cap_link_chk_pkt_start((BT_HDR *)buf);
                *(u8 **)(var_r15 + var_r23) = buf;
                if (buf == 0) {
                    *(u16 *)(var_r21 + 0xC) = var_r18;
                    if (var_r18 == 0) var_r22[0x1A] = 0;
                    else var_r22[0x1A] = 4;
                    break;
                }
            }
            *(u16 *)(var_r21 + 0xC) = var_r18;
            if ((u32)var_r18 + lbl_80560CF8[var_r22[0x14] - 1] + 8 >
                fn_8006D8D0((u32)buf)) {
                GKI_freebuf(buf);
                *(u8 **)(var_r15 + var_r23) = 0;
                var_r22[0x1A] = 4;
                fn_8007093C(0x70000, lbl_80314294);
            } else if (var_r18 != 0) {
                var_r22[0x1A] = 3;
            } else {
                var_r22[0x1A] = 0;
                var_r17 = 1;
            }
        } else {
            var_r22[0x17] = sp8;
        }
        break;
    case 2:
        remaining = *(u16 *)(var_r21 + 0xC) - 1;
        *(u16 *)(var_r21 + 0xC) = remaining;
        if (remaining == 0) {
            var_r18 = sp8;
            if (var_r22[0x14] == 2)
                var_r18 = (u8)(((u16)sp8 << 8) + var_r22[0x17]);
            *(u16 *)(var_r21 + 0xC) = var_r18;
            var_r22[0x1A] = 4;
        } else {
            var_r22[0x17] = sp8;
        }
        break;
    case 3:
        buf = *(u8 **)(var_r15 + var_r23);
        offset = *(u16 *)(buf + 2);
        buf[offset + 8] = sp8;
        *(u16 *)(buf + 2) = offset + 1;
        remaining = *(u16 *)(var_r21 + 0xC) - 1;
        *(u16 *)(var_r21 + 0xC) = remaining;
        got = ((u16 (*)(u8, u8 *, u16, u8, BT_HDR *))fn_8007011C)(
            (u8)var_r16, buf + *(u16 *)(buf + 2) + 8, remaining, sp8, (BT_HDR *)buf);
        var_r19 += got;
        buf = *(u8 **)(var_r15 + var_r23);
        *(u16 *)(buf + 2) = *(u16 *)(buf + 2) + got;
        remaining = *(u16 *)(var_r21 + 0xC) - got;
        *(u16 *)(var_r21 + 0xC) = remaining;
        if (remaining == 0) {
            if (var_r22[0x14] == 2 && (u8)l2cap_link_chk_pkt_end() == 0) {
                var_r22[0x1A] = 0;
            } else {
                var_r22[0x1A] = 0;
                var_r17 = 1;
            }
        }
        break;
    case 4:
        remaining = *(u16 *)(var_r21 + 0xC) - 1;
        *(u16 *)(var_r21 + 0xC) = remaining;
        if (remaining == 0) var_r22[0x1A] = 0;
        break;
    default:
        var_r22[0x1A] = 0;
        break;
    }
    if (var_r17 != 0) {
        GKI_send_msg(((u8 *)&lbl_803BD1A0)[0x1F], 0, *(void **)(var_r15 + var_r23));
        *(void **)(var_r15 + var_r23) = 0;
    }
    }
    return var_r19;
}
#pragma pop
void hcisu_h2_send_msg_now(u8 *queue, s32 arg1) {
    BT_HDR *msg=(BT_HDR*)arg1;
    u8 *data=(u8*)msg+*(u16*)((u8*)msg+4)+8;
    u16 opcode=*(u16*)msg, max_len;
    u8 channel;
    if(opcode==0x2100) channel=2; else if(opcode==0x2200) channel=3; else if(opcode==0x2000) channel=0;
    if(opcode==0x2100 && *(u16*)((u8*)msg+2)>*(u16*)(lbl_803C0A50+0x7E)) {
        u16 header=(u16)((data[0]|(data[1]<<8))&0xCFFF)|0x1000; data+=2;
        for(;;) {
            max_len=*(u16*)(lbl_803C0A50+0x7E); if(*(u16*)((u8*)msg+2)<=max_len)break;
            UUSB_Write(channel,data,*(u16*)((u8*)msg+2),msg);
            *(u16*)((u8*)msg+4)+=*(u16*)(lbl_803C0A50+0x7C);
            data=(u8*)msg+*(u16*)((u8*)msg+4);
            *(u16*)((u8*)msg+2)-=*(u16*)(lbl_803C0A50+0x7C);
            *(u16*)(data+8)=header; data+=0xA;
            if(*(u16*)((u8*)msg+2)>*(u16*)(lbl_803C0A50+0x7E)) { max_len=*(u16*)(lbl_803C0A50+0x7C); data[0]=max_len; data[1]=max_len>>8; }
            else { max_len=*(u16*)((u8*)msg+2)-4; data[0]=max_len; data[1]=max_len>>8; }
            data+=2;
            if(*(u16*)((u8*)msg+6)!=0 && --(*(u16*)((u8*)msg+6))==0) {
                *(u16*)msg=0x1900; GKI_send_msg(((u8*)&lbl_803BD1A0)[0x1F],0,msg); return;
            }
        }
    }
    UUSB_Write(channel,data,*(u16*)((u8*)msg+2),msg);
    GKI_freebuf(msg);
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

void uusb_CloseDeviceCB(s8 arg0) {
    register u8 *control = (u8 *)&lbl_803BD1E0;
    register s32 zero = 0;

    *(s32 *)&lbl_803BD1E0 = zero;
    control[0x10] = zero;
    control[0x11] = zero;
    control[0x12] = zero;
    control[0x13] = zero;
    lbl_8055DC50 = zero;
    fn_8009B0E0();
    fn_8006EBAC();
    control[0x29] = 5;
    control[0x28] = zero;
    lbl_8055DC51 = zero;
    fn_8006EB88();
    if (*(void (**)(s32, s8))(control + 0x20) != 0)
        (*(void (**)(s32, s8))(control + 0x20))(4, arg0);
}

extern s32 IUSB_ReadBlkMsgAsync(s32, u32, u32, void *, void (*)(void), void *);
#pragma push
#pragma use_lmw_stmw off
void uusb_issue_bulk_read(void) {
    extern char lbl_803142C8[];
    extern void uusb_ReadBulkDataCB(void);
    extern u16 fn_8006D8D0(u32);
    uusb_cb_t *control = &lbl_803BD1E0;
    char *report = lbl_803142C8;
    u8 *buf;
    register u8 *aligned;
    u16 header;
    s32 result;

    for (;;) {
        buf = GKI_getpoolbuf(control->pool_id);
        if (buf != 0) {
            break;
        }
        if (control->at_0x28 != 0) {
            OSReport(report + 0x280);
        }
    }

    *(u16 *)buf = 0x1100;
    aligned = (u8 *)(((u32)(buf + 0x27)) & ~31);
    *(u16 *)(buf + 2) = 0;
    header = (u16)(aligned - (buf + 8));
    *(u16 *)(buf + 4) = header;

    result = IUSB_ReadBlkMsgAsync(lbl_803BD1E0.fd, control->endpoint,
                                  fn_8006D8D0((u32)buf) - 0x28 - header,
                                  aligned, uusb_ReadBulkDataCB, buf);
    if (result != 0) {
        if (control->at_0x28 != 0) {
            OSReport(report + 0x2D4, result);
        }
        if (lbl_803BD1E0.at_0x28 != 0) {
            OSReport(report + 0x320, result);
        }
        GKI_freebuf(buf);
    }
}
#pragma pop
extern s32 IUSB_OpenDeviceIds(const char *, u16, u16, s32 *);
extern char lbl_80314898[];
extern char lbl_803148F8[];
extern char lbl_80559004[4];
extern char lbl_80559008[4];
extern s32 lbl_80558FF4;
extern u32 lbl_8055DC54;
extern u32 lbl_8055DC58;
s32 uusb_get_devId(u32 arg0, u32 arg1) {
    s32 result;
    if (lbl_8055DC58 == 1) {
        if (lbl_8055DC54 == 0) {
            result = IUSB_OpenDeviceIds(lbl_80559004, (u16)arg0, (u16)arg1, (s32 *)&lbl_803BD1E0);
        } else if (lbl_8055DC54 == 1) {
            result = IUSB_OpenDeviceIds(lbl_80559008, (u16)arg0, (u16)arg1, (s32 *)&lbl_803BD1E0);
        }
    } else {
        result = IUSB_OpenDeviceIds(lbl_80559008, (u16)arg0, (u16)arg1, (s32 *)&lbl_803BD1E0);
    }
    if (result < 0) {
        if (lbl_803BD1E0.at_0x28 != 0) OSReport(lbl_80314898, result, 0x57E, 0x305);
        if (lbl_803BD1E0.at_0x28 != 0) OSReport(lbl_803148F8);
    } else {
        lbl_80558FF4 = result;
    }
    return result;
}

s32 fn_8007011C(void) { return 0; }

void UUSB_Close(void *arg0) {
    extern s32 IUSB_CloseDeviceAsync(s32, void (*)(void), void *);
    fn_8006EBAC();
    {
        register uusb_cb_t *control = &lbl_803BD1E0;
        control->state = 0;
        fn_8006EB88();
        if (*(u16 *)((u8 *)&control->acl_q + 8) != 0) {
            while (*(u16 *)((u8 *)&control->acl_q + 8) != 0) {
                GKI_freebuf(GKI_dequeue(&control->acl_q));
            }
        }
    }
    {
        register uusb_cb_t *control = &lbl_803BD1E0;
        if (*(u16 *)((u8 *)&control->sco_q + 8) != 0) {
            while (*(u16 *)((u8 *)&control->sco_q + 8) != 0) {
                GKI_freebuf(GKI_dequeue(&control->sco_q));
            }
        }
    }
    IUSB_CloseDeviceAsync(lbl_803BD1E0.fd,
                          (void (*)(void))uusb_CloseDeviceCB, 0);
}

/* uusb control block at lbl_803BD1E0 (96 bytes): fd @0, state u8 @0x29,
 * BUFFER_Q acl_q @0x2C, BUFFER_Q sco_q @0x3C. */
#ifndef UUSB_CB_DEFINED_EARLY
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
#endif

extern uusb_cb_t lbl_803BD1E0;
extern OSAlarm lbl_803C0A20;
extern void uusb_CloseDeviceCB(s8);
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

extern s32 lbl_80558FF0;
extern char lbl_802EE8D8[];
extern u8 lbl_80559048;
extern void fn_80070B54();
extern void fn_80082548();
extern u8 fn_80073B30(void);
void fn_800709FC(void) {
    u64 time;
    u32 time_lo;
    u32 time_hi;

    lbl_8055DC74 = 0;
    GKI_init();
    fn_8006EB88();
    fn_80082548();
    lbl_8055DC6C = &lbl_80559048;
    lbl_8055DC68 = (hcisu_if *)lbl_802EE8D8;
    ((void (*)(u32, void *))bte_hcisu_task)(0, lbl_802EE8D8);

    goto wait_check;
wait_delay:
    ((void (*)(s32))fn_8006EAD8)(0x64);
wait_check:
    if (lbl_80558FF0 != 0) {
        goto wait_delay;
    }

    fn_80070B54();
    time = __OSGetSystemTime();
    time_lo = (u32)time;
    time_hi = (u32)(time >> 32);
    OSCreateAlarm(&lbl_803C0A20);
    ((void (*)(void *, u32, u32, u32, u32, u32, void (*)(void)))OSSetPeriodicAlarm)(
        &lbl_803C0A20, 0x80000000, time_hi, time_lo, 0,
        ((*(u32 *)0x800000F8 >> 2) / 500) & 0x07FFFFFE, fn_800709E4);
    ((void (*)(s32))fn_8006EACC)(0);

    while (fn_80073B30() == 0) {
        ((void (*)(s32))fn_8006EAD8)(0x7D0);
    }
}

void fn_80070AF0(s32 arg0) {
    lbl_8055DC74 = arg0;
    OSCancelAlarm(&lbl_803C0A20);
    fn_80070820();
    GKI_shutdown();
}

typedef int (*Fn80070B24Callback)(int);
int fn_80070B24(int arg0) {
    Fn80070B24Callback callback = (Fn80070B24Callback)lbl_8055DC74;

    if (callback == 0) {
        return arg0;
    }
    if ((s8)arg0 >= 0) {
        return callback(0);
    }
    return callback(1);
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

void bta_sys_init(void) {
    memset(lbl_803C0AD8, 0, 0x8C);
    fn_80071510(lbl_803C0AD8 + 0x68, 0x3E8, lbl_80559038[3]);
    lbl_803C0AD8[0x7D] = fn_8006EB80();
    lbl_8055DC80 = lbl_80559038[4];
}

void bta_sys_event(BT_HDR *msg) {
    extern char lbl_80315010[];
    extern char lbl_80315024[];
    extern u8 lbl_803C0AD8[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_80073A00(void);
    u8 id;
    u8 freebuf = 1;

    if (lbl_8055DC80 >= 4)
        fn_80070954(0x503, lbl_80315010, msg->event);
    id = msg->event >> 8;
    if (lbl_803C0AD8[0x7E] != 0) {
        if (msg->event == 0x101)
            fn_80073A00();
        GKI_freebuf(msg);
        return;
    }
    if (id < 0x1A && *(void **)(lbl_803C0AD8 + id * 4) != 0) {
        void *reg = *(void **)(lbl_803C0AD8 + id * 4);
        freebuf = ((u8 (*)(BT_HDR *))*(void **)reg)(msg);
    } else if (lbl_8055DC80 >= 2) {
        fn_80070954(0x501, lbl_80315024, id);
    }
    if (freebuf)
        GKI_freebuf(msg);
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

    fn_80070FA4(sec_event, bd_addr);
    strncpy((char *)sec_event + 0x06, bd_name, 0x20);
    while (index < 0x18) {
        if (lbl_802EE9C0[index] == service_id) {
            sec_event[0xFE] = index;
            break;
        }
        index++;
    }
    callback = *(u32 (**)(u32, void *))(lbl_803C0C14 + 0x50);
    if (callback != 0 && index <= 0x17) {
        callback(4, sec_event);
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

static UINT8 bta_dm_new_link_key_cback(BD_ADDR bd_addr, DEV_CLASS dev_class, BD_NAME bd_name, UINT8 *link_key) {
    u8 sec_event[0x110];
    void (*callback)(int, void *);

    #pragma unused(dev_class)
    fn_80070FA4(sec_event, bd_addr);
    memcpy(sec_event + 6, bd_name, 0x1F);
    sec_event[0x25] = 0;
    memcpy(sec_event + 0xFF, link_key, 0x10);
    sec_event[0xFE] = 1;
    sec_event[0x10F] = 1;
    callback = *(void (**)(int, void *))(lbl_803C0C14 + 0x50);
    if (callback != NULL)
        callback(3, sec_event);
    return 1;
}

static UINT8 bta_dm_authentication_complete_cback(BD_ADDR bd_addr, DEV_CLASS dev_class, BD_NAME bd_name, int result) {
    u8 sec_event[0x110];
    void (*callback)(int, void *);

    #pragma unused(dev_class)
    if (result != 0) {
        fn_80070FA4(sec_event, bd_addr);
        memcpy(sec_event + 6, bd_name, 0x1F);
        sec_event[0x25] = 0;
        sec_event[0x10F] = 0;
        sec_event[0xFE] = 0;
        callback = *(void (**)(int, void *))(lbl_803C0C14 + 0x50);
        if (callback != NULL)
            callback(3, sec_event);
    }
    return 0;
}

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

extern void bta_dm_rssi_cback(unsigned char *);
extern void bta_dm_link_quality_cback(unsigned char *);
void bta_dm_signal_strength_timer_cback(void *arg0) {
    u8 i;
    u16 timeout;

    if (lbl_803C0C14[0x6C] & 1) {
        for (i = 0; i < lbl_803C0C14[0x4D]; i++) {
            BTM_ReadRSSI(lbl_803C0C14 + i * 0xB, (tBTM_CMPL_CB *)bta_dm_rssi_cback);
        }
    }
    if (lbl_803C0C14[0x6C] & 2) {
        for (i = 0; i < lbl_803C0C14[0x4D]; i++) {
            BTM_ReadLinkQuality(lbl_803C0C14 + i * 0xB, (tBTM_CMPL_CB *)bta_dm_link_quality_cback);
        }
    }
    timeout = *(u16 *)(lbl_803C0C14 + 0x70);
    if (timeout != 0) {
        *(void (**)(void *))(lbl_803C0C14 + 0x5C) = bta_dm_signal_strength_timer_cback;
        fn_8007146C((s32)(lbl_803C0C14 + 0x54), 0, timeout * 1000);
    }
}

void bta_dm_acl_change_cback(u8 *bd_addr, s32 arg1, s32 arg2, s32 arg3, u8 event)
{
    BT_HDR *buf = GKI_getbuf(0x12);
    if (buf != NULL) {
        fn_80070FA4((u8 *)buf + 0xB, bd_addr);
        ((u8 *)buf)[0xA] = event;
        buf->event = 0x105;
        fn_80071450(buf);
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

extern u8 lbl_803C0B68[];
extern u8 lbl_803150DC[];
s32 bta_dm_l2cap_server_compress_cback(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    u8 *entry = lbl_803C0B68;
    u8 *scan = entry;
    s32 result = 0;
    s32 i = 0;

    while (i < 5) {
        if (entry[8] == 1 && bdcmp(scan, (u8 *)arg0) == 0) {
            if (lbl_8055DC80 >= 4) {
                fn_80070954(0x503, lbl_803150DC, lbl_803C0B68[i * 9 + 6]);
            }
            result = ((s32 (*)(u8, s32, s32))fn_8006CFA0)(
                lbl_803C0B68[i * 9 + 6], arg7, arg8
            );
            break;
        }
        i++;
        entry += 9;
        scan += 9;
    }
    return result;
}

extern u8 *lbl_80559010;
void bta_dm_rm_cback(s32 status, u8 addr_type, u8 addr, u8 *bd_addr, u32 unused) {
    u8 i;
    u8 j;
    u8 *config;

    if (status != 0) return;

    for (i = 0; i < lbl_803C0C14[0x4D]; i++) {
        if (bdcmp(lbl_803C0C14 + (u32)i * 0xB, bd_addr) == 0) {
            lbl_803C0C14[(u32)i * 0xB + 6] = 1;
            config = lbl_80559010;
            for (j = 1; j <= config[1]; j++) {
                u32 peer_offset = (u32)j * 4 - j;
                if ((addr == config[peer_offset + 1] || config[peer_offset + 1] == 0xFF) &&
                    addr_type == config[peer_offset]) {
                    if (config[peer_offset + 2] > lbl_803C0C14[(u32)i * 0xB + 7])
                        lbl_803C0C14[(u32)i * 0xB + 7] = config[peer_offset + 2];
                    return;
                }
            }
            return;
        }
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

void bta_dm_send_hci_reset(void) {
    u8 *buf;

    lbl_803C0AD8[0x7E] = 1;
    buf = GKI_getpoolbuf(2);
    if (buf != NULL) {
        fn_80085384(buf, 0);
    }
    BTM_SendHciReset(fn_80073A1C);
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

u8 BTA_DmAddDevice(u8 *bd_addr, u8 *link_key, u32 trusted_mask, u8 is_trusted) {
    u32 service_mask[2];
    u32 bit;
    u32 mapped;
    u32 offset;
    u32 bit_index;
    u8 index = 0;
    u8 result;

    memset(service_mask, 0, 8);
    if (is_trusted != 0) {
        do {
            bit = 1 << index;
            if (trusted_mask & bit) {
                trusted_mask &= ~bit;
                mapped = lbl_802EE9C0[index];
                offset = (mapped >> 3) & 0x3FC;
                bit_index = mapped - (mapped & 0x1FE0);
                *(u32 *)((u8 *)service_mask + offset) |= 1 << bit_index;
            }
            index++;
        } while (trusted_mask != 0 && index < 0x17);
    }
    fn_8006EAD0();
    result = ((BOOLEAN (*)(BD_ADDR, DEV_CLASS, BD_NAME, BD_FEATURES,
                           UINT32 *, LINK_KEY))BTM_SecAddDevice)(
        bd_addr, 0, 0, 0, service_mask, link_key);
    fn_8006EAD4();
    return result == 0;
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
    u32 table = (u32)lbl_802EEA6C;
    s32 i = 0;
    u16 event;
    u8 action;

loop:
    event = p_msg->event;
    action = *(u8 *)(i + table + (((event & 0xFF) * 4) - (event & 0xFF)));
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

void fn_8007403C(void) {
    memset(lbl_803C0D18, 0, 0x2E);
    if (lbl_80559018[1] != 0) {
        fn_80071098((s32)bta_dm_pm_cback);
        BTM_PmRegister(3, lbl_803C0C14 + 0x95,
                       (tBTM_PM_STATUS_CBACK *)bta_dm_pm_btm_cback);
    }
}

void fn_800740A4(void) {
    BTM_PmRegister(4, lbl_803C0C14 + 0x95, 0);
}

extern u8 *lbl_80559018;
extern u8 *lbl_8055901C;
extern u8 lbl_802EE8F0[];
extern u8 lbl_80315188[];
extern u8 lbl_803C0D18[];
extern tBTM_STATUS fn_8007A2C8(u16 *);
extern void bta_dm_pm_set_mode(u8 *, u8);
void bta_dm_pm_cback(u8 status, u8 id, u8 app_id, u8 *peer_addr) {
    u8 version[10];
    u16 policy;
    u8 *cfg;
    u8 *entry;
    u8 *list;
    u8 *conn;
    u8 i;
    u8 j;
    u32 k;
    u32 offset;
    u8 spec_idx;

    if (fn_8007A2C8((u16 *)version) == 0 && *(u16 *)(version + 6) == 0xF && version[0] < 3) {
        if (status == 4) {
            policy = *(u16 *)(lbl_802EE8F0 + 4) & 0xB;
            BTM_SetLinkPolicy(peer_addr, &policy);
        } else if (status == 5) {
            policy = *(u16 *)(lbl_802EE8F0 + 4);
            BTM_SetLinkPolicy(peer_addr, &policy);
        }
    }

    cfg = lbl_80559018;
    for (i = 1; i <= cfg[1]; i++) {
        offset = ((i * 4) & 0x3FC) - i;
        entry = cfg + offset;
        if (entry[0] == id && (entry[1] == 0xFF || entry[1] == app_id))
            break;
    }
    if (i > cfg[1])
        return;

    conn = lbl_803C0C14;
    for (k = 0; k < 3; k++) {
        entry = conn + ((k << 5) & 0x1FE0);
        if (entry[0xB6] != 0 && bdcmp(entry + 0xB0, peer_addr) == 0) {
            fn_8007148C((s32)(entry + 0x98));
            entry[0xB6] = 0;
            break;
        }
    }

    offset = ((i * 4) & 0x3FC) - i;
    spec_idx = *(u8 *)(lbl_80559018 + offset + 2);
    if (*(u8 *)(lbl_8055901C + spec_idx * 0x4A + status * 8 + 2) == 0)
        return;

    list = lbl_803C0D18;
    for (j = 0; j < list[0]; j++) {
        entry = list + j * 9;
        if (entry[7] == id && entry[8] == app_id && bdcmp(entry + 1, peer_addr) == 0)
            break;
    }

    spec_idx = *(u8 *)(lbl_80559018 + offset + 2);
    if (*(u8 *)(lbl_8055901C + spec_idx * 0x4A + status * 8 + 2) == 0x10) {
        if (j < list[0]) {
            for (; j < list[0]; j++)
                memcpy(list + j * 9 + 1, list + (j + 1) * 9 + 1, 9);
            list[0]--;
        }
    } else if (j == list[0]) {
        if (list[0] == 5) {
            if (lbl_8055DC80 >= 2)
                fn_8007093C(0x501, lbl_80315188);
            return;
        }
        entry = list + j * 9;
        entry[7] = id;
        entry[8] = app_id;
        fn_80070FA4(entry + 1, peer_addr);
        list[0]++;
    }

    conn = lbl_803C0C14;
    for (i = 0; i < conn[0x4D]; i++) {
        if (bdcmp(conn + i * 0xB, peer_addr) == 0) {
            conn[i * 0xB + 9] = 0;
            conn[i * 0xB + 0xA] = 0;
            break;
        }
    }

    entry = list + j * 9;
    entry[9] = status;
    bta_dm_pm_set_mode(peer_addr, 0);
}

extern tBTM_PM_PWR_MD *lbl_80559020;
extern u8 lbl_803151B4[];
extern void bta_dm_pm_timer_cback(void *);
void bta_dm_pm_set_mode(u8 *peer_addr, u8 timed_out) {
    u8 *cfg;
    u8 *spec;
    u8 *act_base;
    u8 *entry;
    u8 *p_peer_device;
    u8 pm_action;
    u16 timeout;
    u8 failed_pm;
    u8 allowed_modes;
    u8 pref_modes;
    u8 mode;
    u8 i;
    u8 j;
    u32 off;
    tBTM_PM_MODE read_mode;
    tBTM_PM_PWR_MD pwr_md;

    pm_action = 0;
    timeout = 0;
    failed_pm = 0;
    p_peer_device = 0;
    allowed_modes = 0;
    pref_modes = 0;
    if (lbl_803C0C14[0x4D] == 0)
        return;
    for (i = 0; i < lbl_803C0C14[0x4D]; i++) {
        off = i * 0xB;
        if (bdcmp(lbl_803C0C14 + off, peer_addr) != 0)
            continue;
        p_peer_device = lbl_803C0C14 + off;
        failed_pm = p_peer_device[0xA];
        break;
    }
    if (p_peer_device == 0)
        return;

    for (j = 0; j < lbl_803C0D18[0]; j++) {
        off = j * 9;
        if (bdcmp(lbl_803C0D18 + off + 1, peer_addr) != 0)
            continue;
        entry = lbl_803C0D18 + off;
        cfg = lbl_80559018;
        for (i = 1; i <= cfg[1]; i++) {
            if (cfg[i * 3] == entry[7] &&
                (cfg[i * 3 + 1] == 0xFF || cfg[i * 3 + 1] == entry[8]))
                break;
        }
        spec = lbl_8055901C;
        act_base = spec + cfg[i * 3 + 2] * 0x4A;
        allowed_modes |= act_base[0];
        act_base += entry[9] * 8;
        mode = act_base[2];
        if (!(failed_pm & mode)) {
            pref_modes |= mode;
            if (mode > pm_action) {
                pm_action = mode;
                timeout = *(u16 *)(act_base + 4);
            }
        } else {
            mode = act_base[6];
            if (!(failed_pm & mode)) {
                pref_modes |= mode;
                if (mode > pm_action) {
                    pm_action = mode;
                    timeout = *(u16 *)(act_base + 8);
                }
            }
        }
    }

    if (pm_action & 3) {
        if (!(allowed_modes & pm_action)) {
            pm_action = (allowed_modes & pref_modes) & 3;
            if (pm_action == 0)
                timeout = 0;
        }
    }

    if (!timed_out && timeout) {
        for (i = 0; i < 3; i++) {
            if (lbl_803C0C14[i * 0x20 + 0xB6] == 0) {
                lbl_803C0C14[i * 0x20 + 0xB6] = 1;
                fn_80070FA4(lbl_803C0C14 + i * 0x20 + 0xB0, peer_addr);
                *(void (**)(void *))(lbl_803C0C14 + i * 0x20 + 0xA0) = bta_dm_pm_timer_cback;
                fn_8007146C((s32)(lbl_803C0C14 + i * 0x20 + 0x98), 0, timeout);
                return;
            }
        }
        if (i == 3) {
            if (lbl_8055DC80 >= 2)
                fn_8007093C(0x501, lbl_803151B4);
            return;
        }
    }

    if (pm_action == 0) {
    } else if (pm_action == 1) {
        p_peer_device[9] = 1;
        BTM_ReadPowerMode(peer_addr, &read_mode);
        if (read_mode != 3)
            BTM_SetPowerMode(lbl_803C0C14[0x95], peer_addr, lbl_80559020 + 1);
    } else if (pm_action == 2) {
        p_peer_device[9] = 2;
        BTM_ReadPowerMode(peer_addr, &read_mode);
        if (read_mode != 2)
            BTM_SetPowerMode(lbl_803C0C14[0x95], peer_addr, lbl_80559020);
    } else if (pm_action == 4) {
        pwr_md.mode = 0;
        BTM_SetPowerMode(lbl_803C0C14[0x95], peer_addr, &pwr_md);
    }
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

void bta_dm_pm_timer_cback(void *arg) {
    u8 *base = lbl_803C0C14;
    register void *buf;
    register u8 idx = 0;

    if (base[0xB6] != 0 && (void *)(base + 0x98) == arg) {
        base[0xB6] = 0;
        goto done;
    }
    idx = 1;
    if (base[0xD6] != 0 && (void *)(base + 0xB8) == arg) {
        base[0xD6] = 0;
        goto done;
    }
    idx = 2;
    if (base[0xF6] != 0 && (void *)(base + 0xD8) == arg) {
        base[0xF6] = 0;
        goto done;
    }
    idx = 3;

done:
    if (idx != 3) {
        buf = GKI_getbuf(0xE);
        if (buf != 0) {
            *(u16 *)buf = 0x10A;
            fn_80070FA4((u8 *)buf + 8,
                         lbl_803C0C14 + 0xB0 + ((u32)idx << 5));
            fn_80071450(buf);
        }
    }
}

void bta_dm_pm_btm_status(void *arg0) {
    u8 *p = (u8 *)arg0;
    u8 *base = lbl_803C0C14;
    s32 i;
    u8 *entry;
    u8 mask;
    for (i = 0; i < 3; i++) {
        entry = base + i * 0x20;
        if (entry[0xB6] != 0 && bdcmp(entry + 0xB0, p + 8) == 0) {
            fn_8007148C((s32)(entry + 0x98));
            entry[0xB6] = 0;
            break;
        }
    }
    if (p[0xE] != 0)
        return;
    if (p[0x12] == 0) {
        bta_dm_pm_set_mode(p + 8, 0);
        return;
    }
    for (i = 0, entry = base; i < base[0x4D]; i++, entry += 0xB) {
        if (bdcmp(entry, p + 8) == 0) {
            mask = entry[9] & 3;
            if (mask != 0) {
                entry[0xA] |= mask;
                bta_dm_pm_set_mode(p + 8, 0);
            }
            break;
        }
    }
}

void fn_80074A4C(s32 arg0) {
    bta_dm_pm_set_mode((u8 *)arg0 + 8, 1);
}

void bta_hh_api_disable(void) {
    UINT8 xx;
    UINT8 status;
    void (*callback)(int, void *);

    if (*(void **)(lbl_803C0D48 + 0x224) == NULL)
        return;
    if (lbl_803C0D48[0x22D] == 0) {
        status = 0;
        if (HID_HostDeregister() != HID_SUCCESS)
            status = 6;
        for (xx = 0; xx < 0x10; xx++)
            fn_800716F0(lbl_803C0D48 + xx * 0x20 + 0x14);
        fn_800716F0(lbl_803C0D48 + 0x228);
        callback = *(void (**)(int, void *))(lbl_803C0D48 + 0x224);
        (*callback)(1, &status);
        memset(lbl_803C0D48, 0, 0x230);
    } else {
        lbl_803C0D48[0x22E] = 1;
        for (xx = 0; xx < 0x10; xx++) {
            if (lbl_803C0D48[xx * 0x20 + 0x2C] == 3)
                bta_hh_sm_execute((tBTA_HH_DEV_CB *)(lbl_803C0D48 + xx * 0x20 + 0x10), 0x1701, NULL);
        }
    }
}

void bta_hh_disc_cmpl(void) {
    s8 status = 0;
    u8 *base;
    u32 i;

    if (HID_HostDeregister() == 0) {
        return;
    }
    status = 6;
    i = 0;
    base = lbl_803C0D48;
    do {
        fn_800716F0(base + ((u32)(u8)i << 5) + 0x14);
        i++;
    } while (i < 16);
    base = lbl_803C0D48;
    fn_800716F0(base + 0x228);
    (*(void (**)(u32, void *))(base + 0x224))(1, &status);
    memset(base, 0, 0x230);
}

void bta_hh_sdp_cmpl(void *arg0, u8 *status) {
    u8 info[8];
    u8 result;
    u8 *manager = lbl_803C0D48;
    if (lbl_8055DC80 >= 5)
        fn_80070954(0x504, lbl_803152B0, status[0]);
    memset(info, 0, 8);
    info[7] = *((u8 *)arg0 + 0x16);
    fn_80070FA4(info, (u8 *)arg0 + 8);
    result = status[0];
    if (result == 0) {
        if (*((u8 *)arg0 + 0x19) == 0) {
            HID_HostSetSecurityLevel(&lbl_80559058, *((u8 *)arg0 + 0x14));
            result = HID_HostOpenDev(*((u8 *)arg0 + 0x16));
            if (result != 0) {
                if (lbl_8055DC80 >= 5)
                    fn_80070954(0x504, lbl_803152D0, result);
                HID_HostRemoveDev(*((u8 *)arg0 + 0x16));
            }
        } else bta_hh_sm_execute(arg0, 0x170B, 0);
    }
    if (result == 0) return;
    if (status[0] == 0xFF) info[6] = 0xA;
    else info[6] = 7;
    ((void (*)(u32, void *))(*(void **)(manager + 0x224)))(2, info);
    bta_hh_sm_execute(arg0, 0x1701, 0);
    if (*((u8 *)arg0 + 0x15) == 0 && *((u8 *)arg0 + 0x19) == 0)
        bta_hh_clean_up_kdev(arg0);
    bta_hh_trace_dev_db();
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

extern void fn_8006CF80();
void bta_hh_open_cmpl_act(void *arg0, void *arg1) {
    u8 local[8];
    u8 *dev = arg0;
    u8 *cb;
    u8 handle;
    u8 status;
    if (arg1 != 0) handle = (u8)*(u16 *)((u8 *)arg1 + 6);
    else handle = dev[0x16];
    memset(local, 0, 8);
    local[7] = handle;
    fn_80070FA4(local, dev + 8);
    cb = lbl_803C0D48;
    cb[0x22D]++;
    fn_8006CF80(dev[0x16], dev[0x13], *(u16 *)(dev + 0xE), dev[0x15]);
    bta_sys_conn_open(0x17, dev[0x15], (s32)(u32)(dev + 8));
    if (dev[0x1B] != 0) {
        status = HID_HostWriteDev(handle, 7, dev[0x1B], 0, 0, 0);
        local[6] = status;
        if ((u8)status != 0) {
            local[6] = 8;
            (*(void (**)(u32, void *))(cb + 0x224))(2, local);
        } else *(u16 *)(dev + 0x10) = 2;
    } else {
        dev[0x1A] = 1;
        (*(void (**)(u32, void *))(cb + 0x224))(2, local);
    }
    dev[0x19] = 0;
}

extern char lbl_8031531C[];
extern void bta_hh_start_sdp(void *, void *);
void bta_hh_open_act(void *arg0, void *arg1) {
    u8 *dev = (u8 *)arg0;
    u8 value;
    u32 sp8[4];

    if (arg1 != NULL)
        value = (u8)*(u16 *)((u8 *)arg1 + 6);
    else
        value = dev[0x16];

    if (lbl_8055DC80 >= 4)
        fn_80070954(0x503, lbl_8031531C, value);

    if (dev[0x15] != 0) {
        bta_hh_sm_execute((tBTA_HH_DEV_CB *)arg0, 0x170B, arg1);
        return;
    }

    dev[0x19] = 1;
    memset(sp8, 0, 0x10);
    fn_80070FA4(sp8 + 2, dev + 8);
    bta_hh_start_sdp(arg0, sp8);
}

void bta_hh_data_act(void *arg0, void *arg1) {
    u8 *data = *(u8 **)((u8 *)arg1 + 0xC);
    void *sp8 = data;

    fn_8006CF44((void *)(u32)(u8)*(u16 *)((u8 *)arg1 + 6),
                data + *(u16 *)(data + 4) + 8,
                (void *)(u32)*(u16 *)(data + 2),
                (void *)(u32)((u8 *)arg0)[0x1B],
                (void *)(u32)((u8 *)arg0)[0x13],
                ((u8 *)arg0)[0x15]);
    fn_800716F0(&sp8);
}

void bta_hh_handsk_act(u8 *p_cb, s32 *p_data) {
    u8 hs_data[10];
    u8 conn[8];
    u8 cback_data[2];
    u8 *s = lbl_803151D8;
    s32 result;
    u8 status;
    typedef void (*cback_t)(u16, void *);

    if (lbl_8055DC80 >= 5) {
        char *name;
        switch (*(u16 *)(p_cb + 0x10)) {
        case 4: name = (char *)s + 0x16c; break;
        case 5: name = (char *)s + 0x180; break;
        case 6: name = (char *)s + 0x194; break;
        case 7: name = (char *)s + 0x1ac; break;
        case 8: name = (char *)s + 0x1c4; break;
        case 9: name = (char *)s + 0x1d8; break;
        case 2: name = (char *)s + 0x1f0; break;
        default: name = (char *)s + 0x200; break;
        }
        ((void (*)(u32, void *, void *, u32))fn_8007096C)(0x504, (char *)s + 0x210, name, p_data[2]);
    }

    switch (*(u16 *)(p_cb + 0x10)) {
    case 4: case 6: case 8:
        memset(hs_data, 0, 10);
        hs_data[1] = p_cb[0x16];
        result = p_data[2];
        switch (result) {
        case 0: status = 0; break;
        case 1: case 2: case 3: case 4:
            status = (u8)result; break;
        case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        default: status = 5; break;
        }
        hs_data[0] = status;
        (*(cback_t *)(lbl_803C0D48 + 0x224))(*(u16 *)(p_cb + 0x10), hs_data);
        *(u16 *)(p_cb + 0x10) = 0;
        break;
    case 5: case 7: case 9:
        cback_data[1] = p_cb[0x16];
        result = p_data[2];
        switch (result) {
        case 0: status = 0; break;
        case 1: case 2: case 3: case 4:
            status = (u8)result; break;
        case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        default: status = 5; break;
        }
        cback_data[0] = status;
        (*(cback_t *)(lbl_803C0D48 + 0x224))(*(u16 *)(p_cb + 0x10), cback_data);
        *(u16 *)(p_cb + 0x10) = 0;
        break;
    case 2:
        status = 0;
        if (p_data[2] != 0) status = 8;
        conn[6] = status;
        conn[7] = p_cb[0x16];
        fn_80070FA4(conn, p_cb + 8);
        (*(cback_t *)(lbl_803C0D48 + 0x224))(*(u16 *)(p_cb + 0x10), conn);
        bta_hh_trace_dev_db();
        *(u16 *)(p_cb + 0x10) = 0;
        if (conn[6] == 0) p_cb[0x1a] = 1;
        break;
    default:
        if (lbl_8055DC80 >= 5) fn_8007093C(0x504, (char *)s + 0x23c);
        break;
    }
    fn_80071264((void *)0x17, (void *)(u32)p_cb[0x15], p_cb + 8);
}

void fn_80075AA4(void *arg0) {
    (*(void (**)(int, void *))(lbl_803C0D48 + 0x224))(10, arg0);
}

void bta_hh_maint_dev_act(void *arg0, void *arg1) {
    extern unsigned char lbl_803C0D48[];
    extern char lbl_80315530[];
    extern u8 lbl_8055DC80;
    extern void bta_hh_add_device_to_list(void *, s8, s16, void *, s32, s32);
    extern u8 HID_HostRemoveDev(u32);
    u8 sp17 = 0xFF;
    s8 sp16 = 6;
    u32 sp10;
    u8 sp8;
    u16 event = *(u16 *)((u8 *)arg1 + 0x10);
    u8 result;
    void (*callback)(u16, void *, void *);
    if (event == 12) goto remove;
    if (event < 12) {
        if (event == 11) goto add;
        goto default_case;
    }
    goto default_case;
add:
    fn_80070FA4(&sp10, (u8 *)arg1 + 8);
    result = *(u8 *)((u8 *)arg0 + 0x16);
    if (result == 0xFF) {
        if (HID_HostAddDev((u8 *)arg1 + 8, *(u16 *)((u8 *)arg1 + 0xE), &sp8) == 0) {
            sp16 = 0;
            sp17 = sp8;
            bta_hh_add_device_to_list(arg0, (s8)sp8, *(s16 *)((u8 *)arg1 + 0xE), 0, *(u8 *)((u8 *)arg1 + 0x12), *(u8 *)((u8 *)arg1 + 0x13));
            lbl_803C0D48[sp8 + 0x214] = *(u8 *)((u8 *)arg0 + 0x12);
        }
    } else { sp17 = result; sp16 = 0; }
    bta_hh_trace_dev_db();
    goto finish;
remove:
    sp17 = *(u8 *)((u8 *)arg1 + 6);
    fn_80070FA4(&sp10, (u8 *)arg0 + 8);
    if (*(u8 *)((u8 *)arg0 + 0x1C) != 3 && HID_HostRemoveDev(sp17) == 0) {
        sp16 = 0;
        bta_hh_clean_up_kdev(arg0);
    }
    goto finish;
default_case:
    if (lbl_8055DC80 >= 5) fn_8007093C(0x504, lbl_80315530);
finish:
    callback = *(void (**)(u16, void *, void *))(lbl_803C0D48 + 0x224);
    callback(event, &sp10, lbl_803C0D48);
}

void bta_hh_get_acl_q_info(void) {
    u8 info[0x1E];
    u8 count = 0;
    u8 i;
    u8 *entry;
    u8 *ccb;
    u8 *p;
    memset(info, 0, sizeof(info));
    for (i = 0; i < 0x10; i++) {
        entry = lbl_803C0D48 + i * 0x20;
        if (entry[0x28] != 0 && entry[0x2C] == 3) {
            info[count * 6 + 6] = entry[0x26];
            ccb = (u8 *)l2cu_find_ccb_by_cid(0, *(u16 *)(lbl_803C3C38 + entry[0x26] * 0x34 + 0x16));
            if (ccb != 0 && (p = *(u8 **)(ccb + 0x10)) != 0 && p[0] != 0) {
                *(u16 *)(info + count * 6 + 8) = *(u16 *)(p + 0x4C);
                *(u16 *)(info + count * 6 + 10) = *(u16 *)(p + 0x38);
                count++;
            }
        }
    }
    *(u16 *)(info + 0) = *(u16 *)(lbl_803C4040 + 4);
    *(u16 *)(info + 2) = *(u16 *)(lbl_803C4040 + 2);
    *(u16 *)(info + 4) = count;
    ((void (*)(u32, void *, u16, u16))*(void **)(lbl_803C0D48 + 0x224))(0xF, info,
        *(u16 *)(lbl_803C4040 + 2), *(u16 *)(lbl_803C4040 + 4));
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

void bta_hh_sm_execute(tBTA_HH_DEV_CB *p_cb, UINT16 event, void *p_data) {
    u8 callback_data[0x20];
    char *strings = lbl_80315700;
    UINT16 callback_event = 0;
    u8 state;
    u8 new_state;
    char *state_name;
    char *new_state_name;
    u8 *table;
    u8 action;
    memset(callback_data, 0, 0x20);
    if (p_cb == NULL) {
        if (*(u32 *)(lbl_803C0D48 + 0x224) != 0) {
            switch (event) {
            case 0x1700:
                callback_event = 2;
                fn_80070FA4(callback_data, (u8 *)p_data + 8);
                callback_data[6] = 9;
                callback_data[7] = 0xFF;
                break;
            case 0x170A:
                callback_event = *(u16 *)((u8 *)p_data + 0x10);
                if (callback_event == 0xB) {
                    fn_80070FA4(callback_data, (u8 *)p_data + 8);
                    callback_data[6] = 9;
                    callback_data[7] = 0xFF;
                } else {
                    callback_data[6] = 0xD;
                    callback_data[7] = (u8)*(u16 *)((u8 *)p_data + 6);
                }
                break;
            case 0x1708:
                callback_event = ((u8 *)p_data)[8];
                if (callback_event == 7 || callback_event == 5 || callback_event == 9) {
                    callback_data[0] = 0xD;
                    callback_data[1] = (u8)*(u16 *)((u8 *)p_data + 6);
                } else if (callback_event != 0xA && callback_event != 1) {
                    callback_data[1] = (u8)*(u16 *)((u8 *)p_data + 6);
                    callback_data[0] = 0xD;
                }
                break;
            case 0x1701:
                callback_event = 3;
                callback_data[0] = 0xD;
                callback_data[1] = (u8)*(u16 *)((u8 *)p_data + 6);
                break;
            default:
                if (lbl_8055DC80 >= 1)
                    fn_80070954(0x500, strings, *(u16 *)((u8 *)p_data + 6));
                break;
            }
            if (callback_event != 0)
                ((void (*)(UINT16, void *, void *))*(u32 *)(lbl_803C0D48 + 0x224))(callback_event, callback_data, lbl_803C0D48);
        }
    } else {
        state = *((u8 *)p_cb + 0x1C);
        if (lbl_8055DC80 >= 4) {
            switch (state) {
            case 0: state_name = strings + 0x1C; break;
            case 1: state_name = strings + 0x2C; break;
            case 2: state_name = strings + 0x3C; break;
            case 3: state_name = strings + 0x50; break;
            default: state_name = strings + 0x60; break;
            }
            ((void (*)(u32, void *, u8, char *, char *))fn_80070984)(0x503, strings + 0x78, state, state_name, bta_hh_evt_code(event));
        }
        table = *(u8 **)(lbl_802EEBD8 + ((*(volatile u8 *)((u8 *)p_cb + 0x1C) - 1) * 4));
        event = (u8)event;
        *((u8 *)p_cb + 0x1C) = table[event * 2 + 1];
        action = table[event * 2];
        if (action != 0xC)
            ((void (*)(tBTA_HH_DEV_CB *, void *))*(u32 *)(lbl_802EEB60 + action * 4))(p_cb, p_data);
        new_state = *((u8 *)p_cb + 0x1C);
        if (state != new_state && lbl_8055DC80 >= 5) {
            switch (state) {
            case 0: state_name = strings + 0x1C; break;
            case 1: state_name = strings + 0x2C; break;
            case 2: state_name = strings + 0x3C; break;
            case 3: state_name = strings + 0x50; break;
            default: state_name = strings + 0x60; break;
            }
            switch (new_state) {
            case 0: new_state_name = strings + 0x1C; break;
            case 1: new_state_name = strings + 0x2C; break;
            case 2: new_state_name = strings + 0x3C; break;
            case 3: new_state_name = strings + 0x50; break;
            default: new_state_name = strings + 0x60; break;
            }
            ((void (*)(u32, void *, char *, char *, char *))fn_80070984)(0x504, strings + 0xAC, state_name, new_state_name, bta_hh_evt_code((u8)event));
        }
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

u8 bta_hh_find_cb(u8 *bd_addr) {
    u8 i;
    s32 j;
    extern u8 lbl_803159E0[];
    extern u8 lbl_80565228;

    i = 0;
    do {
        if (bdcmp(bd_addr, lbl_803C0D48 + (i << 5) + 0x18) == 0 && bdcmp(bd_addr, &lbl_80565228) != 0) {
            if (lbl_8055DC80 >= 5)
                fn_8007096C(0x504, lbl_803159E0, i, lbl_803C0D48[(i << 5) + 0x26]);
            return i;
        }
        if (lbl_8055DC80 >= 5)
            ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)(0x504, lbl_803159E0 + 0x24, lbl_803C0D48[(i << 5) + 0x28], i, lbl_803C0D48[(i << 5) + 0x26], lbl_803C0D48[(i << 5) + 0x2C]);
        i++;
    } while (i < 0x10);
    for (j = 0; j < 0x10; j++) {
        if (lbl_803C0D48[(j << 5) + 0x28] == 0) {
            fn_80070FA4(lbl_803C0D48 + (j << 5) + 0x18, bd_addr);
            break;
        }
    }
    if (lbl_8055DC80 >= 5)
        fn_8007096C(0x504, lbl_803159E0 + 0x58, j, 0x10);
    return j;
}

void bta_hh_clean_up_kdev(void *arg0) {
    u8 index;
    u8 state;

    index = *((u8 *)arg0 + 0x16);
    if (index != 0xFF) {
        *(u8 *)((u32)lbl_803C0D48 + (u32)index + 0x214) = 0x10;
    }
    state = *((u8 *)arg0 + 0x12);
    fn_800716F0((u8 *)arg0 + 4);
    memset(arg0, 0, 0x20);
    *((u8 *)arg0 + 0x12) = state;
    *((u8 *)arg0 + 0x1C) = 1;
    *((u8 *)arg0 + 0x16) = 0xFF;
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

void bta_hh_trace_dev_db(void) {
    extern u8 lbl_803159E0[];
    extern void fn_8007093C(u32, void *);
    extern void fn_80070984(u32, void *);
    extern void fn_8007099C(u32, void *);
    u8 *s = lbl_803159E0;
    u32 i;
    u8 *entry;

    if (lbl_8055DC80 >= 5)
        fn_8007093C(0x504, s + 0x1E4);
    i = 0;
    do {
        if (lbl_8055DC80 >= 5) {
            entry = lbl_803C0D48 + ((u8)i << 5);
            ((void (*)(u32, void *, u8, u8, u8))fn_80070984)(0x504, s + 0x220, (u8)i, entry[0x28], entry[0x26]);
        }
        if (lbl_8055DC80 >= 5) {
            entry = lbl_803C0D48 + ((u8)i << 5);
            ((void (*)(u32, void *, u16, u8, u8, u8))fn_8007099C)(0x504, s + 0x244, *(u16 *)(entry + 0x1E), entry[0x2C], entry[0x23], entry[0x22]);
        }
        i++;
    } while (i < 0x10);
    if (lbl_8055DC80 >= 5)
        fn_8007093C(0x504, s + 0x280);
}

extern u8 *lbl_80559030;
extern u8 lbl_80315A64[];
extern void fn_800716F0(void *);
void fn_80076E70(void) {
    *(u16 *)(lbl_803C0F78 + 0x4C6) = 0x7D00;
    lbl_803C0F78[0x27BF] = 0xFF;
}

u8 btm_handle_to_acl_index(u16 hci_handle) {
    u8 *base = lbl_803C0F78;
    u32 index = 0;
    if (base[0x14D] != 0 && *(u16 *)(base + 0x34) == hci_handle) goto done;
    index = 1;
    if (base[0x269] != 0 && *(u16 *)(base + 0x150) == hci_handle) goto done;
    index = 2;
    if (base[0x385] != 0 && *(u16 *)(base + 0x26C) == hci_handle) goto done;
    index = 3;
    if (base[0x4A1] != 0 && *(u16 *)(base + 0x388) == hci_handle) goto done;
    index = 4;
done:
    return index;
}

extern u8 lbl_80315CE0[];
s32 btsnd_hcic_auth_request_80084478(u16);
s32 btsnd_hcic_auth_request_800844F4(u16);
s32 btsnd_hcic_auth_request_80084570(u16);
s32 btsnd_hcic_write_policy_set_80085668(u16, u16);
void btm_acl_created(BD_ADDR bda, DEV_CLASS dev_class, BD_NAME dev_name,
                     UINT16 hci_handle, UINT8 link_role, UINT8 is_le_link) {
    u8 *temp_r3;
    u16 temp_r4;
    s32 var_ctr;
    s32 var_ctr_2;
    u16 temp_r28;
    u16 var_r30;
    u32 var_r29_2;
    u32 var_r31;
    u8 var_r4;
    u8 var_r6;
    u8 *var_r29;
    u8 *var_r30_2;
    u8 *var_r31_2;

    var_r29 = lbl_803C0F78 + 0x34;
    var_r31 = 0;
loop_1:
    if (var_r29[0x119] == 0) {
        goto loop_1_next;
    }
    if (memcmp(var_r29 + 8, bda, 6) != 0) {
        goto loop_1_next;
    }
    goto loop_1_done;
loop_1_next:
    var_r31 += 1;
    var_r29 += 0x11C;
    if (var_r31 < 4) {
        goto loop_1;
    }
    var_r29 = NULL;
loop_1_done:
    if (var_r29 != NULL) {
        *(u16 *)var_r29 = hci_handle;
        var_r29[0x11A] = link_role;
        if (lbl_803C0F78[0x27C0] >= 4) {
            fn_800709CC(0xD0003, lbl_80315CA0, bda[0], bda[1], bda[2],
                        bda[3], bda[4], bda[5]);
        }
    } else {
        for (var_r4 = 0, var_r31_2 = lbl_803C0F78 + 0x34; var_r4 < 4;
             var_r4++, var_r31_2 += 0x11C) {
            if (var_r31_2[0x119] != 0) {
                continue;
            }
            var_r31_2[0x119] = 1;
            *(u16 *)var_r31_2 = hci_handle;
            var_r31_2[0x11A] = link_role;
            *(u16 *)(var_r31_2 + 4) = 0;
            btm_pm_sm_alloc(var_r4);
            memcpy(var_r31_2 + 8, bda, 6);
            if (dev_class != NULL) {
                memcpy(var_r31_2 + 0xE, dev_class, 3);
            }
            if (dev_name != NULL) {
                memcpy(var_r31_2 + 0x11, dev_name, 0xF8);
            }
            btsnd_hcic_auth_request_80084570(*(u16 *)var_r31_2);
            btsnd_hcic_auth_request_800844F4(*(u16 *)var_r31_2);
            temp_r3 = (u8 *)btm_find_dev_by_handle(hci_handle);
            if (temp_r3 != NULL) {
                for (var_r6 = 0; var_r6 < 8; var_r6++) {
                    if (temp_r3[0x77 + var_r6] != 0) {
                        memcpy(var_r31_2 + 0x110, temp_r3 + 0x77, 8);
                        temp_r4 = *(u16 *)(lbl_803C0F78 + 0x654) & 0xCC18;
                        var_r30 = temp_r4 & ~0x3306;
                        if (lbl_803C0F78[0x636] >= 3) {
                            var_r30 = temp_r4 | (*(u16 *)(lbl_803C0F78 + 0x654) & 0x3306);
                        }
                        if (lbl_803C0F78[0x27C0] >= 4) {
                            fn_80070954(0xD0003, lbl_80315CE0, var_r30);
                        }
                        if (btsnd_hcic_change_conn_type(*(u16 *)var_r31_2, var_r30) != 0) {
                            *(u16 *)(var_r31_2 + 2) = var_r30;
                        }
                        if (*(u16 *)(lbl_803C0F78 + 0x4C4) != 0) {
                            BTM_SetLinkPolicy(var_r31_2 + 8, (u16 *)(lbl_803C0F78 + 0x4C4));
                        }
                        var_r29_2 = 0;
                        temp_r28 = *(u16 *)(lbl_803C0F78 + 0x4C6);
                        var_r30_2 = lbl_803C0F78 + 0x34;
loop_27:
                        if (var_r30_2[0x119] == 0) {
                            goto loop_27_next;
                        }
                        if (memcmp(var_r30_2 + 8, var_r31_2 + 8, 6) != 0) {
                            goto loop_27_next;
                        }
                        goto loop_27_done;
loop_27_next:
                        var_r29_2 += 1;
                        var_r30_2 += 0x11C;
                        if (var_r29_2 < 4) {
                            goto loop_27;
                        }
                        var_r30_2 = NULL;
loop_27_done:
                        if (var_r30_2 != NULL) {
                            *(u16 *)(var_r30_2 + 0x10E) = temp_r28;
                            if (var_r30_2[0x11A] == 0) {
                                btsnd_hcic_write_policy_set_80085668(*(u16 *)var_r30_2, temp_r28);
                            }
                        }
                        if (*(void (**)(void *, void *, void *, void *, u32))(lbl_803C0F78 + 0x4C8) != NULL) {
                            (*(void (**)(void *, void *, void *, void *, u32))(lbl_803C0F78 + 0x4C8))(
                                var_r31_2 + 8, var_r31_2 + 0xE, var_r31_2 + 0x11, var_r31_2 + 0x110, 1);
                        }
                        goto block_done;
                    }
                }
            }
            btsnd_hcic_auth_request_80084478(*(u16 *)var_r31_2);
block_done:
            return;
        }
    }
}

void btm_acl_removed(u8 *addr) {
    u32 i;
    u8 *entry;
    void (*callback)(u8 *, u32, u32, u32, u32);

    entry = lbl_803C0F78 + 0x34;
    for (i = 0; i < 4; i++, entry += 0x11C) {
        if (entry[0x119] != 0 && memcmp(entry + 8, addr, 6) == 0)
            goto found;
    }
    entry = 0;
found:
    if (entry != 0) {
        entry[0x119] = 0;
        callback = *(void (**)(u8 *, u32, u32, u32, u32))(lbl_803C0F78 + 0x4C8);
        if (callback != 0)
            callback(addr, 0, 0, 0, 0);
    }
}

extern BOOLEAN l2c_link_hci_disc_comp(UINT16, UINT8);
void btm_acl_device_down(void)
{
    u8 *entry;
    u32 i;
    for (i = 0, entry = lbl_803C0F78 + 0x34; i < 4; i++, entry += 0x11C) {
        if (entry[0x119]) l2c_link_hci_disc_comp(*(u16 *)entry, 3);
    }
}

tBTM_STATUS BTM_SwitchRole(BD_ADDR remote_bd_addr, UINT8 new_role, tBTM_CMPL_CB *p_cb) {
    u32 i; u8 *entry; u8 power_mode; u8 status; tBTM_PM_PWR_MD spC;
    if ((lbl_803C0F78[0x640] & 0x20) == 0) return 4;
    entry = lbl_803C0F78 + 0x34; i = 0;
loop:
    if (entry[0x119] == 0) goto next;
    if (memcmp(entry + 8, remote_bd_addr, 6) != 0) goto next;
    goto found;
next:
    i++; entry += 0x11C;
    if (i < 4) goto loop;
    entry = 0;
found:
    if (entry == 0) return 7;
    if (entry[0x11A] == new_role) return 0;
    status = btm_is_sco_active_by_bdaddr(remote_bd_addr);
    if (status == 1) return 3;
    if (entry[0x11B] != 0) {
        if (lbl_803C0F78[0x27C0] >= 5) fn_8007093C(0xD0004, lbl_80315D00);
        return 2;
    }
    memset(lbl_803C0F78 + 0x624, 0, 8);
    status = BTM_ReadPowerMode(entry + 8, &power_mode);
    if (status != 0) return status;
    if ((u8)(power_mode + 0xFE) <= 1) {
        spC.mode = 0;
        if (BTM_SetPowerMode(0x80, entry + 8, &spC) != 1) return 6;
        entry[0x11B] = 1;
    } else {
        tBTM_SEC_DEV_REC *dev = btm_find_dev(remote_bd_addr);
        if (dev != NULL && (*(u8 *)((u8 *)dev + 0x76) & 4)) {
            if (btsnd_hcic_set_conn_encrypt(*(u16 *)entry, 0) == 0) return 3;
            entry[0x11B] = 2;
        } else {
            if (btsnd_hcic_switch_role(remote_bd_addr, new_role) == 0) return 3;
            entry[0x11B] = 5;
        }
    }
    memcpy(lbl_803C0F78 + 0x626, remote_bd_addr, 6);
    lbl_803C0F78[0x625] = new_role;
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x62C) = p_cb;
    return 1;
}

void btm_acl_encrypt_change(u16 handle, u8 status, u8 enable) {
    u8 *base = lbl_803C0F78;
    u8 *dev;
    u32 index = 0;

    if (base[0x14D] != 0 && *(u16 *)(base + 0x34) == handle)
        goto selected;
    index = 1;
    if (base[0x269] != 0 && *(u16 *)(base + 0x150) == handle)
        goto selected;
    index = 2;
    if (base[0x385] != 0 && *(u16 *)(base + 0x26C) == handle)
        goto selected;
    index = 3;
    if (base[0x4A1] != 0 && *(u16 *)(base + 0x388) == handle)
        goto selected;
    index = 4;
selected:
    if (index >= 4)
        return;
    dev = base + index * 0x11C;
    if (dev[0x14F] == 2) {
        if (enable != 0)
            dev[0x14F] = 0;
        else
            dev[0x14F] = 3;
        if (btsnd_hcic_switch_role(dev + 0x3C, (u8)(dev[0x14E] == 0)) == 0) {
            dev[0x14F] = 0;
            if (*(void (**)(void *))(base + 0x62C) != 0) {
                (*(void (**)(void *))(base + 0x62C))(base + 0x624);
                *(void (**)(void *))(base + 0x62C) = 0;
            }
        }
    } else if (dev[0x14F] == 4) {
        dev[0x14F] = 0;
        if (*(void (**)(void *))(base + 0x62C) != 0) {
            (*(void (**)(void *))(base + 0x62C))(base + 0x624);
            *(void (**)(void *))(base + 0x62C) = 0;
        }
    }
}

void fn_800778C8(s16 arg0) {
    *(s16 *)(lbl_803C0F78 + 0x4C4) = arg0;
}

void btm_read_link_policy_complete(UINT8 *p) {
    tBTM_CMPL_CB_LKP *p_cb = btm_cb_lkp.devcb.p_rlinkp_cmpl_cb;
    tBTM_LNK_POLICY_RESULTS_LKP lnkpol;
    UINT16 handle;
    tACL_CONN_LKP *p_acl_cb = &btm_cb_lkp.acl_db[0];
    UINT16 index;
    btu_stop_timer(btm_cb_lkp.devcb.rlinkp_timer);

    /* If there was a callback address for read local version, call it */
    btm_cb_lkp.devcb.p_rlinkp_cmpl_cb = NULL;

    if (p_cb) {
        lnkpol.hci_status = *p;
        p++;

        if (lnkpol.hci_status == 0) {
            lnkpol.status = 0;

            handle = (UINT16)(*(p) + (((UINT16)(*((p) + 1))) << 8));
            p += 2;

            lnkpol.settings = (UINT16)(*(p) + (((UINT16)(*((p) + 1))) << 8));
            p += 2;

            /* Search through the list of active channels for the correct BD Addr */
            for (index = 0; index < 7; index++, p_acl_cb++) {
                if ((p_acl_cb->in_use) && (handle == p_acl_cb->hci_handle)) {
                    memcpy(lnkpol.rem_bda, p_acl_cb->remote_addr, 6);
                    break;
                }
            }
        } else
            lnkpol.status = 10;

        (*p_cb)(&lnkpol);
    }
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

BOOLEAN BTM_IsAclConnectionUp(BD_ADDR remote_bda) {
    extern char lbl_80315E80[];
    u32 i;
    u8 *entry;

    if (lbl_803C0F78[0x27C0] >= 3) {
        fn_800709CC(0xD0002, lbl_80315E80,
                    remote_bda[0], remote_bda[1], remote_bda[2],
                    remote_bda[3], remote_bda[4], remote_bda[5]);
    }
    i = 0;
    entry = lbl_803C0F78 + 0x34;
loop:
    if (entry[0x119] != 0) {
        if (memcmp(entry + 8, remote_bda, 6) == 0)
            goto found;
    }
    i++;
    entry += 0x11C;
    if (i < 4)
        goto loop;
    entry = NULL;
found:
    if (entry != NULL)
        return TRUE;
    return FALSE;
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

void btm_acl_timeout(TIMER_LIST_ENT *p_tle) {
    u8 param[0xA];
    void (*callback)(u8 *);

    if (*(u32 *)((u8 *)p_tle + 0x10) == 4) {
        callback = *(void (**)(u8 *))(lbl_803C0F78 + 0x5C4);
        param[0] = 0xA;
        *(u16 *)(param + 8) = 0;
        *(void (**)(u8 *))(lbl_803C0F78 + 0x5C4) = NULL;
        if (callback != NULL) {
            callback(param);
        }
    }
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

void btm_qos_setup_complete(UINT8 status, UINT16 handle, FLOW_SPEC *p_flow) {
    tBTM_CMPL_CB *p_cb = btm_cb.devcb.p_qossu_cmpl_cb;
    tBTM_QOS_SETUP_CMPL qossu;

    BTM_TRACE_DEBUG0("btm_qos_setup_complete");
    btu_stop_timer(&btm_cb.devcb.qossu_timer);
    btm_cb.devcb.p_qossu_cmpl_cb = NULL;

    if (p_cb) {
        memset(&qossu, 0, sizeof(tBTM_QOS_SETUP_CMPL));
        qossu.status = status;
        qossu.handle = handle;
        if (p_flow != NULL) {
            qossu.flow.qos_flags = p_flow->qos_flags;
            qossu.flow.service_type = p_flow->service_type;
            qossu.flow.token_rate = p_flow->token_rate;
            qossu.flow.peak_bandwidth = p_flow->peak_bandwidth;
            qossu.flow.latency = p_flow->latency;
            qossu.flow.delay_variation = p_flow->delay_variation;
        }
        BTM_TRACE_DEBUG1("BTM: p_flow->delay_variation: 0x%02x", qossu.flow.delay_variation);
        (*p_cb)(&qossu);
    }
}

void btm_read_rssi_complete(u8 *arg0) {
    u8 spB[6];
    u8 spA;
    u8 sp9;
    s8 sp8;
    void (*callback)(s8 *);
    s32 i;
    u16 handle;
    u8 value;
    u8 status;
    u8 *entry;

    entry = lbl_803C0F78 + 0x34;
    callback = *(void (**)(s8 *))(lbl_803C0F78 + 0x5E0);
    fn_80070F90(lbl_803C0F78 + 0x5C8);
    *(void (**)(s8 *))(lbl_803C0F78 + 0x5E0) = 0;
    if (callback != 0) {
        status = arg0[0];
        sp9 = status;
        if (status == 0) {
            sp8 = 0;
            value = arg0[3];
            spA = value;
            handle = (u16)(arg0[1] + (arg0[2] << 8));
            if (lbl_803C0F78[0x27C0] >= 4) {
                fn_8007096C(0xD0003, lbl_80315FBC, (u16)(s8)value, 0);
            }
            for (i = 0; i < 4; i++, entry += 0x11C) {
                if (entry[0x119] != 0 && handle == *(u16 *)entry) {
                    memcpy(&spB, entry + 8, 6);
                    break;
                }
            }
        } else {
            sp8 = 0xA;
        }
        callback(&sp8);
    }
}

tBTM_STATUS btm_remove_acl(BD_ADDR bd_addr) {
    u32 i = 0;
    u8 *entry = lbl_803C0F78 + 0x34;
    u16 handle;

loop:
    if (entry[0x119] == 0)
        goto next;

    if (memcmp(entry + 8, bd_addr, 6) != 0) {
        goto next;
    } else {
        goto found;
    }

next:
    i++;
    entry += 0x11C;
    if (i < 4)
        goto loop;
    entry = 0;

found:
    if (entry != 0)
        handle = *(u16 *)entry;
    else
        handle = 0xFFFF;

    if (btsnd_hcic_disconnect(handle, 0x13) == 0)
        return 3;
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

BOOLEAN BTM_SecAddDevice(BD_ADDR bd_addr, DEV_CLASS dev_class, BD_NAME bd_name, BD_FEATURES features, UINT32 trusted_mask[], LINK_KEY link_key, UINT8 key_type, tBTM_IO_CAP io_cap) {
    s32 i = 0;
    u8 *entry = lbl_803C0F78 + 0x1F30;
loop:
    if ((entry[0x76] & 0x80) == 0) goto next;
    if (memcmp(entry + 0x1C, bd_addr, 6) != 0) goto next;
    goto found;
next:
    i++;
    entry += 0x88;
    if (i < 16) goto loop;
    entry = 0;
found:
    if (entry == 0) {
        entry = (u8 *)btm_sec_alloc_dev(bd_addr);
        if (entry == 0) return FALSE;
    }
    {
        u32 id = *(u32 *)(lbl_803C0F78 + 0x1974);
        *(u32 *)(entry + 0xC) = id;
        *(u32 *)(lbl_803C0F78 + 0x1974) = id + 1;
    }
    if (dev_class != 0) memcpy(entry + 0x22, dev_class, 3);
    memset(entry + 0x35, 0, 0x41);
    if (bd_name != 0 && bd_name[0] != 0) {
        entry[0x76] |= 8;
        strncpy((char *)entry + 0x35, (char *)bd_name, 0x40);
    }
    if (features != 0) memcpy(entry + 0x77, features, 8);
    else memset(entry + 0x77, 0, 8);
    *(u32 *)(entry + 0x10) = trusted_mask[0];
    *(u32 *)(entry + 0x14) = trusted_mask[1];
    if (link_key != 0) {
        entry[0x76] |= 0x10;
        memcpy(entry + 0x25, link_key, 0x10);
    }
    return TRUE;
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
    s32 i;
    u8 *entry;
    char *name;
    i = 0;
    entry = lbl_803C0F78 + 0x1F30;
    name = 0;
    do {
        if (entry[0x76] & 0x80) {
            if (memcmp(entry + 0x1C, bd_addr, 6) == 0) {
                goto found;
            }
        }
        i++;
        entry += 0x88;
    } while (i < 16);
    entry = 0;
found:
    if (entry != 0) {
        name = (char *)entry + 0x35;
    }
    return name;
}

tBTM_SEC_DEV_REC *btm_sec_alloc_dev(BD_ADDR arg0) {
    u8 *base;
    u8 *dev;
    u8 *inq;
    s32 i;
    s32 count;
    base = lbl_803C0F78;
    dev = 0;
    i = 0;
    count = 0x10;
loop:
    if ((base[0x1FA6] & 0x80) == 0) {
        dev = base + i * 0x88 + 0x1F30;
    } else {
        base += 0x88;
        i++;
        count--;
        if (count != 0) goto loop;
    }
    if (dev == 0) dev = (u8 *)btm_find_oldest_dev();
    memset(dev, 0, 0x88);
    dev[0x76] = 0x80;
    dev[0x85] = 0;
    inq = (u8 *)BTM_InqDbRead(arg0);
    if (inq != 0) memcpy(dev + 0x22, inq + 8, 3);
    else memcpy(dev + 0x22, lbl_803C0F78 + 0x27BA, 3);
    memcpy(dev + 0x1C, arg0, 6);
    *(u16 *)(dev + 0x18) = BTM_GetHCIConnHandle(arg0);
    *(u32 *)(dev + 0xC) = *(u32 *)(lbl_803C0F78 + 0x1974);
    ++*(u32 *)(lbl_803C0F78 + 0x1974);
    return (tBTM_SEC_DEV_REC *)dev;
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

tBTM_SEC_DEV_REC *btm_find_oldest_dev(void) {
    tBTM_SEC_DEV_REC *p_dev_rec = (tBTM_SEC_DEV_REC *)(lbl_803C0F78 + 0x1F30);
    tBTM_SEC_DEV_REC *p_oldest = p_dev_rec;
    UINT32 ot = 0xFFFFFFFF;
    int i;
    for (i = 0; i < 16; i++, p_dev_rec++) {
        if (((p_dev_rec->sec_flags & 0x80) == 0) || ((p_dev_rec->sec_flags & 0x10) != 0))
            continue;
        if (p_dev_rec->timestamp < ot) {
            p_oldest = p_dev_rec;
            ot = p_dev_rec->timestamp;
        }
    }
    if (ot != 0xFFFFFFFF) return p_oldest;
    p_dev_rec = (tBTM_SEC_DEV_REC *)(lbl_803C0F78 + 0x1F30);
    for (i = 0; i < 16; i++, p_dev_rec++) {
        if ((p_dev_rec->sec_flags & 0x80) == 0) continue;
        if (p_dev_rec->timestamp < ot) {
            p_oldest = p_dev_rec;
            ot = p_dev_rec->timestamp;
        }
    }
    return p_oldest;
}

#pragma small_data on
void btm_dev_init(void) {
    memcpy(lbl_803C0F78 + 0x648, &lbl_80559060, 3);
    *(u16 *)(lbl_803C0F78 + 0x64C) = 0x1400;
    *(u32 *)(lbl_803C0F78 + 0x584) = 1;
    *(u32 *)(lbl_803C0F78 + 0x5A0) = 2;
    *(u32 *)(lbl_803C0F78 + 0x5BC) = 4;
    *(u16 *)(lbl_803C0F78 + 0x654) = 0xCC18;
    *(u16 *)(lbl_803C0F78 + 0x656) = 0x3F;
    lbl_803C0F78[0x27BD] = 0xFF;
    lbl_803C0F78[0x27BE] = 0xFF;
    lbl_803C0F78[0x64E] = 0;
    lbl_803C0F78[0x64F] = 5;
    btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 4);
    ((void (*)(void))btsnd_hcic_reset)();
}
void btm_discovery_db_reset(void);
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

u8 BTM_SetAfhChannels(u8 first, u8 last) {
    if (lbl_803C0F78[0x27C0] >= 3) {
        ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)(
            0xD0002, lbl_803160C0, first, lbl_803C0F78[0x27BD],
            last, lbl_803C0F78[0x27BE]);
    }
    if (!(lbl_803C0F78[0x645] & 8) &&
        !(lbl_803C0F78[0x644] & 0x10) &&
        !(lbl_803C0F78[0x645] & 0x10)) {
        return 4;
    }
    if (lbl_803C0F78[0x27BD] != first ||
        lbl_803C0F78[0x27BE] != last) {
        if (!btsnd_hcic_set_afh_channels(first, last)) {
            goto no_resources;
        }
        lbl_803C0F78[0x27BD] = first;
        lbl_803C0F78[0x27BE] = last;
        goto success;
    }
    goto success;

no_resources:
    return 3;
success:
    return 0;
}

void fn_8008C04C(s16);
s32 btsnd_hcic_inq_cancel_8008576C(void);
s32 btsnd_hcic_inq_cancel_80085850(void);
void btm_read_hci_buf_size_complete(UINT8 *p, UINT16 evt_len) {
    UINT8 status = p[0];

    if (status == 0) {
        UINT16 high;
        UINT16 low;
        UINT16 size;
        UINT16 packet_size;
        UINT16 num;
        UINT8 num_hi;
        UINT8 num_lo;
        UINT8 *base;

        high = p[2];
        base = lbl_803C0A50;
        low = p[1];
        size = low + (high << 8);
        *(UINT16 *)(base + 0x7C) = size;
        size = (UINT16)size;
        packet_size = size + 4;
        num_hi = p[5];
        num_lo = p[4];
        num = num_lo + (num_hi << 8);
        *(UINT16 *)(base + 0x7E) = packet_size;
        ((void (*)(UINT16))fn_8008C04C)(num);
        btsnd_hcic_set_host_buf_size(0x69B, 0x1E, 0x14, 0xA);
        lbl_803C0F78[0x64E] = 3;
        lbl_803C0F78[0x64F] = 4;
    } else {
        lbl_803C0F78[0x64F] = status;
        lbl_803C0F78[0x64E] = status;
        btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 1);
        ((void (*)(void))btsnd_hcic_reset)();
        return;
    }
    btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 1);
    btsnd_hcic_inq_cancel_8008576C();
    btsnd_hcic_inq_cancel_80085850();
    btm_pm_reset();
}

void btm_read_local_version_complete(UINT8 *p, UINT16 evt_len) {
    register UINT8 *base = lbl_803C0F78;
    UINT8 status = p[0];
    if (status == 0) {
        base[0x636] = p[1];
        *(u16 *)(base + 0x638) = p[2] + (p[3] << 8);
        base[0x63A] = p[4];
        *(u16 *)(base + 0x63C) = p[5] + (p[6] << 8);
        *(u16 *)(base + 0x63E) = p[7] + (p[8] << 8);
        lbl_803C0F78[0x64E] = 4;
        lbl_803C0F78[0x64F] = 4;
    } else {
        lbl_803C0F78[0x64F] = status;
        lbl_803C0F78[0x64E] = status;
        btu_start_timer(base + 0x574, 1, 1);
        ((void (*)(void))btsnd_hcic_reset)();
        return;
    }
    btu_start_timer(lbl_803C0F78 + 0x574, 1, 1);
    btsnd_hcic_reset_800857CC();
}

extern char lbl_803160C0[];
extern void fn_8007F5A4(void);
void btm_read_local_features_complete(u8 *arg0, u16 arg1) {
    register u8 *cb;
    register u8 (*strings)[1];
    register u8 temp_r29;
    register void (*temp_r28)(s32);
    register u8 temp_r27;
    register u8 temp_r0;
    u8 flags;

    cb = lbl_803C0F78;
    strings = (u8 (*)[1])lbl_803160C0;
    temp_r28 = *(void (**)(s32))(cb + 0x58C);
    *(void (**)(s32))(cb + 0x58C) = 0;
    if (arg0[0] == 0) {
        cb[0x64E] = 5;
        temp_r0 = arg0[1];
        cb[0x640] = temp_r0;
        cb[0x641] = arg0[2];
        cb[0x642] = arg0[3];
        cb[0x643] = arg0[4];
        cb[0x644] = arg0[5];
        cb[0x645] = arg0[6];
        cb[0x646] = arg0[7];
        cb[0x647] = arg0[8];

        *(u16 *)(lbl_803C0F78 + 0x654) = 0x18;
        if (temp_r0 & 1) *(u16 *)(lbl_803C0F78 + 0x654) |= 0xC00;
        if (cb[0x640] & 2) *(u16 *)(lbl_803C0F78 + 0x654) |= 0xC000;

        if ((*(u8 *)(lbl_803C0F78 + 0x636)) >= 3) {
            if (!(cb[0x643] & 2)) *(u16 *)(lbl_803C0F78 + 0x654) |= 0x1102;
            if (!(cb[0x643] & 4)) *(u16 *)(lbl_803C0F78 + 0x654) |= 0x2204;
            if ((cb[0x643] & 2) || (cb[0x643] & 4)) {
                if (!(cb[0x644] & 0x80)) *(u16 *)(lbl_803C0F78 + 0x654) |= 0x300;
                if (!(cb[0x645] & 1)) *(u16 *)(lbl_803C0F78 + 0x654) |= 0x3000;
            }
        }

        if ((*(u8 *)(lbl_803C0F78 + 0x27C0)) >= 5) fn_80070954(0xD0004, strings + 0x44, *(u16 *)(lbl_803C0F78 + 0x654));

        temp_r0 = cb[0x641];
        *(u16 *)(lbl_803C0F78 + 0x656) = 0;
        (*(u8 *)(lbl_803C0F78 + 0x1908)) = 0;
        if (temp_r0 & 8) {
            *(u16 *)(lbl_803C0F78 + 0x656) = 1;
            if (temp_r0 & 0x10) *(u16 *)(lbl_803C0F78 + 0x656) |= 2;
            if (cb[0x641] & 0x20) *(u16 *)(lbl_803C0F78 + 0x656) |= 4;
        }
        if (cb[0x643] & 0x80) *(u16 *)(lbl_803C0F78 + 0x656) |= 8;
        if (cb[0x644] & 1) *(u16 *)(lbl_803C0F78 + 0x656) |= 0x10;
        if (cb[0x644] & 2) *(u16 *)(lbl_803C0F78 + 0x656) |= 0x20;

        if (*(u16 *)(lbl_803C0F78 + 0x656) & 0x38) {
            (*(u8 *)(lbl_803C0F78 + 0x1908)) = 1;
            temp_r0 = cb[0x645];
            if (temp_r0 & 0x20) {
                if (!(temp_r0 & 0x80)) *(u16 *)(lbl_803C0F78 + 0x656) |= 0x100;
            } else {
                *(u16 *)(lbl_803C0F78 + 0x656) |= 0x140;
            }
            temp_r0 = *(volatile u8 *)(cb + 0x645);
            if (temp_r0 & 0x40) {
                if (!(temp_r0 & 0x80)) *(u16 *)(lbl_803C0F78 + 0x656) |= 0x200;
            } else {
                *(u16 *)(lbl_803C0F78 + 0x656) |= 0x280;
            }
        }

        if ((*(u8 *)(lbl_803C0F78 + 0x27C0)) >= 5) fn_80070954(0xD0004, strings + 0x70, *(u16 *)(lbl_803C0F78 + 0x656));

        if (cb[0x640] & 0x20) *(u16 *)(lbl_803C0F78 + 0x4C4) |= 1;
        else *(u16 *)(lbl_803C0F78 + 0x4C4) &= 0xFFFE;
        if (cb[0x640] & 0x40) *(u16 *)(lbl_803C0F78 + 0x4C4) |= 2;
        else *(u16 *)(lbl_803C0F78 + 0x4C4) &= 0xFFFFFFFD;
        if (cb[0x640] & 0x80) *(u16 *)(lbl_803C0F78 + 0x4C4) |= 4;
        else *(u16 *)(lbl_803C0F78 + 0x4C4) &= 0xFFFFFFFB;
        if (cb[0x641] & 1) *(u16 *)(lbl_803C0F78 + 0x4C4) |= 8;
        else *(u16 *)(lbl_803C0F78 + 0x4C4) &= 0xFFFFFFF7;

        fn_8007F5A4();
        temp_r29 = (*(u8 *)(lbl_803C0F78 + 0x27BE));
        if (temp_r29 != 0xFF) {
            temp_r27 = (*(u8 *)(lbl_803C0F78 + 0x27BD));
            (*(u8 *)(lbl_803C0F78 + 0x27BE)) = 0xFF;
            (*(u8 *)(lbl_803C0F78 + 0x27BD)) = 0xFF;
            if ((*(u8 *)(lbl_803C0F78 + 0x27C0)) >= 3) {
                ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)(0xD0002, strings, temp_r27, 0xFF, temp_r29, 0xFF);
            }
            flags = *(u8 *)(lbl_803C0F78 + 0x645);
            if (((flags & 8) || (*(u8 *)(lbl_803C0F78 + 0x644) & 0x10) || (flags & 0x10)) &&
                (((*(u8 *)(lbl_803C0F78 + 0x27BD)) != temp_r27) || ((*(u8 *)(lbl_803C0F78 + 0x27BE)) != temp_r29)) &&
                btsnd_hcic_set_afh_channels(temp_r27, temp_r29)) {
                (*(u8 *)(lbl_803C0F78 + 0x27BD)) = temp_r27;
                (*(u8 *)(lbl_803C0F78 + 0x27BE)) = temp_r29;
            }
        }
        if (cb[0x643] & 0x40) BTM_SetInquiryMode(1);
        BTM_SetPageScanType(1);
        BTM_SetInquiryScanType(1);
        if (*(void (**)(s32))(lbl_803C0F78 + 0x568) != 0) (*(void (**)(s32))(lbl_803C0F78 + 0x568))(0);
    }
    if (temp_r28 != 0) temp_r28(0);
}

void fn_80085DC4(void *arg0, u8 arg1) {
    *(u16 *)((u8 *)arg0 + 2) = 4;
    *(u16 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x43;
    *(u8 *)((u8 *)arg0 + 9) = 0x0C;
    *(u8 *)((u8 *)arg0 + 10) = 1;
    *(u8 *)((u8 *)arg0 + 11) = arg1;
    btu_hcif_send_cmd(arg0);
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
    volatile u16 *base = (volatile u16 *)lbl_803C0F78;
    u16 first;
    u16 second;
    u16 third;
    u16 fourth;

    if (((volatile u8 *)base)[0x64e] < 4) return 0xC;
    first = base[0x31b];
    second = base[0x31c];
    arg0[0] = first;
    arg0[1] = second;
    third = base[0x31d];
    fourth = base[0x31e];
    arg0[2] = third;
    arg0[3] = fourth;
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

tBTM_STATUS BTM_VendorSpecificCommand(UINT16 opcode, UINT8 param_len, UINT8 *p_param_buf, tBTM_VSC_CMPL_CB *p_cb)
{
    extern char lbl_8031615C[];
    extern char lbl_8031619C[];
    void *buffer;
    UINT8 *base;

    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_8007096C(0xD0003, lbl_8031615C, opcode, param_len);
    }
    base = lbl_803C0F78;
    if (base[0x650] != 0) {
        if (base[0x27C0] >= 4) {
            fn_8007093C(0xD0003, lbl_8031619C);
        }
        return 2;
    }
    buffer = GKI_getbuf(param_len + 0xB);
    if (buffer != 0) {
        *(tBTM_VSC_CMPL_CB **)(base + 0x61C) = p_cb;
        if (p_cb != 0) {
            base[0x650] = 1;
        }
        ((void (*)(void *, UINT16, UINT8, UINT8 *))btsnd_hcic_vendor_spec_cmd)(buffer, opcode, param_len, p_param_buf);
        if (p_cb != 0) {
            return 1;
        }
        return 0;
    }
    return 3;
}

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

void btm_vendor_specific_evt(UINT8 *p, UINT8 evt_len) {
    u8 *btm = lbl_803C0F78;
    void (*callback)(UINT8, UINT8 *);
    if (*(UINT16 *)(btm + 0x63C) != 0x12 && *(UINT8 *)(btm + 0x27C0) >= 4) {
        fn_8007093C(0xD0003, lbl_803161E0);
    }
    callback = *(void (**)(UINT8, UINT8 *))(btm + 0x56C);
    *(UINT32 *)(btm + 0x61C) = 0;
    *(UINT8 *)(btm + 0x650) = 0;
    if (callback != 0) {
        callback(evt_len, p);
    }
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

tBTM_STATUS BTM_ReadStoredLinkKey(BD_ADDR bd_addr, tBTM_CMPL_CB *p_cb) {
    extern char lbl_80316290[];
    extern u8 lbl_80559064;
    extern u8 lbl_8055906C;
    BD_ADDR local_bd_addr;
    BOOLEAN read_all_flag = FALSE;
    u8 *p_buf;

    if (*(u32 *)(lbl_803C0F78 + 0x570) != 0)
        return BTM_BUSY;
    if (bd_addr == NULL) {
        read_all_flag = TRUE;
        bd_addr = local_bd_addr;
    }
    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_80070954(
            0xD0003,
            lbl_80316290,
            read_all_flag ? (u16)&lbl_80559064 : (u16)&lbl_8055906C
        );
    }
    p_buf = GKI_getpoolbuf(2);
    if (p_buf != NULL) {
        *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570) = p_cb;
        ((void (*)())btsnd_hcic_read_stored_key)(p_buf, bd_addr, read_all_flag, lbl_803C0F78);
        return BTM_SUCCESS;
    }
    return BTM_NO_RESOURCES;
}

extern char lbl_803162BC[];
tBTM_STATUS BTM_WriteStoredLinkKey(UINT8 num_keys, BD_ADDR *bd_addr, LINK_KEY *link_key, tBTM_CMPL_CB *p_cb) {
    void *buffer;

    if (*(u32 *)(lbl_803C0F78 + 0x570) != 0)
        return BTM_BUSY;

    if (*(u8 *)(lbl_803C0F78 + 0x27C0) >= 4)
        fn_80070954(0xD0003, lbl_803162BC, num_keys);

    if (num_keys > 0xB)
        num_keys = 0xB;

    buffer = GKI_getpoolbuf(2);
    if (buffer != NULL) {
        *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570) = p_cb;
        ((void (*)(void *, UINT8, BD_ADDR *, LINK_KEY *))btsnd_hcic_write_stored_key)(
            buffer, num_keys, bd_addr, link_key
        );
        return BTM_SUCCESS;
    }
    return BTM_NO_RESOURCES;
}

tBTM_STATUS BTM_DeleteStoredLinkKey(BD_ADDR bd_addr, tBTM_CMPL_CB *p_cb) {
    extern u8 lbl_803162E8[];
    extern u8 lbl_80559064;
    extern u8 lbl_8055906C;
    extern s32 btsnd_hcic_switch_role_8008515C(BD_ADDR, UINT8);
    BD_ADDR local_bd_addr;
    BOOLEAN delete_all_flag = FALSE;

    if (*(u32 *)(lbl_803C0F78 + 0x570) != 0)
        return BTM_BUSY;
    if (bd_addr == NULL) {
        delete_all_flag = TRUE;
        bd_addr = local_bd_addr;
    }
    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_80070954(
            0xD0003,
            lbl_803162E8,
            delete_all_flag ? (u16)&lbl_80559064 : (u16)&lbl_8055906C
        );
    }
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570) = p_cb;
    if ((u8)btsnd_hcic_switch_role_8008515C(bd_addr, delete_all_flag) == 0)
        return BTM_NO_RESOURCES;
    return BTM_SUCCESS;
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

/* Reverses each returned address and link key in place before invoking the callback. */
void btm_return_link_keys_evt(tBTM_RETURN_LINK_KEYS_EVT *result) {
    tBTM_CMPL_CB *p_cb = *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570);
    UINT8 i, *p, *p1;
    UINT8 bd_addr[BD_ADDR_LEN];
    UINT8 link_key[LINK_KEY_LEN];
    if (p_cb) {
        p = (UINT8 *)(result + 1);
        for (i = 0; i < result->num_keys; i++) {
            p1 = p;
            REVERSE_STREAM_TO_ARRAY(bd_addr, p1, BD_ADDR_LEN);
            REVERSE_STREAM_TO_ARRAY(link_key, p1, LINK_KEY_LEN);
            ARRAY_TO_STREAM(p, bd_addr, BD_ADDR_LEN);
            ARRAY_TO_STREAM(p, link_key, LINK_KEY_LEN);
        }
        (*p_cb)(result);
    }
}

void fn_8007ABE8(void *arg0) {
    void (*callback)(void) = *(void (**)(void))(lbl_803C0F78 + 0x568);
    if (callback != NULL) callback();
}

void btm_discovery_db_init(void) {
    *(u8 **)(lbl_803C0F78 + 0x1678) = lbl_803C0F78 + 0x6D4;
    memset(lbl_803C0F78 + 0x658, 0, 0x1020);
    *(u16 *)(lbl_803C0F78 + 0x670) = 1;
    *(u16 *)(lbl_803C0F78 + 0x674) = 2;
    *(u16 *)(lbl_803C0F78 + 0x678) = 0x1002;
    SDP_InitDiscoveryDb(*(tSDP_DISCOVERY_DB **)(lbl_803C0F78 + 0x1678), 0xFA0, 1, (tSDP_UUID *)(lbl_803C0F78 + 0x674), 0, 0);
}

void btm_discovery_db_reset(void)
{
    void (*callback)(s32);

    fn_80070F90(lbl_803C0F78 + 0x658);
    if (lbl_803C0F78[0x1674] != 0) {
        callback = *(void (**)(s32))(lbl_803C0F78 + 0x6D0);
        lbl_803C0F78[0x1674] = 0;
        *(void (**)(s32))(lbl_803C0F78 + 0x6D0) = 0;
        if (callback != 0)
            callback(0);
    }

    *(tSDP_DISCOVERY_DB **)(lbl_803C0F78 + 0x1678) =
        (tSDP_DISCOVERY_DB *)(lbl_803C0F78 + 0x6D4);
    memset(lbl_803C0F78 + 0x658, 0, 0x1020);
    *(u16 *)(lbl_803C0F78 + 0x670) = 1;
    *(u16 *)(lbl_803C0F78 + 0x674) = 2;
    *(u16 *)(lbl_803C0F78 + 0x678) = 0x1002;
    SDP_InitDiscoveryDb(*(tSDP_DISCOVERY_DB **)(lbl_803C0F78 + 0x1678),
                        0xFA0, 1, (tSDP_UUID *)(lbl_803C0F78 + 0x674), 0, 0);
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

extern void fn_80085E24(void *, u8);
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

extern u8 lbl_8031637C[];
extern void fn_80085384(u8 *, u8);
extern void fn_800853B4(u8 *, u16, u16);
tBTM_STATUS BTM_SetConnectability(UINT16 page_mode, UINT16 window, UINT16 interval) {
    s32 var_r28 = window;
    s32 var_r29 = interval;
    u8 flags = 0;
    if (page_mode != 0 && page_mode != 1) return 5;
    if (lbl_803C0F78[0x64E] < 3) return 0xC;
    if (window == 0) var_r28 = 0x12;
    if (interval == 0) var_r29 = 0x800;
    if (lbl_803C0F78[0x27C0] >= 3)
        ((void (*)(u32, void *, u16, u16, u16))fn_80070984)(0xD0002, lbl_8031637C, page_mode, var_r28, var_r29);
    if (page_mode == 1) {
        if (var_r28 < 0x12 || var_r28 > 0x1000 || var_r29 < 0x12 || var_r29 > 0x1000 || var_r28 > var_r29) return 5;
        flags |= 2;
    }
    if (var_r28 != *(u16 *)(lbl_803C0F78 + 0x169C) || var_r29 != *(u16 *)(lbl_803C0F78 + 0x169E)) {
        u8 *buf = GKI_getpoolbuf(2);
        if (!buf) return 3;
        *(u16 *)(lbl_803C0F78 + 0x169C) = var_r28;
        *(u16 *)(lbl_803C0F78 + 0x169E) = var_r29;
        fn_800853B4(buf, var_r29, var_r28);
    }
    {
        u8 *buf = GKI_getpoolbuf(2);
        if (!buf) return 3;
        if (*(u16 *)(lbl_803C0F78 + 0x1698) != 0) flags |= 1;
        *(u16 *)(lbl_803C0F78 + 0x169A) = page_mode;
        fn_80085384(buf, flags);
    }
    return 0;
}

u8 fn_8007B340(void) {
    return lbl_803C0F78[0x1848];
}

extern u8 lbl_803163D0[];
tBTM_STATUS BTM_CancelInquiry(void) {
    tBTM_STATUS result = 0;
    u8 *cb = lbl_803C0F78;
    u8 *cb2;
    if (cb[0x27C0] >= 3) fn_8007093C(0xD0002, lbl_803163D0);
    if (fn_80079514() == 0) return 6;
    if (cb[0x1848] != 0 && !(cb[0x1848] & 4)) {
        cb[0x1848] = 0;
        cb[0x1847] = 0;
        *(u32 *)(cb + 0x16B4) = 0;
        *(u32 *)(cb + 0x16B0) = 0;
        if (cb[0x1844] != 0) {
            cb[0x1844] = 0;
            cb[0x1845]++;
        } else if (btsnd_hcic_inq_cancel() == 0) result = 3;
        cb2 = lbl_803C0F78;
        *(u32 *)(cb + 0x16C0) += 1;
        if (*(void **)(cb2 + 0x16DC) != NULL) {
            GKI_freebuf(*(void **)(cb2 + 0x16DC));
            *(u32 *)(cb2 + 0x16DC) = 0;
        }
        *(u16 *)(cb2 + 0x16E0) = 0;
        *(u16 *)(cb2 + 0x16E2) = 0;
    }
    return result;
}

tBTM_STATUS BTM_StartInquiry(tBTM_INQ_PARMS *params, tBTM_INQ_RESULTS_CB *results_cb, tBTM_CMPL_CB *complete_cb) {
    extern u8 lbl_803163EC[];
    u8 *state = lbl_803C0F78;
    u8 *p = (u8 *)params;
    u8 a, b, c, d, e, f;
    s32 mode;
    u8 status;

    if (state[0x27C0] >= 3)
        ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)(0xD0002, lbl_803163EC, p[0], p[1], p[2], p[3]);
    if (state[0x1848] != 0 || state[0x1844] != 0)
        return 2;
    if (p[0] != 0 && p[0] != 1)
        return 5;
    if (fn_80079514() == 0)
        return 6;
    a = p[0]; b = p[1]; state[0x1834] = a; state[0x1835] = b;
    c = p[2]; d = p[3]; state[0x1836] = c; state[0x1837] = d;
    e = p[4]; f = p[5]; state[0x1838] = e; state[0x1839] = f;
    a = p[6]; b = p[7]; state[0x183A] = a; state[0x183B] = b;
    a = p[8]; b = p[9]; state[0x183C] = a; state[0x183D] = b;
    state[0x1847] = 3;
    *(void **)(state + 0x16B0) = complete_cb;
    *(void **)(state + 0x16B4) = results_cb;
    state[0x183F] = 0;
    mode = p[0];
    state[0x1848] = ((s32)~((mode - 1) | (1 - mode)) >> 31) + 2;
    if (p[3] == 0) {
        state[0x1847] = 2;
    } else if (p[3] > 0 && p[3] < 3) {
        state[0x1847] = 1;
        p[3] = 0;
    } else {
        return 5;
    }
    status = btm_set_inq_event_filter(p[3], p + 4);
    if (status != 1)
        state[0x1847] = 0;
    return status;
}

#pragma push
#pragma use_lmw_stmw off
tBTM_STATUS BTM_ReadRemoteDeviceName(BD_ADDR remote_bda, tBTM_CMPL_CB *p_cb) {
    extern char lbl_80316424[];
    u8 *entry;
    u8 *p_i;
    u32 i;
    tBTM_INQ_INFO *p_cur = NULL;

    if (lbl_803C0F78[0x27C0] >= 3) {
        fn_800709CC(0xD0002, lbl_80316424,
                    remote_bda[0], remote_bda[1], remote_bda[2],
                    remote_bda[3], remote_bda[4], remote_bda[5]);
    }

    entry = lbl_803C0F78 + 0x16E4;
    for (i = 0; i < 0xC; i++, entry += 0x1C) {
        if (entry[0x1A] != 0 && memcmp(entry + 0xA, remote_bda, 6) == 0) {
            p_i = entry;
            goto found;
        }
    }
    p_i = NULL;
found:
    if (p_i != NULL)
        p_cur = (tBTM_INQ_INFO *)(p_i + 8);

    return btm_initiate_rem_name(remote_bda, p_cur, 1, 0x28, p_cb);
}
#pragma pop

tBTM_INQ_INFO *BTM_InqDbRead(BD_ADDR p_bda) {
    extern char lbl_80316484[];
    u32 i;
    u8 *cb = lbl_803C0F78;
    u8 *entry = cb + 0x16E4;

    if (cb[0x27C0] >= 3) {
        fn_800709CC(0xD0002, lbl_80316484,
                    p_bda[0], p_bda[1], p_bda[2],
                    p_bda[3], p_bda[4], p_bda[5]);
    }

    for (i = 0; i < 0xC; i++, entry += 0x1C) {
        if (entry[0x1A] != 0 && memcmp(entry + 0xA, p_bda, 6) == 0)
            return (tBTM_INQ_INFO *)(entry + 8);
    }
    return NULL;
}

tBTM_INQ_INFO *BTM_InqDbFirst(void) {
    UINT16 xx;
    u8 *entry = lbl_803C0F78 + 0x16E4;

    for (xx = 0; xx < 12; xx++, entry += 0x1C) {
        if (entry[0x1A])
            return (tBTM_INQ_INFO *)(entry + 8);
    }

    return 0;
}

tBTM_INQ_INFO *BTM_InqDbNext(tBTM_INQ_INFO *p_cur) {
    u8 *base;
    u8 *entry;
    u16 index;
    s32 count;

    base = lbl_803C0F78 + 0x16E4;
    if (p_cur != 0) {
        index = (((u8 *)p_cur - 8 - base) / 28) + 1;
        entry = base + index * 0x1C;
        count = 0xC - index;
        if (index < 0xC) {
            do {
                if (entry[0x1A] != 0) return (tBTM_INQ_INFO *)(entry + 8);
                entry += 0x1C;
            } while (--count != 0);
        }
        return 0;
    }
    entry = base;
    count = 2;
    do {
        if (entry[0x1A] != 0) return (tBTM_INQ_INFO *)(entry + 8);
        if (entry[0x36] != 0) return (tBTM_INQ_INFO *)(entry + 0x24);
        if (entry[0x52] != 0) return (tBTM_INQ_INFO *)(entry + 0x40);
        if (entry[0x6E] != 0) return (tBTM_INQ_INFO *)(entry + 0x5C);
        if (entry[0x8A] != 0) return (tBTM_INQ_INFO *)(entry + 0x78);
        if (entry[0xA6] != 0) return (tBTM_INQ_INFO *)(entry + 0x94);
        entry += 0xA8;
    } while (--count != 0);
    return 0;
}

tBTM_STATUS BTM_ClearInqDb(BD_ADDR p_bda) {
    u8 *base_copy = lbl_803C0F78;
    register u8 *base;
    u16 i;
    u8 *entry;
    tBTM_INQ_DB_CHANGE_CB *callback;

    base = base_copy;
    if (base[0x1848] != 0 || base[0x16AE] != 0 || base[0x1844] != 0)
        return BTM_BUSY;

    for (i = 0, entry = base + 0x16E4; i < 0xC; i++, entry += 0x1C) {
        if (entry[0x1A] != 0 && (p_bda == NULL || memcmp(entry + 0xA, p_bda, BD_ADDR_LEN) == 0)) {
            entry[0x1A] = FALSE;
            callback = *(tBTM_INQ_DB_CHANGE_CB **)(base + 0x16BC);
            if (callback != NULL)
                callback(entry + 8, FALSE);
        }
    }
    return BTM_SUCCESS;
}

void btm_inq_db_reset(void) {
    tBTM_REMOTE_DEV_NAME rem_name;
    tBTM_INQUIRY_VAR_ST *p_inq = &btm_cb.btm_inq_vars;
    UINT8 num_responses;
    UINT8 temp_inq_active;
    tBTM_STATUS status;
    btu_stop_timer(&p_inq->inq_timer_ent);
    if (p_inq->inq_active != BTM_INQUIRY_INACTIVE) {
        temp_inq_active = p_inq->inq_active;
        p_inq->inq_active = BTM_INQUIRY_INACTIVE;
        if (temp_inq_active == BTM_LIMITED_INQUIRY_ACTIVE || temp_inq_active == BTM_GENERAL_INQUIRY_ACTIVE) {
            if (p_inq->p_inq_cmpl_cb) {
                num_responses = 0;
                (*p_inq->p_inq_cmpl_cb)(&num_responses);
            }
        }
    }
    if (p_inq->remname_active) {
        btu_stop_timer(&p_inq->rmt_name_timer_ent);
        p_inq->remname_active = FALSE;
        memset(p_inq->remname_bda, 0, BD_ADDR_LEN);
        if (p_inq->p_remname_cmpl_cb) {
            rem_name.status = BTM_DEV_RESET;
            (*p_inq->p_remname_cmpl_cb)(&rem_name);
            p_inq->p_remname_cmpl_cb = NULL;
        }
    }
    if (p_inq->inqfilt_active) {
        p_inq->inqfilt_active = FALSE;
        if (p_inq->p_inqfilter_cmpl_cb) {
            status = BTM_DEV_RESET;
            (*p_inq->p_inqfilter_cmpl_cb)(&status);
        }
    }
    p_inq->state = BTM_INQ_INACTIVE_STATE;
    p_inq->pending_filt_complete_event = 0;
    p_inq->p_inq_results_cb = NULL;
    btm_clr_inq_db(NULL);
    btm_clr_inq_result_flt();
    p_inq->discoverable_mode = BTM_NON_DISCOVERABLE;
    p_inq->connectable_mode = BTM_NON_CONNECTABLE;
    p_inq->page_scan_type = BTM_SCAN_TYPE_STANDARD;
    p_inq->inq_scan_type = BTM_SCAN_TYPE_STANDARD;
    return;
}

void fn_8007BC88(void) {

}

BOOLEAN btm_inq_find_bdaddr(BD_ADDR addr) {
    u8 *state = lbl_803C0F78;
    u16 count;
    u8 *entry;
    u16 i;

    entry = *(u8 **)(state + 0x16DC);
    if ((state[0x1848] & 4) != 0 || entry == NULL)
        return FALSE;
    count = *(u16 *)(state + 0x16E0);
    for (i = 0; i < count; i++, entry += 0xC) {
        if (memcmp(entry + 4, addr, 6) == 0 &&
            *(u32 *)entry == *(u32 *)(state + 0x16C0))
            return TRUE;
    }
    if (i < *(u16 *)(state + 0x16E2)) {
        *(u32 *)entry = *(u32 *)(state + 0x16C0);
        memcpy(entry + 4, addr, 6);
        *(u16 *)(state + 0x16E0) = *(u16 *)(state + 0x16E0) + 1;
    }
    return FALSE;
}

tINQ_DB_ENT *btm_inq_db_new(BD_ADDR p_bda) {
    UINT16 xx;
    u8 *p_ent;
    u8 *p_old;
    UINT32 ot;
    tBTM_INQ_DB_CHANGE_CB *callback;

    p_ent = lbl_803C0F78 + 0x16E4;
    p_old = p_ent;
    ot = 0xFFFFFFFF;
    for (xx = 0; xx < 0xC; xx++, p_ent += 0x1C) {
        if (!p_ent[0x1A]) {
            memset(p_ent, 0, 0x1C);
            memcpy(p_ent + 0xA, p_bda, BD_ADDR_LEN);
            p_ent[0x1A] = TRUE;
            return (tINQ_DB_ENT *)p_ent;
        }
        if (*(UINT32 *)p_ent < ot) {
            p_old = p_ent;
            ot = *(UINT32 *)p_ent;
        }
    }
    callback = *(tBTM_INQ_DB_CHANGE_CB **)(lbl_803C0F78 + 0x16BC);
    if (callback)
        (*callback)(p_old + 8, FALSE);
    memset(p_old, 0, 0x1C);
    memcpy(p_old + 0xA, p_bda, BD_ADDR_LEN);
    p_old[0x1A] = TRUE;
    return (tINQ_DB_ENT *)p_old;
}

static tBTM_STATUS btm_set_inq_event_filter(UINT8 filter_cond_type, UINT8 *p_filt_cond) {
    void *p_buf;
    UINT8 condition_length = 6;
    UINT8 condition_buf[6];
    UINT8 *p_cond = condition_buf;

    p_buf = GKI_getpoolbuf(2);
    if (p_buf != NULL) {
        switch (filter_cond_type) {
        case 1:
            memcpy(condition_buf, p_filt_cond, 3);
            memcpy(&condition_buf[3], p_filt_cond + 3, 3);
            break;
        case 2:
            p_cond = p_filt_cond;
            break;
        case 0:
            condition_length = 0;
            break;
        default:
            return 5;
        }

        lbl_803C0F78[0x1844] = 1;
        ((BOOLEAN (*)(void *, UINT8, UINT8, UINT8 *, UINT8))btsnd_hcic_set_event_filter)(
            p_buf, 1, filter_cond_type, p_cond, condition_length);
        return 1;
    }

    return 3;
}

void btm_process_inq_complete(UINT8 status, UINT8 unused) {
    u8 result;
    void *zero;
    void (*callback)(void *);
    u8 *base;
    void *buffer;
    u8 *cleanup_base;

    base = lbl_803C0F78;
    callback = *(void (**)(void *))(base + 0x16B0);
    if (base[0x1848] != 0) {
        result = 10;
        *(u32 *)(base + 0x16C0) += 1;
        if (status == 0)
            result = 0;
        base[0x183E] = result;
        if ((base[0x1848] & 4) == 0) {
            cleanup_base = lbl_803C0F78;
            zero = NULL;
            buffer = *(void **)(cleanup_base + 0x16DC);
            *(u32 *)(base + 0x16B4) = (u32)zero;
            base[0x1848] = (u8)zero;
            base[0x1847] = (u8)zero;
            *(void (**)(void *))(base + 0x16B0) = NULL;
            if (buffer != NULL) {
                GKI_freebuf(buffer);
                *(void **)(cleanup_base + 0x16DC) = zero;
            }
            *(u16 *)(cleanup_base + 0x16E0) = (u16)zero;
            *(u16 *)(cleanup_base + 0x16E2) = (u16)zero;
            if (lbl_803C0F78[0x27C0] >= 5)
                fn_8007096C(0xD0004, lbl_803164F4,
                            base[0x183E], base[0x183F]);
            if (callback != NULL)
                callback(base + 0x183E);
        }
    }
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

void btm_process_remote_name(u8 *arg0, u8 *arg1, u16 arg2, u8 arg3) {
    extern unsigned char lbl_803C0F78[];
    u8 buffer[0xF8];
    u16 spA;
    s16 sp8;
    s32 (*callback)(s16 *);
    u16 len;
    u8 *src;
    u8 *dst;
    u32 blocks;
    u8 saved;
    src = arg1;
    callback = *(s32 (**)(s16 *))(lbl_803C0F78 + 0x167C);
    saved = lbl_803C0F78[0x16AE];
    fn_80070F90(lbl_803C0F78 + 0x1680);
    lbl_803C0F78[0x16AE] = 0;
    if (arg3 == 0) {
        dst = buffer;
        len = arg2;
        if (len >= 0xF8) len = 0xF8;
        spA = len;
        sp8 = 0;
        if (len != 0) {
            blocks = len >> 3;
            if (blocks != 0) do {
                dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
                dst[4] = src[4]; dst[5] = src[5]; dst[6] = src[6]; dst[7] = src[7];
                src += 8; dst += 8;
            } while (--blocks != 0);
            len &= 7;
            if (len != 0) do { *dst++ = *src++; } while (--len != 0);
        }
    } else {
        spA = 0;
        sp8 = 9;
        buffer[0] = arg3;
    }
    memset(lbl_803C0F78 + 0x16A8, 0, 6);
    if (saved & 1) {
        *(void **)(lbl_803C0F78 + 0x167C) = 0;
        if (callback != 0) callback(&sp8);
    }
}

#pragma pop

void fn_8007C794(void) {
    btm_process_remote_name(0, 0, 0, 0x1F);
    btm_sec_rmt_name_request_complete(0, 0, 0x1F);
}

void btm_init(void) {
    u8 *base = lbl_803C0F78;

    memset(base, 0, 0x27C4);
    base[0x27C0] = 0;
    fn_8007BC88();
    fn_80076E70();
    fn_8007F588(2);
    fn_8007D4C4();
    btm_dev_init();
}

tBTM_STATUS BTM_PmRegister(UINT8 mask, UINT8 *p_pm_id, tBTM_PM_STATUS_CBACK *p_cb)
{
    int i;
    u8 *entry;

    if (mask & BTM_PM_DEREG) {
        if (*p_pm_id >= BTM_MAX_PM_RECORDS)
            return BTM_ILLEGAL_VALUE;
        *(lbl_803C0F78 + *p_pm_id * 8 + 0x558) = BTM_PM_REC_NOT_USED;
        return BTM_SUCCESS;
    }

    for (i = 0, entry = lbl_803C0F78; i < BTM_MAX_PM_RECORDS; entry += 8, i++) {
        if (entry[0x558] == BTM_PM_REC_NOT_USED) {
            if (mask & BTM_PM_REG_NOTIF) {
                if (p_cb == NULL)
                    return BTM_ILLEGAL_VALUE;
                *(tBTM_PM_STATUS_CBACK **)(lbl_803C0F78 + i * 8 + 0x554) = p_cb;
            }
            *(u8 *)(lbl_803C0F78 + i * 8 + 0x558) = mask;
            *p_pm_id = i;
            return BTM_SUCCESS;
        }
    }
    return BTM_NO_RESOURCES;
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

void btm_pm_reset(void)
{
    int xx;
    tBTM_PM_STATUS_CBACK *cb = NULL;
    if ((btm_cb.pm_pend_id != BTM_PM_SET_ONLY_ID) &&
        (btm_cb.pm_reg_db[btm_cb.pm_pend_id].mask & BTM_PM_REG_NOTIF)) {
        cb = btm_cb.pm_reg_db[btm_cb.pm_pend_id].cback;
    }
    btm_cb.pm_pend_link = MAX_L2CAP_LINKS;
    for (xx = 0; xx < BTM_MAX_PM_RECORDS; xx++) {
        btm_cb.pm_reg_db[xx].mask = BTM_PM_REC_NOT_USED;
    }
    if (cb != NULL) {
        (*cb)(btm_cb.acl_db[btm_cb.pm_pend_link].remote_addr,
              BTM_PM_STS_ERROR, BTM_DEV_RESET, 0);
    }
}

void btm_pm_sm_alloc(u8 index) {
    u8 *entry;
    entry = lbl_803C0F78 + 0x4cc + index * 0x22;
    memset(entry, 0, 0x22);
    entry[0x20] = 0;
}

extern u8 lbl_802EEBE8[];
/* Match fix: the p_md1 == NULL path copies p_md2 verbatim and returns it; only forced modes clear BTM_PM_MD_FORCE. */
tBTM_PM_PWR_MD *btm_pm_compare_modes(tBTM_PM_PWR_MD *p_md1, tBTM_PM_PWR_MD *p_md2, tBTM_PM_PWR_MD *p_res) {
    u8 res;
    if (p_md1 == NULL) {
        *p_res = *p_md2;
        return p_md2;
    }
    if (p_md2->mode == BTM_PM_MD_ACTIVE || p_md1->mode == BTM_PM_MD_ACTIVE) return NULL;
    if (p_md1->mode & BTM_PM_MD_FORCE) {
        *p_res = *p_md1;
        p_res->mode &= ~BTM_PM_MD_FORCE;
        return p_res;
    }
    if (p_md2->mode & BTM_PM_MD_FORCE) {
        *p_res = *p_md2;
        p_res->mode &= ~BTM_PM_MD_FORCE;
        return p_res;
    }
    res = (p_md1->mode - 1) * 3 + (p_md2->mode - 1);
    res = lbl_802EEBE8[res];
    switch (res) {
    case 1:
        *p_res = *p_md1;
        return p_md1;
    case 2:
        *p_res = *p_md2;
        return p_md2;
    case 3:
        p_res->mode = p_md1->mode;
        p_res->max = p_md1->max < p_md2->max ? p_md1->max : p_md2->max;
        p_res->min = p_md1->min > p_md2->min ? p_md1->min : p_md2->min;
        if (p_res->max < p_res->min) return NULL;
        if (p_res->mode == BTM_PM_MD_SNIFF) {
            p_res->attempt = p_md1->attempt > p_md2->attempt ? p_md1->attempt : p_md2->attempt;
            p_res->timeout = p_md1->timeout > p_md2->timeout ? p_md1->timeout : p_md2->timeout;
        }
        return p_res;
    default:
        return NULL;
    }
}

u8 btm_pm_get_set_mode(u32 arg0, void *arg1, void *arg2, void *arg3) {
    extern unsigned char lbl_803C0F78[];
    void *previous = 0;
    void *entry = arg1;
    s32 i = 0;
    u16 t0, t1;
    if (arg2 != 0 && (*(u8 *)((u8 *)arg2 + 8) & 0x10)) {
        t1 = *(u16 *)((u8 *)arg2 + 0); t0 = *(u16 *)((u8 *)arg2 + 2);
        *(u16 *)((u8 *)arg3 + 0) = t1; *(u16 *)((u8 *)arg3 + 2) = t0;
        t1 = *(u16 *)((u8 *)arg2 + 4); t0 = *(u16 *)((u8 *)arg2 + 6);
        *(u16 *)((u8 *)arg3 + 4) = t1; *(u16 *)((u8 *)arg3 + 6) = t0;
        *(u16 *)((u8 *)arg3 + 8) = *(u16 *)((u8 *)arg2 + 8);
        *(u8 *)((u8 *)arg3 + 8) &= ~0x10;
        return *(u8 *)((u8 *)arg3 + 8);
    }
    while (i < 2) {
        if (lbl_803C0F78[0x558 + i * 8] & 1) {
            if (*(u8 *)((u8 *)entry + 8) == 0) return 0;
            if (btm_pm_compare_modes(previous, entry, arg3) == 0) return 0;
            previous = arg3;
        }
        i++; entry = (u8 *)entry + 0xA;
    }
    if (previous == 0) {
        if (arg2 == 0) return 0;
        t1 = *(u16 *)((u8 *)arg2 + 0); t0 = *(u16 *)((u8 *)arg2 + 2);
        *(u16 *)((u8 *)arg3 + 0) = t1; *(u16 *)((u8 *)arg3 + 2) = t0;
        t1 = *(u16 *)((u8 *)arg2 + 4); t0 = *(u16 *)((u8 *)arg2 + 6);
        *(u16 *)((u8 *)arg3 + 4) = t1; *(u16 *)((u8 *)arg3 + 6) = t0;
        *(u16 *)((u8 *)arg3 + 8) = *(u16 *)((u8 *)arg2 + 8);
    } else if (arg0 == 0x80 && btm_pm_compare_modes(arg2, previous, arg3) == 0) return 0;
    return *(u8 *)((u8 *)arg3 + 8);
}

void btm_pm_proc_cmd_status(UINT8 status) {
    u8 result;
    u8 *base = lbl_803C0F78;
    u8 state = base[0x564];
    u8 *record;
    if (state >= 4) {
        return;
    }
    record = base + state * 0x22;
    if (status == 0) {
        record[0x4EC] = 4;
        result = 4;
    } else {
        result = 5;
    }
    if (lbl_803C0F78[0x565] != 0x80) {
        u8 *entry = lbl_803C0F78 + (lbl_803C0F78[0x565] << 3);
        if (entry[0x558] & 2) {
            void *context = lbl_803C0F78 +
                *(volatile u8 *)(lbl_803C0F78 + 0x564) * 0x11C + 0x3C;
            void (*callback)(void *, s32, s32, UINT8) =
                *(void (**)(void *, s32, s32, UINT8))(entry + 0x554);
            callback(context, result, 0, status);
        }
    }
    lbl_803C0F78[0x564] = 4;
}

void fn_8007D4C4(void) {
    extern u32 lbl_802EEBF8[];
    u8 *dst = lbl_803C0F78;
    u32 *src = lbl_802EEBF8;

    *(u16 *)(dst + 0x18F6) = 0xFFFF;
    *(u32 *)(dst + 0x18F8) = *src++;
    *(u32 *)(dst + 0x18FC) = *src++;
    *(u32 *)(dst + 0x1900) = *src++;
    *(u32 *)(dst + 0x1904) = *src++;
    dst[0x1909] = 2;
}

void btm_sco_conn_req(BD_ADDR bda, DEV_CLASS dev_class, UINT8 link_type)
{
    tSCO_CB *p_sco = &btm_cb.sco_cb;
    tSCO_CONN *p = &p_sco->sco_db[0];
    UINT16 xx;
    tBTM_ESCO_CONN_REQ_EVT_DATA evt_data;
    for (xx = 0; xx < BTM_MAX_SCO_LINKS; xx++, p++) {
        if (((p->state == 1 && p->rem_bd_known) || p->state == 3) && !memcmp(p->esco.data.bd_addr, bda, BD_ADDR_LEN)) {
            p->rem_bd_known = TRUE; p->esco.data.link_type = link_type; p->state = 2;
            memcpy(p->esco.data.bd_addr, bda, BD_ADDR_LEN);
            if (!p->esco.p_esco_cback) {
                if ((link_type == BTM_LINK_TYPE_ESCO && !(p_sco->def_esco_parms.packet_types & BTM_ESCO_LINK_ONLY_MASK) &&
                     ((p_sco->def_esco_parms.packet_types & BTM_SCO_EXCEPTION_PKTS_MASK) == BTM_SCO_EXCEPTION_PKTS_MASK)) ||
                    (link_type == BTM_LINK_TYPE_SCO && !(p_sco->def_esco_parms.packet_types & BTM_SCO_LINK_ONLY_MASK)))
                    btm_esco_conn_rsp(xx, HCI_ERR_HOST_REJECT_RESOURCES, bda, NULL);
                else btm_esco_conn_rsp(xx, HCI_SUCCESS, bda, NULL);
            } else {
                memcpy(evt_data.bd_addr, bda, BD_ADDR_LEN); memcpy(evt_data.dev_class, dev_class, DEV_CLASS_LEN);
                evt_data.link_type = link_type; evt_data.sco_inx = xx;
                p->esco.p_esco_cback(BTM_ESCO_CONN_REQ_EVT, (tBTM_ESCO_EVT_DATA *)&evt_data);
            }
            return;
        }
    }
    if (p_sco->app_sco_ind_cb) {
        for (xx = 0, p = &p_sco->sco_db[0]; xx < BTM_MAX_SCO_LINKS; xx++, p++) {
            if (p->state == 0) {
                p->is_orig = FALSE; p->state = 1; p->esco.data.link_type = link_type;
                memcpy(p->esco.data.bd_addr, bda, BD_ADDR_LEN); p->rem_bd_known = TRUE; break;
            }
        }
        if (xx < BTM_MAX_SCO_LINKS) { p_sco->app_sco_ind_cb(xx); return; }
    }
    if (lbl_803C0F78[0x27c0] >= 2) fn_8007093C(0xD0001, lbl_8031669C);
    btm_esco_conn_rsp(BTM_MAX_SCO_LINKS, HCI_ERR_HOST_REJECT_RESOURCES, bda, NULL);
}

void btm_sco_connected(u8 status, u8 *addr, u16 handle, tBTM_ESCO_DATA *params) {
    u8 *cb=lbl_803C0F78+0x1854;
    u8 change=0; u16 index=0;
    *(u16*)(lbl_803C0F78+0x18F6)=status;
    for(;;) {
        u16 state=*(u16*)(cb+8);
        if((u16)(state+0xFFFF)<=2 && cb[0xD] && (addr==0||memcmp(cb+0x28,addr,6)==0)) {
            if(status) {
                if(state==3) {
                    if(status!=0x23) { *(u16*)(cb+8)=0; ((void(*)(u16))*(u32*)(cb+4))(index); }
                } else *(u16*)(cb+8)=1;
            } else {
                if(state==1) change=1;
                *(u16*)(cb+8)=4; *(u16*)(cb+0xA)=handle;
                if(lbl_803C0F78[0x1908]==0) {
                    u16 sp8, spa; u8 spc;
                    cb[0x2E]=0;
                    if(change) {
                        spa=*(u16*)(cb+0x20); sp8=*(u16*)(cb+0x1C); spc=cb[0x22];
                        BTM_ChangeEScoLinkParms(index,(tBTM_CHG_ESCO_PARAMS*)&sp8);
                    }
                } else if(params) {
                    u16 *p=(u16*)params;
                    *(u16*)(cb+0x24)=p[0]; *(u16*)(cb+0x26)=p[1];
                    *(u16*)(cb+0x28)=p[2]; *(u16*)(cb+0x2A)=p[3];
                    *(u16*)(cb+0x2C)=p[4]; *(u16*)(cb+0x2E)=p[5];
                    *(u16*)(cb+0x30)=p[6];
                }
                ((void(*)(u16))*(u32*)cb)(index);
            }
            return;
        }
        index++; cb+=0x34; if(index>=3)return;
    }
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

void btm_sco_removed(u16 handle, u8 packet_types) {
    u8 count = 0;
    u8 *p;
    s32 i;
    u16 state;
    *(u16 *)(lbl_803C0F78 + 0x18F6) = packet_types;
    state = *(u16 *)(lbl_803C0F78 + 0x185C);
    if ((s16)state < 7) { if ((s16)state >= 2) count = 1; }
    state = *(u16 *)(lbl_803C0F78 + 0x1890);
    if ((s16)state < 7) { if ((s16)state >= 2) count++; }
    state = *(u16 *)(lbl_803C0F78 + 0x18C4);
    if ((s16)state < 7) { if ((s16)state >= 2) count++; }
    if (count <= 1) btm_chg_all_acl_pkt_types(FALSE);
    p = lbl_803C0F78 + 0x1854;
    for (i = 0; i < 3; i++, p += 0x34) {
        state = *(u16 *)(p + 8);
        if (state && state != 1 && *(u16 *)(p + 0xA) == handle) {
            *(u16 *)(p + 8) = 0;
            *(u16 *)(p + 0xA) = 0xFFFF;
            p[0xD] = 0;
            *(u32 *)(p + 0x10) = 0;
            ((void (*)(u16))*(u32 *)(p + 4))(i);
            break;
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
    BT_HDR *p_buf;

    GKI_update_timer_list(&p_cb->timer_queue, p_cb->period);

    while (p_cb->timer_queue.p_first != NULL && p_cb->timer_queue.p_first->ticks <= 0) {
        p_entry = p_cb->timer_queue.p_first;
        GKI_remove_from_timer_list(&p_cb->timer_queue, p_entry);
        if (p_entry->p_cback != NULL) {
            p_entry->p_cback(p_entry);
        } else if (p_entry->event != 0) {
            p_buf = (BT_HDR *)GKI_getbuf(sizeof(BT_HDR));
            if (p_buf != NULL) {
                p_buf->event = p_entry->event;
                fn_80071450(p_buf);
            }
        }
    }

    if (p_cb->timer_queue.p_first == NULL)
        GKI_stop_timer(p_cb->timer_id);
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

/* Match note: preserving the caller's scalar timer entry and forwarding it to GKI reproduces the original calls. */
void fn_800716B0(void *p_queue, s32 p_tle, void *arg2) {
    GKI_remove_from_timer_list(p_queue, (TIMER_LIST_ENT *)p_tle);
    if (*(s32 *)p_queue == 0) {
        GKI_stop_timer(((u8 *)p_queue)[0x10]);
    }
}

void fn_800716F0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        GKI_freebuf(buf);
        *(void **)arg0 = NULL;
    }
}

extern tBTM_APPL_INFO lbl_802EEA20;
extern void bta_dm_compress_cback(s32, u8, u8, s32);
extern void fn_80089E3C(void);
void bta_dm_enable(void *arg0) {
    u8 dev_class[3];

    memset(lbl_803C0B98, 0, 0x7C);
    memset(lbl_803C0D18, 0, 0x2E);
    memcpy(dev_class, lbl_802EE8F0, 3);
    BTM_SetDeviceClass(dev_class);
    *(u32 *)(lbl_803C0C14 + 0x50) = *(u32 *)((u8 *)arg0 + 8);
    BTM_SecRegister((tBTM_APPL_INFO *)&lbl_802EEA20);
    ((void (*)(u16))fn_80077C94)(*(u16 *)(lbl_802EE8F0 + 8));
    BTM_WritePageTimeout(*(u16 *)(lbl_802EE8F0 + 6));
    ((void (*)(u16))fn_800778C8)(*(u16 *)(lbl_802EE8F0 + 4));
    fn_80078310((s32)bta_dm_acl_change_cback);
    fn_8007A240((void (*)(void *, void *))fn_8007301C);
    fn_80071078((s32)bta_dm_rm_cback);
    fn_80071088((s32)bta_dm_compress_cback);
    fn_8007403C();
    memset(lbl_803C0B68, 0, 0x2D);
    fn_80071088((s32)bta_dm_compress_cback);
    ((void (*)(void *, u32))fn_80089E3C)(bta_dm_l2cap_server_compress_cback, 0);
    WBT_ExtCreateRecord();
}

extern const BD_ADDR BT_BD_ANY;
void bta_dm_disable(void) {
    extern void bta_dm_disable_timer_cback(void);
    extern void bta_sys_disable(void);

    L2CA_SetIdleTimeoutByBdAddr((UINT8 *)BT_BD_ANY, 0);
    bta_sys_disable();
    BTM_SetDiscoverability(0, 0, 0);
    BTM_SetConnectability(0, 0, 0);
    fn_800740A4();

    if (BTM_GetNumAclLinks() == 0) {
        *(void (**)(void))(lbl_803C0C14 + 0x7C) = fn_80073464;
        fn_8007146C((s32)(lbl_803C0C14 + 0x74), 0, 0x3E8);
        return;
    }

    lbl_803C0C14[0x72] = 1;
    *(void (**)(void))(lbl_803C0C14 + 0x7C) = bta_dm_disable_timer_cback;
    fn_8007146C((s32)(lbl_803C0C14 + 0x74), 0, 0x1388);
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

void bta_dm_bond(u8 *arg0)
{
    u32 sp8[2];
    void *ptr = (void *)fn_8008128C(arg0 + 8);
    if (ptr != 0) {
        memcpy(sp8, ptr, 8);
    } else {
        memset(sp8, 0, 8);
    }
    BTM_SecBond(arg0 + 8, arg0[0xE], arg0 + 0xF, sp8);
}

void bta_dm_pin_reply(u8 *arg0) {
    u32 sp8[2];
    void *ptr = (void *)fn_8008128C(arg0 + 8);
    if (ptr != 0) {
        memcpy(sp8, ptr, 8);
    } else {
        memset(sp8, 0, 8);
    }
    if (arg0[0xE]) {
        BTM_PINCodeReply(arg0 + 8, 0, arg0[0xF], arg0 + 0x10, sp8);
    } else {
        BTM_PINCodeReply(arg0 + 8, 0xB, 0, 0, sp8);
    }
}

void bta_dm_auth_reply(u8 *arg0) {
    u32 trusted_mask[2];
    u32 service_id;
    u32 word_index;
    u32 *p;
    p = (u32 *)fn_8008128C(arg0 + 8);
    if (p != 0) {
        memcpy(trusted_mask, p, 8);
    } else {
        memset(trusted_mask, 0, 8);
    }
    if (arg0[0xF] != 2) {
        if (arg0[0xF] == 0) {
            u8 index = arg0[0xE];
            if (index <= 0x17) {
                service_id = lbl_802EE9C0[index];
                word_index = (service_id >> 3) & 0x3FC;
                *(u32 *)((u8 *)trusted_mask + word_index) |= 1 << (service_id - (service_id & 0x1FE0));
            }
        }
        BTM_DeviceAuthorized(arg0 + 8, 0, trusted_mask);
    } else {
        BTM_DeviceAuthorized(arg0 + 8, 0xB, trusted_mask);
    }
}

extern void bta_dm_inq_results_cb(u8 *);
extern void fn_80072A98(void *);
void bta_dm_search_start(void *arg0) {
    BTM_ClearInqDb(0);
    *(u32 *)lbl_803C0B98 = *(u32 *)((u8 *)arg0 + 0x18);
    *(u32 *)(lbl_803C0B98 + 8) = *(u32 *)((u8 *)arg0 + 0x14);
    BTM_StartInquiry((tBTM_INQ_PARMS *)((u8 *)arg0 + 8),
                     (tBTM_INQ_RESULTS_CB *)bta_dm_inq_results_cb,
                     (tBTM_CMPL_CB *)fn_80072A98);
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

void bta_dm_rmt_name(s32 arg0) {
    extern unsigned char lbl_803C0B98[];
    extern unsigned char lbl_803C0F78[];
    extern void bta_dm_remname_cback(u8 *);
    unsigned char sp8[8];
    s8 spE;
    s32 sp108;
    s32 retry = 1;
    void *entry;
    void *buf;
    void (*callback)(s32, void *);
    do {
        entry = BTM_InqDbNext(*(void **)(lbl_803C0B98 + 4));
        *(void **)(lbl_803C0B98 + 4) = entry;
        if (entry == 0) break;
        if (*((u8 *)entry + 0x10) != 0) {
            fn_80070FA4(sp8, (u8 *)entry + 2);
            spE = 0; sp108 = 0;
            callback = *(void (**)(s32, void *))lbl_803C0B98;
            callback(2, sp8);
            continue;
        }
        break;
    } while (1);
    if (*(u16 *)(lbl_803C0F78 + 0x64C) < 0x7530)
        fn_8007146C((s32)(lbl_803C0B98 + 0x58), 0x205, *(u16 *)(lbl_803C0F78 + 0x64C) + 0x64);
    if (BTM_ReadRemoteDeviceName((u8 *)*(void **)(lbl_803C0B98 + 4) + 2, (tBTM_CMPL_CB *)bta_dm_remname_cback) == 1) {
        retry = 0;
    } else {
        fn_8007148C((s32)(lbl_803C0B98 + 0x58));
        buf = GKI_getbuf(0x110);
        if (buf != 0) {
            fn_80070FA4((u8 *)buf + 8, (u8 *)*(void **)(lbl_803C0B98 + 4) + 2);
            *((u8 *)buf + 0xE) = 0;
            *(u16 *)buf = 0x204;
            fn_80071450(buf);
        }
        retry = 0;
    }
    if (retry != 0) {
        buf = GKI_getbuf(0x110);
        if (buf != 0) {
            *(u16 *)buf = 0x207;
            fn_80071450(buf);
        }
    }
    callback = *(void (**)(s32, void *))lbl_803C0B98;
    callback(2, (void *)(arg0 + 8));
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
void bta_dm_discover_next_device(void);
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

void bta_dm_discover_next_device(void) {
    u8 *search = lbl_803C0B98;
    extern void fn_80072AE4(u8 *, u8 *, u8 *);
    *(void **)(search + 4) = BTM_InqDbNext(*(void **)(search + 4));
    if (*(void **)(search + 4) != 0) {
        if (BTM_IsAclConnectionUp((u8 *)*(void **)(search + 4) + 2)) search[0x78] = 0;
        else search[0x78] = 1;
        {
            u8 *current = lbl_803C0B98;
            u32 zero = 0;
            current[0x79] = zero;
            BTM_SecAddRmtNameNotifyCallback(fn_80072AE4);
            {
                u32 value = *(u32 *)(current + 8);
                current[0x70] = zero;
                *(u32 *)(current + 0x10) = zero;
                current[0x20] = zero;
                *(u32 *)(current + 0xC) = value;
            }
            fn_80070FA4(current + 0x1A, (u8 *)*(void **)(current + 4) + 2);
            bta_dm_find_services((u8 *)*(void **)(current + 4) + 2);
        }
    } else {
        *(u32 *)(search + 8) = 0;
        {
            void *msg = GKI_getbuf(0x110);
            if (msg != 0) {
                *(u16 *)msg = 0x207;
                fn_80071450(msg);
            }
        }
    }
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

extern u8 lbl_80316834[];
void btm_esco_proc_conn_chg(UINT8 status, UINT16 handle, UINT8 tx_interval, UINT8 retrans_window, UINT16 rx_pkt_len, UINT16 tx_pkt_len) {
    u8 *p = lbl_803C0F78 + 0x1854;
    u8 data[16];
    UINT16 i;
    if (lbl_803C0F78[0x27C0] >= 4) fn_8007096C(0xD0003, lbl_80316834, handle, status);
    for (i = 0; i < 3; i++, p += 0x34) {
        if (*(UINT16 *)(p + 8) == 4 && handle == *(UINT16 *)(p + 0xA)) {
            if (*(u32 *)(p + 0x10) != 0) {
                memcpy(data + 6, p + 0x28, 6);
                *(UINT16 *)(p + 0x24) = rx_pkt_len;
                *(UINT16 *)(p + 0x26) = tx_pkt_len;
                p[0x2F] = tx_interval;
                p[0x30] = retrans_window;
                data[12] = status;
                *(UINT16 *)(data) = i;
                *(UINT16 *)(data + 2) = rx_pkt_len;
                *(UINT16 *)(data + 4) = tx_pkt_len;
                data[13] = tx_interval;
                data[14] = retrans_window;
                ((void (*)(u32, void *))*(u32 *)(p + 0x10))(1, data);
            }
            return;
        }
    }
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
    unsigned char *base = lbl_803C0F78;
    int count = 0;
    int state;
    state = *(unsigned short *)(base + 0x185c);
    if (state < 7) {
        if (state >= 2)
            count = 1;
    }
    state = *(unsigned short *)(base + 0x1890);
    if (state < 7) {
        if (state >= 2)
            count++;
    }
    state = *(unsigned short *)(base + 0x18c4);
    if (state >= 7)
        return count;
    if (state >= 2)
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

BOOLEAN BTM_SecRegister(tBTM_APPL_INFO *arg0) {
    volatile u32 *dest = (volatile u32 *)(lbl_803C0F78 + 0x190C);
    volatile u32 *src = (volatile u32 *)arg0;
    u32 first = src[0];
    u32 second = src[1];
    u8 level = lbl_803C0F78[0x27C0];
    u32 third;
    u32 fourth;
    u32 fifth;
    u32 sixth;

    dest[0] = first;
    dest[1] = second;
    third = src[2];
    fourth = src[3];
    dest[2] = third;
    dest[3] = fourth;
    fifth = src[4];
    sixth = src[5];
    dest[4] = fifth;
    dest[5] = sixth;
    if (level >= 4)
        fn_8007093C(0xD0003, lbl_80316870);
    return TRUE;
}

BOOLEAN BTM_SecAddRmtNameNotifyCallback(tBTM_RMT_NAME_CALLBACK *p_callback) {
    u8 *base = lbl_803C0F78;
    int i;

    for (i = 0; i < BTM_SEC_MAX_RMT_NAME_CALLBACKS; i++) {
        if (*(tBTM_RMT_NAME_CALLBACK **)(base + 0x192C) == NULL) {
            *(tBTM_RMT_NAME_CALLBACK **)(lbl_803C0F78 + i * 4 + 0x192C) = p_callback;
            return TRUE;
        }
        base += 4;
    }

    return FALSE;
}

BOOLEAN BTM_SecDeleteRmtNameNotifyCallback(tBTM_RMT_NAME_CALLBACK *p_callback) {
    u8 *base = lbl_803C0F78;
    int i;

    for (i = 0; i < BTM_SEC_MAX_RMT_NAME_CALLBACKS; i++) {
        if (*(tBTM_RMT_NAME_CALLBACK **)(base + 0x192C) == p_callback) {
            *(tBTM_RMT_NAME_CALLBACK **)(lbl_803C0F78 + i * 4 + 0x192C) = NULL;
            return TRUE;
        }
        base += 4;
    }

    return FALSE;
}

extern char lbl_80316908[];
void BTM_SetPinType(UINT8 pin_type, PIN_CODE pin_code, UINT8 pin_code_len) {
    if (lbl_803C0F78[0x27C0] >= 3) {
        ((void (*)(u32, void *, UINT8, PIN_CODE_PTR, UINT8))fn_80070984)(
            0xD0002, lbl_80316908, pin_type, pin_code, pin_code_len);
    }
    if (lbl_803C0F78[0x64E] > 1) {
        btsnd_hcic_write_pin_type(pin_type);
    }
    lbl_803C0F78[0x20] = pin_type;
    lbl_803C0F78[0x21] = pin_code_len;
    memcpy(&lbl_803C0F78[0x22], pin_code, pin_code_len);
}

BOOLEAN BTM_SetSecurityLevel(BOOLEAN is_originator, char *p_name, UINT8 service_id, UINT16 sec_level, UINT16 psm, UINT32 mx_proto_id, UINT32 mx_chan_id) {
    char *trace = lbl_80316870;
    u8 *entry = lbl_803C0F78 + 0x1990;
    u16 index = 0;
    u16 first_free = 0xFFFF;
    BOOLEAN found = FALSE;

    for (; index < 0x18; index++, entry += 0x3C) {
        if (entry[0xE] & 0x80) {
            if (*(u16 *)(entry + 0xC) == psm &&
                *(u32 *)(entry + 0x0) == mx_proto_id &&
                entry[0xF] == service_id &&
                (strncmp(p_name, (char *)(entry + 0x10), 0x15) == 0 ||
                 strncmp(p_name, (char *)(entry + 0x26), 0x15) == 0)) {
                found = TRUE;
                break;
            }
        } else if (!found) {
            found = TRUE;
            first_free = index;
        }
    }
    if (found) {
        if (index >= 0x18) {
            index = first_free;
            entry = lbl_803C0F78 + 0x1990 + index * 0x3C;
        }
        *(u16 *)(entry + 0xC) = psm;
        entry[0xF] = service_id;
        *(u32 *)(entry + 0x0) = mx_proto_id;
        if (is_originator) {
            *(u32 *)(entry + 0x4) = mx_chan_id;
            entry[0xE] &= 0xC7;
            strncpy((char *)(entry + 0x10), p_name, 0x15);
        } else {
            *(u32 *)(entry + 0x8) = mx_chan_id;
            entry[0xE] &= 0xF8;
            strncpy((char *)(entry + 0x26), p_name, 0x15);
        }
        entry[0xE] |= sec_level | 0x80;
        if (lbl_803C0F78[0x27C0] >= 3) {
            ((void (*)(u32, void *, s32, u32, u32, u32, u32, u32))fn_800709CC)(
                0xD0002, trace + 0xE0, index, service_id, is_originator, psm, mx_proto_id, mx_chan_id);
        }
        if (lbl_803C0F78[0x27C0] >= 3) {
            ((void (*)(u32, void *, u8, char *, u32))fn_80070984)(
                0xD0002, trace + 0x128, entry[0xE], p_name, 0x15);
        }
    } else if (lbl_803C0F78[0x27C0] >= 2) {
        fn_80070954(0xD0001, trace + 0x170, 0x18);
    }
    return found;
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

tBTM_STATUS BTM_SecBond(BD_ADDR bd_addr, UINT8 pin_len, UINT8 *p_pin, UINT32 trusted_mask[]) {
    tBTM_SEC_DEV_REC *p_dev_rec;
    tBTM_INQ_INFO *p_inq_info;
    UINT8 pin_type;
    UINT8 allow_switch;
    register char *message_table = lbl_80316870;
    register UINT8 *dev;
    register UINT8 *p_pin_copy = p_pin;
    register UINT32 *trusted_mask_copy = trusted_mask;

    if (lbl_803C0F78[0x27C0] >= 3) {
        fn_800709CC(0xD0002, message_table + 0x230,
                    bd_addr[0], bd_addr[1], bd_addr[2],
                    bd_addr[3], bd_addr[4], bd_addr[5]);
    }

    if (pin_len > 0x10) {
        if (lbl_803C0F78[0x27C0] >= 1) {
            fn_80070954(0xD0000, message_table + 0x260, pin_len);
        }
        return BTM_ILLEGAL_VALUE;
    }

    p_dev_rec = btm_find_dev(bd_addr);
    dev = (UINT8 *)p_dev_rec;
    if (dev == NULL) {
        p_dev_rec = btm_sec_alloc_dev(bd_addr);
        dev = (UINT8 *)p_dev_rec;
        if (dev == NULL) {
            if (lbl_803C0F78[0x27C0] >= 1) {
                fn_8007093C(0xD0000, message_table + 0x280);
            }
            return BTM_NO_RESOURCES;
        }
    }

    if (*(UINT16 *)(dev + 0x18) != 0xFFFF && (dev[0x76] & 2)) {
        if (lbl_803C0F78[0x27C0] >= 2) {
            fn_8007093C(0xD0001, message_table + 0x2A0);
        }
        return BTM_SUCCESS;
    }

    if (BTM_DeleteStoredLinkKey(bd_addr, NULL) != BTM_SUCCESS) {
        return BTM_NO_RESOURCES;
    }

    dev[0x81] = 0x50;
    dev[0x80] = 1;
    *(UINT32 *)(dev + 0x10) = trusted_mask_copy[0];
    *(UINT32 *)(dev + 0x14) = trusted_mask_copy[1];
    lbl_803C0F78[0x197F] = pin_len;
    if (pin_len != 0) {
        memcpy(lbl_803C0F78 + 0x1980, p_pin_copy, pin_len);
    }

    dev[0x76] &= ~0x16;
    if ((dev[0x23] & 0x1F) == 5 &&
        (dev[0x24] & 0x40) &&
        lbl_803C0F78[0x20] != 1) {
        lbl_803C0F78[0x197C] = 1;
        btsnd_hcic_write_pin_type(1);
    }

    lbl_803C0F78[0x197E] = 0;
    if (*(UINT16 *)(dev + 0x18) != 0xFFFF) {
        dev[0x76] &= ~0x10;
        dev[0x7F] = 1;
        if (!btsnd_hcic_auth_request(*(UINT16 *)(dev + 0x18))) {
            return BTM_NO_RESOURCES;
        }
        lbl_803C0F78[0x197D] = 0;
        return BTM_CMD_STARTED;
    }

    if (lbl_803C0F78[0x1978] != 3) {
        if (lbl_803C0F78[0x27C0] >= 5) {
            fn_8007093C(0xD0004, message_table + 0x2C0);
        }
        if ((UINT8)btsnd_hcic_write_pin_type_8008543C(1) == 0) {
            if (lbl_803C0F78[0x27C0] >= 1) {
                fn_8007093C(0xD0000, message_table + 0x2E4);
            }
            return BTM_NO_RESOURCES;
        }
        lbl_803C0F78[0x197B] = 1;
    }

    lbl_803C0F78[0x197D] = 1;
    pin_type = *(UINT8 *)fn_8007A3A4();
    dev[0x85] = 0;
    allow_switch = (pin_type >> 5) & 1;
    p_inq_info = BTM_InqDbRead(bd_addr);
    if (p_inq_info != NULL) {
        pin_type = btsnd_hcic_create_conn(
            bd_addr, 0x18, p_inq_info->results.page_scan_rep_mode,
            p_inq_info->results.page_scan_mode,
            p_inq_info->results.clock_offset | 0x8000, allow_switch);
    } else {
        pin_type = btsnd_hcic_create_conn(
            bd_addr, 0x18, 1, 0, *(UINT16 *)(dev + 0x1A), allow_switch);
    }
    if (pin_type != 0) {
        return BTM_CMD_STARTED;
    }

    if (lbl_803C0F78[0x27C0] >= 1) {
        fn_8007093C(0xD0000, message_table + 0x2E4);
    }
    if (lbl_803C0F78[0x197B] != 0) {
        lbl_803C0F78[0x197B] = 0;
        if (lbl_803C0F78[0x27C0] >= 5) {
            ((void (*)(u32, void *, u32))fn_80070954)(
                0xD0004, message_table + 0x2FC,
                ((lbl_803C0F78[0x1978] - 3) == 0));
        }
        btsnd_hcic_write_pin_type_8008543C(
            (UINT8)((lbl_803C0F78[0x1978] - 3) == 0));
    }
    return BTM_NO_RESOURCES;
}

tBTM_STATUS btm_sec_l2cap_access_req(BD_ADDR bd_addr, UINT16 psm, UINT16 handle,
                                       CONNECTION_TYPE conn_type,
                                       tBTM_SEC_CALLBACK *p_callback,
                                       void *p_ref_data) {
    tBTM_SEC_DEV_REC *p_dev_rec;
    register u8 *p_serv;
    register u8 *p_next;
    u8 *dev;
    register u8 *messages = (u8 *)lbl_80316870;
    register UINT32 i;
    register UINT32 j;
    register UINT8 sec_flags;
    register UINT8 found_current;
    UINT8 rc;

    p_dev_rec = btm_find_dev(bd_addr);
    if (p_dev_rec == NULL) {
        p_dev_rec = btm_sec_alloc_dev(bd_addr);
        if (p_dev_rec == NULL) {
            if (lbl_803C0F78[0x27C0] >= 2)
                fn_80070954(0xD0001, messages + 0x410, psm);
            if (p_callback != NULL)
                (*p_callback)(bd_addr, NULL, 3);
            return 3;
        }
    }
    dev = (u8 *)p_dev_rec;
    *(UINT16 *)(dev + 0x18) = handle;

    p_serv = lbl_803C0F78 + 0x1990;
    for (i = 0; i < 20; i += 5) {
        if ((p_serv[0xE] & 0x80) && *(UINT16 *)(p_serv + 0xC) == psm) {
            break;
        } else {
            sec_flags = p_serv[0x4A];
            p_serv += 0x3C;
            if ((sec_flags & 0x80) && *(UINT16 *)(p_serv + 0xC) == psm) {
                break;
            } else {
            sec_flags = p_serv[0x4A];
            p_serv += 0x3C;
            if ((sec_flags & 0x80) && *(UINT16 *)(p_serv + 0xC) == psm) {
                break;
            } else {
            sec_flags = p_serv[0x4A];
            p_serv += 0x3C;
            if ((sec_flags & 0x80) && *(UINT16 *)(p_serv + 0xC) == psm) {
                break;
            } else {
            sec_flags = p_serv[0x4A];
            p_serv += 0x3C;
            if ((sec_flags & 0x80) && *(UINT16 *)(p_serv + 0xC) == psm) {
                break;
            } else {
            sec_flags = p_serv[0x4A];
            p_serv += 0x3C;
            if ((sec_flags & 0x80) && *(UINT16 *)(p_serv + 0xC) == psm) {
                break;
            } else {
                p_serv += 0x3C;
            }
            }
            }
            }
            }
        }
    }
    if (i == 20)
        p_serv = NULL;
    if (p_serv == NULL) {
        if (lbl_803C0F78[0x27C0] >= 2)
            fn_80070954(0xD0001, messages + 0x448, psm);
        if (p_callback != NULL)
            (*p_callback)(bd_addr, NULL, 4);
        return 4;
    }

    if (conn_type == 0 || p_dev_rec->p_cur_service == NULL)
        p_dev_rec->p_cur_service = (tBTM_SEC_SERV_REC *)p_serv;

    sec_flags = p_serv[0xE];
    p_next = lbl_803C0F78 + 0x1990;
    found_current = 0;
    for (j = 0; j < 18; j += 3) {
        if ((p_next[0xE] & 0x80) == 0)
            goto next_service_1;
        if (*(UINT16 *)(p_next + 0xC) != *(UINT16 *)(p_serv + 0xC))
            goto next_service_1;
        if (found_current)
            goto scan_early;
        if (p_next != p_serv)
            goto next_service_1;
        found_current = 1;
        goto next_service_1;
next_service_1:
        sec_flags = p_next[0x4A];
        p_next += 0x3C;
        if ((sec_flags & 0x80) == 0)
            goto next_service_2;
        if (*(UINT16 *)(p_next + 0xC) != *(UINT16 *)(p_serv + 0xC))
            goto next_service_2;
        if (found_current)
            goto scan_early;
        if (p_next != p_serv)
            goto next_service_2;
        found_current = 1;
        goto next_service_2;
next_service_2:
        sec_flags = p_next[0x4A];
        p_next += 0x3C;
        if ((sec_flags & 0x80) == 0)
            goto next_service_3;
        if (*(UINT16 *)(p_next + 0xC) != *(UINT16 *)(p_serv + 0xC))
            goto next_service_3;
        if (found_current)
            goto scan_early;
        if (p_next != p_serv)
            goto next_service_3;
        found_current = 1;
        goto next_service_3;
next_service_3:
        sec_flags = p_next[0x4A];
        p_next += 0x3C;
        if ((sec_flags & 0x80) == 0)
            goto next_service_4;
        if (*(UINT16 *)(p_next + 0xC) != *(UINT16 *)(p_serv + 0xC))
            goto next_service_4;
        if (found_current)
            goto scan_early;
        if (p_next != p_serv)
            goto next_service_4;
        found_current = 1;
        goto next_service_4;
next_service_4:
        p_next += 0x3C;
    }
    p_next = NULL;
scan_early:
    if (p_next != NULL) {
        if (lbl_803C0F78[0x27C0] >= 4)
            fn_80070954(0xD0003, messages + 0x48C, psm);
        if (p_callback != NULL)
            (*p_callback)(bd_addr, NULL, 0);
        return 0;
    }

    p_dev_rec->p_callback = p_callback;
    p_dev_rec->p_ref_data = NULL;
    dev[0x81] = sec_flags;
    dev[0x80] = conn_type;
    if (lbl_803C0F78[0x27C0] >= 4) {
        ((void (*)(UINT32, void *, UINT32, UINT16, UINT8, UINT8, UINT8))fn_800709B4)(
            0xD0003, messages + 0x4D0, psm, handle, dev[0x7F], dev[0x76], sec_flags);
    }
    if (conn_type == 0 && (sec_flags & 1)) {
        dev[0x76] &= ~1;
        if (lbl_803C0F78[0x27C0] >= 4) {
            ((void (*)(UINT32, void *, UINT32, UINT32, UINT8))fn_80070984)(
                0xD0003, messages + 0x528,
                *(UINT32 *)(dev + 0x14), *(UINT32 *)(dev + 0x10), dev[0x76]);
        }
    }
    rc = btm_sec_execute_procedure(p_dev_rec);
    if (rc != 1 && p_callback != NULL) {
        (*p_callback)(bd_addr, p_dev_rec->p_ref_data, rc);
        p_dev_rec->p_callback = NULL;
    }
    return rc;
}

extern u8 lbl_80316DC8[];

tBTM_STATUS btm_sec_mx_access_request(BD_ADDR bd_addr, UINT16 psm, BOOLEAN is_originator,
                               UINT32 mx_proto_id, UINT32 mx_chan_id,
                               tBTM_SEC_CALLBACK *p_callback, void *p_ref_data)
{
    tBTM_SEC_DEV_REC *p_dev_rec;
    u8 *p_serv_rec;
    u8 *dev;
    u32 index;
    u8 rc;

    p_dev_rec = btm_find_dev(bd_addr);
    if (p_dev_rec == 0) {
        p_dev_rec = btm_sec_alloc_dev(bd_addr);
        if (p_dev_rec == 0) {
            if (p_callback != 0)
                (*p_callback)(bd_addr, p_ref_data, 3);
            return;
        }
    }

    p_serv_rec = lbl_803C0F78 + 0x1990;
    for (index = 0; index < 0x18; index++, p_serv_rec += 0x3C) {
        if ((p_serv_rec[0xE] & 0x80) &&
            *(u16 *)(p_serv_rec + 0xC) == psm &&
            *(u32 *)(p_serv_rec + 0x0) == mx_proto_id &&
            ((is_originator && *(u32 *)(p_serv_rec + 0x4) == mx_chan_id) ||
             (!is_originator && *(u32 *)(p_serv_rec + 0x8) == mx_chan_id))) {
            goto found;
        }
    }
    p_serv_rec = 0;

found:
    if (p_serv_rec == 0) {
        if (p_callback != 0)
            (*p_callback)(bd_addr, p_ref_data, 4);
        if (lbl_803C0F78[0x27C0] >= 1)
            ((void (*)(u32, void *, u32, u32, u32))fn_80070984)(0xD0000, lbl_80316DC8, psm, mx_proto_id, mx_chan_id);
        return;
    }

    dev = (u8 *)p_dev_rec;
    *(u8 **)dev = p_serv_rec;
    dev[0x81] = p_serv_rec[0xE];
    dev[0x80] = is_originator;
    *(tBTM_SEC_CALLBACK **)(dev + 4) = p_callback;
    *(void **)(dev + 8) = p_ref_data;
    dev[0x76] &= ~0x01;

    rc = btm_sec_execute_procedure(p_dev_rec);
    if (rc != 1) {
        if (p_callback != 0) {
            if (dev[0x80] != 0) {
                u8 *p = *(u8 **)dev;
                if (p != 0 && *(u32 *)p == 3)
                    *(u32 *)(p + 4) = 0;
            }
            (*p_callback)(bd_addr, p_ref_data, rc);
            *(u32 *)(dev + 4) = 0;
        }
    }
}

void btm_sec_conn_req(u8 *bd_addr, u8 *dev_class) {
    u8 *dev;
    void *buf;
    u8 *base;
    u8 (*callback)(u8 *, u8 *);
    if (lbl_803C0F78[0x197A] != 0 &&
        ((dev = (u8 *)btm_find_dev(bd_addr)) == 0 || (dev[0x76] & 0x10) == 0)) {
        if (lbl_803C0F78[0x27C0] >= 4)
            fn_8007093C(0xD0003, lbl_80316E08);
        buf = GKI_getpoolbuf(2);
        if (buf != 0) ((void (*)(void *, u8 *, u8))btsnd_hcic_reject_conn)(buf, bd_addr, 0xF);
        return;
    }
    callback = *(u8 (**)(u8 *, u8 *))(lbl_803C0F78 + 0x1934);
    if (callback != 0 && callback(bd_addr, dev_class) == 0) {
        buf = GKI_getpoolbuf(2);
        if (buf != 0) ((void (*)(void *, u8 *, u8))btsnd_hcic_reject_conn)(buf, bd_addr, 0xF);
        return;
    }
    base = lbl_803C0F78;
    memcpy(base + 0x27B4, bd_addr, 6);
    memcpy(base + 0x27BA, dev_class, 3);
    l2c_link_hci_conn_req(bd_addr);
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

extern char lbl_80316E44[];
void btm_sec_rmt_name_request_complete(UINT8 *p_bd_addr, UINT8 *p_bd_name, UINT8 status)
{
    UINT8 *p_dev_rec;
    int i;
    int j;
    UINT8 *p;
    UINT8 state;
    UINT8 result;
    void (*name_cb)(void *, void *, void *);
    void (*security_cb)(void *, void *, void *, void *, UINT8);
    void (*complete_cb)(void *, void *, UINT8);

    if (p_bd_addr) {
        p_dev_rec = (UINT8 *)btm_find_dev(p_bd_addr);
    } else {
        p_dev_rec = (UINT8 *)lbl_803C0F78 + 0x1F30;
        for (i = 0; i < 0x10; i++, p_dev_rec += 0x88) {
            if (!(p_dev_rec[0x76] & 0x80))
                continue;
            if (p_dev_rec[0x7F] == 3)
                break;
        }
        if (i == 0x10)
            p_dev_rec = NULL;
    }

    if (lbl_803C0F78[0x27C0] >= 4)
        fn_8007096C(0xD0003, lbl_80316E44, status,
                    p_dev_rec ? p_dev_rec[0x7F] : 0);

    if (!p_dev_rec)
        return;

    if (status == 0) {
        memcpy(p_dev_rec + 0x35, p_bd_name, 0x40);
        p_dev_rec[0x76] |= 8;
        p = (UINT8 *)lbl_803C0F78;
        for (j = 0; j < 2; j++, p += 4) {
            name_cb = *(void (**)(void *, void *, void *))(p + 0x192C);
            if (name_cb)
                name_cb(p_bd_addr, p_dev_rec + 0x22, p_dev_rec + 0x35);
        }
    }

    if (p_dev_rec[0x82]) {
        if ((p_dev_rec[0x81] & 0x40) && !p_dev_rec[0x85])
            return;
        p_dev_rec[0x82] = 0;
        security_cb = *(void (**)(void *, void *, void *, void *, UINT8))
                          ((UINT8 *)lbl_803C0F78 + 0x1914);
        if (security_cb)
            security_cb(p_dev_rec + 0x1C, p_dev_rec + 0x22,
                        p_dev_rec + 0x35, p_dev_rec + 0x25,
                        p_dev_rec[0x83]);
        p = (UINT8 *)lbl_803C0F78;
        for (j = 0; j < 2; j++, p += 4) {
            security_cb = *(void (**)(void *, void *, void *, void *, UINT8))(p + 0x1924);
            if (security_cb)
                security_cb(p_dev_rec + 0x1C, p_dev_rec + 0x22,
                            p_dev_rec + 0x35, p_dev_rec + 0x25,
                            p_dev_rec[0x83]);
        }
    }

    state = p_dev_rec[0x81];
    if ((state & 0x40) && (p_dev_rec[0x76] & 2)) {
        p_dev_rec[0x81] = state & ~0x50;
        btsnd_hcic_disconnect(*(UINT16 *)(p_dev_rec + 0x18), 0x13);
        return;
    }

    if (p_dev_rec[0x7F] == 3) {
        p_dev_rec[0x7F] = 0;
        if (status != 0) {
            if (*(void **)(p_dev_rec + 4)) {
                ((void (*)(void *, void *, UINT8))*(void **)(p_dev_rec + 4))(
                    p_dev_rec + 0x1C, *(void **)(p_dev_rec + 8), 0xA);
                *(void **)(p_dev_rec + 4) = NULL;
            }
            return;
        }

        result = btm_sec_execute_procedure(p_dev_rec);
        if (result != 1) {
            if (*(void **)(p_dev_rec + 4)) {
                complete_cb = (void (*)(void *, void *, UINT8))*(void **)(p_dev_rec + 4);
                complete_cb(p_dev_rec + 0x1C, *(void **)(p_dev_rec + 8), result);
                *(void **)(p_dev_rec + 4) = NULL;
            }
        }
    }
}

void btm_sec_auth_complete(register UINT16 handle, register UINT8 status) {
    extern char lbl_80316E7C[];
    extern char lbl_80316B6C[];
    extern BOOLEAN btsnd_hcic_disconnect(UINT16, UINT8);
    extern BOOLEAN btsnd_hcic_write_pin_type(UINT8);
    extern BOOL btsnd_hcic_write_pin_type_8008543C(u32);
    extern u8 btm_sec_execute_procedure(void *);
    register u8 *dev = (u8 *)btm_find_dev_by_handle(handle);
    register u8 *dev2;
    void (*auth_cb)(u8 *, u8 *, u8 *, u8);
    register void *request;
    register u8 old_state;
    register u8 reason;
    register u8 flags;
    u32 pin;

    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_8007096C(0xD0003, lbl_80316E7C, status, dev ? dev[0x7F] : 0);
    }

    if (lbl_803C0F78[0x197B] != 0) {
        lbl_803C0F78[0x197B] = 0;
        if (lbl_803C0F78[0x27C0] >= 5) {
            pin = (lbl_803C0F78[0x1978] == 3);
            ((void (*)(u32, void *, u32))fn_80070954)(0xD0004, lbl_80316B6C, pin);
        }
        btsnd_hcic_write_pin_type_8008543C((u8)(lbl_803C0F78[0x1978] == 3));
    }

    if (lbl_803C0F78[0x197C] != 0) {
        lbl_803C0F78[0x197C] = 0;
        btsnd_hcic_write_pin_type(lbl_803C0F78[0x20]);
    }

    if (dev != 0) {
        flags = dev[0x81];
        if ((flags & 0x40) != 0 && lbl_803C0F78[0x197D] == 0) {
            dev[0x81] = flags & ~0x50;
            reason = lbl_803C0F78[0x197E];
            if (reason != 0) {
                dev2 = (u8 *)btm_find_dev_by_handle(handle);
                if (dev2 != 0) {
                    if ((dev2[0x81] & 0x40) != 0) {
                        lbl_803C0F78[0x197E] = reason;
                    } else {
                        old_state = dev2[0x7F];
                        if (old_state != 5) {
                            dev2[0x7F] = 5;
                            if (!btsnd_hcic_disconnect(handle, reason))
                                dev2[0x7F] = old_state;
                        }
                    }
                }
            }
        }
    }

    if (dev != 0) {
        if (dev[0x7F] != 1) {
            auth_cb = *(void (**)(u8 *, u8 *, u8 *, u8))(lbl_803C0F78 + 0x191C);
            if (auth_cb != 0 && status != 0)
                auth_cb(dev + 0x1C, dev + 0x22, dev + 0x35, status);
        } else {
            if (status == 0x0C && (dev[0x76] & 6) == 6)
                status = 0;
            auth_cb = *(void (**)(u8 *, u8 *, u8 *, u8))(lbl_803C0F78 + 0x191C);
            if (auth_cb != 0)
                auth_cb(dev + 0x1C, dev + 0x22, dev + 0x35, status);
            handle = 0;
            dev[0x7F] = (u8)handle;
            flags = dev[0x81];
            if ((flags & 0x40) != 0) {
                dev[0x81] = flags & ~0x50;
                btsnd_hcic_disconnect(*(UINT16 *)(dev + 0x18), 0x13);
            } else if (status != 0) {
                if (*(void **)(dev + 4) != 0) {
                    if (dev[0x80] != 0) {
                        request = *(void **)dev;
                        if (request != 0 && *(u32 *)request == 3)
                            *(u32 *)((u8 *)request + 4) = handle;
                    }
                    ((void (*)(u8 *, u32, u8))*(void **)(dev + 4))(
                        dev + 0x1C, *(u32 *)(dev + 8), 0xA);
                    *(void **)(dev + 4) = 0;
                }
                btsnd_hcic_disconnect(*(UINT16 *)(dev + 0x18), 5);
            } else {
                dev[0x76] |= 2;
                status = btm_sec_execute_procedure(dev);
                if (status != 1 && *(void **)(dev + 4) != 0) {
                    if (dev[0x80] != 0) {
                        request = *(void **)dev;
                        if (request != 0 && *(u32 *)request == 3)
                            *(u32 *)((u8 *)request + 4) = handle;
                    }
                    ((void (*)(u8 *, u32, u8))*(void **)(dev + 4))(
                        dev + 0x1C, *(u32 *)(dev + 8), status);
                    *(void **)(dev + 4) = 0;
                }
            }
        }
    }
}

void btm_sec_mkey_comp_event(u16 handle, u8 status, u8 event) {
    extern char lbl_80316EB0[];
    extern u8 lbl_80560D40;
    extern u8 lbl_80560D41;
    extern u8 lbl_80560D42;
    extern u8 lbl_80560D43;
    extern u8 lbl_80560D44;
    extern u8 lbl_80560D45;
    u8 bd_addr[6];
    tBTM_SEC_DEV_REC *dev;
    void (*callback)(u8 *, u8, u8);

    dev = btm_find_dev_by_handle(handle);
    bd_addr[0] = lbl_80560D40;
    bd_addr[1] = lbl_80560D41;
    bd_addr[2] = lbl_80560D42;
    bd_addr[3] = lbl_80560D43;
    bd_addr[4] = lbl_80560D44;
    bd_addr[5] = lbl_80560D45;

    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_8007096C(0xD0003, lbl_80316EB0, status,
                    dev != 0 ? ((u8 *)dev)[0x7F] : 0);
    }

    callback = *(void (**)(u8 *, u8, u8))(lbl_803C0F78 + 0x27B0);
    if (callback != 0) {
        if (dev == 0) {
            callback(bd_addr, status, event);
        } else {
            callback((u8 *)dev + 0x1C, status, event);
        }
    }
}

/* Match note: combine the null and security-bit tests so both failures share the zero return block. */
s32 fn_8007FEFC(u16 handle) {
    tBTM_SEC_DEV_REC *dev = btm_find_dev_by_handle(handle);
    if (dev != NULL && ((((u8 *)dev)[0x81] & 0x40) != 0)) {
        return 1;
    }
    return 0;
}

extern UINT8 btm_sec_execute_procedure(void *);
extern UINT8 lbl_80316F14[];
void btm_sec_connected(UINT8 *bda, UINT16 handle, UINT8 status, UINT8 enc_mode) {
    extern char lbl_80316B6C[];
    UINT8 *dev;
    UINT8 rc;
    UINT8 *entry;
    INT32 count;
    UINT32 timestamp;

    dev = (UINT8 *)btm_find_dev(bda);
    if (lbl_803C0F78[0x27C0] >= 4)
        ((void (*)(UINT32, void *, UINT16, UINT8, UINT8))fn_80070984)(
            0xD0003, lbl_80316F14, handle, status, enc_mode);
    if (dev == NULL) {
        if (status == 0) {
            dev = (UINT8 *)btm_sec_alloc_dev(bda);
            if (dev == NULL)
                return;
        } else {
            return;
        }
    } else {
        timestamp = *(UINT32 *)(lbl_803C0F78 + 0x1974);
        *(UINT32 *)(dev + 0x0C) = timestamp;
        *(UINT32 *)(lbl_803C0F78 + 0x1974) = timestamp + 1;
        dev[0x85] = 1;
    }

    if (dev[0x81] & 0x40) {
        if (lbl_803C0F78[0x197B] != 0) {
            lbl_803C0F78[0x197B] = 0;
            if (lbl_803C0F78[0x27C0] >= 5)
                ((void (*)(UINT32, void *, UINT32))fn_80070954)(
                    0xD0004, lbl_80316B6C,
                    (lbl_803C0F78[0x1978] - 3) == 0);
            btsnd_hcic_write_pin_type_8008543C(
                (UINT8)((lbl_803C0F78[0x1978] - 3) == 0));
        }
        if (lbl_803C0F78[0x197C] != 0) {
            lbl_803C0F78[0x197C] = 0;
            btsnd_hcic_write_pin_type(lbl_803C0F78[0x20]);
        }
    }

    if (status != 0) {
        if (status == 5 || status == 6 || status == 0xE ||
            status == 0x18 || status == 0x26 || status == 0x29 ||
            status == 0x25 || status == 0x17 || status == 0x22) {
            if (dev[0x81] & 0x40) {
                *(volatile UINT8 *)(dev + 0x81) &= ~0x50;
                dev[0x76] &= ~0x10;
                if (*(UINT32 *)(lbl_803C0F78 + 0x194C) != 0) {
                    fn_80070F90(lbl_803C0F78 + 0x193C);
                    status = 0xE;
                    *(UINT32 *)(lbl_803C0F78 + 0x194C) = 0;
                }
                if (lbl_803C0F78[0x27BF] == 0xE)
                    status = 0xE;
                if (*(void (**)(void *, void *, void *, UINT32))(lbl_803C0F78 + 0x191C) != NULL)
                    (*(void (**)(void *, void *, void *, UINT32))(lbl_803C0F78 + 0x191C))(
                        dev + 0x1C, dev + 0x22, dev + 0x35, status);
                return;
            }
        }
        if (*(void (**)(void *, UINT32, UINT8))(dev + 4) != NULL) {
            if (dev[0x80] != 0) {
                void *p = *(void **)dev;
                if (p != NULL && *(UINT32 *)p == 3)
                    *(UINT32 *)((UINT8 *)p + 4) = 0;
            }
            if (status == 8 || status == 0x1F || status == 4)
                ((void (*)(void *, UINT32, UINT8))(*(void **)(dev + 4)))(
                    dev + 0x1C, *(UINT32 *)(dev + 8), 8);
            else
                ((void (*)(void *, UINT32, UINT8))(*(void **)(dev + 4)))(
                    dev + 0x1C, *(UINT32 *)(dev + 8), 0xA);
        }
        return;
    }

    if ((dev[0x81] & 0x40) && dev[0x82] != 0) {
        dev[0x82] = 0;
        if (*(void (**)(void *, void *, void *, void *, UINT8))(lbl_803C0F78 + 0x1914) != NULL)
            (*(void (**)(void *, void *, void *, void *, UINT8))(lbl_803C0F78 + 0x1914))(
                dev + 0x1C, dev + 0x22, dev + 0x35, dev + 0x25, dev[0x83]);
        entry = lbl_803C0F78;
        for (count = 0; count < 2; count++, entry += 4) {
            if (*(void (**)(void *, void *, void *, void *, UINT8))(entry + 0x1924) != NULL)
                (*(void (**)(void *, void *, void *, void *, UINT8))(entry + 0x1924))(
                    dev + 0x1C, dev + 0x22, dev + 0x35, dev + 0x25, dev[0x83]);
        }
        if (*(void (**)(void *, void *, void *, UINT32))(lbl_803C0F78 + 0x191C) != NULL)
            (*(void (**)(void *, void *, void *, UINT32))(lbl_803C0F78 + 0x191C))(
                dev + 0x1C, dev + 0x22, dev + 0x35, 0);
        rc = dev[0x81];
        dev[0x81] &= ~0x50;
        btsnd_hcic_disconnect(handle, 0x13);
        return;
    }

    *(UINT16 *)(dev + 0x18) = handle;
    dev[0x76] &= 0xF8;
    if (enc_mode != 0)
        dev[0x76] |= 6;
    if (lbl_803C0F78[0x1978] == 3)
        dev[0x76] |= 2;
    dev[0x84] = 0;
    if ((dev[0x76] & 8) != 0 && dev[0x80] == 0)
        return;
    rc = btm_sec_execute_procedure(dev);
    if (rc == 1)
        return;
    if (*(void **)(dev + 4) != NULL) {
        if (dev[0x80] != 0) {
            void *p = *(void **)dev;
            if (p != NULL && *(UINT32 *)p == 3)
                *(UINT32 *)((UINT8 *)p + 4) = 0;
        }
        ((void (*)(void *, UINT32, UINT8))(*(void **)(dev + 4)))(
            dev + 0x1C, *(UINT32 *)(dev + 8), rc);
        *(void **)(dev + 4) = NULL;
    }
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

void btm_sec_disconnected(UINT16 handle, UINT8 reason) {
    register UINT8 saved_reason = reason;
    tBTM_SEC_DEV_REC *p_dev_rec = btm_find_dev_by_handle(handle);
    if (p_dev_rec == NULL)
        return;
    if ((*(u8 *)((u8 *)p_dev_rec + 0x81) & 0x40) &&
        *(void **)(lbl_803C0F78 + 0x191C) != NULL) {
        if (saved_reason == 0x17) {
            ((void (*)(u8 *, u8 *, u8 *, u32))*(void **)(lbl_803C0F78 + 0x191C))
                ((u8 *)p_dev_rec + 0x1C, (u8 *)p_dev_rec + 0x22, (u8 *)p_dev_rec + 0x35, 0x17);
        } else {
            ((void (*)(u8 *, u8 *, u8 *, u32))*(void **)(lbl_803C0F78 + 0x191C))
                ((u8 *)p_dev_rec + 0x1C, (u8 *)p_dev_rec + 0x22, (u8 *)p_dev_rec + 0x35, 5);
        }
    }
    if (*(u32 *)(lbl_803C0F78 + 0x194C) != 0 &&
        memcmp(lbl_803C0F78 + 0x1954, (u8 *)p_dev_rec + 0x1C, 6) == 0) {
        fn_80070F90(lbl_803C0F78 + 0x193C);
        *(u32 *)(lbl_803C0F78 + 0x194C) = 0;
        memset(lbl_803C0F78 + 0x1954, 0xFF, 6);
        if (*(void **)(lbl_803C0F78 + 0x191C) != NULL)
            ((void (*)(u8 *, u8 *, u8 *, u32))*(void **)(lbl_803C0F78 + 0x191C))
                ((u8 *)p_dev_rec + 0x1C, (u8 *)p_dev_rec + 0x22, (u8 *)p_dev_rec + 0x35, 0xE);
    }
    *(UINT16 *)((u8 *)p_dev_rec + 0x18) = 0xFFFF;
    *(u8 *)((u8 *)p_dev_rec + 0x7F) = 0;
    *(u8 *)((u8 *)p_dev_rec + 0x76) &= 0xF8;
    *(u8 *)((u8 *)p_dev_rec + 0x81) &= 0x80;
    *(u32 *)((u8 *)p_dev_rec + 4) = 0;
}

/* Match note: initialize the callback table at its base, then walk two entries by four bytes. */
void btm_sec_link_key_notification(u8 *bd_addr, u8 *link_key, u8 key_type) {
    extern u8 lbl_80316F58[];
    extern u8 lbl_80316F9C[];
    u8 *dev = (u8 *)btm_find_dev(bd_addr);
    u32 (*auth_cb)(void *, void *, void *, void *, u8);
    u32 (*key_cb)(void *, void *, void *, void *, u8);
    u8 *callbacks;
    s32 i;

    if (dev == NULL) {
        dev = (u8 *)btm_sec_alloc_dev(bd_addr);
        if (dev == NULL)
            return;
    }
    if (lbl_803C0F78[0x27C0] >= 4)
        fn_800709CC(0xD0003, lbl_80316F58, bd_addr[0], bd_addr[1], bd_addr[2], bd_addr[3], bd_addr[4], bd_addr[5]);
    if (lbl_803C0F78[0x27C0] >= 4)
        fn_80070954(0xD0003, lbl_80316F9C, key_type);
    if (lbl_803C0F78[0x636] < 1)
        dev[0x83] = 0xFF;
    else
        dev[0x83] = key_type;
    dev[0x76] |= 0x10;
    memcpy(dev + 0x25, link_key, 0x10);
    if ((dev[0x76] & 8) == 0 || ((dev[0x81] & 0x40) != 0 && dev[0x85] == 0)) {
        dev[0x82] = 1;
        return;
    }
    auth_cb = *(u32 (**)(void *, void *, void *, void *, u8))(lbl_803C0F78 + 0x1914);
    if (auth_cb != NULL)
        auth_cb(bd_addr, dev + 0x22, dev + 0x35, link_key, dev[0x83]);
    callbacks = lbl_803C0F78;
    i = 0;
    do {
        key_cb = *(u32 (**)(void *, void *, void *, void *, u8))(callbacks + 0x1924);
        if (key_cb != NULL)
            key_cb(bd_addr, dev + 0x22, dev + 0x35, link_key, dev[0x83]);
        i++;
        callbacks += 4;
    } while (i < 2);
}

extern char lbl_80316FC8[];
void btm_sec_link_key_request(BD_ADDR bd_addr) {
    tBTM_SEC_DEV_REC *p_dev;
    u8 key[16];
    u8 (*p_callback)(BD_ADDR, u8 *);

    p_dev = btm_find_dev(bd_addr);
    if (lbl_803C0F78[0x27C0] >= 4)
        fn_800709CC(0xD0003, lbl_80316FC8, bd_addr[0], bd_addr[1], bd_addr[2], bd_addr[3], bd_addr[4], bd_addr[5]);
    if (p_dev != 0 && (p_dev->sec_flags & BTM_SEC_LINK_KEY_KNOWN)) {
        btsnd_hcic_link_key_req_reply(bd_addr, p_dev->link_key);
        return;
    }
    if (p_dev == 0) p_dev = btm_sec_alloc_dev(bd_addr);
    if ((p_dev->sec_flags & BTM_SEC_LINK_KEY_AUTHED) == 0) {
        p_callback = *(u8 (**)(BD_ADDR, u8 *))(lbl_803C0F78 + 0x1918);
        if (p_callback != 0) {
            if (p_dev != 0) {
                if (p_callback(bd_addr, p_dev->link_key) == 0) {
                    btsnd_hcic_link_key_req_reply(bd_addr, p_dev->link_key);
                    return;
                }
            } else if (p_callback(bd_addr, key) == 0) {
                btsnd_hcic_link_key_req_reply(bd_addr, key);
                return;
            }
        }
    }
    btsnd_hcic_link_key_neg_reply(bd_addr);
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

void btm_sec_pin_code_request(UINT8 *p_bda) {
    u8 *trace = (u8 *)lbl_80316870;
    s32 count;
    u8 *cb = lbl_803C0F78;
    tBTM_SEC_DEV_REC *p_dev_rec;
    u8 *dev;
    u8 *entry;
    void (*p_pin_callback)(u8 *, u8 *, u8 *);
    BOOL do_reject;
    s32 i;

    do_reject = FALSE;
    count = 0;

    if (cb[0x27C0] >= 4) {
        fn_800709CC(0xD0003, trace + 0x7BC, p_bda[0], p_bda[1],
                    p_bda[2], p_bda[3], p_bda[4], p_bda[5]);
    }

    if (cb[0x1979] == 0 && cb[0x20] == 1) {
        if (btm_find_dev(p_bda) == NULL) {
            entry = lbl_803C0F78 + 0x1F30;
            for (i = 0; i < 2; i++, entry += 0x440) {
                if (!(entry[0x76] & 0x80)) goto count_done;
                count++;
                if (!(entry[0xFE] & 0x80)) goto count_done;
                count++;
                if (!(entry[0x186] & 0x80)) goto count_done;
                count++;
                if (!(entry[0x20E] & 0x80)) goto count_done;
                count++;
                if (!(entry[0x296] & 0x80)) goto count_done;
                count++;
                if (!(entry[0x31E] & 0x80)) goto count_done;
                count++;
                if (!(entry[0x3A6] & 0x80)) goto count_done;
                count++;
                if (!(entry[0x42E] & 0x80)) goto count_done;
                count++;
            }
        }
count_done:
        if (count >= 0x10) {
            btsnd_hcic_link_key_neg_reply_800840C8(p_bda);
            return;
        }
        btsnd_hcic_pin_code_req_reply(p_bda, cb[0x21], cb + 0x22);
        return;
    }

    p_dev_rec = btm_find_dev(p_bda);
    if (p_dev_rec == NULL) {
        p_dev_rec = btm_sec_alloc_dev(p_bda);
    }
    memcpy(lbl_803C0F78 + 0x1954, p_bda, 6);
    dev = (u8 *)p_dev_rec;
    if (dev != NULL) {
        if (memcmp(p_bda, cb + 0x27B4, 6) == 0) {
            memcpy(dev + 0x22, cb + 0x27BA, 3);
        }
        if (dev[0x81] & 0x40) {
            if (lbl_803C0F78[0x27C0] >= 4) {
                fn_8007093C(0xD0003, trace + 0x7FC);
            }
            btsnd_hcic_pin_code_req_reply(p_bda, cb[0x197F], cb + 0x1980);
            if (lbl_803C0F78[0x197B] != 0) {
                lbl_803C0F78[0x197B] = 0;
                if (lbl_803C0F78[0x27C0] >= 5) {
                    ((void (*)(u32, void *, u32))fn_80070954)(
                        0xD0004, trace + 0x82C,
                        (u32)((lbl_803C0F78[0x1978] - 3) == 0));
                }
                btsnd_hcic_write_pin_type_8008543C(
                    (u8)((lbl_803C0F78[0x1978] - 3) == 0));
            }
        } else if (cb[0x1979] != 0 || *(void **)(cb + 0x1910) == NULL ||
                   (dev[0x80] == 0 && (dev[0x23] & 0x1F) == 5 &&
                    (dev[0x24] & 0x40))) {
            do_reject = TRUE;
        } else {
            memcpy(cb + 0x27B4, p_bda, 6);
            memcpy(cb + 0x27BA, dev + 0x22, 3);
            *(void **)(cb + 0x194C) = btm_sec_pin_code_request_timeout;
            btu_start_timer((TIMER_LIST_ENT *)(cb + 0x193C), 0x16, 0x3C);
            p_pin_callback = *(void (**)(u8 *, u8 *, u8 *))(cb + 0x1910);
            p_pin_callback(p_bda, dev + 0x22, dev + 0x35);
        }
    } else {
        do_reject = TRUE;
    }

    if (do_reject) {
        if (lbl_803C0F78[0x27C0] >= 2) {
            ((void (*)(u32, void *, u8, void *, void *))fn_80070984)(
                0xD0001, trace + 0x85C, cb[0x1979],
                *(void **)(cb + 0x1910), p_dev_rec);
        }
        btsnd_hcic_link_key_neg_reply_800840C8(p_bda);
    }
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

u8 btm_sec_start_authorization(u8 *p) {
    u8 *peer;
    u8 *remote = 0;
    u8 status;
    u8 flag = 0;
    u8 result;
    if ((p[0x76] & 8) == 0 && *(u16 *)(p + 0x18) == 0xFFFF) {
        if (*(u32 *)(lbl_803C0F78 + 0x190C) == 0)
            return 4;
        peer = *(u8 **)p;
        if (peer != 0) {
            remote = p[0x80] ? peer + 0x10 : peer + 0x26;
            flag = peer[0xF];
        }
        p[0x7F] = 4;
        result = (*(u8 (**)(void *, void *, void *, void *, u8, u8))(lbl_803C0F78 + 0x190C))(p + 0x1C, p + 0x22, p + 0x35, remote, flag, p[0x80]);
        if (result == 0) {
            status = p[0x76];
            p[0x7F] = 0;
            p[0x76] = status | 1;
        }
        return result;
    }
    status = p[0x7F];
    p[0x7F] = 3;
    if (btm_initiate_rem_name(p + 0x1C, 0, 2, 0x1E, 0) != 1)
        p[0x7F] = status;
    return 1;
}

void btm_sec_collision_timeout(void) {
    extern u8 btm_sec_execute_procedure(void *);
    extern void fn_8007093C(u32, void *);
    extern char lbl_80317264[];
    u8 status;
    if (lbl_803C0F78[0x27C0] >= 4) fn_8007093C(0xD0003, lbl_80317264);
    *(u32 *)(lbl_803C0F78 + 0x196C) = 0;
    status = btm_sec_execute_procedure(*(void **)(lbl_803C0F78 + 0x1938));
    if (status != 1) {
        void *sec = *(void **)(lbl_803C0F78 + 0x1938);
        if (*(u32 *)((u8 *)sec + 4) != 0) {
            if (*((u8 *)sec + 0x80) != 0) {
                void *entry = *(void **)sec;
                if (entry != 0 && *(u32 *)entry == 3) *(u32 *)((u8 *)entry + 4) = 0;
            }
            ((void (*)(void *, void *, u8))(*(void **)(*(u8 **)(lbl_803C0F78 + 0x1938) + 4)))((u8 *)*(void **)(lbl_803C0F78 + 0x1938) + 0x1C, *(void **)(*(u8 **)(lbl_803C0F78 + 0x1938) + 8), status);
            *(u32 *)(*(u8 **)(lbl_803C0F78 + 0x1938) + 4) = 0;
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

void btu_hcif_connection_comp_evt(u8 *p) {
    u8 status;
    u16 handle;
    BD_ADDR bda;
    u8 link_type;
    u8 enc_mode;
    tBTM_ESCO_DATA data;

    status = p[0];
    handle = (u16)((p[1] + (p[2] << 8)) & 0x0fff);
    bda[5] = p[3];
    bda[4] = p[4];
    bda[3] = p[5];
    bda[2] = p[6];
    bda[1] = p[7];
    bda[0] = p[8];
    link_type = p[9];
    enc_mode = p[10];
    if (link_type == 1) {
        btm_sec_connected(bda, handle, status, enc_mode);
        l2c_link_hci_conn_comp(status, handle, bda);
    } else {
        memset(&data, 0, 0xE);
        memcpy(data.bd_addr, bda, 6);
        btm_sco_connected(status, bda, handle, &data);
    }
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

void btu_hcif_qos_setup_comp_evt(void *event) {
    register u8 *p = (u8 *)event;
    register UINT8 *stream = p + 5;
    FLOW_SPEC flow;
    UINT8 status;
    UINT16 handle;
    status = p[0];
    handle = (UINT16)((p[1] + (p[2] << 8)));
    flow.qos_flags = p[3];
    flow.service_type = p[4];
    STREAM_TO_UINT32(flow.token_rate, stream);
    STREAM_TO_UINT32(flow.peak_bandwidth, stream);
    STREAM_TO_UINT32(flow.latency, stream);
    STREAM_TO_UINT32(flow.delay_variation, stream);
    btm_qos_setup_complete(status, handle, &flow);
}

void btu_hcif_esco_connection_comp_evt(u8 *p) {
    u8 status;
    tBTM_ESCO_DATA data;
    BD_ADDR bda;
    u16 handle;

    status = p[0];
    handle = p[1] + (p[2] << 8);
    bda[5] = p[3];
    bda[4] = p[4];
    bda[3] = p[5];
    bda[2] = p[6];
    bda[1] = p[7];
    bda[0] = p[8];
    data.link_type = p[9];
    data.tx_interval = p[10];
    data.retrans_window = p[11];
    data.rx_pkt_len = p[12] + (p[13] << 8);
    data.tx_pkt_len = p[14] + (p[15] << 8);
    data.air_mode = p[16];
    memcpy(data.bd_addr, bda, BD_ADDR_LEN);
    btm_sco_connected(status, bda, handle, &data);
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

void btu_hcif_command_complete_evt(UINT8 *p, UINT16 len) {
    UINT16 opcode;
    UINT16 queued_opcode;
    void *buf;
    *(UINT16 *)(lbl_803C0A50 + 0x80) = p[0];
    opcode = (UINT16)(p[1] + (p[2] << 8));
    if (opcode != 0xC03 && opcode != 0xC35 && opcode != 0) {
        buf = GKI_dequeue((BUFFER_Q *)(lbl_803C0A50 + 0x70));
        if (buf != 0) {
            queued_opcode = (UINT16)(((UINT8 *)buf)[8] + (((UINT8 *)buf)[9] << 8));
            if (opcode == 0xFC4C && queued_opcode != opcode) {
                GKI_enqueue_head((BUFFER_Q *)(lbl_803C0A50 + 0x70), buf);
                return;
            }
            GKI_freebuf(buf);
        }
        if (fn_8006DF84(lbl_803C0A50 + 0x70) == 0)
            btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0A50 + 0x4C), 0x3C, 8);
        else
            fn_80070F90(lbl_803C0A50 + 0x4C);
    }
    btu_hcif_hdl_command_complete(opcode, p + 3, len - 3);
    btu_hcif_send_cmd(0);
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

void btu_hcif_command_status_evt(UINT8 *p, UINT16 len) {
    UINT8 status;
    UINT16 opcode;
    UINT16 queued_opcode;
    void *buf;
    UINT8 *cmd;
    status = p[0];
    *(UINT16 *)(lbl_803C0A50 + 0x80) = p[1];
    opcode = (UINT16)(p[2] + (p[3] << 8));
    buf = 0;
    cmd = 0;
    if (opcode != 0xC03 && opcode != 0xC35 && opcode != 0) {
        buf = GKI_dequeue((BUFFER_Q *)(lbl_803C0A50 + 0x70));
        if (buf != 0) {
            cmd = (UINT8 *)buf + *(UINT16 *)((UINT8 *)buf + 4);
            queued_opcode = (UINT16)(cmd[8] + (cmd[9] << 8));
            if (queued_opcode != opcode) {
                fn_8007096C(0x70001, &lbl_80317298, opcode, 0);
                cmd = 0;
            }
        }
        if (fn_8006DF84(lbl_803C0A50 + 0x70) == 0)
            btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0A50 + 0x4C), 0x3C, 8);
        else
            fn_80070F90(lbl_803C0A50 + 0x4C);
    }
    btu_hcif_hdl_command_status(opcode, status, cmd);
    if (buf != 0)
        GKI_freebuf(buf);
    btu_hcif_send_cmd(0);
}

void btu_hcif_cmd_timeout(void) {
    extern unsigned char lbl_803C0A50[];
    extern char lbl_803172C0[];
    extern char lbl_803172E0[];
    void *buf;
    register unsigned char *cmd;
    register s32 opcode;
    UINT8 status;

    *(UINT16 *)(lbl_803C0A50 + 0x80) = 1;
    buf = GKI_dequeue((BUFFER_Q *)(lbl_803C0A50 + 0x70));
    if (buf == 0) {
        fn_8007093C(0x70001, lbl_803172C0);
        return;
    }
    if (fn_8006DF84(lbl_803C0A50 + 0x70) == 0)
        btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0A50 + 0x4C), 0x3C, 8);
    cmd = (unsigned char *)buf + *(UINT16 *)((unsigned char *)buf + 4);
    opcode = (UINT16)(cmd[8] + (cmd[9] << 8));
    fn_80070954(0x70001, lbl_803172E0, opcode);
    if (opcode != 0x419) {
        if (opcode < 0x419) {
            if (opcode != 0x401) {
                if (opcode < 0x401) {
                    if (opcode != 0xD) goto complete;
                    goto command_status;
                }
                if (opcode != 0x405) goto complete;
                goto command_status;
            }
            goto command_status;
        }
        if (opcode == 0x802) goto complete;
        if (opcode < 0x802) {
            if (opcode < 0x801) goto complete;
            goto command_status;
        }
        if (opcode < 0x807) goto command_status;
        goto complete;
    }
command_status:
    btu_hcif_hdl_command_status(opcode, 0x1F, cmd + 0xA);
    goto done;
complete:
    status = 0x1F;
    btu_hcif_hdl_command_complete(opcode, &status, 1);
done:
    GKI_freebuf(buf);
    fn_8007ABE8((void *)2);
    btu_hcif_send_cmd(0);
}

void btu_hcif_link_key_notification_evt(u8 *p, u16 evt_len) {
    BD_ADDR bda;
    LINK_KEY key;
    u8 *key_type_ptr = p;

    key_type_ptr += sizeof(bda) + sizeof(key);
    bda[5] = p[0]; bda[4] = p[1]; bda[3] = p[2];
    bda[2] = p[3]; bda[1] = p[4]; bda[0] = p[5];
    key[15] = p[6]; key[14] = p[7]; key[13] = p[8]; key[12] = p[9];
    key[11] = p[10]; key[10] = p[11]; key[9] = p[12]; key[8] = p[13];
    key[7] = p[14]; key[6] = p[15]; key[5] = p[16]; key[4] = p[17];
    key[3] = p[18]; key[2] = p[19]; key[1] = p[20]; key[0] = p[21];
    btm_sec_link_key_notification(bda, key, *key_type_ptr);
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

BOOLEAN WBT_ExtCreateRecord(void) {
    UINT8 info[0xFC];
    volatile UINT32 handle = 0;
    UINT8 attr[2];
    UINT16 uuid = 0x1002;
    register UINT8 *record;

    if (SDP_GetLocalDiRecord((tSDP_DI_GET_RECORD *)info, (UINT32 *)&handle) != SDP_SUCCESS) {
        record = info + 2;
        memset(record, 0, 0xFA);
        *(UINT16 *)(info + 2) = 0xF;
        *(UINT16 *)(info + 4) = 1;
        info[10] = 1;
        if (SDP_SetLocalDiRecord((tSDP_DI_RECORD *)record, (UINT32 *)&handle) != SDP_SUCCESS) {
            handle = 0;
            return FALSE;
        }
    }
    SDP_AddUuidSequence(handle, 5, 1, &uuid);
    attr[0] = 0;
    attr[1] = 1;
    SDP_AddAttribute(handle, 0x8001, 1, 2, attr);
    return TRUE;
}

extern u8 lbl_803C3740[];
typedef struct {
    u8 inq[0x3C];
    u8 disc_comp[0x34];
    u8 disc_succ[0x28];
    u8 rem_name[1];
} GapTraceStrings;
extern void gap_connect_ind(BD_ADDR, UINT16, UINT16, UINT8), gap_connect_cfm(u32, s32), gap_config_ind(u16, void *), gap_config_cfm(u32, u16 *), gap_disconnect_ind(void), gap_data_ind(u16, void *), gap_congestion_ind(u16, u16);
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

extern u8 lbl_80559078[],lbl_80317310[],lbl_80317354[];
void gap_connect_ind(BD_ADDR addr, UINT16 cid, UINT16 psm, UINT8 status) {
 u8 *entry=lbl_803C3740+0xAC; u8 i=0;
 while(i<8){if(entry[0]==1&&*(u16 *)(entry+0x10)==psm&&(entry[8]==0||memcmp(addr,entry+9,6)==0))break;i++;entry+=0x60;}
 if(i==8){if(lbl_803C3740[0x28]>=2)fn_8007093C(0xE0001,lbl_80559078);if(lbl_803C3740[0x28]>=2)fn_8007093C(0xE0001,lbl_80317310);if(lbl_803C3740[0x28]>=2)fn_8007093C(0xE0001,lbl_80559078);L2CA_DisconnectReq(cid);return;}
 entry[0]=3;memcpy(entry+9,addr,6);*(u16 *)(entry+6)=cid;L2CA_ConnectRsp(addr,status,cid,0,0);
 if(lbl_803C3740[0x28]>=4)fn_80070954(0xE0003,lbl_80317354,*(u16 *)(entry+6));
 L2CA_ConfigReq(cid,(tL2CAP_CFG_INFO *)(entry+0x24));
}

void gap_config_ind(u16 cid, void *p_cfg) {
    u8 *conn = lbl_803C3740 + 0xAC;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (conn[0] != 0 && *(u16 *)(conn + 6) == cid) goto found;
        conn += 0x60;
    }
    conn = 0;
found:
    if (conn == 0) return;
    if (((u8 *)p_cfg)[2] != 0) {
        u16 value = *(u16 *)((u8 *)p_cfg + 4);
        if (value > 0x69B) value = 0x69B;
        *(u16 *)(conn + 0x12) = value;
    }
    ((u8 *)p_cfg)[0x20] = 0;
    ((u8 *)p_cfg)[2] = 0;
    *(u16 *)p_cfg = 0;
    L2CA_ConfigRsp(cid, p_cfg);
    conn[1] |= 2;
    if (conn[1] & 4) {
        conn[0] = 4;
        ((void (*)(u16, u16))*(void **)(conn + 0x20))(*(u16 *)(conn + 4), 0x100);
    }
}

void gap_config_cfm(u32 cid, u16 *p_cfg) {
    u8 *ccb = (u8 *)&lbl_803C3740 + 0xAC;
    s32 i;
    u16 psm;
    for (i = 0; i < 4; i++) {
        if (ccb[0] && *(u16 *)(ccb + 6) == cid) break;
        ccb += 0x60;
    }
    if (i == 4) return;
    if (*p_cfg == 0) {
        ccb[1] |= 4;
        if (ccb[1] & 2) {
            ccb[0] = 4;
            ((void (*)(u16, u16))*(u32 *)(ccb + 0x20))(*(u16 *)(ccb + 4), 0x100);
        }
    } else {
        ((void (*)(u16, u16))*(u32 *)(ccb + 0x20))(*(u16 *)(ccb + 4), 0x101);
        psm = *(u16 *)(ccb + 0x10);
        while (*(u32 *)(ccb + 0x14) != 0)
            GKI_freebuf(GKI_dequeue((BUFFER_Q *)(ccb + 0x14)));
        ccb[0] = 0;
        {
            u8 *p = (u8 *)&lbl_803C3740 + 0xAC;
            for (i = 0; i < 4; i++, p += 0x60)
                if (p[0] && *(u16 *)(p + 0x10) == psm) return;
        }
        L2CA_Deregister(psm);
    }
}

void gap_data_ind(u16 cid, void *p_buf) {
    u8 *conn = lbl_803C3740 + 0xAC;
    u8 i = 0;

    while (i < 8) {
        if (conn[0] != 0 && *(u16 *)(conn + 6) == cid)
            goto found;
        i++;
        conn += 0x60;
    }
    conn = NULL;
found:
    if (conn == NULL) {
        GKI_freebuf(p_buf);
    } else if (conn[0] == 4) {
        GKI_enqueue((BUFFER_Q *)(conn + 0x14), p_buf);
        ((void (*)(u16, u16))*(void **)(conn + 0x20))(*(u16 *)(conn + 4), 0x102);
    } else {
        GKI_freebuf(p_buf);
    }
}

extern char lbl_803173A8[];
void gap_congestion_ind(u16 cid, u16 congest) {
    u8 *base = lbl_803C3740 + 0xAC;
    u8 *p;
    u32 i;
    u16 value;
    void (*callback)(u16, u16);
    if (lbl_803C3740[0x28] >= 4)
        fn_8007096C(0xE0003, lbl_803173A8, congest, cid);
    for (i = 0; i < 4; i++) {
        p = base + i * 0x60;
        if (p[0] && *(u16 *)(p + 6) == cid)
            break;
    }
    if (i < 4) {
        value = (u16)(0x104 + (congest != 0));
        callback = *(void (**)(u16, u16))(p + 0x20);
        callback(*(u16 *)(p + 4), value);
    }
}

extern u8 lbl_803173E0[];
#pragma push
#pragma scheduling invalid_target
void btm_cback(u32 index, void *param) {
    u8 *p_trace = lbl_803173E0;
    u8 *p_elem;
    struct {
        u16 status;
        u8 results;
    } inq_res;

    if (index >= 2) return;

    p_elem = &lbl_803C3740[(u16)index * 0x10];
    if (p_elem[0xF] == 0) return;

    switch (*(u16 *)(p_elem + 0xC)) {
    case 2:
        inq_res.results = ((u8 *)param)[1];
        inq_res.status = ((u8 *)param)[0] == 0 ? 0 : 0x114;
        param = &inq_res;
        if (lbl_803C3740[0x28] >= 4) {
            fn_8007096C(0xE0003, p_trace, inq_res.status, inq_res.results);
        }
        break;
    case 3:
        if (*(u16 *)param != 0) {
            if (lbl_803C3740[0x28] >= 4) {
                fn_80070954(0xE0003, p_trace + 0x3C, *(u16 *)param);
            }
        } else {
            if (lbl_803C3740[0x28] >= 4) {
                fn_8007093C(0xE0003, p_trace + 0x70);
            }
        }
        break;
    case 4: {
        u16 res;
        switch ((u8)*(u16 *)param) {
        case 0: res = 0; break;
        case 1: res = 0x10B; break;
        case 2: res = 0x103; break;
        case 4:
        case 5: res = 0x109; break;
        case 6: res = 0x10C; break;
        case 7: res = 0x10D; break;
        case 8: res = 0x115; break;
        case 3:
        default: res = 0x114; break;
        }
        *(u16 *)param = res;
        if (lbl_803C3740[0x28] >= 4) {
            fn_80070954(0xE0003, p_trace + 0x98, res);
        }
        break;
    }
    }

    if (*(void **)(p_elem + 4) != NULL) {
        ((void (*)(u16, void *))*(void **)(p_elem + 4))(*(u16 *)(p_elem + 0xC), param);
    }
    if (p_elem != NULL) {
        *(void **)(p_elem + 4) = NULL;
        p_elem[0xF] = 0;
    }
}
#pragma pop
void fn_800833E8(void *arg0) { btm_cback(0, arg0); }

void fn_800833F4(void *arg0) { btm_cback(1, arg0); }

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

BOOLEAN btsnd_hcic_create_conn(BD_ADDR dest, UINT16 packet_types, UINT8 page_scan_rep_mode, UINT8 page_scan_mode, UINT16 clock_offset, UINT8 allow_switch) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;
    *(u16 *)(p + 2) = 0x10;
    *(u16 *)(p + 4) = 0;
    p[8] = 5;
    p[9] = 4;
    p[10] = 0xD;
    p[11] = dest[5];
    p[12] = dest[4];
    p[13] = dest[3];
    p[14] = dest[2];
    p[15] = dest[1];
    p[16] = dest[0];
    p[17] = packet_types;
    p[18] = packet_types >> 8;
    p[19] = page_scan_rep_mode;
    p[20] = page_scan_mode;
    p[21] = clock_offset;
    p[22] = clock_offset >> 8;
    p[23] = allow_switch;
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

int btsnd_hcic_accept_conn(void *p_buf, u8 *bd_addr, u8 role) {
    u8 *buf = p_buf;
    *(u16 *)(buf + 2) = 0xA;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 9;
    buf[9] = 4;
    buf[0xA] = 7;
    buf[0xB] = bd_addr[5];
    buf[0xC] = bd_addr[4];
    buf[0xD] = bd_addr[3];
    buf[0xE] = bd_addr[2];
    buf[0xF] = bd_addr[1];
    buf[0x10] = bd_addr[0];
    buf[0x11] = role;
    return btu_hcif_send_cmd(buf);
}

int btsnd_hcic_reject_conn(void *p_buf, u8 *bd_addr, u8 reason) {
    u8 *buf = p_buf;

    *(u16 *)(buf + 2) = 0xA;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 0xA;
    buf[9] = 4;
    buf[0xA] = 7;
    buf[0xB] = bd_addr[5];
    buf[0xC] = bd_addr[4];
    buf[0xD] = bd_addr[3];
    buf[0xE] = bd_addr[2];
    buf[0xF] = bd_addr[1];
    buf[0x10] = bd_addr[0];
    buf[0x11] = reason;
    return btu_hcif_send_cmd(buf);
}

/* Match note: allocate pool 2 directly and send the completed packet with the one-argument helper call. */
BOOLEAN btsnd_hcic_link_key_req_reply(BD_ADDR bd_addr, LINK_KEY link_key) {
    BT_HDR *p;
    UINT8 *pp;

    if ((p = (BT_HDR *)GKI_getpoolbuf(2)) == NULL)
        return FALSE;
    pp = (UINT8 *)(p + 1);
    p->len = 0x19;
    p->offset = 0;
    UINT16_TO_STREAM(pp, HCI_LINK_KEY_REQUEST_REPLY);
    UINT8_TO_STREAM(pp, HCIC_PARAM_SIZE_LINK_KEY_REQ_REPLY);
    BDADDR_TO_STREAM(pp, bd_addr);
    ARRAY16_TO_STREAM(pp, link_key);
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

BOOLEAN btsnd_hcic_setup_esco_conn(UINT16 handle, UINT32 tx_bandwidth, UINT32 rx_bandwidth, UINT16 max_latency, UINT16 voice_setting, UINT8 retrans_effort, UINT16 packet_types) {
    UINT8 *p = (UINT8 *)GKI_getpoolbuf(2);

    if (p == NULL) {
        return FALSE;
    }
    *(UINT16 *)(p + 2) = 0x14;
    *(UINT16 *)(p + 4) = 0;
    p[8] = 0x28;
    p[9] = 4;
    p[10] = 0x11;
    p[11] = handle;
    p[12] = handle >> 8;
    p[13] = tx_bandwidth;
    p[14] = tx_bandwidth >> 8;
    p[15] = tx_bandwidth >> 16;
    p[16] = tx_bandwidth >> 24;
    p[17] = rx_bandwidth;
    p[18] = rx_bandwidth >> 8;
    p[19] = rx_bandwidth >> 16;
    p[20] = rx_bandwidth >> 24;
    p[21] = max_latency;
    p[22] = max_latency >> 8;
    p[23] = voice_setting;
    p[24] = voice_setting >> 8;
    p[25] = retrans_effort;
    p[26] = packet_types;
    p[27] = packet_types >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

void btsnd_hcic_accept_esco_conn(BT_HDR *p, BD_ADDR bd_addr, UINT32 tx_bw,
                                     UINT32 rx_bw, UINT16 max_latency,
                                     UINT16 content_fmt, UINT8 retrans_effort,
                                     UINT16 packet_types) {
    UINT8 *pp = (UINT8 *)(p + 1);

    p->len = 0x18;
    p->offset = 0;
    pp[0] = 0x29;
    pp[1] = 4;
    pp[2] = 0x15;
    pp[3] = bd_addr[5];
    pp[4] = bd_addr[4];
    pp[5] = bd_addr[3];
    pp[6] = bd_addr[2];
    pp[7] = bd_addr[1];
    pp[8] = bd_addr[0];
    pp[9] = tx_bw;
    pp[10] = tx_bw >> 8;
    pp[11] = tx_bw >> 16;
    pp[12] = tx_bw >> 24;
    pp[13] = rx_bw;
    pp[14] = rx_bw >> 8;
    pp[15] = rx_bw >> 16;
    pp[16] = rx_bw >> 24;
    pp[17] = max_latency;
    pp[18] = max_latency >> 8;
    pp[19] = content_fmt;
    pp[20] = content_fmt >> 8;
    pp[21] = retrans_effort;
    pp[22] = packet_types;
    pp[23] = packet_types >> 8;
    btu_hcif_send_cmd(p);
}

int btsnd_hcic_reject_esco_conn(void *p_buf, u8 *bd_addr, u8 reason) {
    u8 *buf = p_buf;

    *(u16 *)(buf + 2) = 0xA;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 0x2A;
    buf[9] = 4;
    buf[0xA] = 7;
    buf[0xB] = bd_addr[5];
    buf[0xC] = bd_addr[4];
    buf[0xD] = bd_addr[3];
    buf[0xE] = bd_addr[2];
    buf[0xF] = bd_addr[1];
    buf[0x10] = bd_addr[0];
    buf[0x11] = reason;
    return btu_hcif_send_cmd(buf);
}

BOOLEAN btsnd_hcic_hold_mode(UINT16 handle, UINT16 max_hold_period, UINT16 min_hold_period) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == NULL)
        return FALSE;
    *(u16 *)(p + 2) = 9;
    *(u16 *)(p + 4) = 0;
    p[8] = 1;
    p[9] = 8;
    p[10] = 6;
    p[11] = handle;
    p[12] = handle >> 8;
    p[13] = max_hold_period;
    p[14] = max_hold_period >> 8;
    p[15] = min_hold_period;
    p[16] = min_hold_period >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_sniff_mode(BT_HDR *p, s16 handle, s16 max_sniff_period, s16 min_sniff_period, s16 sniff_attempt, UINT16 sniff_timeout) {
    UINT8 *bytes;

    if (p == NULL) {
        p = GKI_getpoolbuf(2);
        if (p == NULL) {
            return FALSE;
        }
    }

    bytes = (UINT8 *)p;
    p->len = 0xD;
    p->offset = 0;
    bytes[8] = 3;
    bytes[9] = 8;
    bytes[10] = 0xA;
    bytes[11] = handle;
    bytes[12] = handle >> 8;
    bytes[13] = max_sniff_period;
    bytes[14] = max_sniff_period >> 8;
    bytes[15] = min_sniff_period;
    bytes[16] = min_sniff_period >> 8;
    bytes[17] = sniff_attempt;
    bytes[18] = sniff_attempt >> 8;
    bytes[19] = sniff_timeout;
    bytes[20] = sniff_timeout >> 8;
    btu_hcif_send_cmd(p);
    return TRUE;
}

s32 btsnd_hcic_exit_sniff_mode(void *arg0, u16 arg1) {
    u8 *p = (u8 *)arg0;
    register u8 field8 = 4;
    register u8 field9 = 8;
    register u8 field10 = 2;
    if (p == NULL) {
        p = GKI_getpoolbuf(2);
        if (p == NULL)
            return 0;
    }
    *(u16 *)(p + 2) = 5;
    *(u16 *)(p + 4) = 0;
    p[8] = field8;
    p[9] = field9;
    p[10] = field10;
    p[11] = arg1;
    p[12] = arg1 >> 8;
    btu_hcif_send_cmd(p, field10, field9, field8);
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

void fn_8008534C(void *arg0, u16 arg1) {
    *(u16 *)((u8 *)arg0 + 2) = 5;
    *(u16 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x18;
    *(u8 *)((u8 *)arg0 + 9) = 0x0C;
    *(u8 *)((u8 *)arg0 + 10) = 2;
    *(u8 *)((u8 *)arg0 + 11) = arg1;
    *(u8 *)((u8 *)arg0 + 12) = arg1 >> 8;
    btu_hcif_send_cmd(arg0);
}

void fn_80085384(u8 *arg0, u8 arg1) {
    *(u16 *)(arg0 + 2) = 4;
    *(u16 *)(arg0 + 4) = 0;
    arg0[8] = 0x1A;
    arg0[9] = 0xC;
    arg0[10] = 1;
    arg0[11] = arg1;
    btu_hcif_send_cmd(0xC, 0x1A, 0, 4);
}

void fn_800853B4(u8 *arg0, u16 arg1, u16 arg2) {
    ((u16 *)(arg0 + 2))[0] = 7;
    ((u16 *)(arg0 + 4))[0] = 0;
    arg0[8] = 0x1C;
    arg0[9] = 0xC;
    arg0[10] = 4;
    arg0[11] = arg1;
    arg0[12] = arg1 >> 8;
    arg0[13] = arg2;
    arg0[14] = arg2 >> 8;
    btu_hcif_send_cmd(arg0);
}

void fn_800853F8(u8 *arg0, u16 arg1, u16 arg2) {
    ((u16 *)(arg0 + 2))[0] = 7;
    ((u16 *)(arg0 + 4))[0] = 0;
    arg0[8] = 0x1E;
    arg0[9] = 0xC;
    arg0[10] = 4;
    arg0[11] = arg1;
    arg0[12] = arg1 >> 8;
    arg0[13] = arg2;
    arg0[14] = arg2 >> 8;
    btu_hcif_send_cmd(arg0);
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

void fn_80085524(void *arg0, void *arg1) {
    ((u16 *)((u8 *)arg0 + 2))[0] = 6;
    ((u16 *)((u8 *)arg0 + 4))[0] = 0;
    ((u8 *)arg0)[8] = 0x24;
    ((u8 *)arg0)[9] = 0xC;
    ((u8 *)arg0)[10] = 3;
    ((u8 *)arg0)[11] = ((u8 *)arg1)[2];
    ((u8 *)arg0)[12] = ((u8 *)arg1)[1];
    ((u8 *)arg0)[13] = ((u8 *)arg1)[0];
    btu_hcif_send_cmd(arg0);
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
    if (buf == 0) return 0;
    *(u16 *)(buf + 2) = 7;
    *(u16 *)(buf + 4) = 0;
    buf[8] = 0x37;
    buf[9] = 0x0C;
    buf[10] = 4;
    buf[11] = arg0;
    buf[12] = arg0 >> 8;
    buf[13] = arg1;
    buf[14] = arg1 >> 8;
    btu_hcif_send_cmd(buf);
    return 1;
}

void btsnd_hcic_write_cur_iac_lap(u8 *p_buf, u8 num_cur_iac, LAP *cur_iac_lap) {
    u8 *p = p_buf + 0xC;
    u8 i;

    *(u16 *)(p_buf + 2) = (num_cur_iac * 3) + 4;
    *(u16 *)(p_buf + 4) = 0;
    p_buf[8] = 0x3A;
    p_buf[9] = 0xC;
    p_buf[10] = (num_cur_iac * 3) + 1;
    p_buf[11] = num_cur_iac;
    for (i = 0; i < num_cur_iac; i++) {
        p[0] = cur_iac_lap[i][2];
        p[1] = cur_iac_lap[i][1];
        p[2] = cur_iac_lap[i][0];
        p += 3;
    }
    btu_hcif_send_cmd(p_buf);
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
    struct Cmd {
        u16 pad;
        u16 opcode;
        u16 length;
        u8 reserved[2];
        u8 command;
        u8 parameter;
        u8 zero;
    } *cmd = (struct Cmd *)arg0;

    cmd->opcode = 3;
    cmd->length = 0;
    cmd->command = 5;
    cmd->parameter = 0x10;
    cmd->zero = 0;
    btu_hcif_send_cmd(cmd, 5, 0, 3);
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
    BT_HDR *header = (BT_HDR *)buffer;
    u8 *p = (u8 *)buffer;
    u8 *dst;
    u16 cmd = 0xfc00 | opcode;

    header->len = len + 3;
    dst = p + 0xb;
    header->offset = 0;
    p[8] = (u8)cmd;
    p[9] = (u8)(cmd >> 8);
    p[10] = len;

    if (len > 0)
        memcpy(dst, p_data, len);

    btu_hcif_send_cmd(buffer);
}

extern void hidd_proc_repage_timeout(void);
void HID_DevInit(void) {
    memset(&lbl_803C3AF0[0], 0, 0x144);
    lbl_803C3AF0[0xCA] = 1;
    *(u16*)&lbl_803C3AF0[0xCC] = 0x40;
    lbl_803C3AF0[0x106] = 1;
    *(u16*)&lbl_803C3AF0[0x108] = 0x40;
    *(void**)&lbl_803C3AF0[0x2C] = &hidd_proc_repage_timeout;
    lbl_803C3AF0[0x141] = 0;
}

extern char lbl_803176D0[];
extern char lbl_803176E8[];
s32 hidd_conn_initiate(void) {
    u16 cid;
    u8 *cb = lbl_803C3AF0;

    if (cb[0x141] >= 4) {
        fn_8007093C(0x1E0003, lbl_803176D0);
    }
    *(u16 *)(cb + 0x14) = 0;
    *(s16 *)(cb + 0x16) = 0;
    cb[0x11] = 1;
    cid = L2CA_ConnectReq(0x11, lbl_803C3AF0);
    *(u16 *)(cb + 0x14) = cid;
    if (cid == 0) {
        if (lbl_803C3AF0[0x141] >= 2) {
            fn_8007093C(0x1E0001, lbl_803176E8);
        }
        return 0xE;
    }
    cb[0x10] = 1;
    return 0;
}

void hidd_proc_repage_timeout(void)
{
    u8 *cb;
    void (*callback)(u8, u8, void *);

    if (lbl_803C3AF0[0x141] >= 5) {
        fn_8007093C(0x1E0004, lbl_80317700);
    }

    cb = lbl_803C3AF0;
    cb[9] = (u8)(cb[9] + 1);
    if ((u8)hidd_conn_initiate() != 0) {
        if (cb[9] > 0xF) {
            callback = *(void (**)(u8, u8, void *))(cb + 0xC4);
            cb[8] = 0;
            callback(1, 0, 0);
            return;
        }
        btu_start_timer((TIMER_LIST_ENT *)(cb + 0x1C), 0x16, 1);
        return;
    }

    callback = *(void (**)(u8, u8, void *))(cb + 0xC4);
    callback(2, cb[9], 0);
}

void hidd_pm_set_now(void *arg0) {
    u8 status = 0;
    u32 spC = 0;
    u32 sp10 = 0;
    u16 sp14 = 0;
    u8 mode;
    u8 *cb = lbl_803C3AF0;

    if (cb[0x6E] != 0) return;
    mode = ((u8 *)arg0)[8];
    if (mode == cb[0x6A] && (mode == 0 || (cb[0x6C] >= *(u16 *)((u8 *)arg0 + 2) && cb[0x6C] <= *(u16 *)arg0))) {
        cb[0x78] = 0xFF;
        return;
    }
    switch (mode) {
    case 0:
        if (cb[0x6A] == 2 || cb[0x6A] == 3) {
            status = BTM_SetPowerMode(0x80, cb, (void *)&spC);
            cb[0x6E] = 1;
        }
        break;
    case 2:
        if (cb[0x6A] != 0) hidd_pm_set_now(&spC);
        else { status = BTM_SetPowerMode(0x80, cb, arg0); cb[0x6E] = 1; }
        break;
    case 3:
        if (cb[0x6A] != 0) hidd_pm_set_now(&spC);
        else { status = BTM_SetPowerMode(0x80, cb, arg0); cb[0x6E] = 1; }
        break;
    }
    if (status > 1) {
        status += 0x37;
        if (*(void **)(cb + 0xC4) != 0) ((void (*)(int,u8,u8 *))*(void **)(cb + 0xC4))(4,cb[0x6F],&status);
    }
}

typedef void (*hidd_pm_callback)(u32, u8, void *);
void hidd_pm_proc_mode_change(u8 arg0, u8 arg1, u16 arg2) {
    u8 sp8;
    u16 spA;
    hidd_pm_callback callback;
    sp8 = arg0;
    spA = arg2;
    if (lbl_803C3AF0[0x140] == 0) return;
    lbl_803C3AF0[0x6E] = 0;
    if (arg0 != 0) {
        callback = *(hidd_pm_callback *)(lbl_803C3AF0 + 0xC4);
        if (callback != 0) callback(4, lbl_803C3AF0[0x6F], &sp8);
        return;
    }
    lbl_803C3AF0[0x6A] = arg1;
    *(u16 *)(lbl_803C3AF0 + 0x6C) = arg2;
    if (lbl_803C3AF0[0x78] != 0xFF) {
        if (lbl_803C3AF0[0x78] != arg1 ||
            (lbl_803C3AF0[0x78] != 0 &&
             (arg2 < *(u16 *)(lbl_803C3AF0 + 0x72) ||
              arg2 > *(u16 *)(lbl_803C3AF0 + 0x70)))) {
            hidd_pm_set_now(lbl_803C3AF0 + 0x70);
        } else {
            lbl_803C3AF0[0x78] = 0xFF;
        }
    } else if (arg1 == 0) {
        memcpy(lbl_803C3AF0 + 0x70, lbl_803C3AF0 + 0x4C, 0xA);
        hidd_pm_set_now(lbl_803C3AF0 + 0x4C);
        lbl_803C3AF0[0x6F] = 0;
        *(void (**)(void *))(lbl_803C3AF0 + 0x44) = fn_80086468;
        btu_start_timer(lbl_803C3AF0 + 0x34, 0x16, 0x3C);
    }
    callback = *(hidd_pm_callback *)(lbl_803C3AF0 + 0xC4);
    if (callback != 0) callback(3, arg1, &spA);
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

void *fn_80095C64(void **head, u32 attr);
void hidh_search_callback(UINT16 sdp_result) {
    tSDP_DISCOVERY_DB *p_db = *(tSDP_DISCOVERY_DB **)(lbl_803C3C38 + 0x388);
    tSDP_DISC_REC *p_rec;
    tSDP_DISC_ATTR *p_attr;
    tSDP_DISC_ATTR *p_subattr1;
    tSDP_DISC_ATTR *p_subattr2;
    tSDP_DISC_ATTR *p_repdesc;
    tBT_UUID hid_uuid;
    u8 *p_nvi = lbl_803C3C38 + 0x38c;
    UINT16 attr_mask = 0;
    UINT16 len;

    hid_uuid.len = LEN_UUID_16;
    hid_uuid.uu.uuid16 = UUID_SERVCLASS_HUMAN_INTERFACE;
    lbl_803C3C38[0x380] = FALSE;
    if (sdp_result != SDP_SUCCESS) {
        (*(void (**)(UINT16, UINT16, void *))(lbl_803C3C38 + 0x384))(sdp_result, 0, NULL);
        return;
    }
    if ((p_rec = SDP_FindServiceUUIDInDb(p_db, &hid_uuid, NULL)) == NULL) {
        (*(void (**)(UINT16, UINT16, void *))(lbl_803C3C38 + 0x384))(0xC, 0, NULL);
        return;
    }
    memset(p_nvi, 0, 0x74);
    if (((p_attr = fn_80095C64((void **)p_rec, 0x206)) == NULL)
        || ((*(UINT16 *)((u8 *)p_attr + 6) >> 12) != 6)
        || ((p_subattr1 = *(tSDP_DISC_ATTR **)((u8 *)p_attr + 8)) == NULL)
        || ((*(UINT16 *)((u8 *)p_subattr1 + 6) >> 12) != 6)
        || ((p_subattr2 = *(tSDP_DISC_ATTR **)((u8 *)p_subattr1 + 8)) == NULL)
        || ((p_repdesc = *(tSDP_DISC_ATTR **)p_subattr2) == NULL)
        || ((*(UINT16 *)((u8 *)p_repdesc + 6) >> 12) != 4)) {
        (*(void (**)(UINT16, UINT16, void *))(lbl_803C3C38 + 0x384))(0xD, 0, NULL);
        return;
    }
    len = *(UINT16 *)((u8 *)p_repdesc + 6) & 0xFFF;
    *(UINT16 *)(p_nvi + 0x68) = len;
    if (len != 0)
        *(u8 **)(p_nvi + 0x6C) = (u8 *)p_repdesc + 8;

    p_attr = fn_80095C64((void **)p_rec, 0x204);
    if (p_attr != NULL && *((u8 *)p_attr + 8)) attr_mask |= 1;
    p_attr = fn_80095C64((void **)p_rec, 0x205);
    if (p_attr != NULL && *((u8 *)p_attr + 8)) attr_mask |= 4;
    p_attr = fn_80095C64((void **)p_rec, 0x20D);
    if (p_attr != NULL && *((u8 *)p_attr + 8)) attr_mask |= 2;
    p_attr = fn_80095C64((void **)p_rec, 0x208);
    if (p_attr != NULL && *((u8 *)p_attr + 8)) attr_mask |= 8;
    p_attr = fn_80095C64((void **)p_rec, 0x209);
    if (p_attr != NULL && *((u8 *)p_attr + 8)) attr_mask |= 0x10;
    p_attr = fn_80095C64((void **)p_rec, 0x20A);
    if (p_attr != NULL && *((u8 *)p_attr + 8)) attr_mask |= 0x20;

    p_attr = fn_80095C64((void **)p_rec, 0x100);
    if (p_attr != NULL) {
        len = *(UINT16 *)((u8 *)p_attr + 6) & 0xFFF;
        if (len < 0x20) {
            memcpy(p_nvi, (u8 *)p_attr + 8, len);
            p_nvi[len] = 0;
        } else {
            memcpy(p_nvi, (u8 *)p_attr + 8, 0x1F);
            p_nvi[0x20] = 0;
        }
    } else
        p_nvi[0] = 0;

    p_attr = fn_80095C64((void **)p_rec, 0x101);
    if (p_attr != NULL) {
        len = *(UINT16 *)((u8 *)p_attr + 6) & 0xFFF;
        if (len < 0x20) {
            memcpy(p_nvi + 0x20, (u8 *)p_attr + 8, len);
            *(p_nvi + len + 0x20) = 0;
        } else {
            memcpy(p_nvi + 0x20, (u8 *)p_attr + 8, 0x1F);
            p_nvi[0x40] = 0;
        }
    } else
        p_nvi[0x20] = 0;

    p_attr = fn_80095C64((void **)p_rec, 0x102);
    if (p_attr != NULL) {
        len = *(UINT16 *)((u8 *)p_attr + 6) & 0xFFF;
        if (len < 0x20) {
            memcpy(p_nvi + 0x40, (u8 *)p_attr + 8, len);
            *(p_nvi + len + 0x40) = 0;
        } else {
            memcpy(p_nvi + 0x40, (u8 *)p_attr + 8, 0x1F);
            p_nvi[0x60] = 0;
        }
    } else
        p_nvi[0x40] = 0;

    p_attr = fn_80095C64((void **)p_rec, 0x200);
    if (p_attr != NULL) *(UINT16 *)(p_nvi + 0x60) = *(UINT16 *)((u8 *)p_attr + 8);
    p_attr = fn_80095C64((void **)p_rec, 0x203);
    if (p_attr != NULL) p_nvi[0x65] = *((u8 *)p_attr + 8);
    p_attr = fn_80095C64((void **)p_rec, 0x202);
    if (p_attr != NULL) p_nvi[0x64] = *((u8 *)p_attr + 8);
    p_attr = fn_80095C64((void **)p_rec, 0x201);
    if (p_attr != NULL) *(UINT16 *)(p_nvi + 0x62) = *(UINT16 *)((u8 *)p_attr + 8);
    p_attr = fn_80095C64((void **)p_rec, 0x20C);
    if (p_attr != NULL) {
        attr_mask |= 0x40;
        *(UINT16 *)(p_nvi + 0x66) = *(UINT16 *)((u8 *)p_attr + 8);
    }
    *(tSDP_DISC_REC **)(lbl_803C3C38 + 0x3FC) = p_rec;
    (*(void (**)(UINT16, UINT16, void *))(lbl_803C3C38 + 0x384))(0, attr_mask, lbl_803C3C38 + 0x38c);
}

void fn_800869CC(void) {
    u8 *p = lbl_803C3C38;
    memset(p, 0, 0x404);
    p[0x401] = 0;
}

extern u8 lbl_803C3C38[];
extern u8 lbl_803C3AF0[];
extern u8 hidh_conn_reg(void);
extern u8 hidh_conn_initiate();
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
    extern void fn_80070F90(void *);
    extern void fn_80089248(void);
    u8 *entry;
    u8 *base = lbl_803C3C38;
    u32 i;
    u32 offset;
    u8 one = 1;
    u8 zero = 0;

    if (base[0x400] == 0)
        return 1;
    for (i = 0; i < 0x10; i++) {
        u8 flag = base[0x400];
        u8 active;
        offset = ((u8)i) * 0x34;
        entry = base + offset;
        active = base[offset];
        if (active != 0 && flag != 0 && (u8)i <= 0x10) {
            entry[0xC] = one;
            fn_80070F90(entry + 0x1C);
            if (entry[0xA] == 1) {
                entry[0xC] = one;
                hidh_conn_disconnect((u8)i);
            }
            entry[0] = zero;
            entry[0x10] = zero;
            *(u16 *)(entry + 0x16) = 0;
            *(u16 *)(entry + 0x14) = 0;
        }
    }
    fn_80089248();
    lbl_803C3C38[0x400] = 0;
    return 0;
}

u8 HID_HostAddDev(u8 *addr, u16 attr_mask, u8 *handle) {
    u8 *entry;
    u8 *p;
    s32 i;
    s32 count;
    s32 offset;

    p = lbl_803C3C38;
    if (p[0x400] == 0)
        return 1;
    for (i = 0; i < 0x10; i++) {
        if (memcmp(addr, p + 1, 6) == 0)
            break;
        p += 0x34;
    }
    if (i == 0x10) {
        p = lbl_803C3C38;
        count = 0;
        if (p[0] == 0) goto scan_done; count++;
        if (p[0x34] == 0) goto scan_done; count++;
        if (p[0x68] == 0) goto scan_done; count++;
        if (p[0x9C] == 0) goto scan_done; count++;
        if (p[0xD0] == 0) goto scan_done; count++;
        if (p[0x104] == 0) goto scan_done; count++;
        if (p[0x138] == 0) goto scan_done; count++;
        if (p[0x16C] == 0) goto scan_done; count++;
        p += 0x1A0;
        count++;
        if (p[0] == 0) goto scan_done; count++;
        if (p[0x34] == 0) goto scan_done; count++;
        if (p[0x68] == 0) goto scan_done; count++;
        if (p[0x9C] == 0) goto scan_done; count++;
        if (p[0xD0] == 0) goto scan_done; count++;
        if (p[0x104] == 0) goto scan_done; count++;
        if (p[0x138] == 0) goto scan_done; count++;
        if (p[0x16C] == 0) goto scan_done; count++;
scan_done:
        i = count;
        if (i == 0x10)
            return 3;
    }
    offset = i * 0x34;
    entry = lbl_803C3C38 + offset;
    if (entry[0] == 0) {
        entry[0] = 1;
        memcpy(entry + 1, addr, 6);
        entry[0xA] = 0;
        entry[0xC] = 0;
    }
    *(u16 *)(entry + 8) = attr_mask;
    *handle = i;
    return 0;
}

#pragma pop

#pragma push
#pragma use_lmw_stmw off
u8 HID_HostRemoveDev(u32 dev_handle) {
    extern u8 hidh_conn_disconnect(u32);
    register tHID_HOST_DEV_VIEW *devices = (tHID_HOST_DEV_VIEW *)lbl_803C3C38;
    u32 offset;

    if (lbl_803C3C38[0x400] == 0)
        return 1;
    if (dev_handle > 0x10)
        return 5;
    offset = dev_handle * 0x34;
    if (devices[dev_handle].in_use == 0)
        return 5;
    if (devices[dev_handle].state == 1) {
        devices[dev_handle].conn_tries = 1;
        fn_80070F90(devices[dev_handle].timer_entry);
        if (devices[dev_handle].state == 1) {
            devices[dev_handle].conn_tries = 1;
            hidh_conn_disconnect(dev_handle);
        }
    }
    devices[dev_handle].in_use = 0;
    lbl_803C3C38[offset + 0x10] = 0;
    *(u16 *)(lbl_803C3C38 + offset + 0x16) = 0;
    *(u16 *)(lbl_803C3C38 + offset + 0x14) = 0;
    return 0;
}
#pragma pop
u8 HID_HostOpenDev(u32 arg0) {
    u8 *entry = lbl_803C3C38;
    s32 offset;
    if (entry[0x400] == 0)
        return 1;
    if (arg0 <= 0x10) {
        offset = arg0 * 0x34;
        if (entry[offset] == 0)
            return 5;
    }
    entry += offset;
    if (entry[0xA] != 0)
        return 10;
    entry[0xC] = 1;
    return hidh_conn_initiate();
}

u8 HID_HostCloseDev(u8 dev_handle) {
    extern u8 hidh_conn_disconnect(u32);
    register tHID_HOST_DEV_VIEW *devices = (tHID_HOST_DEV_VIEW *)lbl_803C3C38;
    if (lbl_803C3C38[0x400] == 0) {
        return 1;
    }
    if (dev_handle > 0x10 || devices[dev_handle].in_use == 0) {
        return 5;
    }
    devices[dev_handle].conn_tries = 1;
    fn_80070F90(devices[dev_handle].timer_entry);
    if (devices[dev_handle].state != 1) {
        return 4;
    }
    devices[dev_handle].conn_tries = 1;
    return hidh_conn_disconnect(dev_handle);
}

s32 HID_HostSetSecurityLevel(void *p_name, u8 sec_level) {
    char *messages = lbl_80317720;
    if (!BTM_SetSecurityLevel(0, p_name, 0x20, sec_level, 0x11, 6, 1)) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0x54);
        return 3;
    }
    if (!BTM_SetSecurityLevel(1, p_name, 0x20, sec_level, 0x11, 6, 1)) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0x74);
        return 3;
    }
    if (!BTM_SetSecurityLevel(0, p_name, 0x21, 0, 0x11, 6, 2)) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0x94);
        return 3;
    }
    if (!BTM_SetSecurityLevel(1, p_name, 0x21, 0, 0x11, 6, 2)) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0xB4);
        return 3;
    }
    if (!BTM_SetSecurityLevel(1, p_name, 0x22, 0, 0x13, 6, 0)) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0xD4);
        return 3;
    }
    if (!BTM_SetSecurityLevel(0, p_name, 0x22, 0, 0x13, 6, 0)) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0xF4);
        return 3;
    }
    return 0;
}

u8 hidh_conn_reg(void) {
    extern unsigned char lbl_803C3C38[];
    extern unsigned char lbl_802EEC18[];
    extern char lbl_80317838[];
    extern char lbl_80317858[];
    unsigned char *cb = lbl_803C3C38;
    UINT16 (*reg)(UINT16, void *, ...) = (UINT16 (*)(UINT16, void *, ...))L2CA_Register;

    cb[0x346] = 1;
    *(UINT16 *)(cb + 0x348) = 0x280;
    cb[0x364] = 1;
    *(UINT16 *)(cb + 0x366) = 0xFFFF;
    if (reg(0x11, lbl_802EEC18, 0x280, 1) == 0) {
        if (cb[0x401] >= 1) fn_8007093C(0x1E0000, lbl_80317838);
        return 0xE;
    }
    if (reg(0x13, lbl_802EEC18) == 0) {
        L2CA_Deregister(0x11);
        if (cb[0x401] >= 1) fn_8007093C(0x1E0000, lbl_80317858);
        return 0xE;
    }
    cb[0] = cb[0x10] = cb[0x34] = cb[0x44] = cb[0x68] = cb[0x78] = 0;
    cb[0x9C] = cb[0xAC] = cb[0xD0] = cb[0xE0] = cb[0x104] = cb[0x114] = 0;
    cb[0x138] = cb[0x148] = cb[0x16C] = cb[0x17C] = cb[0x1A0] = cb[0x1B0] = 0;
    cb[0x1D4] = cb[0x1E4] = cb[0x208] = cb[0x218] = cb[0x23C] = cb[0x24C] = 0;
    cb[0x270] = cb[0x280] = cb[0x2A4] = cb[0x2B4] = cb[0x2D8] = cb[0x2E8] = 0;
    cb[0x30C] = cb[0x31C] = 0;
    return 0;
}

u8 hidh_conn_disconnect(u32 index) {
    u8 *conn;

    conn = lbl_803C3C38 + index * 0x34;
    if (lbl_803C3C38[0x401] >= 4) {
        fn_8007093C(0x1E0003, lbl_8031787C);
    }
    if (*(u16 *)(conn + 0x14) == 0) {
        if (*(u16 *)(conn + 0x16) == 0) {
            goto clear_state;
        }
    }
    conn[0x10] = 5;
    if (*(u16 *)(conn + 0x16) != 0) {
        L2CA_DisconnectReq(*(u16 *)(conn + 0x16));
    }
    if (*(u16 *)(conn + 0x14) != 0) {
        L2CA_DisconnectReq(*(u16 *)(conn + 0x14));
    }
    goto done;
clear_state:
    conn[0x10] = 0;
done:
    return 0;
}

extern u8 lbl_8031787C[];
void hidh_sec_check_complete_term(u8 *bd_addr, void *p_ref_data, u8 res) {
    u8 *cb = lbl_803C3C38;
    u8 *conn = p_ref_data;
    u8 index = (u8)(((u8 *)p_ref_data - cb) / 0x34);
    u8 *record;
    if (res == 0 && conn[0x10] == 6) {
        *(u16 *)(conn + 0x1A) = 0;
        conn[0x10] = 2;
        L2CA_ConnectRsp(conn + 1, conn[0x12], *(u16 *)(conn + 0x14), 0, 0);
        L2CA_ConfigReq(*(u16 *)(conn + 0x14), (void *)(cb + 0x344));
        return;
    }
    if (res != 0) {
        *(u16 *)(conn + 0x1A) = 0xF;
        record = lbl_803C3C38 + index * 0x34;
        if (lbl_803C3C38[0x401] >= 4) fn_8007093C(0x1E0003, lbl_8031787C);
        if (*(u16 *)(record + 0x14) != 0 || *(u16 *)(record + 0x16) != 0) {
            record[0x10] = 5;
            if (*(u16 *)(record + 0x16) != 0) L2CA_DisconnectReq(*(u16 *)(record + 0x16));
            if (*(u16 *)(record + 0x14) != 0) L2CA_DisconnectReq(*(u16 *)(record + 0x14));
        } else {
            record[0x10] = 0;
        }
    }
}

extern char lbl_8031799C[];
void hidh_proc_repage_timeout(TIMER_LIST_ENT *p_tle) {
    UINT32 handle = p_tle->param;
    UINT8 index = (UINT8)handle;
    UINT8 *dev = lbl_803C3C38 + index * 0x34;
    UINT16 cid;
    UINT32 dhandle;
    void (**callback)(UINT8, UINT32, UINT8, void *) =
        (void (**)(UINT8, UINT32, UINT8, void *))(lbl_803C3C38 + 0x340);
    if (dev[0x10] == 0) {
        *(UINT16 *)(dev + 0x14) = 0;
        *(UINT16 *)(dev + 0x16) = 0;
        *(UINT16 *)(dev + 0x1A) = 0x100;
        dev[0x11] = 1;
        cid = L2CA_ConnectReq(0x11, dev + 1);
        *(UINT16 *)(dev + 0x14) = cid;
        if (cid == 0) {
            if (lbl_803C3C38[0x401] >= 2)
                fn_8007093C(0x1E0001, lbl_8031799C);
            dhandle = (dev - lbl_803C3C38) / 0x34;
            (*callback)(dhandle, 1, 0xE, 0);
        } else {
            dev[0x10] = 1;
        }
    }
    handle = p_tle->param;
    dev = lbl_803C3C38 + handle * 0x34;
    dev[0xC]++;
    (*callback)(handle, 2, dev[0xC], 0);
}

void hidh_sec_check_complete_orig(BD_ADDR bd_addr, void *p_ref_data, UINT8 res) {
    u8 *p_dev = (u8 *)p_ref_data;
    char *strings = lbl_80317838;
    u8 dhandle = (u8)((p_dev - lbl_803C3C38) / 0x34);
    u8 *record_failure;
    u8 *record_success;
    u16 cid;

    if (res == 0 && p_dev[0x10] == 6) {
        if (lbl_803C3C38[0x401] >= 4)
            fn_8007093C(0x1E0003, strings + 0x180);
        *(u16 *)(p_dev + 0x1A) = 0;
        record_success = lbl_803C3C38 + dhandle * 0x34;
        cid = L2CA_ConnectReq(0x13, record_success + 1);
        *(u16 *)(p_dev + 0x16) = cid;
        if (cid == 0) {
            if (lbl_803C3C38[0x401] >= 2)
                fn_8007093C(0x1E0001, strings + 0x1A0);
            if (lbl_803C3C38[0x401] >= 4)
                fn_8007093C(0x1E0003, strings + 0x44);
            if (*(u16 *)(record_success + 0x14) != 0 || *(u16 *)(record_success + 0x16) != 0) {
                record_success[0x10] = 5;
                if (*(u16 *)(record_success + 0x16) != 0)
                    L2CA_DisconnectReq(*(u16 *)(record_success + 0x16));
                if (*(u16 *)(record_success + 0x14) != 0)
                    L2CA_DisconnectReq(*(u16 *)(record_success + 0x14));
            } else {
                record_success[0x10] = 0;
            }
            ((void (*)(u8, u32, u32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(dhandle, 1, 0x200, 0);
            return;
        }
        p_dev[0x10] = 2;
    }
    if (res != 0 && p_dev[0x10] == 6) {
        *(u16 *)(p_dev + 0x1A) = 0xF;
        record_failure = lbl_803C3C38 + dhandle * 0x34;
        if (lbl_803C3C38[0x401] >= 4)
            fn_8007093C(0x1E0003, strings + 0x44);
        if (*(u16 *)(record_failure + 0x14) != 0 || *(u16 *)(record_failure + 0x16) != 0) {
            record_failure[0x10] = 5;
            if (*(u16 *)(record_failure + 0x16) != 0)
                L2CA_DisconnectReq(*(u16 *)(record_failure + 0x16));
            if (*(u16 *)(record_failure + 0x14) != 0)
                L2CA_DisconnectReq(*(u16 *)(record_failure + 0x14));
        } else {
            record_failure[0x10] = 0;
        }
    }
}

static void hidh_l2cif_connect_cfm(u32 l2cap_cid, s32 result) {
    char *strings = lbl_80317838;
    UINT8 dhandle;
    UINT8 *p_hcon = NULL;
    UINT8 *p_dev = NULL;
    UINT8 *entry;

    for (dhandle = 0; dhandle < 0x10; dhandle++) {
        entry = lbl_803C3C38 + dhandle * 0x34;
        if (entry[0] != 0 && entry[0x10] != 0 &&
            (l2cap_cid == *(UINT16 *)(entry + 0x14) ||
             l2cap_cid == *(UINT16 *)(entry + 0x16))) break;
    }
    if (dhandle != 0x10) {
        p_dev = lbl_803C3C38 + dhandle * 0x34;
        p_hcon = p_dev + 0x10;
    }
    if (p_hcon == NULL || (p_hcon[1] & 1) == 0 ||
        (l2cap_cid == *(UINT16 *)(p_hcon + 4) && p_hcon[0] != 1) ||
        (l2cap_cid == *(UINT16 *)(p_hcon + 6) && p_hcon[0] != 2)) {
        if (lbl_803C3C38[0x401] >= 2)
            ((void (*)(u32, void *, u32))fn_80070954)(
                0x1E0001, strings + 0x1BC, l2cap_cid);
        return;
    }
    if (result != 0) {
        if (l2cap_cid == *(UINT16 *)(p_hcon + 4))
            *(UINT16 *)(p_hcon + 4) = 0;
        else
            *(UINT16 *)(p_hcon + 6) = 0;
        p_dev = lbl_803C3C38 + dhandle * 0x34;
        if (lbl_803C3C38[0x401] >= 4)
            fn_8007093C(0x1E0003, strings + 0x44);
        if (*(UINT16 *)(p_dev + 0x14) != 0 || *(UINT16 *)(p_dev + 0x16) != 0) {
            p_dev[0x10] = 5;
            if (*(UINT16 *)(p_dev + 0x16) != 0)
                L2CA_DisconnectReq(*(UINT16 *)(p_dev + 0x16));
            if (*(UINT16 *)(p_dev + 0x14) != 0)
                L2CA_DisconnectReq(*(UINT16 *)(p_dev + 0x14));
        } else {
            p_dev[0x10] = 0;
        }
        ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
            dhandle, 1, result | 0x100, 0);
        return;
    }
    if (l2cap_cid == *(UINT16 *)(p_hcon + 4)) {
        p_hcon[0] = 6;
        *(UINT16 *)(p_hcon + 0xA) = 0x100;
        {
            u16 attr = *(UINT16 *)(p_dev + 8);
            s32 secLevel = (attr & 0x8000) ? 1 : 2;
            btm_sec_mx_access_request(
                p_dev + 1, 0x11, 1, 6, secLevel,
                &hidh_sec_check_complete_orig, p_dev);
        }
    } else {
        p_hcon[0] = 3;
    }
    ((void (*)(u32, void *))L2CA_ConfigReq)(
        l2cap_cid, (void *)(lbl_803C3C38 + 0x344));
    if (lbl_803C3C38[0x401] >= 4)
        ((void (*)(u32, void *, u32))fn_80070954)(
            0x1E0003, strings + 0x1E8, l2cap_cid);
}

static void hidh_l2cif_config_ind(UINT16 l2cap_cid, tL2CAP_CFG_INFO *p_cfg)
{
    UINT8 dhandle;
    UINT8 *p_hcon = NULL;

    for (dhandle = 0; dhandle < 0x10; dhandle++) {
        UINT8 *p_dev = lbl_803C3C38 + dhandle * 0x34;
        if (p_dev[0] != 0 && p_dev[0x10] != 0 &&
            (l2cap_cid == *(UINT16 *)(p_dev + 0x14) ||
             l2cap_cid == *(UINT16 *)(p_dev + 0x16)))
            break;
    }

    if (dhandle != 0x10)
        p_hcon = lbl_803C3C38 + dhandle * 0x34 + 0x10;

    if (p_hcon == NULL) {
        if (lbl_803C3C38[0x401] >= 2)
            fn_80070954(0x1E0001, lbl_80317A54, l2cap_cid);
    } else {
        if (lbl_803C3C38[0x401] >= 4)
            fn_80070954(0x1E0003, lbl_80317A80, l2cap_cid);

        if (!p_cfg->mtu_present || p_cfg->mtu > 0x280)
            *(UINT16 *)(p_hcon + 8) = 0x280;
        else
            *(UINT16 *)(p_hcon + 8) = p_cfg->mtu;

        p_cfg->flush_to_present = 0;
        p_cfg->mtu_present = 0;
        p_cfg->result = 0;
        L2CA_ConfigRsp(l2cap_cid, p_cfg);

        if (l2cap_cid == *(UINT16 *)(p_hcon + 4))
            p_hcon[1] |= 2;
        else
            p_hcon[1] |= 8;

        if ((p_hcon[1] & 0x1E) == 0x1E && p_hcon[0] == 3) {
            p_hcon[0] = 4;
            *(UINT8 *)(lbl_803C3C38 + dhandle * 0x34 + 0xA) = 1;
            ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(dhandle, 0, 0, 0);
        }
    }
}

static void hidh_l2cif_config_cfm(u32 l2cap_cid, UINT16 *p_result) {
    char *strings = lbl_80317838;
    UINT8 dhandle;
    UINT8 *p_dev;
    UINT8 *p_hcon = NULL;

    if (lbl_803C3C38[0x401] >= 4)
        ((void (*)(u32, void *, u32, u16))fn_8007096C)(0x1E0003, strings + 0x274, l2cap_cid, *p_result);

    for (dhandle = 0; dhandle < 0x10; dhandle++) {
        p_dev = lbl_803C3C38 + dhandle * 0x34;
        if (p_dev[0] != 0 && p_dev[0x10] != 0 &&
            (l2cap_cid == *(UINT16 *)(p_dev + 0x14) ||
             l2cap_cid == *(UINT16 *)(p_dev + 0x16)))
            break;
    }

    if (dhandle != 0x10)
        p_hcon = lbl_803C3C38 + dhandle * 0x34 + 0x10;

    if (p_hcon == NULL) {
        if (lbl_803C3C38[0x401] >= 2)
            ((void (*)(u32, void *, u32))fn_80070954)(0x1E0001, strings + 0x21C, l2cap_cid);
        return;
    }

    if (*p_result != 0) {
        p_dev = lbl_803C3C38 + dhandle * 0x34;
        if (lbl_803C3C38[0x401] >= 4)
            fn_8007093C(0x1E0003, strings + 0x44);
        if (*(UINT16 *)(p_dev + 0x14) != 0 || *(UINT16 *)(p_dev + 0x16) != 0) {
            p_dev[0x10] = 5;
            if (*(UINT16 *)(p_dev + 0x16) != 0)
                L2CA_DisconnectReq(*(UINT16 *)(p_dev + 0x16));
            if (*(UINT16 *)(p_dev + 0x14) != 0)
                L2CA_DisconnectReq(*(UINT16 *)(p_dev + 0x14));
        } else {
            p_dev[0x10] = 0;
        }
        ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
            dhandle, 1, *p_result | 0x400, 0);
        return;
    }

    if (l2cap_cid == *(UINT16 *)(p_hcon + 4))
        p_hcon[1] |= 4;
    else
        p_hcon[1] |= 0x10;

    if ((p_hcon[1] & 0x1E) == 0x1E && p_hcon[0] == 3) {
        p_hcon[0] = 4;
        p_dev = lbl_803C3C38 + dhandle * 0x34;
        p_dev[0xA] = 1;
        ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
            dhandle, 0, 0, 0);
    }
}

extern char lbl_80317AD8[];
extern char lbl_80317B04[];
static void hidh_l2cif_disconnect_ind(UINT16 l2cap_cid, BOOLEAN ack_needed)
{
    UINT8 dhandle;
    UINT8 *p_hcon = NULL;
    UINT16 disc_res = 0;
    UINT16 hid_close_evt_reason;

    for (dhandle = 0; dhandle < 0x10; dhandle++) {
        UINT8 *p_dev = lbl_803C3C38 + dhandle * 0x34;
        if (p_dev[0] != 0 && p_dev[0x10] != 0 &&
            (l2cap_cid == *(UINT16 *)(p_dev + 0x14) ||
             l2cap_cid == *(UINT16 *)(p_dev + 0x16)))
            break;
    }

    if (dhandle != 0x10)
        p_hcon = lbl_803C3C38 + dhandle * 0x34 + 0x10;

    if (p_hcon == NULL) {
        if (lbl_803C3C38[0x401] >= 2)
            fn_80070954(0x1E0001, lbl_80317AD8, l2cap_cid);
    } else {
        if (ack_needed)
            L2CA_DisconnectRsp(l2cap_cid);

        if (lbl_803C3C38[0x401] >= 4)
            fn_80070954(0x1E0003, lbl_80317B04, l2cap_cid);

        p_hcon[0] = 5;
        if (l2cap_cid == *(UINT16 *)(p_hcon + 4))
            *(UINT16 *)(p_hcon + 4) = 0;
        else
            *(UINT16 *)(p_hcon + 6) = 0;

        if (*(UINT16 *)(p_hcon + 4) == 0 && *(UINT16 *)(p_hcon + 6) == 0) {
            *(UINT8 *)(lbl_803C3C38 + dhandle * 0x34 + 0xA) = 0;
            p_hcon[0] = 0;

            if (!ack_needed)
                disc_res = ((UINT16 (*)(void))fn_80077DD8)();

            hid_close_evt_reason = *(UINT16 *)(p_hcon + 0xA);
            if (disc_res == 5 || disc_res == 6 || disc_res == 0xE ||
                disc_res == 0x18 || disc_res == 0x26 || disc_res == 0x29 ||
                disc_res == 0x25 || disc_res == 0x17)
                hid_close_evt_reason = 0xF;

            ((void (*)(UINT8, UINT32, UINT16, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
                dhandle, 1, hid_close_evt_reason, 0);
        }
    }
}

extern char lbl_80317B28[];
extern char lbl_80317B58[];
void hidh_l2cif_disconnect_cfm(u32 handle) {
    u8 index = 0;
    u8 *entry;
    u8 *dev = 0;
    u32 i;

    for (i = 0; i < 4; i++) {
        entry = lbl_803C3C38 + index * 0x34;
        if (entry[0] != 0 && entry[0x10] != 0 &&
            (handle == *(u16 *)(entry + 0x14) ||
             handle == *(u16 *)(entry + 0x16))) {
            dev = entry + 0x10;
            break;
        }
        index++;
    }
    if (dev == 0 && index != 4) {
        entry = lbl_803C3C38 + index * 0x34;
        dev = entry + 0x10;
    }
    if (dev == 0) {
        if (lbl_803C3C38[0x401] >= 2)
            fn_80070954(0x1E0001, lbl_80317B28, (u16)handle);
    } else {
        if (lbl_803C3C38[0x401] >= 4)
            fn_80070954(0x1E0003, lbl_80317B58, (u16)handle);
        if (handle == *(u16 *)(dev + 4))
            *(u16 *)(dev + 4) = 0;
        else
            *(u16 *)(dev + 6) = 0;
        if (*(u16 *)(dev + 4) == 0 && *(u16 *)(dev + 6) == 0) {
            entry[0xA] = 0;
            dev[0] = 0;
            ((void (*)(u8, u32, u32, u32, u32, u32))
                (*(void **)(lbl_803C3C38 + 0x340)))(index, 1, *(u16 *)(dev + 0xA), 0,
                                                    (u32)lbl_803C3C38, 0);
        }
    }
}

extern u8 lbl_80317B80[];
extern u8 lbl_80317BB8[];
void hidh_l2cif_cong_ind(u32 arg0, s32 arg1) {
    u32 i;
    u8 *entry;
    u8 *found;

    found = 0;
    for (i = 0; i < 16; i++) {
        entry = (u8 *)lbl_803C3C38 + i * 0x34;
        if (entry[0] != 0 && entry[0x10] != 0 &&
            (arg0 == *(u16 *)(entry + 0x14) ||
             arg0 == *(u16 *)(entry + 0x16))) {
            found = entry + 0x10;
            break;
        }
    }
    if (found == 0) {
        if (*((u8 *)lbl_803C3C38 + 0x401) >= 2)
            ((void (*)(u32, void *, u32, u32))fn_80070954)(0x1E0001, lbl_80317B80, arg0, 0x1E0000);
    } else {
        if (*((u8 *)lbl_803C3C38 + 0x401) >= 4)
            ((void (*)(u32, void *, u32, s32, u32))fn_8007096C)(0x1E0003, lbl_80317BB8, arg0, arg1, 0x1E0000);
        if (arg1 != 0)
            found[1] |= 0x20;
        else
            found[1] &= ~0x20;
    }
}

extern u8 lbl_80317BF0[];
static void hidh_l2cif_data_ind(UINT16 l2cap_cid, BT_HDR *p_msg) {
    UINT8 *p_data = (UINT8 *)(p_msg + 1) + p_msg->offset;
    UINT8 ttype, param, rep_type, evt;
    UINT8 dhandle;
    UINT8 *entry;
    UINT8 *p_hcon = NULL;
    UINT8 *p_dev = NULL;

    for (dhandle = 0; dhandle < 0x10; dhandle++) {
        entry = lbl_803C3C38 + dhandle * 0x34;
        if (entry[0] != 0 && entry[0x10] != 0 &&
            (l2cap_cid == *(UINT16 *)(entry + 0x14) ||
             l2cap_cid == *(UINT16 *)(entry + 0x16))) {
            break;
        }
    }

    if (dhandle != 0x10) {
        p_hcon = lbl_803C3C38 + dhandle * 0x34 + 0x10;
    }

    if (p_hcon == NULL) {
        if (lbl_803C3C38[0x401] >= 2) {
            fn_80070954(0x1E0001, lbl_80317BF0, l2cap_cid);
        }
        GKI_freebuf(p_msg);
        return;
    }

    ttype = (*p_data >> 4) & 0xF;
    param = *p_data & 0xF;
    rep_type = param & 3;
    p_data++;
    p_msg->len--;
    p_msg->offset++;

    switch (ttype) {
    case 0:
        ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
            dhandle, 7, param, NULL);
        GKI_freebuf(p_msg);
        break;

    case 1:
        switch (param) {
        case 5:
            p_dev = lbl_803C3C38 + dhandle * 0x34;
            if (lbl_803C3C38[0x401] >= 4) {
                fn_8007093C(0x1E0003, lbl_8031787C);
            }
            if (*(UINT16 *)(p_dev + 0x14) != 0 ||
                *(UINT16 *)(p_dev + 0x16) != 0) {
                p_dev[0x10] = 5;
                if (*(UINT16 *)(p_dev + 0x16) != 0) {
                    L2CA_DisconnectReq(*(UINT16 *)(p_dev + 0x16));
                }
                if (*(UINT16 *)(p_dev + 0x14) != 0) {
                    L2CA_DisconnectReq(*(UINT16 *)(p_dev + 0x14));
                }
            } else {
                p_dev[0x10] = 0;
            }
            ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
                dhandle, 8, 0, NULL);
            break;
        default:
            break;
        }
        GKI_freebuf(p_msg);
        break;

    case 0xA:
        evt = (*(UINT16 *)(lbl_803C3C38 + dhandle * 0x34 + 0x16) == l2cap_cid) ? 3 : 5;
        ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
            dhandle, evt, rep_type, p_msg);
        break;

    case 0xB:
        evt = (*(UINT16 *)(lbl_803C3C38 + dhandle * 0x34 + 0x16) == l2cap_cid) ? 4 : 6;
        ((void (*)(UINT8, UINT32, UINT32, void *))(*(void **)(lbl_803C3C38 + 0x340)))(
            dhandle, evt, rep_type, p_msg);
        break;

    default:
        GKI_freebuf(p_msg);
        break;
    }
}

extern UINT8 L2CA_DataWrite(UINT16, BT_HDR *);
UINT8 hidh_conn_snd_data(UINT8 dhandle, s32 trans_type, UINT8 param,
                         UINT16 data, UINT8 rpt_id, BT_HDR *buf) {
    register s32 var_r17;
    register s32 var_r20;
    register s32 var_r4;
    register u16 temp_r24;
    register u16 var_r23;
    register u16 var_r24;
    register u16 var_r25;
    register u32 var_r21;
    register s32 var_r22;
    u8 *temp_r27;
    void *temp_r3;
    void *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    BT_HDR *var_r26;
    register u8 var_r30;
    register u8 var_r29;
    register u8 var_r28;
    register u8 var_r31;

    var_r17 = (s32)trans_type;
    temp_r27 = lbl_803C3C38 + (dhandle * 0x34);
    var_r21 = 0;
    var_r20 = 0;
    if (temp_r27[0x11] & 0x20) {
        if (buf != NULL) GKI_freebuf(buf);
        return 8;
    }
    if (trans_type < 4) {
        if (trans_type != 1) goto block_11;
        goto block_9;
    }
    if (trans_type != 0xA) {
        if (trans_type < 0xA) goto block_9;
        goto block_11;
    }
    goto block_10;
block_9:
    var_r23 = *(u16 *)(temp_r27 + 0x14);
    var_r22 = 2;
    goto block_12;
block_10:
    var_r23 = *(u16 *)(temp_r27 + 0x16);
    var_r22 = 2;
    goto block_12;
block_11:
    return 5;
block_12:
    if ((u32)trans_type == 9U) {
        var_r21 = 1;
    } else if ((u32)trans_type == 4U && (param & 8)) {
        var_r21 = 2;
    }
    var_r30 = param & 0xF;
    var_r29 = (u8)data;
    var_r28 = (u8)(data >> 8);
    var_r31 = 9;
loop_18:
    if (buf == NULL || var_r20 != 0) {
allocate_new:
        temp_r3 = GKI_getpoolbuf(var_r22);
        var_r26 = (BT_HDR *)temp_r3;
        if (temp_r3 == NULL) return 3;
        var_r26->offset = var_r31;
        var_r4 = 0;
        var_r24 = 0;
        var_r25 = 0;
        var_r20 = 0;
        goto block_28;
    }
use_existing:
    var_r24 = buf->len;
    if ((s32)var_r24 > (s32)(*(u16 *)(temp_r27 + 0x18) - 1)) {
        temp_r3_2 = GKI_getpoolbuf(var_r22);
        var_r26 = (BT_HDR *)temp_r3_2;
        if (temp_r3_2 == NULL) return 3;
        var_r26->offset = var_r31;
        var_r4 = 1;
        var_r24 = buf->len;
        var_r25 = *(u16 *)(temp_r27 + 0x18) - 1;
        goto block_28;
    }
    var_r26 = buf;
    var_r25 = var_r24;
    var_r4 = 0;
    buf->offset--;
block_28:
    temp_r3_3 = (u8 *)var_r26 + var_r26->offset;
    temp_r3_3[8] = (u8)(((var_r17 * 0x10) & 0xFF0) | var_r30);
    temp_r3_4 = temp_r3_3 + 9;
    if (var_r17 == 4 && rpt_id != 0) {
        temp_r3_4[0] = rpt_id;
        var_r25 = 1;
        var_r24 = 1;
    }
    if (var_r4 != 0) {
        memcpy(temp_r3_4, (u8 *)buf + buf->offset + 8, var_r25);
        buf->offset += var_r25;
        buf->len -= var_r25;
    } else if (var_r21 == 1) {
        temp_r3_4[var_r25] = var_r29;
    } else if (var_r21 == 2) {
        u8 *write_ptr = temp_r3_4 + var_r25;
        *write_ptr++ = var_r29;
        *write_ptr = var_r28;
    }
    temp_r24 = var_r24 - var_r25;
    var_r26->len = var_r25 + var_r21 + 1;
    if ((temp_r27[0x11] & 0x20) || L2CA_DataWrite(var_r23, var_r26) == 0) return 8;
    if (temp_r24 != 0) {
        var_r17 = 0xB;
        goto loop_18;
    }
    if ((s32)var_r25 == (s32)(*(u16 *)(temp_r27 + 0x18) - 1)) {
        var_r17 = 0xB;
        var_r20 = 1;
        goto loop_18;
    }
    if (var_r20 != 0) goto loop_18;
    return 0;
}

u8 hidh_conn_initiate(u32 dev_handle) {
    u8 *entry = lbl_803C3C38 + dev_handle * 0x34;
    u16 cid;
    u32 dhandle;

    if (entry[0x10] != 0)
        return 9;

    *(u16 *)(entry + 0x14) = 0;
    *(u16 *)(entry + 0x16) = 0;
    *(u16 *)(entry + 0x1a) = 0x100;
    entry[0x11] = 1;
    cid = L2CA_ConnectReq(0x11, entry + 1);
    *(u16 *)(entry + 0x14) = cid;

    if (cid == 0) {
        if (lbl_803C3C38[0x401] >= 2)
            fn_8007093C(0x1e0001, lbl_8031799C);
        dhandle = (u32)((entry - lbl_803C3C38) / 0x34) / 0x34U;
        ((void (*)(u8, u32, u8, void *))(*(void **)(lbl_803C3C38 + 0x340)))((u8)dhandle, 1, 0xe, 0);
    } else {
        entry[0x10] = 1;
    }
    return 0;
}

extern char lbl_80317CC8[];
extern char lbl_80317CFC[];
extern char lbl_80318C8C[];
void fn_80089248(void)
{
    L2CA_Deregister(0x11);
    L2CA_Deregister(0x13);
}

UINT16 L2CA_Register(UINT16 psm, tL2CAP_APPL_INFO *info) {
    extern void *l2cu_find_rcb_by_psm(UINT16);
    extern void *fn_8008EBE4(s16);
    u8 *messages = lbl_80317C20;
    void *entry;
    u32 *src = (u32 *)info;
    u32 *dst;
    u32 a, b;

    if (lbl_803C4040[0] >= 3) fn_80070954(0x80002, messages, psm);
    if (*(u32 *)((u8 *)info + 0x10) == 0 ||
        *(u32 *)((u8 *)info + 0xC) == 0 ||
        *(u32 *)((u8 *)info + 0x20) == 0 ||
        *(u32 *)((u8 *)info + 0x14) == 0) {
        if (lbl_803C4040[0] >= 1) fn_80070954(0x80000, messages + 0x30, psm);
        return 0;
    }
    if ((psm & 0x101) != 1) {
        if (lbl_803C4040[0] >= 1) fn_80070954(0x80000, messages + 0x58, psm);
        return 0;
    }
    entry = l2cu_find_rcb_by_psm(psm);
    if (entry == 0) {
        entry = ((void *(*)(UINT16))fn_8008EBE4)(psm);
        if (entry == 0) {
            if (lbl_803C4040[0] >= 2) fn_80070954(0x80001, messages + 0x80, psm);
            return 0;
        }
    }
    dst = (u32 *)entry;
    a = src[1]; b = src[0]; dst[1] = b; dst[2] = a;
    a = src[3]; b = src[2]; dst[3] = b; dst[4] = a;
    a = src[5]; b = src[4]; dst[5] = b; dst[6] = a;
    a = src[7]; b = src[6]; dst[7] = b; dst[8] = a;
    a = src[9]; b = src[8]; dst[9] = b; dst[10] = a;
    return 1;
}

void L2CA_Deregister(UINT16 psm) {
    extern void *l2cu_find_rcb_by_psm(UINT16);
    extern void fn_8008EC30(void *);
    void *rcb;
    if (lbl_803C4040[0] >= 3) {
        fn_80070954(0x80002, lbl_80317CC8, psm);
    }
    rcb = l2cu_find_rcb_by_psm(psm);
    if (rcb != 0) {
        fn_8008EC30(rcb);
        return;
    }
    if (lbl_803C4040[0] >= 2) {
        fn_80070954(0x80001, lbl_80317CFC, psm);
    }
}

BOOLEAN L2CA_ConnectRsp(BD_ADDR addr, UINT8 id, UINT16 lcid, UINT16 result, UINT16 status) {
 void *lcb,*ccb; s16 info[2];
 if(lbl_803C4040[0]>=3)fn_80070984(0x80002,lbl_80317C20+0x26C);
 if(lbl_803C4040[0]>=3)fn_800709CC(0x80002,lbl_80317C20+0x2A4,addr[0],addr[1],addr[2],addr[3],addr[4],addr[5]);
 lcb=l2cu_find_lcb_by_bd_addr(addr);
 if(!lcb){if(lbl_803C4040[0]>=2)fn_8007093C(0x80001,lbl_80317C20+0x2DC);return 0;}
 ccb=l2cu_find_ccb_by_cid(lcb,lcid);
 if(!ccb){if(lbl_803C4040[0]>=2)fn_8007093C(0x80001,lbl_80317C20+0x300);return 0;}
 if(*(u8 *)((u8 *)ccb+0x36)!=id){if(lbl_803C4040[0]>=2)fn_8007096C(0x80001,lbl_80317C20+0x324,0,id);return 0;}
 if(result==0)fn_80089E40(ccb,0x15,NULL);
 else{info[0]=result;info[1]=status;if(result==1)fn_80089E40(ccb,0x15,info);else fn_80089E40(ccb,0x16,info);}
 return 1;
}

BOOLEAN L2CA_ConfigRsp(UINT16 cid, tL2CAP_CFG_INFO *p_cfg) {
    extern char lbl_80317FC4[];
    extern char lbl_80317FF0[];
    void *p_ccb;

    if (lbl_803C4040[0] >= 3)
        fn_8007096C(0x80002, lbl_80317FC4, cid, p_cfg->result);

    p_ccb = l2cu_find_ccb_by_cid(NULL, cid);
    if (p_ccb == NULL) {
        if (lbl_803C4040[0] >= 2)
            fn_80070954(0x80001, lbl_80317FF0, cid);
        return FALSE;
    }

    if (p_cfg->result == 0)
        fn_80089E40(p_ccb, 0x18, p_cfg);
    else
        fn_80089E40(p_ccb, 0x19, p_cfg);
    return TRUE;
}

BOOLEAN L2CA_DisconnectReq(UINT16 cid) {
    void *ccb;
    if (lbl_803C4040[0] >= 3) {
        fn_80070954(0x80002, lbl_8031801C, cid);
    }
    ccb = l2cu_find_ccb_by_cid(0, cid);
    if (ccb == 0) {
        if (lbl_803C4040[0] >= 2) {
            fn_80070954(0x80001, lbl_80318040, cid);
        }
        return 0;
    }
    fn_80089E40(ccb, 0x1A, 0);
    return 1;
}

BOOLEAN L2CA_DisconnectRsp(UINT16 cid)
{
    void *p_ccb;

    if (lbl_803C4040[0] >= 3) {
        fn_80070954(0x80002, lbl_8031806C, cid);
    }

    p_ccb = l2cu_find_ccb_by_cid(NULL, cid);
    if (p_ccb == NULL) {
        if (lbl_803C4040[0] >= 2) {
            fn_80070954(0x80001, lbl_80318090, cid);
        }
        return FALSE;
    }

    fn_80089E40(p_ccb, 0x1B, NULL);
    return TRUE;
}

extern u8 lbl_80317C20[];
UINT8 L2CA_DataWrite(UINT16 lcid, BT_HDR *p_buf) {
    u8 *trace = lbl_80317C20;
    void *ccb;
    if (lbl_803C4040[0] >= 3)
        fn_8007096C(0x80002, trace + 0x49C, lcid, p_buf->len);
    ccb = l2cu_find_ccb_by_cid(0, lcid);
    if (ccb == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_80070954(0x80001, trace + 0x4C4, lcid);
        GKI_freebuf(p_buf);
        return 0;
    }
    if (p_buf->len <= *(u16 *)((u8 *)ccb + 0x3A)) {
        fn_80089E40(ccb, 0x1D, p_buf);
        return (u8)(1 + !!(*(u8 *)(*(u8 **)((u8 *)ccb + 0x10) + 0x41)));
    }
    if (lbl_803C4040[0] >= 2)
        fn_8007093C(0x80001, trace + 0x4F0);
    GKI_freebuf(p_buf);
    return 0;
}

BOOLEAN L2CA_SetIdleTimeout(UINT16 cid, UINT16 timeout, BOOLEAN is_global)
{
    u8 *p_ccb;
    u8 *p_lcb;

    if (is_global) {
        *(UINT16 *)(lbl_803C4040 + 0x7BA) = timeout;
        goto success;
    }

    p_ccb = (u8 *)l2cu_find_ccb_by_cid(0, cid);
    if (p_ccb == 0) {
        if (lbl_803C4040[0] >= 2) {
            fn_80070954(0x80001, lbl_803181F0, cid);
        }
        return FALSE;
    }

    p_lcb = *(u8 **)(p_ccb + 0x10);
    if (p_lcb != 0 && p_lcb[0] != 0 && *(s32 *)(p_lcb + 4) == 4) {
        *(UINT16 *)(p_lcb + 0x58) = timeout;
        goto success;
    }
    return FALSE;

success:
    return TRUE;
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

extern void l2c_csm_closed(void *, u16, void *);
extern void l2c_csm_orig_w4_sec_comp(void *, u16, void *);
extern void l2c_csm_w4_l2ca_connect_rsp(void *, u16, void *);
extern void l2c_csm_config(void *, u16, void *);
extern void l2c_csm_w4_l2cap_disconnect_rsp(void *, u16, void *);
extern void *jumptable_803183B0[];
void fn_80089E40(void *p_ccb, u8 event, void *p_data) {
    u32 state = *(u32 *)((u8 *)p_ccb + 4);
    if (state > 8) return;
    ((void (*)(void *, u16, void *))jumptable_803183B0[state])(p_ccb, event, p_data);
}

extern char lbl_80318580[];
extern char lbl_803185A8[];
extern void l2cu_release_ccb(void *);
extern void l2cu_send_peer_connect_rsp(void *, u16, u16);
extern void l2c_csm_closed(void *, u16, void *);
extern void l2c_csm_orig_w4_sec_comp(void *, u16, void *);
extern void l2c_csm_w4_l2ca_connect_rsp(void *, u16, void *);
extern void l2c_csm_config(void *, u16, void *);
extern void l2c_csm_w4_l2cap_disconnect_rsp(void *, u16, void *);
void l2c_csm_term_w4_sec_comp(void *p_ccb, u16 event, void *p_msg)
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
void l2c_csm_w4_l2cap_connect_rsp(void *p_ccb, u16 event, void *p_msg)
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

extern void l2cu_process_peer_cfg_req();
extern void l2cu_send_peer_config_rsp(void *, void *);
extern void l2cu_send_peer_disc_req(void *);
extern void forward_peer_data(void *, void *);
extern void l2cu_process_our_cfg_req(void *, void *);
extern void l2cu_send_peer_config_req(void *, void *);
void l2c_csm_open(void *p_ccb, u16 event, void *p_data)
{
    char *p_str = lbl_803183B0;
    void (*disconnect_ind)(u16, u16) = *(void (**)(u16, u16))((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 0x18);
    u16 local_cid = *(u16 *)((u8 *)p_ccb + 0x14);

    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, p_str + 0x628, event);

    switch (event)
    {
    case 3:
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x40, *(u16 *)((u8 *)p_ccb + 0x14));
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, 0);
        break;

    case 6:
    {
        void *p_rcb = *(void **)((u8 *)p_ccb + 0x30);
        void (*cb)(void *) = *(void (**)(void *))((u8 *)p_rcb + 0x20);
        if (cb != 0)
            cb((u8 *)*(void **)((u8 *)p_ccb + 0x10) + 0x2A);
        break;
    }

    case 14:
    {
        u32 tempstate = *(u32 *)((u8 *)p_ccb + 4);
        u8 tempcfgdone = *((u8 *)p_ccb + 0x34);
        *(u32 *)((u8 *)p_ccb + 4) = 5;
        *((u8 *)p_ccb + 0x34) = 0;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        if (((u8 (*)(void *, void *))l2cu_process_peer_cfg_req)(p_ccb, p_data))
        {
            void *p_rcb = *(void **)((u8 *)p_ccb + 0x30);
            void (*config_ind)(u16, void *) = *(void (**)(u16, void *))((u8 *)p_rcb + 0x10);
            config_ind(*(u16 *)((u8 *)p_ccb + 0x14), p_data);
        }
        else
        {
            fn_80070F90((void *)((u32)p_ccb + 0x18));
            *(u32 *)((u8 *)p_ccb + 4) = tempstate;
            *((u8 *)p_ccb + 0x34) = tempcfgdone;
            l2cu_send_peer_config_rsp(p_ccb, p_data);
        }
        break;
    }

    case 17:
    {
        void *p_rcb;
        *(u32 *)((u8 *)p_ccb + 4) = 8;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x54C, *(u16 *)((u8 *)p_ccb + 0x14));
        p_rcb = *(void **)((u8 *)p_ccb + 0x30);
        (*(void (**)(u16, u16))((u8 *)p_rcb + 0x18))(*(u16 *)((u8 *)p_ccb + 0x14), 1);
        break;
    }

    case 19:
    {
        void *p_rcb = *(void **)((u8 *)p_ccb + 0x30);
        (*(void (**)(u16, void *))((u8 *)p_rcb + 0x24))(*(u16 *)((u8 *)p_ccb + 0x14), p_data);
        break;
    }

    case 26:
        l2cu_send_peer_disc_req(p_ccb);
        *(u32 *)((u8 *)p_ccb + 4) = 7;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        break;

    case 29:
        *(u16 *)p_data = *(u16 *)((u8 *)p_ccb + 0x14);
        forward_peer_data(p_ccb, p_data);
        break;

    case 23:
        l2cu_process_our_cfg_req(p_ccb, p_data);
        l2cu_send_peer_config_req(p_ccb, p_data);
        *(u32 *)((u8 *)p_ccb + 4) = 5;
        *((u8 *)p_ccb + 0x34) = 0;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        break;
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

void forward_peer_data(void *arg0, void *arg1) {
    extern u8 lbl_80318BC0[];
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    u8 *ctx = arg0;
    u8 *data = arg1;
    u8 *frame;
    u8 *out;
    u16 length;
    u16 offset;
    u16 count;
    u16 maximum;
    u16 flags;
    void *lcb;

    if (data != 0) {
        if (*(u16 *)(ctx + 0x78) != 0) {
            GKI_enqueue((BUFFER_Q *)(ctx + 0x70), data);
            data = GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
        }
    } else {
        data = GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
    }
    while (data != 0) {
        length = *(u16 *)(data + 4);
        if (length < 9) {
            if (lbl_803C4040[0] >= 1)
                fn_80070954(0x80000, lbl_80318BC0, length);
            GKI_freebuf(data);
            data = GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
            continue;
        }
        offset = length - 8;
        *(u16 *)(data + 4) = offset;
        frame = data + (u16)offset;
        count = *(u16 *)(data + 2);
        out = frame + 0xA;
        *(u16 *)(data + 2) = count + 4;
        lcb = *(void **)(ctx + 0x10);
        flags = *(u16 *)((u8 *)lcb + 0x28) | 0x2000;
        frame[8] = flags;
        lcb = *(void **)(ctx + 0x10);
        flags = *(u16 *)((u8 *)lcb + 0x28) | 0x2000;
        frame[9] = flags >> 8;
        maximum = *(u16 *)(lbl_803C0A50 + 0x7C);
        count = *(u16 *)(data + 2);
        if (count > maximum) {
            out[0] = maximum;
            out[1] = maximum >> 8;
            out += 2;
        } else {
            out[0] = count;
            out[1] = count >> 8;
            out += 2;
        }
        count = *(u16 *)(data + 2);
        out[0] = count - 4;
        out[1] = (count - 4) >> 8;
        out[2] = *(u16 *)(ctx + 0x16);
        out[3] = *(u16 *)(ctx + 0x16) >> 8;
        *(u16 *)(data + 2) = count + 4;
        l2c_link_check_send_pkts(*(void **)(ctx + 0x10), 0, data, count + 4);
        data = GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
    }
}

void l2c_link_sec_comp(BD_ADDR bd_addr, void *ref_data, UINT8 status)
{
    typedef struct {
        UINT8 bd_addr[6];
        UINT8 status;
        UINT8 pad;
        UINT16 psm;
        UINT16 l2cap_result;
        UINT16 l2cap_status;
        UINT16 remote_cid;
    } tL2C_CONN_INFO_LOCAL;
    tL2C_CONN_INFO_LOCAL ci;
    void *lcb;
    void *ccb;
    void *next;
    register s32 event;

    ci.status = status;
    memcpy(ci.bd_addr, bd_addr, 6);
    lcb = l2cu_find_lcb_by_bd_addr(bd_addr);
    if (lcb == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_80318C8C);
    } else {
        event = -(status == 0);
        ccb = *(void **)((u8 *)lcb + 8);
        for (; ccb != 0; ccb = next) {
            next = *(void **)((u8 *)ccb + 8);
            fn_80089E40(ccb, event + 8, &ci);
        }
    }
}

extern void *l2cu_find_lcb_by_handle(u16);
extern void *l2cu_find_lcb_by_state(s32);
extern BOOLEAN l2cu_create_conn(void *);
extern void l2cu_release_lcb(void *);
extern void btm_sco_acl_removed(u8 *);
BOOLEAN l2c_link_hci_disc_comp(UINT16 handle, UINT8 reason) {
    u8 *p_lcb;
    BOOLEAN status = TRUE;
    u8 *p_next_ccb;
    u8 *p_ccb;
    UINT8 reason_copy = reason;

    p_lcb = (u8 *)l2cu_find_lcb_by_handle(handle);
    if (p_lcb == 0) {
        status = FALSE;
    } else {
        if (lbl_803C0F78[0x27BF] != 0x0E)
            lbl_803C0F78[0x27BF] = reason_copy;

        p_ccb = *(u8 **)(p_lcb + 8);
        while (p_ccb != 0) {
            p_next_ccb = *(u8 **)(p_ccb + 8);
            fn_80089E40(p_ccb, 3, &reason_copy);
            p_ccb = p_next_ccb;
        }

        btm_sco_acl_removed(p_lcb + 0x2A);
        l2cu_release_lcb(p_lcb);
    }

    p_lcb = (u8 *)l2cu_find_lcb_by_state(1);
    if (p_lcb != 0)
        l2cu_create_conn(p_lcb);

    return status;
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

void l2c_link_timeout(void *arg0) {
    extern char lbl_80318CB4[];
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    u8 *lcb = arg0;
    void *p;
    int state = *(s32 *)(lcb + 4);
    if (state == 2 || state == 3 || state == 1 || state == 5) {
        p = *(void **)(lcb + 8);
        while (p != 0) {
            void *next = *(void **)((u8 *)p + 8);
            fn_80089E40(p, 3, 0);
            p = next;
        }
        l2cu_release_lcb(arg0);
    }
    if (*(s32 *)(lcb + 4) == 4) {
        void (*cb)(int) = *(void (**)(int))(lcb + 0x54);
        if (cb != 0) {
            *(void (**)(int))(lcb + 0x54) = 0;
            cb(2);
            if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, &lbl_80318CB4);
            p = *(void **)(lcb + 8);
            while (p != 0) {
                void *next = *(void **)((u8 *)p + 8);
                fn_80089E40(p, 3, 0);
                p = next;
            }
        }
        if (*(void **)(lcb + 8) == 0) {
            u8 result = btm_sec_disconnect(*(u16 *)(lcb + 0x28), 0x13);
            u16 timeout;
            if (result == 1) {
                timeout = 0x1e;
                *(s32 *)(lcb + 4) = 5;
            } else if (result == 0) {
                *(s32 *)(lcb + 4) = 5;
                timeout = 0xffff;
            } else {
                timeout = 1;
            }
            if (timeout != 0xffff) btu_start_timer(lcb + 0x10, 2, timeout);
        } else {
            ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(lcb, 0, 0);
        }
    }
}

s32 l2c_link_send_to_lower(void *p_lcb, void *p_buf) {
    u16 len = *(u16 *)((u8 *)p_buf + 2);
    u16 max_len = *(u16 *)(lbl_803C0A50 + 0x7E);
    u16 packets;
    u16 mtu;
    u16 available;
    u16 credits;

    if (len <= max_len) {
        --*(u16 *)((u8 *)p_lcb + 0x36);
        ++*(u16 *)((u8 *)p_lcb + 0x38);
        --*(u16 *)(lbl_803C4040 + 4);
        fn_8007079C(p_buf, 0x2100);
    } else {
        mtu = *(u16 *)(lbl_803C0A50 + 0x7C);
        packets = (len + mtu - 5) / mtu;
        available = *(u16 *)(lbl_803C4040 + 4);

        if (packets > available) {
            *(u16 *)((u8 *)p_buf + 6) = available;
            packets = available;
            *((u8 *)p_lcb + 0x40) = 1;
        }
        credits = *(u16 *)((u8 *)p_lcb + 0x36);
        if (packets > credits) {
            *(u16 *)((u8 *)p_buf + 6) = credits;
            packets = credits;
            *((u8 *)p_lcb + 0x40) = 1;
        }
        *(u16 *)(lbl_803C4040 + 4) -= packets;
        *(u16 *)((u8 *)p_lcb + 0x36) -= packets;
        *(u16 *)((u8 *)p_lcb + 0x38) += packets;
        fn_8007079C(p_buf, 0x2100);
    }
    return 1;
}

extern char lbl_80318BE8[];
void l2c_link_check_send_pkts(void *arg0, u8 arg1, void *arg2, u8 arg3) {
    u8 *p_lcb = (u8 *)arg0;
    u8 *p_buf;
    register char *p_trace = lbl_80318BE8;
    register u8 *p_ccb;
    u8 mode;
    tBTM_PM_PWR_MD pm;

    if (arg2 != 0) {
        if (*(u16 *)(p_lcb + 0x4C) >= *(u16 *)(p_lcb + 0x3A) && p_lcb[0x41] == 0) {
            p_ccb = *(u8 **)(p_lcb + 8);
            while (p_ccb != 0) {
                if (lbl_803C4040[0] >= 2)
                    fn_80070954(0x80001, p_trace + 0xE4, *(u16 *)(p_ccb + 0x14));
                if (*(void **)(*(u8 **)(p_ccb + 0x30) + 0x28) != 0) {
                    if (lbl_803C4040[0] >= 3)
                        fn_80070954(0x80002, p_trace + 0x110, *(u16 *)(p_ccb + 0x14));
                    ((void (*)(u16, u16, void *))(*(void **)(*(u8 **)(p_ccb + 0x30) + 0x28)))(*(u16 *)(p_ccb + 0x14), 1, *(void **)(p_ccb + 0x30));
                }
                p_ccb = *(u8 **)(p_ccb + 8);
            }
            p_lcb[0x41] = 1;
        }
        if (*(u16 *)(p_lcb + 0x4C) <= *(u16 *)(p_lcb + 0x3E)) {
            *(u16 *)((u8 *)arg2 + 6) = 0;
            GKI_enqueue((BUFFER_Q *)(p_lcb + 0x44), arg2);
        } else {
            GKI_freebuf(arg2);
            if (lbl_803C4040[0] >= 2)
                fn_8007093C(0x80001, p_trace + 0x150);
        }
    }

    if (p_lcb[0x40] != 0)
        return;
    if (BTM_ReadPowerMode(p_lcb + 0x2A, &mode) == 0 && mode == 3 && *(u16 *)(p_lcb + 0x4C) != 0) {
        pm.mode = 0;
        BTM_SetPowerMode(0x80, p_lcb + 0x2A, &pm);
        btu_start_timer(p_lcb + 0x10, 2, 1);
        return;
    }

    {
        u8 *global = lbl_803C4040;
        for (;;) {
            u8 *head = *(u8 **)(p_lcb + 0x44);
            if (head == 0 || *(u16 *)(head + 6) != 0 || p_lcb[0x40] != 0)
                break;
            p_buf = (u8 *)GKI_dequeue((BUFFER_Q *)(p_lcb + 0x44));
            if (p_buf == 0 || (u8)l2c_link_send_to_lower(arg0, p_buf) == 0)
                break;
            if (*(u16 *)(global + 4) == 0 || *(u16 *)(p_lcb + 0x36) == 0)
                break;
        }
    }
    if (p_lcb[0x40] != 0)
        return;
    if (*(u16 *)(p_lcb + 0x4C) != 0 && *(u16 *)(p_lcb + 0x36) != 0)
        btu_start_timer(p_lcb + 0x10, 2, 2);
    if (p_lcb[0x41] != 0 && *(u16 *)(p_lcb + 0x4C) <= *(u16 *)(p_lcb + 0x3C)) {
        p_ccb = *(u8 **)(p_lcb + 8);
        p_lcb[0x41] = 0;
        while (p_ccb != 0) {
            if (*(void **)(*(u8 **)(p_ccb + 0x30) + 0x28) != 0) {
                if (lbl_803C4040[0] >= 3)
                    fn_80070954(0x80002, p_trace + 0x170, *(u16 *)(p_ccb + 0x14));
                ((void (*)(u16, u16, void *))(*(void **)(*(u8 **)(p_ccb + 0x30) + 0x28)))(*(u16 *)(p_ccb + 0x14), 0, *(void **)(p_ccb + 0x30));
                if (p_lcb[0x41] != 0)
                    break;
            }
            p_ccb = *(u8 **)(p_ccb + 8);
        }
    }
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

void l2c_link_process_num_completed_pkts(u8 *p, u16 evt_len) {
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    u8 count = p[0];
    u8 i = 0;
    u8 *entry = p + 1;
    u16 zero = 0;

    while (i < count) {
        u16 handle = (u16)(entry[0] + (entry[1] << 8));
        u16 completed = (u16)(entry[2] + (entry[3] << 8));
        void *lcb;
        u32 value;

        entry += 4;
        lcb = l2cu_find_lcb_by_handle(handle);
        if (lcb != 0) {
            value = *(u16 *)((u8 *)lcb + 0x36) + completed;
            *(u16 *)((u8 *)lcb + 0x36) = value;
            if ((u16)value > *(u16 *)((u8 *)lcb + 0x34))
                *(u16 *)((u8 *)lcb + 0x36) = *(u16 *)((u8 *)lcb + 0x34);
            if (*(u16 *)((u8 *)lcb + 0x38) > completed)
                *(u16 *)((u8 *)lcb + 0x38) -= completed;
            else
                *(u16 *)((u8 *)lcb + 0x38) = zero;
            *(u16 *)(lbl_803C4040 + 4) += completed;
            ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(lcb, 0, 0);
        }
        i++;
    }
}

void fn_8008C04C(s16 arg0) {
    *(s16 *)(lbl_803C4040 + 2) = arg0;
    *(s16 *)(lbl_803C4040 + 4) = arg0;
}

BOOL l2cap_link_chk_pkt_end(void) {
    u8 *p_lcb = *(u8 **)(lbl_803C4040 + 0x7BC);
    u8 *p_buf;
    u8 *p_data;
    u16 offset;
    u16 len;
    u8 hi;
    u8 lo;
    u16 l2cap_len;
    if (p_lcb == 0)
        goto empty;
    p_buf = *(u8 **)(p_lcb + 0x50);
    if (p_buf != 0)
        goto have_buf;
empty:
    return TRUE;
have_buf:
    offset = *(u16 *)(p_buf + 4);
    len = *(u16 *)(p_buf + 2);
    p_data = p_buf + offset;
    hi = p_data[0x0D];
    lo = p_data[0x0C];
    l2cap_len = (u16)(lo + (hi << 8));
    if (l2cap_len > len - 8)
        return FALSE;
    *(u8 **)(p_lcb + 0x50) = 0;
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

extern char lbl_80318E20[];
void l2c_link_segments_xmitted(BT_HDR *p_msg) {
    u8 *p;
    u16 handle;
    void *p_lcb;

    p = (u8 *)p_msg + p_msg->offset;
    handle = (u16)((p[8] + (p[9] << 8)) & 0x0fff);
    p_lcb = l2cu_find_lcb_by_handle(handle);
    if (p_lcb == NULL) {
        if (lbl_803C4040[0] >= 2) {
            fn_80070954(0x80001, lbl_80318E20, handle);
        }
        GKI_freebuf(p_msg);
        return;
    }

    if (*(s32 *)((u8 *)p_lcb + 4) == 4) {
        *(u16 *)((u8 *)p_msg + 6) = 0;
        GKI_enqueue_head((BUFFER_Q *)((u8 *)p_lcb + 0x44), p_msg);
        *(u8 *)((u8 *)p_lcb + 0x40) = 0;
        ((void (*)(void *, void *, void *))l2c_link_check_send_pkts)(p_lcb, 0, 0);
    } else {
        GKI_freebuf(p_msg);
    }
}

void fn_8008C464(u8 *bd_addr) {
    void *lcb = l2cu_find_lcb_by_bd_addr(bd_addr);
    if (lcb != 0 && *(u32 *)((u8 *)lcb + 8) == 0)
        btu_start_timer((u8 *)lcb + 0x10, 2, 0x78);
}

void l2c_init(void) {
    u8 *base = lbl_803C4040;
    u32 i;

    memset(base, 0, 0x7E8);
    for (i = 1; i <= 9; i++) {
        *(u8 **)(base + 0x180 + (i - 1) * 0x7C) = base + 0x178 + i * 0x7C;
    }
    *(u8 **)(base + 0x7B0) = base + 0x178;
    *(u8 **)(base + 0x7B4) = base + 0x5D4;
    base[1] = 0;
    *(u16 *)(base + 0x7BA) = 2;
    base[0] = 0;
}

void l2c_rcv_acl_data(register BT_HDR *arg0) {
    extern char lbl_80318E58[];
    extern void process_l2cap_cmd(void *, UINT8 *, UINT16);
    u8 *data;
    register char *trace;
    register u32 temp_r26;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r28;
    register u32 temp_r0_3;
    s32 temp_r0_4;
    register u16 temp_r25;
    s32 temp_r24;
    s32 temp_r4;
    u32 temp_r0;
    u8 temp_r28;

    var_r28 = 0;
    data = (u8 *)arg0 + arg0->offset;
    trace = lbl_80318E58;
    temp_r0 = data[8] + ((u32)data[9] << 8);
    temp_r26 = temp_r0 & 0xFFF;
    if (((temp_r0 >> 12) & 3) != 2) {
        if (lbl_803C4040[0] >= 2)
            fn_80070954(0x80001, trace, (u16)((temp_r0 >> 12) & 3));
        GKI_freebuf(arg0);
        return;
    }
    temp_r3 = (s32)l2cu_find_lcb_by_handle((u16)temp_r26);
    if (temp_r3 == 0) {
        temp_r25 = (u16)(data[14] + (data[15] << 8));
        temp_r28 = data[16];
        if (arg0->layer_specific == 0 && temp_r25 == 1 &&
            (temp_r28 == 10 || temp_r28 == 2) && (u8)fn_8007FEFC(temp_r26) == 0) {
            if (lbl_803C4040[0] >= 2) {
                ((void (*)(u32, void *, u16, u16, u16, u8, u16))fn_800709B4)(
                    0x80001, trace + 0x24, temp_r26,
                    arg0->layer_specific, temp_r25, temp_r28,
                    *(u16 *)(lbl_803C4040 + 0x7C8));
            }
            arg0->layer_specific = 2;
            {
                register u8 *gki_cb = lbl_803C4040;
                GKI_enqueue((BUFFER_Q *)(gki_cb + 0x7C0), arg0);
                if (*(u16 *)(gki_cb + 0x7C8) == 1)
                    btu_start_timer((TIMER_LIST_ENT *)(gki_cb + 0x7CC), 4, 1);
            }
        } else {
            GKI_freebuf(arg0);
        }
        return;
    }

    temp_r4 = arg0->offset;
    temp_r0_3 = (u16)(data[10] + (data[11] << 8));
    arg0->offset = (u16)(temp_r4 + 4);
    temp_r24 = (u16)(data[14] + (data[15] << 8));
    temp_r25 = (u16)(data[12] + (data[13] << 8));
    if ((u32)temp_r24 > 2) {
        temp_r3_2 = (s32)l2cu_find_ccb_by_cid((void *)temp_r3, temp_r24);
        var_r28 = temp_r3_2;
        if (temp_r3_2 == 0) {
            if (lbl_803C4040[0] >= 2)
                fn_80070954(0x80001, trace + 0x78, temp_r24);
            GKI_freebuf(arg0);
            return;
        }
    }
    if (temp_r0_3 >= 4) {
        temp_r4 = temp_r0_3 - 4;
        arg0->len = temp_r4;
        temp_r0_4 = arg0->offset + 4;
        arg0->offset = (u16)temp_r0_4;
    } else {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, trace + 0x90);
        GKI_freebuf(arg0);
        return;
    }
    if (temp_r25 != (u16)temp_r4) {
        if (lbl_803C4040[0] >= 2)
            fn_8007096C(0x80001, trace + 0xB4, temp_r25, (u16)temp_r4);
        GKI_freebuf(arg0);
        return;
    }
    if ((u32)temp_r24 == 1) {
        process_l2cap_cmd((void *)temp_r3, data + 16, temp_r25);
        GKI_freebuf(arg0);
        return;
    }
    if ((u32)temp_r24 == 2) {
        arg0->offset = (u16)(temp_r0_4 + 2);
        arg0->len = temp_r4 - 2;
        if (lbl_803C4040[0] >= 5)
            fn_80070954(0x80004, trace + 0xE0,
                (u16)(((u32)data[17] << 8) + data[16]));
        GKI_freebuf(arg0);
        return;
    }
    if (var_r28 == 0) {
        GKI_freebuf(arg0);
        return;
    }
    fn_80089E40((void *)var_r28, 0x13, arg0);
}

char check_offset[offsetof(tL2CAP_CFG_INFO, flags)];
void fn_80070984(u32, void *);
extern char lbl_80318E58[];
void *l2cu_find_rcb_by_psm(u16 psm);
void l2cu_send_peer_echo_rsp(void *arg0, s32 arg1, u8 *arg2, u32 arg3);
void l2cu_send_peer_info_rsp(void *arg0, s32 arg1, u16 arg2);
void l2cu_reject_connection(void *, u16, u8, u16);
void *l2cu_allocate_ccb(void *, u16);
void l2cu_send_peer_config_rej(void *, u8 *, u16, u16);
void l2cu_send_peer_cmd_reject(void *, u16, u8, u16, u16);
void btu_stop_timer(void *);
void l2cu_send_peer_info_req(void *arg0, u16 arg1);
void l2cu_process_fixed_chnl_resp(void *arg0);
void process_l2cap_cmd(void *p_lcb, UINT8 *p, UINT16 pkt_len)
{
    typedef struct {
        UINT8 bd_addr[6];
        UINT8 status;
        UINT8 pad;
        UINT16 psm;
        UINT16 l2cap_result;
        UINT16 l2cap_status;
        UINT16 remote_cid;
    } tL2C_CONN_INFO_LOCAL;
    UINT8 *p_pkt_end, *p_next_cmd, *p_cfg_end, *p_cfg_start;
    UINT8 cmd_code, cfg_code, cfg_len, id;
    tL2C_CONN_INFO_LOCAL con_info;
    tL2CAP_CFG_INFO cfg_info;
    UINT16 rej_reason, rej_mtu, lcid, rcid, info_type;
    u8 *p_ccb;
    void *p_rcb;
    BOOLEAN cfg_rej;
    UINT16 cfg_rej_len, cmd_len;
    UINT16 result;

    p_next_cmd = p;
    p_pkt_end = p + pkt_len;

    while (TRUE)
    {
        if ((p = p_next_cmd) > (p_pkt_end - 4))
            break;

        STREAM_TO_UINT8 (cmd_code, p);
        STREAM_TO_UINT8 (id, p);
        STREAM_TO_UINT16 (cmd_len, p);

        if ((p_next_cmd = p + cmd_len) > p_pkt_end)
        {
            if (lbl_803C4040[0] >= 2)
                ((void (*)(u32, void *, int, int, int))fn_80070984)(0x80001, lbl_80318E58 + 0x100, pkt_len, cmd_len, cmd_code);
            break;
        }

        switch (cmd_code)
        {
        case 1:
            STREAM_TO_UINT16 (rej_reason, p);
            if (rej_reason == 1)
            {
                STREAM_TO_UINT16 (rej_mtu, p);
                if (lbl_803C4040[0] >= 2)
                    fn_8007096C(0x80001, lbl_80318E58 + 0x134, *(u16 *)((u8 *)p_lcb + 0x28), rej_mtu);
            }
            if (rej_reason == 2)
            {
                STREAM_TO_UINT16 (rcid, p);
                STREAM_TO_UINT16 (lcid, p);

                if (lbl_803C4040[0] >= 2)
                    fn_8007096C(0x80001, lbl_80318E58 + 0x158, lcid, rcid);

                if (((p_ccb = (u8 *)l2cu_find_ccb_by_cid (p_lcb, lcid)) != NULL)
                 && (*(u16 *)(p_ccb + 0x16) == rcid))
                {
                    fn_80089E40(p_ccb, 3, NULL);
                }
            }
            break;

        case 2:
            STREAM_TO_UINT16 (con_info.psm, p);
            STREAM_TO_UINT16 (rcid, p);
            if ((p_rcb = l2cu_find_rcb_by_psm (con_info.psm)) == NULL)
            {
                if (lbl_803C4040[0] >= 2)
                    fn_80070954(0x80001, lbl_80318E58 + 0x188, con_info.psm);
                l2cu_reject_connection (p_lcb, rcid, id, 2);
                break;
            }
            if ((p_ccb = (u8 *)l2cu_allocate_ccb (p_lcb, 0)) == NULL)
            {
                if (lbl_803C4040[0] >= 1)
                    fn_8007093C(0x80000, lbl_80318E58 + 0x1B4);
                l2cu_reject_connection (p_lcb, rcid, id, 4);
                break;
            }
            p_ccb[0x36] = id;
            *(void **)(p_ccb + 0x30) = p_rcb;
            *(u16 *)(p_ccb + 0x16) = rcid;

            fn_80089E40(p_ccb, 10, &con_info);
            break;

        case 3:
            STREAM_TO_UINT16 (con_info.remote_cid, p);
            STREAM_TO_UINT16 (lcid, p);
            STREAM_TO_UINT16 (con_info.l2cap_result, p);
            STREAM_TO_UINT16 (con_info.l2cap_status, p);

            if ((p_ccb = (u8 *)l2cu_find_ccb_by_cid (p_lcb, lcid)) == NULL)
            {
                if (lbl_803C4040[0] >= 2)
                    fn_8007096C(0x80001, lbl_80318E58 + 0x1D4, lcid, con_info.remote_cid);
                break;
            }
            if (p_ccb[0x35] != id)
            {
                if (lbl_803C4040[0] >= 2)
                    fn_8007096C(0x80001, lbl_80318E58 + 0x204, p_ccb[0x35], id);
                break;
            }

            if (con_info.l2cap_result == 0)
                fn_80089E40(p_ccb, 11, &con_info);
            else if (con_info.l2cap_result == 1)
                fn_80089E40(p_ccb, 12, &con_info);
            else
                fn_80089E40(p_ccb, 13, &con_info);

            break;

        case 4:
            p_cfg_end = p + cmd_len;
            cfg_rej = FALSE;
            cfg_rej_len = 0;

            STREAM_TO_UINT16 (lcid, p);
            STREAM_TO_UINT16 (cfg_info.flags, p);

            p_cfg_start = p;

            cfg_info.flush_to_present = cfg_info.mtu_present = cfg_info.qos_present =
                cfg_info.fcr_present = FALSE;

            while (p < p_cfg_end)
            {
                STREAM_TO_UINT8 (cfg_code, p);
                STREAM_TO_UINT8 (cfg_len, p);

                switch (cfg_code & 0x7F)
                {
                case 1:
                    cfg_info.mtu_present = TRUE;
                    STREAM_TO_UINT16 (cfg_info.mtu, p);
                    break;

                case 2:
                    cfg_info.flush_to_present = TRUE;
                    STREAM_TO_UINT16 (cfg_info.flush_to, p);
                    break;

                case 3:
                    cfg_info.qos_present = TRUE;
                    STREAM_TO_UINT8  (cfg_info.qos.qos_flags, p);
                    STREAM_TO_UINT8  (cfg_info.qos.service_type, p);
                    STREAM_TO_UINT32 (cfg_info.qos.token_rate, p);
                    STREAM_TO_UINT32 (cfg_info.qos.token_bucket_size, p);
                    STREAM_TO_UINT32 (cfg_info.qos.peak_bandwidth, p);
                    STREAM_TO_UINT32 (cfg_info.qos.latency, p);
                    STREAM_TO_UINT32 (cfg_info.qos.delay_variation, p);
                    break;

                case 4:
                    cfg_info.fcr_present = TRUE;
                    STREAM_TO_UINT8 (cfg_info.fcr.mode, p);
                    STREAM_TO_UINT8 (cfg_info.fcr.tx_win_sz, p);
                    STREAM_TO_UINT8 (cfg_info.fcr.max_transmit, p);
                    STREAM_TO_UINT16 (cfg_info.fcr.rtrans_tout, p);
                    STREAM_TO_UINT16 (cfg_info.fcr.mon_tout, p);
                    STREAM_TO_UINT16 (cfg_info.fcr.mps, p);
                    break;

                default:
                    if ((cfg_len + 2) <= cmd_len)
                    {
                        p += cfg_len;
                        if ((cfg_code & 0x80) == 0)
                        {
                            cfg_rej_len += cfg_len + 2;
                            cfg_rej = TRUE;
                        }
                    }
                    else
                    {
                        p = p_cfg_end;
                        cfg_rej = TRUE;
                    }
                    break;
                }
            }

            if ((p_ccb = (u8 *)l2cu_find_ccb_by_cid (p_lcb, lcid)) != NULL)
            {
                p_ccb[0x36] = id;
                if (cfg_rej)
                {
                    l2cu_send_peer_config_rej (p_ccb, p_cfg_start, (UINT16)(cmd_len - 4), cfg_rej_len);
                }
                else
                {
                    fn_80089E40 (p_ccb, 14, &cfg_info);
                }
            }
            else
            {
                l2cu_send_peer_cmd_reject (p_lcb, 2, id, 0, 0);
            }
            break;

        case 5:
            p_cfg_end = p + cmd_len;
            STREAM_TO_UINT16 (lcid, p);
            STREAM_TO_UINT16 (cfg_info.flags, p);
            STREAM_TO_UINT16 (cfg_info.result, p);

            cfg_info.flush_to_present = cfg_info.mtu_present = cfg_info.qos_present =
                cfg_info.fcr_present = FALSE;

            while (p < p_cfg_end)
            {
                STREAM_TO_UINT8 (cfg_code, p);
                STREAM_TO_UINT8 (cfg_len, p);

                switch (cfg_code & 0x7F)
                {
                case 1:
                    cfg_info.mtu_present = TRUE;
                    STREAM_TO_UINT16 (cfg_info.mtu, p);
                    break;

                case 2:
                    cfg_info.flush_to_present = TRUE;
                    STREAM_TO_UINT16 (cfg_info.flush_to, p);
                    break;

                case 3:
                    cfg_info.qos_present = TRUE;
                    STREAM_TO_UINT8  (cfg_info.qos.qos_flags, p);
                    STREAM_TO_UINT8  (cfg_info.qos.service_type, p);
                    STREAM_TO_UINT32 (cfg_info.qos.token_rate, p);
                    STREAM_TO_UINT32 (cfg_info.qos.token_bucket_size, p);
                    STREAM_TO_UINT32 (cfg_info.qos.peak_bandwidth, p);
                    STREAM_TO_UINT32 (cfg_info.qos.latency, p);
                    STREAM_TO_UINT32 (cfg_info.qos.delay_variation, p);
                    break;

                case 4:
                    cfg_info.fcr_present = TRUE;
                    STREAM_TO_UINT8 (cfg_info.fcr.mode, p);
                    STREAM_TO_UINT8 (cfg_info.fcr.tx_win_sz, p);
                    STREAM_TO_UINT8 (cfg_info.fcr.max_transmit, p);
                    STREAM_TO_UINT16 (cfg_info.fcr.rtrans_tout, p);
                    STREAM_TO_UINT16 (cfg_info.fcr.mon_tout, p);
                    STREAM_TO_UINT16 (cfg_info.fcr.mps, p);
                    break;
                }
            }

            if ((p_ccb = (u8 *)l2cu_find_ccb_by_cid (p_lcb, lcid)) != NULL)
            {
                if (p_ccb[0x35] != id)
                {
                    if (lbl_803C4040[0] >= 2)
                        fn_8007096C (0x80001, lbl_80318E58 + 0x230, p_ccb[0x35], id);
                    break;
                }
                if ((cfg_info.result == 0) || (cfg_info.result == 1))
                    fn_80089E40 (p_ccb, 15, &cfg_info);
                else
                    fn_80089E40 (p_ccb, 16, &cfg_info);
            }
            else
            {
                if (lbl_803C4040[0] >= 2)
                    fn_80070954 (0x80001, lbl_80318E58 + 0x25C, lcid);
            }
            break;

        case 6:
            STREAM_TO_UINT16 (lcid, p);
            STREAM_TO_UINT16 (rcid, p);

            if ((p_ccb = (u8 *)l2cu_find_ccb_by_cid (p_lcb, lcid)) != NULL)
            {
                if (*(u16 *)(p_ccb + 0x16) == rcid)
                {
                    p_ccb[0x36] = id;
                    fn_80089E40 (p_ccb, 17, &con_info);
                }
            }
            else
                l2cu_send_peer_disc_rsp (p_lcb, id, lcid, rcid);

            break;

        case 7:
            STREAM_TO_UINT16 (rcid, p);
            STREAM_TO_UINT16 (lcid, p);

            if ((p_ccb = (u8 *)l2cu_find_ccb_by_cid (p_lcb, lcid)) != NULL)
            {
                if ((*(u16 *)(p_ccb + 0x16) == rcid) && (p_ccb[0x35] == id))
                {
                    fn_80089E40 (p_ccb, 18, &con_info);
                }
            }
            break;

        case 8:
            if (cmd_len < (*(u16 *)(lbl_803C0A50 + 0x7E) - 12))
            {
                l2cu_send_peer_echo_rsp (p_lcb, id, p, cmd_len);
            }
            else
            {
                l2cu_send_peer_echo_rsp (p_lcb, id, NULL, 0);
            }
            break;

        case 9:
            if (*(void **)((u8 *)p_lcb + 0x58))
            {
                void (*p_cb)(int) = *(void (**)(int))((u8 *)p_lcb + 0x58);
                *(void **)((u8 *)p_lcb + 0x58) = NULL;
                (*p_cb) (0);
            }
            break;

        case 10:
            STREAM_TO_UINT16 (info_type, p);
            l2cu_send_peer_info_rsp (p_lcb, id, info_type);
            break;

        case 11:
            if (((u8 *)p_lcb)[0x67])
            {
                btu_stop_timer ((u8 *)p_lcb + 0x38);
                ((u8 *)p_lcb)[0x67] = FALSE;
            }

            STREAM_TO_UINT16 (info_type, p);
            STREAM_TO_UINT16 (result, p);

            ((u8 *)p_lcb)[0x68] |= (1 << info_type);

            if ( (info_type == 2)
              && (result == 0) )
            {
                STREAM_TO_UINT32( *(u32 *)((u8 *)p_lcb + 0x6C), p );
            }

            con_info.status = 0;
            memcpy (con_info.bd_addr, (u8 *)p_lcb + 0x50, 6);
            for (p_ccb = *(u8 **)((u8 *)p_lcb + 0x2C); p_ccb; p_ccb = *(u8 **)(p_ccb + 0x4))
            {
                fn_80089E40 (p_ccb, 20, &con_info);
            }
            break;

        default:
            if (lbl_803C4040[0] >= 2)
                fn_80070954 (0x80001, lbl_80318E58 + 0x288, cmd_code);
            l2cu_send_peer_cmd_reject (p_lcb, 0, id, 0, 0);
            return;
        }
    }
}

void l2c_process_timeout(void *arg) {
    s32 event = *(u16 *)((u8 *)arg + 0x14);
    switch (event) {
    case 2:
        l2c_link_timeout(*(void **)((u8 *)arg + 0x10));
        break;
    case 3:
        fn_80089E40(*(void **)((u8 *)arg + 0x10), 0x1E, 0);
        break;
    case 4:
        l2c_process_held_packets(1);
        break;
    case 0x49:
        break;
    }
}

void *l2cu_allocate_lcb(u8 *addr) {
    u8 *lcb;
    u16 id;
    s32 i;
    for (i = 0, lcb = lbl_803C4040 + 8; i < 4; i++, lcb += 0x5C) {
        if (lcb[0] == 0) {
            memset(lcb, 0, 0x5C);
            lcb[0] = 1;
            memcpy(lcb + 0x2A, addr, 6);
            *(u32 *)(lcb + 4) = 0;
            *(u16 *)(lcb + 0x28) = 0xFFFF;
            *(u32 *)(lcb + 0x50) = 0;
            *(u16 *)(lcb + 0x32) = 0xFFFF;
            *(u32 *)(lcb + 0x20) = (u32)lcb;
            *(u16 *)(lcb + 0x38) = 0;
            *(u16 *)(lcb + 0x58) = *(u16 *)(lbl_803C4040 + 0x7BA);
            lcb[0x31] = 0;
            id = *(u16 *)(lbl_803C4040 + 0x7B8);
            *(u16 *)(lbl_803C4040 + 0x7B8) = id + 1;
            l2c_link_adjust_allocation();
            return lcb;
        }
    }
    return 0;
}

extern void *GKI_dequeue(BUFFER_Q *);
extern void btm_remove_sco_links(u8 *);
extern void btm_acl_removed(u8 *);
extern void l2c_link_adjust_allocation(void);
void l2cu_release_lcb(void *arg0) {
    u8 *lcb = (u8 *)arg0;
    void *buf;
    void *ccb;
    u16 old_count;
    void (*callback)(u8);

    lcb[0] = 0;
    fn_80070F90(lcb + 0x10);

    buf = *(void **)(lcb + 0x50);
    if (buf != 0) {
        GKI_freebuf(buf);
        *(void **)(lcb + 0x50) = 0;
    }

    btm_remove_sco_links(lcb + 0x2A);

    ccb = *(void **)(lcb + 8);
    while (ccb != 0) {
        l2cu_release_ccb(ccb);
        ccb = *(void **)(lcb + 8);
    }

    if (*(u32 *)(lcb + 4) - 4 <= 1) {
        btm_acl_removed(lcb + 0x2A);
    }

    while (*(void **)(lcb + 0x44) != 0) {
        buf = GKI_dequeue((BUFFER_Q *)(lcb + 0x44));
        GKI_freebuf(buf);
    }

    if (*(u16 *)(lbl_803C4040 + 0x7B8) >= 1) {
        *(u16 *)(lbl_803C4040 + 0x7B8) -= 1;
    }

    old_count = *(u16 *)(lbl_803C4040 + 4);
    *(u16 *)(lbl_803C4040 + 4) = old_count + *(u16 *)(lcb + 0x38);
    ((void (*)(u16, void *))l2c_link_adjust_allocation)(old_count, lbl_803C4040);

    callback = *(void (**)(u8))(lcb + 0x54);
    if (callback != 0) {
        *(void (**)(u8))(lcb + 0x54) = 0;
        callback(1);
    }
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
    u16 length = arg1;
    if (buf == NULL) return NULL;
    buf->offset = 0;
    buf->len = arg1 + 0xC;
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
    p[11] = length >> 8;
    return buf;
}

extern char lbl_80319158[];
void l2cu_send_peer_cmd_reject(void *arg0, u16 arg1, u8 arg2, u16 arg3, u16 arg4) {
    u16 size;
    void *packet;
    u8 *p;

    if (arg1 != 1) {
        goto calc_size;
    }
    size = 2;
    goto size_done;
calc_size:
    size = ((s32)~((arg1 - 2) | (2 - arg1)) >> 31) & 4;
size_done:
    packet = ((void *(*)(u16, u16, u8, s32))l2cu_build_header)(
        *(u16 *)((u8 *)arg0 + 0x28), size + 2, 1, arg2);
    if (packet == 0) {
        if (lbl_803C4040[0] >= 2) {
            fn_8007093C(0x80001, lbl_80319158);
        }
    } else {
        ((u8 *)packet)[0x14] = arg1;
        ((u8 *)packet)[0x15] = arg1 >> 8;
        p = (u8 *)packet + 0x16;
        if (size >= 2) {
            p[0] = arg3;
            p[1] = arg3 >> 8;
            p += 2;
        }
        if (size >= 4) {
            p[0] = arg4;
            p[1] = arg4 >> 8;
        }
        ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(arg0, 0, packet);
    }
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

void l2cu_send_peer_connect_rsp(void *p_ccb, u16 result, u16 status) {
    void *p_buf;
    u8 *p;

    p_buf = l2cu_build_header(
        *(u16 *)(*(u8 **)((u8 *)p_ccb + 0x10) + 0x28),
        8, 3, *(u8 *)((u8 *)p_ccb + 0x36)
    );
    if (p_buf == NULL) {
        if (lbl_803C4040[0] >= 2) {
            fn_8007093C(0x80001, lbl_80319174);
        }
        return;
    }

    p = (u8 *)p_buf + 0x14;
    UINT16_TO_STREAM(p, *(u16 *)((u8 *)p_ccb + 0x14));
    UINT16_TO_STREAM(p, *(u16 *)((u8 *)p_ccb + 0x16));
    UINT16_TO_STREAM(p, result);
    UINT16_TO_STREAM(p, status);
    ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(
        *(void **)((u8 *)p_ccb + 0x10), 0, p_buf
    );
}

void l2cu_reject_connection(void *p_lcb, u16 remote_cid, u8 rem_id, u16 result) {
    void *p_buf;
    u8 *packet;

    p_buf = l2cu_build_header(*(u16 *)((u8 *)p_lcb + 0x28), 8, 3, rem_id);
    if (p_buf == NULL) {
        if (lbl_803C4040[0] >= 2) {
            fn_8007093C(0x80001, lbl_80319174);
        }
        return;
    }

    packet = p_buf;
    packet[0x14] = 0;
    packet[0x15] = 0;
    packet[0x16] = remote_cid;
    packet[0x17] = ((s32)remote_cid) >> 8;
    packet[0x18] = result;
    packet[0x19] = ((u32)result) >> 8;
    packet[0x1A] = 0;
    packet[0x1B] = 0;
    ((void (*)(void *, u8, void *, s32, u8))l2c_link_check_send_pkts)(
        p_lcb, 0, p_buf, ((s32)remote_cid) >> 8, 0);
}

void l2cu_send_peer_config_req(void *arg0, void *arg1)
{
    extern char lbl_80319174[];
    extern void fn_8007093C(u32, void *);
    u8 *ccb = (u8 *)arg0;
    u8 *cfg = (u8 *)arg1;
    u8 *link;
    u8 *packet;
    u8 *dst;
    u16 length;

    length = 0;
    link = *(u8 **)(ccb + 0x10);
    link[0x31] += 1;
    ccb[0x35] = link[0x31];
    if (cfg[2] != 0) length = 4;
    if (cfg[0x20] != 0) length += 4;
    if (cfg[6] != 0) length += 0x18;
    if (cfg[0x24] != 0) length += 0xB;
    packet = ((void *(*)(u16, u16, u8, u8))l2cu_build_header)(
        *(u16 *)(*(u8 **)(ccb + 0x10) + 0x28), length + 4, 4, ccb[0x35]);
    if (packet == NULL) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80319174);
    } else {
        *(u8 *)(packet + 0x14) = *(u16 *)(ccb + 0x16);
        *(u8 *)(packet + 0x15) = ((s32)*(u16 *)(ccb + 0x16)) >> 8;
        packet[0x16] = 0;
        packet[0x17] = 0;
        dst = packet + 0x18;
        if (cfg[2] != 0) {
            dst[0] = 1;
            dst[1] = 2;
            dst[2] = *(u16 *)(cfg + 4);
            dst[3] = ((s32)*(u16 *)(cfg + 4)) >> 8;
            dst += 4;
        }
        if (cfg[0x20] != 0) {
            dst[0] = 2;
            dst[1] = 2;
            dst[2] = *(u16 *)(cfg + 0x22);
            dst[3] = ((s32)*(u16 *)(cfg + 0x22)) >> 8;
            dst += 4;
        }
        if (cfg[6] != 0) {
            dst[0] = 3;
            dst[1] = 0x16;
            dst[2] = cfg[8];
            dst[3] = cfg[9];
            dst[4] = *(u32 *)(cfg + 0xC);
            dst[5] = *(u32 *)(cfg + 0xC) >> 8;
            dst[6] = *(u32 *)(cfg + 0xC) >> 16;
            dst[7] = *(u32 *)(cfg + 0xC) >> 24;
            dst[8] = *(u32 *)(cfg + 0x10);
            dst[9] = *(u32 *)(cfg + 0x10) >> 8;
            dst[10] = *(u32 *)(cfg + 0x10) >> 16;
            dst[11] = *(u32 *)(cfg + 0x10) >> 24;
            dst[12] = *(u32 *)(cfg + 0x14);
            dst[13] = *(u32 *)(cfg + 0x14) >> 8;
            dst[14] = *(u32 *)(cfg + 0x14) >> 16;
            dst[15] = *(u32 *)(cfg + 0x14) >> 24;
            dst[16] = *(u32 *)(cfg + 0x18);
            dst[17] = *(u32 *)(cfg + 0x18) >> 8;
            dst[18] = *(u32 *)(cfg + 0x18) >> 16;
            dst[19] = *(u32 *)(cfg + 0x18) >> 24;
            dst[20] = *(u32 *)(cfg + 0x1C);
            dst[21] = *(u32 *)(cfg + 0x1C) >> 8;
            dst[22] = *(u32 *)(cfg + 0x1C) >> 16;
            dst[23] = *(u32 *)(cfg + 0x1C) >> 24;
            dst += 0x18;
        }
        if (cfg[0x24] != 0) {
            dst[0] = 4;
            dst[1] = 9;
            dst[2] = cfg[0x26];
            dst[3] = cfg[0x27];
            dst[4] = cfg[0x28];
            dst[5] = *(u16 *)(cfg + 0x2A);
            dst[6] = ((s32)*(u16 *)(cfg + 0x2A)) >> 8;
            dst[7] = *(u16 *)(cfg + 0x2C);
            dst[8] = ((s32)*(u16 *)(cfg + 0x2C)) >> 8;
            dst[9] = *(u16 *)(cfg + 0x2E);
            dst[10] = ((s32)*(u16 *)(cfg + 0x2E)) >> 8;
        }
        ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(
            *(void **)(ccb + 0x10), 0, packet);
    }
}

void l2cu_send_peer_config_rsp(void *arg0, void *arg1)
{
    extern char lbl_80319174[];
    extern void fn_8007093C(u32, void *);
    u8 *ccb = (u8 *)arg0;
    u8 *cfg = (u8 *)arg1;
    u8 *packet;
    u8 *dst;
    u16 length;

    length = 0;
    if (cfg[2] != 0) length = 4;
    if (cfg[0x20] != 0) length += 4;
    if (cfg[6] != 0) length += 0x18;
    if (cfg[0x24] != 0) length += 0xB;
    packet = ((void *(*)(u16, u16, u8, u8))l2cu_build_header)(
        *(u16 *)(*(u8 **)(ccb + 0x10) + 0x28), length + 6, 5, ccb[0x36]);
    if (packet == NULL) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80319174);
    } else {
        *(u8 *)(packet + 0x14) = *(u16 *)(ccb + 0x16);
        *(u8 *)(packet + 0x15) = ((s32)*(u16 *)(ccb + 0x16)) >> 8;
        packet[0x16] = 0;
        packet[0x17] = 0;
        *(u8 *)(packet + 0x18) = *(u16 *)cfg;
        *(u8 *)(packet + 0x19) = ((s32)*(u16 *)cfg) >> 8;
        dst = packet + 0x1A;
        if (cfg[2] != 0) {
            dst[0] = 1;
            dst[1] = 2;
            dst[2] = *(u16 *)(cfg + 4);
            dst[3] = ((s32)*(u16 *)(cfg + 4)) >> 8;
            dst += 4;
        }
        if (cfg[0x20] != 0) {
            dst[0] = 2;
            dst[1] = 2;
            dst[2] = *(u16 *)(cfg + 0x22);
            dst[3] = ((s32)*(u16 *)(cfg + 0x22)) >> 8;
            dst += 4;
        }
        if (cfg[6] != 0) {
            dst[0] = 3;
            dst[1] = 0x16;
            dst[2] = cfg[8];
            dst[3] = cfg[9];
            dst[4] = *(u32 *)(cfg + 0xC);
            dst[5] = *(u32 *)(cfg + 0xC) >> 8;
            dst[6] = *(u32 *)(cfg + 0xC) >> 16;
            dst[7] = *(u32 *)(cfg + 0xC) >> 24;
            dst[8] = *(u32 *)(cfg + 0x10);
            dst[9] = *(u32 *)(cfg + 0x10) >> 8;
            dst[10] = *(u32 *)(cfg + 0x10) >> 16;
            dst[11] = *(u32 *)(cfg + 0x10) >> 24;
            dst[12] = *(u32 *)(cfg + 0x14);
            dst[13] = *(u32 *)(cfg + 0x14) >> 8;
            dst[14] = *(u32 *)(cfg + 0x14) >> 16;
            dst[15] = *(u32 *)(cfg + 0x14) >> 24;
            dst[16] = *(u32 *)(cfg + 0x18);
            dst[17] = *(u32 *)(cfg + 0x18) >> 8;
            dst[18] = *(u32 *)(cfg + 0x18) >> 16;
            dst[19] = *(u32 *)(cfg + 0x18) >> 24;
            dst[20] = *(u32 *)(cfg + 0x1C);
            dst[21] = *(u32 *)(cfg + 0x1C) >> 8;
            dst[22] = *(u32 *)(cfg + 0x1C) >> 16;
            dst[23] = *(u32 *)(cfg + 0x1C) >> 24;
            dst += 0x18;
        }
        if (cfg[0x24] != 0) {
            dst[0] = 4;
            dst[1] = 9;
            dst[2] = cfg[0x26];
            dst[3] = cfg[0x27];
            dst[4] = cfg[0x28];
            dst[5] = *(u16 *)(cfg + 0x2A);
            dst[6] = ((s32)*(u16 *)(cfg + 0x2A)) >> 8;
            dst[7] = *(u16 *)(cfg + 0x2C);
            dst[8] = ((s32)*(u16 *)(cfg + 0x2C)) >> 8;
            dst[9] = *(u16 *)(cfg + 0x2E);
            dst[10] = ((s32)*(u16 *)(cfg + 0x2E)) >> 8;
        }
        ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(
            *(void **)(ccb + 0x10), 0, packet);
    }
}

void l2cu_send_peer_disc_req(void *p_ccb) {
    u32 id;
    void *p_buf;
    u8 *p_lcb;

    p_lcb = *(u8 **)((u8 *)p_ccb + 0x10);
    id = *(u8 *)(p_lcb + 0x31) + 1;
    *(u8 *)(p_lcb + 0x31) = id;
    *(volatile u8 *)((u8 *)p_ccb + 0x35) = id;
    p_buf = ((void *(*)(u16, u8, u8, u8, void *))l2cu_build_header)(
        *(u16 *)(*(u8 * volatile *)((u8 *)p_ccb + 0x10) + 0x28),
        4, 6, id, p_lcb
    );
    if (p_buf == NULL) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_80319174);
        return;
    }
    *(u8 *)((u8 *)p_buf + 0x14) = *(u16 *)((u8 *)p_ccb + 0x16);
    *(u8 *)((u8 *)p_buf + 0x15) = *(u16 *)((u8 *)p_ccb + 0x16) >> 8;
    *(u8 *)((u8 *)p_buf + 0x16) = *(u16 *)((u8 *)p_ccb + 0x14);
    *(u8 *)((u8 *)p_buf + 0x17) = *(u16 *)((u8 *)p_ccb + 0x14) >> 8;
    *(u16 *)((u8 *)p_buf + 6) = 0;
    GKI_enqueue((BUFFER_Q *)(*(u8 **)((u8 *)p_ccb + 0x10) + 0x44), p_buf);
    ((void (*)(void *, void *, void *))l2c_link_check_send_pkts)(
        *(u8 **)((u8 *)p_ccb + 0x10), NULL, NULL
    );
}

int l2cu_send_peer_disc_rsp(void *p_lcb, int remote_id, int local_cid, int remote_cid) {
    void *p_buf = l2cu_build_header(*(u16 *)((u8 *)p_lcb + 0x28), 4, 7, remote_id);
    u8 *packet;

    if (p_buf == NULL) {
        if (*(volatile u8 *)lbl_803C4040 < 2) {
            goto done;
        }
        fn_8007093C(0x80001, lbl_80319174);
        goto done;
    }

    packet = p_buf;
    packet[0x14] = local_cid;
    packet[0x15] = local_cid >> 8;
    packet[0x16] = remote_cid;
    packet[0x17] = (u32)remote_cid >> 8;
    *(u16 *)(packet + 6) = 0;
    GKI_enqueue((BUFFER_Q *)((u8 *)p_lcb + 0x44), p_buf);
    ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(p_lcb, 0, 0);

done:
    ;
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

void *l2cu_allocate_ccb(void *arg0, u16 arg1) {
    u8 *ccb = *(u8 **)(lbl_803C4040 + 0x7B0);
    s32 offset;
    u16 index;
    u8 *next;

    if (ccb == NULL) return NULL;

    next = *(u8 **)(ccb + 8);
    *(u8 **)(lbl_803C4040 + 0x7B0) = next;
    ccb[0] = 1;
    offset = (s32)(ccb - (lbl_803C4040 + 0x178));
    index = (u16)(offset / 0x7C);
    *(u16 *)(ccb + 0x14) = index + 0x40;
    *(void **)(ccb + 0x10) = arg0;
    if (*(void **)((u8 *)arg0 + 8) == NULL) {
        *(u8 **)((u8 *)arg0 + 0xC) = ccb;
        *(u8 **)((u8 *)arg0 + 8) = ccb;
        *(u32 *)(ccb + 8) = 0;
        *(u32 *)(ccb + 0xC) = 0;
    } else {
        *(u32 *)(ccb + 8) = 0;
        *(u8 **)(ccb + 0xC) = *(u8 **)((u8 *)arg0 + 0xC);
        *(u8 **)(*(u8 **)((u8 *)arg0 + 0xC) + 8) = ccb;
        *(u8 **)((u8 *)arg0 + 0xC) = ccb;
    }
    *(u16 *)(ccb + 0x3C) = 0xFFFF;
    *(u16 *)(ccb + 0x3A) = 0x2A0;
    *(u16 *)(ccb + 0x38) = 0x2A0;
    ccb[0x59] = 1; ccb[0x41] = 1;
    *(u32 *)(ccb + 0x5C) = 0; *(u32 *)(ccb + 0x44) = 0;
    *(u32 *)(ccb + 0x60) = 0; *(u32 *)(ccb + 0x48) = 0;
    *(u32 *)(ccb + 0x64) = 0; *(u32 *)(ccb + 0x4C) = 0;
    *(u32 *)(ccb + 0x68) = -1; *(u32 *)(ccb + 0x50) = -1;
    *(u32 *)(ccb + 0x6C) = -1; *(u32 *)(ccb + 0x54) = -1;
    ccb[0x34] = 0; *(u32 *)(ccb + 4) = 0; ccb[0x37] = 1;
    *(u8 **)(ccb + 0x28) = ccb;
    return ccb;
}

/* Match note: direct head/tail list updates and a signed state comparison reproduce the target branches and registers. */
void l2cu_release_ccb(void *arg0) {
    u8 *ccb=arg0; u8 *conn=*(u8**)(ccb+0x10); u32 zero=0;
    if(ccb[0]==0)return;
    ccb[0]=0; fn_80070F90(ccb+0x18);
    while(*(void**)(ccb+0x70)!=0) GKI_freebuf(GKI_dequeue((BUFFER_Q*)(ccb+0x70)));
    *(u32*)(ccb+0x10)=0;
    if(*(u8**)(conn+8)==ccb) {
        *(void**)(conn+8)=*(void**)(ccb+8);
        if(*(void**)(conn+8)) *(void**)(*(u8**)(conn+8)+0xC)=0;
    } else if(*(u8**)(conn+0xC)==ccb) {
        *(void**)(conn+0xC)=*(void**)(ccb+0xC);
        *(void**)(*(u8**)(conn+0xC)+8)=0;
    } else {
        *(void**)(*(u8**)(ccb+0xC)+8)=*(void**)(ccb+8);
        *(void**)(*(u8**)(ccb+8)+0xC)=*(void**)(ccb+0xC);
    }
    if(*(void**)(lbl_803C4040+0x7B0)==0) {
        *(void**)(lbl_803C4040+0x7B0)=ccb; *(void**)(lbl_803C4040+0x7B4)=ccb;
        *(u32*)(ccb+8)=zero; *(u32*)(ccb+0xC)=zero;
    } else {
        *(u32*)(ccb+8)=zero; *(void**)(ccb+0xC)=*(void**)(lbl_803C4040+0x7B4);
        *(void**)(*(u8**)(lbl_803C4040+0x7B4)+8)=ccb; *(void**)(lbl_803C4040+0x7B4)=ccb;
    }
    if(conn[0]&&(s32)*(u32*)(conn+4)==4&&*(u32*)(conn+8)==0) {
        u16 timer=*(u16*)(conn+0x58);
        if(timer==0) {
            u8 result=btm_sec_disconnect(*(u16*)(conn+0x28),0x13);
            if(result==1){timer=0x1E;*(u32*)(conn+4)=5;}
            else if(result==0){*(u32*)(conn+4)=5;timer=0xFFFF;}
            else timer=1;
        }
        if(timer!=0xFFFF)btu_start_timer(conn+0x10,2,timer);
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

void *l2cu_find_rcb_by_psm(UINT16 psm) {
    UINT16 xx;
    u8 *p_rcb = lbl_803C4040 + 0x650;

    for (xx = 0; xx < 8; xx++, p_rcb += 0x2C) {
        if ((p_rcb[0]) && (*(UINT16 *)(p_rcb + 2) == psm))
            return p_rcb;
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

void l2cu_process_our_cfg_req(void *p_ccb, void *p_cfg) {
    u8 *ccb = p_ccb;
    u8 *cfg = p_cfg;
    u16 size;
    void *buf;

    if (cfg[2] != 0) {
        u16 requested = *(u16 *)(cfg + 4);
        *(u16 *)(ccb + 0x38) = requested;
        if (requested > 0x69B) {
            *(u16 *)(cfg + 4) = 0x69B;
            *(u16 *)(ccb + 0x38) = 0x69B;
        }
    }
    if (cfg[6] != 0) {
        u32 second;
        u32 first;
        first = *(u32 *)(cfg + 8);
        second = *(u32 *)(cfg + 0xC);
        *(u32 *)(ccb + 0x58) = first;
        *(u32 *)(ccb + 0x5C) = second;
        first = *(u32 *)(cfg + 0x10);
        second = *(u32 *)(cfg + 0x14);
        *(u32 *)(ccb + 0x60) = first;
        *(u32 *)(ccb + 0x64) = second;
        first = *(u32 *)(cfg + 0x18);
        second = *(u32 *)(cfg + 0x1C);
        *(u32 *)(ccb + 0x68) = first;
        *(u32 *)(ccb + 0x6C) = second;
    }
    if (cfg[0x20] != 0 && *(u16 *)(cfg + 0x22) != 0) {
        *(u16 *)(ccb + 0x3C) = *(u16 *)(cfg + 0x22);
        ccb = *(u8 **)(ccb + 0x10);
        if (*(u16 *)(cfg + 0x22) < *(u16 *)(ccb + 0x32)) {
            *(u16 *)(ccb + 0x32) = *(u16 *)(cfg + 0x22);
            if (*(u16 *)(cfg + 0x22) <= 0x4FF) {
                size = (*(u16 *)(cfg + 0x22) * 8 + 3) / 5;
                buf = GKI_getpoolbuf(2);
                if (buf != NULL) fn_80085568(buf, *(u16 *)(ccb + 0x28), size);
            }
        }
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

extern char lbl_80319218[];
void l2cu_create_conn_after_switch(void *arg0) {
    UINT8 temp_r4;
    UINT32 allow_switch;
    UINT32 var_r7;
    UINT8 var_r5;
    UINT8 var_r6;
    void *temp_r3;

    temp_r4 = *((UINT8 *)fn_8007A3A4());
    *(UINT32 *)((UINT8 *)arg0 + 4) = 3;
    allow_switch = (temp_r4 >> 5) & 1;
    temp_r3 = BTM_InqDbRead(*((BD_ADDR *)&((UINT8 *)arg0)[0x2A]));
    if (temp_r3 != NULL) {
        var_r5 = *((UINT8 *)temp_r3 + 0xB);
        var_r6 = *((UINT8 *)temp_r3 + 0xD);
        var_r7 = *(UINT16 *)temp_r3 | 0x8000;
    } else {
        var_r5 = 1;
        var_r6 = 0;
        var_r7 = 0;
    }
    if (!btsnd_hcic_create_conn((UINT8 *)arg0 + 0x2A, 0x18, var_r5, var_r6,
                                var_r7, allow_switch)) {
        if (lbl_803C4040[0] >= 1) {
            fn_8007093C(0x80000, lbl_80319218);
        }
        l2cu_release_lcb(arg0);
        return;
    }
    btu_start_timer((TIMER_LIST_ENT *)((UINT8 *)arg0 + 0x10), 2, 0x3C);
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

u8 l2cu_lcb_disconnecting(void) {
    register u8 result = 0;
    u8 *base = lbl_803C4040;
    u8 *entry = base + 8;
    register u32 i = 0;

    for (; i < 4; i++) {
        if (entry[0] != 0) {
            u8 *link = *(u8 **)(entry + 8);
            if (link == 0 || (s32)*(u32 *)(entry + 4) == 5)
                return 1;
            if (link == *(u8 **)(entry + 0xC) &&
                link[0] != 0 &&
                (u32)(*(u32 *)(link + 4) - 7) <= 1)
                return 1;
        }
        i++;
        if (entry[0x5C] != 0) {
            u8 *link = *(u8 **)(entry + 0x64);
            if (link == 0 || (s32)*(u32 *)(entry + 0x60) == 5)
                return 1;
            if (link == *(u8 **)(entry + 0x68) &&
                link[0] != 0 &&
                (u32)(*(u32 *)(link + 4) - 7) <= 1)
                return 1;
        }
        entry += 0xB8;
    }
    return result;
}

void RFCOMM_Init(void) {
    u8 *p = lbl_803C4828;
    memset(p, 0, 0x418);
    p[0x65] = 1;
    p[0x414] = 5;
    rfcomm_l2cap_if_init();
}

void PORT_StartCnf(void *mux_id, u16 status) {
    s32 i;
    s32 found = 1;
    u8 *mcb = lbl_803C4828;
    u8 *port = mcb + 0x68;
    void (*callback)(s32, u8);

    if (mcb[0x414] >= 4) fn_80070954(0x90003, lbl_80319278, status);
    for (i = 0; i < 5; i++, port += 0xA4) {
        if (*(void **)(port + 0x6C) != mux_id) continue;
        found = 0;
        if (status == 0) {
            RFCOMM_ParNegReq(mux_id, port[0xD], *(u16 *)(port + 0x12));
            continue;
        }
        if (mcb[0x414] >= 2) fn_80070954(0x90001, lbl_80319290, status);
        port[0xE] = status == 4 ? 0x18 : 0xC;
        rfc_release_multiplexer_channel(mux_id);
        *(u32 *)(port + 0x6C) = 0;
        callback = *(void (**)(s32, u8))(port + 0x8C);
        if (callback != 0 && (*(u32 *)(port + 0x88) & 0x8000))
            callback(0x8000, port[0]);
        callback = *(void (**)(s32, u8))(port + 0x90);
        if (callback != 0) callback(0xC, port[0]);
        port_release_port(port);
    }
    if (found) rfc_check_mcb_active(mux_id);
}

void PORT_StartInd(void *arg0) {
    extern char lbl_803192B0[];
    extern void fn_8007093C(u32, void *);
    extern void fn_800934D8(void *, s16);
    u8 *entry;
    s32 i;
    if (lbl_803C4828[0x414] >= 4) {
        fn_8007093C(0x90003, lbl_803192B0);
    }
    for (i = 0, entry = lbl_803C4828 + 0x68; i < 5; i++, entry += 0xA4) {
        void *current = *(void **)(entry + 0x6C);
        if (current == 0 || current == arg0) {
            fn_800934D8(arg0, 0);
            return;
        }
    }
    fn_800934D8(arg0, 1);
}

void PORT_ParNegInd(void *mcb, u8 dlci, u16 mtu, u8 mode, u8 param) {
    u8 *port=(u8*)port_find_mcb_dlci_port(mcb,dlci);
    u16 value; u8 state,limit;
    void (*send)(void*,u16,u16,u16,u16)=(void(*)(void*,u16,u16,u16,u16))fn_800936BC;
    if(lbl_803C4828[0x414]>=4) fn_8007096C(0x90003,lbl_803192C0,dlci,mtu);
    if(port==0) {
        port=(u8*)port_find_dlci_port(dlci);
        if(port==0) {
            rfc_send_dm(mcb,dlci,0); rfc_check_mcb_active(mcb);
            if(lbl_803C4828[0x414]>=4) fn_8007093C(0x90003,lbl_803192E0);
            return;
        }
        *((u8*)mcb+dlci+0x24)=port[0];
    }
    memcpy(port+6,(u8*)mcb+0x62,6); port_select_mtu(port); *(void**)(port+0x6C)=mcb;
    value=*(u16*)(port+0x12); if(value<mtu)mtu=value;
    *(u16*)(port+0x12)=mtu; *(u16*)(port+0x14)=mtu;
    state=((u8*)mcb)[0x72];
    if(state==0){state=mode?2:1;((u8*)mcb)[0x72]=state;}
    if(mode==0){send(mcb,dlci,mtu,0,0);return;}
    if(state==2) {
        *(s16*)(port+0x98)=param;
        if(param==0)port[0x24]=1;
        value=*(u16*)(port+0x9C); limit=7; if(value<7)limit=value;
        *(u16*)(port+0x9A)=limit; send(mcb,dlci,mtu,0xE0,limit);
    } else send(mcb,dlci,mtu,0,0);
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

extern void port_rfc_closed();
extern char lbl_80319454[];
void PORT_DlcReleaseInd(void *arg0, u8 arg1) {
    void *port;
    void *(*find_mcb)(void) = (void *(*)(void))port_find_mcb_dlci_port;

    port = find_mcb();
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, lbl_80319454);
    if (port != 0)
        port_rfc_closed(port, 0x13);
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

extern char lbl_803194E8[];
void PORT_FlowInd(void *p_mcb, s32 dlci, s32 enable_data) {
    u8 *port;
    u8 *p_port = 0;
    u32 events;
    void (*callback)(u32, u8);
    s32 i;
    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, lbl_803194E8, enable_data);
    if (dlci == 0) {
        *(u8 *)((u8 *)p_mcb + 0x71) = enable_data;
    } else {
        p_port = ((u8 *(*)(void *, s32))port_find_mcb_dlci_port)(p_mcb, dlci);
        if (p_port == 0) return;
        p_port[0x24] = (u8)(enable_data == 0);
    }
    for (i = 0, port = lbl_803C4828 + 0x68; i < 5; i++, port += 0xA4) {
        if (dlci == 0) {
            p_port = port;
            if (port[1] == 0 || *(void **)(port + 0x6C) != p_mcb || port[0x68] != 4)
                continue;
        }
        events = port_flow_control_user(p_port);
        events |= port_rfc_send_tx_data(p_port);
        events &= *(u32 *)(p_port + 0x88);
        callback = *(void (**)(u32, u8))(p_port + 0x8C);
        if (callback != 0 && events != 0) callback(events, p_port[0]);
        if (dlci != 0) break;
    }
}

extern char lbl_803194FC[];
extern void fn_800939CC(void *, u8, void *);
extern int port_flow_control_user(void *);
u32 port_rfc_send_tx_data(void *port) {
    u8 *p = (u8 *)port;
    u32 events = 0;
    void *packet;

    if (*(s32 *)(p + 0x28) != 0) {
        for (;;) {
            packet = GKI_dequeue((BUFFER_Q *)(p + 0x18));
            if (packet != 0) {
                if (lbl_803C4828[0x414] >= 4)
                    fn_8007093C(0x90003, lbl_803194FC);

                *(s32 *)(p + 0x28) -= *(u16 *)((u8 *)packet + 2);
                fn_800939CC(*(void **)(p + 0x6c), p[0xd], packet);
                events |= 0x4000;
                if (*(s32 *)(p + 0x28) != 0)
                    continue;
                events |= 4;
                goto flow;
            }
            events |= 4;
            goto flow;
        }
    }

flow:
    if (p[0x24] == 0) {
        void *mcb = *(void **)(p + 0x6c);
        if (mcb != 0 && *((u8 *)mcb + 0x71) == 0)
            events |= port_flow_control_user(port);
    }

    return events & *(u32 *)(p + 0x88);
}

extern u8 lbl_80319514[],lbl_80319540[];
void port_rfc_closed(void *arg0,s32 arg1) {
 void *mcb=*(void **)((u8 *)arg0+0x6C); s32 signals=0;
 if(*((u8 *)arg0+2)==1&&*((u8 *)arg0+0xC)){
  if(lbl_803C4828[0x414]>=4)fn_8007093C(0x90003,lbl_80319514);
  rfc_port_timer_stop(arg0);*((u8 *)arg0+0x68)=0;
  if(mcb){*((u8 *)mcb+*((u8 *)arg0+0xD)+0x24)=0;rfc_check_mcb_active(mcb);*(void **)((u8 *)arg0+0x6C)=0;}
  *((u8 *)arg0+0xD)&=0xFE;return;
 }
 if(*((u8 *)arg0+2)!=3&&*((u8 *)arg0+2)!=0){
  u32 mask=0xFFFFFFF4;
  *((u8 *)arg0+0xF)|=0x10;
  *((u8 *)arg0+0x5F)=*((u8 *)arg0+0x5F)&mask;
  signals=port_get_signal_changes(arg0);
  if(*(u32 *)((u8 *)arg0+0x88)&0x8000)signals|=0x8000;
 }
 if(lbl_803C4828[0x414]>=4)fn_8007096C(0x90003,lbl_80319540,*((u8 *)arg0+2),signals);
 if(*(void **)((u8 *)arg0+0x8C)&&signals)((void (*)(s32,u8))*(void **)((u8 *)arg0+0x8C))(signals,*((u8 *)arg0));
 if(*(void **)((u8 *)arg0+0x90))((void (*)(s32,u8))*(void **)((u8 *)arg0+0x90))(arg1,*((u8 *)arg0));
 *((u8 *)arg0+0x68)=0;port_release_port(arg0);
}

extern char lbl_80319570[];
void port_select_mtu(void *arg0) {
    register char *messages = lbl_80319570;
    register u8 *port = (u8 *)arg0;
    register u16 packet_size;
    register u16 mtu = *(u16 *)(port + 0x12);
    register u16 rate1, rate2, rate3;
    if (mtu == 0) {
        packet_size = btm_get_max_packet_size(port + 6);
        if (packet_size == 0) {
            if (lbl_803C4828[0x414] >= 2) fn_8007093C(0x90001, messages);
            *(u16 *)(port + 0x12) = 0x7F;
        } else if (packet_size <= 0x69F) {
            mtu = ((0x69F / packet_size) * packet_size) - 0xA;
            *(u16 *)(port + 0x12) = mtu;
            if (lbl_803C4828[0x414] >= 5) fn_80070954(0x90004, messages + 0x20, mtu);
        } else {
            *(u16 *)(port + 0x12) = 0x695;
            if (lbl_803C4828[0x414] >= 5) fn_80070954(0x90004, messages + 0x58, 0x695);
        }
    } else if (lbl_803C4828[0x414] >= 5) {
        ((void (*)(u32, void *))fn_80070954)(0x90004, messages + 0x90);
    }
    mtu = *(u16 *)(port + 0x12);
    rate1 = 0x1F40 / mtu;
    rate2 = 0x1388 / mtu;
    rate3 = 0x2EE0 / mtu;
    *(u16 *)(port + 0x9C) = rate1;
    *(u16 *)(port + 0x9E) = rate2;
    *(u16 *)(port + 0xA0) = rate3;
    if (lbl_803C4828[0x414] >= 5) {
        ((void (*)(u32, void *, int, int, int))fn_80070984)(0x90004, messages + 0xB8, rate1, rate2, rate3);
    }
}

void port_release_port(void *arg0) {
    u8 *port = arg0;
    void *buf;
    extern void rfc_check_mcb_active(void *);
    while ((buf = GKI_dequeue((BUFFER_Q *)(port + 0x30))) != 0) GKI_freebuf(buf);
    *(u32 *)(port + 0x40) = 0;
    while ((buf = GKI_dequeue((BUFFER_Q *)(port + 0x18))) != 0) GKI_freebuf(buf);
    *(u32 *)(port + 0x28) = 0;
    port[2] = 0;
    if (port[0x68] == 0) {
        extern void fn_8007093C(u32, void *);
        extern char lbl_80319670[];
        u8 *mcb;
        u8 dlci;
        u8 zero;
        u8 *mcbDlci;
        if (lbl_803C4828[0x414] >= 5) fn_8007093C(0x90004, lbl_80319670);
        mcb = *(u8 **)(port + 0x6C);
        if (mcb != 0) {
            dlci = port[0xD];
            zero = 0;
            mcbDlci = dlci + mcb;
            mcbDlci[0x24] = zero;
            rfc_check_mcb_active(*(void **)(port + 0x6C));
        }
        rfc_port_timer_stop(port);
        memset(port, 0, 0xA4);
    }
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

extern void RFCOMM_ConnectInd(BD_ADDR, UINT16, UINT16, UINT8);
extern void RFCOMM_ConnectCnf(u16, s16);
extern void RFCOMM_ConfigInd(u32, u8 *);
extern void RFCOMM_ConfigCnf_800910D4(u32, u8 *);
extern void fn_800911DC(void);
extern void RFCOMM_DisconnectInd(u16, s32);
extern void RFCOMM_BufDataInd(u32, BT_HDR *);
extern void RFCOMM_CongestionStatusInd(UINT16, BOOLEAN);
void rfcomm_l2cap_if_init(void) {
    tL2CAP_APPL_INFO *info = (tL2CAP_APPL_INFO *)(lbl_803C4828 + 0x14);

    info->pL2CA_ConnectInd_Cb = RFCOMM_ConnectInd;
    info->pL2CA_ConnectCfm_Cb = (tL2CA_CONNECT_CFM_CB *)RFCOMM_ConnectCnf;
    info->pL2CA_ConnectPnd_Cb = 0;
    info->pL2CA_ConfigInd_Cb = (tL2CA_CONFIG_IND_CB *)RFCOMM_ConfigInd;
    info->pL2CA_ConfigCfm_Cb = (tL2CA_CONFIG_CFM_CB *)RFCOMM_ConfigCnf_800910D4;
    info->pL2CA_DisconnectInd_Cb = (tL2CA_DISCONNECT_IND_CB *)RFCOMM_DisconnectInd;
    info->pL2CA_DisconnectCfm_Cb = 0;
    info->pL2CA_QoSViolationInd_Cb = (tL2CA_QOS_VIOLATION_IND_CB *)fn_800911DC;
    info->pL2CA_DataInd_Cb = (tL2CA_DATA_IND_CB *)RFCOMM_BufDataInd;
    info->pL2CA_CongestionStatus_Cb = RFCOMM_CongestionStatusInd;
    L2CA_Register(3, info);
}

void *rfc_alloc_multiplexer_channel(u8 *, s8);
void RFCOMM_ConnectInd(BD_ADDR bd_addr, UINT16 lcid, UINT16 psm, UINT8 id) {
    u8 local_id = id;
    void *mcb;
    u8 *base;
    u32 offset;

    #pragma unused(psm)
    mcb = rfc_alloc_multiplexer_channel(bd_addr, FALSE);
    base = lbl_803C4828;
    offset = (lcid - 0x40) * 4;
    *(void **)((base + 0x3C) + offset) = mcb;
    if (mcb == NULL) {
        L2CA_ConnectRsp(bd_addr, local_id, lcid, 4, 0);
        return;
    }
    *(UINT16 *)((u8 *)mcb + 0x68) = lcid;
    fn_800916F4(mcb, 0xA, (s16 *)&local_id);
}

void RFCOMM_ConnectCnf(u16 arg0, s16 arg1) {
    const char *trace_msg = lbl_803196B8;
    u16 lcid = arg0;
    s32 index = (s32)arg0 - 0x40;
    void *port;
    u16 port_lcid;
    s16 status = arg1;

    if (index >= 10) {
        if (lbl_803C4828[0x414] >= 1)
            fn_80070954(0x90000, (char *)trace_msg, lcid);
        port = NULL;
    } else {
        port = *(void **)(lbl_803C4828 + index * 4 + 0x3C);
        if (port != NULL) {
            port_lcid = *(u16 *)((u8 *)port + 0x68);
            if (port_lcid != lcid) {
                if (lbl_803C4828[0x414] >= 2)
                    fn_8007096C(0x90001, (void *)(trace_msg + 0x1C), lcid, port_lcid);
                port = NULL;
            }
        }
    }
    if (port == NULL) {
        if (lbl_803C4828[0x414] >= 1)
            fn_80070954(0x90000, (void *)(trace_msg + 0x54), lcid);
    } else {
        *(u16 *)((u8 *)port + 0x68) = lcid;
        fn_800916F4(port, 9, &status);
    }
}

void RFCOMM_ConfigInd(u32 arg0, u8 *arg1) {
    s32 index = arg0 - 0x40;
    char *msg = lbl_803196B8;
    void *port;
    if (index >= 10) {
        if (lbl_803C4828[0x414] >= 1) ((void (*)(u32, char *, u32))fn_80070954)(0x90000, msg, arg0);
        port = NULL;
    } else {
        port = *(void **)(lbl_803C4828 + index * 4 + 0x3C);
        if (port != NULL && *(u16 *)((u8 *)port + 0x68) != arg0) {
            if (lbl_803C4828[0x414] >= 2) ((void (*)(u32, char *, u32))fn_8007096C)(0x90001, msg + 0x1C, arg0);
            port = NULL;
        }
    }
    if (port == NULL) {
        if (lbl_803C4828[0x414] >= 1) ((void (*)(u32, char *, u32))fn_80070954)(0x90000, msg + 0x70, arg0);
    } else ((void (*)(void *, u32, u8 *))fn_800916F4)(port, 0xC, arg1);
}

void RFCOMM_ConfigCnf_800910D4(u32 arg0, u8 *arg1) {
    s32 index = (s32)arg0 - 0x40;
    char *trace_msg = lbl_803196B8;
    void *port;

    if (index >= 10) {
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u32))fn_80070954)(
                0x90000, trace_msg, arg0);
        port = NULL;
    } else {
        port = *(void **)(lbl_803C4828 + index * 4 + 0x3C);
        if (port != NULL && *(u16 *)((u8 *)port + 0x68) != arg0) {
            if (lbl_803C4828[0x414] >= 2) {
                char *message = trace_msg + 0x1C;
                u32 severity = 0x90000;
                severity += 1;
                ((void (*)(u32, void *, u32))fn_8007096C)(
                    severity, message, arg0);
            }
            port = NULL;
        }
    }
    if (port == NULL) {
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u32))fn_80070954)(
                0x90000, trace_msg + 0x8C, arg0);
    } else {
        ((void (*)(void *, u32, u8 *))fn_800916F4)(port, 0xB, arg1);
    }
}

void fn_800911DC(void) {

}

void RFCOMM_DisconnectInd(u16 arg0, s32 arg1) {
    s32 temp_r0 = arg0 - 0x40;
    void *var_r30;
    if (temp_r0 >= 0xA) {
        if (*(u8 *)((u8 *)&lbl_803C4828 + 0x414) >= 1) fn_80070954(0x90000, &lbl_803196B8, arg0);
        var_r30 = 0;
    } else {
        var_r30 = *(void **)((u8 *)&lbl_803C4828 + temp_r0 * 4 + 0x3C);
        if (var_r30 && *(u16 *)((u8 *)var_r30 + 0x68) != arg0) {
            if (*(u8 *)((u8 *)&lbl_803C4828 + 0x414) >= 2)
                fn_8007096C(0x90001, (u8 *)&lbl_803196B8 + 0x1C, arg0, *(u16 *)((u8 *)var_r30 + 0x68));
            var_r30 = 0;
        }
    }
    if (arg1) L2CA_DisconnectRsp(arg0);
    if (!var_r30) {
        if (*(u8 *)((u8 *)&lbl_803C4828 + 0x414) >= 2) fn_80070954(0x90001, (u8 *)&lbl_803196B8 + 0xA8, arg0);
    } else fn_800916F4(var_r30, 0xE, 0);
}

extern s32 rfc_parse_data(void *, void *, u8 *);
void RFCOMM_BufDataInd(u32 cid, BT_HDR *p_buf) {
    s32 index = (s32)cid - 0x40;
    char *messages = lbl_803196B8;
    void *p_mcb;
    void *p_port;
    u16 connection_id;
    s32 result;

    if (index >= 10) {
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u32))fn_80070954)(0x90000, messages, cid);
        p_mcb = NULL;
    } else {
        p_mcb = *(void **)(lbl_803C4828 + index * 4 + 0x3C);
        if (p_mcb != NULL) {
            connection_id = *(u16 *)((u8 *)p_mcb + 0x68);
            if ((u32)connection_id != cid) {
                if (lbl_803C4828[0x414] >= 2)
                    ((void (*)(u32, void *, u32, u32))fn_8007096C)(0x90001, messages + 0x1C, cid, connection_id);
                p_mcb = NULL;
            }
        }
    }

    if (p_mcb == NULL) {
        if (lbl_803C4828[0x414] >= 2)
            ((void (*)(u32, void *, u32))fn_80070954)(0x90001, messages + 0xC8, cid);
        GKI_freebuf(p_buf);
        return;
    }

    result = rfc_parse_data(p_mcb, lbl_803C4828, (u8 *)p_buf);
    if ((u8)result == 0x32) {
        GKI_freebuf(p_buf);
        return;
    }

    if (lbl_803C4828[0] == 0) {
        if ((u8)result == 4) {
            rfc_process_mx_message(p_mcb, p_buf);
            return;
        }
        fn_800916F4(p_mcb, (u8)result, NULL);
        GKI_freebuf(p_buf);
        return;
    }

    p_port = port_find_mcb_dlci_port(p_mcb, lbl_803C4828[0]);
    if (p_port == NULL || *(s32 *)((u8 *)p_port + 0x6C) == 0) {
        if ((u8)result != 0) {
            u8 mcb_flag = *(u8 *)((u8 *)p_mcb + 0x6D);
            if (((mcb_flag != 0) && (lbl_803C4828[2] == 0)) ||
                ((mcb_flag == 0) && (lbl_803C4828[2] != 0)))
                rfc_send_dm(p_mcb, lbl_803C4828[0], lbl_803C4828[4]);
            GKI_freebuf(p_buf);
            return;
        }

        p_port = port_find_dlci_port(lbl_803C4828[0]);
        if (p_port == NULL) {
            rfc_send_dm(p_mcb, lbl_803C4828[0], 1);
            GKI_freebuf(p_buf);
            return;
        }
        *((u8 *)p_mcb + lbl_803C4828[0] + 0x24) = *(u8 *)p_port;
        *(void **)((u8 *)p_port + 0x6C) = p_mcb;
    }

    if ((u8)result == 4) {
        if (p_buf->len != 0)
            rfc_port_sm_execute(p_port, (u8)result, p_buf);
        else
            GKI_freebuf(p_buf);
        if (lbl_803C4828[5] != 0)
            rfc_inc_credit(p_port, lbl_803C4828[5]);
    } else {
        rfc_port_sm_execute(p_port, (u8)result, NULL);
        GKI_freebuf(p_buf);
    }
}

void fn_800916D8(void *callback, u32 cid) {
    u32 index = cid - 0x40;
    u8 *base = lbl_803C4828;
    *(void **)(base + 0x3C + index * 4) = callback;
}

extern void rfc_mx_sm_state_idle(void *, s32, void *);
extern void rfc_mx_sm_state_wait_conn_cnf(void *, s32, void *);
extern void rfc_mx_sm_state_configure(void *, s32, void *);
extern void rfc_mx_sm_sabme_wait_ua(void *, s32, void *);
extern void rfc_mx_sm_state_wait_sabme(void *, s32, void *);
extern void rfc_mx_sm_state_connected(void *, s32, void *);
extern void rfc_mx_sm_state_disc_wait_ua(void *, s32, void *);
/* Match note: the seven switch arms preserve the incoming arguments and compile to the original tail-dispatch table. */
void fn_800916F4(void *arg0, s32 arg1, s16 *arg2) {
    switch (((u8 *)arg0)[0x6c]) {
    case 0:
        rfc_mx_sm_state_idle(arg0, arg1, arg2);
        return;
    case 1:
        rfc_mx_sm_state_wait_conn_cnf(arg0, arg1, arg2);
        return;
    case 2:
        rfc_mx_sm_state_configure(arg0, arg1, arg2);
        return;
    case 3:
        rfc_mx_sm_sabme_wait_ua(arg0, arg1, arg2);
        return;
    case 4:
        rfc_mx_sm_state_wait_sabme(arg0, arg1, arg2);
        return;
    case 5:
        rfc_mx_sm_state_connected(arg0, arg1, arg2);
        return;
    case 6:
        rfc_mx_sm_state_disc_wait_ua(arg0, arg1, arg2);
        return;
    }
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
    extern void rfc_send_sabme();
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

void rfc_port_sm_execute(void *p_port, u16 event, void *p_data) {
    if (p_port == 0) {
        if (lbl_803C4828[0x414] >= 2)
            fn_80070954(0x90001, lbl_80319AB0, event);
        return;
    }

    switch (*((u8 *)p_port + 0x68)) {
    case 0:
        rfc_port_sm_state_closed(p_port, event, p_data);
        break;
    case 1:
        rfc_port_sm_sabme_wait_ua(p_port, event, p_data);
        break;
    case 2:
        rfc_port_sm_orig_wait_sec_check(p_port, event, p_data);
        break;
    case 3:
        rfc_port_sm_term_wait_sec_check(p_port, event, p_data);
        break;
    case 4:
        rfc_port_sm_opened(p_port, event, p_data);
        break;
    case 5:
        rfc_port_sm_disc_wait_ua(p_port, event, p_data);
        break;
    default:
        break;
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
    extern void rfc_send_sabme();
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

void rfc_port_sm_opened(void *p_port, u16 event, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319AC4[];
    extern char lbl_80319CE8[];
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void fn_80070954(u32, void *, u16);
    extern void rfc_send_disc();
    extern void rfc_port_closed(void *);
    extern void fn_8009578C(void *);
    extern void rfc_send_ua();
    extern void Port_TimeOutCloseMux(void *);

    u8 *port = (u8 *)p_port;

    switch (event) {
    case 9:
        if (lbl_803C4828[0x414] >= 1) {
            fn_8007096C(0x90000, lbl_80319AC4, port[0x68], event);
        }
        return;

    case 12:
        rfc_port_timer_start(p_port, 3);
        ((void (*)(void *, u8))rfc_send_disc)(*(void **)(port + 0x6C), port[0xD]);
        port[0x69] = 0;
        port[0x68] = 5;
        return;

    case 13:
        rfc_port_closed(p_port);
        return;

    case 14:
        if (*(u8 *)(*(u8 **)(port + 0x6C) + 0x72) == 2
            && *(u16 *)((u8 *)p_data + 2) < *(u16 *)(port + 0x14)
            && port[0x3D] == 0
            && *(u16 *)(port + 0x9C) > *(u16 *)(port + 0x9A)) {
            *(u16 *)((u8 *)p_data + 6) = (u8)(*(u16 *)(port + 0x9C) - *(u16 *)(port + 0x9A));
            *(u16 *)(port + 0x9A) = *(u16 *)(port + 0x9C);
        } else {
            *(u16 *)((u8 *)p_data + 6) = 0;
        }
        rfc_send_buf_uih(*(void **)(port + 0x6C), port[0xD], p_data);
        fn_8009578C(p_port);
        return;

    case 1:
        return;

    case 0:
        ((void (*)(void *, u8))rfc_send_ua)(*(void **)(port + 0x6C), port[0xD]);
        return;

    case 2:
        PORT_DlcReleaseInd(*(void **)(port + 0x6C), port[0xD]);
        rfc_port_closed(p_port);
        return;

    case 3:
        port[0x68] = 0;
        ((void (*)(void *, u8))rfc_send_ua)(*(void **)(port + 0x6C), port[0xD]);
        PORT_DlcReleaseInd(*(void **)(port + 0x6C), port[0xD]);
        return;

    case 4:
        PORT_DataInd(*(void **)(port + 0x6C), port[0xD], p_data);
        return;

    case 5:
        Port_TimeOutCloseMux(*(void **)(port + 0x6C));
        if (lbl_803C4828[0x414] >= 1) {
            fn_8007096C(0x90000, lbl_80319AC4, port[0x68], event);
        }
        return;
    }

    if (lbl_803C4828[0x414] >= 2) {
        fn_80070954(0x90001, lbl_80319CE8, event);
    }
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

void rfc_set_port_state(void *, void *);
void rfc_process_rpn(void *mcb, s32 a1, void *a2, void *rpn) {
    u8 state[9];
    u8 *port;
    u8 *p2;
    u8 ctrl;
    u16 bits;
    u8 t0, t1;

    port = (u8 *)port_find_mcb_dlci_port(mcb, *(u8 *)rpn);
    if (port == NULL) {
        if (a1 == 0) return;
        memset(state, 0, 9);
        rfc_set_port_state(state, rpn);
        PORT_PortNegInd(mcb, *(u8 *)rpn, state, *(u16 *)((u8 *)rpn + 0x12));
        return;
    }
    if (a1 != 0 && a2 != 0) {
        t1 = port[0x52]; t0 = port[0x51]; state[0] = t0; state[1] = t1;
        t1 = port[0x54]; t0 = port[0x53]; state[2] = t0; state[3] = t1;
        t1 = port[0x56]; t0 = port[0x55]; state[4] = t0; state[5] = t1;
        t1 = port[0x58]; t0 = port[0x57]; state[6] = t0; state[7] = t1;
        state[8] = port[0x59];
        rfc_send_rpn(mcb, *(u8 *)rpn, 0, port + 0x51, 0);
        return;
    }
    t1 = port[0x52]; t0 = port[0x51]; state[0] = t0; state[1] = t1;
    t1 = port[0x54]; t0 = port[0x53]; state[2] = t0; state[3] = t1;
    t1 = port[0x56]; t0 = port[0x55]; state[4] = t0; state[5] = t1;
    t1 = port[0x58]; t0 = port[0x57]; state[6] = t0; state[7] = t1;
    state[8] = port[0x59];
    rfc_set_port_state(state, rpn);
    if (a1 != 0) {
        PORT_PortNegInd(mcb, *(u8 *)rpn, state, *(u16 *)((u8 *)rpn + 0x12));
        return;
    }
    p2 = (u8 *)port_find_mcb_dlci_port(mcb, *(u8 *)rpn);
    if (p2 == NULL) return;
    if (p2[0x69] & 6) {
        rfc_port_timer_stop(p2);
        ctrl = p2[0x69];
        if (ctrl & 2) {
            p2[0x69] = ctrl & ~2;
            t1 = state[1]; t0 = state[0]; p2[0x51] = t0; p2[0x52] = t1;
            t1 = state[3]; t0 = state[2]; p2[0x53] = t0; p2[0x54] = t1;
            t1 = state[5]; t0 = state[4]; p2[0x55] = t0; p2[0x56] = t1;
            t1 = state[7]; t0 = state[6]; p2[0x57] = t0; p2[0x58] = t1;
            p2[0x59] = state[8];
            if (state[5] == 0xC || state[5] == 0x30) {
                *(u16 *)((u8 *)rpn + 0x12) = 0x3F7F;
            } else {
                p2[0x56] = 0xC;
                p2[0x69] |= 4;
                rfc_send_rpn(mcb, *(u8 *)rpn, 1, p2 + 0x51, 0xC00);
                rfc_port_timer_start(p2, 0x3C);
                return;
            }
        } else {
            p2[0x69] = ctrl & ~4;
        }
        bits = *(u16 *)((u8 *)rpn + 0x12);
        if ((bits & 0xC00) == 0xC00 || (bits & 0x3000) == 0x3000) {
            PORT_PortNegCnf(mcb, p2[0xD], state, 0);
            return;
        }
        ctrl = p2[0x56];
        if (ctrl == 0xC) {
            p2[0x56] = 0x30;
            p2[0x69] |= 4;
            rfc_send_rpn(mcb, *(u8 *)rpn, 1, p2 + 0x51, 0x3000);
            rfc_port_timer_start(p2, 0x3C);
            return;
        }
        if (ctrl == 0x30) {
            p2[0x56] = 0;
            PORT_PortNegCnf(mcb, p2[0xD], state, 0);
        }
    }
}

void rfc_process_msc(void *mcb, s32 is_command, void *message) {
    u8 flags = *((u8 *)message + 9);
    u8 *port = port_find_mcb_dlci_port(mcb, *(u8 *)message);
    u8 data[5];
    u8 flow;

    if (port == 0) return;
    data[0] = 0;
    if (flags & 0x04) data[0] |= 1;
    if (flags & 0x08) data[0] |= 2;
    if (flags & 0x40) data[0] |= 4;
    if (flags & 0x80) data[0] |= 8;
    flow = (flags >> 1) & 1;
    data[4] = flow;
    data[1] = *((u8 *)message + 0xA) ? *((u8 *)message + 0xB) : 0;
    data[2] = 0;
    data[3] = 1;
    if (is_command != 0) {
        rfc_send_msc(mcb, *(u8 *)message, 0, data);
        if (*((u8 *)*(void **)(port + 0x6C) + 0x72) != 2) {
            port[0x63] = flow;
            if (flow != port[0x24])
                PORT_FlowInd(mcb, *(u8 *)message, (u8)(flow == 0));
        }
        PORT_ControlInd(mcb, *(u8 *)message, data);
        return;
    }
    if (port[0x69] & 8) {
        port[0x69] &= ~8;
        rfc_port_timer_stop(port);
        PORT_ControlCnf(*(void **)(port + 0x6C), port[0xD], data);
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
        rfc_send_pn(p, a1, 0, a2, a3, a4);
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

void rfc_send_sabme(void *arg0, s32 arg1, void *arg2) {
    BT_HDR *p_buf;
    u8 *p_data;
    u8 cr;
    u8 command = 0x3F;
    u8 initiator = *(u8 *)((u8 *)arg0 + 0x6D);

    cr = (u8)((((initiator && 1) || (!initiator && !1)) << 1));
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == 0)
        return;

    p_data = (u8 *)(p_buf + 1) + 9;
    p_buf->offset = 9;
    p_data[0] = (u8)(1 | cr | ((u8)arg1 << 2));
    p_data[1] = command;
    p_data[2] = 1;
    p_data[3] = fn_8009504C(3, (u8 *)(p_buf + 1) + 9, command);
    p_buf->len = 4;
    rfc_check_send_cmd(arg0, p_buf);
}

void rfc_send_ua(void *arg0, s32 arg1, void *arg2) {
    BT_HDR *p_buf;
    u8 *p_data;
    u8 cr;

    cr = (u8)((((*(u8 *)((u8 *)arg0 + 0x6D) == 0) ? 1 : 0) << 1));
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == 0)
        return;

    p_buf->offset = 9;
    p_data = (u8 *)(p_buf + 1) + 9;
    *p_data++ = 1 | cr | (arg1 << 2);
    *p_data++ = 0x73;
    *p_data++ = 1;
    *p_data = fn_8009504C(3, p_data, 0x73);
    p_buf->len = 4;
    rfc_check_send_cmd(arg0, p_buf);
}

void rfc_send_dm(void *arg0, u8 arg1, u8 arg2) {
    u8 *data;
    u8 *buf;
    u8 flag;
    u8 control;
    u8 shifted;
    u8 command;

    flag = 1;
    if (((u8 *)arg0)[0x6D] != 0) {
        flag = 0;
    }
    control = (u8)(flag << 1);
    buf = (u8 *)GKI_getpoolbuf(2);
    if (buf != 0) {
        *(u16 *)(buf + 4) = 9;
        data = buf + 0x11;
        control |= 1;
        shifted = (u8)(arg1 << 2);
        command = (u8)(control | shifted);
        data[0] = command;
        data[1] = (u8)((((-(s32)arg2 | arg2) >> 31) & 0x10) | 0xF);
        data[2] = 1;
        data[3] = fn_8009504C(3, data, command);
        *(u16 *)(buf + 2) = 4;
        rfc_check_send_cmd(arg0, buf);
    }
}

void rfc_send_disc(void *arg0, s32 arg1, void *arg2) {
    BT_HDR *p_buf;
    u8 *p_data;
    u8 is_initiator;
    u8 cr;

    is_initiator = *((u8 *)arg0 + 0x6D);
    cr = (u8)((((is_initiator) && 1) || (!(is_initiator) && !1)) << 1);
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == 0)
        return;

    p_buf->offset = 9;
    p_data = (u8 *)(p_buf + 1) + 9;
    *p_data++ = 1 | cr | (((u8)arg1) << 2);
    p_data[0] = 0x53;
    p_data[1] = 1;
    p_data[2] = fn_8009504C(3, (u8 *)(p_buf + 1) + 9, 0x53);
    p_buf->len = 4;
    rfc_check_send_cmd(arg0, p_buf);
}

void rfc_send_pn(void *p_mcb, s32 dlci, s32 is_command, s32 mtu, s32 cl, s32 k) {
    u8 *buf;
    u8 *p_data;
    s32 sign;

    buf = (u8 *)GKI_getpoolbuf(2);
    if (buf == NULL)
        return;
    *(u16 *)(buf + 4) = 0xC;
    p_data = buf + 0x14;
    sign = -is_command | is_command;
    *p_data++ = (u8)(((sign >> 31) & 2) | 0x81);
    *p_data++ = 0x11;
    *p_data++ = (u8)dlci;
    *p_data++ = (u8)cl;
    if (is_command != 0)
        *p_data++ = 0;
    else
        *p_data++ = lbl_803C4828[0xB];
    *p_data++ = 0;
    *p_data++ = (u8)mtu;
    *p_data++ = (u8)((u16)mtu >> 8);
    *p_data++ = 0;
    *p_data = (u8)k;
    *(u16 *)(buf + 2) = 0xA;
    rfc_send_buf_uih(p_mcb, 0, (BT_HDR *)buf);
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
    u16 new_len;
    u16 count;
    u8 *src;
    u16 i;
    u8 *dst;
    u8 byte;

    if (len < 0x10) {
        count = *(u16 *)(p + 2);
        src = p + len + count + 7;
        dst = p + count;
        dst += 0x17;
        i = 0;
        while (i < *(u16 *)(p + 2)) {
            byte = *src;
            ++i;
            --src;
            *dst = byte;
            --dst;
        }
        *(u16 *)(p + 4) = 0x10;
    }
    new_len = *(u16 *)(p + 4) - 2;
    *(u16 *)(p + 4) = new_len;
    p[new_len + 8] = (((-arg1 | arg1) >> 31) & 2) | 0x21;
    p[new_len + 9] = (*(u16 *)(p + 2) << 1) | 1;
    count = *(u16 *)(p + 2);
    *(u16 *)(p + 2) = count + 2;
    rfc_send_buf_uih((void *)arg0, 0);
}

void rfc_send_credit(void *p_mcb, UINT8 credits, UINT8 arg2, u32 arg3) {
    BT_HDR *p_buf;
    UINT8 *data;
    UINT8 *p_check;
    UINT8 enabled = 1;
    UINT8 state;

    if (*((UINT8 *)p_mcb + 0x6D) == 0) {
        enabled = 0;
    }
    state = enabled << 1;

    p_buf = (BT_HDR *)GKI_getpoolbuf(2);
    if (p_buf == NULL) return;

    p_buf->offset = 9;
    data = (UINT8 *)(p_buf + 1);
    data[9] = state | 1 | (credits << 2);
    p_check = data + 13;
    data[10] = 0xFF;
    data[11] = 1;
    data[12] = arg2;
    *p_check = fn_8009504C(2, (UINT8 *)p_buf + p_buf->offset + 8, 9);
    p_buf->len = 5;
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

#pragma push
#pragma scheduling invalid_target
u8 fn_80095084(s32 arg0, void *arg1) {
    volatile u8 *table = lbl_802EEC40;
    u8 crc = 0xFF;

    do {
        crc = table[crc ^ *(u8 *)arg1];
        arg1 = (u8 *)arg1 + 1;
    } while ((u16)arg0-- != 0);

    crc = lbl_802EEC40[crc ^ (u32)arg1];
    return crc == 0xCF;
}
#pragma pop
extern char lbl_80319EB0[];
void *rfc_alloc_multiplexer_channel(u8 *addr, s8 arg1) {
    s32 index = 0;
    u8 *base = lbl_803C4828;
    u8 *channel;

    if (base[0x408] != 0 && memcmp(base + 0x3FE, addr, 6) == 0) {
        if (base[0x414] >= 4) fn_8007093C(0x90003, lbl_80319EB0);
        channel = base + index * 0x78 + 0x39C;
        fn_80070F90(channel);
        return channel;
    }

    index = base[0x65] + 1;
    if (index >= 1) index = 0;
    channel = base + index * 0x78 + 0x39C;
    if (channel[0x6C] == 0) {
        memset(channel, 0, 0x78);
        memcpy(channel + 0x62, addr, 6);
        fn_8006D4C4(channel + 0x18);
        channel[0x6D] = arg1;
        if (base[0x414] >= 4) fn_80070954(0x90003, lbl_80319EC0, 0x3C);
        *(void **)(channel + 0x10) = channel;
        btu_start_timer(channel, 0xB, 0x3C);
        base[0x65] = index;
        return channel;
    }
    return 0;
}

void rfc_release_multiplexer_channel(void *arg0) {
    u8 *channel = (u8 *)arg0;
    void *buffer;
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, lbl_80319EB0);
    fn_80070F90(channel);
    while ((buffer = GKI_dequeue((BUFFER_Q *)(channel + 0x18))) != 0)
        GKI_freebuf(buffer);
    memset(channel, 0, 0x78);
    channel[0x6C] = 0;
}

void rfc_timer_start(void *arg0, u16 arg1) {
    if (lbl_803C4828[0x414] >= 4) {
        fn_80070954(0x90003, lbl_80319EC0, arg1);
    }
    *(void **)((u8 *)arg0 + 0x10) = arg0;
    btu_start_timer(arg0, 0xB, arg1);
}

void rfc_timer_stop(void *arg0) {
    if (lbl_803C4828[0x414] >= 4) {
        fn_8007093C(0x90003, lbl_80319EB0);
    }
    fn_80070F90(arg0);
}

extern char lbl_80319EE0[];
void rfc_port_timer_start(void *arg0, u16 arg1) {
    TIMER_LIST_ENT *timer = (TIMER_LIST_ENT *)((u8 *)arg0 + 0x70);
    if (lbl_803C4828[0x414] >= 4) {
        fn_80070954(0x90003, lbl_80319EE0, arg1);
    }
    *(void **)((u8 *)timer + 0x10) = arg0;
    btu_start_timer(timer, 0xC, arg1);
}

extern char lbl_80319F04[];
void rfc_port_timer_stop(void *arg0) {
    if (lbl_803C4828[0x414] >= 4) {
        fn_8007093C(0x90003, lbl_80319F04);
    }
    fn_80070F90((u8 *)arg0 + 0x70);
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

/* Match note: widening the halfword state and guarding non-12 values preserves the signed checks and tail-call order. */
void fn_80095518(void *arg0) {
    s32 state = (s32)*(u16 *)((u8 *)arg0 + 0x14);
    if (state != 12) {
        if (state >= 12) return;
        if (state < 11) return;
        fn_800916F4(*(void **)((u8 *)arg0 + 0x10), 5, 0);
        return;
    }
    rfc_port_sm_execute(*(void **)((u8 *)arg0 + 0x10), 5, 0);
}

void rfc_sec_check_complete(void *unused, void *arg0, s8 arg1) {
    if (*((u8 *)arg0 + 1) == 0) return;
    if (*((u8 *)arg0 + 0x68) != 2 && *((u8 *)arg0 + 0x68) != 3) return;
    rfc_port_sm_execute(arg0, 15, &arg1);
}

void rfc_port_closed(void *arg0) {
    extern unsigned char lbl_803C4828[];
    extern char lbl_80319EB0[];
    extern void port_rfc_closed(void *, s32);
    unsigned char *port = arg0;
    unsigned char *mcb = *(unsigned char **)(port + 0x6C);
    u16 i;
    if (lbl_803C4828[0x414] >= 5) fn_8007093C(0x90004, lbl_80319EB0 + 0x68);
    if (lbl_803C4828[0x414] >= 4) fn_8007093C(0x90003, lbl_80319EB0 + 0x54);
    fn_80070F90(port + 0x70);
    port[0x68] = 0;
    if (mcb != 0) {
        mcb[port[0xD] + 0x24] = 0;
        port[0xD] = 0;
        for (i = 0; i < 0x3D; i++) {
            if (mcb[i + 0x24] != 0) {
                mcb[0x74] = 0;
                break;
            }
        }
        if (i == 0x3D) {
            if (mcb[0x74] != 0) {
                mcb[0x74] = 0;
                fn_800916F4(mcb, 8, 0);
            } else {
                if (lbl_803C4828[0x414] >= 4)
                    fn_80070954(0x90003, lbl_80319EB0 + 0x10, 2);
                *(void **)(mcb + 0x10) = mcb;
                btu_start_timer(mcb, 0xB, 2);
            }
        }
    }
    port_rfc_closed(arg0, 0x13);
}

extern char lbl_80319F28[];
void rfc_inc_credit(struct t_port_info *p_port, u8 credit) {
    u16 newCredit;
    if ((*(u8 **)((u8 *)p_port + 0x6C))[0x72] != 2)
        return;
    newCredit = (*(u16 *)((u8 *)p_port + 0x98) += credit);
    if (lbl_803C4828[0x414] >= 4)
        fn_80070954(0x90003, lbl_80319F28, newCredit);
    if (*((u8 *)p_port + 0x24) == 1)
        PORT_FlowInd(*(void **)((u8 *)p_port + 0x6C), *((u8 *)p_port + 0xD), 1);
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

extern char lbl_80319F40[];
BOOLEAN SDP_InitDiscoveryDb(tSDP_DISCOVERY_DB *p_db, UINT32 len, UINT16 num_uuid,
                             tSDP_UUID *p_uuid_list, UINT16 num_attr,
                             UINT16 *p_attr_list) {
    UINT16 xx;

    if (p_db == NULL || len < 0x6C || num_attr > 0xC || num_uuid > 3) {
        if (lbl_803C4C40[0x4630] >= 1) {
            ((void (*)(u32, void *, void *, u32, u16, u16))fn_8007099C)(
                0xA0000, lbl_80319F40, p_db, len, num_uuid, num_attr);
        }
        return FALSE;
    }

    memset(p_db, 0, len);
    p_db->mem_size = len - 0x6C;
    p_db->mem_free = p_db->mem_size;
    p_db->p_first_rec = NULL;
    *(UINT8 **)((UINT8 *)p_db + 0x68) = (UINT8 *)p_db + 0x6C;

    for (xx = 0; xx < num_uuid; xx++) {
        p_db->uuid_filters[xx] = *p_uuid_list++;
    }
    p_db->num_uuid_filters = num_uuid;

    for (xx = 0; xx < num_attr; xx++) {
        p_db->attr_filters[xx] = *p_attr_list++;
    }

    sdpu_sort_attr_list(num_attr, p_db);
    p_db->num_attr_filters = num_attr;
    return TRUE;
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

tSDP_DISC_REC *SDP_FindServiceInDb(tSDP_DISCOVERY_DB *p_db, UINT16 service_uuid, tSDP_DISC_REC *p_start_rec) {
    tSDP_DISC_REC *p_rec;
    tSDP_DISC_ATTR *p_attr;
    tSDP_DISC_ATTR *p_sattr;
    if (p_start_rec == NULL)
        p_rec = p_db->p_first_rec;
    else
        p_rec = p_start_rec->p_next_rec;
    while (p_rec != NULL) {
        p_attr = p_rec->p_first_attr;
        while (p_attr != NULL) {
            if (p_attr->attr_id == ATTR_ID_SERVICE_CLASS_ID_LIST &&
                SDP_DISC_ATTR_TYPE(p_attr->attr_len_type) == DATA_ELE_SEQ_DESC_TYPE) {
                for (p_sattr = p_attr->attr_value.v.p_sub_attr; p_sattr != NULL; p_sattr = p_sattr->p_next_attr) {
                    if (SDP_DISC_ATTR_TYPE(p_sattr->attr_len_type) == UUID_DESC_TYPE &&
                        SDP_DISC_ATTR_LEN(p_sattr->attr_len_type) == 2 &&
                        p_sattr->attr_value.v.u16 == service_uuid)
                        return p_rec;
                }
                break;
            } else if (p_attr->attr_id == ATTR_ID_SERVICE_ID &&
                SDP_DISC_ATTR_TYPE(p_attr->attr_len_type) == UUID_DESC_TYPE &&
                SDP_DISC_ATTR_LEN(p_attr->attr_len_type) == 2 &&
                p_attr->attr_value.v.u16 == service_uuid) {
                return p_rec;
            }
            p_attr = p_attr->p_next_attr;
        }
        p_rec = p_rec->p_next_rec;
    }
    return NULL;
}

tSDP_DISC_REC *SDP_FindServiceUUIDInDb(tSDP_DISCOVERY_DB *p_db, tBT_UUID *p_uuid, tSDP_DISC_REC *p_start_rec) {
    tSDP_DISC_REC *p_rec;
    tSDP_DISC_ATTR *p_attr;
    tSDP_DISC_ATTR *p_sub_attr;

    p_rec = (p_start_rec == NULL) ? p_db->p_first_rec : p_start_rec->p_next_rec;
    while (p_rec != NULL) {
        p_attr = p_rec->p_first_attr;
        while (p_attr != NULL) {
            if (p_attr->attr_id == ATTR_ID_SERVICE_CLASS_ID_LIST &&
                SDP_DISC_ATTR_TYPE(p_attr->attr_len_type) == DATA_ELE_SEQ_DESC_TYPE) {
                p_sub_attr = p_attr->attr_value.v.p_sub_attr;
                while (p_sub_attr != NULL) {
                    if (SDP_DISC_ATTR_TYPE(p_sub_attr->attr_len_type) == UUID_DESC_TYPE &&
                        sdpu_compare_uuid_with_attr(p_uuid, p_sub_attr))
                        return p_rec;
                    p_sub_attr = p_sub_attr->p_next_attr;
                }
                break;
            }
            if (p_attr->attr_id == ATTR_ID_SERVICE_ID &&
                SDP_DISC_ATTR_TYPE(p_attr->attr_len_type) == UUID_DESC_TYPE &&
                sdpu_compare_uuid_with_attr(p_uuid, p_attr))
                return p_rec;
            p_attr = p_attr->p_next_attr;
        }
        p_rec = p_rec->p_next_rec;
    }
    return NULL;
}

UINT16 SDP_SetLocalDiRecord(tSDP_DI_RECORD *p_device_info, UINT32 *p_handle) {
    UINT16 result = 0;
    UINT32 handle;
    UINT16 di_uuid = 0x1200;
    UINT8 temp_u16[2];
    UINT8 *p_temp;

    *p_handle = 0;
    if (p_device_info == NULL) return 0xB;

    if (p_device_info->primary_record == TRUE &&
        *(UINT32 *)(lbl_803C4C40 + 0x121C) != 0) {
        handle = *(UINT32 *)(lbl_803C4C40 + 0x121C);
    } else {
        handle = SDP_CreateRecord();
        if (handle == 0) return 6;
    }

    *p_handle = handle;
    if (!SDP_AddServiceClassIdList(handle, 1, &di_uuid)) result = 7;

    if (result == 0) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, 9);
        if (!SDP_AddAttribute(handle, 0x200, 1, 2, temp_u16)) result = 7;
    }

    if (result == 0 && p_device_info->client_executable_url[0] != '\0') {
        if (!(((UINT32)(strlen(p_device_info->client_executable_url) + 1) <= 0x50U) &&
              SDP_AddAttribute(handle, 0xB, 8,
                               (UINT32)(strlen(p_device_info->client_executable_url) + 1),
                               (UINT8 *)p_device_info->client_executable_url))) result = 7;
    }

    if (result == 0 &&
        (p_device_info->client_executable_url + 0x50)[0] != '\0') {
        if (!(((UINT32)(strlen(p_device_info->client_executable_url + 0x50) + 1) <= 0x50U) &&
              SDP_AddAttribute(handle, 0x101, 4,
                               (UINT32)(strlen(p_device_info->client_executable_url + 0x50) + 1),
                               (UINT8 *)(p_device_info->client_executable_url + 0x50)))) result = 7;
    }

    if (result == 0 &&
        (p_device_info->client_executable_url + 0xA0)[0] != '\0') {
        if (!(((UINT32)(strlen(p_device_info->client_executable_url + 0xA0) + 1) <= 0x50U) &&
              SDP_AddAttribute(handle, 0xA, 8,
                               (UINT32)(strlen(p_device_info->client_executable_url + 0xA0) + 1),
                               (UINT8 *)(p_device_info->client_executable_url + 0xA0)))) result = 7;
    }

    if (result == 0) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->vendor);
        if (!SDP_AddAttribute(handle, 0x201, 1, 2, temp_u16)) result = 7;
    }
    if (result == 0) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->product);
        if (!SDP_AddAttribute(handle, 0x202, 1, 2, temp_u16)) result = 7;
    }
    if (result == 0) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->version);
        if (!SDP_AddAttribute(handle, 0x203, 1, 2, temp_u16)) result = 7;
    }
    if (result == 0) {
        if (!SDP_AddAttribute(handle, 0x204, 5, 1,
                              (UINT8 *)&p_device_info->primary_record)) result = 7;
    }
    if (result == 0) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->vendor_id_source);
        if (!SDP_AddAttribute(handle, 0x205, 1, 2, temp_u16)) result = 7;
    }

    if (result != 0) {
        SDP_DeleteRecord(handle);
    } else if (p_device_info->primary_record == TRUE) {
        *(UINT32 *)(lbl_803C4C40 + 0x121C) = handle;
    }
    return result;
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

extern BOOLEAN find_uuid_in_seq(UINT8 *p, UINT32 seq_len, UINT8 *p_uuid, UINT16 uuid_len, int nest_level);
tSDP_RECORD *sdp_db_service_search(tSDP_RECORD *p_rec, tSDP_UUID_SEQ *p_seq) {
    UINT16 xx, yy;
    UINT8 *p_attr;
    UINT8 *p_end = lbl_803C4C40 + 0x1224 +
        (*(UINT16 *)(lbl_803C4C40 + 0x1222) * 0x298);
    UINT8 *base;

    if (p_rec == NULL)
        base = lbl_803C4C40 + 0x1224;
    else
        base = (UINT8 *)p_rec + 0x298;

    for (; base < p_end; base += 0x298) {
        for (yy = 0; yy < p_seq->num_uids; yy++) {
            p_attr = base + 0xC;
            for (xx = 0; xx < *(UINT16 *)(base + 8); xx++, p_attr += 0xC) {
                UINT8 type = p_attr[0xA];
                if (type == 3) {
                    if (sdpu_compare_uuid_arrays(*(UINT8 **)(p_attr + 4), *(UINT32 *)p_attr,
                            &p_seq->uuid_entry[yy].value[0], p_seq->uuid_entry[yy].len))
                        break;
                } else if (type == 6) {
                    if (find_uuid_in_seq(*(UINT8 **)(p_attr + 4), *(UINT32 *)p_attr,
                            &p_seq->uuid_entry[yy].value[0], p_seq->uuid_entry[yy].len, 0))
                        break;
                }
            }
            if (xx == *(UINT16 *)(base + 8))
                break;
        }
        if (yy == p_seq->num_uids)
            return (tSDP_RECORD *)base;
    }
    return NULL;
}

BOOLEAN find_uuid_in_seq(UINT8 *p, UINT32 seq_len, UINT8 *p_uuid, UINT16 uuid_len, int nest_level)
{
    UINT8 *p_end = p + seq_len;
    UINT8 type;
    UINT32 len;

    if (nest_level > 3)
        return FALSE;

    while (p < p_end)
    {
        type = *p++;
        p = sdpu_get_len_from_type(p, type, &len);
        type = type >> 3;
        if (type == UUID_DESC_TYPE)
        {
            if (sdpu_compare_uuid_arrays(p, len, p_uuid, uuid_len))
                return TRUE;
        }
        else if (type == DATA_ELE_SEQ_DESC_TYPE)
        {
            if (find_uuid_in_seq(p, len, p_uuid, uuid_len, nest_level + 1))
                return TRUE;
        }
        p = p + len;
    }
    return FALSE;
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

u32 SDP_CreateRecord(void) {
    u8 *base = lbl_803C4C40 + 0x121C;
    u32 count;
    u32 handle;
    u8 bytes[4];
    u16 stored_count;

    if (*(u16 *)(lbl_803C4C40 + 0x1222) < 0x14) {
        memset(base + (*(u16 *)(lbl_803C4C40 + 0x1222) * 0x298) + 8, 0, 0x298);
        count = *(u16 *)(base + 6);
        if (count != 0) {
            handle = *(u32 *)(base + ((count - 1) * 0x298) + 8) + 1;
        } else {
            handle = 0x10000;
        }
        bytes[1] = (u8)(handle >> 16);
        bytes[0] = (u8)(handle >> 24);
        *(u32 *)(base + (count * 0x298) + 8) = handle;
        stored_count = *(u16 *)(base + 6);
        *(volatile u16 *)(base + 6) = stored_count + 1;
        bytes[2] = (u8)(handle >> 8);
        bytes[3] = (u8)handle;
        SDP_AddAttribute(handle, 0, 1, 4, bytes);
        return *(u32 *)(base + ((*(u16 *)(base + 6) - 1) * 0x298) + 8);
    }
    return 0;
}

BOOLEAN SDP_DeleteRecord(UINT32 handle) {
    UINT16 xx, yy, zz;
    tSDP_RECORD_VIEW *record = (tSDP_RECORD_VIEW *)(lbl_803C4C40 + 0x1224);

    if (handle == 0 || *(UINT16 *)(lbl_803C4C40 + 0x1222) == 0) {
        *(UINT16 *)(lbl_803C4C40 + 0x1222) = 0;
        *(UINT32 *)(lbl_803C4C40 + 0x121C) = 0;
        lbl_803C4C40[0x1220] = 0;
        return TRUE;
    }

    for (xx = 0; xx < *(UINT16 *)(lbl_803C4C40 + 0x1222); xx++, record++) {
        if (record->record_handle == handle) {
            for (yy = xx; yy < *(UINT16 *)(lbl_803C4C40 + 0x1222); yy++, record++) {
                *record = *(record + 1);
                for (zz = 0; zz < record->num_attributes; zz++) {
                    record->attribute[zz].value_ptr -= sizeof(tSDP_RECORD_VIEW);
                }
            }

            *(UINT16 *)(lbl_803C4C40 + 0x1222) -= 1;
            if (*(UINT32 *)(lbl_803C4C40 + 0x121C) == handle) {
                *(UINT32 *)(lbl_803C4C40 + 0x121C) = 0;
                lbl_803C4C40[0x1220] = 0;
            }
            return TRUE;
        }
    }
    return FALSE;
}

extern char lbl_80319F90[];
BOOLEAN SDP_AddAttribute(UINT32 handle, UINT16 attr_id, UINT8 attr_type,
                          UINT32 attr_len, UINT8 *p_val) {
    UINT16 attr_index;
    tSDP_RECORD *p_rec;
    tSDP_ATTRIBUTE *p_attr;
    UINT16 record_index;
    UINT16 num_attr;
    UINT16 move_index;

    p_rec = (tSDP_RECORD *)(lbl_803C4C40 + 0x1224);
    for (record_index = 0; record_index < *(UINT16 *)(lbl_803C4C40 + 0x1222);
         record_index++, p_rec = (tSDP_RECORD *)((UINT8 *)p_rec + 0x298)) {
        if (p_rec->record_handle != handle) {
            continue;
        }

        p_attr = p_rec->attribute;
        for (attr_index = 0; attr_index < p_rec->num_attributes;
             attr_index++, p_attr++) {
            if (p_attr->id == attr_id) {
                SDP_DeleteAttribute(handle, attr_id);
                break;
            } else if (p_attr->id > attr_id) {
                break;
            }
        }

        num_attr = p_rec->num_attributes;
        if (num_attr == 0x19) {
            return FALSE;
        }

        if (attr_index == num_attr) {
            p_attr = &p_rec->attribute[num_attr];
        } else {
            for (move_index = num_attr; move_index > attr_index; move_index--) {
                p_rec->attribute[move_index] = p_rec->attribute[move_index - 1];
            }
        }

        p_rec->num_attributes++;
        p_attr->id = attr_id;
        p_attr->len = attr_len;
        p_attr->type = attr_type;

        if (p_rec->free_pad_ptr + attr_len >= 0x15E) {
            if (lbl_803C4C40[0x4630] >= 2) {
                ((void (*)(u32, void *, u32, u32))fn_8007096C)(
                    0xA0001, lbl_80319F90, attr_len,
                    0x15E - p_rec->free_pad_ptr);
            }
            attr_len = 0x15E - p_rec->free_pad_ptr;
            p_val[attr_len] = 0;
            p_val[0x15F - p_rec->free_pad_ptr] = 0;
        }

        if (attr_len != 0 && p_val != NULL) {
            memcpy((UINT8 *)p_rec + p_rec->free_pad_ptr + 0x138,
                   p_val, attr_len);
            p_attr->value_ptr = (UINT8 *)p_rec + p_rec->free_pad_ptr + 0x138;
            p_rec->free_pad_ptr += attr_len;
        }

        if (handle == *(UINT32 *)(lbl_803C4C40 + 0x121C) &&
            attr_id == 0x8001) {
            lbl_803C4C40[0x1220] = 1;
        }
        return TRUE;
    }
    return FALSE;
}

extern char lbl_80319FCC[];
BOOLEAN SDP_AddUuidSequence(UINT32 handle, UINT16 attr_id, UINT16 num_uuids, UINT16 *p_uuids) {
    UINT16 xx;
    UINT8 buff[0xA0];
    UINT8 *p = buff;
    INT32 max_len = 0x4D;

    for (xx = 0; xx < num_uuids; xx++, p_uuids++) {
        p[0] = 0x19;
        p[1] = *p_uuids >> 8;
        p[2] = *p_uuids;
        p += 3;

        if ((p - buff) > max_len) {
            if (lbl_803C4C40[0x4630] >= 2) {
                fn_8007096C(0xA0001, lbl_80319FCC, xx, num_uuids);
            }
            break;
        }
    }
    return SDP_AddAttribute(handle, attr_id, 6, (UINT32)(p - buff), buff);
}

u8 *sdpu_build_uuid_seq(u8 *out, u32 count, u8 *uuid) {
    u8 *start = out + 1;
    u8 *p;
    u32 i;
    s32 j;
    u16 len;

    *out = 0x35;
    p = start;
    p++;
    for (i = 0; i < count; i++) {
        len = *(u16 *)uuid;
        if (len == 2) {
            *p++ = 0x19;
            *p++ = (u8)(*(u16 *)(uuid + 4) >> 8);
            *p++ = (u8)*(u16 *)(uuid + 4);
        } else if (len == 4) {
            *p++ = 0x1A;
            *p++ = (u8)(*(u32 *)(uuid + 4) >> 24);
            *p++ = (u8)(*(u32 *)(uuid + 4) >> 16);
            *p++ = (u8)(*(u32 *)(uuid + 4) >> 8);
            *p++ = (u8)*(u32 *)(uuid + 4);
        } else {
            *p++ = 0x1C;
            j = 0;
            while (j < (s32)len) {
                *p++ = uuid[j + 4];
                j++;
                len = *(u16 *)uuid;
            }
        }
        uuid += 0x14;
    }
    *start = (u8)(p - start - 1);
    return start + (p - start);
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

extern char lbl_8031A050[];
void process_service_search_rsp(void *p_ccb, UINT8 *p_reply, UINT16 len) {
    UINT8 *p = p_reply + 8;
    UINT16 orig = *(UINT16 *)((UINT8 *)p_ccb + 0x46C);
    UINT16 cur = (p_reply[6] << 8) + p_reply[7];
    UINT16 total;
    UINT8 cont_len;
    UINT16 i;
    *(UINT16 *)((UINT8 *)p_ccb + 0x46C) = orig + cur;
    if (*(UINT16 *)((UINT8 *)p_ccb + 0x46C) == 0) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_8007093C(0xA0001, lbl_8031A050);
        sdp_disconnect(p_ccb, 0xFFF0);
        return;
    }
    total = *(UINT16 *)((UINT8 *)p_ccb + 0x46C);
    if (total > *(UINT16 *)(lbl_803C4C40 + 0x462E))
        *(UINT16 *)((UINT8 *)p_ccb + 0x46C) = *(UINT16 *)(lbl_803C4C40 + 0x462E);
    for (i = orig; i < *(UINT16 *)((UINT8 *)p_ccb + 0x46C); i++) {
        *(UINT32 *)((UINT8 *)p_ccb + 0x418 + i * 4) =
            ((UINT32)p[0] << 24) | ((UINT32)p[1] << 16) | ((UINT32)p[2] << 8) | p[3];
        p += 4;
    }
    cont_len = *p;
    if (cont_len != 0) {
        if (cont_len > 0x10) {
            sdp_disconnect(p_ccb, 5);
            return;
        }
        sdp_snd_service_search_req(p_ccb, cont_len, p + 1);
    } else {
        *(UINT8 *)((UINT8 *)p_ccb + 0x474) = 2;
        process_service_attr_rsp(p_ccb, 0, 0);
    }
}

static void process_service_attr_rsp(tCONN_CB *p_ccb, UINT8 *p_reply, UINT16 len)
{
    UINT8 *p_start, *p_param_len;
    UINT16 param_len, list_byte_count;
    BOOLEAN cont_request_needed = FALSE;

    #pragma unused(len)

    if (p_reply) {
        p_reply += 4;
        list_byte_count = (p_reply[0] << 8) + p_reply[1];
        p_reply += 2;

        if (p_ccb->list_len + list_byte_count > 0x3E8) {
            sdp_disconnect(p_ccb, 4);
            return;
        }

        memcpy((UINT8 *)p_ccb + p_ccb->list_len + 0x26, p_reply, list_byte_count);
        p_ccb->list_len += list_byte_count;
        p_reply += list_byte_count;

        if (*p_reply) {
            if (*p_reply > 0x10) {
                sdp_disconnect(p_ccb, 5);
                return;
            }
            cont_request_needed = TRUE;
        } else {
            if (!save_attr_seq(p_ccb, (UINT8 *)p_ccb + 0x26,
                               (UINT8 *)p_ccb + p_ccb->list_len + 0x26)) {
                sdp_disconnect(p_ccb, 0xFFF4);
                return;
            }
            p_ccb->list_len = 0;
            *(UINT16 *)((UINT8 *)p_ccb + 0x46E) += 1;
        }
    }

    if (*(UINT16 *)((UINT8 *)p_ccb + 0x46E) < *(UINT16 *)((UINT8 *)p_ccb + 0x46C)) {
        BT_HDR *p_msg = (BT_HDR *)GKI_getpoolbuf(2);
        UINT8 *p;

        if (!p_msg) {
            sdp_disconnect(p_ccb, 6);
            return;
        }

        p_msg->offset = 9;
        p = p_start = (UINT8 *)p_msg + 0x11;

        *p++ = 4;
        *p++ = *(UINT16 *)((UINT8 *)p_ccb + 0x470) >> 8;
        *p++ = *(UINT16 *)((UINT8 *)p_ccb + 0x470);
        *(UINT16 *)((UINT8 *)p_ccb + 0x470) += 1;

        p_param_len = p;
        p += 2;

        *p++ = ((tSDP_CCB_HANDLE_VIEW *)p_ccb)->handles[*(UINT16 *)((UINT8 *)p_ccb + 0x46E)] >> 24;
        *p++ = ((tSDP_CCB_HANDLE_VIEW *)p_ccb)->handles[*(UINT16 *)((UINT8 *)p_ccb + 0x46E)] >> 16;
        *p++ = ((tSDP_CCB_HANDLE_VIEW *)p_ccb)->handles[*(UINT16 *)((UINT8 *)p_ccb + 0x46E)] >> 8;
        *p++ = ((tSDP_CCB_HANDLE_VIEW *)p_ccb)->handles[*(UINT16 *)((UINT8 *)p_ccb + 0x46E)];

        *p++ = *(UINT16 *)(lbl_803C4C40 + 0x462C) >> 8;
        *p++ = *(UINT16 *)(lbl_803C4C40 + 0x462C);

        if (*(UINT16 *)(*(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x4C))
            p = sdpu_build_attrib_seq(
                p,
                (UINT16 *)(*(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x4E),
                *(UINT16 *)(*(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x4C));
        else
            p = sdpu_build_attrib_seq(p, NULL, 0);

        if (cont_request_needed) {
            memcpy(p, p_reply, *p_reply + 1);
            p += *p_reply + 1;
        } else {
            *p++ = 0;
        }

        param_len = p - p_param_len - 2;
        p_param_len[0] = param_len >> 8;
        p_param_len[1] = param_len;
        p_msg->len = p - p_start;

        L2CA_DataWrite(p_ccb->connection_id, p_msg);
        btu_start_timer(&p_ccb->timer_entry, 5, 0x1E);
    } else {
        sdp_disconnect(p_ccb, 0);
        return;
    }
}

extern char lbl_8031A078[];
static void process_service_search_attr_rsp(tCONN_CB *p_ccb, UINT8 *p_reply, UINT16 len)
{
    UINT8 *p, *p_start, *p_end, *p_param_len;
    UINT8 type;
    UINT32 seq_len;
    UINT16 param_len, lists_byte_count = 0;
    register UINT8 *list_end;
    BOOLEAN cont_request_needed = FALSE;
    #pragma unused(len)
    if (p_reply) {
        p_reply += 4;
        lists_byte_count = (p_reply[0] << 8) + p_reply[1];
        p_reply += 2;
        if (*(UINT16 *)((UINT8 *)p_ccb + 0x24) + lists_byte_count > 0x3E8) {
            sdp_disconnect(p_ccb, 4);
            return;
        }
        memcpy((UINT8 *)p_ccb + *(UINT16 *)((UINT8 *)p_ccb + 0x24) + 0x26,
               p_reply, lists_byte_count);
        *(UINT16 *)((UINT8 *)p_ccb + 0x24) =
            *(UINT16 *)((UINT8 *)p_ccb + 0x24) + lists_byte_count;
        p_reply += lists_byte_count;
        if (*p_reply) {
            if (*p_reply > 0x10) {
                sdp_disconnect(p_ccb, 5);
                return;
            }
            cont_request_needed = TRUE;
        }
    }
    if (cont_request_needed || !p_reply) {
        BT_HDR *p_msg = (BT_HDR *)GKI_getpoolbuf(2);
        UINT8 *p;
        if (!p_msg) {
            sdp_disconnect(p_ccb, 6);
            return;
        }
        p_msg->offset = 9;
        p = p_start = (UINT8 *)p_msg + 0x11;
        *p++ = 6;
        *p++ = *(UINT16 *)((UINT8 *)p_ccb + 0x470) >> 8;
        *p++ = *(UINT16 *)((UINT8 *)p_ccb + 0x470);
        *(UINT16 *)((UINT8 *)p_ccb + 0x470) += 1;
        p_param_len = p;
        p += 2;
        p = sdpu_build_uuid_seq(
            p,
            *(UINT16 *)(*(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x0C),
            *(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x10);
        *p++ = *(UINT16 *)(lbl_803C4C40 + 0x462C) >> 8;
        *p++ = *(UINT16 *)(lbl_803C4C40 + 0x462C);
        if (*(UINT16 *)(*(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x4C))
            p = sdpu_build_attrib_seq(
                p,
                (UINT16 *)(*(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x4E),
                *(UINT16 *)(*(UINT8 **)((UINT8 *)p_ccb + 0x410) + 0x4C));
        else
            p = sdpu_build_attrib_seq(p, NULL, 0);
        if (p_reply) {
            memcpy(p, p_reply, *p_reply + 1);
            p += *p_reply + 1;
        } else {
            *p++ = 0;
        }
        param_len = p - p_param_len - 2;
        p_param_len[0] = param_len >> 8;
        p_param_len[1] = param_len;
        p_msg->len = p - p_start;
        L2CA_DataWrite(*(UINT16 *)((UINT8 *)p_ccb + 0x22), p_msg);
        btu_start_timer(&p_ccb->timer_entry, 5, 0x1E);
        return;
    }
    p = (UINT8 *)p_ccb + 0x26;
    type = *p++;
    if ((type >> 3) != 6) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_80070954(0xA0001, lbl_8031A078, type);
        return;
    }
    p = sdpu_get_len_from_type(p, type, &seq_len);
    list_end = (UINT8 *)(u32)*(UINT16 *)((UINT8 *)p_ccb + 0x24);
    list_end = (UINT8 *)p_ccb + (u32)list_end;
    p_end = list_end + 0x26;
    if (p + seq_len != p_end) {
        sdp_disconnect(p_ccb, 5);
        return;
    }
    while (p < p_end) {
        p = (UINT8 *)save_attr_seq(
            p_ccb, p,
            (UINT8 *)p_ccb + *(UINT16 *)((UINT8 *)p_ccb + 0x24) + 0x26);
        if (!p) {
            sdp_disconnect(p_ccb, 0xFFF4);
            return;
        }
    }
    sdp_disconnect(p_ccb, 0);
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

void sdp_init(void) {
    u8 *cb;
    char *log=lbl_8031A188;
    u32 zero=0;
    memset(lbl_803C4C40,0,0x4634);
    cb=lbl_803C4C40;
    *(u16*)(cb+4)=0x100; cb[2]=1; cb[0x20]=1;
    *(u16*)(cb+0x22)=0xFFFF;
    *(u16*)(cb+0x462C)=0xF0; *(u16*)(cb+0x462E)=0x15;
    if(!BTM_SetSecurityLevel(0,log,0,0,1,0,0)) {
        if(cb[0x4630]>=1) fn_8007093C(0xA0000,log+0x14);
        return;
    }
    if(!BTM_SetSecurityLevel(1,log,0,0,1,0,0)) {
        if(cb[0x4630]>=1) fn_8007093C(0xA0000,log+0x38);
        return;
    }
    cb[0x4630]=0;
    *(u32*)(cb+0x4604)=(u32)sdp_connect_ind;
    *(u32*)(cb+0x4608)=(u32)sdp_connect_cfm;
    *(u32*)(cb+0x460C)=zero;
    *(u32*)(cb+0x4610)=(u32)sdp_config_ind;
    *(u32*)(cb+0x4614)=(u32)sdp_config_cfm;
    *(u32*)(cb+0x4618)=(u32)sdp_disconnect_ind;
    *(u32*)(cb+0x461C)=(u32)sdp_disconnect_cfm;
    *(u32*)(cb+0x4620)=zero;
    *(u32*)(cb+0x4624)=(u32)sdp_data_ind;
    *(u32*)(cb+0x4628)=zero;
    if(!L2CA_Register(1,(tL2CAP_APPL_INFO*)(cb+0x4604)) && cb[0x4630]>=1)
        fn_8007093C(0xA0000,log+0x60);
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

/* Match note: preserve status, log base, and handle locals to reproduce target registers. */
void sdp_connect_cfm(u16 cid, u16 result) {
    extern tCONN_CB *l2cu_find_lcb_by_handle_80099E54(UINT16);
    extern char lbl_8031A188[];
    u16 status = result;
    char *log = lbl_8031A188;
    u16 handle = cid;
    tCONN_CB *p_ccb;
    u16 (*p_callback)(u16);

    p_ccb = l2cu_find_lcb_by_handle_80099E54(handle);
    if (p_ccb == NULL) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_80070954(0xA0001, log + 0xB0, handle);
    } else if (status == 0 && p_ccb->con_state == 1) {
        p_ccb->con_state = 2;
        L2CA_ConfigReq(handle, (tL2CAP_CFG_INFO *)lbl_803C4C40);
        if (lbl_803C4C40[0x4630] >= 4)
            fn_80070954(0xA0003, log + 0xDC, p_ccb->connection_id);
    } else {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_8007096C(0xA0001, log + 0x108, status, p_ccb->connection_id);
        p_callback = *(u16 (**)(u16))((u8 *)p_ccb + 0x414);
        if (p_callback != NULL) {
            if (status == 14 || status == 5 || status == 24 || status == 41 || status == 6)
                p_callback(0xFFF6);
            else if (status == 15)
                p_callback(0xFFF7);
            else
                p_callback(0xFFF1);
        }
        fn_80099F58(p_ccb);
    }
}

extern tCONN_CB *l2cu_find_lcb_by_handle_80099E54(UINT16);
void sdp_config_ind(u16 cid, void *p_cfg) {
    tCONN_CB *lcb = l2cu_find_lcb_by_handle_80099E54(cid);
    u16 value;
    volatile u16 *out;
    if (lcb == NULL) {
        if (lbl_803C4C40[0x4630] >= 2) fn_80070954(0xA0001, lbl_8031A2C0, cid);
        return;
    }
    out = (volatile u16 *)((u8 *)lcb + 0x20);
    if (((u8 *)p_cfg)[2] == 0) {
        *out = 0x100;
    } else {
        value = *(u16 *)((u8 *)p_cfg + 4);
        if (value > 0x100) value = 0x100;
        *out = value;
    }
    ((u8 *)p_cfg)[0x20] = 0;
    ((u8 *)p_cfg)[2] = 0;
    *(u16 *)p_cfg = 0;
    L2CA_ConfigRsp(cid, p_cfg);
    if (lbl_803C4C40[0x4630] >= 4) fn_80070954(0xA0003, lbl_8031A2EC, cid);
    ((u8 *)lcb)[1] |= 2;
    if (((u8 *)lcb)[1] & 4) {
        ((u8 *)lcb)[0] = 3;
        if (((u8 *)lcb)[1] & 1) fn_8009757C((u8 *)lcb);
        else btu_start_timer((u8 *)lcb + 8, 5, 0x1E);
    }
}

void sdp_disconnect_ind(u16 handle, u8 reason) {
    extern char lbl_8031A360[];
    extern char lbl_8031A38C[];
    u8 *ccb;
    void (*callback)(u16, s32, u8);
    u8 state;
    s32 result;
    s32 stateDelta;
    s32 reverseDelta;
    s32 equalityMask;

    ccb = (u8 *)l2cu_find_lcb_by_handle_80099E54(handle);
    if (ccb == 0) {
        if (lbl_803C4C40[0x4630] >= 2) {
            fn_80070954(0xA0001, lbl_8031A360, handle);
        }
        return;
    }

    if (reason != 0) {
        L2CA_DisconnectRsp(handle);
    }

    if (lbl_803C4C40[0x4630] >= 4) {
        fn_80070954(0xA0003, lbl_8031A38C, handle);
    }

    callback = *(void (**)(u16, s32, u8))(ccb + 0x414);
    if (callback != 0) {
        state = ccb[0];
        result = 0x10000;
        result -= 15;
        stateDelta = state - 3;
        reverseDelta = 3 - state;
        equalityMask = (s32)~(stateDelta | reverseDelta) >> 31;
        result = result & ~equalityMask;
        callback((u16)result, stateDelta, state);
    }

    fn_80099F58(ccb);
}

extern char lbl_8031A3E8[];
extern void (sdp_server_handle_client_req)(tCONN_CB *, BT_HDR *);
void sdp_data_ind(u16 l2cap_cid, void *p_msg) {
    tCONN_CB *p_ccb;
    u8 con_state;

    p_ccb = l2cu_find_lcb_by_handle_80099E54(l2cap_cid);
    if (p_ccb != 0) {
        con_state = p_ccb->con_state;
        if (con_state == SDP_STATE_CONNECTED) {
            if (p_ccb->con_flags & SDP_FLAGS_IS_ORIG) {
                sdp_disc_server_rsp(p_ccb, p_msg);
            } else {
                (sdp_server_handle_client_req)(p_ccb, p_msg);
            }
        } else if (lbl_803C4C40[0x4630] >= 2) {
            fn_8007096C(0xA0001, lbl_8031A3B0, con_state, l2cap_cid);
        }
    } else if (lbl_803C4C40[0x4630] >= 2) {
        fn_80070954(0xA0001, lbl_8031A3E8, l2cap_cid);
    }
    GKI_freebuf(p_msg);
}

void sdp_disconnect_cfm(u16 cid, u16 result) {
    extern char lbl_8031A460[];
    extern char lbl_8031A490[];
    u16 handle = cid;
    tCONN_CB *p_ccb;
    u16 (*p_callback)(u16);

    p_ccb = l2cu_find_lcb_by_handle_80099E54(handle);
    if (p_ccb == NULL) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_80070954(0xA0001, lbl_8031A460, handle);
        return;
    }

    if (lbl_803C4C40[0x4630] >= 4)
        fn_80070954(0xA0003, lbl_8031A490, handle);

    p_callback = *(u16 (**)(u16))((u8 *)p_ccb + 0x414);
    if (p_callback != NULL)
        p_callback(*(u16 *)((u8 *)p_ccb + 0x472));
    fn_80099F58(p_ccb);
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

void process_service_search(tCONN_CB *p_ccb, UINT16 trans_num, UINT16 param_len, UINT8 *p) {
    tSDP_UUID_SEQ seq;
    tSDP_RECORD *p_rec;
    u32 handles[20];
    UINT16 total_handles;
    UINT16 max_handles;
    UINT16 num_uids;
    UINT16 start_offset;
    UINT16 count;
    UINT8 sp17c;
    u8 *p_param_len;
    u8 *p_end;
    u8 *p_cont;
    u32 param_len2;
    BT_HDR *buf;
    u8 *uid;
    s32 total;

    sp17c = 0;
    p_rec = NULL;
    uid = sdpu_extract_uid_seq(p, param_len, &seq);
    if ((uid == NULL) || (seq.num_uids == 0)) {
        sdpu_build_n_send_error(p_ccb, trans_num, 3, 0);
        return;
    }
    num_uids = ((UINT16) uid[0] << 8) + uid[1];
    if (num_uids > 0x14) {
        num_uids = 0x14;
    }
    total_handles = 0;
    while (total_handles < num_uids) {
        p_rec = sdp_db_service_search(p_rec, &seq);
        if (p_rec == 0) {
            break;
        }
        handles[total_handles] = p_rec->record_handle;
        total_handles++;
    }
    if (uid[2] != 0) {
        if (uid[2] != 2) {
            sdpu_build_n_send_error(p_ccb, trans_num, 5, 0);
            return;
        }
        p_cont = uid + 3;
        start_offset = ((UINT16) p_cont[0] << 8) + p_cont[1];
        if (start_offset != ((tSDP_CCB_CONT_VIEW *)p_ccb)->cont_offset) {
            sdpu_build_n_send_error(p_ccb, trans_num, 5, 0);
            return;
        }
        count = total_handles - start_offset;
    } else {
        count = total_handles;
        start_offset = 0;
    }
    max_handles = (UINT16)(((s32)((u16)p_ccb->rem_mtu_size - 0xc) + 3) >> 2);
    if (count <= max_handles) {
        max_handles = count;
    } else {
        sp17c = 1;
        ((tSDP_CCB_CONT_VIEW *)p_ccb)->cont_offset += max_handles;
    }
    buf = (BT_HDR *)GKI_getpoolbuf(2);
    if (buf == NULL) {
        if (lbl_803C4C40[0x4630] >= 1) {
            fn_8007093C(0xA0000, lbl_8031A50C);
        }
        return;
    }
    buf->offset = 9;
    p_end = (UINT8 *)buf + 0x11;
    p_param_len = p_end + 3;
    p_end[0] = 3;
    total = start_offset + max_handles;
    p_end[1] = (UINT8)(trans_num >> 8);
    p_end[2] = (UINT8)trans_num;
    p_param_len[2] = (UINT8)(total_handles >> 8);
    p_param_len[3] = (UINT8)total_handles;
    p_param_len[4] = (UINT8)(max_handles >> 8);
    p_param_len[5] = (UINT8)max_handles;
    p_end = p_param_len + 6;
    if (start_offset < total) {
        if ((total - start_offset) > 8) {
            while (start_offset < total - 8) {
                p_end[0] = (UINT8)(handles[start_offset] >> 24);
                p_end[1] = (UINT8)(handles[start_offset] >> 16);
                p_end[2] = (UINT8)(handles[start_offset] >> 8);
                p_end[3] = (UINT8)handles[start_offset];
                p_end[4] = (UINT8)(handles[start_offset + 1] >> 24);
                p_end[5] = (UINT8)(handles[start_offset + 1] >> 16);
                p_end[6] = (UINT8)(handles[start_offset + 1] >> 8);
                p_end[7] = (UINT8)handles[start_offset + 1];
                p_end[8] = (UINT8)(handles[start_offset + 2] >> 24);
                p_end[9] = (UINT8)(handles[start_offset + 2] >> 16);
                p_end[10] = (UINT8)(handles[start_offset + 2] >> 8);
                p_end[11] = (UINT8)handles[start_offset + 2];
                p_end[12] = (UINT8)(handles[start_offset + 3] >> 24);
                p_end[13] = (UINT8)(handles[start_offset + 3] >> 16);
                p_end[14] = (UINT8)(handles[start_offset + 3] >> 8);
                p_end[15] = (UINT8)handles[start_offset + 3];
                p_end[16] = (UINT8)(handles[start_offset + 4] >> 24);
                p_end[17] = (UINT8)(handles[start_offset + 4] >> 16);
                p_end[18] = (UINT8)(handles[start_offset + 4] >> 8);
                p_end[19] = (UINT8)handles[start_offset + 4];
                p_end[20] = (UINT8)(handles[start_offset + 5] >> 24);
                p_end[21] = (UINT8)(handles[start_offset + 5] >> 16);
                p_end[22] = (UINT8)(handles[start_offset + 5] >> 8);
                p_end[23] = (UINT8)handles[start_offset + 5];
                p_end[24] = (UINT8)(handles[start_offset + 6] >> 24);
                p_end[25] = (UINT8)(handles[start_offset + 6] >> 16);
                p_end[26] = (UINT8)(handles[start_offset + 6] >> 8);
                p_end[27] = (UINT8)handles[start_offset + 6];
                p_end[28] = (UINT8)(handles[start_offset + 7] >> 24);
                p_end[29] = (UINT8)(handles[start_offset + 7] >> 16);
                p_end[30] = (UINT8)(handles[start_offset + 7] >> 8);
                p_end[31] = (UINT8)handles[start_offset + 7];
                start_offset += 8;
                p_end += 0x20;
            }
        }
        while (start_offset < total) {
            u32 h = handles[start_offset];
            p_end[0] = (UINT8)(h >> 24);
            p_end[1] = (UINT8)(h >> 16);
            p_end[2] = (UINT8)(h >> 8);
            p_end[3] = (UINT8)h;
            start_offset++;
            p_end += 4;
        }
    }
    if (sp17c != 0) {
        p_end[0] = 2;
        p_end[1] = (UINT8)(((tSDP_CCB_CONT_VIEW *)p_ccb)->cont_offset >> 8);
        p_end[2] = (UINT8)((tSDP_CCB_CONT_VIEW *)p_ccb)->cont_offset;
        p_end += 3;
    } else {
        p_end[0] = 0;
        p_end += 1;
    }
    param_len2 = (u32)p_end - (u32)p_param_len - 2;
    p_param_len[0] = (UINT8)(param_len2 >> 8);
    p_param_len[1] = (UINT8)param_len2;
    buf->len = (UINT16)((u32)p_end - ((u32)buf + 0x11));
    L2CA_DataWrite(p_ccb->connection_id, buf);
}

static void process_service_attr_req(tCONN_CB *arg0, UINT16 arg1, UINT16 arg2, UINT8 *arg3, UINT8 *arg4) {
    tSDP_ATTR_SEQ attr_seq;
    register UINT32 record_handle;
    register UINT16 max_list_len;
    register UINT16 i;
    UINT16 list_len;
    UINT16 send_len;
    UINT16 cont_offset;
    register UINT8 *p;
    UINT8 *out;
    register UINT8 *list_base;
    UINT8 *param_len_ptr;
    register tSDP_RECORD *record;
    register tSDP_ATTRIBUTE *attr;
    BT_HDR *buf;

    p = arg3;
    BE_STREAM_TO_UINT32(record_handle, p);
    if (p > arg4) {
        sdpu_build_n_send_error(arg0, arg1, 2, NULL);
        return;
    }

    max_list_len = ((UINT16)p[0] << 8) + p[1];
    if (max_list_len > *(UINT16 *)((UINT8 *)arg0 + 0x20) - 10) {
        max_list_len = *(UINT16 *)((UINT8 *)arg0 + 0x20) - 10;
    }

    p = sdpu_extract_attr_seq(p + 2, arg2, &attr_seq);
    if (p == NULL || attr_seq.num_attr == 0 || p > arg4) {
        sdpu_build_n_send_error(arg0, arg1, 3, NULL);
        return;
    }

    record = sdp_db_find_record(record_handle);
    if (record == NULL) {
        sdpu_build_n_send_error(arg0, arg1, 2, NULL);
        return;
    }

    if (*p != 0) {
        if (*p != 2) {
            sdpu_build_n_send_error(arg0, arg1, 5, NULL);
            return;
        }
        if ((((UINT16)p[1] << 8) + p[2]) != *(UINT16 *)((UINT8 *)arg0 + 0x476)) {
            sdpu_build_n_send_error(arg0, arg1, 5, NULL);
            return;
        }
        goto build_response;
    }

    list_base = (UINT8 *)arg0 + 0x29;
    *(UINT16 *)((UINT8 *)arg0 + 0x476) = 0;
    for (i = 0; i < attr_seq.num_attr; i++) {
        UINT8 *entry = (UINT8 *)&attr_seq + ((UINT32)i << 2);
        UINT16 start = *(UINT16 *)(entry + 2);
        UINT16 end = *(UINT16 *)(entry + 4);
        attr = fn_80096904(record, start, end);
        if (attr != NULL) {
            if ((UINT32)attr->len > (UINT32)((UINT16)(0x3E8 - (UINT16)(list_base - ((UINT8 *)arg0 + 0x26))) - 6)) {
                break;
            }
            list_base = sdpu_build_attrib_entry(list_base, attr);
            if (*(UINT16 *)(entry + 2) != *(UINT16 *)(entry + 4)) {
                *(UINT16 *)(entry + 2) = attr->id + 1;
                i--;
            }
        }
    }

    list_len = (UINT16)(list_base - ((UINT8 *)arg0 + 0x26));
    *(UINT16 *)((UINT8 *)arg0 + 0x24) = list_len;
    if (list_len > 0xFF) {
        UINT16 adjusted = list_len - 3;
        *((UINT8 *)arg0 + 0x26) = 0x36;
        *((UINT8 *)arg0 + 0x27) = adjusted >> 8;
        *((UINT8 *)arg0 + 0x28) = adjusted;
    } else {
        *(UINT16 *)((UINT8 *)arg0 + 0x476) = 1;
        *((UINT8 *)arg0 + 0x27) = 0x35;
        *((UINT8 *)arg0 + 0x28) = list_len - 3;
        *(UINT16 *)((UINT8 *)arg0 + 0x24) = list_len - 1;
    }

build_response:
    buf = (BT_HDR *)GKI_getpoolbuf(2);
    if (buf == NULL) {
        if (lbl_803C4C40[0x4630] >= 1) {
            fn_8007093C(0xA0000, lbl_8031A50C);
        }
        return;
    }

    buf->offset = 9;
    out = (UINT8 *)buf + 0x11;
    out[0] = 5;
    out[1] = arg1 >> 8;
    out[2] = arg1;
    param_len_ptr = out + 3;
    p = param_len_ptr;
    list_len = *(UINT16 *)((UINT8 *)arg0 + 0x24);
    if (list_len <= max_list_len) {
        max_list_len = list_len;
    }
    p[2] = max_list_len >> 8;
    p[3] = max_list_len;
    p += 4;
    memcpy(p, (UINT8 *)arg0 + *(UINT16 *)((UINT8 *)arg0 + 0x476) + 0x26, max_list_len);
    p += max_list_len;
    list_len -= max_list_len;
    *(UINT16 *)((UINT8 *)arg0 + 0x24) = list_len;
    cont_offset = *(UINT16 *)((UINT8 *)arg0 + 0x476) + max_list_len;
    *(UINT16 *)((UINT8 *)arg0 + 0x476) = cont_offset;
    if (list_len != 0) {
        p[0] = 2;
        p[1] = cont_offset >> 8;
        p[2] = cont_offset;
        p += 3;
    } else {
        p[0] = 0;
        p += 1;
    }
    send_len = (UINT16)(p - param_len_ptr - 2);
    param_len_ptr[0] = send_len >> 8;
    param_len_ptr[1] = send_len;
    *(UINT16 *)((UINT8 *)buf + 2) = p - out;
    L2CA_DataWrite(*(UINT16 *)((UINT8 *)arg0 + 0x22), buf);
}

static void process_service_search_attr_req(tCONN_CB *p_ccb, UINT16 trans_num,
                                               UINT16 param_len, UINT8 *p_req,
                                               UINT8 *p_req_end) {
    UINT16 max_list_len;
    UINT16 len_to_send, cont_offset, req_offset;
    UINT16 rsp_param_len, xx;
    tSDP_UUID_SEQ uid_seq;
    tSDP_ATTR_SEQ attr_seq, attr_seq_sav;
    UINT8 *p_rsp;
    UINT8 *p_rsp_start;
    UINT8 *p_rsp_param_len;
    UINT8 *p_seq_start;
    UINT16 seq_len;
    tSDP_RECORD *p_rec;
    tSDP_ATTRIBUTE *p_attr;
    BT_HDR *p_buf;
    BOOLEAN maxxed_out = FALSE;
    (void)p_req_end;

    p_req = sdpu_extract_uid_seq(p_req, param_len, &uid_seq);
    if (p_req == NULL || uid_seq.num_uids == 0) {
        sdpu_build_n_send_error(p_ccb, trans_num, 3, NULL);
        return;
    }
    max_list_len = ((UINT16)p_req[0] << 8) + p_req[1];
    if (max_list_len > p_ccb->rem_mtu_size - 0xA)
        max_list_len = p_ccb->rem_mtu_size - 0xA;
    p_req = sdpu_extract_attr_seq(p_req + 2, param_len, &attr_seq);
    if (p_req == NULL || attr_seq.num_attr == 0) {
        sdpu_build_n_send_error(p_ccb, trans_num, 3, NULL);
        return;
    }
    attr_seq_sav = attr_seq;
    if (*p_req != 0) {
        if (*p_req != 2) {
            sdpu_build_n_send_error(p_ccb, trans_num, 5, NULL);
            return;
        }
        req_offset = (UINT16)(((UINT16)p_req[1] << 8) + p_req[2]);
        if (req_offset != *(UINT16 *)((UINT8 *)p_ccb + 0x476)) {
            sdpu_build_n_send_error(p_ccb, trans_num, 5, NULL);
            return;
        }
    } else {
        p_rsp = (UINT8 *)p_ccb + 0x29;
        *(UINT16 *)((UINT8 *)p_ccb + 0x476) = 0;
        p_rec = sdp_db_service_search(NULL, &uid_seq);
        while (p_rec != NULL) {
            attr_seq = attr_seq_sav;
            p_seq_start = p_rsp;
            p_rsp += 3;
            for (xx = 0; xx < attr_seq.num_attr; xx++) {
                UINT8 *entry = (UINT8 *)&attr_seq + ((UINT32)xx << 2);
                UINT16 start = *(UINT16 *)(entry + 2);
                UINT16 end = *(UINT16 *)(entry + 4);
                p_attr = fn_80096904(p_rec, start, end);
                if (p_attr != NULL) {
                    if ((UINT32)p_attr->len >
                        (UINT32)((UINT16)(0x3E8 - (UINT16)(p_rsp - ((UINT8 *)p_ccb + 0x26))) - 6)) {
                        maxxed_out = TRUE;
                        break;
                    }
                    p_rsp = sdpu_build_attrib_entry(p_rsp, p_attr);
                    if (*(UINT16 *)(entry + 2) != *(UINT16 *)(entry + 4)) {
                        *(UINT16 *)(entry + 2) = p_attr->id + 1;
                        xx--;
                    }
                }
            }
            if (maxxed_out)
                break;
            seq_len = (UINT16)(p_rsp - p_seq_start) - 3;
            if (seq_len != 0) {
                p_seq_start[0] = 0x36;
                p_seq_start[1] = seq_len >> 8;
                p_seq_start[2] = (UINT8)seq_len;
            } else {
                p_rsp = p_seq_start;
            }
            p_rec = sdp_db_service_search(p_rec, &uid_seq);
        }
        len_to_send = (UINT16)(p_rsp - ((UINT8 *)p_ccb + 0x26));
        p_ccb->list_len = len_to_send;
        if (len_to_send > 0xFF) {
            UINT16 adjusted = len_to_send - 3;
            *((UINT8 *)p_ccb + 0x26) = 0x36;
            *((UINT8 *)p_ccb + 0x27) = adjusted >> 8;
            *((UINT8 *)p_ccb + 0x28) = adjusted;
        } else {
            *(UINT16 *)((UINT8 *)p_ccb + 0x476) = 1;
            *((UINT8 *)p_ccb + 0x27) = 0x35;
            *((UINT8 *)p_ccb + 0x28) = len_to_send - 3;
            p_ccb->list_len = len_to_send - 1;
        }
    }
    p_buf = (BT_HDR *)GKI_getpoolbuf(2);
    if (p_buf == NULL) {
        if (lbl_803C4C40[0x4630] >= 1)
            fn_8007093C(0xA0000, lbl_8031A50C);
        return;
    }
    p_buf->offset = 9;
    p_rsp = p_rsp_start = (UINT8 *)p_buf + 0x11;
    p_rsp[0] = 7;
    p_rsp[1] = trans_num >> 8;
    p_rsp[2] = trans_num;
    p_rsp_param_len = p_rsp + 3;
    len_to_send = p_ccb->list_len;
    if (len_to_send > max_list_len)
        len_to_send = max_list_len;
    p_rsp_param_len[2] = len_to_send >> 8;
    p_rsp_param_len[3] = len_to_send;
    p_rsp = p_rsp_param_len + 4;
    cont_offset = *(UINT16 *)((UINT8 *)p_ccb + 0x476);
    memcpy(p_rsp, (UINT8 *)p_ccb + cont_offset + 0x26, len_to_send);
    p_rsp += len_to_send;
    p_ccb->list_len -= len_to_send;
    cont_offset += len_to_send;
    *(UINT16 *)((UINT8 *)p_ccb + 0x476) = cont_offset;
    if (p_ccb->list_len != 0) {
        p_rsp[0] = 2;
        p_rsp[1] = cont_offset >> 8;
        p_rsp[2] = cont_offset;
        p_rsp += 3;
    } else {
        p_rsp[0] = 0;
        p_rsp++;
    }
    rsp_param_len = (UINT16)(p_rsp - p_rsp_param_len - 2);
    p_rsp_param_len[0] = rsp_param_len >> 8;
    p_rsp_param_len[1] = rsp_param_len;
    p_buf->len = p_rsp - p_rsp_start;
    L2CA_DataWrite(p_ccb->connection_id, p_buf);
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

UINT8 *sdpu_build_attrib_seq(UINT8 *out, UINT16 *attribs, UINT16 count) {
    UINT16 i;
    UINT16 length;

    if (attribs != NULL) {
        length = count * 3;
    } else {
        length = 5;
    }

    if (length > 0xFF) {
        out[0] = 0x36;
        out[1] = length >> 8;
        out[2] = length;
        out += 3;
    } else {
        out[0] = 0x35;
        out[1] = length;
        out += 2;
    }

    if (attribs == NULL) {
        out[0] = 0x0A;
        out[1] = 0;
        out[2] = 0;
        out[3] = 0xFF;
        out[4] = 0xFF;
        out += 5;
    } else {
        i = 0;
        if (count != 0) {
            while (count - i > 8) {
                out[0] = 9;
                out[1] = attribs[0] >> 8;
                out[2] = attribs[0];
                out[3] = 9;
                out[4] = attribs[1] >> 8;
                out[5] = attribs[1];
                out[6] = 9;
                out[7] = attribs[2] >> 8;
                out[8] = attribs[2];
                out[9] = 9;
                out[10] = attribs[3] >> 8;
                out[11] = attribs[3];
                out[12] = 9;
                out[13] = attribs[4] >> 8;
                out[14] = attribs[4];
                out[15] = 9;
                out[16] = attribs[5] >> 8;
                out[17] = attribs[5];
                out[18] = 9;
                out[19] = attribs[6] >> 8;
                out[20] = attribs[6];
                out[21] = 9;
                out[22] = attribs[7] >> 8;
                out[23] = attribs[7];
                attribs += 8;
                out += 24;
                i += 8;
            }
            while (i < count) {
                out[0] = 9;
                out[1] = attribs[0] >> 8;
                out[2] = attribs[0];
                attribs++;
                out += 3;
                i++;
            }
        }
    }
    return out;
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

extern char lbl_8031A56C[];
extern char lbl_8031A5A4[];
void sdpu_build_n_send_error(tCONN_CB *p_ccb, UINT16 trans_num, UINT16 error_code, char *p_error_text) {
    UINT8 *p_rsp, *p_rsp_start, *p_rsp_param_len;
    UINT16 rsp_param_len;
    BT_HDR *p_buf;
    if (lbl_803C4C40[0x4630] >= 2)
        fn_8007096C(0xA0001, lbl_8031A56C, 0, p_ccb->connection_id);
    p_buf = (BT_HDR *)GKI_getpoolbuf(SDP_POOL_ID);
    if (p_buf == NULL) {
        if (lbl_803C4C40[0x4630] >= 1)
            fn_8007093C(0xA0000, lbl_8031A5A4);
        return;
    }
    p_buf->offset = L2CAP_MIN_OFFSET;
    p_rsp = p_rsp_start = (UINT8 *)(p_buf + 1) + L2CAP_MIN_OFFSET;
    UINT8_TO_BE_STREAM(p_rsp, SDP_PDU_ERROR_RESPONSE);
    UINT16_TO_BE_STREAM(p_rsp, trans_num);
    p_rsp_param_len = p_rsp;
    p_rsp += 2;
    UINT16_TO_BE_STREAM(p_rsp, error_code);
    if (p_error_text)
        ARRAY_TO_BE_STREAM(p_rsp, p_error_text, (int)strlen(p_error_text));
    rsp_param_len = p_rsp - p_rsp_param_len - 2;
    UINT16_TO_BE_STREAM(p_rsp_param_len, rsp_param_len);
    p_buf->len = p_rsp - p_rsp_start;
    L2CA_DataWrite(p_ccb->connection_id, p_buf);
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

UINT8 *sdpu_extract_attr_seq(UINT8 *p, UINT16 param_len, tSDP_ATTR_SEQ *p_seq)
{
    UINT8 *end;
    UINT32 len, type, size;
    UINT16 i;
    p_seq->num_attr = 0;
    type = *p++;
    if ((type >> 3) != 6) return p;
    switch (type & 7) {
    case 5: len = *p++; break;
    case 6: len = (p[0] << 8) | p[1]; p += 2; break;
    case 7: len = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; p += 4; break;
    default: return p;
    }
    if (len > param_len) return p;
    end = p + len;
    while (p < end) {
        type = *p++;
        if ((type >> 3) != 1) return p;
        switch (type & 7) {
        case 1: size = 2; break;
        case 2: size = 4; break;
        case 5: size = *p++; break;
        case 6: size = (p[0] << 8) | p[1]; p += 2; break;
        case 7: size = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; p += 4; break;
        default: return NULL;
        }
        if (size == 2) {
            p_seq->attr_entry[p_seq->num_attr].start = (p[0] << 8) | p[1];
            p_seq->attr_entry[p_seq->num_attr].end = p_seq->attr_entry[p_seq->num_attr].start;
            p += 2;
        } else if (size == 4) {
            p_seq->attr_entry[p_seq->num_attr].start = (p[0] << 8) | p[1];
            p_seq->attr_entry[p_seq->num_attr].end = (p[2] << 8) | p[3];
            p += 4;
        } else return NULL;
        i = p_seq->num_attr + 1;
        p_seq->num_attr = i;
        if (i >= 16) return NULL;
    }
    return p;
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

BOOLEAN sdpu_is_base_uuid(UINT8 *uuid) {
    extern UINT8 lbl_802EED40[];
    u16 i;
    for (i = 4; i < 16; i++) {
        if (lbl_802EED40[i] != uuid[i]) return FALSE;
    }
    return TRUE;
}

BOOLEAN sdpu_compare_uuid_arrays(UINT8 *p_uuid1, UINT32 len1, UINT8 *p_uuid2, UINT16 len2)
{
    UINT8 nu1[MAX_UUID_SIZE];
    UINT8 nu2[MAX_UUID_SIZE];
    if (len1 == len2) {
        if (len1 == 2) return p_uuid1[0] == p_uuid2[0] && p_uuid1[1] == p_uuid2[1];
        if (len1 == 4) return p_uuid1[0] == p_uuid2[0] && p_uuid1[1] == p_uuid2[1] && p_uuid1[2] == p_uuid2[2] && p_uuid1[3] == p_uuid2[3];
        return memcmp(p_uuid1, p_uuid2, len1) == 0;
    } else if (len1 > len2) {
        if (len1 == 4) return p_uuid1[0] == 0 && p_uuid1[1] == 0 && p_uuid1[2] == p_uuid2[0] && p_uuid1[3] == p_uuid2[1];
        memcpy(nu1, p_uuid1, MAX_UUID_SIZE);
        memcpy(nu2, lbl_802EED40, MAX_UUID_SIZE);
        if (len2 == 4) memcpy(nu2, p_uuid2, len2); else memcpy(nu2 + 2, p_uuid2, len2);
        return memcmp(nu1, nu2, MAX_UUID_SIZE) == 0;
    } else {
        if (len2 == 4) return p_uuid2[0] == 0 && p_uuid2[1] == 0 && p_uuid2[2] == p_uuid1[0] && p_uuid2[3] == p_uuid1[1];
        memcpy(nu2, p_uuid2, MAX_UUID_SIZE);
        memcpy(nu1, lbl_802EED40, MAX_UUID_SIZE);
        if (len1 == 4) memcpy(nu1, p_uuid1, len1); else memcpy(nu1 + 2, p_uuid1, len1);
        return memcmp(nu1, nu2, MAX_UUID_SIZE) == 0;
    }
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

s32 IUSB_OpenLib(void) {
    extern s32 lbl_805590A0;
    extern s32 lbl_8055DC88;
    extern u32 lbl_8055DC8C;
    union {
        void *pointer;
        s32 value;
    } currentHeap;
    register char *base = lbl_8031A620;
    s32 result = 0;
    s32 interruptState;

    interruptState = OSDisableInterrupts();
    currentHeap.pointer = (void *)lbl_805590A0;
    if (currentHeap.value != -1) {
        USB_LOG(base + 0xC);
        goto done;
    }

    if (lbl_8055DC88 == 0) {
        lbl_8055DC88 = (s32)IPCGetBufferLo();
        USB_LOG(base + 0x3C, 0x80, lbl_8055DC88,
                (lbl_8055DC8C = (u32)IPCGetBufferHi()));

        if ((u32)lbl_8055DC88 + 0x1000 > lbl_8055DC8C) {
            USB_ERR(base + 0x5C);
            result = -0x16;
            goto done;
        }
        IPCSetBufferLo((void *)((u32)lbl_8055DC88 + 0x1000));
    }

    if ((lbl_805590A0 = iosCreateHeap((void *)lbl_8055DC88, 0x1000)) < 0) {
        USB_ERR(base + 0x74);
        result = -0x16;
    }

done:
    OSRestoreInterrupts(interruptState);
    return result;
}

u32 fn_8009B0E0(void) {
    return 0;
}

s32 _intBlkCtrlCb(s32 arg0, void *arg1) {
    extern s32 iosFree(s32, void *);
    extern s32 lbl_805590A0;
    register char *base = lbl_8031A620;
    unsigned char *block = arg1;
    long result;
    void *entry;
    unsigned char *entry_ptr;
    s32 i;
    void (*complete)(s32, void *);
    USB_LOG(base + 0x88, arg0);
    USB_LOG(base + 0xA8, *(u32 *)(block + 0x2C));
    if (*(u32 *)(block + 0x2C) != 7 && *(u32 *)(block + 0x2C) != 3 && *(u32 *)(block + 0x2C) != 0) {
        USB_ERR(base + 0xC8);
    } else {
        entry_ptr = block;
        i = 0;
        while (i < *(u32 *)(block + 0x2C)) {
            USB_LOG(base + 0xF0, i, *(void **)(entry_ptr + 0xC));
            entry = *(void **)(entry_ptr + 0xC);
            if (entry) {
                result = iosFree(lbl_805590A0, entry);
                if (result < 0) USB_ERR(base + 0x108, lbl_805590A0, entry, result);
            }
            entry_ptr += 4;
            i++;
        }
    }
    USB_LOG(base + 0x128, *(void **)block, *(void **)(block + 4));
    complete = *(void (**)(s32, void *))block;
    if (complete) complete(arg0, *(void **)(block + 4));
    if (arg1 != 0) {
        result = iosFree(lbl_805590A0, arg1);
        if (result < 0) USB_ERR(base + 0x108, lbl_805590A0, arg1, result);
    }
    return arg0;
}

extern s32 lbl_805590A0;
extern s32 _intBlkCtrlCb(s32, void *);
extern void *iosAllocAligned(s32, u32, u32);
extern s32 iosFree(s32, void *);
extern s32 IOS_CloseAsync(s32, s32 (*)(s32, void *), void *);
s32 IUSB_CloseDeviceAsync(s32 device, void (*callback)(void), void *callbackArg) {
    char *base = lbl_8031A620;
    void *block;
    s32 result;
    USB_LOG(base + 0x1FC);
    block = iosAllocAligned(lbl_805590A0, 0x80, 0x20);
    if (block == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x80, block);
    if (block == 0) {
        USB_ERR(base + 0x228);
        result = -0x16;
    } else {
        *(void **)block = (void *)callback;
        *(void **)((u8 *)block + 4) = callbackArg;
        *(s32 *)((u8 *)block + 0x2C) = 0;
        result = IOS_CloseAsync(device, _intBlkCtrlCb, block);
        USB_LOG(base + 0x20C, result);
        if (result < 0 && block != 0) {
            s32 freeResult = iosFree(lbl_805590A0, block);
            if (freeResult < 0) USB_ERR(base + 0x108, lbl_805590A0, block, freeResult);
        }
    }
    return result;
}

extern s32 IOS_Ioctlv(s32, s32, s32, s32, void *);
extern s32 IOS_IoctlvAsync(s32, s32, s32, s32, void *, void *, void *);
s32 __IntrBlkMsgInt(s32 fd, u32 endpoint, u32 length, void *buffer, s32 ioctl, void (*callback)(void), void *callbackArg, s32 async) {
    register char *base = lbl_8031A620;
    char *msg;
    s32 ret;
    s32 fr;
    char *blk;
    char *a;
    char *b;

    blk = iosAllocAligned(lbl_805590A0, 0x60, 0x20);
    if (blk == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x60, blk);
    a = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (a == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, a);
    b = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (b == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, b);

    if (blk == 0 || a == 0 || b == 0) {
        USB_ERR(base + 0x294);
        ret = -0x16;
        goto free_all;
    }

    *(u8 *)a = endpoint;
    *(u16 *)b = length;
    *(void **)(blk + 0) = a;
    *(s32 *)(blk + 4) = 1;
    *(void **)(blk + 8) = b;
    *(s32 *)(blk + 0xC) = 2;
    *(s32 *)(blk + 0x10) = (s32)buffer;
    *(s32 *)(blk + 0x14) = length;
    DCFlushRange(a, 0x20);
    DCFlushRange(b, 0x20);
    DCFlushRange(blk, 0x60);

    if (async == 0) {
        ret = IOS_Ioctlv(fd, ioctl, 2, 1, blk);
        USB_LOG(base + 0x2B8, ret);
        goto free_all;
    }

    msg = iosAllocAligned(lbl_805590A0, 0x80, 0x20);
    if (msg == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x80, msg);
    if (msg == 0) {
        USB_ERR(base + 0x2D8);
        ret = -0x16;
        goto free_all;
    }

    *(s32 *)(msg + 0) = (s32)callback;
    *(s32 *)(msg + 4) = (s32)callbackArg;
    USB_LOG(base + 0x304, (s32)callback, (s32)callbackArg);
    *(s32 *)(msg + 0x2C) = 3;
    *(void **)(msg + 0xC) = a;
    *(void **)(msg + 0x10) = b;
    *(void **)(msg + 0x14) = blk;
    *(s32 *)(msg + 0x40) = (s32)buffer;
    *(u16 *)(msg + 0x44) = length;
    ret = IOS_IoctlvAsync(fd, ioctl, 2, 1, blk, _intBlkCtrlCb, msg);
    if (ret >= 0) goto done;
    if (msg != 0) {
        fr = iosFree(lbl_805590A0, msg);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, msg, fr);
    }

free_all:
    if (a != 0) {
        fr = iosFree(lbl_805590A0, a);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, a, fr);
    }
    if (b != 0) {
        fr = iosFree(lbl_805590A0, b);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, b, fr);
    }
    if (blk != 0) {
        fr = iosFree(lbl_805590A0, blk);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, blk, fr);
    }
done:
    return ret;
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

void __BzeroDelayLines(void *arg0) {
    u8 *base = (u8 *)arg0;
    u8 *entry = base, *entry2 = base, *entry3 = base;
    u32 i = 0;
    do {
        if (*(void **)entry) memset(*(void **)entry, 0, *(u32 *)(base + 0x1C) * 4);
        if (*(void **)(entry + 0x2C)) memset(*(void **)(entry + 0x2C), 0, *(u32 *)(base + 0x40) * 4);
        {
            u8 *p = entry2, *q = base;
            u32 j = 0;
            do {
                if (*(void **)(p + 0x44)) memset(*(void **)(p + 0x44), 0, *(u32 *)(q + 0x80) * 4);
                j++; q += 4; p += 4;
            } while (j < 3);
        }
        {
            u8 *p = entry3, *q = base;
            u32 j = 0;
            do {
                if (*(void **)(p + 0x98)) memset(*(void **)(p + 0x98), 0, *(u32 *)(q + 0xC0) * 4);
                j++; q += 4; p += 4;
            } while (j < 2);
        }
        if (*(void **)(entry + 0xC8)) memset(*(void **)(entry + 0xC8), 0, *(u32 *)(entry + 0xEC) * 4);
        i++; entry2 += 0xC; entry3 += 8; entry += 4;
    } while (i < 3);
}

void __FreeDelayLine(void *arg0) {
    extern void *lbl_805590B4;
    u8 *base = (u8 *)arg0;
    u8 *p0 = base;
    u8 *p44 = base;
    u8 *p98 = base;
    u32 i = 0;
    u32 j;

    do {
        if (*(void **)p0 != 0) {
            ((void (*)(void))lbl_805590B4)();
            *(void **)p0 = 0;
        }
        if (*(void **)(p0 + 0x2C) != 0) {
            ((void (*)(void))lbl_805590B4)();
            *(void **)(p0 + 0x2C) = 0;
        }

        for (j = 0; j < 3; j++) {
            if (*(void **)(p44 + 0x44) != 0) {
                ((void (*)(void))lbl_805590B4)();
                *(void **)(p44 + 0x44) = 0;
            }
            p44 += 4;
        }

        for (j = 0; j < 2; j++) {
            if (*(void **)(p98 + 0x98) != 0) {
                ((void (*)(void))lbl_805590B4)();
                *(void **)(p98 + 0x98) = 0;
            }
            p98 += 4;
        }

        if (*(void **)(p0 + 0xC8) != 0) {
            ((void (*)(void))lbl_805590B4)();
            *(void **)(p0 + 0xC8) = 0;
        }
        i++;
        p0 += 4;
    } while (i < 3);
}

f64 fn_8002EFBC(f64, f32);
u32 __cvt_fp2unsigned(f32);
extern u8 lbl_8031ABD8[];
extern f32 lbl_80560D58;
extern f32 lbl_80560D5C;
extern f32 lbl_80560D60;
extern f32 lbl_80560D64;
extern f32 lbl_80560D78;
extern f64 lbl_80560D80;
extern f32 lbl_80560D88;
extern f64 lbl_80560D90;
s32 __InitParams(void *arg0) {
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4, temp_f0_5, temp_f0_6;
    f32 temp_f1, temp_f2, temp_f29, temp_f30, temp_f31, temp_f3, temp_f4;
    s32 temp_r6, temp_r8, var_r25, var_r27;
    u32 temp_r0, temp_r4, var_r24;
    u8 *base;
    u8 *cfg;
    void *temp_r3, *temp_r4_2, *temp_r5, *temp_r7, *var_r26, *var_r28;

    temp_r4 = *(u32 *)((u8 *)arg0 + 0x110);
    base = lbl_8031ABD8;
    cfg = arg0;
    if (temp_r4 >= 8U) return 0;
    temp_f4 = *(f32 *)(cfg + 0x118);
    if (temp_f4 < lbl_80560D5C || temp_f4 > *(f32 *)(cfg + 0x114)) return 0;
    if (*(u32 *)(cfg + 0x11C) >= 6U) return 0;
    if (*(f32 *)(cfg + 0x120) < lbl_80560D5C) return 0;
    temp_f0 = *(f32 *)(cfg + 0x124);
    if (temp_f0 < lbl_80560D5C || temp_f0 > lbl_80560D60) return 0;
    temp_f0_2 = *(f32 *)(cfg + 0x128);
    if (temp_f0_2 < lbl_80560D5C || temp_f0_2 > lbl_80560D60) return 0;
    temp_f0_3 = *(f32 *)(cfg + 0x12C);
    if (temp_f0_3 < lbl_80560D5C || temp_f0_3 > lbl_80560D60) return 0;
    temp_f3 = *(f32 *)(cfg + 0x130);
    if (temp_f3 < lbl_80560D5C || temp_f3 > lbl_80560D60) return 0;
    temp_f0_4 = *(f32 *)(cfg + 0x134);
    if (temp_f0_4 < lbl_80560D5C || temp_f0_4 > lbl_80560D60) return 0;
    temp_f0_5 = *(f32 *)(cfg + 0x140);
    if (temp_f0_5 < lbl_80560D5C || temp_f0_5 > lbl_80560D60) return 0;
    temp_f0_6 = *(f32 *)(cfg + 0x144);
    if (temp_f0_6 < lbl_80560D5C || temp_f0_6 > lbl_80560D60) return 0;

    temp_f0 = lbl_80560D58;
    temp_f2 = lbl_80560D64;
    var_r27 = 0;
    temp_f1 = temp_f0 * temp_f4;
    temp_r8 = temp_r4 * 0xC;
    temp_r5 = base + 0x60;
    temp_r7 = base + temp_r8;
    temp_r6 = *(s32 *)((u8 *)temp_r7 + 8);
    temp_r4_2 = (u8 *)temp_r5 + temp_r8;
    *(s32 *)(cfg + 0x18) = temp_r6;
    *(s32 *)(cfg + 0xC) = temp_r6 - *(s32 *)(base + temp_r8);
    *(f32 *)(cfg + 0x20) = temp_f3 * *(f32 *)((u8 *)temp_r5 + temp_r8) * temp_f2;
    *(s32 *)(cfg + 0x10) = temp_r6 - *(s32 *)((u8 *)temp_r7 + 4);
    *(f32 *)(cfg + 0x24) = temp_f3 * *(f32 *)((u8 *)temp_r4_2 + 4) * temp_f2;
    *(s32 *)(cfg + 0x14) = temp_r6 - *(s32 *)((u8 *)temp_r7 + 8);
    *(s32 *)(cfg + 0x38) = var_r27;
    *(f32 *)(cfg + 0x28) = temp_f3 * *(f32 *)((u8 *)temp_r4_2 + 8) * temp_f2;
    *(u32 *)(cfg + 0x3C) = __cvt_fp2unsigned(temp_f1);

    var_r26 = cfg;
    temp_f29 = lbl_80560D90;
    var_r28 = base + 0xC0;
    temp_f30 = lbl_80560D78;
    var_r24 = 0;
    temp_f31 = lbl_80560D58;
    var_r25 = 0;
    do {
        *(s32 *)((u8 *)var_r26 + 0x68) = var_r27;
        temp_r0 = *(u32 *)((u8 *)var_r28 + (*(u32 *)(cfg + 0x11C) << 5) + var_r25);
        *(u32 *)((u8 *)var_r26 + 0x74) = temp_r0;
        var_r24 += 1;
        var_r25 += 4;
        temp_f0 = *(f32 *)(cfg + 0x120);
        *(f32 *)((u8 *)var_r26 + 0x8C) = (f32)fn_8002EFBC(lbl_80560D80,
            (temp_f30 * (f32)temp_r0) / (temp_f31 * temp_f0));
        var_r26 = (u8 *)var_r26 + 4;
    } while (var_r24 < 3U);

    *(s32 *)(cfg + 0xB0) = 0;
    temp_r3 = (u8 *)var_r28 + (*(u32 *)(cfg + 0x11C) << 5);
    temp_f1 = lbl_80560D60 - *(f32 *)(cfg + 0x128);
    *(s32 *)(cfg + 0xB8) = *(s32 *)((u8 *)temp_r3 + 0xC);
    *(s32 *)(cfg + 0xB4) = 0;
    *(s32 *)(cfg + 0xBC) = *(s32 *)((u8 *)temp_r3 + 0x10);
    *(s32 *)(cfg + 0xD4) = 0;
    *(s32 *)(cfg + 0xE0) = *(s32 *)((u8 *)temp_r3 + 0x14);
    *(s32 *)(cfg + 0xD8) = 0;
    *(s32 *)(cfg + 0xE4) = *(s32 *)((u8 *)temp_r3 + 0x18);
    *(s32 *)(cfg + 0xDC) = 0;
    *(s32 *)(cfg + 0xE8) = *(s32 *)((u8 *)temp_r3 + 0x1C);
    *(f32 *)(cfg + 0xF8) = *(f32 *)(cfg + 0x124);
    *(f32 *)(cfg + 0x108) = temp_f1;
    if (temp_f1 > lbl_80560D88) *(f32 *)(cfg + 0x108) = lbl_80560D88;
    *(f32 *)(cfg + 0xFC) = lbl_80560D5C;
    *(f32 *)(cfg + 0x100) = lbl_80560D5C;
    *(f32 *)(cfg + 0x104) = lbl_80560D5C;
    return 1;
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

#pragma push
#pragma opt_propagation off
void fn_8006CF44(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u32 arg8) {
    u8 *ptr = (u8 *)&lbl_80392960;
    void (*func)(void);
    if (arg8 == 3) {
        func = *(void (**)(void))(ptr + 0x66C);
        if (func) func();
    } else {
        DBPrintf_8006CFA8(lbl_803140D0, arg8);
    }
}
#pragma pop
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

void WUDStoredLinkKeyCallback(void *msg);
extern void *WUDiGetNewDevInfo(void);
extern const char lbl_80558FE8;
void WUDStoredLinkKeyCallback(void *msg) {
    u8 *base = (u8 *)msg;
    char *fmt;
    u8 *dev_info;
    u8 *dev;
    u8 *new_dev;
    u8 *gbase;
    s32 i;

    fmt = (char *)lbl_803130C8;
    gbase = lbl_80392960;
    switch (base[0]) {
    case 1:
        DBPrintf_8006CFA8(fmt + 0xb2c);
        dev_info = base + 2;
        i = 0;
        while (i < base[1]) {
            dev = WUDiGetDevInfo(dev_info);
            DBPrintf_8006CFA8(fmt + 0xb4c, dev_info[0], dev_info[1], dev_info[2], dev_info[3], dev_info[4], dev_info[5]);
            DBPrintf_8006CFA8(fmt + 0xb78, dev_info[6], dev_info[7], dev_info[8], dev_info[9],
                              dev_info[10], dev_info[11], dev_info[12], dev_info[0xD], dev_info[0xE], dev_info[0xF],
                              dev_info[0x10], dev_info[0x11], dev_info[0x12], dev_info[0x13], dev_info[0x14], dev_info[0x15]);
            if (dev == 0) {
                DBPrintf_8006CFA8(fmt + 0xbd4);
                new_dev = WUDiGetNewDevInfo();
                if (new_dev == 0) {
                    for (i = 0; i < 6; i++) {
                        if (gbase[i * 0x60 + 0x47d] == 0) {
                            new_dev = gbase + i * 0x60 + 0x424;
                            break;
                        }
                    }
                }
                if (new_dev != 0) {
                    new_dev[0x5c] = 1;
                    new_dev[0x59] = 1;
                    memcpy(new_dev + 0x40, dev_info, 6);
                    memcpy(new_dev + 0x46, dev_info + 6, 0x10);
                }
            } else {
                memcpy(dev + 0x40, dev_info, 6);
                memcpy(dev + 0x46, dev_info + 6, 0x10);
                if (dev[0x5c] == 2) {
                    dev[0x5c] = 3;
                }
                memcpy(gbase + 0x67c, dev_info, 6);
                DBPrintf_8006CFA8(fmt + 0xbf8, gbase[0x67c], gbase[0x67d], gbase[0x67e],
                                  gbase[0x67f], gbase[0x680], gbase[0x681]);
            }
            dev_info += 0x16;
            i++;
        }
        break;
    case 2:
        DBPrintf_8006CFA8(fmt + 0xc20);
        DBPrintf_8006CFA8(fmt + 0xc44, base[1], *(u16 *)(base + 2), *(u16 *)(base + 4));
        gbase[0xe] = 0;
        break;
    case 3:
        DBPrintf_8006CFA8(fmt + 0xc70);
        DBPrintf_8006CFA8(fmt + 0xc94, base[1], base[2]);
        gbase[0xe] = 0;
        break;
    case 4:
        DBPrintf_8006CFA8(fmt + 0xcb0);
        DBPrintf_8006CFA8(fmt + 0xc94, base[1], *(u16 *)(base + 2));
        if (*(u16 *)(base + 2) == 0) {
            DBPrintf_8006CFA8(fmt + 0xcd4);
        }
        gbase[0xe] = 0;
        break;
    default:
        OSPanic((char *)&lbl_80558FE8, 0xe34, fmt + 0xcf4);
        break;
    }
}

extern u8 lbl_803130C8[];
extern u8 lbl_803935C8[];
void WUDPowerManagerCallback(u8 *addr, s32 result, s32 unused, s32 arg) {
    u8 *strings = lbl_803130C8;
    u8 *dev;

    DBPrintf_8006CFA8((char *)strings + 0xd04);
    DBPrintf_8006CFA8((char *)strings + 0xd20, arg);

    dev = WUDiGetDevInfo(addr);
    if (dev == 0) {
        if (memcmp(lbl_803935C8 + 0x40, addr, 6) == 0)
            dev = lbl_803935C8;
    }

    switch (result) {
    case 0:
        dev[0x59] = 8;
        break;
    case 2:
        dev[0x59] = 9;
        break;
    }

    DBPrintf_8006CFA8((char *)strings + 0xd30, dev[0x40], dev[0x41], dev[0x42], dev[0x43], dev[0x44], dev[0x45], dev[0x59]);
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

extern s32 StartSyncDevice(u8 syncType, s8 syncLoopNum, BOOL syncSkipChecks);
#pragma push
#pragma scheduling on
void WUDVendorSpecificCallback(u8 len, register u8 *pData) {
    typedef void (*WUDSyncCallback)(s32, s32);
    typedef void (*WUDClearCallback)(s32);
    register u8 *state = lbl_80392960;
    register u8 *strings = lbl_803130C8;
    u8 event = pData[0];
    u32 enabled, busyEnabled;
    s32 busy, result, started, libStatus;
    WUDSyncCallback syncCallback;
    WUDClearCallback clearCallback;

    (void)len;
    switch (event) {
    case 8:
        DBPrintf_8006CFA8((const char *)strings + 0xA58);
        DBPrintf_8006CFA8((const char *)strings + 0x598);
        enabled = OSDisableInterrupts();
        syncCallback = *(WUDSyncCallback *)lbl_80392960;
        busyEnabled = OSDisableInterrupts();
        if (state[0xC] == 0 && state[0xD] == 0 &&
            state[0xF] == 4 && state[0x10] == 4) {
            OSRestoreInterrupts(busyEnabled);
            busy = 0;
        } else {
            OSRestoreInterrupts(busyEnabled);
            busy = 1;
        }
        result = busy ? -1 : 0;
        OSRestoreInterrupts(enabled);
        if (syncCallback != NULL) {
            syncCallback(result, 0);
            break;
        }
        DBPrintf_8006CFA8((const char *)strings + 0x410);
        started = StartSyncDevice(0, 3, 0);
        enabled = OSDisableInterrupts();
        syncCallback = *(WUDSyncCallback *)lbl_80392960;
        OSRestoreInterrupts(enabled);
        if (started == 0 && syncCallback != NULL) {
            syncCallback(-1, 0);
        }
        break;

    case 9: {
        register u8 *clearState = lbl_80392960;
        DBPrintf_8006CFA8((const char *)strings + 0xA70);
        DBPrintf_8006CFA8((const char *)strings + 0x5BC);
        enabled = OSDisableInterrupts();
        clearCallback = *(WUDClearCallback *)(state + 8);
        busyEnabled = OSDisableInterrupts();
        if (state[0xC] == 0 && state[0xD] == 0 &&
            state[0xF] == 4 && state[0x10] == 4) {
            OSRestoreInterrupts(busyEnabled);
            busy = 0;
        } else {
            OSRestoreInterrupts(busyEnabled);
            busy = 1;
        }
        result = busy ? -1 : 0;
        OSRestoreInterrupts(enabled);
        if (clearCallback != NULL) {
            clearCallback(result);
            break;
        }
        DBPrintf_8006CFA8((const char *)strings + 0x470);
        enabled = OSDisableInterrupts();
        libStatus = (s8)clearState[0x688];
        OSRestoreInterrupts(enabled);
        if ((u32)libStatus != 3U) break;
        busyEnabled = OSDisableInterrupts();
        if (clearState[0xC] == 0 && clearState[0xD] == 0 &&
            clearState[0xF] == 4 && clearState[0x10] == 4) {
            OSRestoreInterrupts(busyEnabled);
            busy = 0;
        } else {
            OSRestoreInterrupts(busyEnabled);
            busy = 1;
        }
        if (busy != 0) break;
        enabled = OSDisableInterrupts();
        clearState[0xD] = 1;
        OSCreateAlarm((OSAlarm *)(clearState + 0x690));
        OSSetPeriodicAlarm((OSAlarm *)(clearState + 0x690), __OSGetSystemTime(),
                           OS_MSEC_TO_TICKS(20), (OSAlarmHandler)fn_80069EB4);
        OSRestoreInterrupts(enabled);
        break;
    }

    case 10:
        DBPrintf_8006CFA8((const char *)strings + 0xA88, pData[1]);
        state[0x689] = pData[1];
        break;
    case 16:
        DBPrintf_8006CFA8((const char *)strings + 0xAAC, pData[1]);
        OSPanic(&lbl_80558FE8, 0xD9C, (const char *)strings + 0xAD4);
        break;
    }
}
#pragma pop
extern u32 lbl_8055DCA4;
extern char lbl_80315700[];
extern void *jumptable_803159A0[];
extern u8 lbl_80559060[];
extern u8 lbl_803151D8[];
extern char lbl_80319EC0[];
extern char lbl_8031669C[];
void fn_80085DF4(void *arg0, u8 arg1) {
    *(u16 *)((u8 *)arg0 + 2) = 4;
    *(u16 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x45;
    *(u8 *)((u8 *)arg0 + 9) = 0x0C;
    *(u8 *)((u8 *)arg0 + 10) = 1;
    *(u8 *)((u8 *)arg0 + 11) = arg1;
    btu_hcif_send_cmd(arg0);
}

void fn_80085E24(void *arg0, u8 arg1) {
    *(u16 *)((u8 *)arg0 + 2) = 4;
    *(u16 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 8) = 0x47;
    *(u8 *)((u8 *)arg0 + 9) = 0x0C;
    *(u8 *)((u8 *)arg0 + 10) = 1;
    *(u8 *)((u8 *)arg0 + 11) = arg1;
    btu_hcif_send_cmd(arg0);
}

