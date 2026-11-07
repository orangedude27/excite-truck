#include "revolution/GX/GXTypes.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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
extern void Halt(void);
extern char OSDefaultExceptionHandler[], lbl_8038E060[], lbl_8038E328[];
typedef struct FatalBytes4 { unsigned char b[4]; } FatalBytes4;
typedef struct FatalInfo { FatalBytes4 a; FatalBytes4 b; int c; } FatalInfo;
extern unsigned short lbl_80558F58;
extern void *lbl_8055DA48;
extern int *lbl_8055DA50;
extern int *lbl_8055DA54;
extern unsigned short lbl_803049F0[];
extern unsigned short lbl_80304B70[];
extern int ReadFont();
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
extern float lbl_80560C78, lbl_80560C7C, lbl_80560C80, lbl_80560C84, lbl_80560C88, lbl_80560C8C, lbl_80560C90, lbl_80560C94, lbl_80560C98, lbl_80560C9C, lbl_80560CA0, lbl_80560CA4, lbl_80560CA8;
static inline float ClampYUV_8004(float v, float hi) {
    if (v > hi) return hi;
    if (v < lbl_80560C7C) return lbl_80560C7C;
    return v;
}
static inline GXColor RGBToYUV_8004(GXColor c) {
    GXColor o;
    float y = lbl_80560C78 + (lbl_80560C7C + (lbl_80560C80 * (float)c.b + (lbl_80560C84 * (float)c.r + lbl_80560C88 * (float)c.g)));
    float u = lbl_80560C78 + (lbl_80560C8C + (lbl_80560C90 * (float)c.b + (lbl_80560C94 * (float)c.r - lbl_80560C98 * (float)c.g)));
    float v = lbl_80560C78 + (lbl_80560C8C + ((lbl_80560C90 * (float)c.r - lbl_80560C9C * (float)c.g) - lbl_80560CA0 * (float)c.b));
    o.r = (u8)ClampYUV_8004(y, lbl_80560CA4);
    o.g = (u8)ClampYUV_8004(u, lbl_80560CA8);
    o.b = (u8)ClampYUV_8004(v, lbl_80560CA8);
    o.a = 0;
    return o;
}
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

#pragma push
#pragma use_lmw_stmw off
void OSFatal(unsigned char *arg0, unsigned char *arg1, int arg2) {
    int start;
    unsigned long long t0;
    unsigned char b7, b6, b5, b4, b3, b2, b1, b0;
    OSDisableInterrupts();
    OSDisableScheduler();
    OSClearContext(lbl_8038E060);
    OSSetCurrentContext(lbl_8038E060);
    __OSStopAudioSystem();
    fn_8005954C();
    __OSUnmaskInterrupts(0x80);
    VISetBlack(1);
    VIFlush();
    fn_800591AC(0);
    AIRegisterDMACallback_800591F0(0);
    OSEnableInterrupts();
    start = fn_8005AC08();
    while (fn_8005AC08() - start < 1) {
    }
    t0 = OSGetTime();
    do {
        if (__OSCallShutdownFunctions(0, 0) != 0)
            break;
    } while ((long long)(OSGetTime() - t0) < (long long)((*(unsigned int *)0x800000F8 / 4 / 1000) * 1000));
    OSDisableInterrupts();
    __OSCallShutdownFunctions(1, 0);
    EXISetExiCallback(0, 0);
    EXISetExiCallback(2, 0);
    while (EXILock(0, 1, 0) == 0) {
        EXISync(0);
        EXIDeselect(0);
        EXIUnlock(0);
    }
    EXIUnlock(0);
    while ((*(volatile unsigned int *)0xCD00680C & 1) == 1) {
    }
    __OSSetExceptionHandler(8, OSDefaultExceptionHandler);
    GXGetVtxAttrFmtv();
    OSSetArenaLo((void *)0x81400000);
    OSSetArenaHi(*(void **)0x80000038);
    b0 = arg0[0];
    b1 = arg0[1];
    b2 = arg0[2];
    b3 = arg0[3];
    b4 = arg1[0];
    b5 = arg1[1];
    b6 = arg1[2];
    b7 = arg1[3];
    lbl_8038E328[0] = b0;
    lbl_8038E328[1] = b1;
    lbl_8038E328[2] = b2;
    lbl_8038E328[3] = b3;
    lbl_8038E328[4] = b4;
    lbl_8038E328[5] = b5;
    lbl_8038E328[6] = b6;
    lbl_8038E328[7] = b7;
    *(int *)(lbl_8038E328 + 8) = arg2;
    ((void (*)(void *, void *))OSSwitchFiber)(Halt, OSGetArenaHi());
}
#pragma pop
static inline BOOL IsSjisTrailByte(u8 ch) {
    return (0x40 <= ch && ch <= 0xFC) && (ch != 0x7F);
}

