// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8037B8A0[32];
extern unsigned int lbl_8055D8F0;
extern unsigned char lbl_8055D8E0;
extern unsigned char lbl_8055D8E1;
extern unsigned char lbl_8055D900;
extern int lbl_8055D8F4;
extern unsigned int lbl_8037B8C0;
extern const char lbl_80302848[];
extern void (*FatalFunc_8055D8D8)(void);
extern unsigned char lbl_80560B08, lbl_80560B09, lbl_80560B0A, lbl_80560B0B;
extern const char *lbl_802EE878[];
extern char __ErrorInfo[];
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);
extern unsigned char SCGetLanguage(void);
extern unsigned short OSSetFontEncode(unsigned short);
extern void OSFatal(void *, void *, const char *);
extern unsigned long long OSGetTime(void);
extern unsigned long long __div2i(unsigned long long, unsigned long long);
extern char lbl_80302384[];
extern void fn_8003A10C(void);
extern char lbl_8037B6D0[];
extern int NANDPrivateCreateDirAsync(const char *, int, int, void (*)(int), void *);
void __DVDPrintFatalMessage(void) {
    if (FatalFunc_8055D8D8 != 0) {
        FatalFunc_8055D8D8();
    }
}

int doTransactionCallback(int arg0, void *arg1) {
    int result = arg0;
    int (*callback)(int);

    if (((unsigned int)*(unsigned int *)((char *)arg1 + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(lbl_80302848);
        *(unsigned int *)((char *)arg1 + 0xC) = 0xFEEBDAED;
    } else {
        lbl_8055D8E0 = 0;
        callback = *(int (**)(int))arg1;
        if (callback != 0) {
            lbl_8055D8E1 = 1;
            if (lbl_8055D900 == 1) {
                lbl_8055D900 = 0;
                result |= 8;
            }
            if (result & 1) {
                lbl_8055D8F4 = 0;
                callback(result);
            }
            lbl_8055D8E1 = 0;
        }
    }
    *(unsigned char *)((char *)arg1 + 8) = 0;
    return 0;
}

int doPrepareCoverRegisterCallback(int arg0, void *arg1) {
    int result = arg0;
    int (*callback)(int);

    lbl_8055D8E0 = 0;
    ((unsigned int *)lbl_8037B8A0)[1] = lbl_8037B8C0;
    if (((unsigned int)*(unsigned int *)((char *)arg1 + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(lbl_80302848);
        *(unsigned int *)((char *)arg1 + 0xC) = 0xFEEBDAED;
    } else {
        callback = *(int (**)(int))arg1;
        if (callback != 0) {
            lbl_8055D8E1 = 1;
            if (lbl_8055D900 == 1) {
                lbl_8055D900 = 0;
                result |= 8;
            }
            callback(result);
            lbl_8055D8E1 = 0;
        }
    }
    *(unsigned char *)((char *)arg1 + 8) = 0;
    return 0;
}

int fn_8003B380(int value) {
    lbl_8055D8F0 = value;
    return 1;
}

int fn_8003BB48(void) {
    return ((int *)lbl_8037B8A0)[1];
}

void *fn_8003BCC0(void) { return *(void **)&lbl_8037B8A0; }

unsigned int DVDLowUnmaskStatusInterrupts(void) { return 1; }

unsigned int DVDLowMaskCoverInterrupt(void) { return 1; }

int fn_8003BE40(void) { return 0; }

