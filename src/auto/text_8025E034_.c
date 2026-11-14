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
/* One line of a debug menu passed to fn_802146BC: label, kind (2 int, 3 string, 5 object,
   6 action, 8 callback), the value/callback it edits and two kind-specific words. */
typedef struct DbgMenuItem {
    void *name;
    int type;
    void *data;
    int a;
    int b;
} DbgMenuItem;
static inline void DbgMenuItemSet(DbgMenuItem *item, void *name, int type, void *data, int a, int b) {
    item->name = name;
    item->type = type;
    item->data = data;
    item->a = a;
    item->b = b;
}
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
extern int fn_80012810(void);
extern void fn_80012794(void);
extern void fn_80012790(int);
extern void *fn_8027B834(int);
extern int fn_802146BC(void *, int, int, int);
extern void fn_802CAC54(int);
extern void fn_80128670(void *);
extern void *fn_8025FA18(void);
extern void fn_8025F46C(void *);
extern void *fn_8025F9C0(void *);
extern void fn_8025F9B8(void *, int);
extern int fn_8025E678(void);
extern int fn_8025ECBC(void);
extern void fn_8025F274(void);
extern char lbl_80345828[];
extern char lbl_8055BAC0[];
extern char lbl_8055B860[];
extern int lbl_802FA690[5];
extern int lbl_80498EE8[5];
void fn_8025E034(void)
{
    extern void *fn_801284F8(int, const char *);
    extern void *lbl_8055F2E4;
    extern int lbl_8055F2E8;
    struct DbgItem { void *name; int type; void *data; int a; int b; };
    struct DbgMenu { int w0; struct DbgItem *items; int w2; int w3; int w4; };
    struct DbgCtx {
        void *list;
        void *seq[3];
        int cur;
        void *heap;
        struct { char name[0x20]; int state; } rows[6];
        struct { char a[0x20]; char b[0x20]; char c[0x18]; } sub[6];
        void *objs[6];
    };
    struct DbgMenu menu;
    struct DbgItem items[35];
    struct DbgCtx ctx;
    char *str = lbl_80345828;
    int old;
    int i;
    void *obj;
    struct { char *recs; int count; } *heap;
    int off;

    old = fn_80012810();
    if (old != 0x130) {
        fn_80012794();
        fn_80012790(0x130);
    }
    lbl_8055F3D4 = &ctx;
    for (i = 0; i < 3; i++)
        ctx.seq[i] = fn_8027B834(i);
    ctx.heap = fn_8025FA18();
    for (i = 0; i < 6; i++) {
        obj = fn_801284F8(0x30, str + 0xC);
        if (obj != 0)
            obj = fn_8025F9C0(obj);
        ctx.objs[i] = obj;
        fn_8025F9B8(obj, (int)ctx.heap);
    }
    ctx.cur = 0;
    ctx.list = ctx.seq[2];
    fn_8025F46C(&ctx);

    items[0].name = lbl_8055BAC0; items[0].type = 8; items[0].data = (void *)fn_8025F274; items[0].a = 0; items[0].b = 0;
    items[1].name = str + 0x18; items[1].type = 3; items[1].data = ctx.rows[0].name; items[1].a = 0; items[1].b = 0;
    items[2].name = str + 0x24; items[2].type = 2; items[2].data = &ctx.rows[0].state; items[2].a = 0; items[2].b = 0;
    items[3].name = str + 0x34; items[3].type = 3; items[3].data = ctx.rows[1].name; items[3].a = 0; items[3].b = 0;
    items[4].name = str + 0x40; items[4].type = 2; items[4].data = &ctx.rows[1].state; items[4].a = 0; items[4].b = 0;
    items[5].name = str + 0x50; items[5].type = 3; items[5].data = ctx.rows[2].name; items[5].a = 0; items[5].b = 0;
    items[6].name = str + 0x5C; items[6].type = 2; items[6].data = &ctx.rows[2].state; items[6].a = 0; items[6].b = 0;
    items[7].name = str + 0x6C; items[7].type = 3; items[7].data = ctx.rows[3].name; items[7].a = 0; items[7].b = 0;
    items[8].name = str + 0x78; items[8].type = 2; items[8].data = &ctx.rows[3].state; items[8].a = 0; items[8].b = 0;
    items[9].name = str + 0x88; items[9].type = 3; items[9].data = ctx.rows[4].name; items[9].a = 0; items[9].b = 0;
    items[10].name = str + 0x94; items[10].type = 2; items[10].data = &ctx.rows[4].state; items[10].a = 0; items[10].b = 0;
    items[11].name = str + 0xA4; items[11].type = 3; items[11].data = ctx.sub[0].a; items[11].a = 0; items[11].b = 0;
    items[12].name = str + 0xB8; items[12].type = 3; items[12].data = ctx.sub[0].b; items[12].a = 0; items[12].b = 0;
    items[13].name = str + 0xC8; items[13].type = 3; items[13].data = ctx.sub[0].c; items[13].a = 0; items[13].b = 0;
    items[14].name = str + 0xD8; items[14].type = 3; items[14].data = ctx.sub[1].a; items[14].a = 0; items[14].b = 0;
    items[15].name = str + 0xF0; items[15].type = 3; items[15].data = ctx.sub[1].b; items[15].a = 0; items[15].b = 0;
    items[16].name = str + 0x100; items[16].type = 3; items[16].data = ctx.sub[1].c; items[16].a = 0; items[16].b = 0;
    items[17].name = str + 0x110; items[17].type = 3; items[17].data = ctx.sub[2].a; items[17].a = 0; items[17].b = 0;
    items[18].name = str + 0x128; items[18].type = 3; items[18].data = ctx.sub[2].b; items[18].a = 0; items[18].b = 0;
    items[19].name = str + 0x138; items[19].type = 3; items[19].data = ctx.sub[2].c; items[19].a = 0; items[19].b = 0;
    items[20].name = str + 0x148; items[20].type = 3; items[20].data = ctx.sub[3].a; items[20].a = 0; items[20].b = 0;
    items[21].name = str + 0x160; items[21].type = 3; items[21].data = ctx.sub[3].b; items[21].a = 0; items[21].b = 0;
    items[22].name = str + 0x170; items[22].type = 3; items[22].data = ctx.sub[3].c; items[22].a = 0; items[22].b = 0;
    items[23].name = str + 0x180; items[23].type = 3; items[23].data = ctx.sub[4].a; items[23].a = 0; items[23].b = 0;
    items[24].name = str + 0x198; items[24].type = 3; items[24].data = ctx.sub[4].b; items[24].a = 0; items[24].b = 0;
    items[25].name = str + 0x1A8; items[25].type = 3; items[25].data = ctx.sub[4].c; items[25].a = 0; items[25].b = 0;
    items[26].name = str + 0x1B8; items[26].type = 5; items[26].data = ctx.objs[0]; items[26].a = 0; items[26].b = 0;
    items[27].name = str + 0x1C4; items[27].type = 5; items[27].data = ctx.objs[1]; items[27].a = 0; items[27].b = 0;
    items[28].name = str + 0x1D0; items[28].type = 5; items[28].data = ctx.objs[2]; items[28].a = 0; items[28].b = 0;
    items[29].name = str + 0x1DC; items[29].type = 5; items[29].data = ctx.objs[3]; items[29].a = 0; items[29].b = 0;
    items[30].name = str + 0x1E8; items[30].type = 5; items[30].data = ctx.objs[4]; items[30].a = 0; items[30].b = 0;
    items[31].name = lbl_8055B860; items[31].type = 6; items[31].data = (void *)fn_8025ECBC; items[31].a = 0; items[31].b = 0x125;
    items[32].name = lbl_8055B860; items[32].type = 6; items[32].data = (void *)fn_8025E678; items[32].a = 0; items[32].b = 0x127;
    items[33].name = lbl_8055B860; items[33].type = 6; items[33].data = 0; items[33].a = -1; items[33].b = 0x1B;
    items[34] = *(struct DbgItem *)lbl_80498EE8;
    menu = *(struct DbgMenu *)lbl_802FA690;
    menu.items = items;
    fn_802146BC(&menu, -999, -999, 1);

    if (old != 0x130) {
        fn_80012794();
        fn_80012790(old);
    }
    lbl_8055F3D4 = 0;
    for (i = 0; i < 6; i++) {
        obj = ctx.objs[i];
        if (obj != 0)
            ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
    }
    if (--lbl_8055F2E8 == 0) {
        heap = lbl_8055F2E4;
        if (heap != 0) {
            for (i = 0, off = 0; i < heap->count; i++, off += 0x38) {
                char *rec = heap->recs + off;
                fn_802CAC54(*(int *)(rec + 0x20));
                fn_802CAC54(*(int *)(rec + 0x24));
            }
            fn_80128670(heap->recs);
            fn_80128668(heap);
        }
        lbl_8055F2E4 = 0;
    }
}

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

