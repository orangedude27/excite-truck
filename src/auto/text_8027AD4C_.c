// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_804A4380[];
long fn_8000D984(long);
long fn_8027B8E4(void *, long);
void *fn_8027B834(void *);
void fn_8027B984(void *, long);
long fn_8027BAB8(void *);
void fn_8027AF94(void *);
void fn_8027B288(void *);
long fn_80131818(long);
long fn_8027D1F4(void);
long fn_8000DA10(void);
void *fn_8001BB58(long, long, long, long);
long fn_801284F8(long, char *);
long fn_8027C41C(long);
long fn_8027C4B4(long, long);
extern long lbl_8055F658;
extern char lbl_80347AB0[];
long fn_8001D884(void *, long);
long fn_8001DA48(void *, long);
long fn_80205268(char *, long, long);
extern char lbl_80347B68[];
extern char lbl_80347BD0[];

extern char lbl_80347B78[];
extern char lbl_80347C14[];
extern char lbl_80347C38[];
extern char *fn_80131234(char *);
long fn_8027CB28(void);
extern long lbl_8055F654;
long fn_8027C1C8(void *, const char *);
void *fn_8027C258(void *, long);
long *fn_8027C26C(void *, const char *);
long fn_8027C788(void *);
long *fn_8027C120(long, long);
long fn_8027C8B0(void);
void fn_802E317C(char *, long);
extern unsigned char lbl_8055F650;
long fn_80019B3C(void);
extern char lbl_80347A5C[];
extern char lbl_8055C758[];
extern char lbl_8055C770[];
long fn_80012854(void);
void *fn_8001285C(long);
int stricmp(const char *, const char *);

extern char lbl_804A4380[];
unsigned char fn_8027AF84(void *arg0) {
    return *((unsigned char *)arg0 + 0x11);
}

#pragma dont_inline on
unsigned char fn_8027AF8C(void *arg0) { return *((unsigned char *)arg0 + 0x10); }
void fn_8027AF94(void *arg0) { ((unsigned char *)arg0)[4] = 0; }

unsigned char fn_8027B280(void *arg0) {
    return *((unsigned char *)arg0 + 0x12);
}

void fn_8027B288(void *arg0) {
    long offset = 0, i = 0;
    goto test;
body:
    fn_8027AF94((char *)*(void **)((char *)arg0 + 0x18) + offset);
    offset += 0x3C;
    i++;
test:
    if (i < *(long *)((char *)arg0 + 0x1C)) goto body;
    *(long *)((char *)arg0 + 0x1C) = 0;
    *(long *)((char *)arg0 + 0x10) = 0;
}

