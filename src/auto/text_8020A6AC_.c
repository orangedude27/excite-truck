// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E317C(const char *, ...);
extern const char lbl_8033C510[];
extern void fn_802E61E4(float);
extern float fn_80209028(void), fn_802091CC(void);
extern int fn_802090CC(void), fn_802E2C20(void);
extern void fn_802E625C(int);
extern void fn_802E61EC(void *, float), fn_802E620C(void *, float), fn_802E6234(void *, float), fn_802E6238(void *, float), fn_802E623C(void *, float), fn_802E622C(void *, float), fn_802E6240(void *, int);
extern float lbl_8055B590, lbl_8055B594, lbl_80558DC4, lbl_805632B8;
extern int lbl_8055EDF8;
extern unsigned int lbl_8055EE00;

extern void fn_802E6264(void);
extern void fn_802E5D5C(void *);
extern void fn_8020B2BC(void *, int, int);
extern int lbl_8055EE0C;
extern void *lbl_8055EE10;
extern char lbl_8033C35C[];
extern char lbl_8033C338[];
extern int stricmp(const char *, const char *);
extern char lbl_8033C368[];
extern char lbl_804892D0[];
extern int fn_801284F8(int, void *);
extern void *fn_8012A13C(void *, int, int);
extern int fn_8012A2D8(void *);
extern int fn_8012A364(void *, void *);
extern void *fn_8012850C(unsigned int, void *);
extern void *memset(void *, int, unsigned int);
  extern void fn_802E6B04(void);
  extern char lbl_8033C388[];
  extern void fn_802E6B34(void);
  typedef struct { void **vtable; } Unk8012A570;
    extern void fn_8020A860();
  extern int fn_80208E90(int);
  extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;

  extern void *lbl_8055EE04;
extern char lbl_8033C37C[];
extern void *lbl_8055EE08;
extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
extern char lbl_8033C458[];
typedef struct { char *name; int state; } UnkStruct_8020A860;
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_8020A6AC(void *arg0) {
    char *entry = lbl_804892D0;
    int i = 0;
    while (i < (int)lbl_8055EE08) {
        if (stricmp((const char *)arg0, entry) == 0)
            return entry;
        entry += 0x24;
        i++;
    }
    return lbl_8033C338;
}
#pragma scheduling on
#pragma dont_inline reset

void fn_8020A72C(void) {
    void *object = (void *)fn_801284F8(0xC, lbl_8033C35C);
    if (object != 0)
        object = ((void *(*)(void *))fn_8020A860)(object);
    ((int (*)(void *, int))fn_80208E90)(object, 0);
}
#pragma scheduling on
void* fn_8020A76C(void) {
    return lbl_8055EE08;
}

void *fn_8020A774(int arg0) { return lbl_804892D0 + arg0 * 0x24; }

void fn_8020A788(void) {
    if (lbl_8055EE0C == 0) {
        if (fn_801284F8(0x20, lbl_8033C368) != 0)
            lbl_8055EE10 = fn_8012A13C(lbl_8033C368, 0x200, 0x54);
    }
    if (fn_8012A2D8(lbl_8055EE10) != 0) {
        int count;
        count = lbl_8055EE0C;
        lbl_8055EE0C = count + 1;
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020A800(void *arg0) {
    class Obj {
    public:
        virtual void f(int);
    };
    fn_8012A364(lbl_8055EE10, arg0);
    if (--lbl_8055EE0C == 0) {
        if (lbl_8055EE10 != 0)
            ((Obj *)lbl_8055EE10)->f(1);
        lbl_8055EE10 = 0;
    }
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling invalid_target
void fn_8020A860(UnkStruct_8020A860 *arg0) {
    arg0->name = lbl_8033C458;
    arg0->state = 0;
}

#pragma scheduling invalid_target
int fn_8020A878(void *arg0) {
    void *buffer;
    if (fn_80019B60() != 0)
        lbl_8055B598 = lbl_805632B0;
    else
        lbl_8055B598 = lbl_805632B4;
    lbl_8055EE04 = arg0;
    buffer = fn_8012850C(0x800, lbl_8033C37C);
    *(void **)((char *)arg0 + 4) = buffer;
    memset(buffer, 0, 0x800);
    fn_802E6B04();
    return 1;
}

void fn_8020A8E8(void *arg0) {
    int *list = *(int **)((char *)arg0 + 4);
    int i = 0;
    while (i < 0x200) {
        if (list[i] != 0) {
            fn_802E317C(lbl_8033C388);
        }
        i++;
    }
    fn_80128670(list);
    *(int **)((char *)arg0 + 4) = 0;
    *(void **)lbl_8055EE04 = 0;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020A978(void *arg0) {
    class Dispatch {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void clear();
        virtual int state();
    };
    register int offset = 0;
    register int count = 0;
    Dispatch *object;

    do {
        object = *(Dispatch **)((char *)*(void **)((char *)arg0 + 4) + offset);
        if (object != 0) {
            if (object->state() != 3) {
                object = *(Dispatch **)((char *)*(void **)((char *)arg0 + 4) + offset);
                object->clear();
            }
        }
        count++;
        offset += 4;
    } while (count < 0x200);
    fn_802E6264();
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling on

extern void fn_802E59BC(void *);
extern void fn_802E5950(int, int);
extern void fn_802E6138(void);
extern void fn_802E61D8(void *);
void fn_8020AA0C(void *arg0) {
    int value = *(int *)((char *)arg0 + 8);
    if (value != 0) {
        fn_802E61D8((void *)value);
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0) {
            fn_802E61D8((void *)value);
        }
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 0xC) = 0;
        }
        value = *(int *)((char *)arg0 + 8);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 8) = 0;
        }
    }
    *(int *)((char *)arg0 + 4) = 3;
    *((unsigned char *)arg0 + 0x3E) = 0;
}

