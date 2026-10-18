// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int fn_80128668();
extern char lbl_80348798[];
extern unsigned int lbl_8055F688;
struct Fn8027F834List { void **items; int count; int pad[2]; };
extern struct Fn8027F834List lbl_804B3048;

extern void *lbl_8055F680;
#pragma dont_inline on
void fn_8027ED2C(void) {
    void *obj = lbl_8055F680;
    if (obj != 0) {
        ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
    }
    lbl_8055F680 = 0;
}
#pragma dont_inline reset

void* fn_8027ED70(void) {
    return lbl_8055F680;
}

extern int fn_802146BC(int *, int, int, int, int, int, int, int);
extern int lbl_802FA848;
extern int lbl_803480A8;
extern int lbl_804B2FF8;
extern int lbl_8055B860;
extern int lbl_8055C7C8;
__declspec(section ".data") extern int lbl_802FA848;
__declspec(section ".data") extern int lbl_804B2FF8;
__declspec(section ".data") extern int lbl_803480A8;
extern int lbl_8055C7C8, lbl_8055B860;
void fn_8027ED78(int arg0, int arg1, int arg2) {
 volatile int sp6c,sp68,sp64,sp60,sp5c;
 volatile int sp58=13,sp54=-2,sp50=0,sp4c=6;
 int * volatile sp48=&lbl_8055B860;
 volatile int sp44=0,sp40=0,sp3c=arg1,sp38=3;
 int * volatile sp34=&lbl_803480A8;
 volatile int sp30=0,sp2c=0,sp28=arg0,sp24=3;
 int * volatile sp20=&lbl_8055C7C8;
 volatile int sp18,sp14,sp10,sp0c,sp08;
 sp5c=((int*)&lbl_804B2FF8)[0]; sp60=((int*)&lbl_804B2FF8)[1]; sp64=((int*)&lbl_804B2FF8)[2]; sp68=((int*)&lbl_804B2FF8)[3]; sp6c=((int*)&lbl_804B2FF8)[4];
 sp08=lbl_802FA848; sp10=((int*)&lbl_802FA848)[2]; sp14=((int*)&lbl_802FA848)[3]; sp18=((int*)&lbl_802FA848)[4];
 fn_802146BC((int*)&sp08,-999,-999,1,sp18,sp14,sp10,sp08);
}

void fn_8027EE74(int arg0) {
    extern unsigned char lbl_8055F684;
    extern int fn_80236914(void);
    lbl_8055F684 = (arg0 - 2) == 0 ? 1 : 0;
    fn_80236914();
}

#pragma dont_inline on
int fn_8027EE88(void) {
    extern unsigned char lbl_8055F684, lbl_8055F685;
    extern int lbl_80348078;
    extern void *fn_8027ED70(void);
    void *obj;
    void (**vt)(void *, void *);
    if (lbl_8055F685 == 0 && lbl_8055F684 != 0) {
        lbl_8055F685 = 1;
        obj = fn_8027ED70();
        vt = (void (**)(void *, void *))*(void ***)obj;
        vt[14](obj, &lbl_80348078);
    }
    return 0;
}
#pragma dont_inline reset
void fn_8027F204(char *src) {
    extern int lbl_8055F69C;
    extern int lbl_80348270;
    extern int fn_802E30C8(const char *);
    int index, i;
    char *dst;
    int *state = (int *)lbl_8055F69C;
    if (state == 0) return;
    if (state[0x44 / 4] + 1 <= state[0x48 / 4]) {
        index = state[0x44 / 4];
        state[0x44 / 4] = index + 1;
        dst = *(char **)((char *)state + 0x40) + index * 0x1e;
        for (i = 0; i < 0x1e; i++) {
            char c = *src++;
            *dst++ = c;
            if (c == 0) return;
        }
        dst[-1] = 0;
        return;
    }
    fn_802E30C8((const char *)&lbl_80348270);
}

