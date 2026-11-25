// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
#pragma push
#pragma cplusplus on
class ParticleConfig {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual const char *getText(const char *);
    virtual void v4();
    virtual void v5();
    virtual int getInt(const char *, int);
    virtual void v6();
    virtual float getFloat(const char *, float);
    virtual void v8();
    virtual int getBool(const char *, int);
};
#pragma pop
extern void *fn_801284F8(int, const char *);
extern void fn_801345D8(char *, int, const char *, ...);
extern void fn_802B2C7C(void *);
extern void **fn_802B2384(void *, void **__restrict);
extern void *fn_802B23A8(void *, void *, void *);
extern int fn_802B2C44(void *);
extern char lbl_8034A2C4[];
extern char lbl_8034A2D8[];
extern char lbl_8055CDC8;
extern char lbl_8055CDD0;

#pragma dont_inline on
int fn_802B2E00(void *);
int *fn_802B320C(int *, int);
#pragma dont_inline reset
int fn_802B2E08(int);
int fn_802B3340(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;
extern float lbl_80564C00, lbl_80564C04, lbl_80564C08;
typedef struct { float x, y, z; } ParticleVec3;
extern float fn_80129DC4(float, float);
extern double cos(float);
extern double sin(float);
extern char lbl_8034A288[];
extern char lbl_8034A3F8[];
extern int lbl_8055CDC0;
extern void fn_802B8AE0(void *, void *);
extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, const char *);
extern void *fn_8002F37C(void *, void (*)(void *), void *(*)(void *, int), int, int);
extern void fn_802B1FC0(void *);
extern void fn_802B1F64(void);
extern void *fn_802B1F68(void *, int);

int fn_8012C33C(void);
int fn_802CAC28(int, int);
extern void fn_80128668(void *);
/* Scalar deleting destructor helper: clears the object's three-word header
 * {+0x00,+0x04,+0x08} to zero, and frees the object when deletingFlag > 0.
 * The redundant null check is intentional (matches the original). */
void *fn_802B1CE0(void *this_, int deletingFlag) {
    if (this_ != 0) {
        if (this_ != 0) {
            *(int *)this_ = 0;
            *((int *)this_ + 1) = 0;
            *((int *)this_ + 2) = 0;
        }
        if (deletingFlag > 0)
            fn_80128668(this_);
    }
    return this_;
}

int fn_802B1D38(int handle) {
    // If the handle is non-null and the NAND subsystem is available, close it via the texture manager; otherwise return an error.
    int isValid = 0;

    if (handle != 0 && fn_8012C33C() != 0) isValid = 1;
    if (isValid != 0) return fn_802CAC28(handle, 0);
    return -2;
}

/* RealName: TreeModel_GetDrawCost (rename_symbol unavailable)
 * Per-instance draw cost of a loaded model resource (a tree class's near or
 * far model), taken from its header according to the format FourCC at +0x00:
 *   'SIND' - the entry count stored at +0x20
 *   'NDL2' - the entry count stored at +0x1C, less the 2 words that head it
 * Any other format falls back to a cost of 1000.  fn_802BCBDC stores the
 * result in each tree class entry's near/far cost fields (+0x14 / +0x24);
 * fn_802BD814 adds that cost up for every instance it draws and skips the
 * second pass once it exceeds 10. */
int fn_802B1DA0(void *model) {
#define TAG_SIND 0x53494E44 /* 'SIND' model format */
#define TAG_NDL2 0x4E444C32 /* 'NDL2' model format */
    typedef struct {
        int tag;       /* format FourCC, one of the TAG_ values above */
        int pad04[6];
        int ndl2Count; /* 'NDL2': entries at +0x1C, header words included */
        int sindCount; /* 'SIND': entries at +0x20 */
    } ModelHeader;
    int tag = *(int *)model;
    switch (tag) {
    case TAG_SIND:
        return ((ModelHeader *)model)->sindCount;
    case TAG_NDL2:
        return ((ModelHeader *)model)->ndl2Count - 2;
    default:
        return 1000;
    }
#undef TAG_SIND
#undef TAG_NDL2
}

extern void *lbl_8055F9BC;
extern struct Unk802B2C98 lbl_804BE1FC;
void fn_802B21D4(void **);
void fn_802B2104(void **);
void fn_80128668(void *);
extern int lbl_8055CDB8;
#define kObjectName lbl_8055CDB8 /* .sdata: "object", the material-item name tested below */
int stricmp(const char *, const char *);
#pragma push
#pragma cplusplus on
extern "C" int fn_802B1DE8(void *item) {
    /* RealName: UMatItem_IsObject (returns nonzero if the material item's name is "object"). */
    class UMatNamedItem {
    public:
        virtual const char *getName();
    };
    return stricmp((char *)&kObjectName, ((UMatNamedItem *)item)->getName()) == 0;
}

