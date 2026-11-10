// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;
typedef unsigned long u32;
typedef float f32;
typedef s32 (*UnkFunc)(s32);
extern void* lbl_8055E9C0;
extern void* lbl_8055E9BC;
extern s32 lbl_8055E9C4;
extern void* lbl_8055E9C8;
extern void* lbl_8055E9CC;
extern u32 lbl_80339478[];
extern u32 lbl_80486F30[];
s32 fn_80145E70(void*);
extern u32 lbl_804348E8[];
s32 fn_80179630(s32);
s32 fn_801DDE78(void);
void fn_801DDED0(s32, f32*, s32, f32, f32, f32);
s32 fn_802E2C20(void);
typedef struct DbgRec { s32 a; f32 b; f32 c; s32 d; f32 e; s32 f; s32 g; s32 h; } DbgRec;
typedef s32 (*UnkFunc2)(void*, s32);
typedef struct UnkObj { UnkFunc2 *vtable; } UnkObj;
#pragma dont_inline on
s32 fn_801DDE78(void) {
    return lbl_804348E8[fn_80179630(0)];
}

s32 fn_801DDEAC(void) {
    return fn_801DDE78() + 0x32C;
}
#pragma push
#pragma scheduling invalid_target
void fn_801DDED0(s32 arg0, f32* arg1, s32 arg2, f32 farg0, f32 farg1, f32 farg2) {
    u32* entry;
    s32 idx = lbl_8055E9C4;
    entry = &lbl_80486F30[idx * 7];
    entry[0] = (u32)arg0;
    entry[1] = (u32)arg2;
    lbl_8055E9C4 = idx + 1;
    entry[2] = (u32)arg1;
    *(f32*)&entry[3] = *arg1;
    *(f32*)&entry[4] = farg0;
    *(f32*)&entry[5] = farg1;
    *(f32*)&entry[6] = farg2;
}
#pragma pop
extern s32 fn_8018A2C0(void **);
extern double lbl_80562BC8;
extern f32 lbl_80562BC0;
extern f32 lbl_80562BC4;
extern u32 lbl_803394A4;
extern void *lbl_8055E9C8;
void fn_801DDF0C(void) {
    void *sp8;
    u32 value;
    s32 i;
    u8 *entry;
    f32 x;
    f32 rounded;
    f32 *ptr;

    value = fn_801DDE78();
    if (value != (u32)lbl_8055E9C8) {
        lbl_8055E9C8 = (void *)value;
        sp8 = &lbl_803394A4;
        lbl_8055E9C4 = 0;
        fn_8018A2C0(&sp8);
        entry = (u8 *)lbl_80486F30;
        i = 0;
        while (i < lbl_8055E9C4) {
            ptr = *(f32 **)(entry + 8);
            x = *ptr / *(f32 *)(entry + 0x18);
            if (x < lbl_80562BC4) {
                rounded = x - lbl_80562BC0;
            } else {
                rounded = lbl_80562BC0 + x;
            }
            *ptr = *(f32 *)(entry + 0x18) * (f32)(s32)rounded;
            *(f32 *)(entry + 0xC) = **(f32 **)(entry + 8);
            entry += 0x1C;
            i++;
        }
    }
}

