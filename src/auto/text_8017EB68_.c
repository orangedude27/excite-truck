// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#define FC48 (*(const float *)&lbl_80561C48)
#define FC4C (*(const float *)&lbl_80561C4C)
#define FC7C (*(const float *)&lbl_80561C7C)
#define FC80 (*(const float *)&lbl_80561C80)
#define FC84 (*(const float *)&lbl_80561C84)
#define FC88 (*(const float *)&lbl_80561C88)
#define FC8C (*(const float *)&lbl_80561C8C)
#define FC90 (*(const float *)&lbl_80561C90)
#define FC94 (*(const float *)&lbl_80561C94)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))

extern float lbl_80561C48;
extern float lbl_80561C4C;
extern float lbl_80561C7C;
extern float lbl_80561C80;
extern float lbl_80561C84;
extern float lbl_80561C88;
extern float lbl_80561C8C;
extern float lbl_80561C90;
extern float lbl_80561C94;
extern float lbl_8055A330;
extern float lbl_8055A334;
extern float lbl_8055A338;
extern float lbl_8055A33C;
extern float lbl_8055A340;
extern float lbl_8055A344;
extern int lbl_802F9530[];
extern int lbl_802F9540[];
extern char lbl_80331F80[];
extern char lbl_80331F90[];
extern char lbl_80331F9C[];
extern char lbl_80331FA8[];
extern char lbl_80331FB4[];
extern char lbl_80331FC0[];
extern char lbl_80331FCC[];
extern char lbl_80331FD8[];
extern char lbl_80331FE4[];
extern char lbl_80331FF0[];
extern char lbl_80331FFC[];
extern char lbl_80332008[];
extern char lbl_80332020[];
extern char lbl_80332030[];
extern char lbl_8033203C[];
extern char lbl_80332050[];
extern char lbl_80332064[];
extern char lbl_80332078[];
extern char lbl_8033208C[];
extern char lbl_8033209C[];
extern char lbl_803320B0[];
extern char lbl_803320BC[];
extern char lbl_803320C8[];
extern char lbl_803320D4[];
extern char lbl_803320E0[];
extern char lbl_803320EC[];
extern char lbl_803320F8[];
extern char lbl_80332104[];
extern char lbl_80332110[];
extern char lbl_8033211C[];
extern char lbl_8033212C[];
extern char lbl_80332138[];
extern char lbl_80332144[];
extern char lbl_80332150[];
extern char lbl_8033215C[];
extern char lbl_80332168[];
extern char lbl_80332178[];
extern char lbl_80332184[];
extern char lbl_80332194[];
extern char lbl_803321A0[];
extern char lbl_803321AC[];
extern char lbl_803321B8[];
extern char lbl_803321C4[];
extern char lbl_803321D0[];
extern char lbl_803321E4[];
extern char lbl_803321F0[];
extern char lbl_80332200[];
extern char lbl_80332210[];
extern char lbl_80332220[];
extern char lbl_80332238[];
extern char lbl_80332248[];
extern char lbl_80332258[];
extern char lbl_80332270[];
__declspec(section ".sdata") extern const char lbl_8055A350[];
__declspec(section ".sdata") extern const char lbl_8055A358[];
__declspec(section ".sdata") extern const char lbl_8055A360[];
__declspec(section ".sdata") extern const char lbl_8055A368[];
__declspec(section ".sdata") extern const char lbl_8055A370[];
__declspec(section ".sdata") extern const char lbl_8055A378[];
__declspec(section ".sdata") extern const char lbl_8055A380[];
__declspec(section ".sdata") extern const char lbl_8055A388[];
__declspec(section ".sdata") extern const char lbl_8055A390[];
__declspec(section ".sdata") extern const char lbl_8055A398[];
extern void fn_801331C4(int, const char *, void *);
extern void fn_801333E8(int, const char *, void *);
extern void fn_801A7974(void *, const char *, int);
extern void fn_801A7DFC(int, int, int);
extern void fn_801A9110(void *, const char *);
extern int sprintf(char *, const char *, ...);
struct Di718Slot {
    void *handler;
    s32 value;
    u8 pad08[4];
    u8 inUse;
    u8 pad0D[3];
};
struct Di718 {
    void *vtable;
    s32 index;
    s32 axStackHead;
    f32 pad0C[8];
    f32 level2C[9];
    s32 pad50[2];
    u8 flag58;
    u8 flag59;
    u8 flag5A;
    u8 flag5B;
    u8 flag5C;
    u8 flag5D;
    u8 flag5E;
    u8 pad5F;
    f32 pad60;
    f32 pad64;
    u8 flag68;
    u8 pad69[3];
    struct Di718Slot slot[42];
    f32 pad30C[9];
    u8 pad330[8];
    u8 flag338;
    u8 pad339[3];
    f32 pad33C;
    u8 flag340;
    u8 flag341;
    u8 flag342;
    u8 flag343;
    u8 flag344;
    u8 pad345[3];
    s32 mode348;
    s32 soundId;
    u8 flag350;
    u8 pad351[3];
};
extern void fn_8017E930(void *);
extern s32 __AXGetStackHead_80137CFC(s32);
extern s32 fn_801298E8(void *, s32);
extern f32 fn_801429D0(f32, f32);
extern f32 fn_801429E0(f32, f32);
extern f32 fn_80144C80(f32, f32, f32);
extern f32 fn_8014C8F8(f32, f32, f32);
extern s32 fn_80179300(void);
extern void fn_8017F628(void *);
float fn_8017F70C(float);
extern void fn_8017F718(void *);
extern void fn_801A7844(s32);
extern f32 fn_801A7F98(void *);
extern int fn_801A8E38(void *);
extern int fn_801A8E68(void *);
extern s32 fn_801A8F10(void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_802E317C(const char *, ...);
extern s32 fn_802E85B0(s32);
extern const char lbl_80331E28[];
extern const char lbl_80332280[];
extern f32 lbl_80561C50;
extern f32 lbl_80561C54;
extern f32 lbl_80561C5C;
extern f32 lbl_80561C60;
extern f32 lbl_80561C64;
extern f32 lbl_80561C68;
extern f32 lbl_80561C6C;
extern f32 lbl_80561C70;
extern f32 lbl_80561C74;
extern f32 lbl_80561C78;
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

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
int fn_8017EBE0(void) {
    int zero = 0;
    int one = 1;
    lbl_8055E4B8 = zero;
    lbl_8055E4BA = one;
    lbl_8055E4B9 = zero;
    lbl_804348D8[0] = (Unk8017Object *)zero;
    lbl_804348D8[1] = (Unk8017Object *)zero;
    lbl_804348D8[2] = (Unk8017Object *)zero;
    lbl_804348D8[3] = (Unk8017Object *)zero;
    fn_801808DC();
    return 1;
}
#pragma pop
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
#pragma processor 750
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

#pragma scheduling invalid_target
void fn_8017F718(void *arg0) {
    char name[64];
    unsigned char flag;
    int keys1[4];
    int keys2[4];
    int *slot;
    int i;
    int j;
    struct Di718 *v;
    float value;
    float f90;
    float f8C;
    float f88;
    float f84;
    float f48;
    float f80;
    float f7C;
    float value2;
    v = (struct Di718 *)arg0;
    {
        s32 axHead = __AXGetStackHead_80137CFC(v->index);
        f7C = lbl_80561C7C;
        f8C = lbl_80561C8C;
        f80 = lbl_80561C80;
        f48 = lbl_80561C48;
        f84 = lbl_80561C84;
        f88 = lbl_80561C88;
        f90 = lbl_80561C90;
        v->axStackHead = axHead;
    }
    v->level2C[0] = f7C;
    v->level2C[3] = f7C;
    v->level2C[6] = f80;
    v->level2C[2] = f48;
    v->level2C[5] = f84;
    v->level2C[8] = f88;
    v->level2C[1] = f8C;
    v->level2C[4] = f90;
    v->level2C[7] = f8C;
    v->flag340 = 0;
    v->flag341 = 0;
    fn_801331C4(v->soundId, lbl_80332270, (char *)v + 0x2C);
    fn_801331C4(v->soundId, lbl_80332258, (char *)v + 0x38);
    fn_801331C4(v->soundId, lbl_80332248, (char *)v + 0x44);
    fn_801331C4(v->soundId, lbl_80332238, (char *)v + 0x30);
    fn_801331C4(v->soundId, lbl_80332220, (char *)v + 0x3C);
    fn_801331C4(v->soundId, lbl_80332210, (char *)v + 0x48);
    fn_801331C4(v->soundId, lbl_80332200, (char *)v + 0x34);
    fn_801331C4(v->soundId, lbl_803321F0, (char *)v + 0x40);
    fn_801331C4(v->soundId, lbl_803321E4, (char *)v + 0x4C);
    fn_801331C4(v->soundId, lbl_803321D0, (char *)v + 0x60);
    v->flag5C = 1;
    fn_801333E8(v->soundId, lbl_803321C4, (char *)v + 0x340);
    fn_801333E8(v->soundId, lbl_803321B8, &v->flag341);
    v->flag5E = 1;
    value = lbl_80561C48;
    value = value < (v->pad60 - lbl_80561C48) ? value : (v->pad60 - lbl_80561C48);
    value = value > lbl_80561C4C ? value : lbl_80561C4C;
    value2 = lbl_80561C48;
    v->pad64 = value;
    value2 = value2 < v->pad60 ? value2 : v->pad60;
    value2 = value2 > lbl_80561C4C ? value2 : lbl_80561C4C;
    value = v->level2C[2];
    v->pad60 = value2;
    value = value > lbl_80561C94 ? value : lbl_80561C94;
    value2 = v->level2C[5];
    v->level2C[2] = value;
    value2 = value2 > lbl_80561C94 ? value2 : lbl_80561C94;
    value = v->level2C[8];
    v->level2C[5] = value2;
    value = value > lbl_80561C94 ? value : lbl_80561C94;
    v->level2C[8] = value;
#pragma push
#pragma cplusplus on
#pragma paired_single off
    {
        class Callback {
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
            virtual void f14();
            virtual void f15();
            virtual void f16();
            virtual void f17();
            virtual void f18();
            virtual void f19();
            virtual void f20();
            virtual int f21();
        };
        if (((Callback *)v)->f21() != 0) {
            v->pad60 = lbl_80561C4C;
        }
    }
#pragma pop
    fn_802E8524(v->flag5C, v->axStackHead);
    keys1[0] = *lbl_802F9530;
    keys1[1] = *(lbl_802F9530 + 1);
    keys1[2] = *(lbl_802F9530 + 2);
    keys1[3] = *(lbl_802F9530 + 3);
    keys2[0] = *lbl_802F9540;
    keys2[1] = *(lbl_802F9540 + 1);
    keys2[2] = *(lbl_802F9540 + 2);
    keys2[3] = *(lbl_802F9540 + 3);
    slot = (int *)((char *)v + 0x2CC);
    for (i = 0; i < 4; i++, slot += 4) {
        fn_801A7DFC(keys1[i], keys2[i], v->soundId);
        fn_801A7974((char *)slot, (const char *)keys1[i], v->soundId);
    }
    fn_801A7974((char *)v + 0x6C, lbl_803321AC, v->soundId);
    fn_801A7974((char *)v + 0x7C, lbl_803321A0, v->soundId);
    fn_801A7974((char *)v + 0x18C, lbl_80332194, v->soundId);
    fn_801A7974((char *)v + 0x19C, lbl_80332184, v->soundId);
    fn_801A7974((char *)v + 0x8C, lbl_80332178, v->soundId);
    fn_801A7974((char *)v + 0x9C, lbl_8055A398, v->soundId);
    fn_801A7974((char *)v + 0xBC, lbl_80332168, v->soundId);
    fn_801A7974((char *)v + 0xCC, lbl_8033215C, v->soundId);
    fn_801A7974((char *)v + 0xDC, lbl_80332150, v->soundId);
    fn_801A7974((char *)v + 0xEC, lbl_80332144, v->soundId);
    fn_801A7974((char *)v + 0x24C, lbl_8055A390, v->soundId);
    fn_801A7974((char *)v + 0x25C, lbl_80332138, v->soundId);
    fn_801A7974((char *)v + 0x26C, lbl_8033212C, v->soundId);
    fn_801A7974((char *)v + 0x27C, lbl_8033211C, v->soundId);
    fn_801A7974((char *)v + 0xAC, lbl_8055A388, v->soundId);
    fn_801A7974((char *)v + 0xFC, lbl_8055A380, v->soundId);
    fn_801A7974((char *)v + 0x10C, lbl_80332110, v->soundId);
    fn_801A7974((char *)v + 0x15C, lbl_8055A378, v->soundId);
    fn_801A7974((char *)v + 0x13C, lbl_8055A370, v->soundId);
    fn_801A7974((char *)v + 0x14C, lbl_80332104, v->soundId);
    fn_801A7974((char *)v + 0x16C, lbl_8055A368, v->soundId);
    fn_801A7974((char *)v + 0x17C, lbl_8055A360, v->soundId);
    fn_801A7974((char *)v + 0x11C, lbl_8055A358, v->soundId);
    fn_801A7974((char *)v + 0x12C, lbl_8055A350, v->soundId);
    fn_801A7974((char *)v + 0x1AC, lbl_803320F8, v->soundId);
    fn_801A7974((char *)v + 0x1BC, lbl_803320EC, v->soundId);
    fn_801A7974((char *)v + 0x1CC, lbl_803320E0, v->soundId);
    fn_801A7974((char *)v + 0x28C, lbl_803320D4, v->soundId);
    fn_801A7974((char *)v + 0x29C, lbl_803320C8, v->soundId);
    fn_801A7974((char *)v + 0x2AC, lbl_803320BC, v->soundId);
    fn_801A7974((char *)v + 0x2BC, lbl_803320B0, v->soundId);
    fn_801331C4(v->soundId, lbl_8033209C, &lbl_8055A330);
    fn_801331C4(v->soundId, lbl_8033208C, &lbl_8055A334);
    fn_801331C4(v->soundId, lbl_80332078, &lbl_8055A338);
    fn_801331C4(v->soundId, lbl_80332064, &lbl_8055A33C);
    fn_801331C4(v->soundId, lbl_80332050, &lbl_8055A340);
    fn_801331C4(v->soundId, lbl_8033203C, &lbl_8055A344);
    v->flag341 = 0;
    fn_801333E8(v->soundId, lbl_80332030, (char *)v + 0x341);
    v->pad345[1] = 0;
    v->pad345[0] = 1;
    fn_801333E8(v->soundId, lbl_80332020, (char *)v + 0x346);
    fn_801333E8(v->soundId, lbl_80332008, (char *)v + 0x345);
    flag = 0;
    fn_801333E8(v->soundId, lbl_80331FFC, &flag);
    if (flag != 0) {
        fn_802E30C8(lbl_80331FF0);
        v->pad345[1] = 0;
        v->pad345[0] = 0;
    }
    fn_801A9110(&v->slot[23], lbl_80331FE4);
    fn_801A9110(&v->slot[24], lbl_80331FD8);
    fn_801A9110(&v->slot[25], lbl_80331FCC);
    fn_801A9110(&v->slot[26], lbl_80331FC0);
    fn_801A9110(&v->slot[27], lbl_80331FB4);
    fn_801A9110(&v->slot[28], lbl_80331FA8);
    fn_801A9110(&v->slot[29], lbl_80331F9C);
    slot = (int *)((char *)v + 0x1DC);
    for (j = 0; j < 6; j++, slot += 4) {
        sprintf(name, lbl_80331F90, j + 1);
        fn_801A7974((char *)slot, name, v->soundId);
    }
    fn_801A7974((char *)v + 0x23C, lbl_80331F80, v->soundId);
    {
        int head = v->axStackHead;
        v->flag344 = 0;
        v->slot[0].value = head;
        v->slot[1].value = head;
        v->slot[18].value = head;
        v->slot[19].value = head;
        v->slot[2].value = head;
        v->slot[3].value = head;
        v->slot[4].value = head;
        v->slot[7].value = head;
        v->slot[8].value = head;
        v->slot[5].value = head;
        v->slot[6].value = head;
        v->slot[9].value = head;
        v->slot[10].value = head;
        v->slot[13].value = head;
        v->slot[14].value = head;
        v->slot[15].value = head;
        v->slot[11].value = head;
        v->slot[12].value = head;
        v->slot[17].value = head;
        v->slot[30].value = head;
        v->slot[31].value = head;
        v->slot[32].value = head;
        v->slot[33].value = head;
        v->slot[16].value = head;
        v->slot[20].value = head;
        v->slot[21].value = head;
        v->slot[22].value = head;
        v->slot[34].value = head;
        v->slot[35].value = head;
        v->slot[36].value = head;
        v->slot[37].value = head;
        v->slot[38].value = head;
        v->slot[39].value = head;
        v->slot[40].value = head;
        v->slot[41].value = head;
        {
            char buf[96];
            if (fn_801298E8(buf, head) != 0 && ((*(int *)(buf + 0x50) & 0x10) != 0)) {
                *(volatile unsigned char *)((char *)v + 0x344) = 1;
                *(volatile unsigned char *)((char *)v + 0x344) = 1u;
            }
        }
    }
}
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

extern float lbl_80561C7C;
extern float lbl_80561C80;
extern float lbl_80561C84;
extern float lbl_80561C88;
extern float lbl_80561C8C;
extern float lbl_80561C90;
extern float lbl_80561C94;
extern float lbl_8055A330;
extern float lbl_8055A338;
extern float lbl_8055A33C;
extern float lbl_8055A340;
extern float lbl_8055A344;
extern char lbl_80331E58[];
extern char lbl_80331F80[];
extern char lbl_80331F90[];
extern char lbl_80331F9C[];
extern char lbl_80331FA8[];
extern char lbl_80331FB4[];
extern char lbl_80331FC0[];
extern char lbl_80331FCC[];
extern char lbl_80331FD8[];
extern char lbl_80331FE4[];
extern char lbl_80331FF0[];
extern char lbl_80331FFC[];
extern char lbl_80332008[];
extern char lbl_80332020[];
extern char lbl_80332030[];
extern char lbl_8033203C[];
extern char lbl_80332050[];
extern char lbl_80332064[];
extern char lbl_80332078[];
extern char lbl_8033208C[];
extern char lbl_8033209C[];
extern char lbl_803320B0[];
extern char lbl_803320BC[];
extern char lbl_803320C8[];
extern char lbl_803320D4[];
extern char lbl_803320E0[];
extern char lbl_803320EC[];
extern char lbl_803320F8[];
extern char lbl_80332104[];
extern char lbl_80332110[];
extern char lbl_8033211C[];
extern char lbl_8033212C[];
extern char lbl_80332138[];
extern char lbl_80332144[];
extern char lbl_80332150[];
extern char lbl_8033215C[];
extern char lbl_80332168[];
extern char lbl_80332178[];
extern char lbl_80332184[];
extern char lbl_80332194[];
extern char lbl_803321A0[];
extern char lbl_803321AC[];
extern char lbl_803321B8[];
extern char lbl_803321C4[];
extern char lbl_803321D0[];
extern char lbl_803321E4[];
extern char lbl_803321F0[];
extern char lbl_80332200[];
extern char lbl_80332210[];
extern char lbl_80332220[];
extern char lbl_80332238[];
extern char lbl_80332248[];
extern char lbl_80332258[];
extern char lbl_80332270[];
extern int lbl_802F9530[];
extern int lbl_802F9540[];
__declspec(section ".sdata") extern const char lbl_8055A350[];
__declspec(section ".sdata") extern const char lbl_8055A358[];
__declspec(section ".sdata") extern const char lbl_8055A360[];
__declspec(section ".sdata") extern const char lbl_8055A368[];
__declspec(section ".sdata") extern const char lbl_8055A370[];
__declspec(section ".sdata") extern const char lbl_8055A378[];
__declspec(section ".sdata") extern const char lbl_8055A380[];
__declspec(section ".sdata") extern const char lbl_8055A388[];
__declspec(section ".sdata") extern const char lbl_8055A390[];
__declspec(section ".sdata") extern const char lbl_8055A398[];
extern void fn_801331C4(int, const char *, void *);
extern void fn_801333E8(int, const char *, void *);
extern void fn_801A7974(void *, const char *, int);
extern void fn_801A7DFC(int, int, int);
extern void fn_801A9110(void *, const char *);
extern int sprintf(char *, const char *, ...);
void fn_801808DC(void) {
    char name[64];
    unsigned char flag;
    int keys1[4];
    int keys2[4];
    int i;
    int count;
    void *obj;
    void **table;
    int *slot;
    fn_801333E8(8, lbl_80331E58, &lbl_8055E4B9);
    lbl_8055E4B8 = 1;
    for (count = 0, table = (void **)lbl_804348D8; count < 4; count++, table++) {
        obj = *table;
        if (obj != 0) {
            *(int *)((char *)obj + 8) = __AXGetStackHead_80137CFC(*(int *)((char *)obj + 4));
            *(float *)((char *)obj + 0x2C) = lbl_80561C7C;
            *(float *)((char *)obj + 0x38) = lbl_80561C7C;
            *(float *)((char *)obj + 0x44) = lbl_80561C80;
            *(float *)((char *)obj + 0x34) = lbl_80561C48;
            *(float *)((char *)obj + 0x40) = lbl_80561C84;
            *(float *)((char *)obj + 0x4C) = lbl_80561C88;
            *(float *)((char *)obj + 0x30) = lbl_80561C8C;
            *(float *)((char *)obj + 0x3C) = lbl_80561C90;
            *(float *)((char *)obj + 0x48) = lbl_80561C8C;
            *(unsigned char *)((char *)obj + 0x340) = 0;
            *(unsigned char *)((char *)obj + 0x341) = 0;
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332270, (char *)obj + 0x2C);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332258, (char *)obj + 0x38);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332248, (char *)obj + 0x44);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332238, (char *)obj + 0x30);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332220, (char *)obj + 0x3C);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332210, (char *)obj + 0x48);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332200, (char *)obj + 0x34);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_803321F0, (char *)obj + 0x40);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_803321E4, (char *)obj + 0x4C);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_803321D0, (char *)obj + 0x60);
            *(unsigned char *)((char *)obj + 0x5C) = 1;
            fn_801333E8(*(int *)((char *)obj + 0x34C), lbl_803321C4, (char *)obj + 0x340);
            fn_801333E8(*(int *)((char *)obj + 0x34C), lbl_803321B8, (char *)obj + 0x341);
            *(unsigned char *)((char *)obj + 0x5E) = 1;
            *(float *)((char *)obj + 0x64) = fn_8014C8F8(*(float *)((char *)obj + 0x60) - lbl_80561C48, lbl_80561C4C, lbl_80561C48);
            *(float *)((char *)obj + 0x60) = fn_8014C8F8(*(float *)((char *)obj + 0x60), lbl_80561C4C, lbl_80561C48);
            *(float *)((char *)obj + 0x34) = fn_801429D0(*(float *)((char *)obj + 0x34), lbl_80561C94);
            *(float *)((char *)obj + 0x40) = fn_801429D0(*(float *)((char *)obj + 0x40), lbl_80561C94);
            *(float *)((char *)obj + 0x4C) = fn_801429D0(*(float *)((char *)obj + 0x4C), lbl_80561C94);
            if (((int (*)(void *))(*(void ***)obj)[23])(obj) != 0) {
                *(float *)((char *)obj + 0x60) = lbl_80561C4C;
            }
            fn_802E8524(*(unsigned char *)((char *)obj + 0x5C), *(int *)((char *)obj + 8));
            keys1[0] = lbl_802F9530[0];
            keys1[1] = lbl_802F9530[1];
            keys1[2] = lbl_802F9530[2];
            keys1[3] = lbl_802F9530[3];
            keys2[0] = lbl_802F9540[0];
            keys2[1] = lbl_802F9540[1];
            keys2[2] = lbl_802F9540[2];
            keys2[3] = lbl_802F9540[3];
            slot = (int *)((char *)obj + 0x2CC);
            for (i = 0; i < 4; i++, slot += 4) {
                fn_801A7DFC(keys1[i], keys2[i], *(int *)((char *)obj + 0x34C));
                fn_801A7974((char *)slot, (const char *)keys1[i], *(int *)((char *)obj + 0x34C));
            }
            fn_801A7974((char *)obj + 0x6C, lbl_803321AC, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x7C, lbl_803321A0, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x18C, lbl_80332194, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x19C, lbl_80332184, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x8C, lbl_80332178, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x9C, lbl_8055A398, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0xBC, lbl_80332168, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0xCC, lbl_8033215C, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0xDC, lbl_80332150, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0xEC, lbl_80332144, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x24C, lbl_8055A390, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x25C, lbl_80332138, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x26C, lbl_8033212C, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x27C, lbl_8033211C, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0xAC, lbl_8055A388, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0xFC, lbl_8055A380, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x10C, lbl_80332110, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x15C, lbl_8055A378, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x13C, lbl_8055A370, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x14C, lbl_80332104, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x16C, lbl_8055A368, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x17C, lbl_8055A360, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x11C, lbl_8055A358, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x12C, lbl_8055A350, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x1AC, lbl_803320F8, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x1BC, lbl_803320EC, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x1CC, lbl_803320E0, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x28C, lbl_803320D4, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x29C, lbl_803320C8, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x2AC, lbl_803320BC, *(int *)((char *)obj + 0x34C));
            fn_801A7974((char *)obj + 0x2BC, lbl_803320B0, *(int *)((char *)obj + 0x34C));
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_8033209C, &lbl_8055A330);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_8033208C, &lbl_8055A334);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332078, &lbl_8055A338);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332064, &lbl_8055A33C);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_80332050, &lbl_8055A340);
            fn_801331C4(*(int *)((char *)obj + 0x34C), lbl_8033203C, &lbl_8055A344);
            *(unsigned char *)((char *)obj + 0x341) = 0;
            fn_801333E8(*(int *)((char *)obj + 0x34C), lbl_80332030, (char *)obj + 0x341);
            *(unsigned char *)((char *)obj + 0x346) = 0;
            *(unsigned char *)((char *)obj + 0x345) = 1;
            fn_801333E8(*(int *)((char *)obj + 0x34C), lbl_80332020, (char *)obj + 0x346);
            fn_801333E8(*(int *)((char *)obj + 0x34C), lbl_80332008, (char *)obj + 0x345);
            flag = 0;
            fn_801333E8(*(int *)((char *)obj + 0x34C), lbl_80331FFC, &flag);
            if (flag != 0) {
                fn_802E30C8(lbl_80331FF0);
                *(unsigned char *)((char *)obj + 0x346) = 0;
                *(unsigned char *)((char *)obj + 0x345) = 0;
            }
            fn_801A9110((char *)obj + 0x1DC, lbl_80331FE4);
            fn_801A9110((char *)obj + 0x1EC, lbl_80331FD8);
            fn_801A9110((char *)obj + 0x1FC, lbl_80331FCC);
            fn_801A9110((char *)obj + 0x20C, lbl_80331FC0);
            fn_801A9110((char *)obj + 0x21C, lbl_80331FB4);
            fn_801A9110((char *)obj + 0x22C, lbl_80331FA8);
            fn_801A9110((char *)obj + 0x23C, lbl_80331F9C);
            slot = (int *)((char *)obj + 0x1DC);
            for (i = 0; i < 6; i++, slot += 4) {
                sprintf(name, lbl_80331F90, i + 1);
                fn_801A7974((char *)slot, name, *(int *)((char *)obj + 0x34C));
            }
            fn_801A7974((char *)obj + 0x23C, lbl_80331F80, *(int *)((char *)obj + 0x34C));
            {
                int head = *(int *)((char *)obj + 8);
                int *p = (int *)((char *)obj + 0x70);
                *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4; *p = head; p += 4;
            }
            *(unsigned char *)((char *)obj + 0x344) = 0;
            {
                char buf[96];
                if (fn_801298E8(buf, *(int *)((char *)obj + 8)) != 0 && ((*(int *)(buf + 0x50) & 0x10) != 0)) {
                    *(unsigned char *)((char *)obj + 0x344) = 1;
                    *(unsigned char *)((char *)obj + 0x344) = 1;
                }
            }
        }
    }
}

