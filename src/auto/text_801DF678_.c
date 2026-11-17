// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma cplusplus on
class MenuResource_801DFFB4 {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void* find(const char*) = 0;
};
#pragma cplusplus off
extern int lbl_804348E8[4];
extern double fn_8002EFB4(void);
extern void fn_801476D8(int, int);
extern void fn_80128668(void*);
extern void* lbl_8055EA04;
extern float lbl_8055AE30;
extern float lbl_80562C1C;
extern float lbl_80562C3C;
extern float lbl_80562C40;
extern float lbl_80562C44;
extern float lbl_80562C48;
extern int lbl_8055E4D0;
extern float PSVECMag(void*);
extern char lbl_8055AE2C;
/* Scalar-deleting style destructor/cleanup for a small 3-word object: clears
 * its three 32-bit fields to 0 and, if deleteFlags > 0, frees the storage.
 * Returns this. (The redundant inner null check is intentional.) */
void* fn_801DF678(void* this_, int deleteFlags) {
    if (this_ != 0) {
        if (this_ != 0) {
            *(int*)this_ = 0;
            *((int*)this_ + 1) = 0;
            *((int*)this_ + 2) = 0;
        }
        if (deleteFlags > 0)
            fn_80128668(this_);
    }
    return this_;
}

#pragma scheduling invalid_target
void fn_801DF6D0(void* elem) {
    /* Initialize one pool element: clear its counters, point its two default
     * pointers at the shared empty value, and set the index word to -1. */
    int zero = 0;
    void* ptr = &lbl_8055AE2C;
    *(int*)((char*)elem + 0x18) = zero;
    *(void**)((char*)elem + 4) = ptr;
    *(void**)((char*)elem + 8) = ptr;
    *(char*)elem = zero;
    *(int*)((char*)elem + 0xC) = zero;
    *(int*)((char*)elem + 0x10) = zero;
    *(int*)((char*)elem + 0x14) = -1;
}
#pragma scheduling on
extern void *fn_801284F8(int, void *);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int fn_80145E70(void *);
extern void fn_801D0DDC(void *);
extern int fn_80207848(void *, int);
extern int fn_802CAC28(void *, int);
extern int stricmp(const char *, const char *);
extern char lbl_803381C0[], lbl_803395D8[], lbl_80339744[];
__declspec(section ".sdata") extern const char lbl_8055AE44[], lbl_8055AE4C[];
extern void *lbl_8055EA04;
#pragma use_lmw_stmw off
void fn_801DF6FC(void) {
    void *obj, *iter, *list, *entry;
    int i, j, n;
    char *p, *q;
    float f, keep;
    char *base = lbl_803395D8;
    obj = fn_801284F8(0x1B4, base);
    if (obj) {
        *(void **)obj = lbl_803381C0;
        fn_801D0DDC(obj);
        *(void **)obj = lbl_80339744;
        lbl_8055EA04 = obj;
        *(int *)((char *)obj + 0xE4) = fn_80145E70(base + 0xC);
        *(int *)((char *)obj + 0xF0) = fn_802CAC28(base + 0x1C, 0);
        *(int *)((char *)obj + 0xE8) = fn_802CAC28(base + 0x28, 0);
        *(int *)((char *)obj + 0xEC) = fn_802CAC28(base + 0x34, 0);
        *(int *)((char *)obj + 0xF4) = fn_802CAC28(base + 0x40, 0);
        *(int *)((char *)obj + 0xF8) = fn_80207848(base + 0x50, 1);
        for (i = 0; i < 3; i++) {
            ((int *)((char *)obj + 0xFC))[i] = fn_80207848(base + 0x60, 1);
        }
        *(int *)((char *)obj + 0x108) = 0;
        *(int *)((char *)obj + 0x10C) = fn_80207848(base + 0x70, 1);
        *(int *)((char *)obj + 0x1B0) = 0;
        iter = fn_80131808(base + 0x80);
        if (iter) {
            list = ((void *(*)(void *, void *))(*(void ***)iter)[2])(iter, base + 0x8C);
            for (j = 0; (entry = ((void *(*)(void *, int))(*(void ***)list)[0x18])(list, j)) != 0; j++) {
                p = ((char *(*)(void *))(*(void ***)entry)[2])(entry);
                if (stricmp(p, lbl_8055AE44) == 0) {
                    keep = ((float (*)(void *, const char *))(*(void ***)entry)[9])(entry, lbl_8055AE44);
                    p = ((char *(*)(void *, const char *))(*(void ***)entry)[5])(entry, lbl_8055AE4C);
                    f = ((float (*)(void *, const char *))(*(void ***)entry)[9])(entry, base + 0x9C);
                    n = *(int *)((char *)obj + 0x1B0);
                    *(int *)((char *)obj + 0x1B0) = n + 1;
                    q = (char *)obj + n * 0x28 + 0x114;
                    *(float *)(q - 4) = f;
                    i = 0x20;
                    while (1) {
                        *q++ = *p++;
                        if (q[-1] == 0) break;
                        if (--i <= 0) {
                            q[-1] = 0;
                            break;
                        }
                    }
                    *(float *)(q + 0x1C) = keep;
                }
            }
            fn_80131818(iter);
        }
    }
}
#pragma use_lmw_stmw on
int fn_801DF93C(int arg0) { (void)arg0; return 1; }

