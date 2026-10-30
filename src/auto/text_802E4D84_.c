// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FFB5;
extern void *lbl_8055FF8C;
extern float lbl_80565128;
extern float lbl_8056512C;
extern float lbl_80565130;
extern float lbl_80565134;
extern void fn_802E5264(int, int);
extern float lbl_804FC680[];
extern int lbl_8055D1EC;
extern int lbl_8055D1F0;
extern void fn_802E7770(void);
extern int fn_802E7774(void (*arg0)(void));
extern void fn_802E2E0C(void *arg0, void *arg1);
extern int TRKReadBuffer_ui32(void);
extern float fn_802E9A2C(void);
extern void fn_80060CC0(int, int, void (*)());
extern void fn_802E30C8(char *, int, char *, ...);
extern void *memset(void *, int, unsigned int);
extern void fn_802E5248(int, int);
extern void fn_802E51D0();
__declspec(section ".sdata") extern char lbl_8055D1D8[];
extern char lbl_8034D39C[];
extern char lbl_8034D384[];
extern char lbl_8034D3C0[];
extern unsigned char lbl_804FC800[];
extern unsigned char lbl_804FC558[];
extern int lbl_8055FF78;
extern int lbl_8055FFA0;
extern int *lbl_8055FF9C;
extern unsigned char *lbl_8055FF94;
extern void *lbl_8055FF90;
extern int fn_802E5AE8(void);
extern void fn_8012BEF0(unsigned char *);
extern void fn_8012C41C(void (*)(void), int, unsigned char *);
extern void fn_802E589C(void);
extern int fn_802E582C(void);
#pragma dont_inline fn_802E582C
__declspec(section ".sdata") extern char lbl_8055D1E4[];
extern char lbl_8034D490[];
extern char lbl_8034D4A0[];
extern char lbl_8034D5B0[];
extern void fn_802E317C(char *, ...);
extern int lbl_8055FF98;
extern char lbl_8034D584[];
extern char lbl_8034D528[];
extern void fn_80128670(int);
extern void fn_8012C4D8(void);
extern void fn_8012BF24(void *);
void fn_802E4D84(void *dst, void *src, int size) {
    void *saved_dst = dst;
    int saved_size = size;
    memcpy(dst, src, size);
    DCFlushRange(saved_dst, saved_size);
}

