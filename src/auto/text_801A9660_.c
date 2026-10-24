#include "revolution/MTX/vec.h"
struct FnTable_801ADA9C { char pad[0x18]; void (*call)(void *, void *, void *); };
struct Obj_801ADA9C { struct FnTable_801ADA9C *vtable; };
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on

extern void fn_8017A57C(void) __attribute__((noreturn));
extern void fn_801AC240(void *);
extern void fn_801AC254(void *);
extern void fn_801ABFF8(int **);
extern int lbl_80335940;
extern float lbl_805624D0;

extern void fn_8017B0B0(void *);
extern int lbl_8033585C[64];
extern float lbl_8055E3C8;
extern void fn_80179EE8(void *, unsigned int);
extern void fn_80128668(void *);
extern void *fn_801792F8(void);
extern void *fn_801284F8(int, ...);
extern int lbl_8055E5E4;
extern int lbl_8055E5EC;
extern int lbl_8055E5F0;
extern char lbl_80335718[];
extern char lbl_80335744[];
extern char lbl_80335808[];
extern void *lbl_80435628[];
extern void fn_802E317C(const char *, ...);
extern void **fn_801A9700(void **);
extern int lbl_8055E3C4;
extern int lbl_8055A858;
extern int jumptable_80335578[];
void fn_801A9660(void) {
    unsigned int index = *(unsigned int *)((char *)fn_801792F8() + 0x50) - 6;
    if (index < 0x11) {
        ((void (*)(void))jumptable_80335578[index])();
        return;
    }
    if (fn_801284F8(0x23c, &lbl_8055A858) != 0) fn_801A9700(0);
}

#pragma scheduling off
void** fn_801A9700(void** arg0) {
    fn_8017B0B0(arg0);
    *arg0 = &lbl_8033585C;
    return arg0;
}
#pragma scheduling on
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801A973C(void *this_, int flag) {
    if (this_) {
        if (this_ != 0) fn_80179EE8(this_, 0);
        if (flag > 0) fn_80128668(this_);
    }
    return this_;
}

extern void *fn_801AE180(void);
extern f32 lbl_80562478, lbl_8056247C;
#pragma scheduling invalid_target
void fn_801A9798(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    struct Node_801A9798 { void *next; f32 values[9]; };
    register struct Node_801A9798 *node;
    volatile f32 sp64, sp60, sp5c, sp58, sp54, sp50, sp4c, sp48, sp44;
    volatile f32 sp40, sp3c, sp38, sp34, sp30, sp2c, sp28, sp24, sp20;
    volatile f32 sp1c, sp18, sp14, sp10, spC, sp8;
    register f32 constA, constB;
    sp60 = farg1; sp5c = -farg0; sp64 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp5c; node->values[1] = sp60; node->values[2] = sp64; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp50 = farg0; sp54 = farg1; sp58 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp50; node->values[1] = sp54; node->values[2] = sp58; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp48 = farg1; sp44 = -farg0; sp4c = farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp44; node->values[1] = sp48; node->values[2] = sp4c; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp38 = farg0; sp3c = farg1; sp40 = farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp38; node->values[1] = sp3c; node->values[2] = sp40; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp2c = -farg0; sp30 = -farg1; sp34 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp2c; node->values[1] = sp30; node->values[2] = sp34; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp20 = farg0; sp24 = -farg1; sp28 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp20; node->values[1] = sp24; node->values[2] = sp28; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp1c = farg2; sp14 = -farg0; sp18 = -farg1;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp14; node->values[1] = sp18; node->values[2] = sp1c; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp8 = farg0; spC = -farg1; sp10 = farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp8; node->values[1] = spC; node->values[2] = sp10; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
}
#pragma scheduling on
void fn_801ABB54(void *arg0) {
    extern float lbl_80562478, lbl_8056247C, lbl_805624A4, lbl_805624AC, lbl_805624D8;
    float dot, magnitude, sign, limit;
    float unused, scale;
    double absolute;
    float z, y, x;
    char *p = arg0;
    dot = PSVECDotProduct((Vec *)(p + 0x124), (Vec *)(p + 0x54));
    limit = *(float *)(p + 0x238);
    scale = lbl_8056247C;
    absolute = __fabs(dot);
    magnitude = (float)absolute;
    if (magnitude > limit) {
        limit = limit < magnitude ? limit : magnitude;
        if (dot > lbl_8056247C) sign = lbl_805624AC;
        else sign = lbl_805624A4;
        scale = -sign * limit;
    } else if (magnitude > lbl_805624D8) {
        scale = -dot * lbl_80562478;
    }
    x = *(float *)(p + 0x54) * scale;
    y = *(float *)(p + 0x58) * scale;
    z = *(float *)(p + 0x5C) * scale;
    y = *(float *)(p + 0x128) + y;
    x = *(float *)(p + 0x124) + x;
    z = *(float *)(p + 0x12C) + z;
    *(float *)(p + 0x128) = y;
    *(float *)(p + 0x124) = x;
    *(float *)(p + 0x12C) = z;
}

