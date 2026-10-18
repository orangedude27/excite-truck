// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

f32 fn_801E9DDC(void);

void fn_801DCEF4(void);

void fn_801E9C80(void) {

}

s32 fn_801DCE14(void *, void *, s32, s32, s32, s32);
extern f32 lbl_80562E2C;
void fn_801E9DC4(s16 *arg0) { *arg0 = -1; }

f32 fn_801E9DD0(void) {
    return fn_801E9DDC();
}

void fn_801E9DD4(void) {

}

void fn_801E9DD8(void) {

}

void fn_801E9E30(void *arg0, void *arg1) {
    s32 sp8 = *(s32 *)((char *)arg1);
    s32 spC = *(s32 *)((char *)arg1 + 4);
    s32 sp10 = *(s32 *)((char *)arg1 + 8);
    fn_801DCE14(arg0, &sp8, 0, 0, 0, 0);
}

void fn_801E9E78(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp = *(s32 *)arg1;
    s32 sp8 = temp;
    s32 spC = *((s32 *)arg1 + 1);
    s32 sp10 = *((s32 *)arg1 + 2);
    fn_801DCE14(arg0, &sp8, (s32)arg1, arg2, arg3, temp);
}

void fn_801E9EC4(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1) {
    f32 data[3];
    data[0] = farg0;
    data[1] = *(f32 *)((char *)arg1 + 4);
    data[2] = farg1;
    fn_801DCE14(arg0, data, (s32)arg1, arg2, arg3, 0);
}

s32 fn_801E9C84(f32 *, void *, void *, s32, s32, s32, f32);
extern f32 lbl_80562E30;
s32 fn_801E9F08(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, f32 farg0) {
    f32 sp8, spC, sp10;
    f32 temp0 = *(f32 *)arg1;
    f32 temp1 = *((f32 *)arg1 + 1);
    f32 temp2 = *((f32 *)arg1 + 2);
    sp8 = temp0;
    spC = temp1 - (lbl_80562E30 + farg0);
    sp10 = temp2;
    if (fn_801E9C84(&sp8, arg1, arg2, arg3, (s32)arg0, 0, farg0) != 0) {
        sp8 = *(f32 *)arg2;
        spC = *((f32 *)arg2 + 1);
        sp10 = *((f32 *)arg2 + 2);
        if (fn_801E9C84(&sp8, arg1, arg2, arg3, (s32)arg0, arg4, farg0) != 0)
            return 1;
    }
    return 0;
}

f32 fn_801E9FDC(s16 *arg0, f32 farg0, f32 farg1) {
    s16 index = *arg0;
    f32 out[5];
    f32 data[3];
    data[0] = farg0;
    data[1] = lbl_80562E2C;
    data[2] = farg1;
    if (fn_801DCE14(&index, &data[0], (s32)&out[2], 0, 0, 0) != 0)
        return out[2];
    return lbl_80562E2C;
}

void fn_801EA03C(s16 *arg0, void *arg1) {
    s16 index = *arg0;
    s32 data[3];
    s32 temp = *(s32 *)arg1;
    data[0] = temp;
    data[1] = *((s32 *)arg1 + 1);
    data[2] = *((s32 *)arg1 + 2);
    *(f32 *)((char *)arg1 + 4) = lbl_80562E2C;
    fn_801DCE14(&index, data, (s32)arg1, 0, 0, temp);
}

void fn_801EA098(s16 *arg0, void *arg1, s32 arg2, s32 arg3, f32 farg0, f32 farg1) {
    s16 index = *arg0;
    f32 data[3];
    data[0] = farg0;
    data[1] = *(f32 *)((char *)arg1 + 4);
    data[2] = farg1;
    fn_801DCE14(&index, data, (s32)arg1, arg2, arg3, 0);
}

f32 fn_801EA0E8(f32 arg0, f32 arg1) {
    f32 sp14 = arg0;
    f32 sp18 = lbl_80562E2C;
    f32 sp1C = arg1;
    s32 sp8;
    if (fn_801DCE14(0, &sp14, (s32)&sp8, 0, 0, 0) != 0)
        return *(f32 *)((char *)&sp8 + 4);
    return lbl_80562E2C;
}

void fn_801EA140(void *arg0) {
    struct { s32 a,b,c; } data;
    data.a = *(s32 *)arg0;
    data.b = *((s32 *)arg0 + 1);
    data.c = *((s32 *)arg0 + 2);
    fn_801DCE14(0, &data, (s32)arg0, 0, 0, 0);
}

void fn_801EA18C(void *arg0, s32 arg1, s32 arg2) {
    struct { s32 a,b,c; } data;
    s32 temp = *(s32 *)arg0;
    data.a = temp;
    data.b = *((s32 *)arg0 + 1);
    data.c = *((s32 *)arg0 + 2);
    fn_801DCE14(0, &data, (s32)arg0, arg1, arg2, temp);
}

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

