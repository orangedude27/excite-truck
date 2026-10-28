// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <stdarg.h>
extern f32 lbl_80560250, lbl_80560254, lbl_80560258, lbl_8056025C, lbl_80560260, lbl_80560264;
extern s32 lbl_80558AA4;
extern s32 lbl_802FC2A8[];
typedef struct UnkF4F0Style {
    s32 unk_0x00, unk_0x04, unk_0x08, unk_0x0C;
    f32 unk_0x10;
    s32 unk_0x14;
    u32 unk_0x18;
    s32 unk_0x1C;
} UnkF4F0Style;
extern int vsprintf(char *, const char *, va_list);
extern unsigned int strlen(const char *);
__declspec(section ".data") extern s32 lbl_803514A0;


extern f32 lbl_80350EC4[];
extern f32 lbl_80350ED8[];

extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern void fn_802344CC(char *, s32, s32, s32, f32, f32, f32);
extern f64 lbl_80560268;
extern s32 fn_8023441C(void);
extern s32 fn_80232B70(s32);
extern f32 fn_80011EDC(void);
extern s32 fn_80232578(s32);
extern char lbl_802FC414[];
extern s32 lbl_8055D49C;
extern f32 lbl_8056025C;
extern f32 lbl_80560260;
extern f32 lbl_805602C4;
extern f32 lbl_805602C0;
extern f32 fn_80011E54(void);
extern f32 fn_80011E90(void);
extern f32 fn_80011E1C(s32);
extern f32 fn_80011DC0(s32);
extern s32 lbl_8055D498;
extern void fn_80234470(void);
extern void fn_802328D4();

extern s32 lbl_8055D4A8;
extern s32 lbl_8055D484;
extern s32 lbl_8055D488;
extern s32 lbl_802ED758[4];
extern s32 lbl_802ED770[4];
extern f32 lbl_80350F28[][6];

typedef struct Unk0x18 {
    f32 unk_0x00;
    f32 unk_0x04;
    f32 unk_0x08;
    f32 unk_0x0C;
    s32 unk_0x10;
    s32 unk_0x14;
} Unk0x18;
extern Unk0x18 lbl_8034F6B0[0x100];
extern void fn_80010A50(f32, f32, f32, f32, s32, s32);
extern void fn_80010B74(void);
extern void fn_80010B7C(void);
extern void fn_802C8BD0(s32);
extern void fn_802C8D74(void);
extern void fn_80234AEC(void);
extern void *fn_80010BEC(void *);

extern void fn_802346C8(void *);

extern s32 lbl_8055D4D0;
extern s32 lbl_8055D4C0;
extern s32 lbl_8055D4C4;
extern s32 lbl_8055D4C8;
extern s32 fn_8023512C();
extern void fn_80235380();
__declspec(section ".data") extern s32 lbl_80350F88;
__declspec(section ".data") extern s32 lbl_80351214;
extern s32 lbl_8055D4BC;
typedef struct UnkF22C UnkF22C;
typedef struct UnkF22CVtable {
    void *unk_0x0;
    void *unk_0x4;
    void (*unk_0x8)();
} UnkF22CVtable;
struct UnkF22C {
    UnkF22CVtable *vtable;
};
extern UnkF22C *lbl_8055D4B4;
extern UnkF22C *lbl_8055D4B8;
  extern void fn_802328D4();
  extern char lbl_802FC414[];
extern s32 fn_80232578(s32);
extern s32 lbl_80351738[0x54];
extern s32 lbl_8055D494;
extern char lbl_802FC518[];
extern s32 lbl_80558AA4;
extern f32 lbl_80560280;
extern f32 lbl_80560264;
extern void fn_802337A0(f32, s32, f32, s32, f32, f32, s32, f32, const char *, ...);
extern UnkF22C *lbl_8055D4B0;
extern void fn_802C6CF8(s32);
extern s32 lbl_80558A94;
extern s32 fn_802C6FC0(s32, s32, s32);
  extern void fn_80234470(void);
  extern s32 lbl_8055D498;
  extern s32 lbl_8055D49C;
  extern s32 fn_8023441C(void);
  extern f32 fn_80011EDC(void);
      extern s32 fn_801E85A4(void);
  extern f32 fn_80011E54(void);
  extern f32 fn_80011E90(void);
  extern f32 fn_80011E1C(s32);
  extern f32 fn_80011DC0(s32);
  extern f32 lbl_80560260;
  extern f32 lbl_805602C4;
  extern f32 lbl_805602C0;
extern s32 fn_80207848(void *, s32);
extern void fn_801310B4(void *, s32, s32);
extern s32 fn_80130FE0(s32);
extern char *strcpy(char *, const char *);
extern f32 lbl_805602B8;
extern f32 lbl_805602BC;
extern char lbl_802FC3A4[];
extern f64 lbl_80560278;
extern f64 fn_8002EFB4(f64);
extern void fn_801E7E18(void);
extern char lbl_802FC3DC[];
extern s32 fn_802E317C(void *, ...);
extern char lbl_802FC420[];
extern char lbl_802FC42C[];
#pragma scheduling off
#pragma peephole off
void fn_8000F188(s32 arg0) {
    lbl_80558A94 = fn_802C6FC0(arg0, 0, 0);
}
#pragma peephole on
#pragma scheduling reset
void fn_8000F1B4(void) {
    fn_802C6CF8(lbl_80558A94);
    lbl_80558A94 = -1;
}

void fn_8000F1E0(void) {
    s32 flag;
    flag = 1;
    lbl_8055D4BC = fn_8023512C();
    lbl_8055D4B4 = (UnkF22C *)fn_80207848(lbl_802FC420, flag);
    lbl_8055D4B8 = (UnkF22C *)fn_80207848(lbl_802FC42C, flag);
}

void fn_8000F22C(void) {
    UnkF22C *obj;
    void (*destroy)(UnkF22C *, s32);
    if (lbl_8055D4BC != 0) fn_80235380(lbl_8055D4BC);
    lbl_8055D4BC = 0;
    obj = lbl_8055D4B4;
    if (obj != 0) {
        if (obj != 0) {
            destroy = obj->vtable->unk_0x8;
            destroy(obj, 1);
        }
    }
    obj = lbl_8055D4B8;
    if (obj != 0) {
        if (obj != 0) {
            destroy = obj->vtable->unk_0x8;
            destroy(obj, 1);
        }
    }
}

void fn_8000F2A8(s32 arg0, s32 arg1) {
    lbl_80350F88 = fn_8023512C(arg0);
    lbl_80351214 = fn_8023512C(arg1);
}

void fn_8000F2EC(void) {
    if (lbl_80350F88 != 0) fn_80235380(lbl_80350F88);
    if (lbl_80351214 != 0) fn_80235380(lbl_80351214);
}

void fn_8000F330(void *arg0, void *arg1, s32 arg2) {
    lbl_8055D4C0 = fn_8023512C();
    lbl_8055D4C4 = fn_80232578((s32)arg1);
    lbl_8055D4C8 = fn_80232578(arg2);
}

void fn_8000F384(void) {
    if (lbl_8055D4C0 != 0) {
        fn_80235380(lbl_8055D4C0);
        lbl_8055D4C0 = 0;
    }
    if (lbl_8055D4C4 != 0) {
        fn_802328D4(lbl_8055D4C4);
        lbl_8055D4C4 = 0;
    }
    if (lbl_8055D4C8 != 0) {
        fn_802328D4(lbl_8055D4C8);
        lbl_8055D4C8 = 0;
    }
}

void fn_8000F3E8(void) {
    lbl_8055D4D0 = fn_8023512C();
}

void fn_8000F40C(void) {
    if (lbl_8055D4D0 != 0) {
        fn_80235380(lbl_8055D4D0);
        lbl_8055D4D0 = 0;
    }
}

extern s32 lbl_8055D4CC;
extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
extern s32 fn_8023441C(void);
extern s32 fn_80232B70(s32);
extern f32 fn_80011EDC(void);
extern s32 fn_80232578(s32);
extern char lbl_802FC414[];
extern s32 lbl_8055D49C;
void fn_8000F440(void) {
    lbl_8055D4CC = fn_8023512C();
}

void fn_8000F464(void) {
    if (lbl_8055D4CC != 0) {
        fn_80235380(lbl_8055D4CC);
        lbl_8055D4CC = 0;
    }
}

extern s32 fn_80232B70(s32);
extern s32 lbl_8055D490;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
extern s32 lbl_8055D4D4;
void fn_8000F498(void) {
    lbl_8055D4D4 = fn_8023512C();
}

void fn_8000F4BC(void) {
    if (lbl_8055D4D4 != 0) {
        fn_80235380(lbl_8055D4D4);
        lbl_8055D4D4 = 0;
    }
}

