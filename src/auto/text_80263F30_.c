// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).



extern int fn_8023695C(void *);
extern void fn_80216CA8(void);
extern void fn_802168BC(int);
extern int fn_80265B5C(void);
extern void fn_80216D28(void);
extern void *lbl_8055F444;
extern void *lbl_8055F448;
extern void fn_80235380(void *);
extern void fn_80128670(void *);
extern void *lbl_8055C458;
extern void fn_80236914(void);
extern void fn_80264098(void *, int);
extern void *fn_80264A54(void);
extern void *fn_80264580(void);

extern char lbl_80346338[];
extern int lbl_8055C450;
extern unsigned char lbl_8055F450;

extern int fn_8020A69C(void);
extern void fn_8020A648(int);
extern void fn_80265A74(void);
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern int fn_802ECF00(int);
extern int fn_802ECF04(void);
extern void fn_802E317C(const char *, ...);
extern void fn_80265940(void);
extern void fn_802646D0(void *);
extern void fn_8026451C(void *);
extern int stricmp(const char *, const char *);
extern int fn_802656C8(void *);
extern int fn_80264538(int, int);
extern void *fn_80264968(void *, int);

#pragma use_lmw_stmw off
#pragma dont_inline off
void fn_80263F30(int arg0, unsigned char arg1, int arg2) {
    char sp8[0x28];
    char sp30[0xE0];
    register const char *base asm("r31") = lbl_80346338;
    register int prev_state asm("r30");
    register void *list asm("r29");
    register void *item asm("r28");
    register int cont asm("r27");
    register int r_arg0 asm("r26") = arg0;
    register int r_arg2 asm("r25") = arg2;

    lbl_8055F450 = arg1;
    prev_state = fn_8020A69C();
    fn_8020A648(1);
    if (r_arg0 != 0) {
        fn_80265A74();
    }
    list = fn_80131810((void *)(base + 0x68));
    if (list != 0) {
        if (fn_802ECF00(lbl_8055C450) == 0) {
            fn_802E317C(base + 0x74, lbl_8055C450);
        }
        fn_80265940();
        fn_802646D0(sp30);
        fn_8026451C(sp8);
        cont = 1;
        r_arg0 = 0;
        while (cont != 0 && (item = ((void *(*)(void *, int))(*(void ***)list)[3])(list, r_arg0)) != 0) {
            if (stricmp(((char *(*)(void *))(*(void ***)item)[2])(item), base + 0xAC) == 0) {
                cont = fn_802656C8(item);
            }
            r_arg0++;
        }
        fn_8020A648(-1);
        fn_80265A74();
        if (fn_802ECF04() == 0) {
            fn_802E317C(base + 0xC0);
        }
        fn_80131818(list);
        fn_80264538((int)sp8, -1);
        fn_80264968(sp30, -1);
    }
    if (r_arg2 != 0) {
        fn_80265940();
    }
    fn_8020A648(prev_state);
}
#pragma use_lmw_stmw on
#pragma dont_inline on

void fn_80264098(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 4) = arg1;
}
#pragma dont_inline off

#pragma dont_inline on
#pragma dont_inline off
void fn_802640A0(void *arg0) {
    *(int *)((char *)arg0 + 8) = 0;
    *(void **)arg0 = lbl_8055C458;
    *(int *)((char *)arg0 + 4) = 0x7b;
    *(int *)((char *)arg0 + 0xc) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
}
#pragma scheduling invalid_target
void fn_802643B8(void *arg0) {
    *(void **)arg0 = &lbl_8055C458;
    fn_80264098(arg0, 8);
    *(void (**)(void))((char *)arg0 + 8) = fn_80236914;
    *(int *)((char *)arg0 + 0xc) = 2;
}
#pragma scheduling on
void fn_80264404(void *arg0) {
    *(void **)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = fn_80264A54();
}

void fn_80264444(void *arg0) {
    *(void **)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = fn_80264580();
}

