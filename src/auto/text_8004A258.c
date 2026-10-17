#include <types.h>

extern void OSExceptionVector(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void __OSDBIntegrator(void) {
    volatile u32 *p = (volatile u32 *)0x48;
    * (volatile u32 *)0x4C = __builtin_return_address(0);
    *(volatile u32 *)0x48 |= 0x80000000;
    __builtin_unreachable();
}

void __OSDBJump(void) {
    __OSDBJUMPDEST();
}

extern void *OSExceptionTable_8055D9D0[256];
#pragma small_data on
void *__OSGetExceptionHandler(s32 arg0) {
    return OSExceptionTable_8055D9D0[(u8)arg0];
}

void __OSPSInit(void) {
    PPCMthid2(PPCMfhid2() | 0xA0000000);
    ICFlashInvalidate();
    __sync();
    OSInitFastCast();
}

u32 __OSGetDIConfig(void) {
    return *(volatile u32 *)0xCD006024 & 0xFF;
}

void OSRegisterVersion(const char *ver) {
    OSReport("%s\n", ver);
}

extern BOOL __OSInIPL;
extern const char *AppGameNameForSysMenu;
extern char GameNameBuffer[5];
extern u8 DriveInfo[4];
u8 OSGetAppType(void) {
    if (__OSInIPL) return 0x40;
    return *(u8 *)0x80003184;
}

