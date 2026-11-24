// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_80335DCC;
#pragma pop
extern char lbl_8055E6D0;
extern int memset(void *, int, unsigned int);
extern int lbl_8055E6D4;
extern void fn_80128670(int);
extern void fn_80128668(void *);
#pragma cplusplus on
extern "C" {
struct F801B4610 {
    virtual void f2(int) = 0;
};
struct F801B4720 {
    virtual void f0(void) = 0;
    virtual void f1(void) = 0;
    virtual void f2(void) = 0;
    virtual void f3(void) = 0;
    virtual void f4(void) = 0;
    virtual void f5(void) = 0;
    virtual void f6(void) = 0;
};
/* The VirtualMemory object (game/vmem.c, vtable VirtualMemory_vtable) a replay queue
 * keeps at its head to hold the recorded packet data. Slot 0xC hands out a
 * pointer into its buffer for a data offset, 0x14 and 0x18 are empty stubs
 * (fn_802E4D6C / fn_802E4D70) and 0x1C always answers yes (fn_802E4D74). */
struct F801B4AC4 {
    virtual void f0() = 0;      /* 0x8: destructor */
    virtual void f1() = 0;      /* 0xC: data offset -> pointer in the buffer */
    virtual void f2() = 0;      /* 0x10: buffer + data offset */
    virtual void f3(int) = 0;   /* 0x14: stub */
    virtual void f4() = 0;      /* 0x18: stub */
    virtual void f5(int) = 0;   /* 0x1C: always 1 */
};
struct F801B49D4 {
    virtual void f0() = 0;      /* 0x8 */
    virtual int f1(int, int) = 0; /* 0xC: data offset -> pointer in the buffer */
};
/* One of the sound objects of the global registered-object list (lbl_8055E434,
 * count lbl_8055E438; fn_801785A4 appends to it).  While a replay is playing,
 * fn_801B50B4 drives every entry through its last two slots each frame: 0x40,
 * the isValid() that fn_801785A4 calls too, says whether the object has
 * something to write, and 0x30 writes its audio for the frame from the current
 * and the next replay frame's recorded data, reporting through its two int*
 * arguments how many bytes of each stream it used. */
struct ReplaySoundObject {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void writeAudio(unsigned char *, int, int *, int *, float) = 0; /* 0x30 */
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual int isValid() = 0; /* 0x40 */
};
}
#pragma cplusplus off
#pragma push
#pragma small_data off
extern char lbl_80435C70[];
#pragma pop
extern char lbl_80335E48[];
extern int lbl_8055E3C4;
extern char *lbl_8055E6DC;
/* Replay playback, the globals the per-frame driver fn_801B50B4 works on: the
 * packet queue being played (created by fn_801B52CC, dropped by fn_801B5274),
 * the rate index its command handlers are given (3 by default), the recorded
 * data of the replay frame whose commands were parsed last, and the tick the
 * audio is currently built for. */
#define gReplayPacketQueue lbl_8055E6D8
#define gReplayRate        lbl_8055E6D4
#define gReplayParsedData  lbl_8055E6DC
#define gCurrentTick       lbl_8055E3C4
/* The replay command block at lbl_80435C70: two header words at +0x200/+0x204
 * and, from +0x208, the 16 command handlers indexed by the opcode byte. */