void *fn_8027F834(void *arg0, int arg1) {
    int temp_r0, var_ctr, var_r7;
    unsigned int *var_r6;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80348798;
        if (lbl_8055F688 == (unsigned int)arg0) lbl_8055F688 = 0;
        var_r6 = (unsigned int *)lbl_804B3048.items;
        var_r7 = 0;
        var_ctr = lbl_804B3048.count;
        if (lbl_804B3048.count > 0) {
loop_4:
            if (*var_r6 == (unsigned int)arg0) {
            } else {
                var_r6 += 4;
                var_r7 += 1;
                var_ctr -= 1;
                if (var_ctr == 0) goto block_7;
                goto loop_4;
            }
        } else {
block_7:
            var_r7 = -1;
        }
        if (var_r7 != -1 && var_r7 >= 0 && var_r7 < lbl_804B3048.count) {
            temp_r0 = lbl_804B3048.count - 1;
            if (var_r7 != temp_r0)
                ((unsigned int *)lbl_804B3048.items)[var_r7] = ((unsigned int *)lbl_804B3048.items)[temp_r0];
            lbl_804B3048.count = lbl_804B3048.count - 1;
        }
        if (arg0 != 0) {
            *((unsigned char *)arg0 + 0x18) = 0;
            *((unsigned char *)arg0 + 0x50) = 0;
            *((unsigned char *)arg0 + 0x5C) = 0;
            *(int *)((char *)arg0 + 0x24) = 1;
            *(int *)((char *)arg0 + 0x20) = 0;
            *((unsigned char *)arg0 + 0x44) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int fn_80280898(void) { extern unsigned int lbl_8055F688; extern int fn_80216D28(void); if (lbl_8055F688 == 0) { fn_80216D28(); return 0; } return 1; }

extern int fn_80216D28();
extern int fn_8025C204(int);
extern unsigned char lbl_8055F684;
extern void *lbl_8055F698;
extern int lbl_8055F69C;
extern unsigned char lbl_80348678[];
extern unsigned int lbl_804B30D8[];
int fn_802837D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void *fn_80283938(void *arg0, int arg1) {
    void *base;
    void *next;
    void *field;
    if (arg0 != 0) {
        base = lbl_80348678;
        *(void **)arg0 = base;
        next = (char *)base + 0x50;
        *(void **)((char *)arg0 + 4) = next;
        lbl_8055F69C = 0;
        field = *(void **)((char *)arg0 + 0x20);
        if (field != 0) fn_80128668(field);
        if ((unsigned int)arg0 + 0x40 != 0) {
            if ((unsigned int)arg0 + 0x40 != 0) {
                *(int *)((char *)arg0 + 0x40) = 0;
                *(int *)((char *)arg0 + 0x44) = 0;
                *(int *)((char *)arg0 + 0x48) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int fn_802839D0(void) {
    int temp_r31;
    void **temp_r3;
    void **temp_r3_2;
    int result;
    if (lbl_8055F684 != 0 && lbl_8055F698 != 0) {
        temp_r3 = *(void *** )((char *)lbl_8055F698 + 0x60);
        temp_r31 = ((int (**)(void *))*temp_r3)[9](temp_r3);
        temp_r3_2 = *(void *** )((char *)lbl_8055F698 + 0x60);
        result = ((int (**)(void *, void *))*temp_r3_2)[8](temp_r3_2, lbl_8055F698);
        ((int (*)(int, int))fn_8025C204)(result, temp_r31);
    } else {
        fn_80216D28();
    }
    return 0;
}

int fn_80283A50(void) {
    int i = 0, count = (int)lbl_804B30D8[1];
    unsigned int *p = (unsigned int *)lbl_804B30D8[0];
    unsigned int value = (unsigned int)lbl_8055F698;
    for (; count > 0; --count) {
        if (*p == value) return 1;
        p += 4; ++i;
    }
    fn_80216D28();
    return 0;
}

int fn_80283AC8(void) {
 int i=0;
 int count=(int)lbl_804B30D8[1];
 unsigned int *p=(unsigned int*)lbl_804B30D8[0];
 unsigned int value=(unsigned int)lbl_8055F698;
 if (count > 0) {
   do {
     if (*p == value) goto found;
     p++;
     ++i;
   } while (--count != 0);
 }
 i=-1;
found:
 if (i >= 0 && *(int *)((char *)lbl_804B30D8[0] + i * 16 + 0x60)) return 1;
 fn_80216D28();
 return 0;
}

void fn_802840F4(void) {
    fn_8027E908();
}

void fn_802840F8(void) {
    fn_8027ED2C();
}

void fn_80286724(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    void** vtable = *(void***)obj;
    ((void (*)(void))vtable[3])();
}

void fn_80286738(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    void** vtable = *(void***)obj;
    ((void (*)(void))vtable[4])();
}

void fn_8028674C(void* arg0) {
    ((void (*)(void))(*(void***)(*(void**)((char*)arg0 + 0x1c)))[5])();
}

void fn_80286760(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    (*(void (**)(void*))(*(void***)obj + 6))(obj);
}

void fn_80286774(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    (*(void (**)(void*))(*(void***)obj + 7))(obj);
}

void fn_80286788(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    ((void (**)(void*))(*(void***)obj))[8](obj);
}

void fn_8028679C(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1c);
    void **vtable = *(void ***)obj;
    void (*fn)(void) = (void (*)(void))vtable[9];
    fn();
}

int fn_802867B0(void *arg0) {
    extern double lbl_80564220;
    void * volatile p = *(void **)((char *)arg0 + 0x20);
    int value;
    if (p != 0) {
        value = (int)((float)*(int *)p + *(float *)((char *)p + 0x10));
        if (value > *(int *)((char *)p + 4))
            value = *(int *)((char *)p + 4);
        return value;
    }
    p = *(void **)((char *)arg0 + 0x1c);
    return ((int (*)(void *))(*(void **)((char *)*(void **)p + 0x28)))(p);
}

void fn_80286834(void **arg0) {
    int result;
    result = ((int (*)(void))(*(void **)((char *)*arg0 + 0x28)))();
    ((void (*)(void **, int))(*(void **)((char *)*arg0 + 0x30)))(arg0, result);
}

void fn_80286884(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    ((void (*)(void*))(*(void**)((char*)obj + 0)))(obj);
}

void fn_80286898(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    (*(void (**)(void*))((char*)*(void**)obj + 0x34))(obj);
}

void fn_802868AC(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    struct VTable { void* pad[14]; };
    ((void (*)(void*))((struct VTable*)*(void**)obj)->pad[14])(obj);
}

void fn_802868C0(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    (*(void (**)(void))((char *)*(void **)obj + 0x3C))();
}

int fn_802868D4(void *arg0) {
    int a = ((int (*)(void *))(*(void ***)arg0)[15])(arg0);
    int b = ((int (*)(void *))(*(void ***)arg0)[10])(arg0);
    return b >= a;
}

void fn_8028693C(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    void **vtable = *(void ***)obj;
    void *slot = vtable[17];
    ((void (*)(void))slot)();
}

typedef unsigned int (*GetFn)(void *);
typedef int (*CmpFn)(void *);
int fn_80286950(void **arg0) {
    unsigned int a;
    GetFn get;
    CmpFn cmp;
    get = *(GetFn *)((char *)*arg0 + 0x4C);
    a = get(arg0);
    cmp = *(CmpFn *)((char *)*arg0 + 0x28);
    return (int)a <= cmp(arg0);
}

void fn_802869B8(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    volatile void * volatile *vtable = (volatile void * volatile *)*(void ***)obj;
    ((void (*)(void *))vtable[19])(obj);
}

int fn_802869CC(void *arg0, int arg1) {
    extern double lbl_80564220;
    void *p;
    int d;
    if (arg1 == 13) {
        p = *(void **)((char *)arg0 + 0x20);
        if (p != 0 && *(unsigned char *)((char *)arg0 + 0x29) == 0) {
            d = *(int *)((char *)p + 4) - *(int *)p;
            *(float *)((char *)p + 0x10) = (float)((double)d - lbl_80564220);
            return 1;
        }
    }
    return 0;
}

#pragma dont_inline on
void fn_80287238(void *arg0) {
    extern float lbl_80564200, lbl_805641FC;
    extern int lbl_80347FB4;
    extern int fn_80214A9C(int);
    extern void *fn_8027ED70(void);
    void *temp_r4 = *(void **)((char *)arg0 + 0x20);
    if (temp_r4 != 0) {
        *(float *)((char *)temp_r4 + 0x10) = lbl_80564200;
        *(unsigned char *)((char *)arg0 + 0x29) = 0;
        *(unsigned char *)((char *)arg0 + 0x2A) = 0;
        *(unsigned char *)((char *)arg0 + 0x28) = ((unsigned char (*)(void))(*(void ***)arg0)[16])();
        ((void (*)(void *))(*(void ***)fn_8027ED70())[14])(&lbl_80347FB4);
        fn_80214A9C(0x1F);
        *(float *)((char *)arg0 + 0x178) = lbl_805641FC;
        return;
    }
    *(unsigned char *)((char *)arg0 + 0x29) = 1;
    *(unsigned char *)((char *)arg0 + 0x2A) = 0;
    *(float *)((char *)arg0 + 0x178) = lbl_80564200;
}
#pragma dont_inline reset
extern float lbl_80564200;
extern float lbl_805641FC;
extern int lbl_80347FB4;
extern void* fn_8027ED70(void);
extern int fn_80214A9C(int);
#pragma scheduling off
void fn_802872DC(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[3])(obj);
}
#pragma scheduling on
void fn_802872F0(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[4])(obj);
}

void fn_80287304(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[5])(obj);
}

extern unsigned char lbl_8055F685;
extern int lbl_80348078;
extern unsigned char lbl_8055F684, lbl_8055F685;
extern int lbl_80348270;
extern void *fn_8027ED70(void);
extern int fn_80216D28(void);
extern int fn_802E30C8(const char *);
void fn_80287318(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[6])(obj);
}

void* fn_8028732C(void* arg0, int arg1) {
    void* cached = *(void**)((char*)arg0 + 8);
    void* obj;
    if (cached != 0 && arg1 == *(int*)((char*)arg0 + 12))
        return cached;
    obj = *(void**)((char*)arg0 + 4);
    return (*(void* (**)(void))(*(void***)obj + 7))();
}

void fn_80287360(void) {
}

int fn_80287364(void* arg0) {
    int i;
    void* item;

    for (i = 0; i < ((int (*)(void*))(*(void***)arg0)[6])(arg0); i++) {
        item = ((void* (*)(void*, int))(*(void***)arg0)[7])(arg0, i);
        if (((int (*)(void))(*(void***)item)[16])() == 0) {
            return 0;
        }
    }
    return 1;
}

void fn_802873F8(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void** vtable = *(void***)obj;
    ((void (*)(void))vtable[9])();
}

int fn_8028740C(void* arg0) {
    int i;
    void* item;

    for (i = 0; i < ((int (*)(void*))(*(void***)arg0)[6])(arg0); i++) {
        item = ((void* (*)(void*, int))(*(void***)arg0)[7])(arg0, i);
        if (((int (*)(void))(*(void***)item)[18])() == 0) {
            return 0;
        }
    }
    return 1;
}

void fn_802874A0(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    register void** vtable = *(void***)obj;
    register void (*fn)(void*) = (void (*)(void*))vtable[11];
    fn(obj);
}

void fn_802874B4(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    void* (*vtable)[13] = (void* (*)[13])*(void***)obj;
    ((void (*)(void*))(*vtable)[12])(obj);
}
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
