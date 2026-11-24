// soundmgr.cpp — game sound manager (SoundManager, soundclass table).
// Recovered TU window 0x80207960..0x80208A18 (see docs/attribution_analysis.md):
// assert string "soundmgr.cpp", "SoundManager::*". Static-init thunk fn_80208A10
// (+ .ctors slot 0x802ED37C) remains in auto/text_80208A10_.c pending promotion.
extern void *fn_8012850C(signed long, const char *);
extern void fn_80207C50(void *, void *, signed long);
extern void fn_80127CF4(void *, const char *, signed long);
extern void *memset(void *, int, unsigned long);
extern char lbl_8033BEE8[];
extern char lbl_8033BDD8[];
extern char lbl_8033BDF0[];
extern float lbl_804891F8[];
extern float lbl_80489228[];
extern float lbl_80563228;
extern float lbl_8056322C;
extern unsigned long lbl_802F9E4C[];
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { int a, b, c; } W3;

#pragma cplusplus on
struct LoopItem_80207E70 {
    virtual int f0(int);
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
};
#pragma cplusplus reset

extern void fn_80208408(void *, void *);
extern void fn_80208858(void *, signed long, signed long);
extern signed long fn_80128668(void);
extern void* fn_802090B4(void);
extern signed long fn_802E317C(const char*, ...);
extern signed long fn_8026A344(signed long);
extern signed long fn_80206570(signed long);
extern signed long fn_8020835C(void *);
extern signed long fn_8020815C(void *);
extern int __cntlzw(unsigned int);

// Removed struct Data3 - it's causing register allocation issues

typedef struct SoundMgrObj {
    char pad0[0x10];
    signed long field_10; /* owning object index (Camera.subject = player truck) */
    char pad14[0x30];
    signed long field_44; /* sound class (SndClass) */
    char pad48[0x20];
    float field_68;       /* priority score; higher ranks first in the class list */
} SoundMgrObj;

typedef struct SoundMgr {
    char pad0[0x8];
    signed long lastUpdateMs; /* ms of the last update pass (fn_80207D40) */
    void** list;              /* +0x0C items the manager tracks */
    char pad10[0x4];
    signed long count;        /* +0x14 */
} SoundMgr;

/* The nine sound classes the manager keeps a list of, plus their count; the
 * names are the ones in its assert table (lbl_802F9DA0).  fn_802085F0 calls
 * ENGINE, TIRESQUEAL, CRASH, ENGINE_START and WIND the positional ones, and
 * fn_80207964 singles out UI. */
enum SndClass {
    SNDCLASS_UI = 0,
    SNDCLASS_COUNTDOWN = 1,
    SNDCLASS_ENGINE_2D = 2,
    SNDCLASS_ENGINE = 3,
    SNDCLASS_TIRESQUEAL = 4,
    SNDCLASS_CRASH = 5,
    SNDCLASS_ENGINE_START = 6,
    SNDCLASS_GEARCHANGE = 7,
    SNDCLASS_WIND = 8,
    SNDCLASS_COUNT = 9
};

#pragma dont_inline on
/* SoundManager construction hook.  The constructor fn_80207990 calls this between
 * clearing the manager's nine soundclass lists (+0x14) and allocating the
 * "SoundManager::snd_tab" array (+0x0C) the sounds are kept in; fn_80208404, called
 * where a soundclass list changes, is the same kind of hook.  The shipped build has
 * no body for either: whatever they did was compiled out, leaving an empty function
 * the call still reaches. */
void fn_80207960(void) {
	return;
}
#pragma dont_inline reset

/* Return nonzero only for the UI sound class; fn_80208858 uses this to flag
   UI voices separately from the positional sound classes. */
signed long fn_80207964(signed long sndClass) {
    switch (sndClass) {
    case SNDCLASS_UI:
        return 1;
    default:
        return 0;
    }
}