#pragma cplusplus on
struct NameObject {
    virtual char *name();
};
class Fn8027CFB4List {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual long lookup(long);
};
#pragma cplusplus reset
extern long fn_80131810(long *);
extern long fn_8027AFA0(void *, void *, void *);
extern int strcmp(const char *, const char *);
extern int lbl_8055C760;
void fn_8027B2F8(long arg0, long *arg1, signed char arg2) {
    register char *self = (char *)arg0;
    long i;
    void *item;

    ((char *)arg0)[0xBCC] = arg2;
    *(void **)(self + 4) = (void *)fn_80131810(arg1);
    if (*(void **)(self + 4) == 0)
        return;
    i = 0;
    goto next_item;

process_item:
    if (strcmp(((char *(*)(void *))(*(void ***)item)[2])(item),
               (char *)&lbl_8055C760) == 0) {
        long count = *(volatile long *)(self + 0xC);
        char *base = *(char **)(self + 8);
        char *record = base + count * 0x1F4;
        *(volatile long *)(self + 0xC) = count + 1;
        if (fn_8027AFA0(record, item, base) == 0) {
            long index = *(volatile long *)(self + 0xC) - 1;
            if (index >= 0) {
                long count2 = *(volatile long *)(self + 0xC);
                if (index < count2) {
                    long last = *(volatile long *)(self + 0xC) - 1;
                    if (index != last) {
                        char *base2 = *(char **)(self + 8);
                        char *dst = base2 + index * 0x1F4;
                        char *src = base2 + last * 0x1F4;
                        long j;
                        long offset;
                        dst[4] = src[4];
                        *(long *)(dst + 8) = *(long *)(src + 8);
                        *(long *)(dst + 0xC) = *(long *)(src + 0xC);
                        *(long *)(dst + 0x10) = *(long *)(src + 0x10);
                        *(long *)(dst + 0x14) = *(long *)(src + 0x14);
                        if (dst + 0x18 != src + 0x18) {
                            long len = *(long *)(src + 0x1C);
                            long cap = *(long *)(dst + 0x20);
                            if (cap < len) {
                                *(long *)(dst + 0x1C) = cap;
                                offset = 0;
                                j = 0;
                                do {
                                    char *sbase;
                                    char *dbase;
                                    char *s;
                                    char *d;
                                    sbase = *(char **)(src + 0x18);
                                    j++;
                                    dbase = *(char **)(dst + 0x18);
                                    s = sbase + offset;
                                    d = dbase + offset;
                                    d[4] = s[4];
                                    *(long *)(d + 8) = *(long *)(s + 8);
                                    *(long *)(d + 0xC) = *(long *)(s + 0xC);
                                    d[0x10] = s[0x10]; d[0x11] = s[0x11]; d[0x12] = s[0x12];
                                    {
                                        long w14 = *(long *)(s + 0x14);
                                        long w18 = *(long *)(s + 0x18);
                                        *(long *)(d + 0x14) = w14;
                                        *(long *)(d + 0x18) = w18;
                                    }
                                    {
                                        long w1c = *(long *)(s + 0x1C);
                                        long w20 = *(long *)(s + 0x20);
                                        *(long *)(d + 0x1C) = w1c;
                                        *(long *)(d + 0x20) = w20;
                                    }
                                    *(long *)(d + 0x24) = *(long *)(s + 0x24);
                                    *(long *)(d + 0x28) = *(long *)(s + 0x28);
                                    *(long *)(d + 0x2C) = *(long *)(s + 0x2C);
                                    *(long *)(d + 0x30) = *(long *)(s + 0x30);
                                    *(long *)(d + 0x34) = *(long *)(s + 0x34);
                                    d[0x38] = s[0x38];
                                    offset += 0x3C;
                                } while (j < *(long *)(dst + 0x1C));
                            }
                        }
                        {
                            char *d = dst + 0x24;
                            char *s = src + 0x24;
                            char *end = dst + 0x18C;
                            do {
                                d[4] = s[4];
                                *(long *)(d + 8) = *(long *)(s + 8);
                                *(long *)(d + 0xC) = *(long *)(s + 0xC);
                                d[0x10] = s[0x10]; d[0x11] = s[0x11]; d[0x12] = s[0x12];
                                *(long *)(d + 0x14) = *(long *)(s + 0x14);
                                *(long *)(d + 0x18) = *(long *)(s + 0x18);
                                *(long *)(d + 0x1C) = *(long *)(s + 0x1C);
                                *(long *)(d + 0x20) = *(long *)(s + 0x20);
                                *(long *)(d + 0x24) = *(long *)(s + 0x24);
                                *(long *)(d + 0x28) = *(long *)(s + 0x28);
                                *(long *)(d + 0x2C) = *(long *)(s + 0x2C);
                                *(long *)(d + 0x30) = *(long *)(s + 0x30);
                                *(long *)(d + 0x34) = *(long *)(s + 0x34);
                                d[0x38] = s[0x38];
                                d += 0x3C;
                                s += 0x3C;
                            } while (d < end);
                        }
                        {
                            char *d = dst + 0x18B;
                            char *s = src + 0x18B;
                            j = 0x32;
                            do {
                                d[1] = s[1];
                                d[2] = s[2];
                                d += 2;
                                s += 2;
                            } while (--j != 0);
                        }
                        dst[0x1F0] = src[0x1F0]; dst[0x1F1] = src[0x1F1];
                        dst[0x1F2] = src[0x1F2]; dst[0x1F3] = src[0x1F3];
                    }
                    *(volatile long *)(self + 0xC) = *(volatile long *)(self + 0xC) - 1;
                }
            }
        }
    }
advance_item:
    i++;
next_item:
    item = ((void *(*)(void *, long))(*(void ***)*(void **)(self + 4))[3])
           (*(void **)(self + 4), i);
    if (item != 0)
        goto process_item;
    if (*(volatile long *)(self + 0xC) > 0)
        return;
    fn_80131818(*(long *)(self + 4));
    *(void **)(self + 4) = 0;
}

