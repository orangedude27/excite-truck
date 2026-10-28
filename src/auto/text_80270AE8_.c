// Code of main that had no source file yet: decomp.wtf gave it this one.

#pragma cplusplus on
struct Parser {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int has(const char *);
    virtual int enumerate(int, char **, int *);
    virtual void slot5();
    virtual void slot6();
    virtual int getCount(const char *);
    virtual int getOption(const char *, int);
    virtual float getFloat(const char *);
};
#pragma cplusplus reset

// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80271624(void);
extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
void *fn_801E87A8(void);
extern void fn_80136468(void **, void *, float);
void fn_8027156C();
#pragma push
#pragma small_data off
extern unsigned char lbl_8049A258[];
#pragma pop
#pragma push
#pragma small_data off
extern char lbl_8049F9D8[];
#pragma pop
extern int lbl_8055F554;
extern int lbl_8055F54C;
extern signed char lbl_8055F558;
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

#pragma push
#pragma small_data off
void fn_80270B74(void) {
    int *p = (int *)lbl_8049F9D8;
    *p = 0;
    *(int *)((char *)p + 0x1C) = 0;
    *(int *)((char *)p + 0x38) = 0;
    *(int *)((char *)p + 0x54) = 0;
    *(int *)((char *)p + 0x70) = 0;
    *(int *)((char *)p + 0x8C) = 0;
    *(int *)((char *)p + 0xA8) = 0;
    *(int *)((char *)p + 0xC4) = 0;
    *(int *)((char *)p + 0xE0) = 0;
    *(int *)((char *)p + 0xFC) = 0;
    *(int *)((char *)p + 0x118) = 0;
    *(int *)((char *)p + 0x134) = 0;
    *(int *)((char *)p + 0x150) = 0;
    *(int *)((char *)p + 0x16C) = 0;
    *(int *)((char *)p + 0x188) = 0;
    *(int *)((char *)p + 0x1A4) = 0;
    *(int *)((char *)p + 0x1C0) = 0;
    *(int *)((char *)p + 0x1DC) = 0;
    *(int *)((char *)p + 0x1F8) = 0;
    *(int *)((char *)p + 0x214) = 0;
    *(int *)((char *)p + 0x230) = 0;
    *(int *)((char *)p + 0x24C) = 0;
    *(int *)((char *)p + 0x268) = 0;
    *(int *)((char *)p + 0x284) = 0;
    *(int *)((char *)p + 0x2A0) = 0;
    *(int *)((char *)p + 0x2BC) = 0;
    *(int *)((char *)p + 0x2D8) = 0;
    *(int *)((char *)p + 0x2F4) = 0;
    *(int *)((char *)p + 0x310) = 0;
    *(int *)((char *)p + 0x32C) = 0;
    *(int *)((char *)p + 0x348) = 0;
    lbl_8055F554 = 0;
    *(int *)((char *)p + 0x364) = 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
void fn_80270C04(void *arg0, unsigned int arg1) {
    extern char lbl_80346B00[];
    extern char lbl_8049EDC8[];
    extern char lbl_8049F9D8[];
    extern int lbl_8055F550;
    extern unsigned char lbl_8055F564;
    extern void fn_80272738(void *, void *);
    register int i = arg1;
    register char *name = lbl_80346B00;
    register char *record;
    register unsigned char flag;
    register char *table;

    fn_80270B74();
    if (lbl_8055F550 == 0)
        return;
    flag = (i >> 8) & 1;
    lbl_8055F564 = flag;
    DBPrintf_80270B00(name + 0x1E0);
    record = lbl_8049EDC8;
    table = lbl_8049F9D8;
    i = 0;
    while (i < lbl_8055F550) {
        DBPrintf_80270B00(name + 0x1F8, i);
        DBPrintf_80270B00(name + 0x208);
        *(char **)(table + lbl_8055F554 * 0x1C) = record;
        if (flag != 0)
            fn_80272738(table + lbl_8055F554 * 0x1C, arg0);
        record += 0x60;
        i++;
        lbl_8055F554++;
    }
    if (lbl_8055F554 == 0) {
        DBPrintf_80270B00(name + 0x224);
        *(int *)lbl_8049F9D8 = (int)lbl_8049EDC8;
        if (flag != 0)
            fn_80272738(lbl_8049F9D8, arg0);
        lbl_8055F554 = 1;
    }
}
#pragma pop
int fn_80270D1C(int arg0) {
    switch (arg0) {
    case 0: return 1;
    case 1: return 2;
    default: return 0;
    }
}

#pragma scheduling off
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
#pragma scheduling on
extern float lbl_80563F40;
#pragma scheduling invalid_target
void fn_80270DB0(void *arg0, void *arg1, float farg0) {
    register unsigned char flag;
    register float *left, *right, *left2, *left3, *left4, *right2, *right3;
    float f2, f3, f0;
    flag = *(unsigned char *)((unsigned char *)arg0 + 4);
    if (flag) left = (float *)(*(char **)arg0 + 0x10); else left = (float *)(*(char **)arg0 + 8);
    f2 = *left;
    if (*(unsigned char *)((unsigned char *)arg1 + 4)) right = (float *)(*(char **)arg1 + 0xC); else right = (float *)(*(char **)arg1 + 4);
    f3 = *right;
    if (flag) left2 = (float *)(*(char **)arg0 + 0xC); else left2 = (float *)(*(char **)arg0 + 4);
    if (f2 < *left2) f2 += farg0;
    if (flag) left3 = (float *)(*(char **)arg0 + 0xC); else left3 = (float *)(*(char **)arg0 + 4);
    if (f3 < *left3) f3 += farg0;
    if (flag) left4 = (float *)(*(char **)arg0 + 0xC); else left4 = (float *)(*(char **)arg0 + 4);
    f0 = lbl_80563F40 * (f2 + f3);
    if (*left4 > f0) f3 = *left4; else f3 = f0;
    if (f3 >= farg0) f3 -= farg0;
    if (flag) right2 = (float *)(*(char **)arg0 + 0x10); else right2 = (float *)(*(char **)arg0 + 8);
    *right2 = f3;
    if (*(unsigned char *)((unsigned char *)arg1 + 4)) right3 = (float *)(*(char **)arg1 + 0xC); else right3 = (float *)(*(char **)arg1 + 4);
    *right3 = f3;
}
#pragma scheduling on
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
void fn_802715C4(void *arg0, void *arg1)
{
  f32 a = *((f32 *) (((u8 *) arg1) + 0x14));
  f32 b = lbl_80563F4C;
  f32 c = *((f32 *) (((u8 *) arg1) + 0x10));
  f32 d = *((f32 *) (((u8 *) arg1) + 0xC));
  f32 x = b * a;
  f32 y = b * c;
  f32 z;
  *((f32 *) (((u8 *) arg0) + 8)) = x;
  z = d;
  z = b * z;
  *((f32 *) (((u8 *) arg0) + 0)) = z;
  *((f32 *) (((u8 *) arg0) + 4)) = y;
}

extern f32 lbl_8055F540;
extern f32 lbl_8055F544;
f32 fn_802715F0(void *arg0) {
    f32 min = lbl_8055F544;
    f32 value = *(f32 *)((u8 *)arg0 + 0x18) * lbl_80563F4C;
    min = (min < value) ? value : min;
    if (min > lbl_8055F540) {
        return min;
    }
    return lbl_8055F540;
}

int fn_80271FAC(const char *arg0) {
    char **entry = lbl_80346B54;
    int i = 0;
    do {
        if ((i != 11) && (stricmp(arg0, *entry) == 0)) return i;
        ++i;
        ++entry;
    } while (i < 18);
    return 11;
}

#pragma cplusplus on
extern "C" void fn_80272354(void *);
extern "C" unsigned char fn_80008050(int);
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void DBPrintf_80270B00(const char *, ...);
extern "C" char lbl_80346B00[];
extern "C" char lbl_8055C5A4[];
extern "C" char lbl_8055C5AC[];
extern "C" char lbl_8055C5B4[];
extern "C" int fn_80272028(void *arg0, Parser *arg1, int arg_sp0) {
    struct Stack {
        char *path;
        int hash;
        char buffer[0x30];
    } stack;
    register char *name = lbl_80346B00;
    register Parser *parser = arg1;
    register void *output = arg0;
    int index;
    int count;
    unsigned char bit;

    #pragma unused(arg_sp0)
    fn_80272354(arg0);

    if (parser->has(name + 0x424) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x424);
        return 0;
    }
    *(float *)output = parser->getFloat(name + 0x424);

    if (parser->has(name + 0x464) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x464);
        return 0;
    }
    *(float *)((char *)output + 4) = parser->getFloat(name + 0x464);

    if (parser->has(name + 0x470) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x470);
        return 0;
    }
    *(float *)((char *)output + 8) = parser->getFloat(name + 0x470);

    if (parser->has(lbl_8055C5A4) == 0) {
        DBPrintf_80270B00(name + 0x430, lbl_8055C5A4);
        return 0;
    }
    *(float *)((char *)output + 0xC) = parser->getFloat(lbl_8055C5A4);
    *(int *)((char *)output + 0x5C) = parser->getOption(lbl_8055C5AC, 2);

    index = 0;
    for (;;) {
        if (parser->enumerate(index, &stack.path, &stack.hash) == 0) {
            break;
        }
        if (strncmp(stack.path, lbl_8055C5B4, 5) == 0 &&
            stack.path[5] != '_') {
            bit = fn_80008050(stack.hash);
            if (bit < 0x20) {
                *(int *)((char *)output + 0x10) |= 1 << bit;
            } else {
                *(int *)((char *)output + 0x14) |= 1 << (bit - 0x20);
            }
        }
        index++;
    }

    if (parser->has(name + 0x47C) == 0) {
        DBPrintf_80270B00(name + 0x430, name + 0x47C);
        return 0;
    }
    count = parser->getCount(name + 0x47C);
    *(int *)((char *)output + 0x58) = count;

    for (index = 0; index < count; index++) {
        sprintf(stack.buffer, name + 0x48C, index);
        if (parser->has(stack.buffer) == 0) {
            DBPrintf_80270B00(name + 0x430, stack.buffer);
            return 0;
        }
        *(int *)((char *)output + 0x18 + index * 4) =
            parser->getCount(stack.buffer);
    }
    return 1;
}
#pragma cplusplus reset

extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
void fn_80272354(void *arg0) {
    float other;
    float value;
    volatile float *out = (volatile float *)arg0;
    value = *(volatile float *)&lbl_80563F48;
    other = *(volatile float *)&lbl_80563F88;
    out[0] = value;
    out[1] = value;
    out[2] = value;
    out[3] = other;
    memset((char *)arg0 + 0x10, 0, 8);
    *(int *)((char *)arg0 + 0x58) = 0;
    *(int *)((char *)arg0 + 0x5C) = 2;
}

#pragma scheduling invalid_target
void fn_802723B4(void *arg0, void *arg1) {
    void *slot;
    void *object;
    float factor;
    float base;
    ((void (*)(void **, void *))fn_80136468)(&slot, arg0);
    object = slot;
    factor = *(float *)((char *)&slot + 4);
    base = *(float *)object;
    *(float *)arg1 = base + (*(float *)*(void **)((char *)object + 0x14) - base) * factor;
    base = *(float *)((char *)object + 4);
    *(float *)((char *)arg1 + 4) = base + (*(float *)((char *)*(void **)((char *)object + 0x14) + 4) - base) * factor;
}
#pragma scheduling on
extern float lbl_8055F560, lbl_80563F40, lbl_80563F48;
extern void fn_80136468(void **, void *, float);
float fn_80272428(void *arg0, void *arg1, float a, float b, float radius) {
    float period = *(float *)((char *)*(void **)((char *)arg0 + 0x2C) + 8);
    void *p;
    float t, x, y, dx, dy, d0, d1, mid;
    if (a > b) {
        float d = b - (a - period);
        if (d * d < lbl_8055F560) return a;
    } else {
        float d = b - a;
        if (d * d < lbl_8055F560) return a;
    }
    fn_80136468(&p, arg0, a);
    t = *(float *)((char *)&p + 4);
    {
        void *v = *(void **)((char *)p + 0x14);
        x = *(float *)p + t * (*(float *)v - *(float *)p);
        y = *(float *)((char *)p + 4) + t * (*(float *)((char *)v + 4) - *(float *)((char *)p + 4));
    }
    dx=x-*(float *)arg1; dy=y-*(float *)((char *)arg1+4);
    d0=(float)__fabsf(radius-(dx*dx+dy*dy));
    if (d0 < lbl_8055F560) return a;
    fn_80136468(&p, arg0, b);
    t = *(float *)((char *)&p + 4);
    {
        void *v = *(void **)((char *)p + 0x14);
        x = *(float *)p + t * (*(float *)v - *(float *)p);
        y = *(float *)((char *)p + 4) + t * (*(float *)((char *)v + 4) - *(float *)((char *)p + 4));
    }
    dx=x-*(float *)arg1; dy=y-*(float *)((char *)arg1+4);
    d1=(float)__fabsf(radius-(dx*dx+dy*dy));
    if (d1 < lbl_8055F560) return b;
    if (a > b) {
        mid=(b+(a-period))*lbl_80563F40;
        if (mid < lbl_80563F48) mid+=period;
    } else mid=(a+b)*lbl_80563F40;
    if (d0 < d1) return fn_80272428(arg0,arg1,a,radius,0);
    return fn_80272428(arg0,arg1,mid,b,radius);
}

