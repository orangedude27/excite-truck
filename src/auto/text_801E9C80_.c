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
#pragma push
#pragma processor 750
s32 fn_801E9C84(f32 *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0) {
    #pragma scheduling invalid_target
    s32 original[3];
    f32 normal[3];
    f32 delta[3];
    s32 first = ((s32 *)arg0)[0];
    s32 last = ((s32 *)arg0)[2];
    f32 diffX;
    f32 diffY;
    f32 diffZ;
    f32 dot;
    original[0] = first;
    original[1] = ((s32 *)arg0)[1];
    original[2] = last;
    if (fn_801DCE14((void *)arg4, arg0, (s32)original, (s32)normal, arg5, arg5) == 0)
        return 0;
    diffX = ((f32 *)arg1)[0] - ((f32 *)original)[0];
    diffY = ((f32 *)arg1)[1] - ((f32 *)original)[1];
    diffZ = ((f32 *)arg1)[2] - ((f32 *)original)[2];
    delta[0] = diffX;
    delta[1] = diffY;
    delta[2] = diffZ;
    dot = PSVECDotProduct(normal, delta);
    if ((f32)__fabs((double)dot) < farg0) {
        register f32 valueZ = ((f32 *)arg1)[2];
        register f32 valueY = ((f32 *)arg1)[1];
        register f32 valueX = ((f32 *)arg1)[0];
        f32 ndot = -dot;
        ((f32 *)arg2)[0] = valueX + normal[0] * ndot;
        ((f32 *)arg2)[1] = valueY + normal[1] * ndot;
        ((f32 *)arg2)[2] = valueZ + normal[2] * ndot;
        ((f32 *)arg3)[0] = normal[0];
        ((f32 *)arg3)[1] = normal[1];
        ((f32 *)arg3)[2] = normal[2];
        return 1;
    }
    return 0;
}
#pragma pop
s32 fn_801DCE14(void *, void *, s32, s32, s32, s32);
extern f32 lbl_80562E2C;
/* Reset a 16-bit index/value to -1 (the invalid-index sentinel). */
void fn_801E9DC4(s16 *index) { *index = -1; }

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
    f32 y = lbl_80562E2C;
    input[0] = farg0;
    input[1] = y;
    input[2] = farg1;
    if (((s32 (*)(void *, void *, void *, s32, s32))fn_801DCE14)(arg0, input, output, 0, 0) != 0)
        return output[1];
    return lbl_80562E2C;
}

#pragma scheduling invalid_target
/* Copy a 3-word vector and query fn_801DCE14 against it, passing the original pointer as context. */
void fn_801E9E30(void *arg0, void *point) {
    struct Vec3 { s32 x, y, z; };
    struct Vec3 pointCopy = *(struct Vec3 *)point;
    ((s32 (*)(void *, void *, s32, s32, s32))fn_801DCE14)(arg0, &pointCopy, (s32)point, 0, 0);
}
/* RealName: QueryRaycastFromPoint (tentative). Copies the 3-s32/vec point from srcPoint into a temp, then forwards to fn_801DCE14 with casted srcPoint and copied first component as extra arg. */
void fn_801E9E78(void *context, void *srcPoint, s32 outPos, s32 outInfo) {
    struct { s32 a, b, c; } pointCopy;
    s32 x = *(s32 *)srcPoint;
    s32 y = *((s32 *)srcPoint + 1);
    pointCopy.a = x;
    pointCopy.b = y;
    pointCopy.c = *((s32 *)srcPoint + 2);
    fn_801DCE14(context, &pointCopy, (s32)srcPoint, outPos, outInfo, x);
}
#pragma scheduling on
void fn_801E9EC4(void *context, void *point, s32 outPos, s32 outInfo, f32 x, f32 z) {
    /* Query using point's Y with the given X/Z, forwarding to fn_801DCE14. */
    f32 y = *(f32 *)((char *)point + 4);
    f32 queryPos[3];
    queryPos[0] = x;
    queryPos[1] = y;
    queryPos[2] = z;
    ((s32 (*)(void *, void *, s32, s32, s32, f32))fn_801DCE14)(context, queryPos, (s32)point, outPos, outInfo, x);
}