void fn_8027B60C(void *arg0) {
    long i, offset;
    if (*(long *)((char *)arg0 + 4) != 0) {
        i = 0; offset = 0;
        do {
            fn_8027B288((char *)*(void **)((char *)arg0 + 8) + offset);
            offset += 0x1F4; i++;
        } while (i < *(long *)((char *)arg0 + 0xC));
        offset = 0;
        *(long *)((char *)arg0 + 0xC) = 0;
        fn_80131818(*(long *)((char *)arg0 + 4));
        *(long *)((char *)arg0 + 4) = 0;
    }
}

void fn_8027B77C(void) {
    char *base, *p;
    long outer, i;
    if (fn_80019B3C() == 0 || lbl_8055F650 != 0) {
        base = lbl_804A4380;
        outer = 0;
        do {
            p = base; i = 0;
            do { fn_8027B60C(p); i++; p += 0xBD0; } while (i < 3);
            p = base + 0x2370; i = 0;
            do { fn_8027B60C(p); i++; p += 0xBD0; } while (i < 2);
            outer++; base += 0x3B10;
        } while (outer < 4);
        lbl_8055F650 = 0;
    }
}

#pragma dont_inline reset
void *fn_8027B878(long arg0) {
    return lbl_804A4380 + fn_8000DA10() * 0x3B10 + arg0 * 0xBD0 + 0x2370;
}

void fn_8027B8C0(void* alarm) {
    fn_8027BA24(fn_8027B834(alarm));
}

void fn_8027B94C(void *arg0) {
    fn_8027B8E4(arg0, fn_8000DA10());
}

#pragma dont_inline on
void fn_8027B984(void *arg0, long arg1) {
    long temp_r30;
    long temp_r31;

    temp_r31 = fn_8000DA10();
    fn_8000D984(arg1);
    temp_r30 = fn_8027BAB8(fn_8027B878((long)arg0));
    fn_8000D984(temp_r31);
}
#pragma dont_inline reset

void fn_8027B9EC(void *arg0) {
    fn_8027B984(arg0, fn_8000DA10());
}

long fn_8027BAB8(void *arg0) {
    long i;
    for (i = 0; i < ((long (*)(void *))(*(void ***)arg0)[3])(arg0); i++) {
        void *item = ((void *(*)(void *, long))(*(void ***)arg0)[4])(arg0, i);
        if (((long (*)(void *))(*(void ***)item)[10])(item) == 0) return 0;
    }
    return 1;
}

long fn_8027BB4C(long, long, long, long);
void fn_8027BCC0(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 0);
}

void fn_8027BCC8(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 1);
}

