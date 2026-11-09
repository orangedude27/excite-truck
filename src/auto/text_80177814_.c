#include <types.h>
#include <string.h>
#pragma ppc_psq_save off
extern void *lbl_8055E430;
extern char lbl_8055E45D;
extern char lbl_8055E45F;
extern int lbl_8055E450;
extern int lbl_8055E8F8;
#include <revolution/MTX/vec.h>
extern int lbl_8055E43C;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern unsigned char lbl_8055E45E;
extern int lbl_80430870[];
extern int lbl_80430590[];
extern int lbl_804305A0[];
extern int lbl_80430830[];

extern long fn_80178C1C(long *);
extern float lbl_80561B60;
void fn_80179EE8(void*, unsigned int);
void fn_80128668(void*);
extern unsigned char lbl_8055E46C;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055A304;
void fn_801DCEC8(int arg0, float arg1);
void fn_801DCEDC(int arg0, float arg1);
extern float lbl_804305D4[];
extern float lbl_80430700[];
extern float lbl_80561B48;
void fn_802E8518(int arg0);
extern int lbl_8055E3C0;
extern unsigned char lbl_8055E3BD;
int fn_801CF064(void);
int fn_8018FD38(void);
extern void *lbl_804340C0[];
extern void **lbl_8055E434;
extern int lbl_8055E438;
extern int lbl_8055E468;
extern int lbl_8055E448;
extern unsigned char lbl_8055E44C;
__declspec(section ".data") extern long lbl_80331938;
__declspec(section ".data") extern long lbl_8033192C;
extern void fn_801AFD20(void *);
extern void fn_8017ACCC(void);
extern void fn_8018A180(void);
int fn_802E2C20(void);
extern int lbl_8055E464;
void fn_80177814(int *arg0) {
    int t;
    t = fn_802E2C20() + lbl_8055E464;
    *arg0 = t % 30000;
    lbl_8055E464 += 0x9947;
    t = fn_802E2C20() + lbl_8055E464;
    arg0[1] = t % 30000;
    lbl_8055E464 += 0x2F1CD;
}

#pragma dont_inline on
void fn_801778C0(void) {
    void **var_r31 = &lbl_804340C0[0];
    void **var_r28;
    int var_r30 = 0;
    int var_r29 = 0;

    lbl_8055E468 = 0;
    for (; var_r29 < lbl_8055E438; var_r29++, var_r30 += 4) {
        var_r28 = *(void **)(lbl_8055E434 + var_r30);
        if (((int (*)(void **))(*(void ***)*var_r28 + 0x44))(var_r28) != 0 &&
            ((int (*)(void **))(*(void ***)*var_r28 + 0x40))(var_r28) != 0) {
            var_r31[lbl_8055E468] = var_r28;
            lbl_8055E468 += 1;
        }
    }
}

#pragma dont_inline off
long fn_80177980(void) {
    return 0;
}

long fn_80177988(void) {
    return 1;
}

void fn_80177990(void) {
    double temp_f31 = lbl_80561B48;
    float *var_r31 = &lbl_80430700[0];
    float *var_r30 = &lbl_804305D4[0];
    int var_r29;

    for (var_r29 = 0; var_r29 < 0x4b; var_r29++) {
        *var_r31 = (float)temp_f31;
        *var_r30 = (float)temp_f31;
        fn_801DCEC8(var_r29, (float)temp_f31);
        fn_801DCEDC(var_r29, lbl_80561B48);
        var_r31++;
        var_r30++;
    }
}

#pragma dont_inline on
void fn_80177A18(void) {
    int var_r31;

    var_r31 = 0;
    do {
        fn_802E8518(var_r31);
        var_r31 += 1;
    } while (var_r31 < 4);
}

void fn_80177A54(void) {
    if (lbl_8055E3C0 == 2 && fn_801CF064() != 0 && fn_8018FD38() != 0) {
        lbl_8055E3C0 = 0;
    }
    switch (lbl_8055E3C0) {
    case 1:
        if (lbl_8055E3BD == 0) {
            fn_80177A18();
        }
        lbl_8055E3BD = 1;
        break;
    case 2:
        lbl_8055E3BD = 0;
        break;
    default:
        break;
    }
    lbl_8055E3C0 = 0;
}
#pragma dont_inline off

#pragma cplusplus on
extern "C" void fn_80177CEC(void) {
    class RotationObject {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual int isValid();
    };
    int index = lbl_8055E43C;
    RotationObject *object;
    Vec right;
    Vec up;
    Vec forward;
    float a, b, c, d, e, f;
    if (index >= lbl_8055E438) { index = 0; lbl_8055E43C = 0; }
    object = (RotationObject *)lbl_8055E434[index];
    if (object != 0 && object->isValid() != 0) {
        c = *(float *)((char *)object + 0x44);
        b = *(float *)((char *)object + 0x40);
        a = *(float *)((char *)object + 0x3C);
        forward.x = a; forward.y = b; forward.z = c;
        f = *(float *)((char *)object + 0x5C);
        e = *(float *)((char *)object + 0x58);
        d = *(float *)((char *)object + 0x54);
        right.x = d; right.y = e; right.z = f;
        PSVECCrossProduct(&right, &forward, &up);
        PSVECNormalize(&forward, &forward);
        PSVECNormalize(&up, &up);
        PSVECCrossProduct(&forward, &up, &right);
        *(float *)((char *)object + 0x3C) = forward.x;
        *(float *)((char *)object + 0x40) = forward.y;
        *(float *)((char *)object + 0x44) = forward.z;
        *(float *)((char *)object + 0x48) = up.x;
        *(float *)((char *)object + 0x4C) = up.y;
        *(float *)((char *)object + 0x50) = up.z;
        *(float *)((char *)object + 0x54) = right.x;
        *(float *)((char *)object + 0x58) = right.y;
        *(float *)((char *)object + 0x5C) = right.z;
    }
    lbl_8055E43C++;
}
#pragma cplusplus off
#pragma dont_inline on
void fn_80177EE4(void) {
    int i;
    if (lbl_8055E44C != 0) {
        for (i = 0; i < 8; i++) {
            if (fn_8017960C(i) != 0) {
                fn_8018A180();
            }
        }
        lbl_8055E44C = 0;
    }
}
#pragma dont_inline off

