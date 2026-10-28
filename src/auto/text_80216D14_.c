// Code of main that had no source file yet: decomp.wtf gave it this one.
extern float lbl_80563490;
extern int fn_802182F0(void *, void *);
extern int fn_802368B4(int);
#pragma cplusplus on
struct Fn8021734CEntry {
    virtual void m0();
    virtual void update();
};
#pragma cplusplus reset
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EFAC;
int fn_80216D14(int arg0) {
    return arg0 < 0 ? 0 : 1 << arg0;
}

#pragma noinline
void fn_80216D28(void) {
    lbl_8055EFAC = 1;
}

#pragma noinline
void fn_80216D34(void) {
    lbl_8055EFAC = 0;
}

extern void fn_802C2D94(void *);
extern void fn_802C4C80(void *);
extern void fn_802C2FC4(void *);
extern void fn_802C519C(void *);
extern void fn_80128668(void *);

#pragma cplusplus on
extern "C" void *fn_80217270(void *arg0, int arg1) {
    class Obj {
    public:
        virtual void v0(int);
    };
    char *entry;
    int i;
    if (arg0 != 0) {
        i = *(int *)((char *)arg0 + 0x430) - 1;
        entry = (char *)arg0 + i * 4;
        while (i >= 0) {
            void *obj = *(void **)(entry + 0x30);
            if (obj != 0) {
                ((Obj *)obj)->v0(1);
            }
            entry -= 4;
            i--;
        }
        fn_802C2D94((char *)arg0 + 0xC);
        if (*(void **)arg0 != 0) fn_802C4C80(*(void **)arg0);
        if (*(void **)((char *)arg0 + 4) != 0) fn_802C2FC4(*(void **)((char *)arg0 + 4));
        if (*(void **)((char *)arg0 + 8) != 0) fn_802C519C(*(void **)((char *)arg0 + 8));
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8021734C(void *arg0) {
    register char *entry = (char *)arg0;
    register char *self = (char *)arg0;
    register int i = 0;
    Fn8021734CEntry *object;
    void *source;
    long value;
    void (*callback)(void);

    goto check;
loop:
    object = *(Fn8021734CEntry **)(entry + 0x30);
    object->update();
    if (*(int *)(self + 0x440) != 0) {
        object = *(Fn8021734CEntry **)(entry + 0x30);
        source = *(void **)((char *)object + 0x240);
        value = source ? *(long *)source : *(long *)((char *)object + 0x23C);
        fn_802368B4(value);
    }
    entry += 4;
    i++;
check:
    if (i < *(int *)(self + 0x430))
        goto loop;
    callback = *(void (**)(void))(self + 0x438);
    if (callback != 0)
        callback();
}
#pragma cplusplus off
#pragma scheduling on
void fn_802173F8(void *arg0) {
    char *base = (char *)arg0;
    int i;
    if (*(void **)(base + 0x43C) != 0) (*(void (**)(void))((char *)base + 0x43C))();
    i = *(int *)(base + 0x430) - 1;
    base += i * 4;
    while (i >= 0) {
        void *obj = *(void **)(base + 0x30);
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[4])(obj);
        base -= 4;
        i--;
    }
    fn_80216D28();
}
#pragma scheduling on
void fn_80217478(void) {

}

extern int fn_802368B4(int);
extern void fn_80216D28(void);
void fn_8021747C(void *arg0, void *arg1, void *arg2) {
    void (*callback)(void *, void *, void *) = *(void (**)(void *, void *, void *))((char *)arg0 + 0x440);
    if (callback != 0) callback(arg0, arg1, arg2);
}

extern void fn_80218198(void *, void **);
extern int fn_80218214(void *, int, int);
#pragma cplusplus on
extern "C" void fn_8021749C(void *arg0, int arg1, int arg2) {
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13(int, int);
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual int v24();
    };
    char *base = (char *)arg0;
    int x;
    int y;
    int index;
    Dummy *obj;
    if (*(void **)(base + 0x44C) == 0) {
        x = arg1 - *(int *)(base + 0x454);
        y = arg2 - *(int *)(base + 0x458);
        index = fn_80218214(arg0, x, y);
        obj = 0;
        if (index >= 0) obj = (Dummy *)*(void **)(base + index * 4 + 0x30);
        *(void **)(base + 0x44C) = obj;
        if (obj != 0 && obj->v24() != 0) {
            if (*(void **)(base + 0x450) != obj)
                fn_80218198(arg0, (void **)obj);
        } else {
            fn_80218198(arg0, 0);
        }
        if (obj != 0) obj->v13(x, y);
    }
}
#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80217590(void *arg0, int arg1, int arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14(int, int);
    };
    char *base = (char *)arg0;
    void *obj = *(void **)(base + 0x44C);
    int x = arg1 - *(int *)(base + 0x454);
    int y = arg2 - *(int *)(base + 0x458);
    if (obj != 0) {
        ((Obj *)obj)->v14(x, y);
    }
    *(void **)(base + 0x44C) = 0;
}
#pragma cplusplus off
void fn_80218198(void *, void **);
int fn_80218214(void *, int, int);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802175F0(void *arg0, int arg1, int arg2) {
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15(int, int);
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual int v24();
    };
    char *base = (char *)arg0;
    int x;
    int y;
    int index;
    Dummy *obj;
    if (*(void **)(base + 0x44C) == 0) {
        x = arg1 - *(int *)(base + 0x454);
        y = arg2 - *(int *)(base + 0x458);
        index = fn_80218214(arg0, x, y);
        obj = 0;
        if (index >= 0) obj = (Dummy *)*(void **)(base + index * 4 + 0x30);
        *(void **)(base + 0x44C) = obj;
        if (obj != 0 && *(void **)(base + 0x450) != obj) {
            if (obj->v24() != 0) {
                fn_80218198(arg0, (void **)obj);
            }
        }
        if (obj != 0) {
            obj->v15(x, y);
        }
    }
}
#pragma scheduling on
extern "C" void fn_802176D4(void *arg0, int arg1, int arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16(int, int);
    };
    char *base = (char *)arg0;
    void *obj = *(void **)(base + 0x44C);
    int x = arg1 - *(int *)(base + 0x454);
    int y = arg2 - *(int *)(base + 0x458);
    if (obj != 0) {
        ((Obj *)obj)->v16(x, y);
    }
    *(void **)(base + 0x44C) = 0;
}
#pragma cplusplus off
void fn_80217734(void *arg0, int arg1, int arg2) {
    char *base = (char *)arg0;
    int x = arg1 - *(int *)(base + 0x454);
    int y = arg2 - *(int *)(base + 0x458);
    int index = fn_80218214(arg0, x, y);
    void *obj = 0;
    void *current;
    if (index >= 0) obj = *(void **)(base + index * 4 + 0x30);
    if (*(void **)(base + 0x44C) != 0 && obj != *(void **)(base + 0x44C)) obj = 0;
    current = *(void **)(base + 0x448);
    if (obj != current) {
        if (current) ((void (*)(void *))(*(void ***)current)[0x5C / 4])(current);
        *(void **)(base + 0x448) = obj;
        if (obj) ((void (*)(void *))(*(void ***)obj)[0x58 / 4])(obj);
    }
    if (!obj) obj = *(void **)(base + 0x44C);
    if (obj) ((void (*)(void *, int, int))(*(void ***)obj)[0x4C / 4])(obj, x, y);
}