u32 GetFontCode(u16 encode, u16 code) {
    u32 tmp;
    s32 trail;

    if (encode == 1) {
        if (code >= 0x20 && code <= 0xDF) {
            return lbl_803049F0[code - 0x20];
        } else if (code > 0x889E && code <= 0x9872) {
            tmp = ((code >> 8) - 0x88) * 0xBC;
            trail = code & 0xFF;

            if (!IsSjisTrailByte(trail)) {
                return 0;
            }

            trail -= 0x40;
            if (trail >= 0x40) {
                trail--;
            }

            return tmp + trail + 0x2BE;
        } else if (code >= 0x8140 && code < 0x879E) {
            tmp = ((code >> 8) - 0x81) * 0xBC;
            trail = code & 0xFF;

            if (!IsSjisTrailByte(trail)) {
                return 0;
            }

            trail -= 0x40;
            if (trail >= 0x40) {
                trail--;
            }

            return lbl_80304B70[tmp + trail];
        }
    } else if (code > 0x20 && code <= 0xFF) {
        return code - 0x20;
    }

    return 0;
}

#pragma push
#pragma use_lmw_stmw off
void Decode(unsigned char *src, unsigned char *dst) {
    unsigned int literalOffset = *(unsigned int *)(src + 0xC);
    unsigned char *commands = src + 0x10;
    unsigned int outputSize = *(unsigned int *)(src + 4);
    unsigned int output = 0;
    unsigned char *literal = src + literalOffset;
    unsigned int input = *(unsigned int *)(src + 8);
    int bitCount = 0;
    unsigned int bits = 0;

    while (output < outputSize) {
        if (bitCount == 0) {
            bits = *(unsigned int *)commands;
            commands += 4;
            bitCount = 32;
        }
        if (bits & 0x80000000) {
            dst[output++] = *literal++;
        } else {
            unsigned int pair = ((unsigned int)src[input] << 8) | src[input + 1];
            int length = (int)pair >> 12;
            unsigned int distance = pair & 0xFFF;
            unsigned int from;
            int j;
            input += 2;
            if (length == 0)
                length = *literal++ + 0x12;
            else
                length += 2;
            if (length > 0) {
                from = output - distance;
                for (j = 0; j < length; ++j) {
                    dst[output] = dst[from - 1];
                    ++output;
                    ++from;
                }
            }
        }
        bits <<= 1;
        --bitCount;
    }
}
#pragma pop
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

typedef struct OSFontHeader {
    u16 type;
    u16 firstChar;
    u16 lastChar;
    u16 invalidChar;
    u16 ascent;
    u16 descent;
    u16 width;
    u16 leading;
    u16 cellWidth;
    u16 cellHeight;
    u32 sheetSize;
    u16 sheetFormat;
    u16 sheetNumCol;
    u16 sheetNumRow;
    u16 sheetWidth;
    u16 sheetHeight;
    u16 widthTableOfs;
    u32 sheetImageOfs;
    u32 sheetFullSize;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} OSFontHeader;

int __OSReadROM(void *, int, const void *);

