#include "math.h"
typedef int M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
#define M2C_ERROR(msg) ((void)0)
#define M2C_BITWISE(t, v) (v)
extern f32 lbl_805617D4;
extern f64 fn_8002F234(f32, f32, f32);
struct Hit { float x; s32 y; };
typedef struct { float x, y; } V2_;
static inline void sub2_(V2_ *o, const V2_ *p, const V2_ *q) {
    o->x = p->x - q->x;
    o->y = p->y - q->y;
}
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055A070[4];
#define CIRCLE_NAME lbl_8055A070 /* .sdata string "circle" */
__declspec(section ".sdata") extern char lbl_8055A078[];
#define ERASER_NAME lbl_8055A078 /* .sdata string "eraser" */
extern int lbl_8055E29C;
extern int lbl_8055E2A0;
void fn_8015F584(int *arg0);
void fn_8015F5F4(int *arg0);
extern float lbl_805617D0;
int stricmp(const char *, const char *);
void fn_80136594(int *, void *, void *);
void* fn_8015EBF8(void* arg0, s32 arg1) {
    /* Destroy a small struct by clearing its three fields and optionally freeing it. */
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
/* Convert a sample offset from a stream position into frames (1/60 s) relative to the stream base. */
void fn_8015EC50(unsigned short *out, void *stream) {
    int sample;
    fn_80136594(&sample, stream, (char *)out + 4);
    *out = (sample - ((int *)((void **)stream)[11])[7]) / 60;
}

int fn_8015ECC0(void *arg0) {
    register int result = 0;
    register int test = 0;
    if (((int *)arg0)[8] < 1000 && ((unsigned int *)arg0)[6] == 0x54554245) {
        test = 1;
    }
    if (test != 0) {
        if ((float)fabs(((float *)((void **)arg0)[3])[7]) > lbl_805617D0) {
            result = test | 1;
        }
    }
    return result;
}
#pragma dont_inline reset

#pragma push
#pragma auto_inline off
#pragma push
#pragma cplusplus on
/* True when a named scene object's virtual name is "circle" (case-insensitive). */
extern "C" int fn_8015ED18(void **node) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)node)->getName(), (const char *)CIRCLE_NAME) == 0;
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma cplusplus on
/* Returns nonzero when a named scene object's name is "eraser" (case-insensitive). */
extern "C" int fn_8015ED54(void **object) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)object)->getName(), (const char *)ERASER_NAME) == 0;
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma cplusplus on
/* Count how many children of a node have the target name (via fn_8015ED18). */
extern "C" int fn_8015ED90(void **node) {
    class Node {
    public:
        virtual void unused01();
        virtual void unused02();
        virtual void unused03();
        virtual void unused04();
        virtual void unused05();
        virtual void unused06();
        virtual void unused07();
        virtual void unused08();
        virtual void unused09();
        virtual void unused10();
        virtual void unused11();
        virtual void unused12();
        virtual void unused13();
        virtual void unused14();
        virtual void unused15();
        virtual void unused16();
        virtual void unused17();
        virtual void unused18();
        virtual void unused19();
        virtual void unused20();
        virtual void unused21();
        virtual void unused22();
        virtual void **get_child(int);
    };
    int count = 0;
    int index;
    void **child;
    if (node != 0) {
        for (index = 0; (child = ((Node *)node)->get_child(index)) != 0; index++) {
            if (fn_8015ED18(child))
                count++;
        }
    }
    return count;
}

__declspec(section ".sdata") extern char lbl_8055A080[];
__declspec(section ".sdata") extern char lbl_8055A084[];
__declspec(section ".sdata") extern char lbl_8055A08C[];
__declspec(section ".sdata") extern char lbl_8055A090[];
extern char lbl_8032F470[];
extern char lbl_8032F47C[];
extern "C" int strcmp(const char *, const char *);
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma push
#pragma processor 750
/* Parameter registry entries are 0x10 bytes; right/left arrows get a type code. */
#define PARAM_STRIDE 0x10
#define PARAM_TYPE_OFF 0x2
#define PARAM_FLOAT_A_OFF 0x4
#define PARAM_FLOAT_B_OFF 0x8
#define PARAM_VALUE_OFF 0xC
enum {
    PARAM_TYPE_VALUE = 0,
    PARAM_TYPE_LEFT_ARROW = 1,
    PARAM_TYPE_RIGHT_ARROW = 2
};
#define gParamRegistry lbl_8055E29C
#define gArrowValue lbl_805617D4
#define PARAM_KEY_PACKED lbl_8055A080
#define PARAM_KEY_NAME1 lbl_8055A084
#define PARAM_KEY_NAME2 lbl_8055A08C
#define PARAM_KEY_FLOAT lbl_8055A090
#define PARAM_NAME_LEFT lbl_8032F470
#define PARAM_NAME_RIGHT lbl_8032F47C