extern void fn_8017B81C(void *);
extern void fn_8017C7C8(void *, float *, float *);
extern float lbl_805624AC, lbl_805624DC, lbl_805624E0, lbl_805624E4;
#pragma cplusplus on
extern "C" void fn_801ABC28(void *arg0) {
    extern void fn_8017A580(void *, int, int, int, int, int, int, int);
    extern void fn_801796CC(int, void *, int);
    struct Work {
        float first[3];
        float second[3];
        Vec output;
        void *object;
        unsigned char flag;
    } work;
    char *p = (char *)arg0;
    register int t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    int flag;
    float first, scale;

    if (*(unsigned char *)(p + 0x222) != 0) {
        *(unsigned char *)(p + 0x1e9) = 0;
        fn_8017C7C8(arg0, work.second, work.first);
        return;
    }
    if (PSVECDotProduct((Vec *)(p + 0x118), (Vec *)(p + 0x118)) > lbl_805624DC ||
        PSVECDotProduct((Vec *)(p + 0x124), (Vec *)(p + 0x124)) > lbl_805624DC) {
        if (*(float *)(p + 0x64) > lbl_805624E0)
            fn_801AC240(arg0);
    }
    if (*(unsigned char *)(p + 0x220) != 0) {
        if (lbl_8055E3C4 == 1 ||
            lbl_8055E3C8 > lbl_805624AC + *(float *)(p + 0x21c)) {
            fn_801AC254(arg0);
            scale = lbl_8056247C;
            *(float *)(p + 0x124) = scale;
            *(float *)(p + 0x128) = scale;
            *(float *)(p + 0x12c) = scale;
            *(float *)(p + 0x118) = scale;
            *(float *)(p + 0x11c) = scale;
            *(float *)(p + 0x120) = scale;
        } else if (*(unsigned char *)(p + 0x221) == 0) {
            fn_8017B81C(arg0);
            #pragma scheduling off
            {
                float a, b, c, d, e, f;
                float r0, r1, r2, r3, r4, r5, check;
                a = *(volatile float *)(p + 0x118);
                scale = *(volatile float *)&lbl_805624E4;
                b = *(volatile float *)(p + 0x11c);
                r0 = a * scale;
                c = *(volatile float *)(p + 0x120);
                r1 = b * scale;
                d = *(volatile float *)(p + 0x124);
                r2 = c * scale;
                e = *(volatile float *)(p + 0x128);
                r3 = d * scale;
                f = *(volatile float *)(p + 0x12c);
                r4 = e * scale;
                r5 = f * scale;
                check = *(volatile float *)(p + 0x238);
                *(float *)(p + 0x118) = r0;
                *(float *)(p + 0x11c) = r1;
                *(float *)(p + 0x120) = r2;
                *(float *)(p + 0x124) = r3;
                *(float *)(p + 0x128) = r4;
                *(float *)(p + 0x12c) = r5;
                if (check > lbl_8056247C)
                    fn_801ABB54(arg0);
            }
            #pragma scheduling on
            flag = 0;
            if (*(unsigned char *)(p + 0x234) != 0 &&
                *(float *)(p + 0x4c) > lbl_80562478)
                flag = 1;
            *(unsigned char *)(p + 0x234) = (unsigned char)flag;
        } else {
            fn_8017B81C(arg0);
            t0 = *(int *)(p + 0x1ec);
            t1 = *(int *)(p + 0x1f0);
            t2 = *(int *)(p + 0x1f4);
            t3 = *(int *)(p + 0x1f8);
            t4 = *(int *)(p + 0x1fc);
            t5 = *(int *)(p + 0x200);
            t6 = *(int *)(p + 0x204);
            t7 = *(int *)(p + 0x208);
            t8 = *(int *)(p + 0x20c);
            t9 = *(int *)(p + 0x210);
            t10 = *(int *)(p + 0x214);
            t11 = *(int *)(p + 0x218);
            scale = lbl_8056247C;
            *(float *)(p + 0x124) = scale;
            *(float *)(p + 0x128) = scale;
            *(float *)(p + 0x12c) = scale;
            *(float *)(p + 0x118) = scale;
            *(float *)(p + 0x11c) = scale;
            *(float *)(p + 0x120) = scale;
            *(int *)(p + 0x3c) = t0;
            *(int *)(p + 0x40) = t1;
            *(int *)(p + 0x44) = t2;
            *(int *)(p + 0x48) = t3;
            *(int *)(p + 0x4c) = t4;
            *(int *)(p + 0x50) = t5;
            *(int *)(p + 0x54) = t6;
            *(int *)(p + 0x58) = t7;
            *(int *)(p + 0x5c) = t8;
            *(int *)(p + 0x60) = t9;
            *(int *)(p + 0x64) = t10;
            *(int *)(p + 0x68) = t11;
            ((void (*)(void *))fn_8017A580)(arg0);
        }
        if (*(float *)(p + 0x64) < lbl_805624E0) {
            struct Dummy { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); };
            ((Dummy *)arg0)->d2();
        }
    }
    if (*(unsigned char *)(p + 0x235) != 0) {
        #pragma scheduling off
        if ((char *)&work.output == p + 0x228) {
            register float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
            f0 = *(volatile float *)(p + 0x7c);
            f6 = *(volatile float *)(p + 0x22c);
            f2 = *(volatile float *)(p + 0x80);
            f4 = f6 * f0;
            f11 = *(volatile float *)(p + 0x84);
            f1 = *(volatile float *)(p + 0x70);
            f2 = f6 * f2;
            f0 = *(volatile float *)(p + 0x228);
            f3 = *(volatile float *)(p + 0x74);
            f5 = f0 * f1;
            f10 = *(volatile float *)(p + 0x78);
            f3 = f0 * f3;
            f8 = *(volatile float *)(p + 0x88);
            f1 = f0 * f10;
            f0 = f6 * f11;
            f7 = *(volatile float *)(p + 0x230);
            f9 = *(volatile float *)(p + 0x8c);
            f5 = f5 + f4;
            f6 = f7 * f8;
            f12 = *(volatile float *)(p + 0x90);
            f3 = f3 + f2;
            f4 = f7 * f9;
            f0 = f1 + f0;
            f2 = f7 * f12;
            f5 = f6 + f5;
            f1 = f4 + f3;
            f0 = f2 + f0;
            work.output.x = f5;
            work.output.y = f1;
            work.output.z = f0;
        } else {
            work.output.x = *(float *)(p + 0x230) * *(float *)(p + 0x88) +
                (*(float *)(p + 0x228) * *(float *)(p + 0x70) +
                *(float *)(p + 0x22c) * *(float *)(p + 0x7c));
            work.output.y = *(float *)(p + 0x230) * *(float *)(p + 0x8c) +
                (*(float *)(p + 0x228) * *(float *)(p + 0x74) +
                *(float *)(p + 0x22c) * *(float *)(p + 0x80));
            work.output.z = *(float *)(p + 0x230) * *(float *)(p + 0x90) +
                (*(float *)(p + 0x228) * *(float *)(p + 0x78) +
                *(float *)(p + 0x22c) * *(float *)(p + 0x84));
        }
        #pragma scheduling invalid_target
        work.output.x += *(float *)(p + 0x94);
        work.output.y += *(float *)(p + 0x98);
        work.output.z += *(float *)(p + 0x9c);
        work.object = arg0;
        work.flag = *(unsigned char *)(p + 0x234);
        fn_801796CC(9, &work.output, 0x14);
    }
    *(int *)(p + 0x1e4) = 0;
}
#pragma cplusplus reset

