#ifndef RVL_SDK_OS_CACHE_H
#define RVL_SDK_OS_CACHE_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

#define OS_CACHE_BASE 0xE0000000

// Locked cache (LC) DMA transfers are counted in cache lines ("blocks"), and
// the transfer length is split over DMAU/DMAL, so a single transfer moves at
// most LC_MAX_BLOCKS lines.
#define LC_LINE_SIZE 32
#define LC_MAX_BLOCKS 128
#define LC_MAX_TRANSFER (LC_LINE_SIZE * LC_MAX_BLOCKS)

// Forward declarations
typedef struct OSContext OSContext;

void DCEnable(void);
void DCInvalidateRange(const void* buf, u32 len);
void DCFlushRange(const void* buf, u32 len);
void DCStoreRange(const void* buf, u32 len);
void DCFlushRangeNoSync(const void* buf, u32 len);
void DCStoreRangeNoSync(const void* buf, u32 len);
void DCZeroRange(const void* buf, u32 len);

void ICInvalidateRange(const void* buf, u32 len);
void ICFlashInvalidate(void);
void ICEnable(void);

void LCEnable(void);
void LCDisable(void);
void LCLoadBlocks(void* dst, const void* src, u32 blocks);
void LCStoreBlocks(void* dst, const void* src, u32 blocks);
u32 LCLoadData(void* dst, const void* src, u32 len);
u32 LCStoreData(void* dst, const void* src, u32 len);
void LCQueueWait(u32 n);

void L2Enable(void);
void L2Disable(void);
void L2GlobalInvalidate(void);

void DMAErrorHandler(u8 error, OSContext* ctx, u32 dsisr, u32 dar, ...);

void __OSCacheInit(void);

#ifdef __cplusplus
}
#endif
#endif
