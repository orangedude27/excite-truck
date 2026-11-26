#pragma push
#pragma cplusplus on
struct Entry8016707C {
    int unk0;
    unsigned char unk4;
    char pad5[0x17];
    float unk1C;
    float unk20;
    char pad24[0x34];
    void *unk58;
};

struct DummySub8016707C {
    char pad[0x24];
    int unk24;
};

class Dummy8016707C {
public:
    virtual void v0();
    virtual void v1();
    virtual DummySub8016707C *v2();
    virtual void v3();
    virtual void *get();
    virtual void v5(int, int);
    virtual void v6();
    virtual void run(int, int);
};
extern "C" {
    double atof(const char *);
    char *strchr(const char *, int);
    float getDifficultySettingFloat(const char *);
    extern char lbl_8055A170, lbl_8055A178, lbl_8055A180, lbl_8055A188;
    extern float lbl_805618A4, lbl_805618A8, lbl_805618AC, lbl_805618B0, lbl_805618B4;
    extern float lbl_805618B8, lbl_805618BC, lbl_805618C0, lbl_805618C4, lbl_805618C8, lbl_805618CC;
}
class Dummy80165B78 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual char *getString(const char *);
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual float getFloat(const char *);
    virtual float getFloatDefault(const char *, float);
    virtual void d9();
    virtual unsigned char getFlag(const char *, int);
    virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20();
    virtual Dummy80165B78 *getObject(const char *);
};
class Dummy80165B78D {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual char *getString(const char *);
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual float getFloat(const char *);
    virtual double getFloatDefaultDouble(const char *, float);
    virtual void d9();
    virtual unsigned char getFlag(const char *, int);
    virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20();
    virtual Dummy80165B78D *getObject(const char *);
};
#pragma cplusplus off
#pragma pop
extern float fn_801660C0(void);
extern int *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(int);
extern void fn_80165FAC(void);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int fn_80204EA0(const char *);
extern void fn_802E30C8(char *, ...);
extern void fn_80163550(int);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void (*)(void *), void *, int, int);
extern float lbl_8055E324;
extern unsigned char lbl_8055E334;
extern char lbl_8055A190;
extern char lbl_8032FCC0[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma small_data off
__declspec(section ".data") extern float lbl_80558DC4;
#pragma pop
extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_80139E18();
extern void *memset(void *, int, unsigned int);
extern unsigned char lbl_8055E32C;
extern float lbl_805618F0;
#define FRAME_TIME_STEP lbl_805618F0 /* ~0.0167s, one 60 Hz frame */
extern float lbl_8055E318;
extern float randFloatInRange(int, float, float, float);

extern unsigned char lbl_8055E32A;
extern unsigned char lbl_8055E32B;
#pragma push
#pragma small_data off
__declspec(section ".data") extern unsigned char lbl_8042FE38;
extern unsigned char lbl_8042FEB0;
#pragma pop
extern float lbl_8056189C;
extern double lbl_80561890;
extern float lbl_8055E320;
extern float fn_8013672C(int);
extern int fn_80179630(int);
extern int getDeitySlot();
extern int fn_80179630(int);
extern int getDeitySlot();
extern float fn_8013672C(int);
extern float lbl_8056189C;
extern double lbl_80561890;
extern unsigned char lbl_8042FE38;
__declspec(section ".data") extern unsigned char lbl_8042FEB0;
extern float lbl_8055E320;
#pragma push
#pragma small_data off
void *fn_80165970(void *self, int shouldDelete) {
    /* Scalar deleting destructor-like helper: clear three fields, then free the object when requested. */
    if (self == 0) goto done;
    if (self == 0) goto after_clear;
    *(int *)self = 0;
    *((int *)self + 1) = 0;
    *((int *)self + 2) = 0;
after_clear:
    if (shouldDelete > 0) fn_80128668(self);
done:
    return self;
}

void fn_801659C8(int subObject) {
    /* Adjust a +0x56C subobject pointer back to its owning TutorialLevel and forward the tutorial-event arguments. */
    fn_80163550(subObject - 0x56C);
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
/* Returns the product of the object's float value and its associated count. */
float fn_801659D0(int obj) {
    float value;
    value = fn_8013672C(obj);
    return value * (float)fn_800081F0(obj);
}
#pragma pop
extern int strcmp(const char *, const char *);
extern float lbl_80561898;
extern float lbl_805618A0;
__declspec(section ".sdata") extern char lbl_8055A150[];
__declspec(section ".sdata") extern char lbl_8055A158[];
#pragma push
#pragma small_data on
__declspec(section ".sdata") extern char lbl_8055A160[];
__declspec(section ".sdata") extern char lbl_8055A168[];
#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_80165A30(void *arg0, int arg1) {
    struct List {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
        virtual void d20(); virtual void d21();
        virtual void *getAt(int);
    };
    struct Entry {
        virtual const char *getName();
        virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6();
        virtual float getValue(const char *);
    };
    float y, x, z;
    void *entry = 0;
    Entry *item = 0;
    int j, count, minusOne;
    List *list;
    *(int *)((char *)&lbl_8042FEB0 + 4) = 0;
    list = (List *)arg0;
    j = 0;
    minusOne = -1;
    goto next_item;
body:
    if (strcmp(item->getName(), lbl_8055A150) == 0) {
        count = *(int *)((char *)&lbl_8042FEB0 + 4);
        void *b = *(void **)&lbl_8042FEB0;
        *(int *)((char *)&lbl_8042FEB0 + 4) = count + 1;
        entry = (char *)b + count * 0x14;
        x = item->getValue(lbl_8055A158);
        y = item->getValue(lbl_8055A160);
        *(float *)entry = item->getValue(lbl_8055A168);
        z = x / 2.0f;
        *(float *)((char *)entry + 4) = y;
        *(float *)((char *)entry + 8) = z;
        *(int *)((char *)entry + 0x10) = minusOne;
        *(float *)((char *)entry + 0xC) =
            lbl_8055E318 - ((float (*)(int, float, float))randFloatInRange)(3, 0.0f, 2.0f * z);
    }
next_item:
    {
        const int idx = ++j;
        item = (Entry *)list->getAt(idx);
    }
    if (item != 0) goto body;
}
#pragma cplusplus reset
#pragma pop
extern double atof(const char *);
extern char *strchr(const char *, int);
extern float getDifficultySettingFloat(const char *);
extern float lbl_805618A4;
extern float lbl_805618A8;
extern float lbl_805618AC;
extern float lbl_805618B0;
extern float lbl_805618B4;
extern float lbl_805618B8;
extern float lbl_805618BC;
extern float lbl_805618C0;
extern float lbl_805618C4;
extern float lbl_805618C8;
extern float lbl_805618CC;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma small_data on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80165B78(void **arg0)
{
  char *strings = lbl_8032FCC0;
  char *match;
  char *text;
  Dummy80165B78 *obj2;
  Dummy80165B78 *obj;
  float scale;
  float value;
  obj = ((Dummy80165B78 *) arg0)->getObject(&lbl_8055A170);
  value = obj->getFloat(strings);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x28)) = value;
  value = obj->getFloat(strings + 0x10);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x2c)) = value;
  value = obj->getFloatDefault(strings + 0x20, lbl_805618A4);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x3c)) = value;
  value = obj->getFloat(strings + 0x30);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x34)) = value;
  value = obj->getFloatDefault(strings + 0x3C, lbl_805618A8);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x38)) = value;
  value = obj->getFloatDefault(strings + 0x50, *((float *) (((char *) (&lbl_8042FE38)) + 0x2c)));
  *((float *) (((char *) (&lbl_8042FE38)) + 0x30)) = value;
  value = obj->getFloatDefault(strings + 0x60, lbl_805618AC);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x44)) = value;
  value = obj->getFloatDefault(strings + 0x70, lbl_805618AC);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x40)) = value;
  value = obj->getFloat(strings + 0x84);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x48)) = value;
  value = obj->getFloatDefault(strings + 0x98, lbl_805618B0);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x64)) = value;
  value = obj->getFloatDefault(&lbl_8055A178, lbl_805618B0);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x68)) = value;
  value = obj->getFloatDefault(strings + 0xA8, lbl_805618B4);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x50)) = value;
  text = obj->getString(strings + 0x84);
  match = strchr(text, 0x4C);
  if (match != 0)
  {
    scale = fn_8013672C((int) match);
    {
      float parsed = (float) atof(text);
      value = parsed * scale;
    }
  }
  else
  {
    value = (float) atof(text);
  }
  *((volatile float *) (0x48 + ((volatile char *) (&lbl_8042FE38)))) = lbl_8055E324 - value;
  *(((volatile unsigned char *) (&lbl_8042FE38)) + 0x4C) = obj->getFlag(strings + 0xC0, 1);
  *(((volatile unsigned char *) (&lbl_8042FE38)) + 0x4D) = obj->getFlag(strings + 0xD8, 1);
  *(((volatile unsigned char *) (&lbl_8042FE38)) + 0x4E) = obj->getFlag(strings + 0xEC, 0);
  obj2 = obj->getObject(strings + 0x100);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x0)) = obj2->getFloat(lbl_8055A168);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x8)) = obj2->getFloat(&lbl_8055A180);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x4)) = obj2->getFloat(lbl_8055A160);
  *((float *) (((char *) (&lbl_8042FE38)) + 0xc)) = obj2->getFloat(&lbl_8055A188);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x10)) = obj2->getFloat(strings + 0x10C);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x14)) = obj2->getFloat(strings + 0x118);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x18)) = obj2->getFloatDefault(strings + 0x124, lbl_805618A8);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x1c)) = obj2->getFloatDefault(strings + 0x134, lbl_805618B8);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x20)) = obj2->getFloatDefault(strings + 0x144, lbl_805618BC);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x24)) = obj2->getFloatDefault(strings + 0x154, lbl_805618C0);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x54)) = getDifficultySettingFloat(strings + 0x164);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x58)) = getDifficultySettingFloat(strings + 0x178);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x5c)) = obj->getFloatDefault(strings + 0x194, lbl_805618C4);
  value = (float) ((Dummy80165B78D *) obj)->getFloatDefaultDouble(strings + 0x1A8, lbl_805618C8);
  *((float *) (((char *) (&lbl_8042FE38)) + 0x60)) = value * lbl_805618CC;
}