int fn_8020AA98(void *arg0) { volatile int *p = (volatile int *)((char *)arg0 + 4); if (*p == 1 && *((unsigned char *)arg0 + 0x3E) != 0) return 2; return *p; }

extern const char lbl_8033C3B4[];
extern const char lbl_8033C3C0[];
#include <macros.h>
DECL_SECTION(".sdata") extern const char lbl_8055B5A0[];
DECL_SECTION(".sdata") extern const char lbl_8055B5A8[];
DECL_SECTION(".sdata") extern const char lbl_8055B5B0[];
extern float lbl_805632B4;
extern void *fn_80131808(const char *);
extern void fn_80131818(void *);
extern void fn_802E58B8(int);
extern int strcmp(const char *, const char *);
#pragma push
#pragma cplusplus on
extern "C" void fn_8020AAC0(int unused, int arg1) {
    struct List {
        virtual void dummy0();
        virtual void *getAt(int);
    };
    struct Entry {
        virtual const char *getName();
        virtual void dummy1();
        virtual void dummy2();
        virtual const char *getString(const char *, int);
        virtual void dummy4();
        virtual void dummy5();
        virtual void dummy6();
        virtual void dummy7();
        virtual float getValue(const char *, float);
    };
    char *base;
    List *list = (List *)fn_80131808(lbl_8033C3B4);
    if (list != 0) {
        base = lbl_804892D0;
        Entry *item;
        int index = 0;
        while ((item = (Entry *)list->getAt(index)) != 0) {
            const char *name = item->getName();
            if (strcmp(name, lbl_8055B5A0) == 0) {
                int n = (int)lbl_8055EE08;
                char *record = base + n * 0x24;
                const char *s;
                lbl_8055EE08 = (void *)(n + 1);
                s = item->getString(lbl_8055B5A8, n);
                {
                    int left = 0x20;
                    char *dest = record;
                    goto copy_check;
copy_loop:
                    if (--left > 0)
                        goto copy_check;
                    dest[-1] = 0;
                    goto copy_done;
copy_check:
                    {
                        unsigned char c = *s++;
                        *dest++ = c;
                        if ((signed char)c != 0)
                            goto copy_loop;
                    }
copy_done:
                    ;
                }
                *((float *)(record + 0x20)) = item->getValue(lbl_8055B5B0, lbl_805632B4);
            }
            ++index;
        }
        fn_80131818(list);
    } else {
        fn_802E317C(lbl_8033C3C0);
    }
    fn_802E58B8(arg1);
}
#pragma cplusplus reset
#pragma pop
extern void fn_802E5950(int, int); void fn_8020AC0C(int arg0, int arg1, int arg2) { fn_802E5950(arg1, arg2); }

extern void fn_802E59BC(void *); void fn_8020AC18(void *arg0, int arg1) { fn_802E59BC((void *)arg1); }

extern void fn_802E5A54(void);
void fn_8020AC20(void) {
    lbl_8055EE08 = 0;
    fn_802E5A54();
}

