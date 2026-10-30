// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { float values[12]; } Unk_801ECFE0;
extern long lbl_80488648[];
void fn_801EDD7C(void *, long);
long fn_80179CB0(void);
void fn_801EECAC(long, long);
void fn_802C6CF8(long);

#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_801EC9CC(void*, int);
void fn_80128668(void*);
void fn_801E323C(void);
void fn_801ECCE0(long, long);
long fn_801E866C(long);
long fn_801E89C8(long);
float fn_802C99E8(void *, float);
void fn_801ED718(void *);
void fn_801ECC70(void *);
float fn_801F159C(long);
long fn_80201018(long, void *, long);
long fn_801ECB60(void);
extern unsigned int lbl_8055EBC8;
void fn_801F131C(void *, long, void *, float);
void fn_801EFC90(long, long, void *);
extern float lbl_80488668[3];
extern unsigned int lbl_8055EBC8;
long fn_801ECB60(void);
void fn_801EC1D4(void) {
    ((unsigned int *)lbl_80488668)[0] = 0x555766;
    ((unsigned int *)lbl_80488668)[1] = 0xFFF5D9;
}

void *fn_801EC1F8(void) {
    return lbl_80488668;
}

void *fn_801EC204(void) {
    return &lbl_80488668[1];
}

extern double fn_8002EFB0(float,float);
extern void fn_801345D8(void *,int,const char *,...);
extern int fn_801E3004(int,const char *,int);
extern void fn_802E317C(const char *,const char *);
extern float lbl_80562E88;
extern char lbl_8033A060[], lbl_8055AFCC[], lbl_8055AFD4[];
extern int sscanf(const char *,...);
void fn_801EC214(void *out, void *obj, int arg2, const char *name, int arg4, float f1, float f2) {
 int count=0; float a=lbl_80562E88,b=lbl_80562E88,c,d; char buf[0x20]; float *entry;
 *(int *)((char *)out+0x50)=arg4;
 if(!((int (*)(void *,const char *))((int (**)(void))*(void **)obj)[3])(obj,name)){*(int *)out=0;return;}
 ((void (*)(void *,const char *))((void (**)(void))*(void **)obj)[5])(obj,name);
 if(sscanf(lbl_8055AFCC,&a,&b)!=2) fn_802E317C(lbl_8033A060,name);
 *(int *)out=fn_801E3004(arg2,name,-1); f1=f1-f2; f2=lbl_80562E88; *(int *)((char *)out+0x4c)=0;
 while(count<8 && ((int (*)(void *,const char *))((int (**)(void))*(void **)obj)[3])(obj,buf)) {
  fn_801345D8(buf,0x20,lbl_8055AFD4,name,count+1);
  entry=(float *)((char *)out+count*8+0xc); c=f2; d=f2;
  ((void (*)(void *,const char *))((void (**)(void))*(void **)obj)[5])(obj,buf);
  if(sscanf(lbl_8033A060+0x10,entry,&c,&d)!=3) fn_802E317C(lbl_8033A060+0x1c,buf);
  entry[1]=(float)fn_8002EFB0(c-a,-(d-b)); entry[0]=entry[0]*f1+f2;
  count++; *(int *)((char *)out+0x4c)=count;
 }
 if(count<2) fn_802E317C(lbl_8033A060+0x34,name);
 *(float *)((char *)out+4)=*(float *)((char *)out+0xc);
 *(float *)((char *)out+8)=*(float *)((char *)out+(count-1)*8+0xc);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448
long __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448(long arg0, long arg1) {
    if (arg0 != 0) {
        long vptr = *(long *)arg0;
        if (vptr != 0) {
            ((void (*)(long))fn_801E323C)(vptr);
        }
        if (arg1 > 0) fn_80128668((void *)arg0);
    }
    return arg0;
}
#pragma pop
void fn_801E353C(long, float);
void fn_801E34E4(void *, long);
#pragma push
#pragma scheduling off
void fn_801EC4A8(void *arg0, long arg1) {
    char *p;
    long object;
    long i, count;
    char *a, *b;
    float lower, value, upper;
    float x, y, nextY;
    object = *(long *)arg0;
    if (object != 0) {
        value = *(float *)((char *)arg0 + 8);
        upper = **(float **)((char *)arg0 + 0x50);
        lower = *(float *)((char *)arg0 + 4);
        value = value < upper ? value : upper;
        value = value > lower ? value : lower;
        p = arg0;
        i = 0;
        count = *(long *)((char *)arg0 + 0x4C) - 2;
        for (; count > 0; count--) {
            if (*(float *)(p + 0x14) > value) break;
            p += 8;
            i++;
        }
        a = (char *)arg0 + i * 8;
        b = (char *)arg0 + (i + 1) * 8;
        x = *(float *)(a + 0xC);
        y = *(float *)(a + 0x10);
        nextY = *(float *)(b + 0x10);
        fn_801E353C(object, -(y + (nextY - y) * ((value - x) / (*(float *)(b + 0xC) - x))));
        fn_801E34E4(*(void **)arg0, arg1);
    }
}

#pragma cplusplus on
union Vec3 {
    struct { float x, y, z; } f;
    unsigned int u[3];
};
struct Parent {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20();
    virtual void *get(int);
};
struct Property {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10();
    virtual Vec3 getVector(char *);
};
extern "C" {
static inline void *fn_801EC59C_parent_get(void *parent, int index) {
    return ((Parent *)parent)->get(index);
}
static inline void fn_801EC59C_property_get(void *out, void *property, char *label) {
    *(Vec3 *)out = ((Property *)property)->getVector(label);
}
}
#pragma cplusplus reset
void fn_801EC59C(void *out, void *parent, int index, int value, float scale, float bias) {
    extern char lbl_8055AFDC, lbl_8055AFE4;
    extern float lbl_80562E88, lbl_80562E8C;
    typedef union { struct { float x, y, z; } f; unsigned int u[3]; } Vec3;
    register void *result;
    Vec3 first, second;
    float dx, dy, slopeX, slopeY, x0, x1, y0, y1;

    *(volatile int *)out = value;
    result = fn_801EC59C_parent_get(parent, index);
    if (result != 0) {
        fn_801EC59C_property_get(&first, result, &lbl_8055AFDC);
        fn_801EC59C_property_get(&second, result, &lbl_8055AFE4);
        x0 = first.f.x * scale - bias;
        x1 = second.f.x * scale - bias;
        y0 = first.f.y * lbl_80562E8C;
        y1 = second.f.y * lbl_80562E8C;
        dx = x0 - x1;
        dy = first.f.z * lbl_80562E8C - second.f.z * lbl_80562E8C;
        slopeX = (y1 - y0) / dx;
        slopeY = dy / dx;
        *(float *)((char *)out + 4) = slopeX;
        *(float *)((char *)out + 0xC) = slopeY;
        *(float *)((char *)out + 8) = y0 - slopeX * x1;
        *(float *)((char *)out + 0x10) = first.f.z * lbl_80562E8C - slopeY * x1;
    } else {
        *(float *)((char *)out + 0x10) = lbl_80562E88;
        *(float *)((char *)out + 0xC) = lbl_80562E88;
        *(float *)((char *)out + 8) = lbl_80562E88;
        *(float *)((char *)out + 4) = lbl_80562E88;
    }
}
#pragma pop
void fn_801EC714(void *arg0, float *arg1, float *arg2) {
    *arg1 = *(float *)((char *)arg0 + 8) + (*(*(float **)arg0) * *(float *)((char *)arg0 + 4));
    *arg2 = *(float *)((char *)arg0 + 0x10) + (*(*(float **)arg0) * *(float *)((char *)arg0 + 0xC));
}

extern char lbl_8033A300[];
extern void fn_801EEC68(void *);
extern void fn_801EFFF8(long);
extern void fn_801EF428(long, long);
extern void fn_8020095C(long);
extern void fn_802792EC(long);
extern long __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448(long, long);
#pragma dont_inline on
void fn_801EC9CC(void *arg0, int arg1) {
    int i;
    char *entry;
    long value;

    if (arg0 == 0) return;

    *(void **)arg0 = lbl_8033A300;
    fn_801EEC68(arg0);

    entry = arg0;
    for (i = 0; i < *(int *)((char *)arg0 + 0x148); i++) {
        *(int *)(entry + 0x84) = -1;
        fn_802C6CF8(*(long *)(entry + 0x44));
        entry += 4;
    }

    entry = arg0;
    for (i = 0; i < *(int *)((char *)arg0 + 0x480); i++) {
        fn_802C6CF8(*(long *)(entry + 0x400));
        entry += 8;
    }

    fn_802C6CF8(*(long *)((char *)arg0 + 0x178));
    ((void (*)(long))fn_801E323C)(*(long *)((char *)arg0 + 0x17C));
    ((void (*)(long))fn_801E323C)(*(long *)((char *)arg0 + 0x180));
    fn_8020095C(*(long *)((char *)arg0 + 0x184));

    entry = arg0;
    for (i = 0; i < 4; i++) {
        value = *(long *)(entry + 0x4D4);
        fn_801EFFF8(value);
        *(long *)(entry + 0x4D4) = 0;
        entry += 4;
    }

    lbl_80488648[*(long *)((char *)arg0 + 0x40)] = 0;
    fn_801EF428(*(long *)((char *)arg0 + 0x3F0), 1);
    fn_802792EC(*(long *)((char *)arg0 + 0x188));
    *(long *)((char *)arg0 + 0x188) = 0;
    if (lbl_8055EBC8 == (unsigned int)arg0) lbl_8055EBC8 = 0;

    __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x384), -1);
    __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x330), -1);
    __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x2DC), -1);
    __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x288), -1);
    __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x234), -1);
    __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x1E0), -1);
    __dt__24J3DUMtxAnmCacheTableBaseFv_801EC448((long)((char *)arg0 + 0x18C), -1);

    if (arg1 > 0) fn_80128668(arg0);
}
#pragma pop
float fn_802C88D4(void *);
float fn_801E88F0(long);
#pragma push
#pragma processor 750
#pragma scheduling 7400
void fn_801ECB80(void *arg0) {
    float value;
    long *count;
    long offset;
    long i;
    value = fn_802C88D4((char *)arg0 + 0x28);
    value *= fn_801E88F0(-1);
    count = *(long **)((char *)arg0 + 0x174);
    i = 0;
    offset = 0;
    *(long *)((char *)arg0 + 0x3F8) = *count - 1;
    for (; i < *count; offset += 8, i++) {
        if (value < *(float *)(*(char **)((char *)arg0 + 0x170) + offset)) {
            *(long *)((char *)arg0 + 0x3F8) = i;
            break;
        }
    }
    if (*(long *)((char *)arg0 + 0x3F8) < *(long *)((char *)arg0 + 0x3FC))
        *(long *)((char *)arg0 + 0x3F8) = *(long *)((char *)arg0 + 0x3FC);
    if (*(long *)((char *)arg0 + 0x3F8) >= **(long **)((char *)arg0 + 0x174))
        *(long *)((char *)arg0 + 0x3F8) = **(long **)((char *)arg0 + 0x174) - 1;
    if (*(long *)((char *)arg0 + 0x40) == fn_801E866C(-1)) {
        long n = *(long *)((char *)arg0 + 0x3F8);
        *(long *)((char *)arg0 + 0x3F8) = n > 1 ? 1 : n;
    }
}

