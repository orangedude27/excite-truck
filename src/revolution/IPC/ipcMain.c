#include <revolution/IPC.h>
#include <revolution/OS.h>

static u8 Initialized = FALSE;
static void* IPCCurrentBufferLo = NULL;
static void* IPCCurrentBufferHi = NULL;
static void* IPCBufferLo = NULL;
static void* IPCBufferHi = NULL;

/* Initialize IPC buffer pointers from OS on first call. */
void IPCInit(void) {
    if (!Initialized) {
        IPCBufferHi = __OSGetIPCBufferHi();
        IPCBufferLo = __OSGetIPCBufferLo();
        IPCCurrentBufferHi = IPCBufferHi;
        IPCCurrentBufferLo = IPCBufferLo;
        Initialized = TRUE;
    }
}

/* Read a 32-bit IPC hardware register from the PPC-side register window. */
u32 IPCReadReg(s32 index) {
    return IPC_HW_REGS_PPC[index];
}

/* Write a 32-bit value to an IPC hardware register in the PPC-side register window. */
void IPCWriteReg(s32 index, u32 value) {
    IPC_HW_REGS_PPC[index] = value;
}

void* IPCGetBufferHi(void) {
    return IPCCurrentBufferHi;
}

void* IPCGetBufferLo(void) {
    return IPCCurrentBufferLo;
}

void IPCSetBufferLo(void* lo) {
    IPCCurrentBufferLo = lo;
}