/* One of the sound-player slots a DriverInterface owns from 0x6C on;
 * fn_80181418 resets one (its id and its "in use" byte), fn_8017F718 gives
 * each of them a name and the sound it plays. */
struct DriverInterfaceSlot {
    void *handler;    /* 0x00 */
    s32 value;        /* 0x04 */
    u8 pad08[4];
    u8 inUse;         /* 0x0C */
    u8 pad0D[3];
};

/* The "DriverInterface" object (the name it is heap-allocated under,
 * lbl_80331E68): one per driver index, created on demand by fn_8018108C and
 * kept in lbl_804348D8[].  Its vtable is lbl_80331E78 (fn_80181428 is the
 * base constructor, which sets the one at lbl_80331EFC first).  Only the
 * fields this file's code touches are named. */
struct DriverInterface {
    void *vtable;                     /* 0x000 */
    s32 index;                        /* 0x004 driver index */
    s32 axStackHead;                  /* 0x008 __AXGetStackHead_80137CFC(index) */
    f32 pad0C[8];                     /* 0x00C */
    f32 level2C[9];                   /* 0x02C levels fn_8017F718 registers */
    s32 pad50[2];                     /* 0x050 */
    u8 flag58;                        /* 0x058 */
    u8 flag59;                        /* 0x059 */
    u8 flag5A;                        /* 0x05A */
    u8 flag5B;                        /* 0x05B */
    u8 flag5C;                        /* 0x05C */
    u8 flag5D;                        /* 0x05D */
    u8 flag5E;                        /* 0x05E */
    u8 pad5F;
    f32 pad60;                        /* 0x060 */
    u8 pad64[4];
    u8 flag68;                        /* 0x068 */
    u8 pad69[3];
    struct DriverInterfaceSlot slot[42]; /* 0x06C */
    f32 pad30C[9];                    /* 0x30C */
    u8 pad330[8];
    u8 flag338;                       /* 0x338 */
    u8 pad339[3];
    f32 pad33C;                       /* 0x33C */
    u8 flag340;                       /* 0x340 */
    u8 flag341;                       /* 0x341 */
    u8 flag342;                       /* 0x342 */
    u8 flag343;                       /* 0x343 */
    u8 flag344;                       /* 0x344 */
    u8 pad345[3];
    s32 mode348;                      /* 0x348 0x10, or the index + 0xC */
    s32 soundId;                      /* 0x34C axStackHead + 8 */
    u8 flag350;                       /* 0x350 */
    u8 pad351[3];
};

