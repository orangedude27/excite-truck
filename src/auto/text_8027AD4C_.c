// Code of main that had no source file yet: decomp.wtf gave it this one.
 // split_file divides it into the game's real files (file_status shows its range).
 
 extern char lbl_804A4380[];
extern long fn_80012790(long);
extern long fn_80012794(void);
extern long fn_80012810(void);
extern void fn_8027CCB4(long, long, long, long);
extern void fn_8027CD80(long, long, long, long);
__declspec(section ".rodata") extern long lbl_80347B4C;
__declspec(section ".rodata") extern long lbl_80347B5C;
long fn_8000D984(long);
long fn_8027B8E4(void *, long);
void *fn_8027B834(void *);
long fn_8027B984(void *, long);
long fn_8027BA24(void *);
long fn_8027BAB8(void *);
void fn_8027AF94(void *);
void fn_8027B288(void *);
long fn_80131818(long);
long fn_8027D1F4(void);
extern int fn_80204BB4(const char *);
extern long fn_8027D0E0(long);
extern long fn_8027D068(long);
extern void fn_8027D158(long, char *, long);
long fn_8000DA10(void);
void *fn_8001BB58(long, long, long, long);
long fn_801284F8(long, char *);
void *fn_8027C41C(void *, long);
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
extern char lbl_80347C70[];
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
extern char lbl_8055C758;
extern char lbl_8055C770;
long fn_80012854(void);
void *fn_8001285C(long);
int stricmp(const char *, const char *);
extern void fn_802E30C8(const char *, ...);
extern void fn_8001D8B4(void *, long);
extern long fn_8027CEC4(long);
extern long fn_8027CF3C(long);
extern long fn_8027CE4C(long);
extern long fn_8027CFB4(long);

extern char lbl_804A4380[];
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" unsigned char fn_8027AD4C(char *a0, void *arg1) {
    extern char lbl_80347A50[];
    class First {
    public:
        virtual char *m0();
        virtual void m1();
        virtual void m2();
        virtual char *m3(const char *);
    };
    class Second {
    public:
        virtual void m0();
        virtual long m1(const char *);
        virtual void m2();
        virtual char *m3(const char *);
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual void m11();
        virtual void m12();
        virtual void m13();
        virtual void m14();
        virtual void m15();
        virtual void m16();
        virtual void m17();
        virtual void m18();
        virtual void m19();
        virtual void m20();
        virtual long m21(long);
    };
    char *base = lbl_80347A50;
    char *name;
    int found, i;
    void *res;

    *(void **)(a0 + 8) = arg1;
    *(unsigned char *)(a0 + 4) = 1;
    if (stricmp(((First *)arg1)->m0(), base) == 0) {
        name = ((First *)arg1)->m3(base + 0xC);
        *(long *)(a0 + 0x30) = fn_8027D1F4();
        found = 0;
        for (i = 0; i < fn_80012854(); i++) {
            char *p = (char *)fn_8001285C(i);
            if ((*(Second **)(p + 0x20))->m1(&lbl_8055C758) != 0) {
                if (stricmp((*(Second **)(p + 0x20))->m3(&lbl_8055C758), name) == 0) {
                    if (found != 0) {
                        fn_802E30C8(base + 0x1C, name);
                    } else {
                        long id, r, key;
                        key = *(long *)p;
                        found = 1;
                        *(long *)(a0 + 0xC) = key;
                        id = fn_80205268(base + 0x60, *(long *)(a0 + 0x30), key);
                        r = (*(Second **)(p + 0x20))->m21(id);
                        if ((((unsigned long)(-r | r)) >> 31) != 0) {
                            fn_8001D8B4(a0 + 0x14, (*(Second **)(p + 0x20))->m21(id));
                        } else {
                            fn_802E30C8(base + 0x6C, name, id);
                        }
                    }
                }
            }
        }
        if (found == 0) {
            ((void (*)(char *, ...))fn_802E317C)(base + 0x98, name);
            return 0;
        }
        *(long *)(a0 + 0x2C) = fn_8027CFB4((long)name);
        *(char *)(a0 + 0x10) = fn_8027CEC4((long)name);
        *(char *)(a0 + 0x11) = fn_8027CE4C((long)name);
        *(char *)(a0 + 0x12) = fn_8027CF3C((long)name);
        res = fn_8001BB58(fn_8000DA10(), *(long *)(a0 + 0xC), *(long *)(a0 + 0x30), 0);
        if (res != 0) {
            *(long *)(a0 + 0x34) = *(long *)((char *)res + 4);
            *(unsigned char *)(a0 + 0x38) = 1;
        } else {
            *(long *)(a0 + 0x34) = 0;
            *(unsigned char *)(a0 + 0x38) = 0;
        }
    } else {
        *(unsigned char *)(a0 + 4) = 0;
    }
    return *(unsigned char *)(a0 + 4);
}
#pragma cplusplus reset
#pragma pop
unsigned char fn_8027AF84(void *arg0) {
    return *((unsigned char *)arg0 + 0x11);
}