extern char lbl_8034705C[];
extern void fn_802723B4(void *, void *);
void fn_8027264C(int arg0, void *arg1, float farg0) {
    float value;
    fn_802723B4(arg1, &value);
    DBPrintf_80270B00(lbl_8034705C, arg0, farg0, value, *(float *)((char *)&value + 4));
}

#pragma dont_inline on
s32 fn_802726AC(f32 farg0, f32 farg1, f32 farg2) {
    if (farg1 < farg2) {
        return (farg1 < farg0) && (farg0 < farg2);
    }
    return (farg1 > farg0) && (farg0 > farg2);
}
#pragma dont_inline reset

extern int fn_802726AC(float, float, float);
int fn_802726EC(float farg0, float farg1, float farg2) {
    int result = 0;
    if (farg0 == farg1 || farg0 == farg2 || fn_802726AC(farg0, farg1, farg2) != 0) {
        result = 1;
    }
    return result;
}

#pragma dont_inline on
int fn_80272C24(float farg0, float farg1, float farg2, float farg3) {
    int result;
    if (farg1 == farg2) return 1;
    if (farg1 > farg2) {
        if (farg1 > farg0) farg1 -= farg3;
        else farg2 += farg3;
    }
    result = 0;
    if ((farg0 >= farg1) && (farg0 <= farg2)) result = 1;
    return result;
}
#pragma dont_inline reset

