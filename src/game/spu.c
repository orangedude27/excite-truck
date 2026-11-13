// spu — SPU voice channels ("Spu: channel %d/%s is still playing").
// Recovered TU window 0x802E4D84..0x802E6B48 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E6B48 (+ .ctors slot 0x802ED604) remains in
// auto/text_802E6B48_.c pending a promotion pass.
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
extern void *fn_802E5AE8();
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
#define VU8(o) (*(unsigned char *)(v + (o)))
#define VF(o) (*(float *)(v + (o)))
#define VI(o) (*(int *)(v + (o)))
#define SI(o) (*(int *)(s + (o)))
#define SU(o) (*(unsigned int *)(s + (o)))
void fn_802E4D84(void *dst, void *src, int size) {
    void *saved_dst = dst;
    int saved_size = size;
    memcpy(saved_dst, src, saved_size);
    DCFlushRange(saved_dst, saved_size);
}

extern unsigned char *fn_8012C370(int, unsigned int *, int, unsigned char *, unsigned char *);
extern char lbl_8034D280[];
#pragma scheduling invalid_target
/* Load an SFX0 sample blob by name: endian-swap its header when the loader says so, relocate its data offset into a pointer, byte-swap 16-bit sample data for non-raw formats, then flush it for the ARAM/DSP reader. */
void *fn_802E4DC8(char *path) {
    unsigned int version;
    unsigned char attr;
    unsigned char needsSwap;
    unsigned char *sfx;
    unsigned char *samples;
    unsigned char tmp;
    int i;
    register int adjusted;
    register int length;

    sfx = ((unsigned char *(*)(char *, unsigned int, unsigned int *, int, unsigned char *, unsigned char *))fn_8012C370)(
        path, 0x53465830 /* 'SFX0' */, &version, 0, &attr, &needsSwap);
    if (sfx == 0) goto return_null;
    if (version != 3) fn_802E317C(lbl_8034D280, path, version, 3);
    if (needsSwap != 0) {
        tmp=sfx[0]; sfx[0]=sfx[3]; sfx[3]=tmp;
        tmp=sfx[1]; sfx[1]=sfx[2]; sfx[2]=tmp;
        tmp=sfx[4]; sfx[4]=sfx[7]; sfx[7]=tmp;
        tmp=sfx[5]; sfx[5]=sfx[6]; sfx[6]=tmp;
        tmp=sfx[12]; sfx[12]=sfx[13]; sfx[13]=tmp;
        tmp=sfx[14]; sfx[14]=sfx[15]; sfx[15]=tmp;
        tmp=sfx[16]; sfx[16]=sfx[19]; sfx[19]=tmp;
        tmp=sfx[17]; sfx[17]=sfx[18]; sfx[18]=tmp;
        tmp=sfx[20]; sfx[20]=sfx[23]; sfx[23]=tmp;
        tmp=sfx[21]; sfx[21]=sfx[22]; sfx[22]=tmp;
        tmp=sfx[24]; sfx[24]=sfx[25]; sfx[25]=tmp;
        tmp=sfx[26]; sfx[26]=sfx[27]; sfx[27]=tmp;
        tmp=sfx[28]; sfx[28]=sfx[29]; sfx[29]=tmp;
        *(unsigned int *)(sfx+4) = (unsigned int)(sfx + *(unsigned int *)(sfx+4));
        if (*(unsigned short *)(sfx+26) == 16 && sfx[9] != 1) {
            samples = *(unsigned char **)(sfx+4);
            for (i=0; (length=*(int *)sfx, adjusted=((unsigned int)length >> 31),
                       adjusted+=length, i<(adjusted >> 1)); i++) {
                tmp=samples[0];
                samples[0]=samples[1];
                samples[1]=tmp;
                samples+=2;
            }
        }
        DCFlushRange(*(void **)(sfx+4), *(unsigned int *)sfx);
    }
    return sfx;
return_null:
    return 0;
}
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802E4F98(void) {
    // Refill the 0x20 SPU voice buffers: stream each half, wrap at the loop end, flag completion.
    extern char lbl_8055FFA4;
    extern char lbl_8055FFA5;
    extern char lbl_8055FFA6;
    extern char lbl_8055FFB4;
    extern int OSEnableInterrupts(int);
    extern int fn_802D9BF0(void);
    extern void fn_80033AAC(void *, void *);
    register int byteOff;
    register int savedInts;
    register int voiceIdx;
    int silent;
    unsigned char *voice;
    unsigned char *stream;
    unsigned int playPos;
    unsigned int halfSize;
    unsigned int wrapPos;
    short initSamp[3];

    if ((unsigned char)lbl_8055FFA5 != 0 &&
        (unsigned char)lbl_8055FFA6 == 0) {
        savedInts = ((int (*)(void))OSEnableInterrupts)();
        silent = fn_802D9BF0();
        lbl_8055FFB4 = 1;
        voiceIdx = 0;
        byteOff = 0;
        do {
            voice = lbl_8055FF94 + byteOff;
            stream = *(unsigned char **)(voice + 0x1C);
            if (voice[0x20] != 0 && stream != 0 &&
                *(int *)(stream + 0x20) == 1 && voice[0x21] == 0) {
                playPos = *(unsigned int *)(*(unsigned char **)(voice + 4) + 0x1BC);
                if (stream[0x24] != 0) {
                    playPos >>= 1;
                } else {
                    playPos <<= 1;
                }
                halfSize = *(unsigned int *)(stream + 0xA0) >> 1;
                wrapPos = *(unsigned int *)(stream + 0x9C) + halfSize;
                if (playPos < *(unsigned int *)(voice + 0x28)) {
                    if (silent == 0) {
                        ((void (*)(void *, unsigned int, void *))*(void **)(stream + 0x88))(
                            (unsigned char *)*(void **)(stream + 0x90) + halfSize,
                            halfSize, *(void **)(stream + 0x8C));
                    } else {
                        memset((unsigned char *)*(void **)(stream + 0x90) + halfSize, 0, halfSize);
                    }
                    DCFlushRange((unsigned char *)*(void **)(stream + 0x90) + halfSize, halfSize);
                }
                if (playPos >= wrapPos && *(unsigned int *)(voice + 0x28) < wrapPos) {
                    if (silent == 0) {
                        ((void (*)(void *, unsigned int, void *))*(void **)(stream + 0x88))(
                            *(void **)(stream + 0x90),
                            halfSize, *(void **)(stream + 0x8C));
                    } else {
                        memset(*(void **)(stream + 0x90), 0, halfSize);
                    }
                    if (stream[0x24] != 0) {
                        initSamp[0] = (short)*((unsigned char *)*(void **)(stream + 0x90));
                        initSamp[1] = 0;
                        initSamp[2] = 0;
                        fn_80033AAC(*(void **)(voice + 4), initSamp);
                    }
                    DCFlushRange(*(void **)(stream + 0x90), halfSize);
                }
                *(unsigned int *)(voice + 0x28) = playPos;
            }
            ++voiceIdx;
            byteOff += 0x2C;
        } while (voiceIdx < 0x20);
        *(volatile unsigned char *)&lbl_8055FFA4 = 1;
        *(volatile unsigned char *)&lbl_8055FFB4 = 0;
        OSRestoreInterrupts(savedInts);
    }
}
#pragma scheduling on
#pragma pop

