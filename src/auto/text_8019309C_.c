// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).

    extern void fn_801958D8(void);
    extern void fn_80195F6C(void *, void *);
    extern void fn_80194624(void *);
    extern void fn_80195654(void *);
    extern void fn_801933FC(void *, void *);
    extern double fn_8002F234(float);
    extern float lbl_8055E584, lbl_8055E588;
    extern void fn_80129DC4(int, float, float);
    extern void fn_8013530C(void *, int);
    extern int lbl_8055E550;
    extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204;

    typedef unsigned char u8;
extern void *lbl_804349C0[];
extern float lbl_8056223C, lbl_8055E57C;
extern int lbl_804348E8[];
extern void *lbl_804349E0[];
extern int lbl_80333390;
void fn_801964D0(void);
void fn_80128668(void *);
void fn_80193138(int);

extern unsigned char lbl_8055A4B8[];
extern float lbl_80562178, lbl_8056217C, lbl_8055E558;
extern void fn_8017B4E0(void *, float *, float *, float);
extern void fn_80193D30(void *);
extern int fn_802E30C8(const char *, ...);
extern char lbl_80333198[];

int fn_8019309C(void *arg0, int index, signed char arg2) {
    void *entry = lbl_804349C0[index];
    int result = 0;
    if (entry != 0 && *((u8 *)entry + 0x2A4) != 0) {
        result = 1;
        *((u8 *)entry + 0x2FC) = *((unsigned int *)((char *)arg0 + 0x290));
        *((u8 *)arg0 + 0x2FD) = arg2;
    }
    return result;
}

u8 fn_801930DC(void *unused, int index) {
    void *entry;
    entry = lbl_804349C0[index];
    if (entry != 0 && *((u8 *)entry + 0x2A4) != 0)
        return *((u8 *)entry + 0x2FD);
    return 0;
}

int fn_80193110(void *arg0, int arg1) {
    u8 value = arg1;
    if (*((u8 *)arg0 + 0x2FC) == value) {
        *((u8 *)arg0 + 0x2FC) = 0xFF;
        return 1;
    }
    return 0;
}

void fn_80193138(int index) {
    void *entry;
    entry = lbl_804349C0[index];
    if (entry) *((u8 *)entry + 0x304) = 0x14;
}

void fn_8019315C(void *unused, int index) {
    void *entry = lbl_804349C0[index];
    if (entry) ++*(int *)((char *)entry + 0x300);
}

u8 fn_80193184(void *unused, int index) {
    void *entry;
    entry = lbl_804349C0[index];
    if (entry != 0) return *((u8 *)entry + 0x2FE);
    return 0;
}

float fn_801931AC(float a, float b, float c, float d) {
    float value = lbl_80562140 - a / d;
    if (value > lbl_80562140) value = lbl_80562140;
    if (value > lbl_80562144) value = lbl_80562144;
    return b + value * (c - b);
}

float fn_801931EC(float a, float b) {
    float quotient;
    float value;
    float floor;
    quotient = a / b;
    value = lbl_80562140;
    floor = lbl_8055E558;
    if (value < value - quotient) {
        value = value - quotient;
    }
    if (value > floor) return value;
    return floor;
}

void fn_801933FC(void *arg0, void *arg1) {
    fn_8019330C(arg1, arg0, *(int *)((char *)arg0 + 0x294) + 0x70);
}

void fn_801935EC(void *arg0) {
    float value = lbl_80562144;
    *(float *)((unsigned char *)arg0 + 0x224) = value;
    *(float *)((unsigned char *)arg0 + 0x228) = value;
    *(float *)((unsigned char *)arg0 + 0x22C) = lbl_8055E3C8;
}

void fn_8019386C(void) {
    fn_80193CE0();
}

void fn_80193878(void *arg0) {
    float a[3], b[3], low[3];
    void *obj;
    low[0] = lbl_8056217C;
    low[1] = lbl_80562144;
    low[2] = lbl_80562144;
    a[0] = lbl_80562144;
    a[1] = lbl_80562144;
    a[2] = lbl_80562178;
    obj = *(void **)((unsigned char *)arg0 + 0x294);
    b[0] = *(float *)((unsigned char *)obj + 0x94) + low[0];
    b[1] = *(float *)((unsigned char *)obj + 0x98) + a[0];
    b[2] = *(float *)((unsigned char *)obj + 0x9C) + a[0];
    fn_8017B4E0(*(void **)((unsigned char *)arg0 + 0x294), a, b, lbl_80562140);
}