#pragma dont_inline on
unsigned char fn_8027AF8C(void *arg0) { return *((unsigned char *)arg0 + 0x10); }
void fn_8027AF94(void *arg0) { ((unsigned char *)arg0)[4] = 0; }

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" long fn_8027AFA0(void *self, void *arg1, void *unused) {
    extern char lbl_80347A50[];
    class Entry {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual long check();
    };
    class Source {
    public:
        virtual void v0();
        virtual long has(const char *);
        virtual void v2();
        virtual long get(const char *);
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21();
        virtual Entry *at(long);
    };
    char *a0 = (char *)self;
    char *base = lbl_80347A50;
    long rate;
    long i;
    Entry *obj;

    *(void **)(a0 + 8) = arg1;
    *(unsigned char *)(a0 + 4) = 1;
    if (arg1 != 0) {
        rate = 0;
        if (((Source *)arg1)->has(base + 0xCC) != 0) {
            rate = fn_80204BB4((const char *)((Source *)arg1)->get(base + 0xCC));
            if (fn_8027D1F4() < rate) {
                *(unsigned char *)(a0 + 4) = 0;
            }
        }
        if (*(unsigned char *)(a0 + 4) != 0) {
            *(long *)(a0 + 0x10) = ((Source *)arg1)->get(base + 0xE0);
            *(long *)(a0 + 0xC) = ((Source *)arg1)->get(base + 0xF0);
            *(long *)(a0 + 0x14) = fn_8027D1F4();
            i = 0;
            while ((obj = ((Source *)arg1)->at(i)) != 0) {
                long n = *(volatile long *)(a0 + 0x1C);
                char *list = *(char **)(a0 + 0x18);
                *(volatile long *)(a0 + 0x1C) = n + 1;
                if (((long (*)(char *, void *))fn_8027AD4C)(list + n * 0x3C, obj) == 0) {
                    long idx = *(volatile long *)(a0 + 0x1C) - 1;
                    if (idx >= 0) {
                        long cnt = *(volatile long *)(a0 + 0x1C);
                        if (idx < cnt) {
                            long last = cnt - 1;
                            if (idx != last) {
                                char *b = *(char **)(a0 + 0x18);
                                char *s = b + last * 0x3C;
                                char *d = b + idx * 0x3C;
                                d[4] = s[4];
                                *(long *)(d + 8) = *(long *)(s + 8);
                                *(long *)(d + 0xC) = *(long *)(s + 0xC);
                                d[0x10] = s[0x10];
                                d[0x11] = s[0x11];
                                d[0x12] = s[0x12];
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
                            }
                            *(volatile long *)(a0 + 0x1C) = *(volatile long *)(a0 + 0x1C) - 1;
                        }
                    }
                }
                i++;
            }
            if (*(long *)(a0 + 0x1C) > 0) {
                long c;
                *(char *)(a0 + 0x1F0) = fn_8027D0E0(*(long *)(a0 + 0x10));
                *(char *)(a0 + 0x1F1) = fn_8027D068(*(long *)(a0 + 0x10));
                i = 0;
                c = *(long *)(a0 + 0x1C);
                *(unsigned char *)(a0 + 0x1F2) = 1;
                if (c > 0) {
                    long off = 0;
                    do {
                        *(unsigned char *)(a0 + 0x1F2) =
                            (*(unsigned char *)(a0 + 0x1F2) & ((Entry *)(*(char **)(a0 + 0x18) + off))->check()) != 0;
                        off += 0x3C;
                        i++;
                    } while (i < *(long *)(a0 + 0x1C));
                }
                fn_8027D158(*(long *)(a0 + 0x10), a0 + 0x18C, 0x64);
                *(char *)(a0 + 0x1F3) = rate > 0;
            } else {
                *(unsigned char *)(a0 + 4) = 0;
            }
        }
    } else {
        *(unsigned char *)(a0 + 4) = 0;
    }
    return *(unsigned char *)(a0 + 4);
}
#pragma cplusplus reset
#pragma pop

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
    virtual void v20();
    virtual long lookup(long);
};
class Fn8027BA24Item {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual long valid();
};
class Fn8027BAB8Item {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual long valid();
};
class Fn8027BA24List {
public:
      virtual void v0();
      virtual long count();
      virtual Fn8027BA24Item *item(long);
  };
  class Fn8027C8B8Formatter {
  public:
      virtual void v0();
      virtual void v1();
      virtual void v2();
      virtual long format(const char *);
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

#pragma push
#pragma scheduling invalid_target
void fn_8027B60C(void *arg0) {
    int offset;
    int i;
    if (*(int *)((char *)arg0 + 4) != 0) {
        for (i = 0, offset = 0; i < *(int *)((char *)arg0 + 0xC); offset += 0x1F4, i++) {
            fn_8027B288((char *)*(void **)((char *)arg0 + 8) + offset);
        }
        offset = 0;
        *(int *)((char *)arg0 + 0xC) = 0;
        fn_80131818(*(int *)((char *)arg0 + 4));
        *(int *)((char *)arg0 + 4) = 0;
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_8027B690(void) {
    register long state;
    register long outer;
    register unsigned long inner;
    register char *base;
    register char *row;
    register long newState;

    state = fn_80012810();
    if (state != 0x130) {
        if (state != 0x134)
            fn_80012794();
        fn_80012790(0x130);
    }
    base = lbl_804A4380;
    outer = 0;
    do {
        row = base;
        inner = 0;
        do {
            ((void (*)(long, long, long))fn_8027CCB4)((long)row, outer, inner);
            row += 0xBD0;
            inner++;
        } while (inner < 3);
        row = base + 0x2370;
        inner = 0;
        do {
            ((void (*)(long, long, long))fn_8027CD80)((long)row, outer, inner);
            inner += 1;
            row += 0xBD0;
        } while (2 > inner);
        base += 0x3B10;
        outer += 1;
    } while (outer < 4);
    lbl_8055F650 = 1;
    newState = fn_80012810();
    if (state != newState) {
        if (newState != 0x134)
            fn_80012794();
        if (state != 0x134)
            fn_80012790(state);
    }
}
#pragma pop
void fn_8027B77C(void) {
    char *base;
    int outer;
    if (fn_80019B3C() == 0 || lbl_8055F650 != 0) {
        base = lbl_804A4380;
        outer = 0;
        do {
            {
                char *p = base;
                unsigned int i = 0;
                do {
                    fn_8027B60C(p);
                    i++;
                    p += 0xBD0;
                } while (i < 3);
            }
            {
                char *p = base + 0x2370;
                unsigned int i = 0;
                do {
                    fn_8027B60C(p);
                    i++;
                    p += 0xBD0;
                } while (i < 2);
            }
            outer++;
            base += 0x3B10;
        } while ((unsigned int)outer < 4);
        lbl_8055F650 = 0;
    }
}

void *fn_8027B834(void *arg0) {
    return lbl_804A4380 + fn_8000DA10() * 0x3B10 + (long)arg0 * 0xBD0;
}

#pragma scheduling on
#pragma pop

#pragma scheduling invalid_target
void *fn_8027B878(long arg0) {
    long a = fn_8000DA10() * 0x3B10;
    char *p = lbl_804A4380 + a;
    long b = arg0 * 0xBD0;
    p += b;
    p += 0x2370;
    return p;
}
#pragma scheduling on
void fn_8027B8C0(void* alarm) {
    fn_8027BA24(fn_8027B834(alarm));
}

#pragma dont_inline on
long fn_8027B8E4(void *arg0, long arg1) {
    long temp_r31;
    long temp_r30;
    temp_r31 = fn_8000DA10();
    fn_8000D984(arg1);
    temp_r30 = fn_8027BAB8(fn_8027B834(arg0));
    fn_8000D984(temp_r31);
    return temp_r30;
}
#pragma dont_inline reset

void fn_8027B94C(void *arg0) {
    fn_8027B8E4(arg0, fn_8000DA10());
}

#pragma dont_inline on
// Returns 1 if every entry of player `player`'s secondary list `listIndex`
// (the sub-table at +0x2370 within that player's block) is valid, else 0.
// Temporarily makes `player` the current player so the list pointer resolves
// against it, runs the validity check, then restores the previously current player.
long fn_8027B984(void *listIndex, long player) {
    long savedPlayer;
    long allValid;
    savedPlayer = fn_8000DA10();
    fn_8000D984(player);
    allValid = fn_8027BAB8(fn_8027B878((long)listIndex));
    fn_8000D984(savedPlayer);
    return allValid;
}
#pragma dont_inline reset

void fn_8027B9EC(void *arg0) {
    fn_8027B984(arg0, fn_8000DA10());
}

#pragma cplusplus on
extern "C" long fn_8027BA24(void *arg0) {
    long i = 0;
    while (i < ((Fn8027BA24List *)arg0)->count()) {
        if (((Fn8027BA24List *)arg0)->item(i)->valid() == 0)
            return 0;
        i++;
    }
    return 1;
}
#pragma cplusplus reset
#pragma cplusplus on
extern "C" long fn_8027BAB8(void *arg0) {
    long i = 0;
    while (i < ((Fn8027BA24List *)arg0)->count()) {
        if (((Fn8027BAB8Item *)((Fn8027BA24List *)arg0)->item(i))->valid() == 0)
            return 0;
        i++;
    }
    return 1;
}
#pragma cplusplus reset

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" long fn_8027BB4C(long arg0, long arg1, long arg2, long arg3) {
    /* Sum resource sizes for items in a two-level list: arg3 clamps each to loaded size (+4),
     * outputs accumulated sum to *arg1 and total item size to *arg2 when non-null. */
    class OuterList {
    public:
        virtual void v0();
        virtual long count();
        virtual void *item(long);
    };
    class InnerList {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual long count();
        virtual void *item(long);
    };
    class Item {
    public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual long id();
    };
    class SizedItem {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16();
        virtual long size();
    };
    long sum;
    long total;
    OuterList *outer;
    long outerIndex;
    InnerList *inner;
    long innerIndex;
    Item *item;
    long key;
    long size;
    long limit;
    void *resource;

    sum = 0;
    total = 0;
    outer = (OuterList *)fn_8027B834((void *)arg0);
    outerIndex = 0;
    while (outerIndex < outer->count()) {
        inner = (InnerList *)outer->item(outerIndex);
        innerIndex = 0;
        while (innerIndex < inner->count()) {
            item = (Item *)inner->item(innerIndex);
            key = item->id();
            resource = fn_8001BB58(fn_8000DA10(), key, arg0, 0);
            if (resource != 0) {
                if (arg3 != 0) {
                    size = ((SizedItem *)item)->size();
                    limit = *(long *)((char *)resource + 4);
                    if (size < limit) limit = size;
                    sum += limit;
                } else {
                    sum += *(long *)((char *)resource + 4);
                }
            }
            total += ((SizedItem *)item)->size();
            innerIndex++;
        }
        outerIndex++;
    }
    if (arg1 != 0) *(long *)arg1 = sum;
    if (arg2 != 0) *(long *)arg2 = total;
}
#pragma cplusplus reset
#pragma use_lmw_stmw on
#pragma pop

long fn_8027BB4C(long, long, long, long);
void fn_8027BCC0(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 0);
}

void fn_8027BCC8(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 1);
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8027BCD0(void *arg0, long arg1) {
    class Obj {
    public:
        virtual void m0();
        virtual long m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual long m5();
        virtual long m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual void m11();
        virtual void m12();
        virtual void m13();
        virtual void m14();
        virtual long m15();
    };
    class Entry {
    public:
        virtual void m0();
        virtual long m1();
        virtual void m2();
        virtual void m3();
        virtual long m4();
        virtual Obj *m5(long);
        virtual void m6();
        virtual long m7();
        virtual void m8();
        virtual long m9();
    };
    class Group {
    public:
        virtual void m0();
        virtual long m1();
        virtual Entry *m2(long);
    };
    char *a0 = (char *)arg0;
    long k;

    k = 0;
    do {
        Group *group = (Group *)fn_8027B834((void *)k);
        long j;
        for (j = 0; j < group->m1(); j++) {
            Entry *entry = group->m2(j);
            long i;
            for (i = 0; i < entry->m4(); i++) {
                Obj *obj = entry->m5(i);
                long key = obj->m6();
                long idx;
                char *rec;
                long flag;
                for (idx = 0; idx < *(long *)(a0 + 4); idx++) {
                    if (*(long *)(*(char **)a0 + idx * 0x18) != key)
                        continue;
                    goto found;
                }
                idx = -1;
            found:
                if (idx == -1) {
                    long cnt = *(long *)(a0 + 4);
                    rec = *(char **)a0 + cnt * 0x18;
                    *(long *)(a0 + 4) = cnt + 1;
                    *(long *)(rec + 0) = obj->m6();
                    *(long *)(rec + 4) = entry->m1();
                    *(long *)(rec + 8) = j;
                    *(long *)(rec + 0xC) = obj->m1();
                    *(long *)(rec + 0x10) = obj->m5();
                    flag = 0;
                    if (entry->m7() != 0) {
                        if (obj->m15() != 0)
                            flag = 1;
                    }
                    *(unsigned char *)(rec + 0x14) = flag;
                    *(unsigned char *)(rec + 0x15) = entry->m9();
                } else {
                    rec = *(char **)a0 + idx * 0x18;
                    flag = 0;
                    if (entry->m7() != 0) {
                        if (obj->m15() != 0)
                            flag = 1;
                    }
                    *(unsigned char *)(rec + 0x14) = ((*(unsigned char *)(rec + 0x14) | flag) != 0);
                }
            }
        }
        k++;
    } while (k < 3);
}
#pragma cplusplus reset
#pragma pop
extern long fn_80012790(long);
extern long fn_80012794(void);
extern long fn_80012810(void);
extern long fn_8001683C(long, long);
extern long fn_80016A44(long);
extern long fn_8001BBB4(long, long, void *, long, long, float);
extern long fn_80012854(void);
extern float lbl_805641F0;
extern char lbl_8055C768;
#pragma scheduling invalid_target
void fn_8027BF38(void) {
    long savedMode, row, col, currentMode;
    savedMode = fn_80012810();
    if (savedMode != 0x130) {
        if (savedMode != 0x134)
            fn_80012794();
        fn_80012790(0x130);
    }
    fn_8001683C(0, 0);
    row = 0;
    while (row < 3) {
        col = 0;
        while (col < fn_80012854()) {
            ((long (*)(float, long, long, long, long, long, long))fn_8001BBB4)(
                lbl_805641F0, fn_8000DA10(), col, row, (long)&lbl_8055C768, 0x1F4, 0);
            col++;
        }
        row++;
    }
    fn_80016A44(0);
    currentMode = fn_80012810();
    if (savedMode != currentMode) {
        if (currentMode != 0x134)
            fn_80012794();
        if (savedMode != 0x134)
            fn_80012790(savedMode);
    }
}
#pragma cplusplus on
extern "C" void fn_8027C014(void *arg0, long arg1, long arg2, void *arg3) {
    class FirstInterface {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual char *getName(const char *);
    };
    class SecondInterface {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual char *getName(const char *, const char *);
    };
    long i;
    void *p;

    *(long *)arg0 = arg1;
    *(long *)((char *)arg0 + 8) = arg2;
    *(void **)((char *)arg0 + 0x10) = arg3;
    *(char **)((char *)arg0 + 0xC) = ((FirstInterface *)arg3)->getName((const char *)&lbl_80347A5C);
    i = 0;
    goto check;
loop:
    p = fn_8001285C(i);
    if (stricmp(((SecondInterface *)*(void **)((char *)p + 0x20))->getName((const char *)&lbl_8055C758, (const char *)&lbl_8055C770),
                *(char **)((char *)arg0 + 0xC)) == 0)
        *(void **)((char *)arg0 + 4) = *(void **)p;
    i++;
check:
    if (i < fn_80012854())
        goto loop;
}
#pragma cplusplus reset
extern char lbl_80347B30[];
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_8027C0D0(void *arg0, long arg1, void *arg2) {
    struct Dummy {
        virtual long m0(char **);
        virtual long m1(char **);
        virtual long m2(char **);
        virtual long m3(char **);
    };
    *(long *)arg0 = arg1;
    *(long *)((char *)arg0 + 8) = (long)arg2;
    *(long *)((char *)arg0 + 4) = ((Dummy *)arg2)->m3((char **)&lbl_80347B30);
}
#pragma cplusplus reset
long *fn_8027C120(long arg0, long arg1) {
    long index = 0;
    long offset = 0;
    long len;
    goto check;
loop:
    len = stricmp((char *)arg1, *(char **)((char *)(*(long *)arg0) + offset + 0xC));
    switch (((unsigned int)__cntlzw(len) >> 5)) {
    case 0:
        goto advance;
    default:
        goto found;
    }
advance:
    offset += 0x14;
    index++;
check:
    if (index < *(volatile long *)(arg0 + 4))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return 0;
    return (long *)(*(long *)arg0 + index * 0x14);
}

#pragma push
#pragma scheduling invalid_target
extern int __cntlzw(unsigned int);
long fn_8027C1C8(void *arg0, const char *arg1) {
    struct StringTable {
        char padding[0xAF0C];
        char *entries;
        long count;
    };
    struct StringTable *table = (struct StringTable *)arg0;
    long index;
    long offset;
    for (index = 0, offset = 0; index < table->count; offset += 0xC, index++) {
        unsigned int equal = (unsigned int)__cntlzw((unsigned int)stricmp(arg1, *(char **)(table->entries + offset + 4))) >> 5;
        if (equal) {
            goto found;
        }
    }
    index = -1;
found:
    return index;
}
#pragma pop
void *fn_8027C258(void *arg0, long arg1) {
    return (char *)*(void **)((char *)arg0 + 0xAF0C) + arg1 * 0xC;
}

long *fn_8027C26C(void *arg0, const char *arg1) {
    long index = fn_8027C1C8(arg0, arg1);
    if (index < 0)
        return 0;
    return (long *)((char *)*(void **)((char *)arg0 + 0xAF0C) + index * 0xC);
}

#pragma push
#pragma use_lmw_stmw off
void fn_8027C2B8(void *arg0, long arg1, void *arg2) {
    extern char lbl_80347A50[];
    extern void *fn_80131808(void *);
    void **outerArray;
    void *outerList;
    void *outerItem;
    void *innerItem;
    void **tableArray;
    char *record;
    long outerCount;
    long outerIndex;
    long tableCount;
    long innerIndex;
    long itemCount;
    char *name;

    outerList = fn_80131808(arg2);
    if (outerList == 0)
        return;

    outerCount = *(volatile long *)((char *)arg0 + 0xB00C);
    outerIndex = 0;
    outerArray = *(void ***)((char *)arg0 + 0xB008);
    *(volatile long *)((char *)arg0 + 0xB00C) = outerCount + 1;
    outerArray[outerCount] = outerList;
    goto fetch_outer;

outer_loop:
    name = ((char *(*)(void *))(*(void ***)outerItem)[2])(outerItem);
    if (stricmp(name, (const char *)&lbl_8055C760) == 0) {
        tableCount = *(volatile long *)((char *)arg0 + 0xAF10);
        tableArray = *(void ***)((char *)arg0 + 0xAF0C);
        record = (char *)tableArray + tableCount * 0xC;
        *(volatile long *)((char *)arg0 + 0xAF10) = tableCount + 1;
        fn_8027C0D0(record, arg1, outerItem);

        innerIndex = 0;
        goto fetch_inner;
inner_loop:
        name = ((char *(*)(void *))(*(void ***)innerItem)[2])(innerItem);
        if (stricmp(name, lbl_80347A50) == 0) {
            itemCount = *(volatile long *)((char *)arg0 + 4);
            tableArray = *(void ***)arg0;
            *(volatile long *)((char *)arg0 + 4) = itemCount + 1;
            fn_8027C014((char *)tableArray + itemCount * 0x14,
                        arg1, *(long *)(record + 4), innerItem);
        }
        innerIndex++;
fetch_inner:
        innerItem = ((void *(*)(void *, long))(*(void ***)outerItem)[24])(
            outerItem, innerIndex);
        if (innerItem != 0)
            goto inner_loop;
    }

    outerIndex++;
fetch_outer:
    outerItem = ((void *(*)(void *, long))(*(void ***)outerList)[3])(
        outerList, outerIndex);
    if (outerItem != 0)
        goto outer_loop;
}
#pragma pop
extern void fn_8027C2B8();
#pragma push
#pragma scheduling invalid_target
void *fn_8027C41C(void *arg0, long arg1) {
    long base = (long)arg0 + 0x10000;
    long zero = 0;
    char *temp_r7 = (char *)(base - 0x50E8);
    char *temp_r6 = (char *)(base - 0x4FEC);
    *(long *)(base - 0x4FE4) = arg1;
    *(void **)arg0 = (char *)arg0 + 0xC;
    *(long *)((char *)arg0 + 8) = 0x8C0;
    *(long *)(base - 0x50EC) = 0x14;
    *(long *)((char *)arg0 + 4) = zero;
    *(void **)(base - 0x50F4) = temp_r7;
    *(long *)(base - 0x50F0) = zero;
    *(void **)(base - 0x4FF8) = temp_r6;
    *(long *)(base - 0x4FF0) = 2;
    *(long *)(base - 0x4FF4) = zero;
    fn_8027C2B8(arg0, 0, &lbl_80347B4C, temp_r6, temp_r7, zero);
    fn_8027C2B8(arg0, 1, &lbl_80347B5C);
    return arg0;
}
#pragma scheduling on
#pragma pop

#pragma use_lmw_stmw off
long fn_8027C4B4(long arg0, long arg1) {
    register long offset;
    register long i;
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
        *(long *)(arg0 + 0xB00C) = 0;
        if ((void *)(arg0 + 0xB008) != 0) {
            if ((void *)(arg0 + 0xB008) != 0) {
                *(long *)(arg0 + 0xB008) = 0;
                *(long *)(arg0 + 0xB00C) = 0;
                *(long *)(arg0 + 0xB010) = 0;
            }
        }
        if ((void *)(arg0 + 0xAF0C) != 0) {
            if ((void *)(arg0 + 0xAF0C) != 0) {
                *(long *)(arg0 + 0xAF0C) = 0;
                *(long *)(arg0 + 0xAF10) = 0;
                *(long *)(arg0 + 0xAF14) = 0;
            }
        }
        if (arg0 != 0) {
            if (arg0 != 0) {
                *(long *)arg0 = 0;
                *(long *)(arg0 + 4) = 0;
                *(long *)(arg0 + 8) = 0;
            }
        }
        if (arg1 > 0) fn_80128668((void *)arg0);
    }
    return arg0;
}
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

