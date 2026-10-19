#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float fabsf(float);
extern void *lbl_8055D350;
extern f32 lbl_80560368, lbl_805603B4, lbl_80560360, lbl_8056039C, lbl_805603A0, lbl_805603A4, lbl_805603A8, lbl_805603AC, lbl_80562068;
extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[], lbl_802FCE88[];
extern u8 lbl_802FCD44[], lbl_802FCD78[], lbl_80558BA0[];
extern void fn_80013EDC(void *, s32, void *, void *, f32, f32, f32);
extern void fn_801476C4(void);
extern u8 lbl_80558BBC[], lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
extern void *lbl_803577E0[];
extern u8 lbl_802FCBEC[], lbl_802FCBF8[], lbl_802FCBC8[];
extern s32 fn_802C9A58(void);
extern void fn_80013BD0();
typedef struct { void *vtable; s32 field4; } VtblObj;
extern f32 lbl_80560360, lbl_80560368, lbl_8056036C, lbl_80560370, lbl_80560374, lbl_80560398;
extern f32 fn_801E7E24(void);
extern f32 fn_801E7E24(void);
extern f32 lbl_80560360, lbl_80560364, lbl_80560398;
extern u8 lbl_802FCB98[];
extern void fn_80130FCC(void *, s32, s32);
extern void fn_801473F8(void *, void *, ...);
#pragma push
#pragma use_lmw_stmw off
void fn_80013BD0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char first[20];
    char second[20];
    u8 *base = lbl_802FCB98;
    ((void (*)(void *, void *))(*(void ***)arg0)[3])(arg0, base);
    fn_801476C4();
    ((void (*)(void *, void *))(*(void ***)arg0)[3])(arg0, base + 0xC);
    fn_801476C4();
    fn_80130FCC(first, 20, arg1);
    fn_801473F8(arg0, base + 0x1C, first);
    if (arg3) {
        fn_80130FCC(second, 20, arg2);
        fn_801473F8(arg0, base + 0x30, second);
    }
}
#pragma pop
void fn_80013C98(f32 *arg0) {
    f32 value;
    if (fn_801E7E24() > lbl_80560360) {
        value = fn_801E7E24() / lbl_80560364;
        value = *arg0 + value;
        value = value < lbl_80560368 ? value : lbl_80560368;
        *arg0 = value;
    }
}

void fn_80013CFC(f32 *arg0) {
    f32 value;
    if (fn_801E7E24() > lbl_80560360) {
        value = fn_801E7E24() / lbl_80560364;
        value = *arg0 - value;
        value = value > lbl_80560360 ? value : lbl_80560360;
        *arg0 = value;
    }
}

f32 fn_80013D60(f32 x) {
    f32 y;
    if (lbl_80560360 != x) {
        if (lbl_80560368 == x) {
            return x;
        }
        y = lbl_8056036C;
        if (x < y) {
        } else if (x > lbl_80560368) {
            y = lbl_80560368;
        } else if (x > lbl_80560360) {
            y = (x * (lbl_80560370 * x * x)) + (lbl_80560374 * x * x);
        } else {
            y = (x * (lbl_80560370 * x * x)) - (lbl_80560374 * x * x);
        }
        return y;
    }
    return x;
}

void fn_80013DF0(s32 arg0) {
    void *obj = *(void **)((u8 *)lbl_803577E0[arg0] + 0x50);
    void **vt = *(void ***)obj;
    ((void (*)(void *, void *))vt[3])(obj, lbl_802FCBEC);
}

void fn_80013E1C(s32 arg0) {
    void *obj;
    void **vt;
    if (fn_802C9A58()) {
        obj = *(void **)((u8 *)lbl_803577E0[arg0] + 0x50);
        vt = *(void ***)obj;
        ((void (*)(void *, void *))vt[3])(obj, lbl_802FCBF8);
    } else {
        obj = *(void **)((u8 *)lbl_803577E0[arg0] + 0x50);
        vt = *(void ***)obj;
        ((void (*)(void *, void *))vt[3])(obj, lbl_802FCBC8);
    }
}