#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_80165FAC(void) {
    /* Load the orbit value file, resolve the active orbit subtable, then load its parameters. */
    class Obj {
    public:
        virtual void **method(int) = 0;
    };
    Obj *orbitValueFile;
    int orbitSubtableId;
    void **orbitSubtable;

    orbitValueFile = (Obj *)fn_80131808(lbl_8032FCC0 + 0x1C0);
    orbitSubtableId = fn_80204EA0(lbl_8032FCC0 + 0x1CC);
    fn_802E30C8(lbl_8032FCC0 + 0x1D8, orbitSubtableId);
    orbitSubtable = orbitValueFile->method(orbitSubtableId);
    ((void (*)(void))fn_80165A30)();
    fn_80165B78(orbitSubtable);
    fn_80131818(orbitValueFile);
}
#pragma cplusplus reset
#pragma pop

#pragma cplusplus off
#pragma scheduling on
#pragma pop
#pragma dont_inline on
#pragma scheduling invalid_target
/* Finds the first free slot (0x14-byte entries at lbl_8042FEB0, field +0x10 == -1),
 * marks it with the given id, and returns a pointer to that slot, or NULL if none. */
void *fn_80166040(int id) {
    void *base;
    void *cur;
    void *found;
    int count;
    int i;
    base = *(void **)&lbl_8042FEB0;
    count = *(int *)((char *)&lbl_8042FEB0 + 4);
    cur = base;
    found = 0;
    i = 0;
    while (count > 0) {
        if (*(int *)((char *)cur + 0x10) == -1) {
            found = (char *)base + i * 0x14;
            *(int *)((char *)found + 0x10) = id;
            break;
        }
        cur = (char *)cur + 0x14;
        i++;
        count--;
    }
    return found;
}
#pragma scheduling on
#pragma dont_inline reset
#pragma pop
void fn_80166098(void) {
#define GetPlayerVehicleIndex fn_80179630
#define GetRacerObject        getDeitySlot
    /* Fetch the reference racer object used for relative progress: resolve
     * player 0's vehicle index (-1 clamps to 0), then index the 0x80-byte
     * racer-object table. The object comes back in r3 from the second call,
     * so callers cast this to a void**-returning getter. */
    GetPlayerVehicleIndex(-1);
    GetRacerObject();
#undef GetPlayerVehicleIndex
#undef GetRacerObject
}