void fn_801ECC70(void *arg0) {
    void *ptr = *(void **)((char *)arg0 + 0x3C);
    fn_802C99E8(ptr, *(float *)((char *)lbl_80488668 + 8) * *(float *)((char *)ptr + 0x2CC));
}

#pragma pop

#pragma scheduling invalid_target
long fn_801ECC8C(unsigned int arg0) {
    long result = 0;
    if (fn_801ECB60() != 0 || arg0 == lbl_8055EBC8)
        result = 1;
    return result;
}
#pragma scheduling on
void fn_801ECF58(void *arg0) {
    long flag;
    long entry;
    long owner;

    if (*(long *)((char *)arg0 + 0x184) != 0) {
        flag = 0;
        entry = *(long *)((char *)arg0 + 0x170) +
                *(long *)((char *)arg0 + 0x3F8) * 8;
        if (*(unsigned char *)(entry + 5) != 0) {
            owner = *(long *)((char *)arg0 + 0x3C);
            if ((*(long *)(owner + 0x2C0) & 0x100) == 0)
                flag = 1;
        }
                  fn_801ECC70(arg0);
          fn_80201018(*(long *)((char *)arg0 + 0x184),
                    *(void **)((char *)arg0 + 0x3C), flag);
    }
}

#pragma push
#pragma processor 750
void fn_801ECFE0(void *arg0) {
    extern void *fn_801E87A8(void);
    extern void fn_801ED46C(void *);
    extern void fn_802DAC54(void);
    extern int fn_802C7A40(int, void *, int, int, void *, int);
    extern void fn_802C70AC(int, void *, int, int);
    extern float lbl_80562E94, lbl_80562E98, lbl_80558DC4;
    extern unsigned char lbl_8055E614;
    extern long lbl_8055EBC0;
    char *self = arg0;
    Unk_801ECFE0 first, second;
    long params[2];
    long *entry;
    long i, j, offset, mask, handle, flag, cached;
    char *part, *data;
    float scale;
          if (!(*(float *)(*(char **)(self+0x3C)+0x22C) < lbl_80562E94)) {
          fn_801ECC70(self);
          flag = (*(unsigned long *)((char *)fn_801E87A8()+0x10) >> 1) & 1;
        entry = (long *)(self+0x154);
        cached = lbl_8055EBC0;
        scale = lbl_80562E98;
        for (i=0; i<*(long *)(self+0x150); i++, entry+=3) {
            mask = *(long *)(*(char **)(self+0x3C)+0x29C) & entry[2];
            params[0] = *(long *)(self+0x3EC);
            params[1] = cached;
            if ((float)__fabs((double)*(float *)(*(char **)(self+0x3C)+0x28C)) <= lbl_80558DC4)
                fn_802DAC54();
            handle = fn_802C7A40(1, *(char **)(self+0x3C)+(entry[0]+1)*12+0x2E0, entry[1]-entry[0], 1, params, 2);
            for (j=0, offset=0; j<*(long *)(*(char **)(self+0x3C)+0xA78); j++, offset+=0x34) {
                data = *(char **)(self+0x3C)+offset;
                part = data+0xA7C;
                if (*(long *)(data+0xAAC) & mask) {
                    if (flag) {
                        first = *(Unk_801ECFE0 *)part;
                        first.values[0] *= scale;
                        first.values[1] *= scale;
                        first.values[2] *= scale;
                        fn_802C70AC((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], &first, handle, *(long *)(part+0x30));
                    } else {
                        fn_802C70AC((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], part, handle, *(long *)(part+0x30));
                    }
                    mask &= ~*(long *)(part+0x30);
                }
            }
            if (!lbl_8055E614) {
                if (flag) {
                    second = *(Unk_801ECFE0 *)(self+0x4A0);
                    second.values[0] *= scale;
                    second.values[1] *= scale;
                    second.values[2] *= scale;
                    fn_802C70AC((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], &second, handle, mask);
                } else {
                    fn_802C70AC((*(int **)(self+0x16C))[*(long *)(self+0x3F8)], self+0x4A0, handle, mask);
                }
            }
        }
        fn_801ED46C(self);
    }
}
#pragma pop

  void fn_801ED2D0(void *arg0) {
      long offset;
      char *current;
      long flag;
      long i;
      char *p;
  
      ((void (*)(void))fn_801ECC70)();
    flag = *(long *)((char *)arg0 + 0x40) == fn_801E866C(-1);
    i = 0;
    current = (char *)arg0;
    offset = 0;
    do {
        p = (char *)*(void **)((char *)arg0 + 0x3C) + offset;
        fn_801F131C(*(void **)(current + 0x4D4), flag, p,
                    *(float *)(p + 0xB0));
        i++;
        offset += 0x6C;
        current += 4;
    } while (i < 4);
}

