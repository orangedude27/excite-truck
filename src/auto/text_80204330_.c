// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

struct Text80204 {
    int unk_0x0, unk_0x4;
    float y;
    int unk_0xc;
    float unk_0x10;
    int unk_0x14, color, unk_0x1c;
};
extern void fn_80230B5C(void *), fn_802C8638(void *);
extern void fn_802C974C(float, float, float);
extern void fn_80011A2C(void), fn_801476C4(void);
extern int fn_801298E8(void *, int);
extern void fn_80147230(void *, const char *, ...);
extern void fn_801473F8(int, const char *, ...);
extern char lbl_8055B428[8], lbl_8055B430[8], lbl_8055B438[8], lbl_8055B440[8];
extern char lbl_8055B448[4], lbl_8055B44C[8], lbl_8055B454[4], lbl_8055B458[4];
extern char lbl_8055B45C[4], lbl_8055B460[4];
extern float lbl_80563188;
extern void* lbl_8055ED48;
extern int fn_802E2C20(void);
int fn_80204354(void);
extern const float lbl_80563168, lbl_8056316C, lbl_80563170, lbl_80563174, lbl_80563178, lbl_8056317C;
extern double lbl_80563180;
extern char lbl_80488BD0[];
struct Entry80204 { int unk_0x0, unk_0x4, unk_0x8; float unk_0xc, unk_0x10, unk_0x14; };
#pragma dont_inline on
void fn_80204330(void) {
#define getCurrentTime fn_802E2C20
#define sGuiTimestamp  lbl_8055ED48
    /* Stamp the GUI timestamp with the current time when the screen opens. */
    sGuiTimestamp = (void*)getCurrentTime();
#undef sGuiTimestamp
#undef getCurrentTime
}
#pragma dont_inline off

int fn_80204354(void) {
#define getCurrentTime fn_802E2C20
#define sGuiTimestamp  lbl_8055ED48
    /* Return the milliseconds elapsed since the GUI timestamp was set;
     * fn_80204330 stamps it with the current time when the screen opens. */
    return getCurrentTime() - (int)sGuiTimestamp;
#undef sGuiTimestamp
#undef getCurrentTime
}

int fn_802E2C20(void);
extern int fn_80145E70(void*);
extern char lbl_8033BB18[];
extern int lbl_8055ED3C, lbl_8055ED40, lbl_8055ED44;
struct Obj80204 { void (*dtor)(void *, int); };
#pragma cplusplus on
struct Gui80204 {
    virtual void v0();
    virtual void *v1(const char *);
    virtual void v2();
    virtual void *v3(const char *);
    virtual void *v4(const char *);
    virtual void v5();
};
#pragma cplusplus off
#pragma dont_inline on
/* Tune Dash: true while the 3.5-second (3500 ms) intro/lockout window is still
 * active, i.e. the elapsed time since the screen's timestamp (fn_80204354)
 * is below 3500 ms. */
int fn_8020437C(void) {
    return fn_80204354() < 3500;
}
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802043B0(int *arg0) {
    struct ColorBits {
        unsigned int a : 8;
        unsigned int rgb : 24;
    };
    const float scale = -255.0f;
    const float bias = 255.0f;
    int elapsed;
    int *out = arg0;
    float temp;
    float value;
    elapsed = fn_80204354();
    temp = ((float)elapsed - 2500.0f) / 1000.0f;
    value = 1.0f;
    if (value < temp) {
        value = value;
    } else {
        value = temp;
    }
    if (value > 0.0f) {
        value = value;
    } else {
        value = 0.0f;
    }
    *out &= 0xFFFFFF;
    ((struct ColorBits *)out)->a = (int)(bias + value * scale);
}
#pragma pop
/* Start up the Tune Dash tuning screen: clear the entry count, selected row and
 * timestamp, then build the OverlayLayout from "tunedash.val". */