static inline void ReadROM(void* dst, s32 size, const void* src) {
    s32 blockSize;

    while (size > 0) {
        blockSize = (size <= 256) ? size : 256;
        size -= blockSize;

        while (!__OSReadROM(dst, blockSize, src)) {
            ;
        }

        src = (u8*)src + blockSize;
        dst = (u8*)dst + blockSize;
    }
}

static inline u32 GetFontSize(const u8* font) {
    if (font[0] == 'Y' && font[1] == 'a' && font[2] == 'y') {
        return *(u32*)(font + 0x4);
    }

    return 0;
}
extern u16 lbl_80560CB8;
extern u16 lbl_80560CBA;
extern u16 lbl_80560CBC;
extern u16 lbl_80560CBE;
#pragma use_lmw_stmw off
int ReadFont(int dst, int encode, int font) {
    u8* tex;
    int i;
    u32 code;
    u32 size;
    s32 sheet;
    s32 numRestTex;
    s32 row;
    s32 col;
    u8* tmp;
    OSFontHeader* f = (OSFontHeader*)font;

    if ((u32)encode == 1) {
        ReadROM((void*)dst, 0x0004D000, (void*)0x001AFF00);
    } else {
        ReadROM((void*)dst, 0x00003000, (void*)0x001FCF00);
    }

    size = GetFontSize((const u8*)dst);
    if (size == 0) {
        return 0;
    }

    Decode((void*)dst, (void*)font);

    if ((u32)encode == 1) {
        u16 c0 = lbl_80560CB8;
        u16 c1 = lbl_80560CBA;
        u16 c2 = lbl_80560CBC;
        u16 c3 = lbl_80560CBE;

        code = GetFontCode(encode, 'T');
        sheet = (s32)code / (f->sheetNumCol * f->sheetNumRow);
        numRestTex = code - (sheet * (f->sheetNumCol * f->sheetNumRow));
        row = numRestTex / f->sheetNumCol;
        col = numRestTex - row * f->sheetNumCol;
        row *= f->cellHeight;
        col *= f->cellWidth;
        tex = (u8*)font + f->sheetImageOfs;
        tex += sheet * f->sheetSize / 2;

        tmp = tex + (((f->sheetWidth / 8) * 32) / 2) * ((row + 4) / 8);
        tmp += (col / 8) * 16;
        tmp += ((row + 4) % 8) * 2;
        tmp += (col % 8) / 4;
        *(u16*)tmp = c0;

        tmp = tex + (((f->sheetWidth / 8) * 32) / 2) * ((row + 5) / 8);
        tmp += (col / 8) * 16;
        tmp += ((row + 5) % 8) * 2;
        tmp += (col % 8) / 4;
        *(u16*)tmp = c1;

        tmp = tex + (((f->sheetWidth / 8) * 32) / 2) * ((row + 6) / 8);
        tmp += (col / 8) * 16;
        tmp += ((row + 6) % 8) * 2;
        tmp += (col % 8) / 4;
        *(u16*)tmp = c2;

        tmp = tex + (((f->sheetWidth / 8) * 32) / 2) * ((row + 7) / 8);
        tmp += (col / 8) * 16;
        tmp += ((row + 7) % 8) * 2;
        tmp += (col % 8) / 4;
        *(u16*)tmp = c3;
    }

    return size;
}
#pragma use_lmw_stmw reset
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
#pragma push
#pragma use_lmw_stmw off
void *ParseStringW(int format, void *input, int *outFont, int *outCode, int unused) {
    int mode;
    unsigned short ch = 0;
    int code = 0;

    switch (format) {
    case 0:
        ch = *(unsigned char *)input;
        mode = (int)lbl_8055DA54;
        if (ch != 0)
            input = (char *)input + 1;
        break;
    case 1:
        ch = *(unsigned char *)input;
        mode = (int)lbl_8055DA50;
        if (ch != 0) {
            int valid = 0;
            unsigned char trail;
            input = (char *)input + 1;
            if ((ch >= 0x81 && ch <= 0x9F) || (ch >= 0xE0 && ch <= 0xFC))
                valid = 1;
            if (valid != 0) {
                valid = 0;
                trail = *(unsigned char *)input;
                if (trail >= 0x40 && trail <= 0xFC && trail != 0x7F)
                    valid = 1;
                if (valid != 0) {
                    ch = (ch << 8) | *(volatile unsigned char *)input;
                    input = (char *)input + 1;
                }
            }
        }
        break;
    case 3:
        input = OSUTF8to32(input, &code);
        break;
    case 4:
        input = OSUTF16to32(input, &code);
        break;
    case 5:
        code = *(int *)input;
        if (code != 0)
            input = (char *)input + 4;
        break;
    }

    if (code != 0) {
        mode = (int)lbl_8055DA54;
        format = 0;
        ch = ((unsigned char (*)(int))OSUTF32toANSI)(code);
        if (ch == 0)
            goto output;
        if (lbl_8055DA4C != 0 &&
            (unsigned int)*(volatile int *)&code <= 0x7F) {
            ch = OSUTF32toSJIS(*(volatile int *)&code);
            if (ch != 0) {
                format = 1;
                mode = (int)lbl_8055DA50;
            }
        }
    }
output:
    *outFont = mode;
    *outCode = ((unsigned int (*)(int, unsigned short))GetFontCode)(format, ch);
    return input;
}
#pragma use_lmw_stmw off
void OSGetFontTexel(char *arg0, unsigned char *arg1, int arg2, int arg3, int *arg4) {
    unsigned char *spC;
    int sp8;
    unsigned short mode = lbl_80558F58;
    int perSheet, tileRowBytes, sheetNo, cell, row, col;
    int xOff, yOff;
    int i, j;
    unsigned char *data;
    unsigned char *table;

    if (mode == 0xFFFF) {
        int console = *(volatile int *)0x800000CC;
        if (console == 0) {
            mode = (*(volatile unsigned short *)0xCC00206E >> 1) & 1;
            lbl_80558F58 = mode;
        } else if (console < 0) {
            mode = 0;
            lbl_80558F58 = 0;
        } else {
            mode = 0;
            lbl_80558F58 = 0;
        }
        lbl_8055DA48 = ParseStringS;
    }
    ((char *(*)(int, char *, int **, int *))lbl_8055DA48)(mode, arg0, (int **)&spC, &sp8);
    perSheet = *(unsigned short *)(spC + 0x1A) * *(unsigned short *)(spC + 0x1C);
    tileRowBytes = ((arg3 * 4) / 8) * 32;
    data = spC + *(int *)(spC + 0x24);
    table = spC + 0x2C;
    sheetNo = sp8 / perSheet;
    cell = sp8 - sheetNo * perSheet;
    data += ((unsigned int)(sheetNo * *(int *)(spC + 0x14))) >> 1;
    row = cell / *(unsigned short *)(spC + 0x1A);
    col = cell - row * *(unsigned short *)(spC + 0x1A);
    yOff = row * *(unsigned short *)(spC + 0x12);
    xOff = col * *(unsigned short *)(spC + 0x10);
    for (i = 0; i < *(unsigned short *)(spC + 0x12); i++) {
        int srcY = yOff + i;
        for (j = 0; j < *(unsigned short *)(spC + 0x10); j++) {
            int srcX = xOff + j;
            int dx = arg2 + j;
            unsigned char byte, val, old, *p;
            int mask = 0xF0;
            byte = data[(srcY / 8) * (((*(unsigned short *)(spC + 0x1E)) / 8 * 32) / 2) + (srcX / 8) * 16 + (srcY % 8) * 2 + (srcX % 8) / 4];
            val = table[(byte >> (6 - (srcX % 4) * 2)) & 3];
            p = arg1 + (i / 8) * tileRowBytes + (dx / 8) * 32 + (i % 8) * 4 + (dx % 8) / 2;
            old = *p;
            if ((dx % 2) != 0) mask = 0xF;
            *p = old | (unsigned char)(val & mask);
        }
    }
    if (arg4 != 0)
        *arg4 = *(unsigned char *)(spC + *(unsigned short *)(spC + 0x22) + sp8);
}
extern void DCStoreRange(void *, unsigned int);
int ExpandFontSheet(void *arg0, void *src0, void *dst0) {
    int i;
    unsigned char *src = (unsigned char *)src0;
    unsigned char *dst = (unsigned char *)dst0;
    const unsigned char *tmp = (unsigned char *)arg0 + 0x2C;
    if (*(unsigned short *)((char *)arg0 + 0x18) == 0) {
        for (i = *(int *)((char *)arg0 + 0x28) / 2 - 1; i >= 0; i--) {
            dst[i * 2 + 0] = tmp[src[i] >> 6 & 3] & 0xF0 | tmp[src[i] >> 4 & 3] & 0x0F;
            dst[i * 2 + 1] = tmp[src[i] >> 2 & 3] & 0xF0 | tmp[src[i] >> 0 & 3] & 0x0F;
        }
    } else if (*(unsigned short *)((char *)arg0 + 0x18) == 2) {
        for (i = *(int *)((char *)arg0 + 0x28) / 4 - 1; i >= 0; i--) {
            dst[i * 4 + 0] = tmp[src[i] >> 6 & 3];
            dst[i * 4 + 1] = tmp[src[i] >> 4 & 3];
            dst[i * 4 + 2] = tmp[src[i] >> 2 & 3];
            dst[i * 4 + 3] = tmp[src[i] >> 0 & 3];
        }
    }
    DCStoreRange(dst, *(int *)((char *)arg0 + 0x28));
}

