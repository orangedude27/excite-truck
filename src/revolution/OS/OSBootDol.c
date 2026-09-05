#include <revolution/OS.h>

extern void fn_800523F0(u32* saveStart, u32* saveEnd);
extern void fn_8004E538(s32 doloffset, u32 restartCode, void* regionStart,
                        void* regionEnd, BOOL argsUseDefault, s32 argc,
                        char** argv);

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