#pragma use_lmw_stmw off
extern "C" void fn_8015EE14(void **collection, void *stream) {
    /* Registers each qualifying collection item as a 0x10-byte parameter entry: copies its
       packed floats and stream-derived index, then classifies left/right arrows by name. */
    class Collection {
    public:
        virtual void unused01(); virtual void unused02(); virtual void unused03(); virtual void unused04();
        virtual void unused05(); virtual void unused06(); virtual void unused07(); virtual void unused08();
        virtual void unused09(); virtual void unused10(); virtual void unused11(); virtual void unused12();
        virtual void unused13(); virtual void unused14(); virtual void unused15(); virtual void unused16();
        virtual void unused17(); virtual void unused18(); virtual void unused19(); virtual void unused20();
        virtual void unused21(); virtual void unused22(); virtual void *getAt(s32 index);
    };
    class Item {
    public:
        virtual void unused01(); virtual void unused02(); virtual void unused03(); virtual void unused04();
        virtual void unused05(); virtual void unused06(); virtual void unused07(); virtual void unused08();
        virtual void unused09(); virtual void unused10(); virtual void unused11(); virtual void unused12();
        virtual void unused13(); virtual u64 getPacked(const char *key);
    };
    class NamedItem {
    public:
        virtual void unused01(); virtual void unused02(); virtual void unused03(); virtual void unused04();
        virtual const char *getName(const char *key1, const char *key2);
    };
    class FloatItem {
    public:
        virtual void unused01(); virtual void unused02(); virtual void unused03(); virtual void unused04();
        virtual void unused05(); virtual void unused06(); virtual void unused07();
        virtual f32 getFloat(const char *key);
    };
    void *entry;
    if (collection != 0) {
        f32 arrowValue = gArrowValue;
        void *item;
        s32 index = 0;
        while ((item = ((Collection *)collection)->getAt(index)) != 0) {
            if (fn_8015ED18((void **)item) != 0) {
                s32 entryCount;
                void *entryArray;
                int *registry = (int *)gParamRegistry;
                entryCount = registry[1];
                entryArray = *(void **)registry;
                union { u64 bits; f32 floats[2]; } packed;
                registry[1] = entryCount + 1;
                entry = (char *)entryArray + entryCount * PARAM_STRIDE;
                packed.bits = ((Item *)item)->getPacked((const char *)PARAM_KEY_PACKED);
                *(f32 *)((char *)entry + PARAM_FLOAT_A_OFF) = packed.floats[0];
                *(f32 *)((char *)entry + PARAM_FLOAT_B_OFF) = packed.floats[1];
                fn_8015EC50((unsigned short *)entry, stream);
                {
                    const char *name = ((NamedItem *)item)->getName((const char *)PARAM_KEY_NAME1, (const char *)PARAM_KEY_NAME2);
                    if (strcmp(name, PARAM_NAME_LEFT) == 0) {
                        *(u16 *)((char *)entry + PARAM_TYPE_OFF) = PARAM_TYPE_LEFT_ARROW;
                        *(f32 *)((char *)entry + PARAM_VALUE_OFF) = arrowValue;
                    } else if (strcmp(name, PARAM_NAME_RIGHT) == 0) {
                        *(u16 *)((char *)entry + PARAM_TYPE_OFF) = PARAM_TYPE_RIGHT_ARROW;
                        *(f32 *)((char *)entry + PARAM_VALUE_OFF) = arrowValue;
                    } else {
                        *(u16 *)((char *)entry + PARAM_TYPE_OFF) = PARAM_TYPE_VALUE;
                        *(f32 *)((char *)entry + PARAM_VALUE_OFF) = ((FloatItem *)item)->getFloat((const char *)PARAM_KEY_FLOAT);
                    }
                }
            }
            index++;
        }
    }
}
#pragma pop

#pragma cplusplus reset
#pragma pop

extern int fn_8015ED54(void **);
extern void fn_802E30C8(const char *, int, const char *, ...);
extern char lbl_8032F488[];
extern char lbl_8055A080[], lbl_8055A090[], lbl_8055A08C[], lbl_8055A094[];
#pragma push
#pragma cplusplus on
extern "C" void fn_8015EF84(void **arg0) {
    class Root {
    public:
        virtual void unused01(); virtual void unused02(); virtual void unused03(); virtual void unused04();
        virtual void unused05(); virtual void unused06(); virtual void unused07(); virtual void unused08();
        virtual void unused09(); virtual void unused10(); virtual void unused11(); virtual void unused12();
        virtual void unused13(); virtual void unused14(); virtual void unused15(); virtual void unused16();
        virtual void unused17(); virtual void unused18(); virtual void unused19(); virtual void unused20();
        virtual void unused21(); virtual void unused22(); virtual void *getAt(int);
    };
    class Object {
    public:
        virtual void unused01(); virtual void unused02(); virtual void unused03(); virtual void unused04();
        virtual void unused05(); virtual void unused06(); virtual void unused07(); virtual float getRadius(const char *);
        virtual void unused08(); virtual void unused09(); virtual void unused10(); virtual void unused11();
        virtual void unused12(); virtual u64 getPacked(const char *);
    };
    void *obj;
    int found = 0;
    int index;
    if (arg0 == 0)
        goto report;
    index = 0;
    goto fetch;
process:
    if (fn_8015ED54((void **)obj)) {
        union { double d; f32 f[2]; } coords;
        union { u64 bits; double d; } raw;
        volatile f32 differences[2];
        f32 radius;
        f32 radius2;
        int i;
        int offset;
        found++;
        raw.bits = ((Object *)obj)->getPacked(lbl_8055A080);
        coords.d = raw.d;
        radius = ((Object *)obj)->getRadius(lbl_8055A090);
        radius2 = radius * radius;
        i = 0;
        offset = 0;
    inner:
        {
            volatile int *table = (volatile int *)lbl_8055E29C;
            char *array = (char *)table[0];
            char *entry = array + offset;
            f32 dy = coords.f[1] - *(f32 *)(entry + 8);
            f32 dx = coords.f[0] - *(f32 *)(entry + 4);
            f32 dy2 = dy * dy;
            differences[1] = dy;
            f32 dx2 = dx * dx;
            differences[0] = dx;
            if (dx2 + dy2 >= radius2)
                goto advance;
            if (i >= 0 && i < table[1]) {
                int count = table[1];
                int last = count - 1;
                if (i != last) {
                    int lastOffset = last * 16;
                    char *from = array + lastOffset;
                    *(u16 *)(entry + 0) = *(u16 *)(from + 0);
                    *(s16 *)(entry + 2) = *(s16 *)(from + 2);
                    *(int *)(entry + 4) = *(int *)(from + 4);
                    *(int *)(entry + 8) = *(int *)(from + 8);
                    *(f32 *)(entry + 12) = *(f32 *)(from + 12);
                }
                table[1] = count - 1;
            }
            goto inner;
        advance:
            offset += 16;
            i++;
            table = (volatile int *)lbl_8055E29C;
            if (i < table[1])
                goto inner;
        }
    }
    index++;
fetch:
    obj = ((Root *)arg0)->getAt(index);
    if (obj != 0)
        goto process;
report:
    if (found > 0) {
        fn_802E30C8(lbl_8032F488, found, found == 1 ? lbl_8055A08C : lbl_8055A094);
    }
}
#pragma cplusplus reset
#pragma pop

