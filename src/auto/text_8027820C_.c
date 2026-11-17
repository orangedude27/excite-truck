extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
void *fn_802678E4(int);
extern float lbl_805640A0, lbl_805640A4, lbl_805640A8, lbl_805640AC;
extern void fn_8026E22C(float *, void *, void *, float);
extern void fn_801345D8(char *, int, const char *, ...);
extern void fn_802D08B4(int, int, int);
extern void fn_802D07E4(char *, int);
extern void fn_80128670(int);
extern const char lbl_80347580[];
extern int fn_8012850C(int, const char *);
extern void *fn_8002F37C(void *, void *, int, int, int);
extern void fn_80278284(void);
extern char lbl_8055F5BA;
extern char lbl_8055F5BB;
extern char lbl_8055F5B9;
extern char lbl_8055F5C8;
extern int lbl_8055E3C4;
extern int lbl_8055F5B4;
extern int lbl_8055F5BC;
extern int lbl_8055F5C0;
extern char lbl_8055F5B8;
extern int fn_802E30C8(const char *, ...);
extern const char lbl_80347590[];
extern const char lbl_803475B4[];
extern const char lbl_80347660[];
extern char lbl_804A15D0[];

// Script-movie keyframe capture: the captured key list (0x38-byte records) and its length.
#define gKeyframeList  lbl_8055F5B0
#define gKeyframeCount lbl_8055F5B4
#define Mem_Free       fn_80128670

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F5B8;
void fn_8027820C(void) {}

void fn_80278210(void) {}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80278214(void) {
    /* Initialize the cscript movie-capture subsystem: allocate the empty 2-slot
     * keyframe list and reset the recording, playback and tick-range globals. */
#define sPlayFlag     lbl_8055F5C8
#define sDemoActive   lbl_8055F5BB
#define sPlayingBack  lbl_8055F5BA
#define sPlayPending  lbl_8055F5B9
#define sPlayEndTick  lbl_8055F5BC
#define sLastPlayTick lbl_8055F5C4
#define sRecording    lbl_8055F5B8
#define cscriptNodeTag lbl_80347580
    int zero = 0;
    int minus = -1;
    gKeyframeCount = zero;
    sPlayFlag = zero;
    sDemoActive = zero;
    sPlayingBack = zero;
    sPlayPending = zero;
    sPlayEndTick = minus;
    sLastPlayTick = minus;
    sRecording = zero;
    gKeyframeList = (int)fn_8002F37C(
        (void *)(((int (*)(int, const char *))fn_8012850C)(0x80, cscriptNodeTag)),
        fn_80278284, zero, 0x38, 2);
#undef sPlayFlag
#undef sDemoActive
#undef sPlayingBack
#undef sPlayPending
#undef sPlayEndTick
#undef sLastPlayTick
#undef sRecording
#undef cscriptNodeTag
}
#pragma scheduling on
#pragma pop
void fn_80278284(void) {}

// Free the captured script-movie keyframe list and reset its count.
void fn_80278288(void) {
    if (gKeyframeList != 0) Mem_Free(gKeyframeList - 0x10);
    gKeyframeList = 0; gKeyframeCount = 0;
}

/* Starts capturing the cscript movie: turns recording on, clears the captured
   keyframe list, the playback flags and the playback tick range, then logs the
   tick recording began on (the script's "begin recording" command). */
#pragma scheduling invalid_target
void fn_802782C4(void) {
#define sRecording       lbl_8055F5B8 /* 1 while keyframes are being captured */
#define sKeyCount        lbl_8055F5B4 /* keyframes captured so far */
#define sPlayPending     lbl_8055F5B9 /* a movie is queued to play back */
#define sPlayingBack     lbl_8055F5BA /* 1 while the captured movie plays */
#define sPlayEndTick     lbl_8055F5BC /* playback range end, -1 = unset */
#define sPlayStartTick   lbl_8055F5C0 /* playback range start, -1 = unset */
#define sCurrentTick     lbl_8055E3C4 /* global tick/frame counter */
#define sMsgBeginRecord  lbl_80347590 /* "script: begin recording on tick %d" */

    sRecording = 1;
    sKeyCount = 0;
    sPlayingBack = 0;
    sPlayPending = 0;
    fn_802E30C8(sMsgBeginRecord, sCurrentTick);
    sPlayEndTick = -1;
    sPlayStartTick = -1;

#undef sRecording
#undef sKeyCount
#undef sPlayPending
#undef sPlayingBack
#undef sPlayEndTick
#undef sPlayStartTick
#undef sCurrentTick
#undef sMsgBeginRecord
}
#pragma scheduling on

