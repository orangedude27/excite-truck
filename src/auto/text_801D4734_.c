

      __declspec(section ".rodata") extern char lbl_80338460;
    extern char lbl_803385D0[];
      extern char lbl_803387C8[];
  extern char lbl_80338C78[];
extern char lbl_80338BD0[];
extern int fn_80128668(void);
typedef struct { char *name; int state; } UnkStruct_801D701C;
extern char lbl_80339038[];
extern char lbl_8033905C[];
extern char lbl_8033907C[];
extern float lbl_8055E3C8;
extern char lbl_803388D4[];
extern char lbl_803388F0[];
extern char lbl_803389B8[];
extern char lbl_8033890C[];
extern void fn_8016A240(const char *arg0);
extern int lbl_8055E3C4;
extern char lbl_804422F0[];
extern float lbl_80562ADC;
extern int fn_801D56C0(void*);
extern void fn_801D5328(int, int);
extern void fn_801D5A14(int);
extern void fn_801D5A1C(int);
extern void fn_801D59C8(int, int);
extern char lbl_80338D80[];
void fn_801D47F4(void) {
    fn_801D57F0();
}

void fn_801D47F8(void* alarm) {
    fn_801D5488(fn_801D5650(alarm));
}

int fn_801D481C(void) {
    char* object = lbl_804422F0;
    float value = lbl_80562ADC;
    *(float*)(object + 0x14) = value;
    *(float*)(object + 0x18) = value;
    *(float*)(object + 0x1C) = value;
    *(float*)(object + 0x4) = value;
    return fn_801D56C0(object);
}

#pragma cplusplus on
extern "C" signed char lbl_8055E954;
extern "C" char lbl_804422F0[];
extern "C" void fn_801D5730(void);
extern "C" void fn_801D483C(void) {
    struct TObjD1Arg { virtual void d0(int); };
    lbl_8055E954 = 0;
    TObjD1Arg *obj = *(TObjD1Arg **)lbl_804422F0;
    if (obj != 0) {
        obj->d0(1);
    }
    fn_801D5730();
}
#pragma cplusplus reset

void fn_801D4888(void) {
    fn_801D5860();
}

void fn_801D48F4(void) {
    fn_801D58DC();
}

void fn_801D48F8(void) {
    fn_801D592C();
}

void fn_801D48FC(int arg0) {
    fn_801D5A14(arg0);
}

void fn_801D4900(int arg0) {
    fn_801D5A1C(arg0);
}

void fn_801D4904(void) {
    fn_801D5A24();
}

void fn_801D4908(void) {
    fn_801D5A2C();
}

extern void fn_8000FF88(int, int, void *, char *, float, float, float);
extern char lbl_80442310[];
extern char lbl_8055AD58[], lbl_8055AD5C[];
extern float lbl_8055E3C8, lbl_80562AD8, lbl_80562ADC, lbl_80562AE0, lbl_80562AE4, lbl_80562AE8, lbl_80562AEC, lbl_80562AF0, lbl_80562AF4, lbl_80562AF8, lbl_80562AFC;
extern char *strchr(char *, int);
void fn_801D490C(void) {
 float x, width, right, alpha, t, edge, y, dy; int color,n; char text[0x40], *src,*dst,*part,*caret;
 x=*(float *)lbl_80442310; width=*(float *)(lbl_80442310+4); right=x+width; alpha=lbl_80562AE0; y=lbl_80562AD8; dy=lbl_80562AFC; src=lbl_80442310+8; dst=text; n=0x40;
 if(lbl_8055E3C8>=right)return;
 if(width>lbl_80562AE4) {
  t=lbl_8055E3C8-x;
  if(t<lbl_80562AE8) {
   t=t/((lbl_80562AE8+x)-x); if(alpha<t)alpha=t; if(alpha>lbl_80562ADC)alpha=lbl_80562ADC; alpha=lbl_80562ADC+alpha*lbl_80562AE0;
  } else {
   edge=right-lbl_80562AE8;
   if(lbl_8055E3C8>edge) { t=(lbl_8055E3C8-edge)/(right-edge); if(alpha<t)alpha=t; if(alpha>lbl_80562ADC)alpha=lbl_80562ADC; alpha=lbl_80562AE0+alpha*lbl_80562AEC; }
  }
 }
 color=((int)(lbl_80562AF0*alpha)<<24)|0x00ffffff;
 fn_8000FF88(color,0xC,lbl_8055AD5C,lbl_80442310+0x48,lbl_80562AF4,lbl_80562ADC,lbl_80562AF8);
 while(n>0) { char c=*src++; *dst++=c; if((signed char)c==0)break; n--; }
 if(n<=0)dst[-1]=0;
 part=text;
 do { caret=strchr(part,0x5e); if(caret)*caret=0; fn_8000FF88(color,0xC,lbl_8055AD58,part,lbl_80562AE0,lbl_80562ADC,y); if(caret)part=caret+1;else part=0; y-=dy; } while(part&&(signed char)*part);
}