#pragma push
#pragma inline_depth 0
#pragma use_lmw_stmw off
int fn_8015F148(void **arg0, int arg1) {
    /* Count valid tube/track entries across the given node groups. */
    void **groupPtr = arg0;
    int childOffset;
    int validCount = 0;
    int groupIndex;
    int *group;
    int childIndex;
    int groupCount = arg1;
    void *node;
    void *candidate;
    for (groupIndex = 0; groupIndex < groupCount; groupIndex++) {
        group = *(int **)groupPtr;
        if (group != 0) {
            for (childIndex = 0, childOffset = 0; childIndex < group[0]; childOffset += 4, childIndex++) {
                node = *(void **)((char *)((void **)group)[1] + childOffset);
                candidate = *(void **)((char *)node + 0x3C);
                if (fn_8015ECC0(candidate))
                    validCount++;
            }
        }
        groupPtr++;
    }
    return validCount;
}

extern f32 lbl_805617D4, lbl_805617D8, lbl_805617DC, lbl_805617E0;
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
void fn_8015F1E4(void *arg0, void *arg1)
{
  void *inputState;
  f32 x = *((f32 *) (((char *) inputState) + 0x18));
  float new_var;
  f32 z = *((f32 *) (((char *) inputState) + 0x20));
  f32 result[5];
  f32 speed;
  void *state;
  f32 threshold;
  f32 tmp;
  f32 angle;
  result[0] = x;
  result[1] = z;
  speed = (f32) ((double (*)(f32)) fn_8002F234)((x * x) + (z * z));
  state = *((void **) (((char *) arg1) + 0xC));
  tmp = lbl_805617D8 * speed;
  threshold = lbl_805617D4;
  inputState = *((void **) (((char *) arg1) + 0xC));
  new_var = lbl_805617DC;
  dummy_label_423612:
  ;

  ;
  angle = x + (new_var * tmp);
  *((f32 *) (((char *) arg0) + 0xC)) = angle;
  {
    f32 y = *((f32 *) (((char *) state) + 0x1C));
    if (y < threshold)
    {
      f32 delta = (*((f32 *) (((char *) arg1) + 0x28))) - lbl_805617E0;
      result[2] = (*((f32 *) (((char *) state) + 0x24))) + ((*((f32 *) (((char *) state) + 0x18))) * delta);
      result[3] = (*((f32 *) (((char *) state) + 0x28))) + ((*((f32 *) (((char *) state) + 0x1C))) * delta);
      result[4] = (*((f32 *) (((char *) state) + 0x2C))) + ((*((f32 *) (((char *) state) + 0x20))) * delta);
    }
    else
    {
      f32 delta = -((*((f32 *) (((char *) arg1) + 0x28))) - lbl_805617E0);
      result[2] = (*((f32 *) (((char *) state) + 0x24))) + ((*((f32 *) (((char *) state) + 0x18))) * delta);
      result[3] = (*((f32 *) (((char *) state) + 0x28))) + ((*((f32 *) (((char *) state) + 0x1C))) * delta);
      result[4] = (*((f32 *) (((char *) state) + 0x2C))) + ((*((f32 *) (((char *) state) + 0x20))) * delta);
    }
  }
  *((f32 *) (((char *) arg0) + 4)) = result[2];
  *((f32 *) (((char *) arg0) + 8)) = result[4];
  *((u16 *) (((char *) arg0) + 2)) = 0;
}
#pragma pop
void fn_8015F1E4();
extern f64 fn_8002F234(f32, f32, f32);
void fn_8015EC50(unsigned short *, void *);
int fn_8015ECC0(void *);
void fn_8015F1E4(void *, void *);
#pragma scheduling invalid_target
/* Collects valid tube-related entries from a list of node groups into the global entry buffer. */
void fn_8015F320(void **nodeGroups, int groupCount, void *context) {
    void *candidate;
    void **groupPtr = nodeGroups;
    int childOffset;
    int groupIndex;
    int *group;
    int childIndex;
    void *processContext = context;
    int groupLimit = groupCount;
    for (groupIndex = 0; groupIndex < groupLimit; groupPtr++, groupIndex++) {
        group = *(int **)groupPtr;
        if (group != 0) {
            for (childIndex = 0, childOffset = 0; childIndex < group[0]; childOffset += 4, childIndex++) {
                void *node = *(void **)((char *)((void **)group)[1] + childOffset);
                candidate = *(void **)((char *)node + 0x3C);
                if (fn_8015ECC0(candidate)) {
                    int entryIndex;
                    void *entryArray;
                    volatile int *entryRecord = (volatile int *)lbl_8055E29C;
                    entryArray = (void *)entryRecord[0];
                    entryIndex = entryRecord[1]++;
                    node = (char *)entryArray + entryIndex * 0x10;
                    fn_8015F1E4(node, candidate);
                    fn_8015EC50((unsigned short *)node, processContext);
                }
            }
        }
    }
}

#pragma pop
/* Sort comparator: order records by their leading unsigned-short key (used by fn_80265DCC). */
int fn_8015F3EC(unsigned short *lhsKey, unsigned short *rhsKey) {
    return *lhsKey - *rhsKey;
}

extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, int);
extern void fn_80265DCC(void *, int, int, void *);
extern int fn_8015F3EC(unsigned short *, unsigned short *);
extern char lbl_8032F4A0[];
extern int lbl_8055A098, lbl_8055E29C, lbl_8055E2A0;
#pragma push
#pragma scheduling on
void fn_8015F3FC(void *arg0) {
    register int max;
    register int offset;
    register int index;
    register int *src;
    register int i;
    register int outIndex;
    int count;
    int *dst, *array, *out, *items;
    if (*(volatile int *)(lbl_8055E29C + 4) <= 0) return;
    fn_80265DCC(*(void **)lbl_8055E29C, *(volatile int *)(lbl_8055E29C + 4), 0x10, fn_8015F3EC);
    count = (int)(*(unsigned int *)(*(int *)((char *)arg0 + 0x2c) + 0x18) >> 16);
    dst = (int *)fn_801284F8(0x10, lbl_8032F4A0);
    if (!dst) return;
    array = (int *)fn_8012850C(count * 4, (int)&lbl_8055A098);
    dst[0] = (int)array;
    dst[2] = count;
    dst[1] = 0;
    dst[3] = (int)array;
    *(int *)&lbl_8055E2A0 = (int)dst;
    if (count <= 0) return;
    for (i = 0; i < count; i++) {
        index = 0;
        offset = 0;
        max = *(volatile int *)(lbl_8055E29C + 4) - 1;
        while (index < max && *(unsigned short *)((char *)*(int *)lbl_8055E29C + offset) < i) {
            offset += 0x10;
            index++;
        }
        max = *(volatile int *)(lbl_8055E29C + 4) - 1;
        if (index == max && *(unsigned short *)((char *)*(int *)lbl_8055E29C + offset) < i) {
            src = (int *)*(int *)lbl_8055E29C;
            out = *(int **)&lbl_8055E2A0;
            items = (int *)out[0];
            outIndex = out[1];
            out[1] = outIndex + 1;
            items[outIndex] = (int)src;
        } else {
            src = (int *)((char *)*(int *)lbl_8055E29C + offset);
            out = *(int **)&lbl_8055E2A0;
            items = (int *)out[0];
            outIndex = out[1];
            out[1] = outIndex + 1;
            items[outIndex] = (int)src;
        }
    }
}
#pragma pop
void fn_8015F554(void) {
}

void fn_8015F558(void) {
    // Releases the module's two global parameter structures: the derived item-pointer array at
    // lbl_8055E2A0 and the parameter-entry registry (gParamRegistry) at lbl_8055E29C.
    fn_8015F584(&lbl_8055E2A0);
    fn_8015F5F4(&gParamRegistry);
}

void fn_8015F584(int *slot) {
    /* Destroys the object stored at *slot: frees its owned array field,
       clears its first three words, frees the object, and clears the slot. */
    void *object = *(void **)slot;
    if (object != 0) {
        if (object != 0) {
            fn_80128670(((s32 *)object)[3]);
            if (object != 0) {
                ((s32 *)object)[0] = 0;
                ((s32 *)object)[1] = 0;
                ((s32 *)object)[2] = 0;
            }
            fn_80128668(object);
        }
        *(void **)slot = 0;
    }
}

/* Frees the entry record `slot` points at - the module's global one,
   lbl_8055E29C, that fn_8015F670 builds: first the entry array the record owns
   (whose block starts 0x10 before the pointer kept at +0x0C), then the record
   itself, and clears the slot. */
void fn_8015F5F4(int *slot) {
    #define Mem_freeArray  fn_80128670   /* free what fn_8012850C allocated */
    #define Mem_freeObject fn_80128668   /* free what fn_801284F8 allocated */
    /* A record of 0x10-byte entries; +0x0C is the array's own pointer, the
       block behind it holding the allocator's cookie 0x10 bytes earlier. */
    struct EntryRecord {
        int items;     /* 0x00: base of the entry array */
        int usedCount; /* 0x04: entries filled so far */
        int capacity;  /* 0x08: entries the array holds */
        int itemArray; /* 0x0C: the array (cookie at itemArray - 0x10) */
    };
    struct EntryRecord *record = *(struct EntryRecord **)slot;
    if (record != 0) {
        if (record != 0) {
            int itemArray = record->itemArray;
            if (itemArray != 0) {
                Mem_freeArray(itemArray - 0x10);
            }
            if (record != 0) {
                record->items = 0;
                record->usedCount = 0;
                record->capacity = 0;
            }
            Mem_freeObject(record);
        }
        *(void **)slot = 0;
    }
    #undef Mem_freeArray
    #undef Mem_freeObject
}

extern void *fn_80178C9C(void);
extern void **fn_80131810(const char *);
extern void fn_80131818(void **);
extern int fn_8015F148(void **, int);
extern int fn_8015ED90(void **);
extern void fn_8015F320(void **, int, void *);
extern void fn_8015EF84(void **);
extern void fn_8015EE14(void **, void *);
extern void fn_8015F3FC(void *);
extern void *fn_8002F37C(void *, void (*)(void *), void (*)(void *), int, int);
extern void fn_8015F79C(void);
extern char lbl_8032F4AC[], lbl_8032F4B8[];
__declspec(section ".sdata") extern char lbl_8055A0A0[];
extern int lbl_8055A098, lbl_8055E29C;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8015F670(void **arg0, s32 arg1) {
    struct Resource {
        virtual void **get(const char *);
    };
    void **itemObject;
    void *processContext;
    void **resourceHandle;
    s32 entryCount;
    void *entryRecord;
    void *entryArray;

    processContext = fn_80178C9C();
    resourceHandle = fn_80131810(lbl_8032F4AC);
    if (resourceHandle != 0) {
        itemObject = ((Resource *)resourceHandle)->get(lbl_8055A0A0);
    } else {
        itemObject = 0;
    }

    entryCount = fn_8015F148(arg0, arg1);
    entryCount += fn_8015ED90(itemObject);
    if (entryCount > 0) {
        /* Build and populate the global entry record when any entries are found. */
        register const char *recordName = lbl_8032F4B8;
        entryRecord = fn_801284F8(0x10, recordName);
        if (entryRecord != 0) {
            register int arrayAllocSize = (entryCount << 4) + 0x10;
            register int arrayTag = (int)&lbl_8055A098;
            entryArray = fn_8012850C(arrayAllocSize, arrayTag);
            entryArray = fn_8002F37C(entryArray, (void (*)(void *))fn_8015F79C, 0, 0x10, entryCount);
            *(void **)entryRecord = entryArray;
            *(s32 *)((char *)entryRecord + 8) = entryCount;
            *(s32 *)((char *)entryRecord + 4) = 0;
            *(void **)((char *)entryRecord + 0xC) = entryArray;
        }
        lbl_8055E29C = (s32)entryRecord;
        fn_8015F320(arg0, arg1, processContext);
        fn_8015EF84(itemObject);
        fn_8015EE14(itemObject, processContext);
        fn_8015F3FC(processContext);
    }

    if (resourceHandle != 0) {
        fn_80131818(resourceHandle);
    }
}
#pragma cplusplus reset
#pragma pop

void fn_8015F79C(void) {
}



