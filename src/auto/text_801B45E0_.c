// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma small_data off
extern int lbl_80335DCC;
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
/* The VirtualMemory object (game/vmem.c, vtable lbl_8034D1D0) a replay queue
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
struct F801B50B4 {
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
    virtual void f10(unsigned char *, int, int *, int *, float) = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual int f14() = 0;
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
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_802E317C(const char *, ...);
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
void fn_801B45E0(void *arg0) {
    *(int *)((char *)arg0 + 0x00) = 0;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(int *)((char *)arg0 + 0x0C) = 0;
    *(int *)((char *)arg0 + 0x08) = 0;
    *(int *)((char *)arg0 + 0x04) = 0;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(int *)((char *)arg0 + 0x24) = 0;
    *(int *)((char *)arg0 + 0x20) = 0;
    *(int *)((char *)arg0 + 0x1C) = 0;
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
void fn_801B46BC(void *arg0, int arg1, int arg2) {
    *(int *)((char *)arg0 + 0x1C) = arg1;
    *(int *)((char *)arg0 + 0x18) = fn_8012850C(arg1 * 0xC, &lbl_80335DB8);
    *(int *)((char *)arg0 + 4) = arg2;
    *(int *)arg0 = fn_802E4CA4(arg2);
    fn_801B4720((int)arg0);
}
#pragma pop
#pragma push
#pragma cplusplus on
extern "C" void fn_801B4720(int arg0) {
    int offset;
    unsigned int i;
    int minusOne;
    int value;
    int zero;

    i = 0;
    offset = 0;
    minusOne = -1;
    zero = 0;
    while (i < *(unsigned int *)(arg0 + 0x1C)) {
        int *entries = *(int **)(arg0 + 0x18);
        i++;
        *(int *)((char *)entries + offset) = minusOne;
        *(int *)((char *)*(int **)(arg0 + 0x18) + offset + 4) = zero;
        *(int *)((char *)*(int **)(arg0 + 0x18) + offset + 8) = zero;
        offset += 12;
    }
    zero = 0;
    value = *(int *)(arg0 + 4);
    *(int *)(arg0 + 8) = zero;
    *(int *)(arg0 + 0xC) = value;
    *(int *)(arg0 + 0x10) = value;
    *(int *)(arg0 + 0x14) = zero;
    *(int *)(arg0 + 0x20) = zero;
    *(int *)(arg0 + 0x24) = zero;
    ((F801B4720 *)*(void **)arg0)->f4();
}
#pragma cplusplus off
#pragma pop

#pragma dont_inline on
int *fn_801B479C(int arg0, int arg1) {
    return (int *)(*(int *)(arg0 + 0x18) + arg1 * 12);
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_801B47AC(int arg0) {
    return *(int *)(arg0 + 0x20);
}
#pragma dont_inline off

#pragma dont_inline on
int fn_801B47B4(void *arg0) {
    return fn_801B47D4(arg0, *(int *)((char *)arg0 + 0x24));
}

int fn_801B47BC(int arg0, int arg1) {
    int next = arg1 + 1;
    if ((unsigned int)next < *(unsigned int *)(arg0 + 0x1C)) {
        return next;
    }
    return 0;
}

#pragma dont_inline off

int fn_801B47D4(int arg0, int arg1) {
    if (arg1 != 0) return arg1 - 1;
    return *(int *)(arg0 + 0x1C) - 1;
}

#pragma dont_inline on
int fn_801B47F0(int arg0) {
    unsigned int temp_r4;
    unsigned int temp_r5;

    temp_r5 = *(unsigned int *)(arg0 + 0x24);
    temp_r4 = *(unsigned int *)(arg0 + 0x20);
    if (temp_r4 < temp_r5) {
        return temp_r5 - temp_r4;
    }
    return temp_r5 + (*(int *)(arg0 + 0x1C) - temp_r4);
}
#pragma dont_inline off

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
    fn_802E30C8((int *)&lbl_80335DCC, (limit / 9) / 60, (limit / 9) % 60, (0x32 * 0xC) >> 10, *arg0 / 1024, arg2 >> 10);
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
int fn_801B4904(int arg0) {
    int spC;
    int sp8;
    int size;
    ((void (*)(void *))fn_801B45E0)((void *)(arg0 + 4));
    size = ((int (*)(int))fn_801B4818)(arg0);
    ((void (*)(int, int *, int *, int))fn_801B4820)(arg0, &spC, &sp8, size);
    ((void (*)(void *, int, int))fn_801B46BC)((void *)(arg0 + 4), sp8, spC);
    *(char *)arg0 = 0;
    return arg0;
}
#pragma pop
int __dt__15shdStateMachineFv_801B496C(int arg0, int arg1) {
    if (arg0 != 0) {
        fn_801B4610((void *)(arg0 + 4), -1);
        if (arg1 > 0) {
            fn_80128668((void *)arg0);
        }
    }
    return arg0;
}

#pragma dont_inline on
void fn_801B49C8(void *arg0) {
    *(unsigned char *)arg0 = 1;
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
#pragma use_lmw_stmw off
int fn_801B49D4(void *arg0, void **arg1, void **arg2, float *arg3, int arg4) {
    int index;
    int value;
    int *entry;
    void *obj;
    if (fn_801B4B44(arg0) == 0)
        return 0;
    index = ((int (*)(void *, int))fn_801B4C9C)(arg0, arg4);
    entry = ((int *(*)(void *, int))fn_801B4C58)(arg0, index);
    value = entry[2];
    obj = *(void **)((char *)arg0 + 4);
    *arg1 = (void *)((int (*)(void *, int, int))(*(void ***)obj)[3])(obj, value, 0x2200U);
    if (fn_801B4C1C((int)arg0, arg4) != 0) {
        *arg2 = *arg1;
    } else {
        entry = ((int *(*)(void *, int))fn_801B4C60)(arg0, index);
        value = entry[2];
        obj = *(void **)((char *)arg0 + 4);
        *arg2 = (void *)((int (*)(void *, int, int))(*(void ***)obj)[3])(obj, value, 0x2200U);
    }
    *arg3 = fn_801B4D10((int)arg0, arg4);
    return 1;
}

#pragma cplusplus on
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
int fn_801B4B44(char *arg0) {
    int result = 0;
    if (fn_801B47F0((int)(arg0 + 4)) != 0 && *(unsigned char *)arg0 != 0) result = 1;
    return result;
}

int fn_801B4B9C(int arg0) {
    return *fn_801B479C(arg0 + 4, fn_801B47AC(arg0 + 4));
}

int fn_801B4BDC(int arg0);

#pragma push
#pragma processor 750
int fn_801B4C1C(int arg0, int arg1) {
    int result = (int)fn_801B4BDC(arg0);
    int copy = arg1;
    return copy >= result;
}
#pragma pop
int fn_801B4BDC(int arg0) {
    void *p = (void *)(arg0 + 4);
    return *fn_801B479C(arg0 + 4, fn_801B47B4(p));
}

void fn_801B4C58(int arg0, int arg1) {
    fn_801B479C(arg0 + 4, arg1);
}

void fn_801B4C60(int arg0, int arg1) {
    fn_801B479C(arg0 + 4, fn_801B47BC(arg0 + 4, arg1));
}

#pragma push
#pragma scheduling invalid_target
void fn_801B4C9C(int arg0, int arg1) {
    int count;
    int value;

    count = arg1 - ((int (*)(int))fn_801B4B9C)(arg0);
    value = fn_801B47AC(arg0 + 4);
    count /= 6;
    while (count-- != 0) {
        value = fn_801B47BC(arg0 + 4, value);
    }
}
#pragma pop
extern float lbl_80562660;
extern float lbl_80562658;
float fn_801B4D10(int arg0, int arg1) {
    return ((arg1 - ((int (*)(int))fn_801B4B9C)(arg0)) % 6) / lbl_80562658;
}

extern float lbl_80562668, lbl_8056266C, lbl_80562670, lbl_80562674, lbl_80562678, lbl_8056267C, lbl_80562680;
int fn_801B4D80(void *arg0, int p1, int p2, float arg3) {
    void *arg1=(void *)p1, *arg2=(void *)p2;
    float a,b,c,d,e,f,t;
    unsigned short x;
    x=*(unsigned short *)((char *)arg2+6);
    *(int *)arg0=*(int *)arg1;
    *(int *)((char *)arg0+4)=*((unsigned char *)arg1+4);
    a=lbl_80562668 > ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    a=a < lbl_80562674 ? a : lbl_80562674;
    t=lbl_8056266C+a*lbl_80562670;
    x=*(unsigned short *)((char *)arg1+6);
    b=lbl_80562668 > ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    b=b < lbl_80562674 ? b : lbl_80562674;
    c=lbl_8056266C+b*lbl_80562670;
    x=*(unsigned short *)((char *)arg2+8);
    *(float *)((char *)arg0+8)=c+arg3*(t-c);
    d=lbl_80562668 > ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    d=d < lbl_80562674 ? d : lbl_80562674;
    t=lbl_8056267C+d*lbl_80562680;
    x=*(unsigned short *)((char *)arg1+8);
    e=lbl_80562668 > ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    e=e < lbl_80562674 ? e : lbl_80562674;
    c=lbl_8056267C+e*lbl_80562680;
    x=*(unsigned short *)((char *)arg2+10);
    *(float *)((char *)arg0+12)=c+arg3*(t-c);
    d=lbl_80562668 > ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    d=d < lbl_80562674 ? d : lbl_80562674;
    t=lbl_8056267C+d*lbl_80562680;
    x=*(unsigned short *)((char *)arg1+10);
    f=lbl_80562668 > ((float)x-lbl_80562674)/lbl_80562678 ? lbl_80562668 : ((float)x-lbl_80562674)/lbl_80562678;
    f=f < lbl_80562674 ? f : lbl_80562674;
    c=lbl_8056267C+f*lbl_80562680;
    *(float *)((char *)arg0+16)=c+arg3*(t-c);
    return (int)arg0;
}

void *__AXGetStudio_80178C90(void);
int fn_801B4D80(void *, int, int, float);
#pragma push
#pragma scheduling invalid_target
void fn_801B5060(int arg0, int arg1, float arg2) {
 void *studio = __AXGetStudio_80178C90();
 fn_801B4D80(studio, arg0, arg1, arg2);
}
#pragma pop

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801B50B4(void **arg0, int arg1) {
    void *state = lbl_8055E6D8;
    unsigned char *buffer;
    unsigned char *initialBuffer;
    int offset;
    float rate;
    int i;

    if (state == 0)
        goto done;
    if (fn_801B4B44((char *)state) != 0)
        goto state_ready;
    else
        goto done;

state_ready:
    if (fn_801B49D4(lbl_8055E6D8, (void **)&buffer, (void **)&offset, &rate, lbl_8055E3C4) != 0) {
        int length;
        int extra;

        initialBuffer = buffer;
        fn_801B5060((int)buffer, offset, rate);
        buffer += 0xC;
        offset += 0xC;

        for (i = 0; i < arg1; i++) {
            F801B50B4 *object = *(F801B50B4 **)arg0;
            if (object != 0 && object->f14() != 0) {
                length = -1;
                extra = -1;
                object->f10(buffer, offset, &length, &extra, rate);
                buffer += length;
                offset += extra;
            }
            arg0++;
        }

        if (lbl_8055E6DC != (char *)initialBuffer) {
            for (;;) {
                unsigned int code = *buffer;
                int (*callback)(unsigned char *, int);
                void *tableEntry;

                if (code >= 0x10)
                    break;
                tableEntry = (char *)lbl_80435C70 + ((code * 4) & 0x3FC);
                callback = *(int (**)(unsigned char *, int))((char *)tableEntry + 0x208);
                if (callback == 0)
                    break;
                buffer += callback(buffer + 1, lbl_8055E6D4) + 1;
            }
        }
        lbl_8055E6DC = (char *)initialBuffer;
        fn_801B4AC4((int)lbl_8055E6D8, lbl_8055E3C4);
    }

    if (fn_801B4C1C((int)lbl_8055E6D8, lbl_8055E3C4) != 0)
        __AXDSPInitCallback_801769E0();

done:
    ;
}
#pragma cplusplus off
#pragma pop

char fn_801B526C(void) {
    return lbl_8055E6D0;
}

extern int memset(void *, int, unsigned int);
extern int lbl_8055E6D4;
#pragma push
#pragma small_data off
void fn_801B5274(void) {
    int n = 0x40;
    memset((char *)&lbl_80435C70 + 0x208, 0, n);
    *(int *)((char *)&lbl_80435C70 + 0x200) = 0;
    *(int *)((char *)&lbl_80435C70 + 0x204) = 0;
    lbl_8055E6D8 = 0;
    lbl_8055E6D0 = 0;
    lbl_8055E6D4 = 3;
}
#pragma push
#pragma scheduling invalid_target
void fn_801B52CC(void) {
    int result;
    fn_802E30C8((int *)&lbl_80335E10);
    result = fn_801284F8(0x2C, (int *)&lbl_80335E28);
    if (result != 0) {
        result = ((int (*)(int))fn_801B4904)(result);
    }
    lbl_8055E6D8 = (void *)result;
}
#pragma pop
void fn_801B5318(void) {

}

extern void *lbl_8055E6D8;
extern void fn_801B49C8(void *);
extern int __dt__15shdStateMachineFv_801B496C();
void fn_801B531C(void) {
    if (lbl_8055E6D8 != 0) {
        ((int (*)(void *, int))__dt__15shdStateMachineFv_801B496C)(lbl_8055E6D8, 1);
        lbl_8055E6D8 = 0;
    }
}

void fn_801B5354(void) {
    fn_801B49C8(lbl_8055E6D8);
}

void fn_801B535C(void) {

}

void fn_801B5360(void) {

}

#pragma push
#pragma scheduling invalid_target
void fn_801B5364(int arg0, int arg1) {
    *(int *)((char *)lbl_80435C70 + 0x208 + arg0 * 4) = arg1;
}
#pragma push
#pragma scheduling invalid_target
void fn_801B537C(int arg0) {
    unsigned int *ptr;
    int i;

    ptr = (unsigned int *)lbl_80435C70;
    for (i = 0; i < 16; i++) {
        if ((unsigned int)ptr[0x82] == (unsigned int)arg0) {
            *(unsigned int *)((char *)lbl_80435C70 + 0x208 + i * 4) = 0;
            return;
        }
        ptr++;
    }
    fn_802E317C(lbl_80335E48, arg0);
}
#pragma pop
