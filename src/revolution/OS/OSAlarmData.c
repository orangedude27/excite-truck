#include <revolution/OS.h>

BOOL OnReset(BOOL final, u32 event);

OSShutdownFunctionInfo ShutdownFunctionInfo = {OnReset, 0xFFFFFFFF};
