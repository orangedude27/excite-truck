// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;

void fn_8013605C(void *);
void fn_80135F64(int, s32, s32, s32, s32);
extern float lbl_8055E3C8;
extern float lbl_8056133C;
void fn_80136714(void *);
extern float lbl_80561320;
extern float lbl_80561324;
extern s32 lbl_8032BE80[];

typedef struct {
    s32 unk_0;
    s32 unk_4;
    float unk_8;
    s32 unk_c;
    float unk_10;
    float unk_14;
    float unk_18;
    float unk_1c;
    float unk_20;
    float unk_24;
    u8 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    float unk_38, unk_3c, unk_40, unk_44, unk_48, unk_4c;
    float *unk_50;
    s32 unk_54, unk_58, unk_5c, unk_60;
} Unk_80135278;

void fn_80135390(Unk_80135278 *);
void fn_801355C0(void *, s32, s32, void *, s32);
void fn_801357A4();

extern void *fn_80156A40(void);

typedef struct {
    float unk_0;
    float unk_4;
} Diffs2_80135278;

static float fn_80135278_dot(float *a, Diffs2_80135278 d) {
    return a[0] * d.unk_0 + a[1] * d.unk_4;
}

static Diffs2_80135278 fn_80135278_diff(float *b, float *c) {
    Diffs2_80135278 r;
    r.unk_0 = b[0] - c[0];
    r.unk_4 = b[1] - c[1];
    return r;
}

float fn_80135278(float *a, float *b, float *c) {
    float dx = b[0] - c[0];
    float dy = b[1] - c[1];
    float x = a[0] * dx;
    float y = a[1] * dy;
    return x + y;
}

void *fn_801352B8(Unk_80135278 *arg0) {
    arg0->unk_0 = (s32)&lbl_8032BE80;
    arg0->unk_4 = 0;
    arg0->unk_c = 0x2710;
    arg0->unk_8 = lbl_80561320;
    fn_80135390(arg0);
    return arg0;
}

