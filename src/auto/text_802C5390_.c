#include "types.h"

extern int lbl_804C1338[];
extern unsigned char lbl_804C1348[];
char *fn_802CAE34(char *);
int stricmp(const char *, const char *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_802C53C4(void *a, void *b, int x, int y, signed char z) {
    int *count = lbl_804C1338;
    unsigned char *entry = 0;
    if (*count < count[1]) {
        entry = (unsigned char *)(unsigned long)count[2] + *count * 20;
        ++*count;
    }
    if (entry) {
        *(int *)(entry + 0) = *(int *)((char *)a + 12);
        *(signed char *)(entry + 4) = z;
        *(int *)(entry + 8) = x;
        *(int *)(entry + 12) = (*(unsigned int *)((char *)a + 4) & 1) ? y : -1;
        *(void **)(entry + 16) = *(void **)((char *)b + 8);
        *(void **)((char *)b + 8) = entry;
    }
}

int fn_802C544C(void **a, void **b) {
    void *right = *b;
    void *left = *a;
    short x = *(short *)((char *)right + 6);
    short y = *(short *)((char *)left + 6);
    if (y != x) return y - x;
    return stricmp(fn_802CAE34(*(char **)left), fn_802CAE34(*(char **)right));
}

void *fn_802C54B4(int i) { return (void *)(lbl_804C1348 + (i - 1) * 8); }

unsigned char fn_802C54CC(unsigned int arg0) { return (unsigned char)(arg0 >> 8); }

void fn_802C6074(s32 *arg0) {
    *arg0 = 0;
}

extern int fn_802D6C48;
void fn_802C5DF0(int*);
int fn_802C90E0(void);
int fn_802E30C8(const char*, int);
int fn_802C6B44(int);
void fn_802C6DC4(int, int, int, int);
extern const char lbl_8034B3DC[];
void fn_802C6C38(void);
void* fn_802C5390(void);
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);
void fn_802C7040(int arg0) {
    float spC;
    unsigned char sp8;
    void* temp;
    if (arg0 != -1) {
        temp = *(void**)((char*)fn_802C5390() + 4);
        if (fn_802C94A0((char*)temp + 0x20, &sp8, &spC, *(float*)((char*)temp + 0x1C))) {
            fn_802C57B4(arg0, 0, -1, sp8, spC);
        }
    }
}

void fn_802C7734(void* alarm) {
    fn_802D0610(fn_802D0514(alarm));
}

void fn_802C7758(void);
void fn_802C7758(void) {
    fn_802D0610(0);
}

void fn_802C7A10(void* alarm) {
    fn_8012C58C(fn_802C53A8(alarm));
}

extern s8 lbl_8055FC20;
extern void fn_802C543C(void);
void fn_802C7A44(void) {
    lbl_8055FC20 = 1;
    fn_802C543C();
}