extern float lbl_80565130;
extern float lbl_80565134;
#pragma dont_inline fn_802E5168
unsigned short fn_802E5168(float arg0) {
    float value = lbl_80565130 * arg0;
    float adjusted;
    int converted;
    int result;
    if (value < lbl_8056512C) {
        adjusted = value - lbl_80565134;
    } else {
        adjusted = lbl_80565134 + value;
    }
    converted = (int)adjusted;
    result = converted & ((-converted & ~converted) >> 31);
    if (result >= 0x8000) {
        result = 0x8000;
    }
    return (unsigned short)result;
}

#pragma scheduling invalid_target
void fn_802E51D0(int arg0, int arg1) {
    unsigned char *entry;
    if (arg1 != 0) {
        return;
    }
    lbl_804FC800[arg0 * 0x2C] = 1;
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

#ifndef SPK_STREAM_MOVED_UP
/* One Wii remote speaker stream, 0x2C bytes per channel at lbl_804FC800;
 * fn_802E51D0 opens one (fn_802E5264 closes it again). */
struct SpkStream {
    unsigned char enabled;   /* +0x00: the channel's speaker stream is open */
    unsigned char enc[0x20]; /* +0x01: the WENCInfo ADPCM encoder state (wenc.h) */
    int restart;             /* +0x24: encode the next frame from scratch */
    int unk_28;              /* +0x28: cleared when the stream is opened */
};
#endif

extern int OSRestoreInterrupts(int);
extern int WPADCanSendStreamData(int);
extern unsigned char fn_802E86B4(int); /* the remote's radio quality, 0-100 */
extern int AXRmtGetSamples(int, short *, int);
extern void WENCGetEncodeData(void *, int, short *, int, void *);
extern void fn_80062278(int, void *, int); /* WPADSendStreamData(chan, data, len) */
extern void AXRmtAdvancePtr(int);
extern unsigned char lbl_804FC6C0[]; /* the AX remote-speaker mix, 0x28 samples per channel */
extern int lbl_8055FFA8;             /* channels whose voices used a speaker lately */
#pragma push
#pragma use_lmw_stmw off
/* Remote-speaker pump, the callback of the periodic OS alarm fn_802E5478 arms:
 * for each of the 4 Wii remote channels that can take stream data, whose radio
 * quality is still good and whose speaker mix has a full frame, it reads 0x28
 * samples out of the AX remote mix, ADPCM-encodes them with the channel's WENC
 * state and queues them to the remote as stream data.  A channel whose stream
 * is open but that was skipped marks its encoder to restart on the next frame;
 * the mix pointer is advanced once, after all channels, if any of them read. */
void fn_802E52EC(void) {
    struct SpkStream *stream = (struct SpkStream *)lbl_804FC800;
    short *samples = (short *)lbl_804FC6C0;
    int chan;
    int sent;
    int zero = 0;
    int one = 1;

    sent = 0;
    chan = 0;
    do {
        int intr = OSDisableInterrupts();
        if (WPADCanSendStreamData(chan) && fn_802E86B4(chan) > 0x55 &&
            AXRmtGetSamples(chan, samples, 0x28) == 0x28) {
            sent = 1;
            if (stream->enabled && (lbl_8055FFA8 & (one << chan))) {
                unsigned char adpcm[0x14];
                int restart = stream->restart;
                int continuing = restart == 0;
                if (restart) stream->restart = zero;
                WENCGetEncodeData(stream->enc, continuing, samples, 0x28, adpcm);
                fn_80062278(chan, adpcm, 0x14);
            } else {
                stream->restart = one;
            }
        }
        OSRestoreInterrupts(intr);
        chan++;
        stream++;
        samples += 0x28;
    } while (chan < 4);
    if (sent) AXRmtAdvancePtr(0x28);
}
#pragma pop
int fn_802E540C(int arg0) {
    if (arg0 == 1) TRKReadBuffer_ui32();
    return 0;
}

extern void fn_802E6248(int, float);
#pragma dont_inline fn_802E5438
void fn_802E5438(void) {
    int i;
    i = 0;
    do {
        fn_802E6248(i, fn_802E9A2C());
        i++;
    } while (i < 4);
}

void fn_802E5478(void) {
    extern char lbl_8034D210[];
    extern int lbl_8055FF7C, lbl_8055FF80, lbl_8055FF84, lbl_8055FF88;
    extern void *lbl_8055FFB0;
    extern unsigned char lbl_804FC690[];
    extern char lbl_8055D1E0;
    extern char lbl_8055FFA5;
    extern float lbl_804FC680[4];
    extern void fn_801282F4(void);
    extern void fn_801282EC(int);
    extern int fn_801284E8(char *, int);
    extern void *fn_8012850C(void *, char *);
    extern void DCInvalidateRange(void *, unsigned int);
    extern void TRKPostEvent(int);
    extern void TRKMessageSend(void);
    extern void fn_80031C6C(int);
    extern int TRKInitializeMessageBuffers(int, int, int);
    extern void AXSetVoiceState(int, int);
    extern void fn_80033538(int, int);
    extern void AIRegisterDMACallback(void *);
    extern void fn_802E6B04(void);
    extern void OSCreateAlarm(void *);
    extern long long OSGetTime(void);
    extern void OSSetPeriodicAlarm(void *, long long, long long, void *);
    extern void fn_802E5438(void);
    char *msg = lbl_8034D210;
    int off, i;
    int voice, tmp;
    char *buf;
    long long now;
    float one;

    ((void (*)(char *, ...))fn_802E30C8)(msg + 0x1BC);
    lbl_8055FF8C = (void *)1;
    lbl_8055FF84 = 0x20000;
    fn_801282F4();
    tmp = fn_801284E8(msg + 0x1C8, lbl_8055FF84);
    lbl_8055FFB0 = (void *)tmp;
    lbl_8055FF7C = tmp;
    lbl_8055FF80 = tmp;
    DCInvalidateRange((void *)lbl_8055FF80, lbl_8055FF84);
    ((void (*)(char *, ...))fn_802E30C8)(msg + 0x1D4, lbl_8055FF80, lbl_8055FF84, (unsigned int)lbl_8055FF84 >> 10);
    TRKPostEvent(0);
    TRKMessageSend();
    fn_80031C6C(0);
    lbl_8055FF90 = fn_8012850C((void *)0xB000, msg + 0x1F4);
    lbl_8055FF94 = (unsigned char *)fn_8012850C((void *)0x580, msg + 0x200);
    lbl_8055FF9C = (int *)fn_8012850C((void *)0x400, msg + 0x20C);
    lbl_8055FFA0 = 0;
    memset(lbl_8055FF90, 0, 0xB000);
    memset(lbl_8055FF94, 0, 0x580);
    i = 0;
    off = 0;
    do {
        voice = TRKInitializeMessageBuffers(0x1F, 0, 0);
        if (voice == 0) fn_802E317C(msg + 0x218, i);
        AXSetVoiceState(voice, 0);
        fn_80033538(voice, 0);
        *(int *)(lbl_8055FF94 + off) = i;
        i++;
        *(int *)(lbl_8055FF94 + off + 4) = voice;
        off += 0x2C;
    } while (i < 0x20);
    lbl_8055FF88 = lbl_8055FF7C + (lbl_8055FF84 - 0x20000);
    fn_801282EC(0x20);
    buf = (char *)fn_8012850C((void *)0x20000, msg + 0x234);
    memset(buf, 0, 0x20000);
    ((void (*)(void *, void *, int, int))fn_802E4D84)((void *)lbl_8055FF88, buf, 0x20000, 1);
    fn_80128670((int)buf);
    AIRegisterDMACallback((void *)fn_802E4F98);
    fn_802E6B04();
    OSCreateAlarm(lbl_804FC690);
    now = OSGetTime();
    OSSetPeriodicAlarm(lbl_804FC690, now, (unsigned int)(((*(unsigned int *)0x800000F8 >> 2) / 125000 * 0x65B9AB) / 8000), (void *)fn_802E52EC);
    one = lbl_80565128;
    lbl_804FC680[0] = one;
    lbl_804FC680[1] = one;
    lbl_804FC680[2] = one;
    lbl_804FC680[3] = one;
    fn_802E2E0C((void *)fn_802E540C, &lbl_8055D1E0);
    lbl_8055FFA5 = 1;
    ((void (*)(void))fn_802E5438)();
}

/* One of the 32 voice channels of the pool at lbl_8055FF94 (0x580 bytes),
 * built by fn_802E5478 and walked by the per-frame mixer fn_802E5C2C. */
struct SpuChannel {
    int index;                  /* +0x00: channel number */
    void *voice;                /* +0x04: voice object from the pool allocator */
    unsigned char pad08[0x14];  /* +0x08 */
    struct SpuSample *sample;   /* +0x1C: sample this channel plays, 0 when free */
    unsigned char active;       /* +0x20: channel is handed out */
    unsigned char playing;      /* +0x21: asked to play */
    unsigned char started;      /* +0x22: voice was started for it */
    unsigned char wantPlay;     /* +0x23: still wants to play */
    unsigned char wasPlaying;   /* +0x24: playing last frame */
    unsigned char adpcm;        /* +0x25: ADPCM (vs 16-bit) stream */
    unsigned char pad26[2];
    unsigned int playPos;       /* +0x28: DSP play position of the last frame */
};

/* One of the 256 sample slots of the pool at lbl_8055FF90 (0xB000 bytes),
 * filled by fn_802E5AE8 and released by fn_802E5D5C. */
struct SpuSample {
    char name[0x20];            /* +0x00: file name, without its directory */
    int streamState;            /* +0x20: 1 while the sample is streamed */
    unsigned char unk24;        /* +0x24: ADPCM loop data present */
    unsigned char unk25;        /* +0x25 */
    unsigned char pad26[2];
    unsigned char loop[0x60];   /* +0x28: loop/ADPCM info copied from the blob */
    void *decode;               /* +0x88: decode(streamBuffer, len, decodeArg) */
    void *decodeArg;            /* +0x8C */
    void *streamBuffer;         /* +0x90: ring buffer fed to the DSP */
    int refCount;               /* +0x94: channels holding this sample */
    int unk98;                  /* +0x98: instances still playing */
    unsigned int unk9C;         /* +0x9C: format/rate code of the blob */
    unsigned int size;          /* +0xA0: byte size, 0x40-aligned */
    float fA4;                  /* +0xA4 */
    float fA8;                  /* +0xA8 */
    void *res;                  /* +0xAC: the loaded SFX0 blob */
};

/* Shuts the SPU layer down (the counterpart of fn_802E5478): stops the
 * speaker-stream alarm and the mixer hook, then checks the pools for leaks --
 * any channel still handed out or sample still referenced panics with
 * "Spu: channel %s still in use" / "Spu: sample %s still in use" -- hands each
 * channel's voice object back to the allocator, frees the channel, sample and
 * slot pools, resets the debugger event state and the mix buffer size, and
 * frees the mix buffer itself. */
void fn_802E56F0(void) {
    extern void OSCancelAlarm(void *);
    extern void fn_802E6B34(void);
    extern void TRKGetFreeBuffer(void *);
    extern void TRKConstructEvent(void);
    extern void fn_80128658(void *);
    extern char lbl_8034D450[]; /* "Spu: channel %s still in use" */
    extern char lbl_8034D470[]; /* "Spu: sample %s still in use" */
    extern unsigned char lbl_804FC690[]; /* alarm for the speaker stream */
    extern char lbl_8055FFA5;   /* SPU layer running */
    extern int lbl_8055FF84;    /* mix buffer size */
    extern void *lbl_8055FFB0;  /* mix buffer */
    int offset;
    int i;
    int count;
    OSCancelAlarm(lbl_804FC690);
    lbl_8055FFA5 = 0;
    fn_802E6B34();
    i = 0;
    offset = 0;
    do {
        struct SpuChannel *channel = (struct SpuChannel *)(lbl_8055FF94 + offset);
        if (channel->active != 0) {
            fn_802E317C(lbl_8034D450, channel->sample);
        }
        /* the voice object is reached through the pool base each time */
        TRKGetFreeBuffer(((struct SpuChannel *)(lbl_8055FF94 + offset))->voice);
        i++;
        ((struct SpuChannel *)(lbl_8055FF94 + offset))->voice = 0;
        offset += 0x2C;
    } while (i < 0x20);
    count = 0;
    i = 0;
    do {
        struct SpuSample *sample = (struct SpuSample *)((unsigned char *)lbl_8055FF90 + i);
        if (sample->refCount > 0) {
            fn_802E317C(lbl_8034D470, sample->name);
        }
        count++;
        i += 0xB0;
    } while (count < 0x100);
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
        lbl_8055FF9C[lbl_8055FFA0] = (int)fn_802E5AE8();
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

extern void fn_802E5D5C(void *);
void fn_802E5A54(void) {
    /* Shut down SPU state: release each tracked object in lbl_8055FF9C
     * (count lbl_8055FFA0) via fn_802E5D5C, then finalize each 0x20-byte entry
     * in lbl_804FC558 (count lbl_8055FF78) via fn_8012BF24, clearing counts. */
    int i, j;
    unsigned char *ptr;
    for (i = 0; i < lbl_8055FFA0; i++) {
        fn_802E5D5C((void *)lbl_8055FF9C[i]);
    }
    lbl_8055FFA0 = 0;
    for (j = 0, ptr = lbl_804FC558; j < lbl_8055FF78; ptr += 0x20, j++) {
        fn_8012BF24(ptr);
    }
    lbl_8055FF78 = 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_802E5AE8(char *arg0) {
    extern char lbl_8034D210[];
    extern float lbl_80565138, lbl_8056513C;
    extern char *fn_80029004(char *, int);
    extern int stricmp(const char *, const char *);
    extern char *strcpy(char *, const char *);
    struct Res {
        unsigned int size;
        unsigned int unk4;
        unsigned char unk8;
        unsigned char unk9;
        short unkA;
        unsigned short unkC;
        short unkE;
        unsigned int unk10;
        unsigned char pad14[0xC];
        unsigned char data[0x60];
    };
    char *msg = lbl_8034D210;
    char *name;
    char *found;
    int off, i, freeIdx;
    unsigned int unk4, aligned;
    float f31, f30;
    struct Res *res;
    unsigned char *slot;
    unsigned char flag;
    int tmp;

    found = fn_80029004(arg0, 0x2F);
    if (found != 0) name = found + 1;
    else name = arg0;
    freeIdx = -1;
    i = 0;
    off = 0;
    for (; i < 0x100; i++, off += 0xB0) {
        slot = (unsigned char *)lbl_8055FF90 + off;
        if (*(int *)(slot + 0x94) != 0) {
            if (stricmp(name, (char *)slot) == 0 && *(int *)((unsigned char *)lbl_8055FF90 + off + 0x20) == 0) {
                slot = (unsigned char *)lbl_8055FF90 + i * 0xB0;
                *(int *)(slot + 0x94) = *(int *)(slot + 0x94) + 1;
                return (unsigned char *)lbl_8055FF90 + i * 0xB0;
            }
        } else if (freeIdx < 0) {
            freeIdx = i;
        }
    }
    if (freeIdx < 0) fn_802E317C(msg + 0x2A8, arg0);
    res = (struct Res *)fn_802E4DC8(arg0);
    if (res == 0) return 0;
    res->unkC = 0xCFFE;
    if (res->unkC != 0xCFFE) fn_802E317C(msg + 0x2C4, arg0);
    f31 = (float)(res->size >> 1) / lbl_80565138;
    aligned = (res->size + 0x3F) & ~0x3F;
    if (res->unk9 == 1) f31 = f31 * lbl_8056513C;
    slot = (unsigned char *)lbl_8055FF90 + freeIdx * 0xB0;
    f30 = (float)res->unk10 / lbl_80565138;
    memset(slot, 0, 0xB0);
    unk4 = res->unk4;
    if (unk4 & 0x1F) fn_802E317C(msg + 0x2FC, name, unk4);
    *(unsigned int *)(slot + 0xA0) = aligned;
    *(int *)(slot + 0x94) = 1;
    *(int *)(slot + 0x20) = 0;
    tmp = res->unk9;
    flag = (tmp == 1);
    slot[0x24] = flag;
    slot[0x25] = (res->unk8 != 0);
    if (flag) memcpy(slot + 0x28, res->data, 0x60);
    else memset(slot + 0x28, 0, 0x60);
    *(int *)(slot + 0x98) = 0;
    *(float *)(slot + 0xA8) = f30;
    *(float *)(slot + 0xA4) = f31 / f30;
    strcpy((char *)slot, name);
    *(unsigned int *)(slot + 0x9C) = unk4;
    *(void **)(slot + 0xAC) = res;
    return slot;
}

#pragma pop
void fn_802E5D5C(void *arg0) {
    if (*(int *)((char *)arg0 + 0x94) == 1 && *(int *)((char *)arg0 + 0x98) > 0) {
        fn_802E317C(lbl_8034D528, arg0, *(int *)((char *)arg0 + 0x98));
    }
    if ((*(int *)((char *)arg0 + 0x94) -= 1) == 0 && *(int *)((char *)arg0 + 0xAC) != 0) {
        ((void (*)(void *))fn_8012C4D8)(*(void **)((char *)arg0 + 0xAC));
        *(int *)((char *)arg0 + 0xAC) = 0;
    }
}

#pragma ppc_psq_save reset
extern void *lbl_8055FF90;
extern float lbl_80565128, lbl_80565148;
extern char lbl_8034D554[], lbl_8034D578[];
extern void fn_801282EC(int);
extern void fn_801282F4(void);
extern void *fn_8012850C(void *, char *);

void *fn_802E5DD8(const char *arg0, unsigned int arg1, int arg2, int arg3, int arg4) {
    int i, index = -1;
    unsigned char *p = (unsigned char *)lbl_8055FF90;
    char *slot, *dst;
    const char *src = arg0;
    unsigned char c;
    for (i = 0; i < 0x100; p += 0xB0, i++) if (*(int *)(p + 0x94) == 0) { index = i; break; }
    if (index < 0) fn_802E317C(lbl_8034D554, (int)arg0);
    slot = (char *)lbl_8055FF90 + index * 0xB0;
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
    goto copy;
chk:
    if (--i > 0) goto copy;
    dst[-1] = 0;
    goto end;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) goto chk;
end:
    return slot;
}

void fn_802E5FE4(void *arg0) {
    if (*(int *)((char *)arg0 + 0x98) > 0) {
        fn_802E317C(lbl_8034D584, arg0, *(int *)((char *)arg0 + 0x98));
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
    for (i = 0; i < 32; i++) {
        unsignedIndex = (unsigned int)i;
        shifted = unsignedIndex << 27;
        entry = lbl_8055FF94 + (((unsignedIndex >> 31) + (((shifted - (unsignedIndex >> 31)) << 5) | ((shifted - (unsignedIndex >> 31)) >> 27))) * 44);
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

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802E6264(void) {
    extern char lbl_8055FFA4;
    extern char lbl_8055FFA6;
    extern int lbl_8055D1D0;
    extern int lbl_8055FF88;
    extern int lbl_8055FFA8;
    extern int lbl_8055FFAC;
    extern char lbl_8034D210[];
    extern int lbl_804FC658[];
    extern float lbl_80565138, lbl_8056514C, lbl_80565150, lbl_80565154, lbl_80565158;
    extern void AXSetVoiceState(int, int);
    extern int OSRestoreInterrupts(int);
    extern void fn_80031C6C(int);
    extern void fn_80033408(void *, int);
    extern void fn_80033538(int, int);
    extern void fn_80033584(void *, void *);
    extern void fn_800337C4(void *, void *);
    extern void fn_8003381C(void *, void *);
    extern void fn_80033918(void *, void *);
    extern void fn_800339B0(void *, void *);
    extern void fn_80033A34(void *, float);
    extern void fn_80033C8C(void *, int);
    extern void fn_80033CD8(void *, void *);
    extern int fn_802D9BF0(void);
    extern int fn_802ECC10(void);
    char *msg = lbl_8034D210;
    unsigned char *v;
    unsigned char *s;
    int mixed;
    int irq;
    int i;
    int off;
    int flags;
    int wasPlaying;
    unsigned int r16;
    unsigned short sp8[2];
    unsigned short spC[2];
    unsigned short sp10[8];
    unsigned short sp20[8];
    unsigned short sp30[8];
    unsigned short sp40[8];
    unsigned short sp50[8];
    unsigned short sp60[16];
    unsigned short sp80[24];
    unsigned short spB0[20];
    unsigned short spD8[20];
    unsigned int sp100[24];
    float f0, f1, f2, f4;
    float one, inv, k4C, k50, k54, k58;
    if ((unsigned char)lbl_8055FFA4 != 0) {
        lbl_8055FFA4 = 0;
        lbl_8055FFA6 = 1;
        flags = 0;
        if ((int)lbl_8055FF8C != lbl_8055D1D0) {
            lbl_8055D1D0 = (int)lbl_8055FF8C;
            ((void (*)(char *, ...))fn_802E30C8)(msg + 0x3C4);
            switch ((int)lbl_8055FF8C) {
            case 0:
            case 1:
                fn_80031C6C(0);
                break;
            case 2:
                fn_80031C6C(2);
                break;
            default:
                ((void (*)(char *, ...))fn_802E317C)(msg + 0x3E0);
                break;
            }
        }
        mixed = 1;
        if (fn_802ECC10() == 0 && fn_802D9BF0() == 0) mixed = 0;
        irq = OSDisableInterrupts();
        one = lbl_80565128;
        inv = lbl_80565138;
        k4C = lbl_8056514C;
        k50 = lbl_80565150;
        k58 = lbl_80565158;
        k54 = lbl_80565154;
        i = 0;
        off = 0;
        do {
            v = lbl_8055FF94 + off;
            wasPlaying = VU8(0x24);
            VU8(0x24) = VU8(0x23);
            if ((wasPlaying != 0 && VU8(0x23) == 0) || (VU8(0x21) != 0 && VU8(0x22) == 0)) {
                AXSetVoiceState(VI(4), 0);
                wasPlaying = 0;
                memset(&spC[0], 0, 4);
                fn_800337C4(*(void **)(v + 4), &spC[0]);
            }
            if (VU8(0x20) != 0) {
                if (VU8(0x21) != 0 && VU8(0x22) == 0) {
                    VU8(0x22) = 1;
                } else {
                    if (VU8(0x21) != 0 && VU8(0x23) != 0) {
                        VU8(0x21) = 0;
                        wasPlaying = 0;
                        s = *(unsigned char **)(v + 0x1C);
                        if (SI(0x20) == 0 && s[0x24] == 0) {
                            unsigned int u;
                            fn_80033538(VI(4), 0);
                            r16 = (int)SU(0x9C) / 2;
                            memset(&sp50[0], 0, 0x10);
                            sp50[0] = VU8(0x25);
                            sp50[1] = 10;
                            if (VU8(0x25) != 0) {
                                sp50[2] = r16 >> 16;
                                sp50[3] = r16;
                            } else {
                                int h = lbl_8055FF88 / 2;
                                sp50[2] = (unsigned int)h >> 16;
                                sp50[3] = h;
                            }
                            sp50[6] = r16 >> 16;
                            sp50[7] = r16;
                            u = r16 + (int)SU(0xA0) / 2 - 1;
                            sp50[5] = u;
                            sp50[4] = u >> 16;
                            fn_8003381C(*(void **)(v + 4), &sp50[0]);
                        } else if (SI(0x20) == 0 && s[0x24] != 0) {
                            unsigned int u;
                            fn_80033538(VI(4), 0);
                            r16 = SU(0x9C) * 2 + 2;
                            memset(&sp40[0], 0, 0x10);
                            sp40[0] = VU8(0x25);
                            sp40[1] = 0;
                            if (VU8(0x25) != 0) {
                                u = r16 + SU(0x38);
                                sp40[2] = u >> 16;
                                sp40[3] = u;
                            } else {
                                u = lbl_8055FF88 * 2 + 2;
                                sp40[2] = u >> 16;
                                sp40[3] = u;
                            }
                            sp40[6] = r16 >> 16;
                            u = r16 + SU(0x3C) - 2;
                            sp40[5] = u;
                            sp40[4] = u >> 16;
                            sp40[7] = r16;
                            memset(&spD8[0], 0, 0x28);
                            memcpy(&spD8[0], s + 0x44, 0x20);
                            spD8[16] = *(unsigned short *)(s + 0x64);
                            spD8[17] = *(unsigned short *)(s + 0x66);
                            spD8[18] = *(unsigned short *)(s + 0x68);
                            spD8[19] = *(unsigned short *)(s + 0x6A);
                            fn_8003381C(*(void **)(v + 4), &sp40[0]);
                            fn_80033918(*(void **)(v + 4), &spD8[0]);
                        } else if (SI(0x20) == 1 && s[0x24] == 0) {
                            unsigned int u;
                            fn_80033538(VI(4), 0);
                            r16 = (int)SU(0x9C) / 2;
                            memset(&sp30[0], 0, 0x10);
                            sp30[0] = 1;
                            sp30[1] = 10;
                            sp30[2] = r16 >> 16;
                            u = r16 + (SU(0xA0) >> 1) - 1;
                            sp30[3] = r16;
                            sp30[4] = u >> 16;
                            sp30[5] = u;
                            sp30[6] = r16 >> 16;
                            sp30[7] = r16;
                            fn_8003381C(*(void **)(v + 4), &sp30[0]);
                            *(float *)(s + 0xA8) = k4C;
                        } else if (SI(0x20) == 1) {
                            unsigned int u;
                            fn_80033538(VI(4), 1);
                            r16 = SU(0x9C) * 2 + 2;
                            memset(&sp20[0], 0, 0x10);
                            sp20[0] = 1;
                            sp20[1] = 0;
                            sp20[2] = r16 >> 16;
                            sp20[3] = r16;
                            sp20[6] = r16 >> 16;
                            u = r16 + SU(0xA0) * 2 - 3;
                            sp20[7] = r16;
                            sp20[4] = u >> 16;
                            sp20[5] = u;
                            memset(&sp100[0], 0, 0x60);
                            (*(void (**)(void *, unsigned int, int))(s + 0x88))(&sp100[0], 0x60, SI(0x8C));
                            *(float *)(s + 0xA8) = (float)sp100[2] / inv;
                            (*(void (**)(void *, unsigned int, int))(s + 0x88))(*(void **)(s + 0x90), SU(0xA0), SI(0x8C));
                            DCFlushRange(*(void **)(s + 0x90), SU(0xA0));
                            fn_8003381C(*(void **)(v + 4), &sp20[0]);
                            memset(&spB0[0], 0, 0x28);
                            memcpy(&spB0[0], &sp100[7], 0x20);
                            spB0[16] = *(unsigned short *)((char *)sp100 + 0x3C);
                            spB0[17] = *(unsigned short *)((char *)sp100 + 0x3E);
                            spB0[18] = *(unsigned short *)((char *)sp100 + 0x40);
                            spB0[19] = *(unsigned short *)((char *)sp100 + 0x42);
                            fn_80033918(*(void **)(v + 4), &spB0[0]);
                        } else {
                            ((void (*)(char *, ...))fn_802E317C)(msg + 0x3F8);
                        }
                        memset(&sp10[0], 0, 0xE);
                        sp10[0] = 1;
                        sp10[1] = 0;
                        sp10[2] = 0;
                        fn_80033408(*(void **)(v + 4), 1);
                        fn_800339B0(*(void **)(v + 4), &sp10[0]);
                    }
                    if (VU8(0x23) != 0) {
                        if (mixed != 0) f1 = lbl_8056512C;
                        else f1 = *(float *)(*(unsigned char **)(v + 0x1C) + 0xA8) * (k50 * VF(0x10));
                        fn_80033A34(*(void **)(v + 4), f1);
                        memset(&sp8[0], 0, 4);
                        f0 = VF(8);
                        if (one < f0) f0 = one;
                        sp8[1] = 0;
                        sp8[0] = k54 * (k58 * f0);
                        if (mixed != 0) sp8[0] = 0;
                        fn_800337C4(*(void **)(v + 4), &sp8[0]);
                        memset(&sp80[0], 0, 0x30);
                        f1 = one - VF(0xC);
                        if (f1 >= one) f1 = one;
                        f4 = one + VF(0xC);
                        if (f4 >= one) f4 = one;
                        f2 = one + VF(0x14);
                        if (f2 >= one) f2 = one;
                        f0 = one - VF(0x14);
                        if (f0 >= one) f0 = one;
                        sp80[0] = k58 * (f1 * f2);
                        sp80[2] = k58 * (f4 * f2);
                        sp80[16] = k58 * (f1 * f0);
                        sp80[12] = k58 * (f4 * f0);
                        fn_80033584(*(void **)(v + 4), &sp80[0]);
                        r16 = VI(0x18);
                        flags |= r16;
                        if (r16 != 0) fn_80033C8C(*(void **)(v + 4), 1);
                        else fn_80033C8C(*(void **)(v + 4), 0);
                        memset(&sp60[0], 0, 0x20);
                        if (r16 & 1) {
                            short t = fn_802E5168(lbl_804FC680[0] * VF(8));
                            sp60[0] = t;
                            sp60[2] = t;
                        }
                        if (r16 & 2) {
                            short t = fn_802E5168(lbl_804FC680[1] * VF(8));
                            sp60[4] = t;
                            sp60[6] = t;
                        }
                        fn_80033CD8(*(void **)(v + 4), &sp60[0]);
                    }
                    if (VU8(0x23) != 0 && wasPlaying == 0) AXSetVoiceState(VI(4), 1);
                }
            }
            i++;
            off += 0x2C;
        } while (i < 0x20);
        OSRestoreInterrupts(irq);
        r16 = lbl_8055FFAC;
        lbl_8055FFAC = r16 + 1;
        lbl_804FC658[r16] = flags;
        if (r16 + 1 >= 10) lbl_8055FFAC = 0;
        flags |= lbl_804FC658[0];
        flags |= lbl_804FC658[1];
        flags |= lbl_804FC658[2];
        flags |= lbl_804FC658[3];
        flags |= lbl_804FC658[4];
        flags |= lbl_804FC658[5];
        flags |= lbl_804FC658[6];
        flags |= lbl_804FC658[7];
        flags |= lbl_804FC658[8];
        flags |= lbl_804FC658[9];
        lbl_8055FFA8 = flags;
        lbl_8055FFA6 = 0;
    }
}
#pragma pop
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
