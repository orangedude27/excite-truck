#include "types.h"
typedef struct { f32 x, y, z; } Vec3_80015A20;
extern s32 fn_80014ADC(void);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float fabsf(float);
extern void *lbl_8055D350;
extern f32 lbl_80560368, lbl_805603B4, lbl_80560360, lbl_8056039C, lbl_805603A0, lbl_805603A4, lbl_805603A8, lbl_805603AC, lbl_80562068;
extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[], lbl_802FCE88[];
extern u8 lbl_802FCD44[], lbl_802FCD78[];
extern u8 lbl_80558BA0;
extern void fn_80013EDC(void *, void *, s32, char *, char *, f32, f32, f32);
extern void fn_801476C4(void);
extern u8 lbl_80558BBC[6];
extern u8 lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
extern void *lbl_803577E0[];
extern u8 lbl_802FCBEC[], lbl_802FCBF8[], lbl_802FCBC8[];
extern s32 fn_802C9A58(void);
/* The race HUD ("RaceOverlay"): one object per screen, registered by
 * fn_80014524 and cleared by fn_80014664. Its +0x50 is the "raceovr.val"
 * layout (fn_80145E70) whose elements the lap readout looks up by name. */
#define sRaceOverlays lbl_803577E0       /* RaceOverlay *, indexed by screen */
#define MSG_LAP_BODY_0 lbl_802FCBEC      /* "lap_body_0" */
#define MSG_LAP_BODY_1_WS lbl_802FCBF8   /* "lap_body_1_ws", the widescreen lap number */
#define MSG_LAP_DENOMINATOR lbl_802FCBC8 /* "lap_denominator", the 4:3 lap number */
extern void fn_80013BD0(void *, s32, s32, s32);
typedef struct { void *vtable; s32 field4; } VtblObj;
extern f32 lbl_80560360, lbl_80560368, lbl_8056036C, lbl_80560370, lbl_80560374, lbl_80560398;
extern f32 fn_801E7E24(void);
extern f32 fn_801E7E24(void);
extern f32 lbl_80560360, lbl_80560364, lbl_80560398;
extern u8 lbl_802FCB98[];
extern u8 lbl_802FCE18[];
extern void fn_80130FCC(void *, s32, s32);
extern void fn_801473F8(void *, void *, ...);
extern char lbl_80558BA4, lbl_80558BA8, lbl_80558BAC, lbl_80558BB4;
extern f32 lbl_805603B8;
extern void fn_802C8BD0(s32);
extern void fn_801E4F20(s32);
extern void fn_801E4F3C(s32, s32, f32, f32, f32, f32, f32);
extern void fn_801E4FF4(void);
extern void fn_802C8D74(void);
extern f32 lbl_805603E8, lbl_805603EC, lbl_805603F0, lbl_805603F4;
typedef struct { s32 a; f32 x; f32 y; s32 d; f32 e; f32 f; s32 g; } Rec7;
typedef struct { s32 a; f32 x; f32 y; s32 d; f32 e; s32 f; s32 g; s32 h; } Rec8;
extern f64 lbl_80560390;
#define VCALL(slot, ofs) ((void *(*)(void *, void *))(*(void ***)obj)[slot])(obj, lbl_802FCB98 + (ofs))
#define VC(slot, ofs) ((void *(*)(void *, void *))(*(void ***)obj)[slot])(obj, base + (ofs))
#define CP8(R, q) do { (R).a = (q)->a; *(s32 *)&(R).x = *(s32 *)&(q)->x; *(s32 *)&(R).y = *(s32 *)&(q)->y; (R).d = (q)->d; (R).e = (q)->e; (R).f = (q)->f; (R).g = (q)->g; (R).h = (q)->h; } while (0)
extern f32 fn_80011EB0(s32);
extern f32 lbl_80560378, lbl_8056037C, lbl_80560380, lbl_80560384, lbl_80560388;
extern void fn_802E317C(void *, ...);
extern void fn_80147230(void *, void *, ...);
extern void fn_80130978(void *, s32, f32);
typedef struct { char pad0[4]; int f4; char pad8[4]; void *fC; char pad10[0x20]; void *f30; } State148;
f32 fn_80013D60(f32);
void fn_80014B9C(void *);
s32 fn_800151DC(void *);
void fn_800154B8(void);
void fn_80015658(void *);
s32 fn_80016214(void);
void fn_80015F30(void *);
void fn_80148134(f32 *, f32 *, s32, f32, f32);
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80013BD0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1(void *);
    };
    char first[20];
    char second[20];
    u8 *base = lbl_802FCB98;
    ((Obj *)arg0)->v1(base + 0);
    fn_801476C4();
    ((Obj *)arg0)->v1(base + 0xC);
    fn_801476C4();
    fn_80130FCC(first, 20, arg1);
    fn_801473F8(arg0, base + 0x1C, first);
    if (arg3) {
        fn_80130FCC(second, 20, arg2);
        fn_801473F8(arg0, base + 0x30, second);
    }
}
#pragma pop
/* Increase *value toward 1.0 over time (by delta/0.35 per frame while delta > 0), clamping at 1.0. */
void fn_80013C98(f32 *value) {
    f32 step;
    if (fn_801E7E24() > lbl_80560360) {
        step = fn_801E7E24() / lbl_80560364;
        step = *value + step;
        step = step < lbl_80560368 ? step : lbl_80560368;
        *value = step;
    }
}

/* Decay a value toward 0 by delta-time (fn_801E7E24 / 0.35), clamping at 0 when dt > 0. */
void fn_80013CFC(f32 *valuePtr) {
    f32 step;
    if (fn_801E7E24() > lbl_80560360) {
        step = fn_801E7E24() / lbl_80560364;
        step = *valuePtr - step;
        step = step > lbl_80560360 ? step : lbl_80560360;
        *valuePtr = step;
    }
}

f32 fn_80013D60(f32 x) {
    f32 c4, cc;
    f32 y;
    if (lbl_80560360 == x)
        return x;
    if (lbl_80560368 == x) {
        return x;
    } else {
        y = lbl_8056036C;
        if (x < y)
            y = lbl_8056036C;
        else if (x > lbl_80560368) {
            y = lbl_80560368;
        } else if (x > lbl_80560360) {
            c4 = lbl_80560374;
            cc = lbl_80560370;
            cc *= x;
            c4 *= x;
            cc *= x;
            c4 *= x;
            x *= cc;
            y = x + c4;
        } else {
            c4 = lbl_80560374;
            cc = lbl_80560370;
            cc *= x;
            c4 *= x;
            cc *= x;
            c4 *= x;
            x *= cc;
            y = x - c4;
        }
        return y;
    }
}

#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
extern "C" void fn_80013DF0(s32 screen) {
    /* Dispatch v3 ("lap_body_0") on the race-overlay layout at +0x50 of
     * screen's RaceOverlay. */
    class Obj {
    public:
        virtual void v0();
        virtual void v3(void *);
    };
    ((Obj *)*(void **)((u8 *)sRaceOverlays[screen] + 0x50))->v3(MSG_LAP_BODY_0);
}
#pragma pop
#pragma push
#pragma cplusplus on
/* Look up the lap-number element of screen `screen`'s race HUD layout: the
   widescreen body element when the display is in widescreen mode, the plain lap
   denominator in 4:3. Returns the layout's 0x20-byte element entry, or 0. */