#pragma dont_inline on
void fn_80207980(void* entry) {
    /* Clear a two-word slot (a pointer plus a word) by zeroing both of its 32-bit halves. */
    *(signed long*)entry = 0;
    *((signed long*)entry + 1) = 0;
}
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_80207990(void *arg0, void *arg1) {
    struct Slot {
        void * volatile ptr;
        signed long value;
    };
    struct SoundObject {
        void *vtable;
        char field4;
        volatile char field5;
        char pad6[2];
        volatile signed long field8;
        void * volatile fieldC;
        signed long count;
        struct Slot slots[9];
        char cleared5C[0x30];
        signed long flag8C;
        void *callback;
        char tail94[0x84];
    };
    struct Callback {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual int f4();
    };
    struct SoundObject *object;
    struct Slot *end;
    struct Slot *slot;
    signed long i;
    signed long values[3];
    unsigned long *source;
    volatile float *vector1;
    volatile float *vector2;
    float zero;
    float one;
    object = (struct SoundObject *)arg0;
    object->vtable = lbl_8033BEE8;
    fn_80207980((void *)&object->fieldC);
    slot = &object->slots[0];
    end = &object->slots[9];
    do {
        fn_80207980(slot);
        slot++;
    } while (slot < end);
    fn_80207960();
    object->fieldC = fn_8012850C(0x3C0, lbl_8033BDD8);
    object->count = 0;
    object->callback = arg1;
    memset(object->cleared5C, 0, 0x30);
    source = lbl_802F9E4C;
    vector1 = lbl_804891F8;
    object->field5 = 0;
    vector2 = lbl_80489228;
    zero = 0.0f;
    one = 1.0f;
    vector1[1] = zero;
    vector1[0] = one;
    vector1[2] = zero;
    vector1[3] = zero;
    vector1[4] = one;
    vector1[5] = zero;
    vector1[6] = zero;
    vector1[7] = zero;
    vector1[8] = one;
    vector1[9] = zero;
    vector1[10] = zero;
    vector1[11] = zero;
    vector2[0] = zero;
    vector2[1] = zero;
    vector2[2] = zero;
    object->flag8C = 1;
    values[0] = *source++;
    values[1] = *source++;
    values[2] = *source++;
    i = 0;
    do {
        fn_80207C50(object, values, i);
        i += 1;
    } while (i < 4);
    memset(object->tail94, 0, 0x84);
    object->slots[0].ptr = object->fieldC;
    object->slots[1].ptr = object->fieldC;
    object->slots[2].ptr = object->fieldC;
    object->slots[3].ptr = object->fieldC;
    object->slots[4].ptr = object->fieldC;
    object->slots[5].ptr = object->fieldC;
    object->slots[6].ptr = object->fieldC;
    object->slots[7].ptr = object->fieldC;
    object->slots[8].ptr = object->fieldC;
    object->field8 = 0;
    fn_80127CF4(object, lbl_8033BDF0, 0);
    object->field4 = ((struct Callback *)arg1)->f4();
    return arg0;
}
#pragma cplusplus reset
#pragma pop