#pragma cplusplus on
extern "C" long fn_8027C650(void *arg0) {
    class List {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20();
        virtual long lookup(long);
    };
    long value = fn_8027D1F4();
    void *object;
    long id;
    void *manager;
    List *list;
    long left;
    long right;
    char buffer[0x18];

    object = fn_8001BB58(fn_8000DA10(), *(long *)((char *)arg0 + 4), value, 0);
    if (object != 0) {
        id = fn_80205268(lbl_80347AB0,
                         *(long *)((char *)(long)lbl_8055F654 + 0xB01C), -1);
        manager = fn_8001285C(*(long *)((char *)arg0 + 4));
        list = *(List **)((char *)manager + 0x20);
        fn_8001D884(buffer, list->lookup(id));
        left = *(volatile long *)(buffer + 0x14);
        right = *(volatile long *)((char *)object + 8);
        return left >= right;
    }
    return 0;
}
#pragma cplusplus reset
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

long fn_8027C650();
extern char lbl_80347A50[];
#pragma dont_inline on
long fn_8027C788(void *arg0) {
    register void *item;
    register long index = 0;
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
    char *name = (char *)*(volatile char **)((char *)arg0 + 4);
    long index = fn_8027C1C8((void *)lbl_8055F654, name);
    if (index == 0)
        return 1;
    return fn_8027C788(fn_8027C26C((void *)lbl_8055F654,
        *(char **)((char *)fn_8027C258((void *)lbl_8055F654, index - 1) + 4)));
}