#pragma scheduling on
void fn_801ABFF4(void) {
    fn_8017A57C();
}

#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma use_lmw_stmw off
void fn_801AC0A0(void *arg0, float *arg1, float *arg2, int arg3, int arg4) {
 extern float lbl_805624E8;
 extern int lbl_803357F0[];
 extern void fn_8017D2C8(void *, void *, void *, int, int);
 struct { void *v; float a[3], b[3]; int c,d; } event;
 float value, scale, squared;
 float z2,y2,x2,z,y,x;
 if(arg3>=100 && *((unsigned char *)arg0+0x220)==0) {
 value=*(float *)((char *)arg0+0xD4);
 scale=lbl_805624E8 * value;
 squared=scale*scale;
 if(PSVECDotProduct((Vec *)arg1,(Vec *)arg1)>squared) {
 x=arg1[0]; y=arg1[1]; z=arg1[2];
 x2=arg2[0]; y2=arg2[1]; z2=arg2[2];
 event.v=lbl_803357F0;
 event.a[0]=x; event.a[1]=y; event.a[2]=z;
 event.b[0]=x2; event.b[1]=y2; event.b[2]=z2;
 event.c=arg3; event.d=arg4;
 ((void (*)(void *, void *))fn_801ABFF8)(arg0,&event);
 }
 }
 fn_8017D2C8(arg0,arg1,arg2,arg3,0);
}
#pragma pop

