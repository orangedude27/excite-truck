// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

  extern "C" void* fn_80299A04(void*, unsigned int);
  extern "C" void fn_8028E584(void*, void*, float*, float);
extern "C" void fn_80288A40(void*, float*);
extern "C" void fn_8028E398(void*);
extern "C" void fn_80128668(void*);
extern "C" float fn_801E7E24(void);
extern "C" void fn_80298B48(void*);
extern "C" void fn_8029BDC4(void*);
extern "C" void fn_80299544(void);
extern "C" void fn_802982C0(void);
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

extern "C" void fn_80297ED4(void) {
}

void fn_80298124(void) {
    fn_80298BBC(lbl_8055F7C8);
    fn_8029BA8C(lbl_8055F7D8);
    if (lbl_8055F7C4 != 0) fn_80299628();
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

void *fn_80299A04(void *, unsigned int);
extern void *lbl_8055F7CC;
void* fn_802981EC(unsigned int size) {
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

extern "C" void fn_8029A890(void *arg0, void *arg1) {
    *(float *)((char *)arg0 + (int)arg1 * 0x2C + 0x24) = lbl_80564590;
}

extern "C" void fn_8029A8A4(void *arg0, void *arg1) {
    *(unsigned char *)((char *)arg0 + (int)arg1 * 0x2C + 0x28) = 1;
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

void* fn_8029B9A4(void* arg0,int arg1) {
    if (arg0) {
        fn_801EF024((void*)fn_8029BFF8);
        __dt__Q210JASDrumSet5TPercFv_8029AE88(*(void**)arg0,1);
        if (arg1>0) fn_80128668(arg0);
    }
    return arg0;
}

extern "C" int fn_8029AF24(int); void fn_8029BA8C(int* arg0) { fn_8029AF24(*arg0); }

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
extern "C" int fn_8029C024(int *arg0) {
    int value = *arg0;
    fn_8029A890(lbl_8055F7D4, (void *)value);
    return 4;
}

int fn_8029C190(void* arg0) {
    fn_8029BE54(lbl_8055F7DC, arg0);
    return 0x14;
}

