// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
__declspec(section ".sdata") extern char lbl_8055C178[];
__declspec(section ".sdata") extern char lbl_8055C180[];
__declspec(section ".sdata") extern char lbl_8055C188[];
__declspec(section ".sdata") extern char lbl_8055C198[];
__declspec(section ".sdata") extern char lbl_8055C1A0[];
__declspec(section ".sdata") extern char lbl_8055C1A8[];
__declspec(section ".sdata") extern char lbl_8055C1B0[];
__declspec(section ".sdata") extern char lbl_8055C1B8[];
extern void fn_80253824(void *);
extern s32 fn_80128668(void);
extern char lbl_80344B98[];
extern char lbl_80344BC0[];
extern void fn_80255200(void *, s32);
extern void fn_80015A20(void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern float fn_8023659C(void);

extern void *lbl_80498E08[];
extern s32 lbl_8055F33C;
extern s32 fn_8012D838(s32);
extern void fn_8012D8A8(s32);
extern int __cntlzw(unsigned int);
extern void fn_802E317C(const char *, ...);
extern void *memmove(void *, const void *, unsigned long);
extern char lbl_803449D4[];

#pragma always_inline on
static inline void removeDeadEntry(void) {
    void **cursor = lbl_80498E08;
    s32 index = 0;
    void **slot;
    for (; index < lbl_8055F33C; cursor++, index++) {
        if ((unsigned int)__cntlzw((unsigned int)fn_8012D838(*(s32 *)((u8 *)*cursor + 0x20))) >> 5) {
            slot = &lbl_80498E08[index];
            cursor = (void **)*slot;
            if (cursor != 0) {
                fn_8012D8A8(*(s32 *)((u8 *)cursor + 0x20));
                ((s32 (*)(void *))fn_80128668)(cursor);
            }
            lbl_8055F33C--;
            memmove(slot, slot + 1, (lbl_8055F33C - index) * 4);
            return;
        }
    }
    fn_802E317C(lbl_803449D4);
}
#pragma always_inline reset

static inline void mtx33_mult_vec(const float *m, const float *v, float *d) {
    float outX;
    float outY;
    float outZ;

    if (v == d) {
        float x = v[0];
        float y = v[1];
        float z = v[2];
        outX = (x * m[0] + y * m[3]) + z * m[6];
        outY = (x * m[1] + y * m[4]) + z * m[7];
        outZ = (x * m[2] + y * m[5]) + z * m[8];
    } else {
        outX = (v[0] * m[0] + v[1] * m[3]) + v[2] * m[6];
        outY = (v[0] * m[1] + v[1] * m[4]) + v[2] * m[7];
        outZ = (v[0] * m[2] + v[1] * m[5]) + v[2] * m[8];
    }
    d[0] = outX;
    d[1] = outY;
    d[2] = outZ;
}

#define AO(T, o) (*(T *)((char *)arg0 + (o)))
void fn_80253254(void) {}

#pragma push
#pragma scheduling on
void fn_80253258(void) {
    extern float lbl_80563A04, lbl_80563A08, lbl_80563A0C, lbl_80563A10;
    extern void PSVECNormalize(float *, float *);
    extern void fn_802C9A1C(float *);
    float v[6];
    v[0] = lbl_80563A04;
    v[1] = lbl_80563A08;
    v[2] = lbl_80563A0C;
    v[3] = v[0] * lbl_80563A10;
    v[4] = v[1] * lbl_80563A10;
    v[5] = v[2] * lbl_80563A10;
    PSVECNormalize(&v[3], &v[3]);
    fn_802C9A1C(&v[3]);
}
#pragma pop
void fn_802532BC(void *arg0) {
    struct Struct_802532BC_Offset28 {
        char pad[0x28];
        int val;
    };
    extern void *memset(void *, int, unsigned long);
    extern float lbl_80563A04;
    extern float lbl_80563A14;
    int len;

    *(unsigned char *)((char *)arg0 + 0x0) = 0;
    *(int *)((char *)arg0 + 0x14) = -1;
    *(int *)((char *)arg0 + 0x10) = -1;
    *(int *)((char *)arg0 + 0x1C) = 0;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(unsigned char *)((char *)arg0 + 0x400) = 0;
    memset((char *)arg0 + 0x28, 0, 0x3D8);

    {
        float zero = lbl_80563A04;
        float one = lbl_80563A14;

        ((struct Struct_802532BC_Offset28 *)arg0)->val = -1;
        len = 0x138;

        *(float *)((char *)arg0 + 0x598) = one;
        *(float *)((char *)arg0 + 0x59C) = zero;
        *(float *)((char *)arg0 + 0x5A0) = zero;
        *(float *)((char *)arg0 + 0x5A4) = zero;

        *(float *)((char *)arg0 + 0x5A8) = one;
        *(float *)((char *)arg0 + 0x5AC) = zero;
        *(float *)((char *)arg0 + 0x5B0) = zero;
        *(float *)((char *)arg0 + 0x5B4) = zero;

        *(float *)((char *)arg0 + 0x5B8) = one;
        *(float *)((char *)arg0 + 0x5BC) = zero;
        *(float *)((char *)arg0 + 0x5C0) = zero;
        *(float *)((char *)arg0 + 0x5C4) = zero;

        *(float *)((char *)arg0 + 0x5D8) = one;
        *(float *)((char *)arg0 + 0x5DC) = zero;
        *(float *)((char *)arg0 + 0x5E0) = zero;
        *(float *)((char *)arg0 + 0x5E4) = zero;

        *(float *)((char *)arg0 + 0x5E8) = one;
        *(float *)((char *)arg0 + 0x5EC) = zero;
        *(float *)((char *)arg0 + 0x5F0) = zero;
        *(float *)((char *)arg0 + 0x5F4) = zero;

        *(float *)((char *)arg0 + 0x5F8) = one;
        *(float *)((char *)arg0 + 0x5FC) = zero;
        *(float *)((char *)arg0 + 0x600) = zero;
        *(float *)((char *)arg0 + 0x604) = zero;

        *(float *)((char *)arg0 + 0x608) = one;
        *(float *)((char *)arg0 + 0x60C) = zero;
        *(float *)((char *)arg0 + 0x610) = zero;
        *(float *)((char *)arg0 + 0x614) = zero;

        *(float *)((char *)arg0 + 0x618) = one;
        *(float *)((char *)arg0 + 0x61C) = zero;
        *(float *)((char *)arg0 + 0x620) = zero;
        *(float *)((char *)arg0 + 0x624) = zero;

        *(float *)((char *)arg0 + 0x628) = one;
        *(float *)((char *)arg0 + 0x62C) = zero;
        *(float *)((char *)arg0 + 0x630) = zero;
        *(float *)((char *)arg0 + 0x634) = zero;

        *(float *)((char *)arg0 + 0x638) = one;
        *(float *)((char *)arg0 + 0x63C) = zero;
        *(float *)((char *)arg0 + 0x640) = zero;
        *(float *)((char *)arg0 + 0x644) = zero;

        *(float *)((char *)arg0 + 0x648) = one;
        *(float *)((char *)arg0 + 0x64C) = zero;
        *(float *)((char *)arg0 + 0x650) = zero;
        *(float *)((char *)arg0 + 0x654) = zero;

        *(float *)((char *)arg0 + 0x658) = one;
        *(float *)((char *)arg0 + 0x65C) = zero;
        *(float *)((char *)arg0 + 0x660) = zero;
        *(float *)((char *)arg0 + 0x664) = zero;

        *(float *)((char *)arg0 + 0x668) = one;
        *(float *)((char *)arg0 + 0x66C) = zero;
        *(float *)((char *)arg0 + 0x670) = zero;
        *(float *)((char *)arg0 + 0x674) = zero;

        *(float *)((char *)arg0 + 0x678) = one;
        *(float *)((char *)arg0 + 0x67C) = zero;
        *(float *)((char *)arg0 + 0x680) = zero;
        *(float *)((char *)arg0 + 0x684) = zero;

        *(float *)((char *)arg0 + 0x688) = one;
        *(float *)((char *)arg0 + 0x68C) = zero;
        *(float *)((char *)arg0 + 0x690) = zero;
        *(float *)((char *)arg0 + 0x694) = zero;

        *(float *)((char *)arg0 + 0x420) = zero;
        *(float *)((char *)arg0 + 0x424) = zero;
        *(float *)((char *)arg0 + 0x428) = zero;
    }

    memset((char *)arg0 + 0x45C, 0, len);

    *(float *)((char *)arg0 + 0x594) = lbl_80563A04;
}

void *fn_8025343C(void *arg0) {
    extern void fn_802532BC(void *);
    extern float fn_8023659C(void);
    extern int fn_801F0008(void);
    extern int fn_801284E8(char *, int);
    extern char lbl_803447C0[], lbl_803447CC[];
    fn_802532BC(arg0);
    *(float *)((u8 *)arg0 + 4) = fn_8023659C();
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0 + 0x20) = fn_801284E8(lbl_803447C0, fn_801F0008());
    *(s32 *)((u8 *)arg0 + 0x24) = fn_801284E8(lbl_803447CC, fn_801F0008());
    return arg0;
}