/* The object is handled as a void * here; cast it to name its fields. */
#define DRIVER(p) ((struct DriverInterface *)(p))

/* The float at 0x30C on its own.  Reaching it as a member (rather than as an
 * array element of the whole object) is what lets the compiler reuse the
 * address the slot loops leave in a register. */
struct DriverInterface30C { u8 pad[0x30c]; f32 field; };

/* The float literals this unit keeps in .sdata2. */
#define F_ZERO lbl_80561C4C  /* 0.0f */
#define F_ONE lbl_80561C48   /* 1.0f */
#define F_TENTH lbl_80561C8C /* 0.1f */

#pragma dont_inline fn_80181418
#pragma dont_inline fn_80181428
extern void fn_80181418(void *, int);
extern void fn_80181428(void **);
extern void *fn_801284F8(s32, const char *);
extern s32 fn_8027AA48(void);
extern u8 lbl_80331E68[];
extern u8 lbl_80331E78[];
extern f32 lbl_80561C8C;
#pragma dont_inline fn_80181418
#pragma dont_inline fn_80181428
#pragma scheduling invalid_target
/* Create the DriverInterface of driver index arg0 - once; the four of them
 * live in lbl_804348D8[] - and return it, or 0 when the heap has no room.
 * The object itself only gets its identity, its sound id and zeroed player
 * slots here; fn_8017F718 is what names the slots and registers the sounds. */
