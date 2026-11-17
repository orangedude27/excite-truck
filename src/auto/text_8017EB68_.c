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

/* Ball-body vtable method: `child` points 0x1EC into the owning object, so recover
 * the BallBody base and forward to fn_8017E930 (out params pass through in r4/r5),
 * which reports the placed ball's x/z position and velocity. */
void fn_8017EB68(void *child) {
    fn_8017E930((char *)child - 0x1EC);
}

extern void fn_8017E96C(void *);
/* Ball-body vtable method: `child` points 0x1EC into the owning object, so recover
 * the BallBody base and forward to fn_8017E96C (out params pass through in r4/r5),
 * which reports a status string and flag derived from the ball's state. */
void fn_8017EB70(void *child) {
    fn_8017E96C((char *)child - 0x1EC);
}

extern void fn_8017E9FC(void *);
/* Ball-body vtable method: `child` points 0x1EC into the owning object, so recover
 * the BallBody base and forward to fn_8017E9FC (other args pass through in r4/r5),
 * which advances the ball's state machine and plays a sound when triggered. */
void fn_8017EB78(void *child) {
    fn_8017E9FC((char *)child - 0x1EC);
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
    int zero;
    int one;

    /* Initialize global player/object state slots and run startup setup. */
    zero = 0;
    one = 1;
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
#pragma scheduling on
void fn_8017EC30(void) {
    /* Shut down the four driver interfaces: for each occupied slot in
     * lbl_804348D8[], call the object's virtual release method (vtable +0x80),
     * clear the slot, then mark the whole group inactive in lbl_8055E4BA. */
    Unk8017Object **slot = lbl_804348D8;
    int driverIndex = 0;
    do {
        Unk8017Object *driver;
        fn_802E8524(0, driverIndex);
        driver = *slot;
        if (driver != 0) {
#pragma push
#pragma cplusplus on
            {
                class DriverInterfaceView {
                public:
                    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
                    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
                    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
                    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
                    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
                    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
                    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
                    virtual void f28(); virtual void f29();
                    virtual void release(int);
                };
                if (driver != 0) ((DriverInterfaceView *)driver)->release(1);
            }
#pragma pop
            *slot = 0;
        }
        driverIndex++;
        slot++;
    } while (driverIndex < 4);
    lbl_8055E4BA = 0;
}
int fn_8017ECC0(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
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
    /* Updates rumble/audio parameters from the object's state when active; otherwise resets them. */
    float scaleFactor = lbl_8055A334;
    if (fn_801769F8() == 0 && fn_801B526C() == 0 && fn_801C5B60() == 0 &&
        *(unsigned char *)((char *)arg0 + 0x5C) && *(unsigned char *)((char *)arg0 + 0x350)) {
        float scaledBase = *(float *)((char *)arg0 + 0x30C) * scaleFactor;
        fn_802E85AC(*(int *)((char *)arg0 + 8), *(float *)((char *)arg0 + 0x314) + scaledBase,
                    *(float *)((char *)arg0 + 0x310) * scaleFactor, scaledBase);
        {
            float scaledParamB = *(float *)((char *)arg0 + 0x318) * scaleFactor;
            float scaledParamC = *(float *)((char *)arg0 + 0x320) * scaleFactor;
            float paramD = *(float *)((char *)arg0 + 0x31C);
            fn_802E85A8(*(int *)((char *)arg0 + 8), scaledParamB, paramD, scaledParamC);
        }
        {
            float scaledX = *(float *)((char *)arg0 + 0x324) * scaleFactor;
            float rawY = *(float *)((char *)arg0 + 0x328);
            float absY = __fabs(rawY);
            float absScaledX = __fabs(scaledX);
            fn_802E8528(*(int *)((char *)arg0 + 8), lbl_80561C60 * absScaledX, absY);
        }
    } else ((void (*)(int))fn_802E8518)(*(int *)((char *)arg0 + 8));
}
#pragma pop
/* Single-precision absolute value (computed in double, then rounded back to float). */
float fn_8017F70C(float value) { double temp = __fabs(value); return temp; }

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
    {
        int *p1 = lbl_802F9530;
        int *p2 = lbl_802F9540;
        keys1[0] = *p1++;
        keys1[1] = *p1++;
        keys1[2] = *p1++;
        keys1[3] = *p1;
        keys2[0] = *p2++;
        keys2[1] = *p2++;
        keys2[2] = *p2++;
        keys2[3] = *p2;
    }
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
/* Return 1 if the object's flag at 0x340 is set or if either of the checked subobjects at offsets 0x6C or 0x7C reports active via fn_801A8EE4. */
int fn_8017FEE4(void *object) {
    int isActive = 0;
    if (*(unsigned char *)((char *)object + 0x340) != 0 ||
        fn_801A8EE4((char *)object + 0x6C) != 0 ||
        fn_801A8EE4((char *)object + 0x7C) != 0) {
        isActive = 1;
    }
    return isActive;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_8017FF4C(f32 dt) {
    /* Per-frame input update for all four players: translate each bound slot
     * into a control value (fn_801A7F98), apply analog rates/dead-zones and
     * digital presses, and write the results into the player's pad0C[] controls
     * and flag bytes. When the early-out condition holds, zero the cached
     * pad30C[] history instead. dt is the frame delta time. */
    struct {
        u8 pad00[0x50];
        u32 flags;
        u8 pad54[0x1C];
    } ctrlInfo;
    u8 useAltB;
    u8 useAltA;
    struct Di718 **playerPtr;
    struct Di718 *player;
    s32 playerIdx;

    if ((u8)lbl_8055E4B8 == 0) {
        return;
    }
    if (fn_801769F8() == 0 && fn_801B526C() == 0) {
        f32 k78;
        f32 k70;
        f32 k6C;
        f32 k64;
        f32 k68;
        f32 k5C;
        f32 minusOne;
        f32 one;
        f32 zero;
        f32 k50;
        f32 k54;
        fn_801A7844(1);
        zero = lbl_80561C4C;
        k70 = lbl_80561C70;
        k6C = lbl_80561C6C;
        k68 = lbl_80561C68;
        k64 = lbl_80561C64;
        k5C = lbl_80561C5C;
        k54 = lbl_80561C54;
        k50 = lbl_80561C50;
        one = lbl_80561C48;
        minusOne = lbl_80561C58;
        k78 = lbl_80561C78;
        playerPtr = (struct Di718 **)lbl_804348D8;
        for (playerIdx = 0; playerIdx < 4; playerIdx++, playerPtr++) {
            s32 slotValue;
            struct Di718Slot *activeSlot;
            struct Di718Slot *gearSlot;
            s32 gear;

            player = *playerPtr;
            if (player == NULL) {
                continue;
            }
            if (player->axStackHead != __AXGetStackHead_80137CFC(player->index)) {
                fn_802E30C8(lbl_80332280, player->index);
                fn_8017F718(player);
            }
            useAltA = player->pad345[0];
            useAltB = player->pad345[1];
            player->flag342 = 0;
            player->flag343 = 0;
            slotValue = player->slot[2].value;
            if (fn_802E85B0(slotValue) == 4) {
                player->flag343 = 1;
                useAltA = 0;
                useAltB = 0;
            }
            if (fn_801298E8(&ctrlInfo, slotValue) != 0) {
                if (ctrlInfo.flags & 2) {
                    player->flag343 = 1;
                    useAltA = 0;
                    useAltB = 0;
                }
                if (ctrlInfo.flags & 8) {
                    player->flag342 = 1;
                    player->flag343 = 1;
                }
            }

            /* Steering: digital left/right or the analog axis difference. */
            if (player->flag340 || fn_801A8EE4(&player->slot[0]) || fn_801A8EE4(&player->slot[1])) {
                f32 base = k54 * player->level2C[2];
                f32 rate = k50 * base;
                f32 fast = rate + base;
                if (player->pad0C[0] > zero) {
                    player->pad0C[0] = fn_801429D0(player->pad0C[0] - rate * dt, zero);
                }
                if (player->pad0C[0] < zero) {
                    player->pad0C[0] = fn_801429E0(player->pad0C[0] + rate * dt, zero);
                }
                if (fn_801A8E38(&player->slot[0])) {
                    player->pad0C[0] -= fast * dt;
                }
                if (fn_801A8E38(&player->slot[1])) {
                    player->pad0C[0] += fast * dt;
                }
                if (player->pad0C[0] > one) {
                    player->pad0C[0] = one;
                }
                if (player->pad0C[0] < minusOne) {
                    player->pad0C[0] = minusOne;
                }
            } else {
                f32 prevSteer = player->pad0C[0];
                f32 rightAxis = fn_801A7F98(&player->slot[1]);
                f32 leftAxis = fn_801A7F98(&player->slot[0]);
                f32 steerInput = -leftAxis + rightAxis;
                if (player->flag344) {
                    player->pad0C[0] = fn_8017EB80(steerInput, player->level2C[0], player->level2C[1]);
                } else if (!player->flag343) {
                    player->pad0C[0] = fn_8017EB80(steerInput, player->level2C[0], player->level2C[1]);
                    player->pad0C[0] *= (one + player->pad60 * fn_8017F70C(player->pad0C[0])) - player->pad60;
                    player->pad0C[0] *= (one + player->pad64 * fn_8017F70C(player->pad0C[0])) - player->pad64;
                } else {
                    player->pad0C[0] = steerInput;
                    if (player->flag342) {
                        player->pad0C[0] *= k5C;
                    }
                }
                if ((u8)lbl_8055E4B9 != 0) {
                    player->pad0C[0] = fn_80144C80(player->pad0C[0], prevSteer, lbl_80561C60);
                }
            }

            /* Acceleration/brake axis. */
            {
                f32 base = k54 * player->level2C[2];
                f32 rate = k50 * base;
                f32 fast = rate + base;
                if (player->pad0C[1] > zero) {
                    player->pad0C[1] = fn_801429D0(player->pad0C[1] - rate * dt, zero);
                }
                if (player->pad0C[1] < zero) {
                    player->pad0C[1] = fn_801429E0(player->pad0C[1] + rate * dt, zero);
                }
                if (fn_801A8E38(&player->slot[18])) {
                    player->pad0C[1] -= fast * dt;
                }
                if (fn_801A8E38(&player->slot[19])) {
                    player->pad0C[1] += fast * dt;
                }
                if (player->pad0C[1] > one) {
                    player->pad0C[1] = one;
                }
                if (player->pad0C[1] < minusOne) {
                    player->pad0C[1] = minusOne;
                }
            }

            activeSlot = &player->slot[2];
            if (!fn_801A8F10(activeSlot)) {
                activeSlot = &player->slot[5];
            } else if (useAltA && fn_801A8F10(&player->slot[5])) {
                activeSlot = &player->slot[5];
            }
            if (player->flag340 || useAltA || fn_801A8EE4(activeSlot)) {
                f32 down;
                f32 up;
                up = k64 * player->level2C[5];
                down = k5C * up;
                if (fn_801A8E38(activeSlot)) {
                    player->pad0C[5] = fn_801429E0(player->pad0C[5] + up * dt, lbl_80561C48);
                } else {
                    player->pad0C[5] = fn_801429D0(player->pad0C[5] - down * dt, lbl_80561C4C);
                }
            } else {
                player->pad0C[5] = fn_8017EB80(fn_801A7F98(activeSlot), player->level2C[3], player->level2C[4]);
            }

            if (player->flag340 || fn_801A8EE4(&player->slot[7])) {
                f32 down;
                f32 up;
                up = k64 * player->level2C[5];
                down = k5C * up;
                if (fn_801A8E38(&player->slot[7])) {
                    player->pad0C[6] = fn_801429E0(player->pad0C[6] + up * dt, lbl_80561C48);
                } else {
                    player->pad0C[6] = fn_801429D0(player->pad0C[6] - down * dt, lbl_80561C4C);
                }
            } else {
                player->pad0C[6] = fn_8017EB80(fn_801A7F98(&player->slot[7]), player->level2C[3], player->level2C[4]);
            }

            activeSlot = &player->slot[3];
            if (!fn_801A8F10(activeSlot)) {
                activeSlot = &player->slot[6];
            } else if (useAltB && fn_801A8F10(&player->slot[6])) {
                activeSlot = &player->slot[6];
            }
            if (player->flag340 || useAltB || fn_801A8EE4(activeSlot)) {
                f32 up = k68 * player->level2C[8];
                f32 down = k64 * player->level2C[8];
                if (player->pad0C[2] > zero) {
                    player->pad0C[2] = fn_801429D0(player->pad0C[2] - down * dt, zero);
                }
                if (fn_801A8E38(activeSlot)) {
                    player->pad0C[2] += up * dt;
                }
                if (player->pad0C[2] > one) {
                    player->pad0C[2] = one;
                }
            } else {
                player->pad0C[2] = fn_8017EB80(fn_801A7F98(activeSlot), player->level2C[6], player->level2C[7]);
            }

            if (player->flag340 || fn_801A8EE4(&player->slot[8])) {
                f32 up = k68 * player->level2C[8];
                f32 down = k64 * player->level2C[8];
                if (player->pad0C[3] > zero) {
                    player->pad0C[3] = fn_801429D0(player->pad0C[3] - down * dt, zero);
                }
                if (fn_801A8E38(&player->slot[8])) {
                    player->pad0C[3] += up * dt;
                }
                if (player->pad0C[3] > one) {
                    player->pad0C[3] = one;
                }
            } else {
                player->pad0C[3] = fn_8017EB80(fn_801A7F98(&player->slot[8]), player->level2C[6], player->level2C[7]);
            }

            player->pad0C[7] = fn_801A7F98(&player->slot[4]);
            if (!player->flag341) {
                player->flag5A = fn_801A8E38(&player->slot[9]) || fn_801A8E38(&player->slot[10]);
            }

            if (fn_801A8EE4(&player->slot[15])) {
                if (fn_801A8E38(&player->slot[15])) {
                    player->pad0C[4] += k6C * dt;
                } else if (player->pad0C[4] > zero) {
                    player->pad0C[4] = fn_801429D0(player->pad0C[4] - k70 * dt, zero);
                }
                if (player->pad0C[4] > one) {
                    player->pad0C[4] = one;
                }
            } else {
                player->pad0C[4] = fn_801A7F98(&player->slot[15]);
            }

            player->flag5B = fn_801A8E38(&player->slot[16]);
            player->flag58 = fn_801A8E38(&player->slot[11]) || fn_801A8E38(&player->slot[12]);
            player->flag5D = fn_801A8E68(&player->slot[2]);
            if (fn_80179300() < 40) {
                player->flag58 = 0;
            }
            player->flag68 = fn_801A8E38(&player->slot[17]);

            /* Camera/look axis is rate-limited towards the raw stick value. */
            {
                f32 leftAxis = fn_801A7F98(&player->slot[20]);
                f32 steerInput = fn_8017EB80(-leftAxis + fn_801A7F98(&player->slot[21]), lbl_80561C60, lbl_80561C74);
                f32 maxStep = k78 * dt;
                player->pad30C[8] += fn_8014C8F8(steerInput - player->pad30C[8], -maxStep, maxStep);
            }

            player->flag338 = fn_801A8E38(&player->slot[22]);
            if (fn_801A8E38(&player->slot[33])) {
                player->flag338 = 1;
            }
            {
                f32 negAxis = fn_801A7F98(&player->slot[34]);
                *(f32 *)&player->pad330[0] = fn_801A7F98(&player->slot[35]) - negAxis;
            }
            {
                f32 negAxis = fn_801A7F98(&player->slot[36]);
                *(f32 *)&player->pad330[4] = fn_801A7F98(&player->slot[37]) - negAxis;
            }

            /* Gear selection via +/- keys or the sequential gear slots. */
            if (!player->flag341) {
                if (fn_801A8E38(&player->slot[13])) {
                    if (!player->flag59) {
                        if (player->pad50[0] < player->pad50[1]) {
                            player->pad50[0]++;
                        }
                        player->flag59 = 1;
                    }
                } else if (fn_801A8E38(&player->slot[14])) {
                    if (!player->flag59) {
                        if (player->pad50[0] > -1) {
                            player->pad50[0]--;
                        }
                        player->flag59 = 1;
                    }
                } else {
                    player->flag59 = 0;
                }
            } else {
                player->flag59 = 0;
                player->pad50[0] = 0;
                gearSlot = &player->slot[23];
                for (gear = 0; gear < player->pad50[1]; gearSlot++, gear++) {
                    if (fn_801A8E38(gearSlot)) {
                        player->pad50[0] = gear + 1;
                    }
                }
                if (fn_801A8E38(&player->slot[29])) {
                    player->pad50[0] = -1;
                }
            }
            fn_8017F628(player);
        }
    } else {
        struct Di718 **playerPtr;
        s32 playerIdx;
        dt = lbl_80561C4C;
        playerPtr = (struct Di718 **)lbl_804348D8;
        for (playerIdx = 0; playerIdx < 4; playerIdx++, playerPtr++) {
            player = *playerPtr;
            if (player != NULL) {
                player->pad30C[6] = dt;
                player->pad30C[7] = dt;
                player->pad30C[2] = dt;
                player->pad30C[1] = dt;
                player->pad30C[0] = dt;
                player->pad30C[5] = dt;
                player->pad30C[4] = dt;
                player->pad30C[3] = dt;
                if (player->axStackHead >= 0) {
                    ((void (*)(s32))fn_802E8518)(player->axStackHead);
                }
            }
        }
    }
}
#pragma pop
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
#pragma push
#pragma processor 750
void fn_801808DC(void) {
    char name[64];
    unsigned char flag;
    int keys1[4];
    int keys2[4];
    int *slot;
    int i;
    int j;
    int count;
    struct Di718 *v;
    float f90;
    float f8C;
    float f88;
    float f84;
    float f48;
    float f80;
    float f7C;
    float f4C;
    Unk8017Object **table;
    int *keyBase1;
    int *keyBase2;
    fn_801333E8(8, lbl_80331E58, &lbl_8055E4B9);
    lbl_8055E4B8 = 1;
    f48 = lbl_80561C48;
    f7C = lbl_80561C7C;
    f80 = lbl_80561C80;
    f84 = lbl_80561C84;
    f88 = lbl_80561C88;
    f8C = lbl_80561C8C;
    f90 = lbl_80561C90;
    f4C = lbl_80561C4C;
    keyBase1 = lbl_802F9530;
    keyBase2 = lbl_802F9540;
    for (count = 0, table = lbl_804348D8; count < 4; count++, table++) {
        float value;
        float value2;
        v = (struct Di718 *)*table;
        if (v == 0) continue;
        v->axStackHead = __AXGetStackHead_80137CFC(v->index);
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
        value = f48;
        value = value < (v->pad60 - f48) ? value : (v->pad60 - f48);
        value = value > f4C ? value : f4C;
        value2 = f48;
        v->pad64 = value;
        value2 = value2 < v->pad60 ? value2 : v->pad60;
        value2 = value2 > f4C ? value2 : f4C;
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
                virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
                virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
                virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
                virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
                virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
                virtual void f20(); virtual int f21();
            };
            if (((Callback *)v)->f21() != 0) {
                v->pad60 = f4C;
            }
        }
#pragma pop
        fn_802E8524(v->flag5C, v->axStackHead);
        {
            register int *p1 = keyBase1;
            register int *p2 = keyBase2;
            keys1[0] = *p1++;
            keys1[1] = *p1++;
            keys1[2] = *p1++;
            keys1[3] = *p1;
            keys2[0] = *p2++;
            keys2[1] = *p2++;
            keys2[2] = *p2++;
            keys2[3] = *p2;
        }
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
}
#pragma pop
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
int fn_801813D8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_80181418(void *arg0, int arg1) {
    /* Reset a driver-interface sound slot: assign its value/id and clear its in-use flag. */
    ((struct DriverInterfaceSlot *)arg0)->value = arg1;
    ((struct DriverInterfaceSlot *)arg0)->inUse = 0;
}

extern void lbl_80331EFC(void);
#define s_baseDriverVTable lbl_80331EFC
/* Base DriverInterface constructor: store the address of the all-null base
 * vtable in *vtableSlot; fn_8018108C then overrides it with the real vtable,
 * lbl_80331E78. */
void fn_80181428(void **vtableSlot) {
    *vtableSlot = (void *)&s_baseDriverVTable;
}
#undef s_baseDriverVTable

void fn_80181438(void) {

}

void fn_8018143C(void) {

}

void fn_80181440(void) {

}

int fn_80181444(void *arg0) { return *(int *)((char *)arg0 + 0x34C); }

int fn_8018144C(void *arg0) { return *(int *)((char *)arg0 + 0x348); }

void GXInitLightAttnA_80181454(void *light, float a, float b, float c) {
    /* Set the three diffuse-attenuation coefficients a/b/c of the light object. */
    *(float *)((char *)light + 0x30C) = a;
    *(float *)((char *)light + 0x310) = b;
    *(float *)((char *)light + 0x314) = c;
}

void GXInitLightAttnK_80181464(void *light, float a, float b, float c) {
    /* Set the three specular-attenuation coefficients a/b/c of the light object. */
    *(float *)((char *)light + 0x318) = a;
    *(float *)((char *)light + 0x31C) = b;
    *(float *)((char *)light + 0x320) = c;
}

void fn_80181474(void *obj, float x, float y) {
    /* Set the two rumble-parameter floats at +0x324/+0x328 (read by fn_8017F628). */
    *(float *)((char *)obj + 0x324) = x;
    *(float *)((char *)obj + 0x328) = y;
}

/* Update the running minimum at +0x50 with value, always recording the latest value at +0x54. */
void fn_80181480(void *tracker, int value) {
 int minSoFar=*(int *)((char *)tracker+0x50);
 *(int *)((char *)tracker+0x54)=value;
 if(minSoFar>value) *(int *)((char *)tracker+0x50)=value;
}

#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma paired_single off
#pragma scheduling invalid_target
extern "C" float fn_80181498(void *arg0) {
    class Callback {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual int f21();
    };
    float a;
    float b;
    a = *(float *)((char *)arg0 + 0xC);
    a = (a > 1.0f) ? a : 1.0f;
    b = *(float *)((char *)arg0 + 0xC);
    b = (b < -1.0f) ? -1.0f : b;
    a = (a < (*(float *)((char *)arg0 + 0xC) + *(float *)((char *)arg0 + 0x10))) ? (*(float *)((char *)arg0 + 0xC) + *(float *)((char *)arg0 + 0x10)) : a;
    a = (a > b) ? b : a;
    float result = a;
    if (((Callback *)arg0)->f21() != 0) {
        result = *(float *)((char *)arg0 + 0xC);
    }
    return result;
}
#pragma pop
/* Return the sum of the two driver stats at +0x20 and +0x24, capped at 1.0. */
float fn_80181548(void *driver) {
#define MAX_STAT lbl_80561C48
    float sum = *(float *)((char *)driver + 0x20) + *(float *)((char *)driver + 0x24);
    if (sum < MAX_STAT) return sum;
    return MAX_STAT;
#undef MAX_STAT
}

/* Return the sum of the two driver stats at +0x14 and +0x18, capped at 1.0. */
float fn_80181568(void *driver) {
#define MAX_STAT lbl_80561C48
    float sum = *(float *)((char *)driver + 0x14) + *(float *)((char *)driver + 0x18);
    if (sum < MAX_STAT) return sum;
    return MAX_STAT;
#undef MAX_STAT
}

extern void fn_802E8518(void);
extern float lbl_80561C98;
extern float lbl_80561C9C;
/* Normalize the stat at +0x1C as (1.1 - 1.2 * value), then clamp to [0,1]
 * (lbl_80561C4C = 0.0f, lbl_80561C48 = 1.0f). */
float fn_80181588(void *arg0) {
    float scaled = lbl_80561C98 - lbl_80561C9C * *(float *)((char *)arg0 + 0x1C);
    float clamped = lbl_80561C4C;
    clamped = clamped > scaled ? clamped : scaled;
    if (lbl_80561C48 < clamped) return lbl_80561C48;
    return clamped;
}

float fn_801815C4(void *arg0) {
    return *(float *)((char *)arg0 + 0x28);
}

/* Return the integer field at offset 0x50 of this object (set by fn_801815D4). */
int fn_801815CC(void *object) {
    return *(int *)((char *)object + 0x50);
}

void fn_801815D4(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x50) = arg1;
}

