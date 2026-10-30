#include <types.h>
#include <math.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern f32 lbl_8055E3C8;
extern f32 lbl_80560470;
extern f32 lbl_80560474;
extern f32 lbl_80560490;

extern "C" s32 fn_80128668(void);
extern void* lbl_80358680[];

class CollisionEntry {
public:
    virtual void unk0();
    virtual void apply(s32, s32);
};
extern s32 lbl_8055E3C4;
extern "C" void** lbl_8055D5FC;
extern "C" void** lbl_8055D600;
extern "C" void** lbl_8055D604;
extern "C" void** lbl_8055D5F4;
extern "C" void** lbl_8055D5F8;

class CleanupEntry {
public:
    virtual void cleanup(s32);
};

class PaneContainer {
public:
    virtual void dummy0();
    virtual void* getPane(const char* name);
};

struct PaneData {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    f32 f10;
    u32 w14;
    u32 w18;
    u32 w1c;
};

extern "C" const char* fn_80131234(const char*);
extern "C" void fn_80147230(void*, const char*, ...);
extern "C" void fn_801476C4(...);
extern "C" s32 fn_80147C50(u32, u32, f32);
extern "C" void fn_80147CEC(void*, void*, void*, f32);
extern "C" void* fn_8017960C(s32);
extern "C" s32 fn_801E85A4(void);
extern "C" void fn_80232928(s32);
extern "C" void fn_80232930(void);

extern char lbl_802FDB68[], lbl_802FDC70[];
extern char lbl_802FDC84[], lbl_802FDC5C[], lbl_802FDC48[], lbl_802FDC34[];
extern "C" int lbl_802FDC98[];
extern "C" void* fn_80145E70(void*);
extern "C" void* fn_801284F8(u32, void*);
extern "C" void* fn_802CAC28(void*, s32);
extern "C" void* fn_80207848(void*, s32);
extern char lbl_80558D08[4];
__declspec(section ".data") extern f32 lbl_80558DC4;
extern f32 lbl_8056047C;
extern f32 lbl_80560480;
extern f32 lbl_80560484;
extern f32 lbl_80560488;
extern f32 lbl_8056048C;
extern f32 lbl_80560460;
extern f32 lbl_80560464;
extern f64 lbl_80560468;
#pragma push
#pragma scheduling invalid_target
extern "C" f32 fn_8001DA5C(s32 arg0) {
    f32 scale = lbl_80560460;
    f64 bias = lbl_80560468;
    f64 angle;
    f64 fraction;
    s32 quotient;
    s32 remainder;
    union { f64 d; u32 words[2]; } angle_bits;
    union { f64 d; u32 words[2]; } fraction_bits;
    angle_bits.words[0] = 0x43300000;
    angle_bits.words[1] = (u32)arg0 ^ 0x80000000;
    angle = angle_bits.d - bias;
    quotient = lbl_8055E3C4 / arg0;
    remainder = lbl_8055E3C4 - quotient * arg0;
    fraction_bits.words[0] = 0x43300000;
    fraction_bits.words[1] = (u32)remainder ^ 0x80000000;
    fraction = fraction_bits.d - bias;
    return lbl_80560464 + lbl_80560464 * (f32)sin((f64)(scale * fraction / angle));
}
#pragma pop
extern "C" void fn_8001DAD8(void) { extern int fn_8001DA5C(int); fn_8001DA5C(0x40); }

extern "C" void fn_8001DAE0(f32* arg0, f32 arg1) {
    *arg0 = arg1;
}

extern "C" f32 fn_8001DAE8(void) {
    return lbl_8055E3C8;
}

#pragma dont_inline on
extern "C" f32 fn_8001DAF0(void *arg0) {
    f32 value = (fn_8001DAE8() - *(f32 *)((u8 *)arg0 + 4)) / *(f32 *)arg0;
    f32 result = lbl_80560470;
    if (result >= value)
        result = value;
    if (result > lbl_80560474)
        result = lbl_80560474;
    return result;
}
#pragma dont_inline reset