extern unsigned char *fn_8012C370(int, unsigned int *, int, unsigned char *, unsigned char *);
extern char lbl_8034D280[];
#pragma scheduling invalid_target
void *fn_802E4DC8(char *arg0) {
    unsigned int size;
    unsigned char sp9;
    unsigned char sp8;
    unsigned char *buf;
    unsigned char *data;
    unsigned char tmp;
    unsigned int i;

    buf = ((unsigned char *(*)(char *, unsigned int, unsigned int *, int, unsigned char *, unsigned char *))fn_8012C370)(
        arg0, 0x53465830, &size, 0, &sp9, &sp8);
    if (buf == 0) {
        goto return_null;
    }
    if (size != 3) {
        fn_802E317C(lbl_8034D280, arg0, size, 3);
    }
    if (sp8 != 0) {
        tmp=buf[0]; buf[0]=buf[3]; buf[3]=tmp;
        tmp=buf[1]; buf[1]=buf[2]; buf[2]=tmp;
        tmp=buf[4]; buf[4]=buf[7]; buf[7]=tmp;
        tmp=buf[5]; buf[5]=buf[6]; buf[6]=tmp;
        tmp=buf[12]; buf[12]=buf[13]; buf[13]=tmp;
        tmp=buf[14]; buf[14]=buf[15]; buf[15]=tmp;
        tmp=buf[16]; buf[16]=buf[19]; buf[19]=tmp;
        tmp=buf[17]; buf[17]=buf[18]; buf[18]=tmp;
        tmp=buf[20]; buf[20]=buf[23]; buf[23]=tmp;
        tmp=buf[21]; buf[21]=buf[22]; buf[22]=tmp;
        tmp=buf[24]; buf[24]=buf[25]; buf[25]=tmp;
        tmp=buf[26]; buf[26]=buf[27]; buf[27]=tmp;
        tmp=buf[28]; buf[28]=buf[29]; buf[29]=tmp;

        *(unsigned int *)(buf+4) = (unsigned int)buf + *(unsigned int *)(buf+4);
        if (*(unsigned short *)(buf+26) == 16 && buf[9] != 1) {
            data = *(unsigned char **)(buf+4);
            for (i=0; i<(unsigned int)((*(int *)buf + (*(int *)buf >> 31)) >> 1); i++) {
                tmp=data[0];
                data[0]=data[1];
                data[1]=tmp;
                data+=2;
            }
        }
        DCFlushRange(*(void **)(buf+4), *(unsigned int *)buf);
    }
    return buf;
return_null:
    return 0;
}
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802E4F98(void) {
    extern char lbl_8055FFA4;
    extern char lbl_8055FFA5;
    extern char lbl_8055FFA6;
    extern char lbl_8055FFB4;
    extern int OSEnableInterrupts(int);
    extern int fn_802D9BF0(void);
    extern void fn_80033AAC(void *, void *);
    register int offset;
    register int interruptState;
    register int count;
    int motor;
    unsigned char *entry;
    unsigned char *object;
    unsigned int span;
    unsigned int sampleCount;
    unsigned int end;
    short samples[3];

    if ((unsigned char)lbl_8055FFA5 != 0 &&
        (unsigned char)lbl_8055FFA6 == 0) {
        interruptState = ((int (*)(void))OSEnableInterrupts)();
        motor = fn_802D9BF0();
        lbl_8055FFB4 = 1;
        count = 0;
        offset = 0;
        do {
            entry = lbl_8055FF94 + offset;
            object = *(unsigned char **)(entry + 0x1C);
            if (entry[0x20] != 0 && object != 0 &&
                *(int *)(object + 0x20) == 1 && entry[0x21] == 0) {
                span = *(unsigned int *)(*(unsigned char **)(entry + 4) + 0x1BC);
                if (object[0x24] != 0) {
                    span >>= 1;
                } else {
                    span <<= 1;
                }
                sampleCount = *(unsigned int *)(object + 0xA0) >> 1;
                end = *(unsigned int *)(object + 0x9C) + sampleCount;
                if (span < *(unsigned int *)(entry + 0x28)) {
                    if (motor == 0) {
                        ((void (*)(void *, unsigned int, void *))*(void **)(object + 0x88))(
                            (unsigned char *)*(void **)(object + 0x90) + sampleCount,
                            sampleCount, *(void **)(object + 0x8C));
                    } else {
                        memset((unsigned char *)*(void **)(object + 0x90) + sampleCount, 0, sampleCount);
                    }
                    DCFlushRange((unsigned char *)*(void **)(object + 0x90) + sampleCount, sampleCount);
                }
                if (span >= end && *(unsigned int *)(entry + 0x28) < end) {
                    if (motor == 0) {
                        ((void (*)(void *, unsigned int, void *))*(void **)(object + 0x88))(
                            *(void **)(object + 0x90),
                            sampleCount, *(void **)(object + 0x8C));
                    } else {
                        memset(*(void **)(object + 0x90), 0, sampleCount);
                    }
                    if (object[0x24] != 0) {
                        samples[0] = (short)*((unsigned char *)*(void **)(object + 0x90));
                        samples[1] = 0;
                        samples[2] = 0;
                        fn_80033AAC(*(void **)(entry + 4), samples);
                    }
                    DCFlushRange(*(void **)(object + 0x90), sampleCount);
                }
                *(unsigned int *)(entry + 0x28) = span;
            }
            ++count;
            offset += 0x2C;
        } while (count < 0x20);
        *(volatile unsigned char *)&lbl_8055FFA4 = 1;
        *(volatile unsigned char *)&lbl_8055FFB4 = 0;
        OSRestoreInterrupts(interruptState);
    }
}
#pragma scheduling on
#pragma pop

