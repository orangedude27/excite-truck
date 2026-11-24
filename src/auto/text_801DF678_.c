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
    register int zero = 0;
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
        *(int *)((char *)obj + 0x108) = zero;
        *(int *)((char *)obj + 0x10C) = fn_80207848(base + 0x70, 1);
        *(int *)((char *)obj + 0x1B0) = zero;
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
                            q[-1] = zero;
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
#pragma push
#pragma processor 750
__declspec(section ".sdata") extern char lbl_8055AE58[];
#pragma push
#pragma processor 750
int fn_801DF93C(int arg0)
{
  extern float lbl_8055AE40;
  extern float lbl_80562C20;
  extern float lbl_80562C24;
  extern float lbl_80562C28;
  extern float lbl_80562C2C;
  extern float lbl_80562C30;
  extern float lbl_80562C34;
  extern float lbl_80562C38;
  extern float fn_8014AEC8(void *);
  extern int fn_80141F7C(float);
  extern void *fn_801E85A4(void);
  extern void fn_8014C72C(void *, void *);
  extern float fn_8014C8F8(float, float, float);
  extern float fn_80176A2C(void);
  extern float fn_801E7E18(void);
  extern float fn_801429D0(float, float);
  extern int fn_80144C68(unsigned int, unsigned int, unsigned int, unsigned int);
  extern void fn_80147C50(int, int, float);
  extern void fn_801DFEB8(void *, void *, int, int);
  extern void fn_801DFE50(void *, int, int);
  extern void fn_801DFE44(int, int);
  extern int fn_801DFF08(int);
  extern float fn_8014C8B4(float, float, float, float, float);
  extern void fn_8014C978(void *, void *);
  extern void fn_8014C7B4(void *, void *);
  extern float fn_80144BD8(float);
  extern float fn_801DFE94();
  extern long long fn_8014C770(const float *, const float *, float);
  extern void fn_8014C75C(float *, const float *);
  extern void fn_801479A8(void *, void *, void *, float, ...);
  extern void *fn_80131234(void *);
  extern void *__AXFXGetLfoSinTable_801769CC(void);
  struct DrawMat
  {
    char pad0[0x10];
    float w;
    char pad1[0xc];
    float h;
    char pad2[4];
  } m;
  struct Pt
  {
    float x;
    float y;
  } pt;
  long long pair;
  char m2[0x28];
  register void *mgr;
  register int subject;
  register char *base;
  register char *entry;
  float f31;
  float f27;
  float f30;
  float opacity;
  float now;
  int c1;
  int c2;
  int c3;
  void *obj1;
  void *obj2;
  void *obj3;
  void *obj4;
  void *obj5;
  void *obj6;
  float w;
  float rem;
  float ratio;
  float r1;
  float r2;
  float ease;
  float v;
  float t;
  float interp;
  mgr = lbl_8055EA04;
  base = lbl_803395D8;
  subject = fn_801E866C(arg0);
  if (fn_80141F7C(fn_8014AEC8((void *) fn_801DFF08(subject))) != 0)
  {
    return 0;
  }
  if (((int) fn_801E85A4()) > 1)
  {
    fn_8014C72C(*((void **) (((char *) mgr) + 0xE4)), lbl_8055AE58);
    return 1;
  }
  entry = ((char *) mgr) + (subject * 0x1C);
  {
    void *u = *((void **) (((char *) mgr) + 0xE4));
    ((void (*)(void *)) (*((void ***) u))[7])(u);
  }
  opacity = fn_8014C8F8(*((float *) (entry + 4)), lbl_80562C1C, lbl_80562C20);
  f27 = lbl_8055AE40 / fn_80176A2C();
  f30 = f27 / lbl_80562C24;
  now = fn_801E7E18();
  f31 = fn_801429D0(lbl_80562C1C, f27 - (now - (*((float *) (entry + 8)))));
  if ((f31 > (f27 - f30)) || ((*((unsigned char *) (entry + 0xC))) == 0))
  {
    c1 = fn_80144C68(0xFF, 0x1E, 0x64, 0xF0);
    c2 = fn_80144C68(0xFF, 0xF0, 0x32, 0);
    fn_80147C50(c1, c2, opacity);
    fn_801DFEB8(*((void **) (((char *) mgr) + 0xE4)), base + 0xAC, -1, *((int *) (((char *) mgr) + 0xF0)));
    fn_801DFEB8(*((void **) (((char *) mgr) + 0xE4)), base + 0xB8, -1, *((int *) (((char *) mgr) + 0xF0)));
    {
      void *u = *((void **) (((char *) mgr) + 0xE4));
      obj1 = ((void *(*)(void *, void *)) (*((void ***) u))[4])(u, base + 0xC4);
      now = fn_801E7E18();
    }
    {
      void *u = *((void **) (((char *) mgr) + 0xE4));
      obj2 = ((void *(*)(void *, void *)) (*((void ***) u))[4])(u, base + 0xD4);
    }
    if ((obj1 != 0) && (obj2 != 0))
    {
      w = *((float *) (((char *) obj1) + 0x10));
      ratio = w / (w + (*((float *) (((char *) obj2) + 0x10))));
      r1 = fn_8014C8B4(lbl_80562C1C, ratio, lbl_80562C1C, lbl_80562C20, opacity);
      r2 = fn_8014C8B4(ratio, lbl_80562C20, lbl_80562C1C, lbl_80562C20, opacity);
      fn_8014C978(&m, obj1);
      m.w *= r1;
      m.h *= r1;
      ((void (*)(void *, int, int, float)) fn_801476D8)(&m, -1, *((int *) (((char *) mgr) + 0xF0)), m.w);
      fn_8014C7B4(&m, obj2);
      m.w *= r2;
      m.h *= r2;
      ((void (*)(void *, int, int, float)) fn_801476D8)(&m, -1, *((int *) (((char *) mgr) + 0xF0)), m.w);
    }
    fn_80144C68((unsigned char) ((int) (lbl_80562C28 * opacity)), 0xFF, 0xFF, 0xFF);
    if ((*((unsigned char *) (entry + 0xC))) == 0)
    {
      fn_8014C72C(*((void **) (((char *) mgr) + 0xE4)), base + 0xE4);
    }
    if (fn_80141F7C(f31) != 0)
    {
      rem = ((float (*)(float, float)) fn_801DFE94)((lbl_80562C2C * fn_801E7E18()) * fn_80176A2C(), lbl_80562C20);
      if (rem < lbl_80562C30)
      {
        v = fn_8014C8B4(lbl_80562C1C, lbl_80562C30, lbl_80562C1C, lbl_80562C20, rem);
      }
      else
      {
        v = fn_8014C8B4(lbl_80562C30, lbl_80562C20, lbl_80562C20, lbl_80562C1C, rem);
      }
      c3 = fn_80144C68((unsigned char) ((int) (lbl_80562C28 * v)), 0xFF, 0xFF, 0xFF);
      fn_801DFEB8(*((void **) (((char *) mgr) + 0xE4)), base + 0xF0, c3, *((int *) (((char *) mgr) + 0xEC)));
      fn_801DFEB8(*((void **) (((char *) mgr) + 0xE4)), base + 0xFC, c3, *((int *) (((char *) mgr) + 0xEC)));
      if ((rem > lbl_80562C34) && (rem < lbl_80562C38))
      {
        fn_801DFE50(*((void **) (((char *) mgr) + 0xE4)), (int) (base + 0x10C), *((int *) (((char *) mgr) + 0xEC)));
      }
      else
      {
        fn_801DFE50(*((void **) (((char *) mgr) + 0xE4)), (int) (base + 0x118), *((int *) (((char *) mgr) + 0xEC)));
      }
      ease = fn_80144BD8(v);
      {
        void *u = *((void **) (((char *) mgr) + 0xE4));
        obj3 = ((void *(*)(void *, void *)) (*((void ***) u))[4])(u, base + 0x124);
      }
      {
        void *u = *((void **) (((char *) mgr) + 0xE4));
        obj4 = ((void *(*)(void *, void *)) (*((void ***) u))[4])(u, base + 0x130);
      }
      if ((obj3 != 0) && (obj4 != 0))
      {
        fn_8014C978(m2, obj3);
        pair = fn_8014C770((const float *) (((char *) obj3) + 4), (const float *) (((char *) obj4) + 4), ease);
        fn_8014C75C(&pt.x, (const float *) (&pair));
        fn_801DFE44((int) m2, *((int *) (((char *) mgr) + 0xEC)));
      }
      fn_8014C72C(*((void **) (((char *) mgr) + 0xE4)), base + 0x13C);
    }
  }
  if ((fn_80141F7C(f31) == 0) && ((*((unsigned char *) (entry + 0xC))) != 0))
  {
    t = lbl_8055AE40 / fn_80176A2C();
    interp = fn_8014C8B4(t - f30, t - (t * lbl_80562C30), lbl_80562C1C, lbl_80562C20, f31);
    ease = fn_80144BD8(interp);
    {
      void *u = *((void **) (((char *) mgr) + 0xE4));
      obj5 = ((void *(*)(void *, void *)) (*((void ***) u))[3])(u, base + 0xE4);
    }
    {
      void *u = *((void **) (((char *) mgr) + 0xE4));
      obj6 = ((void *(*)(void *, void *)) (*((void ***) u))[3])(u, base + 0x148);
    }
    if ((obj5 != 0) && (obj6 != 0))
    {
      fn_801479A8(obj5, obj6, fn_80131234(base + 0x154), ease);
    }
  }
  __AXFXGetLfoSinTable_801769CC();
  return 1;
}
#pragma pop
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