extern void fn_8017A580(void *, int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
void fn_801AC184(void *arg0) {
    int t11, t3, t2, t1, t0, t4, t5, t6, t7, t8, t9, t10;
    fn_801AC240(arg0);
    t0 = *(volatile int *)((char *)arg0 + 0x1EC);
    t1 = *(volatile int *)((char *)arg0 + 0x1F0);
    t2 = *(volatile int *)((char *)arg0 + 0x1F4);
    t3 = *(volatile int *)((char *)arg0 + 0x1F8);
    t4 = *(volatile int *)((char *)arg0 + 0x1FC);
    t5 = *(volatile int *)((char *)arg0 + 0x200);
    t6 = *(volatile int *)((char *)arg0 + 0x204);
    t7 = *(volatile int *)((char *)arg0 + 0x208);
    t8 = *(volatile int *)((char *)arg0 + 0x20C);
    t9 = *(volatile int *)((char *)arg0 + 0x210);
    t10 = *(volatile int *)((char *)arg0 + 0x214);
    t11 = *(volatile int *)((char *)arg0 + 0x218);
    *(int *)((char *)arg0 + 0x3C) = t0;
    *(int *)((char *)arg0 + 0x40) = t1;
    *(int *)((char *)arg0 + 0x44) = t2;
    *(int *)((char *)arg0 + 0x48) = t3;
    *(int *)((char *)arg0 + 0x4C) = t4;
    *(int *)((char *)arg0 + 0x50) = t5;
    *(int *)((char *)arg0 + 0x54) = t6;
    *(int *)((char *)arg0 + 0x58) = t7;
    *(int *)((char *)arg0 + 0x5C) = t8;
    *(int *)((char *)arg0 + 0x60) = t9;
    *(int *)((char *)arg0 + 0x64) = t10;
    *(int *)((char *)arg0 + 0x68) = t11;
    fn_8017A580(arg0, t10, t9, t8, t7, t6, t5, t4);
    fn_8017B164(arg0);
    *(unsigned char *)((char *)arg0 + 0x223) = 1;
    *(unsigned char *)((char *)arg0 + 0x234) = *(unsigned char *)((char *)arg0 + 0x235);
}

#pragma dont_inline on
void fn_801AC240(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x220) = 1;
    *(float *)((char *)arg0 + 0x21C) = lbl_8055E3C8;
}
#pragma dont_inline off