extern float lbl_80565130;
extern float lbl_80565134;
unsigned short fn_802E5168(float arg0) {
    float value = lbl_80565130 * arg0;
    int converted;
    int result;
    if (value < lbl_8056512C) {
        value -= lbl_80565134;
    } else {
        value += lbl_80565134;
    }
    converted = (int)value;
    result = converted & ((-converted & ~converted) >> 31);
    if (result >= 0x8000) result = 0x8000;
    return (unsigned short)result;
}

#pragma scheduling invalid_target
void fn_802E51D0(int arg0, int arg1) {
    unsigned char *entry;

    if (arg1 != 0) {
        return;
    }
    ((volatile unsigned char *)lbl_804FC800)[arg0 * 0x2C] = 1;
    entry = lbl_804FC800 + arg0 * 0x2C;
    *(int *)(entry + 0x24) = 1;
    *(int *)(entry + 0x28) = 0;
    memset(entry + 1, 0, 0x20);
    ((void (*)(char *, int, ...))fn_802E30C8)(lbl_8034D384, arg0);
}
#pragma scheduling on
void fn_802E5248(int arg0, int arg1) {
    if (arg1 == 0) fn_80060CC0(arg0, 4, (void (*)())fn_802E51D0);
}

void fn_802E5264(int arg0, int arg1) {
    fn_802E30C8(lbl_8034D39C, arg0,
                 arg1 < 0 ? lbl_8034D3C0 : lbl_8055D1D8);
    lbl_804FC800[arg0 * 0x2C] = 0;
    if (arg1 >= 0) fn_80060CC0(arg0, 1, (void (*)())fn_802E5248);
}

extern int OSRestoreInterrupts(int);
extern int WPADCanSendStreamData(int);
extern unsigned char fn_802E86B4(int);
extern int AXRmtGetSamples(int, short *, int);
extern void WENCGetEncodeData(void *, int, short *, int, void *);
extern void fn_80062278(int, void *, int);
extern void AXRmtAdvancePtr(int);
extern unsigned char lbl_804FC6C0[];
extern int lbl_8055FFA8;
#pragma push
#pragma use_lmw_stmw off
void fn_802E52EC(void) {
    unsigned char *entry = lbl_804FC800;
    short *samples = (short *)lbl_804FC6C0;
    int i;
    int any;
    int zero = 0;
    int one = 1;

    any = 0;
    i = 0;
    do {
        int state = OSDisableInterrupts();
        if (WPADCanSendStreamData(i) && fn_802E86B4(i) > 0x55 &&
            AXRmtGetSamples(i, samples, 0x28) == 0x28) {
            any = 1;
            if (entry[0] && (lbl_8055FFA8 & (one << i))) {
                unsigned char buf[0x14];
                int active = *(int *)(entry + 0x24);
                int encode = active == 0;
                if (active) *(int *)(entry + 0x24) = zero;
                WENCGetEncodeData(entry + 1, encode, samples, 0x28, buf);
                fn_80062278(i, buf, 0x14);
            } else {
                *(int *)(entry + 0x24) = one;
            }
        }
        OSRestoreInterrupts(state);
        i++;
        entry += 0x2C;
        samples += 0x28;
    } while (i < 4);
    if (any) AXRmtAdvancePtr(0x28);
}
#pragma pop
int fn_802E540C(int arg0) {
    if (arg0 == 1) TRKReadBuffer_ui32();
    return 0;
}