void fn_8027BCD0(void *arg0, long arg1) {
    long outer, inner, item, i, j, k, n, found;
    void *group, *entry, *object, *base, *record;
    outer = 0;
    do {
        group = fn_8027B834((void *)outer);
        for (inner = 0; inner < ((long (*)(void *))(*(void ***)group)[3])(group); inner++) {
            entry = ((void *(*)(void *, long))(*(void ***)group)[4])(group, inner);
            for (item = 0; item < ((long (*)(void *))(*(void ***)entry)[6])(entry); item++) {
                object = ((void *(*)(void *, long))(*(void ***)entry)[7])(entry, item);
                n = ((long (*)(void *))(*(void ***)object)[8])(object);
                found = -1;
                for (i = 0; i < *(long *)((char *)arg0 + 4); i++) {
                    if (*(long *)((char *)*(void **)arg0 + i * 0x18) == n) {
                        found = i;
                        break;
                    }
                }
                if (found == -1) {
                    base = *(void **)arg0;
                    i = *(long *)((char *)arg0 + 4);
                    *(long *)((char *)arg0 + 4) = i + 1;
                    record = (char *)base + i * 0x18;
                    *(long *)((char *)record + 0) = ((long (*)(void *, long, long))(*(void ***)object)[8])(object, i, (long)base);
                    *(long *)((char *)record + 4) = ((long (*)(void *))(*(void ***)entry)[3])(entry);
                    *(long *)((char *)record + 8) = inner;
                    *(long *)((char *)record + 0xC) = ((long (*)(void *))(*(void ***)object)[3])(object);
                    *(long *)((char *)record + 0x10) = ((long (*)(void *))(*(void ***)object)[7])(object);
                    *(unsigned char *)((char *)record + 0x14) =
                        ((long (*)(void *))(*(void ***)entry)[9])(entry) &&
                        ((long (*)(void *))(*(void ***)object)[17])(object);
                    *(unsigned char *)((char *)record + 0x15) = ((long (*)(void *))(*(void ***)entry)[11])(entry);
                } else {
                    record = (char *)*(void **)arg0 + found * 0x18;
                    *(unsigned char *)((char *)record + 0x14) =
                        *(unsigned char *)((char *)record + 0x14) ||
                        (((long (*)(void *))(*(void ***)entry)[9])(entry) &&
                         ((long (*)(void *))(*(void ***)object)[17])(object));
                }
            }
        }
        outer++;
    } while (outer < 3);
}

extern long fn_80012790(long);
extern long fn_80012794(void);
extern long fn_80012810(void);
extern long fn_8001683C(long, long);
extern long fn_80016A44(long);
extern long fn_8001BBB4(long, long, void *, long, long, float);
extern long fn_80012854(void);
extern float lbl_805641F0;
extern char lbl_8055C768[];
void fn_8027BF38(void) {
    long j, i, state, now;
    state = fn_80012810();
    if (state != 0x130) {
        if (state != 0x134) {
            fn_80012794();
            fn_80012790(0x130);
        }
    }
    fn_8001683C(0, 0);
    j = 0;
    while (j < 3) {
        i = 0;
        while (i < fn_80012854()) {
            ((long (*)(float, long, long, long, long, long, long))fn_8001BBB4)(
                lbl_805641F0, fn_8000DA10(), i, j, (long)lbl_8055C768, 0x1F4, 0);
            i++;
        }
        j++;
    }
    fn_80016A44(0);
    now = fn_80012810();
    if (state != now) {
        if (now != 0x134)
            fn_80012794();
        if (state != 0x134)
            fn_80012790(state);
    }
}

void fn_8027C014(void *arg0, long arg1, long arg2, void *arg3) {
    long i;
    void *p, *q;
    *(long *)arg0 = arg1;
    *(char **)((char *)arg0 + 4) = lbl_80347A5C;
    *(long *)((char *)arg0 + 8) = arg2;
    *(void ***)((char *)arg0 + 0x10) = arg3;
    *(char **)((char *)arg0 + 0xC) =
       (*(char *(**)(void *, char **))(*(void ***)arg3)[5])(arg3, (char **)&lbl_80347A5C);
    i = 0;
    do {
        p = fn_8001285C(i);
        q = *(void ***)((char *)p + 0x20);
        if (stricmp((*(char *(**)(void *, char *, char *))(*(void ***)q)[6])(q, lbl_8055C758, lbl_8055C770),
                    *(char **)((char *)arg0 + 0xC)) == 0)
            *(void **)((char *)arg0 + 4) = *(void **)p;
        i++;
    } while (i < fn_80012854());
}