void fn_801AC254(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x220) != 0) {
        *(unsigned char *)((char *)arg0 + 0x220) = 0;
    }
}

void *fn_801AC26C(void) {
    const char *name = lbl_80335718;
    void *obj = ((void *(*)(int, const char *))fn_801284F8)(0x244, name);
    if (obj != 0) {
        fn_801A9700(obj);
        *(void **)obj = &lbl_80335744;
        *(void **)((char *)obj + 0x23C) = (char *)&lbl_80335744 + 0x54;
    }
    return obj;
}

void *fn_801AC2C8(void *arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055E5E4 = 0;
        if (arg0 != 0 && arg0 != 0) fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_801AC330(void *arg0) {
    fn_801A9700(arg0);
    *(void **)arg0 = &lbl_80335808;
    if (lbl_8055E5EC == 0) {
        lbl_8055E5F0 = 0;
    }
    *(int *)((char *)arg0 + 0x250) = lbl_8055E5EC;
    lbl_8055E5EC = lbl_8055E5EC + 1;
    lbl_80435628[*(int *)((char *)arg0 + 0x250)] = arg0;
    *(int *)((char *)arg0 + 0x254) = -1;
    return arg0;
}

extern void fn_801C1C7C(void);
void **fn_801AC3AC(void **arg0, int arg1) {
    if (arg0 != 0) {
        *arg0 = lbl_80335808;
        lbl_8055E5EC = lbl_8055E5EC - 1;
        if (lbl_8055E5EC == 0) {
            int ptr = lbl_8055E5F0;
            if (ptr != 0) {
                ((void (*)(int))fn_801C1C7C)(ptr);
                lbl_8055E5F0 = 0;
            }
        }
        if (arg0 != 0) {
            lbl_8055E5E4 = 0;
            if (arg0 != 0 && arg0 != 0) fn_80179EE8(arg0, 0);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
#pragma scheduling off
void fn_801AC508(void) {
    s32 value = lbl_8055E5EC;
    if (value > 0) {
        lbl_8055E5F0 = fn_801C1BA4(value * 5, value * 5 - 1);
    }
}
#pragma scheduling on
#pragma dont_inline reset

#pragma push
#pragma scheduling 750
void fn_801ACA48(void *arg0) {
    extern void fn_801ABC28(void *);
    extern float lbl_8056247C, lbl_805624CC, lbl_80562508, lbl_8056250C;
    Vec cross;
    float x, y, z;
    float scale, zero, input;
    float copyZ, copyY, copyX;
    char *p = arg0;
    fn_801ABC28(arg0);
    if (*(unsigned char *)(p + 0x220)) {
        input = *(float *)(p + 0x124);
        scale = lbl_805624CC;
        x = input * scale;
        y = *(float *)(p + 0x128) * scale;
        z = *(float *)(p + 0x12C) * scale;
        zero = lbl_8056247C;
        *(float *)(p + 0x118) = zero;
        *(float *)(p + 0x11C) = zero;
        *(float *)(p + 0x120) = zero;
        *(float *)(p + 0x124) = x;
        *(float *)(p + 0x128) = y;
        *(float *)(p + 0x12C) = z;
        PSVECCrossProduct((Vec *)(p + 0x48), (Vec *)(p + 0x1F8), &cross);
        if (*(float *)(p + 0x4C) < lbl_80562508) {
            float vz, vy, vx, factor, product;
            product = cross.x;
            factor = lbl_8056250C;
            vx = *(float *)(p + 0x124);
            vy = *(float *)(p + 0x128);
            vz = *(float *)(p + 0x12C);
            vx += product * factor;
            *(float *)(p + 0x124) = vx;
            vy += cross.y * factor;
            *(float *)(p + 0x128) = vy;
            vz += cross.z * factor;
            *(float *)(p + 0x12C) = vz;
        }
        copyX = *(float *)(p + 0x210);
        copyY = *(float *)(p + 0x214);
        copyZ = *(float *)(p + 0x218);
        *(float *)(p + 0x60) = copyX;
        *(float *)(p + 0x64) = copyY;
        *(float *)(p + 0x68) = copyZ;
    }
}

extern float lbl_80558DC4, lbl_8055E460, lbl_805624AC;
void fn_801ACB30(void *arg0, int arg1) {
    char *p = (char *)arg0;
    char *out = (char *)(arg1 + *(int *)(p + 8));
    float t = lbl_8055E460 - lbl_805624AC;
    int i;
    if (__fabsf(t) <= lbl_80558DC4) {
        for (i = 0; i < 12; i++) *(int *)(out + i*4) = *(int *)(p + 0x70 + i*4);
    } else {
        for (i = 0; i < 12; i++) {
            float a = *(float *)(p + 0x70 + i*4);
            float b = *(float *)(p + 0xA0 + i*4);
            *(float *)(out + i*4) = b + t * (a - b);
        }
    }
    *(short *)(out + 0x30) = *(short *)(p + 0x6C);
    if (*(void **)(p + 0x23C)) {
        float *v = (float *)(p + 0x244);
        float *q = (float *)(p + 0x244);
        for (i = 0; i < 3; i++) {
            float x = v[0] * *(float *)(p + 0x3C + i*4) +
                      v[1] * *(float *)(p + 0x48 + i*4) +
                      v[2] * *(float *)(p + 0x54 + i*4) +
                      *(float *)(p + 0x60 + i*4);
            *(float *)((char *)&t + i*4) = x;
        }
        for (i = 0; i < 3; i++) {
            float x = q[0] * *(float *)((char *)*(void **)(p + 0x23C) + 0x3C + i*4) +
                      q[1] * *(float *)((char *)*(void **)(p + 0x23C) + 0x48 + i*4) +
                      q[2] * *(float *)((char *)*(void **)(p + 0x23C) + 0x54 + i*4) +
                      *(float *)((char *)*(void **)(p + 0x23C) + 0x60 + i*4);
            *(float *)(p + 0x8 + i*4) = x;
        }
    }
}

extern int lbl_8055E5EC, lbl_8055E5F0;
extern float lbl_8056247C, lbl_805624AC, lbl_80562510;
extern void fn_801C2694(void *, int *, float *, float *, float *, float *, float, float);
extern void fn_801796CC(int, void *, int);
void fn_801ACF94(void) {
    char sp90[0x13C];
    int sp8[1];
    float *p;
    int i, j, count;
    void **obj;
    float *src;
    char sp3c[0x18];

    if (lbl_8055E5F0 != 0) {
        sp8[0] = 0x13C;
        *(float *)&sp8[1] = lbl_8056247C;
        p = (float *)((char *)sp8 + 4);
        p[1] = lbl_8056247C; p[2] = lbl_8056247C;
        p[3] = lbl_8056247C; p[4] = lbl_8056247C;
        p[5] = lbl_8056247C; p[6] = lbl_8056247C;
        p[7] = lbl_805624AC; p[8] = lbl_8056247C;
        p[9] = lbl_8056247C; p[10] = lbl_80562510;
        p[11] = lbl_8056247C;
        fn_801C2694(sp90, sp8, p + 8, p + 6, p + 4, p, lbl_805624AC, lbl_8056247C);
        obj = (void **)lbl_80435628;
        i = 0;
        j = 0;
        do {
            void *o = *obj;
            void *a = *(void **)((char *)o + 0x23C);
            if (a != 0) {
                int first = *(int *)((char *)a + 0x254);
                count = *(int *)((char *)o + 0x254) - first + 1;
                src = (float *)(sp90 + first * 12);
                *(int *)sp3c = j;
                *(int *)(sp3c + 4) = i;
                *(int *)(sp3c + 8) = count;
                for (i = 0; i < count; i++) {
                    *(float *)(sp3c + 12 + i * 12) = src[0];
                    *(float *)(sp3c + 16 + i * 12) = src[1];
                    *(float *)(sp3c + 20 + i * 12) = src[2];
                    src += 3;
                }
                fn_801796CC(6, sp3c, 0x54);
            }
            obj++;
            i = ++j;
        } while (j < lbl_8055E5EC);
    }
}

extern void fn_8017AB84(void *, Vec *, void *);
extern void fn_801AD0E0(void *, void *, void *, void *, f32, f32);
void fn_801AD28C(void *arg0, void *arg1, void *arg2, Vec *arg3, f32 farg0, f32 farg1) {
    Vec sp20;
    Vec sp14;
    Vec delta;
    f32 distance;
    fn_8017AB84(*(void **)((char *)arg0 + 0x34), &sp20, arg1);
    if (arg2 != 0) fn_8017AB84(arg2, &sp14, arg3);
    else sp14 = *arg3;
    delta.x = sp14.x - sp20.x;
    delta.y = sp14.y - sp20.y;
    delta.z = sp14.z - sp20.z;
    distance = PSVECMag(&delta);
    *(f32 *)((char *)arg0 + 0x28) = distance;
    fn_801AD0E0(arg0, arg3, arg2, arg1, farg0, farg1);
    *(f32 *)((char *)arg0 + 0x28) = distance;
}

#pragma pop
void fn_801AD5EC(void) {
    fn_801AC508();
}

void fn_801AD5F0(void) {
    fn_801ACF94();
}

extern void fn_801D0A24(void *, void *);
extern void fn_801AC0A0(void *, float *, float *, int, int);
extern void fn_801D09A8(void *, int);
extern void fn_801A9AB0(void);
extern void fn_801D08C0(void *);
extern void fn_801D0934(void *);
void *fn_801AD6B0(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80335744;
        *(void **)((char *)arg0 + 0x23C) = (char *)&lbl_80335744 + 0x54;
        fn_801D0934((char *)arg0 + 0x23C);
        *(int *)((char *)arg0 + 0x240) = 0;
        lbl_8055E5E4 = 0;
        fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling off
void fn_801AD7A4(void *arg0, void *arg1, void *arg2, int arg3) {
    void *obj;
    if (arg3 >= 8) return;
    if (arg0 == 0) return;
    obj = (char *)arg0 + 0x23C;
    fn_801D0A24(obj, arg2);
}
#pragma scheduling on
unsigned char fn_801AD860(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

long fn_801AD868(void) {
    return 0;
}

void fn_801AD870(void *arg0, void *arg1, void *arg2, long *arg3, long *arg4) {
    *arg4 = 0;
    *arg3 = 0;
}

long fn_801AD880(void) {
    return 0;
}

#pragma cplusplus on
struct Dummy_801AD888 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
};
#pragma cplusplus on
extern "C" void fn_801AD888(void *arg0) {
    ((Dummy_801AD888 *)arg0)->d2();
    ((void (*)(void *))fn_801AC254)(arg0);
}
#pragma cplusplus off

void fn_801AD8C8(void *arg0, int *arg1, float *arg2, float *arg3) {
    int l, k, j, i, h, g, f, e, d, c, b, a;
    float z1, y1, x1, z0, y0, x0;
    a=arg1[0]; b=arg1[1]; c=arg1[2]; d=arg1[3];
    e=arg1[4]; f=arg1[5]; g=arg1[6]; h=arg1[7];
    i=arg1[8]; j=arg1[9]; k=arg1[10]; l=arg1[11];
    *(int *)((char *)arg0+0x3c)=a;
    *(int *)((char *)arg0+0x40)=b;
    *(int *)((char *)arg0+0x44)=c;
    *(int *)((char *)arg0+0x48)=d;
    *(int *)((char *)arg0+0x4c)=e;
    *(int *)((char *)arg0+0x50)=f;
    *(int *)((char *)arg0+0x54)=g;
    *(int *)((char *)arg0+0x58)=h;
    *(int *)((char *)arg0+0x5c)=i;
    *(int *)((char *)arg0+0x60)=j;
    *(int *)((char *)arg0+0x64)=k;
    *(int *)((char *)arg0+0x68)=l;
    ((void (*)(void *))fn_8017A580)(arg0);
    x0=arg2[0]; y0=arg2[1]; z0=arg2[2];
    x1=arg3[0]; y1=arg3[1]; z1=arg3[2];
    *(float *)((char *)arg0+0x118)=x0;
    *(float *)((char *)arg0+0x11c)=y0;
    *(float *)((char *)arg0+0x120)=z0;
    *(float *)((char *)arg0+0x124)=x1;
    *(float *)((char *)arg0+0x128)=y1;
    *(float *)((char *)arg0+0x12c)=z1;
    fn_801AC240(arg0);
}

void fn_801AD99C(void *arg0, float *arg1, float *arg2) {
    float scale;
    float sp14[3];
    float sp8[3];
    scale = *(float *)((char *)arg0 + 0xD4) / lbl_805624D0;
    sp14[0] = arg1[0] * scale;
    sp14[1] = arg1[1] * scale;
    sp14[2] = arg1[2] * scale;
    sp8[0] = *(float *)((char *)arg0 + 0x60) + arg2[0];
    sp8[1] = *(float *)((char *)arg0 + 0x64) + arg2[1];
    sp8[2] = *(float *)((char *)arg0 + 0x68) + arg2[2];
    ((void (*)(float *, float *, int, int))(*(void ***)arg0)[18])(sp14, sp8, 100, 0);
}

void fn_801ADA38(void *arg0, int arg1) {
    int *sp8;
    if (arg1) {
        sp8 = &lbl_80335940;
        fn_801ABFF8(&sp8);
    } else {
        *((char *)arg0 + 0x220) = 0;
    }
}

unsigned char fn_801ADA7C(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

short fn_801ADA84(void *arg0) {
    return *(short *)((char *)arg0 + 0x6C);
}

long fn_801ADA8C(long arg0) { return arg0 + 0x118; }

long fn_801ADA94(long arg0) {
    return arg0 + 0x60;
}

extern float lbl_8055E3C8;
typedef void (*Fn801ADA9C)(void *, void *, void *);
extern unsigned char lbl_8055A8A0;
extern unsigned char lbl_8055A8B0;
void fn_801ADA9C(void *arg0) {
    struct Obj_801ADA9C *obj = *(struct Obj_801ADA9C **)((char *)arg0 + 0x240);
    obj->vtable->call(obj, &lbl_8055A8A0, &lbl_8055A8B0);
}

long fn_801ADAB8(void *arg0) {
    return *(long *)((char *)arg0 + 0x240);
}

void fn_801ADAC0(void *arg0, long arg1) {
    fn_801AC240((void *)arg1);
}
