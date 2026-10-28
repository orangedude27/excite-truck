// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int lbl_80499E50[];
extern double lbl_80563C38;
extern int lbl_8055C4B4;
extern int lbl_8055C4B8;
extern float lbl_8055C4BC;
extern float lbl_80563C30;
extern void fn_80135DC4(void *, int, int);
extern float fn_80134E34(float);
extern void fn_80136468(int *, void *, float);
extern float lbl_80563C28;
extern float lbl_80563C9C;
extern char lbl_80499950[];
extern void fn_80128670(void);
extern void fn_8013530C(void *, int);
extern void fn_80268BD4(void *, int, float, float);

extern char lbl_8055F488;
extern float lbl_8055F484;
extern float lbl_80499980[8];
extern float lbl_80563C6C;
extern float lbl_80563C20;
void fn_802693F4(void);
extern void fn_80265E08(void*);
extern float lbl_80563C24;
extern float lbl_80563C44;
extern float lbl_80563C48;
extern float lbl_80563C2C;
extern float lbl_80563C34;
extern float lbl_80563C4C;
extern float lbl_80563C50;
extern float lbl_80563C98;
extern char lbl_80499920[];
extern float lbl_8055C4E0;
extern float lbl_8055C4E4;
extern int lbl_8055C4E8;
extern int lbl_8055C4EC;
extern int lbl_804999A0[];
extern float fn_80129DC4(int, float, float);
extern int fn_80129D90(int, int, int);
extern float PSVECMag(void*);
void* fn_80265DD8(void* arg0) {
    fn_80265E08(arg0);
    return arg0;
}

void fn_80265E08(void* arg0) {
    float zero = lbl_80563C20;
    *(int*)((char*)arg0 + 0) = 0;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = 0;
}

void fn_80265E2C(void) {
    #pragma scheduling invalid_target
    struct Record { float x; float y; int value; };
    float scale = lbl_80563C24;
    struct Record *record = (struct Record *)lbl_804999A0;
    int count = 0;

    do {
        record->x = scale * fn_80129DC4(6, -lbl_8055C4E0, lbl_8055C4E0);
        record->y = scale * fn_80129DC4(6, -lbl_8055C4E4, lbl_8055C4E4);
        {
            int value = fn_80129D90(6, lbl_8055C4E8, lbl_8055C4EC);
            count++;
            record->value = value;
        }
        record++;
    } while (count < 0x64);
}

void fn_80266070(void *arg0, void *arg1, void *arg2, void *arg3) {
    volatile float scaled[3];
    float mag;
    float f;
    float y;
    float xOut;
    float yOut;
    float zOut;
    float *out = (float *)arg1;
    float *base = (float *)arg2;
    float scale = *(float *)((char *)arg0 + 0x10);
    scaled[0] = *(float *)((char *)arg3 + 0) * scale;
    scaled[1] = *(float *)((char *)arg3 + 4) * scale;
    scaled[2] = *(float *)((char *)arg3 + 8) * scale;
    mag = PSVECMag(arg3);
    f = *(float *)((char *)arg0 + 0x14) * mag;
    y = scaled[1] + f;
    xOut = base[0] + scaled[0];
    yOut = base[1] + y;
    zOut = base[2] + scaled[2];
    out[0] = xOut;
    out[1] = yOut;
    out[2] = zOut;
}

extern float lbl_8055C4C0;
extern float lbl_80563C2C;
extern float lbl_8055C4C4;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
void fn_80266150(void *arg0);
int fn_80178CA4(void);
float PSQUATMultiply(float *arg0, int arg1);
void *fn_80266120(void *arg0) {
    fn_80266150(arg0);
    return arg0;
}

void fn_80266150(void *arg0) {
    *(float *)((char *)arg0 + 0xC) = lbl_80563C2C;
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0) = 0;
    *(float *)((char *)arg0 + 8) = lbl_8055C4C0;
}