extern int ExpandFontSheet(void *, void *, void *);
int OSInitFont(void *arg0) {
    register unsigned short mode = lbl_80558F58;
    int dispatch, result, aligned, finalSize, console;
    void *font, *source, *base, *expandBase;

    if (mode == 0xFFFF) goto initialize;
    goto initialized;
initialize:
    console = *(volatile int *)0x800000CC;
    if (console == 0) goto read_mode;
    if (console < 0) goto zero_mode;
    goto zero_mode;
read_mode:
    mode = (*(volatile unsigned short *)0xCC00206E >> 1) & 1;
    lbl_80558F58 = mode;
    goto parse_mode;
zero_mode:
    mode = 0;
    lbl_80558F58 = mode;
parse_mode:
    lbl_8055DA48 = (void *)ParseStringS;
initialized:
    dispatch = (int)mode;
    switch (dispatch) {
    case 0: goto mode0;
    case 1: goto mode1;
    case 2: goto done;
    case 3:
    case 4:
    case 5: goto mode35;
    default: goto done;
    }

mode0:
    lbl_8055DA54 = arg0;
    font = (char *)arg0 + 0x1D120;
    result = ReadFont((int)font, 0, (int)arg0);
    if (result != 0) goto mode0_read;
    return 0;
mode0_read:
    base = lbl_8055DA54;
    result = *(int *)((char *)base + 0x24);
    source = (char *)base + result;
    *(int *)((char *)base + 0x24) = (result + 0x1F) & ~0x1F;
    expandBase = lbl_8055DA54;
    finalSize = *(int *)((char *)expandBase + 0x24);
    ExpandFontSheet(expandBase, source, (char *)expandBase + finalSize);
    goto done;

mode1:
    {
        int finalSize1;
        void *source1, *base1, *expandBase1;
        lbl_8055DA50 = arg0;
        font = (char *)arg0 + 0xD3F00;
        result = ReadFont((int)font, 1, (int)arg0);
        if (result != 0) goto mode1_read;
        return 0;
mode1_read:
        base1 = lbl_8055DA50;
        result = *(int *)((char *)base1 + 0x24);
        source1 = (char *)base1 + result;
        *(int *)((char *)base1 + 0x24) = (result + 0x1F) & ~0x1F;
        expandBase1 = lbl_8055DA50;
        finalSize1 = *(int *)((char *)expandBase1 + 0x24);
        ExpandFontSheet(expandBase1, source1, (char *)expandBase1 + finalSize1);
        goto done;
    }

mode35:
    {
        int size35, aligned35, finalSize35;
        void *source35, *base35, *expandBase35, *font35;
        font35 = (char *)arg0 + 0xF4020;
        lbl_8055DA54 = arg0;
        result = ReadFont((int)font35, 0, (int)arg0);
        if (result != 0) goto mode35_first_read;
        return 0;
mode35_first_read:
        base35 = lbl_8055DA54;
        size35 = *(int *)((char *)base35 + 0x24);
        source35 = (char *)base35 + size35;
        aligned35 = (size35 + 0x1F) & ~0x1F;
        *(int *)((char *)base35 + 0x24) = aligned35;
        expandBase35 = lbl_8055DA54;
        finalSize35 = *(int *)((char *)expandBase35 + 0x24);
        ExpandFontSheet(expandBase35, source35, (char *)expandBase35 + finalSize35);
        expandBase35 = (char *)lbl_8055DA54 + 0x20120;
        lbl_8055DA50 = expandBase35;
        result = ReadFont((int)font35, 1, (int)expandBase35);
        if (result != 0) goto mode35_second_read;
        return 0;
mode35_second_read:
        base35 = lbl_8055DA50;
        result = *(int *)((char *)base35 + 0x24);
        source35 = (char *)base35 + result;
        aligned35 = (result + 0x1F) & ~0x1F;
        *(int *)((char *)base35 + 0x24) = aligned35;
        expandBase35 = lbl_8055DA50;
        finalSize35 = *(int *)((char *)expandBase35 + 0x24);
        ExpandFontSheet(expandBase35, source35, (char *)expandBase35 + finalSize35);
        goto done;
    }
done:
    return 1;
}