#pragma push
#pragma processor 750
void fn_8020AC2C(void *arg0) {
 int i,j,mode,now; void *p,*handle; float volume,x,v,high,low;
 lbl_8055B590=fn_80209028();
 lbl_8055B594=fn_802091CC();
 lbl_8055EDF8++;
 now=fn_802E2C20();
 lbl_8055EE00=now-(*(int *)((char *)(arg0)+(8)));
 if(lbl_8055EE00>200U) lbl_8055EE00=200;
 (*(int *)((char *)(arg0)+(8)))=now;
 high=lbl_805632B4; low=lbl_805632B0;
 for(i=0;i<512;i++) {
 p=(*(void ** *)((char *)(arg0)+(4)))[i];
 if(p) {
 mode=1;
 switch(fn_802090CC()) {case 0: mode=0;break;case 1:break;case 2:mode=2;break;}
 fn_802E625C(mode);
 handle=(*(void * *)((char *)(p)+(8)));
 if(handle) {
 v=(*(float *)((char *)(p)+(0x1c)))*(*(float *)((char *)((*(void * *)((char *)(p)+(0x18))))+(0x20)));
 if((*(unsigned char *)((char *)(p)+(0x3e)))) volume=lbl_805632B0;
 else {if(!(*(unsigned char *)((char *)(p)+(0x3c)))) v*=lbl_8055B590;volume=lbl_8055B598*v;}
 if((*(void * *)((char *)(p)+(0xc)))) {
 x=high+-(*(float *)((char *)(p)+(0x20)));
 if(high<x)x=high;
 x=x>low?x:low;
 ((void (*)(void *,float))fn_802E61E4)(handle,volume*x);
 fn_802E61EC((*(void * *)((char *)(p)+(8))),lbl_805632B8);
 x=high+(*(float *)((char *)(p)+(0x20)));
 if(high<x)x=high;
 x=x>low?x:low;
 ((void (*)(void *,float))fn_802E61E4)((*(void * *)((char *)(p)+(0xc))),volume*x);
 fn_802E61EC((*(void * *)((char *)(p)+(0xc))),lbl_805632B4);
 }else{
 ((void (*)(void *,float))fn_802E61E4)(handle,volume);
 fn_802E61EC((*(void * *)((char *)(p)+(8))),(*(float *)((char *)(p)+(0x20))));
 }
 for(j=0;j<2;j++){
 if(j==0)handle=(*(void * *)((char *)(p)+(8)));else handle=(*(void * *)((char *)(p)+(0xc)));
 if(handle) {
 fn_802E620C(handle,(*(float *)((char *)(p)+(0x28))));
 fn_802E6234(handle,(*(float *)((char *)(p)+(0x2c))));
 fn_802E6238(handle,(*(float *)((char *)(p)+(0x30))));
 fn_802E623C(handle,(*(float *)((char *)(p)+(0x34))));
 fn_802E622C(handle,(*(float *)((char *)(p)+(0x24))));
 fn_802E6240(handle,(*(int *)((char *)(p)+(0x38))));
 }}
 }
 if((*(int *)((char *)(p)+(4)))==1) {
 (*(int *)((char *)(p)+(0x44)))++;
 if(!(*(unsigned char *)((char *)(p)+(0x3e))) && !((float)__fabs((*(float *)((char *)(p)+(0x24))))<=lbl_80558DC4)) (*(unsigned int *)((char *)(p)+(0x50)))+=lbl_8055EE00;
 if(!(*(unsigned char *)((char *)(p)+(0x3d))) && (*(unsigned int *)((char *)(p)+(0x50)))>(*(unsigned int *)((char *)(p)+(0x4c))))
 ((void (*)(void *))(*(void ***)p)[8])(p);
 }else (*(unsigned int *)((char *)(p)+(0x50)))=0;
 }
 }
 fn_802E6264();
}

extern char lbl_8033C3F4[];
#pragma scheduling invalid_target
void *fn_8020B1C8(void *arg0, int arg1) {
    void *old;
    int value;

    if (arg0 != 0) {
        old = *(void **)((char *)arg0 + 8);
        *(void **)arg0 = lbl_8033C3F4;
        if (old != 0)
            fn_802E61D8(old);
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0)
            fn_802E61D8((void *)value);
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 0xC) = 0;
        }
        value = *(int *)((char *)arg0 + 8);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 8) = 0;
        }
        value = *(int *)((char *)arg0 + 0x14);
        if (value != 0)
            fn_802E5D5C((void *)value);
        value = *(int *)((char *)arg0 + 0x10);
        if (value != 0) {
            fn_802E5D5C((void *)value);
            ((void (*)(void *, int, int))fn_8020B2BC)(lbl_8055EE04, (int)arg0, *(int *)((char *)arg0 + 0x40));
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_8020A800)(arg0);
    }
    return arg0;
}
#pragma scheduling on

#pragma pop

int fn_8020B2A8(void *arg0) {
    return *(int *)((char *)arg0 + 0x10) != 0;
}

void fn_8020B2BC(void *arg0, int arg1, int arg2) {
    int *ptr = *(int **)((unsigned char *)arg0 + 4);
    ptr[arg2] = 0;
}

void fn_8020B2D0(void) {

}

extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
int fn_8020B2D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_8020B314(void) {
    return lbl_8033C520;
}