void fn_80204460(void) {
#define sGuiObjectCount lbl_8055ED3C
#define sGuiSelectedRow lbl_8055ED40
#define sGuiTimestamp lbl_8055ED48
#define sGuiObject lbl_8055ED44
#define OverlayLayoutCreate fn_80145E70
#define kLayoutName lbl_8033BB18
    sGuiObjectCount = 0;
    sGuiSelectedRow = 0;
    sGuiTimestamp = 0;
    sGuiObject = OverlayLayoutCreate(kLayoutName);
#undef sGuiObjectCount
#undef sGuiSelectedRow
#undef sGuiTimestamp
#undef sGuiObject
#undef OverlayLayoutCreate
#undef kLayoutName
}

#pragma cplusplus on
extern "C" void fn_8020449C(void) {
    /* Destroys the shared GUI object and resets its state/count. */
#define sGuiObjectCount lbl_8055ED3C
#define sGuiObject lbl_8055ED44
    class Obj {
    public:
        virtual ~Obj();
    };
    sGuiObjectCount = 0;
    delete (Obj *)sGuiObject;
    sGuiObject = 0;
#undef sGuiObjectCount
#undef sGuiObject
}
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" int fn_802044E8(void) {
 char *base = lbl_8033BB18;
 unsigned char input[0x64];
 float matrix[12];
 struct Text80204 label, value;
 int normal, selected;
 int result, count, start, end, i;
 struct Text80204 *a, *b, *c;
 char *area, *entry;
 float step;
 fn_80230B5C(matrix);
 fn_802C8638(matrix);
 fn_802C974C(lbl_80563168, lbl_80563170, lbl_80563188);
 ((Gui80204 *)lbl_8055ED44)->v5();
 result = fn_8020437C();
 if (result) {
  if (lbl_8055ED40 >= 0 && lbl_8055ED40 < lbl_8055ED3C) {
   a = (struct Text80204 *)((Gui80204 *)lbl_8055ED44)->v1(lbl_8055B428);
   b = (struct Text80204 *)((Gui80204 *)lbl_8055ED44)->v1(lbl_8055B430);
   c = (struct Text80204 *)((Gui80204 *)lbl_8055ED44)->v1(lbl_8055B438);
   area = (char *)((Gui80204 *)lbl_8055ED44)->v3(lbl_8055B440);
   if (a && b && c && area) {
    normal = a->color; selected = b->color;
    fn_802043B0(&normal); fn_802043B0(&selected);
    step = b->y - a->y;
    count = (int)(*(float *)(area+0x14)/step);
    label.unk_0x0=a->unk_0x0;
    { int t1=a->unk_0x4; int t2=*(int *)&a->y; label.unk_0x4=t1; *(int *)&label.y=t2; }
    label.unk_0xc=a->unk_0xc; label.unk_0x10=a->unk_0x10; label.unk_0x14=a->unk_0x14; label.color=a->color; label.unk_0x1c=a->unk_0x1c;
    start = lbl_8055ED40 - lbl_8055ED40 % count;
    value.unk_0x0=c->unk_0x0;
    { int t1=c->unk_0x4; int t2=*(int *)&c->y; value.unk_0x4=t1; *(int *)&value.y=t2; }
    value.unk_0xc=c->unk_0xc; value.unk_0x10=c->unk_0x10; value.unk_0x14=c->unk_0x14; value.color=c->color; value.unk_0x1c=c->unk_0x1c;
    entry = lbl_80488BD0 + start*0x18;
    end = start + count;
    for (i=start; i<end && i<lbl_8055ED3C; ++i,entry+=0x18) {
     if (i==lbl_8055ED40) label.color=value.color=selected;
     else label.color=value.color=normal;
     fn_80147230(&label,lbl_8055B448,*(char **)entry);
     switch (*(int *)(entry+4)) {
     case 1: fn_80147230(&value,lbl_8055B44C,**(float **)(entry+8)); break;
     case 0: fn_80147230(&value,lbl_8055B448,**(unsigned char **)(entry+8) ? lbl_8055B454 : lbl_8055B458); break;
     }
     label.y += step; value.y += step;
    }
    if (start >= count) fn_801473F8(lbl_8055ED44,base+0x10,lbl_8055B45C);
    if (end < lbl_8055ED3C) fn_801473F8(lbl_8055ED44,base+0x1c,lbl_8055B460);
   }
  } else fn_801473F8(lbl_8055ED44,lbl_8055B428,base+0x28);
 } else {
  ((Gui80204 *)lbl_8055ED44)->v1(base+0x38);
  fn_801476C4();
  if (fn_801298E8(input,0) && input[0x25]) fn_80204330();
 }
 fn_80011A2C();
 return result;
}
#pragma cplusplus off
#pragma use_lmw_stmw on
#pragma processor gekko
extern int __cntlzw(unsigned int);
int fn_80204870(int arg0) {
    struct Entry {
        int unused;
        int type;
        float *value;
        float lo;
        float hi;
        float step;
    };
    int index;
    struct Entry *rec;
    if (fn_8020437C() != 0) {
        if (arg0 == 0x127)
            goto edit_record;
        if (arg0 >= 0x127)
            goto above_127;
        if (arg0 == 0x125)
            goto edit_record;
        if (arg0 < 0x125)
            goto return_zero;
        goto decrement;
    above_127:
        if (arg0 < 0x129)
            goto increment;
        goto return_zero;
    decrement:
        index = lbl_8055ED40 - 1;
        lbl_8055ED40 = index & ~(index >> 31);
        goto update;
    increment: {
        int limit = lbl_8055ED3C - 1;
        index = lbl_8055ED40 + 1;
        if (limit >= index)
            goto increment_store;
        index = limit;
    increment_store:
        lbl_8055ED40 = index;
        goto update;
    }
    edit_record:
        index = lbl_8055ED40;
        if (index < 0 || index >= lbl_8055ED3C)
            goto return_zero;
        rec = (struct Entry *)lbl_80488BD0 + index;
        switch (rec->type) {
        case 1:
            if ((unsigned int)arg0 == 0x127u) {
                float candidate = *rec->value + rec->step;
                *rec->value = (rec->hi < candidate) ? rec->hi : candidate;
            } else {
                float candidate = *rec->value - rec->step;
                *rec->value = (rec->lo > candidate) ? rec->lo : candidate;
            }
            goto update;
        case 0:
            *(unsigned char *)rec->value = !*(unsigned char *)rec->value;
            goto update;
        default:
            goto return_zero;
        }
    return_zero:
        return 0;
    update:
        fn_80204330();
        return 1;
    }
    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
/* Appends a float slider row (label, value pointer, min, max, step) to the GUI settings menu table. */
void fn_802049DC(int label, int valuePtr, float min, float max, float step) {
#define sGuiEntryCount lbl_8055ED3C
#define sGuiEntries lbl_80488BD0
    int index;
    char *entry;
    int newCount;
    index = sGuiEntryCount;
    if (index >= 0x40) {
        return;
    }
    index = index;
    entry = sGuiEntries + (index * 0x18);
    newCount = index + 1;
    *((int *)(entry + 0)) = label;
    *((int *)(entry + 4)) = 1;
    *((int *)(entry + 8)) = valuePtr;
    *((float *)(entry + 0xC)) = min;
    *((float *)(entry + 0x10)) = max;
    sGuiEntryCount = newCount;
    *((float *)(entry + 0x14)) = step;
#undef sGuiEntryCount
#undef sGuiEntries
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80204A1C(int label, int valuePtr)
{
  /* Append a byte/toggle GUI row: label, value pointer, type flag 0. */
  int index;
  char *entry;
  index = lbl_8055ED3C;
  if (index >= 0x40)
  {
    return;
  }
  index = index;
  entry = lbl_80488BD0 + (index * 0x18);
  *((int *) (entry + 0)) = label;
  lbl_8055ED3C = index + 1;
  *((int *) (entry + 4)) = 0;
  *((int *) (entry + 8)) = valuePtr;
}
#pragma pop
void fn_80204A50(void) {
    fn_80204330();
}
