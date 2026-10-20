// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))

extern void fn_8017E930(void *);
extern int fn_801A8EE4(void *);
extern int fn_80128668(void);
extern double fabs(double);
extern float lbl_80561C48;
extern float lbl_80561C58;
extern float lbl_80561C4C;
extern float lbl_80561C98;
extern float lbl_80561C9C;
extern void fn_802E8518(void);
typedef struct Unk8017Object Unk8017Object;
typedef struct Unk8017VTable {
    void (*unk_0x0[32])(void);
    void (*unk_0x80)(Unk8017Object *, int);
} Unk8017VTable;
struct Unk8017Object {
    Unk8017VTable *vtable;
};
extern Unk8017Object *lbl_804348D8[4];
extern signed char lbl_8055E4B8;
extern signed char lbl_8055E4B9;
extern signed char lbl_8055E4BA;
extern void fn_801808DC();
extern void fn_802E8524(int, int);

void fn_8017EB68(void *arg0) {
    fn_8017E930((char *)arg0 - 0x1EC);
}

extern void fn_8017E96C(void *);
void fn_8017EB70(void *arg0) {
    fn_8017E96C((char *)arg0 - 0x1EC);
}

extern void fn_8017E9FC(void *);
void fn_8017EB78(void *arg0) {
    fn_8017E9FC((char *)arg0 - 0x1EC);
}

float fn_8017EB80(float arg0, float arg1, float arg2) {
    float magnitude = (float)__fabs(arg0);
    float value = lbl_80561C48;
    float temp = value + arg1;
    temp = temp + arg2;
    temp = temp * magnitude;
    temp = temp - arg1;
    value = value < temp ? value : temp;
    value = value > lbl_80561C4C ? value : lbl_80561C4C;
    if (arg0 >= lbl_80561C4C) return value;
    return -value;
}

int fn_8017EBE0(void) {
    int zero = 0;
    int one = 1;
    lbl_8055E4B8 = zero;
    lbl_8055E4BA = one;
    lbl_8055E4B9 = zero;
    lbl_804348D8[0] = 0;
    lbl_804348D8[1] = 0;
    lbl_804348D8[2] = 0;
    lbl_804348D8[3] = 0;
    fn_801808DC();
    return one;
}

void fn_8017EC30(void) {
    Unk8017Object **ptr = lbl_804348D8;
    int i = 0;
    do {
        Unk8017Object *obj;
        fn_802E8524(0, i);
        obj = *ptr;
        if (obj != 0) {
            if (obj != 0) {
                obj->vtable->unk_0x80(obj, 1);
            }
            *ptr = 0;
        }
        i++;
    } while (i < 4 && (++ptr, 1));
    lbl_8055E4BA = 0;
}

int fn_8017ECC0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern int fn_801769F8(void);
extern int fn_801B526C(void);
extern int fn_801C5B60(void);
extern void fn_802E8528(int, float, float);
extern void fn_802E85A8(int, float, float, float);
extern void fn_802E85AC(int, float, float, float);
extern float lbl_8055A334;
extern float lbl_80561C60;
#pragma push
#pragma use_lmw_stmw off
void fn_8017F628(void *arg0) {
    float scale = lbl_8055A334;
    if (fn_801769F8() == 0 && fn_801B526C() == 0 && fn_801C5B60() == 0 &&
        *(unsigned char *)((char *)arg0 + 0x5C) && *(unsigned char *)((char *)arg0 + 0x350)) {
        float a = *(float *)((char *)arg0 + 0x30C) * scale;
        fn_802E85AC(*(int *)((char *)arg0 + 8), *(float *)((char *)arg0 + 0x314) + a,
                    *(float *)((char *)arg0 + 0x310) * scale, a);
        {
            float b = *(float *)((char *)arg0 + 0x318) * scale;
            float c = *(float *)((char *)arg0 + 0x320) * scale;
            float d = *(float *)((char *)arg0 + 0x31C);
            fn_802E85A8(*(int *)((char *)arg0 + 8), b, d, c);
        }
        {
            float x = *(float *)((char *)arg0 + 0x324) * scale;
            float y = *(float *)((char *)arg0 + 0x328);
            float z = __fabs(y);
            float w = __fabs(x);
            fn_802E8528(*(int *)((char *)arg0 + 8), lbl_80561C60 * w, z);
        }
    } else ((void (*)(int))fn_802E8518)(*(int *)((char *)arg0 + 8));
}
#pragma pop
float fn_8017F70C(float arg0) { double temp = __fabs(arg0); return temp; }