void fn_80013EAC(s32 arg0, s32 arg1) {
    void *obj = *(void **)((u8 *)lbl_803577E0[arg0] + 0x50);
    if (arg1 < 1) arg1 = 1;
    fn_80013BD0(obj, arg1, 0, 0);
}

void fn_80014638(void *arg0) {
    f32 zero;
    s32 a;
    f32 one;
    s32 six;
    zero = lbl_80560368;
    a = 0;
    one = lbl_80560398;
    six = 6;
    *(s32 *)((u8 *)arg0 + 0x14) = six;
    *(f32 *)((u8 *)arg0 + 0x1C) = one;
    *(u8 *)((u8 *)arg0 + 0x20) = a;
    *(f32 *)((u8 *)arg0 + 0x2C) = zero;
    *(f32 *)((u8 *)arg0 + 0x28) = zero;
    *(s32 *)((u8 *)arg0 + 0x24) = a;
}

extern u8 lbl_802FCE18[];
extern void fn_8001A04C(void *);
extern void fn_802CAC54(s32);
extern void fn_80235380(void *);
extern void fn_80128668(void *);
#pragma push
#pragma use_lmw_stmw off
void *fn_80014664(void *arg0, s32 arg1) {
    void *obj;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_802FCE18;
        lbl_803577E0[*(s32 *)((u8 *)arg0 + 4)] = 0;
        obj = *(void **)((u8 *)arg0 + 0x50);
        if (obj != 0) {
            void (*fn)(void *, s32) = ((void (**)(void *, s32))(*(void **)obj))[2];
            fn(obj, 1);
        }
        fn_8001A04C(*(void **)((u8 *)arg0 + 0x48));
        *(void **)((u8 *)arg0 + 0x48) = 0;
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x44));
        *(s32 *)((u8 *)arg0 + 0x44) = -2;
        fn_80235380(*(void **)((u8 *)arg0 + 0x40));
        *(void **)((u8 *)arg0 + 0x40) = 0;
        fn_80235380(*(void **)((u8 *)arg0 + 0x3C));
        *(void **)((u8 *)arg0 + 0x3C) = 0;
        fn_80235380(*(void **)((u8 *)arg0 + 0x34));
        *(void **)((u8 *)arg0 + 0x34) = 0;
        fn_80235380(*(void **)((u8 *)arg0 + 0x38));
        *(void **)((u8 *)arg0 + 0x38) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop

void fn_80014750(void *arg0) {
    void *manager;
    void *state;
    f32 value;
    if (*(u8 *)((u8 *)arg0 + 8)) {
        manager=lbl_8055D350;
        if (lbl_80562068-lbl_8056039C <= *(f32 *)((u8 *)manager+0x10)-*(f32 *)((u8 *)*(void **)((u8 *)manager+0xC)+0xC)) return;
        fn_8000C630(0x17,-1);
        return;
    }
    manager=lbl_8055D350;
    state=*(void **)((u8 *)manager+0xC);
    value=*(f32 *)((u8 *)state+0x10);
    if (!(value>lbl_8056039C && value<lbl_805603A0) && !(value>lbl_805603A4)) return;
    if (!((*(u32 *)((u8 *)*(void **)((u8 *)manager+0x2C)+0x2C0)&0x20)!=0)) return;
    fn_8000C630(0x17,-1);
}

void fn_8001480C(void *arg0) {
 *(f32 *)((u8 *)arg0+0x10)=*(f32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x2C)+0x4C);
}