#pragma push
#pragma processor 750
void fn_801DDFE8(void* arg0) {
    float temp_e8; float temp_e4; float temp_e0; float temp_dc;
    float temp_d8; float temp_d4; float temp_d0; float temp_cc; float temp_c8;
    float temp_a0; float temp_9c; float temp_98; float temp_94; float temp_90;
    float temp_8c; float temp_88; float temp_84; float temp_80;
    temp_80 = *(float*)((unsigned char*)arg0 + 0x80);
    temp_84 = *(float*)((unsigned char*)arg0 + 0x84);
    temp_88 = *(float*)((unsigned char*)arg0 + 0x88);
    temp_8c = *(float*)((unsigned char*)arg0 + 0x8c);
    temp_90 = *(float*)((unsigned char*)arg0 + 0x90);
    temp_94 = *(float*)((unsigned char*)arg0 + 0x94);
    temp_98 = *(float*)((unsigned char*)arg0 + 0x98);
    temp_9c = *(float*)((unsigned char*)arg0 + 0x9c);
    temp_a0 = *(float*)((unsigned char*)arg0 + 0xa0);
    temp_c8 = *(float*)((unsigned char*)arg0 + 0xc8);
    temp_cc = *(float*)((unsigned char*)arg0 + 0xcc);
    temp_d0 = *(float*)((unsigned char*)arg0 + 0xd0);
    temp_d4 = *(float*)((unsigned char*)arg0 + 0xd4);
    temp_d8 = *(float*)((unsigned char*)arg0 + 0xd8);
    temp_dc = *(float*)((unsigned char*)arg0 + 0xdc);
    temp_e0 = *(float*)((unsigned char*)arg0 + 0xe0);
    temp_e4 = *(float*)((unsigned char*)arg0 + 0xe4);
    temp_e8 = *(float*)((unsigned char*)arg0 + 0xe8);
    *(float*)((unsigned char*)arg0 + 0xa4) = temp_80;
    *(float*)((unsigned char*)arg0 + 0xa8) = temp_84;
    *(float*)((unsigned char*)arg0 + 0xac) = temp_88;
    *(float*)((unsigned char*)arg0 + 0xb0) = temp_8c;
    *(float*)((unsigned char*)arg0 + 0xb4) = temp_90;
    *(float*)((unsigned char*)arg0 + 0xb8) = temp_94;
    *(float*)((unsigned char*)arg0 + 0xbc) = temp_98;
    *(float*)((unsigned char*)arg0 + 0xc0) = temp_9c;
    *(float*)((unsigned char*)arg0 + 0xc4) = temp_a0;
    *(float*)((unsigned char*)arg0 + 0xec) = temp_c8;
    *(float*)((unsigned char*)arg0 + 0xf0) = temp_cc;
    *(float*)((unsigned char*)arg0 + 0xf4) = temp_d0;
    *(float*)((unsigned char*)arg0 + 0xf8) = temp_d4;
    *(float*)((unsigned char*)arg0 + 0xfc) = temp_d8;
    *(float*)((unsigned char*)arg0 + 0x100) = temp_dc;
    *(float*)((unsigned char*)arg0 + 0x104) = temp_e0;
    *(float*)((unsigned char*)arg0 + 0x108) = temp_e4;
    *(float*)((unsigned char*)arg0 + 0x10c) = temp_e8;
}
#pragma pop
void fn_801DE0A4(void) {
    lbl_8055E9BC = 0;
    lbl_8055E9C8 = 0;
    lbl_8055E9C4 = 0;
    lbl_8055E9C0 = (void*)fn_80145E70(&lbl_80339478);
    lbl_8055E9CC = (void*)fn_802E2C20();
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801DE0E8(void) {
    class Obj {
    public:
        virtual void destroy(int);
    };
    if (lbl_8055E9C0 != 0) {
        ((Obj*)lbl_8055E9C0)->destroy(1);
    }
    lbl_8055E9C0 = 0;
}
#pragma cplusplus reset
#pragma pop
void fn_801DE12C(void) {
    lbl_8055E9CC = (void*)fn_802E2C20();
}

void fn_801DE150(void) {

}

extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_80147230(char *, const char *, ...);
extern void fn_80011A2C(void);
extern f32 lbl_80562BD0;
extern f32 lbl_80562BD4;
extern f32 lbl_80562BD8;
extern f32 lbl_80562BDC;
extern char lbl_8055ADC0[];
extern char lbl_8055ADC8[];
extern char lbl_8055ADD0[];
extern char lbl_8055ADD8[];
extern char lbl_8055ADDC[];
extern char lbl_8055ADE0[];
extern char lbl_8055ADE4[];
extern char lbl_8055ADE8[];
extern char lbl_80339484[];
extern char lbl_80339490[];
typedef DbgRec *(*DbgGet)(void *, const char *);
typedef void (*DbgVoid)(void *);
void fn_801DE154(void) {
    f32 pad[20];
    DbgRec ra, rb, rc;
    DbgRec ca, cb, cc;
    char buf1[32], buf2[32];
    s32 n;
    s32 i;
    u8 *e;
    fn_801DDF0C();
    fn_80230B5C(pad);
    fn_802C8638(pad);
    fn_802C974C(lbl_80562BD0, lbl_80562BD4, lbl_80562BD8);
    ((DbgVoid)(*(void ***)lbl_8055E9C0)[7])(lbl_8055E9C0);
    ra = *((DbgGet)(*(void ***)lbl_8055E9C0)[3])(lbl_8055E9C0, lbl_8055ADC0);
    rb = *((DbgGet)(*(void ***)lbl_8055E9C0)[3])(lbl_8055E9C0, lbl_8055ADC8);
    ca.b = rb.b - ra.b;
    ca.c = rb.c - ra.c;
    rc = *((DbgGet)(*(void ***)lbl_8055E9C0)[3])(lbl_8055E9C0, lbl_8055ADD0);
    n = fn_802E2C20() - (s32)lbl_8055E9CC;
    if (n >= 0x1388) {
        s32 t = ((n - 0x1388) * 0xC0) / 1000;
        if (t < 0) t = 0;
        if (t > 0xC0) t = 0xC0;
        ra.g -= t << 24;
        rb.g -= t << 24;
        rc.g -= t << 24;
    }
    e = (u8 *)lbl_80486F30 - 0x1C;
    for (i = -1; i < lbl_8055E9C4; i++) {
        cb = ra;
        cc = rc;
        e += 0x1C;
    }
    fn_80011A2C();
}

#pragma push
#pragma scheduling invalid_target
s32 fn_801DE5C4(s32 arg0) {
    f32 *value;
    u8 *entry;
    s32 changed;
    s32 index;
    s32 i;
    s32 result;
    f32 x;
    f32 limit;

    fn_801DDF0C();
    changed = 0;
    switch (arg0) {
    case 0x126:
        changed = 1;
        lbl_8055E9BC = (void *)(((s32)lbl_8055E9BC - 1 > -1) ? ((s32)lbl_8055E9BC - 1) : -1);
        break;
    case 0x128:
        changed = 1;
        index = (s32)lbl_8055E9BC;
        index++;
        i = lbl_8055E9C4 - 1;
        if (index >= i) index = i;
        lbl_8055E9BC = (void *)index;
        break;
    case 0x125:
    case 0x127:
        changed = 1;
        index = (s32)lbl_8055E9BC;
        if (index >= 0 && index < lbl_8055E9C4) {
            result = fn_801DDE78();
            entry = (u8 *)lbl_80486F30 + ((s32)lbl_8055E9BC * 0x1C);
            if ((u32)arg0 == 0x127U) {
                value = *(f32 **)(entry + 8);
                x = *value + *(f32 *)(entry + 0x18);
                limit = *(f32 *)(entry + 0x14);
                *value = (limit < x) ? limit : x;
            } else {
                value = *(f32 **)(entry + 8);
                x = *value - *(f32 *)(entry + 0x18);
                limit = *(f32 *)(entry + 0x10);
                *value = (limit > x) ? limit : x;
            }
            fn_801DDFE8((void *)fn_801DDEAC());
            fn_8018A180(result);
        }
        break;
    case 0x58:
        if ((s32)lbl_8055E9BC == -1) {
            changed = 1;
            result = fn_801DDE78();
            entry = (u8 *)lbl_80486F30;
            i = 0;
            while (i < lbl_8055E9C4) {
                x = *(f32 *)(entry + 0xC);
                i++;
                value = *(f32 **)(entry + 8);
                entry += 0x1C;
                *value = x;
            }
            fn_8018A180(result);
            lbl_8055E9BC = (void *)0;
        }
        break;
    }
    if (changed) lbl_8055E9CC = (void *)fn_802E2C20();
    return 0;
}
#pragma pop

typedef void (*ThunkFn)(s32, s32, s32);
void fn_801DE788(s32 arg_unused, s32 arg_a, s32 arg_b, s32 arg_c) {
    (*(void(*)(s32, f32*, s32))fn_801DDED0)(arg_a, (f32*)arg_b, arg_c);
}