#pragma cplusplus on
extern "C" int fn_8025E678(void) {
    typedef SeqObj Obj;
    struct Key { int a; int b; unsigned char c; } out, tmp;
    char buf0[0x24], buf1[0x24], buf2[0x24];
    char *base, *recPtr, *dest1, *dest2, *dest3, *p, *q, *src, *chosen, *arr;
    Obj *obj, *item, *o1;
    void *obj300, *table, *key;
    int i, ii, found, cnt, n, sel, foundIdx, byteOff, t;
    char c;

    if (SeqNextHasItem()) {
        *(int *)((char *)lbl_8055F3D4 + 0x10) = *(int *)((char *)lbl_8055F3D4 + 0x10) + 1;
        base = (char *)lbl_8055F3D4;
        memset(base + 0x18, 0, 0xD8);
        memset(base + 0xF0, 0, 0x210);
        p = base;
        dest1 = base + 0x18;
        i = 0;
        while (i < ((cnt = (*(Obj **)base)->vC()) >= 6 ? 6 : cnt)) {
            obj = *(Obj **)base;
            item = obj->get(i);
            src = (char *)item->vC();
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
            obj = *(Obj **)(recPtr + 4);
            n = *(int *)(base + 0x10);
            if (obj->vC() > n) {
                obj = *(Obj **)(recPtr + 4);
                item = obj->get(n);
                if (item->test() != 0) found = 1;
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
            obj = *(Obj **)base;
            item = obj->get(*(int *)(base + 0x10));
            recPtr = base;
            dest1 = base + 0xF0;
            dest2 = base + 0x110;
            dest3 = base + 0x130;
            i = 0;
            while (i < ((cnt = item->cnt2()) >= 6 ? 6 : cnt)) {
                o1 = item->get2(i);
                src = (char *)o1->vC();
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
                src = (char *)o1->get2(0);
                src = (char *)((Obj *)src)->vC();
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
                t = o1->v20();
                fn_8001BC38(buf0, fn_8000DA10((void *)t), (void *)0x20507, (void *)t, 0);
                t = o1->v20();
                fn_8001BC38(buf1, fn_8000DA10((void *)t), (void *)0x20507, (void *)t, 1);
                t = o1->v20();
                fn_8001BC38(buf2, fn_8000DA10((void *)t), (void *)0x20507, (void *)t, 2);
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
                i++;
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

#pragma cplusplus on
extern "C" int fn_8025ECBC(void) {
    typedef SeqObj Obj;
    struct Key { int a; int b; unsigned char c; } out, tmp;
    char buf0[0x24], buf1[0x24], buf2[0x24];
    char *base, *recPtr, *dest1, *dest2, *dest3, *p, *q, *src, *chosen, *arr;
    Obj *obj, *item, *o1;
    void *obj300, *table, *key;
    int i, ii, found, cnt, n, sel, foundIdx, byteOff, t;
    char c;
    if (*(int *)((char *)lbl_8055F3D4 + 0x10) > 0) {
        *(int *)((char *)lbl_8055F3D4 + 0x10) -= 1;
        base = (char *)lbl_8055F3D4;
        memset(base + 0x18, 0, 0xD8);
        memset(base + 0xF0, 0, 0x210);
        p = base;
        dest1 = base + 0x18;
        i = 0;
        while (i < ((cnt = (*(Obj **)base)->vC()) >= 6 ? 6 : cnt)) {
            obj = *(Obj **)base;
            item = obj->get(i);
            src = (char *)item->vC();
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
            obj = *(Obj **)(recPtr + 4);
            n = *(int *)(base + 0x10);
            if (obj->vC() > n) {
                obj = *(Obj **)(recPtr + 4);
                item = obj->get(n);
                if (item->test() != 0) found = 1;
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
            obj = *(Obj **)base;
            item = obj->get(*(int *)(base + 0x10));
            recPtr = base;
            dest1 = base + 0xF0;
            dest2 = base + 0x110;
            dest3 = base + 0x130;
            i = 0;
            while (i < ((cnt = item->cnt2()) >= 6 ? 6 : cnt)) {
                o1 = item->get2(i);
                src = (char *)o1->vC();
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
                src = (char *)o1->get2(0);
                src = (char *)((Obj *)src)->vC();
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
                t = o1->v20();
                fn_8001BC38(buf0, fn_8000DA10((void *)t), (void *)0x20507, (void *)t, 0);
                t = o1->v20();
                fn_8001BC38(buf1, fn_8000DA10((void *)t), (void *)0x20507, (void *)t, 1);
                t = o1->v20();
                fn_8001BC38(buf2, fn_8000DA10((void *)t), (void *)0x20507, (void *)t, 2);
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
                i++;
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
#pragma cplusplus reset

#pragma cplusplus reset
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
    register int found;
    register int offset;
    i = 0;
    goto L_check;
L_outer:
    offset = 0;
    j = 0;
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
        if (((Item *)value)->test24() == 0)
            goto L_second_retry;
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
            k = 0x20;
            do {
                char c = *q++;
                *p++ = c;
                if (c == 0) break;
                k--;
            } while (k > 0);
            if (k == 0) p[-1] = 0;
            *(int *)(p17 + 0x38) = (i18 == *(int *)(base + 0x10)) ? 6 : 7;
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
        k = 0x20;
        do {
            char c = *q++;
            *p++ = c;
            if (c == 0) break;
            k--;
        } while (k > 0);
        if (k == 0) p[-1] = 0;
        obj2 = ((void *(*)(void *, int))(*(void ***)o1)[7])(o1, i);
        src = ((char *(*)(void *))(*(void ***)obj2)[3])(obj2);
        p = (char *)dest2;
        q = src;
        k = 0x20;
        do {
            char c = *q++;
            *p++ = c;
            if (c == 0) break;
            k--;
        } while (k > 0);
        if (k == 0) p[-1] = 0;
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
    char *dst, *src, *q;
    int *record;
    int n;
    char c;
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
                        int nn = *(int *)((char *)heap + 4);
                        record = (int *)((char *)*(void **)heap + nn * 0x38);
                        *(int *)((char *)heap + 4) = nn + 1;
                        src = ((char *(*)(void *, const char *))((void **)*(void **)entry)[5])(entry, lbl_8055C100);
                        dst = (char *)record;
                        q = dst;
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
                        if (index != 0) {
                            dst = (char *)record;
                            for (n = 0; n < 0x20 && dst[n] != 0; n++) {}
                            if (n < 0x20) {
                                dst += n;
                                src = lbl_8055C0FC;
                                n = 0x20 - n;
                                for (;;) {
                                    c = *src++;
                                    *dst++ = c;
                                    if (c == 0) break;
                                    if (--n <= 0) {
                                        dst[-1] = 0;
                                        break;
                                    }
                                }
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
#pragma processor 750
#pragma paired_single off
void fn_8025FC8C(void* p, int arg1) {
    float spC, sp8, outC, out8, f29, f28, f27, f26, f25, f24;
    float tmpA, tmpB;
    unsigned int color, packed;
    int red, green, blue;
    char* item;
    if (*(unsigned char*)((char*)p + 0x25) == 0)
        return;
    fn_80230C30(&spC, &sp8, *(int*)((char*)p + 4), *(int*)((char*)p + 8));
    f25 = (float)*(int*)((char*)p + 0xC);
    tmpA = spC - lbl_80563B70;
    tmpB = lbl_80563B70 + sp8;
    f24 = (float)*(int*)((char*)p + 0x10);
    fn_802354A0(*(int*)((char*)p + 0x2C), *(unsigned char*)((char*)p + 0x24), -1,
        tmpA, tmpB, lbl_80563B74,
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