void fn_801476D8(int, int);
void fn_801DFE44(int object, int value) { ((void (*)(int, int, int))fn_801476D8)(object, -1, value); }

#pragma cplusplus on
struct Dummy_801DFE50 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
};
extern "C" void fn_801DFE50(void *object, int unused, int value) {
    /* Forward helper: fetches a target from the object's vtable slot 2 and passes it to fn_801476D8 with -1 and the given value. */
    struct Dummy_801DFE50_Local {
        virtual void d0();
        virtual void d1();
        virtual void* d2();
    };
    void *target = ((Dummy_801DFE50_Local *)object)->d2();
    ((void (*)(void *, int, int))fn_801476D8)(target, -1, value);
}
#pragma cplusplus reset

float fn_801DFE94(double x, double y) {
    /* Single-precision fmod: compute the double-precision remainder fn_8002EFB4(x, y) and round it to float. */
    return (float)((double (*)(double, double))fn_8002EFB4)(x, y);
}

typedef void (*Fn)(void *);
#pragma cplusplus on
extern "C" void fn_801DFEB8(void *arg0, int arg1, int arg2, int arg3) {
    /* Forward helper: fetch an object from arg0's vtable (slot 2) and pass it with (arg2, arg3) to fn_801476D8. arg1 is unused. */
    struct VTableSlot2 {
        virtual void d0();
        virtual void d1();
        virtual void *getTarget();
    };
    void *target = ((VTableSlot2 *)arg0)->getTarget();
    ((void (*)(void *, int, int))fn_801476D8)(target, arg2, arg3);
}
#pragma cplusplus reset
/* Return the vehicle stored in the car table (lbl_804348E8) at the given slot index. */
int fn_801DFF08(int index) { return lbl_804348E8[index]; }

void fn_801DFF1C(int arg0) {
    int index = arg0;
    char* entry = (char*)lbl_8055EA04 + index * 0x1C;
    void* vec = ((void**)lbl_804348E8)[index];
    *(float*)(entry + 4) = lbl_80562C3C;
    *(float*)(entry + 0x10) = lbl_80562C1C;
    *(float*)(entry + 8) = lbl_80562C40;
    *(char*)(entry + 0xC) = 0;
    *(float*)(entry + 0x14) = lbl_80562C44 * (lbl_8055AE30 * PSVECMag((char*)vec + 0x118)) / lbl_80562C48;
    *(char*)(entry + 0x18) = 0;
    *(int*)(entry + 0x1C) = -1;
}