extern long fn_801E8954(long);
extern long fn_801E897C(long);
extern void fn_801F1378(void *, void *, float);
extern void fn_801EDD68(void *);
extern unsigned char lbl_8055EBC4;
#pragma push
#pragma dont_inline on
void fn_801ED354(void *arg0) {
    if (fn_801E8954(-1) != 0) {
        fn_801ECF58(arg0);
        fn_801ECFE0(arg0);
        if (*(unsigned char *)((char *)*(void **)((char *)arg0 + 0x170) +
                               *(long *)((char *)arg0 + 0x3F8) * 8 + 4) != 0) {
            long i;
            long offset;
            long current;
            char *p;
            current = (long)arg0;
            i = 0;
            offset = 0;
            do {
                p = (char *)*(void **)((char *)arg0 + 0x3C) + offset;
                fn_801F131C(*(void **)(current + 0x4D4), 1, p,
                            *(float *)(p + 0xB0));
                i++;
                offset += 0x6C;
                current += 4;
            } while (i < 4);
        }
    } else if (fn_801E897C(-1) != 0 || lbl_8055EBC4 != 0) {
        fn_801ECC70(arg0);
        {
            long i;
            long current;
            long offset;
            char *p;
            current = (long)arg0;
            i = 0;
            offset = 0;
            do {
                p = (char *)*(void **)((char *)arg0 + 0x3C) + offset;
                fn_801F1378(*(void **)(current + 0x4D4), p,
                            *(float *)(p + 0xB0));
                i++;
                offset += 0x6C;
                current += 4;
            } while (i < 4);
        }
        fn_801EDD68(arg0);
    }
}
#pragma pop

