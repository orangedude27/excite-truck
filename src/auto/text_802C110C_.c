#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FB28, lbl_8055FB2C, lbl_8055FB30, lbl_8055FB34, lbl_8055CFA0;
extern int lbl_8055FB40;
extern char lbl_804C0810[];
extern char lbl_804C0E10[];
extern f32 lbl_8055FB38;
extern f32 lbl_80564E50;
extern char lbl_8034AEF8[], lbl_8034AF04[];
extern int fn_801FB1F4(int);
extern int fn_8012850C(int, const char *);
extern void fn_801D0590(void *);
extern void fn_801D0800(void *);
extern void *memset(void *, int, unsigned int);
void fn_802C1928(void);
void fn_802C1A08(void);
extern void fn_80128670(int);
extern void fn_801D05B4(void *);
extern void fn_801D0824(void *);
extern void fn_802C1180(void *);
extern int Abend_Panic(const char *);
extern char lbl_8034AED0[];
#pragma cplusplus on
/* One of the level's tree objects: fn_802C143C gives it a tree class and
   fn_802C1550 reads back the parameters its model was saved with.  Slot 0x20
   resolves a parameter name to an int, or to the default it is given when the
   model has no such parameter. */
struct LevelObject {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual int getInt(const char *, int);
};
#pragma cplusplus reset

#define TREEHIT_STRUCTS
struct TreeClass {
    int firstTree;     /* 0x00 this class's tree indices, -1 until it has one */
    int lastTree;      /* 0x04 */
    char name[0x20];   /* 0x08 the "drop_model" object's name */
    u8 wobbles;        /* 0x28 clear when the model has "no_wobble" */
    u8 pad29[3];       /* 0x29 */
    f32 dropHeight;    /* 0x2C how far above the tree its drops spawn */
    void *modelObject; /* 0x30 the level's tree object */
    void **drops;      /* 0x34 the drop models, added by fn_802C1F8C */
    int dropCount;     /* 0x38 how many the model asks for */
    int dropsAdded;    /* 0x3C how many have been added */
    int eventId[8];    /* 0x40 "efx_event_id%d" per slot, -1 when it has none */
};                     /* 0x60 */

struct TreeObject {
    f32 matrix[9];     /* 0x00 rotation, swung about the hit axis by updateTreeHitSwings */
    f32 pos[3];        /* 0x24 Y goes 9000 below the ground once the tree is cut */
};

struct TreeHitRecord {
    int treeIndex;     /* 0x00 the tree this hit is waiting for */
    struct TreeObject *tree; /* 0x04 0 once fn_802C1180 gave the pose back */
    f32 matrix[9];     /* 0x08 the pose to give it */
    f32 pos[3];        /* 0x2C */
    f32 axis[3];       /* 0x38 the axis it is being swung about */
    f32 time;          /* 0x44 when it was hit */
};                     /* 0x48 */

