// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8037B8A0[32];
extern unsigned int lbl_8055D8F0;
extern unsigned char lbl_8055D8E0;
extern unsigned int lbl_8055D8E4, lbl_8055D8E8;
extern unsigned char *lbl_8055D8FC;
extern unsigned int lbl_80558E18;
extern unsigned char lbl_8037B820[];
extern int IOS_IoctlAsync(int, int, void *, int, void *, int, void (*)(int, void *), void *);
extern unsigned char lbl_8055D8E1;
extern unsigned char lbl_8055D900;
extern int lbl_8055D8F4;
extern unsigned char lbl_8037B8C0[];
extern const char lbl_80302848[];
void OSReport(const char *, ...);
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
void fn_80039F3C(int arg0) { if (lbl_8055D8D0 != 0) { lbl_8055D8D0(arg0 == 0 ? 1 : 2, 0); } }

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

void fn_8003A1A0(int arg0, void (*arg1)(int, int)) {
    long long ticks;
    long long divisor;
    long long quotient;
    unsigned int raw;
    *(int*)(__ErrorInfo + 8) = arg0;
    ticks = (long long)OSGetTime();
    raw = *(unsigned int*)0x800000F8;
    divisor = (long long)(raw >> 2);
    quotient = ticks / divisor;
    *(unsigned int*)(__ErrorInfo + 0xC) = (unsigned int)quotient;
    lbl_8055D8D0 = arg1;
    if (NANDPrivateCreateDirAsync(lbl_80302384, 0x3F, 0, fn_8003A10C, lbl_8037B6D0) != 0 &&
        lbl_8055D8D0 != 0) {
        lbl_8055D8D0(2, 0);
    }
}

#pragma scheduling invalid_target
int DVDCompareDiskID(unsigned char *arg0, unsigned char *arg1) {
    if ((signed char)arg0[0] == 0)
        goto disk_id_suffix;
    if ((signed char)arg1[0] == 0)
        goto disk_id_suffix;
    if (strncmp((char *)arg0, (char *)arg1, 4) == 0)
        goto disk_id_suffix;
    return 0;

disk_id_suffix:
    if ((signed char)arg0[4] != 0 && (signed char)arg1[4] != 0 && strncmp((char *)arg0 + 4, (char *)arg1 + 4, 2) != 0)
        return 0;
    if (arg0[6] != 0xFF && arg1[6] != 0xFF && arg0[6] != arg1[6])
        return 0;
    if (arg0[7] != 0xFF && arg1[7] != 0xFF && arg0[7] != arg1[7])
        return 0;
    return 1;
}
#pragma scheduling invalid_target
void __DVDShowFatalMessage(void) {
    unsigned char color[4];
    int zero = 0;
    int foreground;
    int background;
    const char *message;

    color[0] = lbl_80560B08;
    color[1] = lbl_80560B09;
    color[2] = lbl_80560B0A;
    color[3] = lbl_80560B0B;
    background = zero;
    if (SCGetLanguage() == 0) {
        OSSetFontEncode(1);
    } else {
        OSSetFontEncode(0);
    }
    if (SCGetLanguage() > 6) {
        message = lbl_802EE878[1];
    } else {
        message = lbl_802EE878[SCGetLanguage()];
    }
    foreground = *(int *)color;
    OSFatal(&foreground, &background, message);
}
#pragma scheduling on
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
    ((unsigned int *)lbl_8037B8A0)[1] = *(unsigned int *)&lbl_8037B8C0;
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

