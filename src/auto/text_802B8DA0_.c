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
    if (entry != 0 && stricmp(entry->name, arg0) != 0) {
        if (entry->state != -2) fn_802CAC54();
        result = -2;
        entry->state = -2;
        if ((signed char)*arg0 != 0) result = fn_802B110C(fn_802B8E50, arg0);
        entry->state = result;
        entry->name = arg0;
        if (result == -2 && (signed char)*entry->name != 0) fn_802E317C((const char *)lbl_8034AA50);
    }
}

