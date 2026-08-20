#include <revolution/IPC.h>

#define IPC_REQUEST_MAX 32

// These BSS/SBSS symbols are owned by auto-unit objects in the original build.
// They're marked scope:global in symbols.txt so extern resolves correctly.
extern s32 IpcFdArray[IPC_REQUEST_MAX];
extern IPCRequestEx* IpcReqPtrArray[IPC_REQUEST_MAX];
extern s32 IpcNumPendingReqs;
extern s32 IpcNumUnIssuedReqs;

static void AddReqInfo(IPCRequestEx* req, s32 fd);
static void DelReqInfo(IPCRequestEx* req, s32 fd);

void IPCiProfInit(void) {
    int i;

    IpcNumPendingReqs = 0;
    IpcNumUnIssuedReqs = 0;

    for (i = 0; i < IPC_REQUEST_MAX; i++) {
        IpcReqPtrArray[i] = NULL;
        IpcFdArray[i] = -1;
    }
}

void IPCiProfQueueReq(IPCRequestEx* req, s32 fd) {
    IpcNumPendingReqs++;
    IpcNumUnIssuedReqs++;
    AddReqInfo(req, fd);
}

void IPCiProfAck(void) {
    IpcNumUnIssuedReqs--;
}

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