void fn_80266170(void *arg0, int arg1, int arg2, int arg3, float farg0) {
    float var_f0;
    float temp_f0;
    float temp_f0_2;
    float temp_f4;
    float var_f3;
    float var_f4;
    int temp_r0;
    int temp_r0_2;

    if (arg3 != 0) {
        *(int *)((char *)arg0 + 0) = arg1;
        *(int *)((char *)arg0 + 4) = 0;
        var_f0 = lbl_8055C4BC * farg0;
        if (var_f0 >= lbl_8055C4C0) var_f0 = lbl_8055C4C0;
        *(float *)((char *)arg0 + 8) = var_f0;
    }
    if (arg2 != 0) {
        *(int *)((char *)arg0 + 0) = arg1;
        return;
    }
    temp_r0 = arg1 - *(int *)((char *)arg0 + 0);
    *(int *)((char *)arg0 + 0) = arg1;
    temp_r0_2 = *(int *)((char *)arg0 + 4) + temp_r0;
    *(int *)((char *)arg0 + 4) = temp_r0_2;
    var_f4 = lbl_80563C2C;
    temp_f0 = (float)lbl_8055C4B4;
    temp_f0_2 = ((float)temp_r0_2 - temp_f0) / ((float)lbl_8055C4B8 - temp_f0);
    if (var_f4 >= temp_f0_2) var_f4 = temp_f0_2;
    if (var_f4 <= lbl_80563C20) var_f4 = lbl_80563C20;
    var_f3 = lbl_80563C28;
    temp_f4 = lbl_80563C20 + (var_f4 * lbl_80563C2C);
    if (temp_f4 >= var_f3) {
        if (temp_f4 > lbl_80563C2C) {
            var_f3 = lbl_80563C2C;
        } else if (temp_f4 > lbl_80563C20) {
            var_f3 = (temp_f4 * (lbl_80563C30 * temp_f4 * temp_f4)) +
                     (lbl_80563C34 * temp_f4 * temp_f4);
        } else {
            var_f3 = (temp_f4 * (lbl_80563C30 * temp_f4 * temp_f4)) -
                     (lbl_80563C34 * temp_f4 * temp_f4);
        }
    }
    *(float *)((char *)arg0 + 0xC) = var_f3;
}

void fn_802662D8(float *arg0, float *arg1, float *arg2, float *arg3, int arg4) {
    float t;
    float weight;
    float factor;
    float x;
    float y;
    float z;

    t = PSQUATMultiply(arg2, arg4) - lbl_8055C4C4;
    weight = arg0[3];
    t = t - lbl_80563C20;
    factor = lbl_80563C20 + weight * t;
    x = arg2[0] + arg3[0] * factor;
    y = arg2[1] + arg3[1] * factor;
    z = arg2[2] + arg3[2] * factor;
    arg1[0] = x;
    arg1[1] = y;
    arg1[2] = z;
}

void fn_802670A0(int arg0, int *arg1) {
    int count;
    int x;
    int y;
    int div;
    int a;
    int b;
    count = fn_80178CA4();
    x = count ^ 1;
    y = x >> 1;
    x &= count;
    y -= x;
    y = ((unsigned int)y) >> 31;
    y += 1;
    div = (count + y - 1) / y;
    a = lbl_8055CFF0 / y;
    b = lbl_8055CFF4 / div;
    arg1[16] = a;
    arg1[17] = b;
    arg1[14] = a * (arg0 / div);
    arg1[15] = b * (arg0 % div);
}

#pragma scheduling invalid_target
void fn_80267130(void *arg0) {
    float value;
    float clamp;
    clamp = lbl_80563C2C;
    value = (*(float *)((char *)arg0 + 0x30) - lbl_80563C44) / lbl_80563C48;
    clamp = clamp < value ? value : clamp;
    clamp = clamp > lbl_80563C20 ? lbl_80563C20 : clamp;
    *(float *)((char *)arg0 + 0x48) = lbl_80563C34 + clamp * lbl_80563C4C;
    if (fn_80178CA4() == 1) value = lbl_80563C2C;
    else value = lbl_80563C50;
    *(float *)((char *)arg0 + 0x4C) = lbl_8055F484 * value;
}
#pragma scheduling on
extern float lbl_8055D020;
extern double lbl_80563C38;
extern float fn_801EA0E8(unsigned int, float, float, float);
void fn_802671CC(void *arg0, int arg1) {
    float corner[3];
    float z = *(float *)((char *)arg0 + 0x48);
    float dx = z * *(float *)((char *)arg0 + 0x34);
    float xstep = dx / lbl_8055D020;
    float ystep;
    float best = lbl_80563C20;
    int i;
    unsigned int hi = 0x43300000;
    double d;
    *((unsigned int *)&d + 1) = (unsigned int)(*(int *)((char *)arg0 + 0x44) ^ 0x80000000);
    *((unsigned int *)&d) = hi;
    ystep = (float)((d - lbl_80563C38) * dx / lbl_8055D020);
    for (i = 0; i < 4; i++) {
        float x = (i & 1) ? xstep : -xstep;
        float y = (i & 2) ? ystep : -ystep;
        float *m = (float *)arg0;
        corner[0] = x*m[0] + y*m[3] + z*m[6] + m[9];
        corner[1] = x*m[1] + y*m[4] + z*m[7] + m[10];
        corner[2] = x*m[2] + y*m[5] + z*m[8] + m[11];
        fn_801EA0E8(0x43300000, corner[0], corner[1], corner[2]);
        if (best > corner[1]) best = corner[1];
    }
    if (*(int *)((char *)arg0 + 0x58) != 0x11 && *(int *)((char *)arg0 + 0x58) != 0x15)
        *(float *)((char *)arg0 + 0x28) += best;
    (void)arg1;
}