extern char lbl_80347B30[];
void fn_8027C0D0(void *arg0, long arg1, void **arg2) {
    void **vtable;
    long (*method)(void *, char **);
    *(long *)arg0 = arg1;
    *(long *)((char *)arg0 + 8) = (long)arg2;
    vtable = *(void ***)arg2;
    method = (long (*)(void *, char **))vtable[5];
    *(long *)((char *)arg0 + 4) = method(arg2, (char **)&lbl_80347B30);
}
long *fn_8027C120(long arg0, long arg1) {
    long index = 0;
    long offset = 0;
    while (index < *(long *)(arg0 + 4)) {
        if (stricmp((char *)arg1, *(char **)(*(long *)arg0 + offset + 0xC)) == 0)
            break;
        offset += 0x14;
        index++;
    }
    if (index >= *(long *)(arg0 + 4))
        index = -1;
    if (index < 0)
        return 0;
    return (long *)(*(long *)arg0 + index * 0x14);
}

long fn_8027C1C8(void *arg0, const char *arg1) {
    long index = 0;
    long offset = 0;
    while (index < *(long *)((char *)arg0 + 0xAF10)) {
        if (stricmp(arg1, *(char **)((char *)arg0 + 0xAF0C + offset + 4)) == 0)
            break;
        offset += 0xC;
        index++;
    }
    if (index >= *(long *)((char *)arg0 + 0xAF10))
        index = -1;
    return index;
}

void *fn_8027C258(void *arg0, long arg1) {
    return (char *)*(void **)((char *)arg0 + 0xAF0C) + arg1 * 0xC;
}

long *fn_8027C26C(void *arg0, const char *arg1) {
    long index = fn_8027C1C8(arg0, arg1);
    if (index < 0)
        return 0;
    return *(long **)((char *)arg0 + 0xAF0C) + index * 0xC;
}

#pragma push
#pragma use_lmw_stmw off
long fn_8027C4B4(long arg0, long arg1) {
    long offset;
    long i;
    long zero;
    if (arg0 != 0) {
        *(long *)(arg0 + 4) = 0;
        i = 0;
        *(long *)(arg0 + 0xAF10) = 0;
        offset = 0;
        while (i < *(long *)(arg0 + 0xB00C)) {
            fn_80131818(*(long *)(*(long *)(arg0 + 0xB008) + offset));
            offset += 4;
            i++;
        }
        zero = 0;
        if ((void *)(arg0 + 0xB008) != 0) {
            *(long *)(arg0 + 0xB00C) = zero;
            if ((void *)(arg0 + 0xB008) != 0) {
                *(long *)(arg0 + 0xB008) = zero;
                *(long *)(arg0 + 0xB00C) = zero;
                *(long *)(arg0 + 0xB010) = zero;
            }
        }
        if ((void *)(arg0 + 0xAF0C) != 0) {
            if ((void *)(arg0 + 0xAF0C) != 0) {
                *(long *)(arg0 + 0xAF0C) = zero;
                *(long *)(arg0 + 0xAF10) = zero;
                *(long *)(arg0 + 0xAF14) = zero;
            }
        }
        if (arg0 != 0) {
            if (arg0 != 0) {
                *(long *)arg0 = zero;
                *(long *)(arg0 + 4) = zero;
                *(long *)(arg0 + 8) = zero;
            }
        }
        if (arg1 > 0) fn_80128668((void *)arg0);
    }
    return arg0;
}
#pragma pop
void fn_8027C59C(long arg0) {
    long value;

    if (lbl_8055F654 == 0) {
        value = fn_801284F8(0xB020, lbl_80347B68);
        if (value != 0)
            value = ((long (*)(long, long))fn_8027C41C)(value, arg0);
        lbl_8055F654 = value;
        lbl_8055F658 = 1;
    } else {
        lbl_8055F658 += 1;
    }
}