void fn_801ED68C(long arg0) {
    fn_801ECCE0(arg0, 1);
}

void fn_801ED694(long arg0) {
    fn_801ECCE0(arg0, 0);
}

void fn_801ED69C(void *arg0) {
    void *ptr;
    if (*(long *)((char *)arg0 + 0x40) == fn_801E866C(-1) &&
        fn_801E89C8(-1) != 0) {
        ptr = *(void **)((char *)arg0 + 0x3C);
        lbl_80488668[2] = fn_802C99E8(ptr, *(float *)((char *)ptr + 0x2CC));
        fn_802C99E8(((void *(*)(void *))fn_801ED718)(arg0), lbl_80488668[2]);
    }
}

void fn_801EDD68(void *arg0) {
    fn_801EFC90(*(long *)((char *)arg0 + 0x3F0),
                *(long *)((char *)arg0 + 0x3C), (char *)arg0 + 0x4D4);
}

extern void fn_801EABA8(long);
extern void fn_801F0F78(long, long, void *, float);
extern float lbl_80558DC4;
extern float lbl_80562E90;
extern float __fabsf(float);
void fn_801EDD7C(void *arg0, long arg1) {
    float scale;
    unsigned int *a, *b, *c, *d, *e, *f, *g, *h, *j, *k, *m, *n;
    long i, offset;
    char *entry;
    fn_801EABA8(*(long *)((char *)arg0 + 0x3C));
    scale = *(float *)((char *)arg1 + 0x2D0);
    *(float *)((char *)arg0 + 0x4D0) = scale;
    if (__fabsf(scale - lbl_80562E90) <= lbl_80558DC4) {
        a = (unsigned int *)((char *)arg0 + 4); b = a + 1; c = a + 2; d = a + 3;
        e = a + 4; f = a + 5; g = a + 6; h = a + 7;
        j = a + 8; k = a + 9; m = a + 10; n = a + 11;
        *(unsigned int *)((char *)arg0 + 0x4A0) = *a;
        *(unsigned int *)((char *)arg0 + 0x4A4) = *b;
        *(unsigned int *)((char *)arg0 + 0x4A8) = *c;
        *(unsigned int *)((char *)arg0 + 0x4AC) = *d;
        *(unsigned int *)((char *)arg0 + 0x4B0) = *e;
        *(unsigned int *)((char *)arg0 + 0x4B4) = *f;
        *(unsigned int *)((char *)arg0 + 0x4B8) = *g;
        *(unsigned int *)((char *)arg0 + 0x4BC) = *h;
        *(unsigned int *)((char *)arg0 + 0x4C0) = *j;
        *(unsigned int *)((char *)arg0 + 0x4C4) = *k;
        *(unsigned int *)((char *)arg0 + 0x4C8) = *m;
        *(unsigned int *)((char *)arg0 + 0x4CC) = *n;
    } else {
        *(float *)((char *)arg0 + 0x4A0) = *(float *)((char *)arg0 + 4) * scale;
        *(float *)((char *)arg0 + 0x4A4) = *(float *)((char *)arg0 + 8) * scale;
        *(float *)((char *)arg0 + 0x4A8) = *(float *)((char *)arg0 + 0xC) * scale;
        *(float *)((char *)arg0 + 0x4AC) = *(float *)((char *)arg0 + 0x10) * scale;
        *(float *)((char *)arg0 + 0x4B0) = *(float *)((char *)arg0 + 0x14) * scale;
        *(float *)((char *)arg0 + 0x4B4) = *(float *)((char *)arg0 + 0x18) * scale;
        *(float *)((char *)arg0 + 0x4B8) = *(float *)((char *)arg0 + 0x1C) * scale;
        *(float *)((char *)arg0 + 0x4BC) = *(float *)((char *)arg0 + 0x20) * scale;
        *(float *)((char *)arg0 + 0x4C0) = *(float *)((char *)arg0 + 0x24) * scale;
        *(float *)((char *)arg0 + 0x4C4) = *(float *)((char *)arg0 + 0x28);
        *(float *)((char *)arg0 + 0x4C8) = *(float *)((char *)arg0 + 0x2C);
        *(float *)((char *)arg0 + 0x4CC) = *(float *)((char *)arg0 + 0x30);
    }
    entry = arg0; i = 0; offset = 0;
    do {
        fn_801F0F78(*(long *)(entry + 0x4D4), *(long *)((char *)arg0 + 0x3C) + offset + 0x7C,
                    (char *)arg0 + 4, *(float *)((char *)arg0 + 0x4D0));
        i++; offset += 0x6C; entry += 4;
    } while (i < 4);
}

