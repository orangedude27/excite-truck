#include "revolution/GX/GXTypes.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned short lbl_80558F58;
extern void *lbl_8055DA48;
extern int *lbl_8055DA50;
extern int *lbl_8055DA54;
extern unsigned short lbl_803049F0[];
extern unsigned short lbl_80304B70[];
extern int ReadFont(int, int, int);
extern char *ParseStringS(int, char *, int **, int *);
extern void *ParseStringW(int, void *, int *, int *, int);
extern int IOS_IoctlvReboot(int, int, int, int, void *, int);
int IOS_Ioctlv(int, int, int, int, void *, int);
int _ES_GetTicketViews(int *fd, int unused, int inputA, int inputB, unsigned int size, int *outCount) {
    struct Frame {
        int vec[6];
        char pad0[8];
        int args[2];
        char pad1[0x18];
        int output;
        char pad2[0x9C];
    } __attribute__((aligned(32))) frame;
    int result;

    if (*fd < 0) return -0x3F9;
    if (outCount == 0) return -0x3F9;
    if (size & 0x1F) return -0x3F9;

    frame.args[0] = inputA;
    frame.args[1] = inputB;
    if (size == 0) {
        frame.vec[0] = (int)&frame.args[0];
        frame.vec[1] = 8;
        frame.vec[2] = (int)&frame.output;
        frame.vec[3] = 4;
        result = ((int (*)(int, int, int, int, void *))IOS_Ioctlv)(*fd, 0x12, 1, 1, &frame.vec[0]);
        if (result == 0) *outCount = frame.output;
        return result;
    }

    if (*outCount == 0) return -0x3F9;
    frame.vec[0] = (int)&frame.args[0];
    frame.vec[1] = 8;
    frame.vec[2] = (int)&frame.output;
    frame.vec[3] = 4;
    frame.vec[4] = size;
    frame.output = *outCount;
    frame.vec[5] = *outCount * 0xD8;
    return ((int (*)(int, int, int, int, void *))IOS_Ioctlv)(*fd, 0x13, 2, 1, &frame.vec[0]);
}

int _ES_LaunchTitle(int *fd, int unused, int tidHigh, int tidLow, void *views)
{
    struct Vector {
        void *base;
        unsigned int length;
    } vectors[2];
    unsigned char work[0x100] __attribute__((aligned(32)));
    struct Vector *pVectors = vectors;
    unsigned int *pTid = (unsigned int *)work;

    if (*fd < 0)
        return -0x3F9;
    if (((unsigned int)views & 31) != 0)
        return -0x3F9;

    {
        int eight = 8;
        pTid[1] = tidLow;
        pTid[0] = tidHigh;
        pVectors[0].base = pTid;
        pVectors[0].length = eight;
        pVectors[1].base = views;
        pVectors[1].length = 0xD8;
        return IOS_IoctlvReboot(*fd, eight, 2, 0, pVectors, eight);
    }
}