void fn_80217834(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x448);
    if (obj != 0) {
        void **vt = *(void ***)obj;
        ((void (*)(void *))vt[20])(obj);
    }
}

void fn_80217854(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x448);
    if (obj != 0) {
        ((void (*)(void *))(*(void ***)obj)[21])(obj);
    }
}

void fn_80218E08(void *arg0, int arg1);
void fn_80217874(void *arg0, int arg1) {
    char *base = (char *)arg0;
    int i;
    void *list;
    void *obj;
    int found;
    float threshold;
    fn_80216D34();
    if (*(int *)(base + 0x44C) == 0) {
        list = *(void **)(base + 0x450);
        if (list != 0) {
            void **vt = *(void ***)list;
            if (((int (*)(int))vt[0x64 / 4])(arg1)) {
                fn_80218E08(arg0, arg1);
                return;
            }
        }
        threshold = lbl_80563490;
        i = 0;
        while (i < *(int *)(base + 0x430)) {
            obj = *(void **)(base + i * 4 + 0x30);
            if (obj != list) {
                found = 0;
                if (*(unsigned char *)((char *)obj + 0x1A) != 0) {
                    found = 1;
                } else {
                    if (*(float *)((char *)obj + 0x20) >= threshold) found = 1;
                }
                if (found != 0 && *(unsigned char *)((char *)obj + 0x1B) != 0) {
                    void **vt = *(void ***)obj;
                    if (((int (*)(int))vt[0x64 / 4])(arg1)) {
                        fn_80218E08(arg0, arg1);
                        return;
                    }
                }
            }
            i++;
        }
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma paired_single off
void fn_802179A0(void *arg0) {
    char *base = (char *)arg0;
    int scan;
    int i;
    float threshold;
    char *entry;
    void *obj;
    if (*(void **)(base + 0x450) != 0) {
        scan = fn_802182F0(arg0, *(void **)(base + 0x450));
    } else {
        scan = 0;
    }
    if (scan >= 0) {
        threshold = lbl_80563490;
        i = 0;
        goto check;
    loop:
        scan++;
        entry = base + (scan % *(int *)(base + 0x430)) * 4;
        obj = *(void **)(entry + 0x30);
        {
            int eligible = 0;
            void **vtable;
            if (*(unsigned char *)((char *)obj + 0x1A) != 0) goto eligible_yes;
            if (*(float *)((char *)obj + 0x20) >= threshold) goto eligible_yes;
            goto eligible_check;
        eligible_yes:
            eligible = 1;
        eligible_check:
            if (eligible != 0) {
                vtable = *(void ***)obj;
                if (((int (*)(void *))vtable[0x68 / 4])(obj) != 0 &&
                    *(unsigned char *)((char *)obj + 0x1B) != 0) {
                    fn_80218198(arg0, (void **)obj);
                    return;
                }
            }
        }
        i++;
    check:
        if (i < *(int *)(base + 0x430) - 1) goto loop;
    } else {
        extern void fn_802E30C8(const char *, ...);
        extern char lbl_8033D824[];
        fn_802E30C8(lbl_8033D824);
    }
}
#pragma paired_single reset
#pragma pop

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma scheduling on
#pragma cplusplus on
extern "C" void fn_80217AC0(void *arg0) {
    class Dummy {
    public:
        virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3();
        virtual int f4(); virtual int f5(); virtual int f6(); virtual int f7();
        virtual int f8(); virtual int f9(); virtual int f10(); virtual int f11();
        virtual int f12(); virtual int f13(); virtual int f14(); virtual int f15();
        virtual int f16(); virtual int f17(); virtual int f18(); virtual int f19();
        virtual int f20(); virtual int f21(); virtual int f22(); virtual int f23();
        virtual int f24();
    };
    char *base = (char *)arg0;
    int scan;
    int i;
    int initialCount;
    float threshold;
    initialCount = *(int *)(base + 0x450);
    if (initialCount != 0) scan = fn_802182F0(arg0, (void *)initialCount);
    else scan = 0;
    threshold = lbl_80563490;
    for (i = 0; i < *(int *)(base + 0x430) - 1; i++) {
        char *entry;
        void *obj;
        int eligible;
        scan--;
        entry = base + ((scan + *(int *)(base + 0x450)) %
                        *(int *)(base + 0x450)) * 4;
        obj = *(void **)(entry + 0x30);
        eligible = 0;
        if (*(unsigned char *)((char *)obj + 0x1A) != 0) goto eligible_yes;
        if (*(float *)((char *)obj + 0x20) >= threshold) goto eligible_yes;
        goto eligible_check;
    eligible_yes:
        eligible = 1;
    eligible_check:
        if (eligible != 0) {
            if (((Dummy *)obj)->f24() != 0 &&
                *(unsigned char *)((char *)obj + 0x1B) != 0) {
                fn_80218198(arg0, (void **)obj);
                return;
            }
        }
    }
}
#pragma cplusplus reset
#pragma scheduling reset
#pragma dont_inline reset
#pragma pop
int fn_80217BC8(int *arg0, int *arg1) {
    return *arg0 - *arg1;
}

#pragma scheduling invalid_target
void *fn_80217BD8(void *arg0, int arg1, int arg2) {
    char *base = (char *)arg0;
    int count = *(int *)(base + 0x494);
    *(int *)(base + count * 8 + 0x4A0) = arg1;
    *(int *)(base + count * 8 + 0x4A4) = arg2;
    count = *(int *)(base + 0x494) + 1;
    *(int *)(base + 0x494) = count;
    qsort(base + 0x4A0, count, 8, fn_80217BC8, base);
    *(int *)(base + 0x498) = *(int *)(base + 0x4A0);
    return base + 0x498;
}
#pragma scheduling on
void fn_80217C4C(void *arg0) {
    char *base = (char *)arg0;
    int count = *(int *)(base + 0x494);
    int i;
    int last = -1;
    int matches = 0;
    int found = -1;
    int step;
    if (count < 1) return;
    for (i = 0; i < count; i++) {
        char *entry = base + i * 8;
        char *item;
        int ok;
        if (*(int *)(base + 0x498) == *(int *)(entry + 0x4A0)) {
            last = i;
        }
        item = *(char **)(entry + 0x4A4);
        ok = 0;
        if (*(unsigned char *)(item + 0x1A) == 0 && *(float *)(item + 0x20) <= lbl_80563490) {
            ok = 1;
        }
        if (ok && *(unsigned char *)(item + 0x1B) != 0) {
            matches++;
        }
    }
    for (step = 1; step < count; step++) {
        int idx = (last + step) % count;
        char *entry = base + idx * 8;
        char *item;
        int ok;
        item = *(char **)(entry + 0x4A4);
        ok = 0;
        if (*(unsigned char *)(item + 0x1A) == 0 && *(float *)(item + 0x20) <= lbl_80563490) {
            ok = 1;
        }
        if (ok && *(unsigned char *)(item + 0x1B) != 0) {
            found = idx;
            break;
        }
    }
    if (found >= 0 && (found > last || matches > 3)) {
        *(int *)(base + 0x498) = *(int *)(base + found * 8 + 0x4A0);
    }
}

void fn_80217D84(void *arg0) {
    char *base = (char *)arg0;
    int count = *(int *)(base + 0x494);
    int i, last, matches, step, found, idx, item_ok;
    char *entry, *item, *e2;
    if (count < 1) return;
    i = count;
    entry = base + count * 8;
    last = -1;
    matches = 0;
    do {
        entry -= 8;
        if (*(int *)(base + 0x498) == *(int *)(entry + 0x4A0)) last = i - 1;
        item = *(char **)(entry + 0x4A4);
        item_ok = 0;
        if (*(unsigned char *)(item + 0x1A) == 0 && *(float *)(item + 0x20) <= lbl_80563490) item_ok = 1;
        if (item_ok && *(unsigned char *)(item + 0x1B) != 0) matches++;
        i--;
    } while (i > 0);
    step = 1;
    found = -1;
    while (step < count) {
        idx = (last + count - step) % count;
        e2 = base + idx * 8;
        item = *(char **)(e2 + 0x4A4);
        item_ok = 0;
        if (*(unsigned char *)(item + 0x1A) == 0 && *(float *)(item + 0x20) <= lbl_80563490) item_ok = 1;
        if (item_ok && *(unsigned char *)(item + 0x1B) != 0) { found = idx; break; }
        step++;
    }
    if (found >= 0 && (found < last || matches > 3))
        *(int *)(base + 0x498) = *(int *)(base + found * 8 + 0x4A0);
}

void fn_802180B0(void *arg0) { fn_80217EC0(arg0, 1, 0); }

void fn_802180BC(void *arg0) { fn_80217EC0(arg0, 1, 1); }

extern int fn_80217EC0(void *, int, int);
void fn_802180C8(void *arg0) { fn_80217EC0(arg0, 0, 0); }

void fn_802180D4(void *arg0) { fn_80217EC0(arg0, 0, 1); }

void fn_802180E0(void *arg0, int arg1) {
    extern void fn_802E30C8(const char *, ...);
    extern char lbl_8033D83C[];
    if (arg1 < 0 || arg1 >= *(int *)((char *)arg0 + 0x494)) {
        fn_802E30C8(lbl_8033D83C);
        return;
    }
    *(int *)((char *)arg0 + 0x498) = *(int *)((char *)arg0 + 0x4A0 + arg1 * 8);
}

int fn_80218120(void *arg0) {
    extern char lbl_8033D860[];
    extern void fn_802E30C8(const char *, ...);
    long i;
    int count = *(int *)((char *)arg0 + 0x494);
    for (i = 0; i < count; i++) {
        if (*(int *)((char *)arg0 + 0x498) == *(int *)((char *)arg0 + 0x4A0 + i * 8)) return i;
    }
    fn_802E30C8(lbl_8033D860);
    return 0;
}

void fn_8021818C(void *arg0) {
    *(int *)((char *)arg0 + 0x498) = -1;
}

void fn_80218198(void *arg0, void **arg1) {
    void **old;
    old = *(void ***)( (char *)arg0 + 0x450);
    if (arg1 != old) {
        if (old != 0) {
            void *obj = old;
            void **vt = *(void ***)obj;
            ((void (*)(void *))vt[14])(obj);
        }
        *(void ***)((char *)arg0 + 0x450) = arg1;
        if (arg1 != 0) {
            void *obj = arg1;
            void **vt = *(void ***)obj;
            ((void (*)(void *))vt[13])(obj);
        }
    }
}

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_80218214(void *arg0, int arg1, int arg2) {
    struct Dummy {
        virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3();
        virtual int f4(); virtual int f5(); virtual int f6(); virtual int f7();
        virtual int f8(); virtual int f9(); virtual int f10(); virtual int f11();
        virtual int f12(); virtual int f13(); virtual int f14(); virtual int f15();
        virtual int f16(); virtual int f17(); virtual int f18(); virtual int f19();
        virtual int f20(); virtual int f21(); virtual int f22(); virtual int f23();
        virtual int f24(); virtual int f25(); virtual int f26(int, int);
    };
    char *entry;
    int i;
    register float threshold = lbl_80563490;
    i = *(int *)((char *)arg0 + 0x430) - 1;
    entry = (char *)arg0 + i * 4;
    while (i >= 0) {
        void *obj = *(void **)(entry + 0x30);
        if (*(unsigned char *)((char *)obj + 0x1B) != 0) {
            int eligible = 0;
            if (*(unsigned char *)((char *)obj + 0x1A) == 0) {
                if (*(float *)((char *)obj + 0x20) >= threshold)
                    eligible = 1;
            }
            if (eligible != 0 && ((Dummy *)obj)->f26(arg1, arg2) != 0)
                return i;
        }
        entry -= 4;
        i--;
    }
    return -1;
}
#pragma cplusplus reset
#pragma dont_inline reset
#pragma pop
int fn_802182F0(void *arg0, void *arg1) {
    int count;
    int i;
    count = *(int *)((char *)arg0 + 0x430);
    i = 0;
    while (count > 0) {
        if (*(void **)((char *)arg0 + 0x30 + i * 4) == arg1)
            return i;
        i++;
        count--;
    }
    return -1;
}

int fn_8021832C(void *arg0) {
    void *obj;
    void **vtable;
    obj = *(void **)((char *)arg0 + 0x44C);
    if (obj != 0) {
        vtable = *(void ***)obj;
        return ((int (*)(void *))vtable[24])(obj);
    }
    obj = *(void **)((char *)arg0 + 0x448);
    if (obj != 0) {
        vtable = *(void ***)obj;
        return ((int (*)(void *))vtable[24])(obj);
    }
    return 0;
}

extern void fn_80217D84(void *);
#pragma cplusplus on
extern "C" void fn_80218370(void *arg0) {
    class Entry {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28();
        virtual void update();
    };
    register char *base = (char *)arg0;
    register char *cursor = base;
    register int i = 0;
    int j;
    char *scan;
    void *object;
    int found;

    goto checkFirst;
firstLoop:
    ((Entry *)*(void **)(cursor + 0x30))->update();
    cursor += 4;
    i++;
checkFirst:
    if (i < *(int *)(base + 0x430))
        goto firstLoop;

    j = *(int *)(base + 0x494);
    scan = base;
    found = 0;
    for (i = 0; i < j; i++, scan += 8) {
        if (*(int *)(base + 0x498) == *(int *)(scan + 0x4A0)) {
            object = *(void **)(scan + 0x4A4);
            if (*(unsigned char *)((char *)object + 0x1B) != 0) {
                int matched = (*(unsigned char *)((char *)object + 0x1A) != 0) ||
                              (*(float *)((char *)object + 0x20) >= lbl_80563490);
                if (matched) {
                    found = 1;
                    break;
                }
            }
        }
    }
    if (!found)
        fn_80217D84(arg0);
}
#pragma cplusplus off
void fn_80218464(void *arg0) {
    char *base = (char *)arg0;
    int i = 0;
    char *cursor = base;
    while (i < *(int *)(base + 0x430)) {
        void *obj = *(void **)(cursor + 0x30);
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[32])(obj);
        cursor += 4;
        i++;
    }
}

extern float lbl_80563490;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802184D0(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
    };
    register float threshold;
    char *cursor;
    int i;
    char *base;
    for (threshold = lbl_80563490, base = (char *)arg0, cursor = base, i = 0;
         i < *(int *)(base + 0x430); cursor += 4, i++) {
        void *obj = *(void **)(cursor + 0x30);
        int call = 0;
        if (*(unsigned char *)((char *)obj + 0x1A) != 0 ||
            *(float *)((char *)obj + 0x20) >= threshold) {
            call = 1;
        }
        if (call != 0) {
            ((Obj *)obj)->v9();
        }
    }
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
extern float lbl_80563494, lbl_80563498;
extern int fn_80215228(void);
extern void fn_80230C30(float *,float *,int,int);
extern void fn_802C5310(void *,int,float,float,float);
extern void fn_802C86E8(unsigned int);
extern void fn_802C88BC(int);
extern void fn_8022EDB8(void);
extern void fn_8022ED00(void *);
extern void *fn_8022EDC4(void);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80218574(void *arg0) {
    struct State { int matrix[12]; float a,b,c; };
    struct State state;
    float x,y;
    char *base=arg0, *entry;
    int i,current;
    float zero,one,limit;
    if (*(void **)(base+8)) {
        fn_80230C30(&x,&y,0,0);
        fn_802C5310(*(void **)(base+8),0,x,y,lbl_80563490);
    } else if(fn_80215228() && !*(unsigned char *)(base+0xde4)) {
        fn_802C86E8(0xff000000); fn_802C88BC(3);
    }
    zero=lbl_80563490; one=lbl_80563494; limit=lbl_80563498;
    current=-1; entry=base;
    for(i=0;i<*(int *)(base+0x430);i++,entry+=4) {
        char *obj=*(char **)(entry+0x30);
        int active=0;
        if(*(unsigned char *)(obj+0x1a) || *(float *)(obj+0x20)>=zero) active=1;
        if(active) {
            int index, pushed;
            float alpha;
            int *p=*(int **)(obj+0x240);
            if(p) index=*p; else index=*(int *)(obj+0x23c);
            if(index!=current) {
                if(current!=-1) fn_8022EDB8();
                current=index;
                fn_8022ED00(base+index*0x3c+0x6a0);
            }
            if (*(float *)(obj+0x20)>=zero) alpha=one-*(float *)(obj+0x20);
else if (*(float *)(obj+0x1c)>=zero) alpha=*(float *)(obj+0x1c);
else if (*(unsigned char *)(obj+0x1a)) alpha=lbl_80563494;
else alpha=zero;
            pushed=0;
            if(alpha<limit && *(void **)(base+0x444)) {
                int a,b,c,result;
                float innerAlpha;
                pushed=1;
                state=*(struct State *)fn_8022EDC4();
                if (*(float *)(obj+0x20)>=zero) innerAlpha=one-*(float *)(obj+0x20);
else if (*(float *)(obj+0x1c)>=zero) innerAlpha=*(float *)(obj+0x1c);
else if (*(unsigned char *)(obj+0x1a)) innerAlpha=lbl_80563494;
else innerAlpha=zero;
                c=*(int *)(obj+8); b=*(int *)(obj+4); a=*(int *)(obj+0x238);
                result=((int (*)(void *))(*(void ***)obj)[0x78/4])(obj);
                (*(void (**)(void *,int,int,int,int,int,int,float))(base+0x444))(&state,a,b,c,result,*(int *)(obj+0x10)-c,0,innerAlpha);
                fn_8022ED00(&state);
            }
            ((void (*)(void *))(*(void ***)obj)[0x28/4])(obj);
            if(pushed) fn_8022EDB8();
        }
    }
    if(current!=-1) fn_8022EDB8();
}
#pragma pop

#pragma dont_inline on
int fn_8021885C(void *arg0, int arg1) {
    return (*(int *)((char *)arg0 + 0x464) & fn_80216D14(arg1)) == 0;
}

extern int fn_80216D14(int);
extern void fn_802193C8(float);
void fn_8021889C(void *arg0, int arg1, float arg2) {
    int mask = fn_80216D14(arg1);
    if (*(int *)((char *)arg0 + 0x464) & mask)
        return;
    {
        char *cursor;
        int called;
        int currentMask;
        int flags;
        int i;

        currentMask = fn_80216D14(arg1);
        flags = *(int *)((char *)arg0 + 0x464);
        cursor = (char *)arg0;
        called = 0;
        *(int *)((char *)arg0 + 0x464) = flags | currentMask;
        i = 0;
        goto check;
    loop:
        if (*(int *)((char *)arg0 + 0x464) &
            *(int *)((char *)*(void **)(cursor + 0x30) + 0x238)) {
            fn_802193C8(arg2);
            called++;
        }
        cursor += 4;
        i++;
    check:
        if (i < *(int *)((char *)arg0 + 0x430))
            goto loop;
        if (called > 8)
            *(char *)((char *)arg0 + 0x46C) = 1;
    }
}

extern void fn_80219358(float);
void fn_80218968(void *arg0, int arg1, float arg2) {
    int mask = fn_80216D14(arg1);
    if (*(int *)((char *)arg0 + 0x464) & mask) {
        char *cursor;
        int calls;
        int currentMask;
        int flags;
        int i;

        calls = 0;
        currentMask = fn_80216D14(arg1);
        flags = *(int *)((char *)arg0 + 0x464);
        cursor = (char *)arg0;
        i = 0;
        *(int *)((char *)arg0 + 0x464) = flags & ~currentMask;
        goto check;
    loop:
        if ((*(int *)((char *)arg0 + 0x464) &
             *(int *)((char *)*(void **)(cursor + 0x30) + 0x238)) == 0) {
            fn_80219358(arg2);
            calls++;
        }
        cursor += 4;
        i++;
    check:
        if (i < *(int *)((char *)arg0 + 0x430))
            goto loop;
        if (calls >= 8)
            *(char *)((char *)arg0 + 0x46C) = 1;
    }
}

#pragma dont_inline on
void fn_80218A34(void *arg0, int arg1) {
    char *base=(char *)arg0, *cursor;
    int i, one=1;
    int mask=fn_80216D14(arg1);
    if (*(int *)(base+0x468)&mask) {
        mask=fn_80216D14(arg1);
        *(int *)(base+0x468)&=~mask;
        cursor=base;
        i=0;
        for (; i<*(int *)(base+0x430); i++,cursor+=4) {
            void *obj=*(void **)(cursor+0x30);
            if ((*(int *)(base+0x468)&*(int *)((char *)obj+0x238))==0) {
                *(unsigned char *)((char *)obj+0x1B)=one;
                if (*(unsigned char *)((char *)obj+0x1A))
                    *(unsigned char *)((char *)obj+0x234)=one;
            }
        }
    }
}
void fn_80218ADC(void *arg0, int arg1) {
    char *cursor;
    void *obj;
    int i, one = 1, zero = 0;
    int mask = fn_80216D14(arg1);
    if ((*(int *)((char *)arg0 + 0x468) & mask) == 0) {
        mask = fn_80216D14(arg1);
        *(int *)((char *)arg0 + 0x468) |= mask;
        cursor = (char *)arg0;
        i = 0;
        for (; i < *(int *)((char *)arg0 + 0x430); cursor += 4, i++) {
            obj = *(void **)(cursor + 0x30);
            if (*(int *)((char *)arg0 + 0x468) & *(int *)((char *)obj + 0x238)) {
                *(unsigned char *)((char *)obj + 0x1B) = zero;
                if (*(unsigned char *)((char *)obj + 0x1A))
                    *(unsigned char *)((char *)obj + 0x234) = one;
            }
        }
    }
}
#pragma push
#pragma use_lmw_stmw off
void fn_80218B88(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    int mask=fn_80216D14(arg1);
    void **cursor=(void **)arg0;
    int i=0;
    for (; i < *(int *)((char *)arg0+0x430); ++i, ++cursor) {
        void *obj=*(void **)((char *)cursor+0x30);
        if (mask & *(int *)((char *)obj+0x238)) {
            ((void (*)(void *,int,int))(*(void ***)obj)[8])(obj,arg2,arg3);
        }
    }
}
#pragma push
#pragma scheduling on
void fn_80218C14(void *arg0, int arg1, void *arg2) {
    register const unsigned int *src = (const unsigned int *)arg2;
    register unsigned int a;
    register unsigned int b;
    register unsigned int c;
    register int offset = arg1 * 0x3C;
    register unsigned int *dst = (unsigned int *)((char *)arg0 + offset + 0x6A0);
    register float z;
    register float y;
    register float x;
    float *fsrc = (float *)arg2;

    a = src[0];
    b = src[1];
    c = src[2];
    dst[0] = a;
    a = src[3];
    dst[1] = b;
    b = src[4];
    dst[2] = c;
    c = src[5];
    dst[3] = a;
    a = src[6];
    dst[4] = b;
    b = src[7];
    dst[5] = c;
    c = src[8];
    dst[6] = a;
    a = src[9];
    dst[7] = b;
    b = src[10];
    dst[8] = c;
    c = src[11];
    dst[9] = a;
    x = fsrc[12];
    dst[10] = b;
    y = fsrc[13];
    dst[11] = c;
    z = fsrc[14];
    ((float *)dst)[12] = x;
    ((float *)dst)[13] = y;
    ((float *)dst)[14] = z;
}
#pragma cplusplus on
extern "C" void fn_80218C98(void *arg0, void **arg1, int arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual int v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual int v24();
    };
    char *base = (char *)arg0;
    Obj *obj = (Obj *)arg1;
    int count = *(int *)(base + 0x430);
    *(void **)(base + 0x30 + count * 4) = arg1;
    *(int *)(base + 0x430) = count + 1;
    if (obj->v24() != 0 &&
        *(int *)(base + 0x450) == 0 &&
        *(unsigned char *)(base + 0xDE4) != 0) {
        fn_80218198(arg0, arg1);
    }
    *(int *)((char *)obj + 0x238) = fn_80216D14(arg2);
    *(void **)((char *)obj + 0x2C) = arg0;
    obj->v3();
}
extern "C" void fn_80218D54(void *arg0, int arg1) {
    class Obj {
    public:
        virtual int v0();
        virtual int v1();
        virtual int v2();
        virtual int v3();
        virtual int v4();
        virtual int v5();
        virtual int v6();
        virtual int v7();
        virtual int v8();
        virtual int v9();
        virtual int v10();
        virtual int v11();
        virtual int v12();
        virtual int v13();
        virtual int v14();
        virtual int v15();
        virtual int v16();
        virtual int v17();
        virtual int v18();
        virtual int v19();
        virtual int v20();
        virtual int v21();
        virtual int v22();
        virtual int v23();
        virtual int v24();
    };
    char *base = (char *)arg0;
    char *cursor = base;
    int i = 0;
    while (i < *(int *)(base + 0x430)) {
        Obj *obj = *(Obj **)(cursor + 0x30);
        if (obj->v24() != 0 &&
            (*(Obj **)(cursor + 0x30))->v4() == arg1) {
            fn_80218198(arg0, *(void ***)(base + i * 4 + 0x30));
            return;
        }
        cursor += 4;
        i++;
    }
}
#pragma cplusplus off
extern void fn_80214D50(int);
void fn_80218E08(void *arg0, int arg1) {
    if ((unsigned char)lbl_8055EFAC != 0) return;
    if (arg1 == 0xD || (unsigned int)arg1 == 0x113) fn_80214D50(2);
    else if ((unsigned int)arg1 == 0x1B) fn_80214D50(3);
    else fn_80214D50(0);
}

#pragma dont_inline reset
extern int qsort(void *, int, int, int (*)(const void *, const void *), void *);
int fn_80217BC8(int *, int *);
typedef struct { unsigned int words[12]; float values[3]; } Fn80216D40Record;