extern "C" s32 fn_8001DD2C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma scheduling off
extern "C" void fn_8001DD6C(void) {
    if (lbl_8055D604 != 0) ((CleanupEntry*)lbl_8055D604)->cleanup(1);
    lbl_8055D604 = 0;
    if (lbl_8055D5FC != 0) ((CleanupEntry*)lbl_8055D5FC)->cleanup(1);
    lbl_8055D5FC = 0;
    if (lbl_8055D600 != 0) ((CleanupEntry*)lbl_8055D600)->cleanup(1);
    lbl_8055D600 = 0;
    if (lbl_8055D5F4 != 0) ((CleanupEntry*)lbl_8055D5F4)->cleanup(1);
    lbl_8055D5F4 = 0;
    if (lbl_8055D5F8 != 0) ((CleanupEntry*)lbl_8055D5F8)->cleanup(1);
    lbl_8055D5F8 = 0;
    for (s32 i = 0; i < 6; i++) {
        if (lbl_80358680[i] != 0) ((CleanupEntry*)lbl_80358680[i])->cleanup(1);
        lbl_80358680[i] = 0;
    }
}
#pragma scheduling invalid_target
extern "C" void fn_8001DEA8(void) {
    class Entry {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
    };
    void*** p;
    u32 i;
    p = (void***)lbl_80358680;
    i = 0;
    do {
        Entry* obj = (Entry*)p[0];
        obj->f2();
        i++;
        p++;
    } while (i < 6);
}
#pragma scheduling on
extern "C" void fn_8001DF04(void) {
}

extern "C" void fn_8001DF08(s32 arg0, s32 arg1) {
    ((CollisionEntry*)lbl_80358680[0])->apply(arg0, arg1);
    ((CollisionEntry*)lbl_80358680[2])->apply(arg0, arg1);
}

// Invalid-target scheduling reuses r5 for the object base before passing the zero argument.
#pragma scheduling invalid_target
extern "C" void fn_8001DF84(s32 arg0) {
    void *p = lbl_80358680[1];
    ((CollisionEntry *)p)->apply(arg0, 0);
}
#pragma scheduling invalid_target
extern "C" void fn_8001DFA8(s32 arg0) {
    ((CollisionEntry*)lbl_80358680[3])->apply(arg0, 0);
}
#pragma scheduling on
// Invalid-target scheduling keeps the table load ahead of the literal arguments.
#pragma scheduling invalid_target
extern "C" void fn_8001DFCC(void) {
    ((CollisionEntry *)lbl_80358680[4])->apply(9, 17);
}
#pragma scheduling on
extern "C" void fn_8001DFF0(void) {
    ((CollisionEntry*)lbl_80358680[5])->apply(0, 0);
}

