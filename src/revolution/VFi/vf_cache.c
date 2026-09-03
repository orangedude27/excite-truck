#include <types.h>

/* Review carve for the REXE01 VFi PF-cache cluster (auto_03_800A485C_text):
 *
 *   VFiPFCACHE_WriteFATSectorAndFreeIfNeeded@0x800A9048
 *   VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded@0x800A8F70
 *   VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded_800A9098
 *   VFiPFCACHE_FlushAllCaches@0x800A9208
 *
 * PF_VOLUME: total_sectors @+0x8, cache FAT ptr @+0x1630,
 * current data page ptr @+0x1634.  Review-only; not configured.
 */

extern s32 fn_800A861C(void* p_vol, void* p_cache, u8* p_buf, u32 sector);
extern s32 VFiPFCACHE_DoReadNumSector(void* p_vol, void* p_cache, u8* p_buf,
                                      u32 sector, u32 num_sector,
                                      u32* p_num_success);
extern s32 fn_800A8730(void* p_vol, void* p_cache, u8* p_buf, u32 sector,
                       u32 num_sector, u32* p_num_success);
extern s32 fn_800A8AD4(void* p_vol, void* p_cache);

s32 VFiPFCACHE_WriteFATSectorAndFreeIfNeeded(void* p_vol, u8* p_buf,
                                             u32 sector) {
    s32 err;

    if (sector >= *(u32*)&((u8*)p_vol)[0x08]) {
        return 16;
    }

    err = fn_800A861C(p_vol, &((u8*)p_vol)[0x1630], p_buf, sector);
    if (!err) {
        return 0;
    }

    return err;
}

s32 VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded(void* p_vol, u8* p_buf,
                                                 u32 sector, u32 num_sector,
                                                 u32* p_num_success) {
    s32 err;

    if (sector >= *(u32*)&((u8*)p_vol)[0x08]) {
        return 16;
    }

    err = VFiPFCACHE_DoReadNumSector(p_vol, &((u8*)p_vol)[0x1634], p_buf,
                                     sector, num_sector, p_num_success);
    if (!err) {
        return 0;
    }

    return err;
}

s32 VFiPFCACHE_WriteDataNumSectorAndFreeIfNeeded_800A9098(void* p_vol,
                                                          u8* p_buf,
                                                          u32 sector,
                                                          u32 num_sector,
                                                          u32* p_num_success) {
    s32 err;

    if (sector >= *(u32*)&((u8*)p_vol)[0x08]) {
        return 16;
    }

    err = fn_800A8730(p_vol, &((u8*)p_vol)[0x1634], p_buf, sector, num_sector,
                      p_num_success);
    if (!err) {
        return 0;
    }

    return err;
}

s32 VFiPFCACHE_FlushAllCaches(void* p_vol) {
    s32 err;

    err = fn_800A8AD4(p_vol, *(void**)&((u8*)p_vol)[0x1630]);
    if (err != 0) {
        return err;
    }

    err = fn_800A8AD4(p_vol, *(void**)&((u8*)p_vol)[0x1634]);
    if (!err) {
        return 0;
    }

    return err;
}
/* ---- VFiPFENT_CalcCheckSum@0x800AA47C ---- */
extern void fn_800B3A70(u8* buf, u8* short_name, u32 flags);

u8 VFiPFENT_CalcCheckSum(u8* p_ent) {
    u16 i;
    u8 sum;
    u8 buf[13];

    fn_800B3A70(buf, &p_ent[0x20E], 0);
    sum = 0;

    for (i = 0; i < 0xB; i++) {
        sum = (u8)((sum >> 1) + ((sum & 0x1) != 0 ? 0x80 : 0) + buf[i]);
    }

    return sum;
}

/* ---- VFiPFFAT_TraceClustersChain@0x800AF474 ---- */
extern s32 fn_800AF5A0(void* p_ffd, u16 start_clst);
extern s32 fn_800AFE14(void* p_ffd);
extern s32 fn_800B0258(void* p_ffd);

s32 VFiPFFAT_TraceClustersChain(void* p_ffd, u32 start_clst, u32 size,
                                u32* p_target_clst, u32* p_next_clst) {
    s32 err;

    switch (*(u32*)&((u8*)p_ffd)[0x1C]) {
    case 0:
        err = fn_800AF5A0(p_ffd, (u16)start_clst);
        break;
    case 1:
        err = fn_800AFE14(p_ffd);
        break;
    case 2:
        err = fn_800B0258(p_ffd);
        break;
    default:
        *p_next_clst = (u32)-1;
        err = 0xF;
        break;
    }

    return (s32)(err != 0 ? err : 0);
}

/* ---- VFiPFPATH_GetLengthFromShortname@0x800B3FEC ---- */
u32 VFiPFPATH_GetLengthFromShortname(const s8* sSrc) {
    s32 i;
    u32 szStr;

    for (szStr = i = 0; sSrc[i]; i++) {
        if (i == 8 && (sSrc[i] != ' ' || sSrc[i + 1] != ' ' || sSrc[i + 2] != ' ')) {
            szStr++;
        }
        if (sSrc[i] != ' ') {
            szStr++;
        }
    }

    return szStr;
}

/* ---- VFiPFCODE_CP932_isOEMMBchar@0x800B7234 ---- */
u32 VFiPFCODE_CP932_isOEMMBchar(s8 cp932, u32 num) {
    u8 code = (u8)cp932;

    switch (num) {
    case 1:
        return (code >= 0x81 && code <= 0x9F) ||
                       (code >= 0xE0 && code <= 0xFC)
                   ? 1
                   : 0;

    case 2:
        return (code >= 0x40 && code <= 0x7E) ||
                       (code >= 0x80 && code <= 0xFC)
                   ? 1
                   : 0;

    default:
        return 0;
    }
}