long fn_8027C8B0(void) { return 1; }

extern void fn_801345D8(void *, int, const char *, ...);
#pragma cplusplus on
extern "C" void fn_8027C8B8(void *obj, unsigned char *outText, int maxLen) {
    char formatBuffer[0x64];
    Fn8027C8B8Formatter *formatter;
    /* Copy a bounded event-goal status/format string into outText. */
    register char *eventGoalBase = lbl_80347A50;
    register int remaining = maxLen;
    char *dest = (char *)outText;
    register void *object = obj;
    char *source;

    if (fn_8027C788(object) != 0) {
        source = fn_80131234(eventGoalBase + 0x128);
        dest = (char *)outText;
        goto copy_first;
count_first:
        remaining--;
        if (remaining > 0) goto copy_first;
        dest[-1] = 0;
        goto clear_first;
copy_first:
        if ((*dest++ = *source++) != 0) goto count_first;
clear_first:
        outText[0] = 0;
        goto done;
    }

    if (fn_8027C850(object) != 0) {
        source = fn_80131234(eventGoalBase + 0x13C);
        dest = (char *)outText;
        goto copy_second;
count_second:
        remaining--;
        if (remaining > 0) goto copy_second;
        dest[-1] = 0;
        goto clear_second;
copy_second:
        if ((*dest++ = *source++) != 0) goto count_second;
clear_second:
        outText[0] = 0;
        goto done;
    }

    formatter = *(Fn8027C8B8Formatter **)((char *)object + 8);
    fn_801345D8(formatBuffer, 0x64, eventGoalBase + 0x160,
                formatter->format(eventGoalBase + 0xF0));
    source = fn_80131234(formatBuffer);
    dest = (char *)outText;
    goto copy_third;
count_third:
    remaining--;
    if (remaining > 0) goto copy_third;
    dest[-1] = 0;
    goto done;
copy_third:
    if ((*dest++ = *source++) != 0) goto count_third;

done:
    return;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" long fn_8027D1F4(void);
extern "C" long fn_8000DA10(void);
extern "C" void *fn_8001BB58(long, long, long, long);
extern "C" long fn_8001D7EC(void);
#pragma cplusplus on
extern "C" long fn_8027CA1C(void *arg0) {
    long v;
    void *o;
    struct Iface {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual long f3(char *);
    };
    v = fn_8027D1F4();
    o = fn_8001BB58(fn_8000DA10(), *(long *)((char *)arg0 + 4), v, 0);
    v = 0;
    if (o != 0) {
        ((struct Iface *)(*(void **)((char *)arg0 + 0x10)))->f3(lbl_80347BD0);
        if (*(long *)((char *)o + 8) <= fn_8001D7EC())
            v = 1;
    }
    return v;
}
#pragma cplusplus off
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

#pragma push
#pragma scheduling invalid_target
void fn_8027CBF8(long arg0, char *arg1, long arg2) {
    char *src;
    char c;
    if (fn_8027CB28()) {
        src = fn_80131234(lbl_80347B78);
        goto copy_a;
    check_a:
        if (--arg2 > 0)
            goto copy_a;
        arg1[-1] = 0;
        goto done;
    copy_a:
        c = *src++;
        *arg1++ = c;
        if ((signed char)c == 0)
            goto done;
        goto check_a;
    } else {
        src = fn_80131234(lbl_80347C14);
        goto copy_b;
    check_b:
        if (--arg2 > 0)
            goto copy_b;
        arg1[-1] = 0;
        goto done;
    copy_b:
        c = *src++;
        *arg1++ = c;
        if ((signed char)c == 0)
            goto done;
        goto check_b;
    }
done:
    ;
}
#pragma scheduling on
#pragma pop

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
    long value = *fn_8027C120(lbl_8055F654, arg0);
    switch (value) {
    case 0:
        return ((long (*)(void))fn_8027C8B0)();
    case 1:
        return ((long (*)(void))fn_8027CB20)();
    default:
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347C38, arg0, value);
        return 1;
    }
}

