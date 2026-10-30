// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void *fn_8012850C(signed long, const char *);
extern void fn_80207C50(void *, void *, signed long);
extern void fn_80127CF4(void *, const char *, signed long);
extern void *memset(void *, int, unsigned long);
extern char lbl_8033BEE8[];
extern char lbl_8033BDD8[];
extern char lbl_8033BDF0[];
extern float lbl_804891F8[];
extern float lbl_80489228[];
extern float lbl_80563228;
extern float lbl_8056322C;
extern unsigned long lbl_802F9E4C[];
// split_file divides it into the game's real files (file_status shows its range).

#pragma cplusplus on
struct LoopItem_80207E70 {
    virtual int f0(int);
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
};
#pragma cplusplus reset

extern void fn_80208408();
extern void fn_80208858(void *, signed long, signed long);
extern signed long fn_80128668(void);
extern void* fn_802090B4(void);
extern signed long fn_802E317C(const char*, ...);
extern signed long fn_8026A344(signed long);
extern signed long fn_80206570(signed long);
extern signed long fn_8020835C(void *);
extern signed long fn_8020815C(void *);
extern int __cntlzw(unsigned int);

typedef struct SoundMgrObj {
    char pad0[0x10];
    signed long field_10;
    char pad14[0x30];
    signed long field_44;
    char pad48[0x20];
    float field_68;
} SoundMgrObj;

typedef struct SoundMgr {
    char pad0[0xc];
    void** list;
    char pad10[0x4];
    signed long count;
} SoundMgr;

typedef struct Vt_80207960 {
    void (*f0)(void);
    void (*f1)(void*, signed long);
    void (*f2)(void*);
} Vt_80207960;

#pragma dont_inline on
void fn_80207960(void) {
	return;
}
#pragma dont_inline reset

signed long fn_80207964(signed long arg0) {
    switch (arg0) {
    case 0:
        return 1;
    default:
        return 0;
    }
}

#pragma dont_inline on
void fn_80207980(void* arg0) {
    *(signed long*)arg0 = 0;
    *((signed long*)arg0 + 1) = 0;
}
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_80207990(void *arg0, void *arg1) {
    struct Slot {
        void * volatile ptr;
        signed long value;
    };
    struct SoundObject {
        void *vtable;
        char field4;
        volatile char field5;
        char pad6[2];
        volatile signed long field8;
        void * volatile fieldC;
        signed long count;
        struct Slot slots[9];
        char cleared5C[0x30];
        signed long flag8C;
        void *callback;
        char tail94[0x84];
    };
    struct Callback {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual int f4();
    };
    struct SoundObject *object;
    struct Slot *end;
    struct Slot *slot;
    signed long i;
    signed long values[3];
    volatile float *vector1;
    volatile float *vector2;
    unsigned long *source;
    float zero;
    float one;

    object = (struct SoundObject *)arg0;
    object->vtable = lbl_8033BEE8;
    fn_80207980((void *)&object->fieldC);
    slot = &object->slots[0];
    end = &object->slots[9];
    do {
        fn_80207980(slot);
        slot++;
    } while (slot < end);
    fn_80207960();
    object->fieldC = fn_8012850C(0x3C0, lbl_8033BDD8);
    object->count = 0;
    object->callback = arg1;
    memset(object->cleared5C, 0, 0x30);
    vector1 = lbl_804891F8;
    object->field5 = 0;
    vector2 = lbl_80489228;
    zero = lbl_8056322C;
    one = lbl_80563228;
    vector1[1] = zero;
    vector1[0] = one;
    vector1[2] = zero;
    vector1[3] = zero;
    vector1[4] = one;
    vector1[5] = zero;
    vector1[6] = zero;
    vector1[7] = zero;
    vector1[8] = one;
    vector1[9] = zero;
    vector1[10] = zero;
    vector1[11] = zero;
    vector2[0] = zero;
    vector2[1] = zero;
    vector2[2] = zero;
    object->flag8C = 1;
    source = lbl_802F9E4C;
    values[0] = *source++;
    values[1] = *source++;
    values[2] = *source++;
    i = 0;
    do {
        fn_80207C50(object, values, i);
        i += 1;
    } while (i < 4);
    memset(object->tail94, 0, 0x84);
    object->slots[0].ptr = object->fieldC;
    object->slots[1].ptr = object->fieldC;
    object->slots[2].ptr = object->fieldC;
    object->slots[3].ptr = object->fieldC;
    object->slots[4].ptr = object->fieldC;
    object->slots[5].ptr = object->fieldC;
    object->slots[6].ptr = object->fieldC;
    object->slots[7].ptr = object->fieldC;
    object->slots[8].ptr = object->fieldC;
    object->field8 = 0;
    fn_80127CF4(object, lbl_8033BDF0, 0);
    object->field4 = ((struct Callback *)arg1)->f4();
    return arg0;
}
#pragma cplusplus reset
#pragma pop