extern float lbl_80562E88, lbl_80562E90, lbl_80562E9C, lbl_80562EC8;
float fn_802C88E8(void*);
long fn_801E89A4(long);
short fn_801EAC3C(void*, long);
long fn_801E9E78(void*, void*, float*, long*, float);
float PSVECDotProduct(float*, void*);
void* fn_802C9A40(void);
void fn_802C7AE0(long, void*, long, float);
void fn_801F13F4(long, float, float);
void fn_801EDF18(void* arg0) {
    float temp_f31, sp20, sp10, sp14, sp18, var_f29, var_f30, temp_f3, var_f2;
    long var_r31, sp1C, sp24, spC;
    long* var_r3;
    short sp8;
    temp_f31 = fn_801E88F0(-1);
    temp_f31 *= temp_f31;
    temp_f31 *= fn_802C88E8((char*)arg0 + 0x28);
    var_r31 = *(long*)((char*)arg0 + 0x480) - 1;
    var_r3 = (long*)((char*)arg0 + var_r31 * 8);
    while (var_r31 >= 0 && temp_f31 < (*(float*)((char*)var_r3 + 0x404) * *(float*)((char*)var_r3 + 0x404))) { var_r3 = (long*)((char*)var_r3 - 8); var_r31--; }
    if (var_r31 < 0) return;
    if (*(long*)((char*)arg0 + 0x40) == fn_801E866C(-1) && fn_801E89A4(-1) == 0) return;
    sp1C = *(long*)((char*)arg0 + 0x28); sp20 = *(float*)((char*)arg0 + 0x2C); sp24 = *(long*)((char*)arg0 + 0x30);
    sp8 = fn_801EAC3C(arg0, sp1C); sp10 = lbl_80562E88; sp14 = lbl_80562E90; sp18 = lbl_80562E88; spC = 0;
    if (fn_801E9E78(&sp8, &sp1C, &sp10, &spC, lbl_80562E88) != 0) {
        temp_f3 = -PSVECDotProduct(&sp10, fn_802C9A40()); var_f2 = lbl_80562E9C; var_f29 = *(float*)((char*)arg0 + 0x2C) - sp20;
        if (var_f2 <= temp_f3) var_f2 = temp_f3; var_f30 = lbl_80562E90 / var_f2;
    } else { var_f29 = lbl_80562E88; var_f30 = lbl_80562EC8; }
    fn_802C7AE0(*(long*)((char*)arg0 + var_r31 * 8 + 0x400), (char*)arg0 + 0x4A0, -1, var_f30 * (var_f29 + *(float*)((char*)arg0 + 0x484)));
    var_r31 = 0;
    do { fn_801F13F4(*(long*)((char*)arg0 + 0x4D4), temp_f31, var_f29 * var_f30); var_r31++; arg0 = (char*)arg0 + 4; } while (var_r31 < 4);
}

