// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int fn_80128668();
extern char lbl_80348798[];
extern unsigned int lbl_8055F688;
struct Fn8027F834List { void **items; int count; int pad[2]; };
extern struct Fn8027F834List lbl_804B3048;

extern void *lbl_8055F680;
void* fn_8027ED70(void) {
    return lbl_8055F680;
}

void fn_8027EE74(int arg0) {
    extern unsigned char lbl_8055F684;
    extern int fn_80236914(void);
    lbl_8055F684 = (arg0 - 2) == 0 ? 1 : 0;
    fn_80236914();
}

int fn_8027EE88(void) {
    extern unsigned char lbl_8055F684, lbl_8055F685;
    extern int lbl_80348078;
    extern void *fn_8027ED70(void);
    void *obj;
    if (lbl_8055F685 == 0 && lbl_8055F684 != 0) {
        lbl_8055F685 = 1;
        obj = fn_8027ED70();
        ((void (*)(void *))(*(void ***)obj)[14])(&lbl_80348078);
    }
    return 0;
}

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
        if (var_ctr > 0) {
            do {
                if (*var_r6 == (unsigned int)arg0) break;
                var_r6 += 4;
                var_r7 += 1;
            } while (--var_ctr != 0);
            if (var_ctr == 0) var_r7 = -1;
        } else {
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
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80348678;
        *(void **)((char *)arg0 + 4) = lbl_80348678 + 0x50;
        lbl_8055F69C = 0;
        if (*(int *)((char *)arg0 + 0x20) != 0) fn_80128668();
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
    int temp;
    void **p;
    if (lbl_8055F684 != 0 && lbl_8055F698 != 0) {
        p = *(void *** )((char *)lbl_8055F698 + 0x60);
        temp = ((int (*)(void *))(*(void ***)*p + 0x24))(p);
        p = *(void *** )((char *)lbl_8055F698 + 0x60);
        ((int (*)(void *, void *))(*(void ***)*p + 0x20))(p, lbl_8055F698);
        fn_8025C204(temp);
    } else fn_80216D28();
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
    volatile void** vtable = *(volatile void***)obj;
    ((void (*)(void))vtable[3])();
}

void fn_80286738(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    volatile void** vtable = *(volatile void***)obj;
    ((void (*)(void))vtable[4])();
}

void fn_8028674C(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    volatile void** vtable = *(volatile void***)obj;
    ((void (*)(void))vtable[5])();
}

void fn_80286760(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    register void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[6])(obj);
}

void fn_80286774(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    register void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[7])(obj);
}

void fn_80286788(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    register void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[8])(obj);
}

void fn_8028679C(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1c);
    (*(void (**)(void))(*(void ***)obj + 9))();
}

int fn_802867B0(void *arg0) {
    void *p = *(void **)((char *)arg0 + 0x20);
    int value;
    if (p != 0) {
        value = (int)(*(int *)p + *(float *)((char *)p + 0x10));
        if (value > *(int *)((char *)p + 4))
            value = *(int *)((char *)p + 4);
        return value;
    }
    p = *(void **)((char *)arg0 + 0x1c);
    return ((int (*)(void *))(*(void **)((char *)*(void **)p + 0x28)))(p);
}

void fn_80286834(void **arg0) {
    void *obj = *arg0;
    int result = ((int (*)(void))(*(void **)((char *)*(void **)obj + 0x28)))();
    ((void (*)(void *, int))(*(void **)((char *)*(void **)obj + 0x30)))(obj, result);
}

void fn_80286884(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    ((void (*)(void*))(*(void***)obj)[12])(obj);
}

void fn_80286898(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    ((void (*)(void*))(*(void***)obj)[13])(obj);
}

void fn_802868AC(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 0x1c);
    ((void (*)(void*))(*(void***)obj)[14])(obj);
}

void fn_802868C0(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    ((void (*)(void))(*(void ***)obj)[15])();
}

int fn_802868D4(void *arg0) {
    void *obj = arg0;
    unsigned int a = ((unsigned int (*)(void *))(*(void ***)obj)[15])(obj);
    int b = ((int (*)(void *))(*(void ***)obj)[10])(obj);
    return (int)b <= (int)a;
}

void fn_8028693C(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    ((void (*)(void))(*(void ***)obj)[17])();
}

int fn_80286950(void *arg0) {
    unsigned int a;
    int b;
    void **vtable;
    vtable = *(void ***)arg0;
    a = ((unsigned int (*)(void *))vtable[19])(arg0);
    vtable = *(void ***)arg0;
    b = ((int (*)(void *))vtable[10])(arg0);
    return (int)a <= b;
}

void fn_802869B8(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x1C);
    register void **vtable = *(void ***)obj;
    ((void (*)(void *))vtable[19])(obj);
}

int fn_802869CC(void *arg0, int arg1) {
    extern double lbl_80564220;
    void *p;
    double d;
    if (arg1 != 13) {
        goto fail;
    }
    p = *(void **)((char *)arg0 + 0x20);
    if (p == 0) goto fail;
    if (*(unsigned char *)((char *)arg0 + 0x29) != 0) goto fail;
    d = (double)(*(int *)((char *)p + 4) - *(int *)p);
    *(float *)((char *)p + 0x10) = (float)(d - lbl_80564220);
    return 1;
fail:
    return 0;
}

extern float lbl_80564200;
extern float lbl_805641FC;
extern int lbl_80347FB4;
extern void* fn_8027ED70(void);
extern int fn_80214A9C(int);
void fn_802872DC(void* arg0) {
 void* obj = *(void**)((char*)arg0 + 4);
 (*(void (**)(void*))(*(void ***)obj + 3))(obj);
}

void fn_802872F0(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    register void** vtable = *(void***)obj;
    ((void (*)(void*))vtable[4])(obj);
}

void fn_80287304(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    volatile void** vtable = *(volatile void***)obj;
    ((void (*)(void))vtable[5])();
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
    register void** vp = *(void***)obj;
    ((void (*)(void*))vp[6])(obj);
}

void* fn_8028732C(void* arg0, int arg1) {
    void* cached = *(void**)((char*)arg0 + 8);
    void* obj;
    void** vtable;
    if (cached != 0 && arg1 == *(int*)((char*)arg0 + 12))
        return cached;
    obj = *(void**)((char*)arg0 + 4);
    vtable = *(void***)obj;
    return ((void* (*)(void))vtable[7])();
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

void fn_802873F8(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 4);
    ((void (*)(void))(*(void ***)obj)[9])();
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
    ((void (*)(void*))(*(void***)obj)[11])(obj);
}

void fn_802874B4(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    ((void (*)(void*))(*(void***)obj)[12])(obj);
}

