// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F680;
void* fn_8027ED70(void) {
    return lbl_8055F680;
}

extern int fn_80128668();
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
    ((void (*)(void*))(*(void***)obj)[3])(obj);
}

void fn_802872F0(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 4);
    register void **vtable = *(void ***)obj;
    ((void (*)(void *))vtable[4])(obj);
}

void fn_80287304(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    ((void (*)(void*))(*(void***)obj)[5])(obj);
}

void fn_80287318(void* arg0) {
    void* obj = *(void**)((char*)arg0 + 4);
    (*(void (**)(void*))(*(void***)obj + 6))(obj);
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