#define REPLAY_CMD_HANDLERS 0x208
extern void __AXDSPInitCallback_801769E0(void);
extern void Abend_Panic(const char *, ...);
extern int __dt__15shdStateMachineFv_801B496C();
extern void *lbl_8055E6D8;
extern int *fn_801B479C();
extern int fn_801B47BC();
extern int fn_801B4B9C(int);
extern int fn_801B47AC(int);
extern int fn_802E30C8(int *, ...);
extern int fn_801284F8(int, int *);
extern int fn_801B4904();
#pragma push
#pragma small_data off
extern int lbl_80335E10[];
extern int lbl_80335E28[];
#pragma pop
void fn_801B45E0(void *self) {
    /* Reset a frame/resource object to a blank state by zeroing all ten of its
     * int fields (0x00..0x24), in the same order as fn_801B4610's teardown. */
    *(int *)((char *)self + 0x00) = 0;
    *(int *)((char *)self + 0x14) = 0;
    *(int *)((char *)self + 0x10) = 0;
    *(int *)((char *)self + 0x0C) = 0;
    *(int *)((char *)self + 0x08) = 0;
    *(int *)((char *)self + 0x04) = 0;
    *(int *)((char *)self + 0x18) = 0;
    *(int *)((char *)self + 0x24) = 0;
    *(int *)((char *)self + 0x20) = 0;
    *(int *)((char *)self + 0x1C) = 0;
}

