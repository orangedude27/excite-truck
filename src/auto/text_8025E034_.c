// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern void *lbl_8055F3D4;
extern float lbl_80558DC0[];
extern void *memset(void *, int, int);
extern char *fn_8000DA10(void *);
extern void fn_8001BC38(void *, void *, void *, void *, int);
extern int fn_8001BD6C(void *, void *);
extern int fn_8001BCF0(void *);
extern void fn_8001BD38(void *, void *, int);
extern void fn_80130978(void *, int, float);
extern void fn_8001BD54(void *, void *);
extern void *fn_80016510(int);
extern int stricmp(const char *, const char *);
#pragma cplusplus on
struct SeqObj {
    virtual int v8();
    virtual int vC();
    virtual SeqObj *get(int);
    virtual int v14();
    virtual int cnt2();
    virtual SeqObj *get2(int);
    virtual int v20();
    virtual int test();
};
static inline int SeqNextHasItem(void) {
    int i, off, n;
    n = *(int *)((char *)lbl_8055F3D4 + 0x10) + 1;
    for (i = 0, off = 0; i < 3; i++, off += 4) {
        SeqObj *o = *(SeqObj **)((char *)lbl_8055F3D4 + off + 4);
        if (n < o->vC()) {
            o = *(SeqObj **)((char *)lbl_8055F3D4 + off + 4);
            if (o->get(n)->test() != 0) return 1;
        }
    }
    return 0;
}
#pragma cplusplus reset
extern char lbl_80345A30[];
extern char lbl_80345A1C[];
extern void* fn_8023512C(const char*);
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);
void* __dt__Q28PSSystem7SeqHeapFv_8025E614(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80345A30;
        fn_80235380(*(void**)((char*)arg0 + 0x2C), lbl_80345A30);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

int fn_8025E678(void) {
    struct Key { int a; int b; unsigned char c; } out, tmp;
    char buf0[0x24], buf1[0x24], buf2[0x24];
    char *base, *recPtr, *dest1, *dest2, *dest3, *p, *q, *src, *chosen, *arr;
    void *obj, *item, *o1, *obj300, *table, *key;
    int i, ii, found, cnt, n, sel, foundIdx, byteOff;
    char c;

    found = 0;
    n = *(int *)((char *)lbl_8055F3D4 + 0x10) + 1;
    i = 0;
    ii = 0;
    for (;;) {
        obj = *(void **)((char *)lbl_8055F3D4 + ii + 4);
        if (n < ((int (*)(void *))(*(void ***)obj)[3])(obj)) {
            obj = *(void **)((char *)lbl_8055F3D4 + ii + 4);
            item = ((void *(*)(void *, int))(*(void ***)obj)[4])(obj, n);
            if (((int (*)(void *))(*(void ***)item)[9])(item) != 0) {
                found = 1;
                break;
            }
        }
        i++;
        ii += 4;
        if (i >= 3) break;
    }
    if (found) {
        *(int *)((char *)lbl_8055F3D4 + 0x10) = *(int *)((char *)lbl_8055F3D4 + 0x10) + 1;
        base = (char *)lbl_8055F3D4;
        memset(base + 0x18, 0, 0xD8);
        memset(base + 0xF0, 0, 0x210);
        p = base;
        dest1 = base + 0x18;
        i = 0;
        for (;;) {
            cnt = ((int (*)(void *))(*(void ***)(*(void **)base))[3])(*(void **)base);
            if (i >= (cnt >= 6 ? 6 : cnt)) break;
            obj = *(void **)base;
            item = ((void *(*)(void *, int))(*(void ***)obj)[4])(obj, i);
            src = ((char *(*)(void *))(*(void ***)item)[3])(item);
            q = dest1;
            n = 0x20;
            for (;;) {
                c = *src++;
                *q++ = c;
                if (c == 0) break;
                if (--n <= 0) {
                    q[-1] = 0;
                    break;
                }
            }
            *(int *)(p + 0x38) = (i == *(int *)(base + 0x10)) ? 6 : 7;
            dest1 += 0x24;
            p += 0x24;
            i++;
        }
        recPtr = base;
        ii = 0;
        found = 0;
        do {
            obj = *(void **)(recPtr + 4);
            n = *(int *)(base + 0x10);
            if (((int (*)(void *))(*(void ***)obj)[3])(obj) > n) {
                obj = *(void **)(recPtr + 4);
                item = ((void *(*)(void *, int))(*(void ***)obj)[4])(obj, n);
                if (((int (*)(void *))(*(void ***)item)[9])(item) != 0) found = 1;
            }
            ii++;
            recPtr += 4;
        } while (ii < 3);
        *(unsigned char *)(*(char **)(base + 0x300) + 0x25) = 0;
        *(unsigned char *)(*(char **)(base + 0x304) + 0x25) = 0;
        *(unsigned char *)(*(char **)(base + 0x308) + 0x25) = 0;
        *(unsigned char *)(*(char **)(base + 0x30C) + 0x25) = 0;
        *(unsigned char *)(*(char **)(base + 0x310) + 0x25) = 0;
        *(unsigned char *)(*(char **)(base + 0x314) + 0x25) = 0;
        if (found) {
            obj = *(void **)base;
            item = ((void *(*)(void *, int))(*(void ***)obj)[4])(obj, *(int *)(base + 0x10));
            recPtr = base;
            dest1 = base + 0xF0;
            dest2 = base + 0x110;
            dest3 = base + 0x130;
            for (i = 0;; i++) {
                cnt = ((int (*)(void *))(*(void ***)item)[6])(item);
                if (i >= (cnt >= 6 ? 6 : cnt)) break;
                o1 = ((void *(*)(void *, int))(*(void ***)item)[7])(item, i);
                src = ((char *(*)(void *))(*(void ***)o1)[3])(o1);
                q = dest1;
                n = 0x20;
                for (;;) {
                    c = *src++;
                    *q++ = c;
                    if (c == 0) break;
                    if (--n <= 0) {
                        q[-1] = 0;
                        break;
                    }
                }
                src = ((char *(*)(void *))(*(void ***)o1)[7])(o1);
                q = dest2;
                n = 0x20;
                for (;;) {
                    c = *src++;
                    *q++ = c;
                    if (c == 0) break;
                    if (--n <= 0) {
                        q[-1] = 0;
                        break;
                    }
                }
                n = ((int (*)(void *))(*(void ***)o1)[8])(o1);
                fn_8001BC38(buf0, fn_8000DA10(0), (void *)0x20507, (void *)n, 0);
                n = ((int (*)(void *))(*(void ***)o1)[8])(o1);
                fn_8001BC38(buf1, fn_8000DA10(0), (void *)0x20507, (void *)n, 1);
                n = ((int (*)(void *))(*(void ***)o1)[8])(o1);
                fn_8001BC38(buf2, fn_8000DA10(0), (void *)0x20507, (void *)n, 2);
                *(unsigned char *)(*(char **)(base + 0x300) + 0x25) = 1;
                if (fn_8001BD6C(buf0, buf1) != 0) {
                    if (fn_8001BD6C(buf0, buf2) != 0) {
                        fn_8001BD38(buf0, dest3, 0x14);
                        *(int *)(recPtr + 0x144) = 0;
                    } else if (fn_8001BCF0(buf2) != 0) {
                        fn_8001BD38(buf2, dest3, 0x14);
                        *(int *)(recPtr + 0x144) = 2;
                    }
                } else if (fn_8001BD6C(buf1, buf2) != 0) {
                    fn_8001BD38(buf1, dest3, 0x14);
                    *(int *)(recPtr + 0x144) = 1;
                } else if (fn_8001BCF0(buf2) != 0) {
                    fn_8001BD38(buf2, dest3, 0x14);
                    *(int *)(recPtr + 0x144) = 2;
                } else {
                    fn_80130978(dest3, 0x14, -lbl_80558DC0[0]);
                    *(int *)(recPtr + 0x144) = 0;
                    *(unsigned char *)(*(char **)(base + 0x300) + 0x25) = 0;
                }
                if (*(unsigned char *)(*(char **)(base + 0x300) + 0x25) != 0) {
                    chosen = 0;
                    sel = *(int *)(recPtr + 0x144);
                    if (sel == 0) chosen = buf0;
                    else if (sel == 1) chosen = buf1;
                    else if (sel == 2) chosen = buf2;
                    fn_8001BD54(&out, chosen);
                    tmp = out;
                    obj300 = *(void **)(base + 0x300);
                    *(int *)((char *)obj300 + 0x20) = out.b;
                    *(unsigned char *)((char *)obj300 + 0x24) = tmp.c;
                    key = fn_80016510(out.a);
                    table = *(void **)((char *)obj300 + 0x18);
                    arr = *(char **)table;
                    foundIdx = 0;
                    byteOff = 0;
                    for (;;) {
                        if (foundIdx >= *(int *)((char *)table + 4)) {
                            foundIdx = -1;
                            break;
                        }
                        if (stricmp(arr + byteOff, (char *)key + 0x2C) == 0) break;
                        byteOff += 0x38;
                        foundIdx++;
                    }
                    *(int *)((char *)obj300 + 0x1C) = foundIdx;
                    *(int *)((char *)obj300 + 0x28) = *(int *)((char *)key + *(int *)((char *)obj300 + 0x20) * 4 + 0x64);
                }
                dest1 += 0x58;
                dest2 += 0x58;
                base += 4;
                dest3 += 0x58;
                recPtr += 0x58;
            }
        }
        {
            char *r17 = (char *)lbl_8055F3D4;
            int g, e, a;
            for (g = 0; g < 5; g++) {
                a = g + 1;
                for (e = 0; e < 3; e++) {
                    if (e == *(int *)(r17 + 0x144)) fn_80214AF0(a);
                    else fn_80214A9C(a);
                    a += 0xA;
                }
                r17 += 0x58;
            }
        }
    }
    return 0;
}

extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern void *lbl_8055F3D4;
typedef int (*CountFn)(void *);
typedef void *(*GetFn)(void *, int);
typedef int (*TestFn)(void *);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8025F274(void) {
    struct Container {
        virtual int unused();
        virtual int count();
        virtual void *get(int);
    };
    struct Item {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual int f4();
        virtual int f5();
        virtual int f6();
        virtual int test24();
        virtual int f8();
        virtual int test2c();
    };
    register int i;
    register int j;
    register void *value;
    register int offset;
    register int found;
    i = 0;
    goto L_check;
L_outer:
    j = 0;
    offset = 0;
    do {
        if (i >= ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->count())
            goto L_first_retry;
        value = ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->get(i);
        if (((Item *)value)->test24() != 0)
            goto L_first_found;
        if (((Item *)value)->test2c() != 0)
            goto L_first_retry;
L_first_found:
        found = 1;
        goto L_first_done;
L_first_retry:
        j++;
        offset += 4;
    } while (j < 3);
    found = 0;
L_first_done:
    if (found == 0)
        fn_80214A9C(i + 0x10);
    j = 0;
    offset = 0;
    do {
        if (i >= ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->count())
            goto L_second_retry;
        value = ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->get(i);
        if (((Item *)value)->test24() != 0)
            goto L_second_found;
        goto L_second_retry;
L_second_found:
        found = 1;
        goto L_second_done;
L_second_retry:
        j++;
        offset += 4;
    } while (j < 3);
    found = 0;
L_second_done:
    if (found == 0)
        fn_80214A9C(i + 0x1A);
    i++;
L_check:
    if (i < ((Container *)(*(void **)lbl_8055F3D4))->count())
        goto L_outer;
    {
        register int arg;
        register char *base;
        register int inner;
        register int group;
        base = (char *)lbl_8055F3D4;
        group = 0;
        do {
            arg = group + 1;
            inner = 0;
            do {
                if (inner == *(int *)(base + 0x144))
                    fn_80214AF0(arg);
                else
                    fn_80214A9C(arg);
                inner++;
                arg += 0xA;
            } while (inner < 3);
            group++;
            base += 0x58;
        } while (group < 5);
    }
}

#pragma cplusplus reset
#pragma scheduling on
extern float lbl_80558DC0[];
extern void *memset(void *, int, int);
extern char *fn_8000DA10(void *);
extern void fn_8001BC38(void *, void *, void *, void *, int);
extern int fn_8001BD6C(void *, void *);
extern int fn_8001BCF0(void *);
extern void fn_8001BD38(void *, void *, int);
extern void fn_80130978(void *, int, float);
extern void fn_8001BD54(void *, void *);
extern void *fn_80016510(int);
extern int stricmp(const char *, const char *);
void fn_8025F46C(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char *recPtr;
    unsigned char *dest1, *dest2, *dest3;
    void *obj, *obj2, *item;
    char *str, *src;
    char buf0[0x24], buf1[0x24], buf2[0x24];
    int outBuf[6];
    int tmpBuf[6];
    int i, n, sel, cnt;
    void *table, *key;
    char *arr;
    int foundIdx, byteOff;
    void *obj300;
    memset(base + 0x18, 0, 0xD8);
    memset(base + 0xF0, 0, 0x210);
    {
        unsigned char *p16 = base + 0x18;
        unsigned char *p17 = base;
        int i18 = 0;
        for (;;) {
            char *p;
            char *q;
            int k;
            obj = *(void **)base;
            str = ((char *(*)(void *, int))(*(void ***)obj)[4])(obj, i18);
            src = ((char *(*)(void *))(*(void ***)str)[3])(str);
            p = (char *)p16;
            q = src;
            for (k = 0; k < 0x20; k++) {
                char c = *q++;
                *p++ = c;
                if (c == 0) break;
            }
            if (k == 0x20) p[-1] = 0;
            *(int *)(p17 + 0x38) = (i18 == *(int *)(base + 0x10)) ? 7 : 6;
            p16 += 0x24;
            p17 += 0x24;
            i18++;
            cnt = ((int (*)(void *))(*(void ***)obj)[3])(obj);
            if (cnt >= 6) break;
            if (i18 >= cnt) break;
        }
    }
    {
        unsigned char *p15 = base;
        int found = 0, ii = 0;
        for (;;) {
            obj = *(void **)(p15 + 4);
            cnt = ((int (*)(void *))(*(void ***)obj)[3])(obj);
            if (cnt > *(int *)(base + 0x10)) {
                item = ((void *(*)(void *, int))(*(void ***)obj)[4])(obj, *(int *)(base + 0x10));
                if (((int (*)(void *))(*(void ***)item)[9])(item) != 0) found = 1;
            }
            ii++;
            p15 += 4;
            if (found) break;
            if (ii >= 3) break;
        }
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x300) + 0x25) = 0;
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x304) + 0x25) = 0;
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x308) + 0x25) = 0;
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x30C) + 0x25) = 0;
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x310) + 0x25) = 0;
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x314) + 0x25) = 0;
        if (!found) return;
    }
    obj = *(void **)base;
    item = ((void *(*)(void *, int))(*(void ***)obj)[4])(obj, *(int *)(base + 0x10));
    recPtr = base;
    dest1 = base + 0xF0;
    dest2 = base + 0x110;
    dest3 = base + 0x130;
    for (i = 0;; i++) {
        void *o1 = ((void *(*)(void *, int))(*(void ***)item)[7])(item, i);
        char *p;
        char *q;
        int k;
        src = ((char *(*)(void *))(*(void ***)o1)[3])(o1);
        p = (char *)dest1;
        q = src;
        for (k = 0; k < 0x20; k++) {
            char c = *q++;
            *p++ = c;
            if (c == 0) break;
        }
        if (k == 0x20) p[-1] = 0;
        obj2 = ((void *(*)(void *, int))(*(void ***)o1)[7])(o1, i);
        src = ((char *(*)(void *))(*(void ***)obj2)[3])(obj2);
        p = (char *)dest2;
        q = src;
        for (k = 0; k < 0x20; k++) {
            char c = *q++;
            *p++ = c;
            if (c == 0) break;
        }
        if (k == 0x20) p[-1] = 0;
        {
            void *tmp = ((void *(*)(void *))(*(void ***)o1)[8])(o1);
            void *conv = fn_8000DA10(tmp);
            fn_8001BC38(buf0, conv, (void *)0x20507, tmp, 0);
        }
        {
            void *tmp = ((void *(*)(void *))(*(void ***)o1)[8])(o1);
            void *conv = fn_8000DA10(tmp);
            fn_8001BC38(buf1, conv, (void *)0x20507, tmp, 1);
        }
        {
            void *tmp = ((void *(*)(void *))(*(void ***)o1)[8])(o1);
            void *conv = fn_8000DA10(tmp);
            fn_8001BC38(buf2, conv, (void *)0x20507, tmp, 2);
        }
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x300) + 0x25) = 1;
        if (fn_8001BD6C(buf0, buf1) != 0) {
            if (fn_8001BD6C(buf0, buf2) != 0) {
                fn_8001BD38(buf0, dest3, 0x14);
                *(int *)(recPtr + 0x144) = 0;
            } else if (fn_8001BCF0(buf2) != 0) {
                fn_8001BD38(buf2, dest3, 0x14);
                *(int *)(recPtr + 0x144) = 2;
            } else {
                fn_80130978(dest3, 0x14, -lbl_80558DC0[0]);
                *(int *)(recPtr + 0x144) = 0;
            }
        } else if (fn_8001BD6C(buf1, buf2) != 0) {
            fn_8001BD38(buf1, dest3, 0x14);
            *(int *)(recPtr + 0x144) = 1;
        } else if (fn_8001BCF0(buf2) != 0) {
            fn_8001BD38(buf2, dest3, 0x14);
            *(int *)(recPtr + 0x144) = 2;
        } else {
            fn_80130978(dest3, 0x14, -lbl_80558DC0[0]);
            *(int *)(recPtr + 0x144) = 0;
        }
        *(unsigned char *)((unsigned char *)*(void **)(base + 0x300) + 0x25) = 0;
        if (*(unsigned char *)((unsigned char *)*(void **)(base + 0x300) + 0x25) == 0) goto next_iter;
        {
            char *chosen = 0;
            sel = *(int *)(recPtr + 0x144);
            if (sel == 0) chosen = buf0;
            else if (sel == 1) chosen = buf1;
            else if (sel == 2) chosen = buf2;
            fn_8001BD54(outBuf, chosen);
            tmpBuf[0] = outBuf[0]; tmpBuf[1] = outBuf[1]; tmpBuf[2] = outBuf[2];
            obj300 = *(void **)(base + 0x300);
            *(int *)((unsigned char *)obj300 + 0x20) = outBuf[1];
            *(unsigned char *)((unsigned char *)obj300 + 0x24) = (unsigned char)outBuf[2];
            key = fn_80016510(outBuf[0]);
            table = *(void **)((unsigned char *)obj300 + 0x18);
            arr = *(char **)table;
            {
                int c2 = *(int *)((unsigned char *)table + 4);
                foundIdx = 0; byteOff = 0;
                for (;;) {
                    if (stricmp(arr + byteOff, (char *)key + 0x2C) == 0) break;
                    byteOff += 0x38; foundIdx++;
                    if (foundIdx >= c2) { foundIdx = -1; break; }
                }
            }
            *(int *)((unsigned char *)obj300 + 0x1C) = foundIdx;
            *(int *)((unsigned char *)obj300 + 0x28) = *(int *)((char *)key + *(int *)((unsigned char *)obj300 + 0x20) * 4 + 0x64);
        }
