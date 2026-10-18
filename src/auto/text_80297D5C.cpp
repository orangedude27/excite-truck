// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern "C" int fn_8029C190(void*);

  extern "C" int fn_80287B14(void);
  extern "C" void fn_80299830(void*, int);
  extern "C" void fn_802C8BD0(int);
  extern "C" int fn_802C8DBC(int);
  extern "C" void fn_802C8E48(void);
  extern "C" void fn_802C8D74(void);
  extern "C" void* fn_80299FA8(void*, void*);
  extern "C" void* fn_80299A04(void*, unsigned int);
  extern "C" void fn_8028E584(void*, void*, float*, float);
extern "C" void fn_80288A40(void*, float*);
extern "C" void fn_8028E398(void*);
extern "C" void fn_80128668(void*);
extern "C" float fn_801E7E24(void);
  extern "C" void fn_80298B48(void*);
  extern "C" void fn_802976DC(void);
  extern "C" void fn_80128670(int);
  extern "C" void fn_80298FBC(void*);
extern "C" void fn_802CAC54(int);
extern "C" void fn_8029BDC4(void*);
extern "C" void fn_80299544(void);
extern "C" void fn_802982C0(void);
extern "C" void fn_8029998C(void);
extern "C" void fn_80299FE0(void *, void *, float);
extern "C" void fn_80299A88(void *, void *, unsigned int, float);
extern "C" char lbl_803494D0[];
extern "C" void fn_8029998C(void);
extern "C" void fn_8029A17C(void);
extern void* lbl_8055F7CC;
extern void* lbl_8055F7E0;
extern void* lbl_8055F7C8;
extern void* lbl_8055F7DC;
extern void* lbl_8055F7C4;
extern void* lbl_8055F7C0;
extern void* lbl_8055F7D0;
extern void* lbl_8055F7D8;
extern "C" void fn_80298BBC(void*);
extern "C" void fn_8029BA8C(void*);
extern "C" void fn_80299628(void);
extern "C" void fn_8029871C(void*, void*, float);
extern "C" int fn_802984D0(void*, short*);
extern "C" void fn_802994C0(void*, unsigned int);
extern "C" void fn_80299338(void*, unsigned int, void*, void*, void*, short);
extern float lbl_80564590;
extern float lbl_8056459C;
extern float lbl_80564594;
extern float lbl_80564598;
extern float lbl_805645A0;
extern float lbl_805645A4;
extern float lbl_805645A8;
extern float lbl_805645AC;
extern float lbl_805645B0;
extern float lbl_805645B4;
extern float lbl_80558DC4;
int fn_80297D5C(int* out, int value) {
    int i = 1;
    do {
        if (i * i == value) {
            *out = i;
            return 1;
        }
        i++;
    } while (i <= 0x10);
    return 0;
}

int fn_80297D90(int* out, int value) {
    int i = 0;
    do {
        if ((1 << i) == value) {
            *out = i;
            return 1;
        }
        i++;
    } while (i < 0xa);
    return 0;
}

extern "C" void fn_80297DC8(void* arg0) {
    float f0 = lbl_805645B4;
    float f1 = lbl_805645B0;
    float f2 = lbl_805645AC;
    float f3 = lbl_805645A8;
    float f4 = lbl_805645A4;
    float f5 = lbl_805645A0;
    float f6 = lbl_8056459C;
    float f7 = lbl_80564598;
    float f8 = lbl_80564594;
    float f9 = lbl_80564590;
    float tmp[6];
    float tmp2[3];
    *(int*)((char*)arg0 + 0x4) = 0xC0;
    *(float*)((char*)arg0 + 0x8) = f9;
    *(float*)((char*)arg0 + 0xC) = f8;
    *(int*)arg0 = 1;
    tmp[0] = f7;
    tmp[1] = f8;
    tmp[2] = f7;
    tmp2[0] = f9;
    tmp2[1] = f9;
    tmp2[2] = f9;
    *(float*)((char*)arg0 + 0x10) = tmp[0];
    *(float*)((char*)arg0 + 0x14) = tmp[1];
    *(float*)((char*)arg0 + 0x18) = tmp[2];
    *(float*)((char*)arg0 + 0x1C) = tmp2[0];
    *(float*)((char*)arg0 + 0x20) = tmp2[1];
    *(float*)((char*)arg0 + 0x24) = tmp2[2];
    *(float*)((char*)arg0 + 0x28) = f6;
    *(float*)((char*)arg0 + 0x30) = f5;
    *(float*)((char*)arg0 + 0x50) = f9;
    *(float*)((char*)arg0 + 0x54) = f4;
    *(float*)((char*)arg0 + 0x58) = f3;
    *(float*)((char*)arg0 + 0x5C) = f2;
    *(float*)((char*)arg0 + 0x70) = f1;
    *(float*)((char*)arg0 + 0x68) = f1;
    *(float*)((char*)arg0 + 0x60) = f1;
    *(float*)((char*)arg0 + 0x74) = f0;
    *(float*)((char*)arg0 + 0x6C) = f0;
    *(float*)((char*)arg0 + 0x64) = f0;
    *(float*)((char*)arg0 + 0x80) = f9;
    *(int*)((char*)arg0 + 0x84) = 0x40;
    *(unsigned char*)((char*)arg0 + 0x88) = 1;
    *(int*)((char*)arg0 + 0x44) = 2;
    *(unsigned char*)((char*)arg0 + 0x89) = 1;
}