extern void fn_80207DE0(void*);
extern void fn_802E30C8(const char*, ...);
extern void fn_80128670(void);
extern void fn_80127E28(void*);
extern char lbl_8033BE08[];
extern char lbl_8033BEE8[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
/* Destructor for a sound-manager object: tear down active sounds/resources, log leaks, then optionally delete. */
/* SoundManager destructor: reset the vtable, destroy tracked items and log every leftover sound id, free the sound-id array at +0xC, call the callback's f7, deregister the object task, clear the active flag, and free the manager itself when shouldFree > 0. */ extern "C" void* fn_80207B60(void* self, signed long shouldFree) {
    struct Obj {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
    };
    signed long byteOffset;
    signed long index;
    void* ptr;
    if (self != 0) {
        *(void**)self = lbl_8033BEE8;
        fn_80207DE0(self);
        index = 0;
        byteOffset = 0;
        while (index < *(signed long*)((char*)self + 0x10)) {
            fn_802E30C8(lbl_8033BE08, *(signed long*)((char*)*(void***)((char*)self + 0xC) + byteOffset) + 0x37);
            byteOffset += 4;
            index++;
        }
        ptr = *(void**)((char*)self + 0xC);
        if (ptr != 0) {
            ((void (*)(void*))fn_80128670)(ptr);
            *(void**)((char*)self + 0xC) = 0;
        }
        ptr = *(void**)((char*)self + 0x90);
        *(signed long*)((char*)self + 0x10) = 0;
        if (ptr != 0) ((Obj*)ptr)->f7();
        fn_80127E28(self);
        *(char*)((char*)self + 4) = 0;
        if (shouldFree > 0) ((void (*)(void*))fn_80128668)(self);
    }
    return self;
}
#pragma cplusplus reset
#pragma pop
/* No-op member of soundmgr.cpp.  It sits between the SoundManager destructor
 * (fn_80207B60) and the small accessors of a sound object (fn_80207C50 seeds an
 * emitter slot, fn_80207C74 sets the +0x8C flag), next to two other empty stubs,
 * fn_80207C4C and fn_80207C7C: the shipped build compiled their bodies away, so
 * each is just a return.  Nothing in the recovered code calls this one. */
void fn_80207C48(void) {
	return;
}

/* Second of the three empty members of soundmgr.cpp in this stretch (see the note
 * on fn_80207C48): the shipped build compiled its body away, leaving a bare return,
 * and nothing in the recovered code calls it. */
void fn_80207C4C(void) {
	return;
}

#pragma scheduling invalid_target
#pragma push
#pragma opt_propagation off
void fn_80207C50(void* object, void* src, signed long slotIndex) {
    /* Seed one 0xC-byte slot of a sound-manager object (slots start at +0x5C)
     * with the three-word value at src; init calls this for all four slots. */
    signed long w2, w1, w0;
    signed long slotOffset = slotIndex * 0xC;
    volatile signed long *srcWords = (volatile signed long *)src;
    w0 = srcWords[0];
    w1 = srcWords[1];
    w2 = srcWords[2];
    object = (char*)object + slotOffset;
    *(signed long*)((char*)object + 0x5C) = w0;
    *(signed long*)((char*)object + 0x60) = w1;
    *(signed long*)((char*)object + 0x64) = w2;
}
#pragma pop
/* Set the flag at offset 0x8C of a sound object. */
void fn_80207C74(void *object, signed long value) {
    struct SoundObject {
        char pad[0x8C];
        signed long flag8C;
    };
    ((struct SoundObject *)object)->flag8C = value;
}

/* The last of the three empty members of this stretch of soundmgr.cpp (see the note
 * on fn_80207C48): the shipped build kept no body for it.  It sits right after the
 * setter of a sound object's +0x8C flag (fn_80207C74) and just before the manager's
 * per-frame pass fn_80207C80, and nothing in the recovered code calls it. */
void fn_80207C7C(void) {
	return;
}

void fn_80207E70(void* arg0);
void fn_80207F34(void *arg0);
typedef struct SlotLimits { signed long total; signed long lim[9]; signed long pad; } SlotLimits;

/* SoundManager per-frame update: run the audibility pass (fn_802067C8) over
 * every tracked sound, flush the queued mix values (fn_8020835C/fn_80207F34),
 * run each sound's own update (fn_80206824), then finish with
 * fn_8020815C/fn_80207E70. */
void fn_80207C80(void *soundMgr) {
    /* The manager's view of its tracked sounds (the full object is laid out in
     * fn_80207990): +0x0C is the array of sound ids, +0x10 its count, +0x5C the
     * emitter context handed to each sound, +0x8C a flag passed through to the
     * sound's update callback. */
    struct TrackedSounds {
        char pad0[0xC];
        int *soundIds;
        signed long soundCount;
        char pad14[0x48];
        char context[0x30];
        signed long updateArg;
    };
    struct TrackedSounds *mgr = (struct TrackedSounds *)soundMgr;
    signed long index;
    signed long byteOffset;
    byteOffset = 0;
    index = 0;
    while (index < mgr->soundCount) {
        fn_802067C8(*(int *)((char *)mgr->soundIds + byteOffset), (void *)mgr->context, mgr->updateArg);
        byteOffset += 4;
        ++index;
    }
    fn_8020835C(soundMgr);
    fn_80207F34(soundMgr);
    index = 0;
    byteOffset = 0;
    while (index < mgr->soundCount) {
        fn_80206824(*(int *)((char *)mgr->soundIds + byteOffset), (void *)mgr->context, mgr->updateArg);
        byteOffset += 4;
        ++index;
    }
    fn_8020815C(soundMgr);
    fn_80207E70(soundMgr);
}

#pragma dont_inline on
/* Whether the SoundManager may run its update this frame: only once more than 16
 * ms have gone by since its last pass.  fn_802E2C20 counts the ms since boot, and
 * the pass started here is stamped into the manager at +0x08. */
signed long fn_80207D40(SoundMgr* soundMgr) {
    signed long now;

    now = fn_802E2C20();
    if ((signed long)(now - soundMgr->lastUpdateMs) <= 0x10) {
        return 0;
    }
    soundMgr->lastUpdateMs = now;
    return 1;
}
#pragma dont_inline reset

#pragma cplusplus on
/* SoundManager's per-frame update, its first virtual method (vtable lbl_8033BEE8
 * +0x0C, just behind the destructor).  fn_80207D40 lets it run at most once every
 * 16 ms (the time of the last pass is kept at +0x08); it refreshes every sound the
 * manager tracks and then ticks the mixer device it plays on (+0x90, virtual
 * +0x20), handing it the manager's sound context at +0x5C -- the four
 * {id, matrix, vector} emitter slots fn_80207990 sets up at construction. */
extern "C" void SoundMgr_update(SoundMgr *soundMgr) {
    /* The mixer device of src/game/mixer.c (its vtable is documented there and in
     * fn_80208858); only the slots this file reaches through are declared. */
    struct SoundDevice {
        virtual void close(signed long);                                   /* +0x08 */
        virtual const char *name();                                        /* +0x0C */
        virtual void *resetState();                                        /* +0x10 */
        virtual void slot14();                                             /* +0x14 */
        virtual signed long enabled();                                     /* +0x18 */
        virtual signed long createSound(signed long, signed long, signed long); /* +0x1C */
        virtual void update(void *soundContext);                           /* +0x20 */
    };
    if (fn_80207D40(soundMgr) != 0) {
        fn_80207C80(soundMgr);
        ((struct SoundDevice *)*(void **)((char *)soundMgr + 0x90))->update((char *)soundMgr + 0x5C);
    }
}
#pragma cplusplus reset
extern void fn_80207C80(void*);
extern void* lbl_802F9DC8[];
extern char lbl_8033BE20[];
#pragma cplusplus on
/* SoundManager teardown helper: destroy each tracked loop item at +0x94 (count at +0x114) through its virtual f2(1), then clear every item slot and reset the count to zero. */ extern "C" void fn_80207DE0(void* soundMgr) {
    /* Clear/destroy all tracked item pointers at +0x94 (count at +0x114) via virtual f2(1). */
    class Item {
    public:
        virtual void f2(signed long);
    };
    void* mgr; void* slotCursor; signed long index; signed long zero;
    zero = 0; index = 0; mgr = soundMgr; slotCursor = mgr;
    while (index < *(signed long*)(((signed char*)mgr) + 0x114)) {
        void** itemSlot = (void**)((signed char*)slotCursor + 0x94);
        if (*itemSlot != 0) {
            Item* obj = (Item*)*itemSlot;
            obj->f2(1);
        }
        *itemSlot = (void*)zero;
        slotCursor = (void*)(((signed char*)slotCursor) + 4);
        index += 1;
    }
    *(signed long*)(((signed char*)mgr) + 0x114) = 0;
}
#pragma cplusplus reset
extern void* memmove(void*, const void*, unsigned long);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
/* Compacts the owner's pointer list at +0x94/+0x114 by removing entries whose
 * child object reports state 3 (f7()==3), deleting them (f0(1)) as it goes. */
/* Remove finished sounds from the manager's tracked-item list at +0x94 (count at +0x114). Each item holds its sound object at +0xC; the object's f7() reports its state, and state 3 means done, so the item is deleted via f0(1), the count is decremented and the remaining pointers are shifted down with memmove. */ extern "C" void fn_80207E70(void *soundMgr) {
    void *mgr = soundMgr;
    void *slotCursor = mgr;
    void *nextSlot = (char *)mgr + 0x98;
    void *holeSlot = (char *)mgr + 0x94;
    signed long index = 0;
    void *item;
    void *sound;
    signed long newCount;
    while (index < *(signed long *)((char *)mgr + 0x114)) {
        item = *(void **)((char *)slotCursor + 0x94);
        sound = *(void **)((char *)item + 0xC);
        if (((LoopItem_80207E70 *)sound)->f7() == 3) {
            item = *(void **)((char *)slotCursor + 0x94);
            if (item != 0)
                ((LoopItem_80207E70 *)item)->f0(1);
            newCount = *(signed long *)((char *)mgr + 0x114) - 1;
            *(signed long *)((char *)mgr + 0x114) = newCount;
            memmove(holeSlot, nextSlot, (unsigned long)(newCount - index) * 4);
        } else {
            slotCursor = (char *)slotCursor + 4;
            nextSlot = (char *)nextSlot + 4;
            holeSlot = (char *)holeSlot + 4;
            index++;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void fn_80207F34(void *arg0)
{
  signed long idx = (signed long) fn_802090B4();
  signed long off = idx * 0x2c;
  signed long rem = *((signed long *) (((char *) lbl_802F9DC8) + off));
  register char *obj = (char *) arg0;
  signed long counts[9];
  memset(counts, 0, 0x24);
  signed long sel[9];
  register char *rp;
  signed long row;
  signed long j;
  signed long take;
  signed long done;
  if (0 < rem)
  {
    rp = obj;
    for (row = 0; row < 9; row++)
    {
      counts[row] = 0;
      if (((*((unsigned char *) (obj + 5))) == 0) || (row == 0))
      {
        signed long n = *((signed long *) (rp + 0x18));
        for (j = 0; j < n; j++)
        {
          if ((*((unsigned char *) ((*((char **) ((*((char **) (rp + 0x14))) + (j * 4)))) + 0x18))) != 0)
          {
            counts[row]++;
          }
        }

      }
      rp += 8;
    }

  }
  memset(sel, 0, 0x24);
  {
    SlotLimits *entry = (SlotLimits *) (((char *) lbl_802F9DC8) + off);
    do
    {
      done = 1;
      row = 0;
      while ((rem > 0) && (row < 9))
      {
        signed long c = counts[row];
        if (c)
        {
          signed long lim = entry->lim[row];
          take = rem;
          if (lim < rem)
          {
            take = lim;
          }
          if (!(c > take))
          {
            sel[row] += c;
            rem -= counts[row];
            counts[row] = 0;
          }
          else
          {
            done = 0;
            rem -= take;
            counts[row] = counts[row] - sel[row];
            sel[row] = sel[row] + ((unsigned) take);
          }
        }
        ++row;
      }

    }
    while ((done == 0) && (rem > 0));
  }
  {
    char *p3 = obj + 0x14;
    for (row = 0; 0 < 9; row++)
    {
      register signed long n = *((signed long *) (p3 + 4));
      for (j = 0; ((int) 0) < n; j++)
      {
        char *item = *((char **) ((*((char **) p3)) + (j * 4)));
        if ((*((unsigned char *) (item + 0x18))) != 0)
        {
          if (sel[row] == 0)
          {
            item[0x48] = 1;
          }
          else
          {
            sel[row]--;
            item[0x48] = 0;
          }
        }
        else
        {
          item[0x48] = 1;
        }
      }

      p3 += 8;
    }

  }
}
#pragma scheduling on
extern "C" signed long fn_8020815C(void *arg0) {
#pragma scheduling on
    struct Obj {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual signed long check();
    };
    register signed long offset;
    register signed long limit;
    register signed long matches;
    register signed long i;
    void *entry;
    void *owner;

    limit = *(signed long *)((char *)lbl_802F9DC8 +
             (signed long)fn_802090B4() * 0x2C);
    matches = 0;
    i = 0;
    offset = 0;
    while (i < *(signed long *)((char *)arg0 + 0x10)) {
        entry = *(void **)((char *)*(void ***)((char *)arg0 + 0xC) + offset);
        owner = *(void **)((char *)entry + 0xC);
        if (((Obj *)owner)->check() == 1) {
            matches++;
        }
        offset += 4;
        i++;
    }
    if (matches > limit) {
        fn_802E317C(lbl_8033BE20, matches, limit);
    }
}

#pragma push
#pragma use_lmw_stmw off
/* Comparator for insertion-sorting positional sounds: returns nonzero when lhs ranks ahead of rhs by priority score (field_68). ENGINE/TIRESQUEAL voices of the same class owned by the camera's subject (the player's truck) are ranked first. */ extern "C" signed long fn_8020820C(SoundMgrObj* lhsObj, SoundMgrObj* rhsObj) {
    float rhsScore = rhsObj->field_68;
    float lhsScore = lhsObj->field_68;
    unsigned long lhsHigherScore = lhsScore > rhsScore;
    signed long sndClass = lhsObj->field_44;

    if (sndClass == rhsObj->field_44 && (unsigned long)(sndClass - 3) <= 1) {
        signed long subjectIdx = fn_8026A344(0);
        signed long rhsOwnedBySubject = subjectIdx == rhsObj->field_10;
        return subjectIdx == lhsObj->field_10 || (!rhsOwnedBySubject && lhsHigherScore);
    }
    return lhsHigherScore;
}

#pragma push
#pragma inline_depth(0)
extern "C" void fn_802082C0(void *soundMgr, void *classList) {
    register signed long slotByteOffset;
    register signed long *nextItem;
    register signed long *insertSlot;
    register signed long itemCount;
    register signed long *items;
    register signed long itemIndex;
    register signed long item;
    register signed long shiftIndex;

    /* Insertion-sort a sound class's object list (classList: items pointer at +0,
     * count at +4) in place, ranking each item with fn_8020820C.  soundMgr is
     * passed by the caller but unused here. */
    items = *(signed long **)classList;
    itemIndex = 1;
    itemCount = *(signed long *)((char *)classList + 4);
    slotByteOffset = 4;
    nextItem = (signed long *)((char *)items + 4);

    goto outer_check;
outer:
    item = *nextItem;
    shiftIndex = itemIndex;
    insertSlot = (signed long *)((unsigned long)items + (unsigned long)slotByteOffset);
    while (shiftIndex > 0 && fn_8020820C((SoundMgrObj *)item, (SoundMgrObj *)insertSlot[-1]) != 0) {
        *insertSlot = insertSlot[-1];
        shiftIndex--;
        insertSlot--;
    }
    items[shiftIndex] = item;
    nextItem++;
    itemIndex++;
    slotByteOffset += 4;
outer_check:
    if (itemIndex < itemCount)
        goto outer;
}
#pragma pop
extern char lbl_8033BE50[];
extern char lbl_8033BE70[];

/* One sound class in the manager's list table: nine of these at +0x14, one per
 * SndClass, all pointing into the single array at +0x0C whose size is +0x10
 * (fn_80208408 inserts into them and shifts the later ones, fn_80208620 removes). */
typedef struct SndClassList {
    SoundMgrObj *items;     /* the class's objects, in the shared array */
    signed long count;
} SndClassList;

/* fn_802E317C (abend.c) reports through the format and then ends the program. */
#define SNDMGR_INVALID_SOUNDCLASS_FMT lbl_8033BE50   /* "%s/%d: Invalid soundclass! (%s)" */
#define SNDMGR_FILE                   lbl_8033BE70   /* "soundmgr.cpp" */
#define SNDMGR_LINE_INVALID_SOUNDCLASS 0x265         /* its line in soundmgr.cpp */

#pragma cplusplus reset
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
/* Re-sort the five positional soundclass lists in place by priority (engine, tyre squeal, crash, engine start, wind); the 2D classes are left alone and an out-of-range class aborts with a fatal report. */ signed long fn_8020835C(void *soundMgr) {
    /* Re-sort the object list of every positional sound class - engine, tyre
     * squeal, crash, engine start and wind, the ones fn_802085F0 says may be
     * voiced in 3D - so the ones the comparator ranks highest come first; the
     * 2D classes (UI, countdown, 2D engine, gear change) keep their order.  A
     * class outside the manager's nine is fatal: its name, the file and this
     * line are reported and the program ends. */
    register SndClassList *classList;
    register signed long sndClass;

    sndClass = 0;
    classList = (SndClassList *)((char *)soundMgr + 0x14);
    do {
        switch (sndClass) {
        case SNDCLASS_UI:
        case SNDCLASS_COUNTDOWN:
        case SNDCLASS_ENGINE_2D:
        case SNDCLASS_GEARCHANGE:
            break;
        case SNDCLASS_ENGINE:
        case SNDCLASS_TIRESQUEAL:
        case SNDCLASS_CRASH:
        case SNDCLASS_ENGINE_START:
        case SNDCLASS_WIND:
            fn_802082C0(soundMgr, classList);
            break;
        default:
            fn_802E317C(SNDMGR_INVALID_SOUNDCLASS_FMT, SNDMGR_FILE,
                        SNDMGR_LINE_INVALID_SOUNDCLASS, fn_80206570(sndClass));
            break;
        }
        sndClass++;
        classList++;
    } while (sndClass < SNDCLASS_COUNT);
}
#pragma pop

#pragma pop
/* SoundManager list-change hook.  fn_80208408 calls this right after inserting a
 * sound object into its soundclass list, alongside bumping the list count; the
 * constructor hook fn_80207960 is the same kind of callback.  The shipped build
 * has no body for either: whatever they did was compiled out, leaving an empty
 * function the call still reaches. */
#pragma dont_inline on
extern "C" void fn_80208404(void) {
	return;
}
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
void fn_80208408(void *arg0, void *arg1)
{
    typedef struct { int *ptr; int count; } Ent;
    typedef struct { char pad0[0xc]; int *base; int total; Ent ents[9]; } Hdr;
    Hdr *h = (Hdr *)arg0;
    int idx = *(int *)((char *)arg1 + 0x44);
    int i;
    Ent *ent = &h->ents[idx];
    int *p = h->ents[idx].ptr;
    memmove(p + 1, p, (h->total - (p - h->base)) * 4);
    for (i = idx + 1; i < 9; i++) {
        h->ents[i].ptr++;
    }
    *(void **)p = arg1;
    ent->count++;
    h->total++;
    fn_80208404();
}
#pragma pop

/* Trampoline for the sound-object insert helper: tail-calls fn_80208408
 * (which inserts a sound object into its class list) with no adaptation. */
#pragma force_active on
extern "C" void fn_802085E8(void) {
	((void (*)(void))fn_80208408)();
}
#pragma force_active reset
/* Trampoline for the sound-play helper: tail-calls fn_80208858 (which plays a
 * sound on the manager's device) with no adaptation. */
extern "C" void fn_80208994(void) {
	((void (*)(void))fn_80208858)();
}

/* Second trampoline for the sound-play helper fn_80208858 (plays a sound on the
 * manager's device and hands back the created sound): tail-calls it with no
 * adaptation.  The sound-object initializer fn_80207218 in text_802062E8.cpp
 * calls this stub and keeps the returned handle at object+0xC; fn_80208994 is
 * the identical stub the other initializer uses. */
extern "C" void fn_80208998(void) {
	((void (*)(void))fn_80208858)();
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020899C(void* mgr, void* voice) {
    /* Release a sound voice during cleanup: invoke virtual slot 1 (+0xC) on the
       voice object in arg1; the sound-manager pointer in arg0 is unused. */
    struct Obj {
        virtual void v0();
        virtual void v1();
    };
    ((Obj*)voice)->v1();
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma cplusplus on
extern "C" void fn_802089B0(void* self) {
    class Obj {
    public:
        virtual void destroy(int);
    };
    /* If the sound object exists, invoke its virtual destroy with flag 1. */
    if (self == 0) {
        return;
    }
    ((Obj*)self)->destroy(1);
}
extern "C" signed long fn_802089D0(signed long object, signed long deleteFlag) {
    if ((object != 0) && (deleteFlag > 0)) {
        fn_80128668();
    }
    return object;
}
#pragma pop
/* Trampoline for the sound-object registration helper: tail-calls fn_80208408
 * (which inserts a sound object into its soundclass list on the manager) with no
 * adaptation.  The sound-object initializer in text_802062E8.cpp calls it through
 * this stub, passing the sSoundManager (lbl_8055ED80) instance and the object,
 * right after the object acquires its sound handle. */
extern "C" void fn_802085EC(void) {
	((void (*)(void))fn_80208408)();
}

/* Return nonzero for the positional sound classes (engine, tyre squeal, crash,
 * engine start, wind) that fn_80208858 may give a 3D voice. */
extern "C" signed long fn_802085F0(void* soundMgr, signed long sndClass) {
    switch (sndClass) {
        case SNDCLASS_ENGINE:
        case SNDCLASS_TIRESQUEAL:
        case SNDCLASS_CRASH:
        case SNDCLASS_ENGINE_START:
        case SNDCLASS_WIND:
            return 1;
        default:
            return 0;
    }
}

extern char lbl_8033BE80[];
#pragma push
#pragma scheduling invalid_target
void fn_80208620(void *arg0, void *arg1)
{
  typedef struct 
  {
    int *ptr;
    int count;
  } Ent;
  typedef struct 
  {
    char pad0[0xc];
    int *base;
    int total;
    Ent ents[9];
  } Hdr;
  Hdr *h = (Hdr *) arg0;
  int idx = *((int *) (((char *) arg1) + 0x44));
  int *found = 0;
  int i;
  int j;
  for (i = 0; 0 < h->ents[idx].count; i++)
  {
    if (((void *) h->ents[idx].ptr[i]) == arg1)
    {
      found = &h->ents[idx].ptr[i];
      break;
    }
  }

  if (found != 0)
  {
    h->total -= 1;
    h->ents[idx].count -= 1;
    memmove(found, found + 1, (h->total - (found - h->base)) * 4);
    for (j = idx + 1; j < 9; j++)
    {
      h->ents[j].ptr--;
    }

  }
  else
  {
    fn_802E317C(lbl_8033BE80, ((char *) arg1) + 0x37);
  }
}
#pragma pop
/* The sound device (mixer) this manager plays on lives at +0x90: it is the
 * object fn_80207990 was handed, one of the devices of the mixer list
 * (src/game/mixer.c).  Its vtable is +0x08 destroy, +0x0C getName,
 * +0x10 resetState, +0x14 slot14, +0x18 isEnabled, +0x1C createSound.
 * resetState clears the device's shared sound state and hands it back;
 * fn_80208858 reads it to decide how the new sound is to be voiced: */
struct SoundDevState {
    unsigned char active; /* +0x00 device already holds a live sound */
    signed long allow3D;  /* +0x04 positional classes may ask for a 3D voice */
    signed long allow2D;  /* +0x08 otherwise a 2D voice, else the plain one */
};

/* 3rd argument of the device's createSound: 0 asks for a 3D voice (the
 * manager's own message says so), 1 is what it retries with when that
 * fails, 2 is the voice used for sounds that need no positioning. */
enum SoundVoice { SOUND_VOICE_3D = 0, SOUND_VOICE_2D = 1, SOUND_VOICE_PLAIN = 2 };

extern char lbl_8033BEB0[];
#define STR_CREATE_3D_FAILED lbl_8033BEB0 /* "Creating 3d sound failed.  Supposed to be impossible." */

#pragma push
#pragma cplusplus on
#pragma inline_depth(0)
/* Play a sound on the manager's device: prefer a 3D voice for positional classes
 * the device allows, a 2D voice where supported, else a plain voice; retry as 2D
 * if 3D creation fails, and fall back to plain when the device is already active
 * and the class is not positional. */
extern "C" void fn_80208858(void *soundMgr, signed long soundName, signed long sndClass) {
    struct SoundDevice {
        virtual void slot8();
        virtual void slotC();
        virtual struct SoundDevState *resetState();
        virtual void slot14();
        virtual void slot18();
        virtual signed long createSound(signed long, signed long, signed long);
    };
    signed long positional = fn_802085F0(soundMgr, sndClass);
    signed long uiFlag = fn_80207964(sndClass);
    struct SoundDevState *state = (*(struct SoundDevice **)((char *)soundMgr + 0x90))->resetState();
    unsigned char active = state->active;
    signed long voice;
    signed long sound;
    if (active == 0 || positional != 0) {
        if (state->allow3D != 0 && positional != 0) {
            voice = SOUND_VOICE_3D;
        } else {
            voice = SOUND_VOICE_PLAIN;
            if (state->allow2D != 0) {
                voice = SOUND_VOICE_2D;
            }
        }
        sound = (*(struct SoundDevice **)((char *)soundMgr + 0x90))->createSound(soundName, voice, uiFlag);
        if (voice == SOUND_VOICE_3D && sound == 0) {
            fn_802E30C8(STR_CREATE_3D_FAILED);
            (*(struct SoundDevice **)((char *)soundMgr + 0x90))->createSound(soundName, SOUND_VOICE_2D, uiFlag);
        }
    } else {
        (*(struct SoundDevice **)((char *)soundMgr + 0x90))->createSound(soundName, SOUND_VOICE_PLAIN, uiFlag);
    }
}
#pragma pop