void fn_80014820(void *arg0) {
 void *p;
 f32 f;
 *(f32 *)((u8 *)arg0+0xC)=*(f32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x2C)+0x34);
 p=*(void **)((u8 *)lbl_8055D350+0x2C);
 f=lbl_805603A8*(fabsf(*(f32 *)((u8 *)arg0+0x10)-*(f32 *)((u8 *)p+0x4C))/lbl_805603A0);
 if (lbl_80560368<f) {} else { lbl_80560368=f; }
 if (lbl_80560368>lbl_805603AC) {} else { lbl_80560368=lbl_805603AC; }
 *(f32 *)((u8 *)arg0+0x10)=*(f32 *)((u8 *)arg0+0x10)+(lbl_80560368*(*(f32 *)((u8 *)p+0x4C)-*(f32 *)((u8 *)arg0+0x10)));
}

void fn_80014A98(void *arg0) {
 void *p=*(void **)((u8 *)lbl_8055D350+0x30);
 fn_80013EDC(lbl_802FCD44,0,lbl_802FCD78,lbl_80558BA0,*(f32 *)((u8 *)arg0+0x2C),*(s32 *)((u8 *)p+0x24)==3?*(f32 *)((u8 *)p+0x1C):*(f32 *)((u8 *)p+0x14),lbl_80560360);
}

s32 fn_80014ADC(void) { return 0; }

s32 fn_80014AE4(void) {
 s32 var_r6=0,var_r7=0,var_r8=1,var_r9=1;
 void *temp_r11;
 if (*(s32 *)((u8 *)lbl_8055D350+4)==1 && *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x30)+0x10)>0) var_r6=1;
 temp_r11=*(void **)((u8 *)lbl_8055D350+0x30);
 if (!(*(f32 *)((u8 *)temp_r11+0x1C)>lbl_80560368) &&
     *(s32 *)((u8 *)temp_r11+0x10)!=*(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0xC)+8)) var_r9=0;
 if (var_r9==0 && var_r6==0) var_r8=0;
 if (var_r8!=0 && *(f32 *)((u8 *)temp_r11+0x14)<lbl_805603B4) var_r7=1;
 if (var_r7!=0) return 1;
 if (*(s32 *)((u8 *)temp_r11+0x10)<=*(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0xC)+8)) return 0;
 return 1;
}

s32 fn_800151D4(void) { return 1; }

s32 fn_800151DC(void *arg0) {
    s32 result;
    void *manager = lbl_8055D350;
    void *obj;
    if ((*(u32 *)((u8 *)manager + 0x20) & 0x400) &&
        (*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x2C) + 0x2C0) & 0x10)) {
        obj = *(void **)((u8 *)arg0 + 0x50);
        (*(void (**)(void *, void *))((u8 *)*(void ***)obj + 0xC))(obj, lbl_80558BBC);
        fn_801476C4();
    }
    manager = lbl_8055D350;
    result = 0;
    if ((*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x30)) & 4) && (*(u32 *)((u8 *)manager + 0x20) & 0x200)) result = 1;
    if (result) {
        obj = *(void **)((u8 *)arg0 + 0x50);
        (*(void (**)(void *, void *))((u8 *)*(void ***)obj + 0xC))(obj, lbl_802FCDB4);
        fn_801476C4();
    }
    return result;
}