#pragma scheduling invalid_target
void fn_80278318(void) {
#define sRecording       lbl_8055F5B8 /* 1 while keyframes are being captured */
#define sPlayPending     lbl_8055F5B9 /* a movie is queued to play back */
#define sPlayingBack     lbl_8055F5BA /* 1 while the captured movie plays */
#define sCurrentTick     lbl_8055E3C4 /* global tick/frame counter */
#define sMsgEndRecord    lbl_803475B4 /* "script: end recording on tick %d" */

    /* End the script movie recording: log the final tick and clear the record/playback flags. */
    fn_802E30C8(sMsgEndRecord, sCurrentTick);
    sRecording = 0;
    sPlayingBack = 0;
    sPlayPending = 0;

#undef sRecording
#undef sPlayPending
#undef sPlayingBack
#undef sCurrentTick
#undef sMsgEndRecord
}
#pragma scheduling on
/* Returns lbl_8055F5B8 (sRecording): nonzero while replay keyframes are being
 * captured. */
char fn_80278358(void) {
    return lbl_8055F5B8;
}

extern char lbl_8055F5C9;
extern const char lbl_803475D8[];
extern double lbl_805640B0;
#pragma push
#pragma scheduling invalid_target
void fn_80278360(void *arg0) {
    register unsigned char state;
    int count;
    int *base;
    volatile int *dst;
    volatile int *src;
    int now;
    int age;
    int old;
    int first;
    int second;
    int value;
    int offset;
    float f;

    state = (unsigned char)lbl_8055F5B8;
    if (state == 0)
        goto record;
    count = lbl_8055F5B4;
    if (count != 0)
        goto record;
    now = lbl_8055E3C4;
    if (now > 10)
        return;
    if (state == 0)
        goto report_once;
    count = lbl_8055F5B4;
    if (count >= 2)
        goto report_once;
    if (count == 0)
        goto report_always;
    base = (int *)lbl_8055F5B0;
    old = *(int *)((char *)base + (count - 1) * 0x38 + 0x34);
    age = lbl_8055E3C4 - old;
    if (age < 2)
        return;

record:
    src = (volatile int *)arg0;
    count = *(volatile int *)&lbl_8055F5B4;
    base = (int *)*(volatile int *)&lbl_8055F5B0;
    offset = count * 0x38;
    now = *(volatile int *)&lbl_8055E3C4;
    first = src[0x16];
    second = src[0x17];
    *(volatile int *)&lbl_8055F5B4 = count + 1;
    dst = (volatile int *)((char *)base + offset);
    value = src[0x18];
    dst[13] = now;
    now = src[0x19];
    dst[0] = first;
    first = src[0x1A];
    dst[1] = second;
    second = src[0x1B];
    dst[2] = value;
    value = src[0x1C];
    dst[3] = now;
    now = src[0x1D];
    dst[4] = first;
    first = src[0x1E];
    dst[5] = second;
    second = src[0x1F];
    dst[6] = value;
    value = src[0x20];
    dst[7] = now;
    now = src[0x21];
    dst[8] = first;
    f = *(volatile float *)((char *)src + 0xBC);
    dst[9] = second;
    dst[10] = value;
    dst[11] = now;
    *(volatile float *)((char *)dst + 0x30) = f;
    return;

report_always:
    lbl_8055F5C9 = 1;
    fn_802E30C8(lbl_803475D8);
    return;
report_once:
    if (lbl_8055F5C9 == 0) {
        lbl_8055F5C9 = 1;
        fn_802E30C8(lbl_803475D8);
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8027847C(void *arg0) {
    struct Key { float mat[12]; float value; int frame; };
    register const char *base = lbl_80347580;
    register char *obj = (char *)arg0;
    register struct Key *first, *next;
    struct Key *p=(struct Key *)lbl_8055F5B0;
    int now=lbl_8055E3C4;
    int count=lbl_8055F5B4;
    int i=0;
    float fraction, denominator, v, nextvalue;
    int delta, keybase;
    char buffer[256];
    int frame;
    while (i+2 < count) {
        if (p[1].frame > now) break;
        p++; i++;
    }
    if (i>=0 && i+1<count) {
        keybase=*(volatile int *)&lbl_8055F5B0;
        first=(struct Key *)(keybase + i*0x38);
        next=(struct Key *)(keybase + (i+1)*0x38);
        delta=next->frame-first->frame;
        denominator=lbl_805640A0;
        if ((float)delta > denominator) denominator=(float)delta;
        fraction=(float)(now-first->frame)/denominator;
        fraction = lbl_805640A4 < fraction ? lbl_805640A4 : fraction;
        fraction = fraction > lbl_805640A8 ? fraction : lbl_805640A8;
        fn_8026E22C((float *)(obj+0x58),first,next,fraction);
        nextvalue=next->value;
        v=first->value;
        *(float *)(obj+0xbc)=v+fraction*(nextvalue-v);
        if (*(unsigned char *)&lbl_8055F5B9 && !*(unsigned char *)&lbl_8055F5BA && lbl_8055E3C4>=lbl_8055F5C0 && lbl_8055E3C4<lbl_8055F5C0+10) {
            lbl_8055F5B9=0; lbl_8055F5BA=1; lbl_8055F5C4=-1;
            fn_802E30C8(base+0x70,lbl_8055F5C0,lbl_8055F5BC);
        } else if (*(unsigned char *)&lbl_8055F5BA && lbl_8055E3C4>((struct Key *)lbl_8055F5B0)[lbl_8055F5B4-1].frame) {
            lbl_8055F5BA=0;
            fn_802E30C8(base+0x90);
        }
        if (*(unsigned char *)&lbl_8055F5BA) {
            int now2 = lbl_8055E3C4;
            int tmp = lbl_8055F5C4;
            int end, length;
            if (now2 == tmp) goto frame_done;
            tmp = *(volatile int *)&lbl_8055F5C0;
            lbl_8055F5C4 = now2;
            frame = now2 - tmp;
            if (frame < 0) goto frame_done;
            end = *(volatile int *)&lbl_8055F5BC;
            length = end - tmp;
            if (frame > length) goto frame_done;
            if (tmp > end) goto frame_done;
            if (frame % 2 != 0) goto frame_done;
            fn_802E30C8(base+0xa8,frame);
            fn_801345D8(buffer,256,base+0xd0,lbl_804A15D0,frame/2);
            fn_802D08B4(2,2,1);
            fn_802D07E4(buffer,1);
        }
frame_done:;
    } else {
        float *m=(float *)(obj+0x58);
        float end, zero, one;
        zero=lbl_805640A8; one=lbl_805640A4; end=lbl_805640AC;
        m[0]=one; m[1]=zero; m[2]=zero;
        m[3]=zero; m[4]=one; m[5]=zero;
        m[6]=zero; m[7]=zero; m[8]=one;
        m[9]=zero; m[10]=zero; m[11]=zero;
        *(float *)(obj+0xbc)=end;
    }
}
#pragma pop

#pragma pop
/* Copies a movie name into the pending buffer, or reports if recording is active. */
void fn_80278778(char *name) {
    int remaining;
    char *dst;
    if ((unsigned char)lbl_8055F5B8 != 0) {
        fn_802E30C8(lbl_80347660);
        return;
    }
    dst = lbl_804A15D0;
    remaining = 0x100;
    while ((*dst++ = *name++) != '\0') {
        if (--remaining > 0)
            continue;
        dst[-1] = '\0';
        break;
    }
    lbl_8055F5B9 = 1;
    lbl_8055F5BA = 0;
}
#pragma opt_propagation reset
extern char lbl_8055F5B9;
/* Clear scripted-movie playback state: stop any playback and drop the queued movie. */
void fn_802787E4(void) {
    #define sPlayingBack lbl_8055F5BA /* 1 while the captured movie plays */
    #define sPlayPending lbl_8055F5B9 /* a movie is queued to play back */
    sPlayingBack = 0;
    sPlayPending = 0;
    #undef sPlayingBack
    #undef sPlayPending
}

extern char lbl_8055F5BA;
/* Returns lbl_8055F5BA (sPlayingBack): nonzero while the captured scripted movie plays back. */
char fn_802787F4(void) {
    return lbl_8055F5BA;
}

#define sPlayingBack lbl_8055F5BA /* 1 while the captured movie plays back */
#define sDemoActive  lbl_8055F5BB /* 1 while the scripted replay/demo runs */
/* Return 1 if any scripted-movie playback is active: either the captured
 * movie is playing back, or the scripted replay/demo mode is running. */
int fn_802787FC(void) {
    return ((unsigned char)sPlayingBack != 0) || ((unsigned char)sDemoActive != 0);
}

int fn_80278820(void) {
    /* If the current scene/object from fn_802678E4(0) is type 0x19, flag lbl_8055F5B9
       is set, and lbl_8055E3C4 < lbl_8055F5C0, return 1. Otherwise return 0 when
       lbl_8055F5BA is set, else return flag lbl_8055F5C8. */
    if (((int *)fn_802678E4(0))[4] == 0x19 && (unsigned char)lbl_8055F5B9 != 0 && lbl_8055E3C4 < lbl_8055F5C0) {
        return 1;
    }
    return (unsigned char)lbl_8055F5BA != 0 ? 0 : (unsigned char)lbl_8055F5C8;
}

extern char lbl_8055F5BB;
extern char lbl_8055F5B9;
extern char lbl_8055F5C8;
extern int lbl_8055E3C4;
extern char lbl_8055F5C8;
extern int lbl_8055F5C0;
extern int lbl_8055E3C4;
extern float lbl_805640A8;
extern float lbl_805640B8;
extern float lbl_805640BC;
void *fn_802678E4(int);

extern int lbl_8055F5BC;
extern double lbl_805640B0;
#pragma scheduling invalid_target
void fn_8027889C(float arg0) {
    float t;
    float result = 0.0f;
    t = arg0 / lbl_805640B8;
    if (t < lbl_805640A8) {
        result = t - lbl_805640BC;
    } else {
        result = lbl_805640BC + t;
    }
    lbl_8055F5C0 = (int)result;
}

extern float lbl_805640B8, lbl_805640BC;
#pragma processor 750
#pragma scheduling off
void fn_802788E0(float farg0) {
    float q = farg0 / lbl_805640B8;
    float v;
    if (q < lbl_805640A8)
        v = q - lbl_805640BC;
    else
        v = lbl_805640BC + q;
    lbl_8055F5BC = (int)v;
}
#pragma scheduling on
int fn_80278924(float *arg0, float *arg1) {
    int result = 0;
    float scale = lbl_805640B8;
    *arg0 = scale * (float)lbl_8055F5C0;
    *arg1 = scale * (float)lbl_8055F5BC;
    if (lbl_8055F5C0 >= 0 && lbl_8055F5BC >= lbl_8055F5C0) result = 1;
    return result;
}

void fn_8027888C(char arg0) {
    lbl_8055F5C8 = arg0;
}

void fn_80278894(char demoActive) {
    /* Set the global scripted-replay/demo active flag. */
#define sDemoActive lbl_8055F5BB
    sDemoActive = demoActive;
#undef sDemoActive
}
extern int lbl_8055F5B4;
extern char lbl_8055F5B8;
extern int fn_802E30C8(const char *, ...);
extern const char lbl_80347590[];
extern const char lbl_803475B4[];
extern const char lbl_80347660[];
extern char lbl_804A15D0[];
extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern const char lbl_80347580[];
extern void *fn_8002F37C(void *, void *, int, int, int);
extern int lbl_8055F5B0;
extern int lbl_8055F5C4;
extern void fn_80128670(int);