void fn_802E56F0(void) {
    extern void OSCancelAlarm(void *);
    extern void fn_802E6B34(void);
    extern void TRKGetFreeBuffer(int);
    extern void TRKConstructEvent(void);
    extern void fn_80128658(void *);
    extern char lbl_8034D450[];
    extern char lbl_8034D470[];
    extern unsigned char lbl_804FC690[];
    extern char lbl_8055FFA5;
    extern int lbl_8055FF84;
    extern void *lbl_8055FFB0;
    int offset;
    int i;
    int offset2;

    OSCancelAlarm(lbl_804FC690);
    lbl_8055FFA5 = 0;
    fn_802E6B34();
    i = 0;
    offset = 0;
    do {
        unsigned char *entry = lbl_8055FF94 + offset;
        if (entry[0x20] != 0) {
            fn_802E317C(lbl_8034D450, *(int *)(entry + 0x1C));
        }
        TRKGetFreeBuffer(*(int *)(lbl_8055FF94 + offset + 4));
        i++;
        *(int *)(lbl_8055FF94 + offset + 4) = 0;
        offset += 0x2C;
    } while (i < 0x20);

    offset2 = 0;
    i = 0;
    do {
        unsigned char *sample = (unsigned char *)lbl_8055FF90 + offset2;
        if (*(int *)(sample + 0x94) > 0) {
            fn_802E317C(lbl_8034D470, sample);
        }
        i++;
        offset2 += 0xB0;
    } while (i < 0x100);

    fn_80128670((int)lbl_8055FF94);
    lbl_8055FF94 = 0;
    fn_80128670((int)lbl_8055FF90);
    lbl_8055FF90 = 0;
    fn_80128670((int)lbl_8055FF9C);
    lbl_8055FF9C = 0;
    TRKReadBuffer_ui32();
    TRKConstructEvent();
    lbl_8055FF84 = 0;
    if (lbl_8055FFB0 != 0) {
        fn_80128658(lbl_8055FFB0);
        lbl_8055FFB0 = 0;
    }
}

void fn_802E5824(void) {
}

void fn_802E5828(void) {
}

#pragma dont_inline on
#pragma scheduling invalid_target
int fn_802E582C(void) {
    if (lbl_8055FFA0 < 0x100) {
        lbl_8055FF9C[lbl_8055FFA0] = fn_802E5AE8();
        if (lbl_8055FF9C[lbl_8055FFA0] == 0)
            return 0;
        lbl_8055FFA0 = lbl_8055FFA0 + 1;
        return 1;
    }
    return 0;
}
#pragma scheduling on
#pragma dont_inline reset

#pragma dont_inline fn_802E582C
void fn_802E589C(void) {
    fn_802E582C();
}

extern unsigned char lbl_804FC558[];
extern int lbl_8055FF78;
extern int lbl_8055FFA0;
extern int *lbl_8055FF9C;
extern int fn_802E5AE8(void);
extern void fn_8012BEF0(unsigned char *);
extern void fn_8012C41C(void (*)(void), int, unsigned char *);
extern int fn_802E582C(void);
#pragma dont_inline fn_802E582C
int fn_802E58A0(void *arg0, int arg1) {
    if (arg1 == 0x53465830) return fn_802E582C();
    return 1;
}

void fn_802E58B8(unsigned char *arg0) {
       int index;
       char *src;
       unsigned char *dst;
       register volatile unsigned short count = 0x20;
       char value;
       index = lbl_8055FF78;
       *(volatile int *)&lbl_8055FF78 = index + 1;
       dst = lbl_804FC558 + (index << 5);
       src = (char *)arg0;
       do {
           count--;
       } while (count != 0);
       dst[-1] = 0;
       do {
           value = *src++;
           *dst++ = (unsigned char)value;
       } while (value != 0);
       fn_8012BEF0(arg0);
       fn_8012C41C(fn_802E589C, 0, arg0);
   }

extern int sprintf(char *, const char *, ...);
#pragma scheduling invalid_target
void fn_802E5950(int arg0, int arg1) {
    char buffer[0x108];

    sprintf(buffer, lbl_8055D1E4, arg0, arg1);
    ((void (*)(char *, char *, ...))fn_802E30C8)(lbl_8034D490, buffer);
    if (((int (*)(char *))fn_802E582C)(buffer) == 0) {
        ((void (*)(char *, char *, ...))fn_802E30C8)(lbl_8034D4A0, buffer);
    }
}
#pragma scheduling on
void fn_802E59BC(unsigned char *arg0) {
    int index = lbl_8055FF78;
    unsigned char *dst = lbl_804FC558 + (index << 5);
    unsigned char *src = arg0;
    int count = 0x20;
    lbl_8055FF78 = index + 1;
    while (count > 0) {
        count--;
    }
    *--dst = 0;
    while ((signed char)*src != 0) {
        *dst++ = *src++;
    }
    fn_8012BEF0(arg0);
    fn_8012C41C((void (*)())fn_802E58A0, 0, arg0);
}

