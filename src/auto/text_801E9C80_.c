// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

f32 fn_801E9DDC(void *, f32, f32);

void fn_801DCEF4(void);

void fn_801E9C80(void) {
    /* Empty stub (returns immediately). */
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
    f32 diffX;
    f32 diffY;
    f32 diffZ;
    f32 dot;
    original[0] = ((s32 *)arg0)[0];
    original[1] = ((s32 *)arg0)[1];
    original[2] = ((s32 *)arg0)[2];
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
        f32 valueZ = ((f32 *)arg1)[2];
        f32 valueY = ((f32 *)arg1)[1];
        f32 valueX = ((f32 *)arg1)[0];
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

/* Alternate tail-call entry point for the ground-height query: branches straight
 * to fn_801E9DDC with the caller's registers untouched, so callers pass the same
 * outGroundIndex / x / z arguments as the real query. */
f32 fn_801E9DD0(void) {
    return ((f32 (*)(void))fn_801E9DDC)();
}

/* No-op stub. */
void fn_801E9DD4(void) {

}

void fn_801E9DD8(void) {
    /* Empty stub (returns immediately). */
}

#pragma scheduling invalid_target
/* Ground height at world (x, z): builds the query point (x, 0, z), runs it through
   the ground lookup fn_801DCE14 (which resolves the tile under the point and
   interpolates its height) and returns the resulting Y; 0.0f when the query fails.
   outGroundIndex is the caller's optional 16-bit ground-info field, which the
   lookup clears before sampling (fn_801E9DC4 resets the same field to -1);
   fn_801EA0E8 is this query with no field to clear. */
f32 fn_801E9DDC(void *outGroundIndex, f32 x, f32 z) {
    f32 queryPos[3];
    f32 resultPos[3];
    queryPos[0] = x;
    queryPos[1] = 0.0f;
    queryPos[2] = z;
    if (((s32 (*)(void *, f32 *, f32 *, s32, s32))fn_801DCE14)(outGroundIndex, queryPos, resultPos, 0, 0) != 0)
        return resultPos[1];
    return 0.0f;
}
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
/* Two-stage contact probe: first test a shifted copy of the input position, then,
 * if that hits, test again from the resulting contact point. Returns 1 only when
 * both probes succeed, filling contactPoint and normalOut; handle identifies the
 * object for the second probe. */
s32 fn_801E9F08(void *context, void *position, void *contactPoint, s32 normalOut, s32 handle, f32 threshold) {
    f32 candidate[4];
    f32 candZ, candY, candX;
    volatile f32 *positionFloats = (volatile f32 *)position;
    candX = positionFloats[0];
    candY = positionFloats[1];
    candZ = positionFloats[2];
    candidate[0] = candX;
    candidate[2] = candZ;
    candidate[1] = candY - (lbl_80562E30 + threshold);
    if (fn_801E9C84(candidate, position, contactPoint, normalOut, (s32)context, 0, threshold) != 0) {
        candidate[0] = *(f32 *)contactPoint;
        candidate[1] = *((f32 *)contactPoint + 1);
        candidate[2] = *((f32 *)contactPoint + 2);
        if (fn_801E9C84(candidate, position, contactPoint, normalOut, (s32)context, handle, threshold) != 0) {
            return 1;
        }
    }
    return 0;
}
#pragma scheduling on
/* Return the ground height at world (x, z) for the given ground index, or 0.0f when the ground lookup fails. */
f32 fn_801E9FDC(const s16 *groundIndexPtr, f32 worldX, f32 worldZ) {
    s16 groundIndex = *groundIndexPtr;
    f32 queryPos[3];
    f32 resultPos[3];
    queryPos[0] = worldX;
    queryPos[1] = 0.0f;
    queryPos[2] = worldZ;
    if (((s32 (*)(void *, void *, void *, s32, s32))fn_801DCE14)(&groundIndex, queryPos, resultPos, 0, 0) != 0)
        return resultPos[1];
    return 0.0f;
}
#pragma scheduling 603
void fn_801EA03C(s16 *arg0, void *arg1) {
    register f32 v = 0.0f;
    s16 index = *arg0;
    struct V { s32 a, b, c; } data = *(struct V *)arg1;
    *(f32 *)((char *)arg1 + 4) = v;
    ((s32 (*)(s16 *, struct V *, void *, s32, s32))fn_801DCE14)(&index, &data, arg1, 0, 0);
}
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
f32 fn_801EA0E8(f32 x, f32 z) {
    /* Query the ground height at world X/Z: build a 3D query point (x, 0, z), run it
     * through the ground-height lookup fn_801DCE14 and return the resolved Y coordinate;
     * returns 0.0f when the query fails. */
    f32 queryPos[3];
    f32 resultPos[3];
    queryPos[0] = x;
    queryPos[1] = 0.0f;
    queryPos[2] = z;
    if (((s32 (*)(void *, f32 *, f32 *, s32, s32))fn_801DCE14)(0, queryPos, resultPos, 0, 0) != 0)
        return resultPos[1];
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
/* Thunk: reset the active-entry count via fn_801DCEF4, emptying the pending
 * value-accumulation queue (sActiveEntryCount / lbl_8055E9A8). */
void fn_801EA1D8(void) {
    fn_801DCEF4();
}

/* Thunk: reset the ground-query active-entry count, emptying the pending value-accumulation queue. */
void fn_801EA1DC(void) {
    fn_801DCF00();
}

s32 fn_801DD3BC(s32);
/* Thunk: normalize `flag` to a boolean and tail-call fn_801DD3BC; the caller's x/z stay in f1/f2. */
void fn_801EA1E0(s32 value, s32 flag) { ((void (*)(s32, s32))fn_801DD3BC)(value, flag != 0); }

/* Thunk: apply pending accumulated values to all active entries. */
void fn_801EA1F0(void) {
    fn_801DD808();
}