extern "C" void *fn_80013E1C(s32 screen) {
    class RaceOvrLayout {
    public:
        virtual void method0x8();              /* 0x8 */
        virtual void *findElement(void *name); /* 0xC fn_80148284: stricmp over the element list */
    };
    if (fn_802C9A58() != 0) {
        return ((RaceOvrLayout *)*(void **)((u8 *)sRaceOverlays[screen] + 0x50))->findElement(MSG_LAP_BODY_1_WS);
    } else {
        return ((RaceOvrLayout *)*(void **)((u8 *)sRaceOverlays[screen] + 0x50))->findElement(MSG_LAP_DENOMINATOR);
    }
}
#pragma pop
void fn_80013EAC(s32 screen, s32 count, s32 arg2) {
    /* Set up the lap readout on a screen's RaceOverlay: get its "raceovr.val" layout, clamp the count to at least 1, then configure the label text. */
    void *obj = *(void **)((u8 *)sRaceOverlays[screen] + 0x50);
    s32 value = 1;
    if (count >= 1) {
        value = count;
    }
    fn_80013BD0(obj, value, arg2, 0);
}

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_80013EDC(void *arg0, void *name, s32 mode, char *first, char *second, f32 farg0, f32 farg1, f32 farg2) {
    Rec7 L;
    Rec8 R1, R2, R3, R4, R5, R6, R7;
    char b1[20], b2[20], b3[20];
    f32 t;
    u8 *base = lbl_802FCB98;
    s32 n = 0;
    void *obj = *(void **)((u8 *)arg0 + 0x50);
    Rec7 *p = (Rec7 *)VC(5, 0x70);
    if (p) {
        L.a = p->a;
        *(s32 *)&L.x = *(s32 *)&p->x;
        *(s32 *)&L.y = *(s32 *)&p->y;
        L.d = p->d;
        L.e = p->e;
        L.f = p->f;
        L.g = p->g;
    } else {
        fn_802E317C(base + 0x80);
        L.x = lbl_80560378;
        L.y = lbl_8056037C;
        L.e = lbl_80560380;
        L.f = lbl_80560384;
        L.d = 1;
        L.g = -1;
    }
    t = fn_80013D60(farg0);
    L.x = L.x + t * ((lbl_80560388 + (L.x + L.e) + fn_80011EB0(*(s32 *)((u8 *)lbl_8055D350 + 0x1C))) - L.x);
    n = 0;
    if (*(u8 *)((u8 *)lbl_8055D350 + 1) != 0) {
        if (mode != 0) {
            Rec8 *q;
            obj = *(void **)((u8 *)arg0 + 0x50);
            q = (Rec8 *)VC(3, 0xC0);
            if (q) {
                CP8(R1, q);
                R1.x = L.x;
                R1.y = L.y + L.f * (f32)n;
                ((void (*)(void *))fn_801476C4)(&R1);
            }
            obj = *(void **)((u8 *)arg0 + 0x50);
            q = (Rec8 *)VC(3, 0xD4);
            if (q) {
                CP8(R2, q);
                R2.x = L.x + L.e;
                R2.y = L.y + L.f * (f32)n;
                fn_80130FCC(b1, 20, *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0xC) + 8) - *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x30) + 0x10) + 1);
                fn_80147230(&R2, b1);
            }
        } else {
            Rec8 *q;
            obj = *(void **)((u8 *)arg0 + 0x50);
            q = (Rec8 *)VC(3, 0xE0);
            if (q) {
                CP8(R3, q);
                R3.x = L.x;
                R3.y = L.y + L.f * (f32)n;
                ((void (*)(void *))fn_801476C4)(&R3);
            }
        }
        n = 1;
    }
    if (first != 0 && *first != 0) {
        Rec8 *q;
        obj = *(void **)((u8 *)arg0 + 0x50);
        q = (Rec8 *)VC(3, 0xF4);
        if (q) {
            CP8(R4, q);
            R4.x = L.x;
            R4.y = L.y + L.f * (f32)n;
            ((void (*)(void *))fn_801476C4)(&R4);
        }
        obj = *(void **)((u8 *)arg0 + 0x50);
        q = (Rec8 *)VC(3, 0x104);
        if (q) {
            CP8(R5, q);
            R5.x = L.x + L.e;
            R5.y = L.y + L.f * (f32)n;
            fn_80130978(b2, 20, farg1);
            fn_80147230(&R5, b2);
        }
        n++;
    }
    if (second != 0 && *second != 0) {
        Rec8 *q;
        obj = *(void **)((u8 *)arg0 + 0x50);
        q = (Rec8 *)VC(3, 0x110);
        if (q) {
            CP8(R6, q);
            R6.x = L.x;
            R6.y = L.y + L.f * (f32)n;
            ((void (*)(void *))fn_801476C4)(&R6);
        }
        obj = *(void **)((u8 *)arg0 + 0x50);
        q = (Rec8 *)VC(3, 0x124);
        if (q) {
            CP8(R7, q);
            R7.x = L.x + L.e;
            R7.y = L.y + L.f * (f32)n;
            fn_80130978(b3, 20, farg2);
            fn_80147230(&R7, b3);
        }
    }
}
#pragma pop
extern u8 lbl_80558B80;
extern void *fn_8023512C(void *);
extern void *fn_802CAC28(void *, s32);
extern void fn_801333E8(s32, void *, void *);
extern void *fn_80019C68(s32);
extern s32 fn_800167F4(void);
extern void *fn_80145E70(void *);
#pragma push
#pragma cplusplus on
/* Constructor/initializer for a game object: sets vtable and slot, clears flags,
 * resolves several resource handles from a base string table, stores the object
 * index/state, registers it, picks a mode-specific handle, then runs vfunc v5. */
extern "C" void *fn_80014524(void *object, s32 index) {
    class Obj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); };
    u8 *self = (u8 *)object;
    u8 *strBase = lbl_802FCB98;
    *(void **)self = lbl_802FCE18;
    lbl_803577E0[index] = object;
    self[8] = 0;
    *(void **)(self + 0x34) = fn_8023512C(strBase + 0x130);
    *(void **)(self + 0x38) = fn_8023512C(strBase + 0x140);
    *(void **)(self + 0x3C) = fn_8023512C(strBase + 0x14C);
    *(void **)(self + 0x40) = fn_8023512C(strBase + 0x158);
    *(void **)(self + 0x44) = fn_802CAC28(strBase + 0x168, 0);
    *(s32 *)(self + 4) = index;
    self[0x4C] = 0;
    fn_801333E8(5, &lbl_80558B80, self + 0x4C);
    *(void **)(self + 0x48) = fn_80019C68(index);
    if (fn_800167F4() == 1)
        *(void **)(self + 0x50) = fn_80145E70(strBase + 0x178);
    else
        *(void **)(self + 0x50) = fn_80145E70(strBase + 0x184);
    ((Obj *)self)->v5();
    return object;
}
#pragma pop

#pragma scheduling on
/* Reset an object's state fields to defaults: a count of 6, an inactive
 * distance of -1000.0, two zero flags and two unit scale factors.
 * Volatile stores preserve the required initialization order. */
void fn_80014638(void *arg0) {
    f32 unit = lbl_80560368;
    s32 zero = 0;
    f32 inactive = lbl_80560398;
    s32 initial = 6;
    volatile u8 *dst = (volatile u8 *)arg0;
    *(s32 volatile *)(dst + 0x14) = initial;
    *(f32 volatile *)(dst + 0x1C) = inactive;
    *(u8 volatile *)(dst + 0x20) = zero;
    *(f32 volatile *)(dst + 0x2C) = unit;
    *(f32 volatile *)(dst + 0x28) = unit;
    *(s32 volatile *)(dst + 0x24) = zero;
}
#pragma scheduling reset
extern u8 lbl_802FCE18[];
extern void fn_8001A04C(void *);
extern void fn_802CAC54(s32);
extern void fn_80235380(void *);
extern void fn_80128668(void *);
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void *fn_80014664(void *object, s32 deleting) {
    /* Destructor/cleanup for the object with vtable lbl_802FCE18. */
    class Obj {
    public:
        virtual void v0(int);
    };
    void *child;
    if (object != 0) {
        *(void **)object = lbl_802FCE18;
        lbl_803577E0[*(s32 *)((u8 *)object + 4)] = 0;
        child = *(void **)((u8 *)object + 0x50);
        if (child != 0) {
            ((Obj *)child)->v0(1);
        }
        fn_8001A04C(*(void **)((u8 *)object + 0x48));
        *(void **)((u8 *)object + 0x48) = 0;
        fn_802CAC54(*(s32 *)((u8 *)object + 0x44));
        *(s32 *)((u8 *)object + 0x44) = -2;
        fn_80235380(*(void **)((u8 *)object + 0x40));
        *(void **)((u8 *)object + 0x40) = 0;
        fn_80235380(*(void **)((u8 *)object + 0x3C));
        *(void **)((u8 *)object + 0x3C) = 0;
        fn_80235380(*(void **)((u8 *)object + 0x34));
        *(void **)((u8 *)object + 0x34) = 0;
        fn_80235380(*(void **)((u8 *)object + 0x38));
        *(void **)((u8 *)object + 0x38) = 0;
        if (deleting > 0) fn_80128668(object);
    }
    return object;
}
#pragma pop