long fn_801EE0C8(void *arg0) {
    return *(long *)((char *)arg0 + 0x48);
}

void fn_801EE0D0(long arg0, long arg1) {
    fn_801F159C(*(long *)(arg0 + arg1 * 4 + 0x4D4));
}

extern char lbl_8033A1C8[];
extern char lbl_8055B070[8];
extern char lbl_8055B078[8];
long fn_801EFF94(void *, long, long);
#pragma push
#pragma use_lmw_stmw off
void fn_801EE974(void *arg0, void *arg1) {
    char *entries;
    char *out;
    long i;
    long flag;
    void *object;
    void *result;
    void *(*method)(void *, void *);
    out = arg1;
    entries = arg0;
    i = 0;
    do {
        flag = 0;
        if (i == 0) goto enabled;
        if (i != 1) goto checked;
    enabled:
        flag = 1;
    checked:
        if (flag) {
            object = *(void **)(*(char **)((char *)arg0 + 0x188) + 0x2134);
            method = *(void *(**)(void *, void *))((char *)*(void **)object + 8);
            result = method(object, lbl_8055B070);
            method = *(void *(**)(void *, void *))((char *)*(void **)result + 0x14);
            result = method(result, lbl_8033A1C8);
        } else {
            object = *(void **)(*(char **)((char *)arg0 + 0x188) + 0x2134);
            result = (*(void *(**)(void *, void *))((char *)*(void **)object + 8))(object, lbl_8055B078);
            result = (*(void *(**)(void *, void *))((char *)*(void **)result + 0x14))(result, lbl_8033A1C8);
        }
        *(long *)(entries + 0x4D4) = fn_801EFF94(result, *(long *)((char *)arg0 + 0x40), i);
        *(float *)(out + 0x10C) = fn_801F159C(*(long *)(entries + 0x4D4));
        i++;
        entries += 4;
        out += 4;
    } while (i < 4);
}