#pragma scheduling invalid_target
void *fn_802C110C(int treeIndex) {
    /* Look up the tree class (0x60-byte TreeClass in lbl_804C0810) whose
       [firstTree, lastTree] range contains treeIndex. Panics if none matches. */
#define treeClassTable lbl_804C0810
#define treeClassCount lbl_8055FB28
#define Panic Abend_Panic
#define sTreeClassNotFoundFmt lbl_8034AED0
    char *entry = treeClassTable;
    int count = treeClassCount;
    for (; count > 0; --count, entry += 0x60) {
        if (treeIndex < *(int *)entry)
            continue;
        if (treeIndex <= *(int *)(entry + 4))
            return entry;
    }
    ((int (*)(const char *, ...))Panic)(sTreeClassNotFoundFmt, treeIndex);
    return 0;
#undef treeClassTable
#undef treeClassCount
#undef Panic
#undef sTreeClassNotFoundFmt
}
#pragma scheduling on
void fn_802C1180(void *node) {
    /* Copy this node's cached data to its target node, update the target table entry, and clear the link. */
    struct Pair { int a; int b; };
    int *src = (int *)node;
    int *dst = (int *)src[1];
    struct Pair *srcPairs = (struct Pair *)src;
    struct Pair *dstPairs = (struct Pair *)dst;
    if (dst == 0) {
        return;
    }
    dstPairs[0] = srcPairs[1];
    dstPairs[1] = srcPairs[2];
    dstPairs[2] = srcPairs[3];
    dstPairs[3] = srcPairs[4];
    dst[8] = src[10];
    *(struct Pair *)(dst + 9) = *(struct Pair *)(src + 11);
    dst[11] = src[13];
    ((int **)lbl_8055FB30)[src[0]] = (int *)src[1];
    src[1] = 0;
}
#pragma scheduling invalid_target
/* Return the next tree hit record slot, initializing it before use. */
void *fn_802C120C(void) {
    int slotIndex;
    void *record;
    slotIndex = lbl_8055FB34;
    record = (char *)&lbl_804C0E10 + slotIndex * 0x48;
    lbl_8055FB34 = (slotIndex + 1) % 8;
    fn_802C1180(record);
    return record;
}
void fn_802C126C(void) {
    /* RealName: none yet; what it does is InitTreeHit().  Start the treehit
     * subsystem for a new level: take the tree-handle block off the scratch
     * arena, allocate the "treehittree" tree list, put this subsystem's dispatch
     * object (and its second base subobject) on both dispatch lists, clear the
     * 16 tree classes to the "???INVALID???" name and the 8 queued hits, and
     * rewind the hit ring.  Counterpart of fn_802C13A4. */
#define treeHandleBase lbl_8055CFA0 /* arena block; handle - base = tree index */
#define treeList       lbl_8055FB30 /* the "treehittree" heap block */
#define treeCount      lbl_8055FB2C /* trees in treeList */
#define treeClassTable lbl_804C0810 /* the TreeClass table */
#define treeClassCount lbl_8055FB28 /* classes in it */
#define hitRecords     lbl_804C0E10 /* the TreeHitRecord ring */
#define hitIndex       lbl_8055FB34 /* next slot of that ring */
#define hitTime        lbl_8055FB38 /* time of the hit being applied */
#define listener       lbl_8055FB40 /* this subsystem's dispatch object */
#define arenaAlloc     fn_801FB1F4  /* take size bytes off the scratch arena */
#define namedAlloc     fn_8012850C  /* heap allocation tagged with a name */
#define treeListName   lbl_8034AEF8 /* "treehittree" */
#define invalidName    lbl_8034AF04 /* "???INVALID???" */
#define pushDispatch   fn_801D0590  /* push on the first dispatch list */
#define pushDispatch2  fn_801D0800  /* push on the second dispatch list */
#define fZero          lbl_80564E50 /* 0.0f */

    register struct TreeHitRecord *record;
    struct TreeClass *classEntry;
    unsigned char *nameSrc;
    int nameRoom;
    unsigned char *nameDst;
    int classIndex, recordIndex;
    char *listenerCheck, *listenerSubobject;

    treeCount = 0;
    treeClassCount = 0;
    treeHandleBase = arenaAlloc(0x1F40);
    hitTime = fZero;
    treeList = namedAlloc(0x7D00, treeListName);
    pushDispatch(&listener);
    listenerSubobject = (char *)&listener;
    listenerCheck = (char *)&listener;
    if ((int)listenerCheck != 0) /* the second base subobject, at +4 */
        listenerSubobject += 4;
    pushDispatch2(listenerSubobject);

    /* Every class starts empty and named "???INVALID???", with its name cut to
       the 0x20 bytes the class has room for. */
    classEntry = (struct TreeClass *)&treeClassTable;
    classIndex = 0;
    do {
        memset(classEntry, 0, sizeof(struct TreeClass));
        nameSrc = (unsigned char *)invalidName;
        nameDst = (unsigned char *)classEntry->name;
        nameRoom = 0x20;
        goto copy_name;
cut_name:
        if (--nameRoom > 0)
            goto copy_name;
        nameDst[-1] = 0;
        goto name_copied;
copy_name:
        if ((signed char)(*nameDst++ = *nameSrc++) != 0)
            goto cut_name;
name_copied:
        classIndex++;
        classEntry = (struct TreeClass *)((char *)classEntry +
                                          sizeof(struct TreeClass));
    } while (classIndex < 0x10);

    record = (struct TreeHitRecord *)&hitRecords;
    recordIndex = 0;
    do {
        memset(record, 0, sizeof(struct TreeHitRecord));
        recordIndex++;
        record = (struct TreeHitRecord *)((char *)record +
                                          sizeof(struct TreeHitRecord));
    } while (recordIndex < 8);
    hitIndex = 0;
    fn_802C1928(); /* hand every queued hit back and clear the recent-hit table */
    fn_802C1A08();

#undef treeHandleBase
#undef treeList
#undef treeCount
#undef treeClassTable
#undef treeClassCount
#undef hitRecords
#undef hitIndex
#undef hitTime
#undef listener
#undef arenaAlloc
#undef namedAlloc
#undef treeListName
#undef invalidName
#undef pushDispatch
#undef pushDispatch2
#undef fZero
}
#pragma scheduling invalid_target
void fn_802C13A4(void) {
    /* Shut down the treehit subsystem (counterpart to fn_802C126C): unregister
     * the listener object lbl_8055FB40 (and its second base subobject at +4)
     * from both dispatch lists, free each TreeClass's drop-model array (+0x34)
     * across lbl_804C0810, free the tree list lbl_8055FB30, and clear the counts. */
    char *classEntry;
    int listenerCheck;
    char *listenerSubobject;
    int classIndex;
    int dropsBuffer;

    fn_801D05B4(&lbl_8055FB40);
    listenerCheck = (int)&lbl_8055FB40;
    listenerSubobject = (char *)&lbl_8055FB40;
    if (listenerCheck != 0)
        listenerSubobject += 4;
    fn_801D0824(listenerSubobject);

    classEntry = lbl_804C0810;
    classIndex = 0;
    goto check;
loop:
    dropsBuffer = *(int *)(classEntry + 0x34);
    if (dropsBuffer != 0)
        fn_80128670(dropsBuffer);
    classEntry += sizeof(struct TreeClass);
    classIndex += 1;
check:
    if (classIndex < lbl_8055FB28)
        goto loop;

    fn_80128670(lbl_8055FB30);
    lbl_8055FB30 = 0;
    lbl_8055FB2C = 0;
    lbl_8055FB28 = 0;
}
extern int fn_801345D8(char *, int, const char *, ...);
extern char lbl_8034AF14[];

