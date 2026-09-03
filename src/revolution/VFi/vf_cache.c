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