next_iter:
        dest1 += 0x58; dest2 += 0x58; base += 4; dest3 += 0x58; recPtr += 0x58;
        cnt = ((int (*)(void *))(*(void ***)item)[6])(item);
        if (cnt >= 6) break;
        if (i + 1 >= cnt) break;
    }
}
void fn_8025F9B8(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

void* fn_8025F9C0(void* arg0) {
    *(int*)((char*)arg0 + 0x14) = 0;
    *(void**)arg0 = lbl_80345A30;
    *(int*)((char*)arg0 + 0x18) = 0;
    *((char*)arg0 + 0x25) = 0;
    *(void**)((char*)arg0 + 0x2C) = fn_8023512C(lbl_80345A1C);
    return arg0;
}

extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, const char *);
extern void *fn_80131808(const char *);
extern void fn_80131818(void *);
extern int fn_802CAC28(const char *, int);
extern int strcmp(const char *, const char *);
extern char lbl_80344720[], lbl_80344730[], lbl_80344740[], lbl_80344750[], lbl_80344760[];
__declspec(section ".sdata") extern char lbl_8055C0EC[];
__declspec(section ".sdata") extern char lbl_8055C0F0[];
__declspec(section ".sdata") extern char lbl_8055C0F4[];
__declspec(section ".sdata") extern char lbl_8055C0F8[];
__declspec(section ".sdata") extern char lbl_8055C0FC[];
__declspec(section ".sdata") extern char lbl_8055C100[];
__declspec(section ".sdata") extern char lbl_8055C108[];
__declspec(section ".sdata") extern char lbl_8055C10C[];
__declspec(section ".sdata") extern char lbl_8055C114[];
extern void *lbl_8055F2E4;
extern int lbl_8055F2E8;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_8025FA18(void) {
    int count, index;
    void *heap, *set, *entry;
    char *dst, *src;
    int *record;
    int i;

    if (lbl_8055F2E8 == 0) {
        heap = fn_801284F8(8, lbl_8055C114);
        if (heap != 0) {
            set = fn_80131808(lbl_80344760);
            *(int *)((char *)heap + 4) = 0;
            *(void **)heap = fn_8012850C(0xAF0, lbl_8055C10C);
            count = 0;
            for (;;) {
                entry = ((void *(*)(void *, int))((void **)*(void **)set)[3])(set, count);
                if (entry == 0) break;
                if (strcmp(((char *(*)(void *))((void **)*(void **)entry)[2])(entry), lbl_8055C108) == 0) {
                    index = 0;
                    do {
                        int n = *(int *)((char *)heap + 4);
                        record = (int *)((char *)*(void **)heap + n * 0x38);
                        *(int *)((char *)heap + 4) = n + 1;
                        src = ((char *(*)(void *, const char *))((void **)*(void **)entry)[5])(entry, lbl_8055C100);
                        dst = (char *)record;
                        for (i = 0; i < 0x20; i++) {
                            char c = *src++;
                            *dst++ = c;
                            if (c == 0) break;
                        }
                        if (index != 0) {
                            dst = (char *)record;
                            for (i = 0; i < 0x20 && dst[i] != 0; i++) {}
                            if (i < 0x20) {
                                src = lbl_8055C0FC;
                                do { *dst++ = *src; } while (*src++ != 0);
                            }
                        }
                        record[8] = fn_802CAC28(index ? lbl_80344750 : lbl_80344740, 0);
                        record[9] = fn_802CAC28(index ? lbl_80344730 : lbl_80344720, 0);
                        *(float *)((char *)record + 0x28) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0F8);
                        *(float *)((char *)record + 0x2C) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0F4);
                        *(float *)((char *)record + 0x30) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0F0);
                        index++;
                        *(float *)((char *)record + 0x34) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0EC);
                    } while (index < 2);
                }
                count++;
            }
            fn_80131818(set);
        }
        lbl_8055F2E4 = heap;
    }
    lbl_8055F2E8++;
    return lbl_8055F2E4;
}
#pragma pop
extern float lbl_80563B70;
extern float lbl_80563B74;
extern float lbl_80563B78;
extern double lbl_80563B80;
extern void fn_80230C30(float *, float *, int, int);
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
extern float lbl_80563B70, lbl_80563B74, lbl_80563B78;
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8025FC8C(void* p, int arg1) {
    float spC, sp8, outC, out8, f29, f28, f27, f26, f25, f24;
    unsigned int color, packed;
    int red, green, blue;
    char* item;
    if (*(unsigned char*)((char*)p + 0x25) == 0)
        return;
    fn_80230C30(&spC, &sp8, *(int*)((char*)p + 4), *(int*)((char*)p + 8));
    f25 = (float)*(int*)((char*)p + 0xC);
    f24 = (float)*(int*)((char*)p + 0x10);
    fn_802354A0(*(int*)((char*)p + 0x2C), *(unsigned char*)((char*)p + 0x24), -1,
        spC - lbl_80563B70, lbl_80563B70 + sp8, lbl_80563B74,
        lbl_80563B78 + f25, lbl_80563B78 + f24);
    item = (char*)**(void***)((char*)p + 0x18) + *(int*)((char*)p + 0x1C) * 0x38;
    out8 = sp8;
    outC = spC;
    f26 = *(float*)(item + 0x28);
    f27 = *(float*)(item + 0x2C);
    f28 = *(float*)(item + 0x30);
    f29 = *(float*)(item + 0x34);
    color = *(unsigned int*)((char*)p + 0x28);
    fn_80231220(*(int*)(item + 0x20), -1, outC, out8, f25, f24, f26, f27, f28, f29);
    blue = (color & 255) * 65025;
    blue = (blue / 256) / 256;
    green = ((color >> 8) & 255) * 65025;
    green = (green / 256) / 256;
    red = ((color >> 16) & 255) * 65025;
    red = (red / 256) / 256;
    packed = (red & 255) << 16;
    packed |= 0xFF000000;
    packed = (packed & 0xFFFF00FF) | ((green & 255) << 8);
    packed = (packed & 0xFFFFFF00) | (blue & 255);
    fn_80231220(*(int*)(item + 0x24), packed,
        outC, out8, f25, f24, f26, f27, f28, f29);
}
#pragma use_lmw_stmw on
#pragma scheduling on