#pragma push
#pragma dont_inline on
#pragma cplusplus on
#pragma processor 750
#pragma ppc_psq_save off
#pragma scheduling invalid_target
float fn_801660C0(void) {
    class RacerObject {
    public:
        virtual void v0();
        virtual void v1();
        virtual void *getProgress();
        virtual void unused();
        virtual void *getState();
    };
    /* Compute the reference racer's progress-derived value: (progress count - 1) scaled plus a base offset, clamped to a minimum of zero. */
    RacerObject *racer = (RacerObject *)((void *(*)(void))fn_80166098)();
    int progressCount = *(int *)((char *)racer->getProgress() + 0x10) - 1;
    float scale = ((float (*)(void))fn_8013672C)();
    float value = (float)progressCount * scale + *(float *)((char *)racer->getState() + 0x48);
    if (lbl_8056189C > value) {
        return lbl_8056189C;
    }
    return value;
}
#pragma cplusplus reset
#pragma pop

int fn_8016616C(void) {
    /* Return whether the current progress timer (lbl_8055E320) has exceeded
     * this session's timing threshold at lbl_8042FE38+0x48. */
    return lbl_8055E320 > *(float *)((char *)&lbl_8042FE38 + 0x48);
}

#pragma push
#pragma cplusplus on
#pragma processor 750
extern "C" float fn_8016618C(void *arg0);
extern "C" float fn_8016618C(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void *v2();
        virtual void v3();
        virtual void *v4();
        virtual void v5();
        virtual void *v6();
    };
    /* Compute arg0's progress time relative to the current reference object,
       wrapping by fn_8013672C() when their indices differ, plus lbl_8042FE38+0x58. */
    float result;
    float refProgress;
    float objProgress;
    int objIndex;
    void *refObj;

    refObj = ((void *(*)(void))fn_80166098)();
    refProgress = *(float *)((char *)((Obj *)refObj)->v4() + 0x48);
    objProgress = *(float *)((char *)((Obj *)arg0)->v4() + 0x48);
    objIndex = *(int *)((char *)((Obj *)arg0)->v2() + 4);
    if (*(int *)((char *)((Obj *)refObj)->v2() + 4) < objIndex) {
        if (refProgress < objProgress) refProgress += ((float (*)(void))fn_8013672C)();
        result = objProgress - refProgress;
    } else {
        if (objProgress < refProgress) objProgress += ((float (*)(void))fn_8013672C)();
        result = objProgress - refProgress;
    }
    return result + *(float *)((char *)&lbl_8042FE38 + 0x58);
}
#pragma cplusplus reset
#pragma processor reset
#pragma pop

extern void fn_80128668(void *);
extern void fn_80163550(int);
extern int fn_800081F0(int);
extern int getDeitySlot(void);
extern void *getRegisteredObject(void);
extern float lbl_805618D0;
extern float lbl_805618D4;
#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern "C" float fn_80166274(void) {
    /* Computes a clamped ratio from a virtual object's value and a global scale. */
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void *get(void);
    };
    Obj *object;
    void *data;
    fn_80179630(-1);
    object = (Obj *)getDeitySlot();
    data = object->get();
    fn_80179630(-1);
    {
        void *scaleData = getRegisteredObject();
        float limit = *(float *)((char *)*(void **)((char *)data + 4) + 0x20);
        float value = *(float *)((char *)scaleData + 0x25CC);
        float minLimit = lbl_805618D0;
        minLimit = (minLimit > limit) ? minLimit : limit;
        float ratio = value / minLimit;
        float minRatio = lbl_805618D4;
        minRatio = (minRatio > ratio) ? minRatio : ratio;
        return minRatio;
    }
}
#pragma cplusplus reset
#pragma pop
extern void fn_802E30C8(char *, ...);
extern int __cntlzw(unsigned int);
extern int lbl_8055E330;
extern unsigned char lbl_8055E329;
extern unsigned char lbl_8055E328;
extern float lbl_8055E31C;
extern char lbl_8032FEC0[];
extern char lbl_8032FF08[];
#pragma push
void fn_801662FC(void) {
    int flag;
    int count;
    count = lbl_8055E330;
    flag = ((unsigned char)count == 255);
    lbl_8055E330 = count + 1;
    lbl_8055E329 = flag;
    if (flag) {
        if (lbl_8055E328) {
            if (!((float)__fabs(lbl_8055E31C - lbl_805618D0) <= lbl_80558DC4)) {
                fn_802E30C8(lbl_8032FEC0, lbl_8055E31C, lbl_8055E320, *(float *)((char *)&lbl_8042FE38 + 0x48), fn_80166274());
            } else {
                fn_802E30C8(lbl_8032FF08, lbl_8055E320, *(float *)((char *)&lbl_8042FE38 + 0x48), fn_80166274());
            }
        }
    }
}

#pragma push
extern void *fn_80166754(void *);
#pragma processor gekko
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801663C8(int count, const void *records, const void *config)
{
  typedef struct Entry
  {
    int id;
    signed char flag;
    char pad[0x83];
  } Entry;
  typedef struct Holder
  {
    Entry *entries;
    int used;
    int count;
    Entry *base;
  } Holder;
  typedef struct Record
  {
    int type;
    char pad[0x74];
  } Record;
  char *strings = lbl_8032FCC0;
  void *obj;
  Holder *holder;
  void *array;
  int i;
  float value;
  int notDefault;
  lbl_8055E324 = fn_801659D0((int) config);
  fn_80165FAC();
  obj = *((void **) (((char *) fn_8001285C(*__AXFXGetLfoSinTable_801769CC())) + 0x20));
  value = (*((float (***)(void *, char *, float)) obj))[10](obj, strings + 0x270, *((float *) (((char *) (&lbl_8042FE38)) + 0xC)));
  *((float *) (((char *) (&lbl_8042FE38)) + 0xC)) = value;
  fn_802E30C8(strings + 0x280, *((float *) (((char *) (&lbl_8042FE38)) + 8)), (float) ((double) value), *((float *) (((char *) (&lbl_8042FE38)) + 4)), *((float *) (&lbl_8042FE38)));
  holder = (0, fn_801284F8(16, 0x2A0 + strings));
  if (holder)
  {
    array = fn_8002F37C(fn_8012850C((count * 0x88) + 16, &lbl_8055A190), (void (*)(void *)) fn_80166754, 0, 0x88, count);
    *((void **) holder) = array;
    *((int *) (((char *) holder) + 8)) = count;
    *((int *) (((char *) holder) + 4)) = 0;
    *((void **) (((char *) holder) + 12)) = array;
  }
  *((void **) (&lbl_8055E32C)) = holder;
  *((int *) (((char *) holder) + 4)) = 0;
  for (i = 0; i < count; i++)
  {
    int type = ((Record *) records)[i].type;
    Holder *h = (0, *((Holder **) (&lbl_8055E32C)));
    Entry *p = &h->entries[h->used++];
    p->id = i;
    p->flag = (signed char) (type == 0x50);
  }

  lbl_8055E32A = (notDefault = (*((int *) (((char *) config) + 4))) != 0x180304);
  lbl_8055E32B = 0;
  *((int *) (&lbl_8055E334)) = 0;
}
#pragma processor 750
/* Fill one 0x88-byte LFO/automation entry of the effect list: copy the tuning
 * parameter's initial value, clear the fade fields, and set the LFO bounds from
 * the tuning parameter plus a random half-period from RNG slot 3.  The unused
 * 15.0f local is kept because it holds the compiler's FPR allocation. */
