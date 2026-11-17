#include <types.h>

/* Competitor table (see CompetitorTable below), inside the static race block
   that starts at lbl_80435740. */
extern int lbl_80435780[];
extern float fn_801AF9EC(int, float *);
extern void *fn_801AF8D0(int);
extern void fn_801AFABC();
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern char lbl_80558DC4[];
extern float lbl_8055E630;
extern float lbl_8056255C;
  extern float lbl_80562558;
  extern float lbl_80562560;
extern float lbl_80562570;
extern int lbl_8055E628;
extern signed char lbl_8055E635;
  extern int lbl_8055E62C;
  extern double lbl_80562568;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80435740[];
extern const char lbl_80335980[];
extern const char lbl_80335990[];
extern const char lbl_803359AC[];
extern const char lbl_803359BC[];
extern const char lbl_803359CC[];
extern int fn_8012850C(int, const char *);
extern int fn_802794AC(int, void *);
extern float lbl_80562574;
extern void fn_801AFA20(void);
/* End-of-race bookkeeping.  One static block at lbl_80435740 holds
 *   +0x000  one { score, spare } f32 pair per competitor (Pair8)
 *   +0x040  lbl_80435780: the competitor table (CompetitorTable)
 * and it points at the tables the race allocates on the heap:
 *   lbl_8055E620 "CarLapTable"      8 slots, a LapResultTable (0x1F5 laps) each
 *   lbl_8055E624 "RaceResultTable"  { RaceResult *records; s32 count; }
 *   lbl_8055E628 "RecordMgr"        handle the stubbed event callbacks take.
 */
typedef struct {
    unsigned char b[0x60];
} Blob60;
typedef struct {              /* one competitor of the race, 0x78 bytes */
    int id;                   /* 0x00 competitor id; 0x50 is one that sets laps */
    Blob60 b;
    int f64, f68, f6c;
    unsigned char f70;        /* 0x70 & 3: state; 0 = still to be placed */
    int f74;
} Ent78;
typedef struct {              /* what lbl_80435780 points at */
    Ent78 entry[8];
    s32 count;                /* 0x3C0 competitors in the table */
    s32 order[8];             /* 0x3C8 entry indices, qsort'ed by placing */
} CompetitorTable;
typedef struct {              /* one RaceResultTable record, 0x1C bytes */
    f32 time;                 /* 0x00 fn_801AE894 turns this into the speed */
    f32 speed;                /* 0x04 */
    f32 lapTime;              /* 0x08 the value the placing is sorted by */
    s16 rank;                 /* 0x0C placing; 1 = first, 0 = unplaced */
    u16 flags;                /* 0x0E & 1 took part, & 8 disqualified */
    s16 points;               /* 0x10 for the placing (fn_801AE610, stubbed) */
    s16 bonus;                /* 0x12 */
    s16 score;                /* 0x14 shared out by fn_801AEBD0 */
    s16 f16;                  /* 0x16 first sort key of fn_801AEAA4 */
    s16 f18;
    s16 carId;                /* 0x1A racer the record belongs to (fn_801B3050) */
} RaceResult;
typedef struct {
    char pad[0x20];
    Ent78 e[8];
} Src;
typedef struct {
    float a;
    float b;
} Pair8;

int fn_801AE618(int arg0);
#pragma dont_inline on
/* True for competitor id 0x50, the one racer the end-of-race tables keep lap
   times for: fn_801AEF28 gives that competitor a CarLapTable slot and
   fn_801AE79C looks its placing up.  (Not renameable yet: keep fn_801AE600.) */
int fn_801AE600(int competitorId) {
    return competitorId == 0x50;
}
#pragma dont_inline reset

short fn_801AE610(int arg0, short arg1) {
    return 0;
}

#pragma dont_inline on
int fn_801AE618(int arg0) {
    return arg0 & 1;
}
#pragma dont_inline reset

#pragma dont_inline on
/* Test bit 0 of the 16-bit flag field at offset +0xE of a 0x1C-byte entry:
 * fn_801AE618 masks off the low bit, so this marks the entry as active/valid. */
