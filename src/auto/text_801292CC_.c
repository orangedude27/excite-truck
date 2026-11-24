// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055DFA8; /* id of the currently loaded stream bank */
extern float lbl_80561238, lbl_8056123C, lbl_80561240; /* full/half/mute mix levels */
extern char lbl_8032A588[0x14], lbl_80559978; /* "SpuQueueLoadBank!" and "%s.bnk" */
extern char lbl_8032A59C[]; /* "SpuQueueUnloadBank!" */
extern int fn_802E765C(int,int,int);
extern int fn_802E7684(float);
extern int fn_802E30C8(const char *, ...);
extern int unloadStrmBank(int);
extern int fn_802E75E4(const char *);
extern int sprintf(char *, const char *, ...);
#define spuLogPrint fn_802E30C8
#define gLoadBankLog lbl_8032A588 /* "SpuQueueLoadBank!" */
#define gUnloadBankLog lbl_8032A59C /* "SpuQueueUnloadBank!" */
#define sBankFileNameFmt lbl_80559978 /* "%s.bnk" */
#define spuUnloadBank unloadStrmBank
#define gLoadedBankId lbl_8055DFA8
#pragma scheduling invalid_target
/* Loads a sound bank by id: logs the operation, formats "<id>.bnk", and stores the loaded bank handle. */
void fn_801292CC(int bankId) {
    char sp8[24];
    spuLogPrint((const char *)(void *)&gLoadBankLog);
    sprintf(sp8, (const char *)(void *)&sBankFileNameFmt, bankId);
    gLoadedBankId = fn_802E75E4(sp8);
}
#pragma scheduling on

void fn_80129324(void) {
    /* Unload the currently loaded stream bank ("SpuQueueUnloadBank!"): log the
       unload, hand the bank handle to the stream-bank manager, then clear it. */
    spuLogPrint(gUnloadBankLog);
    spuUnloadBank(gLoadedBankId);
    gLoadedBankId = 0;
}

/* Unload the currently loaded stream bank: hand its handle to the stream-bank
   manager's unload routine, forwarding the bank id and flags. */
void fn_80129360(int bankId, int flags) { fn_802E765C(gLoadedBankId, bankId, flags); }

/* These level constants are fed to the stream manager's per-channel level setter (f24). */
#define FULL_LEVEL lbl_80561238 /* 1.0f */
#define HALF_LEVEL lbl_8056123C /* 0.5f */
#define MUTE_LEVEL lbl_80561240 /* 0.0f */
#define setStreamBankLevel fn_802E7684

/* Set a stream-bank channel's mix level: channel 1 uses full scale and channel 0
 * half scale, unless the enable flag is clear, which mutes the channel. */
void fn_80129374(int channel, int enabled) {
    float level;
    if (channel == 1)
        level = FULL_LEVEL;
    else
        level = HALF_LEVEL;
    setStreamBankLevel(enabled != 0 ? level : MUTE_LEVEL);
}