extern void fn_801345D8(void *, int, const char *, ...);
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern int fn_802C6FC0(void *, int, int);
extern int fn_802C7830(void);
extern char lbl_8033A060[];
extern char lbl_8055B080;
void fn_801EEA64(void *arg0, void *arg1, int arg2, int arg3) {
 char sp108[0x100]; char sp8[0x100]; void *iter; void *obj; int value, shift;
 fn_801345D8(sp108,0x100,lbl_8033A060+0x174,arg2);
 iter=fn_80131810(sp108);
 if(iter != 0 && ((int (**)(void *,char *))*(void **)iter)[4](iter,&lbl_8055B080) != 0) {
  obj=((void *(*)(void *,char *))((int (**)(void *,char *))*(void **)iter)[2])(iter,&lbl_8055B080);
  obj=((void *(*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[5])(obj,lbl_8033A060+0x194);
  fn_801345D8(sp8,0x100,lbl_8033A060+0x188,arg2,obj);
  *(int *)((char *)arg0+0x488)=fn_802C6FC0(sp8,0,arg3);
  *(int *)((char *)arg0+0x48C)=((int (*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[7])(obj,lbl_8033A060+0x1A0);
  *(int *)((char *)arg0+0x490)=((int (*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[7])(obj,lbl_8033A060+0x1AC);
  *(int *)((char *)arg0+0x494)=((int (*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[7])(obj,lbl_8033A060+0x1B8);
  if(((int (*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[3])(obj,lbl_8033A060+0x15C)!=0) {
   ((int (*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[5])(obj,lbl_8033A060+0x15C);
   *(int *)((char *)arg0+0x498)=fn_802C7830();
  } else *(int *)((char *)arg0+0x498)=-1;
  shift=((int (*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[7])(obj,lbl_8033A060+0x1C4);
  *(int *)((char *)arg0+0x49C)=1<<shift;
  value=((int (*)(void *,char *))((int (**)(void *,char *))*(void **)obj)[5])(obj,lbl_8033A060+0x1D8);
  fn_801345D8((char *)arg1+0xEC,0x20,lbl_8033A060+0x188,arg2,value);
  fn_80131818(iter); return;
 }
 *(int *)((char *)arg0+0x488)=-1; *(int *)((char *)arg0+0x494)=0; *((char *)arg1+0xEC)=0;
}

#pragma pop
void fn_801EDD7C(void *, long);
long fn_80179CB0(void);
void fn_801EECAC(long, long);
void fn_802C6CF8(long);
void fn_801EEC68(void *arg0) {
    long value;
    value = *(long *)((char *)arg0 + 0x488);
    if (value != -1) {
        fn_802C6CF8(value);
        *(long *)((char *)arg0 + 0x488) = -1;
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801EECAC(long arg0, long arg1) {
    extern void fn_801EAB10(int, int);
    extern char lbl_8055B088;
    extern char lbl_8055B090;
    extern float lbl_80562E90;
    extern float lbl_80562E88;
    extern float lbl_80562ECC;
    extern float lbl_80562ED0;
    extern float lbl_80562ED4;
    struct Property {
        virtual void *get(int);
    };
    char *stringBase = lbl_8033A060;
    void *value;
    void *object;
    long next;
    int count;

    next = arg1 + *(long *)((char *)arg0 + 0x34);
    *(long *)((char *)arg0 + 0x3C) = next;
    fn_801EAB10(*(int *)((char *)arg0 + 0x40), next);

    object = *(void **)((char *)*(void **)((char *)arg0 + 0x188) + 0x2134);
    value = ((Property *)object)->get((int)&lbl_8055B090);
    count = *(int *)((char *)arg0 + 0x178);

    fn_801EC214((void *)(arg0 + 0x384), value,
                count, stringBase + 0x1E4,
                (int)&lbl_8055B088, lbl_80562E90, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x18C), value,
                *(int *)((char *)arg0 + 0x178), stringBase + 0x1F0,
                *(int *)((char *)arg0 + 0x3C) + 0x4C, lbl_80562ECC, lbl_80562E88);
    fn_801EC59C((void *)(arg0 + 0x3D8), value,
                (int)(stringBase + 0x1FC),
                *(int *)((char *)arg0 + 0x3C) + 0x4C,
                lbl_80562ECC, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x1E0), value,
                *(int *)((char *)arg0 + 0x178), stringBase + 0x20C,
                *(int *)((char *)arg0 + 0x3C) + 0x34, lbl_80562E90, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x234), value,
                *(int *)((char *)arg0 + 0x178), stringBase + 0x218,
                *(int *)((char *)arg0 + 0x3C) + 0x2B0, lbl_80562E90, lbl_80562E88);
    fn_801EC214((void *)(arg0 + 0x288), value,
                *(int *)((char *)arg0 + 0x178), stringBase + 0x22C,
                *(int *)((char *)arg0 + 0x3C) + 0x2AC, lbl_80562ED0, lbl_80562ED4);
    fn_801EC214((void *)(arg0 + 0x2DC), value,
                *(int *)((char *)arg0 + 0x178), stringBase + 0x23C,
                *(int *)((char *)arg0 + 0x3C) + 0x2A0, lbl_80562ED0, lbl_80562ED4);
    fn_801EC214((void *)(arg0 + 0x330), value,
                *(int *)((char *)arg0 + 0x178), stringBase + 0x250,
                *(int *)((char *)arg0 + 0x3C) + 0x2B8, lbl_80562E90, lbl_80562E88);
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling invalid_target
long fn_801EEE38(void) {
    long *entries;
    long context;
    unsigned int i;
    long value;

    context = fn_80179CB0();
    entries = lbl_80488648;
    i = 0;
    goto check;

loop:
    fn_801EECAC(value, context);
    i++;
    entries++;
    if (i < 8u) {
        goto check;
    }
    return 0;

check:
    value = *entries;
    if (value != 0) {
        goto loop;
    }
    return value;
}
#pragma scheduling on
extern void fn_801EC750(void *);
extern int lbl_8033A2D4[64];
#pragma scheduling off
void **fn_801EEEB0(void **arg0) {
    fn_801EC750(arg0);
    *arg0 = &lbl_8033A2D4;
    return arg0;
}
#pragma scheduling on

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801EEEEC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_801EC9CC((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_801EEF44(void *arg0, void *arg1) {
    unsigned int index;
    unsigned int base;
    index = *(unsigned int *)((char *)arg1 + 0xFA8);
    base = *(unsigned int *)((char *)lbl_80488648 + index * 4);
    *(unsigned int *)((char *)arg0 + 0x16C) = base + 0x44;
    *(unsigned int *)((char *)arg0 + 0x170) = base + 0xC8;
    *(unsigned int *)((char *)arg0 + 0x174) = base + 0x148;
    fn_801EDD7C(arg0, (long)arg1);
}

unsigned int fn_801EEF74(void) { return 1; }

