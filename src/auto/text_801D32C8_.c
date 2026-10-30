#include "math.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma cplusplus on
class Fn801D3610Interface {
public:
    virtual void *getValue(int);
    virtual void unused1();
    virtual int isAvailable(int);
};
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_802E317C(const char *, ...);
#pragma cplusplus reset

extern int fn_80128668(void *);
extern int fn_80179EE8(int);
extern char lbl_80338400[16];
extern float lbl_80562AAC;
extern float lbl_80562AB8;
extern float lbl_80562ABC;
extern void fn_8017A57C(void *);
extern void fn_8017A580(void *);
extern void fn_8017B164(void *);

void fn_801D32C8(void) {

}

void fn_801D32CC(void) {

}

extern void *lbl_8055E940;
void __AXDSPInitCallback_801D32D0(void) {
    lbl_8055E940 = 0;
}

void fn_801D32DC(void) {

}

int fn_801D36E8(void);
void fn_801D3FA4();
#pragma use_lmw_stmw off
int fn_801D32E0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    int result;

    result = fn_801D36E8();
    fn_801D3FA4(result, arg0, arg1, arg2, arg3, arg4, arg5);
    return result;
}

extern void *fn_80131810(int);
extern void fn_80131818(void *);
extern void fn_801D334C(void *, void *);
extern int lbl_80562AB0;
extern int lbl_80562AB4;
extern char lbl_803383BC[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801D3610(void *arg0, int arg1) {
    int ids[2];
    int *current;
    unsigned int count;
    Fn801D3610Interface *object;
    void *value;
    ids[0] = lbl_80562AB0;
    current = &ids[0];
    ids[1] = lbl_80562AB4;
    count = 0;
    do {
        object = (Fn801D3610Interface *)fn_80131810(*current);
        if (object != 0) {
            if (object->isAvailable(arg1) != 0) {
                value = object->getValue(arg1);
                fn_801D334C(arg0, value);
                fn_80131818(object);
                return;
            }
            fn_80131818(object);
        }
        count++;
        current++;
    } while (count < 2U);
    fn_802E317C(lbl_803383BC, arg1);
}
#pragma scheduling on
#pragma cplusplus reset
extern int fn_801D411C(void *);
extern void *lbl_804421D8[];
#pragma cplusplus on
#pragma paired off
#pragma paired_single off
#pragma scheduling invalid_target
extern "C" int fn_801D36E8(void) {
    struct Dummy {
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
        virtual void f14();
        virtual int check();
    };
    float bestValue;
    void **entry;
    void *best;
    int index;

    bestValue = lbl_80562AB8;
    entry = lbl_804421D8;
    best = 0;
    index = 0;
    goto check_loop;
loop:
    if (((struct Dummy *)*entry)->check() == 0)
        return (int)lbl_804421D8[index];
    if (best == 0 || *(float *)((char *)*entry + 0x224) < bestValue) {
        best = *entry;
        bestValue = *(float *)((char *)best + 0x224);
    }
    entry++;
    index++;
check_loop:
    if (index < *(int *)&lbl_8055E940)
        goto loop;
    fn_801D411C(best);
    return (int)best;
}
#pragma paired reset
#pragma paired_single reset
#pragma cplusplus reset
#pragma scheduling off
unsigned int fn_801D37AC(void *arg0) {
    int temp_r4;
    temp_r4 = *(int *)((char *)arg0 + 0x1EC);
    return (unsigned int)((-1 - temp_r4) | (temp_r4 + 1)) >> 31;
}

#pragma scheduling invalid_target
void *fn_801D3894(void *arg0, int arg1) {
    if (arg0 != 0) {
        float zero = lbl_80562AB8;
        *(int *)((char *)arg0 + 0x28) = 0;
        *(char **)arg0 = (char *)lbl_80338400;
        *(int *)((char *)arg0 + 0x24) = 0;
        *(float *)((char *)arg0 + 0x2C) = zero;
        if (arg0 != 0)
            ((void (*)(void *, int))fn_80179EE8)(arg0, 0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
extern void fn_8017B0F8(void);
extern void fn_8019EECC(void *, void *);
extern void fn_80179F94(void *, void *);
extern char lbl_80333B98[];
extern int lbl_80333B48[];
extern float lbl_80562AAC, lbl_80562AB8;
#pragma scheduling invalid_target
void fn_801D3910(void *arg0) {
    char *p;
    int i;

    fn_8017B0F8();
    p = (char *)arg0 + 0x248;
    *(void **)((char *)arg0 + 0x244) = p;
    if (p != 0) {
        double value = lbl_80562AAC;
        double zero = lbl_80562AB8;
        volatile float temp[3];
        void *initialVtable = lbl_80333B98;

        *(volatile void **)p = initialVtable;
        temp[0] = (float)zero;
        temp[1] = (float)zero;
        temp[2] = (float)zero;
        *(void **)(p + 0xC) = (char *)arg0 + 0x3C;
        *(void **)(p + 4) = arg0;
        *(int *)(p + 8) = 0;
        *(int *)(p + 0x18) = 0x53504852;
        *(float *)(p + 0x10) = (float)value;
        *(float *)(p + 0x14) = (float)value;
        *(int *)(p + 0x20) = 100;
        *(int *)(p + 0x1C) = 0;
        *(void **)p = lbl_80333B48;
        *(float *)(p + 0x24) = (float)value;
        *(float *)(p + 0x34) = (float)zero;
        *(float *)(p + 0x38) = (float)zero;
        *(float *)(p + 0x3C) = (float)zero;
        *(float *)(p + 0x40) = (float)zero;
        *(float *)(p + 0x44) = (float)zero;
        *(float *)(p + 0x48) = (float)zero;
        *(char *)(p + 0x4C) = 0;
        *(float *)(p + 0x50) = (float)zero;
        *(float *)(p + 0x28) = (float)zero;
        *(float *)(p + 0x2C) = (float)zero;
        *(float *)(p + 0x30) = (float)zero;
        if (arg0 != 0)
            fn_8019EECC(arg0, p + 0x28);
    }
    fn_80179F94(arg0, *(void **)((char *)arg0 + 0x244));
    *(char *)((char *)arg0 + 0x1E8) = 1;
    i = *(int *)&lbl_8055E940;
    lbl_804421D8[i] = arg0;
    *(int *)&lbl_8055E940 = i + 1;
}

void fn_801D3A1C(void *arg0) {
    char *self = (char *)arg0;
    char *sound = *(char **)(self + 0x244);
    int zeroInt = 0;
    int minusOne = -1;
    float zero = lbl_80562AB8;
    volatile float sp8, spC, sp10, sp14, sp18, sp1C;
    int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11;

    *(int *)(self + 0x1EC) = minusOne;
    *(int *)(self + 0x1F0) = minusOne;
    *(float *)(self + 0x224) = zero;
    *(int *)(self + 0x228) = zeroInt;
    *(int *)(self + 0x22C) = zeroInt;
    *(int *)(self + 0x23C) = zeroInt;
    *(int *)(self + 0x24) = *(int *)(self + 0x28);
    if (sound != 0) {
        float one = lbl_80562AAC;
        *(void **)(sound + 0xC) = self + 0x3C;
        *(void **)(sound + 4) = arg0;
        *(int *)(sound + 8) = zeroInt;
        *(int *)(sound + 0x18) = 0x53504852;
        *(float *)(sound + 0x10) = one;
        *(float *)(sound + 0x14) = one;
        *(int *)(sound + 0x20) = 100;
        *(int *)(sound + 0x1C) = zeroInt;
        *(void **)sound = lbl_80333B48;
        *(float *)(sound + 0x24) = one;
        *(float *)(sound + 0x34) = zero;
        *(float *)(sound + 0x38) = zero;
        *(float *)(sound + 0x3C) = zero;
        *(float *)(sound + 0x40) = zero;
        *(float *)(sound + 0x44) = zero;
        *(float *)(sound + 0x48) = zero;
        *(char *)(sound + 0x4C) = 0;
        *(float *)(sound + 0x50) = zero;
        *(float *)(sound + 0x28) = zero;
        *(float *)(sound + 0x2C) = zero;
        sp10 = zero;
        spC = zero;
        sp8 = zero;
        *(float *)(sound + 0x30) = zero;
        if (arg0 != 0)
            fn_8019EECC(arg0, sound + 0x28);
    }

    {
        float zero2 = lbl_80562AB8;
        float one2 = lbl_80562AAC;
        float special = lbl_80562ABC;
        *(float *)(self + 0x220) = zero2;
        *(int *)(self + 0x24) = zeroInt;
        *(float *)(self + 0x1F4) = one2;
        *(float *)(self + 0x1F8) = zero2;
        *(float *)(self + 0x1FC) = zero2;
        *(float *)(self + 0x200) = zero2;
        *(float *)(self + 0x204) = one2;
        *(float *)(self + 0x208) = zero2;
        *(float *)(self + 0x20C) = zero2;
        *(float *)(self + 0x210) = zero2;
        *(float *)(self + 0x214) = one2;
        *(float *)(self + 0x218) = zero2;
        *(float *)(self + 0x21C) = special;
        *(float *)(self + 0x220) = zero2;
        sp1C = zero2;
        sp18 = zero2;
        sp14 = zero2;
        *(float *)(self + 0x30) = zero2;
        *(float *)(self + 0x34) = zero2;
        *(float *)(self + 0x38) = zero2;
    }
    fn_8017A57C(arg0);
    v0 = *(int *)(self + 0x1F4);
    v1 = *(int *)(self + 0x1F8);
    v2 = *(int *)(self + 0x1FC);
    v3 = *(int *)(self + 0x200);
    v4 = *(int *)(self + 0x204);
    v5 = *(int *)(self + 0x208);
    v6 = *(int *)(self + 0x20C);
    v7 = *(int *)(self + 0x210);
    v8 = *(int *)(self + 0x214);
    v9 = *(int *)(self + 0x218);
    v10 = *(int *)(self + 0x21C);
    v11 = *(int *)(self + 0x220);
    *(int *)(self + 0x3C) = v0;
    *(int *)(self + 0x40) = v1;
    *(int *)(self + 0x44) = v2;
    *(int *)(self + 0x48) = v3;
    *(int *)(self + 0x4C) = v4;
    *(int *)(self + 0x50) = v5;
    *(int *)(self + 0x54) = v6;
    *(int *)(self + 0x58) = v7;
    *(int *)(self + 0x5C) = v8;
    *(int *)(self + 0x60) = v9;
    *(int *)(self + 0x64) = v10;
    *(int *)(self + 0x68) = v11;
    fn_8017A580(arg0);
    fn_8017B164(arg0);
}

#pragma scheduling invalid_target
#pragma scheduling on
extern void fn_8017A57C(void *);
extern void fn_8017A580();
extern void fn_8017B164(void *);
extern void fn_8017B81C(void);
extern void fn_801D4598(void *, float);
extern float lbl_8055E3C8;
extern float lbl_80562AC0;
#pragma paired off
#pragma paired_single off
void fn_801D3BF0(void *arg0) {
    float temp_f31;
    float a, b, c, d, e, f;
    volatile int reserve[2];

    temp_f31 = lbl_8055E3C8;
    if (*(int *)((char *)arg0 + 0x230) == 2) {
        fn_8017B81C();
        fn_801D4598(arg0, temp_f31);
        return;
    }
    if (temp_f31 < *(float *)((char *)arg0 + 0x224) + *(float *)((char *)arg0 + 0x234)) {
        fn_8017B81C();
        a = *(float *)((char *)arg0 + 0x118) * lbl_80562AC0;
        b = *(float *)((char *)arg0 + 0x11C) * lbl_80562AC0;
        c = *(float *)((char *)arg0 + 0x120) * lbl_80562AC0;
        d = *(float *)((char *)arg0 + 0x124) * lbl_80562AC0;
        e = *(float *)((char *)arg0 + 0x128) * lbl_80562AC0;
        f = *(float *)((char *)arg0 + 0x12C) * lbl_80562AC0;
        *(float *)((char *)arg0 + 0x118) = a;
        *(float *)((char *)arg0 + 0x11C) = b;
        *(float *)((char *)arg0 + 0x120) = c;
        *(float *)((char *)arg0 + 0x124) = d;
        *(float *)((char *)arg0 + 0x128) = e;
        *(float *)((char *)arg0 + 0x12C) = f;
        return;
    }
    fn_801D411C(arg0);
    *(int *)((char *)arg0 + 0x1E4) = 0;
    /* Scale the six stored components only on the timed branch. */
}

extern float lbl_8055E460;
extern char lbl_80558DC4[];
void fn_801D3CB8(void *arg0, char *arg1) {
    char *out = arg1 + *(int *)((char *)arg0 + 8);
    register float blend = lbl_8055E460;
    register float initial = lbl_80562AAC;
    register float delta = blend - initial;
    if ((float)fabs((double)delta) <= *(float *)lbl_80558DC4) {
        unsigned int a, b;
        b = *(unsigned int *)((char *)arg0 + 0x74);
        a = *(unsigned int *)((char *)arg0 + 0x70);
        *(unsigned int *)(out + 0) = a;
        *(unsigned int *)(out + 4) = b;
        b = *(unsigned int *)((char *)arg0 + 0x7C);
        a = *(unsigned int *)((char *)arg0 + 0x78);
        *(unsigned int *)(out + 8) = a;
        *(unsigned int *)(out + 0xC) = b;
        b = *(unsigned int *)((char *)arg0 + 0x84);
        a = *(unsigned int *)((char *)arg0 + 0x80);
        *(unsigned int *)(out + 0x10) = a;
        *(unsigned int *)(out + 0x14) = b;
        b = *(unsigned int *)((char *)arg0 + 0x8C);
        a = *(unsigned int *)((char *)arg0 + 0x88);
        *(unsigned int *)(out + 0x18) = a;
        *(unsigned int *)(out + 0x1C) = b;
        *(unsigned int *)(out + 0x20) = *(unsigned int *)((char *)arg0 + 0x90);
        b = *(unsigned int *)((char *)arg0 + 0x98);
        a = *(unsigned int *)((char *)arg0 + 0x94);
        *(unsigned int *)(out + 0x24) = a;
        *(unsigned int *)(out + 0x28) = b;
        *(unsigned int *)(out + 0x2C) = *(unsigned int *)((char *)arg0 + 0x9C);
    } else {
        float temp[12];
        float *a = (float *)((char *)arg0 + 0x70);
        float *b = (float *)((char *)arg0 + 0xA0);
        float *p = temp;
        int i;
        for (i = 0; i < 2; i++) {
            p[0] = b[0] + blend * (a[0] - b[0]);
            p[1] = b[1] + blend * (a[1] - b[1]);
            p[2] = b[2] + blend * (a[2] - b[2]);
            p[3] = b[3] + blend * (a[3] - b[3]);
            p[4] = b[4] + blend * (a[4] - b[4]);
            p[5] = b[5] + blend * (a[5] - b[5]);
            a += 6;
            b += 6;
            p += 6;
        }
        *(int *)(out + 0) = *(int *)&temp[0];
        *(int *)(out + 4) = *(int *)&temp[1];
        *(int *)(out + 8) = *(int *)&temp[2];
        *(int *)(out + 0xC) = *(int *)&temp[3];
        *(int *)(out + 0x10) = *(int *)&temp[4];
        *(int *)(out + 0x14) = *(int *)&temp[5];
        *(int *)(out + 0x18) = *(int *)&temp[6];
        *(int *)(out + 0x1C) = *(int *)&temp[7];
        *(int *)(out + 0x20) = *(int *)&temp[8];
        *(int *)(out + 0x24) = *(int *)&temp[9];
        *(int *)(out + 0x28) = *(int *)&temp[10];
        *(int *)(out + 0x2C) = *(int *)&temp[11];
    }
    *(short *)(out + 0x30) = *(short *)((char *)arg0 + 0x6C);
    *(int *)(out + 0x34) = *(int *)((char *)arg0 + 0x1EC);
    *(int *)(out + 0x38) = *(int *)((char *)arg0 + 0x1F0);
    *(int *)(out + 0x3C) = 0;
}

#pragma paired reset
#pragma paired_single reset
struct Vec3 {
    float x, y, z;
};
struct Mtx48 {
    int w[12];
};
extern void fn_801A4868(void *, int);
extern void fn_8017A57C(void *);
extern void fn_8017A580();
extern void fn_8017B2D0(void *, float, float, float, float);
extern void fn_801D4294(void *, void *);
extern void fn_8017D2C8();
extern void fn_801796CC();
void fn_801D3E8C(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    float tmp[8];

    fn_8017D2C8(arg0, arg1, arg2);
    if (*(int *)((char *)arg0 + 0x238) > 0 && arg4 != 0) {
        float z_val;
        float y_val;
        float x_val;
        int size;

        x_val = *(float *)arg2;
        y_val = *(float *)((char *)arg2 + 4);
        z_val = *(float *)((char *)arg2 + 8);
        tmp[0] = x_val;
        size = 0x20;
        tmp[1] = y_val;
        tmp[2] = z_val;
        tmp[3] = *(float *)((char *)arg4 + 0x118);
        tmp[4] = *(float *)((char *)arg4 + 0x11C);
        tmp[5] = *(float *)((char *)arg4 + 0x120);
        *(short *)((char *)tmp + 0x18) = *(short *)((char *)arg4 + 0x6C);
        *(int *)((char *)tmp + 0x1C) = *(int *)((char *)arg0 + 0x238);
        fn_801796CC(10, tmp, size);
    }
    if (*(int *)((char *)arg0 + 0x230) == 2 && *(void **)((char *)arg0 + 0x22C) != arg4 && arg4 != 0) {
        int is_car = 0;
        unsigned int tag = *(unsigned int *)((char *)arg4 + 0x10);

        if (tag == 0x43415220 || tag == 0x50434152 || tag == 0x41434152 || tag == 0x4E434152) {
            is_car = 1;
        }
        if (is_car != 0) {
            *(void **)((char *)arg0 + 0x22C) = arg4;
            *(int *)((char *)arg0 + 0x24) = 0;
        }
    }
}

void fn_801D3FA4(void *arg0, int arg1, int arg2, void *arg3, void *arg4, void *arg5, int arg6) {
    float fa;
    float fb;
    float fc;
    int temp_r21;
    int temp_r22;
    int temp_r23;
    int temp_r24;
    int temp_r25;
    int temp_r26;
    int temp_r27;
    int temp_r12;
    int temp_r11;
    int temp_r7;
    int temp_r6;
    int temp_r4;
    int temp_r4_2;
    int temp_r5;
    int temp_r6_2;
    int r0;
    int zero;
    int t0, t1, t2, t3;

    temp_r7 = ((int *)arg3)[0];
    temp_r27 = ((int *)arg3)[1];
    temp_r26 = ((int *)arg3)[2];
    temp_r25 = ((int *)arg3)[3];
    temp_r11 = 0;
    temp_r24 = ((int *)arg3)[4];
    temp_r23 = ((int *)arg3)[5];
    temp_r22 = ((int *)arg3)[6];
    temp_r21 = ((int *)arg3)[7];
    zero = ((int *)arg3)[8];
    r0 = ((int *)arg3)[9];
    temp_r12 = ((int *)arg3)[10];
    temp_r6 = ((int *)arg3)[11];

    *(int *)((char *)arg0 + 0x1EC) = arg1;
    temp_r4 = *(int *)((char *)arg5 + 0x28);
    *(int *)((char *)arg0 + 0x1F4) = temp_r7;
    *(int *)((char *)arg0 + 0x1F0) = arg2;
    *(int *)((char *)arg0 + 0x1F8) = temp_r27;
    *(int *)((char *)arg0 + 0x1FC) = temp_r26;
    *(int *)((char *)arg0 + 0x200) = temp_r25;
    *(int *)((char *)arg0 + 0x204) = temp_r24;
    *(int *)((char *)arg0 + 0x208) = temp_r23;
    *(int *)((char *)arg0 + 0x20C) = temp_r22;
    *(int *)((char *)arg0 + 0x210) = temp_r21;
    *(int *)((char *)arg0 + 0x214) = zero;
    *(int *)((char *)arg0 + 0x218) = r0;
    *(int *)((char *)arg0 + 0x21C) = temp_r12;
    *(int *)((char *)arg0 + 0x220) = temp_r6;
    *(float *)((char *)arg0 + 0x224) = lbl_8055E3C8;
    *(int *)((char *)arg0 + 0x228) = arg6;
    *(int *)((char *)arg0 + 0x22C) = temp_r11;
    *(int *)((char *)arg0 + 0x230) = temp_r4;
    *(float *)((char *)arg0 + 0x234) = *(float *)((char *)arg5 + 0);
    *(int *)((char *)arg0 + 0x238) = *(int *)((char *)arg5 + 0x24);
    fn_8017B2D0(arg0, *(float *)((char *)arg5 + 4), *(float *)((char *)arg5 + 8), *(float *)((char *)arg5 + 0xC), *(float *)((char *)arg5 + 0x10));
    fn_801D4294(arg0, arg5);
    fc = *(float *)((char *)arg4 + 0);
    fb = *(float *)((char *)arg4 + 4);
    fa = *(float *)((char *)arg4 + 8);
    *(float *)((char *)arg0 + 0x30) = fc;
    *(float *)((char *)arg0 + 0x34) = fb;
    *(float *)((char *)arg0 + 0x38) = fa;
    fn_8017A57C(arg0);
    temp_r6_2 = ((int *)arg3)[8];
    temp_r5 = ((int *)arg3)[9];
    temp_r4_2 = ((int *)arg3)[10];
    t0 = ((int *)arg3)[0];
    t1 = temp_r27;
    t2 = temp_r26;
    t3 = temp_r25;
    *(int *)((char *)arg0 + 0x3C) = t0;
    *(int *)((char *)arg0 + 0x40) = t1;
    *(int *)((char *)arg0 + 0x44) = t2;
    *(int *)((char *)arg0 + 0x48) = t3;
    *(int *)((char *)arg0 + 0x4C) = temp_r24;
    *(int *)((char *)arg0 + 0x50) = temp_r23;
    *(int *)((char *)arg0 + 0x54) = temp_r22;
    *(int *)((char *)arg0 + 0x58) = temp_r21;
    *(int *)((char *)arg0 + 0x5C) = temp_r6_2;
    *(int *)((char *)arg0 + 0x60) = temp_r5;
    *(int *)((char *)arg0 + 0x64) = temp_r4_2;
    *(int *)((char *)arg0 + 0x68) = ((int *)arg3)[11];
    fn_8017A580(arg0, temp_r4_2, temp_r5, temp_r6_2, temp_r21, temp_r22, temp_r23, temp_r24);
}

#pragma push
int fn_801D411C(void *arg0) {
    register char *p = (char *)arg0;
    float sp8;
    float sp10;
    float spc;

    if (*(int *)(p + 0x230) == 2 && *(void **)(p + 0x228) != 0) {
        fn_801A4868(*(void **)(p + 0x228), 1);
    }

    {
        register float neg1000;
        register float one;
        register float zero;

        zero = lbl_80562AB8;
        one = lbl_80562AAC;
        neg1000 = lbl_80562ABC;
        *(float *)(p + 0x220) = zero;

#pragma scheduling off
        *(float *)(p + 0x120) = zero;
        *(float *)(p + 0x11C) = zero;
        *(float *)(p + 0x118) = zero;
        *(float *)(p + 0x12C) = zero;
        *(float *)(p + 0x130) = zero;
        *(float *)(p + 0x124) = zero;
        *(float *)(p + 0x138) = zero;
        *(float *)(p + 0x128) = zero;
        *(float *)(p + 0x134) = zero;
        *(float *)(p + 0x13C) = zero;
        *(float *)(p + 0x16C) = zero;
        *(float *)(p + 0x140) = zero;
        *(float *)(p + 0x144) = zero;
        *(float *)(p + 0x178) = zero;
        *(float *)(p + 0x170) = zero;
        *(float *)(p + 0x180) = zero;
        *(float *)(p + 0x174) = zero;
        *(float *)(p + 0x17C) = zero;

        *(float *)(p + 0x1FC) = zero;
        *(float *)(p + 0x1F8) = zero;
        *(float *)(p + 0x1F4) = one;
        *(float *)(p + 0x208) = zero;
        *(float *)(p + 0x200) = zero;
        *(float *)(p + 0x210) = zero;
        *(float *)(p + 0x204) = one;
        *(float *)(p + 0x20C) = zero;
        *(float *)(p + 0x214) = one;
        *(float *)(p + 0x220) = zero;
        *(float *)(p + 0x218) = zero;
        *(float *)(p + 0x21C) = neg1000;

        *(volatile float *)&spc = zero;
        *(volatile float *)&sp10 = zero;
        *(volatile float *)&sp8 = zero;
        *(float *)(p + 0x30) = zero;
        *(float *)(p + 0x34) = zero;
        *(float *)(p + 0x38) = zero;
#pragma scheduling on
        fn_8017A57C(arg0);

        *(struct Mtx48 *)(p + 0x3C) = *(struct Mtx48 *)(p + 0x1F4);
        fn_8017A580(arg0);

        *(int *)(p + 0x24) = 0;
        *(int *)(p + 0x1EC) = -1;
        return 0;
    }
}
#pragma pop

extern double fn_8002F234(float);
extern void fn_8019F564(void *, void *, float *, void *, float, float, float, float, float, float);
extern void fn_802E317C(const char *, ...);
extern float lbl_80562AAC, lbl_80562AB8, lbl_80562ABC, lbl_80562AC4;
extern char lbl_8033837C[];
extern int lbl_80333918[];
#pragma cplusplus on
extern "C" double fn_8002F234(float);
extern "C" void fn_8019EECC(void *, void *);
extern "C" void fn_8019F564(void *, void *, float *, void *, float, float, float, float, float, float);
extern "C" void fn_802E317C(const char *, ...);
extern "C" float lbl_80562AAC, lbl_80562AB8, lbl_80562AC4;
extern "C" char lbl_8033837C[];
extern "C" int lbl_80333918[];
extern "C" void fn_801D4294(void *arg0, void *arg1) {
    unsigned char *self = (unsigned char *)arg0;
    const unsigned char *src = (const unsigned char *)arg1;
    float size;
    float zero = lbl_80562AB8;
    int mode = *(int *)(src + 0x28);
    volatile float sp10;
    volatile float spc;
    volatile float sp8;
    void *resource;

    sp8 = zero;
    spc = zero;
    sp10 = zero;
    switch (mode) {
    case 0: {
        size = *(float *)(src + 0x2C);
        unsigned char *p;
        float posx;
        float posy;
        int shouldInit;
        *(unsigned int *)(self + 0x23C) = 0x53504852;
        *(float *)(self + 0x240) = size;
        resource = *(void **)(self + 0x244);
        if (resource == 0) break;
        p = (unsigned char *)resource;
        posx = *(float *)(src + 0x14);
        *(void **)(p + 0x0C) = self + 0x3C;
        posy = *(float *)(src + 0x18);
        *(void **)(p + 0x04) = self;
        *(unsigned int *)(p + 0x08) = 0;
        *(unsigned int *)(p + 0x18) = 0x53504852;
        *(float *)(p + 0x10) = posx;
        *(float *)(p + 0x14) = posy;
        *(unsigned int *)(p + 0x20) = 0x64;
        *(unsigned int *)(p + 0x1C) = 0;
        *(void **)p = (void *)&lbl_80333B48;
        shouldInit = arg0 != 0;
        *(volatile float *)(p + 0x28) = sp8;
        *(volatile float *)(p + 0x2C) = spc;
        *(volatile float *)(p + 0x30) = sp10;
        *(float *)(p + 0x24) = size;
        *(float *)(p + 0x34) = zero;
        *(float *)(p + 0x38) = zero;
        *(float *)(p + 0x3C) = zero;
        *(float *)(p + 0x40) = zero;
        *(float *)(p + 0x44) = zero;
        *(float *)(p + 0x48) = zero;
        *(unsigned char *)(p + 0x4C) = 0;
        *(float *)(p + 0x50) = zero;
        *(volatile float *)(p + 0x28) = sp8;
        *(volatile float *)(p + 0x2C) = spc;
        *(volatile float *)(p + 0x30) = sp10;
        if (shouldInit) fn_8019EECC(arg0, p + 0x28);
        break;
    }
    case 1: {
        float x = lbl_80562AC4 * *(float *)(src + 0x30);
        float y = *(float *)(src + 0x2C);
        float xx = x * x;
        float yy = y * y;
        *(unsigned int *)(self + 0x23C) = 0x54554245;
        *(float *)(self + 0x240) = (float)fn_8002F234(yy + xx);
        resource = *(void **)(self + 0x244);
        if (resource != 0) {
            unsigned char *p = (unsigned char *)resource;
            unsigned char *subObj;
            float posx, posy, f, h;
            subObj = self + 0x3C;
            posx = *(float *)(src + 0x14);
            *(void **)(p + 0x0C) = subObj;
            posy = *(float *)(src + 0x18);
            *(void **)(p + 0x04) = self;
            *(unsigned int *)(p + 0x08) = 0;
            *(unsigned int *)(p + 0x18) = 0x54554245;
            f = lbl_80562AC4 * *(float *)(src + 0x30);
            h = *(float *)(src + 0x2C);
            *(float *)(p + 0x10) = posx;
            *(float *)(p + 0x14) = posy;
            *(unsigned int *)(p + 0x20) = 0x64;
            *(unsigned int *)(p + 0x1C) = 0;
            *(float *)(p + 0x24) = h;
            *(float *)(p + 0x28) = f - h;
            *(void **)p = lbl_80333918;
        }
        break;
    }
    case 2: {
        float x = *(float *)(src + 0x30);
        float y = *(float *)(src + 0x2C);
        float xx = x * x;
        float yy = y * y;
        *(unsigned int *)(self + 0x23C) = 0x54554245;
        *(float *)(self + 0x240) = (float)fn_8002F234(yy + xx);
        resource = *(void **)(self + 0x244);
        if (resource != 0) {
            unsigned char *p = (unsigned char *)resource;
            unsigned char *subObj;
            float posx, posy, h, f;
            void *vtable;
            subObj = self + 0x3C;
            posx = *(float *)(src + 0x14);
            *(void **)(p + 0x0C) = subObj;
            posy = *(float *)(src + 0x18);
            *(void **)(p + 0x04) = self;
            *(unsigned int *)(p + 0x08) = 0;
            vtable = lbl_80333918;
            *(unsigned int *)(p + 0x18) = 0x54554245;
            h = *(float *)(src + 0x2C);
            f = *(float *)(src + 0x30);
            *(float *)(p + 0x10) = posx;
            *(float *)(p + 0x14) = posy;
            *(unsigned int *)(p + 0x20) = 0x64;
            *(unsigned int *)(p + 0x1C) = 0;
            *(float *)(p + 0x24) = h;
            *(float *)(p + 0x28) = f;
            *(void **)p = vtable;
        }
        break;
    }
    case 3: {
        float radius = lbl_80562AC4 * *(float *)(src + 0x2C);
        *(unsigned int *)(self + 0x23C) = 0x53504852;
        *(float *)(self + 0x240) = radius;
        resource = *(void **)(self + 0x244);
        if (resource != 0) {
            fn_8019F564(resource, self + 0x3C, (float *)&sp8, self,
                        *(float *)(src + 0x14), *(float *)(src + 0x18),
                        lbl_80562AAC, radius, radius, radius);
        }
        break;
    }
    default:
        fn_802E317C(lbl_8033837C, mode);
        break;
    }

    resource = *(void **)(self + 0x244);
    {
        struct Resource {
            virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
            virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
            virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
            virtual void m12(); virtual void m13();
            virtual void update(int);
            virtual void m14(); virtual void m15();
        };
        ((Resource *)resource)->update(*(int *)(src + 0x1C));
    }
    self[0x1E9] = src[0x20];
    *(int *)(self + 0x24) = *(int *)(self + 0x28);
}
#pragma cplusplus reset
extern float PSVECDotProduct(const void *, const void *);
extern void PSVECCrossProduct(const void *, const void *, float *);
extern float PSVECSquareDistance(const void *, const void *);
extern void fn_8017A580(void *);
extern void fn_8017A57C(void *);
extern void fn_801A4868(void *, int);
extern float lbl_80562AAC, lbl_80562AB8, lbl_80562ABC, lbl_80562AC8, lbl_80562ACC, lbl_80562AD0, lbl_80562AD4;
#pragma push
#pragma processor 750
void fn_801D4598(void *arg0, float farg0) {
    char *p = (char *)arg0;
    float sp8[3], dot, scale;
    void *other;
    dot = PSVECDotProduct(p + 0x54, p + 0x20C);
    if (farg0 < (*(float *)(p + 0x224) + *(float *)(p + 0x234)) ||
        dot < lbl_80562AC8 ||
        ((other = *(void **)(p + 0x22C)) != 0 &&
         PSVECSquareDistance((char *)other + 0x60, p + 0x218) <
         ((lbl_80562AAC + *(float *)(p + 0x240)) * (lbl_80562AAC + *(float *)(p + 0x240))))) {
        float f5, f6, f7;
        float step;
        PSVECCrossProduct(p + 0x54, p + 0x20C, sp8);
        scale = dot - lbl_80562ACC;
        {
            float zero = lbl_80562AB8;
            *(float *)(p + 0x118) = zero;
            *(float *)(p + 0x11C) = zero;
            *(float *)(p + 0x120) = zero;
            zero = (zero < scale) ? zero : scale;
            scale = lbl_80562AD0 + zero;
        }
        scale = (lbl_80562AB8 > scale) ? lbl_80562AB8 : scale;
        f7 = *(float *)(p + 0x124) * scale;
        f6 = *(float *)(p + 0x128) * scale;
        f5 = *(float *)(p + 0x12C) * scale;
        step = lbl_80562AD4;
        *(float *)(p + 0x124) = f7;
        *(float *)(p + 0x128) = f6;
        *(float *)(p + 0x12C) = f5;
        {
            float py = *(float *)(p + 0x21C);
            float px = *(float *)(p + 0x218);
            float pz = *(float *)(p + 0x220);
            *(float *)(p + 0x124) = f7 + sp8[0] * step;
            *(float *)(p + 0x128) = f6 + sp8[1] * step;
            f5 += sp8[2] * step;
            *(float *)(p + 0x64) = py;
            *(float *)(p + 0x60) = px;
            *(float *)(p + 0x68) = pz;
            *(float *)(p + 0x12C) = f5;
        }
        fn_8017A580(arg0);
    } else fn_801D411C(arg0);
}
#pragma pop

int fn_801D470C(void) { return 0; }

void fn_801D4714(void *a, void *b, void *c, int *arg3, int *arg4) { *arg4 = 0; *arg3 = 0; }

int fn_801D4724(void) { return 0; }