void *fn_80166754(void *entry)
{
  extern unsigned char lbl_8042FE38;
  char *params = (char *) (&lbl_8042FE38);
  float unusedMax;
  float scale;
  float period;
  float lfoAmplitude;
  unsigned int pad;
  *((float *) (((char *) entry) + 0x18)) = *((float *) (params + 0x14));
  unusedMax = 15.0f;
  *((float *) (((char *) entry) + 0x0C)) = 0.0f;
  *((float *) (((char *) entry) + 0x08)) = 0.0f;
  *((float *) (((char *) entry) + 0x14)) = 0.0f;
  *((float *) (((char *) entry) + 0x10)) = 0.0f;
  *((float *) (((char *) entry) + 0x44)) = 0.4f;
  *((float *) (((char *) entry) + 0x38)) = 0.0f;
  *((float *) (((char *) entry) + 0x34)) = 0.0f;
  *((float *) (((char *) entry) + 0x40)) = 0.0f;
  *((float *) (((char *) entry) + 0x3C)) = 0.0f;
  period = ((float (*)(int, float, float)) randFloatInRange)(3, 8.0f, 15.0f);
  lfoAmplitude = *((float *) (params + 0x3C));
  scale = 0.5f;
  *((float *) (((char *) entry) + 0x4C)) = lfoAmplitude;
  *((float *) (((char *) entry) + 0x48)) = -lfoAmplitude;
  *((float *) (((char *) entry) + 0x50)) = period * scale;
  return entry;
}
#pragma processor gekko
/* IsSystemReady gate: returns 1 when the config-driven enable flag is set and
 * the one-shot status latch is still clear, 0 otherwise. */
int fn_801667F0(void) {
    int ready = 0;
    if (lbl_8055E32A) {
        if (!lbl_8055E32B) ready = 1;
    }
    return ready;
}

/* Frees and clears the global resources tracked by lbl_8055E334 and
 * lbl_8055E32C, releasing any embedded buffer before freeing the object. */
void fn_80166814(void) {
    int temp_r3;
    void *temp_r31;

    if (*(void **)&lbl_8055E334 != 0) {
        fn_80139E18(*(void **)&lbl_8055E334);
        *(void **)&lbl_8055E334 = 0;
    }
    temp_r31 = *(void **)&lbl_8055E32C;
    if (temp_r31 != 0) {
        temp_r3 = *(int *)((char *)temp_r31 + 0xC);
        if (temp_r3 != 0) {
            fn_80128670((char *)(temp_r3 - 0x10));
        }
        if (temp_r31 != 0) {
            *(int *)((char *)temp_r31 + 0) = 0;
            *(int *)((char *)temp_r31 + 4) = 0;
            *(int *)((char *)temp_r31 + 8) = 0;
        }
        fn_80128668(temp_r31);
    }
    *(void **)&lbl_8055E32C = 0;
}

