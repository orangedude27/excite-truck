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
extern float lbl_80563168, lbl_8056316C, lbl_80563170, lbl_80563174, lbl_80563178, lbl_8056317C;
extern double lbl_80563180;
extern char lbl_80488BD0[];
struct Entry80204 { int unk_0x0, unk_0x4, unk_0x8; float unk_0xc, unk_0x10, unk_0x14; };
#pragma dont_inline on
void fn_80204330(void) {
    lbl_8055ED48 = (void*)fn_802E2C20();
}
#pragma dont_inline off

int fn_80204354(void) { return fn_802E2C20() - (int)lbl_8055ED48; }

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
int fn_8020437C(void) {
    return fn_80204354() < 3500;
}
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802043B0(int *arg0) {
    int elapsed;
    volatile int *out = arg0;
    int original;
    int packed;
    int final_value;
    float temp;
    float value;
    float coefficient;
    float product;
    float offset;
    float result;
    elapsed = fn_80204354();
    temp = ((float)elapsed - lbl_8056316C) / lbl_80563170;
    value = lbl_80563168;
    if (value < temp) {
        value = temp;
    } else {
        value = value;
    }
    if (value > lbl_80563174) {
        value = lbl_80563174;
    } else {
        value = value;
    }
    coefficient = lbl_8056317C;
    original = *out;
    product = value * coefficient;
    offset = lbl_80563178;
    packed = original & 0xFFFFFF;
    *out = packed;
    result = offset + product;
    final_value = (int)result;
    packed |= final_value << 24;
    *out = packed;
}
#pragma dont_inline reset
#pragma pop
void fn_80204460(void) {
    lbl_8055ED3C = 0;
    lbl_8055ED40 = 0;
    lbl_8055ED48 = 0;
    lbl_8055ED44 = fn_80145E70(lbl_8033BB18);
}

#pragma cplusplus on
extern "C" void fn_8020449C(void) {
    class Obj {
    public:
        virtual ~Obj();
    };
    lbl_8055ED3C = 0;
    delete (Obj *)lbl_8055ED44;
    lbl_8055ED44 = 0;
}
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
    label.unk_0x0=a->unk_0x0; label.unk_0x4=a->unk_0x4; *(int *)&label.y=*(int *)&a->y; label.unk_0xc=a->unk_0xc; label.unk_0x10=a->unk_0x10; label.unk_0x14=a->unk_0x14; label.color=a->color; label.unk_0x1c=a->unk_0x1c;
    start = lbl_8055ED40 - lbl_8055ED40 % count;
    value.unk_0x0=c->unk_0x0; value.unk_0x4=c->unk_0x4; *(int *)&value.y=*(int *)&c->y; value.unk_0xc=c->unk_0xc; value.unk_0x10=c->unk_0x10; value.unk_0x14=c->unk_0x14; value.color=c->color; value.unk_0x1c=c->unk_0x1c;
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
extern int __cntlzw(unsigned int);
int fn_80204870(int arg0) {
    register int index;
    register struct Entry80204 *table;
    register int type;
    if (fn_8020437C() == 0)
        goto return_zero;
    if (arg0 == 0x127)
        goto edit_record;
    if (arg0 >= 0x127)
        goto above_127;
    if (arg0 == 0x125)
        goto edit_record;
    if (arg0 >= 0x125)
        goto decrement;
    goto return_zero;
above_127:
    if (arg0 >= 0x129)
        goto return_zero;
    goto increment;
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
    table = (struct Entry80204 *)lbl_80488BD0;
    type = table[index].unk_0x4;
    switch (type) {
    case 1:
        if ((unsigned int)arg0 == 0x127u) {
            register float *value = (float *)(unsigned int)table[index].unk_0x8;
            float step = table[index].unk_0x14;
            float current = *value;
            float bound = table[index].unk_0x10;
            float candidate = current + step;
            float result;
            if (bound < candidate)
                result = bound;
            else
                result = candidate;
            *value = result;
        } else {
            register float *value = (float *)(unsigned int)table[index].unk_0x8;
            float step = table[index].unk_0x14;
            float current = *value;
            float bound = table[index].unk_0xc;
            float candidate = current - step;
            float result;
            if (bound > candidate)
                result = bound;
            else
                result = candidate;
            *value = result;
        }
        break;
    case 0: {
        register unsigned char *value = (unsigned char *)(unsigned int)table[index].unk_0x8;
        *value = (unsigned char)((unsigned int)__cntlzw((unsigned int)*value) >> 5);
        break;
    }
    default:
        goto return_zero;
    }
update:
    fn_80204330();
    return 1;
return_zero:
    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802049DC(int a, int b, float c, float d, float e) {
    int i;
    char *entry;
    int next;
    i = lbl_8055ED3C;
    if (i >= 0x40) {
        return;
    }
    i = i;
    entry = lbl_80488BD0 + (i * 0x18);
    next = i + 1;
    *((int *)(entry + 0)) = a;
    *((int *)(entry + 4)) = 1;
    *((int *)(entry + 8)) = b;
    *((float *)(entry + 0xC)) = c;
    *((float *)(entry + 0x10)) = d;
    lbl_8055ED3C = next;
    *((float *)(entry + 0x14)) = e;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_80204A1C(int arg0, int arg1)
{
  int i;
  char *entry;
  i = lbl_8055ED3C;
  if (i >= 0x40)
  {
    return;
  }
  i = i;
  entry = lbl_80488BD0 + (i * 0x18);
  *((int *) (entry + 0)) = arg0;
  lbl_8055ED3C = i + 1;
  *((int *) (entry + 4)) = 0;
  *((int *) (entry + 8)) = arg1;
}
#pragma pop
void fn_80204A50(void) {
    fn_80204330();
}
