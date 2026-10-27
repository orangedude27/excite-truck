// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804348E8[4];
extern double fn_8002EFB4(void);
extern void fn_801476D8(int, int);
extern void fn_80128668(void*);
extern void* lbl_8055EA04;
extern float lbl_8055AE30;
extern float lbl_80562C1C;
extern float lbl_80562C3C;
extern float lbl_80562C40;
extern float lbl_80562C44;
extern float lbl_80562C48;
extern int lbl_8055E4D0;
extern float PSVECMag(void*);
extern char lbl_8055AE2C;
void* fn_801DF678(void* arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int*)arg0 = 0;
            *((int*)arg0 + 1) = 0;
            *((int*)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_801DF6D0(void* arg0) {
    int zero = 0;
    void* ptr = &lbl_8055AE2C;
    *(int*)((char*)arg0 + 0x18) = zero;
    *(void**)((char*)arg0 + 4) = ptr;
    *(void**)((char*)arg0 + 8) = ptr;
    *(char*)arg0 = zero;
    *(int*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 0x10) = zero;
    *(int*)((char*)arg0 + 0x14) = -1;
}
#pragma scheduling on
extern void *fn_801284F8(int, void *);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int fn_80145E70(void *);
extern void fn_801D0DDC(void *);
extern int fn_80207848(void *, int);
extern int fn_802CAC28(void *, int);
extern int stricmp(const char *, const char *);
extern char lbl_803381C0[], lbl_803395D8[], lbl_80339744[];
extern char lbl_8055AE44[], lbl_8055AE4C[];
extern void *lbl_8055EA04;
void fn_801DF6FC(void) {
 void *obj,*iter,*entry; int i,j,n; char *p,*q; float f,keep;
 obj=fn_801284F8(0x1B4,lbl_803395D8);
 if(obj){
  *(void**)obj=lbl_803381C0; fn_801D0DDC(lbl_803381C0);
  *(void**)obj=lbl_80339744; lbl_8055EA04=obj;
  *(int*)((char*)obj+0xE4)=fn_80145E70(lbl_803395D8+0xC);
  *(int*)((char*)obj+0xF0)=fn_802CAC28(lbl_803395D8+0x1C,0);
  *(int*)((char*)obj+0xE8)=fn_802CAC28(lbl_803395D8+0x28,0);
  *(int*)((char*)obj+0xEC)=fn_802CAC28(lbl_803395D8+0x34,0);
  *(int*)((char*)obj+0xF4)=fn_802CAC28(lbl_803395D8+0x40,0);
  *(int*)((char*)obj+0xF8)=fn_80207848(lbl_803395D8+0x50,1);
  for(i=0;i<3;i++) *(int*)((char*)obj+0xFC+i*4)=fn_80207848(lbl_803395D8+0x60,1);
  *(int*)((char*)obj+0x108)=0;
  *(int*)((char*)obj+0x10C)=fn_80207848(lbl_803395D8+0x70,1);
  *(int*)((char*)obj+0x1B0)=0;
  iter=fn_80131808(lbl_803395D8+0x80);
  if(iter){
   entry=((void*(*)(void*,void*))(*(void***)iter)[2])(iter,lbl_803395D8+0x8C);
   j=0;
   while((entry=((void*(*)(void*,int))(*(void***)entry)[0x18])(entry,j))!=0){
    p=((char*(*)(void*))(*(void***)entry)[2])(entry);
    if(stricmp(p,lbl_8055AE44)==0){
     keep=((float(*)(void*,const char*))(*(void***)entry)[9])(entry,lbl_8055AE44);
     p=((char*(*)(void*,const char*))(*(void***)entry)[5])(entry,lbl_8055AE4C);
     f=((float(*)(void*,const char*))(*(void***)entry)[9])(entry,lbl_803395D8+0x9C);
     n=*(int*)((char*)obj+0x1B0); *(int*)((char*)obj+0x1B0)=n+1;
     q=(char*)obj+n*0x28+0x114;
     *(float*)(q-4)=f;
     for(i=0;i<0x20;i++){char c=*p++;*q++=c;if(c==0)break;}
     *(float*)(q+0x1C)=keep;
    }
    j++;
   }
   fn_80131818(iter);
  }
 }
}

void fn_801476D8(int, int);
void fn_801DFE44(int a1, int a2) { ((void (*)(int, int, int))fn_801476D8)(a1, -1, a2); }

#pragma cplusplus on
struct Dummy_801DFE50 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
};
extern "C" void fn_801DFE50(void *arg0, int arg1, int arg2) {
    struct Dummy_801DFE50_Local {
        virtual void d0();
        virtual void d1();
        virtual void* d2();
    };
    void *result = ((Dummy_801DFE50_Local *)arg0)->d2();
    ((void (*)(void *, int, int))fn_801476D8)(result, -1, arg2);
}
#pragma cplusplus reset