extern f32 lbl_805617D4, lbl_805617E4, lbl_805617E8, lbl_805617EC, lbl_805617F0;
extern const f64 lbl_805617F8;
extern f32 lbl_8056182C;
extern f64 fn_8002F234(f32, f32, f32);
f32 PSVECDotProduct(void *, void *);
#pragma push
#pragma processor 750
#pragma dont_inline on
s32 fn_8015F7A0(s32 arg0, void *arg1, void *arg2) {
    f32 scale = (f32)arg0 * lbl_805617E4;
    f32 dot = PSVECDotProduct(arg1, arg2);
    f32 t = (dot - lbl_805617EC) / lbl_805617F0;
    f32 clamp = lbl_805617E8;
    clamp = (clamp > t) ? t : clamp;
    clamp = (lbl_805617D4 > clamp) ? lbl_805617D4 : clamp;
    return (s32)(-scale + clamp * (scale - -scale));
}
#pragma pop
extern f32 lbl_8055E2A4;
extern f32 lbl_805617DC;
extern f32 lbl_80561808;
extern const f64 lbl_805617F8;
__declspec(section ".sdata") extern const f64 lbl_805617F8;
s32 fn_8015F848(f32 *arg0, f32 farg0) {
    f32 *var_r5;
    f32 *temp_r7;
    f32 *var_r6;
    f32 temp_f2;
    f32 temp_f6;
    f32 threshold;
    f32 spacing;
    f32 multiplier;
    f64 magic;
    s32 temp_r0;
    s32 var_ctr;
    s32 var_r9;
    s32 var_r8;

    var_r5 = arg0;
    var_r8 = -1;
    var_r9 = 0;
    threshold = lbl_8055E2A4;
    spacing = lbl_80561808;
    multiplier = lbl_805617DC;
    magic = *(volatile f64 *)&lbl_805617F8;
    do {
        temp_f6 = *var_r5;
        if (temp_f6 < farg0) {
            if (var_r8 > 0) {
                temp_r0 = var_r8 * 8;
                temp_r7 = (f32 *)((char *)arg0 + temp_r0);
                if ((f32)fabs((double)(*temp_r7 - temp_f6)) < farg0 * multiplier &&
                    threshold * (f32)((double)(var_r9 - var_r8) - magic) < spacing) {
                    var_ctr = (var_r9 + 1) - var_r8;
                    var_r6 = temp_r7;
                    if (var_r8 <= var_r9) {
                        do {
                            temp_f2 = *var_r5;
                            temp_f6 = *temp_r7;
                            if (temp_f6 < temp_f2)
                                temp_f6 = temp_f2;
                            *var_r6 = temp_f6;
                            var_r6 = (f32 *)((char *)var_r6 + 8);
                            temp_r7 = (f32 *)((char *)temp_r7 + 8);
                        } while (--var_ctr != 0);
                    }
                }
            }
            var_r8 = var_r9;
        }
        var_r9 += 1;
        var_r5 = (f32 *)((char *)var_r5 + 8);
    } while (var_r9 < 0x40);
    return ((u32)var_r8 >> 31) ^ 1;
}