extern unsigned char lbl_8055F564;
extern float lbl_8055F568;
extern float lbl_80563F50;
extern float PSQUATMultiply(void *, void *);
extern int fn_80272C24(float, float, float, float);
#pragma cplusplus on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" int fn_80272C74(void *arg0, void *arg1, float *arg2, int arg3) {
    struct Manager {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *getCamera() = 0;
    };
    register float initial = lbl_80563F48;
    float height;
    int result;

    *arg2 = initial;
    if (*(int *)((char *)*(void **)arg0 + 0x58) == 0) return 0;
    if (arg3 != -1 && arg3 != *(int *)((char *)*(void **)arg0 + 0x5C)) return 0;
    result = 1;
    if (lbl_8055F564 != 0) {
        void *manager = *(void **)((char *)arg1 + 0x270);
        void *camera = ((Manager *)manager)->getCamera();
        camera = *(void **)((char *)camera + 0x2C);
        height = *(float *)((char *)camera + 8);
        if (fn_80272C24(lbl_8055F568, *(float *)((char *)arg0 + 4), *(float *)((char *)arg0 + 8), height) != 0 ||
            (*(unsigned char *)((char *)arg0 + 0x14) != 0 &&
             fn_80272C24(lbl_8055F568, *(float *)((char *)arg0 + 0xC), *(float *)((char *)arg0 + 0x10), height) != 0)) {
            *arg2 = lbl_80563F50;
            return 1;
        }
        result = 0;
    }
    {
        float value = PSQUATMultiply((char *)arg1 + 0x60, *(void **)arg0) -
                      *(float *)((char *)*(void **)arg0 + 0xC);
        if (value <= lbl_80563F48) *arg2 = lbl_80563F50;
        else *arg2 = lbl_80563F50 / (lbl_80563F50 + value);
    }
    return result;
}
#pragma pop
#pragma cplusplus reset