extern float lbl_8055AE40, lbl_80562C18, lbl_80562C4C, lbl_80562C1C;
extern double __fabs(double);
__declspec(section ".data") extern float lbl_80558DC4;
extern float lbl_80562C30, lbl_80562C20, lbl_80562C28;
extern double lbl_80562C50;
extern int lbl_8055CFF0;
extern char lbl_80339738[];
extern int fn_801E866C(int);
extern int fn_80179650(void);
extern int fn_801B8570(int);
extern int fn_801769F8(void);
extern int fn_80161BB8(void);
extern float fn_801E7E18(void);
extern float fn_802C9A50(void);
extern void fn_80148100(void *);
#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_801DFFB4(void) {
    /* Renders the "whiteout" screen flash: derive a 0..1 opacity from how long
     * ago the event fired, write white-with-alpha into the named menu pane,
     * set its width and refresh it, guarded on the active game/subsystem state.
     * (lbl_/fn_ names kept: rename_symbol unavailable for game symbols.)
     *   WO_DURATION/WO_DURATION_DIV = 1.5/3 -> 0.5s half-window,
     *   WO_MIN_ALPHA/WO_MAX_ALPHA = 0/1, WO_ALPHA_SCALE = 255,
     *   WO_FADE_SCALE = 0.5, WO_TIME_OFFSET = 0.1, WO_REF_WIDTH = 640. */
    #define WO_DURATION      lbl_8055AE40
    #define WO_DURATION_DIV  lbl_80562C18
    #define WO_MIN_ALPHA     lbl_80562C1C
    #define WO_MAX_ALPHA     lbl_80562C20
    #define WO_ALPHA_SCALE   lbl_80562C28
    #define WO_FADE_SCALE    lbl_80562C30
    #define WO_TIME_OFFSET   lbl_80562C4C
    #define WO_EPSILON       lbl_80558DC4
    #define WO_REF_WIDTH     lbl_8055CFF0

    register int subjectIndex;
    register float halfWindow;
    register float remaining;
    float temp;
    float fadeStart;
    float fade;
    float opacity;
    register void *whiteoutPane;
    void *manager;
    void *(*findFn)(void *, const char *);

    manager = lbl_8055EA04;
    subjectIndex = fn_801E866C(0);
    if (fn_80179650() == 1 && fn_801B8570(subjectIndex) && !fn_801769F8() && !fn_80161BB8()) {
        halfWindow = WO_DURATION / WO_DURATION_DIV;
        temp = fn_801E7E18() - *(float *)((char *)manager + subjectIndex * 0x1C + 8);
        temp = halfWindow - temp;
        temp = WO_TIME_OFFSET + temp;
        remaining = WO_MIN_ALPHA;
        remaining = (remaining > temp) ? remaining : temp;

        if (!((float)__fabs((double)remaining) <= WO_EPSILON)) {
            whiteoutPane = *(void **)((char *)manager + 0xE4);
            whiteoutPane = ((MenuResource_801DFFB4 *)whiteoutPane)->find(lbl_80339738);
            fadeStart = halfWindow * WO_FADE_SCALE;
            opacity = WO_MAX_ALPHA;
            fade = (remaining - fadeStart) / (WO_TIME_OFFSET - fadeStart);
            opacity = (opacity < fade) ? opacity : fade;
            opacity = (opacity > WO_MIN_ALPHA) ? opacity : WO_MIN_ALPHA;
            *(int *)((char *)whiteoutPane + 0x18) = ((int)(opacity * WO_ALPHA_SCALE + WO_MIN_ALPHA) << 24) | 0xFFFFFF;
            temp = fn_802C9A50();
            *(float *)((char *)whiteoutPane + 0x10) = (float)WO_REF_WIDTH / temp;
            fn_80148100(whiteoutPane);
        }
    }

    #undef WO_DURATION
    #undef WO_DURATION_DIV
    #undef WO_MIN_ALPHA
    #undef WO_MAX_ALPHA
    #undef WO_ALPHA_SCALE
    #undef WO_FADE_SCALE
    #undef WO_TIME_OFFSET
    #undef WO_EPSILON
    #undef WO_REF_WIDTH
}
#pragma pop
#pragma cplusplus on
extern "C" void fn_801D0DFC(void *);
extern "C" void fn_802CAC54(int);
extern "C" void *fn_801E0150(void *object, int freeFlag) {
    /* Destructor: release owned subobjects/texture refs, clear global, run base dtor, optionally free. */
    struct LocalObj {
        virtual void d0(int);
    };
    LocalObj *subObject;
    char *slotPtr;
    int index;
    void *result = object;

    if (object != 0) {
        subObject = *(LocalObj **)((char *)object + 0x10C);
        *(void **)object = lbl_80339744;
        if (subObject != 0) {
            if (subObject != 0)
                subObject->d0(1);
        }

        slotPtr = (char *)object;
        index = 0;
        do {
            subObject = *(LocalObj **)(slotPtr + 0xFC);
            if (subObject != 0) {
                if (subObject != 0)
                    subObject->d0(1);
            }
            ++index;
            slotPtr += 4;
        } while (index < 3);

        subObject = *(LocalObj **)((char *)object + 0xF8);
        if (subObject != 0) {
            if (subObject != 0)
                subObject->d0(1);
        }

        fn_802CAC54(*(int *)((char *)object + 0xF4));
        fn_802CAC54(*(int *)((char *)object + 0xEC));
        fn_802CAC54(*(int *)((char *)object + 0xE8));
        fn_802CAC54(*(int *)((char *)object + 0xF0));
        lbl_8055EA04 = 0;

        subObject = *(LocalObj **)((char *)object + 0xE4);
        if (subObject != 0)
            subObject->d0(1);

        if (object != 0) {
            *(void **)object = lbl_803381C0;
            fn_801D0DFC(object);
        }
        if (freeFlag > 0)
            fn_80128668(object);
    }
    return result;
}
#pragma cplusplus reset