extern "C" void fn_80297ED4(void) {
}

extern "C" void fn_80298124(void) {
    fn_80298BBC(lbl_8055F7C8);
    fn_8029BA8C(lbl_8055F7D8);
    void *&value = lbl_8055F7C4;
    if (value != (void *)0) fn_80299628();
}

void fn_80298160(void) {
    float value = fn_801E7E24();
    if (__fabsf(value) != lbl_80558DC4) {
        fn_80298B48(lbl_8055F7C8);
        fn_8029BDC4(lbl_8055F7DC);
        if (lbl_8055F7C4 != 0) fn_80299544();
        if (lbl_8055F7C0 != 0) fn_802982C0();
        if (lbl_8055F7CC != 0) fn_8029998C();
        if (lbl_8055F7D0 != 0) fn_8029A17C();
    }
}

extern "C" void* fn_802981EC(unsigned int size) {
    return fn_80299A04(lbl_8055F7CC, size);
}

void fn_802981F8(void* self) {
    float values[3];
    values[0] = lbl_8056459C;
    values[1] = lbl_80564590;
    values[2] = lbl_8056459C;
    fn_8028E584(lbl_8055F7E0, self, values, lbl_8056459C);
    fn_80288A40(self, values);
}

void* __dt__Q216J2DAnmTexPattern27J2DAnmTexPatternTIMGPointerFv_80298250(void* self, int arg1) {
    if (self != 0) {
        fn_8028E398(*(void**)((char*)self + 0xB0));
        if (arg1 > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

void fn_802982A8(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x28) = 0;
    *(unsigned char *)((char *)arg0 + 0x54) = 0;
    *(unsigned char *)((char *)arg0 + 0x80) = 0;
    *(unsigned char *)((char *)arg0 + 0xAC) = 0;
}

extern "C" void fn_80298BBC(void*);
extern "C" void fn_8029BA8C(void*);
extern "C" void fn_80299628(void);
extern void* lbl_8055F7D8;
extern "C" void fn_8029871C(void*, void*, float);
void fn_802982C0(void *arg0) {
    float temp_f31 = fn_801E7E24();
    void *var_r31 = arg0;
    int var_r30 = 0;
    do {
        if (*(unsigned char *)((char *)var_r31 + 0x28) != 0) {
            fn_8029871C(arg0, var_r31, temp_f31);
        }
        var_r30 += 1;
        var_r31 = (char *)var_r31 + 0x2c;
    } while (var_r30 < 4);
}

extern "C" int fn_802984D0(void*, short*);
extern "C" void fn_802994C0(void*, unsigned int);
extern "C" void fn_80299338(void*, unsigned int, void*, void*, void*, short);
void fn_80298458(int arg0, int arg1, short arg2) {
    short value = arg2;
    int item = arg0 + arg1 * 0x2c;
    if (fn_802984D0((void*)item, &value) != 0) {
        fn_802994C0(lbl_8055F7C4, arg1);
        fn_80299338(lbl_8055F7C4, arg1, (void*)item, (void*)(item + 0xc), (void*)(item + 0x18), value);
    }
}

extern "C" void* fn_80298868(void* arg0) {
    char* p = (char*)arg0;
    int i = 0;
    while (i < 4) {
        if (*(unsigned char*)(p + 0x28) == 0) {
            return (void*)(p + i * 0x2C);
        }
        p += 0x2C;
        i++;
    }
    return 0;
}

extern "C" void fn_8029B6E4(void *);
extern "C" void fn_8029B824(void *);
extern "C" void fn_802C9A4C(int, float);
extern float lbl_80564618;
extern "C" void fn_80298A48(void) {
}

extern "C" void* fn_80298A4C(void* arg0, int arg1) {
    if (arg0 != 0) {
        int* p = (int*)arg0;
        if (p[2]) {
            fn_802976DC();
            p[2] = 0;
        }
        fn_8028E398(*(void**)(p + 1));
        if (p[0]) fn_80128670(p[0] - 0x10);
        p[0] = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_80298AD8(void* arg0) {
    int offset = 0;
    int i = 0;
    while (i < fn_80287B14()) {
        i++;
        {
            char* base = (char*)*(void**)arg0;
            *(unsigned char*)(base + offset + 0x19) = 0;
            offset += 0x20;
        }
    }
}

extern "C" void fn_80298B48(void* arg0) {
    int offset = 0;
    int i = 0;
    while (i < fn_80287B14()) {
        unsigned char val = *(unsigned char*)((char*)*(void**)arg0 + offset + 0x19);
        if (val != 0) {
            fn_80298FBC(arg0);
        }
        offset += 0x20;
        i++;
    }
}

extern "C" void* fn_802992C4(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(int*)((char*)arg0 + 0x34) = 0;
        *(int*)((char*)arg0 + 0x74) = 0;
        *(int*)((char*)arg0 + 0xB4) = 0;
        *(int*)((char*)arg0 + 0xF4) = 0;
        fn_802CAC54(*(int*)((char*)arg0 + 0x100));
        *(int*)((char*)arg0 + 0x100) = -1;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

  extern "C" float fn_801E7E18(void);
void fn_802994C0(void* arg0) {
    *(int*)arg0 = -1;
    *(int*)((char*)arg0 + 0x34) = 2;
    *(float*)((char*)arg0 + 0x38) = fn_801E7E18();
}

extern "C" void fn_80299504(void* arg0) {
    float value = lbl_8056459C;
    *(int*)arg0 = -1;
    *(int*)((char*)arg0 + 0x34) = 0;
    *(float*)((char*)arg0 + 0x38) = value;
    *(int*)((char*)arg0 + 0x40) = -1;
    *(int*)((char*)arg0 + 0x74) = 0;
    *(float*)((char*)arg0 + 0x78) = value;
    *(int*)((char*)arg0 + 0x80) = -1;
    *(int*)((char*)arg0 + 0xB4) = 0;
    *(float*)((char*)arg0 + 0xB8) = value;
    *(int*)((char*)arg0 + 0xC0) = -1;
    *(int*)((char*)arg0 + 0xF4) = 0;
    *(float*)((char*)arg0 + 0xF8) = value;
}

void fn_80299628(void* arg0) {
    fn_802C8BD0(*(int*)((char*)arg0 + 0x100));
    if (fn_802C8DBC(0x14) != 0) {
        void* p = arg0;
        int i = 0;
        do {
            if (*(int*)((char*)p + 0x34) != 0) fn_80299830(arg0, i);
            p = (char*)p + 0x40;
            i++;
        } while (i < 4);
        fn_802C8E48();
    }
    fn_802C8D74();
}

extern "C" void* fn_802997F4(void* arg0, int arg1) {
    void* p = arg0;
    int i = 0;
    do {
        if (*(int*)p == arg1) {
            return (char*)arg0 + (i << 6);
        }
        p = (char*)p + 0x40;
        i++;
    } while (i < 4);
    return 0;
}

extern "C" void fn_802C8E00(int, unsigned int, float, float, float, float, float);
extern float lbl_805645E0;
extern float lbl_80564590, lbl_8056459C, lbl_805645E0;
extern "C" void fn_80299830(void* arg0, int arg1) {
    float scale;
    char* var_r31;
    int temp_r0, var_r30, var_r29;
    scale = lbl_805645E0;
    var_r31 = (char*)arg0 + (arg1 << 6);
    temp_r0 = (int)(scale * *(float*)(var_r31 + 0x3C));
    if (temp_r0 >= 1) {
        var_r30 = temp_r0 << 24;
        var_r29 = 0;
        do {
            float var_f4, var_f5;
            int temp_r0_2, temp_r3, value;
            if (var_r29 & 1) var_f4 = lbl_80564590;
            else var_f4 = lbl_8056459C;
            if (var_r29 & 2) var_f5 = lbl_8056459C;
            else var_f5 = lbl_80564590;
            temp_r0_2 = var_r29 ^ 1;
            temp_r3 = temp_r0_2 >> 1;
            value = temp_r0_2 & var_r29;
            value = temp_r3 - value;
            fn_802C8E00(var_r30, (unsigned int)value >> 31,
                *(float*)(var_r31 + 4), *(float*)(var_r31 + 8), *(float*)(var_r31 + 0xC), var_f4, var_f5);
            var_r29++;
            var_r31 += 0xC;
        } while (var_r29 < 4);
    }
}

extern "C" void fn_80299830(void*, int);
extern "C" void fn_802C8BD0(int);
extern "C" int fn_802C8DBC(int);
extern "C" void fn_802C8E48(void);
extern "C" void fn_802C8D74(void);
extern "C" void* fn_80299FA8(void*, void*);
extern "C" void* fn_802998F4(void* arg0, int arg1) {
    if (arg0 != 0) {
        void* p = arg0;
        int i = 0;
        while (1) {
            fn_80299FA8(arg0, p);
            p = (char*)p + 0x9c;
            i++;
            if (i >= *(int*)((char*)arg0 + 0x138))
                break;
        }
        *(int*)((char*)arg0 + 0x138) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_80299988(void) {
}

extern "C" void* fn_80299FA8(void* arg0, void* arg1) {
    fn_8028E398(*(void**)arg1);
    *(void**)arg1 = 0;
}

extern "C" void fn_8029A114(void *arg0) {
    *(float *)((char *)arg0 + 4) = lbl_8056459C;
    *(float *)((char *)arg0 + 0) = lbl_80564590;
    *(float *)((char *)arg0 + 8) = lbl_8056459C;
    *(float *)((char *)arg0 + 0xC) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x10) = lbl_80564590;
    *(float *)((char *)arg0 + 0x14) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x18) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x1C) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x20) = lbl_80564590;
    *(float *)((char *)arg0 + 0x24) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x28) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x2C) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x30) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x34) = lbl_8056459C;
    *(float *)((char *)arg0 + 0x38) = lbl_8056459C;
    *(int *)((char *)arg0 + 0x3C) = -1;
    *(int *)((char *)arg0 + 0x40) = -1;
}

