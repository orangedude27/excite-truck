typedef struct { int id, category, flags; } Record8025;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80345718[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);
extern int lbl_8055F3C4;
extern void fn_80128668(void *);
extern void fn_80214A9C(int);
extern void *fn_8023512C(void *, void *, void *);
extern char lbl_80345694[];
extern int lbl_8055C3E0;
extern double lbl_80563B68;
extern float lbl_80563B58, lbl_80563B5C, lbl_80563B60;
extern void fn_80230C30(float *, float *, int, int);
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
extern int fn_80012810(void);
extern void fn_80012794(void);
extern void fn_80012790(int);
extern char lbl_803454C8[];
extern void *fn_8025D9D0(void *);
extern int lbl_8055F2E8;
extern char lbl_8055C114, lbl_8055C10C;
extern char lbl_80344760[];
extern void *fn_801284F8(int, void *);
extern void **fn_80131808(void *);
extern void *fn_8012850C(int, void *);
extern void *lbl_8055F2E4;
extern char lbl_8055C108[], lbl_8055C100[];
extern char lbl_8055C0FC, lbl_8055C0F8, lbl_8055C0F4, lbl_8055C0F0, lbl_8055C0EC;
extern char lbl_80344750, lbl_80344740, lbl_80344730, lbl_80344720;
extern void *fn_802CAC28(void *, int);
extern void fn_80131818(void *);
extern int strcmp(const char *, const char *);
void fn_8025CE78(void) {
    char *tbl;
    int heapType;
    void *list;
    void **items;
    void *item;
    char *name;
    int i, j, count, n;
    char *entry, *src, *dst;
    char c;
    char buf0[1084], buf1[1084], buf2[1084], buf3[1084], buf4[1084], buf5[1084], buf6[1084];
    tbl = lbl_803454C8;
    heapType = fn_80012810();
    if (heapType != 304) {
        fn_80012794();
        fn_80012790(304);
    }
    fn_8025D9D0(buf0);
    fn_8025D9D0(buf1);
    fn_8025D9D0(buf2);
    fn_8025D9D0(buf3);
    fn_8025D9D0(buf4);
    fn_8025D9D0(buf5);
    fn_8025D9D0(buf6);
    if (lbl_8055F2E8 == 0) {
        list = fn_801284F8(8, &lbl_8055C114);
        if (list != 0) {
            items = fn_80131808(&lbl_80344760);
            *(int *)((char *)list + 4) = 0;
            *(void **)list = fn_8012850C(0xaf0, &lbl_8055C10C);
            for (i = 0; ; i++) {
                item = ((void *(*)(void *, int))*(void **)((char *)*(void **)items + 0xC))(items, i);
                if (item == 0) break;
                name = ((char *(*)(void *))*(void **)((char *)*(void **)item + 0x8))(item);
                if (strcmp(name, lbl_8055C108) == 0) {
                    for (j = 0; j < 2; j++) {
                        count = *(int *)((char *)list + 4);
                        entry = (char *)*(void **)list + count * 0x38;
                        *(int *)((char *)list + 4) = count + 1;
                        src = ((char *(*)(void *, void *, int, void *))*(void **)((char *)*(void **)item + 0x14))(item, &lbl_8055C100, count, *(void **)list);
                        dst = entry;
                        n = 32;
                        while (n-- > 1) {
                            c = *src++;
                            *dst++ = c;
                            if (c == 0) break;
                        }
                        if (n <= 0) *dst = 0;
                        if (j != 0) {
                            dst = entry;
                            n = 32;
                            while (*dst != 0 && n > 0) { dst++; n--; }
                            if (n > 0) {
                                src = &lbl_8055C0FC;
                                while (n-- > 1) {
                                    c = *src++;
                                    *dst++ = c;
                                    if (c == 0) break;
                                }
                                if (n <= 0) *(dst - 1) = 0;
                            }
                        }
                        *(void **)(entry + 0x20) = fn_802CAC28(j ? &lbl_80344750 : &lbl_80344740, 0);
                        *(void **)(entry + 0x24) = fn_802CAC28(j ? &lbl_80344730 : &lbl_80344720, 0);
                        *(float *)(entry + 0x28) = ((float (*)(void *, void *))*(void **)((char *)*(void **)item + 0x24))(item, &lbl_8055C0F8);
                        *(float *)(entry + 0x2C) = ((float (*)(void *, void *))*(void **)((char *)*(void **)item + 0x24))(item, &lbl_8055C0F4);
                        *(float *)(entry + 0x30) = ((float (*)(void *, void *))*(void **)((char *)*(void **)item + 0x24))(item, &lbl_8055C0F0);
                        *(float *)(entry + 0x34) = ((float (*)(void *, void *))*(void **)((char *)*(void **)item + 0x24))(item, &lbl_8055C0EC);
                    }
                }
            }
            fn_80131818(items);
        }
        lbl_8055F2E4 = list;
    }
    (void)tbl;
}