void fn_801E02A8(void) {

}

void fn_801E02AC(void) {

}

void fn_801E02B0(void* arg0) {
    float b;
    float a;
    char* entry;
    int i;
    a = lbl_80562C40;
    b = lbl_80562C1C;
    entry = (char*)arg0 + 4;
    i = 0;
    while (i < lbl_8055E4D0) {
        *(char*)(entry + 8) = 0;
        i++;
        *(float*)(entry + 4) = a;
        *(float*)(entry + 0xC) = b;
        *(float*)(entry + 0x10) = b;
        *(char*)(entry + 0x14) = 0;
        *(int*)(entry + 0x18) = -1;
        *(float*)entry = b;
        entry += 0x1C;
    }
}

/* One slip/skid instance of the manager built by fn_801DF6FC: its entry
 * array starts at +4 and holds lbl_8055E4D0 records, one per vehicle in
 * lbl_804348E8.  fn_801DFF1C and fn_801E02B0 set the fields up. */
struct SlipEntry {
    float charge;           /* 0x00: 0.15..1.0, how strong the effect is */
    float timer;            /* 0x04: when it was raised; < 0 while waiting */
    unsigned char active;   /* 0x08: it has been raised */
    char pad09[3];          /* 0x09 */
    float elapsed;          /* 0x0C: seconds it has been running */
    float slip;             /* 0x10: slip built up since it started */
    unsigned char started;  /* 0x14: its sound has been started */
    char pad15[3];          /* 0x15 */
    int zone;               /* 0x18: sound zone that slip reached, -1 none */
};

extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void fn_8014E61C(int, int, float);
extern int fn_80009C84(void);
extern float PSVECDotProduct(void *, void *);
extern void *fn_801B83A0(void);
extern double __fabs(double);
extern float lbl_8055AE34, lbl_8055AE38, lbl_8055AE3C, lbl_8055E3C8;
extern float lbl_80562C58, lbl_80562C5C, lbl_80562C60, lbl_80562C64, lbl_80562C68, lbl_80562C6C, lbl_80562C70, lbl_80562C74;
__declspec(section ".data") extern float lbl_80558DC4;

extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void fn_8014E61C(int, int, float);
extern int fn_80009C84(void);
extern float PSVECDotProduct(void *, void *);
extern void *fn_801B83A0(void);
extern float lbl_8055AE34, lbl_8055AE38, lbl_8055AE3C, lbl_8055E3C8;
extern float lbl_80562C58, lbl_80562C5C, lbl_80562C60, lbl_80562C64, lbl_80562C68, lbl_80562C6C, lbl_80562C70, lbl_80562C74;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
/* One frame of the slip/skid effects the manager built by fn_801DF6FC holds.
 *
 * For every running instance (one per vehicle in lbl_804348E8) it adds a
 * frame to the instance's timers and, while its sound has not started yet,
 * builds up slip from the vehicle's speed and spin; once that slip passes a
 * named zone's threshold the zone's sound is started.  A waiting instance
 * charges up while the vehicle is slipping, and reaching full charge - or
 * the slip stopping - raises the effect and pokes one of the manager's three
 * cycling effect objects to play it; a raised or never-started instance then
 * fades back down and tells the sound manager about the change.
 */
