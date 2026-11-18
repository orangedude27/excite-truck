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
#define sParamCount lbl_8055E9C4 /* number of records gathered in sParamTable */
#define sParamTable lbl_80486F30 /* 28-byte tunable-parameter records */
#define activeVehicle fn_801DDE78 /* currently selected vehicle value */
#define TUNE_BLOCK_OFFSET 0x32C   /* offset to a vehicle's tunable-parameter block */
s32 fn_80145E70(void*);
extern u32 lbl_804348E8[];
s32 fn_80179630(s32);
s32 fn_801DDE78(void);
void fn_801DDED0(s32, f32*, s32, f32, f32, f32);
s32 fn_802E2C20(void);
typedef struct DbgRec { s32 a; s32 b; s32 c; s32 d; f32 e; s32 f; s32 g; s32 h; } DbgRec;
typedef s32 (*UnkFunc2)(void*, s32);
typedef struct UnkObj { UnkFunc2 *vtable; } UnkObj;
#pragma dont_inline on
/* Return the currently selected value from the lbl_804348E8 table, using the
   index that fn_80179630 reports for slot 0; callers treat it as the active
   vehicle identifier when gathering the garage's tunable parameters. */
s32 fn_801DDE78(void) {
    return lbl_804348E8[fn_80179630(0)];
}

/**
 * Returns the address of the active vehicle's tunable-parameter block: the
 * vehicle value from fn_801DDE78 plus the 0x32C block offset. The caller
 * passes it to fn_801DDFE8 to reset the vehicle's tuning floats.
 */
