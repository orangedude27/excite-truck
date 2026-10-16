#include "types.h"
extern int lbl_8055D008;
void* fn_802C5390(void);
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);

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

extern void fn_802C8B70(int);
extern void fn_802C8D74(void);
extern void fn_802D0610(int);
extern void fn_802D6B08(int);
extern void fn_802DAA18(void);
extern void fn_802DB2BC(unsigned char);
extern int lbl_804C139C[];
void fn_802C5690(void *arg0) {
    void *node;
    int value;
    if (*(int *)((char *)arg0 + 8) != 0) {
        fn_802C8B70(*(int *)arg0);
        node = *(void **)((char *)arg0 + 8);
        while (node != 0) {
            fn_802D0610(*(int *)((char *)node + 8));
            value = *(int *)((char *)node + 12);
            if ((unsigned int)(value + 0x10000) != 0xFFFFFFFF) {
                fn_802DAA18();
            }
            fn_802DB2BC(*(unsigned char *)((char *)node + 4));
            fn_802D6B08(*(int *)node);
            node = *(void **)((char *)node + 16);
        }
        fn_802C8D74();
        *(int *)((char *)arg0 + 8) = 0;
    }
}

extern void fn_802C54D4(void);
extern int lbl_804C1390[];
void fn_802C5720(int arg0) {
    int count;
    void **items;
    int i;
    if (arg0 > 0) {
        void *entry = fn_802C54B4(arg0);
        items = *(void ***)entry;
        count = *(int *)((char *)entry + 4);
    } else {
        count = lbl_804C1390[0];
        items = *(void ***)(lbl_804C1390 + 2);
    }
    fn_802C54D4();
    for (i = 0; i < count; i++) {
        fn_802C5690(items[i]);
    }
    fn_802DB2BC(1);
}

void fn_802C57B0(void) { }

u16 fn_802C5A50(int arg0, int arg1) {
    return (u16)((arg0 << 8) | arg1);
}

void fn_802C6074(s32 *arg0) {
    *arg0 = 0;
}

void fn_802C6A84(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6A9C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AB4(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6ACC(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AE4(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AFC(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6B14(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6B2C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6C30(void) {}

void fn_802C6C34(void) { fn_802C53A8(); }

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

void fn_802C744C(int arg0, void *arg1) { fn_802C70AC(arg0, arg1, -1, -1); }

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
extern int lbl_8055D008;
extern void fn_8012C4E4(void *, int);