extern "C" void fn_801E0300(void *manager) {
    struct FxIface {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
        virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
        virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
        virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void notify(int, int);   /* slot 0xA0: instance, vehicle field 0x26A4 */
    };
    char *vehicle;
    char *zone;
    int *vehicles;
    struct SlipEntry *entry;
    int i, j, changed, muted;
    float fadeStep, chargeMin, chargeDecay, fullCharge, chargeMax, chargeStep, zero,
          slipScale, spinLimit, speedLimit, frameTime, time, sinceSlip, slipLimit,
          timerValue, timeDiv;
    if ((((int *)__AXFXGetLfoSinTable_801769CC())[1] & 0x4000) != 0) return;   /* session flags */
    vehicles = lbl_804348E8;
    zero = lbl_80562C1C; chargeStep = lbl_80562C4C; chargeMax = lbl_80562C68;
    entry = (struct SlipEntry *)((char *)manager + 4);
    chargeDecay = lbl_80562C6C; chargeMin = lbl_80562C3C;
    i = 0;
    frameTime = lbl_80562C58; speedLimit = lbl_80562C60; slipScale = lbl_80562C5C; spinLimit = lbl_80562C64;
    fadeStep = lbl_80562C70; timerValue = lbl_80562C74; timeDiv = lbl_80562C18; fullCharge = lbl_80562C20;
    for (; i < lbl_8055E4D0; vehicles++, entry++, i++) {
        vehicle = (char *)*vehicles;
        if ((float)__fabs((double)*(float *)(vehicle + 0x2690)) <= lbl_80558DC4) continue;
        entry->elapsed += frameTime;
        if (entry->started == 0) {
            float spin = PSVECMag(vehicle + 0x124);
            float velocity = PSVECMag(vehicle + 0x118);
            entry->slip += frameTime * (lbl_8055AE34 * velocity + lbl_8055AE38 * spin);
            muted = ((int *)__AXFXGetLfoSinTable_801769CC())[1] == 0x180201;
            if (!muted && entry->elapsed > lbl_8055AE3C) {
                entry->zone = -1;
                zone = (char *)manager;
                for (j = 0; j < *(int *)((char *)manager + 0x1B0); zone += 0x28, j++) {
                    if (entry->slip > *(float *)(zone + 0x110)) entry->zone = j;
                }
                if (entry->zone >= 0)
                    fn_8014E61C(i, 4, *(float *)((char *)manager + entry->zone * 0x28 + 0x134));
                entry->started = 1;
            }
        }
        {
            float speed = *(float *)(vehicle + 0x25D4);
            time = lbl_8055E3C8;
            sinceSlip = time - *(float *)(vehicle + 0x26A0);
            slipLimit = lbl_80562C5C;
            if (speed > speedLimit || PSVECDotProduct(vehicle + 0x124, vehicle + 0x124) > spinLimit)
                slipLimit *= slipScale;
        }
        changed = 0;
        if (entry->timer < zero && entry->active == 0) {
            if (*(unsigned char *)(vehicle + 0x260E) != 0 && sinceSlip < slipLimit && fn_80179650() == 1) {
                entry->charge += chargeStep;
                if (*(int *)((char *)manager + *(int *)((char *)manager + 0x108) * 4 + 0xFC) != 0 && *(int *)(vehicle + 0x1F0) == 0x50 && fn_80009C84() == 0) {
                    char *effect = (char *)*(int *)((char *)manager + *(int *)((char *)manager + 0x108) * 4 + 0xFC);
                    effect[0x49] = 1; effect[0x4B] = 0; effect[0x4A] = 0;
                    *(int *)((char *)manager + 0x108) = (*(int *)((char *)manager + 0x108) + 1) % 3;
                }
            }
            if (entry->charge >= chargeMax) {
                entry->charge = fullCharge;
                entry->active = 1;
                entry->timer = time;
                if (*(int *)((char *)manager + 0xF8) != 0 && *(int *)(vehicle + 0x1F0) == 0x50 && fn_80009C84() == 0) {
                    char *effect = (char *)*(int *)((char *)manager + 0xF8);
                    effect[0x49] = 1; effect[0x4B] = 0; effect[0x4A] = 0;
                }
            } else if (sinceSlip >= slipLimit) {
                entry->timer = time;
                if (*(int *)((char *)manager + 0x10C) != 0 && *(int *)(vehicle + 0x1F0) == 0x50 && fn_80009C84() == 0) {
                    char *effect = (char *)*(int *)((char *)manager + 0x10C);
                    effect[0x49] = 1; effect[0x4B] = 0; effect[0x4A] = 0;
                }
            } else {
                float down = entry->charge - chargeDecay;
                entry->charge = down > chargeMin ? down : chargeMin;
            }
        } else {
            if (entry->active == 0) {
                float down = entry->charge - fadeStep;
                entry->charge = down > zero ? down : zero;
            }
            if (time - entry->timer > lbl_8055AE40 / timeDiv) {
                changed = 1;
                if (entry->active != 0) {
                    *(float *)(vehicle + 0x258C) = timerValue;
                    *(unsigned char *)(vehicle + 0x259D) = 0;
                }
            }
        }
        if (changed != 0) {
            FxIface *o = (FxIface *)fn_801B83A0();
            o->notify(i, *(int *)(vehicle + 0x26A4));
        }
    }
}
#pragma cplusplus reset
#pragma pop
