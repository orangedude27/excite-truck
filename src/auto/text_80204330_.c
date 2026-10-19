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
#pragma dont_inline on
unsigned int fn_8020437C(void) {
    int value;
    int masked;
    value = fn_80204354();
    value ^= 0xDAC;
    masked = value & 0xDAC;
    value >>= 1;
    return (unsigned int)(value - masked) >> 31;
}
#pragma dont_inline reset
#pragma dont_inline on
void fn_802043B0(int *arg0) {
 float val = lbl_80563168;
 float temp = ((float)fn_80204354() - lbl_8056316C) / lbl_80563170;
 int packed;
 if (val < temp) val = temp;
 if (val > lbl_80563174) val = lbl_80563174;
 packed = *arg0 & 0xFFFFFF;
 *arg0 = packed;
 *arg0 = packed | ((int)(lbl_80563178 + val * lbl_8056317C) << 24);
}

void fn_80204460(void) {
    lbl_8055ED3C = 0;
    lbl_8055ED40 = 0;
    lbl_8055ED48 = 0;
    lbl_8055ED44 = fn_80145E70(lbl_8033BB18);
}

void fn_8020449C(void) {
    lbl_8055ED3C = 0;
    if (lbl_8055ED44 != 0) {
        (*(void (***)(void *, int))lbl_8055ED44)[2]((void *)lbl_8055ED44, 1);
    }
    lbl_8055ED44 = 0;
}

int fn_802044E8(void) {
 unsigned char input[0x64];
 float matrix[12];
 struct Text80204 value, label;
 int normal, selected;
 int result, count, start, end, i;
 struct Text80204 *a, *b, *c;
 char *area, *entry;
 float step;
 fn_80230B5C(matrix);
 fn_802C8638(matrix);
 fn_802C974C(lbl_80563168, lbl_80563170, lbl_80563188);
 (*(void (***)(int))lbl_8055ED44)[7](lbl_8055ED44);
 result = fn_8020437C();
 if (result) {
  if (lbl_8055ED40 >= 0 && lbl_8055ED40 < lbl_8055ED3C) {
   a = (*(struct Text80204 *(***)(int,const char *))lbl_8055ED44)[3](lbl_8055ED44,lbl_8055B428);
   b = (*(struct Text80204 *(***)(int,const char *))lbl_8055ED44)[3](lbl_8055ED44,lbl_8055B430);
   c = (*(struct Text80204 *(***)(int,const char *))lbl_8055ED44)[3](lbl_8055ED44,lbl_8055B438);
   area = (*(char *(***)(int,const char *))lbl_8055ED44)[5](lbl_8055ED44,lbl_8055B440);
   if (a && b && c && area) {
    normal = a->color; selected = b->color;
    fn_802043B0(&normal); fn_802043B0(&selected);
    step = b->y - a->y;
    count = (int)(*(float *)(area+0x14)/step);
    label.unk_0x0=a->unk_0x0; label.unk_0x4=a->unk_0x4; label.y=a->y; label.unk_0xc=a->unk_0xc; label.unk_0x10=a->unk_0x10; label.unk_0x14=a->unk_0x14; label.color=a->color; label.unk_0x1c=a->unk_0x1c;
    start = lbl_8055ED40 - lbl_8055ED40 % count;
    value.unk_0x0=c->unk_0x0; value.unk_0x4=c->unk_0x4; value.y=c->y; value.unk_0xc=c->unk_0xc; value.unk_0x10=c->unk_0x10; value.unk_0x14=c->unk_0x14; value.color=c->color; value.unk_0x1c=c->unk_0x1c;
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
    if (start >= count) fn_801473F8(lbl_8055ED44,lbl_8033BB18+0x10,lbl_8055B45C);
    if (end < lbl_8055ED3C) fn_801473F8(lbl_8055ED44,lbl_8033BB18+0x1c,lbl_8055B460);
   }
  } else fn_801473F8(lbl_8055ED44,lbl_8055B428,lbl_8033BB18+0x28);
 } else {
  (*(void *(***)(int,const char *))lbl_8055ED44)[3](lbl_8055ED44,lbl_8033BB18+0x38);
  fn_801476C4();
  if (fn_801298E8(input,0) && input[0x25]) fn_80204330();
 }
 fn_80011A2C();
 return result;
}

int fn_80204870(int arg0) {
    int index, type;
    char *entry;
    float *value;
    float f;
    if (fn_8020437C() == 0) return 0;
    switch (arg0) {
    case 0x126:
        index = lbl_8055ED40 - 1;
        lbl_8055ED40 = index & ~(index >> 31);
        break;
    case 0x128:
        index = lbl_8055ED40 + 1;
        if (index > lbl_8055ED3C - 1) index = lbl_8055ED3C - 1;
        lbl_8055ED40 = index;
        break;
    case 0x125:
    case 0x127:
        index = lbl_8055ED40;
        if (index >= 0 && index < lbl_8055ED3C) {
            entry = lbl_80488BD0 + index * 0x18;
            type = *(int *)(entry + 4);
            if (type == 1) {
                value = *(float **)(entry + 8);
                if (arg0 == 0x127) {
                    f = *value + *(float *)(entry + 0x14);
                    if (f > *(float *)(entry + 0x10)) f = *(float *)(entry + 0x10);
                    *value = f;
                } else {
                    f = *value - *(float *)(entry + 0x14);
                    if (f < *(float *)(entry + 0xC)) f = *(float *)(entry + 0xC);
                    *value = f;
                }
            } else if (type == 0) {
                value = (float *)*(void **)(entry + 8);
                *(unsigned char *)value = !*(unsigned char *)value;
            }
        }
        break;
    default:
        return 0;
    }
    fn_80204330();
    return 1;
}

void fn_802049DC(int a, int b, float c, float d, float e) {
    int i;
    char *entry;
    i = lbl_8055ED3C;
    if (i < 0x40) {
      entry = lbl_80488BD0 + i * 0x18;
      *(int *)(entry + 0) = a;
      *(int *)(entry + 4) = 1;
      *(int *)(entry + 8) = b;
      *(float *)(entry + 0xC) = c;
      *(float *)(entry + 0x10) = d;
      lbl_8055ED3C = i + 1;
      *(float *)(entry + 0x14) = e;
    }
}

void fn_80204A1C(int a, int b) {
    int i;
    char *entry;
    i = lbl_8055ED3C;
    if (i < 0x40) {
      entry = lbl_80488BD0 + i * 0x18;
      *(int *)(entry + 0) = a;
      *(int *)(entry + 4) = 0;
      lbl_8055ED3C = i + 1;
      *(int *)(entry + 8) = b;
    }
}

void fn_80204A50(void) {
    fn_80204330();
}
