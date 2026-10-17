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
    struct VideoConfig { int mode; short a,b,c,d,e,f,g; int last; } config;
    volatile int padding[8];
    int format;
    padding[0] = 0;
    config.a=arg0; config.b=0x1E0; config.c=arg1;
    config.d=0x28; config.f=0x280; config.g=arg1;
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

void OSGetFontWidth(int ch,int *out) {
 void *p; int n; unsigned short e=lbl_80558F58; int v;
 if(e==(unsigned short)-1) { v=*(volatile int*)0x800000CC; if(v==0) {e=(*(volatile unsigned short*)0xCC00206E>>1)&1;lbl_80558F58=e;} else if(v<0){e=0;lbl_80558F58=e;}else{e=0;lbl_80558F58=e;} lbl_8055DA48=ParseStringS; }
 ((int(*)(unsigned short,int,void**,int*))lbl_8055DA48)(e,ch,&p,&n);
 if(out) *out=(unsigned char)*((char*)p+*(unsigned short*)((char*)p+0x22)+n);
}

