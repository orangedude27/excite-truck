#ifndef RVL_SDK_KPAD_PRIVATE_H
#define RVL_SDK_KPAD_PRIVATE_H

#include <types.h>
#include <revolution/KPAD/KPAD.h>

typedef struct KPADInsideStatus {
    /* REXE01 has four records at 0x8037C808, each 0x400 bytes. */
    KPADStatus status; /* 0x000 */
    u32 status_pad; /* REXE01 KPADStatus occupies 0x88 bytes */
    f32 pos_play_radius; /* 0x088 */
    f32 pos_sensitivity; /* 0x08C */
    f32 hori_play_radius; /* 0x090 */
    f32 hori_sensitivity; /* 0x094 */
    f32 dist_play_radius; /* 0x098 */
    f32 dist_sensitivity; /* 0x09C */
    f32 acc_play_radius; /* 0x0A0 */
    f32 acc_sensitivity; /* 0x0A4 */
    f32 dist_org; /* 0x0A8 */
    Vec2 accXY_nrm_hori; /* 0x0AC */
    Vec2 sec_nrm_hori; /* 0x0B4 */
    Vec2 center_org; /* 0x0BC */
    f32 dpd2pos_scale; /* 0x0C4 */
    u8 private_state[0x338]; /* 0x0C8..0x3FF */
} KPADInsideStatus;


#endif
