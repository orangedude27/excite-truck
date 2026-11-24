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
extern void KERNEL_AddResetCallback(void *arg0, void *arg1);
extern int TRKReadBuffer_ui32(void);
extern float ConfigGetWpadSpeakerVolume(void);
extern void fn_80060CC0(int, int, void (*)());
extern void fn_802E30C8(char *, int, char *, ...);
extern void *memset(void *, int, unsigned int);
extern void fn_802E5248(int, int);
extern void SpuSpeaker_MarkStreamReady();
__declspec(section ".sdata") extern char lbl_8055D1D8[];
extern char lbl_8034D39C[];
extern char lbl_8034D384[];
extern char lbl_8034D3C0[];
extern unsigned char lbl_804FC800[];
extern unsigned char lbl_804FC558[];
extern int lbl_8055FF78;
extern int gSpuSoundSlotCount;
extern int *gSpuSoundSlotTable;
extern unsigned char *lbl_8055FF94;
extern void *lbl_8055FF90;
extern void *fn_802E5AE8();
extern void fn_8012BEF0(unsigned char *);
extern void fn_8012C41C(void (*)(void), int, unsigned char *);
extern void fn_802E589C(void);
extern int Spu_CacheVoiceObject(void);
#pragma dont_inline Spu_CacheVoiceObject
__declspec(section ".sdata") extern char lbl_8055D1E4[];
extern char lbl_8034D490[];
extern char lbl_8034D4A0[];
extern char sChannelStillPlayingFmt[];
extern void fn_802E317C(char *, ...);
extern int lbl_8055FF98;
extern char lbl_8034D584[];
extern char lbl_8034D528[];
extern void fn_80128670(int);
extern void fn_8012C4D8(void);
extern void fn_8012BF24(void *);
#define sSampleStillInUseFmt lbl_8034D528
#define Abend_panic fn_802E317C
#define Resource_release(res) ((void (*)(void *))fn_8012C4D8)(res)

enum {
    SPU_SAMPLE_REF_COUNT_OFFSET       = 0x94,
    SPU_SAMPLE_ACTIVE_CHANNELS_OFFSET = 0x98,
    SPU_SAMPLE_RESOURCE_OFFSET        = 0xAC
};
#define VU8(o) (*(unsigned char *)(v + (o)))
#define VF(o) (*(float *)(v + (o)))
#define VI(o) (*(int *)(v + (o)))
#define SI(o) (*(int *)(s + (o)))
#define SU(o) (*(unsigned int *)(s + (o)))
void fn_802E4D84(void *dst, void *src, int size) {
    register unsigned long destination = (unsigned long)dst;
    register unsigned long length = (unsigned long)size;
    memcpy((void *)destination, src, length);
    DCFlushRange((void *)destination, length);
}

extern unsigned char *fn_8012C370(int, unsigned int *, int, unsigned char *, unsigned char *);
extern char lbl_8034D280[];
#pragma scheduling invalid_target
/* Load an SFX0 sample blob by name: endian-swap its header when the loader says so,
 * relocate its data offset into a pointer, byte-swap 16-bit sample data for
 * non-raw formats, then flush it for the ARAM/DSP reader. */
void *SFXLoad(char *path) {
    unsigned int version;
    unsigned char attr;
    unsigned char needsSwap;
    unsigned char *sfxData;
    unsigned char *sampleData;
    unsigned char tmp;
    int sampleIndex;
    register int byteCount;
    register int dataBytes;

    sfxData = ((unsigned char *(*)(char *, unsigned int, unsigned int *, int, unsigned char *, unsigned char *))fn_8012C370)(
        path, 0x53465830 /* 'SFX0' */, &version, 0, &attr, &needsSwap);
    if (sfxData == 0) goto return_null;
    if (version != 3) fn_802E317C(lbl_8034D280, path, version, 3);
    if (needsSwap != 0) {
        tmp=sfxData[0]; sfxData[0]=sfxData[3]; sfxData[3]=tmp;
        tmp=sfxData[1]; sfxData[1]=sfxData[2]; sfxData[2]=tmp;
        tmp=sfxData[4]; sfxData[4]=sfxData[7]; sfxData[7]=tmp;
        tmp=sfxData[5]; sfxData[5]=sfxData[6]; sfxData[6]=tmp;
        tmp=sfxData[12]; sfxData[12]=sfxData[13]; sfxData[13]=tmp;
        tmp=sfxData[14]; sfxData[14]=sfxData[15]; sfxData[15]=tmp;
        tmp=sfxData[16]; sfxData[16]=sfxData[19]; sfxData[19]=tmp;
        tmp=sfxData[17]; sfxData[17]=sfxData[18]; sfxData[18]=tmp;
        tmp=sfxData[20]; sfxData[20]=sfxData[23]; sfxData[23]=tmp;
        tmp=sfxData[21]; sfxData[21]=sfxData[22]; sfxData[22]=tmp;
        tmp=sfxData[24]; sfxData[24]=sfxData[25]; sfxData[25]=tmp;
        tmp=sfxData[26]; sfxData[26]=sfxData[27]; sfxData[27]=tmp;
        tmp=sfxData[28]; sfxData[28]=sfxData[29]; sfxData[29]=tmp;
        *(unsigned int *)(sfxData+4) = (unsigned int)(sfxData + *(unsigned int *)(sfxData+4));
        if (*(unsigned short *)(sfxData+26) == 16 && sfxData[9] != 1) {
            sampleData = *(unsigned char **)(sfxData+4);
            for (sampleIndex=0; (dataBytes=*(int *)sfxData, byteCount=((unsigned int)dataBytes >> 31),
                       byteCount+=dataBytes, sampleIndex<(byteCount >> 1)); sampleIndex++) {
                tmp=sampleData[0];
                sampleData[0]=sampleData[1];
                sampleData[1]=tmp;
                sampleData+=2;
            }
        }
        DCFlushRange(*(void **)(sfxData+4), *(unsigned int *)sfxData);
    }
    return sfxData;
return_null:
    return 0;
}
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* AI DMA callback: refill the 0x20 SPU voice stream buffers. For each active
 * voice, stream the next half of its sample buffer (or wrap to the start at the
 * loop point), flushing the cache; write silence instead while the disc drive
 * is active, and flag completion when done. */