#pragma cplusplus on
extern "C" void *fn_801D4B60(void *arg0, int arg1) {
 extern char lbl_80338D80[], lbl_80338490[];
 struct Ref { virtual void release(int); };
 char *src; int i; char *dst; int count, offset; void **items; Ref *entry;
 if(arg0) {
  *(void **)arg0=lbl_80338D80;
  if(*(int *)((char *)arg0+4)) {
   count=*(int *)((char *)arg0+0x34); *(int *)((char *)arg0+4)=0; offset=count*4;
loop:
   items=*(void ***)((char *)arg0+0x30); entry=(Ref *)items[count];
   if(count>=0 && count<*(int *)((char *)arg0+0x34)) {
    if(count!=*(int *)((char *)arg0+0x34)-1) items[count]=items[*(int *)((char *)arg0+0x34)-1];
    *(int *)((char *)arg0+0x34)=*(int *)((char *)arg0+0x34)-1;
   }
   if(entry) entry->release(1);
   if(count>0) { offset-=4; count--; goto loop; }
  }
  src=lbl_80338490; dst=(char *)arg0+8; i=0x14; goto copy;
copy:
  i--; if(i<=0) { dst[-1]=0; goto copied; }
  *dst++=*src++;
  if((signed char)dst[-1]!=0) goto copy;
copied:
  if((char *)arg0+0x30) {
   if((char *)arg0+0x30) {
    *(volatile int *)((char *)arg0+0x30)=0; *(int *)((char *)arg0+0x34)=0; *(int *)((char *)arg0+0x38)=0;
   }
  }
  if(arg1>0) ((void (*)(void *))fn_80128668)(arg0);
 }
 return arg0;
}
#pragma cplusplus reset
int fn_801D4CB8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801D4F9C(void) {
}