extern void fn_80207DE0(void*);
extern void fn_802E30C8(const char*, ...);
extern void fn_80128670(void);
extern void fn_80127E28(void*);
extern char lbl_8033BE08[];
extern char lbl_8033BEE8[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void* fn_80207B60(void* arg0, signed long arg1) {
    struct Obj {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
    };
    signed long offset;
    signed long i;
    void* obj;
    if (arg0 != 0) {
        *(void**)arg0 = lbl_8033BEE8;
        fn_80207DE0(arg0);
        i = 0;
        offset = 0;
        while (i < *(signed long*)((char*)arg0 + 0x10)) {
            fn_802E30C8(lbl_8033BE08, *(signed long*)((char*)*(void***)((char*)arg0 + 0xC) + offset) + 0x37);
            offset += 4;
            i++;
        }
        obj = *(void**)((char*)arg0 + 0xC);
        if (obj != 0) {
            ((void (*)(void*))fn_80128670)(obj);
            *(void**)((char*)arg0 + 0xC) = 0;
        }
        obj = *(void**)((char*)arg0 + 0x90);
        *(signed long*)((char*)arg0 + 0x10) = 0;
        if (obj != 0) ((Obj*)obj)->f7();
        fn_80127E28(arg0);
        *(char*)((char*)arg0 + 4) = 0;
        if (arg1 > 0) ((void (*)(void*))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma cplusplus reset
#pragma pop
void fn_80207C48(void) {
	return;
}

void fn_80207C4C(void) {
	return;
}

void fn_80207C50(void* arg0, void* arg1, signed long arg2) {
    signed long c = *((signed long*)arg1 + 2);
    signed long b = *((signed long*)arg1 + 1);
    signed long a = *(signed long*)arg1;
    void* dst = (void*)((char*)arg0 + arg2 * 0xC);
    *(signed long*)((char*)dst + 0x5C) = a;
    *(signed long*)((char*)dst + 0x60) = b;
    *(signed long*)((char*)dst + 0x64) = c;
}

void fn_80207C74(void* arg0, signed long arg1) {
    *(signed long*)((char*)arg0 + 0x8C) = arg1;
}

void fn_80207C7C(void) {
	return;
}

void fn_80207E70(void* arg0);

void fn_80207C80(void *arg0) {
    /* Fix note: iterate the item list twice, then run the matching completion callbacks. */
    struct Object {
        char pad0[0xC];
        int *items;
        signed long count;
        char pad14[0x48];
        char field5c[0x30];
        signed long field8c;
    };
    volatile struct Object *object = (volatile struct Object *)arg0;
    signed long i;
    signed long offset;

    i = 0;
    offset = 0;
    while (i < object->count) {
        fn_802067C8(*(int *)((char *)object->items + offset),
                    (void *)&object->field5c, object->field8c);
        offset += 4;
        i += 1;
    }
    fn_8020835C(arg0);
    fn_80207F34(arg0);
    offset = 0;
    i = 0;
    while (i < object->count) {
        fn_80206824(*(int *)((char *)object->items + offset),
                    (void *)&object->field5c, object->field8c);
        offset += 4;
        i += 1;
    }
    fn_8020815C(arg0);
    fn_80207E70(arg0);
}

#pragma dont_inline on
signed long fn_80207D40(void* arg0) {
    signed long temp_r3;

    temp_r3 = fn_802E2C20();
    if ((signed long)(temp_r3 - *(signed long*)(((signed char*)arg0) + 8)) <= 0x10) {
        return 0;
    }
    *(signed long*)(((signed char*)arg0) + 8) = temp_r3;
    return 1;
}
#pragma dont_inline reset

#pragma cplusplus on
extern "C" void fn_80207D8C(void* arg0) {
    class Item {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6(void*);
    };
    if (fn_80207D40(arg0) != 0) {
        fn_80207C80(arg0);
        ((Item*)*(void**)((char*)arg0 + 0x90))->f6((char*)arg0 + 0x5C);
    }
}
#pragma cplusplus reset
extern void fn_80207C80(void*);
extern void* lbl_802F9DC8[];
extern char lbl_8033BE20[];
#pragma cplusplus on
extern "C" void fn_80207DE0(void* arg0) {
    class Item {
    public:
        virtual void f2(signed long);
    };
    void* var_r28; void* var_r30; signed long var_r29; signed long var_r31;
    var_r31 = 0; var_r29 = 0; var_r28 = arg0; var_r30 = var_r28;
    while (var_r29 < *(signed long*)(((signed char*)var_r28) + 0x114)) {
        void** temp_r3 = (void**)((signed char*)var_r30 + 0x94);
        if (*temp_r3 != 0) {
            Item* obj = (Item*)*temp_r3;
            obj->f2(1);
        }
        *temp_r3 = (void*)var_r31;
        var_r30 = (void*)(((signed char*)var_r30) + 4);
        var_r29 += 1;
    }
    *(signed long*)(((signed char*)var_r28) + 0x114) = 0;
}
#pragma cplusplus reset
extern void* memmove(void*, const void*, unsigned long);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80207E70(void *arg0) {
    void *base = arg0;
    void *cur = base;
    void *src = (char *)base + 0x98;
    void *dst = (char *)base + 0x94;
    signed long i = 0;
    void *temp;
    void *sub;
    signed long n;
    while (i < *(signed long *)((char *)base + 0x114)) {
        temp = *(void **)((char *)cur + 0x94);
        sub = *(void **)((char *)temp + 0xC);
        if (((LoopItem_80207E70 *)sub)->f7() == 3) {
            temp = *(void **)((char *)cur + 0x94);
            if (temp != 0)
                ((LoopItem_80207E70 *)temp)->f0(1);
            n = *(signed long *)((char *)base + 0x114) - 1;
            *(signed long *)((char *)base + 0x114) = n;
            memmove(dst, src, (unsigned long)(n - i) * 4);
        } else {
            cur = (char *)cur + 4;
            src = (char *)src + 4;
            dst = (char *)dst + 4;
            i++;
        }
    }
}

#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" signed long fn_8020815C(void *arg0) {
    struct Obj {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual signed long check();
    };
    register signed long offset;
    register signed long limit;
    register signed long matches;
    register signed long i;
    void *entry;
    void *owner;

    limit = *(signed long *)((char *)&lbl_802F9DC8 +
             (signed long)fn_802090B4() * 0x2C);
    matches = 0;
    i = 0;
    offset = 0;
    while (i < *(signed long *)((char *)arg0 + 0x10)) {
        entry = *(void **)((char *)*(void ***)((char *)arg0 + 0xC) + offset);
        owner = *(void **)((char *)entry + 0xC);
        if (((Obj *)owner)->check() == 1) matches++;
        offset += 4;
        i++;
    }
    if (matches > limit) fn_802E317C(lbl_8033BE20, matches, limit);
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
signed long fn_8020820C(SoundMgrObj* arg0, SoundMgrObj* arg1) {
    float rhs = arg1->field_68;
    float lhs = arg0->field_68;
    unsigned long greater = lhs > rhs;
    signed long type = arg0->field_44;
    if (type == arg1->field_44 && (unsigned long)(type - 3) <= 1) {
        signed long id = fn_8026A344(0);
        signed long other = id == arg1->field_10;
        return id == arg0->field_10 || (!other && greater);
    }
    return greater;
}

#pragma push
#pragma inline_depth(0)
void fn_802082C0(void *arg0, void *arg1) {
    register signed long *source;
    register signed long *target;
    register signed long count;
    register signed long *base;
    register signed long i;
    register signed long value;
    register signed long j;
    register signed long outerOffset;

    base = *(signed long **)arg1;
    i = 1;
    count = *(signed long *)((char *)arg1 + 4);
    outerOffset = 4;
    source = (signed long *)((char *)base + 4);

    goto outer_check;
outer:
    value = *source;
    j = i;
    target = (signed long *)((char *)base + outerOffset);
    goto inner;
inner:
    *target = target[-1];
    j--;
    target--;
    if (j > 0 &&
        fn_8020820C((SoundMgrObj *)value, (SoundMgrObj *)target[-1]) != 0)
        goto inner;
    base[j] = value;
    source++;
    i++;
    outerOffset += 4;
outer_check:
    if (i < count)
        goto outer;
}

#pragma cplusplus reset
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern char lbl_8033BE50[];
extern char lbl_8033BE70[];
#pragma cplusplus reset
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
signed long fn_8020835C(void *arg0) {
    register char *ptr;
    register signed long i;

    i = 0;
    ptr = (char *)arg0 + 0x14;
    do {
        switch (i) {
        case 0:
        case 1:
        case 2:
        case 7:
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            fn_802082C0(arg0, ptr);
            break;
        default:
            fn_802E317C(lbl_8033BE50, lbl_8033BE70, 0x265, fn_80206570(i));
            break;
        }
        i++;
        ptr += 8;
    } while (i < 9);
}
#pragma pop

#pragma pop
void fn_80208404(void) {

}

void fn_802085E8(void) {
	((void (*)(void))fn_80208408)();
}

void fn_80208994(void) {
	((void (*)(void))fn_80208858)();
}

void fn_80208998(void) {
	((void (*)(void))fn_80208858)();
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020899C(void* arg0, void* arg1) {
    struct Obj {
        virtual void v0();
        virtual void v1();
    };
    ((Obj*)arg1)->v1();
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma cplusplus on
extern "C" void fn_802089B0(void* self) {
    class Obj {
    public:
        virtual void f(int);
    };
    if (self == 0) {
        return;
    }
    ((Obj*)self)->f(1);
}
#pragma cplusplus reset
#pragma pop
signed long fn_802089D0(signed long arg0, signed long arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        fn_80128668();
    }
    return arg0;
}

void fn_802085EC(void) {
	((void (*)(void))fn_80208408)();
}

signed long fn_802085F0(void* arg0, signed long x) {
    switch (x) {
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            return 1;
        default:
            return 0;
    }
}

extern char lbl_8033BE80[];
void fn_80208620(void* arg0, void* arg1) {
    signed long index = *(signed long*)((char*)arg1 + 0x44);
    void* entry = (char*)arg0 + index * 8;
    void* found = 0;
    signed long i = 0;
    signed long offset = 0;
    signed long count = *(signed long*)((char*)entry + 0x18);
    while (i < count) {
        if (*(void**)((char*)*(void**)((char*)entry + 0x14) + offset) == arg1) {
            found = (char*)*(void**)((char*)entry + 0x14) + i * 4;
            break;
        }
        offset += 4;
        i++;
    }
    if (found != 0) {
        *(signed long*)((char*)arg0 + 0x10) -= 1;
        *(signed long*)((char*)entry + 0x18) -= 1;
        memmove(found, (char*)found + 4, (unsigned long)(*(signed long*)((char*)arg0 + 0x10) - ((signed long)((char*)found - *(char**)((char*)arg0 + 0xC)) / 4)) * 4);
        index += 1;
        if (index < 9) {
            do {
                *(signed long*)((char*)arg0 + index * 8 + 0x14) -= 4;
                index++;
            } while (index < 9);
        }
    } else {
        fn_802E317C(lbl_8033BE80, (char*)arg1 + 0x37);
    }
}
#pragma cplusplus on
struct Dummy80208858 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void *get();
    virtual void v5();
    virtual void v6();
    virtual int invoke(int, int, int);
};
#pragma cplusplus reset
