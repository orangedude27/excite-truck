#include <revolution/OS.h>

extern void __OSBootDol(u32 doloffset, u32 restartCode, const char** argv);
extern void fn_8004E538(s32 doloffset, u32 restartCode, void* regionStart,
                        void* regionEnd, BOOL argsUseDefault, s32 argc,
                        char** argv);

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

void __OSBootDol(u32 doloffset, u32 restartCode, const char** argv) {
    char doloffInString[20];
    s32 argvlen;
    char** argvToPass;
    s32 i;
    void* saveStart;
    void* saveEnd;

    fn_800523F0((u32*)&saveStart, (u32*)&saveEnd);
    sprintf(doloffInString, "%d", doloffset);
    argvlen = 0;

    if (argv != 0) {
        while (argv[argvlen] != 0)
            argvlen++;
    }

    argvlen++;
    argvToPass = (char**)OSAllocFromMEM1ArenaLo((argvlen + 1) * 4, 1);
    *argvToPass = doloffInString;

    for (i = 1; i < argvlen; i++)
        argvToPass[i] = (char*)argv[i - 1];

    fn_8004E538(-1, restartCode, saveStart, saveEnd, FALSE, argvlen,
                argvToPass);
}
