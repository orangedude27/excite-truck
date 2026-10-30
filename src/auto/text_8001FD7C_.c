#include <types.h>
extern int lbl_8055D668, lbl_8055D66C;
extern char *lbl_80558D8C;
extern int fn_8000DA10(void);
extern int fn_8001BA90(int, int, int, int, int);
extern void fn_8001BA70(int, int, unsigned char *, int);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055D644;
extern unsigned char lbl_8055D645;
extern int lbl_8055D638;
extern int lbl_8055D63C;
extern int lbl_8055D640;
extern unsigned char lbl_8055D670;
extern int lbl_8055D64C;
extern unsigned int lbl_8055E044;
extern float lbl_805604A8;
extern float lbl_805604AC;
extern float lbl_805604B0;
extern float lbl_805604B4;
extern float lbl_805604B8;
extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);
extern void fn_801345D8(void*, ...);
  extern void fn_8000B3DC(s32);
  extern unsigned char lbl_8055D648;
  extern void fn_80230AD8(void*);
  extern void fn_80230B38(void*);
  extern void fn_80230B5C(void*);
  extern void fn_800209A0(int, float);
void fn_8001FD7C(void);
void fn_8001FF34(int);
struct cfg_t {
    char f0[0xc];
    char f1[0xc];
    char f2[0x10];
    char f3[0x10];
    char f4[0x10];
    char f5[0x10];
    char f6[0x10];
    char f7[0x10];
};
struct lbl_8035BAE4_t {
    int unk_0;
    int unk_4;
    unsigned int unk_8;
};
extern struct lbl_8035BAE4_t lbl_8035BAE4;
extern char lbl_802FE1C0[0x100];
int fn_802E2C20(void);
extern int lbl_8055D630;
extern int lbl_8055D634;
extern char lbl_8035B758[];
extern float lbl_805604BC;
extern float lbl_805604C0;
extern float lbl_805604C4;
extern float lbl_805604C8;
extern float lbl_805604CC;
extern float lbl_805604D0;
extern float lbl_805604D4;
extern float lbl_805604D8;
extern float lbl_805604DC;
extern float lbl_805604E0;
extern void fn_802A1120(float*, float*, float);
extern double cos(double);
extern float fn_801EA0E8(float, float, float, float, float, float, float);
extern void fn_8026E22C(float*, void*, void*, float);
extern void fn_80020070(float*);
extern double lbl_805604E8;
void fn_80176734(void);
int fn_801312EC(void*, void*);
void fn_80131318();
int fn_80232BA4(int, int, int, int, float, float, float, float, float);

#pragma scheduling invalid_target
void fn_8001FD7C(void) {
    struct cfg_t* p = (struct cfg_t*) lbl_802FE138;
    fn_8012E81C(p);
    lbl_8055D64C = fn_80232578(p->f1);
    lbl_8055D650 = fn_80232578(p->f2);
    lbl_8055D654 = fn_8023512C(p->f3);
    lbl_8055D658 = fn_8023512C(p->f4);
    lbl_80558D78 = fn_802CAC28(p->f5, 0);
    lbl_80558D7C = fn_802CAC28(p->f6, 0);
    lbl_80558D80 = fn_802CAC28(p->f7, 0);
    lbl_80558D84 = fn_802CAC28(&p->f7[0x10], 0);
}
#pragma scheduling on

void fn_8001FE20(void) {
    lbl_8055D62C = 0;
    fn_802CAC54(lbl_80558D84);
    lbl_80558D84 = -2;
    fn_802CAC54(lbl_80558D80);
    lbl_80558D80 = -2;
    fn_802CAC54(lbl_80558D78);
    lbl_80558D78 = -2;
    fn_802CAC54(lbl_80558D7C);
    lbl_80558D7C = -2;
    fn_802328D4(lbl_8055D64C);
    lbl_8055D64C = 0;
    fn_802328D4(lbl_8055D650);
    lbl_8055D650 = 0;
    fn_80235380(lbl_8055D654);
    lbl_8055D654 = 0;
    fn_80235380(lbl_8055D658);
    lbl_8055D658 = 0;
}

void fn_8001FEB8(void) {
    lbl_8055D645 = 1;
    lbl_8055D640 = fn_802E2C20();
    fn_80176734();
}

void fn_8001FEE8(void) {
    int temp_r3;
    temp_r3 = fn_802E2C20();
    lbl_8055D63C = temp_r3;
    lbl_8055D644 = (lbl_8055D638 = temp_r3, 1);
    lbl_8055D640 = 0;
    lbl_8055D645 = 0;
}