extern f32 fn_80235EF0(void *, s32);
extern f32 fn_80235F64(void *, s32);
extern void fn_80010E94(void *, s32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_8001529C(void *arg0, u32 arg1, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 width, height, half, left, y, bottom, x;
    s32 negative;
    s32 positive = (arg1 >> 31) ^ 1;
    width = fn_80235EF0(*(void **)((u8 *)arg0 + 0x38), 0);
    height = fn_80235F64(*(void **)((u8 *)arg0 + 0x38), 0);
    negative = positive == 0;
    half = width * lbl_805603BC;
    left = b - half;
    bottom = c - e;
    x = left + a * (((b + d) - half) - left);
    y = c + height;
    fn_80010E94(*(void **)((u8 *)arg0 + 0x38), negative,
        x, positive ? y : bottom, lbl_80560360, lbl_80560360);
}

extern s32 fn_801EA994(void);
extern s32 fn_801EA9B0(s32);
extern void fn_8000FF88(s32, s32, void *, s32, s32, f32, f32, f32);
extern f32 lbl_80560368, lbl_80560384, lbl_805603CC, lbl_805603D0;
extern u8 lbl_80558BC4[];
void fn_800154B8(void) {
    s32 current;
    s32 *base;
    s32 first, left, right, start, i;
    f32 y, step;
    current = fn_801EA994();
    base = *(s32 **)((char *)lbl_8055D350 + 0x30);
    first = base[1];
    left = 2; right = 2;
    if (first <= 2) { left = first - 1; right = (2 - left) + 2; }
    else if (first > current - 2) { left = first - (current - 2) + 2; right = current - first; }
    y = lbl_805603CC;
    start = first - (left & ~(left >> 31));
    i = 1;
    if (start >= 1) i = start;
    step = lbl_80560384;
    for (; i < base[1]; ++i) {
        fn_8000FF88(-1, 9, lbl_80558BC4, i, fn_801EA9B0(i - 1) + 0x48, lbl_80560368, lbl_805603D0, y);
        y -= step;
    }
    fn_8000FF88(-0x100, 9, lbl_80558BC4, *(s32 *)((char *)lbl_8055D350 + 0x28) + 0x48, 0, lbl_80560368, lbl_805603D0, y);
    step = lbl_80560384; y -= step;
    i = base[1] + 1;
    for (; i <= base[1] + (right & ~(right >> 31)) && i <= fn_801EA994(); ++i) {
        fn_8000FF88(-1, 9, lbl_80558BC4, i, fn_801EA9B0(i - 1) + 0x48, lbl_80560368, lbl_805603D0, y);
        y -= step;
    }
}

#pragma pop
extern void fn_801476C4(void);
extern u8 lbl_80558BBC[];
extern u8 lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
void fn_80015AA0(void *arg0, f32 angle) {
    f32 c = (f32)cos();
    f32 s = (f32)sin(angle);
    f32 *m = (f32 *)arg0;
    m[0]=c; m[1]=s; m[2]=lbl_80560360; m[3]=-s;
    m[4]=c; m[5]=lbl_80560360; m[6]=lbl_80560360; m[7]=lbl_80560360;
    m[8]=lbl_80560368;
}

void fn_80015E30(void *arg0, f32 angle) {
    f32 temp_f31 = (f32)cos();
    f32 temp_f3 = (f32)sin(angle);
    *(f32 *)((u8 *)arg0 + 4) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 0) = lbl_80560368;
    *(f32 *)((u8 *)arg0 + 8) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 0xC) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 0x10) = temp_f31;
    *(f32 *)((u8 *)arg0 + 0x14) = temp_f3;
    *(f32 *)((u8 *)arg0 + 0x18) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 0x1C) = -temp_f3;
    *(f32 *)((u8 *)arg0 + 0x20) = temp_f31;
}

void fn_80015EB0(void *arg0, f32 angle) {
    f32 temp_f31;
    f32 temp_f3;
    temp_f31 = (f32)cos();
    temp_f3 = (f32)sin(angle);
    *(f32 *)((u8 *)arg0 + 0) = temp_f31;
    *(f32 *)((u8 *)arg0 + 4) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 8) = -temp_f3;
    *(f32 *)((u8 *)arg0 + 0xC) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 0x10) = lbl_80560368;
    *(f32 *)((u8 *)arg0 + 0x14) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 0x18) = temp_f3;
    *(f32 *)((u8 *)arg0 + 0x1C) = lbl_80560360;
    *(f32 *)((u8 *)arg0 + 0x20) = temp_f31;
}