void fn_8027C610(void) {
    long value = lbl_8055F658 - 1;
    lbl_8055F658 = value;
    if (value == 0) {
        fn_8027C4B4(lbl_8055F654, 1);
        lbl_8055F654 = 0;
    }
}

long fn_8027C71C(void *arg0) {
    long value;
    void *result;
    long flag;

    value = fn_8027D1F4();
    result = fn_8001BB58(fn_8000DA10(), *(long *)((char *)arg0 + 4), value, 0);
    flag = 0;
    if (result != 0 && *(long *)((char *)result + 8) == 0) {
        flag = 1;
    }
    return flag;
}

long fn_8027C650(void);
extern char lbl_80347A50[];
#pragma dont_inline on
long fn_8027C788(void *arg0) {
    void *item;
    long index = 0;
    char *name;
    long value;
    goto fetch;
body:
    name = ((char *(*)(void *))(*(void ***)item)[2])(item);
    if (stricmp(name, lbl_80347A50) == 0) {
        value = ((long (*)(void *, char *))(*(void ***)item)[5])(item, lbl_80347A5C);
        fn_8027C120(lbl_8055F654, value);
        if (fn_8027C650() == 0)
            return 0;
    }
    index++;
fetch:
    item = ((void *(*)(void *, long))(*(void ***)*(void **)((char *)arg0 + 8))[24])(*(void **)((char *)arg0 + 8), index);
    if (item != 0)
        goto body;
    return 1;
}

long fn_8027C850(void *arg0) {
    long index;

    index = fn_8027C1C8((void *)lbl_8055F654, *(char **)((char *)arg0 + 4));
    if (index == 0)
        return 1;
    return fn_8027C788(fn_8027C26C((void *)lbl_8055F654,
        *(char **)((char *)fn_8027C258((void *)lbl_8055F654, index - 1) + 4)));
}

long fn_8027C8B0(void) { return 1; }

long fn_8027CA1C(void *arg0) {
    long temp_r30;
    long var_r31;
    void *temp_r3;

    temp_r30 = fn_8027D1F4();
    fn_8000DA10();
    temp_r3 = fn_8001BB58(0, *(long *)((char *)arg0 + 4), temp_r30, 0);
    var_r31 = 0;
    if (temp_r3 != 0) {
        (*(void (**)(void *, char *))(*(void ***)*(void **)((char *)arg0 + 0x10))[5])(*(void **)((char *)arg0 + 0x10), lbl_80347BD0);
        if (*(long *)((char *)temp_r3 + 8) <= fn_8001D7EC())
            var_r31 = 1;
    }
    return var_r31;
}

long fn_8027CAB4(void *arg0) {
    long value;
    void *result;
    long flag;

    value = fn_8027D1F4();
    result = fn_8001BB58(fn_8000DA10(), *(long *)((char *)arg0 + 4), value, 0);
    flag = 0;
    if (result != 0 && *(long *)((char *)result + 8) == 0) {
        flag = 1;
    }
    return flag;
}

long fn_8027CB20(void) { return 1; }

long fn_8027CBF0(void) { return 1; }

void fn_8027CBF8(long arg0, char *arg1, long arg2) {
    long count;
    char *src;
    char c;

    count = arg2;
    if (fn_8027CB28()) {
        src = fn_80131234(lbl_80347B78);
        count--;
        if (count > 0)
            goto copy_a;
        goto terminate_a;
copy_a:
        c = *src++;
        *arg1++ = c;
        if ((signed char)c == 0)
            goto finish_a;
        count--;
        if (count > 0)
            goto copy_a;
terminate_a:
        arg1[-1] = 0;
finish_a:
        ;
    } else {
        src = fn_80131234(lbl_80347C14);
        count--;
        if (count > 0)
            goto copy_b;
        goto terminate_b;
copy_b:
        c = *src++;
        *arg1++ = c;
        if ((signed char)c == 0)
            goto finish_b;
        count--;
        if (count > 0)
            goto copy_b;
terminate_b:
        arg1[-1] = 0;
finish_b:
        ;
    }
}