#pragma dont_inline on
void fn_8001FF24(void) {
    lbl_8055D644 = 0;
    lbl_8055D645 = 0;
}
#pragma dont_inline off

extern char lbl_802FE138[];
extern int lbl_80558D78;
extern int lbl_80558D7C;
extern int lbl_80558D80;
extern int lbl_80558D84;
extern int lbl_8055D62C;
extern int lbl_8055D650;
extern int lbl_8055D654;
extern int lbl_8055D658;
extern void fn_8012E81C(void*);
extern int fn_80232578(void*);
extern int fn_8023512C(void*);
extern int fn_802CAC28(void*, int);
extern void fn_802CAC54(int);
extern void fn_802328D4(int);
extern void fn_80235380(int);

void fn_8001FFD0(int arg0, int arg1, void *arg2, int arg3) {
    char *base = lbl_802FE138;
    switch (arg1) {
        case 0x180303:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(arg2, arg3, base + 0x98, arg0 + 1);
            return;
        case 0x180201:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(arg2, arg3, base + 0xAC, arg0 + 1);
            return;
        case 0x180304:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(arg2, arg3, base + 0xC0, arg0 + 1);
            return;
        default:
            ((void (*)(void *, int, char *, ...))fn_801345D8)(arg2, arg3, base + 0xD4, arg0 + 1);
            return;
    }
}

extern void PSVECCrossProduct();
extern void PSVECNormalize(float *, float *);
typedef void (*Cross3)(float *, float *, float *);
typedef void (*Cross4)(float *, float *, float *, float);
typedef void (*Cross5)(float *, float *, float *, float, float);
typedef void (*Cross7)(float *, float *, float *, float, float, float, float);
#pragma push
#pragma scheduling on
void fn_80020070(float *arg0) {
    float b4 = lbl_805604B4;
    float b8 = lbl_805604B8;
    float axis[3];
    float vec2[3];
    float cross[3];
    float vec0[3];
    float x, y, z, a, b, c;

    axis[0] = b4;
    axis[1] = b8;
    axis[2] = b4;
    ((Cross3)PSVECCrossProduct)(axis, arg0 + 6, arg0);
    ((Cross3)PSVECCrossProduct)(arg0 + 6, arg0, arg0 + 3);

    z = arg0[2];
    y = arg0[1];
    x = arg0[0];
    vec0[0] = x;
    vec0[1] = y;
    vec0[2] = z;
    c = arg0[8];
    b = arg0[7];
    a = arg0[6];
    vec2[0] = a;
    vec2[1] = b;
    vec2[2] = c;
    ((Cross3)PSVECCrossProduct)(vec2, vec0, cross);
    PSVECNormalize(vec0, vec0);
    PSVECNormalize(cross, cross);
    ((Cross3)PSVECCrossProduct)(vec0, cross, vec2);

    arg0[0] = vec0[0];
    arg0[1] = vec0[1];
    arg0[2] = vec0[2];
    arg0[3] = cross[0];
    arg0[4] = cross[1];
    arg0[5] = cross[2];
    arg0[6] = vec2[0];
    arg0[7] = vec2[1];
    arg0[8] = vec2[2];
}
void fn_8002017C(void) {
    fn_8000B3DC(0);
}

int fn_80020184(void) {
    s32 temp_r3;
    u32 temp_r3_2;

    temp_r3_2 = (((fn_802E2C20() - lbl_8055D63C) - 0x12C) << 8) / 1000;
    temp_r3 = temp_r3_2 & ((s32) (-(s32) temp_r3_2 & ~temp_r3_2) >> 0x1F);
    temp_r3 = (temp_r3 < 0xFF) ? temp_r3 : 0xFF;
    return 0xFF - temp_r3;
}

void fn_80020430(void) {
    fn_8001FF24();
}