int fn_8003A834(void *arg0, void *arg1) {
 const char *msg=lbl_80302848; unsigned int slot=lbl_8055D8E8; unsigned char *entry=lbl_8037B820+slot*0x20; unsigned int index; int result;
 lbl_8055D8E0=1;
 if(entry[8]!=0){OSReport(msg+0x218,slot);OSReport(msg+0x250);for(;;){}}
 if(((unsigned int)*(unsigned int *)(entry+0xC)+0x01150000)!=0xFEEBDAED){OSReport(msg+0x280);for(;;){}}
 *(void **)entry=arg1;*(unsigned int *)(entry+4)=1;entry[8]=1;
 index=slot+1;if(index>=4)index=0;lbl_8055D8E8=index;
 if(arg0==0)OSReport(msg+0x2C0);
 index=lbl_8055D8E4+1;lbl_8055D8E4=index;if(index>=4){index=0;lbl_8055D8E4=0;}
 lbl_8055D8FC[index*0x20]=0x70;
 result=IOS_IoctlAsync(lbl_80558E18,0x70,lbl_8055D8FC+lbl_8055D8E4*0x20,0x20,arg0,0x20,(void (*)(int,void *))doTransactionCallback,entry);
 if(result!=0){OSReport(msg+0x2FC,result);entry[8]=0;return 0;} return 1;
}

extern int IOS_IoctlvAsync(int,int,int,int,void*,void*,void*,void*);
extern int doTransactionCallback(int,void*);
int DVDLowOpenPartition(int arg0,int arg1,int arg2,int arg3,int arg4,int arg5) {
    unsigned int slot, idx; unsigned char *entry; unsigned char *vec; int result;
    if (arg1 && (arg1 & 31)) { OSReport(lbl_80302848+0x338); return 0; }
    if (arg3 && (arg3 & 31)) { OSReport(lbl_80302848+0x370); return 0; }
    if (arg4 && (arg4 & 31)) { OSReport(lbl_80302848+0x370); return 0; }
    slot=lbl_8055D8E8; entry=lbl_8037B820+slot*32; lbl_8055D8E0=1;
    if (entry[8]) { OSReport(lbl_80302848+0x218,slot); OSReport(lbl_80302848+0x250); for(;;){} }
    if (*(unsigned int *)(entry+12)+0x01150000 != 0xFEEBDAED) { OSReport(lbl_80302848+0x280); for(;;){} }
    *(int *)entry=arg5; *(int *)(entry+4)=1; entry[8]=1;
    idx=slot+1; if(idx>=4)idx=0; lbl_8055D8E8=idx;
    idx=lbl_8055D8E4+1; lbl_8055D8E4=idx; if(idx>=4){idx=0;lbl_8055D8E4=0;}
    vec=lbl_8055D8FC+idx*32; vec[0]=0x8B; *(int *)(vec+4)=arg0;
    *(int *)(lbl_8037B820+0xC4)=32; *(void **)(lbl_8037B820+0xC0)=vec;
    *(int *)(lbl_8037B820+0xC8)=arg1; *(int *)(lbl_8037B820+0xCC)=arg1?0x2A4:0;
    *(int *)(lbl_8037B820+0xD0)=arg3; *(int *)(lbl_8037B820+0xD4)=arg3?arg2:0;
    *(int *)(lbl_8037B820+0xD8)=arg4; *(int *)(lbl_8037B820+0xDC)=0x49E4;
    *(void **)(lbl_8037B820+0xE0)=lbl_8037B820+0x100; *(int *)(lbl_8037B820+0xE4)=32;
    result=IOS_IoctlvAsync(lbl_80558E18,0x8B,3,2,lbl_8037B820+0xC0,doTransactionCallback,entry,lbl_8037B820+0xC0);
    if(result){OSReport(lbl_80302848+0x3A8,result);entry[8]=0;return 0;} return 1;
}

