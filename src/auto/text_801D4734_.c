

      __declspec(section ".rodata") extern char lbl_80338460;
    extern char lbl_803385D0[];
        
    extern char lbl_803387C8[];
  
  #include <types.h>
#include <math.h>

/* One loaded action sequence: a table of the "action_sequence_file" value
 * file (actseq.val), built by fn_801D4B34/fn_801D4CF8 and updated every frame
 * by fn_801D50B8.  Its *_ASE elements are the events it hands out. */
enum ActionSequenceState {
    ACTION_SEQ_UNLOADED = 0, /* no table loaded yet */
    ACTION_SEQ_READY = 1,    /* idle, may be started */
    ACTION_SEQ_PLAYING = 2,  /* its elements are ticking */
    ACTION_SEQ_FINISHED = 3, /* nothing left to run and auto_reset is off */
    ACTION_SEQ_LAP_GAP = 4   /* leader's lap outside first/last_active_lap */
};
struct ActionSequence {
    void *vtable;                /* 0x00 */
    int state;                   /* 0x04, enum ActionSequenceState */
    char name[0x14];             /* 0x08 the sequence's "name" */
    float resetTime;             /* 0x1C "reset_time" */
    unsigned char autoReset;     /* 0x20 "auto_reset" */
    unsigned char triggerResets; /* 0x21 "trigger_resets" */
    unsigned char hasRumble;     /* 0x22 "has_rumble" */
    int firstActiveLap;          /* 0x24 "first_active_lap", -1: no lower bound */
    int lastActiveLap;           /* 0x28 "last_active_lap", -1: no upper bound */
    unsigned char startFlag;     /* 0x2C how fn_801D5328 started the sequence */
    char pad2d[3];               /* 0x2D */
    void **elements;             /* 0x30 the *_ASE elements, &inlineElements */
    int elementCount;            /* 0x34 */
    int elementCapacity;         /* 0x38 bytes; 0x40 = 16 elements */
    void *inlineElements[16];    /* 0x3C what elements points at */
};
/* The AI truck (racer) table: fn_801B2EC0 gives the 0x80-byte slot of a racer
 * and fn_801B2F24 the number of racers.  vtable+0x10 of a slot hands back the
 * racer state block that starts at slot+4. */
struct RacerState {
    char pad0[0x10];
    int laps;                    /* 0x10 laps this racer has completed */
};
/* The player/vehicle object of fn_8017960C. */
struct RacerObject {
    char pad0[0x1F0];
    int competitorId;            /* 0x1F0, the competitor id of the race table */
};
#define COMPETITOR_SETS_LAPS 0x50 /* the competitor id that runs laps */

/* One timed cue an action sequence starts (fn_801D8CAC) and steps every frame
 * (fn_801D8D00): it waits "delay" seconds from startTime, runs for "length"
 * seconds and then finishes.  The two leading virtual slots are the destructor
 * pair, so the first declared method sits at 0x8; the last three are the steps
 * fn_801D8D00 drives from the frame update. */
/* TimedEffect.state: how far a cue has got. */
enum TimedEffectState {
    TIMED_EFFECT_UNSET = 0,  /* its parameters have not been read yet */
    TIMED_EFFECT_READY = 1,  /* may be started (fn_801D8CAC) */
    TIMED_EFFECT_RUNNING = 2,/* fn_801D8D00 steps it every frame */
    TIMED_EFFECT_FINISHED = 3/* its length ran out */
};
#pragma cplusplus on
struct TimedEffect {
    virtual void v0();   virtual void v1();   virtual void v2();
    virtual void v3();   virtual void v4();   virtual void v5();
    virtual void v6();   virtual void v7();   virtual void v8();
    virtual void v9();   virtual void v10();  virtual void v11();
    virtual void onStart();       /* 0x38: run when the cue is started */
    virtual void onWaiting();     /* 0x3C: the delay has not run out yet */
    virtual void onRunning(float);/* 0x40: seconds since the delay ran out */
    virtual void onFinished();    /* 0x44: the length ran out */
    int   state;                  /* 0x04: enum TimedEffectState */
    float delay;                  /* 0x08, the value file's "delay" */
    float length;                 /* 0x0C, the value file's "length" */
    float startTime;              /* 0x10: lbl_8055E3C8 when it was started */
    float interval;               /* 0x14, the value file's "interval" */
    int   index;                  /* 0x18: last (elapsed / interval) step */
};
#pragma cplusplus reset

/* The element fn_801D701C constructs and fn_801D707C reads parameters for is
 * the "RingMaster_ASE" (its name comes back from fn_801D7200) and its vtable
 * is lbl_80338B08: +0x8 fn_801D7034 (delete), +0xC fn_801D707C (read
 * parameters), +0x10 fn_801D71A8 (free the sound), +0x14 fn_801D7200 (class
 * name), +0x18 fn_801D720C, +0x1C fn_801D8AA4.  What is known of its fields:
 * +0x04 state (1 once read), +0x08 the "name" string (0x1E bytes), +0x28
 * "delay", +0x2C a float kept at 0, +0x30 "length", +0x34 a flag byte and
 * +0x38 the "ringon.sfx" Sound fn_80207848 made. */

  extern void fn_801D50B8(int);

extern int fn_8017960C(int);
extern void *fn_801B2EC0(int);
extern int fn_801B2F24(void);
  extern char lbl_80338C78[];
extern char lbl_80338BD0[];
/* The delete entry point: fn_80128584(object, 3), i.e. MemFree on the object's
 * heap.  The destructor helpers below call it with no argument because the
 * object is already in the argument register where they branch out to it. */
extern int fn_80128668(void);
extern void fn_80128658(int);
typedef struct { char *name; int state; } UnkStruct_801D701C;
/* The header every *_ASE action-sequence element shares: the type/vtable table its
 * constructor installs at +0 and the state its state()/start()/update() methods step
 * through (0 unset, 1 ready, 2 running, 3 finished - see enum TimedEffectState). */
typedef struct { char *typeInfo; int state; } AseElementHeader;
/* One "Text_ASE" subtitle cue: fn_801D6D68 constructs it, fn_801D6DC8 reads its
 * parameters from the value file and fn_801D6EE4 copies it into the on-screen
 * display buffer lbl_80442310 when it is triggered. */
struct TextAseElement {
    void *typeInfo;    /* 0x00 the class's type/vtable table lbl_80338B98 */
    int state;         /* 0x04, enum TimedEffectState; 1 once read */
    float length;      /* 0x08 the value file's "length", seconds on screen */
    char title[0x40];  /* 0x0C the value file's "title" */
    char text[0x40];   /* 0x4C the value file's "text" */
};
extern char lbl_80339038[];
extern char lbl_8033905C[];
extern char lbl_8033907C[];
extern float lbl_8055E3C8;
extern char lbl_803388D4[];
extern char lbl_803388F0[];
extern char lbl_803389B8[];
extern char lbl_8033890C[];
extern void fn_8016A240(const char *arg0);
extern int lbl_8055E3C4;
extern double lbl_80562B18;
extern float lbl_80562AE0;
extern void fn_801D9AB8(void *, float);
extern void fn_80178DBC(int, float);
extern char lbl_804422F0[];
  extern float lbl_80562ADC;
  __declspec(section ".rodata") extern float lbl_80558DC4;
extern int fn_801D56C0(void*);
    extern float PSVECDotProduct(void *, void *);
    extern void PSVECNormalize(void *, void *);
    extern float fn_80129DC4(int, float, float);
extern void fn_801D5328(int, int);
extern void fn_801D5A14(int);
extern void fn_801D5A1C(int);
extern int fn_801D59C8(int, int);
extern char lbl_80338D80[];
extern float fn_801D58DC();
extern unsigned char fn_801D592C();
extern void *fn_801D5860();
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma opt_strength_reduction off
extern "C" void fn_801D4734(void) {
    struct Mgr { virtual void v0(); virtual int v1(void *); virtual void v2(); virtual char *v3(void *); };
    extern char lbl_80338460;
    extern char lbl_804422F0[];
    extern signed char lbl_8055E954;
    extern float lbl_80562AD8;
    extern void *fn_802077A4(void *, int, void *, void *);
    extern void fn_801D5520(char *);
    extern void *fn_8001285C(void *);
    extern void **__AXFXGetLfoSinTable_801769CC(void);
    char *base = &lbl_80338460;
    void *obj;
    void *manager;
    Mgr *m;
    lbl_8055E954 = 1;
    obj = fn_802077A4(&lbl_80338460, 5, lbl_804422F0 + 8, lbl_804422F0 + 0x14);
    *(void **)lbl_804422F0 = obj;
    if (obj != 0) {
        *(float *)((char *)obj + 0x6C) = lbl_80562AD8;
    }
    fn_801D5520(base + 0xC);
    manager = fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    m = *(Mgr **)((char *)manager + 0x20);
    if (m->v1(base + 0x18) != 0) {
        char *r = m->v3(base + 0x18);
        fn_801D5520(r);
    }
}
#pragma pop

void fn_801D47F4(void) {
    fn_801D57F0();
}

void fn_801D5488(void);
/* Periodic tick callback: advance all action sequences, then update the global effect timer. */
void fn_801D47F8(void *alarm) {
    fn_801D5650(alarm);
    fn_801D5488();
}

/* Zero the global effect manager's position (+0x14..0x1C) and timer (+0x4),
 * then flush every entry in the global action list via fn_801D56C0. */
int fn_801D481C(void) {
    char* mgr = lbl_804422F0;
    float zero = lbl_80562ADC;
    *(float*)(mgr + 0x14) = zero;
    *(float*)(mgr + 0x18) = zero;
    *(float*)(mgr + 0x1C) = zero;
    *(float*)(mgr + 0x4) = zero;
    return fn_801D56C0(mgr);
}

#pragma cplusplus on
extern "C" signed char lbl_8055E954;
extern "C" char lbl_804422F0[];
extern "C" void fn_801D5730(void);
extern "C" void fn_801D483C(void) {
    /* Clears the active flag, releases the global object at lbl_804422F0 (virtual slot 2, arg 1) if present, and runs cleanup. */
    struct TObjD1Arg { virtual void d0(int); };
    lbl_8055E954 = 0;
    TObjD1Arg *obj = *(TObjD1Arg **)lbl_804422F0;
    if (obj != 0) {
        obj->d0(1);
    }
    fn_801D5730();
}
#pragma cplusplus reset

void fn_801D4888(void) {
    fn_801D5860();
}

void fn_801D5454(void *, void *);
void fn_801D597C(void *, int);
int fn_801D5A68(void *);
#pragma push
#pragma scheduling invalid_target
/* Applies a state change to a registered handle and, when requested and active, updates its position. */
void fn_801D488C(int handle, int state, int updatePosition, float *position) {
    fn_801D597C((void *)handle, state);
    if (updatePosition != 0 && fn_801D5A68((void *)handle) != 0) {
        fn_801D5454((void *)handle, (void *)position);
    }
}
#pragma pop
void fn_801D48F4(void) {
    fn_801D58DC();
}

void fn_801D48F8(void) {
    fn_801D592C();
}

void fn_801D48FC(int arg0) {
    fn_801D5A14(arg0);
}

void fn_801D4900(int arg0) {
    fn_801D5A1C(arg0);
}

void fn_801D4904(void) {
    fn_801D5A24();
}

void fn_801D4908(void) {
    fn_801D5A2C();
}

extern void fn_8000FF88(int, int, const char *, float, float, float, ...);
extern char lbl_80442310[];
extern char lbl_8055AD58[3], lbl_8055AD5C[3];
extern float lbl_8055E3C8, lbl_80562AD8, lbl_80562ADC, lbl_80562AE0, lbl_80562AE4, lbl_80562AE8, lbl_80562AEC, lbl_80562AF0, lbl_80562AF4, lbl_80562AF8, lbl_80562AFC;
extern char *strchr(char *, int);
#pragma push
#pragma processor 750
void fn_801D490C(void) {
    float width, right, x, alpha, t, edge, dy, y, limit;
    int color, n;
    char text[0x40], *src, *dst, *part, *caret;
    x = *(float *)lbl_80442310;
    width = *(float *)(lbl_80442310 + 4);
    right = x + width;
    limit = lbl_8055E3C8;
    if (limit < right) {
        alpha = lbl_80562AE0;
        if (width > lbl_80562AE4) {
            t = limit - x;
            if (t < lbl_80562AE8) {
                t = t / ((lbl_80562AE8 + x) - x);
                alpha = alpha < t ? t : alpha;
                alpha = alpha > lbl_80562ADC ? lbl_80562ADC : alpha;
                alpha = lbl_80562ADC + alpha * lbl_80562AE0;
            } else {
                edge = right - lbl_80562AE8;
                if (limit > edge) {
                    t = (limit - edge) / (right - edge);
                    alpha = alpha < t ? t : alpha;
                    alpha = alpha > lbl_80562ADC ? lbl_80562ADC : alpha;
                    alpha = lbl_80562AE0 + alpha * lbl_80562AEC;
                }
            }
        }
        color = (((unsigned int)(int)(lbl_80562AF0 * alpha) << 24) | 0x00ffffff) & 0xffffff00;
        fn_8000FF88(color, 0xC, lbl_8055AD5C, lbl_80562AF4, lbl_80562ADC, lbl_80562AF8, lbl_80442310 + 0x48);
        src = lbl_80442310 + 8; dst = text; n = 0x40;
        goto copy;
    limit_lbl:
        if (--n > 0) goto copy;
        dst[-1] = 0;
        goto done;
    copy:
        { char c = *src++; *dst++ = c; if ((signed char)c) goto limit_lbl; }
    done:
        y = lbl_80562AD8;
        dy = lbl_80562AFC;
        part = text;
        while (part && (signed char)*part) {
            caret = strchr(part, 0x5e);
            if (caret) *caret = 0;
            fn_8000FF88(color, 0xC, lbl_8055AD58, lbl_80562AE0, lbl_80562ADC, y, part);
            if (caret) part = caret + 1; else part = 0;
            y -= dy;
        }
    }
}
#pragma pop

#pragma dont_inline on
void* fn_801D4B34(void* arg0) {
    *(void**)arg0 = lbl_80338D80;
    *(int*)((char*)arg0 + 4) = 0;
    *(void**)((char*)arg0 + 0x30) = (char*)arg0 + 0x3C;
    *(int*)((char*)arg0 + 0x38) = 0x40;
    *(int*)((char*)arg0 + 0x34) = 0;
    return arg0;
}
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_801D4B60(void *arg0, int arg1) {
    extern char lbl_80338D80[], lbl_80338490[];
    struct Ref { virtual void release(int); };
    struct ResetFields { char pad[0x30]; int buffer; int count; int capacity; };
    char *src;
    int i;
    char *dst;
    int count;
    int offset;
    void **items;
    Ref *entry;

    /* Destructor/cleanup: clear owned refs, reset to "UNLOADED_SEQUENCE", and optionally delete. */
    if (arg0) {
        *(void **)arg0 = lbl_80338D80;
        if (*(int *)((char *)arg0 + 4)) {
            count = *(int *)((char *)arg0 + 0x34);
            *(int *)((char *)arg0 + 4) = 0;
            offset = count * 4;
            goto cleanup_check;
cleanup_body:
            items = *(void ***)((char *)arg0 + 0x30);
            entry = (Ref *)items[count];
            if (count >= 0 && count < *(int *)((char *)arg0 + 0x34)) {
                if (count != *(int *)((char *)arg0 + 0x34) - 1) {
                    items[count] = items[*(int *)((char *)arg0 + 0x34) - 1];
                }
                *(int *)((char *)arg0 + 0x34) = *(int *)((char *)arg0 + 0x34) - 1;
            }
            if (entry) {
                entry->release(1);
            }
cleanup_check:
            if (count-- > 0) {
                offset -= 4;
                goto cleanup_body;
            }
        }
        src = lbl_80338490;
        dst = (char *)arg0 + 8;
        i = 0x14;
        goto copy_body;
copy_check:
        i--;
        if (i > 0) {
            goto copy_body;
        }
        dst[-1] = 0;
        goto copied;
copy_body:
        *dst++ = *src++;
        if ((signed char)dst[-1] != 0) {
            goto copy_check;
        }
copied:
        if ((int)arg0 + 0x30) {
            if ((int)arg0 + 0x30) {
                ((ResetFields *)arg0)->buffer = 0;
                ((ResetFields *)arg0)->count = 0;
                ((ResetFields *)arg0)->capacity = 0;
            }
        }
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}
#pragma cplusplus reset
#pragma pop
int fn_801D4CB8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_801D4CF8(void *arg0, void *arg1) {
    struct Node {
        virtual const char *name();
    };
    struct Dummy {
        virtual void v0();
        virtual int has(char *);
        virtual void v2();
        virtual char *get(char *);
        virtual void v4();
        virtual void v5();
        virtual int getInt(char *, int);
        virtual void v7();
        virtual float value(float, char *);
        virtual void v9();
        virtual unsigned char flag(char *, int);
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual Node *child(int);
    };
    struct Out {
        int pad0;
        int state;
        char name[0x14];
        float f1c;
        unsigned char b20;
        unsigned char b21;
        unsigned char b22;
        int i24;
        int i28;
        int pad2c;
        void **items;
        int count;
    };
    extern char lbl_8055AC80;
    extern char lbl_8055AC88;
    extern float lbl_80562B00;
    extern void *fn_801D7334(void *);
    extern void fn_802E30C8(const char *, const char *);
    extern int stricmp(const char *, const char *);
    char *base = &lbl_80338460;
    Node *node;
    int i;
    Dummy *obj = (Dummy *)arg1;
    Out *out = (Out *)arg0;
    char *src;
    int remaining;
    char *dst;
    if (obj->has(&lbl_8055AC80) == 0x0) {
        ((void (*)(const char *, ...))fn_802E30C8)(base + 0x44);
        return 0;
    }
    src = obj->get(&lbl_8055AC80);
    dst = out->name;
    remaining = 0x14;
    goto copy_body;
copy_limit:
    if (--remaining > 0)
        goto copy_body;
    dst[-1] = 0;
    goto copy_done;
copy_body:
    if ((signed char)(*dst++ = *src++) != 0)
        goto copy_limit;
copy_done:
    i = 0;
    goto loop_test;
loop_body:
    if (stricmp(node->name(), &lbl_8055AC88) == 0) {
        void *r = fn_801D7334(node);
        if (r != 0) {
            int n = out->count;
            void **items = out->items;
            out->count = n + 1;
            items[n] = r;
        }
    } else {
        ((void (*)(const char *, ...))fn_802E30C8)(base + 0x88, out->name, node->name());
    }
    i++;
loop_test:
    node = obj->child(i);
    if (node != 0) goto loop_body;
    out->b20 = obj->flag(base + 0xC8, 0);
    out->f1c = obj->value(*(volatile float *)&lbl_80562B00, base + 0xD4);
    out->b21 = obj->flag(base + 0xE0, 1);
    out->b22 = obj->flag(base + 0xF0, 1);
    out->i24 = obj->getInt(base + 0xFC, -1);
    out->i28 = obj->getInt(base + 0x110, -1);
    out->state = 1;
    return 1;
}
#pragma cplusplus reset
#pragma pop

void fn_801D4F9C(void) {
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D4FA0(void *arg0) {
    /* Call virtual method v8 on each entry in the object's pointer array at +0x30 (count at +0x34). */
    struct E {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8();
    };
    s32 offset;
    s32 i;
    E *obj;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x34)) {
        obj = *(E **)((u8 *)*(void **)((u8 *)arg0 + 0x30) + offset);
        obj->v8();
        offset += 4;
        i += 1;
    }
}
#pragma pop
#pragma cplusplus reset