void *fn_8013530C(void *arg0, s32 arg1) {
    if (arg0 != (void*)0) {
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void fn_80135354(Unk_80135278 *arg0) {
    float g, f;
    g = lbl_80561324;
    f = lbl_80561320;
    arg0->unk_8 = f;
    arg0->unk_4 = 0;
    arg0->unk_c = 0;
    arg0->unk_20 = f;
    arg0->unk_24 = f;
    arg0->unk_10 = g;
    arg0->unk_14 = f;
    arg0->unk_18 = f;
    arg0->unk_1c = f;
    arg0->unk_28 = 0;
    arg0->unk_2c = 0;
}

#pragma dont_inline on
void fn_80135390(Unk_80135278 *arg0) {
    fn_80135354(arg0);
    arg0->unk_30 = 0;
}
#pragma dont_inline off

#pragma dont_inline on
void fn_801353C8(Unk_80135278 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    float f = lbl_80561320;
    arg0->unk_8 = f;
    arg0->unk_4 = arg3;
    fn_801355C0(arg0, arg1, arg2, &arg0->unk_4, 0);
    fn_801357A4(arg0, arg1);
}

void fn_801353C4(void) {
    fn_801357A4();
}

s32 fn_801355B8(void *arg0, void *arg1) {
    return 0;
}

extern void fn_80135EA8(void *, s32, s32);
extern void fn_80135F4C(void *);
extern s32 lbl_8032BE6C[];
#pragma dont_inline on
void *fn_80135DC4(void *arg0, s32 arg1, s32 arg2) {
    s32 v;
    v = arg2;
    fn_801352B8(arg0);
    *(s32 *)((char *)arg0 + 0x58) = 0;
    *(s32 **)arg0 = lbl_8032BE6C;
    *(s32 *)((char *)arg0 + 0x54) = 0;
    *(s32 *)((char *)arg0 + 0x50) = 0;
    if (v == 0) {
        void *obj = fn_80156A40();
        v = ((s32 (**)(void *, s32))*(void **)obj)[2](obj, 0);
    }
    if (((s32 (**)(void *, s32))*(void **)arg0)[3](arg0, v) != 0) {
        if (arg1 != 0) {
            void *p = *(void **)((char *)arg0 + 0x2C);
            fn_80135EA8((char *)arg0 + 0x50, *(s32 *)((char *)p + 0x18) >> 16, 2);
        } else {
            *(s32 *)((char *)arg0 + 0x58) = 0;
            *(s32 *)((char *)arg0 + 0x54) = 0;
            *(s32 *)((char *)arg0 + 0x50) = 0;
        }
        fn_80135F4C(arg0);
    }
    return arg0;
}

extern s32 fn_8012850C(s32, void *);
extern s32 lbl_8032BE20[];
void fn_80135EA8(void *arg0, s32 arg1, s32 arg2) {
    s32 temp = arg1 + arg2;
    *(s32 *)((char *)arg0 + 4) = arg1;
    *(s32 *)((char *)arg0 + 8) = temp;
    *(s32 *)arg0 = fn_8012850C(temp * 4, lbl_8032BE20);
}

#pragma dont_inline off
void fn_80135EF0(void *arg0) {
    int zero = 0;
    int value;
    if (fn_80135D60() == 1) {
        *(int *)((char *)arg0 + 0x34) = zero;
        value = *(int *)((char *)arg0 + 0x50);
        *(int *)((char *)arg0 + 0x5C) = zero;
        if (value != 0) {
            value = *(int *)(*(char **)((char *)arg0 + 0x2C) + 0x18);
            *(int *)((char *)arg0 + 0x54) = value >> 16;
        }
    }
}

void fn_80135F4C(void *arg0) {
    int x = *(int *)(*(char **)((char *)arg0 + 0x2C) + 0x1C);
    fn_80135F64((int)arg0, x, x + 8, 1, 0);
}

#pragma dont_inline on
void fn_80135F64(int arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
 s32 offset;
 s32 i;
 void *p;
 fn_801353C8((void *)arg0,arg1,arg2,arg4);
 fn_80136714((void *)arg0);
 if(arg3 != 0 && *(s32 *)((char *)arg0+0x50)!=0) {
  float a=lbl_8055E3C8;
 float f=lbl_8056133C+a;
  for(i=0,offset=0;i<*(s32 *)((char *)arg0+0x54);i++,offset+=4)
   *(float *)(*(char **)((char *)arg0+0x50)+offset)=f;
  fn_8013605C((void *)arg0);
 } else fn_8013605C((void *)arg0);
 {
 Unk_80135278 *obj=(Unk_80135278 *)arg0;
 float a=-obj->unk_10;
 float zero=lbl_80561320;
 Unk_80135278 *p=(Unk_80135278 *)obj->unk_4;
 float b,c,d,e,f,g;
 obj->unk_44=zero;
 b=obj->unk_18;
 obj->unk_4c=zero;
 c=obj->unk_1c;
 d=p->unk_18;
 e=p->unk_1c;
 a=a*c;
 f=obj->unk_8;
 g=obj->unk_14;
 d=d*f;
 obj->unk_5c=0;
 c=g*b;
 obj->unk_60=0;
 e=e+d;
 a=c+a;
 obj->unk_48=e;
 obj->unk_40=a;
 }
}
#pragma dont_inline off

void fn_8013605C(void *arg0) {
    *(signed char *)((char *)arg0 + 0x64) = 0;
}

int fn_801363A0(void *arg0, void *arg1) {
    int temp_r31 = *(int *)((char *)*(void **)arg1 + 0x10);
    int var = *(int *)((char *)*((void **)*(void **)arg1 + 0x14) + 0x10);
    if (var == 0) var = *(int *)((char *)*(void **)((char *)arg0 + 0x2C) + 0x18);
    return temp_r31 + (unsigned int)(*(float *)((char *)arg1 + 4) * (float)(var - temp_r31));
}

float fn_801365C4(Unk_80135278 *a, Unk_80135278 *b) {
    s32 same, offset, pos, count, i, j;
    unsigned long length;
    Unk_80135278 *p;
    void *data;
    float value, result;
    data = (void *)a->unk_2c;
    if (data == 0 || b->unk_4 == 0 || a->unk_4 == 0 || b->unk_54 != a->unk_54)
        return lbl_80561320;
    p = (Unk_80135278 *)a->unk_4;
    same = p == (Unk_80135278 *)b->unk_4;
    offset = ((-same | same) >> 31) - 1;
    pos = *(s32 *)((char *)p + 0x10);
    if (a->unk_34 != 0) {
        length = *(unsigned long *)((char *)data + 0x18);
        pos = (length + (pos - a->unk_34)) % length;
    }
    count = a->unk_54;
    i = ((pos >> 16) + (count + offset)) % count;
    j = (i + 1) % count;
    value = a->unk_8 * (b->unk_50[j] - b->unk_50[i]) + b->unk_50[i];
    if (same)
        result = a->unk_8 * (a->unk_50[j] - a->unk_50[i]) + a->unk_50[i];
    else
        result = lbl_8055E3C8;
    return result - value;
}

s32 fn_801366C0(void *arg0, void *arg1, float farg0) {
    if (*(s32 *)((char *)arg0 + 4) != 0) {
        if (*(s32 *)(*(s32 *)((char *)arg0 + 0x2C) + 0x1C) == 0) {
            return 0;
        }
    }
    return ((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)arg0 + 0x10))
          + (*(float *)((char *)arg1 + 8)) * (*(float *)((char *)arg0 + 0x14))) < -farg0;
}

void fn_80136714(void *arg0) {
    float a = *(float *)((char *)arg0 + 0x10);
    float b = *(float *)((char *)arg0 + 0x14);
    *(float *)((char *)arg0 + 0x38) = b;
    *(float *)((char *)arg0 + 0x3C) = -a;
}

extern void *fn_80156A40(void);

typedef struct {
    void *unk_0;
    void *unk_4;
    void *(*unk_8)(void *, s32);
} Vt_8013672C;

typedef struct {
    Vt_8013672C *vtbl;
} Unk_8013672C_vt;

float fn_8013672C(void) {
    void *obj = fn_80156A40();
    void *ret = ((void *(*)(void *, s32))((void **)*(void **)obj)[2])(obj, 0);
    return *(float *)((char *)ret + 8);
}

void fn_80136764(void) {
    fn_801564B0();
}

void fn_80136768(void) {
    fn_801569FC();
}

void fn_801367E8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 r;
    void ***vtbl = (void ***)arg0;
    r = ((s32 (*)(void))vtbl[0][3])();
    if (r == 1) {
        fn_801353C8((Unk_80135278 *)arg0, arg2, arg3, 0);
    }
}

void fn_80136854(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 r;
    r = ((s32 (*)(void))(*(void **)((char *)(*(void **)arg0) + 0xc)))();
    if (r == 1) {
        fn_80135F64((int)arg0, arg2, arg3, 1, 0);
    }
}