extern void OSGetFontTexel(char *, unsigned char *, int, int, int *);
#pragma push
#pragma use_lmw_stmw off
void ScreenReport(void* fb, u16 width, u16 height, GXColor msgYUV, s32 x,
                  s32 y, u32 lf, const char* msg) {
    u32 texel[70];
    u32 charWidth;
    u8* tmp;
    u8 bright;
    s32 xPos;
    u32 idx;
    u32 idx2;
    u32 idx3;
    u32 i;
    u32 j;
new_line:
    if (height - 24 < y) return;
    tmp = (u8*)fb + ((x + (y * width)) * 2);
    xPos = x;
    while (*msg != '\0') {
        if (*msg == '\n') {
            msg++;
            y += lf;
            goto new_line;
        } else if (width - 48 < xPos) {
            y += lf;
            goto new_line;
        }
        for (i = 0; i < 24; i++) {
            idx = (i & 7) + ((i / 8) * 24);
            texel[idx] = 0;
            texel[idx + 8] = 0;
            texel[idx + 16] = 0;
        }
        msg = ((const char *(*)(const char *, u32 *, s32, s32, u32 *))OSGetFontTexel)(
            msg, texel, 0, 6, &charWidth);
        for (i = 0; i < 24; i++) {
            idx = (i & 7) + ((i / 8) * 24);
            for (j = 0; j < 24; j++) {
                idx2 = idx + ((j / 8) * 8);
                bright = (texel[idx2] >> ((7 - (j & 7)) * 4)) & 0x0F;
                if (bright != 0) {
                    bright = (((msgYUV.r * (bright * 0xEF)) / 255) / 15) + 16;
                    idx3 = (j + (width * i));
                    tmp[idx3 * 2] = bright;
                    if ((xPos + j) % 2 != 0) {
                        tmp[(idx3 * 2) - 1] = msgYUV.g;
                        tmp[(idx3 * 2) + 1] = msgYUV.b;
                    } else {
                        tmp[(idx3 * 2) - 1] = msgYUV.b;
                        tmp[(idx3 * 2) + 1] = msgYUV.g;
                    }
                }
            }
        }
        tmp += charWidth * 2;
        xPos += charWidth;
    }
}
#pragma pop
extern int VIGetTvFormat(short, short);
extern int VIConfigure(void *);
extern int VIConfigurePan(int, int, int, int);
void ConfigureVideo(short arg0, short arg1) {
    struct VideoConfig { int mode; volatile short a,b,c,d,e,f,g; int last; volatile int padding[12]; } config;
    int format;
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

unsigned short GetFontCode(unsigned int mode, unsigned short code) {
    unsigned int lead;
    unsigned int trail;
    unsigned int base;
    unsigned int valid;
    if (mode == 1) {
        if (code >= 0x20 && code <= 0xDF)
            return lbl_803049F0[code - 0x20];
        if (code > 0x889E && code <= 0x9872) {
            lead = (code >> 8) - 0x88;
            base = lead * 0xBC;
            trail = code & 0xFF;
            valid = 0;
            if (trail >= 0x40) {
                if (trail <= 0xFC) {
                    if (trail != 0x7F)
                        valid = 1;
                }
            }
            if (valid == 0) return 0;
            trail -= 0x40;
            if (trail >= 0x40) trail -= 1;
            return base + trail + 0x2BE;
        }
        if (code >= 0x8140 && code < 0x879E) {
            lead = (code >> 8) - 0x81;
            base = lead * 0xBC;
            trail = code & 0xFF;
            valid = 0;
            if (trail >= 0x40) {
                if (trail <= 0xFC) {
                    if (trail != 0x7F)
                        valid = 1;
                }
            }
            if (valid == 0) return 0;
            trail -= 0x40;
            if (trail >= 0x40) trail -= 1;
            return lbl_80304B70[base + trail];
        }
        return 0;
    }
    if (code > 0x20 && code <= 0xFF)
        return code - 0x20;
    return 0;
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
#pragma opt_propagation off
unsigned short OSGetFontEncode(void) {
    if (lbl_80558F58 != 0xFFFF) {
        return lbl_80558F58;
    }

    switch (*(int *)0x800000CC) {
    case 0:
        lbl_80558F58 = (*(volatile unsigned short *)0xCC00206E >> 1) & 1;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    default:
        lbl_80558F58 = 0;
        break;
    }

    lbl_8055DA48 = (void *)ParseStringS;
    return lbl_80558F58;
}
#pragma opt_propagation reset
unsigned short OSSetFontEncode(unsigned short arg0) {
    u16 old = OSGetFontEncode();

    if (arg0 <= 5) {
        lbl_80558F58 = arg0;
        if (arg0 >= 3 && arg0 <= 5) {
            lbl_8055DA48 = (void *)ParseStringW;
        }
    }

    return old;
}

int OSLoadFont(int arg0, int arg1) {
    int result;

    switch (OSGetFontEncode()) {
    case 0:
        lbl_8055DA54 = (int *)arg0;
        result = ReadFont(arg1, 0, arg0);
        break;
    case 1:
        lbl_8055DA50 = (int *)arg0;
        result = ReadFont(arg1, 1, arg0);
        break;
    case 3:
    case 4:
    case 5:
        lbl_8055DA54 = (int *)arg0;
        result = ReadFont(arg1, 0, arg0);
        if (result != 0) {
            lbl_8055DA50 = (int *)((char *)lbl_8055DA54 + result);
            result += ReadFont(arg1, 1, (int)lbl_8055DA50);
        }
        break;
    case 2:
    default:
        result = 0;
        break;
    }
    return result;
}

extern unsigned short lbl_803049F0[];
extern unsigned short lbl_80304B70[];
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
    *outCode = GetFontCode(format, first);
    return next;
}

extern void *OSUTF8to32(void *, int *);
extern void *OSUTF16to32(void *, int *);
extern int OSUTF32toANSI(void);
extern unsigned short OSUTF32toSJIS(int);
extern int lbl_8055DA4C;
void *ParseStringW(int format, void *input, int *outFont, int *outCode, int unused) {
    int code=0, mode=format;
    unsigned short ch=0;
    void *next=input;
    switch(format) {
    case 0: ch=*(unsigned char*)input; mode=(int)lbl_8055DA54; if(ch) next=(char*)input+1; break;
    case 1:
        ch=*(unsigned char*)input; mode=(int)lbl_8055DA50;
        if(ch) { next=(char*)input+1;
            if((ch>=0x81&&ch<=0x9f)||(ch>=0xe0&&ch<=0xfc)) {
                unsigned char trail=*(unsigned char*)next;
                if(trail>=0x40&&trail<=0xfc&&trail!=0x7f) { ch=(ch<<8)|trail; next=(char*)next+1; }
            }
        } break;
    case 3: next=OSUTF8to32(input,&code); break;
    case 4: next=OSUTF16to32(input,&code); break;
    case 5: code=*(int*)input; if(code) next=(char*)input+4; break;
    }
    if(code) {
        mode=(int)lbl_8055DA54;
        if(!((int(*)(int))OSUTF32toANSI)(code) && lbl_8055DA4C && (unsigned int)code<=0x7f) {
            ch=OSUTF32toSJIS(code);
            if(ch) mode=(int)lbl_8055DA50;
        }
    }
    *outFont=mode; *outCode=GetFontCode(mode,ch); return next;
}

void OSGetFontTexel(char *arg0, unsigned char *arg1, int arg2, int arg3, int *arg4) {
    void *spC;
    int sp8;
    unsigned short mode = lbl_80558F58;
    unsigned int a, b, c, d;
    int x, y;
    unsigned char *pixels;
    unsigned char *table;
    int i, j;
    if (mode == 0xFFFF) {
        int console = *(volatile int *)0x800000CC;
        if (console == 0) {
            mode = (*(volatile unsigned short *)0xCC00206E >> 1) & 1;
            lbl_80558F58 = mode;
        } else {
            mode = 0;
            lbl_80558F58 = 0;
        }
        lbl_8055DA48 = ParseStringS;
    }
    ((char *(*)(int, char *, int **, int *))lbl_8055DA48)(mode, arg0, (int **)&spC, &sp8);
    a = *(unsigned short *)((char *)spC + 0x1A);
    b = *(unsigned short *)((char *)spC + 0x1C);
    pixels = (unsigned char *)spC + *(int *)((char *)spC + 0x24);
    table = (unsigned char *)spC + 0x2C;
    x = sp8;
    y = arg3;
    for (i = 0; i < *(unsigned short *)((char *)spC + 0x12); i++) {
        for (j = 0; j < *(unsigned short *)((char *)spC + 0x10); j++) {
            unsigned int index = (unsigned int)(j + arg2);
            unsigned int outIndex = (unsigned int)(i + arg3);
            unsigned char *out = arg1 + ((outIndex >> 3) * (*(unsigned short *)((char *)spC + 0x12) * 4)) + ((index >> 3) * 32) + ((outIndex & 7) * 4);
            unsigned int src = (unsigned int)(x * *(unsigned short *)((char *)spC + 0x10) + j);
            unsigned char v = pixels[src] & 0xF;
            *out = (*out & 0xF0) | v;
        }
    }
    if (arg4 != 0)
        *arg4 = *(unsigned char *)((char *)spC + *(unsigned short *)((char *)spC + 0x22) + sp8);
}

extern void DCStoreRange(void *, unsigned int);
int ExpandFontSheet(void *arg0, void *src0, void *dst0) {
    unsigned char *src = src0, *dst = dst0;
    unsigned char *table = (unsigned char *)arg0 + 0x2C;
    int format = *(unsigned short *)((char *)arg0 + 0x18);
    int size = *(int *)((char *)arg0 + 0x28);
    if (format == 0) {
        int count = (size + (size >> 31)) >> 1;
        int i;
        for (i = 0; i < count; i++) {
            unsigned char x = src[count - i - 1];
            dst[(count - i - 1) * 2] = table[(x >> 6) & 3];
            dst[(count - i - 1) * 2 + 1] = table[(x >> 4) & 3];
            dst[(count - i - 1) * 2 - 2] = table[(x >> 2) & 3];
            dst[(count - i - 1) * 2 - 1] = table[x & 3];
        }
    } else if (format == 2) {
        int count = size / 4;
        int i;
        for (i = 0; i < count; i++) {
            unsigned char x = src[count - i - 1];
            int j;
            for (j = 0; j < 4; j++)
                dst[(count - i - 1) * 4 + j] = table[(x >> (6 - 2 * j)) & 3];
        }
    }
    DCStoreRange(dst, size);
    return size;
}

extern int ExpandFontSheet(void *, void *, void *);
int OSInitFont(void *arg0) {
    unsigned short mode=lbl_80558F58;
    int result;
    int size, aligned;
    void *font, *cursor;
    if(mode==(unsigned short)-1) {
        int console=*(volatile int*)0x800000CC;
        if(console==0) mode=(*(volatile unsigned short*)0xCC00206E>>1)&1;
        else mode=0;
        lbl_80558F58=mode;
        lbl_8055DA48=(void*)ParseStringS;
    }
    if(mode==2) return 1;
    if(mode==0) {
        lbl_8055DA54=arg0;
        font=(char*)arg0+0x1D120;
        result=ReadFont((int)font,0,(int)arg0);
        if(!result)return 0;
        size=*(int*)((char*)arg0+0x24);
        aligned=(size+0x1f)&~0x1f;
        *(int*)((char*)arg0+0x24)=aligned;
        ExpandFontSheet(arg0,(char*)arg0+size,(char*)arg0+aligned);
    } else if(mode==1) {
        lbl_8055DA50=arg0;
        font=(char*)arg0+0xD3F00;
        result=ReadFont((int)font,1,(int)arg0);
        if(!result)return 0;
        size=*(int*)((char*)arg0+0x24);
        aligned=(size+0x1f)&~0x1f;
        *(int*)((char*)arg0+0x24)=aligned;
        ExpandFontSheet(arg0,(char*)arg0+size,(char*)arg0+aligned);
    } else if(mode<6) {
        lbl_8055DA54=arg0;
        font=(char*)arg0+0xF4020;
        result=ReadFont((int)font,0,(int)arg0);
        if(!result)return 0;
        size=*(int*)((char*)arg0+0x24);
        aligned=(size+0x1f)&~0x1f;
        *(int*)((char*)arg0+0x24)=aligned;
        ExpandFontSheet(arg0,(char*)arg0+size,(char*)arg0+aligned);
        cursor=(char*)arg0+0x20120;
        lbl_8055DA50=cursor;
        result=ReadFont((int)font,1,(int)cursor);
        if(!result)return 0;
        size=*(int*)((char*)cursor+0x24);
        aligned=(size+0x1f)&~0x1f;
        *(int*)((char*)cursor+0x24)=aligned;
        ExpandFontSheet(cursor,(char*)cursor+size,(char*)cursor+aligned);
    } else return 1;
    return 1;
}

void OSGetFontTexture(int arg0, void **arg1, int *arg2, int *arg3, int *arg4) {
    unsigned short encode;
    int console;
    void *texture;
    int index;
    int tile;
    int remainder;
    int column;
    int row;
    char *(*parse)(int, char *, int **, int *);
    encode = lbl_80558F58;
    if (encode == 0xFFFF)
        goto initialize;
    goto ready;
initialize:
    console = *(volatile int *)0x800000CC;
    if (console != 0) {
        if (console < 0)
            goto zero;
        goto zero;
    }
    encode = (*(volatile unsigned short *)0xCC00206E >> 1) & 1;
    lbl_80558F58 = encode;
    goto store_parser;
zero:
    encode = 0;
    lbl_80558F58 = encode;
store_parser:
    lbl_8055DA48 = (void *)ParseStringS;
ready:
    parse = (char *(*)(int, char *, int **, int *))lbl_8055DA48;
    parse(encode, (char *)arg0, (int **)&texture, &index);
    tile = index / (*(volatile unsigned short *)((char *)texture + 0x1A) *
                    *(volatile unsigned short *)((char *)texture + 0x1C));
    *arg1 = (char *)texture + *(int *)((char *)texture + 0x24) +
        *(int *)((char *)texture + 0x14) * tile;
    remainder = index - tile *
        *(volatile unsigned short *)((char *)texture + 0x1A) *
        *(volatile unsigned short *)((char *)texture + 0x1C);
    column = remainder / *(volatile unsigned short *)((char *)texture + 0x1A);
    row = remainder - column * *(volatile unsigned short *)((char *)texture + 0x1A);
    *arg2 = row * *(volatile unsigned short *)((char *)texture + 0x10);
    *arg3 = column * *(volatile unsigned short *)((char *)texture + 0x12);
    if (arg4 != 0)
        *arg4 = *(unsigned char *)(index + (char *)texture + *(volatile unsigned short *)((char *)texture + 0x22));
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