int fn_80020434(void* arg0, float* arg1) {
    float out1[2], out2[2];
    float mat[12];
    double dbl;
    float var_f1;
    float var_f3;
    float var_f31;
    float temp_f0;
    float temp_f1;
    float temp_f2;
    float temp_f3;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f7;
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r6;
    s32 temp_r0;
    void* temp_r28;

    mat[0] = lbl_805604B8;
    mat[1] = lbl_805604B4;
    mat[2] = lbl_805604B4;
    mat[3] = lbl_805604B4;
    mat[4] = lbl_805604B8;
    mat[5] = lbl_805604B4;
    mat[6] = lbl_805604B4;
    mat[7] = lbl_805604B4;
    mat[8] = lbl_805604B8;
    mat[9] = lbl_805604B4;
    mat[10] = lbl_805604B4;
    mat[11] = lbl_805604B4;
    fn_802A1120(out1, out2, lbl_805604B8);
    mat[9] = out1[0];
    mat[10] = lbl_805604B4;
    mat[11] = out1[1];
    mat[6] = out2[0];
    mat[7] = lbl_805604B4;
    mat[8] = out2[1];
    ((Cross7)PSVECCrossProduct)(&mat[3], &mat[6], &mat[0], out2[0], out1[1], lbl_805604B4, out1[0]);
    temp_r3 = fn_802E2C20();
    temp_r6 = temp_r3 - lbl_8055D63C;
    temp_r0 = temp_r6 / 50000;
    temp_r0 = temp_r6 - temp_r0 * 50000;
    ((s32*)&dbl)[0] = 0x43300000;
    ((s32*)&dbl)[1] = temp_r0 ^ 0x8000;
    temp_f2 = (dbl - lbl_805604E8) / lbl_805604BC * lbl_805604C0;
    temp_f7 = lbl_805604C4 + (lbl_805604C8 * (lbl_805604B8 - cos(temp_f2)));
    temp_f5 = mat[9];
    temp_f3 = mat[10];
    temp_f6 = mat[6] * temp_f7;
    temp_f4 = mat[7] * temp_f7;
    temp_f1 = temp_f5 + temp_f6;
    temp_f2 = mat[11] + (mat[8] * temp_f7);
    mat[9] = temp_f1;
    mat[10] = temp_f3 + temp_f4;
    mat[11] = temp_f2;
    mat[10] = lbl_805604CC + fn_801EA0E8(temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7);
    var_f1 = lbl_805604D0;
    if (lbl_8055D630 > 0) {
        temp_r28 = &lbl_8035B758[lbl_8055D634 * 0x70];
        ((s32*)&dbl)[0] = 0x43300000;
        temp_r3 = fn_802E2C20();
        ((s32*)&dbl)[1] = (temp_r3 - lbl_8055D638) ^ 0x8000;
        var_f31 = lbl_805604D4 * (dbl - lbl_805604E8);
        temp_f3 = *(float*)&((char*)temp_r28)[0x68];
        if (var_f31 > temp_f3) {
            temp_r4 = lbl_8055D634 + 1;
            lbl_8055D634 = (lbl_8055D634 + 1) % lbl_8055D630;
            lbl_8055D638 = fn_802E2C20();
        }
        var_f3 = lbl_805604B8;
        temp_f0 = (var_f31 - lbl_805604B4) / (temp_f3 - lbl_805604B4);
        if (var_f3 >= temp_f0) {
            var_f3 = temp_f0;
        }
        if (var_f3 <= lbl_805604B4) {
            var_f3 = lbl_805604B4;
        }
        var_f31 = lbl_805604B4 + var_f3 * lbl_805604B8;
        if (*(unsigned char*)&((char*)temp_r28)[0x6C] != 0) {
            var_f1 = lbl_805604D8;
            if (var_f31 < var_f1) {
            } else if (var_f31 > lbl_805604B8) {
                var_f1 = lbl_805604B8;
            } else if (var_f31 > lbl_805604B4) {
                var_f1 = var_f31 * (lbl_805604DC * var_f31 * var_f31) + lbl_805604E0 * var_f31 * var_f31;
            } else {
                var_f1 = var_f31 * (lbl_805604DC * var_f31 * var_f31) - lbl_805604E0 * var_f31 * var_f31;
            }
            var_f31 = var_f1;
        }
        fn_8026E22C(mat, temp_r28, (char*)temp_r28 + 0x30, var_f31);
        fn_80020070(mat);
        temp_f1 = *(float*)&((char*)temp_r28)[0x60];
        var_f1 = temp_f1 + var_f31 * (*(float*)&((char*)temp_r28)[0x64] - temp_f1);
    }
    ((s32*)arg0)[0] = ((s32*)mat)[0];
    ((s32*)arg0)[1] = ((s32*)mat)[1];
    ((s32*)arg0)[2] = ((s32*)mat)[2];
    ((s32*)arg0)[3] = ((s32*)mat)[3];
    ((s32*)arg0)[4] = ((s32*)mat)[4];
    ((s32*)arg0)[5] = ((s32*)mat)[5];
    ((s32*)arg0)[6] = ((s32*)mat)[6];
    ((s32*)arg0)[7] = ((s32*)mat)[7];
    ((s32*)arg0)[8] = ((s32*)mat)[8];
    ((s32*)arg0)[9] = ((s32*)mat)[9];
    ((s32*)arg0)[10] = ((s32*)mat)[10];
    ((s32*)arg0)[11] = ((s32*)mat)[11];
    *arg1 = var_f1;
    return 0;
}