/* One slip/skid instance: how far one vehicle's tyres have been sliding, and
 * the sound zone and screen effect that slip has reached.  fn_801DFF1C sets one
 * up, fn_801E02B0 clears them all and fn_801E0300 runs them once a frame. */
struct SlipRecord {
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

/* The manager built by fn_801DF6FC (the object in lbl_8055EA04) holds one slip
 * record per vehicle of lbl_804348E8, starting at its +4.  Its setters address
 * slot i as the object plus i * 0x1C, so a slot begins one word before the
 * record it holds: that word is the previous slot's zone. */
struct SlipSlot {
    int prevZone;             /* 0x00: the previous slot's SlipRecord.zone */
    struct SlipRecord record; /* 0x04 */
};

/* Start one vehicle's slip/skid record in the manager at lbl_8055EA04: the
 * effect begins at its minimum charge, unraised and inactive, its timers and
 * sound zone cleared, and its slip is seeded from the speed the vehicle already
 * has (20 * 2 * speed / 53.3333) so that a vehicle which is already sliding
 * reaches the sound zones fn_801E0300 tests without waiting for it to build up. */
void fn_801DFF1C(int index) {
    #define SLIP_SEED_SCALE lbl_80562C44 /* 20.0 */
    #define SLIP_SPEED_SCALE lbl_8055AE30 /* 2.0 */
    #define SLIP_SEED_LIMIT lbl_80562C48 /* 53.3333 */
    struct SlipSlot *slot = (struct SlipSlot *)((char *)lbl_8055EA04 + index * 0x1C);
    void *vehicle = ((void **)lbl_804348E8)[index];
    float longAgo = -100.0f;
    float zero = 0.0f;
    float minCharge = 0.15f;

    slot->record.charge = minCharge;
    slot->record.elapsed = zero;
    slot->record.timer = longAgo;
    slot->record.active = 0;
    slot->record.slip =
        SLIP_SEED_SCALE * (SLIP_SPEED_SCALE * PSVECMag((char *)vehicle + 0x118)) / SLIP_SEED_LIMIT;
    slot->record.started = 0;
    slot->record.zone = -1;
    #undef SLIP_SEED_SCALE
    #undef SLIP_SPEED_SCALE
    #undef SLIP_SEED_LIMIT
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

/* No-op stub. */
void fn_801E02A8(void) {

}

/* No-op stub. */
void fn_801E02AC(void) {

}

void fn_801E02B0(void *manager) {
    /* Clear every vehicle's slip/skid record: zero the charge, elapsed time and
       slip, clear the two flags, put the activation timer far in the past and
       set the sound zone to -1 (none). */
    float zero;
    float longAgo;
    struct SlipRecord *record;
    int i;
    longAgo = lbl_80562C40;
    zero = lbl_80562C1C;
    record = (struct SlipRecord *)((char *)manager + 4);
    i = 0;
    while (i < lbl_8055E4D0) {
        record->active = 0;
        i++;
        record->timer = longAgo;
        record->elapsed = zero;
        record->slip = zero;
        record->started = 0;
        record->zone = -1;
        record->charge = zero;
        record++;
    }
}

/* The record layout is in struct SlipRecord, above fn_801DFF1C; the array
 * starts at the manager's +4 and holds lbl_8055E4D0 records, one per vehicle
 * of lbl_804348E8. */

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
    struct SlipRecord *entry;
    int i, j, changed, muted;
    float fadeStep, chargeMin, chargeDecay, fullCharge, chargeMax, chargeStep, zero,
          slipScale, spinLimit, speedLimit, frameTime, time, sinceSlip, slipLimit,
          timerValue, timeDiv;
    if ((((int *)__AXFXGetLfoSinTable_801769CC())[1] & 0x4000) != 0) return;   /* session flags */
    vehicles = lbl_804348E8;
    zero = lbl_80562C1C; chargeStep = lbl_80562C4C; chargeMax = lbl_80562C68;
    entry = (struct SlipRecord *)((char *)manager + 4);
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
