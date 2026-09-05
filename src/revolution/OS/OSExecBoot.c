#include <revolution/OS.h>

extern void __OSBootDol(u32 doloffset, u32 restartCode, const char** argv);

static u32 lbl_8055DA74;
static u32 lbl_8055DA70;

/* fn_80052390 - disable interrupts, set arenas, launch DOL */
void fn_80052390(u32 dolAddr, u32 bootAddr) {
    u32 dummy;

    OSDisableInterrupts();
    OSSetArenaLo((void*)0x81280000);
    OSSetArenaHi((void*)0x812F0000);
    dummy = 0;
    __OSBootDol(bootAddr, dolAddr | 0x80000000, (const char**)&dummy);
}

/* fn_800523F0 - read reboot params */
void fn_800523F0(u32* a, u32* b) {
    *a = lbl_8055DA70;
    *b = lbl_8055DA74;
}