extern int fn_80020434(void*, float*);
extern int fn_8026A2CC(void*, int, float);
extern int fn_8000C630(int, int);
void fn_800207B0(void) {
    char sp10[0x30];
    float sp8;

    if ((lbl_8055D644 != 0) && (lbl_8055D645 == 0)) {
        fn_802E2C20();
    }
    if ((lbl_8055D644 != 0) && (lbl_8055D645 != 0) && ((fn_801E8838() > 0xF0) || ((fn_802E2C20() - lbl_8055D640) > 0x4B0))) {
        lbl_8055D645 = 0;
        lbl_8055D644 = 0;
    }
    if (lbl_8055D644 != 0) {
        fn_80020434(&sp10, &sp8);
        fn_8026A2CC(&sp10, 0, sp8);
        fn_8000C630(0x15, -1);
    }
}

extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern double lbl_805604E8;
extern float lbl_805604F0;
extern float lbl_805604F4;
extern float lbl_805604F8;
extern float lbl_805604FC;
extern int fn_802354A0(int, int, s32, f32, f32, f32, f32, f32);
#pragma push
#pragma dont_inline on
void fn_80020860(int arg0) {
    f32 t4;
    f32 t5;

    t4 = lbl_805604F0 * (f32)lbl_8055CFF0 / lbl_805604F4;
    t5 = (f32)lbl_8055CFF4;
    fn_802354A0(lbl_8055D654, 0, (arg0 << 24) | 0xFF0000 | 0xFFFF,
                lbl_805604F8 * t4,
                lbl_805604FC * t5,
                lbl_805604B4,
                t4,
                t5);
}

#pragma push
#pragma scheduling invalid_target
void fn_800208F0(int arg0, unsigned char *arg1, int arg2) {
    char temp_r3_2;
    int var_r31;
    unsigned char *var_r30;
    char *var_r4;
    int temp_r3;

    var_r31 = arg2;
    var_r30 = arg1;
    temp_r3 = fn_8001BA90(fn_8000DA10(), arg0, lbl_8055D668, lbl_8055D66C, -1);
    if ((unsigned int)((s32)temp_r3 + 0x10000) != 0xFFFF) {
        fn_8001BA70(arg0, temp_r3, var_r30, var_r31);
        return;
    }
    var_r4 = lbl_80558D8C;
    goto loop_body;
count_check:
    var_r31 -= 1;
    if (var_r31 > 0) {
        goto loop_body;
    }
    var_r30[-1] = 0;
    return;
loop_body:
    temp_r3_2 = *var_r4;
    var_r4 += 1;
    *var_r30 = temp_r3_2;
    var_r30 += 1;
    if (temp_r3_2 != 0) {
        goto count_check;
    }
}
#pragma pop