void fn_80273354(void) {
    int *ptr = (int *)lbl_8049A258;
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
#pragma dont_inline on
void fn_802733C8(void) {
    fn_80271578();
    lbl_8055F54C = 0x12;
}
#pragma dont_inline reset
void fn_802733F0(void) {
}

void fn_80273490(void) {
    fn_80271624();
}

#pragma dont_inline on
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
#pragma dont_inline reset

#pragma push
#pragma small_data off
#pragma dont_inline on
int fn_802734F0(int arg0) {
    extern unsigned char lbl_8055F480;
    extern unsigned char lbl_80346BA0[];
    int status = fn_80273494(arg0);
    int flags = 0;
    unsigned char *entry;
    unsigned char *state;

    if (lbl_8055F480 != 0) {
        flags |= 8;
    } else if (status != 6 && status != 0) {
        entry = lbl_8049A258 + status * 0x14;
        state = lbl_80346BA0 + (*(int *)(entry + 0xC) + *(int *)(entry + 4)) * 0x28;
        if (state[0x24] == 0)
            flags |= 1;
        else if (*(int *)state == 2)
            flags |= 2;
        else if (*(int *)state == 0)
            flags |= 8;
        if (state[0x25] == 0)
            flags |= 4;
    } else {
        if (arg0 == 1) goto done;
        if (arg0 == 1) goto fallback;
        if (arg0 >= 1) goto check3;
        if (0 <= arg0) goto flag8;
        goto fallback;
check3:
        if (arg0 >= 3) goto fallback;
        flags |= 6;
        goto done;
flag8:
        flags |= 8;
        goto done;
fallback:
        flags |= 5;
    }
done:
    return flags;
}
#pragma dont_inline reset
#pragma pop
void fn_802735F4(int arg0, signed char arg1) {
    if (arg0 == 0) {
        lbl_8055F558 = arg1;
    }
}

#pragma push
#pragma small_data off
#pragma pop
#pragma push
#pragma small_data off
void fn_80273604(void *arg0, s32 arg1) {
    extern float PSVECMag(float *);
    extern double sin(float), cos(float);
    extern void fn_80015B20(void *, float *, void *);
    extern void fn_801BFD34(void *, float *, void *);
    extern void fn_802704D0();
    extern void fn_802704D4(s32, void *);
    extern s32 fn_80273494(s32);
    extern void fn_80273BD0(void);
    extern void fn_80274268(void);
    extern void fn_802E30C8(const char *, ...);
    extern unsigned char lbl_8049A258[];
    extern u8 lbl_80346BA0[];
    extern char lbl_80347310[];
    extern float lbl_80563F48, lbl_80563F4C, lbl_80563F50, lbl_80563F9C;
    u8 *table = (u8 *)&lbl_8049A258 + arg1 * 0x14;
    s32 start = *(s32 *)(table + 4);
    s32 count = *(s32 *)(table + 0xC);
    u8 *state = lbl_80346BA0 + (start + count) * 0x28;
    s32 kind = *(s32 *)(lbl_80346BA0 + (start + count) * 0x28);
    switch (kind) {
    case 0x22: {
        struct Scratch { float vec[3]; float pad; float matrix[9]; float pos[3]; } scratch;
        float scale = lbl_80563F4C;
        float mag, nx, ny, nz, sine, cosine, oneMinusCos, t0, t1, t2, t3, t4, t5;
        *(s32 *)((u8 *)arg0 + 88) = *(s32 *)((u8 *)arg0 + 192); *(s32 *)((u8 *)arg0 + 92) = *(s32 *)((u8 *)arg0 + 196); *(s32 *)((u8 *)arg0 + 96) = *(s32 *)((u8 *)arg0 + 200); *(s32 *)((u8 *)arg0 + 100) = *(s32 *)((u8 *)arg0 + 204);
        *(s32 *)((u8 *)arg0 + 104) = *(s32 *)((u8 *)arg0 + 208); *(s32 *)((u8 *)arg0 + 108) = *(s32 *)((u8 *)arg0 + 212); *(s32 *)((u8 *)arg0 + 112) = *(s32 *)((u8 *)arg0 + 216); *(s32 *)((u8 *)arg0 + 116) = *(s32 *)((u8 *)arg0 + 220);
        *(s32 *)((u8 *)arg0 + 120) = *(s32 *)((u8 *)arg0 + 224); *(s32 *)((u8 *)arg0 + 124) = *(s32 *)((u8 *)arg0 + 228); *(s32 *)((u8 *)arg0 + 128) = *(s32 *)((u8 *)arg0 + 232); *(s32 *)((u8 *)arg0 + 132) = *(s32 *)((u8 *)arg0 + 236);
        scratch.pos[0] = *(float *)(state + 8);
        scratch.pos[1] = *(float *)(state + 0xC);
        scratch.pos[2] = *(float *)(state + 0x10);
        scratch.vec[0] = *(float *)(state + 0x14) * scale;
        scratch.vec[1] = *(float *)(state + 0x18) * scale;
        scratch.vec[2] = *(float *)(state + 0x1C) * scale;
        nz = PSVECMag(scratch.vec);
        if (nz > lbl_80563F9C) {
            t0 = lbl_80563F50 / nz;
            nx = t0 * scratch.vec[0]; ny = t0 * scratch.vec[1]; mag = t0 * scratch.vec[2];
            sine = (float)sin(nz);
            cosine = (float)cos(nz);
            oneMinusCos = lbl_80563F50 - cosine;
            t1 = sine * mag;
            t2 = oneMinusCos * nx;
            t3 = ny * t2;
            scratch.matrix[0] = cosine + (oneMinusCos * (nx * nx));
            t4 = mag * t2;
            t5 = sine * ny;
            scratch.matrix[1] = t3 + t1;
            t0 = mag * (oneMinusCos * ny);
            t2 = sine * nx;
            scratch.matrix[3] = t3 - t1;
            scratch.matrix[2] = t4 - t5;
            scratch.matrix[4] = cosine + (oneMinusCos * (ny * ny));
            scratch.matrix[5] = t0 + t2;
            scratch.matrix[6] = t4 + t5;
            scratch.matrix[7] = t0 - t2;
            scratch.matrix[8] = cosine + (oneMinusCos * (mag * mag));
        } else {
            scratch.matrix[1] = lbl_80563F48;
            scratch.matrix[0] = lbl_80563F50;
            scratch.matrix[2] = lbl_80563F48;
            scratch.matrix[3] = lbl_80563F48;
            scratch.matrix[4] = lbl_80563F50;
            scratch.matrix[5] = lbl_80563F48;
            scratch.matrix[6] = lbl_80563F48;
            scratch.matrix[7] = lbl_80563F48;
            scratch.matrix[8] = lbl_80563F50;
        }
        fn_801BFD34((u8 *)arg0 + 0x7C, scratch.pos, (u8 *)arg0 + 0xC0);
        fn_80015B20((u8 *)arg0 + 0x58, scratch.matrix, (u8 *)arg0 + 0xC0);
        *(float *)((u8 *)arg0 + 0xBC) = *(float *)(state + 0x20) * lbl_80563F4C;
        return;
    }
    case 0:
        fn_80273BD0();
        return;
    case 2:
        fn_80274268();
        return;
    case 4:
    case 5:
    case 7: {
        s32 other = fn_80273494(*(s32 *)((u8 *)arg0 + 4));
        if (other != 6 && other != 0 && other != arg1) {
            u8 *otherTable = (u8 *)&lbl_8049A258 + other * 0x14;
            s32 otherStart = *(s32 *)(otherTable + 4);
            s32 otherCount = *(s32 *)(otherTable + 0xC);
            u8 *otherState = lbl_80346BA0 + (otherStart + otherCount) * 0x28;
            fn_802704D0(*(s32 *)state, *(s32 *)otherState, arg0, otherStart);
        } else {
            s32 wrap = *(s32 *)(table + 8);
            s32 index = start + ((wrap + count - 1) % wrap);
            u8 *prevState = lbl_80346BA0 + index * 0x28;
            fn_802704D0(*(s32 *)state, *(s32 *)prevState, arg0, start, wrap);
        }
        return;
    }
    default:
        fn_802E30C8(lbl_80347310, kind);
        fn_802704D4(4, arg0);
        return;
    }
}
#pragma pop
extern int fn_80128668(void);
int fn_80273978(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma push
#pragma small_data off
extern char lbl_8049F9D8[];
#pragma pop
#pragma push
#pragma small_data off
extern unsigned char lbl_8049A258[];
#pragma pop
extern int lbl_8055F554;
extern f32 lbl_80563E78;
extern int stricmp(const char *, const char *);
extern char *lbl_80346B54[];
extern float lbl_80563F48;
extern float lbl_80563F88;
extern void *memset(void *, int, unsigned int);
typedef struct { void **v; } Obj;
typedef int (*Has)(Obj *, const char *);
typedef float (*Get)(Obj *, const char *);
typedef int (*Find)(Obj *, const char *, int);
typedef float (*Get3)(Obj *, const char *, float,float,float,float,float,float,float);
extern int lbl_8055F548;
extern int lbl_8055F550;
extern unsigned char lbl_8055F55B;

