// Code of main that had no source file yet: decomp.wtf gave it this one.
extern char lbl_8055EA21;
extern float lbl_8055E3C8;
__declspec(section ".data") extern float lbl_80558DC4;
extern float lbl_80562CB0, lbl_80562CB4, lbl_80562CB8, lbl_80562CBC, lbl_80562CC0, lbl_80562CC4;
extern int fn_80129D18(int, int);
extern float fn_80129DC4(int, float, float);
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EA20;
extern char lbl_804874D4[];
extern char lbl_804874B8[];
extern unsigned char lbl_8055EA22;
extern unsigned char lbl_8055EA22;
extern float lbl_80562CAC;
extern float lbl_80562CC8;
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562CD4;
void fn_801E1B30(void);
extern const char lbl_80339878[];
extern const char lbl_80339884[];
int *fn_801E1F44(void);
void *fn_80207848(const char *, int);
#pragma scheduling invalid_target
void fn_801E1874(void) {
    *(volatile int *)lbl_804874D4 = 0;
    *((volatile char *)lbl_804874D4 + 0x18) = 0;
    *((volatile char *)lbl_804874D4 + 4) = 0;
    lbl_8055EA22 = 0;
}
#pragma scheduling on
extern void *fn_802AE414(const char *);
extern int stricmp(const char *, const char *);
extern unsigned char lbl_8055AE60, lbl_8055AE68, lbl_8055AE6C, lbl_8055AE74, lbl_8055AE7C, lbl_8055AE84, lbl_8055AE8C, lbl_8055AE94, lbl_8055AE9C, lbl_8055AEA8;
extern unsigned char lbl_80339860[], lbl_8033986C[];
extern float lbl_80562CA8;
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma inline_depth(0)
extern "C" int fn_801E1894(void) {
 struct Vec { float x,y,z; };
 struct Settings {
 virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
 virtual float get(const char *); virtual void s10(); virtual void s11(); virtual void s12(); virtual Vec vector(const char *);
 };
 struct Obj {
 virtual void s2(); virtual int has(const char *); virtual void s4(); virtual void s5(); virtual char *text(const char *, const char *);
 virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual int flag(const char *); virtual int val(const char *, int);
 virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual Settings *child(const char *);
 };
 Obj *obj; Settings *settings; char *name; int r,g,b, n, raw;
 fn_801E1874();
 if (fn_802AE414((const char *)&lbl_8055AE60) != 0) {
  obj=(Obj *)fn_802AE414((const char *)&lbl_8055AE60);
  settings=obj->child((const char *)&lbl_8055AE68);
  name=obj->text((const char *)&lbl_8055AE6C,(const char *)&lbl_8055AE74);
  if(stricmp(name,(const char *)&lbl_8055AE7C)==0) *(int *)&lbl_804874D4=1;
  else if(stricmp(name,(const char *)&lbl_8055AE84)==0) *(int *)&lbl_804874D4=2;
  { int flag;
  if(obj->has((const char *)lbl_80339860)!=0)
   flag=obj->flag((const char *)lbl_80339860);
  else flag=(*(int *)&lbl_804874D4==1);
  lbl_8055EA22=flag;
  }
  *((unsigned char *)&lbl_804874D4+4)=obj->val((const char *)lbl_8033986C,0);
  if(settings) {
   const Vec &v = settings->vector((const char *)&lbl_8055AE8C);
   raw=(int)(lbl_80562CA8*v.x); n=raw&((-raw&~raw)>>31); r = n < 255 ? n : 255;
   raw=(int)(lbl_80562CA8*v.y); n=raw&((-raw&~raw)>>31); g = n < 255 ? n : 255;
   raw=(int)(lbl_80562CA8*v.z); n=raw&((-raw&~raw)>>31); b = n < 255 ? n : 255;
   *(int *)((char *)&lbl_804874D4+8)=((r & 255)<<16)|0xff000000|((g & 255)<<8)|(b & 255);
   *(float *)((char *)&lbl_804874D4+0xc)=settings->get((const char *)&lbl_8055AE94);
   *(float *)((char *)&lbl_804874D4+0x10)=settings->get((const char *)&lbl_8055AE9C);
   *(float *)((char *)&lbl_804874D4+0x14)=settings->get((const char *)&lbl_8055AEA8);
   *((unsigned char *)&lbl_804874D4+0x18)=1;
  }
 }
 lbl_8055EA20=1;
}
#pragma pop
extern float __fabsf(float);
extern double __fabs(double);
#pragma scheduling invalid_target
#pragma push
#pragma processor 750
void fn_801E1B30(void) {
    float temp = lbl_8055E3C8;
    char *state = lbl_804874B8;
    int zero;

    zero = 0;
    if (fn_80129D18(4, 0x12C) == 0 || (unsigned char)lbl_8055EA21 != 0) {
        if (*(int *)state == 1 || (unsigned char)lbl_8055EA21 != 0) {
            if (fn_80129D18(4, 0xA) < 6 || (unsigned char)lbl_8055EA21 != 0) {
                *(int *)state = 2;
                *(float *)(state + 0x10) = fn_80129DC4(4, lbl_80562CAC, lbl_80562CB0);
            } else {
                *(int *)state = 3;
                *(float *)(state + 0xC) = temp + fn_80129DC4(4, lbl_80562CB4, lbl_80562CB8);
            }
            *(float *)(state + 8) = fn_80129DC4(4, lbl_80562CB8, lbl_80562CBC);
        } else if (*(float *)(state + 4) > *(float *)(state + 8)) {
            *(float *)(state + 8) = fn_80129DC4(4, *(float *)(state + 4), lbl_80562CC0);
        }
    }

    lbl_8055EA21 = zero;
    if (*(int *)state != 1) {
        float target = *(float *)(state + 8);
        float current = *(float *)(state + 4);
        if ((float)__fabs((double)(target - current)) < lbl_80562CC4) {
            if ((float)__fabs((double)target) <= lbl_80558DC4) {
                goto set_mode;
            }
            *(float *)(state + 8) = lbl_80562CAC;
            goto after_mode;
        set_mode:
            *(int *)state = 1;
        after_mode:
            ;
        }
        *(float *)(state + 4) =
            *(float *)(state + 4) +
            lbl_80562CB4 * (*(float *)(state + 8) - *(float *)(state + 4));
    }

    if (*(void **)(lbl_804874B8 + 0x18) != 0 &&
        *(float *)(state + 0xC) > lbl_80562CAC &&
        temp > *(float *)(state + 0xC)) {
        unsigned char *obj = *(unsigned char **)(lbl_804874B8 + 0x18);
        if (obj[0x19] != 0) {
            obj[0x4C] = 1;
            obj[0x4A] = 0;
        } else {
            obj[0x49] = 1;
            obj[0x4B] = 0;
            obj[0x4A] = 0;
        }
        *(float *)(state + 0xC) = lbl_80562CC8;
    }
}
#pragma pop
#pragma scheduling on
void fn_801E1D20(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D2C(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D38(void) {
    if (*fn_801E1F44() == 1) {
        *(void **)(lbl_804874B8 + 0x14) = fn_80207848(lbl_80339878, 2);
        *(void **)(lbl_804874B8 + 0x18) = fn_80207848(lbl_80339884, 2);
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801E1D9C(void) {
    struct Dummy_801E1D9C_Local {
        virtual void d1(int);
    };
    typedef Dummy_801E1D9C_Local *LocalPtr;
    // try recompute base
    if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x18) != 0) {
        if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x18) != 0) {
            ((LocalPtr)*(LocalPtr *)((char *)&lbl_804874B8 + 0x18))->d1(1);
        }
        *(void **)((char *)&lbl_804874B8 + 0x18) = 0;
    }
    if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x14) != 0) {
        if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x14) != 0) {
            ((LocalPtr)*(LocalPtr *)((char *)&lbl_804874B8 + 0x14))->d1(1);
        }
        *(void **)((char *)&lbl_804874B8 + 0x14) = 0;
    }
}
#pragma pop
void fn_801E1E30(void) {
    int v = lbl_8055EA22;
    *((float *)&lbl_804874B8 + 1) = lbl_80562CAC;
    *(int *)&lbl_804874B8 = (-v | v) >> 31 & 1;
    *((float *)&lbl_804874B8 + 2) = lbl_80562CAC;
    *((float *)&lbl_804874B8 + 3) = lbl_80562CC8;
}

