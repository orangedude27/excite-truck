// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/bta/include/ptim.h"
#include "revolution/BTE/gki/platform/gki_int.h"

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

s32 fn_8006DF60(s32 *arg0) {
    return *arg0;
}

extern void fn_8006EBAC(void);
extern void fn_8006EB88(void);
extern u8 fn_8006EB80(void);
extern u32 lbl_803946C0[];
s32 fn_8006DF68(s32 *arg0) {
    s32 val = arg0[-2];
    if (val != 0) {
        return val + 8;
    }
    return 0;
}

u8 fn_8006DF84(void *arg0) {
    u16 val = *(u16 *)((u8 *)arg0 + 8);
    u32 clz = __builtin_clz(val);
    return (u8)(clz >> 19);
}

void fn_8006EACC(void) {

}

void fn_8006EAD0(void) {

}

void fn_8006EAD4(void) {

}

void fn_8006EAD8(void) {

}

void fn_8006EBF0(void) {

}

void fn_8006EC20(void) {
    fn_80068E08();
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

void fn_80089E3C(void) {

}

void fn_800911DC(void) {

}

void fn_800932D8(void) {

}

void fn_8009BFBC(void) {
    AXFXReverbHiExpCallback();
}

