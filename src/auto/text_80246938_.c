typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
extern float lbl_80563898;
extern float lbl_805638A8;
extern double lbl_805638A0;
void fn_80246CAC(float);
void fn_80127464(void);
void fn_802E2D74(s32);
void fn_8020A634(void);
s32 fn_802E2C20(void);
void fn_80214AF0(s32);
void fn_80214A9C(s32);
extern char lbl_80343600[16];
typedef struct Obj_802470D4 {
    void *vtable;
    char pad[0x14];
    s32 field18;
    s32 field1C;
    s32 field20;
    char pad24[0xC];
    s32 *field30;
} Obj_802470D4;
void fn_80235380(s32);
void fn_802C519C(s32);
void fn_802328D4(s32);
void fn_80128668(void *);
s32 fn_802E499C(unsigned short *, unsigned short, unsigned short, unsigned short, unsigned short);
void fn_8020C918(s32);
extern unsigned short lbl_802FA48C[6];
extern float lbl_805638B0;
s32 fn_80221EA8(void);
extern s32 lbl_8055BEF0;
extern void *lbl_8055F278;
extern float lbl_805638C8;
float fn_80214D48(void);


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F260;
extern unsigned char lbl_803432EC[];
extern void fn_80246CB8(void *);
void fn_80246DE8(void) {
    fn_80246CB8(lbl_803432EC);
}

extern unsigned char lbl_803432FC[];
void fn_80246DF4(void) {
    fn_80246CB8(lbl_803432FC);
}

extern unsigned char lbl_8034330C[];
void fn_80246E00(void) {
    fn_80246CB8(lbl_8034330C);
}

Obj_802470D4 *fn_802470D4(Obj_802470D4 *arg0, s32 arg1) {
    s32 *p;
    if (arg0 != 0) {
        arg0->vtable = &lbl_80343600;
        fn_80235380(arg0->field18);
        fn_80235380(arg0->field1C);
        fn_802C519C(arg0->field20);
        p = arg0->field30;
        if (p != 0) {
            fn_802328D4(*p);
            *p = 0;
            fn_80128668(p);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_80247174(void) {
    s32 i = 0;
    do {
        fn_80246CAC(lbl_80563898 - ((float)i / lbl_805638A8));
        fn_80127464();
        fn_802E2D74(0x10);
        i++;
    } while (i < 0x32);
    fn_8020A634();
    fn_80246CAC(lbl_80563898);
}

s32 fn_8024739C(void) { return 0; }

char fn_80247624(void) {
    return lbl_8055F260;
}

s32 fn_8024762C(void) {
    if (fn_802E2C20() % 1500 > 500) fn_80214AF0(1);
    else fn_80214A9C(1);
    return 0;
}

extern void* lbl_8055BEAC;
s32 fn_80214D04(void);
void fn_80247768(void) {
    lbl_8055BEAC = (void*)fn_80214D04();
}

extern void* lbl_8055BEB0;
void fn_80247880(void) {
    lbl_8055BEB0 = (void*)fn_80214D04();
}

extern void* lbl_8055BEB4;
void fn_80247AAC(void) {
    lbl_8055BEB4 = (void*)fn_80214D04();
}

void* fn_8024859C(void *arg0, s32 arg1) {
    void* ptr = arg0;
    if (ptr != 0) {
        *(unsigned char*)((char*)ptr + 0x18) = 0;
        *(unsigned char*)((char*)ptr + 0x50) = 0;
        *(unsigned char*)((char*)ptr + 0x5C) = 0;
        *(s32*)((char*)ptr + 0x24) = 1;
        *(s32*)((char*)ptr + 0x20) = 0;
        *(unsigned char*)((char*)ptr + 0x44) = 0;
        if (arg1 > 0) {
            fn_80128668(ptr);
        }
    }
    return ptr;
}

void fn_802485FC(void) {
    unsigned short a[5];
    a[0] = lbl_802FA48C[0];
    a[1] = lbl_802FA48C[1];
    a[2] = lbl_802FA48C[2];
    a[3] = lbl_802FA48C[3];
    a[4] = 0;
    if (fn_802E499C(a, a[3], a[2], a[1], a[0]) != 0) {
        fn_80246CAC(lbl_805638B0);
        fn_8020C918(1);
    }
}

void fn_80248770(void *arg0) {
    *(unsigned char*)((char*)arg0 + 0x18) = 1;
    *(s32*)((char*)arg0 + 0x1C) = fn_80221EA8();
}

void fn_802487A8(void *arg0) {
    *(unsigned char*)((char*)arg0 + 0x18) = 0;
}

void fn_80248A68(void *arg0) {
    *(float*)((char*)arg0 + 0x1C) = lbl_805638B0;
}