void fn_802E4F98(void) {
    extern char lbl_8055FFA4;
    extern char lbl_8055FFA5;
    extern char lbl_8055FFA6;
    extern char lbl_8055FFB4;
    extern int OSEnableInterrupts(int);
    extern int fn_802D9BF0(void);
    extern void fn_80033AAC(void *, void *);
    register int channelOffset;
    register int interruptState;
    register int channelIndex;
    int silence;
    unsigned char *channel;
    unsigned char *sample;
    unsigned int playPosition;
    unsigned int halfBufferSize;
    unsigned int wrapPosition;
    short initialSamples[3];

    if ((unsigned char)lbl_8055FFA5 != 0 &&
        (unsigned char)lbl_8055FFA6 == 0) {
        interruptState = ((int (*)(void))OSEnableInterrupts)();
        silence = fn_802D9BF0();
        lbl_8055FFB4 = 1;
        channelIndex = 0;
        channelOffset = 0;
        do {
            channel = lbl_8055FF94 + channelOffset;
            sample = *(unsigned char **)(channel + 0x1C);
            if (channel[0x20] != 0 && sample != 0 &&
                *(int *)(sample + 0x20) == 1 && channel[0x21] == 0) {
                playPosition = *(unsigned int *)(*(unsigned char **)(channel + 4) + 0x1BC);
                if (sample[0x24] != 0) {
                    playPosition >>= 1;
                } else {
                    playPosition <<= 1;
                }
                halfBufferSize = *(unsigned int *)(sample + 0xA0) >> 1;
                wrapPosition = *(unsigned int *)(sample + 0x9C) + halfBufferSize;
                if (playPosition < *(unsigned int *)(channel + 0x28)) {
                    if (silence == 0) {
                        ((void (*)(void *, unsigned int, void *))*(void **)(sample + 0x88))(
                            (unsigned char *)*(void **)(sample + 0x90) + halfBufferSize,
                            halfBufferSize, *(void **)(sample + 0x8C));
                    } else {
                        memset((unsigned char *)*(void **)(sample + 0x90) + halfBufferSize, 0, halfBufferSize);
                    }
                    DCFlushRange((unsigned char *)*(void **)(sample + 0x90) + halfBufferSize, halfBufferSize);
                }
                if (playPosition >= wrapPosition && *(unsigned int *)(channel + 0x28) < wrapPosition) {
                    if (silence == 0) {
                        ((void (*)(void *, unsigned int, void *))*(void **)(sample + 0x88))(
                            *(void **)(sample + 0x90),
                            halfBufferSize, *(void **)(sample + 0x8C));
                    } else {
                        memset(*(void **)(sample + 0x90), 0, halfBufferSize);
                    }
                    if (sample[0x24] != 0) {
                        initialSamples[0] = (short)*((unsigned char *)*(void **)(sample + 0x90));
                        initialSamples[1] = 0;
                        initialSamples[2] = 0;
                        fn_80033AAC(*(void **)(channel + 4), initialSamples);
                    }
                    DCFlushRange(*(void **)(sample + 0x90), halfBufferSize);
                }
                *(unsigned int *)(channel + 0x28) = playPosition;
            }
            ++channelIndex;
            channelOffset += 0x2C;
        } while (channelIndex < 0x20);
        *(volatile unsigned char *)&lbl_8055FFA4 = 1;
        *(volatile unsigned char *)&lbl_8055FFB4 = 0;
        OSRestoreInterrupts(interruptState);
    }
}
#pragma scheduling on
#pragma pop

extern float lbl_80565130;
extern float lbl_80565134;
#pragma dont_inline fn_802E5168
/* Convert a normalized value to an unsigned 16-bit sample value by scaling to 32768, rounding to nearest, and clamping to [0, 0x8000]. */
unsigned short fn_802E5168(float value) {
    float scaled = 32768.0f * value;
    float rounded;
    int truncated;
    int clampedLow;
    int clampedHigh;
    if (scaled < 0.0f) {
        rounded = scaled - 0.5f;
    } else {
        rounded = 0.5f + scaled;
    }
    truncated = (int)rounded;
    clampedLow = truncated & ((-truncated & ~truncated) >> 31);
    if (clampedLow < 0x8000) {
        clampedHigh = clampedLow;
    } else {
        clampedHigh = 0x8000;
    }
    return (unsigned short)clampedHigh;
}

/* One Wii remote speaker stream per Wii remote channel, 0x2C bytes each in the
 * table at lbl_804FC800; SpuSpeaker_MarkStreamReady opens one, fn_802E5264 closes it again. */
struct SpkStream {
    unsigned char enabled;   /* +0x00: the channel's speaker stream is open */
    unsigned char enc[0x20]; /* +0x01: the WENCInfo ADPCM encoder state (wenc.h) */
    int restart;             /* +0x24: encode the next frame from scratch */
    int unk_28;              /* +0x28: cleared when the stream is opened */
};

/* WPAD's speaker commands (WPADSpeakerCommand in WPAD.h, which this unit can't
 * include) and the words fn_802E5264 prints with its connect message. */
#define WPAD_SPEAKER_ON       1
#define WPAD_SPEAKER_PLAY     4
#define spuConnectMsg         lbl_8034D39C /* "spu: WPAD connect callback(%d) : %s" */
#define spuNameDisconnect     lbl_8034D3C0 /* "disconnect" */
#define spuNameConnect        lbl_8055D1D8 /* "connect" */
#define spuStreams            ((struct SpkStream *)lbl_804FC800)

#pragma scheduling invalid_target
/* On a successful WPAD_SPEAKER_PLAY reply, mark the channel's SpkStream enabled, clear its WENC encoder state, and log that the speaker stream is ready. */ void SpuSpeaker_MarkStreamReady(int channel, int result) {
    /* On success, mark the SPU stream channel ready and log its availability. */
    unsigned char *stream;

    if (result != 0) {
        return;
    }

    lbl_804FC800[channel * 0x2C] = 1;
    stream = lbl_804FC800 + channel * 0x2C;
    *(int *)(stream + 0x24) = 1;
    *(int *)(stream + 0x28) = 0;
    memset(stream + 1, 0, 0x20);
    ((void (*)(char *, int, ...))fn_802E30C8)(lbl_8034D384, channel);
}
#pragma scheduling on
/* Completion callback for the WPAD_SPEAKER_ON command: if the remote accepted
 * it, send WPAD_SPEAKER_PLAY; the reply SpuSpeaker_MarkStreamReady marks the stream ready. */