void fn_802E5A54(void) {
    unsigned char *ptr;
    int i;
    for (i = 0; i < lbl_8055FFA0; i++) {
        fn_802E5D5C(lbl_8055FF9C[i]);
    }
    lbl_8055FFA0 = 0;
    for (ptr = lbl_804FC558, i = 0; i < lbl_8055FF78; i++, ptr += 0x20) {
        fn_8012BF24(ptr);
    }
    lbl_8055FF78 = 0;
}

extern void *lbl_8055FF90;
extern float lbl_80565128, lbl_80565148;
extern char lbl_8034D554[], lbl_8034D578[];
extern void fn_801282EC(int);
extern void fn_801282F4(void);
extern void *fn_8012850C(void *, char *);

void *fn_802E5DD8(const char *arg0, unsigned int arg1, int arg2, int arg3, int arg4) {
    int i, index = -1;
    unsigned char *base = (unsigned char *)lbl_8055FF90, *slot, *dst;
    const char *src = arg0;
    for (i = 0; i < 0x20; i++) if (*(int *)(base + i * 0x50 + 0x94) == 0) { index = i; break; }
    if (index < 0) fn_802E317C(lbl_8034D554, (int)arg0, (void *)0);
    slot = base + index * 0xB0;
    memset(slot, 0, 0xB0);
    fn_801282EC(0x80); fn_801282F4();
    *(void **)(slot + 0x90) = fn_8012850C((void *)arg1, lbl_8034D578);
    memset(*(void **)(slot + 0x90), 0, arg1);
    slot[0x25] = 1;
    *(void **)(slot + 0x9C) = (void *)((unsigned int)*(void **)(slot + 0x90) + 0x80000000);
    *(unsigned int *)(slot + 0xA0) = arg1;
    *(int *)(slot + 0x94) = 1; *(int *)(slot + 0x20) = 1;
    slot[0x24] = (arg2 == 1);
    *(int *)(slot + 0x88) = arg3; *(int *)(slot + 0x8C) = arg4; *(int *)(slot + 0x98) = 0;
    *(float *)(slot + 0xA8) = lbl_80565128; *(float *)(slot + 0xA4) = lbl_80565148;
    dst = slot; i = 0x20;
    do { unsigned char c = *src++; *dst++ = c; if ((signed char)c == 0) break; if (--i <= 0) { dst[-1] = 0; break; } } while (1);
    return slot;
}

void fn_802E5FE4(void *arg0) {
    if (*(int *)((char *)arg0 + 0x98) > 0) {
        ((void (*)(char *, void *, ...))fn_802E317C)(lbl_8034D584, arg0);
    }
    fn_80128670(*(int *)((char *)arg0 + 0x90));
    *(int *)((char *)arg0 + 0x90) = 0;
    *(int *)((char *)arg0 + 0x94) = 0;
}

float fn_802E6040(void *arg0) {
    if (arg0 != 0) return *(float *)((char *)arg0 + 0xA4);
    return lbl_8056512C;
}

