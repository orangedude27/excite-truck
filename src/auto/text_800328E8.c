// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D7E0;
extern unsigned char lbl_80363C60[];
extern unsigned char lbl_80368460[];
extern unsigned char lbl_8036C460[];
extern unsigned char lbl_8036D460[];
extern unsigned int lbl_802FED20[];
extern int lbl_8055D7E4;
extern unsigned int lbl_8055D7E8;
extern void DCInvalidateRange(void *, unsigned int);
extern void DCFlushRange(void *, unsigned int);
extern int fn_80031248(void);
extern void *TRKReadBuffer_ui8(int);
extern void __AXDepopVoice(void *);
extern void *memcpy(void *, const void *, unsigned int);
typedef struct { unsigned char b[0x120]; } Block120;
typedef struct { unsigned char b[0x30]; } Block30;
extern void fn_800328F0(void *);
extern void TRKAppendBuffer(void *);
void* fn_800328E8(void) {
    return lbl_8055D7E0;
}

#pragma use_lmw_stmw off
void fn_800328F0(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    unsigned char *src;
    unsigned char *dst;
    unsigned int flags;
    unsigned int n;
    unsigned int *cs;
    unsigned int *cd;
    int *z;

    dst = p + 0x138;
    lbl_8055D7E0 = (void *)((unsigned int)lbl_8055D7E0 + 1);
    flags = *(unsigned int *)(p + 0x1C);
    src = lbl_80363C60 + *(int *)(p + 0x18) * 0x120;
    if (flags == 0) {
        *(unsigned short *)(dst + 0x10) = *(unsigned short *)(src + 0x10);
        *(unsigned short *)(dst + 0x74) = *(unsigned short *)(src + 0x74);
        *(unsigned short *)(dst + 0x84) = *(unsigned short *)(src + 0x84);
        *(unsigned short *)(dst + 0x86) = *(unsigned short *)(src + 0x86);
        return;
    }
    if (flags & 0x80000000) {
        memcpy(src, dst, 0x120);
        n = *(unsigned int *)(p + 0x28);
        if (n != 0) {
            cs = (unsigned int *)(p + 0x34);
            cd = (unsigned int *)(lbl_80368460 + (*(int *)(p + 0x18) << 8));
            while (n != 0) {
                *cd++ = *cs++;
                n--;
            }
        }
    } else {
        if (flags & 1) {
            *(unsigned short *)(src + 0x08) = *(unsigned short *)(dst + 0x08);
            *(unsigned short *)(src + 0x0A) = *(unsigned short *)(dst + 0x0A);
        }
        if (flags & 2) {
            *(int *)(src + 0x0C) = *(int *)(dst + 0x0C);
        }
        if (flags & 4) {
            *(unsigned short *)(src + 0x10) = *(unsigned short *)(dst + 0x10);
        } else {
            *(unsigned short *)(dst + 0x10) = *(unsigned short *)(src + 0x10);
        }
        if (flags & 8) {
            *(unsigned short *)(src + 0x12) = *(unsigned short *)(dst + 0x12);
        }
        if (flags & 0x10) {
            memcpy(src + 0x14, dst + 0x14, 0x30);
        }
        if (flags & 0x40) {
            *(unsigned short *)(src + 0x4E) = *(unsigned short *)(dst + 0x4E);
            *(unsigned short *)(src + 0x50) = *(unsigned short *)(dst + 0x50);
        } else if (flags & 0x20) {
            *(unsigned short *)(src + 0x44) = *(unsigned short *)(dst + 0x44);
            *(unsigned short *)(src + 0x46) = *(unsigned short *)(dst + 0x46);
            *(unsigned short *)(src + 0x48) = *(unsigned short *)(dst + 0x48);
            *(unsigned short *)(src + 0x4A) = *(unsigned short *)(dst + 0x4A);
            *(unsigned short *)(src + 0x4C) = *(unsigned short *)(dst + 0x4C);
            *(unsigned short *)(src + 0x4E) = *(unsigned short *)(dst + 0x4E);
            *(unsigned short *)(src + 0x50) = *(unsigned short *)(dst + 0x50);
            z = *(int **)(p + 0x134);
            z[0x00] = 0; z[0x01] = 0; z[0x02] = 0; z[0x03] = 0;
            z[0x04] = 0; z[0x05] = 0; z[0x06] = 0; z[0x07] = 0;
            z[0x08] = 0; z[0x09] = 0; z[0x0A] = 0; z[0x0B] = 0;
            z[0x0C] = 0; z[0x0D] = 0; z[0x0E] = 0; z[0x0F] = 0;
        }
        if (flags & 0x80) {
            memcpy(src + 0x52, dst + 0x52, 0xA);
            n = *(unsigned int *)(p + 0x28);
            if (n != 0) {
                cs = (unsigned int *)(p + 0x34);
                cd = (unsigned int *)(lbl_80368460 + (*(int *)(p + 0x18) << 8));
                while (n != 0) {
                    *cd++ = *cs++;
                    n--;
                }
            }
        }
        if (flags & 0x100) {
            memcpy(src + 0x5C, dst + 0x5C, 0x18);
        }
        if (flags & 0x400) {
            *(unsigned short *)(dst + 0x74) = *(unsigned short *)(src + 0x74);
            *(short *)(src + 0x76) = *(short *)(dst + 0x76);
        } else if (flags & 0x200) {
            *(unsigned short *)(src + 0x74) = *(unsigned short *)(dst + 0x74);
            *(short *)(src + 0x76) = *(short *)(dst + 0x76);
        }
        if (flags & 0xF000) {
            if (flags & 0x1000) {
                *(unsigned short *)(src + 0x78) = *(unsigned short *)(dst + 0x78);
            }
            if (flags & 0x2000) {
                *(int *)(src + 0x7C) = *(int *)(dst + 0x7C);
            }
            if (flags & 0x4000) {
                *(int *)(src + 0x80) = *(int *)(dst + 0x80);
            }
            if (flags & 0x8000) {
                *(int *)(src + 0x84) = *(int *)(dst + 0x84);
            } else {
                *(int *)(dst + 0x84) = *(int *)(src + 0x84);
            }
        } else if (flags & 0x800) {
            *(int *)(src + 0x78) = *(int *)(dst + 0x78);
            *(int *)(src + 0x7C) = *(int *)(dst + 0x7C);
            *(int *)(src + 0x80) = *(int *)(dst + 0x80);
            *(int *)(src + 0x84) = *(int *)(dst + 0x84);
        } else {
            *(unsigned short *)(dst + 0x84) = *(unsigned short *)(src + 0x84);
            *(unsigned short *)(dst + 0x86) = *(unsigned short *)(src + 0x86);
        }
        if (flags & 0x10000) {
            *(int *)(src + 0x88) = *(int *)(dst + 0x88);
            *(int *)(src + 0x8C) = *(int *)(dst + 0x8C);
            *(int *)(src + 0x90) = *(int *)(dst + 0x90);
            *(int *)(src + 0x94) = *(int *)(dst + 0x94);
            *(int *)(src + 0x98) = *(int *)(dst + 0x98);
            *(int *)(src + 0x9C) = *(int *)(dst + 0x9C);
            *(int *)(src + 0xA0) = *(int *)(dst + 0xA0);
            *(int *)(src + 0xA4) = *(int *)(dst + 0xA4);
            *(int *)(src + 0xA8) = *(int *)(dst + 0xA8);
            *(int *)(src + 0xAC) = *(int *)(dst + 0xAC);
        }
        if (flags & 0x40000) {
            *(unsigned short *)(src + 0xB0) = *(unsigned short *)(dst + 0xB0);
            *(unsigned short *)(src + 0xB2) = *(unsigned short *)(dst + 0xB2);
        } else if (flags & 0x20000) {
            *(unsigned short *)(src + 0xB0) = *(unsigned short *)(dst + 0xB0);
            *(unsigned short *)(src + 0xB2) = *(unsigned short *)(dst + 0xB2);
            *(unsigned short *)(src + 0xB4) = *(unsigned short *)(dst + 0xB4);
            *(unsigned short *)(src + 0xB6) = *(unsigned short *)(dst + 0xB6);
            *(unsigned short *)(src + 0xB8) = *(unsigned short *)(dst + 0xB8);
            *(unsigned short *)(src + 0xBA) = *(unsigned short *)(dst + 0xBA);
            *(unsigned short *)(src + 0xBC) = *(unsigned short *)(dst + 0xBC);
        }
        if (flags & 0x80000) {
            *(unsigned short *)(src + 0xBE) = *(unsigned short *)(dst + 0xBE);
            *(unsigned short *)(src + 0xC0) = *(unsigned short *)(dst + 0xC0);
            *(unsigned short *)(src + 0xC2) = *(unsigned short *)(dst + 0xC2);
        }
        if (flags & 0x200000) {
            *(unsigned short *)(src + 0xC8) = *(unsigned short *)(dst + 0xC8);
            *(unsigned short *)(src + 0xCA) = *(unsigned short *)(dst + 0xCA);
        } else if (flags & 0x100000) {
            *(unsigned short *)(src + 0xC4) = *(unsigned short *)(dst + 0xC4);
            *(unsigned short *)(src + 0xC6) = *(unsigned short *)(dst + 0xC6);
            *(unsigned short *)(src + 0xC8) = *(unsigned short *)(dst + 0xC8);
            *(unsigned short *)(src + 0xCA) = *(unsigned short *)(dst + 0xCA);
        }
        if (flags & 0x800000) {
            *(unsigned short *)(src + 0xD0) = *(unsigned short *)(dst + 0xD0);
            *(unsigned short *)(src + 0xD2) = *(unsigned short *)(dst + 0xD2);
        } else if (flags & 0x400000) {
            *(unsigned short *)(src + 0xCC) = *(unsigned short *)(dst + 0xCC);
            *(unsigned short *)(src + 0xCE) = *(unsigned short *)(dst + 0xCE);
            *(unsigned short *)(src + 0xD0) = *(unsigned short *)(dst + 0xD0);
            *(unsigned short *)(src + 0xD2) = *(unsigned short *)(dst + 0xD2);
        }
        if (flags & 0x01000000) {
            *(unsigned short *)(src + 0xD4) = *(unsigned short *)(dst + 0xD4);
        }
        if (flags & 0x02000000) {
            *(unsigned short *)(src + 0xD6) = *(unsigned short *)(dst + 0xD6);
        }
        if (flags & 0x04000000) {
            memcpy(src + 0xD8, dst + 0xD8, 0x20);
        }
        if (flags & 0x08000000) {
            memcpy(src + 0xF8, dst + 0xF8, 0x10);
        }
        if (flags & 0x10000000) {
            memcpy(src + 0x108, dst + 0x108, 0xA);
        }
    }
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
void fn_80032EAC(int arg0) {
    unsigned int r29;
    int i;
    unsigned char *p;

    lbl_8055D7E0 = 0;
    DCInvalidateRange(lbl_80363C60, 0x4800);
    DCInvalidateRange(lbl_8036C460, 0x1000);
    r29 = (fn_80031248() + 0x10000 + arg0) - 0x55F0;
    i = 0x1F;

    do {
        p = (unsigned char *)TRKReadBuffer_ui8(i);
        while (p != 0) {
            if (*(int *)(p + 0x20) != 0) {
                __AXDepopVoice(lbl_80363C60 + *(int *)(p + 0x18) * 0x120);
            }
            if (*(unsigned short *)(p + 0x148) == 1 || *(int *)(p + 0x28) != 0) {
                if (*(unsigned short *)(p + 0x140) != 2) {
                    unsigned int v = __rlwimi(*(unsigned short *)(p + 0x1EA), *(unsigned short *)(p + 0x1E8), 16, 0, 15);
                    r29 += ((((v * 0x84) + 0x8000) >> 16) + 0x2D8) * 6;
                }
                if (*(unsigned short *)(p + 0x1FC) != 0) {
                    r29 += 0x22B;
                }
                if (*(unsigned short *)(p + 0x204) != 0) {
                    r29 += 0x22B;
                }
                {
                    unsigned int t = *(unsigned int *)(p + 0x144);
                    unsigned int sum = lbl_802FED20[(t >> 21) & 0x1F] + lbl_802FED20[t & 0x1F];
                    r29 = sum
                        + lbl_802FED20[(t >> 16) & 0x1F]
                        + (lbl_802FED20[(t >> 26) & 0x1F] + r29)
                        + 0x8C;
                }
                if (lbl_8055D7E8 > r29) {
                    fn_800328F0(p);
                } else {
                    unsigned char *vpb = lbl_80363C60 + *(int *)(p + 0x18) * 0x120;
                    if (*(unsigned short *)(vpb + 0x10) == 1) {
                        __AXDepopVoice(vpb);
                    }
                    *(short *)(vpb + 0x56) = 0;
                    *(short *)(vpb + 0x54) = 0;
                    *(short *)(vpb + 0x52) = 0;
                    *(short *)(vpb + 0x10) = 0;
                    *(unsigned short *)(p + 0x148) = 0;
                    TRKAppendBuffer(p);
                }
            } else {
                fn_800328F0(p);
            }
            *(int *)(p + 0x1C) = 0;
            *(int *)(p + 0x20) = 0;
            *(int *)(p + 0x28) = 0;
            *(int *)(p + 0x24) = 0;
            *(void **)(p + 0x30) = (void *)(p + 0x34);
            p = *(unsigned char **)p;
        }
    } while (--i != 0);

    lbl_8055D7E4 = r29;
    {
        unsigned char *p2 = (unsigned char *)TRKReadBuffer_ui8(0);
        while (p2 != 0) {
            if (*(int *)(p2 + 0x20) != 0) {
                __AXDepopVoice(lbl_80363C60 + *(int *)(p2 + 0x18) * 0x120);
            }
            *(int *)(p2 + 0x20) = 0;
            *(short *)(lbl_80363C60 + *(int *)(p2 + 0x18) * 0x120 + 0x56) = 0;
            *(short *)(lbl_80363C60 + *(int *)(p2 + 0x18) * 0x120 + 0x54) = 0;
            *(short *)(lbl_80363C60 + *(int *)(p2 + 0x18) * 0x120 + 0x52) = 0;
            *(short *)(lbl_80363C60 + *(int *)(p2 + 0x18) * 0x120 + 0x10) = 0;
            p2 = *(unsigned char **)p2;
        }
    }

    DCFlushRange(lbl_80363C60, 0x4800);
    DCFlushRange(lbl_8036C460, 0x1000);
    DCFlushRange(lbl_80368460, 0x4000);
}
#pragma use_lmw_stmw reset
void *__AXFXGetLfoSinTable_8003313C(void) { return lbl_80363C60; }

void fn_80033148(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    *(short *)(p + 0x148) = 0;
    *(short *)(p + 0x17C) = 0;
    *(int *)(p + 0x1C) = 0x115000A4;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x30) = (int)(p + 0x34);
    *(short *)(p + 0x18E) = 0;
    *(short *)(p + 0x18C) = 0;
    *(short *)(p + 0x18A) = 0;
    *(short *)(p + 0x1FC) = 0;
    *(short *)(p + 0x204) = 0;
    *(short *)(p + 0x20C) = 0;
    *(short *)(p + 0x240) = 0;
    *(short *)(p + 0x242) = 0;
    *(short *)(p + 0x244) = 0;
    *(short *)(p + 0x246) = 0;
    *(short *)(p + 0x248) = 0;
}

