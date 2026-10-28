// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
__declspec(section ".sdata") extern char lbl_8055C178[];
__declspec(section ".sdata") extern char lbl_8055C180[];
__declspec(section ".sdata") extern char lbl_8055C188[];
extern void fn_80253824(void *);
extern s32 fn_80128668(void);
extern char lbl_80344B98[];
extern char lbl_80344BC0[];
extern void fn_80255200(void *, s32);
extern void fn_80015A20(void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern float fn_8023659C(void);

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

void fn_80253254(void) {}

#pragma scheduling invalid_target
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
#pragma scheduling on

void *fn_8025343C(void *arg0) {
    extern void fn_802532BC(void);
    extern float fn_8023659C(void);
    extern int fn_801F0008(void);
    extern int fn_801284E8(char *, int);
    extern char lbl_803447C0[], lbl_803447CC[];
    fn_802532BC();
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
#pragma scheduling invalid_target
extern "C" void fn_80253510(void *arg0, unsigned char *arg1) {
    struct Stack {
        float sp8;
        float spC;
        float sp10;
        unsigned int pad14;
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
    float temp_f2;
    float var_f2;
    float temp_f3;
    float var_f4;
    float temp_f29;
    float temp_f30;
    float temp_f31;
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
        var_f2 = temp_f3 * var_f0;
        stack.spC = *(float *)((unsigned char *)var_r4_2 + 0x4F4) -
                    *(float *)((unsigned char *)var_r4_2 + 0x4DC);
        var_f2 = var_f2 * var_f4;
        stack.sp8 = var_f2;
        if (var_r0_2 != 0) var_f0_2 = lbl_80563A14;
        else var_f0_2 = lbl_80563A10;
        var_r4_2 = (unsigned char *)var_r4_2 + 0x24;
        *(float *)((unsigned char *)var_r5_2 + 0x42C) = stack.sp8;
        temp_f1_2 = temp_f29 * (temp_f3 * var_f0_2);
        *(float *)((unsigned char *)var_r5_2 + 0x430) = stack.spC;
        *(float *)((unsigned char *)var_r5_2 + 0x434) = temp_f1_2;
        var_r5_2 = (unsigned char *)var_r5_2 + 0xC;
        stack.sp10 = temp_f1_2;
    }
    fn_80253890(arg0, stack.sp38);
    *(signed char *)arg0 = 1;
}

extern "C" void fn_802C6CF8(s32);
extern "C" void fn_801F0000(s32);
extern "C" void fn_80253C48(void *);
extern "C" void fn_802532BC(void);
#pragma dont_inline on
extern "C" void fn_80253824(void *arg0) {
    if (*(u8 *)arg0 != 0) {
        *(u8 *)arg0 = 0;
        fn_802C6CF8(*(s32 *)((u8 *)arg0 + 0x10));
        fn_802C6CF8(*(s32 *)((u8 *)arg0 + 0x14));
        fn_801F0000(*(s32 *)((u8 *)arg0 + 0x18));
        fn_801F0000(*(s32 *)((u8 *)arg0 + 0x1C));
        fn_80253C48(arg0);
        ((void (*)(void *))fn_802532BC)(arg0);
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
void fn_80253890(void *arg0, void *arg1) {
    extern void *fn_80131810(void *);
    extern void fn_801345D8(void *, int, const char *, ...);
    extern void fn_802E317C(const char *, ...);
    extern int fn_802C7830(void);
    extern int fn_801D2008(char *);
    extern int sprintf(char *, const char *, ...);
    extern void *memset(void *, int, unsigned long);
    extern char lbl_8055C150[], lbl_8055C158[], lbl_8055C160[], lbl_8055C168[], lbl_8055C16C[];
    extern int lbl_802FA5A8[];
    extern float lbl_80563A04;
    typedef int (*has_fn)(void *, const char *);
    typedef int (*has8_fn)(void *, const char *, int, int, int, int, int, int);
    typedef void *(*get_fn)(void *, const char *);
    typedef const char *(*str_fn)(void *, const char *);
    typedef int (*int_fn)(void *, const char *);
    typedef void (*parse_fn)(float *, void *, const char *, float *);
    typedef int (*param_fn)(void *, int);
    unsigned char stack[0x350];
    void *manager;
    void *resource;
    char *labels = lbl_803447C0;
    int i;
    volatile int *p;
    void **vtable;
    const char *str;

    if (*(int *)((char *)arg0 + 0x28) != -1) return;
    fn_801345D8((char *)stack + 0x258, 0x100, labels + 0x50, arg1);
    manager = fn_80131810((char *)stack + 0x258);
    if (manager == 0) {
        *(int *)((char *)arg0 + 0x34) = 0;
        *(int *)((char *)arg0 + 0x28) = -1;
        *(int *)((char *)arg0 + 0x3FC) = 0;
        return;
    }
    p = (int *)((char *)stack + 0x154);
    i = 0x20;
    do { p[1] = 0; *(p += 2) = 0; } while (--i != 0);
    vtable = *(void ***)manager;
    if (((has_fn)vtable[4])(manager, lbl_8055C150) != 0) {
        resource = ((get_fn)vtable[2])(manager, lbl_8055C150);
        str = ((str_fn)(*(void ***)resource)[5])(resource, labels + 0x60);
        sprintf((char *)stack + 0x158, lbl_8055C158, arg1, str);
        str = ((str_fn)(*(void ***)resource)[5])(resource, labels + 0x6C);
        fn_801345D8((char *)stack + 0x58, 0x100, lbl_8055C158, arg1, str);
        *(int *)((char *)arg0 + 0x28) = fn_802C6FC0((char *)stack + 0x58, 0, (int)arg1);
        *(int *)((char *)arg0 + 0x2C) = ((int_fn)(*(void ***)resource)[7])(resource, labels + 0x78);
        *(int *)((char *)arg0 + 0x30) = ((int_fn)(*(void ***)resource)[7])(resource, labels + 0x84);
        *(int *)((char *)arg0 + 0x34) = ((int_fn)(*(void ***)resource)[7])(resource, labels + 0x90);
        if (((has_fn)(*(void ***)resource)[3])(resource, labels + 0x9C) != 0) {
            ((str_fn)(*(void ***)resource)[5])(resource, labels + 0x9C);
            *(int *)((char *)arg0 + 0x38) = fn_802C7830();
        } else *(int *)((char *)arg0 + 0x38) = -1;
    } else fn_802E317C(labels + 0xA8, (char *)stack + 0x258);
    vtable = *(void ***)manager;
    if (((has_fn)vtable[4])(manager, lbl_8055C160) != 0) {
        float zero = lbl_80563A04;
        ((float *)((char *)stack + 0x28))[0] = zero; ((float *)((char *)stack + 0x28))[1] = zero; ((float *)((char *)stack + 0x28))[2] = zero;
        resource = ((get_fn)vtable[2])(manager, lbl_8055C160);
        for (i = 0; i < *(int *)((char *)arg0 + 0x34); i++) {
            fn_801345D8((char *)stack + 0x38, 0x20, lbl_8055C168, i);
            ((parse_fn)(*(void ***)resource)[14])((float *)((char *)stack + 0xC), resource, (char *)stack + 0x38, (float *)stack);
            *(float *)((char *)arg0 + 0x3C + i * 0xC) = ((float *)((char *)stack + 0xC))[0];
            *(float *)((char *)arg0 + 0x40 + i * 0xC) = ((float *)((char *)stack + 0xC))[1];
            *(float *)((char *)arg0 + 0x44 + i * 0xC) = ((float *)((char *)stack + 0xC))[2];
        }
    } else memset((char *)arg0 + 0x3C, 0x3C0, 0);
    vtable = *(void ***)manager;
    if (((has8_fn)vtable[4])(manager, lbl_8055C16C,
                            lbl_802FA5A8[2], lbl_802FA5A8[1],
                            lbl_802FA5A8[0], lbl_802FA5A8[1],
                            lbl_802FA5A8[2], lbl_802FA5A8[3]) != 0) {
        resource = ((get_fn)vtable[2])(manager, lbl_8055C16C);
        for (i = 0; i < 4; i++)
            ((param_fn)(*(void ***)resource)[8])(resource, *(int *)((char *)stack + 0x18 + i * 4));
    }
    ((void (*)(void *))fn_80131818)(manager);
    if (*(char *)((char *)stack + 0x158) != 0) *(int *)((char *)arg0 + 0x3FC) = fn_801D2008((char *)stack + 0x158);
    else *(int *)((char *)arg0 + 0x3FC) = 0;
}

#pragma scheduling on
#pragma cplusplus reset

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
 float temp_f0,temp_f2,var_f1; unsigned char *var_r31; s32 var_r30,temp_r31,temp_r6,var_r0;
 memset(sp10,0,0x3C0); temp_f0=fn_8023659C(); var_f4=lbl_80563A14;
 temp_f0=((temp_f0-*(float *)((u8 *)arg0+4))-lbl_80563A04)/lbl_80563A20;
 if(var_f4<temp_f0)var_f4=temp_f0; if(var_f4>lbl_80563A04)var_f4=lbl_80563A04;
 var_f1=lbl_80563A10; temp_f2=lbl_80563A04+(var_f4*lbl_80563A14);
 if(temp_f2>=var_f1){} else if(temp_f2>lbl_80563A14)var_f1=lbl_80563A14;
 else if(temp_f2>lbl_80563A04) {
  var_f1=lbl_80563A24*temp_f2; temp_f0=lbl_80563A28*temp_f2;
  var_f1=var_f1*temp_f2; temp_f0=temp_f0*temp_f2; var_f1=temp_f2*var_f1; var_f1=var_f1+temp_f0;
 } else {
  var_f1=lbl_80563A24*temp_f2; temp_f0=lbl_80563A28*temp_f2;
  var_f1=var_f1*temp_f2; temp_f0=temp_f0*temp_f2; var_f1=temp_f2*var_f1; var_f1=var_f1-temp_f0;
 }
 spC=fn_80147C50(*(s32 *)((u8 *)arg0+0xC),*(s32 *)((u8 *)arg0+8),var_f1);
 temp_r31=fn_802C7A40(1,sp10,0x50,1,&spC,1); fn_8018BF44(&sp8);
 temp_r6=sp8|0x10000000; sp8=temp_r6; fn_802C70AC(*(s32 *)((u8 *)arg0+0x10),(u8 *)arg0+0x598,temp_r31,temp_r6);
 var_r31=(u8 *)arg0+0x5D8; var_r30=0;
 do { var_r0=0; if(var_r30!=0){if(var_r30==1)var_r0=1;}
  if(var_r0)fn_801F1394(*(s32 *)((u8 *)arg0+0x18),var_r31);
  else fn_801F1394(*(s32 *)((u8 *)arg0+0x1C),var_r31);
  var_r30++;var_r31+=0x30;
 }while(var_r30<4);
 fn_802543FC(arg0);
}

extern void fn_802C7AE0(s32, void *, s32, float);
#pragma scheduling invalid_target
void fn_80254354(void *arg0) {
    extern float lbl_80563A2C;
    u8 *p;
    s32 i;
    s32 var_r0;
    register float initial;
    initial = lbl_80563A2C;
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
    float sourceY;
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
            sourceY = *(float *)(base + 0x5C8);
            difference = *(float *)(base + 0x424);
            difference = sourceY - difference;
            point = base + index * 12;
            *(float *)(point + 0x3C) = zero;
            *(float *)(point + 0x40) = difference;
            *(float *)(point + 0x44) = zero;
            index = *(s32 *)((u8 *)p + 0xD0);
            sourceY = *(float *)(base + 0x5CC);
            difference = *(float *)(base + 0x424);
            difference = sourceY - difference;
            point = base + index * 12;
            *(float *)(point + 0x3C) = zero;
            *(float *)(point + 0x40) = difference;
            *(float *)(point + 0x44) = zero;
            index = *(s32 *)((u8 *)p + 0xD4);
            sourceY = *(float *)(base + 0x5D0);
            difference = *(float *)(base + 0x424);
            difference = sourceY - difference;
            point = base + index * 12;
            *(float *)(point + 0x3C) = zero;
            *(float *)(point + 0x40) = difference;
            *(float *)(point + 0x44) = zero;
            index = *(s32 *)((u8 *)p + 0xD8);
            sourceY = *(float *)(base + 0x5D4);
            difference = *(float *)(base + 0x424);
            difference = sourceY - difference;
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
#pragma dont_inline reset
void fn_80255200(void *arg0, s32 arg1) {
    extern float lbl_80563A04,lbl_80563A14,lbl_80563A58,lbl_80563A5C;
    extern char lbl_803447C0[]; extern void *lbl_80498E08[];
    extern long lbl_8055C190; extern s32 lbl_8055F33C;
    extern void fn_8025539C(void); extern void *fn_802CAC28(void *,s32);
    extern void *fn_801284F8(s32,void *); extern void *fn_8012CAA0(s32,void *);
    extern void fn_80255A84(void *);
    float zero=lbl_80563A04, one=lbl_80563A14, two=lbl_80563A58, three=lbl_80563A5C;
    u8 *p=(u8 *)arg0; void *obj; s32 n;
    *(u8 *)(p+0x118)=0; *(float *)(p+0x11C)=zero;
    *(u8 *)(p+0xDD)=0; *(u8 *)(p+0xDC)=0; *(u8 *)(p+0x30)=0;
    *(float *)(p+0x98)=two; *(float *)(p+0xA8)=one;
    *(float *)(p+0xAC)=zero; *(float *)(p+0xB0)=zero; *(float *)(p+0xB4)=zero;
    *(float *)(p+0xB8)=one; *(float *)(p+0xBC)=zero; *(float *)(p+0xC0)=zero;
    *(float *)(p+0xC4)=zero; *(float *)(p+0xC8)=one; *(float *)(p+0xCC)=zero;
    *(float *)(p+0xD0)=zero; *(float *)(p+0xD4)=zero; *(s32 *)(p+0xD8)=-1;
    *(float *)(p+0xEC)=three; *(float *)(p+0xF0)=zero; *(float *)(p+0xF4)=zero; *(float *)(p+0xF8)=zero;
    *(u8 *)(p+0x10)=0; *(u8 *)(p+0x38)=0; *(u8 *)(p+0x58)=0; *(u8 *)(p+0x78)=0;
    *(unsigned int *)(p+0xC)=0xFF000000;
    if(arg1) fn_8025539C();
    *(void **)(p+0xE8)=fn_802CAC28(lbl_803447C0+0x100,0);
    obj=fn_801284F8(0x28,lbl_803447C0+0x110);
    if(obj) *(void **)((u8 *)obj+0x20)=fn_8012CAA0(0x16E360,lbl_803447C0+0x11C);
    n=lbl_8055F33C; lbl_80498E08[n]=obj; lbl_8055F33C=n+1;
    obj=fn_801284F8(0x28,lbl_803447C0+0x110);
    if(obj) *(void **)((u8 *)obj+0x20)=fn_8012CAA0(0x16E360,lbl_803447C0+0x11C);
    n=lbl_8055F33C; lbl_80498E08[n]=obj; lbl_8055F33C=n+1;
    obj=fn_801284F8(0x698,&lbl_8055C190);
    if(obj) *(void **)(p+8)=((void *(*)(void))fn_8025343C)();
    fn_80255A84(arg0);
}

#pragma dont_inline fn_80255604
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

void *fn_80255758(void *arg0, s32 arg1, s32 arg2) {
    extern char lbl_80344B98[]; extern char lbl_803449D4[];
    extern void *lbl_80498E08[]; extern s32 lbl_8055F33C;
    extern void fn_80255B5C(void *);
    extern void fn_802CAC54(s32);
    extern s32 fn_8012D838(s32); extern void fn_8012D8A8(s32);
    extern void fn_802E317C(const char *, ...);
    extern void *memmove(void *, const void *, unsigned long);
    s32 i,count; void *obj; void **slot;
    (void)arg2;
    if(arg0) {
        *(void **)arg0=lbl_80344B98;
        fn_80255B5C(arg0);
        ((void *(*)(void *,s32))__dt__Q210JASDrumSet5TPercFv_802534B0)(*(void **)((u8 *)arg0+8),1);
        fn_802CAC54(*(s32 *)((u8 *)arg0+0xE8));
        for(i=0;i<lbl_8055F33C;) {
            if(fn_8012D838(*(s32 *)((u8 *)lbl_80498E08[i]+0x20))==0) {
                slot=&lbl_80498E08[i]; obj=*slot;
                if(obj){fn_8012D8A8(*(s32 *)((u8 *)obj+0x20));((s32 (*)(void *))fn_80128668)(obj);}
                count=lbl_8055F33C-1; lbl_8055F33C=count;
                memmove(slot,slot+1,(count-i)*4);
            } else i++;
        }
        fn_802E317C(lbl_803449D4);
        for(i=0;i<lbl_8055F33C;) {
            if(fn_8012D838(*(s32 *)((u8 *)lbl_80498E08[i]+0x20))==0) {
                slot=&lbl_80498E08[i]; obj=*slot;
                if(obj){fn_8012D8A8(*(s32 *)((u8 *)obj+0x20));((s32 (*)(void *))fn_80128668)(obj);}
                count=lbl_8055F33C-1; lbl_8055F33C=count;
                memmove(slot,slot+1,(count-i)*4);
            } else i++;
        }
        fn_802E317C(lbl_803449D4);
        if(arg1>0)((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

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
        char name[0x20];
        s32 id;
        s32 refCount;
    } StringEntry;
    typedef struct {
        char pad0[0x58];
        char name[1];
    } Obj;
    extern void *lbl_80498E08[];
    extern s32 lbl_8055F33C;
    extern void fn_8012D3D8(s32);
    extern int stricmp(const char *, const char *);
    Obj *obj;
    register s32 i;
    register StringEntry **entries;

    obj = (Obj *)arg0;
    if (obj->name[0] != 0) {
        entries = (StringEntry **)lbl_80498E08;
        i = 0;
        goto scan_test;
    scan:
        if (stricmp((*entries)->name, obj->name) == 0) {
            {
                char ch;
                char *src;
                s32 count;
                char *dst;
                StringEntry *entry;
                entry = ((StringEntry **)lbl_80498E08)[i];
                dst = entry->name;
                if (--entry->refCount == 0) {
                    fn_8012D3D8(entry->id);
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
    lbl_8055F340++;
    lbl_80498E28[*(s32 *)((char *)arg0 + 4)] = arg0;
    *(float *)((char *)arg0 + 0x9C) = lbl_80563A68;
    *(float *)((char *)arg0 + 0xA0) = lbl_80563A6C;
    *(float *)((char *)arg0 + 0xA4) = lbl_80563A70;
}
#pragma dont_inline reset
struct Obj_80256548 {
    char pad[0x24];
    float pos[3];
    char pad2[0x48];
};
void fn_80256548(void *arg0) {
    extern float lbl_80563A04;
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
        float vec[3];
        unsigned int pad;
        struct Obj_80256548 out;
    } frame;
    char *str_base = lbl_803447C0;

    frame.vec[0] = lbl_80563A04;
    frame.vec[1] = lbl_80563A04;
    frame.vec[2] = lbl_80563A04;

    if (*(int *)((char *)arg0 + 0x120) == 0) {
        if (lbl_8055F330 != 0) {
            fn_80253004(*(int *)((char *)arg0 + 4), &frame.out);
        } else {
            fn_802545C4(&frame.out, *(int *)((char *)arg0 + 0xE4), *(int *)((char *)arg0 + 8));
        }
        frame.vec[0] = frame.out.pos[0];
        frame.vec[1] = frame.out.pos[1];
        frame.vec[2] = frame.out.pos[2];
    }
    fn_80203E88((char *)arg0 + 0xA8, frame.vec, 0);
    if (!lbl_8055F344) { lbl_8055F344 = 1; fn_802E30C8(&lbl_8055C1D0, str_base + 0x314); }
    if (!lbl_8055F345) { lbl_8055F345 = 1; fn_802E30C8(&lbl_8055C1D0, str_base + 0x338); }
    if (!lbl_8055F346) { lbl_8055F346 = 1; fn_802E30C8(&lbl_8055C1D0, str_base + 0x36C); }
    if (!lbl_8055F347) { lbl_8055F347 = 1; fn_802E30C8(&lbl_8055C1D0, str_base + 0x398); }
    fn_802C86E8(0);
    fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802C88BC(-1);
}

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
            register float *input;
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
                out[0] = (x * frame.basis.value[0] + y * frame.basis.value[3]) +
                         z * frame.basis.value[6];
                out[1] = (x * frame.basis.value[1] + y * frame.basis.value[4]) +
                         z * frame.basis.value[7];
                out[2] = (x * frame.basis.value[2] + y * frame.basis.value[5]) +
                         z * frame.basis.value[8];
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

void fn_80256DD8(void *arg0) {

extern void *fn_802C86DC(void);
extern void fn_80253004(s32, void *);
extern void fn_802545C4(void *, s32, s32);
extern float fn_802C9744(void);
extern void fn_802C974C(float, float, float);
extern void fn_802C8638(void *);
extern void fn_802C99E8(float);
extern void fn_802C9950(s32);
extern void fn_802C9994(s32);
extern void fn_801F1C24(void *);
extern void fn_802C7730(void *);
extern void fn_802ABE58(void *, float *, s32 *, float);
extern void fn_80253CA4(void *, void *, float *, void *);
extern void fn_802569DC(void *, s32, float);
extern void fn_802C744C(s32, void *);
extern void fn_802C70AC(s32, void *, s32, s32);
extern void fn_802AEB3C(void *);
extern void fn_802B016C(void);
extern s32 fn_802C9C8C(s32);
extern void fn_802C9CE0(void);
extern u8 fn_802C2C00(u8);
extern s32 fn_802C990C(s32);
extern void fn_802C2BB8(float *, float *, float *);
extern void fn_802C2B78(float, float, float);
extern void fn_802ABFF8(s32, float);
extern void fn_802AC070(void);
extern void fn_802ABE50(void);
extern void *memset(void *, int, unsigned long);
extern u8 lbl_8055F330;
extern float lbl_80563AA0;
extern float lbl_80563A00, lbl_80563A04, lbl_80563A14, lbl_80563AA4, lbl_8055F334;
    u8 frame[0x160];
    s32 *source;
    s32 i;
    float value;
    float maxValue;

    struct Copy32 { s32 v[8]; };
    source = (s32 *)fn_802C86DC();
    *(struct Copy32 *)(frame + 0xB0) = *(struct Copy32 *)source;
    *(s32 *)(frame + 0xD0) = source[8];
    *(s32 *)(frame + 0xD4) = source[9];
    *(s32 *)(frame + 0xD8) = source[10];
    *(s32 *)(frame + 0xDC) = source[11];

    if (lbl_8055F330 != 0) {
        fn_80253004(*(s32 *)((u8 *)arg0 + 4), frame + 0xe0);
        maxValue = lbl_80563AA0;
        value = *(float *)(frame + 0x120);
        value = value < maxValue ? value : maxValue;
        *(float *)(frame + 0x120) = value;
        value = *(float *)(frame + 0x124);
        value = value < maxValue ? value : maxValue;
        *(float *)(frame + 0x124) = value;
        value = *(float *)(frame + 0x128);
        value = value < maxValue ? value : maxValue;
        *(float *)(frame + 0x128) = value;
        value = *(float *)(frame + 0x12c);
        value = value < maxValue ? value : maxValue;
        *(float *)(frame + 0x12c) = value;
    } else {
        fn_802545C4(frame + 0xe0, *(s32 *)((u8 *)arg0 + 0xE4),
                    *(s32 *)((u8 *)arg0 + 8));
    }

    value = fn_802C9744();
    fn_802C974C(lbl_80563A14, lbl_80563A00, value);
    fn_802C8638((u8 *)arg0 + 0xA8);
    fn_80253258();
    fn_802C99E8(lbl_80563A14);
    if (*(s32 *)((u8 *)arg0 + 0x120) == 1)
        fn_802C9950(0x00AAAAC8);
    else
        fn_802C9950(0x00555766);
    fn_802C9994(0x00FFF5D9);
    fn_801F1C24(frame + 0x80);
    fn_802C7730(frame + 0x80);
    fn_802ABE58((u8 *)arg0 + 0x11C, (float *)(frame + 0x4),
                (s32 *)frame, lbl_8055F334);

    if (*(u8 *)*(void **)((u8 *)arg0 + 8) != 0)
        fn_80253CA4(*(void **)((u8 *)arg0 + 8), frame + 0xe0,
                    (float *)(frame + 0x120), frame + 0x130);

    if (*(s32 *)((u8 *)arg0 + 0x120) == 1)
        fn_802569DC(arg0, *(s32 *)frame, *(float *)(frame + 0x4));

    if (*(s32 *)((u8 *)arg0 + 0xE4) != -1) {
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
            *(float *)(frame + 0x74) = *(float *)((u8 *)arg0 + 0xCC);
            *(float *)(frame + 0x78) = *(float *)((u8 *)arg0 + 0xD0);
            *(float *)(frame + 0x7c) = *(float *)((u8 *)arg0 + 0xD4);
            fn_802C744C(*(s32 *)((u8 *)arg0 + 0xE4), frame + 0x50);
        } else {
            fn_802C70AC(*(s32 *)((u8 *)arg0 + 0xE4), frame + 0x50, 0, 1);
        }
    }

    if (lbl_8055F330 != 0) {
        fn_802AEB3C((u8 *)arg0 + 0xA8);
        fn_802B016C();
    }

    if (*(s32 *)((u8 *)arg0 + 0x120) == 0 &&
        fn_802C9C8C(0x50000000) != 0) {
        void *flag = *(void **)((u8 *)arg0 + 8);
        if (*(u8 *)flag != 0) fn_80254354(flag);
        fn_802C9CE0();
    }

    if (*(s32 *)((u8 *)arg0 + 0x120) == 1)
        fn_802566A4(arg0);

    if (*(u8 *)((u8 *)arg0 + 0xDC) != 0) {
        *(u8 *)(frame + 0x18) = fn_802C2C00(1);
        *(s32 *)(frame + 0x8) = fn_802C990C(0xFF000000);
        fn_802C2BB8((float *)(frame + 0xc), (float *)(frame + 0x10),
                    (float *)(frame + 0x14));
        fn_802C2B78(lbl_80563A14, lbl_80563AA4, lbl_80563A14);
    } else {
        memset(frame + 0x8, 0, 0x14);
    }

    if (*(u8 *)((u8 *)arg0 + 0x118) != 0 &&
        *(u8 *)((u8 *)arg0 + 0xDC) == 0)
        fn_802ABFF8(*(s32 *)frame, *(float *)(frame + 0x4));

    {
        void *flag = *(void **)((u8 *)arg0 + 8);
        if (*(u8 *)flag != 0) fn_8025419C(flag);
    }

    if (*(u8 *)((u8 *)arg0 + 0x118) != 0 &&
        *(u8 *)((u8 *)arg0 + 0xDC) == 0)
        fn_802AC070();

    if (*(u8 *)((u8 *)arg0 + 0xDC) != 0) {
        fn_802C990C(*(s32 *)(frame + 0x8));
        fn_802C2B78(*(float *)(frame + 0xc), *(float *)(frame + 0x10),
                    *(float *)(frame + 0x14));
        fn_802C2C00(*(u8 *)(frame + 0x18));
    }

    if (*(s32 *)((u8 *)arg0 + 0xE4) != -1) {
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
        fn_802C70AC(*(s32 *)((u8 *)arg0 + 0xE4), frame + 0x20, 0, 2);
    }

    if (*(u8 *)((u8 *)arg0 + 0x118) != 0)
        fn_802ABE50();
    fn_802C8638(frame + 0xb0);
}
#pragma scheduling on

#pragma scheduling on
s32 fn_802571F0(void) { return 0; }

void fn_802571F8(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 1; }

void fn_80257204(void *arg0) { *(u8 *)((u8 *)arg0 + 0x18) = 0; }

void fn_80257210(void) {}

