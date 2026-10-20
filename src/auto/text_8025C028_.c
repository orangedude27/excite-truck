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

extern void* lbl_8055C390;
extern void fn_80214CB4(void*);
extern void* fn_80214D04(void);
extern char lbl_803453B8[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);

void fn_8025C028(void) {
    lbl_8055C390 = fn_80214D04();
}

void fn_8025C04C(void) {
    fn_80214CB4(lbl_8055C390);
}

void* __dt__Q28PSSystem7SeqHeapFv_8025CC14(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_803453B8;
        fn_80235380(*(void**)((char*)arg0 + 0x28), lbl_803453B8);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern void fn_80230C30(float*, float*, int, int);
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
extern float lbl_80563B40, lbl_80563B44, lbl_80563B48;
extern double lbl_80563B50;
#pragma scheduling off
void fn_8025CC78(void* arg0, int arg1) {
    float spC, sp8, f25, f24, f26, f27, f28, f29;
    unsigned int color;
    char* item;
    if (*(unsigned char*)((char*)arg0 + 0x20) != 0) {
        fn_80230C30(&spC, &sp8, *(int*)((char*)arg0 + 4), *(int*)((char*)arg0 + 8));
        f25 = (float)*(int*)((char*)arg0 + 0xC);
        f24 = (float)*(int*)((char*)arg0 + 0x10);
        fn_802354A0(*(int*)((char*)arg0 + 0x28), *(unsigned char*)((char*)arg0 + 0x2C), -1, spC - lbl_80563B40, lbl_80563B40 + sp8, lbl_80563B44, lbl_80563B48 + f25, lbl_80563B48 + f24);
        item = (char*)**(void***)((char*)arg0 + 0x18) + *(int*)((char*)arg0 + 0x1C) * 0x38;
        f26 = *(float*)(item + 0x28); f27 = *(float*)(item + 0x2C); f28 = *(float*)(item + 0x30); f29 = *(float*)(item + 0x34);
        color = *(unsigned int*)((char*)arg0 + 0x24);
        fn_80231220(*(int*)(item + 0x20), -1, spC, sp8, f25, f24, f26, f27, f28, f29);
        fn_80231220(*(int*)(item + 0x24), (color & 0xFFFFFF) | 0xFF000000, spC, sp8, f25, f24, f26, f27, f28, f29);
    }
}
#pragma scheduling on