void fn_802E5248(int chan, int result) {
    if (result == 0) fn_80060CC0(chan, WPAD_SPEAKER_PLAY, (void (*)())SpuSpeaker_MarkStreamReady);
}

/* WPAD connect callback for the Wii remote speaker, reached through
 * fn_802E6B44 from the remote-joy connect handler: it logs which way channel
 * `chan` went (status < 0 is a disconnect), closes that channel's speaker
 * stream, and on a connect turns the remote's speaker on.  fn_802E5248 is
 * answered when the speaker is on and queues the play command, whose answer
 * SpuSpeaker_MarkStreamReady uses to mark the stream ready. */
/* WPAD connect callback for the Wii remote speaker: log connect/disconnect, close the channel's speaker stream, and on connect request WPAD_SPEAKER_ON (queued via fn_802E5248). */ void fn_802E5264(int chan, int status) {
    fn_802E30C8(spuConnectMsg, chan,
                 status < 0 ? spuNameDisconnect : spuNameConnect);
    spuStreams[chan].enabled = 0;
    if (status >= 0) fn_80060CC0(chan, WPAD_SPEAKER_ON, (void (*)())fn_802E5248);
}


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
/* Remote-speaker pump, the callback of the periodic OS alarm Spu_Init arms:
 * for each of the 4 Wii remote channels that can take stream data, whose radio
 * quality is still good and whose speaker mix has a full frame, it reads 0x28
 * samples out of the AX remote mix, ADPCM-encodes them with the channel's WENC
 * state and queues them to the remote as stream data.  A channel whose stream
 * is open but that was skipped marks its encoder to restart on the next frame;
 * the mix pointer is advanced once, after all channels, if any of them read. */