extern float lbl_805618A0, lbl_805618D0, lbl_805618E4, lbl_805618E8;
extern void *memset(void *, int, unsigned int);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80166898(void) {
    register float scale;
    float height;
    register float zero;
    register int zeroInt;
    register int i;
    register int j;
    register unsigned int offset;
    unsigned char *p1;
    register unsigned char *p2;
    register unsigned int minusOne;
    register char *countPtr;
    register unsigned char *holder;
    float arg1;
    float arg2;
    float callArg;
    zero = lbl_8056189C;
    zeroInt = 0;
    lbl_8055E32B = zeroInt;
    i = 0;
    height = lbl_805618D0;
    lbl_8055E318 = zero;
    offset = 0;
    scale = lbl_805618A0;
    lbl_8055E320 = zero;
    lbl_8055E31C = zero;
    while (i < *(int *)((char *)*(unsigned char * volatile *)&lbl_8055E32C + 4)) {
        holder = *(unsigned char * volatile *)&lbl_8055E32C;
        p1 = *(unsigned char **)holder + offset;
        arg1 = lbl_805618E4;
        arg2 = lbl_805618E8;
        *(float *)(p1 + 0xC) = height;
        *(float *)(p1 + 8) = height;
        *(float *)(p1 + 0x14) = zero;
        *(float *)(p1 + 0x10) = zero;
        *(float *)(p1 + 0x1C) = lbl_8055E318 + ((float (*)(int, float, float))randFloatInRange)(3, arg1, arg2);
        *(float *)(p1 + 0x20) = zero;
        *(float *)(p1 + 0x24) = height;
        *(float *)(p1 + 0x28) = zero;
        *(float *)(p1 + 0x38) = zero;
        *(float *)(p1 + 0x34) = zero;
        *(float *)(p1 + 0x40) = zero;
        *(float *)(p1 + 0x3C) = zero;
        *(float *)(p1 + 0x54) = lbl_8055E318 - ((float (*)(int, float, float))randFloatInRange)(3, zero, scale * *(float *)(p1 + 0x50));
        *(int *)(p1 + 0x58) = zeroInt;
        p1[0x5C] = zeroInt; p1[0x5E] = zeroInt; p1[0x5D] = zeroInt; p1[5] = zeroInt; p1[0x5F] = zeroInt; p1[0x60] = zeroInt; p1[0x2C] = zeroInt;
        *(float *)(p1 + 0x30) = zero;
        memset(p1 + 0x64, zeroInt, 0x24);
        offset += 0x88;
        i += 1;
    }
    scale = lbl_805618A0;
    countPtr = (char *)&lbl_8042FEB0 + 4;
    offset = zeroInt;
    j = (short)zeroInt;
    minusOne = -1;
    while (j < *(int *)countPtr) {
        callArg = lbl_8056189C;
        p2 = *(unsigned char **)&lbl_8042FEB0 + offset;
        *(int *)(p2 + 0x10) = minusOne;
        *(float *)(p2 + 0xC) = lbl_8055E318 - ((float (*)(int, float, float))randFloatInRange)(3, callArg, scale * *(float *)(p2 + 8));
        j++;
        offset += 0x14;
    }
}
#pragma pop
extern char lbl_8032FF6C[];
extern float lbl_8055E3C8;
extern float fn_801429D0(float, float);
extern float fn_8014C8B4(float, float, float, float, float);
extern float fn_8014C8F8(float, float);
extern void *fn_80156A40(void);
extern void fn_801662FC(void);
extern float fn_80166DD4(void *);
extern void fn_80166E54(void *);
extern void fn_80166E68(float *, float);
extern void fn_80166F3C(float *);
extern int fn_80166F78(float *);
extern float fn_80166F90(float *);
extern void fn_8016707C(void *, void **);
extern float lbl_8055E3C8, lbl_80561898, lbl_805618D0, lbl_805618E0, lbl_805618EC;
#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_80166A24(void) {
    unsigned char *object;
    unsigned int wasActive;
    unsigned char *var_r27;
    int var_r28;
    int var_r29;
    int var_r30;
    unsigned char *temp_r31;
    unsigned char *params;
    float time;
    float delta;
    float emptyValue;
    float previous;
    float firstValue;
    float amount;
    float stateValue;
    int active;

    if (!((int (*)(void))fn_801667F0)()) return;

    wasActive = ((int (*)(void))fn_8016616C)();
    lbl_8055E318 = lbl_8055E3C8;
    lbl_8055E31C = lbl_805618D0;
    if (*((unsigned char *)&lbl_8042FE38 + 0x4D) != 0) {
        lbl_8055E31C *= fn_80166274();
    }
    lbl_8055E320 = fn_801660C0();

    if (((int (*)(void))fn_8016616C)() && !wasActive) {
        if (lbl_8055E328 != 0) {
            fn_802E30C8(lbl_8032FF6C);
        }
        for (var_r28 = 0, var_r27 = 0;
             var_r28 < *(int *)((unsigned char *)(*(unsigned char * volatile *)&lbl_8055E32C) + 4);
             var_r27 += 0x88, var_r28++) {
            object = *(unsigned char * volatile *)(*(unsigned char * volatile *)&lbl_8055E32C) + (int)var_r27;
            time = fn_8016618C((void *)((int (*)(int))getDeitySlot)(*(int *)object));
            object[0x2C] = 1;
            *(float *)(object + 0x30) = time;
        }
    }

    ((void (*)(void))fn_801662FC)();
    previous = lbl_80561898;
    emptyValue = lbl_805618D0;
    var_r28 = 0;
    params = (unsigned char *)&lbl_8042FE38;
    for (var_r30 = 0, var_r29 = 0;
         var_r30 < *(int *)((unsigned char *)(*(unsigned char *volatile *)&lbl_8055E32C) + 4);
         var_r29 += 0x88, var_r30++) {
        temp_r31 = *(unsigned char * volatile *)(*(unsigned char * volatile *)&lbl_8055E32C) + var_r29;
        object = (unsigned char *)((int (*)(int))getDeitySlot)(*(int *)temp_r31);
        fn_8016707C(temp_r31, (void **)object);
        if (*(void **)(temp_r31 + 0x58) != 0) {
            time = fn_8016618C(object);
            *(float *)(temp_r31 + 0x28) = time;
            stateValue = fn_80166F90(*(float **)(temp_r31 + 0x58));
            if (temp_r31[0x2C] != 0) {
                stateValue = *(float *)(temp_r31 + 0x30);
            }
            delta = time - stateValue;

            if (fn_80166F78((float *)(temp_r31 + 0x1C))) {
                firstValue = fn_801429D0(lbl_8056189C, *(float *)(params + 0x10) - previous);
                ((void (*)(float *, float, float))fn_80166F3C)((float *)(temp_r31 + 0x1C), firstValue, previous + *(float *)(params + 0x10));
                amount = fn_8014C8B4(*(float *)&lbl_8042FE38, *(float *)(params + 4), *(float *)(params + 0xC), *(float *)(params + 8), delta);
                active = time > *(float *)(params + 0x18) && time < *(float *)(params + 0x1C);
                temp_r31[5] = active;
                if (active) {
                    amount = ((float (*)(float, float, float))fn_8014C8F8)(amount, *(float *)(params + 0x20), *(float *)(params + 0x24));
                }
                fn_80166E68((float *)(temp_r31 + 8), *(float *)(params + 0x54) + amount * lbl_8055E31C);
            }

            active = 0;
            if (params[0x4C] != 0 && (delta < *(float *)&lbl_8042FE38 || delta > *(float *)(params + 4))) {
                active = 1;
            }
            if (active) {
                fn_80166E54(*(void **)(temp_r31 + 0x58));
            }

            active = delta > *(float *)(params + 0x2C);
            if (delta > *(float *)(params + 0x28) && fn_80166F78((float *)(temp_r31 + 0x20))) {
                if (active) {
                    ((Dummy8016707C *)fn_80156A40())->v5(*(int *)temp_r31, 1);
                } else {
                    ((Dummy8016707C *)fn_80156A40())->v5(*(int *)temp_r31, 0);
                }
                ((void (*)(float *, float, float))fn_80166F3C)((float *)(temp_r31 + 0x20), lbl_805618EC, lbl_805618E0);
            }

            if (active) {
                fn_80166E68((float *)(temp_r31 + 0x34), lbl_805618D0);
            } else {
                fn_80166E68((float *)(temp_r31 + 0x34), lbl_8056189C);
            }
            *(float *)(temp_r31 + 0x24) = fn_80166DD4(temp_r31 + 8);
            temp_r31[0x5D] = delta > *(float *)(params + 0x34);
            temp_r31[0x5C] = delta > *(float *)(params + 0x30);
            temp_r31[0x5E] = delta < *(float *)(params + 0x38);
            temp_r31[0x5F] = delta < *(float *)(params + 0x40);
            temp_r31[0x60] = delta < *(float *)(params + 0x44);
        } else {
            temp_r31[0x5C] = var_r28;
            temp_r31[0x5E] = var_r28;
            temp_r31[0x5D] = var_r28;
            temp_r31[0x5F] = var_r28;
            temp_r31[0x60] = var_r28;
            *(float *)(temp_r31 + 0x24) = emptyValue;
            memset(temp_r31 + 0x64, var_r28, 0x24);
        }
    }
}
#pragma pop
float fn_80166DD4(void *entry) {
    float rangeStart;
    float rangeEnd;
    float outStart;
    float outEnd;
    float normalized;
    float t;
    /* Remap the global input from this entry's input range into its output range, clamping t to [0,1]; a degenerate range returns outStart. */
    rangeEnd = *(float *)((char *)entry + 0xC);
    rangeStart = *(float *)((char *)entry + 8);
    if ((float)__fabs(rangeStart - rangeEnd) <= lbl_80558DC4) return *(float *)entry;
    normalized = (lbl_8055E318 - rangeStart) / (rangeEnd - rangeStart);
    outEnd = *(float *)((char *)entry + 4);
    outStart = *(float *)entry;
    t = lbl_805618D0;
    t = (t < normalized) ? t : normalized;
    t = (t > lbl_8056189C) ? t : lbl_8056189C;
    return outStart + t * (outEnd - outStart);
}

