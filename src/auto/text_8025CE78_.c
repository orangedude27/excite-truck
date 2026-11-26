typedef struct { int id, category, flags; } Record8025;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80345718[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);
extern int lbl_8055F3C4;
extern void fn_80128668(void *);
extern void fn_80214A9C(int);
extern void *ArtSetGet(void *, void *, void *);
extern char lbl_80345694[];
extern int lbl_8055C3E0;
extern double lbl_80563B68;
extern float lbl_80563B58, lbl_80563B5C, lbl_80563B60;
extern void fn_80230C30(float *, float *, int, int);
extern void drawPictureScaled(int, unsigned char, int, float, float, float, float, float);
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
extern void *RegisterTextureByName(void *, int);
extern void fn_80131818(void *);
extern int strcmp(const char *, const char *);
extern void fn_802146BC();
extern void fn_802CAC54(void *);
extern int fn_80128670(void *);
extern char lbl_80498ED0[];
extern char lbl_802FA678[];
extern char lbl_8055B860[];
extern char lbl_803456B8[];
extern void fn_8025DAEC(void *, void *);
#define sp8 low.f8
#define spC low.fC
#define sp10 low.f10
#define sp14 low.f14
#define sp18 low.f18
#define sp1C low.f1C
#define sp30 low.f30
#define sp34 low.f34
#define sp38 low.f38
#define sp3C low.f3C
#define sp40 low.f40
#define desc low.fd
#define DS(off) desc[(((off) - 0xB8) >> 2)]
#define APPEND(v) { int *_d=(int*)(long)lbl_8055F3C4; int _i=_d[7]; _d[7]=_i+1; ((int*)_d[6])[_i]=(v); }
#pragma use_lmw_stmw off
void fn_8025CE78(void) {
    char buf6[0x43C], buf5[0x43C], buf4[0x43C], buf3[0x43C];
    char buf2[0x43C], buf1[0x43C], buf0[0x43C];
    struct {
        int f8;
        int *fC;
        int f10, f14, f18;
        void *f1C;
        char pad[16];
        int f30, f34, f38, f3C;
        int f40[30];
        int fd[155];
    } low;
    void *list, **items, *item;
    char *name, *entry, *src, *dst;
    char c;
    int heapType, i, j, count, n;
    void *base;
    int heap2;
    heapType = fn_80012810();
    if (heapType != 304) { fn_80012794(); fn_80012790(304); }
    fn_8025D9D0(buf0); fn_8025D9D0(buf1); fn_8025D9D0(buf2); fn_8025D9D0(buf3);
    fn_8025D9D0(buf4); fn_8025D9D0(buf5); fn_8025D9D0(buf6);
    if (lbl_8055F2E8 == 0) {
        list = fn_801284F8(8, &lbl_8055C114);
        if (list != 0) {
            items = fn_80131808(&lbl_80344760);
            *(int *)((char *)list + 4) = 0;
            *(void **)list = fn_8012850C(0xaf0, &lbl_8055C10C);
            for (i = 0; ; i++) {
                item = ((void *(*)(void *, int))*(void **)((char *)*items + 0xC))(items, i);
                if (item == 0) break;
                name = ((char *(*)(void *))*(void **)((char *)item + 0x8))(item);
                if (strcmp(name, lbl_8055C108) == 0) {
                    for (j = 0; j < 2; j++) {
                        count = *(int *)((char *)list + 4);
                        entry = (char *)*(void **)list + count * 0x38;
                        *(int *)((char *)list + 4) = count + 1;
                        src = ((char *(*)(void *, void *, int, void *))*(void **)((char *)item + 0x14))(item, &lbl_8055C100, count, *(void **)list);
                        dst = entry; n = 32;
                        while (n-- > 1) { c = *src++; *dst++ = c; if (c == 0) break; }
                        if (n <= 0) *dst = 0;
                        if (j != 0) {
                            dst = entry; n = 32;
                            while (*dst != 0 && n > 0) { dst++; n--; }
                            if (n > 0) {
                                src = &lbl_8055C0FC;
                                while (n-- > 1) { c = *src++; *dst++ = c; if (c == 0) break; }
                                if (n <= 0) *(dst - 1) = 0;
                            }
                        }
                        *(void **)(entry + 0x20) = RegisterTextureByName(j ? &lbl_80344750 : &lbl_80344740, 0);
                        *(void **)(entry + 0x24) = RegisterTextureByName(j ? &lbl_80344730 : &lbl_80344720, 0);
                        *(float *)(entry + 0x28) = ((float (*)(void *, void *))*(void **)((char *)item + 0x24))(item, &lbl_8055C0F8);
                        *(float *)(entry + 0x2C) = ((float (*)(void *, void *))*(void **)((char *)item + 0x24))(item, &lbl_8055C0F4);
                        *(float *)(entry + 0x30) = ((float (*)(void *, void *))*(void **)((char *)item + 0x24))(item, &lbl_8055C0F0);
                        *(float *)(entry + 0x34) = ((float (*)(void *, void *))*(void **)((char *)item + 0x24))(item, &lbl_8055C0EC);
                    }
                }
            }
            fn_80131818(items);
        }
        lbl_8055F2E4 = list;
    }
    lbl_8055F2E8++;
    *(void **)(buf0 + 0x424) = lbl_8055F2E4; *(void **)(buf1 + 0x424) = lbl_8055F2E4;
    *(void **)(buf2 + 0x424) = lbl_8055F2E4; *(void **)(buf3 + 0x424) = lbl_8055F2E4;
    *(void **)(buf4 + 0x424) = lbl_8055F2E4; *(void **)(buf5 + 0x424) = lbl_8055F2E4;
    *(void **)(buf6 + 0x424) = lbl_8055F2E4;
    sp30 = 0; sp1C = &lbl_803456B8; sp34 = (int)&sp40[0]; sp3C = 0x1E; sp38 = 0;
    lbl_8055F3C4 = (int)(long)&sp1C;
    ((void (*)(void *, int, int, void *, void *, int, void *))fn_8025DAEC)(buf0, 0x40901, 0x1E, &sp40[0], &lbl_803456B8, 0, lbl_8055F2E4);
    if (*(int *)(buf0 + 0x408) != 0) APPEND(1);
    if (*(int *)(buf0 + 0x408) != 1) APPEND(0xB);
    if (*(int *)(buf0 + 0x408) != 2) APPEND(0x15);
    fn_8025DAEC(buf1, (void *)0x40902);
    if (*(int *)(buf1 + 0x408) != 0) APPEND(2);
    if (*(int *)(buf1 + 0x408) != 1) APPEND(0xC);
    if (*(int *)(buf1 + 0x408) != 2) APPEND(0x16);
    fn_8025DAEC(buf2, (void *)0x41206);
    if (*(int *)(buf2 + 0x408) != 0) APPEND(3);
    if (*(int *)(buf2 + 0x408) != 1) APPEND(0xD);
    if (*(int *)(buf2 + 0x408) != 2) APPEND(0x17);
    fn_8025DAEC(buf3, (void *)0x48203);
    if (*(int *)(buf3 + 0x408) != 0) APPEND(4);
    if (*(int *)(buf3 + 0x408) != 1) APPEND(0xE);
    if (*(int *)(buf3 + 0x408) != 2) APPEND(0x18);
    fn_8025DAEC(buf4, (void *)0x50204);
    if (*(int *)(buf4 + 0x408) != 0) APPEND(5);
    if (*(int *)(buf4 + 0x408) != 1) APPEND(0xF);
    if (*(int *)(buf4 + 0x408) != 2) APPEND(0x19);
    DS(0xC0) = (int)&sp1C; DS(0xCC) = (int)(lbl_803454C8 + 0xC); DS(0xBC) = 5;
    DS(0xB8) = 0; DS(0xC4) = 0; DS(0xC8) = 0; DS(0xD0) = 3;
    DS(0xD4) = *(int *)(buf0 + 0); DS(0xD8) = 0; DS(0xDC) = 0; DS(0xE4) = 3;
    DS(0xE0) = (int)(lbl_803454C8 + 0x1C); DS(0xE8) = (int)(buf0 + 4);
    DS(0xEC) = 0; DS(0xF0) = 0; DS(0xF8) = 3;
    DS(0xF4) = (int)(lbl_803454C8 + 0x2C); DS(0xFC) = (int)(buf0 + 0x20);
    DS(0x100) = 0; DS(0x104) = 0; DS(0x10C) = 5;
    DS(0x108) = (int)(lbl_803454C8 + 0x40); DS(0x110) = (int)(buf0 + 0x40C);
    DS(0x114) = 0; DS(0x118) = 0; DS(0x120) = 3;
    DS(0x11C) = (int)(lbl_803454C8 + 0x4C); DS(0x124) = *(int *)(buf1 + 0);
    DS(0x128) = 0; DS(0x12C) = 0; DS(0x134) = 3;
    DS(0x130) = (int)(lbl_803454C8 + 0x5C); DS(0x138) = (int)(buf1 + 4);
    DS(0x13C) = 0; DS(0x140) = 0; DS(0x148) = 3;
    DS(0x144) = (int)(lbl_803454C8 + 0x6C); DS(0x14C) = (int)(buf1 + 0x20);
    DS(0x150) = 0; DS(0x154) = 0; DS(0x15C) = 5;
    DS(0x158) = (int)(lbl_803454C8 + 0x80); DS(0x160) = (int)(buf1 + 0x40C);
    DS(0x164) = 0; DS(0x168) = 0; DS(0x16C) = (int)(lbl_803454C8 + 0x8C);
    DS(0x174) = *(int *)(buf2 + 0); DS(0x170) = 3; DS(0x178) = 0; DS(0x17C) = 0; DS(0x184) = 3;
    DS(0x180) = (int)(lbl_803454C8 + 0x9C); DS(0x188) = (int)(buf2 + 4);
    DS(0x18C) = 0; DS(0x190) = 0; DS(0x198) = 3;
    DS(0x194) = (int)(lbl_803454C8 + 0xAC); DS(0x19C) = (int)(buf2 + 0x20);
    DS(0x1A0) = 0; DS(0x1A4) = 0; DS(0x1AC) = 5;
    DS(0x1A8) = (int)(lbl_803454C8 + 0xC0); DS(0x1B0) = (int)(buf2 + 0x40C);
    DS(0x1B4) = 0; DS(0x1B8) = 0; DS(0x1C0) = 3;
    DS(0x1BC) = (int)(lbl_803454C8 + 0xCC); DS(0x1C4) = *(int *)(buf3 + 0);
    DS(0x1C8) = 0; DS(0x1CC) = 0; DS(0x1D4) = 3;
    DS(0x1D0) = (int)(lbl_803454C8 + 0xDC); DS(0x1D8) = (int)(buf3 + 4);
    DS(0x1DC) = 0; DS(0x1E0) = 0; DS(0x1E8) = 3;
    DS(0x1E4) = (int)(lbl_803454C8 + 0xEC); DS(0x1EC) = (int)(buf3 + 0x20);
    DS(0x1F0) = 0; DS(0x1F4) = 0; DS(0x1FC) = 5;
    DS(0x1F8) = (int)(lbl_803454C8 + 0x100); DS(0x200) = (int)(buf3 + 0x40C);
    DS(0x204) = 0; DS(0x208) = 0; DS(0x210) = 3;
    DS(0x20C) = (int)(lbl_803454C8 + 0x10C); DS(0x214) = *(int *)(buf4 + 0);
    DS(0x220) = (int)(lbl_803454C8 + 0x11C); DS(0x228) = (int)(buf4 + 4);
    DS(0x218) = 0; DS(0x21C) = 0; DS(0x224) = 3; DS(0x22C) = 0; DS(0x230) = 0; DS(0x238) = 3;
    DS(0x234) = (int)(lbl_803454C8 + 0x12C); DS(0x23C) = (int)(buf4 + 0x20);
    DS(0x240) = 0; DS(0x244) = 0; DS(0x24C) = 5;
    DS(0x248) = (int)(lbl_803454C8 + 0x140); DS(0x250) = (int)(buf4 + 0x40C);
    DS(0x254) = 0; DS(0x258) = 0; DS(0x260) = 3;
    DS(0x25C) = (int)(lbl_803454C8 + 0x14C); DS(0x264) = *(int *)(buf5 + 0);
    DS(0x268) = 0; DS(0x26C) = 0; DS(0x274) = 3;
    DS(0x270) = (int)(lbl_803454C8 + 0x15C); DS(0x278) = (int)(buf5 + 4);
    DS(0x27C) = 0; DS(0x280) = 0; DS(0x288) = 3;
    DS(0x284) = (int)(lbl_803454C8 + 0x16C); DS(0x28C) = (int)(buf5 + 0x20);
    DS(0x290) = 0; DS(0x294) = 0; DS(0x29C) = 5;
    DS(0x298) = (int)(lbl_803454C8 + 0x180); DS(0x2A0) = (int)(buf5 + 0x40C);
    DS(0x2A4) = 0; DS(0x2A8) = 0; DS(0x2B0) = 3;
    DS(0x2AC) = (int)(lbl_803454C8 + 0x18C); DS(0x2B4) = *(int *)(buf6 + 0);
    DS(0x2B8) = 0; DS(0x2BC) = 0; DS(0x2C4) = 3;
    DS(0x2C0) = (int)(lbl_803454C8 + 0x19C);
    base = lbl_803454C8 + 0x1AC;
    DS(0x2C8) = (int)(buf6 + 4); DS(0x2CC) = 0; DS(0x2D0) = 0; DS(0x2D8) = 3;
    DS(0x2D4) = (int)base; DS(0x2DC) = (int)(buf6 + 0x20);
    DS(0x2E0) = 0; DS(0x2E4) = 0; DS(0x2EC) = 5;
    DS(0x2E8) = (int)(lbl_803454C8 + 0x1C0); DS(0x2F0) = (int)(buf6 + 0x40C);
    DS(0x2F4) = 0; DS(0x2F8) = 0; DS(0x300) = 6;
    DS(0x2FC) = (int)&lbl_8055B860; DS(0x304) = 0; DS(0x308) = -1; DS(0x30C) = 0x1B;
    DS(0x310) = *(int *)(lbl_80498ED0 + 0); DS(0x314) = *(int *)(lbl_80498ED0 + 4);
    DS(0x318) = *(int *)(lbl_80498ED0 + 8); DS(0x31C) = *(int *)(lbl_80498ED0 + 0xC);
    DS(0x320) = *(int *)(lbl_80498ED0 + 0x10);
    sp8 = *(int *)(lbl_802FA678 + 0); sp10 = *(int *)(lbl_802FA678 + 8);
    sp14 = *(int *)(lbl_802FA678 + 0xC); sp18 = *(int *)(lbl_802FA678 + 0x10);
    spC = &desc[0];
    fn_802146BC(&sp8, -0x3E7, -0x3E7, 1, 0, 5, base, &desc[0]);
    heap2 = lbl_8055F2E8 - 1; lbl_8055F2E8 = heap2;
    if (heap2 == 0) {
        void *l = lbl_8055F2E4;
        if (l != 0) {
            int ci = 0, co = 0;
            while (ci < *(int *)((char *)l + 4)) {
                char *e = *(char **)l + co;
                fn_802CAC54(*(void **)(e + 0x20)); fn_802CAC54(*(void **)(e + 0x24));
                co += 0x38; ci++;
            }
            fn_80128670(*(void **)l); fn_80128668(l);
        }
        lbl_8055F2E4 = 0;
    }
    if (heapType != 304) { fn_80012794(); fn_80012790(heapType); }
    lbl_8055F3C4 = 0; sp34 = 0; sp38 = 0; sp3C = 0;
    *(void **)(buf6 + 0x40C) = &lbl_80345718; ((void (*)(void *))fn_80235380)(*(void **)(buf6 + 0x434));
    *(void **)(buf5 + 0x40C) = &lbl_80345718; ((void (*)(void *))fn_80235380)(*(void **)(buf5 + 0x434));
    *(void **)(buf4 + 0x40C) = &lbl_80345718; ((void (*)(void *))fn_80235380)(*(void **)(buf4 + 0x434));
    *(void **)(buf3 + 0x40C) = &lbl_80345718; ((void (*)(void *))fn_80235380)(*(void **)(buf3 + 0x434));
    *(void **)(buf2 + 0x40C) = &lbl_80345718; ((void (*)(void *))fn_80235380)(*(void **)(buf2 + 0x434));
    *(void **)(buf1 + 0x40C) = &lbl_80345718; ((void (*)(void *))fn_80235380)(*(void **)(buf1 + 0x434));
    *(void **)(buf0 + 0x40C) = &lbl_80345718; ((void (*)(void *))fn_80235380)(*(void **)(buf0 + 0x434));
}
#undef sp8
#undef spC
#undef sp10
#undef sp14
#undef sp18
#undef sp1C
#undef sp30
#undef sp34
#undef sp38
#undef sp3C
#undef sp40
#undef desc
#undef DS
#undef APPEND

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
    *(void **)((char *)self + 0x434) = ((void *(*)(const char *))ArtSetGet)(lbl_80345694);
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

