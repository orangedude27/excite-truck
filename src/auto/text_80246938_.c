typedef signed long s32;
extern s32 lbl_8055F26C;
s32 fn_802411D4(void);
s32 fn_80214B44(s32);
s32 fn_80214B94(s32);
typedef s32 (*UnkFunc)(s32);
extern float lbl_80563898;
extern float lbl_805638A8;
extern double lbl_805638A0;
void fn_80246CAC(float);
void fn_80127464(void);
void fn_802E2D74(s32);
void fn_8020A5F8(float);
void fn_8020A634(void);
s32 fn_802E2C20(void);
void fn_80214AF0(s32);
void fn_80214A9C(s32);
extern char lbl_80343600[16];
typedef struct Obj_802470D4 {
    void *vtable;
    char pad[0x14];
    s32 field18;
    s32 field1C;
    s32 field20;
    char pad24[0xC];
    s32 *field30;
} Obj_802470D4;
void fn_80235380(s32);
void fn_802C519C(s32);
void fn_802328D4(s32);
void fn_80128668(void *);
s32 fn_802E499C(unsigned short *, unsigned short, unsigned short, unsigned short, unsigned short);
void fn_8020C918(s32);
extern unsigned short lbl_802FA48C[6];
extern float lbl_805638B0;
s32 fn_80221EA8(void);
extern s32 lbl_8055BEF0;
extern void *lbl_8055F278;

typedef struct lbl_8055F278_struct {
    char pad00[0x04];
    s32 unk04;
    s32 unk08;
    char pad0C[0x38];
    unsigned char unk44;
    char pad45[0x03];
    s32 unk48;
    s32 unk4C;
    unsigned char unk50;
    char pad51[0x03];
    s32 unk54;
    s32 unk58;
    unsigned char unk5C;
} lbl_8055F278_struct;
extern float lbl_805638B0;
#pragma push
#pragma small_data off
extern float lbl_805638C8;
#pragma pop
float fn_80214D48(void);
unsigned char fn_802E8690(s32);
void fn_80221F94(void *, s32);
#pragma push
#pragma small_data off
extern float lbl_805638CC;
#pragma pop
extern float lbl_80558DC4[];


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F260;
extern unsigned char lbl_803432EC[];
extern void fn_80246CB8(void *);
extern char lbl_80343780[];
extern float lbl_8055F264;
int fn_80246AA8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

