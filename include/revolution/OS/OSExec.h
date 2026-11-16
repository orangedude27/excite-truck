#ifndef RVL_SDK_OS_EXEC_H
#define RVL_SDK_OS_EXEC_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSExecParams {
    UNKWORD WORD_0x0; // at 0x0: nonzero when booted from reboot params (reset-code flag)
    UNKWORD WORD_0x4; // at 0x4: the reboot's device/reset code, used by OSGetResetCode
    char UNK_0x8[0x4];
    void* regionStart; // at 0xC
    void* regionEnd;   // at 0x10
    char UNK_0x14[0x1C - 0x14];
} OSExecParams;

extern BOOL __OSInReboot;

void __OSGetExecParams(OSExecParams* out);
void __OSLaunchMenu(void);

#ifdef __cplusplus
}
#endif
#endif
