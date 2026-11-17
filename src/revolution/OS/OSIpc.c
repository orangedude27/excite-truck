#include <revolution/OS.h>

static void* IpcBufferLo = (void*)-1;
static void* IpcBufferHi = NULL;

/* Return the cached upper bound of the IPC buffer. */
void* __OSGetIPCBufferHi(void) {
    return IpcBufferHi;
}

/* Return the cached lower bound of the IPC buffer. */
void* __OSGetIPCBufferLo(void) {
    /* Return the cached lower bound of the IPC buffer. */
    return IpcBufferLo;
}

void __OSInitIPCBuffer(void) {
    /* Cache the IPC buffer bounds stored by the IPC driver at the physical IPC buffer registers. */
    IpcBufferLo = *(void**)OSPhysicalToCached(OS_PHYS_IPC_BUFFER_START);
    IpcBufferHi = *(void**)OSPhysicalToCached(OS_PHYS_IPC_BUFFER_END);
}
