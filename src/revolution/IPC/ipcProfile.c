#include <revolution/IPC.h>

/* IPC request profiling: track queued and in-flight requests by file
 * descriptor so the SDK can account for each one from queue through reply. */

#define IPC_REQUEST_MAX 32

/* Request-tracking state living in the build's BSS/SBSS: a free-slot table of
 * (request pointer, file descriptor) pairs plus the counts of pending and
 * not-yet-issued requests. */
extern s32 IpcFdArray[IPC_REQUEST_MAX];
extern IPCRequestEx* IpcReqPtrArray[IPC_REQUEST_MAX];
extern s32 IpcNumPendingReqs;
extern s32 IpcNumUnIssuedReqs;

static void AddReqInfo(IPCRequestEx* req, s32 fd);
static void DelReqInfo(IPCRequestEx* req, s32 fd);

void IPCiProfInit(void) {
    /* Reset IPC profiling counters and clear tracked request slots. */
    int i;

    IpcNumPendingReqs = 0;
    IpcNumUnIssuedReqs = 0;

    for (i = 0; i < IPC_REQUEST_MAX; i++) {
        IpcReqPtrArray[i] = NULL;
        IpcFdArray[i] = -1;
    }
}

/* Track a queued IPC request: increment pending/unissued counters and record request info. */
void IPCiProfQueueReq(IPCRequestEx* req, s32 fd) {
    IpcNumPendingReqs++;
    IpcNumUnIssuedReqs++;
    AddReqInfo(req, fd);
}

/* Acknowledge an issued IPC request by decrementing the unissued-request counter. */
void IPCiProfAck(void) {
    IpcNumUnIssuedReqs--;
}

/* A reply reached the application: stop counting the request as in flight and free its tracking slot. */
void IPCiProfReply(IPCRequestEx* req, s32 fd) {
    IpcNumPendingReqs--;
    DelReqInfo(req, fd);
}

static void AddReqInfo(IPCRequestEx* req, s32 fd) {
    u32 i;

    for (i = 0; i < IPC_REQUEST_MAX; i++) {
        if (IpcReqPtrArray[i] == NULL && IpcFdArray[i] == -1) {
            IpcReqPtrArray[i] = req;
            IpcFdArray[i] = fd;
            return;
        }
    }
}

static void DelReqInfo(IPCRequestEx* req, s32 fd) {
    u32 i;

    for (i = 0; i < IPC_REQUEST_MAX; i++) {
        if (req == IpcReqPtrArray[i] && IpcFdArray[i] == fd) {
            IpcReqPtrArray[i] = NULL;
            IpcFdArray[i] = -1;
            return;
        }
    }
}