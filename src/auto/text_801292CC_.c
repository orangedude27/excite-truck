// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055DFA8;
extern float lbl_80561238, lbl_8056123C, lbl_80561240;
extern char lbl_8032A588[0x14], lbl_80559978;
extern char lbl_8032A59C[];
extern int fn_802E765C(int,int,int);
extern int fn_802E7684(float);
extern int fn_802E30C8(const char *, ...);
extern int fn_802E75FC(int);
extern int fn_802E75E4(const char *);
extern int sprintf(char *, const char *, ...);
#define spuLogPrint fn_802E30C8
#define gUnloadBankLog lbl_8032A59C
#define spuUnloadBank fn_802E75FC
#define gLoadedBankId lbl_8055DFA8
#pragma scheduling invalid_target
/* Loads a sound bank by id: logs the operation, formats "<id>.bnk", and stores the loaded bank handle. */
void fn_801292CC(int bankId) {
    char sp8[24];
    fn_802E30C8((const char *)(void *)&lbl_8032A588);
    sprintf(sp8, (const char *)(void *)&lbl_80559978, bankId);
    lbl_8055DFA8 = fn_802E75E4(sp8);
}
#pragma scheduling on

void fn_80129324(void) {
    /* Unload the currently loaded stream bank ("SpuQueueUnloadBank!"): log the
       unload, hand the bank handle to the stream-bank manager, then clear it. */
    spuLogPrint(gUnloadBankLog);
    spuUnloadBank(gLoadedBankId);
    gLoadedBankId = 0;
}

void fn_80129360(int a, int b) { fn_802E765C(lbl_8055DFA8,a,b); }

/* These level constants are fed to the stream manager's per-channel level setter (f24). */
#define FULL_LEVEL lbl_80561238 /* 1.0f */
#define HALF_LEVEL lbl_8056123C /* 0.5f */
#define MUTE_LEVEL lbl_80561240 /* 0.0f */
#define setStreamBankLevel fn_802E7684

void fn_80129374(int arg0, int arg1) {
    float v;
    if (arg0 == 1)
        v = lbl_80561238;
    else
        v = lbl_8056123C;
    if (arg1 != 0)
        fn_802E7684(v);
    else
        fn_802E7684(lbl_80561240);
}

