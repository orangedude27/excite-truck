

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
#pragma cplusplus on
struct TimedEffect {
    virtual void v0();   virtual void v1();   virtual void v2();
    virtual void v3();   virtual void v4();   virtual void v5();
    virtual void v6();   virtual void v7();   virtual void v8();
    virtual void v9();   virtual void v10();  virtual void v11();
    virtual void v12();
    virtual void onWaiting();     /* 0x3C: the delay has not run out yet */
    virtual void onRunning(float);/* 0x40: seconds since the delay ran out */
    virtual void onFinished();    /* 0x44: the length ran out */
    int   state;                  /* 0x04: 1 ready, 2 running, 3 finished */
    float delay;                  /* 0x08, the value file's "delay" */
    float length;                 /* 0x0C, the value file's "length" */
    float startTime;              /* 0x10: lbl_8055E3C8 when it was started */
    float interval;               /* 0x14, the value file's "interval" */
    int   index;                  /* 0x18: last (elapsed / interval) step */
};
#pragma cplusplus reset

  extern void fn_801D50B8(int);

extern int fn_8017960C(int);
extern void *fn_801B2EC0(int);
extern int fn_801B2F24(void);
  extern char lbl_80338C78[];
extern char lbl_80338BD0[];
extern int fn_80128668(void);
extern void fn_80128658(int);
typedef struct { char *name; int state; } UnkStruct_801D701C;
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
    obj = fn_802077A4(&base[0], 5, lbl_804422F0 + 8, lbl_804422F0 + 0x14);
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
#pragma cplusplus reset
#pragma pop

void fn_801D47F4(void) {
    fn_801D57F0();
}

void fn_801D5488(void);
void fn_801D47F8(void* alarm) {
    fn_801D5650(alarm);
    fn_801D5488();
}

int fn_801D481C(void) {
    char* object = lbl_804422F0;
    float value = lbl_80562ADC;
    *(float*)(object + 0x14) = value;
    *(float*)(object + 0x18) = value;
    *(float*)(object + 0x1C) = value;
    *(float*)(object + 0x4) = value;
    return fn_801D56C0(object);
}