extern int lbl_8055FB28;
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
/* Add a tree class (struct TreeClass below, the lbl_804C0810 table) for one of
   the level's tree objects and return its index; lbl_8055FB28 counts the
   classes.  The class has no trees yet (-1) and wobbles until fn_802C1550 reads
   the object's parameters, and its eight "efx_event_id%d" effect events are
   looked up here - the object answers -1 for the ones its model does not have. */
extern "C" int fn_802C143C(void *modelObject) {
    char paramName[0x20];
    int index;
    int *entry;
    u32 i;
    int next;
    index = lbl_8055FB28;
    entry = (int *)((char *)&lbl_804C0810 + index * 0x60);
    entry[0] = -1;                      /* TreeClass::firstTree */
    next = index + 1;
    lbl_8055FB28 = next;
    *((u8 *)entry + 0x28) = 1;          /* TreeClass::wobbles */
    entry[0x30 / 4] = (int)modelObject; /* TreeClass::modelObject */
    i = 0;
    do {
        if (modelObject != NULL) {
            fn_801345D8(paramName, 0x20, lbl_8034AF14, i + 1); /* "efx_event_id%d" */
            entry[0x40 / 4] = ((LevelObject *)modelObject)->getInt(paramName, -1);
        } else {
            entry[0x40 / 4] = -1;
        }
        i++;
        entry++;
    } while (i < 8);
    return index;
}
#pragma cplusplus off
int fn_802C1500(int tree, int classIndex) {
#pragma scheduling invalid_target
#define treeClassTable lbl_804C0810 /* the TreeClass table */
#define treeList       lbl_8055FB30 /* the "treehittree" heap block */
#define treeCount      lbl_8055FB2C /* trees in treeList */
#define treeHandleBase lbl_8055CFA0 /* arena block; handle - base = tree index */
    /* Append a tree to the treehit list, add its index to the given class's
       [firstTree, lastTree] range, and return its tree handle. */
    int index = treeCount;
    struct TreeClass *table = (struct TreeClass *)treeClassTable;
    int off = classIndex * 0x60;
    treeCount = index + 1;
    ((int *)treeList)[index] = tree;
    if (((struct TreeClass *)((char *)table + off))->firstTree < 0) {
        ((struct TreeClass *)((char *)table + off))->firstTree = index;
        ((struct TreeClass *)((char *)table + off))->lastTree = index;
    } else {
        ((struct TreeClass *)((char *)table + off))->lastTree = index;
    }
    return treeHandleBase + index;
#undef treeClassTable
#undef treeList
#undef treeCount
#undef treeHandleBase
}
#pragma cplusplus on
extern char lbl_8034AED0[];
extern f32 lbl_80564E54, lbl_80564E50, lbl_80564E58;
extern char lbl_8055CFA4[], lbl_8055CFAC[], lbl_8055CFB8[], lbl_8055CFC0[];
__declspec(section ".sdata") extern char lbl_8055CFA4[];
__declspec(section ".sdata") extern char lbl_8055CFAC[];
__declspec(section ".sdata") extern char lbl_8055CFB8[];
__declspec(section ".sdata") extern char lbl_8055CFC0[];
extern void fn_801FA7F4(int, f32 *, void *);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma paired off
extern "C" void fn_802C1550(void) {
    struct Dispatch {
        virtual void u1();
        virtual void u0();
        virtual void u2();
        virtual char *getResource(const char *);
        virtual void u4();
        virtual int getCount(const char *);
        virtual void u6();
        virtual float getValue(const char *);
        virtual void u8();
        virtual void u9();
        virtual int hasFlag(const char *, int);
        virtual void u11();
        virtual void u12();
        virtual void u13();
        virtual void u15();
        virtual void u14();
        virtual void u16();
        virtual void u17();
        virtual void u19();
        virtual void u18();
        virtual void u20();
        virtual Dispatch *find(const char *);
    };
    register char *entry = lbl_804C0810;
    int outer = 0;
    register unsigned long zero = 0;
    register f32 depth;
    f32 blank;
    register f32 diagonal;
    f32 pos[12];
    diagonal = lbl_80564E54;
    blank = lbl_80564E50;
    depth = lbl_80564E58;
    while (outer < lbl_8055FB28) {
        int count;
        char *index;
        char *name;
        entry[0x28] = ((Dispatch *)*(void **)(entry + (int)0x30))->hasFlag(lbl_8034AED0 + 0x54, zero) == zero;
        if (Dispatch *obj = ((Dispatch *)*(void **)(entry + 0x30))->find(lbl_8034AED0 + 0x60)) {
            *(f32 *)(entry + 0x2c) = obj->getValue(lbl_8034AED0 + 0x6c);
            index = obj->getResource(lbl_8055CFA4);
            count = obj->getCount(lbl_8055CFAC);
            *(int *)(entry + 0x38) = count;
            *(int *)(entry + 0x3c) = zero;
            {
                register void *buffer = (void *)fn_8012850C(count * 4, lbl_8055CFB8);
                *(void **)(entry + (unsigned)0x34) = buffer;
                memset(buffer, zero, *(int *)(entry + 0x38) * 4);
            }
            name = ((Dispatch *)*(void **)(entry + 0x30))->getResource(lbl_8055CFC0);
            {
                char *source = name;
                char c;
                int remaining = 0x20;
                char *destination = entry + 8;
                goto copy_body;
            copy_check:
                remaining -= 1;
                if (remaining > 0)
                    goto copy_body;
                destination[-1] = zero;
                goto copy_done;
            copy_body:
                c = *source++;
                *destination++ = c;
                if ((signed char)c != 0)
                    goto copy_check;
            copy_done:;
            }
            {
                int item = 0;
                if (0 >= count)
                    goto next_entry;
                for (; item < count; item++) {
                    pos[0] = diagonal;
                    pos[1] = blank; pos[2] = blank;
                    pos[3] = blank; pos[4] = diagonal;
                    pos[5] = blank; pos[6] = blank;
                    pos[7] = blank; pos[8] = diagonal;
                    pos[9] = blank; pos[11] = blank; pos[10] = depth;
                    fn_801FA7F4((int)index, pos, *(void **)(entry + 0x30));
                }
            }
        }
    next_entry:
        entry += 0x60;
        outer++;
    }
}
#pragma pop
extern "C" f64 sin(f32);
extern "C" void fn_8022FF10(void *, void *);
extern "C" void fn_80015B20(void *, void *, void *);
extern f32 lbl_80564E50, lbl_80564E54, lbl_80564E5C, lbl_80564E60;
extern f32 lbl_80564E64, lbl_80564E68, lbl_80564E6C;
#pragma push
#pragma processor 750
#pragma paired_single off
extern "C" void updateTreeHitSwings(float time)
{
  struct M33 { f32 m[9]; };
  struct V3 { f32 x, y, z; };
  struct Pose { struct M33 m; struct V3 p; };
  struct Scratch
  {
    f32 vec[3];
    f32 rot[3];
    char padding[0x18];
    struct Pose pose;
  };
  /* Tree-hit swing: store `time` as the hit time, then walk the 8 queued
   * TreeHitRecords. While a hit is young (lower <= age < upper) it swings the
   * tree about its hit axis by a damped, sine-shaped angle; once it ages out
   * the cached pose is handed back to the tree (fn_802C1180). */
  register f32 scale;
  register f32 baseAmplitude;
  register f32 decaySlope;
  register f32 swingFrequency;
  register f32 minAge;
  register f32 ageUpper;
  register f32 ageLower;
  struct TreeHitRecord *hit;
  int hitIndex;
  lbl_8055FB38 = time;
  minAge = lbl_80564E50;
  swingFrequency = lbl_80564E64;
  decaySlope = lbl_80564E68;
  baseAmplitude = lbl_80564E54;
  scale = lbl_80564E6C;
  ageUpper = lbl_80564E60;
  ageLower = lbl_80564E5C;
  hit = (struct TreeHitRecord *)lbl_804C0E10;
  hitIndex = 0;
  do
  {
    if (hit->tree != 0)
    {
      f32 age = lbl_8055FB38 - hit->time;
      if ((age >= ageLower) && (age < ageUpper))
      {
        struct Scratch s;
        f32 amplitude;
        f32 sine;
        f32 swingAngle;
        s.pose = *(struct Pose *)hit->matrix;
        sine = (f32)sin(swingFrequency * ((age > minAge) ? age : minAge));
        amplitude = baseAmplitude - age * decaySlope;
        swingAngle = amplitude * (scale * sine);
        s.vec[0] = hit->axis[0] * swingAngle;
        s.vec[1] = hit->axis[1] * swingAngle;
        s.vec[2] = hit->axis[2] * swingAngle;
        fn_8022FF10(s.rot, s.vec);
        fn_80015B20(&s.pose, &s.pose, s.rot);
        *(struct Pose *)hit->tree = s.pose;
      }
      else
      {
        fn_802C1180(hit);
      }
    }
    hitIndex = hitIndex + 1;
    hit = hit + 1;
  }
  while (hitIndex < 8);
}
#pragma pop
extern f32 lbl_804C1050[16];
extern f32 lbl_80564E58;
extern f32 lbl_80564E70;
extern f32 lbl_80564E74;
extern void fn_802BDFF4(void *, int);
#pragma push
#pragma processor 750
/* Manager tick: reset the eight score slots, flush the eight pending nodes
 * into the object table, then adjust and flag every registered object whose
 * score is below the threshold. */