void *__dt__Q28PSSystem7SeqHeapFv_80246C48(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80343780;
        ((void (*)(s32, void *))fn_80235380)(*(s32 *)((char *)arg0 + 0x18), lbl_80343780);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
void fn_80246CAC(float farg0) {
}
#pragma dont_inline reset

extern char lbl_803436C0[];
extern s32 lbl_804988F0[5];
extern void fn_80216CA8(void);
extern void fn_802146BC(void *, s32, s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 3
void fn_80246CB8(void *arg0) {
    s32 text[12];
    s32 item[10];
    s32 menu[6];
    s32 *p = text;
    p[5] = 0;
    p[0] = (s32)lbl_803436C0;
    p[8] = 2500;
    p[9] = 1;
    p[10] = 0;
    p[7] = fn_802E2C20();
    p[6] = 1;
    item[1] = 5;
    item[0] = 0;
    item[2] = (s32)p;
    item[3] = 0;
    item[4] = 0;
    item[5] = lbl_804988F0[0];
    item[6] = lbl_804988F0[1];
    item[7] = lbl_804988F0[2];
    item[8] = lbl_804988F0[3];
    item[9] = lbl_804988F0[4];
    menu[2] = 0;
    menu[3] = 0;
    menu[4] = 0;
    menu[0] = (s32)arg0;
    menu[1] = (s32)item;
    fn_80216CA8();
    fn_802146BC(menu, -999, -999, 1);
}
#pragma pop

int fn_80246DA8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

void fn_80246DE8(void) {
    fn_80246CB8(lbl_803432EC);
}

extern unsigned char lbl_803432FC[];
void fn_80246DF4(void) {
    fn_80246CB8(lbl_803432FC);
}

extern unsigned char lbl_8034330C[];
void fn_80246E00(void) {
    fn_80246CB8(lbl_8034330C);
}

int fn_80246E0C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

Obj_802470D4 *fn_802470D4(Obj_802470D4 *arg0, s32 arg1) {
    s32 *p;
    if (arg0 != 0) {
        arg0->vtable = &lbl_80343600;
        fn_80235380(arg0->field18);
        fn_80235380(arg0->field1C);
        fn_802C519C(arg0->field20);
        p = arg0->field30;
        if (p != 0) {
            fn_802328D4(*p);
            *p = 0;
            fn_80128668(((*p = 0), p));
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_80247174(void) {
    s32 i = 0;
    do {
        fn_80246CAC(lbl_80563898 - ((float)i / lbl_805638A8));
        fn_80127464();
        fn_802E2D74(0x10);
        i++;
    } while (i < 0x32);
    fn_8020A634();
    fn_80246CAC(lbl_80563898);
}

s32 fn_8024739C(void) { return 0; }

extern char lbl_8055F260, lbl_8055F269, lbl_8055F26A;
extern unsigned int lbl_8055D430, lbl_8055E044;
extern char lbl_80343270[], lbl_80498980[], lbl_8049898C[];
extern void fn_8020A600(void), fn_802ECEC4(void), fn_80019708(void);
extern void fn_80129AEC(int), fn_8024CF60(void), fn_8024CFB4(void);
extern void fn_8027DDCC(int), fn_80260954(int), fn_8023BEA8(void);
extern void fn_801312EC(void *, const char *), fn_80131318(void *);
extern void fn_80214FD8(void *, void *), fn_80239F74(void), fn_8000DA10(void);
extern int fn_8000DBAC(void);
extern void fn_802E6FBC(void), fn_8000DC70(int), fn_800169F8(int), fn_80137C78(int);
extern void fn_802E4A10(void), fn_80137C84(int), fn_8023BCEC(void);
extern void fn_8025812C(void), fn_8025C054(void), fn_800196FC(void), fn_80161DE4(void);
extern void fn_8027DE6C(void), fn_80263F30(int,int,int);
extern void fn_802E317C(const char *, ...);
void fn_802473A4(void) {
    int again = 1;
    int prior;
    fn_8020A600(); fn_802ECEC4();
    while (fn_80246AE8() != 0 && fn_8024CF54() == 0) {}
    fn_80019708();
    for (;;) {
        int code, old;
        fn_80129AEC(0);
        code = fn_80247C18();
        if ((unsigned int)(code + 1) > 0x12) fn_802E317C("%s", lbl_80343270 + 0x168);
        else switch (code) {
        case -1: fn_8024CF60(); break;
        case 0: fn_8024CFB4(); break;
        case 1: fn_8027DDCC(0); break;
        case 2: fn_8027DDCC(1); break;
        case 3: fn_8027DDCC(2); break;
        case 4: fn_80260954(0); break;
        case 5: fn_80260954(1); break;
        case 6:
            old=lbl_8055D430; lbl_8055D430|=1; fn_8023BEA8();
            if (fn_802411D4()==0) {
                if (!lbl_8055F269) { fn_801312EC(lbl_80498980,lbl_80343270+0x114); lbl_8055F269=1; }
                if (!lbl_8055F26A) { fn_801312EC(lbl_8049898C,lbl_80343270+0x13c); lbl_8055F26A=1; }
                if (*(unsigned int *)(lbl_80498980+8)!=lbl_8055E044) fn_80131318(lbl_80498980);
                if (*(unsigned int *)(lbl_8049898C+8)!=lbl_8055E044) fn_80131318(lbl_8049898C);
                fn_80214FD8(*(void **)(lbl_80498980+4),*(void **)(lbl_8049898C+4));
            }
            lbl_8055D430=(lbl_8055D430&~1)|(old&1); break;
        case 7: fn_80239F74(); fn_8000DA10(); if(fn_8000DBAC()){fn_802E6FBC();again=0;} break;
        case 8: fn_802E6FBC(); break;
        case 9:
            old=lbl_8055D430; lbl_8055D430|=1;
            fn_8000DC70(0); fn_800169F8(0); fn_80137C78(1); fn_8000DA10();
            prior=0; fn_802E4A10(); fn_80137C84(prior); fn_802E4A10();
            fn_80129AEC(0); fn_8023BCEC(); lbl_8055D430=(lbl_8055D430&~1)|(old&1); break;
        case 10: fn_8025812C(); break;
        case 11: fn_8025C054(); break;
        case 12: fn_800196FC(); break;
        case 13: fn_80161DE4(); fn_8027DE6C(); break;
        case 14: fn_80263F30(1,1,1); break;
        case 15: again=0; break;
        }
        if (!again && (fn_8024CF54()==0 && fn_80246AE8()!=0)) break;
    }
    lbl_8055F260=0;
}

char fn_80247624(void) {
    return lbl_8055F260;
}

s32 fn_8024762C(void) {
    if (fn_802E2C20() % 1500 > 500) fn_80214AF0(1);
    else fn_80214A9C(1);
    return 0;
}

s32 fn_802476FC(void) {
    UnkFunc fn;
    if (fn_802411D4() != 0 && lbl_8055F26C > 0) fn = fn_80214B94;
    else fn = fn_80214B44;
    return (fn(4), 0);
}

extern s32 lbl_8055BEA8;
extern s32 lbl_8055BEBC;
extern void* lbl_8055BEAC;
s32 fn_80214D04(void);
void fn_80247768(void) {
    lbl_8055BEAC = (void*)fn_80214D04();
}

extern void *lbl_8055BEB0;
extern s32 lbl_8055BEB8;
extern s32 lbl_8055F26C;
void fn_8024778C(void) {
    s32 var_r31;
    register s32 previous = lbl_8055BEB8;
    if (previous != lbl_8055F26C) {
        lbl_8055BEB8 = lbl_8055F26C;
        switch ((s32)lbl_8055F26C) {
        case 2: lbl_8055BEB0 = (void*)1; break;
        case 3: lbl_8055BEB0 = (void*)2; break;
        default: lbl_8055BEB0 = 0; break;
        }
    }
    fn_80214CB4((s32)lbl_8055BEB0);
    switch ((s32)lbl_8055F26C) {
    case 1: fn_80214B44(2); fn_80214A9C(3); break;
    case 2:
        if (fn_8027B8C0(1) != 0) fn_80214B44(3);
        else fn_80214A9C(3);
        break;
    }
    var_r31 = 0;
    do {
        if (fn_8027B94C(var_r31) == 0) fn_80214A9C(var_r31 + 0xB);
        var_r31 += 1;
    } while (var_r31 < 3);
}

extern void* lbl_8055BEB0;
extern s32 lbl_8055BEB4;
void fn_80247880(void) {
    lbl_8055BEB0 = (void*)fn_80214D04();
}

void fn_80247A0C(void) {
    s32 var_r31;
    s32 val;
    int flag;

    if (lbl_8055BEBC != lbl_8055BEA8) {
        val = lbl_8055BEA8;
        flag = val == 5;
        lbl_8055BEBC = val;
        lbl_8055BEB4 = flag;
    }
    fn_80214CB4(lbl_8055BEB4);
    if (lbl_8055BEBC == 4) {
        fn_80214B44(2);
    }
    var_r31 = 0;
    do {
        if (fn_8027B9EC(var_r31) == 0) {
            fn_80214A9C(var_r31 + 0xB);
        }
        var_r31 += 1;
    } while (var_r31 < 2);
}

void fn_80247AAC(void) {
    lbl_8055BEB4 = (s32) (void*)fn_80214D04();
}

void *fn_80248140(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((unsigned int)arg0 + 0x18 != 0) {
            if ((unsigned int)arg0 + 0x18 != 0) {
                *(int *)((char *)arg0 + 0x18) = 0;
                *(int *)((char *)arg0 + 0x1C) = 0;
                *(int *)((char *)arg0 + 0x20) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_80248398(void) {
    s32 c;
    s32 a;
    s32 b;
    lbl_8055F278_struct *p;

    p = (lbl_8055F278_struct *)lbl_8055F278;
    if (p != 0) {
        a = p->unk04;
        b = p->unk08;
        c = lbl_8055BEF0 + a;
        p->unk50 = 1;
        p->unk48 = c;
        p->unk4C = b;
        p = (lbl_8055F278_struct *)lbl_8055F278;
        p->unk5C = 1;
        p->unk54 = a;
        p->unk58 = b;
        p->unk44 = 0;
    }
}

void* fn_8024859C(void *arg0, s32 arg1) {
    volatile s32 test;
    test = arg1;
    if (arg0 != 0) {
        *(volatile unsigned char*)((char*)arg0 + 0x18) = 0;
        *(unsigned char*)((char*)arg0 + 0x50) = 0;
        *(unsigned char*)((char*)arg0 + 0x5C) = 0;
        *(s32*)((char*)arg0 + 0x24) = 1;
        *(s32*)((char*)arg0 + 0x20) = 0;
        *(unsigned char*)((char*)arg0 + 0x44) = 0;
        if (test > 0) fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_802485FC(void) {
    unsigned short args[5];
    unsigned short *p = lbl_802FA48C;

    args[0] = *p++;
    args[1] = *p++;
    args[2] = *p++;
    args[3] = *p++;
    args[4] = *p++;
    if (fn_802E499C(args, args[3], args[2], args[1], args[0]) != 0) {
        fn_80246CAC(lbl_805638B0);
        fn_8020C918(1);
    }
    return 0;
}

void fn_80248770(void *arg0) {
    *(unsigned char*)((char*)arg0 + 0x18) = 1;
    *(s32*)((char*)arg0 + 0x1C) = fn_80221EA8();
}

void fn_802487A8(void *arg0) {
    *(unsigned char*)((char*)arg0 + 0x18) = 0;
}

#pragma push
#pragma optimization_level 3
void fn_802487B4(void *arg0) {
 extern void fn_80214BE4(s32,s32,s32);
 extern float lbl_805638B8,lbl_805638BC,lbl_805638C0,lbl_805638C4;
 float t, x1,x0,y1,y0, factor;
 s32 y,x;
 if (*(s32 *)((char *)arg0+0x20)!=*(s32 *)((char *)arg0+0x24)) {
 if (*(s32 *)((char *)arg0+0x20)==0) fn_80214AF0(*(s32 *)((char *)arg0+0x1C)); else fn_80214A9C(*(s32 *)((char *)arg0+0x1C));
 *(s32 *)((char *)arg0+0x24)=*(s32 *)((char *)arg0+0x20);
 }
 if (*(unsigned char *)((char *)arg0+0x50)) {
 x=*(s32 *)((char *)arg0+0x48); y=*(s32 *)((char *)arg0+0x4C);
 *(s32 *)((char *)arg0+0x30)=x; *(s32 *)((char *)arg0+0x28)=x; *(s32 *)((char *)arg0+0x34)=y; *(s32 *)((char *)arg0+0x2C)=y;
 fn_80214BE4(*(s32 *)((char *)arg0+0x1C),x-*(s32 *)((char *)arg0+0x4),y-*(s32 *)((char *)arg0+0x8));
 t=lbl_805638BC; *(unsigned char *)((char *)arg0+0x50)=0; *(float *)((char *)arg0+0x3C)=t;
 }
 if (*(unsigned char *)((char *)arg0+0x5C)) {
 t=lbl_805638B0;
 *(s32 *)((char *)arg0+0x28)=*(s32 *)((char *)arg0+0x4); *(s32 *)((char *)arg0+0x2C)=*(s32 *)((char *)arg0+0x8); *(s32 *)((char *)arg0+0x30)=*(s32 *)((char *)arg0+0x54); *(s32 *)((char *)arg0+0x34)=*(s32 *)((char *)arg0+0x58);
 *(float *)((char *)arg0+0x3C)=t; *(unsigned char *)((char *)arg0+0x5C)=0;
 }
 t=*(float *)((char *)arg0+0x3C)+*(float *)((char *)arg0+0x38)*fn_80214D48();
 *(float *)((char *)arg0+0x3C)=t;
 switch (*(s32 *)((char *)arg0+0x40)) {
 case 1:
 t=t<lbl_80563898?t:lbl_80563898;
 factor=t*t; break;
 case 2:
 t=t<lbl_80563898?t:lbl_80563898;
 factor=t<lbl_805638C0?lbl_805638C0:
 t>lbl_80563898?lbl_80563898:
 t>lbl_805638B0?t*((lbl_805638C4*t)*t)+((lbl_805638B8*t)*t):
 t*((lbl_805638C4*t)*t)-((lbl_805638B8*t)*t);
 break;
 default: factor=*(float *)((char *)arg0+0x3C); factor=factor<lbl_80563898?factor:lbl_80563898;
 }
 x1=(float)*(s32 *)((char *)arg0+0x30); x0=(float)*(s32 *)((char *)arg0+0x28); y1=(float)*(s32 *)((char *)arg0+0x34); y0=(float)*(s32 *)((char *)arg0+0x2C);
 x=(s32)(x0+factor*(x1-x0)); y=(s32)(y0+factor*(y1-y0));
 fn_80214BE4(*(s32 *)((char *)arg0+0x1C),x-*(s32 *)((char *)arg0+0x4),y-*(s32 *)((char *)arg0+0x8));
 if (*(unsigned char *)((char *)arg0+0x44)) {
 s32 done=(*(float *)((char *)arg0+0x3C)>=lbl_80563898);
 if (done) { *(unsigned char *)((char *)arg0+0x44)=0; *(s32 *)((char *)arg0+0x20)=1; }
 }
}
#pragma pop
void fn_80248A68(void *arg0) {
    *(float*)((char*)arg0 + 0x1C) = lbl_805638B0;
}

void fn_80248A74(void *arg0) {
    float *fp = (float *)((char *)arg0 + 0x1C);
    float value = *fp;
    float limit = lbl_805638C8;
    s32 rate;
    float delta;
    if (value > limit) rate = 0xC8;
    else rate = 0x32;
    delta = fn_80214D48();
    *fp = value + (float)rate * delta;
}

#pragma push
#pragma processor 750
void fn_80230C30(float *, float *, s32, s32);
float fn_80235F64(s32, s32);
void fn_802353F4(s32, s32, float, float, float);
#pragma push
#pragma processor 750
void fn_80248AF0(void *arg0) {
    float spC, sp8;
    float width, height;
    s32 flag;
    fn_80230C30(&spC, &sp8, *(s32*)((char*)arg0+4), *(s32*)((char*)arg0+8));
    width = (float)*(s32*)((char*)arg0+0xC);
    height = (float)*(s32*)((char*)arg0+0x10);
    if (*(float*)((char*)arg0+0x1C) > width)
        *(float*)((char*)arg0+0x1C) -= width;
    flag = *(float*)((char*)arg0+0x1C) > lbl_805638C8;
    fn_802353F4(*(s32*)((char*)arg0+0x18), flag, spC + *(float*)((char*)arg0+0x1C), (sp8-height)+fn_80235F64(*(s32*)((char*)arg0+0x18), flag), lbl_805638B0);
}
#pragma pop

void fn_80248BD0(void *arg0) {
    *(float *)((char *)arg0 + 0x20) = lbl_805638CC;
    *(unsigned char *)((char *)arg0 + 0x1C) = fn_802E8690(*(s32 *)((char *)arg0 + 0x18));
}

void fn_80248C0C(void *arg0) {
    unsigned char res;
    float *fp = (float *)((char *)arg0 + 0x20);

    res = fn_802E8690(*(s32 *)((char *)arg0 + 0x18));
    *(unsigned char *)((char *)arg0 + 0x1C) = res;
    if (res != 0) {
        *fp = lbl_805638CC;
        fn_80214A9C(0x1E);
    } else {
        *fp -= fn_80214D48();
        fn_80214AF0(0x1E);
    }
    if (*fp < lbl_80558DC4[0]) {
        fn_80221F94(arg0, 0);
    }
}

int fn_80248C94(void *arg0, int arg1) {
    if (*(unsigned char *)((char *)arg0 + 0x1C) == 0 && arg1 == 13) {
        fn_80221F94(arg0, 0);
        return 1;
    } else {
        return 0;
    }
}

#pragma scheduling off
s32 fn_80248FB0(void *arg0, s32 arg1) {
    s32 now, start, duration;
    now = fn_802E2C20();
    start = *(s32 *)((char *)arg0 + 0x1C);
    if (now < start + 750) return 0;
    duration = *(s32 *)((char *)arg0 + 0x20);
    if (duration != 0 && now - start > duration - 500) return 0;
    if (*(s32 *)((char *)arg0 + 0x18) != 1) return 0;
    switch (arg1) {
    case 27:
        if (*(s32 *)((char *)arg0 + 0x24) & 2) *(s32 *)((char *)arg0 + 0x18) = 4;
        else return 0;
        break;
    case 13:
        if (*(s32 *)((char *)arg0 + 0x24) & 1) *(s32 *)((char *)arg0 + 0x18) = 2;
        else return 0;
        break;
    default: return 0;
    }
    *(s32 *)((char *)arg0 + 0x1C) = now - *(s32 *)((char *)arg0 + 0x20) + 500;
    return 1;
}
#pragma scheduling on
void fn_802490AC(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;

    *(p + 0x1C) = 0;
    *(s32 *)((char *)arg0 + 0x18) = fn_802E2C20();
    if (fn_802C9A58() != 0) {
        fn_80214A9C(1);
    } else {
        fn_80214A9C(2);
    }
}

void fn_80249104(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;

    if (*(p + 0x1C) == 0 && fn_802E2C20() - *(s32 *)((char *)arg0 + 0x18) >= 0x3A98) {
        fn_802168BC(-2);
    }
}

s32 fn_80249154(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;

    if (*(p + 0x1C) == 0 && fn_802E2C20() - *(s32 *)((char *)arg0 + 0x18) >= 0x5DC) {
        fn_802168BC(-2);
    }
    return 1;
}

s32 fn_80249334(void *arg0, s32 arg1) {
    s32 *val = (s32 *)((char *)arg0 + 0x28);

    switch (arg1) {
    case 0x126:
        break;
    case 0x125:
        if (*val > 0) {
            fn_80214D50(0);
            *val = *val - 1;
        } else {
            fn_80214D50(1);
        }
        break;
    case 0x127:
        if (*val + 1 < *(s32 *)((char *)arg0 + 0x24)) {
            fn_80214D50(0);
            *val = *val + 1;
        } else {
            fn_80214D50(1);
        }
        break;
    }
    return 0;
}

#pragma push
#pragma optimization_level 3
void fn_802493E8(void *arg0) {
    s32 var_r31 = 0;
    s32 var_r30 = 0;
    register s32 var_r29 = (s32)arg0;
    while (var_r30 < *(s32 *)((char *)var_r29 + 0x1C)) {
        s32 *entry = (s32 *)(*(s32 *)((char *)var_r29 + 0x18) + var_r31);
        if (*(unsigned char *)((char *)entry + 4) != 0)
            fn_80214AF0(*entry);
        else
            fn_80214A9C(*entry);
        var_r31 += 8;
        var_r30 += 1;
    }
}
#pragma pop