extern unsigned char lbl_80368460[];
extern unsigned char lbl_8036C460[];
extern unsigned char lbl_8036D460[];
extern int lbl_8055D7E4;
extern unsigned int lbl_8055D7E8;
extern void TRKReadBuffer(void);
extern void DCFlushRange(void *, unsigned int);
void fn_800331A0(void) {
    unsigned int i;
    int j;
    int *p;
    lbl_8055D7E4 = 0;
    lbl_8055D7E8 = *(unsigned int *)0x800000F8 / 667;
    p = (int *)lbl_80363C60;
    for (j = 0; j < 0x200; j++) {
        int k;
        for (k = 0; k < 9; k++) *p++ = 0;
    }
    p = (int *)lbl_8036C460;
    for (j = 0; j < 0x80; j++) {
        int k;
        for (k = 0; k < 8; k++) *p++ = 0;
    }
    p = (int *)lbl_8036D460;
    for (j = 0; j < 0x3c0; j++) {
        int k;
        for (k = 0; k < 10; k++) *p++ = 0;
    }
    for (i = 0; i < 0x40; i++) {
        unsigned char *vpb = lbl_8036D460 + i * 0x258;
        unsigned char *buf = lbl_80363C60 + i * 0x120;
        unsigned char *b2 = lbl_8036C460 + i * 0x40;
        unsigned char *b3 = lbl_80368460 + i * 0x100;
        *(unsigned int *)(vpb + 0x18) = i;
        *(void **)(vpb + 0x134) = b2;
        fn_80033148(vpb);
        if (i == 0x3F) {
            *(unsigned short *)(buf + 2) = 0;
            *(unsigned short *)(vpb + 0x13A) = 0;
            *(unsigned short *)(buf + 0) = 0;
            *(unsigned short *)(vpb + 0x138) = 0;
        } else {
            unsigned int next = (unsigned int)(buf + 0x120);
            *(unsigned short *)(vpb + 0x138) = next >> 16;
            *(unsigned short *)(buf + 0) = next >> 16;
            *(unsigned short *)(vpb + 0x13A) = next;
            *(unsigned short *)(buf + 2) = next;
        }
        *(unsigned short *)(vpb + 0x13C) = (unsigned int)buf >> 16;
        *(unsigned short *)(vpb + 0x13E) = (unsigned int)buf;
        *(unsigned short *)(buf + 4) = (unsigned int)buf >> 16;
        *(unsigned short *)(buf + 6) = (unsigned int)buf;
        *(unsigned short *)(vpb + 0x17E) = (unsigned int)b2 >> 16;
        *(unsigned short *)(vpb + 0x180) = (unsigned int)b2;
        *(unsigned short *)(buf + 0x46) = (unsigned int)b2 >> 16;
        *(unsigned short *)(buf + 0x48) = (unsigned int)b2;
        *(unsigned short *)(vpb + 0x190) = (unsigned int)b3 >> 16;
        *(unsigned short *)(vpb + 0x192) = (unsigned int)b3;
        *(unsigned short *)(buf + 0x58) = (unsigned int)b3 >> 16;
        *(unsigned short *)(buf + 0x5A) = (unsigned int)b3;
        *(int *)(vpb + 0xC) = 1;
        TRKReadBuffer();
    }
    DCFlushRange(lbl_80363C60, 0x4800);
}

void fn_80033404(void) {

}

extern unsigned char lbl_80363C60[];
extern unsigned long OSDisableInterrupts(void);
extern void OSRestoreInterrupts(unsigned long);
void fn_80033408(void *arg0, int arg1) {
    unsigned char *p = (unsigned char *)arg0;
    unsigned long state = OSDisableInterrupts();
    switch (arg1) {
    case 0: *(short *)(p + 0x140) = 2; break;
    case 1: *(short *)(p + 0x140) = 1; break;
    case 2: *(short *)(p + 0x140) = 0; *(short *)(p + 0x142) = 0; break;
    case 3: *(short *)(p + 0x140) = 0; *(short *)(p + 0x142) = 1; break;
    case 4: *(short *)(p + 0x140) = 0; *(short *)(p + 0x142) = 2; break;
    }
    *(unsigned int *)(p + 0x1C) |= 1;
    OSRestoreInterrupts(state);
}

