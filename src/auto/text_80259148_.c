// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_80344EA0[];
extern char lbl_80344FE0[];
extern char lbl_80345098[];
extern float lbl_80498EAC[3];
extern float lbl_8055F398;
extern float lbl_80563AEC;
extern float lbl_80563AF0;
__declspec(section ".sdata") extern double lbl_80563B00;
__declspec(section ".rodata") extern float lbl_80558DC4;
__declspec(section ".sdata") extern unsigned char lbl_8055C380[];
extern unsigned char lbl_8055F67C;

extern void *fn_80258354(void);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80345158;
extern float lbl_80563AE0;
extern float lbl_80563B14;
extern double fn_8002F234(double);
extern float PSVECDotProduct();
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80259148(void) {
    struct Row { int first; char rest[0xC]; };
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void apply(void *, void *, int);
    };
    register Row *base asm("r31") = (Row *)lbl_80344DE0;
    register void *first asm("r4") = &base[0].first;
    Obj *obj = (Obj *)fn_80258354();
    lbl_8055F394 = obj;
    obj->apply(first, &base[1].first, 0);
    ((Obj *)lbl_8055F394)->apply(&base[2].first, &base[3].first, 0);
    ((Obj *)lbl_8055F394)->apply(&base[4].first, &base[5].first, 1);
}
#pragma scheduling on
#pragma cplusplus reset

#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_802591D8(void) {
    class Obj {
    public:
        virtual void destroy(int);
    };
    if (lbl_8055F394 != 0) {
        ((Obj*)lbl_8055F394)->destroy(1);
    }
    lbl_8055F394 = 0;
}
#pragma cplusplus reset
#pragma pop
struct Loc_8025AA90 {
    float v8[3];
    float v14[3];
    float v20[3];
    float v2C[3];
    float v38[3];
    float v44[3];
    float v50[3];
    float rot[9];
    unsigned char info[0x60];
};

int fn_8025921C(void) { return 0; }

