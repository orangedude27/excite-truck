#include <revolution/AI.h>
#include <revolution/DSP.h>
#include <revolution/OS.h>

u32 lbl_8055D6A8;

static AIDMACallback __AID_Callback;

AIDMACallback AIRegisterDMACallback(AIDMACallback callback) {
    AIDMACallback oldCallback;
    BOOL enabled;

    oldCallback = __AID_Callback;
    enabled = OSDisableInterrupts();
    __AID_Callback = callback;
    OSRestoreInterrupts(enabled);

    return oldCallback;
}

void AIInitDMA(void* buffer, u32 length) {
    BOOL enabled;

    enabled = OSDisableInterrupts();

    DSP_HW_REGS[DSP_AI_DMA_START_H] =
        (DSP_HW_REGS[DSP_AI_DMA_START_H] & ~0x1FFF) |
        (((uintptr_t)buffer) >> 16 & 0xFFFF);

    DSP_HW_REGS[DSP_AI_DMA_START_L] =
        (DSP_HW_REGS[DSP_AI_DMA_START_L] & ~0xFFE0) |
        (((uintptr_t)buffer) & 0xFFFF);

    DSP_HW_REGS[DSP_AI_DMA_CSR] =
        (DSP_HW_REGS[DSP_AI_DMA_CSR] & ~0x7FFF) | ((length / 32) & 0xFFFF);

    OSRestoreInterrupts(enabled);
}

void AIStartDMA(void) {
    DSP_HW_REGS[DSP_AI_DMA_CSR] |= DSP_AI_DMA_CSR_PLAY;
}

void AIStopDMA(void) {
    DSP_HW_REGS[DSP_AI_DMA_CSR] &= ~DSP_AI_DMA_CSR_PLAY;
}

u32 AIGetDMAStatus(void) {
    return lbl_8055D6A8;
}