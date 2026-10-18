#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];

extern void fn_80141558(void *, int, const char *);
extern char fn_8000FDF0[];
extern void fn_80128658(void *);
extern void fn_80128668(void *);
extern void fn_801777D0(void *);
extern void __dt__Q210JASDrumSet5TPercFv(void *, int);
extern char lbl_80330ED8[];
void *fn_801717B4(void *arg0, int arg1) {
    int i;
    int offset;
    int zero;
    int *check;
    unsigned char *item;
    if (arg0 == 0)
        return arg0;
    *(void **)arg0 = lbl_80330ED8;
    *(void **)((char *)arg0 + 4) = lbl_80330ED8 + 0x10;
    if (arg0 != 0) {
        fn_801777D0((char *)arg0 + 4);
        i = 0;
        offset = 0;
        zero = 0;
        do {
            item = *(unsigned char **)((char *)arg0 + 8) + offset;
            fn_80128658(*(void **)(item + 0x18));
            *(void **)(item + 0x18) = (void *)zero;
            offset += 0x28;
            i++;
        } while (i < *(int *)((char *)arg0 + 0xC));
        __dt__Q210JASDrumSet5TPercFv((char *)arg0 + 0xA14, -1);
        check = (int *)((char *)arg0 + 8);
        if (check != 0) {
            *check = zero;
            *(int *)((char *)arg0 + 0xC) = zero;
            *(int *)((char *)arg0 + 0x10) = zero;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_8017188C(void *arg0) {
    int i;
    int offset;
    unsigned char *base;
    i = 0;
    offset = 0;
    base = *(unsigned char **)((char *)arg0 + 8);
    while (i < *(int *)((char *)arg0 + 12)) {
        unsigned char *p = base + offset;
        if (p[0x25] && !p[0x24] && *(int *)*(void **)(p + 0x18) > 1)
            fn_80141558((char *)arg0 + 0xa14, 2, fn_8000FDF0 + 0x110);
        offset += 0x28;
        i++;
    }
}

void fn_80171930(void) {
}

void fn_80171A4C(void *arg0) {
    int offset;
    int count;
    offset = 0;
    count = 0;
    do {
        count++;
        *(unsigned char *)(*(char **)((char *)arg0 + 8) + offset + 0x24) = 0;
        offset += 0x28;
    } while (count < *(int *)((char *)arg0 + 12));
}

void fn_80171CE0(void) {

}