void fn_802C1928(void) {
    f32 *scores = (f32 *)((char *)&lbl_804C1050 + 4);
    scores[0] = -1000.0f;
    scores[2] = -1000.0f;
    scores[4] = -1000.0f;
    scores[6] = -1000.0f;
    scores[8] = -1000.0f;
    scores[10] = -1000.0f;
    scores[12] = -1000.0f;
    scores[14] = -1000.0f;
    char *pendingNode = (char *)&lbl_804C0E10;
    int slot = 0;
    do {
        fn_802C1180(pendingNode);
        slot++;
        pendingNode += 0x48;
    } while (slot < 8);
    {
        register f32 delta = lbl_80564E74;
        register int index = 0;
        register f32 threshold = lbl_80564E70;
        register int byteOffset = 0;
        goto check;
    loop:
        {
            int *object = (int *)*(int *)((char *)(int *)lbl_8055FB30 + byteOffset);
            if (*(f32 *)((char *)object + 0x28) < threshold) {
                *(f32 *)((char *)object + 0x28) -= delta;
                ((void (*)(int *, int))fn_802BDFF4)(
                    (int *)*(int *)((char *)(int *)lbl_8055FB30 + byteOffset), 1);
            }
        }
        byteOffset += 4;
        index++;
    check:
        if (index < lbl_8055FB2C)
            goto loop;
    }
}
#pragma pop
/* Empty no-op reset hook: invoked by tree-hit init (fn_802C126C) and by the
 * per-frame shutdown pass (fn_801E8CE4), but currently has no behaviour. */
