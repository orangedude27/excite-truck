#include "types.h"

extern int lbl_804C1338[];
extern unsigned char lbl_804C1348[];
char *fn_802CAE34(char *);
int stricmp(const char *, const char *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_802C544C(void **a, void **b) {
    short x = *(short *)((char *)*b + 6);
    short y = *(short *)((char *)*a + 6);
    if (y != x) return y - x;
    return stricmp(fn_802CAE34(*(char **)*a), fn_802CAE34(*(char **)*b));
}

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

