// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    int v[5];
} MenuHeader;

typedef struct {
    void *label;
    int type;
    void *value;
    int flags;
    int id;
} MenuEntry;

typedef struct {
    MenuHeader header;
    MenuEntry entries[6];
    MenuHeader footer;
} Menu;

extern int lbl_8055BAC0, lbl_8055BABC, lbl_8055C394, lbl_8055C39C, lbl_8055B860;
extern char lbl_80345264[];
extern MenuHeader lbl_80498EB8, lbl_802FA650;
extern int fn_802146BC(void *, int, int, int);
extern void fn_8025A50C(void), fn_8025CE78(void), fn_8025E034(void);

extern void* lbl_8055C390;
extern void fn_80214CB4(void*);
extern void* fn_80214D04(void);
extern int lbl_8055F2E8;
extern int lbl_8055F2E4;
extern void *fn_801284F8(int, void *);
extern char lbl_803453B8[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);

/* Menu action: capture the active window's current menu index (fn_80214D04)
   into the saved selection lbl_8055C390, so the companion action fn_8025C04C
   can later restore it via fn_80214CB4. */
void fn_8025C028(void) {
    lbl_8055C390 = fn_80214D04();
}

/* Menu action: restore the previously saved menu selection from lbl_8055C390
   back into the active window via fn_80214CB4 (the inverse of fn_8025C028). */
void fn_8025C04C(void) {
    fn_80214CB4(lbl_8055C390);
}