float fn_801DFE94(void) {
    return (float)fn_8002EFB4();
}

typedef void (*Fn)(void *);
#pragma cplusplus on
extern "C" void fn_801DFEB8(void *arg0, int arg1, int arg2, int arg3) {
    struct Dummy_801DFEB8_Local {
        virtual void d0();
        virtual void d1();
        virtual void* d2();
    };
    void *result = ((Dummy_801DFEB8_Local *)arg0)->d2();
    ((void (*)(void *, int, int))fn_801476D8)(result, arg2, arg3);
}
#pragma cplusplus reset
int fn_801DFF08(int index) { return lbl_804348E8[index]; }

void fn_801DFF1C(int arg0) {
    int index = arg0;
    char* entry = (char*)lbl_8055EA04 + index * 0x1C;
    void* vec = ((void**)lbl_804348E8)[index];
    *(float*)(entry + 4) = lbl_80562C3C;
    *(float*)(entry + 0x10) = lbl_80562C1C;
    *(float*)(entry + 8) = lbl_80562C40;
    *(char*)(entry + 0xC) = 0;
    *(float*)(entry + 0x14) = lbl_80562C44 * (lbl_8055AE30 * PSVECMag((char*)vec + 0x118)) / lbl_80562C48;
    *(char*)(entry + 0x18) = 0;
    *(int*)(entry + 0x1C) = -1;
}

#pragma cplusplus on
extern "C" void fn_801D0DFC(void *);
extern "C" void fn_802CAC54(int);
extern "C" void *fn_801E0150(void *arg0, int arg1) {
    struct LocalObj {
        virtual void d0(int);
    };
    LocalObj *object;
    char *p;
    int i;
    void *result = arg0;

    if (arg0 != 0) {
        object = *(LocalObj **)((char *)arg0 + 0x10C);
        *(void **)arg0 = lbl_80339744;
        if (object != 0) {
            if (object != 0)
                object->d0(1);
        }

        p = (char *)arg0;
        i = 0;
        do {
            object = *(LocalObj **)(p + 0xFC);
            if (object != 0) {
                if (object != 0)
                    object->d0(1);
            }
            ++i;
            p += 4;
        } while (i < 3);

        object = *(LocalObj **)((char *)arg0 + 0xF8);
        if (object != 0) {
            if (object != 0)
                object->d0(1);
        }

        fn_802CAC54(*(int *)((char *)arg0 + 0xF4));
        fn_802CAC54(*(int *)((char *)arg0 + 0xEC));
        fn_802CAC54(*(int *)((char *)arg0 + 0xE8));
        fn_802CAC54(*(int *)((char *)arg0 + 0xF0));
        lbl_8055EA04 = 0;

        object = *(LocalObj **)((char *)arg0 + 0xE4);
        if (object != 0)
            object->d0(1);

        if (arg0 != 0) {
            *(void **)arg0 = lbl_803381C0;
            fn_801D0DFC(arg0);
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return result;
}
#pragma cplusplus reset

void fn_801E02A8(void) {

}

void fn_801E02AC(void) {

}

void fn_801E02B0(void* arg0) {
    float b;
    float a;
    char* entry;
    int i;
    a = lbl_80562C40;
    b = lbl_80562C1C;
    entry = (char*)arg0 + 4;
    i = 0;
    while (i < lbl_8055E4D0) {
        *(char*)(entry + 8) = 0;
        i++;
        *(float*)(entry + 4) = a;
        *(float*)(entry + 0xC) = b;
        *(float*)(entry + 0x10) = b;
        *(char*)(entry + 0x14) = 0;
        *(int*)(entry + 0x18) = -1;
        *(float*)entry = b;
        entry += 0x1C;
    }
}

