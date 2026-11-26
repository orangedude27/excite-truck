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
extern void* ArtSetGet(const char*);
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
extern void refreshTimesScreenPanes(void);
extern char lbl_80345828[];
extern char lbl_8055BAC0[];
extern char lbl_8055B860[];
extern int lbl_802FA690[5];
extern int lbl_80498EE8[5];
__declspec(section ".sdata") extern char lbl_8055BAC0[];
__declspec(section ".sdata") extern char lbl_8055B860[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8025E034(void)
{
    extern void *fn_801284F8(int, const char *);
    extern void *lbl_8055F2E4;
    extern int lbl_8055F2E8;
    struct DbgMenu { int w0; DbgMenuItem *items; int w2; int w3; int w4; };
    struct DbgCtx {
        void *list;
        void *seq[3];
        int cur;
        void *heap;
        struct { char name[0x20]; int state; } rows[6];
        struct { char a[0x20]; char b[0x20]; char c[0x18]; } sub[6];
        void *objs[6];
    };
    struct DbgCtx ctx;
    DbgMenuItem items[35];
    struct DbgMenu menu;
    char *str = lbl_80345828;
    int old = fn_80012810();
    if (old != 0x130) {
        fn_80012794();
        fn_80012790(0x130);
    }
    lbl_8055F3D4 = &ctx;
    {
        int i;
        for (i = 0; i < 3; i++)
            ctx.seq[i] = fn_8027B834(i);
    }
    ctx.heap = fn_8025FA18();
    {
        int i;
        for (i = 0; i < 6; i++) {
            void *obj = fn_801284F8(0x30, str + 0xC);
            if (obj != 0)
                obj = fn_8025F9C0(obj);
            ctx.objs[i] = obj;
            fn_8025F9B8(obj, (int)ctx.heap);
        }
    }
    ctx.cur = 0;
    ctx.list = ctx.seq[2];
    fn_8025F46C(&ctx);

    DbgMenuItemSet(&items[0], lbl_8055BAC0, 8, (void *)refreshTimesScreenPanes, 0, 0);
    DbgMenuItemSet(&items[1], lbl_80345828 + 0x18, 3, ctx.rows[0].name, 0, 0);
    DbgMenuItemSet(&items[2], lbl_80345828 + 0x24, 2, &ctx.rows[0].state, 0, 0);
    DbgMenuItemSet(&items[3], lbl_80345828 + 0x34, 3, ctx.rows[1].name, 0, 0);
    DbgMenuItemSet(&items[4], lbl_80345828 + 0x40, 2, &ctx.rows[1].state, 0, 0);
    DbgMenuItemSet(&items[5], lbl_80345828 + 0x50, 3, ctx.rows[2].name, 0, 0);
    DbgMenuItemSet(&items[6], lbl_80345828 + 0x5C, 2, &ctx.rows[2].state, 0, 0);
    DbgMenuItemSet(&items[7], lbl_80345828 + 0x6C, 3, ctx.rows[3].name, 0, 0);
    DbgMenuItemSet(&items[8], lbl_80345828 + 0x78, 2, &ctx.rows[3].state, 0, 0);
    DbgMenuItemSet(&items[9], lbl_80345828 + 0x88, 3, ctx.rows[4].name, 0, 0);
    DbgMenuItemSet(&items[10], lbl_80345828 + 0x94, 2, &ctx.rows[4].state, 0, 0);
    DbgMenuItemSet(&items[11], lbl_80345828 + 0xA4, 3, ctx.sub[0].a, 0, 0);
    DbgMenuItemSet(&items[12], lbl_80345828 + 0xB8, 3, ctx.sub[0].b, 0, 0);
    DbgMenuItemSet(&items[13], lbl_80345828 + 0xC8, 3, ctx.sub[0].c, 0, 0);
    DbgMenuItemSet(&items[14], lbl_80345828 + 0xD8, 3, ctx.sub[1].a, 0, 0);
    DbgMenuItemSet(&items[15], lbl_80345828 + 0xF0, 3, ctx.sub[1].b, 0, 0);
    DbgMenuItemSet(&items[16], lbl_80345828 + 0x100, 3, ctx.sub[1].c, 0, 0);
    DbgMenuItemSet(&items[17], lbl_80345828 + 0x110, 3, ctx.sub[2].a, 0, 0);
    DbgMenuItemSet(&items[18], lbl_80345828 + 0x128, 3, ctx.sub[2].b, 0, 0);
    DbgMenuItemSet(&items[19], lbl_80345828 + 0x138, 3, ctx.sub[2].c, 0, 0);
    DbgMenuItemSet(&items[20], lbl_80345828 + 0x148, 3, ctx.sub[3].a, 0, 0);
    DbgMenuItemSet(&items[21], lbl_80345828 + 0x160, 3, ctx.sub[3].b, 0, 0);
    DbgMenuItemSet(&items[22], lbl_80345828 + 0x170, 3, ctx.sub[3].c, 0, 0);
    DbgMenuItemSet(&items[23], lbl_80345828 + 0x180, 3, ctx.sub[4].a, 0, 0);
    DbgMenuItemSet(&items[24], lbl_80345828 + 0x198, 3, ctx.sub[4].b, 0, 0);
    DbgMenuItemSet(&items[25], lbl_80345828 + 0x1A8, 3, ctx.sub[4].c, 0, 0);
    DbgMenuItemSet(&items[26], lbl_80345828 + 0x1B8, 5, ctx.objs[0], 0, 0);
    DbgMenuItemSet(&items[27], lbl_80345828 + 0x1C4, 5, ctx.objs[1], 0, 0);
    DbgMenuItemSet(&items[28], lbl_80345828 + 0x1D0, 5, ctx.objs[2], 0, 0);
    DbgMenuItemSet(&items[29], lbl_80345828 + 0x1DC, 5, ctx.objs[3], 0, 0);
    DbgMenuItemSet(&items[30], lbl_80345828 + 0x1E8, 5, ctx.objs[4], 0, 0);
    DbgMenuItemSet(&items[31], lbl_8055B860, 6, (void *)fn_8025ECBC, 0, 0x125);
    DbgMenuItemSet(&items[32], lbl_8055B860, 6, (void *)fn_8025E678, 0, 0x127);
    DbgMenuItemSet(&items[33], lbl_8055B860, 6, 0, -1, 0x1B);
    items[34] = *(DbgMenuItem *)lbl_80498EE8;
    menu = *(struct DbgMenu *)lbl_802FA690;
    menu.items = items;
    fn_802146BC(&menu, -999, -999, 1);

    if (old != 0x130) {
        fn_80012794();
        fn_80012790(old);
    }
    lbl_8055F3D4 = 0;
    {
        int i;
        for (i = 0; i < 6; i++) {
            void *obj = ctx.objs[i];
            if (obj != 0)
                ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
        }
    }
    if (--lbl_8055F2E8 == 0) {
        struct { char *recs; int count; } *heap = lbl_8055F2E4;
        if (heap != 0) {
            int i, off;
            for (i = 0, off = 0; i < heap->count; off += 0x38, i++) {
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
#pragma pop
void* __dt__Q28PSSystem7SeqHeapFv_8025E614(void* arg0, int arg1) {
    /* Destroy a PSSystem::SeqHeap: reset its vtable, tear down the owned
       object at +0x2C, and optionally free the storage when arg1 > 0. */
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
    volatile char pad[0xC];
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

extern "C" int fn_8025ECBC(void) {
    typedef SeqObj Obj;
    char buf2[0x24], buf1[0x24], buf0[0x24];
    int outArr[3], tmpArr[3];
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
            goto copyNameByte;
            do {
                if (--n <= 0) {
                    q[-1] = 0;
                    break;
                }
copyNameByte:
                c = *src++;
                *q++ = c;
            } while (c != 0);
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
                goto copyFirstDetailByte;
                do {
                    if (--n <= 0) {
                        q[-1] = 0;
                        break;
                    }
copyFirstDetailByte:
                    c = *src++;
                    *q++ = c;
                } while (c != 0);
                src = ((char *(*)(Obj *))(*(void ***)o1)[7])(o1);
                q = dest2;
                n = 0x20;
                goto copySecondDetailByte;
                do {
                    if (--n <= 0) {
                        q[-1] = 0;
                        break;
                    }
copySecondDetailByte:
                    c = *src++;
                    *q++ = c;
                } while (c != 0);
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
                    fn_8001BD54(outArr, chosen);
                    tmpArr[0] = outArr[0];
                    tmpArr[1] = outArr[1];
                    tmpArr[2] = outArr[2];
                    obj300 = *(void **)(base + 0x300);
                    *(int *)((char *)obj300 + 0x20) = tmpArr[1];
                    *(unsigned char *)((char *)obj300 + 0x24) = *(unsigned char *)&tmpArr[2];
                    o1 = (Obj *)fn_80016510(tmpArr[0]);
                    table = *(void **)((char *)obj300 + 0x18);
                    foundIdx = 0;
                    byteOff = 0;
                    while (foundIdx < *(int *)((char *)table + 4)) {
                        if (stricmp(*(char **)table + byteOff, (char *)o1 + 0x2C) == 0)
                            goto foundEntry;
                        byteOff += 0x38;
                        foundIdx++;
                    }
                    foundIdx = -1;
foundEntry:
                    *(int *)((char *)obj300 + 0x1C) = foundIdx;
                    *(int *)((char *)obj300 + 0x28) = *(int *)((char *)o1 + *(int *)((char *)obj300 + 0x20) * 4 + 0x64);
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
extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern void *lbl_8055F3D4;
typedef int (*CountFn)(void *);
typedef void *(*GetFn)(void *, int);
typedef int (*TestFn)(void *);
#pragma scheduling invalid_target
#pragma cplusplus on
/* Menu callback for the "times" screen (times.lyt): refreshes which UI pane
   groups are on screen.  For every row of the event list it hides the row's
   "name" pane group unless one of the three sequence containers (DbgCtx::seq)
   still holds a usable entry for that row, and hides its "select" pane group
   unless one of them holds an in-use entry.  It then leaves visible only the
   pane holding the time variant selected for each of the five event rows. */
/* Refreshes the times screen, hiding row groups without usable sequence entries and showing only the selected time pane per event row. */ extern "C" void refreshTimesScreenPanes(void) {
#define UIHideGroup fn_80214A9C
#define UIShowGroup fn_80214AF0
#define dbgCtx lbl_8055F3D4
#define SEQ_LIST_COUNT 3
#define UI_GROUP_ROW_NAME 0x10
#define UI_GROUP_ROW_SELECT 0x1A
#define UI_GROUP_EVENT_BASE 1
#define UI_GROUP_EVENT_STRIDE 10
#define EVENT_ROW_COUNT 5
#define EVENT_PANE_COUNT 3
#define EVENT_ROW_STRIDE 0x58
#define EVENT_ROW_SEL 0x144
    struct SeqList {
        virtual int v8();
        virtual int count();
        virtual void *get(int);
    };
    struct SeqEntry {
        virtual int v0();
        virtual int v4();
        virtual void *v8(int);
        virtual int vC();
        virtual int v10();
        virtual int v14();
        virtual int v18();
        virtual int inUse();
        virtual int v20();
        virtual int v24();
    };
    register int row;
    struct { int seqIndex; } loop;
    int &seqIndex = loop.seqIndex;
    struct { void *entry; } entryBox;
    void *&entry = entryBox.entry;
    register int found;
    register int seqOffset;
    int secondSeqOffset;
    row = 0;
    goto check_row;
check_row_body:
    seqIndex = 0;
    seqOffset = 0;
    do {
        if (row >= ((SeqList *)(*(void **)((char *)dbgCtx + seqOffset + 4)))->count())
            goto name_retry;
        entry = ((SeqList *)(*(void **)((char *)dbgCtx + seqOffset + 4)))->get(row);
        if (((SeqEntry *)entry)->inUse() != 0)
            goto name_found;
        if (((SeqEntry *)entry)->v24() != 0)
            goto name_retry;
    name_found:
        found = 1;
        goto name_done;
    name_retry:
        seqIndex++;
        seqOffset += 4;
    } while (seqIndex < SEQ_LIST_COUNT);
    found = 0;
name_done:
    if (found == 0)
        UIHideGroup(row + UI_GROUP_ROW_NAME);
    seqIndex = 0;
    secondSeqOffset = 0;
    do {
        if (row >= ((SeqList *)(*(void **)((char *)dbgCtx + secondSeqOffset + 4)))->count())
            goto select_retry;
        entry = ((SeqList *)(*(void **)((char *)dbgCtx + secondSeqOffset + 4)))->get(row);
        if (((SeqEntry *)entry)->inUse() == 0)
            goto select_retry;
        found = 1;
        goto select_done;
    select_retry:
        seqIndex++;
        secondSeqOffset += 4;
    } while (seqIndex < SEQ_LIST_COUNT);
    found = 0;
select_done:
    if (found == 0)
        UIHideGroup(row + UI_GROUP_ROW_SELECT);
    row++;
check_row:
    if (row < ((SeqList *)(*(void **)dbgCtx))->count())
        goto check_row_body;
    {
        register int groupId;
        register char *rowBase;
        register int pane;
        register int eventRow;
        rowBase = (char *)dbgCtx;
        eventRow = 0;
        do {
            groupId = eventRow + UI_GROUP_EVENT_BASE;
            pane = 0;
            do {
                if (pane == *(int *)(rowBase + EVENT_ROW_SEL))
                    UIShowGroup(groupId);
                else
                    UIHideGroup(groupId);
                pane++;
                groupId += UI_GROUP_EVENT_STRIDE;
            } while (pane < EVENT_PANE_COUNT);
            eventRow++;
            rowBase += EVENT_ROW_STRIDE;
        } while (eventRow < EVENT_ROW_COUNT);
    }
#undef EVENT_ROW_SEL
#undef EVENT_ROW_STRIDE
#undef EVENT_ROW_COUNT
#undef EVENT_PANE_COUNT
#undef UI_GROUP_EVENT_STRIDE
#undef UI_GROUP_EVENT_BASE
#undef UI_GROUP_ROW_SELECT
#undef UI_GROUP_ROW_NAME
#undef SEQ_LIST_COUNT
#undef dbgCtx
#undef UIShowGroup
#undef UIHideGroup
}
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
extern "C" void fn_8025F46C(void *arg0)
{
    struct Item {
        virtual void *v0();
        virtual void *v4();
        virtual void *v8();
        virtual char *name();
        virtual void *v10();
        virtual void *v14();
        virtual int count();
        virtual Item *sub(int);
        virtual void *obj();
    };
    struct ItemPlain {
        virtual void *v0();
        virtual void *v4();
        virtual void *v8();
        virtual char *name();
        virtual void *v10();
        virtual void *v14();
        virtual int count();
        virtual char *sub();
    };
    struct Elem {
        virtual void *s0();
        virtual void *s4();
        virtual void *s8();
        virtual void *sC();
        virtual void *s10();
        virtual void *s14();
        virtual void *s18();
        virtual void *s1C();
        virtual void *s20();
        virtual int test();
    };
    struct List {
        virtual void *v0();
        virtual void *v4();
        virtual void *v8();
        virtual int count();
        virtual Item *get(int);
    };
    struct ElemList {
        virtual void *v0();
        virtual void *v4();
        virtual void *v8();
        virtual int count();
        virtual Elem *get(int);
    };
    struct Slot {
        char pad[0x18];
        void *table;
        int index;
        int field20;
        unsigned char flag24;
        unsigned char flag25;
        int field28;
    };
    unsigned char *base = (unsigned char *) arg0;
    unsigned char *walk;
    unsigned char *recPtr;
    Item *item;
    Item *o1;
    char *src;
    char *dest1;
    char *dest2;
    char *dest3;
    char *chosen;
    char *key;
    char *arr;
    Slot *slot;
    void *table;
    int i;
    int cnt;
    int sel;
    int found;
    int off;
    int idx;
    char buf0[0x24];
    char buf1[0x24];
    char buf2[0x24];
    int tmpBuf[3];
    int outBuf[3];

    memset(base + 0x18, 0, 0xD8);
    memset(base + 0xF0, 0, 0x210);
    {
        unsigned char *row = base + 0x18;
        unsigned char *state = base;
        for (i = 0; i < (((cnt = ((List *) *(void **) base)->count()) >= 6) ? 6 : cnt); i++) {
            char *q;
            char *p;
            int k;
            item = ((List *) *(void **) base)->get(i);
            src = item->name();
            p = (char *) row;
            q = src;
            k = 0x20;
            for (;;) {
                char c;
                if (--k <= 0) {
                    *--p = 0;
                    break;
                }
                c = *q++;
                *p++ = c;
                if (c == 0) break;
            }
            *(int *) (state + 0x38) = (i == *(int *) (base + 0x10)) ? 6 : 7;
            row += 0x24;
            state += 0x24;
        }
    }
    {
        unsigned char *seqPtr = base;
        found = 0;
        for (i = 0; i < 3; i++) {
            if (((ElemList *) *(void **) (seqPtr + 4))->count() > *(int *) (base + 0x10)) {
                if (((ElemList *) *(void **) (seqPtr + 4))->get(*(int *) (base + 0x10))->test() != 0) {
                    found = 1;
                }
            }
            seqPtr += 4;
        }
    }
    *((unsigned char *) (*(void **) (base + 0x300)) + 0x25) = 0;
    *((unsigned char *) (*(void **) (base + 0x304)) + 0x25) = 0;
    *((unsigned char *) (*(void **) (base + 0x308)) + 0x25) = 0;
    *((unsigned char *) (*(void **) (base + 0x30C)) + 0x25) = 0;
    *((unsigned char *) (*(void **) (base + 0x310)) + 0x25) = 0;
    *((unsigned char *) (*(void **) (base + 0x314)) + 0x25) = 0;
    if (!found) return;
    item = ((List *) *(void **) base)->get(*(int *) (base + 0x10));
    walk = base;
    recPtr = base;
    dest1 = (char *) (base + 0xF0);
    dest2 = (char *) (base + 0x110);
    dest3 = (char *) (base + 0x130);
    for (i = 0; i < (((cnt = item->count()) >= 6) ? 6 : cnt); i++) {
        char *q;
        char *p;
        int k;
        o1 = item->sub(i);
        src = o1->name();
        p = dest1;
        q = src;
        k = 0x20;
        for (;;) {
            char c;
            if (--k <= 0) {
                *--p = 0;
                break;
            }
            c = *q++;
            *p++ = c;
            if (c == 0) break;
        }
        src = ((ItemPlain *) o1)->sub();
        p = dest2;
        q = src;
        k = 0x20;
        for (;;) {
            char c;
            if (--k <= 0) {
                *--p = 0;
                break;
            }
            c = *q++;
            *p++ = c;
            if (c == 0) break;
        }
        {
            void *tmp = o1->obj();
            fn_8001BC38(buf0, fn_8000DA10(tmp), (void *) 0x20507, tmp, 0);
        }
        {
            void *tmp = o1->obj();
            fn_8001BC38(buf1, fn_8000DA10(tmp), (void *) 0x20507, tmp, 1);
        }
        {
            void *tmp = o1->obj();
            fn_8001BC38(buf2, fn_8000DA10(tmp), (void *) 0x20507, tmp, 2);
        }
        *((unsigned char *) (*(void **) (walk + 0x300)) + 0x25) = 1;
        if (fn_8001BD6C(buf0, buf1) != 0) {
            if (fn_8001BD6C(buf0, buf2) != 0) {
                fn_8001BD38(buf0, dest3, 0x14);
                *(int *) (recPtr + 0x144) = 0;
            } else if (fn_8001BCF0(buf2) != 0) {
                fn_8001BD38(buf2, dest3, 0x14);
                *(int *) (recPtr + 0x144) = 2;
            } else {
                fn_80130978(dest3, 0x14, -lbl_80558DC0[0]);
                *(int *) (recPtr + 0x144) = 0;
            }
        } else if (fn_8001BD6C(buf1, buf2) != 0) {
            fn_8001BD38(buf1, dest3, 0x14);
            *(int *) (recPtr + 0x144) = 1;
        } else if (fn_8001BCF0(buf2) != 0) {
            fn_8001BD38(buf2, dest3, 0x14);
            *(int *) (recPtr + 0x144) = 2;
        } else {
            fn_80130978(dest3, 0x14, -lbl_80558DC0[0]);
            *(int *) (recPtr + 0x144) = 0;
        }
        *((unsigned char *) (*(void **) (walk + 0x300)) + 0x25) = 0;
        if (*((unsigned char *) (*(void **) (walk + 0x300)) + 0x25) == 0) goto next_iter;
        sel = *(int *) (recPtr + 0x144);
        chosen = 0;
        if (sel == 0) chosen = buf0;
        else if (sel == 1) chosen = buf1;
        else if (sel == 2) chosen = buf2;
        fn_8001BD54(outBuf, chosen);
        tmpBuf[0] = outBuf[0];
        tmpBuf[1] = outBuf[1];
        tmpBuf[2] = outBuf[2];
        slot = (Slot *) *(void **) (walk + 0x300);
        slot->field20 = tmpBuf[1];
        slot->flag24 = (unsigned char) tmpBuf[2];
        key = (char *) fn_80016510(outBuf[0]);
        table = slot->table;
        arr = *(char **) table;
        off = 0;
        idx = 0;
        for (;;) {
            if (stricmp(arr + off, key + 0x2C) == 0) break;
            off += 0x38;
            idx++;
            if (idx >= *(int *) ((char *) table + 4)) {
                idx = -1;
                break;
            }
        }
        slot->index = idx;
        slot->field28 = *(int *) (key + slot->field20 * 4 + 0x64);
    next_iter:
        dest1 += 0x58;
        dest2 += 0x58;
        walk += 4;
        dest3 += 0x58;
        recPtr += 0x58;
    }
}
void fn_8025F9B8(void* seqObj, int heap) {
    // Store the sound sequence heap handle in the object's field at +0x18.
    *(int*)((char*)seqObj + 0x18) = heap;
}

void* fn_8025F9C0(void* self) {
    /* Initialize this object: clear fields, install vtable lbl_80345A30, and open the resource named by lbl_80345A1C. */
    *(int*)((char*)self + 0x14) = 0;
    *(void**)self = lbl_80345A30;
    *(int*)((char*)self + 0x18) = 0;
    *((char*)self + 0x25) = 0;
    *(void**)((char*)self + 0x2C) = ArtSetGet(lbl_80345A1C);
    return self;
}

#pragma cplusplus on
struct ParamItem_8025FA18 {
    virtual char *getName();
    virtual void *v1();
    virtual void *v2();
    virtual char *getParam(const char *);
    virtual void *v4();
    virtual void *v5();
    virtual void *v6();
    virtual float getFloat(const char *);
};
struct ParamDir_8025FA18 {
    virtual void *v0();
    virtual ParamItem_8025FA18 *getAt(int);
};
#pragma cplusplus reset
extern void *fn_801284F8(int, const char *);
extern "C" void *fn_8012850C(int, const char *);
extern void *fn_80131808(const char *);
extern void fn_80131818(void *);
extern int RegisterTextureByName(const char *, int);
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
static inline void setRecordIds_8025FA18(char *dst, int index) {
    *(int *)(dst + 0x20) = RegisterTextureByName(index ? lbl_80344750 : lbl_80344740, 0);
    *(int *)(dst + 0x24) = RegisterTextureByName(index ? lbl_80344730 : lbl_80344720, 0);
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void *fn_8025FA18(void) {
    int index, count;
    void *heap;
    ParamItem_8025FA18 *entry;
    ParamDir_8025FA18 *set;
    char *dst, *src, *q;
    int n;
    char c;
    int *record;
    if (lbl_8055F2E8 == 0) {
        heap = fn_801284F8(8, lbl_8055C114);
        if (heap != 0) {
            set = (ParamDir_8025FA18 *)fn_80131808(lbl_80344760);
            *(int *)((char *)heap + 4) = 0;
            *(void **)heap = fn_8012850C(0xAF0, lbl_8055C10C);
            for (count = 0; (entry = set->getAt(count)) != 0; count++) {
                if (strcmp(entry->getName(), lbl_8055C108) == 0) {
                    index = 0;
                    do {
                        int nn = *(int *)((char *)heap + 4);
                        record = (int *)((char *)*(void **)heap + nn * 0x38);
                        *(int *)((char *)heap + 4) = nn + 1;
                        src = entry->getParam(lbl_8055C100);
                        dst = (char *)record;
                        q = dst;
                        n = 0x20;
                        goto copy1_check;
                    copy1_dec:
                        if (--n <= 0) { q[-1] = 0; goto copy1_done; }
                    copy1_check:
                        c = *src++;
                        *q++ = c;
                        if (c != 0) goto copy1_dec;
                    copy1_done:
                        if (index != 0) {
                            n = 0x20;
                            q = (char *)record;
                            goto scan_check;
                        scan_dec:
                            n--;
                            q++;
                        scan_check:
                            c = *q;
                            if (c != 0) goto scan_dec;
                            if (n > 0) {
                                src = lbl_8055C0FC;
                                goto copy2_check;
                            copy2_dec:
                                if (--n <= 0) { q[-1] = 0; goto copy2_done; }
                            copy2_check:
                                c = *src++;
                                *q++ = c;
                                if (c != 0) goto copy2_dec;
                            copy2_done: ;
                            }
                        }
                        record[8] = RegisterTextureByName(index ? lbl_80344750 : lbl_80344740, 0);
                        record[9] = RegisterTextureByName(index ? lbl_80344730 : lbl_80344720, 0);
                        *(float *)((char *)record + 0x28) = entry->getFloat(lbl_8055C0F8);
                        *(float *)((char *)record + 0x2C) = entry->getFloat(lbl_8055C0F4);
                        *(float *)((char *)record + 0x30) = entry->getFloat(lbl_8055C0F0);
                        *(float *)((char *)record + 0x34) = entry->getFloat(lbl_8055C0EC);
                        index++;
                    } while (index < 2);
                }
            }
            fn_80131818(set);
        }
        lbl_8055F2E4 = heap;
    }
    lbl_8055F2E8++;
    return lbl_8055F2E4;
}
extern float lbl_80563B70;
extern float lbl_80563B74;
extern float lbl_80563B78;
extern double lbl_80563B80;
extern "C" void fn_80230C30(float *, float *, int, int);
extern "C" void drawPictureScaled(int, unsigned char, int, float, float, float, float, float);
extern "C" void fn_80231220(int, int, float, float, float, float, float, float, float, float);
extern float lbl_80563B70, lbl_80563B74, lbl_80563B78;
#pragma processor 750
#pragma paired_single off
extern "C" void fn_8025FC8C(void* p, int arg1) {
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
    drawPictureScaled(*(int*)((char*)p + 0x2C), *(unsigned char*)((char*)p + 0x24), -1,
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
