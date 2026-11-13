#include <revolution/AI.h>
#include <revolution/DSP.h>
#include <revolution/OS.h>

u32 lbl_8055D6A8;

/**
 * Loads the DSP's audio-interface (AI) DMA engine with the next block of samples
 * to play, but leaves it stopped; AIStartDMA() kicks the transfer off. The three
 * registers are updated with interrupts disabled so a running transfer never sees
 * a half-written address or length.
 *
 * @param buffer  Address of the sample block (the engine works in 32-byte units).
 * @param length  Size of the block in bytes.
 */
void AIInitDMA(void* buffer, u32 length) {
    BOOL enabled;

    enabled = OSDisableInterrupts();

    DSP_HW_REGS[DSP_AI_DMA_START_H] =
        (DSP_HW_REGS[DSP_AI_DMA_START_H] & ~DSP_AI_DMA_START_H_ADDR) |
        (((uintptr_t)buffer) >> 16 & 0xFFFF);

    DSP_HW_REGS[DSP_AI_DMA_START_L] =
        (DSP_HW_REGS[DSP_AI_DMA_START_L] & ~DSP_AI_DMA_START_L_ADDR) |
        (((uintptr_t)buffer) & 0xFFFF);

    DSP_HW_REGS[DSP_AI_DMA_CSR] =
        (DSP_HW_REGS[DSP_AI_DMA_CSR] & ~DSP_AI_DMA_CSR_LEN) |
        ((length / AI_DMA_BLOCK_SIZE) & 0xFFFF);

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