#pragma scheduling invalid_target
#pragma processor 750
#pragma paired_single off
extern "C" void fn_8025DDD0(void *arg0, int arg1) {
    float spC, sp8, outC, out8, f29, f28, f27, f26, f25, f24;
    float tmpA, tmpB;
    unsigned int color, packed;
    int blue, green, red;
    char *item;
    if (*(unsigned char *)((char *)arg0 + 0x20) == 0)
        return;
    fn_80230C30(&spC, &sp8, *(int *)((char *)arg0 + 4), *(int *)((char *)arg0 + 8));
    f25 = (float)*(int *)((char *)arg0 + 0xC);
    tmpA = spC - lbl_80563B58;
    tmpB = lbl_80563B58 + sp8;
    f24 = (float)*(int *)((char *)arg0 + 0x10);
    drawPictureScaled(*(int *)((char *)arg0 + 0x28), *(unsigned char *)((char *)arg0 + 0x2C), -1,
        tmpA, tmpB, lbl_80563B5C,
        lbl_80563B60 + f25, lbl_80563B60 + f24);
    item = (char *)**(void ***)((char *)arg0 + 0x18) + *(int *)((char *)arg0 + 0x1C) * 0x38;
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
    fn_80231220(*(int *)(item + 0x24), packed,
        outC, out8, f25, f24, f26, f27, f28, f29);
}
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
