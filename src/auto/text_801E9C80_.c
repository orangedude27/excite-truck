// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

f32 fn_801E9DDC(void *, f32, f32);

void fn_801DCEF4(void);

void fn_801E9C80(void) {

}

extern s32 fn_801DCE14(void *, void *, s32, s32, s32, s32);
extern f32 PSVECDotProduct(const void *, const void *);
extern f32 __fabsf(f32);
extern double __fabs(double);
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
s32 fn_801E9C84(f32 *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0) {
    s32 original[3];
    f32 normal[3];
    f32 delta[3];
    volatile s32 *bits = (volatile s32 *)arg0;
    s32 first = bits[0];
    s32 last = bits[2];
    f32 diffX;
    f32 diffY;
    f32 diffZ;
    f32 dot;
    f32 valueX;
    f32 valueY;
    f32 valueZ;

    original[0] = first;
    original[1] = bits[1];
    original[2] = last;
    if (((s32 (*)(s32, void *, void *, void *, s32, s32))fn_801DCE14)(arg4, arg0, original, normal, arg5, arg5) == 0)
        return 0;

    diffX = ((f32 *)arg1)[0] - ((f32 *)original)[0];
    diffY = ((f32 *)arg1)[1] - ((f32 *)original)[1];
    diffZ = ((f32 *)arg1)[2] - ((f32 *)original)[2];
    delta[0] = diffX;
    delta[1] = diffY;
    delta[2] = diffZ;
    dot = PSVECDotProduct(normal, delta);
    if ((f32)__fabs((double)dot) < farg0) {
        valueX = ((f32 *)arg1)[0];
        valueY = ((f32 *)arg1)[1];
        valueZ = ((f32 *)arg1)[2];
        dot = -dot;
        ((f32 *)arg2)[0] = valueX + normal[0] * dot;
        ((f32 *)arg2)[1] = valueY + normal[1] * dot;
        ((f32 *)arg2)[2] = valueZ + normal[2] * dot;
        ((f32 *)arg3)[0] = normal[0];
        ((f32 *)arg3)[1] = normal[1];
        ((f32 *)arg3)[2] = normal[2];
        return 1;
    }
    return 0;
}
#pragma paired_single reset
#pragma paired reset
#pragma scheduling on
s32 fn_801DCE14(void *, void *, s32, s32, s32, s32);
extern f32 lbl_80562E2C;
void fn_801E9DC4(s16 *arg0) { *arg0 = -1; }

f32 fn_801E9DD0(void) {
    return ((f32 (*)(void))fn_801E9DDC)();
}

void fn_801E9DD4(void) {

}

void fn_801E9DD8(void) {

}

f32 fn_801E9DDC(void *arg0, f32 farg0, f32 farg1) {
    f32 input[3];
    f32 output[3];
    input[0] = farg0;
    input[1] = lbl_80562E2C;
    input[2] = farg1;
    if (((s32 (*)(void *, void *, void *, s32, s32))fn_801DCE14)(arg0, input, output, 0, 0) != 0)
        return output[1];
    return lbl_80562E2C;
}

#pragma scheduling invalid_target
void fn_801E9E30(void *arg0, void *arg1) {
    struct V { s32 a, b, c; };
    struct V data = *(struct V *)arg1;
    ((s32 (*)(void *, void *, s32, s32, s32))fn_801DCE14)(arg0, &data, (s32)arg1, 0, 0);
}
void fn_801E9E78(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    struct { s32 a, b, c; } data;
    s32 temp = *(s32 *)arg1;
    s32 temp1 = *((s32 *)arg1 + 1);
    data.a = temp;
    data.b = temp1;
    data.c = *((s32 *)arg1 + 2);
    fn_801DCE14(arg0, &data, (s32)arg1, arg2, arg3, temp);
}
#pragma scheduling on
void fn_801E9EC4(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1) {
    f32 temp = *(f32 *)((char *)arg1 + 4);
    f32 data[3];
    data[0] = farg0;
    data[1] = temp;
    data[2] = farg1;
    ((s32 (*)(void *, void *, s32, s32, s32, f32))fn_801DCE14)(arg0, data, (s32)arg1, arg2, arg3, farg0);
}