int fn_801AE620(void *entry) {
    return fn_801AE618(*(unsigned short *)((char *)entry + 0xE));
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801AE628(int arg0) {
    struct {
        int count;
        int indices[8];
        int max_val;
    } data;
    register int offset;
    register int i;
    register char *entry;
    register int k;
    data.max_val = -1;
    data.count = 0;
    for (i = 0, offset = 0; i < lbl_80435780[0x3C0 / 4]; offset += 0x1C, i++) {
        entry = (char *)*lbl_8055E624 + offset;
        if (fn_801AE620(entry) != 0) {
            if (*(short *)(entry + 0x14) >= data.max_val) {
                if (*(short *)(entry + 0x14) > data.max_val) {
                    data.count = 0;
                }
                data.indices[data.count++] = i;
                data.max_val = *(short *)(entry + 0x14);
            }
        }
    }
    {
        char *e2;
        int off;
        int j;
        for (j = 0, off = 0; j < lbl_80435780[0x3C0 / 4]; off += 0x1C, j++) {
            e2 = (char *)*lbl_8055E624 + off;
            if (fn_801AE620(e2) != 0) {
                *(short *)(e2 + 0x10) = fn_801AE610(arg0, *(short *)(e2 + 0xC));
                *(short *)(e2 + 0x12) = 0;
                if (*(short *)(e2 + 0x14) != 0) {
                    *(short *)(e2 + 0x12) += 5;
                }
                for (k = 0; k < data.count; k++) {
                    if (j == data.indices[k]) {
                        *(short *)(e2 + 0x12) += 5;
                    }
                }
            }
        }
    }
}
/* Return the placement state (low 2 bits of byte 0x70) of a race competitor; 0 means still unplaced. */
int fn_801AE790(void *entry) {
    return ((Ent78 *)entry)->f70 & 3;
}
#pragma dont_inline reset

#pragma scheduling invalid_target
/* End of the race-result pass: in mode 2 with a full grid, look up the placing
   of the last competitor that sets lap times (id 0x50) and is still unplaced,
   and hand it to the RecordMgr callback (fn_801AFABC, stubbed out here).  The
   competitor table holds 8 records, so the count > 10 test never lets it run. */
void fn_801AE79C(s32 mode) {
    register s32 enabled;
    register CompetitorTable *table;
    register Ent78 *competitor;
    s16 rank;
    s32 index;

    enabled = 0;
    if (mode == 2 && ((CompetitorTable *)lbl_80435780)->count > 10)
        enabled = 1;
    if (enabled != 0) {
        competitor = (Ent78 *)lbl_80435780;
        table = (CompetitorTable *)competitor;
        rank = 0;
        index = 0;
        for (; index < table->count; competitor++, index++) {
            if (competitor->id == 0x50 && fn_801AE790(competitor) == 0) {
                RaceResult *result = (RaceResult *)fn_801AF8D0(index);
                if (result != 0)
                    rank = result->rank;
            }
        }
        if (rank >= 1)
            fn_801AFABC(lbl_8055E628, rank);
    }
}
#pragma scheduling on
extern int lbl_8055E62C;
extern float lbl_8056255C;
extern double lbl_80562568;
/* Mark a race-result flags word as "took part" (0x1); when extra is nonzero also set 0x4. */
void fn_801AE874(unsigned short *flags, int extra) {
    unsigned short marked = *flags | 1;
    *flags = marked;
    if (extra) *flags = marked | 4;
}

#pragma scheduling invalid_target
void fn_801AE894(void *q) {
    int c;
    float s;
    float v;
    c = *(short *)((char *)q + 0x18);
    if (c > 0) {
        s = *(float *)q;
        if (s > lbl_8056255C) {
            v = (lbl_8055E630 * (float)c) / s;
            *(float *)((char *)q + 4) = v;
            *(float *)((char *)q + 4) = v * ((float)c / (float)lbl_8055E62C);
            return;
        }
    }
    *(float *)((char *)q + 4) = lbl_80562560;
}

#pragma processor 750
#pragma dont_inline on
void fn_801AE928(void) {
    /* For each active entry (stride 0x1C), initialize inactive ones: set flags, store default duration, recompute. */
    int count;
    float duration;
    int offset;
    int index;
    char *entry;
    count = fn_801EA994();
    duration = lbl_80562560;
    index = 0;
    offset = 0;
    while (index < count) {
        if (index < lbl_8055E624[1]) {
            entry = (char *)lbl_8055E624[0] + offset;
            if (!fn_801AE620(entry)) {
                fn_801AE874((unsigned short *)(entry + 0xE), 1);
                *(unsigned short *)(entry + 0xE) |= 8;
                *(float *)entry = duration;
                fn_801AE894(entry);
            }
        }
        offset += 0x1C;
        index++;
    }
}
#pragma dont_inline reset
#pragma processor gekko

float fn_801AE9E0(int competitorIndex, float *outValue) {
    /* Returns a competitor's stored lap/time value, optionally writing a derived inverse value to outValue. */
    char *entry;
    if (outValue != 0) *outValue = lbl_80562560;
    entry = (char *)lbl_8055E624[0] + competitorIndex * 0x1C;
    if (fn_801AE620(entry)) {
        if (outValue != 0) *outValue = lbl_8055E630 / *(float *)(entry + 8);
        return *(float *)(entry + 8);
    }
    return lbl_80562558;
}

#pragma small_data off
extern float lbl_80562560;
extern float lbl_8055E630;
extern float lbl_80562558;
extern int lbl_8055E62C;
extern double lbl_80562568;
extern float lbl_8056255C;
extern void fn_801AE874(unsigned short *, int);
extern void fn_801AE894(void *);
extern int fn_801EA994(void);
extern double __fabs(double);
int fn_801AEA64(float a, float b) {
#define gZeroEpsilon lbl_80558DC4
    /* Three-way compare for qsort: values within the zero epsilon are equal, otherwise ordered by magnitude. */
    float diff = a - b;
    float magnitude = (float)__fabs((double)diff);
    if (magnitude <= *(float *)(void *)&gZeroEpsilon) return 0;
    if (b < a) return 1;
    return -1;
#undef gZeroEpsilon
}

#pragma push
#pragma dont_inline on
/* Compare two race-result indices by placement for qsort: sort non-disqualified
 * entries by their recorded rank key, break ties by race time, and push
 * disqualified or missing entries to the end. */
int fn_801AEAA4(const void *left, const void *right) {
    int leftIndex = *(const int *)left;
    int rightIndex = *(const int *)right;
    RaceResult *leftResult = (RaceResult *)fn_801AF8D0(leftIndex);
    RaceResult *rightResult = (RaceResult *)fn_801AF8D0(rightIndex);
    int cmp;

    if (leftResult != 0 && rightResult != 0) {
        unsigned short leftFlags = leftResult->flags;
        unsigned short rightFlags = rightResult->flags;
        if (((leftFlags | rightFlags) & 8) == 0) {
            short rightRankKey = rightResult->f16;
            short leftRankKey = leftResult->f16;
            if (leftRankKey == rightRankKey) {
                return fn_801AEA64(leftResult->time, rightResult->time);
            }
            return leftRankKey - rightRankKey;
        }
        cmp = -1;
        if ((leftFlags & 8) != 0) {
            cmp = 1;
        }
        return cmp;
    }

    cmp = -1;
    if (leftResult == 0) {
        cmp = 1;
    }
    return cmp;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma dont_inline on
/* Compare two entry IDs by their scores (from fn_801AF9EC), treating values below 1.0 as a sentinel (10000.0). */
int fn_801AEB58(const void *a, const void *b) {
    float scoreA;
    float scoreB;
    float adjustedB;
    int idB = *(const int *)b;
    scoreA = fn_801AF9EC(*(const int *)a, 0);
    scoreB = fn_801AF9EC(idB, 0);
    adjustedB = scoreB;
    if (scoreA < lbl_8056255C)
        scoreA = lbl_80562570;
    if (scoreB < lbl_8056255C)
        adjustedB = lbl_80562570;
    return fn_801AEA64(scoreA, adjustedB);
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling invalid_target
void fn_801AEBD0(void) {
    register int value = lbl_8055E62C;
    register int count = lbl_80435780[0x3C0 / 4];
    register int i;
    register int share;
    register int remainder;
    register int offset;

    for (i = 0; i < count; i++) {
        short *item = (short *)(*lbl_8055E624 + i * 0x1C);
        value -= item[0x14 / 2];
    }

    share = value / 3;
    remainder = value % 3;

    for (offset = 0, i = 0;
         i < *(volatile int *)((char *)lbl_80435780 + 0x3C0);
         offset += 0x1C, i++) {
        char *entry = (char *)*(volatile int *)lbl_8055E624 + offset;
        short type = *(short *)(entry + 0xC);
        if (type < 4) {
            *(short *)(entry + 0x14) += share;
            if (type == 1)
                *(short *)(entry + 0x14) += remainder;
        }
    }
}
#pragma scheduling on
void fn_801AED54(void) {

}

void fn_801AED58(void) {

}

extern signed char lbl_8055E634;
extern void fn_801B8778(void);
extern void fn_801B878C(void);
extern float fn_801AF9EC(int, float *);
extern int fn_801AEA64(float, float);
extern void *fn_801AF8D0(int);
/* Set the global arena-event flag (lbl_8055E634) to 1/true, then notify the
 * arena-event master via fn_801B8778 (its f46 virtual call). */
void fn_801AED5C(void) {
#define sArenaEventFlag lbl_8055E634
    sArenaEventFlag = 1;
#undef sArenaEventFlag
    fn_801B8778();
}

/* Disable the arena event: clear its active flag and invoke the master object's stop handler (fn_801B878C). */
void fn_801AED68(void) {
#define s_arenaEventActive lbl_8055E634 /* nonzero while the arena event is enabled */
    s_arenaEventActive = 0;
#undef s_arenaEventActive
    fn_801B878C();
}

extern void *lbl_8055E620;
extern int fn_801B2F24(void);
extern int fn_801B3050(int);
extern int fn_801B2ED4(void);
extern void *memset(void *, int, unsigned int);
#pragma push
#pragma processor 750
void fn_801AED74(void)
{
  register int *base;
  register void *data;
  register int i;
  register int offset;
  register int **table;
  register int j;
  register int *entry;
  register int count;
  register int byteOffset;
  register float value;
  register int zero;
  register int progress;
  if ((*((unsigned char *) (&lbl_8055E634))) == 0)
  {
    base = lbl_8055E624;
    i = 0;
    value = lbl_80562558;
    offset = 0;
    for (; i < base[1]; i++)
    {
      int selected;
      data = ((char *) base[0]) + offset;
      memset(data, 0, 0x1C);
      *((float *) (((char *) data) + 8)) = value;
      count = -100;
      *((short *) (((char *) data) + 0xC)) = count;
      if (i < fn_801B2F24())
      {
        selected = fn_801B3050(i);
      }
      else
      {
        selected = -1;
      }
      *((short *) (((char *) data) + 0x1A)) = selected;
      offset += 0x1C;
    }

    table = (int **) lbl_8055E620;
    zero = 0;
    progress = 0;
    for (j = 0; j < 8; j += 4)
    {
      entry = table[j + 0];
      if (entry != 0)
      {
        count = 0;
        byteOffset = 0;
        while (count < entry[1])
        {
          *((short *) ((((char *) entry[0]) + byteOffset) + 6)) = zero;
          count++;
          byteOffset += 8;
        }

      }
      entry = table[j + 1];
      if (entry != 0)
      {
        count = 0;
        byteOffset = 0;
        while (count < entry[1])
        {
          *((short *) ((((char *) entry[0]) + byteOffset) + 6)) = zero;
          count++;
          byteOffset += 8;
        }

      }
      entry = table[j + 2];
      if (entry != 0)
      {
        count = 0;
        byteOffset = 0;
        while (count < entry[1])
        {
          *((short *) ((((char *) entry[0]) + byteOffset) + 6)) = zero;
          count++;
          byteOffset += 8;
        }

      }
      entry = table[j + 3];
      if (entry != 0)
      {
        count = 0;
        byteOffset = 0;
        while (count < entry[1])
        {
          *((short *) ((((char *) entry[0]) + byteOffset) + 6)) = zero;
          count++;
          byteOffset += 8;
        }

      }
      progress += 4;
    }

  }
  lbl_8055E62C = fn_801B2ED4();
}
#pragma pop
void fn_801AEF28(Src *arg0) {
    int *p;
    int *q;
    int i, off;
    char *base = (char *)lbl_80435740;
    Ent78 *dst = (Ent78 *)(base + 0x40);
    int *dcount = (int *)(base + 0x40 + 0x3C0);
    lbl_8055E635 = 1;
    p = (int *)fn_801284F8(0x24, lbl_80335980);
    if (p != 0) {
        memset(p, 0, 0x20);
        p[8] = 8;
    }
    lbl_8055E620 = p;
    q = (int *)fn_801284F8(8, lbl_80335990);
    if (q != 0) {
        float v;
        q[1] = 8;
        q[0] = fn_8012850C(q[1] * 0x1C, lbl_803359CC);
        v = lbl_80562558;
        for (i = 0, off = 0; i < q[1]; i++, off += 0x1C) {
            char *d = (char *)q[0] + off;
            int sel;
            memset(d, 0, 0x1C);
            *(float *)(d + 8) = v;
            *(short *)(d + 0xC) = -100;
            if (i < fn_801B2F24())
                sel = fn_801B3050(i);
            else
                sel = -1;
            *(short *)(d + 0x1A) = sel;
        }
    }
    lbl_8055E624 = q;
    lbl_8055E628 = ((int (*)(void *))fn_801AFA20)(arg0);
    *dcount = 0;
    for (i = 0; i < *(int *)((char *)arg0 + 0x3E0); i++) {
        Ent78 *s = &arg0->e[i];
        Ent78 *d = &dst[i];
        int id = s->id;
        if (fn_802794AC(id, (char *)arg0 + 0x3E4) == 0)
            break;
        d->id = id;
        d->b = s->b;
        d->f64 = s->f64;
        d->f68 = s->f68;
        d->f6c = s->f6c;
        d->f70 = s->f70;
        d->f74 = s->f74;
        ((int *)(base + 0x408))[i] = *dcount;
        (*dcount)++;
        if (fn_801AE600(id) != 0) {
            int *r = (int *)lbl_8055E620;
            int *t = (int *)fn_801284F8(8, lbl_803359AC);
            if (t != 0) {
                int k;
                t[1] = 0x1F5;
                t[0] = fn_8012850C(0xFA8, lbl_803359BC);
                for (k = 0; k < t[1]; k++)
                    *(short *)((char *)t[0] + k * 8 + 6) = 0;
            }
            r[i] = (int)t;
        }
    }
    for (i = 0; i < *dcount; i++) {
        lbl_80435740[i * 2] = lbl_80562560;
        lbl_80435740[i * 2 + 1] = lbl_8056255C;
    }
    lbl_8055E634 = 0;
    lbl_8055E630 = lbl_80562574;
    lbl_8055E62C = -1;
    for (i = 0; i < 4; i++)
        memset(base + 0x428 + i * 0x10, 0, 0x10);
}

#pragma paired_single reset
#pragma paired reset
extern void fn_801AFA5C(int);
extern void fn_80128670(void *);
extern void fn_80128668();
/* Heap-backed end-of-race tables allocated in fn_801AEF28 and released below. */
#define gCarLapTable     lbl_8055E620
#define gRaceResultTable lbl_8055E624
#define gRecordMgr       lbl_8055E628
#define gResultsReady    lbl_8055E635
#pragma scheduling invalid_target
void fn_801AF598(void) {
    /* Tear down the heap-backed end-of-race tables allocated by fn_801AEF28:
       destroy the RecordMgr, free each of the 8 CarLapTables (their lap arrays
       and the table structs), then the table array, and finally the
       RaceResultTable and its records. */
    register unsigned int slotIndex;
    register int **slot;
    register int *lapTable;
    register int **carLapTable;
    int recordMgr = lbl_8055E628;
    int zero = 0;
    lbl_8055E635 = 0;
    fn_801AFA5C(recordMgr);
    carLapTable = (int **)lbl_8055E620;
    lbl_8055E628 = zero;
    if (carLapTable != 0) {
        slot = carLapTable;
        for (slotIndex = 0; slotIndex < 8U; slotIndex++, slot++) {
            lapTable = *slot;
            if (lapTable != 0) {
                if (lapTable != 0) {
                    fn_80128670((void *)*lapTable);
                    *lapTable = zero;
                    fn_80128668(lapTable);
                }
                *(volatile int **)slot = 0;
            }
        }
        fn_80128668(carLapTable);
    }
    {
        register int **raceResultTable;
        raceResultTable = (int **)lbl_8055E624;
        lbl_8055E620 = 0;
        if (raceResultTable != 0) {
            fn_80128670((void *)*raceResultTable);
            *raceResultTable = 0;
            fn_80128668(raceResultTable);
        }
    }
    lbl_8055E624 = 0;
}
#pragma scheduling on

#pragma scheduling invalid_target
void fn_801AF65C(void) {
    /* For each active/result entry, set the flag bit at +0xE when the entry and its indexed query both pass. */
    int *tableBase = lbl_80435780;
    int entryOffset = 0;
    int index = 0;

    while (index < tableBase[0x3C0 / 4]) {
        char *entry = (char *)lbl_8055E624[0] + entryOffset;
        if (fn_801AE620(entry) && *fn_801EA9A0(index)) {
            *(unsigned short *)(entry + 0xE) |= 2;
        }
        entryOffset += 0x1C;
        index++;
    }
}
extern int fn_801769B8(void);
extern void fn_801AE928(void);
extern void fn_801AF65C(void);
extern void fn_801AFAB0(void);
extern void fn_801AFAB4(void);
extern void fn_801AFAB8(void);
extern int fn_80137C4C(void);
extern int fn_801AEAA4(const void *, const void *);
extern int fn_801AEB58(const void *, const void *);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern void fn_801B3208(int, int, float);
#pragma small_data off
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801AF6FC(void) {
    register char *base = (char *)lbl_80435740;
    register int mode;
    register unsigned int notTwo;
    register float *value;
    register int dataIndex;
    register int entryOffset;
    register int entryCount;
    register int rank;
    register int *sorted;
    register int finalIndex;
    register int *finalSorted;
    register int (*compare)(const void *, const void *);
    mode = fn_801769B8();
    notTwo = (unsigned int)((2 - mode) | (mode - 2)) >> 31;
    if (notTwo == 0) {
        fn_801AE928();
    }
    fn_801AF65C();
    for (entryOffset = 0, entryCount = 0; entryCount < *(int *)((char *)lbl_8055E620 + 0x20); entryOffset += 4, entryCount++) {
        int *entry = *(int **)((char *)lbl_8055E620 + entryOffset);
        if (entry != 0) {
            ((void (*)(int, int, int))fn_801AFAB0)(lbl_8055E628, entry[0], entry[1]);
        }
    }
    if (notTwo == 0) {
        ((void (*)(int, int, int))fn_801AFAB4)(lbl_8055E628, lbl_8055E624[0], lbl_8055E624[1]);
    }
    if (mode == 1) {
        char *tbl = base + 0x40;
        value = (float *)base;
        for (dataIndex = 0; dataIndex < *(int *)(tbl + 0x3C0); dataIndex++, value += 2) {
            value[0] = fn_801AE9E0(dataIndex, value + 1);
        }
    }
    {
        char *tbl = base + 0x40;
        sorted = (int *)(tbl + 0x3C8);
        qsort(sorted, *(int *)(tbl + 0x3C0), 4, (mode == 1) ? fn_801AEB58 : fn_801AEAA4);
    }
    {
        char *tbl = base + 0x40;
        rank = 0;
        sorted = (int *)(tbl + 0x3C8);
        for (; rank < *(int *)(tbl + 0x3C0); rank++, sorted++) {
            int index = *sorted;
            short rankValue = rank + 1;
            *(short *)((char *)lbl_8055E624[0] + index * 0x1C + 0xC) = rankValue;
        }
    }
    fn_801AEBD0();
    fn_801AE628((int)fn_80137C4C());
    if (notTwo == 0) {
        ((void (*)(int, int, int))fn_801AFAB8)(lbl_8055E628, lbl_8055E624[0], lbl_8055E624[1]);
    }
    fn_801AE79C(mode);
    if (mode == 1) {
        char *tbl = base + 0x40;
        finalSorted = (int *)(tbl + 0x3C8);
        for (finalIndex = 0; finalIndex < *(int *)(tbl + 0x3C0); finalSorted++, finalIndex++) {
            int index = *finalSorted;
            float itemValue = fn_801AF9EC(index, 0);
            fn_801B3208(index, finalIndex, itemValue);
        }
    }
}
#pragma scheduling on
#pragma dont_inline reset
#pragma small_data on

#pragma scheduling on
/* Return the result-table entry at the given index, or NULL if out of range or invalid. */
void *fn_801AF8D0(int index) {
    void *entry = 0;

    if (index < lbl_8055E624[1]) {
        entry = (char *)lbl_8055E624[0] + index * 0x1C;
        if (!fn_801AE620(entry)) {
            entry = 0;
        }
    }
    return entry;
}

#pragma small_data off
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
/* Populate a competitor summary buffer with count and per-entry result ids/states (skipped if blocked). */
void fn_801AF92C(void *output) {
    void *base = output;
    char *entry;
    int count;
    register int i;
    register int zero;
    register int minusOne;

    if (fn_801B8728() != 0)
        goto done;
    if (fn_801B2C70(base) != 0)
        goto done;

    count = lbl_80435780[0x3C0 / 4];
    zero = 0;
    *(int *)base = count;
    entry = (char *)base + 0x10;
    *(int *)((char *)base + 4) = zero;
    minusOne = -1;
    *((signed char *)base + 0xC) = zero;
    *((signed char *)base + 0xD) = 1;
    i = 0;

    for (; i < count; entry += 0x14, i++) {
        void *item = fn_801AF8D0(i);
        if (item != 0) {
            *(int *)(entry + 4) = *(short *)((char *)item + 0xC);
            *(int *)(entry + 8) = zero;
            entry[0x10] = zero;
        } else {
            *(int *)(entry + 4) = minusOne;
            *(int *)(entry + 8) = zero;
            entry[0x10] = zero;
        }
    }

done:
    ;
}
#pragma scheduling on
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma small_data on
float fn_801AF9EC(int arg0, float *arg1) {
    if (arg1 != 0) *arg1 = ((float (*)[2])lbl_80435740)[arg0][1];
    return lbl_80435740[arg0 * 2];
}

#pragma scheduling invalid_target
void fn_801AFA20(void) {
#define kRecordMgrName lbl_803359A0
#define createObject fn_801284F8
#define RecordMgr_init fn_801AFA64
    /* Allocate a RecordMgr object and clear its first field. */
    int recordMgr = createObject(4, kRecordMgrName);
    if (recordMgr != 0) {
        ((void (*)(int *, int))RecordMgr_init)((int *)recordMgr, -1);
    }
#undef kRecordMgrName
#undef createObject
#undef RecordMgr_init
}
#pragma scheduling on
void fn_801AFA5C(int arg0) { fn_801AFA70(arg0, 1); }

extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];

void fn_801AFA64(int *recordMgr) {
    /* RecordMgr constructor: clear the object's first field. */
    *recordMgr = 0;
}

/* CodeWarrior deleting-destructor helper: free object via Mem_freeObject (fn_80128668)
   when deleteFlag > 0, then return object. */
int fn_801AFA70(int object, int deleteFlag) {
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

void fn_801AFAB4(void) {

}

void fn_801AFABC(void) {

}

void fn_801AFAB8(void) {

}

void fn_801AFAB0(void) {

}
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