void fn_802C1A08(void) {}

/* ---- treehit: the trees the trucks drive into ------------------------------
 * lbl_804C0810  the tree classes (fn_802C143C adds one per level object,
 *               fn_802C1550 fills them in from the object's parameters,
 *               count lbl_8055FB28, looked up by tree index in fn_802C110C)
 * lbl_8055FB30  the tree list (heap block "treehittree", lbl_8034AEF8),
 *               count lbl_8055FB2C; fn_802C1500 appends a tree to it
 * lbl_8055CFA0  base of the tree handles fn_801500 hands out: handle - base is
 *               the index in the tree list, which is what the level objects
 *               report when something hits them
 * lbl_804C0E10  the eight queued hits (ring, next slot lbl_8055FB34); fn_802C1C34
 *               queues one, fn_802C1180 hands its pose back to the tree and
 *               updateTreeHitSwings swings the tree about the hit axis (time lbl_8055FB38)
 * lbl_80564E50 / lbl_80564E54  0.0f / 1.0f
 * lbl_80564E70  -2000.0f: a tree whose Y is under it has been cut
 * lbl_80564E74  -9000.0f: how far below a cut tree is dropped
 */
#ifndef TREEHIT_STRUCTS
#define TREEHIT_STRUCTS
struct TreeClass {
    int firstTree;     /* 0x00 this class's tree indices, -1 until it has one */
    int lastTree;      /* 0x04 */
    char name[0x20];   /* 0x08 the "drop_model" object's name */
    u8 wobbles;        /* 0x28 clear when the model has "no_wobble" */
    u8 pad29[3];       /* 0x29 */
    f32 dropHeight;    /* 0x2C how far above the tree its drops spawn */
    void *modelObject; /* 0x30 the level's tree object */
    void **drops;      /* 0x34 the drop models, added by fn_802C1F8C */
    int dropCount;     /* 0x38 how many the model asks for */
    int dropsAdded;    /* 0x3C how many have been added */
    int eventId[8];    /* 0x40 "efx_event_id%d" per slot, -1 when it has none */
};                     /* 0x60 */