extern int __cntlzw(unsigned int);
void fn_80014750(void *arg0) {
    void *gameManager;
    void *gameState;
    void *padInput;
    f32 stateValue;
    s32 inRange;
    s32 buttonPressed;

    /* Triggers transition 0x17 when flag set and timeout elapsed, or when state value is in range and button 0x20 pressed. */
    if (*(u8 *)((u8 *)arg0 + 8)) {
        gameManager = lbl_8055D350;
        gameState = *(void **)((u8 *)gameManager + 0xC);
        if (*(f32 *)((u8 *)gameManager + 0x10) - *(f32 *)((u8 *)gameState + 0xC) <
            lbl_80562068 - lbl_8056039C)
            fn_8000C630(0x17, -1);
    } else {
        gameManager = lbl_8055D350;
        gameState = *(void **)((u8 *)gameManager + 0xC);
        stateValue = *(f32 *)((u8 *)gameState + 0x10);
        inRange = 0;
        if (stateValue > lbl_8056039C) {
            if (stateValue < lbl_805603A0)
                goto set_result;
        }
        if (stateValue > lbl_805603A4) {
        set_result:
            inRange = 1;
        }
        padInput = *(void **)((u8 *)gameManager + 0x2C);
        buttonPressed = (u32)__cntlzw(*(u32 *)((u8 *)padInput + 0x2C0) & 0x20) >> 5;
        inRange = inRange && buttonPressed;
        if (inRange != 0)
            fn_8000C630(0x17, -1);
    }
}

/* Seed the smoothed value at +0x10 of `state` from the game manager's target
 * value (gameManager +0x2C -> +0x4C), as used by fn_80014820. */
void fn_8001480C(void *state) {
 *(f32 *)((u8 *)state+0x10)=*(f32 *)((u8 *)*(void **)((u8 *)lbl_8055D350+0x2C)+0x4C);
}

#pragma dont_inline on
extern float __fabsf(float);
extern double __fabs(double);
#pragma scheduling invalid_target
void fn_80014820(void *arg0) {
    void *data;
    f32 current;
    f32 divisor;
    f32 value34;
    f32 scale;
    f32 factor;
    f32 target;
    f32 delta;
    f32 amount;
    f32 cap;
    data = lbl_8055D350;
    current = *(f32 *)((u8 *)arg0 + 0x10);
    data = *(void **)((u8 *)data + 0x2C);
    scale = lbl_805603A8;
    divisor = lbl_805603A0;
    value34 = *(f32 *)((u8 *)data + 0x34);
    factor = lbl_80560368;
    *(f32 *)((u8 *)arg0 + 0xC) = value34;
    data = *(void **)((u8 *)lbl_8055D350 + 0x2C);
    target = *(f32 *)((u8 *)data + 0x4C);
    delta = current - target;
    amount = scale * ((f32)__fabs((f64)delta) / divisor);
    if (factor < amount) {
        factor = amount;
    } else {
        factor = factor;
    }
    cap = lbl_805603AC;
    if (factor > cap) {
        factor = cap;
    } else {
        factor = factor;
    }
    *(f32 *)((u8 *)arg0 + 0x10) =
        *(f32 *)((u8 *)arg0 + 0x10) +
        factor * (*(f32 *)((u8 *)data + 0x4C) -
                  *(f32 *)((u8 *)arg0 + 0x10));
}

extern char *strcpy(char *, const char *);
extern u8 lbl_80558B88, lbl_80558B90, lbl_80558B98;
extern f32 lbl_805603B0;
#pragma processor 750
#pragma scheduling invalid_target
void fn_800148A0(void *arg0) {
    char name[0x40];
    char first[0x40];
    char second[0x40];
    void *info;
    void *other;
    f32 value1;
    f32 value2;
    u8 *base;
    s32 mode;
    u8 *ap = (u8 *)arg0;
    value1 = lbl_80560360;
    value2 = value1;
    base = lbl_802FCB98;
    mode = 1;
    first[0] = 0;
    second[0] = 0;
    if (*(s32 *)((u8 *)lbl_8055D350 + 4) != 1) {
        strcpy(name, (char *)base + 0x194);
        info = *(void **)((u8 *)lbl_8055D350 + 0x30);
        if (*(f32 *)((u8 *)info + 0x18) > lbl_805603B0) {
            strcpy(first, (char *)&lbl_80558B88);
            info = *(void **)((u8 *)lbl_8055D350 + 0x30);
            value1 = *(f32 *)((u8 *)info + 0x18);
        }
    }
    info = *(void **)((u8 *)lbl_8055D350 + 0x30);
    if (*(f32 *)((u8 *)info + 0x1C) > lbl_805603B0 &&
        (*(s32 *)((u8 *)lbl_8055D350 + 4) != 1 ||
         *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0xC) + 8) > 1)) {
        strcpy(second, (char *)&lbl_80558B90);
        info = *(void **)((u8 *)lbl_8055D350 + 0x30);
        value2 = *(f32 *)((u8 *)info + 0x1C);
    }
    if (*(s32 *)((u8 *)info + 0x24) == 3) {
        if (*(s32 *)((u8 *)lbl_8055D350 + 4) != 1) {
            strcpy(name, (char *)base + 0x1A0);
        } else {
            strcpy(name, (char *)base + 0x1AC);
            strcpy(first, (char *)base + 0x1B8);
            info = *(void **)((u8 *)lbl_8055D350 + 0x30);
            value1 = *(f32 *)((u8 *)info + 0x18);
        }
    } else if (*(s32 *)((u8 *)lbl_8055D350 + 4) == 1) {
        strcpy(name, (char *)&lbl_80558B98);
    } else {
        other = *(void **)((u8 *)lbl_8055D350 + 0xC);
        if (*(s32 *)((u8 *)info + 0x10) == *(s32 *)((u8 *)other + 8) ||
            *(s32 *)other >= *(s32 *)((u8 *)other + 8)) {
            strcpy(name, (char *)base + 0x1C8);
            mode = 0;
        }
    }
    if (((s32 (*)(void *))fn_80014ADC)(arg0) != 0) {
        info = *(void **)((u8 *)lbl_8055D350 + 0x30);
        if (*(s32 *)((u8 *)info + 0x24) == 3)
            value1 = *(f32 *)((u8 *)info + 0x1C);
        else
            value1 = *(f32 *)((u8 *)info + 0x14);
        strcpy(first, (char *)base + 0x1D4);
    }
    ((void (*)(void *, void *, s32, void *, void *, f32, f32, f32))fn_80013EDC)(
        arg0, name, mode, first, second, *(f32 *)(ap + 0x2C), value1, value2);
}
void fn_80014A98(void *obj) {
    /* Build a "TIMED LAP" display entry using the current lap/sector value. */
    void *info;
    f32 value;
    info = *(void **)((u8 *)lbl_8055D350 + 0x30);
    if (*(s32 *)((u8 *)info + 0x24) == 3)
        value = *(f32 *)((u8 *)info + 0x1C);
    else
        value = *(f32 *)((u8 *)info + 0x14);
    ((void (*)(void *, void *, s32, void *, void *, f32, f32, f32))fn_80013EDC)(
        obj, lbl_802FCD44, 0, lbl_802FCD78, &lbl_80558BA0,
        *(f32 *)((u8 *)obj + 0x2C), value, lbl_80560360);
}

