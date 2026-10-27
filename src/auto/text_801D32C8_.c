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
int fn_801D3FA4(int, int, int, int, int, int, int);
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
#pragma scheduling on
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
#pragma paired reset
#pragma paired_single reset
struct Mtx48 {
    int w[12];
};
extern void fn_801A4868(void *, int);
extern void fn_8017A57C(void *);
extern void fn_8017A580(void *);
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


