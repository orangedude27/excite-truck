extern unsigned char lbl_80313E90[];
extern unsigned char lbl_803935C8[];
extern unsigned char lbl_803C3AF0[];
extern unsigned char lbl_803C0A50[];
extern void WUDiMoveTopStdDevInfoPtr(unsigned char *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <stdarg.h>
#include <printf.h>
#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/include/gap_api.h"
#define btm_sco_chk_pend_unpark btm_sco_chk_pend_unpark_old2
#include "revolution/BTE/stack/btm/btm_int.h"
#undef btm_sco_chk_pend_unpark
#define btsnd_hcic_reject_conn btsnd_hcic_reject_conn_public
#define btsnd_hcic_reject_esco_conn btsnd_hcic_reject_esco_conn_public
#define btsnd_hcic_accept_conn btsnd_hcic_accept_conn_public
#define btsnd_hcic_write_cur_iac_lap btsnd_hcic_write_cur_iac_lap_hcimsgs
#define btsnd_hcic_exit_sniff_mode btsnd_hcic_exit_sniff_mode_api
#define btsnd_hcic_sniff_mode btsnd_hcic_sniff_mode_api
#define btsnd_hcic_accept_esco_conn btsnd_hcic_accept_esco_conn_api
#define btsnd_hcic_set_event_filter btsnd_hcic_set_event_filter_4arg
#include "revolution/BTE/stack/include/hcimsgs.h"
#undef btsnd_hcic_set_event_filter
extern BOOLEAN btsnd_hcic_set_event_filter(void *, UINT8, UINT8, UINT8 *, UINT8);
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
extern void BTA_DmSetVisibility(unsigned char, unsigned char);
typedef struct {
    u8 _p0[0x110];
    u32 earlyMode;
    f32 preDelayTimeMax;
    f32 preDelayTime;
    u32 fusedMode;
    f32 fusedTime;
    f32 coloration;
    f32 damping;
    f32 crosstalk;
    f32 earlyGain;
    f32 fusedGain;
    void *busIn;
    void *busOut;
    f32 outGain;
    f32 sendGain;
} AutoReverbExp;
typedef struct {
    AutoReverbExp exp;
    f32 coloration;
    f32 mix;
    f32 time;
    f32 damping;
    f32 preDelay;
    f32 crosstalk;
} AutoReverbHi;


/* Forward declare tL2C_CONN_INFO for l2c_csm_w4_l2ca_connect_rsp */
typedef struct {
    u8 bd_addr[6];
    u8 status;
    u16 psm;
    u16 l2cap_result;
    u16 l2cap_status;
    u16 remote_cid;
} tL2C_CONN_INFO;
typedef struct { UINT8 tod; UINT8 app_id; } BtaHhSptTodLocal;
typedef struct { UINT8 max_devt_spt; UINT8 _pad[3]; BtaHhSptTodLocal *p_devt_list; } BtaHhCfgLocal;
extern u8 fn_8006EB80(void);
  extern char lbl_80314128[];
  extern char lbl_803187B0[];
  void rfc_send_buf_uih();
void rfc_process_mx_message();

/* logical struct used for decoding RFCOMM MX frames (see rfc_int.h) */
typedef struct {
    UINT8 dlci;
    UINT8 type;
    UINT8 cr;
    UINT8 ea;
    UINT8 pf;
    UINT8 credit;
    union {
        struct { UINT8 dlci; UINT8 frame_type; UINT8 conv_layer; UINT8 priority; UINT8 t1; UINT16 mtu; UINT8 n2; UINT8 k; } pn;
        struct { UINT8 *p_data; UINT16 data_len; } test;
        struct { UINT8 dlci; UINT8 signals; UINT8 break_present; UINT8 break_duration; } msc;
        struct { UINT8 ea; UINT8 cr; UINT8 type; } nsc;
        struct { UINT8 dlci; UINT8 is_request; UINT8 baud_rate; UINT8 byte_size; UINT8 stop_bits; UINT8 parity; UINT8 parity_type; UINT8 fc_type; UINT8 xon_char; UINT8 xoff_char; UINT16 param_mask; } rpn;
        struct { UINT8 dlci; UINT8 line_status; } rls;
    } u;
} MX_FRAME;
extern s32 lbl_805590A0;
extern void fn_8006B330(void);
extern void l2cu_release_ccb(void *);
extern void l2cu_send_peer_connect_req(void *);
extern void *iosAllocAligned(s32, u32, u32);
extern s32 iosFree(s32, void *);
static void USB_LOG(const char *, ...);
static void USB_ERR(const char *, ...);
extern void bta_hh_add_device_to_list(void *, s8, s16, void *, s32, s32);
extern char lbl_80313258[];
extern char lbl_803191B4[];
extern char lbl_80314110[];
extern u32 lbl_803946C0[];
extern u8 *lbl_80559030;
extern void fn_8006EBF0();
extern char lbl_80316EE0[];
extern char lbl_80315EBC[];
extern char lbl_80315F80[];
extern s32 btsnd_hcic_auth_request_800858B0(u16);
extern void btm_sec_collision_timeout(void);
extern void rfc_send_rpn();
extern void rfc_send_msc();
extern u8 HID_HostCloseDev(u8);
static tBTM_STATUS btm_set_inq_event_filter(UINT8, UINT8 *);

typedef struct {
    u8 pad[0x554];
    tBTM_PM_RCB pm_reg_db[BTM_MAX_PM_RECORDS + 1];
} tBTM_PM_REG_DB_MATCH_VIEW;

/* The power manager's per-ACL-link mode control block (btm_int.h's tBTM_PM_MCB)
   as this stack lays it out: 0x22 bytes, one per link in btm_cb at +0x4CC.  The
   header's version is bigger - it holds BTM_MAX_PM_RECORDS + 1 requests and the
   SSR fields this build has - so only the fields this unit reaches are named. */
typedef struct {
    tBTM_PM_PWR_MD req_mode[BTM_MAX_PM_RECORDS]; /* +0x00 what each registered module asked for */
    tBTM_PM_PWR_MD set_mode;    /* +0x14 the mode sent down to the controller */
    UINT16         interval;    /* +0x1E interval from the last mode change */
    tBTM_PM_STATE  state;       /* +0x20 the current mode of the connection */
    BOOLEAN        chg_ind;     /* +0x21 a mode change is on its way */
} tBTM_PM_MCB_VIEW;

typedef struct {
    u8 pad0[0x25];
    u8 link_key[16];
    u8 pad35[0x41];
    u8 sec_flags_76;
    u8 pad77[0x0A];
    u8 sec_flags_81;
} tBTM_SEC_DEV_REC_MATCH_VIEW;

typedef struct {
    u8 pad0[4];
    u32 unk_0x04;
    u8 pad08[0x10];
    u16 hci_handle;
    u8 pad1A[2];
    u8 bd_addr[6];
    u8 dev_class[3];
    u8 pad25[0x10];
    u8 sec_bd_name[0x41];
    u8 sec_flags;
    u8 pad77[8];
    u8 sec_state;
    u8 pad80;
    u8 sm4;
} tBTM_SEC_DEV_REC_DISCONNECT_VIEW;

/* Number of extra link key notifiers registered in btm_cb (btm_cb+0x1924). */
#define BTM_SEC_MAX_LINK_KEY_NOTIFY_CALLBACKS 2

/* The security-manager callbacks as btm_cb holds them.  The app installs the
   first six with BTM_SecRegister(); the header's typedefs for them use the
   248-byte name buffer this stack does not carry, so the name is a plain
   string here (tBTM_SEC_DEV_REC_FULL_VIEW.sec_bd_name). */
typedef UINT8 (tBTM_LINK_KEY_NOTIFY_CB) (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                         u8 *bd_name, LINK_KEY link_key,
                                         UINT8 key_type);
typedef UINT8 (tBTM_AUTH_COMPLETE_CB) (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                       u8 *bd_name, UINT32 result);

/*
 * btm_cb - the BTM module's control block (lbl_803C0F78) - as this stack lays
 * it out, with the members the security manager uses named.
 */
typedef struct {
    u8      pad_0000[0x0020];
    u8      cfg_pin_type;                /* 0x0020 PIN type from BTM_SetPinType() */
    u8      pad_0021[0x18F3];
    tBTM_LINK_KEY_NOTIFY_CB *p_link_key_callback;    /* 0x1914 new link key */
    u8      pad_1918[0x04];              /* 0x1918 link key request callback */
    tBTM_AUTH_COMPLETE_CB *p_auth_complete_callback; /* 0x191C pairing done */
    u8      pad_1920[0x04];              /* 0x1920 abort callback */
    tBTM_LINK_KEY_NOTIFY_CB *p_link_key_notify_callback
        [BTM_SEC_MAX_LINK_KEY_NOTIFY_CALLBACKS];     /* 0x1924 extra notifiers */
    u8      pad_192C[0x10];              /* 0x192C remote name callbacks */
    u8      pin_code_tle[0x10];          /* 0x193C timer waiting for a local PIN */
    void    *pin_code_tle_cback;         /* 0x194C non-NULL while that timer runs */
    u8      pad_1950[0x04];
    BD_ADDR pin_code_bda;                /* 0x1954 device the PIN was asked for */
    u8      pad_195A[0x001A];
    UINT32  dev_rec_count;               /* 0x1974 counter stamped into dev records */
    UINT8   security_mode;               /* 0x1978 BTM_SEC_MODE_* */
    u8      pad_1979[0x02];              /* 0x1979 pairing_disabled, connect_only_paired */
    UINT8   security_mode_changed;       /* 0x197B security_mode raised for pairing */
    UINT8   pin_type_changed;            /* 0x197C PIN type changed for pairing */
    u8      pad_197D[0x0E42];
    UINT8   acl_disc_reason;             /* 0x27BF reason to report when the ACL drops */
    UINT8   trace_level;                 /* 0x27C0 BTM trace level */
} tBTM_CB_SEC_VIEW;

#define btm_cb_sec (*(tBTM_CB_SEC_VIEW *)lbl_803C0F78)

/*
 * The btm_cb (lbl_803C0F78) members the security manager uses, named from the
 * code that reads them.  Reading them through tBTM_CB_SEC_VIEW instead changes
 * how the compiler allocates registers, so the code keeps the byte offsets and
 * these macros.
 */
#define btm_cb_cfg_pin_type     (lbl_803C0F78[0x0020]) /* PIN type from BTM_SetPinType() */
#define btm_cb_security_mode    (lbl_803C0F78[0x1978]) /* BTM_SEC_MODE_*; 3 is secure pairing here */
#define btm_cb_mode_changed     (lbl_803C0F78[0x197B]) /* security mode was raised for this pairing */
#define btm_cb_pin_type_changed (lbl_803C0F78[0x197C]) /* PIN type was changed for this pairing */
#define btm_cb_bonding          (lbl_803C0F78[0x197D]) /* pairing is bringing a link up */
#define btm_cb_disc_reason      (lbl_803C0F78[0x197E]) /* reason to report when that link drops */
#define btm_cb_pin_code_len     (lbl_803C0F78[0x197F]) /* length of the PIN below */
#define btm_cb_pin_code         (lbl_803C0F78 + 0x1980) /* PIN kept for the controller to ask for */
#define btm_cb_trace_level      (lbl_803C0F78[0x27C0]) /* BTM_TRACE_LEVEL_* */
#define btm_cb_cfg_pin_code_len (lbl_803C0F78[0x0021]) /* fixed PIN length from BTM_SetPinType() */
#define btm_cb_cfg_pin_code     (lbl_803C0F78 + 0x0022) /* fixed PIN from BTM_SetPinType() */
#define btm_cb_p_pin_callback   (lbl_803C0F78 + 0x1910) /* upper-layer PIN request callback slot */
#define btm_cb_pin_timer        (lbl_803C0F78 + 0x193C) /* PIN request timeout timer */
#define btm_cb_pin_timer_cback  (lbl_803C0F78 + 0x194C) /* its timeout function */
#define btm_cb_pairing_bda      (lbl_803C0F78 + 0x1954) /* BDA of the device being paired */
#define btm_cb_pairing_disabled (lbl_803C0F78[0x1979]) /* upper layer disabled pairing */
#define btm_cb_connecting_bda   (lbl_803C0F78 + 0x27B4) /* BDA of the device being connected */
#define btm_cb_connecting_dc    (lbl_803C0F78 + 0x27BA) /* its class of device */

/* The HCI Write_Authentication_Enable command (opcode 0x0C20); the game's
   symbol for it still carries the name of the PIN-type helper next to it. */
#define btsnd_hcic_write_auth_enable btsnd_hcic_write_pin_type_8008543C

/*
 * tBTM_SEC_DEV_REC as this stack lays it out: 0x88 bytes, and 0x10 of them
 * (this build's BTM_SEC_MAX_DEVICE_RECORDS; the header's 100 is a newer
 * config) in btm_cb at 0x1F30, ending where connecting_bda starts at 0x27B0.  The
 * header's struct agrees up to is_originator and then describes a newer
 * stack, so the security-manager bytes at the end are named from the code.
 */
typedef struct {
    tBTM_SEC_SERV_REC *p_cur_service;    /* 0x00 service this connection is for */
    tBTM_SEC_CBACK    *p_callback;       /* 0x04 who asked for security */
    void              *p_ref_data;       /* 0x08 its reference value */
    UINT32             timestamp;        /* 0x0C when the link last came up */
    UINT32             trusted_mask[2];  /* 0x10 bitwise OR of trusted services */
    UINT16             hci_handle;       /* 0x18 */
    UINT16             clock_offset;     /* 0x1A */
    BD_ADDR            bd_addr;          /* 0x1C */
    DEV_CLASS          dev_class;        /* 0x22 */
    LINK_KEY           link_key;         /* 0x25 */
    u8                 sec_bd_name[0x41];/* 0x35 name of the device */
    UINT8              sec_flags;        /* 0x76 BTM_SEC_* flags of what is done */
    u8                 features[8];      /* 0x77 LMP features of the device */
    UINT8              sec_state;        /* 0x7F BTM_SEC_STATE_* */
    UINT8              is_originator;    /* 0x80 we opened the connection */
    UINT8              sec_req;          /* 0x81 BTM_SEC_* requirements of p_cur_service */
    UINT8              link_key_not_sent;/* 0x82 link key notification still owed */
    UINT8              link_key_type;    /* 0x83 */
    UINT8              link_key_changed; /* 0x84 */
    UINT8              conn_up;          /* 0x85 set when a link to a known record comes up */
    UINT8              sm4;              /* 0x86 */
    UINT8              rmt_io_caps;      /* 0x87 */
} tBTM_SEC_DEV_REC_FULL_VIEW;

/* This stack has no role-switch security state, so the "disconnecting" state
   the security manager parks a record in while it drops the link is the
   header's BTM_SEC_STATE_SWITCHING_ROLE (5); its BTM_SEC_STATE_DISCONNECTING
   (6) belongs to a newer stack. */
#define BTM_SEC_STATE_DISCONNECTING_HERE 5

typedef struct {
    char first;
} tRFCOMM_TRACE_TEXT_VIEW;

typedef struct {
    u8 pad0[0x10];
    u8 cb[0x10];
} tBTA_HH_DEV_ENTRY_VIEW;

typedef struct {
    u8 pad0[0x0C];
    u8 sync_state;
    u8 delete_state;
    u8 pad0E;
    u8 stack_state;
    u8 init_state;
    u8 pad11[0x655];
    u8 synced_num;
    u8 sync_skip_checks;
    s8 sync_loop_num;
    u8 sync_type;
    u8 pad66A[0x1E];
    volatile s8 lib_status;
    u8 pad689[7];
    OSAlarm sync_alarm;
} WUDSyncControlView;

typedef struct {
    u8 in_use;
    u8 pad_0x01[9];
    u8 state;
    u8 pad_0x0B;
    u8 conn_tries;
    u8 pad_0x0D[0x0F];
    u8 timer_entry[0x18];
} tHID_HOST_DEV_VIEW;

extern void *WUDiGetNewDevInfo(void);
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
typedef struct {
    u8 pad0[0x12];
    u8 index;
    u8 pad13[3];
    u8 hid_handle;
    u8 pad17[5];
    u8 state;
    u8 pad1D[3];
} tBTA_HH_DEV_CB_MATCH;

typedef struct {
    u8 pad0[0x10];
    tBTA_HH_DEV_CB_MATCH kdev[0x10];
    u8 p_cur[4];
    u8 cb_index[0x10];
    void *p_cback;
    u8 pad228[8];
} tBTA_HH_CB_MATCH;

#define UUSB_CB_DEFINED_EARLY 1
extern u8 lbl_803C0F78[];
extern char lbl_80316464[];
extern void fn_8007093C(u32, void *);
extern s32 btsnd_hcic_link_key_neg_reply_800843D8(u8 *);
extern BOOLEAN l2c_link_hci_conn_comp(UINT8 status, UINT16 handle, UINT8 *p_bda);
static inline u8 *btm_bda_to_acl_inl(u8 *bda) {
    u8 *q = lbl_803C0F78 + 0x34;
    u32 j = 0;
    for (; j < 4; j++, q += 0x11C) {
        if (q[0x119] && memcmp(q + 8, bda, 6) == 0) return q;
    }
    return 0;
}
extern uusb_cb_t lbl_803BD1E0;
extern char lbl_803142C8[];
extern char lbl_803BE240[];
__declspec(section ".sdata") extern char lbl_80558FF8[];
__declspec(section ".sdata") extern char lbl_80559000[];
extern void fn_80070844(void *);
extern BT_HDR *l2cap_link_chk_pkt_start(BT_HDR *);
extern BOOL l2cap_link_chk_pkt_end(void);
extern u8 lbl_8055DC50;
extern u8 lbl_8055DC51;
extern void uusb_CloseDeviceCB(s8);
extern void uusb_issue_intr_read(void);
extern void uusb_issue_bulk_read(void);
extern s32 IUSB_ReadIntrMsgAsync(s32, u32, u32, void *, void (*)(void), void *);
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
extern s32 SCCheckStatus(void);
extern s32 SCSetBtDeviceInfoArray(void *);
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
extern u8 fn_8009504C(u16, u8 *);
extern u8 lbl_803C3740[];
extern void fn_800826D4(void);
extern void fn_800833E8(void *);
extern void fn_800833F4(void *);
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
extern u16 UUSB_Write(u8, u8 *, u16, BT_HDR *);
extern void sdp_connect_ind(u8 *, u16, u16, u8);
extern void sdp_connect_cfm(u16, u16);
extern void sdp_config_ind(u16, void *);
extern void sdp_config_cfm(u16, u16 *);
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
extern u8 lbl_80559058;
extern char lbl_80319278[];
extern char lbl_80319290[];
extern void RFCOMM_ParNegReq(void *, s32, s32);
extern void rfc_release_multiplexer_channel(void *);
extern void port_release_port(void *);
extern void rfc_check_mcb_active(void *);
extern u8 lbl_803C3AF0[];
extern char lbl_80317700[];
extern void fn_80086468(void *);
u8 btm_sec_start_authorization(u8 *p);
static __inline BOOLEAN btm_sec_are_all_trusted_inl(u32 *p_mask) {
    if (p_mask[0] != 0xFFFFFFFF)
        return 0;
    if (p_mask[1] != 0xFFFFFFFF)
        return 0;
    return 1;
}
extern void *l2cu_allocate_lcb(u8 *);
extern BOOLEAN l2cu_create_conn(void *);
extern u8 lbl_803C4040[];

/* The L2CAP control block l2cb (l2c_int.h's tL2C_CB): lbl_803C4040 is its
   address and byte 0 is its first field, l2cb.l2cap_trace_level. The stack's
   L2CAP_TRACE_* macros compare it with bt_types.h's BT_TRACE_LEVEL_* values
   (1 error, 2 warning, 3 API, 4 event) and hand the message to the LogMsg_N()
   trace functions (fn_8007093C/_954/_96C/_984/_9CC take the number of
   parameters to print, plus the trace code TRACE_CTRL_GENERAL |
   TRACE_LAYER_L2CAP | TRACE_ORG_STACK | TRACE_TYPE_*). */
#define l2cb_trace_level lbl_803C4040[0]
#define l2cb_num_links_active (*(u16 *)(lbl_803C4040 + 0x7B8)) /* LCBs handed out and not released */
#define l2cb_idle_timeout     (*(u16 *)(lbl_803C4040 + 0x7BA)) /* seconds a link may stay idle */

/* The L2CAP link control block, as far as this unit reaches into it (the game
   runs an older stack than l2c_int.h, so only the fields it uses are named). */
typedef struct {
    u8      pad_00[4];
    s32     link_state;     /* +0x04  a LST_* link state */
    void   *p_first_ccb;    /* +0x08  first channel on this link (ccb_queue.p_first_ccb) */
    u8      pad_0C[4];
    TIMER_LIST_ENT timer_entry; /* +0x10  this link's timeout entry (btu_start/stop_timer) */
    u16     handle;         /* +0x28  ACL connection handle, used with the LM */
    u8      remote_bd_addr[6]; /* +0x2A  the peer's Bluetooth address (BD_ADDR) */
    u8      link_role;      /* +0x30  master or slave */
    u8      id;             /* +0x31  identifier of the next command we send */
    u8      pad_32[0xF];
    u8      is_congested;   /* +0x41  set while the link's transmit queue is at or over
                               its quota; channels answer L2CA_DataWrite with CONGESTED */
    u8      pad_42[0x12];
    void   *p_echo_rsp_cb;  /* +0x54  echo response callback, NULL when none is set */
} tL2C_LCB_VIEW;

/* The L2CAP channel state machine states (l2c_int.h's tL2C_CHNL_STATE); the game
   numbers them the same way, so these are the header's names. */
typedef enum {
    CST_CLOSED,                   /* channel is in closed state */
    CST_ORIG_W4_SEC_COMP,         /* originator waits for security clearance */
    CST_TERM_W4_SEC_COMP,         /* acceptor waits for security clearance */
    CST_W4_L2CAP_CONNECT_RSP,     /* waiting for the peer's connect response */
    CST_W4_L2CA_CONNECT_RSP,      /* waiting for the upper layer's connect response */
    CST_CONFIG,                   /* negotiating configuration */
    CST_OPEN,                     /* data transfer state */
    CST_W4_L2CAP_DISCONNECT_RSP,  /* waiting for the peer's disconnect response */
    CST_W4_L2CA_DISCONNECT_RSP    /* waiting for the upper layer's disconnect response */
} tL2C_CHNL_STATE;

/* The registration control block (l2c_int.h's tL2C_RCB): one per PSM an
   application registered with L2CA_Register(), 0x2C bytes each in the pool
   l2cu_register_for_connection hands out, holding the API callbacks L2CAP
   calls back into (their prototypes are l2c_api.h's tL2CA_*_CB). */
typedef struct {
    u8   in_use;                                              /* +0x00 */
    u8   pad_01;
    u16  psm;                                                 /* +0x02  PSM this is registered for */
    void (*pL2CA_ConnectInd_Cb)(u8 *bd_addr, u16 lcid, u16 psm, u8 status);
                                                              /* +0x04  peer wants to connect */
    void (*pL2CA_ConnectCfm_Cb)(u16 lcid, u16 status);        /* +0x08  our connect request done */
    void (*pL2CA_ConnectPnd_Cb)(u16 lcid);                    /* +0x0C  peer's connect still pending */
    void (*pL2CA_ConfigInd_Cb)(u16 lcid, void *p_cfg);        /* +0x10  peer wants to configure */
    void (*pL2CA_ConfigCfm_Cb)(u16 lcid, void *p_cfg);        /* +0x14  our config request done */
    void (*pL2CA_DisconnectInd_Cb)(u16 lcid, u16 need_confirm);
                                                              /* +0x18  channel is going away */
    void (*pL2CA_DisconnectCfm_Cb)(u16 lcid, u16 result);     /* +0x1C  our disconnect done */
    void (*pL2CA_QoSViolationInd_Cb)(u8 *bd_addr);            /* +0x20  link QOS was violated */
    void (*pL2CA_DataInd_Cb)(u16 lcid, void *p_buf);          /* +0x24  data from the peer */
    void (*pL2CA_CongestionStatus_Cb)(u16 lcid, u16 congested);/* +0x28  transmit queue filled up */
} tL2C_RCB_VIEW;

/* The L2CAP channel control block (l2c_int.h's tL2C_CCB); the game lays it out
   the same way, so the names below are the header's. */
typedef struct t_l2c_ccb_view {
    u8              pad_00[4];
    tL2C_CHNL_STATE chnl_state;   /* +0x04  where this channel is in the CSM */
    u8              pad_08[8];
    tL2C_LCB_VIEW  *p_lcb;        /* +0x10  the link this channel is assigned to */
    u16             local_cid;    /* +0x14  our CID on that link */
    u16             remote_cid;   /* +0x16  the peer's CID */
    TIMER_LIST_ENT  timer_entry;  /* +0x18  this channel's timeout entry */
    tL2C_RCB_VIEW  *p_rcb;        /* +0x30  registration control block of the PSM */
    u8              config_done;  /* +0x34  IB_CFG_DONE / OB_CFG_DONE flags */
    u8              local_id;     /* +0x35  identifier of the last command we sent */
    u8              remote_id;    /* +0x36  identifier of the peer's last command */
    u8              pad_37;
    u16             our_mtu;      /* +0x38  MTU our configuration asked for (l2cu_process_our_cfg_req) */
    u16             peer_mtu;     /* +0x3A  MTU the peer's configuration allows us to send
                                     (l2cu_process_peer_cfg_req, clamped to 0x69B) */
} tL2C_CCB_VIEW;

/* Events l2c_csm_execute() (fn_80089E40) feeds the state handlers. This stack
   predates l2c_int.h's L2CEVT_ list: it has no L2CEVT_L2CAP_INFO_RSP and no
   L2CA_FLUSH_REQ, and numbers the security events after the link ones, so the
   values are the game's own. Checked against the senders: the HCI connect
   complete sends 0/1, a link disconnect 3, a QOS violation 6, the peer's
   connect signalling 10..13, a data indication 19, L2CA_ConnectReq 20,
   L2CA_ConfigRsp 24/25, L2CA_DisconnectReq 26, L2CA_DisconnectRsp 27,
   L2CA_DataWrite 29 and l2c_process_timeout 30. */
#define L2CEVT_LP_CONNECT_CFM        0  /* lower layer connect confirm */
#define L2CEVT_LP_CONNECT_CFM_NEG    1  /* lower layer connect confirm (failed) */
#define L2CEVT_LP_DISCONNECT_IND     3  /* link was disconnected */
#define L2CEVT_LP_QOS_VIOLATION_IND  6  /* lower layer QOS violation indication */
#define L2CEVT_L2CAP_CONNECT_REQ     10 /* peer connection request */
#define L2CEVT_L2CAP_CONNECT_RSP     11 /* peer connection response */
#define L2CEVT_L2CAP_CONNECT_RSP_PND 12 /* peer connection response pending */
#define L2CEVT_L2CAP_CONNECT_RSP_NEG 13 /* peer connection response (failed) */
#define L2CEVT_L2CAP_CONFIG_REQ      14 /* peer configuration request */
#define L2CEVT_L2CAP_DISCONNECT_REQ  17 /* peer disconnect request */
#define L2CEVT_L2CAP_DATA            19 /* peer data */
#define L2CEVT_L2CA_CONNECT_REQ      20 /* upper layer connect request */
#define L2CEVT_L2CA_CONNECT_RSP      21 /* upper layer connect response */
#define L2CEVT_L2CA_CONNECT_RSP_NEG  22 /* upper layer connect response (failed) */
#define L2CEVT_L2CA_CONFIG_REQ       23 /* upper layer config request */
#define L2CEVT_L2CA_CONFIG_RSP       24 /* upper layer config response */
#define L2CEVT_L2CA_CONFIG_RSP_NEG   25 /* upper layer config response (failed) */
#define L2CEVT_L2CA_DISCONNECT_REQ   26 /* upper layer disconnect request */
#define L2CEVT_L2CA_DISCONNECT_RSP   27 /* upper layer disconnect response */
#define L2CEVT_L2CA_DATA_WRITE       29 /* upper layer data to send */
#define L2CEVT_TIMEOUT               30 /* channel timeout */

/* The L2CAP link states (l2c_int.h's tL2C_LINK_STATE); the game numbers them
   the same way. p_lcb's +0x04 link_state field holds one of these. */
#define LST_DISCONNECTED             0  /* link control block is free */
#define LST_CONNECT_HOLDING          1  /* waiting for another link to drop */
#define LST_CONNECTING_WAIT_SWITCH   2  /* waiting for a role switch to connect */
#define LST_CONNECTING               3  /* ACL connect request has been sent */
#define LST_CONNECTED                4  /* link is up */
#define LST_DISCONNECTING            5  /* tearing the link down */

/* Link timeouts in seconds passed to btu_start_timer() (l2c_int.h / bt_target.h). */
#define L2CAP_ECHO_RSP_TOUT          30 /* waiting for the peer's echo response */
#define L2CAP_LINK_STARTUP_TOUT      60 /* link left idle right after connecting */

/* Seconds an L2CAP channel waits for the peer; this stack uses 30 both while
   negotiating a configuration and while tearing the channel down. */
#define L2CAP_CHNL_TIMEOUT           30

/* Extra seconds it waits after the peer answered a connect request with
   "pending" (l2c_int.h's L2CAP_CHNL_CONNECT_TOUT_EXT). */
#define L2CAP_CHNL_CONNECT_TOUT_EXT  120

extern void l2c_init(void);
extern char lbl_803181F0[];
extern void fn_80089E40(void *, u8, void *);
extern u8 lbl_803151D8[];
extern char lbl_8031801C[];
extern char lbl_80318040[];
extern char lbl_8031806C[];
extern char lbl_80318090[];
extern void *l2cu_find_lcb_by_bd_addr(u8 *addr);
extern void l2c_link_hci_conn_req(u8 *bd_addr);
extern u8 fn_8008D7C4(void);
extern char lbl_80318BE8[];
extern char lbl_80318C08[];
extern void l2cu_create_conn_after_switch(void *p_lcb);
extern u8 lbl_803130C8[];
extern u8 lbl_80392960[];
extern u8 lbl_803934C0[];
extern u8 lbl_8055DC48;
extern u8 lbl_8055DC49;
extern void fn_8006C00C(s32, void *);
extern s32 fn_80069178(void);
extern s32 fn_800692D0(void);
extern void fn_8006B488(void);
extern int fn_8006B598(void *);
extern void *WUDiGetDevInfo(u8 *);
extern void *WUDiGetNewDevInfo(void);
extern void WUDiMoveTopSmpDevInfoPtr(u8 *, void *);
extern void WUDiMoveBottomSmpDevInfoPtr_8006B98C(void *);
extern void BTA_DmSearch(u8 *, u32, u32);
extern void BTA_HhOpen(const u8 *, s8, s8);
extern tBTM_STATUS BTM_ReadStoredLinkKey(BD_ADDR, tBTM_CMPL_CB *);
extern tBTM_STATUS BTM_WriteStoredLinkKey(UINT8, BD_ADDR *, LINK_KEY *, tBTM_CMPL_CB *);
extern void SCFlushAsync(void *);
extern void fn_80073CA8(void);
extern void WUDStoredLinkKeyCallback(void *);
extern void DBPrintf_8006CFA8(const char *, ...);
extern u8 lbl_80393058[];
extern char lbl_80313238[];
extern u8 lbl_803C0D48[];
extern u8 lbl_803C3C38[];
extern u8 HID_HostWriteDev(u8 dev_handle, u8 t_type, u8 param, u16 data, u8 report_id, BT_HDR *pbuf);
extern u8 hidh_conn_snd_data(u8 dev_handle, s32 trans_type, u8 param, u16 data, u8 report_id, BT_HDR *buf);
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

/* tSDP_RECORD as this build lays it out: SDP_MAX_PAD_LEN is 350 here, not the 600
   bt_target.h gives the header's tSDP_RECORD, so a record is 0x298 bytes - 0x10 of
   header, SDP_MAX_REC_ATTR attributes and the value pool at 0x138. */
#define SDP_BUILD_MAX_PAD_LEN   350

typedef struct {
    UINT32          record_handle;
    UINT32          free_pad_ptr;
    UINT16          num_attributes;
    tSDP_ATTRIBUTE  attribute[SDP_MAX_REC_ATTR];
    UINT8           attr_pad[SDP_BUILD_MAX_PAD_LEN];
} tSDP_RECORD_BUILD_VIEW;                 /* 0x298 */

/* tSDP_DB with those records: the server database as this build lays it out,
   num_records at +6 and record[] at +8. */
typedef struct {
    UINT32                  di_primary_handle;
    UINT8                   brcm_di_registered;
    UINT16                  num_records;
    tSDP_RECORD_BUILD_VIEW  record[SDP_MAX_RECORDS];
} tSDP_DB_BUILD_VIEW;
#define sdp_cb_server_db_view   ((tSDP_DB_BUILD_VIEW *)(lbl_803C4C40 + 0x121C))

/* lbl_803C4C40 is the SDP control block (tSDP_CB of stack/sdp/sdpint.h).  Its
   server database starts at 0x121C - di_primary_handle, brcm_di_registered at
   0x1220, num_records at 0x1222 and record[] at 0x1224 - and sdp_cb.trace_level
   is at 0x4630.  The header's tSDP_DB only serves for the first three fields;
   its record[] is followed by the wrong-sized records. */
#define sdp_cb_server_db        ((tSDP_DB *)(lbl_803C4C40 + 0x121C))
/* sdp_cb.server_db.num_records.  Reading it through tSDP_DB schedules the record
   pointer's setup differently, so the server-database loops count with this. */
#define sdp_cb_num_records      (*(UINT16 *)(lbl_803C4C40 + 0x1222))
#define sdp_cb_record_db        ((tSDP_RECORD_BUILD_VIEW *)(lbl_803C4C40 + 0x1224))
#define sdp_cb_trace_level      (lbl_803C4C40[0x4630])
#define sdp_cb_max_attr_list_size   (*(UINT16 *)(lbl_803C4C40 + 0x462C))

/* sdp_utils.c's sdpu_find_ccb_by_cid(): looks an SDP connection up in sdp_cb.ccb[]
   (SDP_MAX_CONNECTIONS blocks of 0x478 at sdp_cb + 0x3C) by its L2CAP CID.  It is
   not the L2CAP l2cu_find_lcb_by_handle() its symbol suggests, but this project
   cannot rename the game's symbol, so the source uses the SDK name through this. */
#define sdpu_find_ccb_by_cid sdpu_find_ccb_by_cid_80099E54
extern tCONN_CB *sdpu_find_ccb_by_cid_80099E54(UINT16 cid);

typedef struct { UINT8 pad[0x476]; UINT16 cont_offset; } tSDP_CCB_CONT_VIEW;
static void process_service_attr_rsp(tCONN_CB *, UINT8 *, UINT16);
typedef struct { UINT8 pad[0x418]; UINT32 handles[0x15]; } tSDP_CCB_HANDLE_VIEW;
typedef struct {
    UINT8 pad_0x000[0x418];
    UINT32 handles[0x15];
    UINT16 num_handles;
    UINT8 pad_0x46E[6];
    UINT8 disc_state;
} tCONN_CB_SEARCH_VIEW;
/* tCONN_CB as this build lays it out: the response list is stored inline at 0x26
   (its SDP_MAX_LIST_BYTE_COUNT is 1000 here, not the 4096 of bt_target.h) where
   sdpint.h declares "UINT8 *rsp_list", so every field after it moves: p_db at
   0x410, transaction_id at 0x470.  Fields before 0x26 are still the header's. */
#define SDP_BUILD_MAX_LIST_BYTE_COUNT 1000
#define SDP_CCB_RSP_LIST_OFFSET       0x26
typedef struct {
    UINT8               pad_0x000[0x22];
    UINT16              connection_id;                            /* 0x22 */
    UINT16              list_len;                                 /* 0x24 */
    UINT8               rsp_list[SDP_BUILD_MAX_LIST_BYTE_COUNT];  /* 0x26 */
    UINT8               pad_0x40E[2];
    tSDP_DISCOVERY_DB  *p_db;                                     /* 0x410 */
    UINT8               pad_0x414[4];
    UINT32              handles[SDP_MAX_DISC_SERVER_RECS];        /* 0x418 */
    UINT16              num_handles;                              /* 0x46C */
    UINT16              cur_handle;                               /* 0x46E */
    UINT16              transaction_id;                           /* 0x470 */
} tCONN_CB_ATTR_VIEW;
typedef struct { UINT8 pad[0x24]; UINT16 list_len; UINT8 list_data[1]; } tSDP_CCB_RAW_LIST_VIEW;
extern char lbl_80317A54[];
extern char lbl_80317A80[];
#include "revolution/BTE/stack/include/wbt_api.h"
extern void AXFXReverbHiExpShutdown(void*);
BOOL AXFXReverbHiExpInit(void*);
extern void __FreeDelayLine(void*);
typedef struct AXFX_BUFFERUPDATE_VIEW {
    s32 *left;
    s32 *right;
    s32 *surround;
} AXFX_BUFFERUPDATE_VIEW;

typedef struct AXFX_BUS_VIEW {
    s32 *left;
    s32 *right;
    s32 *surround;
} AXFX_BUS_VIEW;

typedef struct AXFX_REVERBHI_EXP_VIEW {
    f32 *earlyLine[3];             /* 0x00 */
    u32 earlyPos[3];               /* 0x0C */
    u32 earlyLength;               /* 0x18 */
    u32 earlyMaxLength;            /* 0x1C */
    f32 earlyCoef[3];              /* 0x20 */
    f32 *preDelayLine[3];          /* 0x2C */
    u32 preDelayPos;               /* 0x38 */
    u32 preDelayLength;            /* 0x3C */
    u32 preDelayMaxLength;         /* 0x40 */
    f32 *combLine[3][3];           /* 0x44 */
    u32 combPos[3];                /* 0x68 */
    u32 combLength[3];             /* 0x74 */
    u32 combMaxLength[3];          /* 0x80 */
    f32 combCoef[3];               /* 0x8C */
    f32 *allpassLine[3][2];        /* 0x98 */
    u32 allpassPos[2];             /* 0xB0 */
    u32 allpassLength[2];          /* 0xB8 */
    u32 allpassMaxLength[2];       /* 0xC0 */
    f32 *lastAllpassLine[3];       /* 0xC8 */
    u32 lastAllpassPos[3];         /* 0xD4 */
    u32 lastAllpassLength[3];      /* 0xE0 */
    u32 lastAllpassMaxLength[3];   /* 0xEC */
    f32 allpassCoef;               /* 0xF8 */
    f32 lastLpfOut[3];             /* 0xFC */
    f32 lpfCoef;                   /* 0x108 */
    u32 active;                    /* 0x10C */
    u32 earlyMode;                 /* 0x110 */
    f32 preDelayTimeMax;           /* 0x114 */
    f32 preDelayTime;              /* 0x118 */
    u32 fusedMode;                 /* 0x11C */
    f32 fusedTime;                 /* 0x120 */
    f32 coloration;                /* 0x124 */
    f32 damping;                   /* 0x128 */
    f32 crosstalk;                 /* 0x12C */
    f32 earlyGain;                 /* 0x130 */
    f32 fusedGain;                 /* 0x134 */
    AXFX_BUS_VIEW *busIn;          /* 0x138 */
    AXFX_BUS_VIEW *busOut;         /* 0x13C */
    f32 outGain;                   /* 0x140 */
    f32 sendGain;                  /* 0x144 */
} AXFX_REVERBHI_EXP_VIEW;

extern void AXFXReverbHiExpCallback();
extern u8 lbl_8031ABD8[];
extern f32 lbl_80560D58;
extern f32 lbl_80560D5C;
extern f32 lbl_80560D60;
extern f32 lbl_80560D64;
extern f32 lbl_80560D78;
extern f64 lbl_80560D80;
extern f32 lbl_80560D88;
extern f64 lbl_80560D90;
extern u8 lbl_8031AC98[];
extern f32 lbl_80560D50;
extern f32 lbl_80560D54;
extern u32 lbl_80560D28;

typedef struct {
    void *earlyLine[3];
    u32 earlyPos[3];
    u32 earlyLength;
    u32 earlyMaxLength;
    f32 earlyCoef[3];
    void *preDelayLine[3];
    u32 preDelayPos;
    u32 preDelayLength;
    u32 preDelayMaxLength;
    void *combLine[3][3];
    u32 combPos[3];
    u32 combLength[3];
    u32 combMaxLength[3];
    f32 combCoef[3];
    void *allpassLine[3][2];
    u32 allpassPos[2];
    u32 allpassLength[2];
    u32 allpassMaxLength[2];
    void *lastAllpassLine[3];
    u32 lastAllpassPos[3];
    u32 lastAllpassLength[3];
    u32 lastAllpassMaxLength[3];
} AXFX_REVERBHI_EXP_FREE_VIEW;

extern u8 lbl_803C0F78[];
extern char lbl_803164B8[];
__declspec(section ".sdata") extern u8 lbl_80560D30[];
__declspec(section ".sdata") extern u8 lbl_80560D34[];
extern u8 lbl_80316570[];
extern void fn_80072AE4(u8 *, u8 *, u8 *);
extern void bta_dm_disc_remname_cback(u8 *);
extern void bta_dm_find_services(u8 *);
extern u16 lbl_802EE990[];
void *fn_80095C64(void **head, u32 attr);
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
extern void port_rfc_closed(struct t_port_info *, u8);
extern void rfc_inc_credit(struct t_port_info *, u8);
extern void rfc_send_fcon(void *, s32, void *);
extern void rfc_send_fcon_80093FDC(void *, s32);
extern void PORT_FlowInd(void *, s32, s32);
extern void PORT_LineStatusInd(void *, u8, u8);
extern u32 port_rfc_send_tx_data(void *);
extern void rfc_process_l2cap_congestion(void *, s32);
extern void *port_find_mcb_dlci_port(void *mcb, u8 dlci);
extern void rfc_port_timer_stop(void *);
extern void rfc_timer_stop(void *);
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
extern s32 IUSB_OpenLib(void);
extern s32 uusb_get_devId(u32 arg0, u32 arg1);
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

extern u8 lbl_80393028[];
#pragma use_lmw_stmw off
u8 fn_80068F94(void) { /* v6 */
    BOOL interrupts;
    u8 state;
    u8 state2;
    u8 *base = lbl_80392960;
    if ((s8)base[0x668] == 0) return 0xE;
    interrupts = OSDisableInterrupts();
    state = base[0x665];
    OSRestoreInterrupts(interrupts);
    if (state == 4) {
        interrupts = OSDisableInterrupts();
        state2 = base[0x664];
        OSRestoreInterrupts(interrupts);
        if (state2 == 4) return 0xE;
    }
    if (base[0x667] != 0) {
        u8 *scan_base;
        u8 *record;
        s32 i;
        s32 offset;
        offset = 0;
        record = lbl_80392960;
        i = 0;
    loop:
        interrupts = OSDisableInterrupts();
        if (offset < 0) goto high_record;
        if (offset >= 0xA) goto high_record;
        scan_base = record + i + 0x64;
        goto selected_record;
    high_record:
        scan_base = record + (((u8)offset - 0xA) * 0x60) + 0x424;
    selected_record:
        OSRestoreInterrupts(interrupts);
        if (scan_base[0x59] == 9) {
            tBTM_PM_PWR_MD mode;
            mode.mode = 0;
            mode.max = 0;
            mode.min = 0;
            mode.attempt = 1;
            mode.timeout = 0;
            BTM_SetPowerMode(lbl_80392960[0x68A], scan_base + 0x40, &mode);
            return 1;
        }
        offset++;
        i += 0x60;
        if (offset < 0x10) goto loop;
    }
    if ((s8)base[0x668] > 0) base[0x668]--;
    if ((s8)base[0x668] == -1) {
        u8 timer_state;
        s32 interval;
        ((s8 *)base)[0x668] = -2;
        interrupts = OSDisableInterrupts();
        timer_state = lbl_80392960[0x665];
        OSRestoreInterrupts(interrupts);
        interval = 2;
        if (timer_state == 3) interval = 4;
        interrupts = OSDisableInterrupts();
        timer_state = lbl_80392960[0x665];
        OSRestoreInterrupts(interrupts);
        if (timer_state == 4) {
            interrupts = OSDisableInterrupts();
            state2 = lbl_80392960[0x664];
            OSRestoreInterrupts(interrupts);
            if (state2 == 4) lbl_80392960[0xC] = 0xE;
        }
        OSCreateAlarm((OSAlarm *)lbl_80393028);
        OSSetAlarm((OSAlarm *)lbl_80393028, (s64)(interval * ((*(u32 *)0x800000F8) >> 2)), (OSAlarmHandler)fn_80068F80);
        return 0x18;
    }
    return 2;
}
#pragma use_lmw_stmw on
s32 fn_80069178(void) {
    s32 status;
    BOOL interrupts;
    register u8 *device_info;
    register const u8 *record;
    register u8 count;
    register s32 index;

    status = SCCheckStatus();
    if (((u32)((1 - status) | (status - 1)) >> 31) == 0) {
        return 0x16;
    }

    memset(lbl_80393058 + 1, 0, 0x2BC);

    interrupts = OSDisableInterrupts();
    device_info = lbl_80392960;
    index = device_info[0x12];
    OSRestoreInterrupts(interrupts);
    lbl_80393058[0] = (u8)index;

    index = 0;
    count = 0;
    do {
        interrupts = OSDisableInterrupts();
        if (index < 0) goto high_record;
        if (index >= 0xA) goto high_record;
        record = device_info + (u8)index * 0x60 + 0x64;
        goto selected_record;
    high_record:
        record = device_info + ((u8)index - 0xA) * 0x60 + 0x424;
    selected_record:
        OSRestoreInterrupts(interrupts);

        if (record[0x59] != 0) {
            if (record[0x5B] == 0 || record[0x5B] == 2 || record[0x5B] == 4) {
                memcpy(lbl_80393058 + (u8)count * 0x46 + 1, record + 0x40, 6);
                memcpy(lbl_80393058 + (u8)count * 0x46 + 7, record, 0x40);
                count++;
            }
        }
        index++;
    } while ((u32)index < 0xA);

    DBPrintf_8006CFA8(lbl_80313238, count);
    if (SCSetBtDeviceInfoArray(lbl_80393058) != 0) {
        return 0x19;
    }
    return 0x16;
}
#pragma use_lmw_stmw reset
s32 fn_800692D0(void) {
    u8 *record;
    u8 *offset;
    u8 *base = lbl_80392960;
    s32 i;
    s32 interruptState;
    tBTM_PM_PWR_MD mode;
    s32 callback;

    if (base[0x667] != 0) {
        i = 0;
        offset = (u8 *)0;
        while (i < 0x10) {
            interruptState = OSDisableInterrupts();
            if (i < 0) goto high_record;
            if (i >= 0xA) goto high_record;
            record = (u8 *)((u32)base + (u32)offset + 0x64);
            goto selected_record;
        high_record:
            record = (u8 *)((u32)base + ((u32)(i - 0xA) * 0x60u) + 0x424);
        selected_record:
            OSRestoreInterrupts(interruptState);
            if (record[0x59] == 8) {
                mode.mode = 2;
                mode.max = 8;
                mode.min = 8;
                mode.attempt = 1;
                mode.timeout = 0;
                BTM_SetPowerMode(lbl_80392960[0x68A], record + 0x40, &mode);
                return 0xE;
            }
            i++;
            offset += 0x60;
        }
    }

    OSCancelAlarm((OSAlarm *)(base + 0x690));
    if (base[0x669] == 0) {
        callback = *(s32 *)(base + 0);
    } else {
        callback = *(s32 *)(base + 4);
    }
    if (callback != 0) {
        ((void (*)(u8, u8))callback)(1, base[0x666]);
    }
    DBPrintf_8006CFA8(lbl_80313258);
    return 0;
}

void fn_80069408(void) {
    u8 *base = lbl_80392960;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    u8 sp30[0x30];
    switch (base[0xC]) {
    case 1:
        base[0xC] = fn_80068F94();
        return;
    case 2: {
        BOOL interrupts;
        u8 timer_state;
        sp30[0] = 1;
        sp30[2] = 1;
        sp30[3] = 0;
        if (base[0x667] != 0) {
            sp30[1] = 3;
        } else if (base[0x669] == 0) {
            interrupts = OSDisableInterrupts();
            timer_state = base[0x665];
            OSRestoreInterrupts(interrupts);
            if (timer_state == 3) {
                sp30[1] = 0xA - base[0x668];
            } else {
                sp30[1] = 5 - base[0x668];
            }
        } else {
            interrupts = OSDisableInterrupts();
            timer_state = base[0x665];
            OSRestoreInterrupts(interrupts);
            if (timer_state == 3) {
                sp30[1] = 8;
            } else {
                sp30[1] = 3;
            }
        }
        lbl_8055DC49 = 0;
        memset(base + 0xB60, 0, 0x108);
        BTA_DmSearch(sp30, 0, (u32)fn_8006C00C);
        base[0xC] = 3;
        return;
    }
    case 4: {
        u8 result = 1;
        if (lbl_8055DC49 != 0) {
            if (memcmp(base + 0xB60 + 6, lbl_803130C8 + 0x1A0, 0x10) == 0 && (s8)lbl_8055DC48 > (s8)base[0x68B]) {
                result = 5;
            }
        } else {
            BOOL interrupts;
            u8 timer_state;
            s32 interval = 2;
            interrupts = OSDisableInterrupts();
            timer_state = base[0x665];
            OSRestoreInterrupts(interrupts);
            if (timer_state == 3) interval = 4;
            interrupts = OSDisableInterrupts();
            timer_state = base[0x665];
            OSRestoreInterrupts(interrupts);
            if (timer_state == 4) {
                interrupts = OSDisableInterrupts();
                timer_state = base[0x664];
                OSRestoreInterrupts(interrupts);
                if (timer_state == 4) base[0xC] = 0xE;
            }
            OSCreateAlarm((OSAlarm *)(base + 0x6C8));
            OSSetAlarm((OSAlarm *)(base + 0x6C8), (s64)(interval * ((*(u32 *)0x800000F8) >> 2)), (OSAlarmHandler)fn_80068F80);
            result = 0x18;
        }
        base[0xC] = result;
        return;
    }
    case 5: {
        u8 result = 0x11;
        void *info = WUDiGetDevInfo(base + 0xB60);
        if (info != 0) {
            memcpy(base + 0xC68, info, 0x60);
            result = 0x10;
        }
        base[0xC] = result;
        return;
    }
    case 0x10: {
        u8 *info = base + 0xC68;
        u8 v = info[0x5B];
        info[0x59] = 1;
        if (v == 2 || v == 0 || (v >= 4 && v < 6)) {
            if (base[0x669] == 0) {
                fn_8006B598(info + 0x40);
                base[0xC] = 0x11;
            } else {
                info[0x5B] = 4;
                base[0xC] = 0xF;
            }
        } else {
            WUDiMoveBottomSmpDevInfoPtr_8006B98C(info);
            fn_8006B598(*(u8 **)(base + 0x18) + 0x40);
            base[0xC] = 0x11;
        }
        return;
    }
    case 0x11: {
        u8 *info = base + 0xC68;
        info[0x59] = 1;
        info[0x5B] = (base[0x669] != 0);
        memcpy(info + 0x40, base + 0xB60, 6);
        memcpy(info, base + 0xB60 + 6, 0x40);
        memset(info + 0x46, 0, 0x10);
        base[0xC] = 0xF;
        return;
    }
    case 0xF: {
        u8 result = 0xFF;
        if (memcmp(base + 0xB60 + 6, lbl_803130C8 + 0x1A0, 0x10) == 0) {
            u8 *info = base + 0xC68;
            info[0x59] = 2;
            BTA_HhOpen(info + 0x40, 0, 0x12);
            result = 6;
        }
        base[0xC] = result;
        return;
    }
    case 0x12: {
        u8 v = *(base + 0xC68 + 0x5B);
        u8 result = v;
        switch (v) {
        case 1: result = 0x13; break;
        case 0: result = 0x14; break;
        case 5: result = 0x15; break;
        case 3: result = 0x17; break;
        case 4: result = 7; break;
        case 2: result = 7; break;
        }
        base[0xC] = result;
        return;
    }
    case 0x13: {
        BOOL interrupts;
        u8 v;
        interrupts = OSDisableInterrupts();
        v = base[0x13];
        OSRestoreInterrupts(interrupts);
        if (v == 6) {
            fn_8006B598(*(u8 **)(base + 0x18) + 0x40);
        }
        {
            void *info = WUDiGetNewDevInfo();
            memcpy(info, base + 0xC68, 0x60);
            ((void (*)(void *))fn_8006B488)((u8 *)info + 0x40);
            ((void (*)(u8 *))WUDiMoveTopSmpDevInfoPtr)(info);
            base[0xC] = 0x17;
            *(void **)(base + 0xCC8 + ((u8 *)info)[0x56] * 4) = (u8 *)info + 0x40;
        }
        return;
    }
    case 0x14: {
        BOOL interrupts;
        u8 v;
        interrupts = OSDisableInterrupts();
        v = base[0x12];
        OSRestoreInterrupts(interrupts);
        if (v == 0xA) {
            base[0xE] = 1;
            BTM_ReadStoredLinkKey(NULL, WUDStoredLinkKeyCallback);
            base[0xC] = 0xA;
        } else {
            void *info = WUDiGetNewDevInfo();
            memcpy(info, base + 0xC68, 0x60);
            ((void (*)(void *))fn_8006B488)((u8 *)info + 0x40);
            base[0xC] = 7;
            *(void **)(base + 0xCC8 + ((u8 *)info)[0x56] * 4) = (u8 *)info + 0x40;
        }
        return;
    }
    case 0x15: {
        WUDiMoveBottomSmpDevInfoPtr_8006B98C(base + 0xC68);
        fn_8006B598(*(u8 **)(base + 0x18) + 0x40);
        {
            BOOL interrupts;
            u8 v;
            interrupts = OSDisableInterrupts();
            v = base[0x12];
            OSRestoreInterrupts(interrupts);
            if (v == 0xA) {
                base[0xE] = 1;
                BTM_ReadStoredLinkKey(NULL, WUDStoredLinkKeyCallback);
                base[0xC] = 0xA;
            } else {
                void *info = WUDiGetNewDevInfo();
                memcpy(info, base + 0xC68, 0x60);
                ((void (*)(void *))fn_8006B488)((u8 *)info + 0x40);
                base[0xC] = 7;
                *(void **)(base + 0xCC8 + ((u8 *)info)[0x56] * 4) = (u8 *)info + 0x40;
            }
        }
        return;
    }
    case 7: {
        if (base[0xE] != 0) {
            base[0xC] = 7;
        } else {
            void *info = WUDiGetDevInfo(base + 0xC68 + 0x40);
            DBPrintf_8006CFA8((const char *)(lbl_803130C8 + 0x1B4));
            DBPrintf_8006CFA8((const char *)(lbl_803130C8 + 0x1CC), ((u8 *)info)[0x40], ((u8 *)info)[0x41], ((u8 *)info)[0x42], ((u8 *)info)[0x43], ((u8 *)info)[0x44], ((u8 *)info)[0x45]);
            sp8 = ((u8 *)info)[0x4D];
            spC = ((u8 *)info)[0x4E];
            sp10 = ((u8 *)info)[0x4F];
            sp14 = ((u8 *)info)[0x50];
            sp18 = ((u8 *)info)[0x51];
            sp1C = ((u8 *)info)[0x52];
            sp20 = ((u8 *)info)[0x53];
            sp24 = ((u8 *)info)[0x54];
            sp28 = ((u8 *)info)[0x55];
            DBPrintf_8006CFA8((const char *)(lbl_803130C8 + 0x1F8), ((u8 *)info)[0x46], ((u8 *)info)[0x47], ((u8 *)info)[0x48], ((u8 *)info)[0x49], ((u8 *)info)[0x4A], ((u8 *)info)[0x4B], ((u8 *)info)[0x4C]);
            base[0xE] = 2;
            BTM_WriteStoredLinkKey(1, (BD_ADDR *)((u8 *)info + 0x40), (LINK_KEY *)((u8 *)info + 0x46), WUDStoredLinkKeyCallback);
            base[0xC] = 8;
        }
        return;
    }
    case 8: {
        if (base[0xE] == 0) {
            base[0xC] = 0x16;
        } else {
            base[0xC] = 8;
        }
        return;
    }
    case 0x16:
        base[0xC] = fn_80069178();
        return;
    case 0x19: {
        BOOL interrupts;
        interrupts = OSDisableInterrupts();
        base[0xC] = 0xD;
        OSRestoreInterrupts(interrupts);
        SCFlushAsync(SyncFlushCallback);
        return;
    }
    case 0xA: {
        if (base[0xE] == 0) {
            fn_8006B598(base + 0x67C);
            base[0xC] = 0x14;
        } else {
            base[0xC] = 0xA;
        }
        return;
    }
    case 0x17: {
        u8 *info = base + 0xC68;
        u8 count = base[0x666];
        base[0x666] = count + 1;
        memset(info, 0, 0x60);
        if (base[0x669] == 0) {
            base[0xC] = 0xE;
        } else {
            base[0xC] = 1;
        }
        return;
    }
    case 0xFF: {
        memset(base + 0xC68, 0, 0x60);
        if (base[0x669] == 0) {
            base[0xC] = 0xE;
        } else {
            base[0xC] = 1;
        }
        return;
    }
    case 0xE:
        base[0xC] = fn_800692D0();
        return;
    case 3: {
        BOOL interrupts;
        u8 v;
        interrupts = OSDisableInterrupts();
        v = base[0x665];
        OSRestoreInterrupts(interrupts);
        if (v == 4) {
            interrupts = OSDisableInterrupts();
            v = base[0x664];
            OSRestoreInterrupts(interrupts);
            if (v == 4) {
                DBPrintf_8006CFA8((const char *)(lbl_803130C8 + 0x250));
                fn_80073CA8();
                base[0xC] = 0x1A;
                return;
            }
        }
        base[0xC] = 3;
        return;
    }
    default:
        DBPrintf_8006CFA8((const char *)(lbl_803130C8 + 0x280));
        return;
    }
}

extern u8 lbl_80393680[];
extern void fn_80069408(void);
extern void fn_80069D80(void);
void fn_80069C14(u32 r3, u32 r4) {
    OSSwitchFiberEx(r3, r4, 0, 0, fn_80069408, (u8*)&lbl_80393680 + 0x1000);
}

/* --- WUD paired-device database -------------------------------------------------
   One of the device records the WUD control block keeps, as this build lays it out
   (0x60 bytes; same fields and offsets as the SDK's WUDDevInfo in
   include/revolution/WUD/WUD.h, which needs SCDevInfo, so it is repeated here). */
typedef struct {
    u8 conf[0x40];  /* SCDevInfo: device name, class of device, ... */
    u8 devAddr[6];  /* 0x40: BD_ADDR */
    u8 linkKey[16]; /* 0x46: LINK_KEY */
    u8 devHandle;   /* 0x56: HID device handle */
    u8 subclass;    /* 0x57 */
    u8 appID;       /* 0x58 */
    u8 status;      /* 0x59: 0 = free, 1 = registered, >1 while a link is up */
    u8 flags[4];    /* 0x5A: link-key/registration flags */
    u16 hhAttrMask; /* 0x5E: tBTA_HH_ATTR_MASK, the HID attributes read from the device */
} WUDDevInfoSlot;

/* The WUD control block (lbl_80392960, the SDK's "WUDCB _wcb").  This build has no
   stdList[] array, so from the device records on everything sits 0x80 below the
   layout in include/revolution/WUD/WUDInternal.h. */
typedef struct {
    u8 pad0[0x64];
    WUDDevInfoSlot stdDevs[10]; /* WUD_MAX_DEV_ENTRY_FOR_STD standard-pairing devices */
    WUDDevInfoSlot smpDevs[6];  /* WUD_MAX_DEV_ENTRY_FOR_SMP simple-pairing devices */
    u8 connectedNum;            /* 0x664: devices HID is talking to */
    u8 linkedNum;               /* 0x665: devices with a link up */
} WUDCBView;

/* include/revolution/WUD/WUDInternal.h's WUDDeleteState; spelled out here because this
   unit does not include the WUD headers. */
#define WUD_STATE_DELETE_CLEANUP_DATABASE 3
#define WUD_STATE_DELETE_CLEANUP_SETTING 5
#define WUDiRemoveDevice fn_8006B598 /* drops a paired device given its BD_ADDR */

#pragma push
#pragma dont_inline on
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
#pragma pop

/* One step of WUD's "delete all devices" state machine: while any device still has a link
   up there is nothing to remove yet, so stay in this state; once every link is down, drop
   every paired device record (the 10 standard slots, then the 6 simple-pairing ones) that
   is registered, and move on to wiping the stored settings. */
s32 WUDiDeleteDevice(void)
{
    u8 linkedNum;
    WUDDevInfoSlot *dev;
    s32 i;
    s32 j;
    WUDDevInfoSlot *dev2;
    u32 interrupt_state;
    register WUDCBView *base = (WUDCBView *)lbl_80392960;

    interrupt_state = OSDisableInterrupts();
    linkedNum = base->linkedNum;
    OSRestoreInterrupts(interrupt_state);
    if (linkedNum != 0)
        return WUD_STATE_DELETE_CLEANUP_DATABASE;

    for (i = 0, dev = base->stdDevs; i < 10; i++, dev++) {
        if (dev->status == 1)
            WUDiRemoveDevice(dev->devAddr);
    }
    for (j = 0, dev2 = base->smpDevs; j < 6; j++, dev2++) {
        if (dev2->status == 1)
            WUDiRemoveDevice(dev2->devAddr);
    }
    return WUD_STATE_DELETE_CLEANUP_SETTING;
}

void fn_80069D80(void) {
    /* Advances the WUD device-delete state machine (lbl_80392960 control block, state at +0xD): clears busy flag (+0xC), steps through visibility off, terminate/delete, SC BT device-info flush, then restores visibility and invokes the completion callback (+8). */
    extern s32 WUDiDeleteDevice(void);
    extern s32 SCCheckStatus(void);
    extern s32 SCSetBtDeviceInfoArray(void *);
    extern void SCFlushAsync(void *);
    extern void OSCancelAlarm(OSAlarm *);
    extern u8 lbl_80393058[];
    u8 connectable;
    u8 *wud = lbl_80392960;
    u8 deleteState = wud[0xD];
    void (*completionCallback)(u32);
    wud[0xC] = 0;
    switch (deleteState) {
    case 1:
        BTA_DmSetVisibility(0, 0);
        wud[0xD] = 2;
        break;
    case 2:
        wud[0xD] = WUDiTerminateDevice();
        break;
    case 3:
        wud[0xD] = WUDiDeleteDevice();
        break;
    case 5:
        if (SCCheckStatus() != 0) break;
        memset(lbl_80393058, 0, 0x461);
        if (SCSetBtDeviceInfoArray(lbl_80393058) != 0) {
            wud[0xD] = 6;
            SCFlushAsync(DeleteFlushCallback);
        }
        break;
    case 8: {
        BOOL enabled = OSDisableInterrupts();
        connectable = wud[0x66A];
        OSRestoreInterrupts(enabled);
        enabled = OSDisableInterrupts();
        wud[0x66B] = 0;
        wud[0x66A] = connectable;
        OSRestoreInterrupts(enabled);
        BTA_DmSetVisibility(0, connectable);
        OSCancelAlarm((OSAlarm *)(wud + 0x690));
        completionCallback = *(void (**)(u32))(wud + 8);
        wud[0xD] = 0;
        if (completionCallback != 0) {
            completionCallback(1);
        }
        wud[0xD] = 0;
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
    u32 offset;
    s32 index;
    u8 *base;
    u8 *entry;
    void *info;

    if (lbl_80392960[0xE] == 0) {
        base = lbl_80392960;
        index = 0;
        offset = 0;
        while (index < 0x10) {
            s32 interrupt = OSDisableInterrupts();
            if (index >= 0 && index < 10)
                entry = base + offset + 0x64;
            else
                entry = base + (index - 10) * 0x60 + 0x424;
            OSRestoreInterrupts(interrupt);
            if (entry[0x59] != 0) {
                if (entry[0x5C] == 1) {
                    base[0xE] = 3;
                    BTM_DeleteStoredLinkKey(entry + 0x40, WUDStoredLinkKeyCallback);
                    entry[0x5C] = 0;
                    return 2;
                }
                if (entry[0x5C] != 3) {
                    info = WUDiGetDevInfo(entry + 0x40);
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
    return 2;
}

void fn_80069FE8(void)
{
    extern u8 lbl_8055DC38;
    extern u8 lbl_803135C0[];
    extern u32 lbl_8055DC3C;
    extern u32 lbl_8055DC44;
    extern void fn_8006AED4(s32);
    extern tBTM_STATUS fn_8007A2C8(u16 *);
    u8 *base = lbl_80392960;
    u8 *strings = lbl_803130C8;
    u8 version[10];
    u8 state;

    switch (base[0xF]) {
    case 1:
        if (*(u32 *)(base + 0x6C0) == 1) {
            base[0xE] = 1;
            BTM_ReadStoredLinkKey(NULL, WUDStoredLinkKeyCallback);
        }
        base[0xF] = 2;
        break;
    case 2:
        base[0xF] = WUDiClearUnregisteredDevice();
        break;
    case 3:
        if (base[0xE] == 0) {
            OSCancelAlarm((OSAlarm *)(base + 0x690));
            fn_8007A2C8((u16 *)version);
            DBPrintf_8006CFA8((const char *)(strings + 0x2C0), version[0]);
            DBPrintf_8006CFA8((const char *)(strings + 0x2D8), *(u16 *)(version + 2));
            DBPrintf_8006CFA8((const char *)(strings + 0x2F0), version[4]);
            DBPrintf_8006CFA8((const char *)(strings + 0x308), *(u16 *)(version + 8));
            DBPrintf_8006CFA8((const char *)(strings + 0x320), *(u16 *)(version + 6));
            DBPrintf_8006CFA8((const char *)(strings + 0x338), *(u16 *)(version + 2) & 0xFFF);

            if ((*(u16 *)(version + 2) & 0xFFF) == 0xA7) {
                volatile u8 *addr = lbl_803135C0;
                u32 first, second, byte;
                DBPrintf_8006CFA8((const char *)(strings + 0x360));
                first = addr[3];
                second = addr[7];
                byte = addr[2];
                first = (first << 8) + byte;
                byte = addr[6];
                second = (second << 8) + byte;
                byte = addr[1];
                first = (first << 8) + byte;
                byte = addr[5];
                second = (second << 8) + byte;
                byte = *(volatile u8 *)&lbl_803135C0[0];
                first = (first << 8) + byte;
                byte = addr[4];
                second = (second << 8) + byte;
                lbl_8055DC3C = first;
                lbl_8055DC44 = second;
                BTM_VendorSpecificCommand(0xFC4F, 1, &lbl_8055DC38, (tBTM_VSC_CMPL_CB *)fn_8006AED4);
            } else {
                fn_8006B330();
            }
            state = 4;
        } else {
            state = 2;
        }
        base[0xF] = state;
        break;
    }
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

#pragma use_lmw_stmw off
u8 fn_8006A1DC(void) {
    char *strings = (char *)lbl_803130C8;
    u8 *entry;
    u8 *addr;
    s32 i;
    u8 *dev;
    u8 one = 1;
    u8 zero = 0;
    u8 two = 2;
    u32 value = 0x10000;
    u8 three = 3;
    u8 b40 = 0;
    memset(lbl_80393058, 0, 0x461);
    SCGetBtDeviceInfoArray(lbl_80393058);
    entry = lbl_80393058 + 1;
    addr = lbl_80393058 + 7;
    i = 0;
    while (i < lbl_80393058[0]) {
        dev = WUDiGetNewDevInfo();
        memcpy(dev + 0x40, entry, 6);
        memcpy(dev, addr, 0x40);
        dev[0x59] = one;
        dev[0x5B] = zero;
        dev[0x5C] = two;
        if (memcmp(dev, strings + 0x37C, 0x13) == 0) {
            dev[0x57] = two;
            *(u16 *)(dev + 0x5E) = value - 0x7F8C;
            dev[0x58] = three;
            b40 = dev[0x40];
            DBPrintf_8006CFA8(strings + 0x1CC, b40, dev[0x41], dev[0x42], dev[0x43], dev[0x44], dev[0x45]);
            DBPrintf_8006CFA8(strings + 0x390, dev);
        }
        entry += 0x46;
        addr += 0x46;
        i++;
    }
    return 3;
}
#pragma use_lmw_stmw reset
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
    register u32 var_r10;
    void *var_r0;
    void *var_r0_2;
    void *var_r0_3;
    void *var_r0_4;
    u8 *base;
    u8 *setup;
    u32 *words;
    u16 *shorts1;
    u16 *shorts2;
    s32 init_zero = 0;
    register s32 old_state;
    register s32 lock_state;
    s32 i;
    register u32 zero = 0;
    register u32 one = 1;
    OSTime now;
    u32 scale;

    base = lbl_80392960;
    setup = base + 0;
    if (lbl_8055DC30 != 0) {
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

void fn_8006A81C(void) {
    extern char lbl_80313490[];
    u8 *wudControl = lbl_80392960;
    BOOL interrupts;
    BOOL savedInterrupts;
    BOOL shouldCancel;
    OSTime currentTime;
    u32 periodTicks;

    /* Shut down WUD: log, clear visibility flags, stop discovery, and schedule the shutdown alarm. */
    DBPrintf_8006CFA8(lbl_80313490);

    interrupts = OSDisableInterrupts();
    wudControl[0x66B] = 0;
    wudControl[0x66A] = 0;
    OSRestoreInterrupts(interrupts);

    BTA_DmSetVisibility(0, 0);

    savedInterrupts = OSDisableInterrupts();
    interrupts = OSDisableInterrupts();
    if (wudControl[0xC] == 0 && wudControl[0xD] == 0 &&
        wudControl[0xF] == 4 && wudControl[0x10] == 4) {
        OSRestoreInterrupts(interrupts);
        shouldCancel = 0;
    } else {
        OSRestoreInterrupts(interrupts);
        shouldCancel = 1;
    }
    if (shouldCancel != 0)
        OSCancelAlarm((OSAlarm *)(wudControl + 0x690));

    wudControl[0x11] = 1;
    OSCreateAlarm((OSAlarm *)(wudControl + 0x690));
    currentTime = __OSGetSystemTime();
    periodTicks = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 10;
    OSSetPeriodicAlarm((OSAlarm *)(wudControl + 0x690), currentTime, (s64)periodTicks,
                       (OSAlarmHandler)fn_8006A440);
    wudControl[0x688] = 4;
    OSRestoreInterrupts(savedInterrupts);
}

s8 fn_8006A940(void) {
    u32 saved = OSDisableInterrupts();
    u8 val = lbl_80392960[0x688];
    OSRestoreInterrupts(saved);
    return (s8)val;
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

#pragma use_lmw_stmw off
static inline BOOL StartSyncDeviceBusy(void) {
    u8 *base = lbl_80392960;
    BOOL enabled = OSDisableInterrupts();
    if (base[0xC] == 0 && base[0xD] == 0 &&
        base[0xF] == 4 && base[0x10] == 4) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

/* Starts the WUD sync process if the library is ready and not busy: arms the sync state/params and schedules the periodic sync alarm callback. */
s32 StartSyncDevice(u8 syncType, s8 syncLoopNum, BOOL syncSkipChecks) {
    WUDSyncControlView *control = (WUDSyncControlView *)lbl_80392960;
    s32 success = 0;
    u32 libStatus;
    BOOL enabled;
    OSTime now;
    u32 period;

    enabled = OSDisableInterrupts();
    libStatus = control->lib_status;
    OSRestoreInterrupts(enabled);

    if (libStatus == 3 && !StartSyncDeviceBusy()) {
        enabled = OSDisableInterrupts();
        control->sync_state = 1;
        control->sync_loop_num = syncLoopNum;
        control->sync_type = syncType;
        control->sync_skip_checks = syncSkipChecks != 0;
        control->synced_num = 0;
        OSCreateAlarm(&control->sync_alarm);
        now = __OSGetSystemTime();
        period = (((*(volatile u32 *)0x800000F8) >> 2) / 1000) * 0x14;
        OSSetPeriodicAlarm(&control->sync_alarm, now, (s64)period,
                           (OSAlarmHandler)fn_80069C14);
        OSRestoreInterrupts(enabled);
        success = 1;
    }
    return success;
}
#pragma use_lmw_stmw reset

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
    s32 result = 0;
    volatile u8 *base = lbl_80392960;
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

extern u32 lbl_8055DC3C;
extern u32 lbl_8055DC40;
extern u32 lbl_8055DC44;
extern u8 lbl_803135C0[];
extern void fn_8006B044(tBTM_VSC_CMPL *);
void fn_8006AED4(s32 arg0) {
    u8 packet[0x100];
    s32 i;
    s32 length;
    u32 header;
    if (arg0 == 0) {
        fn_8006B330();
        return;
    }
    length = (u8)(lbl_8055DC44 >= 0xFB ? 0xFB : lbl_8055DC44);
    header = lbl_8055DC3C;
    packet[0] = (u8)header;
    packet[1] = (u8)(header >> 8);
    packet[2] = (u8)(header >> 16);
    packet[3] = (u8)(header >> 24);
    for (i = 0; i < length; i++)
        packet[i + 4] = lbl_803135C0[i + 8];
    lbl_8055DC40 = length;
    BTM_VendorSpecificCommand(0xFC4C, (u8)(length + 4), packet, fn_8006B044);
}

void fn_8006B044(tBTM_VSC_CMPL *arg0) {
    extern u8 lbl_8055DC39;
    extern u8 lbl_8055DC3A;
    extern u8 lbl_80313600[];
    extern void fn_8006B26C(tBTM_VSC_CMPL *);
    u8 buf[0x100];
    u8 packet[0x100];
    s32 i;
    s32 length;
    s32 count;
    s32 size;
    u32 header;
    u32 off;
    u32 total;

    if (arg0 != 0) {
        off = lbl_8055DC40;
        total = lbl_8055DC44;
        if (total == off) {
            lbl_8055DC39 = 0;
            count = lbl_80313600[0];
            lbl_8055DC3A = count;
            count = count < 0x13 ? count : 0x13;
            buf[0] = count;
            count = (u8)count;
            size = count * 0xD;
            memcpy(buf + 1, lbl_80313600 + 1, size);
            lbl_8055DC39 += count;
            BTM_VendorSpecificCommand(0xFC4F, (u8)(size + 1), buf, (tBTM_VSC_CMPL_CB *)fn_8006B26C);
            return;
        }
        length = total - off;
        length = (u32)length < 0xFB ? length : 0xFB;
        length = (u8)length;
        header = lbl_8055DC3C + off;
        packet[0] = (u8)header;
        packet[1] = (u8)(header >> 8);
        packet[2] = (u8)(header >> 16);
        packet[3] = (u8)(header >> 24);
        for (i = 0; i < length; i++)
            packet[i + 4] = lbl_803135C0[lbl_8055DC40 + i + 8];
        lbl_8055DC40 += length;
        BTM_VendorSpecificCommand(0xFC4C, (u8)(length + 4), packet, (tBTM_VSC_CMPL_CB *)fn_8006B044);
        return;
    }
    fn_8006B330();
}

/* Continuation callback for the Nintendo BT install-patch VSC (0xFC4F): sends the
 * next chunk (up to 0x13 entries * 0xD bytes each) from the patch data table,
 * tracking progress in the sent/total counters, and completes when done. */
void fn_8006B26C(tBTM_VSC_CMPL *p_vsc_cmpl) {
    extern u8 lbl_8055DC39; /* sInstallPatchSentCount */
    extern u8 lbl_8055DC3A; /* sInstallPatchTotalCount */
    extern u8 lbl_80313600[]; /* sInstallPatchData */
    extern void fn_8006B330(void); /* WUDiInstallPatchComplete */
    s32 count;
    s32 size;
    u8 packet[0x100];

    if (p_vsc_cmpl != 0) {
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

void fn_8006B330(void) {
    /* Configure local BT device state/callbacks and initialize active device entries. */
    extern u8 lbl_80560CF0;
    extern u8 lbl_80560CF1;
    extern u8 lbl_80560CF2;
    extern u8 lbl_80560CF3;
    extern u8 lbl_80560CF4;
    extern u8 lbl_80560CF5;
    extern u8 lbl_80560CF6;
    extern char lbl_80313644[];
    extern void BTA_DmSetDeviceName(char *);
    extern s32 fn_8007A534(s32);
    extern s32 fn_8007A3B4(s32);
    extern void fn_800778C8(s16);
    extern void fn_80077C94(s16);
    extern void WUDDeviceStatusCallback(u32);
    extern void WUDVendorSpecificCallback(u8, u8 *);
    extern void WUDPowerManagerCallback(u8 *, s32, s32, s32);
    extern void fn_8006B488(void);
    u8 deviceName[4];
    DEV_CLASS deviceClass;
    register u8 *entryFlags;
    register u8 *entryData;
    register u8 *wudState = lbl_80392960;
    s32 index;
    BOOL interrupts;

    deviceName[0] = lbl_80560CF0;
    deviceName[1] = lbl_80560CF1;
    deviceName[2] = lbl_80560CF2;
    deviceName[3] = lbl_80560CF3;
    deviceClass[0] = lbl_80560CF4;
    deviceClass[1] = lbl_80560CF5;
    deviceClass[2] = lbl_80560CF6;
    DBPrintf_8006CFA8(lbl_80313644, lbl_80560CF5, lbl_80560CF4,
                      lbl_80560CF3, lbl_80560CF2, lbl_80560CF1, lbl_80560CF0);
    BTA_DmSetDeviceName((char *)deviceName);
    BTM_SetDeviceClass(deviceClass);
    fn_8007A534((s32)WUDVendorSpecificCallback);
    fn_8007A3B4((s32)WUDDeviceStatusCallback);
    BTM_PmRegister(3, wudState + 0x68A, (tBTM_PM_STATUS_CBACK *)WUDPowerManagerCallback);
    BTM_WritePageTimeout(0x8000);
    fn_800778C8(5);
    fn_80077C94(0xC80);
    entryData = wudState + 0xA4;
    entryFlags = wudState;
    index = 0;
    do {
        if (entryFlags[0xBD] == 1)
            ((void (*)(void *))fn_8006B488)(entryData);
        index++;
        entryFlags += 0x60;
        entryData += 0x60;
    } while (index < 10);
    interrupts = OSDisableInterrupts();
    wudState[0x688] = 3;
    OSRestoreInterrupts(interrupts);
    interrupts = OSDisableInterrupts();
    lbl_80392960[0x66B] = 0;
    lbl_80392960[0x66A] = 1;
    OSRestoreInterrupts(interrupts);
    BTA_DmSetVisibility(0, 1);
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
    u16 dl_len;
    u32 dsc_list;
    f64 argData;
    status = BTA_DmAddDevice(info + 0x40, info + 0x46, 0, 0);
    DBPrintf_8006CFA8((const char *)(base + 0x5D8), status);
    if (memcmp(info, base + 0x1A0, 0x10) == 0) {
        dl_len = 217;
        dsc_list = (u32)base;
        DBPrintf_8006CFA8((const char *)(base + 0x5F0));
        argData = *(f64 *)&dl_len;
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

extern void BTA_HhRemoveDev(u8);
extern u8 fn_80073E5C(u8 *);
int fn_8006B598(void *addr) {
    register u8 *strings = lbl_803130C8;
    register u8 *state = lbl_80392960;
    u8 *deviceInfo;
    u32 interrupts;
    u8 status;
    /* Logs and removes a WUD device by address: prints device details, removes HID pairing
       and security records when matching, updates active device counts, clears the record, and
       restores interrupts. */
    interrupts = OSDisableInterrupts();
    DBPrintf_8006CFA8((const char *)(strings + 0x600));
    deviceInfo = WUDiGetDevInfo((u8 *)addr);
    if (deviceInfo != 0) {
        DBPrintf_8006CFA8((const char *)(strings + 0x618),
                          deviceInfo[0x56], deviceInfo[0x40], deviceInfo[0x41], deviceInfo[0x42],
                          deviceInfo[0x43], deviceInfo[0x44], deviceInfo[0x45]);
        DBPrintf_8006CFA8((const char *)(strings + 0x650));
        if (memcmp(deviceInfo, strings + 0x1A0, 0x10) == 0) {
            DBPrintf_8006CFA8((const char *)(strings + 0x674));
            DBPrintf_8006CFA8((const char *)(strings + 0x688), deviceInfo[0x56]);
            BTA_HhRemoveDev(deviceInfo[0x56]);
        }
        status = fn_80073E5C(deviceInfo + 0x40);
        DBPrintf_8006CFA8((const char *)(strings + 0x698), status);
        if (deviceInfo[0x5B] == 0)
            state[0x12]--;
        else
            state[0x13]--;
        memset(deviceInfo, 0, 0x60);
    }
    OSRestoreInterrupts(interrupts);
}

#pragma use_lmw_stmw off
/* Returns the WUD device-info record whose 6-byte Bluetooth address matches bdAddr,
   searching the 10 standard slots then the 6 simple-pairing slots, or NULL if not found. */
void *WUDiGetDevInfo(u8 *bdAddr) {
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
    void *devInfo;
    s32 enabled;
    s32 index;
    u8 *devEntry;

    control = (struct WUDControlView *)lbl_80392960;
    devInfo = 0;
    enabled = OSDisableInterrupts();
    devEntry = control->stdDevs[0].addr;
    for (index = 0; index < 10; index++, devEntry += 0x60) {
        if (memcmp(devEntry, bdAddr, 6) == 0) {
            devInfo = &control->stdDevs[index];
            break;
        }
    }
    if (devInfo == 0) {
        devEntry = control->smpDevs[0].addr;
        for (index = 0; index < 6; index++, devEntry += 0x60) {
            if (memcmp(devEntry, bdAddr, 6) == 0) {
                devInfo = &control->smpDevs[index];
                break;
            }
        }
    }
    OSRestoreInterrupts(enabled);
    return devInfo;
}
#pragma use_lmw_stmw on
extern char lbl_8031377C[];
void *WUDiGetNewDevInfo(void) {
    /* Return a free WUD device-info slot (first unused std slot when not SMP mode, else current new-dev slot). */
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

#pragma use_lmw_stmw off
void WUDiMoveTopSmpDevInfoPtr(u8 *arg0, void *arg1) {
    typedef struct WUDDevInfoView {
        u8 pad[0x40];
        u8 devAddr[6];
    } WUDDevInfoView;
    typedef struct WUDListEntry WUDListEntry;
    struct WUDListEntry {
        WUDDevInfoView *devInfo;
        WUDListEntry *prev;
        WUDListEntry *next;
    };
    typedef struct {
        u8 pad[0x14];
        WUDListEntry *smpListHead;
        WUDListEntry *smpListTail;
        WUDListEntry smpList[6];
    } WUDCBView;

    WUDCBView *wudCb = (WUDCBView *)lbl_80392960;
    WUDDevInfoView *targetDevInfo = (WUDDevInfoView *)arg0;
    BOOL interrupts;
    s32 i;
    u8 *scan;

    interrupts = OSDisableInterrupts();
    scan = (u8 *)wudCb;
    for (i = 0; i < 6; i++, scan += 0xC) {
        WUDListEntry *entry;
        WUDListEntry *cur = (WUDListEntry *)(scan + 0x1C);
        if (memcmp(cur->devInfo->devAddr, targetDevInfo->devAddr, 6) != 0)
            continue;
        {
            u8 *baseOff = (u8 *)wudCb + (s32)i * 0xC;
            WUDListEntry *e2 = (WUDListEntry *)(baseOff + 0x1C);
            if (memcmp(wudCb->smpListHead->devInfo->devAddr, e2->devInfo->devAddr, 6) == 0)
                break;
            *(WUDListEntry **)(*(u8 **)(baseOff + 0x20) + 8) = *(WUDListEntry **)(baseOff + 0x24);
            if (memcmp(wudCb->smpListTail->devInfo->devAddr, e2->devInfo->devAddr, 6) == 0) {
                wudCb->smpListTail = *(WUDListEntry **)(baseOff + 0x20);
            } else {
                *(WUDListEntry **)(*(u8 **)(baseOff + 0x24) + 4) = *(WUDListEntry **)(baseOff + 0x20);
            }
            entry = e2;
            entry->next = wudCb->smpListHead;
            wudCb->smpListHead->prev = entry;
            wudCb->smpListHead = entry;
            entry->prev = 0;
            break;
        }
    }
    OSRestoreInterrupts(interrupts);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
void WUDiMoveBottomSmpDevInfoPtr_8006B98C(void *arg0) {
    /* Move the SMP device-info list entry matching arg0's device address to the bottom of the list, if it is not already there. */
    typedef struct WUDDevInfoView {
        u8 pad[0x40];
        u8 devAddr[6];
    } WUDDevInfoView;
    typedef struct WUDListEntry WUDListEntry;
    struct WUDListEntry {
        WUDDevInfoView *devInfo;
        WUDListEntry *prev;
        WUDListEntry *next;
    };
    typedef struct {
        u8 pad[0x14];
        WUDListEntry *smpListHead;
        WUDListEntry *smpListTail;
        WUDListEntry smpList[6];
    } WUDCBView;

    WUDCBView *wudCb = (WUDCBView *)lbl_80392960;
    WUDDevInfoView *targetDevInfo = (WUDDevInfoView *)arg0;
    BOOL interrupts;
    s32 i;

    interrupts = OSDisableInterrupts();
    for (i = 0; i < 6; i++) {
        if (memcmp(wudCb->smpList[i].devInfo->devAddr, targetDevInfo->devAddr, 6) != 0) {
            continue;
        }

        if (memcmp(wudCb->smpListTail->devInfo->devAddr, wudCb->smpList[i].devInfo->devAddr, 6) == 0) {
            break;
        }

        wudCb->smpList[i].next->prev = wudCb->smpList[i].prev;
        if (memcmp(wudCb->smpListHead->devInfo->devAddr, wudCb->smpList[i].devInfo->devAddr, 6) == 0) {
            wudCb->smpListHead = wudCb->smpList[i].next;
        } else {
            wudCb->smpList[i].prev->next = wudCb->smpList[i].next;
        }

        wudCb->smpList[i].prev = wudCb->smpListTail;
        wudCb->smpListTail->next = &wudCb->smpList[i];
        wudCb->smpListTail = &wudCb->smpList[i];
        wudCb->smpList[i].next = 0;
        break;
    }
    OSRestoreInterrupts(interrupts);
}
#pragma use_lmw_stmw reset
extern char lbl_80319994[];
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

#pragma push
#pragma use_lmw_stmw off
/*******************************************************************************
**
** Function         gki_init_free_queue
**
** Description      Internal function called at startup to initialize one buffer
**                  pool and its free queue (once per queue, from
**                  gki_buffer_init() / GKI_create_pool()).  The pool's buffers
**                  are size bytes of payload each, spaced act_size apart
**                  (payload + BUFFER_PADDING_SIZE for the header and its magic
**                  word); they are chained through p_next into the pool's free
**                  queue and every header is marked free and unowned.
**                  Original gki/common/gki_buffer.c.
**
** Returns          void
**
*******************************************************************************/
void gki_init_free_queue(UINT8 id, UINT16 size, UINT16 total, void *p_mem) {
    UINT16 i;
    UINT16 act_size;
    BUFFER_HDR_T *hdr;
    BUFFER_HDR_T *hdr1 = NULL;
    UINT32 *magic;
    INT32 tempsize = size;
    tGKI_COM_CB *p_cb = &gki_cb.com;

    /* Round the payload up to a whole number of longwords; each buffer also
       needs room for its header and trailing magic number */
    tempsize = (INT32)ALIGN_POOL(size);
    act_size = (UINT16)(tempsize + BUFFER_PADDING_SIZE);

    /* Remember where this pool lives and how big its buffers are */
    p_cb->pool_start[id] = (UINT8 *)p_mem;
    p_cb->pool_end[id] = (UINT8 *)p_mem + (act_size * total);
    p_cb->pool_size[id] = act_size;

    /* The free queue starts empty, holding buffers of the aligned size */
    p_cb->freeq[id].size = (UINT16)tempsize;
    p_cb->freeq[id].total = total;
    p_cb->freeq[id].cur_cnt = 0;
    p_cb->freeq[id].max_cnt = 0;
    hdr = (BUFFER_HDR_T *)p_mem;
    p_cb->freeq[id].p_first = hdr;

    /* Link all total buffers into one free list */
    for (i=0; i<total; i++) {
        hdr->task_id = GKI_INVALID_TASK;
        hdr->q_id = id;
        hdr->status = BUF_STATUS_FREE;
        magic = (UINT32 *)((UINT8 *)hdr + BUFFER_HDR_SIZE + tempsize);
        *magic = MAGIC_NO;
        hdr1 = hdr;
        hdr = (BUFFER_HDR_T *)((UINT8 *)hdr + act_size);
        hdr1->p_next = hdr;
    }

    /* Terminate the list; hdr1 is the last buffer of the pool */
    hdr1->p_next = NULL;
    p_cb->freeq[id].p_last = hdr1;
}
#pragma pop
extern void gki_init_free_queue(UINT8, UINT16, UINT16, void *);
/*******************************************************************************
**
** Function         gki_buffer_init
**
** Description      Called once at startup by GKI_init() to set up GKI's buffer
**                  allocator: empties every task mailbox, clears all of the
**                  buffer pool descriptors and their free queues, then links
**                  the buffers of the fixed pools compiled into gki_cb into
**                  their free lists.  Original gki/common/gki_buffer.c.
**
** Returns          void
**
*******************************************************************************/
void gki_buffer_init(void)
{
    UINT8   pool, task, mbox;
    tGKI_COM_CB *p_cb = &gki_cb.com;

    /* Initialize mailboxes */
    for (task = 0; task < GKI_MAX_TASKS; task++) {
        for (mbox = 0; mbox < NUM_TASK_MBOX; mbox++) {
            p_cb->OSTaskQFirst[task][mbox] = NULL;
            p_cb->OSTaskQLast[task][mbox] = NULL;
        }
    }

    /* No pool is set up yet: no memory, no buffers on the free queue */
    for (pool = 0; pool < GKI_NUM_TOTAL_BUF_POOLS; pool++) {
        p_cb->pool_start[pool] = NULL;
        p_cb->pool_end[pool] = NULL;
        p_cb->pool_size[pool] = 0;
        p_cb->freeq[pool].p_first = 0;
        p_cb->freeq[pool].p_last = 0;
        p_cb->freeq[pool].size = 0;
        p_cb->freeq[pool].total = 0;
        p_cb->freeq[pool].cur_cnt = 0;
        p_cb->freeq[pool].max_cnt = 0;
    }

    /* Use default from target.h (GKI_DEF_BUFPOOL_PERM_MASK): the pools above the
       fixed ones are reserved for restricted use */
    p_cb->pool_access_mask = GKI_DEF_BUFPOOL_PERM_MASK;

    /* The fixed pools are static arrays inside gki_cb; each becomes a free list
       of GKI_BUFn_MAX buffers of GKI_BUFn_SIZE bytes */
    gki_init_free_queue(0, GKI_BUF0_SIZE, GKI_BUF0_MAX, p_cb->bufpool0);
    gki_init_free_queue(1, GKI_BUF1_SIZE, GKI_BUF1_MAX, p_cb->bufpool1);
    gki_init_free_queue(2, GKI_BUF2_SIZE, GKI_BUF2_MAX, p_cb->bufpool2);
    gki_init_free_queue(3, GKI_BUF3_SIZE, GKI_BUF3_MAX, p_cb->bufpool3);
    gki_init_free_queue(4, GKI_BUF4_SIZE, GKI_BUF4_MAX, p_cb->bufpool4);

    /* Pools are ordered smallest to largest; GKI_getbuf() takes the first pool
       whose buffers are big enough.  Only the fixed pools exist so far. */
    for (pool = 0; pool < GKI_NUM_FIXED_BUF_POOLS; pool++)
        p_cb->pool_list[pool] = pool;
    p_cb->curr_total_no_of_pools = GKI_NUM_FIXED_BUF_POOLS;
}

void fn_8006D4C4(void *arg) {
    ((s32 *)arg)[1] = 0;
    ((s32 *)arg)[0] = 0;
    ((u16 *)arg)[4] = 0;
}

/* Allocate a buffer from the first suitable GKI pool for the requested size, or report an allocation error. */
void *GKI_getbuf(UINT16 size) {
    UINT8 poolIndex;
    FREE_QUEUE_T *freeQueue;
    BUFFER_HDR_T *bufferHdr;
    tGKI_COM_CB *comCb = (tGKI_COM_CB *)((UINT8 *)lbl_803946C0 + 0x54);

    if (size == 0) {
        ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_BUF_SIZE_ZERO, lbl_80314110);
        return NULL;
    }

    for (poolIndex = 0; poolIndex < comCb->curr_total_no_of_pools; poolIndex++) {
        if (size <= comCb->freeq[comCb->pool_list[poolIndex]].size)
            break;
    }

    if (poolIndex == comCb->curr_total_no_of_pools) {
        ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_BUF_SIZE_TOOBIG, lbl_80314128);
        return NULL;
    }

    fn_8006EBAC();

    for (; poolIndex < comCb->curr_total_no_of_pools; poolIndex++) {
        if (((UINT16)1 << comCb->pool_list[poolIndex]) & *(volatile UINT16 *)((UINT8 *)comCb + 0x28A7C))
            continue;

        freeQueue = &comCb->freeq[comCb->pool_list[poolIndex]];
        if (freeQueue->cur_cnt < freeQueue->total) {
            bufferHdr = freeQueue->p_first;
            freeQueue->p_first = bufferHdr->p_next;
            if (!freeQueue->p_first)
                freeQueue->p_last = NULL;
            if (++freeQueue->cur_cnt > freeQueue->max_cnt)
                freeQueue->max_cnt = freeQueue->cur_cnt;
            fn_8006EB88();
            bufferHdr->task_id = fn_8006EB80();
            bufferHdr->status = BUF_STATUS_UNLINKED;
            bufferHdr->p_next = NULL;
            bufferHdr->Type = 0;
            return (void *)((UINT8 *)bufferHdr + BUFFER_HDR_SIZE);
        }
    }
    fn_8006EB88();
    return NULL;
}

/* Allocate a buffer from a GKI pool free queue, or fall back to GKI_getbuf(pool size). */
void *GKI_getpoolbuf(UINT8 pool_id) {
    extern u32 lbl_803946C0[];
    extern void fn_8006EBAC(void);
    extern void fn_8006EB88(void);
    extern u8 fn_8006EB80(void);
    FREE_QUEUE_T *queue;
    BUFFER_HDR_T *hdr;
    tGKI_COM_CB *com = (tGKI_COM_CB *)((UINT8 *)lbl_803946C0 + 0x54);

    if (pool_id >= GKI_NUM_TOTAL_BUF_POOLS)
        return NULL;

    fn_8006EBAC();

    queue = &com->freeq[pool_id];
    if (queue->cur_cnt < queue->total) {
        hdr = queue->p_first;
        queue->p_first = hdr->p_next;

        if (!queue->p_first)
            queue->p_last = NULL;

        if (++queue->cur_cnt > queue->max_cnt)
            queue->max_cnt = queue->cur_cnt;

        fn_8006EB88();

        hdr->task_id = fn_8006EB80();
        hdr->status = BUF_STATUS_UNLINKED;
        hdr->p_next = NULL;
        hdr->Type = 0;

        return (void *)((UINT8 *)hdr + BUFFER_HDR_SIZE);
    }

    fn_8006EB88();
    return GKI_getbuf(com->freeq[pool_id].size);
}

/* GKI_exception() message strings, as offsets into the GKI strings block that
   starts at lbl_80314110 ("getbuf: Size is zero").  See gki_buffer.c. */
#define GKI_STR_FREE_BUF_CORRUPTED  0x30  /* "Free - Buf Corrupted" */
#define GKI_STR_FREEING_LINKED_BUF  0x48  /* "Freeing Linked Buf" */
#define GKI_STR_BAD_BUF_QID         0x5C  /* "Bad Buf QId" */
#define GKI_STR_SEND_BAD_DEST       0x68  /* "Sending to unknown dest" */
#define GKI_STR_SEND_BUF_CORRUPTED  0x80  /* "Send - Buffer corrupted" */
#define GKI_STR_SEND_BUF_LINKED     0x98  /* "Send - buffer linked" */

/*
 * Return a buffer to the free list of the pool it came from (gki_buffer.c).
 *
 * The buffer is checked the way gki_chk_buf_damage() does: its size comes from
 * the pool named by the header's queue id (GKI_get_buf_size()), and MAGIC_NO
 * has to sit in the word right past the buffer.  A null or damaged buffer, a
 * header that is still queued and a pool id past the last pool are each
 * reported with GKI_exception() and left alone.  Otherwise the header goes on
 * the tail of gki_cb.com.freeq[q_id], is marked free and no longer owned by a
 * task, and the pool's count of allocated buffers drops by one - all with
 * interrupts disabled around the list surgery.
 */
void GKI_freebuf(void *p_buf)
{
    char *p_err_str = lbl_80314110;   /* GKI_exception() message strings */
    BUFFER_HDR_T *p_hdr;
    UINT16 size;
    UINT8 pool_id;
    UINT32 *magic;
    BOOLEAN damaged;
    FREE_QUEUE_T *Q;

    if (p_buf == NULL)
        goto bad_buffer;

    /* GKI_get_buf_size(): an odd header address means no size to trust */
    p_hdr = (BUFFER_HDR_T *)((UINT8 *)p_buf - BUFFER_HDR_SIZE);
    if (((UINT32)p_hdr & 1) != 0) {
        size = 0;
    } else {
        pool_id = p_hdr->q_id;
        if (pool_id < GKI_NUM_TOTAL_BUF_POOLS)
            size = gki_cb.com.freeq[pool_id].size;
        else
            size = 0;
    }

    /* gki_chk_buf_damage(): the magic word written past the user's buffer */
    magic = (UINT32 *)((UINT8 *)p_buf + size);
    if (((UINT32)magic & 1) != 0) {
        damaged = TRUE;
    } else if (*magic == MAGIC_NO) {
        damaged = FALSE;
    } else {
        damaged = TRUE;
    }
    if (damaged == FALSE)
        goto valid_buffer;

bad_buffer:
    /* GKI_exception(GKI_ERROR_BUF_CORRUPTED, "Free - Buf Corrupted") */
    ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_BUF_CORRUPTED,
                                               p_err_str + GKI_STR_FREE_BUF_CORRUPTED);
    return;

valid_buffer:
    /* GKI_exception(GKI_ERROR_FREEBUF_BUF_LINKED, "Freeing Linked Buf") */
    if (p_hdr->status != BUF_STATUS_UNLINKED) {
        ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_FREEBUF_BUF_LINKED,
                                                   p_err_str + GKI_STR_FREEING_LINKED_BUF);
        return;
    }
    /* GKI_exception(GKI_ERROR_FREEBUF_BAD_QID, "Bad Buf QId") */
    if (p_hdr->q_id >= GKI_NUM_TOTAL_BUF_POOLS) {
        ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_FREEBUF_BAD_QID,
                                                   p_err_str + GKI_STR_BAD_BUF_QID);
        return;
    }

    fn_8006EBAC();                            /* GKI_disable() */
    Q = &gki_cb.com.freeq[p_hdr->q_id];
    if (Q->p_last != NULL)
        Q->p_last->p_next = p_hdr;
    else
        Q->p_first = p_hdr;
    Q->p_last = p_hdr;
    p_hdr->p_next = NULL;
    p_hdr->status = BUF_STATUS_FREE;
    p_hdr->task_id = GKI_INVALID_TASK;
    if (Q->cur_cnt != 0)
        Q->cur_cnt--;
    fn_8006EB88();                            /* GKI_enable() */
}

/*
 * Send a buffer to a task's mailbox (gki_buffer.c).
 *
 * A buffer for a task that does not exist or has not started is dropped with
 * GKI_exception() and freed.  The buffer is then checked the way
 * gki_chk_buf_damage() does (its size from the pool named by the header's queue
 * id, MAGIC_NO sitting in the word past it); a damaged buffer or one whose
 * header is already linked is reported and left alone.  Otherwise, with
 * interrupts disabled, the header is appended to gki_cb.com.OSTaskQ[task][mbox],
 * marked queued and owned by the task, and the task is woken with the mailbox's
 * event bit.
 */
void GKI_send_msg(UINT8 task_id, UINT8 mbox, void *msg) {
    BUFFER_HDR_T *p_hdr;
    char *p_err_str = lbl_80314110;   /* GKI_exception() message strings */
    tGKI_COM_CB *p_cb = &gki_cb.com;
    UINT16 size;
    UINT32 *magic;
    BOOLEAN damaged;

    /* If task non-existent or not started, drop buffer */
    if (task_id >= GKI_MAX_TASKS || mbox >= NUM_TASK_MBOX || p_cb->OSRdyTbl[task_id] == TASK_DEAD) {
        /* GKI_exception(GKI_ERROR_SEND_MSG_BAD_DEST, "Sending to unknown dest") */
        ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_SEND_MSG_BAD_DEST,
                                                   p_err_str + GKI_STR_SEND_BAD_DEST);
        GKI_freebuf(msg);
        return;
    }

    /* gki_chk_buf_damage(): the magic word written past the user's buffer */
    p_hdr = (BUFFER_HDR_T *)((UINT8 *)msg - BUFFER_HDR_SIZE);
    if (((UINT32)p_hdr & 1) != 0) {
        size = 0;
    } else {
        UINT8 pool_id = p_hdr->q_id;
        if (pool_id < GKI_NUM_TOTAL_BUF_POOLS)
            size = gki_cb.com.freeq[pool_id].size;
        else
            size = 0;
    }
    magic = (UINT32 *)((UINT8 *)msg + size);
    if (((UINT32)magic & 1) != 0)
        damaged = TRUE;
    else if (*magic == MAGIC_NO)
        damaged = FALSE;
    else
        damaged = TRUE;
    if (damaged != FALSE) {
        /* GKI_exception(GKI_ERROR_BUF_CORRUPTED, "Send - Buffer corrupted") */
        ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_BUF_CORRUPTED,
                                                   p_err_str + GKI_STR_SEND_BUF_CORRUPTED);
        return;
    }

    if (p_hdr->status != BUF_STATUS_UNLINKED) {
        /* GKI_exception(GKI_ERROR_SEND_MSG_BUF_LINKED, "Send - buffer linked") */
        ((void (*)(u16, const char *))fn_8006EBF0)(GKI_ERROR_SEND_MSG_BUF_LINKED,
                                                   p_err_str + GKI_STR_SEND_BUF_LINKED);
        return;
    }

    fn_8006EBAC();                            /* GKI_disable() */
    if (p_cb->OSTaskQFirst[task_id][mbox])
        p_cb->OSTaskQLast[task_id][mbox]->p_next = p_hdr;
    else
        p_cb->OSTaskQFirst[task_id][mbox] = p_hdr;
    p_cb->OSTaskQLast[task_id][mbox] = p_hdr;
    p_hdr->p_next = NULL;
    p_hdr->status = BUF_STATUS_QUEUED;
    p_hdr->task_id = task_id;
    fn_8006EB88();                            /* GKI_enable() */
    GKI_send_event(task_id, (UINT16)EVENT_MASK(mbox));
}

void *GKI_read_mbox(UINT8 mbox) {
    /* Read and dequeue the first buffer from the current task's mailbox queue,
     * returning a pointer to the buffer payload (or NULL if invalid/empty). */
    UINT8 taskId = GKI_get_taskid();
    void *buffer = NULL;
    BUFFER_HDR_T *bufferHeader;

    if (taskId >= GKI_MAX_TASKS || mbox >= NUM_TASK_MBOX) {
        return NULL;
    }

    GKI_disable();

    if (gki_cb.com.OSTaskQFirst[taskId][mbox]) {
        bufferHeader = gki_cb.com.OSTaskQFirst[taskId][mbox];
        gki_cb.com.OSTaskQFirst[taskId][mbox] = bufferHeader->p_next;
        bufferHeader->p_next = NULL;
        bufferHeader->status = BUF_STATUS_UNLINKED;
        buffer = (UINT8 *)bufferHeader + BUFFER_HDR_SIZE;
    }

    GKI_enable();

    return buffer;
}

void GKI_enqueue(BUFFER_Q *p_q, void *p_buf) {
    /* Enqueue a buffer at the tail of a GKI queue after validating its header/magic and link status. */
    extern u32 lbl_803946C0[];
    extern char lbl_803141C0[];
    extern char lbl_803141DC[];
    extern void fn_8006EBF0(void);
    BUFFER_HDR_T *p_hdr = (BUFFER_HDR_T *)((u8 *)p_buf - 8);
    u8 pool_id;
    u16 size;
    u32 *magic;
    u8 damaged;
    BUFFER_HDR_T *p_last_hdr;

    if (((u32)p_hdr & 1) != 0) {
        size = 0;
    } else {
        pool_id = p_hdr->q_id;
        if (pool_id < 9)
            size = *(u16 *)((u8 *)lbl_803946C0 + 0x289E8 + (pool_id << 4));
        else
            size = 0;
    }
    magic = (u32 *)((u8 *)p_buf + size);
    if (((u32)magic & 1) != 0) {
        damaged = 1;
    } else if (*magic == 0xDDBADDBA) {
        damaged = 0;
    } else {
        damaged = 1;
    }
    if (damaged != 0) {
        ((void (*)(u16, const char *))fn_8006EBF0)(0xFFFF, lbl_803141C0);
        return;
    }
    if (p_hdr->status != BUF_STATUS_UNLINKED) {
        ((void (*)(u16, const char *))fn_8006EBF0)(0xFFF9, lbl_803141DC);
        return;
    }

    fn_8006EBAC();
    if (p_q->p_first != NULL) {
        p_last_hdr = (BUFFER_HDR_T *)((u8 *)p_q->p_last - 8);
        p_last_hdr->p_next = p_hdr;
    } else {
        p_q->p_first = p_buf;
    }
    p_q->p_last = p_buf;
    p_q->count++;
    p_hdr->p_next = NULL;
    p_hdr->status = BUF_STATUS_QUEUED;
    fn_8006EB88();
}

void GKI_enqueue_head(BUFFER_Q *p_q, void *p_buf) {
    extern u32 lbl_803946C0[];
    extern char lbl_803141C0[];
    extern char lbl_803141FC[];
    extern void fn_8006EBF0(void);
    /* Prepends a buffer to the head of a GKI queue after inline damage/status checks,
       updating queue links/count and buffer status under interrupt protection. */
    BUFFER_HDR_T *p_hdr = (BUFFER_HDR_T *)((u8 *)p_buf - 8);
    u8 pool_id;
    u16 size;
    u32 *magic;
    u8 damaged;

    if (((u32)p_hdr & 1) != 0) {
        size = 0;
    } else {
        pool_id = p_hdr->q_id;
        if (pool_id < 9)
            size = *(u16 *)((u8 *)lbl_803946C0 + 0x289E8 + (pool_id << 4));
        else
            size = 0;
    }
    magic = (u32 *)((u8 *)p_buf + size);
    if (((u32)magic & 1) != 0) {
        damaged = 1;
    } else if (*magic == 0xDDBADDBA) {
        damaged = 0;
    } else {
        damaged = 1;
    }
    if (damaged != 0) {
        ((void (*)(u16, const char *))fn_8006EBF0)(0xFFFF, lbl_803141C0);
        return;
    }
    if (p_hdr->status != BUF_STATUS_UNLINKED) {
        ((void (*)(u16, const char *))fn_8006EBF0)(0xFFF9, lbl_803141FC);
        return;
    }

    fn_8006EBAC();
    if (p_q->p_first != NULL) {
        p_hdr->p_next = (BUFFER_HDR_T *)((u8 *)p_q->p_first - 8);
        p_q->p_first = p_buf;
    } else {
        p_q->p_first = p_buf;
        p_q->p_last = p_buf;
        p_hdr->p_next = NULL;
    }
    p_q->count++;
    p_hdr->status = BUF_STATUS_QUEUED;
    fn_8006EB88();
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

/* Remove a specific buffer from a queue, updating links/count/status, or return NULL if not found. */
void *GKI_remove_from_queue(BUFFER_Q *p_q, void *p_buf)
{
    BUFFER_HDR_T *p_buf_hdr;
    BUFFER_HDR_T *p_scan_hdr;

    fn_8006EBAC();
    if (p_buf == p_q->p_first) {
        fn_8006EB88();
        return GKI_dequeue(p_q);
    }

    p_buf_hdr = (BUFFER_HDR_T *)((u8 *)p_buf - BUFFER_HDR_SIZE);
    p_scan_hdr = (BUFFER_HDR_T *)((u8 *)p_q->p_first - BUFFER_HDR_SIZE);
    while (p_scan_hdr != NULL) {
        if (p_scan_hdr->p_next == p_buf_hdr) {
            p_scan_hdr->p_next = p_buf_hdr->p_next;
            if (p_buf == p_q->p_last) {
                p_q->p_last = (u8 *)p_scan_hdr + BUFFER_HDR_SIZE;
            }
            p_q->count--;
            p_buf_hdr->p_next = NULL;
            p_buf_hdr->status = BUF_STATUS_UNLINKED;
            fn_8006EB88();
            return p_buf;
        }
        p_scan_hdr = (BUFFER_HDR_T *)p_scan_hdr->p_next;
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

static void gki_remove_pool_from_list_local(UINT8 pool_id)
{
    UINT8 i;
    tGKI_COM_CB *p_cb = (tGKI_COM_CB *)((u8 *)lbl_803946C0 + 0x54);

    for (i = 0; i < p_cb->curr_total_no_of_pools; i++) {
        if (pool_id == p_cb->pool_list[i])
            break;
    }

    while (i < (p_cb->curr_total_no_of_pools - 1)) {
        p_cb->pool_list[i] = p_cb->pool_list[i + 1];
        i++;
    }
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
#pragma push
#pragma use_lmw_stmw off
void GKI_delete_pool(UINT8 pool_id) {
    FREE_QUEUE_T *Q;
    tGKI_COM_CB *p_cb = &((tGKI_CB *)lbl_803946C0)->com;
    tGKI_COM_CB *list_base;
    UINT8 i;
    if (pool_id >= 9) {
        goto bad_pool;
    }
    if (p_cb->pool_start[pool_id] != NULL) {
        fn_8006EBAC();
        Q = &p_cb->freeq[pool_id];
        if (!Q->cur_cnt) {
            Q->size = 0;
            Q->total = 0;
            Q->cur_cnt = 0;
            Q->max_cnt = 0;
            Q->p_first = NULL;
            Q->p_last = NULL;
            fn_8006EC20(p_cb->pool_start[pool_id]);
            p_cb->pool_start[pool_id] = NULL;
            p_cb->pool_end[pool_id] = NULL;
            p_cb->pool_size[pool_id] = 0;
            list_base = p_cb;
            for (i = 0; i < list_base->curr_total_no_of_pools; i++) {
                if (pool_id == list_base->pool_list[i]) {
                    break;
                }
            }
            while (i < (list_base->curr_total_no_of_pools - 1)) {
                list_base->pool_list[i] = list_base->pool_list[i + 1];
                i++;
            }
            list_base->curr_total_no_of_pools--;
        } else {
            goto bad_pool;
        }
        fn_8006EB88();
        return;
    }
bad_pool:
    fn_8006EBF0(0xFFF8, lbl_80314240);
    fn_8006EB88();
}
#pragma pop
/* Initialize GKI timer state by clearing the timer tick counters and
 * per-task timer slots in gki_cb.com (fixed-offset fields relative to lbl_803946C0). */
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

#pragma push
#pragma use_lmw_stmw off
#pragma push
#pragma scheduling invalid_target
void GKI_start_timer(UINT8 tnum, INT32 ticks, BOOLEAN is_continuous) {
    INT32 reload;
    INT32 total;
    register INT32 start;
    register INT32 end;
    UINT8 task_id;
    BOOLEAN bad_timer;

    task_id = fn_8006EB80();
    bad_timer = FALSE;
    if (ticks <= 0)
        ticks = 1;
    reload = ticks & ((-(INT32)is_continuous | (INT32)is_continuous) >> 31);
    fn_8006EBAC();

    start = *(volatile INT32 *)&gki_cb.com.OSTicksTilExp;
    end = *(volatile INT32 *)&gki_cb.com.OSNumOrigTicks;
    total = end - start;
    if ((INT32)(0x7FFFFFFF - total) > ticks)
        total = ticks + total;
    else
        total = 0x7FFFFFFF;

    switch (tnum) {
    case 0:
        gki_cb.com.OSTaskTmr0R[task_id] = reload;
        gki_cb.com.OSTaskTmr0[task_id] = total;
        break;
    case 1:
        gki_cb.com.OSTaskTmr1R[task_id] = reload;
        gki_cb.com.OSTaskTmr1[task_id] = total;
        break;
    default:
        bad_timer = TRUE;
        break;
    }

    if (!bad_timer && ticks > 0 &&
        (gki_cb.com.OSNumOrigTicks == 0 ||
         (ticks < gki_cb.com.OSTicksTilExp && gki_cb.com.OSTicksTilExp > 0))) {
        gki_cb.com.OSNumOrigTicks =
            ticks + (gki_cb.com.OSNumOrigTicks - gki_cb.com.OSTicksTilExp);
        gki_cb.com.OSTicksTilExp = ticks;
    }
    fn_8006EB88();
}
#pragma pop
#pragma pop

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

/* Insert a timer entry into a delta-tick timer list queue. */
void GKI_add_to_timer_list(TIMER_LIST_Q *p_timer_listq, TIMER_LIST_ENT *p_tle) {
    TIMER_LIST_ENT *p_temp;
    INT32 nr_ticks_total;

    if (p_tle->ticks < 0) return;
    if (p_tle->ticks >= p_timer_listq->last_ticks) {
        if (p_timer_listq->p_first == NULL) {
            p_timer_listq->p_first = p_tle;
        } else {
            if (p_timer_listq->p_last != NULL) p_timer_listq->p_last->p_next = p_tle;
            p_tle->p_prev = p_timer_listq->p_last;
        }
        p_tle->p_next = NULL;
        p_timer_listq->p_last = p_tle;
        nr_ticks_total = p_tle->ticks;
        p_tle->ticks = nr_ticks_total - p_timer_listq->last_ticks;
        p_timer_listq->last_ticks = nr_ticks_total;
    } else {
        p_temp = p_timer_listq->p_first;
        while (p_tle->ticks > p_temp->ticks) {
            if (p_temp->ticks > 0) p_tle->ticks -= p_temp->ticks;
            p_temp = p_temp->p_next;
        }
        if (p_temp == p_timer_listq->p_first) {
            p_tle->p_next = p_timer_listq->p_first;
            p_timer_listq->p_first->p_prev = p_tle;
            p_timer_listq->p_first = p_tle;
        } else {
            p_temp->p_prev->p_next = p_tle;
            p_tle->p_prev = p_temp->p_prev;
            p_temp->p_prev = p_tle;
            p_tle->p_next = p_temp;
        }
        p_temp->ticks -= p_tle->ticks;
    }
    p_tle->in_use = 1;
}

/* Remove a timer entry from a delta-tick timer list, adjusting the following entry's
 * remaining ticks or the list tail remainder as needed before unlinking it. Invalid
 * or inconsistent links are left unchanged. */
void GKI_remove_from_timer_list(TIMER_LIST_Q *timer_list, TIMER_LIST_ENT *timer_entry) {
    if (timer_entry == NULL || timer_entry->in_use == FALSE || timer_list->p_first == NULL)
        return;

    if (timer_entry->p_next != NULL)
        timer_entry->p_next->ticks += timer_entry->ticks;
    else
        timer_list->last_ticks -= timer_entry->ticks;

    if (timer_list->p_first == timer_entry) {
        timer_list->p_first = timer_entry->p_next;
        if (timer_list->p_first != NULL)
            timer_list->p_first->p_prev = NULL;
        if (timer_list->p_last == timer_entry)
            timer_list->p_last = NULL;
    } else {
        if (timer_list->p_last == timer_entry) {
            timer_list->p_last = timer_entry->p_prev;
            if (timer_list->p_last != NULL)
                timer_list->p_last->p_next = NULL;
        } else {
            if (timer_entry->p_next != NULL && timer_entry->p_next->p_prev == timer_entry)
                timer_entry->p_next->p_prev = timer_entry->p_prev;
            else
                return;
            if (timer_entry->p_prev != NULL && timer_entry->p_prev->p_next == timer_entry)
                timer_entry->p_prev->p_next = timer_entry->p_next;
            else
                return;
        }
    }

    timer_entry->p_next = timer_entry->p_prev = NULL;
    timer_entry->ticks = 0x80000000L;
    timer_entry->in_use = FALSE;
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

/* Shut down the GKI kernel: mark the PPC task dead and restore all nested interrupt-disable states. */
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

/* Post an event mask to a GKI task, taking the GKI interrupt lock around the update. */
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
    register u16 *var_r21;
    register u16 var_r16;
    register s32 var_r19 = 0;
    register u32 var_r23;
    register u8 *var_r22;
    register u8 var_r17;
    register u16 var_r18;
    register u8 *buf;
    register u16 offset;
    register u16 remaining;
    register u16 len;
    register u16 got;

    if (var_r15[0x1E] != 2) return 0;
    var_r16 = (u16)(arg0 + 1);
    var_r22 = arg1 + arg0;
    var_r23 = ((u32)arg0 << 2) & 0x3FFFC;
    var_r21 = (u16 *)(arg1 + (((u32)arg0 << 1) & 0x1FFFE));
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
        *(u16 *)(var_r21 + 6) = lbl_80560CF8[var_r22[0x14] - 1];
        /* fall through */
    case 1:
        buf = *(u8 **)(var_r15 + var_r23);
        offset = *(u16 *)(buf + 2);
        buf[offset + 8] = sp8;
        *(u16 *)(buf + 2) = offset + 1;
        if (--*(u16 *)(var_r21 + 6) == 0) {
            var_r18 = sp8;
            if (var_r22[0x14] == 2) {
                var_r18 = (u8)(((u16)sp8 << 8) + var_r22[0x17]);
                buf = (u8 *)l2cap_link_chk_pkt_start((BT_HDR *)buf);
                *(u8 **)(var_r15 + var_r23) = buf;
                if (buf == 0) {
                    *(u16 *)(var_r21 + 6) = var_r18;
                    if (var_r18 == 0) var_r22[0x1A] = 0;
                    else var_r22[0x1A] = 4;
                    break;
                }
            }
            *(u16 *)(var_r21 + 6) = var_r18;
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
        if ((*(u16 *)(var_r21 + 6) -= 1) == 0) {
            var_r18 = sp8;
            if (var_r22[0x14] == 2)
                var_r18 = (u8)(((u16)sp8 << 8) + var_r22[0x17]);
            *(u16 *)(var_r21 + 6) = var_r18;
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
        remaining = *(u16 *)(var_r21 + 6) - 1;
        *(u16 *)(var_r21 + 6) = remaining;
        got = ((u16 (*)(u8, u8 *, u16, u8, BT_HDR *))fn_8007011C)(
            (u8)var_r16, buf + *(u16 *)(buf + 2) + 8, remaining, sp8, (BT_HDR *)buf);
        var_r19 += got;
        buf = *(u8 **)(var_r15 + var_r23);
        *(u16 *)(buf + 2) = *(u16 *)(buf + 2) + got;
        remaining = *(u16 *)(var_r21 + 6) - got;
        *(u16 *)(var_r21 + 6) = remaining;
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
        if ((*(u16 *)(var_r21 + 6) -= 1) == 0) var_r22[0x1A] = 0;
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
#pragma push
#pragma use_lmw_stmw off
void hcisu_h2_send_msg_now(u8 *queue, s32 arg1) {
    u16 event = *(u16 *)arg1;
    u8 *msg = (u8 *)arg1;
    u8 *data, *base;
    u16 header_hi, header;
    u16 max_len, len;
    u8 channel;
    data = msg + *(u16 *)(msg + 4) + 8;
    if (event == 0x2100) {
        channel = 2;
    } else if (event == 0x2200) {
        channel = 3;
    } else if (event == 0x2000) {
        channel = 0;
    }
    if (event == 0x2100 && *(u16 *)(msg + 2) > *(u16 *)(lbl_803C0A50 + 0x7E)) {
        header = (u16)(data[0] + ((data[1] << 8) & 0xFF00));
        header = (header & 0xCFFF) | 0x1000;
        header_hi = header >> 8;
        data += 2;
        do {
            UUSB_Write(channel, data, event, (BT_HDR *)msg);
            len = *(u16 *)(msg + 2);
            *(u16 *)(msg + 4) += *(u16 *)(lbl_803C0A50 + 0x7C);
            base = msg + *(u16 *)(msg + 4);
            *(u16 *)(msg + 2) = len - *(u16 *)(lbl_803C0A50 + 0x7C);
            base[8] = header;
            base[9] = header_hi;
            data = base + 0xA;
            if (*(u16 *)(msg + 2) > *(u16 *)(lbl_803C0A50 + 0x7E)) {
                data[0] = *(u16 *)(lbl_803C0A50 + 0x7C);
                data[1] = *(u16 *)(lbl_803C0A50 + 0x7C) >> 8;
            } else {
                data[0] = *(u16 *)(msg + 2) - 4;
                data[1] = (*(u16 *)(msg + 2) - 4) >> 8;
            }
            data += 2;
            if (*(u16 *)(msg + 6) != 0 && --*(u16 *)(msg + 6) == 0) {
                *(u16 *)msg = 0x1900;
                GKI_send_msg(((u8 *)&lbl_803BD1A0)[0x1F], 0, (BT_HDR *)msg);
                return;
            }
            event = *(u16 *)(lbl_803C0A50 + 0x7E);
            len = *(u16 *)(msg + 2);
        } while (len > event);
    }
    UUSB_Write(channel, data, *(u16 *)(msg + 2), (BT_HDR *)msg);
    GKI_freebuf((BT_HDR *)msg);
}
#pragma pop
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

void uusb_CloseDeviceCB(s8 arg0) { register u8 *control = (u8 *)&lbl_803BD1E0; register u8 zero = 0; *(s32 *)&lbl_803BD1E0 = zero; control[0x10] = zero; control[0x11] = zero; control[0x12] = zero; control[0x13] = zero; lbl_8055DC50 = zero; fn_8009B0E0(); fn_8006EBAC(); control[0x28] = zero; control[0x29] = 5; lbl_8055DC51 = zero; fn_8006EB88(); if (*(void (**)(s32, s8))(control + 0x20) != 0) (*(void (**)(s32, s8))(control + 0x20))(4, arg0); }

void uusb_ReadIntrDataCB(s32 length, BT_HDR *buf) {
    extern char lbl_803BD240[];
    char *report = lbl_803142C8;
    BT_HDR *copy;
    s32 size, i;
    u32 zero;
    uusb_cb_t *control;
    u8 *p;
    if (lbl_803BD1E0.at_0x28) OSReport(report);
    zero = ((u8 *)&lbl_803BD1E0)[0x2B] = 0;
    if (lbl_803BD1E0.state != 2) {
        if (lbl_803BD1E0.at_0x28) OSReport(report + 0x28);
        if (lbl_803BD1E0.at_0x28) OSReport(report + 0x6c);
        GKI_freebuf(buf);
        GKI_delete_pool(((u8 *)&lbl_803BD1E0)[0x1c]);
        ((u8 *)&lbl_803BD1E0)[0x1c] = 0xff;
        return;
    }
    if ((u32)buf != zero) {
        if (length <= 0) {
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0xdc, length);
            GKI_freebuf(buf);
            return;
        }
        copy = GKI_getpoolbuf(2);
        if (copy == 0) {
            GKI_freebuf(buf);
            return;
        }
        buf->len = length;
        buf->event = 0x1000;
        size = (((u16)buf->len + buf->offset + 8) & ~3) + 4;
        memcpy(copy, buf, size);
        if (lbl_803BD1E0.at_0x28) OSReport(report + 0x114, copy->len, copy->offset, size);
        control = &lbl_803BD1E0;
        p = (u8 *)(copy + 1) + copy->offset;
        for (i = 0; i < length; i++, p++) {
            if (control->at_0x28) OSReport(lbl_80558FF8, *p);
        }
        if (lbl_803BD1E0.at_0x28) OSReport(lbl_80559000);
        OSSwitchFiberEx((u32)copy, 0, 0, 0, fn_80070844, lbl_803BD240 + 0x1000);
        GKI_freebuf(buf);
    }
    uusb_issue_intr_read();
}

extern char lbl_80558FF8[];
extern char lbl_80559000[];
void uusb_ReadBulkDataCB(s32 length, BT_HDR *buf) {
    s32 size, i;
    u8 *p;
    BT_HDR *copy;
    u32 zero = 0;
    char *report=lbl_803142C8;
    uusb_cb_t *control=&lbl_803BD1E0;
    if(control->state!=2) {
        if(control->at_0x28) OSReport(report+0x15c);
        if(lbl_803BD1E0.at_0x28) OSReport(report+0x1a0);
        GKI_freebuf(buf);
        GKI_delete_pool(((u8*)&lbl_803BD1E0)[0x1d]);
        ((u8*)&lbl_803BD1E0)[0x1d]=0xff;
        return;
    }
    if(length<=0) {
        if(control->at_0x28) OSReport(report+0x200,length);
        GKI_freebuf(buf);
    } else {
        buf->len=length;
        copy=GKI_getpoolbuf(3);
        if(copy==0) GKI_freebuf(buf);
        else {
            size=((buf->len+buf->offset+8)&~3)+4;
            memcpy(copy,buf,size);
            if(control->at_0x28) OSReport(report+0x238,copy->len,copy->offset,size);
            p=(u8*)(copy+1)+copy->offset;
            for(i=0;i<(s32)copy->len;i++,p++) {
                if(lbl_803BD1E0.at_0x28) OSReport(lbl_80558FF8,*p);
            }
            if(lbl_803BD1E0.at_0x28) OSReport(lbl_80559000);
            copy=l2cap_link_chk_pkt_start(copy);
            if((u32)copy != zero && (u8)l2cap_link_chk_pkt_end() != 0) {
                OSSwitchFiberEx((u32)copy,0,0,0,fn_80070844,lbl_803BE240+0x1000);
            }
            GKI_freebuf(buf);
        }
    }
    uusb_issue_bulk_read();
}

extern s32 IUSB_ReadBlkMsgAsync(s32, u32, u32, void *, void (*)(void), void *);
#pragma push
#pragma use_lmw_stmw off
void uusb_issue_bulk_read(void) {
    extern char lbl_803142C8[];
    extern void uusb_ReadBulkDataCB(s32, BT_HDR *);
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
                                  aligned, (void (*)(void))uusb_ReadBulkDataCB, buf);
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

#pragma push
#pragma use_lmw_stmw off
void uusb_issue_intr_read(void) {
    struct uusb_intr_cb_view {
        s32 fd;
        u8 pad04[0x0E];
        u8 endpoint;
        u8 pad13[0x09];
        u8 pool_id;
        u8 pad1D[0x0B];
        u8 at_0x28;
    } *control = (struct uusb_intr_cb_view *)&lbl_803BD1E0;
    extern char lbl_803142C8[];
    extern void uusb_ReadIntrDataCB(s32, BT_HDR *);
    extern u16 fn_8006D8D0(u32);
    register char *report = lbl_803142C8;
    register u8 *buf;
    register u8 *aligned;
    u16 header;
    s32 result;

    for (;;) {
        buf = GKI_getpoolbuf(control->pool_id);
        if (buf != 0) {
            break;
        }
        if (control->at_0x28 != 0) {
            OSReport(report + 0x378);
        }
    }

    *(u16 *)buf = 0x1000;
    aligned = (u8 *)(((u32)(buf + 0x27)) & ~31);
    *(u16 *)(buf + 2) = 0;
    header = (u16)(aligned - (buf + 8));
    *(u16 *)(buf + 4) = header;

    result = IUSB_ReadIntrMsgAsync(lbl_803BD1E0.fd, control->endpoint,
                                   fn_8006D8D0((u32)buf) - 0x28 - header,
                                   aligned, (void (*)(void))uusb_ReadIntrDataCB, buf);
    if (result != 0) {
        if (control->at_0x28 != 0) {
            OSReport(report + 0x3CC, result);
        }
        if (lbl_803BD1E0.at_0x28 != 0) {
            OSReport(report + 0x404, result);
        }
        GKI_freebuf(buf);
    }

    ((u8 *)&lbl_803BD1E0)[0x2B] = 1;
}

void uusb_WriteCtrlDataCB(s32 arg0, BT_HDR *arg1) {
    extern char lbl_803142C8[];
    extern s32 IUSB_WriteCtrlMsgAsync(s32, s32, s32, s32, s32, u32, void *, void *, void *);
    register s32 status = arg0;
    register char *report = lbl_803142C8;
    if (lbl_803BD1E0.at_0x28 != 0)
        OSReport(report + 0x460, status);
    if (status < 0 && lbl_803BD1E0.at_0x28 != 0)
        OSReport(report + 0x498, status);
    if (arg1 != 0) {
        GKI_freebuf(arg1);
        fn_8006EBAC();
        ((u8 *)&lbl_803BD1E0)[0x48] = ((u8 *)&lbl_803BD1E0)[0x48] - 1;
        fn_8006EB88();
    }
    {
        register u8 *control = (u8 *)&lbl_803BD1E0;
        if (control[0x48] < 5 && *(u16 *)(control + 0x44) != 0) {
            arg1 = GKI_dequeue((BUFFER_Q *)(control + 0x3C));
            if (IUSB_WriteCtrlMsgAsync(lbl_803BD1E0.fd, 0x20, 0, 0, 0, arg1->len, (u8 *)arg1 + arg1->offset + 8, (void *)uusb_WriteCtrlDataCB, (void *)arg1) < 0) {
                if (control[0x28] != 0)
                    OSReport(report + 0x4D0);
                GKI_enqueue_head((BUFFER_Q *)(control + 0x3C), arg1);
                return;
            }
            fn_8006EBAC();
            control[0x48] = control[0x48] + 1;
            fn_8006EB88();
        }
    }
}

void uusb_WriteBulkDataCB(s32 arg0, s32 arg1) {
    extern char lbl_803142C8[];
    extern s32 IUSB_WriteBlkMsgAsync(s32, u32, u32, void *, void (*)(void), void *);
    register int status = arg0;
    register const char *report = lbl_803142C8;
    u16 offset;
    if (lbl_803BD1E0.at_0x28 != 0) {
        OSReport((char *)report + 0x518, status);
    }
    if (status < 0 && lbl_803BD1E0.at_0x28 != 0) {
        OSReport((char *)report + 0x550, status);
    }
    if (arg1 != 0) {
        GKI_freebuf((void *)arg1);
        fn_8006EBAC();
        ((u8 *)&lbl_803BD1E0)[0x38] = ((u8 *)&lbl_803BD1E0)[0x38] - 1;
        fn_8006EB88();
    }
    {
        register u8 *control = (u8 *)&lbl_803BD1E0;
        if (control[0x38] < 5 && *(u16 *)(control + 0x34) != 0) {
            arg1 = (s32)GKI_dequeue((BUFFER_Q *)(control + 0x2C));
            offset = *(u16 *)((u8 *)arg1 + 4);
            if (IUSB_WriteBlkMsgAsync(lbl_803BD1E0.fd, control[0x10],
                                      *(u16 *)((u8 *)arg1 + 2),
                                      (u8 *)arg1 + offset + 8,
                                      (void (*)(void))uusb_WriteBulkDataCB, (void *)arg1) < 0) {
                if (control[0x28] != 0) {
                    OSReport((char *)report + 0x588);
                }
                GKI_enqueue_head((BUFFER_Q *)((u8 *)&lbl_803BD1E0 + 0x2C), (void *)arg1);
                return;
            }
            fn_8006EBAC();
            control[0x38] = control[0x38] + 1;
            fn_8006EB88();
        }
    }
}

#pragma pop

#pragma pop
extern s32 IUSB_OpenDeviceIds(const char *, u16, u16, s32 *);
extern char lbl_80314898[];
extern char lbl_803148F8[];
extern char lbl_80559004[4];
extern char lbl_80559008[4];
extern s32 lbl_80558FF4;
extern u32 lbl_8055DC54;
extern u32 lbl_8055DC58;
s32 uusb_get_devId(u32 vendorId, u32 productId) {
    /* Open a USB device by VID/PID on the selected host, store its fd on success, and log/report failures. */
    s32 deviceId;
    if (lbl_8055DC58 == 1) {
        if (lbl_8055DC54 == 0) {
            deviceId = IUSB_OpenDeviceIds(lbl_80559004, (u16)vendorId, (u16)productId, (s32 *)&lbl_803BD1E0);
        } else if (lbl_8055DC54 == 1) {
            deviceId = IUSB_OpenDeviceIds(lbl_80559008, (u16)vendorId, (u16)productId, (s32 *)&lbl_803BD1E0);
        }
    } else {
        deviceId = IUSB_OpenDeviceIds(lbl_80559008, (u16)vendorId, (u16)productId, (s32 *)&lbl_803BD1E0);
    }
    if (deviceId < 0) {
        if (lbl_803BD1E0.at_0x28 != 0) OSReport(lbl_80314898, deviceId, 0x57E, 0x305);
        if (lbl_803BD1E0.at_0x28 != 0) OSReport(lbl_803148F8);
    } else {
        lbl_80558FF4 = deviceId;
    }
    return deviceId;
}

void UUSB_Register(tUUSB *uusb) {
    extern u8 lbl_8055DC5C;
    extern s32 lbl_8055DC60;
    extern s32 lbl_8055DC64;
    extern s32 lbl_80558FF0;
    register char *report = lbl_803142C8;
    register u8 *c = (u8 *)&lbl_803BD1E0;
    u8 pool0;
    u8 pool1;

    memset(&lbl_803BD1E0, 0, 0x4C);
    fn_8006EBAC();
    c[0x29] = 5;
    fn_8006EB88();
    if (lbl_8055DC51 == 0) {
        c[0x28] = 0;
        lbl_8055DC51 = 1;
    }
    if (IPCCltInit() != 0) {
        if (lbl_803BD1E0.at_0x28 != 0) OSReport(report + 0x670);
        return;
    }
    if (IUSB_OpenLib() != 0) {
        if (lbl_803BD1E0.at_0x28 != 0) OSReport(report + 0x6A8);
        return;
    }
    *(tUUSB **)((u8 *)&lbl_803BD1E0 + 0x24) = uusb;
    if (lbl_8055DC5C == 1) {
        *(s32 *)((u8 *)&lbl_803BD1E0 + 0x14) = lbl_8055DC60;
        *(s32 *)((u8 *)&lbl_803BD1E0 + 0x18) = lbl_8055DC64;
    } else {
        *(s32 *)((u8 *)&lbl_803BD1E0 + 0x14) = 0x57E;
        *(s32 *)((u8 *)&lbl_803BD1E0 + 0x18) = 0x305;
    }
    c = (u8 *)&lbl_803BD1E0;
    c[0x10] = 0;
    c[0x11] = 0;
    c[0x12] = 0;
    c[0x13] = 0;
    if (uusb_get_devId(*(s32 *)(c + 0x14), *(s32 *)(c + 0x18)) < 0) {
        if (c[0x28] != 0) OSReport(report + 0x6E0);
        return;
    }
    if (lbl_803BD1E0.at_0x28 != 0) OSReport(report + 0x720, lbl_803BD1E0.fd);
    c = (u8 *)&lbl_803BD1E0;
    c[0x10] = 2;
    c[0x11] = 0x82;
    c[0x12] = 0x81;
    c[0x13] = 0;
    fn_8006D4C4(c + 0x2C);
    c[0x38] = 0;
    fn_8006D4C4(c + 0x3C);
    c[0x48] = 0;
    pool0 = GKI_create_pool(0x294, 0x2D, 1, 0);
    c[0x1C] = pool0;
    pool1 = GKI_create_pool(0x708, 0x1E, 1, 0);
    c[0x1D] = pool1;
    if (c[0x1C] == 0xFF || pool1 == 0xFF) {
        if (lbl_803BD1E0.at_0x28 != 0) OSReport(report + 0x768);
        return;
    }
    if (c[0x28] != 0) OSReport(report + 0x7A4);
    fn_8006EBAC();
    ((u8 *)&lbl_803BD1E0)[0x29] = 4;
    fn_8006EB88();
    lbl_80558FF0 = 1;
}

void UUSB_Open(tUUSB *uusb, void *callback) {
    extern char lbl_803142C8[];
    extern s32 lbl_80558FF0;
    register uusb_cb_t *controlBlock = &lbl_803BD1E0;
    register char *logBase = lbl_803142C8;
    u8 *controlBytes = (u8 *)controlBlock;

    /* Open the USB device: validate state/IDs, store callback, start I/O, reset counter. */
    if (controlBlock->state == 4) goto validate;
    if (controlBlock->at_0x28 != 0) OSReport(logBase + 0x7F0);
    goto done;

validate:
    if (controlBytes[0x1C] == 0xFF) goto bad_ids;
    if (controlBytes[0x1D] != 0xFF) goto open_device;

bad_ids:
    if (lbl_803BD1E0.at_0x28 != 0) OSReport(logBase + 0x838);
    if (lbl_803BD1E0.at_0x28 != 0) OSReport(logBase + 0x870, ((u8 *)&lbl_803BD1E0)[0x1C]);
    if (lbl_803BD1E0.at_0x28 != 0) OSReport(logBase + 0x8A0, ((u8 *)&lbl_803BD1E0)[0x1D]);
    goto done;

open_device:
    fn_8006EBAC();
    *(void **)(controlBytes + 0x20) = callback;
    controlBytes[0x29] = 2;
    fn_8006EB88();
    uusb_issue_intr_read();
    uusb_issue_bulk_read();
    lbl_80558FF0 = 0;

done:
    return;
}

s32 fn_8007011C(void) { return 0; }

u16 UUSB_Write(u8 arg0, u8 *arg1, u16 arg2, BT_HDR *arg3) {
    extern u16 fn_8006D8D0(u32);
    extern s32 IUSB_WriteCtrlMsgAsync(s32, s32, s32, s32, s32, u32, void *, void *, void *);
    extern s32 IUSB_WriteBlkMsgAsync(s32, u32, u32, void *, void (*)(void), void *);
    s32 ret = 0;
    char *report = lbl_803142C8;
    u16 i;
    BT_HDR *buf;
    u8 *data;
    uusb_cb_t *cb;
    if (((u8 *)&lbl_803BD1E0)[0x29] != 2) {
        if (lbl_803BD1E0.at_0x28) OSReport(report + 0x8d0);
        return 0;
    }
    if (lbl_803BD1E0.at_0x28) OSReport(report + 0x908, fn_8006D8D0((u32)arg3) - 8);
    if (lbl_803BD1E0.at_0x28) OSReport(report + 0x928, arg0, arg2);
    cb = &lbl_803BD1E0;
    for (i = 0; i < arg2; i++) {
        if (cb->at_0x28) OSReport(lbl_80558FF8, arg1[i]);
    }
    if (lbl_803BD1E0.at_0x28) OSReport(lbl_80559000);
    switch (arg0) {
    case 0:
        cb = &lbl_803BD1E0;
        buf = GKI_getpoolbuf(((u8 *)cb)[0x1c]);
        if (buf == 0) {
            if (cb->at_0x28) OSReport(report + 0x958);
            return 0;
        }
        buf->len = arg2;
        data = (u8 *)(((u32)buf + 0x27) & ~0x1F);
        buf->offset = data - ((u8 *)buf + 8);
        memcpy(data, arg1, arg2);
        if (((u8 *)cb)[0x48] < 5 && *(u16 *)((u8 *)cb + 0x44) == 0) {
            ret = IUSB_WriteCtrlMsgAsync(cb->fd, 0x20, 0, 0, 0, arg2, data, (void *)uusb_WriteCtrlDataCB, buf);
        } else {
            GKI_enqueue((BUFFER_Q *)((u8 *)&lbl_803BD1E0 + 0x3c), buf);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x99c, *(u16 *)((u8 *)&lbl_803BD1E0 + 0x44));
            return 0;
        }
        if (ret != 0) {
            if (cb->at_0x28) OSReport(report + 0x9d0);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x9d0);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0xa34, ret, ((u8 *)&lbl_803BD1E0)[0x48]);
            if (ret != -0x16 && lbl_803BD1E0.at_0x28) OSReport(report + 0xa90, ret, ((u8 *)&lbl_803BD1E0)[0x38]);
            if (ret == -8 && lbl_803BD1E0.at_0x28) OSReport(report + 0xb00, ret, ((u8 *)&lbl_803BD1E0)[0x38]);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x9d0);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x9d0);
            GKI_freebuf(buf);
        } else {
            fn_8006EBAC();
            ((u8 *)cb)[0x48]++;
            fn_8006EB88();
        }
        break;
    case 2:
        buf = GKI_getpoolbuf(((u8 *)&lbl_803BD1E0)[0x1d]);
        if (buf == 0) {
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0xb6c);
            return 0;
        }
        buf->len = arg2;
        data = (u8 *)(((u32)buf + 0x27) & ~0x1F);
        buf->offset = data - ((u8 *)buf + 8);
        memcpy(data, arg1, arg2);
        if (arg2 > 0xbe && lbl_803BD1E0.at_0x28) OSReport(report + 0xbb0);
        if (((u8 *)&lbl_803BD1E0)[0x38] < 5 && *(u16 *)((u8 *)&lbl_803BD1E0 + 0x34) == 0) {
            ret = IUSB_WriteBlkMsgAsync(lbl_803BD1E0.fd, ((u8 *)&lbl_803BD1E0)[0x10], arg2, data, (void (*)(void))uusb_WriteBulkDataCB, buf);
        } else {
            GKI_enqueue((BUFFER_Q *)((u8 *)&lbl_803BD1E0 + 0x2c), buf);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0xbdc, *(u16 *)((u8 *)&lbl_803BD1E0 + 0x34));
            return 0;
        }
        if (ret != 0) {
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x9d0);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x9d0);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0xc10, ret, ((u8 *)&lbl_803BD1E0)[0x38]);
            if (ret != -0x16 && lbl_803BD1E0.at_0x28) OSReport(report + 0xc6c, ret, ((u8 *)&lbl_803BD1E0)[0x38]);
            if (ret == -8 && lbl_803BD1E0.at_0x28) OSReport(report + 0xcdc, ret, ((u8 *)&lbl_803BD1E0)[0x38]);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x9d0);
            if (lbl_803BD1E0.at_0x28) OSReport(report + 0x9d0);
            GKI_freebuf(buf);
        } else {
            fn_8006EBAC();
            ((u8 *)&lbl_803BD1E0)[0x38]++;
            fn_8006EB88();
        }
        break;
    }
    return ret;
}

void UUSB_Close(void *arg0) {
    extern s32 IUSB_CloseDeviceAsync(s32, void (*)(void), void *);
    fn_8006EBAC();
    {
        u32 base = (u32)&lbl_803BD1E0;
        *(u8 *)(base + 0x29) = 0;
        fn_8006EB88();
        if (*(u16 *)(base + 0x34) != 0) {
            while (*(u16 *)(base + 0x34) != 0) {
                GKI_freebuf(GKI_dequeue((BUFFER_Q *)(base + 0x2C)));
            }
        }
        base = (u32)&lbl_803BD1E0;
        if (*(u16 *)(base + 0x44) != 0) {
            while (*(u16 *)(base + 0x44) != 0) {
                GKI_freebuf(GKI_dequeue((BUFFER_Q *)(base + 0x3C)));
            }
        }
    }
    IUSB_CloseDeviceAsync(lbl_803BD1E0.fd, (void (*)(void))uusb_CloseDeviceCB, 0);
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
    // Formats a variadic trace message into the shared log buffer and reports it.
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
    u64 now;
    u32 hi;
    u32 lo;
    lbl_8055DC74 = 0;
    GKI_init();
    fn_8006EB88();
    fn_80082548();
    lbl_8055DC6C = &lbl_80559048;
    lbl_8055DC68 = (hcisu_if *)lbl_802EE8D8;
    ((void (*)(unsigned int, void *))bte_hcisu_task)(0u, lbl_802EE8D8);
    goto wait_check;
wait_delay:
    ((void (*)(s32))fn_8006EAD8)(100);
wait_check:
    if (lbl_80558FF0 != 0) {
        goto wait_delay;
    }
    fn_80070B54();
    now = __OSGetSystemTime();
    hi = (u32)(now >> 32u);
    lo = (u32)now;
    OSCreateAlarm(&lbl_803C0A20);
    ((void (*)(void *, u32, u32, u32, u32, u32, void (*)(void)))OSSetPeriodicAlarm)(
        &lbl_803C0A20, 0x80000000u, hi, lo, 0u,
        ((*(u32 *)0x800000F8 >> 2) / 500u) & 0x07FFFFFEu, fn_800709E4);
    ((void (*)(s32))fn_8006EACC)(0);
    goto poll_check;
poll_delay:
    ((void (*)(s32))fn_8006EAD8)(2000);
poll_check:
    if (fn_80073B30() == 0u) {
        goto poll_delay;
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

/*
 * The BTU (Bluetooth Upper Layers) control block, a tBTU_CB as described by
 * revolution/BTE/stack/include/btu.h:
 *
 *   0x00  tBTU_TIMER_REG  timer_reg[BTU_MAX_REG_TIMER]  { p_tle, timer_cb }
 *   0x10  tBTU_EVENT_REG  event_reg[BTU_MAX_REG_EVENT]  { event_range, event_cb }
 *   0x40  TIMER_LIST_Q    timer_queue                   (1 second per tick)
 *
 * The rest of the block (HCI buffer sizes, command queue) is used by
 * btu_hcif_send_cmd() and btm_read_hci_buf_size_complete().
 */
#define btu_cb                  lbl_803C0A50
#define btu_cb_timer_reg(i)     (btu_cb + (i) * 8)          /* tBTU_TIMER_REG  */
#define btu_cb_event_reg(i)     (btu_cb + 0x10 + (i) * 8)   /* tBTU_EVENT_REG  */
#define btu_cb_timer_queue      ((TIMER_LIST_Q *)(btu_cb + 0x40))

/* callback types of btu.h */
typedef void (*tBTU_TIMER_CALLBACK)(TIMER_LIST_ENT *p_tle);
typedef void (*tBTU_EVENT_CALLBACK)(BT_HDR *p_hdr);

#define BTU_MAX_REG_TIMER       2   /* max # timer callbacks which may register */
#define BTU_MAX_REG_EVENT       6   /* max # event callbacks which may register */

/* The BTU task's own state, kept next to the fiber it runs in. */
#define btu_task_dropped_ticks  lbl_80559050 /* alarm ticks lost while the fiber ran */
#define btu_task_is_idle        lbl_80559054 /* TRUE while the fiber is not running */
#define btu_task_ticks          lbl_8055DC78 /* alarm ticks; 500 of them are a second */
#define btu_task_second_tick    lbl_8055DC7C /* tick the last second of work ran on */

/* Timer types held in btu_cb.timer_queue, named as in btu.h. This stack still
   numbers the HCI command complete timeout 60, and has no handler for type 8. */
#define BTU_TTYPE_BTM_DEV_CTL       1
#define BTU_TTYPE_L2CAP_LINK        2
#define BTU_TTYPE_L2CAP_CHNL        3
#define BTU_TTYPE_L2CAP_HOLD        4
#define BTU_TTYPE_SDP               5
#define BTU_TTYPE_BTM_ACL           9
#define BTU_TTYPE_BTM_RMT_NAME      10
#define BTU_TTYPE_RFCOMM_MFC        11
#define BTU_TTYPE_RFCOMM_PORT       12
#define BTU_TTYPE_USER_FUNC         22
#define BTU_TTYPE_BTU_CMD_CMPL      60
#define BTU_TTYPE_HID_HOST_REPAGE_TO 66

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
/*
 * The body of the Bluetooth Upper Layers (BTU) task.
 *
 * The periodic alarm the BTE task installs switches into a fiber running this
 * function 500 times a second.  Every call drains the HCI receive mailbox
 * (ACL data to L2CAP, HCI events and commands to the transport, and anything
 * else into the event ranges layers registered in btu_cb) and the BTA
 * mailbox; every 500 ticks - one second - it also advances the BTU timer
 * queue by a tick and dispatches the timers that expired, then updates the
 * BTA protocol timers.  The work to do is kept in GKI event mask bits, and
 * APPL_EVT_7 stops the loop when the stack is shut down.
 */
void btu_task_msg_handler(void) {
    extern unsigned char btu_cb[];
    UINT32 event;
    TIMER_LIST_ENT *p_tle;
    BT_HDR *p_msg;
    UINT16 events;
    UINT8 j;
    UINT8 i;
    int done = 0;
    int handled;
    tBTU_TIMER_CALLBACK timer_cb;
    unsigned char *p_timer_reg;
    int timer_handled;
    extern void l2c_rcv_acl_data(BT_HDR *);
    extern void l2c_link_segments_xmitted(BT_HDR *);
    extern void btu_hcif_process_event(BT_HDR *);
    extern int btu_hcif_send_cmd();
    extern void l2c_process_timeout(void *);
    extern void btu_hcif_cmd_timeout(void);
    extern void hidh_proc_repage_timeout(TIMER_LIST_ENT *);
    extern void bta_sys_event(BT_HDR *);
    extern void fn_8007DEF4(void *);       /* SCO data: freed straight away */
    extern void fn_8007C794(void);         /* remote name request timed out */
    extern void fn_8007AD38(void);         /* timer type 8: nothing to do */
    extern void fn_80095518(void *);       /* RFCOMM MFC / port timeout */
    extern void fn_8007141C(void);         /* bta_sys_timer_update() */
    extern void sdp_conn_timeout(tCONN_CB *);

    OSGetTime();
    btu_task_ticks++;
    fn_8006EBAC();                         /* GKI_disable() */
    if (btu_task_is_idle) {
        btu_task_is_idle = 0;              /* the fiber is running now */
        btu_task_dropped_ticks = 1;
    } else {
        btu_task_dropped_ticks++;          /* the alarm outran the task */
        fn_8006EB88();                     /* GKI_enable() */
        return;
    }
    fn_8006EB88();                         /* GKI_enable() */

    events = TASK_MBOX_0_EVT_MASK | TASK_MBOX_2_EVT_MASK;
    if ((UINT32)btu_task_ticks > (UINT32)(btu_task_second_tick + 500)) {
        btu_task_second_tick = btu_task_ticks;
        events |= TIMER_0_EVT_MASK | TIMER_1_EVT_MASK;    /* a second went by */
    }

    while (!done) {
        done = 1;

        /* buffers sent to the BTU task by the HCI layer */
        if (events & TASK_MBOX_0_EVT_MASK) {
            while ((p_msg = GKI_read_mbox(TASK_MBOX_0)) != 0) {
                done = 0;
                event = p_msg->event & BT_EVT_MASK;
                switch (event) {
                case BT_EVT_TO_BTU_HCI_ACL:
                    l2c_rcv_acl_data(p_msg);
                    break;
                case BT_EVT_TO_BTU_L2C_SEG_XMIT:
                    l2c_link_segments_xmitted(p_msg);
                    break;
                case BT_EVT_TO_BTU_HCI_SCO:
                    fn_8007DEF4(p_msg);
                    break;
                case BT_EVT_TO_BTU_HCI_EVT:
                    btu_hcif_process_event(p_msg);
                    GKI_freebuf(p_msg);
                    break;
                case BT_EVT_TO_BTU_HCI_CMD:
                    btu_hcif_send_cmd(p_msg);
                    break;
                default:
                    /* anything else goes to the registered event ranges */
                    for (i = 0, handled = 0; !handled && i < BTU_MAX_REG_EVENT; i++) {
                        unsigned char *p_event_reg = btu_cb_event_reg(i);
                        tBTU_EVENT_CALLBACK event_cb = *(tBTU_EVENT_CALLBACK *)(p_event_reg + 4);
                        if (event_cb && event == *(UINT16 *)p_event_reg) {
                            if (event_cb) {
                                event_cb(p_msg);
                                handled = 1;
                            }
                        }
                    }
                    if (!handled) {
                        GKI_freebuf(p_msg);
                    }
                    break;
                }
            }
        }

        /* the timers of the transport and of the layers above it */
        if (events & TIMER_0_EVT_MASK) {
            GKI_update_timer_list(btu_cb_timer_queue, 1);
            events &= ~TIMER_0_EVT_MASK;
            while ((p_tle = btu_cb_timer_queue->p_first) != 0 && p_tle->ticks == 0) {
                done = 0;
                GKI_remove_from_timer_list(btu_cb_timer_queue, p_tle);
                switch (p_tle->event) {
                case BTU_TTYPE_BTM_DEV_CTL:
                    btm_dev_timeout(p_tle);
                    break;
                case BTU_TTYPE_BTM_ACL:
                    btm_acl_timeout(p_tle);
                    break;
                case BTU_TTYPE_L2CAP_LINK:
                case BTU_TTYPE_L2CAP_CHNL:
                case BTU_TTYPE_L2CAP_HOLD:
                    l2c_process_timeout(p_tle);
                    break;
                case BTU_TTYPE_SDP:
                    sdp_conn_timeout((tCONN_CB *)p_tle->param);
                    break;
                case BTU_TTYPE_BTM_RMT_NAME:
                    fn_8007C794();
                    break;
                case 8:
                    fn_8007AD38();
                    break;
                case BTU_TTYPE_RFCOMM_MFC:
                case BTU_TTYPE_RFCOMM_PORT:
                    fn_80095518(p_tle);
                    break;
                case BTU_TTYPE_BTU_CMD_CMPL:
                    btu_hcif_cmd_timeout();
                    break;
                case BTU_TTYPE_HID_HOST_REPAGE_TO:
                    hidh_proc_repage_timeout(p_tle);
                    break;
                case BTU_TTYPE_USER_FUNC:
                    ((tBTU_TIMER_CALLBACK)p_tle->param)(p_tle);
                    break;
                default:
                    /* or to a timer another layer registered in btu_cb */
                    for (j = 0, timer_handled = 0; !timer_handled && j < BTU_MAX_REG_TIMER; j++) {
                        p_timer_reg = btu_cb_timer_reg(j);
                        timer_cb = *(tBTU_TIMER_CALLBACK *)(p_timer_reg + 4);
                        if (timer_cb && *(TIMER_LIST_ENT **)p_timer_reg == p_tle) {
                            timer_cb(p_tle);
                            timer_handled = 1;
                        }
                    }
                    break;
                }
            }
        }

        /* events of the application (BTA) layer */
        if (events & TASK_MBOX_2_EVT_MASK) {
            while ((p_msg = GKI_read_mbox(TASK_MBOX_2)) != 0) {
                done = 0;
                bta_sys_event(p_msg);
            }
        }

        if (events & TIMER_1_EVT_MASK) {
            events &= ~TIMER_1_EVT_MASK;
            fn_8007141C();                 /* bta_sys_timer_update() */
        }

        if (events & EVENT_MASK(APPL_EVT_7)) {
            break;                         /* the stack is being shut down */
        }
    }

    btu_task_is_idle = 1;
}

void btu_start_timer(void *p_tle, UINT16 event, UINT32 timeout) {
    GKI_remove_from_timer_list((TIMER_LIST_Q *)&lbl_803C0A50[0x40], (TIMER_LIST_ENT *)p_tle);
    ((TIMER_LIST_ENT *)p_tle)->event = event;
    ((TIMER_LIST_ENT *)p_tle)->ticks = (INT32)timeout;
    GKI_add_to_timer_list((TIMER_LIST_Q *)&lbl_803C0A50[0x40], (TIMER_LIST_ENT *)p_tle);
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
    int i;
    for (i = 0; i < 6; i++) {
        if (arg0[i] != arg1[i]) return -1;
    }
    return 0;
}

void fn_80071078(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x80) = arg0; }

void fn_80071088(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x88) = arg0; }

void fn_80071098(s32 arg0) { *(s32 *)(lbl_803C0AD8 + 0x84) = arg0; }

typedef void (*tConnOpenCb)(u8, u8, u16);
/* Notify registered BTA system connection-open callbacks (event 0) with the given id/app/peer. */
void bta_sys_conn_open(s32 id, s32 app_id, s32 peer_addr) {
    typedef void (*tConnOpenCb2)(s32, s32, s32, s32);
    tConnOpenCb2 *callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x80 / 4] != 0) callbacks[0x80 / 4](0, id, app_id, peer_addr);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x84 / 4] != 0) callbacks[0x84 / 4](0, id, app_id, peer_addr);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x88 / 4] != 0) callbacks[0x88 / 4](0, id, app_id, peer_addr);
}

void bta_sys_conn_open_8007116C(s32 connId, s32 param1, s32 param2) {
    /* Notifies registered BTA system connection-open callbacks (at offsets 0x80/0x84/0x88 in lbl_803C0AD8) with event=1. */
    typedef void (*tConnOpenCb2)(s32, s32, s32, s32);
    tConnOpenCb2 *callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x80 / 4] != 0) callbacks[0x80 / 4](1, connId, param1, param2);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x84 / 4] != 0) callbacks[0x84 / 4](1, connId, param1, param2);
    callbacks = (tConnOpenCb2 *)lbl_803C0AD8;
    if (callbacks[0x88 / 4] != 0) callbacks[0x88 / 4](1, connId, param1, param2);
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

/* Dispatches a BTA system event to the registered handler for its subsystem id, or frees it if unhandled/disabled. */
void bta_sys_event(BT_HDR *msg) {
    extern char lbl_80315010[];
    extern char lbl_80315024[];
    extern u8 lbl_803C0AD8[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_80073A00(void);
    u8 subsystemId;
    u8 shouldFree = 1;

    if (lbl_8055DC80 >= 4)
        fn_80070954(0x503, lbl_80315010, msg->event);
    subsystemId = msg->event >> 8;
    /* lbl_803C0AD8+0x7E: system disabled flag */
    if (lbl_803C0AD8[0x7E] != 0) {
        if (msg->event == 0x101)
            fn_80073A00();
        GKI_freebuf(msg);
        return;
    }
    if (subsystemId < 0x1A && *(void **)(lbl_803C0AD8 + subsystemId * 4) != 0) {
        void *handlerReg = *(void **)(lbl_803C0AD8 + subsystemId * 4);
        shouldFree = ((u8 (*)(BT_HDR *))*(void **)handlerReg)(msg);
    } else if (lbl_8055DC80 >= 2) {
        fn_80070954(0x501, lbl_80315024, subsystemId);
    }
    if (shouldFree)
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

extern char lbl_80315088[];
extern int strncpy(char *, const char *, unsigned int);
extern u32 lbl_802EE9C0[];
u8 bta_dm_authorize_cback(const void *bd_addr, const void *dev_class, const char *bd_name,
                         u8 *service_name, u8 service_id, int is_originator) {
    /* Build a security-authorize event (copy BD addr, copy name, map service_id
     * to an index) and, if a DM callback is registered, dispatch event 4 and
     * return 1; otherwise return 0xB (not authorized/handled). */
    u8 sec_event[0x110];
    u8 service_index = 1;
    u32 (*dm_callback)(u32, void *);

    fn_80070FA4(sec_event, bd_addr);
    strncpy((char *)sec_event + 0x06, bd_name, 0x20);
    while (service_index < 0x18) {
        if (lbl_802EE9C0[service_index] == service_id) {
            sec_event[0xFE] = service_index;
            break;
        }
        service_index++;
    }
    dm_callback = *(u32 (**)(u32, void *))(lbl_803C0C14 + 0x50);
    if (dm_callback != 0 && service_index <= 0x17) {
        dm_callback(4, sec_event);
        return 1;
    }
    return 0xB;
}

/* bta_dm_cb, the BTA Device Manager control block.  The SDK name belongs to the
 * unbuilt reference source src/revolution/BTE/bta/dm/bta_dm_act.c, so its
 * fields are reached through these.  A PIN request for a peer whose name is not
 * known saves the address, class of device and PIN numeric here while BTM looks
 * the name up; bta_dm_pinname_cback is what BTM then calls back. */
#define bta_dm_cb_p_sec_cback   (*(tBTA_DM_SEC_CBACK **)(lbl_803C0C14 + 0x50)) /* the registered DM callback */
#define bta_dm_cb_pin_bd_addr   (lbl_803C0C14 + 0xF8)   /* pin_bd_addr */
#define bta_dm_cb_pin_dev_class (lbl_803C0C14 + 0xFE)   /* pin_dev_class */
/* bdcpy() of bd.h: the six byte BD_ADDR copy. */
#define bdcpy fn_80070FA4
/* This build's BD_NAME_LEN (the reference headers say 248): a device name in a
 * DM security event is this long, the terminating NUL included. */
#define DM_BD_NAME_LEN 0x21
#define BTA_DM_PIN_REQ_EVT 2 /* tBTA_DM_SEC_EVT of bta_api.h, which is not included here */
/* The part of tBTA_DM_SEC - the union of the DM security event data - that the
 * PIN-request path fills; the rest of the 0x108 byte event belongs to the other
 * members of that union. */
typedef struct {
    BD_ADDR   bd_addr;                 /* 0x00 peer address */
    u8        bd_name[DM_BD_NAME_LEN]; /* 0x06 peer name, NUL-terminated */
    u8        pad_27[0xFE - 0x27];
    DEV_CLASS dev_class;               /* 0xFE peer class of device */
    u8        pad_101[0x108 - 0x101];
} tDmSecEvent;
/* The security callback an upper layer registers with the Device Manager.  The
 * SDK calls it (event, &event data); the game's code loads it through the
 * control block and keeps that in a register for the call, so the block travels
 * as a third argument here to match what the compiler did. */
typedef void (tBTA_DM_SEC_CBACK)(int event, void *p_sec_event, void *p_dm_cb);
void bta_dm_pinname_cback(tBTM_REMOTE_DEV_NAME *p_result) {
    tDmSecEvent sec_event;
    u16 len;
    u32 bytes_to_copy;
    u8 *dst;
    const u8 *src;
    tBTA_DM_SEC_CBACK *p_sec_cback;

    /* BTM's answer to the remote name request the Device Manager started for a
     * PIN request: fill the security event with the peer address, class of
     * device and PIN numeric saved for it, add the name BTM found - or an empty
     * one when there is none - and report BTA_DM_PIN_REQ_EVT to the registered
     * security callback. */
    bdcpy(sec_event.bd_addr, bta_dm_cb_pin_bd_addr);
    sec_event.dev_class[0] = bta_dm_cb_pin_dev_class[0];
    sec_event.dev_class[1] = bta_dm_cb_pin_dev_class[1];
    sec_event.dev_class[2] = bta_dm_cb_pin_dev_class[2];
    if (p_result != 0 && p_result->status == BTM_SUCCESS) {
        len = p_result->length;
        dst = sec_event.bd_name;
        src = p_result->remote_bd_name;
        bytes_to_copy = DM_BD_NAME_LEN - 1;
        if (len < DM_BD_NAME_LEN - 1) bytes_to_copy = len;
        memcpy(dst, src, bytes_to_copy);
        sec_event.bd_name[DM_BD_NAME_LEN - 1] = 0;
    } else {
        sec_event.bd_name[0] = 0;
    }
    p_sec_cback = bta_dm_cb_p_sec_cback;
    p_sec_cback(BTA_DM_PIN_REQ_EVT, &sec_event, lbl_803C0C14);
}

/* Handle a PIN code request: if no device name is known, cache the request and
 * ask BTM for the remote name; otherwise deliver the PIN event to the DM callback. */
u8 bta_dm_pin_cback(u8 *bd_addr, u8 *pin_info, u8 *pin_name) {
    u8 sec_event[0x110];

    if (*(void **)(lbl_803C0C14 + 0x50) == 0)
        return 0xB;

    if (pin_name[0] == 0) {
        fn_80070FA4(lbl_803C0C14 + 0xF8, bd_addr);
        lbl_803C0C14[0xFE] = pin_info[0];
        lbl_803C0C14[0xFF] = pin_info[1];
        lbl_803C0C14[0x100] = pin_info[2];

        if (BTM_ReadRemoteDeviceName(bd_addr, (tBTM_CMPL_CB *)bta_dm_pinname_cback) == 1)
            return 1;

        if (lbl_8055DC80 >= 2)
            fn_8007093C(0x501, lbl_80315088);
    }

    fn_80070FA4(sec_event, bd_addr);
    sec_event[0xFE] = pin_info[0];
    sec_event[0xFF] = pin_info[1];
    sec_event[0x100] = pin_info[2];
    strncpy((char *)sec_event + 6, (const char *)pin_name, 0x20);
    sec_event[0x26] = 0;
    (*(void (**)(int, void *))(lbl_803C0C14 + 0x50))(2, sec_event);

    return 1;
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
void bta_dm_signal_strength_timer_cback(void *timerEnt) {
    u8 deviceIndex;
    u16 timeout;

    /* Poll RSSI and/or link quality for connected devices, then reschedule the timer if configured. */
    if (lbl_803C0C14[0x6C] & 1) {
        for (deviceIndex = 0; deviceIndex < lbl_803C0C14[0x4D]; deviceIndex++) {
            BTM_ReadRSSI(lbl_803C0C14 + deviceIndex * 0xB, (tBTM_CMPL_CB *)bta_dm_rssi_cback);
        }
    }
    if (lbl_803C0C14[0x6C] & 2) {
        for (deviceIndex = 0; deviceIndex < lbl_803C0C14[0x4D]; deviceIndex++) {
            BTM_ReadLinkQuality(lbl_803C0C14 + deviceIndex * 0xB, (tBTM_CMPL_CB *)bta_dm_link_quality_cback);
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

extern u8 lbl_803150C8[];
extern u8 fn_80077DD8(void);
extern void bta_dm_discover_next_device(void);
extern void fn_80073464(void);
void bta_dm_acl_change(u8 *arg0) {
    u8 *bd = arg0 + 0xB;
    u8 idx;
    u8 sp[0x110];
    u8 *entry;

    if (arg0[0xA] != 0) {
        for (idx = 0; idx < lbl_803C0C14[0x4D]; idx++) {
            if (bdcmp(lbl_803C0C14 + idx * 0xB, bd) == 0)
                break;
        }
        if (idx == lbl_803C0C14[0x4D]) {
            fn_80070FA4(lbl_803C0C14 + lbl_803C0C14[0x4D] * 0xB, bd);
            lbl_803C0C14[0x4D]++;
        }
        entry = lbl_803C0C14 + idx * 0xB;
        entry[6] = 1;
        entry[7] = 0;
        fn_80070FA4(sp, bd);
        ((void (*)(int, void *))(*(void **)(lbl_803C0C14 + 0x50)))(5, sp);
        return;
    }
    for (idx = 0; idx < lbl_803C0C14[0x4D]; idx++) {
        if (bdcmp(lbl_803C0C14 + idx * 0xB, bd) == 0)
            break;
    }
    if (idx < lbl_803C0C14[0x4D]) {
        u8 j = idx;
        for (; j < lbl_803C0C14[0x4D]; j++) {
            memcpy(lbl_803C0C14 + j * 0xB, lbl_803C0C14 + (j + 1) * 0xB, 0xB);
        }
    }
    lbl_803C0C14[0x4D]--;
    if (lbl_803C0B98[0x78] != 0 && bdcmp(lbl_803C0B98 + 0x1A, bd) == 0) {
        lbl_803C0B98[0x78] = 0;
        if (lbl_803C0B98[0x79] != 0) {
            if (lbl_8055DC80 >= 4)
                fn_8007093C(0x503, lbl_803150C8);
            fn_8007148C((s32)(lbl_803C0B98 + 0x40));
            bta_dm_discover_next_device();
        }
    }
    if (lbl_803C0C14[0x72] != 0 && BTM_GetNumAclLinks() == 0) {
        lbl_803C0C14[0x72] = 0;
        fn_8007148C((s32)(lbl_803C0C14 + 0x74));
        *(void **)(lbl_803C0C14 + 0x7C) = fn_80073464;
        fn_8007146C((s32)(lbl_803C0C14 + 0x74), 0, 0x3E8);
    }
    fn_80070FA4(sp, bd);
    sp[6] = fn_80077DD8();
    ((void (*)(int, void *))(*(void **)(lbl_803C0C14 + 0x50)))(6, sp);
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
// Looks up a BTA DM L2CAP server entry by BD address and forwards the compress callback for its BTA ID.
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

void bta_dm_compress_cback(s32 event, u8 service, u8 id, s32 addr) {
    extern u8 *lbl_80559014;
    extern u8 lbl_803C0B68[];
    extern char lbl_8031510C[], lbl_80315148[];
    int found;
    u8 k, j, i;
    u8 *table;
    u8 *entry, *slot;
    if (event == 0) {
        table = lbl_80559014;
        for (i = 1; i <= table[1]; i++) {
            entry = table + i * 3;
            if ((id == entry[1] || entry[1] == 0xff) && service == entry[0] && entry[2] == 1) {
                u8 count = *(volatile u8 *)(table + 1);
                found = 0;
                for (j = 1; j <= count; j++) {
                    if (table[j * 3 + 2] == 2) {
                        for (k = 0; k < lbl_803C0D18[0]; k++) {
                            if (lbl_803C0D18[k * 9 + 7] == table[j * 3]) found = 1;
                        }
                    }
                }
                if (!found) {
                    int offset;
                    u8 *base;
                    u8 *current;
                    base = lbl_803C0B68;
                    offset = ((int)i - 1) * 9;
                    current = base + offset;
                    current[7] = id;
                    current[6] = service;
                    fn_80070FA4(current, (void *)addr);
                    current[8] = 1;
                    if (lbl_8055DC80 >= 4)
                        ((void (*)(u32, void *, u8, u8, u8))fn_80070984)(0x503, lbl_8031510C, base[offset + 7], base[offset + 6], base[offset + 8]);
                }
                return;
            }
        }
    } else if ((u32)event == 1) {
        table = lbl_80559014;
        for (i = 1; i <= table[1]; i++) {
            entry = table + i * 3;
            if ((id == entry[1] || entry[1] == 0xff) && service == entry[0]) {
                slot = lbl_803C0B68 + (i - 1) * 9;
                slot[8] = 0;
                if (lbl_8055DC80 >= 4)
                    ((void (*)(u32, void *, u8, u8, u8))fn_80070984)(0x503, lbl_80315148, slot[7], slot[6], slot[8]);
                return;
            }
        }
    }
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
                if ((addr == config[((u32)j << 2) - (u32)j + 1] || config[((u32)j << 2) - (u32)j + 1] == 0xFF) &&
                    addr_type == config[((u32)j << 2) - (u32)j]) {
                    if (config[((u32)j << 2) - (u32)j + 2] > lbl_803C0C14[(u32)i * 0xB + 7])
                        lbl_803C0C14[(u32)i * 0xB + 7] = config[((u32)j << 2) - (u32)j + 2];
                    return;
                }
            }
            return;
        }
    }
}

extern const BD_ADDR BT_BD_ANY; void bta_dm_keep_acl(void *arg0) { u16 timeout = *(u16 *)((u8 *)arg0 + 6); lbl_803C0C14[0x101] = timeout; if ((u8)timeout != 0) { L2CA_SetIdleTimeoutByBdAddr((UINT8 *)BT_BD_ANY, 0xFFFF); L2CA_SetIdleTimeout(0, 0xFFFF, TRUE); } else { L2CA_SetIdleTimeoutByBdAddr((UINT8 *)BT_BD_ANY, 2); L2CA_SetIdleTimeout(0, 2, TRUE); } }

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

void BTA_DmSetVisibility(u8 arg0, u8 arg1) {
    void *buf = GKI_getbuf(0x110);
    if (buf != 0) {
        *(u16 *)buf = 0x103;
        *((u8 *)buf + 8) = arg0;
        *((u8 *)buf + 9) = arg1;
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
    memset(service_mask, 0, sizeof(service_mask));
    if (is_trusted != 0) {
        do {
            bit = 1u << index;
            if ((trusted_mask & bit) != 0u) {
                trusted_mask &= ~bit;
                mapped = lbl_802EE9C0[index];
                offset = (mapped >> 3) & 0x3FCu;
                bit_index = mapped - (mapped & 0x1FE0u);
                *(u32 *)((u8 *)service_mask + offset) |= 1u << bit_index;
            }
            ++index;
        } while (trusted_mask != 0u && index < 0x17u);
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

/* BTA device manager, DM search state machine (SDK bta_dm_main.c).
 * bta_dm_search_st_tbl holds one table per search state (idle, search active,
 * search cancelling, discover active); every row of a table is the event's two
 * action indices into bta_dm_search_action[] followed by the next state.
 * The SDK spells these bta_dm_search_cb / bta_dm_search_st_tbl /
 * bta_dm_search_action, names the reference sources already use, so alias them
 * to the labels this unit was given. */
#define bta_dm_search_st_tbl                    lbl_802EEB50
#define bta_dm_search_action                    lbl_802EEA98

/* state table layout */
#define BTA_DM_SEARCH_NUM_COLS                  3   /* columns of a state table row */
#define BTA_DM_SEARCH_ACTIONS                   2   /* action columns of a state table row */
#define BTA_DM_SEARCH_NEXT_STATE                2   /* row column holding the next state */
#define BTA_DM_SEARCH_IGNORE                    18  /* BTA_DM_SEARCH_NUM_ACTIONS: no action */

/* bta_dm_search_cb.state */
#define DM_SCB_STATE                            (*(u16 *)(lbl_803C0B98 + 0x18))

/* type for action functions, and for one state table */
typedef void (*tBTA_DM_ACTION)(BT_HDR *p_data);
typedef const u8 (*tBTA_DM_ST_TBL)[BTA_DM_SEARCH_NUM_COLS];

extern const tBTA_DM_ST_TBL bta_dm_search_st_tbl[];
extern const tBTA_DM_ACTION bta_dm_search_action[];

/* Run the DM search state machine for one event: look up the table of the
 * current state, take the next state from the event's row, then call the row's
 * action functions until the first BTA_DM_SEARCH_IGNORE. */
BOOLEAN bta_dm_search_sm_execute(BT_HDR *p_msg) {
    tBTA_DM_ST_TBL state_table;
    u8 action;
    int i;

    /* look up the state table for the current state */
    state_table = bta_dm_search_st_tbl[DM_SCB_STATE];
    DM_SCB_STATE = state_table[p_msg->event & 0xFF][BTA_DM_SEARCH_NEXT_STATE];

    /* execute action functions */
    for (i = 0; i < BTA_DM_SEARCH_ACTIONS; i++) {
        if ((action = state_table[p_msg->event & 0xFF][i]) != BTA_DM_SEARCH_IGNORE) {
            bta_dm_search_action[action](p_msg);
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
    u8 k;
    u32 offset;
    u32 toff;
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
        if (id == entry[0] && (entry[1] == 0xFF || app_id == entry[1]))
            break;
    }
    if (i > cfg[1])
        return;

    conn = lbl_803C0C14;
    for (k = 0; k < 3; k++) {
        toff = k << 5;
        entry = conn + toff;
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
        if (id == entry[7] && app_id == entry[8] && bdcmp(entry + 1, peer_addr) == 0)
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
        if (bdcmp(((u8 (*)[0xB])lbl_803C0C14)[i], peer_addr) != 0)
            continue;
        p_peer_device = ((u8 (*)[0xB])lbl_803C0C14)[i];
        failed_pm = p_peer_device[0xA];
        break;
    }
    if (p_peer_device == 0)
        return;

    for (j = 0; j < lbl_803C0D18[0]; j++) {
        if (bdcmp(((u8 (*)[9])lbl_803C0D18)[j] + 1, peer_addr) != 0)
            continue;
        entry = ((u8 (*)[9])lbl_803C0D18)[j];
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

/* Handles a BTA device-manager power-mode timer expiry: finds which PM timer slot fired, clears it, and posts a PM timer event with the slot's peer address. */
void bta_dm_pm_timer_cback(void *expiredTimer) {
    u8 *dmControlBlock = lbl_803C0C14;
    register void *eventMsg;
    register u8 slotIndex = 0;

    if (dmControlBlock[0xB6] != 0 && (void *)(dmControlBlock + 0x98) == expiredTimer) {
        dmControlBlock[0xB6] = 0;
        goto done;
    }
    slotIndex = 1;
    if (dmControlBlock[0xD6] != 0 && (void *)(dmControlBlock + 0xB8) == expiredTimer) {
        dmControlBlock[0xD6] = 0;
        goto done;
    }
    slotIndex = 2;
    if (dmControlBlock[0xF6] != 0 && (void *)(dmControlBlock + 0xD8) == expiredTimer) {
        dmControlBlock[0xF6] = 0;
        goto done;
    }
    slotIndex = 3;

done:
    if (slotIndex != 3) {
        eventMsg = GKI_getbuf(0xE);
        if (eventMsg != 0) {
            *(u16 *)eventMsg = 0x10A;
            fn_80070FA4((u8 *)eventMsg + 8,
                         lbl_803C0C14 + 0xB0 + ((u32)slotIndex << 5));
            fn_80071450(eventMsg);
        }
    }
}

void bta_dm_pm_btm_status(void *arg0) {
    register u8 *p = (u8 *)arg0;
    s32 offset;
    s32 mask;
    u32 i;
    u8 j;
    void *entry;
    void *record;

    i = 0;
loop_first:
    entry = (u8 *)&lbl_803C0C14 + ((i << 5) & 0x1FE0);
    if (*(u8 *)((u8 *)entry + 0xB6) != 0 &&
        bdcmp((u8 *)entry + 0xB0, p + 8) == 0) {
        fn_8007148C((s32)((u8 *)entry + 0x98));
        *(u8 *)((u8 *)entry + 0xB6) = 0;
    } else {
        i++;
        if (i < 3)
            goto loop_first;
    }

    if (p[0xE] == 0)
        goto check_links;
    goto done;
check_links:
    if (p[0x12] == 0)
        goto fallback;

    j = 0;
loop_second:
    offset = j * 0xB;
    if (bdcmp((u8 *)&lbl_803C0C14 + offset, p + 8) == 0) {
        record = (u8 *)&lbl_803C0C14 + offset;
        mask = *(u8 *)((u8 *)record + 9) & 3;
        if (mask != 0) {
            *(u8 *)((u8 *)record + 0xA) |= mask;
            bta_dm_pm_set_mode(p + 8, 0);
        }
        goto done;
    }
    j++;
    if (j < lbl_803C0C14[0x4D])
        goto loop_second;
    goto done;

fallback:
    bta_dm_pm_set_mode(p + 8, 0);
done:
    ;
}

void fn_80074A4C(s32 arg0) {
    bta_dm_pm_set_mode((u8 *)arg0 + 8, 1);
}

extern u8 HID_HostRegister(void *);
extern void bta_hh_cback(u8, u8, u32, BT_HDR *);
/* Enables the HID host: initializes the HID host control block, sets security level, registers the host callback, resets device slots on success, and invokes the stored completion callback with status. */
void bta_hh_api_enable(void *enableRequest) {
    s8 status = 6;
    u8 deviceIndex;

    fn_800869CC();
    memset(lbl_803C0D48, 0, sizeof(tBTA_HH_CB_MATCH));
    HID_HostSetSecurityLevel(&lbl_80559058, *((u8 *)enableRequest + 8));
    if (HID_HostRegister(bta_hh_cback) == 0) {
        ((tBTA_HH_CB_MATCH *)lbl_803C0D48)->p_cback =
            *(void **)((u8 *)enableRequest + 0x30);
        status = 0;
        for (deviceIndex = 0; deviceIndex < 0x10; deviceIndex++) {
            ((tBTA_HH_CB_MATCH *)lbl_803C0D48)->kdev[deviceIndex].state = 1;
            ((tBTA_HH_CB_MATCH *)lbl_803C0D48)->kdev[deviceIndex].hid_handle = 0xFF;
            ((tBTA_HH_CB_MATCH *)lbl_803C0D48)->kdev[deviceIndex].index = deviceIndex;
            ((tBTA_HH_CB_MATCH *)lbl_803C0D48)->cb_index[deviceIndex] = 0x10;
        }
    }
    (*(void (**)(u32, void *, void *))(lbl_803C0D48 + 0x224))(0, &status, lbl_803C0D48);
}

/* Disable the BTA HID host: if no disable is pending, deregister the HID host,
 * free each device descriptor buffer and the discovery database buffer, invoke
 * the disable callback with the status, and clear the control block; otherwise
 * mark disable pending and request disconnect for each connected device. */
void bta_hh_api_disable(void) {
    UINT8 deviceIndex;
    UINT8 status;
    void (*disableCb)(int, void *);

    if (*(void **)(lbl_803C0D48 + 0x224) == NULL)
        return;
    if (lbl_803C0D48[0x22D] == 0) {
        status = 0;
        if (HID_HostDeregister() != HID_SUCCESS)
            status = 6;
        for (deviceIndex = 0; deviceIndex < 0x10; deviceIndex++)
            fn_800716F0(lbl_803C0D48 + deviceIndex * 0x20 + 0x14);
        fn_800716F0(lbl_803C0D48 + 0x228);
        disableCb = *(void (**)(int, void *))(lbl_803C0D48 + 0x224);
        (*disableCb)(1, &status);
        memset(lbl_803C0D48, 0, 0x230);
    } else {
        lbl_803C0D48[0x22E] = 1;
        for (deviceIndex = 0; deviceIndex < 0x10; deviceIndex++) {
            if (lbl_803C0D48[deviceIndex * 0x20 + 0x2C] == 3)
                bta_hh_sm_execute((tBTA_HH_DEV_CB *)(lbl_803C0D48 + deviceIndex * 0x20 + 0x10), 0x1701, NULL);
        }
    }
}

void bta_hh_disc_cmpl(void) {
    volatile UINT8 status;
    UINT8 i;
    void (*cb)(int, void *);
    status = 0;
    if (HID_HostDeregister() == 0)
        return;
    status = 6;
    for (i = 0; i < 0x10; i++)
        fn_800716F0(lbl_803C0D48 + i * 0x20 + 0x14);
    fn_800716F0(lbl_803C0D48 + 0x228);
    cb = *(void (**)(int, void *))(lbl_803C0D48 + 0x224);
    (*cb)(1, (void *)&status);
    memset(lbl_803C0D48, 0, 0x230);
}

extern u8 bta_hh_tod_spt(void *, u8);
/* SDP callback for HID host: on success, ensures device type is supported, adds the
 * host device if needed, updates device list, then frees discovery DB and notifies
 * the state machine with SDP completion status. */
void bta_hh_sdp_cback(s32 result, u16 attr_mask, void *sdp_rec) {
    u8 cb_index;
    u8 status = 0x10;
    void *p_cb = *(void **)(lbl_803C0D48 + 0x210);
    void *p_sdp_rec = sdp_rec;
    if (result == 0) {
        if (*(u8 *)((u8 *)p_cb + 0x14) != 0) {
            attr_mask |= 0x8000;
        }
        if (lbl_8055DC80 >= 4) {
            ((void (*)(u32, void *, void *, s32, u16))fn_80070984)(0x503, lbl_803151D8, p_cb, result, attr_mask);
        }
        if (bta_hh_tod_spt(p_cb, *(u8 *)((u8 *)p_sdp_rec + 0x64)) != 0) {
            if (*(u8 *)((u8 *)p_cb + 0x16) == 0xFF) {
                status = HID_HostAddDev((u8 *)p_cb + 8, attr_mask, &cb_index);
                if (status == 0) {
                    *(u8 *)(lbl_803C0D48 + 0x214 + cb_index) = *(u8 *)((u8 *)p_cb + 0x12);
                    ((void (*)(void *, u8, u16, void *, u8, u8))bta_hh_add_device_to_list)(p_cb, cb_index, attr_mask, (u8 *)p_sdp_rec + 0x68, *(u8 *)((u8 *)p_sdp_rec + 0x64), *(u8 *)((u8 *)p_cb + 0x15));
                } else {
                    *(u8 *)((u8 *)p_cb + 0x15) = 0;
                }
            }
        } else {
            status = 0xFF;
        }
    }
    fn_800716F0(lbl_803C0D48 + 0x228);
    bta_hh_sm_execute((tBTA_HH_DEV_CB *)p_cb, 0x1707, &status);
}

extern char lbl_80315230[];
extern char lbl_80315260[];
extern s32 HID_HostGetSDPRecord(void *, void *, u32, void *);
void bta_hh_start_sdp(void *arg0, void *arg1) {
    /* Start SDP for an incoming HID connection, or skip SDP and add a known device. */
    u8 status = 0x10;
    u8 hidHandle;
    void *sdpBuf;
    u8 *devCb = (u8 *)arg0;
    u8 *eventData = (u8 *)arg1;

    devCb[0x14] = eventData[0xE];
    devCb[0x1B] = eventData[0xF];

    if (devCb[0x15] != 0) {
        status = 0;
        if (lbl_8055DC80 >= 5)
            fn_8007093C(0x504, lbl_80315230);

        if (devCb[0x16] == 0xFF) {
            status = HID_HostAddDev(devCb + 8, *(u16 *)(devCb + 0xE), &hidHandle);
            if (status == 0) {
                ((void (*)(void *, u8, u16, s32, u8, u8))bta_hh_add_device_to_list)(
                    arg0, hidHandle, *(u16 *)(devCb + 0xE), 0, devCb[0x13], devCb[0x15]);
                ((u8 *)lbl_803C0D48 + hidHandle)[0x214] = devCb[0x12];
            }
        }

        bta_hh_sm_execute(arg0, 0x1707, &status);
        return;
    }

    if (*(void **)(lbl_803C0D48 + 0x228) == 0) {
        sdpBuf = GKI_getbuf(*(u16 *)(lbl_80559030 + 8));
        *(void **)(lbl_803C0D48 + 0x228) = sdpBuf;
        *(void **)(lbl_803C0D48 + 0x210) = arg0;
        status = (u8)HID_HostGetSDPRecord(eventData + 8, sdpBuf,
                                          *(u16 *)(lbl_80559030 + 8),
                                          bta_hh_sdp_cback);
        if (status != 0) {
            if (lbl_8055DC80 >= 5)
                fn_80070954(0x504, lbl_80315260, status);
            status = 7;
            fn_800716F0(lbl_803C0D48 + 0x228);
        }
    }

    if (status != 0)
        bta_hh_sm_execute(arg0, 0x1707, &status);
}

void bta_hh_sdp_cmpl(void *arg0, u8 *status) {
    /* Handles HID Host SDP completion: on success opens the device (or continues SM), on failure reports an open event and cleans up. */
    u8 eventData[8];
    u8 hciStatus;
    if (lbl_8055DC80 >= 5)
        fn_80070954(0x504, lbl_803152B0, status[0]);
    memset(eventData, 0, 8);
    eventData[7] = *((u8 *)arg0 + 0x16);
    fn_80070FA4(eventData, (u8 *)arg0 + 8);
    hciStatus = status[0];
    if (hciStatus == 0) {
        if (*((u8 *)arg0 + 0x19) == 0) {
            HID_HostSetSecurityLevel(&lbl_80559058, *((u8 *)arg0 + 0x14));
            hciStatus = HID_HostOpenDev(*((u8 *)arg0 + 0x16));
            if (hciStatus != 0) {
                if (lbl_8055DC80 >= 5)
                    fn_80070954(0x504, lbl_803152D0, hciStatus);
                HID_HostRemoveDev(*((u8 *)arg0 + 0x16));
            }
        } else bta_hh_sm_execute(arg0, 0x170B, 0);
    }
    if (hciStatus == 0) return;
    if (status[0] == 0xFF) eventData[6] = 0xA;
    else eventData[6] = 7;
    ((void (*)(u32, void *))(*(void **)(lbl_803C0D48 + 0x224)))(2, eventData);
    bta_hh_sm_execute(arg0, 0x1701, 0);
    if (*((u8 *)arg0 + 0x15) == 0 && *((u8 *)arg0 + 0x19) == 0)
        bta_hh_clean_up_kdev(arg0);
    bta_hh_trace_dev_db();
}

void bta_hh_api_disc_act(void *arg0, void *arg1) {
    u8 buf[2];
    u8 handle;
    if (arg1 != 0) handle = (u8)*(u16 *)((u8 *)arg1 + 6);
    else handle = *(u8 *)((u8 *)arg0 + 0x16);
    buf[1] = handle;
    buf[0] = 6;
    if (HID_HostCloseDev(handle)) {
        (*(void (**)(int, u8 *))(lbl_803C0D48 + 0x224))(3, buf);
    }
}

extern void fn_8006CF80();
void bta_hh_open_cmpl_act(void *arg0, void *arg1) {
    u8 local[8];
    u8 *dev = arg0;
    u8 *cb;
    u8 handle;
    u8 status;
    /* HID host open completion: build open event, register connection, then
     * send queued virtual-cable setup or report open-complete. */
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
    /* Open a HID host device: log handle, re-enter SM if busy, or start SDP discovery. */
    u8 *devCb = (u8 *)arg0;
    u8 deviceHandle;
    u32 sdpData[4];

    if (arg1 != NULL)
        deviceHandle = (u8)*(u16 *)((u8 *)arg1 + 6);
    else
        deviceHandle = devCb[0x16];

    if (lbl_8055DC80 >= 4)
        fn_80070954(0x503, lbl_8031531C, deviceHandle);

    if (devCb[0x15] != 0) {
        bta_hh_sm_execute((tBTA_HH_DEV_CB *)arg0, 0x170B, arg1);
        return;
    }

    devCb[0x19] = 1;
    memset(sdpData, 0, 0x10);
    fn_80070FA4(sdpData + 2, devCb + 8);
    bta_hh_start_sdp(arg0, sdpData);
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

void bta_hh_ctrl_dat_act(void *arg0, void *arg1) {
    register u8 *cb = (u8 *)arg0;
    void *buf = *(void **)((u8 *)arg1 + 0x0C);
    u16 len = *(u16 *)((u8 *)buf + 4);
    register u8 *tail = (u8 *)buf + len;
    register u8 *strings = lbl_803151D8;
    u8 cfm[10];
    s32 event;

    if (lbl_8055DC80 >= 5) {
        register u8 *msg;
        switch (*(u16 *)(cb + 0x10)) {
        case 4: msg = strings + 0x16C; break;
        case 5: msg = strings + 0x180; break;
        case 6: msg = strings + 0x194; break;
        case 7: msg = strings + 0x1AC; break;
        case 8: msg = strings + 0x1C4; break;
        case 9: msg = strings + 0x1D8; break;
        case 2: msg = strings + 0x1F0; break;
        case 0:
        case 1:
        case 3: msg = strings + 0x200; break;
        default: break;
        }
        ((void (*)(u32, void *, void *))fn_80070954)(
            0x504, strings + 0x2A8, msg);
    }

    cfm[0] = 0;
    cfm[1] = cb[0x16];
    event = *(u16 *)(cb + 0x10);
    if (event == 7) goto second_trace;
    if (event >= 7) goto event_high;
    if (event == 5) goto second_trace;
    if (event >= 5) goto byte6;
    if (event < 4) goto second_trace;
    goto copy_eight;

event_high:
    if (event == 9) goto second_trace;
    if (event >= 9) goto second_trace;
    cfm[2] = tail[8];
    goto data_done;

copy_eight:
    memcpy(cfm + 2, buf, 8);
    goto data_done;

byte6:
    cfm[2] = tail[8];
    goto data_done;

second_trace:
    if (lbl_8055DC80 >= 5) {
        register u8 *msg;
        switch (event) {
        case 4: msg = strings + 0x16C; break;
        case 5: msg = strings + 0x180; break;
        case 6: msg = strings + 0x194; break;
        case 7: msg = strings + 0x1AC; break;
        case 8: msg = strings + 0x1C4; break;
        case 9: msg = strings + 0x1D8; break;
        case 2: msg = strings + 0x1F0; break;
        case 0:
        case 1:
        case 3: msg = strings + 0x200; break;
        default: break;
        }
        ((void (*)(u32, void *, void *))fn_80070954)(
            0x504, strings + 0x2CC, msg);
    }
data_done:
    fn_80071298((void *)0x17, (void *)(u32)cb[0x15], cb + 8);
    fn_80071264((void *)0x17, (void *)(u32)cb[0x15], cb + 8);
    (*(void (**)(u16, void *))(lbl_803C0D48 + 0x224))(
        *(u16 *)(cb + 0x10), cfm);
    *(u16 *)(cb + 0x10) = 0;
    fn_800716F0(&buf);
}

extern void fn_8006CF90();
void bta_hh_close_act(u8 *p_cb, u8 *p_data) {
    /* Handle HID host close: report close/error events and clean up or disable as needed. */
    u8 conn[8];
    u8 status[2] = {0, 0};
    u8 disc[2];
    u8 evt = 3;
    u32 reason;
    int xx;

    reason = *(u32 *)(p_data + 8);
    if (p_cb[0x17] != 0) evt = 0xD;
    status[1] = p_cb[0x16];
    status[0] = *(u32 *)(p_data + 8);
    if ((reason & 0x700) || reason == 0xF || reason == 0xE || p_cb[0x1A] == 0) {
        u8 handle = p_cb[0x16];
        u8 res;
        conn[7] = handle;
        res = (reason == 0xF) ? 0xC : 6;
        conn[6] = res;
        fn_80070FA4(conn, p_cb + 8);
        HID_HostCloseDev(p_cb[0x16]);
        (*(void (**)(u32, void *, void *))(lbl_803C0D48 + 0x224))(2, conn, lbl_803C0D48);
        bta_hh_trace_dev_db();
        return;
    }
    fn_8006CF90(p_cb[0x16], p_cb[0x15]);
    bta_sys_conn_open_8007116C(0x17, p_cb[0x15], (s32)(p_cb + 8));
    lbl_803C0D48[0x22D]--;
    p_cb[0x1A] = 0;
    if (status[0] != 0) status[0] = 6;
    (*(void (**)(u32, void *, void *))(lbl_803C0D48 + 0x224))(evt, status, lbl_803C0D48);
    if (p_cb[0x17] != 0) {
        HID_HostRemoveDev(p_cb[0x16]);
        bta_hh_clean_up_kdev(p_cb);
    }
    bta_hh_trace_dev_db();
    p_cb[0x17] = 0;
    *(u16 *)(p_cb + 0x10) = 0;
    if (lbl_803C0D48[0x22D] == 0 && lbl_803C0D48[0x22E] != 0) {
        disc[0] = 0;
        if (HID_HostDeregister() != 0) disc[0] = 6;
        for (xx = 0; (u8)xx < 0x10; xx++)
            fn_800716F0(lbl_803C0D48 + ((u8)xx << 5) + 0x14);
        fn_800716F0(lbl_803C0D48 + 0x228);
        (*(void (**)(u32, void *))(lbl_803C0D48 + 0x224))(1, disc);
        memset(lbl_803C0D48, 0, 0x230);
    }
}

void fn_80075AA4(void *arg0) {
    (*(void (**)(int, void *))(lbl_803C0D48 + 0x224))(10, arg0);
}

void bta_hh_maint_dev_act(void *devCbArg, void *eventArg) {
    extern unsigned char lbl_803C0D48[];
    extern char lbl_80315530[];
    extern u8 lbl_8055DC80;
    extern u8 HID_HostRemoveDev(u32);
    /* Maintain an HID host device: add on event 11, remove on 12, else log invalid. */
    struct {
        u32 data;
        u16 pad;
        u8 status;
        u8 dev;
    } resultCb;
    u8 hostDevHandle;
    s32 event;

    resultCb.status = 6;
    resultCb.dev = 0xFF;
    event = *(u16 *)((u8 *)eventArg + 0x10);
    switch (event) {
    case 12:
        goto remove;
    case 11:
        goto add;
    default:
        goto default_case;
    }
add:
    fn_80070FA4(&resultCb, &((u32 *)eventArg)[2]);
    if (*(u8 *)((u8 *)devCbArg + 0x16) == 0xFF) {
        if (HID_HostAddDev((u8 *)eventArg + 8, *(u16 *)((u8 *)eventArg + 0xE), &hostDevHandle) == 0) {
            resultCb.status = 0;
            resultCb.dev = hostDevHandle;
            ((void (*)(void *, u8, u16, u32, u8, u8))bta_hh_add_device_to_list)(devCbArg, hostDevHandle, *(u16 *)((u8 *)eventArg + 0xE), 0, *(u8 *)((u8 *)eventArg + 0x12), *(u8 *)((u8 *)eventArg + 0x13));
            *((u8 *)(lbl_803C0D48 + hostDevHandle) + 0x214) = *(u8 *)((u8 *)devCbArg + 0x12);
        }
    } else {
        resultCb.dev = *(u8 *)((u8 *)devCbArg + 0x16);
        resultCb.status = 0;
    }
    goto trace;
trace:
    bta_hh_trace_dev_db();
    goto finish;
remove:
    resultCb.dev = (u8)*(u16 *)((u8 *)eventArg + 6);
    fn_80070FA4(&resultCb, (u8 *)devCbArg + 8);
    if (*(u8 *)((u8 *)devCbArg + 0x1C) != 3 && HID_HostRemoveDev(resultCb.dev) == 0) {
        resultCb.status = 0;
        bta_hh_clean_up_kdev(devCbArg);
    }
    goto finish;
default_case:
    if (lbl_8055DC80 >= 5) fn_8007093C(0x504, lbl_80315530);
finish:
    (*(void (**)(u16, void *, void *))(lbl_803C0D48 + 0x224))(*(u16 *)((u8 *)eventArg + 0x10), &resultCb, lbl_803C0D48);
}

void bta_hh_get_acl_q_info(void) {
    u8 info[0x1E];
    register u8 count;
    register u8 *config;
    register u8 *entry_base;
    register u8 *row;
    register u8 i;
    u8 *ccb;
    u8 *p;

    count = 0;
    memset(info, 0, 0x1E);
    config = lbl_803C3C38;
    entry_base = lbl_803C0D48;
    for (i = 0; i < 0x10; i++) {
        u8 *entry = entry_base + ((u32)i << 5);
        if (entry[0x28] != 0 && entry[0x2C] == 3) {
            row = info + ((u32)count * 6);
            row[6] = entry[0x26];
            ccb = (u8 *)l2cu_find_ccb_by_cid(0,
                *(u16 *)(config + entry[0x26] * 0x34 + 0x16));
            if (ccb != 0 && (p = *(u8 **)(ccb + 0x10)) != 0 && p[0] != 0) {
                *(u16 *)(row + 8) = *(u16 *)(p + 0x4C);
                *(u16 *)(row + 0xA) = *(u16 *)(p + 0x38);
                count++;
            }
        }
    }
    *(u16 *)(info + 0) = *(u16 *)(lbl_803C4040 + 4);
    *(u16 *)(info + 2) = *(u16 *)(lbl_803C4040 + 2);
    *(u16 *)(info + 4) = count;
    ((void (*)(u32, void *, u16, u16))*(void **)(lbl_803C0D48 + 0x224))(
        0xF, info, *(u16 *)(lbl_803C4040 + 2), *(u16 *)(lbl_803C4040 + 4));
}

void bta_hh_write_dev_act(void *p_dev, void *p_msg) {
    extern char lbl_80315540[];
    extern char lbl_8031555C[];
    u8 *dev = (u8 *)p_dev;
    u8 *msg = (u8 *)p_msg;
    u16 status = 0;
    u8 saved_event = msg[8];
    u8 result;
    s32 state;

    ((u8 *)&status)[1] = dev[0x16];
    result = HID_HostWriteDev(dev[0x16], msg[8], msg[9], *(u16 *)(msg + 0xC), msg[0xA], *(BT_HDR **)(msg + 0x10));
    if (result != 0) {
        if (lbl_8055DC80 >= 1)
            fn_80070954(0x500, lbl_80315540, result);
        ((u8 *)&status)[0] = 6;
        if (msg[8] != 1 && msg[8] != 0xA) {
            (*(void (**)(u32, void *, void *))(lbl_803C0D48 + 0x224))(saved_event, &status, lbl_803C0D48);
            return;
        }
        if (msg[9] == 5)
            (*(void (**)(u32, void *, void *))(lbl_803C0D48 + 0x224))(0xD, &status, lbl_803C0D48);
        return;
    }

    state = msg[8];
    if (state == 0xA)
        goto state_special;
    if (state >= 0xA)
        goto state_log;
    if (state == 1)
        goto state_special;
    if (state < 1)
        goto state_log;
    if (state >= 4)
        goto state_store;
    goto state_log2;

state_store:
    *(u16 *)(dev + 0x10) = saved_event;
    goto state_done;
state_special:
    if (msg[9] == 5)
        dev[0x17] = 1;
    goto state_done;
state_log2:
state_log:
    if (lbl_8055DC80 >= 5)
        ((void (*)(u32, void *))fn_80070954)(0x504, lbl_8031555C);
state_done:
    if (msg[8] != 1) {
        fn_80071298((void *)0x17, (void *)(u32)dev[0x15], dev + 8);
        fn_80071264((void *)0x17, (void *)(u32)dev[0x15], dev + 8);
        return;
    }
    if (msg[9] == 3)
        fn_80071230((void *)0x17, (void *)(u32)dev[0x15], dev + 8);
    else if (msg[9] == 4)
        fn_80071298((void *)0x17, (void *)(u32)dev[0x15], dev + 8);
}

void bta_hh_cback(u8 arg0, u8 arg1, u32 arg2, BT_HDR *arg3) {
    u32 event = 0x1710;
    void *p504;
    u8 *base504 = lbl_803151D8;
    if (lbl_8055DC80 > 5) {
        if (arg1 <= 8) {
            switch (arg1) {
            case 0: p504 = base504 + 0x3AC; break;
            case 1: p504 = base504 + 0x3C0; break;
            case 2: p504 = base504 + 0x3D4; break;
            case 3: p504 = base504 + 0x3EC; break;
            case 4: p504 = base504 + 0x404; break;
            case 5: p504 = base504 + 0x41C; break;
            case 6: p504 = base504 + 0x434; break;
            case 7: p504 = base504 + 0x44C; break;
            case 8: p504 = base504 + 0x464; break;
            default: p504 = base504 + 0x47C; break;
            }
        } else {
            p504 = base504 + 0x47C;
        }
        fn_80070954(0x504, p504, (u16)arg3);
        if (arg1 <= 8) {
            switch (arg1) {
            case 0: event = 0x1702; break;
            case 1: event = 0x1703; break;
            case 2: event = 0x1704; break;
            case 3: event = 0x1706; break;
            case 4: event = 0x1705; break;
            case 5: event = 0x1710; fn_800716F0((void *)((u8 *)arg3 + 4)); break;
            case 6: {
                u8 *base = lbl_803C0D48;
                u32 i;
                for (i = 0; i < 9; i++) {
                    u8 *e = base + i * 0x28;
                    if (e[0x26] == arg0) { e[0x27] = 1; break; }
                }
                break;
            }
            case 7: {
                u8 *base = lbl_803C0D48;
                u32 i;
                for (i = 0; i < 9; i++) {
                    u8 *e = base + i * 0x28;
                    if (e[0x26] == arg0) { e[0x27] = 1; break; }
                }
                break;
            }
            case 8: {
                u8 *base = lbl_803C0D48;
                u32 i;
                for (i = 0; i < 9; i++) {
                    u8 *e = base + i * 0x28;
                    if (e[0x26] == arg0) { e[0x27] = 1; break; }
                }
                break;
            }
            default: break;
            }
        }
    }
    if (event != 0x1710) {
        void *buf = GKI_getbuf(0x18);
        if (buf != 0) {
            *(u16*)buf = (u16)event;
            *(u16*)((u8*)buf + 6) = arg0;
            *(u32*)((u8*)buf + 8) = arg2;
            *(u32*)((u8*)buf + 12) = (u32)arg3;
            fn_80071450(buf);
        }
    }
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
/* Open HID host connection to a device: build and send BTA_HH_API_OPEN_EVT, or log if no buffer. */
void BTA_HhOpen(const u8 *dev_bda, s8 proto_mode, s8 sec_mask) {
    u8 *p_buf = GKI_getbuf(0x10);
    if (p_buf != 0) {
        memset(p_buf, 0, 0x10);
        *(u16 *)p_buf = 0x1700;
        *(u16 *)(p_buf + 6) = 0xFF;
        p_buf[0xE] = sec_mask;
        p_buf[0xF] = proto_mode;
        fn_80070FA4(p_buf + 8, dev_bda);
        fn_80071450(p_buf);
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

/* BTA-HID device maintenance request, this BTE revision's tBTA_HH_MAINT_DEV
 * (bta_hh_int.h).  BTA_HhAddDev() and BTA_HhRemoveDev() queue one for the BTA
 * task; here dscp_info is only the report descriptor, where the newer stack the
 * reference headers describe carries a whole tBTA_HH_DEV_DSCP_INFO. */
typedef u16 tBTA_HH_ATTR_MASK;      /* HID attribute mask (bta_hh_api.h) */
typedef struct {
    BT_HDR              hdr;        /* 0x00 event; layer_specific = device handle */
    BD_ADDR             bda;        /* 0x08 device address */
    UINT16              attr_mask;  /* 0x0E HID attribute mask */
    UINT16              sub_event;  /* 0x10 BTA_HH_ADD_DEV_EVT / BTA_HH_RMV_DEV_EVT */
    UINT8               sub_class;  /* 0x12 class-of-device sub-class */
    UINT8               app_id;     /* 0x13 application ID for this connection */
    tBTA_HH_DEV_DESCR   dscp_info;  /* 0x14 report descriptor */
} tBTA_HH_MAINT_DEV;

#define BTA_HH_API_MAINT_DEV_EVT                  0x170A  /* tBTA_HH_INT_EVT */
#define BTA_HH_ADD_DEV_EVT                        11      /* sub_event: add device */
#define BTA_HH_INVALID_HANDLE                     0xff    /* no device handle yet */
#define bta_sys_sendmsg                           fn_80071450  /* -> BTA task */

void BTA_HhAddDev(const u8 *bda, tBTA_HH_ATTR_MASK attr_mask, u8 sub_class,
                  u8 app_id, const void *dscp_info) {
    /* Queue a virtually-cabled HID device for HID-Host to manage: its address,
     * attribute mask, class-of-device sub-class, application ID and report
     * descriptor go to the BTA-HID state machine as an add-device maintenance
     * message, with no device handle assigned yet. */
    tBTA_HH_MAINT_DEV *p_buf = (tBTA_HH_MAINT_DEV *)GKI_getbuf(sizeof(tBTA_HH_MAINT_DEV));
    if (p_buf != 0) {
        memset(p_buf, 0, sizeof(tBTA_HH_MAINT_DEV));
        p_buf->hdr.event = BTA_HH_API_MAINT_DEV_EVT;
        p_buf->sub_event = BTA_HH_ADD_DEV_EVT;
        p_buf->hdr.layer_specific = BTA_HH_INVALID_HANDLE;
        p_buf->attr_mask = attr_mask;
        p_buf->sub_class = sub_class;
        p_buf->app_id = app_id;
        memcpy(&p_buf->dscp_info, dscp_info, sizeof(tBTA_HH_DEV_DESCR));
        bdcpy(p_buf->bda, bda);
        bta_sys_sendmsg(p_buf);
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
    u8 action;
    u8 new_state;
    register char *state_name;
    char *new_state_name;
    u8 *table;
    u8 state;
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
            case 3: state_name = strings + (unsigned short)0x50; break;
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

extern void bta_hh_api_enable(void *);
extern void bta_hh_api_disable(void);
extern void bta_hh_disc_cmpl(void);
extern void bta_hh_get_acl_q_info(void);
extern UINT8 bta_hh_find_cb(BD_ADDR);
BOOLEAN bta_hh_hdl_event(BT_HDR *p_msg) {
    /* HID Host main event handler: dispatch global HH events, resolve target device CB by handle/BD_ADDR mapping, trace, and run device state machine. */
    UINT16 event = p_msg->event;
    UINT8 index = 0x10;
    tBTA_HH_DEV_CB *p_cb = NULL;
    u32 addr;
    switch (event) {
    case 0x170C:
        bta_hh_api_enable(p_msg);
        goto done;
    case 0x170D:
        bta_hh_api_disable();
        goto done;
    case 0x170F:
        bta_hh_disc_cmpl();
        goto done;
    case 0x170E:
        bta_hh_get_acl_q_info();
        goto done;
    }
    if (event == 0x1700) {
        index = bta_hh_find_cb((u8 *)p_msg + 8);
    } else if (event == 0x170A) {
        if (*(UINT16 *)((u8 *)p_msg + 0x10) == 0x0B) {
            index = bta_hh_find_cb((u8 *)p_msg + 8);
        } else {
            index = *(lbl_803C0D48 + p_msg->layer_specific + 0x214);
        }
    } else if (p_msg->layer_specific < 0x10) {
        index = *(lbl_803C0D48 + p_msg->layer_specific + 0x214);
    }
    if (index != 0x10) {
        addr = (u32)lbl_803C0D48 + ((u32)index << 5);
        p_cb = (tBTA_HH_DEV_CB *)(addr + 0x10);
    }
    if (lbl_8055DC80 >= 5) {
        fn_8007096C(0x504, lbl_803157DC, p_msg->layer_specific, index);
    }
    bta_hh_sm_execute(p_cb, p_msg->event, p_msg);
done:
    return TRUE;
}

extern char lbl_80315700[];
extern void *jumptable_803159A0[];
/* Map a BTA HH API event code to its debug string name. */
char *bta_hh_evt_code(u32 event) {
    u32 index = event - 0x1700;
    char *evt_strings = lbl_80315700;
    switch (index) {
    case 0: return evt_strings + 0x108;
    case 1: return evt_strings + 0x120;
    case 2: return evt_strings + 0x138;
    case 3: return evt_strings + 0x14C;
    case 4: return evt_strings + 0x164;
    case 5: return evt_strings + 0x178;
    case 6: return evt_strings + 0x190;
    case 7: return evt_strings + 0x1A8;
    case 8: return evt_strings + 0x1BC;
    case 9: return evt_strings + 0x1D4;
    case 10: return evt_strings + 0x1F0;
    case 11: return evt_strings + 0x204;
    case 12: return evt_strings + 0x21C;
    case 13: return evt_strings + 0x238;
    case 14: return evt_strings + 0x250;
    case 15: return evt_strings + 0x268;
    default: return evt_strings + 0x284;
    }
}

u8 bta_hh_find_cb(u8 *bd_addr) {
    extern u8 lbl_803159E0[];
    extern u8 lbl_80565228;
    u8 *messages;
    u8 i;
    messages = lbl_803159E0;

    for (i = 0; i < 0x10; i++) {
        if (bdcmp(bd_addr, lbl_803C0D48 + ((i & 0xFF) << 5) + 0x18) == 0 &&
            bdcmp(bd_addr, &lbl_80565228) != 0) {
            if (lbl_8055DC80 >= 5)
                fn_8007096C(0x504, messages + 0, i,
                            lbl_803C0D48[((i & 0xFF) << 5) + 0x26]);
            return i;
        }
        if (5 <= lbl_8055DC80)
            ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)
                (0x504, messages + 0x24,
                 lbl_803C0D48[((i & 0xFF) << 5) + 0x28],
                 i, lbl_803C0D48[((i & 0xFF) << 5) + 0x26],
                 lbl_803C0D48[((i & 0xFF) << 5) + 0x2C]);
    }

    for (i = 0; i < 0x10; i++) {
        if (lbl_803C0D48[(i << 5) + 0x28] == 0) {
            fn_80070FA4(lbl_803C0D48 + ((u32)i << 5) + 0x18, bd_addr);
            break;
        }
    }
    if (lbl_8055DC80 >= 5)
        fn_8007096C(0x504, messages + 0x58, i, 0x10);
    return i;
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
/* Adds/updates a device in the BTA HH device list, optionally copying descriptor data. */
void bta_hh_add_device_to_list(void *devCb, s8 handle, s16 attrMask, void *desc, s32 subClass, s32 appId) {
    if (lbl_8055DC80 >= 5) {
        ((void (*)(u32, void *, s32))fn_80070954)(0x504, lbl_80315A64, subClass);
    }
    *((u8 *)devCb + 0x16) = handle;
    *((u8 *)devCb + 0x18) = 1;
    *(u16 *)((u8 *)devCb + 0xE) = attrMask;
    *((u8 *)devCb + 0x13) = subClass;
    *((u8 *)devCb + 0x15) = appId;
    if (desc != 0) {
        fn_800716F0(&((void **)devCb)[1]);
        if (*(u16 *)desc != 0) {
            void *p = GKI_getbuf(*(u16 *)desc);
            ((void **)devCb)[1] = p;
            if (p != 0) {
                *(u16 *)devCb = *(u16 *)desc;
                memcpy(p, ((void **)desc)[1], *(u16 *)desc);
            }
        }
    }
}

BOOLEAN bta_hh_tod_spt(void *p_cb, UINT8 sub_class) {
    UINT8 max_devt = lbl_80559030[0];
    UINT32 cod = (sub_class >> 2) & 0x3F;
    UINT8 xx;
    for (xx = 0; xx < max_devt; xx++) {
        UINT8 *p_list = *(UINT8 **)(lbl_80559030 + 4);
        if (cod == p_list[xx * 2]) {
            ((UINT8 *)p_cb)[0x15] = p_list[xx * 2 + 1];
            return TRUE;
        }
    }
    return FALSE;
}

void bta_hh_trace_dev_db(void) {
    /* Traces the HID host device database when debug tracing is enabled. */
    extern u8 lbl_803159E0[];
    extern void fn_8007093C(u32, void *);
    extern void fn_80070984(u32, void *);
    extern void fn_8007099C(u32, void *);
    u8 *traceStrings = lbl_803159E0;
    u32 index;
    u8 *deviceEntry;

    if (lbl_8055DC80 >= 5)
        fn_8007093C(0x504, traceStrings + 0x1E4);
    index = 0;
    do {
        if (lbl_8055DC80 >= 5) {
            deviceEntry = lbl_803C0D48 + ((u8)index << 5);
            ((void (*)(u32, void *, u8, u8, u8))fn_80070984)(0x504, traceStrings + 0x220, (u8)index, deviceEntry[0x28], deviceEntry[0x26]);
        }
        if (lbl_8055DC80 >= 5) {
            deviceEntry = lbl_803C0D48 + ((u8)index << 5);
            ((void (*)(u32, void *, u16, u8, u8, u8))fn_8007099C)(0x504, traceStrings + 0x244, *(u16 *)(deviceEntry + 0x1E), deviceEntry[0x2C], deviceEntry[0x23], deviceEntry[0x22]);
        }
        index++;
    } while (index < 0x10);
    if (lbl_8055DC80 >= 5)
        fn_8007093C(0x504, traceStrings + 0x280);
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
    unsigned long var_ctr_2;
    u8 *var_r30_2;
    u16 var_r30;
    u8 var_r6;
    u32 var_r31;
    u8 var_r4;
    u32 var_r29_2;
    u8 *var_r29;
    u16 temp_r28;
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
                        if (4 > var_r29_2) {
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
    unsigned int i;
    u8 *entry;
    void (*callback)(u8 *, u32, u32, u32, u32);
    entry = lbl_803C0F78 + 0x34;
    for (i = 0; i < 4; i++, entry += 0x11C) {
        if (entry[0x119] && memcmp(entry + 8, addr, 6) == 0)
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

#pragma push
#pragma optimization_level 3
tBTM_STATUS BTM_SwitchRole(BD_ADDR remote_bd_addr, UINT8 new_role, tBTM_CMPL_CB *p_cb) {
    u32 i; u8 *entry; u8 power_mode; u8 status; tBTM_PM_PWR_MD spC;
    if ((lbl_803C0F78[0x640] & 0x20) == 0) return 4;
    entry = lbl_803C0F78 + 0x34;
    for (i = 0; i < 4; i++, entry += 0x11C) {
        if (entry[0x119] == 0) continue;
        if (memcmp(entry + 8, remote_bd_addr, 6) != 0) continue;
        goto found;
    }
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
#pragma pop
void btm_acl_encrypt_change(u16 handle, u8 status, u8 enable)
{
    /* Finds the ACL device entry matching handle in lbl_803C0F78, then handles
     * pending encrypt/switch-role states (0x14F == 2/4), issuing HCI switch-role
     * when needed and invoking/clearing a stored callback on completion/failure. */
    u8 *base = lbl_803C0F78;
    u32 index = 0;
    u8 *dev;

    if (base[0x14D] != 0 && *(u16 *)(base + 0x34) == handle)
        goto found;
    index = 1;
    if (base[0x269] != 0 && *(u16 *)(base + 0x150) == handle)
        goto found;
    index = 2;
    if (base[0x385] != 0 && *(u16 *)(base + 0x26C) == handle)
        goto found;
    index = 3;
    if (base[0x4A1] != 0 && *(u16 *)(base + 0x388) == handle)
        goto found;
    index = 4;

found:
    if (index >= 4)
        goto done;

    dev = (u8 *)lbl_803C0F78 + index * 0x11C;
    goto process;
done:
    return;
process:
    if (dev[0x14F] == 2) {
        if (enable != 0)
            dev[0x14F] = 0;
        else
            dev[0x14F] = 3;
        if (btsnd_hcic_switch_role(dev + 0x3C, (u8)(dev[0x14E] == 0)) == 0) {
            dev[0x14F] = 0;
            if (*(void (**)(void *))((u8 *)lbl_803C0F78 + 0x62C) != 0) {
                (*(void (**)(void *))((u8 *)lbl_803C0F78 + 0x62C))((u8 *)lbl_803C0F78 + 0x624);
                *(void (**)(void *))((u8 *)lbl_803C0F78 + 0x62C) = 0;
            }
        }
    } else if (dev[0x14F] == 4) {
        dev[0x14F] = 0;
        if (*(void (**)(void *))((u8 *)lbl_803C0F78 + 0x62C) != 0) {
            (*(void (**)(void *))((u8 *)lbl_803C0F78 + 0x62C))((u8 *)lbl_803C0F78 + 0x624);
            *(void (**)(void *))((u8 *)lbl_803C0F78 + 0x62C) = 0;
        }
    }
}

extern void *fn_8007A3A4(void);
tBTM_STATUS BTM_SetLinkPolicy(BD_ADDR remote_bda, UINT16 *settings)
{
    u8 *strings = lbl_80315CA0;
    u8 *features;
    u32 value;
    u32 i;
    u8 *entry;
    u16 policy;

    features = (u8 *)fn_8007A3A4();
    policy = *settings;
    if (policy != 0) {
        if ((policy & 1) && !(features[0] & 0x20)) {
            value = (u32)policy & 0xFFFE;
            *settings = value;
            if (lbl_803C0F78[0x27C0] >= 3) fn_80070954(0xD0002, strings + 0xBC, value);
        }
        policy = *settings;
        if ((policy & 2) && !(features[0] & 0x40)) {
            value = (u32)policy & 0xFFFFFFFD;
            *settings = value;
            if (lbl_803C0F78[0x27C0] >= 3) fn_80070954(0xD0002, strings + 0xF8, value);
        }
        policy = *settings;
        if ((policy & 4) && !(features[0] & 0x80)) {
            value = (u32)policy & 0xFFFFFFFB;
            *settings = value;
            if (lbl_803C0F78[0x27C0] >= 3) fn_80070954(0xD0002, strings + 0x130, value);
        }
        policy = *settings;
        if ((policy & 8) && !(features[1] & 1)) {
            value = (u32)policy & 0xFFFFFFF7;
            *settings = value;
            if (lbl_803C0F78[0x27C0] >= 3) fn_80070954(0xD0002, strings + 0x170, value);
        }
    }

    entry = lbl_803C0F78 + 0x34;
    for (i = 0; i < 4; i++, entry += 0x11C) {
        if (entry[0x119] != 0) {
            int r = memcmp(entry + 8, remote_bda, 6);
            if (r == 0) goto found;
        }
    }
    entry = NULL;
found:
    if (entry != NULL) {
        return btsnd_hcic_write_policy_set(*(u16 *)entry, *settings) ? 1 : 3;
    }
    return 7;
}

void fn_800778C8(s16 arg0) {
    *(s16 *)(lbl_803C0F78 + 0x4C4) = arg0;
}

/* Handles HCI Read Link Policy Settings complete: stores status/settings for the ACL connection and invokes the pending callback. */
void btm_read_link_policy_complete(u8 *event) {
    tBTM_CMPL_CB *completionCb;
    tBTM_LNK_POLICY_RESULTS_LKP results;
    u16 handle;
    u8 *aclConn;
    u16 index;

    completionCb = *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5C4);
    aclConn = lbl_803C0F78 + 0x34;
    fn_80070F90(lbl_803C0F78 + 0x5AC);
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5C4) = 0;
    if (completionCb) {
        results.hci_status = event[0];
        if (results.hci_status == 0) {
            results.status = 0;
            handle = (u16)(event[1] + (event[2] << 8));
            results.settings = (u16)(event[3] + (event[4] << 8));
            for (index = 0; index < 4; index++, aclConn += 0x11C) {
                if (aclConn[0x119] != 0 && handle == *(u16 *)aclConn) {
                    memcpy(results.rem_bda, aclConn + 8, 6);
                    break;
                }
            }
        } else {
            results.status = 10;
        }
        (*completionCb)(&results);
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

void btm_read_remote_features_complete(UINT8 *p) {
    extern u8 lbl_80315CE0[];
    u8 *acl = lbl_803C0F78 + 0x34;
    u16 handle;
    u16 temp;
    s32 i;
    u8 *dev;
    u32 j;
    u8 *q;
    u16 policy;

    if (p[0] == 0) {
        handle = p[1] + (p[2] << 8);
        for (i = 0; i < 4; i++, acl += 0x11C) {
            if (acl[0x119] && *(u16 *)acl == handle) {
                acl[0x110] = p[3];
                acl[0x111] = p[4];
                acl[0x112] = p[5];
                acl[0x113] = p[6];
                acl[0x114] = p[7];
                acl[0x115] = p[8];
                acl[0x116] = p[9];
                acl[0x117] = p[10];
                dev = (u8 *)btm_find_dev_by_handle(handle);
                if (dev) memcpy(dev + 0x77, acl + 0x110, 8);
                temp = *(u16 *)(lbl_803C0F78 + 0x654) & 0xCC18;
                if (lbl_803C0F78[0x636] >= 3) temp |= *(u16 *)(lbl_803C0F78 + 0x654) & 0x3306;
                else temp &= ~0x3306;
                if (lbl_803C0F78[0x27C0] >= 4) fn_80070954(0xD0003, lbl_80315CE0, temp);
                if (btsnd_hcic_change_conn_type(*(u16 *)acl, temp)) *(u16 *)(acl + 2) = temp;
                if (*(u16 *)(lbl_803C0F78 + 0x4C4)) BTM_SetLinkPolicy(acl + 8, (u16 *)(lbl_803C0F78 + 0x4C4));
                j = 0;
                policy = *(u16 *)(lbl_803C0F78 + 0x4C6);
                q = lbl_803C0F78 + 0x34;
                for (; j < 4; j++, q += 0x11C) {
                    if (!q[0x119])
                        continue;
                    if (memcmp(q + 8, acl + 8, 6) != 0)
                        continue;
                    goto found;
                }
                q = 0;
found:
                if (q) {
                    *(u16 *)(q + 0x10E) = policy;
                    if (!q[0x11A]) btsnd_hcic_write_policy_set_80085668(*(u16 *)q, policy);
                }
                if (*(void **)(lbl_803C0F78 + 0x4C8)) {
                    (*(void (**)(u8 *, u8 *, u8 *, u8 *, s32))(lbl_803C0F78 + 0x4C8))(acl + 8, acl + 0xE, acl + 0x11, acl + 0x110, 1);
                }
                break;
            }
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
    entry = lbl_803C0F78 + 0x34;
    for (i = 0; i < 4; i++, entry += 0x11C) {
        if (entry[0x119] != 0) {
            if (memcmp(entry + 8, remote_bda, 6) == 0)
                goto found;
            else
                goto cont;
        }
cont: ;
    }
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

void btm_acl_role_changed(u8 status, u8 *bd_addr, u8 role) { /* w5 */
    u32 i;
    u8 *entry;
    u8 *other;
    u8 *buffer;
    u8 *addr;
    u32 j;
    u16 supervision_timeout;
    u32 (*callback)(void *);
    u32 trace_level;
    if (bd_addr != NULL)
        addr = bd_addr;
    else
        addr = lbl_803C0F78 + 0x27B4;
    entry = lbl_803C0F78 + 0x34;
    i = 0;
    for (;;) {
        if (entry[0x119] == 0)
            goto next1;
        if (memcmp(entry + 8, addr, 6) != 0)
            goto next1;
        break;
    next1:
        i++;
        entry += 0x11C;
        if (i >= 4) {
            entry = NULL;
            break;
        }
    }
    buffer = lbl_803C0F78 + 0x624;
    if (entry == NULL)
        return;
    buffer[0] = status;
    if (status == 0) {
        buffer[1] = role;
        memcpy(buffer + 2, addr, 6);
        entry[0x11A] = role;
    }
    if (bd_addr != NULL) {
        supervision_timeout = *(u16 *)(entry + 0x10E);
        other = lbl_803C0F78 + 0x34;
        j = 0;
        for (;;) {
            if (other[0x119] == 0)
                goto next2;
            if (memcmp(other + 8, entry + 8, 6) != 0)
                goto next2;
            break;
        next2:
            j++;
            other += 0x11C;
            if (j >= 4) {
                other = NULL;
                break;
            }
        }
        if (other != NULL) {
            *(u16 *)(other + 0x10E) = supervision_timeout;
            if (other[0x11A] == 0)
                btsnd_hcic_write_policy_set_80085668(*(u16 *)other, supervision_timeout);
        }
    }
    if (entry[0x11B] == 3 && btsnd_hcic_set_conn_encrypt(*(u16 *)entry, 1) != FALSE)
        entry[0x11B] = 4;
    if (entry != NULL && entry[0x11B] == 5)
        entry[0x11B] = 0;
    callback = *(u32 (**)(void *))(lbl_803C0F78 + 0x62C);
    if (callback != NULL) {
        callback(buffer);
        *(u32 *)(lbl_803C0F78 + 0x62C) = 0;
    }
    trace_level = lbl_803C0F78[0x27C0];
    if (trace_level >= 4)
        fn_8007096C(0xD0003, lbl_80315EBC, buffer[1], buffer[0]);
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

UINT16 btm_get_max_packet_size(BD_ADDR addr) {
    u32 i;
    u8 *p;
    u16 pkt_types;
    u16 pkt_size;
    i = 0;
    p = lbl_803C0F78 + 0x34;
loop:
    if (p[0x119] == 0)
        goto next;
    if (memcmp(p + 8, addr, 6) != 0)
        goto next;
    goto done;
next:
    i++;
    p += 0x11C;
    if (i < 4)
        goto loop;
    p = 0;
done:
    pkt_types = 0;
    pkt_size = 0;
    if (p != 0)
        pkt_types = *(u16 *)(p + 2);
    else if (memcmp(lbl_803C0F78 + 0x630, addr, 6) == 0)
        pkt_types = *(u16 *)(lbl_803C0F78 + 0x654);
    if (pkt_types) {
        if (!(pkt_types & 0x2000))
            pkt_size = 0x3FD;
        else if (!(pkt_types & 0x1000))
            pkt_size = 0x2A7;
        else if (!(pkt_types & 0x0200))
            pkt_size = 0x228;
        else if (pkt_types & 0x8000)
            pkt_size = 0x153;
        else if (!(pkt_types & 0x0100))
            pkt_size = 0x16F;
        else if (pkt_types & 0x4000)
            pkt_size = 0xE0;
        else if (pkt_types & 0x0800)
            pkt_size = 0xB7;
        else if (pkt_types & 0x0400)
            pkt_size = 0x79;
        else if (!(pkt_types & 0x0004))
            pkt_size = 0x53;
        else if (!(pkt_types & 0x0002))
            pkt_size = 0x36;
        else if (pkt_types & 0x0010)
            pkt_size = 0x1B;
        else if (pkt_types & 0x0008)
            pkt_size = 0x11;
    }
    if (pkt_size == 0x3FD && *(u16 *)(lbl_803C0A50 + 0x7C) == 0x3F9)
        pkt_size = 0x3F9;
    return pkt_size;
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

extern char lbl_80315F24[];
void btm_qos_setup_complete(UINT8 status, UINT16 handle, FLOW_SPEC *p_flow) {
    u8 *base = lbl_803C0F78;
    tBTM_CMPL_CB *p_cb = *(tBTM_CMPL_CB **)(base + 0x618);
    volatile tBTM_QOS_SETUP_CMPL qossu;
    fn_80070F90(base + 0x600);
    *(tBTM_CMPL_CB **)(base + 0x618) = NULL;
    if (p_cb) {
        qossu.status = status;
        qossu.handle = handle;
        if (p_flow != NULL) {
            qossu.flow.qos_flags = p_flow->qos_flags;
            qossu.flow.service_type = p_flow->service_type;
            qossu.flow.token_rate = p_flow->token_rate;
            qossu.flow.peak_bandwidth = p_flow->peak_bandwidth;
            qossu.flow.latency = p_flow->latency;
            qossu.flow.delay_variation = p_flow->delay_variation;
            if (*(volatile u8 *)(lbl_803C0F78 + 0x27C0) >= 5) {
                ((void (*)(u32, void *, u32))fn_80070954)(0xD0004, lbl_80315F24, p_flow->delay_variation);
            }
        }
        (*p_cb)((void *)&qossu);
    }
}

tBTM_STATUS BTM_ReadRSSI(BD_ADDR remote_bda, tBTM_CMPL_CB *p_cb) {
    extern char lbl_80315F4C[];
    u8 *entry;
    u32 i;
    if (lbl_803C0F78[0x27C0] >= 3) {
        fn_800709CC(0xD0002, lbl_80315F4C,
                    remote_bda[0], remote_bda[1], remote_bda[2],
                    remote_bda[3], remote_bda[4], remote_bda[5]);
    }
    if (*(void **)(lbl_803C0F78 + 0x5E0) != NULL) return 2;
    entry = lbl_803C0F78 + 0x34;
    i = 0;
    do {
        if (entry[0x119] == 0)
            goto next;
        switch (memcmp(entry + 8, remote_bda, 6)) {
        case 0:
            goto found;
        default:
            goto next;
        }
next:
        i++;
        entry += 0x11C;
    } while (i < 4);
    entry = NULL;
found:
    if (entry != NULL) {
        btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x5C8), 9, 3);
        *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5E0) = p_cb;
        if (btsnd_hcic_read_rssi(*(u16 *)entry) == 0) {
            *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5E0) = NULL;
            fn_80070F90(lbl_803C0F78 + 0x5C8);
            return 3;
        }
        return 1;
    }
    return 7;
}

tBTM_STATUS BTM_ReadLinkQuality(BD_ADDR remote_bda, tBTM_CMPL_CB *p_cb) {
    u8 *p_dev_rec;
    u32 i;

    if (lbl_803C0F78[0x27C0] >= 3) {
        fn_800709CC(0xD0002, lbl_80315F80,
                    remote_bda[0], remote_bda[1], remote_bda[2],
                    remote_bda[3], remote_bda[4], remote_bda[5]);
    }
    if (*(u32 *)(lbl_803C0F78 + 0x5FC) != 0) {
        return (tBTM_STATUS)2;
    }
    p_dev_rec = lbl_803C0F78 + 0x34;
    i = 0;
    for (; i < 4; i++, p_dev_rec += 0x11C) {
        if (p_dev_rec[0x119] == 0) {
            continue;
        }
        if (memcmp(p_dev_rec + 8, remote_bda, 6) != 0) {
            continue;
        }
        goto found;
    }
    p_dev_rec = NULL;
found:
    if (p_dev_rec == NULL) {
        goto not_found;
    }
    btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x5E4), 9, 3);
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5FC) = p_cb;
    if (((u8 (*)(u16))btsnd_hcic_auth_request_800858B0)(*(u16 *)p_dev_rec) == 0) {
        fn_80070F90(lbl_803C0F78 + 0x5E4);
        *(u32 *)(lbl_803C0F78 + 0x5FC) = 0;
        return (tBTM_STATUS)3;
    }
    return (tBTM_STATUS)1;
not_found:
    return (tBTM_STATUS)7;
}

void btm_read_rssi_complete(u8 *hciEvent) {
    tBTM_CMPL_CB *completionCb;
    tBTM_RSSI_RESULTS results;
    u16 connHandle;
    u8 *aclRec;
    u16 aclIndex;

    completionCb = *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5E0);
    aclRec = lbl_803C0F78 + 0x34;
    fn_80070F90(lbl_803C0F78 + 0x5C8);
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x5E0) = 0;

    if (completionCb != 0) {
        results.hci_status = hciEvent[0];
        if (results.hci_status == 0) {
            results.status = 0;
            connHandle = (u16)(hciEvent[1] + (hciEvent[2] << 8));
            results.rssi = (s8)hciEvent[3];
            if (lbl_803C0F78[0x27C0] >= 4)
                ((void (*)(u32, void *, s32, u32))fn_8007096C)(
                    0xD0003, lbl_80315FBC, results.rssi, results.hci_status);
            for (aclIndex = 0; aclIndex < 4; aclIndex++, aclRec += 0x11C) {
                if (aclRec[0x119] != 0 && connHandle == *(u16 *)aclRec) {
                    memcpy(results.rem_bda, aclRec + 8, 6);
                    break;
                }
            }
        } else {
            results.status = 0xA;
        }
        (*completionCb)(&results);
    }
}

extern char lbl_80315FEC[];
void btm_read_link_quality_complete(u8 *arg0) {
    typedef void (*Callback)(s8 *);
    struct Result {
        s8 result;
        u8 status;
        u8 quality;
        u8 address[6];
    } result;

    u8 *control = lbl_803C0F78;
    Callback callback = *(Callback *)(control + 0x5FC);
    u8 *connection = control + 0x34;
    u8 logLevel;
    u8 high;
    u8 low;
    u8 status;
    u16 handle;
    u8 i;

    fn_80070F90(control + 0x5C8);
    *(Callback *)(control + 0x5FC) = 0;
    if (callback == 0) {
        return;
    }

    status = arg0[0];
    result.status = status;
    if (status == 0) {
        result.result = 0;
        logLevel = control[0x27C0];
        high = arg0[2];
        low = arg0[1];
        result.quality = arg0[3];
        handle = (u16)(low + (high << 8));
        if (logLevel >= 4) {
            ((void (*)(u32, void *))fn_8007096C)(0xD0003, lbl_80315FEC);
        }

        for (i = 0; i < 4; i++, connection += 0x11C) {
            if (connection[0x119] != 0 && handle == *(u16 *)connection) {
                memcpy(result.address, connection + 8, 6);
                break;
            }
        }
    } else {
        result.result = 0xA;
    }

    callback(&result.result);
}

tBTM_STATUS btm_remove_acl(BD_ADDR bd_addr) {
    u32 i = 0;
    u8 *entry = lbl_803C0F78 + 0x34;
    u16 handle;
loop:
    if (entry[0x119] == 0)
        goto next;
    if (memcmp(entry + 8, bd_addr, 6))
        goto next;
    goto found;
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
    u8 *log = lbl_80315CA0;
    u8 *p = lbl_803C0F78 + 0x34;
    u32 i;
    u16 mask, pkt, temp;
    u8 mode, sp8;
    u8 spC[12];
    if (start) {
        for (i = 0; i < 4; ++i, p += 0x11C) {
            if (!p[0x119]) continue;
            if (lbl_803C0F78[0x27C0] >= 5) fn_80070954(0xD0004, log + 0x38C, *(u16 *)p);
            *(u16 *)(p + 4) = *(u16 *)(p + 2);
            pkt = 0x18;
            mode = lbl_803C0F78[0x636];
            if (mode >= 3) pkt |= 0x3300;
            mask = *(u16 *)(lbl_803C0F78 + 0x654);
            temp = pkt & mask & 0xCC18;
            if (mode >= 3) temp |= (pkt | mask) & 0x3306;
            else temp &= ~0x3306;
            if (lbl_803C0F78[0x27C0] >= 4) fn_80070954(0xD0003, log + 0x40, temp);
            if (btsnd_hcic_change_conn_type(*(u16 *)p, temp)) *(u16 *)(p + 2) = temp;
        }
    } else {
        for (i = 0; i < 4; ++i, p += 0x11C) {
            if (!p[0x119]) continue;
            if (!*(u16 *)(p + 4)) continue;
            if (BTM_ReadPowerMode(p + 8, &sp8)) continue;
            if (sp8 == 2) {
                if (lbl_803C0F78[0x27C0] >= 5) fn_80070954(0xD0004, log + 0x3BC, *(u16 *)p);
                spC[8] = 0;
                BTM_SetPowerMode(0x80, p + 8, (void *)spC);
            } else {
                if (lbl_803C0F78[0x27C0] >= 5) fn_8007096C(0xD0004, log + 0x3EC, *(u16 *)p, *(u16 *)(p + 2));
                pkt = *(u16 *)(p + 4);
                mask = *(u16 *)(lbl_803C0F78 + 0x654);
                mode = lbl_803C0F78[0x636];
                temp = pkt & mask & 0xCC18;
                if (mode >= 3) temp |= (pkt | mask) & 0x3306;
                else temp &= ~0x3306;
                if (lbl_803C0F78[0x27C0] >= 4) fn_80070954(0xD0003, log + 0x40, temp);
                if (btsnd_hcic_change_conn_type(*(u16 *)p, temp)) *(u16 *)(p + 2) = temp;
                *(u16 *)(p + 4) = 0;
            }
        }
    }
}

BOOLEAN BTM_SecAddDevice(BD_ADDR bd_addr, DEV_CLASS dev_class, BD_NAME bd_name, BD_FEATURES features, UINT32 trusted_mask[], LINK_KEY link_key, UINT8 key_type, tBTM_IO_CAP io_cap) {
    u32 id;
    s32 i = 0;
    u8 *entry = lbl_803C0F78 + 0x1F30;
loop:
    if ((entry[0x76] & 0x80) == 0)
        goto next;
    if (memcmp(entry + 0x1C, bd_addr, 6) != 0)
        goto next;
    goto found;
next:
    i++;
    entry += 0x88;
    if (i < 16)
        goto loop;
    entry = 0;
found:
    if (entry == 0) {
        entry = (u8 *)btm_sec_alloc_dev(bd_addr);
        if (entry == 0)
            return FALSE;
    }
    id = *(u32 *)(lbl_803C0F78 + 0x1974);
    *(u32 *)(entry + 0xC) = id;
    *(u32 *)(lbl_803C0F78 + 0x1974) = id + 1;
    if (dev_class != 0) {
        memcpy(entry + 0x22, dev_class, 3);
    }
    memset(entry + 0x35, 0, 0x41);
    if (bd_name != 0) {
        if (bd_name[0] != 0) {
            entry[0x76] |= 8;
            strncpy((char *)entry + 0x35, (char *)bd_name, 0x40);
        }
    }
    if (features != 0)
        memcpy(entry + 0x77, features, 8);
    else
        memset(entry + 0x77, 0, 8);
    *(u32 *)(entry + 0x10) = trusted_mask[0];
    *(u32 *)(entry + 0x14) = trusted_mask[1];
    if (link_key != 0) {
        entry[0x76] |= 0x10;
        memcpy(entry + 0x25, link_key, 0x10);
    }
    return TRUE;
}

BOOLEAN BTM_SecDeleteDevice(BD_ADDR bd_addr) {
    int i = 0;
    u8 *entry = lbl_803C0F78 + 0x1F30;
    do {
        if (entry[0x76] & 0x80) {
            if (memcmp(entry + 0x1C, bd_addr, 6) == 0)
                goto found;
        }
        i++;
        entry += 0x88;
    } while (i < 16);
    entry = 0;
found:
    if (entry == 0)
        return FALSE;
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

tBTM_SEC_DEV_REC *btm_sec_alloc_dev(BD_ADDR bd_addr) {
    struct tBTM_SEC_DEV_SLOT_VIEW {
        u8 pad0[0x76];
        u8 in_use;
        u8 pad77[0x11];
    };
    struct tBTM_SEC_CB_VIEW {
        u8 pad0[0x1F30];
        struct tBTM_SEC_DEV_SLOT_VIEW dev[0x10];
    };
    u8 *base;
    u8 *devRec;
    u8 *inqInfo;
    s32 i;

    base = lbl_803C0F78;
    devRec = 0;
    for (i = 0; i < 0x10; i++) {
        if ((base[0x1FA6] & 0x80) == 0) {
            devRec = (u8 *)&((struct tBTM_SEC_CB_VIEW *)lbl_803C0F78)->dev[i];
            break;
        }
        base += 0x88;
    }

    if (devRec == 0)
        devRec = (u8 *)btm_find_oldest_dev();

    /* Allocate/initialize a security device record for bd_addr, copying inquiry page-scan data if known and assigning the next device timestamp/handle. */
    memset(devRec, 0, 0x88);
    devRec[0x76] = 0x80;
    devRec[0x85] = 0;
    inqInfo = (u8 *)BTM_InqDbRead(bd_addr);
    if (inqInfo != 0)
        memcpy(devRec + 0x22, inqInfo + 8, 3);
    else
        memcpy(devRec + 0x22, lbl_803C0F78 + 0x27BA, 3);
    memcpy(devRec + 0x1C, bd_addr, 6);
    *(u16 *)(devRec + 0x18) = BTM_GetHCIConnHandle(bd_addr);
    *(u32 *)(devRec + 0xC) = (*(u32 *)(lbl_803C0F78 + 0x1974))++;
    return (tBTM_SEC_DEV_REC *)devRec;
}

tBTM_SEC_DEV_REC *btm_find_dev_by_handle(UINT16 handle) {
    int index;
    u8 *devRec = lbl_803C0F78 + 0x1F30;
    for (index = 0; index < 16; index++, devRec += 0x88) {
        if ((devRec[0x76] & 0x80) && *(u16 *)(devRec + 0x18) == handle)
            return (tBTM_SEC_DEV_REC *)devRec;
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

/* Returns the oldest BTM security device record: first among in-use, non-linked
 * records by lowest timestamp, or if none qualify, the oldest in-use record. */
tBTM_SEC_DEV_REC *btm_find_oldest_dev(void) {
    struct RecView {
        u8 pad0[0x0C];
        u32 timestamp;
        u8 pad1[0x66];
        u8 sec_flags;
        u8 pad2[0x11];
    };
    struct RecView *deviceRecord = (struct RecView *)(lbl_803C0F78 + 0x1F30);
    struct RecView *candidate = deviceRecord;
    UINT32 oldestTimestamp = 0xFFFFFFFF;
    int index;
    for (index = 0; index < 16; index++, deviceRecord++) {
        if (((deviceRecord->sec_flags & 0x80) == 0) || ((deviceRecord->sec_flags & 0x10) != 0))
            continue;
        if (deviceRecord->timestamp < oldestTimestamp) {
            candidate = deviceRecord;
            oldestTimestamp = deviceRecord->timestamp;
        }
    }
    if (oldestTimestamp != 0xFFFFFFFF)
        return (tBTM_SEC_DEV_REC *)candidate;
    deviceRecord = (struct RecView *)(lbl_803C0F78 + 0x1F30);
    for (index = 0; index < 16; index++, deviceRecord++) {
        if ((deviceRecord->sec_flags & 0x80) == 0)
            continue;
        if (deviceRecord->timestamp < oldestTimestamp) {
            candidate = deviceRecord;
            oldestTimestamp = deviceRecord->timestamp;
        }
    }
    return (tBTM_SEC_DEV_REC *)candidate;
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
// Reset BTM inquiry/discovery databases and invoke pending completion callbacks with reset status.
void btm_db_reset(void) {
    u8 resetStatus = 12;
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
        if (callback) callback(&resetStatus);
    }
    if (*(void (**)(void *))(lbl_803C0F78 + 0x5E0)) {
        void (*callback)(void *) = *(void (**)(void *))(lbl_803C0F78 + 0x5E0);
        *(void (**)(void *))(lbl_803C0F78 + 0x5E0) = NULL;
        if (callback) callback(&resetStatus);
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
    btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 4);
    ((void (*)(void))btsnd_hcic_reset)();
    if (*(void (**)(void *))(lbl_803C0F78 + 0x568) != NULL)
        (*(void (**)(void *))(lbl_803C0F78 + 0x568))((void *)1);
}

/* Send an HCI reset if no other reset callback owns it, tearing down ACL/DB state and starting the reset timer. */
void BTM_SendHciReset(void (*p_cb)(void)) {
    u32 zero = 0;
    if (*(u32 *)(lbl_803C0F78 + 0x58C) != 0 &&
        *(u32 *)(lbl_803C0F78 + 0x58C) != (u32)p_cb &&
        *(u32 *)(lbl_803C0F78 + 0x620) != (u32)p_cb)
        return;
    btm_acl_device_down();
    btm_db_reset();
    *(volatile u32 *)(lbl_803C0F78 + 0x620) = (u32)p_cb;
    *(volatile u8 *)(lbl_803C0F78 + 0x64E) = zero;
    *(volatile u8 *)(lbl_803C0F78 + 0x64F) = 5;
    btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 4);
    ((void (*)(void))btsnd_hcic_reset)();
    if (*(void (**)(void *))(lbl_803C0F78 + 0x568) != NULL)
        (*(void (**)(void *))(lbl_803C0F78 + 0x568))((void *)1);
}

u8 fn_80079514(void) {
    return (u8)((lbl_803C0F78[0x64E] - 5) == 0);
}

/* Set the disabled AFH channel range (first..last), updating HCI only when changed.
 * Returns 0 on success, 3 if no resources, 4 if AFH/device mode is unsupported. */
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

void btm_dev_timeout(struct _tle *arg0) {
    extern void fn_80085828(void *);
    extern void fn_80085524(void *, void *);
    if (*(u32 *)((u8 *)arg0 + 0x10) == 1) {
        switch (lbl_803C0F78[0x64E]) {
        case 0:
            lbl_803C0F78[0x64E] = 0;
            lbl_803C0F78[0x64F] = 5;
            btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 4);
            ((void (*)(void))btsnd_hcic_reset)();
            return;
        case 1: {
            void *buf;
            lbl_803C0F78[0x64E] = 2;
            lbl_803C0F78[0x64F] = 4;
            btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 1);
            buf = GKI_getpoolbuf(2);
            if (buf != NULL) {
                fn_80085828(buf);
            }
            memcpy(lbl_803C0F78 + 0x648, lbl_803C0F78 + 0x648, 3);
            if (lbl_803C0F78[0x64E] != 0 && lbl_803C0F78[0x64E] != 1) {
                buf = GKI_getpoolbuf(2);
                if (buf != NULL) {
                    fn_80085524(buf, lbl_803C0F78 + 0x648);
                }
            }
            if (lbl_803C0F78 != NULL && lbl_803C0F78[0x64E] != 0 && lbl_803C0F78[0x64E] != 1) {
                void *buf2;
                buf2 = GKI_getpoolbuf(2);
                if (buf2 != NULL) {
                    void *dst = lbl_803C0F78;
                    if (lbl_803C0F78 != dst) {
                        memset(lbl_803C0F78, 0, 0x20);
                        strncpy((char *)lbl_803C0F78, (char *)lbl_803C0F78, 0x1F);
                    }
                    ((BOOLEAN (*)(void *, BD_NAME))btsnd_hcic_change_name)(buf2, lbl_803C0F78);
                }
            }
            ((void (*)(u8, void *, u8))BTM_SetPinType)(lbl_803C0F78[0x20], lbl_803C0F78 + 0x22, lbl_803C0F78[0x21]);
            return;
        }
        case 2: {
            u8 v;
            lbl_803C0F78[0x64F] -= 1;
            v = lbl_803C0F78[0x64F];
            if (v == 0) {
                lbl_803C0F78[0x64E] = 0;
                lbl_803C0F78[0x64F] = 5;
                btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 4);
                ((void (*)(void))btsnd_hcic_reset)();
                return;
            }
            btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 1);
            {
                void *buf = GKI_getpoolbuf(2);
                if (buf != NULL) {
                    fn_80085828(buf);
                }
            }
            return;
        }
        case 3: {
            u8 v;
            lbl_803C0F78[0x64F] -= 1;
            v = lbl_803C0F78[0x64F];
            if (v == 0) {
                lbl_803C0F78[0x64E] = 0;
                lbl_803C0F78[0x64F] = 5;
                btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 4);
                ((void (*)(void))btsnd_hcic_reset)();
                return;
            }
            btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x574), 1, 1);
            {
                extern s32 btsnd_hcic_inq_cancel_8008576C(void);
                extern s32 btsnd_hcic_inq_cancel_80085850(void);
                btsnd_hcic_inq_cancel_8008576C();
                btsnd_hcic_inq_cancel_80085850();
            }
            btm_pm_reset();
            return;
        }
        }
        return;
    }
    if (*(u32 *)((u8 *)arg0 + 0x10) == 2) {
        void (*callback)(void *) = *(void (**)(void *))(lbl_803C0F78 + 0x5A8);
        *(void (**)(void *))(lbl_803C0F78 + 0x5A8) = NULL;
        if (callback) callback(NULL);
    }
}

extern void l2cu_device_reset(void);
void btm_reset_complete(void) {
    extern u8 lbl_803C0F78[];
    extern char lbl_803160F0[];
    extern void fn_8007093C(u32, void *);
    extern void fn_80085828();
    void (*callback)(void *);
    void *buf;
    u8 *p;
    u32 two;

    if (lbl_803C0F78[0x27C0] >= 4)
        fn_8007093C(0xD0003, lbl_803160F0);

    callback = *(void (**)(void *))(lbl_803C0F78 + 0x620);
    if (callback != 0) {
        *(void (**)(void *))(lbl_803C0F78 + 0x620) = 0;
        callback(0);
        return;
    }
    if (lbl_803C0F78[0x64E] != 0)
        return;

    l2cu_device_reset();
    *(u16 *)(lbl_803C0F78 + 0x16A0) = 0x12;
    *(u16 *)(lbl_803C0F78 + 0x16A2) = 0x800;
    *(u16 *)(lbl_803C0F78 + 0x16A4) = 0;
    *(u16 *)(lbl_803C0F78 + 0x169C) = 0x12;
    *(u16 *)(lbl_803C0F78 + 0x169E) = 0x800;
    *(u16 *)(lbl_803C0F78 + 0x16A6) = 0;
    two = 2;
    lbl_803C0F78[0x64F] = 4;
    lbl_803C0F78[0x64E] = two;
    if (lbl_803C0F78[0x64E] == 0) {
        lbl_803C0F78[0x64E] = 0;
        lbl_803C0F78[0x64F] = 4;
        btu_start_timer(0, 0, 0);
        ((void (*)(void))btsnd_hcic_reset)();
    } else {
        btu_start_timer(lbl_803C0F78 + 0x574, 1, 1);
        buf = GKI_getpoolbuf(2);
        if (buf != 0)
            ((void (*)(void *))fn_80085828)(buf);
    }

    memcpy(lbl_803C0F78 + 0x648, lbl_803C0F78 + 0x648, 3);

    if (lbl_803C0F78[0x64E] != 0 && lbl_803C0F78[0x64E] != 1) {
        buf = GKI_getpoolbuf(2);
        if (buf != 0)
            fn_80085524(buf, lbl_803C0F78 + 0x648);
    }

    p = lbl_803C0F78;
    if (p != 0 && p[0x64E] != 0 && p[0x64E] != 1) {
        void *buf2;
        buf2 = GKI_getpoolbuf(2);
        if (buf2 != 0) {
            void *dst = p;
            if (p != dst) {
                memset(p, 0, 0x20);
                strncpy((char *)p, (char *)p, 0x1F);
            }
            ((BOOLEAN (*)(void *, BD_NAME))btsnd_hcic_change_name)(buf2, p);
        }
    }
    ((void (*)(u8, void *, u8))BTM_SetPinType)(lbl_803C0F78[0x20], lbl_803C0F78 + 0x22, lbl_803C0F78[0x21]);
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
        *(u16 *)(base + 0x638) = (p[3] << 8) + p[2];
        base[0x63A] = p[4];
        *(u16 *)(base + 0x63C) = (p[6] << 8) + p[5];
        *(u16 *)(base + 0x63E) = (p[8] << 8) + p[7];
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
        *(u16 *)(lbl_803C0F78 + 0x656) = 0;
        *(u8 *)(lbl_803C0F78 + 0x1908) = 0;
        if (cb[0x641] & 8) {
            *(u16 *)(lbl_803C0F78 + 0x656) = 1;
            if (cb[0x641] & 0x10) *(u16 *)(lbl_803C0F78 + 0x656) |= 2;
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
                ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)(0xD0002, strings + 0x40 - 0x40, temp_r27, 0xFF, temp_r29, 0xFF);
            }
            flags = *(u8 *)(lbl_803C0F78 + 0x645);
            if (((flags & 8) || (*(u8 *)(lbl_803C0F78 + 0x644) & 0x10) || (flags & 0x10)) && (((*(u8 *)(lbl_803C0F78 + 0x27BD)) != temp_r27) || ((*(u8 *)(lbl_803C0F78 + 0x27BE)) != temp_r29)) && btsnd_hcic_set_afh_channels(temp_r27, temp_r29)) {
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

/* Set the local Bluetooth device name and send HCI Change_Local_Name (BTM_SetLocalDeviceName). */
tBTM_STATUS BTM_SetLocalDeviceName(char *p_name) {
    void *cmd_buf;
    u8 *btm_cb_ptr;

    if (p_name == NULL) return 5;
    btm_cb_ptr = lbl_803C0F78;
    if (btm_cb_ptr[0x64E] <= 1) return 0xC;
    cmd_buf = GKI_getpoolbuf(2);
    if (cmd_buf != NULL) {
        if ((void *)btm_cb_ptr != (void *)p_name) {
            memset(btm_cb_ptr, 0, 0x20);
            strncpy((char *)btm_cb_ptr, p_name, 0x1F);
        }
        ((BOOLEAN (*)(void *, BD_NAME))btsnd_hcic_change_name)(cmd_buf, btm_cb_ptr);
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
    UINT8 *btmCb;

    /* Sends a vendor-specific HCI command, logging and rejecting if a previous command is still pending. */
    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_8007096C(0xD0003, lbl_8031615C, opcode, param_len);
    }
    btmCb = lbl_803C0F78;
    if (btmCb[0x650] != 0) {
        if (btmCb[0x27C0] >= 4) {
            fn_8007093C(0xD0003, lbl_8031619C);
        }
        return 2;
    }
    buffer = GKI_getbuf(param_len + 0xB);
    if (buffer != 0) {
        *(tBTM_VSC_CMPL_CB **)(btmCb + 0x61C) = p_cb;
        if (p_cb != 0) {
            btmCb[0x650] = 1;
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

/* btm_cb.page_timeout: the page timeout in milliseconds.  BTM_WritePageTimeout
   takes it in 0.625 ms slots and converts it; the BTA search times its SDP
   database with it. */
#define BTM_CB_PAGE_TIMEOUT (*(u16 *)(lbl_803C0F78 + 0x64C))

/* The game's btsnd_hcic_write_page_tout: writes the HCI Write_Page_Timeout
   command (opcode 0x0C18) into a buffer the caller took from the command pool
   and hands it to the BTU task. */
#define btsnd_hcic_write_page_tout fn_8008534C

extern char lbl_80316220[]; /* "BTM: BTM_WritePageTimeout: Timeout: %d." */
extern void fn_8008534C(void *, u16);
/* Sends the HCI Write_Page_Timeout command to the controller, and remembers the
   timeout - given in 0.625 ms slots - in btm_cb as milliseconds. */
tBTM_STATUS BTM_WritePageTimeout(UINT16 timeout) {
    void *cmd_buf;
    if (btm_cb_trace_level >= BTM_TRACE_LEVEL_EVENT) {
        fn_80070954(TRACE_LAYER_BTM | TRACE_TYPE_EVENT, lbl_80316220, timeout);
    }
    BTM_CB_PAGE_TIMEOUT = (timeout * 625) / 1000;
    cmd_buf = GKI_getpoolbuf(BTM_CMD_POOL_ID);
    if (cmd_buf != NULL) {
        btsnd_hcic_write_page_tout(cmd_buf, timeout);
        return BTM_SUCCESS;
    }
    return BTM_NO_RESOURCES;
}

/* Reads stored link key(s) for bdAddr (or all if NULL) via HCI and invokes completionCb when done. */
tBTM_STATUS BTM_ReadStoredLinkKey(BD_ADDR bdAddr, tBTM_CMPL_CB *completionCb) {
    extern char lbl_80316290[];
    extern u8 lbl_80559064;
    extern u8 lbl_8055906C;
    BD_ADDR tempBdAddr;
    BOOLEAN readAll = FALSE;
    u8 *cmdBuf;

    if (*(u32 *)(lbl_803C0F78 + 0x570) != 0)
        return BTM_BUSY;
    if (bdAddr == NULL) {
        readAll = TRUE;
        bdAddr = tempBdAddr;
    }
    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_80070954(
            0xD0003,
            lbl_80316290,
            readAll ? (u16)&lbl_80559064 : (u16)&lbl_8055906C
        );
    }
    cmdBuf = GKI_getpoolbuf(2);
    if (cmdBuf != NULL) {
        *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570) = completionCb;
        ((void (*)())btsnd_hcic_read_stored_key)(cmdBuf, bdAddr, readAll, lbl_803C0F78);
        return BTM_SUCCESS;
    }
    return BTM_NO_RESOURCES;
}

extern char lbl_803162BC[];
tBTM_STATUS BTM_WriteStoredLinkKey(UINT8 num_keys, BD_ADDR *bd_addr, LINK_KEY *link_key, tBTM_CMPL_CB *p_cb) {
    /* Write up to 11 stored link keys to the controller (HCI Write_Stored_Link_Key). */
    void *cmdBuf;

    if (*(u32 *)(lbl_803C0F78 + 0x570) != 0)
        return BTM_BUSY;

    if (*(u8 *)(lbl_803C0F78 + 0x27C0) >= 4)
        fn_80070954(0xD0003, lbl_803162BC, num_keys);

    if (num_keys > 0xB)
        num_keys = 0xB;

    cmdBuf = GKI_getpoolbuf(2);
    if (cmdBuf != NULL) {
        *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570) = p_cb;
        ((void (*)(void *, UINT8, BD_ADDR *, LINK_KEY *))btsnd_hcic_write_stored_key)(
            cmdBuf, num_keys, bd_addr, link_key
        );
        return BTM_SUCCESS;
    }
    return BTM_NO_RESOURCES;
}

tBTM_STATUS BTM_DeleteStoredLinkKey(BD_ADDR bdAddr, tBTM_CMPL_CB *completionCb) {
    extern u8 lbl_803162E8[];
    extern u8 lbl_80559064;
    extern u8 lbl_8055906C;
    extern s32 btsnd_hcic_switch_role_8008515C(BD_ADDR, UINT8);
    BD_ADDR tempBdAddr;
    BOOLEAN deleteAll = FALSE;

    if (*(u32 *)(lbl_803C0F78 + 0x570) != 0)
        return BTM_BUSY;
    if (bdAddr == NULL) {
        deleteAll = TRUE;
        bdAddr = tempBdAddr;
    }
    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_80070954(
            0xD0003,
            lbl_803162E8,
            deleteAll ? (u16)&lbl_80559064 : (u16)&lbl_8055906C
        );
    }
    /* Requests deletion of one stored link key (or all when bdAddr is NULL) and records the completion callback. */
    *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570) = completionCb;
    if ((u8)btsnd_hcic_switch_role_8008515C(bdAddr, deleteAll) == 0)
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

/* Reverses each returned BD address and link key in place, then invokes the registered completion callback. */
void btm_return_link_keys_evt(tBTM_RETURN_LINK_KEYS_EVT *result) {
    tBTM_CMPL_CB *completionCb = *(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x570);
    UINT8 keyIndex, *recordPtr, *readPtr;
    UINT8 bdAddr[BD_ADDR_LEN];
    UINT8 linkKey[LINK_KEY_LEN];
    if (completionCb) {
        recordPtr = (UINT8 *)(result + 1);
        for (keyIndex = 0; keyIndex < result->num_keys; keyIndex++) {
            readPtr = recordPtr;
            REVERSE_STREAM_TO_ARRAY(bdAddr, readPtr, BD_ADDR_LEN);
            REVERSE_STREAM_TO_ARRAY(linkKey, readPtr, LINK_KEY_LEN);
            ARRAY_TO_STREAM(recordPtr, bdAddr, BD_ADDR_LEN);
            ARRAY_TO_STREAM(recordPtr, linkKey, LINK_KEY_LEN);
        }
        (*completionCb)(result);
    }
}

void fn_8007ABE8(void *arg0) {
    void (*callback)(void *) = *(void (**)(void *))(lbl_803C0F78 + 0x568);
    if (callback != 0)
        callback(arg0);
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
    /* Reset discovery state/timer and reinitialize the SDP discovery database. */
    void (*discoveryCmplCallback)(s32);

    fn_80070F90(lbl_803C0F78 + 0x658);
    if (lbl_803C0F78[0x1674] != 0) {
        discoveryCmplCallback = *(void (**)(s32))(lbl_803C0F78 + 0x6D0);
        lbl_803C0F78[0x1674] = 0;
        *(void (**)(s32))(lbl_803C0F78 + 0x6D0) = 0;
        if (discoveryCmplCallback != 0)
            discoveryCmplCallback(0);
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

tBTM_STATUS BTM_SetInquiryScanType(UINT16 scan_type) {
    /* Sets the inquiry scan type in BTM state and sends the HCI command if
       interlaced scan is supported, the stack is in the right mode, and the
       requested type differs from the current one. */
    void *p_cmd_buf;
    tBTM_STATUS status;

    if (scan_type != BTM_SCAN_TYPE_STANDARD && scan_type != BTM_SCAN_TYPE_INTERLACED)
        return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x10))
        return BTM_MODE_UNSUPPORTED;
    if (scan_type != *(u16 *)(lbl_803C0F78 + 0x16A4)) {
        if ((u8)fn_80079514() != 0) {
            p_cmd_buf = GKI_getpoolbuf(2);
            if (p_cmd_buf != 0) {
                fn_80085DC4(p_cmd_buf, (u8)scan_type);
                *(u16 *)(lbl_803C0F78 + 0x16A4) = scan_type;
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
/* Set the page scan type (0=standard, 1=interlaced) in the controller if supported. */
tBTM_STATUS BTM_SetPageScanType(UINT16 scanType) {
    void *p_buf;
    tBTM_STATUS status;
    if (scanType != 0 && scanType != 1) return BTM_ILLEGAL_VALUE;
    if (!(lbl_803C0F78[0x643] & 0x20)) return BTM_MODE_UNSUPPORTED;
    if (scanType != *(u16 *)(lbl_803C0F78 + 0x16A6)) {
        if ((u8)fn_80079514() != 0) {
            p_buf = GKI_getpoolbuf(2);
            if (p_buf != 0) {
                fn_80085E24(p_buf, (u8)scanType);
                *(u16 *)(lbl_803C0F78 + 0x16A6) = scanType;
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
    /* Sets BR/EDR page scan connectability (mode 0/1), updating page scan
       window/interval and HCI scan enable as needed; returns BTM status. */
    register s32 connectableMode = page_mode;
    register u8 *btmCb = lbl_803C0F78;
    register u8 scanEnable = 0;
    register s32 pageInterval = interval;
    register s32 pageWindow = window;

    if (connectableMode == 0 || (u32)connectableMode == 1U)
        goto valid_mode;
    return 5;

valid_mode:
    if (lbl_803C0F78[0x64E] < 3)
        return 0xC;

    if (pageWindow == 0)
        pageWindow = 0x12;
    if (pageInterval == 0)
        pageInterval = 0x800;

    if (lbl_803C0F78[0x27C0] >= 3)
        ((void (*)(u32, void *, u16, u16, u16))fn_80070984)(
            0xD0002, lbl_8031637C, (u16)connectableMode, (u16)pageWindow, (u16)pageInterval);

    if ((u32)connectableMode == 1U) {
        if ((u32)pageWindow < 0x12U || (u32)pageWindow > 0x1000U ||
            (u32)pageInterval < 0x12U || (u32)pageInterval > 0x1000U ||
            (u32)pageWindow > (u32)pageInterval)
            return 5;
        scanEnable |= 2;
    }

    if ((u32)pageWindow != *(u16 *)(btmCb + 0x169C) ||
        (u32)pageInterval != *(u16 *)(btmCb + 0x169E)) {
        u8 *cmdBuf = GKI_getpoolbuf(2);
        if (cmdBuf == 0)
            goto no_buffer_first;
        *(u16 *)(btmCb + 0x169C) = (u16)pageWindow;
        *(u16 *)(btmCb + 0x169E) = (u16)pageInterval;
        fn_800853B4(cmdBuf, (u16)pageInterval, (u16)pageWindow);
        goto after_first_error;
no_buffer_first:
        return 3;
after_first_error:
        ;
    }

    {
        u8 *cmdBuf = GKI_getpoolbuf(2);
        if (cmdBuf == 0)
            goto no_buffer_second;
        if (*(u16 *)(btmCb + 0x1698) != 0)
            scanEnable |= 1;
        *(u16 *)(btmCb + 0x169A) = (u16)connectableMode;
        fn_80085384(cmdBuf, scanEnable);
        goto done;
no_buffer_second:
        return 3;
    }

done:
    return 0;
}

u8 fn_8007B340(void) {
    return lbl_803C0F78[0x1848];
}

extern u8 lbl_803163D0[];
tBTM_STATUS BTM_CancelInquiry(void) {
    u8 *btmCb2;
    u8 *btmCb = lbl_803C0F78;
    tBTM_STATUS status = 0;
    /* Cancel an active inquiry: log if busy, refuse when not ready, clear inquiry
       state (or complete pending cancel via HCI), bump the cancel count, and free
       any queued inquiry result buffer. */
    if (btmCb[0x27C0] >= 3) fn_8007093C(0xD0002, lbl_803163D0);
    if (fn_80079514() == 0) return 6;
    if (btmCb[0x1848] != 0 && !(btmCb[0x1848] & 4)) {
        btmCb[0x1848] = 0;
        btmCb[0x1847] = 0;
        *(u32 *)(btmCb + 0x16B4) = 0;
        *(u32 *)(btmCb + 0x16B0) = 0;
        if (btmCb[0x1844] != 0) {
            btmCb[0x1844] = 0;
            btmCb[0x1845]++;
        } else if (btsnd_hcic_inq_cancel() == 0) status = 3;
        btmCb2 = lbl_803C0F78;
        *(u32 *)(btmCb + 0x16C0) += 1;
        if (*(void **)(btmCb2 + 0x16DC) != NULL) {
            GKI_freebuf(*(void **)(btmCb2 + 0x16DC));
            *(u32 *)(btmCb2 + 0x16DC) = 0;
        }
        *(u16 *)(btmCb2 + 0x16E0) = 0;
        *(u16 *)(btmCb2 + 0x16E2) = 0;
    }
    return status;
}

tBTM_STATUS BTM_StartInquiry(tBTM_INQ_PARMS *params, tBTM_INQ_RESULTS_CB *results_cb, tBTM_CMPL_CB *complete_cb) {
    extern u8 lbl_803163EC[];
    u8 *state = lbl_803C0F78;
    u8 *p = (u8 *)params;
    u32 b, a, d, c, f, e;
    s32 mode, filter;
    u8 status;
    if (state[0x27C0] >= 3)
        ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)(0xD0002, lbl_803163EC, p[0], p[1], p[2], p[3]);
    if (state[0x1848] != 0 || state[0x1844] != 0) return 2;
    if (p[0] != 0 && p[0] != 1) return 5;
    if (fn_80079514() == 0) return 6;
    a=p[0]; b=p[1]; state[0x1834]=a; state[0x1835]=b;
    c=p[3]; d=p[2]; state[0x1836]=d; state[0x1837]=c;
    e=p[5]; f=p[4]; state[0x1838]=f; state[0x1839]=e;
    a=p[7]; b=p[6]; state[0x183A]=b; state[0x183B]=a;
    c=p[8]; state[0x183C]=c;
    c=p[9]; state[0x183D]=c;
    state[0x1847]=3;
    *(void **)(state+0x16B0)=complete_cb;
    *(void **)(state+0x16B4)=results_cb;
    state[0x183F]=0;
    mode=p[0];
    state[0x1848]=((s32)~((mode-1)|(1-mode))>>31)+2;
    filter=p[3];
    if (filter==0) goto mode_two;
    if (filter<0) goto invalid_filter;
    if (filter>=3) goto invalid_filter;
    goto mode_one;
invalid_filter:
    return 5;
mode_two:
    state[0x1847]=2;
    goto after_filter;
mode_one:
    state[0x1847]=1;
    p[3]=0;
after_filter:
    status=btm_set_inq_event_filter(p[3],p+4);
    if (status!=1) state[0x1847]=0;
    return status;
}

#pragma push
#pragma use_lmw_stmw off
/* Reads a remote device's name, using cached inquiry info when available. */
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

tBTM_STATUS BTM_CancelRemoteDeviceName(void) {
    u8 *base = lbl_803C0F78;
    if (base[0x27C0] >= 3)
        fn_8007093C(0xD0002, lbl_80316464);
    if (base[0x16AE] & 1) {
        if ((u8)btsnd_hcic_link_key_neg_reply_800843D8(base + 0x16A8) != 0)
            return 1;
        return 3;
    } else
        return 6;
}

#pragma pop

tBTM_INQ_INFO *BTM_InqDbRead(BD_ADDR p_bda) {
    /* Look up a device by BD_ADDR in the BTM inquiry database and return its inquiry info, or NULL if not found. */
    extern char lbl_80316484[];
    u32 index;
    u8 *btmCb = lbl_803C0F78;
    u8 *inqEntry = btmCb + 0x16E4;

    if (btmCb[0x27C0] >= 3) {
        fn_800709CC(0xD0002, lbl_80316484,
                    p_bda[0], p_bda[1], p_bda[2],
                    p_bda[3], p_bda[4], p_bda[5]);
    }

    for (index = 0; index < 0xC; index++, inqEntry += 0x1C) {
        if (inqEntry[0x1A] != 0 && memcmp(inqEntry + 0xA, p_bda, 6) == 0)
            return (tBTM_INQ_INFO *)(inqEntry + 8);
    }
    return NULL;
}

tBTM_INQ_INFO *BTM_InqDbFirst(void) {
    /* Return the first in-use inquiry database entry, or NULL if none. */
    UINT16 index;
    u8 *dbEntry = lbl_803C0F78 + 0x16E4;

    for (index = 0; index < 12; index++, dbEntry += 0x1C) {
        if (dbEntry[0x1A])
            return (tBTM_INQ_INFO *)(dbEntry + 8);
    }

    return 0;
}

tBTM_INQ_INFO *BTM_InqDbNext(tBTM_INQ_INFO *p_cur) {
    u8 *base;
    u8 *entry;
    u16 index;
    u16 xx;

    if (p_cur != 0) {
        base = lbl_803C0F78;
        index = (u16)(((u8 *)p_cur - 8 - (base + 0x16E4)) / 28 + 1);
        entry = base + 0x16E4;
        entry += (u32)index * 0x1C;
        for (; index < 12; index++, entry += 0x1C) {
            if (entry[0x1A] != 0)
                return (tBTM_INQ_INFO *)(entry + 8);
        }
        return 0;
    }
    entry = lbl_803C0F78 + 0x16E4;
    for (xx = 0; xx < 12; xx++, entry += 0x1C) {
        if (entry[0x1A])
            return (tBTM_INQ_INFO *)(entry + 8);
    }
    return 0;
}

tBTM_STATUS BTM_ClearInqDb(BD_ADDR p_bda) {
    u8 *base;
    u16 i;
    u8 *entry;
    tBTM_INQ_DB_CHANGE_CB *callback;
    if (lbl_803C0F78[0x1848] != 0 || lbl_803C0F78[0x16AE] != 0 || lbl_803C0F78[0x1844] != 0)
        return BTM_BUSY;
    base = lbl_803C0F78;
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
    u8 *base = lbl_803C0F78;
    u8 *loopBase;
    u32 zero;
    tBTM_REMOTE_DEV_NAME rem_name;
    u8 num_responses;
    u8 value;
    u8 temp_inq_active;
    u32 i;
    u8 *entry = 0;
    fn_80070F90(base + 0x16C4);
    if (base[0x1848] != 0) {
        temp_inq_active = base[0x1848];
        base[0x1848] = 0;
        temp_inq_active += 0xFF;
        if (temp_inq_active <= 1) {
            if (*(void (**)(void *))(base + 0x16B0) != 0) {
                num_responses = 0;
                (*(void (**)(void *))(base + 0x16B0))(&num_responses);
            }
        }
    }
    if (base[0x16AE] & 1) {
        fn_80070F90(base + 0x1680);
        base[0x16AE] = 0;
        memset(base + 0x16A8, 0, 6);
        if (*(void (**)(void *))(base + 0x167C) != 0) {
            rem_name.status = 0x000C;
            (*(void (**)(void *))(base + 0x167C))(&rem_name);
            *(void (**)(void *))(base + 0x167C) = 0;
        }
    }
    if (base[0x1844] != 0) {
        base[0x1844] = 0;
        if (*(void (**)(void *))(base + 0x16B8) != 0) {
            value = 0x0C;
            (*(void (**)(void *))(base + 0x16B8))(&value);
        }
    }
    zero = 0;
    loopBase = lbl_803C0F78;
    base[0x1847] = (u8)zero;
    base[0x1845] = (u8)zero;
    *(u32 *)(base + 0x16B4) = zero;
    for (i = 0, entry = loopBase + 0x16E4; i < 12; i++, entry += 0x1C) {
        if (entry[0x1A] != 0) {
            entry[0x1A] = (u8)zero;
            if (*(void (**)(void *, u32))(loopBase + 0x16BC) != 0)
                (*(void (**)(void *, u32))(loopBase + 0x16BC))(entry + 8, 0);
        }
    }
    if (*(void **)(loopBase + 0x16DC) != 0) {
        GKI_freebuf(*(void **)(loopBase + 0x16DC));
        *(void **)(loopBase + 0x16DC) = 0;
    }
    *(u16 *)(loopBase + 0x16E0) = 0;
    *(u16 *)(loopBase + 0x16E2) = 0;
    *(u16 *)(base + 0x1698) = 0;
    *(u16 *)(base + 0x169A) = 0;
    *(u16 *)(base + 0x16A6) = 0;
    *(u16 *)(base + 0x16A4) = 0;
}

void fn_8007BC88(void) {

}

/* Check if a peer BD_ADDR was already reported in the current inquiry; if not and there is space, record it. */
BOOLEAN btm_inq_find_bdaddr(BD_ADDR p_bda) {
    u8 *p_btm_cb = lbl_803C0F78;
    u16 inq_count;
    u8 *p_inq_ent;
    u16 i;

    p_inq_ent = *(u8 **)(p_btm_cb + 0x16DC);
    if ((p_btm_cb[0x1848] & 4) != 0 || p_inq_ent == NULL)
        return FALSE;
    inq_count = *(u16 *)(p_btm_cb + 0x16E0);
    for (i = 0; i < inq_count; i++, p_inq_ent += 0xC) {
        if (memcmp(p_inq_ent + 4, p_bda, 6) == 0 &&
            *(u32 *)p_inq_ent == *(u32 *)(p_btm_cb + 0x16C0))
            return TRUE;
    }
    if (i < *(u16 *)(p_btm_cb + 0x16E2)) {
        *(u32 *)p_inq_ent = *(u32 *)(p_btm_cb + 0x16C0);
        memcpy(p_inq_ent + 4, p_bda, 6);
        *(u16 *)(p_btm_cb + 0x16E0) = *(u16 *)(p_btm_cb + 0x16E0) + 1;
    }
    return FALSE;
}

/* Returns an inquiry DB entry for p_bda: uses the first free slot (cleared and
 * marked in use) or evicts the oldest by time stamp, notifying the change
 * callback before overwriting it. */
tINQ_DB_ENT *btm_inq_db_new(BD_ADDR p_bda) {
    UINT16 index;
    u8 *entry;
    u8 *oldest;
    UINT32 oldestTime;
    tBTM_INQ_DB_CHANGE_CB *changeCb;

    entry = lbl_803C0F78 + 0x16E4;
    oldest = entry;
    oldestTime = 0xFFFFFFFF;
    for (index = 0; index < 0xC; index++, entry += 0x1C) {
        if (!entry[0x1A]) {
            memset(entry, 0, 0x1C);
            memcpy(entry + 0xA, p_bda, BD_ADDR_LEN);
            entry[0x1A] = TRUE;
            return (tINQ_DB_ENT *)entry;
        }
        if (*(UINT32 *)entry < oldestTime) {
            oldest = entry;
            oldestTime = *(UINT32 *)entry;
        }
    }
    changeCb = *(tBTM_INQ_DB_CHANGE_CB **)(lbl_803C0F78 + 0x16BC);
    if (changeCb)
        (*changeCb)(oldest + 8, FALSE);
    memset(oldest, 0, 0x1C);
    memcpy(oldest + 0xA, p_bda, BD_ADDR_LEN);
    oldest[0x1A] = TRUE;
    return (tINQ_DB_ENT *)oldest;
}

static tBTM_STATUS btm_set_inq_event_filter(UINT8 filter_cond_type, UINT8 *p_filt_cond) {
    /* Set the HCI inquiry event filter (clear, device class, or BD address)
     * and record that an inquiry filter is active. */
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

/*
 * btm_cb.btm_inq_vars - the inquiry variables inside the BTM control block
 * (lbl_803C0F78) - as this build lays them out.  btm_int.h's
 * tBTM_INQUIRY_VAR_ST describes a newer stack (inq_db[BTM_INQ_DB_SIZE] with
 * 40 entries, an extra tBTM_INQ_PARMS.report_dup, other inq_active masks),
 * while this one has 12 inquiry database entries of 0x1C bytes (see
 * btm_inq_db_new) and an inqparms without report_dup, starting at 0x1834:
 * mode, duration, max_resps, filter_cond_type and the 3-byte filter_cond.
 * So the members are named by offset and read through a byte pointer; reading
 * them through a struct view changes how the compiler allocates registers.
 */
#define BTM_INQ_DB_SIZE_HERE      12  /* inq_db[] entries in this build */
#define btm_cb_inqfilter_cmpl_cb  (*(tBTM_CMPL_CB **)(lbl_803C0F78 + 0x16B8))
#define btm_cb_inq_p_bd_db        (*(tINQ_BDADDR **)(lbl_803C0F78 + 0x16DC))
#define btm_cb_inq_num_bd_entries (*(UINT16 *)(lbl_803C0F78 + 0x16E0))
#define btm_cb_inq_max_bd_entries (*(UINT16 *)(lbl_803C0F78 + 0x16E2))
#define btm_cb_inq_mode           (lbl_803C0F78[0x1834]) /* tBTM_INQ_PARMS.mode */
#define btm_cb_inq_duration       (lbl_803C0F78[0x1835])
#define btm_cb_inq_max_resps      (lbl_803C0F78[0x1836])
#define btm_cb_inq_filter_type    (lbl_803C0F78[0x1837])
#define btm_cb_inq_filter_cond    (lbl_803C0F78 + 0x1838)
#define btm_cb_per_inq_min_delay  (*(UINT16 *)(lbl_803C0F78 + 0x1840))
#define btm_cb_per_inq_max_delay  (*(UINT16 *)(lbl_803C0F78 + 0x1842))
#define btm_cb_inqfilt_active     (lbl_803C0F78[0x1844])
#define btm_cb_pending_filt_cmpl  (lbl_803C0F78[0x1845])
#define btm_cb_inq_state          (lbl_803C0F78[0x1847])
#define btm_cb_inq_active         (lbl_803C0F78[0x1848])

/* btm_inq.c's two static inquiry access codes; the game's symbols still carry
   their lbl_ names, so they are aliased here (0x9e8b33 / 0x9e8b00). */
#define general_inq_lap           lbl_80560D30
#define limited_inq_lap           lbl_80560D34

/* inq_active masks as this build numbers them; btm_api.h's are the newer
   stack's (LIMITED 0x2, SSP 0x4, PERIODIC 0x8). */
#define BTM_LIMITED_INQUIRY_ACTIVE_HERE   0x1
#define BTM_PERIODIC_INQUIRY_ACTIVE_HERE  0x4

/*
 * The same btm_cb.btm_inq_vars members through the byte pointer a function
 * keeps in a register (btm_event_filter_complete holds &btm_cb in one, and
 * btm_initiate_inquiry is inlined into it).  The macros above fold to
 * lbl_803C0F78 and cost the compiler an extra address load, so these take the
 * pointer as an argument.
 */
#define btm_inq_filt_cmpl_cb(b)   (*(tBTM_CMPL_CB **)((b) + 0x16B8)) /* p_inqfilter_cmpl_cb */
#define btm_inq_bd_db(b)          (*(tINQ_BDADDR **)((b) + 0x16DC))  /* p_bd_db: answers so far */
#define btm_inq_num_bd(b)         (*(UINT16 *)((b) + 0x16E0))        /* num_bd_entries */
#define btm_inq_max_bd(b)         (*(UINT16 *)((b) + 0x16E2))        /* max_bd_entries */
#define btm_inq_duration(b)       ((b)[0x1835])                      /* inqparms.duration */
#define btm_inq_max_resps(b)      ((b)[0x1836])                      /* inqparms.max_resps */
#define btm_inq_filt_type(b)      ((b)[0x1837])                      /* inqparms.filter_cond_type */
#define btm_inq_filt_cond(b)      ((b) + 0x1838)                     /* inqparms.filter_cond */
#define btm_inq_per_min_delay(b)  (*(UINT16 *)((b) + 0x1840))        /* per_min_delay */
#define btm_inq_per_max_delay(b)  (*(UINT16 *)((b) + 0x1842))        /* per_max_delay */
#define btm_inq_filt_active(b)    ((b)[0x1844])                      /* inqfilt_active */
#define btm_inq_pending_cmpl(b)   ((b)[0x1845])                      /* pending_filt_complete_event */
#define btm_inq_state(b)          ((b)[0x1847])                      /* BTM_INQ_*_STATE */
#define btm_inq_active(b)         ((b)[0x1848])                      /* BTM_*_INQUIRY_ACTIVE masks */

/* This build's largest GKI buffer (pool 3, see gki_buffer_init) and how many
   12-byte tINQ_BDADDR entries fit in it; btm_initiate_inquiry() allocates one
   to record the addresses that answer an inquiry.  gki_target.h's
   GKI_MAX_BUF_SIZE is a newer, bigger configuration. */
#define BTM_INQ_BD_BUF_SIZE_HERE    0x708
#define BTM_INQ_BD_BUF_ENTRIES_HERE (BTM_INQ_BD_BUF_SIZE_HERE / sizeof(tINQ_BDADDR))

/*
 * btm_inq.c: a Set Event Filter command has completed.  btu_hcif_hdl_command_complete
 * calls this with the parameter part of the HCI Command Complete event, whose
 * first byte is the HCI status.  Only the inquiry filter is used here: the
 * status decides whether the inquiry carries on to the next filter state or
 * ends, and a filter set on its own (no inquiry active) is simply reported to
 * the caller's completion callback.  The last branch is btm_initiate_inquiry(),
 * which this build inlines.
 */
void btm_event_filter_complete(UINT8 *p_param) {
    u8 *cb_clr;                     /* the inlined btm_clr_inq_result_flt()'s view */
    u8 *cb = lbl_803C0F78;          /* the BTM control block */
    u8 *lap;                        /* the access code to inquire against */
    tBTM_STATUS status;
    tBTM_CMPL_CB *p_cb = btm_inq_filt_cmpl_cb(cb);

    /* a filter command this state sent on its own is only counted out */
    if (btm_inq_pending_cmpl(cb)) { btm_inq_pending_cmpl(cb)--; return; }
    if (btm_inq_filt_active(cb) != TRUE) return;

    if (*p_param != HCI_SUCCESS) {
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_WARNING)
            fn_80070954(TRACE_LAYER_BTM | TRACE_TYPE_WARNING, lbl_803164B8, *p_param); /* "BTM Warning: Set Event Filter Failed (HCI returned 0x%x)" */
        status = BTM_ERR_PROCESSING;
    } else {
        status = BTM_SUCCESS;
    }

    if (btm_inq_state(cb) == BTM_INQ_INACTIVE_STATE) {
        /* the filter was set by BTM_SetEventFilter(): report it and stop */
        btm_inq_filt_active(cb) = FALSE;
        if (p_cb) {
            p_cb(&status);
        }
    } else if (status != BTM_SUCCESS) {
        ((void (*)(UINT8))btm_process_inq_complete)(BTM_ERR_PROCESSING);
        btm_inq_filt_active(cb) = FALSE;
        btm_inq_active(cb) = BTM_INQUIRY_INACTIVE;
        btm_inq_state(cb) = BTM_INQ_INACTIVE_STATE;
    } else if (btm_inq_state(cb) == BTM_INQ_CLR_FILT_STATE) {
        /* the inquiry's own filter is off again: set the caller's and wait */
        status = btm_set_inq_event_filter(btm_inq_filt_type(cb), btm_inq_filt_cond(cb));
        if (status == BTM_CMD_STARTED) {
            btm_inq_state(cb) = BTM_INQ_SET_FILT_STATE;
        } else {
            btm_inq_filt_active(cb) = FALSE;
            ((void (*)(UINT8))btm_process_inq_complete)(BTM_ERR_PROCESSING);
        }
    } else {
        /* --- btm_initiate_inquiry(), inlined --- */
        UINT8 old_max_resps = btm_inq_max_resps(cb);
        int zero = 0;                /* the compiler keeps the 0 in a register here */

        btm_inq_state(cb) = BTM_INQ_ACTIVE_STATE;
        btm_inq_filt_active(cb) = zero;
        /* never ask the controller for more answers than the inquiry database holds */
        btm_inq_max_resps(cb) = (old_max_resps <= BTM_INQ_DB_SIZE_HERE) ? old_max_resps : BTM_INQ_DB_SIZE_HERE;

        lap = general_inq_lap;
        if (btm_inq_active(cb) & BTM_LIMITED_INQUIRY_ACTIVE_HERE) {
            lap = limited_inq_lap;
        }

        if (btm_inq_active(cb) & BTM_PERIODIC_INQUIRY_ACTIVE_HERE) {
            if (!btsnd_hcic_per_inq_mode(btm_inq_per_max_delay(cb), btm_inq_per_min_delay(cb),
                                         lap, btm_inq_duration(cb), btm_inq_max_resps(cb))) {
                ((void (*)(UINT8))btm_process_inq_complete)(BTM_NO_RESOURCES);
            }
        } else {
            /* btm_clr_inq_result_flt(): start the list of answering addresses afresh */
            cb_clr = lbl_803C0F78;
            if (btm_inq_bd_db(cb_clr)) {
                GKI_freebuf(btm_inq_bd_db(cb_clr));
                btm_inq_bd_db(cb_clr) = NULL;
            }
            btm_inq_num_bd(cb_clr) = 0;
            btm_inq_max_bd(cb_clr) = 0;

            btm_inq_bd_db(cb) = GKI_getbuf(BTM_INQ_BD_BUF_SIZE_HERE);
            if (btm_inq_bd_db(cb)) {
                btm_inq_max_bd(cb) = BTM_INQ_BD_BUF_ENTRIES_HERE;
                memset(btm_inq_bd_db(cb), 0, BTM_INQ_BD_BUF_SIZE_HERE);
            }
            if (!btsnd_hcic_inquiry(lap, btm_inq_duration(cb), 0)) {
                ((void (*)(UINT8))btm_process_inq_complete)(BTM_NO_RESOURCES);
            }
        }
    }
}

void btm_process_inq_results(UINT8 *p, UINT8 mode)
{
    UINT8 n, i;
    UINT8 bda[6];
    UINT8 *entry;
    UINT8 *base = lbl_803C0F78;
    UINT32 is_new = 1;
    void (*cb)(void *) = *(void (**)(void *))(base + 0x16b4);
    UINT8 rssi = 0, scan = 0, per = 0, rep = 0;
    UINT8 dc[3];
    UINT16 clock;
    UINT8 j;
    if (!base[0x1848]) return;
    n = *p++;
    for (i = 0; i < n; i++) {
        bda[5] = *p++; bda[4] = *p++; bda[3] = *p++;
        bda[2] = *p++; bda[1] = *p++; bda[0] = *p++;
        rep = *p++; per = *p++;
        if (!mode) scan = *p++;
        dc[2] = *p++; dc[1] = *p++; dc[0] = *p++;
        clock = p[0] + (p[1] << 8); p += 2;
        if (mode) rssi = *p++;
        if (btm_inq_find_bdaddr(bda)) continue;
        if (*(UINT8 (**)(UINT8 *, UINT8 *))(base + 0x184c) &&
            !(*(UINT8 (**)(UINT8 *, UINT8 *))(base + 0x184c))(bda, dc)) continue;
        entry = base + 0x16e4;
        j = 0;
        do {
            if (entry[0x1a] && !memcmp(entry + 0xa, bda, 6)) goto found;
            j++; entry += 0x1c;
        } while (j < 12);
        entry = 0;
found:
        if (!entry) { entry = (UINT8 *)btm_inq_db_new(bda); is_new = 1; }
        else if (*(UINT32 *)(entry + 4) == *(UINT32 *)(base + 0x16c0)) is_new = 0;
        if (is_new == 1) {
            entry[0x13] = rep; entry[0x14] = per; 
            entry[0x15] = scan;
            entry[0x10] = dc[0]; entry[0x11] = dc[1]; entry[0x12] = dc[2];
            *(UINT16 *)(entry + 8) = clock | 0x8000;
            if (mode) entry[0x8 + 0xe] = rssi; else entry[0x8 + 0xe] = 0x7f;
            *(UINT32 *)entry = fn_8006E4F8();
            *(UINT32 *)(entry + 4) = *(UINT32 *)(base + 0x16c0);
            base[0x183f]++;
            if (!(base[0x1848] & 4) && base[0x1836] &&
                base[0x183f] == base[0x1836]) btsnd_hcic_inq_cancel();
            entry[0x18] = 0;
            if (cb) cb(entry + 8);
            if (*(void (**)(void *, UINT8))(base + 0x16bc))
                (*(void (**)(void *, UINT8))(base + 0x16bc))(entry + 8, 1);
        }
    }
}

void btm_process_inq_complete(UINT8 status, UINT8 unused) {
    register u32 zero;
    register u8 *cleanup_base;
    u8 *base;
    void (*callback)(void *);
    u8 result;
    void *buffer;
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
            zero = 0;
            buffer = *(void **)(cleanup_base + 0x16DC);
            *(u32 *)(base + 0x16B4) = zero;
            base[0x1848] = (u8)zero;
            base[0x1847] = (u8)zero;
            *(void (**)(void *))(base + 0x16B0) = NULL;
            if (buffer != NULL) {
                GKI_freebuf(buffer);
                *(void **)(cleanup_base + 0x16DC) = (void *)zero;
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

    /* Start a remote-name request if idle, or attach to an in-progress inquiry request for the same device. */
    if (!fn_80079514()) return 6;
    active = base[0x16AE];
    if (active & origin) goto return2;
    if (origin == 1) {
        if (active != 0) {
            if (memcmp(remote_bda, base + 0x16A8, 6) == 0) {
                start = 0;
            } else {
                return 2;
            }
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
    if (result) {
        base[0x16AE] |= origin;
    } else {
        status = 3;
    }
    goto done;
return2:
    status = 2;
done:
    return status;
}

void btm_process_remote_name(u8 *arg0, u8 *arg1, u16 arg2, u8 arg3) {
    /* Completes a remote device name request: copies the reported name (or sets error status)
       into a result record, clears the pending request state/timer, and invokes the saved
       completion callback when one is registered. */
    tBTM_REMOTE_DEV_NAME rem_name;
    u8 *base = lbl_803C0F78;
    tBTM_CMPL_CB *callback;
    u8 saved;
    u8 *p_n1;
    u16 temp_evt_len;

    callback = *(tBTM_CMPL_CB **)(base + 0x167C);
    saved = base[0x16AE];
    fn_80070F90(base + 0x1680);
    base[0x16AE] = 0;

    if (arg3 == 0) {
        p_n1 = (u8 *)rem_name.remote_bd_name;
        rem_name.length = arg2 < 0xF8 ? arg2 : 0xF8;
        rem_name.status = 0;
        temp_evt_len = rem_name.length;
        while (temp_evt_len > 0) {
            *p_n1++ = *arg1++;
            temp_evt_len--;
        }
    } else {
        rem_name.status = 9;
        rem_name.length = 0;
        rem_name.remote_bd_name[0] = 0;
    }

    memset(base + 0x16A8, 0, 6);
    if (saved & 1) {
        *(void **)(base + 0x167C) = 0;
        if (callback)
            callback(&rem_name);
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

/* Registers or deregisters a BTM power-management client in the PM record table. */
tBTM_STATUS BTM_PmRegister(UINT8 mask, UINT8 *p_pm_id, tBTM_PM_STATUS_CBACK *p_cb)
{
    int slotIndex;
    u8 *pmEntry;

    if (mask & BTM_PM_DEREG) {
        if (*p_pm_id >= BTM_MAX_PM_RECORDS)
            return BTM_ILLEGAL_VALUE;
        *(lbl_803C0F78 + *p_pm_id * 8 + 0x558) = BTM_PM_REC_NOT_USED;
        return BTM_SUCCESS;
    }

    for (slotIndex = 0, pmEntry = lbl_803C0F78; slotIndex < BTM_MAX_PM_RECORDS; pmEntry += 8, slotIndex++) {
        if (pmEntry[0x558] == BTM_PM_REC_NOT_USED) {
            if (mask & BTM_PM_REG_NOTIF) {
                if (p_cb == NULL)
                    return BTM_ILLEGAL_VALUE;
                *(tBTM_PM_STATUS_CBACK **)(lbl_803C0F78 + slotIndex * 8 + 0x554) = p_cb;
            }
            *(u8 *)(lbl_803C0F78 + slotIndex * 8 + 0x558) = mask;
            *p_pm_id = slotIndex;
            return BTM_SUCCESS;
        }
    }
    return BTM_NO_RESOURCES;
}

extern u8 lbl_80560D38;
extern u8 lbl_80560D3C;
extern tBTM_STATUS btm_pm_snd_md_req(UINT8, int, tBTM_PM_PWR_MD *);
tBTM_STATUS BTM_SetPowerMode(UINT8 pm_id, BD_ADDR remote_bda, tBTM_PM_PWR_MD *p_mode)
{
    register tBTM_PM_MODE mode;
    int ind;
    u32 acl_ind;
    UINT8 acl_index;
    UINT8 feature_offset, feature_mask;
    UINT8 *p_cb;
    UINT8 *p_acl;
    UINT8 *p_features;
    if (pm_id >= 2)
        pm_id = BTM_PM_SET_ONLY_ID;
    if (p_mode == NULL)
        return BTM_ILLEGAL_VALUE;
    mode = p_mode->mode & ~BTM_PM_MD_FORCE;
    acl_ind = 0;
    p_acl = lbl_803C0F78 + 0x34;
loop:
    if (p_acl[0x119] == 0)
        goto next;
    if (memcmp(p_acl + 8, remote_bda, 6) != 0)
        goto next;
    goto found;
next:
    acl_ind++;
    p_acl += 0x11C;
    if (acl_ind < 4)
        goto loop;
found:
    acl_index = (UINT8)acl_ind;
    if ((s32)acl_index == 4)
        return BTM_UNKNOWN_ADDR;
    p_cb = lbl_803C0F78 + acl_index * 0x22 + 0x4CC;
    if (mode != BTM_PM_MD_ACTIVE) {
        ind = mode - BTM_PM_MD_HOLD;
        p_features = (UINT8 *)fn_8007A3A4();
        feature_offset = ((UINT8 *)&lbl_80560D38)[ind];
        feature_mask = ((UINT8 *)&lbl_80560D3C)[ind];
        if (!(p_features[feature_offset] & feature_mask))
            return BTM_MODE_UNSUPPORTED;
    }
    if (mode == p_cb[0x20]) {
        if (mode == BTM_PM_MD_ACTIVE ||
            (p_mode->max >= *(UINT16 *)(p_cb + 0x1E) &&
             p_mode->min <= *(UINT16 *)(p_cb + 0x1E)))
            return BTM_SUCCESS;
    }
    if (pm_id != BTM_PM_SET_ONLY_ID &&
        ((lbl_803C0F78 + ((pm_id * 8) & 0x7F8))[0x558] & BTM_PM_REG_SET)) {
        UINT16 max = p_mode->max;
        u32 offset = pm_id * 0xA;
        UINT16 min = p_mode->min;
        UINT16 *p_req = (UINT16 *)(p_cb + offset);
        UINT16 attempt;
        UINT16 timeout;
        p_req[0] = max;
        p_req[1] = min;
        attempt = p_mode->attempt;
        timeout = p_mode->timeout;
        p_req[2] = attempt;
        p_req[3] = timeout;
        p_req[4] = *(UINT16 *)&p_mode->mode;
        p_cb[0x21] = TRUE;
    }
    if (p_cb[0x20] == 1 || p_cb[0x20] == 4 ||
        lbl_803C0F78[0x564] != 4)
        return 0xD;
    return btm_pm_snd_md_req(pm_id, acl_index, p_mode);
}

/* Read the current power mode for the ACL link to remote_bda into *p_mode. */
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
/* The stack's own names for the power mode comparison (stack/btm/btm_pm.c). */
#define btm_pm_md_comp_matrix   lbl_802EEBE8 /* who wins each pair of set modes */
#define BTM_PM_NUM_SET_MODES    3             /* only hold, sniff & park */
#define BTM_PM_GET_MD1          1             /* the first mode wins */
#define BTM_PM_GET_MD2          2             /* the second mode wins */
#define BTM_PM_GET_COMP         3             /* the same mode twice: merge the parameters */

/*
 * btm_pm_compare_modes - work out the power mode a link gets when the module
 * wanting p_md1 and the one wanting p_md2 have to agree on one, leave it in
 * p_res and return the request it came from (NULL when there is no mode both
 * can live with).  Active is never a compromise.  A mode a module forced
 * (BTM_PM_MD_FORCE) wins outright and loses its force bit; otherwise
 * btm_pm_md_comp_matrix picks the winner of hold, sniff and park (sniff over
 * park over hold), and two requests for the same mode are merged into the
 * overlap of their intervals - the shorter max and the longer min, which is no
 * mode at all when the intervals do not overlap - plus, for sniff, the longer
 * attempt count and timeout.  Unlike the stack's btm_pm.c, a NULL p_md1 here
 * copies p_md2 across as it is, force bit and all.
 */
tBTM_PM_PWR_MD *btm_pm_compare_modes(tBTM_PM_PWR_MD *p_md1, tBTM_PM_PWR_MD *p_md2, tBTM_PM_PWR_MD *p_res) {
    UINT8 res;
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
    res = (p_md1->mode - 1) * BTM_PM_NUM_SET_MODES + (p_md2->mode - 1);
    res = btm_pm_md_comp_matrix[res];
    switch (res) {
    case BTM_PM_GET_MD1:
        *p_res = *p_md1;
        return p_md1;
    case BTM_PM_GET_MD2:
        *p_res = *p_md2;
        return p_md2;
    case BTM_PM_GET_COMP:
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

tBTM_PM_MODE btm_pm_get_set_mode(UINT8 pm_id, tBTM_PM_MCB *p_cb, tBTM_PM_PWR_MD *p_mode, tBTM_PM_PWR_MD *p_res) {
    int xx;
    register tBTM_PM_REG_DB_MATCH_VIEW *reg_db;
    tBTM_PM_PWR_MD *p_md = NULL;

    /* BTM power manager: compute the power mode to set for a connection (pm_id,
       link control block p_cb) given optional requested mode p_mode, writing the
       chosen mode into *p_res and returning its mode. A forced request
       (BTM_PM_MD_FORCE) is applied directly (force bit cleared). Otherwise scan
       registered modules in btm_cb.pm_reg_db (lbl_803C0F78, mask BTM_PM_REG_SET)
       up to BTM_MAX_PM_RECORDS: any ACTIVE request forces ACTIVE, else merge each
       request into p_md via btm_pm_compare_modes (NULL -> ACTIVE). If no merged
       mode, use p_mode or ACTIVE; for BTM_PM_SET_ONLY_ID also reconcile p_mode vs
       merged p_md. reg_db view matches target's global base/offset. */
    if (p_mode != NULL && p_mode->mode & BTM_PM_MD_FORCE) {
        *p_res = *p_mode;
        p_res->mode &= ~BTM_PM_MD_FORCE;
        return p_res->mode;
    }

    reg_db = (tBTM_PM_REG_DB_MATCH_VIEW *)lbl_803C0F78;
    for (xx = 0; xx < BTM_MAX_PM_RECORDS; xx++) {
        if (reg_db->pm_reg_db[xx].mask & BTM_PM_REG_SET) {
            if (p_cb->req_mode[xx].mode == BTM_PM_MD_ACTIVE) {
                return BTM_PM_MD_ACTIVE;
            } else {
                if (btm_pm_compare_modes(p_md, &p_cb->req_mode[xx], p_res) == NULL) {
                    return BTM_PM_MD_ACTIVE;
                }
                p_md = p_res;
            }
        }
    }

    if (p_md == NULL) {
        if (p_mode != NULL) {
            *p_res = *p_mode;
        } else {
            return BTM_PM_MD_ACTIVE;
        }
    } else {
        if (pm_id == BTM_PM_SET_ONLY_ID &&
            btm_pm_compare_modes(p_mode, p_md, p_res) == NULL) {
            return BTM_PM_MD_ACTIVE;
        }
    }

    return p_res->mode;
}

/* btm_cb's power-management members and the ACL handle of a link, named from
   the code that reads them.  btm_int.h's tBTM_CB cannot be used here: its
   tACL_CONN is 0x120 bytes where this stack's is 0x11C, and it counts
   MAX_L2CAP_LINKS links where this build has four, so the byte offsets stay. */
#define btm_cb_pm_pend_link  (lbl_803C0F78[0x564]) /* acl_db entry with a mode change outstanding, 4 (this build's MAX_L2CAP_LINKS) when none */
#define btm_cb_pm_pend_id    (lbl_803C0F78[0x565]) /* the module waiting for its command status, BTM_PM_SET_ONLY_ID when none */
#define btm_cb_acl_handle(i) (*(u16 *)(lbl_803C0F78 + (i) * 0x11c + 0x34)) /* acl_db[i].hci_handle */

/* The two park-mode command senders.  Like the other senders in this unit they
   build the packet in the buffer they are handed (NULL = allocate one) and the
   game's symbols kept the names of the sniff/hold senders next to them: the
   first writes HCI opcode 0x0805 (Link Policy / Park_Mode, parameters handle,
   interval, interval) and the second 0x0806 (Exit_Park_Mode, parameter handle). */
#define btsnd_hcic_park_mode      btsnd_hcic_hold_mode_80084A34
#define btsnd_hcic_exit_park_mode btsnd_hcic_exit_sniff_mode_80084AE8

/* Send the controller the mode change the power manager settled on for one ACL
 * link.  btm_pm_get_set_mode() merges what every registered module asked for;
 * the mode that comes out picks the HCI command - hold, sniff or park, or
 * leaving sniff/park for active.  btm_cb remembers the link and the module
 * waiting for the command status, and a request that needs no command at all
 * is reported as stored instead of started. */
tBTM_STATUS btm_pm_snd_md_req(UINT8 pm_id, int link_ind, tBTM_PM_PWR_MD *p_mode) {
    extern BOOLEAN btsnd_hcic_sniff_mode(BT_HDR *, s16, s16, s16, s16, u16);
    extern s32 btsnd_hcic_exit_sniff_mode(void *, u16);
    extern s32 btsnd_hcic_exit_park_mode(u8 *, u16);
    extern s32 btsnd_hcic_park_mode(u8 *, u16, u16, u16);
    tBTM_PM_PWR_MD result;
    tBTM_PM_MCB_VIEW *p_cb = (tBTM_PM_MCB_VIEW *)(lbl_803C0F78 + 0x4cc + link_ind * 0x22);
    u8 mode;
    u8 changed = 0;
    u8 *buf;

    mode = btm_pm_get_set_mode(pm_id, (tBTM_PM_MCB *)p_cb, p_mode, &result);
    result.mode = mode;
    if (p_cb->state == mode) {
        /* already in that mode, and the interval asked for covers the current one */
        if (mode == BTM_PM_MD_ACTIVE || (result.max >= p_cb->interval && result.min <= p_cb->interval))
            return BTM_CMD_STORED;
        changed = 1;
    }
    p_cb->chg_ind = changed;
    /* one low-power mode into another is a change the controller has to make */
    if (mode != BTM_PM_MD_ACTIVE && p_cb->state != BTM_PM_MD_ACTIVE) p_cb->chg_ind = 1;

    buf = GKI_getpoolbuf(BTM_CMD_POOL_ID);
    if (buf == 0) return BTM_NO_RESOURCES;
    /* a change between two modes goes through active first */
    if (p_cb->chg_ind == 1) result.mode = BTM_PM_MD_ACTIVE;
    btm_cb_pm_pend_link = link_ind;
    btm_cb_pm_pend_id = pm_id;
    switch (result.mode) {
    case BTM_PM_MD_ACTIVE:
        switch (p_cb->state) {
        case BTM_PM_MD_SNIFF:
            btsnd_hcic_exit_sniff_mode(buf, btm_cb_acl_handle(link_ind));
            break;
        case BTM_PM_MD_PARK:
            btsnd_hcic_exit_park_mode(buf, btm_cb_acl_handle(link_ind));
            break;
        default: btm_cb_pm_pend_link = 4; break;   /* no command went out */
        }
        break;
    case BTM_PM_MD_HOLD:
        /* btsnd_hcic_hold_mode() allocates its own buffer; this caller hands it one anyway */
        ((BOOLEAN (*)(void *, u16, u16, u16))btsnd_hcic_hold_mode)(buf, btm_cb_acl_handle(link_ind), result.max, result.min);
        break;
    case BTM_PM_MD_SNIFF:
        ((BOOLEAN (*)(BT_HDR *, u16, u16, u16, u16, u16))btsnd_hcic_sniff_mode)((BT_HDR *)buf, btm_cb_acl_handle(link_ind), result.max, result.min, result.attempt, result.timeout);
        break;
    case BTM_PM_MD_PARK:
        btsnd_hcic_park_mode(buf, btm_cb_acl_handle(link_ind), result.max, result.min);
        break;
    default: btm_cb_pm_pend_link = 4; break;       /* no command went out */
    }
    if (btm_cb_pm_pend_link == 4) GKI_freebuf(buf);
    return BTM_CMD_STARTED;
}

void btm_pm_proc_cmd_status(UINT8 status) {
    /* Handle HCI command status for BTM power management: update the current PM
     * record state on success/failure, optionally notify the registered callback,
     * and mark PM state as idle (4). Uses lbl_803C0F78 (btm_cb) offsets directly. */
    u8 result;
    u8 *btmCb = lbl_803C0F78;
    u8 pmState = btmCb[0x564];
    u8 *pmRecord;
    if (pmState >= 4) {
        return;
    }
    pmRecord = btmCb + pmState * 0x22;
    if (status == 0) {
        pmRecord[0x4EC] = 4;
        result = 4;
    } else {
        result = 5;
    }
    if (lbl_803C0F78[0x565] != 0x80) {
        u8 *pmEntry = lbl_803C0F78 + (lbl_803C0F78[0x565] << 3);
        if (pmEntry[0x558] & 2) {
            void *context = lbl_803C0F78 +
                *(volatile u8 *)(lbl_803C0F78 + 0x564) * 0x11C + 0x3C;
            void (*callback)(void *, s32, s32, UINT8) =
                *(void (**)(void *, s32, s32, UINT8))(pmEntry + 0x554);
            callback(context, result, 0, status);
        }
    }
    lbl_803C0F78[0x564] = 4;
}

void btm_pm_proc_mode_change(u8 status, u16 handle, u8 mode, u16 interval) {
    extern char lbl_80316530[];
    extern tBTM_STATUS btm_pm_snd_md_req(UINT8, int, tBTM_PM_PWR_MD *);
    u8 *acl, *pm, *reg, *dev, *addr, *link;
    int offset, index, i;
    index = (u8)btm_handle_to_acl_index(handle);
    if (index >= 4) return;
    offset = index * 0x11c;
    acl = lbl_803C0F78 + offset;
    if (mode == 0 && *(u16 *)(acl + 0x38) != 0 && (u8)btm_num_sco_links_active() == 0) {
        *(u16 *)(acl + 0x38) = 0;
        if (lbl_803C0F78[0x27c0] >= 5)
            fn_8007096C(0xD0004, lbl_80316530, handle, *(u16 *)(acl + 0x36));
        btsnd_hcic_change_conn_type(*(u16 *)(acl + 0x34), *(u16 *)(acl + 0x36));
    }
    pm = lbl_803C0F78 + index * 0x22;
    pm[0x4ec] = mode;
    *(u16 *)(pm + 0x4ea) = interval;
    {
        tBTM_PM_PWR_MD *req = (tBTM_PM_PWR_MD *)(pm + 0x4cc);
        int n;
        for (n = 0; n <= 1; ++n, ++req) {
            if (mode == 0 && req->mode == 1) req->mode = 0;
        }
    }
    if (pm[0x4ed] == 1) btm_pm_snd_md_req(0x80, index, 0);
    reg = lbl_803C0F78;
    for (i = 0; i < 2; i++, reg += 8) {
        if (reg[0x558] & 2)
            (*(void (**)(u8 *, u8, u16, u8))(reg + 0x554))(acl + 0x3c, mode, interval, status);
    }
    link = (u8 *)((u32)lbl_803C0F78 + offset);
    if (link[0x14f] == 1) {
        addr = link + 0x3c;
        dev = (u8 *)btm_find_dev(addr);
        if (dev != 0 && (dev[0x76] & 4)) {
            if (btsnd_hcic_set_conn_encrypt(handle, 0)) {
                link[0x14f] = 2;
                return;
            }
        } else {
            if (btsnd_hcic_switch_role(addr, (lbl_803C0F78 + offset)[0x14e] == 0)) {
                link[0x14f] = 0;
                return;
            }
        }
        link[0x14f] = 0;
        if (*(void (**)(void *))(lbl_803C0F78 + 0x62c) != 0) {
            lbl_803C0F78[0x624] = status;
            (*(void (**)(void *))(lbl_803C0F78 + 0x62c))(lbl_803C0F78 + 0x624);
            *(void (**)(void *))(lbl_803C0F78 + 0x62c) = 0;
        }
    }
    (void)acl;
}

void fn_8007D4C4(void) {
    extern u32 lbl_802EEBF8[];
    extern u8 lbl_803C0F78[];
    u32 *src = lbl_802EEBF8;
    *(u16 *)(lbl_803C0F78 + 0x18F6) = 0xFFFF;
    *(u32 *)(lbl_803C0F78 + 0x18F8) = *src++;
    *(u32 *)(lbl_803C0F78 + 0x18FC) = *src++;
    *(u32 *)(lbl_803C0F78 + 0x1900) = *src++;
    *(u32 *)(lbl_803C0F78 + 0x1904) = *src++;
    lbl_803C0F78[0x1909] = 2;
}

/* One entry of btm_cb.sco_cb.sco_db[] - the game's tSCO_CONN, 0x34 bytes.  The
 * header's tSCO_CONN sits at another offset in this build, so this describes
 * the record where it really is and names only what the SCO code reads. */
typedef struct {
    UINT8  _00[8];            /* 0x00: the connect/disconnect callbacks */
    UINT16 state;             /* 0x08: SCO_ST_* */
    UINT8  _0A[0x14 - 0x0A];  /* 0x0A: the HCI handle and the flags after it */
    tBTM_ESCO_PARAMS setup;   /* 0x14: esco.setup - parameters to negotiate with */
    UINT8  _24[4];            /* 0x24: esco.data - the SCO handle of the link */
    BD_ADDR bd_addr;          /* 0x28: esco.data.bd_addr - the peer of the link */
    UINT8  link_type;         /* 0x2E: esco.data.link_type, BTM_LINK_TYPE_* */
    UINT8  _2F[5];            /* 0x2F: the rest of esco.data and its HCI status */
} ScoConnView;

#define SCO_ST_UNUSED       0 /* the record is free */
#define SCO_ST_LISTENING    1 /* waiting for an (e)SCO connection */
#define SCO_ST_W4_CONN_RSP  2 /* an (e)SCO request is waiting for the application */
#define SCO_ST_CONNECTING   3
#define SCO_ST_PEND_UNPARK  6 /* an (e)SCO connect waits for the parked link to come back */

#define BTM_SCO_DB          0x1854 /* btm_cb.sco_cb.sco_db[] */
#define BTM_SCO_DB_LINKS    3      /* BTM_MAX_SCO_LINKS as this build counts it */

#define btm_cb_esco_supported (lbl_803C0F78[0x1908]) /* btm_cb.sco_cb.esco_supported: 1.2 cntlr with eSCO links */
#define btm_cb_desired_sco_mode (lbl_803C0F78[0x1909]) /* btm_cb.sco_cb.desired_sco_mode: 0 unknown, 1 SCO, 2 eSCO (BTM_DEFAULT_SCO_MODE) */
#define btm_cb_def_pkt_types  (*(UINT16 *)(lbl_803C0F78 + 0x1904)) /* btm_cb.sco_cb.def_esco_parms.packet_types */
#define btm_cb_sco_pkt_types  (*(UINT16 *)(lbl_803C0F78 + 0x656))  /* btm_cb.btm_sco_pkt_types_supported */
#define btm_cb_hci_version    (lbl_803C0F78[0x636]) /* btm_cb.devcb.local_version.hci_version */

int btsnd_hcic_accept_conn(void *p_buf, u8 *bda, u8 link_type);
void btsnd_hcic_accept_esco_conn(BT_HDR *p_buf, BD_ADDR bda, UINT32 tx_bw, UINT32 rx_bw,
                                 UINT16 max_latency, UINT16 voice_contfmt,
                                 UINT8 retrans_effort, UINT16 packet_types);
void btm_chg_all_acl_pkt_types(UINT8);
/* Answer an incoming (e)SCO connection request (the BTM_ESCO_CONN_REQ_EVT the
 * application replies to through BTM_EscoConnResponse): with hci_status other
 * than HCI_SUCCESS the record goes back to listening (or is freed) and HCI is
 * told to reject, otherwise the link is taken up - as an eSCO link with the
 * negotiated parameters, or as a plain SCO one when the controller has no eSCO
 * or the request arrived as SCO.  p_parms is NULL to keep the parameters last
 * set by BTM_SetEscoMode, of which only the packet types are taken here. */
static void btm_esco_conn_rsp(UINT16 sco_inx, UINT8 hci_status, BD_ADDR bda, tBTM_ESCO_PARAMS *p_parms) {
    ScoConnView *p_sco;
    void *p_buf;
    UINT16 pkt_types;
    p_sco = 0;
    p_buf = GKI_getpoolbuf(2); /* the HCI command to answer with */
    if (p_buf == 0) {
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_ERROR) {
            fn_8007093C(0xD0000, (void *)lbl_80316570); /* "btm_esco_conn_rsp -> No Resources" */
        }
        return;
    }
    if (sco_inx < BTM_SCO_DB_LINKS) {
        u32 tmp = (u32)lbl_803C0F78 + (u32)(sco_inx * 0x34);
        p_sco = (ScoConnView *)(tmp + BTM_SCO_DB);
    }
    if (hci_status != HCI_SUCCESS) {
        if (p_sco != 0) {
            /* SCO_ST_LISTENING when the request was only awaited, else SCO_ST_UNUSED */
            p_sco->state = (p_sco->state - SCO_ST_W4_CONN_RSP) == 0;
        }
        if (btm_cb_esco_supported == 0) {
            btsnd_hcic_reject_conn(p_buf, bda, hci_status);
        } else {
            btsnd_hcic_reject_esco_conn(p_buf, bda, hci_status);
        }
        return;
    }
    btm_chg_all_acl_pkt_types(TRUE);
    p_sco->state = SCO_ST_CONNECTING;
    if (btm_cb_esco_supported != 0 && p_sco->link_type == BTM_LINK_TYPE_ESCO) {
        if (p_parms != 0) {
            p_sco->setup = *p_parms;
        }
        p_sco->setup.packet_types = btm_cb_def_pkt_types;
        pkt_types = p_sco->setup.packet_types & btm_cb_sco_pkt_types;
        pkt_types &= BTM_SCO_SUPPORTED_PKTS_MASK;
        /* ask for at least one eSCO packet type, or the peer may get confused */
        if ((pkt_types & BTM_ESCO_LINK_ONLY_MASK) == 0) {
            pkt_types |= BTM_SCO_PKT_TYPES_MASK_EV3;
        }
        if (btm_cb_hci_version >= HCI_PROTO_VERSION_2_0) {
            pkt_types |= (p_sco->setup.packet_types | btm_cb_sco_pkt_types) & BTM_SCO_EXCEPTION_PKTS_MASK;
        }
        btsnd_hcic_accept_esco_conn(
            p_buf, bda, p_sco->setup.tx_bw, p_sco->setup.rx_bw,
            p_sco->setup.max_latency, p_sco->setup.voice_contfmt,
            p_sco->setup.retrans_effort, pkt_types);
        p_sco->setup.packet_types = pkt_types;
        return;
    }
    btsnd_hcic_accept_conn(p_buf, bda, 0); /* accept it as a SCO link */
}

extern char lbl_803165FC[];
extern char lbl_8031664C[];
extern void btm_chg_all_acl_pkt_types(BOOLEAN);
/* Called for every HCI mode change event (the parked link's return to active is
 * mode == HCI_MODE_ACTIVE): each (e)SCO record that was left waiting for that
 * unpark (SCO_ST_PEND_UNPARK) on this ACL link now gets the connect request it
 * was holding, as plain SCO or as eSCO, and moves on to SCO_ST_CONNECTING.
 * This is btm_send_connect_request() inlined for the unpark case. */
void btm_sco_chk_pend_unpark(UINT8 hci_status, UINT16 hci_handle, UINT8 mode) {
    UINT32 xx;
    ScoConnView *p;
    UINT16 acl_handle;
    UINT16 packet_types;
    UINT16 supported;
    UINT16 requested;
    UINT8 status;
    xx = 0;
    p = (ScoConnView *)(lbl_803C0F78 + BTM_SCO_DB);
    while (xx < BTM_SCO_DB_LINKS) {
        if (p->state != SCO_ST_PEND_UNPARK)
            goto next;
        if (mode != HCI_MODE_ACTIVE)
            goto next;
        if (hci_status != HCI_SUCCESS)
            goto next;
        acl_handle = BTM_GetHCIConnHandle(p->bd_addr);
        if (hci_handle != acl_handle)
            goto next;
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_API)
            fn_8007096C(TRACE_LAYER_BTM | TRACE_TYPE_API, lbl_8031664C, acl_handle, btm_cb_desired_sco_mode);
        btm_chg_all_acl_pkt_types(TRUE);
        if (btm_cb_esco_supported == 0) {
            /* 1.1 controller: the record's eSCO packet types become SCO ones */
            if (!btsnd_hcic_add_SCO_conn(acl_handle,
                    (p->setup.packet_types << 5) & 0xE0 /* BTM_ESCO_2_SCO() */)) {
                status = BTM_NO_RESOURCES;
                goto update_state;
            }
        } else {
            /* keep only the packet types both sides support, ... */
            supported = btm_cb_sco_pkt_types;
            requested = p->setup.packet_types;
            packet_types = (requested & supported) & BTM_SCO_SUPPORTED_PKTS_MASK;
            /* ... and pass on the 2.0 exception bits when the controller is 2.0 */
            if (btm_cb_hci_version >= HCI_PROTO_VERSION_2_0)
                packet_types |= (requested | supported) & BTM_SCO_EXCEPTION_PKTS_MASK;
            if (btm_cb_trace_level >= BTM_TRACE_LEVEL_API)
                fn_800709CC(TRACE_LAYER_BTM | TRACE_TYPE_API, lbl_803165FC,
                    p->setup.tx_bw, p->setup.rx_bw,
                    p->setup.max_latency, p->setup.voice_contfmt,
                    p->setup.retrans_effort, packet_types);
            if (!btsnd_hcic_setup_esco_conn(acl_handle,
                    p->setup.tx_bw, p->setup.rx_bw,
                    p->setup.max_latency, p->setup.voice_contfmt,
                    p->setup.retrans_effort, packet_types)) {
                status = BTM_NO_RESOURCES;
                goto update_state;
            }
            p->setup.packet_types = packet_types;
        }
        status = BTM_CMD_STARTED;
    update_state:
        if (status == BTM_CMD_STARTED)
            p->state = SCO_ST_CONNECTING;
    next:
        xx++;
        p++;
    }
}

void btm_sco_conn_req(BD_ADDR bda, DEV_CLASS dev_class, tBTM_SCO_TYPE link_type)
{
    /* Handle an incoming SCO/eSCO connection request: match/reuse an existing SCO entry, notify or auto-accept via callback, or reject if no one wants it. */
    tBTM_ESCO_CONN_REQ_EVT_DATA event_data;
    register UINT8 *p_bda = bda;
    register UINT8 *p_dev_class = dev_class;
    register UINT8 type = link_type;
    UINT8 *entry;
    UINT16 i;

    entry = lbl_803C0F78 + 0x1854;
    i = 0;
    for (; i < 3; i++, entry += 0x34) {
        UINT16 state = *(UINT16 *)(entry + 8);
        if (!((state == 1 && entry[0xD] != 0) || state == 3))
            continue;
        if (memcmp(entry + 0x28, p_bda, 6) != 0)
            continue;
        entry[0xD] = 1;
        entry[0x2E] = type;
        memcpy(entry + 0x28, p_bda, 6);
        if (*(UINT32 *)(entry + 0x10) == 0) {
            btm_esco_conn_rsp(i, 0, p_bda, NULL);
        } else {
            memcpy(event_data.bd_addr, p_bda, 6);
            memcpy(event_data.dev_class, p_dev_class, 3);
            event_data.link_type = type;
            *(UINT16 *)(entry + 8) = 2;
            event_data.sco_inx = i;
            ((tBTM_ESCO_CBACK *)*(UINT32 *)(entry + 0x10))(
                2, (tBTM_ESCO_EVT_DATA *)&event_data);
        }
        return;
    }
    if (*(UINT32 *)(lbl_803C0F78 + 0x1850) != 0) {
        entry = lbl_803C0F78 + 0x1854;
        i = 0;
        for (; i < 3; i++, entry += 0x34) {
            if (*(UINT16 *)(entry + 8) == 0) {
                entry[0xC] = 0;
                *(UINT16 *)(entry + 8) = 1;
                entry[0x2E] = type;
                memcpy(entry + 0x28, p_bda, 6);
                entry[0xD] = 1;
                break;
            }
        }
        if (i < 3) {
            ((void (*)(UINT16))*(UINT32 *)(lbl_803C0F78 + 0x1850))(i);
            return;
        }
    }
    if (lbl_803C0F78[0x27C0] >= 2)
        fn_8007093C(0xD0001, lbl_8031669C);
    btm_esco_conn_rsp(3, 0x0D, p_bda, NULL);
}

/* Handle HCI SCO/eSCO connection complete: update the matching SCO control block and invoke its callback. */
void btm_sco_connected(u8 status, u8 *addr, u16 handle, tBTM_ESCO_DATA *params) {
    u8 *scoCb = lbl_803C0F78 + 0x1854;
    u16 scoState;
    u8 needsParamChange = 0;
    u32 scoIndex = 0;
    u16 p1, p0;
    u16 p3, p2;

    *(u16 *)(lbl_803C0F78 + 0x18F6) = status;
    for (;;) {
        scoState = *(u16 *)(scoCb + 8);
        if ((u16)(scoState + 0xFFFF) <= 2 && scoCb[0xD] && (addr == 0 || memcmp(scoCb + 0x28, addr, 6) == 0)) {
            if (status != 0) {
                if (scoState == 3) {
                    if (status != 0x23) {
                        *(u16 *)(scoCb + 8) = 0;
                        ((void (*)(u16))*(u32 *)(scoCb + 4))(scoIndex);
                    }
                } else {
                    *(u16 *)(scoCb + 8) = 1;
                }
            } else {
                if (scoState == 1)
                    needsParamChange = 1;
                *(u16 *)(scoCb + 8) = 4;
                *(u16 *)(scoCb + 0xA) = handle;
                if (lbl_803C0F78[0x1908] == 0) {
                    tBTM_CHG_ESCO_PARAMS new_params;
                    scoCb[0x2E] = 0;
                    if (needsParamChange) {
                        new_params.packet_types = *(u16 *)(scoCb + 0x20);
                        new_params.max_latency = *(u16 *)(scoCb + 0x1C);
                        new_params.retrans_effort = scoCb[0x22];
                        BTM_ChangeEScoLinkParms(scoIndex, &new_params);
                    }
                } else if (params != 0) {
                    p0 = *(volatile u16 *)((u8 *)params + 0);
                    p1 = *(volatile u16 *)((u8 *)params + 2);
                    *(u16 *)(scoCb + 0x24) = p0;
                    *(u16 *)(scoCb + 0x26) = p1;
                    p2 = *(volatile u16 *)((u8 *)params + 4);
                    p3 = *(volatile u16 *)((u8 *)params + 6);
                    *(u16 *)(scoCb + 0x28) = p2;
                    *(u16 *)(scoCb + 0x2A) = p3;
                    p0 = *(volatile u16 *)((u8 *)params + 8);
                    *(u16 *)(scoCb + 0x2C) = p0;
                    p0 = *(volatile u16 *)((u8 *)params + 0xA);
                    *(u16 *)(scoCb + 0x2E) = p0;
                    p0 = *(volatile u16 *)((u8 *)params + 0xC);
                    *(u16 *)(scoCb + 0x30) = p0;
                }
                ((void (*)(u16))*(u32 *)scoCb)(scoIndex);
            }
            return;
        }
        scoIndex++;
        scoCb += 0x34;
        if (scoIndex >= 3)
            return;
    }
}

tBTM_STATUS BTM_RemoveSco(UINT16 sco_inx) {
    /* Remove a SCO connection by index, or clear a pending/unparked slot. */
    u8 *scoEntry = lbl_803C0F78 + sco_inx * 0x34;
    u16 savedState;
    if (sco_inx >= 3 || (savedState = *(u16 *)(scoEntry + 0x185C)) == 0) return 7;
    if (*(u16 *)(scoEntry + 0x185E) == 0xFFFF || savedState == 6) {
        *(u16 *)(scoEntry + 0x185E) = 0xFFFF;
        *(u16 *)(scoEntry + 0x185C) = 0;
        *(u32 *)(scoEntry + 0x1864) = 0;
        return 0;
    }
    *(u16 *)(scoEntry + 0x185C) = 5;
    if (!btsnd_hcic_disconnect(*(u16 *)(scoEntry + 0x185E), 0x13)) {
        *(u16 *)(scoEntry + 0x185C) = savedState;
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
    u32 count = 0;
    u8 *p;
    s32 i;
    s32 state;
    u8 *base = lbl_803C0F78;
    *(volatile u16 *)(base + 0x18F6) = packet_types;
    state = *(volatile u16 *)(base + 0x185C);
    if (state >= 2 && state < 7) count = 1;
    state = *(volatile u16 *)(base + 0x1890);
    if (state >= 2 && state < 7) count++;
    state = *(volatile u16 *)(base + 0x18C4);
    if (state >= 2 && state < 7) count++;
    if (!((u8)count > 1U)) btm_chg_all_acl_pkt_types(FALSE);
    p = lbl_803C0F78 + 0x1854;
    for (i = 0; i < 3; i++, p += 0x34) {
        state = *(u16 *)(p + 8);
        if (state && (u32)state != 1U && *(u16 *)(p + 0xA) == handle) {
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
/* Notify SCO connections that an ACL link was removed and clear their state. */
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

/* GKI tick conversion, as in revolution/BTE/include/gki_target.h (a header this
   file does not include): the stack runs at 100 ticks per second, so a tick is
   10 ms and a protocol timer period in ms converts by dividing by 10. */
#define TICKS_PER_SEC      100
#define GKI_MS_TO_TICKS(x) ((x) / (1000 / TICKS_PER_SEC))

void ptim_timer_update(tPTIM_CB *p_cb) {
    /* Advance this protocol timer queue by one period and dispatch any expired
       entries: call their callback, or post an event message via fn_80071450,
       stopping the GKI timer when the queue becomes empty. */
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

/* Start a protocol timer: (re)insert p_tle in the queue so it expires after
   `timeout` ticks, starting the periodic GKI tick timer if the queue was empty. */
void ptim_start_timer(tPTIM_CB *p_cb, TIMER_LIST_ENT *p_tle, UINT16 type, INT32 timeout) {
    /* if timer list is currently empty, start periodic GKI timer */
    if (p_cb->timer_queue.p_first == NULL) {
        GKI_start_timer(p_cb->timer_id, GKI_MS_TO_TICKS(p_cb->period), TRUE);
    }
    /* drop the entry from any position it already has in the queue */
    GKI_remove_from_timer_list(&p_cb->timer_queue, p_tle);
    /* event to report when it expires, and how long to wait */
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
/* Initializes BTA device manager state, sets device/security parameters and registers DM callbacks. */
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
    /* BTA device-manager disable: set L2CAP idle timeout for any BD addr, disable
     * BTA/sys and inquiry/connectability, tear down PM state. If no ACL links
     * remain, arm the disable timer (+0x74) for 1000 ms with callback fn_80073464
     * (+0x7C); otherwise mark disabling (+0x72) and arm a 5000 ms timer with
     * bta_dm_disable_timer_cback. */
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

/* Called when BTA DM disable timer expires; tears down ACL links or reports disable complete. */
void bta_dm_disable_timer_cback(void) {
    u8 device_index;
    if (lbl_8055DC80 >= 4) {
        fn_8007093C(0x503, lbl_80315048);
    }
    if (BTM_GetNumAclLinks() && lbl_803C0C14[0x101] == 0) {
        for (device_index = 0; device_index < lbl_803C0C14[0x4D]; device_index++) {
            btm_remove_acl((u8 *)lbl_803C0C14 + device_index * 0xB);
        }
    } else {
        lbl_803C0C14[0x72] = 0;
        ((void (**)(int, int, void *))(lbl_803C0C14 + 0x50))[0](1, 0, lbl_803C0C14);
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

/* tBTA_DM_MSG's auth_reply event (BTA device manager, bta_dm_int.h's
 * tBTA_DM_AUTH_REPLY): the peer asking to be authorized, the BTA service id it
 * asked for, and the answer the application gave. */
typedef struct {
    u16 event;          /* BT_HDR: BTA_DM_API_AUTH_REPLY_EVT */
    u16 len;            /* BT_HDR */
    u32 _reserved;      /* start of the union's payload */
    u8  bd_addr[6];     /* BD_ADDR of the peer */
    u8  service;        /* BTA service id, an index into the table below */
    u8  response;       /* one of BTA_DM_AUTH_* / BTA_DM_NOT_AUTH */
} tBTA_DM_AUTH_REPLY;

/* The application's answer to an authorization request. */
#define BTA_DM_AUTH_PERM        0   /* allow, and remember the service from now on */
#define BTA_DM_AUTH_TEMP        1   /* allow for this connection only */
#define BTA_DM_NOT_AUTH         2   /* refuse */

/* This BTE revision keeps BTM_SEC_MAX_SERVICES authorization bits per device
 * in BTM's device record (2 words here), and BTA knows this many service ids;
 * the table maps a BTA service id onto the BTM_SEC_SERVICE_* bit it grants. */
#define BTM_TRUSTED_MASK_WORDS  2
#define BTA_DM_LAST_SERVICE_ID  0x17

#define bta_service_id_to_btm_srv_id_lkup_tbl   lbl_802EE9C0
#define BTM_ReadTrustedMask                     fn_8008128C  /* -> device record + 0x10 */

/* Sends the application's answer to a device authorization request back to BTM:
 * the peer's current trusted-service mask is copied, a permanent grant sets the
 * bit of the requested service in it, and BTM_DeviceAuthorized() records the
 * result (BTM_NOT_AUTHORIZED when the request was refused). */
void bta_dm_auth_reply(tBTA_DM_AUTH_REPLY *p_data) {
    u32 trusted_mask[BTM_TRUSTED_MASK_WORDS];
    u32 service_id;
    u32 word_index;
    u32 *current_trusted_mask;
    current_trusted_mask = (u32 *)BTM_ReadTrustedMask(p_data->bd_addr);
    if (current_trusted_mask != 0) {
        memcpy(trusted_mask, current_trusted_mask, sizeof(trusted_mask));
    } else {
        memset(trusted_mask, 0, sizeof(trusted_mask));
    }
    if (p_data->response != BTA_DM_NOT_AUTH) {
        if (p_data->response == BTA_DM_AUTH_PERM) {
            u8 service_index = p_data->service;
            if (service_index <= BTA_DM_LAST_SERVICE_ID) {
                service_id = bta_service_id_to_btm_srv_id_lkup_tbl[service_index];
                word_index = (service_id >> 3) & 0x3FC;
                *(u32 *)((u8 *)trusted_mask + word_index) |= 1 << (service_id - (service_id & 0x1FE0));
            }
        }
        BTM_DeviceAuthorized(p_data->bd_addr, BTM_SUCCESS, trusted_mask);
    } else {
        BTM_DeviceAuthorized(p_data->bd_addr, BTM_NOT_AUTHORIZED, trusted_mask);
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

/* Starts BTA device discovery: initializes the search state from the request, registers the remote-name notify callback, copies the peer address, then either starts service discovery or requests the remote name and posts a failure message if needed. */
void bta_dm_discover(void *data) {
    u8 *search = lbl_803C0B98;
    u8 *input = (u8 *)data;
    u16 timeout;
    u32 value;
    void *msg_buf;
    tBTM_RMT_NAME_CALLBACK *remote_name_cb;

    value = *(u32 *)(input + 0x14);
    *(u32 *)lbl_803C0B98 = value;
    remote_name_cb = fn_80072AE4;
    value = *(u32 *)(input + 0x10);
    *(u32 *)(search + 8) = value;
    *(u32 *)(search + 0xC) = value;
    search[0x70] = 0;
    *(u32 *)(search + 0x10) = 0;
    search[0x20] = 0;
    BTM_SecAddRmtNameNotifyCallback(remote_name_cb);
    fn_80070FA4(search + 0x1A, input + 8);

    if (*(u32 *)(search + 8) != 0) {
        bta_dm_find_services(search + 0x1A);
        return;
    }

    timeout = *(u16 *)(lbl_803C0F78 + 0x64C);
    if (timeout < 0x7530)
        fn_8007146C((s32)(search + 0x58), 0x205, timeout + 0x64);

    if (BTM_ReadRemoteDeviceName(lbl_803C0B98 + 0x1A, (tBTM_CMPL_CB *)bta_dm_disc_remname_cback) != 1) {
        fn_8007148C((s32)(lbl_803C0B98 + 0x58));
        msg_buf = GKI_getbuf(0x110);
        if (msg_buf != 0) {
            fn_80070FA4((u8 *)msg_buf + 8, lbl_803C0B98 + 0x1A);
            *((u8 *)msg_buf + 0xE) = 0;
            *(u16 *)msg_buf = 0x204;
            fn_80071450(msg_buf);
        }
    }
}

/* BTA device-manager search: SDK names for this (older) BTE revision's DM
 * search control block and the BTA system helpers around it.  bta_dm_int.h and
 * bd.h declare these names for the newer stack the reference sources use, so
 * alias them to the labels this unit was given.
 *
 * bta_dm_search_cb is the SDK's tBTA_DM_SEARCH_CB; the field offsets below are
 * the ones this revision uses.
 */
#define bta_dm_search_cb                        lbl_803C0B98
#define bdcpy                                   fn_80070FA4  /* copy a BD_ADDR */
#define bta_sys_sendmsg                         fn_80071450  /* -> BTA task */
#define bta_sys_start_timer                     fn_8007146C
#define bta_sys_stop_timer                      fn_8007148C
#define bta_dm_service_search_remname_cback     fn_80072AE4

/* bta_dm_search_cb fields */
#define DM_SCB_P_SEARCH_CBACK                   ((void (*)(int, void *))*(u32 *)bta_dm_search_cb)
#define DM_SCB_P_INQ_INFO                       (*(void **)(bta_dm_search_cb + 4))
#define DM_SCB_SERVICES                         (*(u32 *)(bta_dm_search_cb + 8))
#define DM_SCB_SERVICES_TO_SEARCH               (*(u32 *)(bta_dm_search_cb + 0xC))
#define DM_SCB_SERVICES_FOUND                   (*(u32 *)(bta_dm_search_cb + 0x10))
#define DM_SCB_PEER_BDADDR                      (bta_dm_search_cb + 0x1A)
#define DM_SCB_PEER_NAME                        (bta_dm_search_cb + 0x20)
#define DM_SCB_SDP_DB_TIMER                     (bta_dm_search_cb + 0x58)
#define DM_SCB_SERVICE_INDEX                    (bta_dm_search_cb[0x70])
#define DM_SCB_WAIT_LINK                        (bta_dm_search_cb[0x78])
#define DM_SCB_LINK_TOUT_PENDING                (bta_dm_search_cb[0x79])

/* tBTM_INQ_INFO of this revision: the peer's address, and the flag saying
 * whether its remote name is already known. */
#define INQ_INFO_BD_ADDR(p)                     ((u8 *)(p) + 2)
#define INQ_INFO_KNOWS_REM_NAME(p)              (((u8 *)(p))[0x10])

/* tBTA_DM_MSG: BT_HDR followed by the event's payload. */
#define DM_MSG_EVENT(p)                         (*(u16 *)(p))
#define DM_MSG_BD_ADDR(p)                       ((u8 *)(p) + 8)
#define DM_MSG_BD_NAME(p)                       ((u8 *)(p) + 0xE)
#define BTA_DM_MSG_SIZE                         0x110

/* tBTA_DM_MSG events (bta_dm_int.h's DM search events). */
#ifndef BTA_DM_REMT_NAME_EVT
#define BTA_DM_REMT_NAME_EVT                    0x204
#define BTA_DM_SDP_RESULT_EVT                   0x205
#define BTA_DM_DISCOVERY_RESULT_EVT             0x207
#endif

/* tBTA_DM_SEARCH_EVT codes for the application's search callback. */
#ifndef BTA_DM_INQ_CMPL_EVT
#define BTA_DM_INQ_CMPL_EVT                     1
#define BTA_DM_DISC_RES_EVT                     2
#endif

/* tBTA_DM_SEARCH: what the search callback is handed with each event. */
typedef union {
    u8  num_resps;                              /* BTA_DM_INQ_CMPL_EVT */
    struct {
        u8  bd_addr[6];                         /* 0x00 */
        u8  bd_name[0xFA];                      /* 0x06 */
        u32 db_search_time;                     /* 0x100 */
        u8  _tail[4];                           /* 0x104 */
    } disc_res;                                 /* BTA_DM_DISC_RES_EVT */
} BtaDmSearch;

/* Process the inquiry-complete event from BTM: report the number of inquiry
 * results to the application's search callback, then start name and service
 * discovery on the devices the inquiry found.  With services to search for,
 * discovery starts on the first device (waiting for its ACL link when it is
 * down); otherwise the devices whose name is already known are reported one by
 * one and a remote name request is made for the first one that needs it.  When
 * there is nothing left to do the DM state machine gets a search-complete
 * message instead. */
void bta_dm_inq_cmpl(void *p_data) {
    extern void bta_dm_remname_cback(u8 *);
    BtaDmSearch result, info;
    tBTM_INQ_INFO *p_inq_info;
    u8 *peer_addr;
    void *p_msg;
    int search_complete = 1;
    p_inq_info = BTM_InqDbFirst();
    DM_SCB_P_INQ_INFO = p_inq_info;
    if (p_inq_info != 0) {
        search_complete = 0;
        if (DM_SCB_SERVICES != 0) {
            if (BTM_IsAclConnectionUp(INQ_INFO_BD_ADDR(p_inq_info))) DM_SCB_WAIT_LINK = 0;
            else DM_SCB_WAIT_LINK = 1;
            DM_SCB_LINK_TOUT_PENDING = 0;
            BTM_SecAddRmtNameNotifyCallback(bta_dm_service_search_remname_cback);
            DM_SCB_SERVICE_INDEX = 0;
            DM_SCB_SERVICES_FOUND = 0;
            DM_SCB_SERVICES_TO_SEARCH = DM_SCB_SERVICES;
            DM_SCB_PEER_NAME[0] = 0;
            bdcpy(DM_SCB_PEER_BDADDR, INQ_INFO_BD_ADDR(DM_SCB_P_INQ_INFO));
            bta_dm_find_services(INQ_INFO_BD_ADDR(DM_SCB_P_INQ_INFO));
        } else {
            search_complete = 1;
            goto check_entry;
            do {
                if (INQ_INFO_KNOWS_REM_NAME(p_inq_info) != 0) {
                    bdcpy(info.disc_res.bd_addr, INQ_INFO_BD_ADDR(p_inq_info));
                    info.disc_res.bd_name[0] = 0;
                    info.disc_res.db_search_time = 0;
                    DM_SCB_P_SEARCH_CBACK(BTA_DM_DISC_RES_EVT, &info);

                } else {
                    if (BTM_CB_PAGE_TIMEOUT < 0x7530)
                        bta_sys_start_timer((s32)DM_SCB_SDP_DB_TIMER, BTA_DM_SDP_RESULT_EVT, BTM_CB_PAGE_TIMEOUT + 0x64);
                    if (BTM_ReadRemoteDeviceName(INQ_INFO_BD_ADDR(DM_SCB_P_INQ_INFO), (tBTM_CMPL_CB *)bta_dm_remname_cback) != 1) {
                        bta_sys_stop_timer((s32)DM_SCB_SDP_DB_TIMER);
                        peer_addr = INQ_INFO_BD_ADDR(DM_SCB_P_INQ_INFO);
                        p_msg = GKI_getbuf(BTA_DM_MSG_SIZE);
                        if (p_msg != 0) {
                            bdcpy(DM_MSG_BD_ADDR(p_msg), peer_addr);
                            DM_MSG_BD_NAME(p_msg)[0] = 0;
                            DM_MSG_EVENT(p_msg) = BTA_DM_REMT_NAME_EVT;
                            bta_sys_sendmsg(p_msg);
                        }
                    }
                    search_complete = 0;
                    break;
                }
                DM_SCB_P_INQ_INFO = BTM_InqDbNext(*(tBTM_INQ_INFO **)(bta_dm_search_cb + 4));
            check_entry:
                p_inq_info = (tBTM_INQ_INFO *)*(u8 **)(bta_dm_search_cb + 4);
            } while (p_inq_info != 0);
        }
    }
    if (search_complete) {
        DM_SCB_SERVICES = 0;
        p_msg = GKI_getbuf(BTA_DM_MSG_SIZE);
        if (p_msg != 0) {
            DM_MSG_EVENT(p_msg) = BTA_DM_DISCOVERY_RESULT_EVT;
            bta_sys_sendmsg(p_msg);
        }
    }
    result.num_resps = *((u8 *)p_data + 8);
    DM_SCB_P_SEARCH_CBACK(BTA_DM_INQ_CMPL_EVT, &result);
}

void bta_dm_rmt_name(s32 arg0) {
    extern unsigned char lbl_803C0B98[];
    extern unsigned char lbl_803C0F78[];
    extern void bta_dm_remname_cback(u8 *);
    unsigned char info[0x104];
    int retry = 1;
    void *entry;
    void *buf;
    void (*callback)(s32, void *);
    for (;;) {
        entry = *(void **)(lbl_803C0B98 + 4);
        if (entry == 0 || *((u8 *)entry + 0x10) == 0)
            break;
        fn_80070FA4(info, (u8 *)entry + 2);
        info[6] = 0;
        *(u32 *)(info + 0x100) = 0;
        callback = *(void (**)(s32, void *))lbl_803C0B98;
        callback(2, info);
    }
    if (*(u16 *)(lbl_803C0F78 + 0x64C) < 0x7530)
        fn_8007146C((s32)(lbl_803C0B98 + 0x58), 0x205, *(u16 *)(lbl_803C0F78 + 0x64C) + 0x64);
    if (BTM_ReadRemoteDeviceName((u8 *)*(void **)(lbl_803C0B98 + 4) + 2, (tBTM_CMPL_CB *)bta_dm_remname_cback) != 1) {
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

void bta_dm_sdp_result(u8 *arg0) {
    u32 ok = 0;
    u8 *msg;
    u8 *state;
    tSDP_DISC_REC *rec = 0;
    u16 status = *(u16 *)(arg0 + 8);
    u16 service;
    u8 *name;

    if (status == 0 || status == 0xFFF0 || status == 0xFFF4) {
        service = lbl_802EE990[lbl_803C0B98[0x70] - 1];
        if (status == 0xFFF4 ||
            (rec = SDP_FindServiceInDb(*(tSDP_DISCOVERY_DB **)(lbl_803C0B98 + 0x14), service, 0)) != 0) {
            if (service == 0x1200) {
                if (rec != 0 && ((void *(*)(void **, u16))fn_80095C64)((void **)rec, 0x8001) != 0)
                    ok = 1;
            } else {
                ok = 1;
            }
            if (ok != 0) {
                *(u32 *)(lbl_803C0B98 + 0x10) |= 1 << (lbl_803C0B98[0x70] - 1);
            }
        }
        state = lbl_803C0B98;
        GKI_freebuf(*(void **)(state + 0x14));
        *(void **)(state + 0x14) = 0;
        if (*(u32 *)(state + 0xC) != 0) {
            bta_dm_find_services(state + 0x1A);
            return;
        }
        BTM_SecDeleteRmtNameNotifyCallback(fn_80072AE4);
        msg = GKI_getbuf(0x110);
        if (msg != 0) {
            *(u16 *)msg = 0x208;
            msg[0x10C] = 0;
            *(u32 *)(msg + 0x108) = *(u32 *)(state + 0x10);
            fn_80070FA4(msg + 8, state + 0x1A);
            name = state + 0x20;
            if ((s8)state[0x20] == 0) {
                u8 *read_name = (u8 *)BTM_SecReadDevName(state + 0x1A);
                if (read_name != 0)
                    name = read_name;
            }
            strncpy((char *)msg + 0xE, (char *)name, 0x20);
            fn_80071450(msg);
        }
    } else {
        if (status == 0xFFF1 || (u16)(status + 10) <= 1)
            lbl_803C0B98[0x78] = 0;
        state = lbl_803C0B98;
        GKI_freebuf(*(void **)(state + 0x14));
        *(void **)(state + 0x14) = 0;
        BTM_SecDeleteRmtNameNotifyCallback(fn_80072AE4);
        msg = GKI_getbuf(0x110);
        if (msg != 0) {
            *(u16 *)msg = 0x208;
            msg[0x10C] = 1;
            *(u32 *)(msg + 0x108) = *(u32 *)(state + 0x10);
            fn_80070FA4(msg + 8, state + 0x1A);
            name = state + 0x20;
            if ((s8)state[0x20] == 0) {
                u8 *read_name = (u8 *)BTM_SecReadDevName(state + 0x1A);
                if (read_name != 0)
                    name = read_name;
            }
            strncpy((char *)msg + 0xE, (char *)name, 0x20);
            fn_80071450(msg);
        }
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

extern u16 lbl_80560D10;
extern u16 lbl_80560D12;
extern u16 lbl_802EE990[];
extern void fn_800729C0(s16);
void bta_dm_find_services(u8 *bd_addr) {
    u16 attr_values[2];
    volatile tSDP_UUID service_uuid;
    u16 service;
    register u16 num_attr = 1;
    register u32 bit_base = 1;
    register u16 uuid_len = 2;
    register u32 zero = 0;
    register u8 last_index = 0x17;
    u8 *state = lbl_803C0B98;
    u16 *service_table = lbl_802EE990;
    u8 *name;
    void *msg;

    attr_values[0] = lbl_80560D10;
    attr_values[1] = lbl_80560D12;
    goto service_check;

service_loop:
    if ((*(volatile u32 *)(state + 0xC) &
         (bit_base << state[0x70])) != 0) {
        *(tSDP_DISCOVERY_DB **)(state + 0x14) =
            (tSDP_DISCOVERY_DB *)GKI_getbuf(0xFA);
        if (*(tSDP_DISCOVERY_DB **)(state + 0x14) != 0) {
            service = service_table[state[0x70]];
            *(volatile u32 *)(state + 0xC) &=
                ~(bit_base << state[0x70]);
            service_uuid.len = uuid_len;
            service_uuid.uu.uuid16 = service;
            if (service == 0x1200)
                num_attr = 2;
            SDP_InitDiscoveryDb(*(tSDP_DISCOVERY_DB **)(state + 0x14),
                                0xFA, 1, (tSDP_UUID *)&service_uuid,
                                num_attr, attr_values);
            if (SDP_ServiceSearchAttributeRequest(
                    bd_addr, *(tSDP_DISCOVERY_DB **)(state + 0x14),
                    (tSDP_DISC_CMPL_CB *)fn_800729C0) == FALSE) {
                GKI_freebuf(*(void **)(state + 0x14));
                *(void **)(state + 0x14) = (void *)zero;
                state[0x70] = last_index;
                goto increment_index;
            }
            state[0x70]++;
            goto complete;
        }
    }

increment_index:
    state[0x70]++;
service_check:
    if (state[0x70] < last_index)
        goto service_loop;

complete:
    msg = GKI_getbuf(0x110);
    if (msg != 0) {
        *(u16 *)msg = 0x208;
        *(u32 *)((u8 *)msg + 0x108) = *(u32 *)(state + 0x10);
        fn_80070FA4((u8 *)msg + 8, state + 0x1A);
        name = state + 0x20;
        if ((s8)state[0x20] == 0) {
            u8 *read_name = (u8 *)BTM_SecReadDevName(state + 0x1A);
            if (read_name != 0)
                name = read_name;
        }
        strncpy((char *)msg + 0xE, (char *)name, 0x20);
        fn_80071450(msg);
    }
}

void bta_dm_discover_next_device(void) {
    /* Advances to the next inquiry result and starts service/name discovery, or posts search-complete when none remain. */
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
    u8 *strBase = lbl_80316570;
    u8 *pp = (u8 *)p_parms;
    u8 *p_sco;
    u8 *p_setup;
    u16 temp_pkt;
    u16 req;
    if (sco_inx >= 3) {
        return BTM_WRONG_MODE;
    }
    p_sco = lbl_803C0F78 + sco_inx * 0x34;
    if (*(u16 *)(p_sco + 0x185C) != 4) {
        return BTM_WRONG_MODE;
    }
    p_setup = p_sco + 0x1868;
    if (*(u8 *)(p_sco + 0x1882) == 0 || lbl_803C0F78[0x1908] == 0) {
        *(u16 *)(p_setup + 0xC) = (*(u16 *)(pp + 2) & (*(u16 *)(lbl_803C0F78 + 0x656) & 7));
        if (lbl_803C0F78[0x27C0] >= 3) {
            fn_8007096C(0xD0002, strBase + 0x248, *(u16 *)(p_sco + 0x185E), *(u16 *)(p_setup + 0xC));
        }
        if (btsnd_hcic_change_conn_type(*(u16 *)(p_sco + 0x185E), (*(u16 *)(p_setup + 0xC) << 5) & 0xE0) == 0) {
            return BTM_NO_RESOURCES;
        }
        return BTM_CMD_STARTED;
    }
    req = *(u16 *)(pp + 2);
    temp_pkt = ((req & *(u16 *)(lbl_803C0F78 + 0x656)) & 0x3F);
    if (lbl_803C0F78[0x636] >= 3) {
        temp_pkt |= ((req | *(u16 *)(lbl_803C0F78 + 0x656)) & 0x3C0);
    }
    if (lbl_803C0F78[0x27C0] >= 3) {
        fn_80070954(0xD0002, strBase + 0x28C, *(u16 *)(p_sco + 0x185E));
    }
    if (lbl_803C0F78[0x27C0] >= 3) {
        fn_800709CC(0xD0002, strBase + 0x8C, *(u32 *)(p_sco + 0x1868), *(u32 *)(p_setup + 4), *(u16 *)(pp + 0), *(u16 *)(p_setup + 0xA), *(pp + 4), temp_pkt);
    }
    if (btsnd_hcic_setup_esco_conn(*(u16 *)(p_sco + 0x185E), *(u32 *)(p_sco + 0x1868), *(u32 *)(p_setup + 4), *(u16 *)(pp + 0), *(u16 *)(p_setup + 0xA), *(pp + 4), temp_pkt) == 0) {
        return BTM_NO_RESOURCES;
    }
    *(u16 *)(pp + 2) = temp_pkt;
    return BTM_CMD_STARTED;
}

extern u8 lbl_80316834[];
// Handle eSCO connection change for the matching SCO/eSCO link entry.
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
    switch (state) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        count = 1;
        break;
    default:
        break;
    }
    state = *(unsigned short *)(base + 0x1890);
    switch (state) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        count++;
        break;
    default:
        break;
    }
    state = *(unsigned short *)(base + 0x18c4);
    switch (state) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        count++;
        break;
    default:
        break;
    }
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
    u8 *p = lbl_803C0F78;
    volatile u32 *src = (volatile u32 *)arg0;
    u32 first = src[0];
    u32 second = src[1];
    u8 level = p[0x27C0];
    u32 fourth;
    u32 third;
    u32 sixth;
    register u32 fifth;

    *(u32 *)(p + 0x190C) = first;
    *(u32 *)(p + 0x1910) = second;
    third = src[2];
    fourth = src[3];
    *(u32 *)(p + 0x1914) = third;
    *(u32 *)(p + 0x1918) = fourth;
    fifth = src[4];
    sixth = src[5];
    *(u32 *)(p + 0x191C) = fifth;
    *(u32 *)(p + 0x1920) = sixth;
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
/* Sets the host's PIN type/code in BTM state and programs the controller when ready. */
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

/*
 * tBTM_SEC_SERV_REC as this stack lays it out: 0x3C bytes, and
 * BTM_SEC_MAX_SERVICE_RECORDS_HERE of them in btm_cb at 0x1990.  The header's
 * version has a 16-bit security_flags (and newer configs add UCD flags), so
 * its field offsets no longer fit this build.
 */
typedef struct {
    UINT32 mx_proto_id;             /* 0x00 multiplexer protocol below L2CAP */
    UINT32 orig_mx_chan_id;         /* 0x04 its channel, for a connection we open */
    UINT32 term_mx_chan_id;         /* 0x08 its channel, for a connection we accept */
    UINT16 psm;                     /* 0x0C L2CAP PSM of the service */
    UINT8  security_flags;          /* 0x0E BTM_SEC_* required; BTM_SEC_IN_USE when taken */
    UINT8  service_id;              /* 0x0F passed to the authorization callback */
    UINT8  orig_service_name[0x16]; /* 0x10 name to show, for a connection we open */
    UINT8  term_service_name[0x16]; /* 0x26 name to show, for a connection we accept */
} tBTM_SEC_SERV_REC_HERE;           /* 0x3C */

/* This stack's service-record config; bt_target.h describes a newer one. */
#define BTM_SEC_MAX_SERVICE_RECORDS_HERE 0x18
#define BTM_SEC_SERVICE_NAME_LEN_HERE    0x15
#define btm_cb_sec_serv_rec ((tBTM_SEC_SERV_REC_HERE *)(lbl_803C0F78 + 0x1990))
#ifndef BTM_NO_AVAIL_SEC_SERVICES
#define BTM_NO_AVAIL_SEC_SERVICES ((UINT16)0xffff) /* btm_sec.c's "no free record" */
#endif

/* Register one service's security requirements with the security manager: the
 * record of a service already registered under the same PSM, multiplexer
 * protocol, service id and name is updated, otherwise the first free record is
 * taken (and the last one reused when none is free). */
BOOLEAN BTM_SetSecurityLevel(BOOLEAN is_originator, char *p_name, UINT8 service_id, UINT16 sec_level, UINT16 psm, UINT32 mx_proto_id, UINT32 mx_chan_id) {
    char *trace = lbl_80316870; /* this file's trace strings */
    tBTM_SEC_SERV_REC_HERE *p_srec;
    UINT16 index;
    UINT16 first_unused_record;
    BOOLEAN record_allocated;

    first_unused_record = BTM_NO_AVAIL_SEC_SERVICES;
    p_srec = btm_cb_sec_serv_rec;
    record_allocated = FALSE;
    index = 0;
    for (; index < BTM_SEC_MAX_SERVICE_RECORDS_HERE; index++, p_srec++) {
        /* a record in use for this very service can be reused as it is */
        if (p_srec->security_flags & BTM_SEC_IN_USE) {
            if (p_srec->psm == psm &&
                p_srec->mx_proto_id == mx_proto_id &&
                service_id == p_srec->service_id &&
                (strncmp(p_name, (char *)p_srec->orig_service_name, BTM_SEC_SERVICE_NAME_LEN_HERE) == 0 ||
                 strncmp(p_name, (char *)p_srec->term_service_name, BTM_SEC_SERVICE_NAME_LEN_HERE) == 0)) {
                record_allocated = TRUE;
                break;
            }
        } else if (!record_allocated) {
            /* remember the first free record to fall back on */
            record_allocated = TRUE;
            first_unused_record = index;
        }
    }
    if (record_allocated) {
        /* no duplicate service: take that first free record */
        if (index >= BTM_SEC_MAX_SERVICE_RECORDS_HERE) {
            index = first_unused_record;
            p_srec = &btm_cb_sec_serv_rec[index];
        }
        p_srec->psm = psm;
        p_srec->service_id = service_id;
        p_srec->mx_proto_id = mx_proto_id;
        if (is_originator) {
            p_srec->orig_mx_chan_id = mx_chan_id;
            p_srec->security_flags &= ~0x38; /* old BTM_SEC_OUT_{AUTHORIZE,AUTHENTICATE,ENCRYPT} */
            strncpy((char *)p_srec->orig_service_name, p_name, BTM_SEC_SERVICE_NAME_LEN_HERE);
        } else {
            p_srec->term_mx_chan_id = mx_chan_id;
            p_srec->security_flags &= 0xF8; /* old BTM_SEC_IN_{AUTHORIZE,AUTHENTICATE,ENCRYPT} */
            strncpy((char *)p_srec->term_service_name, p_name, BTM_SEC_SERVICE_NAME_LEN_HERE);
        }
        p_srec->security_flags |= sec_level | BTM_SEC_IN_USE;
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_API) {
            ((void (*)(u32, void *, s32, u32, u32, u32, u32, u32))fn_800709CC)(
                TRACE_LAYER_BTM | TRACE_TYPE_API, trace + 0xE0, /* "BTM_SEC_REG[%d]: id %d, is_orig %d, psm 0x%04x, proto_id %d, chan_id %d" */
                index, service_id, is_originator, psm, mx_proto_id, mx_chan_id);
        }
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_API) {
            ((void (*)(u32, void *, u8, char *, u32))fn_80070984)(
                TRACE_LAYER_BTM | TRACE_TYPE_API, trace + 0x128, /* "               : sec: 0x%x, service name [%s] (up to %d chars saved)" */
                p_srec->security_flags, p_name, BTM_SEC_SERVICE_NAME_LEN_HERE);
        }
    } else if (btm_cb_trace_level >= BTM_TRACE_LEVEL_WARNING) {
        fn_80070954(0xD0001 /* TRACE_LAYER_BTM | TRACE_TYPE_ERROR */, trace + 0x170, /* "BTM_SEC_REG: Out of Service Records (%d)" */
                    BTM_SEC_MAX_SERVICE_RECORDS_HERE);
    }
    return record_allocated;
}

void BTM_PINCodeReply(BD_ADDR bd_addr, UINT8 res, UINT8 pin_len, UINT8 *p_pin, UINT32 trusted_mask[]) {
    /* Reply to a PIN code request: stop the pairing timer, send negative or positive HCI reply, and save trusted services. */
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
/* Records the application's authorization verdict for bd_addr: on success marks the device authorized and saves its trusted services, then if the record was waiting in AUTHORIZING state clears it to IDLE and either reports a denial or runs the pending security procedure and reports its result through the stored callback. */
void BTM_DeviceAuthorized(BD_ADDR bd_addr, UINT8 res, UINT32 trusted_mask[]) {
    tBTM_SEC_DEV_REC_FULL_VIEW *p_dev_rec = (tBTM_SEC_DEV_REC_FULL_VIEW *)btm_find_dev(bd_addr);
    tBTM_SEC_DEV_REC_FULL_VIEW *dev = p_dev_rec;
    if (p_dev_rec == 0) {
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_WARNING) {
            fn_800709CC(0xD0001 /* TRACE_LAYER_BTM | TRACE_TYPE_WARNING */, lbl_80316A10, bd_addr[0], bd_addr[1], bd_addr[2],
                        bd_addr[3], bd_addr[4], bd_addr[5]);
        }
    } else {
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_EVENT)
            fn_8007096C(0xD0003 /* TRACE_LAYER_BTM | TRACE_TYPE_EVENT */, lbl_80316A70, res,
                        (UINT8)(dev->sec_state * (p_dev_rec != 0)));
        if (res == 0) {
            dev->sec_flags |= BTM_SEC_AUTHORIZED;
            dev->trusted_mask[0] = trusted_mask[0];
            dev->trusted_mask[1] = trusted_mask[1];
        }
        if (dev->sec_state == BTM_SEC_STATE_AUTHORIZING) {
            dev->sec_state = BTM_SEC_STATE_IDLE;
            if (res != 0) {
                if (dev->p_callback != 0) {
                    if (dev->is_originator != 0) {
                        tBTM_SEC_SERV_REC *p_service = dev->p_cur_service;
                        if (p_service != 0 && p_service->mx_proto_id == BTM_SEC_PROTO_RFCOMM) p_service->orig_mx_chan_id = 0;
                    }
                    ((void (*)(u8 *, u32, u8))dev->p_callback)(bd_addr, (u32)dev->p_ref_data, res);
                    dev->p_callback = 0;
                }
            } else {
                res = btm_sec_execute_procedure(dev);
                if (res != BTM_CMD_STARTED && dev->p_callback != 0) {
                    if (dev->is_originator != 0) {
                        tBTM_SEC_SERV_REC *p_service = dev->p_cur_service;
                        if (p_service != 0 && p_service->mx_proto_id == BTM_SEC_PROTO_RFCOMM) p_service->orig_mx_chan_id = 0;
                    }
                    ((void (*)(u8 *, u32, u8))dev->p_callback)(bd_addr, (u32)dev->p_ref_data, res);
                    dev->p_callback = 0;
                }
            }
        }
    }
}

/* Pair bd_addr with us: authenticate (and then encrypt) a link that is already
   up, or page the device to bring one up.  The PIN the caller passes, if any,
   is kept in btm_cb for the controller to ask for.  Returns BTM_SUCCESS when
   the device is paired already, BTM_CMD_STARTED once the controller is working
   on it, or why bonding could not be started. */
tBTM_STATUS BTM_SecBond(BD_ADDR bd_addr, UINT8 pin_len, UINT8 *p_pin, UINT32 trusted_mask[]) {
    tBTM_SEC_DEV_REC *p_dev_rec;
    tBTM_INQ_INFO *p_inq_info;
    UINT8 value;              /* btm_cb.devcb.local_features[0], then the HCI command status */
    UINT8 allow_role_switch;
    register char *messages = lbl_80316870;
    register tBTM_SEC_DEV_REC_FULL_VIEW *dev;
    register UINT8 *pin = p_pin;
    register UINT32 *mask = trusted_mask;

    if (btm_cb_trace_level >= BTM_TRACE_LEVEL_API) {
        fn_800709CC(TRACE_LAYER_BTM | TRACE_TYPE_API, messages + 0x230, /* "BTM_SecBond BDA: %02x:%02x:%02x:%02x:%02x:%02x" */
                    bd_addr[0], bd_addr[1], bd_addr[2],
                    bd_addr[3], bd_addr[4], bd_addr[5]);
    }

    if (pin_len > PIN_CODE_LEN) {
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_ERROR) {
            fn_80070954(TRACE_LAYER_BTM | TRACE_TYPE_ERROR, messages + 0x260, pin_len); /* "BTM_SecBond: Illegal Pin len:%d" */
        }
        return BTM_ILLEGAL_VALUE;
    }

    p_dev_rec = btm_find_dev(bd_addr);
    dev = (tBTM_SEC_DEV_REC_FULL_VIEW *)p_dev_rec;
    if (dev == NULL) {
        p_dev_rec = btm_sec_alloc_dev(bd_addr);
        dev = (tBTM_SEC_DEV_REC_FULL_VIEW *)p_dev_rec;
        if (dev == NULL) {
            if (btm_cb_trace_level >= BTM_TRACE_LEVEL_ERROR) {
                fn_8007093C(TRACE_LAYER_BTM | TRACE_TYPE_ERROR, messages + 0x280); /* "BTM_SecBond: no device block" */
            }
            return BTM_NO_RESOURCES;
        }
    }

    /* The link is up and the device is authenticated: it is paired already. */
    if (dev->hci_handle != BTM_SEC_INVALID_HANDLE && (dev->sec_flags & BTM_SEC_AUTHENTICATED)) {
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_WARNING) {
            fn_8007093C(TRACE_LAYER_BTM | TRACE_TYPE_WARNING, messages + 0x2A0); /* "BTM_SecBond -> Already Paired" */
        }
        return BTM_SUCCESS;
    }

    /* Make the controller forget any link key it still holds for this device. */
    if (BTM_DeleteStoredLinkKey(bd_addr, NULL) != BTM_SUCCESS) {
        return BTM_NO_RESOURCES;
    }

    dev->sec_req = 0x50;      /* authenticate and encrypt: this stack's BTM_SEC_OUT_* pair */
    dev->is_originator = 1;
    dev->trusted_mask[0] = mask[0];
    dev->trusted_mask[1] = mask[1];
    btm_cb_pin_code_len = pin_len;
    if (pin_len != 0) {
        memcpy(btm_cb_pin_code, pin, pin_len);
    }

    dev->sec_flags &= ~(BTM_SEC_LINK_KEY_KNOWN | BTM_SEC_AUTHENTICATED | BTM_SEC_ENCRYPTED);
    /* A keyboard is paired by typing its PIN twice, so it needs the fixed
       PIN type - the controller would otherwise ask for a variable one. */
    if ((dev->dev_class[1] & BTM_COD_MAJOR_CLASS_MASK) == BTM_COD_MAJOR_PERIPHERAL &&
        (dev->dev_class[2] & BTM_COD_MINOR_KEYBOARD) &&
        btm_cb_cfg_pin_type != HCI_PIN_TYPE_FIXED) {
        btm_cb_pin_type_changed = 1;
        btsnd_hcic_write_pin_type(HCI_PIN_TYPE_FIXED);
    }

    btm_cb_disc_reason = 0;
    if (dev->hci_handle != BTM_SEC_INVALID_HANDLE) {
        /* Link already up: authenticate it instead of paging. */
        dev->sec_flags &= ~BTM_SEC_LINK_KEY_KNOWN;
        dev->sec_state = BTM_SEC_STATE_AUTHENTICATING;
        if (!btsnd_hcic_auth_request(dev->hci_handle)) {
            return BTM_NO_RESOURCES;
        }
        btm_cb_bonding = 0;
        return BTM_CMD_STARTED;
    }

    if (btm_cb_security_mode != 3) { /* less than secure simple pairing */
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_DEBUG) {
            fn_8007093C(TRACE_LAYER_BTM | TRACE_TYPE_DEBUG, messages + 0x2C0); /* "BTM_SecBond: Authen Enable -> TRUE" */
        }
        if ((UINT8)btsnd_hcic_write_auth_enable(1) == 0) {
            if (btm_cb_trace_level >= BTM_TRACE_LEVEL_ERROR) {
                fn_8007093C(TRACE_LAYER_BTM | TRACE_TYPE_ERROR, messages + 0x2E4); /* "BTM_SecBond: no buffer" */
            }
            return BTM_NO_RESOURCES;
        }
        btm_cb_mode_changed = 1;
    }

    /* Page the device; the PIN request and what follows run from the events. */
    btm_cb_bonding = 1;
    value = *(UINT8 *)fn_8007A3A4();      /* btm_cb.devcb.local_features[0] */
    dev->conn_up = 0;
    allow_role_switch = (value >> 5) & 1; /* HCI_LM_ACCEPT */
    p_inq_info = BTM_InqDbRead(bd_addr);
    if (p_inq_info != NULL) {
        value = btsnd_hcic_create_conn(
            bd_addr, 0x18, /* packet types: DH1 */
            p_inq_info->results.page_scan_rep_mode,
            p_inq_info->results.page_scan_mode,
            p_inq_info->results.clock_offset | BTM_CLOCK_OFFSET_VALID,
            allow_role_switch);
    } else {
        value = btsnd_hcic_create_conn(
            bd_addr, 0x18, 1, 0, dev->clock_offset, allow_role_switch);
    }
    if (value != 0) {
        return BTM_CMD_STARTED;
    }

    if (btm_cb_trace_level >= BTM_TRACE_LEVEL_ERROR) {
        fn_8007093C(TRACE_LAYER_BTM | TRACE_TYPE_ERROR, messages + 0x2E4); /* "BTM_SecBond: no buffer" */
    }
    if (btm_cb_mode_changed != 0) {
        /* btm_restore_mode(): put the authentication enable back as the
           security mode wants it. */
        btm_cb_mode_changed = 0;
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_DEBUG) {
            ((void (*)(u32, void *, u32))fn_80070954)(
                TRACE_LAYER_BTM | TRACE_TYPE_DEBUG, messages + 0x2FC, /* "btm_restore_mode: Authen Enable -> %d" */
                ((btm_cb_security_mode - 3) == 0));
        }
        btsnd_hcic_write_auth_enable((UINT8)((btm_cb_security_mode - 3) == 0));
    }
    return BTM_NO_RESOURCES;
}

tBTM_STATUS btm_sec_l2cap_access_req(BD_ADDR bd_addr, UINT16 psm, UINT16 handle,
                                       CONNECTION_TYPE conn_type,
                                       tBTM_SEC_CALLBACK *p_callback,
                                       void *p_ref_data) {
    tBTM_SEC_DEV_REC *p_dev_rec;
    u8 *p_serv;
    u8 *p_next;
    u8 *dev;
    u8 *messages = (u8 *)lbl_80316870;
    UINT32 i;
    UINT32 j;
    UINT8 sec_flags;
    UINT8 found_current;
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

    /* Handle incoming HCI connection request: reject if pairing is required or app callback declines, else cache address/class and accept via L2CAP. */
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
    u32 zero = 0;
    u32 *p;
    u8 state;
    void (*cb)(BD_ADDR, void *, void *);
    tBTM_SEC_DEV_REC *dev = btm_find_dev(arg0);
    if (dev == 0)
        return;
    cb = *(void (**)(BD_ADDR, void *, void *))((u8 *)lbl_803C0F78 + 0x1920);
    if (cb != 0)
        cb(arg0, (u8 *)dev + 0x22, (u8 *)dev + 0x35);
    state = *((u8 *)dev + 0x7f);
    if (state == 4)
        return;
    if (state != 1)
        return;
    *((u8 *)dev + 0x7f) = (u8)zero;
    if (*((u8 *)dev + 0x80) == 0)
        return;
    p = *(u32 **)dev;
    if (p == 0)
        return;
    if (*p != 3)
        return;
    p[1] = zero;
    *(u32 *)((u8 *)dev + 4) = zero;
}

extern char lbl_80316E44[];
/* Called when the remote name request for a device ends, with p_bd_name and
 * status from the HCI Remote_Name_Request_Complete event (a failed request
 * carries no address).  The name goes into the device record, everyone waiting
 * for a name is told, then whatever security work was parked behind the name
 * (the owed link key notification, a bonding link that can drop now, or the
 * security procedure the upper layer asked for) is carried on.
 *
 * btm_cb (lbl_803C0F78) is read at its byte offsets here: taking it through
 * tBTM_CB_SEC_VIEW makes the compiler keep its base in a callee-saved register.
 */
void btm_sec_rmt_name_request_complete(UINT8 *p_bd_addr, UINT8 *p_bd_name, UINT8 status)
{
    tBTM_SEC_DEV_REC_FULL_VIEW *p_dev_rec;
    int i;
    int j;
    UINT8 *p;
    UINT8 state;
    UINT8 result;
    tBTM_RMT_NAME_CALLBACK *name_cb;
    tBTM_LINK_KEY_NOTIFY_CB *security_cb;
    tBTM_SEC_CBACK *complete_cb;

    if (p_bd_addr) {
        p_dev_rec = (tBTM_SEC_DEV_REC_FULL_VIEW *)btm_find_dev(p_bd_addr);
    } else {
        /* No address with a failed request: only one name is asked for at a
           time, so find the record that is still waiting for its name. */
        p_dev_rec = (tBTM_SEC_DEV_REC_FULL_VIEW *)(lbl_803C0F78 + 0x1F30); /* btm_cb.sec_dev_rec */
        for (i = 0; i < 0x10; i++, p_dev_rec++) { /* BTM_SEC_MAX_DEVICE_RECORDS here */
            if (!(p_dev_rec->sec_flags & BTM_SEC_IN_USE))
                continue;
            if (p_dev_rec->sec_state == BTM_SEC_STATE_GETTING_NAME)
                break;
        }
        if (i == 0x10)
            p_dev_rec = NULL;
    }

    if (lbl_803C0F78[0x27C0] >= BT_TRACE_LEVEL_EVENT) /* "Security Manager: rmt_name_complete status:%d State:%d" */
        fn_8007096C(TRACE_LAYER_BTM | TRACE_TYPE_EVENT, lbl_80316E44, status,
                    p_dev_rec ? p_dev_rec->sec_state : 0);

    if (!p_dev_rec)
        return;

    if (status == HCI_SUCCESS) {
        memcpy(p_dev_rec->sec_bd_name, p_bd_name, 0x40);
        p_dev_rec->sec_flags |= BTM_SEC_NAME_KNOWN;
        /* Tell every client waiting for this name. */
        p = (UINT8 *)lbl_803C0F78;
        for (j = 0; j < BTM_SEC_MAX_RMT_NAME_CALLBACKS; j++, p += 4) {
            name_cb = *(tBTM_RMT_NAME_CALLBACK **)(p + 0x192C); /* btm_cb.p_rmt_name_callback[j] */
            if (name_cb)
                name_cb(p_bd_addr, p_dev_rec->dev_class, p_dev_rec->sec_bd_name);
        }
    }

    if (p_dev_rec->link_key_not_sent) {
        /* A bonding link whose connection has not come up yet still owes it. */
        if ((p_dev_rec->sec_req & BTM_SEC_BOND) && !p_dev_rec->conn_up)
            return;
        p_dev_rec->link_key_not_sent = 0;
        security_cb = *(tBTM_LINK_KEY_NOTIFY_CB **)(lbl_803C0F78 + 0x1914); /* btm_cb.api.p_link_key_callback */
        if (security_cb)
            security_cb(p_dev_rec->bd_addr, p_dev_rec->dev_class, p_dev_rec->sec_bd_name,
                        p_dev_rec->link_key, p_dev_rec->link_key_type);
        p = (UINT8 *)lbl_803C0F78;
        for (j = 0; j < BTM_SEC_MAX_LINK_KEY_NOTIFY_CALLBACKS; j++, p += 4) {
            security_cb = *(tBTM_LINK_KEY_NOTIFY_CB **)(p + 0x1924); /* btm_cb.p_link_key_notify_callback[j] */
            if (security_cb)
                security_cb(p_dev_rec->bd_addr, p_dev_rec->dev_class, p_dev_rec->sec_bd_name,
                            p_dev_rec->link_key, p_dev_rec->link_key_type);
        }
    }

    /* A link brought up only for bonding is done with once the name is known. */
    state = p_dev_rec->sec_req;
    if ((state & BTM_SEC_BOND) && (p_dev_rec->sec_flags & BTM_SEC_AUTHENTICATED)) {
        p_dev_rec->sec_req = state & ~(BTM_SEC_BOND | BTM_SEC_OUT_AUTHENTICATE);
        btsnd_hcic_disconnect(p_dev_rec->hci_handle, HCI_ERR_PEER_USER);
        return;
    }

    if (p_dev_rec->sec_state == BTM_SEC_STATE_GETTING_NAME) {
        p_dev_rec->sec_state = BTM_SEC_STATE_IDLE;
        if (status != HCI_SUCCESS) {
            /* No name: end the security request that was waiting for it. */
            if (p_dev_rec->p_callback) {
                p_dev_rec->p_callback(p_dev_rec->bd_addr, p_dev_rec->p_ref_data,
                                      BTM_ERR_PROCESSING);
                p_dev_rec->p_callback = NULL;
            }
            return;
        }

        result = btm_sec_execute_procedure(p_dev_rec);
        if (result != BTM_CMD_STARTED) { /* not still working on it: report */
            if (p_dev_rec->p_callback) {
                complete_cb = p_dev_rec->p_callback;
                complete_cb(p_dev_rec->bd_addr, p_dev_rec->p_ref_data, result);
                p_dev_rec->p_callback = NULL;
            }
        }
    }
}

/*
 * btm_sec_auth_complete - the link manager finished authenticating the
 * connection whose HCI handle is `handle`; status is the HCI error code
 * (HCI_SUCCESS when the link is authenticated).  It puts back the
 * authentication-enable and the PIN type that pairing raised
 * (btm_restore_mode), drops a link that was only opened to bond, tells the
 * app's authentication callback how it went and then runs the security
 * procedure the service asked for - reporting that to whoever asked for
 * security, unless the controller is still working on it.
 *
 * btm_cb (lbl_803C0F78) is read at its byte offsets here (the btm_cb_*
 * macros): taking it through tBTM_CB_SEC_VIEW makes the compiler keep its
 * base address in a callee-saved register instead of reloading it.
 */
void btm_sec_auth_complete(register UINT16 handle, register UINT8 status) {
    extern char lbl_80316E7C[]; /* "Security Manager: auth_complete status:%d State:%d" */
    extern char lbl_80316B6C[]; /* "btm_restore_mode: Authen Enable -> %d" */
    extern BOOL btsnd_hcic_write_pin_type_8008543C(u32); /* = btsnd_hcic_write_auth_enable */
    extern u8 btm_sec_execute_procedure(void *);
    register tBTM_SEC_DEV_REC_FULL_VIEW *dev =
        (tBTM_SEC_DEV_REC_FULL_VIEW *)btm_find_dev_by_handle(handle);
    register tBTM_SEC_DEV_REC_FULL_VIEW *disc_rec;
    tBTM_AUTH_COMPLETE_CB *auth_cb;   /* btm_cb.p_auth_complete_callback */
    register tBTM_SEC_SERV_REC *service;
    register UINT8 old_state;
    register UINT8 reason;
    register UINT8 sec_req;
    UINT32 authen_enable;

    if (btm_cb_trace_level >= BTM_TRACE_LEVEL_EVENT) {
        fn_8007096C(TRACE_LAYER_BTM | TRACE_TYPE_EVENT, lbl_80316E7C, status,
                    dev ? dev->sec_state : 0);
    }

    /* btm_restore_mode(): put back what raising the security level for
       pairing changed in the controller. */
    if (btm_cb_mode_changed != 0) {
        btm_cb_mode_changed = 0;
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_DEBUG) {
            authen_enable = (btm_cb_security_mode == BTM_SEC_MODE_LINK);
            ((void (*)(u32, void *, u32))fn_80070954)(TRACE_LAYER_BTM | TRACE_TYPE_DEBUG,
                                                      lbl_80316B6C, authen_enable);
        }
        btsnd_hcic_write_pin_type_8008543C(
            (u8)(btm_cb_security_mode == BTM_SEC_MODE_LINK));
    }

    if (btm_cb_pin_type_changed != 0) {
        btm_cb_pin_type_changed = 0;
        btsnd_hcic_write_pin_type(btm_cb_cfg_pin_type);
    }

    /* A link opened just for bonding is done with once it is authenticated:
       clear what bonding asked for and drop it (btm_sec_disconnect). */
    if (dev != 0) {
        sec_req = dev->sec_req;
        if ((sec_req & BTM_SEC_BOND) != 0 && btm_cb_bonding == 0) {
            dev->sec_req = sec_req & ~(BTM_SEC_BOND | BTM_SEC_OUT_AUTHENTICATE);
            reason = btm_cb_disc_reason;
            if (reason != 0) {
                disc_rec = (tBTM_SEC_DEV_REC_FULL_VIEW *)btm_find_dev_by_handle(handle);
                if (disc_rec != 0) {
                    if ((disc_rec->sec_req & BTM_SEC_BOND) != 0) {
                        btm_cb_disc_reason = reason; /* still bonding: drop it later */
                    } else {
                        old_state = disc_rec->sec_state;
                        if (old_state != BTM_SEC_STATE_DISCONNECTING_HERE) {
                            disc_rec->sec_state = BTM_SEC_STATE_DISCONNECTING_HERE;
                            if (!btsnd_hcic_disconnect(handle, reason))
                                disc_rec->sec_state = old_state;
                        }
                    }
                }
            }
        }
    }

    if (dev != 0) {
        if (dev->sec_state != BTM_SEC_STATE_AUTHENTICATING) {
            /* Not the authentication we were waiting for: only a failure is
               worth telling the app about. */
            auth_cb = *(tBTM_AUTH_COMPLETE_CB **)(lbl_803C0F78 + 0x191C);
            if (auth_cb != 0 && status != HCI_SUCCESS)
                auth_cb(dev->bd_addr, dev->dev_class, dev->sec_bd_name, status);
        } else {
            /* The peer encrypted the link before authenticating it, which the
               spec allows: what we wanted is there anyway. */
            if (status == HCI_ERR_COMMAND_DISALLOWED &&
                (dev->sec_flags & (BTM_SEC_AUTHENTICATED | BTM_SEC_ENCRYPTED)) ==
                    (BTM_SEC_AUTHENTICATED | BTM_SEC_ENCRYPTED))
                status = HCI_SUCCESS;
            auth_cb = *(tBTM_AUTH_COMPLETE_CB **)(lbl_803C0F78 + 0x191C);
            if (auth_cb != 0)
                auth_cb(dev->bd_addr, dev->dev_class, dev->sec_bd_name, status);
            handle = 0;
            dev->sec_state = (u8)handle; /* BTM_SEC_STATE_IDLE */
            sec_req = dev->sec_req;
            if ((sec_req & BTM_SEC_BOND) != 0) {
                dev->sec_req = sec_req & ~(BTM_SEC_BOND | BTM_SEC_OUT_AUTHENTICATE);
                btsnd_hcic_disconnect(dev->hci_handle, HCI_ERR_PEER_USER);
            } else if (status != HCI_SUCCESS) {
                if (dev->p_callback != 0) {
                    if (dev->is_originator != 0) {
                        /* An RFCOMM service we called: its channel is free again. */
                        service = dev->p_cur_service;
                        if (service != 0 && service->mx_proto_id == 3)
                            service->orig_mx_chan_id = handle;
                    }
                    ((void (*)(void *, void *, UINT8))dev->p_callback)(
                        dev->bd_addr, dev->p_ref_data, BTM_ERR_PROCESSING);
                    dev->p_callback = 0;
                }
                btsnd_hcic_disconnect(dev->hci_handle, HCI_ERR_AUTH_FAILURE);
            } else {
                dev->sec_flags |= BTM_SEC_AUTHENTICATED;
                status = btm_sec_execute_procedure(dev);
                if (status != BTM_CMD_STARTED && dev->p_callback != 0) {
                    if (dev->is_originator != 0) {
                        service = dev->p_cur_service;
                        if (service != 0 && service->mx_proto_id == 3)
                            service->orig_mx_chan_id = handle;
                    }
                    ((void (*)(void *, void *, UINT8))dev->p_callback)(
                        dev->bd_addr, dev->p_ref_data, status);
                    dev->p_callback = 0;
                }
            }
        }
    }
}

/* Handles master-key completion by logging and notifying the registered callback. */
void btm_sec_mkey_comp_event(u16 handle, u8 status, u8 event) {
    extern char lbl_80316EB0[];
    extern u8 lbl_80560D40;
    extern u8 lbl_80560D41;
    extern u8 lbl_80560D42;
    extern u8 lbl_80560D43;
    extern u8 lbl_80560D44;
    extern u8 lbl_80560D45;
    u8 fallback_bd_addr[6];
    tBTM_SEC_DEV_REC *device;
    void (*callback)(u8 *, u8, u8);

    device = btm_find_dev_by_handle(handle);
    fallback_bd_addr[0] = lbl_80560D40;
    fallback_bd_addr[1] = lbl_80560D41;
    fallback_bd_addr[2] = lbl_80560D42;
    fallback_bd_addr[3] = lbl_80560D43;
    fallback_bd_addr[4] = lbl_80560D44;
    fallback_bd_addr[5] = lbl_80560D45;

    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_8007096C(0xD0003, lbl_80316EB0, status,
                    device != 0 ? ((u8 *)device)[0x7F] : 0);
    }

    callback = *(void (**)(u8 *, u8, u8))(lbl_803C0F78 + 0x27B0);
    if (callback != 0) {
        if (device == 0) {
            callback(fallback_bd_addr, status, event);
        } else {
            callback((u8 *)device + 0x1C, status, event);
        }
    }
}

void btm_sec_encrypt_change(UINT16 handle, UINT8 status, UINT8 encr_enable) {
    /* Handle HCI Encryption Change: log, retry on LMP collision (status 0x23), or complete/fail pending security procedure. */
    tBTM_SEC_DEV_REC *p_dev_rec;
    void (*callback)(u8 *, u32, u8);
    u8 result;

    p_dev_rec = btm_find_dev_by_handle(handle);
    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_8007096C(0xD0003, lbl_80316EE0, status,
                    p_dev_rec != NULL ? ((u8 *)p_dev_rec)[0x7F] : 0);
    }
    if (p_dev_rec == NULL) {
        return;
    }
    if (status == 0x23) {
        *(void **)(lbl_803C0F78 + 0x1938) = p_dev_rec;
        *(void (**)(void))(lbl_803C0F78 + 0x196C) = btm_sec_collision_timeout;
        btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0F78 + 0x195C), 0x16, 1);
        return;
    }
    if (status != 0) {
        callback = *(void (**)(u8 *, u32, u8))((u8 *)p_dev_rec + 4);
        if (callback != NULL) {
            callback((u8 *)p_dev_rec + 0x1C,
                     *(u32 *)((u8 *)p_dev_rec + 8), 0xA);
            *(void **)((u8 *)p_dev_rec + 4) = NULL;
        }
        return;
    }
    ((u8 *)p_dev_rec)[0x76] |= 6;
    if (((u8 *)p_dev_rec)[0x7F] == 2) {
        ((u8 *)p_dev_rec)[0x7F] = 0;
        result = btm_sec_execute_procedure(p_dev_rec);
        if (result != 1) {
            callback = *(void (**)(u8 *, u32, u8))((u8 *)p_dev_rec + 4);
            if (callback != NULL) {
                callback((u8 *)p_dev_rec + 0x1C,
                         *(u32 *)((u8 *)p_dev_rec + 8), result);
                *(u32 *)((u8 *)p_dev_rec + 4) = 0;
            }
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
/*
 * btm_sec_connected - the security manager heard that the ACL link to bda came
 * up or failed (HCI Connection Complete, and a connection the host rejected).
 * It finds or allocates the device record and stamps it, puts back the
 * authentication-enable and PIN type that pairing changed (btm_restore_mode),
 * reports the new link key and "pairing done" when dedicated bonding finished -
 * dropping the bonding-only link again - and otherwise starts the security
 * procedure the service asked for.  status is the HCI error code (HCI_SUCCESS
 * for a link that came up) and enc_mode the encryption mode it came up in.
 *
 * btm_cb (lbl_803C0F78) is read at its byte offsets here: taking it through the
 * tBTM_CB_SEC_VIEW struct makes the compiler keep its base address in a
 * callee-saved register over the whole function instead of reloading it.
 */
void btm_sec_connected(UINT8 *bda, UINT16 handle, UINT8 status, UINT8 enc_mode) {
    extern char lbl_80316B6C[]; /* "btm_restore_mode: Authen Enable -> %d" */
    tBTM_SEC_DEV_REC_FULL_VIEW *p_dev_rec;
    UINT8 rc;
    UINT8 *entry;
    INT32 count;
    UINT32 timestamp;

    p_dev_rec = (tBTM_SEC_DEV_REC_FULL_VIEW *)btm_find_dev(bda);
    if (lbl_803C0F78[0x27C0] >= BT_TRACE_LEVEL_EVENT) /* "Security Manager: btm_sec_connected handle:%d status:%d enc_mode:%d" */
        ((void (*)(UINT32, void *, UINT16, UINT8, UINT8))fn_80070984)(
            TRACE_LAYER_BTM | TRACE_TYPE_EVENT, lbl_80316F14, handle, status, enc_mode);
    if (p_dev_rec == NULL) {
        /* Unknown device: take a record for it, but a failure of a device we
           never heard of is nothing to report. */
        if (status == HCI_SUCCESS) {
            p_dev_rec = (tBTM_SEC_DEV_REC_FULL_VIEW *)btm_sec_alloc_dev(bda);
            if (p_dev_rec == NULL)
                return;
        } else {
            return;
        }
    } else {
        /* Known device: it becomes the most recently used one. */
        /* btm_cb.dev_rec_count: a stamp ordering the device records */
        timestamp = *(UINT32 *)(lbl_803C0F78 + 0x1974);
        p_dev_rec->timestamp = timestamp;
        *(UINT32 *)(lbl_803C0F78 + 0x1974) = timestamp + 1;
        p_dev_rec->conn_up = 1;
    }

    /* btm_restore_mode(): undo what raising the security level for bonding set. */
    if (p_dev_rec->sec_req & BTM_SEC_BOND) {
        if (lbl_803C0F78[0x197B] != 0) { /* security_mode_changed */
            lbl_803C0F78[0x197B] = 0;
            if (lbl_803C0F78[0x27C0] >= BT_TRACE_LEVEL_DEBUG)
                ((void (*)(UINT32, void *, UINT32))fn_80070954)(
                    TRACE_LAYER_BTM | TRACE_TYPE_DEBUG, lbl_80316B6C,
                    (lbl_803C0F78[0x1978] - BTM_SEC_MODE_LINK) == 0); /* security_mode */
            btsnd_hcic_write_pin_type_8008543C(/* = btsnd_hcic_write_auth_enable */
                (UINT8)((lbl_803C0F78[0x1978] - BTM_SEC_MODE_LINK) == 0));
        }
        if (lbl_803C0F78[0x197C] != 0) { /* pin_type_changed */
            lbl_803C0F78[0x197C] = 0;
            btsnd_hcic_write_pin_type(lbl_803C0F78[0x20]); /* cfg_pin_type */
        }
    }

    if (status != HCI_SUCCESS) {
        /* These failures mean the link key is no longer usable (or pairing was
           refused), so forget it; any other failure only ends this attempt. */
        if ((status == HCI_ERR_AUTH_FAILURE || status == HCI_ERR_KEY_MISSING ||
            status == HCI_ERR_HOST_REJECT_SECURITY ||
            status == HCI_ERR_PAIRING_NOT_ALLOWED || status == HCI_ERR_UNIT_KEY_USED ||
            status == HCI_ERR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED ||
            status == HCI_ERR_ENCRY_MODE_NOT_ACCEPTABLE ||
            status == HCI_ERR_REPEATED_ATTEMPTS ||
            status == HCI_ERR_LMP_RESPONSE_TIMEOUT) ||
            (p_dev_rec->sec_req & BTM_SEC_BOND)) {
            *(volatile UINT8 *)&p_dev_rec->sec_req &= ~(BTM_SEC_BOND | BTM_SEC_OUT_AUTHENTICATE);
            p_dev_rec->sec_flags &= ~BTM_SEC_FLAG_LKEY_KNOWN;
            if (*(UINT32 *)(lbl_803C0F78 + 0x194C) != 0) { /* pin_code_tle_cback: a PIN wanted */
                fn_80070F90(lbl_803C0F78 + 0x193C); /* cancel the pin_code_tle timer */
                status = HCI_ERR_HOST_REJECT_SECURITY;
                *(UINT32 *)(lbl_803C0F78 + 0x194C) = 0;
            }
            if (lbl_803C0F78[0x27BF] == HCI_ERR_HOST_REJECT_SECURITY) /* acl_disc_reason */
                status = HCI_ERR_HOST_REJECT_SECURITY;
            /* p_auth_complete_callback: tell the app pairing ended */
            if (*(tBTM_AUTH_COMPLETE_CB **)(lbl_803C0F78 + 0x191C) != NULL)
                (*(tBTM_AUTH_COMPLETE_CB **)(lbl_803C0F78 + 0x191C))(
                    p_dev_rec->bd_addr, p_dev_rec->dev_class, p_dev_rec->sec_bd_name, status);
            return;
        }
        if (p_dev_rec->p_callback != NULL) { /* btm_sec_dev_rec_cback_event() */
            if (p_dev_rec->is_originator != 0) {
                /* An RFCOMM service we called: its server channel is free again. */
                tBTM_SEC_SERV_REC *p_serv_rec = p_dev_rec->p_cur_service;
                if (p_serv_rec != NULL && p_serv_rec->mx_proto_id == 3)
                    p_serv_rec->orig_mx_chan_id = 0;
            }
            if (status == HCI_ERR_CONNECTION_TOUT || status == HCI_ERR_UNSPECIFIED ||
                status == HCI_ERR_PAGE_TIMEOUT)
                ((void (*)(void *, void *, UINT8))p_dev_rec->p_callback)(
                    p_dev_rec->bd_addr, p_dev_rec->p_ref_data, BTM_DEVICE_TIMEOUT);
            else
                ((void (*)(void *, void *, UINT8))p_dev_rec->p_callback)(
                    p_dev_rec->bd_addr, p_dev_rec->p_ref_data, BTM_ERR_PROCESSING);
        }
        return;
    }

    /* Dedicated bonding over a link that came up: hand out the new link key,
       say pairing is done and drop the link that was only opened to pair. */
    if ((p_dev_rec->sec_req & BTM_SEC_BOND) && p_dev_rec->link_key_not_sent != 0) {
        p_dev_rec->link_key_not_sent = 0;
        /* p_link_key_callback: the app's new-link-key handler */
        if (*(tBTM_LINK_KEY_NOTIFY_CB **)(lbl_803C0F78 + 0x1914) != NULL)
            (*(tBTM_LINK_KEY_NOTIFY_CB **)(lbl_803C0F78 + 0x1914))(
                p_dev_rec->bd_addr, p_dev_rec->dev_class, p_dev_rec->sec_bd_name,
                p_dev_rec->link_key, p_dev_rec->link_key_type);
        /* p_link_key_notify_callback[]: the extra notifiers registered on top */
        entry = lbl_803C0F78;
        for (count = 0; count < BTM_SEC_MAX_LINK_KEY_NOTIFY_CALLBACKS; count++, entry += 4) {
            if (*(tBTM_LINK_KEY_NOTIFY_CB **)(entry + 0x1924) != NULL)
                (*(tBTM_LINK_KEY_NOTIFY_CB **)(entry + 0x1924))(
                    p_dev_rec->bd_addr, p_dev_rec->dev_class, p_dev_rec->sec_bd_name,
                    p_dev_rec->link_key, p_dev_rec->link_key_type);
        }
        if (*(tBTM_AUTH_COMPLETE_CB **)(lbl_803C0F78 + 0x191C) != NULL)
            (*(tBTM_AUTH_COMPLETE_CB **)(lbl_803C0F78 + 0x191C))(
                p_dev_rec->bd_addr, p_dev_rec->dev_class, p_dev_rec->sec_bd_name,
                HCI_SUCCESS);
        rc = p_dev_rec->sec_req;
        p_dev_rec->sec_req &= ~(BTM_SEC_BOND | BTM_SEC_OUT_AUTHENTICATE);
        btsnd_hcic_disconnect(handle, HCI_ERR_PEER_USER);
        return;
    }

    p_dev_rec->hci_handle = handle;
    p_dev_rec->sec_flags &= ~(BTM_SEC_FLAG_AUTHORIZED | BTM_SEC_FLAG_ENCRYPTED |
                              BTM_SEC_FLAG_AUTHENTICATED);
    if (enc_mode != HCI_ENCRYPT_MODE_DISABLED)
        p_dev_rec->sec_flags |= (BTM_SEC_FLAG_AUTHENTICATED | BTM_SEC_FLAG_ENCRYPTED);
    if (lbl_803C0F78[0x1978] == BTM_SEC_MODE_LINK) /* security_mode */
        p_dev_rec->sec_flags |= BTM_SEC_FLAG_AUTHENTICATED;
    p_dev_rec->link_key_changed = 0;

    /* Only run security for a device we still have to learn about, or one we
       called ourselves: an authorized service may have been registered while
       the link was down. */
    if ((p_dev_rec->sec_flags & BTM_SEC_NAME_KNOWN) != 0 && p_dev_rec->is_originator == 0)
        return;
    rc = btm_sec_execute_procedure(p_dev_rec);
    if (rc == BTM_CMD_STARTED)
        return;
    if (p_dev_rec->p_callback != NULL) { /* btm_sec_dev_rec_cback_event(p_dev_rec, rc) */
        if (p_dev_rec->is_originator != 0) {
            tBTM_SEC_SERV_REC *p_serv_rec = p_dev_rec->p_cur_service;
            if (p_serv_rec != NULL && p_serv_rec->mx_proto_id == 3)
                p_serv_rec->orig_mx_chan_id = 0;
        }
        ((void (*)(void *, void *, UINT8))p_dev_rec->p_callback)(
            p_dev_rec->bd_addr, p_dev_rec->p_ref_data, rc);
        p_dev_rec->p_callback = NULL;
    }
}

tBTM_STATUS btm_sec_disconnect(UINT16 handle, UINT8 reason) {
    // Requests HCI disconnect for a security device record, storing reason when disconnect is deferred and restoring state on failure.
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

/* Handles security-manager cleanup on HCI disconnect: notifies the auth-complete callback (lbl_803C0F78+0x191C) for the device (found by handle) on disconnect/pair-timeout, cancels a pending PIN-code timer for that BD_ADDR, and resets the device record's connection/security state. */
void btm_sec_disconnected(UINT16 handle, UINT8 reason) {
    register UINT8 disconnectReason = reason;
    tBTM_SEC_DEV_REC_DISCONNECT_VIEW *deviceRec =
        (tBTM_SEC_DEV_REC_DISCONNECT_VIEW *)btm_find_dev_by_handle(handle);
    if (deviceRec == NULL)
        return;
    if ((deviceRec->sm4 & 0x40) &&
        *(void **)(lbl_803C0F78 + 0x191C) != NULL) {
        if (disconnectReason == 0x17) {
            ((void (*)(u8 *, u8 *, u8 *, u32))*(void **)(lbl_803C0F78 + 0x191C))
                (deviceRec->bd_addr, deviceRec->dev_class, deviceRec->sec_bd_name, 0x17);
        } else {
            ((void (*)(u8 *, u8 *, u8 *, u32))*(void **)(lbl_803C0F78 + 0x191C))
                (deviceRec->bd_addr, deviceRec->dev_class, deviceRec->sec_bd_name, 5);
        }
    }
    if (*(u32 *)(lbl_803C0F78 + 0x194C) != 0 &&
        memcmp(lbl_803C0F78 + 0x1954, deviceRec->bd_addr, 6) == 0) {
        fn_80070F90(lbl_803C0F78 + 0x193C);
        *(u32 *)(lbl_803C0F78 + 0x194C) = 0;
        memset(lbl_803C0F78 + 0x1954, 0xFF, 6);
        if (*(void **)(lbl_803C0F78 + 0x191C) != NULL)
            ((void (*)(u8 *, u8 *, u8 *, u32))*(void **)(lbl_803C0F78 + 0x191C))
                (deviceRec->bd_addr, deviceRec->dev_class, deviceRec->sec_bd_name, 0xE);
    }
    deviceRec->hci_handle = 0xFFFF;
    deviceRec->sec_state = 0;
    deviceRec->sec_flags &= 0xF8;
    deviceRec->sm4 &= 0x80;
    deviceRec->unk_0x04 = 0;
}

/* Match note: initialize the callback table at its base, then walk two entries by four bytes.
 * Notifies BTM callbacks of a new/updated link key for a device, allocating/storing device state as needed. */
void btm_sec_link_key_notification(u8 *bd_addr, u8 *link_key, u8 key_type) {
    extern u8 lbl_80316F58[];
    extern u8 lbl_80316F9C[];
    u8 *dev = (u8 *)btm_find_dev(bd_addr);
    u32 (*auth_cb)(void *, void *, void *, void *, u8);
    u32 (*key_cb)(void *, void *, void *, void *, u8);
    u8 *callbackTable;
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
    callbackTable = lbl_803C0F78;
    i = 0;
    do {
        key_cb = *(u32 (**)(void *, void *, void *, void *, u8))(callbackTable + 0x1924);
        if (key_cb != NULL)
            key_cb(bd_addr, dev + 0x22, dev + 0x35, link_key, dev[0x83]);
        i++;
        callbackTable += 4;
    } while (i < 2);
}

extern char lbl_80316FC8[];
void btm_sec_link_key_request(BD_ADDR bd_addr) {
    tBTM_SEC_DEV_REC *p_dev_rec;
    tBTM_SEC_DEV_REC_MATCH_VIEW *p_dev_view;
    u8 temp_link_key[16];
    u8 (*p_link_key_req_cb)(BD_ADDR, u8 *);

    /* Handle controller link-key request: reply with stored/app key when available, else negative reply. */
    p_dev_rec = btm_find_dev(bd_addr);
    p_dev_view = (tBTM_SEC_DEV_REC_MATCH_VIEW *)p_dev_rec;
    if (lbl_803C0F78[0x27C0] >= 4)
        fn_800709CC(0xD0003, lbl_80316FC8, bd_addr[0], bd_addr[1], bd_addr[2], bd_addr[3], bd_addr[4], bd_addr[5]);

    if (p_dev_rec != 0 && (p_dev_view->sec_flags_76 & 0x10)) {
        btsnd_hcic_link_key_req_reply(bd_addr, p_dev_view->link_key);
        return;
    }

    if (p_dev_rec == 0) {
        p_dev_rec = btm_sec_alloc_dev(bd_addr);
        p_dev_view = (tBTM_SEC_DEV_REC_MATCH_VIEW *)p_dev_rec;
    }

    if ((p_dev_view->sec_flags_81 & 0x40) == 0) {
        p_link_key_req_cb = *(u8 (**)(BD_ADDR, u8 *))(lbl_803C0F78 + 0x1918);
        if (p_link_key_req_cb != 0) {
            if (p_dev_rec != 0) {
                if (p_link_key_req_cb(bd_addr, p_dev_view->link_key) == 0) {
                    btsnd_hcic_link_key_req_reply(bd_addr, p_dev_view->link_key);
                    return;
                }
            } else if (p_link_key_req_cb(bd_addr, temp_link_key) == 0) {
                btsnd_hcic_link_key_req_reply(bd_addr, temp_link_key);
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
    /* Handle the controller's HCI Pin Code Request event for device p_bda:
       answer it from a fixed/stored PIN, reject it, or pass it up to the
       application's PIN callback with a timeout running. */
    u8 *trace = (u8 *)lbl_80316870;
    s32 count;
    u8 *cb = lbl_803C0F78; /* &btm_cb */
    tBTM_SEC_DEV_REC *p_dev_rec;
    tBTM_SEC_DEV_REC_FULL_VIEW *dev;
    u8 *entry;
    void (*p_pin_callback)(u8 *, u8 *, u8 *);
    BOOL do_reject;
    s32 i;

    do_reject = FALSE;
    count = 0;

    if (cb[0x27C0] >= BTM_TRACE_LEVEL_EVENT) { /* btm_cb.trace_level */
        fn_800709CC(TRACE_LAYER_BTM | TRACE_TYPE_EVENT, trace + 0x7BC, p_bda[0], p_bda[1],
                    p_bda[2], p_bda[3], p_bda[4], p_bda[5]);
    }

    /* pairing enabled and a fixed PIN is configured: reply with it, unless too
       many device records are already waiting for a link key */
    if (cb[0x1979] == 0 && cb[0x20] == HCI_PIN_TYPE_FIXED) { /* pairing_disabled, cfg.pin_type */
        if (btm_find_dev(p_bda) == NULL) {
            entry = lbl_803C0F78 + 0x1F30; /* btm_cb.sec_dev_rec[] */
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
        btsnd_hcic_pin_code_req_reply(p_bda, cb[0x21], cb + 0x22); /* cfg.pin_code_len, cfg.pin_code */
        return;
    }

    p_dev_rec = btm_find_dev(p_bda);
    if (p_dev_rec == NULL) {
        p_dev_rec = btm_sec_alloc_dev(p_bda);
    }
    memcpy(btm_cb_pairing_bda, p_bda, 6);
    dev = (tBTM_SEC_DEV_REC_FULL_VIEW *)p_dev_rec;
    if (dev != NULL) {
        /* use the connecting device's class of device for this connection */
        if (memcmp(p_bda, cb + 0x27B4, 6) == 0) { /* connecting_bda */
            memcpy(dev->dev_class, cb + 0x27BA, 3); /* connecting_dc */
        }
        if (dev->sec_req & BTM_SEC_BOND) {
            /* a PIN was already supplied by the user: send it to the controller */
            if (btm_cb_trace_level >= BTM_TRACE_LEVEL_EVENT) {
                fn_8007093C(TRACE_LAYER_BTM | TRACE_TYPE_EVENT, trace + 0x7FC);
            }
            btsnd_hcic_pin_code_req_reply(p_bda, cb[0x197F], cb + 0x1980); /* pin_code_len, pin_code */
            if (btm_cb_mode_changed != 0) {
                btm_cb_mode_changed = 0;
                if (btm_cb_trace_level >= BTM_TRACE_LEVEL_DEBUG) {
                    ((void (*)(u32, void *, u32))fn_80070954)(
                        TRACE_LAYER_BTM | TRACE_TYPE_DEBUG, trace + 0x82C,
                        (u32)((btm_cb_security_mode - 3) == 0));
                }
                btsnd_hcic_write_auth_enable(
                    (u8)((btm_cb_security_mode - 3) == 0));
            }
        } else if (cb[0x1979] != 0 || *(void **)(cb + 0x1910) == NULL ||
                   (dev->is_originator == 0 && (dev->dev_class[1] & BTM_COD_MAJOR_CLASS_MASK) == BTM_COD_MAJOR_PERIPHERAL &&
                    (dev->dev_class[2] & BTM_COD_MINOR_KEYBOARD))) {
            /* pairing off, no callback to ask, or a stray keyboard: reject it */
            do_reject = TRUE;
        } else {
            /* remember the device, start the PIN timeout and ask the application */
            memcpy(cb + 0x27B4, p_bda, 6);
            memcpy(cb + 0x27BA, dev->dev_class, 3);
            *(void **)(cb + 0x194C) = btm_sec_pin_code_request_timeout; /* pin timer timeout_func */
            btu_start_timer((TIMER_LIST_ENT *)(cb + 0x193C), 0x16, 0x3C);
            p_pin_callback = *(void (**)(u8 *, u8 *, u8 *))(cb + 0x1910); /* api.p_pin_callback */
            p_pin_callback(p_bda, dev->dev_class, dev->sec_bd_name);
        }
    } else {
        do_reject = TRUE;
    }

    if (do_reject) {
        if (btm_cb_trace_level >= BTM_TRACE_LEVEL_WARNING) {
            ((void (*)(u32, void *, u8, void *, void *))fn_80070984)(
                TRACE_LAYER_BTM | TRACE_TYPE_WARNING, trace + 0x85C, cb[0x1979],
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

u8 btm_sec_execute_procedure(void *arg0) {
    extern void fn_8007093C(u32, void *);
    extern char lbl_80316870[];
    char *p_str = lbl_80316870;
    u8 *dev = (u8 *)arg0;
    void *lcb;
    u8 tempstate;
    u8 flags;
    u8 sid;

    if (lbl_803C0F78[0x27C0] >= 4)
        ((void (*)(u32, void *, u8, u8, u8))fn_80070984)(0xD0003, p_str + 0x8AC, dev[0x81], dev[0x76], dev[0x7F]);

    if (dev[0x7F] != 0)
        return 1;

    if (*(u16 *)(dev + 0x18) == 0xFFFF) {
        lcb = l2cu_allocate_lcb(dev + 0x1C);
        if (lcb == 0) {
            if (lbl_803C4040[0] >= 2)
                fn_8007093C(0x80001, p_str + 0x8EC);
            return 3;
        }
        if (!l2cu_create_conn(lcb))
            return 3;
        dev[0x80] = 1;
        return 1;
    }

    if (!(dev[0x76] & 8) && *(u16 *)(dev + 0x18) != 0xFFFF) {
        u8 started;
        if (lbl_803C0F78[0x27C0] >= 4)
            fn_8007093C(0xD0003, p_str + 0x910);
        tempstate = dev[0x7F];
        dev[0x7F] = 3;
        if (btm_initiate_rem_name(dev + 0x1C, 0, 2, 0x1E, 0) != 1) {
            dev[0x7F] = tempstate;
            started = 0;
        } else {
            started = 1;
        }
        if (started)
            return 1;
        dev[0x76] |= 8;
    }

    flags = dev[0x76];
    if (!(flags & 2)
        && ((dev[0x80] && (dev[0x81] & 0x10)) || (!dev[0x80] && (dev[0x81] & 2)))
        && *(u16 *)(dev + 0x18) != 0xFFFF) {
        if (lbl_803C0F78[0x27C0] >= 4)
            fn_8007093C(0xD0003, p_str + 0x934);
        dev[0x7F] = 1;
        if (!btsnd_hcic_auth_request(*(u16 *)(dev + 0x18)))
            return 3;
        return 1;
    }

    if (!(flags & 4)
        && ((dev[0x80] && (dev[0x81] & 0x20)) || (!dev[0x80] && (dev[0x81] & 4)))
        && *(u16 *)(dev + 0x18) != 0xFFFF) {
        u8 ok;
        if (lbl_803C0F78[0x27C0] >= 4)
            fn_8007093C(0xD0003, p_str + 0x95C);
        if (!btsnd_hcic_set_conn_encrypt(*(u16 *)(dev + 0x18), 1)) {
            ok = 0;
        } else {
            dev[0x7F] = 2;
            ok = 1;
        }
        if (!ok)
            return 3;
        return 1;
    }

    if (!(flags & 1)
        && ((dev[0x80] && (dev[0x81] & 8)) || (!dev[0x80] && (dev[0x81] & 1)))) {
        u32 all;
        if (*(u32 *)(dev + 0x10) != 0xFFFFFFFF) {
            all = 0;
            goto have_all;
        }
        if (*(u32 *)(dev + 0x14) != 0xFFFFFFFF) {
            all = 0;
            goto have_all;
        }
        all = 1;
have_all:
        if (all == 0) {
            sid = (*(u8 **)dev)[0xF];
            if (sid < 0x2E && !((1 << (sid & 0x1F)) & *(u32 *)(dev + ((sid >> 3) & 0x1C) + 0x10))) {
                if (lbl_803C0F78[0x27C0] >= 4)
                    fn_8007093C(0xD0003, p_str + 0x980);
                return btm_sec_start_authorization(dev);
            }
        }
    }

    dev[0x81] &= 0xC0;
    if (lbl_803C0F78[0x27C0] >= 4)
        ((void (*)(u32, void *, u32, u32))fn_8007096C)(0xD0003, p_str + 0x9A8, *(u32 *)(dev + 0x14), *(u32 *)(dev + 0x10));
    if (lbl_803C0F78[0x27C0] >= 4)
        fn_8007093C(0xD0003, p_str + 0x9D0);
    return 0;
}

u8 btm_sec_start_authorization(u8 *devRec) {
    u8 *peerRec;
    u8 *remoteName;
    u8 prevSecState;
    u8 peerFlag;
    u8 authResult;

    remoteName = 0;

    /* Start authorization for a device: if known/connected, invoke the authorization callback (or fail if none); otherwise initiate a remote name request first. */
    if ((devRec[0x76] & 8) != 0 || *(u16 *)(devRec + 0x18) == 0xFFFF) {
        if (*(u32 *)(lbl_803C0F78 + 0x190C) == 0)
            return 4;
        peerRec = *(u8 **)devRec;
        if (peerRec != 0) {
            remoteName = devRec[0x80] ? peerRec + 0x10 : peerRec + 0x26;
            peerFlag = peerRec[0xF];
        } else {
            peerFlag = 0;
        }
        devRec[0x7F] = 4;
        authResult = (*(u8 (**)(void *, void *, void *, void *, u8, u8))(lbl_803C0F78 + 0x190C))(devRec + 0x1C, devRec + 0x22, devRec + 0x35, remoteName, peerFlag, devRec[0x80]);
        if (authResult == 0) {
            prevSecState = devRec[0x76];
            devRec[0x7F] = 0;
            devRec[0x76] = prevSecState | 1;
        }
        return authResult;
    }
    prevSecState = devRec[0x7F];
    devRec[0x7F] = 3;
    if (btm_initiate_rem_name(devRec + 0x1C, 0, 2, 0x1E, 0) != 1)
        devRec[0x7F] = prevSecState;
    return 1;
}

/* Retry the security procedure for the collided device after a collision timeout. */
void btm_sec_collision_timeout(void) {
    extern u8 btm_sec_execute_procedure(void *);
    extern void fn_8007093C(u32, void *);
    extern char lbl_80317264[];
    u8 status;

    if (lbl_803C0F78[0x27C0] >= 4) {
        fn_8007093C(0xD0003, lbl_80317264);
    }

    *(u32 *)(lbl_803C0F78 + 0x196C) = 0;

    status = btm_sec_execute_procedure(*(void **)(lbl_803C0F78 + 0x1938));
    if (status != 1) {
        void *dev_rec = *(void **)(lbl_803C0F78 + 0x1938);
        if (*(u32 *)((u8 *)dev_rec + 4) != 0) {
            if (*((u8 *)dev_rec + 0x80) != 0) {
                void *cur_service = *(void **)dev_rec;
                if (cur_service != 0 && *(u32 *)cur_service == 3) {
                    *(u32 *)((u8 *)cur_service + 4) = 0;
                }
            }

            ((void (*)(void *, void *, u8))(*(void **)(*(u8 **)(lbl_803C0F78 + 0x1938) + 4)))(
                (u8 *)*(void **)(lbl_803C0F78 + 0x1938) + 0x1C,
                *(void **)(*(u8 **)(lbl_803C0F78 + 0x1938) + 8),
                status);
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

extern char lbl_80317280[];
extern void l2c_link_role_changed(u8 *, u8);
extern void hidd_pm_proc_mode_change(s32, u8, s32);
extern void fn_8008C464(u8 *);
extern void btu_hcif_connection_comp_evt(u8 *);
extern void btu_hcif_connection_request_evt(u8 *);
extern void btu_hcif_qos_setup_comp_evt(void *);
extern void btu_hcif_command_complete_evt(UINT8 *, UINT16);
extern void btu_hcif_command_status_evt(UINT8 *, UINT16);
extern void btu_hcif_link_key_notification_evt(u8 *, u16);
extern void btu_hcif_esco_connection_comp_evt(u8 *);
extern s32 l2c_link_hci_qos_violation(u16);
extern void l2c_link_process_num_completed_pkts(u8 *, u16);
extern BOOLEAN l2c_link_hci_disc_comp(UINT16, UINT8);

void btu_hcif_process_event(BT_HDR *p_msg) {
    UINT8 *p = (UINT8 *)(p_msg + 1) + p_msg->offset;
    UINT8 hci_evt_code, hci_evt_len;

    hci_evt_code = p[0];
    hci_evt_len = p[1];

    if (lbl_803C0F78[0x64E] == 0 && hci_evt_code != 0xE && hci_evt_code != 0xF)
        return;

    switch (hci_evt_code) {
    case 0x01:
        ((void (*)(UINT8))btm_process_inq_complete)(p[2]);
        break;
    case 0x02:
        btm_process_inq_results(p + 2, 0);
        break;
    case 0x22:
        btm_process_inq_results(p + 2, 1);
        break;
    case 0x03:
        btu_hcif_connection_comp_evt(p + 2);
        break;
    case 0x04:
        btu_hcif_connection_request_evt(p + 2);
        break;
    case 0x05: {
        UINT8 status;
        UINT16 handle;
        UINT8 reason;
        UINT8 *d = p + 2;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_UINT16(handle, d);
        handle = HCID_GET_HANDLE(handle);
        STREAM_TO_UINT8(reason, d);
        if (!l2c_link_hci_disc_comp(handle, reason))
            btm_sco_removed(handle, reason);
        btm_sec_disconnected(handle, reason);
        break;
    }
    case 0x06: {
        UINT16 handle;
        UINT8 status;
        UINT8 *d = p + 2;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_UINT16(handle, d);
        btm_sec_auth_complete(handle, status);
        break;
    }
    case 0x07: {
        BD_ADDR bd_addr;
        UINT8 status;
        UINT8 *d = p + 2;
        UINT8 *p_name;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_BDADDR(bd_addr, d);
        p_name = d;
        btm_process_remote_name(bd_addr, p_name, hci_evt_len - 7, status);
        btm_sec_rmt_name_request_complete(bd_addr, p_name, status);
        break;
    }
    case 0x08: {
        UINT8 enable;
        UINT16 handle;
        UINT8 status;
        UINT8 *d = p + 2;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_UINT16(handle, d);
        STREAM_TO_UINT8(enable, d);
        btm_acl_encrypt_change(handle, status, enable);
        btm_sec_encrypt_change(handle, status, enable);
        break;
    }
    case 0x0A: {
        UINT16 handle;
        UINT8 status, key_flg;
        UINT8 *d = p + 2;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_UINT16(handle, d);
        STREAM_TO_UINT8(key_flg, d);
        btm_sec_mkey_comp_event(handle, status, key_flg);
        break;
    }
    case 0x0B:
        btm_read_remote_features_complete(p + 2);
        break;
    case 0x0C:
        btm_read_remote_version_complete(p + 2);
        break;
    case 0x0D:
        btu_hcif_qos_setup_comp_evt(p + 2);
        break;
    case 0x0E:
        ((void (*)(UINT8 *))btu_hcif_command_complete_evt)(p + 2);
        break;
    case 0x0F:
        ((void (*)(UINT8 *))btu_hcif_command_status_evt)(p + 2);
        break;
    case 0x10:
        fn_8007093C(0x70000, lbl_80317280);
        if (fn_80079514())
            BTM_DeviceReset(0);
        break;
    case 0x12: {
        BD_ADDR bd_addr;
        UINT8 status, role;
        UINT8 *d = p + 2;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_BDADDR(bd_addr, d);
        STREAM_TO_UINT8(role, d);
        if (status == 0)
            l2c_link_role_changed(bd_addr, role);
        btm_acl_role_changed(status, bd_addr, role);
        break;
    }
    case 0x13:
        ((void (*)(UINT8 *))l2c_link_process_num_completed_pkts)(p + 2);
        break;
    case 0x14: {
        UINT16 interval;
        UINT8 mode;
        UINT16 handle;
        UINT8 status;
        UINT8 *d = p + 2;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_UINT16(handle, d);
        STREAM_TO_UINT8(mode, d);
        STREAM_TO_UINT16(interval, d);
        ((void (*)(UINT8, UINT16, UINT8))btm_sco_chk_pend_unpark)(status, handle, mode);
        btm_pm_proc_mode_change(status, handle, mode, interval);
        hidd_pm_proc_mode_change(status, mode, interval);
        break;
    }
    case 0x15:
        if (p[2] != 0) {
            p[1] = 1;
            btm_return_link_keys_evt((tBTM_RETURN_LINK_KEYS_EVT *)(p + 1));
        }
        break;
    case 0x16: {
        BD_ADDR bd_addr;
        UINT8 *d = p + 2;
        STREAM_TO_BDADDR(bd_addr, d);
        fn_8008C464(bd_addr);
        btm_sec_pin_code_request(bd_addr);
        break;
    }
    case 0x17: {
        BD_ADDR bd_addr;
        UINT8 *d = p + 2;
        STREAM_TO_BDADDR(bd_addr, d);
        btm_sec_link_key_request(bd_addr);
        break;
    }
    case 0x18:
        ((void (*)(u8 *))btu_hcif_link_key_notification_evt)(p + 2);
        break;
    case 0x1C:
        if (p[2] == 0) {
            UINT16 handle, clock_offset;
            UINT8 *d = p + 3;
            STREAM_TO_UINT16(handle, d);
            handle = HCID_GET_HANDLE(handle);
            STREAM_TO_UINT16(clock_offset, d);
            btm_process_clk_off_comp_evt(handle, clock_offset);
            btm_sec_update_clock_offset(handle, clock_offset);
        }
        break;
    case 0x1E: {
        UINT16 handle;
        UINT8 *d = p + 2;
        STREAM_TO_UINT16(handle, d);
        handle = HCID_GET_HANDLE(handle);
        l2c_link_hci_qos_violation(handle);
        break;
    }
    case 0x21:
        break;
    case 0x2C:
        btu_hcif_esco_connection_comp_evt(p + 2);
        break;
    case 0x2D: {
        UINT8 status, tx_interval, retrans_window;
        UINT16 handle, rx_pkt_len, tx_pkt_len;
        UINT8 *d = p + 2;
        STREAM_TO_UINT8(status, d);
        STREAM_TO_UINT16(handle, d);
        STREAM_TO_UINT8(tx_interval, d);
        STREAM_TO_UINT8(retrans_window, d);
        STREAM_TO_UINT16(rx_pkt_len, d);
        STREAM_TO_UINT16(tx_pkt_len, d);
        btm_esco_proc_conn_chg(status, handle, tx_interval, retrans_window, rx_pkt_len, tx_pkt_len);
        break;
    }
    case 0xEF:
    case 0xFF:
        ((void (*)(UINT8 *))btm_vendor_specific_evt)(p + 2);
        break;
    }
}

int btu_hcif_send_cmd(arg0)
void *arg0;
{
    u8 *msg = (u8 *)arg0;
    u8 *queueBase;
    u8 *newMsg;
    u16 count;
    u16 opcode;
    u16 offset;
    u8 *payload;
    if (msg != 0) {
        if (*(volatile u16 *)(lbl_803C0A50 + 0x6C) != 0) {
            GKI_enqueue((BUFFER_Q *)(lbl_803C0A50 + 0x64), msg);
            msg = 0;
        }
    }
    if (*(volatile u16 *)(lbl_803C0A50 + 0x80) == 0 && lbl_803C0F78[0x64E] == 0)
        *(volatile u16 *)(lbl_803C0A50 + 0x80) = *(volatile u16 *)(lbl_803C0A50 + 0x6C) + 1;
    queueBase = lbl_803C0A50;
    while (*(volatile u16 *)(queueBase + 0x80) != 0) {
        if (msg == 0)
            msg = (u8 *)GKI_dequeue((BUFFER_Q *)(queueBase + 0x64));
        if (msg == 0)
            break;
        offset = *(u16 *)(msg + 4);
        payload = msg + offset;
        opcode = (u16)(((u16)payload[9] << 8) + payload[8]);
        if (opcode != 0x0C03 && opcode != 0x0C35) {
            newMsg = (u8 *)GKI_getpoolbuf(2);
            if (newMsg != 0) {
                memcpy(newMsg, msg, 8);
                memcpy(newMsg + *(u16 *)(newMsg + 4) + 8,
                       msg + *(u16 *)(msg + 4) + 8,
                       *(u16 *)(msg + 2));
                GKI_enqueue((BUFFER_Q *)(queueBase + 0x70), newMsg);
                btu_start_timer((TIMER_LIST_ENT *)(queueBase + 0x4C), 0x3C, 8);
            }
        }
        count = *(volatile u16 *)(queueBase + 0x80);
        *(volatile u16 *)(queueBase + 0x80) = count - 1;
        ((void (*)(void *, u16, u16))fn_8007079C)(msg, 0x2000, count);
        msg = 0;
    }
    if (msg != 0)
        GKI_enqueue((BUFFER_Q *)(lbl_803C0A50 + 0x64), msg);
}

/* Handle HCI Connection Complete event: dispatch ACL links to security/L2CAP and SCO links to SCO manager. */
void btu_hcif_connection_comp_evt(u8 *p_event) {
    u8 status;
    u16 handle;
    BD_ADDR bda;
    u8 link_type;
    u8 enc_mode;
    tBTM_ESCO_DATA esco_data;

    status = p_event[0];
    handle = (u16)((p_event[1] + (p_event[2] << 8)) & 0x0fff);
    bda[5] = p_event[3];
    bda[4] = p_event[4];
    bda[3] = p_event[5];
    bda[2] = p_event[6];
    bda[1] = p_event[7];
    bda[0] = p_event[8];
    link_type = p_event[9];
    enc_mode = p_event[10];
    if (link_type == 1) {
        btm_sec_connected(bda, handle, status, enc_mode);
        l2c_link_hci_conn_comp(status, handle, bda);
    } else {
        memset(&esco_data, 0, 0xE);
        memcpy(esco_data.bd_addr, bda, 6);
        btm_sco_connected(status, bda, handle, &esco_data);
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

/* Parses the HCI QoS Setup Complete event and forwards the result to BTM. */
void btu_hcif_qos_setup_comp_evt(void *event) {
    register u8 *event_bytes = (u8 *)event;
    register UINT8 *stream = event_bytes + 5;
    FLOW_SPEC flow;
    UINT8 status;
    UINT16 handle;
    status = event_bytes[0];
    handle = (UINT16)((event_bytes[1] + (event_bytes[2] << 8)));
    flow.qos_flags = event_bytes[3];
    flow.service_type = event_bytes[4];
    STREAM_TO_UINT32(flow.token_rate, stream);
    STREAM_TO_UINT32(flow.peak_bandwidth, stream);
    STREAM_TO_UINT32(flow.latency, stream);
    STREAM_TO_UINT32(flow.delay_variation, stream);
    btm_qos_setup_complete(status, handle, &flow);
}

/* Handles an HCI eSCO Connection Complete event and reports it to BTM. */
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

void btu_hcif_hdl_command_complete(s32 opcode, UINT8 *param2, UINT16 param3) {
    /* Dispatches HCI Command Complete events by opcode to the corresponding BTM handler
       (reset, inquiry, link keys, local info, VSC, etc.). */
    register s32 saved_opcode = opcode;

    switch (opcode) {
    case 0x0C03:
        btm_reset_complete();
        return;
    case 0x0402:
        ((void (*)(UINT8, u32))btm_process_inq_complete)(0, (u32)param2);
        return;
    case 0x0C05:
        btm_event_filter_complete(param2);
        return;
    case 0x0C0D:
        btm_read_stored_link_key_complete(param2);
        return;
    case 0x0C11:
        btm_write_stored_link_key_complete(param2);
        return;
    case 0x0C12:
        btm_delete_stored_link_key_complete(param2);
        return;
    case 0x1001:
        btm_read_local_version_complete(param2, param3);
        return;
    case 0x080C:
        btm_read_link_policy_complete(param2);
        return;
    case 0x1005:
        btm_read_hci_buf_size_complete(param2, param3);
        return;
    case 0x1003:
        btm_read_local_features_complete(param2, param3);
        return;
    case 0x0C14:
        btm_read_local_name_complete(param2, param3);
        return;
    case 0x1009:
        ((void (*)(UINT8 *, UINT16))fn_8007A280)(param2, param3);
        return;
    case 0x1403:
        btm_read_link_quality_complete(param2);
        return;
    case 0x1405:
        btm_read_rssi_complete(param2);
        return;
    default:
        if ((saved_opcode & 0xFC00) == 0xFC00) {
            ((void (*)(UINT8 *, u32, UINT16, tBTM_CMPL_CB *))btm_vsc_complete)(
                param2, (u32)saved_opcode, param3, (tBTM_CMPL_CB *)saved_opcode);
        }
        return;
    }
}

void btu_hcif_command_complete_evt(UINT8 *eventData, UINT16 dataLength) {
    UINT16 opcode;
    UINT16 queuedOpcode;
    void *commandBuffer;

    /* Handle HCI command-complete event: update status, reconcile queued command, manage timer, dispatch. */
    *(UINT16 *)(lbl_803C0A50 + 0x80) = eventData[0];
    opcode = (UINT16)(eventData[1] + (eventData[2] << 8));
    if (opcode != 0xC03 && opcode != 0xC35 && opcode != 0) {
        commandBuffer = GKI_dequeue((BUFFER_Q *)(lbl_803C0A50 + 0x70));
        if (commandBuffer != 0) {
            queuedOpcode = (UINT16)(((UINT8 *)commandBuffer)[8] + (((UINT8 *)commandBuffer)[9] << 8));
            if (opcode == 0xFC4C && queuedOpcode != opcode) {
                GKI_enqueue_head((BUFFER_Q *)(lbl_803C0A50 + 0x70), commandBuffer);
                return;
            }
            GKI_freebuf(commandBuffer);
        }
        if (fn_8006DF84(lbl_803C0A50 + 0x70) == 0)
            btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0A50 + 0x4C), 0x3C, 8);
        else
            fn_80070F90(lbl_803C0A50 + 0x4C);
    }
    btu_hcif_hdl_command_complete(opcode, eventData + 3, dataLength - 3);
    btu_hcif_send_cmd(0);
}

extern void l2c_link_role_change_failed(void);
/* Handle an HCI command-status event.  The link-policy mode commands report their
 * result to the power manager; any other command that failed to start has to be
 * reported to the BTM/L2CAP layer that started it, with the handle or BD_ADDR read
 * back out of the command the stack kept queued (p_cmd, NULL when it is gone). */
void btu_hcif_hdl_command_status(s32 opcode, UINT8 status, UINT8 *p_cmd) {
    tBTM_ESCO_DATA esco_data;
    BD_ADDR bd_addr;
    UINT16 handle;

    switch (opcode) {
    /* HCI_HOLD_MODE, HCI_SNIFF_MODE, HCI_EXIT_SNIFF_MODE, HCI_PARK_MODE,
     * HCI_EXIT_PARK_MODE: the mode change failed or went through. */
    case HCI_HOLD_MODE:
    case HCI_SNIFF_MODE:
    case HCI_EXIT_SNIFF_MODE:
    case HCI_PARK_MODE:
    case HCI_EXIT_PARK_MODE:
        btm_pm_proc_cmd_status(status);
        return;

    default:
        /* If the command failed to start, we may need to tell BTM */
        if (status != HCI_SUCCESS) {
            switch (opcode) {
            case HCI_INQUIRY:
                /* Tell inquiry processing that we are done */
                ((void (*)(UINT8))btm_process_inq_complete)(status);
                return;

            case HCI_RMT_NAME_REQUEST:
                /* Tell inquiry processing that we are done */
                btm_process_remote_name(0, 0, 0, status);
                btm_sec_rmt_name_request_complete(0, 0, status);
                return;

            case HCI_QOS_SETUP_COMP_EVT:
                /* Tell qos setup that we are done */
                btm_qos_setup_complete(status, 0, 0);
                return;

            case HCI_SWITCH_ROLE:
                /* Tell BTM that the command failed */
                btm_acl_role_changed(status, 0, BTM_ROLE_UNDEFINED);
                l2c_link_role_change_failed();
                return;

            case HCI_CREATE_CONNECTION:
                /* read bd addr out of stored command */
                if (p_cmd != 0) {
                    bd_addr[5] = p_cmd[1];
                    bd_addr[4] = p_cmd[2];
                    bd_addr[3] = p_cmd[3];
                    bd_addr[2] = p_cmd[4];
                    bd_addr[1] = p_cmd[5];
                    bd_addr[0] = p_cmd[6];
                    btm_sec_connected(bd_addr, HCI_INVALID_HANDLE, status, 0);
                    l2c_link_hci_conn_comp(status, HCI_INVALID_HANDLE, bd_addr);
                    return;
                }
                break;

            case HCI_SETUP_ESCO_CONNECTION:
                /* read handle out of stored command */
                if (p_cmd != 0) {
                    handle = p_cmd[1] + (p_cmd[2] << 8);
                    /* Determine if initial connection failed or is a change of setup */
                    if (btm_is_sco_active(handle) != 0) {
                        btm_esco_proc_conn_chg(status, handle, 0, 0, 0, 0);
                        return;
                    }
                    btm_sco_connected(status, 0, handle, &esco_data);
                    return;
                }
                break;

            default:
                if ((opcode & HCI_GRP_VENDOR_SPECIFIC) == HCI_GRP_VENDOR_SPECIFIC) {
                    ((void (*)(UINT8 *, s32, s32))btm_vsc_complete)(p_cmd, opcode, 1);
                }
                break;
            }
        }
        return;
    }
}

void btu_hcif_command_status_evt(UINT8 *p, UINT16 len) {
    UINT8 status;
    UINT16 opcode;
    UINT16 queued_opcode;
    void *buf;
    UINT8 *cmd;
    UINT8 *cmd_base;
    status = p[0];
    *(UINT16 *)(lbl_803C0A50 + 0x80) = p[1];
    opcode = (UINT16)(p[2] + (p[3] << 8));
    buf = 0;
    cmd = 0;
    if (opcode != 0xC03 && opcode != 0xC35 && opcode != 0) {
        buf = GKI_dequeue((BUFFER_Q *)(lbl_803C0A50 + 0x70));
        if (buf != 0) {
            cmd_base = (UINT8 *)buf + *(UINT16 *)((UINT8 *)buf + 4);
            queued_opcode = (UINT16)(cmd_base[8] + (cmd_base[9] << 8));
            cmd = cmd_base + 0xA;
            if (queued_opcode != opcode) {
                cmd = 0;
                ((void (*)(u32, void *, u16))fn_8007096C)(0x70001, &lbl_80317298, opcode);
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
    /* Handle HCI command timeout: fail pending command, dispatch status/complete, and send next command. */
    extern unsigned char lbl_803C0A50[];
    extern char lbl_803172C0[];
    extern char lbl_803172E0[];
    void *cmdBuf;
    register unsigned char *cmdData;
    register s32 opcode;
    UINT8 status;

    *(UINT16 *)(lbl_803C0A50 + 0x80) = 1;
    cmdBuf = GKI_dequeue((BUFFER_Q *)(lbl_803C0A50 + 0x70));
    if (cmdBuf == 0) {
        fn_8007093C(0x70001, lbl_803172C0);
        return;
    }
    if (fn_8006DF84(lbl_803C0A50 + 0x70) == 0)
        btu_start_timer((TIMER_LIST_ENT *)(lbl_803C0A50 + 0x4C), 0x3C, 8);
    cmdData = (unsigned char *)cmdBuf + *(UINT16 *)((unsigned char *)cmdBuf + 4);
    opcode = (UINT16)(cmdData[8] + (cmdData[9] << 8));
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
    btu_hcif_hdl_command_status(opcode, 0x1F, cmdData + 0xA);
    goto done;
complete:
    status = 0x1F;
    btu_hcif_hdl_command_complete(opcode, &status, 1);
done:
    GKI_freebuf(cmdBuf);
    fn_8007ABE8((void *)2);
    btu_hcif_send_cmd(0);
}

void btu_hcif_link_key_notification_evt(u8 *p, u16 evt_len) {
    BD_ADDR bda;
    LINK_KEY key;
    u8 key_type;

    bda[5] = p[0];
    bda[4] = p[1];
    bda[3] = p[2];
    bda[2] = p[3];
    bda[1] = p[4];
    bda[0] = p[5];
    key[15] = p[6];
    key[14] = p[7];
    key[13] = p[8];
    key[12] = p[9];
    key[11] = p[10];
    key[10] = p[11];
    key[9] = p[12];
    key[8] = p[13];
    key[7] = p[14];
    key[6] = p[15];
    key[5] = p[16];
    key[4] = p[17];
    key[3] = p[18];
    key[2] = p[19];
    key[1] = p[20];
    key[0] = p[21];
    key_type = p[22];
    btm_sec_link_key_notification(bda, key, key_type);
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
    /* Ensure a local SDP Device ID record exists, add the public browse root
     * UUID to its browse group list, and mark it as the primary record. */
    UINT8 diRecordBuf[0xFC];
    volatile UINT32 recordHandle = 0;
    UINT8 isPrimaryAttr[2];
    UINT16 browseGroupUuid = 0x1002;
    register UINT8 *diRecord;

    if (SDP_GetLocalDiRecord((tSDP_DI_GET_RECORD *)diRecordBuf, (UINT32 *)&recordHandle) != SDP_SUCCESS) {
        diRecord = diRecordBuf + 2;
        memset(diRecord, 0, 0xFA);
        *(UINT16 *)(diRecordBuf + 2) = 0xF;
        *(UINT16 *)(diRecordBuf + 4) = 1;
        diRecordBuf[10] = 1;
        if (SDP_SetLocalDiRecord((tSDP_DI_RECORD *)diRecord, (UINT32 *)&recordHandle) != SDP_SUCCESS) {
            recordHandle = 0;
            return FALSE;
        }
    }
    SDP_AddUuidSequence(recordHandle, 5, 1, &browseGroupUuid);
    isPrimaryAttr[0] = 0;
    isPrimaryAttr[1] = 1;
    SDP_AddAttribute(recordHandle, 0x8001, 1, 2, isPrimaryAttr);
    return TRUE;
}

/* --- the GAP control block, lbl_803C3740, 0x3AC bytes zeroed by GAP_Init ---
 * trace level at 0x28 (BT_TRACE_LEVEL_*), the two BTM callbacks at 0x20/0x24,
 * the L2CAP callbacks at 0x84..0xA8 and the eight connection blocks
 * (tGAP_CONN_VIEW below) from 0xAC.  What is left is the single
 * GAP_FindAddr_byname request the stack can have running, whose fields the
 * macros below name: */
#define gap_cb                    lbl_803C3740
#define gap_find_addr_cback(cb)   (*(void (**)(u32, u16 *))((u8 *)(cb) + 0x2C)) /* the user's tGAP_CALLBACK, called with a GAP_EVT_* and the result below */
#define gap_find_addr_inq_rec(cb) (*(void **)((u8 *)(cb) + 0x30))               /* inquiry DB record whose name is being read */
#define gap_find_addr_result(cb)  ((u16 *)((u8 *)(cb) + 0x34))                  /* status for that callback, its BD_ADDR at +2, the name looked for at +8 */
#define gap_find_addr_busy(cb)    (((u8 *)(cb))[0x7E])                          /* set while the request is running */

/* How many connections GAP can have at once (gap_int.h's GAP_NUM_CONNECTIONS);
   the control block's array of them starts at +0xAC. */
#define GAP_NUM_CONNECTIONS 8

/* Where a GAP connection is in its setup (gap_int.h's tGAP_CONN_STATE); the
   values are the game's, read off what its callbacks store in state. */
typedef enum {
    GAP_CONN_STATE_DISCONNECTED,    /* the block is free */
    GAP_CONN_STATE_WF_SEC_CMP,      /* waiting for BTM security to clear the peer */
    GAP_CONN_STATE_WF_L2CA_CONN,    /* L2CA_ConnectReq sent, waiting for its confirm */
    GAP_CONN_STATE_WF_L2CA_CFG,     /* channel up, both sides still configuring */
    GAP_CONN_STATE_OPEN             /* configured: data can flow */
} tGAP_CONN_STATE;

/* One GAP connection (gap_int.h's tGAP_CONNECTION), as far as this unit reaches
   into it; only the fields it uses are named. */
typedef struct {
    u8                  state;          /* +0x00 a tGAP_CONN_STATE */
    u8                  conn_flags;     /* +0x01 2: the peer's configuration is done, 4: ours is */
    u8                  pad_02[2];
    u16                 id;             /* +0x04 the GAP handle the client was given */
    u16                 cid;            /* +0x06 the L2CAP channel it rides on */
    u8                  wildcard;       /* +0x08 the BD_ADDR below stands for any address */
    BD_ADDR             bd_addr;        /* +0x09 the peer's address */
    u16                 psm;            /* +0x10 the PSM the client registered for */
    u16                 rem_mtu;        /* +0x12 MTU the peer's configuration allows (clamped to 0x69B) */
    BUFFER_Q            pending_data;   /* +0x14 buffers that arrived before the client had a callback */
    tGAP_CONN_CALLBACK *p_conn_cb;      /* +0x20 the client's callback, called with a GAP_EVT_CONN_* */
    u8                  my_cfg[0x3C];   /* +0x24 the tL2CAP_CFG_INFO we ask L2CAP for (the game's is smaller than l2c_api.h's) */
} tGAP_CONN_VIEW;                       /* 0x60 */

void GAP_Init(void) {
    memset(lbl_803C3740, 0, 0x3AC);
    *(void **)(lbl_803C3740 + 0x20) = fn_800833E8;
    *(void **)(lbl_803C3740 + 0x24) = fn_800833F4;
    *(u8 *)(lbl_803C3740 + 0x28) = 5;
    fn_800826D4();
}

extern u8 lbl_803C3740[];
typedef struct {
    u8 inq[0x3C];
    u8 disc_comp[0x34];
    u8 disc_succ[0x28];
    u8 rem_name[1];
} GapTraceStrings;
extern void gap_connect_cfm(u32, s32), gap_config_ind(u16, void *), gap_config_cfm(u32, u16 *), gap_disconnect_ind(u16, BOOLEAN), gap_data_ind(u16, void *), gap_congestion_ind(u16, u16);
void gap_connect_ind(BD_ADDR addr, UINT16 cid, UINT16 psm, UINT8 status);
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
/* L2CAP's connect-indication callback (the GAP control block's +0x84): the peer
 * is connecting to a PSM GAP registered for one of its clients.  Hand the new
 * channel to the connection block that was waiting for it -- same PSM, and
 * either any address or exactly this one -- answer L2CAP in its name and start
 * negotiating configuration; a connection nobody waited for is dropped again.
 * The traces go through fn_8007093C/fn_80070954, the LogMsg_0/LogMsg_1 wrappers
 * around LogMsg, with the GAP trace code. */
void gap_connect_ind(BD_ADDR addr, UINT16 cid, UINT16 psm, UINT8 status) {
    extern u8 lbl_80559078[8]; /* "*******", the line the warning is printed between */
    tGAP_CONN_VIEW *first = (tGAP_CONN_VIEW *)(gap_cb + 0xAC);
    register UINT16 i = 0;
    register tGAP_CONN_VIEW *ccb = first;

    while (i < GAP_NUM_CONNECTIONS) {
        if (ccb->state == GAP_CONN_STATE_WF_SEC_CMP && ccb->psm == psm &&
            (ccb->wildcard == 0 || memcmp(addr, ccb->bd_addr, BD_ADDR_LEN) == 0))
            break;
        i++;
        ccb++;
    }
    if (i == GAP_NUM_CONNECTIONS) {
        if (gap_cb[0x28] >= BT_TRACE_LEVEL_WARNING) /* "*******" */
            fn_8007093C(TRACE_CTRL_GENERAL | TRACE_LAYER_GAP | TRACE_ORG_STACK | TRACE_TYPE_WARNING, lbl_80559078);
        if (gap_cb[0x28] >= BT_TRACE_LEVEL_WARNING) /* "WARNING: GAP Conn Indication for Unexpected Bd Addr...Disconnecting" */
            fn_8007093C(TRACE_CTRL_GENERAL | TRACE_LAYER_GAP | TRACE_ORG_STACK | TRACE_TYPE_WARNING, lbl_80317310);
        if (gap_cb[0x28] >= BT_TRACE_LEVEL_WARNING) /* "*******" */
            fn_8007093C(TRACE_CTRL_GENERAL | TRACE_LAYER_GAP | TRACE_ORG_STACK | TRACE_TYPE_WARNING, lbl_80559078);
        L2CA_DisconnectReq(cid);
        return;
    }
    ccb->state = GAP_CONN_STATE_WF_L2CA_CFG;
    memcpy(ccb->bd_addr, addr, BD_ADDR_LEN);
    ccb->cid = cid;
    L2CA_ConnectRsp(addr, status, cid, 0, 0); /* the client's handle, and a PSM of L2CAP's choosing */
    if (gap_cb[0x28] >= BT_TRACE_LEVEL_EVENT) /* "GAP_CONN - Rcvd L2CAP conn ind, CID: 0x%x" */
        fn_80070954(TRACE_CTRL_GENERAL | TRACE_LAYER_GAP | TRACE_ORG_STACK | TRACE_TYPE_EVENT, lbl_80317354, ccb->cid);
    L2CA_ConfigReq(cid, (tL2CAP_CFG_INFO *)&ccb->my_cfg);
}

void gap_connect_cfm(u32 cid, s32 result) {
    u8 *entry = lbl_803C3740 + 0xAC;
    u8 i;
    u16 psm;
    for (i = 0; i < 8; i++, entry += 0x60) {
        if (entry[0] != 0 && *(u16 *)(entry + 6) == cid)
            goto found;
    }
    entry = 0;
found:
    if (entry == 0)
        return;
    if (result == 0 && entry[0] == 2) {
        entry[0] = 3;
        L2CA_ConfigReq((u16)cid, (tL2CAP_CFG_INFO *)(entry + 0x24));
        return;
    }
    if (*(void **)(entry + 0x20) != 0)
        ((void (*)(u16, u16))*(void **)(entry + 0x20))(*(u16 *)(entry + 4), 0x101);
    psm = *(u16 *)(entry + 0x10);
    while (*(u32 *)(entry + 0x14) != 0)
        GKI_freebuf(GKI_dequeue((BUFFER_Q *)(entry + 0x14)));
    entry[0] = 0;
    {
        u8 *p = lbl_803C3740 + 0xAC;
        for (i = 0; i < 8; i++, p += 0x60) {
            if (p[0] != 0 && *(u16 *)(p + 0x10) == psm)
                return;
        }
    }
    L2CA_Deregister(psm);
}

void gap_config_ind(u16 cid, void *p_cfg) {
    u8 *conn = lbl_803C3740 + 0xAC;
    u32 outer = 2;
    u32 idx = 0;
    do {
        if (conn[0] != 0 && *(u16 *)(conn + 6) == cid)
            goto found;
        conn += 0x60; idx++;
        if (conn[0] != 0 && *(u16 *)(conn + 6) == cid)
            goto found;
        conn += 0x60; idx++;
        if (conn[0] != 0 && *(u16 *)(conn + 6) == cid)
            goto found;
        conn += 0x60; idx++;
        if (conn[0] != 0 && *(u16 *)(conn + 6) == cid)
            goto found;
        conn += 0x60; idx++;
    } while (--outer != 0);
    conn = NULL;
found:
    (void)idx;
    if (conn == NULL)
        return;
    if (((u8 *)p_cfg)[2] != 0) {
        u16 value = *(u16 *)((u8 *)p_cfg + 4);
        if (value > 0x69B)
            value = 0x69B;
        *(u16 *)(conn + 0x12) = value;
    } else {
        *(u16 *)(conn + 0x12) = 0;
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
    u8 *ccb = (u8 *)&lbl_803C3740 + 172;
    register u8 i = 0;
    u16 psm;
    while (i < 8) {
        if (ccb[0] != 0 && *(u16 *)(ccb + 6) == cid)
            break;
        i++;
        ccb += 96;
    }
    if (i == 8)
        ccb = 0;
    if (ccb == 0)
        return;
    if (*p_cfg == 0) {
        ccb[1] |= 4;
        if (ccb[1] & 2) {
            ccb[0] = 4;
            ((void (*)(u16, u16))*(u32 *)(ccb + 32))(*(u16 *)(ccb + 4), 256);
        }
        return;
    }
    ((void (*)(u16, u16))*(u32 *)(ccb + 32))(*(u16 *)(ccb + 4), 257);
    psm = *(u16 *)(ccb + 16);
    while (*(u32 *)(ccb + 20) != 0)
        GKI_freebuf(GKI_dequeue((BUFFER_Q *)(ccb + 20)));
    ccb[0] = 0;
    {
        u8 *scan = (u8 *)&lbl_803C3740 + 172;
        register u8 j = 0;
        while (j < 8) {
            if (scan[0] != 0 && *(u16 *)(scan + 16) == psm)
                return;
            if (scan[96] != 0 && *(u16 *)(scan + 112) == psm)
                return;
            if (scan[192] != 0 && *(u16 *)(scan + 208) == psm)
                return;
            if (scan[288] != 0 && *(u16 *)(scan + 304) == psm)
                return;
            j += 4;
            scan += 384;
        }
    }
    L2CA_Deregister(psm);
}

extern char lbl_80317380[];
void gap_disconnect_ind(u16 cid, BOOLEAN ack_needed)
{
    u8 *entry;
    u8 *p;
    u32 group;
    u32 slot;
    u32 i;
    u16 psm;

    if (lbl_803C3740[0x28] >= 4) {
        fn_80070954(0xE0003, lbl_80317380, cid);
    }

    entry = lbl_803C3740 + 0xAC;
    i = 0;
    for (group = 0; group < 2; group++) {
        for (slot = 0; slot < 4; slot++, entry += 0x60) {
            if (entry[0] == 0) goto next_slot;
            if (*(u16 *)(entry + 6) != cid) goto next_slot;
            goto found;
        next_slot:
            i++;
        }
    }
    if (i == 8) entry = NULL;
found:
    if (entry == NULL) return;

    if (ack_needed) L2CA_DisconnectRsp(cid);
    ((void (*)(u16, u16))*(void **)(entry + 0x20))(*(u16 *)(entry + 4), 0x101);
    psm = *(u16 *)(entry + 0x10);
    while (*(u32 *)(entry + 0x14) != 0) {
        GKI_freebuf(GKI_dequeue((BUFFER_Q *)(entry + 0x14)));
    }
    entry[0] = 0;

    p = lbl_803C3740 + 0xAC;
    i = 0;
    for (group = 0; group < 2; group++) {
        for (slot = 0; slot < 4; slot++, p += 0x60) {
            if (p[slot * 0x60] == 0) goto next_psm;
            if (*(u16 *)(p + slot * 0x60 + 0x10) != psm) goto next_psm;
            goto psm_found;
        next_psm:
            i++;
        }
    }
    if (i == 8) L2CA_Deregister(psm);
psm_found:
    ;
}

void gap_data_ind(u16 cid, void *p_buf) {
    u8 *conn = lbl_803C3740 + 0xAC;
    u8 i = 0;
    while (i < 8) {
        if (conn[0] != 0) {
            if (*(u16 *)(conn + 6) == cid)
                goto found;
        }
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
    u8 *p;
    u32 i;

    if (lbl_803C3740[0x28] >= 4) {
        fn_8007096C(0xE0003, lbl_803173A8, congest, cid);
    }
    p = lbl_803C3740 + 0xAC;
    i = 0;
    do {
        if (p[0] != 0 && *(u16 *)(p + 6) == cid) goto found;
        if ((p += 0x60)[0] != 0 && *(u16 *)(p + 6) == cid) goto found;
        if ((p += 0x60)[0] != 0 && *(u16 *)(p + 6) == cid) goto found;
        if ((p += 0x60)[0] != 0 && *(u16 *)(p + 6) == cid) goto found;
        p += 0x60;
        i++;
    } while (i < 2);
    return;

found:
    ((void (*)(u16, u16))*(void **)(p + 0x20))(
        *(u16 *)(p + 4), (u16)(0x104 + ((-(s32)congest | (s32)congest) >> 31)));
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

extern char lbl_80317558[];
extern char lbl_8031759C[];
/* GAP find-address-by-name callback: processes remote name read results during inquiry, updates the output record/status, invokes the completion callback, and clears the in-progress state. */
void gap_find_addr_name_cb(void *param) {
    u8 *cb = lbl_803C3740;
    u16 *result = (u16 *)(cb + 0x34);
    u8 *evt = (u8 *)param;
    void *inqRec;
    u16 status;

    if (cb[0x7E] == 0) return;
    if (*(u16 *)evt == 0) {
        if (cb[0x28] >= 4)
            ((void (*)(u32, void *, u16, void *))fn_8007096C)(0xE0003, lbl_80317558, *(u16 *)evt, evt + 4);
        if (strncmp((char *)(result + 4), (char *)(evt + 4), strlen((char *)(result + 4))) == 0) {
            memcpy((u8 *)result + 2, (u8 *)*(void **)(cb + 0x30) + 2, 6);
            *result = 0;
        } else {
            inqRec = BTM_InqDbNext(*(void **)(cb + 0x30));
            *(void **)(cb + 0x30) = inqRec;
            if (inqRec != 0) {
                if ((u8)BTM_ReadRemoteDeviceName((u8 *)inqRec + 2, gap_find_addr_name_cb) == 1)
                    return;
                switch (*(u16 *)evt & 0xFF) {
                case 0: status = 0; break;
                case 1: status = 0x10B; break;
                case 2: status = 0x103; break;
                case 4:
                case 5: status = 0x109; break;
                case 6: status = 0x10C; break;
                case 7: status = 0x10D; break;
                case 8: status = 0x115; break;
                default: status = 0x114; break;
                }
                *result = status;
            } else {
                *result = 0x102;
            }
        }
    } else {
        if (cb[0x28] >= 4)
            ((void (*)(u32, void *))fn_80070954)(0xE0003, lbl_8031759C);
        switch (*(u16 *)evt & 0xFF) {
        case 0: status = 0; break;
        case 1: status = 0x10B; break;
        case 2: status = 0x103; break;
        case 4:
        case 5: status = 0x109; break;
        case 6: status = 0x10C; break;
        case 7: status = 0x10D; break;
        case 8: status = 0x115; break;
        default: status = 0x114; break;
        }
        *result = status;
    }
    if (*(void (**)(u32, u16 *))(cb + 0x2C) != 0)
        (*(void (**)(u32, u16 *))(cb + 0x2C))(5, result);
    cb[0x7E] = 0;
    *(void **)(cb + 0x2C) = 0;
}

extern char lbl_80317620[];
extern void gap_find_addr_name_cb(void *);
/* GAP_FindAddr_byname's inquiry-complete callback.  The inquiry the request
 * started is over, so ask the first device in the inquiry database for its
 * name -- gap_find_addr_name_cb compares it and walks on with BTM_InqDbNext --
 * or report why that cannot be done; then hand the result to the user's
 * callback and release the request.  param is BTM's inquiry result: byte 0 is
 * its tBTM_STATUS, byte 1 how many devices answered. */
void gap_find_addr_inq_cb(u8 *param) {
    u8 *cb = lbl_803C3740;
    u16 *result = gap_find_addr_result(cb);
    void *inqRec;
    u16 status;

    if (gap_find_addr_busy(cb) == 0) return;
    if (cb[0x28] >= BT_TRACE_LEVEL_EVENT) /* "GAP: FindAddrByName Inq Cmpl Evt (Status 0x%04x, Result(s) %d" */
        fn_8007096C(0xE0003, &lbl_80317620, param[0], param[1]);
    if (param[0] == BTM_SUCCESS) {
        *result = GAP_NO_DATA_AVAIL;
        inqRec = BTM_InqDbFirst();
        gap_find_addr_inq_rec(cb) = inqRec;
        if (inqRec != 0) {
            /* +2 is the record's BD_ADDR; BTM_CMD_STARTED means the name
             * callback will report the outcome instead of what follows. */
            if ((u8)BTM_ReadRemoteDeviceName((u8 *)inqRec + 2, gap_find_addr_name_cb) == BTM_CMD_STARTED)
                return;
            /* the stack's BTM -> GAP status conversion, as in gap_convert_btm_status */
            switch (param[0]) {
            case BTM_SUCCESS: status = 0; break;
            case BTM_CMD_STARTED: status = GAP_CMD_INITIATED; break;
            case BTM_BUSY: status = GAP_ERR_BUSY; break;
            case BTM_NO_RESOURCES: status = GAP_ERR_ILL_PARM; break;
            case BTM_MODE_UNSUPPORTED: status = GAP_DEVICE_NOT_UP; break;
            case BTM_ILLEGAL_VALUE: status = GAP_BAD_BD_ADDR; break;
            case BTM_WRONG_MODE: status = GAP_ERR_TIMEOUT; break;
            case BTM_UNKNOWN_ADDR:
            case BTM_DEVICE_TIMEOUT:
            default: status = GAP_ERR_PROCESSING; break;
            }
            *result = status;
        } else {
            *result = GAP_EOINQDB; /* nothing in the inquiry database */
        }
    } else {
        switch (param[0]) {
        case BTM_SUCCESS: status = 0; break;
        case BTM_CMD_STARTED: status = GAP_CMD_INITIATED; break;
        case BTM_BUSY: status = GAP_ERR_BUSY; break;
        case BTM_NO_RESOURCES: status = GAP_ERR_ILL_PARM; break;
        case BTM_MODE_UNSUPPORTED: status = GAP_DEVICE_NOT_UP; break;
        case BTM_ILLEGAL_VALUE: status = GAP_BAD_BD_ADDR; break;
        case BTM_WRONG_MODE: status = GAP_ERR_TIMEOUT; break;
        case BTM_UNKNOWN_ADDR:
        case BTM_DEVICE_TIMEOUT:
        default: status = GAP_ERR_PROCESSING; break;
        }
        *result = status;
    }
    if (gap_find_addr_cback(cb) != 0)
        gap_find_addr_cback(cb)(GAP_EVT_FIND_ADDR_COMPLETE, result);
    gap_find_addr_busy(cb) = 0;
    gap_find_addr_cback(cb) = 0;
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

/* Builds and sends an HCI Inquiry command (OGF 0x01, OCF 0x0001) with the given LAP, duration and response limit. */
BOOLEAN btsnd_hcic_inquiry(const LAP inq_lap, UINT8 duration, UINT8 response_cnt) {
    u8 *cmd_buf;
    u8 lap2;
    u8 lap1;
    if ((cmd_buf = GKI_getpoolbuf(2)) == NULL) return FALSE;
    *(u16*)&cmd_buf[2] = 8;
    *(u16*)&cmd_buf[4] = 0;
    cmd_buf[8] = 1;
    cmd_buf[9] = 4;
    cmd_buf[10] = 5;
    lap2 = inq_lap[2];
    cmd_buf[11] = lap2;
    lap1 = inq_lap[1];
    cmd_buf[12] = lap1;
    cmd_buf[13] = inq_lap[0];
    cmd_buf[14] = duration;
    cmd_buf[15] = response_cnt;
    btu_hcif_send_cmd(cmd_buf);
    return TRUE;
}

u8 btsnd_hcic_inq_cancel(void) {
    u8 *p = (u8 *)GKI_getpoolbuf(2);
    if (p == 0)
        return 0;
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = 0;
    p[8] = 2;
    p[9] = 4;
    p[10] = 0;
    btu_hcif_send_cmd(p);
    return 1;
}

/* Build and send HCI Periodic_Inquiry_Mode command with the given inquiry parameters. */
BOOLEAN btsnd_hcic_per_inq_mode(UINT16 max_period, UINT16 min_period, const LAP inq_lap, UINT8 duration, UINT8 response_cnt) {
    u8 *cmd = (u8 *)GKI_getpoolbuf(2);
    if (cmd == NULL) return FALSE;
    *(u16 *)(cmd + 2) = 0xC;
    *(u16 *)(cmd + 4) = 0;
    cmd[8] = 3; cmd[9] = 4; cmd[10] = 9;
    cmd[11] = max_period; cmd[12] = max_period >> 8;
    cmd[13] = min_period; cmd[14] = min_period >> 8;
    cmd[15] = inq_lap[2]; cmd[16] = inq_lap[1]; cmd[17] = inq_lap[0];
    cmd[18] = duration; cmd[19] = response_cnt;
    btu_hcif_send_cmd(cmd);
    return TRUE;
}

BOOLEAN btsnd_hcic_create_conn(BD_ADDR dest, UINT16 packet_types, UINT8 page_scan_rep_mode, UINT8 page_scan_mode, UINT16 clock_offset, UINT8 allow_switch) {
    /* Builds and sends an HCI Create_Connection command buffer for the destination device. */
    u8 *cmdBuffer = (u8 *)GKI_getpoolbuf(2);
    if (cmdBuffer == NULL) return FALSE;
    *(u16 *)(cmdBuffer + 2) = 0x10;
    *(u16 *)(cmdBuffer + 4) = 0;
    cmdBuffer[8] = 5;
    cmdBuffer[9] = 4;
    cmdBuffer[10] = 0xD;
    cmdBuffer[11] = dest[5];
    cmdBuffer[12] = dest[4];
    cmdBuffer[13] = dest[3];
    cmdBuffer[14] = dest[2];
    cmdBuffer[15] = dest[1];
    cmdBuffer[16] = dest[0];
    cmdBuffer[17] = packet_types;
    cmdBuffer[18] = packet_types >> 8;
    cmdBuffer[19] = page_scan_rep_mode;
    cmdBuffer[20] = page_scan_mode;
    cmdBuffer[21] = clock_offset;
    cmdBuffer[22] = clock_offset >> 8;
    cmdBuffer[23] = allow_switch;
    btu_hcif_send_cmd(cmdBuffer);
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

/* Send an HCI Link Key Request Reply command for a device address and link key. */
BOOLEAN btsnd_hcic_link_key_req_reply(BD_ADDR bd_addr, LINK_KEY link_key) {
    BT_HDR *cmdBuf;
    UINT8 *payload;

    if ((cmdBuf = (BT_HDR *)GKI_getpoolbuf(2)) == NULL)
        return FALSE;
    payload = (UINT8 *)(cmdBuf + 1);
    cmdBuf->len = 0x19;
    cmdBuf->offset = 0;
    UINT16_TO_STREAM(payload, HCI_LINK_KEY_REQUEST_REPLY);
    UINT8_TO_STREAM(payload, HCIC_PARAM_SIZE_LINK_KEY_REQ_REPLY);
    BDADDR_TO_STREAM(payload, bd_addr);
    ARRAY16_TO_STREAM(payload, link_key);
    btu_hcif_send_cmd(cmdBuf);
    return TRUE;
}

/* Build and send an HCI Link_Key_Request_Negative_Reply command for bd_addr:
   answer a Link_Key_Request event with "no stored link key for this device",
   so the controller authenticates with the combination (PIN) key instead.
   Returns FALSE when the HCI command pool has no buffer left. */
BOOLEAN btsnd_hcic_link_key_neg_reply(BD_ADDR bd_addr) {
    BT_HDR *p;
    UINT8 *pp;

    if ((p = HCI_GET_CMD_BUF(HCIC_PARAM_SIZE_LINK_KEY_NEG_REPLY)) == NULL)
        return FALSE;

    pp = (UINT8 *)(p + 1);

    p->len    = HCIC_PREAMBLE_SIZE + HCIC_PARAM_SIZE_LINK_KEY_NEG_REPLY;
    p->offset = 0;

    UINT16_TO_STREAM (pp, HCI_LINK_KEY_REQUEST_NEG_REPLY);
    UINT8_TO_STREAM  (pp, HCIC_PARAM_SIZE_LINK_KEY_NEG_REPLY);

    BDADDR_TO_STREAM (pp, bd_addr);

    btu_hcif_send_cmd(p);
    return TRUE;
}

BOOLEAN btsnd_hcic_pin_code_req_reply(BD_ADDR bd_addr, UINT8 pin_code_len, PIN_CODE pin_code) {
    BT_HDR *p_buf;
    UINT8 *p;
    UINT8 *src;
    UINT8 *dst;
    s32 i;

    p_buf = (BT_HDR *)GKI_getpoolbuf(2);
    if (p_buf == NULL) return FALSE;
    p = (UINT8 *)p_buf;
    i = 0;
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
    for (; i < pin_code_len; i++)
        *dst++ = *src++;
    while (i < 16) {
        *dst++ = 0;
        i++;
    }
    btu_hcif_send_cmd(p_buf);
    return TRUE;
}

/* Build and send an HCI PIN_Code_Request_Negative_Reply command for bd_addr: tell
   the controller to reject the remote device's PIN code request. NOTE: the name is
   a misnomer left over from the draft - the opcode streamed here is
   HCI_PIN_CODE_REQUEST_NEG_REPLY (0x040E), not the Link_Key_Request negative reply
   (0x040C, which is btsnd_hcic_link_key_neg_reply above). Returns FALSE when the
   HCI command pool has no buffer left. */
BOOL btsnd_hcic_link_key_neg_reply_800840C8(BD_ADDR bd_addr) {
    BT_HDR *p;
    UINT8 *pp;

    if ((p = HCI_GET_CMD_BUF(HCIC_PARAM_SIZE_PIN_CODE_NEG_REPLY)) == NULL)
        return FALSE;

    pp = (UINT8 *)(p + 1);

    p->len    = HCIC_PREAMBLE_SIZE + HCIC_PARAM_SIZE_PIN_CODE_NEG_REPLY;
    p->offset = 0;

    UINT16_TO_STREAM (pp, HCI_PIN_CODE_REQUEST_NEG_REPLY);
    UINT8_TO_STREAM  (pp, HCIC_PARAM_SIZE_PIN_CODE_NEG_REPLY);

    BDADDR_TO_STREAM (pp, bd_addr);

    btu_hcif_send_cmd(p);
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

/* Build and send an HCI Remote_Name_Request command: ask the remote device
   bd_addr for its friendly name. The stack pages it with the given page scan
   repetition mode / page scan mode and clock_offset (clock offset of the
   piconet to join, bit 15 selects an R2 request). Returns FALSE when the HCI
   command pool has no buffer left. */
BOOLEAN btsnd_hcic_rmt_name_req(BD_ADDR bd_addr, UINT8 page_scan_rep_mode,
                                UINT8 page_scan_mode, UINT16 clock_offset) {
    BT_HDR *p;
    UINT8 *pp;

    if ((p = HCI_GET_CMD_BUF(HCIC_PARAM_SIZE_RMT_NAME_REQ)) == NULL)
        return FALSE;

    pp = (UINT8 *)(p + 1);

    p->len    = HCIC_PREAMBLE_SIZE + HCIC_PARAM_SIZE_RMT_NAME_REQ;
    p->offset = 0;

    UINT16_TO_STREAM (pp, HCI_RMT_NAME_REQUEST);
    UINT8_TO_STREAM  (pp, HCIC_PARAM_SIZE_RMT_NAME_REQ);

    BDADDR_TO_STREAM (pp, bd_addr);
    UINT8_TO_STREAM  (pp, page_scan_rep_mode);
    UINT8_TO_STREAM  (pp, page_scan_mode);
    UINT16_TO_STREAM (pp, clock_offset);

    btu_hcif_send_cmd(p);
    return TRUE;
}

/* Build and send an HCI Remote_Name_Request_Cancel command for bd_addr: drop the
   pending Remote_Name_Request, which is all BTM_CancelRemoteDeviceName() wants.
   NOTE: the name is a misnomer left over from the draft - the opcode streamed
   here is HCI_RMT_NAME_REQUEST_CANCEL (0x041A), not the Link_Key_Request
   negative reply (0x040C, which is btsnd_hcic_link_key_neg_reply above).
   Returns FALSE when the HCI command pool has no buffer left. */
s32 btsnd_hcic_link_key_neg_reply_800843D8(BD_ADDR bd_addr) {
    BT_HDR *p;
    UINT8 *pp;

    if ((p = HCI_GET_CMD_BUF(HCIC_PARAM_SIZE_RMT_NAME_REQ_CANCEL)) == NULL)
        return FALSE;

    pp = (UINT8 *)(p + 1);

    p->len    = HCIC_PREAMBLE_SIZE + HCIC_PARAM_SIZE_RMT_NAME_REQ_CANCEL;
    p->offset = 0;

    UINT16_TO_STREAM (pp, HCI_RMT_NAME_REQUEST_CANCEL);
    UINT8_TO_STREAM  (pp, HCIC_PARAM_SIZE_RMT_NAME_REQ_CANCEL);

    BDADDR_TO_STREAM (pp, bd_addr);

    btu_hcif_send_cmd(p);
    return TRUE;
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
    /* Build and send HCI Setup_Synchronous_Connection (0x0428): allocate a cmd
       buffer, fill the header/fields into the raw packet bytes, dispatch it, and
       report success. */
    UINT8 *cmd = (UINT8 *)GKI_getpoolbuf(2);

    if (cmd == NULL) {
        return FALSE;
    }
    *(UINT16 *)(cmd + 2) = 0x14;
    *(UINT16 *)(cmd + 4) = 0;
    cmd[8] = 0x28;
    cmd[9] = 4;
    cmd[10] = 0x11;
    cmd[11] = handle;
    cmd[12] = handle >> 8;
    cmd[13] = tx_bandwidth;
    cmd[14] = tx_bandwidth >> 8;
    cmd[15] = tx_bandwidth >> 16;
    cmd[16] = tx_bandwidth >> 24;
    cmd[17] = rx_bandwidth;
    cmd[18] = rx_bandwidth >> 8;
    cmd[19] = rx_bandwidth >> 16;
    cmd[20] = rx_bandwidth >> 24;
    cmd[21] = max_latency;
    cmd[22] = max_latency >> 8;
    cmd[23] = voice_setting;
    cmd[24] = voice_setting >> 8;
    cmd[25] = retrans_effort;
    cmd[26] = packet_types;
    cmd[27] = packet_types >> 8;
    btu_hcif_send_cmd(cmd);
    return TRUE;
}

void btsnd_hcic_accept_esco_conn(BT_HDR *p, BD_ADDR bd_addr, UINT32 tx_bw,
                                     UINT32 rx_bw, UINT16 max_latency,
                                     UINT16 content_fmt, UINT8 retrans_effort,
                                     UINT16 packet_types) {
    /* Build and send HCI Accept_Synchronous_Connection_Request command into the provided buffer. */
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

/* Build and send an HCI Sniff_Mode command for the given connection handle. */
BOOLEAN btsnd_hcic_sniff_mode(BT_HDR *p_buf, s16 handle, s16 max_sniff_period, s16 min_sniff_period, s16 sniff_attempt, UINT16 sniff_timeout) {
    UINT8 *p_bytes;

    if (p_buf == NULL) {
        p_buf = GKI_getpoolbuf(2);
        if (p_buf == NULL) {
            return FALSE;
        }
    }

    p_bytes = (UINT8 *)p_buf;
    p_buf->len = 0xD;
    p_buf->offset = 0;
    p_bytes[8] = 3;
    p_bytes[9] = 8;
    p_bytes[10] = 0xA;
    p_bytes[11] = handle;
    p_bytes[12] = handle >> 8;
    p_bytes[13] = max_sniff_period;
    p_bytes[14] = max_sniff_period >> 8;
    p_bytes[15] = min_sniff_period;
    p_bytes[16] = min_sniff_period >> 8;
    p_bytes[17] = sniff_attempt;
    p_bytes[18] = sniff_attempt >> 8;
    p_bytes[19] = sniff_timeout;
    p_bytes[20] = sniff_timeout >> 8;
    btu_hcif_send_cmd(p_buf);
    return TRUE;
}

s32 btsnd_hcic_exit_sniff_mode(void *arg0, u16 arg1) {
    u8 *p = (u8 *)arg0;
    if (p == NULL) {
        p = GKI_getpoolbuf(2);
        if (p == NULL)
            return 0;
    }
    *(u16 *)(p + 2) = 5;
    *(u16 *)(p + 4) = 0;
    p[8] = 4;
    p[9] = 8;
    p[10] = 2;
    p[11] = arg1;
    p[12] = arg1 >> 8;
    btu_hcif_send_cmd(p);
    return 1;
}

/* Build and send HCI Hold_Mode command (OGF 0x08, OCF 0x0001) for handle with max/min intervals; allocates pool buffer if needed. */
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

// Build and send an HCI Switch Role command for the given Bluetooth device address and role.
BOOLEAN btsnd_hcic_switch_role(BD_ADDR bd_addr, UINT8 role) {
    u8 *cmdBuf = GKI_getpoolbuf(2);
    if (cmdBuf == NULL) return FALSE;
    *(u16 *)(cmdBuf + 2) = 10;
    *(u16 *)(cmdBuf + 4) = 0;
    cmdBuf[8] = 0xB;
    cmdBuf[9] = 8;
    cmdBuf[10] = 7;
    cmdBuf[11] = bd_addr[5];
    cmdBuf[12] = bd_addr[4];
    cmdBuf[13] = bd_addr[3];
    cmdBuf[14] = bd_addr[2];
    cmdBuf[15] = bd_addr[1];
    cmdBuf[16] = bd_addr[0];
    cmdBuf[17] = role;
    btu_hcif_send_cmd(cmdBuf);
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

BOOLEAN btsnd_hcic_set_event_filter(void *p_buf, UINT8 filt_type, UINT8 cond_type, UINT8 *p_cond, UINT8 cond_len) {
    UINT8 *raw = (UINT8 *)p_buf;
    BT_HDR *p = (BT_HDR *)p_buf;
    UINT8 *src = p_cond;
    UINT8 *dst;
    int len = cond_len;
    int ijk;
    p->offset = 0;
    raw[8] = 5;
    raw[9] = 0xC;
    if (filt_type != 0) {
        p->len = cond_len + 5;
        raw[0xA] = cond_len + 2;
        raw[0xB] = filt_type;
        raw[0xC] = cond_type;
        dst = raw + 0xD;
        if (cond_type == 1) {
            dst[0] = src[2];
            len = (UINT8)(len - 6);
            src += 6;
            dst[1] = p_cond[1];
            dst[2] = p_cond[0];
            dst[3] = p_cond[5];
            dst[4] = p_cond[4];
            dst[5] = p_cond[3];
            dst += 6;
        } else if (cond_type == 2) {
            dst[0] = src[5];
            len = (UINT8)(len - 6);
            src += 6;
            dst[1] = p_cond[4];
            dst[2] = p_cond[3];
            dst[3] = p_cond[2];
            dst[4] = p_cond[1];
            dst[5] = p_cond[0];
            dst += 6;
        }
        if (len != 0) {
            for (ijk = 0; ijk < len; ijk++) {
                *dst++ = src[ijk];
            }
        }
    } else {
        p->len = 4;
        raw[0xA] = 1;
        raw[0xB] = filt_type;
    }
    btu_hcif_send_cmd(p_buf);
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

/* Builds and sends an HCI Write_Stored_Link_Key command for up to 11 BD_ADDR/link-key pairs. */
BOOLEAN btsnd_hcic_write_stored_key(void *buffer, UINT8 num_keys, BD_ADDR *bd_addr, LINK_KEY *link_key) {
    u32 len;
    u16 length;
    u8 *pp;
    int i;

    *(u16 *)((u8 *)buffer + 4) = 0;
    len = num_keys * 0x16;
    len += 4;
    length = (u16)len;
    *(u16 *)((u8 *)buffer + 2) = (u16)len;
    ((u8 *)buffer)[8] = 0x11;
    ((u8 *)buffer)[9] = 0x0C;
    ((u8 *)buffer)[0xA] = (u8)(length - 3);
    if (num_keys > 0xB)
        num_keys = 0xB;
    ((u8 *)buffer)[0xB] = num_keys;
    pp = (u8 *)buffer + 0xC;

    for (i = 0; i < num_keys; i++) {
        BDADDR_TO_STREAM(pp, bd_addr[i]);
        ARRAY16_TO_STREAM(pp, link_key[i]);
    }
    btu_hcif_send_cmd(buffer);
}

/* Builds and sends an HCI Switch Role command for the given remote address and role. */
s32 btsnd_hcic_switch_role_8008515C(BD_ADDR bdAddr, UINT8 role) {
    u8 *cmdBuf = GKI_getpoolbuf(2);
    if (cmdBuf == NULL) return 0;
    *(u16 *)(cmdBuf + 2) = 10;
    *(u16 *)(cmdBuf + 4) = 0;
    cmdBuf[8] = 0x12; cmdBuf[9] = 0xC; cmdBuf[10] = 7;
    cmdBuf[11] = bdAddr[5]; cmdBuf[12] = bdAddr[4]; cmdBuf[13] = bdAddr[3];
    cmdBuf[14] = bdAddr[2]; cmdBuf[15] = bdAddr[1]; cmdBuf[16] = bdAddr[0];
    cmdBuf[17] = role;
    btu_hcif_send_cmd(cmdBuf);
    return 1;
}

/* Send HCI Change Local Name command with the provided device name */
BOOLEAN btsnd_hcic_change_name(void *p_buf, BD_NAME name) {
    BT_HDR *p = (BT_HDR *)p_buf;
    UINT8 *pp;
    UINT16 len = strlen((char *)name) + 1;
    pp = (UINT8 *)(p + 1);
    p->len = 0xFB;
    p->offset = 0;
    UINT16_TO_STREAM(pp, HCI_CHANGE_LOCAL_NAME);
    UINT8_TO_STREAM(pp, HCIC_PARAM_SIZE_CHANGE_NAME);
    ARRAY_TO_STREAM(pp, name, len);
    btu_hcif_send_cmd(p);
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
    arg0[9] = 0x0C;
    arg0[10] = 1;
    arg0[11] = arg1;
    btu_hcif_send_cmd(arg0);
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

/* Build and send the HCI Set_Host_Buffer_Size command with the given ACL/SCO sizes and counts. */
BOOLEAN btsnd_hcic_set_host_buf_size(UINT16 acl_len, UINT8 sco_len, UINT16 acl_num, UINT16 sco_num) {
    BT_HDR *buf = GKI_getpoolbuf(2);
    u8 *cmd;
    if (buf == NULL) return FALSE;
    buf->len = 10;
    buf->offset = 0;
    cmd = (u8 *)(buf + 1);
    cmd[0] = 0x33; cmd[1] = 0xC; cmd[2] = 7;
    cmd[3] = acl_len; cmd[4] = acl_len >> 8;
    cmd[5] = sco_len;
    cmd[6] = acl_num; cmd[7] = acl_num >> 8;
    cmd[8] = sco_num; cmd[9] = sco_num >> 8;
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

void btsnd_hcic_write_cur_iac_lap(u8 *p_buf, u8 num_cur_iac, u8 *cur_iac_lap) {
    u8 *p = p_buf + 12;
    u8 *q = cur_iac_lap;
    *(u16 *)(p_buf + 2) = num_cur_iac * 3 + 4;
    *(u16 *)(p_buf + 4) = 0;
    p_buf[8] = 0x3A;
    p_buf[9] = 0x0C;
    p_buf[10] = num_cur_iac * 3 + 1;
    p_buf[11] = num_cur_iac;
    while (num_cur_iac-- != 0) {
        p[0] = q[2];
        p[1] = q[1];
        p[2] = q[0];
        p += 3;
        q += 3;
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
    if (p == NULL) return 0;
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = 0;
    p[8] = 3;
    p[9] = 0x10;
    p[10] = 0;
    btu_hcif_send_cmd(p);
    return 1;
}

void fn_80085828(void *arg0) {
    ((u16 *)((u8 *)arg0 + 2))[0] = 3;
    ((u16 *)((u8 *)arg0 + 4))[0] = 0;
    ((u8 *)arg0)[8] = 5;
    ((u8 *)arg0)[9] = 0x10;
    ((u8 *)arg0)[10] = 0;
    btu_hcif_send_cmd(arg0);
}

s32 btsnd_hcic_inq_cancel_80085850(void) {
    u8 *p = GKI_getpoolbuf(2);
    if (p == 0) return 0;
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = 0;
    p[8] = 9; p[9] = 0x10; p[10] = 0;
    btu_hcif_send_cmd(p);
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

/* .rodata image of the default AFH channel map: all 79 Bluetooth channels
   (0-78) enabled. A set bit means the channel is in use, so disabling a
   channel clears its bit; the compiler pools the local initialiser here. */
extern u8 lbl_802EEC08[];
typedef struct { u8 channels[HCI_AFH_CHANNEL_MAP_LEN]; } tAFH_CHANNEL_MAP;

/* Clears the bits of the channels in [first_disabled, last_disabled] in the
   default AFH map (all channels enabled to start with), then sends
   HCI_Set_AFH_Channel_Classification with the resulting map. */
BOOLEAN btsnd_hcic_set_afh_channels(u8 first_disabled, u8 last_disabled) {
    tAFH_CHANNEL_MAP map;
    u8 *p;
    int i;

    /* Copy the all-channels-enabled map out of the rodata pool. */
    map = *(tAFH_CHANNEL_MAP *)lbl_802EEC08;

    p = (u8 *)GKI_getpoolbuf(2);
    if (p == NULL) return FALSE;

    *(u16 *)(p + 2) = HCIC_PREAMBLE_SIZE + HCIC_PARAM_SIZE_SET_AFH_CHANNELS;
    *(u16 *)(p + 4) = 0;
    p[8] = (u8)HCI_SET_AFH_CHANNELS;
    p[9] = (u8)(HCI_SET_AFH_CHANNELS >> 8);
    p[10] = HCIC_PARAM_SIZE_SET_AFH_CHANNELS;

    if (first_disabled <= last_disabled && last_disabled <= 78) {
        for (i = first_disabled; i <= last_disabled; i++) map.channels[i / 8] &= ~(1 << (i % 8));
    }
    for (i = 0; i < HCI_AFH_CHANNEL_MAP_LEN; i++) p[11 + i] = map.channels[i];

    btu_hcif_send_cmd(p);
    return TRUE;
}

/* Builds an HCI vendor-specific command in a GKI buffer the caller allocated
   (room for BT_HDR + 3-byte preamble + len parameters) and queues it for the
   HCI task: the opcode is OR'd with the vendor-specific OGF, written little-
   endian at the start of the payload, followed by the parameter length and the
   parameters themselves. This build keeps the command-complete callback in the
   BTM control block instead of in the buffer, so p_cmd_cplt_cback is unused. */
void btsnd_hcic_vendor_spec_cmd(void *buffer, u16 opcode, u8 len, u8 *p_data, void *p_cmd_cplt_cback) {
    BT_HDR *p_hdr = (BT_HDR *)buffer;
    u8 *p = (u8 *)buffer;
    u8 *pp;
    u16 cmd = HCI_GRP_VENDOR_SPECIFIC | opcode;
    register int i;

    p_hdr->len = HCIC_PREAMBLE_SIZE + len;
    pp = p + BT_HDR_SIZE + HCIC_PREAMBLE_SIZE;
    p_hdr->offset = 0;
    p[BT_HDR_SIZE] = (u8)cmd;
    p[BT_HDR_SIZE + 1] = (u8)(cmd >> 8);
    p[BT_HDR_SIZE + 2] = len;
    for (i = 0; i < len; i++) /* ARRAY_TO_STREAM(pp, p_data, len) */
        *pp++ = p_data[i];
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
/* Initiate an outgoing HID device connection: trace start, reset connection IDs/state,
   request an L2CAP connection on the HID control PSM, and return success or failure. */
s32 hidd_conn_initiate(void) {
    u16 l2capCid;
    u8 *devCb = lbl_803C3AF0;

    if (devCb[0x141] >= 4) {
        fn_8007093C(0x1E0003, lbl_803176D0);
    }
    *(u16 *)(devCb + 0x14) = 0;
    *(s16 *)(devCb + 0x16) = 0;
    devCb[0x11] = 1;
    l2capCid = L2CA_ConnectReq(0x11, lbl_803C3AF0);
    *(u16 *)(devCb + 0x14) = l2capCid;
    if (l2capCid == 0) {
        if (lbl_803C3AF0[0x141] >= 2) {
            fn_8007093C(0x1E0001, lbl_803176E8);
        }
        return 0xE;
    }
    devCb[0x10] = 1;
    return 0;
}

void hidd_proc_repage_timeout(void)
{
    /* HID device repage/connect timer callback: count the repage attempt, retry
     * connection initiation (re-arming the timer while retries remain), or report
     * timeout/success to the host callback. */
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

BOOLEAN hidd_pm_set_now(void *arg0) {
    u8 mode = 0;
    tBTM_PM_PWR_MD spC = {0};
    u8 status = 0;
    u8 state_mode; /* early busy check leaves mode 0 */
    if (lbl_803C3AF0[0x6E] == 0) {
        state_mode = lbl_803C3AF0[0x6A];
        mode = ((u8 *)arg0)[8];
        if (mode == state_mode && mode != 0 && *(u16 *)(lbl_803C3AF0 + 0x6C) >= *(u16 *)((u8 *)arg0 + 2) && *(u16 *)(lbl_803C3AF0 + 0x6C) <= *(u16 *)arg0) {
            lbl_803C3AF0[0x78] = 0xFF;
            return TRUE;
        }
    }
    switch (mode) {
    case 0:
        if (state_mode == 2) {
            status = BTM_SetPowerMode(0x80, lbl_803C3AF0, &spC);
            lbl_803C3AF0[0x6E] = 1;
        } else if (state_mode == 3) {
            status = BTM_SetPowerMode(0x80, lbl_803C3AF0, (void *)&spC);
            lbl_803C3AF0[0x6E] = 1;
        }
        break;
    case 2:
        if (state_mode != 0) {
            hidd_pm_set_now((void *)&spC);
        } else {
            status = BTM_SetPowerMode(0x80, lbl_803C3AF0, arg0);
            lbl_803C3AF0[0x6E] = 1;
        }
        break;
    case 3:
        if (state_mode != 0) {
            hidd_pm_set_now((void *)&spC);
        } else {
            status = BTM_SetPowerMode(0x80, lbl_803C3AF0, arg0);
            lbl_803C3AF0[0x6E] = 1;
        }
        break;
    }
    if (status <= 1)
        return TRUE;
    status += 0x37;
    if (*(void **)(lbl_803C3AF0 + 0xC4) != NULL)
        ((void (*)(u8, u8, void *))*(void **)(lbl_803C3AF0 + 0xC4))(4, lbl_803C3AF0[0x6F], &status);
    return FALSE;
}

typedef void (*hidd_pm_callback)(u32, u8, void *);
void hidd_pm_proc_mode_change(s32 arg0, u8 arg1, s32 arg2) {
    /* HID device power-mode change callback: on error notifies the host callback (event 4);
       on success updates mode/interval, reconciles a pending request (0x78) or on idle copies
       the active power-mode params and arms a 0x3C-tick timer to fn_80086468, then notifies
       the host callback (event 3) with the new interval. */
    u8 sp8;
    u16 spA;
    u32 arg2cmp;
    hidd_pm_callback callback;
    sp8 = (u8)arg0;
    spA = (u16)arg2;
    if (lbl_803C3AF0[0x140] == 0) return;
    lbl_803C3AF0[0x6E] = 0;
    if ((u8)arg0 != 0) {
        callback = *(hidd_pm_callback *)(lbl_803C3AF0 + 0xC4);
        if (callback != 0) callback(4, lbl_803C3AF0[0x6F], &sp8);
        return;
    }
    arg2cmp = (u16)arg2;
    lbl_803C3AF0[0x6A] = arg1;
    *(u16 *)(lbl_803C3AF0 + 0x6C) = (u16)arg2;
    if (lbl_803C3AF0[0x78] != 0xFF) {
        if (lbl_803C3AF0[0x78] != arg1 ||
            (lbl_803C3AF0[0x78] != 0 &&
             (arg2cmp < *(u16 *)(lbl_803C3AF0 + 0x72) ||
              arg2cmp > *(u16 *)(lbl_803C3AF0 + 0x70)))) {
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

void fn_80086468(void *arg) {
    memcpy(lbl_803C3AF0 + 0x70, lbl_803C3AF0 + 0x56, 0xA);
    hidd_pm_set_now(lbl_803C3AF0 + 0x56);
    lbl_803C3AF0[0x6F] = 1;
}

s32 HID_HostGetSDPRecord(void *addr, void *p_db, u32 db_len, void *sdp_cback) {
    /* Start SDP discovery for a HID (Human Interface Device, UUID 0x1124) service
     * record at addr, storing the DB/callback in the HID host control block and
     * marking SDP busy; returns 0 on success, 0x10 if busy, or 3 on request failure. */
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

/* fn_80095C64 is the stack's SDP_FindAttributeInRec(). */
void *fn_80095C64(void **head, u32 attr);

/* HID host SDP result codes and attribute mask bits, from
   stack/include/hidh_api.h - that header can't be included here, its prototypes
   clash with this unit's own declarations. */
#define HID_SDP_NO_SERV_UUID      (SDP_ILLEGAL_PARAMETER + 1)
#define HID_SDP_MANDATORY_MISSING (SDP_ILLEGAL_PARAMETER + 2)
#define HID_VIRTUAL_CABLE         0x0001
#define HID_RECONN_INIT           0x0004
#define HID_NORMALLY_CONNECTABLE  0x0002
#define HID_SDP_DISABLE           0x0008
#define HID_BATTERY_POWER         0x0010
#define HID_REMOTE_WAKE           0x0020
#define HID_SUP_TOUT_AVLBL        0x0040

/* tHID_HOST_SDP_CALLBACK, from the header we can't include either. */
typedef void (*tHID_HOST_SDP_CALLBACK)(UINT16 result, UINT16 attr_mask,
                                       void *p_sdp_rec /* tHID_DEV_SDP_INFO * */);

/* Events the HID host reports to the application, and the callback's type
   (tHID_HOST_DEV_CALLBACK), both from that same hidh_api.h. */
enum {
    HID_HDEV_EVT_OPEN,
    HID_HDEV_EVT_CLOSE,
    HID_HDEV_EVT_RETRYING,
    HID_HDEV_EVT_INTR_DATA,
    HID_HDEV_EVT_INTR_DATC,
    HID_HDEV_EVT_CTRL_DATA,
    HID_HDEV_EVT_CTRL_DATC,
    HID_HDEV_EVT_HANDSHAKE,
    HID_HDEV_EVT_VC_UNPLUG
};
typedef void (*tHID_HOST_DEV_CALLBACK)(UINT8 dev_handle, UINT8 event, UINT32 data,
                                       BT_HDR *p_buf);

/* tHID_CONN (stack/hid/hid_conn.h) as the device record holds it at 0x10, and the
   record itself (tHID_HOST_DEV_CTB of stack/hid/hidh_int.h). */
#define HID_CONN_STATE_UNUSED         (0)  /* record free */
#define HID_CONN_STATE_CONNECTING     (1)  /* control channel connect pending */
#define HID_CONN_STATE_INTR_CONNECTING (2) /* interrupt channel connect pending */
#define HID_CONN_STATE_CONFIG         (3)  /* both channels up, L2CAP config pending */
#define HID_CONN_STATE_OPENED         (4)  /* reports may flow */
#define HID_CONN_STATE_DISCONNECTING  (5)  /* tearing the channels down */
#define HID_CONN_STATE_SECURITY       (6)  /* control up, BTM security check running */

/* conn_flags, from the same hid_conn.h. Bit 0 says we opened the channels (the
   originator); the four L2CAP config events masked by 0x1E are what
   hidh_l2cif_config_cfm waits for before it reports HID_CONN_STATE_OPENED. */
#define HID_CONN_FLAGS_IS_ORIG            0x01
#define HID_CONN_FLAGS_HIS_CTRL_CFG_DONE  0x02  /* peer's config of the control channel */
#define HID_CONN_FLAGS_MY_CTRL_CFG_DONE   0x04  /* our config of the control channel */
#define HID_CONN_FLAGS_HIS_INTR_CFG_DONE  0x08  /* peer's config of the interrupt channel */
#define HID_CONN_FLAGS_MY_INTR_CFG_DONE   0x10  /* our config of the interrupt channel */
#define HID_CONN_FLAGS_ALL_CONFIGURED     0x1E  /* all four done */
#define HID_CONN_FLAGS_CONGESTED          0x20
#define HID_CONN_FLAGS_INACTIVE           0x40

/* The security channel a HID connection asks BTM for (hid_conn.h), and the
   hidh_api.h attribute bit that says the device wants that check at all. */
#define HID_SEC_CHN                       1
#define HID_NOSEC_CHN                     2
#define HID_SEC_REQUIRED                  0x8000

/* hh_cb.devices[].state, the tHID_HOST_DEV_STATE of hidh_api.h. */
#define HID_DEV_NO_CONN                   0
#define HID_DEV_CONNECTED                 1

/* hh_cb.l2cap_cfg: the L2CAP config options every HID channel is opened with. */
#define hh_cb_l2cap_cfg               (lbl_803C3C38 + 0x344)

typedef struct {
    /* 0x10 */ u8 conn_state;        /* HID_CONN_STATE_* */
               u8 conn_flags;        /* HID_CONN_FLAGS_* */
               u8 ctrl_id;
               u8 pad_0x13;
               u16 ctrl_cid;
               u16 intr_cid;
               u16 rem_mtu_size;
               u16 disc_reason;
               u8 timer_entry[0x18];
} tHID_CONN_VIEW;                    /* 0x24 */

typedef struct {
    /* 0x00 */ u8 in_use;
               u8 addr[6];           /* BD_ADDR of the host device */
               u8 pad_0x07;
               u16 attr_mask;        /* HID_VIRTUAL_CABLE .. HID_SUP_TOUT_AVLBL */
    /* 0x0A */ u8 state;
               u8 conn_substate;
               u8 conn_tries;
               u8 pad_0x0D[3];
    /* 0x10 */ tHID_CONN_VIEW conn;
} tHID_HOST_DEV_CTB_VIEW;            /* 0x34 */

/* The HID host control block hh_cb (tHID_HOST_CTB).  This build compiles with
   HID_HOST_MAX_DEVICES = 16 rather than bt_target.h's 7, so devices[] runs to
   0x340, where the application callback follows; then l2cap_cfg at 0x344,
   sdp_busy 0x380, sdp_cback 0x384, p_sdp_db 0x388, sdp_rec 0x38c, reg_flag 0x400
   and trace_level 0x401. */
#define HIDH_MAX_DEVICES        16
#define hh_cb_devices           (lbl_803C3C38)
#define hh_cb_dev(d)            ((tHID_HOST_DEV_CTB_VIEW *)(hh_cb_devices + (d) * sizeof(tHID_HOST_DEV_CTB_VIEW)))
#define hh_cb_callback          (*(tHID_HOST_DEV_CALLBACK *)(lbl_803C3C38 + 0x340))
#define hh_cb_trace_level       (lbl_803C3C38[0x401])

/* SDP search callback of HID_HostGetSDPRecord: pulls the device's Human Interface
   Service record out of the discovery database into hh_cb.sdp_rec, collects the
   optional attributes into an attribute mask and reports both to the
   application's callback. */
void hidh_search_callback(UINT16 sdp_result) {
    tSDP_DISCOVERY_DB *p_db = *(tSDP_DISCOVERY_DB **)(lbl_803C3C38 + 0x388);  // hh_cb.p_sdp_db
    tSDP_DISC_REC *p_rec;
    tSDP_DISC_ATTR *p_attr;
    tSDP_DISC_ATTR *p_subattr1;
    tSDP_DISC_ATTR *p_subattr2;
    tSDP_DISC_ATTR *p_repdesc;
    tBT_UUID hid_uuid;
    tHID_DEV_SDP_INFO *p_nvi = (tHID_DEV_SDP_INFO *)(lbl_803C3C38 + 0x38c);  // &hh_cb.sdp_rec
    UINT16 attr_mask = 0;
    UINT16 len;

    hid_uuid.len = LEN_UUID_16;
    hid_uuid.uu.uuid16 = UUID_SERVCLASS_HUMAN_INTERFACE;

    lbl_803C3C38[0x380] = FALSE;  // hh_cb.sdp_busy
    if (sdp_result != SDP_SUCCESS) {
        (*(tHID_HOST_SDP_CALLBACK *)(lbl_803C3C38 + 0x384))(sdp_result, 0, NULL);
        return;
    }
    if ((p_rec = SDP_FindServiceUUIDInDb(p_db, &hid_uuid, NULL)) == NULL) {
        (*(tHID_HOST_SDP_CALLBACK *)(lbl_803C3C38 + 0x384))(HID_SDP_NO_SERV_UUID, 0, NULL);
        return;
    }
    memset(p_nvi, 0, sizeof(tHID_DEV_SDP_INFO));
    /* First, verify the mandatory fields we care about: the first report
       descriptor of the HID descriptor list has to be a text string. */
    if (((p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_DESCRIPTOR_LIST)) == NULL)
        || (SDP_DISC_ATTR_TYPE(p_attr->attr_len_type) != DATA_ELE_SEQ_DESC_TYPE)
        || ((p_subattr1 = p_attr->attr_value.v.p_sub_attr) == NULL)
        || (SDP_DISC_ATTR_TYPE(p_subattr1->attr_len_type) != DATA_ELE_SEQ_DESC_TYPE)
        || ((p_subattr2 = p_subattr1->attr_value.v.p_sub_attr) == NULL)
        || ((p_repdesc = p_subattr2->p_next_attr) == NULL)
        || (SDP_DISC_ATTR_TYPE(p_repdesc->attr_len_type) != TEXT_STR_DESC_TYPE)) {
        (*(tHID_HOST_SDP_CALLBACK *)(lbl_803C3C38 + 0x384))(HID_SDP_MANDATORY_MISSING, 0, NULL);
        return;
    }
    len = SDP_DISC_ATTR_LEN(p_repdesc->attr_len_type);
    p_nvi->dscp_info.dl_len = len;
    if (len != 0)
        p_nvi->dscp_info.dsc_list = (UINT8 *)&p_repdesc->attr_value;

    /* The optional boolean attributes, each with its bit in the mask. */
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_VIRTUAL_CABLE);
    if (p_attr != NULL && p_attr->attr_value.v.u8) attr_mask |= HID_VIRTUAL_CABLE;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_RECONNECT_INITIATE);
    if (p_attr != NULL && p_attr->attr_value.v.u8) attr_mask |= HID_RECONN_INIT;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_NORMALLY_CONNECTABLE);
    if (p_attr != NULL && p_attr->attr_value.v.u8) attr_mask |= HID_NORMALLY_CONNECTABLE;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_SDP_DISABLE);
    if (p_attr != NULL && p_attr->attr_value.v.u8) attr_mask |= HID_SDP_DISABLE;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_BATTERY_POWER);
    if (p_attr != NULL && p_attr->attr_value.v.u8) attr_mask |= HID_BATTERY_POWER;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_REMOTE_WAKE);
    if (p_attr != NULL && p_attr->attr_value.v.u8) attr_mask |= HID_REMOTE_WAKE;

    /* The three display strings, truncated to their buffer with a NUL. */
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_SERVICE_NAME);
    if (p_attr != NULL) {
        len = SDP_DISC_ATTR_LEN(p_attr->attr_len_type);
        if (len < HID_MAX_SVC_NAME_LEN) {
            memcpy(p_nvi->svc_name, p_attr->attr_value.v.array, len);
            p_nvi->svc_name[len] = 0;
        } else {
            memcpy(p_nvi->svc_name, p_attr->attr_value.v.array, HID_MAX_SVC_NAME_LEN - 1);
            p_nvi->svc_name[HID_MAX_SVC_NAME_LEN] = 0;
        }
    } else
        p_nvi->svc_name[0] = 0;

    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_SERVICE_DESCRIPTION);
    if (p_attr != NULL) {
        len = SDP_DISC_ATTR_LEN(p_attr->attr_len_type);
        if (len < HID_MAX_SVC_DESCR_LEN) {
            memcpy(p_nvi->svc_descr, p_attr->attr_value.v.array, len);
            p_nvi->svc_descr[len] = 0;
        } else {
            memcpy(p_nvi->svc_descr, p_attr->attr_value.v.array, HID_MAX_SVC_DESCR_LEN - 1);
            p_nvi->svc_descr[HID_MAX_SVC_DESCR_LEN] = 0;
        }
    } else
        p_nvi->svc_descr[0] = 0;

    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_PROVIDER_NAME);
    if (p_attr != NULL) {
        len = SDP_DISC_ATTR_LEN(p_attr->attr_len_type);
        if (len < HID_MAX_PROV_NAME_LEN) {
            memcpy(p_nvi->prov_name, p_attr->attr_value.v.array, len);
            p_nvi->prov_name[len] = 0;
        } else {
            memcpy(p_nvi->prov_name, p_attr->attr_value.v.array, HID_MAX_PROV_NAME_LEN - 1);
            p_nvi->prov_name[HID_MAX_PROV_NAME_LEN] = 0;
        }
    } else
        p_nvi->prov_name[0] = 0;

    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_DEVICE_RELNUM);
    if (p_attr != NULL) p_nvi->rel_num = p_attr->attr_value.v.u16;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_COUNTRY_CODE);
    if (p_attr != NULL) p_nvi->ctry_code = p_attr->attr_value.v.u8;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_DEVICE_SUBCLASS);
    if (p_attr != NULL) p_nvi->sub_class = p_attr->attr_value.v.u8;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_PARSER_VERSION);
    if (p_attr != NULL) p_nvi->hpars_ver = p_attr->attr_value.v.u16;
    p_attr = fn_80095C64((void **)p_rec, ATTR_ID_HID_LINK_SUPERVISION_TO);
    if (p_attr != NULL) {
        attr_mask |= HID_SUP_TOUT_AVLBL;
        p_nvi->sup_timeout = p_attr->attr_value.v.u16;
    }
    *(tSDP_DISC_REC **)(lbl_803C3C38 + 0x3FC) = p_rec;  // hh_cb.sdp_rec.p_sdp_layer_rec
    (*(tHID_HOST_SDP_CALLBACK *)(lbl_803C3C38 + 0x384))(SDP_SUCCESS, attr_mask,
                                                       lbl_803C3C38 + 0x38c);
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
    u8 *base;
    u8 *entry;
    u32 i;
    u32 offset;
    u8 one = 1;
    u8 zero = 0;
    base = lbl_803C3C38;
    if (lbl_803C3C38[0x400] == 0)
        return 1;
    for (i = 0; i < 0x10; i++) {
        u8 flag = lbl_803C3C38[0x400];
        u8 active;
        if (flag == 0)
            continue;
        if ((u8)i > 0x10)
            continue;
        offset = ((u8)i) * 0x34;
        entry = base + offset;
        active = base[offset];
        if (active == 0)
            continue;
        if (flag == 0 || (u8)i > 0x10 || active == 0)
            goto do_clear;
        entry[0xC] = one;
        fn_80070F90(entry + 0x1C);
        if (entry[0xA] != 1)
            goto do_clear;
        entry[0xC] = one;
        hidh_conn_disconnect((u8)i);
do_clear:
        entry[0] = zero;
        entry[0x10] = zero;
        *(u16 *)(entry + 0x16) = 0;
        *(u16 *)(entry + 0x14) = 0;
    }
    fn_80089248();
    lbl_803C3C38[0x400] = 0;
    return 0;
}

u8 HID_HostAddDev(u8 *addr, u16 attr_mask, u8 *handle) {
    u32 offset;
    s32 index;
    u8 *p;
    s32 ctr;
    u8 value;
    p = lbl_803C3C38;
    if (p[0x400] == 0)
        return 1;
    index = 0;
search:
    if (memcmp(addr, p + 1, 6) != 0) {
        index++;
        p += 0x34;
        if (index < 0x10)
            goto search;
    }
    if (index == 0x10) {
        p = lbl_803C3C38;
        index = 0;
        ctr = 2;
scan:
        if (p[0] == 0)
            goto scan_done;
        value = p[0x34];
        index++;
        if (value == 0)
            goto scan_done;
        value = p[0x68];
        index++;
        if (value == 0)
            goto scan_done;
        value = p[0x9C];
        index++;
        if (value == 0)
            goto scan_done;
        value = p[0xD0];
        index++;
        if (value == 0)
            goto scan_done;
        value = p[0x104];
        index++;
        if (value == 0)
            goto scan_done;
        value = p[0x138];
        index++;
        if (value == 0)
            goto scan_done;
        value = p[0x16C];
        index++;
        if (value == 0)
            goto scan_done;
        p += 0x1A0;
        index++;
        ctr--;
        if (ctr != 0)
            goto scan;
    }
scan_done:
    if (index == 0x10)
        return 3;
    offset = (u32)index * 0x34U;
    p = lbl_803C3C38;
    if (p[offset] == 0) {
        p[offset] = 1;
        memcpy(p + offset + 1, addr, 6);
        p[offset + 0xA] = 0;
        p[offset + 0xC] = 0;
    }
    *(u16 *)(p + offset + 8) = attr_mask;
    *handle = (u8)index;
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
    if (arg0 > 0x10 || ((offset = arg0 * 0x34), entry[offset] == 0))
        return 5;
    entry += offset;
    if (entry[0xA] != 0)
        return 10;
    entry[0xC] = 1;
    return hidh_conn_initiate(arg0);
}

u8 HID_HostWriteDev(u8 dev_handle, u8 t_type, u8 param, u16 data, u8 report_id, BT_HDR *pbuf) {
    char *messages = lbl_80317720;
    u8 status = 0;

    if (lbl_803C3C38[0x400] == 0) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0);
        status = 1;
    }
    if ((dev_handle > 0x10) ||
        (*((u8 *)lbl_803C3C38 + dev_handle * 0x34) == 0)) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_8007093C(0x1E0000, messages + 0x18);
        status = 5;
    }
    if (*((u8 *)lbl_803C3C38 + dev_handle * 0x34 + 0xA) != 1) {
        if (lbl_803C3C38[0x401] >= 1)
            fn_80070954(0x1E0000, messages + 0x30, dev_handle);
        status = 4;
    }
    if (status != 0) {
        if (pbuf != NULL)
            GKI_freebuf(pbuf);
    } else {
        status = hidh_conn_snd_data(dev_handle, t_type, param, data, report_id, pbuf);
    }
    return status;
}

u8 HID_HostCloseDev(u8 dev_handle) {
    extern u8 hidh_conn_disconnect(u32);
    tHID_HOST_DEV_VIEW *devices = (tHID_HOST_DEV_VIEW *)lbl_803C3C38;
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

/* Register the HID host's services with the security manager (BTM_SetSecurityLevel
 * keeps a service record per psm/service_id/name): the HID service on the control
 * PSM at the level the application asked for, then the HID device record and the
 * boot interface on the interrupt PSM at the stack default, each registered twice
 * - once as the acceptor of the connection and once as its initiator.  The last
 * two arguments are BTM's class-of-service feature mask and the security id BTM
 * hands back with the channel (1 control, 2 interrupt, 0 boot).
 * Returns a tHID_STATUS: HID_SUCCESS, or HID_ERR_NO_RESOURCES if BTM has no free
 * service record, which is traced as "Security Registration <n> failed". */
s32 HID_HostSetSecurityLevel(void *serv_name, u8 sec_lvl) {
    char *messages = lbl_80317720;

    if (!BTM_SetSecurityLevel(FALSE, serv_name, HID_SERVICE_ATTR_MASK, sec_lvl, HID_PSM_CONTROL, 6, 1)) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_ERROR)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_ERROR, messages + 0x54); /* "Security Registration 1 failed" */
        return HID_ERR_NO_RESOURCES;
    }
    if (!BTM_SetSecurityLevel(TRUE, serv_name, HID_SERVICE_ATTR_MASK, sec_lvl, HID_PSM_CONTROL, 6, 1)) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_ERROR)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_ERROR, messages + 0x74); /* "Security Registration 2 failed" */
        return HID_ERR_NO_RESOURCES;
    }
    if (!BTM_SetSecurityLevel(FALSE, serv_name, HID_HID_DEV_ATTR_MASK, 0, HID_PSM_CONTROL, 6, 2)) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_ERROR)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_ERROR, messages + 0x94); /* "Security Registration 3 failed" */
        return HID_ERR_NO_RESOURCES;
    }
    if (!BTM_SetSecurityLevel(TRUE, serv_name, HID_HID_DEV_ATTR_MASK, 0, HID_PSM_CONTROL, 6, 2)) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_ERROR)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_ERROR, messages + 0xB4); /* "Security Registration 4 failed" */
        return HID_ERR_NO_RESOURCES;
    }
    if (!BTM_SetSecurityLevel(TRUE, serv_name, HID_BOOT_IFACE_ATTR_MASK, 0, HID_PSM_INTERRUPT, 6, 0)) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_ERROR)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_ERROR, messages + 0xD4); /* "Security Registration 5 failed" */
        return HID_ERR_NO_RESOURCES;
    }
    if (!BTM_SetSecurityLevel(FALSE, serv_name, HID_BOOT_IFACE_ATTR_MASK, 0, HID_PSM_INTERRUPT, 6, 0)) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_ERROR)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_ERROR, messages + 0xF4); /* "Security Registration 6 failed" */
        return HID_ERR_NO_RESOURCES;
    }
    return HID_SUCCESS;
}

u8 hidh_conn_reg(void) {
    /* Register HID control/interrupt L2CAP PSMs and initialize HID control block state. */
    extern unsigned char lbl_803C3C38[];
    extern unsigned char lbl_802EEC18[];
    extern char lbl_80317838[];
    extern char lbl_80317858[];
    unsigned char *hidhCb = lbl_803C3C38;

    hidhCb[0x346] = 1;
    *(UINT16 *)(hidhCb + 0x348) = 0x280;
    hidhCb[0x364] = 1;
    *(UINT16 *)(hidhCb + 0x366) = 0xFFFF;
    if ((u8)L2CA_Register(0x11, (tL2CAP_APPL_INFO *)lbl_802EEC18) == 0) {
        if (hidhCb[0x401] >= 1) fn_8007093C(0x1E0000, lbl_80317838);
        return 0xE;
    }
    if ((u8)L2CA_Register(0x13, (tL2CAP_APPL_INFO *)lbl_802EEC18) == 0) {
        L2CA_Deregister(0x11);
        if (hidhCb[0x401] >= 1) fn_8007093C(0x1E0000, lbl_80317858);
        return 0xE;
    }
    hidhCb[0] = 0; hidhCb[0x10] = 0; hidhCb[0x34] = 0; hidhCb[0x44] = 0;
    hidhCb[0x68] = 0; hidhCb[0x78] = 0; hidhCb[0x9C] = 0; hidhCb[0xAC] = 0;
    hidhCb[0xD0] = 0; hidhCb[0xE0] = 0; hidhCb[0x104] = 0; hidhCb[0x114] = 0;
    hidhCb[0x138] = 0; hidhCb[0x148] = 0; hidhCb[0x16C] = 0; hidhCb[0x17C] = 0;
    hidhCb[0x1A0] = 0; hidhCb[0x1B0] = 0; hidhCb[0x1D4] = 0; hidhCb[0x1E4] = 0;
    hidhCb[0x208] = 0; hidhCb[0x218] = 0; hidhCb[0x23C] = 0; hidhCb[0x24C] = 0;
    hidhCb[0x270] = 0; hidhCb[0x280] = 0; hidhCb[0x2A4] = 0; hidhCb[0x2B4] = 0;
    hidhCb[0x2D8] = 0; hidhCb[0x2E8] = 0; hidhCb[0x30C] = 0; hidhCb[0x31C] = 0;
    return 0;
}

/* Disconnect a HID host connection by device index, requesting L2CAP disconnects for any active CIDs. */
u8 hidh_conn_disconnect(u32 deviceIndex) {
    u8 *connBase;

    connBase = lbl_803C3C38 + deviceIndex * 0x34;
    if (lbl_803C3C38[0x401] >= 4) {
        fn_8007093C(0x1E0003, lbl_8031787C);
    }
    if (*(u16 *)(connBase + 0x14) == 0) {
        if (*(u16 *)(connBase + 0x16) == 0) {
            goto clear_state;
        }
    }
    connBase[0x10] = 5;
    if (*(u16 *)(connBase + 0x16) != 0) {
        L2CA_DisconnectReq(*(u16 *)(connBase + 0x16));
    }
    if (*(u16 *)(connBase + 0x14) != 0) {
        L2CA_DisconnectReq(*(u16 *)(connBase + 0x14));
    }
    goto done;
clear_state:
    connBase[0x10] = 0;
done:
    return 0;
}

extern u8 lbl_8031787C[];
void hidh_sec_check_complete_term(u8 *bd_addr, void *p_ref_data, u8 res) {
    /* HID security procedure callback: on success when connection is in pairing state, send L2CAP connect response and config request; on failure, mark failure and disconnect any active L2CAP channels. */
    u8 *hidhCb = lbl_803C3C38;
    u8 *conn = p_ref_data;
    u8 connIndex = (u8)(((u8 *)p_ref_data - hidhCb) / 0x34);
    u8 *connRec;
    if (res == 0 && conn[0x10] == 6) {
        *(u16 *)(conn + 0x1A) = 0;
        conn[0x10] = 2;
        L2CA_ConnectRsp(conn + 1, conn[0x12], *(u16 *)(conn + 0x14), 0, 0);
        L2CA_ConfigReq(*(u16 *)(conn + 0x14), (void *)(hidhCb + 0x344));
        return;
    }
    if (res != 0) {
        *(u16 *)(conn + 0x1A) = 0xF;
        connRec = lbl_803C3C38 + connIndex * 0x34;
        if (lbl_803C3C38[0x401] >= 4) {
            fn_8007093C(0x1E0003, lbl_8031787C);
        }
        if (*(u16 *)(connRec + 0x14) != 0 || *(u16 *)(connRec + 0x16) != 0) {
            connRec[0x10] = 5;
            if (*(u16 *)(connRec + 0x16) != 0) L2CA_DisconnectReq(*(u16 *)(connRec + 0x16));
            if (*(u16 *)(connRec + 0x14) != 0) L2CA_DisconnectReq(*(u16 *)(connRec + 0x14));
        } else {
            connRec[0x10] = 0;
        }
    }
}

/* L2CAP connection indication on one of the two PSMs this host serves
   (hidh_l2cif_connect_ind of stack/hid/hidh_conn.c).  The peer has to be one of
   the 16 host-device records already; the interrupt channel is only accepted
   while the control channel is up and the record waits for it, the control
   channel only while the record is free.  A control channel then runs the BTM
   security check and answers L2CAP from its callback; an interrupt channel is
   answered at once and sent its L2CAP configuration request. */
void hidh_l2cif_connect_ind(BD_ADDR bd_addr, UINT16 l2cap_cid, UINT16 psm, UINT8 l2cap_id) {
    extern void hidh_sec_check_complete_term(u8 *, void *, u8);
    BOOLEAN bAccept = TRUE;
    char *strings = lbl_80317838;
    tHID_HOST_DEV_CTB_VIEW *p_dev;
    int i;
    tHID_HOST_DEV_CTB_VIEW *entry;

    if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
        fn_8007096C(TRACE_LAYER_HID | TRACE_TYPE_EVENT, strings + 0x58, psm, l2cap_cid); /* "HID - Rcvd L2CAP conn ind, PSM: 0x%04x  CID 0x%x" */

    /* Which of our records is this device? */
    p_dev = (tHID_HOST_DEV_CTB_VIEW *)hh_cb_devices;
    for (i = 0; i < HIDH_MAX_DEVICES; i++, p_dev++) {
        if (p_dev->in_use && memcmp(bd_addr, p_dev->addr, sizeof(BD_ADDR)) == 0)
            break;
    }
    if (i == HIDH_MAX_DEVICES) {
        L2CA_ConnectRsp(bd_addr, l2cap_id, l2cap_cid, L2CAP_CONN_SECURITY_BLOCK, 0);
        return;
    }
    entry = hh_cb_dev(i);

    /* Check we are in the correct state for this channel. */
    if (psm == HID_PSM_INTERRUPT) {
        if (entry->conn.ctrl_cid == 0) {
            if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
                fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_WARNING, strings + 0x8c); /* "HID - Rcvd INTR L2CAP conn ind, but no CTL channel" */
            bAccept = FALSE;
        }
        if (entry->conn.conn_state != HID_CONN_STATE_INTR_CONNECTING) {
            if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
                fn_80070954(TRACE_LAYER_HID | TRACE_TYPE_WARNING, strings + 0xc0, entry->conn.conn_state); /* "HID - Rcvd INTR L2CAP conn ind, wrong state: %d" */
            bAccept = FALSE;
        }
    } else if (entry->conn.conn_state != HID_CONN_STATE_UNUSED) { /* the CTRL channel */
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
            fn_80070954(TRACE_LAYER_HID | TRACE_TYPE_WARNING, strings + 0xf0, entry->conn.conn_state); /* "HID - Rcvd CTL L2CAP conn ind, wrong state: %d" */
        bAccept = FALSE;
    }
    if (!bAccept) {
        L2CA_ConnectRsp(bd_addr, l2cap_id, l2cap_cid, L2CAP_CONN_NO_RESOURCES, 0);
        return;
    }

    if (psm == HID_PSM_CONTROL) {
        entry->conn.conn_flags = 0;
        entry->conn.ctrl_cid = l2cap_cid;
        entry->conn.ctrl_id = l2cap_id;
        /* in case the channels go down before security is done, this is the
           reason the application hears about */
        entry->conn.disc_reason = HID_L2CAP_CONN_FAIL;
        entry->conn.conn_state = HID_CONN_STATE_SECURITY;
        /* L2CA_ConnectRsp comes later, from hidh_sec_check_complete_term */
        btm_sec_mx_access_request(entry->addr, HID_PSM_CONTROL, FALSE, BTM_SEC_PROTO_HID,
                                  (entry->attr_mask & HID_SEC_REQUIRED) ? HID_SEC_CHN : HID_NOSEC_CHN,
                                  hidh_sec_check_complete_term, entry);
    } else {
        /* Transition to the next appropriate state, configuration. */
        entry->conn.conn_state = HID_CONN_STATE_CONFIG;
        entry->conn.intr_cid = l2cap_cid;
        L2CA_ConnectRsp(bd_addr, l2cap_id, l2cap_cid, L2CAP_CONN_OK, L2CAP_CONN_OK);
        L2CA_ConfigReq(l2cap_cid, (void *)hh_cb_l2cap_cfg);
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
            fn_8007096C(TRACE_LAYER_HID | TRACE_TYPE_EVENT, strings + 0x120, psm, l2cap_cid); /* "HID - Rcvd L2CAP conn ind, sent config req, PSM: 0x%04x  CID 0x%x" */
    }
}

extern char lbl_8031799C[];
void hidh_proc_repage_timeout(TIMER_LIST_ENT *p_tle) {
    UINT32 handle = p_tle->param;
    UINT8 index = (UINT8)handle;
    UINT8 one = 1;
    UINT8 *callbackBase = lbl_803C3C38;
    UINT8 *device = callbackBase + index * 0x34;
    UINT16 cid;
    UINT32 deviceHandle;
    void (**callback)(UINT8, UINT32, UINT8, void *);

    /* Handles HID host repage timeout: retries L2CAP connect if needed, then bumps retry count and notifies callback. */
    if (device[0x10] == 0) {
        *(UINT16 *)(device + 0x14) = 0;
        *(UINT16 *)(device + 0x16) = 0;
        *(UINT16 *)(device + 0x1A) = 0x100;
        device[0x11] = one;
        cid = L2CA_ConnectReq(0x11, device + 1);
        *(UINT16 *)(device + 0x14) = cid;
        if (cid == 0) {
            if (lbl_803C3C38[0x401] >= 2)
                fn_8007093C(0x1E0001, lbl_8031799C);
            callbackBase = lbl_803C3C38;
            deviceHandle = (device - callbackBase) / 0x34;
            deviceHandle = deviceHandle / 0x34;
            (*((void (**)(UINT8, UINT32, UINT8, void *))(callbackBase + 0x340)))(
                (UINT8)deviceHandle, 1, 0xE, 0);
        } else {
            device[0x10] = one;
        }
    }

    callbackBase = lbl_803C3C38;
    *(UINT8 *)(callbackBase + p_tle->param * 0x34 + 0xC) += 1;
    callback = (void (**)(UINT8, UINT32, UINT8, void *))(callbackBase + 0x340);
    (*callback)((UINT8)p_tle->param, 2,
                *(UINT8 *)(callbackBase + p_tle->param * 0x34 + 0xC), 0);
}

void hidh_sec_check_complete_orig(BD_ADDR bd_addr, void *p_ref_data, UINT8 res) {
    /* HID host security check completion: on success in connecting state, open the
       control L2CAP channel; on failure or connect error, disconnect channels and
       report status via the registered callback. */
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

/* L2CAP connect confirmation for a channel we opened (hidh_l2cif_connect_cfm of
   stack/hid/hidh_api.c).  Finds the device that owns the control or interrupt
   channel that just came up: on a failure it drops the channel and, if nothing
   is left, tears the device down and reports HID_HDEV_EVT_CLOSE; on success it
   runs the BTM security check for the control channel (or marks the interrupt
   channel as waiting for its configuration) and asks for the L2CAP config. */
static void hidh_l2cif_connect_cfm(u32 l2cap_cid, s32 result) {
    char *strings = lbl_80317838;
    UINT8 dhandle;
    tHID_CONN_VIEW *p_hcon = NULL;
    tHID_HOST_DEV_CTB_VIEW *p_dev = NULL;
    tHID_HOST_DEV_CTB_VIEW *entry;

    /* Which device does this channel belong to? */
    for (dhandle = 0; dhandle < HIDH_MAX_DEVICES; dhandle++) {
        entry = hh_cb_dev(dhandle);
        if (entry->in_use != 0 && entry->conn.conn_state != 0 &&
            (l2cap_cid == entry->conn.ctrl_cid ||
             l2cap_cid == entry->conn.intr_cid)) break;
    }
    if (dhandle != HIDH_MAX_DEVICES) {
        p_dev = hh_cb_dev(dhandle);
        p_hcon = &p_dev->conn;
    }

    /* Not ours, we did not open it, or the channel already answered. */
    if (p_hcon == NULL || (p_hcon->conn_flags & HID_CONN_FLAGS_IS_ORIG) == 0 ||
        (l2cap_cid == p_hcon->ctrl_cid && p_hcon->conn_state != HID_CONN_STATE_CONNECTING) ||
        (l2cap_cid == p_hcon->intr_cid && p_hcon->conn_state != HID_CONN_STATE_INTR_CONNECTING)) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
            ((void (*)(u32, void *, u32))fn_80070954)(
                TRACE_LAYER_HID | TRACE_TYPE_WARNING, strings + 0x1BC, l2cap_cid); /* "HID - Rcvd unexpected conn cnf, CID 0x%x " */
        return;
    }

    if (result != 0) {
        /* The channel is gone; forget its CID. */
        if (l2cap_cid == p_hcon->ctrl_cid)
            p_hcon->ctrl_cid = 0;
        else
            p_hcon->intr_cid = 0;
        p_dev = hh_cb_dev(dhandle);
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_EVENT, strings + 0x44); /* "HID - disconnect" */
        if (p_dev->conn.ctrl_cid != 0 || p_dev->conn.intr_cid != 0) {
            /* The other channel is still up, so take the device down with it. */
            p_dev->conn.conn_state = HID_CONN_STATE_DISCONNECTING;
            if (p_dev->conn.intr_cid != 0)
                L2CA_DisconnectReq(p_dev->conn.intr_cid);
            if (p_dev->conn.ctrl_cid != 0)
                L2CA_DisconnectReq(p_dev->conn.ctrl_cid);
        } else {
            p_dev->conn.conn_state = HID_CONN_STATE_UNUSED;
        }
        hh_cb_callback(dhandle, HID_HDEV_EVT_CLOSE, result | 0x100, NULL);
        return;
    }

    if (l2cap_cid == p_hcon->ctrl_cid) {
        /* Control channel: the interrupt one may only be opened once the device
           passed the security check for this connection. */
        p_hcon->conn_state = HID_CONN_STATE_SECURITY;
        p_hcon->disc_reason = 0x100;
        {
            u16 attr = p_dev->attr_mask;
            s32 sec_level = (attr & 0x8000) ? 1 : 2;
            btm_sec_mx_access_request(
                p_dev->addr, 0x11 /* PSM_HID_CONTROL */, 1 /* we are the originator */,
                6, sec_level,
                &hidh_sec_check_complete_orig, p_dev);
        }
    } else {
        p_hcon->conn_state = HID_CONN_STATE_CONFIG;
    }

    /* Widened cast: the CID is passed as a full word, not truncated to u16. */
    ((void (*)(u32, void *))L2CA_ConfigReq)(l2cap_cid, (void *)hh_cb_l2cap_cfg);
    if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
        ((void (*)(u32, void *, u32))fn_80070954)(
            TRACE_LAYER_HID | TRACE_TYPE_EVENT, strings + 0x1E8, l2cap_cid); /* "HID - got CTRL conn cnf, sent cfg req, CID: 0x%x" */
}

/* L2CAP configuration indication for one of this device's HID channels
   (hidh_l2cif_config_ind of stack/hid/hidh_conn.c).  Finds which host device
   owns the control or interrupt channel being configured, remembers the peer's
   MTU (capped at HID_HOST_MTU) and always accepts its configuration with
   L2CA_ConfigRsp.  The peer's "config done" flag for that channel is set; when
   all four configuration events are in and the channels are still in
   HID_CONN_STATE_CONFIG, the device is marked connected and the application is
   told HID_HDEV_EVT_OPEN. */
static void hidh_l2cif_config_ind(UINT16 l2cap_cid, tL2CAP_CFG_INFO *p_cfg)
{
    UINT8 dhandle;
    tHID_CONN_VIEW *p_hcon = NULL;

    /* Find the device this channel belongs to */
    for (dhandle = 0; dhandle < HIDH_MAX_DEVICES; dhandle++) {
        tHID_HOST_DEV_CTB_VIEW *p_dev = hh_cb_dev(dhandle);
        if (p_dev->in_use != 0 && p_dev->conn.conn_state != 0 &&
            (l2cap_cid == p_dev->conn.ctrl_cid ||
             l2cap_cid == p_dev->conn.intr_cid))
            break;
    }

    if (dhandle != HIDH_MAX_DEVICES)
        p_hcon = &hh_cb_dev(dhandle)->conn;

    if (p_hcon == NULL) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
            fn_80070954(TRACE_LAYER_HID | TRACE_TYPE_WARNING, lbl_80317A54, l2cap_cid); /* "HID - Rcvd L2CAP cfg ind, unknown CID: 0x%x" */
    } else {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
            fn_80070954(TRACE_LAYER_HID | TRACE_TYPE_EVENT, lbl_80317A80, l2cap_cid); /* "HID - Rcvd cfg ind, sent cfg cfm, CID: 0x%x" */

        /* Remember the remote MTU size, never trusting the peer to send more
           than we can take */
        if (!p_cfg->mtu_present || p_cfg->mtu > HID_HOST_MTU)
            p_hcon->rem_mtu_size = HID_HOST_MTU;
        else
            p_hcon->rem_mtu_size = p_cfg->mtu;

        /* For now, always accept configuration from the other side */
        p_cfg->flush_to_present = FALSE;
        p_cfg->mtu_present = FALSE;
        p_cfg->result = L2CAP_CFG_OK;
        L2CA_ConfigRsp(l2cap_cid, p_cfg);

        if (l2cap_cid == p_hcon->ctrl_cid)
            p_hcon->conn_flags |= HID_CONN_FLAGS_HIS_CTRL_CFG_DONE;
        else
            p_hcon->conn_flags |= HID_CONN_FLAGS_HIS_INTR_CFG_DONE;

        /* If all configuration is complete, change state and tell management we are up */
        if ((p_hcon->conn_flags & HID_CONN_FLAGS_ALL_CONFIGURED) == HID_CONN_FLAGS_ALL_CONFIGURED &&
            p_hcon->conn_state == HID_CONN_STATE_CONFIG) {
            p_hcon->conn_state = HID_CONN_STATE_OPENED;
            hh_cb_dev(dhandle)->state = HID_DEV_CONNECTED;
            hh_cb_callback(dhandle, HID_HDEV_EVT_OPEN, 0, NULL);
        }
    }
}

/* L2CAP configuration confirmation for one of our HID channels
   (hidh_l2cif_config_cfm of stack/hid/hidh_conn.c).  Finds the device that owns
   the control or interrupt channel whose configuration was just confirmed.  A
   configuration the peer rejected tears the channels down (the work of
   hidh_conn_disconnect) and reports HID_HDEV_EVT_CLOSE with HID_L2CAP_CFG_FAIL;
   otherwise this side's "config done" flag for that channel is set, and once all
   four configurations are done on a device still waiting in
   HID_CONN_STATE_CONFIG, the device is marked connected and the application is
   told HID_HDEV_EVT_OPEN. */
static void hidh_l2cif_config_cfm(u32 l2cap_cid, tL2CAP_CFG_INFO *p_cfg) {
    char *strings = lbl_80317838;
    UINT8 dhandle;
    tHID_HOST_DEV_CTB_VIEW *p_dev;
    tHID_CONN_VIEW *p_hcon = NULL;

    if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
        ((void (*)(u32, void *, u32, u16))fn_8007096C)(TRACE_LAYER_HID | TRACE_TYPE_EVENT, strings + 0x274, l2cap_cid, p_cfg->result); /* "HID - Rcvd cfg cfm, CID: 0x%x  Result: %d" */

    /* Find the device this channel belongs to */
    for (dhandle = 0; dhandle < HIDH_MAX_DEVICES; dhandle++) {
        p_dev = hh_cb_dev(dhandle);
        if (p_dev->in_use != 0 && p_dev->conn.conn_state != 0 &&
            (l2cap_cid == p_dev->conn.ctrl_cid ||
             l2cap_cid == p_dev->conn.intr_cid))
            break;
    }

    if (dhandle != HIDH_MAX_DEVICES)
        p_hcon = &hh_cb_dev(dhandle)->conn;

    if (p_hcon == NULL) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
            ((void (*)(u32, void *, u32))fn_80070954)(TRACE_LAYER_HID | TRACE_TYPE_WARNING, strings + 0x21C, l2cap_cid); /* "HID - Rcvd L2CAP cfg ind, unknown CID: 0x%x" */
        return;
    }

    /* If configuration failed, disconnect the channel(s) */
    if (p_cfg->result != L2CAP_CFG_OK) {
        p_dev = hh_cb_dev(dhandle);
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
            fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_EVENT, strings + 0x44); /* "HID - disconnect" */
        if (p_dev->conn.ctrl_cid != 0 || p_dev->conn.intr_cid != 0) {
            /* The other channel is still up, so take the device down with it. */
            p_dev->conn.conn_state = HID_CONN_STATE_DISCONNECTING;
            if (p_dev->conn.intr_cid != 0)
                L2CA_DisconnectReq(p_dev->conn.intr_cid);
            if (p_dev->conn.ctrl_cid != 0)
                L2CA_DisconnectReq(p_dev->conn.ctrl_cid);
        } else {
            p_dev->conn.conn_state = HID_CONN_STATE_UNUSED;
        }
        hh_cb_callback(dhandle, HID_HDEV_EVT_CLOSE, p_cfg->result | HID_L2CAP_CFG_FAIL, NULL);
        return;
    }

    if (l2cap_cid == p_hcon->ctrl_cid)
        p_hcon->conn_flags |= HID_CONN_FLAGS_MY_CTRL_CFG_DONE;
    else
        p_hcon->conn_flags |= HID_CONN_FLAGS_MY_INTR_CFG_DONE;

    /* If all configuration is complete, change state and tell management we are up */
    if ((p_hcon->conn_flags & HID_CONN_FLAGS_ALL_CONFIGURED) == HID_CONN_FLAGS_ALL_CONFIGURED &&
        p_hcon->conn_state == HID_CONN_STATE_CONFIG) {
        p_hcon->conn_state = HID_CONN_STATE_OPENED;
        p_dev = hh_cb_dev(dhandle);
        p_dev->state = HID_DEV_CONNECTED;
        hh_cb_callback(dhandle, HID_HDEV_EVT_OPEN, 0, NULL);
    }
}

extern char lbl_80317AD8[];
extern char lbl_80317B04[];
/* fn_80077DD8 is btm_get_acl_disc_reason_code() of stack/btm/btm_acl.c; this unit
   defines it as u8, so the UINT16 the stack wants needs the cast. */
#define btm_get_acl_disc_reason_code() ((UINT16 (*)(void))fn_80077DD8)()

/* L2CAP disconnect indication for one of a HID device's channels
   (hidh_l2cif_disconnect_ind of stack/hid/hidh_conn.c).  Finds the device that
   owns the channel that just went down, answers the disconnect first when L2CAP
   asked for it, and clears that channel's CID.  Once the control and the
   interrupt channel are both gone the device is closed: the application gets
   HID_HDEV_EVT_CLOSE, with its reason changed to HID_ERR_AUTH_FAILED when the
   baseband dropped the link for one of the security errors below. */
static void hidh_l2cif_disconnect_ind(UINT16 l2cap_cid, BOOLEAN ack_needed)
{
    UINT8 dhandle;
    tHID_CONN_VIEW *p_hcon = NULL;
    UINT16 disc_res = HCI_SUCCESS;
    UINT16 hid_close_evt_reason;

    /* Find the device this channel belongs to */
    for (dhandle = 0; dhandle < HIDH_MAX_DEVICES; dhandle++) {
        tHID_HOST_DEV_CTB_VIEW *p_dev = hh_cb_dev(dhandle);
        if (p_dev->in_use != 0 && p_dev->conn.conn_state != 0 &&
            (l2cap_cid == p_dev->conn.ctrl_cid ||
             l2cap_cid == p_dev->conn.intr_cid))
            break;
    }

    if (dhandle != HIDH_MAX_DEVICES)
        p_hcon = &hh_cb_dev(dhandle)->conn;

    if (p_hcon == NULL) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
            fn_80070954(TRACE_LAYER_HID | TRACE_TYPE_WARNING, lbl_80317AD8, l2cap_cid); /* "HID - Rcvd L2CAP disc, unknown CID: 0x%x" */
    } else {
        if (ack_needed)
            L2CA_DisconnectRsp(l2cap_cid);

        if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
            fn_80070954(TRACE_LAYER_HID | TRACE_TYPE_EVENT, lbl_80317B04, l2cap_cid); /* "HID - Rcvd L2CAP disc, CID: 0x%x" */

        p_hcon->conn_state = HID_CONN_STATE_DISCONNECTING;
        if (l2cap_cid == p_hcon->ctrl_cid)
            p_hcon->ctrl_cid = 0;
        else
            p_hcon->intr_cid = 0;

        /* Both channels down: the device is closed. */
        if (p_hcon->ctrl_cid == 0 && p_hcon->intr_cid == 0) {
            hh_cb_dev(dhandle)->state = HID_DEV_NO_CONN;
            p_hcon->conn_state = HID_CONN_STATE_UNUSED;

            if (!ack_needed)
                disc_res = btm_get_acl_disc_reason_code();

            hid_close_evt_reason = p_hcon->disc_reason;
            if (disc_res == HCI_ERR_AUTH_FAILURE || disc_res == HCI_ERR_KEY_MISSING ||
                disc_res == HCI_ERR_HOST_REJECT_SECURITY ||
                disc_res == HCI_ERR_PAIRING_NOT_ALLOWED ||
                disc_res == HCI_ERR_UNIT_KEY_USED ||
                disc_res == HCI_ERR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED ||
                disc_res == HCI_ERR_ENCRY_MODE_NOT_ACCEPTABLE ||
                disc_res == HCI_ERR_REPEATED_ATTEMPTS)
                hid_close_evt_reason = HID_ERR_AUTH_FAILED;

            hh_cb_callback(dhandle, HID_HDEV_EVT_CLOSE, hid_close_evt_reason, NULL);
        }
    }
}

extern char lbl_80317B28[];
extern char lbl_80317B58[];
void hidh_l2cif_disconnect_cfm(u32 handle) {
    u8 dhandle;
    u8 *found = 0;

    for (dhandle = 0; dhandle < 0x10; dhandle++) {
        u8 *entry = (u8 *)lbl_803C3C38 + dhandle * 0x34;
        if (entry[0] != 0 && entry[0x10] != 0 &&
            (handle == *(u16 *)(entry + 0x14) ||
             handle == *(u16 *)(entry + 0x16)))
            break;
    }
    if (dhandle != 0x10)
        found = (u8 *)lbl_803C3C38 + dhandle * 0x34 + 0x10;

    if (found == 0) {
        if (*((u8 *)lbl_803C3C38 + 0x401) >= 2)
            ((void (*)(u32, void *, u32))fn_80070954)(0x1E0001, lbl_80317B28, handle);
    } else {
        if (*((u8 *)lbl_803C3C38 + 0x401) >= 4)
            ((void (*)(u32, void *, u32))fn_80070954)(0x1E0003, lbl_80317B58, handle);
        if (handle == *(u16 *)(found + 4))
            *(u16 *)(found + 4) = 0;
        else
            *(u16 *)(found + 6) = 0;
        if (*(u16 *)(found + 4) == 0 && *(u16 *)(found + 6) == 0) {
            *((u8 *)lbl_803C3C38 + dhandle * 0x34 + 0xA) = 0;
            found[0] = 0;
            ((void (*)(u8, u8, u16, u8, void *, u8))
                (*(void **)((u8 *)lbl_803C3C38 + 0x340)))(dhandle, 1, *(u16 *)(found + 0xA), 0,
                                                    (void *)lbl_803C3C38, 0);
        }
    }
}

extern u8 lbl_80317B80[];
extern u8 lbl_80317BB8[];
/* HID Host: L2CAP congestion indication callback; finds the host entry for the
 * given CID and updates its congestion flag, logging if not found or on change. */
void hidh_l2cif_cong_ind(u32 cid, s32 congested) {
    u8 handle;
    u8 *found = 0;

    for (handle = 0; handle < 0x10; handle++) {
        u8 *entry = (u8 *)lbl_803C3C38 + handle * 0x34;
        if (entry[0] != 0 && entry[0x10] != 0 &&
            (cid == *(u16 *)(entry + 0x14) ||
             cid == *(u16 *)(entry + 0x16)))
            break;
    }
    if (handle != 0x10)
        found = (u8 *)lbl_803C3C38 + handle * 0x34 + 0x10;

    if (found == 0) {
        if (*((u8 *)lbl_803C3C38 + 0x401) >= 2)
            ((void (*)(u32, void *, u32))fn_80070954)(0x1E0001, lbl_80317B80, cid);
    } else {
        if (*((u8 *)lbl_803C3C38 + 0x401) >= 4)
            ((void (*)(u32, void *, u32, s32))fn_8007096C)(0x1E0003, lbl_80317BB8, cid, congested);
        if (congested != 0)
            found[1] |= 0x20;
        else
            found[1] &= ~0x20;
    }
}

extern u8 lbl_80317BF0[];
static void hidh_l2cif_data_ind(UINT16 l2cap_cid, BT_HDR *p_msg) {
    /* HID header byte: transaction type in the high nibble, parameter in the low. */
    UINT8 *p_data = (UINT8 *)(p_msg + 1) + p_msg->offset;
    UINT8 ttype, param, rep_type, evt;
    UINT8 dhandle;
    tHID_HOST_DEV_CTB_VIEW *dev;
    tHID_CONN_VIEW *p_hcon = NULL;
    tHID_HOST_DEV_CTB_VIEW *p_dev = NULL;

    /* Find the device that owns this control or interrupt channel. */
    for (dhandle = 0; dhandle < HIDH_MAX_DEVICES; dhandle++) {
        dev = hh_cb_dev(dhandle);
        if (dev->in_use != 0 && dev->conn.conn_state != 0 &&
            (l2cap_cid == dev->conn.ctrl_cid ||
             l2cap_cid == dev->conn.intr_cid)) {
            break;
        }
    }

    if (dhandle != HIDH_MAX_DEVICES) {
        p_hcon = &hh_cb_dev(dhandle)->conn;
    }

    if (p_hcon == NULL) {
        if (hh_cb_trace_level >= BT_TRACE_LEVEL_WARNING) {
            fn_80070954(TRACE_LAYER_HID | TRACE_TYPE_WARNING, lbl_80317BF0, l2cap_cid); /* "HID - Rcvd L2CAP data, unknown CID: 0x%x" */
        }
        GKI_freebuf(p_msg);
        return;
    }

    ttype = HID_GET_TRANS_FROM_HDR(*p_data);
    param = HID_GET_PARAM_FROM_HDR(*p_data);
    rep_type = param & HID_PAR_REP_TYPE_MASK;
    p_data++;

    /* Get rid of the data type */
    p_msg->len--;
    p_msg->offset++;

    switch (ttype) {
    case HID_TRANS_HANDSHAKE:
        /* The device answered one of our requests with a handshake. */
        hh_cb_callback(dhandle, HID_HDEV_EVT_HANDSHAKE, param, NULL);
        GKI_freebuf(p_msg);
        break;

    case HID_TRANS_CONTROL:
        switch (param) {
        case HID_PAR_CONTROL_VIRTUAL_CABLE_UNPLUG:
            /* hidh_conn_disconnect(dhandle): the device is unplugging from us. */
            p_dev = hh_cb_dev(dhandle);
            if (hh_cb_trace_level >= BT_TRACE_LEVEL_EVENT) {
                fn_8007093C(TRACE_LAYER_HID | TRACE_TYPE_EVENT, lbl_8031787C); /* "HID - disconnect" */
            }
            if (p_dev->conn.ctrl_cid != 0 ||
                p_dev->conn.intr_cid != 0) {
                p_dev->conn.conn_state = HID_CONN_STATE_DISCONNECTING;
                if (p_dev->conn.intr_cid != 0) {
                    L2CA_DisconnectReq(p_dev->conn.intr_cid);
                }
                if (p_dev->conn.ctrl_cid != 0) {
                    L2CA_DisconnectReq(p_dev->conn.ctrl_cid);
                }
            } else {
                p_dev->conn.conn_state = HID_CONN_STATE_UNUSED;
            }
            /* Tell the application. */
            hh_cb_callback(dhandle, HID_HDEV_EVT_VC_UNPLUG, 0, NULL);
            break;
        default:
            break;
        }
        GKI_freebuf(p_msg);
        break;

    case HID_TRANS_DATA:
        evt = (hh_cb_dev(dhandle)->conn.intr_cid == l2cap_cid) ?
                    HID_HDEV_EVT_INTR_DATA : HID_HDEV_EVT_CTRL_DATA;
        hh_cb_callback(dhandle, evt, rep_type, p_msg);
        break;

    case HID_TRANS_DATAC:
        evt = (hh_cb_dev(dhandle)->conn.intr_cid == l2cap_cid) ?
                    HID_HDEV_EVT_INTR_DATC : HID_HDEV_EVT_CTRL_DATC;
        hh_cb_callback(dhandle, evt, rep_type, p_msg);
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
    s32 var_r4;
    register u16 temp_r24;
    register u16 var_r23;
    register u16 var_r24;
    register u16 var_r25;
    register u32 var_r21;
    void *temp_r3_2;
    u8 *temp_r27;
    void *temp_r3;
    register s32 var_r22;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    BT_HDR *var_r26;
    register u8 var_r30;
    register u8 var_r29;
    register u8 var_r28;
    register u8 var_r31;

    var_r17 = trans_type;
    temp_r27 = lbl_803C3C38 + (dhandle * 0x34);
    var_r21 = 0;
    var_r20 = 0;
    if (temp_r27[0x11] & 0x20) {
        if (buf != NULL) GKI_freebuf(buf);
        return 8;
    }
    if (4 > trans_type) {
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
    /* Initiates HID host control L2CAP connection for the given device handle, updating state and invoking the status callback on failure. */
    u8 *device = lbl_803C3C38 + dev_handle * 0x34;
    u16 cid;
    u32 cbIndex;

    if (device[0x10] != 0)
        return 9;

    *(u16 *)(device + 0x14) = 0;
    *(u16 *)(device + 0x16) = 0;
    *(u16 *)(device + 0x1a) = 0x100;
    device[0x11] = 1;
    cid = L2CA_ConnectReq(0x11, device + 1);
    *(u16 *)(device + 0x14) = cid;

    if (cid == 0) {
        if (lbl_803C3C38[0x401] >= 2)
            fn_8007093C(0x1e0001, lbl_8031799C);
        cbIndex = (u32)((device - lbl_803C3C38) / 0x34) / 0x34U;
        ((void (*)(u8, u32, u8, void *))(*(void **)(lbl_803C3C38 + 0x340)))((u8)cbIndex, 1, 0xe, 0);
    } else {
        device[0x10] = 1;
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
    struct Callback10 { u32 f[10]; };
    u8 *messages = lbl_80317C20;
    void *entry;

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
    *(struct Callback10 *)((u8 *)entry + 4) = *(struct Callback10 *)info;
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

/* Higher layers call this to start an L2CAP connection to a PSM on a peer.
 * Nothing is connected when it returns: it looks up (or creates) the link
 * control block for the peer's BD_ADDR, kicks off the ACL link when there is
 * none, and allocates the channel control block whose local CID it returns.
 * The callbacks of the PSM's RCB report when the connection comes up or
 * fails. Returns that CID, or 0 when the connection could not be started. */
u16 L2CA_ConnectReq(u16 psm, u8 *p_bd_addr) {
    extern void *l2cu_find_rcb_by_psm(u16);
    extern void *l2cu_allocate_lcb(u8 *);
    extern void *l2cu_allocate_ccb(void *, u16);
    extern BOOLEAN l2cu_create_conn(void *);
    u8 *trace = lbl_80317C20; /* this file's L2CAP trace strings */
    tL2C_RCB_VIEW *p_rcb;
    tL2C_LCB_VIEW *p_lcb;
    tL2C_CCB_VIEW *p_ccb;

    if (l2cb_trace_level >= BT_TRACE_LEVEL_API) /* L2CA_ConnectReq() PSM: ... */
        fn_80070954(0x80002, trace + 0x110, psm);
    if (l2cb_trace_level >= BT_TRACE_LEVEL_API) /* ... and the peer's BD_ADDR */
        fn_800709CC(0x80002, trace + 0x130, p_bd_addr[0], p_bd_addr[1], p_bd_addr[2], p_bd_addr[3], p_bd_addr[4], p_bd_addr[5]);

    /* Fail if we have not established communications with the controller */
    if (!fn_80079514()) { /* BTM_IsDeviceUp() */
        if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* BTU not ready */
            fn_8007093C(0x80001, trace + 0x168);
        return 0;
    }

    /* Fail if the PSM is not registered */
    p_rcb = l2cu_find_rcb_by_psm(psm);
    if (p_rcb == 0) {
        if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* no RCB for this PSM */
            fn_80070954(0x80001, trace + 0x18c, psm);
        return 0;
    }

    /* First, see if we already have a link to the remote */
    p_lcb = l2cu_find_lcb_by_bd_addr(p_bd_addr);
    if (p_lcb == 0) {
        /* No link. Get an LCB and start link establishment */
        p_lcb = l2cu_allocate_lcb(p_bd_addr);
        if (p_lcb == 0) {
            if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* no LCB for L2CA_conn_req */
                fn_8007093C(0x80001, trace + 0x1bc);
            return 0;
        }
        if (!l2cu_create_conn(p_lcb))
            return 0;
    }

    /* A link that is on its way down cannot take another channel */
    if (p_lcb->link_state == LST_DISCONNECTING) {
        if (l2cb_trace_level >= BT_TRACE_LEVEL_API)
            fn_8007093C(0x80002, trace + 0x1e0);
        return 0;
    }

    /* Allocate a channel control block for the new channel; the CID to ask for
     * is 0 ("pick one"), which r4 already holds, so only the LCB is passed. */
    p_ccb = ((tL2C_CCB_VIEW *(*)(tL2C_LCB_VIEW *))l2cu_allocate_ccb)(p_lcb);
    if (p_ccb == 0) {
        if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* no CCB for L2CA_conn_req */
            fn_8007093C(0x80001, trace + 0x218);
        return 0;
    }

    /* Save registration info */
    p_ccb->p_rcb = p_rcb;

    /* If the link is already up, start the L2CAP connection now */
    if (p_lcb->link_state == LST_CONNECTED)
        fn_80089E40(p_ccb, L2CEVT_L2CA_CONNECT_REQ, 0); /* l2c_csm_execute() */

    if (l2cb_trace_level >= BT_TRACE_LEVEL_API) /* the CID the channel got */
        fn_80070954(0x80002, trace + 0x23c, p_ccb->local_cid);
    return p_ccb->local_cid;
}

BOOLEAN L2CA_ConnectRsp(BD_ADDR addr, UINT8 id, UINT16 lcid, UINT16 result, UINT16 status) {
    /* Handle an upper-layer L2CAP connect response by finding the link/channel and advancing the CCB state machine. */
    register u8 *logBase = lbl_80317C20;
    void *linkControlBlock;
    void *channelControlBlock;
    struct {
        u8 pad[0xA];
        s16 info[2];
    } resultData;
    u8 channelId;

    if (lbl_803C4040[0] >= 3)
        fn_80070984(0x80002, logBase + 0x26C);

    if (lbl_803C4040[0] >= 3)
        fn_800709CC(0x80002, logBase + 0x2A4,
                    addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

    linkControlBlock = l2cu_find_lcb_by_bd_addr(addr);
    if (linkControlBlock == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, logBase + 0x2DC);
        return 0;
    }

    channelControlBlock = l2cu_find_ccb_by_cid(linkControlBlock, lcid);
    if (channelControlBlock == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, logBase + 0x300);
        return 0;
    }

    channelId = *(u8 *)((u8 *)channelControlBlock + 0x36);
    if (channelId != id) {
        if (lbl_803C4040[0] >= 2)
            fn_8007096C(0x80001, logBase + 0x324, channelId, id);
        return 0;
    }

    if (result == 0) {
        fn_80089E40(channelControlBlock, 0x15, 0);
    } else {
        resultData.info[0] = result;
        resultData.info[1] = status;
        if (result == 1)
            fn_80089E40(channelControlBlock, 0x15, &resultData);
        else
            fn_80089E40(channelControlBlock, 0x16, &resultData);
    }
    return 1;
}

extern u8 lbl_80317F78[];
extern u8 lbl_80317F98[];
BOOLEAN L2CA_ConfigReq(UINT16 cid, tL2CAP_CFG_INFO *p_cfg) {
    void *channelControlBlock;
    if (lbl_803C4040[0] >= 3) {
        fn_80070954(0x80002, lbl_80317F78, cid);
    }
    channelControlBlock = l2cu_find_ccb_by_cid(NULL, cid);
    if (channelControlBlock == NULL) {
        if (lbl_803C4040[0] >= 2) {
            fn_80070954(0x80001, lbl_80317F98, cid);
        }
        return FALSE;
    }
    ((u8 *)p_cfg)[0x24] = 0;
    fn_80089E40(channelControlBlock, 0x17, p_cfg);
    return TRUE;
}

/* Send an upper-layer configuration response for a channel (L2CA_ConfigRsp). */
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
        fn_80089E40(p_ccb, L2CEVT_L2CA_CONFIG_RSP, p_cfg);
    else
        fn_80089E40(p_ccb, L2CEVT_L2CA_CONFIG_RSP_NEG, p_cfg);
    return TRUE;
}

/* Higher layers ask for an open L2CAP channel to be torn down with this
 * (l2c_api.c's L2CA_DisconnectReq): the channel's state machine is told the
 * upper layer wants it closed. FALSE when no channel has that CID. */
BOOLEAN L2CA_DisconnectReq(UINT16 cid)
{
    tL2C_CCB_VIEW *p_ccb;

    if (l2cb_trace_level >= BT_TRACE_LEVEL_API) /* "L2CA_DisconnectReq()  CID: 0x%04x" */
    {
        fn_80070954(TRACE_LAYER_L2CAP | TRACE_TYPE_API, lbl_8031801C, cid);
    }

    /* Find the channel control block. We don't know the link it is on. */
    p_ccb = l2cu_find_ccb_by_cid(NULL, cid);
    if (p_ccb == NULL) {
        if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* "L2CAP - no CCB for L2CA_disc_req, CID: %d" */
        {
            fn_80070954(TRACE_LAYER_L2CAP | TRACE_TYPE_WARNING, lbl_80318040, cid);
        }
        return FALSE;
    }

    fn_80089E40(p_ccb, L2CEVT_L2CA_DISCONNECT_REQ, NULL); /* l2c_csm_execute() */
    return TRUE;
}

/* Higher layers acknowledge that a channel is disconnected with this (l2c_api.c's
 * L2CA_DisconnectRsp): the channel's state machine is told the upper layer is
 * done with it. FALSE when no channel has that CID. */
BOOLEAN L2CA_DisconnectRsp(UINT16 cid)
{
    tL2C_CCB_VIEW *p_ccb;

    if (l2cb_trace_level >= BT_TRACE_LEVEL_API) /* "L2CA_DisconnectRsp()  CID: 0x%04x" */
    {
        fn_80070954(TRACE_LAYER_L2CAP | TRACE_TYPE_API, lbl_8031806C, cid);
    }

    /* Find the channel control block. We don't know the link it is on. */
    p_ccb = l2cu_find_ccb_by_cid(NULL, cid);
    if (p_ccb == NULL) {
        if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* "L2CAP - no CCB for L2CA_disc_rsp, CID: %d" */
        {
            fn_80070954(TRACE_LAYER_L2CAP | TRACE_TYPE_WARNING, lbl_80318090, cid);
        }
        return FALSE;
    }

    fn_80089E40(p_ccb, L2CEVT_L2CA_DISCONNECT_RSP, NULL); /* l2c_csm_execute() */
    return TRUE;
}

extern u8 lbl_80317C20[];
/* Higher layers call this to send data on an open L2CAP channel. The buffer is
 * handed to the channel's state machine, which owns it from here on; the answer
 * says whether the link the channel runs on is now congested. A buffer no
 * channel will take (no CCB for the CID, or bigger than the peer's MTU) is
 * freed here and the call fails. */
UINT8 L2CA_DataWrite(UINT16 lcid, BT_HDR *p_buf) {
    u8 *trace = lbl_80317C20; /* this file's L2CAP trace strings */
    tL2C_CCB_VIEW *p_ccb;

    if (l2cb_trace_level >= BT_TRACE_LEVEL_API) /* L2CA_DataWrite() CID: 0x%04x Len: %d */
        fn_8007096C(TRACE_LAYER_L2CAP | TRACE_TYPE_API, trace + 0x49C, lcid, p_buf->len);

    /* Find the channel control block; we don't know which link it is on. */
    p_ccb = l2cu_find_ccb_by_cid(NULL, lcid);
    if (p_ccb == NULL) {
        if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* no CCB for L2CA_DataWrite */
            fn_80070954(TRACE_LAYER_L2CAP | TRACE_TYPE_WARNING, trace + 0x4C4, lcid);
        GKI_freebuf(p_buf);
        return L2CAP_DW_FAILED;
    }

    if (p_buf->len <= p_ccb->peer_mtu) {
        fn_80089E40(p_ccb, L2CEVT_L2CA_DATA_WRITE, p_buf); /* l2c_csm_execute() */
        if (p_ccb->p_lcb->is_congested)
            return L2CAP_DW_CONGESTED;
        return L2CAP_DW_SUCCESS;
    }

    if (l2cb_trace_level >= BT_TRACE_LEVEL_WARNING) /* bigger than the peer's MTU */
        fn_8007093C(TRACE_LAYER_L2CAP | TRACE_TYPE_WARNING, trace + 0x4F0);
    GKI_freebuf(p_buf);
    return L2CAP_DW_FAILED;
}

/* Set the L2CAP idle timeout for a CID's link, or globally when requested. */
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
    extern u8 lbl_80560D48[6];
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
    entry += 0x64;
    if (entry[0] != 0 && *(s32 *)(entry + 4) == 4) *(u16 *)(entry + 0x58) = timeout;
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
extern void l2c_csm_term_w4_sec_comp(void *, s32, void *);
extern void l2c_csm_w4_l2cap_connect_rsp(tL2C_CCB_VIEW *, u16, void *);
extern void l2c_csm_w4_l2ca_connect_rsp(void *, u16, void *);
extern void *jumptable_803187D4[];
extern void l2c_csm_config(void *, u16, void *);
extern void l2c_csm_open(tL2C_CCB_VIEW *, u16, void *);
extern void l2c_csm_w4_l2cap_disconnect_rsp(void *, u16, void *);
extern void l2c_csm_w4_l2ca_disconnect_rsp(void *, u16, void *);
extern void *jumptable_803183B0[];
extern void l2cu_process_peer_cfg_req();
extern void l2cu_send_peer_config_rsp(tL2C_CCB_VIEW *, tL2CAP_CFG_INFO *);
extern void l2cu_send_peer_disc_req(void *);
extern void forward_peer_data(void *, void *);
extern void l2cu_process_our_cfg_req(void *, void *);
extern void l2cu_send_peer_config_req(tL2C_CCB_VIEW *, tL2CAP_CFG_INFO *);
extern void fn_8008EE40(void *, void *);
extern void fn_8008EF90(void *, void *);
void fn_80089E40(void *p_ccb, u8 event, void *p_data) {
    u32 state = *(u32 *)((u8 *)p_ccb + 4);
    switch (state) {
    case 0:
        l2c_csm_closed(p_ccb, event, p_data);
        break;
    case 1:
        l2c_csm_orig_w4_sec_comp(p_ccb, event, p_data);
        break;
    case 2:
        l2c_csm_term_w4_sec_comp(p_ccb, event, p_data);
        break;
    case 3:
        l2c_csm_w4_l2cap_connect_rsp((tL2C_CCB_VIEW *)p_ccb, event, p_data);
        break;
    case 4:
        l2c_csm_w4_l2ca_connect_rsp(p_ccb, event, p_data);
        break;
    case 5:
        l2c_csm_config(p_ccb, event, p_data);
        break;
    case 6:
        l2c_csm_open((tL2C_CCB_VIEW *)p_ccb, event, p_data);
        break;
    case 7:
        l2c_csm_w4_l2cap_disconnect_rsp(p_ccb, event, p_data);
        break;
    case 8:
        l2c_csm_w4_l2ca_disconnect_rsp(p_ccb, event, p_data);
        break;
    default:
        break;
    }
}

void l2c_csm_closed(void *p_ccb, u16 event, void *p_msg) {
    extern void l2c_link_sec_comp(BD_ADDR, void *, UINT8);
    char *p_str = (char *)jumptable_803183B0;
    void *p_rcb = *(void **)((u8 *)p_ccb + 0x30);
    void (*disconnect_ind)(u16, u8) = *(void (**)(u16, u8))((u8 *)p_rcb + 0x18);
    void (*connect_cfm)(u16, u8) = *(void (**)(u16, u8))((u8 *)p_rcb + 8);
    u16 local_cid = *(u16 *)((u8 *)p_ccb + 0x14);
    if (lbl_803C4040[0] >= 4) fn_80070954(0x80003, p_str + 0x24, event);
    switch (event) {
    case 0:
        if (lbl_803C4040[0] >= 3) fn_80070954(0x80002, p_str + 0x40, local_cid);
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, 0);
        break;
    case 1: {
        void *id = *(void **)((u8 *)p_ccb + 0x10);
        *(u32 *)((u8 *)p_ccb + 4) = 1;
        btm_sec_l2cap_access_req((u8 *)id + 0x2A, *(u16 *)((u8 *)id + 0x28), *(u16 *)((u8 *)(*(void **)((u8 *)p_ccb + 0x30)) + 2), 1, l2c_link_sec_comp, 0);
        break;
    }
    case 3: {
        void *id = *(void **)((u8 *)p_ccb + 0x10);
        u8 *addr = (u8 *)id + 0x2A;
        u16 psm = *(u16 *)((u8 *)id + 0x28);
        u16 h = *(u16 *)((u8 *)(*(void **)((u8 *)p_ccb + 0x30)) + 2);
        u8 r = btm_sec_l2cap_access_req(addr, psm, h, 1, l2c_link_sec_comp, 0);
        if ((u8)(r - 1) == 0) *(u32 *)((u8 *)p_ccb + 4) = 1;
        break;
    }
    case 7: {
        if (lbl_803C4040[0] >= 3) fn_8007096C(0x80002, p_str + 0x84, local_cid, *((u8 *)p_msg + 6));
        l2cu_release_ccb(p_ccb);
        connect_cfm(local_cid, *((u8 *)p_msg + 6));
        break;
    }
    case 8: {
        l2cu_send_peer_connect_req(p_ccb);
        *(u32 *)((u8 *)p_ccb + 4) = 3;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x3C);
        break;
    }
    case 9: {
        if (lbl_803C4040[0] >= 3) fn_8007096C(0x80002, p_str + 0x84, local_cid, 1);
        l2cu_release_ccb(p_ccb);
        connect_cfm(local_cid, 3);
        break;
    }
    case 10: {
        void *id = *(void **)((u8 *)p_ccb + 0x10);
        *(u32 *)((u8 *)p_ccb + 4) = 2;
        btm_sec_l2cap_access_req((u8 *)id + 0x2A, *(u16 *)((u8 *)id + 0x28), *(u16 *)((u8 *)(*(void **)((u8 *)p_ccb + 0x30)) + 2), 0, l2c_link_sec_comp, 0);
        break;
    }
    case 19: {
        if (lbl_803C4040[0] >= 3) fn_8007096C(0x80002, p_str + 0x84, local_cid, 1);
        l2cu_release_ccb(p_ccb);
        connect_cfm(local_cid, 1);
        break;
    }
    case 20: {
        if (lbl_803C4040[0] >= 3) fn_8007096C(0x80002, p_str + 0x84, local_cid, 1);
        l2cu_release_ccb(p_ccb);
        connect_cfm(local_cid, 1);
        break;
    }
    case 30:
        GKI_freebuf(p_msg);
        break;
    }
}

void l2c_csm_orig_w4_sec_comp(void *p_ccb, u16 event, void *p_data)
{
    /* Originator L2CAP channel state machine handler for "waiting for security
     * complete": logs the event, handles disconnect/security-complete/failure/
     * free/disconnect-abort cases, and updates CCB state/callbacks accordingly. */
    char *p_str = (char *)jumptable_803183B0;
    void *p_rcb = *(void **)((u8 *)p_ccb + 0x30);
    void (*disconnect_ind)(u16, u8) = *(void (**)(u16, u8))((u8 *)p_rcb + 0x18);
    void (*connect_cfm)(u16, u16) = *(void (**)(u16, u16))((u8 *)p_rcb + 8);
    u16 local_cid = *(u16 *)((u8 *)p_ccb + 0x14);

    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, p_str + 0x13C, event);

    switch (event) {
    case 3:
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x40, *(u16 *)((u8 *)p_ccb + 0x14));
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, 0);
        break;
    case 7:
        *(u32 *)((u8 *)p_ccb + 4) = 3;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x3C);
        l2cu_send_peer_connect_req(p_ccb);
        *((u8 *)p_ccb + 0x37) = 0;
        break;
    case 8:
        if (lbl_803C4040[0] >= 3)
            fn_8007096C(0x80002, p_str + 0x84, *(u16 *)((u8 *)p_ccb + 0x14), 5);
        l2cu_release_ccb(p_ccb);
        connect_cfm(local_cid, 5);
        break;
    case 20:
    case 29:
        GKI_freebuf(p_data);
        break;
    case 27:
        btm_sec_abort_access_req((u8 *)*(void **)((u8 *)p_ccb + 0x10) + 0x2A);
        l2cu_release_ccb(p_ccb);
        break;
    }
}

extern char lbl_80318580[];
extern char lbl_803185A8[];
extern void l2cu_send_peer_connect_rsp(void *, u16, u16);
extern void l2c_csm_closed(void *, u16, void *);
extern void l2c_csm_orig_w4_sec_comp(void *, u16, void *);
extern void l2c_csm_w4_l2ca_connect_rsp(void *, u16, void *);
extern void l2c_csm_config(void *, u16, void *);
extern void l2c_csm_w4_l2cap_disconnect_rsp(void *, u16, void *);
void l2c_csm_term_w4_sec_comp(void *p_ccb, s32 event, void *p_data)
{
    /* L2CAP CSM handler for terminator waiting-for-security-complete: logs the event and handles abort, security complete, reject, data free, timeout, and peer disconnect. */
    if (lbl_803C4040[0] >= 4) {
        ((void (*)(u32, void *, u32))fn_80070954)(0x80003, lbl_80318580, event);
    }
    switch (event) {
    case 3:
        btm_sec_abort_access_req((u8 *)*(void **)((u8 *)p_ccb + 0x10) + 0x2A);
        l2cu_release_ccb(p_ccb);
        break;
    case 7:
        *(u32 *)((u8 *)p_ccb + 4) = 4;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x3C);
        if (lbl_803C4040[0] >= 3) {
            fn_80070954(0x80002, lbl_803185A8, *(u16 *)((u8 *)p_ccb + 0x14));
        }
        {
            u8 *p_rcb = *(u8 **)((u8 *)p_ccb + 0x30);
            void (*connect_ind_cb)(void *, u16, u16, u8) = *(void (**)(void *, u16, u16, u8))(p_rcb + 4);
            connect_ind_cb((u8 *)*(void **)((u8 *)p_ccb + 0x10) + 0x2A,
               *(u16 *)((u8 *)p_ccb + 0x14), *(u16 *)(p_rcb + 2),
               *((u8 *)p_ccb + 0x36));
        }
        break;
    case 8:
        l2cu_send_peer_connect_rsp(p_ccb, 3, 0);
        l2cu_release_ccb(p_ccb);
        break;
    case 17:
        GKI_freebuf(p_data);
        break;
    case 19:
        l2cu_release_ccb(p_ccb);
        break;
    case 26:
        l2cu_send_peer_disc_rsp(*(void **)((u8 *)p_ccb + 0x10),
            *((u8 *)p_ccb + 0x36), *(u16 *)((u8 *)p_ccb + 0x14),
            *(u16 *)((u8 *)p_ccb + 0x16));
        btm_sec_abort_access_req((u8 *)*(void **)((u8 *)p_ccb + 0x10) + 0x2A);
        l2cu_release_ccb(p_ccb);
        break;
    case 29:
        break;
    }
}

extern char lbl_803183B0[];
/* L2CAP channel state machine, W4_L2CAP_CONNECT_RSP state (l2c_csm.c l2c_csm_w4_l2cap_connect_rsp):
 * we have sent the peer a connect request, so this waits for what ends the wait - the peer's
 * confirm (go to CONFIG and confirm to the upper layer), its "pending" answer (extend the timeout
 * and let the upper layer know), its rejection, the connect timeout, the link going away or the
 * upper layer giving up. */
void l2c_csm_w4_l2cap_connect_rsp(tL2C_CCB_VIEW *p_ccb, u16 event, void *p_msg)
{
    char *p_str = (char *)jumptable_803183B0;   /* l2c_csm.c's trace strings, after the CSM jump table */
    tL2C_RCB_VIEW *p_rcb = p_ccb->p_rcb;
    void (*disconnect_ind)(u16, u16) = p_rcb->pL2CA_DisconnectInd_Cb;
    void (*connect_cfm)(u16, u16) = p_rcb->pL2CA_ConnectCfm_Cb;
    u16 local_cid = p_ccb->local_cid;

    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, p_str + 0x294, event); /* "L2CAP - st: W4_L2CAP_CON_RSP evt: %d" */

    switch (event)
    {
    case L2CEVT_LP_DISCONNECT_IND:                      /* Link was disconnected */
        p_ccb->chnl_state = CST_CLOSED;
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x40, p_ccb->local_cid); /* "L2CAP - Calling Disconnect_Ind_Cb(), CID: 0x%04x  No Conf Needed" */
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, FALSE);
        break;

    case L2CEVT_L2CAP_CONNECT_RSP:                      /* Got peer connect confirm */
        p_ccb->remote_cid = ((tL2C_CONN_INFO *)p_msg)->remote_cid;
        p_ccb->chnl_state = CST_CONFIG;
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_TIMEOUT);
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x2bc, p_ccb->local_cid); /* trace: Calling Connect_Cfm_Cb(), Success */
        p_ccb->p_rcb->pL2CA_ConnectCfm_Cb(p_ccb->local_cid, L2CAP_CONN_OK);
        break;

    case L2CEVT_L2CAP_CONNECT_RSP_PND:                  /* Got peer connect pending */
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_CONNECT_TOUT_EXT);
        if (p_ccb->p_rcb->pL2CA_ConnectPnd_Cb)
        {
            if (lbl_803C4040[0] >= 3)
                fn_8007093C(0x80002, p_str + 0x2f4);    /* trace: Calling Connect_Pnd_Cb() */
            p_ccb->p_rcb->pL2CA_ConnectPnd_Cb(0);       /* @bug the channel's CID is not passed */
        }
        break;

    case L2CEVT_L2CAP_CONNECT_RSP_NEG:                  /* Peer rejected the connection */
        if (lbl_803C4040[0] >= 3)
            fn_8007096C(0x80002, p_str + 0x318, p_ccb->local_cid,
                        ((tL2C_CONN_INFO *)p_msg)->l2cap_result); /* trace: Connect_Cfm_Cb, Failure Code */
        l2cu_release_ccb(p_ccb);
        connect_cfm(local_cid, ((tL2C_CONN_INFO *)p_msg)->l2cap_result);
        break;

    case L2CEVT_TIMEOUT:                                /* Connect request timed out */
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x358, p_ccb->local_cid); /* trace: Connect_Cfm_Cb, Timeout */
        l2cu_release_ccb(p_ccb);
        connect_cfm(local_cid, L2CAP_CONN_TIMEOUT);
        break;

    case L2CEVT_L2CA_DISCONNECT_REQ:                    /* Upper wants to disconnect */
        l2cu_release_ccb(p_ccb);
        break;

    case L2CEVT_L2CAP_DATA:                             /* Peer data we cannot use yet */
    case L2CEVT_L2CA_DATA_WRITE:                        /* Upper layer data to send */
        GKI_freebuf(p_msg);
        break;
    }
}

/* L2CAP channel state machine, W4_L2CA_CONNECT_RSP state (l2c_csm.c's
 * l2c_csm_w4_l2ca_connect_rsp): the peer's connect request was passed up to the
 * upper layer with a connect indication, so this waits for what ends the wait -
 * the layer's answer, which is forwarded to the peer as our connect response
 * (OK/pending goes CONFIG, a rejection frees the channel), the link going away or
 * the connect timeout, both of which drop the channel and call the layer's
 * disconnect callback, and data that can only be freed here. */
void l2c_csm_w4_l2ca_connect_rsp(void *p_ccb, u16 event, void *p_data)
{
    extern char lbl_803183F0[];   /* "L2CAP - Calling Disconnect_Ind_Cb(), CID: 0x%04x  No Conf Needed" */
    tL2C_CCB_VIEW *ccb = (tL2C_CCB_VIEW *)p_ccb;
    void (*disconnect_ind)(u16, u16) = ccb->p_rcb->pL2CA_DisconnectInd_Cb;
    u16 local_cid = ccb->local_cid;

    if (l2cb_trace_level >= 4)
        fn_80070954(0x80003, lbl_803187B0, event); /* "L2CAP - st: W4_L2CA_CON_RSP evt: %d" */

    switch (event)
    {
    case L2CEVT_LP_DISCONNECT_IND:                  /* Link was disconnected */
        if (l2cb_trace_level >= 3)
            fn_80070954(0x80002, lbl_803183F0, ccb->local_cid);
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, FALSE);
        break;

    case L2CEVT_L2CA_CONNECT_RSP:                   /* Upper layer answered the connect indication */
        /* Result should be OK or PENDING */
        if (p_data == 0 || ((tL2C_CONN_INFO *)p_data)->l2cap_result == L2CAP_CONN_OK)
        {
            l2cu_send_peer_connect_rsp(p_ccb, L2CAP_CONN_OK, 0);
            ccb->chnl_state = CST_CONFIG;
            btu_start_timer(&ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_TIMEOUT);
        }
        else
        {
            /* If pending, stay in same state and start extended timer */
            l2cu_send_peer_connect_rsp(p_ccb, ((tL2C_CONN_INFO *)p_data)->l2cap_result,
                                       ((tL2C_CONN_INFO *)p_data)->l2cap_status);
            btu_start_timer(&ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_CONNECT_TOUT_EXT);
        }
        break;

    case L2CEVT_L2CA_CONNECT_RSP_NEG:               /* Upper layer rejected the connection */
        l2cu_send_peer_connect_rsp(p_ccb, ((tL2C_CONN_INFO *)p_data)->l2cap_result,
                                   ((tL2C_CONN_INFO *)p_data)->l2cap_status);
        l2cu_release_ccb(p_ccb);
        break;

    case L2CEVT_TIMEOUT:                            /* Upper layer took too long to answer */
        l2cu_send_peer_connect_rsp(p_ccb, L2CAP_CONN_NO_PSM, 0);
        if (l2cb_trace_level >= 3)
            fn_80070954(0x80002, lbl_803183F0, ccb->local_cid);
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, FALSE);
        break;

    case L2CEVT_L2CA_CONNECT_REQ:                   /* Upper layer wants to connect while we wait */
    case L2CEVT_L2CAP_DATA:                         /* Peer data packet rcvd */
        GKI_freebuf(p_data);
        break;

    case L2CEVT_L2CA_DISCONNECT_REQ:                /* Upper wants to disconnect */
        l2cu_send_peer_disc_req(p_ccb);
        ccb->chnl_state = CST_W4_L2CAP_DISCONNECT_RSP;
        btu_start_timer(&ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_TIMEOUT);
        break;
    }
}

void l2c_csm_config(void *p_ccb, u16 event, void *p_data)
{
    void *p_rcb = *(void **)((u8 *)p_ccb + 0x30);
    void (*disconnect_ind)(u16, u16) = *(void (**)(u16, u16))((u8 *)p_rcb + 0x18);
    u16 local_cid = *(u16 *)((u8 *)p_ccb + 0x14);
    char *p_str = (char *)jumptable_803183B0;

    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, p_str + 0x494, event);

    switch (event)
    {
    case 3:
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x40, *(u16 *)((u8 *)p_ccb + 0x14));
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, 0);
        break;

    case 14:
        if (((u8 (*)(void *, void *))l2cu_process_peer_cfg_req)(p_ccb, p_data))
        {
            if (lbl_803C4040[0] >= 3)
                fn_80070954(0x80002, p_str + 0x4B0, *(u16 *)((u8 *)p_ccb + 0x14));
            (*(void (**)(u16, void *))((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 0x10))(*(u16 *)((u8 *)p_ccb + 0x14), p_data);
        }
        else
        {
            l2cu_send_peer_config_rsp(p_ccb, p_data);
        }
        break;

    case 15:
        fn_8008EE40(p_ccb, p_data);
        *((u8 *)p_ccb + 0x34) |= 2;
        if (*((u8 *)p_ccb + 0x34) & 1)
        {
            *(u32 *)((u8 *)p_ccb + 4) = 6;
            fn_80070F90((u8 *)p_ccb + 0x18);
            forward_peer_data(p_ccb, 0);
        }
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x4E0, *(u16 *)((u8 *)p_ccb + 0x14));
        (*(void (**)(u16, void *))((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 0x14))(*(u16 *)((u8 *)p_ccb + 0x14), p_data);
        break;

    case 16:
        fn_80070F90((u8 *)p_ccb + 0x18);
        if (lbl_803C4040[0] >= 3)
            fn_8007096C(0x80002, p_str + 0x510, *(u16 *)((u8 *)p_ccb + 0x14), *(u16 *)p_data);
        (*(void (**)(u16, void *))((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 0x14))(*(u16 *)((u8 *)p_ccb + 0x14), p_data);
        break;

    case 17:
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        *(u32 *)((u8 *)p_ccb + 4) = 8;
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x54C, *(u16 *)((u8 *)p_ccb + 0x14));
        (*(void (**)(u16, u16))((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 0x18))(*(u16 *)((u8 *)p_ccb + 0x14), 1);
        break;

    case 23:
        l2cu_process_our_cfg_req(p_ccb, p_data);
        l2cu_send_peer_config_req(p_ccb, p_data);
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        break;

    case 24:
        fn_8008EF90(p_ccb, p_data);
        *((u8 *)p_ccb + 0x34) |= 1;
        if (*((u8 *)p_ccb + 0x34) & 2)
        {
            *(u32 *)((u8 *)p_ccb + 4) = 6;
            fn_80070F90((u8 *)p_ccb + 0x18);
            forward_peer_data(p_ccb, 0);
        }
        l2cu_send_peer_config_rsp(p_ccb, p_data);
        break;

    case 25:
        l2cu_send_peer_config_rsp(p_ccb, p_data);
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        break;

    case 26:
        l2cu_send_peer_disc_req(p_ccb);
        *(u32 *)((u8 *)p_ccb + 4) = 7;
        btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 0x18), 3, 0x1E);
        break;

    case 19:
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x58C, *(u16 *)((u8 *)p_ccb + 0x14));
        (*(void (**)(u16, void *))((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 0x24))(*(u16 *)((u8 *)p_ccb + 0x14), p_data);
        break;

    case 29:
        if (*((u8 *)p_ccb + 0x34) & 2)
            GKI_enqueue((BUFFER_Q *)((u8 *)p_ccb + 0x70), p_data);
        else
            GKI_freebuf(p_data);
        break;

    case 30:
        l2cu_send_peer_disc_req(p_ccb);
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x40, *(u16 *)((u8 *)p_ccb + 0x14));
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, 0);
        break;
    }
}

extern void l2cu_process_peer_cfg_req();
extern void l2cu_send_peer_config_rsp(tL2C_CCB_VIEW *, tL2CAP_CFG_INFO *);
extern void l2cu_send_peer_disc_req(void *);
extern void forward_peer_data(void *, void *);
extern void l2cu_process_our_cfg_req(void *, void *);
extern void l2cu_send_peer_config_req(tL2C_CCB_VIEW *, tL2CAP_CFG_INFO *);
/* L2CAP channel state machine, OPEN state (l2c_csm.c l2c_csm_open): the channel is up, so this
 * dispatches what the peer link layer (disconnect / QOS violation), the peer L2CAP (config request,
 * disconnect request, data) and the upper layer (disconnect, data write, config request) send it. */
void l2c_csm_open(tL2C_CCB_VIEW *p_ccb, u16 event, void *p_data)
{
    char *p_str = (char *)jumptable_803183B0;   /* l2c_csm.c's trace strings, after the CSM jump table */
    void (*disconnect_ind)(u16, u16) = p_ccb->p_rcb->pL2CA_DisconnectInd_Cb;
    u16 local_cid = p_ccb->local_cid;

    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, p_str + 0x628, event);   /* "L2CAP - st: OPEN evt: %d" */

    switch (event)
    {
    case L2CEVT_LP_DISCONNECT_IND:                    /* Link was disconnected */
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x40, p_ccb->local_cid); /* Disconnect_Ind, no conf needed */
        l2cu_release_ccb(p_ccb);
        disconnect_ind(local_cid, FALSE);
        break;

    case L2CEVT_LP_QOS_VIOLATION_IND:                 /* QOS violation */
    {
        tL2C_RCB_VIEW *p_rcb = p_ccb->p_rcb;
        void (*qos_violation_ind)(u8 *) = p_rcb->pL2CA_QoSViolationInd_Cb;
        if (qos_violation_ind != 0)
            qos_violation_ind(p_ccb->p_lcb->remote_bd_addr);
        break;
    }

    case L2CEVT_L2CAP_CONFIG_REQ:                     /* Peer config request */
    {
        tL2C_CHNL_STATE tempstate = p_ccb->chnl_state;
        u8 tempcfgdone = p_ccb->config_done;
        p_ccb->chnl_state = CST_CONFIG;
        p_ccb->config_done = 0;                       /* config_done &= ~CFG_DONE_MASK */
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_TIMEOUT);
        if (((u8 (*)(void *, void *))l2cu_process_peer_cfg_req)(p_ccb, p_data))
        {
            tL2C_RCB_VIEW *p_rcb = p_ccb->p_rcb;
            void (*config_ind)(u16, void *) = p_rcb->pL2CA_ConfigInd_Cb;
            config_ind(p_ccb->local_cid, p_data);
        }
        else  /* error in the peer's parameters: put the state back and answer it */
        {
            fn_80070F90(&p_ccb->timer_entry);         /* btu_stop_timer */
            p_ccb->chnl_state = tempstate;
            p_ccb->config_done = tempcfgdone;
            l2cu_send_peer_config_rsp(p_ccb, p_data);
        }
        break;
    }

    case L2CEVT_L2CAP_DISCONNECT_REQ:                 /* Peer disconnected request */
    {
        tL2C_RCB_VIEW *p_rcb;
        p_ccb->chnl_state = CST_W4_L2CA_DISCONNECT_RSP;
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_TIMEOUT);
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x54C, p_ccb->local_cid); /* Disconnect_Ind, conf needed */
        p_rcb = p_ccb->p_rcb;
        p_rcb->pL2CA_DisconnectInd_Cb(p_ccb->local_cid, TRUE);
        break;
    }

    case L2CEVT_L2CAP_DATA:                           /* Peer data packet rcvd */
    {
        tL2C_RCB_VIEW *p_rcb = p_ccb->p_rcb;
        p_rcb->pL2CA_DataInd_Cb(p_ccb->local_cid, p_data);
        break;
    }

    case L2CEVT_L2CA_DISCONNECT_REQ:                  /* Upper layer wants to disconnect */
        l2cu_send_peer_disc_req(p_ccb);
        p_ccb->chnl_state = CST_W4_L2CAP_DISCONNECT_RSP;
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_TIMEOUT);
        break;

    case L2CEVT_L2CA_DATA_WRITE:                      /* Upper layer data to send */
        *(u16 *)p_data = p_ccb->local_cid;            /* our CID heads the buffer for the link layer */
        forward_peer_data(p_ccb, p_data);
        break;

    case L2CEVT_L2CA_CONFIG_REQ:                      /* Upper layer config request */
        l2cu_process_our_cfg_req(p_ccb, p_data);
        l2cu_send_peer_config_req(p_ccb, p_data);
        p_ccb->chnl_state = CST_CONFIG;
        p_ccb->config_done = 0;
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_L2CAP_CHNL, L2CAP_CHNL_TIMEOUT);
        break;
    }
}

void l2c_csm_w4_l2cap_disconnect_rsp(void *p_ccb, u16 event, void *p_data) {
    char *p_str = (char *)jumptable_803183B0;
    void *p_lcb = *(void **)((u8 *)p_ccb + 0x30);
    void (*disc_cfm)(u16, u16) = *(void (**)(u16, u16))((u8 *)p_lcb + 0x1CU);
    void (*disc_ind)(u16, u8) = *(void (**)(u16, u8))((u8 *)p_lcb + 0x18U);
    u16 local_cid = *(u16 *)((u8 *)p_ccb + 0x14U);
    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, p_str + 0x6B0, event);
    if ((u16)(event - 3) > 0x1B)
        goto free_data;
    switch (event) {
    case 3:
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, p_str + 0x40, local_cid);
        l2cu_release_ccb(p_ccb);
        disc_ind(local_cid, 0);
        break;
    case 4: case 5: case 6: case 7: case 8: case 9: case 10:
    case 11: case 12: case 13: case 14: case 15: case 16:
        goto free_data;
    case 17:
        l2cu_send_peer_disc_rsp(*(void **)((u8 *)p_ccb + 0x10),
                                *((u8 *)p_ccb + 0x36),
                                local_cid,
                                *(u16 *)((u8 *)p_ccb + 0x16));
    case 18:
        l2cu_release_ccb(p_ccb);
        if (disc_cfm != 0) {
            if (lbl_803C4040[0] >= 3)
                fn_80070954(0x80002, p_str + 0x6D8, local_cid);
            disc_cfm(local_cid, 0);
        }
        break;
    case 19:
        l2cu_release_ccb(p_ccb);
        if (disc_cfm != 0) {
            if (lbl_803C4040[0] >= 3)
                fn_80070954(0x80002, p_str + 0x6D8, local_cid);
            disc_cfm(local_cid, 0xEEEE);
        }
        break;
    case 20: case 21: case 22: case 23: case 24: case 25:
    case 26: case 27: case 28: case 29: case 30:
        goto free_data;
    }
    return;
free_data:
    GKI_freebuf(p_data);
}

extern char lbl_80318B28[];
extern char lbl_803183F0[];
// L2CAP CSM handler for "waiting for local disconnect response": traces the event, sends peer
// disconnect response/releases CCB and/or notifies disconnect indication as required, or frees
// unexpected buffers (events 20/30), depending on event.
void l2c_csm_w4_l2ca_disconnect_rsp(void *p_ccb, u16 event, void *p_data)
{
    void *disconnect_ind;
    u16 local_cid;
    disconnect_ind = *(void **)((u8 *)(*(void **)((u8 *)p_ccb + 0x30)) + 0x18);
    local_cid = *(u16 *)((u8 *)p_ccb + 0x14);
    if (lbl_803C4040[0] >= 4)
        fn_80070954(0x80003, lbl_80318B28, event);
    switch (event)
    {
    case 3:
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, lbl_803183F0, *(u16 *)((u8 *)p_ccb + 0x14));
        l2cu_release_ccb(p_ccb);
        ((void (*)(u16, u8))disconnect_ind)(local_cid, 0);
        break;
    case 7:
        l2cu_send_peer_disc_rsp(*(void **)((u8 *)p_ccb + 0x10),
            *((u8 *)p_ccb + 0x36), *(u16 *)((u8 *)p_ccb + 0x14), *(u16 *)((u8 *)p_ccb + 0x16));
        if (lbl_803C4040[0] >= 3)
            fn_80070954(0x80002, lbl_803183F0, *(u16 *)((u8 *)p_ccb + 0x14));
        l2cu_release_ccb(p_ccb);
        ((void (*)(u16, u8))disconnect_ind)(local_cid, 0);
        break;
    case 8:
    case 9:
        l2cu_send_peer_disc_rsp(*(void **)((u8 *)p_ccb + 0x10),
            *((u8 *)p_ccb + 0x36), *(u16 *)((u8 *)p_ccb + 0x14), *(u16 *)((u8 *)p_ccb + 0x16));
        l2cu_release_ccb(p_ccb);
        break;
    case 20:
    case 30:
        GKI_freebuf(p_data);
        break;
    }
}

void forward_peer_data(void *arg0, void *arg1) {
    extern u8 lbl_80318BC0[];
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    register u8 *ctx = (u8 *)arg0;
    register BT_HDR *data = (BT_HDR *)arg1;
    register u8 *frame;
    register u8 *out;
    u16 count;
    u16 flags;
    void *lcb;
    if (data == 0)
        goto dequeue_initial;
    if (*(u16 *)(ctx + 0x78) == 0)
        goto dequeue_initial;
    GKI_enqueue((BUFFER_Q *)(ctx + 0x70), data);
    data = (BT_HDR *)GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
    goto initial_done;
dequeue_initial:
    if (data != 0)
        goto initial_done;
    data = (BT_HDR *)GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
initial_done:
    while (data != 0) {
        if (data->offset < 9) {
            if (lbl_803C4040[0] >= 1u)
                fn_80070954(0x80000u, lbl_80318BC0, data->offset);
            GKI_freebuf(data);
            data = (BT_HDR *)GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
            continue;
        }
        data->offset -= 8;
        frame = (u8 *)data + data->offset;
        out = frame + 10;
        data->len += 4;
        lcb = *(void **)(ctx + 0x10);
        flags = *(u16 *)((u8 *)lcb + 0x28) | 0x2000;
        frame[8] = flags;
        lcb = *(void **)(ctx + 0x10);
        flags = *(u16 *)((u8 *)lcb + 0x28) | 0x2000;
        frame[9] = flags >> 8;
        if (data->len > *(u16 *)(lbl_803C0A50 + 0x7C)) {
            out[0] = *(u16 *)(lbl_803C0A50 + 0x7C);
            out[1] = *(u16 *)(lbl_803C0A50 + 0x7C) >> 8;
        } else {
            out[0] = data->len;
            out[1] = data->len >> 8;
        }
        out += 2;
        count = data->len;
        out[0] = count - 4;
        out[1] = (count - 4) >> 8;
        out[2] = *(u16 *)(ctx + 0x16);
        out[3] = *(u16 *)(ctx + 0x16) >> 8;
        data->len += 4;
        ((void (*)(void *, u8, void *, u16))l2c_link_check_send_pkts)(*(void **)(ctx + 0x10), 0u, data, count);
        data = (BT_HDR *)GKI_dequeue((BUFFER_Q *)(ctx + 0x70));
    }
}

/* Handles an incoming HCI connection request: accept/reject and create or update the L2CAP link control block. */
void l2c_link_hci_conn_req(u8 *bd_addr)
{
    void *p_buf;
    tL2C_LCB_VIEW *p_lcb;
    p_buf = GKI_getpoolbuf(2);
    if (p_buf == 0)
        return;
    p_lcb = (tL2C_LCB_VIEW *)l2cu_find_lcb_by_bd_addr(bd_addr);
    if (p_lcb == 0) {
        p_lcb = (tL2C_LCB_VIEW *)l2cu_allocate_lcb(bd_addr);
        if (p_lcb == 0) {
            btsnd_hcic_reject_conn(p_buf, bd_addr, 0x14);
            if (lbl_803C4040[0] >= 1)
                fn_8007093C(0x80000, lbl_80318BE8);
        } else {
            p_lcb->link_role = fn_8008D7C4();
            btsnd_hcic_accept_conn(p_buf, bd_addr, p_lcb->link_role);
            p_lcb->link_state = 3;
            btu_start_timer(&p_lcb->timer_entry, 2, 0x3C);
        }
    } else {
        if (p_lcb->link_state == 3 || p_lcb->link_state == 1) {
            btsnd_hcic_accept_conn(p_buf, bd_addr, p_lcb->link_role);
            p_lcb->link_state = 3;
        } else if (p_lcb->link_state == 5) {
            btsnd_hcic_reject_conn(p_buf, bd_addr, 0x15);
        } else {
            if (lbl_803C4040[0] >= 1)
                fn_8007093C(0x80000, lbl_80318C08);
            GKI_freebuf(p_buf);
        }
    }
}

/*******************************************************************************
**
** Function         l2c_link_hci_conn_comp
**
** Description      Handles an HCI Connection Complete event: finds the link
**                  control block for the peer, records the connection handle,
**                  and runs every channel's state machine with the connect
**                  confirm (or connect confirm-neg) event.
**
*******************************************************************************/
BOOLEAN l2c_link_hci_conn_comp(UINT8 status, UINT16 handle, UINT8 *p_bda) {
    extern u8 lbl_80318C30[];
    extern u8 lbl_80318C58[];
    extern void l2cu_release_lcb(void *);
    extern void l2c_process_held_packets(u8 timed_out);
    extern void l2cu_send_peer_echo_req(void *p_lcb, u8 *p_data, s32 data_len);
    extern u8 l2cu_lcb_disconnecting(void);
    tL2C_LCB_VIEW *p_lcb;
    u8 *p_buf;
    u8 *next;
    u8 *p_dev;
    u8 ci[24];   /* a tL2C_CONN_INFO: bd_addr in [0..5], then status at [6] */

    /* Save the event parameters where the CSM callbacks can reach them. */
    *(volatile u8 *)&ci[6] = status;
    memcpy(ci, p_bda, 6);

    /* See if we have a link control block for the remote device. */
    p_lcb = l2cu_find_lcb_by_bd_addr(ci);
    if (p_lcb == 0) {
        /* fn_8007FEFC() looks the handle up; warn only when it is unknown. */
        if (!(u8)fn_8007FEFC(handle) && lbl_803C4040[0] >= 2) {
            fn_8007093C(0x80001, lbl_80318C30);   /* L2CAP_TRACE_WARNING0 */
        }
        return FALSE;
    }

    /* Only meaningful while the link is still connecting. */
    if (p_lcb->link_state != LST_CONNECTING) {
        if (lbl_803C4040[0] >= 1) {
            ((void (*)(u32, void *, s32, s32))fn_8007096C)(0x80000, lbl_80318C58, p_lcb->link_state, status);   /* L2CAP_TRACE_ERROR2 */
        }
        if (status != HCI_SUCCESS) {
            l2c_link_hci_disc_comp(p_lcb->handle, status);
        }
        return FALSE;
    }

    /* Save the handle. */
    p_lcb->handle = handle;
    if (ci[6] == HCI_SUCCESS) {
        /* Connected OK. Change state to connected. */
        p_lcb->link_state = LST_CONNECTED;
        /* Tell BTM ACL management about the link. */
        p_dev = (u8 *)btm_find_dev(p_bda);
        if (p_dev) {
            ((void (*)(u8 *, u8 *, u8 *, u16, u8))btm_acl_created)(ci, p_dev + 0x22, p_dev + 0x35, handle, p_lcb->link_role);
        } else {
            ((void (*)(u8 *, u8 *, u8 *, u16, u8))btm_acl_created)(ci, 0, 0, handle, p_lcb->link_role);
        }
        /* Update the timeouts in the hold queue and stop the connect timer. */
        l2c_process_held_packets(0);
        fn_80070F90(&p_lcb->timer_entry);   /* btu_stop_timer */
        /* For all channels, send the connect-confirm event through their FSMs. */
        for (p_buf = (u8 *)p_lcb->p_first_ccb; p_buf; p_buf = *(u8 **)(p_buf + 8)) {
            fn_80089E40(p_buf, L2CEVT_LP_CONNECT_CFM, ci);   /* l2c_csm_execute */
        }
        if (p_lcb->p_echo_rsp_cb != 0) {
            l2cu_send_peer_echo_req(p_lcb, 0, 0);
            btu_start_timer(&p_lcb->timer_entry, BTU_TTYPE_L2CAP_LINK, L2CAP_ECHO_RSP_TOUT);
        } else if (p_lcb->p_first_ccb == 0) {
            btu_start_timer(&p_lcb->timer_entry, BTU_TTYPE_L2CAP_LINK, L2CAP_LINK_STARTUP_TOUT);
        }
    } else if (ci[6] == HCI_ERR_MAX_NUM_OF_CONNECTIONS && l2cu_lcb_disconnecting()) {
        /* Max ACL connections: if one is dropping, hold this one instead. */
        p_lcb->link_state = LST_CONNECT_HOLDING;
        p_lcb->handle = HCI_INVALID_HANDLE;
    } else {
        /* Connection failed: send connect-confirm-neg through each channel's
           FSM (they remove themselves), then release the LCB. */
        for (p_buf = (u8 *)p_lcb->p_first_ccb; p_buf; p_buf = next) {
            next = *(u8 **)(p_buf + 8);
            fn_80089E40(p_buf, L2CEVT_LP_CONNECT_CFM_NEG, ci);   /* l2c_csm_execute */
        }
        l2cu_release_lcb(p_lcb);
    }
    return TRUE;
}

void l2c_link_sec_comp(BD_ADDR bd_addr, void *ref_data, UINT8 status)
{
    u8 ci[7];
    void *lcb;
    void *ccb;
    void *next;
    s8 event;
    ci[6] = status;
    memcpy(ci, bd_addr, 6);
    lcb = l2cu_find_lcb_by_bd_addr(bd_addr);
    if (lcb == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_80318C8C);
    } else {
        event = -(status == 0);
        ccb = *(void **)((u8 *)lcb + 8);
        while (ccb != 0) {
            next = *(void **)((u8 *)ccb + 8);
            fn_80089E40(ccb, (u8)(event + 8), ci);
            ccb = next;
        }
    }
}

extern void *l2cu_find_lcb_by_handle(u16);
extern void *l2cu_find_lcb_by_state(s32);
extern BOOLEAN l2cu_create_conn(void *);
extern void l2cu_release_lcb(void *);
extern void btm_sco_acl_removed(u8 *);
/* Handles HCI disconnect complete for an L2CAP link: notifies channels, cleans up the link, and starts any pending connection. */
BOOLEAN l2c_link_hci_disc_comp(UINT16 handle, UINT8 reason) {
    u8 *p_link_cb;
    BOOLEAN disconnectHandled = TRUE;
    u8 *p_next_channel_cb;
    u8 *p_channel_cb;
    UINT8 disconnectReason = reason;

    p_link_cb = (u8 *)l2cu_find_lcb_by_handle(handle);
    if (p_link_cb == 0) {
        disconnectHandled = FALSE;
    } else {
        if (lbl_803C0F78[0x27BF] != 0x0E)
            lbl_803C0F78[0x27BF] = disconnectReason;

        p_channel_cb = *(u8 **)(p_link_cb + 8);
        while (p_channel_cb != 0) {
            p_next_channel_cb = *(u8 **)(p_channel_cb + 8);
            fn_80089E40(p_channel_cb, 3, &disconnectReason);
            p_channel_cb = p_next_channel_cb;
        }

        btm_sco_acl_removed(p_link_cb + 0x2A);
        l2cu_release_lcb(p_link_cb);
    }

    p_link_cb = (u8 *)l2cu_find_lcb_by_state(1);
    if (p_link_cb != 0)
        l2cu_create_conn(p_link_cb);

    return disconnectHandled;
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
    /* Handle an L2CAP link timeout: flush queued packets and release the link in terminal states, or complete disconnect processing (callback/trace, security disconnect timer, or send pending packets). */
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
    /* Send an L2CAP buffer to the lower layer, fragmenting and accounting credits when needed. */
    u16 bufLen = *(u16 *)((u8 *)p_buf + 2);
    u16 maxLen = *(u16 *)(lbl_803C0A50 + 0x7E);
    if (bufLen <= maxLen) {
        --*(u16 *)((u8 *)p_lcb + 0x36);
        ++*(u16 *)((u8 *)p_lcb + 0x38);
        --*(u16 *)(lbl_803C4040 + 4);
        fn_8007079C(p_buf, 0x2100);
    } else {
        u16 controllerCredits;
        u16 numPackets;
        u16 mtu;
        u16 linkCredits;
        mtu = *(u16 *)(lbl_803C0A50 + 0x7C);
        numPackets = (bufLen + mtu - 5) / mtu;
        controllerCredits = *(u16 *)(lbl_803C4040 + 4);
        if (numPackets > controllerCredits) {
            *(u16 *)((u8 *)p_buf + 6) = controllerCredits;
            numPackets = controllerCredits;
            *((u8 *)p_lcb + 0x40) = 1;
        }
        linkCredits = *(u16 *)((u8 *)p_lcb + 0x36);
        if (numPackets > linkCredits) {
            *(u16 *)((u8 *)p_buf + 6) = linkCredits;
            numPackets = linkCredits;
            *((u8 *)p_lcb + 0x40) = 1;
        }
        *(u16 *)(lbl_803C4040 + 4) -= numPackets;
        *(u16 *)((u8 *)p_lcb + 0x36) -= numPackets;
        *(u16 *)((u8 *)p_lcb + 0x38) += numPackets;
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
            if (head != 0 && *(u16 *)(head + 6) == 0 && p_lcb[0x40] == 0) {
                p_buf = (u8 *)GKI_dequeue((BUFFER_Q *)(p_lcb + 0x44));
                if (p_buf != 0 && (u8)l2c_link_send_to_lower(arg0, p_buf) != 0 && *(u16 *)(global + 4) != 0 && *(u16 *)(p_lcb + 0x36) != 0)
                    continue;
            }
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
/* Recompute L2CAP link transmit allocations and flow-control thresholds for all
 * active link control blocks based on the current scheduler divisor/state. */
void l2c_link_adjust_allocation(void) {
    u8 *base = lbl_803C4040;
    u16 num_active_links = *(u16 *)(base + 0x7B8);
    u8 *loopBase;
    u32 lcb_index;
    u8 *lcb;
    u16 fair_allocation;
    s32 active_link_count = 0;
    u16 high_watermark;

    if (num_active_links == 0)
        return;
    /* Count LCBs that are both present and in the active transmission state. */
    if (base[8] != 0 && base[0x62] == 1)
        active_link_count = 1;
    if (base[0x64] != 0 && base[0xBE] == 1)
        active_link_count++;
    if (base[0xC0] != 0 && base[0x11A] == 1)
        active_link_count++;
    if (base[0x11C] != 0 && base[0x176] == 1)
        active_link_count++;

    loopBase = lbl_803C4040;
    fair_allocation = *(u16 *)(loopBase + 2) / num_active_links + 1;
    lcb = loopBase + 8;
    for (lcb_index = 0; lcb_index < 4; lcb_index++, lcb += 0x5C) {
        if (lcb[0] != 0) {
            /* Inactive/idle links get a small fixed quota; active links share fairly. */
            if (active_link_count == 0 || lcb[0x5A] == 1) {
                *(u16 *)(lcb + 0x34) = fair_allocation;
                *(u16 *)(lcb + 0x36) = fair_allocation;
            } else {
                *(u16 *)(lcb + 0x34) = 3;
                *(u16 *)(lcb + 0x36) = 3;
            }
            high_watermark = *(u16 *)(lcb + 0x34) * 120 / 100;
            *(u16 *)(lcb + 0x3A) = high_watermark;
            *(u16 *)(lcb + 0x3C) = high_watermark > 3 ? high_watermark - 3 : 0;
            *(u16 *)(lcb + 0x3E) = high_watermark + 2;
            if (*(u8 *)lbl_803C4040 >= 5)
                ((void (*)(u32, void *, u16, u8, u16, u16, u16, u16))fn_800709CC)(
                    0x80004, lbl_80318D98, (u16)lcb_index, lcb[0x5A],
                    *(u16 *)(lcb + 0x36), *(u16 *)(lcb + 0x3A),
                    *(u16 *)(lcb + 0x3C), *(u16 *)(lcb + 0x3E));
        }
    }
}

/* Process HCI Number Of Completed Packets event: update each LCB's completed/
 * sent packet counts and total controller completed count, then trigger sends. */
void l2c_link_process_num_completed_pkts(u8 *p, u16 evt_len) {
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    u8 numHandles = p[0];
    u8 i = 0;
    u8 *entry = p + 1;
    u16 zero = 0;

    while (i < numHandles) {
        u16 handle = (u16)(entry[0] + (entry[1] << 8));
        u16 numCompleted = (u16)(entry[2] + (entry[3] << 8));
        void *lcb;
        u32 pendingCount;

        entry += 4;
        lcb = l2cu_find_lcb_by_handle(handle);
        if (lcb != 0) {
            pendingCount = *(u16 *)((u8 *)lcb + 0x36) + numCompleted;
            *(u16 *)((u8 *)lcb + 0x36) = pendingCount;
            if ((u16)pendingCount > *(u16 *)((u8 *)lcb + 0x34))
                *(u16 *)((u8 *)lcb + 0x36) = *(u16 *)((u8 *)lcb + 0x34);
            if (*(u16 *)((u8 *)lcb + 0x38) > numCompleted)
                *(u16 *)((u8 *)lcb + 0x38) -= numCompleted;
            else
                *(u16 *)((u8 *)lcb + 0x38) = zero;
            *(u16 *)(lbl_803C4040 + 4) += numCompleted;
            ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(lcb, 0, 0);
        }
        i++;
    }
}

void fn_8008C04C(s16 arg0) {
    *(s16 *)(lbl_803C4040 + 2) = arg0;
    *(s16 *)(lbl_803C4040 + 4) = arg0;
}

BT_HDR *l2cap_link_chk_pkt_start(BT_HDR *p_cur_buf) {
    extern char lbl_80318DE0[];
    extern char lbl_80318E00[];
    extern void fn_8007093C(u32, void *);
    u8 *p;
    u16 handle;
    u16 hci_len;
    u16 pkt_type;
    u8 *p_lcb;
    BT_HDR *p_return_buf;

    p = (u8 *)p_cur_buf + p_cur_buf->offset;
    p_cur_buf->layer_specific = 0;
    handle = p[8] + (p[9] << 8);
    hci_len = p[10] + (p[11] << 8);
    pkt_type = (handle >> 12) & 3;
    handle &= 0x0FFF;
    *(void **)(lbl_803C4040 + 0x7BC) = 0;
    p_lcb = (u8 *)l2cu_find_lcb_by_handle(handle);
    if (p_lcb == 0)
        return p_cur_buf;

    if (pkt_type == 2) {
        if (*(void **)(p_lcb + 0x50) != 0) {
            if (lbl_803C4040[0] >= 2)
                fn_8007093C(0x80001, lbl_80318DE0);
            GKI_freebuf(*(void **)(p_lcb + 0x50));
        }
        p_return_buf = p_cur_buf;
        *(BT_HDR **)(p_lcb + 0x50) = p_return_buf;
        *(void **)(lbl_803C4040 + 0x7BC) = p_lcb;
    } else if (*(void **)(p_lcb + 0x50) != 0) {
        u16 total_len;
        BT_HDR *p_base_buf = *(BT_HDR **)(p_lcb + 0x50);
        u8 *p_f = (u8 *)p_base_buf + p_base_buf->offset;

        total_len = p_f[10] + (p_f[11] << 8);
        if (total_len + hci_len <= 0x69F) {
            p_return_buf = *(BT_HDR **)(p_lcb + 0x50);
            *(void **)(lbl_803C4040 + 0x7BC) = p_lcb;
            if (p_cur_buf->len > 4) {
                u16 cur_len = p_cur_buf->len;
                u16 base_offset = p_return_buf->offset;
                s32 copy_len = cur_len - 4;
                u16 cur_offset = p_cur_buf->offset;
                u8 *p_dst = (u8 *)p_return_buf + base_offset;
                u16 base_len = p_return_buf->len;
                u8 *p_data = (u8 *)p_cur_buf + cur_offset;
                p_dst += base_len + 8;
                p_data += 0xC;
                memcpy(p_dst, p_data, copy_len);
                p_return_buf->len += p_cur_buf->len - 4;
            }
            GKI_freebuf(p_cur_buf);
            total_len += hci_len;
            p_f[10] = (u8)total_len;
            p_f[11] = (u8)(total_len >> 8);
        } else {
            if (lbl_803C4040[0] >= 2)
                fn_8007093C(0x80001, lbl_80318E00);
            GKI_freebuf(*(void **)(p_lcb + 0x50));
            *(void **)(p_lcb + 0x50) = 0;
            p_return_buf = 0;
        }
    } else {
        p_return_buf = 0;
    }

    if (p_return_buf == 0)
        GKI_freebuf(p_cur_buf);
    return p_return_buf;
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
    /* Handle completion of a transmitted ACL segment: requeue for connected LCB or free on unknown/non-connected. */
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
    typedef struct { u8 _a[8]; void *p_next; u8 _b[0x70]; } CcbEnt;
    typedef struct { u8 _h[0x178]; CcbEnt pool[10]; u8 _rcb[0x160]; void *p_first; void *p_last; u16 num_links; u16 idle; } L2cbView;
    /* Initialize the global L2CAP control block and free CCB pool. */
    memset(lbl_803C4040, 0, 0x7E8);
    {
        L2cbView *cb = (L2cbView *)lbl_803C4040;
        INT16 index;
        for (index = 0; index < 9; index++) {
            cb->pool[index].p_next = &cb->pool[index + 1];
        }
        cb->p_first = &cb->pool[0];
        cb->p_last = &cb->pool[9];
        ((u8 *)cb)[1] = 0;
        cb->idle = 2;
        lbl_803C4040[0] = 0;
    }
}

void l2c_rcv_acl_data(register BT_HDR *arg0) {
    extern char lbl_80318E58[];
    extern void process_l2cap_cmd(void *, UINT8 *, UINT16);
    u8 *data;
    register char *trace;
    s32 temp_r26;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r28;
    register u32 temp_r0_3;
    u32 temp_r0_4;
    u32 temp_r24;
    register u16 temp_r25;
    s32 temp_r4;
    u32 temp_r0;
    register u32 temp_r28;

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
    if (temp_r24 > 2) {
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
    if (temp_r24 == 1) {
        process_l2cap_cmd((void *)temp_r3, data + 16, temp_r25);
        GKI_freebuf(arg0);
        return;
    }
    if (temp_r24 == 2) {
        arg0->offset = (u16)(temp_r0_4 + 2);
        arg0->len = temp_r4 - 2;
        if (lbl_803C4040[0] >= 5)
            fn_80070954(0x80004, trace + 0xE0,
                (u16)(data[16] + (data[17] << 8)));
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

extern char lbl_80315088[];
extern char lbl_8031912C[];
extern char lbl_80319140[];
extern void l2c_process_held_packets(u8 timed_out);
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

void l2c_process_held_packets(u8 timed_out) {
    BT_HDR *buf;
    BT_HDR *next;
    BUFFER_Q *queue = (BUFFER_Q *)(lbl_803C4040 + 0x7C0);

    if (*(u16 *)(lbl_803C4040 + 0x7C8) == 0)
        return;
    if (timed_out == 0) {
        fn_80070F90(lbl_803C4040 + 0x7CC);
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_8031912C);
    } else if (lbl_803C4040[0] >= 2) {
        fn_8007093C(0x80001, lbl_80319140);
    }

    buf = (BT_HDR *)fn_8006DF60((s32 *)queue);
    while (buf != 0) {
        next = (BT_HDR *)fn_8006DF68((s32 *)buf);
        if (timed_out == 0 || buf->layer_specific == 0 || --buf->layer_specific == 0) {
            GKI_remove_from_queue(queue, buf);
            buf->layer_specific = 0xFFFF;
            l2c_rcv_acl_data(buf);
        }
        buf = next;
    }
    if (*(u16 *)((u8 *)queue + 8) != 0)
        btu_start_timer((TIMER_LIST_ENT *)(lbl_803C4040 + 0x7CC), 4, 1);
}

/* One entry of l2cb's LCB pool (l2c_int.h's tL2C_LCB, as this older stack lays it
 * out), sized the way the pool lays them out: 0x5C bytes each, MAX_L2CAP_LINKS of
 * them at l2cb + 8.  Only l2cu_allocate_lcb() uses this view of it, so the field
 * names live here rather than in tL2C_LCB_VIEW, whose layout the rest of the unit
 * is compiled against. */
typedef struct {
    u8      in_use;             /* +0x00  TRUE once the entry was handed out */
    u8      pad_01[3];
    s32     link_state;         /* +0x04  a LST_* link state */
    void   *p_first_ccb;        /* +0x08  first channel on this link */
    u8      pad_0C[4];
    TIMER_LIST_ENT timer_entry; /* +0x10  the link's timeout entry; .param points back here */
    u16     handle;             /* +0x28  ACL connection handle, used with the LM */
    u8      remote_bd_addr[6];  /* +0x2A  the peer's Bluetooth address */
    u8      link_role;          /* +0x30  master or slave */
    u8      id;                 /* +0x31  identifier of the next command we send */
    u16     link_flush_tout;    /* +0x32  flush timeout in use */
    u8      pad_34[4];
    u16     link_xmit_quota;    /* +0x38  packets we may still send; l2c_link_adjust_allocation() sets it */
    u8      pad_3A[7];
    u8      is_congested;       /* +0x41  transmit queue is at or over its quota */
    u8      pad_42[0xE];
    void   *p_pending_rx_buf;   /* +0x50  a segmented SDU waiting for the rest of it */
    void   *p_echo_rsp_cb;      /* +0x54  echo response callback, NULL when none is set */
    u16     idle_timeout;       /* +0x58  seconds this link may stay idle */
    u8      pad_5A[2];
} tL2C_LCB_ENTRY;

/* Entries in l2cb's LCB pool: MAX_L2CAP_LINKS as this build was configured.  The
 * bt_target.h shipped with the headers says 7, which is newer than this stack. */
#define L2C_LCB_POOL_SIZE 4

/* l2cu_allocate_lcb(): look for a free entry in l2cb's LCB pool, clear it and set the
 * fields every LCB starts with for a connection to p_bd_addr, then let
 * l2c_link_adjust_allocation() share the link buffers out again.  Returns the LCB, or
 * NULL when all of them are in use. */
void *l2cu_allocate_lcb(BD_ADDR p_bd_addr) {
    tL2C_LCB_ENTRY *p_lcb;
    u16 numLinksActive;
    s32 xx;
    for (xx = 0, p_lcb = (tL2C_LCB_ENTRY *)(lbl_803C4040 + 8); xx < L2C_LCB_POOL_SIZE; xx++, p_lcb++) {
        if (p_lcb->in_use == 0) {
            memset(p_lcb, 0, sizeof(tL2C_LCB_ENTRY));
            p_lcb->in_use = TRUE;
            memcpy(p_lcb->remote_bd_addr, p_bd_addr, BD_ADDR_LEN);
            p_lcb->link_state = LST_DISCONNECTED;
            p_lcb->handle = HCI_INVALID_HANDLE;
            p_lcb->p_pending_rx_buf = 0;
            p_lcb->link_flush_tout = HCI_INVALID_HANDLE;
            p_lcb->timer_entry.param = (TIMER_PARAM_TYPE)p_lcb;
            p_lcb->link_xmit_quota = 0;   /* until the LM tells us our quota */
            p_lcb->idle_timeout = l2cb_idle_timeout;
            p_lcb->id = 0;                /* the first command sent pre-increments it */
            numLinksActive = l2cb_num_links_active;
            l2cb_num_links_active = numLinksActive + 1;
            l2c_link_adjust_allocation();
            return p_lcb;
        }
    }
    return 0;
}

extern void *GKI_dequeue(BUFFER_Q *);
extern void btm_remove_sco_links(u8 *);
extern void btm_acl_removed(u8 *);
extern void l2c_link_adjust_allocation(void);
/* Release an L2CAP link control block: stop its timer, free any partial RX/queued TX buffers, release attached CCBs, remove SCO/ACL tracking, adjust controller buffer accounting, and invoke the echo-response callback if set. */
void l2cu_release_lcb(void *arg0) {
    u8 *p_lcb = (u8 *)arg0;
    void *p_buf;
    void *p_ccb;
    u16 old_num_lm_acl_bufs;
    void (*p_echo_rsp_cb)(u8);

    p_lcb[0] = 0;
    fn_80070F90(p_lcb + 0x10);

    p_buf = *(void **)(p_lcb + 0x50);
    if (p_buf != 0) {
        GKI_freebuf(p_buf);
        *(void **)(p_lcb + 0x50) = 0;
    }

    btm_remove_sco_links(p_lcb + 0x2A);

    p_ccb = *(void **)(p_lcb + 8);
    while (p_ccb != 0) {
        l2cu_release_ccb(p_ccb);
        p_ccb = *(void **)(p_lcb + 8);
    }

    if (*(u32 *)(p_lcb + 4) - 4 <= 1) {
        btm_acl_removed(p_lcb + 0x2A);
    }

    while (*(void **)(p_lcb + 0x44) != 0) {
        p_buf = GKI_dequeue((BUFFER_Q *)(p_lcb + 0x44));
        GKI_freebuf(p_buf);
    }

    if (*(u16 *)(lbl_803C4040 + 0x7B8) >= 1) {
        *(u16 *)(lbl_803C4040 + 0x7B8) -= 1;
    }

    old_num_lm_acl_bufs = *(u16 *)(lbl_803C4040 + 4);
    *(u16 *)(lbl_803C4040 + 4) = old_num_lm_acl_bufs + *(u16 *)(p_lcb + 0x38);
    ((void (*)(u16, void *))l2c_link_adjust_allocation)(old_num_lm_acl_bufs, lbl_803C4040);

    p_echo_rsp_cb = *(void (**)(u8))(p_lcb + 0x54);
    if (p_echo_rsp_cb != 0) {
        *(void (**)(u8))(p_lcb + 0x54) = 0;
        p_echo_rsp_cb(1);
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

/* Build an L2CAP signaling command header in a command-pool buffer. */
void *l2cu_build_header(u16 arg0, u8 arg1, u8 arg2, s32 arg3) {
    void *buf = GKI_getpoolbuf(2);
    u8 *p;
    u16 payloadLen = arg1;

    if (buf == NULL) {
        return NULL;
    }

    /* BT_HDR: offset/len */
    *(u16 *)((u8 *)buf + 4) = 0;
    *(u16 *)((u8 *)buf + 2) = (u16)(arg1 + 0xC);

    p = (u8 *)buf + 8;
    p[0] = (u8)(arg0 | 0x2000);
    p[1] = (u8)((arg0 | 0x2000) >> 8);
    p[2] = (u8)(arg1 + 8);
    p[3] = (u8)((arg1 + 8) >> 8);
    p[4] = (u8)(arg1 + 4);
    p[5] = (u8)((arg1 + 4) >> 8);
    p[6] = 1;
    p[7] = 0;
    p[8] = arg2;
    p[9] = (u8)arg3;
    p[10] = arg1;
    p[11] = (u8)(payloadLen >> 8);

    return buf;
}

extern char lbl_80319158[];
void l2cu_send_peer_cmd_reject(void *arg0, u16 arg1, u8 arg2, u16 arg3, u16 arg4) {
    u16 size;
    void *packet;
    u8 *p;
    if (arg1 == (u16)1) {
        size = (u16)2;
    } else {
        size = (u16)(((s32)~((arg1 - 2) | (2 - arg1)) >> 31) & 4);
    }
    packet = ((void *(*)(u16, u16, u8, s32))l2cu_build_header)(
        *(u16 *)((u8 *)arg0 + 0x28), (u16)(size + 2), (u8)1, arg2);
    if (packet == (void *)0) {
        if (lbl_803C4040[0] >= 2) {
            fn_8007093C(0x80001, lbl_80319158);
        }
    } else {
        ((u8 *)packet)[0x14] = (u8)arg1;
        ((u8 *)packet)[0x15] = (u8)(arg1 >> 8);
        p = (u8 *)packet + 0x16;
        if (size >= (u16)2) {
            p[0] = (u8)arg3;
            p[1] = (u8)(arg3 >> 8);
            p += 2;
        }
        if (size >= (u16)4) {
            p[0] = (u8)arg4;
            p[1] = (u8)(arg4 >> 8);
        }
        ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(arg0, 0, packet);
    }
}

void l2cu_send_peer_connect_req(void *p_ccb) {
    /* Send an L2CAP connection request for the given channel control block. */
    UINT8 id;
    void *p_buf;
    u8 *p_lcb;
    p_lcb = *(u8 **)((u8 *)p_ccb + 0x10);
    id = *(u8 *)(p_lcb + 0x31) + 1;
    *(u8 *)(p_lcb + 0x31) = id;
    *(volatile u8 *)((u8 *)p_ccb + 0x35) = id;
    p_buf = l2cu_build_header(*(u16 *)(*(u8 * volatile *)((u8 *)p_ccb + 0x10) + 0x28), 4, 2, id);
    if (p_buf == NULL) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_80319174);
    } else {
        *(u8 *)((u8 *)p_buf + 0x14) = *(u16 *)((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 2);
        *(u8 *)((u8 *)p_buf + 0x15) = *(u16 *)((u8 *)*(void **)((u8 *)p_ccb + 0x30) + 2) >> 8;
        *(u8 *)((u8 *)p_buf + 0x16) = *(u16 *)((u8 *)p_ccb + 0x14);
        *(u8 *)((u8 *)p_buf + 0x17) = *(u16 *)((u8 *)p_ccb + 0x14) >> 8;
        ((void (*)(void *, void *, void *))l2c_link_check_send_pkts)(*(u8 **)((u8 *)p_ccb + 0x10), NULL, p_buf);
    }
}

void l2cu_send_peer_connect_rsp(void *p_ccb, u16 result, u16 status) {
    /* Send L2CAP connection response (cmd 3) with local/remote CIDs, result, and status. */
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
    u8 *packet;
    void *p_buf;

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
    packet[0x19] = (result) >> 8;
    packet[0x1A] = 0;
    packet[0x1B] = 0;
    ((void (*)(void *, u8, void *, s32, u8))l2c_link_check_send_pkts)(
        p_lcb, 0, p_buf, ((s32)remote_cid) >> 8, 0);
}

/* Build and send an L2CAP "configuration request" message to the peer, asking
   it to accept the options p_cfg holds for this channel. */
void l2cu_send_peer_config_req(tL2C_CCB_VIEW *p_ccb, tL2CAP_CFG_INFO *p_cfg)
{
    extern char lbl_80319174[];           /* "L2CAP - no buffer for conn_req" */
    extern void fn_8007093C(u32, void *); /* the stack's LogMsg_0() */
    tL2C_LCB_VIEW *p_lcb;
    void *p_buf;
    u8 *p;
    u16 cfg_len;

    cfg_len = 0;

    /* Create an identifier for this packet */
    p_lcb = p_ccb->p_lcb;
    p_lcb->id += 1;
    p_ccb->local_id = p_lcb->id;

    /* How much option data the request carries. */
    if (p_cfg->mtu_present)
        cfg_len = L2CAP_CFG_MTU_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
    if (p_cfg->flush_to_present)
        cfg_len += L2CAP_CFG_FLUSH_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
    if (p_cfg->qos_present)
        cfg_len += L2CAP_CFG_QOS_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
    if (p_cfg->fcr_present)
        cfg_len += L2CAP_CFG_FCR_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;

    /* l2cu_build_header() takes the option data's length as a UINT16. */
    p_buf = ((void *(*)(u16, u16, u8, u8))l2cu_build_header)(
        p_ccb->p_lcb->handle, cfg_len + L2CAP_CONFIG_REQ_LEN, L2CAP_CMD_CONFIG_REQ,
        p_ccb->local_id);
    if (p_buf == NULL) {
        /* L2CAP_TRACE_WARNING0 ("L2CAP - no buffer for conn_req") */
        if (lbl_803C4040[0] >= BT_TRACE_LEVEL_WARNING)
            fn_8007093C(TRACE_LAYER_L2CAP | TRACE_TYPE_WARNING, lbl_80319174);
    } else {
        /* the command's parameters, past the HCI, L2CAP and command headers */
        p = (u8 *)p_buf + 0x14;
        UINT16_TO_STREAM(p, p_ccb->remote_cid);
        UINT16_TO_STREAM(p, 0);       /* Flags: no continuation */

        /* Now, put the options */
        if (p_cfg->mtu_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_MTU);
            UINT8_TO_STREAM(p, L2CAP_CFG_MTU_OPTION_LEN);
            UINT16_TO_STREAM(p, p_cfg->mtu);
        }
        if (p_cfg->flush_to_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FLUSH_TOUT);
            UINT8_TO_STREAM(p, L2CAP_CFG_FLUSH_OPTION_LEN);
            UINT16_TO_STREAM(p, p_cfg->flush_to);
        }
        if (p_cfg->qos_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_QOS);
            UINT8_TO_STREAM(p, L2CAP_CFG_QOS_OPTION_LEN);
            UINT8_TO_STREAM(p, p_cfg->qos.qos_flags);
            UINT8_TO_STREAM(p, p_cfg->qos.service_type);
            UINT32_TO_STREAM(p, p_cfg->qos.token_rate);
            UINT32_TO_STREAM(p, p_cfg->qos.token_bucket_size);
            UINT32_TO_STREAM(p, p_cfg->qos.peak_bandwidth);
            UINT32_TO_STREAM(p, p_cfg->qos.latency);
            UINT32_TO_STREAM(p, p_cfg->qos.delay_variation);
        }
        if (p_cfg->fcr_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FCR);
            UINT8_TO_STREAM(p, L2CAP_CFG_FCR_OPTION_LEN);
            UINT8_TO_STREAM(p, p_cfg->fcr.mode);
            UINT8_TO_STREAM(p, p_cfg->fcr.tx_win_sz);
            UINT8_TO_STREAM(p, p_cfg->fcr.max_transmit);
            UINT16_TO_STREAM(p, p_cfg->fcr.rtrans_tout);
            UINT16_TO_STREAM(p, p_cfg->fcr.mon_tout);
            UINT16_TO_STREAM(p, p_cfg->fcr.mps);
        }

        ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(p_ccb->p_lcb, 0,
                                                                 p_buf);
    }
}

/* Build and send an L2CAP "configuration response" message to the peer: the
   answer to its configuration request, echoing back with our own values the
   options p_cfg says we accept. */
void l2cu_send_peer_config_rsp(tL2C_CCB_VIEW *p_ccb, tL2CAP_CFG_INFO *p_cfg)
{
    extern char lbl_80319174[];           /* "L2CAP - no buffer for conn_req" */
    extern void fn_8007093C(u32, void *); /* the stack's LogMsg_0() */
    void *p_buf;
    u8 *p;
    u16 cfg_len;

    /* How much option data the response carries. */
    cfg_len = 0;
    if (p_cfg->mtu_present)
        cfg_len = L2CAP_CFG_MTU_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
    if (p_cfg->flush_to_present)
        cfg_len += L2CAP_CFG_FLUSH_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
    if (p_cfg->qos_present)
        cfg_len += L2CAP_CFG_QOS_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
    if (p_cfg->fcr_present)
        cfg_len += L2CAP_CFG_FCR_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;

    /* l2cu_build_header() takes the option data's length as a UINT16. */
    p_buf = ((void *(*)(u16, u16, u8, u8))l2cu_build_header)(
        p_ccb->p_lcb->handle, cfg_len + L2CAP_CONFIG_RSP_LEN, L2CAP_CMD_CONFIG_RSP,
        p_ccb->remote_id);
    if (p_buf == NULL) {
        /* L2CAP_TRACE_WARNING0 ("L2CAP - no buffer for conn_req") */
        if (lbl_803C4040[0] >= BT_TRACE_LEVEL_WARNING)
            fn_8007093C(TRACE_LAYER_L2CAP | TRACE_TYPE_WARNING, lbl_80319174);
    } else {
        /* the command's parameters, past the HCI, L2CAP and command headers */
        p = (u8 *)p_buf + 0x14;
        UINT16_TO_STREAM(p, p_ccb->remote_cid);
        UINT16_TO_STREAM(p, 0);       /* Flags: no continuation */
        UINT16_TO_STREAM(p, p_cfg->result);

        /* Now, put the options */
        if (p_cfg->mtu_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_MTU);
            UINT8_TO_STREAM(p, L2CAP_CFG_MTU_OPTION_LEN);
            UINT16_TO_STREAM(p, p_cfg->mtu);
        }
        if (p_cfg->flush_to_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FLUSH_TOUT);
            UINT8_TO_STREAM(p, L2CAP_CFG_FLUSH_OPTION_LEN);
            UINT16_TO_STREAM(p, p_cfg->flush_to);
        }
        if (p_cfg->qos_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_QOS);
            UINT8_TO_STREAM(p, L2CAP_CFG_QOS_OPTION_LEN);
            UINT8_TO_STREAM(p, p_cfg->qos.qos_flags);
            UINT8_TO_STREAM(p, p_cfg->qos.service_type);
            UINT32_TO_STREAM(p, p_cfg->qos.token_rate);
            UINT32_TO_STREAM(p, p_cfg->qos.token_bucket_size);
            UINT32_TO_STREAM(p, p_cfg->qos.peak_bandwidth);
            UINT32_TO_STREAM(p, p_cfg->qos.latency);
            UINT32_TO_STREAM(p, p_cfg->qos.delay_variation);
        }
        if (p_cfg->fcr_present) {
            UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FCR);
            UINT8_TO_STREAM(p, L2CAP_CFG_FCR_OPTION_LEN);
            UINT8_TO_STREAM(p, p_cfg->fcr.mode);
            UINT8_TO_STREAM(p, p_cfg->fcr.tx_win_sz);
            UINT8_TO_STREAM(p, p_cfg->fcr.max_transmit);
            UINT16_TO_STREAM(p, p_cfg->fcr.rtrans_tout);
            UINT16_TO_STREAM(p, p_cfg->fcr.mon_tout);
            UINT16_TO_STREAM(p, p_cfg->fcr.mps);
        }

        ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(p_ccb->p_lcb, 0,
                                                                 p_buf);
    }
}

extern char lbl_80319194[];
/* Build and send an L2CAP Configuration Response rejecting unsupported options.
 * Copies rejectable (non-hint, unrecognized) options from the peer config into
 * the response, fills L2CAP/signaling headers from the CCB/LCB, and queues it.
 */
void l2cu_send_peer_config_rej(void *p_ccb, u8 *p_cfg_start, u16 cfg_len, u16 cfg_rej_len) {
    u8 *p_msg;
    u8 *out;
    u8 *out_start;
    u8 *p;
    u8 *p_end;
    u8 *lcb;
    u8 option_len;
    s32 option;
    s32 option_type;
    s32 total_len;
    s32 flags;
    u16 out_len;
    p_msg = (u8 *)GKI_getpoolbuf(2);
    if (p_msg == 0) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80319194);
        return;
    }
    out = p_msg + 0xA;
    *(u16 *)(p_msg + 4) = 0;
    out_start = out;
    p_end = p_cfg_start + cfg_len;
    lcb = *(u8 **)((u8 *)p_ccb + 0x10);
    flags = *(u16 *)(lcb + 0x28) | 0x2000;
    p_msg[8] = flags;
    lcb = *(u8 **)((u8 *)p_ccb + 0x10);
    flags = *(u16 *)(lcb + 0x28) | 0x2000;
    p_msg[9] = flags >> 8;
    out[2] = cfg_rej_len + 0xA;
    out[3] = (cfg_rej_len + 0xA) >> 8;
    out[4] = 1;
    out[5] = 0;
    out[6] = 5;
    out[7] = *((u8 *)p_ccb + 0x36);
    out[8] = cfg_rej_len + 6;
    out[9] = (cfg_rej_len + 6) >> 8;
    out[0xA] = *(u16 *)((u8 *)p_ccb + 0x16);
    out[0xB] = (*(u16 *)((u8 *)p_ccb + 0x16)) >> 8;
    out[0xC] = 0;
    out[0xD] = 0;
    out[0xE] = 3;
    out[0xF] = 0;
    out += 0x10;
    p = p_cfg_start;
    goto check_options;
copy_or_skip:
    option = p[0];
    option_len = p[1];
    option_type = option & 0x7F;
    switch (option_type) {
    case 1:
    case 2:
    case 3:
        p += option_len + 2;
        goto check_options;
    default:
        break;
    }
    total_len = option_len + 2;
    if (total_len <= cfg_len) {
        if ((option & 0x80) == 0) {
            memcpy(out, p, total_len);
            out += total_len;
        }
        p += total_len;
    } else p = p_end;
check_options:
    if (p < p_end) goto copy_or_skip;
    out_len = (out - out_start) - 2;
    out_start[0] = out_len;
    out_start[1] = out_len >> 8;
    *(u16 *)(p_msg + 2) = out_len + 4;
    ((void (*)(void *, void *, void *))l2c_link_check_send_pkts)(
        *(void **)((u8 *)p_ccb + 0x10), p_ccb, p_msg);
}

void l2cu_send_peer_disc_req(void *pCcb) {
    /* Send an L2CAP disconnect request for the given channel control block. */
    u32 cmdId;
    void *pBuf;
    u8 *pLcb;

    pLcb = *(u8 **)((u8 *)pCcb + 0x10);
    cmdId = *(u8 *)(pLcb + 0x31) + 1;
    *(u8 *)(pLcb + 0x31) = cmdId;
    *(volatile u8 *)((u8 *)pCcb + 0x35) = cmdId;
    pBuf = ((void *(*)(u16, u8, u8, u8, void *))l2cu_build_header)(
        *(u16 *)(*(u8 * volatile *)((u8 *)pCcb + 0x10) + 0x28),
        4, 6, cmdId, pLcb
    );
    if (pBuf == NULL) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_80319174);
        return;
    }
    *(u8 *)((u8 *)pBuf + 0x14) = *(u16 *)((u8 *)pCcb + 0x16);
    *(u8 *)((u8 *)pBuf + 0x15) = *(u16 *)((u8 *)pCcb + 0x16) >> 8;
    *(u8 *)((u8 *)pBuf + 0x16) = *(u16 *)((u8 *)pCcb + 0x14);
    *(u8 *)((u8 *)pBuf + 0x17) = *(u16 *)((u8 *)pCcb + 0x14) >> 8;
    *(u16 *)((u8 *)pBuf + 6) = 0;
    GKI_enqueue((BUFFER_Q *)(*(u8 **)((u8 *)pCcb + 0x10) + 0x44), pBuf);
    ((void (*)(void *, void *, void *))l2c_link_check_send_pkts)(
        *(u8 **)((u8 *)pCcb + 0x10), NULL, NULL
    );
}

int l2cu_send_peer_disc_rsp(void *p_lcb, int remote_id, int local_cid, int remote_cid) {
    void *p_buf = l2cu_build_header(*(u16 *)((u8 *)p_lcb + 0x28), 4, 7, remote_id);
    u8 *packet;
    if (p_buf == NULL) {
        if (lbl_803C4040[0] >= 2) {
            fn_8007093C(0x80001, lbl_80319174);
        }
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

/* Sends an L2CAP echo request to a peer, or logs an error if no buffer is available. */
void l2cu_send_peer_echo_req(void *p_lcb, u8 *p_data, s32 data_len)
{
    BT_HDR *p_buf;
    u8 *p;

    if ((p_buf = (BT_HDR *)((BT_HDR *(*)(u16, s32, u8, u8))l2cu_build_header)(
             *(u16 *)((u8 *)p_lcb + 0x28), data_len, 8,
             ++*(((u8 *)p_lcb) + 0x31))) == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_803191B4);
        return;
    }

    p = (u8 *)(p_buf + 1) + 0xC;
    if (data_len)
        ARRAY_TO_STREAM(p, p_data, data_len);
    ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(p_lcb, 0, p_buf);
}

/* Send an L2CAP Echo Response (cmd 9) to the peer on the given LCB/CID, copying
 * up to the controller's effective MTU-sized payload (capped when too large). */
void l2cu_send_peer_echo_rsp(void *p_lcb, s32 local_cid, u8 *p_data, u32 data_len_arg)
{
    BT_HDR *p_buf;
    u8 *p;
    u16 mtu_limit;
    s32 data_len = data_len_arg;

    /* Use configured max PDU size, capped at the default echo-data limit. */
    if (*(u16 *)(lbl_803C0A50 + 0x7E) < 0x294)
        mtu_limit = *(u16 *)(lbl_803C0A50 + 0x7C);
    else
        mtu_limit = 0x294;

    /* Drop payload if it would exceed the header-adjusted MTU. */
    if (data_len_arg > (u16)(mtu_limit - 0xC))
        data_len = 0;

    if ((p_buf = (BT_HDR *)((BT_HDR *(*)(u16, s32, u8, s32))l2cu_build_header)(
             *(u16 *)((u8 *)p_lcb + 0x28), data_len, 9, local_cid)) == 0) {
        if (lbl_803C4040[0] >= 2)
            fn_8007093C(0x80001, lbl_80319174);
        return;
    }

    /* Write echo payload after the L2CAP/signaling header area. */
    p = (u8 *)(p_buf + 1) + 0xC;
    if (data_len)
        ARRAY_TO_STREAM(p, p_data, data_len);
    ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(p_lcb, 0, p_buf);
}

extern void *l2cu_build_header(u16, u8, u8, s32);
extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
extern void fn_8007093C(u32, void *);
extern char lbl_80319174[];
/* Send an L2CAP Information Response (cmd 0x0B) for the requested info type. */
void l2cu_send_peer_info_rsp(void *p_lcb, s32 id, u16 info_type) {
    void *p_buf;
    extern void *l2cu_build_header(u16, u8, u8, s32);
    extern void l2c_link_check_send_pkts(void *, u8, void *, u8);
    extern void fn_8007093C(u32, void *);
    extern char lbl_80319174[];
    p_buf = l2cu_build_header(*(u16 *)((u8 *)p_lcb + 0x28), 4, 0xb, id);
    if (p_buf == 0) {
        if (lbl_803C4040[0] >= 2) fn_8007093C(0x80001, lbl_80319174);
    } else {
        *(u8 *)((u8 *)p_buf + 0x14) = info_type;
        *((u8 *)p_buf + 0x15) = info_type >> 8;
        *((u8 *)p_buf + 0x16) = 1;
        *((u8 *)p_buf + 0x17) = 0;
        ((void (*)(void *, u8, void *))l2c_link_check_send_pkts)(p_lcb, 0, p_buf);
    }
}

/* Allocates a free L2CAP channel control block from l2cb, attaches it to the given
 * L2CAP link's CCB list, and initializes its default state/timer fields. */
void *l2cu_allocate_ccb(void *p_lcb, u16 psm) {
    u8 *p_ccb = *(u8 **)(lbl_803C4040 + 0x7B0);
    s32 offset;
    u16 index;
    u8 *next;

    if (p_ccb == NULL) return NULL;

    next = *(u8 **)(p_ccb + 8);
    *(u8 **)(lbl_803C4040 + 0x7B0) = next;
    p_ccb[0] = 1;
    offset = (s32)(p_ccb - (lbl_803C4040 + 0x178));
    index = (u16)(offset / 0x7C);
    *(u16 *)(p_ccb + 0x14) = index + 0x40;
    *(void **)(p_ccb + 0x10) = p_lcb;
    if (*(void **)((u8 *)p_lcb + 8) == NULL) {
        *(u8 **)((u8 *)p_lcb + 0xC) = p_ccb;
        *(u8 **)((u8 *)p_lcb + 8) = p_ccb;
        *(u32 *)(p_ccb + 8) = 0;
        *(u32 *)(p_ccb + 0xC) = 0;
    } else {
        *(u32 *)(p_ccb + 8) = 0;
        *(u8 **)(p_ccb + 0xC) = *(u8 **)((u8 *)p_lcb + 0xC);
        *(u8 **)(*(u8 **)((u8 *)p_lcb + 0xC) + 8) = p_ccb;
        *(u8 **)((u8 *)p_lcb + 0xC) = p_ccb;
    }
    *(u16 *)(p_ccb + 0x3C) = 0xFFFF;
    *(u16 *)(p_ccb + 0x3A) = 0x2A0;
    *(u16 *)(p_ccb + 0x38) = 0x2A0;
    p_ccb[0x59] = 1; p_ccb[0x41] = 1;
    *(u32 *)(p_ccb + 0x5C) = 0; *(u32 *)(p_ccb + 0x44) = 0;
    *(u32 *)(p_ccb + 0x60) = 0; *(u32 *)(p_ccb + 0x48) = 0;
    *(u32 *)(p_ccb + 0x64) = 0; *(u32 *)(p_ccb + 0x4C) = 0;
    *(u32 *)(p_ccb + 0x68) = -1; *(u32 *)(p_ccb + 0x50) = -1;
    *(u32 *)(p_ccb + 0x6C) = -1; *(u32 *)(p_ccb + 0x54) = -1;
    p_ccb[0x34] = 0; *(u32 *)(p_ccb + 4) = 0; p_ccb[0x37] = 1;
    *(u8 **)(p_ccb + 0x28) = p_ccb;
    return p_ccb;
}

/* Releases an L2CAP channel control block from its connection, frees queued buffers, returns it to the free CCB list, and may schedule disconnect cleanup. */
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
    UINT16 i;
    u8 *p_rcb = lbl_803C4040 + 0x650;
    for (i = 0; i < 8; i++, p_rcb += 0x2C) {
        if (p_rcb[0] == 0) {
            p_rcb[0] = 1;
            *(s16 *)(p_rcb + 2) = psm;
            return p_rcb;
        }
    }
    return 0;
}

void fn_8008EC30(void *arg0) {
    *(u8 *)arg0 = 0;
    *(u16 *)((u8 *)arg0 + 2) = 0;
}

/* Find the registration control block for a PSM in l2cb's RCB pool, or NULL if none. */
void *l2cu_find_rcb_by_psm(UINT16 psm) {
    UINT16 xx;
    tL2C_RCB_VIEW *p_rcb = (tL2C_RCB_VIEW *)(lbl_803C4040 + 0x650);

    for (xx = 0; xx < 8; xx++, p_rcb++) {
        if ((p_rcb->in_use) && (p_rcb->psm == psm))
            return p_rcb;
    }

    return 0;
}

void l2cu_process_peer_cfg_req(void *arg0, void *arg1) {
    /* Validate a peer L2CAP config request (MTU, flush timeout, QoS): clamp/adjust invalid fields and, on any rejection, mark the response unacceptable and clear accepted options. */
    int var_r0, var_r3, mtuOk = 1, qosOk = 1, flushOk = 1;
    unsigned short mtu;
    unsigned char *ccb = (unsigned char *)arg0;
    unsigned char *cfg = (unsigned char *)arg1;
    if (cfg[2]) {
        mtu = *(unsigned short *)(cfg + 4);
        if (mtu >= 0x30) {
            *(unsigned short *)(ccb + 0x3A) = mtu;
            if (mtu > 0x69B) {
                *(unsigned short *)(cfg + 4) = 0x69B;
                *(unsigned short *)(ccb + 0x3A) = 0x69B;
            }
        } else { mtuOk = 0; *(unsigned short *)(cfg + 4) = 0x30; }
    }
    if (cfg[0x20] && !*(unsigned short *)(cfg + 0x22)) {
        flushOk = 0; *(unsigned short *)(cfg + 0x22) = 0xFFFF;
    }
    if (cfg[6]) {
        if (cfg[9] <= 2) {
            struct Copy { unsigned int w[6]; };
            *(struct Copy *)(ccb + 0x40) = *(struct Copy *)(cfg + 8);
        } else { qosOk = 0; cfg[9] = 1; }
    }
    var_r3 = 0; var_r0 = 0;
    if (mtuOk && flushOk && qosOk) var_r0 = 1;
    if (var_r0) var_r3 = 1;
    if (!var_r3) {
        *(short *)cfg = 1;
        if (mtuOk) cfg[2] = 0;
        if (flushOk) cfg[0x20] = 0;
        if (qosOk) cfg[6] = 0;
        *(signed char *)(cfg + 0x24) = 0;
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
    u32 second;
    u32 first;

    if (cfg[2] != 0) {
        u16 requested = *(u16 *)(cfg + 4);
        *(u16 *)(ccb + 0x38) = requested;
        if (requested > 0x69B) {
            *(u16 *)(cfg + 4) = 0x69B;
            *(u16 *)(ccb + 0x38) = 0x69B;
        }
    }
    if (cfg[6] != 0) {
        first = *(u32 *)(cfg + 8);
        second = *(u32 *)(cfg + 0xC);
        *(u32 *)(ccb + 0x58) = first;
        *(u32 *)(ccb + 0x5C) = second;
        first = *(u32 *)(cfg + 0x10);
        second = *(u32 *)(cfg + 0x14);
        *(u32 *)(ccb + 0x64) = second;
        *(u32 *)(ccb + 0x60) = first;
        first = *(u32 *)(cfg + 0x18);
        second = *(u32 *)(cfg + 0x1C);
        *(u32 *)(ccb + 0x6C) = second;
        *(u32 *)(ccb + 0x68) = first;
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

extern char lbl_803191D4[];
extern u8 lbl_80559080;
extern u8 lbl_80559088;
BOOLEAN l2cu_create_conn(void *arg0) {
    register s32 i;
    register u8 *p_lcb_iter;
    register BOOLEAN sco_active;
    register u8 *p_lcb = (u8 *)arg0;
    u16 log_param;

    *(u32 *)(p_lcb + 4) = 3;
    for (i = 0, p_lcb_iter = lbl_803C4040 + 8;
         i < 4;
         i++, p_lcb_iter += 0x5C) {
        if (p_lcb_iter != p_lcb && p_lcb_iter[0] != 0 &&
            p_lcb_iter[0x30] == 1) {
            sco_active = btm_is_sco_active_by_bdaddr(p_lcb_iter + 0x2A);
            if (lbl_803C4040[0] >= 3) {
                if (sco_active == 1)
                    log_param = (u16)&lbl_80559080;
                else
                    log_param = (u16)&lbl_80559088;
                fn_80070954(0x80002, lbl_803191D4, log_param);
            }

            if (sco_active != 1 &&
                (lbl_803C0F78[0x640] & 0x20) != 0) {
                *(u32 *)(p_lcb + 4) = 2;
                p_lcb[0x30] = 0;
                BTM_SwitchRole(p_lcb_iter + 0x2A, 0, 0);
                btu_start_timer((TIMER_LIST_ENT *)(p_lcb + 0x10), 2, 0xA);
                return TRUE;
            }
        }
    }

    return ((BOOLEAN (*)(void *))l2cu_create_conn_after_switch)(p_lcb);
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
    if (!btsnd_hcic_create_conn((UINT8 *)arg0 + 0x2A, 0x18, var_r5, var_r6, var_r7, allow_switch)) {
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

// Handles RFCOMM server-channel start confirmation: if successful, request parameter
// negotiation for each port on the multiplexer; on failure, report the error, close the
// affected ports, and notify callbacks. If no ports remain up, release the multiplexer.
void PORT_StartCnf(void *mux_id, u16 status) {
    u8 *p_port;
    s32 i;
    u8 no_ports_up = 1;

    if (lbl_803C4828[0x414] >= 4)
        fn_80070954(0x90003, lbl_80319278, status);

    p_port = lbl_803C4828 + 0x68;
    for (i = 0; i < 5; i++, p_port += 0xA4) {
        if (*(void **)(p_port + 0x6C) == mux_id) {
            no_ports_up = 0;
            if (status == 0) {
                RFCOMM_ParNegReq(mux_id, p_port[0xD], *(u16 *)(p_port + 0x12));
                continue;
            }

            if (lbl_803C4828[0x414] >= 2)
                fn_80070954(0x90001, lbl_80319290, status);
            if (status == 4)
                p_port[0xE] = 0x18;
            else
                p_port[0xE] = 0xC;

            rfc_release_multiplexer_channel(mux_id);
            *(u32 *)(p_port + 0x6C) = 0;
            if (*(void **)(p_port + 0x8C) != 0 &&
                (*(u32 *)(p_port + 0x88) & 0x8000) != 0) {
                ((void (*)(s32, u8))*(void **)(p_port + 0x8C))(0x8000, p_port[0]);
            }
            if (*(void **)(p_port + 0x90) != 0) {
                ((void (*)(s32, u8))*(void **)(p_port + 0x90))(0xC, p_port[0]);
            }
            port_release_port(p_port);
        }
    }
    if (no_ports_up)
        rfc_check_mcb_active(mux_id);
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
    /* Handles RFCOMM parameter-negotiation indication: selects/updates the port, negotiates MTU/mode, and replies. */
    u8 *port;
    register u32 value;
    u32 limit;
    register u8 sendMode;
    register u8 sendParam;

    port = (u8 *)port_find_mcb_dlci_port(mcb, dlci);
    if (lbl_803C4828[0x414] >= 4)
        fn_8007096C(0x90003, lbl_803192C0, dlci, mtu);
    if (port == 0) {
        port = (u8 *)port_find_dlci_port(dlci);
        if (port == 0) {
            rfc_send_dm(mcb, dlci, 0);
            rfc_check_mcb_active(mcb);
            if (lbl_803C4828[0x414] >= 4)
                fn_8007093C(0x90003, lbl_803192E0);
            return;
        }
        *((u8 *)mcb + dlci + 0x24) = port[0];
    }

    memcpy(port + 6, (u8 *)mcb + 0x62, 6);
    port_select_mtu(port);
    *(void **)(port + 0x6C) = mcb;
    value = *(u16 *)(port + 0x12);
    if (value < mtu)
        mtu = value;
    *(u16 *)(port + 0x12) = mtu;
    *(u16 *)(port + 0x14) = mtu;

    if (((u8 *)mcb)[0x72] == 0) {
        if (mode != 0)
            goto set_state_two;
        ((u8 *)mcb)[0x72] = 1;
        goto state_ready;
set_state_two:
        ((u8 *)mcb)[0x72] = 2;
    }
state_ready:
    if (mode == 0) {
        sendMode = 0;
        sendParam = 0;
        goto send_reply;
    }
    if (((u8 *)mcb)[0x72] == 2) {
        *(s16 *)(port + 0x98) = param;
        if (param == 0)
            port[0x24] = 1;
        sendMode = 0xE0;
        value = *(u16 *)(port + 0x9C);
        limit = value < 7 ? value : 7;
        sendParam = limit;
        *(u16 *)(port + 0x9A) = sendParam;
    } else {
        sendMode = 0;
        sendParam = 0;
    }
send_reply:
    ((void (*)(void *, u16, u16, u16, u16))fn_800936BC)(mcb, dlci, *(u16 *)(port + 0x12), sendMode, sendParam);
}

extern void RFCOMM_DlcEstablishReq(void *, u8);
extern char lbl_80319300[];
/* RFCOMM port parameter negotiation confirm: logs when enabled, updates the port's negotiated MTU/control state, and starts DLC establishment if it was pending. */
void PORT_ParNegCnf(void *p_mcb, u8 dlci, u16 mtu, u8 cl_type, u8 k) {
    void *p_port;
    u8 *port_cb;
    p_port = port_find_mcb_dlci_port(p_mcb, dlci);
    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, u8, u16, u8, u8))fn_8007099C)(0x90003, lbl_80319300, dlci, mtu, cl_type, k);
    if (p_port == 0) return;
    port_cb = (u8 *)p_port;
    if (*((u8 *)p_mcb + 0x72) == 0) {
        if (cl_type == 0xE0) *((u8 *)p_mcb + 0x72) = 2;
        else *((u8 *)p_mcb + 0x72) = 1;
    }
    if (*(u16 *)(port_cb + 0x12) < mtu) mtu = *(u16 *)(port_cb + 0x12);
    *(u16 *)(port_cb + 0x12) = mtu;
    *(u16 *)(port_cb + 0x14) = mtu;
    if (*((u8 *)p_mcb + 0x72) == 2) {
        *(s16 *)(port_cb + 0x98) = k;
        if (k == 0) port_cb[0x24] = 1;
    }
    if (port_cb[2] == 1) ((void (*)(void *, u8, u16))RFCOMM_DlcEstablishReq)(p_mcb, port_cb[0xD], *(u16 *)(port_cb + 0x12));
}

void PORT_DlcEstablishInd(s32 arg0, s32 arg1, s32 arg2) {
    /* RFCOMM PORT: handle DLC establishment indication - resolve port for (mcb, dlci), adopt peer MTU if smaller, respond, stop timer, fire port callbacks, and mark port opened. */
    extern char lbl_8031932C[];
    extern void RFCOMM_DlcEstablishRsp(void *, u8, s32, u16);
    u8 *port;
    port = (u8 *)((void *(*)(s32, s32))port_find_mcb_dlci_port)(arg0, arg1);
    if (lbl_803C4828[0x414] >= 4) {
        ((void (*)(u32, void *, s32, s32))fn_8007096C)(0x90003, lbl_8031932C, arg1, arg2);
    }
    if (port == 0) {
        port = (u8 *)port_find_dlci_port((unsigned int)arg1);
        if (port == 0) {
            ((void (*)(s32, s32, s32, s32))RFCOMM_DlcEstablishRsp)(arg0, arg1, 0, 1);
            return;
        }
        *(u8 *)(arg0 + arg1 + 0x24) = port[0];
    }
    if (arg2 != 0 && (u32)arg2 < *(u16 *)(port + 0x14)) {
        *(u16 *)(port + 0x14) = (u16)arg2;
    }
    rfc_timer_stop((void *)arg0);
    ((void (*)(s32, s32, s32, s32))RFCOMM_DlcEstablishRsp)(arg0, arg1, *(u16 *)(port + 0x12), 0);
    if (*(void **)(port + 0x8C) != 0 && (*(u32 *)(port + 0x88) & 0x200) != 0) {
        ((void (*)(u32, u8))*(void **)(port + 0x8C))(0x200, port[0]);
    }
    if (*(void **)(port + 0x90) != 0) {
        ((void (*)(u32, u8))*(void **)(port + 0x90))(0, port[0]);
    }
    port[2] = 2;
}

extern char lbl_80319350[];
/* Handle DLC establishment confirmation: update port state and negotiate parameters */
void PORT_DlcEstablishCnf(void *p_mcb, u8 dlci, u16 mtu, u16 result) {
    extern void RFCOMM_PortNegReq(void *p_mcb, u8 dlci, void *p_port_pars);
    extern void RFCOMM_ControlReq(void *p_mcb, u8 dlci, void *p_pars);
    void *p_port = port_find_mcb_dlci_port(p_mcb, dlci);

    if (lbl_803C4828[0x414] >= 4) {
        ((void (*)(u32, void *, u8, u16, u16))fn_80070984)(
            0x90003, lbl_80319350, dlci, mtu, result);
    }
    if (p_port == 0) return;
    if (result != 0) {
        *(u8 *)((u8 *)p_port + 0x0E) = 0x0C;
        port_rfc_closed((struct t_port_info *)p_port, 0x0C);
        return;
    }
    if (mtu != 0 && mtu < *(u16 *)((u8 *)p_port + 0x14))
        *(u16 *)((u8 *)p_port + 0x14) = mtu;
    rfc_timer_stop(p_mcb);
    if (*(void **)((u8 *)p_port + 0x8C) != 0 &&
        (*(u32 *)((u8 *)p_port + 0x88) & 0x200) != 0) {
        ((void (*)(u32, u8))*(void **)((u8 *)p_port + 0x8C))(0x200, *(u8 *)p_port);
    }
    if (*(void **)((u8 *)p_port + 0x90) != 0) {
        ((void (*)(u32, u8))*(void **)((u8 *)p_port + 0x90))(0, *(u8 *)p_port);
    }
    *(u8 *)((u8 *)p_port + 2) = 2;
    if (*(u16 *)((u8 *)p_port + 4) == 0x1103 ||
        *(u16 *)((u8 *)p_port + 4) == 0x1111) {
        RFCOMM_PortNegReq(*(void **)((u8 *)p_port + 0x6C),
                          *(u8 *)((u8 *)p_port + 0x0D), 0);
    } else {
        RFCOMM_ControlReq(*(void **)((u8 *)p_port + 0x6C),
                          *(u8 *)((u8 *)p_port + 0x0D),
                          (u8 *)p_port + 0x5A);
    }
}

void PORT_PortNegInd(void *arg0, u8 arg1, u8 *arg2, u16 arg3) {
    extern char lbl_80319380[];
    extern void fn_800937A0(void *, u16, u16, u16);
    void *port;
    u8 *dst;
    u8 *src;
    u8 first;
    u8 second;

    port = port_find_mcb_dlci_port(arg0, arg1);
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, lbl_80319380);
    if (port == NULL) {
        port = port_find_dlci_port(arg1);
        if (port == NULL) {
            dst = (u8 *)port;
            src = arg2;
            second = src[0]; first = src[1];
            dst[0x51] = second; dst[0x52] = first;
            first = src[2]; second = src[3];
            dst[0x53] = first; dst[0x54] = second;
            first = src[4]; second = src[5];
            dst[0x55] = first; dst[0x56] = second;
            first = src[6]; second = src[7];
            dst[0x57] = first; dst[0x58] = second;
            dst[0x59] = src[8];
            ((void (*)(void *, u16, void *, u16))fn_800937A0)(arg0, arg1, src, 0);
            return;
        }
        *((u8 *)arg0 + arg1 + 0x24) = *(u8 *)port;
    }
    dst = (u8 *)port;
    src = arg2;
    first = src[0]; second = src[1];
    dst[0x51] = first; dst[0x52] = second;
    first = src[2]; second = src[3];
    dst[0x53] = first; dst[0x54] = second;
    first = src[4]; second = src[5];
    dst[0x55] = first; dst[0x56] = second;
    first = src[6]; second = src[7];
    dst[0x57] = first; dst[0x58] = second;
    dst[0x59] = src[8];
    ((void (*)(void *, u16, void *, u16))fn_800937A0)(arg0, arg1, src, arg3);
}

extern char lbl_80319240[];
extern void fn_800939A0(void *, u8);
extern void RFCOMM_ControlReq(void *, u8, void *);
/* RFCOMM port negotiation confirmation: find the port for (mcb,dlci), log via
 * trace, then on error mark/close it, else send control request or log. */
void PORT_PortNegCnf(void *p_mcb, u8 dlci, void *p_pars, u16 result) {
    register char *p_messages = lbl_80319240;
    struct t_port_info *p_port;

    p_port = (struct t_port_info *)port_find_mcb_dlci_port(p_mcb, dlci);
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, p_messages + 0x150);
    if (p_port == 0) {
        if (lbl_803C4828[0x414] >= 2)
            fn_8007093C(0x90001, p_messages + 0x160);
        return;
    }
    if (result != 0) {
        ((u8 *)p_port)[0x0E] = 0x0E;
        fn_800939A0(p_mcb, ((u8 *)p_port)[0x0D]);
        port_rfc_closed(p_port, 0x0E);
        return;
    }
    if ((((u8 *)p_port)[0x64] & 1) == 0) {
        RFCOMM_ControlReq(*(void **)((u8 *)p_port + 0x6C), ((u8 *)p_port)[0x0D],
                          (u8 *)p_port + 0x5A);
        return;
    }
    if (lbl_803C4828[0x414] >= 2)
        fn_8007093C(0x90001, p_messages + 0x178);
}

extern int port_get_signal_changes();
extern char lbl_803193E0[];
extern char lbl_803193F0[];
/* Handle an RFCOMM modem/control signal indication for a port and dispatch any resulting events to its callback. */
void PORT_ControlInd(void *rfcommMcb, u8 dlci, u8 *params) {
    void *portCb;
    u32 eventMask;
    u8 signalState;
    void (*eventCallback)(u32, u8);

    portCb = port_find_mcb_dlci_port(rfcommMcb, dlci);
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, lbl_803193E0);
    if (portCb != 0) {
        eventMask = port_get_signal_changes(portCb, *((u8 *)portCb + 0x5F), params[0]);
        *((u8 *)portCb + 0x5F) = params[0];
        *((u8 *)portCb + 0x60) = params[1];
        *((u8 *)portCb + 0x61) = params[2];
        *((u8 *)portCb + 0x62) = params[3];
        *((u8 *)portCb + 0x63) = params[4];
        signalState = *((u8 *)portCb + 0x64);
        if ((signalState & 1) == 0) {
            RFCOMM_ControlReq(*(void **)((u8 *)portCb + 0x6C),
                              *((u8 *)portCb + 0xD), (u8 *)portCb + 0x5A);
        } else {
            if ((signalState & 4) == 0)
                eventMask |= *(u32 *)((u8 *)portCb + 0x88) & 0x200;
            if (signalState & 2)
                eventMask |= port_rfc_send_tx_data(portCb);
        }
        *((u8 *)portCb + 0x64) |= 0xC;
        if (params[1] != 0)
            eventMask |= *(u32 *)((u8 *)portCb + 0x88) & 0x40;
        if (eventMask != 0) {
            eventCallback = *(void (**)(u32, u8))((u8 *)portCb + 0x8C);
            if (eventCallback != 0)
                eventCallback(eventMask, *((u8 *)portCb));
        }
        if (lbl_803C4828[0x414] >= 4) {
            signalState = *((u8 *)portCb + 0x5F);
            ((void (*)(u32, void *, u8, u8, u8, u8))fn_8007099C)(
                0x90003, lbl_803193F0,
                (signalState & 1) ? 1 : 0,
                (signalState & 2) ? 1 : 0,
                (signalState & 4) ? 1 : 0,
                (signalState & 8) ? 1 : 0);
        }
    }
}

void PORT_ControlCnf(void *mcb, u8 dlci, void *pars) {
    /* RFCOMM control-confirmation callback: record peer acknowledgement of modem-signal control, send pending TX data if ready, and notify the port's event callback. */
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

/* Notify the port's event callback of RFCOMM remote line status changes. */
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

extern char lbl_80319454[];
void PORT_DlcReleaseInd(void *arg0, u8 arg1) {
    void *port;
    void *(*find_mcb)(void) = (void *(*)(void))port_find_mcb_dlci_port;

    port = find_mcb();
    if (lbl_803C4828[0x414] >= 4)
        fn_8007093C(0x90003, lbl_80319454);
    if (port != 0)
        port_rfc_closed((struct t_port_info *)port, 0x13);
}

/* ---- RFCOMM port pool names (port_rfc.c) ----------------------------------
 * rfc_cb is the RFCOMM control block at lbl_803C4828 (0x418 bytes, cleared by
 * rfc_init_cb): its trace level (BT_TRACE_LEVEL_*) at +0x414 and the port pool
 * at +0x68, where this build keeps 5 tPORT entries of 0xA4 bytes -- its
 * MAX_RFC_PORTS, while the SDK's bt_target.h default is 30, so the count is
 * spelled out under its own name.  tPORT.rfc.p_mcb, the multiplexer control
 * block a port runs on, is at +0x6C.  port_api.h is not part of this unit, so
 * the close reason it passes to the port callback is spelled out here too.
 */
#define rfc_cb                        lbl_803C4828 /* tRFC_CB */
#define rfc_cb_ports                  (lbl_803C4828 + 0x68) /* tPORT port[0] */
#define RFC_PORT_COUNT                5     /* tPORT entries in the pool */
#define PORT_INFO_SIZE                0xA4  /* sizeof(tPORT) */
#define PORT_MCB                      0x6C  /* tPORT.rfc.p_mcb */
#define PORT_PEER_CONNECTION_FAILED   0x10  /* port_api.h: PORT_ERR_BASE + 16 */

/* port_rfc.c's PORT_CloseInd(): the RFCOMM layer reports that the multiplexer
 * connection under p_mcb is gone.  Walk the port pool and close every port
 * running on it with PORT_PEER_CONNECTION_FAILED (port_rfc_closed() tells the
 * application's callback), then release the multiplexer channel itself. */
void PORT_CloseInd(void *p_mcb) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319468[];               /* "PORT_CloseInd" */
    extern void fn_8007093C(u32, void *);     /* RFCOMM trace event -> LogMsg */
    extern void rfc_release_multiplexer_channel(void *);
    u8 *p_port;
    s32 i;

    /* RFCOMM_TRACE_EVENT0(): group 9, event level */
    if (rfc_cb[0x414] >= BT_TRACE_LEVEL_EVENT) fn_8007093C(0x90003, lbl_80319468);
    for (i = 0, p_port = rfc_cb_ports; i < RFC_PORT_COUNT; i++, p_port += PORT_INFO_SIZE)
        if (*(void **)(p_port + PORT_MCB) == p_mcb) port_rfc_closed((struct t_port_info *)p_port, PORT_PEER_CONNECTION_FAILED);
    rfc_release_multiplexer_channel(p_mcb);
}

void Port_TimeOutCloseMux(void *arg0) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319478[];
      extern void fn_8007093C(u32, void *);
      u8 *entry;
    s32 i;

    if (lbl_803C4828[0x414] >= 4) fn_8007093C(0x90003, lbl_80319478);
    for (i = 0, entry = lbl_803C4828 + 0x68; i < 5; i++, entry += 0xA4)
        if (*(void **)(entry + 0x6C) == arg0) port_rfc_closed((struct t_port_info *)entry, 0x12);
}

extern void port_flow_control_peer(void *, s32, u16);
extern void RFCOMM_LineStatusReq(void *, u8, u8);
extern char lbl_80319490[];
extern char lbl_803194B4[];
// Handles an inbound RFCOMM data indication for a port: dispatches to a data callback if
// present, otherwise queues the buffer (checking overflow and scanning for the event char),
// updates flow control, and signals data/event callbacks when not holding events.
void PORT_DataInd(void *p_mcb, u8 dlci, BT_HDR *p_buf) {
    u8 *p_port = (u8 *)port_find_mcb_dlci_port(p_mcb, dlci);
    u8 rx_char1;
    u32 events = 0;
    u8 *p;
    int i;
    if (lbl_803C4828[0x414] >= 4) fn_80070954(0x90003, lbl_80319490, p_buf->len);
    if (!p_port) {
        GKI_freebuf(p_buf);
        return;
    }
    if (*(void **)(p_port + 0x94)) {
        port_flow_control_peer(p_port, 1, 1);
        (*(void (**)(u8, u8 *, u16))(p_port + 0x94))(p_port[0], (u8 *)(p_buf + 1) + p_buf->offset, p_buf->len);
        GKI_freebuf(p_buf);
        return;
    }
    if (*(u32 *)(p_port + 0x40) + p_buf->len > 0x2EE0
        || *(u16 *)(p_port + 0x38) + 1 > (s32)*(u16 *)(p_port + 0xA0)) {
        if (lbl_803C4828[0x414] >= 4) fn_8007093C(0x90003, lbl_803194B4);
        GKI_freebuf(p_buf);
        RFCOMM_LineStatusReq(p_mcb, dlci, 2);
        return;
    }
    if (((rx_char1 = p_port[0x4E]) != 0) && (*(u32 *)(p_port + 0x88) & 2)) {
        for (i = 0, p = (u8 *)(p_buf + 1) + p_buf->offset; i < p_buf->len; i++) {
            if (*p++ == rx_char1) {
                events |= 2;
                break;
            }
        }
    }
    GKI_enqueue((BUFFER_Q *)(p_port + 0x30), p_buf);
    *(u32 *)(p_port + 0x40) += p_buf->len;
    port_flow_control_peer(p_port, 0, 0);
    if (p_port[0x3D]) {
        if (events & 2) p_port[0x65] = 1;
        return;
    }
    events |= 1;
    events &= *(u32 *)(p_port + 0x88);
    if (*(void **)(p_port + 0x8C) && events)
        (*(void (**)(u32, u8))(p_port + 0x8C))(events, p_port[0]);
}

extern char lbl_803194E8[];
/* Handle RFCOMM flow control indication for a DLCI: update MUX/port flow state,
 * recompute events for affected port(s), and notify the port callback. */
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
        if (p_port == 0)
            return;
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
        if (callback != 0 && events != 0)
            callback(events, p_port[0]);

        if (dlci != 0)
            break;
    }
}

extern char lbl_803194FC[];
extern void fn_800939CC(void *, u8, void *);
extern int port_flow_control_user(void *);
u32 port_rfc_send_tx_data(void *port) {
    u8 *p = (u8 *)port;
    u32 events = 0u;
    void *packet = (void *)0;
    if (*(s32 *)(p + 0x28) == 0)
        goto flow;
    for (;;) {
        packet = GKI_dequeue((BUFFER_Q *)(p + 0x18));
        if (packet != (void *)0) {
            if (lbl_803C4828[0x414] >= (s32)4)
                fn_8007093C(0x90003u, lbl_803194FC);
            *(s32 *)(p + 0x28) -= (s32)*(u16 *)((u8 *)packet + 2);
            fn_800939CC(*(void **)(p + 0x6c), p[0xd], packet);
            events |= 0x4000u;
            if (*(s32 *)(p + 0x28) != (s32)0)
                continue;
            events |= 4u;
            goto flow;
        }
        events |= 4u;
        goto flow;
    }
flow:
    if (p[0x24] == 0) {
        void *mcb = *(void **)(p + 0x6c);
        if (mcb != (void *)0 && *((u8 *)mcb + 0x71) == 0)
            events |= port_flow_control_user(port);
    }
    return events & *(u32 *)(p + 0x88);
}

extern u8 lbl_80319514[],lbl_80319540[];
void port_rfc_closed(struct t_port_info *arg0, u8 arg1) {
    void *mcb = *(void **)((u8 *)arg0 + 0x6C);
    s32 signals = 0;
    if (*((u8 *)arg0 + 2) == 1 && *((u8 *)arg0 + 0xC)) {
        if (lbl_803C4828[0x414] >= 4)
            fn_8007093C(0x90003, lbl_80319514);
        rfc_port_timer_stop(arg0);
        *((u8 *)arg0 + 0x68) = 0;
        if (mcb) {
            *((u8 *)mcb + *((u8 *)arg0 + 0xD) + 0x24) = 0;
            rfc_check_mcb_active(mcb);
            *(void **)((u8 *)arg0 + 0x6C) = 0;
        }
        *((u8 *)arg0 + 0xD) &= 0xFE;
        return;
    }
    if (*((u8 *)arg0 + 2) != 3 && *((u8 *)arg0 + 2) != 0) {
        s32 mask = -12;
        *((u8 *)arg0 + 0xF) |= 0x10;
        *((u8 *)arg0 + 0x5F) = *((u8 *)arg0 + 0x5F) & mask;
        signals = port_get_signal_changes(arg0);
        if (*(u32 *)((u8 *)arg0 + 0x88) & 0x8000)
            signals |= 0x8000;
    }
    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, const char *, u8, s32))fn_8007096C)(
            0x90003, (const char *)lbl_80319540, *((u8 *)arg0 + 2), signals);
    if (*(void **)((u8 *)arg0 + 0x8C) && signals)
        ((void (*)(s32, u8))*(void **)((u8 *)arg0 + 0x8C))(
            signals, *((u8 *)arg0));
    if (*(void **)((u8 *)arg0 + 0x90))
        ((void (*)(s32, u8))*(void **)((u8 *)arg0 + 0x90))(
            arg1, *((u8 *)arg0));
    *((u8 *)arg0 + 0x68) = 0;
    port_release_port(arg0);
}

extern char lbl_80319570[];
void port_select_mtu(void *arg0) {
    register char *messages = lbl_80319570;
    register u8 *port = (u8 *)arg0;
    u16 packet_size;
    u32 mtu;

    mtu = *(u16 *)(port + 0x12);
    if (mtu == 0) {
        packet_size = btm_get_max_packet_size(port + 6);
        if (packet_size == 0) {
            if (lbl_803C4828[0x414] >= 2)
                fn_8007093C(0x90001, messages);
            *(u16 *)(port + 0x12) = 0x7F;
        } else if (packet_size <= 0x69F) {
            mtu = ((0x69F / packet_size) * packet_size) - 0xA;
            *(u16 *)(port + 0x12) = mtu;
            if (lbl_803C4828[0x414] >= 5)
                fn_80070954(0x90004, messages + 0x20, mtu);
        } else {
            *(u16 *)(port + 0x12) = 0x695;
            if (lbl_803C4828[0x414] >= 5)
                fn_80070954(0x90004, messages + 0x58, 0x695);
        }
    } else if (lbl_803C4828[0x414] >= 5) {
        ((void (*)(u32, void *))fn_80070954)(0x90004, messages + 0x90);
    }

    *(u16 *)(port + 0x9C) = 0x1F40 / *(u16 *)(port + 0x12);
    *(u16 *)(port + 0x9E) = 0x1388 / *(u16 *)(port + 0x12);
    *(u16 *)(port + 0xA0) = 0x2EE0 / *(u16 *)(port + 0x12);
    if (lbl_803C4828[0x414] >= 5) {
        ((void (*)(u32, void *, int, int, int))fn_80070984)(
            0x90004, messages + 0xB8,
            *(u16 *)(port + 0x9C), *(u16 *)(port + 0x9E), *(u16 *)(port + 0xA0));
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
    u8 *entry;
    u8 *base;
    unsigned int odd;
    unsigned int prev;
    unsigned short i;
    unsigned int dlci;
    u8 *port;
    odd = arg0 & 1;
    prev = arg0 - 1;
    base = (u8 *)&lbl_803C4828;
    for (i = 0; i < 5; i++) {
        entry = base + (i * 0xA4);
        port = entry + 0x68;
        if (*(u8 *)(entry + 0x69) == 0) continue;
        if (*(unsigned int *)(port + 0x6C) != 0) continue;
        dlci = *(u8 *)(port + 0xD);
        if (dlci == arg0) return port;
        if (odd != 0 && (int)dlci == (int)prev) {
            *(u8 *)(port + 0xD) = dlci + 1;
            return port;
        }
    }
    return 0;
}

int port_flow_control_user(void *arg0) {
    void *temp_r4;
    unsigned char var_r5 = 0;
    if (*((unsigned char *)arg0 + 0x24) != 0) goto set1;
    temp_r4 = *(void **)((char *)arg0 + 0x6c);
    if (temp_r4 == 0) goto set1;
    if (*((unsigned char *)temp_r4 + 0x71) == 0) goto set1;
    if (*(unsigned int *)((char *)arg0 + 0x28) > 0x1f40) goto set1;
    if (*(unsigned short *)((char *)arg0 + 0x20) <= 0x10) goto done;
set1:
    var_r5 = 1;
done:
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
    s32 index = (s32)arg0 - 0x40;
    char *trace_msg = lbl_803196B8;
    u16 lcid = arg0;
    void *port;
    u16 port_lcid;
    s16 status = arg1;

    if (index >= 10) {
        if (lbl_803C4828[0x414] >= 1)
            fn_80070954(0x90000, trace_msg + 0, lcid);
        port = NULL;
    } else {
        port = *(void **)(lbl_803C4828 + index * 4 + 0x3C);
        if (port != NULL) {
            port_lcid = *(u16 *)((u8 *)port + 0x68);
            if (port_lcid != lcid) {
                if (lbl_803C4828[0x414] >= 2)
                    fn_8007096C(0x90001, trace_msg + 0x1C, lcid, port_lcid);
                port = NULL;
            }
        }
    }
    if (port == NULL) {
        if (lbl_803C4828[0x414] >= 1)
            fn_80070954(0x90000, trace_msg + 0x54, lcid);
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
        if (lbl_803C4828[0x414] >= 1) ((void (*)(u32, char *, u32))fn_80070954)(0x90000, lbl_803196B8, arg0);
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
    u16 port_lcid;
    if (index >= 10) {
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u32))fn_80070954)(0x90000, trace_msg + 0, arg0);
        port = NULL;
    } else {
        port = *(void **)(lbl_803C4828 + index * 4 + 0x3C);
        if (port != NULL) {
            port_lcid = *(u16 *)((u8 *)port + 0x68);
            if (port_lcid != arg0) {
                if (lbl_803C4828[0x414] >= 2)
                    ((void (*)(u32, void *, u32))fn_8007096C)(0x90001, trace_msg + 0x1C, arg0);
                port = NULL;
            }
        }
    }
    if (port == NULL) {
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u32))fn_80070954)(0x90000, trace_msg + 0x8C, arg0);
    } else {
        ((void (*)(void *, u32, u8 *))fn_800916F4)(port, 0xB, arg1);
    }
}

void fn_800911DC(void) {

}

void RFCOMM_DisconnectInd(u16 arg0, s32 arg1) {
    register volatile char *messages = (volatile char *)lbl_803196B8;
    s32 temp_r0 = arg0 - 0x40;
    void *var_r30;

    if (temp_r0 >= 0xA) {
        if (lbl_803C4828[0x414] >= 1)
            fn_80070954(0x90000, (char *)messages, arg0);
        var_r30 = 0;
    } else {
        var_r30 = *(void **)((u8 *)&lbl_803C4828 + temp_r0 * 4 + 0x3C);
        if (var_r30 && *(u16 *)((u8 *)var_r30 + 0x68) != arg0) {
            if (lbl_803C4828[0x414] >= 2)
                fn_8007096C(0x90001, (char *)messages + 0x1C, arg0, *(u16 *)((u8 *)var_r30 + 0x68));
            var_r30 = 0;
        }
    }
    if (arg1)
        L2CA_DisconnectRsp(arg0);
    if (!var_r30) {
        if (lbl_803C4828[0x414] >= 2)
            fn_80070954(0x90001, (char *)messages + 0xA8, arg0);
    } else {
        fn_800916F4(var_r30, 0xE, 0);
    }
}

extern s32 rfc_parse_data(void *, void *, u8 *);
void RFCOMM_BufDataInd(u32 cid, BT_HDR *p_buf) {
    s32 index;
    char *messages = lbl_803196B8;
    void *p_mcb;
    void *p_port;
    u16 connection_id;
    s32 result;

    index = (s32)cid - 0x40;
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

void RFCOMM_CongestionStatusInd(UINT16 lcid, BOOLEAN is_congested) {
    register char *messages = lbl_803196B8;
    void *p_mcb;
    s32 index;
    u16 mcb_lcid;
    index = lcid - 0x40;
    if (index >= 0xA) {
        if (lbl_803C4828[0x414] >= 1)
            fn_80070954(0x90000, messages + 0, lcid);
        p_mcb = 0;
    } else {
        p_mcb = *(void **)(lbl_803C4828 + index * 4 + 0x3C);
        if (p_mcb != 0) {
            mcb_lcid = *(u16 *)((u8 *)p_mcb + 0x68);
            if (mcb_lcid != lcid) {
                if (lbl_803C4828[0x414] >= 2)
                    fn_8007096C(0x90001, messages + 0x1C, lcid, mcb_lcid);
                p_mcb = 0;
            }
        }
    }
    if (p_mcb == 0) {
        if (lbl_803C4828[0x414] >= 1)
            fn_80070954(0x90000, messages + 0xE4, lcid);
    } else {
        if (lbl_803C4828[0x414] >= 4)
            fn_80070954(0x90003, messages + 0x114, lcid);
        rfc_process_l2cap_congestion(p_mcb, is_congested);
    }
}

void fn_800916D8(void *callback, u32 cid) {
    u32 index = cid - 0x40;
    u8 *base = lbl_803C4828;
    *(void **)(base + 0x3C + index * 4) = callback;
}

/* RFCOMM multiplexer control block (rfc_int.h's tRFC_MCB) as this build lays it
   out; only the fields the multiplexer state machine is known to touch are named.
   fn_800916F4 dispatches on state, +0x68 is the channel L2CA_DisconnectReq() is
   called with and +0x62 is the address handed to L2CA_ConnectReq(). */
typedef struct t_rfc_mcb_view {
    u8  pad_00[0x62];
    u8  sec_bd_addr[6]; /* +0x62  peer this multiplexer channel runs to */
    u16 lcid;           /* +0x68  L2CAP channel carrying the multiplexer */
    u16 peer_l2cap_mtu;  /* +0x6A  peer's L2CAP MTU, less the RFCOMM framing */
    u8  state;          /* +0x6C  RFC_MX_STATE_* */
    u8  is_initiator;   /* +0x6D  we asked for this multiplexer channel */
    u8  local_cfg_sent; /* +0x6E  our L2CA_ConfigReq() has been confirmed */
    u8  peer_cfg_rcvd;  /* +0x6F  the peer's L2CA_ConfigInd() has arrived */
    u8  pad_70;
    u8  peer_ready;     /* +0x71  peer is up on the multiplexer channel */
} tRFC_MCB_VIEW;

/* Multiplexer states (tRFC_MCB.state, 0..6 is the switch in fn_800916F4) and the
   events rfc_mx_sm_execute() hands the state handlers. The names are rfc_int.h's
   and its values match this stack: the L2CAP layer's disconnect indication is 14,
   the peer's SABME is 0 and the start response carrying a status word is 7. */
#define RFC_MX_STATE_IDLE           0
#define RFC_MX_STATE_WAIT_CONN_CNF  1
#define RFC_MX_STATE_CONFIGURE      2
#define RFC_MX_STATE_SABME_WAIT_UA  3
#define RFC_MX_STATE_WAIT_SABME     4
#define RFC_MX_STATE_CONNECTED      5
#define RFC_MX_STATE_DISC_WAIT_UA   6
#define RFC_EVENT_SABME             0  /* peer sent SABME on the multiplexer channel */
#define RFC_MX_EVENT_START_RSP      7  /* our start request finished; status word in p_data */
#define RFC_MX_EVENT_DISC_IND       14 /* the L2CAP link under the multiplexer went down */
#define RFCOMM_MX_DLCI              0  /* DLCI of the multiplexer control channel */
#define RFCOMM_MIN_OFFSET           5  /* rfcdefs.h: ctrl 2, len 1 or 2 bytes, credit 1 byte */
#define rfc_cb_trace_level          (lbl_803C4828[0x414]) /* RFCOMM_TRACE_LEVEL_* */

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

void rfc_mx_sm_state_idle(void *muxControlBlock, s32 event, void *eventData) {
    /* RFCOMM multiplexer state machine: IDLE state. Handles incoming events to
       initiate/accept an L2CAP channel, respond to connection indications, and
       transition the multiplexer control state. */
    extern u8 lbl_803C4828[];
    extern char jumptable_803197F8[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void PORT_StartCnf(void *, u16);
    extern void rfc_timer_start(void *, u16);
    char *traceStrings = jumptable_803197F8;
    u8 *mcb = (u8 *)muxControlBlock;
    u8 config[0x3C];

    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, traceStrings + 0x1C, event);

    switch (event) {
    case 6: {
        u16 lcid;
        *(u16 *)(mcb + 0x6A) = 0x29A;
        lcid = L2CA_ConnectReq(3, mcb + 0x62);
        *(u16 *)(mcb + 0x68) = lcid;
        if (lcid == 0) {
            PORT_StartCnf(muxControlBlock, 1);
            return;
        }
        fn_800916D8(muxControlBlock, lcid);
        mcb[0x6C] = 1;
        break;
    }
    case 7:
    case 9:
    case 11:
    case 12:
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u8, s32))fn_8007096C)(0x90000, traceStrings + 0x3C, mcb[0x6C], event);
        break;
    case 10:
        if (mcb[0x6D] != 0) {
            L2CA_ConnectRsp(mcb + 0x62, *(u8 *)eventData, *(u16 *)(mcb + 0x68), 1, 0);
            break;
        }
        rfc_timer_start(muxControlBlock, 0x78);
        L2CA_ConnectRsp(mcb + 0x62, *(u8 *)eventData, *(u16 *)(mcb + 0x68), 0, 0);
        if (lbl_803C4828[0x414] >= 4)
            fn_8007093C(0x90003, traceStrings + 0x58);
        memset(config, 0, sizeof(config));
        config[2] = 1;
        *(u16 *)(config + 4) = 0x69B;
        config[0x20] = 0;
        config[6] = 0;
        ((void (*)(u32, void *))L2CA_ConfigReq)(*(u16 *)(mcb + 0x68), config);
        mcb[0x6C] = 2;
        break;
    case 1:
    case 2:
        return;
    case 3:
        rfc_send_dm(muxControlBlock, 0, 1);
        break;
    case 4:
        rfc_send_dm(muxControlBlock, 0, 0);
        break;
    default:
        if (lbl_803C4828[0x414] >= 4)
            ((void (*)(u32, void *, s32, u8))fn_8007096C)(0x90003, traceStrings + 0x70, event, mcb[0x6C]);
        break;
    }
}

void rfc_mx_sm_state_wait_conn_cnf(void *muxCb, s32 event, void *eventData) {
    extern u8 lbl_803C4828[];
    extern char jumptable_803197F8[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_8007096C(u32, void *, u16, u16);
    char *trace = jumptable_803197F8;
    u8 config[0x3C];

    /* RFCOMM multiplexer state: waiting for L2CAP connection/config confirmation. */
    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, trace + 0xCC, event);

    switch (event) {
    case 6:
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u8, s32))fn_8007096C)(0x90000, trace + 0x3C, *(u8 *)((u8 *)muxCb + 0x6C), event);
        break;
    case 9:
        if (*(u16 *)eventData != 0) {
            *(u8 *)((u8 *)muxCb + 0x6C) = 0;
            PORT_StartCnf(muxCb, *(u16 *)eventData);
        } else {
            *(u8 *)((u8 *)muxCb + 0x6C) = 2;
            if (lbl_803C4828[0x414] >= 4)
                fn_8007093C(0x90003, trace + 0x58);
            memset(config, 0, sizeof(config));
            config[2] = 1;
            *(u16 *)(config + 4) = 0x69B;
            config[0x20] = 0;
            config[6] = 0;
            ((void (*)(u32, void *))L2CA_ConfigReq)(*(u16 *)((u8 *)muxCb + 0x68), config);
        }
        break;
    case 14:
        *(u8 *)((u8 *)muxCb + 0x6C) = 0;
        PORT_CloseInd(muxCb);
        break;
    case 5:
        *(u8 *)((u8 *)muxCb + 0x6C) = 0;
        L2CA_DisconnectReq(*(u16 *)((u8 *)muxCb + 0x68));
        PORT_CloseInd(muxCb);
        break;
    default:
        if (lbl_803C4828[0x414] >= 4)
            ((void (*)(u32, void *, s32, u8))fn_8007096C)(0x90003, trace + 0x70, event, *(u8 *)((u8 *)muxCb + 0x6C));
        break;
    }
}

/* Handle RFCOMM multiplexer events while in the configure state. */
void rfc_mx_sm_state_configure(void *p_mcb, s32 event, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char jumptable_803197F8[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void rfc_mx_conf_ind(void *, void *);
    extern void rfc_mx_conf_cnf(void *, u16 *);
    extern void PORT_CloseInd(void *);
    char *trace = jumptable_803197F8;

    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, trace + 0xF4, event);

    switch (event) {
    case 6:
    case 9:
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, s32, s32))fn_8007096C)(0x90000, trace + 0x3C, *(u8 *)((u8 *)p_mcb + 0x6C), event);
        break;
    case 12:
        rfc_mx_conf_ind(p_mcb, p_data);
        break;
    case 11:
        rfc_mx_conf_cnf(p_mcb, (u16 *)p_data);
        break;
    case 14:
        *(u8 *)((u8 *)p_mcb + 0x6C) = 0;
        PORT_CloseInd(p_mcb);
        break;
    default:
        if (lbl_803C4828[0x414] >= 4)
            ((void (*)(u32, void *, s32, s32))fn_8007096C)(0x90003, trace + 0x70, event, *(u8 *)((u8 *)p_mcb + 0x6C));
        break;
    }
}

/* RFCOMM multiplexer SABME-wait-UA state: handle UA/DM/disconnect/config events while awaiting peer UA. */
void rfc_mx_sm_sabme_wait_ua(void *p_mcb, s32 event, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char jumptable_803197F8[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void rfc_mx_conf_ind(void *, void *);
    extern void rfc_mx_conf_cnf(void *, u16 *);
    extern void rfc_timer_stop(void *);
    extern void PORT_CloseInd(void *);
    extern void PORT_StartCnf(void *, u16);
    char *trace = jumptable_803197F8;
    u8 *mcb = (u8 *)p_mcb;
    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, trace + 0x13C, event);
    switch (event) {
    case 6:
    case 9:
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, s32, s32))fn_8007096C)(0x90000, trace + 0x3C, mcb[0x6C], event);
        break;
    case 12:
        rfc_mx_conf_ind(p_mcb, p_data);
        break;
    case 11:
        rfc_mx_conf_cnf(p_mcb, (u16 *)p_data);
        break;
    case 14:
        mcb[0x6C] = 0;
        PORT_CloseInd(p_mcb);
        break;
    case 1:
        rfc_timer_stop(p_mcb);
        mcb[0x6C] = 5;
        mcb[0x71] = 1;
        PORT_StartCnf(p_mcb, 0);
        break;
    case 2:
        rfc_timer_stop(p_mcb);
    case 5:
        mcb[0x6C] = 0;
        L2CA_DisconnectReq(*(u16 *)(mcb + 0x68));
        PORT_StartCnf(p_mcb, 1);
        break;
    default:
        if (lbl_803C4828[0x414] >= 4)
            ((void (*)(u32, void *, s32, s32))fn_8007096C)(0x90003, trace + 0x70, event, mcb[0x6C]);
        break;
    }
}

/* RFCOMM multiplexer state machine, WAIT_SABME state: the L2CAP link is configured
   and we wait for the peer to open the multiplexer channel with a SABME, or for
   our own start request to come back. */
void rfc_mx_sm_state_wait_sabme(void *p_mcb, s32 event, void *p_data) {
    extern char lbl_80319868[];
    extern void PORT_CloseInd(void *);
    extern void PORT_StartInd(void *);
    extern void rfc_send_ua(void *, s32, void *);
    tRFC_MCB_VIEW *mcb = (tRFC_MCB_VIEW *)p_mcb;

    if (rfc_cb_trace_level >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, lbl_80319994, event);

    switch (event) {
    case RFC_MX_EVENT_DISC_IND:
        mcb->state = RFC_MX_STATE_IDLE;
        PORT_CloseInd(p_mcb);
        return;
    case RFC_EVENT_SABME:
        PORT_StartInd(p_mcb);
        return;
    case RFC_MX_EVENT_START_RSP:
        if (*(u16 *)p_data != 0) { /* status != RFCOMM_SUCCESS: refuse the channel */
            rfc_send_dm(p_mcb, RFCOMM_MX_DLCI, TRUE);
            return;
        }
        ((void (*)(void *, s32))rfc_send_ua)(p_mcb, RFCOMM_MX_DLCI);
        mcb->state = RFC_MX_STATE_CONNECTED;
        mcb->peer_ready = TRUE;
        return;
    default:
        if (rfc_cb_trace_level >= 4)
            ((void (*)(u32, void *, s32, u16))fn_8007096C)(0x90003, lbl_80319868, event, mcb->state);
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

    /* RFCOMM multiplexer state machine: CONNECTED state event handler. */
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

/* RFCOMM multiplexer state machine: handle events while waiting for UA after disconnect. */
void rfc_mx_sm_state_disc_wait_ua(void *muxCb, s32 event, void *eventData) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319A0C[];
    extern char lbl_80319868[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void rfc_send_ua(void *, s32, void *);
    extern void GKI_freebuf(void *);
    extern void PORT_CloseInd(void *);
    extern void PORT_StartCnf(void *, u16);
    u8 *muxCbBytes = (u8 *)muxCb;

    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32))fn_80070954)(0x90003, lbl_80319A0C, event);

    switch (event) {
    case 1:
    case 2:
    case 5:
        L2CA_DisconnectReq(*(u16 *)(muxCbBytes + 0x68));
        if (muxCbBytes[0x70]) {
            u16 lcid = L2CA_ConnectReq(3, muxCbBytes + 0x62);
            *(u16 *)(muxCbBytes + 0x68) = lcid;
            if (lcid == 0) {
                PORT_StartCnf(muxCb, 1);
                return;
            }
            fn_800916D8(muxCb, lcid);
            muxCbBytes[0x70] = 0;
            muxCbBytes[0x6e] = 0;
            muxCbBytes[0x6f] = 0;
            muxCbBytes[0x6c] = 1;
        } else {
            rfc_release_multiplexer_channel(muxCb);
        }
        return;
    case 3:
        ((void (*)(void *, u8))rfc_send_ua)(muxCb, 0);
        return;
    case 4:
        GKI_freebuf(eventData);
        rfc_send_dm(muxCb, 0, 0);
        return;
    case 6:
        muxCbBytes[0x70] = 1;
        return;
    case 14:
        muxCbBytes[0x6c] = 0;
        PORT_CloseInd(muxCb);
        return;
    case 8:
        return;
    case 13:
        break;
    default:
        break;
    }

    if (lbl_803C4828[0x414] >= 4)
        ((void (*)(u32, void *, s32, u32))fn_8007096C)(0x90003, lbl_80319868, event, muxCbBytes[0x6c]);
}

/* Handle the L2CA_ConfigCnf event on the RFCOMM multiplexer channel. If L2CAP
   refused our configuration, tell the port layer that the start failed (when we
   opened the channel) and release the multiplexer channel; otherwise note that
   our configuration is out and, once the peer's has arrived as well, send the
   multiplexer SABME (initiator) or wait for the peer to send it (responder). */
void rfc_mx_conf_cnf(void *arg0, u16 *arg1) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319A70[];
    extern void rfc_send_sabme();
    tRFC_MCB_VIEW *mcb = (tRFC_MCB_VIEW *)arg0;
    tL2CAP_CFG_INFO *p_cfg = (tL2CAP_CFG_INFO *)arg1;

    if (rfc_cb_trace_level >= BT_TRACE_LEVEL_EVENT) {
        /* "rfc_mx_conf_cnf p_cfg:%08x res:%d " - the cast keeps the pointer
           whole in the third argument. */
        ((void (*)(u32, void *, void *, u16))fn_8007096C)(
            TRACE_LAYER_RFCOMM | TRACE_TYPE_EVENT, lbl_80319A70, p_cfg,
            p_cfg ? p_cfg->result : 0);
    }

    if (p_cfg->result != L2CAP_CFG_OK) {
        if (mcb->is_initiator) {
            PORT_StartCnf(arg0, p_cfg->result);
            L2CA_DisconnectReq(mcb->lcid);
        }
        rfc_release_multiplexer_channel(arg0);
        return;
    }

    mcb->local_cfg_sent = TRUE;
    if (mcb->state == RFC_MX_STATE_CONFIGURE && mcb->peer_cfg_rcvd) {
        if (mcb->is_initiator) {
            mcb->state = RFC_MX_STATE_SABME_WAIT_UA;
            /* rfc_send_sabme() is defined in this unit with one argument too
               many; the original symbol takes (p_mcb, dlci). */
            ((void (*)(void *, u8))rfc_send_sabme)(arg0, RFCOMM_MX_DLCI);
            return;
        }
        mcb->state = RFC_MX_STATE_WAIT_SABME;
    }
}

/* Handle the peer's L2CA_ConfigInd on the RFCOMM multiplexer channel: save the
   peer's L2CAP MTU (less the framing RFCOMM puts on every frame), answer the
   configuration with L2CAP_CFG_OK, and note that the peer's configuration has
   arrived.  Once our own configuration has been confirmed as well, send the
   multiplexer SABME (if we are the initiator) or wait for the peer's. */
void rfc_mx_conf_ind(void *p_mcb, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319A94[];
    extern void rfc_send_sabme();
    tRFC_MCB_VIEW *mcb = (tRFC_MCB_VIEW *)p_mcb;
    /* the peer's L2CAP configuration, handed straight back in the response */
    tL2CAP_CFG_INFO *p_cfg = (tL2CAP_CFG_INFO *)p_data;

    if (rfc_cb_trace_level >= BT_TRACE_LEVEL_EVENT)
        /* "rfc_mx_conf_ind p_cfg:%0x" */
        ((void (*)(u32, void *, void *))fn_80070954)(
            TRACE_LAYER_RFCOMM | TRACE_TYPE_EVENT, lbl_80319A94, p_cfg);

    /* RFCOMM adds 3-4 bytes in the beginning and 1 byte FCS to the MTU */
    if (p_cfg->mtu_present) {
        mcb->peer_l2cap_mtu = p_cfg->mtu - RFCOMM_MIN_OFFSET - 1;
    } else {
        mcb->peer_l2cap_mtu = L2CAP_DEFAULT_MTU - RFCOMM_MIN_OFFSET - 1;
    }

    /* Nothing of ours to negotiate: reply to the peer's request as-is */
    p_cfg->mtu_present = FALSE;
    p_cfg->flush_to_present = FALSE;
    p_cfg->qos_present = FALSE;
    p_cfg->result = L2CAP_CFG_OK;
    L2CA_ConfigRsp(mcb->lcid, p_cfg);

    mcb->peer_cfg_rcvd = TRUE;
    if (mcb->state == RFC_MX_STATE_CONFIGURE && mcb->local_cfg_sent) {
        if (mcb->is_initiator) {
            mcb->state = RFC_MX_STATE_SABME_WAIT_UA;
            /* rfc_send_sabme() is defined in this unit with one argument too
               many; the original symbol takes (p_mcb, dlci). */
            ((void (*)(void *, u8))rfc_send_sabme)(p_mcb, RFCOMM_MX_DLCI);
            return;
        }
        mcb->state = RFC_MX_STATE_WAIT_SABME;
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
    /* RFCOMM port state machine (CLOSED): handle open/security/connect/close/timeout
     * events, requesting security checks or sending DM/freeing buffers as needed. */
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

/* RFCOMM port state machine: handle events while waiting for UA after SABME. */
void rfc_port_sm_sabme_wait_ua(void *p_port, u16 event, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319AC4[];
    extern char lbl_80319B44[];
    extern void rfc_port_closed(void *);
    extern void rfc_port_timer_stop(void *);
    extern void rfc_send_disc();
    extern void rfc_send_ua();
    u8 *portCb = (u8 *)p_port;

    switch (event) {
    case 9:
    case 11:
    log_event:
        if (lbl_803C4828[0x414] >= 1)
            fn_8007096C(0x90000, lbl_80319AC4, portCb[0x68], event);
        return;
    case 12:
        rfc_port_timer_start(p_port, 3);
        ((void (*)(void *, u8))rfc_send_disc)(*(void **)(portCb + 0x6C), portCb[0xD]);
        portCb[0x69] = 0;
        portCb[0x68] = 5;
        return;
    case 13:
        rfc_port_closed(p_port);
        return;
    case 14:
        GKI_freebuf(p_data);
        goto log_default;
    case 2:
        rfc_port_timer_stop(p_port);
        portCb[0x68] = 4;
        PORT_DlcEstablishCnf(*(void **)(portCb + 0x6C), portCb[0xD],
                             *(u16 *)(*(u8 **)(portCb + 0x6C) + 0x6A), 0);
        return;
    case 3:
        PORT_DlcEstablishCnf(*(void **)(portCb + 0x6C), portCb[0xD],
                             *(u16 *)(*(u8 **)(portCb + 0x6C) + 0x6A), 1);
        rfc_port_closed(p_port);
        return;
    case 4:
        ((void (*)(void *, u8))rfc_send_ua)(*(void **)(portCb + 0x6C), portCb[0xD]);
        PORT_DlcEstablishCnf(*(void **)(portCb + 0x6C), portCb[0xD],
                             *(u16 *)(*(u8 **)(portCb + 0x6C) + 0x6A), 1);
        rfc_port_closed(p_port);
        return;
    case 5:
        ((void (*)(void *, u8))rfc_send_ua)(*(void **)(portCb + 0x6C), portCb[0xD]);
        return;
    case 1:
        GKI_freebuf(p_data);
        return;
    case 0:
        portCb[0x68] = 0;
        PORT_DlcEstablishCnf(*(void **)(portCb + 0x6C), portCb[0xD],
                             *(u16 *)(*(u8 **)(portCb + 0x6C) + 0x6A), 1);
        return;
    default:
    log_default:
        if (lbl_803C4828[0x414] >= 2)
            fn_80070954(0x90001, lbl_80319B44, event);
        return;
    }
}

/* RFCOMM port state machine: TERM_WAIT_SEC_CHECK state.
 * Handles security-check completion and teardown events while waiting to
 * establish/release the DLC after a security procedure.
 */
void rfc_port_sm_term_wait_sec_check(void *p_port, u16 event, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319AB0[];
    extern void rfc_port_closed(void *);
    extern void rfc_send_ua();
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void fn_8007093C(u32, void *);
    extern void fn_80070954(u32, void *, u16);
    u8 *port = (u8 *)p_port;
    u8 *data = (u8 *)p_data;
    char *messages = lbl_80319AB0;

    switch (event) {
    case 15:
        if (*data != 0) {
            if (*(void **)(port + 0x6C) != 0) {
                rfc_send_dm(*(void **)(port + 0x6C), port[0xD], 1);
                ((void (*)(void *, u8))port_rfc_closed)(p_port, 15);
            }
        } else {
            PORT_DlcEstablishInd((s32)*(void **)(port + 0x6C), (s32)port[0xD], (s32)*(u16 *)((u8 *)*(void **)(port + 0x6C) + 0x6A));
        }
        return;
    case 9:
    case 12:
        if (lbl_803C4828[0x414] >= 1)
            fn_8007096C(0x90000, messages + 0x14, port[0x68], event);
        return;
    case 13:
        btm_sec_abort_access_req((u8 *)*(void **)(port + 0x6C) + 0x62);
        rfc_port_closed(p_port);
        return;
    case 14:
        if (lbl_803C4828[0x414] >= 1)
            fn_8007093C(0x90000, messages + 0xFC);
        GKI_freebuf(p_data);
        return;
    case 0:
        return;
    case 3:
        btm_sec_abort_access_req((u8 *)*(void **)(port + 0x6C) + 0x62);
        port[0x68] = 0;
        ((void (*)(void *, u8))rfc_send_ua)(*(void **)(port + 0x6C), port[0xD]);
        PORT_DlcReleaseInd(*(void **)(port + 0x6C), port[0xD]);
        return;
    case 4:
        GKI_freebuf(p_data);
        return;
    case 11:
        if (*data != 0) {
            if (*(void **)(port + 0x6C) != 0)
                rfc_send_dm(*(void **)(port + 0x6C), port[0xD], 1);
        } else {
            ((void (*)(void *, u8))rfc_send_ua)(*(void **)(port + 0x6C), port[0xD]);
            port[0x68] = 4;
        }
        return;
    }
    if (lbl_803C4828[0x414] >= 2)
        fn_80070954(0x90001, messages + 0x128, event);
}

/* RFCOMM port state machine: originator waits for security check result. */
void rfc_port_sm_orig_wait_sec_check(void *port, u16 event, void *data) {
    extern char lbl_80319AB0[];
    extern void rfc_send_sabme();
    extern void rfc_port_closed(void *);
    u8 *portBytes = port;
    char *messages = lbl_80319AB0;
    switch (event) {
    case 15:
        if (*(u8 *)data != 0) {
            PORT_DlcEstablishCnf(*(void **)(portBytes + 0x6C), portBytes[0xD], 0, 0x70);
            rfc_port_closed(port);
            return;
        }
        ((void (*)(void *, u8))rfc_send_sabme)(*(void **)(portBytes + 0x6C), portBytes[0xD]);
        rfc_port_timer_start(port, 0x3C);
        portBytes[0x68] = 1;
        return;
    case 9:
    case 0:
        if (lbl_803C4828[0x414] >= 1) fn_8007096C(0x90000, messages + 0x14, portBytes[0x68], event);
        return;
    case 12:
        btm_sec_abort_access_req((u8 *)*(void **)(portBytes + 0x6C) + 0x62);
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

/* RFCOMM port state machine handler for the OPENED state. */
void rfc_port_sm_opened(void *p_port, u16 event, void *p_data)
{
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

/* Handle RFCOMM port events while in the DISC_WAIT_UA state. */
void rfc_port_sm_disc_wait_ua(void *p_port, s32 event, void *p_data) {
    extern u8 lbl_803C4828[];
    extern char lbl_80319AC4[];
    extern char lbl_80319D48[];
    extern void fn_80070954(u32, void *, u16);
    extern void fn_8007096C(u32, void *, u16, u16);
    extern void rfc_port_closed(void *);
    extern void GKI_freebuf(void *);
    extern void rfc_send_dm(void *, u8, BOOLEAN);

    u8 *port = (u8 *)p_port;

    switch (event) {
    case 9:
    case 11:
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u32, u32))fn_8007096C)(0x90000, lbl_80319AC4, port[0x68], event);
        return;
    case 13:
        rfc_port_closed(p_port);
        return;
    case 14:
        GKI_freebuf(p_data);
        return;
    case 1:
        *(u8 *)(*(u8 **)(port + 0x6C) + 0x74) = 1;
    case 2:
        rfc_port_closed(p_port);
        return;
    case 0:
        rfc_send_dm(*(void **)(port + 0x6C), port[0xD], TRUE);
        return;
    case 3:
        rfc_send_dm(*(void **)(port + 0x6C), port[0xD], TRUE);
        return;
    case 4:
        GKI_freebuf(p_data);
        rfc_send_dm(*(void **)(port + 0x6C), port[0xD], FALSE);
        return;
    case 5:
        rfc_port_closed(p_port);
        return;
    case 6:
    case 7:
    case 8:
    case 10:
    case 12:
    default:
        if (lbl_803C4828[0x414] >= 2)
            ((void (*)(u32, void *, u32))fn_80070954)(0x90001, lbl_80319D48, event);
        return;
    }
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
        if (mcb == 0)
            return;
        flag = *(u8 *)((u8 *)mcb + 0x69);
        if ((flag & 1) != 0)
            goto do_clear;
        goto end;
    do_clear:
        *(u8 *)((u8 *)mcb + 0x69) = flag & 0xFE;
        rfc_port_timer_stop(mcb);
        PORT_ParNegCnf(arg0, dlci, *(u16 *)((u8 *)arg2 + 0xE), *(u8 *)((u8 *)arg2 + 0xA), *(u8 *)((u8 *)arg2 + 0x11));
    end:;
    }
}

/* ---- RFCOMM Remote Port Negotiation (RPN) names ----------------------------
 * These live in include/revolution/BTE/stack/rfcomm/port_int.h,
 * .../stack/include/port_api.h and .../stack/include/rfcdefs.h.  This auto unit
 * carries its own MX_FRAME / tRFC_MCB declarations and cannot include them, so
 * the names rfc_process_rpn() needs are spelled out here (same names, same
 * values, same offsets).
 */
struct tRFC_MCB;
#ifndef PORT_API_H
/* tPORT_STATE (port_api.h): the RFCOMM line parameters of a port */
typedef struct {
    UINT8 baud_rate;    /* 0x00 PORT_BAUD_RATE_* */
    UINT8 byte_size;    /* 0x01 PORT_*_BITS */
    UINT8 stop_bits;    /* 0x02 */
    UINT8 parity;       /* 0x03 */
    UINT8 parity_type;  /* 0x04 */
    UINT8 fc_type;      /* 0x05 flow control, RFCOMM_FC_* */
    UINT8 rx_char1;     /* 0x06 */
    UINT8 xon_char;     /* 0x07 */
    UINT8 xoff_char;    /* 0x08 */
} tPORT_STATE;
#endif
#ifndef PORT_INT_H
/* tPORT_CTRL (port_int.h): the modem status of a port, carried in an MSC frame */
typedef struct {
    UINT8   modem_signal;     /* 0x00 [DTR/DSR | RTS/CTS | RI | DCD] */
    UINT8   break_signal;     /* 0x01 0-3 s in steps of 200 ms */
    UINT8   discard_buffers;  /* 0x02 0 - do not discard, 1 - discard */
    UINT8   break_signal_seq; /* 0x03 RFCOMM_CTRL_BREAK_* */
    BOOLEAN fc;               /* 0x04 TRUE when we cannot accept more frames */
} tPORT_CTRL;
/* tPORT (port_int.h) as far as the RFCOMM port code reaches into it; the tx/rx
 * queues (tPORT_DATA) and the peer's modem control block are left as raw padding. */
typedef struct {
    UINT8   inx;                  /* 0x00 index in the port_info array */
    UINT8   in_use;               /* 0x01 */
    UINT8   state;                /* 0x02 PORT_STATE_* */
    UINT8   scn;                  /* 0x03 service channel number */
    UINT16  uuid;                 /* 0x04 */
    UINT8   bd_addr[6];           /* 0x06 BD ADDR of the multiplexer channel */
    UINT8   is_server;            /* 0x0C */
    UINT8   dlci;                 /* 0x0D DLCI of the connection */
    UINT8   error;                /* 0x0E last error detected */
    UINT8   line_status;          /* 0x0F line status as reported by the peer */
    UINT8   default_signal_state; /* 0x10 */
    UINT8   pad11;                /* 0x11 */
    UINT16  mtu;                  /* 0x12 max MTU this port can receive */
    UINT16  peer_mtu;             /* 0x14 max MTU this port can send */
    UINT8   queues[0x51 - 0x16];  /* 0x16 tPORT_DATA tx and rx */
    tPORT_STATE peer_port_pars;   /* 0x51 peer's port parameters */
    tPORT_CTRL local_ctrl;        /* 0x5A our modem status, sent to the peer in an MSC */
    UINT8   pad5F[0x68 - 0x5F];   /* 0x5F peer ctrl, port_ctrl, rx flag */
    UINT8   rfc_state;            /* 0x68 tRFC_PORT.rfc.state, RFC_STATE_* */
    UINT8   expected_rsp;         /* 0x69 tRFC_PORT.rfc.expected_rsp, RFC_RSP_* */
} tPORT_VIEW;
#endif
#define RFC_RSP_RPN_REPLY       0x02  /* peer answers our RPN request */
#define RFC_RSP_RPN             0x04  /* peer answers our RPN command */
#define RFC_RSP_MSC             0x08  /* peer answers our MSC command */

#define PORT_STATE_OPENED       2     /* tPORT.state: the port is connected */
#define RFC_STATE_OPENED        4     /* tRFC_PORT.rfc.state: the DLCI is established */

#define RFCOMM_FLOW_STATE_DISABLE   0 /* the port will not accept more data */
#define RFCOMM_FLOW_STATE_ENABLE    1 /* the port can accept data again */

#define RFC_T2_TIMEOUT          60    /* seconds to wait for an MSC/PN reply; the SDK's
                                       * rfc_int.h has 20, this build waits 60 */

#define RFCOMM_FC_OFF               0x00
#define RFCOMM_FC_RTR_ON_INPUT      0x04
#define RFCOMM_FC_RTR_ON_OUTPUT     0x08
#define RFCOMM_FC_RTC_ON_INPUT      0x10
#define RFCOMM_FC_RTC_ON_OUTPUT     0x20

#define RFCOMM_RPN_PM_RTR_ON_INPUT  0x0400
#define RFCOMM_RPN_PM_RTR_ON_OUTPUT 0x0800
#define RFCOMM_RPN_PM_RTC_ON_INPUT  0x1000
#define RFCOMM_RPN_PM_RTC_ON_OUTPUT 0x2000
#define RFCOMM_RPN_PM_MASK          0x3F7F

#define RFCOMM_SUCCESS              0
#define RFC_PORT_T1_TIMEOUT         60  /* seconds to wait for a port reply */

void rfc_set_port_state(void *, void *);
/* RFCOMM Remote Port Negotiation (RPN) command/response.  A command is passed
 * up to the user as PORT_PortNegInd(); a response to a request we sent is
 * checked and, when the peer will not take the flow control we proposed, we
 * retry with RTC and then fall back to no flow control at all.
 * (rfc_int.h: rfc_process_rpn(tRFC_MCB *p_mcb, BOOLEAN is_command,
 *                             BOOLEAN is_request, MX_FRAME *p_frame)) */
void rfc_process_rpn(struct tRFC_MCB *p_mcb, BOOLEAN is_command, void *is_request, MX_FRAME *p_frame) {
    tPORT_STATE port_pars;
    tPORT_VIEW *p_port;
    tPORT_VIEW *p_rsp_port;
    UINT8 ctrl;         /* tRFC_PORT.expected_rsp, then tPORT_STATE.fc_type */
    UINT16 param_mask;

    p_port = (tPORT_VIEW *)port_find_mcb_dlci_port(p_mcb, p_frame->dlci);
    if (p_port == NULL) {
        /* first command on this port: hand the parameters straight to the user */
        if (is_command == 0) return;
        memset(&port_pars, 0, sizeof(tPORT_STATE));
        rfc_set_port_state((u8 *)&port_pars, p_frame);
        PORT_PortNegInd(p_mcb, p_frame->dlci, (u8 *)&port_pars, p_frame->u.rpn.param_mask);
        return;
    }
    if (is_command != 0 && is_request != 0) {
        /* the peer only wants to know our parameters: send them back as a reply */
        port_pars = p_port->peer_port_pars;
        rfc_send_rpn(p_mcb, p_frame->dlci, 0, &p_port->peer_port_pars, 0);
        return;
    }
    port_pars = p_port->peer_port_pars;
    rfc_set_port_state((u8 *)&port_pars, p_frame);
    if (is_command != 0) {
        PORT_PortNegInd(p_mcb, p_frame->dlci, (u8 *)&port_pars, p_frame->u.rpn.param_mask);
        return;
    }
    /* response: ignore it unless we are still waiting for an RPN answer */
    p_rsp_port = (tPORT_VIEW *)port_find_mcb_dlci_port(p_mcb, p_frame->dlci);
    if (p_rsp_port == NULL || (p_rsp_port->expected_rsp & (RFC_RSP_RPN | RFC_RSP_RPN_REPLY)) == 0) return;
    rfc_port_timer_stop(p_rsp_port);
    ctrl = p_rsp_port->expected_rsp;
    if (ctrl & RFC_RSP_RPN_REPLY) {
        /* the peer answered the request we sent with mask 0 */
        p_rsp_port->expected_rsp = ctrl & ~RFC_RSP_RPN_REPLY;
        p_rsp_port->peer_port_pars = port_pars;
        if (port_pars.fc_type == (RFCOMM_FC_RTR_ON_INPUT | RFCOMM_FC_RTR_ON_OUTPUT) ||
            port_pars.fc_type == (RFCOMM_FC_RTC_ON_INPUT | RFCOMM_FC_RTC_ON_OUTPUT)) {
            /* satisfactory parameters: mark every one of them as accepted */
            p_frame->u.rpn.param_mask = RFCOMM_RPN_PM_MASK;
        } else {
            /* not good, try to fix them */
            p_rsp_port->peer_port_pars.fc_type = (RFCOMM_FC_RTR_ON_INPUT | RFCOMM_FC_RTR_ON_OUTPUT);
            p_rsp_port->expected_rsp |= RFC_RSP_RPN;
            rfc_send_rpn(p_mcb, p_frame->dlci, TRUE, &p_rsp_port->peer_port_pars,
                         RFCOMM_RPN_PM_RTR_ON_INPUT | RFCOMM_RPN_PM_RTR_ON_OUTPUT);
            rfc_port_timer_start(p_rsp_port, RFC_PORT_T1_TIMEOUT);
            return;
        }
    } else {
        p_rsp_port->expected_rsp = ctrl & ~RFC_RSP_RPN;
    }
    /* check whether all the parameters we suggested were accepted */
    param_mask = p_frame->u.rpn.param_mask;
    if ((param_mask & (RFCOMM_RPN_PM_RTR_ON_INPUT | RFCOMM_RPN_PM_RTR_ON_OUTPUT)) == (RFCOMM_RPN_PM_RTR_ON_INPUT | RFCOMM_RPN_PM_RTR_ON_OUTPUT) ||
        (param_mask & (RFCOMM_RPN_PM_RTC_ON_INPUT | RFCOMM_RPN_PM_RTC_ON_OUTPUT)) == (RFCOMM_RPN_PM_RTC_ON_INPUT | RFCOMM_RPN_PM_RTC_ON_OUTPUT)) {
        PORT_PortNegCnf(p_mcb, p_rsp_port->dlci, (u8 *)&port_pars, RFCOMM_SUCCESS);
        return;
    }
    ctrl = p_rsp_port->peer_port_pars.fc_type;
    /* we were proposing RTR: try RTC instead */
    if (ctrl == (RFCOMM_FC_RTR_ON_INPUT | RFCOMM_FC_RTR_ON_OUTPUT)) {
        p_rsp_port->peer_port_pars.fc_type = (RFCOMM_FC_RTC_ON_INPUT | RFCOMM_FC_RTC_ON_OUTPUT);
        p_rsp_port->expected_rsp |= RFC_RSP_RPN;
        rfc_send_rpn(p_mcb, p_frame->dlci, TRUE, &p_rsp_port->peer_port_pars,
                     RFCOMM_RPN_PM_RTC_ON_INPUT | RFCOMM_RPN_PM_RTC_ON_OUTPUT);
        rfc_port_timer_start(p_rsp_port, RFC_PORT_T1_TIMEOUT);
        return;
    }
    /* we were proposing RTC: the other side does not support flow control */
    if (ctrl == (RFCOMM_FC_RTC_ON_INPUT | RFCOMM_FC_RTC_ON_OUTPUT)) {
        p_rsp_port->peer_port_pars.fc_type = RFCOMM_FC_OFF;
        PORT_PortNegCnf(p_mcb, p_rsp_port->dlci, (u8 *)&port_pars, RFCOMM_SUCCESS);
    }
}

/* Processes an RFCOMM MSC (modem status command/response) message for a port. */
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
            flow = data[4];
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

// Copy RPN port parameters from an MX frame into a port state, for each field
// whose corresponding bit is set in the frame's parameter mask (u16 at +0x12).
void rfc_set_port_state(void *portState, void *frame) {
    if (*(u16 *)((u8 *)frame + 0x12) & 1) {
        *(u8 *)portState = *(u8 *)((u8 *)frame + 0xA);
    }
    if (*(u16 *)((u8 *)frame + 0x12) & 2) {
        *(u8 *)((u8 *)portState + 1) = *(u8 *)((u8 *)frame + 0xB);
    }
    if (*(u16 *)((u8 *)frame + 0x12) & 4) {
        *(u8 *)((u8 *)portState + 2) = *(u8 *)((u8 *)frame + 0xC);
    }
    if (*(u16 *)((u8 *)frame + 0x12) & 8) {
        *(u8 *)((u8 *)portState + 3) = *(u8 *)((u8 *)frame + 0xD);
    }
    if (*(u16 *)((u8 *)frame + 0x12) & 0x10) {
        *(u8 *)((u8 *)portState + 4) = *(u8 *)((u8 *)frame + 0xE);
    }
    if (*(u16 *)((u8 *)frame + 0x12) & 0x3F00) {
        *(u8 *)((u8 *)portState + 5) = *(u8 *)((u8 *)frame + 0xF);
    }
    if (*(u16 *)((u8 *)frame + 0x12) & 0x20) {
        *(u8 *)((u8 *)portState + 7) = *(u8 *)((u8 *)frame + 0x10);
    }
    if (*(u16 *)((u8 *)frame + 0x12) & 0x40) {
        *(u8 *)((u8 *)portState + 8) = *(u8 *)((u8 *)frame + 0x11);
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

void RFCOMM_ParNegReq(void *mcb, s32 dlci, s32 mtu) {
    /* Sends an RFCOMM parameter negotiation request for a DLCI, choosing frame/credit limits from the port when required. */
    u8 *p_port;
    u32 max_frame;
    u16 peer_mtu;
    u16 frame;
    u8 value;
    u8 credits;

    p_port = ((u8 * (*)())port_find_mcb_dlci_port)();
    if (((u8 *)mcb)[0x6C] != 5) {
        p_port[0xE] = 0xD;
        return;
    }
    value = ((u8 *)mcb)[0x72];
    frame = 2;
    if ((s32)value != 0)
        frame = value;
    if ((u8)frame == 2) {
        peer_mtu = *(u16 *)(p_port + 0x9C);
        max_frame = 0xF0;
        frame = 7;
        if (peer_mtu < 7)
            frame = peer_mtu;
        credits = (u8)frame;
        *(u16 *)(p_port + 0x9A) = credits;
    } else {
        max_frame = 0;
        credits = 0;
    }
    p_port[0x69] |= 1;
    rfc_send_pn(mcb, dlci, 1, mtu, max_frame, credits);
    rfc_port_timer_start(p_port, 0x3C);
}

void fn_800936BC(void *p, u16 a1, u16 a2, u16 a3, u16 a4, u16 a5, u16 a6) {
    if (*((u8 *)p + 0x6C) == 5)
        rfc_send_pn(p, a1, 0, a2, a3, a4);
}

void RFCOMM_PortNegReq(void *mcb, u8 dlci, void *pars) {
    // Requests port parameter negotiation for a DLCI, marking pending flags and sending RPN when the multiplexer is connected.
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

/* RFCOMM flow control request (rfc_port_if.c): the port layer tells us that its
 * ability to receive data changed.  We mirror that in our own modem status
 * (fc = "no more room") and report it to the peer with an MSC command, then wait
 * RFC_T2_TIMEOUT for the peer's answer. */
void RFCOMM_FlowReq(struct tRFC_MCB *p_mcb, UINT8 dlci, UINT8 enable) {
    tPORT_VIEW *p_port = (tPORT_VIEW *)port_find_mcb_dlci_port(p_mcb, dlci);

    if ((p_port->state != PORT_STATE_OPENED) || (p_port->rfc_state != RFC_STATE_OPENED))
        return;

    p_port->local_ctrl.fc = !enable;
    p_port->expected_rsp |= RFC_RSP_MSC;

    rfc_send_msc(p_mcb, dlci, TRUE, &p_port->local_ctrl);
    rfc_port_timer_start(p_port, RFC_T2_TIMEOUT);
}

void RFCOMM_LineStatusReq(void *arg0, u8 arg1, u8 arg2) {
    void *mcb = port_find_mcb_dlci_port(arg0, arg1);
    unsigned int mode;
    if (*((u8 *)mcb + 2) != 2) return;
    mode = *((unsigned char *)mcb + 0x68);
    switch (mode) {
    case 4:
        *((u8 *)mcb + 0x69) |= 0x10;
        rfc_send_rls(arg0, arg1, 1, arg2);
        rfc_port_timer_start(mcb, 0x3C);
        break;
    default:
        return;
    }
}

void fn_800939A0(void *arg0, u8 arg1) { rfc_port_sm_execute(port_find_mcb_dlci_port(arg0, arg1), 0xC, 0); }

void fn_800939CC(void *arg0, u8 arg1, void *arg2) { rfc_port_sm_execute(port_find_mcb_dlci_port(arg0, arg1), 0xE, arg2); }

void rfc_send_sabme(void *p_mcb, s32 dlci, void *unused) {
    BT_HDR *p_buf;
    u8 *p_data;
    u8 cr;
    u8 command = 0x3F;
    u8 initiator = *(u8 *)((u8 *)p_mcb + 0x6D);

    /* Send an RFCOMM SABME command frame for dlci (addr with C/R from initiator, control 0x3F, len 1, FCS). */
    cr = (u8)((((initiator && 1) || (!initiator && !1)) << 1));
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == 0)
        return;

    p_data = (u8 *)(p_buf + 1) + 9;
    p_buf->offset = 9;
    p_data[0] = (u8)(1 | cr | ((u8)dlci << 2));
    p_data[1] = command;
    p_data[2] = 1;
    p_data[3] = fn_8009504C(3, (u8 *)(p_buf + 1) + 9);
    p_buf->len = 4;
    rfc_check_send_cmd(p_mcb, p_buf);
}

/* rfc_ts_frames.c's rfc_calc_fcs() (rfc_int.h's RFCOMM_*_FCS macros expand to
 * it); this auto unit links it under its map name. */
#define rfc_calc_fcs fn_8009504C

/* rfcdefs.h's RFCOMM_CR(initiator, is_command) for a response frame
 * (is_command == 0), with the two tests in the order this build emits them. */
#define RFCOMM_CR_RSP(initiator) ((((!(initiator) && 1) || ((initiator) && !1))) << 1)

/* Builds and sends an RFCOMM UA (unnumbered acknowledgment) frame for `dlci` on
 * the multiplexer channel of `p_mcb`: the C/R bit is the inverse of our
 * initiator flag because this is a response, P/F is set, and the 4-byte frame is
 * handed to rfc_check_send_cmd(). The third argument is unused. */
void rfc_send_ua(void *p_mcb, s32 dlci, void *unused) {
    BT_HDR *p_buf;
    u8 *p_data;
    u8 cr;
    u8 type_field = RFCOMM_UA | RFCOMM_PF;
    u8 initiator = ((tRFC_MCB_VIEW *)p_mcb)->is_initiator;
    cr = (u8)RFCOMM_CR_RSP(initiator);
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(RFCOMM_CMD_POOL_ID)) == 0)
        return;
    p_data = (u8 *)(p_buf + 1) + 9; /* L2CAP_MIN_OFFSET of this build */
    p_buf->offset = 9;
    p_data[0] = (u8)(RFCOMM_EA | cr | ((u8)dlci << RFCOMM_SHIFT_DLCI));
    p_data[1] = type_field;
    p_data[2] = RFCOMM_EA;
    p_data[3] = rfc_calc_fcs(3, (u8 *)(p_buf + 1) + 9);
    p_buf->len = 4;
    rfc_check_send_cmd(p_mcb, p_buf);
}

/* Sends an RFCOMM DM frame for the given DLCI, setting P/F from pf and using the
 * MCB's initiator flag to form the control byte, then queues it for transmit. */
void rfc_send_dm(void *p_mcb, u8 dlci, u8 pf) {
    u8 *p_data;
    u8 *p_buf;
    u8 initiatorFlag;
    u8 control;
    u32 dlciShifted;
    u8 command;

    initiatorFlag = 1;
    if (((u8 *)p_mcb)[0x6D] != 0) {
        initiatorFlag = 0;
    }
    control = (u8)(initiatorFlag << 1);
    p_buf = (u8 *)GKI_getpoolbuf(2);
    if (p_buf != 0) {
        *(u16 *)(p_buf + 4) = 9;
        p_data = p_buf + 0x11;
        control |= 1;
        dlciShifted = dlci << 2;
        command = (u8)(control | dlciShifted);
        p_data[0] = command;
        p_data[1] = (u8)((((-(s32)pf | pf) >> 31) & 0x10) | 0xF);
        p_data[2] = 1;
        p_data[3] = fn_8009504C(3, p_data);
        *(u16 *)(p_buf + 2) = 4;
        rfc_check_send_cmd(p_mcb, p_buf);
    }
}

typedef struct tRFC_MCB tRFC_MCB;

/* Send an RFCOMM DISC (disconnect) command frame for dlci on the multiplexer control block. */
void rfc_send_disc(void *p_mcb, s32 dlci, void *unused) {
    BT_HDR *p_buf;
    u8 *p_data;
    u8 is_initiator;
    u8 cr;

    is_initiator = *((u8 *)p_mcb + 0x6D);
    cr = (u8)((((is_initiator) && 1) || (!(is_initiator) && !1)) << 1);
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == 0)
        return;

    p_buf->offset = 9;
    p_data = (u8 *)(p_buf + 1) + 9;
    *p_data++ = 1 | cr | (((u8)dlci) << 2);
    p_data[0] = 0x53;
    p_data[1] = 1;
    p_data[2] = fn_8009504C(3, (u8 *)(p_buf + 1) + 9);
    p_buf->len = 4;
    rfc_check_send_cmd(p_mcb, p_buf);
}

/* Builds and sends an RFCOMM UIH frame for a DLCI, prepending address/control,
 * length (and credits when present), appending FCS, then dispatching control
 * frames (DLCI 0) via RFCOMM or data frames via L2CAP. */
void rfc_send_buf_uih(p_mcb, dlci, p_buf)
tRFC_MCB *p_mcb;
UINT8 dlci;
BT_HDR *p_buf;
{
    UINT8 *headerPtr;
    UINT8 commandResponse;
    UINT8 creditCount;

    commandResponse = (UINT8)((((*(u8 *)((u8 *)p_mcb + 0x6D) && 1)
        || (!*(u8 *)((u8 *)p_mcb + 0x6D) && !1)) << 1));

    p_buf->offset -= 3;
    if (p_buf->len > 127)
        p_buf->offset--;
    if (dlci)
        creditCount = (u8)p_buf->layer_specific;
    else
        creditCount = 0;
    if (creditCount)
        p_buf->offset--;

    headerPtr = (u8 *)(p_buf + 1) + p_buf->offset;
    *headerPtr++ = (u8)(commandResponse | 1 | (dlci << 2));
    *headerPtr++ = (u8)(0xEF | (creditCount ? 0x10 : 0));
    if (p_buf->len <= 127) {
        *headerPtr++ = (u8)(1 | (p_buf->len << 1));
        p_buf->len += 3;
    } else {
        *headerPtr++ = (u8)((p_buf->len & 0x7F) << 1);
        *headerPtr++ = (u8)(p_buf->len >> 7);
        p_buf->len += 4;
    }
    if (creditCount) {
        *headerPtr++ = creditCount;
        p_buf->len++;
    }

    headerPtr = (u8 *)(p_buf + 1) + p_buf->offset + p_buf->len++;
    *headerPtr = fn_8009504C(2, (u8 *)(p_buf + 1) + p_buf->offset);

    if (dlci == 0)
        rfc_check_send_cmd(p_mcb, p_buf);
    else
        L2CA_DataWrite(*(u16 *)((u8 *)p_mcb + 0x68), p_buf);
}

void rfc_send_pn(void *p_mcb, s32 dlci, s32 is_command, s32 mtu, s32 cl, s32 k) {
    u8 *buf;
    u8 *p_data;
    s32 sign;

    /* Build and send an RFCOMM Parameter Negotiation (PN) multiplexer command/response. */
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
    u8 *buf = (u8 *)GKI_getpoolbuf(2);
    if (buf != 0) {
        s32 sign = (-arg1 | arg1) >> 31;
        u16 f = 2;
        u8 e = 1;
        *(u16 *)(buf + 4) = 12;
        buf[20] = (u8)((sign & 2) | 161);
        buf[21] = e;
        *(u16 *)(buf + 2) = f;
        rfc_send_buf_uih(arg0, 0, buf, 2);
    }
}

void rfc_send_fcon_80093FDC(void *arg0, s32 arg1) { BT_HDR *p_buf; UINT8 *p_data; if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == NULL) return; p_buf->offset = 12; p_data = (UINT8 *)(p_buf + 1) + p_buf->offset; *p_data++ = (UINT8)(0x61 | (arg1 ? 2 : 0)); *p_data = 1; p_buf->len = 2; rfc_send_buf_uih(arg0, 0, p_buf); }

void rfc_send_msc(void *p_mcb, s32 dlci, s32 is_command, u8 *p_pars) {
    BT_HDR *p_buf;
    u8 *p_data;
    u8 signals;
    u8 break_duration;
    u8 len;
    signals = p_pars[0];
    break_duration = p_pars[1];
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == NULL)
        return;
    p_buf->offset = 12;
    p_data = (u8 *)(p_buf + 1) + p_buf->offset;
    if (break_duration)
        len = 3;
    else
        len = 2;
    *p_data++ = (u8)(0xE1 | (is_command ? 2 : 0));
    *p_data++ = (u8)(1 | (len << 1));
    *p_data++ = (u8)(3 | (dlci << 2));
    *p_data++ = (u8)(1 | (p_pars[4] ? 2 : 0) | ((signals & 1) ? 4 : 0) | ((signals & 2) ? 8 : 0) | ((signals & 4) ? 0x40 : 0) | ((signals & 8) ? 0x80 : 0));
    if (break_duration)
        *p_data++ = (u8)(3 | (break_duration << 4));
    p_buf->len = (u16)(len + 2);
    rfc_send_buf_uih(p_mcb, 0, p_buf);
}

/* Send an RFCOMM Remote Line Status (RLS) UIH frame for the given DLCI. */
void rfc_send_rls(void *p_mcb, u8 dlci, s32 isCommand, u8 lineStatus) {
    u8 *p_buf = GKI_getpoolbuf(2);
    if (p_buf != 0) {
        *(u16 *)(p_buf + 4) = 0xC;
        p_buf[0x14] = (u8)((((s32)(-isCommand | isCommand) >> 31) & 2) | 0x51);
        p_buf[0x15] = 5;
        p_buf[0x16] = (u8)((dlci << 2) | 3);
        p_buf[0x17] = lineStatus | 1;
        *(u16 *)(p_buf + 2) = 4;
        rfc_send_buf_uih(p_mcb, 0, p_buf);
    }
}

/* Build and send an RFCOMM Remote Port Negotiation (RPN) command or response. */
void rfc_send_rpn(void *p_mcb, s32 dlci, s32 is_command, u8 *p_pars, s32 mask) {
    u8 *buf;
    u8 *p_data;
    s32 sign;

    buf = (u8 *)GKI_getpoolbuf(2);
    if (buf == NULL)
        return;
    *(u16 *)(buf + 4) = 0xC;
    p_data = buf + 0x14;
    sign = -is_command | is_command;
    *p_data++ = (u8)(((sign >> 31) & 2) | 0x91);
    if (p_pars == NULL) {
        *p_data++ = 3;
        *p_data++ = (u8)((((u8)dlci) << 2) | 3);
        *(u16 *)(buf + 2) = 3;
    } else {
        *p_data++ = 0x11;
        *p_data++ = (u8)((((u8)dlci) << 2) | 3);
        *p_data++ = p_pars[0];
        *p_data++ = (u8)(p_pars[1] | (p_pars[2] << 2) | (p_pars[3] << 3) | (p_pars[4] << 4));
        *p_data++ = p_pars[5];
        *p_data++ = p_pars[7];
        *p_data++ = p_pars[8];
        *p_data++ = (u8)mask;
        *p_data = (u8)(((u16)mask) >> 8);
        *(u16 *)(buf + 2) = 0xA;
    }
    rfc_send_buf_uih(p_mcb, 0, (BT_HDR *)buf);
}

void rfc_send_test(s32 arg0, s32 arg1, void *p_buf) {
    u8 *p = p_buf;
    u16 len = *(u16 *)(p + 4);
    u16 count;
    u8 *src;
    u16 i;
    u8 *dst;
    u8 byte;
    s32 tmp;
    u16 old;
    u16 new_len;
    u8 *q;
    if (len < 0x10) {
        count = *(u16 *)(p + 2);
        src = p + len + count + 7;
        dst = p + count + 0x17;
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
    tmp = -arg1 | arg1;
    old = *(u16 *)(p + 4);
    new_len = old - 2;
    *(u16 *)(p + 4) = new_len;
    q = p + new_len;
    q[8] = ((tmp >> 31) & 2) | 0x21;
    q[9] = (*(u16 *)(p + 2) << 1) | 1;
    count = *(u16 *)(p + 2);
    *(u16 *)(p + 2) = count + 2;
    rfc_send_buf_uih((void *)arg0, 0);
}

/* Build and queue an RFCOMM UIH frame carrying flow-control credits for a DLCI. */
void rfc_send_credit(void *p_mcb, UINT8 credits, UINT8 credit) {
    BT_HDR *p_buf;
    UINT8 *p_data;
    UINT8 initiator = *(UINT8 *)((UINT8 *)p_mcb + 0x6D);
    UINT8 cr = (UINT8)((((initiator && 1) || (!initiator && !1)) << 1));
    if ((p_buf = (BT_HDR *)GKI_getpoolbuf(2)) == 0)
        return;
    p_buf->offset = 9;
    p_data = (UINT8 *)(p_buf + 1) + 9;
    *p_data++ = (UINT8)(1 | cr | ((UINT8)credits << 2));
    *p_data++ = 0xFF;
    *p_data++ = 1;
    *p_data++ = credit;
    *p_data = fn_8009504C(2, (UINT8 *)p_buf + p_buf->offset + 8);
    p_buf->len = 5;
    rfc_check_send_cmd(p_mcb, p_buf);
}

extern u8 fn_80095084();
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
        if ((((s32) temp_r6_3 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || (((s32) temp_r6_3 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || ((s32) (*(u8 *)((u8 *)(arg1) + 4)) == 0) || ((u16) var_r8 != 0) || ((temp_r3 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3 == 0) == 0)) && ((temp_r3 < 2U) || (temp_r3 > 0x3DU))) || (fn_80095084(3, temp_r7, temp_r7[3]) == 0)) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, lbl_80319DD8 + 0x24);
            }
            return 0x32;
        }
        return 0;
    case 0x63:
        temp_r6_4 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r6_4 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || (((s32) temp_r6_4 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || ((s32) (*(u8 *)((u8 *)(arg1) + 4)) == 0) || ((u16) var_r8 != 0) || ((temp_r3_2 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3_2 == 0) == 0)) && ((temp_r3_2 < 2U) || (temp_r3_2 > 0x3DU))) || (fn_80095084(3, temp_r7, temp_r7[3]) == 0)) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, messages + 0x10);
            }
            return 0x32;
        }
        return 1;
    case 0xF:
        temp_r6_5 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r6_5 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || (((s32) temp_r6_5 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || ((u16) var_r8 != 0) || ((temp_r3_3 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3_3 == 0) == 0)) && ((temp_r3_3 < 2U) || (temp_r3_3 > 0x3DU))) || (fn_80095084(3, temp_r7, temp_r7[3]) == 0)) {
            if ((u8) (*(u8 *)((u8 *)(&lbl_803C4828) + 0x414)) >= 1U) {
                fn_8007093C(0x90000, messages + 0x20);
            }
            return 0x32;
        }
        return 2;
    case 0x43:
        temp_r6_6 = (*(u8 *)((u8 *)(arg0) + 0x6D));
        if ((((s32) temp_r6_6 != 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) != 0)) || (((s32) temp_r6_6 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + 2)) == 0)) || ((s32) (*(u8 *)((u8 *)(arg1) + 4)) == 0) || ((u16) var_r8 != 0) || ((temp_r3_4 = (*(u8 *)((u8 *)(arg1) + 0)), (((s32) temp_r3_4 == 0) == 0)) && ((temp_r3_4 < 2U) || (temp_r3_4 > 0x3DU))) || (fn_80095084(3, temp_r7, temp_r7[3]) == 0)) {
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
        if (fn_80095084(2, temp_r7, temp_r7[2]) == 0) {
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

void rfc_process_mx_message(void *p_rfc_mcb, BT_HDR *p_buf)
{
    MX_FRAME *p_rx_frame = (MX_FRAME *)lbl_803C4828;
    UINT8 *p_data;
    s32 len;
    UINT8 length;
    UINT8 ll;
    UINT8 b;
    BOOLEAN is_command;
    char *msgs = lbl_80319DD8;

    len = p_buf->len;
    p_data = (UINT8 *)(p_buf + 1) + p_buf->offset;
    p_rx_frame->ea = p_data[0] & 1;
    is_command = (p_data[0] >> 1) & 1;
    p_rx_frame->cr = is_command;
    p_rx_frame->type = p_data[0] & 0xFC;

    if (!p_rx_frame->ea || !(UINT16)len) {
        if (lbl_803C4828[0x414] >= 1)
            ((void (*)(u32, void *, u32))fn_8007096C)(0x90000, msgs + 0x78, p_rx_frame->ea);
        GKI_freebuf(p_buf);
        return;
    }

    ll = p_data[1];
    p_data += 2;
    length = ll >> 1;
    len = (UINT16)len - 2;
    if (!(ll & 1)) {
        len--;
        length = length + (*p_data++ << 7);
    }

    if (length != (UINT16)len) {
        if (lbl_803C4828[0x414] >= 1)
            fn_8007093C(0x90000, msgs + 0x98);
        GKI_freebuf(p_buf);
        return;
    }

    switch (p_rx_frame->type) {
    case 0x80:
        if ((UINT16)len == 8) {
            p_rx_frame->dlci = p_data[0] & 0x3F;
            p_rx_frame->u.pn.frame_type = p_data[1] & 0xF;
            p_rx_frame->u.pn.conv_layer = p_data[1] & 0xF0;
            p_rx_frame->u.pn.priority = p_data[2] & 0x3F;
            p_rx_frame->u.pn.t1 = p_data[3];
            p_rx_frame->u.pn.mtu = p_data[4] + (p_data[5] << 8);
            p_rx_frame->u.pn.n2 = p_data[6];
            p_rx_frame->u.pn.k = p_data[7] & 7;
            if (!p_rx_frame->dlci || p_rx_frame->dlci < 2 || p_rx_frame->dlci > 0x3D ||
                p_rx_frame->u.pn.mtu < 0x17 || p_rx_frame->u.pn.mtu > 0x7FFF) {
                if (lbl_803C4828[0x414] >= 1)
                    fn_8007093C(0x90000, msgs + 0xA8);
                break;
            }
            GKI_freebuf(p_buf);
            rfc_process_pn(p_rfc_mcb, is_command, p_rx_frame);
            return;
        }
        break;
    case 0x20:
        if ((UINT16)len) {
            p_rx_frame->u.test.p_data = p_data;
            p_rx_frame->u.test.data_len = len;
            p_buf->offset += 2;
            p_buf->len -= 2;
            if (is_command) {
                rfc_send_test((s32)p_rfc_mcb, 0, p_buf);
            } else {
                ((void (*)(void *, BT_HDR *))fn_800932DC)(p_rfc_mcb, p_buf);
            }
            return;
        }
        break;
    case 0xA0:
        if (!(UINT16)len) {
            GKI_freebuf(p_buf);
            rfc_process_fcon(p_rfc_mcb, is_command);
            return;
        }
        break;
    case 0x60:
        if (!(UINT16)len) {
            GKI_freebuf(p_buf);
            rfc_process_fcoff(p_rfc_mcb, is_command);
            return;
        }
        break;
    case 0xE0:
        b = p_data[0];
        p_rx_frame->dlci = b >> 2;
        if (!(b & 1) || !((b & 2) >> 1) || !p_rx_frame->dlci ||
            p_rx_frame->dlci < 2 || p_rx_frame->dlci > 0x3D) {
            if (lbl_803C4828[0x414] >= 1)
                fn_8007093C(0x90000, msgs + 0xB8);
            break;
        }
        p_rx_frame->u.msc.signals = p_data[1];
        if (length == 3) {
            p_rx_frame->u.msc.break_present = p_data[2] & 2;
            p_rx_frame->u.msc.break_duration = (p_data[2] >> 4) & 0xF;
        } else {
            p_rx_frame->u.msc.break_present = 0;
            p_rx_frame->u.msc.break_duration = 0;
        }
        GKI_freebuf(p_buf);
        rfc_process_msc(p_rfc_mcb, is_command, p_rx_frame);
        return;
    case 0x10:
        if ((UINT16)len == 1 && is_command) {
            p_rx_frame->u.nsc.ea = p_data[0] & 1;
            p_rx_frame->u.nsc.cr = (p_data[0] & 2) >> 1;
            p_rx_frame->u.nsc.type = p_data[0] >> 2;
            GKI_freebuf(p_buf);
            ((void (*)(void *, MX_FRAME *))fn_800932D8)(p_rfc_mcb, p_rx_frame);
            return;
        }
        break;
    case 0x90:
        if ((UINT16)len == 1 || (UINT16)len == 8) {
            b = p_data[0];
            p_rx_frame->dlci = b >> 2;
            if (!(b & 1) || !((b & 2) >> 1) || !p_rx_frame->dlci ||
                p_rx_frame->dlci < 2 || p_rx_frame->dlci > 0x3D) {
                if (lbl_803C4828[0x414] >= 1)
                    fn_8007093C(0x90000, msgs + 0xC8);
                break;
            }
            p_rx_frame->u.rpn.is_request = ((UINT16)len == 1);
            if (!p_rx_frame->u.rpn.is_request) {
                p_rx_frame->u.rpn.baud_rate = p_data[1];
                p_rx_frame->u.rpn.byte_size = p_data[2] & 3;
                p_rx_frame->u.rpn.stop_bits = (p_data[2] >> 2) & 1;
                p_rx_frame->u.rpn.parity = (p_data[2] >> 3) & 1;
                p_rx_frame->u.rpn.parity_type = (p_data[2] >> 4) & 3;
                p_rx_frame->u.rpn.fc_type = p_data[3] & 0x3F;
                p_rx_frame->u.rpn.xon_char = p_data[4];
                p_rx_frame->u.rpn.xoff_char = p_data[5];
                p_rx_frame->u.rpn.param_mask = (p_data[6] + (p_data[7] << 8)) & 0x3F7F;
            }
            GKI_freebuf(p_buf);
            rfc_process_rpn(p_rfc_mcb, is_command, (void *)(u32)p_rx_frame->u.rpn.is_request, p_rx_frame);
            return;
        }
        break;
    case 0x50:
        if ((UINT16)len == 2) {
            b = p_data[0];
            p_rx_frame->dlci = b >> 2;
            p_rx_frame->u.rls.line_status = p_data[1] & 0xFE;
            if (!(b & 1) || !((b & 2) >> 1) || !p_rx_frame->dlci ||
                p_rx_frame->dlci < 2 || p_rx_frame->dlci > 0x3D) {
                if (lbl_803C4828[0x414] >= 1)
                    fn_8007093C(0x90000, msgs + 0xC8);
                break;
            }
            GKI_freebuf(p_buf);
            rfc_process_rls(p_rfc_mcb, is_command, p_rx_frame);
            return;
        }
        break;
    }

    GKI_freebuf(p_buf);
    if (is_command) {
        p_buf = GKI_getpoolbuf(2);
        if (p_buf) {
            UINT8 *p;
            p_buf->offset = 12;
            p = (UINT8 *)(p_buf + 1) + 12;
            *p++ = 0x11;
            *p++ = 3;
            *p = p_rx_frame->type | (p_rx_frame->ea | (p_rx_frame->cr << 1));
            p_buf->len = 3;
            rfc_send_buf_uih(p_rfc_mcb, 0, p_buf);
        }
    }
}

u8 fn_8009504C(u16 arg0, u8 *arg1) {
    u8 *table = lbl_802EEC40;
    u8 fcs = 0xFF;
    u8 *ptr = arg1;
    u16 len = arg0;
    while (len-- != 0) {
        fcs = table[fcs ^ *ptr];
        ptr++;
    }
    return (u8)(0xFF - fcs);
}

#pragma push
#pragma scheduling invalid_target
u8 fn_80095084(arg0, arg1, arg2)
u16 arg0;
u8 *arg1;
u8 arg2;
{
    u8 *ptr = arg1;
    u16 len = arg0;
    u8 *table = lbl_802EEC40;
    u8 crc = 0xFF;
    while (len-- != 0) {
        crc = table[crc ^ *ptr];
        ptr++;
    }
    crc = lbl_802EEC40[crc ^ arg2];
    return crc == 0xCF;
}
#pragma pop
extern char lbl_80319EB0[];
/* Allocate or reuse an RFCOMM multiplexer channel for a peer BD address. */
void *rfc_alloc_multiplexer_channel(u8 *addr, s8 is_initiator) {
    u8 *existing;
    long i;
    long j;
    u8 *mcb_base;
    register u8 *channel;
    u8 *peer_addr;
    for (i = 0; i < 1; i++) {
        peer_addr = lbl_803C4828 + i * 0x78 + 0x3FE;
        if (lbl_803C4828[i * 0x78 + 0x408] != 0 &&
            memcmp(peer_addr, addr, 6) == 0) {
            if (lbl_803C4828[0x414] >= 4) fn_8007093C(0x90003, lbl_80319EB0);
            existing = (lbl_803C4828 + 0x39C) + i * 0x78;
            fn_80070F90(existing);
            return existing;
        }
    }
    for (i = 0, j = lbl_803C4828[0x65] + 1; i < 1; i++, j++) {
        if (j >= 1) j = 0;
        mcb_base = lbl_803C4828 + j * 0x78;
        channel = mcb_base + 0x39C;
        if (mcb_base[0x408] == 0) {
            memset(channel, 0, 0x78);
            memcpy(channel + 0x62, addr, 6);
            fn_8006D4C4(channel + 0x18);
            channel[0x6D] = is_initiator;
            if (lbl_803C4828[0x414] >= 4) fn_80070954(0x90003, lbl_80319EC0, 0x3C);
            *(void **)(channel + 0x10) = channel;
            btu_start_timer(channel, 0xB, 0x3C);
            lbl_803C4828[0x65] = j;
            return channel;
        }
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

/* Check if any DLCI is active on this RFCOMM MCB; clear idle state or start close timer as needed. */
void rfc_check_mcb_active(void *p_mcb) {
    u8 *mcb = (u8 *)p_mcb;
    u16 i;
    for (i = 0; i < 0x3D; i++) {
        if (mcb[i + 0x24] != 0) {
            mcb[0x74] = 0;
            return;
        }
    }
    if (mcb[0x74] != 0) {
        mcb[0x74] = 0;
        fn_800916F4(p_mcb, 8, 0);
        return;
    }
    if (lbl_803C4828[0x414] >= 4) {
        fn_80070954(0x90003, lbl_80319EC0, 2);
    }
    *(void **)(mcb + 0x10) = p_mcb;
    btu_start_timer(p_mcb, 0xB, 2);
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
    /* RFCOMM port close handler: stops the port timer, detaches/clears the port's DLCI from
       its MCB (and tears down the MCB if no DLCIs remain), then notifies the upper layer that
       the RFC port closed (reason 0x13). */
    extern unsigned char lbl_803C4828[];
    extern char lbl_80319EB0[];
    register char *messages = lbl_80319EB0;
    register unsigned char *mcb;
    register unsigned char *port = arg0;

    mcb = *(unsigned char **)(port + 0x6C);
    if (lbl_803C4828[0x414] >= 5) fn_8007093C(0x90004, messages + 0x68);
    if (lbl_803C4828[0x414] >= 4) fn_8007093C(0x90003, messages + 0x54);
    fn_80070F90(port + 0x70);
    port[0x68] = 0;
    if (mcb != 0) {
        ((unsigned char *)mcb + port[0xD])[0x24] = 0;
        port[0xD] = 0;
        {
            u16 i;
            for (i = 0; i < 0x3D; i++) {
                if (mcb[i + 0x24] != 0) {
                    mcb[0x74] = 0;
                    goto done;
                }
            }
        }
        if (mcb[0x74] != 0) {
            mcb[0x74] = 0;
            fn_800916F4(mcb, 8, 0);
        } else {
            if (lbl_803C4828[0x414] >= 4)
                fn_80070954(0x90003, messages + 0x10, 2);
            *(void **)(mcb + 0x10) = mcb;
            btu_start_timer(mcb, 0xB, 2);
        }
    }
done:
    port_rfc_closed((struct t_port_info *)port, 0x13);
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
    while (p[0x73] == 0) {
        arg1 = GKI_dequeue((BUFFER_Q *)(p + 0x18));
        if (arg1 == 0) {
            return;
        }
        L2CA_DataWrite(*(u16 *)(p + 0x68), (BT_HDR *)arg1);
    }
}

extern char lbl_80319F40[];
/* SDP_InitDiscoveryDb - initialize a service-discovery database.
 *
 * Clears the caller-supplied buffer p_db (len bytes) and sets it up to collect
 * SDP records, remembering up to num_uuid service-class UUID filters
 * (p_uuid_list) and num_attr attribute-ID filters (p_attr_list); the attribute
 * list is sorted so later searches can walk it in order.  Returns FALSE if a
 * parameter is bad (null buffer, buffer smaller than the DB header, or more
 * filters than the header can hold), TRUE on success.
 *
 * In this build the tSDP_DISCOVERY_DB header is 0x6C bytes and its p_free_mem
 * field sits at 0x68; SDP_MAX_ATTR_FILTERS is 0xC and SDP_MAX_UUID_FILTERS is 3.
 * lbl_80319F40 is the "SDP_InitDiscoveryDb Illegal param: ..." format string. */
BOOLEAN SDP_InitDiscoveryDb(tSDP_DISCOVERY_DB *p_db, UINT32 len, UINT16 num_uuid,
                             tSDP_UUID *p_uuid_list, UINT16 num_attr,
                             UINT16 *p_attr_list) {
    UINT16 xx;

    /* verify the parameters */
    if (p_db == NULL || len < 0x6C || num_attr > 0xC || num_uuid > 3) {
        /* SDP_TRACE_ERROR4("... Illegal param: p_db 0x%x, len %d, num_uuid %d, num_attr %d",
         *                  p_db, len, num_uuid, num_attr) */
        if (sdp_cb_trace_level >= BT_TRACE_LEVEL_ERROR) {
            ((void (*)(u32, void *, void *, u32, u16, u16))fn_8007099C)(
                TRACE_LAYER_SDP | TRACE_TYPE_ERROR, lbl_80319F40, p_db, len, num_uuid, num_attr);
        }
        return FALSE;
    }

    memset(p_db, 0, len);
    p_db->mem_size = len - 0x6C;                              /* space after the header */
    p_db->mem_free = p_db->mem_size;
    p_db->p_first_rec = NULL;
    *(UINT8 **)((UINT8 *)p_db + 0x68) = (UINT8 *)p_db + 0x6C; /* p_free_mem = (UINT8 *)(p_db + 1) */

    for (xx = 0; xx < num_uuid; xx++) {
        p_db->uuid_filters[xx] = *p_uuid_list++;
    }
    p_db->num_uuid_filters = num_uuid;

    for (xx = 0; xx < num_attr; xx++) {
        p_db->attr_filters[xx] = *p_attr_list++;
    }

    sdpu_sort_attr_list(num_attr, p_db);                     /* sort attributes */
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

/* Find the next discovery-db record offering a 16-bit service UUID in its
 * ServiceClassIDList or ServiceID attribute, starting after p_start_rec. */
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

/*******************************************************************************
**
** Function         SDP_FindServiceUUIDInDb
**
** Description      Searches a discovery database for a service record that
**                  contains the given UUID, either in its ServiceClassIDList
**                  attribute sequence or directly as the ServiceID attribute.
**                  The search starts after p_start_rec when provided,
**                  otherwise from the first record in the database.
**
** Returns          Pointer to the matching discovery record, or NULL if none
**                  is found.
**
*******************************************************************************/
tSDP_DISC_REC *SDP_FindServiceUUIDInDb(tSDP_DISCOVERY_DB *p_db, tBT_UUID *p_uuid, tSDP_DISC_REC *p_start_rec)
{
    tSDP_DISC_REC  *p_rec;
    tSDP_DISC_ATTR *p_attr;
    tSDP_DISC_ATTR *p_svc_class_attr;

    for (p_rec = (p_start_rec == NULL) ? p_db->p_first_rec : p_start_rec->p_next_rec;
         p_rec != NULL;
         p_rec = p_rec->p_next_rec)
    {
        for (p_attr = p_rec->p_first_attr; p_attr != NULL; p_attr = p_attr->p_next_attr)
        {
            if ((p_attr->attr_id == ATTR_ID_SERVICE_CLASS_ID_LIST) &&
                (SDP_DISC_ATTR_TYPE(p_attr->attr_len_type) == DATA_ELE_SEQ_DESC_TYPE))
            {
                for (p_svc_class_attr = p_attr->attr_value.v.p_sub_attr;
                     p_svc_class_attr != NULL;
                     p_svc_class_attr = p_svc_class_attr->p_next_attr)
                {
                    if ((SDP_DISC_ATTR_TYPE(p_svc_class_attr->attr_len_type) == UUID_DESC_TYPE) &&
                        sdpu_compare_uuid_with_attr(p_uuid, p_svc_class_attr))
                    {
                        return (p_rec);
                    }
                }
                break;
            }

            if ((p_attr->attr_id == ATTR_ID_SERVICE_ID) &&
                (SDP_DISC_ATTR_TYPE(p_attr->attr_len_type) == UUID_DESC_TYPE) &&
                sdpu_compare_uuid_with_attr(p_uuid, p_attr))
            {
                return (p_rec);
            }
        }
    }

    return (NULL);
}

UINT16 SDP_SetLocalDiRecord(tSDP_DI_RECORD *p_device_info, UINT32 *p_handle) {
    /* Add a Device Identification (DI) service record to the local SDP database.
       Builds the record out of p_device_info's fields; on success *p_handle
       receives the new record handle and SDP_SUCCESS is returned, otherwise the
       record is deleted and an SDP_* error is returned. */
    UINT16 result = SDP_SUCCESS;
    UINT32 handle;
    UINT16 di_uuid = UUID_SERVCLASS_PNP_INFORMATION;
    UINT8 temp_u16[2];
    UINT8 *p_temp;

    *p_handle = 0;
    if (p_device_info == NULL) return SDP_ILLEGAL_PARAMETER;

    /* if this is to be the primary DI record, reuse the old primary's handle */
    if (p_device_info->primary_record == TRUE &&
        sdp_cb_server_db->di_primary_handle != 0) {
        handle = sdp_cb_server_db->di_primary_handle;
    } else {
        handle = SDP_CreateRecord();
        if (handle == 0) return SDP_NO_RESOURCES;
    }

    *p_handle = handle;
    if (!SDP_AddServiceClassIdList(handle, 1, &di_uuid)) result = SDP_DI_REG_FAILED;

    /* specification id (DI spec version) */
    if (result == SDP_SUCCESS) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, 9);
        if (!SDP_AddAttribute(handle, ATTR_ID_SPECIFICATION_ID, UINT_DESC_TYPE, 2, temp_u16)) result = SDP_DI_REG_FAILED;
    }

    /* optional client executable URL - skip when the string is empty */
    if (result == SDP_SUCCESS && p_device_info->client_executable_url[0] != '\0') {
        if (!(((UINT32)(strlen(p_device_info->client_executable_url) + 1) <= 0x50U) &&
              SDP_AddAttribute(handle, ATTR_ID_CLIENT_EXE_URL, URL_DESC_TYPE,
                               (UINT32)(strlen(p_device_info->client_executable_url) + 1),
                               (UINT8 *)p_device_info->client_executable_url))) result = SDP_DI_REG_FAILED;
    }

    /* optional service description - the build packs the three DI strings 0x50 apart */
    if (result == SDP_SUCCESS &&
        (p_device_info->client_executable_url + 0x50)[0] != '\0') {
        if (!(((UINT32)(strlen(p_device_info->client_executable_url + 0x50) + 1) <= 0x50U) &&
              SDP_AddAttribute(handle, ATTR_ID_SERVICE_DESCRIPTION, TEXT_STR_DESC_TYPE,
                               (UINT32)(strlen(p_device_info->client_executable_url + 0x50) + 1),
                               (UINT8 *)(p_device_info->client_executable_url + 0x50)))) result = SDP_DI_REG_FAILED;
    }

    /* optional documentation URL */
    if (result == SDP_SUCCESS &&
        (p_device_info->client_executable_url + 0xA0)[0] != '\0') {
        if (!(((UINT32)(strlen(p_device_info->client_executable_url + 0xA0) + 1) <= 0x50U) &&
              SDP_AddAttribute(handle, ATTR_ID_DOCUMENTATION_URL, URL_DESC_TYPE,
                               (UINT32)(strlen(p_device_info->client_executable_url + 0xA0) + 1),
                               (UINT8 *)(p_device_info->client_executable_url + 0xA0)))) result = SDP_DI_REG_FAILED;
    }

    /* vendor id */
    if (result == SDP_SUCCESS) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->vendor);
        if (!SDP_AddAttribute(handle, ATTR_ID_VENDOR_ID, UINT_DESC_TYPE, 2, temp_u16)) result = SDP_DI_REG_FAILED;
    }
    /* product id */
    if (result == SDP_SUCCESS) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->product);
        if (!SDP_AddAttribute(handle, ATTR_ID_PRODUCT_ID, UINT_DESC_TYPE, 2, temp_u16)) result = SDP_DI_REG_FAILED;
    }
    /* product version */
    if (result == SDP_SUCCESS) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->version);
        if (!SDP_AddAttribute(handle, ATTR_ID_PRODUCT_VERSION, UINT_DESC_TYPE, 2, temp_u16)) result = SDP_DI_REG_FAILED;
    }
    /* primary-record flag (boolean) */
    if (result == SDP_SUCCESS) {
        if (!SDP_AddAttribute(handle, ATTR_ID_PRIMARY_RECORD, BOOLEAN_DESC_TYPE, 1,
                              (UINT8 *)&p_device_info->primary_record)) result = SDP_DI_REG_FAILED;
    }
    /* vendor id source */
    if (result == SDP_SUCCESS) {
        p_temp = temp_u16;
        UINT16_TO_BE_STREAM(p_temp, p_device_info->vendor_id_source);
        if (!SDP_AddAttribute(handle, ATTR_ID_VENDOR_ID_SOURCE, UINT_DESC_TYPE, 2, temp_u16)) result = SDP_DI_REG_FAILED;
    }

    if (result != SDP_SUCCESS) {
        SDP_DeleteRecord(handle);
    } else if (p_device_info->primary_record == TRUE) {
        sdp_cb_server_db->di_primary_handle = handle;
    }
    return result;
}

extern void *fn_80096904(void *, u32, u32);
UINT16 SDP_GetLocalDiRecord(tSDP_DI_GET_RECORD *p_device_info, UINT32 *p_handle) {
    UINT16 result = 9;
    tSDP_RECORD *record;
    void *attr;
    u32 len;
    s32 i;
    u8 *d;
    u8 *s;
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
        {
            void *a = fn_80096904(record, 0xB, 0xB);
            if (a != NULL) { len = *(u32 *)a; len = (len >= 0x50) ? 0x50 : len; s = *(u8 **)((u8 *)a + 4); d = (u8 *)p_device_info->rec.client_executable_url; for (i = 0; i < (s32)len; i++) *d++ = *s++; }
        }
        {
            void *a = fn_80096904(record, 0x101, 0x101);
            if (a != NULL) { len = *(u32 *)a; len = (len >= 0x50) ? 0x50 : len; s = *(u8 **)((u8 *)a + 4); d = (u8 *)p_device_info->rec.service_description; for (i = 0; i < (s32)len; i++) *d++ = *s++; }
        }
        {
            void *a = fn_80096904(record, 0xA, 0xA);
            if (a != NULL) { len = *(u32 *)a; len = (len >= 0x50) ? 0x50 : len; s = *(u8 **)((u8 *)a + 4); d = (u8 *)p_device_info->rec.documentation_url; for (i = 0; i < (s32)len; i++) *d++ = *s++; }
        }
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
    tSDP_ATTRIBUTE *p_attr;
    UINT8 *p_end = lbl_803C4C40 + 0x1224 +
        (*(UINT16 *)(lbl_803C4C40 + 0x1222) * 0x298);
    UINT8 *base;

    if (p_rec == NULL)
        base = lbl_803C4C40 + 0x1224;
    else
        base = (UINT8 *)p_rec + 0x298;

    for (; base < p_end; base += 0x298) {
        for (yy = 0; yy < p_seq->num_uids; yy++) {
            p_attr = (tSDP_ATTRIBUTE *)(base + 0xC);
            for (xx = 0; xx < *(UINT16 *)(base + 8); xx++, p_attr++) {
                if (p_attr->type == UUID_DESC_TYPE) {
                    if (sdpu_compare_uuid_arrays(p_attr->value_ptr, p_attr->len,
                            &p_seq->uuid_entry[yy].value[0], p_seq->uuid_entry[yy].len))
                        break;
                } else if (p_attr->type == DATA_ELE_SEQ_DESC_TYPE) {
                    if (find_uuid_in_seq(p_attr->value_ptr, p_attr->len,
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
    /* Search an SDP data element sequence (recursively, up to depth 3) for a UUID element matching p_uuid. */
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
    u8 *end = &lbl_803C4C40[0] + 0x1224 + (u32)(*(u16 *)&lbl_803C4C40[0x1222]) * 0x298;
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

/* Create an empty service record in the SDP server database (stack/sdp/sdp_db.c).
   Its handle is one past the last record's, or 0x10000 for the first record, and
   the service-record-handle attribute is added to it automatically.
   Returns the new handle, or 0 when all SDP_MAX_RECORDS records are in use. */
u32 SDP_CreateRecord(void) {
    tSDP_DB_BUILD_VIEW *p_db = sdp_cb_server_db_view;
    u32 count;
    u32 handle;
    u8 bytes[4];
    u16 stored_count;
    if (sdp_cb_num_records < SDP_MAX_RECORDS) {
        memset(&p_db->record[sdp_cb_num_records], 0, sizeof(tSDP_RECORD_BUILD_VIEW));
        count = p_db->num_records;
        if (count != 0) {
            u32 prev = count - 1;
            handle = p_db->record[prev].record_handle + 1;
        } else {
            handle = 0x10000;
        }
        bytes[0] = (u8)(handle >> 24);
        p_db->record[count].record_handle = handle;
        stored_count = p_db->num_records;
        bytes[1] = (u8)(handle >> 16);
        *(volatile u16 *)&p_db->num_records = stored_count + 1;
        bytes[2] = (u8)(handle >> 8);
        bytes[3] = (u8)handle;
        SDP_AddAttribute(handle, ATTR_ID_SERVICE_RECORD_HDL, UINT_DESC_TYPE, 4, bytes);
        return p_db->record[p_db->num_records - 1].record_handle;
    }
    return 0;
}

/* Delete a service record from the SDP server database by handle, compacting the record array and fixing attribute value pointers; handle 0 clears the database. */
BOOLEAN SDP_DeleteRecord(UINT32 handle) {
    UINT16 recordIndex, shiftIndex, attrIndex;
    tSDP_RECORD_VIEW *record = (tSDP_RECORD_VIEW *)(lbl_803C4C40 + 0x1224);

    if (handle == 0 || *(UINT16 *)(lbl_803C4C40 + 0x1222) == 0) {
        *(UINT16 *)(lbl_803C4C40 + 0x1222) = 0;
        *(UINT32 *)(lbl_803C4C40 + 0x121C) = 0;
        lbl_803C4C40[0x1220] = 0;
        return TRUE;
    }

    for (recordIndex = 0; recordIndex < *(UINT16 *)(lbl_803C4C40 + 0x1222); recordIndex++, record++) {
        if (record->record_handle == handle) {
            for (shiftIndex = recordIndex; shiftIndex < *(UINT16 *)(lbl_803C4C40 + 0x1222); shiftIndex++, record++) {
                *record = *(record + 1);
                for (attrIndex = 0; attrIndex < record->num_attributes; attrIndex++) {
                    record->attribute[attrIndex].value_ptr -= sizeof(tSDP_RECORD_VIEW);
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
/* Add an attribute to a record of the SDP server database (stack/sdp/sdp_db.c):
   an attribute with this id is replaced, otherwise the new one is inserted where
   the record's sorted attribute list wants it and its big-endian value is copied
   into the record's value pool.  Returns TRUE when the attribute was added. */
BOOLEAN SDP_AddAttribute(UINT32 handle, UINT16 attr_id, UINT8 attr_type,
                          UINT32 attr_len, UINT8 *p_val) {
    UINT16 attr_index;
    tSDP_RECORD_BUILD_VIEW *p_rec;
    tSDP_ATTRIBUTE *p_attr;
    UINT16 record_index;
    UINT16 num_attr;
    UINT16 move_index;

    /* Find the record in the database. */
    p_rec = sdp_cb_record_db;
    for (record_index = 0; record_index < sdp_cb_server_db->num_records;
         record_index++, p_rec++) {
        if (p_rec->record_handle != handle) {
            continue;
        }

        /* See if the attribute already exists, or where it sorts in. */
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
        if (num_attr == SDP_MAX_REC_ATTR) {
            return FALSE;
        }

        if (attr_index == num_attr) {
            p_attr = &p_rec->attribute[num_attr];
        } else {
            /* Attributes stay in id order: make room at attr_index. */
            for (move_index = num_attr; move_index > attr_index; move_index--) {
                p_rec->attribute[move_index] = p_rec->attribute[move_index - 1];
            }
        }

        p_rec->num_attributes++;
        p_attr->id = attr_id;
        p_attr->len = attr_len;
        p_attr->type = attr_type;

        if (p_rec->free_pad_ptr + attr_len >= SDP_BUILD_MAX_PAD_LEN) {
            /* No room left in the pad: truncate the value to what fits. */
            if (sdp_cb_trace_level >= BT_TRACE_LEVEL_WARNING) {
                ((void (*)(u32, void *, u32, u32))fn_8007096C)(
                    TRACE_LAYER_SDP | TRACE_TYPE_WARNING, lbl_80319F90, attr_len,
                    SDP_BUILD_MAX_PAD_LEN - p_rec->free_pad_ptr); /* "SDP_AddAttribute: attr_len:%d too long. truncate to (%d)" */
            }
            attr_len = SDP_BUILD_MAX_PAD_LEN - p_rec->free_pad_ptr;
            p_val[attr_len] = 0;
            p_val[SDP_BUILD_MAX_PAD_LEN + 1 - p_rec->free_pad_ptr] = 0;
        }

        if (attr_len != 0 && p_val != NULL) {
            memcpy(&p_rec->attr_pad[p_rec->free_pad_ptr], p_val, attr_len);
            p_attr->value_ptr = &p_rec->attr_pad[p_rec->free_pad_ptr];
            p_rec->free_pad_ptr += attr_len;
        }

        /* The record holding the BRCM version attribute is the Broadcom one. */
        if (handle == sdp_cb_server_db->di_primary_handle &&
            attr_id == ATTR_ID_EXT_BRCM_VERSION) {
            sdp_cb_server_db->brcm_di_registered = TRUE;
        }
        return TRUE;
    }
    return FALSE;
}

extern char lbl_80319FCC[];
/* Builds a data element sequence of 16-bit UUIDs and adds it as an SDP
 * attribute, stopping early with a trace warning if the buffer would overflow. */
BOOLEAN SDP_AddUuidSequence(UINT32 handle, UINT16 attr_id, UINT16 num_uuids, UINT16 *p_uuids) {
    UINT16 uuidIndex;
    UINT8 buff[0xA0];
    UINT8 *p = buff;
    INT32 max_len = 0x4D;

    for (uuidIndex = 0; uuidIndex < num_uuids; uuidIndex++, p_uuids++) {
        p[0] = 0x19;
        p[1] = *p_uuids >> 8;
        p[2] = *p_uuids;
        p += 3;

        if ((p - buff) > max_len) {
            if (lbl_803C4C40[0x4630] >= 2) {
                fn_8007096C(0xA0001, lbl_80319FCC, uuidIndex, num_uuids);
            }
            break;
        }
    }
    return SDP_AddAttribute(handle, attr_id, 6, (UINT32)(p - buff), buff);
}

/* Add the ServiceClassIDList attribute (0x0001): a Data Element Sequence of 16-bit UUIDs. */
BOOLEAN SDP_AddServiceClassIdList(UINT32 handle, UINT16 num_services, UINT16 *service_uuids) {
    UINT16 index;
    UINT8 uuid_buffer[0xA8];
    UINT8 *cursor = uuid_buffer;

    for (index = 0; index < num_services; index++, service_uuids++) {
        *cursor++ = 0x19;
        *cursor++ = (UINT8)(*service_uuids >> 8);
        *cursor++ = (UINT8)*service_uuids;
    }

    return SDP_AddAttribute(handle, 1, 6, (UINT32)(cursor - uuid_buffer), uuid_buffer);
}

extern char lbl_8031A000[];
/* Delete one attribute from a record of the SDP server database (stack/sdp/sdp_db.c):
   the record's attribute list shifts up over the entry, the values stored after the
   deleted one move down by its length, and the record's value pool gives back the
   bytes it held.  Returns TRUE when the attribute was deleted, FALSE if not found. */
BOOLEAN SDP_DeleteAttribute(UINT32 handle, UINT16 attr_id) {
    UINT16 entry_index, yy;
    UINT16 tail_len;
    UINT32 len;                        /* Number of bytes in the entry */
    UINT8 *pad_ptr;
    tSDP_RECORD *p_rec = (tSDP_RECORD *)sdp_cb_record_db;
    tSDP_ATTRIBUTE *p_attr;

    /* Find the record in the database; a record is 0x298 bytes in this build. */
    for (entry_index = 0; entry_index < sdp_cb_num_records;
         entry_index++, p_rec = (tSDP_RECORD *)((UINT8 *)p_rec + 0x298)) {
        if (p_rec->record_handle == handle) {
            /* Found it. Now, find the attribute */
            p_attr = &p_rec->attribute[0];
            if (sdp_cb_trace_level >= BT_TRACE_LEVEL_API) {
                /* SDP_TRACE_API2("Deleting attr_id 0x%04x for handle 0x%x", attr_id, handle) */
                ((void (*)(u32, void *, u32, u32))fn_8007096C)(
                    TRACE_LAYER_SDP | TRACE_TYPE_API, lbl_8031A000, attr_id, handle);
            }
            for (entry_index = 0; entry_index < p_rec->num_attributes;
                 entry_index++, p_attr++) {
                if (p_attr->id == attr_id) {
                    len = p_attr->len;
                    pad_ptr = p_attr->value_ptr;
                    if (len != 0) {
                        /* Values held after the deleted one move down by its length */
                        for (yy = 0; yy < p_rec->num_attributes; yy++) {
                            if (p_rec->attribute[yy].value_ptr > pad_ptr) {
                                p_rec->attribute[yy].value_ptr -= len;
                            }
                        }
                    }
                    /* Found it. Shift everything up one */
                    p_rec->num_attributes--;
                    for (yy = entry_index; yy < p_rec->num_attributes;
                         yy++, p_attr++) {
                        *p_attr = *(p_attr + 1);
                    }
                    if (len != 0) {
                        /* adjust attribute values: close the gap in the value pool */
                        tail_len =
                            p_rec->free_pad_ptr - (pad_ptr + len - p_rec->attr_pad);
                        for (yy = 0; yy < tail_len; yy++, pad_ptr++) {
                            *pad_ptr = *(pad_ptr + len);
                        }
                        p_rec->free_pad_ptr -= len;
                    }
                    return TRUE;
                }
            }
        }
    }
    /* If here, not found */
    return FALSE;
}

u8 *sdpu_build_uuid_seq(u8 *out, u32 count, u8 *uuid) {
    u8 *start;
    u8 *p;
    u32 i = 0;
    s32 j;
    u16 len;
    u8 c19 = 0x19;
    u8 c1A = 0x1A;
    u8 c1C = 0x1C;
    u8 *q = out;
    p = q + 1;
    start = p;
    *q = 0x35;
    p++;
    for (; i < count; i++) {
        len = *(u16 *)uuid;
        if (len == 2) {
            *p++ = c19;
            *p++ = (u8)(*(u16 *)(uuid + 4) >> 8);
            *p++ = (u8)*(u16 *)(uuid + 4);
        } else if (len == 4) {
            *p++ = c1A;
            *p++ = (u8)(*(u32 *)(uuid + 4) >> 24);
            *p++ = (u8)(*(u32 *)(uuid + 4) >> 16);
            *p++ = (u8)(*(u32 *)(uuid + 4) >> 8);
            *p++ = (u8)*(u32 *)(uuid + 4);
        } else {
            *p++ = c1C;
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
    return p;
}

void sdp_snd_service_search_req(tCONN_CB *p_ccb, u8 num_uuid, u8 *p_uuid_list) {
    u8 *p_param_len;
    u8 *p_start;
    BT_HDR *p_msg;
    u8 *p;
    u8 *p_next;
    u8 *p_db;
    u16 param_len;

    /* Build and send an SDP Service Search Request for the UUIDs in the discovery DB. */
    p_msg = (BT_HDR *)GKI_getpoolbuf(2);
    if (p_msg == NULL) {
        sdp_disconnect(p_ccb, 6);
        return;
    }

    *(u16 *)((u8 *)p_msg + 4) = 9;
    p_start = (u8 *)p_msg + 0x11;
    p_start[0] = 2;
    p_param_len = p_start + 3;
    p_start[1] = *(u16 *)((u8 *)p_ccb + 0x470) >> 8;
    p_start[2] = *(u16 *)((u8 *)p_ccb + 0x470);
    p_db = *(u8 **)((u8 *)p_ccb + 0x410);
    *(u16 *)((u8 *)p_ccb + 0x470) += 1;

    p = sdpu_build_uuid_seq(p_param_len + 2, *(u16 *)(p_db + 0xC), p_db + 0x10);
    p_next = p + 3;
    p[0] = *(u16 *)(lbl_803C4C40 + 0x462E) >> 8;
    p[1] = *(u16 *)(lbl_803C4C40 + 0x462E);
    p[2] = num_uuid;

    if (num_uuid != 0 && p_uuid_list != NULL) {
        memcpy(p_next, p_uuid_list, num_uuid);
        p_next += num_uuid;
    }

    param_len = p_next - p_param_len - 2;
    p_param_len[0] = param_len >> 8;
    p_param_len[1] = param_len;
    *(u8 *)((u8 *)p_ccb + 0x474) = 1;
    *(u16 *)((u8 *)p_msg + 2) = p_next - p_start;

    L2CA_DataWrite(*(u16 *)((u8 *)p_ccb + 0x22), p_msg);
    btu_start_timer((TIMER_LIST_ENT *)((u8 *)p_ccb + 8), 5, 0x1E);
}

extern void process_service_search_attr_rsp(tCONN_CB *, u8 *, u16);
extern UINT8 *save_attr_seq(tCONN_CB *, UINT8 *, UINT8 *);
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

extern void process_service_search_rsp(void *, UINT8 *, UINT16);
extern char lbl_8031A028[];
extern void process_service_search_rsp(void *, UINT8 *, UINT16);
extern char lbl_8031A028[];
/* Handle an SDP discovery server response PDU and dispatch by current discovery state. */
void sdp_disc_server_rsp(tCONN_CB *p_ccb, BT_HDR *p_msg) {
    UINT8 *p;
    UINT8 rsp_pdu;
    UINT32 len;
    BOOLEAN invalid_pdu = TRUE;

    fn_80070F90((UINT8 *)p_ccb + 8);
    p = (UINT8 *)p_msg + p_msg->offset;
    rsp_pdu = p[8];
    len = p_msg->len - 1;
    p_msg->len = len;

    switch (rsp_pdu) {
    case 3:
        if (*(UINT8 *)((UINT8 *)p_ccb + 0x474) == 1) {
            process_service_search_rsp(p_ccb, p + 9, len);
            invalid_pdu = FALSE;
        }
        break;
    case 5:
        if (*(UINT8 *)((UINT8 *)p_ccb + 0x474) == 2) {
            process_service_attr_rsp(p_ccb, p + 9, len);
            invalid_pdu = FALSE;
        }
        break;
    case 7:
        if (*(UINT8 *)((UINT8 *)p_ccb + 0x474) == 3) {
            process_service_search_attr_rsp(p_ccb, p + 9, len);
            invalid_pdu = FALSE;
        }
        break;
    }

    if (invalid_pdu) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_8007096C(0xA0001, lbl_8031A028, rsp_pdu,
                        *(UINT8 *)((UINT8 *)p_ccb + 0x474));
        sdp_disconnect(p_ccb, 0xFFF3);
    }
}

extern char lbl_8031A050[];
void process_service_search_rsp(void *p_ccb, UINT8 *p_reply, UINT16 len) {
    /* Handles an SDP service-search response: collect handles, cap to max, continue on continuation, or proceed to attribute request. */
    tCONN_CB_SEARCH_VIEW *ccb = (tCONN_CB_SEARCH_VIEW *)p_ccb;
    UINT16 xx;
    UINT16 total, cur_handles, orig;
    UINT8 cont_len;

    p_reply += 4;
    BE_STREAM_TO_UINT16(total, p_reply);
    BE_STREAM_TO_UINT16(cur_handles, p_reply);

    orig = ccb->num_handles;
    ccb->num_handles += cur_handles;
    if (ccb->num_handles == 0) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_8007093C(0xA0001, lbl_8031A050);
        sdp_disconnect((tCONN_CB *)p_ccb, 0xFFF0);
        return;
    }

    if (ccb->num_handles > *(UINT16 *)(lbl_803C4C40 + 0x462E))
        ccb->num_handles = *(UINT16 *)(lbl_803C4C40 + 0x462E);

    for (xx = orig; xx < ccb->num_handles; xx++)
        BE_STREAM_TO_UINT32(ccb->handles[xx], p_reply);

    BE_STREAM_TO_UINT8(cont_len, p_reply);
    if (cont_len != 0) {
        if (cont_len > 0x10) {
            sdp_disconnect((tCONN_CB *)p_ccb, 5);
            return;
        }
        sdp_snd_service_search_req((tCONN_CB *)p_ccb, cont_len, p_reply);
    } else {
        ccb->disc_state = 2;
        process_service_attr_rsp((tCONN_CB *)p_ccb, 0, 0);
    }
}

/* Handle a Service Attribute response from the SDP server.
 *
 * One record handle of a discovery is read at a time.  Each response carries
 * part of that record's attribute list followed by a continuation state; the
 * parts are appended to the connection's own rsp_list and, while a continuation
 * is pending, another ServiceAttr request goes out for the rest.  Once the list
 * is complete save_attr_seq() stores the record into the caller's discovery DB
 * and the code below asks for the next handle; when every handle of the search
 * has been read the connection is closed.  Called with p_reply == NULL right
 * after the handle list arrived, to send the very first request.
 */
static void process_service_attr_rsp(tCONN_CB *p_ccb, UINT8 *p_reply, UINT16 len)
{
    tCONN_CB_ATTR_VIEW *ccb = (tCONN_CB_ATTR_VIEW *)p_ccb;
    UINT8 *p_start, *p_param_len;
    UINT16 param_len, list_byte_count;
    BOOLEAN cont_request_needed = FALSE;

    #pragma unused(len)

    /* If p_reply is NULL, we were called after the records handles were read */
    if (p_reply) {
        /* skip the transaction ID and the PDU length, then read the list length */
        p_reply += 4;
        BE_STREAM_TO_UINT16(list_byte_count, p_reply);

        /* copy the response into the scratchpad; first a safety check on the length */
        if (ccb->list_len + list_byte_count > SDP_BUILD_MAX_LIST_BYTE_COUNT) {
            sdp_disconnect(p_ccb, SDP_INVALID_PDU_SIZE);
            return;
        }

        memcpy(&ccb->rsp_list[ccb->list_len], p_reply, list_byte_count);
        ccb->list_len += list_byte_count;
        p_reply += list_byte_count;

        /* a continuation state means the list is not complete yet */
        if (*p_reply) {
            if (*p_reply > SDP_MAX_CONTINUATION_LEN) {
                sdp_disconnect(p_ccb, SDP_INVALID_CONT_STATE);
                return;
            }
            cont_request_needed = TRUE;
        } else {
            /* save the response in the database. Stop on any error */
            if (!save_attr_seq(p_ccb, ccb->rsp_list,
                               (UINT8 *)ccb + ccb->list_len + SDP_CCB_RSP_LIST_OFFSET)) {
                sdp_disconnect(p_ccb, SDP_DB_FULL);
                return;
            }
            ccb->list_len = 0;
            ccb->cur_handle++;
        }
    }

    /* Now, ask for the next handle. Re-use the buffer we just got. */
    if (ccb->cur_handle < ccb->num_handles) {
        BT_HDR *p_msg = (BT_HDR *)GKI_getpoolbuf(2);  /* pool of the SDP layer */
        UINT8 *p;

        if (!p_msg) {
            sdp_disconnect(p_ccb, SDP_NO_RESOURCES);
            return;
        }

        p_msg->offset = 9;                            /* L2CAP_MIN_OFFSET of this build */
        p = p_start = (UINT8 *)(p_msg + 1) + 9;

        /* Get all the attributes of this record from the server */
        UINT8_TO_BE_STREAM(p, SDP_PDU_SERVICE_ATTR_REQ);
        UINT16_TO_BE_STREAM(p, ccb->transaction_id);
        ccb->transaction_id++;

        /* Skip the length, we need to add it at the end */
        p_param_len = p;
        p += 2;

        UINT32_TO_BE_STREAM(p, ccb->handles[ccb->cur_handle]);

        /* Max attribute byte count */
        UINT16_TO_BE_STREAM(p, sdp_cb_max_attr_list_size);

        /* If no attribute filters, build a wildcard attribute sequence */
        if (ccb->p_db->num_attr_filters)
            p = sdpu_build_attrib_seq(p, ccb->p_db->attr_filters,
                                      ccb->p_db->num_attr_filters);
        else
            p = sdpu_build_attrib_seq(p, NULL, 0);

        /* Was this a continuation request ? */
        if (cont_request_needed) {
            memcpy(p, p_reply, *p_reply + 1);
            p += *p_reply + 1;
        } else {
            UINT8_TO_BE_STREAM(p, 0);
        }

        /* Go back and put the parameter length into the buffer */
        param_len = p - p_param_len - 2;
        UINT16_TO_BE_STREAM(p_param_len, param_len);

        /* Set the length of the SDP data in the buffer */
        p_msg->len = p - p_start;

        L2CA_DataWrite(ccb->connection_id, p_msg);

        /* Start inactivity timer */
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_SDP, SDP_INACT_TIMEOUT);
    } else {
        /* every handle of the search has been read: we are done with the server */
        sdp_disconnect(p_ccb, SDP_SUCCESS);
        return;
    }
}

extern char lbl_8031A078[];
/* Handle a Service Search Attribute response from the SDP server.
 *
 * The attribute list of a search comes back in pieces: each response carries
 * part of it followed by a continuation state.  Every piece is appended to the
 * connection's own rsp_list, and while a continuation is pending another
 * ServiceSearchAttr request goes out (the very first request is sent here with
 * p_reply == NULL).  Once the last piece has arrived the list is a
 * data-element sequence of service records, which save_attr_seq() stores one
 * by one into the caller's discovery DB, and the connection is closed.
 */
static void process_service_search_attr_rsp(tCONN_CB *p_ccb, UINT8 *p_reply, UINT16 len)
{
    tCONN_CB_ATTR_VIEW *ccb = (tCONN_CB_ATTR_VIEW *)p_ccb;
    UINT8 *p, *p_start, *p_end, *p_param_len;
    UINT8 type;
    UINT32 seq_len;
    UINT16 param_len, lists_byte_count = 0;
    register UINT8 *list_end;
    BOOLEAN cont_request_needed = FALSE;
    #pragma unused(len)
    if (p_reply) {
        /* skip the transaction ID and the PDU length, then read the list length */
        p_reply += 4;
        BE_STREAM_TO_UINT16(lists_byte_count, p_reply);

        /* still room left in our response buffer? */
        if (ccb->list_len + lists_byte_count > SDP_BUILD_MAX_LIST_BYTE_COUNT) {
            sdp_disconnect(p_ccb, SDP_INVALID_PDU_SIZE);
            return;
        }

        memcpy(&ccb->rsp_list[ccb->list_len], p_reply, lists_byte_count);
        ccb->list_len += lists_byte_count;
        p_reply += lists_byte_count;

        /* a continuation state means the list is not complete yet */
        if (*p_reply) {
            if (*p_reply > SDP_MAX_CONTINUATION_LEN) {
                sdp_disconnect(p_ccb, SDP_INVALID_CONT_STATE);
                return;
            }
            cont_request_needed = TRUE;
        }
    }
    /* first request of the search, or the next one for the continuation */
    if (cont_request_needed || !p_reply) {
        BT_HDR *p_msg = (BT_HDR *)GKI_getpoolbuf(2);  /* pool of the SDP layer */
        UINT8 *p;
        if (!p_msg) {
            sdp_disconnect(p_ccb, SDP_NO_RESOURCES);
            return;
        }
        p_msg->offset = 9;                    /* L2CAP_MIN_OFFSET of this build */
        p = p_start = (UINT8 *)(p_msg + 1) + 9;

        /* Build a service search attribute request packet */
        UINT8_TO_BE_STREAM(p, SDP_PDU_SERVICE_SEARCH_ATTR_REQ);
        UINT16_TO_BE_STREAM(p, ccb->transaction_id);
        ccb->transaction_id++;

        p_param_len = p;                      /* its length is filled in at the end */
        p += 2;

        p = sdpu_build_uuid_seq(p, ccb->p_db->num_uuid_filters,
                                (UINT8 *)ccb->p_db->uuid_filters);
        UINT16_TO_BE_STREAM(p, sdp_cb_max_attr_list_size);

        /* without attribute filters this is a wildcard attribute sequence */
        if (ccb->p_db->num_attr_filters)
            p = sdpu_build_attrib_seq(p, ccb->p_db->attr_filters,
                                      ccb->p_db->num_attr_filters);
        else
            p = sdpu_build_attrib_seq(p, NULL, 0);

        if (p_reply) {                        /* ask for where the last reply left off */
            memcpy(p, p_reply, *p_reply + 1);
            p += *p_reply + 1;
        } else {                              /* no continuation for the first request */
            UINT8_TO_BE_STREAM(p, 0);
        }

        param_len = p - p_param_len - 2;
        UINT16_TO_BE_STREAM(p_param_len, param_len);
        p_msg->len = p - p_start;

        L2CA_DataWrite(ccb->connection_id, p_msg);
        btu_start_timer(&p_ccb->timer_entry, BTU_TTYPE_SDP, SDP_INACT_TIMEOUT);
        return;
    }
    /* the complete response is now in the connection's list: a sequence of records */
    p = ccb->rsp_list;
    type = *p++;
    if ((type >> 3) != DATA_ELE_SEQ_DESC_TYPE) {
        if (sdp_cb_trace_level >= BT_TRACE_LEVEL_WARNING)
            fn_80070954(TRACE_LAYER_SDP | TRACE_TYPE_WARNING, lbl_8031A078, type); /* "SDP - Wrong type: 0x%02x in attr_rsp" */
        return;
    }
    p = sdpu_get_len_from_type(p, type, &seq_len);
    list_end = (UINT8 *)(UINT32)ccb->list_len;
    list_end = (UINT8 *)ccb + (UINT32)list_end;
    p_end = list_end + SDP_CCB_RSP_LIST_OFFSET;
    if (p + seq_len != p_end) {
        sdp_disconnect(p_ccb, SDP_INVALID_CONT_STATE);
        return;
    }
    while (p < p_end) {
        p = (UINT8 *)save_attr_seq(p_ccb, p,
                                   (UINT8 *)ccb + ccb->list_len + SDP_CCB_RSP_LIST_OFFSET);
        if (!p) {
            sdp_disconnect(p_ccb, SDP_DB_FULL);
            return;
        }
    }
    /* we have everything we asked for, so drop the connection */
    sdp_disconnect(p_ccb, SDP_SUCCESS);
}

extern void *add_record(); /* defined below: (tSDP_DISCOVERY_DB *p_db, BD_ADDR p_bda) */
/* This build's tSDP_DISCOVERY_DB was compiled with SDP_MAX_ATTR_FILTERS 12 (the
 * header uses 15), so its p_free_mem field sits at 0x68, not the header's 0x6C. */
#define DB_P_FREE_MEM(db) (*(UINT8 **)((UINT8 *)(db) + 0x68))
extern UINT8 *add_attr(UINT8 *, tSDP_DISCOVERY_DB *, tSDP_DISC_REC *, UINT16, tSDP_DISC_ATTR *, UINT8);
/* Parses an SDP attribute-sequence element from a response and adds each attribute ID/value to the connection's discovery record. */
UINT8 *save_attr_seq(tCONN_CB *p_ccb, UINT8 *p, UINT8 *p_msg_end) {
    register char *logBase = lbl_8031A028;
    UINT32 seqLen;
    UINT32 attrLen;
    UINT16 attrId;
    UINT8 type;
    UINT8 *pSeqEnd;
    UINT8 *pNext;
    tSDP_DISC_REC *pRec;

    type = *p;
    pNext = p + 1;
    if ((type >> 3) != 6) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_80070954(0xA0001, logBase + 0x50, type);
        return NULL;
    }

    p = sdpu_get_len_from_type(pNext, type, &seqLen);
    if (p + seqLen > p_msg_end) {
        if (lbl_803C4C40[0x4630] >= 2)
            ((void (*)(u32, void *, u32))fn_80070954)(0xA0001, logBase + 0x78, seqLen);
        return NULL;
    }

    pRec = add_record(*(void **)((u8 *)p_ccb + 0x410), (u8 *)p_ccb + 2);
    if (pRec == NULL) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_8007093C(0xA0001, logBase + 0x98);
        return NULL;
    }

    pSeqEnd = p + seqLen;
    while (p < pSeqEnd) {
        type = *p++;
        p = sdpu_get_len_from_type(p, type, &attrLen);
        if ((type >> 3) != 1 || attrLen != 2) {
            if (lbl_803C4C40[0x4630] >= 2)
                ((void (*)(u32, void *, u32, u32))fn_8007096C)(
                    0xA0001, logBase + 0xA8, type, attrLen);
            return NULL;
        }

        attrId = ((UINT16)p[0] << 8) + p[1];
        p += 2;
        p = add_attr(p, *(tSDP_DISCOVERY_DB **)((u8 *)p_ccb + 0x410), pRec, attrId, NULL, 0);
        if (p == NULL) {
            if (lbl_803C4C40[0x4630] >= 2)
                fn_8007093C(0xA0001, logBase + 0x98);
            return NULL;
        }
    }
    return p;
}

/* Allocate the next service-discovery record out of the SDP discovery
 * database's own free space, remember which remote device it was read from,
 * and chain it onto the end of the database's record list.  Returns NULL when
 * the database has less than one record's worth of memory left.
 * (stack/sdp/sdp_discovery.c: tSDP_DISC_REC *add_record(p_db, p_bda)) */
void *add_record(tSDP_DISCOVERY_DB *p_db, BD_ADDR p_bda) {
    UINT32 memFree = p_db->mem_free;
    tSDP_DISC_REC *p_rec;
    tSDP_DISC_REC *p_prev;

    /* See if there is enough space in the database */
    if (memFree < sizeof(tSDP_DISC_REC))
        return NULL;

    p_rec = (tSDP_DISC_REC *)DB_P_FREE_MEM(p_db);
    p_db->mem_free = memFree - sizeof(tSDP_DISC_REC);
    DB_P_FREE_MEM(p_db) = (UINT8 *)p_rec + sizeof(tSDP_DISC_REC);

    p_rec->p_first_attr = NULL;
    p_rec->p_next_rec = NULL;

    memcpy(p_rec->remote_bd_addr, p_bda, BD_ADDR_LEN);

    /* Add the record to the end of chain */
    p_prev = p_db->p_first_rec;
    if (p_prev == NULL) {
        p_db->p_first_rec = p_rec;
    } else {
        while (p_prev->p_next_rec != NULL)
            p_prev = p_prev->p_next_rec;
        p_prev->p_next_rec = p_rec;
    }

    return p_rec;
}

UINT8 *add_attr(UINT8 *p, tSDP_DISCOVERY_DB *p_db, tSDP_DISC_REC *p_rec, UINT16 attr_id, tSDP_DISC_ATTR *p_parent_attr, UINT8 nest_level) {
    char *log = lbl_8031A028;
    UINT32 total_len;
    UINT32 size;
    tSDP_DISC_ATTR *p_attr;
    tSDP_DISC_ATTR *p_last;
    UINT32 attr_len;
    UINT16 attr_type;
    UINT32 type_bits;
    UINT16 id;
    UINT8 type;
    UINT8 *p_end;
    UINT8 is_additional_list = nest_level & 0x80;
#define FREE_MEM(db) (*(UINT8 **)((UINT8 *)(db) + 0x68))
#define COPY_ARRAY(p, a, len) {register int ijk; for (ijk = 0; ijk < (int)(len); ijk++) ((UINT8 *) a)[ijk] = *p++;}

    nest_level &= ~0x80;

    type = *p++;
    p = sdpu_get_len_from_type(p, type, &attr_len);
    attr_len &= 0x0FFF;
    attr_type = (type >> 3) & 0x0f;

    if (attr_len > 4)
        size = attr_len - 4 + 12;
    else
        size = 12;
    total_len = (size + 3) & ~3;

    if (p_db->mem_free < total_len)
        return NULL;

    p_attr = (tSDP_DISC_ATTR *)FREE_MEM(p_db);
    p_attr->attr_id = attr_id;
    type_bits = attr_type << 12;
    p_attr->attr_len_type = (UINT16)attr_len | type_bits;
    p_attr->p_next_attr = NULL;

    switch (attr_type) {
    case 1:
        if (is_additional_list != 0 && attr_len == 2) {
            id = (p[0] << 8) + p[1];
            if (id == 4) {
                FREE_MEM(p_db) += 12;
                p_db->mem_free -= 12;
                total_len = 0;
                p += 2;
                p_end = p + attr_len;
                if (nest_level >= 5) {
                    if (lbl_803C4C40[0x4630] >= 1)
                        fn_8007093C(0xA0000, log + 0xD8);
                    return p_end;
                }
                p = add_attr(p, p_db, p_rec, 4, p_attr, nest_level + 1);
                break;
            }
            p = p;
        }
    case 2:
        switch (attr_len) {
        case 1:
            p_attr->attr_value.v.u8 = *p++;
            break;
        case 2:
            BE_STREAM_TO_UINT16(p_attr->attr_value.v.u16, p);
            break;
        case 4:
            BE_STREAM_TO_UINT32(p_attr->attr_value.v.u32, p);
            break;
        default:
            COPY_ARRAY(p, p_attr->attr_value.v.array, attr_len);
            break;
        }
        break;
    case 3: {
        int len = attr_len;
        switch (len) {
        case 2:
            BE_STREAM_TO_UINT16(p_attr->attr_value.v.u16, p);
            break;
        case 4:
            BE_STREAM_TO_UINT32(p_attr->attr_value.v.u32, p);
            if (p_attr->attr_value.v.u32 < 0x10000) {
                attr_len = 2;
                p_attr->attr_len_type = 2 | type_bits;
                p_attr->attr_value.v.u16 = (UINT16)p_attr->attr_value.v.u32;
            }
            break;
        case 16:
            if (sdpu_is_base_uuid(p)) {
                if (p[0] == 0 && p[1] == 0) {
                    p_attr->attr_len_type = (p_attr->attr_len_type & ~0xFFF) | 2;
                    p += 2;
                    BE_STREAM_TO_UINT16(p_attr->attr_value.v.u16, p);
                    p += 12;
                } else {
                    p_attr->attr_len_type = (p_attr->attr_len_type & ~0xFFF) | 4;
                    BE_STREAM_TO_UINT32(p_attr->attr_value.v.u32, p);
                    p += 12;
                }
            } else {
                COPY_ARRAY(p, p_attr->attr_value.v.array, attr_len);
            }
            break;
        default:
            if (lbl_803C4C40[0x4630] >= 2)
                ((void (*)(u32, void *))fn_80070954)(0xA0001, log + 0xF4);
            return p + attr_len;
        }
        break;
    }
    case 6:
    case 7:
        FREE_MEM(p_db) += 12;
        p_db->mem_free -= 12;
        total_len = 0;
        p_end = p + attr_len;
        if (nest_level >= 5) {
            if (lbl_803C4C40[0x4630] >= 1)
                fn_8007093C(0xA0000, log + 0xD8);
            return p_end;
        }
        if (is_additional_list != 0 || attr_id == 0xD)
            nest_level |= 0x80;
        while (p < p_end) {
            p = add_attr(p, p_db, p_rec, 0, p_attr, nest_level + 1);
            if (p == NULL)
                return NULL;
        }
        break;
    case 4:
    case 8:
        COPY_ARRAY(p, p_attr->attr_value.v.array, attr_len);
        break;
    case 5: {
        int len = attr_len;
        switch (len) {
        case 1:
            p_attr->attr_value.v.u8 = *p++;
            break;
        default:
            if (lbl_803C4C40[0x4630] >= 2)
                ((void (*)(u32, void *))fn_80070954)(0xA0001, log + 0x114);
            return p + attr_len;
        }
        break;
    }
    }

    FREE_MEM(p_db) += total_len;
    p_db->mem_free -= total_len;

    if (p_parent_attr == NULL) {
        p_last = p_rec->p_first_attr;
        if (p_last == NULL) {
            p_rec->p_first_attr = p_attr;
        } else {
            while (p_last->p_next_attr != NULL)
                p_last = p_last->p_next_attr;
            p_last->p_next_attr = p_attr;
        }
    } else {
        p_last = p_parent_attr->attr_value.v.p_sub_attr;
        if (p_last == NULL) {
            p_parent_attr->attr_value.v.p_sub_attr = p_attr;
        } else {
            while (p_last->p_next_attr != NULL)
                p_last = p_last->p_next_attr;
            p_last->p_next_attr = p_attr;
        }
    }
    return p;
}

void sdp_init(void) {
    u8 *cb;
    char *log = lbl_8031A188;
    u8 *reg_info;
    register u32 zero = 0;
    memset(lbl_803C4C40, 0, 0x4634);
    cb = lbl_803C4C40;
    reg_info = cb + 0x4604;
    cb[2] = 1;
    *(u16 *)(cb + 4) = 0x100;
    cb[0x20] = 1;
    *(u16 *)(cb + 0x22) = 0xFFFF;
    *(u16 *)(cb + 0x462C) = 0xF0;
    *(u16 *)(cb + 0x462E) = 0x15;
    if (!BTM_SetSecurityLevel(0, lbl_8031A188, 0, 0, 1, 0, 0)) {
        if (cb[0x4630] >= 1)
            fn_8007093C(0xA0000, log + 0x14);
        return;
    }
    if (!BTM_SetSecurityLevel(1, lbl_8031A188, 0, 0, 1, 0, 0)) {
        if (cb[0x4630] >= 1)
            fn_8007093C(0xA0000, log + 0x38);
        return;
    }
    cb[0x4630] = zero;
    *(u32 *)(cb + 0x4604) = (u32)sdp_connect_ind;
    *(u32 *)(cb + 0x4608) = (u32)sdp_connect_cfm;
    *(u32 *)(cb + 0x460C) = zero;
    *(u32 *)(cb + 0x4610) = (u32)sdp_config_ind;
    *(u32 *)(cb + 0x4614) = (u32)sdp_config_cfm;
    *(u32 *)(cb + 0x4618) = (u32)sdp_disconnect_ind;
    *(u32 *)(cb + 0x461C) = (u32)sdp_disconnect_cfm;
    *(u32 *)(cb + 0x4620) = zero;
    *(u32 *)(cb + 0x4624) = (u32)sdp_data_ind;
    *(u32 *)(cb + 0x4628) = zero;
    if (!(u8)L2CA_Register(1, (tL2CAP_APPL_INFO *)reg_info) && cb[0x4630] >= 1)
        fn_8007093C(0xA0000, log + 0x60);
}

/* Handle an inbound SDP L2CAP connection indication: allocate/configure a CCB and accept the channel. */
void sdp_connect_ind(u8 *addr, u16 cid, u16 psm, u8 status) {
    extern void fn_80070954(u32, void *, u16);
    extern u8 lbl_8031A200[];
    void *p_ccb = sdpu_allocate_ccb();
    if (p_ccb != 0) {
        *(u8 *)p_ccb = 2;
        memcpy((u8 *)p_ccb + 2, addr, 6);
        *(u16 *)((u8 *)p_ccb + 0x22) = cid;
        L2CA_ConnectRsp(addr, status, cid, 0, 0);
        L2CA_ConfigReq(cid, (tL2CAP_CFG_INFO *)lbl_803C4C40);
        if (lbl_803C4C40[0x4630] >= 4) {
            fn_80070954(0xA0003, lbl_8031A200, *(u16 *)((u8 *)p_ccb + 0x22));
        }
    }
}

/* Handles L2CAP connect confirmation for SDP: configures the channel on success or reports failure to the SDP callback and releases the connection. */
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
/* Handles an L2CAP configuration indication for SDP: validates the CID, clamps/stores MTU, responds with L2CA_ConfigRsp, and advances the SDP connection state/timers. */
void sdp_config_ind(u16 cid, void *config) {
    tCONN_CB *lcb = l2cu_find_lcb_by_handle_80099E54(cid);
    u16 mtu;
    if (lcb == NULL) {
        if (lbl_803C4C40[0x4630] >= 2) fn_80070954(0xA0001, lbl_8031A2C0, cid);
        return;
    }
    if (((u8 *)config)[2] == 0) {
        *(u16 *)((u8 *)lcb + 0x20) = 0x100;
    } else {
        mtu = *(u16 *)((u8 *)config + 4);
        if (mtu <= 0x100) goto store_mtu;
        *(u16 *)((u8 *)lcb + 0x20) = 0x100;
        goto stored;
store_mtu:
        *(u16 *)((u8 *)lcb + 0x20) = mtu;
stored:
        ;
    }
    ((u8 *)config)[0x20] = 0;
    ((u8 *)config)[2] = 0;
    *(u16 *)config = 0;
    L2CA_ConfigRsp(cid, config);
    if (lbl_803C4C40[0x4630] >= 4) fn_80070954(0xA0003, lbl_8031A2EC, cid);
    ((u8 *)lcb)[1] |= 2;
    if (((u8 *)lcb)[1] & 4) {
        ((u8 *)lcb)[0] = 3;
        if (((u8 *)lcb)[1] & 1) fn_8009757C((u8 *)lcb);
        else btu_start_timer((u8 *)lcb + 8, 5, 0x1E);
    }
}

void sdp_config_cfm(u16 cid, u16 *p_cfg_result) {
    /* L2CAP config-confirm callback for SDP: find connection control block, mark configured or fail/disconnect with status, and start/notify as needed. */
    register char *messages = lbl_8031A188;
    tCONN_CB *ccb;
    u8 flags;
    void (*callback)(u16);

    if (lbl_803C4C40[0x4630] >= 4) {
        fn_8007096C(0xA0003, messages + 0x190, cid, *p_cfg_result);
    }
    ccb = l2cu_find_lcb_by_handle_80099E54(cid);
    if (ccb == 0) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_80070954(0xA0001, messages + 0x138, cid);
    } else if (*p_cfg_result == 0) {
        flags = *((u8 *)ccb + 1) | 4;
        *((u8 *)ccb + 1) = flags;
        if (flags & 2) {
            *((u8 *)ccb) = 3;
            if (*((u8 *)ccb + 1) & 1)
                fn_8009757C((u8 *)ccb);
            else
                btu_start_timer((u8 *)ccb + 8, 5, 0x1E);
        }
    } else {
        if (lbl_803C4C40[0x4630] >= 4)
            fn_80070954(0xA0003, messages + 0x1BC, *((u16 *)((u8 *)ccb + 0x22)));
        if (*((u8 *)ccb) != 1) {
            L2CA_DisconnectReq(*((u16 *)((u8 *)ccb + 0x22)));
            *((u16 *)((u8 *)ccb + 0x472)) = 0xFFF2;
        } else {
            callback = *(void (**)(u16))((u8 *)ccb + 0x414);
            if (callback != 0)
                callback(0xFFF2);
            fn_80099F58(ccb);
        }
    }
}

void sdp_disconnect_ind(u16 handle, u8 reason) {
    extern char lbl_8031A360[];
    extern char lbl_8031A38C[];
    u8 *ccb;
    void (*callback)(u16, s32, u8);
    u8 state;
    s32 stateDelta;
    s32 reverseDelta;
    s32 equalityMask;
    u32 result;

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
        result = 0xFFF1;
        stateDelta = state - 3;
        reverseDelta = 3 - state;
        equalityMask = (s32)~(stateDelta | reverseDelta) >> 31;
        result &= ~equalityMask;
        callback((u16)result, stateDelta, state);
    }

    fn_80099F58(ccb);
}

extern char lbl_8031A3E8[];
extern void (sdp_server_handle_client_req)(tCONN_CB *, BT_HDR *);
/* L2CAP data indication for SDP (sdp_main.c).  p_msg is the received SDP PDU
 * (a GKI buffer, BT_HDR).  Finds the connection the CID belongs to and, while it
 * is connected, passes the PDU to the discovery client when this side originated
 * the connection (we are the SDP client) or to the server otherwise; anything
 * else - unknown CID, or data outside the connected state - is only logged.
 * The buffer is always freed here. */
void sdp_data_ind(u16 l2cap_cid, void *p_msg) {
    tCONN_CB *p_ccb;
    u8 con_state;

    /* Find CCB based on CID */
    p_ccb = sdpu_find_ccb_by_cid(l2cap_cid);
    if (p_ccb != NULL) {
        con_state = p_ccb->con_state;
        if (con_state == SDP_STATE_CONNECTED) {
            if (p_ccb->con_flags & SDP_FLAGS_IS_ORIG) {
                /* we are the client: this is a response from the server */
                sdp_disc_server_rsp(p_ccb, p_msg);
            } else {
                /* we are the server: the parens keep sdpint.h's empty
                   sdp_server_handle_client_req() macro away */
                (sdp_server_handle_client_req)(p_ccb, p_msg);
            }
        } else if (sdp_cb_trace_level >= BT_TRACE_LEVEL_WARNING) {
            fn_8007096C(TRACE_LAYER_SDP | TRACE_TYPE_WARNING, lbl_8031A3B0, con_state, l2cap_cid); /* "SDP - Ignored L2CAP data while in state: %d, CID: 0x%x" */
        }
    } else if (sdp_cb_trace_level >= BT_TRACE_LEVEL_WARNING) {
        fn_80070954(TRACE_LAYER_SDP | TRACE_TYPE_WARNING, lbl_8031A3E8, l2cap_cid); /* "SDP - Rcvd L2CAP data, unknown CID: 0x%x" */
    }

    GKI_freebuf(p_msg);
}

/* Originates an SDP (Service Discovery Protocol) L2CAP connection to the given peer.
 * Allocates an SDP connection control block, emits trace logs based on the SDP
 * trace level, copies the peer BD address, sets connection state/flags, and
 * requests an L2CAP connection on PSM 1. On success stores the returned CID in
 * the CCB; on failure logs and releases the CCB. */
tCONN_CB *sdp_conn_originate(UINT8 *p_bd_addr) {
    char *log = lbl_8031A188;
    tCONN_CB *p_ccb;
    UINT16 cid;

    p_ccb = sdpu_allocate_ccb();
    if (p_ccb == NULL) {
        if (lbl_803C4C40[0x4630] >= 2)
            fn_8007093C(0xA0001, log + 0x28C);
        return NULL;
    }

    if (lbl_803C4C40[0x4630] >= 4)
        fn_8007093C(0xA0003, log + 0x2A8);

    ((UINT8 *)p_ccb)[1] |= 1;
    memcpy((UINT8 *)p_ccb + 2, p_bd_addr, 6);
    ((UINT8 *)p_ccb)[0] = 1;
    cid = L2CA_ConnectReq(1, p_bd_addr);
    if (cid != 0) {
        *(UINT16 *)((UINT8 *)p_ccb + 0x22) = cid;
        return p_ccb;
    }

    if (lbl_803C4C40[0x4630] >= 2)
        fn_8007093C(0xA0001, log + 0x2C0);
    fn_80099F58(p_ccb);
    return NULL;
}

void sdp_disconnect(tCONN_CB *p_ccb, UINT16 reason) {
    extern u8 lbl_803C4C40[];
    extern char lbl_8031A344[];
    if (lbl_803C4C40[0x4630] >= 4) {
        fn_80070954(0xA0003, lbl_8031A344, p_ccb->connection_id);
    }
    if (p_ccb->con_state != 1) {
        L2CA_DisconnectReq(p_ccb->connection_id);
        *(u16 *)((u8 *)p_ccb + 0x472) = reason;
        return;
    }
    if (*(void (**)(UINT16))((u8 *)p_ccb + 0x414) != 0) {
        (*(void (**)(UINT16))((u8 *)p_ccb + 0x414))(reason);
    }
    fn_80099F58(p_ccb);
}

void sdp_disconnect_cfm(u16 cid, u16 result) {
    // Handles L2CAP disconnect confirmation for SDP: logs, invokes completion callback, and frees the connection block.
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

#undef sdp_server_handle_client_req
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

extern void process_service_search(tCONN_CB *, UINT16, UINT16, UINT8 *);
static void process_service_attr_req(tCONN_CB *, UINT16, UINT16, UINT8 *, UINT8 *);
typedef struct { UINT8 pad0[0x26]; UINT8 data[0x450]; volatile UINT16 cont_off; } tCCB_CONT_VIEW;
static void process_service_search_attr_req(tCONN_CB *, UINT16, UINT16, UINT8 *, UINT8 *);
/* Dispatch an incoming SDP server request PDU and route it to the appropriate handler. */
void sdp_server_handle_client_req(tCONN_CB *p_ccb, BT_HDR *p_msg) {
    extern char lbl_8031A4E8[];
    UINT8 *p;
    UINT8 *p_end;
    UINT32 base;
    UINT8 opcode;
    UINT16 trans_num;
    UINT16 param_len;
    base = (UINT32)p_msg + p_msg->offset;
    p = (UINT8 *)(base + 8);
    p_end = p + p_msg->len;
    btu_start_timer((TIMER_LIST_ENT *)((UINT8 *)p_ccb + 8), 5, 0x1E);
    opcode = *p++;
    trans_num = ((UINT16)p[0] << 8) + p[1];
    param_len = ((UINT16)p[2] << 8) + p[3];
    if (p + param_len + 4 > p_end) {
        sdpu_build_n_send_error(p_ccb, trans_num, 4, NULL);
        return;
    }
    switch (opcode) {
    case 2:
        ((void (*)(tCONN_CB *, UINT16, UINT16, UINT8 *, UINT8 *))process_service_search)(p_ccb, trans_num, param_len, p + 4, p_end);
        break;
    case 4:
        process_service_attr_req(p_ccb, trans_num, param_len, p + 4, p_end);
        break;
    case 6:
        process_service_search_attr_req(p_ccb, trans_num, param_len, p + 4, p_end);
        break;
    default:
        sdpu_build_n_send_error(p_ccb, trans_num, 3, NULL);
        if (lbl_803C4C40[0x4630] >= 2)
            fn_80070954(0xA0001, lbl_8031A4E8, opcode);
        break;
    }
}

void process_service_search(tCONN_CB *p_ccb, UINT16 trans_num, UINT16 param_len, UINT8 *p) {
    UINT16 start_offset;
    tSDP_RECORD *p_rec;
    UINT16 num_uids;
    UINT16 total_handles;
    u8 *uid;
    tSDP_UUID_SEQ seq;
    u32 handles[20];
    UINT16 max_handles;
    UINT16 count;
    UINT8 sp17c;
    u8 *p_end;
    u8 *p_param_len;
    u8 *p_cont;
    u32 param_len2;
    BT_HDR *buf;
    s32 total;
    tSDP_CCB_CONT_VIEW *ccb_view;

    sp17c = 0;
    p_rec = NULL;
    ccb_view = (tSDP_CCB_CONT_VIEW *)p_ccb;
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
        if (start_offset != ccb_view->cont_offset) {
            sdpu_build_n_send_error(p_ccb, trans_num, 5, 0);
            return;
        }
        count = total_handles - start_offset;
    } else {
        count = total_handles;
        start_offset = 0;
    }
    max_handles = (UINT16)(((s32)p_ccb->rem_mtu_size - 12) / 4);
    if (count <= max_handles) {
        max_handles = count;
    } else {
        sp17c = 1;
        ccb_view->cont_offset += max_handles;
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
        p_end[1] = (UINT8)(ccb_view->cont_offset >> 8);
        p_end[2] = (UINT8)ccb_view->cont_offset;
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
    UINT32 record_handle;
    UINT16 max_list_len;
    UINT16 i;
    UINT16 list_len;
    UINT16 send_len;
    UINT16 cont_offset;
    UINT8 *p;
    UINT8 *out;
    UINT8 *list_base;
    UINT8 *param_len_ptr;
    tSDP_RECORD *record;
    tSDP_ATTRIBUTE *attr;
    BT_HDR *buf;

    p = arg3;
    record_handle = (((UINT32)p[0] << 24) + ((UINT32)p[1] << 16)) + (p[3] + ((UINT32)p[2] << 8));
    p += 4;
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
    UINT16 len_to_send, req_offset;
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
        if (req_offset != ((tCCB_CONT_VIEW *)p_ccb)->cont_off) {
            sdpu_build_n_send_error(p_ccb, trans_num, 5, NULL);
            return;
        }
    } else {
        p_rsp = (UINT8 *)p_ccb + 0x29;
        ((tCCB_CONT_VIEW *)p_ccb)->cont_off = 0;
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
                        (UINT32)((UINT16)(0x3E8 - (UINT16)(p_rsp - ((tCCB_CONT_VIEW *)p_ccb)->data)) - 6)) {
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
        len_to_send = (UINT16)(p_rsp - ((tCCB_CONT_VIEW *)p_ccb)->data);
        p_ccb->list_len = len_to_send;
        if (len_to_send > 0xFF) {
            UINT16 adjusted = len_to_send - 3;
            ((tCCB_CONT_VIEW *)p_ccb)->data[0] = 0x36;
            ((tCCB_CONT_VIEW *)p_ccb)->data[1] = adjusted >> 8;
            ((tCCB_CONT_VIEW *)p_ccb)->data[2] = adjusted;
        } else {
            ((tCCB_CONT_VIEW *)p_ccb)->cont_off = 1;
            ((tCCB_CONT_VIEW *)p_ccb)->data[1] = 0x35;
            ((tCCB_CONT_VIEW *)p_ccb)->data[2] = len_to_send - 3;
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
    memcpy(p_rsp, ((tCCB_CONT_VIEW *)p_ccb)->data + ((tCCB_CONT_VIEW *)p_ccb)->cont_off, len_to_send);
    p_rsp += len_to_send;
    p_ccb->list_len -= len_to_send;
    ((tCCB_CONT_VIEW *)p_ccb)->cont_off += len_to_send;
    if (p_ccb->list_len != 0) {
        p_rsp[0] = 2;
        p_rsp[1] = ((tCCB_CONT_VIEW *)p_ccb)->cont_off >> 8;
        p_rsp[2] = ((tCCB_CONT_VIEW *)p_ccb)->cont_off;
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

#pragma unroll off
UINT8 *sdpu_build_attrib_seq(UINT8 *p_out, UINT16 *p_attr, UINT16 num_attrs) {
    UINT16 xx;
    UINT16 length;

    /* Data element sequence header. A NULL list means a 4-byte wildcard id. */
    if (p_attr != NULL)
        length = num_attrs * 3;
    else
        length = 5;

    if (length > 0xFF) {
        p_out[0] = (DATA_ELE_SEQ_DESC_TYPE << 3) | SIZE_IN_NEXT_WORD;
        p_out[1] = length >> 8;
        p_out[2] = length;
        p_out += 3;
    } else {
        p_out[0] = (DATA_ELE_SEQ_DESC_TYPE << 3) | SIZE_IN_NEXT_BYTE;
        p_out[1] = length;
        p_out += 2;
    }

    if (p_attr == NULL) {
        /* Wildcard: one 4-byte uint attribute id covering 0x0000..0xFFFF. */
        p_out[0] = (UINT_DESC_TYPE << 3) | SIZE_FOUR_BYTES;
        p_out[1] = 0;
        p_out[2] = 0;
        p_out[3] = 0xFF;
        p_out[4] = 0xFF;
        p_out += 5;
    } else {
        /* One 2-byte uint attribute id per entry in the list. */
        for (xx = 0; xx < num_attrs; xx++) {
            *p_out++ = (UINT_DESC_TYPE << 3) | SIZE_TWO_BYTES;
            *p_out++ = (UINT8)(*p_attr >> 8);
            *p_out++ = (UINT8)*p_attr;
            p_attr++;
        }
    }
    return p_out;
}
#pragma unroll reset
UINT8 *sdpu_build_attrib_entry(UINT8 *p_out, tSDP_ATTRIBUTE *p_attr)
{
    /* Serialize one SDP attribute (id + value data element) into the output buffer and return the next write position. */
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
    /* Build and send an SDP Error Response PDU (optionally with an error text string) over the L2CAP connection. */
    UINT8 *p_rsp, *p_rsp_start, *p_rsp_param_len;
    UINT16 rsp_param_len;
    UINT8 *p_buf;

    if (lbl_803C4C40[0x4630] >= 2)
        fn_8007096C(0xA0001, lbl_8031A56C, error_code, p_ccb->connection_id);

    p_buf = (UINT8 *)GKI_getpoolbuf(2);
    if (p_buf == NULL) {
        if (lbl_803C4C40[0x4630] >= 1)
            fn_8007093C(0xA0000, lbl_8031A5A4);
        return;
    }

    *(UINT16 *)(p_buf + 4) = 9;
    p_rsp = p_rsp_start = p_buf + 0x11;
    UINT8_TO_BE_STREAM(p_rsp, SDP_PDU_ERROR_RESPONSE);
    UINT16_TO_BE_STREAM(p_rsp, trans_num);
    p_rsp_param_len = p_rsp;
    p_rsp += 2;
    UINT16_TO_BE_STREAM(p_rsp, error_code);
    if (p_error_text)
        ARRAY_TO_BE_STREAM(p_rsp, p_error_text, (int)strlen(p_error_text));
    rsp_param_len = p_rsp - p_rsp_param_len - 2;
    UINT16_TO_BE_STREAM(p_rsp_param_len, rsp_param_len);
    *(UINT16 *)(p_buf + 2) = p_rsp - p_rsp_start;
    L2CA_DataWrite(p_ccb->connection_id, (BT_HDR *)p_buf);
}

/*******************************************************************************
**
** Function         sdpu_extract_uid_seq
**
** Description      Extracts a UUID sequence (an SDP data element sequence whose
**                  elements are UUIDs) from the input buffer and puts it into
**                  the given list.  Original stack/sdp/sdp_utils.c.
**
** Returns          Pointer to the next byte in the input buffer after the
**                  sequence, or NULL if it is malformed.
**
*******************************************************************************/
UINT8 *sdpu_extract_uid_seq (UINT8 *p, UINT16 param_len, tSDP_UUID_SEQ *p_seq)
{
    UINT8   *p_seq_end;
    UINT8   descr, type, size;
    UINT32  seq_len, uuid_len;

    /* Assume none found */
    p_seq->num_uids = 0;

    /* A UID sequence is composed of a bunch of UIDs. */

    /* The descriptor byte is a 5-bit type and a 3-bit length code. */
    BE_STREAM_TO_UINT8 (descr, p);
    type = descr >> 3;
    size = descr & 7;

    if (type != DATA_ELE_SEQ_DESC_TYPE)
        return (NULL);

    /* The length code says how many bytes follow the descriptor. */
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

        /* If UUID length is valid, copy it across into the next tSDP_UUID_ENTRY */
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

    /* Only good if the elements filled the sequence exactly. */
    if (p != p_seq_end)
        return (NULL);

    return (p);
}

/*******************************************************************************
**
** Function         sdpu_extract_attr_seq
**
** Description      Extracts an attribute sequence (an SDP data element sequence
**                  whose elements are attribute ID ranges) from the input
**                  buffer and puts it into the given list.  Original
**                  stack/sdp/sdp_utils.c.
**
** Returns          Pointer to the next byte in the input buffer after the
**                  sequence, or NULL if it is malformed.
**
*******************************************************************************/
UINT8 *sdpu_extract_attr_seq(UINT8 *p, UINT16 param_len, tSDP_ATTR_SEQ *p_seq) {
    UINT8 *p_end_list;
    UINT8 descr, type, size;
    UINT32 list_len, attr_len;

    /* Assume none found */
    p_seq->num_attr = 0;

    /* The descriptor byte is a 5-bit type and a 3-bit length code. */
    descr = *p;
    type = descr >> 3;
    size = descr & 7;

    /* An attribute sequence is a data element sequence; p + 1 skips its descriptor. */
    if (type != DATA_ELE_SEQ_DESC_TYPE) return p + 1;
    p++;

    /* The length code says where the sequence length follows the descriptor. */
    switch (size) {
    case SIZE_IN_NEXT_BYTE: BE_STREAM_TO_UINT8(list_len, p); break;
    case SIZE_IN_NEXT_WORD: BE_STREAM_TO_UINT16(list_len, p); break;
    case SIZE_IN_NEXT_LONG: BE_STREAM_TO_UINT32(list_len, p); break;
    default: return p;
    }

    /* Refuse a sequence longer than the parameter it came in. */
    if (list_len > param_len) return p;
    p_end_list = p + list_len;

    /* Loop through, extracting the attribute IDs */
    while (p < p_end_list) {
        BE_STREAM_TO_UINT8(descr, p);
        type = descr >> 3;
        size = descr & 7;

        /* Each attribute ID is an unsigned integer data element. */
        if (type != UINT_DESC_TYPE) return p;

        switch (size) {
        case SIZE_TWO_BYTES: attr_len = 2; break;
        case SIZE_FOUR_BYTES: attr_len = 4; break;
        case SIZE_IN_NEXT_BYTE: BE_STREAM_TO_UINT8(attr_len, p); break;
        case SIZE_IN_NEXT_WORD: BE_STREAM_TO_UINT16(attr_len, p); break;
        case SIZE_IN_NEXT_LONG: BE_STREAM_TO_UINT32(attr_len, p); break;
        default: return NULL;
        }

        /* Attribute length must be 2-bytes or 4-bytes for a paired entry. */
        if (attr_len == 2) {
            BE_STREAM_TO_UINT16(p_seq->attr_entry[p_seq->num_attr].start, p);
            p_seq->attr_entry[p_seq->num_attr].end = p_seq->attr_entry[p_seq->num_attr].start;
        } else if (attr_len == 4) {
            BE_STREAM_TO_UINT16(p_seq->attr_entry[p_seq->num_attr].start, p);
            BE_STREAM_TO_UINT16(p_seq->attr_entry[p_seq->num_attr].end, p);
        } else return NULL;

        p_seq->num_attr++;

        /* We can only do so many */
        if (p_seq->num_attr >= MAX_ATTR_PER_SEQ) return NULL;
    }

    return p;
}

UINT8 *sdpu_get_len_from_type (UINT8 *p, UINT8 type, UINT32 *p_len)
{
    /* Return the data-element length for a type descriptor, advancing p when the length is encoded inline. */
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

/* Checks whether a 128-bit UUID uses the Bluetooth base UUID by comparing bytes 4..15. */
BOOLEAN sdpu_is_base_uuid(UINT8 *p_uuid) {
    extern UINT8 lbl_802EED40[];
    u16 index;

    for (index = 4; index < 16; index++) {
        if (lbl_802EED40[index] != p_uuid[index]) return FALSE;
    }
    return TRUE;
}

/* stack/sdp/sdp_utils.c kept its static const sdp_base_uuid[] in .rodata: the
   Bluetooth SIG base UUID 00000000-0000-1000-8000-00805F9B34FB that 16- and
   32-bit UUIDs are expanded into before they are compared.  The game's symbols
   can't be renamed yet, so alias it here. */
#define sdp_base_uuid lbl_802EED40

/*******************************************************************************
**
** Function         sdpu_compare_uuid_arrays
**
** Description      Compares two Big Endian UUIDs of any length (16-, 32- or
**                  128-bit): same-length ones are compared as they are, a short
**                  one is first expanded into the Bluetooth base UUID, then the
**                  two 128-bit forms are compared.  Original stack/sdp/sdp_utils.c.
**
** NOTE             it is assumed that the arrays are in Big Endian format
**
** Returns          TRUE if matched, else FALSE
**
*******************************************************************************/
BOOLEAN sdpu_compare_uuid_arrays(UINT8 *p_uuid1, UINT32 len1, UINT8 *p_uuid2, UINT16 len2)
{
    UINT8 nu1[MAX_UUID_SIZE]; /* the two UUIDs, each written out as 128 bits */
    UINT8 nu2[MAX_UUID_SIZE];

    /* If lengths match, do a straight compare */
    if (len1 == len2) {
        /* two 16-bit UUIDs */
        if (len1 == 2) return p_uuid1[0] == p_uuid2[0] && p_uuid1[1] == p_uuid2[1];
        /* two 32-bit UUIDs */
        if (len1 == 4) return p_uuid1[0] == p_uuid2[0] && p_uuid1[1] == p_uuid2[1] && p_uuid1[2] == p_uuid2[2] && p_uuid1[3] == p_uuid2[3];
        /* two 128-bit UUIDs (or two of any other length) */
        return memcmp(p_uuid1, p_uuid2, len1) == 0;
    } else if (len1 > len2) {
        /* If the len1 was 4-byte, (so len2 is 2-byte), compare on the fly */
        if (len1 == 4) return p_uuid1[0] == 0 && p_uuid1[1] == 0 && p_uuid1[2] == p_uuid2[0] && p_uuid1[3] == p_uuid2[1];
        else {
            /* Normalize UUIDs to 16-byte form, then compare. Len1 must be 16 */
            memcpy(nu1, p_uuid1, MAX_UUID_SIZE);
            memcpy(nu2, sdp_base_uuid, MAX_UUID_SIZE);
            /* a 32-bit UUID replaces the base's first four bytes, a 16-bit one
               the two bytes just before the 12-byte body of the base */
            if (len2 == 4) memcpy(nu2, p_uuid2, len2); else memcpy(nu2 + 2, p_uuid2, len2);
            return memcmp(nu1, nu2, MAX_UUID_SIZE) == 0;
        }
    } else {
        /* len2 is greater than len1 */
        /* If the len2 was 4-byte, (so len1 is 2-byte), compare on the fly */
        if (len2 == 4) return p_uuid2[0] == 0 && p_uuid2[1] == 0 && p_uuid2[2] == p_uuid1[0] && p_uuid2[3] == p_uuid1[1];
        else {
            /* Normalize UUIDs to 16-byte form, then compare. Len2 must be 16 */
            memcpy(nu2, p_uuid2, MAX_UUID_SIZE);
            memcpy(nu1, sdp_base_uuid, MAX_UUID_SIZE);
            if (len1 == 4) memcpy(nu1, p_uuid1, len1); else memcpy(nu1 + 2, p_uuid1, len1);
            return memcmp(nu1, nu2, MAX_UUID_SIZE) == 0;
        }
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
    int last;
    UINT16 x;
    UINT16 i;

    if (num_attr <= 1) {
        return;
    }
    last = num_attr - 1;
    for (i = 0; i < last;) {
        if (p_db->attr_filters[i] > p_db->attr_filters[i + 1]) {
            x = p_db->attr_filters[i];
            p_db->attr_filters[i] = p_db->attr_filters[i + 1];
            p_db->attr_filters[i + 1] = x;
            i = (UINT16)-1;
        }
        i++;
    }
}

/* ---------------------------------------------------------------------------
 * Revolution SDK USB library (usb.c) internals.
 *
 * lbl_805590A0 is the library's IOS heap handle (its static "hId"):
 * IUSB_OpenLib() creates the heap and every work buffer/control block below
 * is allocated from it.  lbl_8031A620 is the pool holding this library's
 * debug format strings; USB_LOG()/USB_ERR() print "USB: "/"USB ERR: " and
 * then the string found at an offset in that pool.
 * ------------------------------------------------------------------------- */
#define usbHeapId lbl_805590A0
#define usbDebugStrings lbl_8031A620

/* Offsets of the format strings inside the USB debug string pool. */
enum {
    USB_MSG_IOS_FREE_FAILED = 0x108,      /* "iosFree(%d, 0x%x) failed: %d\n" */
    USB_MSG_IOS_ALLOC_FAILED = 0x13C,     /* "iosAllocAligned(%d, %u) failed: %d\n" */
    USB_MSG_INTRBLK_NO_MEM = 0x294,       /* "__IntrBlkMsgInt: Not enough memory\n" */
    USB_MSG_INTRBLK_RESULT = 0x2B8,       /* "intr/blk ioctl returned: %d\n" */
    USB_MSG_INTRBLK_ASYNC_NO_MEM = 0x2D8, /* "IntBlkMsgInt (async): Not enough memory\n" */
    USB_MSG_INTRBLK_CALLBACK = 0x304      /* "intrblkmsg: cb = 0x%x cbArg = 0x%x\n" */
};

/* IOS work buffers are one cache line, allocated 32 bytes aligned. */
#define USB_WORK_SIZE 0x20

/* IPC's IPCIOVector (revolution/IPC/ipcclt.h); this unit cannot include it
   without pulling in IOS_* prototypes that clash with its own. */
typedef struct IPCIOVector {
    void *base; /* 0x0 */
    u32 length; /* 0x4 */
} IPCIOVector;

/* How many entries of USBCommandBlock::clean the async callback frees. */
typedef enum {
    USB_NCLEAN_CLOSEDEVICE = 0,
    USB_NCLEAN_BULKMSG = 3,
    USB_NCLEAN_CTRLMSG = 7,
    USB_NCLEAN_MAX = 8
} USBNClean;

/* One /dev/usb request, allocated from usbHeapId.  For an async request it is
   passed to _intBlkCtrlCb, which frees clean[] and then the block itself. */
typedef struct USBCommandBlock {
    void (*callback)(void);      /* 0x00 completion callback, called (result, arg) */
    void *callbackArg;           /* 0x04 */
    u8 pad08[0x0C - 0x08];
    void *clean[USB_NCLEAN_MAX]; /* 0x0C buffers to free when the request ends */
    s32 nclean;                  /* 0x2C how many of clean[] are in use */
    u8 pad30[0x40 - 0x30];
    union {
        char path[0x40];         /* 0x40 device path (IUSB_OpenDeviceIds) */
        struct {
            void *buffer;        /* 0x40 transfer buffer */
            u16 length;          /* 0x44 transfer length */
        } msg;
    };
} USBCommandBlock;

/* Log a formatted USB debug message when USB debug logging is enabled. */
static void USB_LOG(const char *fmt, ...) {
    va_list list;
    if (lbl_8055DC90) {
        OSReport((const char *)&lbl_805590A4);
        va_start(list, fmt);
        vprintf(fmt, list);
        va_end(list);
    }
}

/* Conditionally prints a "USB ERR: " prefix and the formatted message when the USB debug/error flag is set. */
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
    register char *base = lbl_8031A620;
    s32 result = 0;
    s32 interruptState;

    interruptState = OSDisableInterrupts();
    if (lbl_805590A0 != -1) {
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

// USB interrupt/bulk control completion callback: logs status/count, frees per-entry buffers
// for valid nclean counts (0,3,7), invokes stored completion callback, then frees the block.
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

extern s32 IOS_Open(const char *, s32);
/* Opens an IOS USB device node for the given device name/vendor/product and stores the fd. */
s32 IUSB_OpenDeviceIds(const char *name, u16 vendorId, u16 productId, s32 *fd) {
    register char *base = lbl_8031A620;
    s32 result;
    char *block = 0;
    s32 freeResult;

    if (fd == 0) {
        result = -4;
    } else {
        block = iosAllocAligned(lbl_805590A0, 0x80, 0x20);
        if (block == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x80, block);
        if (block == 0) {
            USB_ERR(base + 0x160);
            result = -0x16;
        } else {
            snprintf(block + 0x40, 0x40, base + 0x184, name, vendorId, productId);
            USB_LOG(base + 0x198, block + 0x40);
            result = IOS_Open(block + 0x40, 0);
            USB_LOG(base + 0x1AC, result);
            *fd = result;
        }
    }
    if (block != 0) {
        freeResult = iosFree(lbl_805590A0, block);
        if (freeResult < 0) USB_ERR(base + 0x108, lbl_805590A0, block, freeResult);
    }
    return result;
}

extern s32 lbl_805590A0;
extern s32 _intBlkCtrlCb(s32, void *);
extern void *iosAllocAligned(s32, u32, u32);
extern s32 iosFree(s32, void *);
extern s32 IOS_CloseAsync(s32, s32 (*)(s32, void *), void *);
/* Asynchronously closes an IOS USB device, allocating a control block to carry the callback and freeing it on failure. */
s32 IUSB_CloseDeviceAsync(s32 device, void (*callback)(void), void *callbackArg) {
    char *logBase = lbl_8031A620;
    void *ctrlBlock;
    s32 result;
    USB_LOG(logBase + 0x1FC);
    ctrlBlock = iosAllocAligned(lbl_805590A0, 0x80, 0x20);
    if (ctrlBlock == 0) USB_ERR(logBase + 0x13C, lbl_805590A0, 0x80, ctrlBlock);
    if (ctrlBlock == 0) {
        USB_ERR(logBase + 0x228);
        result = -0x16;
    } else {
        *(void **)ctrlBlock = (void *)callback;
        *(void **)((u8 *)ctrlBlock + 4) = callbackArg;
        *(s32 *)((u8 *)ctrlBlock + 0x2C) = 0;
        result = IOS_CloseAsync(device, _intBlkCtrlCb, ctrlBlock);
        USB_LOG(logBase + 0x20C, result);
        if (result < 0 && ctrlBlock != 0) {
            s32 freeResult = iosFree(lbl_805590A0, ctrlBlock);
            if (freeResult < 0) USB_ERR(logBase + 0x108, lbl_805590A0, ctrlBlock, freeResult);
        }
    }
    return result;
}

extern s32 IOS_Ioctlv(s32, s32, s32, s32, void *);
extern s32 IOS_IoctlvAsync(s32, s32, s32, s32, void *, void *, void *);
s32 __IntrBlkMsgInt(s32 fd, u32 endpoint, u32 length, void *buffer, s32 ioctl, void (*callback)(void), void *callbackArg, s32 async) {
    register char *base = usbDebugStrings;
    USBCommandBlock *block;
    s32 ret;
    s32 freeResult;
    IPCIOVector *vectors;
    u8 *endpointWork;
    u16 *lengthWork;

    /* One interrupt or bulk USB transfer: the endpoint number and the length go
       to the IOS as the two input vectors, the buffer as the one output vector.
       A synchronous call frees the work buffers itself; an async one lets
       _intBlkCtrlCb free them through the command block's clean[] list. */
    vectors = iosAllocAligned(usbHeapId, 0x60, USB_WORK_SIZE);
    if (vectors == 0) USB_ERR(base + USB_MSG_IOS_ALLOC_FAILED, usbHeapId, 0x60, vectors);
    endpointWork = iosAllocAligned(usbHeapId, USB_WORK_SIZE, USB_WORK_SIZE);
    if (endpointWork == 0) USB_ERR(base + USB_MSG_IOS_ALLOC_FAILED, usbHeapId, USB_WORK_SIZE, endpointWork);
    lengthWork = iosAllocAligned(usbHeapId, USB_WORK_SIZE, USB_WORK_SIZE);
    if (lengthWork == 0) USB_ERR(base + USB_MSG_IOS_ALLOC_FAILED, usbHeapId, USB_WORK_SIZE, lengthWork);

    if (vectors == 0 || endpointWork == 0 || lengthWork == 0) {
        USB_ERR(base + USB_MSG_INTRBLK_NO_MEM);
        ret = -0x16; /* IPC_RESULT_ALLOC_FAILED */
        goto free_all;
    }

    *endpointWork = (u8)endpoint;
    *lengthWork = (u16)length;
    vectors[0].base = endpointWork;
    vectors[0].length = sizeof(u8);
    vectors[1].base = lengthWork;
    vectors[1].length = sizeof(u16);
    vectors[2].base = buffer;
    vectors[2].length = length;
    DCFlushRange(endpointWork, USB_WORK_SIZE);
    DCFlushRange(lengthWork, USB_WORK_SIZE);
    DCFlushRange(vectors, 0x60);

    if (async == 0) {
        ret = IOS_Ioctlv(fd, ioctl, 2, 1, vectors);
        USB_LOG(base + USB_MSG_INTRBLK_RESULT, ret);
        goto free_all;
    }

    block = iosAllocAligned(usbHeapId, sizeof(USBCommandBlock), USB_WORK_SIZE);
    if (block == 0) USB_ERR(base + USB_MSG_IOS_ALLOC_FAILED, usbHeapId, sizeof(USBCommandBlock), block);
    if (block == 0) {
        USB_ERR(base + USB_MSG_INTRBLK_ASYNC_NO_MEM);
        ret = -0x16; /* IPC_RESULT_ALLOC_FAILED */
        goto free_all;
    }

    block->callback = callback;
    block->callbackArg = callbackArg;
    USB_LOG(base + USB_MSG_INTRBLK_CALLBACK, (s32)callback, (s32)callbackArg);
    block->nclean = USB_NCLEAN_BULKMSG;
    block->clean[0] = endpointWork;
    block->clean[1] = lengthWork;
    block->clean[2] = vectors;
    block->msg.buffer = buffer;
    block->msg.length = length;
    ret = IOS_IoctlvAsync(fd, ioctl, 2, 1, vectors, _intBlkCtrlCb, block);
    if (ret >= 0) goto done;
    if (block != 0) {
        freeResult = iosFree(usbHeapId, block);
        if (freeResult < 0) USB_ERR(base + USB_MSG_IOS_FREE_FAILED, usbHeapId, block, freeResult);
    }

free_all:
    if (endpointWork != 0) {
        freeResult = iosFree(usbHeapId, endpointWork);
        if (freeResult < 0) USB_ERR(base + USB_MSG_IOS_FREE_FAILED, usbHeapId, endpointWork, freeResult);
    }
    if (lengthWork != 0) {
        freeResult = iosFree(usbHeapId, lengthWork);
        if (freeResult < 0) USB_ERR(base + USB_MSG_IOS_FREE_FAILED, usbHeapId, lengthWork, freeResult);
    }
    if (vectors != 0) {
        freeResult = iosFree(usbHeapId, vectors);
        if (freeResult < 0) USB_ERR(base + USB_MSG_IOS_FREE_FAILED, usbHeapId, vectors, freeResult);
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

s32 __CtrlMsgInt(s32 fd, s32 reqType, s32 req, s32 value, s32 index, u32 length, void *buffer, void *callback, void *callbackArg, u8 async) {
    register char *base = lbl_8031A620;
    s32 fr;
    char *blk;
    char *a;
    char *b;
    char *c;
    char *d;
    char *e;
    char *f;
    char *msg;

    if ((buffer == 0 && length != 0) || ((u32)buffer & 0x1F)) {
        fd = -4;
        USB_ERR(base + 0x328);
        goto done;
    }
    blk = iosAllocAligned(lbl_805590A0, 0xE0, 0x20);
    if (blk == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0xE0, blk);
    a = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (a == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, a);
    b = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (b == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, b);
    c = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (c == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, c);
    d = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (d == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, d);
    e = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (e == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, e);
    f = iosAllocAligned(lbl_805590A0, 0x20, 0x20);
    if (f == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x20, f);

    if (a == 0 || b == 0 || c == 0 || d == 0 || e == 0 || f == 0 || blk == 0) {
        USB_ERR(base + 0x344);
        fd = -0x16;
        goto free_all;
    }

    *(u8 *)a = reqType;
    *(u8 *)b = req;
    __sthbrx(value, d, 0);
    __sthbrx(index, e, 0);
    __sthbrx(length, f, 0);
    *(u8 *)c = 0;
    *(void **)(blk + 0) = a;
    *(s32 *)(blk + 4) = 1;
    *(void **)(blk + 8) = b;
    *(s32 *)(blk + 0xC) = 1;
    *(void **)(blk + 0x10) = d;
    *(s32 *)(blk + 0x14) = 2;
    *(void **)(blk + 0x18) = e;
    *(s32 *)(blk + 0x1C) = 2;
    *(void **)(blk + 0x20) = f;
    *(s32 *)(blk + 0x24) = 2;
    *(void **)(blk + 0x28) = c;
    *(s32 *)(blk + 0x2C) = 1;
    *(void **)(blk + 0x30) = buffer;
    *(s32 *)(blk + 0x34) = length;
    DCFlushRange(a, 0x20);
    DCFlushRange(b, 0x20);
    DCFlushRange(c, 0x20);
    DCFlushRange(d, 0x20);
    DCFlushRange(e, 0x20);
    DCFlushRange(f, 0x20);
    DCFlushRange(blk, 0xE0);

    if (async == 0) {
        fd = IOS_Ioctlv(fd, 0, 6, 1, blk);
        goto free_all;
    }

    msg = iosAllocAligned(lbl_805590A0, 0x80, 0x20);
    if (msg == 0) USB_ERR(base + 0x13C, lbl_805590A0, 0x80, msg);
    if (msg == 0) {
        USB_ERR(base + 0x364);
        fd = -0x16;
        goto free_all;
    }

    *(s32 *)(msg + 0) = (s32)callback;
    *(s32 *)(msg + 4) = (s32)callbackArg;
    USB_LOG(base + 0x38C, (s32)callback, (s32)callbackArg);
    *(s32 *)(msg + 0x2C) = 7;
    *(void **)(msg + 0xC) = a;
    *(void **)(msg + 0x10) = b;
    *(void **)(msg + 0x14) = d;
    *(void **)(msg + 0x18) = e;
    *(void **)(msg + 0x1C) = f;
    *(void **)(msg + 0x20) = c;
    *(void **)(msg + 0x24) = blk;
    *(s32 *)(msg + 0x40) = (s32)buffer;
    *(u16 *)(msg + 0x44) = length;
    fd = IOS_IoctlvAsync(fd, 0, 6, 1, blk, _intBlkCtrlCb, msg);
    USB_LOG(base + 0x3B0, fd);
    if (fd >= 0) goto done;
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
    if (d != 0) {
        fr = iosFree(lbl_805590A0, d);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, d, fr);
    }
    if (e != 0) {
        fr = iosFree(lbl_805590A0, e);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, e, fr);
    }
    if (f != 0) {
        fr = iosFree(lbl_805590A0, f);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, f, fr);
    }
    if (c != 0) {
        fr = iosFree(lbl_805590A0, c);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, c, fr);
    }
    if (blk != 0) {
        fr = iosFree(lbl_805590A0, blk);
        if (fr < 0) USB_ERR(base + 0x108, lbl_805590A0, blk, fr);
    }
done:
    return fd;
}

#pragma use_lmw_stmw off
s32 IUSB_WriteCtrlMsgAsync(s32 a,s32 b,s32 c,s32 d,s32 e,u32 length,void* data,void* callback,void* context) {
    DCFlushRange(data,length);
    return __CtrlMsgInt(a,b,c,d,e,length,data,callback,context,1);
}
#pragma use_lmw_stmw reset
s32 AXFXReverbHiInit(void* arg0) {
    AutoReverbHi* fx = (AutoReverbHi*)arg0;
    fx->exp.earlyMode = 5;
    fx->exp.preDelayTimeMax = fx->preDelay;
    fx->exp.preDelayTime = fx->preDelay;
    fx->exp.fusedMode = 0;
    fx->exp.fusedTime = fx->time;
    fx->exp.coloration = fx->coloration;
    fx->exp.damping = fx->damping;
    fx->exp.crosstalk = fx->crosstalk;
    fx->exp.earlyGain = 0.0f;
    fx->exp.fusedGain = 1.0f;
    fx->exp.busIn = 0;
    fx->exp.busOut = 0;
    fx->exp.outGain = fx->mix;
    fx->exp.sendGain = 0.0f;
    return AXFXReverbHiExpInit(&fx->exp);
}

s32 fn_8009BF98(void* arg0) {
    AXFXReverbHiExpShutdown(arg0);
    return 1;
}

void fn_8009BFBC(void) {
    AXFXReverbHiExpCallback();
}

extern void __FreeDelayLine(void *);
extern void __BzeroDelayLines(void *);
extern BOOL __AllocDelayLine(AXFX_REVERBHI_EXP_FREE_VIEW *);
extern s32 __InitParams(void *);
BOOL AXFXReverbHiExpInit(void *arg0) {
    BOOL mask;
    AXFX_REVERBHI_EXP_VIEW *fx;
    f32 preMax;
    fx = (AXFX_REVERBHI_EXP_VIEW *)arg0;
    mask = OSDisableInterrupts();
    preMax = fx->preDelayTimeMax;
    fx->active = 1;
    if (preMax < lbl_80560D5C) {
        BOOL m2 = OSDisableInterrupts();
        fx->active |= 1;
        __FreeDelayLine(fx);
        OSRestoreInterrupts(m2);
        OSRestoreInterrupts(mask);
        return FALSE;
    }
    fx->earlyMaxLength = *(u32 *)(lbl_8031ABD8 + 0x5C);
    fx->preDelayMaxLength = (u32)(lbl_80560D58 * preMax);
    fx->combMaxLength[0] = *(u32 *)(lbl_8031AC98 + 0xC0);
    fx->combMaxLength[1] = *(u32 *)(lbl_8031AC98 + 0xC4);
    fx->combMaxLength[2] = *(u32 *)(lbl_8031AC98 + 0xC8);
    fx->allpassMaxLength[0] = *(u32 *)(lbl_8031AC98 + 0xCC);
    fx->allpassMaxLength[1] = *(u32 *)(lbl_8031AC98 + 0xD0);
    fx->lastAllpassMaxLength[0] = *(u32 *)(lbl_8031AC98 + 0xD4);
    fx->lastAllpassMaxLength[1] = *(u32 *)(lbl_8031AC98 + 0xD8);
    fx->lastAllpassMaxLength[2] = *(u32 *)(lbl_8031AC98 + 0xDC);
    if (!__AllocDelayLine((AXFX_REVERBHI_EXP_FREE_VIEW *)fx)) {
        BOOL m2 = OSDisableInterrupts();
        fx->active |= 1;
        __FreeDelayLine(fx);
        OSRestoreInterrupts(m2);
        OSRestoreInterrupts(mask);
        return FALSE;
    }
    __BzeroDelayLines(fx);
    if (!__InitParams(fx)) {
        BOOL m2 = OSDisableInterrupts();
        fx->active |= 1;
        __FreeDelayLine(fx);
        OSRestoreInterrupts(m2);
        OSRestoreInterrupts(mask);
        return FALSE;
    }
    fx->active &= ~1;
    OSRestoreInterrupts(mask);
    return TRUE;
}

void AXFXReverbHiExpShutdown(void* arg0) {
    s32 enabled = OSDisableInterrupts();
    *(u32*)((u8*)arg0 + 0x10C) |= 1;
    __FreeDelayLine(arg0);
    OSRestoreInterrupts(enabled);
}

#pragma use_lmw_stmw off
/* Process one 96-sample block of the exponential reverb: read the input
   channels (mixed with the aux bus when one is set), filter them through the
   early-reflection taps, pre-delay, comb and all-pass sections, then the fused
   stage and crosstalk, and write the wet mix to the output and send buses. */
void AXFXReverbHiExpCallback(AXFX_BUFFERUPDATE_VIEW* update,
                             AXFX_REVERBHI_EXP_VIEW* fx) {
    u32 ch, i;
    u32 samp;
    s32* input[3];
    f32 data;
    f32 output[3];
    f32* earlyLine;
    f32 earlyOut;
    f32* preDelayLine;
    f32 preDelayOut;
    f32 filterOut;
    f32* combLine;
    f32 combOutOne;
    f32* allpass;
    f32 outTmp;
    f32 allpassIn;
    f32 allpassCoef;
    f32 lpfOut;
    f32 lpfCoef1;
    f32 lpfCoef2;
    f32 fusedOut[3];
    f32 fusedGain;
    f32 crosstalkGain;
    f32 crosstalkL;
    f32 crosstalkR;
    f32 crosstalkS;
    s32* inBusData[3];
    s32* outBusData[3];

    if (fx->active != 0) {
        fx->active &= ~2;
        return;
    }

    input[0] = update->left;
    input[1] = update->right;
    input[2] = update->surround;

    if (fx->busIn != NULL) {
        inBusData[0] = fx->busIn->left;
        inBusData[1] = fx->busIn->right;
        inBusData[2] = fx->busIn->surround;
    }

    if (fx->busOut != NULL) {
        outBusData[0] = fx->busOut->left;
        outBusData[1] = fx->busOut->right;
        outBusData[2] = fx->busOut->surround;
    }

    lpfCoef1 = 1.0f - fx->lpfCoef;
    lpfCoef2 = fx->lpfCoef;
    allpassCoef = fx->allpassCoef;
    fusedGain = fx->fusedGain * 0.6f;
    crosstalkGain = fx->crosstalk * 0.5f;

    for (samp = 0; samp < 96; samp++) {
        for (ch = 0; ch < 3; ch++) {
            if (fx->busIn != NULL) {
                data = (f32)(*(input[ch]) + *(inBusData[ch]++));
            } else {
                data = (f32)(*input[ch]);
            }

            earlyLine = fx->earlyLine[ch];
            earlyOut = earlyLine[fx->earlyPos[0]] * fx->earlyCoef[0] +
                       earlyLine[fx->earlyPos[1]] * fx->earlyCoef[1] +
                       earlyLine[fx->earlyPos[2]] * fx->earlyCoef[2];

            if (fx->preDelayLength != 0) {
                preDelayLine = fx->preDelayLine[ch];
                preDelayOut = preDelayLine[fx->preDelayPos];
                preDelayLine[fx->preDelayPos] = data;
            } else {
                preDelayOut = data;
            }

            filterOut = 0.0f;
            for (i = 0; i < 3; i++) {
                combLine = fx->combLine[ch][i];
                combOutOne = combLine[fx->combPos[i]];
                combLine[fx->combPos[i]] =
                    preDelayOut + (combOutOne * fx->combCoef[i]);
                filterOut += combOutOne;
            }

            for (i = 0; i < 2; i++) {
                allpass = fx->allpassLine[ch][i];
                outTmp = allpass[fx->allpassPos[i]];
                allpassIn = filterOut + outTmp * allpassCoef;
                allpass[fx->allpassPos[i]] = allpassIn;
                filterOut = outTmp - allpassIn * allpassCoef;
            }

            lpfOut = lpfCoef1 * filterOut + lpfCoef2 * fx->lastLpfOut[ch];
            fx->lastLpfOut[ch] = lpfOut;
            allpass = fx->lastAllpassLine[ch];
            outTmp = allpass[fx->lastAllpassPos[ch]];
            allpassIn = lpfOut + outTmp * allpassCoef;
            allpass[fx->lastAllpassPos[ch]] = allpassIn;
            fusedOut[ch] = outTmp - allpassIn * allpassCoef;
            if (++fx->lastAllpassPos[ch] >= fx->lastAllpassLength[ch]) {
                fx->lastAllpassPos[ch] = 0;
            }

            fusedOut[ch] *= fusedGain;
            fusedOut[ch] += earlyOut;
        }

        crosstalkL = fusedOut[1] + fusedOut[2];
        crosstalkR = fusedOut[0] + fusedOut[2];
        crosstalkS = fusedOut[0] + fusedOut[1];

        output[0] = fusedOut[0] + crosstalkL * crosstalkGain;
        output[1] = fusedOut[1] + crosstalkR * crosstalkGain;
        output[2] = fusedOut[2] + crosstalkS * crosstalkGain;

        *(input[0]++) = (s32)(output[0] * fx->outGain);
        *(input[1]++) = (s32)(output[1] * fx->outGain);
        *(input[2]++) = (s32)(output[2] * fx->outGain);

        if (fx->busOut != NULL) {
            *(outBusData[0]++) = (s32)(output[0] * fx->sendGain);
            *(outBusData[1]++) = (s32)(output[1] * fx->sendGain);
            *(outBusData[2]++) = (s32)(output[2] * fx->sendGain);
        }

        for (i = 0; i < 3; i++) {
            if (++fx->earlyPos[i] >= fx->earlyLength) {
                fx->earlyPos[i] = 0;
            }
        }

        if (fx->preDelayLength != 0) {
            if (++fx->preDelayPos >= fx->preDelayLength) {
                fx->preDelayPos = 0;
            }
        }

        for (i = 0; i < 3; i++) {
            if (++fx->combPos[i] >= fx->combLength[i]) {
                fx->combPos[i] = 0;
            }
        }

        for (i = 0; i < 2; i++) {
            if (++fx->allpassPos[i] >= fx->allpassLength[i]) {
                fx->allpassPos[i] = 0;
            }
        }
    }
}
#pragma use_lmw_stmw reset

/* Allocates the per-channel early, pre-delay, comb, allpass and last-allpass delay line buffers for a reverb effect; returns FALSE on any allocation failure. */
BOOL __AllocDelayLine(AXFX_REVERBHI_EXP_FREE_VIEW *reverb) {
    extern void *lbl_805590B0;
    u32 channel, i;

    for (channel = 0; channel < 3; channel++) {
        reverb->earlyLine[channel] = ((void *(*)(s32))lbl_805590B0)(reverb->earlyMaxLength * 4);
        if (reverb->earlyLine[channel] == 0)
            return FALSE;

        if (reverb->preDelayMaxLength != 0) {
            reverb->preDelayLine[channel] = ((void *(*)(s32))lbl_805590B0)(reverb->preDelayMaxLength * 4);
            if (reverb->preDelayLine[channel] == 0)
                return FALSE;
        } else {
            reverb->preDelayLine[channel] = 0;
        }

        for (i = 0; i < 3; i++) {
            reverb->combLine[channel][i] = ((void *(*)(s32))lbl_805590B0)(reverb->combMaxLength[i] * 4);
            if (reverb->combLine[channel][i] == 0)
                return FALSE;
        }

        for (i = 0; i < 2; i++) {
            reverb->allpassLine[channel][i] = ((void *(*)(s32))lbl_805590B0)(reverb->allpassMaxLength[i] * 4);
            if (reverb->allpassLine[channel][i] == 0)
                return FALSE;
        }

        reverb->lastAllpassLine[channel] = ((void *(*)(s32))lbl_805590B0)(reverb->lastAllpassMaxLength[channel] * 4);
        if (reverb->lastAllpassLine[channel] == 0)
            return FALSE;
    }
    return TRUE;
}

void __BzeroDelayLines(void *arg0) {
    u8 *entry = (u8 *)arg0;
    u8 *entry2 = (u8 *)arg0;
    u8 *entry3 = (u8 *)arg0;
    u32 i = 0;

    do {
        if (*(void **)entry)
            memset(*(void **)entry, 0, *(u32 *)((u8 *)arg0 + 0x1C) * 4);
        if (*(void **)(entry + 0x2C))
            memset(*(void **)(entry + 0x2C), 0, *(u32 *)((u8 *)arg0 + 0x40) * 4);
        {
            u8 *p = entry2;
            u8 *q = (u8 *)arg0;
            u32 j = 0;
            do {
                if (*(void **)(p + 0x44))
                    memset(*(void **)(p + 0x44), 0, *(u32 *)(q + 0x80) * 4);
                j++;
                q += 4;
                p += 4;
            } while (j < 3);
        }
        {
            u8 *p = entry3;
            u8 *q = (u8 *)arg0;
            u32 j = 0;
            do {
                if (*(void **)(p + 0x98))
                    memset(*(void **)(p + 0x98), 0, *(u32 *)(q + 0xC0) * 4);
                j++;
                q += 4;
                p += 4;
            } while (j < 2);
        }
        if (*(void **)(entry + 0xC8))
            memset(*(void **)(entry + 0xC8), 0, *(u32 *)(entry + 0xEC) * 4);
        i++;
        entry2 += 0xC;
        entry3 += 8;
        entry += 4;
    } while (i < 3);
}

void __FreeDelayLine(void *arg0) {
    /* Free the AXFX reverb delay-line buffers for all channels and clear their pointers. */
    extern void *lbl_805590B4; /* __AXFXFreeFunction */
    AXFX_REVERBHI_EXP_FREE_VIEW *reverb = (AXFX_REVERBHI_EXP_FREE_VIEW *)arg0;
    u32 channel, line;

    for (channel = 0; channel < 3; channel++) {
        if (reverb->earlyLine[channel] != 0) {
            ((void (*)(void *))lbl_805590B4)(reverb->earlyLine[channel]);
            reverb->earlyLine[channel] = 0;
        }
        if (reverb->preDelayLine[channel] != 0) {
            ((void (*)(void *))lbl_805590B4)(reverb->preDelayLine[channel]);
            reverb->preDelayLine[channel] = 0;
        }
        for (line = 0; line < 3; line++) {
            if (reverb->combLine[channel][line] != 0) {
                ((void (*)(void *))lbl_805590B4)(reverb->combLine[channel][line]);
                reverb->combLine[channel][line] = 0;
            }
        }
        for (line = 0; line < 2; line++) {
            if (reverb->allpassLine[channel][line] != 0) {
                ((void (*)(void *))lbl_805590B4)(reverb->allpassLine[channel][line]);
                reverb->allpassLine[channel][line] = 0;
            }
        }
        if (reverb->lastAllpassLine[channel] != 0) {
            ((void (*)(void *))lbl_805590B4)(reverb->lastAllpassLine[channel]);
            reverb->lastAllpassLine[channel] = 0;
        }
    }
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
extern u8 lbl_8031AC98[];
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

extern char lbl_8031AD78[];
extern char lbl_805590B8;
/* Bind a TPL (texture palette) image loaded at the given base address.
 * Validates the TPL magic, relocates the descriptor table offset, then for each
 * descriptor relocates image/palette header pointers and (once) their data offsets. */
void TPLBind(void *tplBase) {
    u8 *base = (u8 *)tplBase;
    u16 i;
    u32 flag = 1;

    if (*(u32 *)base != 0x0020AF30) {
        OSPanic(&lbl_805590B8, 0x19, (const char *)lbl_8031AD78);
    }

    *(u32 *)(base + 8) += (u32)base;
    i = 0;
    while (i < *(u32 *)(base + 4)) {
        u32 index = ((u32)i & 0xFFFF) << 3;

        if (*(u32 *)((u8 *)*(u32 *)(base + 8) + index) != 0) {
            *(u32 *)((u8 *)*(u32 *)(base + 8) + index) = (u32)(base + *(u32 *)((u8 *)*(u32 *)(base + 8) + index));
            if (*(u8 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index) + 0x23) == 0) {
                *(u32 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index) + 8) = (u32)(base + *(u32 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index) + 8));
                *(u8 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index) + 0x23) = flag;
            }
        }

        if (*(u32 *)((u8 *)*(u32 *)(base + 8) + index + 4) != 0) {
            *(u32 *)((u8 *)*(u32 *)(base + 8) + index + 4) = (u32)(base + *(u32 *)((u8 *)*(u32 *)(base + 8) + index + 4));
            if (*(u8 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index + 4) + 2) == 0) {
                *(u32 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index + 4) + 8) = (u32)(base + *(u32 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index + 4) + 8));
                *(u8 *)(*(u32 *)((u8 *)*(u32 *)(base + 8) + index + 4) + 2) = flag;
            }
        }
        i++;
    }
}

void* TPLGet(void* tpl, u32 index) {
    u32 count = *(u32*)((u8*)tpl + 4);
    u8* entries = *(u8**)((u8*)tpl + 8);
    return entries + (index % count) * 8;
}

/* Initialize the EUART interface by writing the required EXI setup bytes; returns 1 on
 * success or if already initialized, 0 if unsupported or EXI writes fail. */
s32 EUARTInit(void) {
    u8 cmdByte;
    s32 savedIrq;
    extern u32 lbl_8055DC98, lbl_8055DC9C, lbl_8055DCA0;

    if (lbl_8055DC98 != 0)
        return 1;

    if (!(OSGetConsoleType() & 0x10000000)) {
        lbl_8055DC9C = 2;
        return 0;
    }

    savedIrq = OSDisableInterrupts();

    cmdByte = 0xF2;
    if (EXIWriteReg(0, 1, 0xB0000000, &cmdByte, 1) == 0) {
        lbl_8055DC9C = 5;
        OSRestoreInterrupts(savedIrq);
        return 0;
    }

    cmdByte = 0xF3;
    if (EXIWriteReg(0, 1, 0xB0000000, &cmdByte, 1) == 0) {
        lbl_8055DC9C = 5;
        OSRestoreInterrupts(savedIrq);
        return 0;
    }

    OSRestoreInterrupts(savedIrq);
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

// The evaluation-board UART driver (revolution/EUART/euart.c in the SDK; this
// unit is C and does not include those headers).  The UART sits on the internal
// EXI port, and its queue is written a byte at a time as 32-bit immediates.
enum {
    EUART_ERROR_OK,     // everything went out
    EUART_ERROR_FATAL,  // __EUARTLastErrorCode: init did not finish
    EUART_ERROR_INVALID,// not enabled / not initialised / EXI busy
    EUART_ERROR_BUSY,   // the EXI peripheral could not be selected
};

enum {
    EUART_EXI_CHAN = 0,  // EXI_CHAN_0
    EUART_EXI_DEV = 1,   // EXI_DEV_INT: the internal port the dev board's UART is on
    EUART_EXI_READ = 0,  // EXI_READ
    EUART_EXI_WRITE = 1, // EXI_WRITE
};

#define EUART_CMD_WRITE 0xB0000100 // write bytes to the UART queue
#define EUART_CMD_QUEUE 0x30000100 // read the UART queue's fill byte
#define EUART_QUEUE_SIZE 32        // bytes the transmit queue holds

// Sends n bytes of msg to the evaluation board's UART, which hangs off the
// internal EXI port and so only exists on dev hardware.  Line feeds in the
// caller's buffer are rewritten as carriage returns first; the text then goes
// out in chunks, each preceded by a read of the queue's fill byte, and a chunk
// is only written while the queue is empty, so this spins until everything has
// gone out.  Returns an EUARTError - and reports EUART_ERROR_OK, having written
// nothing, when another user is holding the EXI lock.
s32 WriteUARTN(char *msg, u32 n) {
    extern u32 lbl_8055DCA4; // euart.c's Enabled: InitializeUART() sets 0xA5FF005A
    extern u32 lbl_8055DC98; // euart.c's __EUARTInitialized
    extern u32 lbl_8055DC9C; // euart.c's __EUARTLastErrorCode
    extern const u32 __EXIFreq; // EXICommon.c: EXI_FREQ_16MHZ
    // revolution/EXI.h's routines; this unit includes no EXI header
    extern s32 EXILock(s32, s32, void *);
    extern s32 EXISelect(s32, s32, u32);
    extern s32 EXIImm(s32, void *, s32, s32, void *);
    extern s32 EXISync(s32);
    extern s32 EXIDeselect(s32);
    extern s32 EXIUnlock(s32);
    char *p;
    u32 freq;
    s32 space;
    s32 err;
    char *it;
    u32 cmd;
    u32 ch;
    u32 status;
    u32 queueCmd;

    p = msg;
    if (lbl_8055DCA4 != 0xA5FF005A) {
        return EUART_ERROR_INVALID; // InitializeUART() was never run
    }
    if (!lbl_8055DC98 && !EUARTInit()) {
        return EUART_ERROR_INVALID; // this console has no EUART
    }
    if (!lbl_8055DC98) {
        lbl_8055DC9C = EUART_ERROR_FATAL;
        return EUART_ERROR_INVALID;
    }
    if (!EXILock(EUART_EXI_CHAN, EUART_EXI_DEV, NULL)) {
        return EUART_ERROR_OK; // the EXI internal port is taken
    }

    // the UART wants carriage returns, and the caller's buffer is edited in place
    for (it = p; it - msg < n; it++) {
        if (*it == '\n') {
            *it = '\r';
        }
    }

    freq = __EXIFreq;
    err = EUART_ERROR_OK;
    cmd = EUART_CMD_WRITE;

    while (n > 0) {
        // how full is the queue?  the fill byte comes back in the top byte of
        // the immediate read; space is what it leaves of the 32-byte queue
        if (!EXISelect(EUART_EXI_CHAN, EUART_EXI_DEV, freq)) {
            space = -1;
        } else {
            queueCmd = EUART_CMD_QUEUE;
            EXIImm(EUART_EXI_CHAN, &queueCmd, sizeof(u32), EUART_EXI_WRITE, NULL);
            EXISync(EUART_EXI_CHAN);
            EXIImm(EUART_EXI_CHAN, &status, sizeof(u32), EUART_EXI_READ, NULL);
            EXISync(EUART_EXI_CHAN);
            EXIDeselect(EUART_EXI_CHAN);
            space = EUART_QUEUE_SIZE - ((status >> 24) % 64);
        }
        if (space < 0) {
            err = EUART_ERROR_BUSY;
            break;
        }
        if (space != EUART_QUEUE_SIZE) {
            continue; // still draining: ask again
        }
        if (!EXISelect(EUART_EXI_CHAN, EUART_EXI_DEV, freq)) {
            err = EUART_ERROR_BUSY;
            break;
        }
        EXIImm(EUART_EXI_CHAN, &cmd, sizeof(u32), EUART_EXI_WRITE, NULL);
        EXISync(EUART_EXI_CHAN);

        // one byte per immediate, in its top byte, until the queue or the text runs out
        for (; space > 0 && n > 0; p++, space--, n--) {
            ch = *p << 24;
            EXIImm(EUART_EXI_CHAN, &ch, sizeof(u32), EUART_EXI_WRITE, NULL);
            EXISync(EUART_EXI_CHAN);
        }

        EXIDeselect(EUART_EXI_CHAN);
    }

    EXIUnlock(EUART_EXI_CHAN);
    return err;
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

void fn_8006CAA8(u32 event, u8 *data) {
    u8 *base = lbl_80392960;
    register u8 *strings = lbl_80313E90;
    u8 *pInfo;
    switch (event) {
    case 0:
        DBPrintf_8006CFA8((char *)strings + 0);
        *(u32 *)(base + 0x6C0) |= 1;
        break;
    case 1:
        DBPrintf_8006CFA8((char *)strings + 0x14);
        break;
    case 2: {
        DBPrintf_8006CFA8((char *)strings + 0x28);
        DBPrintf_8006CFA8((char *)strings + 0x3C, data[7], data[0], data[1], data[2], data[3], data[4], data[5]);
        if (data[6] == 0) {
            pInfo = lbl_803935C8;
            if (memcmp(lbl_803935C8 + 0x40, data, 6) != 0) {
                pInfo = WUDiGetDevInfo(data);
            }
            switch (pInfo[0x59]) {
            case 12:
                base[0xC] = 0x12;
                break;
            case 2:
                base[0xC] = 0x17;
                break;
            }
            pInfo[0x59] = 8;
            pInfo[0x56] = data[7];
            base[0x664]++;
            pInfo = WUDiGetDevInfo(data);
            if (pInfo == 0) {
                pInfo = lbl_803935C8;
            }
            ((u32 *)lbl_80393628)[data[7]] = (u32)(pInfo + 0x40);
            lbl_80394680[data[7]] = 0;
            lbl_803946A0[data[7]] = 0;
            if (pInfo[0x5B] == 3 || pInfo[0x5B] == 1) {
                ((void (*)(u8 *))WUDiMoveTopSmpDevInfoPtr)(pInfo);
            }
            ((void (*)(void *, s32))WUDSetSniffMode)(pInfo + 0x40, 8);
            if (*(void (**)(u32, s32))(base + 0x670) != 0) {
                (*(void (**)(u32, s32))(base + 0x670))(data[7], 1);
            }
        } else {
            DBPrintf_8006CFA8((char *)strings + 0x70, data[6]);
            if (memcmp(data, lbl_803935C8 + 0x40, 6) == 0 && base[0xC] != 0 && lbl_803935C8[0x59] == 2) {
                if (WUDiGetDevInfo(data) != 0 && data[6] == 12) {
                    fn_8006B598(data);
                    base[0x665]--;
                    base[0xC] = 0xFF;
                }
            }
        }
        break;
    }
    case 3: {
        DBPrintf_8006CFA8((char *)strings + 0x80);
        base[0x664]--;
        DBPrintf_8006CFA8((char *)strings + 0x94, data[1], data[0]);
        ((u32 *)lbl_80393628)[data[1]] = 0;
        lbl_80394680[data[1]] = 0;
        lbl_803946A0[data[1]] = 0;
        if (*(void (**)(u32, s32))(base + 0x670) != 0) {
            (*(void (**)(u32, s32))(base + 0x670))(data[1], 0);
        }
        break;
    }
    case 4:
        DBPrintf_8006CFA8((char *)strings + 0xB8);
        break;
    case 5:
        DBPrintf_8006CFA8((char *)strings + 0xCC);
        break;
    case 6:
        DBPrintf_8006CFA8((char *)strings + 0xE0);
        break;
    case 7:
        DBPrintf_8006CFA8((char *)strings + 0xF8);
        break;
    case 8:
        DBPrintf_8006CFA8((char *)strings + 0x110);
        break;
    case 9:
        DBPrintf_8006CFA8((char *)strings + 0x128);
        break;
    case 10:
        DBPrintf_8006CFA8((char *)strings + 0x140);
        break;
    case 11: {
        DBPrintf_8006CFA8((char *)strings + 0x158);
        DBPrintf_8006CFA8((char *)strings + 0x16C, data[6], data[7], data[0], data[1], data[2], data[3], data[4], data[5]);
        pInfo = WUDiGetDevInfo(data);
        pInfo[0x56] = data[7];
        break;
    }
    case 12: {
        DBPrintf_8006CFA8((char *)strings + 0x1AC);
        DBPrintf_8006CFA8((char *)strings + 0x16C, data[6], data[7], data[0], data[1], data[2], data[3], data[4], data[5]);
        break;
    }
    case 13:
        DBPrintf_8006CFA8((char *)strings + 0x1C0);
        break;
    case 15: {
        *(u16 *)(base + 0x6C4) = *(u16 *)(data + 0);
        *(u16 *)(base + 0x6C6) = *(u16 *)(data + 2);
        if (base[0x665] < *(u16 *)(data + 4)) {
            OSReport((char *)strings + 0x1D8);
            base[0x665] = *(u16 *)(data + 4);
        }
        {
            u8 *dev = data;
            s32 i = 0;
            for (i = 0; i < *(u16 *)(data + 4); i++) {
                if (dev[6] < 0x10) {
                    lbl_80394680[dev[6]] = *(u16 *)(dev + 8);
                    lbl_803946A0[dev[6]] = *(u16 *)(dev + 0xA);
                }
                dev += 6;
            }
        }
        break;
    }
    }
}

#pragma push
#pragma opt_propagation off
void fn_8006CF44(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u32 arg8) {
    u32 *ptr = (u32 *)&lbl_80392960;
    void (*func)(void *, void *, void *);
    if (arg8 == 3) {
        func = (void (*)(void *, void *, void *))ptr[0x66C / 4];
        if (func) func(arg0, arg1, arg2);
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
    char *fmt;
    tBTM_BD_ADDR_LINK_KEY_PAIR *pPair;
    u8 *pInfo;
    u8 *pNewInfo;
    u8 *wcb;
    s32 i;

    fmt = (char *)lbl_803130C8; /* WUD's DEBUGPrint() format strings */
    wcb = lbl_80392960;         /* _wcb, the WUD control block */
    switch (((tBTM_STORED_LINK_KEYS_EVT *)msg)->event) {
    case BTM_CB_EVT_RETURN_LINK_KEYS: /* the controller returned its stored link keys */
        DBPrintf_8006CFA8(fmt + 0xb2c); /* "BTM_CB_EVT_RETURN_LINK_KEYS\n" */
        pPair = (tBTM_BD_ADDR_LINK_KEY_PAIR *)((tBTM_RETURN_LINK_KEYS_EVT *)msg + 1);
        i = 0;
        while (i < ((tBTM_RETURN_LINK_KEYS_EVT *)msg)->num_keys) {
            pInfo = (u8 *)WUDiGetDevInfo(pPair->bd_addr);
            DBPrintf_8006CFA8(fmt + 0xb4c, pPair->bd_addr[0], pPair->bd_addr[1], pPair->bd_addr[2],
                              pPair->bd_addr[3], pPair->bd_addr[4], pPair->bd_addr[5]);
            DBPrintf_8006CFA8(fmt + 0xb78, pPair->link_key[0],  pPair->link_key[1],  pPair->link_key[2],
                              pPair->link_key[3],  pPair->link_key[4],  pPair->link_key[5],
                              pPair->link_key[6],  pPair->link_key[7],  pPair->link_key[8],
                              pPair->link_key[9],  pPair->link_key[10], pPair->link_key[11],
                              pPair->link_key[12], pPair->link_key[13], pPair->link_key[14],
                              pPair->link_key[15]);
            if (pInfo == 0) {
                DBPrintf_8006CFA8(fmt + 0xbd4); /* "this device is not stored in NAND\n" */
                pNewInfo = (u8 *)WUDiGetNewDevInfo();
                if (pNewInfo == 0) { /* none free: borrow a simple-mode entry nobody uses */
                    for (i = 0; i < 6; i++) {
                        if (wcb[i * 0x60 + 0x47d] == 0) { /* _wcb.smpDevs[i].status */
                            pInfo = wcb;
                            pInfo += i * 0x60;
                            pNewInfo = pInfo + 0x424; /* &_wcb.smpDevs[i] */
                            break;
                        }
                    }
                }
                if (pNewInfo != 0) {
                    pNewInfo[0x5c] = 1;
                    pNewInfo[0x59] = 1; /* status = 1 */
                    memcpy(pNewInfo + 0x40, pPair->bd_addr, BD_ADDR_LEN);
                    memcpy(pNewInfo + 0x46, pPair->link_key, LINK_KEY_LEN);
                }
            } else {
                memcpy(pInfo + 0x40, pPair->bd_addr, BD_ADDR_LEN);
                memcpy(pInfo + 0x46, pPair->link_key, LINK_KEY_LEN);
                if (pInfo[0x5c] == 2) {
                    pInfo[0x5c] = 3;
                }
                memcpy(wcb + 0x67c, pPair->bd_addr, BD_ADDR_LEN); /* _wcb.pairAddr */
                DBPrintf_8006CFA8(fmt + 0xbf8, wcb[0x67c], wcb[0x67d], wcb[0x67e],
                                  wcb[0x67f], wcb[0x680], wcb[0x681]);
            }
            pPair++;
            i++;
        }
        break;
    case BTM_CB_EVT_READ_STORED_LINK_KEYS:
        DBPrintf_8006CFA8(fmt + 0xc20); /* "BTM_CB_EVT_READ_STORED_LINK_KEYS\n" */
        DBPrintf_8006CFA8(fmt + 0xc44, ((tBTM_READ_STORED_LINK_KEY_COMPLETE *)msg)->status,
                          ((tBTM_READ_STORED_LINK_KEY_COMPLETE *)msg)->max_keys,
                          ((tBTM_READ_STORED_LINK_KEY_COMPLETE *)msg)->read_keys);
        wcb[0xe] = 0; /* _wcb.linkKeyState = WUD_STATE_START */
        break;
    case BTM_CB_EVT_WRITE_STORED_LINK_KEYS:
        DBPrintf_8006CFA8(fmt + 0xc70); /* "BTM_CB_EVT_WRITE_STORED_LINK_KEYS\n" */
        DBPrintf_8006CFA8(fmt + 0xc94, ((tBTM_WRITE_STORED_LINK_KEY_COMPLETE *)msg)->status,
                          ((tBTM_WRITE_STORED_LINK_KEY_COMPLETE *)msg)->num_keys);
        wcb[0xe] = 0;
        break;
    case BTM_CB_EVT_DELETE_STORED_LINK_KEYS:
        DBPrintf_8006CFA8(fmt + 0xcb0); /* "BTM_CB_EVT_DELETE_STORED_LINK_KEYS\n" */
        DBPrintf_8006CFA8(fmt + 0xc94, ((tBTM_DELETE_STORED_LINK_KEY_COMPLETE *)msg)->status,
                          ((tBTM_DELETE_STORED_LINK_KEY_COMPLETE *)msg)->num_keys);
        if (((tBTM_DELETE_STORED_LINK_KEY_COMPLETE *)msg)->num_keys == 0) {
            DBPrintf_8006CFA8(fmt + 0xcd4); /* "WARNING: no entry is deleted\n" */
        }
        wcb[0xe] = 0;
        break;
    default: /* OS_ERROR("Unknown event\n") */
        OSPanic((char *)&lbl_80558FE8, 0xe34, fmt + 0xcf4);
        break;
    }
}

extern u8 lbl_803130C8[];
extern u8 lbl_803935C8[];
/* BTM power-manager callback: logs the transition, locates the device record for the address, updates its power/state byte (0x59) for success/timeout results, and logs the device. */
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

void fn_8006C00C(s32 event, void *arg) {
    register char *strings = (char *)lbl_803130C8;
    u8 *p = (u8 *)arg;
    u16 timeout;
    BOOL interrupts;
    u8 state;
    u8 count;
    u8 field;
    u32 value;

    switch (event) {
    case 0:
        DBPrintf_8006CFA8(strings + 0x96C,
                           p[0], p[1], p[2], p[3], p[4], p[5], p[6],
                           p[7], p[8], (s8)p[9]);
        field = p[9];
        state = lbl_80392960[0x667];
        lbl_8055DC48 = field;
        if (state == 1)
            goto high_timeout;
        if (state == 0) {
            interrupts = OSDisableInterrupts();
            count = lbl_80392960[0x665];
            OSRestoreInterrupts(interrupts);
            if (count < 3) {
                timeout = 0x12C0;
                goto write_timeout;
            }
        }
high_timeout:
        timeout = 0x8000;
write_timeout:
        BTM_WritePageTimeout(timeout);
        break;
    case 1:
        DBPrintf_8006CFA8(strings + 0x9B0);
        break;
    case 2:
        memcpy(lbl_803934C0, p, 6);
        memcpy(lbl_803934C0 + 6, p + 6, 0x40);
        value = *(u32 *)(p + 0x100);
        *(u32 *)(lbl_803934C0 + 0x100) = value;
        lbl_8055DC49++;
        DBPrintf_8006CFA8(strings + 0x9C4,
                           lbl_803934C0[0], lbl_803934C0[1],
                           lbl_803934C0[2], lbl_803934C0[3],
                           lbl_803934C0[4], lbl_803934C0[5],
                           lbl_803934C0 + 6, value);
        break;
    case 3:
        DBPrintf_8006CFA8(strings + 0xA04);
        lbl_80392960[0xC] = 4;
        break;
    case 4:
        DBPrintf_8006CFA8(strings + 0xA18);
        lbl_8055DC49 = 0;
        memset(lbl_803934C0, 0, 0x108);
        lbl_80392960[0xC] = 4;
        break;
    default:
        DBPrintf_8006CFA8(strings + 0xA28);
        break;
    }
}

extern s32 StartSyncDevice(u8 syncType, s8 syncLoopNum, BOOL syncSkipChecks);
#pragma push
#pragma scheduling on
void WUDVendorSpecificCallback(u8 len, u8 *pData) {
    typedef void (*WUDSyncCallback)(s32, s32);
    typedef void (*WUDClearCallback)(s32);
    u8 *state = lbl_80392960;
    u8 *strings = lbl_803130C8;
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

    case 9:
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
        libStatus = (s8)state[0x688];
        OSRestoreInterrupts(enabled);
        if ((u32)libStatus != 3U) break;

        busyEnabled = OSDisableInterrupts();
        if (state[0xC] == 0 && state[0xD] == 0 &&
            state[0xF] == 4 && state[0x10] == 4) {
            OSRestoreInterrupts(busyEnabled);
            busy = 0;
        } else {
            OSRestoreInterrupts(busyEnabled);
            busy = 1;
        }
        if (busy != 0) break;

        enabled = OSDisableInterrupts();
        state[0xD] = 1;
        OSCreateAlarm((OSAlarm *)(state + 0x690));
        OSSetPeriodicAlarm((OSAlarm *)(state + 0x690), __OSGetSystemTime(),
                           OS_MSEC_TO_TICKS(20), (OSAlarmHandler)fn_80069EB4);
        OSRestoreInterrupts(enabled);
        break;

    case 10:
        DBPrintf_8006CFA8((const char *)strings + 0xA88, pData[1]);
        state[0x689] = pData[1];
        break;

    case 16:
        DBPrintf_8006CFA8((const char *)strings + 0xAAC, pData[1]);
        OSPanic(&lbl_80558FE8, 0xD9C,
                (const char *)strings + 0xAD4);
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