/* Reverse-direction condition check for the timer/progress display: this build never runs in reverse, so it always reports false (0). */
s32 fn_80014ADC(void) { return 0; }

s32 fn_80014AE4(void) {
    register s32 var_r6 = 0;
    register s32 var_r7 = 0;
    register s32 var_r8 = 1;
    register s32 var_r9 = 1;
    void *temp_r11;
    if (*(s32 *)((u8 *)lbl_8055D350 + 4) == 1 && *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x30) + 0x10) > 0) {
        var_r6 = 1;
    }
    temp_r11 = *(void **)((u8 *)lbl_8055D350 + 0x30);
    var_r7 = 0;
    var_r8 = 1;
    var_r9 = 1;
    if (!(*(f32 *)((u8 *)temp_r11 + 0x1C) > lbl_80560368) && (*(s32 *)((u8 *)temp_r11 + 0x10) != *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0xC) + 8))) {
        var_r9 = 0;
    }
    if ((var_r9 == 0) && (var_r6 == 0)) {
        var_r8 = 0;
    }
    if ((var_r8 != 0) && (*(f32 *)((u8 *)temp_r11 + 0x14) < lbl_805603B4)) {
        var_r7 = 1;
    }
    if ((var_r7 == 0) && (*(s32 *)((u8 *)temp_r11 + 0x10) <= *(s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0xC) + 8))) {
        return 0;
    }
    return 1;
}

extern void fn_80013C98(f32 *);
extern void fn_80013CFC(f32 *);
extern void fn_800148A0(void *);
extern void fn_80014A98(void *);
extern s32 fn_80014ADC(void);
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
/* Updates a UI/progress object's fade state (+0x24) and value (+0x2C) based on reverse/active conditions (fn_80014ADC/fn_80014AE4), ramping toward lbl_80560360 (0.0f) or lbl_80560368 (1.0f). */
void fn_80014B9C(void *arg0) {
    struct Obj {
        u8 pad0[0x24];
        s32 state;
        u8 pad28[4];
        f32 value;
    };
    struct Obj *obj = (struct Obj *)arg0;
    s32 state, reverse, result;

    reverse = fn_80014ADC();
    result = ((s32 (*)(void *))fn_80014AE4)(obj);
    state = obj->state;
    if (state == 0) {
        if (reverse != 0 || result != 0) {
            s32 newState;
            fn_80013CFC(&obj->value);
            if (reverse != 0) fn_80014A98(obj);
            else fn_800148A0(obj);
            if (lbl_80560360 == obj->value) {
                newState = 1;
                if (reverse != 0) newState = 2;
                obj->state = newState;
            }
        } else {
            obj->value = lbl_80560368;
        }
    } else if (state == 2) {
        if (reverse != 0) {
            if (obj->value > lbl_80560360) fn_80013CFC(&obj->value);
            fn_80014A98(obj);
        } else {
            fn_80013C98(&obj->value);
            fn_80014A98(obj);
            if (lbl_80560368 == obj->value) obj->state = 0;
        }
    } else {
        if (result != 0) {
            if (obj->value > lbl_80560360) fn_80013CFC(&obj->value);
            fn_800148A0(obj);
        } else {
            fn_80013C98(&obj->value);
            fn_800148A0(obj);
            if (lbl_80560368 == obj->value) obj->state = 0;
        }
    }
}
#pragma pop

/* The per-session state block (lbl_8034EE84) that lbl_8055D350 points at;
 * what the race HUD reads every frame. */
typedef struct RaceSession {
    u8 pad0[0x08];
    void *app;       /* 0x08: app object; the word at its +4 holds app flags */
    void *rules;     /* 0x0C: race rules; +0x08 is the lap count */
    f32 speed;       /* 0x10: this screen's speed */
    s32 playerCount; /* 0x14: racers taking part */
    s32 mode;        /* 0x18: race mode (1 = single player) */
    s32 playerIndex; /* 0x1C: screen/player whose HUD is being drawn */
    u32 hudMask;     /* 0x20: which readouts to refresh this frame */
    s32 racerIndex;  /* 0x24: this player's entry in the racer table */
    s32 field28;     /* 0x28: racer entry the standings list highlights */
    void *truck;     /* 0x2C: the player's truck; +0x28C.. position, +0x2C0 buttons */
    void *standing;  /* 0x30: the player's standing; +0x04 place, +0x10 lap */
} RaceSession;
#define gSession ((RaceSession *)lbl_8055D350)

/* Bits of the HUD mask at state+0x20; each block of fn_80014D04 draws one. */
#define HUD_LAP       0x0001 /* "lap <n> / <total>" */
#define HUD_PLACE     0x0002 /* place number and its ordinal suffix */
#define HUD_SPEED     0x0008 /* speed needle and the boost gauge */
#define HUD_DAMAGE    0x0010 /* off-screen marker for this player's damage */
#define HUD_INCIDENTS 0x0020 /* markers for the four arena incidents */
#define HUD_LAPINFO   0x0040 /* the lap-info line (fn_80014B9C) */
#define HUD_LAPWARN   0x0200 /* lap warning (fn_800151DC) */
#define HUD_RESETWARN 0x0400 /* "wrong way" / reset warning (fn_800151DC) */
#define HUD_TRACKMAP  0x1000 /* this player's mark on the track map */
#define HUD_STANDINGS 0x2000 /* the standings list (fn_800154B8) */
#define HUD_COUNTS    0x4000 /* the two counters drawn over the map */

/* One screen's race HUD object (vtable lbl_802FCE18, see fn_80014524). */
typedef struct RaceOverlay {
    void *vtable;      /* 0x00: lbl_802FCE18 */
    s32 screen;        /* 0x04: index into sRaceOverlays */
    u8 pad08[0x08];
    f32 speed;         /* 0x10: smoothed speed, kept up to date by fn_80014820 */
    u8 pad14[0x04];
    s32 racerIndex;    /* 0x18: racer the readouts were last built for */
    u8 pad1C[0x2C];
    s32 mapFrame;      /* 0x48: track-map marker object, 0 when there is none */
    void *messageSlot; /* 0x4C: written by the message hook fn_801333E8 registers */
    void *layout;      /* 0x50: the "raceovr.val" layout the readouts live in */
} RaceOverlay;

/* Element names of the "raceovr.val" layout, in the string table at lbl_802FCB98. */
#define NAME_PLACE_NUMBER 0x1F0 /* "place_numerator" */
#define NAME_PLACE_SUFFIX 0x200 /* "place_suffix" */
#define NAME_TRACK_MAP    0x210 /* "track_map" */
#define FMT_INT           (&lbl_80558BA4)  /* "%d" */
#define FMT_STR           (&lbl_80558BA8)  /* "%s" */
#define MSG_DAMAGE        (&lbl_80558BAC)  /* "DAMAGE": off-screen marker name */
#define MSG_KILLED        (&lbl_80558BB4)  /* "KILLED": likewise, for a wrecked racer */