s32 fn_8018108C(s32 arg0) {
    Unk8017Object **table;
    s32 entry_offset = arg0 * 4;
    void *slot_end;
    void *driver;
    void *slot;
    void *slot2;
    s32 zero;
    f32 zero_f, one_f, tenth_f;

    if ((table = lbl_804348D8,
         *(Unk8017Object **)((u8 *)table + entry_offset)) == 0) {
        driver = fn_801284F8(sizeof(struct DriverInterface), (const char *)lbl_80331E68);
        if (driver != 0) {
            fn_80181428(&DRIVER(driver)->vtable);
            DRIVER(driver)->vtable = lbl_80331E78;
            fn_80181418(&DRIVER(driver)->slot[0], 0);
            fn_80181418(&DRIVER(driver)->slot[1], 0);
            fn_80181418(&DRIVER(driver)->slot[2], 0);
            fn_80181418(&DRIVER(driver)->slot[3], 0);
            fn_80181418(&DRIVER(driver)->slot[4], 0);
            fn_80181418(&DRIVER(driver)->slot[5], 0);
            fn_80181418(&DRIVER(driver)->slot[6], 0);
            fn_80181418(&DRIVER(driver)->slot[7], 0);
            fn_80181418(&DRIVER(driver)->slot[8], 0);
            fn_80181418(&DRIVER(driver)->slot[9], 0);
            fn_80181418(&DRIVER(driver)->slot[10], 0);
            fn_80181418(&DRIVER(driver)->slot[11], 0);
            fn_80181418(&DRIVER(driver)->slot[12], 0);
            fn_80181418(&DRIVER(driver)->slot[13], 0);
            fn_80181418(&DRIVER(driver)->slot[14], 0);
            fn_80181418(&DRIVER(driver)->slot[15], 0);
            fn_80181418(&DRIVER(driver)->slot[16], 0);
            fn_80181418(&DRIVER(driver)->slot[17], 0);
            fn_80181418(&DRIVER(driver)->slot[18], 0);
            fn_80181418(&DRIVER(driver)->slot[19], 0);
            fn_80181418(&DRIVER(driver)->slot[20], 0);
            fn_80181418(&DRIVER(driver)->slot[21], 0);
            fn_80181418(&DRIVER(driver)->slot[22], 0);
            slot = (u8 *)driver + 0x1DC; /* slot[23] .. slot[28] */
            slot_end = (u8 *)driver + 0x23C;
            do {
                fn_80181418(slot, 0);
                slot = (u8 *)slot + 0x10;
            } while (slot < slot_end);
            fn_80181418(slot_end, 0);
            fn_80181418(&DRIVER(driver)->slot[30], 0);
            fn_80181418(&DRIVER(driver)->slot[31], 0);
            fn_80181418(&DRIVER(driver)->slot[32], 0);
            fn_80181418(&DRIVER(driver)->slot[33], 0);
            fn_80181418(&DRIVER(driver)->slot[34], 0);
            fn_80181418(&DRIVER(driver)->slot[35], 0);
            fn_80181418(&DRIVER(driver)->slot[36], 0);
            fn_80181418(&DRIVER(driver)->slot[37], 0);
            slot2 = (u8 *)driver + 0x2CC; /* slot[38] .. slot[41] */
            slot_end = (u8 *)driver + 0x30C;
            do {
                fn_80181418(slot2, 0);
                slot2 = (u8 *)slot2 + 0x10;
            } while (slot2 < slot_end);

            DRIVER(driver)->index = arg0;
            DRIVER(driver)->axStackHead = __AXGetStackHead_80137CFC(arg0);
            DRIVER(driver)->flag350 = 0;
            if (fn_8027AA48() != 0)
                DRIVER(driver)->mode348 = 0x10;
            else
                DRIVER(driver)->mode348 = arg0 + 0xC;
            zero = 0;
            zero_f = F_ZERO;
            DRIVER(driver)->soundId =
                DRIVER(driver)->axStackHead + 8;
            one_f = F_ONE;
            {
                DRIVER(driver)->pad33C = zero_f;
                tenth_f = F_TENTH;
                DRIVER(driver)->flag5B = zero;
                DRIVER(driver)->flag5C = zero;
                DRIVER(driver)->flag5E = 1;
                DRIVER(driver)->pad60 = one_f;
                DRIVER(driver)->level2C[0] = zero_f;
                DRIVER(driver)->level2C[2] = one_f;
                DRIVER(driver)->level2C[1] = tenth_f;
                DRIVER(driver)->level2C[3] = tenth_f;
                DRIVER(driver)->level2C[5] = one_f;
                DRIVER(driver)->level2C[4] = tenth_f;
                DRIVER(driver)->level2C[6] = tenth_f;
                DRIVER(driver)->level2C[8] = one_f;
                DRIVER(driver)->level2C[7] = tenth_f;
                DRIVER(driver)->pad50[0] = zero;
                DRIVER(driver)->pad50[1] = zero;
                DRIVER(driver)->pad0C[0] = zero_f;
                DRIVER(driver)->pad0C[1] = zero_f;
                DRIVER(driver)->pad0C[2] = zero_f;
                DRIVER(driver)->pad0C[5] = zero_f;
                DRIVER(driver)->pad0C[3] = zero_f;
                DRIVER(driver)->pad0C[6] = zero_f;
                DRIVER(driver)->pad0C[4] = zero_f;
                DRIVER(driver)->pad0C[7] = zero_f;
                DRIVER(driver)->flag58 = zero;
                DRIVER(driver)->flag5D = zero;
                DRIVER(driver)->flag68 = zero;
                DRIVER(driver)->flag59 = zero;
                DRIVER(driver)->flag5A = zero;
                DRIVER(driver)->pad30C[2] = zero_f;
                DRIVER(driver)->pad30C[1] = zero_f;
                ((struct DriverInterface30C *)driver)->field = zero_f;
                DRIVER(driver)->pad30C[5] = zero_f;
                DRIVER(driver)->pad30C[4] = zero_f;
                DRIVER(driver)->pad30C[3] = zero_f;
                DRIVER(driver)->pad30C[7] = zero_f;
                DRIVER(driver)->pad30C[6] = zero_f;
                DRIVER(driver)->pad30C[8] = zero_f;
                DRIVER(driver)->flag338 = zero;
                DRIVER(driver)->flag340 = zero;
                DRIVER(driver)->flag341 = zero;
                DRIVER(driver)->flag342 = zero;
                DRIVER(driver)->flag343 = zero;
                DRIVER(driver)->flag344 = zero;
                ((void (*)(void *, f32, f32))fn_8017F718)(driver, one_f, zero_f);
            }
        }
        *(Unk8017Object **)((u8 *)table + entry_offset) = driver;
    }
    return (s32)*(Unk8017Object **)((u8 *)table + entry_offset);
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

#pragma push
#pragma cplusplus on
#pragma paired_single off
#pragma scheduling invalid_target
extern "C" float fn_80181498(void *arg0) {
    class Callback {
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
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
        virtual int f21();
    };
    float f31 = *(float *)((char *)arg0 + 0xC);
    float f2;
    float f0;

    f0 = lbl_80561C48;
    if (f31 > f0) {
    } else {
        f31 = f0;
    }
    f2 = *(float *)((char *)arg0 + 0xC);
    f0 = lbl_80561C58;
    if (f2 < f0) {
        f2 = f0;
    }
    f0 = *(float *)((char *)arg0 + 0xC);
    f0 += *(float *)((char *)arg0 + 0x10);
    if (f31 < f0) {
        f31 = f0;
    }
    if (f31 > f2) {
        f31 = f2;
    }
    if (((Callback *)arg0)->f21() != 0) {
        f31 = *(float *)((char *)arg0 + 0xC);
    }
    return f31;
}
#pragma pop
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
    for (p = (char *)arg0 + 0x2cc, i = 0; i < 4; i++, p += 0x10) {
        if (fn_801A8E68(p)) {
            fn_801797F8(*(int *)((char *)arg0 + 4), 4, i);
            break;
        }
    }
}

void fn_80181700(void *arg0, int arg1) {
    int val;
    *(unsigned char *)((char *)arg0 + 0x350) = arg1;
    if (arg1 != 0) return;
    val = *(int *)((char *)arg0 + 8);
    if (val < 0) return;
    ((void (*)(int))fn_802E8518)(val);
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
