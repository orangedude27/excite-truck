// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F714;
__declspec(section ".data") extern int lbl_804B3400;
extern int lbl_8055F728;
extern int lbl_8055F724;
extern int lbl_8055F718, lbl_8055F71C, lbl_8055F720;
extern float lbl_8055F710, lbl_805643E8, lbl_805643EC;
extern float fn_801E88F0(int);
extern float fn_802C9A4C(float);
extern void fn_802C9648(float);
extern void fn_802C8BD0(int);
extern int fn_801E5370(int, int, float);
extern void fn_8028D7C0(int);
extern void fn_801E58FC(void);
extern void DrawList_RestoreNormalMode(void);
extern void DrawList_reapplyProjection(void);
extern float lbl_80558DC4[];
extern float fn_801E7E24(void);
extern void fn_8028D728(void);
extern void fn_8028D4FC(void);
extern void fn_8028D4A0(void);
extern void fn_8028D25C(void);
extern int fn_8028D17C(void);
extern void fn_8028D2B4(void);
extern void fn_8028DDF0(void *, int);
extern void fn_80287B38(void *);
void fn_8028CED8(void) {
    /* RealName: SkidSystem_Init (guess). If skid data is ready, allocate/init buffers, register the update callback, and mark active. */
#define sSkidSystemActive lbl_8055F714
#define SkidSystem_PrepareData fn_8028D17C
#define SkidSystem_InitBuffers fn_8028D2B4
#define SkidSystem_RegisterUpdate fn_80287B38
#define SkidSystem_UpdateCallback fn_8028DDF0
    if (SkidSystem_PrepareData() != 0) {
        SkidSystem_InitBuffers();
        SkidSystem_RegisterUpdate(SkidSystem_UpdateCallback);
        sSkidSystemActive = 1;
    }
#undef sSkidSystemActive
#undef SkidSystem_PrepareData
#undef SkidSystem_InitBuffers
#undef SkidSystem_RegisterUpdate
#undef SkidSystem_UpdateCallback
}

/* RealName: SkidSystem_Shutdown (guess). When active, release the skid system's buffers and entries, then mark it inactive. */
void fn_8028CF18(void) {
#define sSkidSystemActive      lbl_8055F714
#define SkidSystem_ReleaseBuffers fn_8028D4A0
#define SkidSystem_ReleaseEntries fn_8028D25C
    if (sSkidSystemActive != 0) {
        SkidSystem_ReleaseBuffers();
        SkidSystem_ReleaseEntries();
        sSkidSystemActive = 0;
    }
#undef SkidSystem_ReleaseEntries
#undef SkidSystem_ReleaseBuffers
#undef sSkidSystemActive
}

/* Reset the skid system's per-entry items and global records, but only while it is active. */
void fn_8028CF50(void) {
#define sSkidSystemActive lbl_8055F714
#define SkidSystem_Reset  fn_8028D4FC
    if (sSkidSystemActive != 0) {
        SkidSystem_Reset();
    }
#undef SkidSystem_Reset
#undef sSkidSystemActive
}