extern s32 fn_8000D75C(void);
extern void fn_8000FBE4(void);
extern void fn_80010F38(void *, s32, s32, s32, f32);
extern void fn_800111A4(void *, s32, s32, s32, s32, f32);
extern void fn_80014820(void *);
extern void fn_80015364(void *);
extern void fn_8001A1F4(s32, f32, f32, f32, f32);
extern void fn_8001DF84(s32);
extern s32 fn_80130FE0(s32);
extern s32 fn_80144F2C(void);
extern void *fn_801B83A0(void);
extern void fn_801D490C(void);
extern void fn_801DF93C(s32);
extern s32 fn_801E7E34(void);
extern s32 fn_801E866C(s32);
extern void fn_801E87A8(void);
extern s32 fn_801E89C8(s32);
extern s32 fn_801E89EC(void);
extern s32 fn_8026B0C0(s32);
extern s32 fn_8027AA48(void *, f32, f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
#pragma opt_propagation off
/* Per-frame update of one screen's race HUD (vtable lbl_802FCE18, slot 0x24).
 * While the session's HUD mask (state+0x20) is clear it does nothing; otherwise
 * it re-arms itself when the player's racer changes, and then refreshes exactly
 * the readouts the mask asks for: the place number and its "st/nd/rd/th" suffix,
 * the "lap n / total" line, the speed needle and boost gauge, off-screen DAMAGE
 * markers for this player and for the four arena incidents (KILLED when the
 * incident is a wreck), the lap-info line, the lap/reset warnings, the standings
 * list, the counters over the map and this player's mark on the track map.
 * A screen whose entry in the 4-slot pool at lbl_80499E60 is in use shows the
 * arena-event master's own state instead of the race readouts. */
extern "C" void fn_80014D04(RaceOverlay *overlay) {
    /* The overlay's own slot 0xC, which this class leaves empty. */
    class Overlay {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void onRacerChanged();
    };
    /* The arena-event master fn_801B83A0 hands out; slot 0xA8 is its "show me"
     * question, answered here instead of drawing the race readouts. */
    class ArenaMaster {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual s32 v20();
    };
    class Layout {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void *findElement(void *name); /* 0xC: stricmp over the element list */
    };
    u8 *base = lbl_802FCB98;
    s32 skipGauge;
    f32 mapX, mapY;
    void *obj;
    if (gSession->hudMask != 0) {
        if (gSession->racerIndex != overlay->racerIndex) {
            ((Overlay *)overlay)->onRacerChanged();
        }
        overlay->racerIndex = gSession->racerIndex;
        if (fn_8026B0C0(gSession->playerIndex) != 0) {
            obj = fn_801B83A0();
            if (((ArenaMaster *)obj)->v20() != 0) {
                fn_801DF93C(gSession->playerIndex);
            }
        } else {
            s32 posX;
            RaceSession *session;
            void *marker;
            s32 posY, posZ;
            /* The start countdown is drawn once per frame, on the first screen. */
            if (gSession->playerIndex == 0) {
                fn_8000FBE4();
            }
            session = (RaceSession *)lbl_8055D350;
            /* A player whose frame entry says he is out of the running keeps the
             * speed gauge hidden, whatever the mask asks for. */
            skipGauge = 0;
            if (session->racerIndex == fn_801E866C(session->playerIndex)) {
                if (fn_801E89C8(session->playerIndex) != 0) {
                    skipGauge = 1;
                }
            }
            fn_801E87A8();
            if (skipGauge == 0 && (gSession->hudMask & HUD_SPEED)) {
                if (fn_8000D75C() == 0) {
                    fn_80014820(overlay);
                }
                if (*(u32 *)((u8 *)gSession->app + 0x4) & 0x80000) {
                    fn_80015F30(overlay);
                    fn_8001DF84(gSession->racerIndex);
                }
            }
            if (gSession->hudMask & HUD_PLACE) {
                fn_801473F8(overlay->layout, base + NAME_PLACE_NUMBER, FMT_INT,
                            *(s32 *)((u8 *)gSession->standing + 0x4));
                fn_801473F8(overlay->layout, base + NAME_PLACE_SUFFIX, FMT_STR,
                            fn_80130FE0(*(s32 *)((u8 *)gSession->standing + 0x4)));
            }
            if (gSession->hudMask & HUD_LAP) {
                s32 lap = 1;
                s32 totalLaps;
                s32 curLap;
                totalLaps = *(s32 *)((u8 *)gSession->rules + 0x8);
                curLap = *(s32 *)((u8 *)gSession->standing + 0x10);
                if (curLap > 1) lap = curLap;
                fn_80013BD0(overlay->layout, lap < totalLaps ? lap : totalLaps, totalLaps, 1);
            }
            if (gSession->hudMask & HUD_DAMAGE) {
                /* The truck's position is a 0..1 pair; 1.0 - it, times 100, is the
                 * distance of the marker pointing back at it. */
                marker = MSG_DAMAGE;
                obj = gSession->truck;
                posX = (s32)((lbl_80560368 - *(f32 *)((u8 *)obj + 0x28C)) * lbl_805603B8);
                posY = (s32)((lbl_80560368 - *(f32 *)((u8 *)obj + 0x290)) * lbl_805603B8);
                posZ = (s32)((lbl_80560368 - *(f32 *)((u8 *)obj + 0x294)) * lbl_805603B8);
                if (((s32 (*)(void))fn_8027AA48)() != 0) {
                    fn_800111A4(marker, posX, posY, posZ, 7, lbl_80560368);
                } else {
                    fn_80010F38(marker, posX, posY, 6, lbl_80560368);
                }
            }
            if (gSession->hudMask & HUD_INCIDENTS) {
                f32 scale, one;
                u8 *incident;
                s32 i;
                /* The four incidents this player's frame entry keeps at +0x78. */
                s32 entry = fn_801E7E34();
                entry += gSession->playerIndex * 0xE0;
                incident = (u8 *)(entry + 0x78);
                i = 0;
                one = lbl_80560368;
                scale = lbl_805603B8;
                do {
                    if (*(s32 *)incident >= 0) {
                        s32 kind = *(s32 *)(incident + 0x14);
                        if (kind > 9 && kind < 0xD) {
                            fn_80010F38(MSG_KILLED, (s32)(scale * (one - *(f32 *)(incident + 8))),
                                        (s32)(scale * (one - *(f32 *)(incident + 0xC))), 8, one);
                        } else {
                            fn_80010F38(MSG_DAMAGE, (s32)(scale * (one - *(f32 *)(incident + 8))),
                                        (s32)(scale * (one - *(f32 *)(incident + 0xC))), 8, one);
                        }
                    }
                    i += 1;
                    incident += 0x18;
                } while (i < 4);
            }
            if ((gSession->hudMask & HUD_LAPINFO) && gSession->mode < 3) {
                fn_80014B9C(overlay);
            }
            {
                /* The speed warning of fn_80016214 only runs while no lap or reset
                 * warning is on screen. */
                s32 warning = 0;
                if ((gSession->hudMask & (HUD_LAPWARN | HUD_RESETWARN)) && fn_800151DC(overlay) != 0) {
                    warning = 1;
                }
                if (fn_801E89EC() == 1 && warning == 0) {
                    ((s32 (*)(void *))fn_80016214)(overlay);
                }
            }
            if ((gSession->hudMask & HUD_STANDINGS) && gSession->mode == 1) {
                ((void (*)(void *))fn_800154B8)(overlay);
            }
            if ((gSession->hudMask & HUD_COUNTS) && fn_80144F2C() != 0) {
                fn_80015658(overlay);
            }
            if (gSession->hudMask & HUD_TRACKMAP) {
                if (overlay->mapFrame != 0) {
                    /* Place the map marker where the "track_map" element sits. */
                    obj = overlay->layout;
                    obj = ((Layout *)obj)->findElement(base + NAME_TRACK_MAP);
                    if (obj != 0) {
                        f32 *pOutX = &mapX;
                        f32 *pOutY = &mapY;
                        s32 mode = *(s32 *)((u8 *)obj + 0xC);
                        f32 elemX = *(f32 *)((u8 *)obj + 4);
                        f32 elemY = *(f32 *)((u8 *)obj + 8);
                        fn_80148134(pOutX, pOutY, mode, elemX, elemY);
                        fn_8001A1F4(overlay->mapFrame, mapX, mapY,
                                    *(f32 *)((u8 *)obj + 0x10), *(f32 *)((u8 *)obj + 0x14));
                    }
                } else if (gSession->playerIndex == 0) {
                    fn_80015364(overlay);
                }
            }
            fn_801D490C();
        }
    }
}
#pragma pop

s32 fn_800151D4(void) { return 1; }

#pragma push
#pragma cplusplus on
extern "C" s32 fn_800151DC(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v3(void *);
    };
    s32 result;
    void *manager = lbl_8055D350;
    void *obj;

    /* Check manager/state flags and invoke object handlers (reset/wrong-way) when conditions match. */
    if ((*(u32 *)((u8 *)manager + 0x20) & 0x400) &&
        (*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x2C) + 0x2C0) & 0x10)) {
        obj = *(void **)((u8 *)arg0 + 0x50);
        ((Obj *)obj)->v3(lbl_80558BBC);
        fn_801476C4();
    }

    manager = lbl_8055D350;
    result = 0;
    if ((*(u32 *)((u8 *)*(void **)((u8 *)manager + 0x30)) & 4) && (*(u32 *)((u8 *)manager + 0x20) & 0x200)) result = 1;
    if (result) {
        obj = *(void **)((u8 *)arg0 + 0x50);
        ((Obj *)obj)->v3(lbl_802FCDB4);
        fn_801476C4();
    }

    return result;
}
#pragma pop
extern f32 fn_80235EF0(void *, s32);
extern f32 fn_80235F64(void *, s32);
extern void fn_80010E94(void *, s32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_8001529C(void *arg0, u32 arg1, f32 a, f32 b, f32 c, f32 d, f32 e) {
    /* Position a UI element (arg0+0x38) horizontally by interpolating a between
     * b and b+d with half-width centering, and place it above or below c based on
     * arg1's sign bit, then apply the transform via fn_80010E94. */
    f32 width, height, half, left, y, bottom, x;
    s32 negative;
    s32 positive = (arg1 >> 31) ^ 1;
    width = fn_80235EF0(*(void **)((u8 *)arg0 + 0x38), 0);
    height = fn_80235F64(*(void **)((u8 *)arg0 + 0x38), 0);
    negative = positive == 0;
    half = width * lbl_805603BC;
    left = b - half;
    bottom = c - e;
    x = left + a * (((b + d) - half) - left);
    y = c + height;
    fn_80010E94(*(void **)((u8 *)arg0 + 0x38), negative,
        x, positive ? y : bottom, lbl_80560360, lbl_80560360);
}

#pragma dont_inline on
#pragma use_lmw_stmw off
extern void fn_80010B80(s32, f32, f32, f32, f32);
extern f32 fn_80011E60(void);
extern f32 fn_8013672C(void);
extern void *fn_801E7E3C(void);
extern s32 fn_801EA994();
extern void *fn_801EA9A0(s32);
extern f32 lbl_805603C0, lbl_805603C4, lbl_805603C8;
extern f64 lbl_80560390;
#pragma dont_inline on
#pragma use_lmw_stmw off
/* Draws per-participant progress bars in the results/progress UI. */
void fn_80015364(void *arg0) {
    f32 selected;
    f32 delta;
    f32 total;
    s32 frameCount;
    s32 activeCount;
    s32 index;
    s32 value;
    s32 resultIndex;
    void *entry;
    void *record;
    f32 amount;
    if (*(s32 *)((u8 *)lbl_8055D350 + 0x18) == 1) {
        selected = lbl_805603C0;
    } else {
        selected = fn_80011E60();
    }
    activeCount = 0;
    fn_80010B80(0xC80000C8, lbl_805603C4, selected, lbl_805603C8, lbl_805603B4);
    delta = fn_8013672C();
    frameCount = *(s32 *)((u8 *)fn_801E7E3C() + 8);
    index = 0;
    total = delta * (f32)frameCount;
    while (index < fn_801EA994()) {
        record = fn_801EA9A0(index);
        entry = *(void **)((u8 *)record + 8);
        amount = lbl_80560360;
        record = fn_801EA9A0(index);
        value = *(s32 *)((u8 *)record + 0x1C);
        if (value > 0) {
            amount = (*(f32 *)((u8 *)entry + 0x2C8) +
                      (f32)(value - 1) * delta) / total;
        }
        record = fn_801EA9A0(index);
        if (*(u8 *)record != 0) {
            resultIndex = activeCount;
            activeCount++;
        } else {
            resultIndex = -1;
        }
        fn_8001529C(arg0, (u32)resultIndex, amount, lbl_805603C4,
                    selected, lbl_805603C8, lbl_805603B4);
        index++;
    }
}
extern s32 fn_801EA994(void);
extern s32 fn_801EA9B0(s32);
extern void fn_8000FF88(s32, s32, void *, s32, s32, f32, f32, f32, ...);
extern f32 lbl_80560368, lbl_80560384, lbl_805603CC, lbl_805603D0;
extern char lbl_80558BC4;
void fn_800154B8(void) {
    /* Fix note: final loop is a pre-tested for loop (target branches to its condition first). */
    s32 current;
    s32 *base;
    register s32 first, left, right, start, i, limit;
    register f32 y, step;
    current = fn_801EA994();
    base = *(s32 **)((char *)lbl_8055D350 + 0x30);
    left = 2;
    right = 2;
    first = base[1];
    if (first <= 2) {
        left = first - 1;
        right = 2 - left;
        right = right + 2;
    } else if (first > current - 2) {
        left = first - (current - 2);
        left = left + 2;
        right = current - first;
    }
    y = lbl_805603CC;
    start = first - (left & ~(left >> 31));
    right = right & ~(right >> 31);
    i = 1;
    if (start >= 1)
        i = start;
    step = lbl_80560384;
    for (; i < (limit = *(s32 *)(*(u8 **)((u8 *)lbl_8055D350 + 0x30) + 4)); ++i) {
        fn_8000FF88(-1, 9, &lbl_80558BC4, i, fn_801EA9B0(i - 1) + 0x48, lbl_80560368, lbl_805603D0, y);
        y -= step;
    }
    fn_8000FF88(-0x100, 9, &lbl_80558BC4, limit,
                *(s32 *)((u8 *)lbl_8055D350 + 0x28) + 0x48,
                lbl_80560368, lbl_805603D0, y);
    step = lbl_80560384;
    y -= step;
    for (i = *(s32 *)(*(u8 **)((u8 *)lbl_8055D350 + 0x30) + 4) + 1;
         i <= *(s32 *)(*(u8 **)((u8 *)lbl_8055D350 + 0x30) + 4) + right &&
         i <= fn_801EA994(); ++i) {
        fn_8000FF88(-1, 9, &lbl_80558BC4, i, fn_801EA9B0(i - 1) + 0x48, lbl_80560368, lbl_805603D0, y);
        y -= step;
    }
}

extern s32 fn_80144F34(void *, s32, void *);
extern f32 fn_80011DEC(void *);
extern f32 fn_80011DC0(void *);
extern void fn_802354A0(void *, s32, s32, f32, f32, f32, f32, f32);
extern f32 lbl_805603D4, lbl_805603D8, lbl_805603DC, lbl_805603E0, lbl_805603E4;
extern f32 lbl_80560360, lbl_805603A0;
#pragma push
#pragma use_lmw_stmw off
#pragma optimize_for_size off
/* HUD piece drawn while the race state (lbl_8055D350) has flag 0x4000 set: a 60x45
 * sprite (entry 3 of the sprite group at arg0+0x3C, drawn by fn_802354A0) placed at
 * the current entry's position -- fn_80011DEC/fn_80011DC0 of the float table indexed
 * by the entry number at state+0x1C, moved back by 60 (lbl_805603D4) and 314
 * (lbl_805603D8). Over it go the two values fn_80144F34 reports for rows 0 and 1 of
 * the record picked by the id at state+0x24, drawn as "%d" text (0.94 scale) 22.5
 * pixels apart; fn_80144E38 also writes a range-check flag for each row into
 * row0Ok/row1Ok, which nothing here reads. */
void fn_80015658(void *arg0) {
    char row0Ok;
    char row1Ok;
    f32 x;
    f32 y;
    s32 count0;
    s32 count1;
    count0 = fn_80144F34(*(void **)((u8 *)lbl_8055D350 + 0x24), 0, &row0Ok);
    count1 = fn_80144F34(*(void **)((u8 *)lbl_8055D350 + 0x24), 1, &row1Ok);
    x = fn_80011DEC(*(void **)((u8 *)lbl_8055D350 + 0x1C)) - lbl_805603D4;
    y = fn_80011DC0(*(void **)((u8 *)lbl_8055D350 + 0x1C)) - lbl_805603D8;
    fn_802354A0(*(void **)((u8 *)arg0 + 0x3C), 3, -1, x, y, lbl_80560360, lbl_805603D4, lbl_805603DC);
    ((void (*)(s32, s32, void *, s32, ...))fn_8000FF88)(-0x100, 0xA, &lbl_80558BA4, count0, lbl_805603E0, x - lbl_805603A0, y);
    ((void (*)(s32, s32, void *, s32, ...))fn_8000FF88)(-0x100, 0xA, &lbl_80558BA4, count1, lbl_805603E0, x - lbl_805603A0, y - lbl_805603E4);
}
#pragma pop
void fn_80015A20();
#pragma push
#pragma use_lmw_stmw off
void fn_80015770(void *arg0, f64 x, f64 y, f32 a, f32 b, f32 c) {
    f32 vec[4];
    f32 mtx[12];
    f32 verts[4][3];
    f32 *p;
    f32 *q;
    s32 i;
    f64 z;
    f32 ox, oy, oz;
    f32 k1, k2;
    vec[0] = lbl_80560360;
    vec[1] = lbl_80560360;
    vec[2] = c;
    fn_80015A20(mtx, vec);
    z = lbl_80560360;
    mtx[9] = x;
    mtx[10] = y;
    mtx[11] = z;
    ox = x;
    oy = y;
    oz = z;
    k1 = lbl_805603BC;
    k2 = lbl_805603E8;
    p = verts[0];
    q = p;
    for (i = 0; i < 4; i++) {
        p[1] = (i % 2 != 0) ? b * k1 : -b * k1;
        p[0] = (i < 2) ? a - k2 : lbl_805603EC;
        p[2] = z;
        if (p == q) {
            f32 vx = p[0], vy = p[1], vz = p[2];
            p[0] = vx * mtx[0] + vy * mtx[3] + vz * mtx[6];
            p[1] = vx * mtx[1] + vy * mtx[4] + vz * mtx[7];
            p[2] = vx * mtx[2] + vy * mtx[5] + vz * mtx[8];
        } else {
            q[0] = p[0] * mtx[0] + p[1] * mtx[3] + p[2] * mtx[6];
            q[1] = q[0] * mtx[1] + p[1] * mtx[4] + p[2] * mtx[7];
            q[2] = q[1] * mtx[2] + p[1] * mtx[5] + p[2] * mtx[8];
        }
        q += 3;
        p[0] = p[0] + ox;
        p[1] = p[1] + oy;
        p[2] = p[2] + oz;
        p += 3;
    }
    fn_802C8BD0(*(s32 *)((u8 *)arg0 + 0x44));
    fn_801E4F20(4);
    p = verts[0];
    for (i = 0; i < 4; i++) {
        fn_801E4F3C(-1, i > 1, p[0], p[1], p[2],
                    (i % 2 != 0) ? lbl_805603F0 : lbl_80560368,
                    (i < 2) ? lbl_805603F4 : lbl_80560368);
        p += 3;
    }
    fn_801E4FF4();
    fn_802C8D74();
}
#pragma pop
void fn_80015AA0(void *, f32);
void fn_80015EB0(void *, f32);
#pragma use_lmw_stmw off
#pragma optimize_for_size off
#pragma scheduling on
void fn_80015A20(void *arg0, Vec3_80015A20 *arg1) {
    f32 matrix[9];
    f32 angle0 = arg1->x;
    f32 angle2 = arg1->z;
    fn_80015EB0(arg0, arg1->y);
    fn_80015E30(matrix, angle0);
    fn_80015B20(arg0, matrix, arg0);
    fn_80015AA0(matrix, angle2);
    fn_80015B20(arg0, matrix, arg0);
}
extern void fn_801476C4(void);
extern u8 lbl_80558BBC[];
extern u8 lbl_802FCDB4[];
extern void fn_80015E30(void *, f32);
extern void fn_80015B20(void *, void *, void *);
extern f64 cos(void);
extern f64 sin(f32);
#pragma scheduling invalid_target
void fn_80015AA0(void *arg0, f32 angle) {
    f32 one;
    f32 zero;
    f32 sine;
    f32 cosine = (f32)cos();
    f32 *m;
    sine = (f32)sin(angle);
    zero = lbl_80560360;
    one = lbl_80560368;
    m = (f32 *)arg0;
    m[0] = cosine;
    m[1] = sine;
    m[2] = zero;
    m[3] = -sine;
    m[4] = cosine;
    m[5] = zero;
    m[6] = zero;
    m[7] = zero;
    m[8] = one;
}
#pragma push
#pragma scheduling invalid_target
void fn_80015B20(void *arg0, void *arg1, void *arg2) {
    f32 *out = (f32 *)arg0;
    f32 *a = (f32 *)arg1;
    f32 *b = (f32 *)arg2;

    if ((arg0 == arg1) || (arg0 == arg2)) {
        register f32 temp_f10, temp_f1, temp_f19, temp_f12, temp_f3, temp_f9, temp_f0, temp_f20;
        register f32 temp_f11, temp_f18, temp_f7, temp_f6, temp_f1_2, temp_f0_2, temp_f2;
        register f32 temp_f4, temp_f5, temp_f8;

        temp_f10 = a[1]; temp_f1 = b[3]; temp_f19 = a[4]; temp_f12 = b[4];
        temp_f3 = a[7]; temp_f9 = a[0]; temp_f0 = b[0]; temp_f20 = a[3];
        temp_f11 = b[1]; temp_f18 = a[6]; temp_f7 = b[5]; temp_f6 = b[2];
        temp_f1_2 = a[2]; temp_f0_2 = b[6]; temp_f2 = a[5]; temp_f4 = a[8];
        temp_f5 = b[7]; temp_f8 = b[8];

        out[0] = (temp_f0_2 * temp_f1_2) + ((temp_f0 * temp_f9) + (temp_f1 * temp_f10));
        out[3] = (temp_f0_2 * temp_f2) + ((temp_f0 * temp_f20) + (temp_f1 * temp_f19));
        out[6] = (temp_f0_2 * temp_f4) + ((temp_f0 * temp_f18) + (temp_f1 * temp_f3));
        out[1] = (temp_f5 * temp_f1_2) + ((temp_f11 * temp_f9) + (temp_f12 * temp_f10));
        out[4] = (temp_f5 * temp_f2) + ((temp_f11 * temp_f20) + (temp_f12 * temp_f19));
        out[7] = (temp_f5 * temp_f4) + ((temp_f11 * temp_f18) + (temp_f12 * temp_f3));
        out[2] = (temp_f8 * temp_f1_2) + ((temp_f6 * temp_f9) + (temp_f7 * temp_f10));
        out[5] = (temp_f8 * temp_f2) + ((temp_f6 * temp_f20) + (temp_f7 * temp_f19));
        out[8] = (temp_f8 * temp_f4) + ((temp_f6 * temp_f18) + (temp_f7 * temp_f3));
    } else {
        out[0] = (b[6] * a[2]) + ((b[0] * a[0]) + (b[3] * a[1]));
        out[3] = (b[7] * a[2]) + ((b[1] * a[0]) + (b[4] * a[1]));
        out[6] = (b[8] * a[2]) + ((b[2] * a[0]) + (b[5] * a[1]));
        out[1] = (b[6] * a[5]) + ((b[0] * a[3]) + (b[3] * a[4]));
        out[4] = (b[7] * a[5]) + ((b[1] * a[3]) + (b[4] * a[4]));
        out[7] = (b[8] * a[5]) + ((b[2] * a[3]) + (b[5] * a[4]));
        out[2] = (b[6] * a[8]) + ((b[0] * a[6]) + (b[3] * a[7]));
        out[5] = (b[7] * a[8]) + ((b[1] * a[6]) + (b[3] * a[7]));
        out[8] = (b[8] * a[8]) + ((b[2] * a[6]) + (b[5] * a[7]));
    }
}
#pragma scheduling on
void fn_80015E30(void *arg0, f32 angle) {
    f32 neg;
    f32 zero;
    f32 one;
    f32 sine;
    f32 cosine;
    cosine = (f32)cos();
    sine = (f32)sin(angle);
    zero = lbl_80560360;
    one = lbl_80560368;
#pragma scheduling off
    *(volatile f32 *)((u8 *)arg0 + 4) = zero;
    neg = -sine;
    *(f32 *)((u8 *)arg0 + 0) = one;
    *(f32 *)((u8 *)arg0 + 8) = zero;
    *(f32 *)((u8 *)arg0 + 0xC) = zero;
    *(f32 *)((u8 *)arg0 + 0x10) = cosine;
    *(f32 *)((u8 *)arg0 + 0x14) = sine;
    *(f32 *)((u8 *)arg0 + 0x18) = zero;
    *(f32 *)((u8 *)arg0 + 0x1C) = neg;
    *(f32 *)((u8 *)arg0 + 0x20) = cosine;
}
void fn_80015EB0(void *arg0, f32 angle) {
    f32 c;
    f32 s;
    f32 zero;
    f32 neg;
    f32 *m;
    c = (f32)cos();
    s = (f32)sin(angle);
    zero = lbl_80560360;
    m = (f32 *)arg0;
    m[0] = c;
    neg = -s;
    m[1] = zero;
    m[2] = neg;
    m[3] = zero;
    m[4] = lbl_80560368;
    m[5] = zero;
    m[6] = s;
    m[7] = zero;
    m[8] = c;
}

extern f32 lbl_805603F8,lbl_805603FC,lbl_80560408,lbl_8056040C,lbl_80560410,lbl_80560414;
extern void fn_801478E0(void*,void*,s32,s32);
extern void fn_80147F30(s32,s32,s32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void fn_80148134(f32*,f32*,s32,f32,f32);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma processor 750
#pragma scheduling on
extern "C" void fn_80015F30(void* arg0) {
 struct Desc { s32 a; f32 x,y; s32 d; f32 w,h; s32 g,k; };
 struct Copy { s32 a,x,y,d; f32 w; s32 h,g,k; };
 class Obj { public:
 virtual void v0(); virtual Desc* get(void*); virtual void v2(); virtual Desc* find(void*);
 };
 struct Copy copy;
 f32 x,y;
 f32 value;
 f32 low;
 f32 high;
 f64 period=lbl_80560400;
 u8* base=lbl_802FCB98;
 low=lbl_805603F8;
 high=lbl_805603FC;
 void* mgr=*(void**)((u8*)lbl_8055D350+0x2c);
 f32 speed=*(f32*)((u8*)lbl_8055D350+0x10);
 value=*(f32*)((u8*)mgr+0x2a8);
 s32 positive=(f32)((f64(*)(void*,f32,f64))fn_8002EFB4)(mgr,speed,period)>lbl_805603BC;
 s32 flag=0;
 void* obj;
 struct Desc* desc;
 if(value>lbl_80560408 && positive) flag=1;
 fn_801478E0(*(void**)((u8*)arg0+0x50),base+0x228,*(s32*)((u8*)arg0+0x40),3);
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->find(base+0x234);
 if(desc) {
  if(flag || *(f32*)((u8*)*(void**)((u8*)lbl_8055D350+0x2c)+0x2c4)>lbl_80560360) {
   f32 a=lbl_8056040C*value;
   f32 b;
   if(a<lbl_80560360) b=a-lbl_805603BC; else b=lbl_805603BC+a;
   f32 scale=(high-low)/lbl_8056040C;
   ((void(*)(f32,f32,f32,f32,s32,s32,s32,f32,f32,f32,f32,f32,f32))fn_80147F30)(desc->x,desc->y,desc->w,desc->h,desc->g,(s32)b,*(s32*)((u8*)arg0+0x44),low,scale,lbl_805603BC,lbl_80560360,lbl_80560410,lbl_80560414);
  } else {
   f32 a=lbl_8056040C*value;
   f32 b;
   if(a<lbl_80560360) b=a-lbl_805603BC; else b=lbl_805603BC+a;
   f32 scale=(high-low)/lbl_8056040C;
   ((void(*)(f32,f32,f32,f32,s32,s32,s32,f32,f32,f32,f32,f32,f32))fn_80147F30)(desc->x,desc->y,desc->w,desc->h,desc->g,(s32)b,*(s32*)((u8*)arg0+0x44),low,scale,lbl_80560360,lbl_80560360,lbl_80560414,lbl_80560414);
  }
 }
 fn_801478E0(*(void**)((u8*)arg0+0x50),base+0x240,*(s32*)((u8*)arg0+0x40),0);
 obj=*(void**)((u8*)arg0+0x50);
 desc=((Obj*)obj)->find(base+0x24c);
 if(desc) {
  high=low+value*(high-low);
  fn_80148134(&x,&y,desc->d,desc->x,desc->y);
  fn_80015770(arg0,x,y,desc->w,desc->h,high);
 }
 obj=*(void**)((u8*)arg0+0x50);
 Copy* src=(Copy*)((Obj*)obj)->get(base+0x258);
 if(src) {
 copy.a=src->a; copy.x=src->x; copy.y=src->y; copy.d=src->d;
 copy.w=src->w; copy.h=src->h; copy.g=src->g; copy.k=src->k;
 if(flag) copy.g=0x80FFFF00;
 ((void(*)(void*))fn_801476C4)(&copy);
 }
}
#pragma cplusplus reset
#pragma pop

#pragma push
#pragma scheduling off
#pragma processor 750
s32 fn_80016214(void) {
    f64 scale = lbl_80560400;
    void *manager = lbl_8055D350;
    f32 speed = *(f32 *)((u8 *)manager + 0x10);
    f32 value = (f32)((f64 (*)(void *, f32, f64))fn_8002EFB4)(manager, speed, scale);
    s32 greater = value > lbl_805603BC;
    if (greater != 0 && lbl_8055E520 != 0) {
        fn_80011E04(0);
        fn_80010FDC(lbl_802FCE04, 0xC);
        return 1;
    }
    return 0;
}
#pragma pop
s32 fn_80016288(void) { return 0; }

extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[];
extern u8 lbl_802FCE88[];
// Return the static data block at lbl_802FCE88 used as the AX FX LFO sine-table pointer.
void *__AXFXGetLfoSinTable(void) {
    return lbl_802FCE88;
}
extern f32 fn_8002EFB4(void *, f32, f64);
extern void fn_80011E04(s32);
extern void fn_80010FDC(void *, s32);
extern f64 lbl_80560400;
extern f32 lbl_805603BC;
extern u8 lbl_8055E520;
extern u8 lbl_802FCE04[], lbl_802FCE88[];
