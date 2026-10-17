// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EA20;
extern int lbl_804874D4;
extern int lbl_804874B8;
extern char lbl_8055EA22;
extern char lbl_8055EA22;
extern float lbl_80562CAC;
extern float lbl_80562CC8;
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562D4;
void fn_801E1B30(void);
extern const char lbl_80339878[];
extern const char lbl_80339884[];
int *fn_801E1F44(void);
void *fn_80207848(const char *, int);
void fn_801E1874(void) {
    volatile int *p = (volatile int *)&lbl_804874D4;
    *p = 0;
    *((volatile char *)p + 0x18) = 0;
    *((volatile char *)p + 4) = 0;
    lbl_8055EA22 = 0;
}

void fn_801E1D20(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D2C(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D38(void) {
    int *base;
    if (*fn_801E1F44() == 1) {
        base = &lbl_804874B8;
        base[5] = (int)fn_80207848(lbl_80339878, 2);
        base[6] = (int)fn_80207848(lbl_80339884, 2);
    }
}

void fn_801E1D9C(void) {
    void *p;
    p = *(void **)((char *)&lbl_804874B8 + 0x18);
    if (p != 0) {
        ((void (*)(void *, int))(*(void ***)p)[2])(p, 1);
        *(void **)((char *)&lbl_804874B8 + 0x18) = 0;
    }
    p = *(void **)((char *)&lbl_804874B8 + 0x14);
    if (p != 0) {
        ((void (*)(void *, int))(*(void ***)p)[2])(p, 1);
        *(void **)((char *)&lbl_804874B8 + 0x14) = 0;
    }
}

void fn_801E1E30(void) {
    int v = lbl_8055EA22;
    float x = lbl_80562CAC;
    float z = lbl_80562CC8;
    *((float *)&lbl_804874B8 + 1) = x;
    *(int *)&lbl_804874B8 = (v | -v) >> 31 & 1;
    *((float *)&lbl_804874B8 + 2) = x;
    *((float *)&lbl_804874B8 + 3) = z;
}

extern int fn_801E1894(void);
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562CD4;
extern void fn_801E1B30(void);
void fn_801E1E64(void) {
    void *p = *(void **)((char *)&lbl_804874B8 + 0x14);
    if (p != 0) {
        *(unsigned char *)((char *)p + 0x4A) = 0;
        *(unsigned char *)((char *)p + 0x4B) = 1;
        *(unsigned char *)((char *)p + 0x49) = 1;
    }
    if (lbl_804874B8 != 0)
        fn_801E1B30();
}

extern char lbl_8055EA21;
void fn_801E1F78(void) {
    lbl_8055EA21 = 1;
}
typedef struct { int pad0; float x; float y; float z; char pad10[4]; void *p14; void *p18; } Obj;