/* Tick this subsystem while active, but only when the frame delta is non-zero. */
void fn_8028CF64(void) {
    if (lbl_8055F714 != 0) {
        float frameDelta = fn_801E7E24();
        float absFrameDelta = (float)__fabs((double)frameDelta);
        if (!(absFrameDelta <= lbl_80558DC4[0]))
            fn_8028D728();
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028CFB0(void) {
    /* Update active entries in the table, processing those with pending work and restoring the previous timer state. */
    int *entry;
    int i;
    float scale;
    float savedTime;
    if (lbl_8055F714 != 0) {
        savedTime = fn_802C9A4C(lbl_8055F710);
        fn_802C9648(lbl_805643E8);
        entry = &lbl_804B3400;
        scale = lbl_805643EC;
        for (i = 0; i < *(volatile int *)&lbl_8055F728; i++) {
            if (entry[6] > 1) {
                fn_802C8BD0(entry[0]);
                if (fn_801E5370(entry[6], 4, scale * fn_801E88F0(-1)) != 0) {
                    fn_8028D7C0(i);
                    fn_801E58FC();
                }
                DrawList_RestoreNormalMode();
            }
            entry = (int *)((char *)entry + 0x1C);
        }
        DrawList_reapplyProjection();
        fn_802C9A4C(savedTime);
    }
}
#pragma pop
extern int fn_802CAC28(int, int);
extern int Abend_Panic(char *, ...);
__declspec(section ".data") extern int lbl_80348C50;
struct Tbl8028D084 { char f0[12]; char f1[12]; char f2[12]; char f3[12]; char fmt[0x20]; };
extern char lbl_8055C8C8[];
#pragma cplusplus on
struct Obj8028D084 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f5(const char *);
    virtual void f4();
    virtual int f7(char *);
    virtual void f6();
    virtual float f9(char *);
    virtual void f8();
    virtual void f3();
};
#pragma cplusplus on
extern "C" void fn_8028D084(void *arg0, void *arg1) {
    extern char lbl_8055C8C8[8];
    char *base = (char *)&lbl_80348C50;
    int value;
    *(int *)arg0 = fn_802CAC28(((Obj8028D084 *)arg1)->f5(lbl_8055C8C8), 0);
    *(float *)((char *)arg0 + 4) = ((Obj8028D084 *)arg1)->f9(base + 0);
    *(float *)((char *)arg0 + 8) = ((Obj8028D084 *)arg1)->f9(base + 0xC);
    *(float *)((char *)arg0 + 0xC) = ((Obj8028D084 *)arg1)->f9(base + 0x18);
    value = ((Obj8028D084 *)arg1)->f7(base + 0x24);
    *(int *)((char *)arg0 + 0x10) = value;
    if (value < 8 || value > 0x24)
        Abend_Panic(base + 0x30, value);
}
extern char lbl_804B3470[];
extern char lbl_80348CA0[];
extern int lbl_8055C8D0;
extern "C" int fn_801345D8(void *, int, const void *, ...);
extern "C" void *fn_802AE414(void *);
extern void fn_8028D084(void *, void *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma cplusplus on
int fn_8028D17C(void) {
    /* Initialize the 8 terrain skid-handler slots: for each "terrain_%d", look up
       its object, fetch the "skid" sub-object through virtual get(), build a
       0x1C-byte handler with fn_8028D084 and record its index, or store -1 when
       the terrain has no skid data.  Returns nonzero if any handler was built. */
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20();
        virtual void *get(void *);
    };
    register int *slot;
    int terrainIndex;
    register int invalid;
    char terrainName[0x20];
    void *obj;
    slot = (int *)lbl_804B3470;
    lbl_8055F728 = 0;
    terrainIndex = 0;
    invalid = -1;
    for (; terrainIndex < 8; terrainIndex++) {
        fn_801345D8(terrainName, 0x20, lbl_80348CA0, terrainIndex);
        obj = fn_802AE414(terrainName);
        if (obj != 0) {
            obj = ((Obj *)obj)->get(&lbl_8055C8D0);
        }
        if (obj != 0) {
            fn_8028D084((char *)&lbl_804B3400 + lbl_8055F728 * 0x1C, obj);
            *slot = lbl_8055F728;
            lbl_8055F728++;
        } else {
            *slot = invalid;
        }
        slot++;
    }
    return lbl_8055F728 > 0;
}
#pragma cplusplus off
#pragma dont_inline reset
#pragma scheduling reset
#pragma use_lmw_stmw reset
extern int lbl_8055F728;
extern void fn_802CAC54(int);
/* Releases the texture handle in each registered 0x1C-byte entry
 * at lbl_804B3400 (count lbl_8055F728). */
void fn_8028D25C(void) {
    int *entry = (int *)(void *)&lbl_804B3400;
    int index = 0;
    while (index < lbl_8055F728) {
        fn_802CAC54(*entry);
        entry = (int *)((char *)entry + 0x1C);
        index++;
    }
}

extern void *fn_8012850C(int, void *);
extern int fn_80287B14(void);
extern void *fn_8002F37C(void *, void (*)(void), int, int, int);
extern void fn_8028D49C(void);
#pragma push
#pragma scheduling invalid_target
void fn_8028D2B4(void) {
    typedef struct {
        int unk0;
        int unk4;
        int unk8;
        int unkC;
        int elemCount; /* 0x10 */
        int subRecords; /* 0x14 */
        int unk18;
    } SkidDef;
    register char *labelStrings = (char *)&lbl_80348C50;
    register int totalElems = 0;
    int i = 0;
    int slots;
    int records;
    void *buffer;
    int *current;
    int *entry;
    int *ptr;
    int defIndex;
    int slotIndex;

    /* Allocate and initialize per-definition skid particle/element buffers. */
    for (; i < lbl_8055F728; i++)
        totalElems += ((SkidDef *)&lbl_804B3400)[i].elemCount;

    slots = fn_80287B14() * 4;
    totalElems *= slots;
    lbl_8055F724 = slots;
    records = lbl_8055F728 * slots;
    buffer = fn_8012850C(totalElems * 0x28 + 0x10, labelStrings + 0x5C);
    lbl_8055F718 = (int)fn_8002F37C(buffer, fn_8028D49C, 0, 0x28, totalElems);
    lbl_8055F71C = (int)fn_8012850C(records * 0xC, labelStrings + 0x6C);
    lbl_8055F720 = (int)fn_8012850C(*(volatile int *)&lbl_8055F724 * 8, labelStrings + 0x80);

    entry = &lbl_804B3400;
    current = (int *)lbl_8055F718;
    ptr = (int *)lbl_8055F71C;
    for (defIndex = 0; defIndex < lbl_8055F728; defIndex++) {
        *(int **)((char *)entry + 0x14) = ptr;
        for (slotIndex = 0; slotIndex < *(volatile int *)&lbl_8055F724; slotIndex++) {
            *ptr = (int)current;
            ptr[2] = entry[4];
            ptr += 3;
            current = (int *)((char *)current + entry[4] * 0x28);
        }
        entry += 7;
    }
}
#pragma pop

/* RealName: SkidSystem_ElementInit (guess). No-op per-element constructor passed
 * as the init callback to the skid element array allocator in fn_8028D2B4; skid
 * elements need no default initialization, so it intentionally does nothing. */
void fn_8028D49C(void) {
}

extern int lbl_8055F718, lbl_8055F71C, lbl_8055F720;
extern int fn_80128670(int);
void fn_8028D4A0(void) {
    /* Release the three buffers allocated by fn_8028D2B4 (lbl_8055F720, lbl_8055F71C, and lbl_8055F718) and clear their pointers. */
    fn_80128670(lbl_8055F720);
    lbl_8055F720 = 0;
    fn_80128670(lbl_8055F71C);
    lbl_8055F71C = 0;
    if (lbl_8055F718 != 0) {
        fn_80128670(lbl_8055F718 - 0x10);
    }
    lbl_8055F718 = 0;
}

extern int lbl_8055F724;
extern float lbl_805643F0;
extern void fn_8028D58C(void *);
#pragma scheduling invalid_target
void fn_8028D4FC(void) {
    /* SkidSystem_Reset: clear each group's item state (+4 of every 0xC-byte
     * item) and reset every global record (flag -1, value 0.0f). */
    typedef struct { unsigned char pad[0x14]; int *items; int total; } SkidEntry;
    typedef struct { int flag; float value; } SkidRecord;
    SkidEntry *entry = (SkidEntry *)&lbl_804B3400;
    int itemOffset;
    int groupIndex, itemIndex;
    int *item;
    groupIndex = 0;
    while (groupIndex < *(volatile int *)&lbl_8055F728) {
        itemIndex = 0;
        itemOffset = 0;
        while (itemIndex < *(volatile int *)&lbl_8055F724) {
            item = (int *)((char *)entry->items + itemOffset);
            *(int *)((char *)item + 4) = 0;
            itemIndex++;
            itemOffset += 0xC;
        }
        entry++;
        groupIndex++;
    }
    {
        float resetValue = lbl_805643F0;
        int recordOffset;
        int recordIndex;
        recordIndex = 0;
        recordOffset = 0;
        while (recordIndex < *(volatile int *)&lbl_8055F724) {
            SkidRecord *records = (SkidRecord *)*(volatile int *)&lbl_8055F720;
            SkidRecord *record = (SkidRecord *)((char *)records + recordOffset);
            record->flag = -1;
            record->value = resetValue;
            recordIndex++;
            recordOffset += 8;
        }
    }
}
#pragma scheduling on
void fn_8028D58C(void *arg0)
{
  unsigned int count;
  int startIndex;
  unsigned char *end;
  unsigned char *start;
  unsigned char *current;
  unsigned char *dst;
  int normalized;
  int *pcount;
  count = *((unsigned int *) (((char *) arg0) + 4));
  startIndex = (((int) count) - (*((int *) (((char *) arg0) + 8)))) + 2;
  startIndex = startIndex > 0 ? startIndex : 0;
  dst = *((unsigned char **) arg0);
  end = dst + (count * 0x28);
  start = dst + (((unsigned int) startIndex) * 0x28);
  for (current = start; current < end; current += 0x28)
  {
    startIndex = 0;
    if (((current > start) && (current[0x26] != 0)) && (((((*((unsigned short *) (current + 0x24))) >= 0x100) || ((*((unsigned short *) (current - 4))) >= 0x100)) || ((current + 0x28) >= end)) || ((current[0x4E] != 0) && ((*((unsigned short *) (current + 0x4C))) >= 0x100))))
    {
      startIndex = 1;
    }
    current[0x26] = (unsigned char) startIndex;
  }

  dst = *((unsigned char * volatile *) arg0);
  for (current = start; current < end; current += 0x28)
  {
    if ((current[0x26] != 0) || (((current + 0x28) < end) && (current[0x4E] != 0)))
    {
      *((float *) (dst + 0x00)) = *((float *) (current + 0x00));
      *((float *) (dst + 0x04)) = *((float *) (current + 0x04));
      *((float *) (dst + 0x08)) = *((float *) (current + 0x08));
      *((float *) (dst + 0x0C)) = *((float *) (current + 0x0C));
      *((float *) (dst + 0x10)) = *((float *) (current + 0x10));
      normalized = 0x14;
      *((float *) (dst + normalized)) = *((float *) (current + 0x14));
      *((float *) (dst + 0x18)) = *((float *) (current + 0x18));
      *((float *) (dst + 0x1C)) = *((float *) (current + 0x1C));
      *((float *) (0x20 + dst)) = *((float *) (current + 0x20));
      normalized = (*((unsigned short *) (current + 0x24))) - 0x80;
      normalized = normalized > 0 ? normalized : 0;
      *((unsigned short *) (dst + 0x24)) = (unsigned short) normalized;
      dst[0x26] = current[0x26];
      dst += 0x28;
    }
  }

  pcount = (int *)(((char *)arg0) + 4);
  *pcount = dst - (*((unsigned char * volatile *) arg0));
  *pcount = (*pcount) / 0x28;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028D728(void) {
    /* Recompute totals for each group entry by compacting/updating its items. */
    typedef struct { unsigned char pad[0x14]; int *items; int total; } Entry;
    Entry *entry = (Entry *)&lbl_804B3400;
    int i, j;
    for (i = 0; i < lbl_8055F728; i++) {
        entry[i].total = 0;
        for (j = 0; j < lbl_8055F724; j++) {
            int *item = (int *)((char *)entry[i].items + j * 0xC);
            fn_8028D58C(item);
            entry[i].total += item[1];
        }
    }
}
#pragma scheduling on
#pragma pop
extern double lbl_805643F8;
extern float lbl_805643F4;
extern void fn_801E53A8(void *, void *, void *, int, float);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma fp_contract on
#pragma use_lmw_stmw off
void fn_8028D7C0(int arg0) {
    register float scale;
    register double bias;
    register int outerOffset;
    register int offset;
    register int *table;
    register int outer;
    register int *group;
    register int inner;
    register int *item;

    bias = lbl_805643F8;
    scale = lbl_805643F4;
    table = (int *)((char *)&lbl_804B3400 + arg0 * 0x1C);
    outer = 0;
    outerOffset = 0;
    while (outer < lbl_8055F724) {
        group = (int *)((char *)table[5] + outerOffset);
        inner = 0;
        offset = 0;
        while (inner < group[1]) {
            item = (int *)((char *)group[0] + offset);
            {
                double raw;
                float value;
                *(unsigned int *)&raw = 0x43300000;
                *((unsigned int *)&raw + 1) =
                    *(unsigned short *)((char *)item + 0x24);
                value = (float)(raw - bias);
                fn_801E53A8(item, (char *)item + 0xC, (char *)item + 0x18,
                            *((unsigned char *)item + 0x26) != 0,
                            scale * value);
            }
            offset += 0x28;
            inner++;
        }
        outerOffset += 0xC;
        outer++;
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern float lbl_80564400;
extern float lbl_80564404;
extern float lbl_80564408;
extern float lbl_8056440C;
extern float lbl_80564410;
extern void PSVECCrossProduct(void *, void *, void *);
void fn_8028D89C(void *arg0, int arg1, float arg2) {
#pragma fp_contract off
    void *base;
    int idx, kind, flag;
    unsigned char *g;
    unsigned char *entry;
    unsigned char *itemC;
    unsigned char *item;
    unsigned char *next;
    int key;
    int *state;
    unsigned char *group;
    float crossA[3], crossB[3], crossC[3];
    float t, lim, gt, scale;
    int i, clamped;

    base = *(void **)arg0;
    entry = (unsigned char *)base + arg1 * 0x3c;
    kind = *(int *)(entry + 0xa8);
    idx = arg1 + *(int *)((unsigned char *)arg0 + 4) * 4;
    state = (int *)((unsigned char *)(unsigned long)*(volatile int *)&lbl_8055F720 + idx * 8);
    if (kind >= 8) goto clear1;
    key = ((int *)&lbl_804B3470)[kind];
    if (key < 0) goto clear1;
    group = (unsigned char *)&lbl_804B3400 + key * 0x1c;
    flag = 0;
    if (*(unsigned char *)(entry + 0xa0) != 0 &&
        *(float *)(entry + 0x98) > *(float *)(group + 0xc))
        flag = 1;
    if (flag == 0) goto clear2;
    if (state[0] == key) {
        if (arg2 > lbl_80564400 + *(float *)(state + 1)) {
            scale = lbl_80564404;
            g = *(unsigned char **)(group + 0x14) + idx * 0xc;
            item = *(unsigned char **)g + *(int *)(g + 4) * 0x28;
            *(float *)(item + 0) = *(float *)(entry + 0x7c);
            *(float *)(item + 4) = *(float *)(entry + 0x80);
            *(float *)(item + 8) = *(float *)(entry + 0x84);
            *(float *)(item + 0xc) = *(float *)((unsigned char *)base + 0x34) * scale;
            *(float *)(item + 0x10) = *(float *)((unsigned char *)base + 0x38) * scale;
            *(float *)(item + 0x14) = *(float *)((unsigned char *)base + 0x3c) * scale;
            PSVECCrossProduct((unsigned char *)base + 0x40, entry + 0x88, crossA);
            if (((*(int *)(entry + 0x9c)) & 8) == 0) {
                float s = lbl_80564408;
                *(float *)(item + 0x18) = crossA[0] * s;
                *(float *)(item + 0x1c) = crossA[1] * s;
                *(float *)(item + 0x20) = crossA[2] * s;
            } else {
                float s = lbl_8056440C;
                *(float *)(item + 0x18) = crossA[0] * s;
                *(float *)(item + 0x1c) = crossA[1] * s;
                *(float *)(item + 0x20) = crossA[2] * s;
            }
            gt = *(float *)(group + 0xc);
            lim = (lbl_805643F0 > gt) ? lbl_805643F0 : gt;
            t = *(float *)(entry + 0x98) - lim;
            i = (int)(lbl_80564410 * (*(float *)(group + 4) + *(float *)(group + 8) * t));
            clamped = i & (((-i) & ~i) >> 31);
            if (clamped < 0xFFFF) *(unsigned short *)(item + 0x24) = clamped;
            *(unsigned char *)(item + 0x26) = 1;
            *(int *)(g + 4) = *(int *)(g + 4) + 1;
            *(int *)(group + 0x18) = *(int *)(group + 0x18) + 1;
            *(float *)(state + 1) = arg2;
        } else {
            scale = lbl_80564404;
            g = *(unsigned char **)(group + 0x14) + idx * 0xc;
            item = *(unsigned char **)g + (*(int *)(g + 4) - 1) * 0x28;
            *(float *)(item + 0) = *(float *)(entry + 0x7c);
            *(float *)(item + 4) = *(float *)(entry + 0x80);
            *(float *)(item + 8) = *(float *)(entry + 0x84);
            *(float *)(item + 0xc) = *(float *)((unsigned char *)base + 0x34) * scale;
            *(float *)(item + 0x10) = *(float *)((unsigned char *)base + 0x38) * scale;
            *(float *)(item + 0x14) = *(float *)((unsigned char *)base + 0x3c) * scale;
            PSVECCrossProduct((unsigned char *)base + 0x40, entry + 0x88, crossB);
            if (((*(int *)(entry + 0x9c)) & 8) == 0) {
                float s = lbl_80564408;
                *(float *)(item + 0x18) = crossB[0] * s;
                *(float *)(item + 0x1c) = crossB[1] * s;
                *(float *)(item + 0x20) = crossB[2] * s;
            } else {
                float s = lbl_8056440C;
                *(float *)(item + 0x18) = crossB[0] * s;
                *(float *)(item + 0x1c) = crossB[1] * s;
                *(float *)(item + 0x20) = crossB[2] * s;
            }
            gt = *(float *)(group + 0xc);
            lim = (lbl_805643F0 > gt) ? lbl_805643F0 : gt;
            t = *(float *)(entry + 0x98) - lim;
            i = (int)(lbl_80564410 * (*(float *)(group + 4) + *(float *)(group + 8) * t));
            clamped = i & (((-i) & ~i) >> 31);
            if (clamped < 0xFFFF) *(unsigned short *)(item + 0x24) = clamped;
        }
    } else {
        int z = 0, o = 1;
        scale = lbl_80564404;
        g = *(unsigned char **)(group + 0x14) + idx * 0xc;
        itemC = *(unsigned char **)g + *(int *)(g + 4) * 0x28;
        next = *(unsigned char **)g + (*(int *)(g + 4) + 1) * 0x28;
        *(float *)(itemC + 0) = *(float *)(entry + 0x7c);
        *(float *)(itemC + 4) = *(float *)(entry + 0x80);
        *(float *)(itemC + 8) = *(float *)(entry + 0x84);
        *(float *)(itemC + 0xc) = *(float *)((unsigned char *)base + 0x34) * scale;
        *(float *)(itemC + 0x10) = *(float *)((unsigned char *)base + 0x38) * scale;
        *(float *)(itemC + 0x14) = *(float *)((unsigned char *)base + 0x3c) * scale;
        PSVECCrossProduct((unsigned char *)base + 0x40, entry + 0x88, crossC);
        if (((*(int *)(entry + 0x9c)) & 8) == 0) {
            float s = lbl_80564408;
            *(float *)(itemC + 0x18) = crossC[0] * s;
            *(float *)(itemC + 0x1c) = crossC[1] * s;
            *(float *)(itemC + 0x20) = crossC[2] * s;
        } else {
            float s = lbl_8056440C;
            *(float *)(itemC + 0x18) = crossC[0] * s;
            *(float *)(itemC + 0x1c) = crossC[1] * s;
            *(float *)(itemC + 0x20) = crossC[2] * s;
        }
        gt = *(float *)(group + 0xc);
        lim = (lbl_805643F0 > gt) ? lbl_805643F0 : gt;
        t = *(float *)(entry + 0x98) - lim;
        i = (int)(lbl_80564410 * (*(float *)(group + 4) + *(float *)(group + 8) * t));
        clamped = i & (((-i) & ~i) >> 31);
        if (clamped < 0xFFFF) *(unsigned short *)(itemC + 0x24) = clamped;
        *(unsigned char *)(itemC + 0x26) = z;
        *(float *)(next + 0) = *(float *)(itemC + 0);
        *(float *)(next + 4) = *(float *)(itemC + 4);
        *(float *)(next + 8) = *(float *)(itemC + 8);
        *(float *)(next + 0x18) = *(float *)(itemC + 0x18);
        *(float *)(next + 0x1c) = *(float *)(itemC + 0x1c);
        *(float *)(next + 0x20) = *(float *)(itemC + 0x20);
        *(float *)(next + 0xc) = *(float *)(itemC + 0xc);
        *(float *)(next + 0x10) = *(float *)(itemC + 0x10);
        *(float *)(next + 0x14) = *(float *)(itemC + 0x14);
        *(unsigned short *)(next + 0x24) = *(unsigned short *)(itemC + 0x24);
        *(unsigned char *)(next + 0x26) = o;
        *(int *)(g + 4) = *(int *)(g + 4) + 2;
        *(int *)(group + 0x18) = *(int *)(group + 0x18) + 2;
    }
    state[0] = key;
    return;
clear2:
    state[0] = -1;
    return;
clear1:
    state[0] = -1;
}
#pragma pop

extern int lbl_804B3490[];
typedef struct {
    int *items;
    int index;
    float f8;
    unsigned char c;
} SkidEntry;
extern float lbl_80564414;
extern float fn_801E7E18(void);
extern void fn_8028D89C(void *, int, float);
#pragma cplusplus on
void fn_8028DDF0(register void *arg0, register int arg1) {
    typedef struct {
        int *items;
        int index;
        float f8;
        unsigned char c;
    } Entry;
    typedef struct {
        int a, b, c, d, e, f, g, h;
    } Output;
    Entry *entry = (Entry *)arg0;
    register int invalid;
    register int *slot;
    register int i;
    register float threshold;
    register float result;
    float value;
    float abs;

    value = fn_801E7E24();
    abs = (float)__fabs((double)value);
    if (abs <= lbl_80558DC4[0])
        return;

    threshold = lbl_80564414;
    result = fn_801E7E18();
    slot = lbl_804B3490;
    i = 0;
    invalid = -1;
    while (i < arg1) {
        if (entry->f8 < threshold &&
            (void *)(unsigned long)entry->items[0x19] == (void *)slot[entry->index] &&
            entry->c != 0) {
            int j;
            for (j = 0; j < 4; j++)
                fn_8028D89C(entry, j, result);
        } else {
            int offset = entry->index << 5;
            *(int *)((char *)(unsigned long)lbl_8055F720 + offset) = invalid;
            *(int *)((char *)(unsigned long)*(volatile int *)&lbl_8055F720 + offset + 8) = invalid;
            *(int *)((char *)(unsigned long)*(volatile int *)&lbl_8055F720 + offset + 0x10) = invalid;
            *(int *)((char *)(unsigned long)*(volatile int *)&lbl_8055F720 + offset + 0x18) = invalid;
        }
        slot[entry->index] = entry->items[0x19];
        entry++;
        i++;
    }
}