extern long lbl_8055E2A8;
extern float lbl_8056180C;
void fn_8015F92C(float *arg0, float farg0)
{
  s32 v;
  s32 i;
  s32 count;
  float value;
  float temp;
  v = lbl_8055E2A8;
  i = 0;
  count = (v / 2) + 1;
  value = farg0;
  arg0 = arg0;
  for (; i < count; i++)
  {
    temp = arg0[64];
    value = (value < temp) ? (value) : (temp);
 temp = arg0[(32 - i) * 2]; value = (value < temp) ? (value) : (temp); arg0 += 2; } { float scale = lbl_8056180C; float current0; float current1; float current2; float current3; float current4; float current5; float current6; float current7; for (i = 0; i < 8; i++) { current0 = (current4 = arg0[0]);
      arg0[0] = current0 + ((current0 - value) * scale);
      current1 = arg0[2];
      arg0[2] = current1 + ((current1 - value) * scale);
      current2 = arg0[4];
      arg0[4] = current2 + ((current2 - value) * scale);
      current3 = arg0[6];
      arg0[6] = current3 + ((current3 - value) * scale);
      current4 = arg0[8];
      arg0[8] = current4 + ((current4 - value) * scale);
      current5 = arg0[10];
      arg0[10] = current5 + ((current5 - value) * scale);
      current6 = arg0[12];
      arg0[12] = current6 + ((current6 - value) * scale);
      current7 = arg0[14];
      arg0[14] = current7 + ((current7 - value) * scale);
      arg0 += 16;
    }

  }
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Finds the next entry index > arg1 in a 0x40-element array of 8-byte records {f32 value, s32 type} whose value is > threshold, stopping at type 1 or returning a type-2 candidate; returns -1 if none. */
s32 fn_8015FA44(void *records, s32 startIndex, f32 threshold) {
    s32 result = -1;
    s32 i;
    if (((s32 *)((char *)records + startIndex * 8))[1] != 1) {
        for (i = startIndex + 1; i < 0x40; i++) {
            void *p = (char *)records + i * 8;
            if (*(f32 *)p > threshold) {
                result = i;
                break;
            }
            if (((s32 *)p)[1] == 1) break;
            if (((s32 *)p)[1] == 2) result = i;
        }
    }
    return result;
}
#pragma scheduling on
/* Finds the previous entry index < startIndex in an array of 8-byte records {f32 value, s32 type} whose value is > threshold, stopping at type 2 or returning a type-1 candidate; returns -1 if none. */
s32 fn_8015FAB8(s32 *records, s32 startIndex, f32 threshold) {
    s32 result = -1;
    s32 i;
    if (records[startIndex * 2 + 1] != 2) {
        for (i = startIndex - 1; i >= 0; i--) {
            if (*(f32 *)&records[i * 2] > threshold) { result = i; break; }
            if (records[i * 2 + 1] == 2) break;
            if (records[i * 2 + 1] == 1) result = i;
        }
    }
    return result;
}
#pragma dont_inline reset
#pragma scheduling reset
extern f32 lbl_80561810;
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8015FB28(void *arg0, void *arg1, void *arg2, int arg3) {
    volatile u32 *dst = (volatile u32 *)arg0;
    volatile u32 *src = (volatile u32 *)arg1;
    volatile f32 *dstFloat = (volatile f32 *)arg0;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word28;
    u32 word24;
    u32 word2C;
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    f32 velocityX;
    f32 velocityY;
    f32 velocityZ;
    f32 scale;
    f32 scaledX;
    f32 scaledY;
    f32 scaledZ;
    f32 positionX;
    f32 positionY;
    f32 positionZ;
    f32 newX;
    f32 newY;
    f32 newZ;

    word18 = src[6];
    word1C = src[7];
    dst[6] = word18;
    word20 = src[8];
    dst[7] = word1C;
    word28 = src[10];
    dst[8] = word20;
    word24 = src[9];
    word2C = src[11];
    dst[9] = word24;
    velocityX = dstFloat[6];
    scale = lbl_80561810;
    dst[10] = word28;
    velocityZ = dstFloat[8];
    scaledX = velocityX * scale;
    velocityY = dstFloat[7];
    dst[11] = word2C;
    scaledZ = velocityZ * scale;
    scaledY = velocityY * scale;
    positionY = dstFloat[10];
    positionX = dstFloat[9];
    newY = positionY + scaledY;
    positionZ = dstFloat[11];
    newX = positionX + scaledX;
    word0 = src[0];
    newZ = positionZ + scaledZ;
    word4 = src[1];
    word8 = src[2];
    wordC = src[3];
    word10 = src[4];
    word14 = src[5];
    dst[0] = word0;
    dst[1] = word4;
    dst[2] = word8;
    dst[3] = wordC;
    dst[4] = word10;
    dst[5] = word14;
    dstFloat[9] = newX;
    dstFloat[10] = newY;
    dstFloat[11] = newZ;
}

extern f32 lbl_80561814, lbl_80561818, lbl_8056181C, lbl_80561820, lbl_80561824, lbl_80561800;
extern void fn_801606B8(void);
extern void *fn_8016060C(void *, void *);
extern void fn_8016025C(void *, void *, float, float, float, float);
extern s32 fn_8016024C(s32, s32);
extern int fn_80160268(int);
extern void fn_80160278(void);
extern void fn_8016027C(void *, float, float);
extern void fn_80160288(void *, void *);
extern f32 fn_8016029C(f32 *, f32 *);
extern void fn_801602B0(void);
extern s32 fn_801602B4(s32);
extern s32 fn_801602BC(s32 *, s32);
extern s32 fn_801602CC(void *);
extern void fn_801602D4(void *, int *, void *, unsigned char, float);
extern void fn_80160230(void *, void *);
extern int fn_8019321C(void *, void *, void *);
extern int fn_8014C75C(int, void *);
extern void fn_8001BA68(void *);
extern int fn_80179650(void);
extern void fn_80179630(int);
extern void fn_8017960C(void);
#pragma scheduling invalid_target
s32 fn_8015FBCC(void *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct Hit table[64];
    u32 sp68[12];
    f32 sp50[6];
    f32 sp40[4];
    s32 sp30[4];
    u8 sp28[8];
    f32 sp18[2];
    f32 sp20[2];
    f32 sp10[2];
    u8 sp8;
    f32 lim, tmp, f1, fv;
    s32 idx, t26, t27, t29, t31, t3;
    void *obj2, *sub;
    s32 *p26;
    struct Hit *hp;
    f32 *fp;
    int ctr, j, n;
    s32 ret = 0;

    if ((void *)lbl_8055E2A0 != (void *)0) {
        obj2 = ((void *(*)(void *))(*(void ***) *(void **)((char *)arg0 + 0x270))[6])(*(void **)((char *)arg0 + 0x270));
        sub = *(void **)((char *)obj2 + 0x2C);
        idx = (*(s32 *)((char *)obj2 + 4) - *(s32 *)((char *)sub + 0x1C)) / 60;
        ((void (*)(void *, void *, void *, int))fn_8015FB28)(sp68, (char *)arg0 + 0x3C, sub, 0x88888889);
        tmp = *(f32 *)((char *)arg0 + 0x25D4) * lbl_80561814;
        lim = (lbl_80561818 > tmp) ? tmp : lbl_80561818;
        sp8 = arg2;
        p26 = (s32 *)((s32 **)lbl_8055E2A0)[0][idx];
        ((void (*)(void *, void *))fn_801606B8)(&sp8, *(void **)lbl_8055E2A0);
        hp = table;
        ctr = 4;
        do {
            for (j = 0; j < 16; j++) { hp->x = lim; hp->y = 0; hp++; }
        } while (--ctr);
        fn_8016060C(sp50, (void *)sp68);
        n = 0;
        do {
            fn_801602D4(table, (int *)p26, sp50, sp8, lim);
            p26 = (s32 *)((char *)p26 + 0x10);
            if ((s32)p26 > fn_801602BC((s32 *)lbl_8055E29C, fn_801602CC((void *)lbl_8055E29C) - 1)) {
                p26 = (s32 *)fn_801602BC((s32 *)lbl_8055E29C, 0);
            }
            n++;
        } while (n < 0x32);
        for (n = 0; n < fn_80179650(); n++) {
            fn_80179630(n);
            fn_8017960C();
            t27 = ((int (*)(void))fn_801602B4)() + 0x24;
            ((void (*)(void *))fn_801602B0)(sp10);
            fn_8016029C(sp10, (f32 *)&sp10[t27]);
            sp30[0] = 0; sp30[1] = 0; sp30[2] = 0;
            *(f32 *)&sp30[3] = 0.0f;
            fn_80160288(&sp30[1], sp10);
            *(f32 *)&sp30[3] = lbl_8056181C;
            fn_801602D4(table, (int *)&sp30, sp50, sp8, lim);
        }
        t26 = fn_8015F848((f32 *)table, lim);
        f1 = ((f32 (*)(f32 *, f32))fn_8015F92C)((f32 *)table, lim);
        if (t26 != 0) {
            if (arg3 != 0) {
                hp = table;
                ctr = 0x10;
                do {
                    hp->x = (hp->x >= lim) ? f1 : lim; hp++;
                    hp->x = (hp->x >= lim) ? f1 : lim; hp++;
                    hp->x = (hp->x >= lim) ? f1 : lim; hp++;
                    hp->x = (hp->x >= lim) ? f1 : lim; hp++;
                    ctr -= 4;
                } while (ctr != 0);
            }
            fn_8016027C(sp18, lbl_805617D4, lbl_805617D4);
            fn_8016027C(sp20, lbl_805617D4, lbl_805617D4);
            t3 = fn_8015F7A0(0x40, (char *)arg0 + 0x118, ((void *(*)(void *))fn_80160278)(sp68));
            t31 = t3 + 0x20;
            if (table[t31].x < lim) {
                t26 = fn_8015FA44(table, t31, lim);
                t27 = fn_8015FAB8((s32 *)table, t31, lim);
                if ((t26 >= 0) && ((t27 < 0) || ((t29 = fn_80160268(t27 - t31)), (fn_80160268(t26 - t31) < t29)))) {
                    fv = (f32)t26;
                    fv = lbl_8055E2A4 * fv;
                    fn_8016025C(sp18, &table, lbl_80561820 + (fv - lbl_80561800 * lbl_805617DC), table[t26 - 1].x, fv, fv);
                    ((void (*)(void *, f32, f32))fn_8016025C)(sp20, lbl_80561820, lbl_805617D4);
                    ret = 1;
                } else if ((t27 >= 0) && ((t26 < 0) || ((t29 = fn_80160268(t27 - t31)), (fn_80160268(t26 - t31) > t29)))) {
                    fv = (f32)t27;
                    fv = lbl_8055E2A4 * fv;
                    fn_8016025C(sp18, &table, (fv - lbl_80561800 * lbl_805617DC) - lbl_80561820, table[t27 + 1].x, fv, fv);
                    ((void (*)(void *, f32, f32))fn_8016025C)(sp20, lbl_80561824, lbl_805617D4);
                    ret = 1;
                }
            } else {
                t29 = fn_80160268(0);
                t29 = 0x20 - t29;
                t3 = fn_8016024C(t29, ((s32)(((u32)lbl_8055E2A8 >> 31) + lbl_8055E2A8) >> 1) + fn_80160268(t3) + 1);
                ctr = t3 - 1;
                j = 1;
                fp = (f32 *)((char *)table + t31 * 8 + 8);
                if (t3 > 1) {
                    do {
                        if (*fp < lim) {
                            t3 = t31 + j;
                            fv = (f32)(t3 - 1);
                            f1 = lbl_8055E2A4 * fv;
                            fn_8016025C(sp18, &table, (f1 - lbl_80561800 * lbl_805617DC) - lbl_80561820, table[t3].x, f1, fv);
                            ((void (*)(void *, f32, f32))fn_8016025C)(sp20, lbl_80561824, lbl_805617D4);
                            ret = 1;
                        } else {
                            t3 = t31 - j;
                            if (table[t3].x < lim) {
                                fv = (f32)(t3 + 1);
                                f1 = lbl_8055E2A4 * fv;
                                fn_8016025C(sp18, &table, lbl_80561820 + (f1 - lbl_80561800 * lbl_805617DC), f1, lbl_8055E2A4, fv);
                                ((void (*)(void *, f32, f32))fn_8016025C)(sp20, lbl_80561820, lbl_805617D4);
                                ret = 1;
                            } else {
                                fp++;
                                j++;
                                ctr--;
                            }
                        }
                    } while (ctr != 0);
                }
            }
            if (ret != 0) {
                ((void (*)(void *))fn_801602B0)(sp28);
                fn_8019321C(sp28, sp18, sp68);
                if (arg1 != 0) fn_8014C75C(arg1, sp28);
                fn_8001BA68(sp40);
                fn_80160230(sp40, sp28);
            }
        }
    }
    return ret;
}
#pragma scheduling on
extern f32 lbl_805617D4;
void fn_80160230(void *dst, void *src) {
    /* Expand a 2-component (x, y) float vector into a 3-component (x, 0, y) vector, with a zero middle component. */
    register f32 y, mid, x;
    x = *(f32 *)((u8 *)src + 0);
    mid = lbl_805617D4;
    y = *(f32 *)((u8 *)src + 4);
    *(f32 *)((u8 *)dst + 0) = x;
    *(f32 *)((u8 *)dst + 4) = mid;
    *(f32 *)((u8 *)dst + 8) = y;
}

#pragma dont_inline on
/* Return the smaller of the two values a and b. */
s32 fn_8016024C(s32 a, s32 b) {
    if (b < a) {
        return b;
    }
    return a;
}

/* Write the two-float pair (x, y) into the output at +0/+4; the remaining arguments are unused. */
void fn_8016025C(void *out, void *context, float x, float y, float unusedA, float unusedB) {
    *(f32 *)((u8 *)out + 0) = x;
    *(f32 *)((u8 *)out + 4) = y;
}

/* Integer absolute value: (value ^ sign) - sign, with sign = value >> 31 (all ones if negative). */
int fn_80160268(int value) {
    int sign;
    sign = value >> 31;
    return (sign ^ value) - sign;
}

void fn_80160278(void) {
}

// Set both components of a 2D vector (two adjacent f32s).
void fn_8016027C(void *vec, f32 x, f32 y) {
    *(f32 *)((u8 *)vec + 0) = x;
    *(f32 *)((u8 *)vec + 4) = y;
}

void fn_80160288(void *dst, void *src) {
    /* Copy one 8-byte pair of words from src to dst. */
    struct Pair { u32 first; u32 second; };
    *(struct Pair *)dst = *(struct Pair *)src;
}

f32 fn_8016029C(f32 *out, f32 *vec) {
    /* Copy a 3D vector's X and Z components (elements 0 and 2) into a 2D vector, returning X. */
    f32 x = vec[0];
    f32 z = vec[2];
    out[0] = x;
    out[1] = z;
    return x;
}

void fn_801602B0(void) {
}

s32 fn_801602B4(s32 object) {
    /* Field-offset helper: return a pointer to the field at +0x3C of the given object. */
    return object + 0x3C;
}

/* Compute the address of the index-th 16-byte record in the array whose base pointer is stored at *arg0 (a ring-buffer header: +0 base pointer, +4 record count). */
s32 fn_801602BC(s32 *header, s32 index) {
    return *header + (index * 0x10);
}

/* Return the record count (+0x4) from a ring-buffer header (+0 base pointer, +4 count). */
s32 fn_801602CC(void *header) {
    return ((s32 *)header)[1];
}
#pragma dont_inline reset

extern float fn_80160588(void *, void *, void *);
extern float fn_801605C8(void *, void *, void *);
extern float lbl_8055E2A4, lbl_805617D4, lbl_805617DC, lbl_805617E8, lbl_80561800, lbl_80561828;
#pragma push
#pragma processor 750
#pragma opt_common_subs off
void fn_801602D4(void *arg0_, int *arg1_, void *arg2_, unsigned char arg3_, float arg4_)
{
  struct Hit *arg0 = (struct Hit *) arg0_;
  void *arg1 = (void *) arg1_;
  void *arg2 = arg2_;
  float new_var;
  float arg3 = arg4_;
  float dist;
  char *desc4 = ((char *) arg1) + 4;
  char *new_var2;
  float low;
  float high;
  float height;
  float pos;
  float t;
  s16 type;
  int first;
  int i;
  int last;
  dist = fn_80160588(arg2, desc4, ((char *) arg2) + 0x10) - (*((float *) (((char *) arg1) + 0xC)));
  if ((dist > lbl_805617D4) && (dist < arg3))
  {
    pos = fn_801605C8(arg2, desc4, ((char *) arg2) + 0x10);
    height = *((float *) (((char *) arg1) + 0xC));
    low = (-lbl_80561800) * lbl_805617DC;
    if ((pos + height) > low)
    {
      high = lbl_80561800 * ((double) lbl_805617DC);
      if ((pos - height) < high)
      {
        type = *((s16 *) (((char *) arg1) + 2));
        switch (type)
        {
          case 0:
            t = low;
            t = pos - height;
            t = (t - low) / (high - t);
            new_var2 = ((char *) arg1) + 0xC;
            t = (t > lbl_805617E8) ? (t) : (lbl_805617E8);
            t = (t < lbl_805617D4) ? (t) : (lbl_805617D4);
            first = (int) (lbl_805617D4 + (t * lbl_80561828));
            t = ((lbl_8055E2A4 + (pos + (*((float *) new_var2)))) - ((-lbl_80561800) * lbl_805617DC)) / ((lbl_80561800 * lbl_805617DC) - ((-lbl_80561800) * lbl_805617DC));
            new_var = lbl_805617E8;
            t = (t > new_var) ? (t) : (lbl_805617E8);
            t = (t < lbl_805617D4) ? (t) : (lbl_805617D4);
            last = (int) (lbl_805617D4 + (t * lbl_80561828));
            break;

          case 2:
            first = 0;
            t = ((pos + lbl_8055E2A4) - low) / (high - low);
            t = (t > lbl_805617E8) ? (t) : (lbl_805617E8);
            t = (t < lbl_805617D4) ? (t) : (lbl_805617D4);
            last = (int) (lbl_805617D4 + (t * lbl_80561828));
            break;

          case 1:
            t = (pos - low) / (high - low);
            t = (t > lbl_805617E8) ? (t) : (lbl_805617E8);
            t = (t < lbl_805617D4) ? (t) : (lbl_805617D4);
            first = (int) (lbl_805617D4 + (t * lbl_80561828));
            last = 0x40;
            break;

          default:
            first = (last = 0);
            break;

        }

        for (i = first; i < last; i++)
        {
          if (dist < arg0[i].x)
          {
            arg0[i].x = dist;
            arg0[i].y = *((s16 *) (((char *) arg1) + 2));
          }
        }

      }
    }
  }
}

float fn_80160588(void * __restrict arg0, void * __restrict arg1, void * __restrict arg2) {
    volatile f32 d[2];
    f32 *a = (f32 *)arg0;
    f32 *b = (f32 *)arg1;
    f32 *c = (f32 *)arg2;
    f32 dx, dy, t0, t1, r;
    dx = b[0] - c[0];
    dy = b[1] - c[1];
    t0 = a[0] * dx;
    t1 = a[1] * dy;
    d[0] = dx;
    r = t0 + t1;
    d[1] = dy;
    return r;
}

#pragma scheduling reset
f32 fn_801605C8(void *arg0, void *arg1, void *arg2) {
    f32 result2;
    f32 result1;
    f32 dy;
    f32 dx;
    f32 y;
    f32 negX;
    f32 sp8;
    f32 spC;
    negX = -*(f32 *)arg0;
    dx = *(f32 *)arg1 - *(f32 *)arg2;
    dy = *(f32 *)((u8 *)arg1 + 4) - *(f32 *)((u8 *)arg2 + 4);
    y = *(f32 *)((u8 *)arg0 + 4);
    result1 = y * dx;
    *(volatile f32 *)&spC = dx;
    result2 = negX * dy;
    *(volatile f32 *)&sp8 = dy;
    return result1 + result2;
}
void *fn_8016060C(void *arg0, void *arg1) {
#pragma scheduling invalid_target
    f32 *dst = (f32 *)arg0;
    f32 *src = (f32 *)arg1;
    f32 x = src[6];
    f32 y = src[8];
    f32 magnitude;
    f32 limit;
    f32 clamped;
    f32 inputX;
    f32 outputX;
    f32 inputY;
    f32 outputY;
    f32 normalizedX;
    f32 normalizedY;
    f32 scale;
    dst[0] = x;
    dst[1] = y;
    magnitude = (f32)fn_8002F234(x * x + y * y, y, x);
    limit = lbl_8056182C;
    if (limit > magnitude)
        clamped = limit;
    else
        clamped = magnitude;
    inputX = src[9];
    scale = lbl_805617E8 / clamped;
    outputX = dst[0];
    inputY = src[11];
    outputY = dst[1];
    dst[4] = inputX;
    normalizedX = outputX * scale;
    dst[5] = inputY;
    normalizedY = outputY * scale;
    dst[0] = normalizedX;
    dst[1] = normalizedY;
    dst[2] = normalizedY;
    dst[3] = -normalizedX;
    return arg0;
}
#pragma scheduling on
void fn_801606B8(void) {
}