/* Destructor-like cleanup: clears a global state, zeroes fields at +0x18..+0x20
 * when present, and optionally deletes the object. */
void *fn_8025D96C(void *self, int shouldDelete)
{
  char *basePtr;
  unsigned int offset;
  if (self)
  {
    int zero = 0;
    basePtr = (char *) self;
    lbl_8055F3C4 = 0;
    if (((basePtr + 0x18) != 0) && ((((char *) self) + 0x18) != 0))
    {
      offset = 0x18;
      *((int *) (((char *) self) + offset)) = zero;
      *((int *) (((char *) self) + 0x1c)) = zero;
      *((int *) (((char *) self) + 0x20)) = zero;
    }
    if (shouldDelete > 0)
    {
      fn_80128668(self);
    }
  }
  return self;
}

/* Initialize a UI/record object: clear its status fields, load the "caricona.art" art set into +0x434,
 * copy the (empty) default name into the 20-byte inline buffer at +4, and point the name fields at it. */
void *fn_8025D9D0(void *self) {
#pragma scheduling invalid_target
    char *defaultName;
    int remaining;
    char *nameDst;
    char *defaultNameEnd;
    *(volatile int *)((char *)self + 0x420) = 0;
    *(volatile void **)((char *)self + 0x40C) = lbl_80345718;
    *(int *)((char *)self + 0x424) = 0;
    *((char *)self + 0x42C) = 0;
    *(void **)((char *)self + 0x434) = ((void *(*)(const char *))fn_8023512C)(lbl_80345694);
    nameDst = (char *)self + 4;
    *(void **)self = (void *)&lbl_8055C3E0;
    defaultName = (char *)&lbl_8055C3E0;
    remaining = 0x14;
    goto copy;
    do {
        if (--remaining <= 0) {
            nameDst[-1] = 0;
            break;
        }
    copy:
        *nameDst++ = *defaultName++;
    } while (nameDst[-1]);
    defaultNameEnd = (char *)&lbl_8055C3E0;
    *(int *)((char *)self + 0x408) = 0;
    *(void **)((char *)self + 0x1C) = defaultNameEnd;
    *(void **)((char *)self + 0x18) = defaultNameEnd;
    *((char *)self + 0x20) = 0;
    *((char *)self + 0x42C) = 0;
    return self;
}

/* Destructor for PSSystem::SeqHeap (address-suffixed variant): restore vtable, release the owned subobject/resource, and conditionally delete storage. */
void* __dt__Q28PSSystem7SeqHeapFv_8025DA88(void* seqHeap, int shouldDelete) {
    if (seqHeap != 0) {
        *(void**)seqHeap = lbl_80345718;
        fn_80235380(*(void**)((char*)seqHeap + 0x28), lbl_80345718);
        if (shouldDelete > 0) {
            fn_80128668(seqHeap);
        }
    }
    return seqHeap;
}