extern int fn_80128668(void);
extern int fn_801A8EE4(void *);
int fn_8017FEE4(void *arg0) {
    int result = 0;
    if (*(unsigned char *)((char *)arg0 + 0x340) != 0 ||
        fn_801A8EE4((char *)arg0 + 0x6C) != 0 ||
        fn_801A8EE4((char *)arg0 + 0x7C) != 0) {
        result = 1;
    }
    return result;
}

int fn_801813D8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80181418(void *arg0, int arg1) {
 *(int *)((char *)arg0+4)=arg1;
 *(unsigned char *)((char *)arg0+0xC)=0;
}

extern void lbl_80331EFC(void);
void fn_80181428(void **arg0) {
    *arg0 = (void *)&lbl_80331EFC;
}

void fn_80181438(void) {

}

void fn_8018143C(void) {

}

void fn_80181440(void) {

}

int fn_80181444(void *arg0) { return *(int *)((char *)arg0 + 0x34C); }

int fn_8018144C(void *arg0) { return *(int *)((char *)arg0 + 0x348); }

void GXInitLightAttnA_80181454(void *arg0, float farg0, float farg1, float farg2) {
    *(float *)((char *)arg0 + 0x30C) = farg0;
    *(float *)((char *)arg0 + 0x310) = farg1;
    *(float *)((char *)arg0 + 0x314) = farg2;
}

void GXInitLightAttnK_80181464(void *arg0, float farg0, float farg1, float farg2) {
    *(float *)((char *)arg0 + 0x318) = farg0;
    *(float *)((char *)arg0 + 0x31C) = farg1;
    *(float *)((char *)arg0 + 0x320) = farg2;
}

void fn_80181474(void *arg0, float arg1, float arg2) {
 *(float *)((char *)arg0+0x324)=arg1;
 *(float *)((char *)arg0+0x328)=arg2;
}

void fn_80181480(void *arg0, int arg1) {
 int old=*(int *)((char *)arg0+0x50);
 *(int *)((char *)arg0+0x54)=arg1;
 if(old>arg1) *(int *)((char *)arg0+0x50)=arg1;
}

float fn_80181498(void *arg0) {
 float f31=*(float *)((char *)arg0+0xC);
 float f2;
 float f0;
 if (f31 <= lbl_80561C48) f31=lbl_80561C48;
 f2=*(float *)((char *)arg0+0xC);
 if (f2 >= lbl_80561C58) {} else f2=lbl_80561C58;
 f0=*(float *)((char *)arg0+0xC)+*(float *)((char *)arg0+0x10);
 if (f31 < f0) f31=f0;
 if (f31 > f2) f31=f2;
 if (((int (*)(void *))(*(char **)arg0+0x5C))(arg0)) f31=*(float *)((char *)arg0+0xC);
 return f31;
}

float fn_80181548(void *arg0) {
    float value = *(float *)((char *)arg0 + 0x20) + *(float *)((char *)arg0 + 0x24);
    if (value < lbl_80561C48) return value;
    return lbl_80561C48;
}

float fn_80181568(void *arg0) {
    float value = *(float *)((char *)arg0 + 0x14) + *(float *)((char *)arg0 + 0x18);
    if (value < lbl_80561C48) return value;
    return lbl_80561C48;
}

extern void fn_802E8518(void);
extern float lbl_80561C98;
extern float lbl_80561C9C;
float fn_80181588(void *arg0) {
    float value = lbl_80561C98 - lbl_80561C9C * *(float *)((char *)arg0 + 0x1C);
    float result = lbl_80561C4C;
    result = result > value ? result : value;
    if (lbl_80561C48 < result) return lbl_80561C48;
    return result;
}

