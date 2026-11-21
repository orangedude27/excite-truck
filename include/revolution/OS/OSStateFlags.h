#ifndef RVL_SDK_OS_STATE_FLAGS_H
#define RVL_SDK_OS_STATE_FLAGS_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSStateFlags {
    u32 checksum; // at 0x0
    u8 BYTE_0x4;
    u8 bootType;  // at 0x5: requested mode for the next boot (1 shutdown, 3 menu, 5 WC24 idle)
    u8 discState; // at 0x6
    u8 BYTE_0x7;
    u32 WORD_0x8;
    u32 WORD_0xC;
    u32 WORD_0x10;
    u32 WORD_0x14;
    u32 WORD_0x18;
    u32 WORD_0x1C;
} OSStateFlags;

BOOL __OSWriteStateFlags(const OSStateFlags* state);
BOOL __OSReadStateFlags(OSStateFlags* state);

#ifdef __cplusplus
}
#endif
#endif