void fn_8020B320(void) {
    volatile unsigned char *p = lbl_80489BD0;
    p[0] = 0;
    *(volatile int *)(p + 4) = 0;
    *(volatile int *)(p + 8) = 0x20;
}

void fn_8020B340(void) {
    fn_802E5824();
}

void fn_8020B344(void) {
    fn_802E5828();
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020B348(void *arg0) {
    class Obj {
    public:
        virtual void f(int);
    };
    if (arg0 == 0) return;
    ((Obj *)arg0)->f(1);
}
#pragma cplusplus reset
#pragma pop
extern void *fn_802E5AE8(void *);
extern void fn_802E5D5C(void *);
#pragma dont_inline fn_8020A6AC
extern void *fn_8020A6AC(void *);
#pragma dont_inline fn_8020A6AC
extern void fn_802E30C8(const char *, ...);
extern const char lbl_8033C4F0[];
int fn_8020B874(void *object, void *name) {
    int result = 0;
    void *created = fn_802E5AE8(name);
    if (created != 0) {
        fn_802E5D5C(*(void **)((char *)object + 0x10));
        *(void **)((char *)object + 0x10) = created;
        *(void **)((char *)object + 0x18) = fn_8020A6AC(name);
        result = 1;
    } else {
        fn_802E30C8(lbl_8033C4F0, name);
    }
    return result;
}

extern void fn_802E61E4(float);
extern int lbl_8055EDFC;
extern float lbl_805632B0;
void fn_8020B908(void *arg0) {
    if (*((unsigned char *)arg0 + 0x3E) == 0 && *(int *)((char *)arg0 + 4) != 3) {
        *((unsigned char *)arg0 + 0x3E) = 1;
        lbl_8055EDFC++;
        if (*(void **)((char *)arg0 + 8) != 0) {
            fn_802E61D8(*(void **)((char *)arg0 + 8));
            if (*(void **)((char *)arg0 + 0xC) != 0)
                fn_802E61D8(*(void **)((char *)arg0 + 0xC));
            if (*(void **)((char *)arg0 + 0xC) != 0) {
                ((void (*)(void *))fn_802E6138)(*(void **)((char *)arg0 + 0xC));
                *(void **)((char *)arg0 + 0xC) = 0;
            }
            if (*(void **)((char *)arg0 + 8) != 0) {
                ((void (*)(void *))fn_802E6138)(*(void **)((char *)arg0 + 8));
                *(void **)((char *)arg0 + 8) = 0;
            }
        }
        if (*(void **)((char *)arg0 + 8) != 0)
            ((void (*)(void *, float))fn_802E61E4)(*(void **)((char *)arg0 + 8), lbl_805632B0);
        if (*(void **)((char *)arg0 + 0xC) != 0)
            ((void (*)(void *, float))fn_802E61E4)(*(void **)((char *)arg0 + 0xC), lbl_805632B0);
    }
}

void fn_8020BC50(void *arg0, float farg0) { *(float *)((char *)arg0 + 0x24) = farg0; }

typedef float f32;
typedef signed int s32;
void fn_8020BC58(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

s32 fn_8020BC60(void) { return 0; }

void fn_8020BC68(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x20) = farg0; }

void fn_8020BC70(void *arg0, f32 farg0) {
    *(f32 *)((signed char *)arg0 + 0x28) = farg0;
}

void fn_8020BC78(void *arg0, f32 farg0) {
    *(f32 *)((signed char *)arg0 + 0x2C) = farg0;
}

void fn_8020BC80(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x30) = arg1;
}

void fn_8020BC88(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x34) = arg1;
}

void fn_8020BC90(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x38) = arg1;
}

#pragma scheduling invalid_target
void fn_8020BC98(void) {
    fn_802E317C(lbl_8033C510);
}

float fn_8020BCA8(void *arg0) {
    return *(float *)((char *)arg0 + 0x48);
}

void fn_8020BCB0(void) {

}

void fn_8020BCB4(void) {

}

extern void fn_802E6264(void);
extern void fn_802E6B34(void);
extern int fn_80128670(void *);
extern int fn_80019B60(void);
extern void *fn_8012850C(unsigned int, void *);
extern void *memset(void *, int, unsigned int);
extern char lbl_8033C388[];
extern char lbl_8033C37C[];
extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;
extern void *lbl_8055EE04;
extern int lbl_8055EE0C;
extern void *lbl_8055EE10;
extern int fn_8012A364(void *, void *);
extern int fn_801284F8(int, void *);
extern void *fn_8012A13C(void *, int, int);
extern int fn_8012A2D8(void *);
extern char lbl_8033C368[];
extern char lbl_8033C35C[];
extern char lbl_804892D0[];
extern void fn_8020A860();
extern int fn_80208E90(int);