struct TreeObject {
    f32 matrix[9];     /* 0x00 rotation, swung about the hit axis by updateTreeHitSwings */
    f32 pos[3];        /* 0x24 Y goes 9000 below the ground once the tree is cut */
};

struct TreeHitRecord {
    int treeIndex;     /* 0x00 the tree this hit is waiting for */
    struct TreeObject *tree; /* 0x04 0 once fn_802C1180 gave the pose back */
    f32 matrix[9];     /* 0x08 the pose to give it */
    f32 pos[3];        /* 0x2C */
    f32 axis[3];       /* 0x38 the axis it is being swung about */
    f32 time;          /* 0x44 when it was hit */
};                     /* 0x48 */
#endif

struct TreeHitEvent {  /* the 0x20-byte payload of efx event 10, fn_801796EC */
    f32 pos[3];        /* 0x00 where the tree was hit */
    f32 velocity[3];   /* 0x0C the player's velocity */
    s16 angle;         /* 0x18 the player's heading */
    u8 pad1A[2];       /* 0x1A */
    int eventId;       /* 0x1C the class slot's "efx_event_id" */
};                     /* 0x20 */

struct PlayerObject {  /* one of the eight players of lbl_80430830, getRegisteredObject */
    u8 pad0[0x6C];
    s16 heading;       /* 0x6C */
    u8 pad6E[0x118 - 0x6E];
    f32 velocity[3];   /* 0x118 */
};

