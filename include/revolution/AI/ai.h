#ifndef RVL_SDK_AI_H
#define RVL_SDK_AI_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations
typedef struct OSContext OSContext;

typedef void (*AIDMACallback)(void);

typedef enum {
    AI_DSP_32KHZ,
    AI_DSP_48KHZ,
} AIDSPSampleRate;

// The AI DMA engine counts a transfer's length in 32-byte blocks.
#define AI_DMA_BLOCK_SIZE 32

AIDMACallback AIRegisterDMACallback(AIDMACallback callback);
void AIInitDMA(void* buffer, u32 length);
void AIStartDMA(void);
u32 AIGetDMABytesLeft(void);
void AISetDSPSampleRate(u32 rate);
u32 AIGetDSPSampleRate(void);
void AIInit(void* stack);
void __AIDHandler(s16 intr, OSContext* ctx);

#ifdef __cplusplus
}
#endif
#endif