extern "C" void fn_8029A4B4(void);
extern "C" void fn_8029840C(void);
extern "C" void fn_8029A208(void* arg0, int arg1, int arg2) {
    int index;
    unsigned char* entry;
    if (arg2 != 0 && *(int*)((char*)arg0 + 0x40) == -1) {
        fn_8029A4B4();
        return;
    }
    if (arg2 == 0 && arg1 == *(int*)((char*)arg0 + 0x3C)) {
        register int index2 = *(int*)((char*)arg0 + 0x40);
        if (index2 != -1) {
            entry = (unsigned char*)lbl_8055F7C0 + index2 * 0x2C;
            if (entry[0x28] != 0)
                fn_8029840C();
            *(int*)((char*)arg0 + 0x40) = -1;
        }
    }
}

extern "C" int fn_8029A290(void *arg0, void *arg1) {
    extern float PSVECSquareDistance(const void *, const void *);
    extern float PSVECDotProduct(const void *, const void *);
    extern float lbl_80564604;
    double temp_f31 = (double)lbl_80564594;
    int var_r31 = 1;
    int var_r30 = 0;
    void *var_r29 = arg0;
    if (PSVECSquareDistance((char *)arg0 + 0x24, (char *)arg1 + 0x24) > (float)temp_f31) {
        return var_r31;
    }
    if (PSVECDotProduct((char *)arg0 + 0x24, (char *)arg1 + 0x24) > lbl_80564604) {
        return var_r31;
    }
    var_r31 = 0;
    return var_r31;
}