extern "C" void fn_802CAC54(void*);
extern "C" int lbl_802FDC98[];
extern "C" void* __dt__14CollisionSpaceFv(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_802FDC98;
        fn_802CAC54(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" s32 fn_8001E26C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8001E2AC(void* arg0, s32 arg1) {
    PaneData buffer;
    f32* p;
    const char* base = lbl_802FDB68;
    void* truck = fn_8017960C(arg1);
    p = (f32*)arg0 + arg1 * 3;
    bool active = *(f32*)((u8*)truck + 0x2588) > lbl_80560474;
    if (active) {
        if (!((f32)fabs(p[2] - lbl_80560470) <= lbl_80558DC4)) {
            p[1] = lbl_8055E3C8;
            p[2] = lbl_80560470;
        } else {
            p[2] = *(volatile f32*)&p[2] - lbl_8056047C;
        }
    } else {
        p[2] = lbl_80560474;
    }
    p[3] = *(f32*)((u8*)truck + 0x25A0);

    PaneContainer* paneMgr;
    if (fn_801E85A4() == 2) {
        paneMgr = (PaneContainer*)lbl_8055D5F8;
    } else {
        paneMgr = (PaneContainer*)lbl_8055D5F4;
    }
    if (paneMgr == NULL) {
        return;
    }

    if (p[2] > lbl_80560480) {
        arg1 = (s32)(lbl_80560484 * p[2]);
        void* r28 = paneMgr->getPane(base + 0x1FC);
        void* r29 = paneMgr->getPane(base + 0x20C);
        if (r28 != NULL && r29 != NULL) {
            f32 f2 = lbl_80560470;
            f32 f0 = ((lbl_8055E3C8 - p[1]) - f2) / lbl_80560488;
            f2 = (f2 < f0) ? f2 : f0;
            f2 = (f2 > lbl_80560474) ? f2 : lbl_80560474;
            fn_80147CEC(&buffer, r28, r29, lbl_80560474 + f2 * lbl_80560470);
            f32 factor1 = ((f32(*)(void))fn_8001DAD8)();
            u32 c1 = (u32)fn_80147C50(*(u32*)((u8*)r28 + 0x18), *(u32*)((u8*)r29 + 0x18), factor1);
            buffer.w18 = (c1 & 0x00FFFFFF) | (arg1 << 24);
            arg1 <<= 24;
            f32 factor2 = ((f32(*)(void))fn_8001DAD8)();
            u32 c2 = (u32)fn_80147C50(*(u32*)((u8*)r29 + 0x18), *(u32*)((u8*)r28 + 0x18), factor2);
            fn_80232928((c2 & 0x00FFFFFF) | arg1);
            fn_80147230(&buffer, lbl_80558D08, fn_80131234(base + 0x220));
            fn_80232930();
        }
    } else if (p[3] > lbl_8056048C) {
        void* r3 = paneMgr->getPane(base + 0x238);
        if (r3 != NULL) {
            PaneData temp = *(PaneData*)r3;
            f32 factor = ((f32(*)(void))fn_8001DAD8)();
            temp.w18 = fn_80147C50(0xC0FFFFFFU, 0xFFFF2020U, factor);
            fn_801476C4(&temp);
        }
    }
}

extern "C" f32 fn_8001DA5C(s32);
extern f32 lbl_80560490;
#pragma scheduling off
extern "C" void fn_8001E544(void* arg0) {
    f32 b;
    f32 a;
    a = lbl_80560490;
    b = lbl_80560474;
    ((f32*)arg0)[1] = a;
    ((f32*)arg0)[2] = b;
    ((f32*)arg0)[3] = b;
    ((f32*)arg0)[4] = a;
    ((f32*)arg0)[5] = b;
    ((f32*)arg0)[6] = b;
    ((f32*)arg0)[7] = a;
    ((f32*)arg0)[8] = b;
    ((f32*)arg0)[9] = b;
    ((f32*)arg0)[10] = a;
    ((f32*)arg0)[11] = b;
    ((f32*)arg0)[12] = b;
    ((f32*)arg0)[13] = a;
    ((f32*)arg0)[14] = b;
    ((f32*)arg0)[15] = b;
    ((f32*)arg0)[16] = a;
    ((f32*)arg0)[17] = b;
    ((f32*)arg0)[18] = b;
    ((f32*)arg0)[19] = a;
    ((f32*)arg0)[20] = b;
    ((f32*)arg0)[21] = b;
    ((f32*)arg0)[22] = a;
    ((f32*)arg0)[23] = b;
    ((f32*)arg0)[24] = b;
}
#pragma scheduling on
extern char lbl_802FDC70[];
#pragma push
#pragma scheduling invalid_target
extern "C" void* fn_8001E5B0(void* arg0, s32 arg1) {
    class Entry {
    public:
        virtual void destroy(s32);
    };
    void* entry;

    if (arg0 != 0) {
        entry = *(void**)((u8*)arg0 + 0x24);
        *(void**)arg0 = (void*)lbl_802FDC70;
        if (entry != 0) {
            if (entry != 0)
                ((Entry*)entry)->destroy(1);
        }
        if (arg1 > 0)
            ((s32 (*)(void*))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma pop
extern "C" void fn_8001E964(void* arg0) {
    f32 value = lbl_80560490;
    *(f32*)((u8*)arg0 + 0x34) = value;
    *(f32*)((u8*)arg0 + 0x2C) = value;
}

extern "C" s32 fn_8001E974(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void* fn_801EA9A0(s32);
extern "C" f32 fn_801E7E18(void);
extern "C" void* fn_801E7E3C(void);
extern "C" void fn_801345D8(char*, s32, const char*, ...);
extern "C" s32 fn_80147ABC(s32, s32, const char*, f64, ...);
extern "C" u32 lbl_802ED840[];
extern "C" char lbl_80558D14[];
extern "C" char lbl_80558D1C[];
extern "C" char lbl_80558D24[];
__declspec(section ".sdata") extern char lbl_80558D14[];
__declspec(section ".sdata") extern char lbl_80558D1C[];
__declspec(section ".sdata") extern char lbl_80558D24[];
#pragma scheduling invalid_target
extern "C" void fn_8001E9B4(s32 arg0, s32 arg1) {
    register char* base = lbl_802FDB68;
    register s32* record;
    register void* object = fn_801EA9A0(arg1);
    f32 now = fn_801E7E18();
    record = (s32*)((u8*)arg0 + (arg1 << 3));
    struct Locals {
        s32 idsA[4];
        s32 idsB[4];
        u32 thresholds[4];
        char temp[30];
        u16 pad;
        char nameB[32];
        char nameA[32];
        char text[32];
    } work;
    volatile u32* src = (volatile u32*)lbl_802ED840;
    void* widget;
    f32 delta;

    if (*(s32*)((u8*)object + 0x1C) > record[1]) {
        *(f32*)((u8*)record + 8) = now;
        record[1] = *(s32*)((u8*)object + 0x1C);
    }
    delta = now - *(volatile f32*)((u8*)arg0 + (arg1 << 3) + 8);
    widget = *((void* volatile*)&lbl_8055D604);
    work.thresholds[0] = *src++;
    work.thresholds[1] = *src++;
    work.thresholds[2] = *src++;
    work.thresholds[3] = *src++;
    if (widget != 0 && delta < *(f32*)&work.thresholds[3]) {
        s32 row = 0;
        do {
            s32* out = work.idsA;
            if (row == 0) out = work.idsB;
            s32 col = 0;
            do {
                const char* suffix = lbl_80558D24;
                if (row == 0) suffix = lbl_80558D1C;
                fn_801345D8(work.text, 0x20, lbl_80558D14, suffix, col);
                *out = ((s32 (**)(void*, char*))(*(void***)widget))[3](widget, work.text);
                col++;
                out++;
            } while (col < 4);
            row++;
        } while (row < 2);
        void* menu = fn_801E7E3C();
        s32 current = record[1];
        if (current != 1 && current <= 3) {
            s32 count = *(s32*)((u8*)menu + 8);
            if (current < count) {
                const char* text = fn_80131234(base + 0x278);
                char* dst = work.nameA;
                s32 left = 0x20;
                            goto copy_a;
            count_a:
                left--;
                if (left > 0) goto copy_a;
                *(dst - 1) = 0;
                goto end_a;
            copy_a:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_a; }
            end_a: ;
                fn_801345D8(work.temp, 0x1E, base + 0x28C, record[1]);
                text = fn_80131234(work.temp);
                dst = work.nameB;
                left = 0x20;
                            goto copy_b;
            count_b:
                left--;
                if (left > 0) goto copy_b;
                *(dst - 1) = 0;
                goto end_b;
            copy_b:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_b; }
            end_b: ;
            } else {
                if (current == count) {
                const char* text = fn_80131234(base + 0x2A4);
                char* dst = work.nameA;
                s32 left = 0x20;
                            goto copy_c;
            count_c:
                left--;
                if (left > 0) goto copy_c;
                *(dst - 1) = 0;
                goto end_c;
            copy_c:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_c; }
            end_c: ;
                text = fn_80131234(base + 0x2B8);
                dst = work.nameB;
                left = 0x20;
                            goto copy_d;
            count_d:
                left--;
                if (left > 0) goto copy_d;
                *(dst - 1) = 0;
                goto end_d;
            copy_d:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_d; }
            end_d: ;
                } else if ((count + 1) != current) {
                    return;
                }
            }
            s32 index = 0;
            if (delta < *(f32*)&work.thresholds[1]) {
                index = 0;
            } else if (delta < *(f32*)&work.thresholds[2]) {
                index = 1;
            } else if (delta < *(f32*)&work.thresholds[3]) {
                index = 2;
            }
            s32 nextIndex = index + 1;
            f32 low = *(f32*)&work.thresholds[index];
            f32 high = *(f32*)&work.thresholds[nextIndex];
            f32 numerator = delta - low;
            f32 denominator = high - low;
            f32 lower = lbl_80560470;
            f32 t = numerator / denominator;
            if (lower < t) lower = t;
            if (lower > lbl_80560474) lower = lbl_80560474;
            f32 value = lbl_80560474 + lower * lbl_80560470;
            fn_80232928(-1);
            fn_80147ABC(work.idsB[index], work.idsB[nextIndex], lbl_80558D08, value, work.nameA);
            fn_80147ABC(work.idsA[index], work.idsA[nextIndex], lbl_80558D08, value, work.nameB);
            fn_80232930();
        }
    }
}
#pragma scheduling on
extern "C" void fn_8001ED2C(void* arg0) {
    f32 value = lbl_80560490;
    *(s32*)((u8*)arg0 + 0x04) = 0;
    *(f32*)((u8*)arg0 + 0x08) = value;
    *(s32*)((u8*)arg0 + 0x0C) = 0;
    *(f32*)((u8*)arg0 + 0x10) = value;
    *(s32*)((u8*)arg0 + 0x14) = 0;
    *(f32*)((u8*)arg0 + 0x18) = value;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(f32*)((u8*)arg0 + 0x20) = value;
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(f32*)((u8*)arg0 + 0x28) = value;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *(f32*)((u8*)arg0 + 0x30) = value;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    *(f32*)((u8*)arg0 + 0x38) = value;
    *(s32*)((u8*)arg0 + 0x3C) = 0;
    *(f32*)((u8*)arg0 + 0x40) = value;
}

extern "C" s32 fn_8001ED78(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801E85A4(void);
extern "C" char lbl_802FDE38[];
extern "C" char lbl_802FDE48[];
extern "C" char lbl_802FDE54[];
extern "C" void** lbl_8055D5FC;
extern "C" void** lbl_8055D600;
// The array label, typed virtual call, and fixed-arity cleanup call preserve the target instructions.
extern "C" void fn_8001EDB8(void) {
    struct Obj { virtual void v0(); virtual void v1(void *); };
    void* object = lbl_802FDE38;
    void* selected;
    if (fn_801E85A4() == 2) {
        selected = lbl_8055D600;
    } else {
        selected = lbl_8055D5FC;
    }
    ((Obj *)selected)->v1(object);
    ((void (*)(void))fn_801476C4)();
}

extern "C" s32 fn_8001EE14(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_8001EE54(void) {
    class Pane {
    public:
        virtual void v0();
        virtual void set(void*);
    };
    void* object = lbl_802FDE48;
    void* selected;

    if (fn_801E85A4() == 2)
        selected = lbl_8055D600;
    else
        selected = lbl_8055D5FC;
    ((Pane*)selected)->set(object);
    ((void (*)(void))fn_801476C4)();

    object = lbl_802FDE54;
    if (fn_801E85A4() == 2)
        selected = lbl_8055D600;
    else
        selected = lbl_8055D5FC;
    ((Pane*)selected)->set(object);
    ((void (*)(void))fn_801476C4)();
}