/* Remote-speaker pump: ADPCM-encode and send a 0x28-sample frame to each eligible Wii remote speaker stream, marking skipped streams to restart. */ void fn_802E52EC(void) {
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
int fn_802E540C(int request) {
#define KERNEL_RESET_NOTIFY 1
#define spuResetTeardown TRKReadBuffer_ui32
    /* Reset callback registered under "Spu" in Spu_Init: when the reset is
     * actually on, tear down the TRK/AX debugger state; never cancels a reset. */
    if (request == KERNEL_RESET_NOTIFY) {
        spuResetTeardown();
    }
    return 0;
#undef spuResetTeardown
#undef KERNEL_RESET_NOTIFY
}

extern void fn_802E6248(int, float);
#pragma dont_inline fn_802E5438
void fn_802E5438(void) {
#define spuSetRemoteSpeakerVolume fn_802E6248
#define getWpadSpeakerVolume ConfigGetWpadSpeakerVolume
    /* Copy the configured Wii Remote speaker volume into all four remote-speaker channels. */
    int channel;
    channel = 0;
    do {
        spuSetRemoteSpeakerVolume(channel, getWpadSpeakerVolume());
        channel++;
    } while (channel < 4);
#undef spuSetRemoteSpeakerVolume
#undef getWpadSpeakerVolume
}

/* The strings of this file's block at lbl_8034D210 that the SPU start-up logs
 * with and registers its allocations under (`msg` is that block). */
#define sBeginLogName   (msg + 0x1BC)  /* "SpuBegin" */
#define sAramBufName    (msg + 0x1C8)  /* "aram_buf" */
#define sAramBaseFmt    (msg + 0x1D4)  /* "spu: aram_base: %x -- %x (%dK)" */
#define sSpuSampleName  (msg + 0x1F4)  /* "SpuSample" */
#define sSpuChannelName (msg + 0x200)  /* "SpuChannel" */
#define sSpuCacheName   (msg + 0x20C)  /* "Spucache" */
#define sNoVoiceFmt     (msg + 0x218)  /* "Spu: can't acquire voice %d" */
#define sZeroBufName    (msg + 0x234)  /* "zero_buf" */

/* The state the start-up below sets up. */
#define gAramBase       lbl_8055FF7C   /* ARAM block taken for the mix */
#define gAramPos        lbl_8055FF80   /* where the mix reads ARAM from */
#define gAramSize       lbl_8055FF84   /* its size: the whole 128K */
#define gAramLastEnd    lbl_8055FF88   /* end of the last block written to ARAM */
#define gMixBuffer      lbl_8055FFB0   /* CPU side of that ARAM block */
#define gSpuSamples     lbl_8055FF90   /* "SpuSample": 256 slots of 0xB0 */
#define gSpuChannels    lbl_8055FF94   /* "SpuChannel": the 32 voice channels */
#define gSoundSlotTable gSpuSoundSlotTable   /* "Spucache" */
#define gSoundSlotCount gSpuSoundSlotCount   /* entries of it in use */
#define gSpuRunning     lbl_8055FFA5   /* the voice refill (fn_802E4F98) may run */
#define gSpuResetPending lbl_8055FFB5  /* set by the reset callback, forces a re-init */

enum {
    SPU_ARAM_SIZE     = 0x20000,  /* all of ARAM, held as "aram_buf" */
    SPU_SAMPLE_POOL   = 0xB000,   /* "SpuSample" */
    SPU_CHANNEL_POOL  = 0x580,    /* "SpuChannel": 32 * 0x2C */
    SPU_CACHE_POOL    = 0x400,    /* "Spucache" */
    SPU_CHANNEL_SIZE  = 0x2C,     /* sizeof(struct SpuChannel) */
    SPU_CHANNEL_COUNT = 32
};

/* Start the SPU voice layer (logs "SpuBegin"): reserve all of ARAM as the mix
 * buffer and invalidate its cache mirror, allocate the SpuSample slots, the 32
 * SpuChannel entries and the Spucache, clear ARAM by copying in a zeroed buffer,
 * register fn_802E4F98 as the AI DMA refill callback, and arm the periodic alarm
 * whose callback fn_802E52EC feeds the Wii Remote speakers. */
void Spu_Init(void) {
    extern char lbl_8034D210[];
    extern int lbl_8055FF7C, lbl_8055FF80, lbl_8055FF84, lbl_8055FF88;
    extern void *lbl_8055FFB0;
    extern unsigned char lbl_804FC690[];
    extern char lbl_8055D1E0;
    extern char lbl_8055FFA5;
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
    register float *vec;
    float one;
    char *msg = lbl_8034D210;
    int off, chan;
    int voice, aram;
    char *buf;
    long long now;

    ((void (*)(char *, ...))fn_802E30C8)(sBeginLogName);
    lbl_8055FF8C = (void *)1;
    gAramSize = SPU_ARAM_SIZE;
    fn_801282F4();
    /* the whole of ARAM, held under the name "aram_buf" */
    aram = fn_801284E8(sAramBufName, gAramSize);
    gMixBuffer = (void *)aram;
    gAramBase = aram;
    gAramPos = aram;
    DCInvalidateRange((void *)gAramPos, gAramSize);
    ((void (*)(char *, ...))fn_802E30C8)(sAramBaseFmt, gAramPos, gAramSize, (unsigned int)gAramSize >> 10);
    TRKPostEvent(0);
    TRKMessageSend();
    fn_80031C6C(0);
    gSpuSamples = fn_8012850C((void *)SPU_SAMPLE_POOL, sSpuSampleName);
    gSpuChannels = (unsigned char *)fn_8012850C((void *)SPU_CHANNEL_POOL, sSpuChannelName);
    gSoundSlotTable = (int *)fn_8012850C((void *)SPU_CACHE_POOL, sSpuCacheName);
    gSoundSlotCount = 0;
    memset(gSpuSamples, 0, SPU_SAMPLE_POOL);
    memset(gSpuChannels, 0, SPU_CHANNEL_POOL);
    /* one voice of the pool per channel: its number and its voice object */
    chan = 0;
    off = 0;
    do {
        voice = TRKInitializeMessageBuffers(0x1F, 0, 0);
        if (voice == 0) fn_802E317C(sNoVoiceFmt, chan);
        AXSetVoiceState(voice, 0);
        fn_80033538(voice, 0);
        *(int *)(gSpuChannels + off) = chan;
        chan++;
        *(int *)(gSpuChannels + off + 4) = voice;
        off += SPU_CHANNEL_SIZE;
    } while (chan < SPU_CHANNEL_COUNT);
    gAramLastEnd = gAramBase + (gAramSize - SPU_ARAM_SIZE);
    fn_801282EC(0x20);
    buf = (char *)fn_8012850C((void *)SPU_ARAM_SIZE, sZeroBufName);
    memset(buf, 0, SPU_ARAM_SIZE);
    ((void (*)(void *, void *, int, int))fn_802E4D84)((void *)gAramLastEnd, buf, SPU_ARAM_SIZE, 1);
    fn_80128670((int)buf);
    AIRegisterDMACallback((void *)fn_802E4F98);
    fn_802E6B04();
    OSCreateAlarm(lbl_804FC690);
    now = OSGetTime();
    /* the alarm that pumps stream data to the Wii remote speakers */
    OSSetPeriodicAlarm(lbl_804FC690, now, (unsigned int)(((*(unsigned int *)0x800000F8 >> 2) / 125000 * 0x65B9AB) / 8000), (void *)fn_802E52EC);
    one = lbl_80565128;
    vec = (float *)lbl_804FC680;
    vec[0] = one;
    vec[1] = one;
    vec[2] = one;
    vec[3] = one;
    KERNEL_AddResetCallback((void *)fn_802E540C, &lbl_8055D1E0);
    gSpuRunning = 1;
    ((void (*)(void))fn_802E5438)();
}

/* One of the 32 voice channels of the pool at lbl_8055FF94 (0x580 bytes),
 * built by Spu_Init and walked by the per-frame mixer fn_802E5C2C. */
struct SpuChannel {
    int index;                  /* +0x00: channel number */
    void *voice;                /* +0x04: voice object from the pool allocator */
    float volume;               /* +0x08: volume, SND_SetVolume writes it */
    float pan;                  /* +0x0C: left/right pan, SND_SetPan */
    float rate;                 /* +0x10: playback rate, SND_SetRate */
    float surroundPan;          /* +0x14: surround pan, SND_SetSurroundPan */
    int auxFlags;               /* +0x18: auxiliary send flags, SND_SetAuxFlags */
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
 * filled by fn_802E5AE8 and released by SpuSampleReleaseRef. */
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
    int activeChannels;         /* +0x98: instances still playing */
    unsigned int unk9C;         /* +0x9C: format/rate code of the blob */
    unsigned int size;          /* +0xA0: byte size, 0x40-aligned */
    float fA4;                  /* +0xA4 */
    float rate;                 /* +0xA8: playback rate copied into a channel */
    void *res;                  /* +0xAC: the loaded SFX0 blob */
};

/* Shuts the SPU layer down (the counterpart of Spu_Init): stops the
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
    int channelOffset;
    int idx;
    int sampleIndex;
    OSCancelAlarm(lbl_804FC690);
    lbl_8055FFA5 = 0;
    fn_802E6B34();
    idx = 0;
    channelOffset = 0;
    do {
        struct SpuChannel *channel = (struct SpuChannel *)(lbl_8055FF94 + channelOffset);
        if (channel->active != 0) {
            fn_802E317C(lbl_8034D450, channel->sample);
        }
        /* the voice object is reached through the pool base each time */
        TRKGetFreeBuffer(((struct SpuChannel *)(lbl_8055FF94 + channelOffset))->voice);
        idx++;
        ((struct SpuChannel *)(lbl_8055FF94 + channelOffset))->voice = 0;
        channelOffset += 0x2C;
    } while (idx < 0x20);
    sampleIndex = 0;
    idx = 0;
    do {
        struct SpuSample *sample = (struct SpuSample *)((unsigned char *)lbl_8055FF90 + idx);
        if (sample->refCount > 0) {
            fn_802E317C(lbl_8034D470, sample->name);
        }
        sampleIndex++;
        idx += 0xB0;
    } while (sampleIndex < 0x100);
    fn_80128670((int)lbl_8055FF94);
    lbl_8055FF94 = 0;
    fn_80128670((int)lbl_8055FF90);
    lbl_8055FF90 = 0;
    fn_80128670((int)gSpuSoundSlotTable);
    gSpuSoundSlotTable = 0;
    TRKReadBuffer_ui32();
    TRKConstructEvent();
    lbl_8055FF84 = 0;
    if (lbl_8055FFB0 != 0) {
        fn_80128658(lbl_8055FFB0);
        lbl_8055FFB0 = 0;
    }
}

