// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
void *fn_801E87A8(void);
extern int fn_802726AC(void);
void fn_8027156C();
#pragma push
#pragma small_data off
extern int lbl_8049A258;
#pragma pop
#pragma push
#pragma small_data off
extern int lbl_8049F9D8;
#pragma pop
extern int lbl_8055F554;
extern int lbl_8055F54C;
extern float lbl_80563E78;
void fn_80270AE8(void *arg0) {
    float value = lbl_80563E78;
    ((float *)arg0)[0] = value;
    ((float *)arg0)[1] = value;
    ((float *)arg0)[3] = value;
    ((float *)arg0)[2] = value;
}

void DBPrintf_80270B00(const char *fmt, ...) {
#pragma unused(fmt)
}

#pragma dont_inline on
int fn_80270B50(void) {
    return *(int *)((char *)fn_801E87A8() + 4);
}
#pragma dont_inline reset

void fn_80270B74(void) {
    *(int *)((char *)&lbl_8049F9D8 + 0x00) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x1C) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x38) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x54) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x70) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x8C) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0xA8) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0xC4) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0xE0) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0xFC) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x118) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x134) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x150) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x16C) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x188) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x1A4) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x1C0) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x1DC) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x1F8) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x214) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x230) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x24C) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x268) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x284) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x2A0) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x2BC) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x2D8) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x2F4) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x310) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x32C) = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x348) = 0;
    lbl_8055F554 = 0;
    *(int *)((char *)&lbl_8049F9D8 + 0x364) = 0;
}

int fn_80270D1C(int arg0) {
    switch (arg0) {
    case 0: return 1;
    case 1: return 2;
    default: return 0;
    }
}

int fn_80270D4C(void *arg0, void *arg1) {
    float *right;
    float *left;
    if (*((unsigned char *)arg1 + 4) != 0) {
        right = (float *)(*(char **)arg1 + 0xC);
    } else {
        right = (float *)(*(char **)arg1 + 4);
    }
    if (*((unsigned char *)arg0 + 4) != 0) {
        left = (float *)(*(char **)arg0 + 0xC);
    } else {
        left = (float *)(*(char **)arg0 + 4);
    }
    return (int)(*left - *right);
}

extern char lbl_80346E90[];
void fn_802712F8(void *);
void fn_8027156C(void) {
    fn_802712F8(lbl_80346E90);
}

typedef signed int s32;
typedef unsigned char u8;
void *fn_80178C9C(void);
s32 fn_80270EC4(void *, s32);
void fn_80271578(void) {
    s32 temp_r31;
    void *temp_r30;
    void *temp_r3;
    temp_r3 = fn_80178C9C();
    temp_r31 = *(s32 *)((u8 *)temp_r3 + 0xC);
    temp_r30 = temp_r3;
    fn_80270EC4(temp_r30, fn_80270B50());
    *(s32 *)((u8 *)temp_r30 + 0xC) = temp_r31;
}

typedef float f32;
extern f32 lbl_80563F4C;
void fn_802715C4(void *arg0, void *arg1) {
    f32 x = *(f32 *)((u8 *)arg1 + 0x14);
    f32 scale = lbl_80563F4C;
    f32 y = *(f32 *)((u8 *)arg1 + 0x10);
    f32 z = *(f32 *)((u8 *)arg1 + 0xC);
    *(f32 *)((u8 *)arg0 + 8) = x * scale;
    *(f32 *)((u8 *)arg0 + 4) = y * scale;
    *(f32 *)((u8 *)arg0 + 0) = z * scale;
}

extern f32 lbl_8055F540;
extern f32 lbl_8055F544;
f32 fn_802715F0(void *arg0) {
    f32 value = lbl_80563F4C * *(f32 *)((u8 *)arg0 + 0x18);
    f32 min = lbl_8055F544;
    if (min < value) {
        min = value;
    }
    if (min > lbl_8055F540) {
        return min;
    }
    return lbl_8055F540;
}

int fn_80271FAC(const char *arg0) {
    char **entry;
    int i;
    entry = lbl_80346B54;
    i = 0;
loop:
    if (i != 11 && stricmp(arg0, *entry) == 0) {
        return i;
    }
    i++;
    if (i >= 18) {
        return 11;
    }
    entry++;
    goto loop;
}

extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
void fn_80272354(void *arg0) {
    float other = lbl_80563F88;
    float value = lbl_80563F48;
    *(float *)((char *)arg0 + 0x0) = value;
    *(float *)((char *)arg0 + 0x4) = value;
    *(float *)((char *)arg0 + 0x8) = value;
    *(float *)((char *)arg0 + 0xC) = other;
    memset((char *)arg0 + 0x10, 0, 8);
    *(int *)((char *)arg0 + 0x58) = 0;
    *(int *)((char *)arg0 + 0x5C) = 2;
}

extern int fn_802726AC(void);
int fn_802726EC(float farg0, float farg1, float farg2) {
    int result = 0;
    if (farg0 == farg1 || farg0 == farg2 || fn_802726AC() != 0) {
        result = 1;
    }
    return result;
}

int fn_80272C24(float farg0, float farg1, float farg2, float farg3) {
    if (farg1 == farg2) return 1;
    if (farg1 > farg2) {
        if (farg1 > farg0) farg1 -= farg3;
        else farg2 += farg3;
    }
    if (!(farg0 < farg1)) return 0;
    if (!(farg0 > farg2)) return 0;
    return 1;
}

void fn_80273354(void) {
    int *ptr = &lbl_8049A258;
    memset(ptr, 0, 0x64);
    *(int *)((char *)ptr + 0x1C) = 1;
    *(int *)((char *)ptr + 0x18) = 0;
    *(int *)((char *)ptr + 0x2C) = 1;
    *(int *)((char *)ptr + 0x30) = 1;
    *(int *)((char *)ptr + 0x40) = 2;
    *(int *)((char *)ptr + 0x44) = 3;
    *(int *)((char *)ptr + 0x54) = 5;
    *(int *)((char *)ptr + 0x58) = 3;
    ((void (*)(int, int, int, void *))fn_8027156C)(3, 2, 1, ptr);
}

extern int lbl_8055F54C;
void fn_802733C8(void) {
    fn_80271578();
    lbl_8055F54C = 0x12;
}

void fn_802733F0(void) {
}

int fn_80273494(int arg0) {
    switch (arg0) {
    case 11: return 0;
    case 12: return 1;
    case 13: return 2;
    case 14: return 3;
    case 15: return 4;
    default: return 6;
    }
}

extern int fn_80128668(void);
extern void fn_80271624(void);
extern signed char lbl_8055F558;
int fn_80273978(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern int lbl_8049F9D8;
extern int lbl_8049A258;
extern int lbl_8055F554;
extern f32 lbl_80563E78;
extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
