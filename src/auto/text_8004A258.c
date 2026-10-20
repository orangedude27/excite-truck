#include <types.h>

extern void **OSExceptionTable_8055D9D0;
extern void OSExceptionVector(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void __OSGetIOSRev(char *rev) {
    u32 version = *(u32 *)0xC0003144;
    u32 date = *(u32 *)0xC0003140;
    rev[3] = date;
    rev[0] = date >> 24;
    rev[1] = date >> 16;
    rev[2] = date >> 8;
    rev[4] = version >> 16;
    rev[5] = ((version >> 8) & 0xF) + (((version >> 12) & 0xF) * 10);
    *(u16 *)(rev + 6) = (u8)version + 0x7D0;
}

void __OSDBIntegrator(void) {
    volatile u32 *p = (volatile u32 *)0x48;
    * (volatile u32 *)0x4C = __builtin_return_address(0);
    *(volatile u32 *)0x48 |= 0x80000000;
    __builtin_unreachable();
}

extern void __OSDBJump(void) {
    OSExceptionVector();
}

#pragma small_data on
void *__OSSetExceptionHandler(u8 type, void *handler) {
    void *old = OSExceptionTable_8055D9D0[type];
    OSExceptionTable_8055D9D0[type] = handler;
    return old;
}

extern void **OSExceptionTable_8055D9D0;
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

extern void OSReport(const char *, ...);
extern const char lbl_80558F0C[];
extern const char lbl_80558F0C[4];
void OSRegisterVersion(const char *ver) {
    OSReport(lbl_80558F0C, ver);
}

extern BOOL __OSInIPL;
extern const char *AppGameNameForSysMenu;
extern char GameNameBuffer[5];
extern u8 DriveInfo[4];
u8 OSGetAppType(void) {
    if (__OSInIPL) return 0x40;
    return *(u8 *)0x80003184;
}

