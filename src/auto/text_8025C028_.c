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
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
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
    fn_802354A0(*(int*)((char*)p + 0x28), *(unsigned char*)((char*)p + 0x2C), -1,
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
#pragma scheduling on
#pragma push
#pragma use_lmw_stmw off
void fn_8025C054(void) {
    Menu menu;
    int running;

    menu.entries[0].type = 8;
    menu.entries[0].label = &lbl_8055BAC0;
    menu.entries[0].value = (void *)fn_8025C04C;
    menu.entries[0].flags = 0;
    menu.entries[0].id = 0;

    menu.entries[1].type = 8;
    menu.entries[1].label = &lbl_8055BABC;
    menu.entries[1].value = (void *)fn_8025C028;
    menu.entries[1].flags = 1;
    menu.entries[1].id = 0;

    menu.entries[2].type = 0;
    menu.entries[2].label = lbl_80345264;
    menu.entries[2].value = 0;
    menu.entries[2].flags = 0;
    menu.entries[2].id = 0;

    menu.entries[3].type = 0;
    menu.entries[3].label = &lbl_8055C394;
    menu.entries[3].value = 0;
    menu.entries[3].flags = 1;
    menu.entries[3].id = 0;

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
    menu.header.v[1] = (int)menu.entries;

    running = 1;
    while (running) {
        switch (fn_802146BC(menu.header.v, -999, -999, 1)) {
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

typedef int M2C_UNK;
typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
#define NULL 0
#define M2C_FIELD(p, T, off) (*(T)((char*)(p) + (off)))
typedef void **(*M2C_F1)(void *, int);
typedef int (*M2C_F2)(void *);
typedef unsigned char *(*M2C_F3)(void *, int *, int, int);
typedef float (*M2C_F4)(void *, int *);
typedef int (*M2C_F5)(void *, int *);
typedef int (*M2C_F6)(void *, int *);
typedef int (*M2C_F7)(void *, void *);

extern char lbl_8055C114[], lbl_8055C10C[], lbl_80344760[];
extern void **fn_80131808(void *);
extern void *fn_8012850C(int, void *);
void fn_8025C204(int arg0, int arg1) {
    void *obj;
    void *list;
    if (lbl_8055F2E8 == 0) {
        obj = fn_801284F8(8, (void *)lbl_8055C114);
        if (obj != 0) {
            list = fn_80131808((void *)lbl_80344760);
            *(int *)((char *)obj + 4) = 0;
            *(void **)obj = fn_8012850C(0xAF0, (void *)lbl_8055C10C);
            (void)list;
            lbl_8055F2E4 = (int)obj;
            lbl_8055F2E8 = lbl_8055F2E8 + 1;
        }
    }
    (void)arg0;
    (void)arg1;
}

#pragma pop