float fn_801815C4(void *arg0) {
    return *(float *)((char *)arg0 + 0x28);
}

int fn_801815CC(void *arg0) {
    return *(int *)((char *)arg0 + 0x50);
}

void fn_801815D4(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x50) = arg1;
}

void fn_801815DC(void *arg0, float arg1) {
    float value = lbl_80561C48 < arg1 ? lbl_80561C48 : arg1;
    value = value > lbl_80561C4C ? value : lbl_80561C4C;
    *(float *)((char *)arg0 + 0x20) = value;
}

extern int fn_801A8E68(void *);
extern void fn_801797F8(int, int, int);
void fn_8018160C(void *arg0) {
    char *p;
    int i;
    if (fn_801A8E68((char *)arg0 + 0x25c)) fn_801797F8(*(int *)((char *)arg0 + 4), 2, 0);
    if (fn_801A8E68((char *)arg0 + 0x26c)) fn_801797F8(*(int *)((char *)arg0 + 4), 1, 0);
    if (fn_801A8E68((char *)arg0 + 0x27c)) fn_801797F8(*(int *)((char *)arg0 + 4), 3, 0);
    if (fn_801A8E68((char *)arg0 + 0x24c)) fn_801797F8(*(int *)((char *)arg0 + 4), 0, 0);
    p = (char *)arg0 + 0x2cc;
    i = 0;
    do {
        if (fn_801A8E68(p)) {
            fn_801797F8(*(int *)((char *)arg0 + 4), 4, i);
            break;
        }
        ++i;
        if (i >= 4) break;
        p += 0x10;
    } while (1);
}

void fn_80181700(void *arg0, int arg1) {
    *(unsigned char *)((char *)arg0 + 0x350) = arg1;
    if (arg1 != 0) return;
    arg0 = *(void **)((char *)arg0 + 8);
    if ((int)arg0 < 0) return;
    fn_802E8518();
}

void fn_80181720(void *arg0) {
    if (*(int *)((char *)arg0 + 8) >= 0 && fn_8026A368(*(int *)((char *)arg0 + 4)) != 0x11) {
        fn_802E85F4(*(int *)((char *)arg0 + 8));
    }
}

int fn_8018176C(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x58);
}

int fn_80181774(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x5D);
}

int fn_8018177C(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x68);
}

int fn_80181784(void *arg0) {
    return *(unsigned char *)((char *)arg0 + 0x5A);
}

unsigned char fn_8018178C(void *arg0) { return *((unsigned char *)arg0 + 0x5B); }

float fn_80181794(void *arg0) { return *(float *)((char *)arg0 + 0x32C); }

float fn_8018179C(void *arg0) { return *(float *)((char *)arg0 + 0x330); }

float fn_801817A4(void *arg0) { return *(float *)((char *)arg0 + 0x334); }

unsigned char fn_801817AC(void *arg0) {
    return *((unsigned char *)arg0 + 0x338);
}

int fn_801817B4(void *arg0) {
    int result = 0;
    if (*(unsigned char *)((char *)arg0 + 0x340) != 0 || fn_801A8EE4((char *)arg0 + 0x9C) != 0) {
        result = 1;
    }
    return result;
}

int fn_80181800(void *arg0) {
    int result = 0;
    if (*(unsigned char *)((char *)arg0 + 0x340) != 0 || fn_801A8EE4((char *)arg0 + 0x8C) != 0) {
        result = 1;
    }
    return result;
}

unsigned char fn_8018184C(void *arg0) { return *((unsigned char *)arg0 + 0x344); }
extern int fn_801769F8(void);
extern int fn_801B526C(void);
extern int fn_801C5B60(void);
extern void fn_802E8528(int, float, float);
extern void fn_802E85A8(int, float, float, float);
extern void fn_802E85AC(int, float, float, float);
extern float lbl_8055A334;
extern float lbl_80561C60;