/* Advance this state object's elapsed time (+0xC) by one frame step. */
void fn_80166E54(void *state) {
    *(float *)((char *)state + 0xC) += FRAME_TIME_STEP;
}

/* Retarget a time-based float ramp. The ramp stores {value, target, startTime, endTime, rate}
   in arg0[0..4]. If the target changes, advance toward it from the current interpolated
   value and recompute the end time from the remaining distance and rate. */
void fn_80166E68(float *ramp, float newTarget)
{
  float value;
  float startTime;
  float endTime;
  float oldValue;
  float oldTarget;
  float clampedT;
  float t;
  if (((float) __fabs(newTarget - ramp[1])) <= lbl_80558DC4)
  {
    return;
  }
  startTime = ramp[2];
  endTime = ramp[3];
  if (((float) __fabs(ramp[2] - endTime)) <= lbl_80558DC4)
  {
    value = ramp[0];
  }
  else
  {
    oldTarget = ((volatile float *) ramp)[1];
    oldValue = ramp[0];
    t = (lbl_8055E318 - ramp[2]) / (endTime - ramp[2]);
    clampedT = lbl_805618D0;
    clampedT = (clampedT < t) ? (clampedT) : (t);
    clampedT = (clampedT > lbl_8056189C) ? (clampedT) : (lbl_8056189C);
    value = oldValue + (clampedT * (oldTarget - oldValue));
  }
  ramp[1] = newTarget;
  ramp[0] = value;
  ramp[2] = lbl_8055E318;
  {
    double targetD = newTarget;
    double currentD = value;
    newTarget = ((float)currentD) - ((float)targetD);
    ramp[3] = lbl_8055E318 + ((float)__fabs(newTarget) / ramp[4]);
  }
}

void fn_80166F3C(float *out) {
#define gClock lbl_8055E318
    /* Store the global clock plus a slot-3 random offset; the caller passes the offset range in the incoming float argument registers. */
    *out = gClock + ((float (*)(int))randFloatInRange)(3);
#undef gClock
}

int fn_80166F78(float *time) {
    /* True once the global clock (lbl_8055E318) has passed *time. */
    return lbl_8055E318 > *time;
}

extern double fn_8002EFB4(float, float, float);
extern float lbl_805618A0, lbl_805618F4, lbl_805618F8, lbl_805618FC;
#pragma push
#pragma optimization_level 2
#pragma scheduling on
float fn_80166F90(float * __restrict params) {
    /* Compute a smooth ping-pong interpolation between params[0] and params[1]
     * over time, using params[2] as the half-period and params[3] as the phase offset. */
    float period = 2.0f * params[2];
    float elapsed = lbl_8055E318 - params[3];
    float phase;
    float eased;
    float start;
    float end;
    float term1;
    float term2;
    phase = (float)fn_8002EFB4(elapsed, period, 2.0f);
    if (phase > params[2]) {
        phase = 2.0f * params[2] - phase;
    }
    phase /= params[2];
    if (phase < lbl_805618F4) {
        eased = lbl_805618F4;
    } else if (phase > lbl_805618D0) {
        eased = lbl_805618D0;
    } else if (phase > lbl_8056189C) {
        term1 = lbl_805618F8 * phase;
        term2 = lbl_805618FC * phase;
        term1 *= phase;
        term2 *= phase;
        term1 = phase * term1;
        eased = term1 + term2;
    } else {
        term1 = lbl_805618F8 * phase;
        term2 = lbl_805618FC * phase;
        term1 *= phase;
        term2 *= phase;
        term1 = phase * term1;
        eased = term1 - term2;
    }
    end = params[1];
    start = params[0];
    return start + eased * (end - start);
}

#pragma push
#pragma cplusplus on
extern int fn_801B8570(void);
extern void *fn_80166040(int);
extern float lbl_805618A0, lbl_805618DC, lbl_805618E0, lbl_805618E4;
extern "C" void fn_8016707C(void *arg0, register void **arg1) {
    /* Update this effect entry's active slot and schedule its next event times:
       release and randomize when inactive, or claim a free slot (when allowed)
       and randomize its times. */
    Entry8016707C *entry = (Entry8016707C *)arg0;
    void *slot;
    float randMin;
    float randMax;
    float randValue;
    float scheduledTime;
    float nextRandValue;

    if (entry->unk4 != 0) {
        return;
    }

    fn_80179630(-1);
    if (fn_801B8570() == 0) {
        slot = entry->unk58;
        if (slot != 0) {
            *(int *)((char *)slot + 0x10) = -1;
        }
        entry->unk58 = (void *)0;
        randValue = ((float (*)(int, float, float))randFloatInRange)(3, 2.0f, 5.0f);
        randMax = lbl_805618E0;
        scheduledTime = lbl_8055E318 + randValue;
        randMin = lbl_805618DC;
        entry->unk1C = scheduledTime;
        nextRandValue = ((float (*)(int, float, float))randFloatInRange)(3, randMin, randMax);
        entry->unk20 = lbl_8055E318 + nextRandValue;
        return;
    }

    if (entry->unk58 != 0) {
        return;
    }

    if (((Dummy8016707C *)arg1)->v2()->unk24 != 0) {
        return;
    }

    slot = fn_80166040(entry->unk0);
    {
        void *oldSlot = entry->unk58;
        if (oldSlot != 0) {
            *(int *)((char *)oldSlot + 0x10) = -1;
        }
    }
    entry->unk58 = slot;
    randValue = ((float (*)(int, float, float))randFloatInRange)(3, lbl_805618A0, lbl_805618E4);
    randMax = lbl_805618E0;
    scheduledTime = lbl_8055E318 + randValue;
    randMin = lbl_805618DC;
    entry->unk1C = scheduledTime;
    nextRandValue = ((float (*)(int, float, float))randFloatInRange)(3, randMin, randMax);
    entry->unk20 = lbl_8055E318 + nextRandValue;
}