void fn_801D5010(void) {
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Returns nonzero if any element in the list accepts the given test arguments. */
extern "C" int fn_801D5014(void *list, int arg1, int arg2, int arg3) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual int test(int, int);
    };
    int offset;
    int i;
    Dummy *element;

    i = 0;
    offset = 0;
    while (i < *(int *)((char *)list + 0x34)) {
        element = *(Dummy **)(*(char **)((char *)list + 0x30) + offset);
        if (element->test(arg1, arg2) != 0) {
            return 1;
        }
        offset += 4;
        i += 1;
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop

/* ActionSequence virtual at vtable slot +0x30 (lbl_80338D80): a base-class stub
 * that always reports 0, like its neighbour fn_801D544C at slot +0x2C. */
int fn_801D50A0(void) {
    return 0;
}

#pragma dont_inline on
/* Start the given loaded action sequence (fn_801D5328) with start flag 1;
 * fn_801D50B0 is the flag-0 twin. */
void fn_801D50A8(int sequence) {
    fn_801D5328(sequence, 1);
}

/* Start the action sequence with start flag 0; fn_801D50A8 is the flag-1 twin. */
void fn_801D50B0(int sequence) {
    fn_801D5328(sequence, 0);
}

  #pragma push
  #pragma use_lmw_stmw off
      #pragma cplusplus on

/* ActionSequence::Update - per-frame update of one loaded action sequence.
 * While the sequence plays it ticks its *_ASE elements, and once none of them
 * is waiting any more it either resets them all and goes ready again
 * (auto_reset) or ends.  In every other state it follows the lap of the race
 * leader and keeps the sequence ready only while that lap lies between
 * first_active_lap and last_active_lap. */
void fn_801D50B8(int arg0) {
    /* One *_ASE element: state() is vtable+0x18, update() +0x2C and reset()
     * +0x30; the two leading slots are this ABI's destructor pair. */
    struct Element {
        virtual void destroy();
        virtual void destroyDeleting();
        virtual void v2();
        virtual void v3();
        virtual int state();
        virtual void v5();
        virtual void v6();
        virtual void apply(int mode);
        virtual void v8();
        virtual void update();
        virtual void reset();
    };
    /* One racer slot of the AI truck table (fn_801B2EC0). */
    struct RacerSlot {
        virtual void v0();
        virtual void v1();
        virtual struct RacerState *state();
    };
    extern int fn_8017960C(int);
    extern void *fn_801B2EC0(int);
    extern int fn_801B2F24(void);
    ActionSequence *seq = (ActionSequence *)arg0;
    if (seq->state == ACTION_SEQ_PLAYING) {
        int offset;
        int waiting;
        int i;
        waiting = 0;
        i = 0;
        offset = 0;
        goto test1;
loop1:
        {
            Element *elem = *(Element **)((char *)seq->elements + offset);
            int elemState = elem->state();
            if (elemState == 2) {
                waiting = 1;
                elem->update();
                elem->state();
            }
        }
        offset += 4;
        i++;
test1:
        if (i < seq->elementCount) goto loop1;
        if (waiting == 0) {
            unsigned char autoReset = seq->autoReset;
            if (autoReset != 0) {
                int j = 0;
                offset = 0;
                goto test2;
loop2:
                {
                    Element *nextElem = *(Element **)((char *)seq->elements + offset);
                    nextElem->reset();
                }
                offset += 4;
                j++;
test2:
                if (j < seq->elementCount) goto loop2;
                seq->state = ACTION_SEQ_READY;
                return;
            }
            seq->state = ACTION_SEQ_FINISHED;
        }
        return;
    }
    {
        int leaderLap = -1;
        int racer = 0;
        goto test3;
loop3:
        {
            RacerObject *player = (RacerObject *)fn_8017960C(racer);
            if (player->competitorId == COMPETITOR_SETS_LAPS) {
                RacerSlot *slot = (RacerSlot *)fn_801B2EC0(racer);
                RacerState *racerState = slot->state();
                int lap = racerState->laps;
                if (lap > leaderLap) leaderLap = lap;
            }
            racer++;
        }
test3:
        if (racer < fn_801B2F24()) goto loop3;
        if (leaderLap >= 0) {
            if (seq->state == ACTION_SEQ_READY) {
                if ((seq->firstActiveLap >= 0 && leaderLap < seq->firstActiveLap) ||
                    (seq->lastActiveLap >= 0 && leaderLap > seq->lastActiveLap)) {
                    seq->state = ACTION_SEQ_LAP_GAP;
                    return;
                }
            } else if (seq->state == ACTION_SEQ_LAP_GAP) {
                if ((seq->firstActiveLap < 0 || leaderLap >= seq->firstActiveLap) &&
                    (seq->lastActiveLap < 0 || leaderLap <= seq->lastActiveLap)) {
                    seq->state = ACTION_SEQ_READY;
                }
            }
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
/* Invoke the run method (vtable slot 0x34) on each element in an action sequence.
 * When the sequence state is nonzero, iterates its element list and then sets
 * the state to ACTION_SEQ_READY (1). */
extern "C" void fn_801D52A4(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void run();
    };
    int offset;
    int count;
    void *obj;
    if (*(int *)((char *)arg0 + 4) != 0) {
        count = 0;
        offset = 0;
        while (count < *(int *)((char *)arg0 + 0x34)) {
            obj = *(void **)(*(char **)((char *)arg0 + 0x30) + offset);
            ((Dummy *)obj)->run();
            offset += 4;
            count += 1;
        }
        *(int *)((char *)arg0 + 4) = 1;
    }
}
#pragma cplusplus reset
#pragma pop
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma pop

#pragma dont_inline reset

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
void fn_801D5328(int arg0, int arg1) {
 struct Dummy { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual int state(); virtual void v6(); virtual int apply(int); };
 int offset;
 int mode;
 int changed;
 int i;
 if(*(int *)(arg0+4)!=1) return;
 *(unsigned char *)(arg0+0x2c)=arg1;
 mode=((unsigned char)arg1==0);
 changed=0;
 i=0;
 offset=0;
 goto test1;
loop1:
 {
   Dummy *item=*(Dummy **)(*(int *)(arg0+0x30)+offset);
   if(item->state()==0 && item->apply(mode)!=0) changed=1;
 }
 offset+=4;
 i++;
test1:
 if(i<*(int *)(arg0+0x34)) goto loop1;
 if(changed==0) goto done;
 {
   int j=0;
   offset=0;
   goto test2;
loop2:
   {
     Dummy *item=*(Dummy **)(*(int *)(arg0+0x30)+offset);
     if(item->state()!=0) item->apply(mode);
   }
   offset+=4;
   j++;
test2:
   if(j<*(int *)(arg0+0x34)) goto loop2;
 }
done:
 *(int *)(arg0+4)=2;
}
#pragma cplusplus reset
#pragma pop

/* ActionSequence base-class virtual at vtable slot +0x2C (lbl_80338D80):
 * a stub that always reports 0, like its neighbour fn_801D50A0 at +0x30. */
int fn_801D544C(void) {
    return 0;
}

extern float lbl_80562B04;
/* Update the global effect manager's target position from the given vector and
 * add 3.0 (lbl_80562B04) to its timer at lbl_804422F0+4; self is unused. */
void fn_801D5454(void *self, void *position) {
    float oldTimer;
    float posY;
    float posX;
    float posZ;
    posX = *(float *)position;
    oldTimer = *(float *)(lbl_804422F0 + 4);
    posY = *(float *)((unsigned char *)position + 4);
    posZ = *(float *)((unsigned char *)position + 8);
    *(float *)(lbl_804422F0 + 0x14) = posX;
    *(float *)(lbl_804422F0 + 0x18) = posY;
    *(float *)(lbl_804422F0 + 0x1C) = posZ;
    *(float *)(lbl_804422F0 + 4) = oldTimer + lbl_80562B04;
}

extern float lbl_80562AE0;
extern float lbl_80562B08;
#pragma push
#pragma scheduling invalid_target
void fn_801D5488(void) {
    /* Ticks down the global effect timer at lbl_804422F0+4; while positive, clamps/updates the active value and state flags, otherwise marks inactive. */
    extern char lbl_804422F0[];
    extern float lbl_80562ADC;
    extern float lbl_80562AE0;
    extern float lbl_80562B08;
    char *base;
    char *obj = *(char **)lbl_804422F0;
    if (obj == 0) return;
    base = lbl_804422F0;
    if (*(float *)(base + 4) > lbl_80562ADC) {
        float f2 = lbl_80562AE0;
        float f0 = *(float *)(base + 4) - lbl_80562B08;
        *(float *)(base + 4) = f0;
        f2 = (f2 < f0) ? f2 : f0;
        obj = *(char **)lbl_804422F0;
        if (f2 != *(float *)(obj + 8)) {
            obj[0x4d] = 1;
            *(float *)(obj + 8) = f2;
        }
        obj = *(char **)lbl_804422F0;
        obj[0x4a] = 0;
        obj[0x4b] = 1;
        obj[0x49] = 1;
        return;
    }
    obj[0x4a] = 1;
    obj[0x4c] = 0;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D5520(char *arg0) {
    /* Look up a node named "..." (base+0x150) under the given manager, build
     * a wrapper object for it, and append it to the global list on success. */
    struct Manager { virtual void v0(); virtual void *get(int); };
    struct Node { virtual const char *name(); };
    struct Releasable { virtual void release(int); };
    extern void *fn_80131810(void); extern void fn_80131818(void *); extern void *fn_801D4B34(void *); extern int fn_801D4CF8(void *,void *); extern void *fn_801284F8(int,void *); extern void fn_802E30C8(const char *, const char *); extern int stricmp(const char *,const char *); extern char lbl_80338460; extern int lbl_804423A4[];
    char *base=(char *)&lbl_80338460;
    void *obj;
    Manager *manager=(Manager *)fn_80131810();
    Node *node;
    const char *name;
    int i;
    if(!manager) { ((void (*)(const char *, ...))fn_802E30C8)(base+0x120,arg0); return; }
    i=0;
    goto fetch;
body:
    name=node->name();
    if(stricmp(name,base+0x150)==0) {
        obj=fn_801284F8(0x13c,base+0x160);
        if(obj) obj=fn_801D4B34(obj);
        if(fn_801D4CF8(obj,node)) {
            int n=lbl_804423A4[1];
            void **items=(void **)lbl_804423A4[0];
            lbl_804423A4[1]=n+1;
            items[n]=obj;
        } else if(obj) ((Releasable *)obj)->release(1);
    }
    i++;
fetch:
    node=(Node *)manager->get(i);
    if(node) goto body;
    fn_80131818(manager);
}
#pragma cplusplus reset
#pragma pop

              extern int lbl_804423A4[];
#pragma scheduling invalid_target
                int fn_801D5650(void *alarm) {
    /* Tick every action sequence in the global list (lbl_804423A4). */
    int offset;
    int i;

    offset = 0;
    i = 0;
    while (i < lbl_804423A4[1]) {
        fn_801D50B8(*(int *)((char *)lbl_804423A4[0] + offset));
        offset += 4;
        i += 1;
    }
}
extern void fn_801D52A4();
/* Calls fn_801D52A4 for each element in the global list at lbl_804423A4. */
int fn_801D56C0(void *alarm) {
    int offset;
    int index;
    offset = 0;
    index = 0;
    while (index < lbl_804423A4[1]) {
        fn_801D52A4(*(int *)((char *)lbl_804423A4[0] + offset));
        offset += 4;
        index += 1;
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma cplusplus on
/* Iterates the container's entry list (items at +0x30, count at +0x34) and invokes virtual slot v4 on each entry. */
extern "C" void fn_801D4F2C(void *container) {
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v4();
    };
    int byteOffset = 0;
    int entryIndex = 0;
    while (entryIndex < *(int *)((char *)container + 0x34)) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)container + 0x30) + byteOffset);
        entry->v4();
        byteOffset += 4;
        entryIndex += 1;
    }
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801D5730(void) {
    /* Destroy all entries in the global object list: clean up each, remove from list (swap-with-last), and release. */
    struct Entry { virtual void release(int); };
    int count;
    void *entry;
    count = lbl_804423A4[1];
    goto check;
loop:
    entry = ((void **)lbl_804423A4[0])[count];
    fn_801D4F2C(entry);
    if (count >= 0 && count < lbl_804423A4[1]) {
        if (count != lbl_804423A4[1] - 1) {
            ((void **)lbl_804423A4[0])[count] = ((void **)lbl_804423A4[0])[lbl_804423A4[1] - 1];
        }
        lbl_804423A4[1] = lbl_804423A4[1] - 1;
    }
    if (entry != 0) {
        ((Entry *)entry)->release(1);
    }
check:
    if (count-- > 0) {
        goto loop;
    }
}
#pragma cplusplus reset
#pragma pop

#pragma cplusplus on
extern "C" void fn_801D4FA0(void *);
#pragma cplusplus reset
int fn_801D57F0(void *alarm) {
    /* Call fn_801D4FA0 for each entry in the global object list at lbl_804423A4. */
    int offset;
    int i;
    offset = 0;
    i = 0;
    while (i < lbl_804423A4[1]) {
        fn_801D4FA0(*(void **)((char *)lbl_804423A4[0] + offset));
        offset += 4;
        i += 1;
    }
}

extern int strcmp(const char *, const char *);
#pragma push
#pragma use_lmw_stmw off
/* Searches the global ActionSequence list (lbl_804423A4) for an entry whose name field (+0x08) matches name, returning the ActionSequence or 0 if not found. */
void *fn_801D5860(const char *name) {
#define gActionSequenceList lbl_804423A4
    void **sequences;
    int count;
    int i;
    char *seq;
    sequences = (void **)gActionSequenceList[0];
    count = gActionSequenceList[1];
    i = 0;
    while (i < count) {
        seq = (char *)*sequences;
        if (strcmp(seq + 8, name) == 0) {
            return seq;
        }
        sequences++;
        i++;
    }
    return 0;
#undef gActionSequenceList
}
#pragma pop
extern float lbl_80562B00;
float fn_801D58DC(void *sequence) {
#define gActionSequenceList lbl_804423A4
#define kActionSequenceDefaultValue lbl_80562B00
    void **entries;
    int count;
    if (sequence == 0) {
        return kActionSequenceDefaultValue;
    }
    entries = (void **)gActionSequenceList[0];
    count = gActionSequenceList[1];
    while (count > 0) {
        if (entries[0] == sequence) {
            return *(float *)((char *)sequence + 0x1C);
        }
        entries++;
        count--;
    }
    return kActionSequenceDefaultValue;
#undef gActionSequenceList
#undef kActionSequenceDefaultValue
}

/* Return the byte flag at offset 0x21 for obj if it is registered in lbl_804423A4, else 0. */
unsigned char fn_801D592C(void *obj) {
    void **entries;
    int count;
    if (obj == 0) {
        return 0;
    }
    entries = (void **)lbl_804423A4[0];
    count = lbl_804423A4[1];
    while (count > 0) {
        if (entries[0] == obj) {
            return *(unsigned char *)((char *)obj + 0x21);
        }
        entries++;
        count--;
    }
    return 0;
}

void fn_801D597C(void *actionSequence, int startNow) {
    /* Run a registered action sequence now, either starting or stopping it. */
    void **entries;
    int count;
    int i;
    if (actionSequence == 0) {
        return;
    }
    entries = (void **)lbl_804423A4[0];
    count = lbl_804423A4[1];
    for (i = 0; i < count; i++) {
        if (entries[i] == actionSequence) {
            if (startNow != 0) {
                fn_801D50A8((int)actionSequence);
            } else {
                fn_801D50B0((int)actionSequence);
            }
            return;
        }
    }
}

#pragma dont_inline on
/* Return nonzero if the given object is in lbl_804423A4 and its field at +4 matches arg1. */
int fn_801D59C8(int arg0, int arg1) {
    void **entries;
    int count;
    entries = (void **)lbl_804423A4[0];
    count = lbl_804423A4[1];
    while (count > 0) {
        if (entries[0] == (void *)arg0) {
            return arg1 == *(int *)((char *)arg0 + 4);
        }
        entries++;
        count--;
    }
    return 0;
}
#pragma dont_inline off

#pragma scheduling reset
/* Test (result discarded) whether the registered action sequence's state field
 * (+0x4) is ACTION_SEQ_PLAYING (2); fn_801D59C8 performs the list lookup. */
void fn_801D5A14(int sequence) {
    (void)fn_801D59C8(sequence, ACTION_SEQ_PLAYING);
}

/* Return nonzero when the registered action sequence's state field (+0x4) is
 * ACTION_SEQ_READY (1), or 0 when the sequence is not in the global list. */
void fn_801D5A1C(int sequence) {
    (void)fn_801D59C8(sequence, ACTION_SEQ_READY);
}

/* Return nonzero when the registered action sequence's state field (+0x4) equals 4
 * (ACTION_SEQ_LAP_GAP), or 0 when the sequence is not in the global list. */
int fn_801D5A24(int sequence) {
    return fn_801D59C8(sequence, 4);
}

#pragma scheduling invalid_target
#pragma dont_inline on
int fn_801D5A2C(void *actionSequence, int testArg1, int testArg2) {
#define gActionSequenceList lbl_804423A4
#define ActionSequence_test fn_801D5014
    /* If the action sequence is registered, test its sub-elements with the two arguments; otherwise return 0. */
    void **entries = (void **)gActionSequenceList[0];
    int count = gActionSequenceList[1];
    int i;
    for (i = 0; i < count; i++) {
        if (entries[i] == actionSequence) {
            return ((int (*)(void *, int, int))ActionSequence_test)(actionSequence, testArg1, testArg2);
        }
    }
    return 0;
#undef ActionSequence_test
#undef gActionSequenceList
}

/* Return the "has_rumble" flag (+0x22) of an action sequence if it is registered
 * in the global ActionSequence list (lbl_804423A4), else 0. */
int fn_801D5A68(void *sequence) {
    void **entries = (void **)lbl_804423A4[0];
    int count = lbl_804423A4[1];
    int i;
    for (i = 0; i < count; i++) {
        if (entries[i] == sequence) {
            return *((u8 *)sequence + 0x22);
        }
    }
    return 0;
}

extern char lbl_80338D20[];
/* Initialize an object with primary/secondary vtables and two inline buffer descriptors at +0x10/+0x70. */
void fn_801D5AA8(void *object) {
    char *base;
    char *vtable;
    char *inlineBuffer1;
    char *inlineBuffer2;
    int zero;
    int initialCount1;
    int capacity2;
    base = object;
    vtable = lbl_80338D20;
    *(void **)base = vtable;
    zero = 0;
    inlineBuffer1 = base + 0x1C;
    *(void **)(base + 4) = vtable + 0x38;
    inlineBuffer2 = base + 0x7C;
    initialCount1 = 4;
    *(int *)(base + 8) = zero;
    capacity2 = 0x40;
    *(void **)(base + 0x10) = inlineBuffer1;
    *(int *)(base + 0x18) = initialCount1;
    *(int *)(base + 0x14) = zero;
    *(void **)(base + 0x70) = inlineBuffer2;
    *(int *)(base + 0x78) = capacity2;
    *(int *)(base + 0x74) = zero;
}

extern void fn_801D0824(void *);
void *fn_801D5AF0(void *arg0, int arg1) {
    int field8;
    int has_field;
    void *table;
    void *table2;
    void *child;
    if (arg0 != 0) {
        field8 = *(int *)((char *)arg0 + 8);
        table = lbl_80338D20;
        table2 = (char *)table + 0x38;
        *(void **)arg0 = table;
        has_field = field8 != 0;
        *(void **)((char *)arg0 + 4) = table2;
        if (has_field) {
            *(int *)((char *)arg0 + 8) = 0;
            child = (char *)arg0 + 4;
            if (arg0 != 0) {
                fn_801D0824(child);
            }
            *(int *)((char *)arg0 + 0xC) = -1;
        }
        if ((unsigned int)arg0 + 0x70 != 0) {
            if ((unsigned int)arg0 + 0x70 != 0) {
                *(int *)((char *)arg0 + 0x70) = 0;
                *(int *)((char *)arg0 + 0x74) = 0;
                *(int *)((char *)arg0 + 0x78) = 0;
            }
        }
        if ((unsigned int)arg0 + 0x10 != 0) {
            if ((unsigned int)arg0 + 0x10 != 0) {
                *(int *)((char *)arg0 + 0x10) = 0;
                *(int *)((char *)arg0 + 0x14) = 0;
                *(int *)((char *)arg0 + 0x18) = 0;
            }
        }
        if (arg1 > 0) {
            ((int (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" int fn_801D5BBC(void *out, void *object) {
    extern char lbl_80338460;
    extern char lbl_8055AC90;
    extern char lbl_8055AC98;
    extern char lbl_8055ACA0;
    extern char lbl_8055ACA8;
    extern float lbl_80562AEC;
    extern float lbl_80562B0C;
    extern void fn_801345D8(char *, int, char *, ...);
    extern void fn_801D0800(void *);
    extern void fn_802E30C8(const char *, const char *);
    struct Vec3 {
        float x;
        float y;
        float z;
    };
    struct Dummy {
        virtual void v0();
        virtual int has(char *);
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual int get(char *);
        virtual int count(char *, int);
        virtual void v7();
        virtual float value(char *, float);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual Vec3 vector2(char *, Vec3);
    };
    Dummy *obj = (Dummy *)object;
    char *base = &lbl_80338460;
    int result = 0;
    int i;
    char name[20];
    float f;

    ((int *)out)[3] = obj->count(base + 0x170, -1);
    if (((int *)out)[3] >= 0) {
        for (i = 0; i < 4; i++) {
            int *entry;
            fn_801345D8(name, 0x14, base + 0x17C, i);
            if (obj->has(name) != 0) {
                int n = ((int *)out)[5];
                ((int *)out)[5] = n + 1;
                entry = (int *)(((int *)out)[4] + n * 8);
                entry[0] = obj->get(name);
                fn_801345D8(name, 0x14, base + 0x190, i);
                f = obj->value(name, lbl_80562ADC);
                ((float *)entry)[1] = f * f;
            }
        }
        f = obj->value(&lbl_8055AC90, lbl_80562ADC);
        ((float *)out)[0x18] = f;
        ((float *)out)[0x19] = obj->value(&lbl_8055AC98, f);
        {
            Vec3 def;
            def.x = lbl_80562ADC;
            def.y = lbl_80562ADC;
            def.z = lbl_80562ADC;
            const Vec3 &v = obj->vector2(&lbl_8055ACA0, def);
            ((float *)out)[0xF] = v.x;
            ((float *)out)[0x10] = v.y;
            ((float *)out)[0x11] = v.z;
        }
        {
            Vec3 arg;
            arg.x = ((float *)out)[0xF];
            arg.y = ((float *)out)[0x10];
            arg.z = ((float *)out)[0x11];
            const Vec3 &v = obj->vector2(&lbl_8055ACA8, arg);
            ((float *)out)[0x12] = v.x;
            ((float *)out)[0x13] = v.y;
            ((float *)out)[0x14] = v.z;
        }
        {
            Vec3 def;
            def.x = lbl_80562ADC;
            def.y = lbl_80562ADC;
            def.z = lbl_80562ADC;
            const Vec3 &v = obj->vector2(base + 0x1A0, def);
            ((float *)out)[0x15] = v.x;
            ((float *)out)[0x16] = v.y;
            ((float *)out)[0x17] = v.z;
        }
        ((int *)out)[0x1A] = (int)(lbl_80562B0C * obj->value(base + 0x1AC, lbl_80562AEC));
        fn_801D0800(out ? (char *)out + 4 : (char *)out);
        ((int *)out)[2] = 1;
        result = 1;
    } else {
        ((void (*)(const char *, ...))fn_802E30C8)(base + 0x1BC);
    }
    return result;
}

extern "C" s32 fn_801D5E94(void *object) {
    /* ObstacleActionSequenceEvent's start step: hand every obstacle of the
     * event's group a random throw.
     *
     * While the event is ready (state 1), each obstacle collected in its list
     * (+0x70, count +0x74 -- fn_801D7874 appends the nodes whose "group_id"
     * matches the event's own, read into +0x0C by fn_801D5BBC) gets a direction
     * drawn at random between "dir1" (+0x3C) and "dir2" (+0x48) and a speed
     * drawn between "speed1" (+0x60) and "speed2" (+0x64); both draws come from
     * RNG slot 4 through fn_80129DC4().  A degenerate draw -- a direction of
     * (almost) zero length, or a zero speed -- only tells the obstacle to stop
     * (vtable +0x20); otherwise the direction is normalised, scaled to that
     * speed and handed to the obstacle's throw method (vtable +0x24) together
     * with the event's "throw_pt" (+0x54).
     *
     * The event then waits "reset_timeout" (+0x68, seconds already scaled to
     * frames) in state 2 with its start tick in +0x6C -- fn_801D6080() releases
     * the obstacles once that is up -- or, with no timeout, goes straight to
     * state 3.  Returns 1 when it ran and 0 when the event was not ready. */
    struct Vec { f32 x, y, z; };
    struct Obstacle {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5();
        virtual void stop(s32);                /* vtable +0x20 */
        virtual void setThrow(void *, void *); /* vtable +0x24 */
    };
#define kState          0x08  /* 1 ready, 2 waiting for the reset, 3 done */
#define kDir1           0x3C  /* "dir1": one end of the random direction */
#define kDir2           0x48  /* "dir2": the other end */
#define kThrowPoint     0x54  /* "throw_pt", handed to the obstacle as-is */
#define kSpeed1         0x60  /* "speed1": slowest throw */
#define kSpeed2         0x64  /* "speed2": fastest throw */
#define kResetTimeout   0x68  /* frames to wait before releasing, <=0: none */
#define kStartTick      0x6C  /* frame tick the wait began */
#define kObstacles      0x70  /* the group's obstacles; count at +0x74 */
#define kObstacleCount  0x74
#define kRandomSlot     4     /* the RNG slot fn_80129DC4() draws from */
#define kNearZero       lbl_80558DC4 /* 2.35e-38: bound under which it is zero */
#define kBlendMin       lbl_80562ADC /* 0.0f */
#define kBlendMax       lbl_80562AE0 /* 1.0f */
#define gFrameTick      lbl_8055E3C4 /* global frame-tick counter */

    char *self = (char *)object;
    Vec dir, velocity;
    f32 d1x, d2x, d1y, d1z, d2z, d2y;
    f32 dirX, dirY, dirZ;
    f32 speed, blend;
    s32 byteOffset, i;

    if (*(s32 *)(self + kState) == 1) {
        f32 zero = kBlendMin;
        i = 0;
        byteOffset = 0;
        while (i < *(s32 *)(self + kObstacleCount)) {
            f32 mag;
            speed = fn_80129DC4(kRandomSlot, kBlendMin, kBlendMax);
            blend = fn_80129DC4(kRandomSlot, kBlendMin, kBlendMax);
            d2z = *(f32 *)(self + kDir2 + 8);
            d1z = *(f32 *)(self + kDir1 + 8);
            d2y = *(f32 *)(self + kDir2 + 4);
            d1y = *(f32 *)(self + kDir1 + 4);
            d2x = *(f32 *)(self + kDir2);
            d1x = *(f32 *)(self + kDir1);
            dirZ = d1z + blend * (d2z - d1z);
            dirY = d1y + blend * (d2y - d1y);
            dirX = d1x + blend * (d2x - d1x);
            dir.x = dirX; dir.y = dirY; dir.z = dirZ;
            speed = *(f32 *)(self + kSpeed1) + speed * (*(f32 *)(self + kSpeed2) - *(f32 *)(self + kSpeed1));
            velocity.x = zero; velocity.y = zero; velocity.z = zero;
            mag = PSVECDotProduct(&dir, &dir);
            mag = (float)__fabs(mag);
            if (mag <= kNearZero || (mag = (float)__fabs(speed)) <= kNearZero) {
                Obstacle *obstacle = *(Obstacle **)(*(char **)(self + kObstacles) + byteOffset);
                obstacle->stop(1);
            } else {
                Obstacle *obstacle;
                PSVECNormalize(&dir, &dir);
                velocity.x = dir.x * speed; velocity.y = dir.y * speed; velocity.z = dir.z * speed;
                obstacle = *(Obstacle **)(*(char **)(self + kObstacles) + byteOffset);
                obstacle->setThrow(&velocity, self + kThrowPoint);
            }
            byteOffset += 4;
            i += 1;
        }
        if (*(s32 *)(self + kResetTimeout) > 0) {
            *(s32 *)(self + kState) = 2;
            *(s32 *)(self + kStartTick) = gFrameTick;
        } else {
            *(s32 *)(self + kState) = 3;
        }
        return 1;
    }
    return 0;
#undef kState
#undef kDir1
#undef kDir2
#undef kThrowPoint
#undef kSpeed1
#undef kSpeed2
#undef kResetTimeout
#undef kStartTick
#undef kObstacles
#undef kObstacleCount
#undef kRandomSlot
#undef kNearZero
#undef kBlendMin
#undef kBlendMax
#undef gFrameTick
}

#pragma cplusplus reset
#pragma scheduling reset
#pragma pop

#pragma dont_inline reset
#pragma scheduling reset

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801D6080(void *arg0) {
    int *p = (int *)arg0;
    int offset;
    int count;
    void *obj;
    struct TObjD1Call {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
    };
    /* When playing and its delay has elapsed, notify each element then finish. */
    if (p[2] == 2 && lbl_8055E3C4 - p[0x1B] >= p[0x1A]) {
        count = 0;
        offset = 0;
        while (count < p[0x1D]) {
            obj = *(void **)((char *)p[0x1C] + offset);
            ((TObjD1Call *)obj)->f9();
            offset += 4;
            count++;
        }
        p[2] = 3;
    }
}
#pragma pop
#pragma cplusplus reset

// One value of an action-sequence group and how strong the object's vector has
// to be (its squared length) for the value to fire; the table is in step order.
struct ActionThreshold {
    int value;                  // +0x00 what the group sends when this step is reached
    float limit;                // +0x04 least squared length that reaches it
};

// An action-sequence group: the id its objects must carry and the values it can
// send, in the order their thresholds have to be passed.
struct ActionGroup {
    unsigned char pad[0xC];     // +0x00 the group's own state
    int groupId;                // +0x0C id the object's "group_id" must equal
    struct ActionThreshold *thresholds;  // +0x10 the value/threshold table
    int count;                  // +0x14 entries in it
};

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D611C(void *arg0, void *arg1, void *arg2) {
    // Fire an action-sequence group at an object: unless the object's "group_id"
    // parameter is this group's, do nothing; otherwise send one record for every
    // threshold the object's transformed vector is long enough to pass, stopping
    // at the first threshold it does not reach.
    struct ActionObject {               // the object the group is fired at
        virtual void *get();            // +0x8  its parameter set
        virtual void v1();
        virtual void v2();
        virtual void *transform();      // +0x14 the vector in the object's own space
        virtual short index();          // +0x18 which of the object's slots this is
        virtual void v5();
    };
    struct ParameterSet {               // an object's values, looked up by name
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual int find(char *, int);  // +0x20 the id of a name, -1 when absent
    };
    struct GroupRecord {                // the 32 bytes sent per threshold reached
        float input[3];                 // the vector handed to the group
        float output[3];                // that vector as the object sees it
        short index;                    // the object's slot
        short pad;
        int value;                      // what this threshold is worth
    };
    extern float PSVECDotProduct(float *, float *);
    extern void fn_801796CC(int, void *, int);
    struct GroupRecord record;
    float inZ;
    float inY;
    float inX;
    float length;   // squared length of the transformed vector
    int offset;
    int sent;
    int valid;
    int groupId;
    void *params;
    float *transformed;

    if (((struct ActionGroup *)arg0)->count <= 0) return;
    params = ((struct ActionObject *)arg1)->get();
    if (((struct ActionGroup *)arg0)->groupId < 0) goto is_invalid;
    if (params == 0) goto is_invalid;
    groupId = ((struct ParameterSet *)params)->find(lbl_803385D0, -1);
    if (groupId != ((struct ActionGroup *)arg0)->groupId) goto is_invalid;
    valid = 1;
    goto check_valid;
is_invalid:
    valid = 0;
check_valid:
    if (valid == 0) return;
    inX = ((float *)arg2)[0];
    inY = ((float *)arg2)[1];
    inZ = ((float *)arg2)[2];
    record.input[0] = inX;
    record.input[1] = inY;
    record.input[2] = inZ;
    transformed = (float *)((struct ActionObject *)arg1)->transform();
    record.output[0] = transformed[0];
    record.output[1] = transformed[1];
    record.output[2] = transformed[2];
    record.index = ((struct ActionObject *)arg1)->index();
    length = PSVECDotProduct(record.output, record.output);
    sent = 0;
    offset = 0;
    goto threshold_test;
threshold_loop:
    {
        struct ActionThreshold *step = (struct ActionThreshold *)
            ((char *)((struct ActionGroup *)arg0)->thresholds + offset);
        if (length < step->limit) return;  // the object is not moving fast enough
        record.value = step->value;
        fn_801796CC(10, &record, 32);
    }
    offset += 8;
    sent += 1;
threshold_test:
    if (sent < ((struct ActionGroup *)arg0)->count) goto threshold_loop;
}
#pragma pop

void fn_801D628C(void *object) {
    /* CameraShake_ASE constructor: install the vtable at +0 and clear the fields at +4 and +0x14. */
    *(int *)((char *)object + 4) = 0;
    *(char **)((char *)object + 0) = lbl_80338C78;
    *(int *)((char *)object + 0x14) = 0;
}

void *fn_801D62A8(void *arg0, int arg1) {
    return arg0;
}

int fn_801D6320(void *out, void *object) {
    extern char lbl_80338460;
    extern char lbl_8055ACB0, lbl_8055ACB8, lbl_8055ACC0, lbl_8055ACC8;
    extern float lbl_80562ADC, lbl_80562AE4, lbl_80562B0C;
    extern int fn_801399FC(void);
    extern void fn_802E30C8(const char *, const char *);
    char *messages = &lbl_80338460;
    float a, b;
    #define VT(off) (*(void **)((char *)*(void ***)object + (off)))
    #define LOG ((void (*)(const char *, ...))fn_802E30C8)
    if (((int (*)(void *, const char *))VT(0xC))(object, &lbl_8055ACB0) == 0) { LOG(messages + 0x210); return 0; }
    a = ((float (*)(void *, const char *))VT(0x24))(object, &lbl_8055ACB0);
    if (a < lbl_80562ADC) { LOG(messages + 0x254, a); return 0; }
    *(int *)((char *)out + 0xC) = (int)(lbl_80562B0C * a);
    *(int *)((char *)out + 8) = (int)(lbl_80562B0C * ((float (*)(void *, const char *, float))VT(0x28))(object, &lbl_8055ACB8, lbl_80562ADC));
    if (((int (*)(void *, const char *))VT(0xC))(object, &lbl_8055ACC0) == 0) { LOG(messages + 0x2A4); return 0; }
    b = ((float (*)(void *, const char *, float))VT(0x28))(object, &lbl_8055ACC0, lbl_80562AE4);
    *(float *)((char *)out + 0x10) = b;
    if (b < lbl_80562ADC) { LOG(messages + 0x2E8, b); return 0; }
    *(int *)((char *)out + 0x14) = 0;
    if (((int (*)(void *, const char *))VT(0x5C))(object, &lbl_8055ACC8)) *(int *)((char *)out + 0x14) = fn_801399FC();
    *(signed char *)((char *)out + 0x18) = ((signed char (*)(void *, const char *, int))VT(0x30))(object, messages + 0x338, 0);
    *(int *)((char *)out + 4) = 1;
    return 1;
}

/* AX effect helper: return the address of the LFO sine table used by the FX. */
int *__AXFXGetLfoSinTable_801D64F4(void) {
    extern char lbl_803387A8[];
    return (int *)lbl_803387A8;
}

int fn_801D6500(int effect) {
    /* Return the state (enum TimedEffectState) of a timed effect cue. */
    return ((int *)effect)[1];
}

/* Start a ready timed effect: when its state is READY (1), record the current frame tick as its start tick (+0x1C), move it to RUNNING (2) and report success (1). An effect that is not ready is left alone and reports failure (0). */
int fn_801D6508(int effect) {
    if (((int *)effect)[1] == TIMED_EFFECT_READY) {
        ((int *)effect)[7] = lbl_8055E3C4;
        ((int *)effect)[1] = TIMED_EFFECT_RUNNING;
        return 1;
    }
    return 0;
}

#pragma push
#pragma scheduling invalid_target
/* While active (state 2), after start delay iterate objects from fn_8017960C
 * and apply fn_80267E40 to those passing optional filter fn_80139B5C; advance
 * to state 3 once start+duration has elapsed. */
void fn_801D6534(void *self) {
    extern int fn_80139B5C(int, int);
    extern int fn_8017960C(int);
    extern void fn_80267E40(int, float);
    int object;
    int index;
    int filter;
    if (*(int *)((char *)self + 4) != 2) return;
    if (lbl_8055E3C4 - *(int *)((char *)self + 0x1C) < *(int *)((char *)self + 8))
        goto finish;
    index = 0;
    goto fetch;
process:
    filter = *(int *)((char *)self + 0x14);
    if (filter == 0 || fn_80139B5C(object, filter) != 0)
        fn_80267E40(object, *(float *)((char *)self + 0x10));
    index++;
fetch:
    object = fn_8017960C(index);
    if (object != 0) goto process;
finish:
    if (lbl_8055E3C4 - *(int *)((char *)self + 0x1C) >= *(int *)((char *)self + 8) + *(int *)((char *)self + 0xC))
        *(int *)((char *)self + 4) = 3;
}
#pragma scheduling reset
#pragma pop
/* If the object's state is set (nonzero), clamp it to 1; leave state 0 alone. */
void fn_801D6600(UnkStruct_801D701C *object) {
    if (object->state != 0) {
        object->state = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D6618(UnkStruct_801D701C *object) {
    /* Constructor: install the type/vtable table lbl_80338C40 in the object's
       first field and reset its state. */
    extern char lbl_80338C40[];
    object->name = lbl_80338C40;
    object->state = 0;
}
#pragma scheduling reset

/* Destroy/teardown helper: clear the object's state field at +4 and optionally delete it when deleteFlag > 0. */
int fn_801D6630(int object, int deleteFlag) {
    if (object != 0) {
        ((int *)object)[1] = 0;
        if (deleteFlag > 0) fn_80128668();
    }
    return object;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_801D6678(void *out, void *object) {
    extern char lbl_80338798[];
    extern char lbl_803387B8[];
    extern char lbl_8055ACB0;
    extern char lbl_8055ACB8;
    extern char lbl_8055ACD0;
    extern char lbl_8055ACD4;
    extern float lbl_80562B0C;
    struct Vec3 {
        float x;
        float y;
        float z;
    };
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual int id(char *);
        virtual void v6();
        virtual void v7();
        virtual float value(char *, float);
        virtual void v9();
        virtual unsigned char flag(char *, int);
        virtual Vec3 vector(char *);
    };
    Dummy *obj = (Dummy *)object;
    float first;
    float second;
    float scale;
    first = obj->value(&lbl_8055ACB0, lbl_80562ADC);
    second = obj->value(&lbl_8055ACB8, lbl_80562ADC);
    scale = lbl_80562B0C;
    *(int *)((char *)out + 8) = (int)(scale * first);
    *(int *)((char *)out + 0xC) = (int)(scale * second);
    {
        const Vec3 &v14 = obj->vector(&lbl_8055ACD0);
        *(float *)((char *)out + 0x14) = v14.x;
        *(float *)((char *)out + 0x18) = v14.y;
        *(float *)((char *)out + 0x1C) = v14.z;
    }
    {
        const Vec3 &v8 = obj->vector(&lbl_8055ACD4);
        *(float *)((char *)out + 0x20) = v8.x;
        *(float *)((char *)out + 0x24) = v8.y;
        *(float *)((char *)out + 0x28) = v8.z;
    }
    *(int *)((char *)out + 0x2C) = obj->id(lbl_803387B8);
    *(unsigned char *)((char *)out + 0x30) = obj->flag(lbl_80338798, 0);
    *(int *)((char *)out + 4) = 1;
    return 1;
}
#pragma pop

/* Name accessor: returns the "TrackEffect_ASE" identifier string for this effect system. */
void *fn_801D67D4(void) {
#define STR_TRACK_EFFECT_ASE lbl_803387C8
    return STR_TRACK_EFFECT_ASE;
#undef STR_TRACK_EFFECT_ASE
}

/* Return the current state field (+0x4) of the effect object. */
int fn_801D67E0(int object) {
    return ((UnkStruct_801D701C *)object)->state;
}

int fn_801D67E8(int effect) {
    /* If a timed effect is ready, record the current global tick as its start and mark it running. */
    if (((int *)effect)[1] == TIMED_EFFECT_READY) {
        ((int *)effect)[4] = lbl_8055E3C4;
        ((int *)effect)[1] = TIMED_EFFECT_RUNNING;
        return 1;
    }
    return 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_801D6814(void *arg0) {
    extern int lbl_8055E3C4;
    extern void fn_801E9DC4(void *);
    extern void fn_801796CC(int, void *, int);
    struct MessageData {
        float values[6];
        int unk18;
        int unk1C;
    };
    struct MessageData messageData;
    int state = *(int *)((char *)arg0 + 4);
    int startTick = *(int *)((char *)arg0 + 0x10);
    int delayTicks = *(int *)((char *)arg0 + 0x0C);
    int elapsedTicks = lbl_8055E3C4 - (startTick + delayTicks);

    /* If active (state 2) and delay elapsed, send a 0x20-byte message from arg0 fields and advance to state 3 when duration expires. */
    if (state == 2 && elapsedTicks > 0) {
        messageData.values[0] = *(float *)((char *)arg0 + 0x14);
        messageData.values[1] = *(float *)((char *)arg0 + 0x18);
        messageData.values[2] = *(float *)((char *)arg0 + 0x1C);
        messageData.values[3] = *(float *)((char *)arg0 + 0x20);
        messageData.values[4] = *(float *)((char *)arg0 + 0x24);
        messageData.values[5] = *(float *)((char *)arg0 + 0x28);
        fn_801E9DC4((char *)&messageData + 0x18);
        messageData.unk1C = *(int *)((char *)arg0 + 0x2C);
        fn_801796CC(10, messageData.values, 0x20);
        if (elapsedTicks >= *(int *)((char *)arg0 + 8)) {
            *(int *)((char *)arg0 + 4) = 3;
        }
    }
}
#pragma pop

/* Normalizes the object's +0x4 state/active flag: any non-zero value becomes 1. */
void fn_801D68D0(int object) {
    if (((int *)object)[1] != 0) {
        ((int *)object)[1] = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D68E8(UnkStruct_801D701C *soundEffect) {
    /* SoundEffect_ASE ctor: install its type/vtable table at +0 and clear state. */
    soundEffect->name = lbl_80338BD0;
    soundEffect->state = 0;
}
#pragma scheduling reset
int fn_801D6900(int arg0, int arg1) {
    /* Clear the object's field at +0x4; optionally free the object. */
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" int fn_801D6948(void *out, void *object) {
    extern char lbl_80338460;
    extern char lbl_8055ACB0;
    extern char lbl_8055ACB8;
    extern char lbl_8055ACD0;
    extern char lbl_8055ACD4;
    extern char lbl_8055ACD8;
    extern char lbl_8055ACE0;
    extern float lbl_80562B0C;
    extern float lbl_80562B10;
    extern void *fn_802077A4(int, int, void *, void *);
    extern int fn_80207848(char *, int);
    extern void fn_802E30C8(char *);
    struct Vec3 {
        float x;
        float y;
        float z;
        Vec3() {}
        Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    };
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual int find(char *, int);
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float value(char *, float);
        virtual void v9();
        virtual int flag(char *, int);
        virtual Vec3 vector(char *);
        virtual Vec3 vector2(char *, Vec3);
    };
    char *base = &lbl_80338460;
    int id;
    Dummy *obj = (Dummy *)object;
    float first;
    float second;
    float scale;

    first = obj->value(&lbl_8055ACB0, lbl_80562ADC);
    second = obj->value(&lbl_8055ACB8, lbl_80562ADC);
    scale = lbl_80562B0C;
    *(int *)((char *)out + 8) = (int)(scale * first);
    *(int *)((char *)out + 0xC) = (int)(scale * second);
    {
        const Vec3 &v = obj->vector(&lbl_8055ACD0);
        ((float *)out)[6] = v.x;
        ((float *)out)[7] = v.y;
        ((float *)out)[8] = v.z;
    }
    *(unsigned char *)((char *)out + 0x14) = obj->flag(base + 0x338, 0);
    *(unsigned char *)((char *)out + 0x15) = obj->flag(&lbl_8055ACD8, 1);
    *(unsigned char *)((char *)out + 0x16) = obj->flag(base + 0x378, 1);
    id = obj->find(base + 0x388, 0);
    if (id == 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(base + 0x394);
        return 0;
    }
    {
        const Vec3 &v = obj->vector2(&lbl_8055ACD4, Vec3(lbl_80562ADC, lbl_80562ADC, lbl_80562ADC));
        ((float *)out)[9] = v.x;
        ((float *)out)[10] = v.y;
        ((float *)out)[11] = v.z;
    }
    if (obj->flag(&lbl_8055ACE0, 0) != 0) {
        void *p = fn_802077A4(id, 5, &((float *)out)[9], &((float *)out)[6]);
        ((void **)out)[12] = p;
        if (p != 0) {
            *(float *)((char *)p + 0x6C) = obj->value(base + 0x3C8, lbl_80562B10);
        }
    } else {
        ((volatile int *)out)[12] = fn_80207848((char *)id, 1);
    }
    if (((volatile int *)out)[12] == 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(base + 0x3D8, id);
        return 0;
    }
    *(int *)((char *)out + 4) = 1;
    return 1;
}
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
/* Destroy the thread object stored at +0x30, if any, and clear the slot. */
extern "C" void fn_801D6BD0(void *owner) {
    class ThreadObject {
    public:
        virtual void destroy(int);
    };
    ThreadObject *thread = *(ThreadObject **)((u8 *)owner + 0x30);
    if (thread) {
        if (thread)
            thread->destroy(1);
    }
    *(ThreadObject **)((u8 *)owner + 0x30) = 0;
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset
#pragma scheduling reset
#pragma pop

int fn_801D6C28(void) {
    extern char lbl_80338868[];
    /* Return the address of the "SoundEffect_ASE" name string, used to register and identify that action-sequence element class. */
    return (int)lbl_80338868;
}

/* state() of a SoundEffect_ASE action-sequence element (vtable slot +0x18): report the
 * element's state field (+0x04), which its start/update methods step through. */
int fn_801D6C34(int element) {
    return ((AseElementHeader *)element)->state;
}

/* If the timer object is idle (state 1), stamp its start field with the current global tick (lbl_8055E3C4), switch it to the active state (2) and report success. */
int fn_801D6C3C(int self) {
    if (((int *)self)[1] == 1) {
        ((int *)self)[4] = lbl_8055E3C4;
        ((int *)self)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D6C68(void *arg0)
{
  s32 remaining;
  void *obj;
  f32 value;
  remaining = lbl_8055E3C4 - ((*((s32 *) (((u8 *) arg0) + 0x10))) + (*((s32 *) (((u8 *) arg0) + 0xC))));
  if ((*((s32 *) (((u8 *) arg0) + 4))) != 2)
  {
    return;
    *((u8 *) (((u8 *) obj) + 0x4B)) = 0;
  }
  if (remaining <= 0)
  {
    return;
  }
  if ((*((u8 *) (((u8 *) arg0) + 0x16))) != 0)
  {
    obj = *((void **) (((u8 *) arg0) + 0x30));
    value = lbl_80562AE0;
    if (value != (*((f32 *) (((u8 *) obj) + 8))))
    {
      *((u8 *) (((u8 *) obj) + 0x4D)) = 1;
      *((f32 *) (((u8 *) obj) + 8)) = value;
    }
  }
  if ((*((u8 *) (((u8 *) arg0) + 0x15))) != 0)
  {
    obj = *((void **) (((u8 *) arg0) + 0x30));
    *((u8 *) (((u8 *) obj) + 0x4A)) = 0;
    *((u8 *) (((u8 *) obj) + 0x4B)) = 1;
    *((u8 *) (((u8 *) obj) + 0x49)) = 1;
    if (remaining >= (*((s32 *) (((u8 *) arg0) + 8))))
    {
      obj = *((void **) (((u8 *) arg0) + 0x30));
      *((s32 *) (((u8 *) arg0) + 4)) = 3;
      *((u8 *) (((u8 *) obj) + 0x4A)) = 1;
      *((u8 *) (((u8 *) obj) + 0x4C)) = 0;
    }
  }
  else
  {
    obj = *((void **) (((u8 *) arg0) + 0x30));
    *((u8 *) (((u8 *) obj) + 0x49)) = 1;
    *((u8 *) (((u8 *) obj) + 0x4A)) = 0;
    *((s32 *) (((u8 *) arg0) + 4)) = 3;
  }
}

#pragma scheduling invalid_target
void fn_801D6D28(void* cue) {
    /* If the effect held at +0x30 is active (byte 0x19 set), mark it finished (0x4A=1, 0x4C=0); then reset the cue's state at +4 to ready (1) if it was set. */
    unsigned char* effect = *(unsigned char**)((char*)cue + 0x30);
    if (effect != 0 && effect[0x19] != 0) {
        effect[0x4A] = 1;
        effect[0x4C] = 0;
    }
    if (*(int*)((char*)cue + 4) == 0) {
        return;
    }
    *(int*)((char*)cue + 4) = 1;
}
#pragma scheduling on
void fn_801D6D68(UnkStruct_801D701C *object) {
    /* Constructor: install the type/vtable table lbl_80338B98 in the object's
       first field and reset its state. */
    extern char lbl_80338B98[];
    object->name = lbl_80338B98;
    object->state = 0;
}
#pragma scheduling reset
/* Clear the object's secondary pointer and, if requested, run its cleanup helper. */
int fn_801D6D80(int object, int shouldFree) {
    if (object != 0) {
        ((int *)object)[1] = 0;
        if (shouldFree > 0) fn_80128668();
    }
    return object;
}

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
extern "C" int fn_801D6DC8(void *textElem, void *valueNode) {
    /* Text_ASE parameter reader (vtable+0xC of the cue's class): pull this
       subtitle cue's parameters out of the value-file node -- its "length" in
       seconds (default 5.0) into +8, its "title" into the 64-byte field at
       +0xC and its body "text" into the 64-byte field at +0x4C (both default
       to the empty string and are truncated to 63 characters plus a NUL) --
       then mark the cue ready to be triggered (state = 1). */
    struct ValueNode {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual char *getString(char *, char *);   /* 0x10 */
        virtual void v5(); virtual void v6(); virtual void v7();
        virtual float getFloat(char *, float);     /* 0x20 */
    };
    extern char lbl_8055ACB0; /* "length" */
    extern char lbl_8055ACE8; /* "title" */
    extern char lbl_8055ACF0; /* "" - the default string */
    extern char lbl_8055ACF4; /* "text" */
    ValueNode *node = (ValueNode *)valueNode;
    TextAseElement *cue = (TextAseElement *)textElem;
    char *src;
    int remaining1;
    char *dst1;
    int remaining2;
    char *dst2;

    cue->length = node->getFloat(&lbl_8055ACB0, 5.0f);
    src = node->getString(&lbl_8055ACE8, &lbl_8055ACF0);
    dst1 = cue->title;
    remaining1 = 0x40;
    goto copy_title;
count_title:
    if (--remaining1 > 0) goto copy_title;
    dst1[-1] = 0;
    goto done_title;
copy_title:
    if ((signed char)(*dst1++ = *src++) != 0) goto count_title;
done_title:
    src = node->getString(&lbl_8055ACF4, &lbl_8055ACF0);
    dst2 = cue->text;
    remaining2 = 0x40;
    goto copy_text;
count_text:
    if (--remaining2 > 0) goto copy_text;
    dst2[-1] = 0;
    goto done_text;
copy_text:
    if ((signed char)(*dst2++ = *src++) != 0) goto count_text;
done_text:
    cue->state = 1;
    return 1;
}
#pragma pop
#pragma scheduling reset
#pragma cplusplus reset

extern char lbl_80338868[];
extern char lbl_80338B98[];
extern char lbl_80338878[];
/* Return the address of the "Text_ASE" name string, used to register and
   identify that action-sequence element class. */
int fn_801D6ED0(void) {
    return (int)lbl_80338878;
}

/* Text_ASE_GetState: return the state word (+4) of a Text_ASE action-sequence
 * element -- the value its trigger fn_801D6EE4 checks before showing the text. */
int fn_801D6EDC(int textElem) {
    return ((int *)textElem)[1];
}

#pragma scheduling invalid_target
/* Triggers a Text_ASE action-sequence element when ready (state == 1): copies its
   duration (+8), start timestamp (lbl_8055E3C8), 64-byte title (+0xC) and 64-byte
   body text (+0x4C) into the global display buffer (lbl_80442310), and advances
   its state to 3. */
int fn_801D6EE4(void *textElem) {
    extern char lbl_80442310[];
    extern float lbl_8055E3C8;
    register unsigned char c1;
    register unsigned char *src1;
    register unsigned char *dst1;
    register int count1;
    register unsigned char c2;
    register unsigned char *src2;
    register int count2;
    register unsigned char *dst2;
    register char *displayBuf;
    float duration;
    float startTime;
    if (*(int *)((char *)textElem + 4) != 1) {
        goto fail;
    }
    displayBuf = lbl_80442310;
    duration = *(float *)((char *)textElem + 8);
    startTime = lbl_8055E3C8;
    *(float *)(displayBuf + 4) = duration;
    *(float *)displayBuf = startTime;
    src1 = (unsigned char *)textElem + 0xC;
    dst1 = (unsigned char *)displayBuf + 0x48;
    count1 = 0x40;
    goto copy_first;
first_count:
    if (--count1 > 0) {
        goto copy_first;
    }
    dst1[-1] = 0;
    goto first_done;
copy_first:
    c1 = *src1++;
    *dst1++ = c1;
    if ((signed char)c1 != 0) {
        goto first_count;
    }
first_done:
    src2 = (unsigned char *)textElem + 0x4C;
    dst2 = (unsigned char *)lbl_80442310 + 8;
    count2 = 0x40;
    goto copy_second;
second_count:
    if (--count2 > 0) {
        goto copy_second;
    }
    dst2[-1] = 0;
    goto second_done;
copy_second:
    c2 = *src2++;
    *dst2++ = c2;
    if ((signed char)c2 != 0) {
        goto second_count;
    }
second_done:
    *(int *)((char *)textElem + 4) = 3;
    return 1;
fail:
    return 0;
}
#pragma scheduling reset

/* Re-arm an action-sequence element: if its state field (+4) is active (nonzero), force it back to 1 (ready). */
void fn_801D6FA0(int elem) {
    if (((int *)elem)[1] != 0) {
        ((int *)elem)[1] = 1;
    }
}

/* If this element has not yet triggered, looks up the named object (+8) via
 * fn_8016A15C and, on success, sets flags 0x49=1, 0x4B=0, 0x4A=0 on the
 * target object stored at +0x38, then marks the element as triggered (+0x34). */
void fn_801D6FB8(int self) {
    if (*(unsigned char *)(self + 0x34) == 0) {
        if (fn_8016A15C((char *)self + 8) != 0) {
            int target = ((int *)self)[0x38 / 4];
            *(char *)(target + 0x49) = 1;
            *(char *)(target + 0x4B) = 0;
            *(char *)(target + 0x4A) = 0;
        }
        *(char *)(self + 0x34) = 1;
    }
}

#pragma scheduling invalid_target
/* Constructor for a RingMaster_ASE action-sequence element: install its
 * vtable (lbl_80338B08) at +0 and clear its state word at +4. */
void fn_801D701C(UnkStruct_801D701C *element) {
    extern char lbl_80338B08[];
    element->name = lbl_80338B08;
    element->state = 0;
}
#pragma scheduling reset
int fn_801D7034(int arg0, int arg1) {
    /* Clear the object's field at +0x4; optionally free the object. */
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma cplusplus on
extern "C" int fn_801D707C(void *arg0, void *arg1) {
    struct Dummy {
        virtual void v0();
        virtual char *check(char *);
        virtual void v1();
        virtual char *get(char *);
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual float value(char *, float);
    };
    extern char lbl_80338888[];
    extern char lbl_803388C8[];
    extern char lbl_8055AC80;
    extern char lbl_8055ACB0;
    extern char lbl_8055ACB8;
    extern float lbl_80562ADC;
    extern float lbl_80562AEC;
    extern int fn_80207848(char *, int);
    extern void fn_802E30C8(char *);
    Dummy *obj;
    char *src;
    int remaining;
    char *dst;

    obj = (Dummy *)arg1;
    if (obj->check(&lbl_8055AC80) == 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_80338888);
        return 0;
    }
    src = obj->get(&lbl_8055AC80);
    dst = (char *)arg0 + 8;
    remaining = 0x1E;
    goto copy_body;
copy_limit:
    if (--remaining > 0)
        goto copy_body;
    dst[-1] = 0;
    goto copy_done;
copy_body:
    if ((signed char)(*dst++ = *src++) != 0)
        goto copy_limit;
copy_done:
    *(float *)((char *)arg0 + 0x28) = obj->value(&lbl_8055ACB8, lbl_80562ADC);
    *(float *)((char *)arg0 + 0x30) = obj->value(&lbl_8055ACB0, lbl_80562AEC);
    *(float *)((char *)arg0 + 0x2C) = lbl_80562ADC;
    *(int *)((char *)arg0 + 4) = 1;
    *((char *)arg0 + 0x34) = 0;
    *(int *)((char *)arg0 + 0x38) = fn_80207848(lbl_803388C8, 1);
    return 1;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
/* RingMaster_ASE (vtable lbl_80338B08, class name returned by fn_801D7200):
 * frees the "ringon.sfx" Sound that fn_801D707C created with fn_80207848 and
 * kept at +0x38, then clears the field.  destroy(1) is the deleting destructor
 * call -- vtable +0x8 with the delete flag, as in fn_80207848's cleanup.
 * The original tests the pointer twice (both branches are in the code), so the
 * null check is written twice. */
extern "C" void fn_801D71A8(void *self) {
    struct Sound {
        virtual void destroy(int); /* the deleting destructor, vtable +0x8 */
    };
    Sound *sound = *(Sound **)((char *)self + 0x38);
    if (sound != 0 && sound != 0) {
        sound->destroy(1);
    }
    *(Sound **)((char *)self + 0x38) = 0;
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset

/* Return the "RingMaster_ASE" resource name string. */
void *fn_801D7200(void) {
#define STR_RING_MASTER_ASE lbl_803388D4
    return STR_RING_MASTER_ASE;
#undef STR_RING_MASTER_ASE
}

/* State getter of a RingMaster_ASE action-sequence element (vtable +0x18):
 * returns its +0x04 state word (1 ready, 2 running), as set by fn_801D7214. */
int fn_801D720C(int element) {
    return ((int *)element)[1];
}

int fn_801D7214(int self) {
    /* Start method of a RingMaster_ASE action-sequence element: if it is ready
     * (state 1), stamp its +0x2C start-time field with the current global tick
     * lbl_8055E3C8, switch it to running (state 2) and report success; else fail. */
    if (((int *)self)[1] == 1) {
        ((int *)self)[1] = 2;
        *(float *)((char *)self + 0x2C) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

#pragma dont_inline on
/* Advances this action-sequence element from running (state 2): finishes when its remaining time reaches zero or the accumulated time reaches the limit, or triggers the end action when the running time is below the limit. */
void fn_801D7240(void *arg0) {
    extern float lbl_80562ADC;
    extern float lbl_8055E3C8;
    float runningTime;
    float remainingTime;
    float timeLimit;

    if (*(int *)((char *)arg0 + 4) == 2) {
        remainingTime = *(float *)((char *)arg0 + 0x30);
        if (remainingTime < lbl_80562ADC) {
            fn_801D6FB8((int)arg0);
            *(int *)((char *)arg0 + 4) = 3;
        } else {
            runningTime = *(float *)((char *)arg0 + 0x2C);
            runningTime += *(float *)((char *)arg0 + 0x28);
            timeLimit = lbl_8055E3C8;
            if (remainingTime + runningTime < timeLimit) {
                fn_8016A240((char *)arg0 + 8);
                *(int *)((char *)arg0 + 4) = 3;
            } else if (runningTime < timeLimit) {
                fn_801D6FB8((int)arg0);
            }
        }
    }
}
#pragma dont_inline reset

/* Reset this object's state: clear its timer data, mark it idle, clear the linked
   object's active flags if present, and clear the running flag. */
void fn_801D72D0(void *self) {
    char *linked;
    fn_8016A240((char *)self + 8);
    linked = *(char **)((char *)self + 0x38);
    *(volatile int *)((char *)self + 4) = 1;
    if (linked != 0 && *(unsigned char *)(linked + 0x19) != 0) {
        *(unsigned char *)(linked + 0x4A) = 1;
        *(unsigned char *)(linked + 0x4C) = 0;
    }
    *(unsigned char *)((char *)self + 0x34) = 0;
}

extern void *fn_801284F8(int, void *);
extern void fn_801D5AA8(void *);
extern int stricmp(const char *, const char *);
extern char lbl_80338A40[];
extern char lbl_80338A78[];
extern char lbl_80338B40[];
extern char lbl_80338C08[];
extern char lbl_80338CB0[];
extern char lbl_80338CE8[];
extern char lbl_8055ACFC;
extern char lbl_8055AD08;
/* The factory below is driven entirely by strings.  The request's "type"
 * field is matched against a type name and the product is allocated under
 * its class name; both are entries of the action-sequence string pool at
 * lbl_80338460 (.data), which cannot be given real symbols yet, so they are
 * reached as offsets and aliased here (and #undef'd after the function). */
#define type_obstacle        (strings + 0x484) /* "obstacle" */
#define alloc_Obstacle_ASE   (strings + 0x490) /* "Obstacle_ASE" */
#define type_world_morph     (strings + 0x4A0) /* "world_morph" */
#define alloc_WorldMorph_ASE (strings + 0x4AC) /* "WorldMorph_ASE" */
#define type_phys_path       (strings + 0x4BC) /* "phys_path" */
#define alloc_PhysPath_ASE   (strings + 0x4C8) /* "PhysPath_ASE" */
#define type_camera_shake    (strings + 0x4D8) /* "camera_shake" */
#define alloc_CameraShake_ASE (strings + 0x348) /* "CameraShake_ASE" */
#define type_track_effect    (strings + 0x4E8) /* "track_effect" */
#define alloc_TrackEffect_ASE (strings + 0x368) /* "TrackEffect_ASE" */
#define type_sound_effect    (strings + 0x4F8) /* "sound_effect" */
#define alloc_SoundEffect_ASE (strings + 0x408) /* "SoundEffect_ASE" */
#define alloc_Text_ASE       (strings + 0x418) /* "Text_ASE" */
#define type_surfchange      (strings + 0x508) /* "surfchange" */
#define alloc_SurfChange_ASE (strings + 0x514) /* "SurfChange_ASE" */
#define type_embedded_effect (strings + 0x528) /* "embedded_effect" */
#define alloc_EmbeddedEffect_ASE (strings + 0x538) /* "EmbeddedEffect_ASE" */
#define type_ring_set        (strings + 0x54C) /* "ring_set" */
#define alloc_RingMaster_ASE (strings + 0x474) /* "RingMaster_ASE" */
#define alloc_Trigger_ASE    (strings + 0x558) /* "Trigger_ASE" */
#define type_lightning       (strings + 0x564) /* "lightning" */
#define alloc_Lightning_ASE  (strings + 0x570) /* "Lightning_ASE" */
/* the three names the linker pooled in .sdata instead */
#define field_type           ((const char *)&lbl_8055ACFC) /* "type" */
#define type_text            ((const char *)&lbl_8055ACF4) /* "text" */
#define type_trigger         ((const char *)&lbl_8055AD08) /* "trigger" */
/* vtables of the elements whose constructor is open-coded here */
#define vtable_WorldMorph_ASE     lbl_80338CE8
#define vtable_PhysPath_ASE       lbl_80338CB0
#define vtable_SurfChange_ASE     lbl_80338B40 /* +0x38: vtable of the 2nd base */
#define vtable_EmbeddedEffect_ASE lbl_80338C08
#define vtable_Trigger_ASE        lbl_80338A40
#define vtable_Lightning_ASE      lbl_80338A78
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
/*
 * The *_ASE element factory.  Reads the request's "type" string and builds
 * the action-sequence element it names -- obstacle, world_morph, phys_path,
 * camera_shake, track_effect, sound_effect, text, surfchange,
 * embedded_effect, ring_set, trigger or lightning -- allocating it under its
 * class name and either calling its constructor or setting its vtable here.
 * The element is then handed the request with accept(); an element that
 * refuses the request is destroyed and nothing is returned.
 */
extern "C" void *fn_801D7334(void *arg0) {
    extern char lbl_80338460;
    extern char lbl_8055ACF4;
    struct Request {
        virtual void v0();
        virtual int has(const char *);
        virtual void v2();
        virtual const char *getString(const char *); /* slot 3: a named string field */
    };
    struct WorldMorph_ASE { void *vtable; char pad[0x24]; int value; }; /* 0x2C bytes */
    struct PhysPath_ASE { void *vtable; char pad[0x3C]; int value; };   /* 0x44 bytes */
    struct Element {
        virtual void destroy(int);
        virtual int accept(void *);
    };
    char *strings = (char *)&lbl_80338460;
    Request *request = (Request *)arg0;
    const char *name = request->getString(field_type);
    void *element = 0;
    register void *object;

    if (stricmp(name, type_obstacle) == 0) {
        object = fn_801284F8(0x17C, alloc_Obstacle_ASE);
        if (object != 0) {
            object = ((void *(*)(void *))fn_801D5AA8)(object); /* Obstacle_ASE ctor */
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_world_morph) == 0) {
        object = fn_801284F8(0x2C, alloc_WorldMorph_ASE);
        if (object != 0) {
            ((WorldMorph_ASE *)object)->vtable = vtable_WorldMorph_ASE;
            ((WorldMorph_ASE *)object)->value = 0;
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_phys_path) == 0) {
        object = fn_801284F8(0x44, alloc_PhysPath_ASE);
        if (object != 0) {
            ((PhysPath_ASE *)object)->vtable = vtable_PhysPath_ASE;
            ((PhysPath_ASE *)object)->value = 0;
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_camera_shake) == 0) {
        object = fn_801284F8(0x20, alloc_CameraShake_ASE);
        if (object != 0) {
            object = ((void *(*)(void *))fn_801D628C)(object); /* CameraShake_ASE ctor */
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_track_effect) == 0) {
        object = fn_801284F8(0x34, alloc_TrackEffect_ASE);
        if (object != 0) {
            object = ((void *(*)(void *))fn_801D6618)(object); /* TrackEffect_ASE ctor */
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_sound_effect) == 0) {
        object = fn_801284F8(0x34, alloc_SoundEffect_ASE);
        if (object != 0) {
            object = ((void *(*)(void *))fn_801D68E8)(object); /* SoundEffect_ASE ctor */
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_text) == 0) {
        object = fn_801284F8(0x8C, alloc_Text_ASE);
        if (object != 0) {
            object = ((void *(*)(void *))fn_801D6D68)(object); /* Text_ASE ctor */
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_surfchange) == 0) {
        object = fn_801284F8(0x1B0, alloc_SurfChange_ASE);
        if (object != 0) {
            *(void **)object = vtable_SurfChange_ASE;
            *(void **)((char *)object + 4) = (char *)vtable_SurfChange_ASE + 0x38; /* 2nd base */
            *(void **)((char *)object + 0x24) = (char *)object + 0x30; /* empty list: end = head */
            *(int *)((char *)object + 0x2C) = 0x20;  /* capacity */
            *(int *)((char *)object + 0x28) = 0;     /* count */
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_embedded_effect) == 0) {
        object = fn_801284F8(0x18, alloc_EmbeddedEffect_ASE);
        if (object != 0) {
            *(void **)object = vtable_EmbeddedEffect_ASE;
            *(int *)((char *)object + 4) = 0;
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_ring_set) == 0) {
        object = fn_801284F8(0x3C, alloc_RingMaster_ASE);
        if (object != 0) {
            object = ((void *(*)(void *))fn_801D701C)(object); /* RingMaster_ASE ctor */
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_trigger) == 0) {
        object = fn_801284F8(0x24, alloc_Trigger_ASE);
        if (object != 0) {
            *(void **)object = vtable_Trigger_ASE;
            *(int *)((char *)object + 4) = 0;
        }
        element = object;
        goto done;
    }
    if (stricmp(name, type_lightning) == 0) {
        object = fn_801284F8(0x1C, alloc_Lightning_ASE);
        if (object != 0) {
            *(int *)((char *)object + 4) = 0;
            *(void **)object = vtable_Lightning_ASE;
        }
        element = object;
    }
done:
    if (!element) goto fail;
    if (((Element *)element)->accept(arg0) != 0) return element;
    if (element != 0) ((Element *)element)->destroy(1);
fail:
    return 0;
}
#pragma cplusplus reset
#pragma scheduling reset
#pragma dont_inline reset
#undef type_obstacle
#undef alloc_Obstacle_ASE
#undef type_world_morph
#undef alloc_WorldMorph_ASE
#undef type_phys_path
#undef alloc_PhysPath_ASE
#undef type_camera_shake
#undef alloc_CameraShake_ASE
#undef type_track_effect
#undef alloc_TrackEffect_ASE
#undef type_sound_effect
#undef alloc_SoundEffect_ASE
#undef alloc_Text_ASE
#undef type_surfchange
#undef alloc_SurfChange_ASE
#undef type_embedded_effect
#undef alloc_EmbeddedEffect_ASE
#undef type_ring_set
#undef alloc_RingMaster_ASE
#undef alloc_Trigger_ASE
#undef type_lightning
#undef alloc_Lightning_ASE
#undef field_type
#undef type_text
#undef type_trigger
#undef vtable_WorldMorph_ASE
#undef vtable_PhysPath_ASE
#undef vtable_SurfChange_ASE
#undef vtable_EmbeddedEffect_ASE
#undef vtable_Trigger_ASE
#undef vtable_Lightning_ASE

/* Lightning_ASE's deleting destructor -- the slot +0x8 of the second interface
 * of its vtable (lbl_80338A78 + 0x48).  The class holds nothing that needs
 * cleaning up, so this only hands the object to the delete entry point when it
 * is being deleted rather than destroyed in place, and returns it. */
int fn_801D76CC(int object, int deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668(); /* MemFree; `object` is still in the argument register */
    }
    return object;
}

int fn_801D770C(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Destructor-like helper: clear embedded state at offsets +0x24, +0x28, +0x2C, then optionally free the object. */
void *fn_801D774C(void *object, int shouldDelete) {
    if (object != 0) {
        if (((int)object + 0x24) != 0) {
            if (((int)object + 0x24) != 0) {
                *(int *)((char *)object + 0x24) = 0;
                *(int *)((char *)object + 0x28) = 0;
                *(int *)((char *)object + 0x2C) = 0;
            }
        }
        if (shouldDelete > 0)
            ((void (*)(void *))fn_80128668)(object);
    }
    return object;
}

/* Name accessor: returns the "Obstacle_ASE" identifier string for this effect system. */
char *fn_801D77AC(void) {
    return lbl_803388F0;
}

/* Getter for the word at +0x8 of an Obstacle_ASE effect object: the flag/count
 * that fn_801D5AF0 tests (and clears) before freeing the child at +0x4 and that
 * fn_801D77C0 clamps to 0/1. */
int fn_801D77B8(int object) {
    return ((int *)object)[2];
}

/* Clamps the object's word at +0x8 to 1 if it is nonzero (leaves 0 alone), then returns the object. */
int fn_801D77C0(int object) {
    if (((int *)object)[2] == 0) {
        return object;
    }
    ((int *)object)[2] = 1;
    return object;
}

#pragma cplusplus on
extern "C" void fn_801D77D8(void *obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
    };
    /* Virtual-dispatch thunk: invoke the 12th virtual method (vtable +0x34). */
    ((Dummy *)obj)->f11();
}
#pragma cplusplus reset
void fn_801D77E8(void) {
}

#pragma push
#pragma scheduling invalid_target
#pragma peephole off
static inline int fn_801D77EC_Find(void *arg0, unsigned int arg1) {
    int count;
    unsigned int byteOffset;
    int index;
    void **items;

    count = *(int volatile *)((char *)arg0 + 0x74);
    index = 0;
    byteOffset = 0;
    for (; index < count; index += 1) {
        items = *(void **)((char *)arg0 + 0x70);
        if (*(void **)((char *)items + byteOffset) == (void *)arg1)
            return index;
        byteOffset += 4;
    }
    return -1;
}

void fn_801D77EC(void *list, unsigned int item) {
    int count;
    int lastIndex;
    unsigned int *items;
    /* Remove `item` from the list's pointer array (+0x70, length at +0x74):
     * find its slot, move the last element into it, then shrink the count. */
    int index = fn_801D77EC_Find(list, item);

    if (index == -1)
        return;
    if (index < 0)
        return;
    count = *(int volatile *)((char *)list + 0x74);
    if (index >= count)
        return;
    lastIndex = count - 1;
    if (index != lastIndex) {
        items = *(unsigned int **)((char *)list + 0x70);
        items[index] = items[lastIndex];
    }
    count = *(int volatile *)((char *)list + 0x74);
    *(int *)((char *)list + 0x74) = count - 1;
}

#pragma peephole on
#pragma cplusplus on
extern "C" char lbl_803385D0[];
#pragma cplusplus on
extern "C" void fn_801D7874(void *arg0, void *arg1) {
    struct ObjA {
        virtual void *v0();
    };
    struct ObjB {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual int v6(char *, int);
    };

    ObjA *b = (ObjA *)arg1;
    void *node = b->v0();
    int match;
    int result;
    if (*(int *)((char *)arg0 + 0xc) >= 0 && node != 0 && (result = ((ObjB *)node)->v6(lbl_803385D0, -1)) == *(int *)((char *)arg0 + 0xc)) {
        match = 1;
    } else {
        match = 0;
    }
    if (match) {
        int count = *(int *)((char *)arg0 + 0x74);
        void **items = *(void ***)((char *)arg0 + 0x70);
        *(int *)((char *)arg0 + 0x74) = count + 1;
        items[count] = b;
    }
}

#pragma pop

/* RealName: UnkObj_ClearField28_DestroyIfFlag
 * If object is non-null, clears its int field at +0x28. If arg1 > 0, also
 * calls fn_80128668() (object destruction/finalization path), then returns arg0.
 */
int fn_801D7924(int arg0, int arg1) {
#define DestroyObject fn_80128668
    if (arg0 != 0) {
        ((int *)arg0)[10] = 0;
        if (arg1 > 0) DestroyObject();
    }
    return arg0;
#undef DestroyObject
}

#pragma push
#pragma scheduling invalid_target
/* Return 1 if arg0 matches any id in arg1[0..arg2): if arg0[1] is set use fn_801D9B28(container, id) lookup, else compare arg0[2] directly. */
int fn_801D796C(void *arg0, int *arg1, int arg2) {
    int *entry;
    int idx;

    entry = arg1;
    for (idx = 0; idx < arg2; entry++, idx++) {
        if (((int *)arg0)[1] != 0) {
            if (fn_801D9B28(((int *)arg0)[1], *entry) != 0) {
                return 1;
            }
        } else if (((int *)arg0)[2] == *entry) {
            return 1;
        }
    }
    return 0;
}

extern void *fn_801D9A54(const char *);
extern char lbl_8055ACB0, lbl_8055ACB8, lbl_8055AD10, lbl_8055AD18;
extern float lbl_80562AEC, lbl_80562B0C;
#pragma cplusplus on
extern "C" int fn_801D7A0C(void *arg0, void *arg1) {
    extern void fn_802E30C8(char *);
    struct Manager { virtual void v0(); virtual int has(char *); virtual void v2(); virtual const char *name(char *); virtual void v4(); virtual int number(char *); virtual void v6(); virtual void v7(); virtual float value(char *, float); };
    struct ManagerAlt { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual float value(char *); };
    struct Output { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void finish(); };
    Manager *obj = (Manager *)arg1;
    char *base = &lbl_80338460;
    const char *name;
    int index;
    float value;
    *(void **)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 8) = -1;
    if (obj->has(base + 0x994)) {
        name = obj->name(base + 0x994);
        *(void **)((char *)arg0 + 4) = fn_801D9A54(name);
        if (*(void **)((char *)arg0 + 4) == 0) {
            ((void (*)(const char *, ...))fn_802E30C8)(base + 0x9A0, name);
            return 0;
        }
    } else {
        if (!obj->has(base + 0x9E0)) {
            ((void (*)(const char *, ...))fn_802E30C8)(base + 0x9EC);
            return 0;
        }
        index = obj->number(base + 0x9E0);
        *(int *)((char *)arg0 + 8) = index;
        if (index < 0) {
            ((void (*)(const char *, ...))fn_802E30C8)(base + 0xA40, index);
            return 0;
        }
        if (index >= 0x4B) {
            ((void (*)(const char *, ...))fn_802E30C8)(base + 0xA90, index, 0x4B);
            return 0;
        }
    }
    value = obj->value(&lbl_8055ACB0, lbl_80562AEC);
    if (value < 0.0f) return 0;
    *(int *)((char *)arg0 + 0xC) = (int)(lbl_80562B0C * value);
    value = obj->value(&lbl_8055ACB8, 0.0f);
    *(int *)((char *)arg0 + 0x10) = (int)(lbl_80562B0C * value);
    obj->value(base + 0xAD8, 0.0f);
    *(float *)((char *)arg0 + 0x14) = ((ManagerAlt *)arg1)->value(&lbl_8055AD10);
    obj->value(base + 0xAE4, 1.0f);
    *(float *)((char *)arg0 + 0x18) = ((ManagerAlt *)arg1)->value(&lbl_8055AD18);
    *(int *)((char *)arg0 + 0x28) = 1;
    ((Output *)arg0)->finish();
    return 1;
}
#pragma cplusplus reset

#pragma pop

/* Return the "WorldMorph_ASE" resource name string. */
void *fn_801D7C6C(void) {
#define STR_WORLD_MORPH_ASE lbl_8033890C
    return STR_WORLD_MORPH_ASE;
#undef STR_WORLD_MORPH_ASE
}

/* A WorldMorph_ASE action-sequence element.  fn_801D7C80 starts the blend by
 * stamping startTime and copying fromValue/toValue; fn_801D7D20 steps it;
 * fn_801D7E54 restores it.  Values blend from fromValue to toValue over
 * duration ticks after a delay, and go to a terrain morph group or an
 * indexed audio parameter. */
struct WorldMorphAse {
    void *vtable;       /* 0x00 */
    void *morphGroup;   /* 0x04 target terrain-morph group (else audio param) */
    int audioParam;     /* 0x08 index passed to SetAudioParam */
    int duration;       /* 0x0C blend length in ticks */
    int delay;          /* 0x10 ticks to wait before the blend starts */
    float baseValue;    /* 0x14 weight restored by fn_801D7E54 */
    char unused18[4];   /* 0x18 */
    int startTime;      /* 0x1C frame tick the blend was started at */
    float fromValue;    /* 0x20 blend start value */
    float toValue;      /* 0x24 blend end value */
    int state;          /* 0x28 1 = idle/ready, 2 = running, 3 = finished */
};

/* Return the current state of a WorldMorph_ASE action-sequence element (the
 * state() slot at vtable+0x18); fn_801D7C80 starts it and fn_801D7D20 steps it. */
int fn_801D7C78(struct WorldMorphAse *element) {
    return element->state;
}

extern int fn_802E317C(const char *, ...);
extern char lbl_80338F50[];
#pragma push
#pragma scheduling invalid_target
int fn_801D7C80(void *object, int direction) {
    int *wordFields = (int *)object;
    float *floatFields = (float *)object;

    /* If the action-sequence event is in state 1, initialize its direction values and advance to state 2. */
    if (wordFields[0xA] == 1) {
        wordFields[7] = lbl_8055E3C4;
        switch (direction) {
        case 0:
            floatFields[8] = floatFields[5];
            floatFields[9] = floatFields[6];
            break;
        case 1:
            floatFields[8] = floatFields[6];
            floatFields[9] = floatFields[5];
            break;
        default:
            fn_802E317C(lbl_80338F50, direction);
            break;
        }
        wordFields[0xA] = 2;
        return 1;
    }
    return 0;
}

void fn_801D7D20(void *arg0) {
    /* Advance a running WorldMorph_ASE element: blend its saved start value
     * toward its end value over the element's duration, apply the result to
     * the chosen morph group or audio parameter, then mark it finished. */
    #define gFrameTick lbl_8055E3C4       /* global frame-tick counter */
    #define kBlendMax lbl_80562AE0         /* 1.0f: upper bound on the blend */
    #define kBlendMin lbl_80562ADC         /* 0.0f: lower bound / int->float bias */
    #define ApplyGroupWeight fn_801D9AB8
    #define SetAudioParam fn_80178DBC
    struct WorldMorphAse *binding = (struct WorldMorphAse *)arg0;
    int elapsed;
    void *group;
    register float duration;
    float fromValue;
    float toValue;
    float fraction;
    float value;

    if (binding->state == 2) {
        elapsed = (gFrameTick - binding->startTime) - binding->delay;
        if (elapsed >= 0) {
            fraction = kBlendMax;
            duration = (float)binding->duration;
            toValue = binding->toValue;
            fromValue = binding->fromValue;
            fraction = fraction < (((float)elapsed - kBlendMin) / (duration - kBlendMin))
                           ? fraction
                           : (((float)elapsed - kBlendMin) / (duration - kBlendMin));
            fraction = fraction > kBlendMin ? fraction : kBlendMin;
            value = fromValue + fraction * (toValue - fromValue);
            group = binding->morphGroup;
            if (group != 0) {
                ApplyGroupWeight(group, value);
            } else {
                SetAudioParam(binding->audioParam, value);
            }
        }
        if (elapsed >= binding->duration) {
            binding->state = 3;
        }
    }
    #undef gFrameTick
    #undef kBlendMax
    #undef kBlendMin
    #undef ApplyGroupWeight
    #undef SetAudioParam
}

#pragma pop

void fn_801D7E3C(int binding) {
    /* Mark an active audio/parameter binding as applied: set its state field at +0x28 to 1 when it is nonzero. */
    if (((int *)binding)[10] != 0) {
        ((int *)binding)[10] = 1;
    }
}

extern void fn_801D9AB8(void *, float);
extern void fn_80178DBC(int, float);
/* Restores an audio/parameter binding to its saved base value if the slot is active,
 * not already applied, and has a value to restore. */
void fn_801D7E54(void *arg0) {
#define ApplyGroupWeight fn_801D9AB8
#define SetAudioParam fn_80178DBC
    void *targetGroup;
    float baseValue;
    if (*(int *)((char *)arg0 + 0x28) != 0) {
        if (*(int *)((char *)arg0 + 0x10) == 0) {
            targetGroup = *(void **)((char *)arg0 + 4);
            baseValue = *(float *)((char *)arg0 + 0x14);
            if (targetGroup != 0) ApplyGroupWeight(targetGroup, baseValue);
            else SetAudioParam(*(int *)((char *)arg0 + 8), baseValue);
        }
        *(int *)((char *)arg0 + 0x28) = 1;
    }
#undef ApplyGroupWeight
#undef SetAudioParam
}

#pragma cplusplus on
extern "C" void fn_80128658(int);
extern "C" void *fn_801D7EC0(void *arg0, s32 arg1) {
    struct Entry_801D7EC0 {
        virtual void destroy(s32);
    };
    void *child;
    int val;

    if (arg0 != 0) {
        *(void **)arg0 = (void *)lbl_80338CB0;
        child = *(void **)((u8 *)arg0 + 0x2C);
        *(s32 *)((u8 *)arg0 + 0x40) = 0;
        if (child != 0) {
            if (child != 0)
                ((Entry_801D7EC0 *)child)->destroy(1);
        }
        val = *(int *)((u8 *)arg0 + 0x3C);
        if (val != 0)
            fn_80128658(val);
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma cplusplus reset
int fn_801D7F5C(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* One "PhysPath_ASE" action-sequence element (its name table is lbl_80338928 and
 * its vtable lbl_80338CB0): fn_801D7F9C reads its parameters out of the
 * action-sequence value table, fn_801D825C resolves its two names to the object
 * it drives, fn_801D815C starts it and fn_801D82A0 fires the target once its
 * delay has run out. */
struct PhysPathAse {
    void *typeInfo;        /* 0x00 the class's type/vtable table lbl_80338CB0 */
    char objectName[0x14]; /* 0x04 the value table's "object" ("*": none) */
    char pathName[0x14];   /* 0x18 the value table's "path" */
    void *target;          /* 0x2C the object fn_801D825C resolved the names to */
    int delay;             /* 0x30 the "delay" in ticks: seconds * 59.94 */
    int startTime;         /* 0x34 the tick fn_801D815C started the element at */
    int direction;         /* 0x38 0: drive the target with +1.0, 1: with -1.0 */
    void *killBound;       /* 0x3C the "kill_bound" value list, 0 when unset */
    int state;             /* 0x40, enum TimedEffectState */
};

/* RealName: PhysPathActionSequenceEvent::Read
 * The "PhysPath_ASE" element's read method (vtable+0xC): take this cue's
 * parameters out of the action-sequence value table -- its "path" (the cue is
 * refused, with a diagnostic, when the table has none) and its "object" (the
 * name "*" when the table names none) into the two 20-byte name fields, the
 * "kill_bound" flag as the parsed value list fn_801399FC builds, and its
 * "delay" in seconds as a tick count at 59.94 ticks per second -- then mark the
 * cue ready (state 1) and report what it was bound to. */
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_801D7F9C(void *arg0, void *arg1) {
    /* The action-sequence value table (actseq.val) an element reads itself
     * from; the two leading vtable entries are the destructor pair, so the
     * first method declared here sits at +0x8. */
    struct ValueTable {
        virtual void v0();                         /* 0x08 */
        virtual char *find(char *);                /* 0x0C: a key's entry, 0 if absent */
        virtual void v2();                         /* 0x10 */
        virtual char *getString(char *);           /* 0x14 */
        virtual char *getStringOr(char *, char *); /* 0x18 */
        virtual void v5();   virtual void v6();   virtual void v7();
        virtual float getFloat(float, char *);     /* 0x28: default in f1, key in r4 */
        virtual void v9();   virtual void v10();  virtual void v11();
        virtual void v12();  virtual void v13();  virtual void v14();
        virtual void v15();  virtual void v16();  virtual void v17();
        virtual void v18();  virtual void v19();  virtual void v20();
        virtual int getInt(char *);                /* 0x5C */
    };
    extern void fn_802E30C8(const char *, ...);
    extern int fn_801399FC(void);
    extern char lbl_80338460;
    extern char lbl_8055AD20; /* "path" */
    extern char lbl_8055AD28; /* "object" */
    extern char lbl_8055AD30; /* "*" - the object name when the table names none */
    extern char lbl_8055ACB8; /* "delay" */
#define MSG_NO_PATH (base + 0xB24) /* "PhysPathActionSequenceEvent: no \"path\" was found in the table!" */
#define KEY_KILL_BOUND (base + 0xB64) /* "kill_bound" */
#define MSG_INITIALIZED (base + 0xB70) /* "PhysPathActionSequenceEvent: initialized with object \"%s\", path \"%s\"" */
#define TICKS_PER_SECOND 59.94f /* the value files' seconds-to-ticks scale */
    char *base = &lbl_80338460;
    ValueTable *table = (ValueTable *)arg1;
    PhysPathAse *effect = (PhysPathAse *)arg0;
    char *path;
    char *pathSrc;
    int pathRemaining;
    char *pathDst;
    char *objectSrc;
    int objectRemaining;
    char *objectDst;
    int killBound;
    float delaySeconds;
    float ticksPerSecond;
    float ticks;
    path = table->find(&lbl_8055AD20);
    if (path == 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(MSG_NO_PATH);
        return 0;
    }
    pathSrc = table->getString(&lbl_8055AD20);
    pathDst = effect->pathName;
    pathRemaining = 0x14;
    goto copy_path_body;
copy_path_limit:
    if (--pathRemaining > 0)
        goto copy_path_body;
    pathDst[-1] = 0;
    goto copy_path_done;
copy_path_body:
    if ((signed char)(*pathDst++ = *pathSrc++) != 0)
        goto copy_path_limit;
copy_path_done:
    objectSrc = table->getStringOr(&lbl_8055AD28, &lbl_8055AD30);
    objectDst = effect->objectName;
    objectRemaining = 0x14;
    goto copy_object_body;
copy_object_limit:
    if (--objectRemaining > 0)
        goto copy_object_body;
    objectDst[-1] = 0;
    goto copy_object_done;
copy_object_body:
    if ((signed char)(*objectDst++ = *objectSrc++) != 0)
        goto copy_object_limit;
copy_object_done:
    killBound = table->getInt(KEY_KILL_BOUND);
    effect->killBound = killBound == 0 ? 0 : (void *)fn_801399FC();
    delaySeconds = table->getFloat(0.0f, &lbl_8055ACB8);
    ticksPerSecond = TICKS_PER_SECOND;
    effect->direction = 0;
    ticks = ticksPerSecond * delaySeconds;
    effect->target = 0;
    effect->state = TIMED_EFFECT_READY;
    effect->delay = (int)ticks;
    ((void (*)(const char *, ...))fn_802E30C8)(MSG_INITIALIZED, effect->objectName, effect->pathName);
    return 1;
#undef MSG_NO_PATH
#undef KEY_KILL_BOUND
#undef MSG_INITIALIZED
#undef TICKS_PER_SECOND
}
#pragma cplusplus reset
#pragma pop
extern char lbl_80338928[];
/* Return the effect-name table ("PhysPath_ASE", "camera_shake", "track_effect", ...). */
void *fn_801D8148(void) {
    return lbl_80338928;
}

int fn_801D8154(void *effect) {
    /* Return the state machine value at +0x40 of a track/camera effect (0 unused, 1 ready, 2 running, 3 finished). */
    return *(int *)((char *)effect + 0x40);
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" int fn_801D815C(void *arg0, int arg1) {
    extern int fn_80179630(int);
    extern int fn_8017960C(int);
    extern int fn_80179650(void);
    extern int fn_80139B5C(int, int);
    extern void *fn_801B2EC0(int);
    extern void *fn_801B83A0(void);
    extern char lbl_80339018[];
    extern char lbl_8055AD34;
    extern char lbl_8055AD40;
    extern void fn_802E30C8();
    struct Name { virtual void *v0(); virtual void *v1(); virtual void *get(); };
    struct Callback {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual void v24();
        virtual void v25();
        virtual void v26();
        virtual void v27();
        virtual void v28();
        virtual void v29();
        virtual void v30();
        virtual void v31();
        virtual void v32();
        virtual void v33();
        virtual void v34();
        virtual void v35();
        virtual void v36();
        virtual void v37();
        virtual void v38();
        virtual void v39();
        virtual void run(int, int);
    };
    register void *self = arg0;
    register int property;
    register int key;
    register int index;
    register int result;
    Name *name;
    Callback *callback;

    if (*(int *)((char *)self + 0x40) == 1) {
        *(int *)((char *)self + 0x34) = lbl_8055E3C4;
        *(int *)((char *)self + 0x38) = arg1;
        *(int *)((char *)self + 0x40) = 2;
        if (*(int *)((char *)self + 0x3C) != 0) {
            index = 0;
            while (index < fn_80179650()) {
                key = fn_80179630(index);
                result = fn_80139B5C(fn_8017960C(key), *(int *)((char *)self + 0x3C));
                if (result != 0) {
                    name = (Name *)fn_801B2EC0(key);
                    property = *(int *)((char *)name->get() + 4);
                    callback = (Callback *)fn_801B83A0();
                    callback->run(key, property);
                }
                ((void (*)(const char *, ...))fn_802E30C8)(
                    lbl_80339018, key,
                    result != 0 ? &lbl_8055AD34 : &lbl_8055AD40);
                index++;
            }
        }
        return 1;
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop

void *fn_801DA8C8(const char *, const char *);
/* RealName: ResolveLinkedObject_801D825C */
void fn_801D825C(void *object) {
    /* If a linked name is set, resolve it into the object pointer at offset 0x2C. */
    if (*(int *)((char *)object + 0x40) != 0) {
        *(void **)((char *)object + 0x2C) = fn_801DA8C8((char *)object + 4, (char *)object + 0x18);
    }
}

#pragma cplusplus on
extern "C" void fn_801D82A0(void *arg0) {
    /* If this object is in running state and its scheduled time has elapsed, invoke the target callback with +1.0 or -1.0 based on a direction flag, then advance to finished state. */
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(float);
    };
    extern int lbl_8055E3C4;
    extern float lbl_80562AE0;
    extern float lbl_80562AEC;
    register void *self = arg0;
    int state = *(int *)((char *)self + 0x40);
    int baseTime = *(int *)((char *)self + 0x34);
    int delay = *(int *)((char *)self + 0x30);
    int timeRemaining = lbl_8055E3C4 - (baseTime + delay);
    Dummy *target;
    float value;
    if (state == 2 && timeRemaining >= 0) {
        target = *(Dummy **)((char *)self + 0x2C);
        if (target != 0) {
            if (*(int *)((char *)self + 0x38) == 0) {
                value = lbl_80562AE0;
            } else {
                value = lbl_80562AEC;
            }
            target->v3(value);
        }
        *(int *)((char *)self + 0x40) = 3;
    }
}
#pragma cplusplus reset

void fn_801D832C(void *self) {
    /* If this object's state (+0x40) is nonzero, reset it to state 1. */
    if (*(int *)((char *)self + 0x40) != 0) {
        *(int *)((char *)self + 0x40) = 1;
    }
}

#pragma cplusplus on
/* Resets to state 1 and, if a target object at +0x2C is present, invokes its virtual method v5. */
extern "C" void fn_801D8344(void *self) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    if (*(int *)((char *)self + 0x40) != 0) {
        Dummy *target = *(Dummy **)((char *)self + 0x2C);
        if (target != 0) {
            target->v5();
        }
        *(int *)((char *)self + 0x40) = 1;
    }
}
#pragma cplusplus reset

int fn_801D839C(void *arg0) {
    /* Returns nonzero while this object's flag byte at +0x18 is clear (zero). */
    typedef struct {
        unsigned char _pad[0x18];
        unsigned char flag;
    } FlagObj;
    return ((FlagObj *)arg0)->flag == 0;
}

#pragma cplusplus on
extern "C" void fn_801D83AC(void *effect) {
    /* Virtual dispatch on an action-sequence TimedEffect cue: jump to the
       vtable entry at offset 0x34 (vtable slot 13) on effect. */
    struct TimedEffectVtbl {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((TimedEffectVtbl *)effect)->v11();
}
#pragma cplusplus reset

int fn_801D83BC(void *arg0) {
    /* Returns nonzero while this object's flag byte at +0x30 is clear (zero). */
    typedef struct {
        unsigned char _pad[0x30];
        unsigned char flag;
    } FlagObj;
    return ((FlagObj *)arg0)->flag == 0;
}

#pragma cplusplus on
extern "C" void fn_801D83CC(void *obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
    };
    /* Virtual-dispatch thunk: invoke the 12th virtual method (vtable +0x34). */
    ((Dummy *)obj)->f11();
}
#pragma cplusplus reset

/* Destructor-like reset: clear the stored object pointer at +4 and, if requested, free this object. */
int fn_801D83DC(int object, int shouldFree) {
    if (object != 0) {
        ((int *)object)[1] = 0;
        if (shouldFree > 0) fn_80128668();
    }
    return object;
}

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma cplusplus on
extern "C" int fn_801D8424(void *arg0, void *arg1) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void set(char *, int);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float get(char *, float);
    };
    extern char lbl_8055ACB0;
    extern char lbl_8055ACB8;
    extern char lbl_8055AD48;
    extern int fn_8029F3BC(void);
    Dummy *obj = (Dummy *)arg1;
    float first = obj->get(&lbl_8055ACB0, 0.0f);
    float second = obj->get(&lbl_8055ACB8, 0.0f);
    float scaledFirst = 59.94f * first;
    float scaledSecond = 59.94f * second;
    int resultFirst = (int)scaledFirst;
    int resultSecond = (int)scaledSecond;
    *(int *)((char *)arg0 + 8) = resultFirst;
    *(int *)((char *)arg0 + 0xC) = resultSecond;
    obj->set(&lbl_8055AD48, resultFirst);
    int status = fn_8029F3BC();
    *(int *)((char *)arg0 + 0x14) = status;
    if (status < 0) return 0;
    *(int *)((char *)arg0 + 4) = 1;
    return 1;
}
#pragma pop

/* Name accessor: returns the "EmbeddedTrackEffect_ASE" identifier string for this effect system. */
void *fn_801D8504(void) {
    return lbl_80339038;
}

/* state() of an EmbeddedTrackEffect_ASE action-sequence element (vtable slot +0x18):
 * report the element's state field (+0x04), which its start/update methods step through. */
int fn_801D8510(void *element) {
    return ((AseElementHeader *)element)->state;
}

int fn_801D8518(int effect) {
    /* If a timed effect is ready, record the current global tick as its start and mark it running. */
    if (((int *)effect)[1] == TIMED_EFFECT_READY) {
        ((int *)effect)[4] = lbl_8055E3C4;
        ((int *)effect)[1] = TIMED_EFFECT_RUNNING;
        return 1;
    }
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801796CC(int, void *, int);
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D8544(void *stream) {
    int data;
    int remaining;

    remaining = lbl_8055E3C4 - (*(int *)((char *)stream + 0x10) + *(int *)((char *)stream + 0xC));
    if (*(int *)((char *)stream + 4) == 2 && remaining > 0) {
        data = *(int *)((char *)stream + 0x14);
        fn_801796CC(0xB, &data, 4);
        if (remaining >= *(int *)((char *)stream + 8)) {
            *(int *)((char *)stream + 4) = 3;
        }
    }
}
#pragma pop
#pragma cplusplus reset
extern "C" void fn_801D85C8(void *effect) {
    /* Virtual dispatch on an action-sequence TimedEffect cue: jump to the
       vtable entry at offset 0x34 (vtable slot 13) on effect. */
    struct TimedEffectVtbl {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((TimedEffectVtbl *)effect)->v11();
}
#pragma cplusplus reset

void fn_801D85D8(int object) {
    /* Normalizes the object's +0x4 state/active flag: any non-zero value becomes 1. */
    if (((int *)object)[1] != 0) {
        ((int *)object)[1] = 1;
    }
}

int fn_801D85F0(void *arg0) {
    /* Returns nonzero while this object's flag byte at +0x14 is clear (zero). */
    typedef struct {
        unsigned char _pad[0x14];
        unsigned char flag;
    } FlagObj;
    return ((FlagObj *)arg0)->flag == 0;
}

/* If the object's state is set (nonzero), clamp it to 1; leave state 0 alone. */
void fn_801D8600(UnkStruct_801D701C *object) {
    if (object->state != 0) {
        object->state = 1;
    }
}

int fn_801D8618(void) {
    /* No-op query stub: always reports 0 (false / no result). */
    return 0;
}

void fn_801D8620(void) {

}

#pragma cplusplus on
extern "C" void fn_801D8624(void *obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
    };
    /* Virtual-dispatch thunk: invoke the 12th virtual method (vtable +0x34). */
    ((Dummy *)obj)->f11();
}

#pragma push
#pragma scheduling invalid_target
extern "C" int fn_801D8634(void *out, void *obj) {
    extern float lbl_80562ADC;
    extern char lbl_8055ACB8;
    extern char lbl_8055ACB0;
    extern char lbl_803385D0[];
    extern char lbl_80339050[];
    extern int fn_801D04D0(void);
    extern void fn_801D0590(void *);
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(void *);
        virtual void v4();
        virtual int v5(void *);
        virtual void v6();
        virtual float v7(void *);
        virtual float v8(void *, float);
    };
    Dummy *thing = (Dummy *)obj;
    int result;
    *(float *)((char *)out + 0xC) = thing->v8(&lbl_8055ACB8, 0.0f);
    *(float *)((char *)out + 0x14) = thing->v7(&lbl_8055ACB0);
    *(int *)((char *)out + 8) = thing->v5(lbl_803385D0);
    thing->v3(lbl_80339050);
    *(int *)((char *)out + 0x1C) = fn_801D04D0();
    result = (int)out;
    if (out != 0) {
        fn_801D0590((char *)out + 4);
        {
            float finalRate = lbl_80562ADC;
            *(int *)((char *)out + 0x18) = 1;
            result = 1;
            *(float *)((char *)out + 0x10) = finalRate;
        }
    }
    return result;
}
#pragma pop

#pragma cplusplus reset

extern void fn_801D05B4(int);
/* Unregister a created listener object from the dispatch list: the list stores
 * object+4 (past the vtable), so advance a non-null object by 4 before asking
 * fn_801D05B4 to find and remove it; a null object is passed through unchanged. */
void fn_801D8710(int object) {
    if (object != 0) {
        object += 4;
    }
    fn_801D05B4(object);
}

void *fn_801D8720(void) {
    /* Return the "SurfaceChange_ASE" name string. */
    #define sSurfaceChangeAseName lbl_8033905C
    return sSurfaceChangeAseName;
    #undef sSurfaceChangeAseName
}

/* One "SurfaceChange_ASE" action: fn_801D8634 builds it from the *_ASE element's
 * parameters, fn_801D875C steps it every frame -- after "delay" seconds it hands
 * its surface type to every target of the +0x24 list, holds it for "holdTime"
 * seconds and then gives each target its old override (-1) back -- and
 * fn_801D88BC resets it. */
struct SurfaceChangeAse {
    void *vtable;      /* 0x00 */
    int pad04;         /* 0x04 */
    int groupId;       /* 0x08 the element's "group_id" */
    float delay;       /* 0x0C seconds from start until the change is applied */
    float startTime;   /* 0x10 game time (lbl_8055E3C8) when it was started */
    float holdTime;    /* 0x14 seconds the change stays on */
    int state;         /* 0x18 1 = idle, 2 = running */
    int surfaceType;   /* 0x1C fn_801D04D0() of the element's "surftype" */
    int applied;       /* 0x20 0 before the change is applied, 1 after */
    void *targets;     /* 0x24 12-byte {target, type, type} records */
    int targetCount;   /* 0x28 */
};

/* State getter of a SurfaceChange_ASE action: 1 = idle, 2 = running
 * (fn_801D873C starts it, fn_801D88BC resets it, fn_801D875C steps it while 2). */
int fn_801D872C(struct SurfaceChangeAse *action) {
    return action->state;
}

/* SurfaceChange_ASE virtual hook at vtable +0x1C (the slot between state() and
 * apply()).  The shared ActionSequenceEvent default for this slot, fn_801D544C,
 * returns 0, and this effect keeps that default: it reports no extra result. */
int fn_801D8734(void) {
    return 0;
}

int fn_801D873C(int object) {
    /* Reset the object's mode (+0x18) to 2 and its counter (+0x20) to 0, then stamp +0x10
       with the current game time (lbl_8055E3C8); returns 0. */
    ((int *)object)[6] = 2;
    ((int *)object)[8] = 0;
    *(float *)((char *)object + 0x10) = lbl_8055E3C8;
    return 0;
}

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801D875C(void *arg0) {
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void first(int); virtual void v6(); virtual void second_pad();
        virtual void second(int);
    };
    struct Entry {
        Dummy *item;
        int arg4;
        int arg8;
        void start(int p) { item->first(p); item->second(arg8); }
        void stop() { item->first(arg4); item->second(-1); }
    };
    struct Self {
        char pad[0xC];
        float delay;
        float start;
        float duration;
        int state;
        int param;
        int started;
        Entry *entries;
        int count;
    };
    Self *self = (Self *)arg0;
    int i;
    float time;
    if (self->state != 2) return;
    time = lbl_8055E3C8;
    if (self->started == 0) {
        if (time - self->start > self->delay) {
            for (i = 0; i < self->count; i++) {
                self->entries[i].start(self->param);
            }
            self->started = 1;
        }
    } else {
        if (time - self->start - self->delay > self->duration) {
            for (i = 0; i < self->count; i++) {
                self->entries[i].stop();
            }
            self->state = 1;
        }
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801D88AC(void *obj) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    /* Virtual-dispatch thunk: invoke the 12th virtual method (vtable +0x34). */
    ((Dummy *)obj)->v11();
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
/* Resets a SurfaceChange_ASE action (state +0x18 = 1) and clears the override (-1) on each registered target in +0x24. */
extern "C" void fn_801D88BC(void *surfaceChange) {
    struct SurfaceTarget {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void setOverride(int value);
    };
    int i;
    *(int *)((char *)surfaceChange + 0x18) = 1;
    for (i = 0; i < *(int *)((char *)surfaceChange + 0x28); i++) {
        SurfaceTarget *target = *(SurfaceTarget **)((char *)*(void **)((char *)surfaceChange + 0x24) + i * 0xC);
        target->setOverride(-1);
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset

void fn_801D8938(void) {

}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D893C(void *list, unsigned int id) {
    int count;
    int byteOffset;
    unsigned char *entry;
    unsigned char *base;
    int index;

    /* Remove the 12-byte entry whose first word matches id from the list at +0x24/+0x28 by swapping in the last entry. */
    index = 0;
    byteOffset = 0;
    goto test;
loop:
    base = *(unsigned char **)((unsigned char *)list + 0x24);
    entry = base + byteOffset;
    if (*(unsigned int *)entry == id) {
        if (index >= 0) {
            count = *(volatile int *)((unsigned char *)list + 0x28);
            if (index < count) {
                int lastIndex = count - 1;
                if (index != lastIndex) {
                    *(unsigned int *)entry = *(unsigned int *)(base + lastIndex * 0xC);
                    *(unsigned int *)(entry + 4) = *(unsigned int *)(base + lastIndex * 0xC + 4);
                    *(unsigned int *)(entry + 8) = *(unsigned int *)(base + lastIndex * 0xC + 8);
                }
                *(int *)((unsigned char *)list + 0x28) = *(int *)((unsigned char *)list + 0x28) - 1;
            }
        }
    }
    byteOffset += 0xC;
    index++;
test:
    if (index < *(int *)((unsigned char *)list + 0x28)) {
        goto loop;
    }
}
#pragma pop
#pragma cplusplus reset

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D89C0(void *arg0, void *arg1) {
    extern char lbl_803385D0[];
    struct NameObject {
        virtual void *v0();
        virtual void *v1();
        virtual void *v2();
        virtual void *v3();
        virtual void *v4();
        virtual void *v5();
        virtual int find(char *, int);
    };
    struct Request {
        virtual void *getObject();
        virtual void *v1();
        virtual void *v2();
        virtual void *v3();
        virtual void *v4();
        virtual void *v5();
        virtual int getFirst();
        virtual int getSecond();
        virtual void finish(int, int, int, int);
    };
    struct Record { void *object; int first; int second; };
    struct Tmp { int pad; volatile int first; int second; };
    Request *request = (Request *)arg1;
    int *output = (int *)arg0;
    NameObject *object = (NameObject *)request->getObject();
    if (object == 0) return;
    int found = object->find(lbl_803385D0, -1);
    int expected = output[2];
    if (found != expected) return;
    Tmp tmp;
    tmp.first = request->getFirst();
    tmp.second = request->getSecond();
    int count = output[0x28 / 4];
    Record *records = (Record *)output[0x24 / 4];
    output[0x28 / 4] = count + 1;
    records[count].object = request;
    records[count].first = tmp.first;
    records[count].second = tmp.second;
    request->finish(-1, (int)&records[count], count + 1, (int)records);
}
#pragma cplusplus reset
#pragma pop
int fn_801D8AA4(void *ringMaster) {
    /* Return 1 if this RingMaster_ASE's "length" field (+0x30) is negative;
       lbl_80562ADC is the shared 0.0f constant. */
    extern float lbl_80562ADC;
    return *(float *)((char *)ringMaster + 0x30) < lbl_80562ADC;
}

#pragma cplusplus on
extern "C" void fn_801D8ABC(void *obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
    };
    /* Virtual-dispatch thunk: invoke the 12th virtual method (vtable +0x34). */
    ((Dummy *)obj)->f11();
}

#pragma push
#pragma cplusplus on
extern "C" s32 fn_801D8ACC(void *arg0, void *arg1) {
    extern float lbl_80562ADC;
    extern float lbl_80562B14;
    extern char lbl_8055ACB8;
    extern char lbl_8055ACB0;
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float get(char *, float);
    };
    #pragma opt_propagation off
    float value = lbl_80562ADC;
    Dummy *obj = (Dummy *)arg1;
    *(int *)((char *)arg0 + 4) = 1;
    *(float *)((char *)arg0 + 0x10) = value;
    *(float *)((char *)arg0 + 8) = obj->get(&lbl_8055ACB8, value);
    *(float *)((char *)arg0 + 0xC) = obj->get(&lbl_8055ACB0, lbl_80562B14);
    return 1;
    #pragma opt_propagation reset
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset

void fn_801D8B50(void) {
}

void fn_801D8B54(void) {
}

void fn_801D8B58(void) {
}

void fn_801D8B5C(void) {

}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_801D8B60(void *effectPtr, void *valueReader) {
    extern char lbl_80339070[];
    extern char lbl_8055ACB8;
    extern char lbl_8055ACB0;
    struct ValueReader {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float readFloat(char *, float);
    };
    ValueReader *reader = (ValueReader *)valueReader;
    TimedEffect *effect = (TimedEffect *)effectPtr;
    float zero;

    /* Initialize a timed cue from the named-value reader (vtable+0x28 reads a
       float by name with a default): "interval" (default 999), "delay" (default
       0) and "length" (default 5) fill the effect's fields, state 1 marks it
       READY, and its start time is zeroed. */
    effect->interval = reader->readFloat(lbl_80339070, 999.0f);
    effect->state = 1;
    zero = 0.0f;
    effect->startTime = zero;
    effect->delay = reader->readFloat(&lbl_8055ACB8, zero);
    effect->length = reader->readFloat(&lbl_8055ACB0, 5.0f);
    return 1;
}
#pragma cplusplus reset
#pragma pop

/* Invalidate the cached index at +0x18 (set it to -1) so the next check in
   fn_801D8C1C sees a change and forces a refresh via gForceWeather. */
void fn_801D8C0C(void *state) {
    *(int *)((char *)state + 0x18) = -1;
}

void fn_801D8C18(void) {
}

extern float lbl_80562AE4;
extern void fn_801E1F78(void);
#pragma scheduling invalid_target
void fn_801D8C1C(void *arg0, float farg0) {
    float tmp = farg0 / *(float *)((char *)arg0 + 0x14);
    float v;
    int t;
    if (tmp < 0.0f) {
        v = tmp - lbl_80562AE4;
    } else {
        v = lbl_80562AE4 + tmp;
    }
    t = (int)v;
    if (t != *(int *)((char *)arg0 + 0x18)) {
        fn_801E1F78();
        *(int *)((char *)arg0 + 0x18) = t;
    }
}
#pragma scheduling on
void fn_801D8C94(void) {
}

/* Name accessor: returns the "LightningASE" identifier string for this effect system. */
void *fn_801D8C98(void) {
    return lbl_8033907C;
}

/* Return the current state field (+0x4) of the effect object. */
int fn_801D8CA4(void *object) {
    return ((UnkStruct_801D701C *)object)->state;
}

#pragma cplusplus on
extern "C" s32 fn_801D8CAC(void *obj) {
    /* Start one timed cue of an action sequence (a TimedEffect element).

       A cue that is ready is put into its running state, stamps the moment it
       started from the frame clock lbl_8055E3C8 -- fn_801D8D00 subtracts that
       from the clock every frame to pick the step to run -- and runs its start
       step, the virtual at vtable+0x38, just before the waiting, running and
       finished steps.  Answering whether the cue started makes a trigger that
       fires the same cue twice start it only once.
       Proposed name: TimedEffect_start */
    TimedEffect *effect = (TimedEffect *)obj;
    if (effect->state == TIMED_EFFECT_READY) {
        effect->state = TIMED_EFFECT_RUNNING;
        effect->startTime = lbl_8055E3C8;
        effect->onStart();
        return 1;
    }
    return 0;
}

#pragma use_lmw_stmw off
#pragma cplusplus on
/* Frame update of a running timed cue: work out how long it has been going and
 * hand the frame to whichever step that time falls in -- still waiting out its
 * delay, part way through its length (passed the seconds past the delay), or
 * past its end, which runs the last step and marks the cue finished. */
extern "C" void fn_801D8D00(void *arg0) {
    TimedEffect *effect = (TimedEffect *)arg0;
    float delay;
    float elapsed;
    if (effect->state == 2) {
        delay = effect->delay;
        elapsed = lbl_8055E3C8 - effect->startTime;
        if (elapsed < delay) {
            effect->onWaiting();
            return;
        }
        if (elapsed < delay + effect->length) {
            effect->onRunning(elapsed - delay);
            return;
        }
        effect->onFinished();
        effect->state = 3;
    }
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801D8DA0(void *effect) {
    /* Virtual dispatch on an action-sequence TimedEffect cue: jump to the
       vtable entry at offset 0x34 (vtable slot 13) on effect. */
    struct TimedEffectVtbl {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((TimedEffectVtbl *)effect)->v11();
}
#pragma cplusplus reset

/* Normalizes the object's +0x4 state/active flag: any non-zero value becomes 1. */
void fn_801D8DB0(int object) {
    if (((int *)object)[1] != 0) {
        ((int *)object)[1] = 1;
    }
}

/* Destroy/teardown helper: clear the object's state field at +4 and optionally delete it when deleteFlag > 0. */
int fn_801D8DC8(int object, int deleteFlag) {
    if (object != 0) {
        ((int *)object)[1] = 0;
        if (deleteFlag > 0) fn_80128668();
    }
    return object;
}

#pragma cplusplus on
extern "C" int fn_801D8E10(void *arg0, void *arg1);
extern "C" int fn_801D8E10(void *arg0, void *arg1) {
    extern char lbl_8055ACF0;
    extern char lbl_8055AD50;
    extern char lbl_8055ACB8;
    extern float lbl_80562ADC;
    extern char lbl_8033908C;
    extern void fn_802E30C8();
    struct Lookup {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual char *get(char *, char *);
    };
    struct Measure {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual float get(char *, float);
    };
    char *src;
    char *dst;
    int count;
    Lookup *lookup;
    Measure *measure;

    lookup = (Lookup *)arg1;
    src = lookup->get(&lbl_8055AD50, &lbl_8055ACF0);
    dst = (char *)arg0 + 8;
    count = 0x14;
    goto copy;
copy:
    count--;
    if (count <= 0) {
        dst[-1] = 0;
        goto copied;
    }
    *dst++ = *src++;
    if ((signed char)dst[-1] != 0) {
        goto copy;
    }
copied:
    if ((signed char)*((char *)arg0 + 8) == 0) {
        ((void (*)(char *))fn_802E30C8)(&lbl_8033908C);
        return 0;
    }
    measure = (Measure *)arg1;
    *(float *)((char *)arg0 + 0x1C) = measure->get(&lbl_8055ACB8, lbl_80562ADC);
    *(float *)((char *)arg0 + 0x20) = lbl_80562ADC;
    *(int *)((char *)arg0 + 4) = 1;
    return 1;
}
#pragma cplusplus reset

/* Returns the "Trigger_ASE" name string that identifies trigger action-sequence events. */
char *fn_801D8EF0(void) {
    return lbl_803389B8;
}

/* Return the current state field (+0x4) of the effect object. */
int fn_801D8EFC(void *object) {
    return ((UnkStruct_801D701C *)object)->state;
}

/* Starts a ready timed cue: switches its state from READY to RUNNING and stamps
 * the current game time (lbl_8055E3C8) as its start time. Returns 1 if it started. */
int fn_801D8F04(void *cue) {
    if (*(int *)((char *)cue + 4) == TIMED_EFFECT_READY) {
        *(int *)((char *)cue + 4) = TIMED_EFFECT_RUNNING;
        *(float *)((char *)cue + 0x20) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

extern char lbl_803390C0[];
extern void fn_802E30C8();
extern void fn_801D488C(int, int, int, float *);
/* TriggerActionSequenceEvent update: when a pending event (state 2) passes its
   wait timer (now - +0x20 >= +0x1C), start the named action sequence with state 1
   (or log an error if that name is unknown), then advance the event to state 3. */
void fn_801D8F30(void *event) {
    struct Obj { char pad[8]; char name; };
    float position[3];
    int sequence;
    if (*(int *)((char *)event + 4) == 2 && lbl_8055E3C8 - *(float *)((char *)event + 0x20) >= *(float *)((char *)event + 0x1C)) {
        sequence = ((int (*)(void *))fn_801D4888)((char *)event + 8);
        if (sequence == 0) {
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_803390C0, &((struct Obj *)event)->name);
        } else {
            position[0] = lbl_80562ADC;
            position[1] = lbl_80562ADC;
            position[2] = lbl_80562ADC;
            ((void (*)(int, int, int, float *))fn_801D488C)(sequence, 1, 0, position);
        }
        *(int *)((char *)event + 4) = 3;
    }
}

#pragma cplusplus on
extern "C" void fn_801D8FD0(void *obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
    };
    /* Virtual-dispatch thunk: invoke the 12th virtual method (vtable +0x34). */
    ((Dummy *)obj)->f11();
}
#pragma cplusplus reset

/* Normalizes the object's +0x4 state/active flag: any non-zero value becomes 1. */
void fn_801D8FE0(int object) {
    if (((int *)object)[1] != 0) {
        ((int *)object)[1] = 1;
    }
}

extern char lbl_803385D0[];

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