extern void *lbl_8055F490;
extern int lbl_8055F494;
extern void *fn_80267EE4(int);
extern void fn_801EF024(void *);
extern void fn_80278288(void);
extern void fn_802733F0(void);
extern void fn_80209110(void *);
extern float lbl_8055E3C8;
void *fn_802678E4(int arg0) {
    return fn_80267EE4(arg0);
}

void fn_80267E40(unsigned int arg0, float arg1, int arg2) {
    float temp_f29;
    float temp_f30;
    float temp_f31;
    int i;
    void *p;
    temp_f29 = lbl_8055E3C8;
    temp_f30 = lbl_80563C6C;
    temp_f31 = lbl_80563C2C;
    for (i = 0; i < 4; i++) {
        p = fn_80267EE4(i);
        if (*(unsigned int *)((char *)p + 0x140) == arg0) {
            if (arg1 > *(float *)((char *)p + 0x154) * (temp_f31 - ((temp_f29 - *(float *)((char *)p + 0x158)) / temp_f30))) {
                *(float *)((char *)p + 0x158) = temp_f29;
                *(float *)((char *)p + 0x154) = arg1;
                return;
            }
        }
    }
}

extern void fn_802734F0(void);
extern char lbl_80499080[];
extern float lbl_80499050[];
extern float lbl_8055F47C;
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern int lbl_8055F4A0;
extern int lbl_8055F4A4;
extern int lbl_8055F4A8;
extern void fn_801E9DC4(int *);
void fn_80267EE0(void) {
    fn_802734F0();
}

void *fn_80267EE4(int arg0) {
    return lbl_80499080 + arg0 * 0x228;
}

void fn_802682B0(void *arg0) {
    char *p = (char *)arg0;
    float *base;
    if (*(unsigned char *)(p + 0x138) != 0) {
        float b;
        float a;
        float *q;
        a = lbl_80563C2C;
        q = lbl_80499050 - 1;
        b = lbl_80563C20;
        *++q = a;
        q[1] = b; q[2] = b; q[3] = b;
        q[4] = a;
        q[5] = b; q[6] = b; q[7] = b;
        q[8] = a;
        q[9] = b; q[10] = b; q[11] = b;
    }
    base = lbl_80499050;
    fn_801BFD34(p + 0x7c, base + 9, p + 0xc0);
    fn_80015B20(p + 0x58, base, p + 0xc0);
    *(float *)(p + 0xbc) = lbl_8055F47C;
}

void fn_80268B94(int arg0) {
    lbl_8055F4A0 = arg0;
    lbl_8055F4A4 = arg0;
    fn_801E9DC4(&lbl_8055F4A8);
}

extern char lbl_80499920[];
extern float lbl_80563C44, lbl_80563C48, lbl_80563C2C, lbl_80563C34, lbl_80563C4C, lbl_80563C50;
extern float lbl_80563C98;
extern int fn_80178CA4(void);
int fn_80268BA4(int arg0) {
    unsigned int shift = arg0 - 4;
    int result = 0;
    if (shift > 0x13)
        goto done;
    if (!((1U << shift) & 0x80037))
        goto done;
    result = 1;
done:
    return result;
}

extern float lbl_80563C20, lbl_80563C2C, lbl_80563C8C, lbl_80563C90, lbl_80563C94;
extern float fn_8002F234(void*, float, float, float, float, float, float, float, float);
extern void fn_801EA140(void*, float, float, float, float, float, float, float);
extern void PSVECCrossProduct(void*, void*, void*);
extern double cos(float);
extern double sin(float);
void fn_80268BD4(void *out, int arg1, float t, float angle) {
    float *inp=(float*)arg1;
    float *b = *(float **)((char *)inp + 0x14);
    float x,y,z,w,mag,scale,xx,yy,rot,cs,sn;
    x=inp[2]; y=inp[3]; z=inp[0]; w=inp[1];
    x += t*(b[2]-x); y += t*(b[3]-y); z += t*(b[0]-z); w += t*(b[1]-w);
    mag=fn_8002F234(b,x*x+y*y,x*x,y*t,w,z,inp[0],y,x);
    scale=lbl_80563C2C/mag; xx=x*scale; yy=y*scale;
    *(float*)((char*)out+0x28)=lbl_80563C20;
    rot=lbl_80563C8C*inp[10]-lbl_80563C90;
    cs=yy*rot; sn=-xx*rot;
    *(float*)((char*)out+0x24)=w+cs; *(float*)((char*)out+0x2c)=inp[1]+sn;
    fn_801EA140((char*)out+0x24,inp[1],w+cs,cs,rot,-xx,yy,xx);
    *(float*)((char*)out+0x28)+=lbl_80563C94;
    cs=cos(angle); sn=sin(angle);
    *(float*)((char*)out+0xc)=lbl_80563C20; *(float*)((char*)out+0x10)=lbl_80563C2C; *(float*)((char*)out+0x14)=lbl_80563C20;
    *(float*)((char*)out+0x18)=xx*cs-yy*sn; *(float*)((char*)out+0x1c)=lbl_80563C20; *(float*)((char*)out+0x20)=xx*sn+yy*cs;
    PSVECCrossProduct((char*)out+0xc,(char*)out+0x18,out);
}