extern unsigned char *lbl_8055FF94;
extern int OSDisableInterrupts(void);
extern int OSEnableInterrupts(int);
__declspec(section ".sdata") extern unsigned char *lbl_8055FF94;
#pragma scheduling invalid_target
void *fn_802E6058(void *arg0) {
    unsigned char *entry;
    register int i;
    unsigned int unsignedIndex;
    unsigned int shifted;
    float zeroValue;
    float oneValue;

    for (i = 0; i < 0x20; i++) {
        unsignedIndex = (unsigned int)i;
        shifted = unsignedIndex << 27;
        entry = lbl_8055FF94 +
                (((((shifted - (unsignedIndex >> 31)) << 5) |
                   ((shifted - (unsignedIndex >> 31)) >> 27)) +
                  (unsignedIndex >> 31)) * 0x2C);
        if (entry[0x20] == 0) {
            OSDisableInterrupts();
            entry[0x20] = 1;
            oneValue = lbl_80565128;
            zeroValue = lbl_8056512C;
            *(void **)(entry + 0x1C) = arg0;
            *(float *)(entry + 8) = oneValue;
            *(float *)(entry + 0xC) = zeroValue;
            *(float *)(entry + 0x14) = oneValue;
            *(int *)(entry + 0x18) = 0;
            *(float *)(entry + 0x10) = *(float *)((char *)arg0 + 0xA8);
            entry[0x23] = 0;
            entry[0x25] = 0;
            *(int *)((char *)arg0 + 0x98) += 1;
            entry[0x21] = 1;
            entry[0x22] = 0;
            *(int *)(entry + 0x28) = 0;
            ((void (*)(void))OSEnableInterrupts)();
            ++lbl_8055FF98;
            return entry;
        }
    }
    return 0;
}
#pragma scheduling on
void fn_802E6138(void *arg0) {
    if (((unsigned char *)arg0)[0x23] != 0) {
        fn_802E317C(lbl_8034D5B0, *(int *)arg0, *(void **)((char *)arg0 + 0x1C));
    }
    {
        void *temp_r4 = *(void **)((char *)arg0 + 0x1C);
        *(int *)((char *)temp_r4 + 0x98) -= 1;
    }
    ((unsigned char *)arg0)[0x20] = 0;
    lbl_8055FF98 -= 1;
}

void fn_802E61A8(void *arg0) {
    ((unsigned char *)arg0)[0x25] = 0;
    ((unsigned char *)arg0)[0x23] = 1;
}

void fn_802E61BC(void *arg0) {
    if (((unsigned char *)arg0)[0x23] == 0) {
        ((unsigned char *)arg0)[0x25] = 1;
        ((unsigned char *)arg0)[0x23] = 1;
    }
}

void fn_802E61D8(void *arg0) {
    ((unsigned char *)arg0)[0x23] = 0;
}

void fn_802E61E4(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 8) = farg0;
}

void fn_802E61EC(void *arg0, float farg0) {
    if (lbl_8055FF8C != 0) {
        *(float *)((char *)arg0 + 0xC) = farg0;
        return;
    }
    *(float *)((char *)arg0 + 0xC) = lbl_8056512C;
}

void fn_802E620C(void *arg0, float farg0) {
    if ((int)lbl_8055FF8C == 2) {
        *(float *)((char *)arg0 + 0x14) = farg0;
        return;
    }
    *(float *)((char *)arg0 + 0x14) = lbl_80565128;
}

void fn_802E622C(void *arg0, float farg0) { *(float *)((char *)arg0 + 0x10) = farg0; }

void fn_802E6234(void) {}

void fn_802E6238(void) {}

void fn_802E623C(void) {}

void fn_802E6240(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

void fn_802E6248(int arg0, float arg1) {
    lbl_804FC680[arg0] = arg1;
}

void fn_802E625C(void* hi) {
    lbl_8055FF8C = hi;
}

int* fn_802E6ABC(void) {
    return &lbl_8055D1EC;
}

void fn_802E6AC4(void) {
    lbl_8055FFB5 = 1;
}

int fn_802E6AD0(int arg0) {
    if (arg0 == 1) {
        fn_802E7774(fn_802E6AC4);
    }
    return 0;
}

#pragma scheduling invalid_target
void fn_802E6B04(void) {
    fn_802E7770();
    fn_802E2E0C(fn_802E6AD0, &lbl_8055D1F0);
}
#pragma scheduling on
void fn_802E6B34(void) {
}

void fn_802E6B38(void* arg0, signed char* arg1) {
    *arg1 = 0;
}

#pragma dont_inline on
void fn_802E6B44(int arg0, int arg1) {
    fn_802E5264(arg0, arg1);
}
#pragma dont_inline reset