extern "C" void fn_8029A890(void *arg0, void *arg1) {
    *(float *)((char *)arg0 + (int)arg1 * 0x2C + 0x24) = lbl_80564590;
}

extern "C" void fn_8029A8A4(void *arg0, void *arg1) {
    *(unsigned char *)((char *)arg0 + (int)arg1 * 0x2C + 0x28) = 1u;
}

void fn_8029B138(void *arg0, int arg1, float *arg2, float *arg3, float *arg4, float *arg5) {
    float temp_f1;
    float temp_f1_2;
    temp_f1 = *(float *)((char *)arg0 + 0x1F8) * (float)(arg1 & (*(int *)((char *)arg0 + 0x1EC) - 1));
    *arg2 = temp_f1;
    *arg3 = temp_f1 + *(float *)((char *)arg0 + 0x1F8);
    temp_f1_2 = *(float *)((char *)arg0 + 0x1F8) * (float)(arg1 >> *(int *)((char *)arg0 + 0x1F0));
    *arg4 = temp_f1_2;
    *arg5 = temp_f1_2 - *(float *)((char *)arg0 + 0x1F8);
}

extern "C" int fn_802CAC28(int, int);
extern "C" int fn_80297D5C(void*, int);
extern "C" int fn_80297D90(void*, int);
extern "C" int fn_802E317C(const char*, ...);
extern "C" int fn_801284F8(int, const char*);
extern "C" int fn_8029ADCC(void);
extern "C" int fn_8029BA0C(void*);
extern "C" int fn_801EF024(void*);
extern "C" void __dt__Q210JASDrumSet5TPercFv_8029AE88(void*, int);
extern "C" int fn_8029BFF8(void*);
extern int lbl_8055CA84;
extern int lbl_8055CA88;
extern const char lbl_8034951C[];
extern const char lbl_80349550[];
extern double lbl_805645F8;
extern int lbl_8055CA84, lbl_8055CA88;
extern const char lbl_8034951C[], lbl_80349550[];
void fn_8029B1B8(void* arg0) {
    char* p=(char*)arg0;
    *(int*)(p+0x1E4)=fn_802CAC28(lbl_8055CA84,0);
    *(int*)(p+0x1E8)=fn_802CAC28(lbl_8055CA88,0);
    if (fn_80297D5C(p+0x1EC,0x10) == 0 || fn_80297D90(p+0x1F0,*(int*)(p+0x1EC)) == 0)
        fn_802E317C(lbl_8034951C);
    *(int*)(p+0x1F4)=0x10-(*(unsigned short*)(p+0x1F0)<<1);
    *(float*)(p+0x1F8)=lbl_80564590 / (float)*(unsigned short*)(p+0x1EC);
}