extern unsigned char lbl_8055A4B8[];
extern void fn_801945F8(void *);
extern float lbl_80562140, lbl_80562144, lbl_80562178, lbl_8056217C;
extern void fn_8017B4E0(void *, float *, float *, float);
extern void fn_80193D30(void *);
extern void fn_801942F0(void *, int);
extern int fn_802E30C8(const char *, ...);
extern char lbl_80333198[];
void fn_801939C8(void *arg0) {
    void *obj;
    if (*(unsigned char *)((unsigned char *)arg0 + 0x2A4)) {
        fn_802E30C8(lbl_80333198, *(int *)((unsigned char *)arg0 + 0x290));
    } else {
        obj = *(void **)((unsigned char *)arg0 + 0x294);
        *(unsigned char *)((unsigned char *)arg0 + 0x2A4) = 1;
        *(float *)((unsigned char *)arg0 + 0x24C) = *(float *)((unsigned char *)obj + 0x5B0);
        fn_801942F0(arg0, 1);
        fn_80193D30(arg0);
    }
}

void fn_80193A38(void *arg0) {
    void *obj = *(void **)((unsigned char *)arg0 + 0x294);
    *(unsigned char *)((unsigned char *)arg0 + 0x2A4) = 0;
    *(int *)((unsigned char *)obj + 0x24) = *(int *)((unsigned char *)obj + 0x28);
}

void *fn_80193A50(void *arg0, int arg1) {
    if (arg0 != 0) {
        int index = *(int *)((char *)arg0 + 0x290);
        if (index != -1000) {
            ((int *)lbl_804349C0)[index] = 0;
        }
        lbl_8055E550 -= 1;
        if ((char *)arg0 + 0x168 != 0) {
            fn_8013530C((char *)arg0 + 0x19C, -1);
            fn_8013530C((char *)arg0 + 0x168, -1);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_80193CD4(void *arg0) {
    *(signed char *)((char *)arg0 + 0x2A5) = 1;
}

void fn_80193D20(void) {
    fn_80129DC4(3, lbl_8055E584, lbl_8055E588);
}

void fn_8019416C(void) {

}

typedef unsigned int u32;
extern float lbl_80562140, lbl_80562144;
extern void fn_8018ADB4(int, float);
extern void fn_8018ADBC(int, float);
void fn_80194170(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80562140) value = arg1;
    else value = lbl_80562140;
    if (value > lbl_80562144) value = lbl_80562144;
    *(float *)((char *)arg0 + 0x240) = value;
    fn_8018ADB4(*(int *)((char *)arg0 + 0x294), value);
}

void fn_801942B8(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80562140) value = arg1;
    else value = lbl_80562140;
    if (value > lbl_80562144) value = lbl_80562144;
    *(float *)((char *)arg0 + 0x244) = value;
    fn_8018ADBC(*(int *)((char *)arg0 + 0x294), value);
}

void fn_801942F0(void *arg0, int arg1) {
    if ((*(int *)((unsigned char *)arg0 + 0x2D0) & 0x20) || arg1 != 0) {
        *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x294) + 0x267C) = 1;
    } else {
        *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x294) + 0x267C) = 0;
    }
}

extern float lbl_8055A488;
extern float lbl_8056215C;
void fn_801945F8(void *arg0) {
    if (*(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x294) + 0x1F0) != 0x50 ||
        *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x288) + 0x24) == 3) {
        fn_80194590(arg0);
    }
}

void fn_80194AF4(void *unused, float *out, float *a, float *b, float t) {
    float x, y;
    double pair;
    x = a[1] + t * (b[1] - a[1]);
    y = a[0] + t * (b[0] - a[0]);
    pair = (double)y;
    out[0] = (float)pair;
    out[1] = x;
    out[2] = a[2] + t * (b[2] - a[2]);
}

extern float lbl_8055A488, lbl_8056215C;
extern float PSVECDotProduct(const void *, const void *);
extern void fn_8013B744(int);
extern void fn_80194FD0(void);
void fn_80194F70(void *arg0, float *a, float *b) {
    float x, y, z;
    x = a[0] - b[0];
    y = a[1] - b[1];
    z = a[2] - b[2];
    PSVECDotProduct(arg0, &x);
}

void fn_80194FC4(void) {

}

void fn_80194FC8(void *arg0) {
    fn_8013B744(*(int *)((unsigned char *)arg0 + 0x290));
}

void fn_801955F0(void *arg0, float *arg1) {
    float scale;
    fn_80194FD0();
    scale = *(float *)((unsigned char *)arg0 + 0x2B8);
    arg1[0] += *(float *)((unsigned char *)arg0 + 0x58) * scale;
    arg1[1] += *(float *)((unsigned char *)arg0 + 0x5C) * scale;
}

void fn_80195830(void *arg0) {
    float x, y, scale;
    fn_80195654((unsigned char *)arg0 + 0x20);
    fn_801933FC(arg0, (unsigned char *)arg0 + 0x20);
    x=*(float *)((unsigned char *)arg0+0x20); y=*(float *)((unsigned char *)arg0+0x24);
    *(float *)((unsigned char *)arg0+0x40)=x; *(float *)((unsigned char *)arg0+0x44)=y;
    scale=(float)fn_8002F234(x*x+y*y);
    if (lbl_80562148 > scale) {} else { scale=lbl_80562148; }
    scale=lbl_80562140/scale;
    *(float *)((unsigned char *)arg0+0x40)*=scale;
    *(float *)((unsigned char *)arg0+0x44)*=scale;
}