/* Destroy a PSSystem::SeqHeap: install its vtable, release the owned subobject at +0x28, and optionally delete storage. */
void* __dt__Q28PSSystem7SeqHeapFv_8025CC14(void* self, int shouldDelete) {
    if (self != 0) {
        *(void**)self = lbl_803453B8;
        fn_80235380(*(void**)((char*)self + 0x28), lbl_803453B8);
        if (shouldDelete > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

extern void fn_80230C30(float*, float*, int, int);
extern void drawPictureScaled(int, unsigned char, int, float, float, float, float, float);
extern void drawTexturedQuad(int, int, float, float, float, float, float, float, float, float);
extern float lbl_80563B40, lbl_80563B44, lbl_80563B48;
extern double lbl_80563B50;
#pragma scheduling invalid_target
#pragma processor 750
#pragma paired_single off
void fn_8025CC78(void* p, int arg1) {
    float spC, sp8, outC, out8, f29, f28, f27, f26, f25, f24;
    float tmpA, tmpB;
    unsigned int color, packed;
    int blue, green, red;
    char* item;
    if (*(unsigned char*)((char*)p + 0x20) == 0)
        return;
    fn_80230C30(&spC, &sp8, *(int*)((char*)p + 4), *(int*)((char*)p + 8));
    f25 = (float)*(int*)((char*)p + 0xC);
    tmpA = spC - lbl_80563B40;
    tmpB = lbl_80563B40 + sp8;
    f24 = (float)*(int*)((char*)p + 0x10);
    drawPictureScaled(*(int*)((char*)p + 0x28), *(unsigned char*)((char*)p + 0x2C), -1,
        tmpA, tmpB, lbl_80563B44,
        lbl_80563B48 + f25, lbl_80563B48 + f24);
    item = (char*)**(void***)((char*)p + 0x18) + *(int*)((char*)p + 0x1C) * 0x38;
    out8 = sp8;
    outC = spC;
    f26 = *(float*)(item + 0x28);
    f27 = *(float*)(item + 0x2C);
    f28 = *(float*)(item + 0x30);
    f29 = *(float*)(item + 0x34);
    color = *(unsigned int*)((char*)p + 0x24);
    drawTexturedQuad(*(int*)(item + 0x20), -1, outC, out8, f25, f24, f26, f27, f28, f29);
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
    drawTexturedQuad(*(int*)(item + 0x24), packed,
        outC, out8, f25, f24, f26, f27, f28, f29);
}
#pragma scheduling on
#pragma push
#pragma use_lmw_stmw off
void fn_8025C054(void)
{
  int running;
  Menu menu;
  menu.entries[0].type = 8;
  menu.entries[0].label = &lbl_8055BAC0;
  menu.entries[0].value = (void *) fn_8025C04C;
  menu.entries[0].flags = 0;
  menu.entries[0].id = 0;
  menu.entries[1].type = 8;
  menu.entries[1].id = 0;
  menu.entries[1].label = &lbl_8055BABC;
  menu.entries[1].value = (void *) fn_8025C028;
  menu.entries[1].flags = 1;
  menu.entries[2].type = 0;
  menu.entries[2].label = lbl_80345264;
  menu.entries[2].value = 0;
  menu.entries[2].flags = 0;
  menu.entries[2].id = 0;
  menu.entries[3].type = 0;
  menu.entries[3].id = 0;
  menu.entries[3].label = &lbl_8055C394;
  menu.entries[3].value = 0;
  menu.entries[3].flags = 1;
  menu.entries[4].type = 0;
  menu.entries[4].label = &lbl_8055C39C;
  menu.entries[4].value = 0;
  menu.entries[4].flags = 2;
  menu.entries[4].id = 0;
  menu.entries[5].type = 6;
  menu.entries[5].label = &lbl_8055B860;
  menu.entries[5].value = 0;
  menu.entries[5].flags = -1;
  menu.entries[5].id = 0x1B;
  menu.footer.v[0] = lbl_80498EB8.v[0];
  menu.footer.v[1] = lbl_80498EB8.v[1];
  menu.footer.v[2] = lbl_80498EB8.v[2];
  menu.footer.v[3] = lbl_80498EB8.v[3];
  menu.footer.v[4] = lbl_80498EB8.v[4];
  menu.header = lbl_802FA650;
  menu.header.v[1] = (int) menu.entries;
  running = 1;
  while (running)
  {
    switch (fn_802146BC(menu.header.v, -999, -999, 1))
    {
      case 0:
        fn_8025A50C();
        break;

      case 1:
        fn_8025CE78();
        break;

      case 2:
        fn_8025E034();
        break;

      case -1:

      default:
        running = 0;
        break;

    }

  }

}

typedef struct {
    int a;
    int b;
    unsigned char c;
} EntryRef_8025C204;

typedef struct {
    void *vtable;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    void *f18;
    int f1C;
    unsigned char f20;
    unsigned char pad21[3];
    int f24;
    void *f28;
    unsigned char f2C;
    unsigned char pad2D[3];
} Obj8025C204;

typedef struct {
    char name[0x14];
    void *icon;
    char time[0x14];
} Rec8025C204;

typedef struct {
    MenuEntry entries[24];
    MenuHeader footer;
} MenuBody_8025C204;

extern MenuHeader lbl_802FA664;
extern char lbl_80344720[], lbl_80344730[], lbl_80344740[], lbl_80344750[], lbl_80344760[];
extern char lbl_80345258[];
__declspec(section ".data") extern float lbl_80558DC0;
__declspec(section ".sdata") extern char lbl_8055C0EC[], lbl_8055C0F0[], lbl_8055C0F4[], lbl_8055C0F8[];
__declspec(section ".sdata") extern char lbl_8055C0FC[], lbl_8055C100[], lbl_8055C108[], lbl_8055C10C[], lbl_8055C114[];
__declspec(section ".sdata") extern char lbl_8055C3A4[], lbl_8055C3A8[], lbl_8055C3B0[];
__declspec(section ".sdata") extern char lbl_8055C3B8[], lbl_8055C3C0[], lbl_8055C3C8[], lbl_8055C3D0[], lbl_8055C3D8[];

extern int __AXGetStackHead(int);
extern int getEventDisplayName(int);
extern int fn_8000DA10(void);
extern char *fn_80012820(int);
extern void *fn_8001285C(int);
extern char *fn_80016510(int);
extern void *fn_8001BB58(int, int, int, int);
extern void fn_8001BBBC(EntryRef_8025C204 *, int);
extern int fn_8001BCF0(void *);
extern void *fn_8001BE94(void *, int, int, int, int);
extern float fn_8001BEE8(void *);
extern void *fn_8012850C(int, void *);
extern void fn_80128670(void *);
extern void fn_801308F4(char *, int, int);
extern void fn_80130980(char *, int, int, float);
extern char *fn_80131234(void *);
extern void **getValueFile(void *);
extern void releaseValueFile(void *);
extern void fn_801345D8(char *, int, const char *, ...);
extern void *fn_80214A9C(int);
extern void *fn_80214AF0(int);
extern void *fn_802168E4(void);
extern void *ArtSetGet(void *);
extern int RegisterTextureByName(void *, int);
extern void fn_802CAC54(int);
extern int strcmp(const char *, const char *);
extern int stricmp(const char *, const char *);

static inline void copyStr_8025C204(char *dst, const char *src, int n) {
    char c;
    goto check;
dec:
    if (--n <= 0) {
        dst[-1] = 0;
        return;
    }
check:
    c = *src++;
    *dst++ = c;
    if (c != 0) goto dec;
}

static inline void catStr_8025C204(char *dst, const char *src, int n) {
    char c;
    goto scan_check;
scan_dec:
    n--;
    dst++;
scan_check:
    c = *dst;
    if (c != 0) goto scan_dec;
    if (n > 0) {
        goto copy_check;
    copy_dec:
        if (--n <= 0) {
            dst[-1] = 0;
            return;
        }
    copy_check:
        c = *src++;
        *dst++ = c;
        if (c != 0) goto copy_dec;
    }
}
void fn_8025C204(int arg0, int arg1) {
    char title[0x3E8];
    MenuBody_8025C204 menu;
    Rec8025C204 recs[5];
    Obj8025C204 objs[5];
    unsigned char rec48[0x28];
    char str14[0x14];
    MenuHeader header;
    EntryRef_8025C204 ref2;
    EntryRef_8025C204 ref1;

    char *base;
    void *list;
    void **items;
    void *item;
    char *name;
    char *entry;
    char *src;
    int i;
    int j;
    int count;
    void *carIcons;
    void *recEntry;
    float bestTime;
    char *details;
    char **arr;
    int k;
    int off;
    void *trackEntry;
    char *trackName;
    char *subName;
    int isNotSpecial;
    char *s;
    void *win;
    int heap2;

    base = lbl_80345258;
    if (lbl_8055F2E8 == 0) {
        list = fn_801284F8(8, lbl_8055C114);
        if (list != 0) {
            items = getValueFile(lbl_80344760);
            *(int *)((char *)list + 4) = 0;
            *(void **)list = fn_8012850C(0xAF0, lbl_8055C10C);
            i = 0;
            while ((item = ((void *(*)(void *, int))(*(void ***)items)[3])(items, i)) != 0) {
                name = ((char *(*)(void *))(*(void ***)item)[2])(item);
                if (strcmp(name, lbl_8055C108) == 0) {
                    for (j = 0; j < 2; j++) {
                        count = *(int *)((char *)list + 4);
                        entry = (char *)*(void **)list + count * 0x38;
                        *(int *)((char *)list + 4) = count + 1;
                        src = ((char *(*)(void *, char *))(*(void ***)item)[5])(item, lbl_8055C100);
                        copyStr_8025C204(entry, src, 0x20);
                        if (j != 0) {
                            catStr_8025C204(entry, lbl_8055C0FC, 0x20);
                        }
                        *(int *)(entry + 0x20) = RegisterTextureByName(j != 0 ? lbl_80344750 : lbl_80344740, 0);
                        *(int *)(entry + 0x24) = RegisterTextureByName(j != 0 ? lbl_80344730 : lbl_80344720, 0);
                        *(float *)(entry + 0x28) = ((float (*)(void *, char *))(*(void ***)item)[9])(item, lbl_8055C0F8);
                        *(float *)(entry + 0x2C) = ((float (*)(void *, char *))(*(void ***)item)[9])(item, lbl_8055C0F4);
                        *(float *)(entry + 0x30) = ((float (*)(void *, char *))(*(void ***)item)[9])(item, lbl_8055C0F0);
                        *(float *)(entry + 0x34) = ((float (*)(void *, char *))(*(void ***)item)[9])(item, lbl_8055C0EC);
                    }
                }
                i++;
            }
            releaseValueFile(items);
            lbl_8055F2E4 = (int)list;
        }
    }
    lbl_8055F2E8++;
    carIcons = (void *)lbl_8055F2E4;

    objs[0].f14 = 0;
    objs[0].vtable = lbl_803453B8;
    objs[0].f18 = 0;
    objs[0].f20 = 0;
    objs[0].f28 = ArtSetGet(base + 0x2C);

    objs[1].f14 = 0;
    objs[1].vtable = lbl_803453B8;
    objs[1].f18 = 0;
    objs[1].f20 = 0;
    objs[1].f28 = ArtSetGet(base + 0x2C);

    objs[2].f14 = 0;
    objs[2].vtable = lbl_803453B8;
    objs[2].f18 = 0;
    objs[2].f20 = 0;
    objs[2].f28 = ArtSetGet(base + 0x2C);

    objs[3].f14 = 0;
    objs[3].vtable = lbl_803453B8;
    objs[3].f18 = 0;
    objs[3].f20 = 0;
    objs[3].f28 = ArtSetGet(base + 0x2C);

    objs[4].f14 = 0;
    objs[4].vtable = lbl_803453B8;
    objs[4].f18 = 0;
    objs[4].f20 = 0;
    objs[4].f28 = ArtSetGet(base + 0x2C);

    for (i = 0; i < 5; i++) {
        objs[i].f18 = carIcons;
        objs[i].f20 = 0;
    }
    for (i = 0; i < 5; i++) {
        copyStr_8025C204(recs[i].name, lbl_8055C3A4, 0x14);
        recs[i].icon = lbl_8055C3A4;
        bestTime = -lbl_80558DC0;
        recEntry = fn_8001BB58(fn_8000DA10(), arg0, arg1, i);
        if (recEntry != 0) {
            fn_801308F4(recs[i].name, 0x14, *(int *)((char *)recEntry + 4));
            if (*(int *)((char *)recEntry + 8) != -1) {
                recs[i].icon = (void *)__AXGetStackHead(*(int *)((char *)recEntry + 8));
            }
            bestTime = *(float *)((char *)recEntry + 0xC);
            objs[i].f20 = 1;
            fn_8001BBBC(&ref1, *(int *)((char *)recEntry + 0x10));
            ref2 = ref1;
            objs[i].f2C = ref2.c;
            details = fn_80016510(ref2.a);
            arr = (char **)objs[i].f18;
            k = 0;
            off = 0;
            while (k < *(int *)(arr + 1)) {
                if (stricmp(*arr + off, details + 0x2C) == 0) goto found_car;
                off += 0x38;
                k++;
            }
            k = -1;
        found_car:
            objs[i].f1C = k;
            objs[i].f24 = *(int *)(details + ref2.b * 4 + 0x64);
        }
        fn_80130980(recs[i].time, 0x14, 3, bestTime);
    }
    trackEntry = fn_8001285C(arg0);
    if (((int (*)(void *, char *))(*(void ***)*(void **)((char *)trackEntry + 0x20))[3])(*(void **)((char *)trackEntry + 0x20), lbl_8055C3A8) != 0) {
        trackName = (char *)getEventDisplayName(((int (*)(void *, char *))(*(void ***)*(void **)((char *)trackEntry + 0x20))[5])(*(void **)((char *)trackEntry + 0x20), lbl_8055C3A8));
    } else {
        trackName = (char *)getEventDisplayName((int)(fn_80012820(*(int *)((char *)trackEntry + 4)) + 8));
    }
    subName = ((char *(*)(void *, char *))(*(void ***)*(void **)((char *)trackEntry + 0x20))[5])(*(void **)((char *)trackEntry + 0x20), base + 0x3C);
    fn_801345D8(title, 0x3E8, lbl_8055C3B0, trackName, subName + 1);
    isNotSpecial = (*(int *)((char *)fn_8001285C(arg0) + 8) != 0x180302);
    s = fn_80131234(base + 0x4C);
    if (isNotSpecial) {
        s = fn_80131234(base + 0x5C);
    }
    fn_8001BE94(rec48, fn_8000DA10(), 0x20507, arg0, arg1);
    if (fn_8001BCF0(rec48) != 0) {
        fn_80130980(str14, 0x14, 3, fn_8001BEE8(rec48));
    } else {
        copyStr_8025C204(str14, fn_80131234(base + 0x70), 0x14);
    }
    menu.entries[0].label = base + 0x88;
    menu.entries[0].type = 3;
    menu.entries[0].value = title;
    menu.entries[0].flags = 0;
    menu.entries[0].id = 0;
    menu.entries[1].label = base + 0x94;
    menu.entries[1].type = 3;
    menu.entries[1].value = str14;
    menu.entries[1].flags = 0;
    menu.entries[1].id = 0;
    menu.entries[2].label = base + 0xA0;
    menu.entries[2].type = 3;
    menu.entries[2].value = s;
    menu.entries[2].flags = 0;
    menu.entries[2].id = 0;
    menu.entries[3].label = base + 0xAC;
    menu.entries[3].type = 3;
    menu.entries[3].value = recs[0].name;
    menu.entries[3].flags = 0;
    menu.entries[3].id = 0;
    menu.entries[4].label = base + 0xB8;
    menu.entries[4].type = 3;
    menu.entries[4].value = recs[0].icon;
    menu.entries[4].flags = 0;
    menu.entries[4].id = 0;
    menu.entries[5].label = lbl_8055C3B8;
    menu.entries[5].type = 3;
    menu.entries[5].value = recs[0].time;
    menu.entries[5].flags = 0;
    menu.entries[5].id = 0;
    menu.entries[6].label = base + 0xC4;
    menu.entries[6].type = 5;
    menu.entries[6].value = &objs[0];
    menu.entries[6].flags = 0;
    menu.entries[6].id = 0;
    menu.entries[7].label = base + 0xD0;
    menu.entries[7].type = 3;
    menu.entries[7].value = recs[1].name;
    menu.entries[7].flags = 0;
    menu.entries[7].id = 0;
    menu.entries[8].label = base + 0xDC;
    menu.entries[8].type = 3;
    menu.entries[8].value = recs[1].icon;
    menu.entries[8].flags = 0;
    menu.entries[8].id = 0;
    menu.entries[9].label = lbl_8055C3C0;
    menu.entries[9].type = 3;
    menu.entries[9].value = recs[1].time;
    menu.entries[9].flags = 0;
    menu.entries[9].id = 0;
    menu.entries[10].label = base + 0xE8;
    menu.entries[10].type = 5;
    menu.entries[10].value = &objs[1];
    menu.entries[10].flags = 0;
    menu.entries[10].id = 0;
    menu.entries[11].label = base + 0xF4;
    menu.entries[11].type = 3;
    menu.entries[11].value = recs[2].name;
    menu.entries[11].flags = 0;
    menu.entries[11].id = 0;
    menu.entries[12].label = base + 0x100;
    menu.entries[12].type = 3;
    menu.entries[12].value = recs[2].icon;
    menu.entries[12].flags = 0;
    menu.entries[12].id = 0;
    menu.entries[13].label = lbl_8055C3C8;
    menu.entries[13].type = 3;
    menu.entries[13].value = recs[2].time;
    menu.entries[13].flags = 0;
    menu.entries[13].id = 0;
    menu.entries[14].label = base + 0x10C;
    menu.entries[14].type = 5;
    menu.entries[14].value = &objs[2];
    menu.entries[14].flags = 0;
    menu.entries[14].id = 0;
    menu.entries[15].label = base + 0x118;
    menu.entries[15].type = 3;
    menu.entries[15].value = recs[3].name;
    menu.entries[15].flags = 0;
    menu.entries[15].id = 0;
    menu.entries[16].label = base + 0x124;
    menu.entries[16].type = 3;
    menu.entries[16].value = recs[3].icon;
    menu.entries[16].flags = 0;
    menu.entries[16].id = 0;
    menu.entries[17].label = lbl_8055C3D0;
    menu.entries[17].type = 3;
    menu.entries[17].value = recs[3].time;
    menu.entries[17].flags = 0;
    menu.entries[17].id = 0;
    menu.entries[18].label = base + 0x130;
    menu.entries[18].type = 5;
    menu.entries[18].value = &objs[3];
    menu.entries[18].flags = 0;
    menu.entries[18].id = 0;
    menu.entries[19].label = base + 0x13C;
    menu.entries[19].type = 3;
    menu.entries[19].value = recs[4].name;
    menu.entries[19].flags = 0;
    menu.entries[19].id = 0;
    menu.entries[20].label = base + 0x148;
    menu.entries[20].type = 3;
    menu.entries[20].value = recs[4].icon;
    menu.entries[20].flags = 0;
    menu.entries[20].id = 0;
    menu.entries[21].label = lbl_8055C3D8;
    menu.entries[21].type = 3;
    menu.entries[21].value = recs[4].time;
    menu.entries[21].flags = 0;
    menu.entries[21].id = 0;
    menu.entries[22].label = base + 0x154;
    menu.entries[22].type = 5;
    menu.entries[22].value = &objs[4];
    menu.entries[22].flags = 0;
    menu.entries[22].id = 0;
    menu.entries[23].label = &lbl_8055B860;
    menu.entries[23].type = 6;
    menu.entries[23].value = 0;
    menu.entries[23].flags = -2;
    menu.entries[23].id = 0x1B;
    menu.footer = lbl_80498EB8;
    header = lbl_802FA664;
    header.v[1] = (int)menu.entries;
    win = fn_802168E4();
    if (win != 0) {
        fn_80214A9C(0x1F);
    }
    fn_802146BC(&header, -0x3E7, -0x3E7, 1);
    if (win != 0) {
        fn_80214AF0(0x1F);
    }
    heap2 = lbl_8055F2E8 - 1;
    lbl_8055F2E8 = heap2;
    if (heap2 == 0) {
        void *l = (void *)lbl_8055F2E4;
        if (l != 0) {
            int ci = 0;
            int co = 0;
            while (ci < *(int *)((char *)l + 4)) {
                char *e = *(char **)l + co;
                fn_802CAC54(*(int *)(e + 0x20));
                fn_802CAC54(*(int *)(e + 0x24));
                co += 0x38;
                ci++;
            }
            fn_80128670(*(void **)l);
            fn_80128668(l);
        }
        lbl_8055F2E4 = 0;
    }
    objs[4].vtable = lbl_803453B8; ((void (*)(void *))fn_80235380)(objs[4].f28);
    objs[3].vtable = lbl_803453B8; ((void (*)(void *))fn_80235380)(objs[3].f28);
    objs[2].vtable = lbl_803453B8; ((void (*)(void *))fn_80235380)(objs[2].f28);
    objs[1].vtable = lbl_803453B8; ((void (*)(void *))fn_80235380)(objs[1].f28);
    objs[0].vtable = lbl_803453B8; ((void (*)(void *))fn_80235380)(objs[0].f28);
}

#pragma pop