#pragma pop
/* RealName: Unknown_GetByte5C
 * If the global state is valid, returns the byte at offset +0x5C of the
 * arg0-th 0x88-byte entry in the array pointed to by lbl_8055E32C->items;
 * otherwise returns 0. */
unsigned char fn_801671AC(int index) {
    void *state;
    if (!((int (*)(void))fn_801667F0)()) {
        return 0;
    }
    state = *(void **)&lbl_8055E32C;
    return *((unsigned char *)((char *)*(void **)state + index * 0x88 + 0x5C));
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma optimization_level 2
/* Computes a per-vehicle adjustment factor from the entry's physics record: when the system is ready and both gates pass it derives a delta from the registered vehicle or the AI truck slot, adds it to the record's value and stores it at +0x74; otherwise it stores 0 and returns 1.0. */ extern "C" float computeVehicleFactor(int arg0) {
    /* Compute and return a per-entry value: adjust by a context-dependent delta when gates pass, else store 0 and return base. */
    extern int fn_80139EC4(void *, float, float);
    extern float lbl_80561900;
    extern float lbl_80561904;
    extern float lbl_80561908;
    extern float lbl_8056190C;
    extern double lbl_80561910;
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void *getData();
    };
    register int offset;
    int result;
    float gate1;
    float gate2;
    register void *record;
    void *state;
    void *other;
    void *object;
    float threshold;
    float value;
    float f2;
    float f1;
    float f0;
    float delta;

    if (((int (*)(void))fn_801667F0)() != 0) {
        record = *(void **)&lbl_8055E32C;
        threshold = *(float *)((char *)&lbl_8042FE38 + 0x0c) - lbl_80561900;
        offset = arg0 * 0x88;
        record = (char *)(*(void **)record) + offset;
        value = *(float *)((char *)record + 0x24);
        gate1 = (float)(value > threshold);
        f0 = *(float *)((char *)&lbl_8042FE38 + 0x64);
        f1 = *(float *)((char *)record + 0x28);
        gate2 = (float)(f1 < f0);
        delta = lbl_8056189C;
        if (gate1 != delta && gate2 != delta) {
            if (*(void **)&lbl_8055E334 != 0) {
                other = ((void *(*)(int))getRegisteredObject)(arg0);
                if (*(void **)&lbl_8055E334 != 0) {
                    result = fn_80139EC4(*(void **)&lbl_8055E334,
                                         *(float *)((char *)other + 0x60),
                                         *(float *)((char *)other + 0x68));
                    if (result != 0)
                        delta = lbl_80561898;
                }
            } else {
                object = (void *)((int (*)(int))getDeitySlot)(arg0);
                other = ((Obj *)object)->getData();
                other = *(void **)((char *)other + 4);
                f2 = *(float *)((char *)other + 0x24);
                f1 = lbl_8056189C;
                f0 = (f2 - f1) / lbl_80561904;
                f2 = lbl_805618D0;
                f2 = (f2 < f0) ? f2 : f0;
                f0 = lbl_8056189C;
                f2 = (f2 > f0) ? f2 : f0;
                delta = lbl_80561908 + f2 * lbl_8056190C;
            }
            value += delta;
            state = *(void **)&lbl_8055E32C;
            *(float *)((char *)(*(void **)state) + offset + 0x74) = delta;
        } else {
            *(float *)((char *)record + 0x74) = lbl_8056189C;
        }
        return value;
    }
    return lbl_805618D0;
}
#pragma pop

extern float lbl_805618A0, lbl_8056189C, lbl_805618D0;
extern float lbl_805618F4, lbl_805618F8, lbl_805618FC;

/* One automation entry of the effect list whose holder is lbl_8055E32C (0x88 bytes
 * each; fn_801663C8 allocates the list, fn_80166754 fills the fields below).
 * Only the fields read here are named. */
typedef struct LfoEntry {
    char pad_00[0x34];
    float fadeStartValue; /* +0x34 value before / without the fade */
    float fadeEndValue;   /* +0x38 value once the fade is over */
    float fadeStartTime;  /* +0x3C fade start on the lbl_8055E318 clock */
    float fadeEndTime;    /* +0x40 fade end; equal to the start means no fade */
    float unk44;          /* +0x44 */
    float lfoMin;         /* +0x48 LFO output at its lowest point */
    float lfoMax;         /* +0x4C LFO output at its highest point */
    float lfoPeriod;      /* +0x50 length of one ramp; a full cycle is twice this */
    float lfoPhase;       /* +0x54 clock the LFO was started at */
} LfoEntry;

/* Floats the LFO takes from the small-data pool. */
#define CYCLE_FACTOR lbl_805618A0     /* 2.0f: up+down cycle = 2 * lfoPeriod */
#define FLOAT_ONE lbl_805618D0        /* 1.0f */
#define FLOAT_ZERO lbl_8056189C       /* 0.0f */
#define FLOAT_NEG_ONE lbl_805618F4    /* -1.0f */
#define SMOOTHSTEP_C1 lbl_805618F8    /* -2.0f / 3.0f: smoothstep(t) = -2t^3 + 3t^2 */
#define SMOOTHSTEP_C2 lbl_805618FC
#define CLOCK_EPSILON lbl_80558DC4    /* 2^-15: a time span at or below this is empty */