extern f64 ceil(f64);
extern char *fn_80131268(const char *);
extern void fn_801345D8(char *, s32, const char *, ...);
extern void fn_80147ABC(void *, void *, const char *, ...);
extern void *fn_801E7E3C(void);
extern void fn_80232928(s32);
extern void fn_80232930(void);
extern void fn_802C86F0(void *, s32, s32, s32, s32);
extern void fn_802C8750(void *, s32);
extern s32 lbl_80558A98;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern f32 lbl_805602CC, lbl_805602D0, lbl_805602D4;
void fn_8000F4F0(void) {
    char text[32];
    char buffer[20];
    UnkF4F0Style a, b;
    s32 scope[4];
    f32 time, scale;
    s32 number;
    u32 alpha;
    char *src, *dst;
    s32 count;
    UnkF4F0Style *p, *q;
    UnkF4F0Style *(*lookup)(void *, const char *);
    fn_802C86F0(scope, 0, 0, lbl_8055CFF0, lbl_8055CFF4);
    time = *(f32 *)((u8 *)fn_801E7E3C()+0x10);
    number = -1;
    *(s32 *)(text+0)=0; *(s32 *)(text+4)=0; *(s32 *)(text+8)=0; *(s32 *)(text+12)=0;
    *(s32 *)(text+16)=0; *(s32 *)(text+20)=0; *(s32 *)(text+24)=0; *(s32 *)(text+28)=0;
    scale = lbl_80560280;
    alpha = 255;
    if (!(time > lbl_805602CC)) {
        if (time > lbl_805602D0 && time <= lbl_805602CC) {
            number = (s32)(f32)ceil(time);
            if (number != lbl_80558A98) {
                u8 *obj = (u8 *)lbl_8055D4B4;
                obj[0x49] = 1;
                obj[0x4B] = 0;
                obj[0x4A] = 0;
            }
            scale = (f32)number - time;
            fn_801345D8(buffer,20,(char *)lbl_802FC2A8+0x190,number);
            src = fn_80131268(buffer);
            dst = text; count = 32;
            while ((*dst++ = *src++) != 0) {
                if (--count <= 0) {dst[-1]=0; break;}
            }
        } else if (-time < lbl_805602B8) {
            f32 x, y;
            number = 0;
            if (lbl_80558A98 != 0) {
                u8 *obj = (u8 *)lbl_8055D4B8;
                obj[0x49] = 1;
                obj[0x4B] = 0;
                obj[0x4A] = 0;
            }
            x = (-time-lbl_8056025C)/lbl_80560264;
            x = lbl_80560264 < x ? lbl_80560264 : x;
            x = x > lbl_80560280 ? x : lbl_80560280;
            y = lbl_805602B8 - -time;
            scale = lbl_80560280 + x * lbl_80560264;
            if (y < lbl_805602D4) alpha = (s32)((f32)alpha * (y/lbl_805602D4));
            src = fn_80131268((char *)lbl_802FC2A8+0x1A4);
            dst = text; count = 32;
            while ((*dst++ = *src++) != 0) {
                if (--count <= 0) {dst[-1]=0; break;}
            }
        }
    }
    lbl_80558A98 = number;
    if (lbl_8055D4B0) {
        lookup = *(UnkF4F0Style *(**)(void *, const char *))((u8 *)lbl_8055D4B0->vtable+0xC);
        p = lookup(lbl_8055D4B0,(char *)lbl_802FC2A8+0x1B8);
        lookup = *(UnkF4F0Style *(**)(void *, const char *))((u8 *)lbl_8055D4B0->vtable+0xC);
        q = lookup(lbl_8055D4B0,(char *)lbl_802FC2A8+0x1C4);
        if (p && q) {
            a = *p; b = *q;
            a.unk_0x18 = (a.unk_0x18 & 0xFFFFFF) | (alpha << 24);
            b.unk_0x18 = a.unk_0x18;
            fn_80232928(-1);
            fn_80147ABC(&a,&b,(const char *)&lbl_80558AA4,text,scale);
            fn_80232930();
        }
    }
    fn_802C8750(scope,-1);
}

#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8000FB44(void) {
    struct Obj {
        virtual void v0(int);
    };
    s32 value;

    value = lbl_80351738[0x14];
    if (value != 0) {
        ((void (*)(s32))fn_80235380)(value);
    }
    lbl_80351738[0x14] = 0;
    fn_802328D4(lbl_8055D494, lbl_80351738);
    lbl_8055D494 = 0;
    if (lbl_8055D4B0 != 0) {
        if (lbl_8055D4B0 != 0) {
            ((Obj *)lbl_8055D4B0)->v0(1);
        }
    }
    lbl_8055D4B0 = 0;
    fn_8000F40C();
    fn_8000F464();
    fn_8000F384();
    fn_8000F1B4();
    fn_8000F2EC();
    fn_8000F22C();
    fn_8000F4BC();
}
#pragma cplusplus reset
#pragma scheduling on
extern void fn_8000F4F0(void);
void fn_8000FBE4(void) {
    fn_8000F4F0();
}

#pragma scheduling invalid_target
void fn_8000FBE8(f32 arg0, f32 arg1, f32 arg2) {
    extern f32 fn_80235F64(s32, s32);
    extern s32 lbl_8055D4CC;
    extern f32 lbl_80560290, lbl_805602F8, lbl_805602FC;
    extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f3;

    temp_f28 = arg1 + lbl_80560264;
    temp_f3 = fn_80235F64(lbl_8055D4CC, 4) * arg2;
    temp_f31 = lbl_805602F8 + temp_f3;
    temp_f30 = arg0 - lbl_80560290;
    temp_f29 = lbl_80560290 + (temp_f28 + (temp_f3 * lbl_8056025C));
    ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4D0, 4, temp_f30, temp_f29, temp_f31, temp_f31);
    ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4D0, 5, temp_f30 + temp_f31, temp_f29, lbl_805602FC, temp_f31);
}

#pragma push
#pragma processor 750
#pragma paired_single off
void fn_8000FC8C(s32 arg0, s32 arg1) {
    extern s32 fn_80232B70(s32);
    extern f32 fn_80011E54(void);
    extern f32 fn_80011E70(void);
    extern f32 fn_80235EF0(s32, s32);
    extern f32 fn_80235F64(s32, s32);
    extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
    extern void fn_802337A0(f32, s32, f32, s32, f32, f32, s32, f32, const char *, ...);
    extern f32 lbl_80560300;
    extern f32 lbl_80560304;
    extern f32 lbl_805602B0;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f31;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f1;
    f32 temp_f1_2;

    temp_f1 = (f32)fn_80232B70(lbl_8055D4C4);
    temp_f30 = lbl_80560300 / temp_f1;
    temp_f29 = fn_80011E70();
    temp_f28 = fn_80011E54();
    if (lbl_8055D4C0 != 0) {
        temp_f31 = fn_80235EF0(lbl_8055D4C0, 0);
        temp_f1_2 = temp_f31 + fn_80235EF0(lbl_8055D4C0, 1);
        temp_f27 = temp_f29 - (lbl_8056025C * temp_f1_2);
        temp_f26 = (temp_f28 - lbl_80560304) + (lbl_8056025C * fn_80235F64(lbl_8055D4C0, 0));
        ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4C0, 0, temp_f27, temp_f26, lbl_80560280, lbl_80560280);
        ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4C0, 1, temp_f27 + temp_f31, temp_f26, lbl_80560280, lbl_80560280);
    }
    fn_802337A0(lbl_805602B0 + temp_f29, lbl_8055D4C4, temp_f28 - lbl_805602B0,
                0xFF000000, lbl_80560280, temp_f30, 0xC, lbl_80560264,
                (const char *)&lbl_80558AA4, arg0);
    fn_802337A0(temp_f29, lbl_8055D4C4, temp_f28, -1,
                lbl_80560280, temp_f30, 0xC, lbl_80560264,
                (const char *)&lbl_80558AA4, arg0);
}
#pragma pop

#pragma push
#pragma processor 750
void fn_8000FF88(s32 arg0, s32 arg1, const char *fmt, f32 farg0, f32 farg1, f32 farg2, ...) {
    #pragma scheduling invalid_target
    char buffer[0x200];
    va_list args;

    va_start(args, farg2);
    vsprintf(buffer, fmt, args);
    fn_802344CC(buffer, arg0, arg1, 0, farg1, farg2, lbl_805602C8 * farg0);
}
#pragma pop