void *__dt__Q210JASDrumSet5TPercFv_802534B0(void *arg0, s32 arg1) {
    extern void fn_80128658(s32);
    if (arg0 != 0) {
        fn_80128658(*(s32 *)((u8 *)arg0 + 0x20));
        fn_80128658(*(s32 *)((u8 *)arg0 + 0x24));
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void fn_801345D8(void *, int, const char *, ...);
extern "C" int fn_802C6FC0(void *, int, int);
extern "C" void *fn_80131808(void *);
extern "C" int fn_801F0010(int, int);
extern "C" float fn_801F159C(int);
extern "C" void fn_80131818(void *, float, float, float);
extern "C" void fn_8027A714(void *, void *);
extern "C" void fn_80253890(void *, void *);
extern "C" char lbl_803447C0[];
extern "C" {
__declspec(section ".sdata") extern char lbl_8055C128[];
__declspec(section ".sdata") extern char lbl_8055C130[];
__declspec(section ".sdata") extern char lbl_8055C138[];
}
extern "C" float lbl_80563A10, lbl_80563A14, lbl_80563A18;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_80253510(void *arg0, unsigned char *arg1) {
    struct Stack {
        float sp8;
        float spC;
        float sp10;
        long pad14;
        unsigned char sp18[0x20];
        unsigned char sp38[0x100];
    } stack;
    struct Dummy {
                virtual Dummy *lookup(const char *);
        virtual void v3();
                virtual void v4();
        virtual int load(const char *);
    };
    register unsigned char temp_r3;
    register unsigned char *var_r4;
    register int var_r5;
    register unsigned char *var_r6;
    register char *labels;
    register char *format;
    register void *manager;
    register void *resource;
    register void *var_r30;
    register int var_r28;
    register int var_r0;
    register int var_r0_2;
    register int var_r3;
    register void *var_r4_2;
    register void *var_r5_2;
    register int var_r6_2;
    register int var_ctr;
    float temp_f1;
    float temp_f1_2;
    register float temp_f2;
    register float var_f2;
    register float temp_f3;
    register float var_f4;
    register float temp_f29;
    register float temp_f30;
    register float temp_f31;
    float var_f0;
    float var_f0_2;
    float var_f1;

    labels = lbl_803447C0;
    format = lbl_8055C128;
    fn_801345D8(stack.sp38, 0x100, format, arg1);
    var_r4 = arg1;
    var_r6 = (unsigned char *)arg0 + 0x400;
    var_r5 = 0x20;
    goto copy_body;
copy_limit:
    var_r5 -= 1;
    if (var_r5 > 0) goto copy_body;
    var_r6[-1] = 0;
    goto copy_done;
copy_body:
    temp_r3 = *var_r4;
    var_r4 += 1;
    *var_r6 = temp_r3;
    var_r6 += 1;
    if ((signed char)temp_r3 != 0) goto copy_limit;
copy_done:
    fn_801345D8(stack.sp18, 0x20, labels + 0x18, stack.sp38);
    *(int *)((unsigned char *)arg0 + 0x10) = fn_802C6FC0(stack.sp18, 0, (int)stack.sp38);
    fn_801345D8(stack.sp18, 0x20, labels + 0x24, stack.sp38);
    *(int *)((unsigned char *)arg0 + 0x14) = fn_802C6FC0(stack.sp18, 0, (int)stack.sp38);
    fn_801345D8(stack.sp18, 0x20, labels + 0x34, stack.sp38);
    manager = fn_80131808(stack.sp18);
    resource = ((Dummy *)manager)->lookup(lbl_8055C130);
    *(int *)((unsigned char *)arg0 + 0x18) =
        fn_801F0010(((Dummy *)resource)->load(labels + 0x44),
                    *(int *)((unsigned char *)arg0 + 0x20));
    resource = ((Dummy *)manager)->lookup(lbl_8055C138);
    *(int *)((unsigned char *)arg0 + 0x1C) =
        fn_801F0010(((Dummy *)resource)->load(labels + 0x44),
                    *(int *)((unsigned char *)arg0 + 0x24));
    fn_8027A714((unsigned char *)arg0 + 0x45C, arg1);

    var_r30 = arg0;
    var_r28 = 0;
    do {
        var_r0 = 0;
        if (var_r28 == 0) goto first_true;
        if (var_r28 != 1) goto first_done;
      first_true:
        var_r0 = 1;
      first_done:
        if (var_r0 != 0) var_f1 = fn_801F159C(*(int *)((unsigned char *)arg0 + 0x18));
        else var_f1 = fn_801F159C(*(int *)((unsigned char *)arg0 + 0x1C));
        var_r28 += 1;
        *(float *)((unsigned char *)var_r30 + 0x4F4) = var_f1;
        var_r30 = (unsigned char *)var_r30 + 0x24;
    } while (var_r28 < 4);

    temp_f3 = *(float *)((unsigned char *)arg0 + 0x588);
    temp_f2 = *(float *)((unsigned char *)arg0 + 0x58C);
    temp_f1 = *(float *)((unsigned char *)arg0 + 0x590);
    *(float *)((unsigned char *)arg0 + 0x420) = temp_f3;
    temp_f29 = *(float *)((unsigned char *)arg0 + 0x474);
    *(float *)((unsigned char *)arg0 + 0x424) = temp_f2;
    temp_f30 = *(float *)((unsigned char *)arg0 + 0x46C);
    *(float *)((unsigned char *)arg0 + 0x428) = temp_f1;
    temp_f31 = *(float *)((unsigned char *)arg0 + 0x470);
    *(float *)((unsigned char *)arg0 + 0x594) = *(float *)((unsigned char *)arg0 + 0x548);
    fn_80131818(manager, temp_f1, temp_f2, temp_f3);
    temp_f3 = lbl_80563A18;

    var_r4_2 = arg0;
    var_r5_2 = arg0;
    for (var_r6_2 = 0; var_r6_2 < 4; var_r6_2++) {
        var_r3 = 1;
        if (var_r6_2 == 0) goto axis_true;
        if (var_r6_2 != 2) var_r3 = 0;
      axis_true:
        var_r0_2 = 0;
        if (var_r6_2 == 0) goto side_true;
        if (var_r6_2 != 1) goto side_done;
      side_true:
        var_r0_2 = 1;
      side_done:
        if (var_r0_2 != 0) var_f4 = temp_f30;
        else var_f4 = temp_f31;
        if (var_r3 != 0) var_f0 = lbl_80563A10;
        else var_f0 = lbl_80563A14;
        var_f2 = temp_f3 * var_f0 * var_f4;
        stack.spC = *(float *)((unsigned char *)var_r4_2 + 0x4F4) -
                    *(float *)((unsigned char *)var_r4_2 + 0x4DC);
        stack.sp8 = var_f2;
        if (var_r0_2) var_f0_2 = lbl_80563A14;
        else var_f0_2 = lbl_80563A10;
        var_r4_2 = (unsigned char *)var_r4_2 + 0x24;
        *(float *)((unsigned char *)var_r5_2 + 0x42C) = stack.sp8;
        temp_f1_2 = temp_f29 * (temp_f3 * var_f0_2);
        *(float *)((unsigned char *)var_r5_2 + 0x434) = temp_f1_2;
        *(float *)((unsigned char *)var_r5_2 + 0x430) = stack.spC;
        var_r5_2 = (unsigned char *)var_r5_2 + 0xC;
        stack.sp10 = temp_f1_2;
    }
    fn_80253890(arg0, stack.sp38);
    *(signed char *)arg0 = 1;
}
#pragma pop
extern "C" void fn_802C6CF8(s32);
extern "C" void fn_801F0000(s32);
extern "C" void fn_80253C48(void *);
extern "C" void fn_802532BC(void *);
#pragma dont_inline on
extern "C" void fn_80253824(void *arg0) {
    if (*(u8 *)arg0 != 0) {
        *(u8 *)arg0 = 0;
        fn_802C6CF8(*(s32 *)((u8 *)arg0 + 0x10));
        fn_802C6CF8(*(s32 *)((u8 *)arg0 + 0x14));
        fn_801F0000(*(s32 *)((u8 *)arg0 + 0x18));
        fn_801F0000(*(s32 *)((u8 *)arg0 + 0x1C));
        fn_80253C48(arg0);
        fn_802532BC(arg0);
    }
}
#pragma dont_inline reset

extern "C" void *fn_80131810(void *);
extern "C" int fn_802C7830(void);
extern "C" int fn_801D2008(char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void *memset(void *, int, unsigned long);
extern "C" void fn_802E317C(const char *, ...);
__declspec(section ".sdata") extern char lbl_8055C150[], lbl_8055C158[], lbl_8055C160[], lbl_8055C168[], lbl_8055C16C[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80253890(void *arg0, void *arg1) {
    struct Keys { int v[4]; };
    extern struct Keys lbl_802FA5A8;
    extern float lbl_80563A04;
    struct Vec3 { float x, y, z; };
    struct Obj { char pad[0x3C]; Vec3 points[80]; };
    struct Res {
        virtual Res *get(const char *);
        virtual int has(const char *);
        virtual int exists(const char *);
        virtual const char *getString(const char *);
        virtual void v18();
        virtual int getInt(const char *);
        virtual void setKey(int, int);
        virtual void v24();
        virtual void v28();
        virtual void v2C();
        virtual void v30();
        virtual void v34();
        virtual Vec3 getVec(const char *, Vec3);
    };
    char cfgPath[0x100];
    Res *manager;
    Res *res;
    char *labels = lbl_803447C0;

    if (*(int *)((char *)arg0 + 0x28) != -1) return;
    fn_801345D8(cfgPath, 0x100, labels + 0x50, arg1);
    manager = (Res *)fn_80131810(cfgPath);
    if (manager == 0) {
        *(int *)((char *)arg0 + 0x34) = 0;
        *(int *)((char *)arg0 + 0x28) = -1;
        *(int *)((char *)arg0 + 0x3FC) = 0;
        return;
    }
    {
    char path[0x100] = {0};
    char buf[0x100];
    if (manager->exists(lbl_8055C150)) {
        res = manager->get(lbl_8055C150);
        sprintf(path, lbl_8055C158, arg1, res->getString(labels + 0x60));
        fn_801345D8(buf, 0x100, lbl_8055C158, arg1, res->getString(labels + 0x6C));
        *(int *)((char *)arg0 + 0x28) = fn_802C6FC0(buf, 0, (int)arg1);
        *(int *)((char *)arg0 + 0x2C) = res->getInt(labels + 0x78);
        *(int *)((char *)arg0 + 0x30) = res->getInt(labels + 0x84);
        *(int *)((char *)arg0 + 0x34) = res->getInt(labels + 0x90);
        if (res->has(labels + 0x9C)) {
            res->getString(labels + 0x9C);
            *(int *)((char *)arg0 + 0x38) = fn_802C7830();
        } else {
            *(int *)((char *)arg0 + 0x38) = -1;
        }
    } else {
        fn_802E317C(labels + 0xA8, cfgPath);
    }
    if (manager->exists(lbl_8055C160)) {
        Vec3 def;
        char name[0x20];
        int i;
        float zero = lbl_80563A04;
        def.x = zero;
        def.y = zero;
        def.z = zero;
        res = manager->get(lbl_8055C160);
        for (i = 0; i < *(int *)((char *)arg0 + 0x34); i++) {
            Vec3 d = def;
            fn_801345D8(name, 0x20, lbl_8055C168, i);
            ((Obj *)arg0)->points[i] = res->getVec(name, d);
        }
    } else {
        memset((char *)arg0 + 0x3C, 0x3C0, 0);
    }
    {
        Keys keys = lbl_802FA5A8;
        if (manager->exists(lbl_8055C16C)) {
            int i;
            res = manager->get(lbl_8055C16C);
            for (i = 0; i < 4; i++)
                res->setKey(keys.v[i], -1);
        }
    }
    ((void (*)(void *))fn_80131818)(manager);
    if (path[0] != 0) *(int *)((char *)arg0 + 0x3FC) = fn_801D2008(path);
    else *(int *)((char *)arg0 + 0x3FC) = 0;
    }
}
#pragma pop
#pragma cplusplus off

void fn_80253C48(void *arg0) {
    s32 temp = *(s32 *)((u8 *)arg0 + 0x28);
    if (temp != -1) {
        fn_802C6CF8(temp);
        *(s32 *)((u8 *)arg0 + 0x28) = -1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x3FC) != 0) {
        fn_801D21B4(*(s32 *)((u8 *)arg0 + 0x3FC));
        *(s32 *)((u8 *)arg0 + 0x3FC) = 0;
    }
}

void fn_80253CA4(void *arg0, void *arg1, float *arg2, void *arg3) {
    extern float lbl_80563A04, lbl_80563A10, lbl_80563A14, lbl_80563A1C;
    u8 *base = (u8 *)arg0;
    int *srcp = (int *)arg1;
    float *p2 = arg2;
    float *p3 = (float *)arg3;
    u8 *sca = base;
    u8 *vecp = base;
    u8 *outp = base;
    float t1[3];
    float res[3];
    int ibuf[12];
    float *buf = (float *)ibuf;
    int rot1[9];
    int rot2[9];
    float pin1[3];
    float pin2[3];
    float zero;
    float pi;
    int i;
    int r30;

    *(int *)(base + 0x598) = srcp[0];
    *(int *)(base + 0x59C) = srcp[1];
    *(int *)(base + 0x5A0) = srcp[2];
    *(int *)(base + 0x5A4) = srcp[3];
    *(int *)(base + 0x5A8) = srcp[4];
    *(int *)(base + 0x5AC) = srcp[5];
    *(int *)(base + 0x5B0) = srcp[6];
    *(int *)(base + 0x5B4) = srcp[7];
    *(int *)(base + 0x5B8) = srcp[8];
    *(int *)(base + 0x5BC) = srcp[9];
    *(int *)(base + 0x5C0) = srcp[10];
    *(int *)(base + 0x5C4) = srcp[11];
    mtx33_mult_vec((float *)(base + 0x598), (float *)(base + 0x420), t1);
    *(float *)(base + 0x5BC) = *(float *)(base + 0x5BC) + t1[0];
    *(float *)(base + 0x5C0) = *(float *)(base + 0x5C0) + t1[1];
    *(float *)(base + 0x5C4) = *(float *)(base + 0x5C4) + t1[2];

    zero = lbl_80563A04;
    pi = lbl_80563A1C;
    for (i = 0; i < 4; i++) {
        float s = *p2;
        *(float *)(sca + 0x5C8) = s;
        r30 = (i == 0 || i == 2) ? 1 : 0;
        ibuf[0] = srcp[0];
        ibuf[1] = srcp[1];
        ibuf[2] = srcp[2];
        ibuf[3] = srcp[3];
        ibuf[4] = srcp[4];
        ibuf[5] = srcp[5];
        ibuf[6] = srcp[6];
        ibuf[7] = srcp[7];
        ibuf[8] = srcp[8];
        ibuf[9] = srcp[9];
        ibuf[10] = srcp[10];
        ibuf[11] = srcp[11];
        mtx33_mult_vec(buf, (float *)(vecp + 0x42C), res);
        buf[9] = (buf[9] + res[0]) + buf[3] * s;
        buf[10] = (buf[10] + res[1]) + buf[4] * s;
        buf[11] = (buf[11] + res[2]) + buf[5] * s;
        if (r30 == 0) {
            pin2[0] = zero;
            pin2[1] = pi;
            pin2[2] = zero;
            fn_80015A20(rot1, pin2);
            fn_80015B20(buf, rot1, buf);
        }
        if (r30 != 0) {
            pin1[0] = *p3 * lbl_80563A14;
        } else {
            pin1[0] = *p3 * lbl_80563A10;
        }
        pin1[1] = zero;
        pin1[2] = zero;
        fn_80015A20(rot2, pin1);
        fn_80015B20(buf, rot2, buf);
        *(int *)(outp + 0x5D8) = ibuf[0];
        *(int *)(outp + 0x5DC) = ibuf[1];
        *(int *)(outp + 0x5E0) = ibuf[2];
        *(int *)(outp + 0x5E4) = ibuf[3];
        *(int *)(outp + 0x5E8) = ibuf[4];
        *(int *)(outp + 0x5EC) = ibuf[5];
        *(int *)(outp + 0x5F0) = ibuf[6];
        *(int *)(outp + 0x5F4) = ibuf[7];
        *(int *)(outp + 0x5F8) = ibuf[8];
        *(int *)(outp + 0x5FC) = ibuf[9];
        *(int *)(outp + 0x600) = ibuf[10];
        *(int *)(outp + 0x604) = ibuf[11];
        p2 += 1;
        sca += 4;
        vecp += 0xC;
        p3 += 1;
        outp += 0x30;
    }
}

void fn_8025419C(void *arg0) {
 extern float fn_8023659C(void); extern s32 fn_80147C50(s32,s32,float);
 extern void fn_8018BF44(s32 *); extern void fn_801F1394(s32,void *);
 extern void fn_802C70AC(s32,void *,s32,s32); extern s32 fn_802C7A40(s32,void *,s32,s32,s32 *,s32);
 extern void *memset(void *,int,unsigned long); extern void fn_802543FC(void *);
 extern float lbl_80563A04,lbl_80563A10,lbl_80563A14,lbl_80563A20,lbl_80563A24,lbl_80563A28;
 unsigned char sp10[0x3C0]; s32 spC,sp8; register float var_f4;
 float temp_f0,temp_f2,var_f1; s32 var_r31,var_r30,temp_r6,var_r0;
 memset(sp10,0,0x3C0); temp_f0=fn_8023659C(); var_f4=lbl_80563A14;
 temp_f0=((temp_f0-*(float *)((u8 *)arg0+4))-lbl_80563A04)/lbl_80563A20;
 if(var_f4<temp_f0)var_f4=temp_f0; if(var_f4>lbl_80563A04)var_f4=lbl_80563A04;
 var_f1=lbl_80563A10; temp_f2=lbl_80563A04+(var_f4*lbl_80563A14);
 if(!(temp_f2<var_f1)){} else if(temp_f2>lbl_80563A14)var_f1=lbl_80563A14;
 else if(temp_f2>lbl_80563A04) {
  var_f1=lbl_80563A24*temp_f2; temp_f0=lbl_80563A28*temp_f2;
  var_f1=var_f1*temp_f2; temp_f0=temp_f0*temp_f2; var_f1=temp_f2*var_f1; var_f1=var_f1+temp_f0;
 } else {
  var_f1=lbl_80563A24*temp_f2; temp_f0=lbl_80563A28*temp_f2;
  var_f1=var_f1*temp_f2; temp_f0=temp_f0*temp_f2; var_f1=temp_f2*var_f1; var_f1=var_f1-temp_f0;
 }
 spC=fn_80147C50(*(s32 *)((u8 *)arg0+0xC),*(s32 *)((u8 *)arg0+8),var_f1);
 var_r31=fn_802C7A40(1,sp10,0x50,1,&spC,1); fn_8018BF44(&sp8);
 temp_r6=sp8|0x10000000; sp8=temp_r6; fn_802C70AC(*(s32 *)((u8 *)arg0+0x10),(u8 *)arg0+0x598,var_r31,temp_r6);
 var_r31=(s32)((u8 *)arg0+0x5D8); var_r30=0;
 do { var_r0=0; if(var_r30!=0){if(var_r30==1)var_r0=1;}
  if(var_r0)fn_801F1394(*(s32 *)((u8 *)arg0+0x18),(void *)var_r31);
  else fn_801F1394(*(s32 *)((u8 *)arg0+0x1C),(void *)var_r31);
  var_r30++;var_r31+=0x30;
 }while(var_r30<4);
 fn_802543FC(arg0);
}

extern void fn_802C7AE0(s32, void *, s32, float);
#pragma scheduling invalid_target
void fn_80254354(void *arg0) {
    #pragma scheduling on
    extern float lbl_80563A2C;
    u8 *p;
    s32 i;
    s32 var_r0;
    float initial = lbl_80563A2C;
    fn_802C7AE0(*(s32 *)((u8 *)arg0 + 0x14), (u8 *)arg0 + 0x598, -1, initial);
    p = (u8 *)arg0 + 0x5D8;
    i = 0;
    do {
        var_r0 = 0;
        if (i == 0) goto set_result;
        if (i != 1) goto result_done;
      set_result:
        var_r0 = 1;
      result_done:
        if (var_r0 != 0)
            fn_801F1474(*(s32 *)((u8 *)arg0 + 0x18), p, lbl_80563A2C);
        else
            fn_801F1474(*(s32 *)((u8 *)arg0 + 0x1C), p, lbl_80563A2C);
        i++;
        p += 0x30;
    } while (i < 4);
}
#pragma scheduling on
void fn_802543FC(void *arg0) {
    extern void *fn_802C86DC(void);
    extern s32 fn_802C7A34(s32, void *, s32);
    extern void fn_802C70AC(s32, void *, s32, s32);
    extern float lbl_80563A04;
    extern float lbl_80563A10;
    u8 *base = (u8 *)arg0;
    u8 *vertices = base + 0x598;
    void *v;
    void *p;
    union { s32 i; float f; } c, b, a;
    s32 index;
    u8 *point;
    float difference;
    float zero;
    float scale;

    if (*(s32 *)(base + 0x28) != -1) {
        v = fn_802C86DC();
        a.i = *(s32 *)((u8 *)v + 0);
        b.i = *(s32 *)((u8 *)v + 4);
        c.i = *(s32 *)((u8 *)v + 8);
        point = base + *(s32 *)(base + 0x2C) * 12;
        *(float *)(point + 0x3C) = a.f;
        *(float *)(point + 0x40) = b.f;
        *(float *)(point + 0x44) = c.f;
        scale = lbl_80563A10;
        point = base + *(s32 *)(base + 0x30) * 12;
        *(float *)(point + 0x3C) = a.f * scale;
        *(float *)(point + 0x40) = b.f * scale;
        *(float *)(point + 0x44) = c.f * scale;
        p = *(void **)(base + 0x3FC);
        if (p != 0) {
            zero = lbl_80563A04;
            index = *(s32 *)((u8 *)p + 0xCC);
            difference = *(float *)(base + 0x5C8);
            difference -= *(float *)(base + 0x424);
            point = base + index * 12;
            *(float *)(point + 0x3C) = zero;
            *(float *)(point + 0x40) = difference;
            *(float *)(point + 0x44) = zero;
            index = *(s32 *)((u8 *)p + 0xD0);
            difference = *(float *)(base + 0x5CC);
            difference -= *(float *)(base + 0x424);
            point = base + index * 12;
            *(float *)(point + 0x3C) = zero;
            *(float *)(point + 0x40) = difference;
            *(float *)(point + 0x44) = zero;
            index = *(s32 *)((u8 *)p + 0xD4);
            difference = *(float *)(base + 0x5D0);
            difference -= *(float *)(base + 0x424);
            point = base + index * 12;
            *(float *)(point + 0x3C) = zero;
            *(float *)(point + 0x40) = difference;
            *(float *)(point + 0x44) = zero;
            index = *(s32 *)((u8 *)p + 0xD8);
            difference = *(float *)(base + 0x5D4);
            difference -= *(float *)(base + 0x424);
            point = base + index * 12;
            *(float *)(point + 0x3C) = zero;
            *(float *)(point + 0x40) = difference;
            *(float *)(point + 0x44) = zero;
        }
        index = fn_802C7A34(1, base + 0x48, *(s32 *)(base + 0x34));
        fn_802C70AC(*(s32 *)(base + 0x28), vertices, index, *(s32 *)(base + 0x38));
    }
}
#pragma scheduling on

void fn_80254568(void *arg0, s32 arg1, const char *arg2) {
    struct Result {
        s32 x;
        s32 y;
        s32 z;
    };
    void *sp8 = 0;
    struct Result *result;
    fn_801E2CCC(arg1, arg2, &sp8);
    result = (struct Result *)((u8 *)sp8 + 0x24);
    *(struct Result *)arg0 = *result;
}

#pragma dont_inline on
void fn_802545C4(void *arg0, s32 arg1, s32 arg2) {
    extern void *memset(void *, int, unsigned long);
    extern void PSVECCrossProduct(float *, float *, float *);
    extern void PSVECNormalize(float *, float *);
    extern float fn_801F159C(s32);
    extern float lbl_80498E18[3];
    extern float lbl_80563A04, lbl_80563A14, lbl_80563A18;
    extern float lbl_80563A30, lbl_80563A34, lbl_80563A38, lbl_80563A3C;
    extern char lbl_8055C178[], lbl_8055C180[], lbl_8055C188[];
    extern void fn_80254568(void *, s32, const char *);
    struct Stack {
        float sp8[3];
        float sp14[3];
        float sp20[3];
        float sp2c[3];
    } stack;
    memset(arg0, 0, 0x78);
    *(u8 *)((char *)arg0 + 0x30) = 1;
    if (*(u8 *)(char *)arg2 != 0) {
        *(float *)((char *)arg0 + 0x40) = *(float *)((char *)arg2 + 0x58C);
        if (arg1 != -1)
            *(float *)((char *)arg0 + 0x40) =
                *(float *)((char *)arg0 + 0x40) - lbl_80563A30;
        *(float *)((char *)arg0 + 0x44) = *(float *)((char *)arg2 + 0x58C);
        if (arg1 != -1)
            *(float *)((char *)arg0 + 0x44) =
                *(float *)((char *)arg0 + 0x44) - lbl_80563A30;
        *(float *)((char *)arg0 + 0x48) = *(float *)((char *)arg2 + 0x58C);
        if (arg1 != -1)
            *(float *)((char *)arg0 + 0x48) =
                *(float *)((char *)arg0 + 0x48) - lbl_80563A30;
        *(float *)((char *)arg0 + 0x4C) = *(float *)((char *)arg2 + 0x58C);
        if (arg1 != -1)
            *(float *)((char *)arg0 + 0x4C) =
                *(float *)((char *)arg0 + 0x4C) - lbl_80563A30;
    }
    if (arg1 != -1) {
        fn_80254568(stack.sp2c, arg1, lbl_8055C178);
        fn_80254568(stack.sp20, arg1, lbl_8055C180);
        fn_80254568(stack.sp14, arg1, lbl_8055C188);
        stack.sp8[0] = stack.sp20[0] +
            lbl_80563A18 * (stack.sp2c[0] - stack.sp20[0]);
        stack.sp8[1] = stack.sp20[1] +
            lbl_80563A18 * (stack.sp2c[1] - stack.sp20[1]);
        stack.sp8[2] = stack.sp20[2] +
            lbl_80563A18 * (stack.sp2c[2] - stack.sp20[2]);
        *(float *)((char *)arg0 + 0x18) = stack.sp8[0] - stack.sp14[0];
        *(float *)((char *)arg0 + 0x1C) = stack.sp8[1] - stack.sp14[1];
        *(float *)((char *)arg0 + 0x20) = stack.sp8[2] - stack.sp14[2];
        *(float *)arg0 = stack.sp2c[0] - stack.sp20[0];
        *(float *)((char *)arg0 + 4) = stack.sp2c[1] - stack.sp20[1];
        *(float *)((char *)arg0 + 8) = stack.sp2c[2] - stack.sp20[2];
        PSVECCrossProduct((float *)((char *)arg0 + 0x18), (float *)arg0,
                          (float *)((char *)arg0 + 0xC));
        PSVECCrossProduct((float *)((char *)arg0 + 0xC),
                          (float *)((char *)arg0 + 0x18), (float *)arg0);
        PSVECNormalize((float *)arg0, (float *)arg0);
        PSVECNormalize((float *)((char *)arg0 + 0xC),
                       (float *)((char *)arg0 + 0xC));
        PSVECNormalize((float *)((char *)arg0 + 0x18),
                       (float *)((char *)arg0 + 0x18));
        lbl_80498E18[0] =
            stack.sp8[0] + *(float *)((char *)arg0 + 0x18) * lbl_80563A34;
        lbl_80498E18[1] =
            stack.sp8[1] + *(float *)((char *)arg0 + 0x1C) * lbl_80563A34;
        lbl_80498E18[2] =
            stack.sp8[2] + *(float *)((char *)arg0 + 0x20) * lbl_80563A34;
        lbl_80498E18[0] += *(float *)((char *)arg0 + 0xC) * lbl_80563A38;
        lbl_80498E18[1] += *(float *)((char *)arg0 + 0x10) * lbl_80563A38;
        lbl_80498E18[2] += *(float *)((char *)arg0 + 0x14) * lbl_80563A38;
        if (*(u8 *)(char *)arg2 != 0) {
            float distance = fn_801F159C(*(s32 *)((char *)arg2 + 0x18));
            float scale = -(lbl_80563A3C + *(float *)((char *)arg2 + 0x440));
            float lateral = lbl_80563A04 +
                (-*(float *)((char *)arg0 + 0x44) +
                 (-*(float *)((char *)arg2 + 0x43C) + distance));
            *(float *)((char *)arg0 + 0x24) =
                stack.sp8[0] + *(float *)((char *)arg0 + 0x18) * scale;
            *(float *)((char *)arg0 + 0x28) =
                stack.sp8[1] + *(float *)((char *)arg0 + 0x1C) * scale;
            *(float *)((char *)arg0 + 0x2C) =
                stack.sp8[2] + *(float *)((char *)arg0 + 0x20) * scale;
            *(float *)((char *)arg0 + 0x24) +=
                *(float *)((char *)arg0 + 0xC) * lateral;
            *(float *)((char *)arg0 + 0x28) +=
                *(float *)((char *)arg0 + 0x10) * lateral;
            *(float *)((char *)arg0 + 0x2C) +=
                *(float *)((char *)arg0 + 0x14) * lateral;
        } else {
            *(float *)((char *)arg0 + 0x24) = lbl_80498E18[0];
            *(float *)((char *)arg0 + 0x28) = lbl_80498E18[1];
            *(float *)((char *)arg0 + 0x2C) = lbl_80498E18[2];
        }
    } else {
        *(float *)((char *)arg0 + 4) = lbl_80563A04;
        *(float *)arg0 = lbl_80563A14;
        *(float *)((char *)arg0 + 8) = lbl_80563A04;
        *(float *)((char *)arg0 + 0xC) = lbl_80563A04;
        *(float *)((char *)arg0 + 0x10) = lbl_80563A14;
        *(float *)((char *)arg0 + 0x14) = lbl_80563A04;
        *(float *)((char *)arg0 + 0x18) = lbl_80563A04;
        *(float *)((char *)arg0 + 0x1C) = lbl_80563A04;
        *(float *)((char *)arg0 + 0x20) = lbl_80563A14;
        *(float *)((char *)arg0 + 0x24) = lbl_80563A04;
        *(float *)((char *)arg0 + 0x28) = lbl_80563A04;
        *(float *)((char *)arg0 + 0x2C) = lbl_80563A04;
    }
}
#pragma push
#pragma scheduling invalid_target
void fn_80255200(void *arg0, s32 arg1) {
    extern float lbl_80563A04, lbl_80563A14, lbl_80563A58, lbl_80563A5C;
    extern char lbl_803447C0[];
    extern void *lbl_80498E08[];
    extern long lbl_8055C190;
    extern s32 lbl_8055F33C;
    extern void fn_8025539C(void *, s32);
    extern void *fn_802CAC28(void *, s32);
    extern void *fn_801284F8(s32, void *);
    extern void *fn_8012CAA0(s32, void *);
    extern void fn_80255A84(void *);
    float three, one, two, zero;
    u8 *p = (u8 *)arg0;
    char *strings;
    void *obj;
    s32 n;

    zero = lbl_80563A04; one = lbl_80563A14; two = lbl_80563A58; three = lbl_80563A5C;
    strings = lbl_803447C0;
    *(u8 *)(p + 0x118) = 0;
    *(float *)(p + 0x11C) = zero;
    *(u8 *)(p + 0xDD) = 0;
    *(u8 *)(p + 0xDC) = 0;
    *(u8 *)(p + 0x30) = 0;
    *(float *)(p + 0x98) = two;
    *(float *)(p + 0xA8) = one;
    *(float *)(p + 0xAC) = zero;
    *(float *)(p + 0xB0) = zero;
    *(float *)(p + 0xB4) = zero;
    *(float *)(p + 0xB8) = one;
    *(float *)(p + 0xBC) = zero;
    *(float *)(p + 0xC0) = zero;
    *(float *)(p + 0xC4) = zero;
    *(float *)(p + 0xC8) = one;
    *(float *)(p + 0xCC) = zero;
    *(float *)(p + 0xD0) = zero;
    *(float *)(p + 0xD4) = zero;
    *(s32 *)(p + 0xD8) = -1;
    *(float *)(p + 0xEC) = three;
    *(float *)(p + 0xF0) = zero;
    *(float *)(p + 0xF4) = zero;
    *(float *)(p + 0xF8) = zero;
    *(u8 *)(p + 0x10) = 0;
    *(u8 *)(p + 0x38) = 0;
    *(u8 *)(p + 0x58) = 0;
    *(u8 *)(p + 0x78) = 0;
    *(unsigned int *)(p + 0xC) = 0xFF000000;
    if (arg1 != 0) fn_8025539C(arg0, arg1);
    *(void **)(p + 0xE8) = fn_802CAC28(strings + 0x100, 0);
    obj = fn_801284F8(0x28, strings + 0x110);
    if (obj) *(void **)((u8 *)obj + 0x20) = fn_8012CAA0(0x16E360, strings + 0x11C);
    n = lbl_8055F33C; lbl_80498E08[n] = obj; lbl_8055F33C = n + 1;
    obj = fn_801284F8(0x28, strings + 0x110);
    if (obj) *(void **)((u8 *)obj + 0x20) = fn_8012CAA0(0x16E360, strings + 0x11C);
    n = lbl_8055F33C; lbl_80498E08[n] = obj; lbl_8055F33C = n + 1;
    obj = fn_801284F8(0x698, &lbl_8055C190);
    if (obj) *(void **)(p + 8) = ((void *(*)(void))fn_8025343C)();
    fn_80255A84(arg0);
}

#pragma cplusplus on
extern "C" int fn_8012C33C(void *);
extern "C" void fn_802E30C8(void *, ...);
extern "C" void fn_8025539C(void *, s32);
void fn_8025539C(void *arg0, s32 arg1) {
    extern float lbl_80563A04;
    extern float lbl_80563A5C;
    struct Factory {
        virtual void *get(s32);
        virtual void pad();
        virtual int test(s32);
    };
    struct Query {
        virtual void *pad08();
        virtual void *pad0C();
        virtual void *pad10();
        virtual void *pad14();
        virtual void *pad18();
        virtual void *pad1C();
        virtual void *pad20();
        virtual void *pad24();
        virtual float value(const char *, float);
        virtual void *pad2C();
        virtual void *pad30();
        virtual void *pad34();
        virtual void fill();
        virtual void *pad3C();
        virtual void *pad40();
        virtual void *pad44();
        virtual void *pad48();
        virtual void *pad4C();
        virtual void *pad50();
        virtual void *pad54();
        virtual void *pad58();
        virtual void *find(const char *);
    };
    struct Vec3 { float x, y, z; };
    void *manager;
    char *strings;
    void *obj;
    void *result;
    float value;
    register float *stats;
    register float *inputPtr;
    float output[3];
    struct Vec3 input, initial;

    strings = lbl_803447C0;
    manager = strings + 0x128;
    if (fn_8012C33C(manager) != 0) {
        obj = fn_80131808(manager);
        if (((Factory *)obj)->test(arg1) != 0) {
            result = ((Factory *)obj)->get(arg1);
            value = ((Query *)result)->value(strings + 0x134, lbl_80563A5C);
            initial.x = lbl_80563A04;
            initial.y = lbl_80563A04;
            initial.z = lbl_80563A04;
            inputPtr = &input.x;
            *(float *)((char *)arg0 + 0xEC) = value;
            ((int *)&input)[0] = ((int *)&initial)[0];
            ((int *)&input)[1] = ((int *)&initial)[1];
            ((int *)&input)[2] = ((int *)&initial)[2];
            ((void (*)(float *, void *, const char *, float *, unsigned int, unsigned int))(*(void ***)result)[14])
                (output, result, strings + 0x140, inputPtr,
                 *(unsigned int *)&initial.y, *(unsigned int *)&initial.x);
            *(float *)((char *)arg0 + 0xF0) = output[0];
            *(float *)((char *)arg0 + 0xF4) = output[1];
            *(float *)((char *)arg0 + 0xF8) = output[2];
            arg1 = (s32)((Query *)result)->find(lbl_8055C198);
            if (arg1 != 0) {
                stats = (float *)(strings + 0xD0);
                stats[1] = ((Query *)(void *)arg1)->value(lbl_8055C1A0, lbl_80563A04);
                stats[2] = ((Query *)(void *)arg1)->value(strings + 0x150, lbl_80563A04);
                stats[4] = ((Query *)(void *)arg1)->value(lbl_8055C1A8, lbl_80563A04);
                stats[5] = ((Query *)(void *)arg1)->value(strings + 0x15C, lbl_80563A04);
                stats[7] = ((Query *)(void *)arg1)->value(lbl_8055C1B0, lbl_80563A04);
                stats[8] = ((Query *)(void *)arg1)->value(strings + 0x168, lbl_80563A04);
                stats[10] = ((Query *)(void *)arg1)->value(lbl_8055C1B8, lbl_80563A04);
                stats[11] = ((Query *)(void *)arg1)->value(strings + 0x174, lbl_80563A04);
            }
        } else {
            fn_802E30C8(strings + 0x180, arg1, manager);
        }
        ((void (*)(void *))fn_80131818)(obj);
    } else {
        fn_802E30C8(strings + 0x1B8, manager);
    }
}
#pragma cplusplus off
void fn_80255604(s32 arg0) {
    extern char lbl_803447C0[];
    extern u8 lbl_8055F330;
    fn_8012E81C(lbl_803447C0 + 0x1E0);
    fn_8012E81C(lbl_803447C0 + 0x1F0);
    fn_8012E81C(lbl_803447C0 + 0x1FC);
    fn_8012E96C(lbl_803447C0 + 0x208);
    fn_80203C50(arg0 != 0);
    fn_801EFF4C();
    lbl_8055F330 = 0;
    fn_802AB9E8();
}

void fn_8025567C(void) {
    extern u8 lbl_8055F330;
    if (lbl_8055F330 != 0) {
        fn_802AE9D0();
        fn_80252BC8();
    }
    fn_802ABC2C();
    fn_801EFF70();
    fn_80203DC8();
    fn_802C7A00();
}

void *fn_802556BC(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x120) = arg1;
    *(void **)arg0 = lbl_80344B98;
    *(void **)((u8 *)arg0 + 0xFC) = lbl_80344BC0;
    *(s32 *)((u8 *)arg0 + 0x110) = 0;
    *(u8 *)((u8 *)arg0 + 0x114) = 0;
    fn_80255200(arg0, 0);
    return arg0;
}

s32 fn_80255718(s32 arg0, s32 arg1) {
    extern s32 fn_80128668(void);
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma use_lmw_stmw off
void *fn_80255758(void *arg0, s32 arg1, s32 arg2) {
    extern char lbl_80344B98[]; extern char lbl_803449D4[];
    extern void *lbl_80498E08[]; extern s32 lbl_8055F33C;
    extern void fn_80255B5C(void *);
    extern void fn_802CAC54(s32);
    extern s32 fn_8012D838(s32); extern void fn_8012D8A8(s32);
    extern int __cntlzw(unsigned int);
    extern void *memmove(void *, const void *, unsigned long);
    extern void fn_802E317C(const char *, ...);
    void **slot;
    register void *obj;
    s32 index;
    u8 *cursor;
    (void)arg2;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80344B98;
        fn_80255B5C(arg0);
        ((void *(*)(void *, s32))__dt__Q210JASDrumSet5TPercFv_802534B0)(*(void **)((u8 *)arg0 + 8), 1);
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0xE8));

        cursor = (u8 *)lbl_80498E08;
        index = 0;
        while (lbl_8055F33C > index) {
            if (((unsigned int)__cntlzw((unsigned int)fn_8012D838(*(s32 *)((u8 *)*(void **)cursor + 0x20))) >> 5)) {
                slot = &lbl_80498E08[index];
                obj = *slot;
                if (obj) {
                    fn_8012D8A8(*(s32 *)((u8 *)obj + 0x20));
                    ((s32 (*)(void *))fn_80128668)(obj);
                }
                lbl_8055F33C--;
                memmove(slot, slot + 1, (lbl_8055F33C - index) * 4);
                goto second_pass;
            }
            cursor += 4;
            ++index;
        }
        fn_802E317C(lbl_803449D4);

    second_pass:
        cursor = (u8 *)lbl_80498E08;
        index = 0;
        while (index < lbl_8055F33C) {
            if (((unsigned int)__cntlzw((unsigned int)fn_8012D838(*(s32 *)((u8 *)*(void **)cursor + 0x20))) >> 5)) {
                slot = &lbl_80498E08[index];
                obj = *slot;
                if (obj) {
                    fn_8012D8A8(*(s32 *)((u8 *)obj + 0x20));
                    ((s32 (*)(void *))fn_80128668)(obj);
                }
                lbl_8055F33C -= 1;
                memmove(slot, slot + 1, (lbl_8055F33C - index) * 4);
                goto finish;
            }
            index += 1;
            cursor += 4;
        }
        fn_802E317C(lbl_803449D4);

    finish:
        if (0 < arg1) {
            ((s32 (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}
#pragma use_lmw_stmw reset

void fn_80255904(void *arg0) {
    extern void fn_80253824(void *);
    fn_80253824(*(void **)((u8 *)arg0 + 8));
}

u8 fn_8025590C(void *arg0) {
    return **(u8 **)((u8 *)arg0 + 8);
}

void fn_80255918(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xC) = arg1;
}

void fn_80255920(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x118) = arg1;
}

__declspec(section ".sdata") extern char lbl_8055C1C0[];
__declspec(section ".sdata") extern float lbl_80563A60;
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80255928(void *arg0, char *arg1) {
    typedef struct {
        char pad0[0x58];
        char name[1];
    } Obj;
    extern void *lbl_80498E08[];
    extern s32 lbl_8055F33C;
    extern void fn_8012D3D8(s32);
    extern int stricmp(const char *, const char *);
    Obj *obj;
    register void *object;
    register s32 i;
    register void **entries;

    obj = (Obj *)arg0;
    if (obj->name[0] != 0) {
        entries = lbl_80498E08;
        i = 0;
        goto scan_test;
    scan:
        if (stricmp((char *)*entries, obj->name) == 0) {
            object = lbl_80498E08[i];
            {
                char ch;
                char *src;
                s32 count;
                char *dst;
                dst = (char *)object;
                if (--*(s32 *)((u8 *)object + 0x24) == 0) {
                    fn_8012D3D8(*(s32 *)((u8 *)object + 0x20));
                    src = lbl_8055C1C0;
                    count = 0x20;
                    goto name_copy;
                name_check:
                    if (--count > 0) goto name_copy;
                    dst[-1] = 0;
                    goto name_end;
                name_copy:
                    ch = *src++;
                    *dst++ = ch;
                    if ((s8)ch == 0) goto name_end;
                    goto name_check;
                name_end:
                    ;
                }
            }
        } else {
            entries++;
            i++;
        scan_test:
            if (i < lbl_8055F33C) goto scan;
        }
        obj->name[0] = 0;
    }
    {
        char *src;
        char ch;
        s32 count;
        char *dst;
        dst = (char *)obj + 0x10;
        src = arg1;
        count = 0x20;
        goto arg_copy;
    arg_check:
        if (--count > 0) goto arg_copy;
        dst[-1] = 0;
        goto arg_end;
    arg_copy:
        ch = *src++;
        *dst++ = ch;
        if (ch != 0) goto arg_check;
    arg_end:
        ;
    }
    *((u8 *)obj + 0x30) = 1;
    if (*((s8 *)obj + 0x78) != 0) {
        *(float *)((u8 *)obj + 0x34) = fn_8023659C();
    } else {
        *(float *)((u8 *)obj + 0x34) = lbl_80563A60;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset

void fn_80255A7C(void) {
}

void fn_80255A80(void) {
}

__declspec(section ".sdata") extern s32 lbl_8055F340;
__declspec(section ".sdata") extern u8 lbl_8055F330;
__declspec(section ".sdata") extern float lbl_80563A64, lbl_80563A68, lbl_80563A6C, lbl_80563A70;
__declspec(section ".sdata") extern char lbl_8055C1C8[];
extern char lbl_80344A48[];
__declspec(section ".data") extern void *lbl_80498E28[];
extern void fn_80255604(s32);
extern void fn_80252BF0(void);
extern void fn_80252F50(float);
extern s32 fn_802C6FC0(void *, s32, s32);
#pragma dont_inline on
void fn_80255A84(void *arg0) {
    if (lbl_8055F340 == 0) {
        fn_80255604(*(s32 *)((char *)arg0 + 0x120));
    }
    if (lbl_8055F330 != 0) {
        fn_80252BF0();
        fn_80252F50(lbl_80563A64);
        *(s32 *)((char *)arg0 + 0xE4) = fn_802C6FC0(lbl_8055C1C8, 0, 0);
    } else {
        *(s32 *)((char *)arg0 + 0xE4) = -1;
        if (*(s32 *)((char *)arg0 + 0x120) == 0) {
            *(s32 *)((char *)arg0 + 0xE4) = fn_802C6FC0(lbl_80344A48, 0, 0);
        }
    }
    *(s32 *)((char *)arg0 + 4) = lbl_8055F340;
    {
        float t3 = lbl_80563A70;
        float t2 = lbl_80563A6C;
        float t1 = lbl_80563A68;
        lbl_8055F340++;
        lbl_80498E28[*(s32 *)((char *)arg0 + 4)] = arg0;
        *(float *)((char *)arg0 + 0x9C) = t1;
        *(float *)((char *)arg0 + 0xA0) = t2;
        *(float *)((char *)arg0 + 0xA4) = t3;
    }
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80255B5C(void *arg0) {
    typedef struct {
        char name[0x20];
        s32 id;
        s32 refCount;
    } StringEntry;
    typedef struct { char pad0[0x78]; char name78[1]; } Obj78;
    typedef struct { char pad0[0x58]; char name58[1]; } Obj58;
    extern s32 lbl_8055F33C;
    extern void *lbl_80498E08[];
    extern void fn_8012D3D8(s32);
    Obj78 *obj78 = (Obj78 *)arg0;
    extern void fn_80252C78(void);
    extern int stricmp(const char *, const char *);
    Obj58 *obj58 = (Obj58 *)arg0;
    StringEntry **entries;
    register int i;
    fn_80253824(*(void **)((char *)arg0 + 8));
    if (obj78->name78[0] != 0) {
        entries = (StringEntry **)lbl_80498E08;
        i = 0;
        goto scan78_test;
scan78:
        if (stricmp((*entries)->name, obj78->name78) == 0) {
            StringEntry *entry = ((StringEntry **)lbl_80498E08)[i];
            char *dst = entry->name;
            if (--entry->refCount == 0) {
                char ch;
                char *src;
                s32 count;
                fn_8012D3D8(entry->id);
                src = lbl_8055C1C0;
                count = 0x20;
                goto copy78;
copy78_check:
                if (--count > 0) goto copy78;
                dst[-1] = 0;
                goto copy78_end;
copy78:
                ch = *src++;
                *dst++ = ch;
                if ((s8)ch == 0) goto copy78_end;
                goto copy78_check;
copy78_end:
                ;
            }
        } else {
            entries++;
            i++;
scan78_test:
            if (lbl_8055F33C > i) goto scan78;
        }
    }
    if (obj58->name58[0] != 0) {
        entries = (StringEntry **)lbl_80498E08;
        i = 0;
        goto scan58_test;
scan58:
        if (stricmp((*entries)->name, obj58->name58) == 0) {
            StringEntry *entry = ((StringEntry **)lbl_80498E08)[i];
            char *dst = entry->name;
            if (--entry->refCount == 0) {
                char ch;
                char *src;
                s32 count;
                fn_8012D3D8(entry->id);
                src = lbl_8055C1C0;
                count = 0x20;
                goto copy58;
copy58_check:
                if (--count > 0) goto copy58;
                dst[-1] = 0;
                goto copy58_end;
copy58:
                ch = *src++;
                *dst++ = ch;
                if ((s8)ch == 0) goto copy58_end;
                goto copy58_check;
copy58_end:
                ;
            }
        } else {
            i++;
            entries++;
scan58_test:
            if (i < lbl_8055F33C) goto scan58;
        }
    }
    if (lbl_8055F330)
        fn_80252C78();
    if (*(s32 *)((char *)arg0 + 0xE4) != -1) {
        fn_802C6CF8(*(s32 *)((char *)arg0 + 0xE4));
        *(s32 *)((char *)arg0 + 0xE4) = -1;
    }
    *(u8 *)((char *)arg0 + 0x78) = 0;
    *(u8 *)((char *)arg0 + 0x58) = 0;
    *(u8 *)((char *)arg0 + 0x38) = 0;
    *(u8 *)((char *)arg0 + 0x10) = 0;
    {
        unsigned temp = lbl_8055F340 - 1;
        lbl_8055F340 = temp;
        if (temp == 0)
            fn_8025567C();
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80255D3C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float farg0) { typedef struct { char name[0x20]; s32 id; s32 refCount; } StringEntry; typedef struct { float x, y, z; } Vec3; typedef struct { char pad0[0x10]; char n10[0x20]; u8 f30; char pad31[7]; char n38[0x20]; char n58[0x20]; char n78[0x20]; } Obj; extern void *lbl_80498E08[]; extern s32 lbl_8055F33C; extern float lbl_8055F334, lbl_8055F338; extern float lbl_80563A04, lbl_80563A10, lbl_80563A14, lbl_80563A20, lbl_80563A24, lbl_80563A28; extern float lbl_80563A48, lbl_80563A74, lbl_80563A78, lbl_80563A88, lbl_80563A8C; extern double lbl_80563A80; extern char lbl_803447C0[]; extern s32 fn_802D3EBC(void); extern float fn_8023659C(void); extern void fn_80252F50(float); extern void fn_801345D8(void *, int, const char *, ...); extern s32 fn_8012D838(s32); extern s32 fn_8012CC20(s32, void *); extern void fn_8012D3D8(s32); extern int stricmp(const char *, const char *); extern void fn_802E30C8(void *, ...); extern void fn_80253510(void *, unsigned char *); extern void *fn_8001668C(void *, int); extern void fn_80253104(s32, void *); extern s32 fn_80147C50(s32, s32, float); extern void fn_802C77F0(s32, float *); extern void fn_802C7808(s32); extern void fn_8002F234(); extern void fn_802AB9E0(float); extern void fn_802AB9E4(void); extern void fn_802ABC80(void *, float *, float, float, float); extern void fn_80253004(s32, void *); extern void fn_802545C4(void *, int, int); extern void fn_802C98DC(void *, void *, void *, void *); extern void fn_80254938(void *, s32, s32, s32, s32, float, float); char *msg = lbl_803447C0; Obj *o = (Obj *)arg0; s32 cond; char *src; char *dst; char ch; s32 count; s32 i; s32 found; s32 freeIdx; StringEntry **entries; StringEntry *entry; unsigned char *obj; float dt; Vec3 spA0; float sp40[28]; float sp28[6]; Vec3 sp18; s32 sp14, sp10, spC, sp8; float temp_f0, temp_f2, var_f1; register float var_f4; s32 isLive; unsigned int target; float a0, a9c; dt = farg0; lbl_8055F334 = dt; if (fn_802D3EBC() != 0) { dt = lbl_80563A04; lbl_8055F334 = dt; } if (*(s32 *)((u8 *)arg0 + 4) == 0) { lbl_8055F338 = lbl_8055F338 + dt; } if (lbl_8055F330 != 0 && *(s32 *)((u8 *)arg0 + 4) == 0) { fn_80252F50(dt); } cond = 0; if (o->f30 != 0 && fn_8023659C() - *(float *)((u8 *)arg0 + 0x34) > lbl_80563A74) { cond = 1; } if (cond != 0 && (s8)o->n58[0] == 0) { o->f30 = 0; fn_801345D8(o->n58, 0x20, lbl_8055C128, o->n10); src = o->n10; dst = o->n38; count = 0x20; goto copyA; checkA: if (--count > 0) goto copyA; dst[-1] = 0; goto endA; copyA: ch = *src++; *dst++ = ch; if ((s8)ch != 0) goto checkA; endA: entries = (StringEntry **)lbl_80498E08; freeIdx = -1; i = 0; goto scanTest; scanBody: if (((unsigned int)__cntlzw((unsigned int)fn_8012D838((*entries)->id)) >> 5)) { freeIdx = i; goto scanNext; } if (stricmp((*entries)->name, o->n58) == 0) { entry = ((StringEntry **)lbl_80498E08)[i]; entry->refCount = entry->refCount + 1; found = 1; goto scanDone; } scanNext: entries++; i++; scanTest: if (i < lbl_8055F33C) goto scanBody; entry = ((StringEntry **)lbl_80498E08)[freeIdx]; src = o->n58; count = 0x20; dst = entry->name; goto copyB; checkB: if (--count > 0) goto copyB; dst[-1] = 0; goto endB; copyB: ch = *src++; *dst++ = ch; if ((s8)ch != 0) goto checkB; endB: if (fn_8012CC20(entry->id, entry) != 0) { entry->refCount = 1; found = 1; } else { fn_802E30C8(msg + 0x294, entry); dst = entry->name; src = lbl_8055C1C0; count = 0x20; goto copyC; checkC: if (--count > 0) goto copyC; dst[-1] = 0; goto endC; copyC: ch = *src++; *dst++ = ch; if ((s8)ch != 0) goto checkC; endC: entry->refCount = 0; found = 0; } scanDone: if (found == 0) { fn_802E30C8(msg + 0x2BC, o->n58); o->n58[0] = 0; } } else if ((s8)o->n58[0] != 0) { if ((s8)o->n58[0] == 0) { fn_802E30C8(msg + 0x2D8); isLive = 0; } else { entries = (StringEntry **)lbl_80498E08; i = 0; goto liveTest; liveBody: if (stricmp((*entries)->name, o->n58) == 0) { isLive = (fn_8012D838(((StringEntry **)lbl_80498E08)[i]->id) - 2) == 0; goto liveDone; } entries++; i++; liveTest: if (i < lbl_8055F33C) goto liveBody; isLive = 0; } liveDone: if (isLive != 0) { if ((s8)o->n78[0] != 0) { fn_80253824(*(void **)((u8 *)arg0 + 8)); entries = (StringEntry **)lbl_80498E08; i = 0; goto relTest; relBody: if (stricmp((*entries)->name, o->n78) == 0) { entry = ((StringEntry **)lbl_80498E08)[i]; if (--entry->refCount == 0) { fn_8012D3D8(entry->id); src = lbl_8055C1C0; count = 0x20; dst = entry->name; goto copyD; checkD: if (--count > 0) goto copyD; dst[-1] = 0; goto endD; copyD: ch = *src++; *dst++ = ch; if ((s8)ch != 0) goto checkD; endD: ; } goto relDone; } entries++; i++; relTest: if (i < lbl_8055F33C) goto relBody; } relDone: fn_80253510(*(void **)((u8 *)arg0 + 8), (unsigned char *)o->n38); ((void (*)(void *, int))fn_80255920)(arg0, (*(unsigned int *)((char *)fn_8001668C(o->n38, 0) + 0xA0) >> 2) & 1); if (lbl_8055F330 != 0) { fn_80253104(*(s32 *)((u8 *)arg0 + 4), (char *)*(void **)((u8 *)arg0 + 8) + 0x45C); } src = o->n58; dst = o->n78; count = 0x20; goto copyE; checkE: if (--count > 0) goto copyE; dst[-1] = 0; goto endE; copyE: ch = *src++; *dst++ = ch; if ((s8)ch != 0) goto checkE; endE: obj = *(unsigned char **)((u8 *)arg0 + 8); o->n58[0] = 0; target = *(unsigned int *)((u8 *)arg0 + 0xC); o->n38[0] = 0; *(unsigned int *)(obj + 8) = target; *(unsigned int *)(obj + 0xC) = target; *(u8 *)((u8 *)arg0 + 0xDC) = *(u8 *)((u8 *)arg0 + 0xDD); } } if ((s8)o->n58[0] == 0) { obj = *(unsigned char **)((u8 *)arg0 + 8); if (obj[0] != 0 && o->f30 == 0) { target = *(unsigned int *)((u8 *)arg0 + 0xC); if (*(unsigned int *)(obj + 8) != target) { if (*(s32 *)(obj + 8) != 0) { temp_f0 = fn_8023659C(); var_f4 = lbl_80563A14; temp_f0 = ((temp_f0 - *(float *)(obj + 4)) - lbl_80563A04) / lbl_80563A20; if (var_f4 < temp_f0) {} else var_f4 = temp_f0; if (var_f4 > lbl_80563A04) {} else var_f4 = lbl_80563A04; var_f1 = lbl_80563A10; temp_f2 = lbl_80563A04 + (var_f4 * lbl_80563A14); if (temp_f2 < var_f1) { } else if (temp_f2 > lbl_80563A14) var_f1 = lbl_80563A14; else if (temp_f2 > lbl_80563A04) { var_f1 = lbl_80563A24 * temp_f2; temp_f0 = lbl_80563A28 * temp_f2; var_f1 = var_f1 * temp_f2; temp_f0 = temp_f0 * temp_f2; var_f1 = temp_f2 * var_f1; var_f1 = var_f1 + temp_f0; } else { var_f1 = lbl_80563A24 * temp_f2; temp_f0 = lbl_80563A28 * temp_f2; var_f1 = var_f1 * temp_f2; temp_f0 = temp_f0 * temp_f2; var_f1 = temp_f2 * var_f1; var_f1 = var_f1 - temp_f0; } *(s32 *)(obj + 0xC) = fn_80147C50(*(s32 *)(obj + 0xC), *(s32 *)(obj + 8), var_f1); } else { *(unsigned int *)(obj + 0xC) = target; } *(unsigned int *)(obj + 8) = target; *(float *)(obj + 4) = fn_8023659C(); } } } obj = *(unsigned char **)((u8 *)arg0 + 8); temp_f0 = *(float *)((u8 *)arg0 + 0x98) + dt; *(float *)((u8 *)arg0 + 0x98) = temp_f0; if (obj[0] == 0) { if (temp_f0 > lbl_80563A48) { float t = *(float *)((u8 *)arg0 + 0x9C); a0 = *(float *)((u8 *)arg0 + 0xA0) + lbl_80563A78 * dt; a9c = t + lbl_80563A64 * (lbl_80563A68 - t); *(float *)((u8 *)arg0 + 0xA0) = a0; *(float *)((u8 *)arg0 + 0x9C) = a9c; } fn_80254938(arg0, arg1, arg2, arg3, arg4, *(float *)((u8 *)arg0 + 0xA0), *(float *)((u8 *)arg0 + 0x9C)); return; } fn_802C77F0(*(s32 *)(obj + 0x10), sp28); fn_802C7808(*(s32 *)((char *)*(void **)((u8 *)arg0 + 8) + 0x10)); { float dy = sp28[3] - sp28[2]; float dx = sp28[1] - sp28[0]; float dz = sp28[5] - sp28[4]; fn_8002F234(dz * dz + (dx * dx + dy * dy)); } fn_8002F234(lbl_80563A80); if (*(s32 *)((u8 *)arg0 + 4) == 0) { void **list; float k = lbl_80563A88; float zero = lbl_80563A04; fn_802AB9E0(lbl_8055F338); list = lbl_80498E28; i = 0; while (i < lbl_8055F340) { if (*(u8 *)((char *)*list + 0x118) != 0) { sp18.x = zero; sp18.y = zero; sp18.z = zero; if (*(s32 *)((u8 *)arg0 + 0x120) == 0) { if (lbl_8055F330 != 0) { fn_80253004(i, sp40); } else { fn_802545C4(sp40, *(s32 *)((u8 *)arg0 + 0xE4), (int)*(void **)((u8 *)arg0 + 8)); spA0.x = sp40[6] * k; spA0.y = sp40[7] * k; spA0.z = sp40[8] * k; sp18 = spA0; } } fn_802ABC80((char *)*(void **)((char *)*list + 8) + 0x598, &sp18.x, lbl_80563A14, lbl_80563A8C, lbl_80563A14); } list++; i++; } fn_802AB9E4(); } fn_802C98DC(&spC, &sp14, &sp10, &sp8); if (*(float *)((u8 *)arg0 + 0x98) > lbl_80563A48) { float t = *(float *)((u8 *)arg0 + 0x9C); a0 = *(float *)((u8 *)arg0 + 0xA0) + lbl_80563A78 * dt; a9c = t + lbl_80563A64 * (lbl_80563A68 - t); *(float *)((u8 *)arg0 + 0xA0) = a0; *(float *)((u8 *)arg0 + 0x9C) = a9c; } fn_80254938(arg0, arg1, arg2, arg3, arg4, *(float *)((u8 *)arg0 + 0xA0), *(float *)((u8 *)arg0 + 0x9C)); }
#pragma pop

#pragma scheduling on
#pragma use_lmw_stmw on

#pragma dont_inline reset

/* The car shown in the UI ("caruimod"; fn_802556BC builds it, its methods
 * run from the two tables below lbl_80344B98 and lbl_80344BC0). */
struct CarUIModelRec {
    void *vtable;          /* 0x00: lbl_80344B98 */
    s32 cameraIndex;       /* 0x04: entry of the camera table (stride 0x78) */
    void *vehicle;         /* 0x08: vehicle object; its byte 0 says "ready" */
    s32 unkC;              /* 0x0C */
    u8 pad10[0x48];        /* 0x10 */
    char name[1];          /* 0x58: resource name, compared case-insensitively */
    u8 pad59[0x4F];        /* 0x59 */
    float modelMtx[4][3];  /* 0xA8: world matrix; row 3 is the position */
    u8 padD8[4];           /* 0xD8 */
    u8 stretch;            /* 0xDC: draw stretched (1,1.01,1) and un-tinted */
    u8 padDD[3];           /* 0xDD */
    s32 unkE0;             /* 0xE0 */
    s32 modelIndex;        /* 0xE4: "cc_back.mod" handle, -1 while unloaded */
    s32 resId;             /* 0xE8 */
    u8 padEC[0x10];        /* 0xEC */
    void *vtable2;         /* 0xFC: lbl_80344BC0 */
    u8 pad100[0x10];       /* 0x100 */
    s32 unk110;            /* 0x110 */
    u8 unk114;             /* 0x114 */
    u8 pad115[3];          /* 0x115 */
    u8 tinted;             /* 0x118: draw in the level's colour and scale */
    u8 pad119[3];          /* 0x119 */
    float level;           /* 0x11C: grows with time; drives that scale/colour */
    s32 mode;              /* 0x120: 0 = to the screen, 1 = fn_802569DC path */
};

/* The 0x78-byte view setup fn_80253004 copies out of the camera table
 * (lbl_80498D00, 0x78 bytes per camera) or fn_802545C4 builds from a vehicle. */
struct Obj_80256548 {
    char pad[0x24];
    float pos[3];          /* 0x24: where the model is drawn */
    char pad2[0x48];
};
void fn_80256548(struct CarUIModelRec *model) {
    /* Put the UI car where the current view wants it and set up the whole
     * screen to draw it on.
     *
     * When the model is the one drawn to the screen (mode == 0) its position is
     * taken from the 0x78-byte view setup: the camera table entry of
     * cameraIndex while a UI view is being drawn (lbl_8055F330), or one built
     * from the vehicle and the loaded model otherwise.  The position at +0x24
     * of that record is handed to fn_80203E88 together with the model's world
     * matrix.  Then the four "GC: CarUIModel is clearing screen ..." debug
     * reports, each printed only the first time through, and the full-screen
     * viewport (0, 0, screen width, screen height) the car is drawn into. */
    extern unsigned char lbl_8055F330, lbl_8055F344, lbl_8055F345, lbl_8055F346, lbl_8055F347;
    extern char lbl_803447C0[], lbl_8055C1D0;
    extern int lbl_8055CFF0, lbl_8055CFF4;
    extern void fn_80253004(s32, void *);
    extern void fn_802545C4(void *, int, int);
    extern void fn_80203E88(void *, float *, int);
    extern void fn_802E30C8(void *, ...);
    extern void fn_802C86E8(int);
    extern void fn_802C87B4(int, int, int, int);
    extern void fn_802C88BC(int);
    struct {
        float pos[3];
        unsigned int pad;
        struct Obj_80256548 view;
    } frame;
    char *strings = lbl_803447C0;
    frame.pos[0] = 0.0f;
    frame.pos[1] = 0.0f;
    frame.pos[2] = 0.0f;
    if (model->mode == 0) {
        if (lbl_8055F330 != 0) {
            fn_80253004(model->cameraIndex, &frame.view);
        } else {
            fn_802545C4(&frame.view, model->modelIndex, (int)model->vehicle);
        }
        frame.pos[0] = frame.view.pos[0];
        frame.pos[1] = frame.view.pos[1];
        frame.pos[2] = frame.view.pos[2];
    }
    fn_80203E88((void *)model->modelMtx, frame.pos, 0); /* the callee takes no arguments */
    /* printf("%s", ...), once per message: the car preview is what clears the
     * screen here, as the text below lbl_80344A48 explains. */
    if (!lbl_8055F344) { lbl_8055F344 = 1; fn_802E30C8(&lbl_8055C1D0, strings + 0x314 /* "GC: CarUIModel is clearing screen" */); }
    if (!lbl_8055F345) { lbl_8055F345 = 1; fn_802E30C8(&lbl_8055C1D0, strings + 0x338 /* "GC: because this screen has no background right now." */); }
    if (!lbl_8055F346) { lbl_8055F346 = 1; fn_802E30C8(&lbl_8055C1D0, strings + 0x36C /* "GC: and the GC envmap stomps the backbuffer." */); }
    if (!lbl_8055F347) { lbl_8055F347 = 1; fn_802E30C8(&lbl_8055C1D0, strings + 0x398 /* "GC: so no one is actually clearing the backbuffer besides me" */); }
    fn_802C86E8(0);
    fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4); /* the whole screen */
    fn_802C88BC(-1);
}

#pragma push
#pragma processor 750
#pragma cplusplus off
#pragma scheduling invalid_target
void fn_802566A4(void *arg0) {
    extern void *fn_802C86DC(void);
    extern void PSVECCrossProduct(float *, float *, float *);
    extern void PSVECNormalize(float *, float *);
    extern void fn_802C9A1C(float *);
    extern int fn_802C9C8C(int);
    extern void fn_802C9CE0(void);
    extern unsigned int lbl_802FA5B8[9];
    extern float lbl_80563A04;
    extern float lbl_80563A14;
    struct Frame {
        float u[3];
        float v[3];
        float w[3];
        float fallback[3];
        float output[3];
        unsigned int pad;
        union {
            unsigned int word[12];
            float value[12];
        } basis;
        unsigned int config[9];
    } frame;
    int i = 0;
    float zero = lbl_80563A04;
    float one = lbl_80563A14;
    unsigned int *config = lbl_802FA5B8;
    float *out = frame.output;

    frame.config[0] = *config++;
    frame.config[1] = *config++;
    frame.config[2] = *config++;
    frame.config[3] = *config++;
    frame.config[4] = *config++;
    frame.config[5] = *config++;
    frame.config[6] = *config++;
    frame.config[7] = *config++;
    frame.config[8] = *config++;

    do {
        unsigned int *matrix = (unsigned int *)fn_802C86DC();
        unsigned int m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11;
        m0 = matrix[0];
        m2 = matrix[2];
        frame.basis.word[0] = m0;
        m6 = matrix[6];
        frame.basis.word[2] = m2;
        m8 = matrix[8];
        frame.basis.word[6] = m6;
        m1 = matrix[1];
        frame.basis.word[8] = m8;
        m4 = matrix[4];
        frame.basis.word[1] = m1;
        m7 = matrix[7];
        frame.basis.word[4] = m4;
        m3 = matrix[3];
        frame.basis.word[7] = m7;
        m5 = matrix[5];
        frame.basis.word[3] = m3;
        m9 = matrix[9];
        m10 = matrix[10];
        m11 = matrix[11];
        frame.basis.word[5] = m5;
        frame.basis.word[9] = m9;
        frame.basis.word[10] = m10;
        frame.basis.word[11] = m11;

        frame.u[0] = frame.basis.value[0];
        frame.u[1] = zero;
        frame.u[2] = frame.basis.value[2];
        frame.w[0] = frame.basis.value[6];
        frame.w[1] = zero;
        frame.w[2] = frame.basis.value[8];
        PSVECCrossProduct(frame.w, frame.u, frame.v);
        PSVECNormalize(frame.u, frame.u);
        PSVECNormalize(frame.v, frame.v);
        PSVECCrossProduct(frame.u, frame.v, frame.w);
        frame.basis.value[0] = frame.u[0];
        frame.basis.value[1] = frame.u[1];
        frame.basis.value[2] = frame.u[2];
        frame.basis.value[3] = frame.v[0];
        frame.basis.value[4] = frame.v[1];
        frame.basis.value[5] = frame.v[2];
        frame.basis.value[6] = frame.w[0];
        frame.basis.value[7] = frame.w[1];
        frame.basis.value[8] = frame.w[2];

        {
            float *input;
            if (i > 0) {
                input = (float *)frame.config + (i - 1) * 3;
            } else {
                frame.fallback[0] = zero;
                frame.fallback[1] = one;
                frame.fallback[2] = zero;
                input = frame.fallback;
            }
            if (out == input) {
                float x = input[0];
                float y = input[1];
                float z = input[2];
                float a0 = frame.basis.value[0];
                float a3 = frame.basis.value[3];
                float a6 = frame.basis.value[6];
                float a1 = frame.basis.value[1];
                float a4 = frame.basis.value[4];
                float a7 = frame.basis.value[7];
                float a2 = frame.basis.value[2];
                float a5 = frame.basis.value[5];
                float a8 = frame.basis.value[8];
                out[0] = (x * a0 + y * a3) + z * a6;
                out[1] = (x * a1 + y * a4) + z * a7;
                out[2] = (x * a2 + y * a5) + z * a8;
            } else {
                out[0] = (input[0] * frame.basis.value[0] +
                          input[1] * frame.basis.value[3]) +
                          input[2] * frame.basis.value[6];
                out[1] = (input[0] * frame.basis.value[1] +
                          input[1] * frame.basis.value[4]) +
                          input[2] * frame.basis.value[7];
                out[2] = (input[0] * frame.basis.value[2] +
                          input[1] * frame.basis.value[5]) +
                          input[2] * frame.basis.value[8];
            }
        }

        fn_802C9A1C(out);
        if (fn_802C9C8C(0x14000000) != 0) {
            unsigned char *flag = *(unsigned char **)((char *)arg0 + 8);
            if (*flag != 0) {
                fn_80254354(flag);
            }
            fn_802C9CE0();
        }
        i++;
    } while (i < 4);
}

#pragma push
#pragma use_lmw_stmw off
void fn_802569DC(void *arg0, int arg1, float scale) {
    struct Matrix { float m[12]; };
    struct Vertex { float x,y,z; unsigned int color; float u,v; };
    extern void fn_802C942C(int);
    extern void *fn_802C86DC(void);
    extern void fn_802C8638(void *);
    extern float fn_801F159C(int);
    extern void fn_802ABFF8(int, float);
    extern void fn_802AC070(void);
    extern void fn_802ABE50(void);
    extern void fn_802C8BD0(int);
    extern void fn_802C8DB8(void *, int, void *, int);
    extern void fn_802C8D74(void);
    extern double cos(double), sin(double);
    extern float lbl_80563A04, lbl_80563A10, lbl_80563A8C, lbl_80563A90, lbl_80563A94, lbl_80563A98, lbl_80563A9C;
    struct Matrix original, adjusted;
    struct Vertex vertices[301];
    unsigned short indices[1350];
    char *obj;
    float outer, inner, factor, step;
    float height;
    int i, j;
    int n;
    fn_802C942C(-1);
    original = *(struct Matrix *)fn_802C86DC();
    ((double *)&adjusted)[0] = ((double *)&original)[0];
    ((double *)&adjusted)[1] = ((double *)&original)[1];
    ((double *)&adjusted)[2] = ((double *)&original)[2];
    ((double *)&adjusted)[3] = ((double *)&original)[3];
    ((unsigned int *)&adjusted)[8] = ((unsigned int *)&original)[8];
    ((double *)((char *)&adjusted + 0x24))[0] = ((double *)((char *)&original + 0x24))[0];
    ((unsigned int *)&adjusted)[11] = ((unsigned int *)&original)[11];
    adjusted.m[10] *= lbl_80563A10;
    obj = *(char **)((char *)arg0 + 8);
    if (*(unsigned char *)obj) {
        float old = *(float *)(obj + 0x594);
        float y = fn_801F159C(*(int *)(obj + 0x18));
        adjusted.m[10] += (*(float *)(obj + 0x600) + (*(float *)(obj + 0x5c0) - old)) - y - lbl_80563A90;
    }
    adjusted.m[1] *= lbl_80563A10;
    adjusted.m[4] *= lbl_80563A10;
    adjusted.m[7] *= lbl_80563A10;
    fn_802C8638(&adjusted);
    if (**(unsigned char **)((char *)arg0 + 8)) {
        if (*(unsigned char *)((char *)arg0 + 0x118)) fn_802ABFF8(arg1, scale);
        fn_8025419C(*(void **)((char *)arg0 + 8));
        if (*(unsigned char *)((char *)arg0 + 0x118)) { fn_802AC070(); fn_802ABE50(); }
    }
    fn_802C8638(&original);
    fn_802C942C(0x40ffffff);
    obj = *(char **)((char *)arg0 + 8);
    if (*(unsigned char *)obj) height = *(float *)(obj + 0x600) - fn_801F159C(*(int *)(obj + 0x18));
    else height = lbl_80563A04;
    vertices[0].x = lbl_80563A04;
    vertices[0].y = height;
    vertices[0].z = lbl_80563A04;
    vertices[0].color = 0x20ffffff;
    vertices[0].u = lbl_80563A04;
    vertices[0].v = lbl_80563A04;
    { step = lbl_80563A94; factor = lbl_80563A98; inner = lbl_80563A8C; outer = lbl_80563A9C;
    for (i = 0; i < 150; i++) {
        float fi = (float)i;
        float x = factor * (float)cos(fi * step);
        float z = factor * (float)sin(fi * step);
        float x1 = inner * x;
        float z1 = inner * z;
        float x2 = outer * x;
        float z2 = outer * z;
        vertices[1+i*2].x = x1;
        vertices[1+i*2].y = height;
        vertices[1+i*2].z = z1;
        vertices[1+i*2].color = 0x20ffffff;
        vertices[1+i*2].u = factor * x1;
        vertices[1+i*2].v = factor * z1;
        vertices[2+i*2].x = x2;
        vertices[2+i*2].y = height;
        vertices[2+i*2].z = z2;
        vertices[2+i*2].color = 0x00ffffff;
        vertices[2+i*2].u = factor * x2;
        vertices[2+i*2].v = factor * z2;
    }
    }
    for (i = 0, n = 1; i < 150; i++, n += 2) {
        unsigned short *p = &indices[i*9];
        int b = n + 1, c = b + 1;
        p[0]=0; p[1]=n; p[2]=c; p[3]=n; p[4]=b;
        p[5]=c; p[6]=c; p[7]=b; p[8]=b+2;
        for (j=0; j<9; j++) if (p[j] > 300) p[j] -= 300;
    }
    fn_802C8BD0(*(int *)((char *)arg0 + 0xe8));
    fn_802C8DB8(vertices, 301, indices, 1350);
    fn_802C8D74();
}
#pragma pop

/* Light colours (packed RGB, alpha ignored) fn_80256DD8 gives the car
 * preview's light: the diffuse colour depends on the view mode (field
 * mode), the ambient colour is always the same warm white. */
#define UI_LIGHT_DIFFUSE_MODE1 0x00AAAAC8
#define UI_LIGHT_DIFFUSE_MODE0 0x00555766
#define UI_LIGHT_AMBIENT 0x00FFF5D9

/* Draw the car preview (caruimod) for one frame.
 *
 * Keeps the renderer's current 4x3 model matrix, picks up the view setup for
 * this model (the camera record of cameraIndex, or one built from the
 * vehicle), sets the projection, the light direction, intensity and colours
 * and a camera-relative basis, then places the loaded model (modelIndex,
 * "cc_back.mod") at the position of modelMtx.  It is drawn tinted and scaled
 * from level, or stretched 1% in Y, and every piece of renderer state is put
 * back before returning.
 */
void fn_80256DD8(struct CarUIModelRec *model) {

extern void *fn_802C86DC(void);          /* the current 4x3 model matrix */
extern void fn_80253004(s32, void *);    /* copy a camera record by index */
extern void fn_802545C4(void *, s32, s32); /* build the view setup instead */
extern float fn_802C9744(void);          /* current field of view */
extern void fn_802C974C(float, float, float); /* projection: near, far, fov */
extern void fn_802C8638(void *);         /* make a 4x3 matrix the current one */
extern void fn_802C99E8(float);          /* light intensity */
extern void fn_802C9950(s32);            /* light diffuse colour */
extern void fn_802C9994(s32);            /* light ambient colour */
extern void fn_801F1C24(void *);         /* camera-relative orthonormal basis */
extern void fn_802C7730(void *);
extern void fn_802ABE58(void *, float *, s32 *, float); /* level -> scale + colour */
extern void fn_80253CA4(void *, void *, float *, void *); /* the four wheels */
extern void fn_802569DC(void *, s32, float);
extern void fn_802C744C(s32, void *);    /* set a model's transform */
extern void fn_802C70AC(s32, void *, s32, s32); /* set a model's transform */
extern void fn_802AEB3C(void *);
extern void fn_802B016C(void);
extern s32 fn_802C9C8C(s32);             /* start drawing to the screen */
extern void fn_802C9CE0(void);           /* and show it */
extern u8 fn_802C2C00(u8);               /* global scale on/off, returns old */
extern s32 fn_802C990C(s32);             /* model colour, returns old */
extern void fn_802C2BB8(float *, float *, float *); /* get global scale */
extern void fn_802C2B78(float, float, float);       /* set global scale */
extern void fn_802ABFF8(s32, float);     /* draw tinted and scaled */
extern void fn_802AC070(void);           /* undo fn_802ABFF8 */
extern void fn_802ABE50(void);
extern void *memset(void *, int, unsigned long);
extern u8 lbl_8055F330;      /* which view is being drawn (0 = plain UI) */
extern float lbl_80563AA0;   /* -0.3048f: how far a wheel offset may sink */
extern float lbl_80563A00, lbl_80563A04, lbl_80563A14, lbl_80563AA4, lbl_8055F334;
    u8 frame[0x160];
    s32 *currentMtx;
    s32 wheel;
    float fov;
    float scale;
    void *mtx;

    struct MtxWords9 { s32 v[9]; };
    struct MtxWords3 { s32 v[3]; };
    currentMtx = (s32 *)fn_802C86DC();
    *(struct MtxWords9 *)(frame + 0xB0) = *(struct MtxWords9 *)currentMtx;
    *(struct MtxWords3 *)(frame + 0xD4) = *(struct MtxWords3 *)(currentMtx + 9);

    if (lbl_8055F330 != 0) {
        float *wheelOffsets = (float *)(frame + 0x120);
        fn_80253004(model->cameraIndex, frame + 0xe0);
        for (wheel = 0; wheel < 4; wheel++) {
            wheelOffsets[wheel] = wheelOffsets[wheel] < lbl_80563AA0 ? wheelOffsets[wheel] : lbl_80563AA0;
        }
    } else {
        fn_802545C4(frame + 0xe0, model->modelIndex, (s32)model->vehicle);
    }

    fov = fn_802C9744();
    fn_802C974C(lbl_80563A14 /* 1.0f */, lbl_80563A00 /* 2250.0f */, fov);
    fn_802C8638(model->modelMtx);
    fn_80253258();
    fn_802C99E8(lbl_80563A14);
    if (model->mode == 1)
        fn_802C9950(UI_LIGHT_DIFFUSE_MODE1);
    else
        fn_802C9950(UI_LIGHT_DIFFUSE_MODE0);
    fn_802C9994(UI_LIGHT_AMBIENT);
    fn_801F1C24(frame + 0x80);
    fn_802C7730(frame + 0x80);
    fn_802ABE58(&model->level, (float *)(frame + 0x4),
                (s32 *)frame, lbl_8055F334);

    if (*(u8 *)model->vehicle != 0)
        fn_80253CA4(model->vehicle, frame + 0xe0,
                    (float *)(frame + 0x120), frame + 0x130);

    if (model->mode == 1) {
        scale = *(float *)(frame + 0x4);
        fn_802569DC(model, *(s32 *)frame, scale);
    }

    if (model->modelIndex != -1) {
        mtx = frame + 0x50;
        *(float *)(frame + 0x50) = lbl_80563A14;
        *(float *)(frame + 0x54) = lbl_80563A04;
        *(float *)(frame + 0x58) = lbl_80563A04;
        *(float *)(frame + 0x5c) = lbl_80563A04;
        *(float *)(frame + 0x60) = lbl_80563A14;
        *(float *)(frame + 0x64) = lbl_80563A04;
        *(float *)(frame + 0x68) = lbl_80563A04;
        *(float *)(frame + 0x6c) = lbl_80563A04;
        *(float *)(frame + 0x70) = lbl_80563A14;
        *(float *)(frame + 0x74) = lbl_80563A04;
        *(float *)(frame + 0x78) = lbl_80563A04;
        *(float *)(frame + 0x7c) = lbl_80563A04;
        if (lbl_8055F330 != 0) {
            *(float *)(frame + 0x74) = model->modelMtx[3][0];
            *(float *)(frame + 0x78) = model->modelMtx[3][1];
            *(float *)(frame + 0x7c) = model->modelMtx[3][2];
            fn_802C744C(model->modelIndex, mtx);
        } else {
            fn_802C70AC(model->modelIndex, mtx, 0, 1);
        }
    }

    if (lbl_8055F330 != 0) {
        fn_802AEB3C(model->modelMtx);
        fn_802B016C();
    }

    if (model->mode == 0 &&
        fn_802C9C8C(0x50000000) != 0) {
        void *vehicle = model->vehicle;
        if (*(u8 *)vehicle != 0) fn_80254354(vehicle);
        fn_802C9CE0();
    }

    if (model->mode == 1)
        fn_802566A4(model);

    if (model->stretch != 0) {
        *(u8 *)(frame + 0x18) = fn_802C2C00(1);
        *(s32 *)(frame + 0x8) = fn_802C990C(0xFF000000);
        fn_802C2BB8((float *)(frame + 0xc), (float *)(frame + 0x10),
                    (float *)(frame + 0x14));
        fn_802C2B78(lbl_80563A14, lbl_80563AA4 /* 1.01f */, lbl_80563A14);
    } else {
        memset(frame + 0x8, 0, 0x14);
    }

    if (model->tinted != 0 &&
        model->stretch == 0) {
        scale = *(float *)(frame + 0x4);
        fn_802ABFF8(*(s32 *)frame, scale);
    }

    {
        void *vehicle = model->vehicle;
        if (*(u8 *)vehicle != 0) fn_8025419C(vehicle);
    }

    if (model->tinted != 0 &&
        model->stretch == 0)
        fn_802AC070();

    if (model->stretch != 0) {
        fn_802C990C(*(s32 *)(frame + 0x8));
        fn_802C2B78(*(float *)(frame + 0xc), *(float *)(frame + 0x10),
                    *(float *)(frame + 0x14));
        fn_802C2C00(*(u8 *)(frame + 0x18));
    }

    if (model->modelIndex != -1) {
        *(float *)(frame + 0x20) = lbl_80563A14;
        *(float *)(frame + 0x24) = lbl_80563A04;
        *(float *)(frame + 0x28) = lbl_80563A04;
        *(float *)(frame + 0x2c) = lbl_80563A04;
        *(float *)(frame + 0x30) = lbl_80563A14;
        *(float *)(frame + 0x34) = lbl_80563A04;
        *(float *)(frame + 0x38) = lbl_80563A04;
        *(float *)(frame + 0x3c) = lbl_80563A04;
        *(float *)(frame + 0x40) = lbl_80563A14;
        *(float *)(frame + 0x44) = lbl_80563A04;
        *(float *)(frame + 0x48) = lbl_80563A04;
        *(float *)(frame + 0x4c) = lbl_80563A04;
        fn_802C70AC(model->modelIndex, frame + 0x20, 0, 2);
    }

    if (model->tinted != 0)
        fn_802ABE50();
    fn_802C8638(frame + 0xb0);
}
#pragma scheduling on


#pragma scheduling on
s32 fn_802571F0(void) { return 0; }

void fn_802571F8(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 1; }

void fn_80257204(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 0; }

void fn_80257210(void) {}