/* Clamp a level to [0,1] and store it in the object's field at +0x20. */
void fn_801815DC(void *obj, float level) {
#define MAX_LEVEL lbl_80561C48  /* 1.0f */
#define MIN_LEVEL lbl_80561C4C  /* 0.0f */
    float clamped = MAX_LEVEL < level ? MAX_LEVEL : level;
    clamped = clamped > MIN_LEVEL ? clamped : MIN_LEVEL;
    *(float *)((char *)obj + 0x20) = clamped;
#undef MIN_LEVEL
#undef MAX_LEVEL
}

extern int fn_801A8E68(void *);
extern void fn_801797F8(int, int, int);
void fn_8018160C(void *arg0) {
    /* Poll input/state slots on this object and queue events through fn_801797F8
     * (using the id at +0x4) when fn_801A8E68 reports a triggered edge. */
    char *slotPtr;
    int slotIndex;
    if (fn_801A8E68((char *)arg0 + 0x25c)) fn_801797F8(*(int *)((char *)arg0 + 4), 2, 0);
    if (fn_801A8E68((char *)arg0 + 0x26c)) fn_801797F8(*(int *)((char *)arg0 + 4), 1, 0);
    if (fn_801A8E68((char *)arg0 + 0x27c)) fn_801797F8(*(int *)((char *)arg0 + 4), 3, 0);
    if (fn_801A8E68((char *)arg0 + 0x24c)) fn_801797F8(*(int *)((char *)arg0 + 4), 0, 0);
    for (slotPtr = (char *)arg0 + 0x2cc, slotIndex = 0; slotIndex < 4; slotIndex++, slotPtr += 0x10) {
        if (fn_801A8E68(slotPtr)) {
            fn_801797F8(*(int *)((char *)arg0 + 4), 4, slotIndex);
            break;
        }
    }
}