extern int fn_80020184(void);
extern int fn_801E8838(void);
extern int fn_8020DE1C(void);
extern char lbl_8035BAFC[], lbl_8035BB08[], lbl_802FE374[], lbl_802FE398[];
extern unsigned char lbl_8055D672, lbl_8055D673;
extern float lbl_80560554, lbl_80560500, lbl_80560558, lbl_8056055C;
#pragma dont_inline on
int fn_80021258(void) {
 int count;
 float rate;
 if (!lbl_8055D644) return 0;
 count=fn_80020184();
 if(count>0) fn_80020860(count);
 if(count>0) rate=lbl_805604B4;
 else rate=((float)fn_801E8838()-lbl_805604E8)/lbl_80560554;
 fn_800209A0(255,rate);
 if(fn_8020DE1C()==0) {
 if((signed char)lbl_8055D672==0) { fn_801312EC(&lbl_8035BAFC,&lbl_802FE374); lbl_8055D672=1; }
 if((signed char)lbl_8055D673==0) { fn_801312EC(&lbl_8035BB08,&lbl_802FE398); lbl_8055D673=1; }
 if(*(unsigned int *)((char *)&lbl_8035BB08+8)!=(unsigned int)lbl_8055E044) fn_80131318();
 fn_80232BA4(*(int *)((char *)&lbl_8035BB08+4),lbl_8055D64C,-1,20,lbl_80560500,lbl_80560558,lbl_805604B0,lbl_805604B4,lbl_805604B8);
 if(*(unsigned int *)((char *)&lbl_8035BAFC+8)!=(unsigned int)lbl_8055E044) fn_80131318();
 fn_80232BA4(*(int *)((char *)&lbl_8035BAFC+4),lbl_8055D64C,-1,20,lbl_8056055C,lbl_80560558,lbl_805604B0,lbl_805604B4,lbl_805604B8);
 }
 return 1;
}
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_800213DC(int arg0) {
    int r;
    if (lbl_8055D644) {
        if (!lbl_8055D645 && !fn_801E8838() && !fn_802E4A10()) {
            switch (arg0) {
                case 0x58:
                    fn_8001FEB8();
                    break;
                case 0x1B:
                    fn_8002017C();
                    break;
            }
        }
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
#pragma pop
void fn_8002167C(void) {
    fn_8001FF24();
}

void fn_80021680(void) {
    fn_80020860(0xFF);
    fn_800209A0(0xFF, lbl_805604B4);
    fn_8001FF34(-1);
}

void __AXDSPInitCallback_800216B8(void) { lbl_8055D62C = 2; }

void fn_800216C4(void) {

}

#pragma push
#pragma inline_depth 0
void fn_800216C8(void) {
    fn_8001FF34(-1);
}
extern int lbl_8055D668, lbl_8055D66C;
extern char *lbl_80558D8C;
extern int fn_8000DA10(void);
extern int fn_8001BA90(int, int, int, int, int);
extern void fn_8001BA70(int, int, unsigned char *, int);
#pragma dont_inline on
int fn_800216D0(void) {
    int result = 0;
    if (lbl_8055D644) {
        if (!lbl_8055D645) result = 1;
    }
    return result;
}
unsigned char fn_800216F4(void) {
    return lbl_8055D644;
}

int fn_800216FC(void) {
    if (lbl_8055D644 != 0)
        return fn_80020184() > 0;
    return 0;
}

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
int fn_8002173C(void) {
    extern void fn_80230B38_0(void);
    char sp8[0x38];
    if (lbl_8055D62C != 0) {
        fn_80230B5C(sp8);
        fn_80230AD8(sp8);
        switch (lbl_8055D62C) {
        case 2: fn_800216C8(); break;
        case 1: fn_80021680(); break;
        }
        {
            void (*f)(void) = (void (*)(void))fn_80230B38;
            f();
        }
        return 1;
    }
    return 0;
}
#pragma pop
int fn_800217AC(void) {
    int result;
    if (lbl_8055D648 != 0)
        return 0;
    result = 0;
    if (lbl_8055D644 == 0 || lbl_8055D645 != 0)
        result = 1;
    return result;
}

extern float lbl_80560560, lbl_80560564, lbl_805604B8, lbl_805604B4, lbl_80560568, lbl_80560554, lbl_805604FC;
extern int fn_802E2C20(void);
extern void fn_80020860(int);
void fn_800217E4(void) {
    float temp_f1;
    float var_f0;
    float var_f4;
    int temp_r0;
    int temp_r31;

    if (lbl_8055D648 != 0) {
        temp_r0 = fn_802E2C20() - lbl_8055D63C;
        if (temp_r0 < 0x5DC) {
            var_f4 = lbl_805604B8;
            var_f4 = var_f4 < ((float)temp_r0 - lbl_80560560) / lbl_80560564
                ? var_f4
                : ((float)temp_r0 - lbl_80560560) / lbl_80560564;
            var_f4 = var_f4 > lbl_805604B4 ? var_f4 : lbl_805604B4;
            temp_f1 = lbl_80560554 + (var_f4 * lbl_80560568);
            if (temp_f1 < lbl_805604B4) {
                var_f0 = temp_f1 - lbl_805604FC;
            } else {
                var_f0 = lbl_805604FC + temp_f1;
            }
            temp_r31 = (int)var_f0;
            if (temp_r31 > 0) {
                fn_80020860(temp_r31);
                fn_800209A0(temp_r31, lbl_805604B4);
            }
        } else {
            lbl_8055D648 = 0;
        }
    }
}

void fn_800218F4(void) {
    fn_8001FD7C();
}

void fn_800218F8(void) {
    fn_8001FE20();
}
void fn_8001FF34(int arg0) {
    if ((char)lbl_8055D670 == 0) {
        fn_801312EC(&lbl_8035BAE4, &lbl_802FE1C0);
        lbl_8055D670 = 1;
    }
    if (lbl_8035BAE4.unk_8 != lbl_8055E044) {
        fn_80131318(&lbl_8035BAE4);
    }
    fn_80232BA4(lbl_8035BAE4.unk_4, lbl_8055D64C, arg0, 0x12, lbl_805604A8, lbl_805604AC, lbl_805604B0, lbl_805604B4, lbl_805604B8);
}