long fn_8027CEC4(long arg0) {
    long value = *fn_8027C120(lbl_8055F654, arg0);
    switch (value) {
    case 0:
        return ((long (*)(void))fn_8027C650)();
    case 1:
        return ((long (*)(void))fn_8027CA1C)();
    default:
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347C38, arg0, value);
        return 1;
    }
}

long fn_8027CF3C(long arg0) {
    long value = *fn_8027C120(lbl_8055F654, arg0);
    switch (value) {
    case 0:
        return ((long (*)(void))fn_8027C71C)();
    case 1:
        return ((long (*)(void))fn_8027CAB4)();
    default:
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347C38, arg0, value);
        return 1;
    }
}

#pragma cplusplus on
extern "C" long fn_8027CFB4(long arg0) {
    long *obj = fn_8027C120(lbl_8055F654, arg0);
    long id = fn_80205268(lbl_80347AB0,
                          *(long *)((char *)(long)lbl_8055F654 + 0xB01C), -1);
    void *manager = fn_8001285C(*(long *)((char *)obj + 4));
    Fn8027CFB4List *list = *(Fn8027CFB4List **)((char *)manager + 0x20);
    char result[0x18];
    long i;
    fn_8001D884(result, list->lookup(id));
    i = 0;
    do {
        long found = fn_8001DA48(result, i);
        if (found >= 0)
            return found;
        i++;
    } while (i < 5);
    return 0;
}

extern "C" long fn_8027D068(long arg0) {
    long value = *fn_8027C26C((void *)lbl_8055F654, (const char *)arg0);
    switch (value) {
    case 0:
        return ((long (*)(void))fn_8027C850)();
    case 1:
        return ((long (*)(void))fn_8027CBF0)();
    default:
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347C70, arg0, value);
        return 1;
    }
}

extern "C" long fn_8027D0E0(long arg0) {
    long value = *fn_8027C26C((void *)lbl_8055F654, (const char *)arg0);
    switch (value) {
    case 0:
        return ((long (*)(void))fn_8027C788)();
    case 1:
        return ((long (*)(void))fn_8027CB28)();
    default:
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80347C70, arg0, value);
        return 1;
    }
}

void fn_8027C8B8(long, char *, long);
#pragma opt_propagation off
extern "C" void fn_8027D158(long arg0, char *arg1, long arg2) {
    long *result = fn_8027C26C((void *)lbl_8055F654, (const char *)arg0);
    switch (*(unsigned long *)result) {
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
long fn_8027D1F4(void) {
    return *(long *)((char *)lbl_8055F654 + 0xB01C);
}