extern void *fn_801284F8(int, const char *);
extern int fn_8001EF9C(int, int, int, const void *, const void *);
extern int fn_802CAC28(void *, int, float);
extern int fn_802146BC(int *, int, int, int);
extern void fn_802368E0(void);
extern void fn_80216CA8(void);
extern int fn_8025921C(void);
extern void fn_80259740(int, float);
extern char lbl_803450F8[];
extern int lbl_80498E98[5];
extern int lbl_802FA63C[5];
extern char lbl_8055BAB8[];
extern char lbl_8055B860[];
extern char lbl_8055C260[];
extern char lbl_8055C264[];
extern char lbl_8055C26C[];
extern char lbl_8055C274[];
extern char lbl_8055C27C[];
extern char lbl_8055C284[];
extern char lbl_8055C28C[];
#pragma cplusplus on
#pragma dont_inline on
extern "C" int fn_80259224(void **arg0) {
    extern float lbl_80563AE4;
    extern unsigned char *fn_8001EFAC(int, int);
    extern int fn_801345D8(char *, int, const char *, int);
    extern int fn_8001EFA4(int, int);
    extern int fn_8001EF9C(int, int, int, const void *, const void *);
    extern void fn_80259740(int, float);
    extern char lbl_803450F8[];
    extern int lbl_80498E98[5];
    extern int lbl_802FA63C[5];
    extern char lbl_8055BAB8[];
    extern char lbl_8055B860[];
    extern char lbl_8055C260[];
    extern char lbl_8055C264[];
    extern char lbl_8055C26C[];
    extern char lbl_8055C274[];
    extern char lbl_8055C27C[];
    extern char lbl_8055C284[];
    extern char lbl_8055C28C[];
    class Dialog_80259224 {
    public:
        virtual void destroy(int);
    };
    unsigned int frame[0x9A];
    void *button;
    void *buttonA;
    void *buttonB;
    int size;
    if (0) size = 105;
    int result;
    int i;
    unsigned char *src;
    unsigned char *dst;
    unsigned char c;
    int count;
    int n;

    *(int *)(((char *)frame + 0x110 - 8)) = -1;
    *(char **)(((char *)frame + 0xC0 - 8)) = (char *)&lbl_80345158;
    *(float *)(((char *)frame + 0x144 - 8)) = lbl_80563AE0;
    *(float *)(((char *)frame + 0x148 - 8)) = lbl_80563AE4;
    *(float *)(((char *)frame + 0x14C - 8)) = lbl_80563AE4;
    *(float *)(((char *)frame + 0x150 - 8)) = lbl_80563AE4;
    *(float *)(((char *)frame + 0x154 - 8)) = lbl_80563AE0;
    *(float *)(((char *)frame + 0x158 - 8)) = lbl_80563AE4;
    *(float *)(((char *)frame + 0x15C - 8)) = lbl_80563AE4;
    *(float *)(((char *)frame + 0x160 - 8)) = lbl_80563AE4;
    *(float *)(((char *)frame + 0x164 - 8)) = lbl_80563AE0;
    *(unsigned char *)(((char *)frame + 0xC4 - 8)) = 0;
    *(unsigned char *)(((char *)frame + 0xF6 - 8)) = 0;
    *(void **)(((char *)frame + 0x168 - 8)) = (void *)fn_802CAC28((char *)lbl_80344DE0 + 0x108, 0, lbl_80563AE0);
    *(unsigned char *)(((char *)frame + 0x10A - 8)) = 0;
    *(int *)(((char *)frame + 0x10C - 8)) = 5;

    if (fn_8025921C() != 0) {
        buttonA = fn_801284F8(0x78, (char *)lbl_80344DE0 + 0x114);
        if (buttonA != 0) {
            *(int *)((char *)buttonA + 0x14) = 0;
            *(void **)buttonA = lbl_803450F8;
            *(void **)((char *)buttonA + 0x18) = ((char *)frame + 0xC0 - 8);
            *(int *)((char *)buttonA + 0x70) = *(int *)((char *)arg0 + 0x18);
            *(int *)((char *)buttonA + 0x1C) = 5;
            *(unsigned char *)((char *)buttonA + 0x20) = 0;
            *(int *)((char *)buttonA + 0x74) = 5;
        }
        button = buttonA;
    } else {
        buttonB = fn_801284F8(0x78, (char *)lbl_80344DE0 + 0x114);
        if (buttonB != 0) {
            size = *(int *)((char *)arg0 + 0xC8);
            *(int *)((char *)buttonB + 0x14) = 0;
            *(void **)buttonB = lbl_803450F8;
            *(void **)((char *)buttonB + 0x18) = ((char *)frame + 0xC0 - 8);
            *(int *)((char *)buttonB + 0x70) = *(int *)((char *)arg0 + 0x18);
            *(int *)((char *)buttonB + 0x1C) = size;
            *(unsigned char *)((char *)buttonB + 0x20) = 0;
            *(int *)((char *)buttonB + 0x74) = size;
        }
        button = buttonB;
    }

    size = *(int *)((char *)arg0 + 0xC8);
    src = fn_8001EFAC(*(int *)((char *)arg0 + 0x18), size);
    if (src != 0) {
        dst = (unsigned char *)(((char *)frame + 0xC4 - 8));
        count = 0x32;
        for (;;) {
            --count;
            if (count <= 0) {
                dst[-1] = 0;
                break;
            }
            c = *src++;
            *dst++ = c;
            if ((signed char)c == 0)
                break;
        }
    } else {
        *(unsigned char *)(((char *)frame + 0xC4 - 8)) = 0;
    }
    if (size > 0) {
        fn_801345D8((char *)(((char *)frame + 0xF6 - 8)), 0x14, (char *)lbl_80344DE0 + 0x128, size);
    } else {
        *(unsigned char *)(((char *)frame + 0xF6 - 8)) = 0;
    }
    *(unsigned char *)(((char *)frame + 0x10A - 8)) = 1;
    for (i = 1; i <= 5; ++i) {
        fn_801345D8(((char *)frame + 0x20 - 8) + (i - 1) * 5, 0x20, lbl_8055C260,
                    fn_8001EFA4(*(int *)((char *)arg0 + 0x18), i));
    }

    *(void **)(((char *)frame + 0x188 - 8)) = button;
    *(void **)(((char *)frame + 0x174 - 8)) = fn_80259740;
    *(int *)(((char *)frame + 0x170 - 8)) = 8;
    *(void **)(((char *)frame + 0x16C - 8)) = lbl_8055BAB8;
    *(int *)(((char *)frame + 0x178 - 8)) = 2;
    *(int *)(((char *)frame + 0x17C - 8)) = 0;
    *(int *)(((char *)frame + 0x184 - 8)) = 5;
    *(int *)(((char *)frame + 0x180 - 8)) = 0;
    *(int *)(((char *)frame + 0x18C - 8)) = 0;
    *(int *)(((char *)frame + 0x190 - 8)) = 0;
    *(void **)(((char *)frame + 0x194 - 8)) = lbl_8055C264;
    *(int *)(((char *)frame + 0x198 - 8)) = 0x13;
    *(void **)(((char *)frame + 0x19C - 8)) = ((char *)frame + 0xC0 - 8);
    *(int *)(((char *)frame + 0x1A0 - 8)) = 0;
    *(int *)(((char *)frame + 0x1A4 - 8)) = 0;
    *(void **)(((char *)frame + 0x1A8 - 8)) = lbl_8055C264;
    *(int *)(((char *)frame + 0x1AC - 8)) = 3;
    *(void **)(((char *)frame + 0x1B0 - 8)) = (char *)button + 0x20;
    *(int *)(((char *)frame + 0x1B4 - 8)) = 0;
    *(int *)(((char *)frame + 0x1B8 - 8)) = 0;

    result = fn_8001EF9C(*(int *)((char *)arg0 + 0x18), 0x13, 5,
                         lbl_8055C264, lbl_8055C264);

    *(void **)(((char *)frame + 0x1BC - 8)) = (char *)lbl_80344DE0 + 0x134;
    *(int *)(((char *)frame + 0x1C0 - 8)) = 3;
    *(int *)(((char *)frame + 0x1C4 - 8)) = result;
    *(int *)(((char *)frame + 0x1C8 - 8)) = 0;
    *(int *)(((char *)frame + 0x1CC - 8)) = 0;
    *(void **)(((char *)frame + 0x1D0 - 8)) = (char *)lbl_80344DE0 + 0x148;
    *(int *)(((char *)frame + 0x1D4 - 8)) = 3;
    *(int *)(((char *)frame + 0x1D8 - 8)) = *((int *)((char *)lbl_80344DE0 + 0xC0 +
                                    *(int *)((char *)arg0 + 0x24) * 8) + 1);
    *(int *)(((char *)frame + 0x1DC - 8)) = 0;
    *(int *)(((char *)frame + 0x1E0 - 8)) = 0;
    *(void **)(((char *)frame + 0x1E4 - 8)) = lbl_8055C26C;
    *(int *)(((char *)frame + 0x1E8 - 8)) = 3;
    *(void **)(((char *)frame + 0x1EC - 8)) = ((char *)frame + 0x20 - 8);
    *(int *)(((char *)frame + 0x1F0 - 8)) = 0;
    *(int *)(((char *)frame + 0x1F4 - 8)) = 0;
    *(void **)(((char *)frame + 0x1F8 - 8)) = lbl_8055C274;
    *(int *)(((char *)frame + 0x1FC - 8)) = 3;
    *(void **)(((char *)frame + 0x200 - 8)) = ((char *)frame + 0x25 - 8);
    *(int *)(((char *)frame + 0x204 - 8)) = 0;
    *(int *)(((char *)frame + 0x208 - 8)) = 0;
    *(void **)(((char *)frame + 0x20C - 8)) = lbl_8055C27C;
    *(int *)(((char *)frame + 0x210 - 8)) = 3;
    *(void **)(((char *)frame + 0x214 - 8)) = ((char *)frame + 0x2A - 8);
    *(int *)(((char *)frame + 0x218 - 8)) = 0;
    *(int *)(((char *)frame + 0x21C - 8)) = 0;
    *(void **)(((char *)frame + 0x220 - 8)) = lbl_8055C284;
    *(int *)(((char *)frame + 0x224 - 8)) = 3;
    *(void **)(((char *)frame + 0x228 - 8)) = ((char *)frame + 0x2F - 8);
    *(int *)(((char *)frame + 0x22C - 8)) = 0;
    *(int *)(((char *)frame + 0x230 - 8)) = 0;
    *(void **)(((char *)frame + 0x234 - 8)) = lbl_8055C28C;
    *(int *)(((char *)frame + 0x238 - 8)) = 3;
    *(void **)(((char *)frame + 0x23C - 8)) = ((char *)frame + 0x34 - 8);
    *(int *)(((char *)frame + 0x240 - 8)) = 0;
    *(int *)(((char *)frame + 0x244 - 8)) = 0;
    *(void **)(((char *)frame + 0x248 - 8)) = lbl_8055B860;
    *(int *)(((char *)frame + 0x24C - 8)) = 6;
    *(int *)(((char *)frame + 0x250 - 8)) = 0;
    *(int *)(((char *)frame + 0x254 - 8)) = -1;
    *(int *)(((char *)frame + 0x258 - 8)) = 0x1B;
    *(int *)(((char *)frame + 0x25C - 8)) = lbl_80498E98[0];
    *(int *)(((char *)frame + 0x260 - 8)) = lbl_80498E98[1];
    *(int *)(((char *)frame + 0x264 - 8)) = lbl_80498E98[2];
    *(int *)(((char *)frame + 0x268 - 8)) = lbl_80498E98[3];
    *(int *)(((char *)frame + 0x26C - 8)) = lbl_80498E98[4];

    *(int *)(((char *)frame + 0x08 - 8)) = lbl_802FA63C[0];
    *(void **)(((char *)frame + 0x0C - 8)) = ((char *)frame + 0x16C - 8);
    *(int *)(((char *)frame + 0x10 - 8)) = lbl_802FA63C[2];
    *(int *)(((char *)frame + 0x14 - 8)) = lbl_802FA63C[3];
    *(int *)(((char *)frame + 0x18 - 8)) = lbl_802FA63C[4];
    fn_802368E0();
    fn_80216CA8();
    n = fn_802146BC((int *)(((char *)frame + 0x08 - 8)), -0x3E7, -0x3E7, 1);

    if (button != 0)
        ((Dialog_80259224 *)button)->destroy(1);

    *(char **)(((char *)frame + 0xC0 - 8)) = (char *)&lbl_80345158;
    if (*(int *)(((char *)frame + 0x110 - 8)) != -1) {
        fn_802C6CF8(*(int *)(((char *)frame + 0x110 - 8)));
        *(int *)(((char *)frame + 0x110 - 8)) = -1;
    }
    fn_802CAC54(*(int *)(((char *)frame + 0x168 - 8)));
    return n;
}
#pragma dont_inline reset
#pragma cplusplus reset

