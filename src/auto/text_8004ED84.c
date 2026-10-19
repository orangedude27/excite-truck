// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned short lbl_80558F58;
extern void *lbl_8055DA48;
extern char *ParseStringS(int, char *, int **, int *);
extern void ParseStringW(void);
extern int IOS_IoctlvReboot(int, int, int, int, void *, int);
int _ES_LaunchTitle(int *fd, int arg1, int arg2, int arg3, void *arg4, int *arg5, int arg6) {
    unsigned char work[0x140] __attribute__((aligned(32)));
    void *vec[2];
    int lens[2];
    if (*fd < 0) return -0x3F9;
    if ((arg3 & 31) != 0) return -0x3F9;
    vec[0] = work;
    vec[1] = (void *)arg3;
    lens[0] = 8;
    lens[1] = 0xD8;
    return IOS_IoctlvReboot(*fd, 8, 2, 0, vec, 8);
}

extern int VIGetTvFormat(short, short);
extern int VIConfigure(void *);
extern int VIConfigurePan(int, int, int, int);
void ConfigureVideo(short arg0, short arg1) {
    struct VideoConfig { int mode; short a,b,c,d,e,f,g; int last; volatile int padding[12]; } config;
    int format;
    config.a=arg0; config.b=0x1E0; config.c=arg1;
    config.g=arg1; config.f=0x280; config.d=0x28;
    format=VIGetTvFormat(arg0,arg1);
    switch(format) {
    case 0: case 2:
        if (*(volatile unsigned short *)0xCC00206C & 1) {
            config.mode=2; config.e=0; config.last=0;
        } else { config.mode=0; config.e=0; config.last=1; }
        break;
    case 5: config.mode=0x14; config.e=0; config.last=1; break;
    case 1: config.mode=4; config.e=0x2F; config.last=1; break;
    }
    VIConfigure(&config);
    VIConfigurePan(0,0,0x280,0x1E0);
}

void Decode(unsigned char *src, unsigned char *dst) {
    unsigned char *out = dst;
    unsigned char *literal = src + *(unsigned int *)(src + 0xC);
    unsigned char *cmd = src + 0x10;
    unsigned int outputSize = *(unsigned int *)(src + 4);
    unsigned int in = *(unsigned int *)(src + 8);
    unsigned int bits = 0;
    int count = 0;

    while ((unsigned int)(out - dst) < outputSize) {
        if (count == 0) {
            bits = *(unsigned int *)cmd;
            cmd += 4;
            count = 32;
        }
        if ((bits & 0x80000000) != 0) {
            *out++ = *literal++;
        } else {
            unsigned char a = src[in++];
            unsigned char b = src[in++];
            unsigned int pair = (a << 8) | b;
            int length = pair >> 12;
            int distance = pair & 0xFFF;
            unsigned char extra;
            int i;
            if (length == 0) {
                extra = *literal++;
                length = extra + 0x12;
            } else {
                length += 2;
            }
            for (i = 0; i < length; ++i)
                out[i] = out[i - distance];
            out += length;
        }
        bits <<= 1;
        --count;
    }
}

extern int IOS_IoctlvReboot(int,int,int,int,void*,int);
unsigned short OSGetFontEncode(void) {
 unsigned short x=lbl_80558F58; int v;
 if (x==(unsigned short)-1) { v=*(volatile int*)0x800000CC; if(v==0) { x=(*(volatile unsigned short*)0xCC00206E>>1)&1; lbl_80558F58=x; } else if(v<0) { x=0; lbl_80558F58=x; } else { x=0; lbl_80558F58=x; } lbl_8055DA48=ParseStringS; }
 return x;
}

unsigned short OSSetFontEncode(unsigned short arg0) {
    unsigned short encode = lbl_80558F58;
    if (encode == 0xFFFF) {
        if (*(int *)0x800000CC == 0) {
            encode = (*(unsigned short *)0xCC00206E >> 1) & 1;
        } else {
            encode = 0;
        }
        lbl_80558F58 = encode;
        lbl_8055DA48 = (void *)ParseStringS;
    }
    if (arg0 <= 5) {
        if (arg0 >= 3) {
            lbl_80558F58 = arg0;
            if (arg0 <= 5) {
                lbl_8055DA48 = (void *)ParseStringW;
            }
        }
    }
    return encode;
}

extern int GetFontCode(unsigned short);
extern int *lbl_8055DA50;
extern int *lbl_8055DA54;
char *ParseStringS(int format, char *text, int **outWidths, int *outCode) {
    int valid;
    unsigned short first;
    int *widths;
    char *next;
    unsigned char second;
    next = text;
    first = 0;
    widths = outCode;
    switch (format) {
    case 0:
        first = *(unsigned char *)text;
        widths = lbl_8055DA54;
        if (first != 0) next = text + 1;
        break;
    case 1:
        first = *(unsigned char *)text;
        widths = lbl_8055DA50;
        if (first != 0) {
            next = text + 1;
            valid = 0;
            if (first >= 0x81) {
                if (first <= 0x9F) valid = 1;
                else if (first >= 0xE0 && first <= 0xFC) valid = 1;
            }
            if (valid != 0) {
                second = *(unsigned char *)next;
                valid = 0;
                if (second >= 0x40 && second <= 0xFC && second != 0x7F) valid = 1;
                if (valid != 0) {
                    first = (first << 8) | second;
                    next++;
                }
            }
        }
        break;
    }
    *outWidths = widths;
    *outCode = GetFontCode(first);
    return next;
}

void OSGetFontWidth(int ch,int *out) {
 void *p; int n; unsigned short e=lbl_80558F58; int v;
 if(e==(unsigned short)-1) { v=*(volatile int*)0x800000CC; if(v==0) {e=(*(volatile unsigned short*)0xCC00206E>>1)&1;lbl_80558F58=e;} else if(v<0){e=0;lbl_80558F58=e;}else{e=0;lbl_80558F58=e;} lbl_8055DA48=ParseStringS; }
 ((int(*)(unsigned short,int,void**,int*))lbl_8055DA48)(e,ch,&p,&n);
 if(out) *out=(unsigned char)*((char*)p+*(unsigned short*)((char*)p+0x22)+n);
}
extern void OSDisableInterrupts(void);
extern void OSDisableScheduler(void);
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);
extern void __OSStopAudioSystem(void);
extern void fn_8005954C(void);
extern void __OSUnmaskInterrupts(int);
extern void VISetBlack(int);
extern void VIFlush(void);
extern void fn_800591AC(int);
extern void AIRegisterDMACallback_800591F0(void *);
extern void OSEnableInterrupts(void);
extern int fn_8005AC08(void);
extern unsigned long long OSGetTime(void);
extern int __OSCallShutdownFunctions(int,int);
extern void EXISetExiCallback(int,void *);
extern int EXILock(int,int,void *);
extern void EXISync(int);
extern void EXIDeselect(int);
extern void EXIUnlock(int);
extern void __OSSetExceptionHandler(int,void *);
extern void GXGetVtxAttrFmtv(void);
extern void OSSetArenaLo(void *);
extern void OSSetArenaHi(void *);
extern void *OSGetArenaHi(void);
extern void OSSwitchFiber(void *,void *,void *);
extern char Halt, OSDefaultExceptionHandler, lbl_8038E060, lbl_8038E328;