void fn_80176A6C(void);
void fn_80176A34(int);
void fn_8026C014(int);
void fn_80177AE4(int, int);
void fn_801777B4(void);
int fn_802D3EBC(void);
void fn_80265D84(void);
void fn_80265D88(void);
void fn_801B2364(void);
void fn_8026B6E4(void);
void fn_801CEDDC(void);
void fn_801D2214(void);
void fn_8020C59C(void);
void fn_801DEFE0(void);
void fn_801EA1F0(void);
int fn_801B526C(void);
void fn_801B8BF4(void);
int fn_801C5B60(void);
void fn_801B841C(void);
void fn_801C4CE8(void);
void fn_801D47F8(void);
void fn_80134A8C(void);
void fn_80134B50(void);
void fn_80177CEC(void);
void fn_80177EE4(void);
void fn_8017FF4C(float);
void fn_801778C0(void);
void fn_801E22D0(void *, int);
void fn_80177E14(void);
void fn_801E1E64(void);
void fn_801B24B8(void);
void fn_801279D0(void);
void fn_80178DBC(int, float);
double sin(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80177F40(void) {
    extern void *lbl_8055E458;
    extern unsigned char lbl_8055E45C;
    extern int lbl_8055A300;
    extern long lbl_8055E3C4;
    extern float lbl_8055E3C8;
    extern int lbl_8055E488;
    extern float lbl_80561B50, lbl_80561B54, lbl_80561B58, lbl_80561B5C;
    char *base = (char *)lbl_80430590;
    unsigned char saved;
    int active;
    unsigned char flag;
    int other;
    int mask;

    fn_80176A6C();
    fn_80177A54();
    mask = (int)(-(int)lbl_8055E3BD | lbl_8055E3BD) >> 31;
    lbl_8055E458 = (void *)(((int)lbl_8055E458 + 1) & ~mask);
    fn_8026C014(1);
    lbl_8055E45D = lbl_8055E45C;
    lbl_8055E45F = lbl_8055E45E;
    fn_80177AE4(0, lbl_8055E45C);
    saved = lbl_8055E3BD;
    active = fn_802D3EBC();
    if (active != 0) lbl_8055E3BD = 1;
    flag = lbl_8055E3BD;
    *(int *)(base + 0x2E0) = 0;
    fn_80265D84();
    fn_801B2364();
    fn_8026B6E4();
    fn_801CEDDC();
    fn_801D2214();
    fn_8020C59C();
    fn_801DEFE0();
    if (flag != 0) fn_801EA1F0();
    other = fn_801B526C();
    if (other != 0 || flag == 0) {
        int i, off, zero, cur;
        float *src, *dst;
        float scale = lbl_80561B50;
        dst = (float *)(base + 0x170);
        src = (float *)(base + 0x44);
        for (i = 0; i < 0x4B; i++) {
            fn_801DCEDC(i, scale * (*src - *dst));
            *dst = *src;
            dst++;
            src++;
        }
        cur = lbl_8055A300;
        if (cur >= 0 && cur < 0x4B) {
            float s = (float)sin(lbl_80561B54 * (lbl_80561B58 * lbl_8055E3C8));
            fn_80178DBC(cur, lbl_80561B5C + lbl_80561B5C * s);
        }
        fn_801B8BF4();
        if (fn_801C5B60() == 0) fn_801B841C();
        fn_801C4CE8();
        fn_801D47F8();
        fn_801EA1F0();
        if (other == 0) {
            if (fn_801C5B60() == 0) fn_80134A8C();
        } else {
            fn_80134B50();
        }
        fn_80177CEC();
        *(int *)(base + 0x22E8) = 0;
        fn_80177EE4();
        fn_8017FF4C(lbl_80561B60);
        fn_801778C0();
        if (other == 0) fn_801E22D0(base + 0x3B30, lbl_8055E468);
        fn_80177E14();
        i = 0;
        off = 0;
        zero = 0;
        while (i < lbl_8055E438) {
            void **obj = *(void ***)((char *)lbl_8055E434 + off);
            char *r = ((char *(*)(void **))(*(char ***)obj)[0x3C / 4])(obj);
            if (r != 0) *(int *)(r + 0x1E4) = zero;
            off += 4;
            i++;
        }
        lbl_8055E488 = 0;
        fn_801E1E64();
    } else {
        fn_8017FF4C(lbl_80561B60);
    }
    fn_801B24B8();
    fn_80265D88();
    if (flag == 0) {
        fn_801777B4();
        fn_80176A34(lbl_8055E3C4 + 1);
    }
    fn_801279D0();
    if (active != 0) lbl_8055E3BD = saved;
}
#pragma pop
extern char jumptable_803318F8[];
#pragma dont_inline off
long fn_801781B8(void) { return 0; }

#pragma scheduling invalid_target
int fn_801781C0(int arg0) {
    switch (arg0 - 0x13) {
    case 0:
    case 2:
    case 5:
    case 7:
    case 12:
        return 1;
    default:
        return 0;
    }
}
#pragma scheduling on
unsigned char *fn_801781F4(long arg0) {
    volatile unsigned char *p = &lbl_8055E46C;
    register unsigned char a;
    unsigned char b;
    unsigned char c;
    *(volatile long *)p = arg0;
    a = p[0];
    c = p[3];
    b = p[1];
    b = p[2];
    p[0] = c;
    p[3] = a;
    p[1] = b;
    p[2] = b;
    return (unsigned char *)p;
}
#pragma dont_inline off

void fn_80178224(void) {
    if (fn_801284F8(0x2780, &lbl_8055A304) != 0)
        fn_801A6484();
}

#pragma scheduling on
void fn_80178258(void) {
    if (fn_801284F8(0xD0, &lbl_8033192C) != 0) {
        fn_8017ACCC();
    }
}
#pragma scheduling on
void fn_80178290(void) {
    void *p = (void *)fn_801284F8(0x1FC, &lbl_80331938);
    if (p != 0) {
        fn_801AFD20(p);
    }
}
extern char lbl_80331944[];
extern char lbl_80338400[];
void *fn_8017B0B0(void *);
#pragma scheduling invalid_target
void *fn_801782C8(void) {
    long object = fn_801284F8(0x29C, (void *)&lbl_80331944[0]);
    if (object != 0) {
        fn_8017B0B0((void *)object);
        *(long *)object = (long)&lbl_80338400[0];
    }
    return (void *)object;
}
#pragma scheduling on

#pragma scheduling on
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8017831C(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80179EE8((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

extern char lbl_80331950[];
#pragma dont_inline on
char *fn_80178374(long arg0) {
    char *var_r4 = lbl_80331950;
    int temp_r0;

    while ((temp_r0 = *(int *)var_r4) != 0) {
        if ((unsigned long)temp_r0 == (unsigned long)arg0) {
            return var_r4;
        }
        var_r4 += 0xC;
    }
    return NULL;
}

#pragma cplusplus on
extern "C" void *lbl_8055E454;
extern "C" void fn_80179D8C(void *, int);
extern "C" long fn_802E317C(const char *, long, ...);
#pragma cplusplus on
extern "C" void **fn_801783A8(int *arg0, int arg1) {
    struct Provider {
        int id;
        int reserved;
        void **(*create)(void);
    };
    struct Handler {
        virtual void run(int *);
    };
    struct Provider *provider;
    char *table;
    void **object;
    object = 0;
    table = jumptable_803318F8;
    lbl_8055E454 = arg0;
    provider = (struct Provider *)fn_80178374(*arg0);
    if (provider != 0) {
        if (provider->create != 0) {
            object = provider->create();
            if (object != 0) {
                fn_80179D8C(object, arg1);
                ((struct Handler *)object)->run(arg0);
            } else {
                fn_802E317C(table + 0xF4, (long)fn_801781F4(*arg0));
            }
        } else {
            fn_802E317C(table + 0x110, (long)fn_801781F4(*arg0));
        }
    } else {
        fn_802E317C(table + 0x134, (long)fn_801781F4(*arg0));
    }
    lbl_8055E454 = 0;
    return object;
}
#pragma cplusplus off

#pragma dont_inline off

void fn_801784AC(void) {
    fn_801E2640(&lbl_804340C0[0], &lbl_8055E468);
}

extern float lbl_80561B64;
#pragma scheduling invalid_target
s32 fn_801784DC(Vec *arg0, f32 *arg1, Vec *arg2, s32 *arg3, s32 arg4) {
    Vec start;
    Vec hit;
    Vec normal;
    s32 value;
    s32 other;
    start.y = arg0->y - lbl_80561B64;
    start.z = arg0->z;
    start.x = arg0->x;
    if (((s32 (*)(Vec *, Vec *, Vec *, Vec *, s32 *, s32 *, s32))fn_801784AC)(arg0, &start, &hit, &normal, &value, &other, arg4)) {
        *arg1 = hit.y;
        if (arg2 != 0) {
            arg2->x = normal.x;
            arg2->y = normal.y;
            arg2->z = normal.z;
        }
        if (arg3 != 0) {
            *arg3 = value;
        }
        return 1;
    }
    return 0;
}
#pragma scheduling on
void fn_801785A4(void **arg0) {
    int index;
    void **table;
    struct Funcs {
        void *pad[0x10];
        int (*callback)(void **);
    };
    index = lbl_8055E438;
    table = lbl_8055E434;
    table[index] = arg0;
    lbl_8055E438 = index + 1;
    if (((struct Funcs *)*arg0)->callback(arg0) != 0) {
        fn_801B5318(arg0);
    }
}

int fn_80178604(void *arg0) {
    int result = 0;
    unsigned int magic = *(unsigned int *)arg0;
    if (magic == 0x43415220 || magic == 0x50434152 ||
        magic == 0x41434152 || magic == 0x4e434152) {
        result = 1;
    }
    if (result != 0) return 0;
    if (magic == 0x4f425354 && *(int *)((char *)arg0 + 0x50) == 0x14) return 2;
    return 1;
}

long fn_8017873C(long *arg0, long arg1, long arg2, long arg3, long arg4) {
    if ((unsigned long)(arg3 + *arg0 + 1) < 0x1000) {
        long result;
        *(unsigned char *)((char *)arg0 + *arg0 + 4) = arg1;
        memcpy((char *)arg0 + *arg0 + 5, (void *)arg2, arg3);
        result = arg3 + *arg0;
        *arg0 = result + 1;
        return result;
    }
    return (long)arg0;
}

#pragma push
#pragma processor 750
int fn_801787B4(void *arg0)
{
    extern int fn_80019B78(void);
    extern int fn_80278820(void);
    extern int fn_802787FC(void);
    extern int fn_80176A1C(void);
    extern float fn_80176A2C(void);
    extern void fn_802E2D74(int);
    extern void fn_802E30C8(const char *, ...);
    extern int fn_80265D64(void);
    extern u64 fn_802E2C9C(void);
    extern s64 fn_80178BBC(s32 *);
    extern s32 lbl_8055E3C4;
    extern s32 lbl_8055D430;
    extern float lbl_80561B48;
    extern float lbl_80561B5C;
    extern float lbl_80561B68;
    extern float lbl_80561B6C;
    extern float lbl_8055E460;
    extern double lbl_80561B70;
    char *tbl = jumptable_803318F8;
    s32 result;
    s32 *p = (s32 *)arg0;
    s32 r28;
    float f31;
    u64 now;
    s32 delta;
    s32 w;
    float scale;
    float var;
    s32 vi;
    s32 ip;
    s32 flag;
    s32 state;
    s32 c;
    s64 t;
    if (fn_80019B78() != 0) {
        return 1;
    }
    if (fn_80278820() != 0) {
        return 10;
    }
    if (fn_802787FC() != 0) {
        return 1;
    }
    if (fn_80176A1C() == 2) {
        float limit;
        f31 = fn_80176A2C();
        now = fn_802E2C9C();
        delta = (s32)(now - *(u64 *)(p + 6));
        delta = delta > 0 ? delta : 0;
        w = delta < 0xC350 ? delta : 0xC350;
        scale = lbl_80561B68;
        limit = lbl_80561B48;
        scale *= f31;
        p[7] = (s32)now;
        p[6] = (s32)(now >> 32);
        if (scale < limit) {
            var = scale - lbl_80561B5C;
        } else {
            var = lbl_80561B5C + scale;
        }
        vi = (s32)var;
        if (lbl_8055E3BD == 0) {
            lbl_8055E460 += (float)w / (float)(vi < 1 ? 1 : vi);
        }
        ip = (s32)lbl_8055E460;
        lbl_8055E460 -= (float)ip;
        *((u8 *)p + 0x14) = 1;
        return lbl_8055E3BD ? 1 : ip;
    }
    lbl_8055E460 = lbl_80561B6C;
    flag = ((lbl_8055D430 & 1) != 0 && (lbl_8055D430 & 0x600) != 0) ? 1 : 0;
    if (flag != 0) {
        *((u8 *)p + 0x14) = 1;
        return 3;
    }
    result = 1;
    state = fn_80176A1C();
    r28 = 1;
    if (lbl_8055E3BD == 0 && state == 1) {
        r28 = 0;
    }
    if (state == 0) {
        result = 10;
        if ((u8)lbl_8055E3C4 < 0x80 && (u8)(lbl_8055E3C4 - 10) > 0x80) {
            fn_802E2D74(0x14);
        }
    }
    if (r28 == 0) {
        if (*((u8 *)p + 0x14) != 0) {
            p[0] = lbl_8055E3C4;
            t = fn_802E2C9C();
            *((u8 *)p + 0x14) = 0;
            *(s64 *)(p + 2) = (t + 0x2000) & ~(s64)0x3FFF;
        } else {
            result = ((s32)fn_80178BBC(p) + 0x2095) / 16683;
            if (fn_801B526C() != 0) {
                if ((result < 0 ? -result : result) > 10) {
                    *((u8 *)p + 0x14) = 1;
                }
                c = result > 0 ? result : 0;
                result = c < 4 ? c : 4;
            } else if (fn_80265D64() != 0) {
                if (result > 12) {
                    result = 12;
                }
            } else {
                if (result > 8) {
                    *((u8 *)p + 0x14) = 1;
                }
                if (result < -8) {
                    if (result < -16) {
                        s64 t2;
                        s64 t3;
                        s32 diff;
                        s64 sum;
                        fn_802E30C8(tbl + 0x14C, result);
                        t2 = fn_80178BBC(p);
                        fn_802E30C8(tbl + 0x178, (s32)t2, (s32)(t2 >> 32), (s32)t2);
                        sum = *(s64 *)(p + 2) + (s64)(diff = lbl_8055E3C4 - p[0]) * 0x412B;
                        fn_802E30C8(tbl + 0x19C, diff * 0x412B, (s32)(sum >> 32), (s32)sum);
                        t3 = fn_802E2C9C();
                        fn_802E30C8(tbl + 0x1C0, (s32)t3, (s32)(t3 >> 32), (s32)t3);
                    }
                    *((u8 *)p + 0x14) = 1;
                }
                c = result > 0 ? result : 0;
                result = c < 8 ? c : 8;
            }
        }
    } else {
        *((u8 *)p + 0x14) = 1;
    }
    return result;
}
extern void DBPrintf_80179758(const char *fmt, ...);
extern s32 lbl_8055E3C4;
extern u64 fn_802E2C9C(void);
extern s64 __div2i(s64, s64);
extern u8 lbl_804305C0[];
#pragma dont_inline on
s64 fn_80178BBC(s32 *arg0) {
    s32 r4 = lbl_8055E3C4 - arg0[0];
    s64 r31 = *(s64 *)&arg0[2] + (s64)r4 * 0x412b;
    return fn_802E2C9C() - r31;
}
s32 fn_80178C1C(s32 *arg0) {
    s64 r3 = fn_80178BBC(arg0);
    return (s32)__div2i(r3, 0x412b);
}

s32 fn_80178C4C(void *arg0) {
    DBPrintf_80179758((char *)arg0 + 4);
    return *(u16 *)arg0 + 4;
}

#pragma dont_inline off
void fn_80178C88(void) {

}

void fn_80178C8C(void) {

}

void *__AXGetStudio_80178C90(void) {
    return lbl_804305C0;
}

extern void *lbl_8055E414;
void* fn_80178C9C(void) {
    return lbl_8055E414;
}

extern void *lbl_8055E444;
void* fn_80178CA4(void) {
    return lbl_8055E444;
}

void fn_80178DBC(int arg0, float arg1) {
    lbl_804305D4[arg0] = arg1;
    fn_801DCEC8(arg0, arg1);
}

#pragma dont_inline on
void fn_80178DD0(void) {
    fn_80177990();
}

extern char jumptable_803318F8[];
extern int lbl_8055E3CC;
extern int lbl_8055E418;
extern int lbl_8055E420;
extern int lbl_8055E428;
extern int lbl_8055E440;
extern unsigned char lbl_8055E45C;
extern void __AXDSPInitCallback_801D0CF0(void);
extern void __AXDSPInitCallback_801D32D0(void);
extern void __AXFXGetLfoSinTable_801769CC(void);
extern int *fn_801769D8(void);
extern int fn_80127464(void);
extern int fn_801284E8(void *, int);
extern int fn_8012850C(int, void *);
extern void fn_80129C80(int, int, int);
extern int fn_8012F3CC(int);
extern void fn_8012F43C(void *);
extern void fn_8012F418(void *);
extern int fn_80135DC4(int, int, int);
extern int fn_80137C74(void);
extern int fn_80178678(void *, void **, int);
extern void fn_80179320(void);
extern void fn_8017D2CC(int);
extern void fn_80181FEC(void);
extern void fn_80181F30(void);
extern void fn_801A4E28(void);
extern void fn_801AD5EC(void);
extern void fn_801AE4C4(void);
extern void fn_801AFAC8(void);
extern void fn_801B06C8(void);
extern void fn_801B2024(void);
extern void fn_801B2320(void);
extern void fn_801B3448(void);
extern void fn_801B5274(void);
extern void fn_801B52CC(void);
extern void fn_801B5364(int, void *);
extern void fn_801B5FA0(void);
extern void fn_801B8318(void);
extern void fn_801B8B84(void);
extern void fn_801C1B9C(void);
extern void fn_801C4AD0(void);
extern void fn_801C4B10(void);
extern void fn_801CB2D8(void);
extern void fn_801CEC80(void);
extern void fn_801CEFAC(void);
extern void fn_801D0E0C(void);
extern void fn_801D21C0(void);
extern void fn_801D4734(void);
extern void fn_801D47F4(void);
extern void fn_801D9284(void);
extern void fn_801DA6EC(void);
extern void fn_801DE0A4(void);
extern void fn_801DEC18(void);
extern void fn_801DF6FC(void);
extern void fn_801E0710(void);
extern void fn_801E1D38(void *, int);
extern void fn_801E2188(void);
extern void fn_801E21BC(void);
extern void fn_801FA978(void);
extern void fn_8020C41C(void);
extern void fn_80267420(void);
extern void fn_8026B644(void);
#pragma push
#pragma use_lmw_stmw off
void fn_80178DD4(int arg0) {
    register char *table = jumptable_803318F8;
    register char *base = (char *)lbl_80430590;
    register int var_r28;
    register int var_r27;
    register int var_r26;
    register int var_r31;
    register int version;
    int value;
    void *object;

    __AXDSPInitCallback_801D0CF0();
    lbl_8055E8F8 = *fn_801769D8();
    fn_80181FEC(); fn_801DF6FC(); fn_801DA6EC(); fn_801D0E0C();
    fn_80127464(); fn_801CEFAC();
    fn_80177814(&lbl_8055E418); fn_80177814(&lbl_8055E420); fn_80177814(&lbl_8055E428);
    value = fn_801284F8(0x68, table + 0x220);
    if (value != 0) value = fn_80135DC4(value, 0, 0);
    lbl_8055E414 = (void *)value;
    memset(base + 0x32F0, 0, 0x840);
    fn_80129C80(4, lbl_8055E418, *(int *)((char *)&lbl_8055E418 + 4));
    fn_80129C80(3, lbl_8055E420, *(int *)((char *)&lbl_8055E420 + 4));
    fn_80129C80(5, lbl_8055E428, *(int *)((char *)&lbl_8055E428 + 4));

    var_r28 = (int)base;
    var_r27 = (int)(base + 0x10);
    for (var_r26 = 0; var_r26 < 4; ++var_r26, var_r28 += 4, var_r27 += 8) {
        *(int *)var_r28 = -1;
        memset((void *)var_r27, 0, 8);
    }

    lbl_8055E430 = (void *)fn_80137C74();
    var_r31 = 0;
    lbl_8055E43C = var_r31;
    fn_80127464(); fn_801B5274(); fn_801B5FA0(); fn_801B3448();
    fn_801A4E28(); fn_801AFAC8(); fn_801B06C8(); fn_801B8B84();
    fn_801CEC80(); fn_80181F30(); fn_801DE0A4();
    __AXFXGetLfoSinTable_801769CC(); fn_801B2024(); fn_80127464();
    fn_801C4AD0(); fn_8020C41C(); fn_8026B644(); fn_801C1B9C();
    fn_801D21C0(); __AXDSPInitCallback_801D32D0(); fn_801D9284();
    fn_801D4734(); fn_801CB2D8(); fn_801DEC18(); fn_80127464();
    fn_801E0710(); fn_801B8318(); fn_801FA978();
    lbl_8055E434 = (void **)fn_8012850C(0x800, table + 0x230);
    fn_801E2188();
    *(int *)(base + 0x2A0) = var_r31;
    {
        int *field = (int *)(base + 0x2A0);
        field[1] = var_r31; field[2] = var_r31; field[3] = var_r31;
        field[4] = var_r31; field[5] = var_r31; field[6] = var_r31; field[7] = var_r31;
    }
    lbl_8055E45E = var_r31; lbl_8055E45F = var_r31; lbl_8055E45C = var_r31; lbl_8055E45D = var_r31;
    lbl_8055E438 = var_r31;
    *(int *)(base + 0x22E8) = var_r31;
    *(int *)(base + 0x2E0) = var_r31;
    *(int *)(base + 0x12E4) = var_r31;

    var_r26 = fn_8012F3CC(arg0);
    fn_801AE4C4(); fn_80127464();
    var_r27 = 0;
    do {
        fn_8012F43C((void *)var_r26);
        while (fn_80178678((void *)var_r26, &object, var_r27) != 0) {
            if (object != 0) fn_801785A4((void **)object);
        }
        var_r27 += 1;
    } while (var_r27 < 3);

    fn_80127464(); fn_8012F418((void *)var_r26); fn_801B52CC();
    fn_801E21BC(); fn_80127464(); fn_8017D2CC(0x200);
    lbl_8055E448 = 0;
    value = 1;
    version = (int)lbl_8055E430;
    if (version > 1) value = version;
    lbl_8055E440 = value; lbl_8055E444 = (void *)value;
    fn_80267420();
    lbl_8055E450 = fn_801284E8(table + 0x23C, lbl_8055E3CC + 0x2EE8);
    fn_801AD5EC(); fn_80127464(); fn_801B2320(); fn_801C4B10();
    {
        int *field = (int *)(base + 0x2C0);
        field[4] = var_r31;
        *((unsigned char *)field + 0x14) = 1;
        field[7] = var_r31; field[6] = var_r31;
        fn_801E1D38(field, 1);
    }
    fn_801D47F4(); fn_801B5364(9, (void *)fn_80178C4C);
    fn_80129C80(4, lbl_8055E418, *(int *)((char *)&lbl_8055E418 + 4));
    fn_80129C80(3, lbl_8055E420, *(int *)((char *)&lbl_8055E420 + 4));
    fn_80129C80(5, lbl_8055E428, *(int *)((char *)&lbl_8055E428 + 4));
    fn_80127464(); fn_80179320();
}
#pragma pop
extern void fn_801B2C6C(void);
extern void fn_801B5354(void);
void fn_80179110(void) {
    fn_801B2C6C();
    fn_801B5354();
    lbl_8055E448 += 1;
}
extern int fn_802E4C18(int);
extern int fn_801787B4(void *);
extern void fn_80177F40(void);
extern long lbl_80430850[];
#pragma cplusplus on
extern "C" void fn_80179140(void) {
    class Element {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
    };
    s32 i = 0;
    s32 count = 0;
    Element *entry;
    while (count < lbl_8055E438) {
        entry = (Element *)*(void **)((char *)lbl_8055E434 + i);
        entry->f3();
        i += 4;
        count += 1;
    }
}
#pragma cplusplus off

void fn_801791A4(void) {

}

#pragma cplusplus on
extern "C" void fn_801B537C(long (*)(void *));
extern "C" void fn_801E1D9C(void);
extern "C" void fn_8026785C(void);
extern "C" void fn_8017D334(void);
extern "C" void fn_80128658(int);
extern "C" void fn_80128670(void *);
extern "C" void fn_801AE50C(void);
extern "C" void fn_801E222C(void);
extern "C" void fn_801E1520(void);
extern "C" void fn_801DEE3C(void);
extern "C" void fn_801CB518(void);
extern "C" void fn_801D483C(void);
extern "C" void fn_801D9828(void);
extern "C" void fn_801D32DC(void);
extern "C" void fn_801D2210(void);
extern "C" void fn_801C1BA0(void);
extern "C" void fn_8026B69C(void);
extern "C" void fn_801B228C(void);
extern "C" void fn_801AFBE8(void);
extern "C" void fn_801B06CC(void);
extern "C" void fn_801C4B74(void);
extern "C" void fn_8020C45C(void);
extern "C" void fn_801DE0E8(void);
extern "C" void fn_80181FC4(void);
extern "C" void fn_801CECB4(void);
extern "C" void fn_801B8BBC(void);
extern "C" void fn_801A4E54(void);
extern "C" void fn_801B3B28(void);
extern "C" void fn_801B60A8(void);
extern "C" void fn_801B531C(void);
extern "C" void fn_801CEFC4(void);
extern "C" void fn_80206550(int);
extern "C" void fn_801D0E70(void);
extern "C" void fn_801D0CFC(void);
#pragma cplusplus on
extern "C" void fn_801791A8(void) {
    class Element {
    public:
        virtual void f0();
        virtual void disable(int);
    };
    class Owner {
    public:
        virtual void destroy(int);
    };
    int offset;
    int i;
    Element *object;
    fn_80177A18();
    fn_801B537C(fn_80178C4C);
    fn_801E1D9C(); fn_8026785C(); fn_8017D334();
    fn_80128658(lbl_8055E450);
    lbl_8055E450 = 0;
    i = 0;
    offset = 0;
    while (i < lbl_8055E438) {
        object = (Element *)*(void **)((char *)lbl_8055E434 + offset);
        if (object != 0) object->disable(1);
        offset += 4;
        i++;
    }
    fn_80128670(lbl_8055E434);
    lbl_8055E434 = 0;
    fn_801AE50C(); fn_801E222C(); fn_801E1520(); fn_801DEE3C(); fn_801CB518();
    fn_801D483C(); fn_801D9828(); fn_801D32DC(); fn_801D2210(); fn_801C1BA0();
    fn_8026B69C(); fn_801B228C(); fn_801AFBE8(); fn_801B06CC(); fn_801C4B74();
    fn_8020C45C(); fn_801DE0E8(); fn_80181FC4(); fn_801CECB4(); fn_801B8BBC();
    fn_801A4E54(); fn_801B3B28(); fn_801B60A8(); fn_801B531C();
    if (lbl_8055E414 != 0) ((Owner *)lbl_8055E414)->destroy(1);
    lbl_8055E414 = 0;
    fn_801CEFC4(); fn_80206550(1); fn_801D0E70();
    lbl_8055E8F8 = 0;
    fn_801D0CFC();
}
#pragma cplusplus off
void fn_801792F4(void) {
    fn_801E21B4();
}

extern void *lbl_8055E454;
void* fn_801792F8(void) {
    return lbl_8055E454;
}

extern void *lbl_8055E458;
void* fn_80179300(void) {
    return lbl_8055E458;
}

void fn_80179308(void) {
    lbl_8055E448 += 1;
}

void* fn_80179318(void) {
    return (void *)lbl_8055E448;
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_80179320(void) {
    extern float lbl_8055E460;
    extern float lbl_80561B6C;
    float initial = lbl_80561B6C;
    register char *base = (char *)lbl_80430590;
    register int i;
    register int offset;
    void *object;
    int old;
    int *field;
    char *bytes;

    lbl_8055E43C = 0;
    lbl_8055E460 = initial;
    lbl_8055E44C = 0;
    lbl_8055E458 = 0;
    fn_80177990();
    if (fn_801CF050() != 0) {
        fn_80177814(&lbl_8055E418);
        fn_80177814(&lbl_8055E420);
        fn_80177814(&lbl_8055E428);
    }
    fn_80129C80(4, lbl_8055E418, *(int *)((char *)&lbl_8055E418 + 4));
    fn_80129C80(3, lbl_8055E420, *(int *)((char *)&lbl_8055E420 + 4));
    fn_80129C80(5, lbl_8055E428, *(int *)((char *)&lbl_8055E428 + 4));
    fn_80176A34(0);
    fn_801D9A08();
    __AXDSPInitCallback_801B8BE8();
    fn_801DEF98();
    fn_801B83A8();
    fn_801B34A4();
    fn_8026B6D0();
    fn_802C1928();
    fn_80134998();
    fn_801B265C();
    fn_801AED74();
    fn_801E2294();

    i = 0;
    offset = 0;
    while (offset < lbl_8055E438) {
        object = *(void **)((char *)lbl_8055E434 + i);
        ((void (*)(void *))(*(void ***)object)[4])(object);
        i += 4;
        offset += 1;
    }

    fn_801B2910();
    fn_80267680();
    if (fn_801CF064() == 0) {
        i = (int)base;
        offset = 0;
        while (offset < (int)lbl_8055E430) {
            old = *(int *)i;
            fn_8026A248(old, offset);
            i += 4;
            offset += 1;
        }
    }

    i = (int)(base + 0x10);
    offset = 0;
    do {
        memset((void *)i, 0, 8);
        offset += 1;
        i += 8;
    } while (offset < 4);

    base[0x32F0] = 0;
    bytes = base + 0x32F0;
    bytes[0x108] = 0;
    bytes[0x210] = 0;
    bytes[0x318] = 0;
    bytes[0x420] = 0;
    bytes[0x528] = 0;
    bytes[0x630] = 0;
    bytes[0x738] = 0;
    fn_80265D60(bytes);
    fn_801CECE0();
    if (fn_80265D64() == 0) {
        field = (int *)(base + 0x2C0);
        field[4] = 0;
        *((char *)field + 0x14) = 1;
        field[7] = 0;
        field[6] = 0;
    }

    old = lbl_8055E448;
    lbl_8055E448 = old + 1;
    fn_801349C4(old);
    fn_801CB320();
    fn_801D481C();
    fn_801C4BAC();
    fn_8020C54C();
    fn_801E1E30();
    fn_801D0ED4();
    fn_801777A8();
}
void fn_8017952C(void) {
    long count;
    long i;

    fn_802E4C18(1);
    count = fn_801787B4(&lbl_80430850);
    i = 0;
    while (i < count) {
        fn_80177F40();
        i++;
    }
}

void fn_801CEFE8(void);
void fn_801AED5C(void);
void fn_801CB464(void);
void fn_80179588(void) {
    fn_801CEFE8();
    fn_801AED5C();
    fn_801CB464();
}

void fn_801CF01C(void);
void fn_801CB4A0(void);
void fn_801AED68(void);
void fn_801795B0(void) {
    fn_801CF01C();
    fn_801CB4A0();
    fn_801AED68();
}

void fn_801795D8(void *arg0, int arg1) {
    ((void **)lbl_80430830)[arg1] = arg0;
    if (*(int *)((char *)arg0 + 0x1F0) == 0x50) {
        lbl_80430590[(*(unsigned char *)((char *)arg0 + 0x260) & 3)] = arg1;
    }
}

int fn_8017960C(int arg0) {
    if (arg0 < 8) return lbl_80430830[arg0];
    return 0;
}

int fn_80179630(int arg0) {
    if (arg0 < 0) arg0 = 0;
    return lbl_80430590[arg0];
}

extern void *lbl_8055E430;
void* fn_80179650(void) {
    return lbl_8055E430;
}

extern char lbl_8055E45D;
char fn_801796B4(void) {
    return lbl_8055E45D;
}

void fn_801796BC(unsigned char arg0) {
    lbl_8055E45E = arg0;
}

extern char lbl_8055E45F;
char fn_801796C4(void) {
    return lbl_8055E45F;
}

#pragma dont_inline on
long fn_801796CC(long arg0, long arg1, long arg2) {
    return fn_8017873C((long*)&lbl_80430870[0], arg0, arg1, arg2, arg0);
}

extern int lbl_80431874[];
long fn_801796EC(long arg0, long arg1, long arg2) {
    return fn_8017873C((long*)&lbl_80431874, arg0, arg1, arg2, arg0);
}

float fn_8017970C(void) {
    return lbl_80561B60 * (float)fn_80178C1C((long *)lbl_80430850);
}

#pragma dont_inline off
void DBPrintf_80179758(const char *fmt, ...) {
#pragma unused(fmt)
}

void DBPrintf_801797A8(const char *fmt, ...) {
#pragma unused(fmt)
}

extern int lbl_804305A0[];
extern int lbl_8055E450;
int fn_801797F8(int arg0, int arg1, int arg2) {
    int combined = (arg1 << 16) | (arg2 & 0xFFFF);
    int *entry = (int *)((char *)lbl_804305A0 + (arg0 << 3));
    entry[0] = combined;
    return entry[1]++;
}

#pragma push
#pragma dont_inline on
void *fn_80179824(void) {
    extern int fn_8026A368();
    extern void fn_802678E8();
    extern void fn_801B2D28();
    extern void fn_801CEEC8();
    extern void fn_801B848C();
    extern void fn_801E1EA4();
    extern void fn_80176C0C();
    extern int lbl_8055E440;
    extern void *lbl_8055E444;
    extern float lbl_8055E460;
    extern float lbl_80561B6C;
    extern float lbl_8055E3C8;
    int *tbl = lbl_80430590;
    char *p = (char *)lbl_8055E450;
    char *arg = p + 0x2ee8;
    char *q;
    int *e;
    int i, j, k;
    float d;
    *(int *)(p + 0x398) = lbl_8055E448;
    *(int *)(p + 0x394) = lbl_8055E440;
    *(int *)(p + 0x384) = tbl[0];
    *(int *)(p + 0x388) = tbl[1];
    *(int *)(p + 0x38c) = tbl[2];
    *(int *)(p + 0x390) = tbl[3];
    if (fn_801CF050() == 0 || (int)fn_801781C0(fn_8026A368(0)) != 0 || fn_801B526C() != 0) {
        *(int *)(p + 0x394) = 1;
    }
    lbl_8055E444 = *(void **)(p + 0x394);
    e = tbl + 4;
    for (i = 0, q = p + 4; i < lbl_8055E440; i++, q += 0xe0) {
        fn_802678E8(q, i);
        *(int *)(q + 0x70) = e[0];
        *(int *)(q + 0x6c) = e[1];
        e += 2;
    }
    fn_80206550((int)lbl_8055E444);
    d = lbl_8055E460 - lbl_80561B6C;
    *(float *)p = lbl_80561B60 * d + lbl_8055E3C8;
    for (j = 0, k = 0; j < lbl_8055E438; j++, k += 4) {
        void **o = *(void ***)((char *)lbl_8055E434 + k);
        ((void (*)(void *, void *))(((void **)*o)[10]))(o, arg);
    }
    fn_801B2D28(p);
    fn_801CEEC8(p);
    fn_801B848C(p);
    *(int *)(p + 0x57c) = tbl[12];
    *(int *)(p + 0x580) = tbl[13];
    *(float *)(p + 0x584) = ((float *)tbl)[14];
    *(float *)(p + 0x588) = ((float *)tbl)[15];
    *(float *)(p + 0x58c) = ((float *)tbl)[16];
    fn_801E1EA4(p);
    {
        float *s = (float *)(tbl + 17);
        float *dd = (float *)(p + 0xdb4);
        for (i = 0; i < 75; i++) dd[i] = s[i];
    }
    fn_80176C0C(p + 0xee0, tbl + 0xb8);
    fn_80176C0C(p + 0x1ee4, tbl + 0x4b9);
    tbl[0x4b9] = 0;
    return p;
}
#pragma pop
extern float lbl_80561B6C;
extern float lbl_8055E460;
extern char lbl_80558DC4[];
#pragma scheduling invalid_target
void fn_80179AF4(void *arg0, int arg1) {
    struct WordPair { unsigned int a, b; };
    extern char lbl_80558DC4[];
    extern float lbl_8055E460;
    extern float lbl_80561B6C;
    unsigned char *src = (unsigned char *)arg0;
    unsigned char *dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    float base;
    float top;
    float delta;
    base = lbl_80561B6C;
    top = lbl_8055E460;
    delta = top - base;
    if ((float)__fabs((double)delta) <= *(float *)lbl_80558DC4) {
        struct WordPair *s = (struct WordPair *)(src + 0x70);
        struct WordPair *d = (struct WordPair *)dst;
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        ((unsigned int *)dst)[8] = ((unsigned int *)(src + 0x70))[8];
        ((struct WordPair *)(dst + 0x24))[0] = ((struct WordPair *)(src + 0x94))[0];
        ((unsigned int *)dst)[11] = ((unsigned int *)(src + 0x70))[11];
    } else {
        float temp[12];
        float *a = (float *)(src + 0x70);
        float *b = (float *)(src + 0xA0);
        float *out = temp;
        int i;
        for (i = 0; i < 2; i++) {
            float a0 = a[0], b0 = b[0];
            float a1 = a[1], b1 = b[1];
            float a2 = a[2], b2 = b[2];
            float a3 = a[3], b3 = b[3];
            float a4 = a[4], b4 = b[4];
            float a5 = a[5], b5 = b[5];
            out[0] = b0 + top * (a0 - b0);
            out[1] = b1 + top * (a1 - b1);
            out[2] = b2 + top * (a2 - b2);
            out[3] = b3 + top * (a3 - b3);
            out[4] = b4 + top * (a4 - b4);
            out[5] = b5 + top * (a5 - b5);
            a += 6; b += 6; out += 6;
        }
        {
            unsigned int *s = (unsigned int *)temp;
            unsigned int *d = (unsigned int *)dst;
            d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
            d[4] = s[4]; d[5] = s[5]; d[6] = s[6]; d[7] = s[7];
            d[8] = s[8]; d[9] = s[9]; d[10] = s[10]; d[11] = s[11];
        }
    }
    *(short *)(dst + 0x30) = *(short *)(src + 0x6C);
}
#pragma scheduling on
int fn_80179CB0(void) {
    return lbl_8055E450 + 0x2EE8;
}

extern unsigned char lbl_8055E46C;
extern unsigned char lbl_8055A304;
extern long fn_801284F8(long, void *);
extern long fn_801A6484(void);
extern unsigned char lbl_8055E45E;
extern long fn_8017873C(long *, long, long, long, long);
extern long lbl_80430850[];
extern long fn_80178C1C(long *);
extern float lbl_80561B60;
extern double lbl_80561B70;
extern char *fn_80178374(long);
extern long fn_802E317C(const char *, long, ...);
extern const char lbl_80331B40[];
#include <revolution/MTX/vec.h>
extern int lbl_8055E43C;