extern int fn_801E1894(void);
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562CD4;
extern void fn_801E1B30(void);
void fn_801E1E64(void) {
    void *p = *(void **)(lbl_804874B8 + 0x14);
    if (p != 0) {
        *(unsigned char *)((char *)p + 0x4A) = 0;
        *(unsigned char *)((char *)p + 0x4B) = 1;
        *(unsigned char *)((char *)p + 0x49) = 1;
    }
    if (*(int *)lbl_804874B8 != 0)
        fn_801E1B30();
}

void fn_801E1EA4(void *arg0) {
    void *var_r6;
    int var_r7;
    float c0 = lbl_80562CAC;
    float c1 = lbl_80562CD4;
    float c3 = lbl_80562CD0;
    float c2 = lbl_80562CCC;
    float tmp;
    var_r6 = (char *)arg0 + 4;
    var_r7 = 0;
    goto check;
loop:
    switch (*(int *)&lbl_804874B8) {
    case 2:
        tmp = *(float *)((char *)&lbl_804874B8 + 4);
        *(float *)((char *)var_r6 + 0xD4) = c2 * tmp;
        tmp = *(float *)((char *)&lbl_804874B8 + 4);
        *(float *)((char *)var_r6 + 0xD8) = c3 * tmp;
        tmp = *(float *)((char *)&lbl_804874B8 + 0x10);
        *(float *)((char *)var_r6 + 0xDC) = tmp;
        break;
    case 3:
        *(float *)((char *)var_r6 + 0xD4) = c0;
        tmp = *(float *)((char *)&lbl_804874B8 + 4);
        *(float *)((char *)var_r6 + 0xD8) = c1 * tmp;
        *(float *)((char *)var_r6 + 0xDC) = c0;
        break;
    default:
        *(float *)((char *)var_r6 + 0xD4) = c0;
        *(float *)((char *)var_r6 + 0xD8) = c0;
        *(float *)((char *)var_r6 + 0xDC) = c0;
        break;
    }
    var_r6 = (char *)var_r6 + 0xE0;
    var_r7 += 1;
check:
    if (var_r7 < *(int *)((char *)arg0 + 0x394))
        goto loop;
}

int *fn_801E1F44(void) {
    if ((unsigned char)lbl_8055EA20 == 0)
        fn_801E1894();
    return (int *)&lbl_804874D4;
}

extern char lbl_8055EA21;
extern float lbl_8055E3C8;
extern float lbl_80558DC4;
extern float lbl_80562CB0, lbl_80562CB4, lbl_80562CB8, lbl_80562CBC, lbl_80562CC0, lbl_80562CC4;
extern int fn_80129D18(int, int);
extern float fn_80129DC4(int, float, float);
void fn_801E1F78(void) {
    lbl_8055EA21 = 1;
}
typedef struct { int pad0; float x; float y; float z; char pad10[4]; void *p14; void *p18; } Obj;