/* Empty SPU voice-layer routine at slot +0x40 of the voice device backend's
 * vtable. The "Voice Mixer" device forwards to it from fn_8020B340, but this
 * build does nothing here (the "Null Mixer" device's slot is empty too). */
void fn_802E5824(void) {
}

/* Empty SPU voice-layer routine at slot +0x44 of the voice device backend's
 * vtable. The "Voice Mixer" device forwards to it from fn_8020B344, but this
 * build does nothing here (the "Null Mixer" device's slot is empty too). */
void fn_802E5828(void) {
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Allocates the next voice/sample object and stores it in the sound-name slot
 * table; returns 1 on success, 0 if the table is full or allocation failed. */
int Spu_CacheVoiceObject(void) {
#define gSoundSlotTable gSpuSoundSlotTable
#define gSoundSlotCount gSpuSoundSlotCount
#define Spu_allocVoiceObject fn_802E5AE8
    if (gSoundSlotCount < 0x100) {
        gSoundSlotTable[gSoundSlotCount] = (int)Spu_allocVoiceObject();
        if (gSoundSlotTable[gSoundSlotCount] == 0)
            return 0;
        gSoundSlotCount = gSoundSlotCount + 1;
        return 1;
    }
    return 0;
#undef gSoundSlotTable
#undef gSoundSlotCount
#undef Spu_allocVoiceObject
}
#pragma scheduling on
#pragma dont_inline reset

#pragma dont_inline Spu_CacheVoiceObject
/* One slot of the sound-name queue lbl_804FC558 (8 slots, count lbl_8055FF78),
 * which holds the resource-directory names currently being played. */
#define SFX_NAME_SLOT_SIZE 0x20

/* fn_8012C41C resource-directory callback used by fn_802E58B8: allocate a voice
 * object for every loaded entry of the directory, whatever its type. It is a
 * plain tail call to Spu_CacheVoiceObject, so the entry pointer still in r3 reaches
 * fn_802E5AE8 and the allocate/continue result flows back to fn_8012C41C, which
 * stops the walk at the first entry that cannot be allocated. */
void fn_802E589C(void) {
    Spu_CacheVoiceObject();
}

/* FourCC of the sample blobs SFXLoad loads, found at a resource entry's data. */
#define TAG_SFX0 0x53465830
extern unsigned char lbl_804FC558[]; /* sound-name queue: 0x20-byte NUL-terminated names */
extern int lbl_8055FF78;             /* sound-name queue: names in use */
extern int gSpuSoundSlotCount;             /* voice table gSpuSoundSlotTable: entries in use */
extern int *gSpuSoundSlotTable;            /* voice objects allocated by fn_802E5AE8 */
extern void fn_8012BEF0(unsigned char *);
extern void fn_8012C41C(void (*)(void), int, unsigned char *);
extern int Spu_CacheVoiceObject(void);
#pragma dont_inline Spu_CacheVoiceObject
/* fn_8012C41C callback: for every loaded entry of a resource directory whose
 * data is tagged 'SFX0', allocate a voice object for it (Spu_CacheVoiceObject keeps the
 * resource's name in r3 for fn_802E5AE8); returning 0 stops the walk. */
int fn_802E58A0(void *entry, int dataTag) {
    /* Resource-directory walk callback: for the 'SFX0' sample type, allocate a
     * voice object via Spu_CacheVoiceObject; for any other type keep the walk going (1). */
    if (dataTag == TAG_SFX0) return Spu_CacheVoiceObject();
    return 1;
}

/* Queue a resource directory to play: copy its name into the next slot of the
 * sound-name queue (lbl_804FC558, count lbl_8055FF78), hand the name to the
 * resource system, then walk the directory's loaded entries and allocate a
 * voice object for every one of them (fn_802E589C), stopping at the first
 * failure. fn_802E59BC is the same thing restricted to 'SFX0' entries. */
/* Queue a resource directory to play: copy its name into the next slot of the sound-name queue, request it from the resource system, then allocate a voice object for every loaded entry of the directory, stopping at the first failure. */ void fn_802E58B8(unsigned char *dirName) {
    const unsigned char *src = dirName;
    int remaining;
    unsigned char *slot;
    unsigned char c;
    slot = lbl_804FC558 + (lbl_8055FF78++ << 5);
    remaining = SFX_NAME_SLOT_SIZE;
    goto copy;
slot_check:
    if (--remaining > 0)
        goto copy;
    slot[-1] = 0;
    goto done;
copy:
    c = *src++;
    *slot++ = c;
    if ((signed char)c != 0)
        goto slot_check;
done:
    fn_8012BEF0(dirName);
    fn_8012C41C((void (*)())fn_802E589C, 0, dirName);
}

extern int sprintf(char *, const char *, ...);
#pragma scheduling invalid_target
/* Builds a SPU resource path from a directory and name, logs it, and warns if it cannot be cached. */
void fn_802E5950(int dirName, int fileName) {
    char path[0x108];

    sprintf(path, lbl_8055D1E4, dirName, fileName);
    ((void (*)(char *, char *, ...))fn_802E30C8)(lbl_8034D490, path);
    if (((int (*)(char *))Spu_CacheVoiceObject)(path) == 0) {
        ((void (*)(char *, char *, ...))fn_802E30C8)(lbl_8034D4A0, path);
    }
}
#pragma scheduling on
/* Queue a sound directory to play: copy its name into the next slot of the
 * sound-name queue (lbl_804FC558, count lbl_8055FF78), hand the name to the
 * resource system, then walk the directory's loaded entries and allocate a
 * voice object for each one tagged 'SFX0', stopping at the first failure. */
/* Queue an SFX0 sound directory for playback: copy its name (up to 0x20 bytes, NUL-terminated) into the next slot of the sound-name queue lbl_804FC558 (count lbl_8055FF78), request the directory from the resource loader fn_8012BEF0, then walk its loaded entries and allocate a voice object for each one tagged 'SFX0' via fn_802E58A0, stopping at the first failure. */ void fn_802E59BC(unsigned char *sfxDirName) {
    const unsigned char *srcName = sfxDirName;
    int charsLeft;
    unsigned char *dstSlot;
    unsigned char ch;
    dstSlot = lbl_804FC558 + (lbl_8055FF78++ << 5);
    charsLeft = SFX_NAME_SLOT_SIZE;
    goto copy;
slot_check:
    if (--charsLeft > 0)
        goto copy;
    dstSlot[-1] = 0;
    goto done;
copy:
    ch = *srcName++;
    *dstSlot++ = ch;
    if ((signed char)ch != 0)
        goto slot_check;
done:
    fn_8012BEF0(sfxDirName);
    fn_8012C41C((void (*)())fn_802E58A0, 0, sfxDirName);
}

extern void SpuSampleReleaseRef(void *);
void fn_802E5A54(void) {
    /* Shut down SPU state: release every allocated sound slot, finalize every
     * queued sound name, and reset both counts to zero. */
    int slotIndex;
    int nameIndex;
    unsigned char *name;

    for (slotIndex = 0; slotIndex < gSpuSoundSlotCount; slotIndex++) {
        SpuSampleReleaseRef((void *)gSpuSoundSlotTable[slotIndex]);
    }
    gSpuSoundSlotCount = 0;
    for (nameIndex = 0, name = lbl_804FC558; nameIndex < lbl_8055FF78; name += 0x20, nameIndex++) {
        fn_8012BF24(name);
    }
    lbl_8055FF78 = 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_strength_reduction off
void *fn_802E5AE8(char *arg0) {
char *__repair_addr;

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
    char *slot;
    int flag;
    found = fn_80029004(arg0, 0x2F);
    if (found != 0) name = found + 1;
    else name = arg0;
    freeIdx = -1;
    i = 0;
    off = 0;
    for (; i < 0x100; i++, off += 0xB0) {
        slot = (char *)lbl_8055FF90 + off;
__repair_addr = (char *)(slot + 0x94);

        if (*(int *)(__repair_addr) != 0) {
            if (stricmp(name, slot) == 0 && *(int *)((char *)lbl_8055FF90 + off + 0x20) == 0) {
                slot = (char *)lbl_8055FF90 + i * 0xB0;
                *(int *)(slot + 0x94) = *(int *)(slot + 0x94) + 1;
                return (char *)lbl_8055FF90 + i * 0xB0;
            }
        } else if (freeIdx < 0) {
            freeIdx = i;
        }
    }
    if (freeIdx < 0) fn_802E317C(msg + 0x2A8, arg0);
    res = (struct Res *)SFXLoad(arg0);
    if (res == 0) return 0;
    res->unkC = 0xCFFE;
    if (res->unkC != 0xCFFE) fn_802E317C(msg + 0x2C4, arg0);
    f31 = (float)(res->size >> 1) / lbl_80565138;
    aligned = (res->size + 0x3F) & ~0x3F;
    if (res->unk9 == 1) f31 = f31 * lbl_8056513C;
    f30 = (float)res->unk10 / lbl_80565138;
    slot = (char *)lbl_8055FF90 + freeIdx * 0xB0;
    memset(slot, 0, 0xB0);
    unk4 = res->unk4;
    if (unk4 & 0x1F) fn_802E317C(msg + 0x2FC, name, unk4);
    *(unsigned int *)(slot + 0xA0) = aligned;
    *(int *)(slot + 0x94) = 1;
    *(int *)(slot + 0x20) = 0;
    flag = res->unk9 == 1;
    slot[0x24] = flag;
    slot[0x25] = res->unk8 != 0;
    if (flag) memcpy(slot + 0x28, res->data, 0x60);
    else memset(slot + 0x28, 0, 0x60);
    *(int *)(slot + 0x98) = 0;
    *(float *)(slot + 0xA8) = f30;
    *(float *)(slot + 0xA4) = f31 / f30;
    strcpy(slot, name);
    *(unsigned int *)(slot + 0x9C) = unk4;
    *(void **)(slot + 0xAC) = res;
    return slot;
}
#pragma pop
/* SpuSample_release: decrement a sample's reference count, panicking if the last reference is dropped while channels still use it, and free its loaded SFX0 resource when the count reaches zero. */
/* Decrement a sample's reference count; panic if the last reference is dropped while channels still use it, and free its loaded SFX0 resource when the count reaches zero. */ void SpuSampleReleaseRef(void *sample) {
    if (*(int *)((char *)sample + SPU_SAMPLE_REF_COUNT_OFFSET) == 1 &&
        *(int *)((char *)sample + SPU_SAMPLE_ACTIVE_CHANNELS_OFFSET) > 0) {
        Abend_panic(sSampleStillInUseFmt, sample,
                    *(int *)((char *)sample + SPU_SAMPLE_ACTIVE_CHANNELS_OFFSET));
    }
    if ((*(int *)((char *)sample + SPU_SAMPLE_REF_COUNT_OFFSET) -= 1) == 0 &&
        *(int *)((char *)sample + SPU_SAMPLE_RESOURCE_OFFSET) != 0) {
        Resource_release(*(void **)((char *)sample + SPU_SAMPLE_RESOURCE_OFFSET));
        *(int *)((char *)sample + SPU_SAMPLE_RESOURCE_OFFSET) = 0;
    }
}
#pragma ppc_psq_save reset
extern void *lbl_8055FF90;
extern float lbl_80565128, lbl_80565148;
extern char lbl_8034D554[], lbl_8034D578[];
extern void fn_801282EC(int);
extern void fn_801282F4(void);
extern void *fn_8012850C(void *, char *);

/* Creates a streaming SpuSample in a free pool slot: allocates a zeroed stream
 * buffer of bufSize bytes under the "stream_buf" name, initializes the sample's
 * fields and decode callback, copies name into the slot, and returns the slot. */
void *Spu_createStreamSample(const char *name, unsigned int bufSize, int hasAdpcmData, int decodeFn, int decodeArg) {
    #define sNoStreamSamplesFmt lbl_8034D554 /* "spu: out of samples for stream %s" */
    #define sStreamBufName      lbl_8034D578 /* "stream_buf" */
    int i, freeSlot = -1;
    unsigned char *walker = (unsigned char *)lbl_8055FF90;
    char *sample, *nameDst;
    const char *nameSrc = name;
    unsigned char ch;
    float lengthValue, rateValue;
    for (i = 0; i < 0x100; walker += 0xB0, i++) if (*(int *)(walker + 0x94) == 0) { freeSlot = i; break; }
    if (freeSlot < 0) fn_802E317C(sNoStreamSamplesFmt, (int)name);
    sample = (char *)lbl_8055FF90 + freeSlot * 0xB0;
    memset(sample, 0, 0xB0);
    fn_801282EC(0x80); fn_801282F4();
    *(void **)(sample + 0x90) = fn_8012850C((void *)bufSize, sStreamBufName);
    memset(*(void **)(sample + 0x90), 0, bufSize);
    rateValue = 1.0f;
    sample[0x25] = 1;
    *(void **)(sample + 0x9C) = (void *)((unsigned int)*(void **)(sample + 0x90) + 0x80000000);
    lengthValue = 1000.0f;
    *(unsigned int *)(sample + 0xA0) = bufSize;
    *(int *)(sample + 0x94) = 1; *(int *)(sample + 0x20) = 1;
    sample[0x24] = (hasAdpcmData == 1);
    *(int *)(sample + 0x88) = decodeFn; *(int *)(sample + 0x8C) = decodeArg; *(int *)(sample + 0x98) = 0;
    *(float *)(sample + 0xA8) = rateValue;
    *(float *)(sample + 0xA4) = lengthValue;
    nameDst = sample; i = 0x20;
    goto copy;
chk:
    if (--i > 0) goto copy;
    nameDst[-1] = 0;
    goto end;
copy:
    ch = *nameSrc++;
    *nameDst++ = ch;
    if ((signed char)ch != 0) goto chk;
end:
    return sample;
    #undef sStreamBufName
    #undef sNoStreamSamplesFmt
}

// Free the audio buffer/region owned by this object and clear its state fields.
void fn_802E5FE4(void *obj) {
    if (*(int *)((char *)obj + 0x98) > 0) {
        fn_802E317C(lbl_8034D584, obj, *(int *)((char *)obj + 0x98));
    }
    fn_80128670(*(int *)((char *)obj + 0x90));
    *(int *)((char *)obj + 0x90) = 0;
    *(int *)((char *)obj + 0x94) = 0;
}

float fn_802E6040(void *sample) {
    /* Return an SPU sample's stored length (+0xA4), or 0.0 when no sample is loaded. */
    if (sample != 0) return *(float *)((char *)sample + 0xA4);
    return lbl_8056512C;
}

extern unsigned char *lbl_8055FF94;
extern int OSDisableInterrupts(void);
extern int OSEnableInterrupts(int);
__declspec(section ".sdata") extern unsigned char *lbl_8055FF94;
#pragma scheduling invalid_target
/* Allocate a free SPU voice channel for the given sample and initialize it for playback. */
void *fn_802E6058(void *sample) {
#define CHANNEL_COUNT 32
#define CHANNEL_SIZE  0x2C
    struct SpuChannel *channel;
    int i;

    for (i = 0; i < CHANNEL_COUNT; i++) {
        channel = (struct SpuChannel *)(lbl_8055FF94 + (i % CHANNEL_COUNT) * CHANNEL_SIZE);
        if (channel->active == 0) {
            OSDisableInterrupts();
            channel->active = 1;
            channel->sample = (struct SpuSample *)sample;
            channel->volume = 1.0f;
            channel->pan = 0.0f;
            channel->surroundPan = 1.0f;
            channel->auxFlags = 0;
            channel->rate = ((struct SpuSample *)sample)->rate;
            channel->wantPlay = 0;
            channel->adpcm = 0;
            ((struct SpuSample *)sample)->activeChannels += 1;
            channel->playing = 1;
            channel->started = 0;
            channel->playPos = 0;
            ((void (*)(void))OSEnableInterrupts)();
            ++lbl_8055FF98;
            return channel;
        }
    }
    return 0;
#undef CHANNEL_SIZE
#undef CHANNEL_COUNT
}
#pragma scheduling on
/* Release an SPU voice channel: warn if still playing, drop the sample's active-channel count, clear the in-use flag, decrement the global active voice count. */ void fn_802E6138(void *channel) {
    /* Release an SPU voice channel: if it was still marked playing, log the
       channel and sample; drop the sample's active-channel count, clear the
       channel's in-use flag, and decrement the global active voice count. */
    if (((unsigned char *)channel)[0x23] != 0) {
        fn_802E317C(sChannelStillPlayingFmt, *(int *)channel, *(void **)((char *)channel + 0x1C));
    }
    {
        void *sample = *(void **)((char *)channel + 0x1C);
        *(int *)((char *)sample + SPU_SAMPLE_ACTIVE_CHANNELS_OFFSET) -= 1;
    }
    ((unsigned char *)channel)[0x20] = 0;
    lbl_8055FF98 -= 1;
}

/* SND_Start: start this SPU voice from the beginning by clearing its ADPCM flag
 * (+0x25) and marking it as wanting to play (+0x23). */
void fn_802E61A8(void *channel) {
    ((struct SpuChannel *)channel)->adpcm = 0;
    ((struct SpuChannel *)channel)->wantPlay = 1;
}

void fn_802E61BC(void *channel) {
    /* SND_StartLoop: if the channel was idle, set its loop flag (+0x25) and flag it to keep playing. */
    if (((struct SpuChannel *)channel)->wantPlay == 0) {
        ((struct SpuChannel *)channel)->adpcm = 1;
        ((struct SpuChannel *)channel)->wantPlay = 1;
    }
}

/* SND_Stop: clear the channel's want-play flag so it stops after the current frame. */
void fn_802E61D8(void *channel) {
    ((struct SpuChannel *)channel)->wantPlay = 0;
}

#define SoundOutputMode lbl_8055FF8C /* 0 = mono, 2 = surround */
#define PanCenter lbl_8056512C
#define SurroundPanDefault lbl_80565128
/* SND_SetVolume: set a voice channel's volume (+0x08); the voice mixer in
 * src/game/voicesnd.c rewrites it every frame with the speaker's volume scaled
 * by the voice's own level and distance falloff. */
void fn_802E61E4(void *voice, float volume) {
    ((struct SpuChannel *)voice)->volume = volume;
}

void fn_802E61EC(void *voice, float pan) {
    /* Set a voice's pan, forcing it to center (0.0) when the sound output mode is mono. */
    if (SoundOutputMode != 0) {
        *(float *)((char *)voice + 0xC) = pan;
        return;
    }
    *(float *)((char *)voice + 0xC) = PanCenter;
}

void fn_802E620C(void *voice, float surroundPan) {
    /* Set a voice's surround pan, forcing it to the default (1.0) unless the output mode is surround (2). */
    if ((int)SoundOutputMode == 2) {
        *(float *)((char *)voice + 0x14) = surroundPan;
        return;
    }
    *(float *)((char *)voice + 0x14) = SurroundPanDefault;
}

/* Set a voice handle's playback rate (offset 0x10), the field SND_SetRate writes. */
void fn_802E622C(void *voice, float rate) { *(float *)((char *)voice + 0x10) = rate; }

/* No-op voice-parameter setter: the sound mixer passes a voice handle and the
 * float from the sound's unused +0x2C field here, but this build discards it. */
void fn_802E6234(void) {}

/* No-op voice-parameter setter: the sound mixer passes a voice handle and the
 * float from the sound's unused +0x30 field here, but this build discards it. */
void fn_802E6238(void) {}

/* No-op voice-parameter setter: the sound mixer passes a voice handle and the
 * float from the sound's unused +0x34 field here, but this build discards it. */
void fn_802E623C(void) {}

void fn_802E6240(void* voice, int flags) {
    // Set a voice handle's auxiliary send flags (SND_SetAuxFlags), stored at +0x18.
    *(int*)((char*)voice + 0x18) = flags;
}

/* Set the volume of one Wii Remote speaker channel (spuSetRemoteSpeakerVolume). */
void fn_802E6248(int channel, float volume) {
    lbl_804FC680[channel] = volume;
}

/* Set the sound output mode (0 = mono, 2 = surround). */
void fn_802E625C(void* mode) {
    SoundOutputMode = mode;
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
    extern double lbl_80565140;
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
    int off;
    int flags;
    int irq;
    int i;
    unsigned char *v;
    int wasPlaying;
    unsigned char *s;
    unsigned int r16;
    union { struct { unsigned int hi, lo; } word; double value; } conv;
    unsigned int sp100[24];
    unsigned short spD8[20];
    unsigned short spB0[20];
    unsigned short sp80[24];
    unsigned short sp60[16];
    unsigned short sp50[8];
    unsigned short sp40[8];
    unsigned short sp30[8];
    unsigned short sp20[8];
    unsigned short sp10[8];
    unsigned short spC[2];
    unsigned short sp8[2];
    float f0, f1, f2, f4;
    float k54, k58, one, k50, inv;
    double magic;
    float k4C;
    char *msg = lbl_8034D210;
    int mixed;
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
        magic = lbl_80565140;
        inv = lbl_80565138;
        k4C = lbl_8056514C;
        k50 = lbl_80565150;
        i = 0;
        k58 = lbl_80565158;
        off = 0;
        k54 = lbl_80565154;
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
                        f1 = f1 < one ? f1 : one;
                        f4 = one + VF(0xC);
                        f4 = f4 < one ? f4 : one;
                        f2 = one + VF(0x14);
                        f2 = f2 < one ? f2 : one;
                        f0 = one - VF(0x14);
                        f0 = f0 < one ? f0 : one;
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
                            short t = ((unsigned short (*)(float))fn_802E5168)(lbl_804FC680[0] * VF(8));
                            sp60[0] = t;
                            sp60[2] = t;
                        }
                        if (r16 & 2) {
                            short t = ((unsigned short (*)(float))fn_802E5168)(lbl_804FC680[1] * VF(8));
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
        if ((int)(r16 + 1) >= 10) lbl_8055FFAC = 0;
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
/* SND_Name: return the default sound-resource name, the shared "!!" string shown
 * for resources that have no name. The resource argument callers pass is ignored. */
int* fn_802E6ABC(void) {
    return &lbl_8055D1EC;
}

/* Flag an SPU reset as pending: registered as the reset callback by fn_802E6AD0,
 * this asks the SPU to re-initialize itself on its next pass. */
void fn_802E6AC4(void) {
    gSpuResetPending = 1;
}

int fn_802E6AD0(int request) {
#define KERNEL_RESET_NOTIFY 1
#define invokeCallback fn_802E7774
#define flagSpuReset fn_802E6AC4
    /* SPU reset callback: on a real reset request, flag the SPU to reset itself. */
    if (request == KERNEL_RESET_NOTIFY) {
        invokeCallback(flagSpuReset);
    }
    return 0;
#undef flagSpuReset
#undef invokeCallback
#undef KERNEL_RESET_NOTIFY
}

#pragma scheduling invalid_target
void fn_802E6B04(void) {
#define registerResetCallback KERNEL_AddResetCallback
#define spuResetCallback      fn_802E6AD0
#define spuCallbackTag        lbl_8055D1F0
#define spuIdleNoop           fn_802E7770
    /* Register the SPU reset handler under the "DTK" tag in the kernel reset list. */
    spuIdleNoop();
    registerResetCallback(spuResetCallback, &spuCallbackTag);
#undef spuIdleNoop
#undef spuCallbackTag
#undef spuResetCallback
#undef registerResetCallback
}
#pragma scheduling on
/* No-op sound-system teardown hook: called from the SPU shutdown (fn_802E56F0)
 * and VoiceSoundMixer::End (fn_8020A8E8); this build leaves it empty. */
void fn_802E6B34(void) {
}

/* Clear a scratch text buffer to an empty string before a sound name is formatted
 * into it (the sound-index argument is unused). */
void fn_802E6B38(void* index, signed char* text) {
    *text = 0;
}

#pragma dont_inline on
/* Tail-call the WPAD speaker connect/disconnect callback, forwarding the channel and connect status. */
void fn_802E6B44(int chan, int status) {
    fn_802E5264(chan, status);
}
#pragma dont_inline reset