s32 fn_801E9C84(f32 *, void *, void *, s32, s32, s32, f32);
extern f32 lbl_80562E30;
#pragma scheduling invalid_target
s32 fn_801E9F08(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, f32 farg0) {
    struct Vec3 { f32 x, y, z; } data;
    f32 temp2 = *((f32 *)arg1 + 2);
    f32 temp1 = *((f32 *)arg1 + 1);
    f32 temp0 = *(f32 *)arg1;
    f32 offset = lbl_80562E30 + farg0;

    data.x = temp0;
    data.z = temp2;
    data.y = temp1 - offset;
    if (fn_801E9C84(&data.x, arg1, arg2, arg3, (s32)arg0, 0, farg0) != 0) {
        data.x = *(f32 *)arg2;
        data.y = *((f32 *)arg2 + 1);
        data.z = *((f32 *)arg2 + 2);
        if (fn_801E9C84(&data.x, arg1, arg2, arg3, (s32)arg0, arg4, farg0) != 0) {
            return 1;
        }
    }
    return 0;
}
#pragma scheduling on
f32 fn_801E9FDC(s16 *arg0, f32 farg0, f32 farg1) {
    s16 index = *arg0;
    f32 data[3];
    f32 out[3];
    data[0] = farg0;
    data[1] = lbl_80562E2C;
    data[2] = farg1;
    if (((s32 (*)(void *, void *, void *, s32, s32))fn_801DCE14)(&index, data, out, 0, 0) != 0)
        return out[1];
    return lbl_80562E2C;
}

#pragma scheduling invalid_target
void fn_801EA03C(s16 *arg0, void *arg1) {
    s16 index = *arg0;
    struct V { s32 a, b, c; } data = *(struct V *)arg1;
    *(f32 *)((char *)arg1 + 4) = lbl_80562E2C;
    ((s32 (*)(s16 *, struct V *, void *, s32, s32))fn_801DCE14)(&index, &data, arg1, 0, 0);
}
#pragma scheduling on
void fn_801EA098(s16 *arg0, void *arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1) {
    s16 index = *arg0;
    f32 temp = *(f32 *)((char *)arg1 + 4);
    f32 data[3];
    data[0] = farg0;
    data[1] = temp;
    data[2] = farg1;
    ((s32 (*)(s16 *, f32 *, void *, s32, s32))fn_801DCE14)(&index, data, arg1, arg2, arg3);
}
#pragma scheduling invalid_target
f32 fn_801EA0E8(f32 arg0, f32 arg1) {
    f32 center = *(volatile f32 *)&lbl_80562E2C;
    volatile f32 input[3];
    f32 output[3];
    input[0] = arg0;
    input[1] = center;
    input[2] = arg1;
    if (((s32 (*)(void *, f32 *, f32 *, s32, s32))fn_801DCE14)(0, (f32 *)input, output, 0, 0) != 0)
        return output[1];
    return lbl_80562E2C;
}
#pragma scheduling on
void fn_801EA140(void *arg0) {
    struct V { s32 a, b, c; };
    struct V data = *(struct V *)arg0;
    ((s32 (*)(void *, void *, s32, s32, s32))fn_801DCE14)(0, &data, (s32)arg0, 0, 0);
}

#pragma scheduling invalid_target
void fn_801EA18C(void *arg0, s32 arg1, s32 arg2) {
    struct { s32 a, b, c; } data;
    s32 temp = *(s32 *)arg0;
    s32 temp1 = *((s32 *)arg0 + 1);
    data.a = temp;
    data.b = temp1;
    data.c = *((s32 *)arg0 + 2);
    fn_801DCE14(0, &data, (s32)arg0, arg1, arg2, temp);
}
#pragma scheduling on
void fn_801EA1D8(void) {
    fn_801DCEF4();
}

void fn_801EA1DC(void) {
    fn_801DCF00();
}

s32 fn_801DD3BC(s32);
void fn_801EA1E0(s32 arg0, s32 arg1) { ((void (*)(s32, s32))fn_801DD3BC)(arg0, arg1 != 0); }

void fn_801EA1F0(void) {
    fn_801DD808();
}

