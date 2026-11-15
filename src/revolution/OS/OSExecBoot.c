#include <revolution/OS.h>

extern void __OSBootDol(u32 doloffset, u32 restartCode, const char** argv);

static u32 lbl_8055DA74;
static u32 lbl_8055DA70;

/* Disable interrupts, set the MEM1 arena bounds, and boot a DOL image. */
void fn_80052390(u32 dolOffset, u32 restartCode) {
    u32 argvDummy;

    OSDisableInterrupts();
    OSSetArenaLo((void*)0x81280000);
    OSSetArenaHi((void*)0x812F0000);
    argvDummy = 0;
    __OSBootDol(restartCode, dolOffset | 0x80000000, (const char**)&argvDummy);
}

/* fn_800523F0 - read reboot params */
void fn_800523F0(u32* a, u32* b) {
    *a = lbl_8055DA70;
    *b = lbl_8055DA74;
}