s32 fn_801E9C84(f32 *, void *, void *, s32, s32, s32, f32);
extern f32 lbl_80562E30;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
s32 fn_801E9F08(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, f32 farg0) {
    f32 data[4];
    f32 temp2, temp1, temp0;
    f32 offset;
    temp1 = *((f32 *)arg1 + 1);
    temp0 = *(f32 *)arg1;
    temp2 = *((f32 *)arg1 + 2);
    offset = lbl_80562E30 + farg0;
    data[0] = temp0;
    data[2] = temp2;
    data[1] = temp1 - offset;
    if (fn_801E9C84(data, arg1, arg2, arg3, (s32)arg0, 0, farg0) != 0) {
        data[0] = *(f32 *)arg2;
        data[1] = *((f32 *)arg2 + 1);
        data[2] = *((f32 *)arg2 + 2);
        if (fn_801E9C84(data, arg1, arg2, arg3, (s32)arg0, arg4, farg0) != 0) {
            return 1;
        }
    }
    return 0;
}
#pragma pop
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
    struct W { s32 a; f32 b; s32 c; } *p = arg1;
    struct W data;
    s16 index = *arg0;
    s32 zero = 0;
    data = *p;
    p->b = lbl_80562E2C;
    ((s32 (*)(s16 *, struct W *, void *, s32, s32))fn_801DCE14)(&index, &data, p, zero, zero);
}
#pragma scheduling invalid_target
/* RealName: QueryGroundPosAtXZ
 * Builds an XZ query position using the caller's X/Z and the input position's Y,
 * copies the index from *indexPtr, and queries ground/height info via fn_801DCE14. */
void fn_801EA098(s16 *indexPtr, void *position, s32 outPosition, s32 outIndex, f32 queryX, f32 queryZ) {
#define QueryGroundHeight fn_801DCE14
    s16 index = *indexPtr;
    f32 posY = *(f32 *)((char *)position + 4);
    f32 queryPos[3];
    queryPos[0] = queryX;
    queryPos[1] = posY;
    queryPos[2] = queryZ;
    ((s32 (*)(s16 *, f32 *, void *, s32, s32))QueryGroundHeight)(&index, queryPos, position, outPosition, outIndex);
#undef QueryGroundHeight
}
f32 fn_801EA0E8(f32 arg0, f32 arg1) {
    f32 input[3];
    f32 output[3];
    input[0] = arg0;
    input[1] = 0.0f;
    input[2] = arg1;
    if (((s32 (*)(void *, f32 *, f32 *, s32, s32))fn_801DCE14)(0, input, output, 0, 0) != 0)
        return output[1];
    return 0.0f;
}
#pragma scheduling on
/* Forwards a 3-word point through fn_801DCE14 with a null context, using a stack copy of the point. */
void fn_801EA140(void *point) {
    struct Vec3i {
        s32 x;
        s32 y;
        s32 z;
    };
    struct Vec3i pointCopy = *(struct Vec3i *)point;

    ((s32 (*)(void *, void *, s32, s32, s32))fn_801DCE14)(0, &pointCopy, (s32)point, 0, 0);
}

#pragma scheduling invalid_target
/* Copies a 3-word point and passes it with the original pointer to fn_801DCE14 (query id 0). */
void fn_801EA18C(void *point, s32 arg1, s32 arg2) {
    struct { s32 a, b, c; } pointCopy;
    s32 temp = *(s32 *)point;
    s32 temp1 = *((s32 *)point + 1);
    pointCopy.a = temp;
    pointCopy.b = temp1;
    pointCopy.c = *((s32 *)point + 2);
    fn_801DCE14(0, &pointCopy, (s32)point, arg1, arg2, temp);
}
#pragma scheduling on
void fn_801EA1D8(void) {
    fn_801DCEF4();
}

void fn_801EA1DC(void) {
    fn_801DCF00();
}

s32 fn_801DD3BC(s32);
/* Thunk: normalize `flag` to a boolean and tail-call fn_801DD3BC; the caller's x/z stay in f1/f2. */
void fn_801EA1E0(s32 value, s32 flag) { ((void (*)(s32, s32))fn_801DD3BC)(value, flag != 0); }

void fn_801EA1F0(void) {
    fn_801DD808();
}