void fn_80268D94(void) {
    struct {
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        int g;
        int h;
        int i;
        int j;
        int k;
        int l;
        int m;
        int n;
        int o;
        int p;
        int q;
        int r;
        int s;
    } sp8;
    int sp58;
    fn_80135DC4(&sp8, 0, 0);
    fn_80268BD4(lbl_80499920, *(int *)&sp8 + 0x1c, lbl_80563C20, lbl_80563C98);
    if (sp58 != 0) {
        fn_80128670();
    }
    sp58 = 0;
    fn_8013530C(&sp8, 0);
}

void fn_80268E00(void) {
    #pragma scheduling invalid_target
    struct Result {
        int value;
        float fraction;
        int mode;
        int padding;
    } result;
    struct Object {
        char pad2c[0x2C];
        void *context;
        char pad30[0x20];
        int resource;
        int field54;
        int field58;
    } object;

    fn_80135DC4(&object, 0, 0);
    fn_80136468((int *)&result, &object, fn_80134E34(lbl_80563C28));
    if (result.value == 0) {
        result.value = *(int *)((char *)object.context + 0x1C);
    }
    fn_80268BD4(lbl_80499950, result.value, result.fraction, lbl_80563C9C);
    if (object.resource != 0) {
        ((void (*)(int))fn_80128670)(object.resource);
    }
    object.resource = 0;
    fn_8013530C(&object, 0);
}

#pragma dont_inline on
void fn_8026A248(int arg0, int arg1) {
    *(int *)((char *)fn_80267EE4(arg1) + 0x24) = arg0;
}
extern void fn_802735F4(int, int);
extern void fn_80135DC4(void *, int, int);
extern float fn_80134E34(float);
extern void fn_80136468(int *, void *, float);
extern void fn_80128670(void);
extern void fn_8013530C(void *, int);
extern void fn_80268BD4(void *, int, float, float);
extern float lbl_80563C28;
extern float lbl_80563C9C;
extern char lbl_80499950[];
#pragma push
#pragma scheduling invalid_target
int fn_8026A27C(int arg0) {
    int value = lbl_80499E50[arg0];
    lbl_80499E50[arg0] = 0;
    return value;
}
#pragma pop
void fn_8026A298(int arg0) {
    lbl_80499E50[arg0] = -1;
}

extern void fn_801EA994(void);
extern int lbl_80499E50[];
void fn_8026A2B0(int arg0) {
    lbl_80499E50[arg0] = 1;
}

void fn_8026A2C8(void) {
    fn_801EA994();
}

#pragma scheduling invalid_target
#pragma scheduling on
void fn_8026A2CC(int *arg0, int arg1, float arg2) {
    int *dst = (int *)((char *)lbl_80499080 + arg1 * 0x228 + 0x1a4);
    int *src = arg0;
    int a = src[0];
    int b = src[1];
    int c = src[2];
    int d = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
    dst[9] = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
    *(float *)(dst + 12) = arg2;
}
int fn_8026A344(int arg0) {
    return *(int *)((char *)fn_80267EE4(arg0) + 0x20);
}
void *fn_80267EE4();
int fn_8026A368(void) {
    return *(int *)((char *)fn_80267EE4() + 0x10);
}
int fn_802678C0(void) {
    return (int)fn_80267EE4() + 0x58;
}
char fn_8026A38C(void) {
    return lbl_8055F488;
}