void *fn_80259680(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 0x50);
        *(void **)arg0 = &lbl_80345158;
        if (value != -1) {
            fn_802C6CF8(value);
            *(int *)((char *)arg0 + 0x50) = -1;
        }
        fn_802CAC54(*(int *)((char *)arg0 + 0xA8));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_80259700(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

extern float lbl_80563AE4;
extern float lbl_8055F3A4;
extern signed char lbl_8055F3A0;
extern int fn_80236914(void);
void fn_80259740(int arg0, float farg0) {
    fn_80236914();
    lbl_8055F3A4 = farg0;
    lbl_8055F3A0 = (arg0 - 2) == 0;
}

int fn_8025A1C4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

int fn_8025A4CC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

extern int fn_8001EFA0(int, int);
extern int fn_8001EFA4(int, int);
extern void fn_8001EFB0(void *);
extern void fn_80130FCC(void *, int, int);
extern int fn_80259224(void **);
extern int fn_8025978C(void **);
extern void fn_802E317C(const char *, int);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8025A50C(void) {
    extern unsigned char *fn_8001EFAC(int, int);
    struct State {
        char pad0[0x0C]; volatile int state; volatile int object; volatile int selected; volatile int next;
        volatile int index; float number; char shortText[0x14]; char spareText[0x14];
        float fade; volatile unsigned char flag; char pad1[7]; char title[0x32];
        char pad2[0x32]; volatile unsigned char dialog; unsigned char difference;
        char pad3[2]; int saved; float value;
    } state;
    float base;
    int index, changed, current, result, count, objectValue, firstResult, secondResult;
    unsigned int running;
    char *src, *dst;
    char * volatile text;
    register int zero = 0;
    fn_80259148();
    base = lbl_80563AE4;
    lbl_80498EAC[0] = base;
    lbl_80498EAC[1] = lbl_80563AEC;
    lbl_80498EAC[2] = base;
    lbl_8055F398 = lbl_80563AF0;
    index = 0;
    running = 1;
    while (running != 0) {
        state.state = zero;
        objectValue = lbl_80344EA0[index * 2];
        text = lbl_80345098;
        state.index = index;
        state.object = objectValue;
        state.fade = base;
        state.value = base;
        fn_8001EFB0((void *)&state.object);
        if (lbl_8055F67C != 0) {
            state.next = state.selected + 0x32;
            firstResult = fn_8001EFA0(state.object, state.next);
            secondResult = fn_8001EFA0(state.object, state.selected);
            state.difference = (unsigned int)((firstResult - secondResult) | (secondResult - firstResult)) >> 31;
        }
        state.number = (float)(int)state.selected;
        current = (int)(state.number + lbl_80558DC4);
        fn_80130FCC(state.shortText, 0x14, current);
        changed = 1;
        if (state.dialog != 0 && state.flag == 0 && state.difference == 0)
            changed = zero;
        current = fn_8001EFA0(state.object, current);
        state.saved = current;
        result = fn_8001EFA4(state.object, current + 1);
        if (result >= 0) {
            fn_80130FCC(state.spareText, 0x14, result);
        } else {
            src = (char *)lbl_8055C380;
            count = 0x14;
            dst = state.spareText;
            while ((*dst++ = *src++) != 0) {
                count -= 1;
                if (count <= 0) { dst[-1] = (char)zero; break; }
            }
        }
        src = (char *)fn_8001EFAC(state.object, state.saved);
        if (src != 0 && changed != 0) {
            dst = state.title;
            count = 0x32;
            while ((*dst++ = *src++) != 0) {
                count -= 1;
                if (count <= 0) { dst[-1] = 0; break; }
            }
        } else {
            src = (char *)lbl_8055C380;
            count = 0x32;
            dst = state.title;
            while ((*dst++ = *src++) != 0) {
                count -= 1;
                if (count <= 0) { dst[-1] = 0; break; }
            }
        }
        state.dialog = (unsigned char)zero;
        result = fn_8025978C((void **)&text);
        switch (result) {
        case 1: index = (index + 6) % 7; break;
        case 2: index = (index + 1) % 7; break;
        case 3:
            do { result = fn_80259224((void **)&text); } while (result != -1);
            break;
        case -1: running = 0; break;
        default: fn_802E317C(lbl_80344FE0, result); break;
        }
    }
    fn_802591D8();
}
#pragma pop

void fn_8025A83C(void *arg0) {
    float a = lbl_80563AE4;
    float b = lbl_80563AE0;
    float *p = (float *)((char *)arg0 + 0x84);
    p[1] = a;
    p[0] = b;
    p[2] = a;
    p[3] = a;
    p[4] = b;
    p[5] = a;
    p[6] = a;
    p[7] = a;
    p[8] = b;
    ((void (*)(void *, void *))(*(void ***)arg0)[3])(arg0, (char *)arg0 + 4);
}

void fn_8025A87C(void *arg0) {
    float a = lbl_80563AE4;
    char zero = 0;
    float b = lbl_80563AE0;
    float *p = (float *)((char *)arg0 + 0x84);
    p[1] = a;
    p[0] = b;
    p[2] = a;
    p[3] = a;
    p[4] = b;
    p[5] = a;
    p[6] = a;
    p[7] = a;
    p[8] = b;
    ((char *)arg0)[4] = zero;
    ((char *)arg0)[0x36] = zero;
}

extern char lbl_80345208[];
__declspec(section ".sdata") extern char lbl_8055C384[];
extern int fn_8012C33C(char *);
extern int fn_802C6FC0(char *, int, int);
extern char *fn_80029004(char *, int);
extern int strlen(char *);
void fn_8025A8B8(void *arg0, char *arg1) {
    char name[0x40];
    register char *input = arg1;
    register void *obj = arg0;
    char *src;
    char *dst;
    int id;
    int count;
    signed char c;

    id = *(int *)((char *)obj + 0x50);
    if (id != -1) {
        fn_802C6CF8(id);
        *(int *)((char *)obj + 0x50) = -1;
    }

    if (*(signed char *)input != 0 && strlen(input) != 0) {
        src = lbl_80345208;
        dst = name;
        count = 0x40;
        goto prefix_char;
prefix_check:
        --count;
        if (count > 0)
            goto prefix_char;
        *--dst = 0;
        goto prefix_done;
prefix_char:
        c = (signed char)*src++;
        *dst++ = (char)c;
        if (c != 0)
            goto prefix_check;
prefix_done:
        dst = name;
        count = 0x40;
input_scan:
        if ((signed char)*dst != 0) {
            --count;
            ++dst;
            if (count > 0)
                goto input_scan;
        }
        if (count > 0) {
            goto input_char;
        }
        goto input_done;
input_check:
        --count;
        if (count > 0)
            goto input_char;
        *--dst = 0;
        goto input_done;
input_char:
        c = (signed char)*input++;
        *dst++ = (char)c;
        if (c != 0)
            goto input_check;
input_done:
        if (fn_80029004(name, '.') != 0) {
            dst = fn_80029004(name, '.');
            *dst = 0;
        }

        dst = name;
        count = 0x40;
suffix_scan:
        if ((signed char)*dst != 0) {
            --count;
            ++dst;
            if (count > 0)
                goto suffix_scan;
        }
        if (count > 0) {
            src = lbl_8055C384;
            goto suffix_char;
        }
        goto suffix_done;
suffix_check:
        --count;
        if (count > 0)
            goto suffix_char;
        *--dst = 0;
        goto suffix_done;
suffix_char:
        c = (signed char)*src++;
        *dst++ = (char)c;
        if (c != 0)
            goto suffix_check;
suffix_done:
        if (fn_8012C33C(name))
            *(int *)((char *)obj + 0x50) = fn_802C6FC0(name, 0, 0);
    }
    *(float *)((char *)obj + 0x88) = lbl_80563AE4;
    *(float *)((char *)obj + 0x84) = lbl_80563AE0;
    *(float *)((char *)obj + 0x8C) = lbl_80563AE4;
    *(float *)((char *)obj + 0x90) = lbl_80563AE4;
    *(float *)((char *)obj + 0x94) = lbl_80563AE0;
    *(float *)((char *)obj + 0x98) = lbl_80563AE4;
    *(float *)((char *)obj + 0x9C) = lbl_80563AE4;
    *(float *)((char *)obj + 0xA0) = lbl_80563AE4;
    *(float *)((char *)obj + 0xA4) = lbl_80563AE0;
}

extern int fn_801298E8(void *, int);
extern void fn_8001BA68();
extern void fn_8025AD88(void);
extern void fn_80144DAC(void *, void *);
extern float fn_80144CC8(float);
extern float fn_801429D0(float, float);
extern void fn_8025AD8C(void *, float *, float *, float *, float);
extern float fn_8025ADF4(float);
extern void GXInitLightAttnA_801BFEBC(void *, float, float, float);
extern float fn_8017F70C(float);
extern void fn_801F3198(void *);
extern void GXInitLightAttnA_80144B44(void *, float, float, float);
extern void fn_801C0E4C(void *, void *, void *);
extern float fn_8014C8B4(float, float, float, float, float);
extern void fn_8025AD3C(float *, float *, float *, float);
extern void fn_80015EB0(void *, float);
extern void fn_80015B20(void *, void *, void *);
extern void *fn_802C86DC(void);
extern float lbl_8055F398;
extern float lbl_80563AEC, lbl_80563B08, lbl_80563B0C, lbl_80563B10;
extern float lbl_80498EAC[3];
#pragma push
#pragma processor 750
void fn_8025AA90(void *arg0, float farg0) {
    unsigned char info[0x60];
    float rot[9];
    float v50[3];
    float v44[3];
    float v38[3];
    float v2C[3];
    float v20[3];
    float v14[3];
    float v8[3];
    unsigned int flags40, flags50;
    float color0, color1, sum, d1;
    if (*(int *)((char *)arg0 + 0x50) != -1) {
        if (((unsigned char *)arg0)[0x4A] != 0) {
            if (fn_801298E8(info, 0) != 0) {
                flags40 = *(int *)(info + 0x40);
                color0 = (flags40 & 2) ? lbl_80563AE0 : lbl_80563AE4;
                color1 = (flags40 & 8) ? lbl_80563AEC : lbl_80563AE4;
                sum = color1 + color0;
                lbl_8055F398 += farg0 * (lbl_80563B08 * sum);
                fn_8001BA68(v8);
                flags50 = *(int *)(info + 0x50);
                if (flags50 & 0x20) {
                    fn_80144DAC(v8, (float *)(info + 0x54));
                } else {
                    GXInitLightAttnA_801BFEBC(v8,
                        *(float *)(info + 0),
                        -fn_8025ADF4(fn_801429D0(lbl_80563AE4,
                            (lbl_80563AE0 - fn_80144CC8(*(float *)(info + 0))) + fn_80144CC8(*(float *)(info + 4)))),
                        *(float *)(info + 4));
                }
                fn_8025AD8C((char *)arg0 + 0x84, lbl_80498EAC, lbl_80498EAC, v8, farg0);
                GXInitLightAttnA_801BFEBC((char *)arg0 + 0x90, lbl_80498EAC[0], -lbl_80498EAC[1], lbl_80498EAC[2]);
                fn_801F3198((char *)arg0 + 0x90);
            }
            GXInitLightAttnA_80144B44(v14, lbl_80563AE0, lbl_80563AE4, lbl_80563AE4);
            GXInitLightAttnA_80144B44(v20, lbl_80563AE4, lbl_80563AE4, lbl_80563AE0);
            d1 = fn_8017F70C(((float (*)(void *, void *))fn_8025AD88)(v14, (char *)arg0 + 0x90));
            fn_8017F70C(((float (*)(void *, void *))fn_8025AD88)((char *)arg0 + 0x90, v20));
            if (d1 > lbl_80563B0C) {
                fn_8001BA68(v2C);
                fn_8001BA68(v38);
                fn_8001BA68(v44);
                fn_801C0E4C(v44, v14, (char *)arg0 + 0x90);
                fn_801C0E4C(v2C, (char *)arg0 + 0x90, v44);
                fn_801C0E4C(v38, (char *)arg0 + 0x90, v20);
                d1 = fn_8014C8B4(lbl_80563B0C, lbl_80563B10, lbl_80563AE4, lbl_80563AE0, d1);
                fn_8025AD3C(v50, v2C, v38, d1);
                fn_801C0E4C((char *)arg0 + 0x9C, v50, (char *)arg0 + 0x90);
                fn_801F3198((char *)arg0 + 0x9C);
                fn_801C0E4C((char *)arg0 + 0x84, (char *)arg0 + 0x90, (char *)arg0 + 0x9C);
            } else {
                fn_801C0E4C((char *)arg0 + 0x9C, v14, (char *)arg0 + 0x90);
                fn_801F3198((char *)arg0 + 0x9C);
                fn_801C0E4C((char *)arg0 + 0x84, (char *)arg0 + 0x90, (char *)arg0 + 0x9C);
            }
            fn_80015EB0(rot, lbl_8055F398);
            fn_80015B20((char *)arg0 + 0x84, rot, (char *)arg0 + 0x84);
            fn_80015B20((char *)arg0 + 0x84, (char *)arg0 + 0x84, fn_802C86DC());
        }
    }
}
#pragma pop
void fn_8025AD3C(float *out, float *a, float *b, float t) {
    float bz, az, by, dz, ay, bx, dy, ax, dx;
    float pz, py, rz, px, ry, rx;
    bz = b[2];
    az = a[2];
    by = b[1];
    dz = bz - az;
    ay = a[1];
    bx = b[0];
    dy = by - ay;
    ax = a[0];
    dx = bx - ax;
    pz = t * dz;
    py = t * dy;
    rz = az + pz;
    px = t * dx;
    ry = ay + py;
    out[2] = rz;
    rx = ax + px;
    out[1] = ry;
    out[0] = rx;
}

void fn_8025AD88(void) { PSVECDotProduct(); }

#pragma scheduling invalid_target
void fn_8025AD8C(void *unused, float *out, float *a, float *b, float t) {
    float dx, dy, dz;
    float x, y, z;
    float max, scale;
    scale = lbl_80563B14 * t;
    max = lbl_80563AE0;
    max = (max < scale) ? scale : max;
    dx = b[0] - a[0];
    dy = b[1] - a[1];
    dz = b[2] - a[2];
    x = a[0] + max * dx;
    y = a[1] + max * dy;
    z = a[2] + max * dz;
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
#pragma scheduling on
float fn_8025ADF4(float arg0) { return (float)fn_8002F234(arg0); }

extern double sin(double);
typedef unsigned int u32;
typedef float f32;
extern f32 lbl_80563B1C;
f32 fn_8025B0A8(void *arg0) {
    f32 *p = (f32 *)arg0;
    f32 d = p[1] - p[0];
    f32 out = p[0];
    out += d * lbl_80563B1C;
    return out;
}

f32 fn_8025B0C4(f32 arg0) {
    return (f32)sin(arg0);
}

void fn_8025B0E8(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_8025B134(void) {
}

void fn_8025B138(void *arg0) {
    extern unsigned char *fn_8001EFAC(int, int);
    extern int fn_801345D8(char *, int, const char *, int);
    extern const char lbl_80344F08[];
    extern char lbl_8055C38C;
    void *obj;
    int size;
    int resource;
    unsigned char *src;
    unsigned char *dst;
    unsigned char c;
    volatile int count;
    size = *(int *)((char *)arg0 + 0x1C);
    obj = *(void **)((char *)arg0 + 0x18);
    *(int *)((char *)arg0 + 0x74) = size;
    resource = *(int *)((char *)arg0 + 0x70);
    *(int *)((char *)obj + 0x4C) = size;
    src = fn_8001EFAC(resource, size);
    if (src != 0) {
        dst = (unsigned char *)obj + 4;
        count = 0x32;
        do { count--; } while (count > 0);
        dst[-1] = 0;
        do {
            c = *src++;
            *dst++ = c;
            if ((signed char)c == 0) break;
        } while (1);
    } else *((unsigned char *)obj + 4) = 0;
    if (size > 0)
        ((void (*)(char *, int, const char *, ...))fn_801345D8)((char *)obj + 0x36, 0x14, lbl_80344F08, size);
    else *((unsigned char *)obj + 0x36) = 0;
    ((void (*)(char *, int, const char *, ...))fn_801345D8)((char *)arg0 + 0x20, 0x50, &lbl_8055C38C,
                fn_8001EFAC(*(int *)((char *)arg0 + 0x70),
                            *(int *)((char *)arg0 + 0x74)));
}

extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
void fn_8025B22C(void *arg0) {
    int i;
    for (i = 1; i <= 5; i++) {
        if (*(int *)((char *)arg0 + 0x74) == i)
            fn_80214AF0(i + 5);
        else
            fn_80214A9C(i + 5);
        if (i <= *(int *)((char *)arg0 + 0x1C)) {
            fn_80214AF0(i);
            fn_80214A9C(i + 10);
        } else {
            fn_80214AF0(i + 10);
            fn_80214A9C(i);
        }
    }
}

void fn_8025B784(void) {
}

extern unsigned char *fn_8001EFAC(int, int);
extern int fn_801345D8(char *, int, const char *, int);
extern const char lbl_80344F08[];
void fn_8025BE0C(void *arg0) {
    void *arg1;
    int size;
    void *obj;
    unsigned char *src;
    unsigned char *dst;
    int count;
    arg1 = arg0;
    size = *(int *)((char *)arg0 + 0x24);
    obj = *(void **)((char *)arg1 + 0x18);
    *(int *)((char *)obj + 0x4C) = size;
    src = fn_8001EFAC(*(int *)((char *)arg0 + 0x20), size);
    if (src != 0) {
        dst = (unsigned char *)obj + 4;
        count = 0x32;
        do { count--; } while (count > 0);
        dst[-1] = 0;
        do {
            unsigned char c = *src++;
            *dst++ = c;
            if ((signed char)c == 0) break;
        } while (1);
    } else *((unsigned char *)obj + 4) = 0;
    if (size > 0)
        fn_801345D8((char *)obj + 0x36, 0x14, lbl_80344F08, size);
    else *((unsigned char *)obj + 0x36) = 0;
}

void fn_8025BED0(void *arg0) {
    void *data = *(void **)((char *)arg0 + 0x1C);
    void *obj;
    int size;
    unsigned char *src;
    unsigned char *dst;
    int count;
    if (*(unsigned char *)((char *)data + 0xC5) == 0) return;
    if (*(unsigned char *)((char *)data + 0x58) != 0) return;
    size = *(int *)((char *)data + 0xC8);
    obj = *(void **)((char *)arg0 + 0x18);
    *(int *)((char *)arg0 + 0x24) = size;
    *(int *)((char *)data + 0x18);
    *(int *)((char *)arg0 + 0x20) = *(int *)((char *)data + 0x18);
    *(int *)((char *)obj + 0x4C) = size;
    src = fn_8001EFAC(*(int *)((char *)arg0 + 0x20), size);
    if (src != 0) {
        dst = (unsigned char *)obj + 4;
        count = 0x32;
        while (--count > 0) {}
        dst[-1] = 0;
        do {
            unsigned char c = *src++;
            *dst++ = c;
            if ((signed char)c == 0) break;
        } while (1);
    } else {
        *((unsigned char *)obj + 4) = 0;
    }
    if (size > 0)
        fn_801345D8((char *)obj + 0x36, 0x14, lbl_80344F08, size);
    else
        *((unsigned char *)obj + 0x36) = 0;
    obj = *(void **)((char *)arg0 + 0x18);
    *(unsigned char *)((char *)obj + 0x4A) = 1;
}

extern void *fn_80258354(void);
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int lbl_80345158;
extern float lbl_80563AE4;
extern float lbl_8055F3A4;
extern signed char lbl_8055F3A0;
extern int fn_80236914(void);