extern void fn_801958D8(void);
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern float lbl_8055E3C8;
extern float lbl_80562144;
extern void fn_80195654(void *);
extern void fn_801933FC(void *, void *);
extern double fn_8002F234(float);
extern float lbl_80562140;
extern float lbl_80562148;
extern float lbl_80562204;
void fn_801958C4(void *arg0) { *(float *)((unsigned char *)arg0+0x248) *= lbl_80562204; }

void fn_801961F8(void) {

}

extern float fn_801671FC(int);
extern int fn_801B89F8(void);
extern int lbl_8055E0D0;
extern void fn_8018ADAC(int, float);
extern void fn_8018AE24(int, int);
extern void fn_80136EA4(int, int);
extern void fn_80136E8C(int, int, int);
void fn_80196328(void *arg0) {
    float value = lbl_80562140;
    fn_8018ADBC(*(int *)((char *)arg0 + 0x294), value);
    fn_8018ADB4(*(int *)((char *)arg0 + 0x294), lbl_80562144);
    fn_8018ADAC(*(int *)((char *)arg0 + 0x294), lbl_80562144);
    fn_8018AE24(*(int *)((char *)arg0 + 0x294), 0);
    fn_80136EA4(lbl_8055E0D0, *(int *)((char *)arg0 + 0x290));
    fn_80136E8C(lbl_8055E0D0, *(int *)((char *)arg0 + 0x290), 0);
}

extern int fn_801B2F24(void);
extern void fn_801B2F40(int);
extern int fn_8019643C(void);

void fn_8019639C(void) {
    fn_80194844();
}

void fn_80196414(void *arg0) {
    fn_80196DC4(arg0);
}

extern int fn_801B2F24(void);
extern void fn_801B2F40(int);
extern int fn_8019643C(void);
int fn_80196468(int arg0) {
    int end = fn_801B2F24();
    int i = arg0;
    while (i <= end) {
        fn_801B2F40(i - 1);
        if (fn_8019643C() != 0)
            return 1;
        i++;
    }
    return 0;
}

void fn_80196A9C(void) {
    fn_8019684C();
}

void fn_80198488(void *arg0) {
    int a;
    int b;
    int zero;
    int limit;
    a = *((unsigned char *)arg0 + 0x9C);
    b = *((unsigned char *)arg0 + 0x74);
    limit = (int)*(float *)((unsigned char *)arg0 + 0x2F4);
    if (b + a + 1 > limit) {
        zero = (*(int *)((unsigned char *)arg0 + 0x18) == 0);
        if (zero) {
            if (b != 0) {
                if (*((unsigned char *)arg0 + 0x74) != 0)
                    fn_80193138(*(int *)((unsigned char *)arg0 + 0x90));
                else
                    fn_80193138(-1);
            }
        } else if (a != 0) {
            if (*((unsigned char *)arg0 + 0x9C) != 0)
                fn_80193138(*(int *)((unsigned char *)arg0 + 0xB8));
            else
                fn_80193138(-1);
        }
    }
}

void *fn_80198DD0(void *arg0, int arg1) {
    int i;
    int count;
    void **items;
    if (arg0 == 0) return arg0;
    *(void **)arg0 = &lbl_80333390;
    count = *(int *)((unsigned char *)lbl_804349E0 + 0x20);
    items = (void **)lbl_804349E0;
    for (i = 0; i < count; i++) {
        if (items[i] == arg0) {
            count--;
            *(int *)((unsigned char *)lbl_804349E0 + 0x20) = count;
            items[i] = items[count];
        }
    }
    if (arg1 > 0) fn_80128668(arg0);
    return arg0;
}

void fn_80198EA0(void) {
    fn_80198E7C();
}

typedef unsigned char u8;
extern void *lbl_804349C0[];
extern void *lbl_804349E0[];
extern int lbl_80333390;
void fn_801964D0(void);
void fn_80128668(void *);
void fn_80193138(int);
void fn_801964D0(void);
void fn_80128668(void *);
void fn_80193138(int);
extern float fn_801671FC(int);
extern int fn_801B89F8(void);
extern int lbl_8055E0D0;
extern void fn_8018ADBC(int, float);
extern void fn_8018ADB4(int, float);
extern void fn_8018ADAC(int, float);
extern void fn_8018AE24(int, int);
extern void fn_80136EA4(int, int);
extern void fn_80136E8C(int, int, int);
int fn_80198EA4(void) { return 0; }
extern void fn_801958D8(void);
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern void fn_80195654(void *);
extern void fn_801933FC(void *, void *);
extern double fn_8002F234(float);
extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204;
