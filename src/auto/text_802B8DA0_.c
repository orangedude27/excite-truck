#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
extern double cos(double);
extern double sin(double);
extern void *fn_801284F8(int, void *);
extern void fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern int lbl_8034A9F4;
extern void *lbl_8055FA7C;
extern int lbl_804BFFF4;
extern int lbl_8055FA6C, lbl_8055FA70;
extern void *lbl_8055FA74;
int fn_802CAC28(int, int);
void fn_802B9FC0(void *);
int fn_80128668(void *);
void fn_8002F6AC(int, void (*)(void));
void* fn_802B8DA0(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void* fn_802B8DF8(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_802B8E50(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

int fn_802B9100(void) {
    return 0;
}

void fn_802B98D0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

int fn_802B9914(void *arg0) {
    return (short)((int *)arg0)[6];
}

extern int lbl_802FAB60[];
int fn_802B9920(int arg0) {
    int v = arg0 + 0x200;
    int idx = (v >> 31) + (v << 27) + ((v << 27) >> 27);
    return (short)lbl_802FAB60[idx];
}

short fn_802B9954(void* arg0) {
    return (short)((int*)arg0)[5];
}

void fn_802B9960(void) {
}

extern double ceil(double);
float fn_802B9A80(float arg0) {
    return ceil(arg0);
}

void fn_802B9AA4(void *arg0, float *arg1, float *arg2) {
    arg1[0] = *(float *)((char *)arg0 + 0x14);
    arg1[1] = *(float *)((char *)arg0 + 0x18);
    arg2[0] = *(float *)((char *)arg0 + 0x1C);
    arg2[1] = *(float *)((char *)arg0 + 0x20);
}

void fn_802B9AC8(void) {
}

s32 fn_802B9ACC(void *arg0) { return ((s32 *)arg0)[2]; }

void* fn_802B9AD4(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B9B2C(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B9B40(void *arg0) {
    ((int *)arg0)[1] = 0;
    ((int *)arg0)[0] = 0;
}

int fn_802B9B50(int **arg0, int **arg1) {
    return (*arg0)[2] - (*arg1)[2];
}

void* fn_802B9C9C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B9CF4(void *arg0) {
    ((int *)arg0)[0] = 0;
    ((int *)arg0)[2] = 0;
    ((int *)arg0)[1] = 0;
}

void fn_802B9DD0(void* arg0) {
    void* p = *(void**)arg0;
    if (p != NULL) {
        if (p != NULL) {
            int x = ((int*)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != NULL) {
                ((int*)p)[0] = 0;
                ((int*)p)[1] = 0;
                ((int*)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void**)arg0 = NULL;
    }
}

void fn_802B9E4C(void *arg0) {
    void *p = *(void **)arg0;
    if (p != 0) {
        if (p != 0) {
            int x = ((int *)p)[3];
            if (x != 0) {
                fn_80128670(x - 0x10);
            }
            if (p != 0) {
                ((int *)p)[0] = 0;
                ((int *)p)[1] = 0;
                ((int *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = 0;
    }
}

void fn_802B9EC8(void *arg0) {
    void *p = *(void **)arg0;
    if (p != 0) {
        if (p != 0) {
            fn_80128670(((s32 *)p)[3]);
            if (p != 0) {
                ((s32 *)p)[0] = 0;
                ((s32 *)p)[1] = 0;
                ((s32 *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = 0;
    }
}

#pragma push
#pragma opt_common_subs off
void fn_802B9F38(void **arg0) {
    void *ptr = *arg0;
    if (ptr != 0) {
        if (ptr != 0) {
            fn_802B9FC0(ptr);
            if ((char *)ptr + 4 != 0) {
                fn_8002F6AC(((int *)ptr)[4], (void (*)(void))fn_802B9C9C);
                if ((char *)ptr + 4 != 0) {
                    ((int *)ptr)[1] = 0;
                    ((int *)ptr)[2] = 0;
                    ((int *)ptr)[3] = 0;
                }
            }
            fn_80128668(ptr);
        }
        *arg0 = 0;
    }
}
#pragma pop
void fn_802B9FC0(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128670(buf);
        *(void **)arg0 = NULL;
    }
}

extern int lbl_802FAB60[];
extern void *lbl_8055FA84;
void fn_802BA004(void) {
    lbl_8055FA84 = 0;
}

void fn_802BA560(void *arg0) {
    *(volatile int *)((char *)arg0 + 4) = 0;
    *(volatile int *)((char *)arg0 + 0) = 0;
    *(volatile int *)((char *)arg0 + 8) = 3;
    *(volatile unsigned char *)((char *)arg0 + 0xC) = 1;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
#pragma dont_inline on
extern "C" void *fn_802BA580(void **arg0, void *arg1, float scale) {
    class Object { public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual char *name(void *);
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual unsigned long long value(void *);
    };
    extern int fn_802E317C(const char *, ...);
    extern int fn_802B110C(void *, char *);
    extern int stricmp(const char *,const char *);
    extern void fn_801602B0(void *);
    extern void fn_8016029C(void *, void *);
    extern void fn_80160B18(void *);
    extern void fn_80160BA0(void *, void *, float);
    extern void fn_80144D64(void *, void *);
    extern void *fn_802C9A40(void);
    extern void fn_801E0F78(void *, void *, void *, float);
    extern void fn_8001BA68(void *);
    extern float fn_801DCF48(void *, float, float);
    extern float fn_801E0FA4(void *, void *);
    extern float fn_8014C8B4(float,float,float,float,float);
    extern void fn_802BAA50(void *);
    extern void fn_802BA848(void *,void *,void *,void *);
    extern float lbl_80564CDC, lbl_80564CC4, lbl_80564CD8;
    extern float lbl_80564CE0, lbl_80564CE4, lbl_80564CE8, lbl_80564CCC;
    extern int lbl_8055CF04, lbl_8055CEF8, lbl_8055CECC, lbl_8034AA2C;
    float j[3], h[3];
    union { unsigned long long bits; float v[2]; } value;
    float g[2], f[2], e[2], d[2], c[2], b[2], a[2];
    char *result;
    char *name;
    int *entry;
    int **items;
    int index;
    int state;
    int count;
    result = *(char **)lbl_8055FA7C + (*(int *)((char *)lbl_8055FA7C+4))*0x44;
    ++*(int *)((char *)lbl_8055FA7C+4);
    fn_801602B0(a); fn_801602B0(b); fn_801602B0(c); fn_801602B0(d);
    value.bits = ((Object *)arg0)->value(&lbl_8055CF04);
    fn_80160BA0(d,&value,scale);
    fn_80144D64(h,fn_802C9A40());
    fn_801602B0(e);
    fn_8016029C(e,h);
    fn_80160B18(e);
    fn_80160BA0(b,e,d[1]);
    fn_80160BA0(c,e,d[0]);
    fn_802BAA50(c);
    fn_801E0F78(a,arg1,c,lbl_80564CDC);
    fn_801602B0(f);
    fn_801E0F78(f,arg1,b,lbl_80564CC4);
    fn_8001BA68(j);
    if (fn_801DCF48(j,f[0],f[1]) != lbl_80564CD8) {
        fn_801602B0(g);
        fn_8016029C(g,j);
        fn_80160BA0(b,b,fn_8014C8B4(lbl_80564CE0,lbl_80564CE4,lbl_80564CE8,lbl_80564CCC,fn_801E0FA4(g,e)));
    }
    fn_802BA848(result,c,b,a);
    *(int *)(result+8)=1;
    name=((Object *)arg0)->name(&lbl_8055CEF8);
    for(index=0; index < *(int *)((char *)&lbl_804BFFF4+4); index++) {
        entry=(*(int ***)&lbl_804BFFF4)[index];
        if (stricmp((char *)entry[0],name)==0) goto found;
    }
    count=*(int *)((char *)&lbl_804BFFF4+4);
    items=*(int ***)&lbl_804BFFF4;
    *(int *)((char *)&lbl_804BFFF4+4)=count+1;
    entry=(int *)fn_801284F8(0x10,&lbl_8055CECC);
    if(entry) {
        entry[0]=(int)name;
        if ((signed char)*name) state=fn_802B110C((void *)fn_802B8E50,name);
        else state=-2;
        entry[1]=state;
        if(state==-2 && (signed char)*name) fn_802E317C((char *)&lbl_8034AA2C,name);
        entry[3]=0;
        entry[2]=999;
    }
    items[count]=entry;
found:
    *(int *)(result+16)=entry[3];
    entry[3]=(int)result;
    lbl_8055FA84=(void *)((int)lbl_8055FA84+1);
    return result;
}
#pragma cplusplus reset
#pragma pop

void fn_802BAA50(void *arg0) {
    float a = *(float *)arg0;
    float b = *((float *)arg0 + 1);
    *(float *)arg0 = b;
    *((float *)arg0 + 1) = -a;
}

void fn_802BAD0C(void *arg0, float angle) {
    float x = *(float *)((char *)arg0 + 0);
    float c = (float)cos(angle);
    float s = (float)sin(angle);
    float y = *(float *)((char *)arg0 + 4);
    *(float *)((char *)arg0 + 4) = x * s + y * c;
    *(float *)((char *)arg0 + 0) = *(float *)((char *)arg0 + 0) * c - y * s;
}

int fn_80128668(void *);
int fn_80128670(int);
double cos(double);
double sin(double);
extern float lbl_80564CF0;
float fn_802BAD90(float farg0) {
    return lbl_80564CF0 * farg0;
}

void fn_802BAE30(void *arg0) {
    *(volatile int *)((char *)arg0 + 4) = 0;
    *(volatile int *)((char *)arg0 + 0) = 0;
    *(volatile int *)((char *)arg0 + 8) = 3;
    *(volatile unsigned char *)((char *)arg0 + 0xC) = 1;
}

typedef signed char s8;
void fn_802BAF98(void* arg0, s8 arg1) {
    ((s8*)arg0)[0xC] = arg1;
}

void fn_802BAFA0(void) {
    void **entries = *(void ***)&lbl_804BFFF4;
    int count = *(int *)((char *)&lbl_804BFFF4 + 4);
    lbl_8055FA6C = 0;
    lbl_8055FA70 = 0;
    while (count > 0) {
        void *p = *(void **)((char *)*entries + 12);
        while (p != 0)
            p = *(void **)((char *)p + 16);
        entries++;
        count--;
    }
    *(int *)((char *)lbl_8055FA74 + 8) = 0;
}

extern int lbl_804C0088[];
extern int lbl_8034AA50;
extern int fn_802B110C(void *, char *);
extern int fn_802CAC54(void);
extern int fn_802E317C(const char *, ...);
extern int stricmp(const char *, const char *);
extern int fn_802B8E50(int);
void fn_802BB674(char *arg0, int arg1) {
    struct Entry { char *name; int state; };
    struct Entry *entry = ((struct Entry **)lbl_804C0088)[arg1];
    int result;
    int first;
    if (entry != 0 && stricmp(entry->name, arg0) != 0) {
        if (*(volatile int *)&entry->state != -2) fn_802CAC54();
        first = (signed char)*arg0;
        result = -2;
        entry->state = -2;
        if (first != 0) result = fn_802B110C(fn_802B8E50, arg0);
        entry->state = result;
        entry->name = arg0;
        if (result == -2 && (signed char)*(volatile char *)entry->name != 0)
            fn_802E317C((char *)&lbl_8034AA50);
    }
}