#pragma push
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
float fn_801673A4(int entryIndex, float *lfoOut) {
    /* Sample automation entry `entryIndex` on the lbl_8055E318 clock: *lfoOut gets
     * its triangle LFO, smoothed with smoothstep and scaled into [+0x48, +0x4C],
     * and the return value is the entry's fade weight, interpolated from +0x34 to
     * +0x38 across +0x3C..+0x40. Both are 0 while the automation list is off. */
    void *holder;
    LfoEntry *entry;
    float ramp, shape, cycleFactor, fadeStart, fadeEnd, fadeFrom, fadeTo;
    float mix, elapsed, phaseStart, period2, clock, term1, term2, lfoFrom, lfoTo, idleValue;

    if (((int (*)(void))fn_801667F0)()) {
        holder = *(void **)&lbl_8055E32C;
        entry = (LfoEntry *)((char *)*(void **)holder + entryIndex * 0x88);
        cycleFactor = CYCLE_FACTOR;
        clock = lbl_8055E318;
        period2 = entry->lfoPeriod;
        phaseStart = entry->lfoPhase;
        period2 = cycleFactor * period2;
        clock -= phaseStart;
        ramp = fn_8002EFB4(clock, period2, cycleFactor); /* fmod into one up/down cycle */

        if (ramp > entry->lfoPeriod)
            ramp = CYCLE_FACTOR * entry->lfoPeriod - ramp; /* second half ramps back down */
        ramp /= entry->lfoPeriod;

        shape = FLOAT_NEG_ONE;
        if (ramp < shape) {
            shape = FLOAT_NEG_ONE;
        } else if (ramp > FLOAT_ONE) {
            shape = FLOAT_ONE;
        } else if (ramp > FLOAT_ZERO) {
            term1 = SMOOTHSTEP_C1 * ramp;
            term2 = SMOOTHSTEP_C2 * ramp;
            term1 *= ramp;
            term2 *= ramp;
            term1 = ramp * term1;
            shape = term1 + term2;
        } else {
            term1 = SMOOTHSTEP_C1 * ramp;
            term2 = SMOOTHSTEP_C2 * ramp;
            term1 *= ramp;
            term2 *= ramp;
            term1 = ramp * term1;
            shape = term1 - term2;
        }

        lfoTo = entry->lfoMax;
        lfoFrom = entry->lfoMin;
        *lfoOut = lfoFrom + shape * (lfoTo - lfoFrom);

        fadeEnd = entry->fadeEndTime;
        fadeStart = entry->fadeStartTime;
        if ((float)__fabs(fadeStart - fadeEnd) <= CLOCK_EPSILON)
            return entry->fadeStartValue;

        fadeTo = entry->fadeEndValue;
        fadeFrom = entry->fadeStartValue;
        mix = FLOAT_ONE;
        elapsed = (lbl_8055E318 - fadeStart) / (fadeEnd - fadeStart);
        if (mix < elapsed) {
            mix = FLOAT_ONE;
        } else {
            mix = elapsed;
        }
        if (mix > FLOAT_ZERO) {
            mix = mix;
        } else {
            mix = FLOAT_ZERO;
        }
        return fadeFrom + mix * (fadeTo - fadeFrom);
    }

    idleValue = FLOAT_ZERO;
    *lfoOut = idleValue;
    return idleValue;
}
#pragma pop
/* Returns the byte at offset 0x5D of the indexed 0x88-byte entry, or 0 if unavailable. */
unsigned char fn_80167544(int index) {
#define IsSystemReady fn_801667F0
#define gSystemData lbl_8055E32C
    void *base;
    if (!((int (*)(void))IsSystemReady)())
        return 0;
    base = *(void **)&gSystemData;
    return *((unsigned char *)((char *)*(void **)base + index * 0x88 + 0x5D));
#undef IsSystemReady
#undef gSystemData
}

/* Returns the byte at offset 0x5E of the indexed 0x88-byte entry, or 0 if unavailable. */
unsigned char fn_80167594(int index) {
    void *systemData;
    if (!((int (*)(void))fn_801667F0)())
        return 0;
    systemData = *(void **)&lbl_8055E32C;
    return *((unsigned char *)((char *)*(void **)systemData + index * 0x88 + 0x5E));
}

/* RealName: Unknown_GetByte5F
 * If the global state is valid, returns the byte at offset +0x5F of the
 * arg0-th 0x88-byte entry in the array pointed to by lbl_8055E32C->items;
 * otherwise returns 0. */
unsigned char fn_801675E4(int index) {
    void *state;
    if (!((int (*)(void))fn_801667F0)()) {
        return 0;
    }
    state = *(void **)&lbl_8055E32C;
    return *((unsigned char *)((char *)*(void **)state + index * 0x88 + 0x5F));
}

unsigned char fn_80167634(int index) {
    /* Returns the byte at offset 0x60 of the indexed 0x88-byte entry, or 0 if unavailable. */
    void *base;
    if (!((int (*)(void))fn_801667F0)())
        return 0;
    base = *(void **)&lbl_8055E32C;
    return *((unsigned char *)((char *)*(void **)base + index * 0x88 + 0x60));
}

extern float lbl_8055E324;

extern char lbl_8032FF8C[];
extern char lbl_8032FFC4[];
#pragma push
#pragma processor 750
void fn_80167684(float arg0) {
    /* Warn once if the player cannot possibly finish within the given remaining time
     * (based on orbit/turtle timing thresholds in lbl_8042FE38 and current progress). */
    float temp_f31;
    if (!lbl_8055E32B && arg0 < *(float *)((char *)&lbl_8042FE38 + 0x5C)) {
        temp_f31 = (lbl_8055E324 - fn_801660C0()) / *(float *)((char *)&lbl_8042FE38 + 0x60);
        if (temp_f31 > arg0) {
            fn_802E30C8(lbl_8032FF8C);
            fn_802E30C8(lbl_8032FFC4, arg0, temp_f31);
            lbl_8055E32B = 1;
        }
    }
}
#pragma pop
/* Returns whether the +0x28 float of the indexed 0x88-byte automation entry
 * (from the lbl_8055E32C effect list) is below the timing threshold at
 * lbl_8042FE38+0x68. */
int fn_80167728(int entryIndex) {
    unsigned char **holder = *(unsigned char ***)&lbl_8055E32C;
    int offset = entryIndex * 0x88;
    unsigned char *items = *holder;
    return *(float *)(items + offset + 0x28) <
           *(float *)((char *)&lbl_8042FE38 + 0x68);
}
#pragma pop
/* Return the orbit-config flag byte at lbl_8042FE38+0x4E, just before the turbo-enabled throttle threshold. */
unsigned char fn_80167758(void) { return *((unsigned char *)&lbl_8042FE38 + 0x4E); }
int fn_80167768(float throttle) {
    /* Return whether the given throttle exceeds the orbit config's
     * "turbo_enabled_throttle" threshold at lbl_8042FE38+0x50 (turbo engages). */
    return throttle > *(float *)((char *)&lbl_8042FE38 + 0x50);
}
#pragma pop
extern float lbl_805618EC;
extern float lbl_805618D8;
extern float lbl_805618DC;
extern float lbl_805618E0;
extern float lbl_8055E318;

extern float randFloatInRange(int, float, float, float);
extern void fn_80128670(void *);
extern void fn_80139E18(void);
extern unsigned char lbl_8055E32C;
extern unsigned char lbl_8055E334;
