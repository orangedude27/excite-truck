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
extern void fn_8003A10C(int);
extern char lbl_8037B6D0[];
extern int NANDPrivateCreateDirAsync(const char *, int, int, void (*)(int), void *);
extern void (*lbl_8055D8D0)(int, int);
extern int NANDCloseAsync(void *, void *, void *);
extern int NANDWriteAsync(void *, void *, int, void *, void *);
extern int NANDPrivateOpenAsync(const char *, void *, int, void *, void *);
extern char lbl_8037B640[], lbl_80302368[];
extern void fn_80039F3C(int);
extern void fn_80039F68(int);
extern void fn_80039FC4(int);
void fn_80039F3C(int arg0) { if (lbl_8055D8D0 != 0) { int v = __cntlzw(arg0) & 0x20; lbl_8055D8D0(2 - (v >> 5), 0); } }

void fn_80039F68(int arg0) { if (NANDCloseAsync(lbl_8037B640, fn_80039F3C, lbl_8037B6D0) != 0 && lbl_8055D8D0 != 0) lbl_8055D8D0(2, 0); }

void fn_80039FC4(int arg0) {
 char *base = lbl_8037B640;
 if (arg0 == 0) {
  if (NANDWriteAsync(base, base+0x160, 0x80, fn_80039F68, base+0x90) != 0 &&
      NANDCloseAsync(base, fn_80039F3C, base+0x90) != 0 && lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
 } else if (lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
}

void fn_8003A074(int arg0) {
 if (arg0 == 0 || arg0 == -6) {
  if (NANDPrivateOpenAsync(lbl_80302368,lbl_8037B640,2,fn_80039FC4,lbl_8037B6D0) != 0 && lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
 } else if (lbl_8055D8D0 != 0) lbl_8055D8D0(2,0);
}

extern int NANDPrivateCreateAsync(const char *, int, void *, void *, void *);
extern char lbl_80302368[];
extern void fn_8003A074(int);
void fn_8003A10C(int arg0) {
    if (arg0 == 0 || arg0 == -6) {
        if (NANDPrivateCreateAsync(lbl_80302368, 0x3F, 0, fn_8003A074, lbl_8037B6D0) != 0 &&
            lbl_8055D8D0 != 0) {
            lbl_8055D8D0(2, 0);
        }
    } else if (lbl_8055D8D0 != 0) {
        lbl_8055D8D0(2, 0);
    }
}

void __DVDShowFatalMessage(void) {
 unsigned char bg[4]={0,0,0,0}; unsigned char fg[4]={255,255,255,0}; const char *msg;
 if(SCGetLanguage()==0) OSSetFontEncode(1); else OSSetFontEncode(0);
 msg=(SCGetLanguage()>6)?lbl_802EE878[1]:lbl_802EE878[SCGetLanguage()];
 OSFatal(fg,bg,msg);
}

extern void __DVDShowFatalMessage(void);
extern void (*lbl_8055D8D0)(int, int);
int DVDSetAutoFatalMessaging(int enable) {
 int old; OSDisableInterrupts(); old=FatalFunc_8055D8D8 != 0;
 if(enable) FatalFunc_8055D8D8=__DVDShowFatalMessage; else FatalFunc_8055D8D8=0;
 OSRestoreInterrupts(); return old;
}

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