void fn_801D5010(void) {
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" int fn_801D5014(void *arg0, int arg1, int arg2, int arg3) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual int test(int, int);
    };
    int offset;
    int i;
    Dummy *obj;

    i = 0;
    offset = 0;
    while (i < *(int *)((char *)arg0 + 0x34)) {
        obj = *(Dummy **)(*(char **)((char *)arg0 + 0x30) + offset);
        if (obj->test(arg1, arg2) != 0) {
            return 1;
        }
        offset += 4;
        i += 1;
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop

int fn_801D50A0(void) {
    return 0;
}

void fn_801D50A8(int arg0) {
    fn_801D5328(arg0, 1);
}

void fn_801D50B0(int arg0) {
    fn_801D5328(arg0, 0);
}

#pragma cplusplus on
void fn_801D5328(int arg0, int arg1) {
 struct Dummy { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual int state(); virtual void v6(); virtual int apply(int); };
 int mode, changed, count, offset;
 Dummy *item;
 if (*(int *)(arg0+4)!=1) return;
 *(unsigned char *)(arg0+0x2c)=arg1;
 mode=((unsigned char)arg1==0); changed=0; count=0; offset=0;
 goto test1;
loop1:
 item=*(Dummy **)(*(int *)(arg0+0x30)+offset);
 if(item->state()==0 && item->apply(mode)!=0) changed=1;
 offset+=4; count++;
test1:
 if(count<*(int *)(arg0+0x34)) goto loop1;
 if(changed==0) goto done;
 count=0; offset=0;
 goto test2;
loop2:
 item=*(Dummy **)(*(int *)(arg0+0x30)+offset);
 if(item->state()!=0) item->apply(mode);
 offset+=4; count++;
test2:
 if(count<*(int *)(arg0+0x34)) goto loop2;
done:
 *(int *)(arg0+4)=2;
}
#pragma cplusplus reset

int fn_801D544C(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801D5520(char *arg0) {
 struct Manager { virtual void v0(); virtual void *get(int); };
 struct Node { virtual const char *name(); };
 extern void *fn_80131810(void); extern void fn_80131818(void *); extern void *fn_801D4B34(void); extern int fn_801D4CF8(void *,void *); extern void *fn_801284F8(int,void *); extern void fn_802E30C8(const char *,const char *); extern int stricmp(const char *,const char *); extern char lbl_80338460; extern int lbl_804423A4[];
 Manager *manager=(Manager *)fn_80131810(); int i=0;
 if(!manager) { fn_802E30C8((char *)&lbl_80338460+0x120,arg0); return; }
 for(;;) {
  void *node=manager->get(i); if(!node) break;
  const char *name=((Node *)node)->name();
  if(stricmp(name,(char *)&lbl_80338460+0x150)==0) {
   void *obj=fn_801284F8(0x13c,(char *)&lbl_80338460+0x160);
   if(obj) obj=fn_801D4B34();
   if(fn_801D4CF8(obj,node)) {
    int n=lbl_804423A4[1]++;
    ((void **)lbl_804423A4[0])[n]=obj;
   } else if(obj) ((void (*)(void *,int))(*(void ***)obj)[2])(obj,1);
  }
  i++;
 }
 fn_80131818(manager);
}
#pragma cplusplus reset

extern int lbl_804423A4[];
extern void fn_801D50B8(int);
#pragma scheduling invalid_target
int fn_801D5650(void *alarm) {
    int offset;
    int i;
    offset = 0;
    i = 0;
    while (i < lbl_804423A4[1]) {
        fn_801D50B8(*(int *)((char *)lbl_804423A4[0] + offset));
        offset += 4;
        i += 1;
    }
}

extern void fn_801D52A4(int);
int fn_801D56C0(void *alarm) {
    int offset;
    int i;
    offset = 0;
    i = 0;
    while (i < lbl_804423A4[1]) {
        fn_801D52A4(*(int *)((char *)lbl_804423A4[0] + offset));
        offset += 4;
        i += 1;
    }
}

extern void fn_801D4FA0(int);
int fn_801D57F0(void *alarm) {
    int offset;
    int i;
    offset = 0;
    i = 0;
    while (i < lbl_804423A4[1]) {
        fn_801D4FA0(*(int *)((char *)lbl_804423A4[0] + offset));
        offset += 4;
        i += 1;
    }
}

#pragma scheduling reset
void fn_801D5A14(int arg0) {
    fn_801D59C8(arg0, 2);
}

void fn_801D5A1C(int arg0) {
    fn_801D59C8(arg0, 1);
}

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801D6080(void *arg0) {
    int *p = (int *)arg0;
    int offset;
    int count;
    void *obj;
    struct TObjD1Call {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
    };
    if (p[2] == 2 && lbl_8055E3C4 - p[0x1B] >= p[0x1A]) {
        count = 0;
        offset = 0;
        while (count < p[0x1D]) {
            obj = *(void **)((char *)p[0x1C] + offset);
            ((TObjD1Call *)obj)->f9();
            offset += 4;
            count++;
        }
        p[2] = 3;
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801D611C(void *arg0, void *arg1, void *arg2) {
    struct Dummy {
        virtual void *get();
        virtual void v1();
        virtual void v2();
        virtual void *transform(float, float, float);
        virtual short index();
        virtual void v5();
        virtual int find(char *, int);
    };
    extern float PSVECDotProduct(float *, float *);
    extern void fn_801796CC(int, void *, int);
    Dummy *obj = (Dummy *)arg1;
    float input[3], output[3], dot;
    int count, offset, id, value;
    void *found, *vec;
    if (*(int *)((char *)arg0 + 0x14) <= 0) return;
    found = obj->get();
    id = *(int *)((char *)arg0 + 0xC);
    if (id < 0 || found == 0) return;
    if (((Dummy *)found)->find(lbl_803385D0, -1) != id) return;
    input[0] = *(float *)arg2;
    input[1] = *((float *)arg2 + 1);
    input[2] = *((float *)arg2 + 2);
    vec = obj->transform(input[0], input[1], input[2]);
    output[0] = *(float *)vec;
    output[1] = *((float *)vec + 1);
    output[2] = *((float *)vec + 2);
    obj->index();
    dot = PSVECDotProduct(output, output);
    count = 0;
    offset = 0;
    goto test;
loop:
    {
        char *entry = (char *)*(int *)((char *)arg0 + 0x10) + offset;
        if (dot >= *(float *)(entry + 4)) {
            value = *(int *)entry;
            fn_801796CC(10, input, 32);
        }
    }
    offset += 8;
    count += 1;
test:
    if (count < *(int *)((char *)arg0 + 0x14)) goto loop;
}
#pragma cplusplus reset

void fn_801D628C(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(char **)((char *)arg0 + 0) = lbl_80338C78;
    *(int *)((char *)arg0 + 0x14) = 0;
}

int fn_801D6320(void *out, void *object) {
    extern char lbl_80338460;
    extern char lbl_8055ACB0, lbl_8055ACB8, lbl_8055ACC0, lbl_8055ACC8;
    extern float lbl_80562ADC, lbl_80562AE4, lbl_80562B0C;
    extern int fn_801399FC(void);
    extern void fn_802E30C8(const char *, const char *);
    char *messages = &lbl_80338460;
    float a, b;
    if (((int (*)(void *, const char *))(*(void **)(*(void ***)object + 0xC)))(object, &lbl_8055ACB0) == 0) { fn_802E30C8(messages + 0x210, 0); return 0; }
    a = ((float (*)(void *, const char *))(*(void **)(*(void ***)object + 0x24)))(object, &lbl_8055ACB0);
    if (a < lbl_80562ADC) { fn_802E30C8(messages + 0x254, 0); return 0; }
    *(int *)((char *)out + 0xC) = (int)(lbl_80562B0C * a);
    *(int *)((char *)out + 8) = (int)(lbl_80562B0C * ((float (*)(void *, const char *, float))(*(void **)(*(void ***)object + 0x28)))(object, &lbl_8055ACB8, lbl_80562ADC));
    if (((int (*)(void *, const char *))(*(void **)(*(void ***)object + 0xC)))(object, &lbl_8055ACC0) == 0) { fn_802E30C8(messages + 0x2A4, 0); return 0; }
    b = ((float (*)(void *, const char *, float))(*(void **)(*(void ***)object + 0x28)))(object, &lbl_8055ACC0, lbl_80562AE4);
    *(float *)((char *)out + 0x10) = b;
    if (b < lbl_80562ADC) { fn_802E30C8(messages + 0x2E8, 0); return 0; }
    *(int *)((char *)out + 0x14) = 0;
    if (((int (*)(void *, const char *))(*(void **)(*(void ***)object + 0x5C)))(object, &lbl_8055ACC8)) *(int *)((char *)out + 0x14) = fn_801399FC();
    *(signed char *)((char *)out + 0x18) = ((signed char (*)(void *, const char *, int))(*(void **)(*(void ***)object + 0x30)))(object, messages + 0x338, 0);
    *(int *)((char *)out + 4) = 1;
    return 1;
}

int *__AXFXGetLfoSinTable_801D64F4(void) {
    extern char lbl_803387A8[];
    return (int *)lbl_803387A8;
}

int fn_801D6500(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D6508(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[7] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D6534(void *self) {
    extern int fn_80139B5C(int);
    extern int fn_8017960C(int);
    extern void fn_80267E40(int, float);
    int object;
    int index;
    int filter;
    if (*(int *)((char *)self + 4) != 2) return;
    if (lbl_8055E3C4 - *(int *)((char *)self + 0x1C) < *(int *)((char *)self + 8)) return;
    index = 0;
    goto fetch;
process:
    filter = *(int *)((char *)self + 0x14);
    if (filter == 0 || fn_80139B5C(object) != 0)
        fn_80267E40(object, *(float *)((char *)self + 0x10));
    index++;
fetch:
    object = fn_8017960C(index);
    if (object != 0) goto process;
    if (lbl_8055E3C4 - *(int *)((char *)self + 0x1C) >= *(int *)((char *)self + 8) + *(int *)((char *)self + 0xC))
        *(int *)((char *)self + 4) = 3;
}

void fn_801D6600(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D6618(UnkStruct_801D701C *arg0) {
    extern char lbl_80338C40[];
    arg0->name = lbl_80338C40;
    arg0->state = 0;
}
#pragma scheduling reset

int fn_801D6630(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

int fn_801D67D4(void) {
    return (int)lbl_803387C8;
}

int fn_801D67E0(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D67E8(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

void fn_801D68D0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D68E8(UnkStruct_801D701C *arg0) {
    arg0->name = lbl_80338BD0;
    arg0->state = 0;
}
#pragma scheduling reset
int fn_801D6900(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

int fn_801D6C28(void) {
    extern char lbl_80338868[];
    return (int)lbl_80338868;
}

int fn_801D6C34(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D6C3C(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

#pragma scheduling invalid_target
void fn_801D6D68(UnkStruct_801D701C *arg0) {
    extern char lbl_80338B98[];
    arg0->name = lbl_80338B98;
    arg0->state = 0;
}
#pragma scheduling reset
int fn_801D6D80(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma cplusplus on
extern "C" int fn_801D6DC8(void *arg0, void *arg1) {
 struct Dummy { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual char *get(char *, char *); virtual void v7(); virtual void v8(); virtual void v9(); virtual float value(char *, float); };
 extern char lbl_8055ACB0;
 extern char lbl_8055ACE8;
 extern char lbl_8055ACF0;
 extern char lbl_8055ACF4;
 extern float lbl_80562B14;
 Dummy *obj=(Dummy *)arg1; char *src; char *dst; int i;
 *(float *)((char *)arg0+8)=obj->value(&lbl_8055ACB0,lbl_80562B14);
 src=obj->get(&lbl_8055ACE8,&lbl_8055ACF0); dst=(char *)arg0+0xC;
 for(i=0;i<0x40 && (*dst++=*src++)!=0;i++) {} if(i==0x40) dst[-1]=0;
 src=obj->get(&lbl_8055ACF4,&lbl_8055ACF0); dst=(char *)arg0+0x4C;
 for(i=0;i<0x40 && (*dst++=*src++)!=0;i++) {} if(i==0x40) dst[-1]=0;
 *(int *)((char *)arg0+4)=1; return 1;
}
#pragma cplusplus reset

extern char lbl_80338868[];
extern char lbl_80338B98[];
extern char lbl_80338878[];
int fn_801D6ED0(void) {
    return (int)lbl_80338878;
}

int fn_801D6EDC(int arg0) {
    return ((int *)arg0)[1];
}

void fn_801D6FA0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

void fn_801D6FB8(int arg0) {
    if (*(unsigned char *)(arg0 + 0x34) == 0) {
        if (fn_8016A15C((char *)arg0 + 8) != 0) {
            int p = ((int *)arg0)[0x38 / 4];
            *(char *)(p + 0x49) = 1;
            *(char *)(p + 0x4B) = 0;
            *(char *)(p + 0x4A) = 0;
        }
        *(char *)(arg0 + 0x34) = 1;
    }
}

#pragma scheduling invalid_target
void fn_801D701C(UnkStruct_801D701C *arg0) {
    extern char lbl_80338B08[];
    arg0->name = lbl_80338B08;
    arg0->state = 0;
}
#pragma scheduling reset
int fn_801D7034(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma cplusplus on
extern "C" int fn_801D707C(void *arg0, void *arg1) {
 struct Dummy { virtual void v0(); virtual void v1(); virtual void v2(); virtual char *check(char *); virtual void v4(); virtual char *get(char *); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual float value(char *, float); };
 extern char lbl_80338888[];
 extern char lbl_803388C8[];
 extern char lbl_8055AC80;
 extern char lbl_8055ACB0;
 extern char lbl_8055ACB8;
 extern float lbl_80562ADC;
 extern float lbl_80562AEC;
 extern int fn_80207848(char *, int);
 extern void fn_802E30C8(char *);
 Dummy *obj=(Dummy *)arg1;
 char *src; char *dst; int i; float temp;
 if (obj->check(&lbl_8055AC80)==0) { fn_802E30C8(lbl_80338888); return 0; }
 src=obj->get(&lbl_8055AC80); dst=(char *)arg0+8;
 for(i=0;i<30 && (*dst++=*src++)!=0;i++) {}
 if(i==30) dst[-1]=0;
 *(float *)((char *)arg0+0x28)=obj->value(&lbl_8055ACB8,lbl_80562ADC);
 temp=obj->value(&lbl_8055ACB0,lbl_80562AEC);
 *(int *)((char *)arg0+4)=1;
 *(float *)((char *)arg0+0x30)=temp;
 *(float *)((char *)arg0+0x2C)=lbl_80562ADC;
 *((char *)arg0+0x34)=0;
 *(int *)((char *)arg0+0x38)=fn_80207848(lbl_803388C8,1);
 return 1;
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D71A8(void *arg0) {
    struct ThreadObject {
        virtual void destroy(int);
    };
    ThreadObject *obj = *(ThreadObject **)((char *)arg0 + 0x38);
    if (obj != 0 && obj != 0) {
        obj->destroy(1);
    }
    *(ThreadObject **)((char *)arg0 + 0x38) = 0;
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset

void *fn_801D7200(void) {
    return lbl_803388D4;
}

int fn_801D720C(int arg0) {
    return ((int *)arg0)[1];
}

int fn_801D7214(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[1] = 2;
        *(float *)((char *)arg0 + 0x2C) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

void fn_801D72D0(int arg0) {
    int p;
    fn_8016A240((char *)arg0 + 8);
    p = ((int *)arg0)[0x38 / 4];
    ((int *)arg0)[1] = 1;
    if (p != 0 && *(char *)(p + 0x19) != 0) {
        *(char *)(p + 0x4A) = 1;
        *(char *)(p + 0x4C) = 0;
    }
    *(char *)(arg0 + 0x34) = 0;
}

extern void *fn_801284F8(int, void *);
extern void fn_801D5AA8(void *);
extern int stricmp(const char *, const char *);
extern char lbl_80338A40[];
extern char lbl_80338A78[];
extern char lbl_80338B40[];
extern char lbl_80338C08[];
extern char lbl_80338CB0[];
extern char lbl_80338CE8[];
extern char lbl_8055ACFC;
extern char lbl_8055AD08;
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_801D7334(void *arg0) {
    extern char lbl_80338460;
    extern char lbl_8055ACF4;
    struct Request {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual const char *getName(const char *);
    };
    struct Object28 { void *vtable; char pad[0x24]; int value; };
    struct Object40 { void *vtable; char pad[0x3C]; int value; };
    struct Product {
        virtual void destroy(int);
        virtual int accept(void *);
    };
    char *strings = (char *)&lbl_80338460;
    Request *request = (Request *)arg0;
    const char *name = request->getName((const char *)&lbl_8055ACFC);
    void *product = 0;
    register void *object;

    if (stricmp(name, strings + 0x484) == 0) {
        object = fn_801284F8(0x17C, strings + 0x490);
        if (object != 0) {
            product = (Product *)((void *(*)(void *))fn_801D5AA8)(object);
            goto done;
        }
    }
    if (stricmp(name, strings + 0x4A0) == 0) {
        object = fn_801284F8(0x2C, strings + 0x4AC);
        if (object != 0) {
            ((Object28 *)object)->vtable = lbl_80338CE8;
            ((Object28 *)object)->value = 0;
            product = (Product *)object;
            goto done;
        }
    }
    if (stricmp(name, strings + 0x4BC) == 0) {
        object = fn_801284F8(0x44, strings + 0x4C8);
        if (object != 0) {
            ((Object40 *)object)->vtable = lbl_80338CB0;
            ((Object40 *)object)->value = 0;
            product = (Product *)object;
            goto done;
        }
    }
    if (stricmp(name, strings + 0x4D8) == 0) {
        object = fn_801284F8(0x20, strings + 0x348);
        if (object != 0) {
            product = (Product *)((void *(*)(void *))fn_801D628C)(object);
            goto done;
        }
    }
    if (stricmp(name, strings + 0x4E8) == 0) {
        object = fn_801284F8(0x34, strings + 0x368);
        if (object != 0) {
            product = (Product *)((void *(*)(void *))fn_801D6618)(object);
            goto done;
        }
    }
    if (stricmp(name, strings + 0x4F8) == 0) {
        object = fn_801284F8(0x34, strings + 0x408);
        if (object != 0) {
            product = (Product *)((void *(*)(void *))fn_801D68E8)(object);
            goto done;
        }
    }
    if (stricmp(name, (const char *)&lbl_8055ACF4) == 0) {
        object = fn_801284F8(0x8C, strings + 0x418);
        if (object != 0) {
            product = (Product *)((void *(*)(void *))fn_801D6D68)(object);
            goto done;
        }
    }
    if (stricmp(name, strings + 0x508) == 0) {
        object = fn_801284F8(0x1B0, strings + 0x514);
        if (object != 0) {
            *(void **)object = lbl_80338B40;
            *(void **)((char *)object + 4) = (char *)lbl_80338B40 + 0x38;
            *(void **)((char *)object + 0x24) = (char *)object + 0x30;
            *(int *)((char *)object + 0x2C) = 0x20;
            *(int *)((char *)object + 0x28) = 0;
            product = (Product *)object;
            goto done;
        }
    }
    if (stricmp(name, strings + 0x528) == 0) {
        object = fn_801284F8(0x18, strings + 0x538);
        if (object != 0) {
            *(void **)object = lbl_80338C08;
            *(int *)((char *)object + 4) = 0;
            product = (Product *)object;
            goto done;
        }
    }
    if (stricmp(name, strings + 0x54C) == 0) {
        object = fn_801284F8(0x3C, strings + 0x474);
        if (object != 0) {
            product = (Product *)((void *(*)(void *))fn_801D701C)(object);
            goto done;
        }
    }
    if (stricmp(name, (const char *)&lbl_8055AD08) == 0) {
        object = fn_801284F8(0x24, strings + 0x558);
        if (object != 0) {
            *(void **)object = lbl_80338A40;
            *(int *)((char *)object + 4) = 0;
            product = (Product *)object;
            goto done;
        }
    }
    if (stricmp(name, strings + 0x564) == 0) {
        object = fn_801284F8(0x1C, strings + 0x570);
        if (object != 0) {
            *(int *)((char *)object + 4) = 0;
            *(void **)object = lbl_80338A78;
            product = (Product *)object;
        }
    }
done:
    if (product != 0) {
        if (((Product *)product)->accept(arg0) != 0) return product;
    }
    if (product != 0) ((Product *)product)->destroy(1);
    return 0;
}
#pragma cplusplus reset
#pragma scheduling reset
#pragma dont_inline reset

int fn_801D76CC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801D770C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_801D774C(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (((int)arg0 + 0x24) != 0) {
            if (((int)arg0 + 0x24) != 0) {
                *(int *)((char *)arg0 + 0x24) = 0;
                *(int *)((char *)arg0 + 0x28) = 0;
                *(int *)((char *)arg0 + 0x2C) = 0;
            }
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

char *fn_801D77AC(void) {
    return lbl_803388F0;
}

int fn_801D77B8(int arg0) {
    return ((int *)arg0)[2];
}

int fn_801D77C0(int arg0) {
    if (((int *)arg0)[2] == 0) {
        return arg0;
    }
    ((int *)arg0)[2] = 1;
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_801D77D8(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset
void fn_801D77E8(void) {
}

int fn_801D7924(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[10] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

#pragma push
#pragma scheduling invalid_target
int fn_801D796C(void *arg0, int *arg1, int arg2) {
    int *entry;
    int idx;

    entry = arg1;
    for (idx = 0; idx < arg2; entry++, idx++) {
        if (((int *)arg0)[1] != 0) {
            if (fn_801D9B28(((int *)arg0)[1], *entry) != 0) {
                return 1;
            }
        } else if (((int *)arg0)[2] == *entry) {
            return 1;
        }
    }
    return 0;
}
#pragma pop

void *fn_801D7C6C(void) {
    return lbl_8033890C;
}

int fn_801D7C78(int arg0) {
    return ((int *)arg0)[10];
}

extern int fn_802E317C(const char *, ...);
extern char lbl_80338F50[];
#pragma push
#pragma scheduling invalid_target
int fn_801D7C80(void *arg0, int arg1) {
    int *ptr = (int *)arg0;
    float *fptr = (float *)arg0;

    if (ptr[0xA] == 1) {
        ptr[7] = lbl_8055E3C4;
        switch (arg1) {
        case 0:
            fptr[8] = fptr[5];
            fptr[9] = fptr[6];
            break;
        case 1:
            fptr[8] = fptr[6];
            fptr[9] = fptr[5];
            break;
        default:
            fn_802E317C(lbl_80338F50, arg1);
            break;
        }
        ptr[0xA] = 2;
        return 1;
    }
    return 0;
}
#pragma pop

void fn_801D7E3C(int arg0) {
    if (((int *)arg0)[10] != 0) {
        ((int *)arg0)[10] = 1;
    }
}

extern void fn_801D9AB8(void *, float);
extern void fn_80178DBC(int, float);
void fn_801D7E54(void *arg0) {
    void *temp;
    float f;
    if (*(int *)((char *)arg0 + 0x28) != 0) {
        if (*(int *)((char *)arg0 + 0x10) == 0) {
            temp = *(void **)((char *)arg0 + 4);
            f = *(float *)((char *)arg0 + 0x14);
            if (temp != 0) fn_801D9AB8(temp, f);
            else fn_80178DBC(*(int *)((char *)arg0 + 8), f);
        }
        *(int *)((char *)arg0 + 0x28) = 1;
    }
}

#pragma cplusplus on
extern "C" void fn_80128658(int);
void *fn_801D7EC0(void *arg0, int arg1) {
    int value;
    void **vtable;
    register void *child;

    if (arg0 == 0) goto done;
    child = *(void **)((unsigned char *)arg0 + 0x2C);
    *(void **)arg0 = lbl_80338CB0;
    *(int *)((unsigned char *)arg0 + 0x40) = 0;
    if (child != 0) {
        if (child != 0) {
            vtable = *(void ***)child;
            ((void (*)(void *, int))vtable[2])(child, 1);
        }
    }
    value = *(int *)((unsigned char *)arg0 + 0x3C);
    if (value != 0) fn_80128658(value);
    if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
done:
    return arg0;
}
#pragma cplusplus reset
int fn_801D7F5C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_801D7F9C(void *arg0, void **arg1) {
    extern void fn_802E30C8(char *); extern int fn_801399FC(void);
    extern char lbl_80338460, lbl_8055AD20, lbl_8055AD28, lbl_8055AD30, lbl_8055ACB8;
    extern float lbl_80562ADC, lbl_80562B0C;
    void **vt; int ok,n,i; unsigned char *src,*dst,c; float v;
    vt=*(void ***)arg1;
    ok=((int (*)(void *,char *))vt[3])(arg1,&lbl_8055AD20);
    if(!ok){fn_802E30C8(&lbl_80338460+0xB24);return 0;}
    src=((unsigned char *(*)(void *,char *))vt[5])(arg1,&lbl_8055AD20);
    dst=(unsigned char *)arg0+0x18; n=0x14;
    while(n>0){c=*src++;*dst++=c;if((signed char)c==0)break;n--;}
    if(n==0)dst[-1]=0;
    src=((unsigned char *(*)(void *,char *,char *))vt[6])(arg1,&lbl_8055AD28,&lbl_8055AD30);
    dst=(unsigned char *)arg0+4;n=0x14;
    while(n>0){c=*src++;*dst++=c;if((signed char)c==0)break;n--;}
    if(n==0)dst[-1]=0;
    if(((int (*)(void *,char *))vt[23])(arg1,&lbl_80338460+0xB64)==0)
        *(int *)((char *)arg0+0x3c)=0;
    else *(int *)((char *)arg0+0x3c)=fn_801399FC();
    v=((float (*)(void *,char *,float))vt[10])(arg1,&lbl_8055ACB8,lbl_80562ADC);
    *(int *)((char *)arg0+0x38)=0; *(int *)((char *)arg0+0x2c)=0;
    *(int *)((char *)arg0+0x40)=1; *(int *)((char *)arg0+0x30)=(int)(lbl_80562B0C*v);
    fn_802E30C8(&lbl_80338460+0xB70); return 1;
}

extern char lbl_80338928[];
void *fn_801D8148(void) {
    return lbl_80338928;
}

int fn_801D8154(void *arg0) {
    return *(int *)((char *)arg0 + 0x40);
}

void fn_801D832C(void *arg0) {
    if (*(int *)((char *)arg0 + 0x40) != 0) {
        *(int *)((char *)arg0 + 0x40) = 1;
    }
}

#pragma cplusplus on
extern "C" void fn_801D8344(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    if (*(int *)((char *)arg0 + 0x40) != 0) {
        Dummy *p = *(Dummy **)((char *)arg0 + 0x2C);
        if (p != 0) {
            p->v5();
        }
        *(int *)((char *)arg0 + 0x40) = 1;
    }
}
#pragma cplusplus reset

int fn_801D839C(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x18)) >> 5;
}

#pragma cplusplus on
extern "C" void fn_801D83AC(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

int fn_801D83BC(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x30)) >> 5;
}

#pragma cplusplus on
extern "C" void fn_801D83CC(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

int fn_801D83DC(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void *fn_801D8504(void) {
    return lbl_80339038;
}

int fn_801D8510(void *arg0) {
    return *(int *)((char *)arg0 + 0x4);
}

int fn_801D8518(int arg0) {
    if (((int *)arg0)[1] == 1) {
        ((int *)arg0)[4] = lbl_8055E3C4;
        ((int *)arg0)[1] = 2;
        return 1;
    }
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801796CC(int, void *, int);
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D8544(void *arg0) {
    int sp8;
    int temp_r31;

    temp_r31 = lbl_8055E3C4 - (*(int *)((char *)arg0 + 0x10) + *(int *)((char *)arg0 + 0xC));
    if (*(int *)((char *)arg0 + 4) == 2 && temp_r31 > 0) {
        sp8 = *(int *)((char *)arg0 + 0x14);
        fn_801796CC(0xB, &sp8, 4);
        if (temp_r31 >= *(int *)((char *)arg0 + 8)) {
            *(int *)((char *)arg0 + 4) = 3;
        }
    }
}
#pragma pop
#pragma cplusplus reset
extern "C" void fn_801D85C8(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

void fn_801D85D8(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D85F0(void *arg0) {
    return (unsigned int)__cntlzw(*(unsigned char *)((char *)arg0 + 0x14)) >> 5;
}

void fn_801D8600(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D8618(void) {
    return 0;
}

void fn_801D8620(void) {

}

#pragma cplusplus on
extern "C" void fn_801D8624(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}

extern "C" int fn_801D8634(void *out, void *obj) {
    extern float lbl_80562ADC;
    extern char lbl_8055ACB8;
    extern char lbl_8055ACB0;
    extern char lbl_803385D0[];
    extern char lbl_80339050[];
    extern int fn_801D04D0(void);
    extern void fn_801D0590(void *);
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(void *);
        virtual void v4();
        virtual int v5(void *);
        virtual void v6();
        virtual float v7(void *);
        virtual float v8(void *, float);
    };
    Dummy *thing = (Dummy *)obj;
    *(float *)((char *)out + 0xC) = thing->v8(&lbl_8055ACB8, lbl_80562ADC);
    *(float *)((char *)out + 0x14) = thing->v7(&lbl_8055ACB0);
    *(int *)((char *)out + 8) = thing->v5(lbl_803385D0);
    thing->v3(lbl_80339050);
    *(int *)((char *)out + 0x1C) = fn_801D04D0();
    if (out != 0) fn_801D0590((char *)out + 4);
    *(int *)((char *)out + 0x18) = 1;
    *(float *)((char *)out + 0x10) = lbl_80562ADC;
    return 1;
}

#pragma cplusplus reset

void fn_801D8710(int arg0) {
    if (arg0 != 0) {
        arg0 += 4;
    }
    fn_801D05B4(arg0);
}

void *fn_801D8720(void) {
    return lbl_8033905C;
}

int fn_801D872C(int arg0) {
    return ((int *)arg0)[6];
}

int fn_801D8734(void) {
    return 0;
}

int fn_801D873C(int arg0) {
    ((int *)arg0)[6] = 2;
    ((int *)arg0)[8] = 0;
    *(float *)((char *)arg0 + 0x10) = lbl_8055E3C8;
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801D875C(void *arg0) {
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void first(int); virtual void v6(); virtual void second_pad();
        virtual void second(int);
    };
    int count, offset;
    float time;
    Dummy *item;
    char *entry;
    if (*(int *)((char *)arg0 + 0x18) != 2) return;
    time = lbl_8055E3C8;
    if (*(int *)((char *)arg0 + 0x20) == 0) {
        if (!(time - *(float *)((char *)arg0 + 0x10) > *(float *)((char *)arg0 + 0xC))) return;
        count = 0; offset = 0;
        goto first_test;
first_loop:
        entry = (char *)*(int *)((char *)arg0 + 0x24) + offset;
        item = *(Dummy **)entry;
        item->first(*(int *)((char *)arg0 + 0x1C));
        item = *(Dummy **)entry;
        item->second(*(int *)(entry + 8));
        offset += 0xC; count += 1;
first_test:
        if (count < *(int *)((char *)arg0 + 0x28)) goto first_loop;
        *(int *)((char *)arg0 + 0x20) = 1;
    } else {
        if (!(time - *(float *)((char *)arg0 + 0x10) - *(float *)((char *)arg0 + 0xC) > *(float *)((char *)arg0 + 0x14))) return;
        count = 0; offset = 0;
        goto second_test;
second_loop:
        entry = (char *)*(int *)((char *)arg0 + 0x24) + offset;
        item = *(Dummy **)entry;
        item->first(*(int *)(entry + 4));
        item = *(Dummy **)entry;
        item->second(-1);
        offset += 0xC; count += 1;
second_test:
        if (count < *(int *)((char *)arg0 + 0x28)) goto second_loop;
        *(int *)((char *)arg0 + 0x18) = 1;
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801D88AC(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D88BC(void *arg0) {
    struct Entry {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void dispatch(int);
    };
    int i;
    *(int *)((char *)arg0 + 0x18) = 1;
    for (i = 0; i < *(int *)((char *)arg0 + 0x28); i++) {
        Entry *entry = *(Entry **)((char *)*(void **)((char *)arg0 + 0x24) + i * 0xC);
        entry->dispatch(-1);
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset

void fn_801D8938(void) {

}

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801D893C(void *arg0, unsigned int arg1) {
    int count;
    int offset;
    unsigned char *item;
    unsigned char *base;
    int i;

    i = 0;
    offset = 0;
    goto test;
loop:
    base = *(unsigned char **)((unsigned char *)arg0 + 0x24);
    item = base + offset;
    if (*(unsigned int *)item == arg1) {
        if (i >= 0) {
            count = *(volatile int *)((unsigned char *)arg0 + 0x28);
            if (i < count) {
                int last = count - 1;
                if (i != last) {
                    *(unsigned int *)item = *(unsigned int *)(base + last * 0xC);
                    *(unsigned int *)(item + 4) = *(unsigned int *)(base + last * 0xC + 4);
                    *(unsigned int *)(item + 8) = *(unsigned int *)(base + last * 0xC + 8);
                }
                *(int *)((unsigned char *)arg0 + 0x28) = *(int *)((unsigned char *)arg0 + 0x28) - 1;
            }
        }
    }
    offset += 0xC;
    i++;
test:
    if (i < *(int *)((unsigned char *)arg0 + 0x28)) {
        goto loop;
    }
}
#pragma pop
#pragma cplusplus reset

void fn_801D89C0(void *arg0, void *arg1) {
    void *object;
    int first;
    int second;
    int count;
    int records;
    int record;

    object = ((void *(*)(void *))(*(void ***)arg1)[1])(arg1);
    if (object == 0) return;
    if (((int (*)(void *, char *, int))(*(void ***)object)[8])(object, lbl_803385D0, -1) != *(int *)((char *)arg0 + 8)) return;
    first = ((int (*)(void *))(*(void ***)arg1)[8])(arg1);
    second = ((int (*)(void *))(*(void ***)arg1)[9])(arg1);
    count = *(int *)((char *)arg0 + 0x28);
    records = *(int *)((char *)arg0 + 0x24);
    record = records + count * 12;
    *(int *)((char *)arg0 + 0x28) = count + 1;
    *(void **)record = arg1;
    *(int *)(record + 4) = first;
    *(int *)(record + 8) = second;
    ((void (*)(void *, int, int, int, int))(*(void ***)arg1)[10])(arg1, -1, record, count + 1, records);
}

int fn_801D8AA4(void *arg0) {
    extern float lbl_80562ADC;
    return *(float *)((char *)arg0 + 0x30) < lbl_80562ADC;
}

#pragma cplusplus on
extern "C" void fn_801D8ABC(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

void fn_801D8B50(void) {
}

void fn_801D8B54(void) {
}

void fn_801D8B58(void) {
}

void fn_801D8B5C(void) {

}

void fn_801D8C0C(void *arg0) {
    *(int *)((char *)arg0 + 0x18) = -1;
}

void fn_801D8C18(void) {
}

void fn_801D8C94(void) {
}

void *fn_801D8C98(void) {
    return lbl_8033907C;
}

int fn_801D8CA4(void *arg0) {
    return ((int *)arg0)[1];
}

#pragma cplusplus on
extern "C" void fn_801D8DA0(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

void fn_801D8DB0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}

int fn_801D8DC8(int arg0, int arg1) {
    if (arg0 != 0) {
        ((int *)arg0)[1] = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

char *fn_801D8EF0(void) {
    return lbl_803389B8;
}

int fn_801D8EFC(void *arg0) {
    return ((int *)arg0)[1];
}

int fn_801D8F04(void *arg0) {
    if (*(int *)((char *)arg0 + 4) == 1) {
        *(int *)((char *)arg0 + 4) = 2;
        *(float *)((char *)arg0 + 0x20) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801D8FD0(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };
    ((Dummy *)arg0)->v11();
}
#pragma cplusplus reset

void fn_801D8FE0(int arg0) {
    if (((int *)arg0)[1] != 0) {
        ((int *)arg0)[1] = 1;
    }
}
extern char lbl_803385D0[];
extern char lbl_803385D0[];
