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
extern void *volatile lbl_8055F278;

typedef struct lbl_8055F278_struct {
    char pad00[0x04];
    s32 unk04;
    s32 unk08;
    char pad0C[0x38];
    unsigned char unk44;
    char pad45[0x03];
    s32 unk48;
    s32 unk4C;
    unsigned char unk50;
    char pad51[0x03];
    s32 unk54;
    s32 unk58;
    unsigned char unk5C;
} lbl_8055F278_struct;
extern float lbl_805638B0;
#pragma push
#pragma small_data off
extern float lbl_805638C8;
#pragma pop
float fn_80214D48(void);
unsigned char fn_802E8690(s32);
void fn_80221F94(void *, s32);
#pragma push
#pragma small_data off
extern float lbl_805638CC;
#pragma pop
extern float lbl_80558DC4[];


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F260;
extern unsigned char lbl_803432EC[];
extern void fn_80246CB8(void *);
extern char lbl_80343780[];
extern float lbl_8055F264;
int fn_80246AA8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

int fn_80246DA8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

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

int fn_80246E0C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
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

extern s32 lbl_8055BEA8;
extern s32 lbl_8055BEBC;
extern void* lbl_8055BEAC;
s32 fn_80214D04(void);
void fn_80247768(void) {
    lbl_8055BEAC = (void*)fn_80214D04();
}

extern void* lbl_8055BEB0;
extern s32 lbl_8055BEB4;
void fn_80247880(void) {
    lbl_8055BEB0 = (void*)fn_80214D04();
}

void fn_80247A0C(void) {
    s32 var_r31;
    s32 val;
    int flag;

    if (lbl_8055BEBC != lbl_8055BEA8) {
        val = lbl_8055BEA8;
        flag = val == 5;
        lbl_8055BEBC = val;
        lbl_8055BEB4 = flag;
    }
    fn_80214CB4(lbl_8055BEB4);
    if (lbl_8055BEBC == 4) {
        fn_80214B44(2);
    }
    var_r31 = 0;
    do {
        if (fn_8027B9EC(var_r31) == 0) {
            fn_80214A9C(var_r31 + 0xB);
        }
        var_r31 += 1;
    } while (var_r31 < 2);
}

void fn_80247AAC(void) {
    lbl_8055BEB4 = (s32) (void*)fn_80214D04();
}

void *fn_80248140(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((unsigned int)arg0 + 0x18 != 0) {
            if ((unsigned int)arg0 + 0x18 != 0) {
                *(int *)((char *)arg0 + 0x18) = 0;
                *(int *)((char *)arg0 + 0x1C) = 0;
                *(int *)((char *)arg0 + 0x20) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_80248398(void) {
    lbl_8055F278_struct *s;
    s32 a;
    s32 b;

    if (lbl_8055F278 != 0) {
        s = (lbl_8055F278_struct *)lbl_8055F278;
        a = s->unk04;
        b = s->unk08;
        s->unk50 = 1;
        s->unk48 = lbl_8055BEF0 + a;
        s->unk4C = b;
        s = (lbl_8055F278_struct *)lbl_8055F278;
        s->unk5C = 1;
        s->unk54 = a;
        s->unk58 = b;
        s->unk44 = 0;
    }
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

s32 fn_802485FC(void) {
    unsigned short args[5];
    unsigned short *p = lbl_802FA48C;

    args[0] = *p++;
    args[1] = *p++;
    args[2] = *p++;
    args[3] = *p++;
    args[4] = *p++;
    if (fn_802E499C(args, args[3], args[2], args[1], args[0]) != 0) {
        fn_80246CAC(lbl_805638B0);
        fn_8020C918(1);
    }
    return 0;
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

void fn_80248A74(void *arg0) {
    s32 var_r31;
    union {
        double d;
        unsigned int u[2];
    } t;

    if (*(float *)((char *)arg0 + 0x1C) > lbl_805638C8) {
        var_r31 = 0xC8;
    } else {
        var_r31 = 0x32;
    }
    t.u[1] = (unsigned int)var_r31 ^ 0x80000000;
    t.u[0] = 0x43300000;
    *(float *)((char *)arg0 + 0x1C) += (t.d - lbl_805638A0) * fn_80214D48();
}

void fn_80248BD0(void *arg0) {
    *(float *)((char *)arg0 + 0x20) = lbl_805638CC;
    *(unsigned char *)((char *)arg0 + 0x1C) = fn_802E8690(*(s32 *)((char *)arg0 + 0x18));
}

void fn_80248C0C(void *arg0) {
    unsigned char res;
    float *fp = (float *)((char *)arg0 + 0x20);

    res = fn_802E8690(*(s32 *)((char *)arg0 + 0x18));
    *(unsigned char *)((char *)arg0 + 0x1C) = res;
    if (res != 0) {
        *fp = lbl_805638CC;
        fn_80214A9C(0x1E);
    } else {
        *fp -= fn_80214D48();
        fn_80214AF0(0x1E);
    }
    if (*fp < lbl_80558DC4[0]) {
        fn_80221F94(arg0, 0);
    }
}

int fn_80248C94(void *arg0, int arg1) {
    if (*(unsigned char *)((char *)arg0 + 0x1C) == 0 && arg1 == 13) {
        fn_80221F94(arg0, 0);
        return 1;
    } else {
        return 0;
    }
}

void fn_802490AC(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;

    *(p + 0x1C) = 0;
    *(s32 *)((char *)arg0 + 0x18) = fn_802E2C20();
    if (fn_802C9A58() != 0) {
        fn_80214A9C(1);
    } else {
        fn_80214A9C(2);
    }
}