#pragma cplusplus on
extern "C" signed char lbl_8055E954;
extern "C" char lbl_804422F0[];
extern "C" void fn_801D5730(void);
extern "C" void fn_801D483C(void) {
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
void fn_801D488C(int arg0, int arg1, int arg2, float *arg3) {
    fn_801D597C((void *)arg0, arg1);
    if (arg2 != 0 && fn_801D5A68((void *)arg0) != 0) {
        fn_801D5454((void *)arg0, (void *)arg3);
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
void fn_801D490C(void) {
    float alpha, right, width, x, t, edge, dy, y;
    int color, n;
    char text[0x40], *src, *dst, *part, *caret;
    x = *(float *)lbl_80442310;
    width = *(float *)(lbl_80442310 + 4);
    right = x + width;
    if (lbl_8055E3C8 < right) {
        alpha = lbl_80562AE0;
        if (width > lbl_80562AE4) {
            t = lbl_8055E3C8 - x;
            if (t < lbl_80562AE8) {
                t = t / ((lbl_80562AE8 + x) - x);
                alpha = alpha < t ? t : alpha;
                alpha = alpha > lbl_80562ADC ? lbl_80562ADC : alpha;
                alpha = lbl_80562ADC + alpha * lbl_80562AE0;
            } else {
                edge = right - lbl_80562AE8;
                if (lbl_8055E3C8 > edge) {
                    t = (lbl_8055E3C8 - edge) / (right - edge);
                    alpha = alpha >= t ? alpha : t;
                    alpha = alpha <= lbl_80562ADC ? alpha : lbl_80562ADC;
                    alpha = lbl_80562AE0 + alpha * lbl_80562AEC;
                }
            }
        }
        color = (((unsigned int)(int)(lbl_80562AF0 * alpha) << 24) | 0x00ffffff) & 0xffffff00;
        fn_8000FF88(color, 0xC, lbl_8055AD5C, lbl_80562AF4, lbl_80562ADC, lbl_80562AF8, lbl_80442310 + 0x48);
        src = lbl_80442310 + 8; dst = text; n = 0x40;
        goto copy;
    limit:
        if (--n > 0) goto copy;
        dst[-1] = 0;
        goto done;
    copy:
        { char c = *src++; *dst++ = c; if ((signed char)c) goto limit; }
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
int fn_801D4CB8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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
        virtual float value(char *, float);
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
    out->f1c = obj->value(base + 0xD4, lbl_80562B00);
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

int fn_801D50A0(void) {
    return 0;
}

#pragma dont_inline on
void fn_801D50A8(int arg0) {
    fn_801D5328(arg0, 1);
}

void fn_801D50B0(int arg0) {
    fn_801D5328(arg0, 0);
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
#pragma cplusplus on
void fn_801D5328(int arg0, int arg1) {
 struct Dummy { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual int state(); virtual void v6(); virtual int apply(int); };
 int state, mode, changed, count, offset;
 Dummy *item;
 state = *(int *)(arg0+4);
 if (state != 1) return;
 *(unsigned char *)(arg0+0x2c)=arg1;
 mode=((unsigned char)arg1==0); changed=0; count=0; offset=0;
 goto test1;
loop1:
 item=*(Dummy **)(*(int *)(arg0+0x30)+offset);
 if(item->state()==0 && item->apply(mode)!=0) changed=1;
 offset+=4; count++;
test1:
 if(count<*(int *)(arg0+0x34)) goto loop1;
 if(changed==0) goto done;
 count=0; offset=0;
 goto test2;
loop2:
 item=*(Dummy **)(*(int *)(arg0+0x30)+offset);
 if(item->state()!=0) item->apply(mode);
 offset+=4; count++;
test2:
 if(count<*(int *)(arg0+0x34)) goto loop2;
done:
 *(int *)(arg0+4)=2;
}
#pragma cplusplus reset
#pragma pop

int fn_801D544C(void) {
    return 0;
}

extern float lbl_80562B04;
void fn_801D5454(void *self, void *arg0) {
    float old;
    float y;
    float x;
    float z;
    x = *(float *)arg0;
    old = *(float *)(lbl_804422F0 + 4);
    y = *(float *)((unsigned char *)arg0 + 4);
    z = *(float *)((unsigned char *)arg0 + 8);
    *(float *)(lbl_804422F0 + 0x14) = x;
    *(float *)(lbl_804422F0 + 0x18) = y;
    *(float *)(lbl_804422F0 + 0x1C) = z;
    *(float *)(lbl_804422F0 + 4) = old + lbl_80562B04;
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
int fn_801D56C0(void *alarm) {
    int offset;
    int i;
    offset = 0;
    i = 0;
    while (i < lbl_804423A4[1]) {
        fn_801D52A4(*(int *)((char *)lbl_804423A4[0] + offset));
        offset += 4;
        i += 1;
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_801D4F2C(void *arg0) {
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v4();
    };
    int offset = 0;
    int i = 0;
    while (i < *(int *)((char *)arg0 + 0x34)) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)arg0 + 0x30) + offset);
        entry->v4();
        offset += 4;
        i += 1;
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
void *fn_801D5860(const char *arg0) {
    void **entries;
    int count;
    int i;
    char *entry;
    entries = (void **)lbl_804423A4[0];
    count = lbl_804423A4[1];
    i = 0;
    while (i < count) {
        entry = (char *)*entries;
        if (strcmp(entry + 8, arg0) == 0) {
            return entry;
        }
        entries++;
        i++;
    }
    return 0;
}
#pragma pop
extern float lbl_80562B00;
float fn_801D58DC(void *arg0) {
    void **entries;
    int count;
    if (arg0 == 0) {
        return lbl_80562B00;
    }
    entries = (void **)lbl_804423A4[0];
    count = lbl_804423A4[1];
    while (count > 0) {
        if (entries[0] == arg0) {
            return *(float *)((char *)arg0 + 0x1C);
        }
        entries++;
        count--;
    }
    return lbl_80562B00;
}

unsigned char fn_801D592C(void *arg0) {
    void **entries;
    int count;
    if (arg0 == 0) {
        return 0;
    }
    entries = (void **)lbl_804423A4[0];
    count = lbl_804423A4[1];
    while (count > 0) {
        if (entries[0] == arg0) {
            return *(unsigned char *)((char *)arg0 + 0x21);
        }
        entries++;
        count--;
    }
    return 0;
}

void fn_801D597C(void *arg0, int arg1) {
    void **entries;
    int count;
    int i;
    if (arg0 == 0) {
        return;
    }
    entries = (void **)lbl_804423A4[0];
    count = lbl_804423A4[1];
    for (i = 0; i < count; i++) {
        if (entries[i] == arg0) {
            if (arg1 != 0) {
                fn_801D50A8((int)arg0);
            } else {
                fn_801D50B0((int)arg0);
            }
            return;
        }
    }
}

#pragma dont_inline on
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
void fn_801D5A14(int arg0) {
    (void)fn_801D59C8(arg0, 2);
}

void fn_801D5A1C(int arg0) {
    (void)fn_801D59C8(arg0, 1);
}

int fn_801D5A24(int arg0) {
    return fn_801D59C8(arg0, 4);
}

#pragma scheduling invalid_target
#pragma dont_inline on
int fn_801D5A2C(void *arg0, int arg1, int arg2) {
    void **entries = (void **)lbl_804423A4[0];
    int count = lbl_804423A4[1];
    int i;
    for (i = 0; i < count; i++) {
        if (entries[i] == arg0) {
            return ((int (*)(void *, int, int))fn_801D5014)(arg0, arg1, arg2);
        }
    }
    return 0;
}

int fn_801D5A68(void *arg0) {
    void **entries = (void **)lbl_804423A4[0];
    int count = lbl_804423A4[1];
    int i;
    for (i = 0; i < count; i++) {
        if (entries[i] == arg0) {
            return *((u8 *)arg0 + 0x22);
        }
    }
    return 0;
}

extern char lbl_80338D20[];
void fn_801D5AA8(void *arg0) {
    char *base;
    char *vtable;
    char *p1c;
    char *p7c;
    int zero;
    int four;
    int size;
    base = arg0;
    vtable = lbl_80338D20;
    *(void **)base = vtable;
    zero = 0;
    p1c = base + 0x1C;
    *(void **)(base + 4) = vtable + 0x38;
    p7c = base + 0x7C;
    four = 4;
    *(int *)(base + 8) = zero;
    size = 0x40;
    *(void **)(base + 0x10) = p1c;
    *(int *)(base + 0x18) = four;
    *(int *)(base + 0x14) = zero;
    *(void **)(base + 0x70) = p7c;
    *(int *)(base + 0x78) = size;
    *(int *)(base + 0x74) = zero;
}

extern void fn_801D0824(void *);
void *fn_801D5AF0(void *arg0, int arg1) {
    int field8;
    int has_field;

    if (arg0 != 0) {
        field8 = *(int *)((char *)arg0 + 8);
        *(void **)arg0 = lbl_80338D20;
        has_field = field8 != 0;
        *(void **)((char *)arg0 + 4) = lbl_80338D20 + 0x38;

        if (has_field) {
            *(int *)((char *)arg0 + 8) = 0;
            if (arg0 != 0) {
                fn_801D0824((char *)arg0 + 4);
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

void fn_801D628C(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(char **)((char *)arg0 + 0) = lbl_80338C78;
    *(int *)((char *)arg0 + 0x14) = 0;
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
    if (((int (*)(void *, const char *))(*(void **)(*(void ***)object + 0xC)))(object, &lbl_8055ACB0) == 0) { fn_802E30C8(messages + 0x210, 0); return 0; }
    a = ((float (*)(void *, const char *))(*(void **)(*(void ***)object + 0x24)))(object, &lbl_8055ACB0);
    if (a < lbl_80562ADC) { fn_802E30C8(messages + 0x254, 0); return 0; }
    *(int *)((char *)out + 0xC) = (int)(lbl_80562B0C * a);
    *(int *)((char *)out + 8) = (int)(lbl_80562B0C * ((float (*)(void *, const char *, float))(*(void **)(*(void ***)object + 0x28)))(object, &lbl_8055ACB8, lbl_80562ADC));
    if (((int (*)(void *, const char *))(*(void **)(*(void ***)object + 0xC)))(object, &lbl_8055ACC0) == 0) { fn_802E30C8(messages + 0x2A4, 0); return 0; }
    b = ((float (*)(void *, const char *, float))(*(void **)(*(void ***)object + 0x28)))(object, &lbl_8055ACC0, lbl_80562AE4);
    *(float *)((char *)out + 0x10) = b;
    if (b < lbl_80562ADC) { fn_802E30C8(messages + 0x2E8, 0); return 0; }
    *(int *)((char *)out + 0x14) = 0;
    if (((int (*)(void *, const char *))(*(void **)(*(void ***)object + 0x5C)))(object, &lbl_8055ACC8)) *(int *)((char *)out + 0x14) = fn_801399FC();
    *(signed char *)((char *)out + 0x18) = ((signed char (*)(void *, const char *, int))(*(void **)(*(void ***)object + 0x30)))(object, messages + 0x338, 0);
    *(int *)((char *)out + 4) = 1;
    return 1;
}

int *__AXFXGetLfoSinTable_801D64F4(void) {
    extern char lbl_803387A8[];
    return (int *)lbl_803387A8;
}

int fn_801D6500(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D6508(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[7] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
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
void fn_801D6600(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D6618(UnkStruct_801D701C *arg0) {
    extern char lbl_80338C40[];
    arg0->name = lbl_80338C40;
    arg0->state = 0;
}
#pragma scheduling reset

int fn_801D6630(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
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
    register Dummy *obj = (register Dummy *)object;
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

int fn_801D67D4(void) {
    return (int)lbl_803387C8;
}

int fn_801D67E0(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D67E8(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
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

void fn_801D68D0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D68E8(UnkStruct_801D701C *arg0) {
    arg0->name = lbl_80338BD0;
    arg0->state = 0;
}
#pragma scheduling reset
int fn_801D6900(int arg0, int arg1) {
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
        Vec3 v = obj->vector2(&lbl_8055ACD4, Vec3(lbl_80562ADC, lbl_80562ADC, lbl_80562ADC));
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
extern "C" void fn_801D6BD0(void *arg0) {
    class ThreadObject {
    public:
        virtual void destroy(int);
    };
    ThreadObject *p = *(ThreadObject **)((u8 *)arg0 + 0x30);
    if (p) {
        if (p)
            p->destroy(1);
    }
    *(ThreadObject **)((u8 *)arg0 + 0x30) = 0;
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset
#pragma scheduling reset
#pragma pop

int fn_801D6C28(void) {
    extern char lbl_80338868[];
    return (int)lbl_80338868;
}

int fn_801D6C34(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D6C3C(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D6C68(void *arg0) {
    s32 remaining;
    void *obj;
    f32 value;
    remaining = lbl_8055E3C4 - (*(s32 *)((u8 *)arg0 + 0x10) + *(s32 *)((u8 *)arg0 + 0xC));
    if (*(s32 *)((u8 *)arg0 + 4) != 2) return;
    if (remaining <= 0) return;
    if (*(u8 *)((u8 *)arg0 + 0x16) != 0) {
        obj = *(void **)((u8 *)arg0 + 0x30);
        value = lbl_80562AE0;
        if (value != *(f32 *)((u8 *)obj + 8)) {
            *(u8 *)((u8 *)obj + 0x4D) = 1;
            *(f32 *)((u8 *)obj + 8) = value;
        }
    }
    if (*(u8 *)((u8 *)arg0 + 0x15) != 0) {
        obj = *(void **)((u8 *)arg0 + 0x30);
        *(u8 *)((u8 *)obj + 0x4A) = 0;
        *(u8 *)((u8 *)obj + 0x4B) = 1;
        *(u8 *)((u8 *)obj + 0x49) = 1;
        if (remaining >= *(s32 *)((u8 *)arg0 + 8)) {
            obj = *(void **)((u8 *)arg0 + 0x30);
            *(s32 *)((u8 *)arg0 + 4) = 3;
            *(u8 *)((u8 *)obj + 0x4A) = 1;
            *(u8 *)((u8 *)obj + 0x4C) = 0;
        }
    } else {
        u8 *q;
        int a;
        int b;
        q = *(u8 **)((u8 *)arg0 + 0x30);
        a = 1;
        b = 0;
        q[0x49] = (u8)a;
        a = 3;
        q[0x4B] = (u8)b;
        q[0x4A] = (u8)b;
        *(s32 *)((u8 *)arg0 + 4) = a;
    }
}

#pragma scheduling invalid_target
void fn_801D6D28(void* arg0) {
    unsigned char* ptr = *(unsigned char**)((char*)arg0 + 0x30);
    if (ptr != 0 && ptr[0x19] != 0) {
        ptr[0x4A] = 1;
        ptr[0x4C] = 0;
    }
    if (*(int*)((char*)arg0 + 4) == 0) {
        return;
    }
    *(int*)((char*)arg0 + 4) = 1;
}
#pragma scheduling on
void fn_801D6D68(UnkStruct_801D701C *arg0) {
    extern char lbl_80338B98[];
    arg0->name = lbl_80338B98;
    arg0->state = 0;
}
#pragma scheduling reset
int fn_801D6D80(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
extern "C" int fn_801D6DC8(void *arg0, void *arg1) {
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual char *get(char *, char *);
        virtual void v5(); virtual void v6(); virtual void v7();
        virtual float value(char *, float);
    };
    extern char lbl_8055ACB0;
    extern char lbl_8055ACE8;
    extern char lbl_8055ACF0;
    extern char lbl_8055ACF4;
    extern float lbl_80562B14;
    float initial = lbl_80562B14;
    Dummy *obj = (Dummy *)arg1;
    char *src;
    int remaining1;
    char *dst1;
    int remaining2;
    char *dst2;

    *(float *)((char *)arg0 + 8) = obj->value(&lbl_8055ACB0, initial);
    src = obj->get(&lbl_8055ACE8, &lbl_8055ACF0);
    dst1 = (char *)arg0 + 0xC;
    remaining1 = 0x40;
    goto copy_first;
count_first:
    if (--remaining1 > 0) goto copy_first;
    dst1[-1] = 0;
    goto done_first;
copy_first:
    if ((signed char)(*dst1++ = *src++) != 0) goto count_first;
done_first:
    src = obj->get(&lbl_8055ACF4, &lbl_8055ACF0);
    dst2 = (char *)arg0 + 0x4C;
    remaining2 = 0x40;
    goto copy_second;
count_second:
    if (--remaining2 > 0) goto copy_second;
    dst2[-1] = 0;
    goto done_second;
copy_second:
    if ((signed char)(*dst2++ = *src++) != 0) goto count_second;
done_second:
    *(int *)((char *)arg0 + 4) = 1;
    return 1;
}
#pragma pop
#pragma scheduling reset
#pragma cplusplus reset

extern char lbl_80338868[];
extern char lbl_80338B98[];
extern char lbl_80338878[];
int fn_801D6ED0(void) {
    return (int)lbl_80338878;
}

int fn_801D6EDC(int arg0) {
    return ((int *)arg0)[1];
}

#pragma push
#pragma scheduling invalid_target
int fn_801D6EE4(void *arg0) {
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
    register char *base;
    float t0;
    float t1;
    if (*(int *)((char *)arg0 + 4) != 1) {
        goto fail;
    }
    base = lbl_80442310;
    t0 = *(float *)((char *)arg0 + 8);
    t1 = lbl_8055E3C8;
    *(float *)(base + 4) = t0;
    *(float *)base = t1;
    src1 = (unsigned char *)arg0 + 0xC;
    dst1 = (unsigned char *)base + 0x48;
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
    src2 = (unsigned char *)arg0 + 0x4C;
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
    *(int *)((char *)arg0 + 4) = 3;
    return 1;
fail:
    return 0;
}
#pragma pop

void fn_801D6FA0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

void fn_801D6FB8(int arg0) {
    if (*(unsigned char *)(arg0 + 0x34) == 0) {
        if (fn_8016A15C((char *)arg0 + 8) != 0) {
            int p = ((int *)arg0)[0x38 / 4];
            *(char *)(p + 0x49) = 1;
            *(char *)(p + 0x4B) = 0;
            *(char *)(p + 0x4A) = 0;
        }
        *(char *)(arg0 + 0x34) = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D701C(UnkStruct_801D701C *arg0) {
    extern char lbl_80338B08[];
    arg0->name = lbl_80338B08;
    arg0->state = 0;
}
#pragma scheduling reset
int fn_801D7034(int arg0, int arg1) {
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
    float second;

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
    second = lbl_80562AEC;
    *(float *)((char *)arg0 + 0x30) = obj->value(&lbl_8055ACB0, second);
    *(int *)((char *)arg0 + 4) = 1;
    *(float *)((char *)arg0 + 0x2C) = lbl_80562ADC;
    *((char *)arg0 + 0x34) = 0;
    *(int *)((char *)arg0 + 0x38) = fn_80207848(lbl_803388C8, 1);
    return 1;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D71A8(void *arg0) {
    struct ThreadObject {
        virtual void destroy(int);
    };
    ThreadObject *obj = *(ThreadObject **)((char *)arg0 + 0x38);
    if (obj != 0 && obj != 0) {
        obj->destroy(1);
    }
    *(ThreadObject **)((char *)arg0 + 0x38) = 0;
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset

void *fn_801D7200(void) {
    return lbl_803388D4;
}

int fn_801D720C(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D7214(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[1] = 2;
        *(float *)((char *)arg0 + 0x2C) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

#pragma dont_inline on
void fn_801D7240(void *arg0) {
    extern float lbl_80562ADC;
    extern float lbl_8055E3C8;
    float f2;
    float f1;
    if (*(int *)((char *)arg0 + 4) == 2) {
        f2 = *(float *)((char *)arg0 + 0x30);
        if (f2 < lbl_80562ADC) {
            fn_801D6FB8((int)arg0);
            *(int *)((char *)arg0 + 4) = 3;
        } else {
            f1 = *(float *)((char *)arg0 + 0x2C);
            f1 += *(float *)((char *)arg0 + 0x28);
            if (f2 + f1 < lbl_8055E3C8) {
                fn_8016A240((char *)arg0 + 8);
                *(int *)((char *)arg0 + 4) = 3;
            } else if (f1 < lbl_8055E3C8) {
                fn_801D6FB8((int)arg0);
            }
        }
    }
}
#pragma dont_inline reset

void fn_801D72D0(void *arg0) {
    char *p;
    fn_8016A240((char *)arg0 + 8);
    p = *(char **)((char *)arg0 + 0x38);
    *(volatile int *)((char *)arg0 + 4) = 1;
    if (p != 0 && *(unsigned char *)(p + 0x19) != 0) {
        *(unsigned char *)(p + 0x4A) = 1;
        *(unsigned char *)(p + 0x4C) = 0;
    }
    *(unsigned char *)((char *)arg0 + 0x34) = 0;
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

int fn_801D76CC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801D770C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_801D774C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (((int)arg0 + 0x24) != 0) {
            if (((int)arg0 + 0x24) != 0) {
                *(int *)((char *)arg0 + 0x24) = 0;
                *(int *)((char *)arg0 + 0x28) = 0;
                *(int *)((char *)arg0 + 0x2C) = 0;
            }
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

char *fn_801D77AC(void) {
    return lbl_803388F0;
}

int fn_801D77B8(int arg0) {
    return ((int *)arg0)[2];
}

int fn_801D77C0(int arg0) {
    if (((int *)arg0)[2] == 0) {
        return arg0;
    }
    ((int *)arg0)[2] = 1;
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_801D77D8(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset
void fn_801D77E8(void) {
}

#pragma push
#pragma scheduling invalid_target
#pragma peephole off
void fn_801D77EC(void *arg0, unsigned int arg1) {
    int count;
    int index;
    unsigned int byteOffset;
    int last;
    unsigned int *items;

    count = *(int volatile *)((char *)arg0 + 0x74);
    index = 0;
    byteOffset = 0;
    for (; index < count; byteOffset += 4, index += 1) {
        items = *(unsigned int **)((char *)arg0 + 0x70);
        if (*(unsigned int *)((char *)items + byteOffset) != arg1)
            goto next_item;
        goto found;
    next_item:
        ;
    }
    index = -1;
found:
    if (index == -1)
        return;
    if (index < 0)
        return;
    count = *(int volatile *)((char *)arg0 + 0x74);
    if (index >= count)
        return;
    last = count - 1;
    if (index != last) {
        items = *(unsigned int **)((char *)arg0 + 0x70);
        items[index] = items[last];
    }
    count = *(int volatile *)((char *)arg0 + 0x74);
    *(int *)((char *)arg0 + 0x74) = count - 1;
}

#pragma cplusplus on
extern "C" char lbl_803385D0[];
#pragma cplusplus on
extern "C" void fn_801D7874(void *arg0, void *arg1) {
    struct ObjA { virtual void *v0(); };
    struct ObjB {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual int v6(char *, int);
    };
    struct ObjA *b = (struct ObjA *)arg1;
    void *node = b->v0();
    int match;
    if (*(int *)((char *)arg0 + 0xc) >= 0 && node != 0 && ((struct ObjB *)node)->v6(lbl_803385D0, -1) == *(int *)((char *)arg0 + 0xc)) {
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
#pragma cplusplus reset

#pragma pop

int fn_801D7924(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[10] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
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
    int index, initial = 0;
    float value, zero;
    *(int *)((char *)arg0 + 4) = initial;
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
    zero = lbl_80562ADC;
    if (value < zero) return 0;
    *(int *)((char *)arg0 + 0xC) = (int)(lbl_80562B0C * value);
    value = obj->value(&lbl_8055ACB8, zero);
    zero = lbl_80562ADC;
    *(int *)((char *)arg0 + 0x10) = (int)(lbl_80562B0C * value);
    obj->value(base + 0xAD8, zero);
    *(float *)((char *)arg0 + 0x14) = ((ManagerAlt *)arg1)->value(&lbl_8055AD10);
    obj->value(base + 0xAE4, lbl_80562AE0);
    *(float *)((char *)arg0 + 0x18) = ((ManagerAlt *)arg1)->value(&lbl_8055AD18);
    *(int *)((char *)arg0 + 0x28) = 1;
    ((Output *)arg0)->finish();
    return 1;
}
#pragma cplusplus reset

#pragma pop

void *fn_801D7C6C(void) {
    return lbl_8033890C;
}

int fn_801D7C78(int arg0) {
    return ((int *)arg0)[10];
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
    int temp_r31;
    int temp_r0;
    register float temp_f1;
    float current;
    float target;
    float var_f6;
    float value;

    if (*(int *)((char *)arg0 + 0x28) == 2) {
        temp_r31 = (lbl_8055E3C4 - *(int *)((char *)arg0 + 0x1C)) -
                   *(int *)((char *)arg0 + 0x10);
        if (temp_r31 >= 0) {
            var_f6 = lbl_80562AE0;
            temp_f1 = (float)*(int *)((char *)arg0 + 0x0C) - lbl_80562ADC;
            target = *(float *)((char *)arg0 + 0x24);
            current = *(float *)((char *)arg0 + 0x20);
            var_f6 = var_f6 < (((float)temp_r31 - lbl_80562ADC) / temp_f1)
                         ? var_f6
                         : ((float)temp_r31 - lbl_80562ADC) / temp_f1;
            var_f6 = var_f6 > lbl_80562ADC ? var_f6 : lbl_80562ADC;
            value = current + var_f6 * (target - current);
            temp_r0 = *(int *)((char *)arg0 + 4);
            if (temp_r0 != 0) {
                fn_801D9AB8((void *)temp_r0, value);
            } else {
                fn_80178DBC(*(int *)((char *)arg0 + 8), value);
            }
        }
        if (temp_r31 >= *(int *)((char *)arg0 + 0x0C)) {
            *(int *)((char *)arg0 + 0x28) = 3;
        }
    }
}

#pragma pop

void fn_801D7E3C(int arg0) {
    if (((int *)arg0)[10] != 0) {
        ((int *)arg0)[10] = 1;
    }
}

extern void fn_801D9AB8(void *, float);
extern void fn_80178DBC(int, float);
void fn_801D7E54(void *arg0) {
    void *temp;
    float f;
    if (*(int *)((char *)arg0 + 0x28) != 0) {
        if (*(int *)((char *)arg0 + 0x10) == 0) {
            temp = *(void **)((char *)arg0 + 4);
            f = *(float *)((char *)arg0 + 0x14);
            if (temp != 0) fn_801D9AB8(temp, f);
            else fn_80178DBC(*(int *)((char *)arg0 + 8), f);
        }
        *(int *)((char *)arg0 + 0x28) = 1;
    }
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
int fn_801D7F5C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_801D7F9C(void *arg0, void *arg1) {
    struct Dummy {
        virtual void v0();
        virtual char *get(char *);
        virtual void v2();
        virtual char *get2(char *);
        virtual char *get3(char *, char *);
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual float getFloat(float, char *);
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
        virtual int getInt(char *);
    };
    extern void fn_802E30C8(const char *, ...);
    extern int fn_801399FC(void);
    extern char lbl_80338460;
    extern char lbl_8055AD20;
    extern char lbl_8055AD28;
    extern char lbl_8055AD30;
    extern char lbl_8055ACB8;
    extern float lbl_80562ADC;
    extern float lbl_80562B0C;
    char *base = &lbl_80338460;
    Dummy *obj = (Dummy *)arg1;
    char *out = (char *)arg0;
    char *path;
    char *src;
    int remaining;
    char *dst;
    char *src2;
    int remaining2;
    char *dst2;
    int tmp;
    float v;
    float scale;
    float prod;
    path = obj->get(&lbl_8055AD20);
    if (path == 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(base + 0xB24);
        return 0;
    }
    src = obj->get2(&lbl_8055AD20);
    dst = out + 0x18;
    remaining = 0x14;
    goto copy_body1;
copy_limit1:
    if (--remaining > 0)
        goto copy_body1;
    dst[-1] = 0;
    goto copy_done1;
copy_body1:
    if ((signed char)(*dst++ = *src++) != 0)
        goto copy_limit1;
copy_done1:
    src2 = obj->get3(&lbl_8055AD28, &lbl_8055AD30);
    dst2 = out + 4;
    remaining2 = 0x14;
    goto copy_body2;
copy_limit2:
    if (--remaining2 > 0)
        goto copy_body2;
    dst2[-1] = 0;
    goto copy_done2;
copy_body2:
    if ((signed char)(*dst2++ = *src2++) != 0)
        goto copy_limit2;
copy_done2:
    tmp = obj->getInt(base + 0xB64);
    *(int *)(out + 0x3C) = tmp == 0 ? 0 : fn_801399FC();
    v = obj->getFloat(lbl_80562ADC, &lbl_8055ACB8);
    scale = lbl_80562B0C;
    *(int *)(out + 0x38) = 0;
    prod = scale * v;
    *(int *)(out + 0x2C) = 0;
    *(int *)(out + 0x40) = 1;
    *(int *)(out + 0x30) = (int)prod;
    ((void (*)(const char *, ...))fn_802E30C8)(base + 0xB70, out + 4, out + 0x18);
    return 1;
}
#pragma cplusplus reset
#pragma pop
extern char lbl_80338928[];
void *fn_801D8148(void) {
    return lbl_80338928;
}

int fn_801D8154(void *arg0) {
    return *(int *)((char *)arg0 + 0x40);
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
void fn_801D825C(void *arg0) {
    if (*(int *)((char *)arg0 + 0x40) != 0) {
        *(void **)((char *)arg0 + 0x2C) = fn_801DA8C8((char *)arg0 + 4, (char *)arg0 + 0x18);
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

void fn_801D832C(void *arg0) {
    if (*(int *)((char *)arg0 + 0x40) != 0) {
        *(int *)((char *)arg0 + 0x40) = 1;
    }
}

#pragma cplusplus on
extern "C" void fn_801D8344(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    if (*(int *)((char *)arg0 + 0x40) != 0) {
        Dummy *p = *(Dummy **)((char *)arg0 + 0x2C);
        if (p != 0) {
            p->v5();
        }
        *(int *)((char *)arg0 + 0x40) = 1;
    }
}
#pragma cplusplus reset

int fn_801D839C(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x18)) >> 5;
}

#pragma cplusplus on
extern "C" void fn_801D83AC(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

int fn_801D83BC(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x30)) >> 5;
}

#pragma cplusplus on
extern "C" void fn_801D83CC(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

int fn_801D83DC(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
#pragma scheduling invalid_target
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
    extern float lbl_80562ADC;
    extern float lbl_80562B0C;
    extern char lbl_8055ACB0;
    extern char lbl_8055ACB8;
    extern char lbl_8055AD48;
    extern int fn_8029F3BC(void);
    Dummy *obj = (Dummy *)arg1;
    float f1_ = obj->get(&lbl_8055ACB0, lbl_80562ADC);
    float f2_ = obj->get(&lbl_8055ACB8, lbl_80562ADC);
    float s1_ = lbl_80562B0C * f1_;
    float s2_ = lbl_80562B0C * f2_;
    int r1_ = (int)s1_;
    int r2_ = (int)s2_;
    *(int *)((char *)arg0 + 8) = r1_;
    *(int *)((char *)arg0 + 0xC) = r2_;
    obj->set(&lbl_8055AD48, r1_);
    int st_ = fn_8029F3BC();
    *(int *)((char *)arg0 + 0x14) = st_;
    if (st_ < 0) return 0;
    *(int *)((char *)arg0 + 4) = 1;
    return 1;
}
#pragma cplusplus reset
#pragma pop

void *fn_801D8504(void) {
    return lbl_80339038;
}

int fn_801D8510(void *arg0) {
    return *(int *)((char *)arg0 + 0x4);
}

int fn_801D8518(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
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
extern "C" void fn_801D85C8(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

void fn_801D85D8(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D85F0(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x14)) >> 5;
}

void fn_801D8600(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D8618(void) {
    return 0;
}

void fn_801D8620(void) {

}

#pragma cplusplus on
extern "C" void fn_801D8624(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}

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
    *(float *)((char *)out + 0xC) = thing->v8(&lbl_8055ACB8, lbl_80562ADC);
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

#pragma cplusplus reset

void fn_801D8710(int arg0) {
    if (arg0 != 0) {
        arg0 += 4;
    }
    fn_801D05B4(arg0);
}

void *fn_801D8720(void) {
    return lbl_8033905C;
}

int fn_801D872C(int arg0) {
    return ((int *)arg0)[6];
}

int fn_801D8734(void) {
    return 0;
}

int fn_801D873C(int arg0) {
    ((int *)arg0)[6] = 2;
    ((int *)arg0)[8] = 0;
    *(float *)((char *)arg0 + 0x10) = lbl_8055E3C8;
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
    int count, offset;
    float time;
    char *entry;
    Dummy *item;
    if (*(int *)((char *)arg0 + 0x18) != 2) return;
    time = lbl_8055E3C8;
    if (*(int *)((char *)arg0 + 0x20) == 0) {
        if (!(time - *(float *)((char *)arg0 + 0x10) > *(float *)((char *)arg0 + 0xC))) return;
        count = 0; offset = 0;
        goto first_test;
first_loop:
        entry = (char *)*(int *)((char *)arg0 + 0x24) + offset;
        item = *(Dummy **)entry;
        item->first(*(int *)((char *)arg0 + 0x1C));
        item = *(Dummy **)entry;
        item->second(*(int *)(entry + 8));
        offset += 0xC; count += 1;
first_test:
        if (count < *(int *)((char *)arg0 + 0x28)) goto first_loop;
        *(int *)((char *)arg0 + 0x20) = 1;
    } else {
        if (!(time - *(float *)((char *)arg0 + 0x10) - *(float *)((char *)arg0 + 0xC) > *(float *)((char *)arg0 + 0x14))) return;
        count = 0; offset = 0;
        goto second_test;
second_loop:
        entry = (char *)*(int *)((char *)arg0 + 0x24) + offset;
        item = *(Dummy **)entry;
        item->first(*(int *)(entry + 4));
        item = *(Dummy **)entry;
        item->second(-1);
        offset += 0xC; count += 1;
second_test:
        if (count < *(int *)((char *)arg0 + 0x28)) goto second_loop;
        *(int *)((char *)arg0 + 0x18) = 1;
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801D88AC(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D88BC(void *arg0) {
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void dispatch(int);
    };
    int i;
    *(int *)((char *)arg0 + 0x18) = 1;
    for (i = 0; i < *(int *)((char *)arg0 + 0x28); i++) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)arg0 + 0x24) + i * 0xC);
        entry->dispatch(-1);
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
    Request *request = (Request *)arg1;
    int *output = (int *)arg0;
    NameObject *object = (NameObject *)request->getObject();
    volatile int first;
    int second;
    if (object == 0) return;
    if (object->find(lbl_803385D0, -1) != output[2]) return;
    first = request->getFirst();
    second = request->getSecond();
    int count = output[0x28 / 4];
    Record *records = (Record *)output[0x24 / 4];
    output[0x28 / 4] = count + 1;
    records[count].object = request;
    records[count].first = first;
    records[count].second = second;
    request->finish(-1, (int)&records[count], count + 1, (int)records);
}
#pragma cplusplus reset
#pragma pop
int fn_801D8AA4(void *arg0) {
    extern float lbl_80562ADC;
    return *(float *)((char *)arg0 + 0x30) < lbl_80562ADC;
}

#pragma cplusplus on
extern "C" void fn_801D8ABC(void *arg0) {
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
    ((Dummy *)arg0)->v11();
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
    float value = lbl_80562ADC;
    Dummy *obj = (Dummy *)arg1;
    *(int *)((char *)arg0 + 4) = 1;
    *(float *)((char *)arg0 + 0x10) = value;
    *(float *)((char *)arg0 + 8) = obj->get(&lbl_8055ACB8, value);
    *(float *)((char *)arg0 + 0xC) = obj->get(&lbl_8055ACB0, lbl_80562B14);
    return 1;
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
extern "C" int fn_801D8B60(void *arg0, void *arg1) {
    extern char lbl_80339070[];
    extern char lbl_8055ACB8;
    extern char lbl_8055ACB0;
    extern float lbl_80562ADC;
    extern float lbl_80562B14;
    extern float lbl_80562B20;
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float value(char *, float);
    };
    Dummy *obj = (Dummy *)arg1;
    float temp;

    *(float *)((char *)arg0 + 0x14) = obj->value(lbl_80339070, lbl_80562B20);
    *(int *)((char *)arg0 + 4) = 1;
    temp = lbl_80562ADC;
    *(float *)((char *)arg0 + 0x10) = temp;
    *(float *)((char *)arg0 + 8) = obj->value(&lbl_8055ACB8, temp);
    *(float *)((char *)arg0 + 0xC) = obj->value(&lbl_8055ACB0, lbl_80562B14);
    return 1;
}
#pragma cplusplus reset
#pragma pop

void fn_801D8C0C(void *arg0) {
    *(int *)((char *)arg0 + 0x18) = -1;
}

void fn_801D8C18(void) {
}

extern float lbl_80562AE4;
extern void fn_801E1F78(void);
void fn_801D8C1C(void *arg0, float farg0) {
    float tmp = farg0 / *(float *)((char *)arg0 + 0x14);
    float v;
    int t;
    if (farg0 / *(float *)((char *)arg0 + 0x14) < lbl_80562ADC) {
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

void fn_801D8C94(void) {
}

void *fn_801D8C98(void) {
    return lbl_8033907C;
}

int fn_801D8CA4(void *arg0) {
    return ((int *)arg0)[1];
}

#pragma cplusplus on
extern "C" s32 fn_801D8CAC(void *arg0) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12();
        s32 f4;
        u8 pad[8];
        f32 f10;
    };
    Obj *o = (Obj *)arg0;
    if (o->f4 == 1) {
        o->f4 = 2;
        o->f10 = lbl_8055E3C8;
        o->v12();
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
extern "C" void fn_801D8DA0(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

void fn_801D8DB0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D8DC8(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
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

char *fn_801D8EF0(void) {
    return lbl_803389B8;
}

int fn_801D8EFC(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_801D8F04(void *arg0) {
    if (*(int *)((char *)arg0 + 4) == 1) {
        *(int *)((char *)arg0 + 4) = 2;
        *(float *)((char *)arg0 + 0x20) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

extern char lbl_803390C0[];
extern void fn_802E30C8();
extern void fn_801D488C(int, int, int, float *);
void fn_801D8F30(void *arg0) {
    struct Obj { char pad[8]; char field; };
    float vec[3];
    int result;
    if (*(int *)((char *)arg0 + 4) == 2 && lbl_8055E3C8 - *(float *)((char *)arg0 + 0x20) >= *(float *)((char *)arg0 + 0x1C)) {
        result = ((int (*)(void *))fn_801D4888)((char *)arg0 + 8);
        if (result == 0) {
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_803390C0, &((struct Obj *)arg0)->field);
        } else {
            vec[0] = lbl_80562ADC;
            vec[1] = lbl_80562ADC;
            vec[2] = lbl_80562ADC;
            ((void (*)(int, int, int, float *))fn_801D488C)(result, 1, 0, vec);
        }
        *(int *)((char *)arg0 + 4) = 3;
    }
}

#pragma cplusplus on
extern "C" void fn_801D8FD0(void *arg0) {
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
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

void fn_801D8FE0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

extern char lbl_803385D0[];

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