#pragma scheduling on
extern f32 lbl_805602B0;
extern void fn_802344CC(char *, s32, s32, s32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80010074(s32 arg0, s32 arg1, const char *fmt, f32 farg0, f32 farg1, f32 farg2, ...) {
    char buffer[0x200];
    va_list args;
    va_start(args, farg2);
    vsprintf(buffer, fmt, args);
    fn_802344CC(buffer, arg0 & 0xFF000000, arg1, 0,
                lbl_805602B0 + farg1, farg2 - lbl_805602B0, lbl_805602C8 * farg0);
    fn_802344CC(buffer, arg0, arg1, 0, farg1, farg2, lbl_805602C8 * farg0);
}
#pragma scheduling on
#pragma pop

extern void fn_80232BA4(char *, s32, s32, s32, f32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80010188(s32 arg0, s32 arg1, const char *fmt, f32 scale, f32 x, f32 y, ...) {
    char buffer[0x200];
    va_list args;
    va_start(args, y);
    vsprintf(buffer, fmt, args);
    fn_80232BA4(buffer, lbl_8055D490, arg0, arg1,
                x, y, lbl_805602C8 * scale,
                lbl_80560280, lbl_80560264);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8001027C(s32 arg0, s32 arg1, const char *fmt, f32 last, f32 value, f32 scale, ...) {
    char buffer[0x200];
    va_list args;

    if (lbl_8055D494 != 0) {
        va_start(args, scale);
        vsprintf(buffer, fmt, args);
        if (strlen(buffer) >= 0x200)
            fn_802E317C((void *)lbl_802FC518, strlen(buffer), fmt);
        fn_802337A0(value, lbl_8055D494, scale, arg0,
                    lbl_80560280, last, arg1, lbl_80560264,
                    (const char *)&lbl_80558AA4, buffer);
    }
}
#pragma scheduling on
#pragma pop

#pragma scheduling on
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_800103B8(s32 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3, const char *fmt, ...) {
    char buffer[0x200];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    fn_80233010(buffer, lbl_8055D490,
                farg1, farg2, farg3,
                lbl_805602C8 * farg0,
                lbl_80560280, lbl_80560264,
                arg0, arg1, 1);
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_800105A0(s32 arg0, s32 arg1, s32 unused) {
    extern s32 fn_80137C74(void);
    extern f32 fn_800108C8(f32, s32);
    extern f32 fn_80011E04(s32);
    extern f32 fn_80011E1C(s32);
    extern void fn_80010B80(s32, f32, f32, f32, f32);
    extern void fn_80010C74(f32, f32, f32);
    extern void fn_80010D88(f64, f64, f64);
    extern void fn_8000FF88(s32, s32, const char *, f32, f32, f32, ...);
    extern f32 lbl_8056025C;
    extern f32 lbl_80560264;
    extern f32 lbl_805602EC;
    extern f32 lbl_805602F8;
    extern f32 lbl_80560314;
    extern f32 lbl_80560318;
    s32 mode;
    s32 temp;
    s32 mask;
    s32 amount;
    s32 result;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;

    mode = fn_80137C74();
    temp = mode ^ 2;
    mask = temp >> 1;
    temp &= mode;
    temp = mask - temp;
    result = ((u32)temp) >> 31;
    if (result != 0)
        f30 = lbl_80560264;
    else
        f30 = lbl_80560318;
    f29 = lbl_805602F8 + fn_800108C8(f30, arg0);
    if (result != 0)
        f31 = lbl_805602EC;
    else
        f31 = lbl_80560314;
    f28 = (-f29 * lbl_8056025C) + fn_80011E04(arg1);
    f27 = fn_80011E04(arg1);
    amount = (result != 0) ? 0 : -0x28;
    f26 = (f32)amount + fn_80011E1C(arg1);
    fn_80010B80(0x90000000, f28, f26, f29, f31);
    fn_80010C74(f28, lbl_80560264 + f26, lbl_80560264 + f29);
    fn_80010D88(f28 + f29, f26, f31);
    fn_80010C74(f28, f26 - f31, lbl_80560264 + f29);
    fn_80010D88(f28, f26, f31);
    fn_8000FF88(-1, 0xC, (const char *)arg0, f30, f27, f26);
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma pop
extern void fn_80010FDC(s32);
extern f32 lbl_80560280;
extern f32 fn_8023293C(s32, f32);
extern f32 fn_80235F64(s32, s32);
extern f32 lbl_8056025C;
extern f32 lbl_80560264;
extern f32 lbl_80560290;
extern f32 lbl_805602F8;
extern f32 lbl_805602FC;
extern s32 lbl_80558A90;
extern s32 lbl_8055D494;
  extern UnkF22C *lbl_8055D4B0;
  extern char lbl_802FC518[];
  extern s32 lbl_80558AA4;
  extern void fn_802337A0(f32, s32, f32, s32, f32, f32, s32, f32, const char *, ...);
  void fn_8001071C(s32 arg0) {
    ((void (*)(s32, s32))fn_80010FDC)(arg0, 0xD);
}

#pragma push
#pragma processor 750
#pragma paired_single off
void fn_80010724(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 fn_8001084C(s32);
    extern s32 fn_80010964(s32);
    extern f32 fn_800109A0(s32);
    extern void fn_80010B80(s32, f32, f32, f32, f32);
    extern f32 lbl_80560310;
    extern f32 lbl_8056031C;
    extern f32 lbl_80560320;
    extern f32 lbl_805602F4;
    f32 temp_f1;
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f31_2;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 result;

    temp_f1 = (f32)((s32 (*)(s32, s32))fn_8001084C)(0x10, arg2);
    temp_f31 = lbl_80560310 + temp_f1;
    temp_f4 = lbl_8056031C + (f32)fn_80010964(0x10);
    temp_f6 = (f32)arg0;
    temp_f5 = temp_f6 - lbl_80560320;
    temp_f30 = temp_f5 - (temp_f31 * lbl_8056025C);
    temp_f31_2 = (lbl_805602F4 - (f32)arg1) + (temp_f4 * lbl_8056025C);
    ((void (*)(s32, f32, f32, f32, f32, f32, f32))fn_80010B80)(0x80000000, temp_f30, temp_f31_2, temp_f31, temp_f4, temp_f5, temp_f6);
    result = fn_800109A0(lbl_80558A90);
    ((void (*)(s32, s32, const char *, f32, ...))fn_8000FF88)(-1, 0x14, (const char *)&lbl_80558AA4, result, arg2, temp_f30, temp_f31_2);
}
#pragma pop
s32 fn_8001084C(s32 arg0) {
    return (s32)(((f32)arg0 * fn_8023293C(lbl_8055D490, lbl_80560264)) / (f32)lbl_80558A90);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
f32 fn_800108C8(f32 farg0, s32 arg0) {
    return (farg0 * ((f32 (*)(s32, s32, f32))fn_8023293C)(lbl_8055D490, arg0, lbl_80560264)) * lbl_805602C8;
}
#pragma pop
extern s32 lbl_80558A90;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma fp_contract on
f32 fn_8001090C(f32 farg0) {
    union {
        f64 value;
        u32 words[2];
    } converted;
    s32 raw;
    f64 number;
    f64 magic;
    f32 scaled;
    raw = fn_80232B70(lbl_8055D490);
    converted.words[1] = (u32)raw ^ 0x80000000;
    converted.words[0] = 0x43300000;
    number = converted.value;
    magic = lbl_80560268;
    scaled = (f32)(number - magic);
    return lbl_805602C8 * (farg0 * scaled);
}
#pragma pop
s32 fn_80010964(s32 arg0) {
    return (s32)(arg0 * fn_80232B70(lbl_8055D490)) / (s32)lbl_80558A90;
}

extern s32 fn_80232B70(s32);
extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
f32 fn_800109A0(s32 arg0) {
    return (f32)arg0 / (f32)lbl_80558A90;
}

void fn_800109E4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    s32 sp18;
    s32 sp1C;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg3;
    sp14 = arg4;
    sp18 = arg0;
    sp1C = arg0;
    fn_80010B74();
    fn_80010A50(arg1, arg2, arg3, arg4, arg0, arg0);
    fn_80010B7C();
}

extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
extern void fn_802C8DB8(void *, s32, u16 *, s32);
struct IndexList802ED748 {
    u16 idx[6];
};
extern struct IndexList802ED748 lbl_802ED748;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_80010A50(f32 farg0, f32 farg1, f32 farg2, f32 farg3, s32 arg4, s32 arg5) {
    struct Frame {
        struct IndexList802ED748 indices;
        u8 pad[4];
        f32 sp20[6];
        f32 sp38[6];
        f32 sp50[6];
        f32 sp68[6];
    } __attribute__((aligned(16))) frame;

    fn_80231380(frame.sp20, arg4, farg0, farg1, lbl_80560264, lbl_80560280, lbl_80560280);
    fn_80231380(frame.sp38, arg5, farg0 + farg2, farg1, lbl_80560264, lbl_80560280, lbl_80560280);
    fn_80231380(frame.sp50, arg4, farg0, farg1 - farg3, lbl_80560264, lbl_80560280, lbl_80560280);
    fn_80231380(frame.sp68, arg5, farg0 + farg2, farg1 - farg3, lbl_80560264, lbl_80560280, lbl_80560280);
    frame.indices = lbl_802ED748;
    fn_802C8DB8(frame.sp20, 4, frame.indices.idx, 6);
}
#pragma pop
void fn_80010B74(void) {
    fn_802C8BD0(-1);
}

void fn_80010B7C(void) {
    fn_802C8D74();
}

void fn_80010B80(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    volatile s32 spill_arg0_a;
    volatile s32 spill_arg0_b;
    volatile f32 spill_arg4;
    volatile f32 spill_arg3;
    volatile f32 spill_arg2;
    volatile f32 spill_arg1;
    register s32 index;

    index = lbl_8055D4A8;
    spill_arg1 = arg1;
    spill_arg2 = arg2;
    spill_arg3 = arg3;
    spill_arg4 = arg4;
    spill_arg0_b = arg0;
    spill_arg0_a = arg0;

    if (index < 0x100) {
        Unk0x18 *entry = &lbl_8034F6B0[index];
        entry->unk_0x00 = arg1;
        entry->unk_0x04 = arg2;
        entry->unk_0x08 = arg3;
        entry->unk_0x0C = arg4;
        entry->unk_0x10 = arg0;
        entry->unk_0x14 = arg0;
        lbl_8055D4A8 = index + 1;
    }
}

#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_80010BEC(void *arg0) {
    Unk0x18 *entry;
    s32 i;

    if (lbl_8055D4A8 > 0) {
        fn_80010B74();
        entry = lbl_8034F6B0;
        i = 0;
        while (i < lbl_8055D4A8) {
            fn_80010A50(entry->unk_0x00, entry->unk_0x04, entry->unk_0x08,
                        entry->unk_0x0C, entry->unk_0x10, entry->unk_0x14);
            entry++;
            i++;
        }
        fn_80010B7C();
        lbl_8055D4A8 = 0;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80010C74(register f32 farg0, register f32 farg1, register f32 farg2) {
    volatile s32 sp34;
    volatile s32 sp30;
    volatile f32 sp2C;
    volatile f32 sp28;
    volatile f32 sp24;
    volatile f32 sp20;
    volatile s32 sp1C;
    volatile s32 sp18;
    volatile f32 sp14;
    volatile f32 sp10;
    volatile f32 spC;
    volatile f32 sp8;
    register f32 temp_f4;
    register f32 temp_f5;
    register f32 temp_f6;
    register s32 index;
    register s32 next;

    index = lbl_8055D4A8;
    if (index < 0xFF) {
        *(volatile u32 *)&sp2C = lbl_802ED758[3];
        temp_f6 = farg2;
        temp_f5 = lbl_80560264 + farg0;
        temp_f4 = farg1 - lbl_80560264;
        lbl_8034F6B0[index].unk_0x00 = farg0;
        next = index + 1;
        lbl_8034F6B0[index].unk_0x04 = farg1;
        lbl_8034F6B0[index].unk_0x08 = farg2;
        lbl_8034F6B0[index].unk_0x0C = sp2C;
        lbl_8034F6B0[index].unk_0x10 = lbl_8055D484;
        lbl_8034F6B0[index].unk_0x14 = lbl_8055D484;
        *(volatile u32 *)&sp14 = lbl_802ED770[3];
        lbl_8034F6B0[next].unk_0x00 = temp_f5;
        *(volatile u32 *)&sp20 = lbl_802ED758[0];
        lbl_8034F6B0[next].unk_0x04 = temp_f4;
        lbl_8034F6B0[next].unk_0x08 = temp_f6;
        *(volatile u32 *)&sp24 = lbl_802ED758[1];
        *(volatile u32 *)&sp28 = lbl_802ED758[2];
        *(volatile u32 *)&sp8 = lbl_802ED770[0];
        *(volatile u32 *)&spC = lbl_802ED770[1];
        *(volatile u32 *)&sp10 = lbl_802ED770[2];
        lbl_8034F6B0[next].unk_0x0C = sp14;
        sp20 = farg0;
        sp24 = farg1;
        sp28 = farg2;
        sp30 = lbl_8055D484;
        sp34 = lbl_8055D484;
        sp8 = temp_f5;
        spC = temp_f4;
        sp10 = farg2;
        sp18 = lbl_8055D488;
        sp1C = lbl_8055D488;
        lbl_8055D4A8 = next + 1;
        lbl_8034F6B0[next].unk_0x10 = lbl_8055D488;
        lbl_8034F6B0[next].unk_0x14 = lbl_8055D488;
    }
}
#pragma pop
extern u32 lbl_802ED788[];
extern u32 lbl_802ED7A0[];
extern s32 lbl_8055D484;
extern s32 lbl_8055D488;
#pragma push
#pragma scheduling invalid_target
void fn_80010D88(f64 farg0, f64 farg1, f64 farg2) {
    volatile s32 sp34;
    volatile s32 sp30;
    volatile f32 sp2C;
    volatile f32 sp28;
    volatile f32 sp24;
    volatile f32 sp20;
    volatile s32 sp1C;
    volatile s32 sp18;
    volatile f32 sp14;
    volatile f32 sp10;
    volatile f32 spC;
    volatile f32 sp8;
    register s32 index;
    register s32 next;
    register s32 offset;
    register Unk0x18 *base;
    register Unk0x18 *current;
    register Unk0x18 *following;
    register u32 *configA;
    register u32 *configB;
    register s32 value484;
    register s32 value488;
    register f32 temp_f0;
    register f32 temp_f5;
    register f32 temp_f6;
    register f32 temp_f4;
    u32 word;

    index = lbl_8055D4A8;
    if (index < 0xFF) {
        configA = (u32 *)&lbl_802ED788;
        value484 = *(volatile s32 *)&lbl_8055D484;
        temp_f0 = (f32)farg0;
        offset = index * 0x18;
        word = configA[2];
        temp_f5 = (f32)farg1;
        value488 = *(volatile s32 *)&lbl_8055D488;
        base = lbl_8034F6B0;
        temp_f6 = (f32)farg2;
        *(volatile u32 *)&sp28 = word;
        current = (Unk0x18 *)((u8 *)base + offset);
        current->unk_0x00 = temp_f0;
        next = index + 1;
        current->unk_0x04 = temp_f5;
        current->unk_0x08 = sp28;
        current->unk_0x0C = temp_f6;
        current->unk_0x10 = value484;
        current->unk_0x14 = value484;
        temp_f4 = *(volatile f32 *)&lbl_80560264;
        temp_f5 = temp_f4 + (f32)farg0;
        temp_f4 = (f32)farg1 - temp_f4;
        configB = (u32 *)&lbl_802ED7A0;
        *(volatile u32 *)&sp10 = configB[2];
        offset = next * 0x18;
        following = (Unk0x18 *)((u8 *)base + offset);
        following->unk_0x00 = temp_f5;
        *(volatile u32 *)&sp20 = configA[0];
        following->unk_0x04 = temp_f4;
        following->unk_0x08 = sp10;
        following->unk_0x0C = temp_f6;
        *(volatile u32 *)&sp24 = configA[1];
        *(volatile u32 *)&sp2C = configA[3];
        *(volatile u32 *)&sp8 = configB[0];
        *(volatile u32 *)&spC = configB[1];
        *(volatile u32 *)&sp14 = configB[3];
        following->unk_0x10 = value488;
        sp20 = (f32)farg0;
        sp24 = (f32)farg1;
        sp2C = (f32)farg2;
        sp30 = value484;
        sp34 = value484;
        sp8 = temp_f5;
        spC = temp_f4;
        sp14 = (f32)farg2;
        sp18 = value488;
        sp1C = value488;
        lbl_8055D4A8 = next + 1;
        following->unk_0x14 = value488;
    }
}
#pragma pop

void fn_80010EF0(void);
void fn_80010F08(void);
void fn_80010F20(void);
void fn_80010EC8(void) {
    fn_80010EF0();
    fn_80010F08();
    fn_80010F20();
}

typedef struct Unk80350F88Entry {
    char name[0x28];
    u8 unk_0x28;
    s32 unk_0x2C;
    s32 unk_0x30;
    s32 unk_0x34;
    s32 unk_0x38;
    f32 unk_0x3C;
} Unk80350F88Entry;

typedef struct Unk80350F88 {
    s32 unk_0x00;
    u8 unk_0x04;
    Unk80350F88Entry entries[10];
    s32 unk_0x288;
} Unk80350F88;
extern char *strncpy(char *, const char *, unsigned long);
extern f32 lbl_80560264;
extern f32 lbl_80560280;
extern void fn_802353F4(f32, f32, f32, f32, f32, f32);
extern void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
void fn_80010E94(f32 x, f32 y, f32 a, f32 b, s32 c, s32 d) {
    if (lbl_80560280 == a && lbl_80560280 == b) {
        fn_802353F4(x, y, lbl_80560264, b, b, a);
    } else {
        fn_802354A0(c, d, -1, x, y, lbl_80560264, a, b);
    }
}
#pragma scheduling off
void fn_80010EF0(void) {
    s8 *p;
    s32 *q;
    p = (s8 *)&lbl_80350F88;
    q = (s32 *)(p + 0x288);
    *q = 0;
    *(s8 *)(p + 0x4) = 0;
}

void fn_80010F08(void) {
    s8 *p;
    s32 *q;
    p = (s8 *)&lbl_80351214;
    q = (s32 *)(p + 0x288);
    *q = 0;
    *(s8 *)(p + 0x4) = 0;
}

void fn_80010F20(void) {
    s8 *p;
    s32 *q;
    p = (s8 *)&lbl_803514A0;
    q = (s32 *)(p + 0x288);
    *q = 0;
    *(s8 *)(p + 0x4) = 0;
}

#pragma scheduling on
extern void fn_80011280(s32, s32, f64, f64, f32, f32);
extern void fn_8000E3B4(s32);
extern void fn_8000E874(s32);
extern void fn_8000EF74(s32);
#pragma push
#pragma processor 750
void fn_80010F38(char *name, s32 a2, s32 a3, s32 a4, f32 f1) {
    s32 idx;
    Unk80350F88 *base;
    volatile Unk80350F88Entry *entry;
    char *n;
    base = (Unk80350F88 *)&lbl_80350F88;
    idx = base->unk_0x288;
    n = name;
    base->unk_0x288 = idx + 1;
    entry = &base->entries[idx];
    strncpy((char *)entry->name, n, 0x28);
    entry->unk_0x28 = 0;
    entry->unk_0x2C = a2;
    entry->unk_0x30 = a3;
    entry->unk_0x34 = 0;
    entry->unk_0x38 = a4;
    entry->unk_0x3C = f1;
}
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_800111A4(char *name, s32 a1, s32 a2, s32 a3, s32 a4, f32 f) {
    s32 idx;
    Unk80350F88 *base;
    volatile Unk80350F88Entry *entry;
    char *n;

    base = (Unk80350F88 *)&lbl_80350F88;
    idx = base->unk_0x288;
    n = name;
    base->unk_0x288 = idx + 1;
    entry = &base->entries[idx];
    strncpy((char *)entry->name, n, 0x28);
    entry->unk_0x28 = 0;
    entry->unk_0x2C = a1;
    entry->unk_0x30 = a2;
    entry->unk_0x38 = a4;
    entry->unk_0x3C = f;
    entry->unk_0x34 = a3;
}
#pragma scheduling on
#pragma use_lmw_stmw on
void fn_8001123C(s32 arg0) {
    fn_8000E3B4(arg0);
    fn_8000E874(arg0);
    fn_8000EF74(arg0);
}

void fn_80011278(s32 arg0) {
    ((void (*)(s32, s32))fn_80011280)(arg0, lbl_8055D4D4);
}

extern f32 fn_80235EF0(s32, s32);
void fn_80011280(s32 arg0, s32 arg1, f64 farg0, f64 farg1, f32 farg2, f32 farg3) {
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f26_4;
    f32 temp_f26_5;
    f32 temp_f27;
    f32 temp_f2;
    f32 temp_f5;

    temp_f26 = fn_80235EF0(arg1, 0);
    temp_f5 = fn_80235F64(arg1, 0);
    sp8 = farg0;
    spC = (f32)farg1;
    fn_802354A0(arg1, 0, arg0, (f32)farg0, (f32)farg1, lbl_80560280, temp_f26, temp_f5);
    temp_f1 = fn_80235EF0(arg1, 1);
    spC = (f32)farg1;
    sp8 = (farg0 + farg2) - temp_f1;
    fn_802354A0(arg1, 1, arg0, sp8, (f32)farg1, lbl_80560280, temp_f1, fn_80235F64(arg1, 1));
    temp_f26_2 = fn_80235EF0(arg1, 2);
    temp_f1_2 = fn_80235F64(arg1, 2);
    sp8 = farg0;
    spC = temp_f1_2 + ((f32)farg1 - farg3);
    fn_802354A0(arg1, 2, arg0, (f32)farg0, spC, lbl_80560280, temp_f26_2, fn_80235F64(arg1, 2));
    temp_f1_3 = fn_80235EF0(arg1, 3);
    sp8 = (farg0 + farg2) - temp_f1_3;
    spC = fn_80235F64(arg1, 3) + ((f32)farg1 - farg3);
    fn_802354A0(arg1, 3, arg0, sp8, spC, lbl_80560280, temp_f1_3, fn_80235F64(arg1, 3));
    temp_f1_4 = fn_80235EF0(arg1, 0);
    temp_f0 = farg0 + temp_f1_4;
    spC = (f32)farg1;
    sp8 = temp_f0;
    temp_f26_3 = farg2 - (temp_f1_4 + fn_80235EF0(arg1, 1));
    fn_802354A0(arg1, 4, arg0, sp8, (f32)farg1, lbl_80560280, temp_f26_3, fn_80235F64(arg1, 0));
    temp_f1_5 = fn_80235EF0(arg1, 2);
    sp8 = farg0 + temp_f1_5;
    temp_f26_4 = farg2 - (temp_f1_5 + fn_80235EF0(arg1, 3));
    temp_f1_6 = fn_80235F64(arg1, 2);
    temp_f2 = temp_f1_6 + ((f32)farg1 - farg3);
    spC = temp_f2;
    fn_802354A0(arg1, 5, arg0, sp8, temp_f2, lbl_80560280, temp_f26_4, temp_f1_6);
    temp_f26_5 = fn_80235EF0(arg1, 0);
    temp_f1_7 = fn_80235F64(arg1, 0);
    temp_f0_2 = (f32)farg1 - temp_f1_7;
    sp8 = farg0;
    spC = temp_f0_2;
    fn_802354A0(arg1, 6, arg0, (f32)farg0, spC, lbl_80560280, temp_f26_5, farg3 - (temp_f1_7 + fn_80235F64(arg1, 2)));
    temp_f1_8 = fn_80235EF0(arg1, 1);
    sp8 = (farg0 + farg2) - temp_f1_8;
    temp_f1_9 = fn_80235F64(arg1, 1);
    spC = (f32)farg1 - temp_f1_9;
    fn_802354A0(arg1, 7, arg0, sp8, spC, lbl_80560280, temp_f1_8, farg3 - (temp_f1_9 + fn_80235F64(arg1, 3)));
    temp_f1_10 = fn_80235EF0(arg1, 0);
    sp8 = farg0 + temp_f1_10;
    temp_f27 = (farg2 - temp_f1_10) - fn_80235EF0(arg1, 1);
    temp_f1_11 = fn_80235F64(arg1, 0);
    spC = (f32)farg1 - temp_f1_11;
    fn_802354A0(arg1, 8, arg0, sp8, spC, lbl_80560280, temp_f27, (farg3 - temp_f1_11) - fn_80235F64(arg1, 2));
}

extern f64 sin(f32);
extern f64 cos(f32);
extern s32 fn_8022EDC4(void);
extern void fn_802C8B98(s32, s32);
extern s32 fn_801E4F20(s32);
extern s32 fn_801E4F3C(s32, s32, f32, f32, f32, f32, f32);
extern void fn_801E4FF4(void);
extern f32 lbl_8056025C, lbl_80560264, lbl_80560280, lbl_805602E0, lbl_805602E4;
extern f32 lbl_805602E0;
extern f32 lbl_805602E4;
#pragma scheduling invalid_target
void fn_80011630(s32 arg0, s32 arg1, s32 arg2,
                 register f32 farg0, register f32 farg1, register f32 farg2, register f32 farg3,
                 register f32 farg4, register f32 farg5, register f32 farg6, register f32 farg7,
                 register f32 arg_sp8, register f32 arg_spC) {
    volatile f32 sp14, sp10, spC, sp8;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4;
    f32 temp_f1_2, temp_f22, temp_f23, temp_f23_2;
    f32 temp_f25, temp_f25_2, temp_f26, temp_f27, temp_f28;
    f32 temp_f29, temp_f2, temp_f2_2, temp_f30, temp_f31;
    f32 temp_f3, temp_f4, temp_f4_2, temp_f4_3, temp_f5;
    f32 var_f0, var_f0_2, var_f1, var_f1_2, var_f3, var_f4;
    f32 var_f5, var_f5_2;
    f64 temp_f1;
    s32 var_r31;

    if (arg1 > 0) {
        fn_802C8B98(arg2, fn_8022EDC4());
        fn_801E4F20(arg1 * 4);
        temp_f25 = (f32)sin(farg4);
        temp_f1 = cos(farg4);
        temp_f22 = farg3 / farg2;
        var_f5 = lbl_80560264;
        sp14 = temp_f25;
        temp_f4 = (f32)temp_f1;
        sp10 = temp_f4;
        spC = temp_f25 * farg2;
        temp_f0 = (temp_f4 - lbl_805602E0) * lbl_8056025C;
        sp8 = temp_f4 * farg2;
        if (var_f5 < temp_f0) {
            var_f5 = temp_f0;
        }
        if (var_f5 > lbl_80560280) {
            var_f5 = lbl_80560280;
        }
        var_f3 = lbl_80560264;
        temp_f0_2 = (sp14 - var_f3) / lbl_805602E4;
        if (var_f3 < temp_f0_2) {
            var_f3 = temp_f0_2;
        }
        if (var_f3 > lbl_80560280) {
            var_f3 = lbl_80560280;
        }
        fn_801E4F3C(arg0, 0, farg0 + sp8, farg1 + spC, lbl_80560280,
                    farg6 + (var_f5 * (arg_sp8 - farg6)),
                    farg7 + (var_f3 * (arg_spC - farg7)));
        var_f4 = lbl_80560264;
        temp_f0_3 = ((temp_f22 * sp10) - lbl_805602E0) * lbl_8056025C;
        if (var_f4 < temp_f0_3) {
            var_f4 = temp_f0_3;
        }
        if (var_f4 > lbl_80560280) {
            var_f4 = lbl_80560280;
        }
        var_f5_2 = lbl_80560264;
        temp_f0_4 = ((temp_f22 * sp14) - var_f5_2) / lbl_805602E4;
        if (var_f5_2 < temp_f0_4) {
            var_f5_2 = temp_f0_4;
        }
        if (var_f5_2 > lbl_80560280) {
            var_f5_2 = lbl_80560280;
        }
        fn_801E4F3C(arg0, 0, farg0 + (temp_f22 * sp8),
                    farg1 + (temp_f22 * spC), lbl_80560280,
                    farg6 + (var_f4 * (arg_sp8 - farg6)),
                    farg7 + (var_f5_2 * (arg_spC - farg7)));
        temp_f29 = arg_sp8 - farg6;
        temp_f25_2 = lbl_80560264;
        temp_f31 = arg_spC - farg7;
        temp_f28 = lbl_80560280;
        temp_f26 = lbl_805602E0;
        temp_f27 = lbl_8056025C;
        var_r31 = 0;
        temp_f30 = lbl_805602E4;
        while (var_r31 < arg1) {
            temp_f23 = (f32)cos(farg5);
            temp_f5 = (f32)sin(farg5);
            temp_f4_2 = sp8 * temp_f23;
            temp_f3 = spC * temp_f5;
            temp_f2 = temp_f4_2 - temp_f3;
            spC = (sp8 * temp_f5) + (spC * temp_f23);
            sp8 = temp_f2;
            temp_f23_2 = (f32)cos(farg5);
            temp_f4_3 = (f32)sin(farg5);
            temp_f2_2 = (sp10 * temp_f23_2) - (sp14 * temp_f4_3);
            temp_f1_2 = (sp10 * temp_f4_3) + (sp14 * temp_f23_2);
            sp10 = temp_f2_2;
            sp14 = temp_f1_2;
            var_f1 = (temp_f2_2 - temp_f26) * temp_f27;
            if (temp_f25_2 < var_f1)
                var_f1 = temp_f25_2;
            if (var_f1 > temp_f28)
                var_f1 = temp_f28;
            var_f0 = (sp14 - temp_f25_2) / temp_f30;
            if (temp_f25_2 < var_f0)
                var_f0 = temp_f25_2;
            if (var_f0 > temp_f28)
                var_f0 = temp_f28;
            fn_801E4F3C(arg0, 1, farg0 + sp8, farg1 + spC, lbl_80560280,
                        farg6 + (var_f1 * temp_f29), farg7 + (var_f0 * temp_f31));
            var_f1_2 = ((temp_f22 * sp10) - temp_f26) * temp_f27;
            if (temp_f25_2 < var_f1_2)
                var_f1_2 = temp_f25_2;
            if (var_f1_2 > temp_f28)
                var_f1_2 = temp_f28;
            var_f0_2 = ((temp_f22 * sp14) - temp_f25_2) / temp_f30;
            if (temp_f25_2 < var_f0_2)
                var_f0_2 = temp_f25_2;
            if (var_f0_2 > temp_f28)
                var_f0_2 = temp_f28;
            fn_801E4F3C(arg0, 1, farg0 + (temp_f22 * sp8),
                        farg1 + (temp_f22 * spC), lbl_80560280,
                        farg6 + (var_f1_2 * temp_f29), farg7 + (var_f0_2 * temp_f31));
            var_r31++;
        }
        fn_801E4FF4();
        fn_802C8D74();
    }
}
#pragma scheduling on
void fn_80011A2C(void *arg0) {
    fn_802346C8(fn_80010BEC(arg0));
}

void fn_80011A50(void) {
    lbl_8055D4A8 = 0;
    fn_80234AEC();
}

extern void fn_80231094(s32 *, s32 *, s32 *, s32 *);
extern s32 lbl_8055D4A0;
extern s8 lbl_8055D4A4;
extern f32 lbl_80560280, lbl_80560290, lbl_805602F4, lbl_805602FC;
extern f32 lbl_80560320, lbl_80560324, lbl_80560328, lbl_8056032C;
extern f32 lbl_80560330, lbl_80560334, lbl_80560338, lbl_8056033C;
extern f32 lbl_80560340, lbl_80560344;
void fn_80011A5C(s32 arg0) {
    f32 sp[20];
    s32 sp14, sp10, spC, sp8;
    f32 *var_r5;
    f32 temp_f0, temp_f11, temp_f1, temp_f1_2, temp_f2, temp_f2_2;
    f32 temp_f31, temp_f3, temp_f3_2, temp_f4, temp_f5, temp_f5_2;
    f32 temp_f6, temp_f7, temp_f7_2, temp_f8, temp_f8_2;
    s32 temp_r0, temp_r0_2, temp_r3_4, temp_r7, var_ctr;
    u8 *base, *temp_r3, *temp_r3_2, *temp_r3_3, *var_r4, *var_r6;

    base = (u8 *)lbl_8034F6B0;
    lbl_8055D4A0 = arg0;
    fn_80231094(&spC, &sp8, &sp14, &sp10);
    temp_f5 = (f32)sp14;
    temp_f6 = (f32)sp10;
    temp_f7 = (f32)spC;
    temp_f8 = (f32)sp8;
    if (arg0 == 1) {
        sp[0] = temp_f7;
        sp[3] = temp_f8;
        sp[1] = temp_f5;
        sp[2] = temp_f6;
        sp[4] = lbl_80560320;
    } else if (arg0 == 2) {
        sp[0] = temp_f7;
        sp[3] = lbl_80560280;
        sp[1] = temp_f5;
        sp[2] = temp_f6;
        sp[5] = lbl_80560280;
        sp[8] = temp_f8;
        sp[6] = temp_f5;
        sp[7] = temp_f6;
        sp[4] = lbl_80560320;
        sp[9] = lbl_80560320;
    } else {
        sp[0] = temp_f7;
        temp_f1 = (lbl_80560290 - temp_f5) * lbl_8056025C;
        temp_f0 = (temp_f6 - lbl_80560290) * lbl_8056025C;
        sp[3] = lbl_80560280;
        sp[1] = temp_f5;
        sp[2] = lbl_80560290;
        sp[5] = temp_f7;
        sp[8] = lbl_80560280;
        sp[6] = lbl_80560290;
        sp[7] = temp_f6;
        sp[10] = lbl_80560280;
        sp[13] = temp_f8;
        sp[11] = temp_f5;
        sp[12] = lbl_80560290;
        sp[15] = lbl_80560280;
        sp[18] = temp_f8;
        sp[16] = lbl_80560290;
        sp[17] = temp_f6;
        sp[4] = temp_f1;
        sp[9] = temp_f0;
        sp[14] = temp_f1;
        sp[19] = temp_f0;
    }
    temp_r3 = base + 0x1814;
    temp_f4 = lbl_805602F4 - temp_f7;
    temp_f3 = lbl_80560324 + temp_f8;
    temp_f2 = lbl_80560328 + temp_f5;
    temp_f1_2 = lbl_80560320 - temp_f6;
    *(f32 *)(base + 0x1814) = temp_f4;
    *(f32 *)(temp_r3 + 0xC) = temp_f3;
    *(f32 *)(temp_r3 + 4) = temp_f2;
    *(f32 *)(temp_r3 + 8) = temp_f1_2;
    if (arg0 < 3) {
        temp_r3_2 = base + 0x1800;
        *(f32 *)(base + 0x1800) = temp_f4;
        *(f32 *)(temp_r3_2 + 4) = temp_f2;
        *(f32 *)(temp_r3_2 + 8) = temp_f1_2;
        *(f32 *)(temp_r3_2 + 0xC) = temp_f3;
        *(f32 *)(temp_r3_2 + 0x10) = *(f32 *)(temp_r3 + 0x10);
    } else {
        temp_r3_3 = base + 0x1800;
        *(f32 *)(base + 0x1800) = lbl_8056032C - temp_f7;
        *(f32 *)(temp_r3_3 + 0xC) = lbl_80560330 + temp_f8;
        *(f32 *)(temp_r3_3 + 4) = lbl_80560334 + temp_f5;
        *(f32 *)(temp_r3_3 + 8) = lbl_80560338 - temp_f6;
    }
    var_r5 = sp;
    var_r6 = base + 0x1878;
    temp_r3_4 = lbl_8055D4A0 ^ 1;
    var_ctr = lbl_8055D4A0;
    temp_r0 = lbl_8055D4A0 ^ 2;
    temp_r7 = (((u32)((temp_r3_4 >> 1) - (temp_r3_4 & lbl_8055D4A0)) >> 0x1FU) + 1) * 2;
    temp_r0_2 = (((u32)((temp_r0 >> 1) - (temp_r0 & lbl_8055D4A0)) >> 0x1FU) + 1) * 2;
    var_r4 = base + 0x1828;
    if (lbl_8055D4A0 > 0) {
        do {
            *(f32 *)(var_r4 + 0) = *(f32 *)((u8 *)var_r5 + 0);
            *(f32 *)(var_r4 + 4) = *(f32 *)((u8 *)var_r5 + 4);
            temp_f31 = (lbl_8056033C / (f32)temp_r7) - *(f32 *)((u8 *)var_r5 + 0);
            *(f32 *)(var_r4 + 8) = *(f32 *)((u8 *)var_r5 + 8);
            temp_f11 = *(f32 *)((u8 *)var_r5 + 0xC);
            temp_f8_2 = *(f32 *)((u8 *)var_r5 + 4);
            temp_f5_2 = *(f32 *)((u8 *)var_r5 + 8);
            *(f32 *)(var_r4 + 0xC) = *(f32 *)((u8 *)var_r5 + 0xC);
            *(f32 *)(var_r4 + 0x10) = *(f32 *)((u8 *)var_r5 + 0x10);
            var_r5 += 5;
            var_r4 += 0x14;
            *(f32 *)(var_r6 + 0) = temp_f31;
            temp_f7_2 = (lbl_80560340 / (f32)temp_r7) + temp_f11;
            temp_f2_2 = (lbl_80560344 / (f32)temp_r0_2) + temp_f8_2;
            temp_f3_2 = (lbl_805602FC / (f32)temp_r0_2) - temp_f5_2;
            *(f32 *)(var_r6 + 0xC) = temp_f7_2;
            *(f32 *)(var_r6 + 4) = temp_f2_2;
            *(f32 *)(var_r6 + 8) = temp_f3_2;
            *(f32 *)(var_r6 + 0x10) = (temp_f2_2 + temp_f3_2) * lbl_8056025C;
            *(f32 *)(var_r6 + 0x14) = (temp_f31 + temp_f7_2) * lbl_8056025C;
            var_r6 += 0x18;
            var_ctr -= 1;
        } while (var_ctr != 0);
    }
    lbl_8055D4A4 = 1;
}

f32 fn_80011DC0(s32 arg0) {
    return lbl_80350F28[arg0][0];
}

f32 fn_80011DD4(s32 arg0) {
    return lbl_80350F28[arg0][1];
}

f32 fn_80011DEC(s32 arg0) {
    return lbl_80350F28[arg0][2];
}

f32 fn_80011E04(s32 arg0) {
    return lbl_80350F28[arg0][4];
}

f32 fn_80011E1C(s32 arg0) {
    return lbl_80350F28[arg0][5];
}

f32 fn_80011E34(void) {
    return lbl_80350EC4[1];
}

f32 fn_80011E44(void) {
    return lbl_80350EC4[2];
}

f32 fn_80011E54(void) {
    return lbl_80350EC4[0];
}

extern f32 lbl_80350EC4[];
f32 fn_80011E60(void) {
    return lbl_80350EC4[3];
}

f32 fn_80011E70(void) {
    f32 value;
    value = lbl_80350EC4[1] + lbl_80350EC4[2];
    return value * lbl_8056025C;
}

f32 fn_80011E90(void) {
    f32 value;
    value = lbl_80350EC4[0] + lbl_80350EC4[3];
    return value * lbl_8056025C;
}

f32 fn_80011EB0(s32 arg0) {
    return lbl_80350ED8[arg0 * 5 + 2];
}

f32 fn_80011EC8(s32 arg0) {
    return lbl_80350ED8[arg0 * 5];
}

__declspec(section ".sdata") extern char lbl_80558ACC[];
extern int sprintf(char *, const char *, ...);
#pragma push
#pragma processor 750
#pragma scheduling on
#pragma dont_inline on
f32 fn_80011EDC(void) {
    char buffer[0x10];
    f32 scale;
    f32 best;
    f32 value;
    s32 i;

    scale = lbl_805602C8;
    best = lbl_80560280;
    i = 0;
    do {
        sprintf(buffer, lbl_80558ACC, (char)(i + 0x30));
        value = scale * ((f32 (*)(s32, char *, f32))fn_8023293C)(
            lbl_8055D490, buffer, lbl_80560264);
        if (value > best) {
            best = value;
        }
        i++;
    } while (i < 10);

    return best;
}
#pragma pop

void fn_80011F64(void) {
    extern s32 *fn_801284F8(s32, const char *);
    extern s32 fn_80207848(void *, s32);
    extern void fn_801331C4(s32, void *, f32 *);
    extern char lbl_802FC550[];
    extern char lbl_802FC560[];
    extern char lbl_802FC570[];
    extern char lbl_802FC580[];
    extern s32 *lbl_8055D4AC;
    f32 sp8;
    register f32 value;
    s32 *temp_r3;
    s32 var_r29;
    s32 *var_r28;
    s32 var_r29_2;
    s32 *var_r28_2;
    register s32 *var_r3;
    register s32 var_ctr;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;

    temp_r3 = fn_801284F8(0x1C, lbl_802FC550);
    if (temp_r3 != 0) {
        *temp_r3 = 0;
        var_r28 = temp_r3;
        var_r29 = 0;
        do {
            temp_r4 = (void *)fn_80207848(lbl_802FC570, 0);
            var_r29++;
            var_r28[1] = (s32)temp_r4;
            var_r28++;
        } while (var_r29 < 3);
        var_r28_2 = temp_r3;
        var_r29_2 = 0;
        do {
            temp_r4 = (void *)fn_80207848(lbl_802FC560, 0);
            var_r29_2++;
            var_r28_2[4] = (s32)temp_r4;
            var_r28_2++;
        } while (var_r29_2 < 3);
        sp8 = lbl_80560264;
        fn_801331C4(4, (void *)lbl_802FC580, &sp8);
        var_ctr = 2;
        var_r3 = temp_r3;
        do {
            temp_r4 = (void *)var_r3[1];
            if (temp_r4 != 0) {
                value = sp8;
                if (value != *(f32 *)((char *)temp_r4 + 8)) {
                    *((u8 *)temp_r4 + 0x4D) = 1;
                    *(f32 *)((char *)temp_r4 + 8) = value;
                }
            }
            temp_r4_2 = (void *)var_r3[2];
            if (temp_r4_2 != 0) {
                value = sp8;
                if (value != *(f32 *)((char *)temp_r4_2 + 8)) {
                    *((u8 *)temp_r4_2 + 0x4D) = 1;
                    *(f32 *)((char *)temp_r4_2 + 8) = value;
                }
            }
            temp_r4_3 = (void *)var_r3[3];
            if (temp_r4_3 != 0) {
                value = sp8;
                if (value != *(f32 *)((char *)temp_r4_3 + 8)) {
                    *((u8 *)temp_r4_3 + 0x4D) = 1;
                    *(f32 *)((char *)temp_r4_3 + 8) = value;
                }
            }
            var_r3 += 3;
            var_ctr--;
        } while (var_ctr != 0);
    }
    lbl_8055D4AC = temp_r3;
}

extern s32 *lbl_8055D4AC;
extern void fn_80128668(void *);
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_800120BC(void) {
    struct Dummy {
        virtual void release(s32);
        virtual void v1();
    };
    register s32 *base = lbl_8055D4AC;
    if (base != 0) {
        register s32 *outer = base;
        register s32 i = 0;
        for (; i < 2; ++i, outer += 3) {
            register s32 *inner = outer;
            register s32 j = 0;
            for (; j < 3; ++j, ++inner) {
                void *object = *(void **)(inner + 1);
                if (object == 0)
                    goto next;
                if (object == 0)
                    goto next;
                ((struct Dummy *)object)->release(1);
            next:
                ;
            }
        }
        fn_80128668(base);
    }
    lbl_8055D4AC = 0;
}
#pragma cplusplus reset
void fn_80012158(void) {
    register u8 *obj;
    register s32 *base;
    s32 n;

    base = (s32 *)lbl_8055D4AC;
    obj = *(u8 **)((u8 *)base + base[0] * 4 + 4);
    if (obj == 0) return;
    obj[0x49] = 1;
    obj[0x4B] = 0;
    obj[0x4A] = 0;
    n = base[0];
    n++;
    base[0] = n;
    if (n < 3) return;
    base[0] = 0;
}

void fn_800121A4(void) {
    u8 *obj;
    s32 *base;
    s32 n;
    s32 zero;

    base = (s32 *)lbl_8055D4AC;
    obj = *(u8 **)((u8 *)base + base[0] * 4 + 0x10);
    if (obj == 0) return;
    obj[0x49] = 1;
    zero = 0;
    obj[0x4B] = zero;
    obj[0x4A] = zero;
    n = base[0] + 1;
    base[0] = n;
    if (n < 3) return;
    base[0] = zero;
}

extern void fn_801331C4(s32, void *, f32 *);
extern char lbl_802FC580[];
__declspec(section ".data") extern char lbl_802FC580[];
#pragma unroll off
#pragma optimize_for_size on
#pragma scheduling invalid_target
void fn_800121F0(void) {
    f32 sp8;
    s32 *var_r3;
    s32 var_ctr;
    void *temp_r4;

    sp8 = lbl_80560264;
    var_r3 = (s32 *)lbl_8055D4AC;
    fn_801331C4(4, (void *)lbl_802FC580, &sp8);
    var_ctr = 2;
    do {
        temp_r4 = (void *)var_r3[1];
        if (temp_r4 != 0 && sp8 != *(f32 *)((u8 *)temp_r4 + 8)) {
            *((u8 *)temp_r4 + 0x4D) = 1;
            *(f32 *)((u8 *)temp_r4 + 8) = sp8;
        }
        temp_r4 = (void *)var_r3[2];
        if (temp_r4 != 0 && sp8 != *(f32 *)((u8 *)temp_r4 + 8)) {
            *((u8 *)temp_r4 + 0x4D) = 1;
            *(f32 *)((u8 *)temp_r4 + 8) = sp8;
        }
        temp_r4 = (void *)var_r3[3];
        if (temp_r4 != 0 && sp8 != *(f32 *)((u8 *)temp_r4 + 8)) {
            *((u8 *)temp_r4 + 0x4D) = 1;
            *(f32 *)((u8 *)temp_r4 + 8) = sp8;
        }
        var_r3 += 3;
        var_ctr -= 1;
    } while (var_ctr != 0);
}
#pragma scheduling on
#pragma optimize_for_size reset
#pragma unroll reset
s32 fn_800122B4(s32 arg0, s32 arg1) {
    struct { char sp8[0x14]; volatile s32 sp1C; } frame;

    fn_801310B4(frame.sp8, 0x14, arg0);
    frame.sp1C = fn_80130FE0(arg0);
    strcpy((char *)arg1, frame.sp8);
    return arg1;
}

void fn_8000F158(void) {
    fn_802328D4(lbl_8055D498);
    fn_80234470();
    lbl_8055D490 = 0;
}

extern void fn_801310B4(void *, s32, s32);
extern s32 fn_80130FE0(s32);
extern char *strcpy(char *, const char *);
extern f32 lbl_805602B8;
extern f32 lbl_805602BC;
extern char lbl_802FC3A4[];
extern f64 lbl_80560278;
extern f64 fn_8002EFB4(f64);
extern void fn_801E7E18(void);
extern s32 lbl_802FC2A8[];
s32 fn_8000DFA8(s32 arg0) {
    return lbl_802FC2A8[arg0 * 3 + 1];
}

s32 fn_8000DFC0(s32 arg0) {
    return lbl_802FC2A8[arg0 * 3 + 2];
}

void fn_8000DFD8(void *arg0, s32 arg1, f32 farg0, f32 farg1) {
    s32 count, mode, value;
    f32 x, y;
    void (*draw)(s32,f32,f32,f32,f32)=(void (*)(s32,f32,f32,f32,f32))fn_800109E4;
    count=*(s32*)((u8*)arg0+0x34);
    if(count>0 && *(s32*)((u8*)arg0+0x38)==9) {
        value=((s32)((f32)count*lbl_80560258)<<24)|0x00FDB300;
        y=farg1+lbl_80560254*lbl_8056025C;
        draw(value,farg0,y,lbl_80560250,lbl_80560254);
    }
    mode=*(s32*)((u8*)arg0+0x30);
    x=((f32)mode*lbl_80560250)/lbl_80560260;
    y=farg1+lbl_80560254*lbl_8056025C;
    draw(-1,farg0,y,x,lbl_80560254);
    mode=*(s32*)((u8*)arg0+0x2C);
    x=((f32)mode*lbl_80560250)/lbl_80560260;
    y=farg1+lbl_80560254*lbl_8056025C;
    draw(arg1,farg0,y,x,lbl_80560254);
    ((void (*)(s32,s32,const char*,void*,f32,f32,f32))fn_80010074)(-1,0x14,(const char*)&lbl_80558AA4,arg0,lbl_80560264,farg0+lbl_80560250*lbl_8056025C,farg1);
}

extern f32 lbl_80560250, lbl_80560254, lbl_80560258, lbl_8056025C, lbl_80560260, lbl_80560264, lbl_80560270;
void fn_8000E15C(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 count = *(s32 *)((char *)arg0 + 0x34);
    if (count > 0 && *(s32 *)((char *)arg0 + 0x38) == 9) {
        ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
            (u32)(((s32)((f32)count * lbl_80560258) << 24) | 0x00FDB300),
            arg2, arg3 + lbl_80560254 * lbl_8056025C,
            lbl_80560250, lbl_80560254);
    }
    ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
        (u32)-1, arg2, arg3 + lbl_80560254 * lbl_8056025C,
        ((f32)*(s32 *)((char *)arg0 + 0x30) * lbl_80560250) / lbl_80560260,
        lbl_80560254);
    ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
        (u32)arg1, arg2, arg3 + lbl_80560254 * lbl_8056025C,
        ((f32)*(s32 *)((char *)arg0 + 0x2C) * lbl_80560250) / lbl_80560260,
        lbl_80560254);
    ((void (*)(s32, s32, const char *, void *, f32, f32, f32))fn_80010074)(
        -1, 0x11, (const char *)&lbl_80558AA4, arg0,
        lbl_80560264, lbl_80560270 + arg2, arg3);
}

s32 fn_8000E2D8(s32 arg0) {
    switch (arg0) {
    default:
    case 0:
        return -1;
    case 1:
        return -0x29FFC4;
    case 2:
        return 0xFF2DC82D;
    case 3:
        return 0xFF2D2DC8;
    case 4:
        return -0x100;
    }
}

s32 fn_8000E338(s32 arg0) {
    s32 var_r3;
    if (arg0 <= 0xF) {
        if ((f32)((f64 (*)(f32, f64))fn_8002EFB4)(
                ((f32 (*)(void))fn_801E7E18)(), lbl_80560278) > lbl_8056025C)
            return -1;
    }
    if (arg0 <= 0x28) return 0xFFF70000;
    var_r3 = 0xFF278F27;
    if (arg0 <= 0x46) var_r3 = 0xFFE5A703;
    return var_r3;
}

f32 fn_8000EDC0(s32 arg0) {
    if (fn_801E85A4() > 2)
        return lbl_80560264;
    switch (arg0) {
    case 12:
    case 14:
        return lbl_805602B8;
    case 13:
        return lbl_805602BC;
    case 11:
        return lbl_80560264;
    default:
        fn_802E317C(&lbl_802FC3A4, arg0);
        return lbl_80560264;
    }
}

s32 fn_8000EE54(s32 arg0) {
    switch (arg0) {
    case 13:
        return -0x5400;
    case 11:
        return -1;
    case 12:
    case 14:
        return -0x5400;
    default:
        fn_802E317C(lbl_802FC3DC, arg0);
        return -1;
    }
}

#pragma dont_inline on
f32 fn_8000EEC8(s32 arg0, f32 arg1) {
    f32 f1;
    f32 f31;
    if (fn_801E85A4() == 1) {
        if (arg0 < 0) f1 = fn_80011E54();
        else f1 = fn_80011DC0(arg0);
        return f1 - lbl_80560260;
    }
    if (arg0 < 0) f1 = fn_80011E90();
    else {
        f31 = lbl_805602C4 * fn_80011DC0(arg0);
        f1 = (fn_80011E1C(arg0) * lbl_805602C0) + f31;
    }
    return f1 + (lbl_8056025C * arg1);
}

#pragma use_lmw_stmw off
void fn_8000EF74(s32 arg0) {
    extern f32 fn_8000EDC0(s32);
    extern s32 fn_8000EE54(s32);
    extern f32 fn_8000EEC8(s32, f32);
    extern void fn_80010074(s32, s32, const char *, f32, f32, f32, ...);
    extern f32 fn_80011E70(void);
    u8 *root;
    u8 *entry;
    s32 i;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    if (*(s32 *)((u8 *)&lbl_803514A0 + 0x288) != 0) {
        if (arg0 < 0) temp_f29 = fn_80011E70();
        else temp_f29 = fn_80011E04(arg0);
        entry = (u8 *)&lbl_803514A0;
        root = entry;
        temp_f30 = lbl_80560280;
        i = 0;
        while (i < *(s32 *)(root + 0x288)) {
            temp_f30 += fn_8000EDC0(*(s32 *)(entry + 0x40));
            entry += 0x40;
            i++;
        }
        temp_f30 *= (f32)lbl_80558A90;
        temp_f28 = fn_8000EEC8(arg0, temp_f30);
        temp_f31 = lbl_8056025C;
        entry = root + 8;
        i = 0;
        while (i < *(s32 *)(root + 0x288)) {
            temp_f27 = fn_8000EDC0(*(s32 *)(entry + 0x38));
            temp_f26 = temp_f27 * (f32)lbl_80558A90;
            temp_f25 = temp_f28 - temp_f31 * temp_f26;
            fn_80010074(fn_8000EE54(*(s32 *)(entry + 0x38)), 0x14,
                        (const char *)entry, temp_f27, temp_f29, temp_f25);
            temp_f28 -= temp_f26;
            entry += 0x40;
            i++;
        }
    }
}

#pragma dont_inline reset
void fn_8000F0E4(void) {
    s32 val;
    f32 f1;

    val = fn_8023441C();
    lbl_8055D490 = val;
    f1 = (f32)fn_80232B70(val);
    lbl_80558A90 = (s32)(lbl_805602C8 * f1);
    *(f32 *)&lbl_8055D49C = fn_80011EDC();
    lbl_8055D498 = fn_80232578((s32)lbl_802FC414);
}