extern float lbl_80563CBC, lbl_80563C2C, lbl_80563C20, lbl_8055E3C8;
void fn_8026A394(void *arg0) {
 int i = 0;
 while (i < 4) {
  char *p = (char *)fn_80267EE4(i);
  if (*(void **)(p + 0x140) == arg0) {
   char *q;
   volatile unsigned int *src;
   volatile unsigned int *dst;
   unsigned int one;
   float factor;
   float threshold;
   float zero;
   float copy;
   unsigned int value1;
   unsigned int value0;
   unsigned int value3;
   unsigned int value2;
   unsigned int value5;
   unsigned int value4;
   unsigned int value7;
   unsigned int value6;
   unsigned int value8;
   unsigned int value10;
   unsigned int value9;
   unsigned int value11;
   one = 1;
   factor = *(volatile float *)&lbl_80563CBC;
   *(volatile unsigned char *)(p + 0x139) = one;
   threshold = lbl_80563C2C;
   *(volatile unsigned char *)(p + 0x138) = one;
   q = *(char * volatile *)(p + 0x140);
   factor = *(float *)(q + 0x25d4) * factor;
   *(float *)(p + 0x13c) = threshold < factor ? factor : threshold;
   zero = lbl_80563C20;
   *(float *)(p + 0x154) = zero;
   *(float *)(p + 0x158) = zero;
   src = (volatile unsigned int *)(p + 0x58);
   dst = (volatile unsigned int *)(p + 0x1f8);
   value0 = src[0];
   value1 = src[1];
   dst[0] = value0;
   dst[1] = value1;
   src = (volatile unsigned int *)(p + 0x60);
   dst = (volatile unsigned int *)(p + 0x200);
   value2 = src[0];
   value3 = src[1];
   dst[0] = value2;
   dst[1] = value3;
   src = (volatile unsigned int *)(p + 0x68);
   dst = (volatile unsigned int *)(p + 0x208);
   value4 = src[0];
   value5 = src[1];
   dst[0] = value4;
   dst[1] = value5;
   src = (volatile unsigned int *)(p + 0x70);
   dst = (volatile unsigned int *)(p + 0x210);
   value6 = src[0];
   value7 = src[1];
   dst[0] = value6;
   dst[1] = value7;
   src = (volatile unsigned int *)(p + 0x78);
   dst = (volatile unsigned int *)(p + 0x218);
   value8 = src[0];
   dst[0] = value8;
   src = (volatile unsigned int *)(p + 0x7c);
   dst = (volatile unsigned int *)(p + 0x21c);
   value9 = src[0];
   value10 = src[1];
   dst[0] = value9;
   dst[1] = value10;
   src = (volatile unsigned int *)(p + 0x84);
   dst = (volatile unsigned int *)(p + 0x224);
   value11 = src[0];
   dst[0] = value11;
   copy = *(float *)(p + 0xbc);
   *(float *)(p + 0x1f4) = copy;
   copy = lbl_8055E3C8;
   *(float *)(p + 0x1f0) = copy;
   return;
  }
  i++;
 }
}

  extern void fn_80269BB0(void);
  void fn_8026A49C(void) {
    fn_80269BB0();
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8026A4A0(int arg0, int *arg1, float *arg2) {
    char *base = (char *)lbl_80499080 + arg0 * 0x228;
    arg1[0] = *(int *)(base + 0x58);
    arg1[1] = *(int *)(base + 0x5c);
    arg1[2] = *(int *)(base + 0x60);
    arg1[3] = *(int *)(base + 0x64);
    arg1[4] = *(int *)(base + 0x68);
    arg1[5] = *(int *)(base + 0x6c);
    arg1[6] = *(int *)(base + 0x70);
    arg1[7] = *(int *)(base + 0x74);
    arg1[8] = *(int *)(base + 0x78);
    arg1[9] = *(int *)(base + 0x7c);
    arg1[10] = *(int *)(base + 0x80);
    arg1[11] = *(int *)(base + 0x84);
    *arg2 = *(float *)(base + 0xbc);
}
#pragma pop
extern float lbl_8055F484;
extern float lbl_80563C6C;
extern float lbl_80499980[8];
extern float lbl_80563C20;
void fn_802693F4(void);
void fn_8026A51C(void) {
    fn_802693F4();
}

float fn_8026A520(int arg0) {
    if (arg0 >= 0 && (unsigned int)arg0 < 8U) {
        return lbl_80499980[arg0];
    }
    return lbl_80563C20;
}

void fn_8026A54C(float arg0) {
    lbl_8055F484 = arg0;
}

int fn_8026A554(int *arg0) {
    int index = *arg0;
    if (index >= 0 && (unsigned int)index < 8U) {
        lbl_80499980[index] = lbl_80563C6C;
    }
    return 4;
}
extern float lbl_80563C20;
extern int lbl_80499E50[];
