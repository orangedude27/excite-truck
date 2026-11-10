// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

struct RenderWords5 { unsigned int words[5]; };
struct RenderWords3 { unsigned int words[3]; };
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

extern float lbl_80563AE8;
extern void fn_80216D28(void);
extern void fn_80214D50(int);
extern unsigned char *fn_8001EFAC(int, int);
extern int fn_801345D8(char *, int, const char *, int);
extern const char lbl_80344F08[];
extern char lbl_8055C38C;
static inline int IsLowAndFlagged_(void *obj) {
    int result = 0;
    if (*(float *)((char *)obj + 0xCC) < lbl_80563AE8 && *(unsigned char *)((char *)obj + 0xC5) != 0) {
        result = 1;
    }
    return result;
}
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

#pragma push
#pragma dont_inline on
int fn_8025921C(void) { return 0; }
#pragma pop

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
#pragma scheduling invalid_target
__declspec(section ".sdata") extern char lbl_8055BAB8[];
__declspec(section ".sdata") extern char lbl_8055B860[];
__declspec(section ".sdata") extern char lbl_8055C260[];
__declspec(section ".sdata") extern char lbl_8055C264[];
__declspec(section ".sdata") extern char lbl_8055C26C[];
__declspec(section ".sdata") extern char lbl_8055C274[];
__declspec(section ".sdata") extern char lbl_8055C27C[];
__declspec(section ".sdata") extern char lbl_8055C284[];
__declspec(section ".sdata") extern char lbl_8055C28C[];
__declspec(section ".rodata") extern int lbl_80345158;
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
    class Dialog_80259224 {
    public:
        virtual void destroy(int);
    };
    unsigned int frame[0x9E];
    void *button;
    void *buttonA;
    void *buttonB;
    int size;
    int result;
    unsigned int i;
    unsigned char *src;
    unsigned char *dst;
    unsigned char c;
    long count;
    int n;
    void *dialog = (char *)frame + 0xC0 - 8;

    *(char **)(dialog) = (char *)&lbl_80345158;
    *(int *)(((char *)frame + 0x110 - 8)) = -1;
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
            int owner = *(int *)((char *)arg0 + 0x18);
            *(int *)((char *)buttonA + 0x14) = 0;
            *(void **)buttonA = lbl_803450F8;
            *(void **)((char *)buttonA + 0x18) = dialog;
            *(int *)((char *)buttonA + 0x70) = owner;
            *(int *)((char *)buttonA + 0x1C) = 5;
            *(unsigned char *)((char *)buttonA + 0x20) = 0;
            *(int *)((char *)buttonA + 0x74) = 5;
        }
        button = buttonA;
    } else {
        buttonB = fn_801284F8(0x78, (char *)lbl_80344DE0 + 0x114);
        if (buttonB != 0) {
            int owner;
            size = *(int *)((char *)arg0 + 0xC8);
            owner = *(int *)((char *)arg0 + 0x18);
            *(int *)((char *)buttonB + 0x14) = 0;
            *(void **)buttonB = lbl_803450F8;
            *(void **)((char *)buttonB + 0x18) = dialog;
            *(int *)((char *)buttonB + 0x70) = owner;
            *(int *)((char *)buttonB + 0x1C) = size;
            *(unsigned char *)((char *)buttonB + 0x20) = 0;
            *(int *)((char *)buttonB + 0x74) = size;
        }
        button = buttonB;
    }

    size = *(int *)((char *)arg0 + 0xC8);
    *(volatile int *)(((char *)frame + 0x10C - 8)) = size;
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
        ((int (*)(char *, int, const char *, ...))fn_801345D8)((char *)(((char *)frame + 0xF6 - 8)), 0x14, (char *)lbl_80344DE0 + 0x128, size);
    } else {
        *(unsigned char *)(((char *)frame + 0xF6 - 8)) = 0;
    }
    *(unsigned char *)(((char *)frame + 0x10A - 8)) = 1;
    for (i = 1; i <= 5; ++i) {
        ((int (*)(char *, int, const char *, ...))fn_801345D8)(((char *)frame + 0x20 - 8) + ((i - 1) << 2) + (i - 1), 0x20, lbl_8055C260,
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
    *(void **)(((char *)frame + 0x19C - 8)) = dialog;
    *(int *)(((char *)frame + 0x1A0 - 8)) = 0;
    *(int *)(((char *)frame + 0x1A4 - 8)) = 0;
    *(int *)(((char *)frame + 0x1AC - 8)) = 3;
    *(void **)(((char *)frame + 0x1A8 - 8)) = lbl_8055C264;
    *(void **)(((char *)frame + 0x1B0 - 8)) = (char *)button + 0x20;
    *(int *)(((char *)frame + 0x1B4 - 8)) = 0;
    *(int *)(((char *)frame + 0x1B8 - 8)) = 0;

    result = fn_8001EF9C(*(int *)((char *)arg0 + 0x18), 0x13, 5,
                         lbl_8055C264, lbl_8055C264);

    *(int *)(((char *)frame + 0x1C0 - 8)) = 3;
    *(void **)(((char *)frame + 0x1BC - 8)) = (char *)lbl_80344DE0 + 0x134;
    *(int *)(((char *)frame + 0x1C4 - 8)) = result;
    *(int *)(((char *)frame + 0x1C8 - 8)) = 0;
    *(int *)(((char *)frame + 0x1CC - 8)) = 0;
    *(int *)(((char *)frame + 0x1D4 - 8)) = 3;
    *(void **)(((char *)frame + 0x1D0 - 8)) = (char *)lbl_80344DE0 + 0x148;
    *(int *)(((char *)frame + 0x1D8 - 8)) = *((int *)((char *)lbl_80344DE0 + 0xC0 +
                                    *(int *)((char *)arg0 + 0x24) * 8) + 1);
    *(int *)(((char *)frame + 0x1DC - 8)) = 0;
    *(int *)(((char *)frame + 0x1E0 - 8)) = 0;
    *(int *)(((char *)frame + 0x1E8 - 8)) = 3;
    *(void **)(((char *)frame + 0x1E4 - 8)) = lbl_8055C26C;
    *(void **)(((char *)frame + 0x1EC - 8)) = ((char *)frame + 0x20 - 8);
    *(int *)(((char *)frame + 0x1F0 - 8)) = 0;
    *(int *)(((char *)frame + 0x1F4 - 8)) = 0;
    *(int *)(((char *)frame + 0x1FC - 8)) = 3;
    *(void **)(((char *)frame + 0x1F8 - 8)) = lbl_8055C274;
    *(void **)(((char *)frame + 0x200 - 8)) = ((char *)frame + 0x25 - 8);
    *(int *)(((char *)frame + 0x204 - 8)) = 0;
    *(int *)(((char *)frame + 0x208 - 8)) = 0;
    *(int *)(((char *)frame + 0x210 - 8)) = 3;
    *(void **)(((char *)frame + 0x20C - 8)) = lbl_8055C27C;
    *(void **)(((char *)frame + 0x214 - 8)) = ((char *)frame + 0x2A - 8);
    *(int *)(((char *)frame + 0x218 - 8)) = 0;
    *(int *)(((char *)frame + 0x21C - 8)) = 0;
    *(int *)(((char *)frame + 0x224 - 8)) = 3;
    *(void **)(((char *)frame + 0x220 - 8)) = lbl_8055C284;
    *(void **)(((char *)frame + 0x228 - 8)) = ((char *)frame + 0x2F - 8);
    *(int *)(((char *)frame + 0x22C - 8)) = 0;
    *(int *)(((char *)frame + 0x230 - 8)) = 0;
    *(int *)(((char *)frame + 0x238 - 8)) = 3;
    *(void **)(((char *)frame + 0x234 - 8)) = lbl_8055C28C;
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

    *(char **)(dialog) = (char *)&lbl_80345158;
    if (*(int *)(((char *)frame + 0x110 - 8)) != -1) {
        fn_802C6CF8(*(int *)(((char *)frame + 0x110 - 8)));
        *(int *)(((char *)frame + 0x110 - 8)) = -1;
    }
    fn_802CAC54(*(int *)(((char *)frame + 0x168 - 8)));
    return n;
}
#pragma scheduling on
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

extern double lbl_80563B00;
extern float lbl_80563AF4;
extern float lbl_80563AF8;
extern float lbl_80563AEC;
extern float lbl_80563AF0;
extern int fn_8001EFA0(int, int);
extern int fn_8001EFA4(int, int);
extern void fn_8001EFB0(void *);
extern void fn_80130FCC(void *, int, int);
extern int fn_8025978C(void **);
int fn_8025A1C4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8025A204(void) {
    extern unsigned char *fn_8001EFAC(int, int);
    struct State {
        char pad0[0x0C]; volatile int state; volatile int object; volatile int selected; volatile int next;
        volatile int index; float number; char shortText[0x14]; char spareText[0x14];
        float fade; volatile unsigned char flag; char pad1[7]; char title[0x32];
        char pad2[0x32]; volatile unsigned char dialog; unsigned char difference;
        char pad3[2]; int saved; float value;
    } state;
    float base;
    int *entry;
    int index, changed, current, result, count, firstResult, secondResult;
    char *src, *dst;
    char * volatile text;
    register int zero = 0;
    ((void (*)(void))fn_80259148)();
    base = lbl_80563AE4;
    lbl_80498EAC[0] = base;
    lbl_80498EAC[1] = lbl_80563AEC;
    lbl_80498EAC[2] = base;
    lbl_8055F398 = lbl_80563AF0;
    index = 0;
    entry = lbl_80344EA0;
    do {
        float f;
        if (*entry == 0) f = lbl_80563AF4;
        else f = lbl_80563AF8;
        state.state = zero;
        text = lbl_80345098;
        state.index = index;
        state.object = *entry;
        state.fade = f;
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
        state.dialog = 1;
        if (state.next != state.selected) {
            ((void (*)(void *, void *))(*(void ***)lbl_8055F394)[14])(lbl_8055F394, lbl_80344DE0);
            fn_8025978C((void **)&text);
        }
        index++;
        entry += 2;
    } while (index < 7);
    fn_802591D8();
}
#pragma pop

extern float lbl_80563AF4;
extern float lbl_80563AF8;
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

#pragma cplusplus on
extern "C" void fn_8025A83C(void *arg0) {
    class Obj {
    public:
        virtual void f0();
        virtual void apply(void *);
    };
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
    ((Obj *)arg0)->apply((char *)arg0 + 4);
}
#pragma cplusplus reset
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
    register char *dst;
    register char *src;
    register int count;
    signed char c;
    int id;
    float one;
    float zero;

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
        do {
            --count;
            ++dst;
        } while ((signed char)*dst != 0);
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
        src = lbl_8055C384;
        do {
            --count;
            ++dst;
        } while ((signed char)*dst != 0);
        if (count > 0) {
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

    one = lbl_80563AE4;
    zero = lbl_80563AE0;
    *(float *)((char *)obj + 0x88) = one;
    *(float *)((char *)obj + 0x84) = zero;
    *(float *)((char *)obj + 0x8C) = one;
    *(float *)((char *)obj + 0x90) = one;
    *(float *)((char *)obj + 0x94) = zero;
    *(float *)((char *)obj + 0x98) = one;
    *(float *)((char *)obj + 0x9C) = one;
    *(float *)((char *)obj + 0xA0) = one;
    *(float *)((char *)obj + 0xA4) = zero;
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
#pragma dont_inline on
#pragma opt_common_subs off
#pragma opt_propagation off
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
    bz = b[2]; az = a[2]; by = b[1]; dz = bz - az;
    ay = a[1]; bx = b[0]; dy = by - ay; ax = a[0]; dx = bx - ax;
    pz = t * dz; py = t * dy; rz = pz + az; px = t * dx;
    ry = py + ay; out[2] = rz; rx = px + ax; out[1] = ry; out[0] = rx;
}

void fn_8025AD88(void) { PSVECDotProduct(); }

#pragma scheduling invalid_target
void fn_8025AD8C(void *unused, float *out, float *a, float *b, float t) {
    float bx, ax, by, dx, ay, bz, dy, az, dz;
    float px, py, rx, pz, ry, rz;
    float max, scale;
    scale = lbl_80563B14 * t; max = lbl_80563AE0;
    max = (max < scale) ? max : scale;
    bx = b[0]; by = b[1]; bz = b[2];
    ax = a[0]; ay = a[1]; az = a[2];
    dx = bx - ax; dy = by - ay; dz = bz - az;
    px = max * dx; py = max * dy; rx = ax + px; pz = max * dz;
    ry = ay + py; out[0] = rx; rz = az + pz; out[1] = ry; out[2] = rz;
}
#pragma scheduling on
float fn_8025ADF4(float arg0) { return (float)fn_8002F234(arg0); }

extern float lbl_802FA628[5];
extern char lbl_80345218[];
extern float lbl_80563B18, lbl_80563B1C, lbl_80563B20, lbl_80563B24, lbl_80563B28, lbl_80563B2C, lbl_80563B30, lbl_8055F39C;
extern void *fn_8022EDC4(void);
extern void fn_8025B134(void);
extern void fn_8025B0E8(void *, const void *);
extern float fn_8025B0A8(void *);
extern float fn_8025B0C4(float);
extern void fn_80144D80(void *, float, float, float);
extern void fn_802C77F0(int, void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_801C2B9C(void *, void *, void *);
extern void fn_8001BA68(void *);
extern void fn_801E67B4(void *, void *, void *);
extern void fn_801C0E60(void *, void *, void *);
extern void fn_801BFE7C(void *, void *, void *);
extern int fn_802C9950(int);
extern int fn_802C9994(int);
extern float fn_802C99E8(float);
extern void *fn_802C9A40(void);
extern void fn_802C9A1C(void *);
extern void fn_802D7554(int);
extern void fn_802CA294(int);
extern void fn_802D9230(void);
extern void fn_802C9694(void *, float, float, float);
extern void fn_802C744C(int, void *);
extern void fn_802C96DC(void *, int);
#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_8025AE18(void *arg0) {
    char *obj = (char *)arg0;
    float matrix[9];
    float values[5];
    float ranges[6];
    float color[3], oldcolor[3];
    float state[3], vec[3];
    char *camera, *other;
    int a, b, index;
    float ratio, size, z, y, x, old;
    if (*(int *)(obj + 0x50) == -1 || *(unsigned char *)(obj + 0x4A) == 0) return;
    fn_8025B0E8(obj + 0x54, ((void *(*)(void *))fn_8025B134)(obj + 0x84));
    other = (char *)fn_8022EDC4();
    x = *(float *)(other + 0x38);
    fn_80144D80(matrix, x, x, x);
    fn_80015B20(obj + 0x54, obj + 0x54, matrix);
    fn_802C77F0(*(int *)(obj + 0x50), ranges);
    *(struct RenderWords5 *)values = *(struct RenderWords5 *)lbl_802FA628;
    index = *(int *)(obj + 0x4C);
    if (index <= 0) {
        fn_802E30C8(lbl_80345218);
    } else {
        size = (lbl_80563B18 * values[index - 1]) * lbl_80563B1C;
        ratio = size / fn_8025B0C4(lbl_80563B1C * lbl_8055F39C);
        size = lbl_80563B20 + size;
        camera = (char *)fn_802C86DC();
        fn_801429D0(ratio, size);
        fn_801C2B9C(obj + 0x78, camera + 0x24, camera + 0x18);
        fn_8001BA68(vec);
        z = fn_8025B0A8(&ranges[4]);
        y = fn_8025B0A8(&ranges[2]);
        x = fn_8025B0A8(&ranges[0]);
        GXInitLightAttnA_801BFEBC(vec, x, y, z);
        fn_801E67B4(vec, vec, obj + 0x54);
        fn_801C0E60(obj + 0x78, obj + 0x78, vec);
        fn_801BFE7C(obj + 0x78, obj + 0x78, other + 0x24);
    }
    color[0] = lbl_80563B24; color[1] = lbl_80563B28; color[2] = lbl_80563B2C;
    a = fn_802C9950(0xFF646464);
    b = fn_802C9994(0xFFB4B4B4);
    old = fn_802C99E8(lbl_80563AE0);
    *(struct RenderWords3 *)oldcolor = *(struct RenderWords3 *)fn_802C9A40();
    fn_802C9A1C(color);
    fn_802D7554(1);
    fn_802CA294(*(int *)(obj + 0xA8));
    fn_802D9230();
    fn_802C9694(state, lbl_80563B20, lbl_80563B30, lbl_8055F39C);
    fn_802C744C(*(int *)(obj + 0x50), obj + 0x54);
    fn_802D7554(0);
    fn_802C9A1C(oldcolor);
    fn_802C99E8(old);
    fn_802C9994(b);
    fn_802C9950(a);
    fn_802C96DC(state, -1);
}
#pragma pop

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

// The achievement-level dialog fn_80259224 builds: the name of the threshold a
// level reached, the "Level %d" line and the level itself.
typedef struct LevelDialog {
    /* 0x00 */ void *vtable;             // lbl_80345158
    /* 0x04 */ char rankName[0x32];      // name of the threshold reached
    /* 0x36 */ char levelText[0x14];     // "Level %d", empty below level 1
    /* 0x4A */ unsigned char flag4A;
    /* 0x4B */ char pad4B;
    /* 0x4C */ int level;                // level the dialog shows
    /* 0x50 */ int sound;                // sound to release when the dialog goes away, -1 when none
    /* 0x54 */ char pad54[0x54];
    /* 0xA8 */ int context;
} LevelDialog;

// The "previous/next level" button of that dialog (fn_801284F8 makes it and
// fn_80259224 fills these in); fn_8025B2BC is its message handler.
typedef struct LevelButton {
    /* 0x00 */ void *vtable;             // lbl_803450F8
    /* 0x04 */ char pad04[0x10];
    /* 0x14 */ int pad14;
    /* 0x18 */ LevelDialog *dialog;
    /* 0x1C */ int levelCount;           // how many levels the achievement has
    /* 0x20 */ char description[0x50];   // "%s" filled with the threshold's name
    /* 0x70 */ int achievement;          // which achievement the levels belong to
    /* 0x74 */ int level;                // level the button is on
} LevelButton;

// Message handler of the achievement-level selector button: "one level down"
// (0x128) and "one level up" (0x126) step the level within the achievement's
// thresholds and refresh the dialog's texts with the name and value of the
// threshold now shown; a button already at the first or last level plays the
// "cannot go any further" cue instead.
int fn_8025B2BC(void *arg0, int arg1) {
    typedef void (*Fmt)(char *, int, const char *, ...);
    LevelButton *button = (LevelButton *)arg0;
    LevelDialog *dialog;
    int level;
    unsigned char *nameSrc;
    unsigned char nameC;
    int nameLeft;
    unsigned char *nameDst;
    int bounded;
    int stepped;
    int oldLevel;
    int achievement;
    int level2;
    LevelDialog *dialog2;
    unsigned char *nameSrc2;
    unsigned char nameC2;
    int nameLeft2;
    unsigned char *nameDst2;
    int bounded2;
    int stepped2;
    int oldLevel2;
    int achievement2;

    switch (arg1) {
    case 0x128:  // one level down
        oldLevel = button->level;
        level = button->levelCount;
        stepped = oldLevel - 1;
        button->level = stepped;
        bounded = 1;                     // never below the first level
        if (stepped > 1) bounded = stepped;
        if (bounded < level) level = bounded;  // nor above what the achievement has
        button->level = level;
        if (oldLevel != level) {
            achievement = button->achievement;
            dialog = button->dialog;
            dialog->level = level;
            nameSrc = fn_8001EFAC(achievement, level);
            if (nameSrc == 0) goto prev_else;
            nameDst = (unsigned char *)(dialog->rankName);
            nameLeft = 0x32;
            goto prev_copy;
prev_next:
            nameLeft--;
            if (nameLeft > 0) goto prev_copy;
            nameDst[-1] = 0;
            goto prev_done;
prev_copy:
            nameC = *nameSrc++;
            *nameDst++ = nameC;
            if ((signed char)nameC == 0) goto prev_done;
            goto prev_next;
prev_else:
            dialog->rankName[0] = 0;
prev_done:
            if (level > 0) {
                ((Fmt)fn_801345D8)(dialog->levelText, 0x14, lbl_80344F08, level);
            } else {
                dialog->levelText[0] = 0;  // below the first threshold: no level
            }
            ((Fmt)fn_801345D8)(button->description, 0x50, &lbl_8055C38C,
                        fn_8001EFAC(button->achievement, button->level));
        } else {
            fn_80216D28();
            fn_80214D50(1);
        }
        return 1;
    case 0x126:  // one level up
        oldLevel2 = button->level;
        level2 = button->levelCount;
        stepped2 = oldLevel2 + 1;
        button->level = stepped2;
        bounded2 = 1;
        if (stepped2 > 1) bounded2 = stepped2;
        if (bounded2 < level2) level2 = bounded2;
        button->level = level2;
        if (oldLevel2 != level2) {
            achievement2 = button->achievement;
            dialog2 = button->dialog;
            dialog2->level = level2;
            nameSrc2 = fn_8001EFAC(achievement2, level2);
            if (nameSrc2 == 0) goto next_else;
            nameDst2 = (unsigned char *)(dialog2->rankName);
            nameLeft2 = 0x32;
            goto next_copy;
next_next:
            nameLeft2--;
            if (nameLeft2 > 0) goto next_copy;
            nameDst2[-1] = 0;
            goto next_done;
next_copy:
            nameC2 = *nameSrc2++;
            *nameDst2++ = nameC2;
            if ((signed char)nameC2 == 0) goto next_done;
            goto next_next;
next_else:
            dialog2->rankName[0] = 0;
next_done:
            if (level2 > 0) {
                ((Fmt)fn_801345D8)(dialog2->levelText, 0x14, lbl_80344F08, level2);
            } else {
                dialog2->levelText[0] = 0;
            }
            ((Fmt)fn_801345D8)(button->description, 0x50, &lbl_8055C38C,
                        fn_8001EFAC(button->achievement, button->level));
        } else {
            fn_80216D28();
            fn_80214D50(1);
        }
        return 1;
    default:
        return 0;
    }
}

// One row of the achievements display: a value counting up to a goal, graded
// against the thresholds of one achievement (lbl_802FDF30, "score", "win",
// "AAA", "air", "tree_run", "drift", "rings", ...).  fn_8025B520 fills a row
// in and fn_8025B788 updates it once per frame.
#ifndef ACHIEVEMENT_ROW_DEFINED
#define ACHIEVEMENT_ROW_DEFINED
typedef struct AchievementRow {
    /* 0x00 */ char pad00[0x18];
    /* 0x18 */ int achievement;           // which achievement this row shows
    /* 0x1C */ int startValue;            // value the row starts counting from
    /* 0x20 */ int goal;                  // value the row counts up to
    /* 0x24 */ int pad24;
    /* 0x28 */ float progress;            // value shown, eased towards the goal
    /* 0x2C */ char progressText[0x14];   // progress as text
    /* 0x40 */ char goalText[0x14];       // next threshold as text, empty at the last one
    /* 0x54 */ float rate;                // progress added per second
    /* 0x58 */ unsigned char done;        // the progress has not reached the goal yet
    /* 0x59 */ unsigned char soundPending; // play soundId once, then clear
    /* 0x5C */ int soundId;               // result sound to play
    /* 0x60 */ char rankName[0x32];       // name of the threshold reached
    /* 0x92 */ char shownRankName[0x32];  // rankName as last handed to the achievement list
    /* 0xC4 */ unsigned char flagC4;      // row belongs to the results screen
    /* 0xC5 */ unsigned char flagC5;      // row is live
    /* 0xC8 */ int rank;                  // how many thresholds the value passed
    /* 0xCC */ float timer;               // seconds since the row started
} AchievementRow;
#endif

extern char lbl_80344E20[];
#pragma cplusplus on
extern "C" void fn_8025B520(void *arg0) {
    // The "achieve tally" banner of the results/pause screen (lbl_8055F394);
    // slots 12 and 14 are the ones fn_8025B788 uses as show() and setProgress().
    class AchievementBanner {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual void m11();
        virtual void show(char *name);
        virtual void m13();
        virtual void setProgress(char *name, float amount);
    };
    AchievementRow *row = (AchievementRow *)arg0;
    float start;
    int showName;
    int value;
    int result;
    unsigned char goalC;
    unsigned char *goalSrc;
    int goalLeft;
    unsigned char *goalDst;
    unsigned char *nameSrc;
    unsigned char nameC;
    int nameLeft;
    unsigned char *nameDst;
    unsigned char blankC;
    unsigned char *blankSrc;
    int blankLeft;
    unsigned char *blankDst;
    unsigned char shownC;
    unsigned char *shownSrc;
    int shownLeft;
    unsigned char *shownDst;

    // The row starts at its start value rather than counting up to it from zero.
    start = (float)row->startValue;
    row->progress = start;
    value = (int)(start + lbl_80558DC4);  // 2^-23 bias, then truncate
    fn_80130FCC(row->progressText, 0x14, value);
    // A results-screen row keeps its threshold name hidden until it is finished.
    showName = 1;
    if (row->flagC4 != 0) {
        if (row->done != 0 || row->flagC5 == 0) {
            showName = 0;
        }
    }
    result = fn_8001EFA0(row->achievement, value);
    row->rank = result;
    result = fn_8001EFA4(row->achievement, result + 1);
    if (result >= 0) {
        fn_80130FCC(row->goalText, 0x14, result);
    } else {
        goalDst = (unsigned char *)(row->goalText);  // last threshold: blank the text
        goalSrc = lbl_8055C380;
        goalLeft = 0x14;
        goto goal_copy;
goal_next:
        goalLeft--;
        if (goalLeft > 0) goto goal_copy;
        goalDst[-1] = 0;
        goto goal_done;
goal_copy:
        goalC = *goalSrc++;
        *goalDst++ = goalC;
        if ((signed char)goalC != 0) goto goal_next;
goal_done:;
    }
    nameSrc = fn_8001EFAC(row->achievement, row->rank);
    if (nameSrc != 0 && showName != 0) {
        nameDst = (unsigned char *)(row->rankName);
        nameLeft = 0x32;
        goto name_copy;
name_next:
        nameLeft--;
        if (nameLeft > 0) goto name_copy;
        nameDst[-1] = 0;
        goto name_done;
name_copy:
        nameC = *nameSrc++;
        *nameDst++ = nameC;
        if ((signed char)nameC == 0) goto name_done;
        goto name_next;
    } else {
        blankDst = (unsigned char *)(row->rankName);  // nothing named: blank it
        blankSrc = lbl_8055C380;
        blankLeft = 0x32;
        goto blank_copy;
blank_next:
        blankLeft--;
        if (blankLeft > 0) goto blank_copy;
        blankDst[-1] = 0;
        goto name_done;
blank_copy:
        blankC = *blankSrc++;
        *blankDst++ = blankC;
        if ((signed char)blankC != 0) goto blank_next;
    }
name_done:
    // Counting state cleared: the row is not done and has no result sound queued.
    row->done = 1;
    row->soundPending = 0;
    row->soundId = -0x3E8;
    if (row->flagC4 != 0) {
        // restart the tally banner ("achieve_tally", the same name fn_8025B788
        // fills in) from zero progress and show it again
        ((AchievementBanner *)lbl_8055F394)->setProgress(lbl_80344E20, lbl_80563AE4);
        ((AchievementBanner *)lbl_8055F394)->show(lbl_80344E20);
    }
    fn_80214A9C(0x10);  // fade the next-threshold and goal-reached elements out
    fn_80214A9C(0xD);
    // The threshold name counts as announced already: fn_8025B788 only reports
    // a name to the achievement list when it changes.
    shownSrc = (unsigned char *)(row->rankName);
    shownDst = (unsigned char *)(row->shownRankName);
    shownLeft = 0x32;
    goto shown_copy;
shown_next:
    shownLeft--;
    if (shownLeft > 0) goto shown_copy;
    shownDst[-1] = 0;
    goto shown_done;
shown_copy:
    shownC = *shownSrc++;
    *shownDst++ = shownC;
    if ((signed char)shownC != 0) goto shown_next;
shown_done:;
}
#pragma cplusplus reset
void fn_8025B784(void) {
}

extern int stricmp(const char *, const char *);
extern float fn_80214D48(void);           // seconds since the last frame
extern int fn_8001EFA8(int achievement);  // how many thresholds an achievement has
extern void fn_80236954(void *);          // marks the achievement of this name as reached
extern void fn_80236958(void *);          // clears the "reached" flag of this achievement name
extern void fn_802168BC(int);             // asks for a result sound to be played
extern float lbl_80563B34;                // 0.8f: seconds the value waits before it starts climbing

// (AchievementRow is declared above fn_8025B520.)

#pragma cplusplus on
// One row of the achievements display: eases the shown value towards the goal,
// refreshes the value and next-threshold text and the name of the threshold
// reached, and fades the HUD elements that go with them in and out.
extern "C" void fn_8025B788(void *arg0) {
    class AchievementBanner {
    public:
        virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
        virtual void show(char *name);
        virtual void finish(char *name);
        virtual void setProgress(char *name, float amount);
    };
    char *ctx = (char *)lbl_80344DE0;  // +0x20/+0x40 banner names, +0x464 achievement name
    AchievementRow *row = (AchievementRow *)arg0;
    float amount, capped;
    int value, showName, result;
    unsigned char wasDone;
    unsigned char goalC; unsigned char *goalSrc; int goalLeft; unsigned char *goalDst;
    unsigned char rankC; unsigned char *rankSrc; int rankLeft; unsigned char *rankDst;
    unsigned char blankC; unsigned char *blankSrc; int blankLeft; unsigned char *blankDst;
    unsigned char shownC; unsigned char *shownSrc; int shownLeft; unsigned char *shownDst;

    // A new threshold name that has not been handed to the achievement list yet:
    // report the achievement as reached and remember the name.
    if (stricmp(row->shownRankName, row->rankName) != 0 && row->rankName[0] != 0) {
        fn_80236954(ctx + 0x464);
        shownSrc = (unsigned char *)(row->rankName);
        shownDst = (unsigned char *)(row->shownRankName);
        shownLeft = 0x32;
        goto shown_copy;
shown_next:
        shownLeft--;
        if (shownLeft > 0) goto shown_copy;
        shownDst[-1] = 0;
        goto shown_done;
shown_copy:
        shownC = *shownSrc++;
        *shownDst++ = shownC;
        if ((signed char)shownC != 0) goto shown_next;
shown_done:;
    }
    // Once the pause is over, ease the shown value up by rate * dt, up to the goal.
    if (*(unsigned char *)&lbl_8055F3A0 && row->timer >= lbl_80563B34) {
        capped = row->progress + row->rate * fn_80214D48();
        amount = (float)row->goal;
        amount = amount < capped ? amount : capped;
        row->progress = amount;
    }
    wasDone = row->done;
    row->done = (int)(row->progress + lbl_80558DC4) < row->goal;
    row->timer += fn_80214D48();
    if (row->done) {
        // Still counting: keep the banner filled to the shared progress.
        float limit = lbl_8055F3A4;
        amount = lbl_80563AE0;
        amount = amount < limit ? amount : limit;
        ((AchievementBanner *)lbl_8055F394)->setProgress(ctx + 0x40, amount);
    } else if (wasDone) {
        // Just reached the goal: close the banner and play the result jingle.
        ((AchievementBanner *)lbl_8055F394)->finish(ctx + 0x40);
        if (row->flagC4 && row->flagC5) {
            ((AchievementBanner *)lbl_8055F394)->show(ctx + 0x20);
            fn_80214AF0(0x10);
            row->timer = lbl_80563AE4;
        }
    }
    if (row->soundPending) {
        fn_80236958(ctx + 0x464);
        fn_802168BC(row->soundId);
    }
    value = (int)(row->progress + lbl_80558DC4);
    fn_80130FCC(row->progressText, 0x14, value);
    // A results-screen row only shows its threshold name once it is finished.
    showName = 1;
    if (row->flagC4 != 0) {
        if (row->done != 0 || row->flagC5 == 0) {
            showName = 0;
        }
    }
    result = fn_8001EFA0(row->achievement, value);
    row->rank = result;
    result = fn_8001EFA4(row->achievement, result + 1);
    if (result >= 0) {
        fn_80130FCC(row->goalText, 0x14, result);
    } else {
        goalDst = (unsigned char *)(row->goalText);  // no threshold left: blank the text
        goalSrc = lbl_8055C380;
        goalLeft = 0x14;
        goto goal_copy;
goal_next:
        goalLeft--;
        if (goalLeft > 0) goto goal_copy;
        goalDst[-1] = 0;
        goto goal_done;
goal_copy:
        goalC = *goalSrc++;
        *goalDst++ = goalC;
        if ((signed char)goalC != 0) goto goal_next;
goal_done:;
    }
    rankSrc = fn_8001EFAC(row->achievement, row->rank);
    if (rankSrc != 0 && showName != 0) {
        rankDst = (unsigned char *)(row->rankName);
        rankLeft = 0x32;
        goto rank_copy;
rank_next:
        rankLeft--;
        if (rankLeft > 0) goto rank_copy;
        rankDst[-1] = 0;
        goto rank_done;
rank_copy:
        rankC = *rankSrc++;
        *rankDst++ = rankC;
        if ((signed char)rankC == 0) goto rank_done;
        goto rank_next;
    } else {
        blankDst = (unsigned char *)(row->rankName);  // nothing to name: blank it
        blankSrc = lbl_8055C380;
        blankLeft = 0x32;
        goto blank_copy;
blank_next:
        blankLeft--;
        if (blankLeft > 0) goto blank_copy;
        blankDst[-1] = 0;
        goto rank_done;
blank_copy:
        blankC = *blankSrc++;
        *blankDst++ = blankC;
        if ((signed char)blankC != 0) goto blank_next;
    }
rank_done:
    // The last threshold has a name of its own instead of a "next goal" line.
    if (row->rank >= fn_8001EFA8(row->achievement)) {
        fn_80214AF0(0x15); fn_80214A9C(0x14);
    } else {
        fn_80214AF0(0x14); fn_80214A9C(0x15);
    }
    if (row->rank == 0 || row->flagC4) fn_80214A9C(0xF);
    else fn_80214AF0(0xF);
    if (row->flagC4) fn_80214A9C(0xE);
    else fn_80214AF0(0xE);
    if (row->rank < 2 || row->flagC4) fn_80214A9C(0x11);
    else fn_80214AF0(0x11);
    if (row->done || IsLowAndFlagged_(row)) fn_80214A9C(0xD);
    else fn_80214AF0(0xD);
}
#pragma cplusplus reset

int fn_8025BBFC(void *self, int input) {
    /* Handle menu input/state transitions for this UI object: reject blocked
       states, process confirm/cancel/navigation cases, and trigger the
       corresponding follow-up actions. */
    char *obj = (char *)self;
    if (*(unsigned char *)(obj + 0x58) != 0 || IsLowAndFlagged_(obj) != 0) {
        fn_80216D28();
    }
    switch (input) {
    case 0xD:
        if (*(unsigned char *)(obj + 0xC4) != 0) {
            if (*(unsigned char *)(obj + 0x58) != 0) {
                *(float *)(obj + 0x28) = (float)*(int *)(obj + 0x20);
            } else if (IsLowAndFlagged_(obj) == 0) {
                *(unsigned char *)(obj + 0x59) = 1;
                *(int *)(obj + 0x5C) = -2;
            }
            break;
        }
        if (*(int *)(obj + 0xC8) > 1 || fn_8025921C() != 0) {
            if (IsLowAndFlagged_(obj) == 0) {
                *(int *)(obj + 0x5C) = 3;
                *(unsigned char *)(obj + 0x59) = 1;
                break;
            }
        }
        fn_80214D50(1);
        return 0;
    case 0x1B:
        if (*(unsigned char *)(obj + 0xC4) == 0) {
            *(unsigned char *)(obj + 0x59) = 1;
            *(int *)(obj + 0x5C) = -1;
            break;
        }
        return 0;
    case 0x126:
        if (*(unsigned char *)(obj + 0xC4) == 0) {
            *(unsigned char *)(obj + 0x59) = 1;
            *(int *)(obj + 0x5C) = 1;
            fn_80216CA8();
            break;
        }
        return 0;
    case 0x128:
        if (*(unsigned char *)(obj + 0xC4) == 0) {
            *(unsigned char *)(obj + 0x59) = 1;
            *(int *)(obj + 0x5C) = 2;
            fn_80216CA8();
            break;
        }
        return 0;
    default:
        return 0;
    }
    return 1;
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