extern "C" char fn_802B1E28(void)
{
  typedef struct Pool
  {
    void *data;
    void *nodes;
    volatile int used;
    volatile int capacity;
    void *storage;
  } Pool;
  typedef void *(*AllocArray)(void *, void (*)(void *), void *(*)(void *, int), int, int);
  Pool *pool;
  void *storage;
  void *nodes;
  void *data;
  void *entry;
  int count;
  int size;
  int offset;
  int i;
  s32 index;
  fn_802B8AE0(lbl_8034A288 + 0xC, &lbl_8055F9B4);
  fn_802B8AE0(lbl_8034A288 + 0x18, &lbl_8055F9B0);
  pool = (Pool *) fn_801284F8(0x14, lbl_8034A288 + 0x28);
  if (pool != 0)
  {
    storage = fn_8012850C(0x610, (const char *) (&lbl_8055CDC0));
    do
    {
      nodes = ((AllocArray) fn_8002F37C)(storage, fn_802B1FC0, fn_802B1F68, 0x10, 0x60);
      pool->nodes = nodes;
      pool->capacity = 0x60;
      pool->used = 0;
      pool->storage = nodes;
      size = (count = pool->capacity) << 6;
    }
    while (0);
    storage = fn_8012850C(((size * ((long long) 0x14)) & 0xFF) + 0x10, lbl_8034A3F8);
    data = ((AllocArray) fn_8002F37C)(storage, (void (*)(void *)) fn_802B1F64, (void *(*)(void *, int)) 0, 0x14, size);
    pool->data = data;
    i = 0;
    offset = 0;
    do
    {
      index = pool->used;
      i++;
      nodes = pool->nodes;
      data = pool->data;
      pool->used = index + 1;
      *((void **) (entry = ((char *) nodes) + (index * 0x10))) = ((char *) data) + offset;
      offset += 0x500;
      *((int *) (((char *) entry) + 8)) = 0x40;
      *((int *) (((char *) entry) + 4)) = 0;
    }
    while (i < pool->capacity);
    pool->used = 0;
  }
  lbl_8055F9BC = pool;
}

#pragma cplusplus reset
#pragma pop
/* No-op destructor callback passed to fn_8002F37C for the memory pool's data
   array in fn_802B1E28: each 0x500-byte data block needs no teardown. */
void fn_802B1F64(void) {
}