char *OSGetFontTexture(char *arg0, void **arg1, int *arg2, int *arg3, int *arg4) {
    typedef struct {
        unsigned char pad0[0x10];
        volatile unsigned short width;
        volatile unsigned short height;
        volatile int dataStride;
        unsigned char pad1[2];
        volatile unsigned short tilesWide;
        volatile unsigned short tilesHigh;
        unsigned char pad2[4];
        volatile unsigned short glyphOffset;
        volatile int bitmapOffset;
    } FontTexture;
    unsigned short encode;
    FontTexture *texture;
    register int index;
    int indexOut;
    int tile;
    int remainder;
    unsigned short tilesWide;
    unsigned short tilesHigh;
    int column;
    int row;
    char *(*parse)(int, char *, int **, int *);
    char *next;
    encode = OSGetFontEncode();
    parse = (char *(*)(int, char *, int **, int *))lbl_8055DA48;
    next = parse(encode, arg0, (int **)&texture, &indexOut);
    index = indexOut;
    tile = index / (texture->tilesWide * texture->tilesHigh);
    *arg1 = (char *)texture + texture->bitmapOffset + texture->dataStride * tile;
    tilesWide = texture->tilesWide;
    tilesHigh = texture->tilesHigh;
    remainder = indexOut - tile * tilesWide * tilesHigh;
    column = remainder / tilesWide;
    row = remainder - column * tilesWide;
    *arg2 = row * texture->width;
    *arg3 = column * texture->height;
    if (arg4 != 0)
        *arg4 = *(unsigned char *)((char *)texture + texture->glyphOffset + indexOut);
    return next;
}

void OSGetFontWidth(int ch,int *out) {
 void *p; int n; unsigned short e=lbl_80558F58; int v;
 if(e==(unsigned short)-1) { v=*(volatile int*)0x800000CC; if(v==0) {e=(*(volatile unsigned short*)0xCC00206E>>1)&1;lbl_80558F58=e;} else if(v<0){e=0;lbl_80558F58=e;}else{e=0;lbl_80558F58=e;} lbl_8055DA48=ParseStringS; }
 ((int(*)(unsigned short,int,void**,int*))lbl_8055DA48)(e,ch,&p,&n);
 if(out) *out=(unsigned char)*((char*)p+*(unsigned short*)((char*)p+0x22)+n);
}