void fn_80264484(void *arg0) {
    extern void *fn_801284F8(unsigned int, void *);
    extern char lbl_803464A8[];
    extern char lbl_803464F8[];
    extern unsigned char lbl_80498F78[];
    void *result;
    void **items;
    int count;

    result = fn_801284F8(0x18, lbl_803464A8);
    if (result != 0) {
        *(int *)((char *)result + 0x14) = 0;
        *(void **)result = lbl_803464F8;
    }
    count = *(int *)(lbl_80498F78 + 4);
    items = *(void ***)(lbl_80498F78 + 0);
    *(int *)(lbl_80498F78 + 4) = count + 1;
    items[count] = result;
    *(int *)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = result;
}

#pragma scheduling invalid_target
void fn_8026451C(void *arg0) {
    extern char lbl_803466D8[];
    *(void **)arg0 = lbl_803466D8;
    *(int *)((char *)arg0 + 0x14) = 0;
    lbl_8055F444 = arg0;
}
#pragma scheduling on
int fn_80264538(int arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F444 = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void* fn_80264580(void) {
    return lbl_8055F444;
}

float fn_80264588(void) {
    extern int fn_802645C0(void);
    extern float lbl_80563BF4;
    if (fn_802645C0() != 0) {
        return *(float *)((char *)lbl_8055F444 + 0x20);
    }
    return lbl_80563BF4;
}

int fn_802645C0(void) {
    extern float lbl_80558DC4[];
    float v = *(float *)((char *)lbl_8055F444 + 0x18);
    double abs = __fabs((double)v);
    return (float)abs <= lbl_80558DC4[0];
}

void fn_802645EC(void) {
    extern float lbl_8055C454;
    *(float *)((char *)lbl_8055F444 + 0x1C) = lbl_8055C454;
}

#pragma scheduling invalid_target
void fn_802645FC(void *arg0) {
    extern float lbl_80563BF8;
    extern float lbl_8055C454;
    extern float lbl_80563BF0;
    float b = lbl_80563BF0;
    float a = lbl_80563BF8;
    *(float *)((char *)arg0 + 0x18) = a;
    *(float *)((char *)arg0 + 0x1C) = lbl_8055C454;
    *(float *)((char *)arg0 + 0x20) = b;
}
#pragma dont_inline on
void fn_80264618(void *arg0) {
    extern float lbl_80558DC4[];
    extern float lbl_80563BF0;
    extern float fn_80214D48(void);
    extern int fn_802645C0(void);
    extern void fn_80221F94(void *, int);
    extern void fn_80216CA8(void);
    float a;
    float b;
    float c;
    float limit;

    a = (float)__fabs((double)*(float *)((char *)arg0 + 0x1C));
    if (a <= lbl_80558DC4[0]) {
        fn_80221F94(arg0, 0);
        fn_80216CA8();
    }
    a = fn_80214D48();
    b = *(float *)((char *)arg0 + 0x18);
    limit = lbl_80563BF0;
    b = b - a;
    b = limit > b ? limit : b;
    *(float *)((char *)arg0 + 0x18) = b;
    if (fn_802645C0() != 0) {
        c = fn_80214D48();
        b = *(float *)((char *)arg0 + 0x20);
        b = b + c;
        *(float *)((char *)arg0 + 0x20) = b;
    }
    c = fn_80214D48();
    b = *(float *)((char *)arg0 + 0x1C);
    limit = lbl_80563BF0;
    b = b - c;
    b = limit > b ? limit : b;
    *(float *)((char *)arg0 + 0x1C) = b;
}
#pragma dont_inline off
void *fn_80264968(void *arg0, int arg1) {
    struct Local {
        char pad_00[0x54];
        void *field_54;
        void *field_58;
        void *field_5C;
        void *field_60;
        void *field_64;
        char pad_68[0x4C];
        void *field_B4;
        void *field_B8;
        void *field_BC;
        void *field_C0;
        void *field_C4;
    };
    struct Local *p = (struct Local *)arg0;
    if (arg0 != 0) {
        lbl_8055F448 = 0;
        if ((char *)arg0 + 0x78 != 0) {
            if (p->field_B4 != 0) {
                fn_80235380(p->field_B4);
                p->field_B4 = 0;
            }
            if (&p->field_B8 != 0) {
                fn_80128670(p->field_C4);
                if (&p->field_B8 != 0) {
                    p->field_B8 = 0;
                    p->field_BC = 0;
                    p->field_C0 = 0;
                }
            }
        }
        if ((char *)arg0 + 0x18 != 0) {
            if (p->field_54 != 0) {
                fn_80235380(p->field_54);
                p->field_54 = 0;
            }
            if (&p->field_58 != 0) {
                fn_80128670(p->field_64);
                if (&p->field_58 != 0) {
                    p->field_58 = 0;
                    p->field_5C = 0;
                    p->field_60 = 0;
                }
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void *lbl_8055F448;
void* fn_80264A54(void) {
    return lbl_8055F448;
}

#pragma push
#pragma processor 750
void fn_80264A5C(float farg0, float farg1) {
    extern float lbl_80558DC4[];
    extern float lbl_80563BF0;
    extern float lbl_80563C00;
    extern float lbl_80563C08;
    extern float lbl_80563C0C;
    extern float fn_80214D48(void);
    extern void fn_80230C30(float *, float *, int, int);
    extern float fn_80129DC4(int, float, float);
    extern int fn_80129D18(int, int);
    extern int fn_80235FD8(int);
    extern double cos(double);
    extern double sin(double);
    float sp18;
    float sp1C;
    float sp10;
    float sp14;
    float spC;
    float sp8;
    float temp_f0;
    float temp_f0_2;
    float temp_f2;
    float temp_f30;
    float temp_f30_2;
    float temp_f31;
    float temp_f31_2;
    float temp_f3;
    float temp_f4;
    int temp_r0;
    int temp_r0_2;
    int temp_r4;
    int temp_r4_2;
    int temp_r5;
    int temp_r5_2;
    int temp_r6;
    int temp_r6_2;
    void *temp_r31;
    void *temp_r31_2;
    void *temp_r30;
    void *temp_r30_2;

    if (!((float)__fabs((double)fn_80214D48()) <= lbl_80558DC4[0])) {
        fn_80230C30(&spC, &sp8, (int)farg0, (int)farg1);
        temp_f4 = spC + (farg0 - (float)(int)farg0);
        temp_f3 = sp8 - (farg1 - (float)(int)farg1);
        spC = temp_f4;
        sp8 = temp_f3;
        sp18 = temp_f4;
        temp_r31 = lbl_8055F448;
        temp_f0 = *(float *)((char *)temp_r31 + 0x74) + *(float *)((char *)temp_r31 + 0x40);
        sp1C = temp_f3;
        *(float *)((char *)temp_r31 + 0x74) = temp_f0;
        if (temp_f0 > lbl_80563C00 && *(int *)((char *)temp_r31 + 0x5C) + 1 <= *(int *)((char *)temp_r31 + 0x60)) {
            *(float *)((char *)temp_r31 + 0x74) = *(float *)((char *)temp_r31 + 0x74) - lbl_80563C00;
            temp_r5 = *(int *)((char *)temp_r31 + 0x5C);
            temp_r6 = *(int *)((char *)temp_r31 + 0x58);
            temp_r4 = temp_r5 + 1;
            *(int *)((char *)temp_r31 + 0x5C) = temp_r4;
            temp_r0 = temp_r5 << 5;
            temp_r30 = (void *)((char *)temp_r6 + temp_r0);
            *(float *)((char *)temp_r6 + temp_r0) = temp_f4;
            *(float *)((char *)temp_r30 + 4) = temp_f3;
            temp_f30 = fn_80129DC4(6, *(float *)((char *)temp_r31 + 0x1C), *(float *)((char *)temp_r31 + 0x20));
            temp_f31 = fn_80129DC4(6, *(float *)((char *)temp_r31 + 0x24), *(float *)((char *)temp_r31 + 0x28));
            *(float *)((char *)temp_r30 + 8) = temp_f31 * (float)cos((double)temp_f30);
            *(float *)((char *)temp_r30 + 0xC) = temp_f31 * (float)sin((double)temp_f30);
            *(float *)((char *)temp_r30 + 0x10) = fn_80129DC4(6, lbl_80563BF0, lbl_80563C08);
            *(float *)((char *)temp_r30 + 0x14) = fn_80129DC4(6, *(float *)((char *)temp_r31 + 0x34), *(float *)((char *)temp_r31 + 0x38));
            *(float *)((char *)temp_r30 + 0x18) = *(float *)((char *)temp_r31 + 0x44);
            *(int *)((char *)temp_r30 + 0x1C) = fn_80129D18(6, fn_80235FD8(*(int *)((char *)temp_r31 + 0x54)));
        }
        temp_r31_2 = lbl_8055F448;
        temp_f4 = spC;
        temp_f0_2 = *(float *)((char *)temp_r31_2 + 0xD4) + *(float *)((char *)temp_r31_2 + 0xA0);
        temp_f2 = lbl_80563C0C + sp8;
        sp10 = temp_f4;
        *(float *)((char *)temp_r31_2 + 0xD4) = temp_f0_2;
        sp14 = temp_f2;
        if (temp_f0_2 > lbl_80563C00 && *(int *)((char *)temp_r31_2 + 0xBC) + 1 <= *(int *)((char *)temp_r31_2 + 0xC0)) {
            *(float *)((char *)temp_r31_2 + 0xD4) = *(float *)((char *)temp_r31_2 + 0xD4) - lbl_80563C00;
            temp_r5_2 = *(int *)((char *)temp_r31_2 + 0xBC);
            temp_r6_2 = *(int *)((char *)temp_r31_2 + 0xB8);
            temp_r4_2 = temp_r5_2 + 1;
            *(int *)((char *)temp_r31_2 + 0xBC) = temp_r4_2;
            temp_r0_2 = temp_r5_2 << 5;
            temp_r30_2 = (void *)((char *)temp_r6_2 + temp_r0_2);
            *(float *)((char *)temp_r6_2 + temp_r0_2) = temp_f4;
            *(float *)((char *)temp_r30_2 + 4) = temp_f2;
            temp_f30_2 = fn_80129DC4(6, *(float *)((char *)temp_r31_2 + 0x7C), *(float *)((char *)temp_r31_2 + 0x80));
            temp_f31_2 = fn_80129DC4(6, *(float *)((char *)temp_r31_2 + 0x84), *(float *)((char *)temp_r31_2 + 0x88));
            *(float *)((char *)temp_r30_2 + 8) = temp_f31_2 * (float)cos((double)temp_f30_2);
            *(float *)((char *)temp_r30_2 + 0xC) = temp_f31_2 * (float)sin((double)temp_f30_2);
            *(float *)((char *)temp_r30_2 + 0x10) = fn_80129DC4(6, lbl_80563BF0, lbl_80563C08);
            *(float *)((char *)temp_r30_2 + 0x14) = fn_80129DC4(6, *(float *)((char *)temp_r31_2 + 0x94), *(float *)((char *)temp_r31_2 + 0x98));
            *(float *)((char *)temp_r30_2 + 0x18) = *(float *)((char *)temp_r31_2 + 0xA4);
            *(int *)((char *)temp_r30_2 + 0x1C) = fn_80129D18(6, fn_80235FD8(*(int *)((char *)temp_r31_2 + 0xB4)));
        }
    }
}

void fn_80264D5C(void *arg0) {
 extern float fn_80214D48(void); extern float lbl_80558DC4[];
 int i,off,count; float dt,x,y; unsigned char *p,*last;
 dt=fn_80214D48(); i=0; off=0;
 while(i<*(int*)((char*)arg0+0x5C)){p=*(unsigned char**)((char*)arg0+0x58)+off; *(float*)(p+0x18)-=dt;
 if(*(float*)(p+0x18)<lbl_80558DC4[0]){count=*(int*)((char*)arg0+0x5C);if(i>=0&&i<count){last=*(unsigned char**)((char*)arg0+0x58)+(count-1)*32;if(i!=count-1){*(int*)p=*(int*)last;*(int*)(p+4)=*(int*)(last+4);*(int*)(p+8)=*(int*)(last+8);*(int*)(p+12)=*(int*)(last+12);*(float*)(p+16)=*(float*)(last+16);*(float*)(p+20)=*(float*)(last+20);*(float*)(p+24)=*(float*)(last+24);*(int*)(p+28)=*(int*)(last+28);}*(int*)((char*)arg0+0x5C)=count-1;}}
 else{off+=32;i++;x=*(float*)(p+8)+*(float*)((char*)arg0+0x2C)*dt;*(float*)(p+8)=x;y=*(float*)(p+12)+*(float*)((char*)arg0+0x30)*dt;*(float*)(p+12)=y;*(float*)p+=x*dt;*(float*)(p+4)+=y*dt;*(float*)(p+16)+=*(float*)(p+20)*dt;}}
 dt=fn_80214D48();i=0;off=0;
 while(i<*(int*)((char*)arg0+0xBC)){p=*(unsigned char**)((char*)arg0+0xB8)+off;*(float*)(p+0x18)-=dt;
 if(*(float*)(p+0x18)<lbl_80558DC4[0]){count=*(int*)((char*)arg0+0xBC);if(i>=0&&i<count){last=*(unsigned char**)((char*)arg0+0xB8)+(count-1)*32;if(i!=count-1){*(int*)p=*(int*)last;*(int*)(p+4)=*(int*)(last+4);*(int*)(p+8)=*(int*)(last+8);*(int*)(p+12)=*(int*)(last+12);*(float*)(p+16)=*(float*)(last+16);*(float*)(p+20)=*(float*)(last+20);*(float*)(p+24)=*(float*)(last+24);*(int*)(p+28)=*(int*)(last+28);}*(int*)((char*)arg0+0xBC)=count-1;}}
 else{off+=32;i++;x=*(float*)(p+8)+*(float*)((char*)arg0+0x8C)*dt;*(float*)(p+8)=x;y=*(float*)(p+12)+*(float*)((char*)arg0+0x90)*dt;*(float*)(p+12)=y;*(float*)p+=x*dt;*(float*)(p+4)+=y*dt;*(float*)(p+16)+=*(float*)(p+20)*dt;}}
}

#pragma cplusplus on
extern "C" void fn_80264FD4(void *arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
    };
    ((Dummy*)arg0)->f5();
}

void fn_80264FE4(void *arg0) {
    extern float lbl_80563BF0, lbl_80563C00;
    extern float fn_80235F64(void *, int), fn_80235EF0(void *, int);
    extern void fn_80235AFC(void *, int, unsigned int, float, float, float, float, float, float);
    int i, offset, alpha, id;
    unsigned char *item;
    float limit, value, scale, base, intensity;
    void *renderer;
    limit = lbl_80563C00;
    i=0; offset=0;
    while (i < *(int *)((char *)arg0+0xBC)) {
      item=*(unsigned char **)((char *)arg0+0xB8)+offset;
      value=*(float *)((char *)arg0+0xD0)*(*(float *)((char *)arg0+0xA4)-*(float *)(item+0x18));
      if(limit<value)value=limit;
      if(value<=lbl_80563BF0)value=lbl_80563BF0;
      alpha=(int)(value*(*(float *)(item+0x18)**(float *)((char *)arg0+0xCC)));
      if(alpha<0)alpha=-alpha; if(alpha>255)alpha=255;
      id=*(int *)(item+0x1C);
      scale=*(float *)(item+0x18)**(float *)((char *)arg0+0xC8);
      base=*(float *)((char *)arg0+0xAC)+*(float *)((char *)arg0+0xB0)*(limit-scale);
      renderer=*(void **)((char *)arg0+0xB4);
      intensity=base*fn_80235F64(renderer,id);
      scale=base*fn_80235EF0(renderer,id);
      fn_80235AFC(renderer,id,((unsigned int)alpha<<24)|0xFFFFFF,*(float *)item,*(float *)(item+4),lbl_80563BF0,scale,intensity,*(float *)(item+0x10));
      offset+=32; i++;
    }
    limit=lbl_80563C00; i=0; offset=0;
    while(i<*(int *)((char *)arg0+0x5C)){
      item=*(unsigned char **)((char *)arg0+0x58)+offset;
      value=*(float *)((char *)arg0+0x70)*(*(float *)((char *)arg0+0x44)-*(float *)(item+0x18));
      if(limit<value)value=limit;
      if(value<=lbl_80563BF0)value=lbl_80563BF0;
      alpha=(int)(value*(*(float *)(item+0x18)**(float *)((char *)arg0+0x6C)));
      if(alpha<0)alpha=-alpha; if(alpha>255)alpha=255;
      id=*(int *)(item+0x1C);
      scale=*(float *)(item+0x18)**(float *)((char *)arg0+0x68);
      base=*(float *)((char *)arg0+0x4C)+*(float *)((char *)arg0+0x50)*(limit-scale);
      renderer=*(void **)((char *)arg0+0x54);
      intensity=base*fn_80235F64(renderer,id);
      scale=base*fn_80235EF0(renderer,id);
      fn_80235AFC(renderer,id,((unsigned int)alpha<<24)|0xFFFFFF,*(float *)item,*(float *)(item+4),lbl_80563BF0,scale,intensity,*(float *)(item+0x10));
      offset+=32; i++;
    }
}

#pragma cplusplus off
void fn_8026523C(void *arg0) {
    extern char lbl_80346618[];
    extern float lbl_80563BF0;
    float value = lbl_80563BF0;
    *(void **)arg0 = lbl_80346618;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(unsigned char *)((char *)arg0 + 0x1C) = 0;
    *(int *)((char *)arg0 + 0xB4) = 0;
    *(float *)((char *)arg0 + 0xB8) = value;
}

int strlen(char *);
void fn_80265268(void *arg0, int arg1, char *arg2, float farg0) {
    char *dst = (char *)arg0 + 0x1C;
    int count = 0x96;
    char *src = arg2;
    unsigned char c;
    *(int *)((char *)arg0 + 0x18) = arg1;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
    goto done;
done:
    *(int *)((char *)arg0 + 0xB4) = strlen((char *)arg0 + 0x1C);
    *(float *)((char *)arg0 + 0xB8) = farg0;
}

void fn_80265558(void *arg0) {
    extern char lbl_803465B8[];
    extern float lbl_80563BF0;
    float value = lbl_80563BF0;
    *(void **)arg0 = lbl_803465B8;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(float *)((char *)arg0 + 0x18) = value;
    *(float *)((char *)arg0 + 0x1C) = value;
}

void fn_8026557C(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x18) = farg0;
}

void fn_80265584(void *arg0) {
    extern float lbl_8055C454;
    *(float *)((char *)arg0 + 0x1C) = lbl_8055C454;
    lbl_8055C454 = *(float *)((char *)arg0 + 0x18);
}

extern char lbl_80346558[];
extern float lbl_80563BF0;
extern float lbl_8055C454;
void fn_80265598(void *arg0) {
    extern float lbl_8055C454;
    lbl_8055C454 = *(float *)((char *)arg0 + 0x1C);
}

void fn_802655A4(void *arg0) {
    extern void *lbl_8055F44C;
    extern char lbl_80346558[];
    extern float lbl_80563BF0;
    void *ptr = lbl_80346558;
    float value = lbl_80563BF0;
    *(void **)arg0 = ptr;
    *(int *)((char *)arg0 + 0x14) = 0;
    lbl_8055F44C = arg0;
    *(float *)((char *)arg0 + 0x1C) = value;
}

int fn_802655C8(int arg0, int arg1) {
    extern void *lbl_8055F44C;
    if (arg0 != 0) {
        lbl_8055F44C = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

typedef float f32;
void fn_80265610(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

void fn_80265618(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x20) = 0;
    *(float *)((char *)arg0 + 0x18) = *(float *)((char *)arg0 + 0x1C);
}

#pragma dont_inline on
void fn_8026562C(void *arg0) {
    extern float lbl_80558DC4[];
    extern float fn_80214D48();
    fn_802645EC();
    if (*(float *)((char *)arg0 + 0x18) > lbl_80558DC4[0]) {
        *(float *)((char *)arg0 + 0x18) -= fn_80214D48();
    } else {
        *(unsigned char *)((char *)arg0 + 0x20) = 1;
    }
}

int fn_80265688(void) {
    if (fn_80265B5C() != 0) {
        fn_802168BC(-1);
        return 1;
    }
    fn_80216D28();
    return 0;
}

#pragma dont_inline reset
extern char lbl_8055C4A8[4];
extern void fn_80236954(void *queue);
void fn_802658FC(void) {
    fn_80236954(lbl_8055C4A8);
}

void fn_80265904(void) {
    fn_80236914();
    if (fn_8023695C(lbl_8055C4A8) == 2) {
        fn_80216CA8();
        fn_802168BC(0);
    }
}

extern int fn_802146BC(int *, int, int, int, int, int, int, int);
extern int lbl_80498F58[5];
extern int lbl_802FA73C[5];
__declspec(section ".sdata") extern char lbl_8055BAC0[];
__declspec(section ".sdata") extern char lbl_8055BAB8[];
extern void fn_802658FC(void);
extern void fn_80265904(void);
#pragma push
#pragma use_lmw_stmw off
void fn_80265940(void) {
      int data[24];
      int *v;
      v = lbl_802FA73C;
      data[15] = lbl_80498F58[0];
      data[16] = lbl_80498F58[1];
      data[17] = lbl_80498F58[2];
      data[18] = lbl_80498F58[3];
      data[19] = lbl_80498F58[4];
      data[0] = v[0];
      data[1] = (int)&data[5];
      data[2] = v[2];
      data[3] = v[3];
      data[4] = v[4];
      data[7] = (int)fn_802658FC;
      data[12] = (int)fn_80265904;
      data[5] = (int)lbl_8055BAC0;
      data[10] = (int)lbl_8055BAB8;
      data[13] = 2;
      data[6] = 8;
      data[11] = 8;
      data[8] = 0;
      data[9] = 0;
      data[14] = 0;
      fn_802146BC(data, -999, -999, 1, v[4], v[3], v[2], v[0]);
  }
#pragma pop
extern void fn_80236954(void *);
extern int fn_8023695C(void *);
extern void fn_80216CA8(void);
extern void fn_802168BC(int);
extern char lbl_803464EC[];
extern void *lbl_8055F44C;
extern unsigned char lbl_8055F450;
int fn_80128668(void);
#pragma push
#pragma small_data off
void fn_80265A28(void) {
    fn_80236954(lbl_803464EC);
}
#pragma pop
void fn_80265A34(void) {
    fn_80236914();
    if (fn_8023695C(lbl_803464EC) == 2) {
        fn_80216CA8();
        fn_802168BC(0);
    }
}

int fn_80265B5C(void) {
    int ret = 1;
    void *p = lbl_8055F44C;
    int flag = 0;

    if (p != 0 && *((unsigned char *)p + 0x20) != 0) {
        flag = 1;
    }
    if (flag != 0) {
        goto done;
    }
    if (lbl_8055F450 == 0) {
        ret = 0;
    }
done:
    return ret;
}

int fn_80265B9C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265BDC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265C1C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