void *fn_802B1F68(void *object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when
     * shouldDelete > 0 (deleting-destructor style helper). */
    if (object != 0) {
        if (object != 0) {
            *(int *)object = 0;
            *((int *)object + 1) = 0;
            *((int *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Zero the three 32-bit fields of a pool node; used as the element initializer
 * callback passed to fn_8002F37C (paired with the fn_802B1F68 destructor). */
void fn_802B1FC0(void *node) {
    ((int *)node)[0] = 0;
    ((int *)node)[2] = 0;
    ((int *)node)[1] = 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma opt_common_subs off
/* Tears down the global material registry lbl_804BE1FC: for each material set,
 * material and owned item it releases the resource and frees the object, clears
 * the parent's array/count/capacity fields, then empties the registry count. */
void fn_802B1FD4(void) {
    #pragma scheduling invalid_target
    void *materialSet;
    int matIndex;
    void *material;
    int itemIndex;
    void *item;
    int setOffset;
    int matOffset;
    int itemOffset;
    int setIndex;
    void *materialSets;

    fn_802B2104(&lbl_8055F9BC);
    materialSets = &lbl_804BE1FC;
    setIndex = 0;
    setOffset = 0;
    for (; setIndex < *(int *)((char *)materialSets + 4); setOffset += 4, setIndex++) {
        materialSet = *(void **)(*(char **)&lbl_804BE1FC + setOffset);
        if (materialSet != 0) {
            for (matIndex = 0, matOffset = 0; matIndex < *(int *)((char *)materialSet + 4); matOffset += 4, matIndex++) {
                material = *(void **)(*(char **)materialSet + matOffset);
                if (material != 0) {
                    for (itemIndex = 0, itemOffset = 0; itemIndex < *(int *)((char *)material + 0x40c); itemOffset += 4, itemIndex++) {
                        item = *(void **)(*(char **)((char *)material + 0x408) + itemOffset);
                        if (item != 0) {
                            fn_802B21D4((void **)((char *)item + 0xc));
                            fn_80128668(item);
                        }
                    }
                    *(int *)((char *)material + 0x40c) = 0;
                    if ((char *)material + 0x408 != 0) {
                        if ((char *)material + 0x408 != 0) {
                            *(int *)((char *)material + 0x408) = 0;
                            *(int *)((char *)material + 0x40c) = 0;
                            *(int *)((char *)material + 0x410) = 0;
                        }
                    }
                    fn_80128668(material);
                }
            }
            *(int *)((char *)materialSet + 4) = 0;
            if (materialSet != 0) {
                if (materialSet != 0) {
                    *(int *)materialSet = 0;
                    *((int *)materialSet + 1) = 0;
                    *((int *)materialSet + 2) = 0;
                }
            }
            fn_80128668(materialSet);
        }
    }
    *(int *)((char *)materialSets + 4) = 0;
}
#pragma pop

void fn_80128670(void *);
void fn_802B218C(void *);
void fn_8002F6AC(int, void (*)(void));
void *fn_802B1F68(void *, int);
void fn_80128668(void *);
void fn_802B2104(void **arg0);
void fn_802CAC54(int);
void fn_802C6C20(void *);
int fn_80129D90(int, int, int);

#pragma push
#pragma opt_common_subs off
void fn_802B2104(void **objectSlot) {
    /* Destroy the object stored in *objectSlot and clear the slot. Frees the
     * object's owned buffer, runs the element destructor over its pool, clears
     * the object's bookkeeping fields, then deletes the object. */
    void *object = *objectSlot;
    if (object != 0) {
        if (object != 0) {
            fn_802B218C(object);
            if ((char *)object + 4 != 0) {
                fn_8002F6AC(((int *)object)[4], (void (*)(void))fn_802B1F68);
                if ((char *)object + 4 != 0) {
                    ((int *)object)[1] = 0;
                    ((int *)object)[2] = 0;
                    ((int *)object)[3] = 0;
                }
            }
            fn_80128668(object);
        }
        *objectSlot = 0;
    }
}
#pragma pop
/* Free the owned buffer stored at *object (allocated with a header at -0x10) and clear the pointer. */
void fn_802B218C(void *object) {
    void *buffer = *(void **)object;
    if (buffer != 0) {
        if (buffer != 0) {
            fn_80128670((char *)buffer - 0x10);
        }
        *(void **)object = 0;
    }
}

#pragma push
#pragma opt_common_subs off
void fn_802B21D4(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            int handle = ((int *)ptr)[2];
            if (handle != -2) {
                fn_802CAC54(handle);
                ((int *)ptr)[2] = -2;
            }
            {
                void *resource = *(void **)ptr;
                if (resource != 0) {
                    fn_802C6C20(resource);
                }
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}

#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma opt_common_subs off
extern "C" void fn_802B224C(void *model) {
    /* RealName: MatList_BuildFromModel
     * Builds a named list of the materials (mat1, mat2, ...) exposed by the model
     * object and registers the list in the global material-list table. */
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void *getName(const char *);
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
        virtual int findMaterial(const char *);
    };

    char matName[16];
    void *materials;
    int matIndex;
    void *material;
    void *materialSlot;
    int listCount;
    Obj *modelObj = (Obj *)model;

    listCount = *(int *)((char *)&lbl_804BE1FC + 4);
    if (listCount + 1 > *(int *)((char *)&lbl_804BE1FC + 8))
        return;

    materials = fn_801284F8(0x28, lbl_8034A2C4);
    if (materials != 0) {
        fn_802B2C7C(materials);
        matIndex = 1;
        do {
            fn_801345D8(matName, 0x10, (const char *)&lbl_8055CDC8, matIndex);
            if (((int (*)(void *, void *))fn_802B2C44)(modelObj, matName) == 0)
                break;
            material = fn_801284F8(0x454, lbl_8034A2D8);
            if (material != 0) {
                material = fn_802B23A8(material, (void *)modelObj->findMaterial(matName), (void *)(matIndex - 1));
            }
            materialSlot = material;
            fn_802B2384(materials, &materialSlot);
            matIndex++;
        } while (1);
        *(void **)((char *)materials + 0x24) = modelObj->getName((const char *)&lbl_8055CDD0);
    }

    void **listTable = *(void ***)&lbl_804BE1FC;
    int *listCountPtr = (int *)((char *)&lbl_804BE1FC + 4);
    int listIndex = (*listCountPtr)++;
    listTable[listIndex] = materials;
}

#pragma cplusplus off
#pragma push
#pragma optimization_level 3
#pragma opt_pointer_aliasing on
/* Append *pValue to the pointer vector's data array, advance its count, and
 * return the address of the newly filled slot. */
void **fn_802B2384(void *vec, void **__restrict pValue) {
    int index;
    void **data;
    int newIndex;
    index = ((int *)vec)[1];
    data = *(void ***)vec;
    newIndex = index + 1;
    ((int *)vec)[1] = newIndex;
    data[index] = *pValue;
    return &data[index];
}
#pragma pop

extern char lbl_8034A2E8[];
extern char lbl_8055CDD8;
extern void *fn_801284F8(int, const char *);
extern void fn_802B2504(int *, int);
extern void *fn_802B2958(void *, void *);
extern void **fn_802B2934(void *, void **__restrict);
extern void fn_802B257C(void *);
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma opt_common_subs off
#pragma opt_loop_invariants off
extern "C" void *fn_802B23A8(void *arg0, void *arg1, void *arg2) {
    class Obj {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual int v10(const char *, int);
        virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
        virtual void v19(); virtual void v20(); virtual void v21(); virtual void *v22(int);
    };
    int j;
    void *item;
    void *alloc;
    void *sp8;
    unsigned int i;
    char *p = (char *)arg0;
    *(int *)((char *)arg0 + 0x40C) = 0;
    *(int *)((char *)arg0 + 0x410) = 16;
    *(void **)((char *)arg0 + 0x408) = (char *)arg0 + 0x414;
    *(char *)((char *)arg0 + 4) = 0;
    *(char *)((char *)arg0 + 5) = 0;
    int val = 0;
    do {
        *(int *)(p + 8) = val++;
        *(int *)(p + 0xC) = val++;
        *(int *)(p + 0x10) = val++;
        *(int *)(p + 0x14) = val++;
        *(int *)(p + 0x18) = val++;
        *(int *)(p + 0x1C) = val++;
        *(int *)(p + 0x20) = val++;
        *(int *)(p + 0x24) = val++;
        p += 0x20;
    } while (--i);
    fn_802B2504((int *)((char *)arg0 + 8), 0x80);
    *(char *)((char *)arg0 + 5) = ((Obj *)arg1)->v10(&lbl_8055CDD8, 1);
    *(char *)((char *)arg0 + 4) = *(char *)((char *)arg0 + 5);
    for (j = 0; (item = ((Obj *)arg1)->v22(j)) != 0; j++) {
        if (fn_802B1DE8(item) != 0) {
            alloc = fn_801284F8(0x2A8, lbl_8034A2E8);
            if (alloc != 0) {
                sp8 = fn_802B2958(alloc, item);
                fn_802B2934((char *)arg0 + 0x408, &sp8);
            }
        }
    }
    fn_802B257C(arg0);
    *(void **)arg0 = arg2;
    return arg0;
}
#pragma cplusplus reset
#pragma pop

#pragma pop
int fn_80129D90(int, int, int);
#pragma push
#pragma use_lmw_stmw off
/* Shuffle an integer array in place (Fisher-Yates): swap each element except the
 * last with one drawn at random from the elements after it. `offset` walks the
 * array in bytes. */
void fn_802B2504(int *dst, int count) {
    int limit;
    int offset;
    int i;
    i = 0;
    limit = count - 1;
    offset = 0;
    while (i < limit) {
        int swapIndex = fn_80129D90(0, i + 1, count);
        int saved = dst[offset / 4];
        dst[offset / 4] = dst[swapIndex];
        dst[swapIndex] = saved;
        i++;
        offset += 4;
    }
}
#pragma pop
void fn_802B28BC(int *, int);
void *memset(void *, int, unsigned int);
#pragma push
#pragma use_lmw_stmw off
void fn_802B257C(void *arg0) {
    struct ArgLayout { char pad[8]; int shuffle[0x80]; int output[0x80]; };
    int total = 0;
    int i, idx;
    for (i = 0; i < *(int *)((char *)arg0 + 0x40C); i++) {
        total += *(*(int ***)((char *)arg0 + 0x408))[i];
    }
    if (total > 0x80) {
        idx = fn_80129D90(0, 0, *(int *)((char *)arg0 + 0x40C));
        while (total > 0x80) {
            int *p = (*(int ***)((char *)arg0 + 0x408))[idx];
            if (*p > 0) {
                *p = *p - 1;
                total--;
            }
            idx = (idx + 1) % *(int *)((char *)arg0 + 0x40C);
        }
    }
    memset(((struct ArgLayout *)arg0)->output, 0, 0x200);
    {
        int dbl;
        int pos = 0;
        int bytePos = 0;
        int k;
        i = 0x80 - total;
        dbl = i * 2;
        for (k = 0; k < *(int *)((char *)arg0 + 0x40C); k++) {
            int *obj = (*(int ***)((char *)arg0 + 0x408))[k];
            int lim0 = dbl / *(int *)((char *)arg0 + 0x40C);
            int lim = i;
            if (lim0 < lim)
                lim = lim0;
            if (lim > 0) {
                int n = ((struct ArgLayout *)arg0)->shuffle[k & 0x7F] % lim;
                int j;
                for (j = 0; j < n; j++) {
                    *(int *)((char *)arg0 + bytePos + 0x208) = 0;
                    bytePos += 4;
                    pos++;
                }
                i -= n;
            }
            {
                int j;
                for (j = 0; j < *obj; j++) {
                    *(int **)((char *)arg0 + bytePos + 0x208) = obj;
                    bytePos += 4;
                    pos++;
                }
            }
        }
    }
    if (*(unsigned char *)((char *)arg0 + 4) == 0)
        fn_802B28BC((int *)((char *)arg0 + 0x208), 0x80);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
/* ShuffleSpawnList: Fisher-Yates shuffle of the emitter spawn list -- every
   entry but the last is swapped with one drawn at random from the entries after
   it, so the weighted list built by fn_802B257C comes out in random order.
   `entries` holds `count` 4-byte pointers; `bytePos` walks them in bytes. */
void fn_802B28BC(int *entries, int count) {
#define RandomIntInRange fn_80129D90 /* random int in [min, max) of RNG slot 0 */
    int limit;
    int bytePos;
    int i;
    i = 0;
    limit = count - 1;
    bytePos = 0;
    while (i < limit) {
        int swapWith = RandomIntInRange(0, i + 1, count);
        int saved = entries[bytePos / 4];
        entries[bytePos / 4] = entries[swapWith];
        entries[swapWith] = saved;
        i++;
        bytePos += 4;
    }
#undef RandomIntInRange
}

        #pragma push
   #pragma cplusplus off
   #pragma scheduling invalid_target
   #pragma dont_inline on
   #pragma opt_common_subs off
   #pragma optimization_level 3
   #pragma opt_pointer_aliasing on
/* Append *pValue to the { void **data; int count; } pointer vector and return the new slot. */
void **fn_802B2934(void *vec, void **__restrict pValue) {
    int index;
    void **data;
    int newIndex;
    index = ((int *)vec)[1];
    data = *(void ***)vec;
    newIndex = index + 1;
    ((int *)vec)[1] = newIndex;
    data[index] = *pValue;
    return &data[index];
}
 #pragma pop

extern void fn_802B2C34(void (*)(void *), void *);
extern char lbl_8055CDE0[8], lbl_8055CDE8[4], lbl_8055CDEC[4];
extern void fn_802C6B44(void *);
extern int fn_802B110C(void *, int);
extern int ResourceEntry_GetName(void *);
extern void Abend_Panic(const char *, ...);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void *fn_802B2958(void *arg0, void *arg1) {
    char *base = lbl_8034A288;
    char *p = (char *)fn_801284F8(12, base + 0x70);
    void *item, *child;
    const char *name;
    int key, value, valid;
    char *obj = (char *)arg0;
    float *entry;
    float radius, angle;
    double one, zero, cosine, sine, negSine;
    unsigned int i;
    if (p != 0) {
        name = ((ParticleConfig *)arg1)->getText(lbl_8055CDE0);
        *(int *)(p + 8) = -2;
        if (stricmp(name, lbl_8055CDE8) == 0) {
            *(void **)p = 0;
        } else {
            item = ((void *(*)(void *, void *))fn_802B2C34)((void *)fn_802C6B44, (void *)name);
            *(void **)p = item;
            if (item != 0) {
                child = *(void **)((char *)item + 4);
                key = ResourceEntry_GetName(child);
                value = *(int *)((char *)child + 12);
                valid = 0;
                if (value != 0) {
                    *(int *)(p + 8) = ((int (*)(void *, int))fn_802B110C)((void *)fn_802B1D38, key);
                    if (*(int *)(p + 8) == -2)
                        Abend_Panic(base + 0x80, key);
                    *(int *)(p + 4) = value;
                    valid = 1;
                }
                if (!valid) Abend_Panic(base + 0xA0, name);
            } else {
                Abend_Panic(base + 0xE4, name);
            }
        }
    }
    *(void **)(obj + 12) = p;
    *(int *)(obj + 0x14) = 0;
    *(int *)(obj + 0x10) = 0;
    *(int *)obj = ((ParticleConfig *)arg1)->getInt(lbl_8055CDEC, 1);
    *(const char **)(obj + 0x2A4) = ((ParticleConfig *)arg1)->getText(lbl_8055CDE0);
    *(float *)(obj + 8) = ((ParticleConfig *)arg1)->getFloat(base + 0x104, lbl_80564C00);
    *(float *)(obj + 0x298) = ((ParticleConfig *)arg1)->getFloat(base + 0x110, lbl_80564C04);
    *(float *)(obj + 0x29C) = ((ParticleConfig *)arg1)->getFloat(base + 0x11C, lbl_80564C04);
    *(char *)(obj + 4) = ((ParticleConfig *)arg1)->getBool(base + 0x128, 0);
    entry = (float *)(obj + 0x18);
    zero = 0.0;
    one = 1.0;
    for (i = 0; i < 16; i++, entry += 10) {
        entry[9] = ((float (*)(int, float, float))fn_80129DC4)(0, *(float *)(obj + 0x298), *(float *)(obj + 0x29C));
        angle = ((float (*)(int, float, float))fn_80129DC4)(0, lbl_80564C00, lbl_80564C08);
        cosine = (float)cos(angle);
        sine = (float)sin(angle);
        negSine = -sine;
        radius = entry[9];
        entry[0] = (float)cosine * radius;
        entry[1] = (float)zero * radius;
        entry[2] = (float)negSine * radius;
        radius = entry[9];
        entry[3] = (float)zero * radius;
        entry[4] = (float)one * radius;
        entry[5] = (float)zero * radius;
        radius = entry[9];
        entry[6] = (float)sine * radius;
        entry[7] = (float)zero * radius;
        entry[8] = (float)cosine * radius;
    }
    *(char *)(obj + 0x2A0) = 0;
    return obj;
}
#pragma pop

#pragma scheduling invalid_target
/* Generic trampoline: invoke `callback` with `arg`. Callers cast this to other
 * function-pointer types so the same bridge can adapt a callback's signature
 * or return value (e.g. resolving a resource by name through fn_802C6B44). */
void fn_802B2C34(void (*callback)(void *), void *arg) {
    callback(arg);
}
#pragma scheduling invalid_target
void fn_802B2D94(int *arg0) {
    int *container = arg0;
    int i;
    lbl_8055F9B4 = 0;
    lbl_8055F9B0 = 0;
    i = 0;
    goto check;
loop:
    fn_802B2E08(*fn_802B320C(container, i));
    i++;
check:
    if (i < fn_802B2E00(container)) {
        goto loop;
    }
}
#pragma scheduling on
#pragma push
#pragma dont_inline on
/* Return the element count at +4 of a container (whose base pointer is at +0). */
int fn_802B2E00(void *container) {
    return ((int *)container)[1];
}
#pragma pop

extern double cos(float);
extern double sin(float);
extern double fn_8002EFB4(float, double);
extern float fn_80129DC4(float, float);
extern float fn_801E7E18(void);
extern void fn_801F1C24(float *);
extern void fn_802C28C0(void);
extern void fn_802C8BD0(void);
extern void DrawList_RestoreNormalMode(void);
extern void fn_802DC71C(int, int);
extern void fn_802DC8B4(void);
extern void fn_802DCAE4(int, float *, void *, void *, float);
extern float lbl_80564C00, lbl_80564C04, lbl_80564C08;
extern float lbl_80564C0C, lbl_80564C10, lbl_80564C20;
extern double lbl_80564C18, lbl_80564C28;
#pragma push
#pragma processor 750
int fn_802B2E08(int arg0) {
    char *base, *obj, *transform;
    register float *entry;
    char *head;
    float stack[28];
    double conversion;
    float scaleX, scaleY, scaleZ, normal, vertical;
    float angle, radial, radius, x, x2, yz, x3;
    float product0, product1;
    double cosine, sine, negSine;
    float phase, phase2, scale;
    register int arrayOffset, j, index;
    int zero, eight, row, byteOffset, n;
    unsigned char *data, *record;
    unsigned short selector;

    base = (char *)arg0;
    conversion = lbl_80564C28;
    scaleX = lbl_80564C0C;
    index = 0;
    scaleY = lbl_80564C10;
    scaleZ = lbl_80564C20;
    arrayOffset = 0;
    normal = lbl_80564C00;
    vertical = lbl_80564C04;
    zero = 0;
    eight = 8;
    goto outer_check;

outer_body:
    obj = *(char **)(*(char **)(base + 0x408) + arrayOffset);
    head = *(char **)(obj + 0x10);
    if (head != 0) {
        if (*(unsigned char *)(obj + 0x2A0) != 0) {
            double drad = normal;
            double dvert = vertical;
            entry = (float *)(obj + 0x18);
            radial = (float)drad;
            vertical = (float)dvert;
            j = 0;
            do {
                radius = ((float (*)(int, float, float))fn_80129DC4)(
                    0, *(float *)(obj + 0x298), *(float *)(obj + 0x29C));
                entry[9] = radius;
                angle = ((float (*)(int, float, float))fn_80129DC4)(
                    0, lbl_80564C00, lbl_80564C08);
                cosine = (float)cos(angle);
                sine = (float)sin(angle);
                negSine = -sine;
                x = entry[9];
                j++;
                product1 = radial * x;
                product0 = (float)cosine * x;
                entry[0] = product0;
                entry[1] = product1;
                entry[2] = (float)negSine * x;
                x2 = entry[9];
                yz = radial * x2;
                entry[3] = yz;
                entry[4] = vertical * x2;
                entry[5] = yz;
                x3 = entry[9];
                entry[6] = (float)sine * x3;
                entry[7] = radial * x3;
                entry[8] = (float)cosine * x3;
                entry += 10;
            } while ((unsigned int)j < 16u);
            *(unsigned char *)(obj + 0x2A0) = (unsigned char)zero;
        }

        if (*(unsigned char *)(obj + 4) != 0) {
            fn_801F1C24(stack);
            entry = (float *)(obj + 0x18);
            {
                volatile float *vEntry = (volatile float *)entry;
                for (j = 0; j < eight; j++) {
                    scale = vEntry[9];
                    entry[0] = stack[0] * scale;
                    entry[1] = stack[1] * scale;
                    entry[2] = stack[2] * scale;
                    scale = vEntry[9];
                    entry[3] = stack[3] * scale;
                    entry[4] = stack[4] * scale;
                    entry[5] = stack[5] * scale;
                    scale = vEntry[9];
                    entry[6] = stack[6] * scale;
                    entry[7] = stack[7] * scale;
                    entry[8] = stack[8] * scale;
                    scale = vEntry[19];
                    entry[10] = stack[0] * scale;
                    entry[11] = stack[1] * scale;
                    entry[12] = stack[2] * scale;
                    scale = vEntry[19];
                    entry[13] = stack[3] * scale;
                    entry[14] = stack[4] * scale;
                    entry[15] = stack[5] * scale;
                    scale = vEntry[19];
                    entry[16] = stack[6] * scale;
                    entry[17] = stack[7] * scale;
                    entry[18] = stack[8] * scale;
                    entry += 20;
                    vEntry = (volatile float *)entry;
                }
            }
        } else if (*(float *)(obj + 8) > normal) {
            phase = fn_801E7E18();
            phase2 = scaleZ * phase;
            entry = (float *)(obj + 0x18);
            j = 0;
            do {
                angle = (float)fn_8002EFB4(
                    (scaleX * (float)j) / scaleY + phase, lbl_80564C18);
                sine = (float)sin(angle);
                entry[3] = *(float *)(obj + 8) * (float)sine;
                angle = (float)fn_8002EFB4(
                    (scaleX * (float)j) / scaleY + phase2, lbl_80564C18);
                cosine = (float)cos(angle);
                j++;
                entry[5] = *(float *)(obj + 8) * (float)cosine;
                entry += 10;
            } while ((unsigned int)j < 16u);
        }

        fn_802C28C0();
        fn_802C8BD0();
        fn_802DC71C(*(int *)(*(char **)(obj + 0xC) + 4),
                    *(int *)(*(char **)(obj + 0xC) + 8));
        do {
            n = *(int *)(head + 4);
            row = 0;
            byteOffset = 0;
            while (row < n) {
                data = *(unsigned char **)head;
                record = data + byteOffset;
                stack[21] = *(float *)(record + 4);
                stack[22] = *(float *)(record + 8);
                stack[23] = *(float *)(record + 0xC);
                selector = *(unsigned short *)record;
                transform = obj + ((selector & 0xF) * 0x28);
                ((ParticleVec3 *)(stack+12))[0] = ((ParticleVec3 *)(transform+0x18))[0];
                ((ParticleVec3 *)(stack+12))[1] = ((ParticleVec3 *)(transform+0x18))[1];
                ((ParticleVec3 *)(stack+12))[2] = ((ParticleVec3 *)(transform+0x18))[2];
                fn_802DCAE4(*(int *)(*(char **)(obj + 0xC) + 4), stack + 12, transform,
                            record, *(float *)(record + 0x10));
                byteOffset += 0x14;
                row++;
            }
            head = *(char **)(head + 0xC);
        } while (head != 0);
        fn_802DC8B4();
        DrawList_RestoreNormalMode();
    }
    arrayOffset += 4;
    index++;
outer_check:
    if (index < *(int *)(base + 0x40C))
        goto outer_body;
}
#pragma pop
#pragma push
#pragma dont_inline on
/* Pointer to the 32-bit element at `index` in the array whose base pointer is stored at `basePtr`. */
int *fn_802B320C(int *basePtr, int index) {
    return (int *)((char *)*basePtr + index * 4);
}
#pragma pop

extern char lbl_8034A3BC[];
extern void fn_802E30C8(const char *, ...);
#pragma scheduling invalid_target
void fn_802B321C(int *outList, int *outLayer, int *layers, int layerIndex)
{
    /* GetTweakers: fill the output work list with the tweaker records of the
     * requested layer and hand back that layer's payload pointer; report the
     * request and bail out if the layer index is out of range. */
    int layer;
    int *tweaker;
    int i;
    int offset;

    if (layerIndex >= 0 && layerIndex < layers[1]) {
        layer = *(int *)(*layers + layerIndex * 4);
        if (outList != 0) {
            i = 0;
            offset = 0;
            while (i < *(int *)(layer + 0x40C) &&
                   outList[1] + 1 <= outList[2]) {
                i++;
                tweaker = *(int **)(*(int *)(layer + 0x408) + offset);
                offset += 4;
                {
                    int *dst = (int *)((char *)outList[0] + outList[1]++ * 0xC);
                    dst[0] = *(int *)((char *)tweaker + 0x2A4);
                    dst[1] = (int)tweaker;
                    dst[2] = (int)((char *)tweaker + 0x298);
                }
            }
        }
        if (outLayer != 0)
            *outLayer = layer + 4;
        return;
    }
    fn_802E30C8(lbl_8034A3BC, layerIndex, 0, layers[1]);
}
int fn_802B2E00(void *);
int *fn_802B320C(int *, int);
#pragma dont_inline reset
int fn_802B2E08(int);
extern int lbl_8055F9B4;
extern int lbl_8055F9B0;
int fn_802B3340(int);
#pragma dont_inline on
#pragma dont_inline reset
/* Applies fn_802B3340 to each element in the container. */
void fn_802B32E0(int *arg0) {
    int *container = arg0;
    int i = 0;
    goto check;
loop:
    fn_802B3340(*fn_802B320C(container, i));
    i++;
check:
    if (i < fn_802B2E00(container)) {
        goto loop;
    }
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma ctrloop on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma scheduling invalid_target
int fn_802B3340(int arg) {
    unsigned char *p = (unsigned char *)arg;
    int sp420[128];
    volatile int sp41C;
    volatile int sp418;
    volatile int *sp414;
    int sp214[128];
    int sp210;
    volatile int sp20C;
    volatile int *sp208;
    int sp8[128];
    int total, remain, dbl, idx, k, pos, i;
    int **list;

    if (p[5] != p[4]) {
        total = 0;
        i = *(int *)((char *)p + 0x40C);
        for (list = *(int ***)((char *)p + 0x408); i > 0; i--) total += *list[0], list++;
        if (total > 0x80) {
            int count = *(int *)((char *)p + 0x40C);
            idx = fn_80129D90(0, 0, count);
            do {
                int *q = (*(int ***)((char *)p + 0x408))[idx];
                if (*q > 0) { *q = *q - 1; total--; }
                idx = (idx + 1) % count;
            } while (total > 0x80);
        }
        memset((char *)p + 0x208, 0, 0x200);
        remain = 0x80 - total;
        dbl = remain * 2;
        pos = 0;
        for (k = 0; k < *(int *)((char *)p + 0x40C); k++) {
            int *obj = (*(int ***)((char *)p + 0x408))[k];
            int lim = dbl / *(int *)((char *)p + 0x40C);
            int c, j;
            if (lim > remain) lim = remain;
            if (lim > 0) {
                int n = *(int *)((char *)p + 8 + ((k & 0x7F) << 2)) % lim;
                for (j = 0; j < n; j++) *(void **)((char *)p + 0x208 + (pos++ << 2)) = 0;
                remain -= n;
            }
            c = *obj;
            for (j = 0; j < c; j++) *(void **)((char *)p + 0x208 + (pos++ << 2)) = obj;
        }
        if (p[4] == 0) fn_802B28BC((int *)((char *)p + 0x208), 0x80);
    } else {
        sp41C = 0x80;
        sp414 = &sp420[0];
        sp418 = 0;
        sp208 = &sp214[0];
        sp210 = 0x80;
        sp20C = 0;
        memcpy(sp8, (char *)p + 0x208, 0x200);
        total = 0;
        i = *(int *)((char *)p + 0x40C);
        for (list = *(int ***)((char *)p + 0x408); i > 0; i--) total += *list[0], list++;
        if (total > 0x80) {
            int count = *(int *)((char *)p + 0x40C);
            idx = fn_80129D90(0, 0, count);
            do {
                int *q = (*(int ***)((char *)p + 0x408))[idx];
                if (*q > 0) { *q = *q - 1; total--; }
                idx = (idx + 1) % count;
            } while (total > 0x80);
        }
        memset((char *)p + 0x208, 0, 0x200);
        remain = 0x80 - total;
        dbl = remain * 2;
        pos = 0;
        for (k = 0; k < *(int *)((char *)p + 0x40C); k++) {
            int *obj = (*(int ***)((char *)p + 0x408))[k];
            int lim = dbl / *(int *)((char *)p + 0x40C);
            int c, j;
            if (lim > remain) lim = remain;
            if (lim > 0) {
                int n = sp8[k & 0x7F] % lim;
                for (j = 0; j < n; j++) sp8[pos++] = 0;
                remain -= n;
            }
            c = *obj;
            for (j = 0; j < c; j++) sp8[pos++] = (int)obj;
        }
        if (p[4] == 0) fn_802B28BC((int *)((char *)p + 0x208), 0x80);
        {
            int ctr = 16;
            int *src = sp8;
            do {
                sp414[sp418++] = src[0];
                sp414[sp418++] = src[1];
                sp414[sp418++] = src[2];
                sp414[sp418++] = src[3];
                sp414[sp418++] = src[4];
                sp414[sp418++] = src[5];
                sp414[sp418++] = src[6];
                sp414[sp418++] = src[7];
                src += 8;
            } while (--ctr);
        }
        {
            int ctr = 16;
            char *q = (char *)p + 0x208;
            do {
                sp208[sp20C++] = *(int *)q;
                sp208[sp20C++] = *(int *)(q + 4);
                sp208[sp20C++] = *(int *)(q + 8);
                sp208[sp20C++] = *(int *)(q + 0xC);
                sp208[sp20C++] = *(int *)(q + 0x10);
                sp208[sp20C++] = *(int *)(q + 0x14);
                sp208[sp20C++] = *(int *)(q + 0x18);
                sp208[sp20C++] = *(int *)(q + 0x1C);
                q += 0x20;
            } while (--ctr);
        }
        {
            int m = 0, found, j;
            while (m < sp418) {
                found = -1;
                for (j = 0; j < sp20C; j++) {
                    if ((unsigned)sp208[j] == (unsigned)sp414[m]) { found = j; break; }
                }
                if (found != -1) {
                    if (found != sp20C - 1) sp208[found] = sp208[sp20C - 1];
                    sp20C--;
                    if (m != sp418 - 1) sp414[m] = sp414[sp418 - 1];
                    sp418--;
                } else {
                    m++;
                }
            }
            i = 0;
            while (sp20C > 0) {
                int idx2 = ((int *)((char *)p + 8))[i];
                if ((unsigned)sp8[idx2] == (unsigned)sp414[0]) {
                    sp8[idx2] = sp208[0];
                    if (sp20C - 1 != 0) sp208[0] = sp208[sp20C - 1];
                    sp20C--;
                    if (sp418 - 1 != 0) sp414[0] = sp414[sp418 - 1];
                    sp418--;
                }
                i = (i + 1) % 128;
            }
        }
        memcpy((char *)p + 0x208, sp8, 0x200);
        sp208 = 0; sp20C = 0; sp210 = 0;
        sp414 = 0; sp418 = 0; sp41C = 0;
    }
    p[5] = p[4];
    return arg;
}
#pragma pop
void *fn_802B3DA4(void *container, int slot, int index) {
    /* Look up a field data pointer by index within a slot; returns 0 if out of range or uninitialized. */
    void *result = 0;
    if (index >= 0 && index < ((int *)container)[1]) {
        void *items = *(void **)container;
        void *entry = (char *)((void **)items)[index] + ((slot & 0x7F) * 4);
        void *obj = *(void **)((char *)entry + 0x208);
        result = 0;
        if (obj != 0) {
            void *inner = *(void **)((char *)obj + 0xC);
            result = 0;
            if (*(int *)inner != 0) {
                result = (char *)obj + 0x10;
            }
        }
    }
    return result;
}

#pragma opt_propagation off
void fn_802B3E00(void *queueArg, void *pos, short value, float weight) {
    extern int lbl_8055F9B8;
    extern void *lbl_8055F9BC;
    /* Append a {value,x,y,z,weight} record to a per-object queue: take a 0x14-byte
     * slot from the tail block, linking in a fresh block from the global node pool
     * (lbl_8055F9BC) when the tail is full; bump lbl_8055F9B8 if no block is free. */
    typedef struct Entry {
        short value; unsigned short padding; float x; float y; float z; float weight;
    } Entry;
    typedef struct Node {
        void *data; volatile int count; int capacity; struct Node *next;
    } Node;
    typedef struct Queue { Node *head; Node *tail; } Queue;
    typedef struct Pool { void *buffer; Node *nodes; volatile int used; int capacity; } Pool;
    Queue *queue = (Queue *)queueArg;
    Node *tail = queue->tail;
    Pool *pool = (Pool *)lbl_8055F9BC;
    Entry *out = 0;
    int index; char *data; Node *node;
    if (tail == 0 || tail->count + 1 > tail->capacity) {
        Node *newNode = 0;
        if (pool->used + 1 <= pool->capacity) {
            newNode = (Node *)((char *)pool->nodes + pool->used++ * 0x10);
            newNode->count = 0; newNode->next = 0;
        }
        if (newNode != 0) {
            if (queue->head == 0) queue->head = newNode;
            { Node *prev = queue->tail; if (prev != 0) prev->next = newNode; }
            queue->tail = newNode; newNode->next = 0;
            node = queue->tail; index = node->count; data = (char *)node->data;
            out = (Entry *)(data + index * 0x14);
            node->count = index + 1;
        }
    } else {
        index = tail->count; data = (char *)tail->data;
        out = (Entry *)(data + index * 0x14);
        tail->count = index + 1;
    }
    if (out != 0) {
        float x = ((float *)pos)[0]; float y = ((float *)pos)[1];
        out->x = x;
        { float z = ((float *)pos)[2]; out->y = y; out->z = z; }
        out->value = value; out->weight = weight;
    } else lbl_8055F9B8 += 1;
}
#pragma opt_propagation reset
/* Return the element count at +4 of a container (whose base pointer is at +0). */
int fn_802B3F0C(void *container) {
    return ((int *)container)[1];
}

typedef struct {
    void *m0;
    void *m4;
    void *m8;
    void *mC;
    void *m10;
    void *m14;
    void *m18;
    void *m1C;
    void *m20;
    void *m24;
    void *m28;
    void *m2C;
    void *m30;
    void *m34;
    void *m38;
    void *m3C;
    void *m40;
    void *m44;
    void *m48;
    void *m4C;
    void *m50;
    void *m54;
    void (*m58)(void);
    int (*m5C)(void);
} Unk802B2C44;

typedef struct Unk802B2C98 {
    void *m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
} Unk802B2C98;
extern Unk802B2C98 lbl_804BE1FC;

extern int lbl_8055F9B8;
extern void *lbl_8055F9BC;

#pragma push
#pragma cplusplus on
extern "C" int fn_802B2C44(void *object) {
    class NamedObject {
    public:
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
        virtual int hasChild();
    };
    /* Return nonzero if the named child exists, via the virtual lookup at
       vtable slot 21 (+0x5C). The child name reaches the virtual method in r4
       from the caller and passes through unchanged (this wrapper takes no
       second argument, so the compiler never overwrites r4). */
    return ((NamedObject *)object)->hasChild() != 0;
}
#pragma cplusplus reset
#pragma pop
#pragma scheduling invalid_target
void fn_802B2C7C(void *object) {
    /* Initialize a collection object: point its items at the inline storage
     * at +0xC, set the element count (+0x4) to 0 and its capacity (+0x8) to 6. */
    *(int *)object = (int)((char *)object + 0xC);
    *(int *)((char *)object + 8) = 6;
    *(int *)((char *)object + 4) = 0;
}
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
#pragma opt_common_subs off
#pragma scheduling invalid_target
/* Look up an entry by name in lbl_804BE1FC and return it, or 0 if not found. */
int fn_802B2C98(char *name) {
    void *table;
    int offset;
    int result;
    int i;

    table = &lbl_804BE1FC;
    result = 0;
    i = 0;
    offset = 0;
    for (; i < *(int *)((char *)table + 4); offset += 4, i++) {
        if (stricmp(name, *(char **)(*(char **)(*(char **)&lbl_804BE1FC + offset) + 0x24)) == 0) {
            result = (int)((void **)*(char **)&lbl_804BE1FC)[i];
            break;
        }
    }
    return result;
}
#pragma scheduling on
#pragma pop
/* Resets per-entry state for all entries in every group of the container and clears the pool's active count and global flag. */
void fn_802B2D24(void *arg0) {
    int i = 0;
    int j;
    int index = 0;
    int innerIndex;
    while (i < ((int *)arg0)[1]) {
        void *cur = *(void **)((char *)*(void **)arg0 + index);
        ((int *)lbl_8055F9BC)[2] = 0;
        j = 0;
        innerIndex = 0;
        while (j < ((int *)cur)[0x103]) {
            void *entry = *(void **)((char *)*(void **)((char *)cur + 0x408) + innerIndex);
            ((int *)entry)[5] = 0;
            ((int *)entry)[4] = 0;
            j++;
            innerIndex += 4;
        }
        index += 4;
        i++;
    }
    lbl_8055F9B8 = 0;
}