extern long lbl_80347B4C;
#pragma use_lmw_stmw off
__declspec(section ".rodata") extern long lbl_80347B4C;
#pragma use_lmw_stmw off
void fn_8027CCB4(long arg0, long arg1, long arg2, long arg3) {
    long temp_r3;
    long temp_r3_2;
    long temp_r3_3;
    temp_r3 = fn_80012810();
    if (temp_r3 != 0x130) {
        if (temp_r3 != 0x134) fn_80012794();
        fn_80012790(0x130);
    }
    temp_r3_2 = fn_8000DA10();
    if (temp_r3_2 != arg1) fn_8000D984(arg1);
    fn_8027C59C(arg2);
    fn_8027B2F8(arg0, &lbl_80347B4C, 1);
    if (temp_r3_2 != arg1) fn_8000D984(temp_r3_2);
    fn_8027C610();
    temp_r3_3 = fn_80012810();
    if (temp_r3 != temp_r3_3) {
        if (temp_r3_3 != 0x134) fn_80012794();
        if (temp_r3 != 0x134) fn_80012790(temp_r3);
    }
}

extern long lbl_80347B5C;
#pragma use_lmw_stmw off
__declspec(section ".rodata") extern long lbl_80347B5C;
#pragma use_lmw_stmw off
void fn_8027CD80(long arg0, long arg1, long arg2, long arg3) {
    long temp_r3;
    long temp_r3_2;
    long temp_r3_3;
    temp_r3 = fn_80012810();
    if (temp_r3 != 0x130) {
        if (temp_r3 != 0x134) fn_80012794();
        fn_80012790(0x130);
    }
    temp_r3_2 = fn_8000DA10();
    if (temp_r3_2 != arg1) fn_8000D984(arg1);
    fn_8027C59C(arg2);
    fn_8027B2F8(arg0, &lbl_80347B5C, 1);
    if (temp_r3_2 != arg1) fn_8000D984(temp_r3_2);
    fn_8027C610();
    temp_r3_3 = fn_80012810();
    if (temp_r3 != temp_r3_3) {
        if (temp_r3_3 != 0x134) fn_80012794();
        if (temp_r3 != 0x134) fn_80012790(temp_r3);
    }
}

#pragma scheduling invalid_target
long fn_8027CE4C(long arg0) {
    int value = *fn_8027C120(lbl_8055F654, arg0);
    switch (value) {
    case 0:
        return fn_8027C8B0();
    case 1:
        return fn_8027CB20();
    default:
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347C38, arg0);
        return 1;
    }
}
#pragma scheduling reset
long fn_8027CFB4(long arg0) {
    long *obj = fn_8027C120(lbl_8055F654, arg0);
    long id = fn_80205268(lbl_80347AB0, *(long *)((char *)&lbl_8055F654 + 0xB01C), -1);
    void *manager = fn_8001285C(*(long *)((char *)obj + 4));
    void *list = *(void **)((char *)manager + 0x20);
    long result;
    long i = 0;
    fn_8001D884(&result, ((long (*)(void *, long))(*(void ***)list)[0x17])(list, id));
    do {
        long found = fn_8001DA48(&result, i);
        if (found >= 0)
            return found;
        i++;
    } while (i < 5);
    return 0;
}

#pragma scheduling invalid_target
void fn_8027D158(long arg0, char *arg1, long arg2) {
    long *result = fn_8027C26C((void *)lbl_8055F654, (const char *)arg0);
    register long status = *result;
    switch (status) {
    case 0:
        fn_8027C8B8((long)result, arg1, arg2);
        break;
    case 1:
        fn_8027CBF8((long)result, arg1, arg2);
        break;
    default:
        ((void (*)(char *, ...))fn_802E317C)(lbl_80347C38, arg0);
        break;
    }
}
#pragma scheduling on
long fn_8027D1F4(void) {
    return *(long *)((char *)lbl_8055F654 + 0xB01C);
}