extern unsigned int lbl_8055D8E4, lbl_8055D8E8;
extern unsigned char *lbl_8055D8FC;
extern unsigned int lbl_80558E18;
extern unsigned char lbl_8037B820[];
extern int IOS_IoctlAsync(int, int, void *, int, void *, int, void (*)(int, void *), void *);
#pragma scheduling invalid_target
int fn_8003AC24(void *arg0) {
    const char *msg = lbl_80302848;
    int index = lbl_8055D8E4 + 1;
    int slot;
    int offset;
    unsigned char *base;
    unsigned char *entry;
    unsigned int one = 1;
    int result;

    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x8C;
    lbl_8055D8E0 = one;
    base = lbl_8037B820;
    slot = lbl_8055D8E8;
    offset = slot * 0x20;
    entry = base + offset;
    if ((((unsigned int)entry[8] | (0U - (unsigned int)entry[8])) >> 31) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg0;
    slot = slot + 1;
    *(unsigned int *)(entry + 4) = one;
    entry[8] = one;
    lbl_8055D8E8 = slot;
    if (slot >= 4) {
        slot = 0;
        lbl_8055D8E8 = 0;
    }
    result = IOS_IoctlAsync(lbl_80558E18, 0x8C, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x3E8, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling on

int fn_8003AD88(void *arg0, int arg1, int arg2, unsigned int arg3) {
    const char *msg = lbl_80302848;
    int slot = lbl_8055D8E8;
    int offset = slot * 0x20;
    unsigned char *entry = lbl_8037B820 + offset;
    int index;
    int result;

    lbl_8055D8E0 = 1;
    if (entry[8]) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (((unsigned int)*(unsigned int *)(entry + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)lbl_8037B820)[slot * 8] = arg3;
    index = slot + 1;
    *(unsigned int *)(entry + 4) = 1;
    entry[8] = 1;
    lbl_8055D8E8 = index;
    if (index >= 4) lbl_8055D8E8 = 0;
    index = lbl_8055D8E4 + 1;
    lbl_8055D8F4 = arg1;
    lbl_8055D8E4 = index;
    entry = lbl_8037B820 + offset;
    if (index >= 4) lbl_8055D8E4 = 0;
    lbl_8055D8FC[lbl_8055D8E4 * 0x20] = 0x8D;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 4) = arg1;
    *(unsigned int *)(lbl_8055D8FC + lbl_8055D8E4 * 0x20 + 8) = arg2;
    result = IOS_IoctlAsync(lbl_80558E18, 0x8D, lbl_8055D8FC + lbl_8055D8E4 * 0x20,
                            0x20, arg0, arg1, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x428, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}

int fn_8003AF1C(int arg0, int arg1, int arg2) {
 const char *msg=lbl_80302848; unsigned int slot=lbl_8055D8E8; unsigned int offset=slot<<5; unsigned int flag; unsigned char *entry=lbl_8037B820+offset; unsigned int index; unsigned char *request; int result;
 lbl_8055D8E0=1; flag=entry[8];
 if (((flag | -flag)>>31)==1) { OSReport(msg+0x218,slot); OSReport(msg+0x250); for(;;){} }
 if (((unsigned int)*(unsigned int *)(entry+0xC)+0x01150000)!=0xFEEBDAED) { OSReport(msg+0x280); for(;;){} }
 *(unsigned int *)(lbl_8037B820+offset)=arg2;
 index=slot+1; *(unsigned int *)(entry+4)=1; entry[8]=1; lbl_8055D8E8=index;
 if(index>=4)lbl_8055D8E8=0;
 index=lbl_8055D8E4+1; lbl_8055D8E4=index; entry=lbl_8037B820+offset;
 if(index>=4){index=0;lbl_8055D8E4=0;}
 request=lbl_8055D8FC+index*0x20;request[0]=0xE3;*(int *)(request+4)=arg0;*(int *)(request+8)=arg1;
 result=IOS_IoctlAsync(lbl_80558E18,0xE3,request,0x20,lbl_8037B8A0,0x20,(void (*)(int,void *))doTransactionCallback,entry);
 if(result!=0){OSReport(msg+0x468,result);entry[8]=0;return 0;} return 1;
}

int fn_8003B0B0(void *arg0, void *arg1) {
    const char *msg = lbl_80302848;
    int slot = lbl_8055D8E8;
    int index;
    int result;
    int flag;
    unsigned char *entry;
    unsigned char *entry2;
    unsigned char *entry3;
    lbl_8055D8E0 = 1;
    entry = lbl_8037B820 + slot * 0x20;
    flag = entry[8];
    if ((flag & -flag) == 1) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (*(unsigned int *)(entry + 0xC) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    *(void **)entry = arg1;
    slot = slot + 1;
    if (slot < 4) {
        *(unsigned int *)(entry + 4) = 1;
        entry[8] = 1;
        lbl_8055D8E8 = slot;
    } else {
        slot = 0;
        lbl_8055D8E8 = 0;
    }
    entry2 = lbl_8037B820 + slot * 0x20;
    index = lbl_8055D8E4 + 1;
    if (index < 4) {
        lbl_8055D8E4 = index;
    } else {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    entry3 = lbl_8055D8FC + index * 0x20;
    entry3[0] = 0x12;
    result = IOS_IoctlAsync(lbl_80558E18, 0x12, entry3, 0x20, arg0, 0x20, (void (*)(int, void *))doTransactionCallback, entry2);
    if (result != 0) {
        OSReport(msg + 0x4E8, result);
        entry2[8] = 0;
        return 0;
    }
    return 1;
}

#pragma scheduling invalid_target
int fn_8003B218(void *arg0) {
    unsigned int slot = lbl_8055D8E8;
    unsigned char *base = lbl_8037B820;
    const char *msg = lbl_80302848;
    unsigned int offset = slot << 5;
    unsigned int flag;
    unsigned char *p = base + offset;
    unsigned char *entry;
    int next;
    int index;
    int result;

    lbl_8055D8E0 = 1;
    flag = p[8];
    if (((flag | -flag) >> 31) == 1U) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (*(unsigned int *)(p + 0xC) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((void **)base)[slot * 8] = arg0;
    next = (int)slot + 1;
    *(unsigned int *)(p + 4) = 1;
    p[8] = 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        lbl_8055D8E8 = 0;
    }
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    entry = base + offset;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0xE0;
    result = IOS_IoctlAsync(lbl_80558E18, 0xE0, lbl_8055D8FC + index * 0x20, 0x20, lbl_8037B8A0, 0x20, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x520, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling on
int fn_8003B380(int value) {
    lbl_8055D8F0 = value;
    return 1;
}

int fn_8003B38C(void *arg0) {
    const char *msg = lbl_80302848;
    int slot = lbl_8055D8E8;
    unsigned char *entry = lbl_8037B820 + slot * 0x20;
    int index;
    int result;
    lbl_8055D8E0 = 1;
    if ((entry[8] & -entry[8]) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (((unsigned int)*(unsigned int *)(entry + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    *(void **)entry = arg0;
    slot = slot + 1;
    *(unsigned int *)(entry + 4) = 1;
    entry[8] = 1;
    lbl_8055D8E8 = slot;
    if (slot >= 4) slot = 0;
    index = lbl_8055D8E4 + 1;
    lbl_8055D8E4 = index;
    if (index >= 4) index = 0;
    entry = lbl_8037B820 + slot * 0x20;
    lbl_8055D8FC[index * 0x20] = 0x8A;
    result = IOS_IoctlAsync(lbl_80558E18, 0x8A, lbl_8055D8FC + index * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x5E0, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}

int fn_8003B508(int arg0, int arg1, int arg2) {
 const char *msg=lbl_80302848; unsigned int slot=lbl_8055D8E8; unsigned int offset=slot<<5; unsigned int flag; unsigned char *entry=lbl_8037B820+offset; unsigned int index; unsigned char *request; int result;
 lbl_8055D8E0=1; flag=entry[8];
 if (((flag | -flag)>>31)==1) { OSReport(msg+0x218,slot); OSReport(msg+0x250); for(;;){} }
 if (((unsigned int)*(unsigned int *)(entry+0xC)+0x01150000)!=0xFEEBDAED) { OSReport(msg+0x280); for(;;){} }
 *(unsigned int *)(lbl_8037B820+offset)=arg2;
 index=slot+1; *(unsigned int *)(entry+4)=1; entry[8]=1; lbl_8055D8E8=index;
 if(index>=4)lbl_8055D8E8=0;
 index=lbl_8055D8E4+1; lbl_8055D8E4=index; entry=lbl_8037B820+offset;
 if(index>=4){index=0;lbl_8055D8E4=0;}
 request=lbl_8055D8FC+index*0x20;request[0]=0xE4;*(int *)(request+4)=arg0;*(int *)(request+8)=arg1;
 result=IOS_IoctlAsync(lbl_80558E18,0xE4,request,0x20,lbl_8037B8A0,0x20,(void (*)(int,void *))doTransactionCallback,entry);
 if(result!=0){OSReport(msg+0x618,result);entry[8]=0;return 0;} return 1;
}

int fn_8003B69C(int arg0, void *arg1) {
    const char *msg = lbl_80302848;
    unsigned char *base = lbl_8037B820;
    int slot = lbl_8055D8E8;
    unsigned char *entry;
    int index;
    int result;
    lbl_8055D8E0 = 1;
    entry = base + slot * 0x20;
    if ((entry[8] & -entry[8]) == 1) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (((unsigned int)*(unsigned int *)(entry + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    *(void **)entry = arg1;
    slot = slot + 1;
    if (slot < 4) {
        *(unsigned int *)(entry + 4) = 1;
        entry[8] = 1;
        lbl_8055D8E8 = slot;
    } else {
        slot = 0;
        lbl_8055D8E8 = 0;
    }
    entry = base + slot * 0x20;
    index = lbl_8055D8E4 + 1;
    if (index < 4) {
        lbl_8055D8E4 = index;
    } else {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0xDD;
    *(unsigned int *)(lbl_8055D8FC + index * 0x20 + 4) = (arg0 >> 16) & 3;
    result = IOS_IoctlAsync(lbl_80558E18, 0xDD, lbl_8055D8FC + index * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0x9CC, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}

int fn_8003B81C(void *arg0, int arg1, int arg2, int arg3) {
 const char *msg=lbl_80302848; unsigned int slot; unsigned int offset; unsigned int flag; unsigned char *entry; unsigned int index; unsigned char *request; int result;
 if((unsigned int)arg0&0x1F){OSReport(msg+0xA0C);return 0;}
 slot=lbl_8055D8E8;offset=slot<<5;entry=lbl_8037B820+offset;lbl_8055D8E0=1;flag=entry[8];
 if(((flag|-flag)>>31)==1){OSReport(msg+0x218,slot);OSReport(msg+0x250);for(;;){}}
 if(((unsigned int)*(unsigned int *)(entry+0xC)+0x01150000)!=0xFEEBDAED){OSReport(msg+0x280);for(;;){}}
 *(unsigned int *)(lbl_8037B820+offset)=arg3;index=slot+1;*(unsigned int *)(entry+4)=1;entry[8]=1;lbl_8055D8E8=index;if(index>=4)lbl_8055D8E8=0;
 lbl_8055D8F4=arg1;index=lbl_8055D8E4+1;lbl_8055D8E4=index;entry=lbl_8037B820+offset;if(index>=4){index=0;lbl_8055D8E4=0;}
 request=lbl_8055D8FC+index*0x20;request[0]=0x71;*(int *)(request+4)=arg1;*(int *)(request+8)=arg2;
 result=IOS_IoctlAsync(lbl_80558E18,0x71,request,0x20,arg0,arg1,(void (*)(int,void *))doTransactionCallback,entry);
 if(result!=0){OSReport(msg+0xA4C,result);entry[8]=0;return 0;}return 1;
}

int fn_8003B9CC(void *arg0, void *arg1) {
    const char *msg = lbl_80302848;
    int slot = lbl_8055D8E8;
    int index;
    unsigned char *entry;
    int result;
    lbl_8055D8E0 = 1;
    entry = lbl_8037B820 + slot * 0x20;
    if ((entry[8] & -entry[8]) == 1) {
        OSReport(msg + 0x218, slot);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (((unsigned int)*(unsigned int *)(entry + 0xC) + 0x01150000) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    *(void **)entry = arg1;
    slot = slot + 1;
    if (slot < 4) {
        *(unsigned int *)(entry + 4) = 1;
        entry[8] = 1;
        lbl_8055D8E8 = slot;
    } else {
        slot = 0;
        lbl_8055D8E8 = 0;
    }
    index = lbl_8055D8E4 + 1;
    if (index < 4) {
        lbl_8055D8E4 = index;
    } else {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    entry = lbl_8037B820 + slot * 0x20;
    lbl_8055D8FC[index * 0x20] = 0xAB;
    result = IOS_IoctlAsync(lbl_80558E18, 0xAB, lbl_8055D8FC + index * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0xA80, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}

int fn_8003BB48(void) {
    return ((int *)lbl_8037B8A0)[1];
}

int fn_8003BB58(void *arg0) {
    const char *msg = lbl_80302848;
    int index = lbl_8055D8E4 + 1;
    unsigned char *base;
    int slot;
    unsigned char *entry;
    unsigned char *callbackEntry;
    unsigned char busy;
    unsigned int one = 1;
    int next;
    int result;

    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x7A;
    lbl_8055D8E0 = one;
    base = lbl_8037B820;
    slot = lbl_8055D8E8;
    entry = base + slot * 0x20;
    busy = entry[8];
    if (((busy | (0U - busy)) >> 31) == 1) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if ((*(unsigned int *)(entry + 0xC) + 0x01150000U) != 0xDAEDU) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    ((unsigned int *)base)[slot * 8] = (unsigned int)arg0;
    *(unsigned int *)(entry + 4) = one;
    entry[8] = one;
    next = slot + 1;
    lbl_8055D8E8 = next;
    if (next >= 4) {
        next = 0;
        lbl_8055D8E8 = 0;
    }
    callbackEntry = base + slot * 0x20;
    result = IOS_IoctlAsync(lbl_80558E18, 0x7A,
        lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20,
        &lbl_8037B8C0, 0x20,
        (void (*)(int, void *))doPrepareCoverRegisterCallback,
        callbackEntry);
    if (result != 0) {
        OSReport(msg + 0xB30, result);
        callbackEntry[8] = 0;
        return 0;
    }
    return 1;
}

void *fn_8003BCC0(void) { return *(void **)&lbl_8037B8A0; }

unsigned int DVDLowUnmaskStatusInterrupts(void) { return 1; }

unsigned int DVDLowMaskCoverInterrupt(void) { return 1; }

#pragma scheduling invalid_target
int fn_8003BCDC(void *arg0) {
    const char *msg = lbl_80302848;
    int index = lbl_8055D8E4 + 1;
    int slot;
    unsigned int flag;
    unsigned char *p;
    unsigned char *entry;
    int result;

    lbl_8055D8E4 = index;
    if (index >= 4) {
        index = 0;
        lbl_8055D8E4 = 0;
    }
    lbl_8055D8FC[index * 0x20] = 0x86;
    lbl_8055D8E0 = 1;
    slot = lbl_8055D8E8;
    p = lbl_8037B820 + slot * 0x20;
    flag = p[8];
    if (((flag | -flag) >> 31) == 1U) {
        OSReport(msg + 0x218);
        OSReport(msg + 0x250);
        for (;;) {}
    }
    if (*(unsigned int *)(p + 0xC) != 0xFEEBDAED) {
        OSReport(msg + 0x280);
        for (;;) {}
    }
    *(void **)&lbl_8037B820[slot * 0x20] = arg0;
    index = slot + 1;
    *(unsigned int *)(p + 4) = 1;
    p[8] = 1;
    lbl_8055D8E8 = index;
    if (index >= 4) {
        lbl_8055D8E8 = 0;
    }
    entry = lbl_8037B820 + slot * 0x20;
    result = IOS_IoctlAsync(lbl_80558E18, 0x86, lbl_8055D8FC + lbl_8055D8E4 * 0x20, 0x20, 0, 0, (void (*)(int, void *))doTransactionCallback, entry);
    if (result != 0) {
        OSReport(msg + 0xB74, result);
        entry[8] = 0;
        return 0;
    }
    return 1;
}
#pragma scheduling reset
int fn_8003BE40(void) { return 0; }