s32 fn_801DDEAC(void) {
    return activeVehicle() + TUNE_BLOCK_OFFSET;
}
#pragma push
#pragma scheduling invalid_target
/* Appends one tunable-parameter record (name, unit, value pointer/value, min, max, step) to the garage overlay's entry table. */
void fn_801DDED0(s32 name, f32* value, s32 unit, f32 min, f32 max, f32 step) {
    u32* entry;
    s32 index = sParamCount;
    entry = &sParamTable[index * 7];
    entry[0] = (u32)name;
    entry[1] = (u32)unit;
    sParamCount = index + 1;
    entry[2] = (u32)value;
    *(f32*)&entry[3] = *value;
    *(f32*)&entry[4] = min;
    *(f32*)&entry[5] = max;
    *(f32*)&entry[6] = step;
}
#pragma pop
extern void fn_8018A2C0();
extern double lbl_80562BC8;
extern f32 lbl_80562BC0;
extern f32 lbl_80562BC4;
extern u8 lbl_803394A4[];
extern void *lbl_8055E9C8;
void fn_801DDF0C(void) {
    void *sp8;
    u32 value;
    u8 *entry;
    s32 i;
    f32 x;
    f32 rounded;
    f32 *ptr;
    f32 off;
    f32 thr;
    value = fn_801DDE78();
    if (value != (u32)lbl_8055E9C8) {
        lbl_8055E9C4 = 0;
        sp8 = lbl_803394A4;
        lbl_8055E9C8 = (void *)value;
        fn_8018A2C0(&sp8);
        thr = lbl_80562BC4;
        off = lbl_80562BC0;
        entry = (u8 *)lbl_80486F30;
        i = 0;
        while (i < lbl_8055E9C4) {
            ptr = *(f32 **)(entry + 8);
            x = *ptr / *(f32 *)(entry + 0x18);
            if (x < thr) {
                rounded = x - off;
            } else {
                rounded = off + x;
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
/* Copies two float blocks forward by 0x24 bytes (0x80..0xA0 -> 0xA4..0xC4, 0xC8..0xE8 -> 0xEC..0x10C). */
void fn_801DDFE8(void* obj) {
    float temp_e8; float temp_e4; float temp_e0; float temp_dc;
    float temp_d8; float temp_d4; float temp_d0; float temp_cc; float temp_c8;
    float temp_a0; float temp_9c; float temp_98; float temp_94; float temp_90;
    float temp_8c; float temp_88; float temp_84; float temp_80;
    temp_80 = *(float*)((unsigned char*)obj + 0x80);
    temp_84 = *(float*)((unsigned char*)obj + 0x84);
    temp_88 = *(float*)((unsigned char*)obj + 0x88);
    temp_8c = *(float*)((unsigned char*)obj + 0x8c);
    temp_90 = *(float*)((unsigned char*)obj + 0x90);
    temp_94 = *(float*)((unsigned char*)obj + 0x94);
    temp_98 = *(float*)((unsigned char*)obj + 0x98);
    temp_9c = *(float*)((unsigned char*)obj + 0x9c);
    temp_a0 = *(float*)((unsigned char*)obj + 0xa0);
    temp_c8 = *(float*)((unsigned char*)obj + 0xc8);
    temp_cc = *(float*)((unsigned char*)obj + 0xcc);
    temp_d0 = *(float*)((unsigned char*)obj + 0xd0);
    temp_d4 = *(float*)((unsigned char*)obj + 0xd4);
    temp_d8 = *(float*)((unsigned char*)obj + 0xd8);
    temp_dc = *(float*)((unsigned char*)obj + 0xdc);
    temp_e0 = *(float*)((unsigned char*)obj + 0xe0);
    temp_e4 = *(float*)((unsigned char*)obj + 0xe4);
    temp_e8 = *(float*)((unsigned char*)obj + 0xe8);
    *(float*)((unsigned char*)obj + 0xa4) = temp_80;
    *(float*)((unsigned char*)obj + 0xa8) = temp_84;
    *(float*)((unsigned char*)obj + 0xac) = temp_88;
    *(float*)((unsigned char*)obj + 0xb0) = temp_8c;
    *(float*)((unsigned char*)obj + 0xb4) = temp_90;
    *(float*)((unsigned char*)obj + 0xb8) = temp_94;
    *(float*)((unsigned char*)obj + 0xbc) = temp_98;
    *(float*)((unsigned char*)obj + 0xc0) = temp_9c;
    *(float*)((unsigned char*)obj + 0xc4) = temp_a0;
    *(float*)((unsigned char*)obj + 0xec) = temp_c8;
    *(float*)((unsigned char*)obj + 0xf0) = temp_cc;
    *(float*)((unsigned char*)obj + 0xf4) = temp_d0;
    *(float*)((unsigned char*)obj + 0xf8) = temp_d4;
    *(float*)((unsigned char*)obj + 0xfc) = temp_d8;
    *(float*)((unsigned char*)obj + 0x100) = temp_dc;
    *(float*)((unsigned char*)obj + 0x104) = temp_e0;
    *(float*)((unsigned char*)obj + 0x108) = temp_e4;
    *(float*)((unsigned char*)obj + 0x10c) = temp_e8;
}
#pragma pop
/* RealName: GarageOverlay_Init -- see the comment in the body. */
void fn_801DE0A4(void) {
    /* RealName: GarageOverlay_Init
     * Starts up the garage screen's live parameter overlay: creates the
     * OverlayLayout that draws "garage.val" and clears the state that goes
     * with it -- the list of tunable entries (count and the table it was
     * built from), the row the +/- keys edit, and the time stamp the
     * on-screen text fades out from (fn_801DE154 fades after 5000 ms). */
#define garageOverlay   lbl_8055E9C0 /* OverlayLayout made from "garage.val" */
#define editRow         lbl_8055E9BC /* entry the up/down keys select */
#define entrySet        lbl_8055E9C8 /* table the entry list was built from */
#define entryCount      lbl_8055E9C4 /* entries gathered in lbl_80486F30 */
#define lastEditMs      lbl_8055E9CC /* ms of the last edit, see fn_802E2C20 */
#define garageValName   lbl_80339478 /* "garage.val" */
#define OverlayLayoutCreate fn_80145E70 /* OverlayLayout* by .val file name */
#define GetTimeMs       fn_802E2C20  /* ms since the timer's first call */

    editRow = 0;
    entrySet = 0;
    entryCount = 0;
    garageOverlay = (void *)OverlayLayoutCreate(garageValName);
    lastEditMs = (void *)GetTimeMs();

#undef garageOverlay
#undef editRow
#undef entrySet
#undef entryCount
#undef lastEditMs
#undef garageValName
#undef OverlayLayoutCreate
#undef GetTimeMs
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801DE0E8(void) {
    /* RealName: GarageOverlay_Destroy
     * Destroys the garage overlay layout object (lbl_8055E9C0, created from "garage.val")
     * if present, then clears the global pointer. */
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
#define lastEditMs lbl_8055E9CC /* ms of the last edit, see fn_802E2C20 */
#define GetTimeMs fn_802E2C20 /* ms since the timer's first call */
/* Stamp the current time (ms since the timer's first call) as the garage editor's last-edit time. */
void fn_801DE12C(void) {
    lastEditMs = (void*)GetTimeMs();
}

void fn_801DE150(void) {

}

extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_80147230(void *, const char *, ...);
extern void fn_80011A2C(void);
extern f32 lbl_80562BD0;
extern f32 lbl_80562BD4;
extern f32 lbl_80562BD8;
extern f32 lbl_80562BDC;
__declspec(section ".sdata") extern const char lbl_8055ADC0[];
__declspec(section ".sdata") extern const char lbl_8055ADC8[];
__declspec(section ".sdata") extern const char lbl_8055ADD0[];
__declspec(section ".sdata") extern const char lbl_8055ADD8[];
__declspec(section ".sdata") extern const char lbl_8055ADDC[];
__declspec(section ".sdata") extern const char lbl_8055ADE0[];
__declspec(section ".sdata") extern const char lbl_8055ADE4[];
__declspec(section ".sdata") extern const char lbl_8055ADE8[];
extern char lbl_80339484[];
extern char lbl_80339490[];
typedef DbgRec *(*DbgGet)(void *, const char *);
typedef void (*DbgVoid)(void *);
#pragma push
#pragma processor 603
#pragma cplusplus on
extern "C" void fn_801DE154(void) {
    class Gui {
    public:
        virtual void v0();
        virtual DbgRec *v1(const char *);
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    f32 pad[20];
    DbgRec ra, rb, rc;
    f32 caB, caC;
    DbgRec lineA, lineC;
    s32 n, i, t;
    s32 r5, r7;
    u8 *e;
    f32 x, y;
    s32 xa, ya;
    f32 *value;
    DbgRec *p;
    f32 off;
    fn_801DDF0C();
    fn_80230B5C(pad);
    fn_802C8638(pad);
    fn_802C974C(lbl_80562BD0, lbl_80562BD4, lbl_80562BD8);
    ((Gui *)lbl_8055E9C0)->v5();
    p = ((Gui *)lbl_8055E9C0)->v1(lbl_8055ADC0);
    ra.a = p->a; ra.b = p->b; ra.c = p->c; ra.d = p->d;
    ra.e = p->e; ra.f = p->f; ra.g = p->g; ra.h = p->h;
    p = ((Gui *)lbl_8055E9C0)->v1(lbl_8055ADC8);
    rb.a = p->a; rb.b = p->b; rb.c = p->c; rb.d = p->d;
    rb.e = p->e; rb.f = p->f; rb.g = p->g; rb.h = p->h;
    caB = *(f32 *)&rb.b - *(f32 *)&ra.b;
    caC = *(f32 *)&rb.c - *(f32 *)&ra.c;
    p = ((Gui *)lbl_8055E9C0)->v1(lbl_8055ADD0);
    rc.a = p->a; rc.b = p->b; rc.c = p->c; rc.d = p->d;
    rc.e = p->e; rc.f = p->f; rc.g = p->g; rc.h = p->h;
    n = fn_802E2C20() - (s32)lbl_8055E9CC;
    if (n >= 0x1388) {
        t = ((n - 0x1388) * 0xC0) / 1000;
        t = t & (((-t) & ~t) >> 31);
        t = (t < 0xC0) ? t : 0xC0;
        ra.g -= t << 24;
        rb.g -= t << 24;
        rc.g -= t << 24;
    }
    off = lbl_80562BC0;
    e = (u8 *)lbl_80486F30 - 0x1C;
    for (i = -1; i < lbl_8055E9C4; i++) {
        lineA.a = ra.a;
        *(f32 *)&lineA.b = *(f32 *)&ra.b + caB * (f32)i;
        *(f32 *)&lineA.c = *(f32 *)&ra.c + caC * (f32)i;
        lineA.d = ra.d;
        lineA.e = ra.e;
        lineA.f = ra.f;
        lineA.g = ra.g;
        lineA.h = ra.h;
        lineC.a = rc.a;
        *(f32 *)&lineC.b = *(f32 *)&rc.b + caB * (f32)i;
        *(f32 *)&lineC.c = *(f32 *)&rc.c + caC * (f32)i;
        lineC.d = rc.d;
        lineC.e = rc.e;
        lineC.f = rc.f;
        lineC.g = rc.g;
        lineC.h = rc.h;
        if (i == (s32)lbl_8055E9BC) {
            lineA.g = rb.g;
            lineC.g = rb.g;
        }
        if (i >= 0) {
            fn_80147230(&lineA, lbl_8055ADD8, *(s32 *)(e + 0x1C));
            x = *(f32 *)(e + 0x1C + 0xC) / *(f32 *)(e + 0x1C + 0x18);
            if (x < lbl_80562BC4) {
                x -= off;
            } else {
                x += off;
            }
            xa = (s32)x;
            value = *(f32 **)(e + 0x1C + 8);
            y = *value / *(f32 *)(e + 0x1C + 0x18);
            if (y < lbl_80562BC4) {
                y -= off;
            } else {
                y += off;
            }
            ya = (s32)y;
            if (xa == ya) {
                r7 = (s32)lbl_8055ADDC;
            } else if (*value > *(f32 *)(e + 0x1C + 0xC)) {
                r7 = (s32)lbl_8055ADE0;
            } else {
                r7 = (s32)lbl_8055ADE4;
            }
            r5 = (*(f32 *)(e + 0x1C + 0x18) > lbl_80562BDC) ? 0 : 2;
            fn_80147230(&lineC, lbl_80339484, r5, *(s32 *)(e + 0x1C + 4), r7, *value);
        } else {
            fn_80147230(&lineA, lbl_80339490);
            if (i == (s32)lbl_8055E9BC) {
                fn_80147230(&lineC, lbl_8055ADE8);
            }
        }
        e += 0x1C;
    }
    fn_80011A2C();
}
#pragma cplusplus reset
#pragma pop
#pragma scheduling invalid_target
extern void fn_8018A180(s32);
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
        index = (s32)lbl_8055E9BC + 1;
        lbl_8055E9BC = (void *)((index < lbl_8055E9C4 - 1) ? index : lbl_8055E9C4 - 1);
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
            for (i = 0; i < lbl_8055E9C4; i++) {
                **(f32 **)(entry + 8) = *(f32 *)(entry + 0xC);
                entry += 0x1C;
            }
            fn_8018A180(result);
            lbl_8055E9BC = (void *)0;
        }
        break;
    }
    if (changed) lbl_8055E9CC = (void *)fn_802E2C20();
    return 0;
}
#pragma scheduling on

typedef void (*ThunkFn)(s32, s32, s32);
/* Drop the unused first argument and forward (name, value, unit) to fn_801DDED0. */
void fn_801DE788(s32 unused, s32 name, s32 value, s32 unit) {
    (*(void(*)(s32, f32*, s32))fn_801DDED0)(name, (f32*)value, unit);
}