#pragma push
#pragma cplusplus on
/* Destroy this object: release its owned subobject/resources, clear its fields, and optionally free it. */
extern "C" void *fn_801B4610(void *self, int shouldDelete) {
    int zero;
    if (self != 0) {
        F801B4610 *obj = *(F801B4610 **)self;
        if (obj != 0) {
            obj->f2(1);
        }
        zero = 0;
        *(int *)((char *)self + 0x00) = zero;
        *(int *)((char *)self + 0x14) = zero;
        *(int *)((char *)self + 0x10) = zero;
        *(int *)((char *)self + 0x0C) = zero;
        *(int *)((char *)self + 0x08) = zero;
        *(int *)((char *)self + 0x04) = zero;
        fn_80128670(*(int *)((char *)self + 0x18));
        *(int *)((char *)self + 0x18) = zero;
        *(int *)((char *)self + 0x24) = zero;
        *(int *)((char *)self + 0x20) = zero;
        *(int *)((char *)self + 0x1C) = zero;
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}
#pragma cplusplus off
#pragma pop
#pragma push
#pragma small_data off
__declspec(section ".data") extern int lbl_80335DB8;
#pragma pop
extern int fn_8012850C(int, int *);
extern int fn_802E4CA4(int);
extern void fn_801B4720(int);
#pragma push
#pragma small_data off
/* Initialize a FramePool: set frame count, allocate its frame records and backing buffer, then reset state. */
void fn_801B46BC(void *framePool, int frameCount, int bufferSize) {
    *(int *)((char *)framePool + 0x1C) = frameCount;
    *(int *)((char *)framePool + 0x18) = fn_8012850C(frameCount * 0xC, &lbl_80335DB8);
    *(int *)((char *)framePool + 4) = bufferSize;
    *(int *)framePool = fn_802E4CA4(bufferSize);
    fn_801B4720((int)framePool);
}
#pragma pop
#pragma push
#pragma cplusplus on
extern "C" void fn_801B4720(int arg0) {
#pragma scheduling invalid_target
    int offset;
    unsigned int i;
    int minusOne;

    i = 0;
    offset = 0;
    minusOne = -1;
    while (i < *(unsigned int *)(arg0 + 0x1C)) {
        int *entries = *(int **)(arg0 + 0x18);
        i++;
        *(int *)((char *)entries + offset) = minusOne;
        *(int *)((char *)*(int **)(arg0 + 0x18) + offset + 4) = 0;
        *(int *)((char *)*(int **)(arg0 + 0x18) + offset + 8) = 0;
        offset += 12;
    }
#pragma scheduling on
    *(int *)(arg0 + 0x10) = *(int *)(arg0 + 0xC) = *(int *)(arg0 + 4);
    *(int *)(arg0 + 8) = 0;
    *(int *)(arg0 + 0x14) = 0;
    *(int *)(arg0 + 0x20) = 0;
    *(int *)(arg0 + 0x24) = 0;
    ((F801B4720 *)*(void **)arg0)->f4();
}
#pragma cplusplus off
#pragma pop

#pragma dont_inline on
/* Return the 12-byte ReplayFrame at index in the FramePool's mFrames array,
 * whose base pointer lives at +0x18 of the pool object. */
int *fn_801B479C(int pool, int index) {
    return (int *)(*(int *)(pool + 0x18) + index * 12);
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_801B47AC(int ring) {
    /* Return the replay ring's start/current index, stored at +0x20 of the
     * queue state subobject (used as QueueStart when walking the frame pool). */
    return *(int *)(ring + 0x20);
}
#pragma dont_inline off

#pragma dont_inline on
// Return the index preceding this replay ring's current index (+0x24), wrapping to count-1 at 0.
int fn_801B47B4(void *ring) {
    return fn_801B47D4(ring, *(int *)((char *)ring + 0x24));
}

/* Advance an index by one within the ring of count entries at +0x1C, wrapping to 0. */
int fn_801B47BC(int ring, int index) {
    int next = index + 1;
    if ((unsigned int)next < *(unsigned int *)(ring + 0x1C)) {
        return next;
    }
    return 0;
}

#pragma dont_inline off

/* Return the previous index in a ring buffer of count entries (at +0x1C), wrapping from 0 to count-1. */
int fn_801B47D4(int ring, int index) {
    if (index != 0) return index - 1;
    return *(int *)(ring + 0x1C) - 1;
}

#pragma dont_inline on
int fn_801B47F0(int pool) {
    /* Used frames in the ring buffer: distance from the read index (+0x20) to
       the write index (+0x24), wrapping around the frame count (+0x1C). */
    unsigned int readIndex;
    unsigned int writeIndex;

    writeIndex = *(unsigned int *)(pool + 0x24);
    readIndex = *(unsigned int *)(pool + 0x20);
    if (readIndex < writeIndex) {
        return writeIndex - readIndex;
    }
    return writeIndex + (*(int *)(pool + 0x1C) - readIndex);
}
#pragma dont_inline off

// Report the 1 MiB buffer size used by the replay/recording memory manager.
int fn_801B4818(void) { return 0x100000; }

#pragma push
#pragma small_data off
void fn_801B4820(int unused, int *arg0, int *arg1, unsigned int arg2) {
    unsigned int value;
    unsigned int limit;

    value = arg2 / ((fn_801B2F24() + 1) * 0x44 + 0xC);
    limit = 0x7E90;
    if ((int)value < 0x7E90) {
        limit = value;
    }
    *arg0 = 0x5000;
    *arg1 = 0x32;
    fn_802E30C8(&lbl_80335DCC, (limit / 9) / 60, (limit / 9) % 60,
                (*arg1 * 12) >> 10, *arg0 / 1024, arg2 >> 10);
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
int fn_801B4904(int self) {
    int base;
    int offset;
    int size;
    ((void (*)(void *))fn_801B45E0)((void *)(self + 4));
    size = ((int (*)(int))fn_801B4818)(self);
    ((void (*)(int, int *, int *, int))fn_801B4820)(self, &base, &offset, size);
    ((void (*)(void *, int, int))fn_801B46BC)((void *)(self + 4), offset, base);
    *(char *)self = 0;
    return self;
}
#pragma pop
int __dt__15shdStateMachineFv_801B496C(int arg0, int arg1) {
    /* shdStateMachine destructor (clone): destroy the embedded subobject at +4 via fn_801B4610(-1),
     * and if arg1 > 0 free the object with fn_80128668 (mode 3). Returns arg0. */
    if (arg0 != 0) {
        fn_801B4610((void *)(arg0 + 4), -1);
        if (arg1 > 0) {
            fn_80128668((void *)arg0);
        }
    }
    return arg0;
}

#pragma dont_inline on
/* Set the replay state machine's byte-0 flag (its per-step marker) to 1. */
void fn_801B49C8(void *stateMachine) {
    *(unsigned char *)stateMachine = 1;
}
#pragma dont_inline reset

extern int fn_801B4B44(char *);
extern void fn_801B4C9C(int, int);
extern void fn_801B4C58();
extern void fn_801B4C60();
extern float fn_801B4D10(int, int);

/* One slot of the FramePool ring the replay queue records into (the
 * "FramePool::mFrames" array, fn_801B479C gives the slot of an index): the
 * tick the packet belongs to (-1 while the slot is free) and the offset of
 * its recorded data in the queue's VirtualMemory pool. */
struct ReplayFrame {
    /* 0x0 */ int tick;
    /* 0x4 */ int unk4;
    /* 0x8 */ int dataOfs;
};
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" int fn_801B4C1C(int, int);
extern "C" int fn_801B49D4(void *queue, void **outCurrent, void **outNext, float *outFraction, int tick) {
    int index;
    int dataOfs;
    volatile int *frame;
    void *memory;
    /* Replay playback: for the frame covering tick, fetch its recorded data and
       the next frame's (reusing the current one on the last frame) from the
       queue's VirtualMemory pool, and output the interpolation fraction.  A
       frame's data offset lives at word 2 of the volatile frame record. */
    if (fn_801B4B44((char *)queue) == 0)
        return 0;
    index = ((int (*)(void *, int))fn_801B4C9C)(queue, tick);
    frame = ((volatile int *(*)(void *, int))fn_801B4C58)(queue, index);
    dataOfs = frame[2];
    memory = *(void **)((char *)queue + 4);
    *outCurrent = (void *)((F801B49D4 *)memory)->f1(dataOfs, 0x2200);
    if (fn_801B4C1C((int)queue, tick) != 0) {
        *outNext = *outCurrent;
    } else {
        frame = ((volatile int *(*)(void *, int))fn_801B4C60)(queue, index);
        dataOfs = frame[2];
        memory = *(void **)((char *)queue + 4);
        *outNext = (void *)((F801B49D4 *)memory)->f1(dataOfs, 0x2200);
    }
    *outFraction = fn_801B4D10((int)queue, tick);
    return 1;
}
/* Replay playback: once this tick's audio command list has been built, hand
 * the recorded data of the current replay frame and of the next one to the
 * queue's VirtualMemory pool (its slot-0x14 method, a stub in that class). */
extern "C" void fn_801B4AC4(int queue, int tick) {
    int index;
    volatile ReplayFrame *frame;
    int dataOfs;
    F801B4AC4 *memory;

    index = ((int (*)(int, int))fn_801B4C9C)(queue, tick);
    frame = ((volatile ReplayFrame *(*)(int, int))fn_801B4C58)(queue, index);
    dataOfs = frame->dataOfs;
    memory = *(F801B4AC4 **)(queue + 4);
    memory->f3(dataOfs);
    frame = ((volatile ReplayFrame *(*)(int, int))fn_801B4C60)(queue, index);
    dataOfs = frame->dataOfs;
    memory = *(F801B4AC4 **)(queue + 4);
    memory->f3(dataOfs);
}
#pragma cplusplus off
int fn_801B4B44(char *object) {
    /* Return true if the object is marked active and its buffer at +4 is non-empty. */
    int result = 0;
    if (fn_801B47F0((int)(object + 4)) != 0 && *(unsigned char *)object != 0) result = 1;
    return result;
}

int fn_801B4B9C(int queue) {
    /* Return the tick of the replay queue's current frame (its base tick): the first field of the frame at the FramePool's current index. */
    return *fn_801B479C(queue + 4, fn_801B47AC(queue + 4));
}

int fn_801B4BDC(int arg0);

#pragma scheduling invalid_target
int fn_801B4C1C(int queue, int tick) {
    /* Return whether tick has reached the current replay frame's base tick: test it against the frame tick reported for the queue (fn_801B4BDC). */
    int frameTick = (int)fn_801B4BDC(queue);
    int tickCopy = tick;
    return tickCopy >= frameTick;
}
int fn_801B4BDC(int queue) {
    /* Return the tick of the replay frame at the queue's adjusted current index (its previous/current frame): the first field of that frame in the FramePool. */
    void *state = (void *)(queue + 4);
    return *fn_801B479C(queue + 4, fn_801B47B4(state));
}

/* Return the replay frame at index from the FramePool at +4 of the queue; the tail-call passes the frame pointer back in r3 and callers use it. */
void fn_801B4C58(int queue, int index) {
    fn_801B479C(queue + 4, index);
}

void fn_801B4C60(int queue, int index) {
    /* Pick the replay frame after index by stepping the queue's cursor at +4 forward and indexing the FramePool; callers use the returned pointer. */
    fn_801B479C(queue + 4, fn_801B47BC(queue + 4, index));
}

#pragma push
#pragma scheduling invalid_target
void fn_801B4C9C(int arg0, int arg1) {
    /* Advance a cursor over the queue at arg0 to reach position arg1: count
       how many 6-byte steps lie between arg1 and the queue base (fn_801B4B9C),
       seed from the start index (fn_801B47AC of the subobject at +4), then step
       forward that many times with fn_801B47BC. */
#define QueueBase fn_801B4B9C
#define QueueStart fn_801B47AC
#define QueueStep fn_801B47BC
    int count;
    int value;

    count = arg1 - ((int (*)(int))QueueBase)(arg0);
    value = QueueStart(arg0 + 4);
    count /= 6;
    while (count-- != 0) {
        value = QueueStep(arg0 + 4, value);
    }
#undef QueueBase
#undef QueueStart
#undef QueueStep
}
#pragma pop
extern float lbl_80562660;
extern float lbl_80562658;
float fn_801B4D10(int queue, int tick) {
    /* Return the interpolation fraction (0..1) of tick within the replay
       queue's current 6-tick frame: ticks elapsed past the frame's base tick,
       modulo 6, divided by 6.0. */
    return ((tick - ((int (*)(int))fn_801B4B9C)(queue)) % 6) / lbl_80562658;
}

extern float lbl_80562668, lbl_8056266C, lbl_80562670, lbl_80562674, lbl_80562678, lbl_8056267C, lbl_80562680;
extern const double lbl_80562688;
int fn_801B4D80(void *arg0, int p1, int p2, float arg3) {
    void *arg1=(void *)p1, *arg2=(void *)p2;
    float a,b,c,d,e,f,t;
    unsigned short x;
    x=*(unsigned short *)((char *)arg2+6);
    *(int *)arg0=*(int *)arg1;
    *(int *)((char *)arg0+4)=*((unsigned char *)arg1+4);
    a=lbl_80562668 < ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    a=a>lbl_80562674 ? a : lbl_80562674;
    t=lbl_8056266C+a*lbl_80562670;
    x=*(unsigned short *)((char *)arg1+6);
    b=lbl_80562668 < ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    b=b>lbl_80562674 ? b : lbl_80562674;
    c=lbl_8056266C+b*lbl_80562670;
    x=*(unsigned short *)((char *)arg2+8);
    *(float *)((char *)arg0+8)=c+arg3*(t-c);
    d=lbl_80562668 < ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    d=d>lbl_80562674 ? d : lbl_80562674;
    t=lbl_8056267C+d*lbl_80562680;
    x=*(unsigned short *)((char *)arg1+8);
    e=lbl_80562668 < ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    e=e>lbl_80562674 ? e : lbl_80562674;
    c=lbl_8056267C+e*lbl_80562680;
    x=*(unsigned short *)((char *)arg2+10);
    *(float *)((char *)arg0+12)=c+arg3*(t-c);
    d=lbl_80562668 < ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    d=d>lbl_80562674 ? d : lbl_80562674;
    t=lbl_8056267C+d*lbl_80562680;
    x=*(unsigned short *)((char *)arg1+10);
    f=lbl_80562668 < ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    f=f>lbl_80562674 ? f : lbl_80562674;
    c=lbl_8056267C+f*lbl_80562680;
    *(float *)((char *)arg0+16)=c+arg3*(t-c);
    return (int)arg0;
}
void *__AXGetStudio_80178C90(void);
int fn_801B4D80(void *, int, int, float);
#pragma push
#pragma scheduling invalid_target
void fn_801B5060(int fromFrame, int toFrame, float fraction) {
    /* Blends the sound parameters of two replay frames and leaves the result in
     * the 20-byte parameter block __AXGetStudio_80178C90() returns.  The frames
     * are 12-byte records: a word at +0 and a byte at +4 are copied from the
     * first one, while the u16 fields at +6, +8 and +0xA are turned into
     * pan (-300..300) and two -4..4 mix values, clamped to 0..1 first, and
     * linearly blended by fraction.  fn_801B50B4 calls this with the pointers
     * fn_801B49D4 fetched for the current and the next frame of the replay
     * queue, and the part of the 6-tick frame already played.
     * Proposed name: AudioBlendReplayParams. */
    void *params = __AXGetStudio_80178C90();
    fn_801B4D80(params, fromFrame, toFrame, fraction);
}
#pragma pop

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
/* Per-frame audio update while a replay is playing (fn_80177E14 calls this in
 * place of the empty fn_801B535C): blend the sound parameters of the replay
 * frame covering the current tick with the next one, let every registered
 * sound object write its audio out of the two frames' recorded data, and -
 * once per replay frame - run the command handlers the recorded stream holds.
 * Finishes by telling the replay queue its data was used, and kicks the DSP
 * init callback once the tick has reached the current frame's base tick. */
extern "C" void fn_801B50B4(void **objects, int objectCount) {
    void *queue = gReplayPacketQueue;
    unsigned char *data;
    unsigned char *frameData;
    int nextData;
    float fraction;
    int i;

    if (queue == 0 || !fn_801B4B44((char *)queue))
        return;

    if (fn_801B49D4(gReplayPacketQueue, (void **)&data, (void **)&nextData, &fraction, gCurrentTick) != 0) {
        int used;
        int nextUsed;

        frameData = data;
        fn_801B5060((int)data, nextData, fraction); /* the 12-byte parameter record */
        data += 0xC;
        nextData += 0xC;

        for (i = 0; i < objectCount; i++) {
            ReplaySoundObject *object = *(ReplaySoundObject **)objects;
            if (object != 0 && object->isValid() != 0) {
                used = -1;
                nextUsed = -1;
                object->writeAudio(data, nextData, &used, &nextUsed, fraction);
                data += used;
                nextData += nextUsed;
            }
            objects++;
        }

        if (gReplayParsedData != (char *)frameData) {
            /* Commands of a replay frame not parsed yet: opcode byte, then the
               handler registered for it, which eats the bytes it needs. */
            for (;;) {
                unsigned int opcode = *data;
                int (*handler)(unsigned char *, int);
                void *handlerSlot;

                if (opcode >= 0x10)
                    break;
                handlerSlot = (char *)lbl_80435C70 + ((opcode * 4) & 0x3FC);
                handler = *(int (**)(unsigned char *, int))((char *)handlerSlot + REPLAY_CMD_HANDLERS);
                if (handler == 0)
                    break;
                data += handler(data + 1, gReplayRate) + 1;
            }
        }
        gReplayParsedData = (char *)frameData;
        fn_801B4AC4((int)gReplayPacketQueue, gCurrentTick);
    }

    if (fn_801B4C1C((int)gReplayPacketQueue, gCurrentTick) != 0)
        __AXDSPInitCallback_801769E0();
}
#pragma cplusplus off
#pragma pop

char fn_801B526C(void) {
    /* Returns the replay-state flag byte lbl_8055E6D0 (grouped with the replay
     * packet queue globals and cleared by the replay reset fn_801B5274).
     * Callers test it as a boolean mode flag to gate driving effects and to
     * bypass the track-order remap. */
    return lbl_8055E6D0;
}

extern int memset(void *, int, unsigned int);
extern int lbl_8055E6D4;
#pragma push
#pragma small_data off
/* Reset replay state: clear the 16-entry command callback table (lbl_80435C70+0x208) and its two header words, drop the replay packet queue and mode flag, and restore the default replay rate. */
void fn_801B5274(void) {
    #pragma scheduling invalid_target
    int tableBytes = 0x40;
    memset((char *)&lbl_80435C70 + 0x208, 0, tableBytes);
    *(int *)((char *)&lbl_80435C70 + 0x200) = 0;
    *(int *)((char *)&lbl_80435C70 + 0x204) = 0;
    lbl_8055E6D8 = 0;
    lbl_8055E6D0 = 0;
    lbl_8055E6D4 = 3;
}
#pragma push
#pragma scheduling invalid_target
/* RealName: InitReplayRecording (tentative). Logs "replay: done creating", allocates/creates the replay packet queue (tag 0x2C, "ReplayPacketQueue::recording") via fn_801284F8/fn_801B4904, and stores it in lbl_8055E6D8 (gReplayPacketQueue?). */
void fn_801B52CC(void) {
    int replayQueue;

    fn_802E30C8((int *)&lbl_80335E10);
    replayQueue = fn_801284F8(0x2C, (int *)&lbl_80335E28);
    if (replayQueue != 0) {
        replayQueue = ((int (*)(int))fn_801B4904)(replayQueue);
    }
    lbl_8055E6D8 = (void *)replayQueue;
}
#pragma pop
/* No operation. */
void fn_801B5318(void) {

}

extern void *lbl_8055E6D8;
extern void fn_801B49C8(void *);
extern int __dt__15shdStateMachineFv_801B496C();
void fn_801B531C(void) {
    /* Tear down the replay state-machine singleton if it was created, then clear its handle. */
    #define gReplayQueue  lbl_8055E6D8                        /* replay queue (shdStateMachine) singleton */
    #define DestroyQueue  __dt__15shdStateMachineFv_801B496C   /* shdStateMachine::~shdStateMachine */
    if (gReplayQueue != 0) {
        ((int (*)(void *, int))DestroyQueue)(gReplayQueue, 1);
        gReplayQueue = 0;
    }
    #undef DestroyQueue
    #undef gReplayQueue
}

void fn_801B5354(void) {
    /* Mark the replay state-machine singleton as active: set the byte-0 step flag
     * of gReplayQueue to 1 (the flag the replay reset fn_801B5274 clears). */
    #define gReplayQueue  lbl_8055E6D8
    #define SetStepFlag   fn_801B49C8
    SetStepFlag(gReplayQueue);
    #undef SetStepFlag
    #undef gReplayQueue
}

/* Empty audio-update callback: fn_80177E14 calls this for normal playback instead of the replay audio processor (fn_801B50B4). */
void fn_801B535C(void) {

}

/* No operation. */
void fn_801B5360(void) {

}

#pragma push
#pragma scheduling invalid_target
void fn_801B5364(int eventCode, int handler) {
    /* Register a replay-event handler pointer in slot eventCode (0-15) of the dispatch table. */
    *(int *)((char *)lbl_80435C70 + 0x208 + eventCode * 4) = handler;
}
#pragma push
#pragma scheduling invalid_target
/* Remove a physics replay event handler by handle; panics if the handle is not registered. */
void fn_801B537C(int handler) {
    unsigned int *entry;
    int i;

    entry = (unsigned int *)lbl_80435C70;
    for (i = 0; i < 16; i++) {
        if ((unsigned int)entry[0x82] == (unsigned int)handler) {
            *(unsigned int *)((char *)lbl_80435C70 + 0x208 + i * 4) = 0;
            return;
        }
        entry++;
    }
    Abend_Panic(lbl_80335E48, handler);
}
#pragma pop