extern void *fn_8000DA10(void);
extern int fn_80012854(void);
extern void *fn_8001285C(int);
extern int fn_80012820(void *);
extern void *fn_80016510(int);
extern int fn_8001BA6C(void *);
extern void fn_8001BC38(void *, void *, void *, int, int);
extern int fn_8001BCF0(void *);
extern int fn_8001BD6C(void *, void *);
extern void fn_8001BD38(void *, void *, int);
extern void fn_8001BD54(void *, void *);
extern char *fn_80008188(void *);
extern char *fn_801345D8(char *, int, const char *, ...);
extern int stricmp(const char *, const char *);
static inline int FindRecord8025(const char *name, char *table) {
    int offset, index;
    for (index = 0, offset = 0; index < *(int *)(table + 4); offset += 0x38, index++) {
        if (stricmp(*(char **)table + offset, name) == 0) return index;
    }
    return -1;
}
extern char lbl_8055C3E4, lbl_8055C3E8, lbl_8055C3EC, lbl_8055C3F8;
extern char lbl_803456A4[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8025DAEC(void *arg0, void *arg1) {
    /* Select the best matching record for arg1, copy its display/name data into arg0, or fill defaults if none found. */
    struct Source {
        virtual void s2();
        virtual int has(const char *);
        virtual void s4();
        virtual char *get(const char *);
    };
    char current[0x24], best[0x24], selected[0x24];
    int best_i=-1, j, i, best_j=-1;
    Record8025 record, result;
    char *obj=(char *)arg0;
    for (j=0;j<3;j++) {
        for(i=0;i<fn_80012854();i++) {
            fn_8001BC38(current,fn_8000DA10(),arg1,i,j);
            if (fn_8001BCF0(current)) {
                if(best_i<0) { best_i=i; best_j=j; }
                else {
                    fn_8001BC38(best,fn_8000DA10(),arg1,best_i,best_j);
                    if(fn_8001BD6C(current,best)) { best_i=i; best_j=j; }
                }
            }
        }
    }
    *(int *)obj=fn_8001BA6C(arg1);
    if(best_i<0) {
        const char *src=&lbl_8055C3E4;
        int n=0x14;
        char *dst=obj+4;
        goto copy1;
        do { if (--n <= 0) { dst[-1]=0; break; }
copy1:      *dst++=*src++; } while(dst[-1]);
        dst=obj+0x20; src=&lbl_8055C3E8; n=0x3e8;
        goto copy2;
        do { if (--n <= 0) { dst[-1]=0; break; }
copy2:      *dst++=*src++; } while(dst[-1]);
        *(char **)(obj+0x1c)=&lbl_8055C3E4;
        best_j=0;
        *(char **)(obj+0x18)=&lbl_8055C3E4;
    } else {
        char *entry;
        char *value;
        char *details;
        char *table;
        int index, offset;
        int cat;
        fn_8001BC38(selected,fn_8000DA10(),arg1,best_i,best_j);
        fn_8001BD38(selected,obj+4,0x14);
        entry=(char *)fn_8001285C(best_i);
        if((*(Source **)(entry+0x20))->has(&lbl_8055C3EC))
            *(char **)(obj+0x18)=fn_80008188((*(Source **)(entry+0x20))->get(&lbl_8055C3EC));
        else
            *(char **)(obj+0x18)=fn_80008188((void *)(fn_80012820(*(void **)(entry+4))+8));
        value=(*(Source **)(entry+0x20))->get(lbl_803456A4);
        *(char **)(obj+0x1c)=value;
        fn_801345D8(obj+0x20,0x3e8,&lbl_8055C3F8,*(char **)(obj+0x18),value+1);
        fn_8001BD54(&result,selected);
        record=result;
        cat=record.category;
        obj[0x438]=*(char *)&record.flags;
        details=(char *)fn_80016510(record.id);
        index=FindRecord8025(details+0x2c,*(char **)(obj+0x424));
        *(int *)(obj+0x428)=index;
        *(int *)(obj+0x430)=*(int *)(details+cat*4+0x64);
        obj[0x42c]=1;
    }
    *(int *)(obj+0x408)=best_j;
}

#pragma cplusplus reset
#pragma scheduling invalid_target
#pragma processor 750
#pragma paired_single off
void fn_8025DDD0(void *arg0, int arg1) {
    float spC, sp8, outC, out8, f25, f24, f26, f27, f28, f29;
    float tmpA, tmpB;
    unsigned int color, packed;
    int blue, green, red;
    char *item;
    if (*(unsigned char *)((char *)arg0 + 0x20) == 0)
        return;
    fn_80230C30(&spC, &sp8, *(int *)((char *)arg0 + 4), *(int *)((char *)arg0 + 8));
    f25 = (float)*(int *)((char *)arg0 + 0xC);
    f24 = (float)*(int *)((char *)arg0 + 0x10);
    tmpA = spC - lbl_80563B58;
    tmpB = lbl_80563B58 + sp8;
    fn_802354A0(*(int *)((char *)arg0 + 0x28), *(unsigned char *)((char *)arg0 + 0x2C), -1, tmpA, tmpB, lbl_80563B5C, lbl_80563B60 + f25, lbl_80563B60 + f24);
    item = *(char **)((char *)arg0 + 0x18) + *(int *)((char *)arg0 + 0x1C) * 0x38;
    out8 = sp8;
    outC = spC;
    f26 = *(float *)(item + 0x28);
    f27 = *(float *)(item + 0x2C);
    f28 = *(float *)(item + 0x30);
    f29 = *(float *)(item + 0x34);
    color = *(unsigned int *)((char *)arg0 + 0x24);
    fn_80231220(*(int *)(item + 0x20), -1, outC, out8, f25, f24, f26, f27, f28, f29);
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
    fn_80231220(*(int *)(item + 0x24), packed, outC, out8, f25, f24, f26, f27, f28, f29);
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8025DF80(void *arg0) {
    /* Notify each entry in the object's list (array at offset 0x18, count at 0x1C). */
    register long *object = (long *)arg0;
    register long byteOffset = 0;
    register long index = 0;
    goto check;
loop:
    fn_80214A9C(*(long *)((unsigned char *)object[6] + byteOffset));
    byteOffset += 4;
    index++;
check:
    if (index < object[7])
        goto loop;
}
#pragma pop
extern void *fn_8000DA10(void); extern int fn_80012854(void); extern void *fn_8001285C(int); extern int fn_80012820(void *); extern void *fn_80016510(int); extern int fn_8001BA6C(void *); extern void fn_8001BC38(void *, void *, void *, int, int); extern int fn_8001BCF0(void *); extern int fn_8001BD6C(void *, void *); extern void fn_8001BD38(void *, void *, int); extern void fn_8001BD54(void *, void *); extern char *fn_80008188(void *); extern char *fn_801345D8(char *, int, const char *, ...); extern int stricmp(const char *, const char *); extern char lbl_8055C3E4, lbl_8055C3E8, lbl_8055C3EC, lbl_8055C3F8; extern char lbl_803456A4[];