void* fn_8029B9A4(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_801EF024((void*)fn_8029BFF8);
        __dt__Q210JASDrumSet5TPercFv_8029AE88(*(void**)arg0, 1);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern "C" int fn_8029AF24(int); void fn_8029BA8C(int* arg0) { fn_8029AF24(*arg0); }

extern "C" void* fn_8029BD54(void* arg0, int arg1) {
    if (arg0 != 0) {
        fn_801EF024((void*)fn_8029C190);
        fn_8028E398(*(void**)arg0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" void fn_8029BEF8(void);
extern "C" int fn_801EEFDC(void*, int);
extern "C" int fn_8029C190(void*);
extern "C" void fn_80288208(int);
extern "C" int fn_80287B14(void);
extern "C" int fn_8029AEE8(void*);
extern "C" int fn_8029AF24(int);
extern "C" void fn_8029BDB8(void *arg0) {
    *(int *)((char *)arg0 + 0xA4) = 0;
}

extern "C" void fn_80288A58(void*, float*);
extern "C" void fn_8029BEF8(void);
extern "C" int fn_801EEFDC(void*, int);
extern "C" int fn_8029C190(void*);
extern "C" void fn_80288208(int);
extern "C" int fn_80287B14(void);
extern "C" int fn_8029AEE8(void*);
extern "C" void fn_8029BDC4(void* arg0) {
    float values[3];
    int i = 0;
    char* entry = (char*)arg0 + 4;
    values[0] = lbl_8056459C;
    values[1] = lbl_8056459C;
    values[2] = lbl_8056459C;
    do {
        if (*(unsigned char*)(entry + 0x10)) {
            fn_80288A58(entry, values);
            fn_8028E584(*(void**)arg0, entry, values, 0.0f);
        }
        entry += 0x14;
        i++;
    } while (i < *(int*)((char*)arg0 + 0xA4));
}

extern "C" void fn_802CAC54(int);
extern float lbl_805645B8;
extern "C" void fn_8029A890(void*, void*);
extern "C" void fn_8029BA94(void*, void*);
extern "C" int fn_8029C024(int*);
extern "C" int fn_8029C054(int*);
extern "C" void fn_8029BE54(void*, void*);
void fn_8029BE54(void* arg0, void* arg1) {
    int count = *(int*)((char*)arg0 + 0xA4);
    void* scan = arg0;
    int i = 0;
    while (i < count) {
        unsigned int key = *(unsigned int*)((char*)arg1 + 0xC);
        if (key == *(unsigned int*)((char*)scan + 0x10)) {
            char* dst = (char*)arg0 + i * 0x14;
            int a = *(int*)arg1;
            int b = *((int*)arg1 + 1);
            int c = *((int*)arg1 + 2);
            unsigned char d = *((unsigned char*)arg1 + 0x10);
            *(int*)(dst + 4) = a;
            *(int*)(dst + 8) = b;
            *(int*)(dst + 0xC) = c;
            *(unsigned int*)(dst + 0x10) = key;
            *(unsigned char*)(dst + 0x14) = d;
            return;
        }
        scan = (char*)scan + 0x14;
        i++;
    }
    {
        char* dst = (char*)arg0 + count * 0x14;
        int a = *(int*)arg1;
        int b = *((int*)arg1 + 1);
        int c = *((int*)arg1 + 2);
        int key = *((int*)arg1 + 3);
        unsigned char d = *((unsigned char*)arg1 + 0x10);
        *(int*)(dst + 4) = a;
        *(int*)(dst + 8) = b;
        *(int*)(dst + 0xC) = c;
        *(int*)(dst + 0x10) = key;
        *(unsigned char*)(dst + 0x14) = d;
    }
    *(int*)((char*)arg0 + 0xA4) = count + 1;
}

int fn_8029BFF8(void* arg0) {
    fn_8029BA94(lbl_8055F7D8, arg0);
    return 0x10;
}

extern void* lbl_8055F7D4;
#pragma dont_inline on
extern "C" int fn_8029C024(int *arg0) {
#pragma dont_inline on
    register int *p = arg0;
    int value = *(volatile int *)p;
    fn_8029A890(lbl_8055F7D4, (void *)value);
    return 4;
#pragma dont_inline reset
}

extern "C" void fn_80298DE0(void*, void*, int);
extern "C" void fn_8029BBD4(void*, void*, int);
extern "C" void fn_8029A208(void*, int, int);
extern "C" void fn_8029A904(void*, void*, float, float);
void fn_8029C084(void* arg0, int arg1) {
    float temp_f31 = fn_801E7E24();
    if (__fabsf(temp_f31) != lbl_80558DC4) {
        int i = 0;
        while (i < arg1) {
            unsigned char flag = *(unsigned char*)((char*)arg0 + 0xC);
            int flag2 = 0;
            void* obj = *(void**)((char*)arg0 + 4);
            void* data = *(void**)arg0;
            if (flag != 0 && *(int*)((char*)data + 0x5C) == 0xB) {
                flag2 = 1;
            }
            fn_80298DE0(lbl_8055F7C8, obj, flag2);
            fn_8029BBD4(lbl_8055F7D8, obj, flag);
            if (lbl_8055F7D0 != 0) {
                int flag3 = 0;
                if (flag != 0 && *(int*)((char*)data + 0x5C) == 0xC) {
                    flag3 = 1;
                }
                fn_8029A208(obj, flag3, 0);
            }
            if (lbl_8055F7D4 != 0) {
                fn_8029A904(obj, data, temp_f31, *(float*)((char*)arg0 + 8));
            }
            arg0 = (char*)arg0 + 0x10;
            i++;
        }
    }
}

#pragma dont_inline reset
int fn_8029C190(void* arg0) {
    fn_8029BE54(lbl_8055F7DC, arg0);
    return 0x14;
}

