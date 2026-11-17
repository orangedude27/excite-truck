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

/* Copies the saved MEM1 region bounds, recorded at boot from the exec params,
 * into @p saveStart and @p saveEnd. __OSBootDol forwards them to the reboot
 * call so that this region survives the DOL launch. */
void fn_800523F0(u32* saveStart, u32* saveEnd) {
    *saveStart = lbl_8055DA70;
    *saveEnd = lbl_8055DA74;
}