extern f32 lbl_805603F8,lbl_805603FC,lbl_80560408,lbl_8056040C,lbl_80560410,lbl_80560414;
extern void fn_801478E0(void*,void*,s32,s32);
extern void fn_80147F30(s32,s32,s32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void fn_80148134(f32*,f32*,s32,f32,f32);
extern void fn_80015770(void*,f32,f32,f32,f32,f32);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_80015F30(void* arg0) {
 struct Desc { s32 a; f32 x,y; s32 d; f32 w,h; s32 g,k; };
 class Obj { public:
 virtual void v0(); virtual Desc* get(void*); virtual void v2(); virtual Desc* find(void*);
 };
 struct Desc copy;
 f32 x,y;
 f32 value;
 f32 low;
 f32 high;
 f64 period=lbl_80560400;
 u8* base=lbl_802FCB98;
 low=lbl_805603F8;
 high=lbl_805603FC;
 value=*(f32*)((u8*)*(void**)((u8*)lbl_8055D350+0x2c)+0x2a8);
 s32 positive=(f32)((f64(*)(void*,f32,f64))fn_8002EFB4)(*(void**)((u8*)lbl_8055D350+0x2c),*(f32*)((u8*)lbl_8055D350+0x10),period)>lbl_805603BC;
 s32 flag=0;
 void* obj;
 struct Desc* desc;
 if(value>lbl_80560408 && positive) flag=1;
 fn_801478E0(*(void**)((u8*)arg0+0x50),base+0x228,*(s32*)((u8*)arg0+0x40),3);
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->find(base+0x234);
 if(desc) {
  if(flag || *(f32*)((u8*)*(void**)((u8*)lbl_8055D350+0x2c)+0x2c4)>lbl_80560360) {
   f32 a=lbl_8056040C*value;
   f32 b;
   if(a<lbl_80560360) b=a-lbl_805603BC; else b=lbl_805603BC+a;
   f32 scale=(high-low)/lbl_8056040C;
   ((void(*)(f32,f32,f32,f32,s32,s32,s32,f32,f32,f32,f32,f32,f32))fn_80147F30)(desc->x,desc->y,desc->w,desc->h,desc->g,(s32)b,*(s32*)((u8*)arg0+0x44),low,scale,lbl_805603BC,lbl_80560360,lbl_80560410,lbl_80560414);
  } else {
   f32 a=lbl_8056040C*value;
   f32 b;
   if(a<lbl_80560360) b=a-lbl_805603BC; else b=lbl_805603BC+a;
   f32 scale=(high-low)/lbl_8056040C;
   ((void(*)(f32,f32,f32,f32,s32,s32,s32,f32,f32,f32,f32,f32,f32))fn_80147F30)(desc->x,desc->y,desc->w,desc->h,desc->g,(s32)b,*(s32*)((u8*)arg0+0x44),low,scale,lbl_80560360,lbl_80560360,lbl_80560414,lbl_80560414);
  }
 }
 fn_801478E0(*(void**)((u8*)arg0+0x50),base+0x240,*(s32*)((u8*)arg0+0x40),0);
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->find(base+0x24c);
 if(desc) {
  high=low+value*(high-low);
  fn_80148134(&x,&y,desc->d,desc->x,desc->y);
  fn_80015770(arg0,x,y,desc->w,desc->h,high);
 }
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->get(base+0x258);
 if(desc) {
 copy=*desc;
 if(flag) copy.g=0x80FFFF00;
 ((void(*)(void*))fn_801476C4)(&copy);
 }
}
#pragma cplusplus reset
#pragma pop

s32 fn_80016214(void) {
    f64 scale = lbl_80560400;
    f32 value = (f32)fn_8002EFB4(lbl_8055D350,
                    *(f32 *)((u8 *)lbl_8055D350 + 0x10), scale);
    if (!(value < lbl_805603BC)) {
        if (lbl_8055E520) {
            fn_80011E04(0);
            fn_80010FDC(lbl_802FCE04, 0xC);
            return 1;
        }
    }
    return 0;
}

s32 fn_80016288(void) { return 0; }

extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[];
extern u8 lbl_802FCE88[];
void *__AXFXGetLfoSinTable(void) {
    return lbl_802FCE88;
}
extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[], lbl_802FCE88[];
