#include <types.h>

typedef void (*tBTM_RMT_NAME_CALLBACK)(void*);

/* Review carve for REXE01 hcisu_h2_open@0x8006F1B8 (auto_03_8005D0DC_text).
 * Broadcom HCI-H2 USB stack open; structs are recovered from REXE01 field
 * offsets (tUUSB: u16 @+4/+6/+8, u8 @+0xB; hcisu_h2_cb: u8 @+0x1E/+0x1F).
 * Review-only; not configured.
 */

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

extern hcisu_h2_cb_t hcisu_h2_cb;
extern void UUSB_Register(tUUSB* uusb);
extern void UUSB_Open(tUUSB* uusb, void* cback);
extern void fn_8006EC24(void* data, u32 len, u32 param);

BOOL hcisu_h2_open(tHCI_CFG* p_cfg) {
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
/* bte_hcisu_task@0x800707BC (auto_03_8005D0DC_text): */
typedef struct hcisu_if_t {
    void (*init)(u32, u32, u32); // at 0x0
    void (*open)(void*);         // at 0x4
} hcisu_if_t;

extern hcisu_if_t* p_hcisu_if;
extern void* p_hcisu_cfg;

void bte_hcisu_task(void) {
    if (p_hcisu_if != NULL) {
        if (p_hcisu_if->init != NULL) {
            (*p_hcisu_if->init)(2, 1, 0x800);
        }

        if (p_hcisu_if->open != NULL) {
            (*p_hcisu_if->open)(p_hcisu_cfg);
        }
    }
}

/* bta_dm_send_hci_reset@0x80073A20 (auto_03_8005D0DC_text): */
typedef struct bta_sys_cb_t {
    u8 pad[0x7E];
    u8 events_disabled; // at 0x7E
} bta_sys_cb_t;

extern bta_sys_cb_t bta_sys_cb;
extern void* GKI_getpoolbuf(u16 pool);
extern void fn_80085384(void* p_buf, u8 scan_enable);
extern void fn_80073A1C(void);
extern void BTM_SendHciReset(void (*callback)(void));

void bta_dm_send_hci_reset(void) {
    void* p_buf;

    bta_sys_cb.events_disabled = TRUE;

    if ((p_buf = GKI_getpoolbuf(2)) != NULL) {
        fn_80085384(p_buf, 0);
    }

    BTM_SendHciReset(fn_80073A1C);
}

/* ---- BTA_DmSetVisibility@0x80073BCC ---- */
extern void* GKI_getbuf(u32 size);
extern void fn_80071450(void* msg); // bta_sys_sendmsg

void BTA_DmSetVisibility(u8 disc_mode, u8 conn_mode) {
    u8* p_msg;

    if ((p_msg = GKI_getbuf(0x110)) != NULL) {
        *(u16*)&p_msg[0] = 0x103;      // hdr.event
        p_msg[0x8] = disc_mode;
        p_msg[0x9] = conn_mode;

        fn_80071450(p_msg);
    }
}

/* ---- BTA_HhGetAclQueueInfo@0x8007651C ---- */
void BTA_HhGetAclQueueInfo(void) {
    u8* p_buf;

    if ((p_buf = GKI_getbuf(8)) != NULL) {
        memset(p_buf, 0, 8);

        *(u16*)&p_buf[0] = 0x170E;     // event

        fn_80071450(p_buf);
    }
}

/* ---- bta_hh_tod_spt@0x80076D3C ---- */
typedef struct devt_list_t {
    u8 tod;    // at 0x0
    u8 app_id; // at 0x1
} devt_list_t;

typedef struct hh_cfg_t {
    u8 max_devt_spt;  // at 0x0
    u8 pad[3];
    devt_list_t* p_devt_list; // at 0x4
} hh_cfg_t;

typedef struct hh_dev_cb_t {
    u8 pad[0x15];
    u8 app_id; // at 0x15
} hh_dev_cb_t;

extern hh_cfg_t* p_bta_hh_cfg;

BOOL bta_hh_tod_spt(hh_dev_cb_t* p_cb, u8 sub_class) {
    u8 cod = sub_class >> 2;
    u8 xx;

    for (xx = 0; xx < p_bta_hh_cfg->max_devt_spt; ++xx) {
        if (cod == p_bta_hh_cfg->p_devt_list[xx].tod) {
            p_cb->app_id = p_bta_hh_cfg->p_devt_list[xx].app_id;
            return TRUE;
        }
    }

    return FALSE;
}

/* ---- BTM_GetNumAclLinks@0x80077D7C ---- */
extern u8 lbl_803C0F78[]; // btm_cb

BOOL BTM_GetNumAclLinks(void) {
    u8* p = lbl_803C0F78;
    u16 count = 0;

    if (p[0x14D] != 0) {
        count = 1;
    }
    if (p[0x269] != 0) {
        count = (u16)(count + 1);
    }
    if (p[0x385] != 0) {
        count = (u16)(count + 1);
    }
    if (p[0x4A1] != 0) {
        count = (u16)(count + 1);
    }

    return count;
}

typedef u16 tBTM_STATUS_BRIDGE;

/* ---- BTM_SetDeviceClass@0x8007A314 ---- */
#define DEV_CLASS_LEN 3

extern void fn_80085524(void* p_buf, void* dev_class); // btsnd_hcic_write_dev_class

tBTM_STATUS_BRIDGE BTM_SetDeviceClass(u8* dev_class) {
    void* p_buf;

    memcpy(&lbl_803C0F78[0x648], dev_class, DEV_CLASS_LEN);

    if (lbl_803C0F78[0x64E] <= 1) {
        return 0xC; // BTM_DEV_RESET
    }

    if ((p_buf = GKI_getpoolbuf(2)) != NULL) {
        fn_80085524(p_buf, dev_class);
        return 0; // BTM_SUCCESS
    }

    return 3; // BTM_NO_RESOURCES
}

/* ---- btm_discovery_db_init@0x8007AC08 ---- */
extern void SDP_InitDiscoveryDb(void* p_db, u32 len, u32 num_uuid, void* p_db2,
                                u32 param1, u32 param2);

void btm_discovery_db_init(void) {
    *(u32*)&lbl_803C0F78[0x1678] = (u32)&lbl_803C0F78[0x6D4];

    memset(&lbl_803C0F78[0x658], 0, 0x1020);

    *(u16*)&lbl_803C0F78[0x670] = 1;     // disc_active
    *(u16*)&lbl_803C0F78[0x674] = 2;     // num_bd_entries
    *(u16*)&lbl_803C0F78[0x678] = 0x1002;

    SDP_InitDiscoveryDb(*(void**)&lbl_803C0F78[0x1678], 0xFA0, 1,
                        &lbl_803C0F78[0x674], 0, 0);
}

/* ---- BTM_CancelRemoteDeviceName@0x8007B6F4 ---- */
extern u8 lbl_80316464[];
extern u8 lbl_80316870[];
extern u8 lbl_80317008[];
extern void fn_8007093C(u32 code, void* msg); // BTM_TRACE
extern BOOL btsnd_hcic_link_key_neg_reply_800843D8(void* bda);

tBTM_STATUS_BRIDGE BTM_CancelRemoteDeviceName(void) {
    u8* btm_cb = lbl_803C0F78;

    if (btm_cb[0x27C0] >= 3) {
        fn_8007093C(0xD0002, (void*)&lbl_80316464);
    }

    if (btm_cb[0x16AE] & 1) {
        if ((u8)btsnd_hcic_link_key_neg_reply_800843D8(&btm_cb[0x16A8]) != 0) {
            return 1; // BTM_CMD_STARTED
        }
        return 3; // BTM_NO_RESOURCES
    }

    return 6; // BTM_WRONG_MODE
}

/* ---- btm_is_sco_active@0x8007E1A4 ---- */
typedef struct tSCO_CONN {
    u16 state;      // at 0x0
    u16 hci_handle; // at 0x2
    u8 pad[0x30];   // entry stride 0x34
} tSCO_CONN;

BOOL btm_is_sco_active(u16 handle) {
    tSCO_CONN* p = (tSCO_CONN*)&lbl_803C0F78[0x185C];
    u16 xx;

    for (xx = 0; xx < 3; xx++, p++) {
        if (handle == p->hci_handle && p->state == 4) {
            return TRUE;
        }
    }

    return FALSE;
}

/* ---- btm_num_sco_links_active@0x8007E214 ---- */
u8 btm_num_sco_links_active(void) {
    tSCO_CONN* p = (tSCO_CONN*)&lbl_803C0F78[0x185C];
    u8 num_scos = 0;
    u16 xx;

    for (xx = 0; xx < 3; xx++, p++) {
        switch (p->state) {
        case 2: // SCO_ST_W4_CONN_RSP
        case 3: // SCO_ST_CONNECTING
        case 4: // SCO_ST_CONNECTED
        case 5: // SCO_ST_DISCONNECTING
        case 6: // SCO_ST_PEND_UNPARK
            ++num_scos;
            break;
        }
    }

    return num_scos;
}

typedef struct btm_sec_view_t {
    u8 pad[0x192C];
    tBTM_RMT_NAME_CALLBACK p_rmt_name_callback[2]; // at 0x192C
} btm_sec_view_t;

extern btm_sec_view_t btm_sec_cb;

/* ---- BTM_SecRegister@0x8007E2FC ---- */
#define BTM_SEC_MAX_RMT_NAME_CALLBACKS 2

typedef struct tBTM_APPL_INFO {
    u32 at_0x00[6]; // 0x18 bytes copied to btm_cb+0x190C
} tBTM_APPL_INFO;

tBTM_STATUS_BRIDGE BTM_SecRegister(tBTM_APPL_INFO* p_cb_info) {
    u8* btm_cb = lbl_803C0F78;

    *(u32*)&btm_cb[0x190C] = p_cb_info->at_0x00[0];
    *(u32*)&btm_cb[0x1910] = p_cb_info->at_0x00[1];
    *(u32*)&btm_cb[0x1914] = p_cb_info->at_0x00[2];
    *(u32*)&btm_cb[0x1918] = p_cb_info->at_0x00[3];
    *(u32*)&btm_cb[0x191C] = p_cb_info->at_0x00[4];
    *(u32*)&btm_cb[0x1920] = p_cb_info->at_0x00[5];

    if (btm_cb[0x27C0] >= 4) {
        fn_8007093C(0xD0003, (void*)&lbl_80316870);
    }

    return TRUE;
}

/* ---- BTM_SecAddRmtNameNotifyCallback@0x8007E374 ---- */
BOOL BTM_SecAddRmtNameNotifyCallback(tBTM_RMT_NAME_CALLBACK p_callback) {
    int i;

    for (i = 0; i < BTM_SEC_MAX_RMT_NAME_CALLBACKS; ++i) {
        if (btm_sec_cb.p_rmt_name_callback[i] == NULL) {
            btm_sec_cb.p_rmt_name_callback[i] = p_callback;
            return TRUE;
        }
    }

    return FALSE;
}

/* ---- BTM_SecDeleteRmtNameNotifyCallback@0x8007E3C4 ---- */
BOOL BTM_SecDeleteRmtNameNotifyCallback(tBTM_RMT_NAME_CALLBACK p_callback) {
    int i;

    for (i = 0; i < BTM_SEC_MAX_RMT_NAME_CALLBACKS; ++i) {
        if (btm_sec_cb.p_rmt_name_callback[i] == p_callback) {
            btm_sec_cb.p_rmt_name_callback[i] = NULL;
            return TRUE;
        }
    }

    return FALSE;
}

/* ---- btm_sec_pin_code_request_timeout@0x80080890 ---- */
extern void fn_800833E8(void);
extern void fn_800833F4(void);
extern BOOL btsnd_hcic_link_key_neg_reply_800840C8(void* bda);

void btm_sec_pin_code_request_timeout(void) {
    u8* btm_cb = lbl_803C0F78;

    if (btm_cb[0x27C0] >= 4) {
        fn_8007093C(0xD0003, (void*)&lbl_80317008);
    }

    *(u32*)&btm_cb[0x194C] = 0;

    memset(&btm_cb[0x1954], 0xFF, 6);

    btsnd_hcic_link_key_neg_reply_800840C8(&btm_cb[0x27B4]);
}

/* ---- GAP_Init@0x80082674 ---- */
extern u8 lbl_803C3740[]; // gap_cb
extern void fn_800826D4(void); // gap_conn_init

void GAP_Init(void) {
    memset(&lbl_803C3740[0], 0, 0x3AC);

    *(void**)&lbl_803C3740[0x20] = fn_800833E8;
    *(void**)&lbl_803C3740[0x24] = fn_800833F4;
    lbl_803C3740[0x28] = 5;

    fn_800826D4();
}

/* ---- gap_convert_btm_status@0x800837CC ---- */
u16 gap_convert_btm_status(u16 status) {
    switch (status) {
    case 0:
        return 0x000;
    case 1:
        return 0x10B;
    case 2:
        return 0x103;
    case 3:
        return 0x109;
    case 4:
        return 0x10C;
    case 5:
        return 0x10D;
    case 6:
        return 0x115;
    case 7:
    case 8:
    default:
        return 0x114;
    }
}

/* ---- btsnd_hcic_inq_cancel@0x800838D4 ---- */
extern BOOL btu_hcif_send_cmd(void* p_buf);

BOOL btsnd_hcic_inq_cancel(void) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0003; // length
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x02;           // opcode
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x00;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_accept_conn@0x80083BE8 ---- */
BOOL btsnd_hcic_accept_conn(u8* p_buf, u8* bd_addr, u8 role) {
    *(u16*)&p_buf[0x02] = 0x000A; // length
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x09; // opcode
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x07;

    p_buf[0x0B] = bd_addr[5];
    p_buf[0x0C] = bd_addr[4];
    p_buf[0x0D] = bd_addr[3];
    p_buf[0x0E] = bd_addr[2];
    p_buf[0x0F] = bd_addr[1];
    p_buf[0x10] = bd_addr[0];

    p_buf[0x11] = role;

    return btu_hcif_send_cmd(p_buf);
}

/* ---- btsnd_hcic_reject_conn@0x80083C48 ---- */
BOOL btsnd_hcic_reject_conn(u8* p_buf, u8* bd_addr, u8 reason) {
    *(u16*)&p_buf[0x02] = 0x000A; // length
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x0A; // opcode
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x07;

    p_buf[0x0B] = bd_addr[5];
    p_buf[0x0C] = bd_addr[4];
    p_buf[0x0D] = bd_addr[3];
    p_buf[0x0E] = bd_addr[2];
    p_buf[0x0F] = bd_addr[1];
    p_buf[0x10] = bd_addr[0];

    p_buf[0x11] = reason;

    return btu_hcif_send_cmd(p_buf);
}

/* ---- btsnd_hcic_auth_request@0x800841F8 ---- */
BOOL btsnd_hcic_auth_request(u32 handle) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0005; // length
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x11; // opcode
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x02;

    p_buf[0x0B] = (u8)handle;
    p_buf[0x0C] = (u8)(handle >> 8);

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_auth_request_80084478 ---- */
BOOL btsnd_hcic_auth_request_80084478(u32 handle) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0005; // length
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x1B; // opcode variant
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x02;

    p_buf[0x0B] = (u8)handle;
    p_buf[0x0C] = (u8)(handle >> 8);

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_auth_request_800844F4 / _80084570 ---- */
BOOL btsnd_hcic_auth_request_800844F4(u32 handle) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0005;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x1D;
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x02;

    p_buf[0x0B] = (u8)handle;
    p_buf[0x0C] = (u8)(handle >> 8);

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

BOOL btsnd_hcic_auth_request_80084570(u32 handle) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0005;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x1F;
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x02;

    p_buf[0x0B] = (u8)handle;
    p_buf[0x0C] = (u8)(handle >> 8);

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_reject_esco_conn@0x800847D0 ---- */
BOOL btsnd_hcic_reject_esco_conn(u8* p_buf, u8* bd_addr, u8 reason) {
    *(u16*)&p_buf[0x02] = 0x000A;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x2A;
    p_buf[0x09] = 0x04;
    p_buf[0x0A] = 0x07;

    p_buf[0x0B] = bd_addr[5];
    p_buf[0x0C] = bd_addr[4];
    p_buf[0x0D] = bd_addr[3];
    p_buf[0x0E] = bd_addr[2];
    p_buf[0x0F] = bd_addr[1];
    p_buf[0x10] = bd_addr[0];

    p_buf[0x11] = reason;

    return btu_hcif_send_cmd(p_buf);
}

/* ---- btsnd_hcic_reset@0x80084CB0 ---- */
BOOL btsnd_hcic_reset(void) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0003;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x03;
    p_buf[0x09] = 0x0C;
    p_buf[0x0A] = 0x00;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_write_pin_type@0x80084EC8 ---- */
BOOL btsnd_hcic_write_pin_type(u32 pin_type) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0004;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x0A;
    p_buf[0x09] = 0x0C;
    p_buf[0x0A] = 0x01;

    p_buf[0x0B] = (u8)pin_type;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_write_pin_type_8008543C ---- */
BOOL btsnd_hcic_write_pin_type_8008543C(u32 pin_type) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0004;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x20;
    p_buf[0x09] = 0x0C;
    p_buf[0x0A] = 0x01;

    p_buf[0x0B] = (u8)pin_type;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_read_stored_key@0x80084F3C ---- */
BOOL btsnd_hcic_read_stored_key(u8* p_buf, u8* bd_addr, u8 size) {
    *(u16*)&p_buf[0x02] = 0x000A;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x0D;
    p_buf[0x09] = 0x0C;
    p_buf[0x0A] = 0x07;

    p_buf[0x0B] = bd_addr[5];
    p_buf[0x0C] = bd_addr[4];
    p_buf[0x0D] = bd_addr[3];
    p_buf[0x0E] = bd_addr[2];
    p_buf[0x0F] = bd_addr[1];
    p_buf[0x10] = bd_addr[0];

    p_buf[0x11] = size;

    return btu_hcif_send_cmd(p_buf);
}

/* ---- btsnd_hcic_write_pin_type_800854B0 ---- */
BOOL btsnd_hcic_write_pin_type_800854B0(u32 pin_type) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0004;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x22;
    p_buf[0x09] = 0x0C;
    p_buf[0x0A] = 0x01;

    p_buf[0x0B] = (u8)pin_type;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_inq_cancel_8008576C ---- */
BOOL btsnd_hcic_inq_cancel_8008576C(void) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0003;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x01;
    p_buf[0x09] = 0x10;
    p_buf[0x0A] = 0x00;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_reset_800857CC ---- */
BOOL btsnd_hcic_reset_800857CC(void) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0003;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x03;
    p_buf[0x09] = 0x10;
    p_buf[0x0A] = 0x00;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_inq_cancel_80085850 ---- */
BOOL btsnd_hcic_inq_cancel_80085850(void) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0003;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x09;
    p_buf[0x09] = 0x10;
    p_buf[0x0A] = 0x00;

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_write_cur_iac_lap@0x800856FC ---- */
typedef u8 LAP[3];

typedef struct BT_HDR {
    u8 pad[2];
    u16 len;        // at 0x2
    u16 offset;     // at 0x4
    u8 layer_specific; // at 0x6
    u8 type;        // at 0x7
} BT_HDR;

BOOL btsnd_hcic_write_cur_iac_lap(void* buffer, u8 num_laps, LAP* iac_lap) {
    BT_HDR* p = buffer;
    u8* pp = (u8*)(p + 1);
    p->len = (u16)(3 + 1 + 3 * num_laps);
    p->offset = 0;

    *pp++ = 0x3A;
    *pp++ = 0x0C;
    *pp++ = (u8)(p->len - 3);
    *pp++ = num_laps;

    while (num_laps-- != 0) {
        *pp++ = iac_lap[0][2];
        *pp++ = iac_lap[0][1];
        *pp++ = iac_lap[0][0];
        iac_lap++;
    }

    return btu_hcif_send_cmd(buffer);
}

/* ---- btsnd_hcic_auth_request_800858B0 ---- */
BOOL btsnd_hcic_auth_request_800858B0(u32 handle) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0005;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x03;
    p_buf[0x09] = 0x14;
    p_buf[0x0A] = 0x02;

    p_buf[0x0B] = (u8)handle;
    p_buf[0x0C] = (u8)(handle >> 8);

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- btsnd_hcic_read_rssi@0x8008592C ---- */
BOOL btsnd_hcic_read_rssi(u32 handle) {
    u8* p_buf;

    if ((p_buf = GKI_getpoolbuf(2)) == NULL) {
        return FALSE;
    }

    *(u16*)&p_buf[0x02] = 0x0005;
    *(u16*)&p_buf[0x04] = 0x0000;
    p_buf[0x08] = 0x05;
    p_buf[0x09] = 0x14;
    p_buf[0x0A] = 0x02;

    p_buf[0x0B] = (u8)handle;
    p_buf[0x0C] = (u8)(handle >> 8);

    btu_hcif_send_cmd(p_buf);

    return TRUE;
}

/* ---- HID_DevInit@0x80085F48 ---- */
extern u8 lbl_803C3AF0[]; // hidd_cb
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

/* ---- HID_HostRegister@0x80086A10 ---- */
extern u8 lbl_803C3C38[]; // hidh_cb
extern u8 hidh_conn_reg(void);

u32 HID_HostRegister(void* p_cback) {
    u8* cb = lbl_803C3C38;
    u8 status;

    if (cb[0x400] != 0) {
        return 2;
    }

    if (p_cback == NULL) {
        return 5;
    }

    status = (u8)hidh_conn_reg();
    if (status != 0) {
        return status;
    }

    *(void**)&cb[0x340] = p_cback;
    cb[0x400] = 1;

    return 0;
}

/* ---- HID_HostOpenDev@0x80086DC8 ---- */
extern u32 hidh_conn_initiate(u16 dev);

u32 HID_HostOpenDev(u16 dev) {
    u8* cb = lbl_803C3C38;

    if (cb[0x400] == 0) {
        return 1;
    }

    if (dev > 0x10 || cb[dev * 0x34] == 0) {
        return 5;
    }

    if (cb[dev * 0x34 + 0x0A] != 0) {
        return 0xA;
    }

    cb[dev * 0x34 + 0x0C] = 1;

    return hidh_conn_initiate(dev);
}

/* ---- l2c_link_hci_qos_violation@0x8008B818 ---- */
/* tL2C_LCB: p_first_ccb @0x8; tL2C_CCB: p_next_ccb @0x8, p_rcb @0x30;
 * p_rcb api QoSViolationInd callback @0x20. */
extern u8* l2cu_find_lcb_by_handle(u16 handle);
extern void fn_80089E40(void* p_ccb, u32 evt, void* param); // l2c_csm_execute

typedef struct tL2C_CCB_view {
    u8 pad[0x8];
    void* p_next_ccb;  // at 0x8
    u8 pad2[0x24];
    void* p_rcb;       // at 0x30
} tL2C_CCB_view;

typedef struct tL2C_LCB_view {
    u8 pad[0x8];
    void* p_first_ccb; // at 0x8
} tL2C_LCB_view;

BOOL l2c_link_hci_qos_violation(u16 handle) {
    tL2C_LCB_view* p_lcb;
    tL2C_CCB_view* p_ccb;
    u8* p_rcb;

    p_lcb = (tL2C_LCB_view*)l2cu_find_lcb_by_handle(handle);
    if (p_lcb == NULL) {
        return FALSE;
    }

    for (p_ccb = p_lcb->p_first_ccb; p_ccb; p_ccb = p_ccb->p_next_ccb) {
        p_rcb = p_ccb->p_rcb;
        if (*(void**)&p_rcb[0x20] != NULL) {
            fn_80089E40(p_ccb, 6, NULL);
        }
    }

    return TRUE;
}

/* ---- l2cap_link_chk_pkt_end@0x8008C230 ---- */
/* l2cb: p_cur_hcit_lcb @0x7BC; tL2C_LCB: p_hcit_rcv_acl @0x50. */
extern u8 lbl_803C4040[]; // l2cb

BOOL l2cap_link_chk_pkt_end(void) {
    u8* p_lcb;
    u8* p_buf;
    u16 offset;
    u16 len;
    u16 l2cap_len;

    p_lcb = *(u8**)&lbl_803C4040[0x7BC];
    if (p_lcb == NULL) {
        return TRUE;
    }

    p_buf = *(u8**)&p_lcb[0x50];
    if (p_buf == NULL) {
        return TRUE;
    }

    offset = *(u16*)&p_buf[0x04];
    len = *(u16*)&p_buf[0x02];

    l2cap_len = (u16)(p_buf[offset + 0x0C] | (p_buf[offset + 0x0D] << 8));

    if (l2cap_len <= (len - 8)) {
        *(u8**)&p_lcb[0x50] = NULL;
        return TRUE;
    }

    return FALSE;
}

/* ---- l2c_link_role_change_failed@0x8008C31C ---- */
/* l2cb.lcb_pool @+8, stride 0x5C; in_use @+0, link_state @+4,
 * LST_CONNECTING_WAIT_SWITCH = 2. */
extern void l2cu_create_conn_after_switch(void* p_lcb);

void l2c_link_role_change_failed(void) {
    u8* p_lcb;
    s32 xx;

    p_lcb = &lbl_803C4040[0x8];

    for (xx = 0; xx < 4; xx++, p_lcb += 0x5C) {
        if (p_lcb[0x0] != 0 && *(s32*)&p_lcb[0x04] == 2) {
            l2cu_create_conn_after_switch(p_lcb);
        }
    }
}

/* ---- l2cu_find_ccb_by_cid@0x8008EB88 ---- */
/* l2cb.ccb_pool @+0x78 (entries in_use byte at base), stride 0x7C,
 * p_lcb field @+0x10. */
void* l2cu_find_ccb_by_cid(void* p_lcb, u16 cid) {
    u8* p_ccb = NULL;

    if (cid >= 0x40) {
        p_ccb = &lbl_803C4040[0x178 + ((cid - 0x40) & 0xFFFF) * 0x7C];

        if (*(u8*)p_ccb == 0) {
            p_ccb = NULL;
        } else if (p_lcb != NULL && *(void**)&p_ccb[0x10] != p_lcb) {
            p_ccb = NULL;
        }
    }

    return p_ccb;
}

extern u8 lbl_803C4828[]; // port pool

/* ---- port_find_mcb_dlci_port@0x80090A40 ---- */
/* mcb port-state table at mcb+0x24 keyed by dlci; port pool at
 * lbl_803C4828 + 0x68, stride 0xA4. */
void* port_find_mcb_dlci_port(u8* mcb, u8 dlci) {
    if (mcb == NULL) {
        return NULL;
    }

    if (dlci > 0x3D) {
        return NULL;
    }

    if (mcb[dlci + 0x24] == 0) {
        return NULL;
    }

    return &lbl_803C4828[(mcb[dlci + 0x24] - 1) * 0xA4 + 0x68];
}

/* ---- port_flow_control_user@0x80090B1C ---- */
u32 port_flow_control_user(u8* p_port) {
    u8* port = p_port;
    u8* mcb;
    u8 flow;

    flow = FALSE;

    if (port[0x24] != 0 || *(u8**)&port[0x6C] == NULL ||
        (*(u8**)&port[0x6C])[0x71] == 0 || *(u32*)&port[0x28] > 0x1F40 ||
        *(u16*)&port[0x20] > 0x10) {
        flow = TRUE;
    }

    if (port[0x25] != flow) {
        port[0x25] = flow;
        if (flow == 0) {
            return 0x30000;
        }
        return 0x10000;
    }

    return 0;
}

/* ---- port_get_signal_changes@0x80090B8C ---- */
u32 port_get_signal_changes(u8* p_port, u8 old_signals, u8 new_signals) {
    u32 diff = new_signals ^ old_signals;
    u32 result = 0;

    if (diff & 0x01) {
        result |= 0x10;
        if (new_signals & 0x01) {
            result |= 0x800;
        }
    }
    if (diff & 0x02) {
        result |= 0x08;
        if (new_signals & 0x02) {
            result |= 0x400;
        }
    }
    if (diff & 0x04) {
        result |= 0x100;
    }
    if (diff & 0x08) {
        result |= 0x20;
        if (new_signals & 0x08) {
            result |= 0x1000;
        }
    }

    return *(u32*)&p_port[0x88] & result;
}

/* ---- SDP_ServiceSearchRequest@0x80095BA4 ---- */
/* sdp_ccb: fields at +0x410/+0x414 (params), +0x474 (flags byte). */
extern u8* sdp_conn_originate(void* bd_addr);

BOOL SDP_ServiceSearchRequest(void* bd_addr, u32 p1, u32 p2) {
    u8* p_ccb;

    if ((p_ccb = sdp_conn_originate(bd_addr)) == NULL) {
        return FALSE;
    }

    p_ccb[0x474] = 0;
    *(u32*)&p_ccb[0x410] = p1;
    *(u32*)&p_ccb[0x414] = p2;

    return TRUE;
}

/* ---- SDP_ServiceSearchAttributeRequest@0x80095C00 ---- */
BOOL SDP_ServiceSearchAttributeRequest(void* bd_addr, u32 p1, u32 p2) {
    u8* p_ccb;

    if ((p_ccb = sdp_conn_originate(bd_addr)) == NULL) {
        return FALSE;
    }

    p_ccb[0x474] = 0;
    *(u32*)&p_ccb[0x410] = p1;
    *(u32*)&p_ccb[0x414] = p2;
    p_ccb[0x475] = 1;

    return TRUE;
}

/* ---- sdp_db_find_record@0x800968A8 ---- */
/* sdp_db records: count u16 @0x1222, records @0x1224, stride 0x298,
 * handle u32 @record+0. */
extern u8 lbl_803C4C40[]; // sdp_db

void* sdp_db_find_record(u32 record_handle) {
    u8* start = &lbl_803C4C40[0x1224];
    u8* end = start + (u32)(*(u16*)&lbl_803C4C40[0x1222]) * 0x298;
    u8* p;

    for (p = start; p < end; p += 0x298) {
        if (*(u32*)p == record_handle) {
            return p;
        }
    }

    return NULL;
}

/* ---- sdpu_allocate_ccb@0x80099EE4 ---- */
/* sdp ccb pool @lbl_803C4C40+0x3C, stride 0x478, in-use byte @+0,
 * self-link @+0x18. */
void* sdpu_allocate_ccb(void) {
    u8* p_ccb;
    u32 i;

    p_ccb = &lbl_803C4C40[0x3C];

    for (i = 0; i < 4; i++) {
        p_ccb = &lbl_803C4C40[0x3C + i * 0x478];

        if (*(u8*)p_ccb == 0) {
            memset(p_ccb, 0, 0x478);
            *(void**)&p_ccb[0x18] = p_ccb;
            return p_ccb;
        }
    }

    return NULL;
}