/* Store the control flag at +0x350; when it is cleared, recenter the steering
 * of the (non-negative) axis index kept at +0x8. */
void fn_80181700(void *self, int flag) {
    int stackHead;
    *(unsigned char *)((char *)self + 0x350) = flag;
    if (flag != 0) return;
    stackHead = *(int *)((char *)self + 8);
    if (stackHead < 0) return;
    ((void (*)(int))fn_802E8518)(stackHead);
}

/* Stop the sound/event on a slot when it is valid and its owner is not type 0x11. */
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

/* RealName: IsSubobjectActiveAt9C (tentative). Returns 1 if object has flag set at 0x340 or the subobject at offset 0x9C is active per fn_801A8EE4, else 0. */
int fn_801817B4(void *object) {
    int isActive = 0;

    if (*(unsigned char *)((char *)object + 0x340) != 0 || fn_801A8EE4((char *)object + 0x9C) != 0) {
        isActive = 1;
    }

    return isActive;
}

/* RealName: IsSubobjectActiveAt8C (tentative). Returns 1 if object has flag set at 0x340 or the subobject at offset 0x8C is active per fn_801A8EE4, else 0. */
int fn_80181800(void *object) {
    int isActive = 0;

    if (*(unsigned char *)((char *)object + 0x340) != 0 || fn_801A8EE4((char *)object + 0x8C) != 0) {
        isActive = 1;
    }

    return isActive;
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