#define TREE_CLASS_EVENT_ID 0x40 /* offsetof(struct TreeClass, eventId) */

extern void *getRegisteredObject(int);
extern void fn_801796EC(int, void *, int);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma paired off
/* Resolves queued hit poses for their trees, then cuts the hit tree: spawns one drop event per class slot with event id, drops it below the world, and releases the hit's tree reference. */ extern "C" void cutTreeOnHit(void **hit, int player) {
    /* The hit's tree reference: handle at vtable+0x24, cleared at vtable+0x18. */
    struct Dispatch {
        virtual void unk0();
        virtual void unk1();
        virtual void unk2();
        virtual void unk3();
        virtual void setTree(int);
        virtual void unk5();
        virtual void unk6();
        virtual int getTreeHandle();
    };
    struct TreeHitEvent event;
    int hitIndex;
    register char *base;
    register int treeIndex;
    int *classEntry;
    struct TreeObject *tree;
    register f32 lift;
    f32 coord;
    f32 z;
    /* Hand back the pose of every queued hit waiting for this tree. */
    base = lbl_804C0E10;
    for (treeIndex = 0; treeIndex < 8; treeIndex++, base += sizeof(struct TreeHitRecord)) {
        hitIndex = ((Dispatch *)hit)->getTreeHandle() - lbl_8055CFA0;
        if (((struct TreeHitRecord *)base)->tree != 0 &&
            ((struct TreeHitRecord *)base)->treeIndex == hitIndex)
            fn_802C1180(base);
    }
    treeIndex = ((Dispatch *)hit)->getTreeHandle() - lbl_8055CFA0;
    if (treeIndex < 0)
        goto done;
    if (treeIndex >= lbl_8055FB2C)
        goto done;
    classEntry = (int *)fn_802C110C(treeIndex); /* the tree's class */
    base = (char *)lbl_8055FB30;                /* the tree list */
    tree = (struct TreeObject *)*(void **)(base + treeIndex * 4);
    if (tree->pos[1] > lbl_80564E70) { /* still above the ground, so: cut it */
        struct PlayerObject *hitter = (struct PlayerObject *)getRegisteredObject(player);
        event.velocity[0] = hitter->velocity[0];
        event.velocity[1] = hitter->velocity[1];
        event.velocity[2] = hitter->velocity[2];
        event.angle = hitter->heading;
        lift = lbl_80564E54; /* spawn the drops 1.0 above the hit point */
        {
            u32 i;
            /* One event per class slot that has an "efx_event_id%d"; classEntry
             * walks the class a word at a time, so the slot adds to it. */
            for (i = 0; i < 8; i++, classEntry++) {
                if (classEntry[TREE_CLASS_EVENT_ID / 4] >= 0) {
                    volatile f32 *pos = event.pos;
                    tree = (struct TreeObject *)*(void **)(base + treeIndex * 4);
                    coord = tree->pos[0];
                    pos[0] = coord;
                    coord = tree->pos[1];
                    pos[1] = coord;
                    coord += lift;
                    z = tree->pos[2];
                    pos[2] = z;
                    pos[1] = coord;
                    event.eventId = classEntry[TREE_CLASS_EVENT_ID / 4];
                    fn_801796EC(10, &event, 0x20);
                }
            }
        }
        tree = (struct TreeObject *)*(void **)(base + treeIndex * 4);
        tree->pos[1] += lbl_80564E74; /* drop it out of the world */
        ((Dispatch *)hit)->setTree(0); /* the hit no longer holds the tree */
        fn_802BDFF4((struct TreeObject *)*(void **)(base + treeIndex * 4), 0);
    }
done:
    ;
}
#pragma pop
typedef struct { int a, b; } Pair802C;
